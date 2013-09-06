
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
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"


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
 * Phalcon\DI\Injectable
 *
 * This class allows to access services in the services container by just only accessing a public property
 * with the same name of a registered service
 */
ZEPHIR_INIT_CLASS(Phalcon_DI_Injectable) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\DI, Injectable, phalcon_di_injectable, phalcon_di_injectable_method_entry, 0);

/**
 * Dependency Injector
 *
 * @var Phalcon\DiInteface
 */
	zend_declare_property_null(phalcon_di_injectable_ce, SL("_dependencyInjector"), ZEND_ACC_PUBLIC TSRMLS_CC);
/**
 * Events Manager
 *
 * @var Phalcon\Events\ManagerInterface
 */
	zend_declare_property_null(phalcon_di_injectable_ce, SL("_eventsManager"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_DI_Injectable, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
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
PHP_METHOD(Phalcon_DI_Injectable, getDI) {

	zval *dependencyInjector;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
	}
	RETURN_CCTOR(dependencyInjector);

}

/**
 * Sets the event manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_DI_Injectable, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_DI_Injectable, getEventsManager) {


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Magic method __get
 *
 * @param string propertyName
 */
PHP_METHOD(Phalcon_DI_Injectable, __get) {

	zval *propertyName, *dependencyInjector, *hasService, *service, *persistent, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &propertyName);



	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_di_exception_ce, "A dependency injection object is required to access the application services");
			return;
		}
	}
	ZEPHIR_INIT_VAR(hasService);
	zephir_call_method_p1(hasService, dependencyInjector, "has", propertyName);
	if (zend_is_true(hasService)) {
		ZEPHIR_INIT_VAR(service);
		zephir_call_method_p1(service, dependencyInjector, "getshared", propertyName);
		RETURN_CCTOR(service);
	}
	if (ZEPHIR_IS_STRING(propertyName, "di")) {
		RETURN_CCTOR(dependencyInjector);
	}
	if (ZEPHIR_IS_STRING(propertyName, "persistent")) {
		ZEPHIR_INIT_VAR(_0);
		array_init(_0);
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func_p1(_1, "get_class", this_ptr);
		zephir_array_append(&_0, _1, 0);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "sessionBag", 1);
		ZEPHIR_INIT_VAR(persistent);
		zephir_call_method_p2(persistent, dependencyInjector, "get", _1, _0);
		RETURN_CCTOR(persistent);
	}
	//missing fcall
	RETURN_MM_NULL();

}

