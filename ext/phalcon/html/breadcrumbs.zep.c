
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
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
 */
/**
 * Phalcon\Html\Breadcrumbs
 *
 * This component offers an easy way to create breadcrumbs for your application.
 * The resulting HTML when calling `render()` will have each breadcrumb enclosed
 * in `<dt>` tags, while the whole string is enclosed in `<dl>` tags.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Breadcrumbs)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html, Breadcrumbs, phalcon, html_breadcrumbs, phalcon_html_breadcrumbs_method_entry, 0);

	/**
	 * Keeps all the breadcrumbs
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_breadcrumbs_ce, SL("elements"), ZEND_ACC_PRIVATE);
	/**
	 * Crumb separator
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_breadcrumbs_ce, SL("separator"), " / ", ZEND_ACC_PRIVATE);
	/**
	 * The HTML template to use to render the breadcrumbs.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_breadcrumbs_ce, SL("template"), "<dt><a href=\"%link%\">%label%</a></dt>", ZEND_ACC_PRIVATE);
	phalcon_html_breadcrumbs_ce->create_object = zephir_init_properties_Phalcon_Html_Breadcrumbs;

	return SUCCESS;
}

/**
 * Crumb separator
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, getSeparator)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "separator");
}

/**
 * Crumb separator
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, setSeparator)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *separator_param = NULL;
	zval separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&separator);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(separator)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &separator_param);
	zephir_get_strval(&separator, separator_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("separator"), &separator);
	RETURN_THIS();
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
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, add)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *label_param = NULL, *link_param = NULL;
	zval label, link;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&link);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(label)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(link)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &label_param, &link_param);
	zephir_get_strval(&label, label_param);
	if (!link_param) {
		ZEPHIR_INIT_VAR(&link);
		ZVAL_STRING(&link, "");
	} else {
		zephir_get_strval(&link, link_param);
	}


	zephir_update_property_array(this_ptr, SL("elements"), &link, &label);
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


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("elements"), &_0);
	ZEPHIR_MM_RESTORE();
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
	zval *link_param = NULL, elements, _0;
	zval link;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(link)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &link_param);
	zephir_get_strval(&link, link_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&elements, &_0);
	zephir_array_unset(&elements, &link, PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("elements"), &elements);
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
	zval _6$$3, _8$$3, _10$$4, _12$$4, _15$$6, _17$$6;
	zend_string *_4;
	zend_ulong _3;
	zval element, elements, lastLabel, lastUrl, output, template, url, urls, _0, *_1, _2, _18, _19, _5$$3, _7$$3, _9$$4, _11$$4, _13$$5, _14$$6, _16$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_17$$6);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&output);
	array_init(&output);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&elements, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("template"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&template, &_0);
	ZEPHIR_INIT_VAR(&urls);
	zephir_array_keys(&urls, &elements);
	ZEPHIR_MAKE_REF(&urls);
	ZEPHIR_CALL_FUNCTION(&lastUrl, "end", NULL, 344, &urls);
	ZEPHIR_UNREF(&urls);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&lastLabel);
	zephir_array_fetch(&lastLabel, &elements, &lastUrl, PH_NOISY, "phalcon/Html/Breadcrumbs.zep", 112);
	zephir_array_unset(&elements, &lastUrl, PH_SEPARATE);
	zephir_is_iterable(&elements, 0, "phalcon/Html/Breadcrumbs.zep", 133);
	if (Z_TYPE_P(&elements) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&elements), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&url);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&url, _4);
			} else {
				ZVAL_LONG(&url, _3);
			}
			ZEPHIR_INIT_NVAR(&element);
			ZVAL_COPY(&element, _1);
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZEPHIR_INIT_NVAR(&_6$$3);
			zephir_create_array(&_6$$3, 2, 0);
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZVAL_STRING(&_7$$3, "%label%");
			zephir_array_fast_append(&_6$$3, &_7$$3);
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZVAL_STRING(&_7$$3, "%link%");
			zephir_array_fast_append(&_6$$3, &_7$$3);
			ZEPHIR_INIT_NVAR(&_8$$3);
			zephir_create_array(&_8$$3, 2, 0);
			zephir_array_fast_append(&_8$$3, &element);
			zephir_array_fast_append(&_8$$3, &url);
			zephir_fast_str_replace(&_5$$3, &_6$$3, &_8$$3, &template);
			zephir_array_append(&output, &_5$$3, PH_SEPARATE, "phalcon/Html/Breadcrumbs.zep", 127);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &elements, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &elements, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&url, &elements, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&element, &elements, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZEPHIR_INIT_NVAR(&_10$$4);
				zephir_create_array(&_10$$4, 2, 0);
				ZEPHIR_INIT_NVAR(&_11$$4);
				ZVAL_STRING(&_11$$4, "%label%");
				zephir_array_fast_append(&_10$$4, &_11$$4);
				ZEPHIR_INIT_NVAR(&_11$$4);
				ZVAL_STRING(&_11$$4, "%link%");
				zephir_array_fast_append(&_10$$4, &_11$$4);
				ZEPHIR_INIT_NVAR(&_12$$4);
				zephir_create_array(&_12$$4, 2, 0);
				zephir_array_fast_append(&_12$$4, &element);
				zephir_array_fast_append(&_12$$4, &url);
				zephir_fast_str_replace(&_9$$4, &_10$$4, &_12$$4, &template);
				zephir_array_append(&output, &_9$$4, PH_SEPARATE, "phalcon/Html/Breadcrumbs.zep", 127);
			ZEPHIR_CALL_METHOD(NULL, &elements, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&element);
	ZEPHIR_INIT_NVAR(&url);
	if (0 != zephir_fast_count_int(&elements)) {
		ZEPHIR_INIT_VAR(&_13$$5);
		ZEPHIR_CONCAT_SVS(&_13$$5, "<dt>", &lastLabel, "</dt>");
		zephir_array_append(&output, &_13$$5, PH_SEPARATE, "phalcon/Html/Breadcrumbs.zep", 134);
	} else {
		ZEPHIR_INIT_VAR(&_14$$6);
		ZEPHIR_INIT_VAR(&_15$$6);
		zephir_create_array(&_15$$6, 2, 0);
		ZEPHIR_INIT_VAR(&_16$$6);
		ZVAL_STRING(&_16$$6, "%label%");
		zephir_array_fast_append(&_15$$6, &_16$$6);
		ZEPHIR_INIT_NVAR(&_16$$6);
		ZVAL_STRING(&_16$$6, "%link%");
		zephir_array_fast_append(&_15$$6, &_16$$6);
		ZEPHIR_INIT_VAR(&_17$$6);
		zephir_create_array(&_17$$6, 2, 0);
		zephir_array_fast_append(&_17$$6, &lastLabel);
		zephir_array_fast_append(&_17$$6, &lastUrl);
		zephir_fast_str_replace(&_14$$6, &_15$$6, &_17$$6, &template);
		zephir_array_append(&output, &_14$$6, PH_SEPARATE, "phalcon/Html/Breadcrumbs.zep", 146);
	}
	ZEPHIR_INIT_VAR(&_18);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("separator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_19);
	ZEPHIR_CONCAT_SVS(&_19, "<dt>", &_0, "</dt>");
	zephir_fast_join(&_18, &_19, &output);
	ZEPHIR_CONCAT_SVS(return_value, "<dl>", &_18, "</dl>");
	RETURN_MM();
}

/**
 * Returns the internal breadcrumbs array
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, toArray)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "elements");
}

zend_object *zephir_init_properties_Phalcon_Html_Breadcrumbs(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("elements"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("elements"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

