
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
#include "kernel/fcall.h"
#include "kernel/array.h"


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
 *
 * Messages are stored and iterated by integer position. An entry added under a
 * string key through the ArrayAccess interface (for example
 * `$messages["database"] = $message`) stays reachable by that offset but is not
 * visited during iteration (`foreach`), which walks the integer sequence only.
 * Use the append methods (`appendMessage()` / `appendMessages()`) when entries
 * must take part in iteration.
 *
 * @phpstan-import-type messages_list from MessagesTypes
 * @phpstan-import-type messages_serialized from MessagesTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Messages_Messages)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Messages, Messages, phalcon, messages_messages, phalcon_messages_messages_method_entry, 0);

	/**
	 * @var messages_list
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_messages_messages_ce, SL("messages"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_messages_messages_ce, SL("position"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	zend_class_implements(phalcon_messages_messages_ce, 1, phalcon_contracts_messages_messages_ce);
	zend_class_implements(phalcon_messages_messages_ce, 1, php_json_serializable_ce);
	return SUCCESS;
}

/**
 * Phalcon\Messages\Messages constructor
 *
 * @param messages_list $messages
 */
PHP_METHOD(Phalcon_Messages_Messages, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *messages_param = NULL;
	zval messages;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(messages, messages_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &messages_param);
	if (!messages_param) {
		ZEPHIR_INIT_VAR(&messages);
		array_init(&messages);
	} else {
		zephir_get_arrval(&messages, messages_param);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 954, &messages);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_messages_messageinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
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
 * Accepts an array of MessageInterface objects or an Iterator yielding
 * them. The parameter stays untyped so that a non-iterable argument
 * reaches the guard below and raises MessagesNotIterable rather than a
 * TypeError.
 *
 * @param mixed $messages
 *
 * @return void
 * @throws MessagesNotIterable
 */
PHP_METHOD(Phalcon_Messages_Messages, appendMessages)
{
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *messages, messages_sub, currentMessages, finalMessages, message, _2$$3, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages_sub);
	ZVAL_UNDEF(&currentMessages);
	ZVAL_UNDEF(&finalMessages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(messages)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &messages);
	_0 = Z_TYPE_P(messages) != IS_ARRAY;
	if (_0) {
		_1 = Z_TYPE_P(messages) == IS_OBJECT;
		if (_1) {
			_1 = zephir_zval_is_traversable(messages);
		}
		_0 = !(_1);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_messages_exceptions_messagesnotiterable_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Messages/Messages.zep", 85);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&currentMessages);
	zephir_read_property_cached(&currentMessages, this_ptr, _zephir_prop_0, 954, PH_NOISY_CC);
	if (Z_TYPE_P(messages) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&finalMessages);
		zephir_fast_array_merge(&finalMessages, &currentMessages, messages);
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 954, &finalMessages);
	} else {
		ZEPHIR_CALL_METHOD(NULL, messages, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3$$5, messages, "valid", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_3$$5))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&message, messages, "current", &_4, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_5, 0, &message);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, messages, "next", &_6, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Filters the message collection by field name
 *
 * @return messages_list
 */
PHP_METHOD(Phalcon_Messages_Messages, filter)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval fieldName_zv, filtered, messages, message, _0, *_1, _3, _2$$4, _5$$7;
	zend_string *fieldName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fieldName_zv);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_5$$7);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(fieldName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&fieldName_zv);
	ZVAL_STR_COPY(&fieldName_zv, fieldName);
	ZEPHIR_INIT_VAR(&filtered);
	array_init(&filtered);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 954, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&messages, &_0);
	zephir_is_iterable(&messages, 0, "phalcon/Messages/Messages.zep", 139);
	if (Z_TYPE_P(&messages) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&messages), _1)
		{
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_COPY(&message, _1);
			if ((zephir_method_exists_ex(&message, ZEND_STRL("getfield")) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&_2$$4, &message, "getfield", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_EQUAL(&fieldName_zv, &_2$$4)) {
					zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Messages/Messages.zep", 134);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &messages, "rewind", NULL, 0);
		zephir_check_call_status();
		_4 = 1;
		while (1) {
			if (_4) {
				_4 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &messages, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_3, &messages, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&message, &messages, "current", NULL, 0);
			zephir_check_call_status();
				if ((zephir_method_exists_ex(&message, ZEND_STRL("getfield")) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(&_5$$7, &message, "getfield", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_EQUAL(&fieldName_zv, &_5$$7)) {
						zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/Messages/Messages.zep", 134);
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&message);
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
 *
 * @return messages_serialized
 */
PHP_METHOD(Phalcon_Messages_Messages, jsonSerialize)
{
	zend_bool _5;
	zval records;
	zval message, _0, *_1, _4, _2$$3, _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&records);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 954, PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Messages/Messages.zep", 162);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_COPY(&message, _1);
			ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "checkserializable", &_3, 0, &message);
			zephir_check_call_status();
			zephir_array_append(&records, &_2$$3, PH_SEPARATE, "phalcon/Messages/Messages.zep", 159);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_4, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&message, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "checkserializable", &_3, 0, &message);
				zephir_check_call_status();
				zephir_array_append(&records, &_6$$4, PH_SEPARATE, "phalcon/Messages/Messages.zep", 159);
		}
	}
	ZEPHIR_INIT_NVAR(&message);
	RETURN_CTOR(&records);
}

/**
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Messages_Messages, checkSerializable)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub;

	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &value);
	_0 = Z_TYPE_P(value) == IS_OBJECT;
	if (_0) {
		_0 = 1 == (zephir_method_exists_ex(value, ZEND_STRL("jsonserialize")) == SUCCESS);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(value, "jsonserialize", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();
}

/**
 * Returns the number of messages in the list
 *
 * @return int
 */
PHP_METHOD(Phalcon_Messages_Messages, count)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 954, PH_NOISY_CC | PH_READONLY);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("position", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 954, PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&_2);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 955, PH_NOISY_CC);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "phalcon/Messages/Traits/MessagesHelperTrait.zep", 46);
	RETURN_CTOR(&_1);
}

/**
 * Returns the current position/key in the iterator
 */
PHP_METHOD(Phalcon_Messages_Messages, key)
{

	RETURN_MEMBER_TYPED(getThis(), "position", IS_LONG);
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
 */
PHP_METHOD(Phalcon_Messages_Messages, offsetExists)
{
	zval offset_sub, _0;
	zval *offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &offset);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 954, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, offset));
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
	zval offset_sub, message, _0;
	zval *offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &offset);
	zephir_memory_observe(&message);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 954, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&message, &_0, offset, 0)) {
		RETURN_CCTOR(&message);
	}
	RETURN_MM_NULL();
}

/**
 * Sets an attribute using the array-syntax
 *
 *```php
 * $messages[0] = new \Phalcon\Messages\Message("This is a message");
 *```
 *
 * @throws MessageNotObject
 */
PHP_METHOD(Phalcon_Messages_Messages, offsetSet)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval offset_sub, *value, value_sub, _1$$3;
	zval *offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(offset)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &offset, &value);
	_0 = Z_TYPE_P(value) != IS_OBJECT;
	if (!(_0)) {
		_0 = !((zephir_instance_of_ev(value, phalcon_messages_messageinterface_ce)));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_messages_exceptions_messagenotobject_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Messages/Traits/MessagesHelperTrait.zep", 111);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(offset) == IS_NULL) {
		zephir_update_property_array_append(this_ptr, SL("messages"), value);
	} else {
		zephir_update_property_array(this_ptr, SL("messages"), offset, value);
	}
	ZEPHIR_MM_RESTORE();
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
	zval offset_sub, _0, _1$$3, _2$$3;
	zval *offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &offset);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 954, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value(&_0, offset)) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 954, PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_2$$3, 1);
		ZEPHIR_MAKE_REF(&_1$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "array_splice", NULL, 0, &_1$$3, offset, &_2$$3);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("position", 8, 1);
	}
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 955, &_0);
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("messages", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("position", 8, 1);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 954, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 955, PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset_value(&_0, &_1));
}

