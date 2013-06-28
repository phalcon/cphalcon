
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

#include "kernel/main.h"

/**
 * Phalcon\DispatcherInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_DispatcherInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon, DispatcherInterface, dispatcherinterface, phalcon_dispatcherinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets the default action suffix
 *
 * @param string $actionSuffix
 */
PHALCON_DOC_METHOD(Phalcon_DispatcherInterface, setActionSuffix);

/**
 * Sets the default namespace
 *
 * @param string $namespace
 */
PHALCON_DOC_METHOD(Phalcon_DispatcherInterface, setDefaultNamespace);

/**
 * Sets the default action name
 *
 * @param string $actionName
 */
PHALCON_DOC_METHOD(Phalcon_DispatcherInterface, setDefaultAction);

/**
 * Sets the action name to be dispatched
 *
 * @param string $actionName
 */
PHALCON_DOC_METHOD(Phalcon_DispatcherInterface, setActionName);

/**
 * Gets last dispatched action name
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_DispatcherInterface, getActionName);

/**
 * Sets action params to be dispatched
 *
 * @param array $params
 */
PHALCON_DOC_METHOD(Phalcon_DispatcherInterface, setParams);

/**
 * Gets action params
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_DispatcherInterface, getParams);

/**
 * Set a param by its name or numeric index
 *
 * @param  mixed $param
 * @param  mixed $value
 */
PHALCON_DOC_METHOD(Phalcon_DispatcherInterface, setParam);

/**
 * Gets a param by its name or numeric index
 *
 * @param  mixed $param
 * @param  string|array $filters
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_DispatcherInterface, getParam);

/**
 * Checks if the dispatch loop is finished or has more pendent controllers/tasks to disptach
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_DispatcherInterface, isFinished);

/**
 * Returns value returned by the lastest dispatched action
 *
 * @return mixed
 */
PHALCON_DOC_METHOD(Phalcon_DispatcherInterface, getReturnedValue);

/**
 * Dispatches a handle action taking into account the routing parameters
 *
 * @return object
 */
PHALCON_DOC_METHOD(Phalcon_DispatcherInterface, dispatch);

/**
 * Forwards the execution flow to another controller/action
 *
 * @param array $forward
 */
PHALCON_DOC_METHOD(Phalcon_DispatcherInterface, forward);

