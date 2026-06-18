
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
 * Canonical contract for Phalcon\Cli\Dispatcher.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Cli_Dispatcher)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Cli, Dispatcher, phalcon, contracts_cli_dispatcher, phalcon_contracts_cli_dispatcher_method_entry);

	zend_class_implements(phalcon_contracts_cli_dispatcher_ce, 1, phalcon_contracts_dispatcher_dispatcher_ce);
	return SUCCESS;
}

/**
 * Returns the active task in the dispatcher
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Cli_Dispatcher, getActiveTask);
/**
 * Returns the latest dispatched controller
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Cli_Dispatcher, getLastTask);
/**
 * Get dispatched options
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Cli_Dispatcher, getOptions);
/**
 * Gets last dispatched task name
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Cli_Dispatcher, getTaskName);
/**
 * Gets default task suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Cli_Dispatcher, getTaskSuffix);
/**
 * Sets the default task name
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Cli_Dispatcher, setDefaultTask);
/**
 * Set the options to be dispatched
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Cli_Dispatcher, setOptions);
/**
 * Sets the task name to be dispatched
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Cli_Dispatcher, setTaskName);
/**
 * Sets the default task suffix
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Cli_Dispatcher, setTaskSuffix);
