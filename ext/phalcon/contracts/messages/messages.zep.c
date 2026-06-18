
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
 * Canonical contract for Phalcon\Messages\Messages.
 *
 * The collection stores Phalcon\Messages\MessageInterface objects and is
 * iterated by integer position. An entry added under a string key through the
 * ArrayAccess interface stays reachable by that offset but is not visited
 * during iteration (`foreach`), which walks the integer sequence only.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Messages_Messages)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Messages, Messages, phalcon, contracts_messages_messages, phalcon_contracts_messages_messages_method_entry);

	zend_class_implements(phalcon_contracts_messages_messages_ce, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_contracts_messages_messages_ce, 1, zend_ce_countable);
	zend_class_implements(phalcon_contracts_messages_messages_ce, 1, zend_ce_iterator);
	return SUCCESS;
}

/**
 * Appends a message to the collection
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Messages_Messages, appendMessage);
/**
 * Appends an array of messages to the collection
 *
 * @param \Phalcon\Messages\MessageInterface[] messages
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Messages_Messages, appendMessages);
/**
 * Filters the message collection by field name
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Messages_Messages, filter);
