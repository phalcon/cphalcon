
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

	default_di = phalcon_fetch_static_property_ce(phalcon_di_ce, SL("_default") TSRMLS_CC);
	if (!zend_is_true(default_di)) {
		phalcon_update_static_property(SL("phalcon\\di"), SL("_default"), this_ptr TSRMLS_CC);
	}
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

	zval *name, *definition, *shared = NULL;

	phalcon_fetch_params(0, 2, 1, &name, &definition, &shared);
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	
	PHALCON_MM_GROW();

	if (!shared) {
		PHALCON_INIT_VAR(shared);
		ZVAL_FALSE(shared);
	}

	object_init_ex(return_value, phalcon_di_service_ce);
	phalcon_call_method_p3_noret(return_value, "__construct", name, definition, shared);
	
	phalcon_update_property_array(this_ptr, SL("_services"), name, return_value TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Registers an "always shared" service in the services container
 *
 * @param string $name
 * @param mixed $definition
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_DI, setShared){

	zval *name, *definition, *shared;

	phalcon_fetch_params(0, 2, 0, &name, &definition);
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	
	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(shared);
	ZVAL_TRUE(shared);
	
	object_init_ex(return_value, phalcon_di_service_ce);
	phalcon_call_method_p3_noret(return_value, "__construct", name, definition, shared);
	
	phalcon_update_property_array(this_ptr, SL("_services"), name, return_value TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
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
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "The service name must be a string");
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

	zval *name, *definition, *shared = NULL, *services;

	phalcon_fetch_params(0, 2, 1, &name, &definition, &shared);
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	
	services = phalcon_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
	if (!phalcon_array_isset(services, name)) {
		PHALCON_MM_GROW();

		if (!shared) {
			PHALCON_INIT_VAR(shared);
			ZVAL_FALSE(shared);
		}

		object_init_ex(return_value, phalcon_di_service_ce);
		phalcon_call_method_p3_noret(return_value, "__construct", name, definition, shared);
	
		phalcon_update_property_array(this_ptr, SL("_services"), name, return_value TSRMLS_CC);
		PHALCON_MM_RESTORE();
	}
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
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	if (Z_TYPE_P(raw_definition) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "The service definition must be an object");
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

	zval *name, *exception_message;
	zval *services, *service;

	phalcon_fetch_params(0, 1, 0, &name);

	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}

	PHALCON_MM_GROW();

	services = phalcon_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
	if (phalcon_array_isset_fetch(&service, services, name)) {
		phalcon_call_method_p0_ex(return_value, return_value_ptr, service, "getdefinition");
		RETURN_MM();
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

	zval *name, *exception_message;
	zval *services, *service;

	phalcon_fetch_params(0, 1, 0, &name);
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	
	services = phalcon_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
	if (phalcon_array_isset_fetch(&service, services, name)) {
		RETURN_CTORW(service);
	}
	
	PHALCON_MM_GROW();
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

	zval *name, *parameters = NULL, *instance;
	zval *exception_message;
	zval *services, *service;

	phalcon_fetch_params(0, 1, 1, &name, &parameters);
	
	/** 
	 * A valid service alias is a string
	 */
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "The service alias must be a string");
		return;
	}
	
	PHALCON_MM_GROW();

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}

	PHALCON_INIT_VAR(instance);

	services = phalcon_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
	if (phalcon_array_isset_fetch(&service, services, name)) {
		/** 
		 * The service is registered in the DI
		 */
		phalcon_call_method_p2(instance, service, "resolve", parameters, this_ptr);
	} else {
		/** 
		 * The DI also acts as builder for any class even if it isn't defined in the DI
		 */
		if (phalcon_class_exists(name, 1 TSRMLS_CC)) {
			int res;
			if (Z_TYPE_P(parameters) == IS_ARRAY) { 
				res = phalcon_create_instance_params(instance, name, parameters TSRMLS_CC);
			} else {
				res = phalcon_create_instance(instance, name TSRMLS_CC);
			}

			if (res == FAILURE) {
				RETURN_MM();
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

	zval *name, *parameters = NULL;
	zval *shared_instances, *instance;

	phalcon_fetch_params(0, 1, 1, &name, &parameters);
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "The service alias must be a string");
		return;
	}
	
	/** 
	 * This method provides a first level to shared instances allowing to use
	 * non-shared services as shared
	 */
	shared_instances = phalcon_fetch_nproperty_this(this_ptr, SL("_sharedInstances"), PH_NOISY_CC);
	if (phalcon_array_isset_fetch(&instance, shared_instances, name)) {
		phalcon_update_property_bool(this_ptr, SL("_freshInstance"), 0 TSRMLS_CC);
		RETURN_CTORW(instance);
	}
	
	PHALCON_MM_GROW();

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}

	/**
	 * Resolve the instance normally
	 */
	phalcon_call_method_p2(return_value, this_ptr, "get", name, parameters);

	/**
	 * Save the instance in the first level shared
	 */
	phalcon_update_property_array(this_ptr, SL("_sharedInstances"), name, return_value TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_freshInstance"), 1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
}

/**
 * Check whether the DI contains a service by a name
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_DI, has){

	zval *name;
	zval *services;

	phalcon_fetch_params(0, 1, 0, &name);
	
	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "The service alias must be a string");
		return;
	}
	
	services = phalcon_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
	RETURN_BOOL(phalcon_array_isset(services, name));
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
 * Check if a service is registered using the array syntax.
 * Alias for Phalcon\Di::has()
 *
 * @param string $name
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_DI, offsetExists);

/**
 * Allows to register a shared service using the array syntax.
 * Alias for Phalcon\Di::setShared()
 *
 *<code>
 *	$di['request'] = new Phalcon\Http\Request();
 *</code>
 *
 * @param string $name
 * @param mixed $definition
 */
PHALCON_DOC_METHOD(Phalcon_DI, offsetSet);

/**
 * Allows to obtain a shared service using the array syntax.
 * Alias for Phalcon\Di::getShared()
 *
 *<code>
 *	var_dump($di['request']);
 *</code>
 *
 * @param string $name
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_DI, offsetGet);

/**
 * Removes a service from the services container using the array syntax.
 * Alias for Phalcon\Di::remove()
 *
 * @param string $name
 */
PHALCON_DOC_METHOD(Phalcon_DI, offsetUnset);

/**
 * Magic method to get or set services using setters/getters
 *
 * @param string $method
 * @param array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_DI, __call){

	zval *method, *arguments = NULL, *service_name = NULL;
	zval *exception_message;
	zval *services, *handler;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &method, &arguments);
	
	if (!arguments) {
		PHALCON_INIT_VAR(arguments);
	}
	
	/** 
	 * If the magic method starts with 'get' we try to get a service with that name
	 */
	if (phalcon_start_with_str(method, SL("get"))) {
	
		services = phalcon_fetch_nproperty_this(this_ptr, SL("_services"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(service_name);
		phalcon_substr(service_name, method, 3, 0);
		if (likely(Z_STRLEN_P(service_name) > 0)) {
			Z_STRVAL_P(service_name)[0] = tolower(Z_STRVAL_P(service_name)[0]);
		}
	
		if (phalcon_array_isset(services, service_name)) {
			if (phalcon_fast_count_ev(arguments TSRMLS_CC)) {
				phalcon_call_method_p2(return_value, this_ptr, "get", service_name, arguments);
			}
			else {
				phalcon_call_method_p1(return_value, this_ptr, "get", service_name);
			}

			RETURN_MM();
		}
	}
	
	/** 
	 * If the magic method starts with 'set' we try to set a service using that name
	 */
	if (phalcon_start_with_str(method, SL("set"))) {
		if (phalcon_array_isset_long_fetch(&handler, arguments, 0)) {
			PHALCON_INIT_NVAR(service_name);
			phalcon_substr(service_name, method, 3, 0);
	
			if (likely(Z_STRLEN_P(service_name) > 0)) {
				Z_STRVAL_P(service_name)[0] = tolower(Z_STRVAL_P(service_name)[0]);
			}

			phalcon_call_method_p2_noret(this_ptr, "set", service_name, handler);
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

	default_di = phalcon_fetch_static_property_ce(phalcon_di_ce, SL("_default") TSRMLS_CC);
	RETURN_CTORW(default_di);
}

/**
 * Resets the internal default DI
 */
PHP_METHOD(Phalcon_DI, reset){

	zval *null_value;

	ALLOC_INIT_ZVAL(null_value);
	phalcon_update_static_property(SL("phalcon\\di"), SL("_default"), null_value TSRMLS_CC);
	zval_ptr_dtor(&null_value);
}

