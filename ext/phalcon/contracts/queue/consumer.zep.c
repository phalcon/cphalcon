
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
 * Receives messages from a single queue.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Consumer)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Queue, Consumer, phalcon, contracts_queue_consumer, phalcon_contracts_queue_consumer_method_entry);

	return SUCCESS;
}

/**
 * Acknowledges the message; the transport may then discard it.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Consumer, acknowledge);
/**
 * Returns the queue this consumer reads from.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Consumer, getQueue);
/**
 * Receives a message, blocking up to timeout milliseconds (0 = block
 * until one is available). Returns null when none arrives in time.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Consumer, receive);
/**
 * Receives a message without blocking, or null when none is ready.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Consumer, receiveNoWait);
/**
 * Rejects the message. When requeue is true the transport redelivers it.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Consumer, reject);
