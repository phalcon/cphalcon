
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"


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
/**
* Phalcon\Queue\Beanstalk
*
* Class to access the beanstalk queue service.
* Partially implements the protocol version 1.2
*
* @see http://www.igvita.com/2010/05/20/scalable-work-queues-with-beanstalk/
*/
ZEPHIR_INIT_CLASS(Phalcon_Queue_Beanstalk) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue, Beanstalk, phalcon, queue_beanstalk, phalcon_queue_beanstalk_method_entry, 0);

	zend_declare_property_null(phalcon_queue_beanstalk_ce, SL("_connection"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_queue_beanstalk_ce, SL("_parameters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Queue\Beanstalk
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, __construct) {

	zval *options = NULL, *parameters = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options || Z_TYPE_P(options) == IS_NULL) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if ((Z_TYPE_P(options) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(parameters);
		array_init(parameters);
	} else {
		ZEPHIR_CPY_WRT(parameters, options);
	}
	if (!(zephir_array_isset_string(parameters, SS("host")))) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "127.0.0.1", 1);
		zephir_array_update_string(&parameters, SL("host"), &_0, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(parameters, SS("port")))) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, 11300);
		zephir_array_update_string(&parameters, SL("port"), &_0, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_this(this_ptr, SL("_parameters"), parameters TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Phalcon_Queue_Beanstalk, connect) {

	zval *connection, *parameters, *_0, *_1, *_2, *_3, _4;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(connection);
	zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "is_resource", connection);
	if (zephir_is_true(_0)) {
		zephir_call_method_noret(this_ptr, "disconnect");
	}
	parameters = zephir_fetch_nproperty_this(this_ptr, SL("_parameters"), PH_NOISY_CC);
	zephir_array_fetch_string(&_1, parameters, SL("host"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&_2, parameters, SL("port"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_INIT_BNVAR(connection);
	zephir_call_func_p4(connection, "fsockopen", _1, _2, ZEPHIR_GLOBAL(global_null), ZEPHIR_GLOBAL(global_null));
	ZEPHIR_INIT_VAR(_3);
	zephir_call_func_p1(_3, "is_resource", connection);
	if (!(zephir_is_true(_3))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_exception_ce, "Can't connect to Beanstalk server");
		return;
	}
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, -1);
	zephir_call_func_p3_noret("stream_set_timeout", connection, &_4, ZEPHIR_GLOBAL(global_null));
	zephir_update_property_this(this_ptr, SL("_connection"), connection TSRMLS_CC);
	RETURN_CCTOR(connection);

}

/**
 * Inserts jobs into the queue
 *
 * @param string data
 * @param array options
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, put) {

	zval *data, *options = NULL, *priority = NULL, *delay = NULL, *ttr = NULL, *serialized, *serializedLength, *command, *response, *status, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &options);

	if (!options || Z_TYPE_P(options) == IS_NULL) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_array_isset_string(options, SS("priority"))) {
		ZEPHIR_OBS_VAR(priority);
		zephir_array_fetch_string(&priority, options, SL("priority"), PH_NOISY TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(priority);
		ZVAL_LONG(priority, 100);
	}
	if (zephir_array_isset_string(options, SS("delay"))) {
		ZEPHIR_OBS_VAR(delay);
		zephir_array_fetch_string(&delay, options, SL("delay"), PH_NOISY TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(delay);
		ZVAL_LONG(delay, 0);
	}
	if (zephir_array_isset_string(options, SS("ttr"))) {
		ZEPHIR_OBS_VAR(ttr);
		zephir_array_fetch_string(&ttr, options, SL("ttr"), PH_NOISY TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(ttr);
		ZVAL_LONG(ttr, 86400);
	}
	ZEPHIR_INIT_VAR(serialized);
	zephir_call_func_p1(serialized, "serialize", data);
	ZEPHIR_INIT_VAR(serializedLength);
	ZVAL_LONG(serializedLength, zephir_fast_strlen_ev(serialized));
	ZEPHIR_INIT_VAR(command);
	ZEPHIR_CONCAT_SVSVSVSV(command, "put ", priority, " ", delay, " ", ttr, " ", serializedLength);
	zephir_call_method_p1_noret(this_ptr, "write", command);
	zephir_call_method_p1_noret(this_ptr, "write", serialized);
	ZEPHIR_INIT_VAR(response);
	zephir_call_method(response, this_ptr, "readstatus");
	zephir_array_fetch_long(&status, response, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_STRING(status, "INSERTED")) {
		zephir_array_fetch_long(&_0, response, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_0);
	}
	if (ZEPHIR_IS_STRING(status, "BURIED")) {
		zephir_array_fetch_long(&_0, response, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_0);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Reserves a job in the queue
 *
 * @return boolean|Phalcon\Queue\Beanstalk\Job
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, reserve) {

	zval *timeout = NULL, *command, *response, *status, *jobId, *length, *serializedBody, *body;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &timeout);

	if (!timeout || Z_TYPE_P(timeout) == IS_NULL) {
		timeout = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(command);
	if (zephir_is_true(timeout)) {
		ZEPHIR_CONCAT_SV(command, "reserve-with-timeout ", timeout);
	} else {
		ZVAL_STRING(command, "reserve", 1);
	}
	zephir_call_method_p1_noret(this_ptr, "write", command);
	ZEPHIR_INIT_VAR(response);
	zephir_call_method(response, this_ptr, "readstatus");
	zephir_array_fetch_long(&status, response, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_STRING(status, "RESERVED")) {
		zephir_array_fetch_long(&jobId, response, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_long(&length, response, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_VAR(serializedBody);
		zephir_call_method_p1(serializedBody, this_ptr, "read", length);
		ZEPHIR_INIT_VAR(body);
		zephir_call_func_p1(body, "unserialize", serializedBody);
		object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
		zephir_call_method_p3_noret(return_value, "__construct", this_ptr, jobId, body);
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Change the active tube. By default the tube is "default"
 *
 * @param string tube
 * @return string|boolean
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, choose) {

	zval *tube, *command, *response, *status, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tube);



	ZEPHIR_INIT_VAR(command);
	ZEPHIR_CONCAT_SV(command, "use ", tube);
	zephir_call_method_p1_noret(this_ptr, "write", command);
	ZEPHIR_INIT_VAR(response);
	zephir_call_method(response, this_ptr, "readstatus");
	zephir_array_fetch_long(&status, response, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_STRING(status, "USING")) {
		zephir_array_fetch_long(&_0, response, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_0);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Change the active tube. By default the tube is "default"
 *
 * @param string tube
 * @return string|boolean
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, watch) {

	zval *tube, *command, *response, *status, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tube);



	ZEPHIR_INIT_VAR(command);
	ZEPHIR_CONCAT_SV(command, "watch ", tube);
	zephir_call_method_p1_noret(this_ptr, "write", command);
	ZEPHIR_INIT_VAR(response);
	zephir_call_method(response, this_ptr, "readstatus");
	zephir_array_fetch_long(&status, response, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_STRING(status, "WATCH")) {
		zephir_array_fetch_long(&_0, response, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_0);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Inspect the next ready job.
 *
 * @return boolean|Phalcon\Queue\Beanstalk\Job
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, peekReady) {

	zval *command, *response, *status, *jobId, *length, *serializedBody, *body;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(command);
	ZVAL_STRING(command, "peek-ready", 1);
	zephir_call_method_p1_noret(this_ptr, "write", command);
	ZEPHIR_INIT_VAR(response);
	zephir_call_method(response, this_ptr, "readstatus");
	zephir_array_fetch_long(&status, response, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_STRING(status, "FOUND")) {
		zephir_array_fetch_long(&jobId, response, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_long(&length, response, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_VAR(serializedBody);
		zephir_call_method_p1(serializedBody, this_ptr, "read", length);
		ZEPHIR_INIT_VAR(body);
		zephir_call_func_p1(body, "unserialize", serializedBody);
		object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
		zephir_call_method_p3_noret(return_value, "__construct", this_ptr, jobId, body);
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Reads the latest status from the Beanstalkd server
 *
 * @return array
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, readStatus) {

	zval *_0, _1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "read");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, " ", 0);
	zephir_call_func_p2(return_value, "explode", &_1, _0);
	RETURN_MM();

}

/**
 * Reads a packet from the socket. Prior to reading from the socket will
 * check for availability of the connection.
 *
 * @param int length Number of bytes to read.
 * @return string|boolean Data or `false` on error.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, read) {

	zval *length = NULL, *connection, *isEof, *totalLength, *data, *meta, *timeout, *packet, *_0, *_1, _2 = zval_used_for_init, _3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &length);

	if (!length || Z_TYPE_P(length) == IS_NULL) {
		length = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(connection);
	zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "is_resource", connection);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_BNVAR(connection);
		zephir_call_method(connection, this_ptr, "connect");
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func_p1(_1, "is_resource", connection);
		if (!(zephir_is_true(_1))) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(packet);
	if (zephir_is_true(length)) {
		ZEPHIR_INIT_VAR(isEof);
		ZVAL_BOOL(isEof, zephir_feof(connection));
		if (zephir_is_true(isEof)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(totalLength);
		ZVAL_LONG(totalLength, (zephir_get_numberval(length) + 2));
		ZEPHIR_INIT_VAR(data);
		zephir_call_func_p2(data, "fread", connection, totalLength);
		ZEPHIR_INIT_VAR(meta);
		zephir_call_func_p1(meta, "stream_get_meta_data", connection);
		zephir_array_fetch_string(&timeout, meta, SL("timed_out"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if (zephir_is_true(timeout)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_exception_ce, "Connection timed out");
			return;
		}
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "\r\n", 0);
		zephir_call_func_p2(packet, "rtrim", data, &_2);
	} else {
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, 16384);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "\r\n", 0);
		zephir_call_func_p3(packet, "stream_get_line", connection, &_2, &_3);
	}
	RETURN_CCTOR(packet);

}

/**
 * Writes data to the socket. Performs a connection if none is available
 *
 * @param string data
 * @return integer|boolean
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, write) {

	zval *data, *connection, *packet, *_0, *_1, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_OBS_VAR(connection);
	zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "is_resource", connection);
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_BNVAR(connection);
		zephir_call_method(connection, this_ptr, "connect");
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func_p1(_1, "is_resource", connection);
		if (!(zephir_is_true(_1))) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(packet);
	ZEPHIR_CONCAT_VS(packet, data, "\r\n");
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, zephir_fast_strlen_ev(packet));
	zephir_call_func_p3(return_value, "fwrite", connection, packet, &_2);
	RETURN_MM();

}

/**
 * Closes the connection to the beanstalk server.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, disconnect) {

	zval *connection, *_0;

	ZEPHIR_MM_GROW();

	connection = zephir_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "is_resource", connection);
	if (!(zephir_is_true(_0))) {
		RETURN_MM_BOOL(0);
	}
	zephir_call_func_p1_noret("fclose", connection);
	RETURN_MM_BOOL(1);

}

