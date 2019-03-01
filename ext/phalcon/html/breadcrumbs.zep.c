
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
 * (c) Phalcon Team <team@phalconphp.com>
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
ZEPHIR_INIT_CLASS(Phalcon_Html_Breadcrumbs) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Html, Breadcrumbs, phalcon, html_breadcrumbs, phalcon_html_breadcrumbs_method_entry, 0);

	/**
	 * Keeps all the breadcrumbs
	 * 
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_breadcrumbs_ce, SL("elements"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * Crumb separator
	 * 
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_breadcrumbs_ce, SL("separator"), " / ", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * The HTML template to use to render the breadcrumbs.
	 * 
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_breadcrumbs_ce, SL("template"), "<dt><a href=\"%link%\">%label%</a></dt>", ZEND_ACC_PRIVATE TSRMLS_CC);

	phalcon_html_breadcrumbs_ce->create_object = zephir_init_properties_Phalcon_Html_Breadcrumbs;
	return SUCCESS;

}

/**
 * Crumb separator
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, getSeparator) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "separator");

}

/**
 * Crumb separator
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, setSeparator) {

	zval *separator_param = NULL;
	zval separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&separator);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &separator_param);

	zephir_get_strval(&separator, separator_param);


	zephir_update_property_zval(this_ptr, SL("separator"), &separator);
	RETURN_THIS();

}

/**
 * Adds a new crumb.
 *
 * <code>
 * // Adding a crumb with a link
 * $breadcrumbs->add("Home", "/");
 *
 * // Adding a crumb without a link (normally the last one)
 * $breadcrumbs->add("Users");
 * </code>
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, add) {

	zval *label_param = NULL, *link_param = NULL;
	zval label, link;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&link);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &label_param, &link_param);

	zephir_get_strval(&label, label_param);
	if (!link_param) {
		ZEPHIR_INIT_VAR(&link);
		ZVAL_STRING(&link, "");
	} else {
		zephir_get_strval(&link, link_param);
	}


	zephir_update_property_array(this_ptr, SL("elements"), &link, &label TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Clears the crumbx
 *
 * <code>
 * $breadcrumbs->clear()
 * </code>
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, clear) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("elements"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes crumb by url.
 *
 * <code>
 * $breadcrumbs->remove("/admin/user/create");
 *
 * // remove a crumb without an url (last link)
 * $breadcrumbs->remove();
 * </code>
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, remove) {

	zval *link_param = NULL, elements, _0;
	zval link;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &link_param);

	zephir_get_strval(&link, link_param);


	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&elements, &_0);
	zephir_array_unset(&elements, &link, PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("elements"), &elements);
	ZEPHIR_MM_RESTORE();

}

/**
 * Renders and outputs breadcrumbs based on previously set template.
 *
 * <code>
 * // Php Engine
 * echo $breadcrumbs->render();
 * </code>
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, render) {

	zval _5$$3, _7$$3, _10$$5, _12$$5;
	zend_string *_3;
	zend_ulong _2;
	zval element, elements, lastLabel, lastUrl, output, template, url, urls, _0, *_1, _13, _14, _4$$3, _6$$3, _8$$4, _9$$5, _11$$5;
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
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&output);
	array_init(&output);
	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&elements, &_0);
	zephir_read_property(&_0, this_ptr, SL("template"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&template, &_0);
	ZEPHIR_INIT_VAR(&urls);
	zephir_array_keys(&urls, &elements TSRMLS_CC);
	ZEPHIR_MAKE_REF(&urls);
	ZEPHIR_CALL_FUNCTION(&lastUrl, "end", NULL, 201, &urls);
	ZEPHIR_UNREF(&urls);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&lastLabel);
	zephir_array_fetch(&lastLabel, &elements, &lastUrl, PH_NOISY, "phalcon/html/breadcrumbs.zep", 113 TSRMLS_CC);
	zephir_array_unset(&elements, &lastUrl, PH_SEPARATE);
	zephir_is_iterable(&elements, 0, "phalcon/html/breadcrumbs.zep", 134);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&elements), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&url);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&url, _3);
		} else {
			ZVAL_LONG(&url, _2);
		}
		ZEPHIR_INIT_NVAR(&element);
		ZVAL_COPY(&element, _1);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZEPHIR_INIT_NVAR(&_5$$3);
		zephir_create_array(&_5$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "%label%");
		zephir_array_fast_append(&_5$$3, &_6$$3);
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "%link%");
		zephir_array_fast_append(&_5$$3, &_6$$3);
		ZEPHIR_INIT_NVAR(&_7$$3);
		zephir_create_array(&_7$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_7$$3, &element);
		zephir_array_fast_append(&_7$$3, &url);
		zephir_fast_str_replace(&_4$$3, &_5$$3, &_7$$3, &template TSRMLS_CC);
		zephir_array_append(&output, &_4$$3, PH_SEPARATE, "phalcon/html/breadcrumbs.zep", 128);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&element);
	ZEPHIR_INIT_NVAR(&url);
	if (0 != zephir_fast_count_int(&elements TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_8$$4);
		ZEPHIR_CONCAT_SVS(&_8$$4, "<dt>", &lastLabel, "</dt>");
		zephir_array_append(&output, &_8$$4, PH_SEPARATE, "phalcon/html/breadcrumbs.zep", 135);
	} else {
		ZEPHIR_INIT_VAR(&_9$$5);
		ZEPHIR_INIT_VAR(&_10$$5);
		zephir_create_array(&_10$$5, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_11$$5);
		ZVAL_STRING(&_11$$5, "%label%");
		zephir_array_fast_append(&_10$$5, &_11$$5);
		ZEPHIR_INIT_NVAR(&_11$$5);
		ZVAL_STRING(&_11$$5, "%link%");
		zephir_array_fast_append(&_10$$5, &_11$$5);
		ZEPHIR_INIT_VAR(&_12$$5);
		zephir_create_array(&_12$$5, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_12$$5, &lastLabel);
		zephir_array_fast_append(&_12$$5, &lastUrl);
		zephir_fast_str_replace(&_9$$5, &_10$$5, &_12$$5, &template TSRMLS_CC);
		zephir_array_append(&output, &_9$$5, PH_SEPARATE, "phalcon/html/breadcrumbs.zep", 147);
	}
	ZEPHIR_INIT_VAR(&_13);
	zephir_read_property(&_0, this_ptr, SL("separator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_14);
	ZEPHIR_CONCAT_SVS(&_14, "<dt>", &_0, "</dt>");
	zephir_fast_join(&_13, &_14, &output TSRMLS_CC);
	ZEPHIR_CONCAT_SVS(return_value, "<dl>", &_13, "</dl>");
	RETURN_MM();

}

/**
 * Returns the internal breadcrumbs array
 */
PHP_METHOD(Phalcon_Html_Breadcrumbs, toArray) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "elements");

}

zend_object *zephir_init_properties_Phalcon_Html_Breadcrumbs(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("elements"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

