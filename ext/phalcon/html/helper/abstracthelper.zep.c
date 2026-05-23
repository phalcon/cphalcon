
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */
/**
 * @property string           $delimiter
 * @property EscaperInterface $escaper
 * @property string           $indent
 * @property int              $indentLevel
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_AbstractHelper)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Helper, AbstractHelper, phalcon, html_helper_abstracthelper, phalcon_html_helper_abstracthelper_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_abstracthelper_ce, SL("delimiter"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var Doctype|null
	 */
	zend_declare_property_null(phalcon_html_helper_abstracthelper_ce, SL("doctype"), ZEND_ACC_PROTECTED);
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
	zval *escaper, escaper_sub, *doctype = NULL, doctype_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&doctype_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_escaperinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(doctype, phalcon_html_helper_doctype_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &escaper, &doctype);
	if (!doctype) {
		doctype = &doctype_sub;
		doctype = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_EOL");
	zephir_update_property_zval(this_ptr, ZEND_STRL("delimiter"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("escaper"), escaper);
	zephir_update_property_zval(this_ptr, ZEND_STRL("doctype"), doctype);
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
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(tag_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(raw)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &tag_param, &raw_param);
	zephir_get_strval(&tag, tag_param);
	if (!raw_param) {
		raw = 0;
	} else {
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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

	ZVAL_UNDEF(&overrides);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&order);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&intersect);
	ZVAL_UNDEF(&results);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(overrides, overrides_param)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zend_string *delimiter = NULL;
	zval *elements_param = NULL, delimiter_zv, item, result, *_0, _7, _1$$3, _2$$3, _4$$3, _5$$3, _6$$3, _8$$4, _9$$4, _11$$4, _12$$4, _13$$4;
	zval elements, _3$$3, _10$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&delimiter_zv);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(elements, elements_param)
		Z_PARAM_STR(delimiter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	elements_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&elements, elements_param);
	zephir_memory_observe(&delimiter_zv);
	ZVAL_STR_COPY(&delimiter_zv, delimiter);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "");
	zephir_is_iterable(&elements, 0, "phalcon/Html/Helper/AbstractHelper.zep", 150);
	if (Z_TYPE_P(&elements) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&elements), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			zephir_array_fetch_long(&_1$$3, &item, 2, PH_NOISY | PH_READONLY, "phalcon/Html/Helper/AbstractHelper.zep", 146);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			zephir_create_array(&_3$$3, 2, 0);
			zephir_array_fast_append(&_3$$3, this_ptr);
			ZEPHIR_OBS_NVAR(&_4$$3);
			zephir_array_fetch_long(&_4$$3, &item, 0, PH_NOISY, "phalcon/Html/Helper/AbstractHelper.zep", 146);
			zephir_array_fast_append(&_3$$3, &_4$$3);
			zephir_array_fetch_long(&_5$$3, &item, 1, PH_NOISY | PH_READONLY, "phalcon/Html/Helper/AbstractHelper.zep", 146);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_2$$3, &_3$$3, &_5$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZEPHIR_CONCAT_VVV(&_6$$3, &_1$$3, &_2$$3, &delimiter_zv);
			zephir_concat_self(&result, &_6$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &elements, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_7, &elements, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &elements, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_fetch_long(&_8$$4, &item, 2, PH_NOISY | PH_READONLY, "phalcon/Html/Helper/AbstractHelper.zep", 146);
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZEPHIR_INIT_NVAR(&_10$$4);
				zephir_create_array(&_10$$4, 2, 0);
				zephir_array_fast_append(&_10$$4, this_ptr);
				ZEPHIR_OBS_NVAR(&_11$$4);
				zephir_array_fetch_long(&_11$$4, &item, 0, PH_NOISY, "phalcon/Html/Helper/AbstractHelper.zep", 146);
				zephir_array_fast_append(&_10$$4, &_11$$4);
				zephir_array_fetch_long(&_12$$4, &item, 1, PH_NOISY | PH_READONLY, "phalcon/Html/Helper/AbstractHelper.zep", 146);
				ZEPHIR_CALL_USER_FUNC_ARRAY(&_9$$4, &_10$$4, &_12$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$4);
				ZEPHIR_CONCAT_VVV(&_13$$4, &_8$$4, &_9$$4, &delimiter_zv);
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
	zend_bool _3$$3, _9$$7;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, key, result, value, *_0, _8, _4$$5, _5$$6, _6$$6, _7$$6, _10$$9, _11$$10, _12$$10, _13$$10;
	zval attributes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$10);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &attributes_param);
	zephir_get_arrval(&attributes, attributes_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "");
	zephir_is_iterable(&attributes, 0, "phalcon/Html/Helper/AbstractHelper.zep", 175);
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			_3$$3 = Z_TYPE_P(&key) == IS_STRING;
			if (_3$$3) {
				_3$$3 = Z_TYPE_P(&value) != IS_NULL;
			}
			if (_3$$3) {
				if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
					ZEPHIR_INIT_NVAR(&_4$$5);
					ZEPHIR_CONCAT_VS(&_4$$5, &key, " ");
					zephir_concat_self(&result, &_4$$5);
				} else {
					zephir_read_property(&_5$$6, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_6$$6, &_5$$6, "attributes", NULL, 0, &value);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_7$$6);
					ZEPHIR_CONCAT_VSVS(&_7$$6, &key, "=\"", &_6$$6, "\" ");
					zephir_concat_self(&result, &_7$$6);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &attributes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &attributes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &attributes, "current", NULL, 0);
			zephir_check_call_status();
				_9$$7 = Z_TYPE_P(&key) == IS_STRING;
				if (_9$$7) {
					_9$$7 = Z_TYPE_P(&value) != IS_NULL;
				}
				if (_9$$7) {
					if (ZEPHIR_IS_TRUE_IDENTICAL(&value)) {
						ZEPHIR_INIT_NVAR(&_10$$9);
						ZEPHIR_CONCAT_VS(&_10$$9, &key, " ");
						zephir_concat_self(&result, &_10$$9);
					} else {
						zephir_read_property(&_11$$10, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(&_12$$10, &_11$$10, "attributes", NULL, 0, &value);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_13$$10);
						ZEPHIR_CONCAT_VSVS(&_13$$10, &key, "=\"", &_12$$10, "\" ");
						zephir_concat_self(&result, &_13$$10);
					}
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
 * Forces a single key into the attribute array, stripping any user-supplied
 * value for that key first. Used by helpers whose first positional argument
 * is itself an attribute (`href` for Anchor, `src` for Img, etc.) to make
 * sure that argument always wins.
 *
 * @param string $key
 * @param string $value
 * @param array  $attributes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractHelper, injectAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval attributes, _0;
	zval key_zv, value_zv, *attributes_param = NULL;
	zend_string *key = NULL, *value = NULL;

	ZVAL_UNDEF(&key_zv);
	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(key)
		Z_PARAM_STR(value)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	attributes_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&key_zv);
	ZVAL_STR_COPY(&key_zv, key);
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	zephir_get_arrval(&attributes, attributes_param);
	zephir_array_unset(&attributes, &key_zv, PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0);
	zephir_array_update_zval(&_0, &key_zv, &value_zv, PH_COPY);
	zephir_fast_array_merge(return_value, &_0, &attributes);
	RETURN_MM();
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
	zval tag_zv, *attributes_param = NULL;
	zend_string *tag = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag_zv);
	ZVAL_UNDEF(&attributes);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(tag)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		attributes_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&tag_zv);
	ZVAL_STR_COPY(&tag_zv, tag);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "rendertag", NULL, 0, &tag_zv, &attributes);
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
	zval tag_zv, text_zv, *attributes_param = NULL, *raw_param = NULL, content, _0, _1, _2, _3;
	zend_string *tag = NULL, *text = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag_zv);
	ZVAL_UNDEF(&text_zv);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&attributes);
	ZEND_PARSE_PARAMETERS_START(2, 4)
		Z_PARAM_STR(tag)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_BOOL(raw)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		attributes_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (ZEND_NUM_ARGS() > 3) {
		raw_param = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&tag_zv);
	ZVAL_STR_COPY(&tag_zv, tag);
	zephir_memory_observe(&text_zv);
	ZVAL_STR_COPY(&text_zv, text);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!raw_param) {
		raw = 0;
	} else {
		}
	if (raw) {
		ZEPHIR_CPY_WRT(&content, &text_zv);
	} else {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("escaper"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&content, &_0, "html", NULL, 0, &text_zv);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "renderelement", NULL, 0, &tag_zv, &attributes);
	zephir_check_call_status();
	if (raw) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "close", NULL, 0, &tag_zv, &_3);
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
	zval tag_zv, *attributes_param = NULL, close_zv, attrs, escapedAttrs, localClose, _3, _4, _0$$3, _1$$3, _2$$3;
	zend_string *tag = NULL, *close = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag_zv);
	ZVAL_UNDEF(&close_zv);
	ZVAL_UNDEF(&attrs);
	ZVAL_UNDEF(&escapedAttrs);
	ZVAL_UNDEF(&localClose);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&attributes);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(tag)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
		Z_PARAM_STR(close)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		attributes_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&tag_zv);
	ZVAL_STR_COPY(&tag_zv, tag);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	if (!close) {
		close = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&close_zv);
		ZVAL_STR(&close_zv, close);
	} else {
		zephir_memory_observe(&close_zv);
	ZVAL_STR_COPY(&close_zv, close);
	}
	ZEPHIR_INIT_VAR(&escapedAttrs);
	ZVAL_STRING(&escapedAttrs, "");
	if (1 != ZEPHIR_IS_EMPTY(&attributes)) {
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
	zephir_fast_trim(&_3, &close_zv, NULL , ZEPHIR_TRIM_BOTH);
	if (ZEPHIR_IS_EMPTY(&_3)) {
		ZEPHIR_INIT_VAR(&localClose);
		ZVAL_STRING(&localClose, "");
	} else {
		ZEPHIR_INIT_VAR(&_4);
		zephir_fast_trim(&_4, &close_zv, NULL , ZEPHIR_TRIM_BOTH);
		ZEPHIR_INIT_NVAR(&localClose);
		ZEPHIR_CONCAT_SV(&localClose, " ", &_4);
	}
	ZEPHIR_CONCAT_SVVVS(return_value, "<", &tag_zv, &escapedAttrs, &localClose, ">");
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
	zval tag_zv, *attributes_param = NULL, _0;
	zend_string *tag = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&attributes);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(tag)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		attributes_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&tag_zv);
	ZVAL_STR_COPY(&tag_zv, tag);
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "rendertag", NULL, 0, &tag_zv, &attributes, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

