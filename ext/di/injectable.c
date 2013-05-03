
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"

/**
 * Phalcon\DI\Injectable
 *
 * This class allows to access services in the services container by just only accessing a public property
 * with the same name of a registered service
 */


/**
 * Phalcon\DI\Injectable initializer
 */
PHALCON_INIT_CLASS(Phalcon_DI_Injectable){

	PHALCON_REGISTER_CLASS(Phalcon\\DI, Injectable, di_injectable, phalcon_di_injectable_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_di_injectable_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_di_injectable_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_di_injectable_ce TSRMLS_CC, 2, phalcon_di_injectionawareinterface_ce, phalcon_events_eventsawareinterface_ce);

	return SUCCESS;
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_DI_Injectable, setDI){

	zval *dependency_injector;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &dependency_injector);
	
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "Dependency Injector is invalid");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_DI_Injectable, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_NVAR(dependency_injector);
		PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
	}
	
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Sets the event manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_DI_Injectable, setEventsManager){

	zval *events_manager;

	phalcon_fetch_params(0, 1, 0, &events_manager);
	
	phalcon_update_property_zval(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_DI_Injectable, getEventsManager){


	RETURN_MEMBER(this_ptr, "_eventsManager");
}

/**
 * Magic method __get
 *
 * @param string $propertyName
 */
PHP_METHOD(Phalcon_DI_Injectable, __get){

	zval *property_name, *dependency_injector = NULL;
	zval *has_service, *service = NULL, *class_name, *arguments;
	zval *persistent, *error_msg;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &property_name);
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
	
		PHALCON_INIT_NVAR(dependency_injector);
		PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "A dependency injection object is required to access the application services");
			return;
		}
	}
	
	/** 
	 * This class injects a public property with a resolved service
	 */
	PHALCON_INIT_VAR(has_service);
	PHALCON_CALL_METHOD_PARAMS_1(has_service, dependency_injector, "has", property_name);
	if (zend_is_true(has_service)) {
		PHALCON_INIT_VAR(service);
		PHALCON_CALL_METHOD_PARAMS_1(service, dependency_injector, "getshared", property_name);
		phalcon_update_property_zval_zval(this_ptr, property_name, service TSRMLS_CC);
		RETURN_CCTOR(service);
	}
	
	if (PHALCON_IS_STRING(property_name, "di")) {
		phalcon_update_property_zval(this_ptr, SL("di"), dependency_injector TSRMLS_CC);
		RETURN_CCTOR(dependency_injector);
	}
	
	/** 
	 * Accessing the persistent property will create a session bag in any class
	 */
	if (PHALCON_IS_STRING(property_name, "persistent")) {
		PHALCON_INIT_VAR(class_name);
		phalcon_get_class(class_name, this_ptr, 0 TSRMLS_CC);
	
		PHALCON_INIT_VAR(arguments);
		array_init_size(arguments, 1);
		phalcon_array_append(&arguments, class_name, PH_SEPARATE TSRMLS_CC);
	
		PHALCON_INIT_NVAR(service);
		ZVAL_STRING(service, "sessionBag", 1);
	
		PHALCON_INIT_VAR(persistent);
		PHALCON_CALL_METHOD_PARAMS_2(persistent, dependency_injector, "get", service, arguments);
		phalcon_update_property_zval(this_ptr, SL("persistent"), persistent TSRMLS_CC);
		RETURN_CCTOR(persistent);
	}
	
	/** 
	 * A notice is shown if the property is not defined and isn't a valid service
	 */
	PHALCON_INIT_VAR(error_msg);
	PHALCON_CONCAT_SV(error_msg, "Access to undefined property ", property_name);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("trigger_error", error_msg);
	RETURN_MM_NULL();
}

