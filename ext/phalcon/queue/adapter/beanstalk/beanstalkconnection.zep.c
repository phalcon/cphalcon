
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this component has been inspired by the queue-interop and
 * enqueue projects.
 *
 * @link    https://github.com/queue-interop/queue-interop
 * @license https://github.com/queue-interop/queue-interop/blob/master/LICENSE
 *
 * @link    https://github.com/php-enqueue/enqueue-dev
 * @license https://github.com/php-enqueue/enqueue-dev/blob/master/LICENSE
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
	 * @var resource|null
	 */
	zend_declare_property_null(phalcon_queue_adapter_beanstalk_beanstalkconnection_ce, SL("connection"), ZEND_ACC_PROTECTED);
	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "127.0.0.1", sizeof("127.0.0.1") - 1);
		zephir_declare_typed_property(phalcon_queue_adapter_beanstalk_beanstalkconnection_ce, SL("host"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_BOOL(&_zc0, 0);
		zephir_declare_typed_property(phalcon_queue_adapter_beanstalk_beanstalkconnection_ce, SL("persistent"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 11300);
		zephir_declare_typed_property(phalcon_queue_adapter_beanstalk_beanstalkconnection_ce, SL("port"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	/**
	 * Tube currently selected with `use`. A fresh connection uses "default".
	 */
	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "default", sizeof("default") - 1);
		zephir_declare_typed_property(phalcon_queue_adapter_beanstalk_beanstalkconnection_ce, SL("usedTube"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * Tubes currently on the watch list, keyed by tube name. A fresh
	 * connection watches "default".
	 *
	 * @var array<string, bool>
	 */
	zend_declare_property_null(phalcon_queue_adapter_beanstalk_beanstalkconnection_ce, SL("watchedTubes"), ZEND_ACC_PROTECTED);
	phalcon_queue_adapter_beanstalk_beanstalkconnection_ce->create_object = zephir_init_properties_Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection;

	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, __construct)
{
	zval _1;
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
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("host", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("port", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("persistent", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("watchedTubes", 12, 1);
	}

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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1243, &host_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, port);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1244, &_0);
	if (persistent) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1245, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1245, &__$false);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	zephir_array_update_string(&_1, SL("default"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1246, &_1);
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
	zephir_array_fetch_long(&_3, &_2, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 75);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_3, "BURIED"));
}

/**
 * Opens the socket connection to the Beanstalkd server.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, connect)
{
	zval connection, errorLevel, _0, _9, _10, _1$$4, _2$$4, _3$$4, _4$$4, _5$$5, _6$$5, _7$$5, _8$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&errorLevel);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("connection", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("persistent", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("host", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("port", 4, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1247, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&connection, &_0);
	if (Z_TYPE_P(&connection) == IS_RESOURCE) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "disconnect", NULL, 0);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_FUNCTION(&errorLevel, "error_reporting", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 1245, PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property_cached(&_1$$4, this_ptr, _zephir_prop_2, 1243, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_2$$4, this_ptr, _zephir_prop_3, 1244, PH_NOISY_CC | PH_READONLY);
		ZVAL_NULL(&_3$$4);
		ZVAL_NULL(&_4$$4);
		ZEPHIR_MAKE_REF(&_3$$4);
		ZEPHIR_MAKE_REF(&_4$$4);
		ZEPHIR_CALL_FUNCTION(&connection, "pfsockopen", NULL, 0, &_1$$4, &_2$$4, &_3$$4, &_4$$4);
		ZEPHIR_UNREF(&_3$$4);
		ZEPHIR_UNREF(&_4$$4);
		zephir_check_call_status();
	} else {
		zephir_read_property_cached(&_5$$5, this_ptr, _zephir_prop_2, 1243, PH_NOISY_CC | PH_READONLY);
		zephir_read_property_cached(&_6$$5, this_ptr, _zephir_prop_3, 1244, PH_NOISY_CC | PH_READONLY);
		ZVAL_NULL(&_7$$5);
		ZVAL_NULL(&_8$$5);
		ZEPHIR_MAKE_REF(&_7$$5);
		ZEPHIR_MAKE_REF(&_8$$5);
		ZEPHIR_CALL_FUNCTION(&connection, "fsockopen", NULL, 0, &_5$$5, &_6$$5, &_7$$5, &_8$$5);
		ZEPHIR_UNREF(&_7$$5);
		ZEPHIR_UNREF(&_8$$5);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "error_reporting", NULL, 0, &errorLevel);
	zephir_check_call_status();
	if (Z_TYPE_P(&connection) != IS_RESOURCE) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_exception_ce, "Can't connect to the Beanstalk server", "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 107);
		return;
	}
	ZVAL_LONG(&_9, -1);
	ZVAL_LONG(&_10, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "stream_set_timeout", NULL, 0, &connection, &_9, &_10);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1247, &connection);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "restoresession", NULL, 0);
	zephir_check_call_status();
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
	zephir_array_fetch_long(&_2, &_1, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 126);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_2, "DELETED"));
}

/**
 * Closes the connection to the server.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, disconnect)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$null, connection, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("connection", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1247, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&connection, &_0);
	if (Z_TYPE_P(&connection) != IS_RESOURCE) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "phpfclose", NULL, 0, &connection);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1247, &__$null);
	RETURN_MM_BOOL(1);
}

/**
 * Removes the named tube from the watch list for the connection.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, ignoreTube)
{
	zval _0;
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tube_zv, _1, _2, _3$$3;
	zend_string *tube = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tube_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("watchedTubes", 12, 1);
	}

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
	zephir_array_fetch_long(&_2, &_1, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 158);
	result = ZEPHIR_IS_STRING(&_2, "WATCHING");
	if (result) {
		zephir_unset_property_array(this_ptr, ZEND_STRL("watchedTubes"), &tube_zv);
		zephir_read_property_cached(&_3$$3, this_ptr, _zephir_prop_0, 1246, PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_3$$3, &tube_zv, PH_SEPARATE);
	}
	RETURN_MM_BOOL(result);
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
	zephir_array_fetch_long(&status, &response, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 186);
	_5 = !ZEPHIR_IS_STRING(&status, "INSERTED");
	if (_5) {
		_5 = !ZEPHIR_IS_STRING(&status, "BURIED");
	}
	if (_5) {
		RETURN_MM_BOOL(0);
	}
	zephir_memory_observe(&_6);
	zephir_array_fetch_long(&_6, &response, 1, PH_NOISY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 192);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("connection", 10, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1247, PH_NOISY_CC | PH_READONLY);
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
		zephir_array_fetch_string(&_4$$4, &meta, SL("timed_out"), PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 217);
		if (zephir_is_true(&_4$$4)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_exception_ce, "Connection timed out", "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 218);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_exception_ce, "UNKNOWN_COMMAND", "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 225);
		return;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&data, "JOB_TOO_BIG")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_exception_ce, "JOB_TOO_BIG", "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 229);
		return;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&data, "BAD_FORMAT")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_exception_ce, "BAD_FORMAT", "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 233);
		return;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&data, "OUT_OF_MEMORY")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_exceptions_exception_ce, "OUT_OF_MEMORY", "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 237);
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
	zephir_array_fetch_long(&_4, &_3, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 266);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_4, "RELEASED"));
}

/**
 * Reserves a ready job from a watched tube. A null timeout blocks until a
 * job is available; otherwise it blocks up to timeout seconds. Returns
 * [id, body] or null when none is reserved.
 *
 * @return array{0: string, 1: false|string}|null
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, reserve)
{
	zval _1$$3;
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *timeout = NULL, timeout_sub, __$null, command, response, _3, _4, _5, _6, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&timeout_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&command);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
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
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_LONG(&_0$$3, zephir_get_intval(timeout));
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SV(&_1$$3, "reserve-with-timeout ", &_0$$3);
		ZEPHIR_CPY_WRT(&command, &_1$$3);
	} else {
		ZVAL_STRING(&command, "reserve");
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &command);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 0);
	zephir_check_call_status();
	_2 = !(zephir_array_isset_value_long(&response, 0));
	if (!(_2)) {
		zephir_array_fetch_long(&_3, &response, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 290);
		_2 = !ZEPHIR_IS_STRING(&_3, "RESERVED");
	}
	if (_2) {
		RETURN_MM_NULL();
	}
	zephir_create_array(return_value, 2, 0);
	zephir_memory_observe(&_4);
	zephir_array_fetch_long(&_4, &response, 1, PH_NOISY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 294);
	zephir_array_fast_append(return_value, &_4);
	ZEPHIR_OBS_NVAR(&_4);
	zephir_array_fetch_long(&_4, &response, 2, PH_NOISY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 294);
	ZVAL_LONG(&_6, zephir_get_intval(&_4));
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "read", NULL, 0, &_6);
	zephir_check_call_status();
	zephir_array_fast_append(return_value, &_5);
	RETURN_MM();
}

/**
 * Returns the Beanstalkd statistics for a tube as an associative array, or
 * false when the tube does not exist.
 *
 * @return array<string, int|string>|false
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, statsTube)
{
	zend_bool _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tube_zv, response, body, _2, _3, _4;
	zend_string *tube = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tube_zv);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(tube)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tube_zv);
	ZVAL_STR_COPY(&tube_zv, tube);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "stats-tube ", &tube_zv);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 0);
	zephir_check_call_status();
	_1 = !(zephir_array_isset_value_long(&response, 0));
	if (!(_1)) {
		zephir_array_fetch_long(&_2, &response, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 311);
		_1 = !ZEPHIR_IS_STRING(&_2, "OK");
	}
	if (_1) {
		RETURN_MM_BOOL(0);
	}
	zephir_memory_observe(&_3);
	zephir_array_fetch_long(&_3, &response, 1, PH_NOISY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 315);
	ZVAL_LONG(&_4, zephir_get_intval(&_3));
	ZEPHIR_CALL_METHOD(&body, this_ptr, "read", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parsedictionary", NULL, 0, &body);
	zephir_check_call_status();
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
	zephir_array_fetch_long(&_2, &_1, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 327);
	RETURN_MM_BOOL(ZEPHIR_IS_STRING(&_2, "TOUCHED"));
}

/**
 * Changes the tube new jobs are put on. By default this is "default".
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, useTube)
{
	zval _0;
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tube_zv, _1, _2;
	zend_string *tube = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tube_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("usedTube", 8, 1);
	}

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
	zephir_array_fetch_long(&_2, &_1, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 339);
	result = ZEPHIR_IS_STRING(&_2, "USING");
	if (result) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1248, &tube_zv);
	}
	RETURN_MM_BOOL(result);
}

/**
 * Adds the named tube to the watch list for the connection.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, watchTube)
{
	zval _0;
	zend_bool result = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tube_zv, __$true, _1, _2;
	zend_string *tube = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tube_zv);
	ZVAL_BOOL(&__$true, 1);
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
	zephir_array_fetch_long(&_2, &_1, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 357);
	result = ZEPHIR_IS_STRING(&_2, "WATCHING");
	if (result) {
		zephir_update_property_array(this_ptr, SL("watchedTubes"), &tube_zv, &__$true);
	}
	RETURN_MM_BOOL(result);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("connection", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1247, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&connection, &_0);
	if (Z_TYPE_P(&connection) != IS_RESOURCE) {
		ZEPHIR_CALL_METHOD(&connection, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VS(&_1, &data_zv, "\r\n");
	ZEPHIR_CPY_WRT(&packet, &_1);
	ZVAL_LONG(&_0, zephir_fast_strlen_ev(&packet));
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "phpfwrite", NULL, 0, &connection, &packet, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Parses a Beanstalkd YAML dictionary payload (a flat "key: value" map)
 * into an associative array. Numeric values are cast to int, except the
 * `name` field, which is always kept as a string (a tube may be named
 * numerically). Avoids the yaml extension; the payload format is a fixed,
 * flat map.
 *
 * @return array<string, int|string>
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, parseDictionary)
{
	zend_bool _3$$3, _6$$3, _7$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval payload_zv, line, parts, key, value, result, _0, *_1, _2$$3, _4$$3, _5$$3, _8$$6;
	zend_string *payload = NULL;

	ZVAL_UNDEF(&payload_zv);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(payload)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&payload_zv);
	ZVAL_STR_COPY(&payload_zv, payload);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_explode_str(&_0, SL("\n"), &payload_zv, LONG_MAX);
	zephir_is_iterable(&_0, 0, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 422);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&line);
		ZVAL_COPY(&line, _1);
		ZEPHIR_INIT_NVAR(&_2$$3);
		zephir_fast_trim(&_2$$3, &line, NULL , ZEPHIR_TRIM_BOTH);
		ZEPHIR_CPY_WRT(&line, &_2$$3);
		_3$$3 = ZEPHIR_IS_STRING_IDENTICAL(&line, "");
		if (!(_3$$3)) {
			_3$$3 = ZEPHIR_IS_STRING_IDENTICAL(&line, "---");
		}
		if (_3$$3) {
			continue;
		}
		ZEPHIR_INIT_NVAR(&parts);
		zephir_fast_explode_str(&parts, SL(":"), &line, 2 );
		if (zephir_fast_count_int(&parts) != 2) {
			continue;
		}
		zephir_array_fetch_long(&_4$$3, &parts, 0, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 412);
		ZEPHIR_INIT_NVAR(&key);
		zephir_fast_trim(&key, &_4$$3, NULL , ZEPHIR_TRIM_BOTH);
		zephir_array_fetch_long(&_5$$3, &parts, 1, PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 413);
		ZEPHIR_INIT_NVAR(&value);
		zephir_fast_trim(&value, &_5$$3, NULL , ZEPHIR_TRIM_BOTH);
		_6$$3 = !ZEPHIR_IS_STRING_IDENTICAL(&key, "name");
		if (_6$$3) {
			_6$$3 = !ZEPHIR_IS_STRING_IDENTICAL(&value, "");
		}
		_7$$3 = _6$$3;
		if (_7$$3) {
			_7$$3 = zephir_is_numeric(&value);
		}
		if (_7$$3) {
			ZEPHIR_INIT_NVAR(&_8$$6);
			ZVAL_LONG(&_8$$6, zephir_get_intval(&value));
			zephir_array_update_zval(&result, &key, &_8$$6, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&line);
	RETURN_CCTOR(&result);
}

/**
 * Re-issues the use/watch/ignore commands after a reconnect so a new
 * socket resumes the tube selection the caller established. A fresh
 * connection only uses and watches "default".
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, restoreSession)
{
	zval tube, _0, _3, _4, *_5, _7, _1$$3, _2$$3, _6$$5, _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tube);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("usedTube", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("watchedTubes", 12, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1248, PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_STRING(&_0, "default")) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1248, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "use ", &_1$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "readstatus", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_1, 1246, PH_NOISY_CC | PH_READONLY);
	zephir_array_keys(&_3, &_4);
	zephir_is_iterable(&_3, 0, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnection.zep", 446);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _5)
	{
		ZEPHIR_INIT_NVAR(&tube);
		ZVAL_COPY(&tube, _5);
		if (!ZEPHIR_IS_STRING(&tube, "default")) {
			ZEPHIR_INIT_NVAR(&_6$$5);
			ZEPHIR_CONCAT_SV(&_6$$5, "watch ", &tube);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_6$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "readstatus", NULL, 0);
			zephir_check_call_status();
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&tube);
	zephir_read_property_cached(&_7, this_ptr, _zephir_prop_1, 1246, PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_value_string(&_7, SL("default")))) {
		ZEPHIR_INIT_VAR(&_8$$6);
		ZVAL_STRING(&_8$$6, "ignore default");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_8$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "readstatus", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Closes an open file pointer
 *
 * @link https://php.net/manual/en/function.fclose.php
 *
 * @param resource $handle
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, phpFclose)
{
	zval *handle, handle_sub;

	ZVAL_UNDEF(&handle_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle);
	RETURN_BOOL(zephir_fclose(handle));
}

/**
 * Gets line from file pointer and parse for CSV fields
 *
 * @param resource $stream
 * @param int      $length
 * @param string   $separator
 * @param string   $enclosure
 * @param string   $escape
 *
 * @return array<array-key, mixed>|false
 *
 * @link https://php.net/manual/en/function.fgetcsv.php
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, phpFgetCsv)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *separator = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *stream, stream_sub, *length_param = NULL, separator_zv, *enclosure = NULL, enclosure_sub, *escape = NULL, escape_sub, __$null, _0;

	ZVAL_UNDEF(&stream_sub);
	ZVAL_UNDEF(&separator_zv);
	ZVAL_UNDEF(&enclosure_sub);
	ZVAL_UNDEF(&escape_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_ZVAL(stream)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(length)
		Z_PARAM_STR(separator)
		Z_PARAM_ZVAL_OR_NULL(enclosure)
		Z_PARAM_ZVAL_OR_NULL(escape)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	stream = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 1) {
		length_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 3) {
		enclosure = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		escape = ZEND_CALL_ARG(execute_data, 5);
	}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (!separator) {
		separator = zend_string_init(ZEND_STRL(","), 0);
		zephir_memory_observe(&separator_zv);
		ZVAL_STR(&separator_zv, separator);
	} else {
		zephir_memory_observe(&separator_zv);
	ZVAL_STR_COPY(&separator_zv, separator);
	}
	if (!enclosure) {
		enclosure = &enclosure_sub;
		ZEPHIR_CPY_WRT(enclosure, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(enclosure);
	}
	if (!escape) {
		escape = &escape_sub;
		ZEPHIR_CPY_WRT(escape, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(escape);
	}
	if (Z_TYPE_P(enclosure) == IS_NULL) {
		ZEPHIR_INIT_NVAR(enclosure);
		ZVAL_STRING(enclosure, "\"");
	}
	if (Z_TYPE_P(escape) == IS_NULL) {
		ZEPHIR_INIT_NVAR(escape);
		ZVAL_STRING(escape, "\\");
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fgetcsv", NULL, 159, stream, &_0, &separator_zv, enclosure, escape);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.file-exists.php
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, phpFileExists)
{
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&filename_zv, filename);
	RETURN_BOOL((zephir_file_exists(&filename_zv) == SUCCESS));
}

/**
 * @param string        $filename
 * @param bool          $useIncludePath
 * @param resource|null $context
 * @param int           $offset
 * @param int|null      $length
 *
 * @return false|string
 *
 * @link https://php.net/manual/en/function.file-get-contents.php
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, phpFileGetContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long offset, length, ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, *offset_param = NULL, *length_param = NULL, __$null, _0$$3, _1$$3, _2, _3, _4;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 5)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		context = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		offset_param = ZEND_CALL_ARG(execute_data, 4);
	}
	if (ZEND_NUM_ARGS() > 4) {
		length_param = ZEND_CALL_ARG(execute_data, 5);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	if (!offset_param) {
		offset = 0;
	} else {
		}
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		ZVAL_BOOL(&_0$$3, (useIncludePath ? 1 : 0));
		ZVAL_LONG(&_1$$3, offset);
		ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 160, &filename_zv, &_0$$3, context, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_BOOL(&_2, (useIncludePath ? 1 : 0));
	ZVAL_LONG(&_3, offset);
	ZVAL_LONG(&_4, length);
	ZEPHIR_RETURN_CALL_FUNCTION("file_get_contents", NULL, 160, &filename_zv, &_2, context, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string   $filename
 * @param mixed    $data
 * @param int      $flags
 * @param resource $context
 *
 * @return false|int
 *
 * @link https://php.net/manual/en/function.file-put-contents.php
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, phpFilePutContents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *data, data_sub, *flags_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_ZVAL(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(flags)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	data = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		flags_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!flags_param) {
		flags = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_FUNCTION("file_put_contents", NULL, 161, &filename_zv, data, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param string        $mode
 * @param bool          $useIncludePath
 * @param resource|null $context
 *
 * @return resource|false
 *
 * @link https://php.net/manual/en/function.fopen.php
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, phpFopen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool useIncludePath;
	zval filename_zv, mode_zv, *useIncludePath_param = NULL, *context = NULL, context_sub, __$null, _0;
	zend_string *filename = NULL, *mode = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&mode_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(filename)
		Z_PARAM_STR(mode)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(useIncludePath)
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		useIncludePath_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		context = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	zephir_memory_observe(&mode_zv);
	ZVAL_STR_COPY(&mode_zv, mode);
	if (!useIncludePath_param) {
		useIncludePath = 0;
	} else {
		}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZVAL_BOOL(&_0, (useIncludePath ? 1 : 0));
	ZEPHIR_RETURN_CALL_FUNCTION("fopen", NULL, 162, &filename_zv, &mode_zv, &_0, context);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Binary-safe file write
 *
 * @link https://php.net/manual/en/function.fwrite.php
 *
 * @param resource $handle
 * @param string   $data
 * @param int|null $length
 *
 * @return false|int
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, phpFwrite)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zend_string *data = NULL;
	zval *handle, handle_sub, data_zv, *length_param = NULL, _0;

	ZVAL_UNDEF(&handle_sub);
	ZVAL_UNDEF(&data_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(handle)
		Z_PARAM_STR(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(length, is_null_true)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	handle = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		length_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&data_zv);
	ZVAL_STR_COPY(&data_zv, data);
	if (!length_param) {
		length = 0;
	} else {
		}
	if (0 == length) {
		zephir_fwrite(return_value, handle, &data_zv);
		RETURN_MM();
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 163, handle, &data_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Tells whether the filename is writable
 *
 * @param string $filename
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.is-writable.php
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, phpIsWritable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	ZEPHIR_RETURN_CALL_FUNCTION("is_writable", NULL, 164, &filename_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string        $filename
 * @param resource|null $context
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.unlink.php
 */
PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection, phpUnlink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filename_zv, *context = NULL, context_sub, __$null;
	zend_string *filename = NULL;

	ZVAL_UNDEF(&filename_zv);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(filename)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(context)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&filename_zv);
	ZVAL_STR_COPY(&filename_zv, filename);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 165, &filename_zv, context);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnection(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("watchedTubes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("watchedTubes"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

