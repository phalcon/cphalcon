
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
#include "kernel/string.h"
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
 * Converts strings to snake_case style
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_SnakeCase)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Support\\Helper\\Str, SnakeCase, phalcon, support_helper_str_snakecase, phalcon_support_helper_str_pascalcase_ce, phalcon_support_helper_str_snakecase_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string      $text
 * @param string|null $delimiters
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Helper_Str_SnakeCase, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval text_zv, delimiters_zv, output;
	zend_string *text = NULL, *delimiters = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&delimiters_zv);
	ZVAL_UNDEF(&output);
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
	ZEPHIR_CALL_METHOD(&output, this_ptr, "processarray", NULL, 0, &text_zv, &delimiters_zv);
	zephir_check_call_status();
	zephir_fast_join_str(return_value, SL("_"), &output);
	RETURN_MM();
}

