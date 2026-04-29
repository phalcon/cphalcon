
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"
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

/**
 * Returns current row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, current)
{
	zend_class_entry *_19$$22, *_38$$48;
	zend_string *_5;
	zend_ulong _4;
	zend_bool allNull = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL, *_20 = NULL, *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, dirtyState = 0;
	zval __$true, __$false, row, hydrateMode, eager, alias, activeRow, type, column, columnValue, value, attribute, source, attributes, columnMap, rowModel, keepSnapshots, sqlAlias, modelName, _0, _1, *_2, _3, *_6$$11, _7$$11, *_10$$11, _11$$11, _8$$12, _9$$13, _12$$20, _14$$20, _15$$22, _17$$22, _18$$22, _16$$23, _21$$25, _22$$25, _24$$31, _25$$31, *_26$$37, _27$$37, *_30$$37, _31$$37, _28$$38, _29$$39, _32$$46, _33$$46, _34$$48, _36$$48, _37$$48, _35$$49, _39$$51, _40$$51, _41$$57, _42$$57;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_12$$20);
	ZVAL_UNDEF(&_14$$20);
	ZVAL_UNDEF(&_15$$22);
	ZVAL_UNDEF(&_17$$22);
	ZVAL_UNDEF(&_18$$22);
	ZVAL_UNDEF(&_16$$23);
	ZVAL_UNDEF(&_21$$25);
	ZVAL_UNDEF(&_22$$25);
	ZVAL_UNDEF(&_24$$31);
	ZVAL_UNDEF(&_25$$31);
	ZVAL_UNDEF(&_27$$37);
	ZVAL_UNDEF(&_31$$37);
	ZVAL_UNDEF(&_28$$38);
	ZVAL_UNDEF(&_29$$39);
	ZVAL_UNDEF(&_32$$46);
	ZVAL_UNDEF(&_33$$46);
	ZVAL_UNDEF(&_34$$48);
	ZVAL_UNDEF(&_36$$48);
	ZVAL_UNDEF(&_37$$48);
	ZVAL_UNDEF(&_35$$49);
	ZVAL_UNDEF(&_39$$51);
	ZVAL_UNDEF(&_40$$51);
	ZVAL_UNDEF(&_41$$57);
	ZVAL_UNDEF(&_42$$57);
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
	zephir_is_iterable(&_1, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 279);
	if (Z_TYPE_P(&_1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1), _4, _5, _2)
		{
			ZEPHIR_INIT_NVAR(&alias);
			if (_5 != NULL) { 
				ZVAL_STR_COPY(&alias, _5);
			} else {
				ZVAL_LONG(&alias, _4);
			}
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _2);
			if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Column type is corrupt", "phalcon/Mvc/Model/Resultset/Complex.zep", 143);
				return;
			}
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_string(&type, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 146);
			if (ZEPHIR_IS_STRING(&type, "object")) {
				ZEPHIR_OBS_NVAR(&source);
				zephir_array_fetch_string(&source, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 152);
				ZEPHIR_OBS_NVAR(&attributes);
				zephir_array_fetch_string(&attributes, &column, SL("attributes"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 153);
				ZEPHIR_OBS_NVAR(&columnMap);
				zephir_array_fetch_string(&columnMap, &column, SL("columnMap"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 154);
				ZEPHIR_INIT_NVAR(&rowModel);
				array_init(&rowModel);
				zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 172);
				if (Z_TYPE_P(&attributes) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _6$$11)
					{
						ZEPHIR_INIT_NVAR(&attribute);
						ZVAL_COPY(&attribute, _6$$11);
						ZEPHIR_OBS_NVAR(&columnValue);
						ZEPHIR_INIT_NVAR(&_8$$12);
						ZEPHIR_CONCAT_SVSV(&_8$$12, "_", &source, "_", &attribute);
						zephir_array_fetch(&columnValue, &row, &_8$$12, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 165);
						zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_7$$11, &attributes, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_7$$11)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&columnValue);
							ZEPHIR_INIT_NVAR(&_9$$13);
							ZEPHIR_CONCAT_SVSV(&_9$$13, "_", &source, "_", &attribute);
							zephir_array_fetch(&columnValue, &row, &_9$$13, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 165);
							zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&attribute);
				allNull = 1;
				zephir_is_iterable(&rowModel, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 180);
				if (Z_TYPE_P(&rowModel) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rowModel), _10$$11)
					{
						ZEPHIR_INIT_NVAR(&columnValue);
						ZVAL_COPY(&columnValue, _10$$11);
						if (Z_TYPE_P(&columnValue) != IS_NULL) {
							allNull = 0;
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &rowModel, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_11$$11, &rowModel, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_11$$11)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&columnValue, &rowModel, "current", NULL, 0);
						zephir_check_call_status();
							if (Z_TYPE_P(&columnValue) != IS_NULL) {
								allNull = 0;
								break;
							}
						ZEPHIR_CALL_METHOD(NULL, &rowModel, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&columnValue);
				if (allNull) {
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
							ZEPHIR_INIT_NVAR(&_14$$20);
							ZVAL_STRING(&_14$$20, "orm.late_state_binding");
							ZEPHIR_CALL_CE_STATIC(&_12$$20, phalcon_support_settings_ce, "get", &_13, 0, &_14$$20);
							zephir_check_call_status();
							if (zephir_is_true(&_12$$20)) {
								ZEPHIR_OBS_NVAR(&_15$$22);
								zephir_array_fetch_string(&_15$$22, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 194);
								if (zephir_instance_of_ev(&_15$$22, phalcon_mvc_model_ce)) {
									zephir_array_fetch_string(&_16$$23, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 195);
									ZEPHIR_INIT_NVAR(&modelName);
									zephir_get_class(&modelName, &_16$$23, 0);
								} else {
									ZEPHIR_INIT_NVAR(&modelName);
									ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
								}
								zephir_array_fetch_string(&_17$$22, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 201);
								ZVAL_LONG(&_18$$22, dirtyState);
								_19$$22 = zephir_fetch_class(&modelName);
								ZEPHIR_CALL_CE_STATIC(&value, _19$$22, "cloneresultmap", NULL, 0, &_17$$22, &rowModel, &columnMap, &_18$$22, &keepSnapshots);
								zephir_check_call_status();
							} else {
								zephir_array_fetch_string(&_21$$25, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 213);
								ZVAL_LONG(&_22$$25, dirtyState);
								ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmap", &_20, 0, &_21$$25, &rowModel, &columnMap, &_22$$25, &keepSnapshots);
								zephir_check_call_status();
							}
							break;
						}
						ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_23, 0, &rowModel, &columnMap, &hydrateMode);
						zephir_check_call_status();
						break;
					} while(0);

				}
				ZEPHIR_OBS_NVAR(&attribute);
				zephir_array_fetch_string(&attribute, &column, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 238);
			} else {
				ZEPHIR_OBS_NVAR(&sqlAlias);
				if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_fetch(&value, &row, &sqlAlias, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 244);
				} else {
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_isset_fetch(&value, &row, &alias, 0);
				}
				if (zephir_array_isset_string(&column, SL("balias"))) {
					ZEPHIR_CPY_WRT(&attribute, &alias);
				} else {
					ZEPHIR_INIT_NVAR(&_24$$31);
					ZVAL_STRING(&_24$$31, "_");
					ZEPHIR_INIT_NVAR(&_25$$31);
					ZVAL_STRING(&_25$$31, "");
					ZEPHIR_INIT_NVAR(&attribute);
					zephir_fast_str_replace(&attribute, &_24$$31, &_25$$31, &alias);
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
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &_1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&alias, &_1, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&column, &_1, "current", NULL, 0);
			zephir_check_call_status();
				if (UNEXPECTED(Z_TYPE_P(&column) != IS_ARRAY)) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Column type is corrupt", "phalcon/Mvc/Model/Resultset/Complex.zep", 143);
					return;
				}
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_string(&type, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 146);
				if (ZEPHIR_IS_STRING(&type, "object")) {
					ZEPHIR_OBS_NVAR(&source);
					zephir_array_fetch_string(&source, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 152);
					ZEPHIR_OBS_NVAR(&attributes);
					zephir_array_fetch_string(&attributes, &column, SL("attributes"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 153);
					ZEPHIR_OBS_NVAR(&columnMap);
					zephir_array_fetch_string(&columnMap, &column, SL("columnMap"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 154);
					ZEPHIR_INIT_NVAR(&rowModel);
					array_init(&rowModel);
					zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 172);
					if (Z_TYPE_P(&attributes) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _26$$37)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _26$$37);
							ZEPHIR_OBS_NVAR(&columnValue);
							ZEPHIR_INIT_NVAR(&_28$$38);
							ZEPHIR_CONCAT_SVSV(&_28$$38, "_", &source, "_", &attribute);
							zephir_array_fetch(&columnValue, &row, &_28$$38, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 165);
							zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_27$$37, &attributes, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_27$$37)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&columnValue);
								ZEPHIR_INIT_NVAR(&_29$$39);
								ZEPHIR_CONCAT_SVSV(&_29$$39, "_", &source, "_", &attribute);
								zephir_array_fetch(&columnValue, &row, &_29$$39, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 165);
								zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
					allNull = 1;
					zephir_is_iterable(&rowModel, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 180);
					if (Z_TYPE_P(&rowModel) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rowModel), _30$$37)
						{
							ZEPHIR_INIT_NVAR(&columnValue);
							ZVAL_COPY(&columnValue, _30$$37);
							if (Z_TYPE_P(&columnValue) != IS_NULL) {
								allNull = 0;
								break;
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &rowModel, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_31$$37, &rowModel, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_31$$37)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&columnValue, &rowModel, "current", NULL, 0);
							zephir_check_call_status();
								if (Z_TYPE_P(&columnValue) != IS_NULL) {
									allNull = 0;
									break;
								}
							ZEPHIR_CALL_METHOD(NULL, &rowModel, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&columnValue);
					if (allNull) {
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
								ZEPHIR_INIT_NVAR(&_33$$46);
								ZVAL_STRING(&_33$$46, "orm.late_state_binding");
								ZEPHIR_CALL_CE_STATIC(&_32$$46, phalcon_support_settings_ce, "get", &_13, 0, &_33$$46);
								zephir_check_call_status();
								if (zephir_is_true(&_32$$46)) {
									ZEPHIR_OBS_NVAR(&_34$$48);
									zephir_array_fetch_string(&_34$$48, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 194);
									if (zephir_instance_of_ev(&_34$$48, phalcon_mvc_model_ce)) {
										zephir_array_fetch_string(&_35$$49, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 195);
										ZEPHIR_INIT_NVAR(&modelName);
										zephir_get_class(&modelName, &_35$$49, 0);
									} else {
										ZEPHIR_INIT_NVAR(&modelName);
										ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
									}
									zephir_array_fetch_string(&_36$$48, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 201);
									ZVAL_LONG(&_37$$48, dirtyState);
									_38$$48 = zephir_fetch_class(&modelName);
									ZEPHIR_CALL_CE_STATIC(&value, _38$$48, "cloneresultmap", NULL, 0, &_36$$48, &rowModel, &columnMap, &_37$$48, &keepSnapshots);
									zephir_check_call_status();
								} else {
									zephir_array_fetch_string(&_39$$51, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 213);
									ZVAL_LONG(&_40$$51, dirtyState);
									ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmap", &_20, 0, &_39$$51, &rowModel, &columnMap, &_40$$51, &keepSnapshots);
									zephir_check_call_status();
								}
								break;
							}
							ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_23, 0, &rowModel, &columnMap, &hydrateMode);
							zephir_check_call_status();
							break;
						} while(0);

					}
					ZEPHIR_OBS_NVAR(&attribute);
					zephir_array_fetch_string(&attribute, &column, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 238);
				} else {
					ZEPHIR_OBS_NVAR(&sqlAlias);
					if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
						ZEPHIR_OBS_NVAR(&value);
						zephir_array_fetch(&value, &row, &sqlAlias, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 244);
					} else {
						ZEPHIR_OBS_NVAR(&value);
						zephir_array_isset_fetch(&value, &row, &alias, 0);
					}
					if (zephir_array_isset_string(&column, SL("balias"))) {
						ZEPHIR_CPY_WRT(&attribute, &alias);
					} else {
						ZEPHIR_INIT_NVAR(&_41$$57);
						ZVAL_STRING(&_41$$57, "_");
						ZEPHIR_INIT_NVAR(&_42$$57);
						ZVAL_STRING(&_42$$57, "");
						ZEPHIR_INIT_NVAR(&attribute);
						zephir_fast_str_replace(&attribute, &_41$$57, &_42$$57, &alias);
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
			ZEPHIR_CALL_METHOD(NULL, &_1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	ZEPHIR_INIT_NVAR(&alias);
	zephir_update_property_zval(this_ptr, ZEND_STRL("activeRow"), &activeRow);
	RETURN_CCTOR(&activeRow);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 99);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&current, this_ptr, "current", &_2, 491);
		zephir_check_call_status();
		zephir_array_append(&records, &current, PH_SEPARATE, "phalcon/Mvc/Model/Resultset/Complex.zep", 299);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_3, 0);
		zephir_check_call_status();
	}
	RETURN_CTOR(&records);
}

/**
 * Serializing a resultset will dump all related rows into a big array,
 * serialize it and return the resulting string
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, serialize)
{
	zval data;
	zval container, serializer, _0, _1, _2, _3$$4, _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&data);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector container is not valid", "phalcon/Mvc/Model/Resultset/Complex.zep", 320);
		return;
	}
	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 4, 0);
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("cache"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("cache"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("rows"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("columnTypes"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("columnTypes"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("hydrateMode"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("hydrateMode"), &_0, PH_COPY | PH_SEPARATE);
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
		ZEPHIR_CALL_METHOD(NULL, &serializer, "setdata", NULL, 0, &data);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&serializer, "serialize", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 14, &data);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, unserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, __$true, __$false, resultset, container, serializer, _0, _1, _4, _5, _6, _7, _8, _9, _2$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector container is not valid", "phalcon/Mvc/Model/Resultset/Complex.zep", 356);
		return;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "serializer");
	ZEPHIR_CALL_METHOD(&_0, &container, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "serializer");
		ZEPHIR_CALL_METHOD(&_2$$4, &container, "getshared", NULL, 0, &_3$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&serializer, &_2$$4);
		ZEPHIR_CALL_METHOD(NULL, &serializer, "unserialize", NULL, 0, data);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&resultset, &serializer, "getdata", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&resultset, "unserialize", NULL, 15, data);
		zephir_check_call_status();
	}
	if (UNEXPECTED(Z_TYPE_P(&resultset) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data", "phalcon/Mvc/Model/Resultset/Complex.zep", 369);
		return;
	}
	zephir_array_fetch_string(&_4, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 372);
	zephir_update_property_zval(this_ptr, ZEND_STRL("rows"), &_4);
	zephir_array_fetch_string(&_5, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 373);
	ZVAL_UNDEF(&_6);
	ZVAL_LONG(&_6, zephir_fast_count_int(&_5));
	zephir_update_property_zval(this_ptr, ZEND_STRL("count"), &_6);
	zephir_array_fetch_string(&_7, &resultset, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 374);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cache"), &_7);
	zephir_array_fetch_string(&_8, &resultset, SL("columnTypes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 375);
	zephir_update_property_zval(this_ptr, ZEND_STRL("columnTypes"), &_8);
	zephir_array_fetch_string(&_9, &resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 376);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hydrateMode"), &_9);
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
	zephir_array_fetch_string(&_0, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 407);
	zephir_update_property_zval(this_ptr, ZEND_STRL("rows"), &_0);
	zephir_array_fetch_string(&_1, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 408);
	ZVAL_UNDEF(&_2);
	ZVAL_LONG(&_2, zephir_fast_count_int(&_1));
	zephir_update_property_zval(this_ptr, ZEND_STRL("count"), &_2);
	zephir_array_fetch_string(&_3, &data, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 409);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cache"), &_3);
	zephir_array_fetch_string(&_4, &data, SL("columnTypes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 410);
	zephir_update_property_zval(this_ptr, ZEND_STRL("columnTypes"), &_4);
	zephir_array_fetch_string(&_5, &data, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 411);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hydrateMode"), &_5);
	ZEPHIR_MM_RESTORE();
}

