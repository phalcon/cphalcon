
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
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
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
 * @param Phalcon\Mvc\ModelInterface model
 * @param Phalcon\Db\Result\Pdo result
 * @param Phalcon\Cache\BackendInterface cache
 * @param boolean keepSnapshots
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, __construct) {

	zval *columnMap, *model, *result, *cache = NULL, *keepSnapshots = NULL, *rowCount, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &columnMap, &model, &result, &cache, &keepSnapshots);

	if (!cache) {
		ZEPHIR_CPY_WRT(cache, ZEPHIR_GLOBAL(global_null));
	}
	if (!keepSnapshots) {
		ZEPHIR_CPY_WRT(keepSnapshots, ZEPHIR_GLOBAL(global_null));
	}


	zephir_update_property_this(this_ptr, SL("_model"), model TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_result"), result TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_columnMap"), columnMap TSRMLS_CC);
	if ((Z_TYPE_P(result) != IS_OBJECT)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 1);
	zephir_call_method_p1_noret(result, "setfetchmode", _0);
	ZEPHIR_INIT_VAR(rowCount);
	zephir_call_method(rowCount, result, "numrows");
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
 * Check whether internal resource has rows to fetch
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, valid) {

	zval *result = NULL, *row = NULL, *rows, *hydrateMode, *columnMap, *activeRow, *_0, *_1 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_OBS_VAR(result);
		zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(row);
		if ((Z_TYPE_P(result) == IS_OBJECT)) {
			zephir_call_method_p1(row, result, "fetch", result);
		} else {
			ZVAL_BOOL(row, 0);
		}
	} else {
		rows = zephir_fetch_nproperty_this(this_ptr, SL("_rows"), PH_NOISY_CC);
		if ((Z_TYPE_P(rows) != IS_ARRAY)) {
			ZEPHIR_OBS_NVAR(result);
			zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if ((Z_TYPE_P(result) == IS_OBJECT)) {
				ZEPHIR_INIT_VAR(_1);
				zephir_call_method(_1, result, "fetchall");
				zephir_update_property_this(this_ptr, SL("_rows"), _1 TSRMLS_CC);
			}
		}
		ZEPHIR_INIT_NVAR(row);
		if ((Z_TYPE_P(rows) == IS_ARRAY)) {
			Z_SET_ISREF_P(rows);
			zephir_call_func_p1(row, "current", rows);
			if (!ZEPHIR_IS_FALSE(row)) {
				Z_SET_ISREF_P(rows);
				zephir_call_func_p1_noret("next", rows);
			}
		} else {
			ZVAL_BOOL(row, 0);
		}
	}
	if ((Z_TYPE_P(row) != IS_ARRAY)) {
		zephir_update_property_this(this_ptr, SL("_activeRow"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	hydrateMode = zephir_fetch_nproperty_this(this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	columnMap = zephir_fetch_nproperty_this(this_ptr, SL("_columnMap"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(activeRow);
	if (ZEPHIR_IS_LONG(hydrateMode, 0)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_model"), PH_NOISY_CC);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_keepSnapshots"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 0);
		zephir_call_static_p5(activeRow, "Phalcon\\Mvc\\Model", "cloneresultmap", _2, row, columnMap, _1, _3);
	} else {
		zephir_call_static_p3(activeRow, "Phalcon\\Mvc\\Model", "cloneresultmaphydrate", row, columnMap, hydrateMode);
	}
	zephir_update_property_this(this_ptr, SL("_activeRow"), activeRow TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than currently it does. Export the resultset to an array
 * couldn't be faster with a large number of records
 *
 * @param boolean renameColumns
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, toArray) {

	zend_function *_11 = NULL;
	HashTable *_3, *_6;
	HashPosition _2, _5;
	zval *renameColumns_param = NULL, *result = NULL, *activeRow = NULL, *records = NULL, *record = NULL, *renamed = NULL, *renamedKey, *key = NULL, *value = NULL, *renamedRecords, *columnMap, *_0, *_1, **_4, **_7, *_8 = NULL, *_9 = NULL, *_10 = NULL;
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
		ZEPHIR_INIT_VAR(records);
		if ((Z_TYPE_P(result) == IS_OBJECT)) {
			ZEPHIR_OBS_VAR(activeRow);
			zephir_read_property_this(&activeRow, this_ptr, SL("_activeRow"), PH_NOISY_CC);
			if ((Z_TYPE_P(activeRow) != IS_NULL)) {
				zephir_call_method_noret(result, "execute");
			}
			zephir_call_method(records, result, "fetchall");
		} else {
			array_init(records);
		}
	} else {
		ZEPHIR_OBS_NVAR(records);
		zephir_read_property_this(&records, this_ptr, SL("_rows"), PH_NOISY_CC);
		if ((Z_TYPE_P(records) != IS_ARRAY)) {
			ZEPHIR_OBS_NVAR(result);
			zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if ((Z_TYPE_P(result) == IS_OBJECT)) {
				ZEPHIR_OBS_NVAR(activeRow);
				zephir_read_property_this(&activeRow, this_ptr, SL("_activeRow"), PH_NOISY_CC);
				if ((Z_TYPE_P(activeRow) != IS_NULL)) {
					zephir_call_method_noret(result, "execute");
				}
				ZEPHIR_INIT_NVAR(records);
				zephir_call_method(records, result, "fetchall");
				zephir_update_property_this(this_ptr, SL("_rows"), records TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_1);
				ZVAL_LONG(_1, zephir_fast_count_int(records TSRMLS_CC));
				zephir_update_property_this(this_ptr, SL("_count"), _1 TSRMLS_CC);
			}
		}
	}
	if (renameColumns) {
		columnMap = zephir_fetch_nproperty_this(this_ptr, SL("_columnMap"), PH_NOISY_CC);
		if ((Z_TYPE_P(columnMap) != IS_ARRAY)) {
			RETURN_CCTOR(records);
		}
		ZEPHIR_INIT_VAR(renamedRecords);
		array_init(renamedRecords);
		if ((Z_TYPE_P(records) == IS_ARRAY)) {
			zephir_is_iterable(records, &_3, &_2, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
				; zend_hash_move_forward_ex(_3, &_2)
			) {
				ZEPHIR_GET_HVALUE(record, _4);
				ZEPHIR_INIT_NVAR(renamed);
				array_init(renamed);
				zephir_is_iterable(record, &_6, &_5, 0, 0);
				for (
					; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
					; zend_hash_move_forward_ex(_6, &_5)
				) {
					ZEPHIR_GET_HMKEY(key, _6, _5);
					ZEPHIR_GET_HVALUE(value, _7);
					if (zephir_array_isset_fetch(&renamedKey, columnMap, key, 1 TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(_8);
						object_init_ex(_8, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_9);
						ZEPHIR_CONCAT_SV(_9, "Column '", key);
						ZEPHIR_INIT_LNVAR(_10);
						ZEPHIR_CONCAT_VS(_10, _9, "' is not part of the column map");
						zephir_call_method_p1_cache_noret(_8, "__construct", &_11, _10);
						zephir_throw_exception(_8 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_zval(&renamed, renamedKey, &value, PH_COPY | PH_SEPARATE);
				}
				zephir_array_append(&renamedRecords, renamed, PH_SEPARATE);
			}
		}
		RETURN_CCTOR(renamedRecords);
	}
	RETURN_CCTOR(records);

}

/**
 * Serializing a resultset will dump all related rows into a big array
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, serialize) {

	zval *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();

	zephir_update_property_this(this_ptr, SL("_activeRow"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_model"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("model"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_cache"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("cache"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_method_p1(_2, this_ptr, "toarray", ZEPHIR_GLOBAL(global_false));
	zephir_array_update_string(&_0, SL("rows"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_columnMap"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("columnMap"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("hydrateMode"), &_1, PH_COPY | PH_SEPARATE);
	zephir_call_func_p1(return_value, "serialize", _0);
	RETURN_MM();

}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 *
 * @param string data
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Simple, unserialize) {

	zval *data_param = NULL, *resultset, *_0, *_1, *_2, *_3, *_4;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

		zephir_get_strval(data, data_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("_type"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(resultset);
	zephir_call_func_p1(resultset, "unserialize", data);
	if ((Z_TYPE_P(resultset) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data");
		return;
	}
	zephir_array_fetch_string(&_0, resultset, SL("model"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_model"), _0 TSRMLS_CC);
	zephir_array_fetch_string(&_1, resultset, SL("rows"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_rows"), _1 TSRMLS_CC);
	zephir_array_fetch_string(&_2, resultset, SL("cache"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_cache"), _2 TSRMLS_CC);
	zephir_array_fetch_string(&_3, resultset, SL("columnMap"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_columnMap"), _3 TSRMLS_CC);
	zephir_array_fetch_string(&_4, resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_hydrateMode"), _4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

