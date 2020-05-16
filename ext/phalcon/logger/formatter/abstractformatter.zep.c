
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "ext/date/php_date.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Logger_Formatter_AbstractFormatter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Logger\\Formatter, AbstractFormatter, phalcon, logger_formatter_abstractformatter, phalcon_logger_formatter_abstractformatter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Default date format
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_logger_formatter_abstractformatter_ce, SL("dateFormat"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_logger_formatter_abstractformatter_ce, 1, phalcon_logger_formatter_formatterinterface_ce);
	return SUCCESS;

}

/**
 * Default date format
 */
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, getDateFormat) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "dateFormat");

}

/**
 * Default date format
 */
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, setDateFormat) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *dateFormat_param = NULL;
	zval dateFormat;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dateFormat);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dateFormat_param);

	zephir_get_strval(&dateFormat, dateFormat_param);


	zephir_update_property_zval(this_ptr, SL("dateFormat"), &dateFormat);
	RETURN_THIS();

}

/**
 * Interpolates context values into the message placeholders
 *
 * @see http://www.php-fig.org/psr/psr-3/ Section 1.2 Message
 * @param string $message
 * @param array $context
 */
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, interpolate) {

	zend_string *_4$$3;
	zend_ulong _3$$3;
	zend_bool _0;
	zval replace;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *context = NULL, context_sub, __$null, key, value, *_1$$3, _2$$3, _5$$4, _6$$5;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&replace);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context);

	zephir_get_strval(&message, message_param);
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}


	_0 = Z_TYPE_P(context) == IS_ARRAY;
	if (_0) {
		_0 = zephir_fast_count_int(context) > 0;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&replace);
		array_init(&replace);
		zephir_is_iterable(context, 0, "/home/nikos/Work/niden/cphalcon/phalcon/Logger/Formatter/AbstractFormatter.zep", 46);
		if (Z_TYPE_P(context) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(context), _3$$3, _4$$3, _1$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_4$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _4$$3);
				} else {
					ZVAL_LONG(&key, _3$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _1$$3);
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZEPHIR_CONCAT_SVS(&_5$$4, "{", &key, "}");
				zephir_array_update_zval(&replace, &_5$$4, &value, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, context, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$3, context, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, context, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, context, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_6$$5);
					ZEPHIR_CONCAT_SVS(&_6$$5, "{", &key, "}");
					zephir_array_update_zval(&replace, &_6$$5, &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, context, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 5, &message, &replace);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(&message);

}

/**
 * Returns the date formatted for the logger.
 * @todo Not using the set time from the Item since we have interface
 * misalignment which will break semver This will change in the future
 */
PHP_METHOD(Phalcon_Logger_Formatter_AbstractFormatter, getFormattedDate) {

	zval date, timezone, _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&date);
	ZVAL_UNDEF(&timezone);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&timezone, "date_default_timezone_get", NULL, 109);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&date);
	object_init_ex(&date, zephir_get_internal_ce(SL("datetimeimmutable")));
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, php_date_get_timezone_ce());
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &timezone);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "now");
	ZEPHIR_CALL_METHOD(NULL, &date, "__construct", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("dateFormat"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&date, "format", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

