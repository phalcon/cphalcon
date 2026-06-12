
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
#include "kernel/memory.h"
#include "kernel/operators.h"
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
/**
 * Interpolates context values into the message placeholders. By default, the
 * right and left tokens are `%`
 *
 * @see https://www.php-fig.org/psr/psr-3/ Section 1.2 Message
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Interpolate)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, Interpolate, phalcon, support_helper_str_interpolate, phalcon_support_helper_str_interpolate_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $message
 * @param array  $context
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Interpolate, __invoke)
{
	zend_bool _5$$3;
	zend_ulong _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context, replace;
	zval message_zv, *context_param = NULL, leftToken_zv, rightToken_zv, key, value, *_0$$3, _4$$3, _3$$4, _6$$5;
	zend_string *message = NULL, *leftToken = NULL, *rightToken = NULL, *_2$$3;

	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&leftToken_zv);
	ZVAL_UNDEF(&rightToken_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&replace);
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(message)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(context, context_param)
		Z_PARAM_STR(leftToken)
		Z_PARAM_STR(rightToken)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&message_zv);
	ZVAL_STR_COPY(&message_zv, message);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}
	if (!leftToken) {
		leftToken = zend_string_init(ZEND_STRL("%"), 0);
		zephir_memory_observe(&leftToken_zv);
		ZVAL_STR(&leftToken_zv, leftToken);
	} else {
		zephir_memory_observe(&leftToken_zv);
	ZVAL_STR_COPY(&leftToken_zv, leftToken);
	}
	if (!rightToken) {
		rightToken = zend_string_init(ZEND_STRL("%"), 0);
		zephir_memory_observe(&rightToken_zv);
		ZVAL_STR(&rightToken_zv, rightToken);
	} else {
		zephir_memory_observe(&rightToken_zv);
	ZVAL_STR_COPY(&rightToken_zv, rightToken);
	}
	if (!(ZEPHIR_IS_EMPTY(&context))) {
		ZEPHIR_INIT_VAR(&replace);
		array_init(&replace);
		zephir_is_iterable(&context, 0, "phalcon/Support/Helper/Str/Interpolate.zep", 41);
		if (Z_TYPE_P(&context) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&context), _1$$3, _2$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_2$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _2$$3);
				} else {
					ZVAL_LONG(&key, _1$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _0$$3);
				ZEPHIR_INIT_NVAR(&_3$$4);
				ZEPHIR_CONCAT_VVV(&_3$$4, &leftToken_zv, &key, &rightToken_zv);
				zephir_array_update_zval(&replace, &_3$$4, &value, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &context, "rewind", NULL, 0);
			zephir_check_call_status();
			_5$$3 = 1;
			while (1) {
				if (_5$$3) {
					_5$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &context, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_4$$3, &context, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &context, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &context, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_6$$5);
					ZEPHIR_CONCAT_VVV(&_6$$5, &leftToken_zv, &key, &rightToken_zv);
					zephir_array_update_zval(&replace, &_6$$5, &value, PH_COPY | PH_SEPARATE);
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 4, &message_zv, &replace);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_STR(zend_string_copy(message));
}

