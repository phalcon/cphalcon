
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
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"


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

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(options) != IS_ARRAY) {
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

/**
 * Makes a connection to the Beanstalkd server
 *
 * @return resource
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, connect) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *connection = NULL, *parameters, *_0, *_1, *_2, *_3, _5;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(connection);
	zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) == IS_RESOURCE) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "disconnect", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(parameters);
	zephir_read_property_this(&parameters, this_ptr, SL("_parameters"), PH_NOISY_CC);
	zephir_array_fetch_string(&_0, parameters, SL("host"), PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 81 TSRMLS_CC);
	zephir_array_fetch_string(&_1, parameters, SL("port"), PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 81 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_NULL(_3);
	Z_SET_ISREF_P(_2);
	ZEPHIR_CALL_FUNCTION(&connection, "fsockopen", &_4, _0, _1, _2, _3);
	Z_UNSET_ISREF_P(_2);
	zephir_check_call_status();
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Can't connect to Beanstalk server", "phalcon/queue/beanstalk.zep", 83);
		return;
	}
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, -1);
	ZEPHIR_CALL_FUNCTION(NULL, "stream_set_timeout", &_6, connection, &_5, ZEPHIR_GLOBAL(global_null));
	zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *data, *options = NULL, *priority, *delay, *ttr, *serialized = NULL, *response = NULL, *status, *length, *_1, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(priority);
	if (!(zephir_array_isset_string_fetch(&priority, options, SS("priority"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(priority);
		ZVAL_LONG(priority, 100);
	}
	ZEPHIR_OBS_VAR(delay);
	if (!(zephir_array_isset_string_fetch(&delay, options, SS("delay"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(delay);
		ZVAL_LONG(delay, 0);
	}
	ZEPHIR_OBS_VAR(ttr);
	if (!(zephir_array_isset_string_fetch(&ttr, options, SS("ttr"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(ttr);
		ZVAL_LONG(ttr, 86400);
	}
	ZEPHIR_CALL_FUNCTION(&serialized, "serialize", &_0, data);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(length);
	ZVAL_LONG(length, zephir_fast_strlen_ev(serialized));
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVSVSVSV(_1, "put ", priority, " ", delay, " ", ttr, " ", length);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, serialized);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus",  &_2);
	zephir_check_call_status();
	zephir_array_fetch_long(&status, response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 131 TSRMLS_CC);
	if (ZEPHIR_IS_STRING(status, "INSERTED")) {
		zephir_array_fetch_long(&_3, response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 134 TSRMLS_CC);
		RETURN_CTOR(_3);
	}
	if (ZEPHIR_IS_STRING(status, "BURIED")) {
		zephir_array_fetch_long(&_3, response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 138 TSRMLS_CC);
		RETURN_CTOR(_3);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Reserves a job in the queue
 *
 * @return boolean|Phalcon\Queue\Beanstalk\Job
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, reserve) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *timeout = NULL, *command, *response = NULL, *_1, *_2, *_3 = NULL, *_4, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &timeout);

	if (!timeout) {
		timeout = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(command);
	if (Z_TYPE_P(timeout) != IS_NULL) {
		ZEPHIR_CONCAT_SV(command, "reserve-with-timeout ", timeout);
	} else {
		ZVAL_STRING(command, "reserve", 1);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, command);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus",  &_0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 162 TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_1, "RESERVED")) {
		object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
		zephir_array_fetch_long(&_2, response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 170 TSRMLS_CC);
		zephir_array_fetch_long(&_4, response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 170 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "read", NULL, _4);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_5, "unserialize", &_6, _3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr, _2, _5);
		zephir_check_call_status();
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *tube_param = NULL, *response = NULL, *_2, *_3;
	zval *tube = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tube_param);

	if (unlikely(Z_TYPE_P(tube_param) != IS_STRING && Z_TYPE_P(tube_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tube' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(tube_param) == IS_STRING)) {
		tube = tube_param;
	} else {
		ZEPHIR_INIT_VAR(tube);
		ZVAL_EMPTY_STRING(tube);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "use ", tube);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus",  &_1);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 189 TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_2, "USING")) {
		zephir_array_fetch_long(&_3, response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 190 TSRMLS_CC);
		RETURN_CTOR(_3);
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *tube_param = NULL, *response = NULL, *_2, *_3;
	zval *tube = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tube_param);

	if (unlikely(Z_TYPE_P(tube_param) != IS_STRING && Z_TYPE_P(tube_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tube' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(tube_param) == IS_STRING)) {
		tube = tube_param;
	} else {
		ZEPHIR_INIT_VAR(tube);
		ZVAL_EMPTY_STRING(tube);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "watch ", tube);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus",  &_1);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 209 TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_2, "WATCHING")) {
		zephir_array_fetch_long(&_3, response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 210 TSRMLS_CC);
		RETURN_CTOR(_3);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Inspect the next ready job.
 *
 * @return boolean|Phalcon\Queue\Beanstalk\Job
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, peekReady) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *response = NULL, *_0, *_2, *_3, *_4 = NULL, *_5, *_6 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "peek-ready", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus",  &_1);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 228 TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_2, "FOUND")) {
		object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
		zephir_array_fetch_long(&_3, response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 229 TSRMLS_CC);
		zephir_array_fetch_long(&_5, response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 229 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "read", NULL, _5);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_6, "unserialize", &_7, _4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr, _3, _6);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(0);

}

/**
 * Return the next job in the list of buried jobs
 *
 * @return boolean|Phalcon\Queue\Beanstalk\Job
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, peekBuried) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *response = NULL, *_0, *_2, *_3, *_4 = NULL, *_5, *_6 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "peek-buried", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus",  &_1);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 247 TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_2, "FOUND")) {
		object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
		zephir_array_fetch_long(&_3, response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 248 TSRMLS_CC);
		zephir_array_fetch_long(&_5, response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 248 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "read", NULL, _5);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_6, "unserialize", &_7, _4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr, _3, _6);
		zephir_check_call_status();
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "read",  NULL);
	zephir_check_call_status();
	zephir_fast_explode_str(return_value, SL(" "), _0, LONG_MAX TSRMLS_CC);
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_6 = NULL;
	zval *length_param = NULL, *connection = NULL, *data = NULL, _0 = zval_used_for_init, *_2 = NULL, *_4, _5;
	int length, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &length_param);

	if (!length_param) {
		length = 0;
	} else {
		length = zephir_get_intval(length_param);
	}


	ZEPHIR_OBS_VAR(connection);
	zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
		ZEPHIR_CALL_METHOD(&connection, this_ptr, "connect",  NULL);
		zephir_check_call_status();
		if (Z_TYPE_P(connection) != IS_RESOURCE) {
			RETURN_MM_BOOL(0);
		}
	}
	if (length) {
		if (zephir_feof(connection TSRMLS_CC)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, (length + 2));
		ZEPHIR_CALL_FUNCTION(&data, "fread", &_1, connection, &_0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_2, "stream_get_meta_data", &_3, connection);
		zephir_check_call_status();
		zephir_array_fetch_string(&_4, _2, SL("timed_out"), PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 290 TSRMLS_CC);
		if (zephir_is_true(_4)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Connection timed out", "phalcon/queue/beanstalk.zep", 291);
			return;
		}
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "\r\n", 0);
		zephir_fast_trim(return_value, data, &_0, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		RETURN_MM();
	}
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 16384);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "\r\n", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("stream_get_line", &_6, connection, &_0, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Writes data to the socket. Performs a connection if none is available
 *
 * @param string data
 * @return integer|boolean
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, write) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *connection = NULL, *packet, _0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_OBS_VAR(connection);
	zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
		ZEPHIR_CALL_METHOD(&connection, this_ptr, "connect",  NULL);
		zephir_check_call_status();
		if (Z_TYPE_P(connection) != IS_RESOURCE) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(packet);
	ZEPHIR_CONCAT_VS(packet, data, "\r\n");
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, zephir_fast_strlen_ev(packet));
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", &_1, connection, packet, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Closes the connection to the beanstalk server.
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, disconnect) {

	zval *connection;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(connection);
	zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
		RETURN_MM_BOOL(0);
	}
	zephir_fclose(connection TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

