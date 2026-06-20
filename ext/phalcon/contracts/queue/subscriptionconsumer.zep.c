
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
 * Consumes from several queues at once, dispatching each message to the
 * callback registered for its consumer.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_SubscriptionConsumer)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Queue, SubscriptionConsumer, phalcon, contracts_queue_subscriptionconsumer, phalcon_contracts_queue_subscriptionconsumer_method_entry);

	return SUCCESS;
}

/**
 * Starts consuming, blocking up to timeout milliseconds (0 = block
 * until a message is available).
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_SubscriptionConsumer, consume);
/**
 * Subscribes a consumer; the callback receives each delivered message.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_SubscriptionConsumer, subscribe);
/**
 * Removes a previously subscribed consumer.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_SubscriptionConsumer, unsubscribe);
/**
 * Removes every subscribed consumer.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_SubscriptionConsumer, unsubscribeAll);
