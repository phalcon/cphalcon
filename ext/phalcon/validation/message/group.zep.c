
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/iterator.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"


/**
 * Phalcon\Validation\Message\Group
 *
 * Represents a group of validation messages
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Message_Group) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Validation\\Message, Group, phalcon, validation_message_group, phalcon_validation_message_group_method_entry, 0);

	zend_declare_property_null(phalcon_validation_message_group_ce, SL("_position"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_message_group_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_validation_message_group_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(phalcon_validation_message_group_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_validation_message_group_ce TSRMLS_CC, 1, zend_ce_iterator);
	return SUCCESS;

}

/**
 * Phalcon\Validation\Message\Group constructor
 *
 * @param array messages
 */
PHP_METHOD(Phalcon_Validation_Message_Group, __construct) {

	zval *messages = NULL;

	zephir_fetch_params(0, 0, 1, &messages);

	if (!messages) {
		messages = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(messages) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("_messages"), messages TSRMLS_CC);
	}

}

/**
 * Gets an attribute a message using the array syntax
 *
 *<code>
 * print_r($messages[0]);
 *</code>
 *
 * @param int index
 * @return Phalcon\Validation\Message
 */
PHP_METHOD(Phalcon_Validation_Message_Group, offsetGet) {

	zval *index_param = NULL, *message, *_0;
	int index;

	zephir_fetch_params(0, 1, 0, &index_param);

	if (unlikely(Z_TYPE_P(index_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a long/integer") TSRMLS_CC);
		RETURN_NULL();
	}

	index = Z_LVAL_P(index_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	if (zephir_array_isset_long_fetch(&message, _0, index, 1 TSRMLS_CC)) {
		RETURN_CTORW(message);
	}
	RETURN_BOOL(0);

}

/**
 * Sets an attribute using the array-syntax
 *
 *<code>
 * $messages[0] = new \Phalcon\Validation\Message('This is a message');
 *</code>
 *
 * @param int index
 * @param Phalcon\Validation\Message message
 */
PHP_METHOD(Phalcon_Validation_Message_Group, offsetSet) {

	zval *index_param = NULL, *message, *_0;
	int index;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index_param, &message);

	if (unlikely(Z_TYPE_P(index_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a long/integer") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	index = Z_LVAL_P(index_param);


	if (Z_TYPE_P(message) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The message must be an object", "phalcon/validation/message/group.zep", 83);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, index);
	zephir_update_property_array(this_ptr, SL("_messages"), _0, message TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if an index exists
 *
 *<code>
 * var_dump(isset($message['database']));
 *</code>
 *
 * @param int index
 * @return boolean
 */
PHP_METHOD(Phalcon_Validation_Message_Group, offsetExists) {

	zval *index_param = NULL, *_0;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	RETURN_MM_BOOL(zephir_array_isset(_0, index));

}

/**
 * Removes a message from the list
 *
 *<code>
 * unset($message['database']);
 *</code>
 *
 * @param string index
 */
PHP_METHOD(Phalcon_Validation_Message_Group, offsetUnset) {

	zval *index, *_0, *_1;

	zephir_fetch_params(0, 1, 0, &index);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	if (zephir_array_isset(_0, index)) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
		zephir_array_unset(&_1, index, PH_SEPARATE);
	}
	RETURN_BOOL(0);

}

/**
 * Appends a message to the group
 *
 *<code>
 * $messages->appendMessage(new \Phalcon\Validation\Message('This is a message'));
 *</code>
 */
PHP_METHOD(Phalcon_Validation_Message_Group, appendMessage) {

	zval *message;

	zephir_fetch_params(0, 1, 0, &message);



	zephir_update_property_array_append(this_ptr, SL("_messages"), message TSRMLS_CC);

}

/**
 * Appends an array of messages to the group
 *
 *<code>
 * $messages->appendMessages($messagesArray);
 *</code>
 *
 * @param Phalcon\Validation\MessageInterface[] messages
 */
PHP_METHOD(Phalcon_Validation_Message_Group, appendMessages) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_object_iterator *_1;
	zend_bool _0;
	zval *messages, *currentMessages, *finalMessages = NULL, *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &messages);



	_0 = Z_TYPE_P(messages) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(messages) != IS_OBJECT;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The messages must be array or object", "phalcon/validation/message/group.zep", 146);
		return;
	}
	ZEPHIR_OBS_VAR(currentMessages);
	zephir_read_property_this(&currentMessages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		if (ZEPHIR_IS_STRING(currentMessages, "array")) {
			ZEPHIR_INIT_VAR(finalMessages);
			zephir_fast_array_merge(finalMessages, &(currentMessages), &(messages) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(finalMessages, messages);
		}
		zephir_update_property_this(this_ptr, SL("_messages"), finalMessages TSRMLS_CC);
	} else {
		_1 = zephir_get_iterator(messages TSRMLS_CC);
		_1->funcs->rewind(_1 TSRMLS_CC);
		for (;_1->funcs->valid(_1 TSRMLS_CC) == SUCCESS && !EG(exception); _1->funcs->move_forward(_1 TSRMLS_CC)) {
			{
				zval **ZEPHIR_TMP_ITERATOR_PTR;
				_1->funcs->get_current_data(_1, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
				ZEPHIR_CPY_WRT(message, (*ZEPHIR_TMP_ITERATOR_PTR));
			}
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_2, 0, message);
			zephir_check_call_status();
		}
		_1->funcs->dtor(_1 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Filters the message group by field name
 *
 * @param string fieldName
 * @return array
 */
PHP_METHOD(Phalcon_Validation_Message_Group, filter) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *fieldName_param = NULL, *filtered, *messages, *message = NULL, **_2, *_3 = NULL;
	zval *fieldName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fieldName_param);

	if (unlikely(Z_TYPE_P(fieldName_param) != IS_STRING && Z_TYPE_P(fieldName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'fieldName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(fieldName_param) == IS_STRING)) {
		zephir_get_strval(fieldName, fieldName_param);
	} else {
		ZEPHIR_INIT_VAR(fieldName);
		ZVAL_EMPTY_STRING(fieldName);
	}


	ZEPHIR_INIT_VAR(filtered);
	array_init(filtered);
	ZEPHIR_OBS_VAR(messages);
	zephir_read_property_this(&messages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		zephir_is_iterable(messages, &_1, &_0, 0, 0, "phalcon/validation/message/group.zep", 201);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(message, _2);
			if ((zephir_method_exists_ex(message, SS("getfield") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&_3, message, "getfield", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_EQUAL(fieldName, _3)) {
					zephir_array_append(&filtered, message, PH_SEPARATE, "phalcon/validation/message/group.zep", 196);
				}
			}
		}
	}
	RETURN_CCTOR(filtered);

}

/**
 * Returns the number of messages in the list
 */
PHP_METHOD(Phalcon_Validation_Message_Group, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Validation_Message_Group, rewind) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("_position"), _0 TSRMLS_CC);

}

/**
 * Returns the current message in the iterator
 *
 * @return Phalcon\Validation\Message
 */
PHP_METHOD(Phalcon_Validation_Message_Group, current) {

	zval *message, *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_position"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&message, _0, _1, 1 TSRMLS_CC)) {
		RETURN_CTORW(message);
	}
	RETURN_BOOL(0);

}

/**
 * Returns the current position/key in the iterator
 */
PHP_METHOD(Phalcon_Validation_Message_Group, key) {


	RETURN_MEMBER(this_ptr, "_position");

}

/**
 * Moves the internal iteration pointer to the next position
 */
PHP_METHOD(Phalcon_Validation_Message_Group, next) {


	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_position") TSRMLS_CC));

}

/**
 * Check if the current message in the iterator is valid
 */
PHP_METHOD(Phalcon_Validation_Message_Group, valid) {

	zval *_0, *_1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_position"), PH_NOISY_CC);
	RETURN_BOOL(zephir_array_isset(_0, _1));

}

/**
 * Magic __set_state helps to re-build messages variable when exporting
 *
 * @param array group
 * @return Phalcon\Validation\Message\Group
 */
PHP_METHOD(Phalcon_Validation_Message_Group, __set_state) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *group, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);



	object_init_ex(return_value, phalcon_validation_message_group_ce);
	zephir_array_fetch_string(&_0, group, SL("_messages"), PH_NOISY | PH_READONLY, "phalcon/validation/message/group.zep", 268 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 173, _0);
	zephir_check_call_status();
	RETURN_MM();

}

