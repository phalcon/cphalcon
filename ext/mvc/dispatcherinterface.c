
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

#include "kernel/main.h"

/**
 * Phalcon\Mvc\DispatcherInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_DispatcherInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc, DispatcherInterface, mvc_dispatcherinterface, phalcon_mvc_dispatcherinterface_method_entry);

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

