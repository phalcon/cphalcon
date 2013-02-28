
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Queue\Beanstalk
 *
 * Class to access the beanstalk queue service.
 * Partially implements the protocol version 1.2
 *
 * @see http://www.igvita.com/2010/05/20/scalable-work-queues-with-beanstalk/
 */


/**
 * Phalcon\Queue\Beanstalk initializer
 */
PHALCON_INIT_CLASS(Phalcon_Queue_Beanstalk){

	PHALCON_REGISTER_CLASS(Phalcon\\Queue, Beanstalk, queue_beanstalk, phalcon_queue_beanstalk_method_entry, 0);

	zend_declare_property_null(phalcon_queue_beanstalk_ce, SL("_connection"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_queue_beanstalk_ce, SL("_parameters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Queue\Beanstalk
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, __construct){

	zval *options = NULL, *parameters = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_INIT_VAR(parameters);
		array_init(parameters);
	} else {
		PHALCON_CPY_WRT(parameters, options);
	}
	if (!phalcon_array_isset_string(parameters, SS("host"))) {
		phalcon_array_update_string_string(&parameters, SL("host"), SL("127.0.0.1"), PH_SEPARATE TSRMLS_CC);
	}
	
	if (!phalcon_array_isset_string(parameters, SS("port"))) {
		phalcon_array_update_string_long(&parameters, SL("port"), 11300, PH_SEPARATE TSRMLS_CC);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_parameters"), parameters TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Beanstalk, connect){

	zval *connection = NULL, *parameters, *host, *port, *error_num;
	zval *error_str, *no_timeout, *microseconds;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(connection);
	phalcon_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) == IS_RESOURCE) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, "disconnect");
	}
	
	PHALCON_OBS_VAR(parameters);
	phalcon_read_property(&parameters, this_ptr, SL("_parameters"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(host);
	phalcon_array_fetch_string(&host, parameters, SL("host"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(port);
	phalcon_array_fetch_string(&port, parameters, SL("port"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(error_num);
	
	PHALCON_INIT_VAR(error_str);
	p0[0] = host;
	p0[1] = port;
	Z_SET_ISREF_P(error_num);
	p0[2] = error_num;
	Z_SET_ISREF_P(error_str);
	p0[3] = error_str;
	
	PHALCON_INIT_VAR(r0);
	PHALCON_CALL_FUNC_PARAMS(r0, "fsockopen", 4, p0);
	Z_UNSET_ISREF_P(p0[2]);
	Z_UNSET_ISREF_P(p0[3]);
	PHALCON_CPY_WRT(connection, r0);
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_exception_ce, "Can't connect to Beanstalk server");
		return;
	}
	
	PHALCON_INIT_VAR(no_timeout);
	ZVAL_LONG(no_timeout, -1);
	
	PHALCON_INIT_VAR(microseconds);
	PHALCON_CALL_FUNC_PARAMS_3_NORETURN("stream_set_timeout", connection, no_timeout, microseconds);
	phalcon_update_property_zval(this_ptr, SL("_connection"), connection TSRMLS_CC);
	
	RETURN_CCTOR(connection);
}

/**
 * Inserts jobs into the queue
 *
 * @param string $data
 * @param array $options
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, put){

	zval *data, *options = NULL, *priority = NULL, *delay = NULL, *ttr = NULL, *serialized;
	zval *serialized_length, *command, *response;
	zval *status, *job_id = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &data, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	/** 
	 * Priority is 100 by default
	 */
	if (phalcon_array_isset_string(options, SS("priority"))) {
		PHALCON_OBS_VAR(priority);
		phalcon_array_fetch_string(&priority, options, SL("priority"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(priority);
		ZVAL_STRING(priority, "100", 1);
	}
	if (phalcon_array_isset_string(options, SS("delay"))) {
		PHALCON_OBS_VAR(delay);
		phalcon_array_fetch_string(&delay, options, SL("delay"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(delay);
		ZVAL_STRING(delay, "0", 1);
	}
	
	if (phalcon_array_isset_string(options, SS("ttr"))) {
		PHALCON_OBS_VAR(ttr);
		phalcon_array_fetch_string(&ttr, options, SL("ttr"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(ttr);
		ZVAL_STRING(ttr, "86400", 1);
	}
	
	/** 
	 * Data is automatically serialized before be sent to the server
	 */
	PHALCON_INIT_VAR(serialized);
	PHALCON_CALL_FUNC_PARAMS_1(serialized, "serialize", data);
	
	PHALCON_INIT_VAR(serialized_length);
	phalcon_fast_strlen(serialized_length, serialized);
	
	/** 
	 * Create the command
	 */
	PHALCON_INIT_VAR(command);
	PHALCON_CONCAT_SVSV(command, "put ", priority, " ", delay);
	PHALCON_SCONCAT_SVSV(command, " ", ttr, " ", serialized_length);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "write", command);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "write", serialized);
	
	PHALCON_INIT_VAR(response);
	PHALCON_CALL_METHOD(response, this_ptr, "readstatus");
	
	PHALCON_OBS_VAR(status);
	phalcon_array_fetch_long(&status, response, 0, PH_NOISY_CC);
	if (PHALCON_IS_STRING(status, "INSERTED")) {
		PHALCON_OBS_VAR(job_id);
		phalcon_array_fetch_long(&job_id, response, 1, PH_NOISY_CC);
		RETURN_CCTOR(job_id);
	}
	
	if (PHALCON_IS_STRING(status, "BURIED")) {
		PHALCON_OBS_NVAR(job_id);
		phalcon_array_fetch_long(&job_id, response, 1, PH_NOISY_CC);
		RETURN_CCTOR(job_id);
	}
	
	RETURN_MM_FALSE;
}

/**
 *
 * @return boolean|Phalcon\Queue\Beanstalk\Job
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, reserve){

	zval *timeout = NULL, *command = NULL, *response, *status, *job_id;
	zval *length, *serialized_body, *body, *job;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &timeout) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!timeout) {
		PHALCON_INIT_VAR(timeout);
	}
	
	if (zend_is_true(timeout)) {
		PHALCON_INIT_VAR(command);
		PHALCON_CONCAT_SV(command, "reserve-with-timeout ", timeout);
	} else {
		PHALCON_INIT_NVAR(command);
		ZVAL_STRING(command, "reserve", 1);
	}
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "write", command);
	
	PHALCON_INIT_VAR(response);
	PHALCON_CALL_METHOD(response, this_ptr, "readstatus");
	
	PHALCON_OBS_VAR(status);
	phalcon_array_fetch_long(&status, response, 0, PH_NOISY_CC);
	if (PHALCON_IS_STRING(status, "RESERVED")) {
		/** 
		 * The job is in the first position
		 */
		PHALCON_OBS_VAR(job_id);
		phalcon_array_fetch_long(&job_id, response, 1, PH_NOISY_CC);
	
		/** 
		 * Next is the job length
		 */
		PHALCON_OBS_VAR(length);
		phalcon_array_fetch_long(&length, response, 2, PH_NOISY_CC);
	
		/** 
		 * The body is serialized
		 */
		PHALCON_INIT_VAR(serialized_body);
		PHALCON_CALL_METHOD_PARAMS_1(serialized_body, this_ptr, "read", length);
	
		PHALCON_INIT_VAR(body);
		PHALCON_CALL_FUNC_PARAMS_1(body, "unserialize", serialized_body);
	
		/** 
		 * Create a beanstalk job abstraction
		 */
		PHALCON_INIT_VAR(job);
		object_init_ex(job, phalcon_queue_beanstalk_job_ce);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(job, "__construct", this_ptr, job_id, body);
	
		RETURN_CTOR(job);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Change the active tube. By default the tube is 'default'
 *
 * @param string $tube
 * @return string|boolean
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, choose){

	zval *tube, *command, *response, *status, *using_tube;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &tube) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(command);
	PHALCON_CONCAT_SV(command, "use ", tube);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "write", command);
	
	PHALCON_INIT_VAR(response);
	PHALCON_CALL_METHOD(response, this_ptr, "readstatus");
	
	PHALCON_OBS_VAR(status);
	phalcon_array_fetch_long(&status, response, 0, PH_NOISY_CC);
	if (PHALCON_IS_STRING(status, "USING")) {
		PHALCON_OBS_VAR(using_tube);
		phalcon_array_fetch_long(&using_tube, response, 1, PH_NOISY_CC);
		RETURN_CCTOR(using_tube);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Change the active tube. By default the tube is 'default'
 *
 * @param string $tube
 * @return string|boolean
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, watch){

	zval *tube, *command, *response, *status, *watching_tube;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &tube) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(command);
	PHALCON_CONCAT_SV(command, "watch ", tube);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "write", command);
	
	PHALCON_INIT_VAR(response);
	PHALCON_CALL_METHOD(response, this_ptr, "readstatus");
	
	PHALCON_OBS_VAR(status);
	phalcon_array_fetch_long(&status, response, 0, PH_NOISY_CC);
	if (PHALCON_IS_STRING(status, "WATCH")) {
		PHALCON_OBS_VAR(watching_tube);
		phalcon_array_fetch_long(&watching_tube, response, 1, PH_NOISY_CC);
		RETURN_CCTOR(watching_tube);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Inspect the next ready job.
 *
 * @return boolean|Phalcon\Queue\Beanstalk\Job
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, peekReady){

	zval *command, *response, *status, *job_id, *length;
	zval *serialized_body, *body, *job;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(command);
	ZVAL_STRING(command, "peek-ready", 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "write", command);
	
	PHALCON_INIT_VAR(response);
	PHALCON_CALL_METHOD(response, this_ptr, "readstatus");
	
	PHALCON_OBS_VAR(status);
	phalcon_array_fetch_long(&status, response, 0, PH_NOISY_CC);
	if (PHALCON_IS_STRING(status, "FOUND")) {
		PHALCON_OBS_VAR(job_id);
		phalcon_array_fetch_long(&job_id, response, 1, PH_NOISY_CC);
	
		PHALCON_OBS_VAR(length);
		phalcon_array_fetch_long(&length, response, 2, PH_NOISY_CC);
	
		PHALCON_INIT_VAR(serialized_body);
		PHALCON_CALL_METHOD_PARAMS_1(serialized_body, this_ptr, "read", length);
	
		PHALCON_INIT_VAR(body);
		PHALCON_CALL_FUNC_PARAMS_1(body, "unserialize", serialized_body);
	
		PHALCON_INIT_VAR(job);
		object_init_ex(job, phalcon_queue_beanstalk_job_ce);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(job, "__construct", this_ptr, job_id, body);
	
		RETURN_CTOR(job);
	}
	
	RETURN_MM_FALSE;
}

PHP_METHOD(Phalcon_Queue_Beanstalk, readStatus){

	zval *response, *space, *parts;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(response);
	PHALCON_CALL_METHOD(response, this_ptr, "read");
	
	PHALCON_INIT_VAR(space);
	ZVAL_STRING(space, " ", 1);
	
	PHALCON_INIT_VAR(parts);
	phalcon_fast_explode(parts, space, response TSRMLS_CC);
	RETURN_CTOR(parts);
}

/**
 * Reads a packet from the socket. Prior to reading from the socket will
 * check for availability of the connection.
 *
 * @param int $length Number of bytes to read.
 * @return string|boolean Data or `false` on error.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, read){

	zval *length = NULL, *connection = NULL, *is_eof, *eof_chars;
	zval *total_length = NULL, *data, *meta, *timeout, *mask;
	zval *packet = NULL, *end_of_file;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &length) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!length) {
		PHALCON_INIT_VAR(length);
	}
	
	PHALCON_OBS_VAR(connection);
	phalcon_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
	
		PHALCON_INIT_NVAR(connection);
		PHALCON_CALL_METHOD(connection, this_ptr, "connect");
		if (Z_TYPE_P(connection) != IS_RESOURCE) {
			RETURN_MM_FALSE;
		}
	}
	
	if (zend_is_true(length)) {
	
		PHALCON_INIT_VAR(is_eof);
		PHALCON_CALL_FUNC_PARAMS_1(is_eof, "feof", connection);
		if (zend_is_true(is_eof)) {
			RETURN_MM_FALSE;
		}
	
		PHALCON_INIT_VAR(eof_chars);
		ZVAL_LONG(eof_chars, 2);
	
		PHALCON_INIT_VAR(total_length);
		phalcon_add_function(total_length, length, eof_chars TSRMLS_CC);
	
		PHALCON_INIT_VAR(data);
		PHALCON_CALL_FUNC_PARAMS_2(data, "fread", connection, total_length);
	
		PHALCON_INIT_VAR(meta);
		PHALCON_CALL_FUNC_PARAMS_1(meta, "stream_get_meta_data", connection);
	
		PHALCON_OBS_VAR(timeout);
		phalcon_array_fetch_string(&timeout, meta, SL("timed_out"), PH_NOISY_CC);
		if (zend_is_true(timeout)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_exception_ce, "Connection timed out");
			return;
		}
	
		PHALCON_INIT_VAR(mask);
		ZVAL_STRING(mask, "\r\n", 1);
	
		PHALCON_INIT_VAR(packet);
		PHALCON_CALL_FUNC_PARAMS_2(packet, "rtrim", data, mask);
	} else {
		PHALCON_INIT_NVAR(total_length);
		ZVAL_LONG(total_length, 16384);
	
		PHALCON_INIT_VAR(end_of_file);
		ZVAL_STRING(end_of_file, "\r\n", 1);
	
		PHALCON_INIT_NVAR(packet);
		PHALCON_CALL_FUNC_PARAMS_3(packet, "stream_get_line", connection, total_length, end_of_file);
	}
	
	
	RETURN_CCTOR(packet);
}

/**
 * Writes data to the socket. Performs a connection if none is available
 *
 * @param string $data
 * @return integer|boolean
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, write){

	zval *data, *connection = NULL, *packet, *data_length;
	zval *status;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(connection);
	phalcon_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
	
		PHALCON_INIT_NVAR(connection);
		PHALCON_CALL_METHOD(connection, this_ptr, "connect");
		if (Z_TYPE_P(connection) != IS_RESOURCE) {
			RETURN_MM_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(packet);
	PHALCON_CONCAT_VS(packet, data, "\r\n");
	
	PHALCON_INIT_VAR(data_length);
	phalcon_fast_strlen(data_length, packet);
	
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_FUNC_PARAMS_3(status, "fwrite", connection, packet, data_length);
	
	RETURN_CCTOR(status);
}

/**
 * Closes the connection to the beanstalk server.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, disconnect){

	zval *connection;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(connection);
	phalcon_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
		RETURN_MM_FALSE;
	}
	
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("fclose", connection);
	RETURN_MM_TRUE;
}

