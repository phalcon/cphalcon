
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
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
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
 * Converts strings to upperCamelCase or lowerCamelCase
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Support_Helper_Str_CamelizeTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Support\\Helper\\Str, CamelizeTrait, phalcon, traits_support_helper_str_camelizetrait, phalcon_traits_support_helper_str_camelizetrait_method_entry);

	return SUCCESS;
}

/**
 * @param string $text
 * @param string $delimiters
 * @param bool   $lowerFirst
 *
 * @return string
 */
PHP_METHOD(Phalcon_Traits_Support_Helper_Str_CamelizeTrait, toCamelize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool lowerFirst;
	zval text_zv, delimiters_zv, *lowerFirst_param = NULL, result, _0$$3;
	zend_string *text = NULL, *delimiters = NULL;

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&delimiters_zv);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(delimiters)
		Z_PARAM_BOOL(lowerFirst)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		lowerFirst_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	if (!delimiters) {
		delimiters = zend_string_init(ZEND_STRL("-_"), 0);
		zephir_memory_observe(&delimiters_zv);
		ZVAL_STR(&delimiters_zv, delimiters);
	} else {
		zephir_memory_observe(&delimiters_zv);
	ZVAL_STR_COPY(&delimiters_zv, delimiters);
	}
	if (!lowerFirst_param) {
		lowerFirst = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&result);
	zephir_camelize(&result, &text_zv, &delimiters_zv);
	if (lowerFirst == 1) {
		ZEPHIR_CALL_FUNCTION(&_0$$3, "lcfirst", NULL, 178, &result);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&result, &_0$$3);
	}
	RETURN_CCTOR(&result);
}

