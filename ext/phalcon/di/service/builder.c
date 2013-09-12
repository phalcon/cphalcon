
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/hash.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\DI\Service\Builder
 *
 * This class builds instances based on complex definitions
 */
ZEPHIR_INIT_CLASS(Phalcon_DI_Service_Builder) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\DI\\Service, Builder, phalcon, di_service_builder, phalcon_di_service_builder_method_entry, 0);


	return SUCCESS;

}

/**
 * Resolves a constructor/call parameter
 *
 * @param Phalcon\DiInterface dependencyInjector
 * @param int position
 * @param array argument
 * @return mixed
 */
PHP_METHOD(Phalcon_DI_Service_Builder, _buildParameter) {

	zend_class_entry *_3, *_4;
	zval *dependencyInjector, *position, *argument, type, *name = NULL, *value, *instanceArguments, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dependencyInjector, &position, &argument);



	if (Z_TYPE_P(argument) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_di_exception_ce);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SV(_1, "Argument at position ", position);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_VS(_2, _1, " must be an array");
		zephir_call_method_p1_noret(_0, "__construct", _2);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(type);
	if (!(zephir_array_isset_string_fetch(&type, argument, SS("type")))) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_di_exception_ce);
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_SV(_1, "Argument at position ", position);
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_VS(_2, _1, " must have a type");
		zephir_call_method_p1_noret(_0, "__construct", _2);
		zephir_throw_exception(_0 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (ZEPHIR_IS_STRING(&type, "service")) {
			ZEPHIR_OBS_VAR(name);
			if (!(zephir_array_isset_string_fetch(&name, argument, SS("name")))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_1);
				ZEPHIR_CONCAT_SV(_1, "Service 'name' is required in parameter on position ", position);
				zephir_call_method_p1_noret(_0, "__construct", _1);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The dependency injector container is not valid");
				return;
			}
			zephir_call_method_p1(return_value, dependencyInjector, "get", name);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&type, "parameter")) {
			ZEPHIR_OBS_VAR(value);
			if (!(zephir_array_isset_string_fetch(&value, argument, SS("value")))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_1);
				ZEPHIR_CONCAT_SV(_1, "Service 'value' is required in parameter on position ", position);
				zephir_call_method_p1_noret(_0, "__construct", _1);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(value);
		}
		if (ZEPHIR_IS_STRING(&type, "instance")) {
			ZEPHIR_OBS_NVAR(name);
			if (!(zephir_array_isset_string_fetch(&name, argument, SS("className")))) {
				ZEPHIR_INIT_NVAR(_0);
				_3 = zend_fetch_class(SL("Phalcon_DI_Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(_0, _3);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_INIT_NVAR(_0);
				_4 = zend_fetch_class(SL("Phalcon_DI_Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				object_init_ex(_0, _4);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_VAR(instanceArguments);
			if (zephir_array_isset_string_fetch(&instanceArguments, argument, SS("arguments"))) {
				zephir_call_method_p2(return_value, dependencyInjector, "get", name, instanceArguments);
				RETURN_MM();
			} else {
				zephir_call_method_p1(return_value, dependencyInjector, "get", name);
				RETURN_MM();
			}
		}
			ZEPHIR_INIT_NVAR(_0);
			object_init_ex(_0, phalcon_di_exception_ce);
			ZEPHIR_INIT_LNVAR(_1);
			ZEPHIR_CONCAT_SV(_1, "Unknown service type in parameter on position ", position);
			zephir_call_method_p1_noret(_0, "__construct", _1);
			zephir_throw_exception(_0 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Resolves an array of parameters
 *
 * @param Phalcon\DiInterface dependencyInjector
 * @param array arguments
 * @return array
 */
PHP_METHOD(Phalcon_DI_Service_Builder, _buildParameters) {

	HashTable *_1;
	HashPosition _0;
	zval *dependencyInjector, *arguments, *position = NULL, *argument = NULL, *buildArguments, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &dependencyInjector, &arguments);



	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Definition arguments must be an array");
		return;
	}
	ZEPHIR_INIT_VAR(buildArguments);
	array_init(buildArguments);
	zephir_is_iterable(arguments, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(position, _1, _0);
		ZEPHIR_GET_HVALUE(argument, _2);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_method_p3(_3, this_ptr, "_buildparameter", dependencyInjector, position, argument);
		zephir_array_append(&buildArguments, _3, PH_SEPARATE);
	}
	RETURN_CCTOR(buildArguments);

}

/**
 * Builds a service using a complex service definition
 *
 * @param Phalcon\DiInterface dependencyInjector
 * @param array definition
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_DI_Service_Builder, build) {

	HashTable *_2, *_6;
	HashPosition _1, _5;
	zval *dependencyInjector, *definition, *parameters = NULL, *className, *arguments = NULL, paramCalls = zval_used_for_init, *methodPosition = NULL, *method = NULL, *methodName = NULL, *methodCall = NULL, *instance = NULL, *propertyPosition = NULL, *property = NULL, propertyName = zval_used_for_init, *propertyValue = NULL, *_0 = NULL, **_3, *_4 = NULL, **_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &dependencyInjector, &definition, &parameters);

	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	}


	if (Z_TYPE_P(definition) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service definition must be an array");
		return;
	}
	ZEPHIR_OBS_VAR(className);
	if (!(zephir_array_isset_string_fetch(&className, definition, SS("className")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Invalid service definition. Missing 'className' parameter");
		return;
	}
	if (Z_TYPE_P(parameters) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(instance);
		if (zephir_fast_count_int(parameters TSRMLS_CC)) {
			zephir_call_func_p2(instance, "create_instance_params", className, parameters);
		} else {
			zephir_call_func_p1(instance, "create_instance", className);
		}
	} else {
		ZEPHIR_INIT_NVAR(instance);
		ZEPHIR_OBS_VAR(arguments);
		if (zephir_array_isset_string_fetch(&arguments, definition, SS("arguments"))) {
			ZEPHIR_INIT_VAR(_0);
			zephir_call_method_p2(_0, this_ptr, "_buildparameters", dependencyInjector, arguments);
			zephir_call_func_p2(instance, "create_instance_params", className, _0);
		} else {
			zephir_call_func_p1(instance, "create_instance", className);
		}
	}
	ZEPHIR_OBS_VAR(paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, definition, SS("calls"))) {
		if (Z_TYPE_P(instance) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The definition has setter injection parameters but the constructor didn't return an instance");
			return;
		}
		if (Z_TYPE_P(paramCalls) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Setter injection parameters must be an array");
			return;
		}
		zephir_is_iterable(paramCalls, &_2, &_1, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			; zend_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HMKEY(methodPosition, _2, _1);
			ZEPHIR_GET_HVALUE(method, _3);
			if (Z_TYPE_P(method) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SV(_4, "Method call must be an array on position ", methodPosition);
				zephir_call_method_p1_noret(_0, "__construct", _4);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(methodName);
			if (!(zephir_array_isset_string_fetch(&methodName, method, SS("method")))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SV(_4, "The method name is required on position ", methodPosition);
				zephir_call_method_p1_noret(_0, "__construct", _4);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(methodCall);
			array_init(methodCall);
			zephir_array_append(&methodCall, instance, 0);
			zephir_array_append(&methodCall, methodName, 0);
			ZEPHIR_OBS_NVAR(arguments);
			if (zephir_array_isset_string_fetch(&arguments, method, SS("arguments"))) {
				if (Z_TYPE_P(arguments) != IS_ARRAY) {
					ZEPHIR_INIT_NVAR(_0);
					object_init_ex(_0, phalcon_di_exception_ce);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SV(_4, "Call arguments must be an array ", methodPosition);
					zephir_call_method_p1_noret(_0, "__construct", _4);
					zephir_throw_exception(_0 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_fast_count_int(arguments TSRMLS_CC)) {
					//missing fcall
					continue;
				}
			}
			//missing fcall
		}
	}
	ZEPHIR_OBS_NVAR(paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, definition, SS("properties"))) {
		if (Z_TYPE_P(instance) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The definition has properties injection parameters but the constructor didn't return an instance");
			return;
		}
		if (Z_TYPE_P(paramCalls) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Setter injection parameters must be an array");
			return;
		}
		zephir_is_iterable(paramCalls, &_6, &_5, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
			; zend_hash_move_forward_ex(_6, &_5)
		) {
			ZEPHIR_GET_HMKEY(propertyPosition, _6, _5);
			ZEPHIR_GET_HVALUE(property, _7);
			if (Z_TYPE_P(property) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SV(_4, "Property must be an array on position ", propertyPosition);
				zephir_call_method_p1_noret(_0, "__construct", _4);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(propertyName);
			if (!(zephir_array_isset_string_fetch(&propertyName, property, SS("name")))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SV(_4, "The property name is required on position ", propertyPosition);
				zephir_call_method_p1_noret(_0, "__construct", _4);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(propertyValue);
			if (!(zephir_array_isset_string_fetch(&propertyValue, property, SS("value")))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SV(_4, "The property value is required on position ", propertyPosition);
				zephir_call_method_p1_noret(_0, "__construct", _4);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(_0);
			zephir_call_method_p3(_0, this_ptr, "_buildparameter", dependencyInjector, propertyPosition, propertyValue);
		}
	}
	RETURN_CCTOR(instance);

}

