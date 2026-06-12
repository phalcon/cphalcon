
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */
/**
 * Abstract base class for service locators.
 *
 * Provides a unified way to register, validate, and resolve services
 * from a DI container, with support for both legacy Di and new Container.
 *
 * @template T of object
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_AbstractLocator)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support, AbstractLocator, phalcon, support_abstractlocator, phalcon_support_abstractlocator_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var Collection|DiInterface
	 */
	zend_declare_property_null(phalcon_support_abstractlocator_ce, SL("container"), ZEND_ACC_PROTECTED);
	/**
	 * @phpstan-var array<string, class-string<T>>
	 * @var array
	 */
	zend_declare_property_null(phalcon_support_abstractlocator_ce, SL("services"), ZEND_ACC_PROTECTED);
	phalcon_support_abstractlocator_ce->create_object = zephir_init_properties_Phalcon_Support_AbstractLocator;

	return SUCCESS;
}

/**
 * @phpstan-param array<string, class-string<T>> $services
 */
PHP_METHOD(Phalcon_Support_AbstractLocator, __construct)
{
	zend_string *_4;
	zend_ulong _3;
	zend_bool _0, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval services;
	zval *container, container_sub, *services_param = NULL, definition, name, _1, *_2, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&services);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(container)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(services, services_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &container, &services_param);
	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
		zephir_get_arrval(&services, services_param);
	}
	_0 = !((zephir_instance_of_ev(container, phalcon_contracts_container_service_collection_ce)));
	if (_0) {
		_0 = !((zephir_instance_of_ev(container, phalcon_di_diinterface_ce)));
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_ce_type_error, "The parameter must be an instance of Collection or DiInterface", "phalcon/Support/AbstractLocator.zep", 49);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getservices", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("services"), &_1);
	zephir_is_iterable(&services, 0, "phalcon/Support/AbstractLocator.zep", 60);
	if (Z_TYPE_P(&services) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&services), _3, _4, _2)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&name, _4);
			} else {
				ZVAL_LONG(&name, _3);
			}
			ZEPHIR_INIT_NVAR(&definition);
			ZVAL_COPY(&definition, _2);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "register", &_5, 0, &name, &definition);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &services, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &services, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &services, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &services, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&definition, &services, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "register", &_5, 0, &name, &definition);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&definition);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the full registered service map (defaults plus any added via
 * register()).
 *
 * @return array<string, class-string<T>>
 */
PHP_METHOD(Phalcon_Support_AbstractLocator, getAll)
{

	RETURN_MEMBER_TYPED(getThis(), "services", IS_ARRAY);
}

/**
 * Returns the class-string registered under the given name.
 *
 * @return class-string<T>
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Support_AbstractLocator, getClass)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getservice", NULL, 0, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Whether a service with the given name is registered.
 */
PHP_METHOD(Phalcon_Support_AbstractLocator, has)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, &name_zv));
}

/**
 * Retrieve a shared service instance from the container.
 *
 * @return T
 */
PHP_METHOD(Phalcon_Support_AbstractLocator, newInstance)
{
	zval _5$$3;
	zend_class_entry *_4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, definition, exceptionClass, _0, _1, _6, _8, _2$$3, _3$$3, _7$$4;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&exceptionClass);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_5$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD(&definition, this_ptr, "getservice", NULL, 0, &name_zv);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "has", NULL, 0, &definition);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		ZEPHIR_CALL_METHOD(&exceptionClass, this_ptr, "getexceptionclass", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_fetch_safe_class(&_3$$3, &exceptionClass);
		_4$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_3$$3), Z_STRLEN_P(&_3$$3), ZEND_FETCH_CLASS_AUTO);
		if(!_4$$3) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_2$$3, _4$$3);
		ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&_2$$3);
		zephir_check_call_status();
		if (zephir_has_constructor(&_2$$3)) {
			ZEPHIR_INIT_VAR(&_5$$3);
			ZEPHIR_CONCAT_SVS(&_5$$3, "Service ", &name_zv, " was not found in the DI container");
			ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0, &_5$$3);
			zephir_check_call_status();
		}

		zephir_throw_exception_debug(&_2$$3, "phalcon/Support/AbstractLocator.zep", 108);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_6);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("container"), PH_NOISY_CC);
	if (zephir_instance_of_ev(&_6, phalcon_di_diinterface_ce)) {
		zephir_read_property(&_7$$4, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_7$$4, "getshared", NULL, 0, &definition);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_8, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_8, "get", NULL, 0, &definition);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Register a service or override an existing one.
 *
 * @phpstan-param class-string<T> $definition
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Support_AbstractLocator, register)
{
	zend_class_entry *_3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, definition_zv, exceptionClass, interfaceClass, _0, _1$$3, _2$$3, _4$$3;
	zend_string *name = NULL, *definition = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition_zv);
	ZVAL_UNDEF(&exceptionClass);
	ZVAL_UNDEF(&interfaceClass);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_STR(definition)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&definition_zv);
	ZVAL_STR_COPY(&definition_zv, definition);
	ZEPHIR_CALL_METHOD(&interfaceClass, this_ptr, "getinterfaceclass", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "is_subclass_of", NULL, 133, &definition_zv, &interfaceClass);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&exceptionClass, this_ptr, "getexceptionclass", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fetch_safe_class(&_2$$3, &exceptionClass);
		_3$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_2$$3), Z_STRLEN_P(&_2$$3), ZEND_FETCH_CLASS_AUTO);
		if(!_3$$3) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_1$$3, _3$$3);
		ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&_1$$3);
		zephir_check_call_status();
		if (zephir_has_constructor(&_1$$3)) {
			ZEPHIR_INIT_VAR(&_4$$3);
			ZEPHIR_CONCAT_SVSV(&_4$$3, "Definition ", &definition_zv, " must implement ", &interfaceClass);
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &_4$$3);
			zephir_check_call_status();
		}

		zephir_throw_exception_debug(&_1$$3, "phalcon/Support/AbstractLocator.zep", 138);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("services"), &name_zv, &definition_zv);
	RETURN_THIS();
}

/**
 * Get the exception class to throw on errors.
 *
 * @return class-string<Throwable>
 */
PHP_METHOD(Phalcon_Support_AbstractLocator, getExceptionClass)
{
}

/**
 * Get the interface/class that all registered services must implement.
 * This allows different locators to enforce different contracts.
 *
 * @return class-string
 */
PHP_METHOD(Phalcon_Support_AbstractLocator, getInterfaceClass)
{
}

/**
 * Get the service class name for a given name.
 *
 * @return class-string<T>
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Support_AbstractLocator, getService)
{
	zval _4$$3;
	zend_class_entry *_3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, exceptionClass, _0, _5, _6, _1$$3, _2$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&exceptionClass);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_value(&_0, &name_zv))) {
		ZEPHIR_CALL_METHOD(&exceptionClass, this_ptr, "getexceptionclass", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fetch_safe_class(&_2$$3, &exceptionClass);
		_3$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_2$$3), Z_STRLEN_P(&_2$$3), ZEND_FETCH_CLASS_AUTO);
		if(!_3$$3) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_1$$3, _3$$3);
		ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&_1$$3);
		zephir_check_call_status();
		if (zephir_has_constructor(&_1$$3)) {
			ZEPHIR_INIT_VAR(&_4$$3);
			ZEPHIR_CONCAT_SVS(&_4$$3, "Service ", &name_zv, " is not registered");
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &_4$$3);
			zephir_check_call_status();
		}

		zephir_throw_exception_debug(&_1$$3, "phalcon/Support/AbstractLocator.zep", 176);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Support/AbstractLocator.zep", 179);
	RETURN_CTOR(&_6);
}

/**
 * Get the default services for this locator.
 *
 * @return array<string, class-string<T>>
 */
PHP_METHOD(Phalcon_Support_AbstractLocator, getServices)
{
}

zend_object *zephir_init_properties_Phalcon_Support_AbstractLocator(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("services"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

