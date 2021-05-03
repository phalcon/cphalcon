
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
 * Phalcon\Messages\MessageInterface
 *
 * Interface for Phalcon\Messages\MessageInterface
 */
ZEPHIR_INIT_CLASS(Phalcon_Messages_MessageInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Messages, MessageInterface, phalcon, messages_messageinterface, phalcon_messages_messageinterface_method_entry);

	return SUCCESS;
}

/**
 * Magic __toString method returns verbose message
 */
ZEPHIR_DOC_METHOD(Phalcon_Messages_MessageInterface, __toString);
/**
 * Returns the message code related to this message
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Messages_MessageInterface, getCode);
/**
 * Returns field name related to message
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Messages_MessageInterface, getField);
/**
 * Returns verbose message
 */
ZEPHIR_DOC_METHOD(Phalcon_Messages_MessageInterface, getMessage);
/**
 * Returns message metadata
 */
ZEPHIR_DOC_METHOD(Phalcon_Messages_MessageInterface, getMetaData);
/**
 * Returns message type
 */
ZEPHIR_DOC_METHOD(Phalcon_Messages_MessageInterface, getType);
/**
 * Sets code for the message
 */
ZEPHIR_DOC_METHOD(Phalcon_Messages_MessageInterface, setCode);
/**
 * Sets field name related to message
 */
ZEPHIR_DOC_METHOD(Phalcon_Messages_MessageInterface, setField);
/**
 * Sets verbose message
 */
ZEPHIR_DOC_METHOD(Phalcon_Messages_MessageInterface, setMessage);
/**
 * Sets message metadata
 */
ZEPHIR_DOC_METHOD(Phalcon_Messages_MessageInterface, setMetaData);
/**
 * Sets message type
 */
ZEPHIR_DOC_METHOD(Phalcon_Messages_MessageInterface, setType);
