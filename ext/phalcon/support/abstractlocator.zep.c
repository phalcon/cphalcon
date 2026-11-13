
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
 * For the full copyright and license information, please view the LICENSE
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
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_support_abstractlocator_ce, SL("services"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

/**
 * @phpstan-param array<string, class-string<T>> $services
 */
PHP_METHOD(Phalcon_Support_AbstractLocator, __construct)
{
	zend_string *_4;
	zend_ulong _3;
	zend_bool _0, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval services;
	zval *container, container_sub, *services_param = NULL, definition, name, _1, *_2, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&services);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("services", 8, 1);
	}

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_ce_type_error, "The parameter must be an instance of Collection or DiInterface", "phalcon/Support/AbstractLocator.zep", 48);
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 136, container);
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "getServices", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 137, &_1);
	zephir_is_iterable(&services, 0, "phalcon/Support/AbstractLocator.zep", 59);
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
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "register", &_zephir_call_cache[1], &name, &definition);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &services, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &services, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_5, &services, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&name, &services, "key", &_zephir_call_cache[5]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&definition, &services, "current", &_zephir_call_cache[6]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "register", &_zephir_call_cache[7], &name, &definition);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "getService", &_zephir_call_cache[0], &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Whether a service with the given name is registered.
 */
PHP_METHOD(Phalcon_Support_AbstractLocator, has)
{
	zend_bool _1;
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("services", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 137, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	_1 = zephir_array_isset_value(&_0, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_BOOL(_1);
}

/**
 * Retrieve a service instance from the container.
 *
 * On the `DiInterface` path this returns the container's **shared**
 * instance (`getShared()`) - despite the name, it is not a fresh build.
 * Locators whose services carry per-activation state should override this
 * method to resolve a fresh instance; see `Auth\Access\AccessLocator`, which uses
 * `ContainerResolver::resolveFresh` for exactly that reason.
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("container", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_CALL_METHOD_CACHED(&definition, this_ptr, "getService", &_zephir_call_cache[0], &name_zv);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 136, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_1, &_0, "has", &_zephir_call_cache[1], &definition);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		ZEPHIR_CALL_METHOD_CACHED(&exceptionClass, this_ptr, "getExceptionClass", &_zephir_call_cache[2]);
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[3], &_5$$3);
			zephir_check_call_status();
		}

		zephir_throw_exception_debug(&_2$$3, "phalcon/Support/AbstractLocator.zep", 113);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_6);
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_0, 136, PH_NOISY_CC);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_instance_of_ev(&_6, phalcon_di_diinterface_ce)) {
		zephir_read_property_cached(&_7$$4, this_ptr, _zephir_prop_0, 136, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_RETURN_CALL_METHOD_CACHED(&_7$$4, "getShared", &_zephir_call_cache[4], &definition);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_0, 136, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&_8, "get", &_zephir_call_cache[5], &definition);
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
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
	ZEPHIR_CALL_METHOD_CACHED(&interfaceClass, this_ptr, "getInterfaceClass", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "is_subclass_of", NULL, 41, &definition_zv, &interfaceClass);
	zephir_check_call_status();
	if (!zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD_CACHED(&exceptionClass, this_ptr, "getExceptionClass", &_zephir_call_cache[1]);
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
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[2], &_4$$3);
			zephir_check_call_status();
		}

		zephir_throw_exception_debug(&_1$$3, "phalcon/Support/AbstractLocator.zep", 143);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("services"), &name_zv, &definition_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	zval _5$$3;
	zend_class_entry *_4$$3;
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, exceptionClass, _0, _6, _7, _2$$3, _3$$3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&exceptionClass);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("services", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 137, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_value(&_0, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		ZEPHIR_CALL_METHOD_CACHED(&exceptionClass, this_ptr, "getExceptionClass", &_zephir_call_cache[0]);
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
			ZEPHIR_CONCAT_SVS(&_5$$3, "Service ", &name_zv, " is not registered");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[1], &_5$$3);
			zephir_check_call_status();
		}

		zephir_throw_exception_debug(&_2$$3, "phalcon/Support/AbstractLocator.zep", 181);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_0, 137, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_7);
	zephir_array_fetch(&_7, &_6, &name_zv, PH_NOISY, "phalcon/Support/AbstractLocator.zep", 184);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&_7);
}

/**
 * Get the default services for this locator.
 *
 * @return array<string, class-string<T>>
 */
PHP_METHOD(Phalcon_Support_AbstractLocator, getServices)
{
}

