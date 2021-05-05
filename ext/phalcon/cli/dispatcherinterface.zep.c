
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
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Interface for Phalcon\Cli\Dispatcher
 */
ZEPHIR_INIT_CLASS(Phalcon_Cli_DispatcherInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Cli, DispatcherInterface, phalcon, cli_dispatcherinterface, phalcon_cli_dispatcherinterface_method_entry);

	zend_class_implements(phalcon_cli_dispatcherinterface_ce, 1, phalcon_dispatcher_dispatcherinterface_ce);
	return SUCCESS;
}

/**
 * Returns the active task in the dispatcher
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_DispatcherInterface, getActiveTask);
/**
 * Returns the latest dispatched controller
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_DispatcherInterface, getLastTask);
/**
 * Get dispatched options
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_DispatcherInterface, getOptions);
/**
 * Gets last dispatched task name
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_DispatcherInterface, getTaskName);
/**
 * Gets default task suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_DispatcherInterface, getTaskSuffix);
/**
 * Sets the default task name
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_DispatcherInterface, setDefaultTask);
/**
 * Set the options to be dispatched
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_DispatcherInterface, setOptions);
/**
 * Sets the task name to be dispatched
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_DispatcherInterface, setTaskName);
/**
 * Sets the default task suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_Cli_DispatcherInterface, setTaskSuffix);
