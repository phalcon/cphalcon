
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Pdo
 * @license https://github.com/atlasphp/Atlas.Pdo/blob/1.x/LICENSE.md
 */
/**
 * Manages Connection instances for default, read, and write connections.
 *
 * The locator gives its events manager to each connection that it returns,
 * so connections that are built on demand also fire the DataMapper events.
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_ConnectionLocator)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\DataMapper\\Pdo, ConnectionLocator, phalcon, datamapper_pdo_connectionlocator, phalcon_datamapper_pdo_connectionlocator_method_entry, 0);

	/**
	 * A default Connection connection factory/instance.
	 *
	 * @var ConnectionInterface
	 */
	zend_declare_property_null(phalcon_datamapper_pdo_connectionlocator_ce, SL("master"), ZEND_ACC_PROTECTED);
	/**
	 * A registry of Connection "read" factories/instances.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_datamapper_pdo_connectionlocator_ce, SL("read"), ZEND_ACC_PROTECTED);
	/**
	 * A registry of Connection "write" factories/instances.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_datamapper_pdo_connectionlocator_ce, SL("write"), ZEND_ACC_PROTECTED);
	/**
	 * A collection of resolved instances
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_datamapper_pdo_connectionlocator_ce, SL("instances"), ZEND_ACC_PRIVATE);
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_datamapper_pdo_connectionlocator_ce, SL("eventsManager"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_NULL, SL("Phalcon\\Events\\ManagerInterface"));
	}

	phalcon_datamapper_pdo_connectionlocator_ce->create_object = zephir_init_properties_Phalcon_DataMapper_Pdo_ConnectionLocator;

	zend_class_implements(phalcon_datamapper_pdo_connectionlocator_ce, 1, phalcon_datamapper_pdo_connectionlocatorinterface_ce);
	zend_class_implements(phalcon_datamapper_pdo_connectionlocator_ce, 1, phalcon_contracts_events_eventsaware_ce);
	return SUCCESS;
}

/**
 * Constructor.
 *
 * @param ConnectionInterface $master
 * @param array               $read
 * @param array               $write
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, __construct)
{
	zend_bool _5, _11;
	zend_string *_2, *_8;
	zend_ulong _1, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval read, write;
	zval *master, master_sub, *read_param = NULL, *write_param = NULL, name, callableObject, *_0, _4, *_6, _10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&master_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&callableObject);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&read);
	ZVAL_UNDEF(&write);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_OBJECT_OF_CLASS(master, phalcon_datamapper_pdo_connection_connectioninterface_ce)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(read, read_param)
		ZEPHIR_Z_PARAM_ARRAY(write, write_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &master, &read_param, &write_param);
	if (!read_param) {
		ZEPHIR_INIT_VAR(&read);
		array_init(&read);
	} else {
		zephir_get_arrval(&read, read_param);
	}
	if (!write_param) {
		ZEPHIR_INIT_VAR(&write);
		array_init(&write);
	} else {
		zephir_get_arrval(&write, write_param);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmaster", NULL, 0, master);
	zephir_check_call_status();
	zephir_is_iterable(&read, 0, "phalcon/DataMapper/Pdo/ConnectionLocator.zep", 82);
	if (Z_TYPE_P(&read) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&read), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&name, _2);
			} else {
				ZVAL_LONG(&name, _1);
			}
			ZEPHIR_INIT_NVAR(&callableObject);
			ZVAL_COPY(&callableObject, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setread", &_3, 0, &name, &callableObject);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &read, "rewind", NULL, 0);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &read, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_4, &read, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &read, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&callableObject, &read, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setread", &_3, 0, &name, &callableObject);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&callableObject);
	ZEPHIR_INIT_NVAR(&name);
	zephir_is_iterable(&write, 0, "phalcon/DataMapper/Pdo/ConnectionLocator.zep", 85);
	if (Z_TYPE_P(&write) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&write), _7, _8, _6)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&name, _8);
			} else {
				ZVAL_LONG(&name, _7);
			}
			ZEPHIR_INIT_NVAR(&callableObject);
			ZVAL_COPY(&callableObject, _6);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setwrite", &_9, 0, &name, &callableObject);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &write, "rewind", NULL, 0);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &write, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_10, &write, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &write, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&callableObject, &write, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setwrite", &_9, 0, &name, &callableObject);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&callableObject);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the default connection object.
 *
 * @return ConnectionInterface
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, getMaster)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("master", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 566, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "applyeventsmanager", NULL, 509, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a read connection by name; if no name is given, picks a
 * random connection; if no read connections are present, returns the
 * default connection.
 *
 * @param string $name
 *
 * @return ConnectionInterface
 * @throws ConnectionNotFound
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, getRead)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!name) {
		name = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&name_zv);
		ZVAL_STR(&name_zv, name);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "read");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getconnection", NULL, 0, &_0, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a write connection by name; if no name is given, picks a
 * random connection; if no write connections are present, returns the
 * default connection.
 *
 * @param string $name
 *
 * @return ConnectionInterface
 * @throws ConnectionNotFound
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, getWrite)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!name) {
		name = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&name_zv);
		ZVAL_STR(&name_zv, name);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "write");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getconnection", NULL, 0, &_0, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets the default connection factory.
 *
 * @param ConnectionInterface $callable
 *
 * @return static
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, setMaster)
{
	zval *callableObject, callableObject_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callableObject_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("master", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(callableObject, phalcon_datamapper_pdo_connection_connectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &callableObject);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 566, callableObject);
	RETURN_THISW();
}

/**
 * Sets a read connection factory by name.
 *
 * @param string   $name
 * @param callable $callable
 *
 * @return static
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, setRead)
{
	zval name_zv, *callableObject, callableObject_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&callableObject_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(callableObject)
	ZEND_PARSE_PARAMETERS_END();
	callableObject = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("read"), &name_zv, callableObject);
	RETURN_THISW();
}

/**
 * Sets a write connection factory by name.
 *
 * @param string   $name
 * @param callable $callable
 *
 * @return static
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, setWrite)
{
	zval name_zv, *callableObject, callableObject_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&callableObject_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(callableObject)
	ZEND_PARSE_PARAMETERS_END();
	callableObject = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("write"), &name_zv, callableObject);
	RETURN_THISW();
}

/**
 * Returns a connection by name.
 *
 * @param string $type
 * @param string $name
 *
 * @return ConnectionInterface
 * @throws ConnectionNotFound
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, getConnection)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, name_zv, collection, instanceName, instances, requested, _0, _1, _6, _2$$5, _3$$5, _4$$6, _5$$6;
	zend_string *type = NULL, *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&instanceName);
	ZVAL_UNDEF(&instances);
	ZVAL_UNDEF(&requested);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("instances", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(type)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	if (!name) {
		name = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&name_zv);
		ZVAL_STR(&name_zv, name);
	} else {
		zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	}
	zephir_memory_observe(&collection);
	zephir_read_property_zval(&collection, this_ptr, &type_zv, PH_NOISY_CC);
	ZEPHIR_CPY_WRT(&requested, &name_zv);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 567, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&instances, &_0);
	if (ZEPHIR_IS_EMPTY(&collection)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getmaster", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	if (ZEPHIR_IS_IDENTICAL(&_1, &requested)) {
		ZEPHIR_CALL_FUNCTION(&requested, "array_rand", NULL, 510, &collection);
		zephir_check_call_status();
	}
	if (!(zephir_array_isset_value(&collection, &requested))) {
		ZEPHIR_INIT_VAR(&_2$$5);
		object_init_ex(&_2$$5, phalcon_datamapper_pdo_exception_connectionnotfound_ce);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZEPHIR_CONCAT_SVSV(&_3$$5, "Connection not found: ", &type_zv, ":", &requested);
		ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 9, &_3$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "phalcon/DataMapper/Pdo/ConnectionLocator.zep", 214);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&instanceName);
	ZEPHIR_CONCAT_VSV(&instanceName, &type_zv, "-", &requested);
	if (!(zephir_array_isset_value(&instances, &instanceName))) {
		ZEPHIR_INIT_VAR(&_4$$6);
		zephir_array_fetch(&_5$$6, &collection, &requested, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Pdo/ConnectionLocator.zep", 225);
		ZEPHIR_CALL_USER_FUNC(&_4$$6, &_5$$6);
		zephir_check_call_status();
		zephir_array_update_zval(&instances, &instanceName, &_4$$6, PH_COPY | PH_SEPARATE);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 567, &instances);
	}
	zephir_array_fetch(&_6, &instances, &instanceName, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Pdo/ConnectionLocator.zep", 229);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "applyeventsmanager", NULL, 509, &_6);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Gives the locator's events manager to a connection. Does nothing when
 * the locator has no manager, or when the connection does not accept
 * one. It is safe to call this more than once on the same connection.
 *
 * @param ConnectionInterface $connection
 *
 * @return ConnectionInterface
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, applyEventsManager)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, _0, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(connection, phalcon_datamapper_pdo_connection_connectioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &connection);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 568, PH_NOISY_CC | PH_READONLY);
	_1 = Z_TYPE_P(&_0) != IS_NULL;
	if (_1) {
		_1 = zephir_instance_of_ev(connection, phalcon_contracts_events_eventsaware_ce);
	}
	if (_1) {
		zephir_read_property_cached(&_2$$3, this_ptr, _zephir_prop_0, 568, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, connection, "seteventsmanager", NULL, 0, &_2$$3);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(connection, 1, 0);
	RETURN_MM();
}

/**
 * Returns the internal event manager
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, getEventsManager)
{

	RETURN_MEMBER(getThis(), "eventsManager");
}

/**
 * Sets the events manager
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, setEventsManager)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventsManager, eventsManager_sub, _0, _1, _3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventsManager_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("eventsManager", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(eventsManager, phalcon_events_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &eventsManager);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "container");
	ZEPHIR_CALL_FUNCTION(&_1, "property_exists", NULL, 10, this_ptr, &_0);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_1);
	if (_2) {
		zephir_memory_observe(&_3);
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 569, PH_NOISY_CC);
		_2 = Z_TYPE_P(&_3) != IS_NULL;
	}
	if (_2) {
		zephir_memory_observe(&_4$$3);
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 569, PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "eventsManager");
		ZVAL_BOOL(&_6$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "set", NULL, 0, &_5$$3, eventsManager, &_6$$3);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 568, eventsManager);
	ZEPHIR_MM_RESTORE();
}

/**
 * Helper method to fire an event
 * 
 * @throws EventsException
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, fireManagerEvent)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool cancellable;
	zval eventName_zv, *data = NULL, data_sub, *cancellable_param = NULL, __$null, _0, _1$$3, _2$$3;
	zend_string *eventName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eventName_zv);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("eventsManager", 13, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(eventName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(data)
		Z_PARAM_BOOL(cancellable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		data = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		cancellable_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&eventName_zv);
	ZVAL_STR_COPY(&eventName_zv, eventName);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!cancellable_param) {
		cancellable = 1;
	} else {
		}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 568, PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 568, PH_NOISY_CC | PH_READONLY);
		if (cancellable) {
			ZVAL_BOOL(&_2$$3, 1);
		} else {
			ZVAL_BOOL(&_2$$3, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD(&_1$$3, "fire", NULL, 0, &eventName_zv, this_ptr, data, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);
}

zend_object *zephir_init_properties_Phalcon_DataMapper_Pdo_ConnectionLocator(zend_class_entry *class_type)
{
		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("instances"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("instances"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("write"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("write"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("read"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("read"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

