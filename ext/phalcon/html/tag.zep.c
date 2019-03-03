
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/iterator.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Html\Tag
 *
 * Phalcon\Tag is designed to simplify building of HTML tags. It provides a set
 * of helpers to dynamically generate HTML.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Tag) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Html, Tag, phalcon, html_tag, phalcon_html_tag_method_entry, 0);

	/**
	 * @var <DiInterface>
	 */
	zend_declare_property_null(phalcon_html_tag_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_tag_ce, SL("append"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_html_tag_ce, SL("docType"), 5, ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var <EscaperInterface>
	 */
	zend_declare_property_null(phalcon_html_tag_ce, SL("escaper"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_tag_ce, SL("prepend"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_tag_ce, SL("separator"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_tag_ce, SL("title"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_tag_ce, SL("values"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @var <UrlInterface>
	 */
	zend_declare_property_null(phalcon_html_tag_ce, SL("url"), ZEND_ACC_PRIVATE TSRMLS_CC);

	phalcon_html_tag_ce->create_object = zephir_init_properties_Phalcon_Html_Tag;
	/**
	 * Constants
	 */
	zephir_declare_class_constant_long(phalcon_html_tag_ce, SL("HTML32"), 1);

	zephir_declare_class_constant_long(phalcon_html_tag_ce, SL("HTML401_STRICT"), 2);

	zephir_declare_class_constant_long(phalcon_html_tag_ce, SL("HTML401_TRANSITIONAL"), 3);

	zephir_declare_class_constant_long(phalcon_html_tag_ce, SL("HTML401_FRAMESET"), 4);

	zephir_declare_class_constant_long(phalcon_html_tag_ce, SL("HTML5"), 5);

	zephir_declare_class_constant_long(phalcon_html_tag_ce, SL("XHTML10_STRICT"), 6);

	zephir_declare_class_constant_long(phalcon_html_tag_ce, SL("XHTML10_TRANSITIONAL"), 7);

	zephir_declare_class_constant_long(phalcon_html_tag_ce, SL("XHTML10_FRAMESET"), 8);

	zephir_declare_class_constant_long(phalcon_html_tag_ce, SL("XHTML11"), 9);

	zephir_declare_class_constant_long(phalcon_html_tag_ce, SL("XHTML20"), 10);

	zephir_declare_class_constant_long(phalcon_html_tag_ce, SL("XHTML5"), 11);

	zend_class_implements(phalcon_html_tag_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;

}

/**
 * Appends a text to current document title
 */
PHP_METHOD(Phalcon_Html_Tag, appendTitle) {

	zval *title_param = NULL;
	zval title;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&title);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &title_param);

	zephir_get_arrval(&title, title_param);


	zephir_update_property_zval(this_ptr, SL("append"), &title);
	RETURN_THIS();

}

/**
 * Builds a HTML input[type="button"] tag
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->button('Click Me')
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ button('Click Me) }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, button) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "button");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Resets the request and internal values to avoid those fields will have
 * any default value.
 */
PHP_METHOD(Phalcon_Html_Tag, clear) {

	zval _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("append"), &_0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, 5);
	zephir_update_property_zval(this_ptr, SL("docType"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	zephir_update_property_zval(this_ptr, SL("prepend"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "");
	zephir_update_property_zval(this_ptr, SL("separator"), &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "");
	zephir_update_property_zval(this_ptr, SL("title"), &_3);
	ZEPHIR_INIT_NVAR(&_3);
	array_init(&_3);
	zephir_update_property_zval(this_ptr, SL("values"), &_3);
	ZEPHIR_MM_RESTORE();

}

/**
 * Builds a HTML tag
 *
 * Parameters
 * `onlyStart` Only process the start of th element
 * `selfClose` It is a self close element
 * `useEol`    Append PHP_EOL at the end
 *
 */
PHP_METHOD(Phalcon_Html_Tag, element) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval parameters;
	zval *tag_param = NULL, *parameters_param = NULL, onlyStart, output, selfClose, useEol, _1, _2, _5$$9;
	zval tag, _3, _4$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&onlyStart);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&selfClose);
	ZVAL_UNDEF(&useEol);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tag_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(tag_param) != IS_STRING && Z_TYPE_P(tag_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tag' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tag_param) == IS_STRING)) {
		zephir_get_strval(&tag, tag_param);
	} else {
		ZEPHIR_INIT_VAR(&tag);
		ZVAL_EMPTY_STRING(&tag);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "useEol");
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_CE_STATIC(&useEol, phalcon_helper_arr_ce, "get", &_0, 155, &parameters, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "onlyStart");
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_CE_STATIC(&onlyStart, phalcon_helper_arr_ce, "get", &_0, 155, &parameters, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "selfClose");
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_CE_STATIC(&selfClose, phalcon_helper_arr_ce, "get", &_0, 155, &parameters, &_1, &_2);
	zephir_check_call_status();
	zephir_array_unset_string(&parameters, SL("onlyStart"), PH_SEPARATE);
	zephir_array_unset_string(&parameters, SL("selfClose"), PH_SEPARATE);
	zephir_array_unset_string(&parameters, SL("useEol"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "<", &tag);
	ZEPHIR_CALL_METHOD(&output, this_ptr, "renderattributes", NULL, 201, &_3, &parameters);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("docType"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_2, 5)) {
		if (zephir_is_true(&selfClose)) {
			zephir_concat_self_str(&output, SL(" />") TSRMLS_CC);
		} else {
			zephir_concat_self_str(&output, SL(">") TSRMLS_CC);
		}
	} else {
		if (zephir_is_true(&onlyStart)) {
			zephir_concat_self_str(&output, SL(">") TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(&_4$$8);
			ZEPHIR_CONCAT_SVS(&_4$$8, "></", &tag, ">");
			zephir_concat_self(&output, &_4$$8 TSRMLS_CC);
		}
	}
	if (zephir_is_true(&useEol)) {
		ZEPHIR_INIT_VAR(&_5$$9);
		ZEPHIR_GET_CONSTANT(&_5$$9, "PHP_EOL");
		zephir_concat_self(&output, &_5$$9 TSRMLS_CC);
	}
	RETURN_CCTOR(&output);

}

/**
 * Builds the closing tag of an html element
 *
 * Parameters
 * `useEol`    Append PHP_EOL at the end
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tab = new Tag();
 *
 * echo $tag->elementClose(
 *     [
 *         'name' => 'aside',
 *     ]
 * ); // </aside>
 *
 * echo $tag->elementClose(
 *     [
 *         'name'   => 'aside',
 *         'useEol' => true,
 *     ]
 * ); // '</aside>' . PHP_EOL
 * </code>
 *
 */
PHP_METHOD(Phalcon_Html_Tag, elementClose) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval parameters;
	zval *tag_param = NULL, *parameters_param = NULL, useEol, _1, _2, _3$$3;
	zval tag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&useEol);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tag_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(tag_param) != IS_STRING && Z_TYPE_P(tag_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tag' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tag_param) == IS_STRING)) {
		zephir_get_strval(&tag, tag_param);
	} else {
		ZEPHIR_INIT_VAR(&tag);
		ZVAL_EMPTY_STRING(&tag);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&useEol);
	ZVAL_BOOL(&useEol, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "useEol");
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_CE_STATIC(&useEol, phalcon_helper_arr_ce, "get", &_0, 155, &parameters, &_1, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&useEol)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_GET_CONSTANT(&_3$$3, "PHP_EOL");
		ZEPHIR_CONCAT_SVSV(return_value, "</", &tag, ">", &_3$$3);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "</", &tag, ">");
	RETURN_MM();

}

/**
 * Returns the closing tag of a form element
 */
PHP_METHOD(Phalcon_Html_Tag, endForm) {

	zval *eol_param = NULL, _0$$3;
	zend_bool eol;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &eol_param);

	if (!eol_param) {
		eol = 1;
	} else {
		eol = zephir_get_boolval(eol_param);
	}


	if (eol) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_GET_CONSTANT(&_0$$3, "PHP_EOL");
		ZEPHIR_CONCAT_SV(return_value, "</form>", &_0$$3);
		RETURN_MM();
	} else {
		RETURN_MM_STRING("</form>");
	}

}

/**
 * Builds a HTML FORM tag
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tab = new Tag();
 *
 * echo $tag->form('posts/save');
 *
 * echo $tag->form(
 *     'posts/save',
 *     [
 *         "method" => "post",
 *     ]
 * );
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ form('posts/save') }}
 * {{ form('posts/save', ['method': 'post') }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, form) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *action_param = NULL, *parameters_param = NULL, output, params, service, _0, _1, _3, _4, _6, _5$$3;
	zval action;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &action_param, &parameters_param);

	zephir_get_strval(&action, action_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "url");
	ZEPHIR_CALL_METHOD(&service, this_ptr, "getservice", NULL, 202, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "method");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "post");
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_helper_arr_ce, "get", &_2, 155, &parameters, &_0, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&parameters, SL("method"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_4, &service, "get", NULL, 0, &action);
	zephir_check_call_status();
	zephir_array_update_string(&parameters, SL("action"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&params);
	if (zephir_array_isset_string_fetch(&params, &parameters, SL("parameters"), 0)) {
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_SV(&_5$$3, "?", &params);
		zephir_array_update_string(&parameters, SL("action"), &_5$$3, PH_COPY | PH_SEPARATE);
		zephir_array_unset_string(&parameters, SL("parameters"), PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "<form");
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "renderattributes", NULL, 201, &_0, &parameters);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&output);
	ZEPHIR_CONCAT_VS(&output, &_6, ">");
	RETURN_CCTOR(&output);

}

/**
 * Converts text to URL-friendly strings
 *
 * Parameters
 * `text`      The text to be processed
 * `separator` Separator to use (default '-')
 * `lowercase` Convert to lowercase
 * `replace`
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tab = new Tag();
 *
 * echo $tag->friendlyTitle(
 *     [
 *         'text'       => 'These are big important news',
 *         'separator' => '-',
 *     ]
 * );
 * </code>
 *
 * Volt Syntax:
 * <code>
 * {{ friendly_title(['text': 'These are big important news', 'separator': '-']) }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, friendlyTitle) {

	zend_bool _10$$4;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *text_param = NULL, *parameters_param = NULL, count, from, locale, lowercase, replace, separator, to, output, _0, _1, _7, _8, _9, _15, _2$$3, _3$$3, _4$$3, _5$$3, _11$$4, _12$$4, _13$$4, _14$$8, _16$$9;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&count);
	ZVAL_UNDEF(&from);
	ZVAL_UNDEF(&locale);
	ZVAL_UNDEF(&lowercase);
	ZVAL_UNDEF(&replace);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&to);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "iconv");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 123, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZVAL_LONG(&_2$$3, 6);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "en_US.UTF-8");
		ZEPHIR_CALL_FUNCTION(&locale, "setlocale", NULL, 203, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "UTF-8");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "ASCII//TRANSLIT");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "iconv", NULL, 204, &_3$$3, &_4$$3, &text);
		zephir_check_call_status();
		zephir_get_strval(&text, &_5$$3);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "lowercase");
	ZVAL_BOOL(&_7, 1);
	ZEPHIR_CALL_CE_STATIC(&lowercase, phalcon_helper_arr_ce, "get", &_6, 155, &parameters, &_0, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	array_init(&_0);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "replace");
	ZEPHIR_CALL_CE_STATIC(&replace, phalcon_helper_arr_ce, "get", &_6, 155, &parameters, &_8, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "separator");
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "-");
	ZEPHIR_CALL_CE_STATIC(&separator, phalcon_helper_arr_ce, "get", &_6, 155, &parameters, &_8, &_9);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&replace))) {
		_10$$4 = Z_TYPE_P(&replace) != IS_ARRAY;
		if (_10$$4) {
			_10$$4 = Z_TYPE_P(&replace) != IS_STRING;
		}
		if (_10$$4) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_html_exception_ce, "Parameter replace must be an array or a string", "phalcon/html/tag.zep", 324);
			return;
		}
		if (Z_TYPE_P(&replace) == IS_STRING) {
			ZEPHIR_INIT_VAR(&from);
			zephir_create_array(&from, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&from, &replace);
		} else {
			ZEPHIR_CPY_WRT(&from, &replace);
		}
		ZEPHIR_INIT_VAR(&count);
		ZVAL_LONG(&count, zephir_fast_count_int(&from TSRMLS_CC));
		ZVAL_LONG(&_11$$4, 0);
		ZVAL_LONG(&_12$$4, (zephir_get_numberval(&count) - 1));
		ZEPHIR_INIT_VAR(&_13$$4);
		ZVAL_STRING(&_13$$4, " ");
		ZEPHIR_CALL_FUNCTION(&to, "array_fill", NULL, 205, &_11$$4, &_12$$4, &_13$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_13$$4);
		zephir_fast_str_replace(&_13$$4, &from, &to, &text TSRMLS_CC);
		zephir_get_strval(&text, &_13$$4);
	}
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "/[^a-zA-Z0-9\\/_|+ -]/");
	ZEPHIR_INIT_NVAR(&_9);
	ZVAL_STRING(&_9, "");
	ZEPHIR_CALL_FUNCTION(&output, "preg_replace", NULL, 21, &_8, &_9, &text);
	zephir_check_call_status();
	if (zephir_is_true(&lowercase)) {
		ZEPHIR_INIT_VAR(&_14$$8);
		zephir_fast_strtolower(&_14$$8, &output);
		ZEPHIR_CPY_WRT(&output, &_14$$8);
	}
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "/[\\/_|+ -]+/");
	ZEPHIR_CALL_FUNCTION(&_15, "preg_replace", NULL, 21, &_8, &separator, &output);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&output, &_15);
	ZEPHIR_INIT_NVAR(&_8);
	zephir_fast_trim(&_8, &output, &separator, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(&output, &_8);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "iconv");
	ZEPHIR_CALL_FUNCTION(&_15, "extension_loaded", NULL, 123, &_8);
	zephir_check_call_status();
	if (zephir_is_true(&_15)) {
		ZVAL_LONG(&_16$$9, 6);
		ZEPHIR_CALL_FUNCTION(NULL, "setlocale", NULL, 203, &_16$$9, &locale);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&output);

}

/**
 * Returns the internal dependency injector
 */
PHP_METHOD(Phalcon_Html_Tag, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * Get the document type declaration of content. If the docType has not
 * been set properly, XHTML5 is returned
 */
PHP_METHOD(Phalcon_Html_Tag, getDocType) {

	zval _0, _18, _1$$3, _2$$4, _3$$4, _4$$5, _5$$5, _6$$6, _7$$6, _8$$7, _9$$7, _10$$8, _11$$8, _12$$9, _13$$9, _14$$10, _15$$10, _16$$11, _17$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("docType"), PH_NOISY_CC | PH_READONLY);
	do {
		if (ZEPHIR_IS_LONG(&_0, 1)) {
			ZEPHIR_INIT_VAR(&_1$$3);
			ZEPHIR_GET_CONSTANT(&_1$$3, "PHP_EOL");
			ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">", &_1$$3);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 2)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_GET_CONSTANT(&_2$$4, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_GET_CONSTANT(&_3$$4, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\"", &_2$$4, "\t\"http://www.w3.org/TR/html4/strict.dtd\">", &_3$$4);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 3)) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZEPHIR_GET_CONSTANT(&_4$$5, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_5$$5);
			ZEPHIR_GET_CONSTANT(&_5$$5, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"", &_4$$5, "\t\"http://www.w3.org/TR/html4/loose.dtd\">", &_5$$5);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 4)) {
			ZEPHIR_INIT_VAR(&_6$$6);
			ZEPHIR_GET_CONSTANT(&_6$$6, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_7$$6);
			ZEPHIR_GET_CONSTANT(&_7$$6, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\"", &_6$$6, "\t\"http://www.w3.org/TR/html4/frameset.dtd\">", &_7$$6);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 6)) {
			ZEPHIR_INIT_VAR(&_8$$7);
			ZEPHIR_GET_CONSTANT(&_8$$7, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_9$$7);
			ZEPHIR_GET_CONSTANT(&_9$$7, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\"", &_8$$7, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">", &_9$$7);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 7)) {
			ZEPHIR_INIT_VAR(&_10$$8);
			ZEPHIR_GET_CONSTANT(&_10$$8, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_11$$8);
			ZEPHIR_GET_CONSTANT(&_11$$8, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\"", &_10$$8, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">", &_11$$8);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 8)) {
			ZEPHIR_INIT_VAR(&_12$$9);
			ZEPHIR_GET_CONSTANT(&_12$$9, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_13$$9);
			ZEPHIR_GET_CONSTANT(&_13$$9, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\"", &_12$$9, "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">", &_13$$9);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 9)) {
			ZEPHIR_INIT_VAR(&_14$$10);
			ZEPHIR_GET_CONSTANT(&_14$$10, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_15$$10);
			ZEPHIR_GET_CONSTANT(&_15$$10, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\"", &_14$$10, "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">", &_15$$10);
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 10)) {
			ZEPHIR_INIT_VAR(&_16$$11);
			ZEPHIR_GET_CONSTANT(&_16$$11, "PHP_EOL");
			ZEPHIR_INIT_VAR(&_17$$11);
			ZEPHIR_GET_CONSTANT(&_17$$11, "PHP_EOL");
			ZEPHIR_CONCAT_SVSV(return_value, "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\"", &_16$$11, "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">", &_17$$11);
			RETURN_MM();
		}
	} while(0);

	ZEPHIR_INIT_VAR(&_18);
	ZEPHIR_GET_CONSTANT(&_18, "PHP_EOL");
	ZEPHIR_CONCAT_SV(return_value, "<!DOCTYPE html>", &_18);
	RETURN_MM();

}

/**
 * Gets the current document title. The title will be automatically escaped.
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * $tag
 *		->setTitleSeparator(' ')
 * 		->prependTitle(['Hello'])
 * 		->setTitle('World')
 * 		->appendTitle(['from Phalcon']);
 *
 * echo $tag->getTitle();             // Hello World from Phalcon
 * echo $tag->getTitle(false);        // World from Phalcon
 * echo $tag->getTitle(true, false);  // Hello World
 * echo $tag->getTitle(false, false); // World
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ get_title() }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, getTitle) {

	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_12 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prepend_param = NULL, *append_param = NULL, item, items, output, title, appendTitle, prependTitle, separator, escaper, _0, _1, _2, prependArray$$4, *_3$$4, _4$$4, _5$$5, _7$$6, *_9$$9, _10$$9, _11$$10, _13$$11;
	zend_bool prepend, append;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&title);
	ZVAL_UNDEF(&appendTitle);
	ZVAL_UNDEF(&prependTitle);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&prependArray$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_13$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &prepend_param, &append_param);

	if (!prepend_param) {
		prepend = 1;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}
	if (!append_param) {
		append = 1;
	} else {
		append = zephir_get_boolval(append_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "escaper");
	ZEPHIR_CALL_METHOD(&escaper, this_ptr, "getservice", NULL, 202, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&items);
	array_init(&items);
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	zephir_read_property(&_1, this_ptr, SL("title"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&title, &escaper, "escapehtml", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("separator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&separator, &escaper, "escapehtml", NULL, 0, &_2);
	zephir_check_call_status();
	if (prepend) {
		ZEPHIR_OBS_VAR(&prependTitle);
		zephir_read_property(&prependTitle, this_ptr, SL("prepend"), PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(&prependTitle))) {
			ZEPHIR_CALL_FUNCTION(&prependArray$$4, "array_reverse", NULL, 206, &prependTitle);
			zephir_check_call_status();
			zephir_is_iterable(&prependArray$$4, 0, "phalcon/html/tag.zep", 463);
			if (Z_TYPE_P(&prependArray$$4) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&prependArray$$4), _3$$4)
				{
					ZEPHIR_INIT_NVAR(&item);
					ZVAL_COPY(&item, _3$$4);
					ZEPHIR_CALL_METHOD(&_5$$5, &escaper, "escapehtml", &_6, 0, &item);
					zephir_check_call_status();
					zephir_array_append(&items, &_5$$5, PH_SEPARATE, "phalcon/html/tag.zep", 461);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &prependArray$$4, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_4$$4, &prependArray$$4, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_4$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&item, &prependArray$$4, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_7$$6, &escaper, "escapehtml", &_8, 0, &item);
						zephir_check_call_status();
						zephir_array_append(&items, &_7$$6, PH_SEPARATE, "phalcon/html/tag.zep", 461);
					ZEPHIR_CALL_METHOD(NULL, &prependArray$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&item);
		}
	}
	if (!(ZEPHIR_IS_EMPTY(&title))) {
		zephir_array_append(&items, &title, PH_SEPARATE, "phalcon/html/tag.zep", 467);
	}
	if (append) {
		ZEPHIR_OBS_VAR(&appendTitle);
		zephir_read_property(&appendTitle, this_ptr, SL("append"), PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(&appendTitle))) {
			zephir_is_iterable(&appendTitle, 0, "phalcon/html/tag.zep", 477);
			if (Z_TYPE_P(&appendTitle) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&appendTitle), _9$$9)
				{
					ZEPHIR_INIT_NVAR(&item);
					ZVAL_COPY(&item, _9$$9);
					ZEPHIR_CALL_METHOD(&_11$$10, &escaper, "escapehtml", &_12, 0, &item);
					zephir_check_call_status();
					zephir_array_append(&items, &_11$$10, PH_SEPARATE, "phalcon/html/tag.zep", 475);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &appendTitle, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_10$$9, &appendTitle, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_10$$9)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&item, &appendTitle, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_13$$11, &escaper, "escapehtml", &_14, 0, &item);
						zephir_check_call_status();
						zephir_array_append(&items, &_13$$11, PH_SEPARATE, "phalcon/html/tag.zep", 475);
					ZEPHIR_CALL_METHOD(NULL, &appendTitle, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&item);
		}
	}
	if (!(ZEPHIR_IS_EMPTY(&items))) {
		ZEPHIR_INIT_NVAR(&output);
		zephir_fast_join(&output, &separator, &items TSRMLS_CC);
	}
	RETURN_CCTOR(&output);

}

/**
 * Gets the current document title separator
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->getTitleSeparator();
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ get_title_separator() }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, getTitleSeparator) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "separator");

}

/**
 * Every helper calls this function to check whether a component has a predefined
 * value using `setAttribute` or value from $_POST
 */
PHP_METHOD(Phalcon_Html_Tag, getValue) {

	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _POST, value, _0$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	zephir_get_strval(&name, name_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_OBS_VAR(&value);
	if (!(zephir_array_isset_string_fetch(&value, &parameters, SL("value"), 0))) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_read_property(&_0$$3, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset_fetch(&value, &_0$$3, &name, 0 TSRMLS_CC))) {
			ZEPHIR_OBS_NVAR(&value);
			if (!(zephir_array_isset_fetch(&value, &_POST, &name, 0 TSRMLS_CC))) {
				RETURN_MM_NULL();
			}
		}
	}
	RETURN_CCTOR(&value);

}

/**
 * Check if a helper has a default value set using `setAttribute()` or
 * value from $_POST
 */
PHP_METHOD(Phalcon_Html_Tag, hasValue) {

	zend_bool _1;
	zval *name_param = NULL, _POST, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset(&_0, &name);
	if (!(_1)) {
		_1 = zephir_array_isset(&_POST, &name);
	}
	RETURN_MM_BOOL(_1);

}

/**
 * Builds HTML IMG tags
 *
 * Parameters
 * `local` Local resource or not (default `true`)
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->image('img/bg.png');
 *
 * echo $tag->image(
 *     'img/photo.jpg',
 *     [
 *         'alt' => 'Some Photo',
 *     ]
 * );
 *
 * echo $tag->image(
 *     'http://static.mywebsite.com/img/bg.png',
 *     [
 *         'local' => false,
 *     ]
 * );
 * </code>
 *
 * Volt Syntax:
 * <code>
 * {{ image('img/bg.png') }}
 * {{ image('img/photo.jpg', ['alt': 'Some Photo') }}
 * {{ image('http://static.mywebsite.com/img/bg.png', ['local': false]) }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, image) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval parameters;
	zval *url_param = NULL, *parameters_param = NULL, local, service, src, output, _1, _2, _4, _5, _3$$3;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&local);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&src);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &url_param, &parameters_param);

	if (!url_param) {
		ZEPHIR_INIT_VAR(&url);
		ZVAL_STRING(&url, "");
	} else {
		zephir_get_strval(&url, url_param);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "local");
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_CALL_CE_STATIC(&local, phalcon_helper_arr_ce, "get", &_0, 155, &parameters, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "src");
	ZEPHIR_CALL_CE_STATIC(&src, phalcon_helper_arr_ce, "get", &_0, 155, &parameters, &_1, &url);
	zephir_check_call_status();
	if (zephir_is_true(&local)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "url");
		ZEPHIR_CALL_METHOD(&service, this_ptr, "getservice", NULL, 202, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&src, &service, "getstatic", NULL, 0, &url);
		zephir_check_call_status();
	}
	zephir_array_unset_string(&parameters, SL("local"), PH_SEPARATE);
	zephir_array_update_string(&parameters, SL("src"), &src, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "<img");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "renderattributes", NULL, 201, &_1, &parameters);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "renderclosetag", NULL, 207);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&output);
	ZEPHIR_CONCAT_VV(&output, &_4, &_5);
	RETURN_CCTOR(&output);

}

/**
 * Builds a HTML input[type="check"] tag
 *
 *<code>
 * echo $tag->inputCheckbox(
 *     [
 *         'name'  => 'terms,
 *         'value' => 'Y',
 *     ]
 * );
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ input_checkbox(['name': 'terms, 'value': 'Y']) }}
 *</code>
 *
 * @param array parameters
 */
PHP_METHOD(Phalcon_Html_Tag, inputCheckbox) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "checkbox");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinputchecked", NULL, 208, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='color'] tag
 */
PHP_METHOD(Phalcon_Html_Tag, inputColor) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "color");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='date'] tag
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->inputDate(
 *     [
 *         'name'  => 'born',
 *         'value' => '14-12-1980',
 *     ]
 * );
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ input_date(['name':'born', 'value':'14-12-1980']) }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, inputDate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "date");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='datetime'] tag
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->inputDateTime(
 *     [
 *         'name'  => 'born',
 *         'value' => '14-12-1980',
 *     ]
 * );
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ input_date_time(['name':'born', 'value':'14-12-1980']) }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, inputDateTime) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "datetime");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='datetime-local'] tag
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->inputDateTimeLocal(
 *     [
 *         'name'  => 'born',
 *         'value' => '14-12-1980',
 *     ]
 * );
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ input_date_time_local(['name':'born', 'value':'14-12-1980']) }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, inputDateTimeLocal) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "datetime-local");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='email'] tag
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->inputEmail(
 *     [
 *         'name' => 'email',
 *     ]
 * );
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ input_email(['name': 'email']);
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, inputEmail) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "email");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='file'] tag
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->inputFile(
 *     [
 *         'name' => 'file',
 *     ]
 * );
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ input_file(['name': 'file']);
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, inputFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "file");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='hidden'] tag
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->inputHidden(
 *     [
 *         'name'  => 'my-field',
 *         'value' => 'mike',
 *     ]
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, inputHidden) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "hidden");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="image"] tag
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 * echo $tag->inputImage(
 *     [
 *         'src' => '/img/button.png',
 *     ]
 * );
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ input_image(['src': '/img/button.png']) }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, inputImage) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "image");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='month'] tag
 */
PHP_METHOD(Phalcon_Html_Tag, inputMonth) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "month");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='number'] tag
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->numericField(
 *     [
 *         'name' => 'price',
 *         'min'  => '1',
 *         'max'  => '5',
 *     ]
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, inputNumeric) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "numeric");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='password'] tag
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->passwordField(
 *     [
 *         'name' => 'my-field',
 *         'size' => 30,
 *     ]
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, inputPassword) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "password");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type="radio"] tag
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->inputRadio(
 *     [
 *         'name'  => 'weather',
 *         'value" => 'hot',
 *     ]
 * );
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ input_radio(['name': 'weather', 'value": 'hot']) }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, inputRadio) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "radio");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinputchecked", NULL, 208, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='range'] tag
 */
PHP_METHOD(Phalcon_Html_Tag, inputRange) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "range");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='search'] tag
 */
PHP_METHOD(Phalcon_Html_Tag, inputSearch) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "search");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='tel'] tag
 */
PHP_METHOD(Phalcon_Html_Tag, inputTel) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "tel");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='text'] tag
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->inputText(
 *     [
 *         'name' => 'my-field',
 *         'size' => 30,
 *     ]
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, inputText) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "text");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='time'] tag
 */
PHP_METHOD(Phalcon_Html_Tag, inputTime) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "time");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='url'] tag
 */
PHP_METHOD(Phalcon_Html_Tag, inputUrl) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "url");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML input[type='week'] tag
 */
PHP_METHOD(Phalcon_Html_Tag, inputWeek) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "week");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a script[type="javascript"] tag
 *
 * Parameters
 * `local` Local resource or not (default `true`)
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 * echo $tag->javascript(
 *     'http://ajax.googleapis.com/ajax/libs/jquery/2.2.3/jquery.min.js',
 * 	   ['local' => false]
 * );
 * echo $tag->javascript('javascript/jquery.js');
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ javascript('http://ajax.googleapis.com/ajax/libs/jquery/2.2.3/jquery.min.js', ['local': false]) }}
 * {{ javascript('javascript/jquery.js') }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, javascript) {

	zend_bool local = 0, _7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval parameters;
	zval *url_param = NULL, *parameters_param = NULL, service, output, _0, _2, _3, _6, _8, _9, _10, _4$$3, _5$$3;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url_param, &parameters_param);

	zephir_get_strval(&url, url_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "local");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_helper_arr_ce, "get", &_1, 155, &parameters, &_2, &_3);
	zephir_check_call_status();
	local = zephir_get_boolval(&_0);
	if (local == 1) {
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "url");
		ZEPHIR_CALL_METHOD(&service, this_ptr, "getservice", NULL, 202, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, &service, "getstatic", NULL, 0, &url);
		zephir_check_call_status();
		zephir_array_update_string(&parameters, SL("src"), &_5$$3, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_update_string(&parameters, SL("src"), &url, PH_COPY | PH_SEPARATE);
	}
	zephir_array_unset_string(&parameters, SL("local"), PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "type");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "text/javascript");
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_helper_arr_ce, "get", &_1, 155, &parameters, &_2, &_6);
	zephir_check_call_status();
	zephir_array_update_string(&parameters, SL("type"), &_0, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_3, this_ptr, SL("docType"), PH_NOISY_CC | PH_READONLY);
	_7 = ZEPHIR_GE_LONG(&_3, 5);
	if (_7) {
		zephir_array_fetch_string(&_8, &parameters, SL("type"), PH_NOISY | PH_READONLY, "phalcon/html/tag.zep", 998 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_9);
		ZVAL_STRING(&_9, "text/javascript");
		_7 = ZEPHIR_IS_EQUAL(&_9, &_8);
	}
	if (_7) {
		zephir_array_unset_string(&parameters, SL("type"), PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "<script");
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "renderattributes", NULL, 201, &_2, &parameters);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_GET_CONSTANT(&_2, "PHP_EOL");
	ZEPHIR_INIT_VAR(&output);
	ZEPHIR_CONCAT_VSV(&output, &_10, "></script>", &_2);
	RETURN_CCTOR(&output);

}

/**
 * Builds a HTML A tag using framework conventions
 *
 * Parameters
 * `local` Local resource or not (default `true`)
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->link('signup/register', 'Register Here!');
 *
 * echo $tag->link(
 *     'signup/register',
 *     'Register Here!',
 *     [
 *         'class' => 'btn-primary',
 *     ]
 * );
 *
 * echo $tag->link(
 *     'https://phalconphp.com/',
 *     'Phalcon!',
 *     [
 *         'local' => false,
 *     ]
 * );
 *
 * echo $tag->linkTo(
 *     'https://phalconphp.com/',
 *     'Phalcon!',
 *     [
 *         'local'  => false,
 *         'target' => '_new'
 *     ]
 * );
 *
 *</code>
 */
PHP_METHOD(Phalcon_Html_Tag, link) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *url_param = NULL, text, *text_param = NULL, *parameters_param = NULL, local, query, output, service, _0, _1, _3, _4, _5;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&local);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &url_param, &text_param, &parameters_param);

	zephir_get_strval(&url, url_param);
	if (!text_param) {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_STRING(&text, "");
	} else {
		zephir_get_strval(&text, text_param);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "url");
	ZEPHIR_CALL_METHOD(&service, this_ptr, "getservice", NULL, 202, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "url");
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_helper_arr_ce, "get", &_2, 155, &parameters, &_0, &url);
	zephir_check_call_status();
	zephir_get_strval(&url, &_1);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "text");
	ZEPHIR_CALL_CE_STATIC(&_3, phalcon_helper_arr_ce, "get", &_2, 155, &parameters, &_0, &text);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&text, &_3);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "local");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_CE_STATIC(&local, phalcon_helper_arr_ce, "get", &_2, 155, &parameters, &_0, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "query");
	ZVAL_NULL(&_4);
	ZEPHIR_CALL_CE_STATIC(&query, phalcon_helper_arr_ce, "get", &_2, 155, &parameters, &_0, &_4);
	zephir_check_call_status();
	zephir_array_unset_string(&parameters, SL("url"), PH_SEPARATE);
	zephir_array_unset_string(&parameters, SL("local"), PH_SEPARATE);
	zephir_array_unset_string(&parameters, SL("text"), PH_SEPARATE);
	zephir_array_unset_string(&parameters, SL("query"), PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_3, &service, "get", NULL, 0, &url, &query, &local);
	zephir_check_call_status();
	zephir_array_update_string(&parameters, SL("href"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "<a");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "renderattributes", NULL, 201, &_0, &parameters);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&output);
	ZEPHIR_CONCAT_VSVS(&output, &_5, ">", &text, "</a>");
	RETURN_CCTOR(&output);

}

/**
 * Prepends a text to current document title
 */
PHP_METHOD(Phalcon_Html_Tag, prependTitle) {

	zval *title_param = NULL;
	zval title;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&title);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &title_param);

	zephir_get_arrval(&title, title_param);


	zephir_update_property_zval(this_ptr, SL("prepend"), &title);
	RETURN_THIS();

}

/**
 * Renders the title with title tags. The title is automaticall escaped
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * $tag
 *		->setTitleSeparator(' ')
 * 		->prependTitle(['Hello'])
 * 		->setTitle('World')
 * 		->appendTitle(['from Phalcon']);
 *
 * echo $tag->renderTitle();             // <title>Hello World from Phalcon</title>
 * echo $tag->renderTitle(false);        // <title>World from Phalcon</title>
 * echo $tag->renderTitle(true, false);  // <title>Hello World</title>
 * echo $tag->renderTitle(false, false); // <title>World</title>
 * </code>
 *
 * <code>
 * {{ render_title() }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, renderTitle) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prepend_param = NULL, *append_param = NULL, _0, _1, _2, _3;
	zend_bool prepend, append;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &prepend_param, &append_param);

	if (!prepend_param) {
		prepend = 1;
	} else {
		prepend = zephir_get_boolval(prepend_param);
	}
	if (!append_param) {
		append = 1;
	} else {
		append = zephir_get_boolval(append_param);
	}


	if (prepend) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	if (append) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettitle", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_GET_CONSTANT(&_3, "PHP_EOL");
	ZEPHIR_CONCAT_SVSV(return_value, "<title>", &_0, "</title>", &_3);
	RETURN_MM();

}

/**
 * Builds a HTML input[type="reset"] tag
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->reset('Reset')
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ reset('Save') }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, reset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "reset");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a select element. It accepts an array or a resultset from
 * a Phalcon\Mvc\Model
 *
 *<code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->select(
 *     'status',
 *     [
 *         'id'        => 'status-id',
 *         'useEmpty'  => true,
 *         'emptyValue => '',
 *         'emptyText' => 'Choose Status...',
 *     ],
 *     [
 *         'A' => 'Active',
 *         'I' => 'Inactive',
 *     ]
 * );
 *
 * echo $tag->select(
 *     'status',
 *     [
 *         'id'        => 'status-id',
 *         'useEmpty'  => true,
 *         'emptyValue => '',
 *         'emptyText' => 'Choose Type...',
 *         'using'     => [
 *             'id,
 *             'name',
 *         ],
 *     ],
 *     Robots::find(
 *         [
 *             'conditions' => 'type = :type:',
 *             'bind'       => [
 *                 'type' => 'mechanical',
 *             ]
 *         ]
 *     )
 * );
 *
 *</code>
 *
 * @param array parameters
 * @param array data
 */
PHP_METHOD(Phalcon_Html_Tag, select) {

	zend_bool _4, _7$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, *data = NULL, data_sub, __$null, emptyText, emptyValue, id, output, outputEmpty, useEmpty, using, value, _1, _2, _3, _11, _5$$4, _6$$4, _8$$7, _9$$7, _10$$7, _12$$10, _13$$10, _14$$10, _15$$11, _16$$11, _17$$11;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&emptyText);
	ZVAL_UNDEF(&emptyValue);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&outputEmpty);
	ZVAL_UNDEF(&useEmpty);
	ZVAL_UNDEF(&using);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &parameters_param, &data);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "id");
	ZEPHIR_CALL_CE_STATIC(&id, phalcon_helper_arr_ce, "get", &_0, 155, &parameters, &_1, &name);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "name");
	ZEPHIR_CALL_CE_STATIC(&_2, phalcon_helper_arr_ce, "get", &_0, 155, &parameters, &_1, &name);
	zephir_check_call_status();
	zephir_get_strval(&name, &_2);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "useEmpty");
	ZVAL_BOOL(&_3, 0);
	ZEPHIR_CALL_CE_STATIC(&useEmpty, phalcon_helper_arr_ce, "get", &_0, 155, &parameters, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&using);
	array_init(&using);
	zephir_array_update_string(&parameters, SL("name"), &name, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&parameters, SL("id"), &id, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&outputEmpty);
	ZVAL_STRING(&outputEmpty, "");
	_4 = Z_TYPE_P(data) != IS_ARRAY;
	if (_4) {
		_4 = !ZEPHIR_IS_STRING_IDENTICAL(data, "object");
	}
	if (_4) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_html_exception_ce, "The dataset must be either an array or a ResultsetInterface", "phalcon/html/tag.zep", 1196);
		return;
	}
	if (Z_TYPE_P(data) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_5$$4);
		array_init(&_5$$4);
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "using");
		ZEPHIR_CALL_CE_STATIC(&using, phalcon_helper_arr_ce, "get", &_0, 155, &parameters, &_6$$4, &_5$$4);
		zephir_check_call_status();
		_7$$4 = Z_TYPE_P(&using) == IS_ARRAY;
		if (_7$$4) {
			_7$$4 = zephir_fast_count_int(&using TSRMLS_CC) == 2;
		}
		if (_7$$4) {
			zephir_array_unset_string(&parameters, SL("using"), PH_SEPARATE);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_html_exception_ce, "The 'using' parameter is not a valid array", "phalcon/html/tag.zep", 1207);
			return;
		}
	}
	if (zephir_is_true(&useEmpty)) {
		ZEPHIR_INIT_VAR(&_8$$7);
		ZVAL_STRING(&_8$$7, "emptyText");
		ZEPHIR_INIT_VAR(&_9$$7);
		ZVAL_STRING(&_9$$7, "Choose...");
		ZEPHIR_CALL_CE_STATIC(&emptyText, phalcon_helper_arr_ce, "get", &_0, 155, &parameters, &_8$$7, &_9$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_8$$7);
		ZVAL_STRING(&_8$$7, "emptyValue");
		ZEPHIR_INIT_NVAR(&_9$$7);
		ZVAL_STRING(&_9$$7, "");
		ZEPHIR_CALL_CE_STATIC(&emptyValue, phalcon_helper_arr_ce, "get", &_0, 155, &parameters, &_8$$7, &_9$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_8$$7);
		ZEPHIR_GET_CONSTANT(&_8$$7, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_10$$7);
		ZEPHIR_CONCAT_SV(&_10$$7, "\t<option value=\"%s\">%s</option>", &_8$$7);
		ZEPHIR_CALL_FUNCTION(&outputEmpty, "sprintf", NULL, 139, &_10$$7, &emptyValue, &emptyText);
		zephir_check_call_status();
		zephir_array_unset_string(&parameters, SL("useEmpty"), PH_SEPARATE);
		zephir_array_unset_string(&parameters, SL("emptyText"), PH_SEPARATE);
		zephir_array_unset_string(&parameters, SL("emptyValue"), PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&value);
	if (!(zephir_array_isset_string_fetch(&value, &parameters, SL("value"), 0))) {
		ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0, &id, &parameters);
		zephir_check_call_status();
	} else {
		zephir_array_unset_string(&parameters, SL("value"), PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "<select");
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "renderattributes", NULL, 201, &_1, &parameters);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_GET_CONSTANT(&_1, "PHP_EOL");
	ZEPHIR_INIT_VAR(&output);
	ZEPHIR_CONCAT_VSVV(&output, &_11, ">", &_1, &outputEmpty);
	if (Z_TYPE_P(data) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_13$$10);
		ZEPHIR_GET_CONSTANT(&_13$$10, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_14$$10);
		ZEPHIR_CONCAT_SV(&_14$$10, "</option>", &_13$$10);
		ZEPHIR_CALL_METHOD(&_12$$10, this_ptr, "renderselectresultset", NULL, 209, data, &using, &value, &_14$$10);
		zephir_check_call_status();
		zephir_concat_self(&output, &_12$$10 TSRMLS_CC);
	} else if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_16$$11);
		ZEPHIR_GET_CONSTANT(&_16$$11, "PHP_EOL");
		ZEPHIR_INIT_VAR(&_17$$11);
		ZEPHIR_CONCAT_SV(&_17$$11, "</option>", &_16$$11);
		ZEPHIR_CALL_METHOD(&_15$$11, this_ptr, "renderselectarray", NULL, 210, data, &value, &_17$$11);
		zephir_check_call_status();
		zephir_concat_self(&output, &_15$$11 TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_html_exception_ce, "Invalid data provided to SELECT helper", "phalcon/html/tag.zep", 1248);
		return;
	}
	zephir_concat_self_str(&output, SL("</select>") TSRMLS_CC);
	RETURN_CCTOR(&output);

}

/**
 * Assigns default values to generated tags by helpers
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * // Assigning 'peter' to 'name' component
 * $tag->setAttribute('name', 'peter');
 *
 * // Later in the view
 * echo $tag->inputText('name'); // Will have the value 'peter' by default
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, setAttribute) {

	zend_bool _0$$3;
	zval *name_param = NULL, *value, value_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	if (Z_TYPE_P(value) != IS_NULL) {
		_0$$3 = Z_TYPE_P(value) == IS_ARRAY;
		if (!(_0$$3)) {
			_0$$3 = Z_TYPE_P(value) == IS_OBJECT;
		}
		if (_0$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_html_exception_ce, "Only scalar values can be assigned to UI components", "phalcon/html/tag.zep", 1275);
			return;
		}
	}
	zephir_update_property_array(this_ptr, SL("values"), &name, value);
	RETURN_THIS();

}

/**
 * Assigns default values to generated tags by helpers
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * // Assigning 'peter' to 'name' component
 * $tag->setAttribute(
 *     [
 *         'name' => 'peter',
 *     ]
 * );
 *
 * // Later in the view
 * echo $tag->inputText('name'); // Will have the value 'peter' by default
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, setAttributes) {

	zend_bool merge;
	zval *values_param = NULL, *merge_param = NULL, _0$$3, _1$$3;
	zval values;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &values_param, &merge_param);

	ZEPHIR_OBS_COPY_OR_DUP(&values, values_param);
	if (!merge_param) {
		merge = 0;
	} else {
		merge = zephir_get_boolval(merge_param);
	}


	if (merge) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, &values TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("values"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, SL("values"), &values);
	}
	RETURN_THIS();

}

/**
 * Sets the dependency injector
 */
PHP_METHOD(Phalcon_Html_Tag, setDI) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params(0, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

/**
 * Set the document type of content
 *
 * @param int doctype A valid doctype for the content
 *
 * @return <Tag>
 */
PHP_METHOD(Phalcon_Html_Tag, setDocType) {

	zend_bool _0;
	zval *doctype_param = NULL, _1$$3, _2$$4;
	zend_long doctype;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);

	zephir_fetch_params(0, 1, 0, &doctype_param);

	doctype = zephir_get_intval(doctype_param);


	_0 = doctype < 1;
	if (!(_0)) {
		_0 = doctype > 11;
	}
	if (_0) {
		ZEPHIR_INIT_ZVAL_NREF(_1$$3);
		ZVAL_LONG(&_1$$3, 5);
		zephir_update_property_zval(this_ptr, SL("docType"), &_1$$3);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_2$$4);
		ZVAL_LONG(&_2$$4, doctype);
		zephir_update_property_zval(this_ptr, SL("docType"), &_2$$4);
	}
	RETURN_THISW();

}

/**
 * Set the title separator of view content
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * $tag->setTitle('Phalcon Framework');
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, setTitle) {

	zval *title_param = NULL;
	zval title;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&title);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &title_param);

	zephir_get_strval(&title, title_param);


	zephir_update_property_zval(this_ptr, SL("title"), &title);
	RETURN_THIS();

}

/**
 * Set the title separator of view content
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->setTitleSeparator('-');
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, setTitleSeparator) {

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
 * Builds a LINK[rel="stylesheet"] tag
 *
 * Parameters
 * `local` Local resource or not (default `true`)
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 * echo $tag->stylesheet(
 *     'http://fonts.googleapis.com/css?family=Rosario',
 * 	   ['local' => false]
 * );
 * echo $tag->stylesheet('css/style.css');
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ stylesheet('http://fonts.googleapis.com/css?family=Rosario', ['local': false]) }}
 * {{ stylesheet('css/style.css') }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, stylesheet) {

	zend_bool local = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval parameters;
	zval *url_param = NULL, *parameters_param = NULL, service, output, _0, _2, _3, _7, _8, _9, _4$$3, _5$$3, _6$$5;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &url_param, &parameters_param);

	zephir_get_strval(&url, url_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "local");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_helper_arr_ce, "get", &_1, 155, &parameters, &_2, &_3);
	zephir_check_call_status();
	local = zephir_get_boolval(&_0);
	zephir_array_unset_string(&parameters, SL("local"), PH_SEPARATE);
	if (local == 1) {
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "url");
		ZEPHIR_CALL_METHOD(&service, this_ptr, "getservice", NULL, 202, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, &service, "getstatic", NULL, 0, &url);
		zephir_check_call_status();
		zephir_array_update_string(&parameters, SL("href"), &_5$$3, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_update_string(&parameters, SL("href"), &url, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(&parameters, SL("rel")))) {
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_STRING(&_6$$5, "stylesheet");
		zephir_array_update_string(&parameters, SL("rel"), &_6$$5, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "type");
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "text/css");
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_helper_arr_ce, "get", &_1, 155, &parameters, &_2, &_7);
	zephir_check_call_status();
	zephir_array_update_string(&parameters, SL("type"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "<link");
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "renderattributes", NULL, 201, &_2, &parameters);
	zephir_check_call_status();
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "renderclosetag", NULL, 207, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&output);
	ZEPHIR_CONCAT_VV(&output, &_8, &_9);
	RETURN_CCTOR(&output);

}

/**
 * Builds a HTML input[type="submit"] tag
 *
 * <code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *public
 * echo $tag->submit('Save')
 * </code>
 *
 * Volt syntax:
 * <code>
 * {{ submit('Save') }}
 * </code>
 */
PHP_METHOD(Phalcon_Html_Tag, submit) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "submit");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderinput", NULL, 200, &_0, &name, &parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Builds a HTML TEXTAREA tag
 *
 *<code>
 * use Phalcon\Html\Tag;
 *
 * $tag = new Tag();
 *
 * echo $tag->textArea(
 *     'comments',
 *     [
 *         'cols' => 10,
 *         'rows' => 4,
 *     ]
 * );
 *</code>
 *
 * Volt syntax:
 *<code>
 * {{ text_area('comments', ['cols': 10, 'rows': 4]) }}
 *</code>
 */
PHP_METHOD(Phalcon_Html_Tag, textArea) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval parameters;
	zval *name_param = NULL, *parameters_param = NULL, content, output, _0, _2, _3, _5, _6, _4$$4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &parameters_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "id");
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_helper_arr_ce, "get", &_1, 155, &parameters, &_2, &name);
	zephir_check_call_status();
	zephir_array_update_string(&parameters, SL("id"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "name");
	ZEPHIR_CALL_CE_STATIC(&_3, phalcon_helper_arr_ce, "get", &_1, 155, &parameters, &_2, &name);
	zephir_check_call_status();
	zephir_array_update_string(&parameters, SL("name"), &_3, PH_COPY | PH_SEPARATE);
	if (zephir_array_isset_string(&parameters, SL("value"))) {
		ZEPHIR_OBS_VAR(&content);
		zephir_array_fetch_string(&content, &parameters, SL("value"), PH_NOISY, "phalcon/html/tag.zep", 1478 TSRMLS_CC);
		zephir_array_unset_string(&parameters, SL("value"), PH_SEPARATE);
	} else {
		zephir_array_fetch_string(&_4$$4, &parameters, SL("id"), PH_NOISY | PH_READONLY, "phalcon/html/tag.zep", 1481 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&content, this_ptr, "getvalue", NULL, 0, &_4$$4, &parameters);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "<textarea");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "renderattributes", NULL, 201, &_2, &parameters);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_6, "htmlspecialchars", NULL, 177, &content);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&output);
	ZEPHIR_CONCAT_VSVS(&output, &_5, ">", &_6, "</textarea>");
	RETURN_CCTOR(&output);

}

/**
 * Returns the escaper service from the DI container
 */
PHP_METHOD(Phalcon_Html_Tag, getService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, service, container, _0, _1$$6, _3$$5, _4$$7, _5$$8;
	zval name, _2$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "escaper");
	if (ZEPHIR_IS_IDENTICAL(&_0, &name)) {
		ZEPHIR_OBS_VAR(&service);
		zephir_read_property(&service, this_ptr, SL("escaper"), PH_NOISY_CC);
	} else {
		ZEPHIR_OBS_NVAR(&service);
		zephir_read_property(&service, this_ptr, SL("url"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(&service) != IS_OBJECT) {
		ZEPHIR_CALL_METHOD(&container, this_ptr, "getdi", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&container) != IS_OBJECT) {
			ZEPHIR_INIT_VAR(&_1$$6);
			object_init_ex(&_1$$6, phalcon_html_exception_ce);
			ZEPHIR_INIT_VAR(&_2$$6);
			ZEPHIR_CONCAT_SVS(&_2$$6, "A dependency injector container is required to obtain the '", &name, "' service");
			ZEPHIR_CALL_METHOD(NULL, &_1$$6, "__construct", NULL, 4, &_2$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$6, "phalcon/html/tag.zep", 1508 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_SINIT_VAR(_3$$5);
		ZVAL_STRING(&_3$$5, "escaper");
		ZEPHIR_INIT_NVAR(&service);
		if (ZEPHIR_IS_IDENTICAL(&_3$$5, &name)) {
			ZEPHIR_CALL_METHOD(&_4$$7, &container, "getshared", NULL, 0, &name);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&service, &_4$$7);
			zephir_update_property_zval(this_ptr, SL("escaper"), &service);
		} else {
			ZEPHIR_CALL_METHOD(&_5$$8, &container, "getshared", NULL, 0, &name);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&service, &_5$$8);
			zephir_update_property_zval(this_ptr, SL("url"), &service);
		}
	}
	RETURN_CCTOR(&service);

}

/**
 * Renders the attributes of an HTML element
 */
PHP_METHOD(Phalcon_Html_Tag, renderAttributes) {

	zend_bool _5$$3, _6$$4, _13$$8, _14$$9;
	zend_string *_4;
	zend_ulong _3;
	zephir_fcall_cache_entry *_10 = NULL, *_11 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *code_param = NULL, *attributes_param = NULL, __$null, attrs, escaper, escaped, key, newCode, intersect, order, value, _0, *_1, _2, _12$$4, _7$$5, _8$$5, _9$$5, _19$$9, _15$$10, _16$$10, _17$$10;
	zval code;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&attrs);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&escaped);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&newCode);
	ZVAL_UNDEF(&intersect);
	ZVAL_UNDEF(&order);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&attributes);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &code_param, &attributes_param);

	if (UNEXPECTED(Z_TYPE_P(code_param) != IS_STRING && Z_TYPE_P(code_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'code' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(code_param) == IS_STRING)) {
		zephir_get_strval(&code, code_param);
	} else {
		ZEPHIR_INIT_VAR(&code);
		ZVAL_EMPTY_STRING(&code);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&order);
	zephir_create_array(&order, 10, 0 TSRMLS_CC);
	zephir_array_update_string(&order, SL("rel"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("type"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("for"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("src"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("href"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("action"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("id"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("name"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("value"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&order, SL("class"), &__$null, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect_key", NULL, 3, &order, &attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&attrs);
	zephir_fast_array_merge(&attrs, &intersect, &attributes TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "escaper");
	ZEPHIR_CALL_METHOD(&escaper, this_ptr, "getservice", NULL, 202, &_0);
	zephir_check_call_status();
	zephir_array_unset_string(&attrs, SL("escape"), PH_SEPARATE);
	ZEPHIR_CPY_WRT(&newCode, &code);
	zephir_is_iterable(&attrs, 0, "phalcon/html/tag.zep", 1566);
	if (Z_TYPE_P(&attrs) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attrs), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			_5$$3 = Z_TYPE_P(&key) == IS_STRING;
			if (_5$$3) {
				_5$$3 = Z_TYPE_P(&value) != IS_NULL;
			}
			if (_5$$3) {
				_6$$4 = Z_TYPE_P(&value) == IS_ARRAY;
				if (!(_6$$4)) {
					_6$$4 = Z_TYPE_P(&value) == IS_RESOURCE;
				}
				if (_6$$4) {
					ZEPHIR_INIT_NVAR(&_7$$5);
					object_init_ex(&_7$$5, phalcon_html_exception_ce);
					ZEPHIR_INIT_NVAR(&_8$$5);
					zephir_gettype(&_8$$5, &value TSRMLS_CC);
					ZEPHIR_INIT_LNVAR(_9$$5);
					ZEPHIR_CONCAT_SVSVS(&_9$$5, "Value at index: '", &key, "' type: '", &_8$$5, "' cannot be rendered");
					ZEPHIR_CALL_METHOD(NULL, &_7$$5, "__construct", &_10, 4, &_9$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_7$$5, "phalcon/html/tag.zep", 1555 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&escaper)) {
					ZEPHIR_CALL_METHOD(&escaped, &escaper, "escapehtmlattr", &_11, 0, &value);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&escaped, &value);
				}
				ZEPHIR_INIT_LNVAR(_12$$4);
				ZEPHIR_CONCAT_SVSVS(&_12$$4, " ", &key, "=\"", &escaped, "\"");
				zephir_concat_self(&newCode, &_12$$4 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attrs, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &attrs, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &attrs, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &attrs, "current", NULL, 0);
			zephir_check_call_status();
				_13$$8 = Z_TYPE_P(&key) == IS_STRING;
				if (_13$$8) {
					_13$$8 = Z_TYPE_P(&value) != IS_NULL;
				}
				if (_13$$8) {
					_14$$9 = Z_TYPE_P(&value) == IS_ARRAY;
					if (!(_14$$9)) {
						_14$$9 = Z_TYPE_P(&value) == IS_RESOURCE;
					}
					if (_14$$9) {
						ZEPHIR_INIT_NVAR(&_15$$10);
						object_init_ex(&_15$$10, phalcon_html_exception_ce);
						ZEPHIR_INIT_NVAR(&_16$$10);
						zephir_gettype(&_16$$10, &value TSRMLS_CC);
						ZEPHIR_INIT_LNVAR(_17$$10);
						ZEPHIR_CONCAT_SVSVS(&_17$$10, "Value at index: '", &key, "' type: '", &_16$$10, "' cannot be rendered");
						ZEPHIR_CALL_METHOD(NULL, &_15$$10, "__construct", &_10, 4, &_17$$10);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_15$$10, "phalcon/html/tag.zep", 1555 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_is_true(&escaper)) {
						ZEPHIR_CALL_METHOD(&escaped, &escaper, "escapehtmlattr", &_18, 0, &value);
						zephir_check_call_status();
					} else {
						ZEPHIR_CPY_WRT(&escaped, &value);
					}
					ZEPHIR_INIT_LNVAR(_19$$9);
					ZEPHIR_CONCAT_SVSVS(&_19$$9, " ", &key, "=\"", &escaped, "\"");
					zephir_concat_self(&newCode, &_19$$9 TSRMLS_CC);
				}
			ZEPHIR_CALL_METHOD(NULL, &attrs, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&newCode);

}

/**
 * Returns the closing tag depending on the doctype
 */
PHP_METHOD(Phalcon_Html_Tag, renderCloseTag) {

	zval *addEol_param = NULL, eol, _0;
	zend_bool addEol;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eol);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &addEol_param);

	if (!addEol_param) {
		addEol = 0;
	} else {
		addEol = zephir_get_boolval(addEol_param);
	}


	ZEPHIR_INIT_VAR(&eol);
	ZVAL_STRING(&eol, "");
	if (addEol) {
		ZEPHIR_INIT_NVAR(&eol);
		ZEPHIR_GET_CONSTANT(&eol, "PHP_EOL");
	}
	zephir_read_property(&_0, this_ptr, SL("docType"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_0, 5)) {
		ZEPHIR_CONCAT_SV(return_value, " />", &eol);
		RETURN_MM();
	} else {
		ZEPHIR_CONCAT_SV(return_value, ">", &eol);
		RETURN_MM();
	}

}

/**
 * Builds `input` elements
 */
PHP_METHOD(Phalcon_Html_Tag, renderInput) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval parameters;
	zval *type_param = NULL, name, *name_param = NULL, *parameters_param = NULL, id, output, _1, _2, _3, _4;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &type_param, &name_param, &parameters_param);

	zephir_get_strval(&type, type_param);
	zephir_get_strval(&name, name_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "id");
	ZEPHIR_CALL_CE_STATIC(&id, phalcon_helper_arr_ce, "get", &_0, 155, &parameters, &_1, &name);
	zephir_check_call_status();
	zephir_array_update_string(&parameters, SL("id"), &id, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&parameters, SL("name"), &name, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&parameters, SL("type"), &type, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getvalue", NULL, 0, &id, &parameters);
	zephir_check_call_status();
	zephir_array_update_string(&parameters, SL("value"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "<input");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "renderattributes", NULL, 201, &_1, &parameters);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "renderclosetag", NULL, 207);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&output);
	ZEPHIR_CONCAT_VV(&output, &_3, &_4);
	RETURN_CCTOR(&output);

}

/**
 * Builds INPUT tags that implements the checked attribute
 */
PHP_METHOD(Phalcon_Html_Tag, renderInputChecked) {

	zend_bool _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval parameters;
	zval *type_param = NULL, name, *name_param = NULL, *parameters_param = NULL, currentValue, id, output, value, _1, _5, _6, _3$$4, _4$$6;
	zval type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&currentValue);
	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&parameters);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &type_param, &name_param, &parameters_param);

	zephir_get_strval(&type, type_param);
	zephir_get_strval(&name, name_param);
	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "id");
	ZEPHIR_CALL_CE_STATIC(&id, phalcon_helper_arr_ce, "get", &_0, 155, &parameters, &_1, &name);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&currentValue);
	if (zephir_array_isset_string_fetch(&currentValue, &parameters, SL("value"), 0)) {
		zephir_array_unset_string(&parameters, SL("value"), PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0, &id, &parameters);
		zephir_check_call_status();
		_2$$3 = Z_TYPE_P(&value) != IS_NULL;
		if (_2$$3) {
			_2$$3 = ZEPHIR_IS_IDENTICAL(&currentValue, &value);
		}
		if (_2$$3) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "checked");
			zephir_array_update_string(&parameters, SL("checked"), &_3$$4, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&parameters, SL("value"), &currentValue, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_CALL_METHOD(&value, this_ptr, "getvalue", NULL, 0, &id, &parameters);
		zephir_check_call_status();
		if (Z_TYPE_P(&value) != IS_NULL) {
			ZEPHIR_INIT_VAR(&_4$$6);
			ZVAL_STRING(&_4$$6, "checked");
			zephir_array_update_string(&parameters, SL("checked"), &_4$$6, PH_COPY | PH_SEPARATE);
		}
		zephir_array_update_string(&parameters, SL("value"), &value, PH_COPY | PH_SEPARATE);
	}
	zephir_array_update_string(&parameters, SL("id"), &id, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&parameters, SL("name"), &name, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&parameters, SL("type"), &type, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "<input");
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "renderattributes", NULL, 201, &_1, &parameters);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "renderclosetag", NULL, 207);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&output);
	ZEPHIR_CONCAT_VV(&output, &_5, &_6);
	RETURN_CCTOR(&output);

}

/**
 * Generates the option values or optgroup from an array
 */
PHP_METHOD(Phalcon_Html_Tag, renderSelectArray) {

	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval closeOption, _12$$8, _13$$8, _22$$16, _23$$16;
	zval *options_param = NULL, *value, value_sub, *closeOption_param = NULL, label, strOptionValue, strValue, optionText, optionValue, output, *_0, _1, _5$$4, _6$$4, _8$$4, _9$$4, _10$$6, _11$$7, _14$$9, _15$$10, _16$$12, _17$$12, _18$$12, _19$$12, _20$$14, _21$$15, _24$$17, _25$$18;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&strOptionValue);
	ZVAL_UNDEF(&strValue);
	ZVAL_UNDEF(&optionText);
	ZVAL_UNDEF(&optionValue);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&closeOption);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$16);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &options_param, &value, &closeOption_param);

	zephir_get_arrval(&options, options_param);
	zephir_get_strval(&closeOption, closeOption_param);


	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	zephir_is_iterable(&options, 0, "phalcon/html/tag.zep", 1695);
	if (Z_TYPE_P(&options) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&optionValue);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&optionValue, _3);
			} else {
				ZVAL_LONG(&optionValue, _2);
			}
			ZEPHIR_INIT_NVAR(&optionText);
			ZVAL_COPY(&optionText, _0);
			ZEPHIR_CALL_FUNCTION(&label, "htmlspecialchars", &_4, 177, &optionValue);
			zephir_check_call_status();
			if (Z_TYPE_P(&optionText) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZEPHIR_GET_CONSTANT(&_5$$4, "PHP_EOL");
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "renderselectarray", &_7, 210, &optionText, value, &closeOption);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZEPHIR_GET_CONSTANT(&_8$$4, "PHP_EOL");
				ZEPHIR_INIT_LNVAR(_9$$4);
				ZEPHIR_CONCAT_SVSVVSV(&_9$$4, "\t<optgroup label=\"", &label, "\">", &_5$$4, &_6$$4, "\t</optgroup>", &_8$$4);
				zephir_concat_self(&output, &_9$$4 TSRMLS_CC);
				continue;
			}
			if (Z_TYPE_P(value) == IS_ARRAY) {
				if (zephir_fast_in_array(&optionValue, value TSRMLS_CC)) {
					ZEPHIR_INIT_LNVAR(_10$$6);
					ZEPHIR_CONCAT_SVSVV(&_10$$6, "\t<option selected=\"selected\" value=\"", &label, "\">", &optionText, &closeOption);
					zephir_concat_self(&output, &_10$$6 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_11$$7);
					ZEPHIR_CONCAT_SVSVV(&_11$$7, "\t<option value=\"", &label, "\">", &optionText, &closeOption);
					zephir_concat_self(&output, &_11$$7 TSRMLS_CC);
				}
			} else {
				zephir_get_strval(&_12$$8, &optionValue);
				ZEPHIR_CPY_WRT(&strOptionValue, &_12$$8);
				zephir_get_strval(&_13$$8, value);
				ZEPHIR_CPY_WRT(&strValue, &_13$$8);
				if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
					ZEPHIR_INIT_LNVAR(_14$$9);
					ZEPHIR_CONCAT_SVSVV(&_14$$9, "\t<option selected=\"selected\" value=\"", &label, "\">", &optionText, &closeOption);
					zephir_concat_self(&output, &_14$$9 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_15$$10);
					ZEPHIR_CONCAT_SVSVV(&_15$$10, "\t<option value=\"", &label, "\">", &optionText, &closeOption);
					zephir_concat_self(&output, &_15$$10 TSRMLS_CC);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &options, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &options, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&optionValue, &options, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&optionText, &options, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&label, "htmlspecialchars", &_4, 177, &optionValue);
				zephir_check_call_status();
				if (Z_TYPE_P(&optionText) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(&_16$$12);
					ZEPHIR_GET_CONSTANT(&_16$$12, "PHP_EOL");
					ZEPHIR_CALL_METHOD(&_17$$12, this_ptr, "renderselectarray", &_7, 210, &optionText, value, &closeOption);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_18$$12);
					ZEPHIR_GET_CONSTANT(&_18$$12, "PHP_EOL");
					ZEPHIR_INIT_LNVAR(_19$$12);
					ZEPHIR_CONCAT_SVSVVSV(&_19$$12, "\t<optgroup label=\"", &label, "\">", &_16$$12, &_17$$12, "\t</optgroup>", &_18$$12);
					zephir_concat_self(&output, &_19$$12 TSRMLS_CC);
					continue;
				}
				if (Z_TYPE_P(value) == IS_ARRAY) {
					if (zephir_fast_in_array(&optionValue, value TSRMLS_CC)) {
						ZEPHIR_INIT_LNVAR(_20$$14);
						ZEPHIR_CONCAT_SVSVV(&_20$$14, "\t<option selected=\"selected\" value=\"", &label, "\">", &optionText, &closeOption);
						zephir_concat_self(&output, &_20$$14 TSRMLS_CC);
					} else {
						ZEPHIR_INIT_LNVAR(_21$$15);
						ZEPHIR_CONCAT_SVSVV(&_21$$15, "\t<option value=\"", &label, "\">", &optionText, &closeOption);
						zephir_concat_self(&output, &_21$$15 TSRMLS_CC);
					}
				} else {
					zephir_get_strval(&_22$$16, &optionValue);
					ZEPHIR_CPY_WRT(&strOptionValue, &_22$$16);
					zephir_get_strval(&_23$$16, value);
					ZEPHIR_CPY_WRT(&strValue, &_23$$16);
					if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
						ZEPHIR_INIT_LNVAR(_24$$17);
						ZEPHIR_CONCAT_SVSVV(&_24$$17, "\t<option selected=\"selected\" value=\"", &label, "\">", &optionText, &closeOption);
						zephir_concat_self(&output, &_24$$17 TSRMLS_CC);
					} else {
						ZEPHIR_INIT_LNVAR(_25$$18);
						ZEPHIR_CONCAT_SVSVV(&_25$$18, "\t<option value=\"", &label, "\">", &optionText, &closeOption);
						zephir_concat_self(&output, &_25$$18 TSRMLS_CC);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &options, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&optionText);
	ZEPHIR_INIT_NVAR(&optionValue);
	RETURN_CCTOR(&output);

}

/**
 * Generates the option values from a resultset
 */
PHP_METHOD(Phalcon_Html_Tag, renderSelectResultset) {

	zend_object_iterator *_1;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval closeOption, _10$$15, _11$$15;
	zval *resultset, resultset_sub, *using, using_sub, *value, value_sub, *closeOption_param = NULL, escaper, option, output, optionValue, optionText, parameters, strOptionValue, strValue, _0, _2$$7, _3$$8, _4$$10, _5$$5, _8$$13, _9$$14, _12$$16, _13$$17, _14$$19;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resultset_sub);
	ZVAL_UNDEF(&using_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&escaper);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&output);
	ZVAL_UNDEF(&optionValue);
	ZVAL_UNDEF(&optionText);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&strOptionValue);
	ZVAL_UNDEF(&strValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$13);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&_12$$16);
	ZVAL_UNDEF(&_13$$17);
	ZVAL_UNDEF(&_14$$19);
	ZVAL_UNDEF(&closeOption);
	ZVAL_UNDEF(&_10$$15);
	ZVAL_UNDEF(&_11$$15);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &resultset, &using, &value, &closeOption_param);

	zephir_get_strval(&closeOption, closeOption_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "escaper");
	ZEPHIR_CALL_METHOD(&escaper, this_ptr, "getservice", NULL, 202, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&parameters);
	array_init(&parameters);
	ZEPHIR_INIT_VAR(&output);
	ZVAL_STRING(&output, "");
	if (Z_TYPE_P(using) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&optionValue);
		zephir_array_fetch_long(&optionValue, using, 0, PH_NOISY, "phalcon/html/tag.zep", 1714 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&optionText);
		zephir_array_fetch_long(&optionText, using, 1, PH_NOISY, "phalcon/html/tag.zep", 1715 TSRMLS_CC);
	}
	_1 = zephir_get_iterator(resultset TSRMLS_CC);
	_1->funcs->rewind(_1 TSRMLS_CC);
	for (;_1->funcs->valid(_1 TSRMLS_CC) == SUCCESS && !EG(exception); _1->funcs->move_forward(_1 TSRMLS_CC)) {
		{
			ZEPHIR_ITERATOR_COPY(&option, _1);
		}
		if (Z_TYPE_P(using) == IS_ARRAY) {
			if (Z_TYPE_P(&option) == IS_OBJECT) {
				if ((zephir_method_exists_ex(&option, SL("readattribute") TSRMLS_CC) == SUCCESS)) {
					ZEPHIR_CALL_METHOD(&_2$$7, &option, "readattribute", NULL, 0, &optionValue);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&optionValue, &_2$$7);
					ZEPHIR_CALL_METHOD(&_2$$7, &option, "readattribute", NULL, 0, &optionText);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&optionText, &_2$$7);
				} else {
					zephir_read_property(&_3$$8, &option, SL("optionValue"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CPY_WRT(&optionValue, &_3$$8);
					zephir_read_property(&_3$$8, &option, SL("optionText"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CPY_WRT(&optionText, &_3$$8);
				}
			} else {
				if (Z_TYPE_P(&option) == IS_ARRAY) {
					zephir_array_fetch(&_4$$10, &option, &optionValue, PH_NOISY | PH_READONLY, "phalcon/html/tag.zep", 1731 TSRMLS_CC);
					ZEPHIR_CPY_WRT(&optionValue, &_4$$10);
					zephir_array_fetch(&_4$$10, &option, &optionText, PH_NOISY | PH_READONLY, "phalcon/html/tag.zep", 1732 TSRMLS_CC);
					ZEPHIR_CPY_WRT(&optionText, &_4$$10);
				} else {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_html_exception_ce, "Resultset returned an invalid value", "phalcon/html/tag.zep", 1734);
					return;
				}
			}
			ZEPHIR_CALL_METHOD(&_5$$5, &escaper, "escapehtmlattr", &_6, 0, &optionValue);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&optionValue, &_5$$5);
			ZEPHIR_CALL_METHOD(&_5$$5, &escaper, "escapehtml", &_7, 0, &optionText);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&optionText, &_5$$5);
			if (Z_TYPE_P(value) == IS_ARRAY) {
				if (zephir_fast_in_array(&optionValue, value TSRMLS_CC)) {
					ZEPHIR_INIT_LNVAR(_8$$13);
					ZEPHIR_CONCAT_SVSVV(&_8$$13, "\t<option selected=\"selected\" value=\"", &optionValue, "\">", &optionText, &closeOption);
					zephir_concat_self(&output, &_8$$13 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_9$$14);
					ZEPHIR_CONCAT_SVSVV(&_9$$14, "\t<option value=\"", &optionValue, "\">", &optionText, &closeOption);
					zephir_concat_self(&output, &_9$$14 TSRMLS_CC);
				}
			} else {
				zephir_get_strval(&_10$$15, &optionValue);
				ZEPHIR_CPY_WRT(&strOptionValue, &_10$$15);
				zephir_get_strval(&_11$$15, value);
				ZEPHIR_CPY_WRT(&strValue, &_11$$15);
				if (ZEPHIR_IS_IDENTICAL(&strOptionValue, &strValue)) {
					ZEPHIR_INIT_LNVAR(_12$$16);
					ZEPHIR_CONCAT_SVSVV(&_12$$16, "\t<option selected=\"selected\" value=\"", &strOptionValue, "\">", &optionText, &closeOption);
					zephir_concat_self(&output, &_12$$16 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_LNVAR(_13$$17);
					ZEPHIR_CONCAT_SVSVV(&_13$$17, "\t<option value=\"", &strOptionValue, "\">", &optionText, &closeOption);
					zephir_concat_self(&output, &_13$$17 TSRMLS_CC);
				}
			}
		} else {
			if (Z_TYPE_P(using) == IS_OBJECT) {
				zephir_array_update_long(&parameters, 0, &option, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
				ZEPHIR_INIT_NVAR(&_14$$19);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_14$$19, using, &parameters);
				zephir_check_call_status();
				zephir_concat_self(&output, &_14$$19 TSRMLS_CC);
			}
		}
	}
	zend_iterator_dtor(_1);
	RETURN_CCTOR(&output);

}

zend_object *zephir_init_properties_Phalcon_Html_Tag(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _1$$3, _3$$4, _5$$5;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("values"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("values"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("prepend"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("prepend"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("append"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("append"), &_5$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

