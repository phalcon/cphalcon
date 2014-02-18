
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"


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

	zend_bool _0;
	zval *columnTypes, *result, *cache = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &columnTypes, &result, &cache);

	if (!cache) {
		cache = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_is_instance_of(result, SL("Phalcon\\Db\\ResultInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'result' must be an instance of 'Phalcon\\Db\\ResultInterface'");
		return;
	}
	_0 = (Z_TYPE_P(cache) != IS_NULL);
	if (_0) {
		_0 = !zephir_is_instance_of(cache, SL("Phalcon\\Cache\\BackendInterface") TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'cache' must be an instance of 'Phalcon\\Cache\\BackendInterface'");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_columnTypes"), columnTypes TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_result"), result TSRMLS_CC);
	if ((Z_TYPE_P(cache) != IS_NULL)) {
		zephir_update_property_this(this_ptr, SL("_cache"), cache TSRMLS_CC);
	}
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, 1);
	zephir_update_property_this(this_ptr, SL("_type"), _1 TSRMLS_CC);
	if ((Z_TYPE_P(result) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_LONG(_2, 1);
		zephir_call_method_p1_noret(result, "setfetchmode", _2);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether internal resource has rows to fetch
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, valid) {

	HashTable *_4, *_7;
	HashPosition _3, _6;
	zend_bool _1;
	int dirtyState;
	zval *result, *rows, *row = NULL, *underscore, *emptyStr, *hydrateMode, *alias = NULL, *activeRow = NULL, *type = NULL, *columnTypes, *column = NULL, *columnValue = NULL, *value = NULL, *attribute = NULL, *source = NULL, *attributes = NULL, *columnMap = NULL, *rowModel = NULL, *keepSnapshots = NULL, *sqlAlias = NULL, *_0, *_2, **_5, **_8, *_9 = NULL, *_10, *_11 = NULL, _12 = zval_used_for_init;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_OBS_VAR(result);
		zephir_read_property_this(&result, this_ptr, SL("_result"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(row);
		if (!ZEPHIR_IS_FALSE(result)) {
			zephir_call_method_p1(row, result, "fetch", result);
		} else {
			ZVAL_BOOL(row, 0);
		}
	} else {
		ZEPHIR_OBS_VAR(rows);
		zephir_read_property_this(&rows, this_ptr, SL("_rows"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(row);
		if ((Z_TYPE_P(rows) == IS_ARRAY)) {
			Z_SET_ISREF_P(rows);
			zephir_call_func_p1(row, "current", rows);
			Z_UNSET_ISREF_P(rows);
			if ((Z_TYPE_P(row) == IS_OBJECT)) {
				Z_SET_ISREF_P(rows);
				zephir_call_func_p1_noret("next", rows);
				Z_UNSET_ISREF_P(rows);
			}
		} else {
			ZVAL_BOOL(row, 0);
		}
	}
	_1 = (Z_TYPE_P(row) == IS_OBJECT);
	if (!(_1)) {
		_1 = (Z_TYPE_P(row) == IS_ARRAY);
	}
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
		if (zephir_is_true(_2)) {
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
						zephir_call_method_noret(activeRow, "__construct");
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
			zephir_is_iterable(columnTypes, &_4, &_3, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
			  ; zephir_hash_move_forward_ex(_4, &_3)
			) {
				ZEPHIR_GET_HMKEY(alias, _4, _3);
				ZEPHIR_GET_HVALUE(column, _5);
				ZEPHIR_OBS_NVAR(type);
				zephir_array_fetch_string(&type, column, SL("type"), PH_NOISY TSRMLS_CC);
				if ((Z_TYPE_P(type) == IS_OBJECT)) {
					ZEPHIR_OBS_NVAR(source);
					zephir_array_fetch_string(&source, column, SL("column"), PH_NOISY TSRMLS_CC);
					ZEPHIR_OBS_NVAR(attributes);
					zephir_array_fetch_string(&attributes, column, SL("attributes"), PH_NOISY TSRMLS_CC);
					ZEPHIR_OBS_NVAR(columnMap);
					zephir_array_fetch_string(&columnMap, column, SL("columnMap"), PH_NOISY TSRMLS_CC);
					ZEPHIR_INIT_NVAR(rowModel);
					array_init(rowModel);
					zephir_is_iterable(attributes, &_7, &_6, 0, 0);
					for (
					  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
					  ; zephir_hash_move_forward_ex(_7, &_6)
					) {
						ZEPHIR_GET_HVALUE(attribute, _8);
						ZEPHIR_OBS_NVAR(columnValue);
						ZEPHIR_INIT_LNVAR(_9);
						ZEPHIR_CONCAT_VVVV(_9, underscore, source, underscore, attribute);
						zephir_array_fetch(&columnValue, row, _9, PH_NOISY TSRMLS_CC);
						zephir_array_update_zval(&rowModel, attribute, &columnValue, PH_COPY | PH_SEPARATE);
					}
					do {
						if (ZEPHIR_IS_LONG(hydrateMode, 0)) {
							ZEPHIR_OBS_NVAR(keepSnapshots);
							if (!(zephir_array_isset_string_fetch(&keepSnapshots, column, SS("keepSnapshots"), 0 TSRMLS_CC))) {
								ZEPHIR_INIT_NVAR(keepSnapshots);
								ZVAL_BOOL(keepSnapshots, 0);
							}
							zephir_array_fetch_string(&_10, column, SL("instance"), PH_NOISY | PH_READONLY TSRMLS_CC);
							ZEPHIR_INIT_NVAR(_11);
							ZVAL_LONG(_11, dirtyState);
							ZEPHIR_INIT_NVAR(value);
							zephir_call_static_p5(value, "Phalcon\\Mvc\\Model", "cloneresultmap", _10, rowModel, columnMap, _11, keepSnapshots);
							break;
						}
						ZEPHIR_INIT_NVAR(value);
						zephir_call_static_p3(value, "Phalcon\\Mvc\\Model", "cloneresultmaphydrate", rowModel, columnMap, hydrateMode);
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
						ZEPHIR_SINIT_NVAR(_12);
						ZVAL_STRING(&_12, "", 0);
						zephir_fast_str_replace(attribute, underscore, &_12, alias);
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

	HashTable *_2;
	HashPosition _1;
	zval *records, *current = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(records);
	array_init(records);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func_p1(_0, "iterator", this_ptr);
	zephir_is_iterable(_0, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(current, _3);
		zephir_array_append(&records, current, PH_SEPARATE);
	}
	RETURN_CCTOR(records);

}

/**
 * Serializing a resultset will dump all related rows into a big array
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, serialize) {

	zval *_0;
	zval *records, *cache, *columnTypes, *hydrateMode, *serialized;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(records);
	zephir_call_method(records, this_ptr, "toarray");
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
	ZEPHIR_INIT_VAR(serialized);
	zephir_call_func_p1(serialized, "serialize", _0);
	if ((Z_TYPE_P(serialized) != IS_STRING)) {
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

	zval *data, *resultset, *_0, *_1, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("_type"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(resultset);
	zephir_call_func_p1(resultset, "unserialize", data);
	if ((Z_TYPE_P(resultset) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data");
		return;
	}
	zephir_array_fetch_string(&_1, resultset, SL("rows"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_rows"), _1 TSRMLS_CC);
	zephir_array_fetch_string(&_2, resultset, SL("cache"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_cache"), _2 TSRMLS_CC);
	zephir_array_fetch_string(&_3, resultset, SL("columnTypes"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_columnTypes"), _3 TSRMLS_CC);
	zephir_array_fetch_string(&_4, resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_hydrateMode"), _4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

