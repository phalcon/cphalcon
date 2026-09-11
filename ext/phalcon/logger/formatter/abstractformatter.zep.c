
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class AbstractFormatter
 *
 * @phpstan-import-type logger_context from LoggerTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_AbstractFormatter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger\\Formatter, AbstractFormatter, phalcon, logger_formatter_abstractformatter, phalcon_logger_formatter_abstractformatter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Default date format
	 */
	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "c", sizeof("c") - 1);
		zephir_declare_typed_property(phalcon_logger_formatter_abstractformatter_ce, SL("dateFormat"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "%", sizeof("%") - 1);
		zephir_declare_typed_property(phalcon_logger_formatter_abstractformatter_ce, SL("interpolatorLeft"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "%", sizeof("%") - 1);
		zephir_declare_typed_property(phalcon_logger_formatter_abstractformatter_ce, SL("interpolatorRight"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	zend_class_implements(phalcon_logger_formatter_abstractformatter_ce, 1, phalcon_logger_formatter_formatterinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, getDateFormat)
{

	RETURN_MEMBER_TYPED(getThis(), "dateFormat", IS_STRING);
}

PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, setDateFormat)
{
	zval format_zv;
	zend_string *format = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&format_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dateFormat", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(format)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&format_zv, format);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 231, &format_zv);
}

/**
 * Returns the date formatted for the logger.
 *
 * @param Item $item
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, getFormattedDate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dateFormat", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &item);
	ZEPHIR_CALL_METHOD(&_0, item, "getdatetime", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 231, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "format", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the interpolated message, replacing context placeholders.
 *
 * @param Item   $item
 * @param string $message
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, getInterpolatedMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *message = NULL;
	zval *item, item_sub, message_zv, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("interpolatorLeft", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("interpolatorRight", 17, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_logger_item_ce)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	item = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	ZEPHIR_CALL_METHOD(&_1, item, "getcontext", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "stringifycontext", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 232, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 233, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "tointerpolate", NULL, 0, &message_zv, &_0, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Reduces the log context to the string map interpolation requires.
 *
 * Log context is PSR-3 shaped, so its values are arbitrary, while
 * interpolation replaces a placeholder with a string. Anything that
 * cannot be expressed as one - an array, an object without
 * `__toString()` - substitutes as an empty string, so a placeholder is
 * never left dangling and a non-stringable value can never abort the
 * formatter mid-log.
 *
 * @phpstan-param logger_context $context
 *
 * @return array<string, string>
 */
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, stringifyContext)
{
	zval _5$$4, _11$$7;
	zend_bool _8, _3$$3, _4$$3, _9$$6, _10$$6;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *context_param = NULL, key, value, *_0, _7, _6$$5, _12$$8;
	zval context, result;

	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_11$$7);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(context, context_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &context_param);
	zephir_get_arrval(&context, context_param);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&context, 0, "phalcon/Logger/Formatter/AbstractFormatter.zep", 106);
	if (Z_TYPE_P(&context) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&context), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			_3$$3 = zephir_is_scalar(&value);
			if (!(_3$$3)) {
				_4$$3 = Z_TYPE_P(&value) == IS_OBJECT;
				if (_4$$3) {
					_4$$3 = zephir_is_instance_of(&value, SL("Stringable"));
				}
				_3$$3 = _4$$3;
			}
			if (_3$$3) {
				zephir_cast_to_string(&_5$$4, &value);
				zephir_array_update_zval(&result, &key, &_5$$4, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZVAL_STRING(&_6$$5, "");
				zephir_array_update_zval(&result, &key, &_6$$5, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &context, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &context, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, &context, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &context, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &context, "current", NULL, 0);
			zephir_check_call_status();
				_9$$6 = zephir_is_scalar(&value);
				if (!(_9$$6)) {
					_10$$6 = Z_TYPE_P(&value) == IS_OBJECT;
					if (_10$$6) {
						_10$$6 = zephir_is_instance_of(&value, SL("Stringable"));
					}
					_9$$6 = _10$$6;
				}
				if (_9$$6) {
					zephir_cast_to_string(&_11$$7, &value);
					zephir_array_update_zval(&result, &key, &_11$$7, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_12$$8);
					ZVAL_STRING(&_12$$8, "");
					zephir_array_update_zval(&result, &key, &_12$$8, PH_COPY | PH_SEPARATE);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&result);
}

/**
 * @param string   $input
 * @param string[] $context
 * @param string   $left
 * @param string   $right
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, toInterpolate)
{
	zend_bool _6;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context, replace;
	zval input_zv, *context_param = NULL, left_zv, right_zv, key, value, _0, *_1, _5, _4$$5, _7$$6;
	zend_string *input = NULL, *left = NULL, *right = NULL, *_3;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&left_zv);
	ZVAL_UNDEF(&right_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&replace);
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(context, context_param)
		Z_PARAM_STR(left)
		Z_PARAM_STR(right)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}
	if (!left) {
		left = zend_string_init(ZEND_STRL("%"), 0);
		zephir_memory_observe(&left_zv);
		ZVAL_STR(&left_zv, left);
	} else {
		zephir_memory_observe(&left_zv);
	ZVAL_STR_COPY(&left_zv, left);
	}
	if (!right) {
		right = zend_string_init(ZEND_STRL("%"), 0);
		zephir_memory_observe(&right_zv);
		ZVAL_STR(&right_zv, right);
	} else {
		zephir_memory_observe(&right_zv);
	ZVAL_STR_COPY(&right_zv, right);
	}
	ZEPHIR_INIT_VAR(&replace);
	array_init(&replace);
	if (ZEPHIR_IS_EMPTY(&context)) {
		RETURN_MM_STR(zend_string_copy(input));
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strpos(&_0, &input_zv, &left_zv, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_STR(zend_string_copy(input));
	}
	zephir_is_iterable(&context, 0, "phalcon/Traits/Support/Helper/Str/InterpolateTrait.zep", 49);
	if (Z_TYPE_P(&context) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&context), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_INIT_NVAR(&_4$$5);
			ZEPHIR_CONCAT_VVV(&_4$$5, &left_zv, &key, &right_zv);
			zephir_array_update_zval(&replace, &_4$$5, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &context, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &context, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &context, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &context, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &context, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$6);
				ZEPHIR_CONCAT_VVV(&_7$$6, &left_zv, &key, &right_zv);
				zephir_array_update_zval(&replace, &_7$$6, &value, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 4, &input_zv, &replace);
	zephir_check_call_status();
	RETURN_MM();
}

