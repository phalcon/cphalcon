
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/iterator.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Mvc\Model\Resultset\Complex
 *
 * Complex resultsets may include complete objects and scalar values.
 * This class builds every complex row as it is required
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Complex) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Resultset, Complex, phalcon, mvc_model_resultset_complex, phalcon_mvc_model_resultset_ce, phalcon_mvc_model_resultset_complex_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_resultset_complex_ce, SL("_columnTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_resultset_complex_ce TSRMLS_CC, 1, phalcon_mvc_model_resultsetinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Resultset\Complex constructor
 *
 * @param array columnTypes
 * @param Phalcon\Db\ResultInterface result
 * @param Phalcon\Cache\BackendInterface cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *columnTypes, *result, *cache = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &columnTypes, &result, &cache);

	if (!cache) {
		cache = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(this_ptr, SL("_columnTypes"), columnTypes TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_result"), result TSRMLS_CC);
	if (Z_TYPE_P(cache) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 1);
	zephir_update_property_this(this_ptr, SL("_type"), _0 TSRMLS_CC);
	if (Z_TYPE_P(result) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_LONG(_1, 1);
		ZEPHIR_CALL_METHOD(NULL, result, "setfetchmode", NULL, _1);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns current row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, current) {

	zephir_fcall_cache_entry *_13 = NULL, *_16 = NULL;
	HashTable *_7, *_10;
	HashPosition _6, _9;
	zend_bool _5;
	int dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval *result, *row = NULL, *underscore, *hydrateMode, *alias = NULL, *activeRow = NULL, *type = NULL, *columnTypes, *column = NULL, *columnValue = NULL, *value = NULL, *attribute = NULL, *source = NULL, *attributes = NULL, *columnMap = NULL, *rowModel = NULL, *keepSnapshots = NULL, *sqlAlias = NULL, *isPartial, *_0, *_1 = NULL, *_2, *_3, *_4, **_8, **_11, *_12 = NULL, *_14, *_15 = NULL, _17 = zval_used_for_init;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(activeRow);
	zephir_read_property_this(&activeRow, this_ptr, SL("_activeRow"), PH_NOISY_CC);
	if (Z_TYPE_P(activeRow) != IS_NULL) {
		RETURN_CCTOR(activeRow);
	}
	ZEPHIR_OBS_VAR(isPartial);
	zephir_read_property_this(&isPartial, this_ptr, SL("_type"), PH_NOISY_CC);
	if (zephir_is_true(isPartial)) {
		ZEPHIR_OBS_VAR(row);
		zephir_read_property_this(&row, this_ptr, SL("_row"), PH_NOISY_CC);
	} else {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_OBS_VAR(result);
			zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
			if (Z_TYPE_P(result) == IS_OBJECT) {
				ZEPHIR_CALL_METHOD(&_1, result, "fetchall", NULL);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_rows"), _1 TSRMLS_CC);
			}
		}
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property_this(&_2, this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(row);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_rows"), PH_NOISY_CC);
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_pointer"), PH_NOISY_CC);
			if (!(zephir_array_isset_fetch(&row, _3, _4, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(row);
				ZVAL_BOOL(row, 0);
			}
		} else {
			ZEPHIR_INIT_NVAR(row);
			ZVAL_BOOL(row, 0);
		}
	}
	_5 = Z_TYPE_P(row) != IS_OBJECT;
	if (_5) {
		_5 = Z_TYPE_P(row) != IS_ARRAY;
	}
	if (_5) {
		zephir_update_property_this(this_ptr, SL("_activeRow"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	if (!(zephir_is_true(isPartial))) {
		zephir_update_property_this(this_ptr, SL("_activeRow"), row TSRMLS_CC);
		RETURN_CCTOR(row);
	}
	ZEPHIR_OBS_VAR(hydrateMode);
	zephir_read_property_this(&hydrateMode, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(underscore);
	ZVAL_STRING(underscore, "_", 1);
	do {
		if (ZEPHIR_IS_LONG(hydrateMode, 0)) {
			ZEPHIR_INIT_NVAR(activeRow);
			object_init_ex(activeRow, phalcon_mvc_model_row_ce);
			if (zephir_has_constructor(activeRow TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, activeRow, "__construct", NULL);
				zephir_check_call_status();
			}
			break;
		}
		if (ZEPHIR_IS_LONG(hydrateMode, 1)) {
			ZEPHIR_INIT_NVAR(activeRow);
			array_init(activeRow);
			break;
		}
		ZEPHIR_INIT_NVAR(activeRow);
		object_init(activeRow);
		break;
	} while(0);

	ZEPHIR_OBS_VAR(columnTypes);
	zephir_read_property_this(&columnTypes, this_ptr, SL("_columnTypes"), PH_NOISY_CC);
	dirtyState = 0;
	zephir_is_iterable(columnTypes, &_7, &_6, 0, 0, "phalcon/mvc/model/resultset/complex.zep", 272);
	for (
	  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
	  ; zephir_hash_move_forward_ex(_7, &_6)
	) {
		ZEPHIR_GET_HMKEY(alias, _7, _6);
		ZEPHIR_GET_HVALUE(column, _8);
		if (Z_TYPE_P(column) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Column type is corrupt", "phalcon/mvc/model/resultset/complex.zep", 173);
			return;
		}
		ZEPHIR_OBS_NVAR(type);
		zephir_array_fetch_string(&type, column, SL("type"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 176 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(type, "object")) {
			ZEPHIR_OBS_NVAR(source);
			zephir_array_fetch_string(&source, column, SL("column"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 182 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(attributes);
			zephir_array_fetch_string(&attributes, column, SL("attributes"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 183 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(columnMap);
			zephir_array_fetch_string(&columnMap, column, SL("columnMap"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 184 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(rowModel);
			array_init(rowModel);
			zephir_is_iterable(attributes, &_10, &_9, 0, 0, "phalcon/mvc/model/resultset/complex.zep", 202);
			for (
			  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
			  ; zephir_hash_move_forward_ex(_10, &_9)
			) {
				ZEPHIR_GET_HVALUE(attribute, _11);
				ZEPHIR_OBS_NVAR(columnValue);
				ZEPHIR_INIT_LNVAR(_12);
				ZEPHIR_CONCAT_VVVV(_12, underscore, source, underscore, attribute);
				zephir_array_fetch(&columnValue, row, _12, PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 195 TSRMLS_CC);
				zephir_array_update_zval(&rowModel, attribute, &columnValue, PH_COPY | PH_SEPARATE);
			}
			do {
				if (ZEPHIR_IS_LONG(hydrateMode, 0)) {
					ZEPHIR_OBS_NVAR(keepSnapshots);
					if (!(zephir_array_isset_string_fetch(&keepSnapshots, column, SS("keepSnapshots"), 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(keepSnapshots);
						ZVAL_BOOL(keepSnapshots, 0);
					}
					zephir_array_fetch_string(&_14, column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 217 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, dirtyState);
					ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmap", &_13, _14, rowModel, columnMap, _15, keepSnapshots);
					zephir_check_call_status();
					break;
				}
				ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_16, rowModel, columnMap, hydrateMode);
				zephir_check_call_status();
				break;
			} while(0);

			ZEPHIR_OBS_NVAR(attribute);
			zephir_array_fetch_string(&attribute, column, SL("balias"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 231 TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(sqlAlias);
			if (zephir_array_isset_string_fetch(&sqlAlias, column, SS("sqlAlias"), 0 TSRMLS_CC)) {
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch(&value, row, sqlAlias, PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 239 TSRMLS_CC);
			} else {
				ZEPHIR_OBS_NVAR(value);
				zephir_array_isset_fetch(&value, row, alias, 0 TSRMLS_CC);
			}
			if (zephir_array_isset_string(column, SS("balias"))) {
				ZEPHIR_CPY_WRT(attribute, alias);
			} else {
				ZEPHIR_INIT_NVAR(attribute);
				ZEPHIR_SINIT_NVAR(_17);
				ZVAL_STRING(&_17, "", 0);
				zephir_fast_str_replace(&attribute, underscore, &_17, alias TSRMLS_CC);
			}
		}
		do {
			if (ZEPHIR_IS_LONG(hydrateMode, 1)) {
				zephir_array_update_zval(&activeRow, attribute, &value, PH_COPY | PH_SEPARATE);
				break;
			}
			zephir_update_property_zval_zval(activeRow, attribute, value TSRMLS_CC);
			break;
		} while(0);

	}
	zephir_update_property_this(this_ptr, SL("_activeRow"), activeRow TSRMLS_CC);
	RETURN_CCTOR(activeRow);

}

/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than currently it does.
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, toArray) {

	zend_object_iterator *_0;
	zval *records, *current = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(records);
	array_init(records);
	_0 = zephir_get_iterator(this_ptr TSRMLS_CC);
	_0->funcs->rewind(_0 TSRMLS_CC);
	for (;_0->funcs->valid(_0 TSRMLS_CC) == SUCCESS && !EG(exception); _0->funcs->move_forward(_0 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_0->funcs->get_current_data(_0, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(current, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		zephir_array_append(&records, current, PH_SEPARATE, "phalcon/mvc/model/resultset/complex.zep", 285);
	}
	_0->funcs->dtor(_0 TSRMLS_CC);
	RETURN_CCTOR(records);

}

/**
 * Serializing a resultset will dump all related rows into a big array
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, serialize) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *records = NULL, *cache, *columnTypes, *hydrateMode, *serialized = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&records, this_ptr, "toarray", NULL);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(cache);
	zephir_read_property_this(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(columnTypes);
	zephir_read_property_this(&columnTypes, this_ptr, SL("_columnTypes"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(hydrateMode);
	zephir_read_property_this(&hydrateMode, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("cache"), &cache, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("rows"), &records, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("columnTypes"), &columnTypes, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("hydrateMode"), &hydrateMode, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&serialized, "serialize", &_1, _0);
	zephir_check_call_status();
	if (Z_TYPE_P(serialized) != IS_STRING) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(serialized);

}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, unserialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *data_param = NULL, *resultset = NULL, *_0, *_2, *_3, *_4, *_5;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data", "phalcon/mvc/model/resultset/complex.zep", 339);
		return;
	}
	zephir_array_fetch_string(&_2, resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 342 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_rows"), _2 TSRMLS_CC);
	zephir_array_fetch_string(&_3, resultset, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 343 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_cache"), _3 TSRMLS_CC);
	zephir_array_fetch_string(&_4, resultset, SL("columnTypes"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 344 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_columnTypes"), _4 TSRMLS_CC);
	zephir_array_fetch_string(&_5, resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 345 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_hydrateMode"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

