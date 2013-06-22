
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/object.h"

/**
 * Phalcon\DI\Service\Builder
 *
 * This class builds instances based on complex definitions
 */


/**
 * Phalcon\DI\Service\Builder initializer
 */
PHALCON_INIT_CLASS(Phalcon_DI_Service_Builder){

	PHALCON_REGISTER_CLASS(Phalcon\\DI\\Service, Builder, di_service_builder, phalcon_di_service_builder_method_entry, 0);

	return SUCCESS;
}

/**
 * Resolves a constructor/call parameter
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @param int $position
 * @param array $argument
 * @return mixed
 */
PHP_METHOD(Phalcon_DI_Service_Builder, _buildParameter){

	zval *dependency_injector, *position, *argument;
	zval *exception_message = NULL, *type, *name = NULL, *value = NULL, *instance_arguments;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &dependency_injector, &position, &argument);
	
	/** 
	 * All the arguments must be an array
	 */
	if (Z_TYPE_P(argument) != IS_ARRAY) { 
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Argument at position ", position, " must be an array");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
		return;
	}
	
	/** 
	 * All the arguments must have a type
	 */
	if (!phalcon_array_isset_string(argument, SS("type"))) {
		PHALCON_INIT_NVAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Argument at position ", position, " must have a type");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
		return;
	}
	
	PHALCON_OBS_VAR(type);
	phalcon_array_fetch_string(&type, argument, SL("type"), PH_NOISY_CC);
	
	/** 
	 * If the argument type is 'service', we obtain the service from the DI
	 */
	if (PHALCON_IS_STRING(type, "service")) {
		if (!phalcon_array_isset_string(argument, SS("name"))) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SV(exception_message, "Service 'name' is required in parameter on position ", position);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
			return;
		}
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The dependency injector container is not valid");
			return;
		}
	
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_string(&name, argument, SL("name"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(value);
		phalcon_call_method_p1(value, dependency_injector, "get", name);
	
		RETURN_CCTOR(value);
	}
	
	/** 
	 * If the argument type is 'parameter', we assign the value as it is
	 */
	if (PHALCON_IS_STRING(type, "parameter")) {
		if (!phalcon_array_isset_string(argument, SS("value"))) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SV(exception_message, "Service 'value' is required in parameter on position ", position);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
			return;
		}
	
		PHALCON_OBS_NVAR(value);
		phalcon_array_fetch_string(&value, argument, SL("value"), PH_NOISY_CC);
	
		RETURN_CCTOR(value);
	}
	
	/** 
	 * If the argument type is 'instance', we assign the value as it is
	 */
	if (PHALCON_IS_STRING(type, "instance")) {
		if (!phalcon_array_isset_string(argument, SS("className"))) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SV(exception_message, "Service 'className' is required in parameter on position ", position);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
			return;
		}
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The dependency injector container is not valid");
			return;
		}
	
		PHALCON_OBS_NVAR(name);
		phalcon_array_fetch_string(&name, argument, SL("className"), PH_NOISY_CC);
		if (!phalcon_array_isset_string(argument, SS("arguments"))) {
			/** 
			 * The instance parameter does not have arguments for its constructor
			 */
			PHALCON_INIT_NVAR(value);
			phalcon_call_method_p1(value, dependency_injector, "get", name);
		} else {
			PHALCON_OBS_VAR(instance_arguments);
			phalcon_array_fetch_string(&instance_arguments, argument, SL("arguments"), PH_NOISY_CC);
	
			/** 
			 * Build the instance with arguments
			 */
			PHALCON_INIT_NVAR(value);
			phalcon_call_method_p2(value, dependency_injector, "get", name, instance_arguments);
		}
	
		RETURN_CCTOR(value);
	}
	
	/** 
	 * Unknown parameter type 
	 */
	PHALCON_INIT_NVAR(exception_message);
	PHALCON_CONCAT_SV(exception_message, "Unknown service type in parameter on position ", position);
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
	return;
}

/**
 * Resolves an array of parameters
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @param array $arguments
 * @return arguments
 */
PHP_METHOD(Phalcon_DI_Service_Builder, _buildParameters){

	zval *dependency_injector, *arguments, *build_arguments;
	zval *argument = NULL, *position = NULL, *value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &dependency_injector, &arguments);
	
	/** 
	 * The arguments group must be an array of arrays
	 */
	if (Z_TYPE_P(arguments) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Definition arguments must be an array");
		return;
	}
	
	PHALCON_INIT_VAR(build_arguments);
	array_init(build_arguments);
	
	phalcon_is_iterable(arguments, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HKEY(position, ah0, hp0);
		PHALCON_GET_HVALUE(argument);
	
		PHALCON_INIT_NVAR(value);
		phalcon_call_method_p3(value, this_ptr, "_buildparameter", dependency_injector, position, argument);
		phalcon_array_append(&build_arguments, value, PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_CTOR(build_arguments);
}

/**
 * Builds a service using a complex service definition
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @param array $definition
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_DI_Service_Builder, build){

	zval *dependency_injector, *definition, *parameters = NULL;
	zval *class_name, *instance = NULL, *arguments = NULL, *build_arguments = NULL;
	zval *param_calls = NULL, *method = NULL, *method_position = NULL;
	zval *exception_message = NULL, *method_name = NULL, *method_call = NULL;
	zval *status = NULL, *property = NULL, *property_position = NULL;
	zval *property_name = NULL, *property_value = NULL, *value = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &dependency_injector, &definition, &parameters);
	
	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	if (Z_TYPE_P(definition) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service definition must be an array");
		return;
	}
	
	/** 
	 * The class name is required
	 */
	if (!phalcon_array_isset_string(definition, SS("className"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Invalid service definition. Missing 'className' parameter");
		return;
	}
	
	PHALCON_OBS_VAR(class_name);
	phalcon_array_fetch_string(&class_name, definition, SL("className"), PH_NOISY_CC);
	if (Z_TYPE_P(parameters) == IS_ARRAY) { 
	
		/** 
		 * Build the instance overriding the definition constructor parameters
		 */
		if (phalcon_fast_count_ev(parameters TSRMLS_CC)) {
			PHALCON_INIT_VAR(instance);
			if (phalcon_create_instance_params(instance, class_name, parameters TSRMLS_CC) == FAILURE) {
				return;
			}
		} else {
			PHALCON_INIT_NVAR(instance);
			if (phalcon_create_instance(instance, class_name TSRMLS_CC) == FAILURE) {
				return;
			}
		}
	} else {
		/** 
		 * Check if the argument has constructor arguments
		 */
		if (phalcon_array_isset_string(definition, SS("arguments"))) {
			PHALCON_OBS_VAR(arguments);
			phalcon_array_fetch_string(&arguments, definition, SL("arguments"), PH_NOISY_CC);
	
			/** 
			 * Resolve the constructor parameters
			 */
			PHALCON_INIT_VAR(build_arguments);
			phalcon_call_method_p2(build_arguments, this_ptr, "_buildparameters", dependency_injector, arguments);
	
			/** 
			 * Create the instance based on the parameters
			 */
			PHALCON_INIT_NVAR(instance);
			if (phalcon_create_instance_params(instance, class_name, build_arguments TSRMLS_CC) == FAILURE) {
				return;
			}
		} else {
			PHALCON_INIT_NVAR(instance);
			if (phalcon_create_instance(instance, class_name TSRMLS_CC) == FAILURE) {
				return;
			}
		}
	}
	
	/** 
	 * The definition has calls?
	 */
	if (phalcon_array_isset_string(definition, SS("calls"))) {
		if (Z_TYPE_P(instance) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The definition has setter injection parameters but the constructor didn't return an instance");
			return;
		}
	
		PHALCON_OBS_VAR(param_calls);
		phalcon_array_fetch_string(&param_calls, definition, SL("calls"), PH_NOISY_CC);
		if (Z_TYPE_P(param_calls) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Setter injection parameters must be an array");
			return;
		}
	
		/** 
		 * The method call has parameters
		 */
		phalcon_is_iterable(param_calls, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(method_position, ah0, hp0);
			PHALCON_GET_HVALUE(method);
	
			/** 
			 * The call parameter must be an array of arrays
			 */
			if (Z_TYPE_P(method) != IS_ARRAY) { 
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SV(exception_message, "Method call must be an array on position ", method_position);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * A param 'method' is required
			 */
			if (!phalcon_array_isset_string(method, SS("method"))) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SV(exception_message, "The method name is required on position ", method_position);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
				return;
			}
	
			PHALCON_OBS_NVAR(method_name);
			phalcon_array_fetch_string(&method_name, method, SL("method"), PH_NOISY_CC);
	
			/** 
			 * Create the method call
			 */
			PHALCON_INIT_NVAR(method_call);
			array_init_size(method_call, 2);
			phalcon_array_append(&method_call, instance, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&method_call, method_name, PH_SEPARATE TSRMLS_CC);
			if (phalcon_array_isset_string(method, SS("arguments"))) {
	
				PHALCON_OBS_NVAR(arguments);
				phalcon_array_fetch_string(&arguments, method, SL("arguments"), PH_NOISY_CC);
				if (Z_TYPE_P(arguments) != IS_ARRAY) { 
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SV(exception_message, "Call arguments must be an array ", method_position);
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
					return;
				}
	
				if (phalcon_fast_count_ev(arguments TSRMLS_CC)) {
					/** 
					 * Resolve the constructor parameters
					 */
					PHALCON_INIT_NVAR(build_arguments);
					phalcon_call_method_p2(build_arguments, this_ptr, "_buildparameters", dependency_injector, arguments);
	
					/** 
					 * Call the method on the instance
					 */
					PHALCON_INIT_NVAR(status);
					PHALCON_CALL_USER_FUNC_ARRAY(status, method_call, build_arguments);
	
					/** 
					 * Go to next method call
					 */
					zend_hash_move_forward_ex(ah0, &hp0);
					continue;
				}
			}
	
			/** 
			 * Call the method on the instance without arguments
			 */
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_USER_FUNC(status, method_call);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	/** 
	 * The definition has properties?
	 */
	if (phalcon_array_isset_string(definition, SS("properties"))) {
		if (Z_TYPE_P(instance) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The definition has properties injection parameters but the constructor didn't return an instance");
			return;
		}
	
		PHALCON_OBS_NVAR(param_calls);
		phalcon_array_fetch_string(&param_calls, definition, SL("properties"), PH_NOISY_CC);
		if (Z_TYPE_P(param_calls) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Setter injection parameters must be an array");
			return;
		}
	
		/** 
		 * The method call has parameters
		 */
		phalcon_is_iterable(param_calls, &ah1, &hp1, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_HKEY(property_position, ah1, hp1);
			PHALCON_GET_HVALUE(property);
	
			/** 
			 * The call parameter must be an array of arrays
			 */
			if (Z_TYPE_P(property) != IS_ARRAY) { 
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SV(exception_message, "Property must be an array on position ", property_position);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * A param 'name' is required
			 */
			if (!phalcon_array_isset_string(property, SS("name"))) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SV(exception_message, "The property name is required on position ", property_position);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
				return;
			}
	
			/** 
			 * A param 'value' is required
			 */
			if (!phalcon_array_isset_string(property, SS("value"))) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SV(exception_message, "The property value is required on position ", property_position);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
				return;
			}
	
			PHALCON_OBS_NVAR(property_name);
			phalcon_array_fetch_string(&property_name, property, SL("name"), PH_NOISY_CC);
	
			PHALCON_OBS_NVAR(property_value);
			phalcon_array_fetch_string(&property_value, property, SL("value"), PH_NOISY_CC);
	
			/** 
			 * Resolve the parameter
			 */
			PHALCON_INIT_NVAR(value);
			phalcon_call_method_p3(value, this_ptr, "_buildparameter", dependency_injector, property_position, property_value);
	
			/** 
			 * Update the public property
			 */
			phalcon_update_property_zval_zval(instance, property_name, value TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
	}
	
	RETURN_CTOR(instance);
}

