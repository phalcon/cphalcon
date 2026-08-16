
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Trait MessagesHelperTrait
 *
 * @phpstan-import-type messages_list from MessagesTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Messages_Traits_MessagesHelperTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Messages\\Traits, MessagesHelperTrait, phalcon, messages_traits_messageshelpertrait, phalcon_messages_traits_messageshelpertrait_method_entry);

	/**
	 * @var messages_list
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_messages_traits_messageshelpertrait_ce, SL("messages"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_messages_traits_messageshelpertrait_ce, SL("position"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_LONG, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Returns the number of messages in the list
 *
 * @return int
 */
PHP_METHOD(Phalcon_Messages_Traits_MessagesHelperTrait, count)
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
PHP_METHOD(Phalcon_Messages_Traits_MessagesHelperTrait, current)
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
PHP_METHOD(Phalcon_Messages_Traits_MessagesHelperTrait, key)
{

	RETURN_MEMBER_TYPED(getThis(), "position", IS_LONG);
}

/**
 * Moves the internal iteration pointer to the next position
 */
PHP_METHOD(Phalcon_Messages_Traits_MessagesHelperTrait, next)
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
PHP_METHOD(Phalcon_Messages_Traits_MessagesHelperTrait, offsetExists)
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
PHP_METHOD(Phalcon_Messages_Traits_MessagesHelperTrait, offsetGet)
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
PHP_METHOD(Phalcon_Messages_Traits_MessagesHelperTrait, offsetSet)
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
PHP_METHOD(Phalcon_Messages_Traits_MessagesHelperTrait, offsetUnset)
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
PHP_METHOD(Phalcon_Messages_Traits_MessagesHelperTrait, rewind)
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
PHP_METHOD(Phalcon_Messages_Traits_MessagesHelperTrait, valid)
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

