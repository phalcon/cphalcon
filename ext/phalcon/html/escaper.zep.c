
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
 */
/**
 * Phalcon\Html\Escaper
 *
 * Escapes different kinds of text securing them. By using this component you
 * may prevent XSS attacks.
 *
 * The class is a façade over five per-context escapers (`HtmlEscaper`,
 * `AttributeEscaper`, `CssEscaper`, `JsEscaper`, `UrlEscaper`). Each can be
 * retrieved via the matching `getXxxEscaper()` accessor and substituted via
 * the matching `setXxxEscaper()` setter. The legacy `setEncoding`,
 * `setFlags`, and `setDoubleEncode` continue to fan out to all sub-objects
 * so existing code keeps working.
 *
 * This component only works with UTF-8. The PREG extension needs to be compiled
 * with UTF-8 support.
 *
 *```php
 * $escaper = new \Phalcon\Html\Escaper();
 *
 * $escaped = $escaper->css("font-family: <Verdana>");
 *
 * echo $escaped; // font\2D family\3A \20 \3C Verdana\3E
 *```
 *
 * @property AttributeEscaper $attributeEscaper
 * @property CssEscaper       $cssEscaper
 * @property HtmlEscaper      $htmlEscaper
 * @property JsEscaper        $jsEscaper
 * @property UrlEscaper       $urlEscaper
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Escaper)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html, Escaper, phalcon, html_escaper, phalcon_html_escaper_method_entry, 0);

	/**
	 * @var AttributeEscaper
	 */
	zend_declare_property_null(phalcon_html_escaper_ce, SL("attributeEscaper"), ZEND_ACC_PROTECTED);
	/**
	 * @var CssEscaper
	 */
	zend_declare_property_null(phalcon_html_escaper_ce, SL("cssEscaper"), ZEND_ACC_PROTECTED);
	/**
	 * @var HtmlEscaper
	 */
	zend_declare_property_null(phalcon_html_escaper_ce, SL("htmlEscaper"), ZEND_ACC_PROTECTED);
	/**
	 * @var JsEscaper
	 */
	zend_declare_property_null(phalcon_html_escaper_ce, SL("jsEscaper"), ZEND_ACC_PROTECTED);
	/**
	 * @var UrlEscaper
	 */
	zend_declare_property_null(phalcon_html_escaper_ce, SL("urlEscaper"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_html_escaper_ce, 1, phalcon_html_escaper_escaperinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Html_Escaper, __construct)
{
	zval _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_html_escaper_attributeescaper_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("attributeEscaper"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_html_escaper_cssescaper_ce);
	if (zephir_has_constructor(&_1)) {
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("cssEscaper"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_html_escaper_htmlescaper_ce);
	if (zephir_has_constructor(&_2)) {
		ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("htmlEscaper"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, phalcon_html_escaper_jsescaper_ce);
	if (zephir_has_constructor(&_3)) {
		ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("jsEscaper"), &_3);
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, phalcon_html_escaper_urlescaper_ce);
	if (zephir_has_constructor(&_4)) {
		ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("urlEscaper"), &_4);
	ZEPHIR_MM_RESTORE();
}

/**
 * Escapes a HTML attribute string or array. Delegates to the configured
 * `AttributeEscaper`.
 *
 * @param array|string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, attributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input, input_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &input);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributeEscaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "escape", NULL, 0, input);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Escape CSS strings. Delegates to the configured `CssEscaper`.
 *
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, css)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, _0;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&input_zv, input);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("cssEscaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "escape", NULL, 0, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $input
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Html_Escaper, detectEncoding)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, _0;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&input_zv, input);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("htmlEscaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "detectencoding", NULL, 0, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $input
 *
 * @return string
 * @deprecated
 */
PHP_METHOD(Phalcon_Html_Escaper, escapeCss)
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
	ZVAL_STR_COPY(&input_zv, input);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "css", NULL, 0, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $input
 *
 * @return string
 * @deprecated
 */
PHP_METHOD(Phalcon_Html_Escaper, escapeJs)
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
	ZVAL_STR_COPY(&input_zv, input);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "js", NULL, 0, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string|null $input
 *
 * @return string
 * @deprecated
 */
PHP_METHOD(Phalcon_Html_Escaper, escapeHtml)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0);
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
		ZVAL_STR_COPY(&input_zv, input);
	}
	zephir_cast_to_string(&_0, &input_zv);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "html", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string|null $input
 *
 * @return string
 * @deprecated
 */
PHP_METHOD(Phalcon_Html_Escaper, escapeHtmlAttr)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0);
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
		ZVAL_STR_COPY(&input_zv, input);
	}
	zephir_cast_to_string(&_0, &input_zv);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "attributes", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $input
 *
 * @return string
 * @deprecated
 */
PHP_METHOD(Phalcon_Html_Escaper, escapeUrl)
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
	ZVAL_STR_COPY(&input_zv, input);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "url", NULL, 0, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return AttributeEscaper
 */
PHP_METHOD(Phalcon_Html_Escaper, getAttributeEscaper)
{

	RETURN_MEMBER(getThis(), "attributeEscaper");
}

/**
 * @return CssEscaper
 */
PHP_METHOD(Phalcon_Html_Escaper, getCssEscaper)
{

	RETURN_MEMBER(getThis(), "cssEscaper");
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, getEncoding)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("htmlEscaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getencoding", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Html_Escaper, getFlags)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("htmlEscaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getflags", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return HtmlEscaper
 */
PHP_METHOD(Phalcon_Html_Escaper, getHtmlEscaper)
{

	RETURN_MEMBER(getThis(), "htmlEscaper");
}

/**
 * @return JsEscaper
 */
PHP_METHOD(Phalcon_Html_Escaper, getJsEscaper)
{

	RETURN_MEMBER(getThis(), "jsEscaper");
}

/**
 * @return UrlEscaper
 */
PHP_METHOD(Phalcon_Html_Escaper, getUrlEscaper)
{

	RETURN_MEMBER(getThis(), "urlEscaper");
}

/**
 * Escapes a HTML string. Delegates to the configured `HtmlEscaper`.
 *
 * @param string|null $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, html)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, _0;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0);
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
		ZVAL_STR_COPY(&input_zv, input);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("htmlEscaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "escape", NULL, 0, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Escape javascript strings. Delegates to the configured `JsEscaper`.
 *
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, js)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, _0;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&input_zv, input);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("jsEscaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "escape", NULL, 0, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, normalizeEncoding)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, _0;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&input_zv, input);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("htmlEscaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "normalizeencoding", NULL, 0, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param AttributeEscaper $escaper
 *
 * @return Escaper
 */
PHP_METHOD(Phalcon_Html_Escaper, setAttributeEscaper)
{
	zval *escaper, escaper_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_attributeescaper_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &escaper);
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributeEscaper"), escaper);
	RETURN_THISW();
}

/**
 * @param CssEscaper $escaper
 *
 * @return Escaper
 */
PHP_METHOD(Phalcon_Html_Escaper, setCssEscaper)
{
	zval *escaper, escaper_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_cssescaper_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &escaper);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cssEscaper"), escaper);
	RETURN_THISW();
}

/**
 * Sets the double_encode flag. Fans out to all sub-objects.
 *
 * @param bool $doubleEncode
 */
PHP_METHOD(Phalcon_Html_Escaper, setDoubleEncode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *doubleEncode_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9;
	zend_bool doubleEncode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(doubleEncode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &doubleEncode_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributeEscaper"), PH_NOISY_CC | PH_READONLY);
	if (doubleEncode) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "setdoubleencode", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("cssEscaper"), PH_NOISY_CC | PH_READONLY);
	if (doubleEncode) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_2, "setdoubleencode", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("htmlEscaper"), PH_NOISY_CC | PH_READONLY);
	if (doubleEncode) {
		ZVAL_BOOL(&_5, 1);
	} else {
		ZVAL_BOOL(&_5, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_4, "setdoubleencode", NULL, 0, &_5);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, ZEND_STRL("jsEscaper"), PH_NOISY_CC | PH_READONLY);
	if (doubleEncode) {
		ZVAL_BOOL(&_7, 1);
	} else {
		ZVAL_BOOL(&_7, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_6, "setdoubleencode", NULL, 0, &_7);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, ZEND_STRL("urlEscaper"), PH_NOISY_CC | PH_READONLY);
	if (doubleEncode) {
		ZVAL_BOOL(&_9, 1);
	} else {
		ZVAL_BOOL(&_9, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_8, "setdoubleencode", NULL, 0, &_9);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Sets the encoding. Fans out to all sub-objects.
 *
 * @param string $encoding
 */
PHP_METHOD(Phalcon_Html_Escaper, setEncoding)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval encoding_zv, _0, _1, _2, _3, _4;
	zend_string *encoding = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&encoding_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(encoding)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&encoding_zv, encoding);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributeEscaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setencoding", NULL, 0, &encoding_zv);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("cssEscaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setencoding", NULL, 0, &encoding_zv);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("htmlEscaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "setencoding", NULL, 0, &encoding_zv);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("jsEscaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "setencoding", NULL, 0, &encoding_zv);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("urlEscaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_4, "setencoding", NULL, 0, &encoding_zv);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Sets the htmlspecialchars flags. Fans out to all sub-objects.
 *
 * @param int $flags
 */
PHP_METHOD(Phalcon_Html_Escaper, setFlags)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *flags_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &flags_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributeEscaper"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, flags);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setflags", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("cssEscaper"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, flags);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setflags", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("htmlEscaper"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, flags);
	ZEPHIR_CALL_METHOD(NULL, &_2, "setflags", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("jsEscaper"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, flags);
	ZEPHIR_CALL_METHOD(NULL, &_3, "setflags", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("urlEscaper"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, flags);
	ZEPHIR_CALL_METHOD(NULL, &_4, "setflags", NULL, 0, &_5);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * @param HtmlEscaper $escaper
 *
 * @return Escaper
 */
PHP_METHOD(Phalcon_Html_Escaper, setHtmlEscaper)
{
	zval *escaper, escaper_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_htmlescaper_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &escaper);
	zephir_update_property_zval(this_ptr, ZEND_STRL("htmlEscaper"), escaper);
	RETURN_THISW();
}

/**
 * @param int $flags
 *
 * @deprecated
 */
PHP_METHOD(Phalcon_Html_Escaper, setHtmlQuoteType)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *flags_param = NULL, _0;
	zend_long flags, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &flags_param);
	ZVAL_LONG(&_0, flags);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setflags", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param JsEscaper $escaper
 *
 * @return Escaper
 */
PHP_METHOD(Phalcon_Html_Escaper, setJsEscaper)
{
	zval *escaper, escaper_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_jsescaper_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &escaper);
	zephir_update_property_zval(this_ptr, ZEND_STRL("jsEscaper"), escaper);
	RETURN_THISW();
}

/**
 * @param UrlEscaper $escaper
 *
 * @return Escaper
 */
PHP_METHOD(Phalcon_Html_Escaper, setUrlEscaper)
{
	zval *escaper, escaper_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_urlescaper_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &escaper);
	zephir_update_property_zval(this_ptr, ZEND_STRL("urlEscaper"), escaper);
	RETURN_THISW();
}

/**
 * Escapes a URL. Delegates to the configured `UrlEscaper`.
 *
 * @param string $input
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Escaper, url)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval input_zv, _0;
	zend_string *input = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&input_zv, input);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("urlEscaper"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "escape", NULL, 0, &input_zv);
	zephir_check_call_status();
	RETURN_MM();
}

