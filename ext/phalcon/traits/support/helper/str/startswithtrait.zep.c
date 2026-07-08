
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
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
 * Check if a string starts with a given string
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Support_Helper_Str_StartsWithTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Support\\Helper\\Str, StartsWithTrait, phalcon, traits_support_helper_str_startswithtrait, phalcon_traits_support_helper_str_startswithtrait_method_entry);

	return SUCCESS;
}

/**
 * @param string $haystack
 * @param string $needle
 * @param bool   $ignoreCase
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Traits_Support_Helper_Str_StartsWithTrait, toStartsWith)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ignoreCase;
	zval haystack_zv, needle_zv, *ignoreCase_param = NULL, child, parent, _0;
	zend_string *haystack = NULL, *needle = NULL;

	ZVAL_UNDEF(&haystack_zv);
	ZVAL_UNDEF(&needle_zv);
	ZVAL_UNDEF(&child);
	ZVAL_UNDEF(&parent);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(haystack)
		Z_PARAM_STR(needle)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(ignoreCase)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		ignoreCase_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&haystack_zv);
	ZVAL_STR_COPY(&haystack_zv, haystack);
	zephir_memory_observe(&needle_zv);
	ZVAL_STR_COPY(&needle_zv, needle);
	if (!ignoreCase_param) {
		ignoreCase = 1;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "");
	if (ZEPHIR_IS_IDENTICAL(&_0, &haystack_zv)) {
		RETURN_MM_BOOL(0);
	}
	if (EXPECTED(ignoreCase)) {
		ZEPHIR_CALL_FUNCTION(&child, "mb_strtolower", NULL, 15, &needle_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&parent, "mb_strtolower", NULL, 15, &haystack_zv);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&child, &needle_zv);
		ZEPHIR_CPY_WRT(&parent, &haystack_zv);
	}
	RETURN_MM_BOOL(zephir_start_with(&parent, &child, NULL));
}

