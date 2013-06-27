
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/string.h"

/**
 * Phalcon\DI
 *
 * Phalcon\DI is a component that implements Dependency Injection/Service Location
 * of services and it's itself a container for them.
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
 *
 *<code>
 * $di = new Phalcon\DI();
 *
 * //Using a string definition
 * $di->set('request', 'Phalcon\Http\Request', true);
 *
 * //Using an anonymous function
 * $di->set('request', function(){
 *	  return new Phalcon\Http\Request();
 * }, true);
 *
 * $request = $di->getRequest();
 *
 *</code>
 */


/**
 * Phalcon\DI initializer
 */
PHALCON_INIT_CLASS(Phalcon_DI){

	PHALCON_REGISTER_CLASS(Phalcon, DI, di, phalcon_di_method_entry, 0);

	zend_declare_property_null(phalcon_di_ce, SL("_services"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_di_ce, SL("_sharedInstances"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_di_ce, SL("_freshInstance"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_di_ce, SL("_default"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(phalcon_di_ce TSRMLS_CC, 1, phalcon_diinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\DI constructor
 *
 */
PHP_METHOD(Phalcon_DI, __construct){

	zval *default_di;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(default_di);
	phalcon_read_static_property(&default_di, SL("phalcon\\di"), SL("_default") TSRMLS_CC);
	if (!zend_is_true(default_di)) {
		phalcon_update_static_property(SL("phalcon\\di"), SL("_default"), this_ptr TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Registers a service in the services container
 *
 * @param string $name
 * @param mixed $definition
 * @param boolean $shared
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_DI, set){

	zval *name, *definition, *shared = NULL, *service;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &name, &definition, &shared);
	
	if (!shared) {
		PHALCON_INIT_VAR(shared);
		ZVAL_BOOL(shared, 0);
	}
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	object_init_ex(service, phalcon_di_service_ce);
	phalcon_call_method_p3_noret(service, "__construct", name, definition, shared);
	
	phalcon_update_property_array(this_ptr, SL("_services"), name, service TSRMLS_CC);
	
	RETURN_CTOR(service);
}

/**
 * Registers an "always shared" service in the services container
 *
 * @param string $name
 * @param mixed $definition
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_DI, setShared){

	zval *name, *definition, *shared, *service;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &name, &definition);
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	
	PHALCON_INIT_VAR(shared);
	ZVAL_BOOL(shared, 1);
	
	PHALCON_INIT_VAR(service);
	object_init_ex(service, phalcon_di_service_ce);
	phalcon_call_method_p3_noret(service, "__construct", name, definition, shared);
	
	phalcon_update_property_array(this_ptr, SL("_services"), name, service TSRMLS_CC);
	
	RETURN_CTOR(service);
}

/**
 * Removes a service in the services container
 *
 * @param string $name
 */
PHP_METHOD(Phalcon_DI, remove){

	zval *name;

	phalcon_fetch_params(0, 1, 0, &name);
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	phalcon_unset_property_array(this_ptr, SL("_services"), name TSRMLS_CC);
	
}

/**
 * Attempts to register a service in the services container
 * Only is successful if a service hasn't been registered previously
 * with the same name
 *
 * @param string $name
 * @param mixed $definition
 * @param boolean $shared
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_DI, attempt){

	zval *name, *definition, *shared = NULL, *services, *service;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &name, &definition, &shared);
	
	if (!shared) {
		PHALCON_INIT_VAR(shared);
		ZVAL_BOOL(shared, 0);
	}
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	
	PHALCON_OBS_VAR(services);
	phalcon_read_property_this(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	if (!phalcon_array_isset(services, name)) {
		PHALCON_INIT_VAR(service);
		object_init_ex(service, phalcon_di_service_ce);
		phalcon_call_method_p3_noret(service, "__construct", name, definition, shared);
	
		phalcon_update_property_array(this_ptr, SL("_services"), name, service TSRMLS_CC);
		RETURN_CTOR(service);
	}
	
	RETURN_MM_NULL();
}

/**
 * Sets a service using a raw Phalcon\DI\Service definition
 *
 * @param string $name
 * @param Phalcon\DI\ServiceInterface $rawDefinition
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_DI, setRaw){

	zval *name, *raw_definition;

	phalcon_fetch_params(0, 2, 0, &name, &raw_definition);
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	if (Z_TYPE_P(raw_definition) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service definition must be an object");
		return;
	}
	
	phalcon_update_property_array(this_ptr, SL("_services"), name, raw_definition TSRMLS_CC);
	
	RETURN_CCTORW(raw_definition);
}

/**
 * Returns a service definition without resolving
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, getRaw){

	zval *name, *services, *service, *definition, *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	
	PHALCON_OBS_VAR(services);
	phalcon_read_property_this(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	if (phalcon_array_isset(services, name)) {
		PHALCON_OBS_VAR(service);
		phalcon_array_fetch(&service, services, name, PH_NOISY_CC);
	
		PHALCON_INIT_VAR(definition);
		phalcon_call_method(definition, service, "getdefinition");
		RETURN_CCTOR(definition);
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SVS(exception_message, "Service '", name, "' wasn't found in the dependency injection container");
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
	return;
}

/**
 * Returns a Phalcon\DI\Service instance
 *
 * @param string $name
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_DI, getService){

	zval *name, *services, *service, *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	
	PHALCON_OBS_VAR(services);
	phalcon_read_property_this(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	if (phalcon_array_isset(services, name)) {
		PHALCON_OBS_VAR(service);
		phalcon_array_fetch(&service, services, name, PH_NOISY_CC);
		RETURN_CCTOR(service);
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SVS(exception_message, "Service '", name, "' wasn't found in the dependency injection container");
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
	return;
}

/**
 * Resolves the service based on its configuration
 *
 * @param string $name
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, get){

	zval *name, *parameters = NULL, *services, *service, *instance = NULL;
	zval *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &name, &parameters);
	
	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	/** 
	 * A valid service alias is a string
	 */
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service alias must be a string");
		return;
	}
	
	PHALCON_OBS_VAR(services);
	phalcon_read_property_this(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	if (phalcon_array_isset(services, name)) {
		/** 
		 * The service is registered in the DI
		 */
		PHALCON_OBS_VAR(service);
		phalcon_array_fetch(&service, services, name, PH_NOISY_CC);
	
		PHALCON_INIT_VAR(instance);
		phalcon_call_method_p2(instance, service, "resolve", parameters, this_ptr);
	} else {
		/** 
		 * The DI also acts as builder for any class even if it isn't defined in the DI
		 */
		if (phalcon_class_exists(name TSRMLS_CC)) {
			if (Z_TYPE_P(parameters) == IS_ARRAY) { 
				if (phalcon_fast_count_ev(parameters TSRMLS_CC)) {
					PHALCON_INIT_NVAR(instance);
					if (phalcon_create_instance_params(instance, name, parameters TSRMLS_CC) == FAILURE) {
						return;
					}
				} else {
					PHALCON_INIT_NVAR(instance);
					if (phalcon_create_instance(instance, name TSRMLS_CC) == FAILURE) {
						return;
					}
				}
			} else {
				PHALCON_INIT_NVAR(instance);
				if (phalcon_create_instance(instance, name TSRMLS_CC) == FAILURE) {
					return;
				}
			}
		} else {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Service '", name, "' wasn't found in the dependency injection container");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
			return;
		}
	}
	
	/** 
	 * Pass the DI itself if the instance implements Phalcon\DI\InjectionAwareInterface
	 */
	if (Z_TYPE_P(instance) == IS_OBJECT) {
		if (phalcon_method_exists_ex(instance, SS("setdi") TSRMLS_CC) == SUCCESS) {
			phalcon_call_method_p1_noret(instance, "setdi", this_ptr);
		}
	}
	
	RETURN_CCTOR(instance);
}

/**
 * Resolves a service, the resolved service is stored in the DI, subsequent requests for this service will return the same instance
 *
 * @param string $name
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, getShared){

	zval *name, *parameters = NULL, *shared_instances, *instance = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &name, &parameters);
	
	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service alias must be a string");
		return;
	}
	
	/** 
	 * This method provides a first level to shared instances allowing to use
	 * non-shared services as shared
	 */
	PHALCON_OBS_VAR(shared_instances);
	phalcon_read_property_this(&shared_instances, this_ptr, SL("_sharedInstances"), PH_NOISY_CC);
	if (phalcon_array_isset(shared_instances, name)) {
		PHALCON_OBS_VAR(instance);
		phalcon_array_fetch(&instance, shared_instances, name, PH_NOISY_CC);
		phalcon_update_property_bool(this_ptr, SL("_freshInstance"), 0 TSRMLS_CC);
	} else {
		/** 
		 * Resolve the instance normally
		 */
		PHALCON_INIT_NVAR(instance);
		phalcon_call_method_p2(instance, this_ptr, "get", name, parameters);
	
		/** 
		 * Save the instance in the first level shared
		 */
		phalcon_update_property_array(this_ptr, SL("_sharedInstances"), name, instance TSRMLS_CC);
		phalcon_update_property_bool(this_ptr, SL("_freshInstance"), 1 TSRMLS_CC);
	}
	
	RETURN_CCTOR(instance);
}

/**
 * Check whether the DI contains a service by a name
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_DI, has){

	zval *name, *services, *is_set_service = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service alias must be a string");
		return;
	}
	
	PHALCON_OBS_VAR(services);
	phalcon_read_property_this(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, phalcon_array_isset(services, name));
	PHALCON_CPY_WRT(is_set_service, r0);
	
	RETURN_NCTOR(is_set_service);
}

/**
 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_DI, wasFreshInstance){


	RETURN_MEMBER(this_ptr, "_freshInstance");
}

/**
 * Return the services registered in the DI
 *
 * @return Phalcon\DI\Service[]
 */
PHP_METHOD(Phalcon_DI, getServices){


	RETURN_MEMBER(this_ptr, "_services");
}

/**
 * Check if a service is registered using the array syntax
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_DI, offsetExists){

	zval *name, *exists;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_INIT_VAR(exists);
	phalcon_call_method_p1(exists, this_ptr, "has", name);
	RETURN_CCTOR(exists);
}

/**
 * Allows to register a shared service using the array syntax
 *
 *<code>
 *	$di['request'] = new Phalcon\Http\Request();
 *</code>
 *
 * @param string $name
 * @param mixed $definition
 */
PHP_METHOD(Phalcon_DI, offsetSet){

	zval *name, *definition;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &name, &definition);
	
	phalcon_call_method_p2_noret(this_ptr, "setshared", name, definition);
	
	PHALCON_MM_RESTORE();
}

/**
 * Allows to obtain a shared service using the array syntax
 *
 *<code>
 *	var_dump($di['request']);
 *</code>
 *
 * @param string $name
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, offsetGet){

	zval *name, *service;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &name);
	
	PHALCON_INIT_VAR(service);
	phalcon_call_method_p1(service, this_ptr, "getshared", name);
	RETURN_CCTOR(service);
}

/**
 * Removes a service from the services container using the array syntax
 *
 * @param string $name
 */
PHP_METHOD(Phalcon_DI, offsetUnset){

	zval *name;

	phalcon_fetch_params(0, 1, 0, &name);
	
	RETURN_CCTORW(name);
}

/**
 * Magic method to get or set services using setters/getters
 *
 * @param string $method
 * @param array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, __call){

	zval *method, *arguments = NULL, *services, *service_name = NULL;
	zval *possible_service = NULL, *instance = NULL, *handler;
	zval *exception_message;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &method, &arguments);
	
	if (!arguments) {
		PHALCON_INIT_VAR(arguments);
	}
	
	/** 
	 * If the magic method starts with 'get' we try to get a service with that name
	 */
	if (phalcon_start_with_str(method, SL("get"))) {
	
		PHALCON_OBS_VAR(services);
		phalcon_read_property_this(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(service_name);
		phalcon_substr(service_name, method, 3, 0 TSRMLS_CC);
	
		PHALCON_INIT_VAR(possible_service);
		phalcon_call_func_p1(possible_service, "lcfirst", service_name);
		if (phalcon_array_isset(services, possible_service)) {
			if (phalcon_fast_count_ev(arguments TSRMLS_CC)) {
				PHALCON_INIT_VAR(instance);
				phalcon_call_method_p2(instance, this_ptr, "get", possible_service, arguments);
			} else {
				PHALCON_INIT_NVAR(instance);
				phalcon_call_method_p1(instance, this_ptr, "get", possible_service);
			}
	
			RETURN_CCTOR(instance);
		}
	}
	
	/** 
	 * If the magic method starts with 'set' we try to set a service using that name
	 */
	if (phalcon_start_with_str(method, SL("set"))) {
		if (phalcon_array_isset_long(arguments, 0)) {
			PHALCON_INIT_NVAR(service_name);
			phalcon_substr(service_name, method, 3, 0 TSRMLS_CC);
	
			PHALCON_INIT_NVAR(possible_service);
			phalcon_call_func_p1(possible_service, "lcfirst", service_name);
	
			PHALCON_OBS_VAR(handler);
			phalcon_array_fetch_long(&handler, arguments, 0, PH_NOISY_CC);
			phalcon_call_method_p2_noret(this_ptr, "set", possible_service, handler);
			RETURN_MM_NULL();
		}
	}
	
	/** 
	 * The method doesn't start with set/get throw an exception
	 */
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SVS(exception_message, "Call to undefined method or service '", method, "'");
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_di_exception_ce, exception_message);
	return;
}

/**
 * Set a default dependency injection container to be obtained into static methods
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_DI, setDefault){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	
	phalcon_update_static_property(SL("phalcon\\di"), SL("_default"), dependency_injector TSRMLS_CC);
	
}

/**
 * Return the lastest DI created
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_DI, getDefault){

	zval *default_di;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(default_di);
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

