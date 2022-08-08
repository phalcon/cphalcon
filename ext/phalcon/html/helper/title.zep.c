
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
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
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Title)
{
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
 * @param string      $indent
 * @param string|null $delimiter
 *
 * @return Title
 */
PHP_METHOD(Phalcon_Html_Helper_Title, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *indent_param = NULL, *delimiter_param = NULL, _0;
	zval indent, delimiter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&indent);
	ZVAL_UNDEF(&delimiter);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(indent)
		Z_PARAM_STR_OR_NULL(delimiter)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
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
	if (Z_TYPE_P(&delimiter) == IS_NULL) {
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
 * Returns the title tags
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_Title, __toString)
{
	zval _1;
	zval items, _0, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

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
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("prepend"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("title"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_2);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("append"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&items, "array_merge", NULL, 331, &_0, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	zephir_update_property_zval(this_ptr, ZEND_STRL("append"), &_4);
	ZEPHIR_INIT_VAR(&_5);
	array_init(&_5);
	zephir_update_property_zval(this_ptr, ZEND_STRL("prepend"), &_5);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "");
	zephir_update_property_zval(this_ptr, ZEND_STRL("title"), &_6);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("indent"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_6);
	zephir_read_property(&_9, this_ptr, ZEND_STRL("separator"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_join(&_6, &_9, &items);
	ZEPHIR_INIT_VAR(&_10);
	array_init(&_10);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "title");
	ZVAL_BOOL(&_12, 1);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "renderfullelement", NULL, 0, &_11, &_6, &_10, &_12);
	zephir_check_call_status();
	zephir_read_property(&_12, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VVV(return_value, &_7, &_8, &_12);
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
PHP_METHOD(Phalcon_Html_Helper_Title, append)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval *text_param = NULL, *raw_param = NULL, _0, _1;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(raw)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
PHP_METHOD(Phalcon_Html_Helper_Title, get)
{
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
PHP_METHOD(Phalcon_Html_Helper_Title, set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval *text_param = NULL, *raw_param = NULL, _0, _1;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(raw)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
 * Sets the separator
 *
 * @param string $separator
 * @param bool   $raw
 *
 * @return Title
 */
PHP_METHOD(Phalcon_Html_Helper_Title, setSeparator)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval *separator_param = NULL, *raw_param = NULL, _0, _1;
	zval separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(separator)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(raw)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &separator_param, &raw_param);
	zephir_get_strval(&separator, separator_param);
	if (!raw_param) {
		raw = 0;
	} else {
		raw = zephir_get_boolval(raw_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (raw) {
		ZEPHIR_CPY_WRT(&_0, &separator);
	} else {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_0, &_1, "html", NULL, 0, &separator);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("separator"), &_0);
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
PHP_METHOD(Phalcon_Html_Helper_Title, prepend)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval *text_param = NULL, *raw_param = NULL, _0, _1;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(raw)
	ZEND_PARSE_PARAMETERS_END();
#endif


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

zend_object *zephir_init_properties_Phalcon_Html_Helper_Title(zend_class_entry *class_type)
{
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

