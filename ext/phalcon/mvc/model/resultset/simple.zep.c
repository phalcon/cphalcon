
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
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"
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

	zend_class_implements(phalcon_mvc_model_resultset_simple_ce TSRMLS_CC, 1, zend_ce_iterator);
	zend_class_implements(phalcon_mvc_model_resultset_simple_ce TSRMLS_CC, 1, spl_ce_SeekableIterator);
	zend_class_implements(phalcon_mvc_model_resultset_simple_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(phalcon_mvc_model_resultset_simple_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_mvc_model_resultset_simple_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Resultset\Simple constructor
 *
 * @param array columnMap
 * @param Phalcon\Mvc\ModelInterface|Phalcon\Mvc\Model\Row model
 * @param Phalcon\Db\Result\Pdo|null result
 * @param Phalcon\Cache\BackendInterface cache
 * @param boolean keepSnapshots
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *columnMap, *model, *result, *cache = NULL, *keepSnapshots = NULL, *rowCount = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &columnMap, &model, &result, &cache, &keepSnapshots);

	if (!cache) {
		cache = ZEPHIR_GLOBAL(global_null);
	}
	if (!keepSnapshots) {
		keepSnapshots = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("_model"), model TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_result"), result TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_columnMap"), columnMap TSRMLS_CC);
	if (Z_TYPE_P(result) != IS_OBJECT) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	ZEPHIR_CALL_METHOD(NULL, result, "setfetchmode", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&rowCount, result, "numrows", NULL);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(rowCount, 32)) {
		ZEPHIR_INIT_ZVAL_NREF(_1);
		ZVAL_LONG(_1, 1);
		zephir_update_property_this(this_ptr, SL("_type"), _1 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_1);
		ZVAL_LONG(_1, 0);
		zephir_update_property_this(this_ptr, SL("_type"), _1 TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("_count"), rowCount TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_keepSnapshots"), keepSnapshots TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns current row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, current) {

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *result, *row = NULL, *hydrateMode, *columnMap, *activeRow = NULL, *_0, *_1, *_2 = NULL, *_3, *_4, *_5, *_7;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(activeRow);
	zephir_read_property_this(&activeRow, this_ptr, SL("_activeRow"), PH_NOISY_CC);
	if (Z_TYPE_P(activeRow) != IS_NULL) {
		RETURN_CCTOR(activeRow);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_OBS_VAR(row);
		zephir_read_property_this(&row, this_ptr, SL("_row"), PH_NOISY_CC);
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(_1) == IS_NULL) {
			ZEPHIR_OBS_VAR(result);
			zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if (Z_TYPE_P(result) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&_2, result, "fetchall", NULL);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_rows"), _2 TSRMLS_CC);
			}
		}
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property_this(&_3, this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(_3) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(row);
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_rows"), PH_NOISY_CC);
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
			if (!(zephir_array_isset_fetch(&row, _4, _5, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(row);
				ZVAL_BOOL(row, 0);
			}
		} else {
			ZEPHIR_INIT_NVAR(row);
			ZVAL_BOOL(row, 0);
		}
	}
	if (Z_TYPE_P(row) != IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("_activeRow"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(hydrateMode);
	zephir_read_property_this(&hydrateMode, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(columnMap);
	zephir_read_property_this(&columnMap, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(hydrateMode, 0)) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_model"), PH_NOISY_CC);
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_keepSnapshots"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_7);
			ZVAL_LONG(_7, 0);
			ZEPHIR_CALL_CE_STATIC(&activeRow, phalcon_mvc_model_ce, "cloneresultmap", &_6, _1, row, columnMap, _7, _4);
			zephir_check_call_status();
			break;
		}
		ZEPHIR_CALL_CE_STATIC(&activeRow, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_8, row, columnMap, hydrateMode);
		zephir_check_call_status();
		break;
	} while(0);

	zephir_update_property_this(this_ptr, SL("_activeRow"), activeRow TSRMLS_CC);
	RETURN_CCTOR(activeRow);

}

/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than currently it does. Export the resultset to an array
 * couldn't be faster with a large number of records
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, toArray) {

	zephir_fcall_cache_entry *_10 = NULL;
	HashTable *_3, *_6;
	HashPosition _2, _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *renameColumns_param = NULL, *result = NULL, *records = NULL, *record = NULL, *renamed = NULL, *renamedKey = NULL, *key = NULL, *value = NULL, *renamedRecords, *columnMap, *_0, *_1, **_4, **_7, *_8 = NULL, *_9 = NULL;
	zend_bool renameColumns;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &renameColumns_param);

	if (!renameColumns_param) {
		renameColumns = 1;
	} else {
		renameColumns = zephir_get_boolval(renameColumns_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_OBS_VAR(result);
		zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		if (Z_TYPE_P(result) == IS_OBJECT) {
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("_row"), PH_NOISY_CC);
			if (Z_TYPE_P(_1) != IS_NULL) {
				ZEPHIR_CALL_METHOD(NULL, result, "execute", NULL);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&records, result, "fetchall", NULL);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_row"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(records);
			array_init(records);
		}
	} else {
		ZEPHIR_OBS_NVAR(records);
		zephir_read_property_this(&records, this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(records) != IS_ARRAY) {
			ZEPHIR_OBS_NVAR(result);
			zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if (Z_TYPE_P(result) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&records, result, "fetchall", NULL);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_rows"), records TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(records);
				array_init(records);
			}
		}
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
			zephir_is_iterable(records, &_3, &_2, 0, 0, "phalcon/mvc/model/resultset/simple.zep", 263);
			for (
			  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
			  ; zephir_hash_move_forward_ex(_3, &_2)
			) {
				ZEPHIR_GET_HVALUE(record, _4);
				ZEPHIR_INIT_NVAR(renamed);
				array_init(renamed);
				zephir_is_iterable(record, &_6, &_5, 0, 0, "phalcon/mvc/model/resultset/simple.zep", 261);
				for (
				  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
				  ; zephir_hash_move_forward_ex(_6, &_5)
				) {
					ZEPHIR_GET_HMKEY(key, _6, _5);
					ZEPHIR_GET_HVALUE(value, _7);
					ZEPHIR_OBS_NVAR(renamedKey);
					if (!(zephir_array_isset_fetch(&renamedKey, columnMap, key, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(_8);
						object_init_ex(_8, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_9);
						ZEPHIR_CONCAT_SVS(_9, "Column '", key, "' is not part of the column map");
						ZEPHIR_CALL_METHOD(NULL, _8, "__construct", &_10, _9);
						zephir_check_call_status();
						zephir_throw_exception_debug(_8, "phalcon/mvc/model/resultset/simple.zep", 249 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&renamed, renamedKey, &value, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&renamedRecords, renamed, PH_SEPARATE, "phalcon/mvc/model/resultset/simple.zep", 261);
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

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1 = NULL, *_2 = NULL, *_3;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 5, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_model"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("model"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_cache"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("cache"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_BOOL(_3, 0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "toarray", NULL, _3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("rows"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("columnMap"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("hydrateMode"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", &_4, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, unserialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *data_param = NULL, *resultset = NULL, *_0, *_2, *_3, *_4, *_5, *_6;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	if (unlikely(Z_TYPE_P(data_param) != IS_STRING && Z_TYPE_P(data_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(data_param) == IS_STRING)) {
		zephir_get_strval(data, data_param);
	} else {
		ZEPHIR_INIT_VAR(data);
		ZVAL_EMPTY_STRING(data);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("_type"), _0 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&resultset, "unserialize", &_1, data);
	zephir_check_call_status();
	if (Z_TYPE_P(resultset) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data", "phalcon/mvc/model/resultset/simple.zep", 302);
		return;
	}
	zephir_array_fetch_string(&_2, resultset, SL("model"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 305 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_model"), _2 TSRMLS_CC);
	zephir_array_fetch_string(&_3, resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 306 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_rows"), _3 TSRMLS_CC);
	zephir_array_fetch_string(&_4, resultset, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 307 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_cache"), _4 TSRMLS_CC);
	zephir_array_fetch_string(&_5, resultset, SL("columnMap"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 308 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_columnMap"), _5 TSRMLS_CC);
	zephir_array_fetch_string(&_6, resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/simple.zep", 309 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_hydrateMode"), _6 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

