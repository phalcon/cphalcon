
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "Zend/zend_closures.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been heavily influenced by CapsulePHP.
 * Additionally, there are implementations from ioc-interop, which is a
 * Composer dependency, and from service-interop and resolver-interop. The
 * latter two are copied and re-implemented here: service-interop is not yet
 * published on Packagist, and resolver-interop requires PHP 8.4 (this project
 * targets PHP 8.1). Once both packages become available and compatible, the
 * copies will be replaced with the actual Composer dependencies.
 *
 * @link    https://github.com/capsulephp/di
 * @license https://github.com/capsulephp/di/blob/3.x/LICENSE.md
 *
 * @link    https://github.com/ioc-interop/interface
 * @license https://github.com/ioc-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/service-interop/interface
 * @license https://github.com/service-interop/interface/blob/1.x/LICENSE.md
 *
 * @link    https://github.com/resolver-interop/interface/tree/1.x
 * @license https://github.com/resolver-interop/interface/blob/1.x/LICENSE.md
 */
ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Resolver)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Container\\Resolver, Resolver, phalcon, container_resolver_resolver, phalcon_container_resolver_resolver_method_entry, 0);

	zend_class_implements(phalcon_container_resolver_resolver_ce, 1, phalcon_contracts_container_resolver_resolverservice_ce);
	return SUCCESS;
}

/**
 * Is this a resolvable class?
 *
 * @param string $className
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Container_Resolver_Resolver, isResolvableClass)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, _0;
	zend_string *className = NULL;

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	if (!(zephir_class_exists(&className_zv, 1))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 266, &className_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "isinstantiable", NULL, 408);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolve a call
 *
 * @param object   $ioc
 * @param callable $callable
 * @param array    $arguments
 *
 * @return mixed
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Container_Resolver_Resolver, resolveCall)
{
	zend_class_entry *_0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments;
	zval *ioc, ioc_sub, *callableObject, callableObject_sub, *arguments_param = NULL, closure, reflection, params, resolved;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&callableObject_sub);
	ZVAL_UNDEF(&closure);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&arguments);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(ioc)
		Z_PARAM_ZVAL(callableObject)
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &ioc, &callableObject, &arguments_param);
	zephir_get_arrval(&arguments, arguments_param);
	if (zephir_is_instance_of(callableObject, SL("Closure"))) {
		ZEPHIR_CPY_WRT(&closure, callableObject);
	} else {
		_0 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_CALL_CE_STATIC(&closure, _0, "fromcallable", NULL, 0, callableObject);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionfunction")));
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 263, &closure);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&params, &reflection, "getparameters", NULL, 264);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&resolved, this_ptr, "resolveparameters", NULL, 0, ioc, &params, &arguments);
	zephir_check_call_status();
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, callableObject, &resolved);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolve a class
 *
 * @param object $ioc
 * @param string $className
 * @param array  $arguments
 *
 * @return object
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Container_Resolver_Resolver, resolveClass)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arguments;
	zend_string *className = NULL;
	zval *ioc, ioc_sub, className_zv, *arguments_param = NULL, reflection, constructor, params, resolved, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&constructor);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&arguments);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(ioc)
		Z_PARAM_STR(className)
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ioc = ZEND_CALL_ARG(execute_data, 1);
	arguments_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_get_arrval(&arguments, arguments_param);
	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 266, &className_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&constructor, &reflection, "getconstructor", NULL, 390);
	zephir_check_call_status();
	if (Z_TYPE_P(&constructor) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		ZEPHIR_RETURN_CALL_METHOD(&reflection, "newinstanceargs", NULL, 389, &_0$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&params, &constructor, "getparameters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&resolved, this_ptr, "resolveparameters", NULL, 0, ioc, &params, &arguments);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&reflection, "newinstanceargs", NULL, 389, &resolved);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resolve a method
 *
 * @param object           $ioc
 * @param ReflectionMethod $method
 * @param object           $object
 *
 * @return void
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Container_Resolver_Resolver, resolveMethod)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ioc, ioc_sub, *method, method_sub, *instance, instance_sub, params, resolved, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&instance_sub);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(ioc)
		Z_PARAM_OBJECT_OF_CLASS(method, zephir_get_internal_ce(SL("reflectionmethod")))
		Z_PARAM_OBJECT(instance)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &ioc, &method, &instance);
	ZEPHIR_CALL_METHOD(&params, method, "getparameters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&resolved, this_ptr, "resolveparameters", NULL, 0, ioc, &params, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, method, "invokeargs", NULL, 0, instance, &resolved);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Resolve parameters
 *
 * @param object              $ioc
 * @param ReflectionParameter $parameter
 *
 * @return mixed
 * @throws CannotResolveParameter
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Container_Resolver_Resolver, resolveParameter)
{
	zend_bool _0, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ioc, ioc_sub, *parameter, parameter_sub, type, typeName, declaringClass, declaringName, _1, _4, _6, _7, _3$$3, _5$$5;

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&parameter_sub);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&typeName);
	ZVAL_UNDEF(&declaringClass);
	ZVAL_UNDEF(&declaringName);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$5);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(ioc)
		Z_PARAM_OBJECT_OF_CLASS(parameter, zephir_get_internal_ce(SL("reflectionparameter")))
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &ioc, &parameter);
	ZEPHIR_CALL_METHOD(&type, parameter, "gettype", NULL, 0);
	zephir_check_call_status();
	_0 = zephir_is_instance_of(&type, SL("ReflectionNamedType"));
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1, &type, "isbuiltin", NULL, 0);
		zephir_check_call_status();
		_0 = !zephir_is_true(&_1);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&typeName, &type, "getname", NULL, 0);
		zephir_check_call_status();
		_2$$3 = (zephir_method_exists_ex(ioc, ZEND_STRL("has")) == SUCCESS);
		if (_2$$3) {
			ZEPHIR_CALL_METHOD(&_3$$3, ioc, "has", NULL, 0, &typeName);
			zephir_check_call_status();
			_2$$3 = zephir_is_true(&_3$$3);
		}
		if (_2$$3) {
			ZEPHIR_RETURN_CALL_METHOD(ioc, "get", NULL, 0, &typeName);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_CALL_METHOD(&_4, parameter, "isoptional", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_CALL_METHOD(&_5$$5, parameter, "isdefaultvalueavailable", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$5)) {
			ZEPHIR_RETURN_CALL_METHOD(parameter, "getdefaultvalue", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&declaringClass, parameter, "getdeclaringclass", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&declaringClass) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&declaringName, &declaringClass, "getname", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&declaringName);
		ZVAL_STRING(&declaringName, "unknown");
	}
	ZEPHIR_INIT_VAR(&_6);
	object_init_ex(&_6, phalcon_container_exceptions_cannotresolveparameter_ce);
	ZEPHIR_CALL_METHOD(&_7, parameter, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 409, &_7, &declaringName);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_6, "phalcon/Container/Resolver/Resolver.zep", 183);
	ZEPHIR_MM_RESTORE();
	return;
}

PHP_METHOD(Phalcon_Container_Resolver_Resolver, resolveParameters)
{
	zend_bool _11;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters, arguments;
	zval *ioc, ioc_sub, *parameters_param = NULL, *arguments_param = NULL, resolved, position, parameter, name, *_0, _10, _3$$4, _4$$4, _6$$5, _7$$5, _8$$3, _12$$7, _13$$7, _14$$8, _15$$8, _16$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&resolved);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&parameter);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&arguments);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT(ioc)
		ZEPHIR_Z_PARAM_ARRAY(parameters, parameters_param)
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &ioc, &parameters_param, &arguments_param);
	zephir_get_arrval(&parameters, parameters_param);
	zephir_get_arrval(&arguments, arguments_param);
	ZEPHIR_INIT_VAR(&resolved);
	array_init(&resolved);
	zephir_is_iterable(&parameters, 0, "phalcon/Container/Resolver/Resolver.zep", 211);
	if (Z_TYPE_P(&parameters) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&parameters), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&position);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&position, _2);
			} else {
				ZVAL_LONG(&position, _1);
			}
			ZEPHIR_INIT_NVAR(&parameter);
			ZVAL_COPY(&parameter, _0);
			ZEPHIR_CALL_METHOD(&name, &parameter, "getname", NULL, 0);
			zephir_check_call_status();
			if (zephir_array_key_exists(&arguments, &position)) {
				zephir_array_fetch(&_4$$4, &arguments, &position, PH_NOISY | PH_READONLY, "phalcon/Container/Resolver/Resolver.zep", 199);
				ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "resolvearg", &_5, 410, ioc, &_4$$4);
				zephir_check_call_status();
				zephir_array_update_zval(&resolved, &position, &_3$$4, PH_COPY | PH_SEPARATE);
				continue;
			}
			if (zephir_array_key_exists(&arguments, &name)) {
				zephir_array_fetch(&_7$$5, &arguments, &name, PH_NOISY | PH_READONLY, "phalcon/Container/Resolver/Resolver.zep", 204);
				ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "resolvearg", &_5, 410, ioc, &_7$$5);
				zephir_check_call_status();
				zephir_array_update_zval(&resolved, &position, &_6$$5, PH_COPY | PH_SEPARATE);
				continue;
			}
			ZEPHIR_CALL_METHOD(&_8$$3, this_ptr, "resolveparameter", &_9, 0, ioc, &parameter);
			zephir_check_call_status();
			zephir_array_update_zval(&resolved, &position, &_8$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &parameters, "rewind", NULL, 0);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &parameters, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_10, &parameters, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&position, &parameters, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&parameter, &parameters, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&name, &parameter, "getname", NULL, 0);
				zephir_check_call_status();
				if (zephir_array_key_exists(&arguments, &position)) {
					zephir_array_fetch(&_13$$7, &arguments, &position, PH_NOISY | PH_READONLY, "phalcon/Container/Resolver/Resolver.zep", 199);
					ZEPHIR_CALL_METHOD(&_12$$7, this_ptr, "resolvearg", &_5, 410, ioc, &_13$$7);
					zephir_check_call_status();
					zephir_array_update_zval(&resolved, &position, &_12$$7, PH_COPY | PH_SEPARATE);
					continue;
				}
				if (zephir_array_key_exists(&arguments, &name)) {
					zephir_array_fetch(&_15$$8, &arguments, &name, PH_NOISY | PH_READONLY, "phalcon/Container/Resolver/Resolver.zep", 204);
					ZEPHIR_CALL_METHOD(&_14$$8, this_ptr, "resolvearg", &_5, 410, ioc, &_15$$8);
					zephir_check_call_status();
					zephir_array_update_zval(&resolved, &position, &_14$$8, PH_COPY | PH_SEPARATE);
					continue;
				}
				ZEPHIR_CALL_METHOD(&_16$$6, this_ptr, "resolveparameter", &_9, 0, ioc, &parameter);
				zephir_check_call_status();
				zephir_array_update_zval(&resolved, &position, &_16$$6, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&parameter);
	ZEPHIR_INIT_NVAR(&position);
	RETURN_CCTOR(&resolved);
}

/**
 * type is ReflectionType
 */
PHP_METHOD(Phalcon_Container_Resolver_Resolver, resolveType)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ioc, ioc_sub, *type, type_sub;

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&type_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(ioc)
		Z_PARAM_ZVAL(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &ioc, &type);
	if (zephir_is_instance_of(type, SL("ReflectionNamedType"))) {
		ZEPHIR_RETURN_CALL_METHOD(type, "getname", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();
}

PHP_METHOD(Phalcon_Container_Resolver_Resolver, resolveArg)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *ioc, ioc_sub, *arg, arg_sub;

	ZVAL_UNDEF(&ioc_sub);
	ZVAL_UNDEF(&arg_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT(ioc)
		Z_PARAM_ZVAL(arg)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &ioc, &arg);
	_0 = Z_TYPE_P(arg) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(arg, phalcon_container_resolver_lazy_lazy_ce);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(arg, "resolve", NULL, 0, ioc);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(arg, 1, 0);
	RETURN_MM();
}

