
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
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Mvc\Model\Resultset\Simple
 *
 * Simple resultsets only contains a complete objects
 * This class builds every complete object as it is required
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Simple) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Resultset, Simple, phalcon, mvc_model_resultset_simple, phalcon_mvc_model_resultset_ce, phalcon_mvc_model_resultset_simple_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_resultset_simple_ce, SL("_model"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_resultset_simple_ce, SL("_columnMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_mvc_model_resultset_simple_ce, SL("_keepSnapshots"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Resultset\Simple constructor
 *
 * @param array columnMap
 * @param \Phalcon\Mvc\ModelInterface|Phalcon\Mvc\Model\Row model
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __construct) {

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


	zephir_update_property_zval(this_ptr, SL("_model"), model);
	zephir_update_property_zval(this_ptr, SL("_columnMap"), columnMap);
	if (keepSnapshots) {
		zephir_update_property_zval(this_ptr, SL("_keepSnapshots"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_keepSnapshots"), &__$false);
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_resultset_simple_ce, getThis(), "__construct", &_0, 0, result, cache);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns current row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, current) {

	zend_class_entry *_5$$6;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, __$false, row, hydrateMode, columnMap, activeRow, modelName, _0$$6, _2$$6, _3$$6, _4$$6, _1$$7, _7$$9, _8$$9, _9$$9;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&hydrateMode);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&activeRow);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&activeRow);
	zephir_read_property(&activeRow, this_ptr, SL("_activeRow"), PH_NOISY_CC);
	if (Z_TYPE_P(&activeRow) != IS_NULL) {
		RETURN_CCTOR(&activeRow);
	}
	ZEPHIR_OBS_VAR(&row);
	zephir_read_property(&row, this_ptr, SL("_row"), PH_NOISY_CC);
	if (Z_TYPE_P(&row) != IS_ARRAY) {
		if (0) {
			zephir_update_property_zval(this_ptr, SL("_activeRow"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_activeRow"), &__$false);
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(&hydrateMode);
	zephir_read_property(&hydrateMode, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&columnMap);
	zephir_read_property(&columnMap, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
			if (ZEPHIR_GLOBAL(orm).late_state_binding) {
				ZEPHIR_OBS_VAR(&_0$$6);
				zephir_read_property(&_0$$6, this_ptr, SL("_model"), PH_NOISY_CC);
				if (zephir_instance_of_ev(&_0$$6, phalcon_mvc_model_ce TSRMLS_CC)) {
					zephir_read_property(&_1$$7, this_ptr, SL("_model"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_VAR(&modelName);
					zephir_get_class(&modelName, &_1$$7, 0 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(&modelName);
					ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
				}
				zephir_read_property(&_2$$6, this_ptr, SL("_model"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_3$$6, this_ptr, SL("_keepSnapshots"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_4$$6, 0);
				_5$$6 = zephir_fetch_class(&modelName TSRMLS_CC);
				ZEPHIR_CALL_CE_STATIC(&activeRow, _5$$6, "cloneresultmap", NULL, 0, &_2$$6, &row, &columnMap, &_4$$6, &_3$$6);
				zephir_check_call_status();
			} else {
				zephir_read_property(&_7$$9, this_ptr, SL("_model"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_8$$9, this_ptr, SL("_keepSnapshots"), PH_NOISY_CC | PH_READONLY);
				ZVAL_LONG(&_9$$9, 0);
				ZEPHIR_CALL_CE_STATIC(&activeRow, phalcon_mvc_model_ce, "cloneresultmap", &_6, 0, &_7$$9, &row, &columnMap, &_9$$9, &_8$$9);
				zephir_check_call_status();
			}
			break;
		}
		ZEPHIR_CALL_CE_STATIC(&activeRow, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_10, 0, &row, &columnMap, &hydrateMode);
		zephir_check_call_status();
		break;
	} while(0);

	zephir_update_property_zval(this_ptr, SL("_activeRow"), &activeRow);
	RETURN_CCTOR(&activeRow);

}

/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than currently it does. Export the resultset to an array
 * couldn't be faster with a large number of records
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, toArray) {

	zend_string *_4$$8;
	zend_ulong _3$$8;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *renameColumns_param = NULL, __$null, result, records, record, renamed, renamedKey, key, value, renamedRecords, columnMap, _0$$3, *_1$$7, *_2$$8, _5$$10, _6$$10, _8$$12, _9$$12;
	zend_bool renameColumns;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&renamed);
	ZVAL_UNDEF(&renamedKey);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&renamedRecords);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_9$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &renameColumns_param);

	if (!renameColumns_param) {
		renameColumns = 1;
	} else {
		renameColumns = zephir_get_boolval(renameColumns_param);
	}


	ZEPHIR_OBS_VAR(&records);
	zephir_read_property(&records, this_ptr, SL("_rows"), PH_NOISY_CC);
	if (Z_TYPE_P(&records) != IS_ARRAY) {
		ZEPHIR_OBS_VAR(&result);
		zephir_read_property(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		zephir_read_property(&_0$$3, this_ptr, SL("_row"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0$$3) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, &result, "execute", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&records, &result, "fetchall", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_row"), &__$null);
		zephir_update_property_zval(this_ptr, SL("_rows"), &records);
	}
	if (renameColumns) {
		ZEPHIR_OBS_VAR(&columnMap);
		zephir_read_property(&columnMap, this_ptr, SL("_columnMap"), PH_NOISY_CC);
		if (Z_TYPE_P(&columnMap) != IS_ARRAY) {
			RETURN_CCTOR(&records);
		}
		ZEPHIR_INIT_VAR(&renamedRecords);
		array_init(&renamedRecords);
		if (Z_TYPE_P(&records) == IS_ARRAY) {
			zephir_is_iterable(&records, 0, "phalcon/mvc/model/resultset/simple.zep", 214);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&records), _1$$7)
			{
				ZEPHIR_INIT_NVAR(&record);
				ZVAL_COPY(&record, _1$$7);
				ZEPHIR_INIT_NVAR(&renamed);
				array_init(&renamed);
				zephir_is_iterable(&record, 0, "phalcon/mvc/model/resultset/simple.zep", 212);
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&record), _3$$8, _4$$8, _2$$8)
				{
					ZEPHIR_INIT_NVAR(&key);
					if (_4$$8 != NULL) { 
						ZVAL_STR_COPY(&key, _4$$8);
					} else {
						ZVAL_LONG(&key, _3$$8);
					}
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _2$$8);
					ZEPHIR_OBS_NVAR(&renamedKey);
					if (!(zephir_array_isset_fetch(&renamedKey, &columnMap, &key, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(&_5$$10);
						object_init_ex(&_5$$10, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_6$$10);
						ZEPHIR_CONCAT_SVS(&_6$$10, "Column '", &key, "' is not part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_5$$10, "__construct", &_7, 4, &_6$$10);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_5$$10, "phalcon/mvc/model/resultset/simple.zep", 196 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&renamedKey) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&renamedKey);
						if (!(zephir_array_isset_long_fetch(&renamedKey, &renamedKey, 0, 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_8$$12);
							object_init_ex(&_8$$12, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_9$$12);
							ZEPHIR_CONCAT_SVS(&_9$$12, "Column '", &key, "' is not part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_8$$12, "__construct", &_7, 4, &_9$$12);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_8$$12, "phalcon/mvc/model/resultset/simple.zep", 202 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					zephir_array_update_zval(&renamed, &renamedKey, &value, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&value);
				ZEPHIR_INIT_NVAR(&key);
				zephir_array_append(&renamedRecords, &renamed, PH_SEPARATE, "phalcon/mvc/model/resultset/simple.zep", 212);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&record);
		}
		RETURN_CCTOR(&renamedRecords);
	}
	RETURN_CCTOR(&records);

}

/**
 * Serializing a resultset will dump all related rows into a big array
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, serialize) {

	zval _1, _2, _3;
	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 6, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("_model"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("model"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("_cache"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("cache"), &_1, PH_COPY | PH_SEPARATE);
	ZVAL_BOOL(&_3, 0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "toarray", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("rows"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("columnMap"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("hydrateMode"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("_keepSnapshots"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("keepSnapshots"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 60, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, unserialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, resultset, keepSnapshots, _0, _1, _2, _3, _4, _5, _6;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&keepSnapshots);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	if (UNEXPECTED(Z_TYPE_P(data_param) != IS_STRING && Z_TYPE_P(data_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(data_param) == IS_STRING)) {
		zephir_get_strval(&data, data_param);
	} else {
		ZEPHIR_INIT_VAR(&data);
		ZVAL_EMPTY_STRING(&data);
	}


	ZEPHIR_CALL_FUNCTION(&resultset, "unserialize", NULL, 61, &data);
	zephir_check_call_status();
	if (Z_TYPE_P(&resultset) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data", "phalcon/mvc/model/resultset/simple.zep", 249);
		return;
	}
	zephir_array_fetch_string(&_0, &resultset, SL("model"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 252 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_model"), &_0);
	zephir_array_fetch_string(&_1, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 253 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_rows"), &_1);
	zephir_array_fetch_string(&_2, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 254 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_LONG(&_3, zephir_fast_count_int(&_2 TSRMLS_CC));
	zephir_update_property_zval(this_ptr, SL("_count"), &_3);
	zephir_array_fetch_string(&_4, &resultset, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 255 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_cache"), &_4);
	zephir_array_fetch_string(&_5, &resultset, SL("columnMap"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 256 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_columnMap"), &_5);
	zephir_array_fetch_string(&_6, &resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 257 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_hydrateMode"), &_6);
	if (zephir_array_isset_string_fetch(&keepSnapshots, &resultset, SL("keepSnapshots"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_keepSnapshots"), &keepSnapshots);
	}
	ZEPHIR_MM_RESTORE();

}

