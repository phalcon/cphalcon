
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 * Phalcon\Mvc\DispatcherInterface
 *
 * Interface for Phalcon\Mvc\Dispatcher
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_DispatcherInterface) {

	ZEPHIR_REGISTER_INTERFACE_EX(Phalcon\\Mvc, DispatcherInterface, phalcon, mvc_dispatcherinterface, phalcon_dispatcherinterface_ce, phalcon_mvc_dispatcherinterface_method_entry);


	return SUCCESS;

}

/**
 * Sets the default controller suffix
 *
 * @param string controllerSuffix
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, setControllerSuffix);

/**
 * Sets the default controller name
 *
 * @param string controllerName
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, setDefaultController);

/**
 * Sets the controller name to be dispatched
 *
 * @param string controllerName
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, setControllerName);

/**
 * Gets last dispatched controller name
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, getControllerName);

/**
 * Returns the lastest dispatched controller
 *
 * @return Phalcon\Mvc\ControllerInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, getLastController);

/**
 * Returns the active controller in the dispatcher
 *
 * @return Phalcon\Mvc\ControllerInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, getActiveController);

