
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Cli\DispatcherInterface
 *
 * Interface for Phalcon\Cli\Dispatcher
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_DispatcherInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Cli, DispatcherInterface, phalcon, cli_dispatcherinterface, phalcon_cli_dispatcherinterface_method_entry);

	zend_class_implements(phalcon_cli_dispatcherinterface_ce TSRMLS_CC, 1, phalcon_dispatcherinterface_ce);
	return SUCCESS;

}

/**
 * Sets the default task suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_DispatcherInterface, setTaskSuffix);

/**
 * Sets the default task name
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_DispatcherInterface, setDefaultTask);

/**
 * Sets the task name to be dispatched
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_DispatcherInterface, setTaskName);

/**
 * Gets last dispatched task name
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_DispatcherInterface, getTaskName);

/**
 * Returns the latest dispatched controller
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_DispatcherInterface, getLastTask);

/**
 * Returns the active task in the dispatcher
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_DispatcherInterface, getActiveTask);

