
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This component offers an easy way to create breadcrumbs for your application.
 * The resulting HTML when calling `render()` will have each breadcrumb enclosed
 * in `<li>` tags, while the whole string is enclosed in `<nav>` and `<ol>` tags.
 *
 * @phpstan-type TTemplate = array{
 *      main: string,
 *      line: string,
 *      last: string,
 * }
 * @phpstan-type TElement = array{
 *      attributes: array<string, string>,
 *      icon: string,
 *      link: string,
 *      text: string,
 * }
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Breadcrumbs)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Breadcrumbs, phalcon, html_helper_breadcrumbs, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_breadcrumbs_method_entry, 0);

	/**
	 * @var array<string, string>
	 */
	zend_declare_property_null(phalcon_html_helper_breadcrumbs_ce, SL("attributes"), ZEND_ACC_PRIVATE);
	/**
	 * Keeps all the breadcrumbs.
	 *
	 * @var array<int, TElement>
	 */
	zend_declare_property_null(phalcon_html_helper_breadcrumbs_ce, SL("data"), ZEND_ACC_PRIVATE);
	/**
	 * Crumb separator.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_breadcrumbs_ce, SL("separator"), "<li>/</li>", ZEND_ACC_PRIVATE);
	/**
	 * The HTML template to use to render the breadcrumbs.
	 *
	 * @var TTemplate
	 */
	zend_declare_property_null(phalcon_html_helper_breadcrumbs_ce, SL("template"), ZEND_ACC_PRIVATE);
	/**
	 * The HTML template to use to render the breadcrumbs.
	 *
	 * @var Interpolate
	 */
	zend_declare_property_null(phalcon_html_helper_breadcrumbs_ce, SL("interpolator"), ZEND_ACC_PRIVATE);
	phalcon_html_helper_breadcrumbs_ce->create_object = zephir_init_properties_Phalcon_Html_Helper_Breadcrumbs;

	return SUCCESS;
}

/**
 * AbstractHelper constructor.
 *
 * @param EscaperInterface $escaper
 * @param string $indent = ""
 * @param string|null $delimiter = null
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *escaper, escaper_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_escaperinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &escaper);
	ZEPHIR_CALL_PARENT(NULL, phalcon_html_helper_breadcrumbs_ce, getThis(), "__construct", NULL, 0, escaper);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_support_helper_str_interpolate_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval(this_ptr, ZEND_STRL("interpolator"), &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the indent and delimiter and returns the object back.
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *indent_param = NULL, *delimiter_param = NULL, _0;
	zval indent, delimiter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&indent);
	ZVAL_UNDEF(&delimiter);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(indent)
		Z_PARAM_STR_OR_NULL(delimiter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &indent_param, &delimiter_param);
	if (!indent_param) {
		ZEPHIR_INIT_VAR(&indent);
		ZVAL_STRING(&indent, "    ");
	} else {
		zephir_get_strval(&indent, indent_param);
	}
	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(&delimiter);
	} else {
		zephir_get_strval(&delimiter, delimiter_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_IS_NULL(&delimiter)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_GET_CONSTANT(&_0, "PHP_EOL");
	} else {
		ZEPHIR_CPY_WRT(&_0, &delimiter);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("delimiter"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("indent"), &indent);
	RETURN_THIS();
}

/**
 * Adds a new crumb.
 *
 * ```php
 * // Adding a crumb with a link
 * $breadcrumbs->add("Home", "/");
 *
 * // Adding a crumb with added attributes
 * $breadcrumbs->add("Home", "/", ["class" => "main"]);
 *
 * // Adding a crumb without a link (normally the last one)
 * $breadcrumbs->add("Users");
 * ```
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval attributes, _1;
	zval *text_param = NULL, *link_param = NULL, *icon_param = NULL, *attributes_param = NULL, count, _0;
	zval text, link, icon;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&icon);
	ZVAL_UNDEF(&count);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(link)
		Z_PARAM_STR(icon)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 3, &text_param, &link_param, &icon_param, &attributes_param);
	zephir_get_strval(&text, text_param);
	if (!link_param) {
		ZEPHIR_INIT_VAR(&link);
		ZVAL_STRING(&link, "");
	} else {
		zephir_get_strval(&link, link_param);
	}
	if (!icon_param) {
		ZEPHIR_INIT_VAR(&icon);
		ZVAL_STRING(&icon, "");
	} else {
		zephir_get_strval(&icon, icon_param);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&count);
	ZVAL_LONG(&count, (zephir_fast_count_int(&_0) + 1));
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 4, 0);
	zephir_array_update_string(&_1, SL("attributes"), &attributes, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("icon"), &icon, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("link"), &link, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("text"), &text, PH_COPY | PH_SEPARATE);
	zephir_update_property_array(this_ptr, SL("data"), &count, &_1);
	RETURN_THIS();
}

/**
 * Clears the crumbs.
 *
 * ```php
 * $breadcrumbs->clear()
 * ```
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, clear)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Clear the attributes of the parent element.
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, clearAttributes)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &_0);
	RETURN_THIS();
}

/**
 * Get the attributes of the parent element.
 *
 * @return array<string, string>
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, getAttributes)
{

	RETURN_MEMBER(getThis(), "attributes");
}

/**
 * Returns the separator.
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, getSeparator)
{

	RETURN_MEMBER(getThis(), "separator");
}

/**
 * Return the current template.
 *
 * @return TTemplate
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, getTemplate)
{

	RETURN_MEMBER(getThis(), "template");
}

/**
 * Removes crumb by url.
 *
 * ```php
 * // Remove the second element
 * $breadcrumbs->remove(2);
 * ```
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, remove)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *index_param = NULL, elements;
	zend_long index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &index_param);
	zephir_memory_observe(&elements);
	zephir_read_property(&elements, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
	zephir_array_unset_long(&elements, index, PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &elements);
	ZEPHIR_MM_RESTORE();
}

/**
 * Renders and outputs breadcrumbs based on previously set template.
 *
 * ```php
 * echo $breadcrumbs->render();
 * ```
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, render)
{
	zval output, _20;
	zval lastUrl, lastElement, element, _0, _1, _2, _3, _4, *_5, _6, _14, _15, _16, _17, _18, _19, _21, _22, _23, _24, _25, _26, _27, _28, _7$$4, _8$$4, _9$$4, _11$$5, _12$$5, _13$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&lastUrl);
	ZVAL_UNDEF(&lastElement);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_20);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_INIT_VAR(&output);
	array_init(&output);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&lastUrl, "array_key_last", NULL, 40, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&lastElement);
	zephir_array_fetch(&lastElement, &_2, &lastUrl, PH_NOISY, "phalcon/Html/Helper/Breadcrumbs.zep", 215);
	zephir_unset_property_array(this_ptr, ZEND_STRL("data"), &lastUrl);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_3, &lastUrl, PH_SEPARATE);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "phalcon/Html/Helper/Breadcrumbs.zep", 226);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _5);
			zephir_read_property(&_8$$4, this_ptr, ZEND_STRL("template"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_9$$4, &_8$$4, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Breadcrumbs.zep", 220);
			ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "getlink", &_10, 329, &_9$$4, &element);
			zephir_check_call_status();
			zephir_array_append(&output, &_7$$4, PH_SEPARATE, "phalcon/Html/Helper/Breadcrumbs.zep", 220);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&element, &_4, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("template"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch_string(&_13$$5, &_12$$5, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Breadcrumbs.zep", 220);
				ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "getlink", &_10, 329, &_13$$5, &element);
				zephir_check_call_status();
				zephir_array_append(&output, &_11$$5, PH_SEPARATE, "phalcon/Html/Helper/Breadcrumbs.zep", 220);
			ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	zephir_read_property(&_15, this_ptr, ZEND_STRL("template"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_16, &_15, SL("last"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Breadcrumbs.zep", 226);
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "getlink", &_10, 329, &_16, &lastElement);
	zephir_check_call_status();
	zephir_array_append(&output, &_14, PH_SEPARATE, "phalcon/Html/Helper/Breadcrumbs.zep", 226);
	zephir_read_property(&_17, this_ptr, ZEND_STRL("interpolator"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_18, this_ptr, ZEND_STRL("template"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_19, &_18, SL("main"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Breadcrumbs.zep", 229);
	ZEPHIR_INIT_VAR(&_20);
	zephir_create_array(&_20, 4, 0);
	zephir_read_property(&_22, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_21, this_ptr, "processattributes", NULL, 330, &_22);
	zephir_check_call_status();
	zephir_array_update_string(&_20, SL("attributes"), &_21, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_23);
	zephir_read_property(&_23, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC);
	zephir_array_update_string(&_20, SL("delimiter"), &_23, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_23);
	zephir_read_property(&_23, this_ptr, ZEND_STRL("indent"), PH_NOISY_CC);
	zephir_array_update_string(&_20, SL("indent"), &_23, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_24);
	zephir_read_property(&_25, this_ptr, ZEND_STRL("indent"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_26, this_ptr, ZEND_STRL("separator"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_27, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_28);
	ZEPHIR_CONCAT_VVV(&_28, &_25, &_26, &_27);
	zephir_fast_join(&_24, &_28, &output);
	zephir_array_update_string(&_20, SL("items"), &_24, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(&_17, "__invoke", NULL, 0, &_19, &_20);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set the attributes for the parent element.
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, setAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attributes_param = NULL;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	RETURN_THIS();
}

/**
 * Set the separator.
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, setSeparator)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *separator_param = NULL;
	zval separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&separator);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(separator)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &separator_param);
	zephir_get_strval(&separator, separator_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("separator"), &separator);
	RETURN_THIS();
}

/**
 * Set the HTML template.
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, setTemplate)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *main_param = NULL, *line_param = NULL, *last_param = NULL;
	zval main, line, last;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&main);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&last);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(main)
		Z_PARAM_STR(line)
		Z_PARAM_STR(last)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &main_param, &line_param, &last_param);
	zephir_get_strval(&main, main_param);
	zephir_get_strval(&line, line_param);
	zephir_get_strval(&last, last_param);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	zephir_array_update_string(&_0, SL("main"), &main, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("line"), &line, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("last"), &last, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("template"), &_0);
	RETURN_THIS();
}

/**
 * Returns the internal breadcrumbs array.
 *
 * @return array<int, TElement>
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, toArray)
{

	RETURN_MEMBER(getThis(), "data");
}

/**
 * @param TElement $element
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, getLink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element, _3;
	zval *template_param = NULL, *element_param = NULL, _0, _1, _2, _4, _5, _6, _7, _8, _9;
	zval template;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(template)
		Z_PARAM_ARRAY(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &template_param, &element_param);
	zephir_get_strval(&template, template_param);
	zephir_get_arrval(&element, element_param);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("indent"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("interpolator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 4, 0);
	zephir_array_fetch_string(&_5, &element, SL("attributes"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Breadcrumbs.zep", 300);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "processattributes", NULL, 330, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_3, SL("attributes"), &_4, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_6);
	zephir_array_fetch_string(&_6, &element, SL("icon"), PH_NOISY, "phalcon/Html/Helper/Breadcrumbs.zep", 301);
	zephir_array_update_string(&_3, SL("icon"), &_6, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_8, &element, SL("text"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Breadcrumbs.zep", 302);
	ZEPHIR_CALL_METHOD(&_4, &_7, "html", NULL, 0, &_8);
	zephir_check_call_status();
	zephir_array_update_string(&_3, SL("text"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_6);
	zephir_array_fetch_string(&_6, &element, SL("link"), PH_NOISY, "phalcon/Html/Helper/Breadcrumbs.zep", 304);
	zephir_array_update_string(&_3, SL("link"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, &_1, "__invoke", NULL, 0, &template, &_3);
	zephir_check_call_status();
	zephir_read_property(&_9, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VVV(return_value, &_0, &_2, &_9);
	RETURN_MM();
}

/**
 * Processes attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, processAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, attributesRendered, _0;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&attributesRendered);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);
	ZEPHIR_CALL_METHOD(&attributesRendered, this_ptr, "renderattributes", NULL, 0, &attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	if (!(ZEPHIR_IS_EMPTY(&attributesRendered))) {
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_CONCAT_SV(&_0, " ", &attributesRendered);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "");
	}
	zephir_fast_trim(return_value, &_0, NULL , ZEPHIR_TRIM_RIGHT);
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Html_Helper_Breadcrumbs(zend_class_entry *class_type)
{
		zval _1$$3;
	zval _0, _2, _4, _3$$4, _5$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("template"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 3, 0);
			add_assoc_stringl_ex(&_1$$3, SL("main"), SL("\n<nav%attributes%>\n    <ol>\n%items%\n    </ol>\n</nav>"));
			add_assoc_stringl_ex(&_1$$3, SL("line"), SL("<li%attributes%><a href=\"%link%\">%icon%%text%</a></li>"));
			add_assoc_stringl_ex(&_1$$3, SL("last"), SL("<li><span%attributes%>%text%</span></li>"));
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("template"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("data"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("attributes"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

