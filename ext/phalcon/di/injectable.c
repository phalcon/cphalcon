
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"


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
/**
 * Phalcon\Di\Injectable
 *
 * This class allows to access services in the services container by just only accessing a public property
 * with the same name of a registered service
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_Injectable) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Di, Injectable, phalcon, di_injectable, phalcon_di_injectable_method_entry, 0);

/**
	 * Dependency Injector
	 *
	 * @var Phalcon\DiInteface
	 */
	zend_declare_property_null(phalcon_di_injectable_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Events Manager
	 *
	 * @var Phalcon\Events\ManagerInterface
	 */
	zend_declare_property_null(phalcon_di_injectable_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_di_injectable_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_di_injectable_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);

	return SUCCESS;

}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Di_Injectable, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STRW(phalcon_di_exception_ce, "Dependency Injector is invalid");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Di_Injectable, getDI) {

	zval *dependencyInjector;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_INIT_BNVAR(dependencyInjector);
		zephir_call_static(dependencyInjector, "Phalcon\\Di", "getdefault");
	}
	RETURN_CCTOR(dependencyInjector);

}

/**
 * Sets the event manager
 *
 * @param Phalcon\Events\ManagerInterface eventsManager
 */
PHP_METHOD(Phalcon_Di_Injectable, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Di_Injectable, getEventsManager) {


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Magic method __get
 *
 * @param string propertyName
 */
PHP_METHOD(Phalcon_Di_Injectable, __get) {

	zval *propertyName_param = NULL, *dependencyInjector = NULL, *hasService, *service, *persistent = NULL, *_0, *_1, *_2, *_3 = NULL, *_4;
	zval *propertyName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &propertyName_param);

		if (Z_TYPE_P(propertyName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'propertyName' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		propertyName = propertyName_param;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(dependencyInjector);
		zephir_call_static(dependencyInjector, "Phalcon\\Di", "getdefault");
		if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "A dependency injection object is required to access the application services");
			return;
		}
	}
	ZEPHIR_INIT_VAR(hasService);
	zephir_call_method_p1(hasService, dependencyInjector, "has", propertyName);
	if (zephir_is_true(hasService)) {
		ZEPHIR_INIT_VAR(service);
		zephir_call_method_p1(service, dependencyInjector, "getshared", propertyName);
		zephir_update_property_zval_zval(this_ptr, propertyName, service TSRMLS_CC);
		RETURN_CCTOR(service);
	}
	if (ZEPHIR_IS_STRING(propertyName, "di")) {
		RETURN_CCTOR(dependencyInjector);
	}
	if (ZEPHIR_IS_STRING(propertyName, "persistent")) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_INIT_VAR(_2);
		array_init(_2);
		ZEPHIR_INIT_VAR(_3);
		zephir_call_func_p1(_3, "get_class", this_ptr);
		zephir_array_fast_append(_2, _3);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "sessionBag", 1);
		zephir_call_method_p2(_1, dependencyInjector, "get", _3, _2);
		ZEPHIR_CPY_WRT(persistent, _1);
		RETURN_CCTOR(persistent);
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SV(_4, "Access to undefined property ", propertyName);
	zephir_call_func_p1_noret("trigger_error", _4);
	RETURN_MM_NULL();

}

