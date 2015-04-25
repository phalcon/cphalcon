
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Validation\Message
 *
 * Interface for Phalcon\Validation\Message
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_MessageInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Validation, MessageInterface, phalcon, validation_messageinterface, phalcon_validation_messageinterface_method_entry);

	return SUCCESS;

}

/**
 * Phalcon\Validation\Message constructor
 *
 * @param string message
 * @param string field
 * @param string type
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_MessageInterface, __construct);

/**
 * Sets message type
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_MessageInterface, setType);

/**
 * Returns message type
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_MessageInterface, getType);

/**
 * Sets verbose message
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_MessageInterface, setMessage);

/**
 * Returns verbose message
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_MessageInterface, getMessage);

/**
 * Sets field name related to message
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_MessageInterface, setField);

/**
 * Returns field name related to message
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_MessageInterface, getField);

/**
 * Magic __toString method returns verbose message
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_MessageInterface, __toString);

/**
 * Magic __set_state helps to recover messsages from serialization
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_MessageInterface, __set_state);

