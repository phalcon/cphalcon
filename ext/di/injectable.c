
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

#include "php_phalcon.h"

#include "di/exception.h"
#include "di/injectable.h"
#include "di/injectionawareinterface.h"
#include "events/eventsawareinterface.h"
#include "diinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/operators.h"

/**
 * Phalcon\DI\Injectable
 *
 * This class allows to access services in the services container by just only accessing a public property
 * with the same name of a registered service
 */
zend_class_entry *phalcon_di_injectable_ce;

PHP_METHOD(Phalcon_DI_Injectable, setDI);
PHP_METHOD(Phalcon_DI_Injectable, getDI);
PHP_METHOD(Phalcon_DI_Injectable, setEventsManager);
PHP_METHOD(Phalcon_DI_Injectable, getEventsManager);
PHP_METHOD(Phalcon_DI_Injectable, __get);

static const zend_function_entry phalcon_di_injectable_method_entry[] = {
	PHP_ME(Phalcon_DI_Injectable, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Injectable, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Injectable, setEventsManager, arginfo_phalcon_events_eventsawareinterface_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Injectable, getEventsManager, arginfo_phalcon_events_eventsawareinterface_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Injectable, __get, arginfo_phalcon_di_injectable___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};


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
 * @throw Phalcon\Di\Exception if !($dependencyInjector instanceof Phalcon\DiInterface)
 */
PHP_METHOD(Phalcon_DI_Injectable, setDI){

	zval **dependency_injector;

	phalcon_fetch_params_ex(1, 0, &dependency_injector);
	
	PHALCON_VERIFY_INTERFACE_EX(*dependency_injector, phalcon_diinterface_ce, phalcon_di_exception_ce, 0);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), *dependency_injector TSRMLS_CC);
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_DI_Injectable, getDI){

	zval *dependency_injector ;

	dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_MM_GROW();
		phalcon_return_call_static_p0("phalcon\\di", "getdefault");
		RETURN_MM();
	}
	
	RETURN_ZVAL(dependency_injector, 1, 0);
}

/**
 * Sets the event manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_DI_Injectable, setEventsManager){

	zval *events_manager;

	phalcon_fetch_params(0, 1, 0, &events_manager);
	
	phalcon_update_property_this(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &property_name);

	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {

		PHALCON_INIT_NVAR(dependency_injector);
		phalcon_call_static(dependency_injector, "phalcon\\di", "getdefault");

		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "A dependency injection object is required to access the application services");
			return;
		}
	}

	/**
	 * Fallback to the PHP userland if the cache is not available
	 */
	PHALCON_INIT_VAR(has_service);
	phalcon_call_method_p1(has_service, dependency_injector, "has", property_name);
	if (zend_is_true(has_service)) {
		phalcon_return_call_method_p1(dependency_injector, "getshared", property_name);
		phalcon_update_property_zval_zval(this_ptr, property_name, (return_value_ptr ? *return_value_ptr : return_value) TSRMLS_CC);
		RETURN_MM();
	}

	if (PHALCON_IS_STRING(property_name, "di")) {
		phalcon_update_property_this(this_ptr, SL("di"), dependency_injector TSRMLS_CC);
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
		phalcon_array_append(&arguments, class_name, 0);

		PHALCON_INIT_NVAR(service);
		ZVAL_STRING(service, "sessionBag", 1);

		phalcon_return_call_method_p2(dependency_injector, "get", service, arguments);
		zend_update_property(phalcon_di_injectable_ce, getThis(), SL("persistent"), (return_value_ptr ? *return_value_ptr : return_value) TSRMLS_CC);
		RETURN_MM();
	}

	/**
	 * A notice is shown if the property is not defined and isn't a valid service
	 */
	php_error_docref(NULL TSRMLS_CC, E_WARNING, "Access to undefined property %s", Z_STRVAL_P(property_name));
	RETURN_MM_NULL();
}
