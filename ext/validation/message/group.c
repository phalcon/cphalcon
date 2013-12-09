
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
#include "kernel/hash.h"
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

static void phalcon_validation_message_group_dtor(zend_object_iterator *it TSRMLS_DC)
{
	zval_ptr_dtor((zval**)&it->data);
	efree(it);
}

static int phalcon_validation_message_group_valid(zend_object_iterator *it TSRMLS_DC)
{
	zval *position, *messages;

	position = phalcon_fetch_nproperty_this((zval*)it->data, SL("_position"), PH_NOISY TSRMLS_CC);
	messages = phalcon_fetch_nproperty_this((zval*)it->data, SL("_messages"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(messages, position)) {
		return SUCCESS;
	}

	return FAILURE;
}

static void phalcon_validation_message_group_get_current_data(zend_object_iterator *it, zval ***data TSRMLS_DC)
{
	zval *position, *messages;

	position = phalcon_fetch_nproperty_this((zval*)it->data, SL("_position"), PH_NOISY_CC);
	messages = phalcon_fetch_nproperty_this((zval*)it->data, SL("_messages"), PH_NOISY_CC);

	*data = phalcon_hash_get(Z_ARRVAL_P(messages), position, BP_VAR_NA);
}

#if ZEND_MODULE_API_NO >= 20121212
static void phalcon_validation_message_group_get_current_key(zend_object_iterator *it, zval *key TSRMLS_DC)
{
	zval *position;

	position = phalcon_fetch_nproperty_this((zval*)it->data, SL("_position"), PH_NOISY_CC);
	ZVAL_ZVAL(key, position, 1, 0);
}
#else
static int phalcon_validation_message_group_get_current_key(zend_object_iterator *it, char **str_key, uint *str_key_len, ulong *int_key TSRMLS_DC)
{
	zval *position;

	position = phalcon_fetch_nproperty_this((zval*)it->data, SL("_position"), PH_NOISY_CC);
	*int_key = (IS_LONG == Z_TYPE_P(position)) ? Z_LVAL_P(position) : phalcon_get_intval(position);
	return HASH_KEY_IS_LONG;
}
#endif

static void phalcon_validation_message_group_move_forward(zend_object_iterator *it TSRMLS_DC)
{
	phalcon_property_incr((zval*)it->data, SL("_position") TSRMLS_CC);
}

static void phalcon_validation_message_group_rewind(zend_object_iterator *it TSRMLS_DC)
{
	phalcon_update_property_long((zval*)it->data, SL("_position"), 0 TSRMLS_CC);
}

static zend_object_iterator_funcs phalcon_validation_message_group_iterator_funcs = {
	phalcon_validation_message_group_dtor,
	phalcon_validation_message_group_valid,
	phalcon_validation_message_group_get_current_data,
	phalcon_validation_message_group_get_current_key,
	phalcon_validation_message_group_move_forward,
	phalcon_validation_message_group_rewind
};

static zend_object_iterator* phalcon_validation_message_group_get_iterator(zend_class_entry *ce, zval *object, int by_ref TSRMLS_DC)
{
	zend_object_iterator *result;

	if (by_ref) {
		zend_throw_exception_ex(phalcon_validation_exception_ce, 0 TSRMLS_CC, "Cannot iterate Phalcon\\Validation\\Message\\Group by reference");
		return NULL;
	}

	result = emalloc(sizeof(zend_object_iterator));

	Z_ADDREF_P(object);
	result->data  = object;
	result->funcs = &phalcon_validation_message_group_iterator_funcs;

	return result;
}

/**
 * Phalcon\Validation\Message\Group initializer
 */
PHALCON_INIT_CLASS(Phalcon_Validation_Message_Group){

	PHALCON_REGISTER_CLASS(Phalcon\\Validation\\Message, Group, validation_message_group, phalcon_validation_message_group_method_entry, 0);

	zend_declare_property_null(phalcon_validation_message_group_ce, SL("_position"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_validation_message_group_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_validation_message_group_ce->get_iterator         = phalcon_validation_message_group_get_iterator;
	phalcon_validation_message_group_ce->iterator_funcs.funcs = &phalcon_validation_message_group_iterator_funcs;

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

	phalcon_fetch_params(0, 0, 1, &messages);
	
	if (messages && Z_TYPE_P(messages) == IS_ARRAY) {
		phalcon_update_property_this(this_ptr, SL("_messages"), messages TSRMLS_CC);
	}
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

	phalcon_fetch_params(0, 1, 0, &index);
	
	messages = phalcon_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	if (phalcon_array_isset_fetch(&message, messages, index)) {
		RETURN_ZVAL(message, 1, 0);
	}
	
	RETURN_NULL();
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

	phalcon_fetch_params(0, 2, 0, &index, &message);
	
	if (Z_TYPE_P(message) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_validation_exception_ce, "The message must be an object");
		return;
	}
	phalcon_update_property_array(this_ptr, SL("_messages"), index, message TSRMLS_CC);
	
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

	phalcon_fetch_params(1, 1, 0, &index);
	
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

	zval *index, *messages;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &index);
	
	PHALCON_OBS_VAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (phalcon_array_isset(messages, index)) {
		phalcon_unset_property_array(this_ptr, SL("_messages"), index TSRMLS_CC);
	}
	
	RETURN_MM_FALSE;
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

	phalcon_fetch_params(0, 1, 0, &message);
	
	if (Z_TYPE_P(message) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_validation_exception_ce, "The message must be an object");
		return;
	}
	phalcon_update_property_array_append(this_ptr, SL("_messages"), message TSRMLS_CC);
	
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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &messages);
	
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
		phalcon_update_property_this(this_ptr, SL("_messages"), final_messages TSRMLS_CC);
	} else {
		zend_class_entry *ce     = Z_OBJCE_P(messages);
		zend_object_iterator *it = ce->get_iterator(ce, messages, 0 TSRMLS_CC);

		PHALCON_VERIFY_INTERFACE_EX(messages, zend_ce_iterator, phalcon_validation_exception_ce, 1);

		assert(it != NULL);
		assert(it->funcs->rewind != NULL);
		assert(it->funcs->valid != NULL);
		assert(it->funcs->get_current_data != NULL);
		assert(it->funcs->move_forward != NULL);

		/** 
		 * A group of messages is iterated and appended one-by-one to the current list
		 */
		it->funcs->rewind(it TSRMLS_CC);
		while (!EG(exception) && SUCCESS == it->funcs->valid(it TSRMLS_CC)) {
			zval **message;
	
			it->funcs->get_current_data(it, &message TSRMLS_CC);
			if (!EG(exception)) {
				phalcon_call_method_params(NULL, NULL, this_ptr, SL("appendmessage"), zend_inline_hash_func(SS("appendmessage")) TSRMLS_CC, 1, *message);
			}

			if (!EG(exception)) {
				it->funcs->move_forward(it TSRMLS_CC);
			}
		}

		it->funcs->dtor(it TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Filters the message group by field name
 *
 * @param string $fieldName
 * @return array
 */
PHP_METHOD(Phalcon_Validation_Message_Group, filter){

	zval *field_name, *filtered, *messages, *message = NULL;
	zval *field = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &field_name);
	
	PHALCON_INIT_VAR(filtered);
	array_init(filtered);
	
	PHALCON_OBS_VAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(messages) == IS_ARRAY) { 
	
		/** 
		 * A group of messages is iterated and appended one-by-one to the current list
		 */
		phalcon_is_iterable(messages, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(message);
	
			/** 
			 * Get the field name
			 */
			if (phalcon_method_exists_ex(message, SS("getfield") TSRMLS_CC) == SUCCESS) {
	
				PHALCON_INIT_NVAR(field);
				phalcon_call_method(field, message, "getfield");
				if (PHALCON_IS_EQUAL(field_name, field)) {
					phalcon_array_append(&filtered, message, PH_SEPARATE);
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	RETURN_CTOR(filtered);
}

/**
 * Returns the number of messages in the list
 *
 * @return int
 */
PHP_METHOD(Phalcon_Validation_Message_Group, count){

	zval *messages;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(messages);
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	phalcon_fast_count(return_value, messages TSRMLS_CC);
	RETURN_MM();
}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Validation_Message_Group, rewind){

	zend_object_iterator it;
	it.data = getThis();
	phalcon_validation_message_group_iterator_funcs.rewind(&it TSRMLS_CC);
}

/**
 * Returns the current message in the iterator
 *
 * @return Phalcon\Validation\Message
 */
PHP_METHOD(Phalcon_Validation_Message_Group, current){

	zval **ret;
	zend_object_iterator it;
	it.data = getThis();

	phalcon_validation_message_group_iterator_funcs.get_current_data(&it, &ret TSRMLS_CC);
	if (ret) {
		RETURN_ZVAL(*ret, 1, 0);
	}

	RETURN_NULL();
}

/**
 * Returns the current position/key in the iterator
 *
 * @return int
 */
PHP_METHOD(Phalcon_Validation_Message_Group, key){

	zend_object_iterator it;
	it.data = getThis();
#if ZEND_MODULE_API_NO >= 20121212
	phalcon_validation_message_group_iterator_funcs.get_current_key(&it, return_value TSRMLS_CC);
#else
	{
		char *str_key;
		uint str_key_len;
		ulong int_key;
		if (HASH_KEY_IS_STRING == phalcon_validation_message_group_iterator_funcs.get_current_key(&it, &str_key, &str_key_len, &int_key TSRMLS_CC)) {
			RETURN_STRINGL(str_key, str_key_len-1, 1);
		}

		RETURN_LONG(int_key);
	}
#endif
}

/**
 * Moves the internal iteration pointer to the next position
 *
 */
PHP_METHOD(Phalcon_Validation_Message_Group, next){

	zend_object_iterator it;
	it.data = getThis();
	phalcon_validation_message_group_iterator_funcs.move_forward(&it TSRMLS_CC);
}

/**
 * Check if the current message in the iterator is valid
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Message_Group, valid){

	zend_object_iterator it;
	it.data = getThis();
	RETURN_BOOL(phalcon_validation_message_group_iterator_funcs.valid(&it TSRMLS_CC) == SUCCESS);
}

/**
 * Magic __set_state helps to re-build messages variable when exporting
 *
 * @param array $group
 * @return Phalcon\Mvc\Model\Message\Group
 */
PHP_METHOD(Phalcon_Validation_Message_Group, __set_state){

	zval *group, *messages;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &group);
	
	PHALCON_OBS_VAR(messages);
	phalcon_array_fetch_string(&messages, group, SL("_messages"), PH_NOISY);
	object_init_ex(return_value, phalcon_validation_message_group_ce);
	phalcon_call_method_p1_noret(return_value, "__construct", messages);
	
	RETURN_MM();
}

