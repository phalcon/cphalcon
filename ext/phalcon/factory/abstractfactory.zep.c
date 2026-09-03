
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
#include "kernel/string.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * @phpstan-import-type factory_instances from FactoryTypes
 * @phpstan-import-type factory_services from FactoryTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Factory_AbstractFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Factory, AbstractFactory, phalcon, factory_abstractfactory, phalcon_factory_abstractconfigfactory_ce, phalcon_factory_abstractfactory_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @phpstan-var factory_services
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_factory_abstractfactory_ce, SL("mapper"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var factory_instances
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_factory_abstractfactory_ce, SL("services"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Checks if a service exists and throws an exception
 */
PHP_METHOD(Phalcon_Factory_AbstractFactory, getService)
{
	zval _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _3, _4, _1$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("mapper", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 12, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(!(zephir_array_isset_value(&_0, &name_zv)))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Service ", &name_zv, " is not registered");
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "getexception", NULL, 0, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Factory/AbstractFactory.zep", 39);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 12, PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Factory/AbstractFactory.zep", 42);
	RETURN_CTOR(&_4);
}

/**
 * Returns the adapters for the factory
 *
 * @phpstan-return factory_services
 */
PHP_METHOD(Phalcon_Factory_AbstractFactory, getServices)
{
}

/**
 * Initialize services/add new services
 *
 * @phpstan-param factory_services $services
 */
PHP_METHOD(Phalcon_Factory_AbstractFactory, init)
{
	zend_bool _7;
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *services_param = NULL, adapters, name, service, _0, *_1, *_2, _6, _5$$3, _8$$4;
	zval services;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&services);
	ZVAL_UNDEF(&adapters);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("services", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(services, services_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &services_param);
	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
		zephir_get_arrval(&services, services_param);
	}
	ZEPHIR_CALL_METHOD(&adapters, this_ptr, "getservices", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &adapters, &services);
	ZEPHIR_CPY_WRT(&adapters, &_0);
	if (Z_TYPE_P(&adapters) == IS_STRING) {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_string_to_char_array(&_0, &adapters);
		_1 = &_0;
	} else {
		_1 = &adapters;
	}
	zephir_is_iterable(_1, 0, "phalcon/Factory/AbstractFactory.zep", 68);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _3, _4, _2)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&service);
			ZVAL_COPY(&service, _2);
			zephir_update_property_array(this_ptr, SL("mapper"), &name, &service);
			zephir_unset_property_array(this_ptr, ZEND_STRL("services"), &name);
			zephir_read_property_cached(&_5$$3, this_ptr, _zephir_prop_0, 13, PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_5$$3, &name, PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&service, _1, "current", NULL, 0);
			zephir_check_call_status();
				zephir_update_property_array(this_ptr, SL("mapper"), &name, &service);
				zephir_unset_property_array(this_ptr, ZEND_STRL("services"), &name);
				zephir_read_property_cached(&_8$$4, this_ptr, _zephir_prop_0, 13, PH_NOISY_CC | PH_READONLY);
				zephir_array_unset(&_8$$4, &name, PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&service);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();
}

