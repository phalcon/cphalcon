
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "ext/json/php_json.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Represents a collection of messages
 */
ZEPHIR_INIT_CLASS(Phalcon_Messages_Messages)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Messages, Messages, phalcon, messages_messages, phalcon_messages_messages_method_entry, 0);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_messages_messages_ce, SL("position"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_messages_messages_ce, SL("messages"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_messages_messages_ce, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_messages_messages_ce, 1, zend_ce_countable);
	zend_class_implements(phalcon_messages_messages_ce, 1, zend_ce_iterator);
	zend_class_implements(phalcon_messages_messages_ce, 1, php_json_serializable_ce);
	return SUCCESS;
}

/**
 * Phalcon\Messages\Messages constructor
 */
PHP_METHOD(Phalcon_Messages_Messages, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *messages_param = NULL;
	zval messages;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(messages)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &messages_param);
	if (!messages_param) {
		ZEPHIR_INIT_VAR(&messages);
		array_init(&messages);
	} else {
		zephir_get_arrval(&messages, messages_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("messages"), &messages);
	ZEPHIR_MM_RESTORE();
}

/**
 * Appends a message to the collection
 *
 *```php
 * $messages->appendMessage(
 *     new \Phalcon\Messages\Message("This is a message")
 * );
 *```
 */
PHP_METHOD(Phalcon_Messages_Messages, appendMessage)
{
	zval *message, message_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_messages_messageinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &message);


	zephir_update_property_array_append(this_ptr, SL("messages"), message);
}

/**
 * Appends an array of messages to the collection
 *
 *```php
 * $messages->appendMessages($messagesArray);
 *```
 *
 * @param \Phalcon\Messages\MessageInterface[] messages
 */
PHP_METHOD(Phalcon_Messages_Messages, appendMessages)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages, messages_sub, currentMessages, finalMessages, message, _1$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages_sub);
	ZVAL_UNDEF(&currentMessages);
	ZVAL_UNDEF(&finalMessages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_1$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(messages)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &messages);


	_0 = Z_TYPE_P(messages) != IS_ARRAY;
	if (_0) {
		_0 = Z_TYPE_P(messages) != IS_OBJECT;
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_messages_exception_ce, "The messages must be iterable", "phalcon/Messages/Messages.zep", 69);
		return;
	}
	ZEPHIR_OBS_VAR(&currentMessages);
	zephir_read_property(&currentMessages, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC);
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		if (Z_TYPE_P(&currentMessages) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&finalMessages);
			zephir_fast_array_merge(&finalMessages, &currentMessages, messages);
		} else {
			ZEPHIR_CPY_WRT(&finalMessages, messages);
		}
		zephir_update_property_zval(this_ptr, ZEND_STRL("messages"), &finalMessages);
	} else {
		ZEPHIR_CALL_METHOD(NULL, messages, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1$$7, messages, "valid", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_1$$7))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&message, messages, "current", &_2, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_3, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, messages, "next", &_4, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the number of messages in the list
 */
PHP_METHOD(Phalcon_Messages_Messages, count)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0));
}

/**
 * Returns the current message in the iterator
 */
PHP_METHOD(Phalcon_Messages_Messages, current)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("position"), PH_NOISY_CC);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "phalcon/Messages/Messages.zep", 117);
	RETURN_CTOR(&_1);
}

/**
 * Filters the message collection by field name
 */
PHP_METHOD(Phalcon_Messages_Messages, filter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fieldName_param = NULL, filtered, messages, message, _0, *_1$$3, _2$$3, _3$$5, _4$$8;
	zval fieldName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fieldName);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$8);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(fieldName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fieldName_param);
	if (UNEXPECTED(Z_TYPE_P(fieldName_param) != IS_STRING && Z_TYPE_P(fieldName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'fieldName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(fieldName_param) == IS_STRING)) {
		zephir_get_strval(&fieldName, fieldName_param);
	} else {
		ZEPHIR_INIT_VAR(&fieldName);
	}


	ZEPHIR_INIT_VAR(&filtered);
	array_init(&filtered);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&messages, &_0);
	if (Z_TYPE_P(&messages) == IS_ARRAY) {
		zephir_is_iterable(&messages, 0, "phalcon/Messages/Messages.zep", 145);
		if (Z_TYPE_P(&messages) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&messages), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&message);
				ZVAL_COPY(&message, _1$$3);
				if ((zephir_method_exists_ex(&message, ZEND_STRL("getfield")) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(&_3$$5, &message, "getfield", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_EQUAL(&fieldName, &_3$$5)) {
						zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Messages/Messages.zep", 141);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &messages, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$3, &messages, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&message, &messages, "current", NULL, 0);
				zephir_check_call_status();
					if ((zephir_method_exists_ex(&message, ZEND_STRL("getfield")) == SUCCESS)) {
						ZEPHIR_CALL_METHOD(&_4$$8, &message, "getfield", NULL, 0);
						zephir_check_call_status();
						if (ZEPHIR_IS_EQUAL(&fieldName, &_4$$8)) {
							zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Messages/Messages.zep", 141);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &messages, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&message);
	}
	RETURN_CCTOR(&filtered);
}

/**
 * Returns serialised message objects as array for json_encode. Calls
 * jsonSerialize on each object if present
 *
 *```php
 * $data = $messages->jsonSerialize();
 * echo json_encode($data);
 *```
 */
PHP_METHOD(Phalcon_Messages_Messages, jsonSerialize)
{
	zend_bool _3$$3, _5$$6;
	zval records;
	zval message, _0, *_1, _2, _4$$4, _6$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&records);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Messages/Messages.zep", 174);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_COPY(&message, _1);
			_3$$3 = Z_TYPE_P(&message) == IS_OBJECT;
			if (_3$$3) {
				_3$$3 = (zephir_method_exists_ex(&message, ZEND_STRL("jsonserialize")) == SUCCESS);
			}
			if (_3$$3) {
				ZEPHIR_CALL_METHOD(&_4$$4, &message, "jsonserialize", NULL, 0);
				zephir_check_call_status();
				zephir_array_append(&records, &_4$$4, PH_SEPARATE, "phalcon/Messages/Messages.zep", 168);
			} else {
				zephir_array_append(&records, &message, PH_SEPARATE, "phalcon/Messages/Messages.zep", 170);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&message, &_0, "current", NULL, 0);
			zephir_check_call_status();
				_5$$6 = Z_TYPE_P(&message) == IS_OBJECT;
				if (_5$$6) {
					_5$$6 = (zephir_method_exists_ex(&message, ZEND_STRL("jsonserialize")) == SUCCESS);
				}
				if (_5$$6) {
					ZEPHIR_CALL_METHOD(&_6$$7, &message, "jsonserialize", NULL, 0);
					zephir_check_call_status();
					zephir_array_append(&records, &_6$$7, PH_SEPARATE, "phalcon/Messages/Messages.zep", 168);
				} else {
					zephir_array_append(&records, &message, PH_SEPARATE, "phalcon/Messages/Messages.zep", 170);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&message);
	RETURN_CTOR(&records);
}

/**
 * Returns the current position/key in the iterator
 */
PHP_METHOD(Phalcon_Messages_Messages, key)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "position");
}

/**
 * Moves the internal iteration pointer to the next position
 */
PHP_METHOD(Phalcon_Messages_Messages, next)
{
	zval *this_ptr = getThis();



	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("position")));
}

/**
 * Checks if an index exists
 *
 *```php
 * var_dump(
 *     isset($message["database"])
 * );
 *```
 *
 * @param int index
 */
PHP_METHOD(Phalcon_Messages_Messages, offsetExists)
{
	zval *index, index_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(index)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &index);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, index));
}

/**
 * Gets an attribute a message using the array syntax
 *
 *```php
 * print_r(
 *     $messages[0]
 * );
 *```
 */
PHP_METHOD(Phalcon_Messages_Messages, offsetGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *index, index_sub, message, returnValue, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&returnValue);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(index)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);


	ZEPHIR_INIT_VAR(&returnValue);
	ZVAL_NULL(&returnValue);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&message, &_0, index, 1)) {
		ZEPHIR_CPY_WRT(&returnValue, &message);
	}
	RETURN_CCTOR(&returnValue);
}

/**
 * Sets an attribute using the array-syntax
 *
 *```php
 * $messages[0] = new \Phalcon\Messages\Message("This is a message");
 *```
 *
 * @param \Phalcon\Messages\Message message
 */
PHP_METHOD(Phalcon_Messages_Messages, offsetSet)
{
	zval *index, index_sub, *message, message_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&message_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(index)
		Z_PARAM_ZVAL(message)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &index, &message);


	if (Z_TYPE_P(message) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_messages_exception_ce, "The message must be an object", "phalcon/Messages/Messages.zep", 241);
		return;
	}
	zephir_update_property_array(this_ptr, SL("messages"), index, message);
}

/**
 * Removes a message from the list
 *
 *```php
 * unset($message["database"]);
 *```
 */
PHP_METHOD(Phalcon_Messages_Messages, offsetUnset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index, index_sub, _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(index)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, index)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_2$$3, 1);
		ZEPHIR_MAKE_REF(&_1$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "array_splice", NULL, 407, &_1$$3, index, &_2$$3);
		ZEPHIR_UNREF(&_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Messages_Messages, rewind)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("position"), &_0);
}

/**
 * Check if the current message in the iterator is valid
 */
PHP_METHOD(Phalcon_Messages_Messages, valid)
{
	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("position"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &_1));
}

