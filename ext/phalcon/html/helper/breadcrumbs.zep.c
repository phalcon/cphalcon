
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
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"


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
 * This component offers an easy way to create breadcrumbs for your application.
 * The resulting HTML when calling `render()` will have each breadcrumb enclosed
 * in `<li>` tags, while the whole string is enclosed in `<nav>` and `<ol>` tags.
 *
 * @phpstan-import-type html_breadcrumb_attributes from HtmlTypes
 * @phpstan-import-type html_breadcrumb_data from HtmlTypes
 * @phpstan-import-type html_breadcrumb_element from HtmlTypes
 * @phpstan-import-type html_breadcrumb_template from HtmlTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Breadcrumbs)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Breadcrumbs, phalcon, html_helper_breadcrumbs, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_breadcrumbs_method_entry, 0);

	/**
	 * @phpstan-var html_breadcrumb_attributes
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_html_helper_breadcrumbs_ce, SL("attributes"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Keeps all the breadcrumbs.
	 *
	 * @var html_breadcrumb_data
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_html_helper_breadcrumbs_ce, SL("data"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Link prefix prepended to every non-empty link during rendering.
	 * Auto-populated from the Url service when one is injected.
	 */
	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_html_helper_breadcrumbs_ce, SL("prefix"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * Crumb separator.
	 */
	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "<li>/</li>", sizeof("<li>/</li>") - 1);
		zephir_declare_typed_property(phalcon_html_helper_breadcrumbs_ce, SL("separator"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * The HTML template to use to render the breadcrumbs.
	 *
	 * @phpstan-var html_breadcrumb_template
	 */
	zend_declare_property_null(phalcon_html_helper_breadcrumbs_ce, SL("template"), ZEND_ACC_PRIVATE);
	/**
	 * Optional Url service used to resolve links via get().
	 * When set, takes priority over the string prefix.
	 */
	{
		zval _zc0;
		ZVAL_NULL(&_zc0);
		zephir_declare_typed_property(phalcon_html_helper_breadcrumbs_ce, SL("url"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_NULL, SL("Phalcon\\Mvc\\Url\\UrlInterface"));
	}

	phalcon_html_helper_breadcrumbs_ce->create_object = zephir_init_properties_Phalcon_Html_Helper_Breadcrumbs;

	return SUCCESS;
}

/**
 * AbstractHelper constructor.
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *escaper, escaper_sub, *url = NULL, url_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&url_sub);
	ZVAL_NULL(&__$null);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("url", 3, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_escaperinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(url, phalcon_mvc_url_urlinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &escaper, &url);
	if (!url) {
		url = &url_sub;
		url = &__$null;
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_html_helper_breadcrumbs_ce, getThis(), "__construct", NULL, 0, escaper);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 822, url);
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the indent and delimiter and returns the object back.
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval indent_zv, delimiter_zv, _0;
	zend_string *indent = NULL, *delimiter = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&indent_zv);
	ZVAL_UNDEF(&delimiter_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("delimiter", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("indent", 6, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(indent)
		Z_PARAM_STR_OR_NULL(delimiter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!indent) {
		indent = zend_string_init(ZEND_STRL("    "), 0);
		zephir_memory_observe(&indent_zv);
		ZVAL_STR(&indent_zv, indent);
	} else {
		zephir_memory_observe(&indent_zv);
	ZVAL_STR_COPY(&indent_zv, indent);
	}
	if (!delimiter) {
		ZEPHIR_INIT_VAR(&delimiter_zv);
	} else {
		zephir_memory_observe(&delimiter_zv);
	ZVAL_STR_COPY(&delimiter_zv, delimiter);
	}
	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_IS_NULL(&delimiter_zv)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_GET_CONSTANT(&_0, "PHP_EOL");
	} else {
		ZEPHIR_CPY_WRT(&_0, &delimiter_zv);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 823, &_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 824, &indent_zv);
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
 *
 * @phpstan-param html_breadcrumb_attributes $attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval attributes, _1;
	zval text_zv, link_zv, icon_zv, *attributes_param = NULL, count, _0;
	zend_string *text = NULL, *link = NULL, *icon = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&link_zv);
	ZVAL_UNDEF(&icon_zv);
	ZVAL_UNDEF(&count);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(link)
		Z_PARAM_STR(icon)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 3) {
		attributes_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	if (!link) {
		link = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&link_zv);
		ZVAL_STR(&link_zv, link);
	} else {
		zephir_memory_observe(&link_zv);
	ZVAL_STR_COPY(&link_zv, link);
	}
	if (!icon) {
		icon = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&icon_zv);
		ZVAL_STR(&icon_zv, icon);
	} else {
		zephir_memory_observe(&icon_zv);
	ZVAL_STR_COPY(&icon_zv, icon);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 825, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&count);
	ZVAL_LONG(&count, (zephir_fast_count_int(&_0) + 1));
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 4, 0);
	zephir_array_update_string(&_1, SL("attributes"), &attributes, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("icon"), &icon_zv, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("link"), &link_zv, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("text"), &text_zv, PH_COPY | PH_SEPARATE);
	zephir_update_property_array(this_ptr, SL("data"), &count, &_1);
	RETURN_THIS();
}

/**
 * Clears the crumbs
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 825, &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Clear the attributes of the parent element
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, clearAttributes)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 826, &_0);
	RETURN_THIS();
}

/**
 * Get the attributes of the parent element
 *
 * @phpstan-return html_breadcrumb_attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, getAttributes)
{

	RETURN_MEMBER_TYPED(getThis(), "attributes", IS_ARRAY);
}

/**
 * Returns the link prefix.
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, getPrefix)
{

	RETURN_MEMBER_TYPED(getThis(), "prefix", IS_STRING);
}

/**
 * Returns the separator.
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, getSeparator)
{

	RETURN_MEMBER_TYPED(getThis(), "separator", IS_STRING);
}

/**
 * Return the current template.
 *
 * @phpstan-return html_breadcrumb_template
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, getTemplate)
{

	RETURN_MEMBER_TYPED(getThis(), "template", IS_ARRAY);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &index_param);
	zephir_memory_observe(&elements);
	zephir_read_property_cached(&elements, this_ptr, _zephir_prop_0, 825, PH_NOISY_CC);
	zephir_array_unset_long(&elements, index, PH_SEPARATE);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 825, &elements);
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
	zend_bool _10;
	zval output, _18;
	zval data, lastUrl, lastElement, element, _0, _1, *_2, _3, *_4, _9, _14, _15, _16, _17, _19, _20, _21, _22, _23, _24, _25, _26, _5$$4, _6$$4, _7$$4, _11$$5, _12$$5, _13$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&lastUrl);
	ZVAL_UNDEF(&lastElement);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_18);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("template", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("attributes", 10, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("delimiter", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("indent", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("separator", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 825, PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_STRING("");
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 825, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&data, &_1);
	ZEPHIR_INIT_VAR(&output);
	array_init(&output);
	ZEPHIR_CALL_FUNCTION(&lastUrl, "array_key_last", NULL, 21, &data);
	zephir_check_call_status();
	zephir_memory_observe(&lastElement);
	zephir_array_fetch(&lastElement, &data, &lastUrl, PH_NOISY, "phalcon/Html/Helper/Breadcrumbs.zep", 229);
	zephir_array_unset(&data, &lastUrl, PH_SEPARATE);
	if (Z_TYPE_P(&data) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_string_to_char_array(&_3, &data);
		_2 = &_3;
	} else {
		_2 = &data;
	}
	zephir_is_iterable(_2, 0, "phalcon/Html/Helper/Breadcrumbs.zep", 240);
	if (Z_TYPE_P(_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2), _4)
		{
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _4);
			zephir_read_property_cached(&_6$$4, this_ptr, _zephir_prop_1, 827, PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_7$$4, &_6$$4, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Breadcrumbs.zep", 234);
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "getlink", &_8, 0, &_7$$4, &element);
			zephir_check_call_status();
			zephir_array_append(&output, &_5$$4, PH_SEPARATE, "phalcon/Html/Helper/Breadcrumbs.zep", 234);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _2, "rewind", NULL, 0);
		zephir_check_call_status();
		_10 = 1;
		while (1) {
			if (_10) {
				_10 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _2, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_9, _2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&element, _2, "current", NULL, 0);
			zephir_check_call_status();
				zephir_read_property_cached(&_12$$5, this_ptr, _zephir_prop_1, 827, PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch_string(&_13$$5, &_12$$5, SL("line"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Breadcrumbs.zep", 234);
				ZEPHIR_CALL_METHOD(&_11$$5, this_ptr, "getlink", &_8, 0, &_13$$5, &element);
				zephir_check_call_status();
				zephir_array_append(&output, &_11$$5, PH_SEPARATE, "phalcon/Html/Helper/Breadcrumbs.zep", 234);
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 827, PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_15, &_1, SL("last"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Breadcrumbs.zep", 240);
	ZEPHIR_CALL_METHOD(&_14, this_ptr, "getlink", &_8, 0, &_15, &lastElement);
	zephir_check_call_status();
	zephir_array_append(&output, &_14, PH_SEPARATE, "phalcon/Html/Helper/Breadcrumbs.zep", 240);
	zephir_read_property_cached(&_16, this_ptr, _zephir_prop_1, 827, PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_17, &_16, SL("main"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Breadcrumbs.zep", 243);
	ZEPHIR_INIT_VAR(&_18);
	zephir_create_array(&_18, 4, 0);
	zephir_read_property_cached(&_20, this_ptr, _zephir_prop_2, 826, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_19, this_ptr, "processattributes", NULL, 0, &_20);
	zephir_check_call_status();
	zephir_array_update_string(&_18, SL("attributes"), &_19, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_21);
	zephir_read_property_cached(&_21, this_ptr, _zephir_prop_3, 823, PH_NOISY_CC);
	zephir_array_update_string(&_18, SL("delimiter"), &_21, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_21);
	zephir_read_property_cached(&_21, this_ptr, _zephir_prop_4, 824, PH_NOISY_CC);
	zephir_array_update_string(&_18, SL("indent"), &_21, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_22);
	zephir_read_property_cached(&_23, this_ptr, _zephir_prop_4, 824, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_24, this_ptr, _zephir_prop_5, 828, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_25, this_ptr, _zephir_prop_3, 823, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_26);
	ZEPHIR_CONCAT_VVV(&_26, &_23, &_24, &_25);
	zephir_fast_join(&_22, &_26, &output);
	zephir_array_update_string(&_18, SL("items"), &_22, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "tointerpolate", NULL, 0, &_17, &_18);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set the attributes for the parent element
 *
 * @phpstan-param html_breadcrumb_attributes $attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, setAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *attributes_param = NULL;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("attributes", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 826, &attributes);
	RETURN_THIS();
}

/**
 * Set the link prefix prepended to every non-empty link during rendering.
 * When a Url service was injected, calling this method replaces it.
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, setPrefix)
{
	zval prefix_zv, __$null;
	zend_string *prefix = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix_zv);
	ZVAL_NULL(&__$null);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("prefix", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("url", 3, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(prefix)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&prefix_zv, prefix);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 829, &prefix_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 822, &__$null);
	RETURN_THISW();
}

/**
 * Set the separator
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, setSeparator)
{
	zval separator_zv;
	zend_string *separator = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&separator_zv);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("separator", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(separator)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&separator_zv, separator);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 828, &separator_zv);
	RETURN_THISW();
}

/**
 * Set the HTML template
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, setTemplate)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval main_zv, line_zv, last_zv;
	zend_string *main = NULL, *line = NULL, *last = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&main_zv);
	ZVAL_UNDEF(&line_zv);
	ZVAL_UNDEF(&last_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("template", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(main)
		Z_PARAM_STR(line)
		Z_PARAM_STR(last)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&main_zv);
	ZVAL_STR_COPY(&main_zv, main);
	zephir_memory_observe(&line_zv);
	ZVAL_STR_COPY(&line_zv, line);
	zephir_memory_observe(&last_zv);
	ZVAL_STR_COPY(&last_zv, last);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	zephir_array_update_string(&_0, SL("main"), &main_zv, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("line"), &line_zv, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("last"), &last_zv, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 827, &_0);
	RETURN_THIS();
}

/**
 * Returns the internal breadcrumbs array
 *
 * @phpstan-return html_breadcrumb_data
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, toArray)
{

	RETURN_MEMBER_TYPED(getThis(), "data", IS_ARRAY);
}

/**
 * @phpstan-param html_breadcrumb_element $element
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, getLink)
{
	zend_bool _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval element, _10;
	zval template_zv, *element_param = NULL, link, _1, _3, _8, _9, _11, _12, _13, _14, _15, _16, _17, _4$$3, _5$$3, _6$$4, _7$$4;
	zend_string *template = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&template_zv);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&_10);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("url", 3, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("prefix", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("indent", 6, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("escaper", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("delimiter", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(template)
		ZEPHIR_Z_PARAM_ARRAY(element, element_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	element_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&template_zv);
	ZVAL_STR_COPY(&template_zv, template);
	zephir_get_arrval(&element, element_param);
	_0 = !(zephir_isempty_dim_string(&element, SL("link")));
	if (_0) {
		zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 822, PH_NOISY_CC | PH_READONLY);
		_0 = Z_TYPE_P(&_1) != IS_NULL;
	}
	if (_0) {
		zephir_read_property_cached(&_4$$3, this_ptr, _zephir_prop_0, 822, PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_5$$3, &element, SL("link"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Breadcrumbs.zep", 327);
		ZEPHIR_CALL_METHOD(&link, &_4$$3, "get", NULL, 0, &_5$$3);
		zephir_check_call_status();
	} else {
		_2 = !(zephir_isempty_dim_string(&element, SL("link")));
		if (_2) {
			zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 829, PH_NOISY_CC | PH_READONLY);
			_2 = !(ZEPHIR_IS_EMPTY(&_3));
		}
		if (_2) {
			zephir_read_property_cached(&_6$$4, this_ptr, _zephir_prop_1, 829, PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_7$$4, &element, SL("link"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Breadcrumbs.zep", 329);
			ZEPHIR_INIT_NVAR(&link);
			ZEPHIR_CONCAT_VV(&link, &_6$$4, &_7$$4);
		} else {
			ZEPHIR_OBS_NVAR(&link);
			zephir_array_fetch_string(&link, &element, SL("link"), PH_NOISY, "phalcon/Html/Helper/Breadcrumbs.zep", 331);
		}
	}
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_2, 824, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_10);
	zephir_create_array(&_10, 4, 0);
	zephir_array_fetch_string(&_12, &element, SL("attributes"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Breadcrumbs.zep", 338);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "processattributes", NULL, 0, &_12);
	zephir_check_call_status();
	zephir_array_update_string(&_10, SL("attributes"), &_11, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&_13);
	zephir_array_fetch_string(&_13, &element, SL("icon"), PH_NOISY, "phalcon/Html/Helper/Breadcrumbs.zep", 339);
	zephir_array_update_string(&_10, SL("icon"), &_13, PH_COPY | PH_SEPARATE);
	zephir_read_property_cached(&_14, this_ptr, _zephir_prop_3, 830, PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_15, &element, SL("text"), PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Breadcrumbs.zep", 340);
	ZEPHIR_CALL_METHOD(&_11, &_14, "html", NULL, 0, &_15);
	zephir_check_call_status();
	zephir_array_update_string(&_10, SL("text"), &_11, PH_COPY | PH_SEPARATE);
	zephir_read_property_cached(&_16, this_ptr, _zephir_prop_3, 830, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_11, &_16, "attributes", NULL, 0, &link);
	zephir_check_call_status();
	zephir_array_update_string(&_10, SL("link"), &_11, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "tointerpolate", NULL, 0, &template_zv, &_10);
	zephir_check_call_status();
	zephir_read_property_cached(&_17, this_ptr, _zephir_prop_4, 823, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VVV(return_value, &_8, &_9, &_17);
	RETURN_MM();
}

/**
 * Processes attributes
 *
 * @phpstan-param html_breadcrumb_attributes $attributes
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
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
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

/**
 * @param string   $input
 * @param string[] $context
 * @param string   $left
 * @param string   $right
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Breadcrumbs, toInterpolate)
{
	zend_bool _6;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context, replace;
	zval input_zv, *context_param = NULL, left_zv, right_zv, key, value, _0, *_1, _5, _4$$5, _7$$6;
	zend_string *input = NULL, *left = NULL, *right = NULL, *_3;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&left_zv);
	ZVAL_UNDEF(&right_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&replace);
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(context, context_param)
		Z_PARAM_STR(left)
		Z_PARAM_STR(right)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}
	if (!left) {
		left = zend_string_init(ZEND_STRL("%"), 0);
		zephir_memory_observe(&left_zv);
		ZVAL_STR(&left_zv, left);
	} else {
		zephir_memory_observe(&left_zv);
	ZVAL_STR_COPY(&left_zv, left);
	}
	if (!right) {
		right = zend_string_init(ZEND_STRL("%"), 0);
		zephir_memory_observe(&right_zv);
		ZVAL_STR(&right_zv, right);
	} else {
		zephir_memory_observe(&right_zv);
	ZVAL_STR_COPY(&right_zv, right);
	}
	ZEPHIR_INIT_VAR(&replace);
	array_init(&replace);
	if (ZEPHIR_IS_EMPTY(&context)) {
		RETURN_MM_STR(zend_string_copy(input));
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strpos(&_0, &input_zv, &left_zv, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_STR(zend_string_copy(input));
	}
	zephir_is_iterable(&context, 0, "phalcon/Traits/Support/Helper/Str/InterpolateTrait.zep", 49);
	if (Z_TYPE_P(&context) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&context), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_INIT_NVAR(&_4$$5);
			ZEPHIR_CONCAT_VVV(&_4$$5, &left_zv, &key, &right_zv);
			zephir_array_update_zval(&replace, &_4$$5, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &context, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &context, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &context, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &context, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &context, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$6);
				ZEPHIR_CONCAT_VVV(&_7$$6, &left_zv, &key, &right_zv);
				zephir_array_update_zval(&replace, &_7$$6, &value, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 4, &input_zv, &replace);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Html_Helper_Breadcrumbs(zend_class_entry *class_type)
{
		zval _1$$3;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
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
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

