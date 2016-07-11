
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
#include "kernel/fcall.h"
#include "kernel/hash.h"


/**
 * Phalcon\Validation\Message\Group
 *
 * Represents a group of validation messages
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Message_Group) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Validation\\Message, Group, phalcon, validation_message_group, phalcon_validation_message_group_method_entry, 0);

	zend_declare_property_long(phalcon_validation_message_group_ce, SL("_position"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_message_group_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_validation_message_group_ce->create_object = zephir_init_properties_Phalcon_Validation_Message_Group;

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
 * @return \Phalcon\Validation\Message
 */
PHP_METHOD(Phalcon_Validation_Message_Group, offsetGet) {

	zval *index_param = NULL, *message = NULL, *_0;
	int index;

	zephir_fetch_params(0, 1, 0, &index_param);

	if (unlikely(Z_TYPE_P(index_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a int") TSRMLS_CC);
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
 * @param \Phalcon\Validation\Message message
 */
PHP_METHOD(Phalcon_Validation_Message_Group, offsetSet) {

	zval *index_param = NULL, *message, *_0;
	int index;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index_param, &message);

	if (unlikely(Z_TYPE_P(index_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	index = Z_LVAL_P(index_param);


	if (Z_TYPE_P(message) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The message must be an object", "phalcon/validation/message/group.zep", 82);
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

	zval *index, *_0, *_1$$3;

	zephir_fetch_params(0, 1, 0, &index);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	if (zephir_array_isset(_0, index)) {
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
		zephir_array_unset(&_1$$3, index, PH_SEPARATE);
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
 * @param \Phalcon\Validation\MessageInterface[] messages
 */
PHP_METHOD(Phalcon_Validation_Message_Group, appendMessages) {

	zend_bool _0;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *messages, *currentMessages = NULL, *finalMessages = NULL, *message = NULL, *_1$$7 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &messages);



	_0 = Z_TYPE_P(messages) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(messages) != IS_OBJECT;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The messages must be array or object", "phalcon/validation/message/group.zep", 145);
		return;
	}
	ZEPHIR_OBS_VAR(currentMessages);
	zephir_read_property_this(&currentMessages, this_ptr, SL("_messages"), PH_NOISY_CC);
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		if (Z_TYPE_P(currentMessages) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(finalMessages);
			zephir_fast_array_merge(finalMessages, &(currentMessages), &(messages) TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(finalMessages, messages);
		}
		zephir_update_property_this(this_ptr, SL("_messages"), finalMessages TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(NULL, messages, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1$$7, messages, "valid", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(_1$$7))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&message, messages, "current", &_2, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_3, 0, message);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, messages, "next", &_4, 0);
			zephir_check_call_status();
		}
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

	HashTable *_1$$3;
	HashPosition _0$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *fieldName_param = NULL, *filtered = NULL, *messages = NULL, *message = NULL, **_2$$3, *_3$$5 = NULL;
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
		zephir_is_iterable(messages, &_1$$3, &_0$$3, 0, 0, "phalcon/validation/message/group.zep", 207);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(message, _2$$3);
			if ((zephir_method_exists_ex(message, SS("getfield") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&_3$$5, message, "getfield", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_EQUAL(fieldName, _3$$5)) {
					zephir_array_append(&filtered, message, PH_SEPARATE, "phalcon/validation/message/group.zep", 203);
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
 */
PHP_METHOD(Phalcon_Validation_Message_Group, current) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("_position"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, _2, PH_NOISY | PH_READONLY, "phalcon/validation/message/group.zep", 233 TSRMLS_CC);
	RETURN_CTOR(_1);

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
 * @return \Phalcon\Validation\Message\Group
 */
PHP_METHOD(Phalcon_Validation_Message_Group, __set_state) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *group, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &group);



	object_init_ex(return_value, phalcon_validation_message_group_ce);
	zephir_array_fetch_string(&_0, group, SL("_messages"), PH_NOISY | PH_READONLY, "phalcon/validation/message/group.zep", 268 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 3, _0);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object_value zephir_init_properties_Phalcon_Validation_Message_Group(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_messages"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("_messages"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

