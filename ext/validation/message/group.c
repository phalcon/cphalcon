
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

#include "validation/message/group.h"
#include "validation/exception.h"
#include "validation/message.h"
#include "validation/messageinterface.h"

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
zend_class_entry *phalcon_validation_message_group_ce;

PHP_METHOD(Phalcon_Validation_Message_Group, __construct);
PHP_METHOD(Phalcon_Validation_Message_Group, offsetGet);
PHP_METHOD(Phalcon_Validation_Message_Group, offsetSet);
PHP_METHOD(Phalcon_Validation_Message_Group, offsetExists);
PHP_METHOD(Phalcon_Validation_Message_Group, offsetUnset);
PHP_METHOD(Phalcon_Validation_Message_Group, appendMessage);
PHP_METHOD(Phalcon_Validation_Message_Group, appendMessages);
PHP_METHOD(Phalcon_Validation_Message_Group, filter);
PHP_METHOD(Phalcon_Validation_Message_Group, count);
PHP_METHOD(Phalcon_Validation_Message_Group, rewind);
PHP_METHOD(Phalcon_Validation_Message_Group, current);
PHP_METHOD(Phalcon_Validation_Message_Group, key);
PHP_METHOD(Phalcon_Validation_Message_Group, next);
PHP_METHOD(Phalcon_Validation_Message_Group, valid);
PHP_METHOD(Phalcon_Validation_Message_Group, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_appendmessages, 0, 0, 1)
	ZEND_ARG_INFO(0, messages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, fieldName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_message_group___set_state, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_validation_message_group_method_entry[] = {
	PHP_ME(Phalcon_Validation_Message_Group, __construct, arginfo_phalcon_validation_message_group___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Validation_Message_Group, offsetGet, arginfo_phalcon_validation_message_group_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, offsetSet, arginfo_phalcon_validation_message_group_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, offsetExists, arginfo_phalcon_validation_message_group_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, offsetUnset, arginfo_phalcon_validation_message_group_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, appendMessage, arginfo_phalcon_validation_message_group_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, appendMessages, arginfo_phalcon_validation_message_group_appendmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, filter, arginfo_phalcon_validation_message_group_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Message_Group, __set_state, arginfo_phalcon_validation_message_group___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

static zend_object_handlers phalcon_validation_message_group_object_handlers;

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

	position = phalcon_fetch_nproperty_this((zval*)it->data, SL("_position"), PH_NOISY TSRMLS_CC);
	messages = phalcon_fetch_nproperty_this((zval*)it->data, SL("_messages"), PH_NOISY TSRMLS_CC);

	*data = phalcon_hash_get(Z_ARRVAL_P(messages), position, BP_VAR_NA);
}

#if ZEND_MODULE_API_NO >= 20121212
static void phalcon_validation_message_group_get_current_key(zend_object_iterator *it, zval *key TSRMLS_DC)
{
	zval *position;

	position = phalcon_fetch_nproperty_this((zval*)it->data, SL("_position"), PH_NOISY TSRMLS_CC);
	ZVAL_ZVAL(key, position, 1, 0);
}
#else
static int phalcon_validation_message_group_get_current_key(zend_object_iterator *it, char **str_key, uint *str_key_len, ulong *int_key TSRMLS_DC)
{
	zval *position;

	position = phalcon_fetch_nproperty_this((zval*)it->data, SL("_position"), PH_NOISY TSRMLS_CC);
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
	phalcon_validation_message_group_rewind,
	NULL
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

static zval* phalcon_validation_message_group_read_dimension(zval *object, zval *offset, int type TSRMLS_DC)
{
	zval *messages;

	if (!is_phalcon_class(Z_OBJCE_P(object))) {
		return zend_get_std_object_handlers()->read_dimension(object, offset, type TSRMLS_CC);
	}

	if (UNEXPECTED(!offset)) {
		return EG(uninitialized_zval_ptr);
	}

	messages = phalcon_fetch_nproperty_this(object, SL("_messages"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		zval **res = phalcon_hash_get(Z_ARRVAL_P(messages), offset, type);
		return res ? *res : NULL;
	}

	return NULL;
}

static void phalcon_validation_message_group_write_dimension(zval *object, zval *offset, zval *value TSRMLS_DC)
{
	zval *messages;
	int separate;

	if (!is_phalcon_class(Z_OBJCE_P(object))) {
		zend_get_std_object_handlers()->write_dimension(object, offset, value TSRMLS_CC);
		return;
	}

	PHALCON_VERIFY_CLASS_EX(value, phalcon_validation_message_ce, spl_ce_BadMethodCallException, 0);

	messages = phalcon_fetch_nproperty_this(object, SL("_messages"), PH_NOISY TSRMLS_CC);
	separate = phalcon_maybe_separate_zval(&messages);
	if (Z_TYPE_P(messages) != IS_ARRAY) {
		zval_dtor(messages);
		array_init_size(messages, 1);
	}

	Z_ADDREF_P(value);
	phalcon_hash_update_or_insert(Z_ARRVAL_P(messages), offset, value);
	if (separate) {
		Z_DELREF_P(messages);
		phalcon_update_property_this(object, SL("_messages"), messages TSRMLS_CC);
	}
}

static int phalcon_validation_message_group_has_dimension(zval *object, zval *offset, int check_empty TSRMLS_DC)
{
	zval *messages;

	if (!is_phalcon_class(Z_OBJCE_P(object))) {
		return zend_get_std_object_handlers()->has_dimension(object, offset, check_empty TSRMLS_CC);
	}

	messages = phalcon_fetch_nproperty_this(object, SL("_messages"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		zval **tmp = phalcon_hash_get(Z_ARRVAL_P(messages), offset, BP_VAR_NA);

		if (!tmp) {
			return 0;
		}

		if (0 == check_empty) {
			return Z_TYPE_PP(tmp) != IS_NULL;
		}

		if (1 == check_empty) {
			return zend_is_true(*tmp);
		}

		return 1;
	}

	return 0;
}

static void phalcon_validation_message_group_unset_dimension(zval *object, zval *offset TSRMLS_DC)
{
	zval *messages;
	int separate;

	if (!is_phalcon_class(Z_OBJCE_P(object))) {
		zend_get_std_object_handlers()->unset_dimension(object, offset TSRMLS_CC);
		return;
	}

	messages = phalcon_fetch_nproperty_this(object, SL("_messages"), PH_NOISY TSRMLS_CC);
	separate = phalcon_maybe_separate_zval(&messages);

	if (Z_TYPE_P(messages) != IS_ARRAY) {
		zval_dtor(messages);
		array_init_size(messages, 0);
	}
	else {
		phalcon_array_unset(&messages, offset, 0);
	}

	if (separate) {
		Z_DELREF_P(messages);
		phalcon_update_property_this(object, SL("_messages"), messages TSRMLS_CC);
	}
}

static int phalcon_validation_message_group_count_elements(zval *object, long int *count TSRMLS_DC)
{
	int res;
	zval *cnt = NULL;

	if (is_phalcon_class(Z_OBJCE_P(object))) {
		zval *messages = phalcon_fetch_nproperty_this(object, SL("_messages"), PH_NOISY TSRMLS_CC);
		*count         = (Z_TYPE_P(messages) == IS_ARRAY) ? zend_hash_num_elements(Z_ARRVAL_P(messages)) : 0;
		return SUCCESS;
	}

	res = phalcon_call_method(&cnt, object, "count", 0, NULL TSRMLS_CC);
	if (res == SUCCESS) {
		*count = (Z_TYPE_P(cnt) == IS_LONG) ? Z_LVAL_P(cnt) : phalcon_get_intval(cnt);
		zval_ptr_dtor(&cnt);
	}

	return res;
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

	phalcon_validation_message_group_object_handlers = *zend_get_std_object_handlers();
	phalcon_validation_message_group_object_handlers.read_dimension  = phalcon_validation_message_group_read_dimension;
	phalcon_validation_message_group_object_handlers.write_dimension = phalcon_validation_message_group_write_dimension;
	phalcon_validation_message_group_object_handlers.has_dimension   = phalcon_validation_message_group_has_dimension;
	phalcon_validation_message_group_object_handlers.unset_dimension = phalcon_validation_message_group_unset_dimension;
	phalcon_validation_message_group_object_handlers.count_elements  = phalcon_validation_message_group_count_elements;

	zend_class_implements(phalcon_validation_message_group_ce TSRMLS_CC, 3, spl_ce_Countable, zend_ce_arrayaccess, zend_ce_iterator);

	return SUCCESS;
}

void phalcon_validation_group_construct_helper(zval *object, zval *messages TSRMLS_DC)
{
	Z_OBJ_HT_P(object) = &phalcon_validation_message_group_object_handlers;

	if (messages && Z_TYPE_P(messages) == IS_ARRAY) {
		phalcon_update_property_this(object, SL("_messages"), messages TSRMLS_CC);
	}
}

/**
 * Phalcon\Validation\Message\Group constructor
 *
 * @param array $messages
 */
PHP_METHOD(Phalcon_Validation_Message_Group, __construct){

	zval **messages = NULL;

	phalcon_fetch_params_ex(0, 1, &messages);
	phalcon_validation_group_construct_helper(getThis(), (messages ? *messages : NULL) TSRMLS_CC);
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

	zval **index, *ret;

	phalcon_fetch_params_ex(1, 0, &index);
	ret = phalcon_validation_message_group_read_dimension(getThis(), *index, BP_VAR_NA TSRMLS_CC);
	if (ret) {
		RETURN_ZVAL(ret, 1, 0);
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

	zval **index, **message;

	phalcon_fetch_params_ex(2, 0, &index, &message);
	phalcon_validation_message_group_write_dimension(getThis(), *index, *message TSRMLS_CC);
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

	zval **index;

	phalcon_fetch_params_ex(1, 0, &index);
	RETURN_BOOL(phalcon_validation_message_group_has_dimension(getThis(), *index, 0 TSRMLS_CC));
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

	zval **index;

	phalcon_fetch_params_ex(1, 0, &index);
	phalcon_validation_message_group_unset_dimension(getThis(), *index TSRMLS_CC);
}

/**
 * Appends a message to the group
 *
 *<code>
 * $messages->appendMessage(new Phalcon\Validation\Message('This is a message'));
 *</code>
 *
 * @param Phalcon\Validation\Message $message
 */
PHP_METHOD(Phalcon_Validation_Message_Group, appendMessage){

	zval *message;

	phalcon_fetch_params(0, 1, 0, &message);
	PHALCON_VERIFY_INTERFACE_EX(message, phalcon_validation_messageinterface_ce, phalcon_validation_exception_ce, 0);
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

	zval *messages;
	zval *key = NULL, *message = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &messages);
	
	if (Z_TYPE_P(messages) != IS_ARRAY) { 
		if (Z_TYPE_P(messages) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_validation_exception_ce, "The messages must be array or object");
			return;
		}
	}
	
	if (Z_TYPE_P(messages) == IS_ARRAY) { 
		/** 
		 * An array of messages is simply merged into the current one
		 */
		phalcon_is_iterable(messages, &ah0, &hp0, 0, 0);
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(message);

			PHALCON_CALL_SELF(NULL, "appendmessage", message);

			zend_hash_move_forward_ex(ah0, &hp0);
		}
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
			zval *params[1];
	
			it->funcs->get_current_data(it, &message TSRMLS_CC);
			if (!EG(exception)) {
				params[0] = *message;
				if (FAILURE == phalcon_call_method(NULL, this_ptr, "appendmessage", 1, params TSRMLS_CC)) {
					break;
				}
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
	phalcon_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY TSRMLS_CC);
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
				PHALCON_CALL_METHOD(&field, message, "getfield");
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

	long int count;

	if (SUCCESS == phalcon_validation_message_group_count_elements(getThis(), &count TSRMLS_CC)) {
		RETURN_LONG(count);
	}

	RETURN_NULL();
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

	zval **group, *messages;

	phalcon_fetch_params_ex(1, 0, &group);

	if (phalcon_array_isset_string_fetch(&messages, *group, SS("_messages"))) {
		object_init_ex(return_value, phalcon_validation_message_group_ce);
		phalcon_validation_group_construct_helper(return_value, messages TSRMLS_CC);
	}
	else {
		zend_throw_exception_ex(spl_ce_BadMethodCallException, 0 TSRMLS_CC, "Invalid arguments passed to %s", "Phalcon\\Mvc\\Model\\Message\\Group::__set_state()");
	}
}
