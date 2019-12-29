
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
#include "kernel/concat.h"


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
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Simple) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Resultset, Simple, phalcon, mvc_model_resultset_simple, phalcon_mvc_model_resultset_ce, phalcon_mvc_model_resultset_simple_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_resultset_simple_ce, SL("columnMap"), ZEND_ACC_PROTECTED);

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
 * @param array                                             columnMap
 * @param \Phalcon\Mvc\ModelInterface|Phalcon\Mvc\Model\Row model
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &columnMap, &model, &result, &cache, &keepSnapshots_param);

	if (!cache) {
		cache = &cache_sub;
		cache = &__$null;
	}
	if (!keepSnapshots_param) {
		keepSnapshots = 0;
	} else {
		keepSnapshots = zephir_get_boolval(keepSnapshots_param);
	}


	zephir_update_property_zval(this_ptr, SL("model"), model);
	zephir_update_property_zval(this_ptr, SL("columnMap"), columnMap);
	if (keepSnapshots) {
		zephir_update_property_zval(this_ptr, SL("keepSnapshots"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("keepSnapshots"), &__$false);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_resultset_simple_ce, getThis(), "__construct", &_0, 0, result, cache);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns current row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, current) {

	zend_class_entry *_6$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, __$false, row, hydrateMode, columnMap, activeRow, modelName, _0, _1$$6, _3$$6, _4$$6, _5$$6, _2$$7, _8$$9, _9$$9, _10$$9;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&hydrateMode);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&activeRow);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$9);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("activeRow"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&activeRow, &_0);
	if (Z_TYPE_P(&activeRow) != IS_NULL) {
		RETURN_CCTOR(&activeRow);
	}
	zephir_read_property(&_0, this_ptr, SL("row"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&row, &_0);
	if (Z_TYPE_P(&row) != IS_ARRAY) {
		if (0) {
			zephir_update_property_zval(this_ptr, SL("activeRow"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("activeRow"), &__$false);
		}
		RETURN_MM_NULL();
	}
	zephir_read_property(&_0, this_ptr, SL("hydrateMode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&hydrateMode, &_0);
	zephir_read_property(&_0, this_ptr, SL("columnMap"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&columnMap, &_0);
	do {
		if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
			if (ZEPHIR_GLOBAL(orm).late_state_binding) {
				ZEPHIR_OBS_VAR(&_1$$6);
				zephir_read_property(&_1$$6, this_ptr, SL("model"), PH_NOISY_CC);
				if (zephir_instance_of_ev(&_1$$6, phalcon_mvc_model_ce)) {
					zephir_read_property(&_2$$7, this_ptr, SL("model"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_VAR(&modelName);
					zephir_get_class(&modelName, &_2$$7, 0);
				} else {
					ZEPHIR_INIT_NVAR(&modelName);
					ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
				}
				zephir_read_property(&_3$$6, this_ptr, SL("model"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_4$$6, this_ptr, SL("keepSnapshots"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_5$$6, 0);
				_6$$6 = zephir_fetch_class(&modelName);
				ZEPHIR_CALL_CE_STATIC(&activeRow, _6$$6, "cloneresultmap", NULL, 0, &_3$$6, &row, &columnMap, &_5$$6, &_4$$6);
				zephir_check_call_status();
			} else {
				zephir_read_property(&_8$$9, this_ptr, SL("model"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_9$$9, this_ptr, SL("keepSnapshots"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_10$$9, 0);
				ZEPHIR_CALL_CE_STATIC(&activeRow, phalcon_mvc_model_ce, "cloneresultmap", &_7, 0, &_8$$9, &row, &columnMap, &_10$$9, &_9$$9);
				zephir_check_call_status();
			}
			break;
		}
		ZEPHIR_CALL_CE_STATIC(&activeRow, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_11, 0, &row, &columnMap, &hydrateMode);
		zephir_check_call_status();
		break;
	} while(0);

	zephir_update_property_zval(this_ptr, SL("activeRow"), &activeRow);
	RETURN_CCTOR(&activeRow);

}

/**
 * Returns a complete resultset as an array, if the resultset has a big
 * number of rows it could consume more memory than currently it does.
 * Export the resultset to an array couldn't be faster with a large number
 * of records
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, toArray) {

	zend_string *_7$$8, *_20$$17;
	zend_ulong _6$$8, _19$$17;
	zval renamedRecords, renamed;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *renameColumns_param = NULL, __$null, result, records, record, renamedKey, key, value, columnMap, _0$$3, _1$$5, *_2$$7, _3$$7, *_4$$8, _5$$8, _8$$10, _9$$10, _11$$12, _12$$12, _13$$14, _14$$14, _15$$16, _16$$16, *_17$$17, _18$$17, _21$$19, _22$$19, _23$$21, _24$$21, _25$$23, _26$$23, _27$$25, _28$$25;
	zend_bool renameColumns;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&renamedKey);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_23$$21);
	ZVAL_UNDEF(&_24$$21);
	ZVAL_UNDEF(&_25$$23);
	ZVAL_UNDEF(&_26$$23);
	ZVAL_UNDEF(&_27$$25);
	ZVAL_UNDEF(&_28$$25);
	ZVAL_UNDEF(&renamedRecords);
	ZVAL_UNDEF(&renamed);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &renameColumns_param);

	if (!renameColumns_param) {
		renameColumns = 1;
	} else {
		renameColumns = zephir_get_boolval(renameColumns_param);
	}


	ZEPHIR_OBS_VAR(&records);
	zephir_read_property(&records, this_ptr, SL("rows"), PH_NOISY_CC);
	if (Z_TYPE_P(&records) != IS_ARRAY) {
		zephir_read_property(&_0$$3, this_ptr, SL("result"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&result, &_0$$3);
		zephir_read_property(&_0$$3, this_ptr, SL("row"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0$$3) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, &result, "execute", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&records, &result, "fetchall", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("row"), &__$null);
		zephir_update_property_zval(this_ptr, SL("rows"), &records);
	}
	if (renameColumns) {
		zephir_read_property(&_1$$5, this_ptr, SL("columnMap"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&columnMap, &_1$$5);
		if (Z_TYPE_P(&columnMap) != IS_ARRAY) {
			RETURN_CCTOR(&records);
		}
		ZEPHIR_INIT_VAR(&renamedRecords);
		array_init(&renamedRecords);
		if (Z_TYPE_P(&records) == IS_ARRAY) {
			zephir_is_iterable(&records, 0, "phalcon/Mvc/Model/Resultset/Simple.zep", 227);
			if (Z_TYPE_P(&records) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&records), _2$$7)
				{
					ZEPHIR_INIT_NVAR(&record);
					ZVAL_COPY(&record, _2$$7);
					ZEPHIR_INIT_NVAR(&renamed);
					array_init(&renamed);
					zephir_is_iterable(&record, 0, "phalcon/Mvc/Model/Resultset/Simple.zep", 225);
					if (Z_TYPE_P(&record) == IS_ARRAY) {
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&record), _6$$8, _7$$8, _4$$8)
						{
							ZEPHIR_INIT_NVAR(&key);
							if (_7$$8 != NULL) { 
								ZVAL_STR_COPY(&key, _7$$8);
							} else {
								ZVAL_LONG(&key, _6$$8);
							}
							ZEPHIR_INIT_NVAR(&value);
							ZVAL_COPY(&value, _4$$8);
							ZEPHIR_OBS_NVAR(&renamedKey);
							if (UNEXPECTED(!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0)))) {
								ZEPHIR_INIT_NVAR(&_8$$10);
								object_init_ex(&_8$$10, phalcon_mvc_model_exception_ce);
								ZEPHIR_INIT_NVAR(&_9$$10);
								ZEPHIR_CONCAT_SVS(&_9$$10, "Column '", &key, "' is not part of the column map");
								ZEPHIR_CALL_METHOD(NULL, &_8$$10, "__construct", &_10, 6, &_9$$10);
								zephir_check_call_status();
								zephir_throw_exception_debug(&_8$$10, "phalcon/Mvc/Model/Resultset/Simple.zep", 208);
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
								ZEPHIR_OBS_NVAR(&renamedKey);
								if (UNEXPECTED(!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0)))) {
									ZEPHIR_INIT_NVAR(&_11$$12);
									object_init_ex(&_11$$12, phalcon_mvc_model_exception_ce);
									ZEPHIR_INIT_NVAR(&_12$$12);
									ZEPHIR_CONCAT_SVS(&_12$$12, "Column '", &key, "' is not part of the column map");
									ZEPHIR_CALL_METHOD(NULL, &_11$$12, "__construct", &_10, 6, &_12$$12);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_11$$12, "phalcon/Mvc/Model/Resultset/Simple.zep", 215);
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
							zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &record, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_5$$8, &record, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_5$$8)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&key, &record, "key", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&value, &record, "current", NULL, 0);
							zephir_check_call_status();
								ZEPHIR_OBS_NVAR(&renamedKey);
								if (UNEXPECTED(!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0)))) {
									ZEPHIR_INIT_NVAR(&_13$$14);
									object_init_ex(&_13$$14, phalcon_mvc_model_exception_ce);
									ZEPHIR_INIT_NVAR(&_14$$14);
									ZEPHIR_CONCAT_SVS(&_14$$14, "Column '", &key, "' is not part of the column map");
									ZEPHIR_CALL_METHOD(NULL, &_13$$14, "__construct", &_10, 6, &_14$$14);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_13$$14, "phalcon/Mvc/Model/Resultset/Simple.zep", 208);
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
									ZEPHIR_OBS_NVAR(&renamedKey);
									if (UNEXPECTED(!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0)))) {
										ZEPHIR_INIT_NVAR(&_15$$16);
										object_init_ex(&_15$$16, phalcon_mvc_model_exception_ce);
										ZEPHIR_INIT_NVAR(&_16$$16);
										ZEPHIR_CONCAT_SVS(&_16$$16, "Column '", &key, "' is not part of the column map");
										ZEPHIR_CALL_METHOD(NULL, &_15$$16, "__construct", &_10, 6, &_16$$16);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_15$$16, "phalcon/Mvc/Model/Resultset/Simple.zep", 215);
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
								zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
							ZEPHIR_CALL_METHOD(NULL, &record, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&value);
					ZEPHIR_INIT_NVAR(&key);
					zephir_array_append(&renamedRecords, &renamed, PH_SEPARATE, "phalcon/Mvc/Model/Resultset/Simple.zep", 225);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &records, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_3$$7, &records, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_3$$7)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&record, &records, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&renamed);
						array_init(&renamed);
						zephir_is_iterable(&record, 0, "phalcon/Mvc/Model/Resultset/Simple.zep", 225);
						if (Z_TYPE_P(&record) == IS_ARRAY) {
							ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&record), _19$$17, _20$$17, _17$$17)
							{
								ZEPHIR_INIT_NVAR(&key);
								if (_20$$17 != NULL) { 
									ZVAL_STR_COPY(&key, _20$$17);
								} else {
									ZVAL_LONG(&key, _19$$17);
								}
								ZEPHIR_INIT_NVAR(&value);
								ZVAL_COPY(&value, _17$$17);
								ZEPHIR_OBS_NVAR(&renamedKey);
								if (UNEXPECTED(!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0)))) {
									ZEPHIR_INIT_NVAR(&_21$$19);
									object_init_ex(&_21$$19, phalcon_mvc_model_exception_ce);
									ZEPHIR_INIT_NVAR(&_22$$19);
									ZEPHIR_CONCAT_SVS(&_22$$19, "Column '", &key, "' is not part of the column map");
									ZEPHIR_CALL_METHOD(NULL, &_21$$19, "__construct", &_10, 6, &_22$$19);
									zephir_check_call_status();
									zephir_throw_exception_debug(&_21$$19, "phalcon/Mvc/Model/Resultset/Simple.zep", 208);
									ZEPHIR_MM_RESTORE();
									return;
								}
								if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
									ZEPHIR_OBS_NVAR(&renamedKey);
									if (UNEXPECTED(!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0)))) {
										ZEPHIR_INIT_NVAR(&_23$$21);
										object_init_ex(&_23$$21, phalcon_mvc_model_exception_ce);
										ZEPHIR_INIT_NVAR(&_24$$21);
										ZEPHIR_CONCAT_SVS(&_24$$21, "Column '", &key, "' is not part of the column map");
										ZEPHIR_CALL_METHOD(NULL, &_23$$21, "__construct", &_10, 6, &_24$$21);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_23$$21, "phalcon/Mvc/Model/Resultset/Simple.zep", 215);
										ZEPHIR_MM_RESTORE();
										return;
									}
								}
								zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &record, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_18$$17, &record, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_18$$17)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&key, &record, "key", NULL, 0);
								zephir_check_call_status();
								ZEPHIR_CALL_METHOD(&value, &record, "current", NULL, 0);
								zephir_check_call_status();
									ZEPHIR_OBS_NVAR(&renamedKey);
									if (UNEXPECTED(!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0)))) {
										ZEPHIR_INIT_NVAR(&_25$$23);
										object_init_ex(&_25$$23, phalcon_mvc_model_exception_ce);
										ZEPHIR_INIT_NVAR(&_26$$23);
										ZEPHIR_CONCAT_SVS(&_26$$23, "Column '", &key, "' is not part of the column map");
										ZEPHIR_CALL_METHOD(NULL, &_25$$23, "__construct", &_10, 6, &_26$$23);
										zephir_check_call_status();
										zephir_throw_exception_debug(&_25$$23, "phalcon/Mvc/Model/Resultset/Simple.zep", 208);
										ZEPHIR_MM_RESTORE();
										return;
									}
									if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
										ZEPHIR_OBS_NVAR(&renamedKey);
										if (UNEXPECTED(!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0)))) {
											ZEPHIR_INIT_NVAR(&_27$$25);
											object_init_ex(&_27$$25, phalcon_mvc_model_exception_ce);
											ZEPHIR_INIT_NVAR(&_28$$25);
											ZEPHIR_CONCAT_SVS(&_28$$25, "Column '", &key, "' is not part of the column map");
											ZEPHIR_CALL_METHOD(NULL, &_27$$25, "__construct", &_10, 6, &_28$$25);
											zephir_check_call_status();
											zephir_throw_exception_debug(&_27$$25, "phalcon/Mvc/Model/Resultset/Simple.zep", 215);
											ZEPHIR_MM_RESTORE();
											return;
										}
									}
									zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
								ZEPHIR_CALL_METHOD(NULL, &record, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&value);
						ZEPHIR_INIT_NVAR(&key);
						zephir_array_append(&renamedRecords, &renamed, PH_SEPARATE, "phalcon/Mvc/Model/Resultset/Simple.zep", 225);
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
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, serialize) {

	zval data;
	zval container, serializer, _1, _2, _3, _4, _5$$4, _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_ce, "getdefault", &_0, 0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector container is not valid", "phalcon/Mvc/Model/Resultset/Simple.zep", 248);
		return;
	}
	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 6, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("model"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("model"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("cache"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("cache"), &_1, PH_COPY | PH_SEPARATE);
	ZVAL_BOOL(&_3, 0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "toarray", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&data, SL("rows"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("columnMap"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("columnMap"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("hydrateMode"), PH_NOISY_CC);
	zephir_array_update_string(&data, SL("hydrateMode"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("keepSnapshots"), PH_NOISY_CC);
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
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 12, &data);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializing a resultset will allow to only works on the rows present in
 * the saved state
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, unserialize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data, data_sub, resultset, keepSnapshots, container, serializer, _1, _2, _5, _6, _7, _8, _9, _10, _11, _3$$4, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&keepSnapshots);
	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&serializer);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_CE_STATIC(&container, phalcon_di_ce, "getdefault", &_0, 0);
	zephir_check_call_status();
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The dependency injector container is not valid", "phalcon/Mvc/Model/Resultset/Simple.zep", 286);
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
		ZEPHIR_CALL_METHOD(&resultset, &serializer, "unserialize", NULL, 0, data);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&resultset, "unserialize", NULL, 14, data);
		zephir_check_call_status();
	}
	if (UNEXPECTED(Z_TYPE_P(&resultset) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data", "phalcon/Mvc/Model/Resultset/Simple.zep", 297);
		return;
	}
	zephir_array_fetch_string(&_5, &resultset, SL("model"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 300);
	zephir_update_property_zval(this_ptr, SL("model"), &_5);
	zephir_array_fetch_string(&_6, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 301);
	zephir_update_property_zval(this_ptr, SL("rows"), &_6);
	zephir_array_fetch_string(&_7, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 302);
	ZEPHIR_INIT_ZVAL_NREF(_8);
	ZVAL_LONG(&_8, zephir_fast_count_int(&_7));
	zephir_update_property_zval(this_ptr, SL("count"), &_8);
	zephir_array_fetch_string(&_9, &resultset, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 303);
	zephir_update_property_zval(this_ptr, SL("cache"), &_9);
	zephir_array_fetch_string(&_10, &resultset, SL("columnMap"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 304);
	zephir_update_property_zval(this_ptr, SL("columnMap"), &_10);
	zephir_array_fetch_string(&_11, &resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/Mvc/Model/Resultset/Simple.zep", 305);
	zephir_update_property_zval(this_ptr, SL("hydrateMode"), &_11);
	if (zephir_array_isset_string_fetch(&keepSnapshots, &resultset, SL("keepSnapshots"), 1)) {
		zephir_update_property_zval(this_ptr, SL("keepSnapshots"), &keepSnapshots);
	}
	ZEPHIR_MM_RESTORE();

}

