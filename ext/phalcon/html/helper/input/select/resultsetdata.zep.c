
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
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
 * @phpstan-import-type html_select_attributes from HtmlTypes
 * @phpstan-import-type html_select_attributes_map from HtmlTypes
 * @phpstan-import-type html_select_options from HtmlTypes
 * @phpstan-import-type html_select_using from HtmlTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Select_ResultsetData)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Helper\\Input\\Select, ResultsetData, phalcon, html_helper_input_select_resultsetdata, phalcon_html_helper_input_select_resultsetdata_method_entry, 0);

	/**
	 * @param html_select_attributes_map
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_html_helper_input_select_resultsetdata_ce, SL("attributesMap"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @var html_select_attributes|null
	 */
	zend_declare_property_null(phalcon_html_helper_input_select_resultsetdata_ce, SL("resolvedAttributes"), ZEND_ACC_PROTECTED);
	/**
	 * @var html_select_options|null
	 */
	zend_declare_property_null(phalcon_html_helper_input_select_resultsetdata_ce, SL("resolvedOptions"), ZEND_ACC_PROTECTED);
	/**
	 * @var ResultsetInterface
	 */
	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_html_helper_input_select_resultsetdata_ce, SL("resultset"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Mvc\\Model\\ResultsetInterface"));
	}

	/**
	 * @param html_select_using
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_html_helper_input_select_resultsetdata_ce, SL("using"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	zend_class_implements(phalcon_html_helper_input_select_resultsetdata_ce, 1, phalcon_contracts_html_helper_input_selectdata_ce);
	return SUCCESS;
}

/**
 * @param html_select_using            $using
 * @param html_select_attributes_map   $attributesMap
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select_ResultsetData, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval using, attributesMap;
	zval *resultset, resultset_sub, *using_param = NULL, *attributesMap_param = NULL, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&resultset_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&using);
	ZVAL_UNDEF(&attributesMap);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("resultset", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("using", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("attributesMap", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(resultset, phalcon_mvc_model_resultsetinterface_ce)
		ZEPHIR_Z_PARAM_ARRAY(using, using_param)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(attributesMap, attributesMap_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &resultset, &using_param, &attributesMap_param);
	zephir_get_arrval(&using, using_param);
	if (!attributesMap_param) {
		ZEPHIR_INIT_VAR(&attributesMap);
		array_init(&attributesMap);
	} else {
		zephir_get_arrval(&attributesMap, attributesMap_param);
	}
	if (UNEXPECTED(zephir_fast_count_int(&using) != 2)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_html_exceptions_usingrequirestwovalues_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 66);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 863, resultset);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 864, &using);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 865, &attributesMap);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns per-option attribute maps, keyed by option value.
 *
 * @phpstan-return html_select_attributes
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select_ResultsetData, getAttributes)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("resolvedAttributes", 18, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 866, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "resolve", &_zephir_call_cache[0]);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER_TYPED(getThis(), "resolvedAttributes", IS_ARRAY);
}

/**
 * @phpstan-return html_select_options
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select_ResultsetData, getOptions)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("resolvedOptions", 15, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 867, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "resolve", &_zephir_call_cache[0]);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER_TYPED(getThis(), "resolvedOptions", IS_ARRAY);
}

/**
 * Reads a property from the row, supporting both objects (via
 * `readAttribute` when available) and plain arrays.
 *
 * @param array<array-key, mixed>|object $option
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select_ResultsetData, readField)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *field = NULL;
	zval *option, option_sub, field_zv, _0$$3, _1;

	ZVAL_UNDEF(&option_sub);
	ZVAL_UNDEF(&field_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(option)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	option = ZEND_CALL_ARG(execute_data, 1);
	zephir_memory_observe(&field_zv);
	ZVAL_STR_COPY(&field_zv, field);
	if (Z_TYPE_P(option) == IS_OBJECT) {
		if ((zephir_method_exists_ex(option, ZEND_STRL("readattribute")) == SUCCESS)) {
			ZEPHIR_RETURN_CALL_METHOD_CACHED(option, "readAttribute", &_zephir_call_cache[0], &field_zv);
			zephir_check_call_status();
			RETURN_MM();
		}
		zephir_memory_observe(&_0$$3);
		zephir_read_property_zval(&_0$$3, option, &field_zv, PH_NOISY_CC);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&_0$$3);
	}
	zephir_memory_observe(&_1);
	zephir_array_fetch(&_1, option, &field_zv, PH_NOISY, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 116);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&_1);
}

/**
 * Walks the resultset once, building both the option map and the
 * per-option resolved attribute map. Closures in `attributesMap`
 * receive the current row; static values are passed through.
 * `false` or `null` values skip the attribute entirely.
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select_ResultsetData, resolve)
{
	zval _17$$9, _21$$13, _34$$21, _38$$25;
	zend_string *_14$$5, *_32$$17;
	zend_ulong _13$$5, _31$$17;
	zend_bool _23, _6$$3, _8$$3, _19$$5, _16$$6, _20$$10, _24$$15, _26$$15, _36$$17, _33$$18, _37$$22;
	zval attrName, attrSpec, attrValue, attrs, option, optionAttrs, optionText, optionValue, options, usingZero, usingOne, _0, _1, _2, *_3, _4, *_5, _22, _7$$4, _9$$5, *_10$$5, _11$$5, *_12$$5, _18$$5, _25$$16, _27$$17, *_28$$17, _29$$17, *_30$$17, _35$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&attrName);
	ZVAL_UNDEF(&attrSpec);
	ZVAL_UNDEF(&attrValue);
	ZVAL_UNDEF(&attrs);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&optionAttrs);
	ZVAL_UNDEF(&optionText);
	ZVAL_UNDEF(&optionValue);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&usingZero);
	ZVAL_UNDEF(&usingOne);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_29$$17);
	ZVAL_UNDEF(&_35$$17);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_38$$25);
	ZEND_TLS zephir_method_cache _zephir_call_cache[20];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("using", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("resultset", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("attributesMap", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("resolvedOptions", 15, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("resolvedAttributes", 18, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 864, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&usingZero);
	zephir_array_fetch_long(&usingZero, &_0, 0, PH_NOISY, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 130);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 864, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&usingOne);
	zephir_array_fetch_long(&usingOne, &_1, 1, PH_NOISY, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 131);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&options);
	array_init(&options);
	ZEPHIR_INIT_VAR(&attrs);
	array_init(&attrs);
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 863, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_2) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &_2);
		_3 = &_4;
	} else {
		_3 = &_2;
	}
	zephir_is_iterable(_3, 0, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 166);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _5)
		{
			ZEPHIR_INIT_NVAR(&option);
			ZVAL_COPY(&option, _5);
			_6$$3 = Z_TYPE_P(&option) != IS_OBJECT;
			if (_6$$3) {
				_6$$3 = Z_TYPE_P(&option) != IS_ARRAY;
			}
			if (_6$$3) {
				ZEPHIR_INIT_NVAR(&_7$$4);
				object_init_ex(&_7$$4, phalcon_html_exceptions_invalidresultsetvalue_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_7$$4, "__construct", &_zephir_call_cache[0]);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$4, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 137);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&optionValue, this_ptr, "readField", &_zephir_call_cache[1], &option, &usingZero);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&optionText, this_ptr, "readField", &_zephir_call_cache[2], &option, &usingOne);
			zephir_check_call_status();
			zephir_array_update_zval(&options, &optionValue, &optionText, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_8$$3 = zephir_isempty_property_fast(this_ptr, _zephir_prop_2);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_8$$3)) {
				ZEPHIR_INIT_NVAR(&optionAttrs);
				array_init(&optionAttrs);
				zephir_read_property_cached(&_9$$5, this_ptr, _zephir_prop_2, 865, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&_9$$5) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_11$$5);
					zephir_string_to_char_array(&_11$$5, &_9$$5);
					_10$$5 = &_11$$5;
				} else {
					_10$$5 = &_9$$5;
				}
				zephir_is_iterable(_10$$5, 0, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 160);
				if (Z_TYPE_P(_10$$5) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_10$$5), _13$$5, _14$$5, _12$$5)
					{
						ZEPHIR_INIT_NVAR(&attrName);
						if (_14$$5 != NULL) { 
							ZVAL_STR_COPY(&attrName, _14$$5);
						} else {
							ZVAL_LONG(&attrName, _13$$5);
						}
						ZEPHIR_INIT_NVAR(&attrSpec);
						ZVAL_COPY(&attrSpec, _12$$5);
						if (zephir_is_callable(&attrSpec)) {
							ZEPHIR_CALL_FUNCTION(&attrValue, "call_user_func", &_15, 34, &attrSpec, &option);
							zephir_check_call_status();
						} else {
							ZEPHIR_CPY_WRT(&attrValue, &attrSpec);
						}
						_16$$6 = !ZEPHIR_IS_FALSE_IDENTICAL(&attrValue);
						if (_16$$6) {
							_16$$6 = Z_TYPE_P(&attrValue) != IS_NULL;
						}
						if (_16$$6) {
							zephir_cast_to_string(&_17$$9, &attrValue);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_zval(&optionAttrs, &attrName, &_17$$9, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _10$$5, "rewind", &_zephir_call_cache[3]);
					zephir_check_call_status();
					_19$$5 = 1;
					while (1) {
						if (_19$$5) {
							_19$$5 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _10$$5, "next", &_zephir_call_cache[4]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_18$$5, _10$$5, "valid", &_zephir_call_cache[5]);
						zephir_check_call_status();
						if (!zend_is_true(&_18$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&attrName, _10$$5, "key", &_zephir_call_cache[6]);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD_CACHED(&attrSpec, _10$$5, "current", &_zephir_call_cache[7]);
						zephir_check_call_status();
							if (zephir_is_callable(&attrSpec)) {
								ZEPHIR_CALL_FUNCTION(&attrValue, "call_user_func", &_15, 34, &attrSpec, &option);
								zephir_check_call_status();
							} else {
								ZEPHIR_CPY_WRT(&attrValue, &attrSpec);
							}
							_20$$10 = !ZEPHIR_IS_FALSE_IDENTICAL(&attrValue);
							if (_20$$10) {
								_20$$10 = Z_TYPE_P(&attrValue) != IS_NULL;
							}
							if (_20$$10) {
								zephir_cast_to_string(&_21$$13, &attrValue);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&optionAttrs, &attrName, &_21$$13, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
					}
				}
				ZEPHIR_INIT_NVAR(&attrSpec);
				ZEPHIR_INIT_NVAR(&attrName);
				if (!(ZEPHIR_IS_EMPTY(&optionAttrs))) {
					zephir_array_update_zval(&attrs, &optionValue, &optionAttrs, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "rewind", &_zephir_call_cache[8]);
		zephir_check_call_status();
		_23 = 1;
		while (1) {
			if (_23) {
				_23 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "next", &_zephir_call_cache[9]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_22, _3, "valid", &_zephir_call_cache[10]);
			zephir_check_call_status();
			if (!zend_is_true(&_22)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&option, _3, "current", &_zephir_call_cache[11]);
			zephir_check_call_status();
				_24$$15 = Z_TYPE_P(&option) != IS_OBJECT;
				if (_24$$15) {
					_24$$15 = Z_TYPE_P(&option) != IS_ARRAY;
				}
				if (_24$$15) {
					ZEPHIR_INIT_NVAR(&_25$$16);
					object_init_ex(&_25$$16, phalcon_html_exceptions_invalidresultsetvalue_ce);
					ZEPHIR_CALL_METHOD_CACHED(NULL, &_25$$16, "__construct", &_zephir_call_cache[12]);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_25$$16, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 137);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&optionValue, this_ptr, "readField", &_zephir_call_cache[13], &option, &usingZero);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&optionText, this_ptr, "readField", &_zephir_call_cache[14], &option, &usingOne);
				zephir_check_call_status();
				zephir_array_update_zval(&options, &optionValue, &optionText, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_26$$15 = zephir_isempty_property_fast(this_ptr, _zephir_prop_2);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_26$$15)) {
					ZEPHIR_INIT_NVAR(&optionAttrs);
					array_init(&optionAttrs);
					zephir_read_property_cached(&_27$$17, this_ptr, _zephir_prop_2, 865, PH_NOISY_CC | PH_READONLY);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&_27$$17) == IS_STRING) {
						ZEPHIR_INIT_NVAR(&_29$$17);
						zephir_string_to_char_array(&_29$$17, &_27$$17);
						_28$$17 = &_29$$17;
					} else {
						_28$$17 = &_27$$17;
					}
					zephir_is_iterable(_28$$17, 0, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 160);
					if (Z_TYPE_P(_28$$17) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_28$$17), _31$$17, _32$$17, _30$$17)
						{
							ZEPHIR_INIT_NVAR(&attrName);
							if (_32$$17 != NULL) { 
								ZVAL_STR_COPY(&attrName, _32$$17);
							} else {
								ZVAL_LONG(&attrName, _31$$17);
							}
							ZEPHIR_INIT_NVAR(&attrSpec);
							ZVAL_COPY(&attrSpec, _30$$17);
							if (zephir_is_callable(&attrSpec)) {
								ZEPHIR_CALL_FUNCTION(&attrValue, "call_user_func", &_15, 34, &attrSpec, &option);
								zephir_check_call_status();
							} else {
								ZEPHIR_CPY_WRT(&attrValue, &attrSpec);
							}
							_33$$18 = !ZEPHIR_IS_FALSE_IDENTICAL(&attrValue);
							if (_33$$18) {
								_33$$18 = Z_TYPE_P(&attrValue) != IS_NULL;
							}
							if (_33$$18) {
								zephir_cast_to_string(&_34$$21, &attrValue);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_array_update_zval(&optionAttrs, &attrName, &_34$$21, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _28$$17, "rewind", &_zephir_call_cache[15]);
						zephir_check_call_status();
						_36$$17 = 1;
						while (1) {
							if (_36$$17) {
								_36$$17 = 0;
							} else {
								ZEPHIR_CALL_METHOD_CACHED(NULL, _28$$17, "next", &_zephir_call_cache[16]);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD_CACHED(&_35$$17, _28$$17, "valid", &_zephir_call_cache[17]);
							zephir_check_call_status();
							if (!zend_is_true(&_35$$17)) {
								break;
							}
							ZEPHIR_CALL_METHOD_CACHED(&attrName, _28$$17, "key", &_zephir_call_cache[18]);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&attrSpec, _28$$17, "current", &_zephir_call_cache[19]);
							zephir_check_call_status();
								if (zephir_is_callable(&attrSpec)) {
									ZEPHIR_CALL_FUNCTION(&attrValue, "call_user_func", &_15, 34, &attrSpec, &option);
									zephir_check_call_status();
								} else {
									ZEPHIR_CPY_WRT(&attrValue, &attrSpec);
								}
								_37$$22 = !ZEPHIR_IS_FALSE_IDENTICAL(&attrValue);
								if (_37$$22) {
									_37$$22 = Z_TYPE_P(&attrValue) != IS_NULL;
								}
								if (_37$$22) {
									zephir_cast_to_string(&_38$$25, &attrValue);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
									zephir_array_update_zval(&optionAttrs, &attrName, &_38$$25, PH_COPY | PH_SEPARATE);
									if (UNEXPECTED(EG(exception))) {
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
						}
					}
					ZEPHIR_INIT_NVAR(&attrSpec);
					ZEPHIR_INIT_NVAR(&attrName);
					if (!(ZEPHIR_IS_EMPTY(&optionAttrs))) {
						zephir_array_update_zval(&attrs, &optionValue, &optionAttrs, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&option);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 867, &options);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 866, &attrs);
	ZEPHIR_MM_RESTORE();
}

