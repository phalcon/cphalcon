
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Resultset\Simple
 *
 * Simple resultsets only contains a complete objects
 * This class builds every complete object as it is required
 *
 * @template TKey of int
 * @template TValue of \Phalcon\Mvc\ModelInterface
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Simple)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Resultset, Simple, phalcon, mvc_model_resultset_simple, phalcon_mvc_model_resultset_ce, phalcon_mvc_model_resultset_simple_method_entry, 0);

	/**
	 * @var array|string
	 */
	zend_declare_property_null(phalcon_mvc_model_resultset_simple_ce, SL("columnMap"), ZEND_ACC_PROTECTED);
	/**
	 * @var ModelInterface|Row
	 */
	zend_declare_property_null(phalcon_mvc_model_resultset_simple_ce, SL("model"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_resultset_simple_ce, SL("keepSnapshots"), 0, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Resultset\Simple constructor
 *
 * @param array                             columnMap
 * @param ModelInterface|Row                model
 * @param \Phalcon\Db\ResultInterface|false result
 * @param mixed|null                        cache
 * @param bool keepSnapshots                false
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool keepSnapshots;
	zval *columnMap, columnMap_sub, *model, model_sub, *result, result_sub, *cache = NULL, cache_sub, *keepSnapshots_param = NULL, __$true, __$false, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&result_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 5)
		Z_PARAM_ZVAL(columnMap)
		Z_PARAM_ZVAL(model)
		Z_PARAM_ZVAL(result)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(cache)
		Z_PARAM_BOOL(keepSnapshots)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 2, &columnMap, &model, &result, &cache, &keepSnapshots_param);
	if (!cache) {
		cache = &cache_sub;
		cache = &__$null;
	}
	if (!keepSnapshots_param) {
		keepSnapshots = 0;
	} else {
		}
	zephir_update_property_zval(this_ptr, ZEND_STRL("model"), model);
	zephir_update_property_zval(this_ptr, ZEND_STRL("columnMap"), columnMap);
	if (keepSnapshots) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("keepSnapshots"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("keepSnapshots"), &__$false);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_resultset_simple_ce, getThis(), "__construct", NULL, 0, result, cache);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns current row in the resultset
 * @return TValue
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, current)
{
	zend_class_entry *_8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, __$false, row, hydrateMode, columnMap, activeRow, modelName, _0, _1$$5, _2$$5, _3$$6, _5$$6, _6$$6, _7$$6, _4$$7, _9$$9, _10$$9, _11$$9;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&hydrateMode);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&activeRow);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_11$$9);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("activeRow"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&activeRow, &_0);
	if (Z_TYPE_P(&activeRow) != IS_NULL) {
		RETURN_CCTOR(&activeRow);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("row"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&row, &_0);
	if (Z_TYPE_P(&row) != IS_ARRAY) {
		if (0) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("activeRow"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("activeRow"), &__$false);
		}
		RETURN_MM_NULL();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("hydrateMode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&hydrateMode, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("columnMap"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&columnMap, &_0);
	do {
		if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			ZVAL_STRING(&_2$$5, "orm.late_state_binding");
			ZEPHIR_CALL_CE_STATIC(&_1$$5, phalcon_support_settings_ce, "get", NULL, 0, &_2$$5);
			zephir_check_call_status();
			if (zephir_is_true(&_1$$5)) {
				zephir_memory_observe(&_3$$6);
				zephir_read_property(&_3$$6, this_ptr, ZEND_STRL("model"), PH_NOISY_CC);
				if (zephir_instance_of_ev(&_3$$6, phalcon_mvc_model_ce)) {
					zephir_read_property(&_4$$7, this_ptr, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_VAR(&modelName);
					zephir_get_class(&modelName, &_4$$7, 0);
				} else {
					ZEPHIR_INIT_NVAR(&modelName);
					ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
				}
				zephir_read_property(&_5$$6, this_ptr, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_6$$6, this_ptr, ZEND_STRL("keepSnapshots"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_7$$6, 0);
				_8$$6 = zephir_fetch_class(&modelName);
				ZEPHIR_CALL_CE_STATIC(&activeRow, _8$$6, "cloneresultmap", NULL, 0, &_5$$6, &row, &columnMap, &_7$$6, &_6$$6);
				zephir_check_call_status();
			} else {
				zephir_read_property(&_9$$9, this_ptr, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_10$$9, this_ptr, ZEND_STRL("keepSnapshots"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_11$$9, 0);
				ZEPHIR_CALL_CE_STATIC(&activeRow, phalcon_mvc_model_ce, "cloneresultmap", NULL, 0, &_9$$9, &row, &columnMap, &_11$$9, &_10$$9);
				zephir_check_call_status();
			}
			break;
		}
		ZEPHIR_CALL_CE_STATIC(&activeRow, phalcon_mvc_model_ce, "cloneresultmaphydrate", NULL, 0, &row, &columnMap, &hydrateMode);
		zephir_check_call_status();
		break;
	} while(0);

	zephir_update_property_zval(this_ptr, ZEND_STRL("activeRow"), &activeRow);
	RETURN_CCTOR(&activeRow);
}

/**
 * Returns a complete resultset as an array, if the resultset has a big
 * number of rows it could consume more memory than currently it does.
 * Export the resultset to an array couldn't be faster with a large number
 * of records
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, toArray)
{
	zend_string *_9$$8, *_18$$19;
	zend_ulong _8$$8, _17$$19;
	zval renamedRecords, renamed;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *renameColumns_param = NULL, __$null, result, records, record, renamedKey, key, value, columnMap, _2, _0$$3, _3$$5, *_4$$7, _5$$7, *_6$$8, _7$$8, _10$$11, _12$$13, _13$$16, _14$$18, *_15$$19, _16$$19, _19$$22, _20$$24, _21$$27, _22$$29;
	zend_bool renameColumns, _1;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&renamedKey);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_12$$13);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_14$$18);
	ZVAL_UNDEF(&_16$$19);
	ZVAL_UNDEF(&_19$$22);
	ZVAL_UNDEF(&_20$$24);
	ZVAL_UNDEF(&_21$$27);
	ZVAL_UNDEF(&_22$$29);
	ZVAL_UNDEF(&renamedRecords);
	ZVAL_UNDEF(&renamed);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(renameColumns)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &renameColumns_param);
	if (!renameColumns_param) {
		renameColumns = 1;
	} else {
		}
	zephir_memory_observe(&records);
	zephir_read_property(&records, this_ptr, ZEND_STRL("rows"), PH_NOISY_CC);
	if (Z_TYPE_P(&records) != IS_ARRAY) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("result"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&result, &_0$$3);
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("row"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0$$3) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, &result, "execute", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&records, &result, "fetchall", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("row"), &__$null);
		zephir_update_property_zval(this_ptr, ZEND_STRL("rows"), &records);
	}
	_1 = renameColumns;
	if (_1) {
		zephir_memory_observe(&_2);
		zephir_read_property(&_2, this_ptr, ZEND_STRL("model"), PH_NOISY_CC);
		_1 = !(zephir_instance_of_ev(&_2, phalcon_mvc_model_row_ce));
	}
	if (_1) {
		zephir_read_property(&_3$$5, this_ptr, ZEND_STRL("columnMap"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&columnMap, &_3$$5);
		if (Z_TYPE_P(&columnMap) != IS_ARRAY) {
			RETURN_CCTOR(&records);
		}
		ZEPHIR_INIT_VAR(&renamedRecords);
		array_init(&renamedRecords);
		if (Z_TYPE_P(&records) == IS_ARRAY) {
			zephir_is_iterable(&records, 0, "phalcon/Mvc/Model/Resultset/Simple.zep", 246);
			if (Z_TYPE_P(&records) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&records), _4$$7)
				{
					ZEPHIR_INIT_NVAR(&record);
					ZVAL_COPY(&record, _4$$7);
					ZEPHIR_INIT_NVAR(&renamed);
					array_init(&renamed);
					zephir_is_iterable(&record, 0, "phalcon/Mvc/Model/Resultset/Simple.zep", 244);
					if (Z_TYPE_P(&record) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&record), _8$$8, _9$$8, _6$$8)
						{
							ZEPHIR_INIT_NVAR(&key);
							if (_9$$8 != NULL) { 
								ZVAL_STR_COPY(&key, _9$$8);
							} else {
								ZVAL_LONG(&key, _8$$8);
							}
							ZEPHIR_INIT_NVAR(&value);
							ZVAL_COPY(&value, _6$$8);
							if (Z_TYPE_P(&key) == IS_STRING) {
								ZEPHIR_OBS_NVAR(&renamedKey);
								if (UNEXPECTED(!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0)))) {
									ZEPHIR_INIT_NVAR(&_10$$11);
									object_init_ex(&_10$$11, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
									ZEPHIR_CALL_METHOD(NULL, &_10$$11, "__construct", &_11, 0, &key);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_10$$11, "phalcon/Mvc/Model/Resultset/Simple.zep", 228);
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
									ZEPHIR_OBS_NVAR(&renamedKey);
									if (UNEXPECTED(!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0)))) {
										ZEPHIR_INIT_NVAR(&_12$$13);
										object_init_ex(&_12$$13, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
										ZEPHIR_CALL_METHOD(NULL, &_12$$13, "__construct", &_11, 0, &key);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_12$$13, "phalcon/Mvc/Model/Resultset/Simple.zep", 233);
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
								zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &record, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_7$$8, &record, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_7$$8)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&key, &record, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&value, &record, "current", NULL, 0);
							zephir_check_call_status();
								if (Z_TYPE_P(&key) == IS_STRING) {
									ZEPHIR_OBS_NVAR(&renamedKey);
									if (UNEXPECTED(!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0)))) {
										ZEPHIR_INIT_NVAR(&_13$$16);
										object_init_ex(&_13$$16, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
										ZEPHIR_CALL_METHOD(NULL, &_13$$16, "__construct", &_11, 0, &key);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_13$$16, "phalcon/Mvc/Model/Resultset/Simple.zep", 228);
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&renamedKey);
										if (UNEXPECTED(!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0)))) {
											ZEPHIR_INIT_NVAR(&_14$$18);
											object_init_ex(&_14$$18, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
											ZEPHIR_CALL_METHOD(NULL, &_14$$18, "__construct", &_11, 0, &key);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_14$$18, "phalcon/Mvc/Model/Resultset/Simple.zep", 233);
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
									zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
								}
							ZEPHIR_CALL_METHOD(NULL, &record, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&value);
					ZEPHIR_INIT_NVAR(&key);
					zephir_array_append(&renamedRecords, &renamed, PH_SEPARATE, "phalcon/Mvc/Model/Resultset/Simple.zep", 244);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &records, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_5$$7, &records, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_5$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&record, &records, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&renamed);
						array_init(&renamed);
						zephir_is_iterable(&record, 0, "phalcon/Mvc/Model/Resultset/Simple.zep", 244);
						if (Z_TYPE_P(&record) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&record), _17$$19, _18$$19, _15$$19)
							{
								ZEPHIR_INIT_NVAR(&key);
								if (_18$$19 != NULL) { 
									ZVAL_STR_COPY(&key, _18$$19);
								} else {
									ZVAL_LONG(&key, _17$$19);
								}
								ZEPHIR_INIT_NVAR(&value);
								ZVAL_COPY(&value, _15$$19);
								if (Z_TYPE_P(&key) == IS_STRING) {
									ZEPHIR_OBS_NVAR(&renamedKey);
									if (UNEXPECTED(!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0)))) {
										ZEPHIR_INIT_NVAR(&_19$$22);
										object_init_ex(&_19$$22, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
										ZEPHIR_CALL_METHOD(NULL, &_19$$22, "__construct", &_11, 0, &key);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_19$$22, "phalcon/Mvc/Model/Resultset/Simple.zep", 228);
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&renamedKey);
										if (UNEXPECTED(!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0)))) {
											ZEPHIR_INIT_NVAR(&_20$$24);
											object_init_ex(&_20$$24, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
											ZEPHIR_CALL_METHOD(NULL, &_20$$24, "__construct", &_11, 0, &key);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_20$$24, "phalcon/Mvc/Model/Resultset/Simple.zep", 233);
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
									zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &record, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_16$$19, &record, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_16$$19)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&key, &record, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&value, &record, "current", NULL, 0);
								zephir_check_call_status();
									if (Z_TYPE_P(&key) == IS_STRING) {
										ZEPHIR_OBS_NVAR(&renamedKey);
										if (UNEXPECTED(!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0)))) {
											ZEPHIR_INIT_NVAR(&_21$$27);
											object_init_ex(&_21$$27, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
											ZEPHIR_CALL_METHOD(NULL, &_21$$27, "__construct", &_11, 0, &key);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_21$$27, "phalcon/Mvc/Model/Resultset/Simple.zep", 228);
											ZEPHIR_MM_RESTORE();
											return;
										}
										if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
											ZEPHIR_OBS_NVAR(&renamedKey);
											if (UNEXPECTED(!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0)))) {
												ZEPHIR_INIT_NVAR(&_22$$29);
												object_init_ex(&_22$$29, phalcon_mvc_model_exceptions_resultsetcolumnnotinmap_ce);
												ZEPHIR_CALL_METHOD(NULL, &_22$$29, "__construct", &_11, 0, &key);
												zephir_check_call_status();
												zephir_throw_exception_debug(&_22$$29, "phalcon/Mvc/Model/Resultset/Simple.zep", 233);
												ZEPHIR_MM_RESTORE();
												return;
											}
										}
										zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
									}
								ZEPHIR_CALL_METHOD(NULL, &record, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&value);
						ZEPHIR_INIT_NVAR(&key);
						zephir_array_append(&renamedRecords, &renamed, PH_SEPARATE, "phalcon/Mvc/Model/Resultset/Simple.zep", 244);
					ZEPHIR_CALL_METHOD(NULL, &records, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&record);
		}
		RETURN_CTOR(&renamedRecords);
	}
	RETURN_CCTOR(&records);
}

/**
 * Serializing a resultset will dump all related rows into a big array
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, serialize)
{
	zval data;
	zval container, serializer, _1, _2, _3, _4, _0$$3, _5$$4, _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
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
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Resultset/Simple.zep", 264);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 6, 0);
	zephir_memory_observe(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("model"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("model"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("cache"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("cache"), &_1, PH_COPY | PH_SEPARATE);
	ZVAL_BOOL(&_3, 0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "toarray", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("rows"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("columnMap"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("columnMap"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("hydrateMode"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("hydrateMode"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("keepSnapshots"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("keepSnapshots"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "serializer");
	ZEPHIR_CALL_METHOD(&_2, &container, "has", NULL, 0, &_4);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "serializer");
		ZEPHIR_CALL_METHOD(&_5$$4, &container, "getshared", NULL, 0, &_6$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&serializer, &_5$$4);
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
 * Unserializing a resultset will allow to only works on the rows present in
 * the saved state
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, unserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, resultset, keepSnapshots, container, serializer, _1, _2, _6, _7, _8, _9, _10, _11, _12, _0$$3, _3$$4, _4$$4, _5$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&keepSnapshots);
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
	ZVAL_UNDEF(&_12);
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
	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_di_ce, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&container) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_mvc_model_exceptions_invalidcontainer_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Mvc/Model/Resultset/Simple.zep", 299);
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
		zephir_throw_exception_debug(&_5$$6, "phalcon/Mvc/Model/Resultset/Simple.zep", 312);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&_6, &resultset, SL("model"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 315);
	zephir_update_property_zval(this_ptr, ZEND_STRL("model"), &_6);
	zephir_array_fetch_string(&_7, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 316);
	zephir_update_property_zval(this_ptr, ZEND_STRL("rows"), &_7);
	zephir_array_fetch_string(&_8, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 317);
	ZVAL_UNDEF(&_9);
	ZVAL_LONG(&_9, zephir_fast_count_int(&_8));
	zephir_update_property_zval(this_ptr, ZEND_STRL("count"), &_9);
	zephir_array_fetch_string(&_10, &resultset, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 318);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cache"), &_10);
	zephir_array_fetch_string(&_11, &resultset, SL("columnMap"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 319);
	zephir_update_property_zval(this_ptr, ZEND_STRL("columnMap"), &_11);
	zephir_array_fetch_string(&_12, &resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 320);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hydrateMode"), &_12);
	if (zephir_array_isset_string_fetch(&keepSnapshots, &resultset, SL("keepSnapshots"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("keepSnapshots"), &keepSnapshots);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __serialize)
{
	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_create_array(return_value, 6, 0);
	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("model"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("model"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("cache"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("cache"), &_0, PH_COPY | PH_SEPARATE);
	ZVAL_BOOL(&_2, 0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "toarray", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("rows"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("columnMap"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("columnMap"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("hydrateMode"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("hydrateMode"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("keepSnapshots"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("keepSnapshots"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __unserialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL, keepSnapshots, _0, _1, _2, _3, _4, _5, _6;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&keepSnapshots);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_arrval(&data, data_param);
	zephir_array_fetch_string(&_0, &data, SL("model"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 343);
	zephir_update_property_zval(this_ptr, ZEND_STRL("model"), &_0);
	zephir_array_fetch_string(&_1, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 344);
	zephir_update_property_zval(this_ptr, ZEND_STRL("rows"), &_1);
	zephir_array_fetch_string(&_2, &data, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 345);
	ZVAL_UNDEF(&_3);
	ZVAL_LONG(&_3, zephir_fast_count_int(&_2));
	zephir_update_property_zval(this_ptr, ZEND_STRL("count"), &_3);
	zephir_array_fetch_string(&_4, &data, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 346);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cache"), &_4);
	zephir_array_fetch_string(&_5, &data, SL("columnMap"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 347);
	zephir_update_property_zval(this_ptr, ZEND_STRL("columnMap"), &_5);
	zephir_array_fetch_string(&_6, &data, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 348);
	zephir_update_property_zval(this_ptr, ZEND_STRL("hydrateMode"), &_6);
	if (zephir_array_isset_string_fetch(&keepSnapshots, &data, SL("keepSnapshots"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("keepSnapshots"), &keepSnapshots);
	}
	ZEPHIR_MM_RESTORE();
}

