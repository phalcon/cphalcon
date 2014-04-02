
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

PHP_METHOD(Phalcon_Queue_Beanstalk, connect) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *connection = NULL, *parameters, *_0, *_1, _3;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(connection);
	zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) == IS_RESOURCE) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "disconnect", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(parameters);
	zephir_read_property_this(&parameters, this_ptr, SL("_parameters"), PH_NOISY_CC);
	zephir_array_fetch_string(&_0, parameters, SL("host"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_array_fetch_string(&_1, parameters, SL("port"), PH_NOISY | PH_READONLY TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&connection, "fsockopen", &_2, _0, _1, ZEPHIR_GLOBAL(global_null), ZEPHIR_GLOBAL(global_null));
	zephir_check_call_status();
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Can't connect to Beanstalk server", "phalcon/queue/beanstalk.zep", 76);
		return;
	}
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, -1);
	ZEPHIR_CALL_FUNCTION(NULL, "stream_set_timeout", &_4, connection, &_3, ZEPHIR_GLOBAL(global_null));
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
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *data, *options = NULL, *priority = NULL, *delay = NULL, *ttr = NULL, *serialized = NULL, *response = NULL, *status, *length, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &options);

	if (!options) {
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
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus",  NULL);
	zephir_check_call_status();
	zephir_array_fetch_long(&status, response, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_STRING(status, "INSERTED")) {
		zephir_array_fetch_long(&_2, response, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	if (ZEPHIR_IS_STRING(status, "BURIED")) {
		zephir_array_fetch_long(&_2, response, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Reserves a job in the queue
 *
 * @return boolean|Phalcon\Queue\Beanstalk\Job
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, reserve) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *timeout = NULL, *command, *response = NULL, *jobId, *length, *_0, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &timeout);

	if (!timeout) {
		timeout = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(command);
	if (zephir_is_true(timeout)) {
		ZEPHIR_CONCAT_SV(command, "reserve-with-timeout ", timeout);
	} else {
		ZVAL_STRING(command, "reserve", 1);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, command);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus",  NULL);
	zephir_check_call_status();
	zephir_array_fetch_long(&_0, response, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_0, "RESERVED")) {
		ZEPHIR_OBS_VAR(jobId);
		zephir_array_fetch_long(&jobId, response, 1, PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_VAR(length);
		zephir_array_fetch_long(&length, response, 2, PH_NOISY TSRMLS_CC);
		object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "read", NULL, length);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_2, "unserialize", &_3, _1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr, jobId, _2);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tube, *response = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tube);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "use ", tube);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus",  NULL);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, response, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_1, "USING")) {
		zephir_array_fetch_long(&_2, response, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_2);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tube, *response = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tube);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "watch ", tube);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus",  NULL);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, response, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_1, "WATCH")) {
		zephir_array_fetch_long(&_2, response, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_2);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Inspect the next ready job.
 *
 * @return boolean|Phalcon\Queue\Beanstalk\Job
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, peekReady) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *response = NULL, *jobId, *length, *_0, *_1, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "peek-ready", 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus",  NULL);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, response, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_1, "FOUND")) {
		ZEPHIR_OBS_VAR(jobId);
		zephir_array_fetch_long(&jobId, response, 1, PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_VAR(length);
		zephir_array_fetch_long(&length, response, 2, PH_NOISY TSRMLS_CC);
		object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "read", NULL, length);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_3, "unserialize", &_4, _2);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, this_ptr, jobId, _3);
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

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *length = NULL, *connection = NULL, *data = NULL, *meta = NULL, *packet = NULL, _0 = zval_used_for_init, *_3, _4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &length);

	if (!length) {
		length = ZEPHIR_GLOBAL(global_null);
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
	ZEPHIR_INIT_VAR(packet);
	if (zephir_is_true(length)) {
		if (zephir_feof(connection TSRMLS_CC)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, (zephir_get_numberval(length) + 2));
		ZEPHIR_CALL_FUNCTION(&data, "fread", &_1, connection, &_0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&meta, "stream_get_meta_data", &_2, connection);
		zephir_check_call_status();
		zephir_array_fetch_string(&_3, meta, SL("timed_out"), PH_NOISY | PH_READONLY TSRMLS_CC);
		if (zephir_is_true(_3)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_exception_ce, "Connection timed out", "phalcon/queue/beanstalk.zep", 283);
			return;
		}
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "\r\n", 0);
		zephir_fast_trim(packet, data, &_0, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	} else {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 16384);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "\r\n", 0);
		ZEPHIR_CALL_FUNCTION(&packet, "stream_get_line", &_5, connection, &_0, &_4);
		zephir_check_call_status();
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

