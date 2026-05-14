
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
 * This file is part of the Phalcon Framework.
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
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, start_zv, end_zv, __$true, result, _0, _1;
	zend_string *text = NULL, *start = NULL, *end = NULL;

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&start_zv);
	ZVAL_UNDEF(&end_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(text)
		Z_PARAM_STR(start)
		Z_PARAM_STR(end)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	zephir_memory_observe(&start_zv);
	ZVAL_STR_COPY(&start_zv, start);
	zephir_memory_observe(&end_zv);
	ZVAL_STR_COPY(&end_zv, end);
	ZEPHIR_CALL_FUNCTION(&result, "mb_strstr", NULL, 0, &text_zv, &start_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "");
	} else {
		ZEPHIR_CPY_WRT(&_0, &result);
	}
	ZEPHIR_CPY_WRT(&result, &_0);
	ZEPHIR_CALL_FUNCTION(&_1, "mb_strstr", NULL, 0, &result, &end_zv, &__$true);
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
	ZEPHIR_CONCAT_VV(&_2, &start_zv, &end_zv);
	zephir_fast_trim(return_value, &result, &_2, ZEPHIR_TRIM_BOTH);
	RETURN_MM();
}

