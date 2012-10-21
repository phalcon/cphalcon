
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
#include "kernel/file.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\DI
 *
 * Phalcon\DI is a component that implements Dependency Injection of services and
 * it's itself a container for them.
 *
 * Since Phalcon is highly decoupled, Phalcon\DI is essential to integrate the different
 * components of the framework. The developer can also use this component to inject dependencies
 * and manage global instances of the different classes used in the application.
 *
 * Basically, this component implements the `Inversion of Control` pattern. Applying this,
 * the objects do not receive their dependencies using setters or constructors, but requesting
 * a service dependency injector. This reduces the overall complexity, since there is only one
 * way to get the required dependencies within a component.
 *
 * Additionally, this pattern increases testability in the code, thus making it less prone to errors.
 */


/**
 * Phalcon\DI constructor
 *
 */
PHP_METHOD(Phalcon_DI, __construct){

	zval *default_di = NULL;
	zval *a0 = NULL, *a1 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_di_ce, this_ptr, SL("_services"), a0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_di_ce, this_ptr, SL("_sharedInstances"), a1 TSRMLS_CC);
	PHALCON_OBSERVE_VAR(default_di);
	phalcon_read_static_property(&default_di, SL("phalcon\\di"), SL("_default") TSRMLS_CC);
	if (!zend_is_true(default_di)) {
		phalcon_update_static_property(SL("phalcon\\di"), SL("_default"), this_ptr TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Registers a service in the services container
 *
 * @param string $alias
 * @param mixed $config
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_DI, set){

	zval *alias, *config;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &alias, &config) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_services"), PH_NOISY_CC);
	phalcon_array_update_zval(&t0, alias, &config, PH_COPY TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_services"), t0 TSRMLS_CC);
	
	RETURN_CTOR(this_ptr);
}

/**
 * Removes a service in the services container
 *
 * @param string $alias
 * @param mixed $config
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_DI, remove){

	zval *alias;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &alias) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(t0);
	phalcon_read_property(&t0, this_ptr, SL("_services"), PH_NOISY_CC);
	PHALCON_SEPARATE_NMO(t0);
	phalcon_array_unset(t0, alias);
	
	PHALCON_MM_RESTORE();
}

/**
 * Attempts to register a service in the services container
 * Only is successful if a services hasn't been registered previosly
 * with the same name
 *
 * @param string $alias
 * @param mixed $config
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_DI, attempt){

	zval *alias, *config, *services;
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
	
	
	RETURN_CTOR(this_ptr);
}

/**
 * Factories instances based on its config
 *
 * @param string $service
 * @param mixed $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, _factory){

	zval *service, *parameters, *found = NULL, *instance = NULL, *class_name;
	zval *exception_message;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &service, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(found);
	ZVAL_BOOL(found, 1);
	
	PHALCON_INIT_VAR(instance);
	if (Z_TYPE_P(service) == IS_STRING) {
		if (phalcon_class_exists(service TSRMLS_CC)) {
			if (Z_TYPE_P(parameters) == IS_ARRAY) { 
				if (phalcon_fast_count_ev(parameters TSRMLS_CC)) {
					if (phalcon_create_instance_params(instance, service, parameters TSRMLS_CC) == FAILURE) {
						return;
					}
				} else {
					PHALCON_INIT_NVAR(instance);
					if (phalcon_create_instance(instance, service TSRMLS_CC) == FAILURE) {
						return;
					}
				}
			} else {
				PHALCON_INIT_NVAR(instance);
				if (phalcon_create_instance(instance, service TSRMLS_CC) == FAILURE) {
					return;
				}
			}
		} else {
			if (phalcon_is_callable(service TSRMLS_CC)) {
				if (Z_TYPE_P(parameters) == IS_ARRAY) { 
					PHALCON_INIT_NVAR(instance);
					PHALCON_CALL_USER_FUNC_ARRAY(instance, service, parameters);
				} else {
					PHALCON_INIT_NVAR(instance);
					PHALCON_CALL_USER_FUNC(instance, service);
				}
			} else {
				ZVAL_BOOL(found, 0);
			}
		}
	} else {
		if (Z_TYPE_P(service) == IS_OBJECT) {
			if (phalcon_is_instance_of(service, SL("Closure") TSRMLS_CC)) {
				if (Z_TYPE_P(parameters) == IS_ARRAY) { 
					PHALCON_INIT_NVAR(instance);
					PHALCON_CALL_USER_FUNC_ARRAY(instance, service, parameters);
				} else {
					PHALCON_INIT_NVAR(instance);
					PHALCON_CALL_USER_FUNC(instance, service);
				}
			} else {
				PHALCON_CPY_WRT(instance, service);
			}
		} else {
			if (Z_TYPE_P(service) == IS_ARRAY) { 
				eval_int = phalcon_array_isset_string(service, SS("className"));
				if (!eval_int) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Invalid service definition. Missing 'className' parameter");
					return;
				}
				
				PHALCON_INIT_VAR(class_name);
				phalcon_array_fetch_string(&class_name, service, SL("className"), PH_NOISY_CC);
				if (Z_TYPE_P(parameters) == IS_ARRAY) { 
					if (phalcon_fast_count_ev(parameters TSRMLS_CC)) {
						PHALCON_INIT_NVAR(instance);
						if (phalcon_create_instance_params(instance, service, parameters TSRMLS_CC) == FAILURE) {
							return;
						}
					} else {
						PHALCON_INIT_NVAR(instance);
						if (phalcon_create_instance(instance, class_name TSRMLS_CC) == FAILURE) {
							return;
						}
					}
				} else {
					PHALCON_INIT_NVAR(instance);
					if (phalcon_create_instance(instance, class_name TSRMLS_CC) == FAILURE) {
						return;
					}
				}
				
				
				RETURN_CCTOR(instance);
			} else {
				ZVAL_BOOL(found, 0);
			}
		}
	}
	
	if (PHALCON_IS_FALSE(found)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Service '", service, "' wasn't found in the dependency injection container");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
		return;
	}
	
	
	RETURN_CCTOR(instance);
}

/**
 * Resolves the service based on its configuration
 *
 * @param string $alias
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, get){

	zval *alias, *parameters = NULL, *services, *service = NULL, *instance;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &alias, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
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
		if (phalcon_method_exists_ex(instance, SS("setdi") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(instance, "setdi", this_ptr, PH_NO_CHECK);
		}
	}
	
	
	RETURN_CCTOR(instance);
}

/**
 * Returns a shared service based on its configuration
 *
 * @param string $alias
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, getShared){

	zval *alias, *parameters = NULL, *shared_instances;
	zval *instance = NULL;
	zval *t0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &alias, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	PHALCON_INIT_VAR(shared_instances);
	phalcon_read_property(&shared_instances, this_ptr, SL("_sharedInstances"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(shared_instances, alias);
	if (eval_int) {
		PHALCON_INIT_VAR(instance);
		phalcon_array_fetch(&instance, shared_instances, alias, PH_NOISY_CC);
		phalcon_update_property_bool(this_ptr, SL("_freshInstance"), 0 TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(instance);
		PHALCON_CALL_METHOD_PARAMS_2(instance, this_ptr, "get", alias, parameters, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(t0);
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

	zval *alias, *services, *is_set_service = NULL;
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
	
	PHALCON_INIT_VAR(r0);
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

	zval *fresh_instance;

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

	zval *method, *arguments = NULL, *zero, *three, *action, *services;
	zval *service_name = NULL, *possible_service = NULL, *instance = NULL;
	zval *handler, *exception_message;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &method, &arguments) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!arguments) {
		PHALCON_INIT_NVAR(arguments);
		array_init(arguments);
	}
	
	PHALCON_INIT_VAR(zero);
	ZVAL_LONG(zero, 0);
	
	PHALCON_INIT_VAR(three);
	ZVAL_LONG(three, 3);
	
	PHALCON_INIT_VAR(action);
	PHALCON_CALL_FUNC_PARAMS_3(action, "substr", method, zero, three);
	if (PHALCON_COMPARE_STRING(action, "get")) {
		PHALCON_INIT_VAR(services);
		phalcon_read_property(&services, this_ptr, SL("_services"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(service_name);
		PHALCON_CALL_FUNC_PARAMS_2(service_name, "substr", method, three);
		
		PHALCON_INIT_VAR(possible_service);
		PHALCON_CALL_FUNC_PARAMS_1(possible_service, "lcfirst", service_name);
		eval_int = phalcon_array_isset(services, possible_service);
		if (eval_int) {
			if (phalcon_fast_count_ev(arguments TSRMLS_CC)) {
				PHALCON_INIT_VAR(instance);
				PHALCON_CALL_METHOD_PARAMS_2(instance, this_ptr, "get", possible_service, arguments, PH_NO_CHECK);
			} else {
				PHALCON_INIT_NVAR(instance);
				PHALCON_CALL_METHOD_PARAMS_1(instance, this_ptr, "get", possible_service, PH_NO_CHECK);
			}
			
			RETURN_CCTOR(instance);
		}
	} else {
		if (PHALCON_COMPARE_STRING(action, "set")) {
			eval_int = phalcon_array_isset_long(arguments, 0);
			if (eval_int) {
				PHALCON_INIT_NVAR(service_name);
				PHALCON_CALL_FUNC_PARAMS_2(service_name, "substr", method, three);
				
				PHALCON_INIT_NVAR(possible_service);
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
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
	return;
}

/**
 * Set a default dependency injection container to be obtained into static methods
 *
 * @param string $dependencyInjector
 */
PHP_METHOD(Phalcon_DI, setDefault){

	zval *dependency_injector;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_static_property(SL("phalcon\\di"), SL("_default"), dependency_injector TSRMLS_CC);
	
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

	zval *null_value;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(null_value);
	phalcon_update_static_property(SL("phalcon\\di"), SL("_default"), null_value TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

