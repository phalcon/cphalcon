
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"
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
 * Class AbstractHelper
 *
 * @property string  $delimiter
 * @property Escaper $escaper
 * @property string  $indent
 * @property int     $indentLevel
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_AbstractHelper)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Helper, AbstractHelper, phalcon, html_helper_abstracthelper, phalcon_html_helper_abstracthelper_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_abstracthelper_ce, SL("delimiter"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var EscaperInterface
	 */
	zend_declare_property_null(phalcon_html_helper_abstracthelper_ce, SL("escaper"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_abstracthelper_ce, SL("indent"), "    ", ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_html_helper_abstracthelper_ce, SL("indentLevel"), 1, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * AbstractHelper constructor.
 *
 * @param EscaperInterface $escaper
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *escaper, escaper_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_escaperinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &escaper);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_EOL");
	zephir_update_property_zval(this_ptr, ZEND_STRL("delimiter"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("escaper"), escaper);
	ZEPHIR_MM_RESTORE();
}

/**
 * Produces a closing tag
 *
 * @param string $tag
 * @param bool   $raw
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, close)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval *tag_param = NULL, *raw_param = NULL, _0, _1;
	zval tag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(tag)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(raw)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tag_param, &raw_param);
	zephir_get_strval(&tag, tag_param);
	if (!raw_param) {
		raw = 0;
	} else {
		raw = zephir_get_boolval(raw_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (raw) {
		ZEPHIR_CPY_WRT(&_0, &tag);
	} else {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_0, &_1, "html", NULL, 0, &tag);
		zephir_check_call_status();
	}
	zephir_get_strval(&tag, &_0);
	ZEPHIR_CONCAT_SVS(return_value, "</", &tag, ">");
	RETURN_MM();
}

/**
 * Replicates the indent x times as per indentLevel
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, indent)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("indent"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("indentLevel"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("str_repeat", NULL, 1, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Keeps all the attributes sorted - same order all the tome
 *
 * @param array $overrides
 * @param array $attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, orderAttributes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *overrides_param = NULL, *attributes_param = NULL, __$null, intersect, results, _0;
	zval overrides, attributes, order;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&overrides);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&order);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&intersect);
	ZVAL_UNDEF(&results);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(overrides)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &overrides_param, &attributes_param);
	zephir_get_arrval(&overrides, overrides_param);
	zephir_get_arrval(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&order);
	zephir_create_array(&order, 10, 0);
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
	ZEPHIR_CALL_FUNCTION(&intersect, "array_intersect_key", NULL, 2, &order, &attributes);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&results);
	zephir_fast_array_merge(&results, &intersect, &attributes);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &overrides, &results);
	ZEPHIR_CPY_WRT(&results, &_0);
	zephir_array_unset_string(&results, SL("escape"), PH_SEPARATE);
	RETURN_CCTOR(&results);
}

/**
 * Traverses an array and calls the method defined in the first element
 * with attributes as the second, returning the resulting string
 *
 * @param array  $elements
 * @param string $delimiter
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, renderArrayElements)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval delimiter;
	zval *elements_param = NULL, *delimiter_param = NULL, item, result, *_0, _1, _2$$3, _3$$3, _5$$3, _6$$3, _7$$3, _8$$4, _9$$4, _11$$4, _12$$4, _13$$4;
	zval elements, _4$$3, _10$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&delimiter);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(elements)
		Z_PARAM_STR(delimiter)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &elements_param, &delimiter_param);
	zephir_get_arrval(&elements, elements_param);
	zephir_get_strval(&delimiter, delimiter_param);


	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "");
	zephir_is_iterable(&elements, 0, "phalcon/Html/Helper/AbstractHelper.zep", 142);
	if (Z_TYPE_P(&elements) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&elements), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			zephir_array_fetch_long(&_2$$3, &item, 2, PH_NOISY | PH_READONLY, "phalcon/Html/Helper/AbstractHelper.zep", 138);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_create_array(&_4$$3, 2, 0);
			zephir_array_fast_append(&_4$$3, this_ptr);
			ZEPHIR_OBS_NVAR(&_5$$3);
			zephir_array_fetch_long(&_5$$3, &item, 0, PH_NOISY, "phalcon/Html/Helper/AbstractHelper.zep", 138);
			zephir_array_fast_append(&_4$$3, &_5$$3);
			zephir_array_fetch_long(&_6$$3, &item, 1, PH_NOISY | PH_READONLY, "phalcon/Html/Helper/AbstractHelper.zep", 138);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_3$$3, &_4$$3, &_6$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZEPHIR_CONCAT_VVV(&_7$$3, &_2$$3, &_3$$3, &delimiter);
			zephir_concat_self(&result, &_7$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &elements, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &elements, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &elements, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_long(&_8$$4, &item, 2, PH_NOISY | PH_READONLY, "phalcon/Html/Helper/AbstractHelper.zep", 138);
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZEPHIR_INIT_NVAR(&_10$$4);
				zephir_create_array(&_10$$4, 2, 0);
				zephir_array_fast_append(&_10$$4, this_ptr);
				ZEPHIR_OBS_NVAR(&_11$$4);
				zephir_array_fetch_long(&_11$$4, &item, 0, PH_NOISY, "phalcon/Html/Helper/AbstractHelper.zep", 138);
				zephir_array_fast_append(&_10$$4, &_11$$4);
				zephir_array_fetch_long(&_12$$4, &item, 1, PH_NOISY | PH_READONLY, "phalcon/Html/Helper/AbstractHelper.zep", 138);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_9$$4, &_10$$4, &_12$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$4);
				ZEPHIR_CONCAT_VVV(&_13$$4, &_8$$4, &_9$$4, &delimiter);
				zephir_concat_self(&result, &_13$$4);
			ZEPHIR_CALL_METHOD(NULL, &elements, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&result);
}

/**
 * Renders all the attributes
 *
 * @param array $attributes
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, renderAttributes)
{
	zend_bool _4$$3, _8$$5;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, key, result, value, *_0, _1, _5$$4, _6$$4, _7$$4, _9$$6, _10$$6, _11$$6;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "");
	zephir_is_iterable(&attributes, 0, "phalcon/Html/Helper/AbstractHelper.zep", 163);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			_4$$3 = Z_TYPE_P(&key) == IS_STRING;
			if (_4$$3) {
				_4$$3 = Z_TYPE_P(&value) != IS_NULL;
			}
			if (_4$$3) {
				zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_6$$4, &_5$$4, "attributes", NULL, 0, &value);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZEPHIR_CONCAT_VSVS(&_7$$4, &key, "=\"", &_6$$4, "\" ");
				zephir_concat_self(&result, &_7$$4);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				_8$$5 = Z_TYPE_P(&key) == IS_STRING;
				if (_8$$5) {
					_8$$5 = Z_TYPE_P(&value) != IS_NULL;
				}
				if (_8$$5) {
					zephir_read_property(&_9$$6, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_10$$6, &_9$$6, "attributes", NULL, 0, &value);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_11$$6);
					ZEPHIR_CONCAT_VSVS(&_11$$6, &key, "=\"", &_10$$6, "\" ");
					zephir_concat_self(&result, &_11$$6);
				}
			ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);
}

/**
 * Renders an element
 *
 * @param string $tag
 * @param array  $attributes
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, renderElement)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *tag_param = NULL, *attributes_param = NULL;
	zval tag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(tag)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tag_param, &attributes_param);
	zephir_get_strval(&tag, tag_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "rendertag", NULL, 0, &tag, &attributes);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Renders an element
 *
 * @param string $tag
 * @param string $text
 * @param array  $attributes
 * @param bool   $raw
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, renderFullElement)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool raw;
	zval attributes;
	zval *tag_param = NULL, *text_param = NULL, *attributes_param = NULL, *raw_param = NULL, content, _0, _1, _2, _3;
	zval tag, text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(tag)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
		Z_PARAM_BOOL(raw)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &tag_param, &text_param, &attributes_param, &raw_param);
	zephir_get_strval(&tag, tag_param);
	zephir_get_strval(&text, text_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!raw_param) {
		raw = 0;
	} else {
		raw = zephir_get_boolval(raw_param);
	}


	if (raw) {
		ZEPHIR_CPY_WRT(&content, &text);
	} else {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&content, &_0, "html", NULL, 0, &text);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "renderelement", NULL, 0, &tag, &attributes);
	zephir_check_call_status();
	if (raw) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "close", NULL, 0, &tag, &_3);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVV(return_value, &_1, &content, &_2);
	RETURN_MM();
}

/**
 * Renders a tag
 *
 * @param string $tag
 * @param array  $attributes
 * @param string $close
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, renderTag)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *tag_param = NULL, *attributes_param = NULL, close, *close_param = NULL, attrs, escapedAttrs, _3, _4, _5, _0$$3, _1$$3, _2$$3;
	zval tag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&close);
	ZVAL_UNDEF(&attrs);
	ZVAL_UNDEF(&escapedAttrs);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(tag)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
		Z_PARAM_STR(close)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &tag_param, &attributes_param, &close_param);
	zephir_get_strval(&tag, tag_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!close_param) {
		ZEPHIR_INIT_VAR(&close);
		ZVAL_STRING(&close, "");
	} else {
		zephir_get_strval(&close, close_param);
	}


	ZEPHIR_INIT_VAR(&escapedAttrs);
	ZVAL_STRING(&escapedAttrs, "");
	if (zephir_fast_count_int(&attributes) > 0) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		ZEPHIR_CALL_METHOD(&attrs, this_ptr, "orderattributes", NULL, 0, &_0$$3, &attributes);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "renderattributes", NULL, 0, &attrs);
		zephir_check_call_status();
		zephir_fast_trim(&_1$$3, &_2$$3, NULL , ZEPHIR_TRIM_RIGHT);
		ZEPHIR_INIT_NVAR(&escapedAttrs);
		ZEPHIR_CONCAT_SV(&escapedAttrs, " ", &_1$$3);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_trim(&_4, &close, NULL , ZEPHIR_TRIM_BOTH);
	if (ZEPHIR_IS_EMPTY(&_4)) {
		ZEPHIR_INIT_NVAR(&_3);
		ZVAL_STRING(&_3, "");
	} else {
		ZEPHIR_INIT_VAR(&_5);
		zephir_fast_trim(&_5, &close, NULL , ZEPHIR_TRIM_BOTH);
		ZEPHIR_INIT_NVAR(&_3);
		ZEPHIR_CONCAT_SV(&_3, " ", &_5);
	}
	ZEPHIR_CPY_WRT(&close, &_3);
	ZEPHIR_CONCAT_SVVVS(return_value, "<", &tag, &escapedAttrs, &close, ">");
	RETURN_MM();
}

/**
 * Produces a self close tag i.e. <img />
 *
 * @param string $tag
 * @param array  $attributes
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, selfClose)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *tag_param = NULL, *attributes_param = NULL, _0;
	zval tag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(tag)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tag_param, &attributes_param);
	zephir_get_strval(&tag, tag_param);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "rendertag", NULL, 0, &tag, &attributes, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

