/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "queue/beanstalk.h"
#include "queue/beanstalk/job.h"
#include "exception.h"

#include <ext/standard/file.h>
#include <main/php_streams.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/variables.h"
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
zend_class_entry *phalcon_queue_beanstalk_ce;

PHP_METHOD(Phalcon_Queue_Beanstalk, __construct);
PHP_METHOD(Phalcon_Queue_Beanstalk, connect);
PHP_METHOD(Phalcon_Queue_Beanstalk, put);
PHP_METHOD(Phalcon_Queue_Beanstalk, reserve);
PHP_METHOD(Phalcon_Queue_Beanstalk, choose);
PHP_METHOD(Phalcon_Queue_Beanstalk, watch);
PHP_METHOD(Phalcon_Queue_Beanstalk, peekReady);
PHP_METHOD(Phalcon_Queue_Beanstalk, peekDelayed);
PHP_METHOD(Phalcon_Queue_Beanstalk, peekBuried);
PHP_METHOD(Phalcon_Queue_Beanstalk, readStatus);
PHP_METHOD(Phalcon_Queue_Beanstalk, read);
PHP_METHOD(Phalcon_Queue_Beanstalk, write);
PHP_METHOD(Phalcon_Queue_Beanstalk, disconnect);
PHP_METHOD(Phalcon_Queue_Beanstalk, __sleep);
PHP_METHOD(Phalcon_Queue_Beanstalk, __wakeup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_put, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_reserve, 0, 0, 0)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_choose, 0, 0, 1)
	ZEND_ARG_INFO(0, tube)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_watch, 0, 0, 1)
	ZEND_ARG_INFO(0, tube)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_queue_beanstalk_read, 0, 0, 0)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_queue_beanstalk_method_entry[] = {
	PHP_ME(Phalcon_Queue_Beanstalk, __construct, arginfo_phalcon_queue_beanstalk___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Queue_Beanstalk, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, put, arginfo_phalcon_queue_beanstalk_put, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, reserve, arginfo_phalcon_queue_beanstalk_reserve, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, choose, arginfo_phalcon_queue_beanstalk_choose, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, watch, arginfo_phalcon_queue_beanstalk_watch, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, peekReady, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, peekDelayed, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, peekBuried, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, readStatus, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Queue_Beanstalk, read, arginfo_phalcon_queue_beanstalk_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, write, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Queue_Beanstalk, disconnect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, __sleep, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Queue_Beanstalk, __wakeup, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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

	zval *options = NULL, *parameters = NULL, *tmp;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_INIT_VAR(parameters);
		array_init_size(parameters, 2);
	} else {
		PHALCON_CPY_WRT_CTOR(parameters, options);
	}

	if (!phalcon_array_isset_string_fetch(&tmp, parameters, SS("host"))) {
		phalcon_array_update_string_string(&parameters, SL("host"), SL("127.0.0.1"), 0);
	}
	else {
		convert_to_string(tmp);
	}
	
	if (!phalcon_array_isset_string_fetch(&tmp, parameters, SS("port"))) {
		phalcon_array_update_string_long(&parameters, SL("port"), 11300, 0);
	}
	else {
		convert_to_long(tmp);
	}
	
	phalcon_update_property_this(this_ptr, SL("_parameters"), parameters TSRMLS_CC);
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Beanstalk, connect){

	zval *connection = NULL, *parameters, *host, *port;

	connection = phalcon_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(connection) == IS_RESOURCE) {
		PHALCON_MM_GROW();
		PHALCON_CALL_METHOD(NULL, this_ptr, "disconnect");
		PHALCON_MM_RESTORE();
	}
	
	parameters = phalcon_fetch_nproperty_this(this_ptr, SL("_parameters"), PH_NOISY TSRMLS_CC);
	
	if (!phalcon_array_isset_string_fetch(&host, parameters, SS("host")) || !phalcon_array_isset_string_fetch(&port, parameters, SS("port"))) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_exception_ce, "Unexpected inconsistency in options");
		return;
	}
	
	convert_to_string(host);
	convert_to_long(port);

	{
		ulong timeout = (ulong)(FG(default_socket_timeout) * 1000000.0);
		char *hostname;
		long int hostname_len = spprintf(&hostname, 0, "%s:%ld", Z_STRVAL_P(host), Z_LVAL_P(port));
		struct timeval tv;
		php_stream *stream;
		int err;
		char *errstr = NULL;

		tv.tv_sec  = timeout / 1000000;
		tv.tv_usec = timeout % 1000000;

		stream = php_stream_xport_create(hostname, hostname_len, ENFORCE_SAFE_MODE | REPORT_ERRORS, STREAM_XPORT_CLIENT | STREAM_XPORT_CONNECT, NULL, &tv, NULL, &errstr, &err);
		efree(hostname);

		if (!stream) {
			zend_throw_exception_ex(phalcon_exception_ce, err TSRMLS_CC, "Unable to connect to Beanstalk server at %s:%ld (%s)", Z_STRVAL_P(host), Z_LVAL_P(port), (errstr == NULL ? "Unknown error" : errstr));
		}

		if (errstr) {
			efree(errstr);
		}

		if (!stream) {
			RETURN_NULL();
		}

		tv.tv_sec  = -1;
		tv.tv_usec = 0;
		php_stream_set_option(stream, PHP_STREAM_OPTION_READ_TIMEOUT, 0, &tv);

		MAKE_STD_ZVAL(connection);
		php_stream_to_zval(stream, connection);
		phalcon_update_property_this(this_ptr, SL("_connection"), connection TSRMLS_CC);
		RETVAL_ZVAL(connection, 1, 1);
	}
}

/**
 * Inserts jobs into the queue
 *
 * @param string $data
 * @param array $options
 * @return string|boolean
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, put){

	zval *data, *options = NULL, *priority = NULL, *delay = NULL, *ttr = NULL, *serialized;
	zval *serialized_length, *command, *response = NULL;
	zval *status, *job_id = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &data, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	/** 
	 * Priority is 100 by default
	 */
	if (!phalcon_array_isset_string_fetch(&priority, options, SS("priority"))) {
		PHALCON_INIT_VAR(priority);
		ZVAL_STRING(priority, "100", 1);
	}

	if (!phalcon_array_isset_string_fetch(&delay, options, SS("delay"))) {
		PHALCON_INIT_VAR(delay);
		ZVAL_STRING(delay, "0", 1);
	}

	if (!phalcon_array_isset_string_fetch(&ttr, options, SS("ttr"))) {
		PHALCON_INIT_VAR(ttr);
		ZVAL_STRING(ttr, "86400", 1);
	}
	
	/** 
	 * Data is automatically serialized before be sent to the server
	 */
	PHALCON_INIT_VAR(serialized);
	phalcon_serialize(serialized, &data TSRMLS_CC);
	
	if (Z_TYPE_P(serialized) == IS_STRING) {
		PHALCON_INIT_VAR(serialized_length);
		ZVAL_LONG(serialized_length, Z_STRLEN_P(serialized));
	}
	else {
		RETURN_MM_FALSE;
	}

	/** 
	 * Create the command
	 */
	PHALCON_INIT_VAR(command);
	PHALCON_CONCAT_SVSV(command, "put ", priority, " ", delay);
	PHALCON_SCONCAT_SVSV(command, " ", ttr, " ", serialized_length);
	PHALCON_CALL_METHOD(NULL, this_ptr, "write", command);
	PHALCON_CALL_METHOD(NULL, this_ptr, "write", serialized);
	
	PHALCON_CALL_METHOD(&response, this_ptr, "readstatus");
	
	PHALCON_OBS_VAR(status);
	phalcon_array_fetch_long(&status, response, 0, PH_NOISY);
	if (PHALCON_IS_STRING(status, "INSERTED")) {
		PHALCON_OBS_VAR(job_id);
		phalcon_array_fetch_long(&job_id, response, 1, PH_NOISY);
		RETURN_CCTOR(job_id);
	}
	
	if (PHALCON_IS_STRING(status, "BURIED")) {
		PHALCON_OBS_NVAR(job_id);
		phalcon_array_fetch_long(&job_id, response, 1, PH_NOISY);
		RETURN_CCTOR(job_id);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Reserves a job in the queue
 *
 * @return boolean|\Phalcon\Queue\Beanstalk\Job
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, reserve){

	zval *timeout = NULL, *command = NULL, *response = NULL, *status, *job_id;
	zval *length, *serialized_body = NULL, *body;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &timeout);
	
	if (!timeout) {
		timeout = PHALCON_GLOBAL(z_null);
	}

	PHALCON_INIT_VAR(command);
	if (zend_is_true(timeout)) {
		PHALCON_CONCAT_SV(command, "reserve-with-timeout ", timeout);
	} else {
		ZVAL_STRING(command, "reserve", 1);
	}
	PHALCON_CALL_METHOD(NULL, this_ptr, "write", command);
	PHALCON_CALL_METHOD(&response, this_ptr, "readstatus");
	
	PHALCON_OBS_VAR(status);
	phalcon_array_fetch_long(&status, response, 0, PH_NOISY);
	if (PHALCON_IS_STRING(status, "RESERVED")) {
		/** 
		 * The job is in the first position
		 */
		PHALCON_OBS_VAR(job_id);
		phalcon_array_fetch_long(&job_id, response, 1, PH_NOISY);
	
		/** 
		 * Next is the job length
		 */
		PHALCON_OBS_VAR(length);
		phalcon_array_fetch_long(&length, response, 2, PH_NOISY);
	
		/** 
		 * The body is serialized
		 */
		PHALCON_CALL_METHOD(&serialized_body, this_ptr, "read", length);
	
		PHALCON_INIT_VAR(body);
		phalcon_unserialize(body, serialized_body TSRMLS_CC);
	
		/** 
		 * Create a beanstalk job abstraction
		 */
		object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
		PHALCON_CALL_METHOD(NULL, return_value, "__construct", this_ptr, job_id, body);
	
		RETURN_MM();
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

	zval *tube, *command, *response = NULL, *status, *using_tube;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &tube);
	
	PHALCON_INIT_VAR(command);
	PHALCON_CONCAT_SV(command, "use ", tube);
	PHALCON_CALL_METHOD(NULL, this_ptr, "write", command);
	PHALCON_CALL_METHOD(&response, this_ptr, "readstatus");
	
	PHALCON_OBS_VAR(status);
	phalcon_array_fetch_long(&status, response, 0, PH_NOISY);
	if (PHALCON_IS_STRING(status, "USING")) {
		PHALCON_OBS_VAR(using_tube);
		phalcon_array_fetch_long(&using_tube, response, 1, PH_NOISY);
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

	zval *tube, *command, *response = NULL, *status, *watching_tube;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &tube);
	
	PHALCON_INIT_VAR(command);
	PHALCON_CONCAT_SV(command, "watch ", tube);
	PHALCON_CALL_METHOD(NULL, this_ptr, "write", command);
	PHALCON_CALL_METHOD(&response, this_ptr, "readstatus");
	
	PHALCON_OBS_VAR(status);
	phalcon_array_fetch_long(&status, response, 0, PH_NOISY);
	if (PHALCON_IS_STRING(status, "WATCHING")) {
		PHALCON_OBS_VAR(watching_tube);
		phalcon_array_fetch_long(&watching_tube, response, 1, PH_NOISY);
		RETURN_CCTOR(watching_tube);
	}
	
	RETURN_MM_FALSE;
}

static void phalcon_queue_beanstalk_peek_common(zval *return_value, zval *this_ptr, zval *response TSRMLS_DC)
{
	zval *job_id, *length, *serialized = NULL, *body;

	if (!phalcon_array_isset_long_fetch(&job_id, response, 1)) {
		job_id = PHALCON_GLOBAL(z_null);
	}

	if (!phalcon_array_isset_long_fetch(&length, response, 2)) {
		length = PHALCON_GLOBAL(z_null);
	}

	PHALCON_CALL_METHODW(&serialized, this_ptr, "read", length);

	MAKE_STD_ZVAL(body);
	phalcon_unserialize(body, serialized TSRMLS_CC);
	zval_ptr_dtor(&serialized);
	if (Z_REFCOUNT_P(body) >= 1) {
		Z_DELREF_P(body);
	}

	object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
	PHALCON_CALL_METHODW(NULL, return_value, "__construct", this_ptr, job_id, body);
}

/**
 * Inspect the next ready job.
 *
 * @return boolean|\Phalcon\Queue\Beanstalk\Job
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, peekReady){

	zval *command, *response = NULL, *status;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(command);
	ZVAL_STRING(command, "peek-ready", 1);
	PHALCON_CALL_METHOD(NULL, this_ptr, "write", command);
	PHALCON_CALL_METHOD(&response, this_ptr, "readstatus");
	
	PHALCON_OBS_VAR(status);
	phalcon_array_fetch_long(&status, response, 0, PH_NOISY);
	if (PHALCON_IS_STRING(status, "FOUND")) {
		phalcon_queue_beanstalk_peek_common(return_value, getThis(), response TSRMLS_CC);
		RETURN_MM();
	}
	
	RETURN_MM_FALSE;
}

/**
 * Return the delayed job with the shortest delay left
 *
 * @return boolean|Phalcon\Queue\Beanstalk\Job
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, peekDelayed){

	zval *command, *response = NULL, *status;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(command);
	ZVAL_STRING(command, "peek-delayed", 1);
	PHALCON_CALL_METHOD(NULL, this_ptr, "write", command);
	PHALCON_CALL_METHOD(&response, this_ptr, "readstatus");

	PHALCON_OBS_VAR(status);
	phalcon_array_fetch_long(&status, response, 0, PH_NOISY);
	if (PHALCON_IS_STRING(status, "FOUND")) {
		phalcon_queue_beanstalk_peek_common(return_value, getThis(), response TSRMLS_CC);
		RETURN_MM();
	}

	RETURN_MM_FALSE;
}

/**
 * Return the next job in the list of buried jobs
 *
 * @return boolean|Phalcon\Queue\Beanstalk\Job
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, peekBuried){

	zval *command, *response = NULL, *status;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(command);
	ZVAL_STRING(command, "peek-buried", 1);
	PHALCON_CALL_METHOD(NULL, this_ptr, "write", command);
	PHALCON_CALL_METHOD(&response, this_ptr, "readstatus");

	PHALCON_OBS_VAR(status);
	phalcon_array_fetch_long(&status, response, 0, PH_NOISY);
	if (PHALCON_IS_STRING(status, "FOUND")) {
		phalcon_queue_beanstalk_peek_common(return_value, getThis(), response TSRMLS_CC);
		RETURN_MM();
	}

	RETURN_MM_FALSE;
}

/**
 * Reads the latest status from the Beanstalkd server
 *
 * @return array
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, readStatus){

	zval *response = NULL;

	PHALCON_MM_GROW();

	PHALCON_CALL_METHOD(&response, this_ptr, "read");
	phalcon_fast_explode_str(return_value, SL(" "), response);
	RETURN_MM();
}

/**
 * Reads a packet from the socket. Prior to reading from the socket will
 * check for availability of the connection.
 *
 * @param int $length Number of bytes to read.
 * @return string|boolean Data or `false` on error.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, read){

	zval **length = NULL, *connection, *meta;
	php_stream *stream;

	PHALCON_MM_GROW();

	phalcon_fetch_params_ex(0, 1, &length);
	
	if (!length) {
		length = &PHALCON_GLOBAL(z_zero);
	}
	else {
		PHALCON_ENSURE_IS_LONG(length);
	}
	
	PHALCON_OBS_VAR(connection);
	phalcon_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
		PHALCON_CALL_METHOD(&connection, this_ptr, "connect");
		if (Z_TYPE_P(connection) != IS_RESOURCE) {
			RETURN_MM_FALSE;
		}
	}
	
	php_stream_from_zval_no_verify(stream, &connection);
	if (!stream) {
		RETURN_MM_FALSE;
	}

	if (zend_is_true(*length)) {
		long int total_length;
		long int len;
		zend_bool timeout = 0;
		char *buf;
	
		if (php_stream_eof(stream)) {
			RETURN_MM_FALSE;
		}
	
		total_length = Z_LVAL_PP(length) + 2;

		buf = ecalloc(1, total_length + 1);
		len = php_stream_read(stream, buf, total_length);

		ZVAL_STRINGL(return_value, buf, len, 0);

		PHALCON_INIT_VAR(meta);
		array_init_size(meta, 4);
		if (php_stream_populate_meta_data(stream, meta)) {
			zval *t;
			if (phalcon_array_isset_string_fetch(&t, meta, SS("timed_out"))) {
				timeout = zend_is_true(t);
			}
		}

		if (timeout) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_exception_ce, "Connection timed out");
			return;
		}
	} else {
		size_t line_len = 0;
		long int len = 16384;
		char *buf = ecalloc(1, len+1);

		if (php_stream_get_line(stream, buf, len, &line_len) != NULL) {
			if (line_len < 512) {
				buf = erealloc(buf, line_len + 1);
			}

			ZVAL_STRINGL(return_value, buf, line_len, 0);
		}
		else {
			efree(buf);
			ZVAL_FALSE(return_value);
		}
	}

	if (Z_TYPE_P(return_value) == IS_STRING && Z_STRLEN_P(return_value) >= 2) {
		char *s      = Z_STRVAL_P(return_value);
		long int len = Z_STRLEN_P(return_value);

		if (s[len-1] == '\n' && s[len-2] == '\r') {
			s[len-2] = '\0';
			Z_STRLEN_P(return_value) -= 2;
		}
	}

	PHALCON_MM_RESTORE();
}

/**
 * Writes data to the socket. Performs a connection if none is available
 *
 * @param string $data
 * @return integer|boolean
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, write){

	zval *data, *connection, *packet;
	php_stream *stream;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &data);
	
	PHALCON_OBS_VAR(connection);
	phalcon_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
		PHALCON_CALL_METHOD(&connection, this_ptr, "connect");
		if (Z_TYPE_P(connection) != IS_RESOURCE) {
			RETURN_MM_FALSE;
		}
	}
	
	php_stream_from_zval_no_verify(stream, &connection);
	if (!stream) {
		RETURN_MM_FALSE;
	}

	PHALCON_INIT_VAR(packet);
	PHALCON_CONCAT_VS(packet, data, "\r\n");
	
	php_stream_write(stream, Z_STRVAL_P(packet), Z_STRLEN_P(packet));
	RETURN_MM();
}

/**
 * Closes the connection to the beanstalk server.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, disconnect){

	zval *connection;
	php_stream *stream;

	connection = phalcon_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
		RETURN_FALSE;
	}
	
	php_stream_from_zval_no_verify(stream, &connection);
	if (!stream) {
		RETURN_FALSE;
	}

	if ((stream->flags & PHP_STREAM_FLAG_NO_FCLOSE) == 0) {
		if (!stream->is_persistent) {
			zend_list_delete(stream->rsrc_id);
		}
		else {
			php_stream_pclose(stream);
		}
	}

	RETURN_TRUE;
}

PHP_METHOD(Phalcon_Queue_Beanstalk, __sleep){

	array_init_size(return_value, 1);
	add_next_index_string(return_value, "_parameters", 1);
}

PHP_METHOD(Phalcon_Queue_Beanstalk, __wakeup){

	zval *params, *host, *port;
	int fail;

	zend_update_property_null(phalcon_queue_beanstalk_ce, getThis(), SL("_connection") TSRMLS_CC);

	params = phalcon_fetch_nproperty_this(this_ptr, SL("_parameters"), PH_NOISY TSRMLS_CC);
	if (
			Z_TYPE_P(params) != IS_ARRAY
		 || !phalcon_array_isset_string_fetch(&host, params, SS("host"))
		 || !phalcon_array_isset_string_fetch(&port, params, SS("port"))
	) {
		fail = 1;
	}
	else if (Z_TYPE_P(host) != IS_STRING || Z_TYPE_P(port) != IS_LONG) {
		fail = 1;
	}
	else {
		fail = 0;
	}

	if (fail) {
		zend_throw_exception_ex(phalcon_exception_ce, 0 TSRMLS_CC, "Invalid serialization data");
	}
}
