
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Interpolate)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, Interpolate, phalcon, support_helper_str_interpolate, phalcon_support_helper_str_interpolate_method_entry, 0);

	return SUCCESS;
}

/**
 * Interpolates context values into the message placeholders
 *
 * @see http://www.php-fig.org/psr/psr-3/ Section 1.2 Message
 *
 * @param string $message
 * @param array  $context
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Interpolate, __invoke)
{
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context, replace;
	zval *message_param = NULL, *context_param = NULL, *leftToken_param = NULL, *rightToken_param = NULL, key, value, *_0$$3, _1$$3, _4$$4, _5$$5;
	zval message, leftToken, rightToken;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&leftToken);
	ZVAL_UNDEF(&rightToken);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&replace);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
		Z_PARAM_STR(leftToken)
		Z_PARAM_STR(rightToken)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &message_param, &context_param, &leftToken_param, &rightToken_param);
	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}
	if (!leftToken_param) {
		ZEPHIR_INIT_VAR(&leftToken);
		ZVAL_STRING(&leftToken, "%");
	} else {
		zephir_get_strval(&leftToken, leftToken_param);
	}
	if (!rightToken_param) {
		ZEPHIR_INIT_VAR(&rightToken);
		ZVAL_STRING(&rightToken, "%");
	} else {
		zephir_get_strval(&rightToken, rightToken_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&context))) {
		ZEPHIR_INIT_VAR(&replace);
		array_init(&replace);
		zephir_is_iterable(&context, 0, "phalcon/Support/Helper/Str/Interpolate.zep", 39);
		if (Z_TYPE_P(&context) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&context), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _3$$3);
				} else {
					ZVAL_LONG(&key, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				ZEPHIR_INIT_NVAR(&_4$$4);
				ZEPHIR_CONCAT_VVV(&_4$$4, &leftToken, &key, &rightToken);
				zephir_array_update_zval(&replace, &_4$$4, &value, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &context, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &context, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &context, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &context, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_5$$5);
					ZEPHIR_CONCAT_VVV(&_5$$5, &leftToken, &key, &rightToken);
					zephir_array_update_zval(&replace, &_5$$5, &value, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &context, "next", NULL, 0);
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

