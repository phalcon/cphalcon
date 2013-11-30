
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

#include "ext/standard/file.h"
#include "main/php_streams.h"

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

	phalcon_fetch_params(1, 0, 1, &options);
	
	if (!options) {
		options = PHALCON_GLOBAL(z_null);
	}
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_INIT_VAR(parameters);
		array_init(parameters);
	} else {
		PHALCON_CPY_WRT(parameters, options);
	}
	if (!phalcon_array_isset_string(parameters, SS("host"))) {
		phalcon_array_update_string_string(&parameters, SL("host"), SL("127.0.0.1"), PH_SEPARATE);
	}
	
	if (!phalcon_array_isset_string(parameters, SS("port"))) {
		phalcon_array_update_string_long(&parameters, SL("port"), 11300, PH_SEPARATE);
	}
	
	phalcon_update_property_this(this_ptr, SL("_parameters"), parameters TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Beanstalk, connect){

	zval *connection = NULL, *parameters, *host, *port;

	connection = phalcon_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) == IS_RESOURCE) {
		PHALCON_MM_GROW();
		phalcon_call_method_noret(this_ptr, "disconnect");
		PHALCON_MM_RESTORE();
	}
	
	parameters = phalcon_fetch_nproperty_this(this_ptr, SL("_parameters"), PH_NOISY_CC);
	
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
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, put){

	zval *data, *options = NULL, *priority = NULL, *delay = NULL, *ttr = NULL, *serialized;
	zval *serialized_length, *command, *response;
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
	phalcon_call_method_p1_noret(this_ptr, "write", command);
	phalcon_call_method_p1_noret(this_ptr, "write", serialized);
	
	PHALCON_INIT_VAR(response);
	phalcon_call_method(response, this_ptr, "readstatus");
	
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
 * @return boolean|Phalcon\Queue\Beanstalk\Job
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, reserve){

	zval *timeout = NULL, *command = NULL, *response, *status, *job_id;
	zval *length, *serialized_body, *body;

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
	phalcon_call_method_p1_noret(this_ptr, "write", command);
	
	PHALCON_INIT_VAR(response);
	phalcon_call_method(response, this_ptr, "readstatus");
	
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
		PHALCON_INIT_VAR(serialized_body);
		phalcon_call_method_p1(serialized_body, this_ptr, "read", length);
	
		PHALCON_INIT_VAR(body);
		phalcon_unserialize(body, serialized_body TSRMLS_CC);
	
		/** 
		 * Create a beanstalk job abstraction
		 */
		object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
		phalcon_call_method_p3_noret(return_value, "__construct", this_ptr, job_id, body);
	
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

	zval *tube, *command, *response, *status, *using_tube;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &tube);
	
	PHALCON_INIT_VAR(command);
	PHALCON_CONCAT_SV(command, "use ", tube);
	phalcon_call_method_p1_noret(this_ptr, "write", command);
	
	PHALCON_INIT_VAR(response);
	phalcon_call_method(response, this_ptr, "readstatus");
	
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

	zval *tube, *command, *response, *status, *watching_tube;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &tube);
	
	PHALCON_INIT_VAR(command);
	PHALCON_CONCAT_SV(command, "watch ", tube);
	phalcon_call_method_p1_noret(this_ptr, "write", command);
	
	PHALCON_INIT_VAR(response);
	phalcon_call_method(response, this_ptr, "readstatus");
	
	PHALCON_OBS_VAR(status);
	phalcon_array_fetch_long(&status, response, 0, PH_NOISY);
	if (PHALCON_IS_STRING(status, "WATCH")) {
		PHALCON_OBS_VAR(watching_tube);
		phalcon_array_fetch_long(&watching_tube, response, 1, PH_NOISY);
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
	zval *serialized_body, *body;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(command);
	ZVAL_STRING(command, "peek-ready", 1);
	phalcon_call_method_p1_noret(this_ptr, "write", command);
	
	PHALCON_INIT_VAR(response);
	phalcon_call_method(response, this_ptr, "readstatus");
	
	PHALCON_OBS_VAR(status);
	phalcon_array_fetch_long(&status, response, 0, PH_NOISY);
	if (PHALCON_IS_STRING(status, "FOUND")) {
		PHALCON_OBS_VAR(job_id);
		phalcon_array_fetch_long(&job_id, response, 1, PH_NOISY);
	
		PHALCON_OBS_VAR(length);
		phalcon_array_fetch_long(&length, response, 2, PH_NOISY);
	
		PHALCON_INIT_VAR(serialized_body);
		phalcon_call_method_p1(serialized_body, this_ptr, "read", length);
	
		PHALCON_INIT_VAR(body);
		phalcon_unserialize(body, serialized_body TSRMLS_CC);
		object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
		phalcon_call_method_p3_noret(return_value, "__construct", this_ptr, job_id, body);
	
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

	zval *response;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(response);
	phalcon_call_method(response, this_ptr, "read");
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
	phalcon_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
		PHALCON_INIT_NVAR(connection);
		phalcon_call_method(connection, this_ptr, "connect");
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
	phalcon_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
	
		PHALCON_INIT_NVAR(connection);
		phalcon_call_method(connection, this_ptr, "connect");
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

	connection = phalcon_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY_CC);
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

