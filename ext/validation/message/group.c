
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"

/**
 * Phalcon\Validation\Message\Group
 *
 * Represents a group of validation messages
 */


/**
 * Phalcon\Validation\Message\Group initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Message_Group){

	PHALCON_REGISTER_CLASS(Phalcon\\Validation\\Message, Group, validation_message_group, phalcon_validation_message_group_method_entry, 0);

	zend_declare_property_null(phalcon_validation_message_group_ce, SL("_position"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_message_group_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_validation_message_group_ce TSRMLS_CC, 3, spl_ce_Countable, zend_ce_arrayaccess, zend_ce_iterator);

	return SUCCESS;
}

/**
 * Phalcon\Validation\Message\Group constructor
 *
 * @param array $messages
 */
PHP_METHOD(Phalcon_Validation_Message_Group, __construct){

	zval *messages = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &messages) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!messages) {
		PHALCON_INIT_VAR(messages);
	}
	
	if (Z_TYPE_P(messages) == IS_ARRAY) { 
		phalcon_update_property_zval(this_ptr, SL("_messages"), messages TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets an attribute a message using the array syntax
 *
 *<code>
 * print_r($messages[0]);
 *</code>
 *
 * @param string $index
 * @return Phalcon\Validation\Message
 */
PHP_METHOD(Phalcon_Validation_Message_Group, offsetGet){

	zval *index, *messages, *message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (phalcon_array_isset(messages, index)) {
		PHALCON_OBS_VAR(message);
		phalcon_array_fetch(&message, messages, index, PH_NOISY_CC);
		RETURN_CCTOR(message);
	}
	
	RETURN_MM_NULL();
}

/**
 * Sets an attribute using the array-syntax
 *
 *<code>
 * $messages[0] = new Phalcon\Validation\Message('This is a message');
 *</code>
 *
 * @param string $index
 * @param Phalcon\Validation\Message $message
 */
PHP_METHOD(Phalcon_Validation_Message_Group, offsetSet){

	zval *index, *message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &index, &message) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(message) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The message must be an object");
		return;
	}
	phalcon_update_property_array(this_ptr, SL("_messages"), index, message TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if an index exists
 *
 *<code>
 * var_dump(isset($message['database']));
 *</code>
 *
 * @param string $index
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Message_Group, offsetExists){

	zval *index, *messages;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (phalcon_array_isset(messages, index)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Removes a message from the list
 *
 *<code>
 * unset($message['database']);
 *</code>
 *
 * @param string $index
 */
PHP_METHOD(Phalcon_Validation_Message_Group, offsetUnset){

	zval *index;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &index) == FAILURE) {
		RETURN_NULL();
	}

	RETURN_TRUE;
}

/**
 * Appends a message to the group
 *
 *<code>
 * $messages->appendMessage(new Phalcon\Validation\Message('This is a message'));
 *</code>
 *
 * @param Phalcon\Validation\MessageInterface $message
 */
PHP_METHOD(Phalcon_Validation_Message_Group, appendMessage){

	zval *message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(message) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The message must be an object");
		return;
	}
	phalcon_update_property_array_append(this_ptr, SL("_messages"), message TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Appends an array of messages to the group
 *
 *<code>
 * $messages->appendMessages($messagesArray);
 *</code>
 *
 * @param Phalcon\Validation\MessageInterface[] $messages
 */
PHP_METHOD(Phalcon_Validation_Message_Group, appendMessages){

	zval *messages, *current_messages, *final_messages = NULL;
	zval *message = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &messages) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(messages) != IS_ARRAY) { 
		if (Z_TYPE_P(messages) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The messages must be array or object");
			return;
		}
	}
	
	PHALCON_OBS_VAR(current_messages);
	phalcon_read_property_this(&current_messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(messages) == IS_ARRAY) { 
	
		/** 
		 * An array of messages is simply merged into the current one
		 */
		if (Z_TYPE_P(current_messages) == IS_ARRAY) { 
			PHALCON_INIT_VAR(final_messages);
			phalcon_fast_array_merge(final_messages, &current_messages, &messages TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(final_messages, messages);
		}
		phalcon_update_property_zval(this_ptr, SL("_messages"), final_messages TSRMLS_CC);
	} else {
		/** 
		 * A group of messages is iterated and appended one-by-one to the current list
		 */
		PHALCON_CALL_METHOD_NORETURN(messages, "rewind");
	
		while (1) {
	
			PHALCON_INIT_NVAR(r0);
			PHALCON_CALL_METHOD(r0, messages, "valid");
			if (PHALCON_IS_NOT_FALSE(r0)) {
			} else {
				break;
			}
	
			PHALCON_INIT_NVAR(message);
			PHALCON_CALL_METHOD(message, messages, "current");
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "appendmessage", message);
			PHALCON_CALL_METHOD_NORETURN(messages, "next");
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the number of messages in the list
 *
 * @return int
 */
PHP_METHOD(Phalcon_Validation_Message_Group, count){

	zval *messages, *number;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number);
	phalcon_fast_count(number, messages TSRMLS_CC);
	RETURN_NCTOR(number);
}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Validation_Message_Group, rewind){


	phalcon_update_property_long(this_ptr, SL("_position"), 0 TSRMLS_CC);
	
}

/**
 * Returns the current message in the iterator
 *
 * @return Phalcon\Validation\Message
 */
PHP_METHOD(Phalcon_Validation_Message_Group, current){

	zval *position, *messages, *message;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(position);
	phalcon_read_property_this(&position, this_ptr, SL("_position"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (phalcon_array_isset(messages, position)) {
		PHALCON_OBS_VAR(message);
		phalcon_array_fetch(&message, messages, position, PH_NOISY_CC);
		RETURN_CCTOR(message);
	}
	
	RETURN_MM_NULL();
}

/**
 * Returns the current position/key in the iterator
 *
 * @return int
 */
PHP_METHOD(Phalcon_Validation_Message_Group, key){


	RETURN_MEMBER(this_ptr, "_position");
}

/**
 * Moves the internal iteration pointer to the next position
 *
 */
PHP_METHOD(Phalcon_Validation_Message_Group, next){


	phalcon_property_incr(this_ptr, SL("_position") TSRMLS_CC);
	
}

/**
 * Check if the current message the iterator is valid
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Message_Group, valid){

	zval *position, *messages;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(position);
	phalcon_read_property_this(&position, this_ptr, SL("_position"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (phalcon_array_isset(messages, position)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Magic __set_state helps to re-build messages variable exporting
 *
 * @param array $group
 * @return Phalcon\Mvc\Model\Message\Group
 */
PHP_METHOD(Phalcon_Validation_Message_Group, __set_state){

	zval *group, *messages, *group_object;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &group) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(messages);
	phalcon_array_fetch_string(&messages, group, SL("_messages"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(group_object);
	object_init_ex(group_object, phalcon_validation_message_group_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(group_object, "__construct", messages);
	
	RETURN_CTOR(group_object);
}

