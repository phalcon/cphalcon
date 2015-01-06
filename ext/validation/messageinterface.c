
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

#include "validation/messageinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_validation_messageinterface_ce;

static const zend_function_entry phalcon_validation_messageinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, setType, arginfo_phalcon_validation_messageinterface_settype)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, setCode, arginfo_phalcon_validation_messageinterface_setcode)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, getCode, NULL)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, setMessage, arginfo_phalcon_validation_messageinterface_setmessage)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, getMessage, NULL)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, setField, arginfo_phalcon_validation_messageinterface_setfield)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, getField, NULL)
	PHP_ABSTRACT_ME(Phalcon_Validation_MessageInterface, __toString, NULL)
	PHP_FE_END
};

/**
 * Phalcon\Validation\MessageInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_MessageInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Validation, MessageInterface, validation_messageinterface, phalcon_validation_messageinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets message type
 *
 * @param string $type
 * @return Phalcon\Validation\MessageInterface
 */
PHALCON_DOC_METHOD(Phalcon_Validation_MessageInterface, setType);

/**
 * Returns message type
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Validation_MessageInterface, getType);

/**
 * Sets message code
 *
 * @param string $code
 * @return Phalcon\Validation\MessageInterface
 */
PHALCON_DOC_METHOD(Phalcon_Validation_MessageInterface, setCode);

/**
 * Returns message code
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Validation_MessageInterface, getCode);

/**
 * Sets verbose message
 *
 * @param string $message
 * @return Phalcon\Validation\MessageInterface
 */
PHALCON_DOC_METHOD(Phalcon_Validation_MessageInterface, setMessage);

/**
 * Returns verbose message
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Validation_MessageInterface, getMessage);

/**
 * Sets field name related to message
 *
 * @param string $field
 * @return Phalcon\Validation\MessageInterface
 */
PHALCON_DOC_METHOD(Phalcon_Validation_MessageInterface, setField);

/**
 * Returns field name related to message
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Validation_MessageInterface, getField);

/**
 * Magic __toString method returns verbose message
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Validation_MessageInterface, __toString);
