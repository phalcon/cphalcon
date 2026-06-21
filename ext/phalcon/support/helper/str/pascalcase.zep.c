
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
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Converts strings to PascalCase style
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_PascalCase)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, PascalCase, phalcon, support_helper_str_pascalcase, phalcon_support_helper_str_pascalcase_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string      $text
 * @param string|null $delimiters
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_PascalCase, __invoke)
{
	zend_bool _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, delimiters_zv, exploded, output, element, *_0, _5, _1$$3, _2$$3, _4$$3, _7$$4, _8$$4, _9$$4;
	zend_string *text = NULL, *delimiters = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&delimiters_zv);
	ZVAL_UNDEF(&exploded);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(delimiters)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	if (!delimiters) {
		ZEPHIR_INIT_VAR(&delimiters_zv);
	} else {
		zephir_memory_observe(&delimiters_zv);
	ZVAL_STR_COPY(&delimiters_zv, delimiters);
	}
	ZEPHIR_CALL_METHOD(&exploded, this_ptr, "processarray", NULL, 0, &text_zv, &delimiters_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	zephir_is_iterable(&exploded, 0, "phalcon/Support/Helper/Str/PascalCase.zep", 37);
	if (Z_TYPE_P(&exploded) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&exploded), _0)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _0);
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZEPHIR_CALL_FUNCTION(&_2$$3, "mb_strtolower", &_3, 15, &element);
			zephir_check_call_status();
			zephir_ucfirst(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZEPHIR_CONCAT_VV(&_4$$3, &output, &_1$$3);
			ZEPHIR_CPY_WRT(&output, &_4$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &exploded, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &exploded, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &exploded, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&element, &exploded, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZEPHIR_CALL_FUNCTION(&_8$$4, "mb_strtolower", &_3, 15, &element);
				zephir_check_call_status();
				zephir_ucfirst(&_7$$4, &_8$$4);
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZEPHIR_CONCAT_VV(&_9$$4, &output, &_7$$4);
				ZEPHIR_CPY_WRT(&output, &_9$$4);
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	RETURN_CCTOR(&output);
}

/**
 * @param string      $text
 * @param string|null $delimiters
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Helper_Str_PascalCase, processArray)
{
	zval _6$$4, _8$$4;
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval delimiters, _10, _9$$4;
	zval text_zv, *delimiters_param = NULL, result, _0, _1, _3, _4, _11, _12, _13, _5$$4, _7$$4;
	zend_string *text = NULL;

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&delimiters);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(delimiters_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		delimiters_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	if (!delimiters_param) {
		ZEPHIR_INIT_VAR(&delimiters);
	} else {
		zephir_get_strval(&delimiters, delimiters_param);
	}
	if (ZEPHIR_IS_NULL(&delimiters)) {
		ZEPHIR_INIT_NVAR(&delimiters);
		ZVAL_STRING(&delimiters, "-_");
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\-");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &delimiters, &_0, 0 );
	_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_1);
	if (!(_2)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "-");
		ZEPHIR_INIT_VAR(&_4);
		zephir_fast_strpos(&_4, &delimiters, &_3, 0 );
		_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_4);
	}
	if (_2) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_INIT_VAR(&_6$$4);
		zephir_create_array(&_6$$4, 2, 0);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "\\-");
		zephir_array_fast_append(&_6$$4, &_7$$4);
		ZEPHIR_INIT_NVAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "-");
		zephir_array_fast_append(&_6$$4, &_7$$4);
		ZEPHIR_INIT_VAR(&_8$$4);
		zephir_create_array(&_8$$4, 2, 0);
		ZEPHIR_INIT_NVAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "");
		zephir_array_fast_append(&_8$$4, &_7$$4);
		ZEPHIR_INIT_NVAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "");
		zephir_array_fast_append(&_8$$4, &_7$$4);
		zephir_fast_str_replace(&_5$$4, &_6$$4, &_8$$4, &delimiters);
		zephir_get_strval(&delimiters, &_5$$4);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZEPHIR_CONCAT_SV(&_9$$4, "-", &delimiters);
		ZEPHIR_CPY_WRT(&delimiters, &_9$$4);
	}
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_SVS(&_10, "/[", &delimiters, "]+/");
	ZVAL_LONG(&_11, -1);
	ZVAL_LONG(&_12, (2 | 1));
	ZEPHIR_CALL_FUNCTION(&result, "preg_split", NULL, 142, &_10, &text_zv, &_11, &_12);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_13);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
		ZEPHIR_INIT_NVAR(&_13);
		array_init(&_13);
	} else {
		ZEPHIR_CPY_WRT(&_13, &result);
	}
	RETURN_CCTOR(&_13);
}

