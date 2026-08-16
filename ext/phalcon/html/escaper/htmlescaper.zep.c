
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"


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
 * Escapes a string for use as HTML body content via `htmlspecialchars`.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Escaper_HtmlEscaper)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Escaper, HtmlEscaper, phalcon, html_escaper_htmlescaper, phalcon_html_escaper_abstractescaper_ce, phalcon_html_escaper_htmlescaper_method_entry, 0);

	return SUCCESS;
}

/**
 * @param string|null $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper_HtmlEscaper, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!input) {
		ZEPHIR_INIT_VAR(&input_zv);
	} else {
		zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escape", NULL, 0, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string|null $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper_HtmlEscaper, escape)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, _0, _1, _2;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("flags", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("encoding", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("doubleEncode", 12, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!input) {
		ZEPHIR_INIT_VAR(&input_zv);
	} else {
		zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	}
	if (Z_TYPE_P(&input_zv) == IS_NULL) {
		RETURN_MM_STRING("");
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 808, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 809, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_2, 810, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("htmlspecialchars", NULL, 0, &input_zv, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

