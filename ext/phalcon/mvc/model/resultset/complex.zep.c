
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
 * Phalcon\Mvc\Model\Resultset\Complex
 *
 * Complex resultsets may include complete objects and scalar values.
 * This class builds every complex row as it is required
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Resultset_Complex) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc\\Model\\Resultset, Complex, phalcon, mvc_model_resultset_complex, phalcon_mvc_model_resultset_ce, phalcon_mvc_model_resultset_complex_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_resultset_complex_ce, SL("_columnTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Unserialised result-set hydrated all rows already. unserialise() sets _disableHydration to true
	 */
	zend_declare_property_bool(phalcon_mvc_model_resultset_complex_ce, SL("_disableHydration"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_resultset_complex_ce TSRMLS_CC, 1, phalcon_mvc_model_resultsetinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Resultset\Complex constructor
 *
 * @param array columnTypes
 * @param \Phalcon\Db\ResultInterface result
 * @param \Phalcon\Cache\BackendInterface cache
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *columnTypes, *result = NULL, *cache = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &columnTypes, &result, &cache);

	if (!result) {
		result = ZEPHIR_GLOBAL(global_null);
	}
	if (!cache) {
		cache = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(getThis(), SL("_columnTypes"), columnTypes TSRMLS_CC);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_resultset_complex_ce, getThis(), "__construct", &_0, 388, result, cache);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns current row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, current) {

	zend_class_entry *_13$$15;
	HashTable *_3, *_6$$11;
	HashPosition _2, _5$$11;
	zval *row = NULL, *hydrateMode = NULL, *eager = NULL, *alias = NULL, *activeRow = NULL, *type = NULL, *column = NULL, *columnValue = NULL, *value = NULL, *attribute = NULL, *source = NULL, *attributes = NULL, *columnMap = NULL, *rowModel = NULL, *keepSnapshots = NULL, *sqlAlias = NULL, *modelName = NULL, *_0, *_1, **_4, **_7$$11, *_8$$12 = NULL, *_9$$15 = NULL, *_11$$15, *_12$$15 = NULL, *_10$$16, *_15$$18, *_16$$18 = NULL, _18$$24 = zval_used_for_init, _19$$24 = zval_used_for_init;
	zephir_fcall_cache_entry *_14 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, dirtyState = 0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(activeRow);
	zephir_read_property_this(&activeRow, this_ptr, SL("_activeRow"), PH_NOISY_CC);
	if (Z_TYPE_P(activeRow) != IS_NULL) {
		RETURN_CCTOR(activeRow);
	}
	ZEPHIR_OBS_VAR(row);
	zephir_read_property_this(&row, this_ptr, SL("_row"), PH_NOISY_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_disableHydration"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		zephir_update_property_this(getThis(), SL("_activeRow"), row TSRMLS_CC);
		RETURN_CCTOR(row);
	}
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
	do {
		if (ZEPHIR_IS_LONG(hydrateMode, 0)) {
			ZEPHIR_INIT_NVAR(activeRow);
			object_init_ex(activeRow, phalcon_mvc_model_row_ce);
			if (zephir_has_constructor(activeRow TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, activeRow, "__construct", NULL, 0);
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

	dirtyState = 0;
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_columnTypes"), PH_NOISY_CC);
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "phalcon/mvc/model/resultset/complex.zep", 246);
	for (
	  ; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zend_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(alias, _3, _2);
		ZEPHIR_GET_HVALUE(column, _4);
		if (Z_TYPE_P(column) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Column type is corrupt", "phalcon/mvc/model/resultset/complex.zep", 133);
			return;
		}
		ZEPHIR_OBS_NVAR(type);
		zephir_array_fetch_string(&type, column, SL("type"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 136 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(type, "object")) {
			ZEPHIR_OBS_NVAR(source);
			zephir_array_fetch_string(&source, column, SL("column"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 142 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(attributes);
			zephir_array_fetch_string(&attributes, column, SL("attributes"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 143 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(columnMap);
			zephir_array_fetch_string(&columnMap, column, SL("columnMap"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 144 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(rowModel);
			array_init(rowModel);
			zephir_is_iterable(attributes, &_6$$11, &_5$$11, 0, 0, "phalcon/mvc/model/resultset/complex.zep", 162);
			for (
			  ; zend_hash_get_current_data_ex(_6$$11, (void**) &_7$$11, &_5$$11) == SUCCESS
			  ; zend_hash_move_forward_ex(_6$$11, &_5$$11)
			) {
				ZEPHIR_GET_HVALUE(attribute, _7$$11);
				ZEPHIR_OBS_NVAR(columnValue);
				ZEPHIR_INIT_LNVAR(_8$$12);
				ZEPHIR_CONCAT_SVSV(_8$$12, "_", source, "_", attribute);
				zephir_array_fetch(&columnValue, row, _8$$12, PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 155 TSRMLS_CC);
				zephir_array_update_zval(&rowModel, attribute, &columnValue, PH_COPY | PH_SEPARATE);
			}
			do {
				if (ZEPHIR_IS_LONG(hydrateMode, 0)) {
					ZEPHIR_OBS_NVAR(keepSnapshots);
					if (!(zephir_array_isset_string_fetch(&keepSnapshots, column, SS("keepSnapshots"), 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(keepSnapshots);
						ZVAL_BOOL(keepSnapshots, 0);
					}
					if (ZEPHIR_GLOBAL(orm).late_state_binding) {
						ZEPHIR_OBS_NVAR(_9$$15);
						zephir_array_fetch_string(&_9$$15, column, SL("instance"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 173 TSRMLS_CC);
						if (zephir_instance_of_ev(_9$$15, phalcon_mvc_model_ce TSRMLS_CC)) {
							zephir_array_fetch_string(&_10$$16, column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 174 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(modelName);
							zephir_get_class(modelName, _10$$16, 0 TSRMLS_CC);
						} else {
							ZEPHIR_INIT_NVAR(modelName);
							ZVAL_STRING(modelName, "Phalcon\\Mvc\\Model", 1);
						}
						zephir_array_fetch_string(&_11$$15, column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 180 TSRMLS_CC);
						ZEPHIR_INIT_NVAR(_12$$15);
						ZVAL_LONG(_12$$15, dirtyState);
						_13$$15 = zephir_fetch_class(modelName TSRMLS_CC);
						ZEPHIR_CALL_CE_STATIC(&value, _13$$15, "cloneresultmap", NULL, 0, _11$$15, rowModel, columnMap, _12$$15, keepSnapshots);
						zephir_check_call_status();
					} else {
						zephir_array_fetch_string(&_15$$18, column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 188 TSRMLS_CC);
						ZEPHIR_INIT_NVAR(_16$$18);
						ZVAL_LONG(_16$$18, dirtyState);
						ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmap", &_14, 0, _15$$18, rowModel, columnMap, _16$$18, keepSnapshots);
						zephir_check_call_status();
					}
					break;
				}
				ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_17, 0, rowModel, columnMap, hydrateMode);
				zephir_check_call_status();
				break;
			} while(0);

			ZEPHIR_OBS_NVAR(attribute);
			zephir_array_fetch_string(&attribute, column, SL("balias"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 202 TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(sqlAlias);
			if (zephir_array_isset_string_fetch(&sqlAlias, column, SS("sqlAlias"), 0 TSRMLS_CC)) {
				ZEPHIR_OBS_NVAR(value);
				zephir_array_fetch(&value, row, sqlAlias, PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 210 TSRMLS_CC);
			} else {
				ZEPHIR_OBS_NVAR(value);
				zephir_array_isset_fetch(&value, row, alias, 0 TSRMLS_CC);
			}
			if (zephir_array_isset_string(column, SS("balias"))) {
				ZEPHIR_CPY_WRT(attribute, alias);
			} else {
				ZEPHIR_SINIT_NVAR(_18$$24);
				ZVAL_STRING(&_18$$24, "_", 0);
				ZEPHIR_SINIT_NVAR(_19$$24);
				ZVAL_STRING(&_19$$24, "", 0);
				ZEPHIR_INIT_NVAR(attribute);
				zephir_fast_str_replace(&attribute, &_18$$24, &_19$$24, alias TSRMLS_CC);
			}
		}
		if (!(zephir_array_isset_string_fetch(&eager, column, SS("eager"), 1 TSRMLS_CC))) {
			do {
				if (ZEPHIR_IS_LONG(hydrateMode, 1)) {
					zephir_array_update_zval(&activeRow, attribute, &value, PH_COPY | PH_SEPARATE);
					break;
				}
				zephir_update_property_zval_zval(activeRow, attribute, value TSRMLS_CC);
				break;
			} while(0);

		}
	}
	zephir_update_property_this(getThis(), SL("_activeRow"), activeRow TSRMLS_CC);
	RETURN_CCTOR(activeRow);

}

/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than currently it does.
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, toArray) {

	zval *records = NULL, *current = NULL, *_0 = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(records);
	array_init(records);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 80);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&current, this_ptr, "current", &_2, 389);
		zephir_check_call_status();
		zephir_array_append(&records, current, PH_SEPARATE, "phalcon/mvc/model/resultset/complex.zep", 263);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_3, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(records);

}

/**
 * Serializing a resultset will dump all related rows into a big array
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, serialize) {

	zval *_0;
	zval *records = NULL, *cache = NULL, *columnTypes = NULL, *hydrateMode = NULL, *serialized = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&records, this_ptr, "toarray", NULL, 0);
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
	ZEPHIR_CALL_FUNCTION(&serialized, "serialize", NULL, 68, _0);
	zephir_check_call_status();
	RETURN_CCTOR(serialized);

}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, unserialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, *resultset = NULL, *_0, *_1, *_2, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (1) {
		zephir_update_property_this(getThis(), SL("_disableHydration"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_disableHydration"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_CALL_FUNCTION(&resultset, "unserialize", NULL, 69, data);
	zephir_check_call_status();
	if (Z_TYPE_P(resultset) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data", "phalcon/mvc/model/resultset/complex.zep", 310);
		return;
	}
	zephir_array_fetch_string(&_0, resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 313 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_rows"), _0 TSRMLS_CC);
	zephir_array_fetch_string(&_1, resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 314 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(_2, zephir_fast_count_int(_1 TSRMLS_CC));
	zephir_update_property_this(getThis(), SL("_count"), _2 TSRMLS_CC);
	zephir_array_fetch_string(&_3, resultset, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 315 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_cache"), _3 TSRMLS_CC);
	zephir_array_fetch_string(&_4, resultset, SL("columnTypes"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 316 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_columnTypes"), _4 TSRMLS_CC);
	zephir_array_fetch_string(&_5, resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 317 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_hydrateMode"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

