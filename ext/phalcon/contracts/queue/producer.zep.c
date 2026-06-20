
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
 * Sends messages to a destination.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Producer)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Queue, Producer, phalcon, contracts_queue_producer, phalcon_contracts_queue_producer_method_entry);

	return SUCCESS;
}

/**
 * Returns the delivery delay (in milliseconds) or null when not set.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Producer, getDeliveryDelay);
/**
 * Returns the message priority or null when not set.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Producer, getPriority);
/**
 * Returns the time to live (in milliseconds) or null when not set.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Producer, getTimeToLive);
/**
 * Sends a message to the given destination.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Producer, send);
/**
 * Sets the delivery delay (in milliseconds). Null clears it.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Producer, setDeliveryDelay);
/**
 * Sets the message priority. Null clears it.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Producer, setPriority);
/**
 * Sets the time to live (in milliseconds). Null clears it.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Producer, setTimeToLive);
