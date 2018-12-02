
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


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
 * @param \Phalcon\Db\Result\Pdo|null result
 * @param \Phalcon\Cache\BackendInterface cache
 * @param boolean keepSnapshots
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *columnMap, *model, *result, *cache = NULL, *keepSnapshots = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &columnMap, &model, &result, &cache, &keepSnapshots);

	if (!cache) {
		cache = ZEPHIR_GLOBAL(global_null);
	}
	if (!keepSnapshots) {
		keepSnapshots = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(getThis(), SL("_model"), model TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_columnMap"), columnMap TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_keepSnapshots"), keepSnapshots TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_resultset_simple_ce, getThis(), "__construct", &_0, 388, result, cache);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns current row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, current) {

	zend_class_entry *_5$$6;
	zval *row = NULL, *hydrateMode = NULL, *columnMap = NULL, *activeRow = NULL, *modelName = NULL, *_0$$6, *_2$$6, *_3$$6, *_4$$6, *_1$$7, *_7$$9, *_8$$9, *_9$$9;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(activeRow);
	zephir_read_property_this(&activeRow, this_ptr, SL("_activeRow"), PH_NOISY_CC);
	if (Z_TYPE_P(activeRow) != IS_NULL) {
		RETURN_CCTOR(activeRow);
	}
	ZEPHIR_OBS_VAR(row);
	zephir_read_property_this(&row, this_ptr, SL("_row"), PH_NOISY_CC);
	if (Z_TYPE_P(row) != IS_ARRAY) {
		if (0) {
			zephir_update_property_this(getThis(), SL("_activeRow"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_activeRow"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(hydrateMode);
	zephir_read_property_this(&hydrateMode, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(columnMap);
	zephir_read_property_this(&columnMap, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(hydrateMode, 0)) {
			if (ZEPHIR_GLOBAL(orm).late_state_binding) {
				ZEPHIR_OBS_VAR(_0$$6);
				zephir_read_property_this(&_0$$6, this_ptr, SL("_model"), PH_NOISY_CC);
				if (zephir_instance_of_ev(_0$$6, phalcon_mvc_model_ce TSRMLS_CC)) {
					_1$$7 = zephir_fetch_nproperty_this(this_ptr, SL("_model"), PH_NOISY_CC);
					ZEPHIR_INIT_VAR(modelName);
					zephir_get_class(modelName, _1$$7, 0 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(modelName);
					ZVAL_STRING(modelName, "Phalcon\\Mvc\\Model", 1);
				}
				_2$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_model"), PH_NOISY_CC);
				_3$$6 = zephir_fetch_nproperty_this(this_ptr, SL("_keepSnapshots"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_4$$6);
				ZVAL_LONG(_4$$6, 0);
				_5$$6 = zephir_fetch_class(modelName TSRMLS_CC);
				ZEPHIR_CALL_CE_STATIC(&activeRow, _5$$6, "cloneresultmap", NULL, 0, _2$$6, row, columnMap, _4$$6, _3$$6);
				zephir_check_call_status();
			} else {
				_7$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_model"), PH_NOISY_CC);
				_8$$9 = zephir_fetch_nproperty_this(this_ptr, SL("_keepSnapshots"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_9$$9);
				ZVAL_LONG(_9$$9, 0);
				ZEPHIR_CALL_CE_STATIC(&activeRow, phalcon_mvc_model_ce, "cloneresultmap", &_6, 390, _7$$9, row, columnMap, _9$$9, _8$$9);
				zephir_check_call_status();
			}
			break;
		}
		ZEPHIR_CALL_CE_STATIC(&activeRow, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_10, 391, row, columnMap, hydrateMode);
		zephir_check_call_status();
		break;
	} while(0);

	zephir_update_property_this(getThis(), SL("_activeRow"), activeRow TSRMLS_CC);
	RETURN_CCTOR(activeRow);

}

/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than currently it does. Export the resultset to an array
 * couldn't be faster with a large number of records
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, toArray) {

	HashTable *_2$$7, *_5$$8;
	HashPosition _1$$7, _4$$8;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *renameColumns_param = NULL, *result = NULL, *records = NULL, *record = NULL, *renamed = NULL, *renamedKey = NULL, *key = NULL, *value = NULL, *renamedRecords = NULL, *columnMap = NULL, *_0$$3, **_3$$7, **_6$$8, *_7$$10 = NULL, *_8$$10 = NULL, *_10$$12 = NULL, *_11$$12 = NULL;
	zend_bool renameColumns;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &renameColumns_param);

	if (!renameColumns_param) {
		renameColumns = 1;
	} else {
		renameColumns = zephir_get_boolval(renameColumns_param);
	}


	ZEPHIR_OBS_VAR(records);
	zephir_read_property_this(&records, this_ptr, SL("_rows"), PH_NOISY_CC);
	if (Z_TYPE_P(records) != IS_ARRAY) {
		ZEPHIR_OBS_VAR(result);
		zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_row"), PH_NOISY_CC);
		if (Z_TYPE_P(_0$$3) != IS_NULL) {
			ZEPHIR_CALL_METHOD(NULL, result, "execute", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&records, result, "fetchall", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("_row"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_rows"), records TSRMLS_CC);
	}
	if (renameColumns) {
		ZEPHIR_OBS_VAR(columnMap);
		zephir_read_property_this(&columnMap, this_ptr, SL("_columnMap"), PH_NOISY_CC);
		if (Z_TYPE_P(columnMap) != IS_ARRAY) {
			RETURN_CCTOR(records);
		}
		ZEPHIR_INIT_VAR(renamedRecords);
		array_init(renamedRecords);
		if (Z_TYPE_P(records) == IS_ARRAY) {
			zephir_is_iterable(records, &_2$$7, &_1$$7, 0, 0, "phalcon/mvc/model/resultset/simple.zep", 217);
			for (
			  ; zend_hash_get_current_data_ex(_2$$7, (void**) &_3$$7, &_1$$7) == SUCCESS
			  ; zend_hash_move_forward_ex(_2$$7, &_1$$7)
			) {
				ZEPHIR_GET_HVALUE(record, _3$$7);
				ZEPHIR_INIT_NVAR(renamed);
				array_init(renamed);
				zephir_is_iterable(record, &_5$$8, &_4$$8, 0, 0, "phalcon/mvc/model/resultset/simple.zep", 215);
				for (
				  ; zend_hash_get_current_data_ex(_5$$8, (void**) &_6$$8, &_4$$8) == SUCCESS
				  ; zend_hash_move_forward_ex(_5$$8, &_4$$8)
				) {
					ZEPHIR_GET_HMKEY(key, _5$$8, _4$$8);
					ZEPHIR_GET_HVALUE(value, _6$$8);
					ZEPHIR_OBS_NVAR(renamedKey);
					if (!(zephir_array_isset_fetch(&renamedKey, columnMap, key, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(_7$$10);
						object_init_ex(_7$$10, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_8$$10);
						ZEPHIR_CONCAT_SVS(_8$$10, "Column '", key, "' is not part of the column map");
						ZEPHIR_CALL_METHOD(NULL, _7$$10, "__construct", &_9, 9, _8$$10);
						zephir_check_call_status();
						zephir_throw_exception_debug(_7$$10, "phalcon/mvc/model/resultset/simple.zep", 199 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(renamedKey) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(renamedKey);
						if (!(zephir_array_isset_long_fetch(&renamedKey, renamedKey, 0, 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(_10$$12);
							object_init_ex(_10$$12, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_11$$12);
							ZEPHIR_CONCAT_SVS(_11$$12, "Column '", key, "' is not part of the column map");
							ZEPHIR_CALL_METHOD(NULL, _10$$12, "__construct", &_9, 9, _11$$12);
							zephir_check_call_status();
							zephir_throw_exception_debug(_10$$12, "phalcon/mvc/model/resultset/simple.zep", 205 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					zephir_array_update_zval(&renamed, renamedKey, &value, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&renamedRecords, renamed, PH_SEPARATE, "phalcon/mvc/model/resultset/simple.zep", 215);
			}
		}
		RETURN_CCTOR(renamedRecords);
	}
	RETURN_CCTOR(records);

}

/**
 * Serializing a resultset will dump all related rows into a big array
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, serialize) {

	zval *_1 = NULL, *_2 = NULL, *_3;
	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 6, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_model"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("model"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_cache"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("cache"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "toarray", NULL, 0, _3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("rows"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("columnMap"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("hydrateMode"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_keepSnapshots"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("keepSnapshots"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 68, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, unserialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, *resultset = NULL, *keepSnapshots = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_FUNCTION(&resultset, "unserialize", NULL, 69, data);
	zephir_check_call_status();
	if (Z_TYPE_P(resultset) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data", "phalcon/mvc/model/resultset/simple.zep", 252);
		return;
	}
	zephir_array_fetch_string(&_0, resultset, SL("model"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 255 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_model"), _0 TSRMLS_CC);
	zephir_array_fetch_string(&_1, resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 256 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_rows"), _1 TSRMLS_CC);
	zephir_array_fetch_string(&_2, resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 257 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_3);
	ZVAL_LONG(_3, zephir_fast_count_int(_2 TSRMLS_CC));
	zephir_update_property_this(getThis(), SL("_count"), _3 TSRMLS_CC);
	zephir_array_fetch_string(&_4, resultset, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 258 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_cache"), _4 TSRMLS_CC);
	zephir_array_fetch_string(&_5, resultset, SL("columnMap"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 259 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_columnMap"), _5 TSRMLS_CC);
	zephir_array_fetch_string(&_6, resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 260 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_hydrateMode"), _6 TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&keepSnapshots, resultset, SS("keepSnapshots"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_keepSnapshots"), keepSnapshots TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

