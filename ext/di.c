
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
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"


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
/**
 * Phalcon\Di
 *
 * Phalcon\Di is a component that implements Dependency Injection/Service Location
 * of services and it"s itself a container for them.
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
 * $di->set("request", "Phalcon\Http\Request", true);
 *
 * //Using an anonymous function
 * $di->set("request", function(){
 *	  return new Phalcon\Http\Request();
 * }, true);
 *
 * $request = $di->getRequest();
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Di) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Di, di, phalcon_di_method_entry, 0);

	zend_declare_property_null(phalcon_di_ce, SL("_services"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_di_ce, SL("_sharedInstances"), ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_di_ce, SL("_freshInstance"), 0, ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_null(phalcon_di_ce, SL("_default"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\DI constructor
 *
 */
PHP_METHOD(Phalcon_Di, __construct) {

	zval defaultDi;


	ZEPHIR_SINIT_VAR(defaultDi);
	ZVAL_NULL(&defaultDi);
	if (!(zend_is_true(&defaultDi))) {
	}

}

/**
 * Registers a service in the services container
 *
 * @param string name
 * @param mixed definition
 * @param boolean shared
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_Di, set) {

	zval *name, *definition, *shared = NULL, *service;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name, &definition, &shared);

	if (!shared) {
		ZEPHIR_INIT_VAR(shared);
		ZVAL_BOOLshared, 0);
	}


	if (Z_TYPE_P(name) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	ZEPHIR_INIT_VAR(service);
	object_init_ex(service, phalcon_di_service_ce);
	zephir_call_method_p3_noret(service, "__construct", name, definition, shared);
	zephir_update_property_array(this_ptr, SL("_services"), name, service TSRMLS_CC);
	RETURN_CCTOR(service);

}

/**
 * Registers an "always shared" service in the services container
 *
 * @param string name
 * @param mixed definition
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_Di, setShared) {

	zval *name, *definition, *service, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &definition);



	if (Z_TYPE_P(name) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	ZEPHIR_INIT_VAR(service);
	object_init_ex(service, phalcon_di_service_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_BOOL(_0, 1);
	zephir_call_method_p3_noret(service, "__construct", name, definition, _0);
	zephir_update_property_array(this_ptr, SL("_services"), name, service TSRMLS_CC);
	RETURN_CCTOR(service);

}

/**
 * Removes a service in the services container
 *
 * @param string name
 */
PHP_METHOD(Phalcon_Di, remove) {

	zval *name;

	zephir_fetch_params(0, 1, 0, &name);



	if (Z_TYPE_P(name) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}

}

/**
 * Attempts to register a service in the services container
 * Only is successful if a service hasn"t been registered previously
 * with the same name
 *
 * @param string name
 * @param mixed definition
 * @param boolean shared
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_Di, attempt) {

	zval *name, *definition, *shared = NULL, *services, *service;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name, &definition, &shared);

	if (!shared) {
		ZEPHIR_INIT_VAR(shared);
		ZVAL_BOOLshared, 0);
	}


	if (Z_TYPE_P(name) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	ZEPHIR_OBS_VAR(services);
	zephir_read_property_this(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	if (!(zephir_array_isset(services, name))) {
		ZEPHIR_INIT_VAR(service);
		object_init_ex(service, phalcon_di_service_ce);
		zephir_call_method_p3_noret(service, "__construct", name, definition, shared);
		zephir_update_property_array(this_ptr, SL("_services"), name, service TSRMLS_CC);
		RETURN_CCTOR(service);
	}
	RETURN_MM_NULL();

}

/**
 * Sets a service using a raw Phalcon\DI\Service definition
 *
 * @param string name
 * @param Phalcon\DI\ServiceInterface rawDefinition
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_Di, setRaw) {

	zval *name, *rawDefinition;

	zephir_fetch_params(0, 2, 0, &name, &rawDefinition);



	if (Z_TYPE_P(name) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	if (Z_TYPE_P(rawDefinition) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "The service definition must be an object");
		return;
	}
	zephir_update_property_array(this_ptr, SL("_services"), name, rawDefinition TSRMLS_CC);
	RETURN_CCTORW(rawDefinition);

}

/**
 * Returns a service definition without resolving
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Phalcon_Di, getRaw) {

	zval *name, *services, *service, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	if (Z_TYPE_P(name) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	ZEPHIR_OBS_VAR(services);
	zephir_read_property_this(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	if (zephir_array_isset(services, name)) {
		ZEPHIR_OBS_VAR(service);
		zephir_array_fetch(&service, services, name, PH_NOISY);
		zephir_call_method(return_value, service, "getdefinition");
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_di_exception_ce);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "Service '", name);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, _1, "' wasn't found in the dependency injection container");
	zephir_call_method_p1_noret(_0, "__construct", _2);
	zephir_throw_exception(_0 TSRMLS_CC);
	return;

}

/**
 * Returns a Phalcon\DI\Service instance
 *
 * @param string name
 * @return Phalcon\DI\ServiceInterface
 */
PHP_METHOD(Phalcon_Di, getService) {

	zval *name, *services, *service, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	if (Z_TYPE_P(name) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	ZEPHIR_OBS_VAR(services);
	zephir_read_property_this(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(service);
	if (zephir_array_isset_fetch(&service, services, name)) {
		RETURN_CCTOR(service);
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, phalcon_di_exception_ce);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "Service '", name);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, _1, "' wasn't found in the dependency injection container");
	zephir_call_method_p1_noret(_0, "__construct", _2);
	zephir_throw_exception(_0 TSRMLS_CC);
	return;

}

/**
 * Resolves the service based on its configuration
 *
 * @param string name
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Di, get) {

	zval *name, *parameters = NULL, *services, service, *instance = NULL, *_0 = NULL, *_1, *_2, *_3, _4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &parameters);

	if (!parameters) {
		ZEPHIR_INIT_VAR(parameters);
	}


	if (Z_TYPE_P(name) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	ZEPHIR_OBS_VAR(services);
	zephir_read_property_this(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(service);
	if (zephir_array_isset_fetch(&service, services, name)) {
		ZEPHIR_INIT_VAR(instance);
		zephir_call_method_p2(instance, service, "resolve", parameters, this_ptr);
	} else {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_func_p1(_0, "class_exists", name);
		if (zend_is_true(_0)) {
			if (Z_TYPE_P(parameters) == IS_STRING) {
				ZEPHIR_INIT_NVAR(instance);
				if (zephir_fast_count_int(parameters TSRMLS_CC)) {
					zephir_call_func_p2(instance, "create_instance_params", name, parameters);
				} else {
					zephir_call_func_p1(instance, "create_instance", name);
				}
			} else {
				ZEPHIR_INIT_NVAR(instance);
				zephir_call_func_p1(instance, "create_instance", name);
			}
		} else {
			ZEPHIR_INIT_VAR(_1);
			object_init_ex(_1, phalcon_di_exception_ce);
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_CONCAT_SV(_2, "Service '", name);
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_CONCAT_VS(_3, _2, "' wasn't found in the dependency injection container");
			zephir_call_method_p1_noret(_1, "__construct", _3);
			zephir_throw_exception(_1 TSRMLS_CC);
			return;
		}
	}
	if (Z_TYPE_P(instance) == IS_OBJECT) {
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "setDI", 0);
		ZEPHIR_INIT_NVAR(_0);
		zephir_call_func_p2(_0, "method_exists", instance, &_4);
		if (zend_is_true(_0)) {
			zephir_call_method_p1_noret(instance, "setdi", this_ptr);
		}
	}
	RETURN_CCTOR(instance);

}

/**
 * Resolves a service, the resolved service is stored in the DI, subsequent requests for this service will return the same instance
 *
 * @param string name
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Di, getShared) {

	zval *name, *parameters = NULL, *instance, *sharedInstances, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &parameters);

	if (!parameters) {
		ZEPHIR_INIT_VAR(parameters);
	}


	if (Z_TYPE_P(name) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	ZEPHIR_OBS_VAR(sharedInstances);
	zephir_read_property_this(&sharedInstances, this_ptr, SL("_sharedInstances"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(instance);
	if (!(zephir_array_isset_fetch(&instance, sharedInstances, name))) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_BOOL(_0, 0);
		zephir_update_property_this(this_ptr, SL("_freshInstance"), _0 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_BNVAR(instance);
		zephir_call_method_p2(instance, this_ptr, "get", name, parameters);
		zephir_update_property_array(this_ptr, SL("_sharedInstances"), name, instance TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_BOOL(_0, 1);
		zephir_update_property_this(this_ptr, SL("_freshInstance"), _0 TSRMLS_CC);
	}
	RETURN_CCTOR(instance);

}

/**
 * Check whether the DI contains a service by a name
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Phalcon_Di, has) {

	zval *name, *services;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	if (Z_TYPE_P(name) != IS_STRING) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "The service name must be a string");
		return;
	}
	ZEPHIR_OBS_VAR(services);
	zephir_read_property_this(&services, this_ptr, SL("_services"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(services, name));

}

/**
 * Check whether the last service obtained via getShared produced a fresh instance or an existing one
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Di, wasFreshInstance) {


	RETURN_MEMBER(this_ptr, "_freshInstance");

}

/**
 * Return the services registered in the DI
 *
 * @return Phalcon\DI\Service[]
 */
PHP_METHOD(Phalcon_Di, getServices) {


	RETURN_MEMBER(this_ptr, "_services");

}

/**
 * Check if a service is registered using the array syntax
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Phalcon_Di, offsetExists) {

	zval *name;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	zephir_call_method_p1(return_value, this_ptr, "has", name);
	RETURN_MM();

}

/**
 * Allows to register a shared service using the array syntax
 *
 *<code>
 *	$di["request"] = new Phalcon\Http\Request();
 *</code>
 *
 * @param string name
 * @param mixed definition
 */
PHP_METHOD(Phalcon_Di, offsetSet) {

	zval *name, *definition;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &definition);



	zephir_call_method_p2_noret(this_ptr, "setshared", name, definition);
	ZEPHIR_MM_RESTORE();

}

/**
 * Allows to obtain a shared service using the array syntax
 *
 *<code>
 *	var_dump($di["request"]);
 *</code>
 *
 * @param string name
 * @return mixed
 */
PHP_METHOD(Phalcon_Di, offsetGet) {

	zval *name;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);



	zephir_call_method_p1(return_value, this_ptr, "getshared", name);
	RETURN_MM();

}

/**
 * Removes a service from the services container using the array syntax
 *
 * @param string name
 */
PHP_METHOD(Phalcon_Di, offsetUnset) {

	zval *name;

	zephir_fetch_params(0, 1, 0, &name);



	RETURN_CCTORW(name);

}

/**
 * Magic method to get or set services using setters/getters
 *
 * @param string method
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Di, __call) {

	zval *method, *arguments = NULL, *instance, *possibleService, *services, _0 = zval_used_for_init, *_1 = NULL, *_2, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method, &arguments);

	if (!arguments) {
		ZEPHIR_INIT_VAR(arguments);
	}


	if (zephir_start_with_str(method, SL("get"))) {
		ZEPHIR_OBS_VAR(services);
		zephir_read_property_this(&services, this_ptr, SL("_services"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 3);
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func_p2(_1, "substr", method, &_0);
		ZEPHIR_INIT_VAR(possibleService);
		zephir_call_func_p1(possibleService, "lcfirst", _1);
		if (zephir_array_isset(services, possibleService)) {
			ZEPHIR_INIT_VAR(instance);
			if (zephir_fast_count_int(arguments TSRMLS_CC)) {
				zephir_call_method_p2(instance, this_ptr, "get", possibleService, arguments);
			} else {
				zephir_call_method_p1(instance, this_ptr, "get", possibleService);
			}
			RETURN_CCTOR(instance);
		}
	}
	if (zephir_start_with_str(method, SL("set"))) {
		if (zephir_array_isset_long(arguments, 0)) {
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 3);
			ZEPHIR_INIT_NVAR(_1);
			zephir_call_func_p2(_1, "substr", method, &_0);
			ZEPHIR_INIT_VAR(_2);
			zephir_call_func_p1(_2, "lcfirst", _1);
			ZEPHIR_OBS_VAR(_3);
			zephir_array_fetch_long(&_3, arguments, 0, PH_NOISY);
			zephir_call_method_p2_noret(this_ptr, "set", _2, _3);
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_INIT_NVAR(_1);
	object_init_ex(_1, phalcon_di_exception_ce);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "Call to undefined method or service '", method);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VS(_5, _4, "'");
	zephir_call_method_p1_noret(_1, "__construct", _5);
	zephir_throw_exception(_1 TSRMLS_CC);
	return;

}

/**
 * Set a default dependency injection container to be obtained into static methods
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Di, setDefault) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);




}

/**
 * Return the lastest DI created
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Di, getDefault) {


	RETURN_NULL();

}

/**
 * Resets the internal default DI
 */
PHP_METHOD(Phalcon_Di, reset) {



}

