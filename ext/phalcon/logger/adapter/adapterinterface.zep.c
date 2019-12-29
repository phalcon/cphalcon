
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
 * Phalcon\Logger\AdapterInterface
 *
 * Interface for Phalcon\Logger adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Logger\\Adapter, AdapterInterface, phalcon, logger_adapter_adapterinterface, phalcon_logger_adapter_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * Adds a message in the queue
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_Adapter_AdapterInterface, add);

/**
 * Starts a transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_Adapter_AdapterInterface, begin);

/**
 * Closes the logger
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_Adapter_AdapterInterface, close);

/**
 * Commits the internal transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_Adapter_AdapterInterface, commit);

/**
 * Returns the internal formatter
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_Adapter_AdapterInterface, getFormatter);

/**
 * Returns the whether the logger is currently in an active transaction or
 * not
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_Adapter_AdapterInterface, inTransaction);

/**
 * Processes the message in the adapter
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_Adapter_AdapterInterface, process);

/**
 * Rollbacks the internal transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_Adapter_AdapterInterface, rollback);

/**
 * Sets the message formatter
 */
ZEPHIR_DOC_METHOD(Phalcon_Logger_Adapter_AdapterInterface, setFormatter);

