
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
#include "kernel/object.h"
#include "kernel/memory.h"


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
 * Phalcon\Mvc\Dispatcher
 *
 * Dispatching is the process of taking the request object, extracting the module name,
 * controller name, action name, and optional parameters contained in it, and then
 * instantiating a controller and calling an action of that controller.
 *
 *<code>
 *
 *	$di = new Phalcon\DI();
 *
 *	$dispatcher = new Phalcon\Mvc\Dispatcher();
 *
 *  $dispatcher->setDI($di);
 *
 *	$dispatcher->setControllerName('posts');
 *	$dispatcher->setActionName('index');
 *	$dispatcher->setParams(array());
 *
 *	$controller = $dispatcher->dispatch();
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Dispatcher) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Dispatcher, phalcon, mvc_dispatcher, phalcon_dispatcher_ce, phalcon_mvc_dispatcher_method_entry, 0);

	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_handlerSuffix"), "Controller", ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_defaultHandler"), "index", ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_dispatcher_ce, SL("_defaultAction"), "index", ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * Sets the default controller suffix
 *
 * @param string controllerSuffix
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerSuffix) {

	zval *controllerSuffix;

	zephir_fetch_params(0, 1, 0, &controllerSuffix);



	zephir_update_property_this(this_ptr, SL("_handlerSuffix"), controllerSuffix TSRMLS_CC);

}

/**
 * Sets the default controller name
 *
 * @param string controllerName
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setDefaultController) {

	zval *controllerName;

	zephir_fetch_params(0, 1, 0, &controllerName);



	zephir_update_property_this(this_ptr, SL("_defaultHandler"), controllerName TSRMLS_CC);

}

/**
 * Sets the controller name to be dispatched
 *
 * @param string controllerName
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, setControllerName) {

	zval *controllerName;

	zephir_fetch_params(0, 1, 0, &controllerName);



	zephir_update_property_this(this_ptr, SL("_handlerName"), controllerName TSRMLS_CC);

}

/**
 * Gets last dispatched controller name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Dispatcher, getControllerName) {


	RETURN_MEMBER(this_ptr, "_handlerName");

}

