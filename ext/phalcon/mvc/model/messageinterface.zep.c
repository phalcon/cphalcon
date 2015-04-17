
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\Model\Message
 *
 * Interface for Phalcon\Mvc\Model\Message
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MessageInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, MessageInterface, phalcon, mvc_model_messageinterface, phalcon_mvc_model_messageinterface_method_entry);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Message constructor
 *
 * @param string message
 * @param string field
 * @param string type
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, __construct);

/**
 * Sets message type
 *
 * @param string type
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, setType);

/**
 * Returns message type
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, getType);

/**
 * Sets verbose message
 *
 * @param string message
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, setMessage);

/**
 * Returns verbose message
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, getMessage);

/**
 * Sets field name related to message
 *
 * @param string field
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, setField);

/**
 * Returns field name related to message
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, getField);

/**
 * Magic __toString method returns verbose message
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, __toString);

/**
 * Magic __set_state helps to recover messsages from serialization
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, __set_state);

