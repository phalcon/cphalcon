
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

#include "di/injectable.h"
#include "di/exception.h"
#include "di/injectionawareinterface.h"
#include "diinterface.h"
#include "di.h"
#include "events/eventsawareinterface.h"
#include "events/managerinterface.h"
#include "diinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"

#include "internal/arginfo.h"
#include "interned-strings.h"

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
PHP_METHOD(Phalcon_DI_Injectable, fireEvent);
PHP_METHOD(Phalcon_DI_Injectable, fireEventCancel);
PHP_METHOD(Phalcon_DI_Injectable, __get);

static const zend_function_entry phalcon_di_injectable_method_entry[] = {
	PHP_ME(Phalcon_DI_Injectable, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Injectable, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Injectable, setEventsManager, arginfo_phalcon_events_eventsawareinterface_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Injectable, getEventsManager, arginfo_phalcon_events_eventsawareinterface_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Injectable, fireEvent, arginfo_phalcon_di_injectable_fireevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Injectable, fireEventCancel, arginfo_phalcon_di_injectable_fireeventcancel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DI_Injectable, __get, arginfo___get, ZEND_ACC_PUBLIC)
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
 * @throw Phalcon\Di\Exception
 */
PHP_METHOD(Phalcon_DI_Injectable, setDI){

	zval **dependency_injector;

	phalcon_fetch_params_ex(1, 0, &dependency_injector);
	
	PHALCON_VERIFY_INTERFACE_OR_NULL_EX(*dependency_injector, phalcon_diinterface_ce, phalcon_di_exception_ce, 0);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), *dependency_injector TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_DI_Injectable, getDI)
{
	zval *dependency_injector = phalcon_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_RETURN_CALL_CE_STATICW(phalcon_di_ce, "getdefault");
		return;
	}
	
	RETURN_ZVAL(dependency_injector, 1, 0);
}

/**
 * Sets the event manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_DI_Injectable, setEventsManager)
{
	zval *events_manager;

	phalcon_fetch_params(0, 1, 0, &events_manager);
	PHALCON_VERIFY_INTERFACE_OR_NULL_EX(events_manager, phalcon_events_managerinterface_ce, phalcon_di_exception_ce, 0);
	
	phalcon_update_property_this(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);

	RETURN_THISW();
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
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 *
 * @param string $eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_DI_Injectable, fireEvent){

	zval *event_name, *data = NULL, *cancelable = NULL, *events_manager;
	zval *lower, *event_parts, *name = NULL, *status = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &event_name, &data, &cancelable);
	PHALCON_ENSURE_IS_STRING(&event_name);

	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}

	if (!cancelable) {
		cancelable = PHALCON_GLOBAL(z_true);
	}

	PHALCON_INIT_VAR(lower);
	phalcon_fast_strtolower(lower, event_name);

	if (phalcon_memnstr_str(lower, SL(":"))) {
		PHALCON_INIT_VAR(event_parts);
		phalcon_fast_explode_str(event_parts, SL(":"), lower);

		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_long(&name, event_parts, 1, PH_NOISY);
	} else {
		PHALCON_CPY_WRT(name, lower);
	}

	/**
	 * Check if there is a method with the same name of the event
	 */
	if (phalcon_method_exists(this_ptr, name TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD(NULL, this_ptr, Z_STRVAL_P(name), data);
	}

	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(events_manager) != IS_NULL) {
		PHALCON_VERIFY_INTERFACE_EX(events_manager, phalcon_events_managerinterface_ce, phalcon_di_exception_ce, 1);

		/**
		 * Send a notification to the events manager
		 */
		PHALCON_CALL_METHOD(&status, events_manager, "fire", event_name, this_ptr, data, cancelable);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}

	RETURN_MM_TRUE;
}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 * This method stops if one of the callbacks/listeners returns boolean false
 *
 * @param string $eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_DI_Injectable, fireEventCancel){

	zval *event_name, *data = NULL, *cancelable = NULL, *status = NULL, *events_manager;
	zval *lower, *event_parts, *name = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &event_name, &data, &cancelable);
	PHALCON_ENSURE_IS_STRING(&event_name);

	if (!data) {
		data = PHALCON_GLOBAL(z_null);
	}

	if (!cancelable) {
		cancelable = PHALCON_GLOBAL(z_true);
	}

	PHALCON_INIT_VAR(lower);
	phalcon_fast_strtolower(lower, event_name);

	if (phalcon_memnstr_str(lower, SL(":"))) {
		PHALCON_INIT_VAR(event_parts);
		phalcon_fast_explode_str(event_parts, SL(":"), lower);

		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_long(&name, event_parts, 1, PH_NOISY);
	} else {
		PHALCON_CPY_WRT(name, lower);
	}

	/**
	 * Check if there is a method with the same name of the event
	 */
	if (phalcon_method_exists(this_ptr, name TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD(&status, this_ptr, Z_STRVAL_P(name), data);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}

	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(events_manager) != IS_NULL) {
		PHALCON_VERIFY_INTERFACE_EX(events_manager, phalcon_events_managerinterface_ce, phalcon_di_exception_ce, 1);

		/**
		 * Send a notification to the events manager
		 */
		PHALCON_CALL_METHOD(&status, events_manager, "fire", event_name, this_ptr, data, cancelable);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}

	RETURN_MM_TRUE;
}

/**
 * Magic method __get
 *
 * @param string $propertyName
 */
PHP_METHOD(Phalcon_DI_Injectable, __get){

	zval **property_name, *dependency_injector = NULL;
	zval *has_service = NULL, *service = NULL, *class_name, *arguments, *result = NULL;

	phalcon_fetch_params_ex(1, 0, &property_name);
	PHALCON_ENSURE_IS_STRING(property_name);

	PHALCON_MM_GROW();

	PHALCON_CALL_METHOD(&dependency_injector, this_ptr, "getdi");

	PHALCON_CALL_METHOD(&has_service, dependency_injector, "has", *property_name);
	if (zend_is_true(has_service)) {
		PHALCON_CALL_METHOD(&result, dependency_injector, "getshared", *property_name);
		phalcon_update_property_zval(this_ptr, Z_STRVAL_PP(property_name), Z_STRLEN_PP(property_name), result TSRMLS_CC);
		RETURN_CTOR(result);
	}

	assert(Z_TYPE_PP(property_name) == IS_STRING);

	if (Z_STRLEN_PP(property_name) == sizeof("di")-1 && !memcmp(Z_STRVAL_PP(property_name), "di", sizeof("di")-1)) {
		zend_update_property(phalcon_di_injectable_ce, getThis(), SL("di"), dependency_injector TSRMLS_CC);
		RETURN_CTOR(dependency_injector);
	}

	/**
	 * Accessing the persistent property will create a session bag in any class
	 */
	if (Z_STRLEN_PP(property_name) == sizeof("persistent")-1 && !memcmp(Z_STRVAL_PP(property_name), "persistent", sizeof("persistent")-1)) {
		const char *cn = Z_OBJCE_P(getThis())->name;

		MAKE_STD_ZVAL(class_name);
		PHALCON_ZVAL_MAYBE_INTERNED_STRING(class_name, cn);

		PHALCON_INIT_VAR(arguments);
		array_init_size(arguments, 1);
		add_next_index_zval(arguments, class_name);

		PHALCON_INIT_NVAR(service);
		ZVAL_STRING(service, "sessionBag", 1);

		PHALCON_CALL_METHOD(&result, dependency_injector, "get", service, arguments);
		zend_update_property(phalcon_di_injectable_ce, getThis(), SL("persistent"), result TSRMLS_CC);
		RETURN_CTOR(result);
	}

	/**
	 * A notice is shown if the property is not defined or is not a valid service
	 */
	php_error_docref(NULL TSRMLS_CC, E_WARNING, "Access to undefined property %s::%s", Z_OBJCE_P(getThis())->name, Z_STRVAL_PP(property_name));
	RETURN_MM_NULL();
}
