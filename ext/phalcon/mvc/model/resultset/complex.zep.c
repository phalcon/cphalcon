
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
	zend_class_entry *_14$$16, *_29$$36;
	zend_string *_5;
	zend_ulong _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_15 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, dirtyState = 0;
	zval __$true, __$false, row, hydrateMode, eager, alias, activeRow, type, column, columnValue, value, attribute, source, attributes, columnMap, rowModel, keepSnapshots, sqlAlias, modelName, _0, _1, *_2, _3, *_6$$11, _7$$11, _8$$12, _9$$13, _10$$16, _12$$16, _13$$16, _11$$17, _16$$19, _17$$19, _19$$25, _20$$25, *_21$$31, _22$$31, _23$$32, _24$$33, _25$$36, _27$$36, _28$$36, _26$$37, _30$$39, _31$$39, _32$$45, _33$$45;
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
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_10$$16);
	ZVAL_UNDEF(&_12$$16);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_11$$17);
	ZVAL_UNDEF(&_16$$19);
	ZVAL_UNDEF(&_17$$19);
	ZVAL_UNDEF(&_19$$25);
	ZVAL_UNDEF(&_20$$25);
	ZVAL_UNDEF(&_22$$31);
	ZVAL_UNDEF(&_23$$32);
	ZVAL_UNDEF(&_24$$33);
	ZVAL_UNDEF(&_25$$36);
	ZVAL_UNDEF(&_27$$36);
	ZVAL_UNDEF(&_28$$36);
	ZVAL_UNDEF(&_26$$37);
	ZVAL_UNDEF(&_30$$39);
	ZVAL_UNDEF(&_31$$39);
	ZVAL_UNDEF(&_32$$45);
	ZVAL_UNDEF(&_33$$45);
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
	zephir_is_iterable(&_1, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 262);
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
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Column type is corrupt", "phalcon/Mvc/Model/Resultset/Complex.zep", 141);
				return;
			}
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_string(&type, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 144);
			if (ZEPHIR_IS_STRING(&type, "object")) {
				ZEPHIR_OBS_NVAR(&source);
				zephir_array_fetch_string(&source, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 150);
				ZEPHIR_OBS_NVAR(&attributes);
				zephir_array_fetch_string(&attributes, &column, SL("attributes"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 151);
				ZEPHIR_OBS_NVAR(&columnMap);
				zephir_array_fetch_string(&columnMap, &column, SL("columnMap"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 152);
				ZEPHIR_INIT_NVAR(&rowModel);
				array_init(&rowModel);
				zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 170);
				if (Z_TYPE_P(&attributes) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _6$$11)
					{
						ZEPHIR_INIT_NVAR(&attribute);
						ZVAL_COPY(&attribute, _6$$11);
						ZEPHIR_OBS_NVAR(&columnValue);
						ZEPHIR_INIT_NVAR(&_8$$12);
						ZEPHIR_CONCAT_SVSV(&_8$$12, "_", &source, "_", &attribute);
						zephir_array_fetch(&columnValue, &row, &_8$$12, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 163);
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
							zephir_array_fetch(&columnValue, &row, &_9$$13, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 163);
							zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&attribute);
				do {
					if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
						ZEPHIR_OBS_NVAR(&keepSnapshots);
						if (!(zephir_array_isset_string_fetch(&keepSnapshots, &column, SL("keepSnapshots"), 0))) {
							ZEPHIR_INIT_NVAR(&keepSnapshots);
							ZVAL_BOOL(&keepSnapshots, 0);
						}
						if (ZEPHIR_GLOBAL(orm).late_state_binding) {
							ZEPHIR_OBS_NVAR(&_10$$16);
							zephir_array_fetch_string(&_10$$16, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 178);
							if (zephir_instance_of_ev(&_10$$16, phalcon_mvc_model_ce)) {
								zephir_array_fetch_string(&_11$$17, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 179);
								ZEPHIR_INIT_NVAR(&modelName);
								zephir_get_class(&modelName, &_11$$17, 0);
							} else {
								ZEPHIR_INIT_NVAR(&modelName);
								ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
							}
							zephir_array_fetch_string(&_12$$16, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 185);
							ZVAL_LONG(&_13$$16, dirtyState);
							_14$$16 = zephir_fetch_class(&modelName);
							ZEPHIR_CALL_CE_STATIC(&value, _14$$16, "cloneresultmap", NULL, 0, &_12$$16, &rowModel, &columnMap, &_13$$16, &keepSnapshots);
							zephir_check_call_status();
						} else {
							zephir_array_fetch_string(&_16$$19, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 197);
							ZVAL_LONG(&_17$$19, dirtyState);
							ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmap", &_15, 0, &_16$$19, &rowModel, &columnMap, &_17$$19, &keepSnapshots);
							zephir_check_call_status();
						}
						break;
					}
					ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_18, 0, &rowModel, &columnMap, &hydrateMode);
					zephir_check_call_status();
					break;
				} while(0);

				ZEPHIR_OBS_NVAR(&attribute);
				zephir_array_fetch_string(&attribute, &column, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 221);
			} else {
				ZEPHIR_OBS_NVAR(&sqlAlias);
				if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_fetch(&value, &row, &sqlAlias, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 227);
				} else {
					ZEPHIR_OBS_NVAR(&value);
					zephir_array_isset_fetch(&value, &row, &alias, 0);
				}
				if (zephir_array_isset_string(&column, SL("balias"))) {
					ZEPHIR_CPY_WRT(&attribute, &alias);
				} else {
					ZEPHIR_INIT_NVAR(&_19$$25);
					ZVAL_STRING(&_19$$25, "_");
					ZEPHIR_INIT_NVAR(&_20$$25);
					ZVAL_STRING(&_20$$25, "");
					ZEPHIR_INIT_NVAR(&attribute);
					zephir_fast_str_replace(&attribute, &_19$$25, &_20$$25, &alias);
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
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Column type is corrupt", "phalcon/Mvc/Model/Resultset/Complex.zep", 141);
					return;
				}
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_string(&type, &column, SL("type"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 144);
				if (ZEPHIR_IS_STRING(&type, "object")) {
					ZEPHIR_OBS_NVAR(&source);
					zephir_array_fetch_string(&source, &column, SL("column"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 150);
					ZEPHIR_OBS_NVAR(&attributes);
					zephir_array_fetch_string(&attributes, &column, SL("attributes"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 151);
					ZEPHIR_OBS_NVAR(&columnMap);
					zephir_array_fetch_string(&columnMap, &column, SL("columnMap"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 152);
					ZEPHIR_INIT_NVAR(&rowModel);
					array_init(&rowModel);
					zephir_is_iterable(&attributes, 0, "phalcon/Mvc/Model/Resultset/Complex.zep", 170);
					if (Z_TYPE_P(&attributes) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _21$$31)
						{
							ZEPHIR_INIT_NVAR(&attribute);
							ZVAL_COPY(&attribute, _21$$31);
							ZEPHIR_OBS_NVAR(&columnValue);
							ZEPHIR_INIT_NVAR(&_23$$32);
							ZEPHIR_CONCAT_SVSV(&_23$$32, "_", &source, "_", &attribute);
							zephir_array_fetch(&columnValue, &row, &_23$$32, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 163);
							zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &attributes, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_22$$31, &attributes, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_22$$31)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&attribute, &attributes, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&columnValue);
								ZEPHIR_INIT_NVAR(&_24$$33);
								ZEPHIR_CONCAT_SVSV(&_24$$33, "_", &source, "_", &attribute);
								zephir_array_fetch(&columnValue, &row, &_24$$33, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 163);
								zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &attributes, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&attribute);
					do {
						if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
							ZEPHIR_OBS_NVAR(&keepSnapshots);
							if (!(zephir_array_isset_string_fetch(&keepSnapshots, &column, SL("keepSnapshots"), 0))) {
								ZEPHIR_INIT_NVAR(&keepSnapshots);
								ZVAL_BOOL(&keepSnapshots, 0);
							}
							if (ZEPHIR_GLOBAL(orm).late_state_binding) {
								ZEPHIR_OBS_NVAR(&_25$$36);
								zephir_array_fetch_string(&_25$$36, &column, SL("instance"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 178);
								if (zephir_instance_of_ev(&_25$$36, phalcon_mvc_model_ce)) {
									zephir_array_fetch_string(&_26$$37, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 179);
									ZEPHIR_INIT_NVAR(&modelName);
									zephir_get_class(&modelName, &_26$$37, 0);
								} else {
									ZEPHIR_INIT_NVAR(&modelName);
									ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
								}
								zephir_array_fetch_string(&_27$$36, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 185);
								ZVAL_LONG(&_28$$36, dirtyState);
								_29$$36 = zephir_fetch_class(&modelName);
								ZEPHIR_CALL_CE_STATIC(&value, _29$$36, "cloneresultmap", NULL, 0, &_27$$36, &rowModel, &columnMap, &_28$$36, &keepSnapshots);
								zephir_check_call_status();
							} else {
								zephir_array_fetch_string(&_30$$39, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 197);
								ZVAL_LONG(&_31$$39, dirtyState);
								ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmap", &_15, 0, &_30$$39, &rowModel, &columnMap, &_31$$39, &keepSnapshots);
								zephir_check_call_status();
							}
							break;
						}
						ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_18, 0, &rowModel, &columnMap, &hydrateMode);
						zephir_check_call_status();
						break;
					} while(0);

					ZEPHIR_OBS_NVAR(&attribute);
					zephir_array_fetch_string(&attribute, &column, SL("balias"), PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 221);
				} else {
					ZEPHIR_OBS_NVAR(&sqlAlias);
					if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
						ZEPHIR_OBS_NVAR(&value);
						zephir_array_fetch(&value, &row, &sqlAlias, PH_NOISY, "phalcon/Mvc/Model/Resultset/Complex.zep", 227);
					} else {
						ZEPHIR_OBS_NVAR(&value);
						zephir_array_isset_fetch(&value, &row, &alias, 0);
					}
					if (zephir_array_isset_string(&column, SL("balias"))) {
						ZEPHIR_CPY_WRT(&attribute, &alias);
					} else {
						ZEPHIR_INIT_NVAR(&_32$$45);
						ZVAL_STRING(&_32$$45, "_");
						ZEPHIR_INIT_NVAR(&_33$$45);
						ZVAL_STRING(&_33$$45, "");
						ZEPHIR_INIT_NVAR(&attribute);
						zephir_fast_str_replace(&attribute, &_32$$45, &_33$$45, &alias);
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
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 92);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&current, this_ptr, "current", &_2, 480);
		zephir_check_call_status();
		zephir_array_append(&records, &current, PH_SEPARATE, "phalcon/Mvc/Model/Resultset/Complex.zep", 282);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector container is not valid", "phalcon/Mvc/Model/Resultset/Complex.zep", 303);
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
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 15, &data);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector container is not valid", "phalcon/Mvc/Model/Resultset/Complex.zep", 339);
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
		ZEPHIR_CALL_FUNCTION(&resultset, "unserialize", NULL, 16, data);
		zephir_check_call_status();
	}
	if (UNEXPECTED(Z_TYPE_P(&resultset) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data", "phalcon/Mvc/Model/Resultset/Complex.zep", 352);
		return;
	}
	zephir_array_fetch_string(&_4, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 355);
	zephir_update_property_zval(this_ptr, ZEND_STRL("rows"), &_4);
	zephir_array_fetch_string(&_5, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 356);
	ZVAL_UNDEF(&_6);
	ZVAL_LONG(&_6, zephir_fast_count_int(&_5));
	zephir_update_property_zval(this_ptr, ZEND_STRL("count"), &_6);
	zephir_array_fetch_string(&_7, &resultset, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 357);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cache"), &_7);
	zephir_array_fetch_string(&_8, &resultset, SL("columnTypes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 358);
	zephir_update_property_zval(this_ptr, ZEND_STRL("columnTypes"), &_8);
	zephir_array_fetch_string(&_9, &resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 359);
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
		Z_PARAM_ARRAY(data)
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
	zephir_array_fetch_string(&_0, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 390);
	zephir_update_property_zval(this_ptr, ZEND_STRL("rows"), &_0);
	zephir_array_fetch_string(&_1, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 391);
	ZVAL_UNDEF(&_2);
	ZVAL_LONG(&_2, zephir_fast_count_int(&_1));
	zephir_update_property_zval(this_ptr, ZEND_STRL("count"), &_2);
	zephir_array_fetch_string(&_3, &data, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 392);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cache"), &_3);
	zephir_array_fetch_string(&_4, &data, SL("columnTypes"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 393);
	zephir_update_property_zval(this_ptr, ZEND_STRL("columnTypes"), &_4);
	zephir_array_fetch_string(&_5, &data, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Complex.zep", 394);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hydrateMode"), &_5);
	ZEPHIR_MM_RESTORE();
}

