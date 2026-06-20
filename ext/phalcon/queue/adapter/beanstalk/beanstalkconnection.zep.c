
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Dependency-free socket client for the Beanstalkd work queue, implementing
 * the subset of the 1.2 protocol the adapter needs (use/watch/ignore, put,
 * reserve-with-timeout, delete/release/bury/touch). Recovered and trimmed
 * from the original Phalcon\Queue\Beanstalk transport.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter\\Beanstalk, BeanstalkConnection, phalcon, queue_adapter_beanstalk_beanstalkconnection, phalcon_queue_adapter_beanstalk_beanstalkconnection_method_entry, 0);

	/**
	 * Connection resource.
	 *
	 * @var resource
	 */
	zend_declare_property_null(phalcon_queue_adapter_beanstalk_beanstalkconnection_ce, SL("connection"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_queue_adapter_beanstalk_beanstalkconnection_ce, SL("host"), "127.0.0.1", ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_queue_adapter_beanstalk_beanstalkconnection_ce, SL("persistent"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_queue_adapter_beanstalk_beanstalkconnection_ce, SL("port"), 11300, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool persistent;
	zend_long port;
	zval host_zv, *port_param = NULL, *persistent_param = NULL, __$true, __$false, _0;
	zend_string *host = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&host_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(host)
		Z_PARAM_LONG(port)
		Z_PARAM_BOOL(persistent)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		port_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		persistent_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!host) {
		host = zend_string_init(ZEND_STRL("127.0.0.1"), 0);
		zephir_memory_observe(&host_zv);
		ZVAL_STR(&host_zv, host);
	} else {
		zephir_memory_observe(&host_zv);
	ZVAL_STR_COPY(&host_zv, host);
	}
	if (!port_param) {
		port = 11300;
	} else {
		}
	if (!persistent_param) {
		persistent = 0;
	} else {
		}
	zephir_update_property_zval(this_ptr, ZEND_STRL("host"), &host_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, port);
	zephir_update_property_zval(this_ptr, ZEND_STRL("port"), &_0);
	if (persistent) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("persistent"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("persistent"), &__$false);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Puts a reserved job into the "buried" state.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, buryJob)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval id_zv, *priority_param = NULL, _0, _2, _3;
	zend_string *id = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(id)
		Z_PARAM_LONG(priority)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	priority_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&id_zv);
	ZVAL_STR_COPY(&id_zv, id);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, priority);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVSV(&_1, "bury ", &id_zv, " ", &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "readstatus", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_3, &_2, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 59);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_3, "BURIED"));
}

/**
 * Opens the socket connection to the Beanstalkd server.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, connect)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, connection, _0, _9, _1$$4, _2$$4, _3$$4, _4$$4, _5$$5, _6$$5, _7$$5, _8$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&connection, &_0);
	if (Z_TYPE_P(&connection) == IS_RESOURCE) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "disconnect", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("persistent"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("host"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
		ZVAL_NULL(&_3$$4);
		ZVAL_NULL(&_4$$4);
		ZEPHIR_MAKE_REF(&_3$$4);
		ZEPHIR_MAKE_REF(&_4$$4);
		ZEPHIR_CALL_FUNCTION(&connection, "pfsockopen", NULL, 0, &_1$$4, &_2$$4, &_3$$4, &_4$$4);
		ZEPHIR_UNREF(&_3$$4);
		ZEPHIR_UNREF(&_4$$4);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("host"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_6$$5, this_ptr, ZEND_STRL("port"), PH_NOISY_CC | PH_READONLY);
		ZVAL_NULL(&_7$$5);
		ZVAL_NULL(&_8$$5);
		ZEPHIR_MAKE_REF(&_7$$5);
		ZEPHIR_MAKE_REF(&_8$$5);
		ZEPHIR_CALL_FUNCTION(&connection, "fsockopen", NULL, 0, &_5$$5, &_6$$5, &_7$$5, &_8$$5);
		ZEPHIR_UNREF(&_7$$5);
		ZEPHIR_UNREF(&_8$$5);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&connection) != IS_RESOURCE) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_exception_ce, "Can't connect to the Beanstalk server", "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 82);
		return;
	}
	ZVAL_LONG(&_9, -1);
	ZEPHIR_CALL_FUNCTION(NULL, "stream_set_timeout", NULL, 0, &connection, &_9, &__$null);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("connection"), &connection);
	RETURN_CCTOR(&connection);
}

/**
 * Removes a job from the server entirely.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, deleteJob)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval id_zv, _1, _2;
	zend_string *id = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&id_zv);
	ZVAL_STR_COPY(&id_zv, id);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "delete ", &id_zv);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "readstatus", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &_1, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 99);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_2, "DELETED"));
}

/**
 * Closes the connection to the server.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, disconnect)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, connection, _0;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&connection, &_0);
	if (Z_TYPE_P(&connection) != IS_RESOURCE) {
		RETURN_MM_BOOL(0);
	}
	zephir_fclose(&connection);
	zephir_update_property_zval(this_ptr, ZEND_STRL("connection"), &__$null);
	RETURN_MM_BOOL(1);
}

/**
 * Removes the named tube from the watch list for the connection.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, ignoreTube)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tube_zv, _1, _2;
	zend_string *tube = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tube_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(tube)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tube_zv);
	ZVAL_STR_COPY(&tube_zv, tube);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "ignore ", &tube_zv);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "readstatus", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &_1, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 129);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_2, "WATCHING"));
}

/**
 * Puts a job on the queue using the currently used tube. Returns the new
 * job id, or false when the server did not accept it.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, put)
{
	zend_bool _5;
	zval _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, delay, ttr, ZEPHIR_LAST_CALL_STATUS, length = 0;
	zval data_zv, *priority_param = NULL, *delay_param = NULL, *ttr_param = NULL, response, status, _0, _1, _2, _3, _6;
	zend_string *data = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(data)
		Z_PARAM_LONG(priority)
		Z_PARAM_LONG(delay)
		Z_PARAM_LONG(ttr)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	priority_param = ZEND_CALL_ARG(execute_data, 2);
	delay_param = ZEND_CALL_ARG(execute_data, 3);
	ttr_param = ZEND_CALL_ARG(execute_data, 4);
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	length = zephir_fast_strlen_ev(&data_zv);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, priority);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, delay);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_LONG(&_2, ttr);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_LONG(&_3, length);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVSVSVSVSV(&_4, "put ", &_0, " ", &_1, " ", &_2, " ", &_3, "\r\n", &data_zv);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_array_isset_value_long(&response, 0))) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&status, &response, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 151);
	_5 = !ZEPHIR_IS_STRING(&status, "INSERTED");
	if (_5) {
		_5 = !ZEPHIR_IS_STRING(&status, "BURIED");
	}
	if (_5) {
		RETURN_MM_BOOL(0);
	}
	zephir_memory_observe(&_6);
	zephir_array_fetch_long(&_6, &response, 1, PH_NOISY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 157);
	RETURN_MM_LONG(zephir_get_intval(&_6));
}

/**
 * Reads a packet from the socket. Verifies the connection is available
 * first.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, read)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *length_param = NULL, connection, data, meta, _0, _1$$4, _2$$4, _3$$4, _4$$4, _5$$7, _6$$7;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&meta);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &length_param);
	if (!length_param) {
		length = 0;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&connection, &_0);
	if (Z_TYPE_P(&connection) != IS_RESOURCE) {
		ZEPHIR_CALL_METHOD(&connection, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
	}
	if (length) {
		if (zephir_feof(&connection)) {
			RETURN_MM_BOOL(0);
		}
		ZVAL_LONG(&_1$$4, (length + 2));
		ZEPHIR_CALL_FUNCTION(&_2$$4, "stream_get_line", NULL, 0, &connection, &_1$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "\r\n");
		ZEPHIR_INIT_VAR(&data);
		zephir_fast_trim(&data, &_2$$4, &_3$$4, ZEPHIR_TRIM_RIGHT);
		ZEPHIR_CALL_FUNCTION(&meta, "stream_get_meta_data", NULL, 0, &connection);
		zephir_check_call_status();
		zephir_array_fetch_string(&_4$$4, &meta, SL("timed_out"), PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 182);
		if (zephir_is_true(&_4$$4)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_exception_ce, "Connection timed out", "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 183);
			return;
		}
	} else {
		ZVAL_LONG(&_5$$7, 16384);
		ZEPHIR_INIT_VAR(&_6$$7);
		ZVAL_STRING(&_6$$7, "\r\n");
		ZEPHIR_CALL_FUNCTION(&data, "stream_get_line", NULL, 0, &connection, &_5$$7, &_6$$7);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&data, "UNKNOWN_COMMAND")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_exception_ce, "UNKNOWN_COMMAND", "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 190);
		return;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&data, "JOB_TOO_BIG")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_exception_ce, "JOB_TOO_BIG", "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 194);
		return;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&data, "BAD_FORMAT")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_exception_ce, "BAD_FORMAT", "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 198);
		return;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&data, "OUT_OF_MEMORY")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_exception_ce, "OUT_OF_MEMORY", "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 202);
		return;
	}
	RETURN_CCTOR(&data);
}

/**
 * Reads the latest status line and splits it into tokens.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, readStatus)
{
	zval status;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&status);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&status, this_ptr, "read", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_fast_explode_str(return_value, SL(" "), &status, LONG_MAX);
	RETURN_MM();
}

/**
 * Puts a reserved job back into the ready queue.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, releaseJob)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long priority, delay, ZEPHIR_LAST_CALL_STATUS;
	zval id_zv, *priority_param = NULL, *delay_param = NULL, _0, _1, _3, _4;
	zend_string *id = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(id)
		Z_PARAM_LONG(priority)
		Z_PARAM_LONG(delay)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	priority_param = ZEND_CALL_ARG(execute_data, 2);
	delay_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&id_zv);
	ZVAL_STR_COPY(&id_zv, id);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, priority);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, delay);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVSVSV(&_2, "release ", &id_zv, " ", &_0, " ", &_1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "readstatus", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &_3, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 231);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_4, "RELEASED"));
}

/**
 * Reserves a ready job from a watched tube. A null timeout blocks until a
 * job is available; otherwise it blocks up to timeout seconds. Returns
 * [id, body] or null when none is reserved.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, reserve)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *timeout = NULL, timeout_sub, __$null, command, response, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&timeout_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&command);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(timeout)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &timeout);
	if (!timeout) {
		timeout = &timeout_sub;
		timeout = &__$null;
	}
	ZEPHIR_INIT_VAR(&command);
	if (Z_TYPE_P(timeout) != IS_NULL) {
		ZEPHIR_CONCAT_SV(&command, "reserve-with-timeout ", timeout);
	} else {
		ZVAL_STRING(&command, "reserve");
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &command);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 0);
	zephir_check_call_status();
	_0 = !(zephir_array_isset_value_long(&response, 0));
	if (!(_0)) {
		zephir_array_fetch_long(&_1, &response, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 253);
		_0 = !ZEPHIR_IS_STRING(&_1, "RESERVED");
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	zephir_create_array(return_value, 2, 0);
	zephir_memory_observe(&_2);
	zephir_array_fetch_long(&_2, &response, 1, PH_NOISY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 257);
	zephir_array_fast_append(return_value, &_2);
	ZEPHIR_OBS_NVAR(&_2);
	zephir_array_fetch_long(&_2, &response, 2, PH_NOISY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 257);
	ZVAL_LONG(&_4, zephir_get_intval(&_2));
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "read", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, &_3);
	RETURN_MM();
}

/**
 * Extends the time-to-run of a reserved job.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, touchJob)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval id_zv, _1, _2;
	zend_string *id = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&id_zv);
	ZVAL_STR_COPY(&id_zv, id);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "touch ", &id_zv);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "readstatus", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &_1, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 267);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_2, "TOUCHED"));
}

/**
 * Changes the tube new jobs are put on. By default this is "default".
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, useTube)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tube_zv, _1, _2;
	zend_string *tube = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tube_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(tube)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tube_zv);
	ZVAL_STR_COPY(&tube_zv, tube);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "use ", &tube_zv);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "readstatus", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &_1, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 277);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_2, "USING"));
}

/**
 * Adds the named tube to the watch list for the connection.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, watchTube)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tube_zv, _1, _2;
	zend_string *tube = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tube_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(tube)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tube_zv);
	ZVAL_STR_COPY(&tube_zv, tube);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "watch ", &tube_zv);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "readstatus", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &_1, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 287);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_2, "WATCHING"));
}

/**
 * Writes data to the socket, connecting first when needed.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, write)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data_zv, connection, packet, _0;
	zend_string *data = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&packet);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&connection, &_0);
	if (Z_TYPE_P(&connection) != IS_RESOURCE) {
		ZEPHIR_CALL_METHOD(&connection, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VS(&_1, &data_zv, "\r\n");
	ZEPHIR_CPY_WRT(&packet, &_1);
	ZVAL_LONG(&_0, zephir_fast_strlen_ev(&packet));
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 0, &connection, &packet, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

