
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Check if a string ends with a given string
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_EndsWith)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Support\\Helper\\Str, EndsWith, phalcon, support_helper_str_endswith, phalcon_support_helper_str_abstractstr_ce, phalcon_support_helper_str_endswith_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $haystack
 * @param string $needle
 * @param bool   $ignoreCase
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Helper_Str_EndsWith, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ignoreCase;
	zval haystack_zv, needle_zv, *ignoreCase_param = NULL, _0;
	zend_string *haystack = NULL, *needle = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&haystack_zv);
	ZVAL_UNDEF(&needle_zv);
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
	if (ignoreCase) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toendswith", NULL, 0, &haystack_zv, &needle_zv, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

