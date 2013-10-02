
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/object.h"


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
 * Phalcon\Di\Service\Builder
 *
 * This class builds instances based on complex definitions
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_Service_Builder) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Di\\Service, Builder, phalcon, di_service_builder, phalcon_di_service_builder_method_entry, 0);


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
PHP_METHOD(Phalcon_Di_Service_Builder, _buildParameter) {

	int position;
	zval *dependencyInjector, *position_param = NULL, *argument, *type, *name = NULL, *value, *instanceArguments, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dependencyInjector, &position_param, &argument);

		position = zephir_get_intval(position_param);


	if ((Z_TYPE_P(argument) != IS_ARRAY)) {
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
	if (!(zephir_array_isset_string_fetch(&type, argument, SS("type"), 1 TSRMLS_CC))) {
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
		if (ZEPHIR_IS_STRING(type, "service")) {
			ZEPHIR_OBS_VAR(name);
			if (!(zephir_array_isset_string_fetch(&name, argument, SS("name"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_1);
				ZEPHIR_CONCAT_SV(_1, "Service 'name' is required in parameter on position ", position);
				zephir_call_method_p1_noret(_0, "__construct", _1);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The dependency injector container is not valid");
				return;
			}
			zephir_call_method_p1(return_value, dependencyInjector, "get", name);
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "parameter")) {
			if (!(zephir_array_isset_string_fetch(&value, argument, SS("value"), 1 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_1);
				ZEPHIR_CONCAT_SV(_1, "Service 'value' is required in parameter on position ", position);
				zephir_call_method_p1_noret(_0, "__construct", _1);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_MM_RESTORE();
			RETURN_ZVAL(value, 1, 0);
		}
		if (ZEPHIR_IS_STRING(type, "instance")) {
			ZEPHIR_OBS_NVAR(name);
			if (!(zephir_array_isset_string_fetch(&name, argument, SS("className"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_1);
				ZEPHIR_CONCAT_SV(_1, "Service 'className' is required in parameter on position ", position);
				zephir_call_method_p1_noret(_0, "__construct", _1);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
				ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The dependency injector container is not valid");
				return;
			}
			if (zephir_array_isset_string_fetch(&instanceArguments, argument, SS("arguments"), 1 TSRMLS_CC)) {
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
PHP_METHOD(Phalcon_Di_Service_Builder, _buildParameters) {

	zend_function *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *dependencyInjector, *arguments, *position = NULL, *argument = NULL, *buildArguments, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &dependencyInjector, &arguments);



	if ((Z_TYPE_P(arguments) != IS_ARRAY)) {
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
		zephir_call_method_p3_cache(_3, this_ptr, "_buildparameter", &_4, dependencyInjector, position, argument);
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
PHP_METHOD(Phalcon_Di_Service_Builder, build) {

	zend_function *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL;
	HashTable *_2, *_10;
	HashPosition _1, _9;
	zval *dependencyInjector, *definition, *parameters = NULL, *className, *arguments = NULL, *paramCalls = NULL, *methodPosition = NULL, *method = NULL, *methodName, *methodCall = NULL, *instance = NULL, *propertyPosition = NULL, *property = NULL, *propertyName, *propertyValue, *_0 = NULL, **_3, *_4 = NULL, **_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &dependencyInjector, &definition, &parameters);

	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	}


	if ((Z_TYPE_P(definition) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service definition must be an array");
		return;
	}
	if (!(zephir_array_isset_string_fetch(&className, definition, SS("className"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Invalid service definition. Missing 'className' parameter");
		return;
	}
	if ((Z_TYPE_P(parameters) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(instance);
		if (zephir_fast_count_int(parameters TSRMLS_CC)) {
			if (zephir_create_instance_params(instance, className, parameters TSRMLS_CC) == FAILURE) {
				return;
			}
		} else {
			if (zephir_create_instance(instance, className TSRMLS_CC) == FAILURE) {
				return;
			}
		}
	} else {
		ZEPHIR_INIT_NVAR(instance);
		ZEPHIR_OBS_VAR(arguments);
		if (zephir_array_isset_string_fetch(&arguments, definition, SS("arguments"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_0);
			zephir_call_method_p2(_0, this_ptr, "_buildparameters", dependencyInjector, arguments);
			if (zephir_create_instance_params(instance, className, _0 TSRMLS_CC) == FAILURE) {
				return;
			}
		} else {
			if (zephir_create_instance(instance, className TSRMLS_CC) == FAILURE) {
				return;
			}
		}
	}
	ZEPHIR_OBS_VAR(paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, definition, SS("calls"), 0 TSRMLS_CC)) {
		if ((Z_TYPE_P(instance) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The definition has setter injection parameters but the constructor didn't return an instance");
			return;
		}
		if ((Z_TYPE_P(paramCalls) != IS_ARRAY)) {
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
			if ((Z_TYPE_P(method) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SV(_4, "Method call must be an array on position ", methodPosition);
				zephir_call_method_p1_cache_noret(_0, "__construct", &_5, _4);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(zephir_array_isset_string_fetch(&methodName, method, SS("method"), 1 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SV(_4, "The method name is required on position ", methodPosition);
				zephir_call_method_p1_cache_noret(_0, "__construct", &_6, _4);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(methodCall);
			array_init(methodCall);
			zend_hash_next_index_insert(Z_ARRVAL_P(methodCall), &instance, sizeof(zval *), NULL);
			zend_hash_next_index_insert(Z_ARRVAL_P(methodCall), &methodName, sizeof(zval *), NULL);
			ZEPHIR_OBS_NVAR(arguments);
			if (zephir_array_isset_string_fetch(&arguments, method, SS("arguments"), 0 TSRMLS_CC)) {
				if ((Z_TYPE_P(arguments) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(_0);
					object_init_ex(_0, phalcon_di_exception_ce);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SV(_4, "Call arguments must be an array ", methodPosition);
					zephir_call_method_p1_cache_noret(_0, "__construct", &_7, _4);
					zephir_throw_exception(_0 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_fast_count_int(arguments TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_0);
					zephir_call_method_p2_cache(_0, this_ptr, "_buildparameters", &_8, dependencyInjector, arguments);
					zephir_call_func_p2_noret("call_user_func_array", methodCall, _0);
					continue;
				}
			}
			zephir_call_func_p1_noret("call_user_func", methodCall);
		}
	}
	ZEPHIR_OBS_NVAR(paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, definition, SS("properties"), 0 TSRMLS_CC)) {
		if ((Z_TYPE_P(instance) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The definition has properties injection parameters but the constructor didn't return an instance");
			return;
		}
		if ((Z_TYPE_P(paramCalls) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Setter injection parameters must be an array");
			return;
		}
		zephir_is_iterable(paramCalls, &_10, &_9, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
			; zend_hash_move_forward_ex(_10, &_9)
		) {
			ZEPHIR_GET_HMKEY(propertyPosition, _10, _9);
			ZEPHIR_GET_HVALUE(property, _11);
			if ((Z_TYPE_P(property) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SV(_4, "Property must be an array on position ", propertyPosition);
				zephir_call_method_p1_cache_noret(_0, "__construct", &_12, _4);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(zephir_array_isset_string_fetch(&propertyName, property, SS("name"), 1 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SV(_4, "The property name is required on position ", propertyPosition);
				zephir_call_method_p1_cache_noret(_0, "__construct", &_13, _4);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(zephir_array_isset_string_fetch(&propertyValue, property, SS("value"), 1 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SV(_4, "The property value is required on position ", propertyPosition);
				zephir_call_method_p1_cache_noret(_0, "__construct", &_14, _4);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(_0);
			zephir_call_method_p3_cache(_0, this_ptr, "_buildparameter", &_15, dependencyInjector, propertyPosition, propertyValue);
			zephir_update_property_zval_zval(instance, propertyName, _0 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(instance);

}

