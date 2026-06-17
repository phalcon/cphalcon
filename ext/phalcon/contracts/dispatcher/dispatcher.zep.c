
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Canonical contract for Phalcon\Dispatcher\AbstractDispatcher.
 *
 * Note: The deprecated `getParam()`/`getParams()`/`hasParam()`/`setParam()`/
 * `setParams()` spellings are still declared for backwards compatibility and
 * are scheduled to be removed in the next major version in favor of their
 * `*Parameter` counterparts.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Dispatcher_Dispatcher)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Dispatcher, Dispatcher, phalcon, contracts_dispatcher_dispatcher, phalcon_contracts_dispatcher_dispatcher_method_entry);

	return SUCCESS;
}

/**
 * Dispatches a handle action taking into account the routing parameters
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, dispatch);
/**
 * Forwards the execution flow to another controller/action
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, forward);
/**
 * Gets last dispatched action name
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, getActionName);
/**
 * Gets the default action suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, getActionSuffix);
/**
 * Gets the default handler suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, getHandlerSuffix);
/**
 * Gets a param by its name or numeric index
 *
 * @param  string|array filters
 *
 * @deprecated Use getParameter() instead
 *
 * Note: This signature omits the `defaultValue` argument the implementation
 * accepts; the two will be aligned in the next major version.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, getParam);
/**
 * Gets a param by its name or numeric index
 *
 * @param  string|array filters
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, getParameter);
/**
 * Gets action params
 *
 * @deprecated Use getParameters() instead
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, getParams);
/**
 * Gets action params
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, getParameters);
/**
 * Returns value returned by the latest dispatched action
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, getReturnedValue);
/**
 * Check if a param exists
 *
 * @deprecated Use hasParameter() instead
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, hasParam);
/**
 * Checks if the dispatch loop is finished or has more pendent
 * controllers/tasks to dispatch
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, isFinished);
/**
 * Sets the action name to be dispatched
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, setActionName);
/**
 * Sets the default action suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, setActionSuffix);
/**
 * Sets the default action name
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, setDefaultAction);
/**
 * Sets the default namespace
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, setDefaultNamespace);
/**
 * Sets the default suffix for the handler
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, setHandlerSuffix);
/**
 * Sets the module name which the application belongs to
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, setModuleName);
/**
 * Sets the namespace which the controller belongs to
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, setNamespaceName);
/**
 * Set a param by its name or numeric index
 *
 * @param  mixed value
 *
 * @deprecated Use setParameter() instead
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, setParam);
/**
 * Sets action params to be dispatched
 *
 * @deprecated Use setParameters() instead
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Dispatcher_Dispatcher, setParams);
