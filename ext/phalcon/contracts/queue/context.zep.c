
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
 *
 * Implementation of this component has been inspired by the queue-interop and
 * enqueue projects.
 *
 * @link    https://github.com/queue-interop/queue-interop
 * @license https://github.com/queue-interop/queue-interop/blob/master/LICENSE
 *
 * @link    https://github.com/php-enqueue/enqueue-dev
 * @license https://github.com/php-enqueue/enqueue-dev/blob/master/LICENSE
 */
/**
 * A session with the transport. Factory for messages, destinations,
 * producers and consumers.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Context)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Queue, Context, phalcon, contracts_queue_context, phalcon_contracts_queue_context_method_entry);

	return SUCCESS;
}

/**
 * Closes the context and releases its resources.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Context, close);
/**
 * Creates a consumer for the given destination.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Context, createConsumer);
/**
 * Creates a message with an optional body, properties and headers.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Context, createMessage);
/**
 * Creates a producer.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Context, createProducer);
/**
 * Creates a queue destination by name.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Context, createQueue);
/**
 * Creates a subscription consumer for consuming from several queues.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Context, createSubscriptionConsumer);
/**
 * Creates a temporary queue tied to the lifetime of the context.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Context, createTemporaryQueue);
/**
 * Creates a topic destination by name.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Context, createTopic);
/**
 * Removes all messages from the given queue.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Context, purgeQueue);
