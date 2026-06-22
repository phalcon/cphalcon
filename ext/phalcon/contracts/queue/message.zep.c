
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
 * A message exchanged through the transport. Carries a body, application
 * properties, transport headers and the standard messaging metadata.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Queue_Message)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Queue, Message, phalcon, contracts_queue_message, phalcon_contracts_queue_message_method_entry);

	return SUCCESS;
}

/**
 * Returns the message body.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, getBody);
/**
 * Returns the correlation id used to correlate request/reply messages.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, getCorrelationId);
/**
 * Returns a single header value, or the default when it is not set.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, getHeader);
/**
 * Returns all transport headers.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, getHeaders);
/**
 * Returns the message id.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, getMessageId);
/**
 * Returns all application properties.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, getProperties);
/**
 * Returns a single property value, or the default when it is not set.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, getProperty);
/**
 * Returns the reply-to destination name.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, getReplyTo);
/**
 * Returns the timestamp (in milliseconds) or null when it is not set.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, getTimestamp);
/**
 * Whether the message has been redelivered.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, isRedelivered);
/**
 * Sets the message body.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, setBody);
/**
 * Sets the correlation id.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, setCorrelationId);
/**
 * Sets a single transport header.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, setHeader);
/**
 * Replaces all transport headers.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, setHeaders);
/**
 * Sets the message id.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, setMessageId);
/**
 * Replaces all application properties.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, setProperties);
/**
 * Sets a single application property.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, setProperty);
/**
 * Marks the message as redelivered.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, setRedelivered);
/**
 * Sets the reply-to destination name.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, setReplyTo);
/**
 * Sets the timestamp (in milliseconds).
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Queue_Message, setTimestamp);
