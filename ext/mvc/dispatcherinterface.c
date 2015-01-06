
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

#include "mvc/dispatcherinterface.h"
#include "mvc/../dispatcherinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_dispatcherinterface_ce;

static const zend_function_entry phalcon_mvc_dispatcherinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setControllerSuffix, arginfo_phalcon_mvc_dispatcherinterface_setcontrollersuffix)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setDefaultController, arginfo_phalcon_mvc_dispatcherinterface_setdefaultcontroller)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, setControllerName, arginfo_phalcon_mvc_dispatcherinterface_setcontrollername)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getControllerName, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getLastController, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_DispatcherInterface, getActiveController, NULL)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\DispatcherInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_DispatcherInterface){

	PHALCON_REGISTER_INTERFACE_EX(Phalcon\\Mvc, DispatcherInterface, mvc_dispatcherinterface, phalcon_dispatcherinterface_ce, phalcon_mvc_dispatcherinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets the default controller suffix
 *
 * @param string $controllerSuffix
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, setControllerSuffix);

/**
 * Sets the default controller name
 *
 * @param string $controllerName
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, setDefaultController);

/**
 * Sets the controller name to be dispatched
 *
 * @param string $controllerName
 * @param bool $isExact If true, the name should not be mangled in any way
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, setControllerName);

/**
 * Gets last dispatched controller name
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, getControllerName);

/**
 * Returns the lastest dispatched controller
 *
 * @return Phalcon\Mvc\ControllerInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, getLastController);

/**
 * Returns the active controller in the dispatcher
 *
 * @return Phalcon\Mvc\ControllerInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_DispatcherInterface, getActiveController);
