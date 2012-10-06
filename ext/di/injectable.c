
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
 * Sets the dependency injector
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_DI_Injectable, setDI){

	zval *dependency_injector;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_DI_Injectable, getDI){

	zval *dependency_injector;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Sets the event manager
 *
 * @param Phalcon\Events\Manager $eventsManager
 */
PHP_METHOD(Phalcon_DI_Injectable, setEventsManager){

	zval *events_manager;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &events_manager) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\Manager
 */
PHP_METHOD(Phalcon_DI_Injectable, getEventsManager){

	zval *events_manager;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
	RETURN_CCTOR(events_manager);
}

/**
 * Magic method __get
 *
 * @param string $propertyName
 */
PHP_METHOD(Phalcon_DI_Injectable, __get){

	zval *property_name, *dependency_injector;
	zval *has_service, *service = NULL, *class_name, *arguments;
	zval *persistent, *error_msg;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &property_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "A dependency injection object is required to access the application services");
		return;
	}
	
	PHALCON_INIT_VAR(has_service);
	PHALCON_CALL_METHOD_PARAMS_1(has_service, dependency_injector, "has", property_name, PH_NO_CHECK);
	if (zend_is_true(has_service)) {
		PHALCON_INIT_VAR(service);
		PHALCON_CALL_METHOD_PARAMS_1(service, dependency_injector, "getshared", property_name, PH_NO_CHECK);
		phalcon_update_property_zval_zval(this_ptr, property_name, service TSRMLS_CC);
		
		RETURN_CCTOR(service);
	}
	
	if (PHALCON_COMPARE_STRING(property_name, "di")) {
		phalcon_update_property_zval(this_ptr, SL("di"), dependency_injector TSRMLS_CC);
		
		RETURN_CCTOR(dependency_injector);
	}
	
	if (PHALCON_COMPARE_STRING(property_name, "persistent")) {
		PHALCON_INIT_VAR(class_name);
		phalcon_get_class(class_name, this_ptr TSRMLS_CC);
		
		PHALCON_INIT_VAR(arguments);
		array_init(arguments);
		phalcon_array_append(&arguments, class_name, PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_NVAR(service);
		ZVAL_STRING(service, "sessionBag", 1);
		
		PHALCON_INIT_VAR(persistent);
		PHALCON_CALL_METHOD_PARAMS_2(persistent, dependency_injector, "get", service, arguments, PH_NO_CHECK);
		phalcon_update_property_zval(this_ptr, SL("persistent"), persistent TSRMLS_CC);
		
		RETURN_CCTOR(persistent);
	}
	
	PHALCON_INIT_VAR(error_msg);
	PHALCON_CONCAT_SV(error_msg, "Access to undefined property ", property_name);
	PHALCON_CALL_FUNC_PARAMS_1_NORETURN("trigger_error", error_msg);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

