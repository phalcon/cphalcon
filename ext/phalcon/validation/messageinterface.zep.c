
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
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
 *
 * @param string type
 * @return Phalcon\Validation\Message
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_MessageInterface, setType);

/**
 * Returns message type
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_MessageInterface, getType);

/**
 * Sets verbose message
 *
 * @param string message
 * @return Phalcon\Validation\Message
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
 *
 * @param string field
 * @return Phalcon\Validation\Message
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
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_MessageInterface, __toString);

/**
 * Magic __set_state helps to recover messsages from serialization
 *
 * @param array message
 * @return Phalcon\Validation\Message
 */
ZEPHIR_DOC_METHOD(Phalcon_Validation_MessageInterface, __set_state);

