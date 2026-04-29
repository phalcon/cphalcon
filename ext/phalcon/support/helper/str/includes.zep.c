
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
#include "kernel/operators.h"
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
 * Determines whether a string includes another string or not.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Includes)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Helper\\Str, Includes, phalcon, support_helper_str_includes, phalcon_support_helper_str_includes_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $haystack
 * @param string $needle
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Helper_Str_Includes, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval haystack_zv, needle_zv, _0;
	zend_string *haystack = NULL, *needle = NULL;

	ZVAL_UNDEF(&haystack_zv);
	ZVAL_UNDEF(&needle_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(haystack)
		Z_PARAM_STR(needle)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&haystack_zv, haystack);
	ZVAL_STR_COPY(&needle_zv, needle);
	ZEPHIR_CALL_FUNCTION(&_0, "mb_strpos", NULL, 93, &haystack_zv, &needle_zv);
	zephir_check_call_status();
	RETURN_MM_BOOL(!ZEPHIR_IS_FALSE_IDENTICAL(&_0));
}

