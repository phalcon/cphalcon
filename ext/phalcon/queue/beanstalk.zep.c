
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"


/**
 * Phalcon\Queue\Beanstalk
 *
 * Class to access the beanstalk queue service.
 * Partially implements the protocol version 1.2
 *
 * <code>
 * use Phalcon\Queue\Beanstalk;
 *
 * $queue = new Beanstalk([
 *     'host'       => '127.0.0.1',
 *     'port'       => 11300,
 *     'persistent' => true,
 * ]);
 * </code>
 *
 * @link http://www.igvita.com/2010/05/20/scalable-work-queues-with-beanstalk/
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

	zval *options = NULL, *parameters = NULL, *_0$$5, *_1$$6;

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
		ZEPHIR_INIT_VAR(_0$$5);
		ZVAL_STRING(_0$$5, "127.0.0.1", 1);
		zephir_array_update_string(&parameters, SL("host"), &_0$$5, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(parameters, SS("port")))) {
		ZEPHIR_INIT_VAR(_1$$6);
		ZVAL_LONG(_1$$6, 11300);
		zephir_array_update_string(&parameters, SL("port"), &_1$$6, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_this(this_ptr, SL("_parameters"), parameters TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Makes a connection to the Beanstalkd server
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, connect) {

	zval *connection = NULL, *parameters = NULL, *persistent = NULL, *function = NULL, *_0, *_1, *_2, *_3, _4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(connection);
	zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) == IS_RESOURCE) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "disconnect", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(parameters);
	zephir_read_property_this(&parameters, this_ptr, SL("_parameters"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(persistent);
	if (zephir_array_isset_string_fetch(&persistent, parameters, SS("persistent"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(function);
		if (zephir_is_true(persistent)) {
			ZVAL_STRING(function, "pfsockopen", 1);
		} else {
			ZVAL_STRING(function, "fsockopen", 1);
		}
	} else {
		ZEPHIR_INIT_NVAR(function);
		ZVAL_STRING(function, "fsockopen", 1);
	}
	zephir_array_fetch_string(&_0, parameters, SL("host"), PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 102 TSRMLS_CC);
	zephir_array_fetch_string(&_1, parameters, SL("port"), PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 102 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_NULL(_2);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_NULL(_3);
	ZEPHIR_CALL_ZVAL_FUNCTION(&connection, function, NULL, 0, _0, _1, _2, _3);
	zephir_check_call_status();
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_beanstalk_exception_ce, "Can't connect to Beanstalk server", "phalcon/queue/beanstalk.zep", 105);
		return;
	}
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, -1);
	ZEPHIR_CALL_FUNCTION(NULL, "stream_set_timeout", NULL, 381, connection, &_4, ZEPHIR_GLOBAL(global_null));
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_connection"), connection TSRMLS_CC);
	RETURN_CCTOR(connection);

}

/**
 * Inserts jobs into the queue
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, put) {

	zend_bool _2;
	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;
	zval *data, *options_param = NULL, *priority = NULL, *delay = NULL, *ttr = NULL, *serialized = NULL, *response = NULL, *status = NULL, *length = NULL, *_0, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		zephir_get_arrval(options, options_param);
	}


	ZEPHIR_OBS_VAR(priority);
	if (!(zephir_array_isset_string_fetch(&priority, options, SS("priority"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(priority);
		ZVAL_LONG(priority, 100);
	}
	ZEPHIR_OBS_VAR(delay);
	if (!(zephir_array_isset_string_fetch(&delay, options, SS("delay"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(delay);
		ZVAL_LONG(delay, 0);
	}
	ZEPHIR_OBS_VAR(ttr);
	if (!(zephir_array_isset_string_fetch(&ttr, options, SS("ttr"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(ttr);
		ZVAL_LONG(ttr, 86400);
	}
	ZEPHIR_CALL_FUNCTION(&serialized, "serialize", NULL, 75, data);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(length);
	ZVAL_LONG(length, zephir_fast_strlen_ev(serialized));
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVSVSVSV(_0, "put ", priority, " ", delay, " ", ttr, " ", length);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", &_1, 0, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", &_1, 0, serialized);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 382);
	zephir_check_call_status();
	zephir_array_fetch_long(&status, response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 150 TSRMLS_CC);
	_2 = !ZEPHIR_IS_STRING(status, "INSERTED");
	if (_2) {
		_2 = !ZEPHIR_IS_STRING(status, "BURIED");
	}
	if (_2) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_3, response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 156 TSRMLS_CC);
	RETURN_CTOR(_3);

}

/**
 * Reserves a job in the queue
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, reserve) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *timeout = NULL, *command = NULL, *response = NULL, *_0, *_1, *_2 = NULL, *_3, *_4 = NULL;

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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, command);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 382);
	zephir_check_call_status();
	zephir_array_fetch_long(&_0, response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 175 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(_0, "RESERVED")) {
		RETURN_MM_BOOL(0);
	}
	object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
	zephir_array_fetch_long(&_1, response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 185 TSRMLS_CC);
	zephir_array_fetch_long(&_3, response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 185 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "read", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "unserialize", NULL, 76, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 383, this_ptr, _1, _4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Change the active tube. By default the tube is "default"
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, choose) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tube_param = NULL, *response = NULL, *_1, *_2;
	zval *tube = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tube_param);

	if (unlikely(Z_TYPE_P(tube_param) != IS_STRING && Z_TYPE_P(tube_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tube' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tube_param) == IS_STRING)) {
		zephir_get_strval(tube, tube_param);
	} else {
		ZEPHIR_INIT_VAR(tube);
		ZVAL_EMPTY_STRING(tube);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "use ", tube);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 382);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 198 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(_1, "USING")) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_2, response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 202 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * Change the active tube. By default the tube is "default"
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, watch) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tube_param = NULL, *response = NULL, *_1, *_2;
	zval *tube = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tube_param);

	if (unlikely(Z_TYPE_P(tube_param) != IS_STRING && Z_TYPE_P(tube_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tube' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tube_param) == IS_STRING)) {
		zephir_get_strval(tube, tube_param);
	} else {
		ZEPHIR_INIT_VAR(tube);
		ZVAL_EMPTY_STRING(tube);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "watch ", tube);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 382);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 215 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(_1, "WATCHING")) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_2, response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 219 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * Get stats of the Beanstalk server.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, stats) {

	zval *response = NULL, *_0, *_1, *_2;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "stats", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readyaml", NULL, 384);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 232 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(_1, "OK")) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_2, response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 236 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * Get stats of a tube.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, statsTube) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tube_param = NULL, *response = NULL, *_1, *_2;
	zval *tube = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tube_param);

	if (unlikely(Z_TYPE_P(tube_param) != IS_STRING && Z_TYPE_P(tube_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tube' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tube_param) == IS_STRING)) {
		zephir_get_strval(tube, tube_param);
	} else {
		ZEPHIR_INIT_VAR(tube);
		ZVAL_EMPTY_STRING(tube);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SV(_0, "stats-tube ", tube);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readyaml", NULL, 384);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 249 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(_1, "OK")) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_2, response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 253 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * Get list of a tubes.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, listTubes) {

	zval *response = NULL, *_0, *_1, *_2;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "list-tubes", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readyaml", NULL, 384);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 266 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(_1, "OK")) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_2, response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 270 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * Inspect the next ready job.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, peekReady) {

	zval *response = NULL, *_0, *_1, *_2, *_3 = NULL, *_4, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "peek-ready", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 382);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 283 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(_1, "FOUND")) {
		RETURN_MM_BOOL(0);
	}
	object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
	zephir_array_fetch_long(&_2, response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 287 TSRMLS_CC);
	zephir_array_fetch_long(&_4, response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 287 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "read", NULL, 0, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "unserialize", NULL, 76, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 383, this_ptr, _2, _5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the next job in the list of buried jobs
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, peekBuried) {

	zval *response = NULL, *_0, *_1, *_2, *_3 = NULL, *_4, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "peek-buried", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 382);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 300 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(_1, "FOUND")) {
		RETURN_MM_BOOL(0);
	}
	object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
	zephir_array_fetch_long(&_2, response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 304 TSRMLS_CC);
	zephir_array_fetch_long(&_4, response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 304 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "read", NULL, 0, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "unserialize", NULL, 76, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 383, this_ptr, _2, _5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Reads the latest status from the Beanstalkd server
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, readStatus) {

	zval *status = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&status, this_ptr, "read", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(status)) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_fast_explode_str(return_value, SL(" "), status, LONG_MAX TSRMLS_CC);
	RETURN_MM();

}

/**
 * Fetch a YAML payload from the Beanstalkd server
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, readYaml) {

	zval *response = NULL, *status = NULL, *numberOfBytes = NULL, *data = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 382);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(status);
	zephir_array_fetch_long(&status, response, 0, PH_NOISY, "phalcon/queue/beanstalk.zep", 329 TSRMLS_CC);
	if (zephir_fast_count_int(response TSRMLS_CC) > 1) {
		ZEPHIR_OBS_VAR(numberOfBytes);
		zephir_array_fetch_long(&numberOfBytes, response, 1, PH_NOISY, "phalcon/queue/beanstalk.zep", 332 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&response, this_ptr, "read", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&data, "yaml_parse", NULL, 385, response);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(numberOfBytes);
		ZVAL_LONG(numberOfBytes, 0);
		ZEPHIR_INIT_NVAR(data);
		array_init(data);
	}
	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, status);
	zephir_array_fast_append(return_value, numberOfBytes);
	zephir_array_fast_append(return_value, data);
	RETURN_MM();

}

/**
 * Reads a packet from the socket. Prior to reading from the socket will
 * check for availability of the connection.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, read) {

	zephir_fcall_cache_entry *_1 = NULL;
	zval *length_param = NULL, *connection = NULL, *data = NULL, _4, _5, _0$$5 = zval_used_for_init, *_2$$5 = NULL, *_3$$5;
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
		ZEPHIR_CALL_METHOD(&connection, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(connection) != IS_RESOURCE) {
			RETURN_MM_BOOL(0);
		}
	}
	if (length) {
		if (zephir_feof(connection TSRMLS_CC)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_SINIT_VAR(_0$$5);
		ZVAL_LONG(&_0$$5, (length + 2));
		ZEPHIR_CALL_FUNCTION(&data, "stream_get_line", &_1, 386, connection, &_0$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_2$$5, "stream_get_meta_data", NULL, 387, connection);
		zephir_check_call_status();
		zephir_array_fetch_string(&_3$$5, _2$$5, SL("timed_out"), PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 373 TSRMLS_CC);
		if (zephir_is_true(_3$$5)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_beanstalk_exception_ce, "Connection timed out", "phalcon/queue/beanstalk.zep", 374);
			return;
		}
		ZEPHIR_SINIT_NVAR(_0$$5);
		ZVAL_STRING(&_0$$5, "\r\n", 0);
		zephir_fast_trim(return_value, data, &_0$$5, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		RETURN_MM();
	}
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 16384);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_STRING(&_5, "\r\n", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("stream_get_line", &_1, 386, connection, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Writes data to the socket. Performs a connection if none is available
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, write) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *connection = NULL, *packet = NULL, _1;
	zval *data = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_strval(data, data_param);


	ZEPHIR_OBS_VAR(connection);
	zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
		ZEPHIR_CALL_METHOD(&connection, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(connection) != IS_RESOURCE) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_VS(_0, data, "\r\n");
	ZEPHIR_CPY_WRT(packet, _0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, zephir_fast_strlen_ev(packet));
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 388, connection, packet, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Closes the connection to the beanstalk server.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, disconnect) {

	zval *connection = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(connection);
	zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) != IS_RESOURCE) {
		RETURN_MM_BOOL(0);
	}
	zephir_fclose(connection TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

