
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
 * @property callable $master
 * @property array    $read
 * @property array    $write
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_ConnectionLocator) {

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

	phalcon_datamapper_pdo_connectionlocator_ce->create_object = zephir_init_properties_Phalcon_DataMapper_Pdo_ConnectionLocator;

	zend_class_implements(phalcon_datamapper_pdo_connectionlocator_ce, 1, phalcon_datamapper_pdo_connectionlocatorinterface_ce);
	return SUCCESS;

}

/**
 * Constructor.
 *
 * @param ConnectionInterface $master
 * @param array               $read
 * @param array               $write
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, __construct) {

	zend_string *_3, *_8;
	zend_ulong _2, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval read, write;
	zval *master, master_sub, *read_param = NULL, *write_param = NULL, name, callableObject, *_0, _1, *_5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&master_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&callableObject);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&read);
	ZVAL_UNDEF(&write);

	ZEPHIR_MM_GROW();
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
	zephir_is_iterable(&read, 0, "phalcon/DataMapper/Pdo/ConnectionLocator.zep", 78);
	if (Z_TYPE_P(&read) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&read), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&callableObject);
			ZVAL_COPY(&callableObject, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setread", &_4, 0, &name, &callableObject);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &read, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &read, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &read, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&callableObject, &read, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setread", &_4, 0, &name, &callableObject);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &read, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&callableObject);
	ZEPHIR_INIT_NVAR(&name);
	zephir_is_iterable(&write, 0, "phalcon/DataMapper/Pdo/ConnectionLocator.zep", 81);
	if (Z_TYPE_P(&write) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&write), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&name, _8);
			} else {
				ZVAL_LONG(&name, _7);
			}
			ZEPHIR_INIT_NVAR(&callableObject);
			ZVAL_COPY(&callableObject, _5);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setwrite", &_9, 0, &name, &callableObject);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &write, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &write, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &write, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&callableObject, &write, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setwrite", &_9, 0, &name, &callableObject);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &write, "next", NULL, 0);
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
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, getMaster) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "master");

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
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, getRead) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "read");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getconnection", NULL, 0, &_0, &name);
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
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, getWrite) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "write");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getconnection", NULL, 0, &_0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the default connection factory.
 *
 * @param ConnectionInterface $callable
 *
 * @return ConnectionLocatorInterface
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, setMaster) {

	zval *callableObject, callableObject_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callableObject_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &callableObject);



	zephir_update_property_zval(this_ptr, ZEND_STRL("master"), callableObject);
	RETURN_THISW();

}

/**
 * Sets a read connection factory by name.
 *
 * @param string   $name
 * @param callable $callable
 *
 * @return ConnectionLocatorInterface
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, setRead) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *callableObject, callableObject_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&callableObject_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &callableObject);

	zephir_get_strval(&name, name_param);


	zephir_update_property_array(this_ptr, SL("read"), &name, callableObject);
	RETURN_THIS();

}

/**
 * Sets a write connection factory by name.
 *
 * @param string   $name
 * @param callable $callable
 *
 * @return ConnectionLocatorInterface
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, setWrite) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *callableObject, callableObject_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&callableObject_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &callableObject);

	zephir_get_strval(&name, name_param);


	zephir_update_property_array(this_ptr, SL("write"), &name, callableObject);
	RETURN_THIS();

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
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, getConnection) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *type_param = NULL, *name_param = NULL, collection, instanceName, instances, requested, _0, _1, _6, _2$$5, _3$$5, _4$$6, _5$$6;
	zval type, name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&name);
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &type_param, &name_param);

	zephir_get_strval(&type, type_param);
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_OBS_VAR(&collection);
	zephir_read_property_zval(&collection, this_ptr, &type, PH_NOISY_CC);
	ZEPHIR_CPY_WRT(&requested, &name);
	zephir_read_property(&_0, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&instances, &_0);
	if (ZEPHIR_IS_EMPTY(&collection)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getmaster", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	if (ZEPHIR_IS_IDENTICAL(&_1, &requested)) {
		ZEPHIR_CALL_FUNCTION(&requested, "array_rand", NULL, 200, &collection);
		zephir_check_call_status();
	}
	if (!(zephir_array_isset(&collection, &requested))) {
		ZEPHIR_INIT_VAR(&_2$$5);
		object_init_ex(&_2$$5, phalcon_datamapper_pdo_exception_connectionnotfound_ce);
		ZEPHIR_INIT_VAR(&_3$$5);
		ZEPHIR_CONCAT_SVSV(&_3$$5, "Connection not found: ", &type, ":", &requested);
		ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 8, &_3$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "phalcon/DataMapper/Pdo/ConnectionLocator.zep", 210);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&instanceName);
	ZEPHIR_CONCAT_VSV(&instanceName, &type, "-", &requested);
	if (!(zephir_array_isset(&instances, &instanceName))) {
		ZEPHIR_INIT_VAR(&_4$$6);
		zephir_array_fetch(&_5$$6, &collection, &requested, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Pdo/ConnectionLocator.zep", 221);
		ZEPHIR_CALL_USER_FUNC(&_4$$6, &_5$$6);
		zephir_check_call_status();
		zephir_array_update_zval(&instances, &instanceName, &_4$$6, PH_COPY | PH_SEPARATE);
		zephir_update_property_zval(this_ptr, ZEND_STRL("instances"), &instances);
	}
	zephir_array_fetch(&_6, &instances, &instanceName, PH_NOISY | PH_READONLY, "phalcon/DataMapper/Pdo/ConnectionLocator.zep", 225);
	RETURN_CTOR(&_6);

}

zend_object *zephir_init_properties_Phalcon_DataMapper_Pdo_ConnectionLocator(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zend_update_property(Z_OBJCE_P(this_ptr), this_ptr, ZEND_STRL("instances"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("write"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zend_update_property(Z_OBJCE_P(this_ptr), this_ptr, ZEND_STRL("write"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("read"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zend_update_property(Z_OBJCE_P(this_ptr), this_ptr, ZEND_STRL("read"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

