
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Class Title
 *
 * @property array  $append
 * @property string $delimiter
 * @property string $indent
 * @property array  $prepend
 * @property string $title
 * @property string $separator
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Title) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Title, phalcon, html_helper_title, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_title_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_helper_title_ce, SL("append"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_helper_title_ce, SL("prepend"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_title_ce, SL("title"), "", ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_title_ce, SL("separator"), "", ZEND_ACC_PROTECTED);

	phalcon_html_helper_title_ce->create_object = zephir_init_properties_Phalcon_Html_Helper_Title;
	return SUCCESS;

}

/**
 * Sets the separator and returns the object back
 *
 * @param string      $separator
 * @param string|null $indent
 * @param string|null $delimiter
 *
 * @return Title
 */
PHP_METHOD(Phalcon_Html_Helper_Title, __invoke) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *separator_param = NULL, *indent_param = NULL, *delimiter_param = NULL;
	zval separator, indent, delimiter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&indent);
	ZVAL_UNDEF(&delimiter);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &separator_param, &indent_param, &delimiter_param);

	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "");
	} else {
		zephir_get_strval(&separator, separator_param);
	}
	if (!indent_param) {
		ZEPHIR_INIT_VAR(&indent);
		ZVAL_STRING(&indent, "");
	} else {
		zephir_get_strval(&indent, indent_param);
	}
	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(&delimiter);
		ZVAL_STRING(&delimiter, "");
	} else {
		zephir_get_strval(&delimiter, delimiter_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("delimiter"), &delimiter);
	zephir_update_property_zval(this_ptr, ZEND_STRL("indent"), &indent);
	zephir_update_property_zval(this_ptr, ZEND_STRL("separator"), &separator);
	RETURN_THIS();

}

/**
 * Returns the title tags
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Title, __toString) {

	zval _1;
	zval delimiter, indent, items, _0, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&delimiter);
	ZVAL_UNDEF(&indent);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("prepend"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("title"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("append"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&items, "array_merge", NULL, 297, &_0, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("indent"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_5)) {
		ZEPHIR_OBS_NVAR(&_4);
		zephir_read_property(&_4, this_ptr, ZEND_STRL("indent"), PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_STRING(&_4, "");
	}
	ZEPHIR_CPY_WRT(&indent, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_6)) {
		ZEPHIR_OBS_NVAR(&_4);
		zephir_read_property(&_4, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_STRING(&_4, "");
	}
	ZEPHIR_CPY_WRT(&delimiter, &_4);
	ZEPHIR_INIT_VAR(&_7);
	array_init(&_7);
	zephir_update_property_zval(this_ptr, ZEND_STRL("append"), &_7);
	ZEPHIR_INIT_VAR(&_8);
	array_init(&_8);
	zephir_update_property_zval(this_ptr, ZEND_STRL("prepend"), &_8);
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_INIT_NVAR(&_9);
	ZVAL_STRING(&_9, "");
	zephir_update_property_zval(this_ptr, ZEND_STRL("title"), &_9);
	ZEPHIR_INIT_NVAR(&_9);
	zephir_read_property(&_11, this_ptr, ZEND_STRL("separator"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_join(&_9, &_11, &items);
	ZEPHIR_INIT_VAR(&_12);
	array_init(&_12);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "title");
	ZVAL_BOOL(&_14, 1);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "renderfullelement", NULL, 0, &_13, &_9, &_12, &_14);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVV(return_value, &indent, &_10, &delimiter);
	RETURN_MM();

}

/**
 * Appends text to current document title
 *
 * @param string $text
 * @param bool   $raw
 *
 * @return Title
 */
PHP_METHOD(Phalcon_Html_Helper_Title, append) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval *text_param = NULL, *raw_param = NULL, _0, _1;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &raw_param);

	zephir_get_strval(&text, text_param);
	if (!raw_param) {
		raw = 0;
	} else {
		raw = zephir_get_boolval(raw_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (raw) {
		ZEPHIR_CPY_WRT(&_0, &text);
	} else {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_0, &_1, "html", NULL, 0, &text);
		zephir_check_call_status();
	}
	zephir_get_strval(&text, &_0);
	zephir_update_property_array_append(this_ptr, SL("append"), &text);
	RETURN_THIS();

}

/**
 * Returns the title
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Title, get) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "title");

}

/**
 * Sets the title
 *
 * @param string $text
 * @param bool   $raw
 *
 * @return Title
 */
PHP_METHOD(Phalcon_Html_Helper_Title, set) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval *text_param = NULL, *raw_param = NULL, _0, _1;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &raw_param);

	zephir_get_strval(&text, text_param);
	if (!raw_param) {
		raw = 0;
	} else {
		raw = zephir_get_boolval(raw_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (raw) {
		ZEPHIR_CPY_WRT(&_0, &text);
	} else {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_0, &_1, "html", NULL, 0, &text);
		zephir_check_call_status();
	}
	zephir_get_strval(&text, &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("title"), &text);
	RETURN_THIS();

}

/**
 * Prepends text to current document title
 *
 * @param string $text
 * @param bool   $raw
 *
 * @return Title
 */
PHP_METHOD(Phalcon_Html_Helper_Title, prepend) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval *text_param = NULL, *raw_param = NULL, _0, _1;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &raw_param);

	zephir_get_strval(&text, text_param);
	if (!raw_param) {
		raw = 0;
	} else {
		raw = zephir_get_boolval(raw_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (raw) {
		ZEPHIR_CPY_WRT(&_0, &text);
	} else {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_0, &_1, "html", NULL, 0, &text);
		zephir_check_call_status();
	}
	zephir_get_strval(&text, &_0);
	zephir_update_property_array_append(this_ptr, SL("prepend"), &text);
	RETURN_THIS();

}

zend_object *zephir_init_properties_Phalcon_Html_Helper_Title(zend_class_entry *class_type) {

		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("prepend"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("prepend"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("append"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("append"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

