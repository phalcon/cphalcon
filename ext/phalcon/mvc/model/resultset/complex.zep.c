
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Resultset\Complex
 *
 * Complex resultsets may include complete objects and scalar values.
 * This class builds every complex row as it is required
 *
 * @template TKey of int
 * @template TValue of mixed
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Complex)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Resultset, Complex, phalcon, mvc_model_resultset_complex, phalcon_mvc_model_resultset_ce, phalcon_mvc_model_resultset_complex_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_resultset_complex_ce, SL("columnTypes"), ZEND_ACC_PROTECTED);
	/**
	 * Unserialised result-set hydrated all rows already. unserialise() sets
	 * disableHydration to true
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_resultset_complex_ce, SL("disableHydration"), 0, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Resultset\Complex constructor
 *
 * @param array                $columnTypes
 * @param ResultInterface|null $result
 * @param mixed|null           $cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columnTypes, columnTypes_sub, *result = NULL, result_sub, *cache = NULL, cache_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columnTypes_sub);
	ZVAL_UNDEF(&result_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_ZVAL(columnTypes)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(result, phalcon_db_resultinterface_ce)
		Z_PARAM_ZVAL_OR_NULL(cache)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 2, &columnTypes, &result, &cache);
	if (!result) {
		result = &result_sub;
		result = &__$null;
	}
	if (!cache) {
		cache = &cache_sub;
		cache = &__$null;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("columnTypes"), columnTypes);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_resultset_complex_ce, getThis(), "__construct", NULL, 0, result, cache);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __serialize)
{
	zval records, cache, columnTypes, hydrateMode, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&columnTypes);
	ZVAL_UNDEF(&hydrateMode);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&records, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("cache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cache, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("columnTypes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&columnTypes, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("hydrateMode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&hydrateMode, &_0);
	zephir_create_array(return_value, 4, 0);
	zephir_array_update_string(return_value, SL("cache"), &cache, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("rows"), &records, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("columnTypes"), &columnTypes, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("hydrateMode"), &hydrateMode, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __unserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL, __$true, __$false, _0, _1, _2, _3, _4, _5;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("disableHydration"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("disableHydration"), &__$false);
	}
	zephir_array_fetch_string(&_0, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 102);
	zephir_update_property_zval(this_ptr, ZEND_STRL("rows"), &_0);
	zephir_array_fetch_string(&_1, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 103);
	ZVAL_UNDEF(&_2);
	ZVAL_LONG(&_2, zephir_fast_count_int(&_1));
	zephir_update_property_zval(this_ptr, ZEND_STRL("count"), &_2);
	zephir_array_fetch_string(&_3, &data, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 104);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cache"), &_3);
	zephir_array_fetch_string(&_4, &data, SL("columnTypes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 105);
	zephir_update_property_zval(this_ptr, ZEND_STRL("columnTypes"), &_4);
	zephir_array_fetch_string(&_5, &data, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 106);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hydrateMode"), &_5);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns current row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, current)
{
	zend_class_entry *_23$$20, *_48$$44;
	zend_string *_4;
	zend_ulong _3;
	zend_bool allNull = 0, _31, _10$$11, _13$$11, _36$$35, _39$$35;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_15 = NULL, *_24 = NULL, *_27 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, dirtyState = 0;
	zval __$true, __$false, row, hydrateMode, eager, alias, activeRow, type, column, columnValue, value, attribute, source, attributes, columnMap, rowModel, keepSnapshots, sqlAlias, modelName, _0, _1, *_2, _30, _5$$10, *_7$$11, _9$$11, *_12$$11, _14$$11, _16$$11, _8$$12, _11$$13, _17$$18, _18$$18, _19$$20, _21$$20, _22$$20, _20$$21, _25$$23, _26$$23, _28$$29, _29$$29, _32$$34, *_33$$35, _35$$35, *_38$$35, _40$$35, _41$$35, _34$$36, _37$$37, _42$$42, _43$$42, _44$$44, _46$$44, _47$$44, _45$$45, _49$$47, _50$$47, _51$$53, _52$$53;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&hydrateMode);
	ZVAL_UNDEF(&eager);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&activeRow);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&columnValue);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&rowModel);
	ZVAL_UNDEF(&keepSnapshots);
	ZVAL_UNDEF(&sqlAlias);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_11$$13);
	ZVAL_UNDEF(&_17$$18);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_19$$20);
	ZVAL_UNDEF(&_21$$20);
	ZVAL_UNDEF(&_22$$20);
	ZVAL_UNDEF(&_20$$21);
	ZVAL_UNDEF(&_25$$23);
	ZVAL_UNDEF(&_26$$23);
	ZVAL_UNDEF(&_28$$29);
	ZVAL_UNDEF(&_29$$29);
	ZVAL_UNDEF(&_32$$34);
	ZVAL_UNDEF(&_35$$35);
	ZVAL_UNDEF(&_40$$35);
	ZVAL_UNDEF(&_41$$35);
	ZVAL_UNDEF(&_34$$36);
	ZVAL_UNDEF(&_37$$37);
	ZVAL_UNDEF(&_42$$42);
	ZVAL_UNDEF(&_43$$42);
	ZVAL_UNDEF(&_44$$44);
	ZVAL_UNDEF(&_46$$44);
	ZVAL_UNDEF(&_47$$44);
	ZVAL_UNDEF(&_45$$45);
	ZVAL_UNDEF(&_49$$47);
	ZVAL_UNDEF(&_50$$47);
	ZVAL_UNDEF(&_51$$53);
	ZVAL_UNDEF(&_52$$53);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("activeRow"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&activeRow, &_0);
	if (Z_TYPE_P(&activeRow) != IS_NULL) {
		RETURN_CCTOR(&activeRow);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("row"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&row, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("disableHydration"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("activeRow"), &row);
		RETURN_CCTOR(&row);
	}
	if (Z_TYPE_P(&row) != IS_ARRAY) {
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("activeRow"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("activeRow"), &__$false);
		}
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("hydrateMode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&hydrateMode, &_1);
	do {
		if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
			ZEPHIR_INIT_NVAR(&activeRow);
			object_init_ex(&activeRow, phalcon_mvc_model_row_ce);
			if (zephir_has_constructor(&activeRow)) {
				ZEPHIR_CALL_METHOD(NULL, &activeRow, "__construct", NULL, 0);
				zephir_check_call_status();
			}

			break;
		}
		if (ZEPHIR_IS_LONG(&hydrateMode, 1)) {
			ZEPHIR_INIT_NVAR(&activeRow);
			array_init(&activeRow);
			break;
		}
		ZEPHIR_INIT_NVAR(&activeRow);
		object_init(&activeRow);
		break;
	} while(0);

	dirtyState = 0;
	zephir_read_property(&_1, this_ptr, ZEND_STRL("columnTypes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_1, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 324);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1), _3, _4, _2)
		{
			ZEPHIR_INIT_NVAR(&alias);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&alias, _4);
			} else {
				ZVAL_LONG(&alias, _3);
			}
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _2);
			if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
				ZEPHIR_INIT_NVAR(&_5$$10);
				object_init_ex(&_5$$10, phalcon_mvc_model_exceptions_corruptcolumntype_ce);
				ZEPHIR_CALL_METHOD(NULL, &_5$$10, "__construct", &_6, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$10, "phalcon/Mvc/Model/Resultset/Complex.zep", 181);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_string(&type, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 184);
			if (ZEPHIR_IS_STRING(&type, "object")) {
				ZEPHIR_OBS_NVAR(&source);
				zephir_array_fetch_string(&source, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 190);
				ZEPHIR_OBS_NVAR(&attributes);
				zephir_array_fetch_string(&attributes, &column, SL("attributes"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 191);
				ZEPHIR_OBS_NVAR(&columnMap);
				zephir_array_fetch_string(&columnMap, &column, SL("columnMap"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 192);
				ZEPHIR_INIT_NVAR(&rowModel);
				array_init(&rowModel);
				zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 217);
				if (Z_TYPE_P(&attributes) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _7$$11)
					{
						ZEPHIR_INIT_NVAR(&attribute);
						ZVAL_COPY(&attribute, _7$$11);
						ZEPHIR_OBS_NVAR(&columnValue);
						ZEPHIR_INIT_NVAR(&_8$$12);
						ZEPHIR_CONCAT_SVSV(&_8$$12, "_", &source, "_", &attribute);
						zephir_array_fetch(&columnValue, &row, &_8$$12, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 203);
						zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
					zephir_check_call_status();
					_10$$11 = 1;
					while (1) {
						if (_10$$11) {
							_10$$11 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_9$$11, &attributes, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_9$$11)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&columnValue);
							ZEPHIR_INIT_NVAR(&_11$$13);
							ZEPHIR_CONCAT_SVSV(&_11$$13, "_", &source, "_", &attribute);
							zephir_array_fetch(&columnValue, &row, &_11$$13, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 203);
							zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
					}
				}
				ZEPHIR_INIT_NVAR(&attribute);
				allNull = 1;
				zephir_is_iterable(&rowModel, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 225);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rowModel), _12$$11)
				{
					ZEPHIR_INIT_NVAR(&columnValue);
					ZVAL_COPY(&columnValue, _12$$11);
					if (Z_TYPE_P(&columnValue) != IS_NULL) {
						allNull = 0;
						break;
					}
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&columnValue);
				_13$$11 = allNull;
				if (_13$$11) {
					ZEPHIR_INIT_NVAR(&_16$$11);
					ZVAL_STRING(&_16$$11, "orm.resultset_empty_left_join_model");
					ZEPHIR_CALL_CE_STATIC(&_14$$11, phalcon_support_settings_ce, "get", &_15, 0, &_16$$11);
					zephir_check_call_status();
					_13$$11 = !zephir_is_true(&_14$$11);
				}
				if (_13$$11) {
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_NULL(&value);
				} else {
					do {
						if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
							ZEPHIR_OBS_NVAR(&keepSnapshots);
							if (!(zephir_array_isset_string_fetch(&keepSnapshots, &column, SL("keepSnapshots"), 0))) {
								ZEPHIR_INIT_NVAR(&keepSnapshots);
								ZVAL_BOOL(&keepSnapshots, 0);
							}
							ZEPHIR_INIT_NVAR(&_18$$18);
							ZVAL_STRING(&_18$$18, "orm.late_state_binding");
							ZEPHIR_CALL_CE_STATIC(&_17$$18, phalcon_support_settings_ce, "get", &_15, 0, &_18$$18);
							zephir_check_call_status();
							if (zephir_is_true(&_17$$18)) {
								ZEPHIR_OBS_NVAR(&_19$$20);
								zephir_array_fetch_string(&_19$$20, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 239);
								if (zephir_instance_of_ev(&_19$$20, phalcon_mvc_model_ce)) {
									zephir_array_fetch_string(&_20$$21, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 240);
									ZEPHIR_INIT_NVAR(&modelName);
									zephir_get_class(&modelName, &_20$$21, 0);
								} else {
									ZEPHIR_INIT_NVAR(&modelName);
									ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
								}
								zephir_array_fetch_string(&_21$$20, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 246);
								ZVAL_LONG(&_22$$20, dirtyState);
								_23$$20 = zephir_fetch_class(&modelName);
								ZEPHIR_CALL_CE_STATIC(&value, _23$$20, "cloneresultmap", NULL, 0, &_21$$20, &rowModel, &columnMap, &_22$$20, &keepSnapshots);
								zephir_check_call_status();
							} else {
								zephir_array_fetch_string(&_25$$23, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 258);
								ZVAL_LONG(&_26$$23, dirtyState);
								ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmap", &_24, 0, &_25$$23, &rowModel, &columnMap, &_26$$23, &keepSnapshots);
								zephir_check_call_status();
							}
							break;
						}
						ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_27, 0, &rowModel, &columnMap, &hydrateMode);
						zephir_check_call_status();
						break;
					} while(0);

				}
				ZEPHIR_OBS_NVAR(&attribute);
				zephir_array_fetch_string(&attribute, &column, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 283);
			} else {
				ZEPHIR_OBS_NVAR(&sqlAlias);
				if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_fetch(&value, &row, &sqlAlias, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 289);
				} else {
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_isset_fetch(&value, &row, &alias, 0);
				}
				if (zephir_array_isset_value_string(&column, SL("balias"))) {
					ZEPHIR_CPY_WRT(&attribute, &alias);
				} else {
					ZEPHIR_INIT_NVAR(&_28$$29);
					ZVAL_STRING(&_28$$29, "_");
					ZEPHIR_INIT_NVAR(&_29$$29);
					ZVAL_STRING(&_29$$29, "");
					ZEPHIR_INIT_NVAR(&attribute);
					zephir_fast_str_replace(&attribute, &_28$$29, &_29$$29, &alias);
				}
			}
			if (!(zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 1))) {
				do {
					if (ZEPHIR_IS_LONG(&hydrateMode, 1)) {
						zephir_array_update_zval(&activeRow, &attribute, &value, PH_COPY | PH_SEPARATE);
						break;
					}
					zephir_update_property_zval_zval(&activeRow, &attribute, &value);
					break;
				} while(0);

			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
		zephir_check_call_status();
		_31 = 1;
		while (1) {
			if (_31) {
				_31 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_30, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_30)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&alias, &_1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&column, &_1, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
					ZEPHIR_INIT_NVAR(&_32$$34);
					object_init_ex(&_32$$34, phalcon_mvc_model_exceptions_corruptcolumntype_ce);
					ZEPHIR_CALL_METHOD(NULL, &_32$$34, "__construct", &_6, 0);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_32$$34, "phalcon/Mvc/Model/Resultset/Complex.zep", 181);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_string(&type, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 184);
				if (ZEPHIR_IS_STRING(&type, "object")) {
					ZEPHIR_OBS_NVAR(&source);
					zephir_array_fetch_string(&source, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 190);
					ZEPHIR_OBS_NVAR(&attributes);
					zephir_array_fetch_string(&attributes, &column, SL("attributes"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 191);
					ZEPHIR_OBS_NVAR(&columnMap);
					zephir_array_fetch_string(&columnMap, &column, SL("columnMap"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 192);
					ZEPHIR_INIT_NVAR(&rowModel);
					array_init(&rowModel);
					zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 217);
					if (Z_TYPE_P(&attributes) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _33$$35)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _33$$35);
							ZEPHIR_OBS_NVAR(&columnValue);
							ZEPHIR_INIT_NVAR(&_34$$36);
							ZEPHIR_CONCAT_SVSV(&_34$$36, "_", &source, "_", &attribute);
							zephir_array_fetch(&columnValue, &row, &_34$$36, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 203);
							zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
						zephir_check_call_status();
						_36$$35 = 1;
						while (1) {
							if (_36$$35) {
								_36$$35 = 0;
							} else {
								ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(&_35$$35, &attributes, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_35$$35)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&columnValue);
								ZEPHIR_INIT_NVAR(&_37$$37);
								ZEPHIR_CONCAT_SVSV(&_37$$37, "_", &source, "_", &attribute);
								zephir_array_fetch(&columnValue, &row, &_37$$37, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 203);
								zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
					allNull = 1;
					zephir_is_iterable(&rowModel, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 225);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rowModel), _38$$35)
					{
						ZEPHIR_INIT_NVAR(&columnValue);
						ZVAL_COPY(&columnValue, _38$$35);
						if (Z_TYPE_P(&columnValue) != IS_NULL) {
							allNull = 0;
							break;
						}
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&columnValue);
					_39$$35 = allNull;
					if (_39$$35) {
						ZEPHIR_INIT_NVAR(&_41$$35);
						ZVAL_STRING(&_41$$35, "orm.resultset_empty_left_join_model");
						ZEPHIR_CALL_CE_STATIC(&_40$$35, phalcon_support_settings_ce, "get", &_15, 0, &_41$$35);
						zephir_check_call_status();
						_39$$35 = !zephir_is_true(&_40$$35);
					}
					if (_39$$35) {
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_NULL(&value);
					} else {
						do {
							if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
								ZEPHIR_OBS_NVAR(&keepSnapshots);
								if (!(zephir_array_isset_string_fetch(&keepSnapshots, &column, SL("keepSnapshots"), 0))) {
									ZEPHIR_INIT_NVAR(&keepSnapshots);
									ZVAL_BOOL(&keepSnapshots, 0);
								}
								ZEPHIR_INIT_NVAR(&_43$$42);
								ZVAL_STRING(&_43$$42, "orm.late_state_binding");
								ZEPHIR_CALL_CE_STATIC(&_42$$42, phalcon_support_settings_ce, "get", &_15, 0, &_43$$42);
								zephir_check_call_status();
								if (zephir_is_true(&_42$$42)) {
									ZEPHIR_OBS_NVAR(&_44$$44);
									zephir_array_fetch_string(&_44$$44, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 239);
									if (zephir_instance_of_ev(&_44$$44, phalcon_mvc_model_ce)) {
										zephir_array_fetch_string(&_45$$45, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 240);
										ZEPHIR_INIT_NVAR(&modelName);
										zephir_get_class(&modelName, &_45$$45, 0);
									} else {
										ZEPHIR_INIT_NVAR(&modelName);
										ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
									}
									zephir_array_fetch_string(&_46$$44, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 246);
									ZVAL_LONG(&_47$$44, dirtyState);
									_48$$44 = zephir_fetch_class(&modelName);
									ZEPHIR_CALL_CE_STATIC(&value, _48$$44, "cloneresultmap", NULL, 0, &_46$$44, &rowModel, &columnMap, &_47$$44, &keepSnapshots);
									zephir_check_call_status();
								} else {
									zephir_array_fetch_string(&_49$$47, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 258);
									ZVAL_LONG(&_50$$47, dirtyState);
									ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmap", &_24, 0, &_49$$47, &rowModel, &columnMap, &_50$$47, &keepSnapshots);
									zephir_check_call_status();
								}
								break;
							}
							ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_27, 0, &rowModel, &columnMap, &hydrateMode);
							zephir_check_call_status();
							break;
						} while(0);

					}
					ZEPHIR_OBS_NVAR(&attribute);
					zephir_array_fetch_string(&attribute, &column, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 283);
				} else {
					ZEPHIR_OBS_NVAR(&sqlAlias);
					if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
						ZEPHIR_OBS_NVAR(&value);
						zephir_array_fetch(&value, &row, &sqlAlias, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 289);
					} else {
						ZEPHIR_OBS_NVAR(&value);
						zephir_array_isset_fetch(&value, &row, &alias, 0);
					}
					if (zephir_array_isset_value_string(&column, SL("balias"))) {
						ZEPHIR_CPY_WRT(&attribute, &alias);
					} else {
						ZEPHIR_INIT_NVAR(&_51$$53);
						ZVAL_STRING(&_51$$53, "_");
						ZEPHIR_INIT_NVAR(&_52$$53);
						ZVAL_STRING(&_52$$53, "");
						ZEPHIR_INIT_NVAR(&attribute);
						zephir_fast_str_replace(&attribute, &_51$$53, &_52$$53, &alias);
					}
				}
				ZEPHIR_OBS_NVAR(&eager);
				if (!(zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 0))) {
					do {
						if (ZEPHIR_IS_LONG(&hydrateMode, 1)) {
							zephir_array_update_zval(&activeRow, &attribute, &value, PH_COPY | PH_SEPARATE);
							break;
						}
						zephir_update_property_zval_zval(&activeRow, &attribute, &value);
						break;
					} while(0);

				}
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	ZEPHIR_INIT_NVAR(&alias);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeRow"), &activeRow);
	RETURN_CCTOR(&activeRow);
}

/**
 * Serializing a resultset will dump all related rows into a big array,
 * serialize it and return the resulting string
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, serialize)
{
	zval data;
	zval container, serializer, _1, _2, _3, _0$$3, _4$$4, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&data);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_exceptions_invalidcontainer_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Resultset/Complex.zep", 340);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 4, 0);
	zephir_memory_observe(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("cache"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("cache"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("rows"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("columnTypes"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("columnTypes"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("hydrateMode"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("hydrateMode"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "serializer");
	ZEPHIR_CALL_METHOD(&_2, &container, "has", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "serializer");
		ZEPHIR_CALL_METHOD(&_4$$4, &container, "getshared", NULL, 0, &_5$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&serializer, &_4$$4);
		ZEPHIR_CALL_METHOD(NULL, &serializer, "setdata", NULL, 0, &data);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&serializer, "serialize", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 21, &data);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a complete resultset as an array, if the resultset has a big
 * number of rows it could consume more memory than currently it does.
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, toArray)
{
	zval records;
	zval current, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&records);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 170);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&current, this_ptr, "current", &_2, 0);
		zephir_check_call_status();
		zephir_array_append(&records, &current, PH_SEPARATE, "phalcon/Mvc/Model/Resultset/Complex.zep", 375);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_3, 0);
		zephir_check_call_status();
	}
	RETURN_CTOR(&records);
}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, unserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, __$true, __$false, resultset, container, serializer, _1, _2, _6, _7, _8, _9, _10, _11, _0$$3, _3$$4, _4$$4, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data);
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("disableHydration"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("disableHydration"), &__$false);
	}
	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_exceptions_invalidcontainer_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Resultset/Complex.zep", 397);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "serializer");
	ZEPHIR_CALL_METHOD(&_1, &container, "has", NULL, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "serializer");
		ZEPHIR_CALL_METHOD(&_3$$4, &container, "getshared", NULL, 0, &_4$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&serializer, &_3$$4);
		ZEPHIR_CALL_METHOD(NULL, &serializer, "unserialize", NULL, 0, data);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&resultset, &serializer, "getdata", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&resultset, "unserialize", NULL, 26, data);
		zephir_check_call_status();
	}
	if (UNEXPECTED(Z_TYPE_P(&resultset) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_5$$6);
		object_init_ex(&_5$$6, phalcon_mvc_model_exceptions_invalidserializationdata_ce);
		ZEPHIR_CALL_METHOD(NULL, &_5$$6, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$6, "phalcon/Mvc/Model/Resultset/Complex.zep", 410);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&_6, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 413);
	zephir_update_property_zval(this_ptr, ZEND_STRL("rows"), &_6);
	zephir_array_fetch_string(&_7, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 414);
	ZVAL_UNDEF(&_8);
	ZVAL_LONG(&_8, zephir_fast_count_int(&_7));
	zephir_update_property_zval(this_ptr, ZEND_STRL("count"), &_8);
	zephir_array_fetch_string(&_9, &resultset, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 415);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cache"), &_9);
	zephir_array_fetch_string(&_10, &resultset, SL("columnTypes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 416);
	zephir_update_property_zval(this_ptr, ZEND_STRL("columnTypes"), &_10);
	zephir_array_fetch_string(&_11, &resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 417);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hydrateMode"), &_11);
	ZEPHIR_MM_RESTORE();
}

