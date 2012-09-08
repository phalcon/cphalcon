
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
  |          Nikolaos Dimopoulos <nikos@niden.net>                         |
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

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon_DI
 *
 */

PHP_METHOD(Phalcon_DI, __construct){

	zval *default_di = NULL;
	zval *a0 = NULL, *a1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_di_ce, this_ptr, SL("_services"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a1);
	array_init(a1);
	zend_update_property(phalcon_di_ce, this_ptr, SL("_sharedInstances"), a1 TSRMLS_CC);
	PHALCON_OBSERVE_VAR(default_di);
	phalcon_read_static_property(&default_di, SL("phalcon\\di"), SL("_default") TSRMLS_CC);
	if (!zend_is_true(default_di)) {
		phalcon_update_static_property(SL("phalcon\\di"), SL("_default"), this_ptr TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_DI, set){

	zval *alias = NULL, *config = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &alias, &config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_services"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, alias, &config, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_services"), t0 TSRMLS_CC);
	
	RETURN_CCTOR(this_ptr);
}

PHP_METHOD(Phalcon_DI, remove){

	zval *alias = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &alias) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_services"), PH_NOISY_CC);
	PHALCON_SEPARATE_NMO(t0);
	phalcon_array_unset(t0, alias);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_DI, attempt){

	zval *alias = NULL, *config = NULL, *services = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &alias, &config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(services);
	phalcon_read_property(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(services, alias);
	if (!eval_int) {
		phalcon_array_update_zval(&services, alias, &config, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_services"), services TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(this_ptr);
}

PHP_METHOD(Phalcon_DI, _factory){

	zval *service = NULL, *parameters = NULL, *found = NULL, *instance = NULL, *class_exists = NULL;
	zval *reflection = NULL, *parameter_count = NULL, *is_callable = NULL;
	zval *class_name = NULL, *exception_message = NULL, *exception = NULL;
	int eval_int;
	zend_class_entry *ce0, *ce1, *ce2;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &service, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(found);
	ZVAL_BOOL(found, 1);
	
	PHALCON_INIT_VAR(instance);
	ZVAL_NULL(instance);
	if (Z_TYPE_P(service) == IS_STRING) {
		PHALCON_INIT_VAR(class_exists);
		PHALCON_CALL_FUNC_PARAMS_1(class_exists, "class_exists", service);
		if (zend_is_true(class_exists)) {
			ce0 = zend_fetch_class(SL("ReflectionClass"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			PHALCON_INIT_VAR(reflection);
			object_init_ex(reflection, ce0);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(reflection, "__construct", service, PH_CHECK);
			
			PHALCON_INIT_VAR(parameter_count);
			phalcon_fast_count(parameter_count, parameters TSRMLS_CC);
			if (zend_is_true(parameter_count)) {
				PHALCON_INIT_VAR(instance);
				PHALCON_CALL_METHOD_PARAMS_1(instance, reflection, "newinstanceargs", parameters, PH_NO_CHECK);
			} else {
				PHALCON_INIT_VAR(instance);
				PHALCON_CALL_METHOD(instance, reflection, "newinstance", PH_NO_CHECK);
			}
		} else {
			PHALCON_INIT_VAR(is_callable);
			PHALCON_CALL_FUNC_PARAMS_1(is_callable, "is_callable", service);
			if (zend_is_true(is_callable)) {
				PHALCON_INIT_VAR(instance);
				PHALCON_CALL_FUNC_PARAMS_2(instance, "call_user_func_array", service, parameters);
			} else {
				PHALCON_INIT_VAR(found);
				ZVAL_BOOL(found, 0);
			}
		}
	} else {
		if (Z_TYPE_P(service) == IS_ARRAY) { 
			eval_int = phalcon_array_isset_string(service, SL("className")+1);
			if (!eval_int) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Invalid service definition. Missing 'className' parameter");
				return;
			}
			
			PHALCON_INIT_VAR(class_name);
			phalcon_array_fetch_string(&class_name, service, SL("className"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(parameter_count);
			phalcon_fast_count(parameter_count, parameters TSRMLS_CC);
			if (zend_is_true(parameter_count)) {
				ce1 = zend_fetch_class(SL("ReflectionClass"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
				PHALCON_INIT_VAR(reflection);
				object_init_ex(reflection, ce1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(reflection, "__construct", class_name, PH_CHECK);
				
				PHALCON_INIT_VAR(instance);
				PHALCON_CALL_METHOD_PARAMS_1(instance, reflection, "newinstanceargs", parameters, PH_NO_CHECK);
			} else {
				ce2 = phalcon_fetch_class(class_name TSRMLS_CC);
				PHALCON_INIT_VAR(instance);
				object_init_ex(instance, ce2);
				PHALCON_CALL_METHOD_NORETURN(instance, "__construct", PH_CHECK);
			}
			
			
			RETURN_CCTOR(instance);
		} else {
			if (Z_TYPE_P(service) == IS_OBJECT) {
				PHALCON_INIT_VAR(class_name);
				phalcon_get_class(class_name, service TSRMLS_CC);
				if (PHALCON_COMPARE_STRING(class_name, "Closure")) {
					PHALCON_INIT_VAR(instance);
					PHALCON_CALL_FUNC_PARAMS_2(instance, "call_user_func_array", service, parameters);
				} else {
					PHALCON_CPY_WRT(instance, service);
				}
			} else {
				PHALCON_INIT_VAR(found);
				ZVAL_BOOL(found, 0);
			}
		}
	}
	
	if (!zend_is_true(found)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Service '", service, "' wasn't found in the dependency injection container");
		
		PHALCON_INIT_VAR(exception);
		object_init_ex(exception, phalcon_di_exception_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
		phalcon_throw_exception(exception TSRMLS_CC);
		return;
	}
	
	
	RETURN_CCTOR(instance);
}

PHP_METHOD(Phalcon_DI, get){

	zval *alias = NULL, *parameters = NULL, *services = NULL, *service = NULL, *instance = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &alias, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
		array_init(parameters);
	}
	
	PHALCON_INIT_VAR(services);
	phalcon_read_property(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(services, alias);
	if (eval_int) {
		PHALCON_INIT_VAR(service);
		phalcon_array_fetch(&service, services, alias, PH_NOISY_CC);
	} else {
		PHALCON_CPY_WRT(service, alias);
	}
	
	PHALCON_INIT_VAR(instance);
	PHALCON_CALL_METHOD_PARAMS_2(instance, this_ptr, "_factory", service, parameters, PH_NO_CHECK);
	if (Z_TYPE_P(instance) == IS_OBJECT) {
		if (phalcon_method_exists_ex(instance, SL("setdi") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(instance, "setdi", this_ptr, PH_NO_CHECK);
		}
	}
	
	
	RETURN_CCTOR(instance);
}

PHP_METHOD(Phalcon_DI, getShared){

	zval *alias = NULL, *parameters = NULL, *shared_instances = NULL;
	zval *instance = NULL;
	zval *t0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &alias, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
		array_init(parameters);
	}
	
	PHALCON_INIT_VAR(shared_instances);
	phalcon_read_property(&shared_instances, this_ptr, SL("_sharedInstances"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(shared_instances, alias);
	if (eval_int) {
		PHALCON_INIT_VAR(instance);
		phalcon_array_fetch(&instance, shared_instances, alias, PH_NOISY_CC);
		phalcon_update_property_bool(this_ptr, SL("_freshInstance"), 0 TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(instance);
		PHALCON_CALL_METHOD_PARAMS_2(instance, this_ptr, "get", alias, parameters, PH_NO_CHECK);
		
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_sharedInstances"), PH_NOISY_CC);
		phalcon_array_update_zval(&t0, alias, &instance, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_sharedInstances"), t0 TSRMLS_CC);
		phalcon_update_property_bool(this_ptr, SL("_freshInstance"), 1 TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(instance);
}

/**
 * Check whether the DI contains a service by a name
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_DI, has){

	zval *alias = NULL, *services = NULL, *is_set_service = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &alias) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(services);
	phalcon_read_property(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(services, alias);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	ZVAL_BOOL(r0, eval_int);
	PHALCON_CPY_WRT(is_set_service, r0);
	
	RETURN_NCTOR(is_set_service);
}

/**
 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_DI, wasFreshInstance){

	zval *fresh_instance = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(fresh_instance);
	phalcon_read_property(&fresh_instance, this_ptr, SL("_freshInstance"), PH_NOISY_CC);
	
	RETURN_CCTOR(fresh_instance);
}

/**
 * Magic method to get or set services using setters/getters
 *
 * @param string $method
 * @param array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, __call){

	zval *method = NULL, *arguments = NULL, *action = NULL, *services = NULL, *service_name = NULL;
	zval *possible_service = NULL, *number_arguments = NULL;
	zval *instance = NULL, *handler = NULL, *exception_message = NULL;
	zval *exception = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &method, &arguments) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!arguments) {
		PHALCON_INIT_VAR(arguments);
		array_init(arguments);
	}
	
	PHALCON_INIT_VAR(c0);
	ZVAL_LONG(c0, 0);
	PHALCON_INIT_VAR(c1);
	ZVAL_LONG(c1, 3);
	PHALCON_INIT_VAR(action);
	PHALCON_CALL_FUNC_PARAMS_3(action, "substr", method, c0, c1);
	if (PHALCON_COMPARE_STRING(action, "get")) {
		PHALCON_INIT_VAR(services);
		phalcon_read_property(&services, this_ptr, SL("_services"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(c2);
		ZVAL_LONG(c2, 3);
		
		PHALCON_INIT_VAR(service_name);
		PHALCON_CALL_FUNC_PARAMS_2(service_name, "substr", method, c2);
		
		PHALCON_INIT_VAR(possible_service);
		PHALCON_CALL_FUNC_PARAMS_1(possible_service, "lcfirst", service_name);
		eval_int = phalcon_array_isset(services, possible_service);
		if (eval_int) {
			PHALCON_INIT_VAR(number_arguments);
			phalcon_fast_count(number_arguments, arguments TSRMLS_CC);
			if (zend_is_true(number_arguments)) {
				PHALCON_INIT_VAR(instance);
				PHALCON_CALL_METHOD_PARAMS_2(instance, this_ptr, "get", possible_service, arguments, PH_NO_CHECK);
			} else {
				PHALCON_INIT_VAR(instance);
				PHALCON_CALL_METHOD_PARAMS_1(instance, this_ptr, "get", possible_service, PH_NO_CHECK);
			}
			
			
			RETURN_CCTOR(instance);
		}
	} else {
		if (PHALCON_COMPARE_STRING(action, "set")) {
			eval_int = phalcon_array_isset_long(arguments, 0);
			if (eval_int) {
				PHALCON_INIT_VAR(c3);
				ZVAL_LONG(c3, 3);
				PHALCON_INIT_VAR(service_name);
				PHALCON_CALL_FUNC_PARAMS_2(service_name, "substr", method, c3);
				
				PHALCON_INIT_VAR(possible_service);
				PHALCON_CALL_FUNC_PARAMS_1(possible_service, "lcfirst", service_name);
				
				PHALCON_INIT_VAR(handler);
				phalcon_array_fetch_long(&handler, arguments, 0, PH_NOISY_CC);
				PHALCON_CALL_METHOD_PARAMS_2_NORETURN(this_ptr, "set", possible_service, handler, PH_NO_CHECK);
				PHALCON_MM_RESTORE();
				RETURN_NULL();
			}
		}
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SVS(exception_message, "Call to undefined method or service '", method, "'");
	
	PHALCON_INIT_VAR(exception);
	object_init_ex(exception, phalcon_di_exception_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
	phalcon_throw_exception(exception TSRMLS_CC);
	return;
}

PHP_METHOD(Phalcon_DI, setDefault){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_static_property(SL("phalcon\\di"), SL("_default"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Return the last DI created
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_DI, getDefault){

	zval *default_di = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(default_di);
	phalcon_read_static_property(&default_di, SL("phalcon\\di"), SL("_default") TSRMLS_CC);
	
	RETURN_CCTOR(default_di);
}

/**
 * Resets the internal default DI
 */
PHP_METHOD(Phalcon_DI, reset){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_NULL(t0);
	phalcon_update_static_property(SL("phalcon\\di"), SL("_default"), t0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

