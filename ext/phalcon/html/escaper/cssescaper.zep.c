
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/filter.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */
/**
 * Escapes a string for use inside a CSS value by replacing non-alphanumeric
 * characters with their hexadecimal escape sequence. Wraps the C-level
 * `phalcon_escape_css` after normalising the input to UTF-32.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Escaper_CssEscaper)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Escaper, CssEscaper, phalcon, html_escaper_cssescaper, phalcon_html_escaper_abstractescaper_ce, phalcon_html_escaper_cssescaper_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper_CssEscaper, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escape", NULL, 0, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper_CssEscaper, escape)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, result, _0;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&input_zv))) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeencoding", NULL, 361, &input_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, this_ptr, "doescapecss", NULL, 362, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&result) != IS_STRING) {
		RETURN_MM_STRING("");
	}
	RETURN_CCTOR(&result);
}

/**
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper_CssEscaper, doEscapeCss)
{
	zval input_zv;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&input_zv, input);
	zephir_escape_css(return_value, &input_zv);
	return;
}

