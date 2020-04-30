
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Factory_AbstractFactory) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Factory, AbstractFactory, phalcon, factory_abstractfactory, phalcon_factory_abstractfactory_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_factory_abstractfactory_ce, SL("mapper"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_factory_abstractfactory_ce, SL("services"), ZEND_ACC_PROTECTED);

	phalcon_factory_abstractfactory_ce->create_object = zephir_init_properties_Phalcon_Factory_AbstractFactory;
	return SUCCESS;

}

/**
 * Checks if a service exists and throws an exception
 */
PHP_METHOD(Phalcon_Factory_AbstractFactory, checkService) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1$$3;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset(&_0, &name)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_factory_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Service ", &name, " is not registered");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Factory/AbstractFactory.zep", 33);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks the config if it is a valid object
 */
PHP_METHOD(Phalcon_Factory_AbstractFactory, checkConfig) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);

	ZEPHIR_SEPARATE_PARAM(config);


	_0 = Z_TYPE_P(config) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(config, phalcon_config_ce);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1$$3, config, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(config, &_1$$3);
	}
	if (UNEXPECTED(Z_TYPE_P(config) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "Config must be array or Phalcon\\Config object", "phalcon/Factory/AbstractFactory.zep", 49);
		return;
	}
	if (UNEXPECTED(!(zephir_array_isset_string(config, SL("adapter"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_factory_exception_ce, "You must provide 'adapter' option in factory config parameter.", "phalcon/Factory/AbstractFactory.zep", 55);
		return;
	}
	RETVAL_ZVAL(config, 1, 0);
	RETURN_MM();

}

/**
 * Returns the adapters for the factory
 */
PHP_METHOD(Phalcon_Factory_AbstractFactory, getAdapters) {

}

/**
 * AdapterFactory constructor.
 */
PHP_METHOD(Phalcon_Factory_AbstractFactory, init) {

	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL, adapters, name, service, _0, *_1, _2, _5$$3, _6$$4;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);
	ZVAL_UNDEF(&adapters);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &services_param);

	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&services, services_param);
	}


	ZEPHIR_CALL_METHOD(&adapters, this_ptr, "getadapters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &adapters, &services);
	ZEPHIR_CPY_WRT(&adapters, &_0);
	zephir_is_iterable(&adapters, 0, "phalcon/Factory/AbstractFactory.zep", 80);
	if (Z_TYPE_P(&adapters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&adapters), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&service);
			ZVAL_COPY(&service, _1);
			zephir_update_property_array(this_ptr, SL("mapper"), &name, &service);
			zephir_read_property(&_5$$3, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_5$$3, &name, PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &adapters, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &adapters, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &adapters, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&service, &adapters, "current", NULL, 0);
			zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("mapper"), &name, &service);
				zephir_read_property(&_6$$4, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_6$$4, &name, PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &adapters, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&service);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_Factory_AbstractFactory(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zend_update_property(Z_OBJCE_P(this_ptr), this_ptr, ZEND_STRL("services"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("mapper"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zend_update_property(Z_OBJCE_P(this_ptr), this_ptr, ZEND_STRL("mapper"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

