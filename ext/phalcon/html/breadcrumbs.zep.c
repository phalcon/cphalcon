
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
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
 * Phalcon\Html\Breadcrumbs
 *
 * This component offers an easy way to create breadcrumbs for your application.
 * The resulting HTML when calling `render()` will have each breadcrumb enclosed
 * in `<dt>` tags, while the whole string is enclosed in `<dl>` tags.
 *
 * @phpstan-import-type html_breadcrumb_elements from HtmlTypes
 *
 * @deprecated Will be removed in future version
 * Use {@see \Phalcon\Html\Helper\Breadcrumbs} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Breadcrumbs)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html, Breadcrumbs, phalcon, html_breadcrumbs, phalcon_html_breadcrumbs_method_entry, 0);

	/**
	 * Keeps all the breadcrumbs
	 *
	 * @phpstan-var html_breadcrumb_elements
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_html_breadcrumbs_ce, SL("elements"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Crumb separator
	 */
	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, " / ", sizeof(" / ") - 1);
		zephir_declare_typed_property(phalcon_html_breadcrumbs_ce, SL("separator"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_STRING, NULL, 0);
	}

	/**
	 * The HTML template to use to render the breadcrumbs.
	 */
	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "<dt><a href=\"%link%\">%label%</a></dt>", sizeof("<dt><a href=\"%link%\">%label%</a></dt>") - 1);
		zephir_declare_typed_property(phalcon_html_breadcrumbs_ce, SL("template"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Adds a new crumb.
 *
 * ```php
 * // Adding a crumb with a link
 * $breadcrumbs->add("Home", "/");
 *
 * // Adding a crumb without a link (normally the last one)
 * $breadcrumbs->add("Users");
 * ```
 *
 * Crumbs are stored keyed by their link, so adding two crumbs that share
 * the same link - including two link-less crumbs, which share the empty
 * string key - keeps only the last one.
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval label_zv, link_zv;
	zend_string *label = NULL, *link = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&label_zv);
	ZVAL_UNDEF(&link_zv);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(label)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(link)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&label_zv);
	ZVAL_STR_COPY(&label_zv, label);
	if (!link) {
		link = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&link_zv);
		ZVAL_STR(&link_zv, link);
	} else {
		zephir_memory_observe(&link_zv);
	ZVAL_STR_COPY(&link_zv, link);
	}
	zephir_update_property_array(this_ptr, SL("elements"), &link_zv, &label_zv);
	RETURN_THIS();
}

/**
 * Clears the crumbs
 *
 * ```php
 * $breadcrumbs->clear()
 * ```
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, clear)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elements", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 805, &_0);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the separator
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, getSeparator)
{

	RETURN_MEMBER_TYPED(getThis(), "separator", IS_STRING);
}

/**
 * Removes crumb by url.
 *
 * ```php
 * $breadcrumbs->remove("/admin/user/create");
 *
 * // remove a crumb without an url (last link)
 * $breadcrumbs->remove();
 * ```
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, remove)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval link_zv, elements, _0;
	zend_string *link = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&link_zv);
	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elements", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(link)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&link_zv);
	ZVAL_STR_COPY(&link_zv, link);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 805, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&elements, &_0);
	zephir_array_unset(&elements, &link_zv, PH_SEPARATE);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 805, &elements);
	ZEPHIR_MM_RESTORE();
}

/**
 * Renders and outputs breadcrumbs based on previously set template.
 *
 * ```php
 * echo $breadcrumbs->render();
 * ```
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, render)
{
	zval _10$$4, _13$$4, _20$$5, _22$$5, _23$$6, _30$$7, _32$$7;
	zval _7$$4, _9$$4, _17$$5, _19$$5, _27$$7, _29$$7;
	zend_bool _15;
	zend_string *_5;
	zend_ulong _4;
	zval element, elements, lastLabel, lastUrl, output, template, url, urls, _0, *_1, _2, *_3, _14, _33, _34, _6$$4, _8$$4, _11$$4, _16$$5, _18$$5, _21$$5, _24$$6, _25$$6, _26$$7, _28$$7, _31$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element);
	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&lastLabel);
	ZVAL_UNDEF(&lastUrl);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&urls);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_31$$7);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_29$$7);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_30$$7);
	ZVAL_UNDEF(&_32$$7);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elements", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("template", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("separator", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 805, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&elements, &_0);
	if (ZEPHIR_IS_EMPTY(&elements)) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_INIT_VAR(&output);
	array_init(&output);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 806, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&template, &_0);
	ZEPHIR_INIT_VAR(&urls);
	zephir_array_keys(&urls, &elements);
	ZEPHIR_MAKE_REF(&urls);
	ZEPHIR_CALL_FUNCTION(&lastUrl, "end", NULL, 0, &urls);
	ZEPHIR_UNREF(&urls);
	zephir_check_call_status();
	zephir_memory_observe(&lastLabel);
	zephir_array_fetch(&lastLabel, &elements, &lastUrl, PH_NOISY, "phalcon/Html/Breadcrumbs.zep", 136);
	zephir_array_unset(&elements, &lastUrl, PH_SEPARATE);
	if (Z_TYPE_P(&elements) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_string_to_char_array(&_2, &elements);
		_1 = &_2;
	} else {
		_1 = &elements;
	}
	zephir_is_iterable(_1, 0, "phalcon/Html/Breadcrumbs.zep", 157);
	if (Z_TYPE_P(_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1), _4, _5, _3)
		{
			ZEPHIR_INIT_NVAR(&url);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&url, _5);
			} else {
				ZVAL_LONG(&url, _4);
			}
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _3);
			ZEPHIR_INIT_NVAR(&_6$$4);
			ZEPHIR_INIT_NVAR(&_7$$4);
			zephir_create_array(&_7$$4, 2, 0);
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "%label%");
			zephir_array_fast_append(&_7$$4, &_8$$4);
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "%link%");
			zephir_array_fast_append(&_7$$4, &_8$$4);
			ZEPHIR_INIT_NVAR(&_9$$4);
			zephir_create_array(&_9$$4, 2, 0);
			zephir_cast_to_string(&_10$$4, &element);
			ZEPHIR_CALL_FUNCTION(&_11$$4, "htmlspecialchars", &_12, 197, &_10$$4);
			zephir_check_call_status();
			zephir_array_fast_append(&_9$$4, &_11$$4);
			zephir_cast_to_string(&_13$$4, &url);
			ZEPHIR_CALL_FUNCTION(&_11$$4, "htmlspecialchars", &_12, 197, &_13$$4);
			zephir_check_call_status();
			zephir_array_fast_append(&_9$$4, &_11$$4);
			zephir_fast_str_replace(&_6$$4, &_7$$4, &_9$$4, &template);
			zephir_array_append(&output, &_6$$4, PH_SEPARATE, "phalcon/Html/Breadcrumbs.zep", 151);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _1, "rewind", NULL, 0);
		zephir_check_call_status();
		_15 = 1;
		while (1) {
			if (_15) {
				_15 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_14, _1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&url, _1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&element, _1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$5);
				ZEPHIR_INIT_NVAR(&_17$$5);
				zephir_create_array(&_17$$5, 2, 0);
				ZEPHIR_INIT_NVAR(&_18$$5);
				ZVAL_STRING(&_18$$5, "%label%");
				zephir_array_fast_append(&_17$$5, &_18$$5);
				ZEPHIR_INIT_NVAR(&_18$$5);
				ZVAL_STRING(&_18$$5, "%link%");
				zephir_array_fast_append(&_17$$5, &_18$$5);
				ZEPHIR_INIT_NVAR(&_19$$5);
				zephir_create_array(&_19$$5, 2, 0);
				zephir_cast_to_string(&_20$$5, &element);
				ZEPHIR_CALL_FUNCTION(&_21$$5, "htmlspecialchars", &_12, 197, &_20$$5);
				zephir_check_call_status();
				zephir_array_fast_append(&_19$$5, &_21$$5);
				zephir_cast_to_string(&_22$$5, &url);
				ZEPHIR_CALL_FUNCTION(&_21$$5, "htmlspecialchars", &_12, 197, &_22$$5);
				zephir_check_call_status();
				zephir_array_fast_append(&_19$$5, &_21$$5);
				zephir_fast_str_replace(&_16$$5, &_17$$5, &_19$$5, &template);
				zephir_array_append(&output, &_16$$5, PH_SEPARATE, "phalcon/Html/Breadcrumbs.zep", 151);
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	ZEPHIR_INIT_NVAR(&url);
	if (!(ZEPHIR_IS_EMPTY(&elements))) {
		zephir_cast_to_string(&_23$$6, &lastLabel);
		ZEPHIR_CALL_FUNCTION(&_24$$6, "htmlspecialchars", &_12, 197, &_23$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_25$$6);
		ZEPHIR_CONCAT_SVS(&_25$$6, "<dt>", &_24$$6, "</dt>");
		zephir_array_append(&output, &_25$$6, PH_SEPARATE, "phalcon/Html/Breadcrumbs.zep", 158);
	} else {
		ZEPHIR_INIT_VAR(&_26$$7);
		ZEPHIR_INIT_VAR(&_27$$7);
		zephir_create_array(&_27$$7, 2, 0);
		ZEPHIR_INIT_VAR(&_28$$7);
		ZVAL_STRING(&_28$$7, "%label%");
		zephir_array_fast_append(&_27$$7, &_28$$7);
		ZEPHIR_INIT_NVAR(&_28$$7);
		ZVAL_STRING(&_28$$7, "%link%");
		zephir_array_fast_append(&_27$$7, &_28$$7);
		ZEPHIR_INIT_VAR(&_29$$7);
		zephir_create_array(&_29$$7, 2, 0);
		zephir_cast_to_string(&_30$$7, &lastLabel);
		ZEPHIR_CALL_FUNCTION(&_31$$7, "htmlspecialchars", &_12, 197, &_30$$7);
		zephir_check_call_status();
		zephir_array_fast_append(&_29$$7, &_31$$7);
		zephir_cast_to_string(&_32$$7, &lastUrl);
		ZEPHIR_CALL_FUNCTION(&_31$$7, "htmlspecialchars", &_12, 197, &_32$$7);
		zephir_check_call_status();
		zephir_array_fast_append(&_29$$7, &_31$$7);
		zephir_fast_str_replace(&_26$$7, &_27$$7, &_29$$7, &template);
		zephir_array_append(&output, &_26$$7, PH_SEPARATE, "phalcon/Html/Breadcrumbs.zep", 170);
	}
	ZEPHIR_INIT_VAR(&_33);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_2, 807, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_34);
	ZEPHIR_CONCAT_SVS(&_34, "<dt>", &_0, "</dt>");
	zephir_fast_join(&_33, &_34, &output);
	ZEPHIR_CONCAT_SVS(return_value, "<dl>", &_33, "</dl>");
	RETURN_MM();
}

/**
 * Set the separator
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, setSeparator)
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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 807, &separator_zv);
	RETURN_THISW();
}

/**
 * Returns the internal breadcrumbs array
 *
 * @phpstan-return html_breadcrumb_elements
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, toArray)
{

	RETURN_MEMBER_TYPED(getThis(), "elements", IS_ARRAY);
}

