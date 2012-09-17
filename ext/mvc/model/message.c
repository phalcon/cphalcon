
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Mvc\Model\Message
 *
 * Encapsulates validation info generated before save/delete records fails
 *
 * <code>
 * use Phalcon\Mvc\Model\Message as Message;
 *
 * class Robots extends Phalcon\Mvc\Model
 *{
 *
 *   public function beforeSave()
 *   {
 *     if (this->name == 'Peter') {
 *        $text = "A robot cannot be named Peter";
 *        $field = "name";
 *        $type = "InvalidValue";
 *        $message = new Message($text, $field, $type);
 *        $this->appendMessage($message);
 *     }
 *   }
 *
 * }
 * </code>
 *
 */

/**
 * Phalcon\Mvc\Model\Message constructor
 *
 * @param string $message
 * @param string $field
 * @param string $type
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, __construct){

	zval *message = NULL, *field = NULL, *type = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zz", &message, &field, &type) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!field) {
		PHALCON_ALLOC_ZVAL_MM(field);
		ZVAL_NULL(field);
	}
	
	if (!type) {
		PHALCON_ALLOC_ZVAL_MM(type);
		ZVAL_NULL(type);
	}
	
	phalcon_update_property_zval(this_ptr, SL("_message"), message TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_field"), field TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_type"), type TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets message type
 *
 * @param string $type
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setType){

	zval *type = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &type) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_type"), type TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns message type
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getType){

	zval *type = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(type);
	phalcon_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	
	RETURN_CCTOR(type);
}

/**
 * Sets verbose message
 *
 * @param string $message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setMessage){

	zval *message = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_message"), message TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns verbose message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getMessage){

	zval *message = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(message);
	phalcon_read_property(&message, this_ptr, SL("_message"), PH_NOISY_CC);
	
	RETURN_CCTOR(message);
}

/**
 * Sets field name related to message
 *
 * @param string $field
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, setField){

	zval *field = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &field) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_field"), field TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns field name related to message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, getField){

	zval *field = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(field);
	phalcon_read_property(&field, this_ptr, SL("_field"), PH_NOISY_CC);
	
	RETURN_CCTOR(field);
}

/**
 * Magic __toString method returns verbose message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, __toString){

	zval *message = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(message);
	phalcon_read_property(&message, this_ptr, SL("_message"), PH_NOISY_CC);
	
	RETURN_CCTOR(message);
}

/**
 * Magic __set_state helps to recover messsages from serialization
 *
 * @param array $message
 * @return Phalcon\Mvc\Model\Message
 */
PHP_METHOD(Phalcon_Mvc_Model_Message, __set_state){

	zval *message = NULL, *message_text = NULL, *field = NULL, *type = NULL, *message_object = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(message_text);
	phalcon_array_fetch_string(&message_text, message, SL("_message"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(field);
	phalcon_array_fetch_string(&field, message, SL("_field"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(type);
	phalcon_array_fetch_string(&type, message, SL("_type"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(message_object);
	object_init_ex(message_object, phalcon_mvc_model_message_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(message_object, "__construct", message_text, field, type, PH_CHECK);
	
	RETURN_CTOR(message_object);
}

