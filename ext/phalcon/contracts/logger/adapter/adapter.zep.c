
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

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
 * Canonical contract for Phalcon\Logger adapters.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Logger_Adapter_Adapter)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Logger\\Adapter, Adapter, phalcon, contracts_logger_adapter_adapter, phalcon_contracts_logger_adapter_adapter_method_entry);

	return SUCCESS;
}

/**
 * Adds a message in the queue
 *
 * @param Item $item
 *
 * @return Adapter
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Adapter_Adapter, add);
/**
 * Starts a transaction
 *
 * @return Adapter
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Adapter_Adapter, begin);
/**
 * Closes the logger
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Adapter_Adapter, close);
/**
 * Commits the internal transaction
 *
 * @return Adapter
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Adapter_Adapter, commit);
/**
 * Returns the internal formatter
 *
 * @return FormatterInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Adapter_Adapter, getFormatter);
/**
 * Returns the whether the logger is currently in an active transaction or
 * not
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Adapter_Adapter, inTransaction);
/**
 * Processes the message in the adapter
 *
 * @param Item $item
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Adapter_Adapter, process);
/**
 * Rollbacks the internal transaction
 *
 * @return Adapter
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Adapter_Adapter, rollback);
/**
 * Sets the message formatter
 *
 * @param FormatterInterface $formatter
 *
 * @return Adapter
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Logger_Adapter_Adapter, setFormatter);
