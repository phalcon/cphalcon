
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

#include "mvc/collection/messageinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_collection_messageinterface_ce;

static const zend_function_entry phalcon_mvc_collection_messageinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_MessageInterface, setType, arginfo_phalcon_mvc_collection_messageinterface_settype)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_MessageInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_MessageInterface, setMessage, arginfo_phalcon_mvc_collection_messageinterface_setmessage)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_MessageInterface, getMessage, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_MessageInterface, setField, arginfo_phalcon_mvc_collection_messageinterface_setfield)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Collection_MessageInterface, getField, NULL)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Collection\MessageInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_MessageInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Collection, MessageInterface, mvc_collection_messageinterface, phalcon_mvc_collection_messageinterface_method_entry);

	return SUCCESS;
}

/**
 * Sets message type
 *
 * @param string $type
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_MessageInterface, setType);

/**
 * Returns message type
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_MessageInterface, getType);

/**
 * Sets verbose message
 *
 * @param string $message
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_MessageInterface, setMessage);

/**
 * Returns verbose message
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_MessageInterface, getMessage);

/**
 * Sets field name related to message
 *
 * @param string $field
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_MessageInterface, setField);

/**
 * Returns field name related to message
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Collection_MessageInterface, getField);
