
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Interface for Phalcon\Dispatcher\AbstractDispatcher
 */
ZEPHIR_INIT_CLASS(Phalcon_Dispatcher_DispatcherInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Dispatcher, DispatcherInterface, phalcon, dispatcher_dispatcherinterface, phalcon_dispatcher_dispatcherinterface_method_entry);

	return SUCCESS;

}

/**
 * Dispatches a handle action taking into account the routing parameters
 *
 * @return object|false
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, dispatch);
/**
 * Forwards the execution flow to another controller/action
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, forward);
/**
 * Gets last dispatched action name
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, getActionName);
/**
 * Gets the default action suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, getActionSuffix);
/**
 * Gets the default handler suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, getHandlerSuffix);
/**
 * Gets a param by its name or numeric index
 *
 * @param  string|array filters
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, getParam);
/**
 * Gets action params
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, getParams);
/**
 * Returns value returned by the latest dispatched action
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, getReturnedValue);
/**
 * Check if a param exists
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, hasParam);
/**
 * Checks if the dispatch loop is finished or has more pendent
 * controllers/tasks to dispatch
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, isFinished);
/**
 * Sets the action name to be dispatched
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, setActionName);
/**
 * Sets the default action suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, setActionSuffix);
/**
 * Sets the default action name
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, setDefaultAction);
/**
 * Sets the default namespace
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, setDefaultNamespace);
/**
 * Sets the default suffix for the handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, setHandlerSuffix);
/**
 * Sets the module name which the application belongs to
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, setModuleName);
/**
 * Sets the namespace which the controller belongs to
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, setNamespaceName);
/**
 * Set a param by its name or numeric index
 *
 * @param  mixed value
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, setParam);
/**
 * Sets action params to be dispatched
 */
ZEPHIR_DOC_METHOD(Phalcon_Dispatcher_DispatcherInterface, setParams);
