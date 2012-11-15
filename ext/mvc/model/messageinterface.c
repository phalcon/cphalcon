
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Mvc\Model\MessageInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MessageInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, MessageInterface, mvc_model_messageinterface, phalcon_mvc_model_messageinterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Message constructor
 *
 * @param string $message
 * @param string $field
 * @param string $type
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, __construct);

/**
 * Sets message type
 *
 * @param string $type
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, setType);

/**
 * Returns message type
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, getType);

/**
 * Sets verbose message
 *
 * @param string $message
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, setMessage);

/**
 * Returns verbose message
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, getMessage);

/**
 * Sets field name related to message
 *
 * @param string $field
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, setField);

/**
 * Returns field name related to message
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, getField);

/**
 * Magic __toString method returns verbose message
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, __toString);

/**
 * Magic __set_state helps to recover messsages from serialization
 *
 * @param array $message
 * @return Phalcon\Mvc\Model\MessageInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_MessageInterface, __set_state);

