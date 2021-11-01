
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Returns the first string there is between the strings from the
 * parameter start and end.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_FirstBetween)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, FirstBetween, phalcon, support_helper_str_firstbetween, phalcon_support_helper_str_firstbetween_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $text
 * @param string $start
 * @param string $end
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_FirstBetween, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *start_param = NULL, *end_param = NULL, __$true, result, _0, _1;
	zval text, start, end, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&start);
	ZVAL_UNDEF(&end);
	ZVAL_UNDEF(&_2);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(text)
		Z_PARAM_STR(start)
		Z_PARAM_STR(end)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &text_param, &start_param, &end_param);
	zephir_get_strval(&text, text_param);
	zephir_get_strval(&start, start_param);
	zephir_get_strval(&end, end_param);


	ZEPHIR_CALL_FUNCTION(&result, "mb_strstr", NULL, 308, &text, &start);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "");
	} else {
		ZEPHIR_CPY_WRT(&_0, &result);
	}
	ZEPHIR_CPY_WRT(&result, &_0);
	ZEPHIR_CALL_FUNCTION(&_1, "mb_strstr", NULL, 308, &result, &end, &__$true);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&result, &_1);
	ZEPHIR_INIT_NVAR(&_0);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "");
	} else {
		ZEPHIR_CPY_WRT(&_0, &result);
	}
	ZEPHIR_CPY_WRT(&result, &_0);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &start, &end);
	zephir_fast_trim(return_value, &result, &_2, ZEPHIR_TRIM_BOTH);
	RETURN_MM();
}

