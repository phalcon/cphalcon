
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
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/iterator.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
	zend_bool _0;
	zval *columnTypes, *result, *cache = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &columnTypes, &result, &cache);

	if (!cache) {
		cache = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_instance_of_ev(result, phalcon_db_resultinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'result' must be an instance of 'Phalcon\\Db\\ResultInterface'", "", 0);
		return;
	}
	_0 = Z_TYPE_P(cache) != IS_NULL;
	if (_0) {
		_0 = !zephir_instance_of_ev(cache, phalcon_cache_backendinterface_ce TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'cache' must be an instance of 'Phalcon\\Cache\\BackendInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_columnTypes"), columnTypes TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_result"), result TSRMLS_CC);
	if (Z_TYPE_P(cache) != IS_NULL) {
		zephir_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
	}
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, 1);
	zephir_update_property_this(this_ptr, SL("_type"), _1 TSRMLS_CC);
	if (Z_TYPE_P(result) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 1);
		ZEPHIR_CALL_METHOD(NULL, result, "setfetchmode", NULL, _2);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether internal resource has rows to fetch
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, valid) {

	zephir_fcall_cache_entry *_11 = NULL;
	HashTable *_5, *_8;
	HashPosition _4, _7;
	zend_bool _3;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	int dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval *result, *rows, *row = NULL, *underscore, *emptyStr, *hydrateMode, *alias = NULL, *activeRow = NULL, *type = NULL, *columnTypes, *column = NULL, *columnValue = NULL, *value = NULL, *attribute = NULL, *source = NULL, *attributes = NULL, *columnMap = NULL, *rowModel = NULL, *keepSnapshots = NULL, *sqlAlias = NULL, *_0, **_6, **_9, *_10 = NULL, *_12, *_13 = NULL, _14 = zval_used_for_init;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_OBS_VAR(result);
		zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		if (!ZEPHIR_IS_FALSE(result)) {
			ZEPHIR_CALL_METHOD(&row, result, "fetch", NULL, result);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(row);
			ZVAL_BOOL(row, 0);
		}
	} else {
		ZEPHIR_OBS_VAR(rows);
		zephir_read_property_this(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
		if (Z_TYPE_P(rows) == IS_ARRAY) {
			Z_SET_ISREF_P(rows);
			ZEPHIR_CALL_FUNCTION(&row, "current", &_1, rows);
			Z_UNSET_ISREF_P(rows);
			zephir_check_call_status();
			if (Z_TYPE_P(row) == IS_OBJECT) {
				Z_SET_ISREF_P(rows);
				ZEPHIR_CALL_FUNCTION(NULL, "next", &_2, rows);
				Z_UNSET_ISREF_P(rows);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_INIT_NVAR(row);
			ZVAL_BOOL(row, 0);
		}
	}
	_3 = Z_TYPE_P(row) == IS_OBJECT;
	if (!(_3)) {
		_3 = Z_TYPE_P(row) == IS_ARRAY;
	}
	if (_3) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		if (zephir_is_true(_0)) {
			ZEPHIR_OBS_VAR(hydrateMode);
			zephir_read_property_this(&hydrateMode, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(underscore);
			ZVAL_STRING(underscore, "_", 1);
			ZEPHIR_INIT_VAR(emptyStr);
			ZVAL_STRING(emptyStr, "", 1);
			do {
				if (ZEPHIR_IS_LONG(hydrateMode, 0)) {
					ZEPHIR_INIT_VAR(activeRow);
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
				if (ZEPHIR_IS_LONG(hydrateMode, 2)) {
					ZEPHIR_INIT_NVAR(activeRow);
					object_init(activeRow);
					break;
				}
			} while(0);

			ZEPHIR_OBS_VAR(columnTypes);
			zephir_read_property_this(&columnTypes, this_ptr, SL("_columnTypes"), PH_NOISY_CC);
			dirtyState = 0;
			zephir_is_iterable(columnTypes, &_5, &_4, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_5, &_4)
			) {
				ZEPHIR_GET_HMKEY(alias, _5, _4);
				ZEPHIR_GET_HVALUE(column, _6);
				ZEPHIR_OBS_NVAR(type);
				zephir_array_fetch_string(&type, column, SL("type"), PH_NOISY TSRMLS_CC);
				if (Z_TYPE_P(type) == IS_OBJECT) {
					ZEPHIR_OBS_NVAR(source);
					zephir_array_fetch_string(&source, column, SL("column"), PH_NOISY TSRMLS_CC);
					ZEPHIR_OBS_NVAR(attributes);
					zephir_array_fetch_string(&attributes, column, SL("attributes"), PH_NOISY TSRMLS_CC);
					ZEPHIR_OBS_NVAR(columnMap);
					zephir_array_fetch_string(&columnMap, column, SL("columnMap"), PH_NOISY TSRMLS_CC);
					ZEPHIR_INIT_NVAR(rowModel);
					array_init(rowModel);
					zephir_is_iterable(attributes, &_8, &_7, 0, 0);
					for (
					  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
					  ; zephir_hash_move_forward_ex(_8, &_7)
					) {
						ZEPHIR_GET_HVALUE(attribute, _9);
						ZEPHIR_OBS_NVAR(columnValue);
						ZEPHIR_INIT_LNVAR(_10);
						ZEPHIR_CONCAT_VVVV(_10, underscore, source, underscore, attribute);
						zephir_array_fetch(&columnValue, row, _10, PH_NOISY TSRMLS_CC);
						zephir_array_update_zval(&rowModel, attribute, &columnValue, PH_COPY | PH_SEPARATE);
					}
					do {
						if (ZEPHIR_IS_LONG(hydrateMode, 0)) {
							ZEPHIR_OBS_NVAR(keepSnapshots);
							if (!(zephir_array_isset_string_fetch(&keepSnapshots, column, SS("keepSnapshots"), 0 TSRMLS_CC))) {
								ZEPHIR_INIT_NVAR(keepSnapshots);
								ZVAL_BOOL(keepSnapshots, 0);
							}
							zephir_array_fetch_string(&_12, column, SL("instance"), PH_NOISY | PH_READONLY TSRMLS_CC);
							ZEPHIR_INIT_NVAR(_13);
							ZVAL_LONG(_13, dirtyState);
							ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmap", &_11, _12, rowModel, columnMap, _13, keepSnapshots);
							zephir_check_call_status();
							break;
						}
						ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_11, rowModel, columnMap, hydrateMode);
						zephir_check_call_status();
						break;
					} while(0);

					ZEPHIR_OBS_NVAR(attribute);
					zephir_array_fetch_string(&attribute, column, SL("balias"), PH_NOISY TSRMLS_CC);
				} else {
					ZEPHIR_OBS_NVAR(sqlAlias);
					if (zephir_array_isset_string_fetch(&sqlAlias, column, SS("sqlAlias"), 0 TSRMLS_CC)) {
						ZEPHIR_OBS_NVAR(value);
						zephir_array_fetch(&value, row, sqlAlias, PH_NOISY TSRMLS_CC);
					} else {
						ZEPHIR_OBS_NVAR(value);
						zephir_array_fetch(&value, row, alias, PH_NOISY TSRMLS_CC);
					}
					if (zephir_array_isset_string(column, SS("balias"))) {
						ZEPHIR_CPY_WRT(attribute, alias);
					} else {
						ZEPHIR_INIT_NVAR(attribute);
						ZEPHIR_SINIT_NVAR(_14);
						ZVAL_STRING(&_14, "", 0);
						zephir_fast_str_replace(attribute, underscore, &_14, alias);
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
		} else {
			zephir_update_property_this(this_ptr, SL("_activeRow"), row TSRMLS_CC);
		}
		RETURN_MM_BOOL(1);
	}
	zephir_update_property_this(this_ptr, SL("_activeRow"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_MM_BOOL(0);

}

/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than currently it does.
 *
 * @return array
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
		{ zval **tmp; 
		_0->funcs->get_current_data(_0, &tmp TSRMLS_CC);
		current = *tmp;
		}
		zephir_array_append(&records, current, PH_SEPARATE);
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

	ZEPHIR_CALL_METHOD(&records, this_ptr, "toarray",  NULL);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(cache);
	zephir_read_property_this(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(columnTypes);
	zephir_read_property_this(&columnTypes, this_ptr, SL("_columnTypes"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(hydrateMode);
	zephir_read_property_this(&hydrateMode, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 7);
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
 *
 * @param string data
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, unserialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *data, *resultset = NULL, *_0, *_2, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("_type"), _0 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&resultset, "unserialize", &_1, data);
	zephir_check_call_status();
	if (Z_TYPE_P(resultset) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data", "phalcon/mvc/model/resultset/complex.zep", 339);
		return;
	}
	zephir_array_fetch_string(&_2, resultset, SL("rows"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_rows"), _2 TSRMLS_CC);
	zephir_array_fetch_string(&_3, resultset, SL("cache"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_cache"), _3 TSRMLS_CC);
	zephir_array_fetch_string(&_4, resultset, SL("columnTypes"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_columnTypes"), _4 TSRMLS_CC);
	zephir_array_fetch_string(&_5, resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_hydrateMode"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

