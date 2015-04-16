
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 * Sets the default action suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setActionSuffix);

/**
 * Sets the default namespace
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setDefaultNamespace);

/**
 * Sets the default action name
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setDefaultAction);

/**
 * Sets the namespace which the controller belongs to
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setNamespaceName);

/**
 * Sets the module name which the application belongs to
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setModuleName);

/**
 * Sets the action name to be dispatched
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setActionName);

/**
 * Gets last dispatched action name
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, getActionName);

/**
 * Sets action params to be dispatched
 *
 * @param array params
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setParams);

/**
 * Gets action params
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, getParams);

/**
 * Set a param by its name or numeric index
 *
 * @param  mixed param
 * @param  mixed value
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, setParam);

/**
 * Gets a param by its name or numeric index
 *
 * @param  mixed param
 * @param  string|array filters
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, getParam);

/**
 * Checks if the dispatch loop is finished or has more pendent controllers/tasks to dispatch
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, isFinished);

/**
 * Returns value returned by the lastest dispatched action
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, getReturnedValue);

/**
 * Dispatches a handle action taking into account the routing parameters
 *
 * @return object
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, dispatch);

/**
 * Forwards the execution flow to another controller/action
 *
 * @param array forward
 */
ZEPHIR_DOC_METHOD(Phalcon_DispatcherInterface, forward);

