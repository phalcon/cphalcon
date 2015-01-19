
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

	zval *_2 = NULL;
	int position, ZEPHIR_LAST_CALL_STATUS;
	zval *dependencyInjector, *position_param = NULL, *argument, *type, *name = NULL, *value, *instanceArguments, *_0 = NULL, _1 = zval_used_for_init;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &dependencyInjector, &position_param, &argument);

	position = zephir_get_intval(position_param);


	if (!(zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(argument) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, phalcon_di_exception_ce);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, position);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Argument at position ", &_1, " must be an array");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/di/service/builder.zep", 50 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(type);
	if (!(zephir_array_isset_string_fetch(&type, argument, SS("type"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_di_exception_ce);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, position);
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_SVS(_2, "Argument at position ", &_1, " must have a type");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/di/service/builder.zep", 57 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	do {
		if (ZEPHIR_IS_STRING(type, "service")) {
			ZEPHIR_OBS_VAR(name);
			if (!(zephir_array_isset_string_fetch(&name, argument, SS("name"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, position);
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_SV(_2, "Service 'name' is required in parameter on position ", &_1);
				ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
				zephir_check_call_status();
				zephir_throw_exception_debug(_0, "phalcon/di/service/builder.zep", 67 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The dependency injector container is not valid", "phalcon/di/service/builder.zep", 70);
				return;
			}
			ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "get", NULL, name);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(type, "parameter")) {
			ZEPHIR_OBS_VAR(value);
			if (!(zephir_array_isset_string_fetch(&value, argument, SS("value"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, position);
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_SV(_2, "Service 'value' is required in parameter on position ", &_1);
				ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
				zephir_check_call_status();
				zephir_throw_exception_debug(_0, "phalcon/di/service/builder.zep", 79 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_CCTOR(value);
		}
		if (ZEPHIR_IS_STRING(type, "instance")) {
			ZEPHIR_OBS_NVAR(name);
			if (!(zephir_array_isset_string_fetch(&name, argument, SS("className"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_di_exception_ce);
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, position);
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_SV(_2, "Service 'className' is required in parameter on position ", &_1);
				ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
				zephir_check_call_status();
				zephir_throw_exception_debug(_0, "phalcon/di/service/builder.zep", 89 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The dependency injector container is not valid", "phalcon/di/service/builder.zep", 93);
				return;
			}
			ZEPHIR_OBS_VAR(instanceArguments);
			if (zephir_array_isset_string_fetch(&instanceArguments, argument, SS("arguments"), 0 TSRMLS_CC)) {
				ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "get", NULL, name, instanceArguments);
				zephir_check_call_status();
				RETURN_MM();
			} else {
				ZEPHIR_RETURN_CALL_METHOD(dependencyInjector, "get", NULL, name);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, phalcon_di_exception_ce);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, position);
		ZEPHIR_INIT_LNVAR(_2);
		ZEPHIR_CONCAT_SV(_2, "Unknown service type in parameter on position ", &_1);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalcon/di/service/builder.zep", 111 TSRMLS_CC);
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

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *dependencyInjector, *arguments, *position = NULL, *argument = NULL, *buildArguments, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &dependencyInjector, &arguments);



	if (!(zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Definition arguments must be an array", "phalcon/di/service/builder.zep", 130);
		return;
	}
	ZEPHIR_INIT_VAR(buildArguments);
	array_init(buildArguments);
	zephir_is_iterable(arguments, &_1, &_0, 0, 0, "phalcon/di/service/builder.zep", 137);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(position, _1, _0);
		ZEPHIR_GET_HVALUE(argument, _2);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "_buildparameter", &_4, dependencyInjector, position, argument);
		zephir_check_call_status();
		zephir_array_append(&buildArguments, _3, PH_SEPARATE, "phalcon/di/service/builder.zep", 135);
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

	zephir_fcall_cache_entry *_7 = NULL;
	HashTable *_3, *_9;
	HashPosition _2, _8;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *definition = NULL;
	zval *dependencyInjector, *definition_param = NULL, *parameters = NULL, *className, *arguments = NULL, *paramCalls = NULL, *methodPosition = NULL, *method = NULL, *methodName = NULL, *methodCall = NULL, *instance = NULL, *propertyPosition = NULL, *property = NULL, *propertyName = NULL, *propertyValue = NULL, *reflection = NULL, *_0 = NULL, **_4, *_5 = NULL, *_6 = NULL, **_10, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &dependencyInjector, &definition_param, &parameters);

	definition = definition_param;

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(className);
	if (!(zephir_array_isset_string_fetch(&className, definition, SS("className"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Invalid service definition. Missing 'className' parameter", "phalcon/di/service/builder.zep", 158);
		return;
	}
	if (Z_TYPE_P(parameters) == IS_ARRAY) {
		if (zephir_fast_count_int(parameters TSRMLS_CC)) {
			if (zephir_is_php_version(50600)) {
				ZEPHIR_INIT_VAR(reflection);
				object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
				ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, className);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&instance, reflection, "newinstanceargs", NULL, parameters);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(instance);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(instance, className, parameters TSRMLS_CC);
				zephir_check_call_status();
			}
		} else {
			if (zephir_is_php_version(50600)) {
				ZEPHIR_INIT_NVAR(reflection);
				object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
				ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, className);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&instance, reflection, "newinstanceargs", NULL, parameters);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(instance);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(instance, className TSRMLS_CC);
				zephir_check_call_status();
			}
		}
	} else {
		ZEPHIR_OBS_VAR(arguments);
		if (zephir_array_isset_string_fetch(&arguments, definition, SS("arguments"), 0 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(instance);
			ZEPHIR_CALL_METHOD(&_0, this_ptr, "_buildparameters", &_1, dependencyInjector, arguments);
			zephir_check_call_status();
			ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(instance, className, _0 TSRMLS_CC);
			zephir_check_call_status();
		} else {
			if (zephir_is_php_version(50600)) {
				ZEPHIR_INIT_NVAR(reflection);
				object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
				ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, className);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&instance, reflection, "newinstanceargs", NULL, parameters);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(instance);
				ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(instance, className TSRMLS_CC);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_OBS_VAR(paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, definition, SS("calls"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(instance) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The definition has setter injection parameters but the constructor didn't return an instance", "phalcon/di/service/builder.zep", 210);
			return;
		}
		if (Z_TYPE_P(paramCalls) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Setter injection parameters must be an array", "phalcon/di/service/builder.zep", 214);
			return;
		}
		zephir_is_iterable(paramCalls, &_3, &_2, 0, 0, "phalcon/di/service/builder.zep", 268);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HMKEY(methodPosition, _3, _2);
			ZEPHIR_GET_HVALUE(method, _4);
			if (Z_TYPE_P(method) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(_5);
				object_init_ex(_5, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SV(_6, "Method call must be an array on position ", methodPosition);
				ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_7, _6);
				zephir_check_call_status();
				zephir_throw_exception_debug(_5, "phalcon/di/service/builder.zep", 226 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(methodName);
			if (!(zephir_array_isset_string_fetch(&methodName, method, SS("method"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_5);
				object_init_ex(_5, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SV(_6, "The method name is required on position ", methodPosition);
				ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_7, _6);
				zephir_check_call_status();
				zephir_throw_exception_debug(_5, "phalcon/di/service/builder.zep", 233 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(methodCall);
			array_init_size(methodCall, 3);
			zephir_array_fast_append(methodCall, instance);
			zephir_array_fast_append(methodCall, methodName);
			ZEPHIR_OBS_NVAR(arguments);
			if (zephir_array_isset_string_fetch(&arguments, method, SS("arguments"), 0 TSRMLS_CC)) {
				if (Z_TYPE_P(arguments) != IS_ARRAY) {
					ZEPHIR_INIT_NVAR(_5);
					object_init_ex(_5, phalcon_di_exception_ce);
					ZEPHIR_INIT_LNVAR(_6);
					ZEPHIR_CONCAT_SV(_6, "Call arguments must be an array ", methodPosition);
					ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_7, _6);
					zephir_check_call_status();
					zephir_throw_exception_debug(_5, "phalcon/di/service/builder.zep", 244 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_fast_count_int(arguments TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_5);
					ZEPHIR_CALL_METHOD(&_0, this_ptr, "_buildparameters", &_1, dependencyInjector, arguments);
					zephir_check_call_status();
					ZEPHIR_CALL_USER_FUNC_ARRAY(_5, methodCall, _0);
					zephir_check_call_status();
					continue;
				}
			}
			ZEPHIR_INIT_NVAR(_5);
			ZEPHIR_CALL_USER_FUNC(_5, methodCall);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_NVAR(paramCalls);
	if (zephir_array_isset_string_fetch(&paramCalls, definition, SS("properties"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(instance) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "The definition has properties injection parameters but the constructor didn't return an instance", "phalcon/di/service/builder.zep", 276);
			return;
		}
		if (Z_TYPE_P(paramCalls) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_di_exception_ce, "Setter injection parameters must be an array", "phalcon/di/service/builder.zep", 280);
			return;
		}
		zephir_is_iterable(paramCalls, &_9, &_8, 0, 0, "phalcon/di/service/builder.zep", 315);
		for (
		  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
		  ; zephir_hash_move_forward_ex(_9, &_8)
		) {
			ZEPHIR_GET_HMKEY(propertyPosition, _9, _8);
			ZEPHIR_GET_HVALUE(property, _10);
			if (Z_TYPE_P(property) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(_11);
				object_init_ex(_11, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SV(_6, "Property must be an array on position ", propertyPosition);
				ZEPHIR_CALL_METHOD(NULL, _11, "__construct", &_7, _6);
				zephir_check_call_status();
				zephir_throw_exception_debug(_11, "phalcon/di/service/builder.zep", 292 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(propertyName);
			if (!(zephir_array_isset_string_fetch(&propertyName, property, SS("name"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_5);
				object_init_ex(_5, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SV(_6, "The property name is required on position ", propertyPosition);
				ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_7, _6);
				zephir_check_call_status();
				zephir_throw_exception_debug(_5, "phalcon/di/service/builder.zep", 299 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(propertyValue);
			if (!(zephir_array_isset_string_fetch(&propertyValue, property, SS("value"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_5);
				object_init_ex(_5, phalcon_di_exception_ce);
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SV(_6, "The property value is required on position ", propertyPosition);
				ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_7, _6);
				zephir_check_call_status();
				zephir_throw_exception_debug(_5, "phalcon/di/service/builder.zep", 306 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_0, this_ptr, "_buildparameter", &_12, dependencyInjector, propertyPosition, propertyValue);
			zephir_check_call_status();
			zephir_update_property_zval_zval(instance, propertyName, _0 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(instance);

}

