
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\DispatcherInterface
 *
 * Interface for Phalcon\Dispatcher
 */
ZEPHIR_INIT_CLASS(Phalcon_DispatcherInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon, DispatcherInterface, phalcon, dispatcherinterface, phalcon_dispatcherinterface_method_entry);

	return SUCCESS;

}

/**
 * Dispatches a handle action taking into account the routing parameters
 *
 * @return object
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, dispatch);

/**
 * Forwards the execution flow to another controller/action
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, forward);

/**
 * Gets last dispatched action name
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, getActionName);

/**
 * Gets the default action suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, getActionSuffix);

/**
 * Gets the default handler suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, getHandlerSuffix);

/**
 * Gets a param by its name or numeric index
 *
 * @param  string|array filters
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, getParam);

/**
 * Gets action params
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, getParams);

/**
 * Returns value returned by the latest dispatched action
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, getReturnedValue);

/**
 * Check if a param exists
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, hasParam);

/**
 * Checks if the dispatch loop is finished or has more pendent
 * controllers/tasks to dispatch
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, isFinished);

/**
 * Sets the action name to be dispatched
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setActionName);

/**
 * Sets the default action suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setActionSuffix);

/**
 * Sets the default action name
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setDefaultAction);

/**
 * Sets the default namespace
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setDefaultNamespace);

/**
 * Sets the default suffix for the handler
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setHandlerSuffix);

/**
 * Sets the module name which the application belongs to
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setModuleName);

/**
 * Sets the namespace which the controller belongs to
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setNamespaceName);

/**
 * Set a param by its name or numeric index
 *
 * @param  mixed value
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setParam);

/**
 * Sets action params to be dispatched
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setParams);

