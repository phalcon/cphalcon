
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
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Input_Select_ResultsetData)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Helper\\Input\\Select, ResultsetData, phalcon, html_helper_input_select_resultsetdata, phalcon_html_helper_input_select_resultsetdata_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_helper_input_select_resultsetdata_ce, SL("attributesMap"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|null
	 */
	zend_declare_property_null(phalcon_html_helper_input_select_resultsetdata_ce, SL("resolvedAttributes"), ZEND_ACC_PROTECTED);
	/**
	 * @var array|null
	 */
	zend_declare_property_null(phalcon_html_helper_input_select_resultsetdata_ce, SL("resolvedOptions"), ZEND_ACC_PROTECTED);
	/**
	 * @var ResultsetInterface
	 */
	zend_declare_property_null(phalcon_html_helper_input_select_resultsetdata_ce, SL("resultset"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_helper_input_select_resultsetdata_ce, SL("using"), ZEND_ACC_PROTECTED);
	phalcon_html_helper_input_select_resultsetdata_ce->create_object = zephir_init_properties_Phalcon_Html_Helper_Input_Select_ResultsetData;

	zend_class_implements(phalcon_html_helper_input_select_resultsetdata_ce, 1, phalcon_contracts_html_helper_input_selectdata_ce);
	return SUCCESS;
}

/**
 * @param ResultsetInterface resultset
 * @param array              using
 * @param array              attributesMap
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 61);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("resultset"), resultset);
	zephir_update_property_zval(this_ptr, ZEND_STRL("using"), &using);
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributesMap"), &attributesMap);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns per-option attribute maps, keyed by option value.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select_ResultsetData, getAttributes)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("resolvedAttributes"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolve", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER_TYPED(getThis(), "resolvedAttributes", IS_ARRAY);
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select_ResultsetData, getOptions)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("resolvedOptions"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolve", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_MEMBER_TYPED(getThis(), "resolvedOptions", IS_ARRAY);
}

/**
 * Reads a property from the row, supporting both objects (via
 * `readAttribute` when present) and plain arrays.
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
			ZEPHIR_RETURN_CALL_METHOD(option, "readattribute", NULL, 0, &field_zv);
			zephir_check_call_status();
			RETURN_MM();
		}
		zephir_memory_observe(&_0$$3);
		zephir_read_property_zval(&_0$$3, option, &field_zv, PH_NOISY_CC);
		RETURN_CCTOR(&_0$$3);
	}
	zephir_array_fetch(&_1, option, &field_zv, PH_NOISY | PH_READONLY, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 109);
	RETURN_CTOR(&_1);
}

/**
 * Walks the resultset once, building both the option map and the
 * per-option resolved attribute map. Closures in `attributesMap`
 * receive the current row; static values are passed through.
 * `false` or `null` values skip the attribute entirely.
 */
PHP_METHOD(Phalcon_Html_Helper_Input_Select_ResultsetData, resolve)
{
	zval _15$$9, _19$$13, _30$$21, _34$$25;
	zend_string *_12$$5, *_28$$17;
	zend_ulong _11$$5, _27$$17;
	zend_bool _21, _4$$3, _17$$5, _14$$6, _18$$10, _22$$15, _32$$17, _29$$18, _33$$22;
	zval attrName, attrSpec, attrValue, attrs, option, optionAttrs, optionText, optionValue, options, usingZero, usingOne, _0, _1, _2, *_3, _20, _8$$3, _5$$4, _9$$5, *_10$$5, _16$$5, _24$$15, _23$$16, _25$$17, *_26$$17, _31$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_7 = NULL, *_13 = NULL;
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
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_31$$17);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_30$$21);
	ZVAL_UNDEF(&_34$$25);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("using"), PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&usingZero);
	zephir_array_fetch_long(&usingZero, &_0, 0, PH_NOISY, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 123);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("using"), PH_NOISY_CC | PH_READONLY);
	zephir_memory_observe(&usingOne);
	zephir_array_fetch_long(&usingOne, &_1, 1, PH_NOISY, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 124);
	ZEPHIR_INIT_VAR(&options);
	array_init(&options);
	ZEPHIR_INIT_VAR(&attrs);
	array_init(&attrs);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("resultset"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_2, 0, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 159);
	if (Z_TYPE_P(&_2) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2), _3)
		{
			ZEPHIR_INIT_NVAR(&option);
			ZVAL_COPY(&option, _3);
			_4$$3 = Z_TYPE_P(&option) != IS_OBJECT;
			if (_4$$3) {
				_4$$3 = Z_TYPE_P(&option) != IS_ARRAY;
			}
			if (_4$$3) {
				ZEPHIR_INIT_NVAR(&_5$$4);
				object_init_ex(&_5$$4, phalcon_html_exceptions_invalidresultsetvalue_ce);
				ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", &_6, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$4, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 130);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&optionValue, this_ptr, "readfield", &_7, 0, &option, &usingZero);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&optionText, this_ptr, "readfield", &_7, 0, &option, &usingOne);
			zephir_check_call_status();
			zephir_array_update_zval(&options, &optionValue, &optionText, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_8$$3);
			zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("attributesMap"), PH_NOISY_CC);
			if (!(ZEPHIR_IS_EMPTY(&_8$$3))) {
				ZEPHIR_INIT_NVAR(&optionAttrs);
				array_init(&optionAttrs);
				zephir_read_property(&_9$$5, this_ptr, ZEND_STRL("attributesMap"), PH_NOISY_CC | PH_READONLY);
				zephir_is_iterable(&_9$$5, 0, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 153);
				if (Z_TYPE_P(&_9$$5) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_9$$5), _11$$5, _12$$5, _10$$5)
					{
						ZEPHIR_INIT_NVAR(&attrName);
						if (_12$$5 != NULL) { 
							ZVAL_STR_COPY(&attrName, _12$$5);
						} else {
							ZVAL_LONG(&attrName, _11$$5);
						}
						ZEPHIR_INIT_NVAR(&attrSpec);
						ZVAL_COPY(&attrSpec, _10$$5);
						if (zephir_is_callable(&attrSpec)) {
							ZEPHIR_CALL_FUNCTION(&attrValue, "call_user_func", &_13, 342, &attrSpec, &option);
							zephir_check_call_status();
						} else {
							ZEPHIR_CPY_WRT(&attrValue, &attrSpec);
						}
						_14$$6 = !ZEPHIR_IS_FALSE_IDENTICAL(&attrValue);
						if (_14$$6) {
							_14$$6 = Z_TYPE_P(&attrValue) != IS_NULL;
						}
						if (_14$$6) {
							zephir_cast_to_string(&_15$$9, &attrValue);
							zephir_array_update_zval(&optionAttrs, &attrName, &_15$$9, PH_COPY | PH_SEPARATE);
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_9$$5, "rewind", NULL, 0);
					zephir_check_call_status();
					_17$$5 = 1;
					while (1) {
						if (_17$$5) {
							_17$$5 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &_9$$5, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_16$$5, &_9$$5, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_16$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&attrName, &_9$$5, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&attrSpec, &_9$$5, "current", NULL, 0);
						zephir_check_call_status();
							if (zephir_is_callable(&attrSpec)) {
								ZEPHIR_CALL_FUNCTION(&attrValue, "call_user_func", &_13, 342, &attrSpec, &option);
								zephir_check_call_status();
							} else {
								ZEPHIR_CPY_WRT(&attrValue, &attrSpec);
							}
							_18$$10 = !ZEPHIR_IS_FALSE_IDENTICAL(&attrValue);
							if (_18$$10) {
								_18$$10 = Z_TYPE_P(&attrValue) != IS_NULL;
							}
							if (_18$$10) {
								zephir_cast_to_string(&_19$$13, &attrValue);
								zephir_array_update_zval(&optionAttrs, &attrName, &_19$$13, PH_COPY | PH_SEPARATE);
							}
					}
				}
				ZEPHIR_INIT_NVAR(&attrSpec);
				ZEPHIR_INIT_NVAR(&attrName);
				if (!(ZEPHIR_IS_EMPTY(&optionAttrs))) {
					zephir_array_update_zval(&attrs, &optionValue, &optionAttrs, PH_COPY | PH_SEPARATE);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_2, "rewind", NULL, 0);
		zephir_check_call_status();
		_21 = 1;
		while (1) {
			if (_21) {
				_21 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_2, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_20, &_2, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_20)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&option, &_2, "current", NULL, 0);
			zephir_check_call_status();
				_22$$15 = Z_TYPE_P(&option) != IS_OBJECT;
				if (_22$$15) {
					_22$$15 = Z_TYPE_P(&option) != IS_ARRAY;
				}
				if (_22$$15) {
					ZEPHIR_INIT_NVAR(&_23$$16);
					object_init_ex(&_23$$16, phalcon_html_exceptions_invalidresultsetvalue_ce);
					ZEPHIR_CALL_METHOD(NULL, &_23$$16, "__construct", &_6, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_23$$16, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 130);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD(&optionValue, this_ptr, "readfield", &_7, 0, &option, &usingZero);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&optionText, this_ptr, "readfield", &_7, 0, &option, &usingOne);
				zephir_check_call_status();
				zephir_array_update_zval(&options, &optionValue, &optionText, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_24$$15);
				zephir_read_property(&_24$$15, this_ptr, ZEND_STRL("attributesMap"), PH_NOISY_CC);
				if (!(ZEPHIR_IS_EMPTY(&_24$$15))) {
					ZEPHIR_INIT_NVAR(&optionAttrs);
					array_init(&optionAttrs);
					zephir_read_property(&_25$$17, this_ptr, ZEND_STRL("attributesMap"), PH_NOISY_CC | PH_READONLY);
					zephir_is_iterable(&_25$$17, 0, "phalcon/Html/Helper/Input/Select/ResultsetData.zep", 153);
					if (Z_TYPE_P(&_25$$17) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_25$$17), _27$$17, _28$$17, _26$$17)
						{
							ZEPHIR_INIT_NVAR(&attrName);
							if (_28$$17 != NULL) { 
								ZVAL_STR_COPY(&attrName, _28$$17);
							} else {
								ZVAL_LONG(&attrName, _27$$17);
							}
							ZEPHIR_INIT_NVAR(&attrSpec);
							ZVAL_COPY(&attrSpec, _26$$17);
							if (zephir_is_callable(&attrSpec)) {
								ZEPHIR_CALL_FUNCTION(&attrValue, "call_user_func", &_13, 342, &attrSpec, &option);
								zephir_check_call_status();
							} else {
								ZEPHIR_CPY_WRT(&attrValue, &attrSpec);
							}
							_29$$18 = !ZEPHIR_IS_FALSE_IDENTICAL(&attrValue);
							if (_29$$18) {
								_29$$18 = Z_TYPE_P(&attrValue) != IS_NULL;
							}
							if (_29$$18) {
								zephir_cast_to_string(&_30$$21, &attrValue);
								zephir_array_update_zval(&optionAttrs, &attrName, &_30$$21, PH_COPY | PH_SEPARATE);
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &_25$$17, "rewind", NULL, 0);
						zephir_check_call_status();
						_32$$17 = 1;
						while (1) {
							if (_32$$17) {
								_32$$17 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &_25$$17, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_31$$17, &_25$$17, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_31$$17)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attrName, &_25$$17, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&attrSpec, &_25$$17, "current", NULL, 0);
							zephir_check_call_status();
								if (zephir_is_callable(&attrSpec)) {
									ZEPHIR_CALL_FUNCTION(&attrValue, "call_user_func", &_13, 342, &attrSpec, &option);
									zephir_check_call_status();
								} else {
									ZEPHIR_CPY_WRT(&attrValue, &attrSpec);
								}
								_33$$22 = !ZEPHIR_IS_FALSE_IDENTICAL(&attrValue);
								if (_33$$22) {
									_33$$22 = Z_TYPE_P(&attrValue) != IS_NULL;
								}
								if (_33$$22) {
									zephir_cast_to_string(&_34$$25, &attrValue);
									zephir_array_update_zval(&optionAttrs, &attrName, &_34$$25, PH_COPY | PH_SEPARATE);
								}
						}
					}
					ZEPHIR_INIT_NVAR(&attrSpec);
					ZEPHIR_INIT_NVAR(&attrName);
					if (!(ZEPHIR_IS_EMPTY(&optionAttrs))) {
						zephir_array_update_zval(&attrs, &optionValue, &optionAttrs, PH_COPY | PH_SEPARATE);
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&option);
	zephir_update_property_zval(this_ptr, ZEND_STRL("resolvedOptions"), &options);
	zephir_update_property_zval(this_ptr, ZEND_STRL("resolvedAttributes"), &attrs);
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Phalcon_Html_Helper_Input_Select_ResultsetData(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("using"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("using"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("attributesMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("attributesMap"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

