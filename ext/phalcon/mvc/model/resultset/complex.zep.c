
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *columnTypes, columnTypes_sub, *result = NULL, result_sub, *cache = NULL, cache_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columnTypes_sub);
	ZVAL_UNDEF(&result_sub);
	ZVAL_UNDEF(&cache_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &columnTypes, &result, &cache);

	if (!result) {
		result = &result_sub;
		result = &__$null;
	}
	if (!cache) {
		cache = &cache_sub;
		cache = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("_columnTypes"), columnTypes);
	ZEPHIR_CALL_PARENT(NULL, phalcon_mvc_model_resultset_complex_ce, getThis(), "__construct", &_0, 0, result, cache);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns current row in the resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, current) {

	zend_class_entry *_11$$15;
	zend_string *_4;
	zend_ulong _3;
	zephir_fcall_cache_entry *_12 = NULL, *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, dirtyState = 0;
	zval __$true, __$false, row, hydrateMode, eager, alias, activeRow, type, column, columnValue, value, attribute, source, attributes, columnMap, rowModel, keepSnapshots, sqlAlias, modelName, _0, _1, *_2, *_5$$11, _6$$12, _7$$15, _9$$15, _10$$15, _8$$16, _13$$18, _14$$18, _16$$24, _17$$24;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&hydrateMode);
	ZVAL_UNDEF(&eager);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&activeRow);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&columnValue);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&rowModel);
	ZVAL_UNDEF(&keepSnapshots);
	ZVAL_UNDEF(&sqlAlias);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6$$12);
	ZVAL_UNDEF(&_7$$15);
	ZVAL_UNDEF(&_9$$15);
	ZVAL_UNDEF(&_10$$15);
	ZVAL_UNDEF(&_8$$16);
	ZVAL_UNDEF(&_13$$18);
	ZVAL_UNDEF(&_14$$18);
	ZVAL_UNDEF(&_16$$24);
	ZVAL_UNDEF(&_17$$24);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&activeRow);
	zephir_read_property(&activeRow, this_ptr, SL("_activeRow"), PH_NOISY_CC);
	if (Z_TYPE_P(&activeRow) != IS_NULL) {
		RETURN_CCTOR(&activeRow);
	}
	ZEPHIR_OBS_VAR(&row);
	zephir_read_property(&row, this_ptr, SL("_row"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, SL("_disableHydration"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_update_property_zval(this_ptr, SL("_activeRow"), &row);
		RETURN_CCTOR(&row);
	}
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
	do {
		if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
			ZEPHIR_INIT_NVAR(&activeRow);
			object_init_ex(&activeRow, phalcon_mvc_model_row_ce);
			if (zephir_has_constructor(&activeRow TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, &activeRow, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&hydrateMode, 1)) {
			ZEPHIR_INIT_NVAR(&activeRow);
			array_init(&activeRow);
			break;
		}
		ZEPHIR_INIT_NVAR(&activeRow);
		object_init(&activeRow);
		break;
	} while(0);

	dirtyState = 0;
	zephir_read_property(&_1, this_ptr, SL("_columnTypes"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_1, 0, "phalcon/mvc/model/resultset/complex.zep", 244);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&alias);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&alias, _4);
		} else {
			ZVAL_LONG(&alias, _3);
		}
		ZEPHIR_INIT_NVAR(&column);
		ZVAL_COPY(&column, _2);
		if (Z_TYPE_P(&column) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Column type is corrupt", "phalcon/mvc/model/resultset/complex.zep", 131);
			return;
		}
		ZEPHIR_OBS_NVAR(&type);
		zephir_array_fetch_string(&type, &column, SL("type"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 134 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&type, "object")) {
			ZEPHIR_OBS_NVAR(&source);
			zephir_array_fetch_string(&source, &column, SL("column"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 140 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&attributes);
			zephir_array_fetch_string(&attributes, &column, SL("attributes"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 141 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&columnMap);
			zephir_array_fetch_string(&columnMap, &column, SL("columnMap"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 142 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&rowModel);
			array_init(&rowModel);
			zephir_is_iterable(&attributes, 0, "phalcon/mvc/model/resultset/complex.zep", 160);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _5$$11)
			{
				ZEPHIR_INIT_NVAR(&attribute);
				ZVAL_COPY(&attribute, _5$$11);
				ZEPHIR_OBS_NVAR(&columnValue);
				ZEPHIR_INIT_LNVAR(_6$$12);
				ZEPHIR_CONCAT_SVSV(&_6$$12, "_", &source, "_", &attribute);
				zephir_array_fetch(&columnValue, &row, &_6$$12, PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 153 TSRMLS_CC);
				zephir_array_update_zval(&rowModel, &attribute, &columnValue, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&attribute);
			do {
				if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
					ZEPHIR_OBS_NVAR(&keepSnapshots);
					if (!(zephir_array_isset_string_fetch(&keepSnapshots, &column, SL("keepSnapshots"), 0))) {
						ZEPHIR_INIT_NVAR(&keepSnapshots);
						ZVAL_BOOL(&keepSnapshots, 0);
					}
					if (ZEPHIR_GLOBAL(orm).late_state_binding) {
						ZEPHIR_OBS_NVAR(&_7$$15);
						zephir_array_fetch_string(&_7$$15, &column, SL("instance"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 171 TSRMLS_CC);
						if (zephir_instance_of_ev(&_7$$15, phalcon_mvc_model_ce TSRMLS_CC)) {
							zephir_array_fetch_string(&_8$$16, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 172 TSRMLS_CC);
							ZEPHIR_INIT_NVAR(&modelName);
							zephir_get_class(&modelName, &_8$$16, 0 TSRMLS_CC);
						} else {
							ZEPHIR_INIT_NVAR(&modelName);
							ZVAL_STRING(&modelName, "Phalcon\\Mvc\\Model");
						}
						zephir_array_fetch_string(&_9$$15, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 178 TSRMLS_CC);
						ZVAL_LONG(&_10$$15, dirtyState);
						_11$$15 = zephir_fetch_class(&modelName TSRMLS_CC);
						ZEPHIR_CALL_CE_STATIC(&value, _11$$15, "cloneresultmap", NULL, 0, &_9$$15, &rowModel, &columnMap, &_10$$15, &keepSnapshots);
						zephir_check_call_status();
					} else {
						zephir_array_fetch_string(&_13$$18, &column, SL("instance"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 186 TSRMLS_CC);
						ZVAL_LONG(&_14$$18, dirtyState);
						ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmap", &_12, 0, &_13$$18, &rowModel, &columnMap, &_14$$18, &keepSnapshots);
						zephir_check_call_status();
					}
					break;
				}
				ZEPHIR_CALL_CE_STATIC(&value, phalcon_mvc_model_ce, "cloneresultmaphydrate", &_15, 0, &rowModel, &columnMap, &hydrateMode);
				zephir_check_call_status();
				break;
			} while(0);

			ZEPHIR_OBS_NVAR(&attribute);
			zephir_array_fetch_string(&attribute, &column, SL("balias"), PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 200 TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(&sqlAlias);
			if (zephir_array_isset_string_fetch(&sqlAlias, &column, SL("sqlAlias"), 0)) {
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_fetch(&value, &row, &sqlAlias, PH_NOISY, "phalcon/mvc/model/resultset/complex.zep", 208 TSRMLS_CC);
			} else {
				ZEPHIR_OBS_NVAR(&value);
				zephir_array_isset_fetch(&value, &row, &alias, 0 TSRMLS_CC);
			}
			if (zephir_array_isset_string(&column, SL("balias"))) {
				ZEPHIR_CPY_WRT(&attribute, &alias);
			} else {
				ZEPHIR_INIT_NVAR(&_16$$24);
				ZVAL_STRING(&_16$$24, "_");
				ZEPHIR_INIT_NVAR(&_17$$24);
				ZVAL_STRING(&_17$$24, "");
				ZEPHIR_INIT_NVAR(&attribute);
				zephir_fast_str_replace(&attribute, &_16$$24, &_17$$24, &alias TSRMLS_CC);
			}
		}
		if (!(zephir_array_isset_string_fetch(&eager, &column, SL("eager"), 1))) {
			do {
				if (ZEPHIR_IS_LONG(&hydrateMode, 1)) {
					zephir_array_update_zval(&activeRow, &attribute, &value, PH_COPY | PH_SEPARATE);
					break;
				}
				zephir_update_property_zval_zval(&activeRow, &attribute, &value TSRMLS_CC);
				break;
			} while(0);

		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&column);
	ZEPHIR_INIT_NVAR(&alias);
	zephir_update_property_zval(this_ptr, SL("_activeRow"), &activeRow);
	RETURN_CCTOR(&activeRow);

}

/**
 * Returns a complete resultset as an array, if the resultset has a big number of rows
 * it could consume more memory than currently it does.
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, toArray) {

	zval records, current, _0;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&records);
	array_init(&records);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rewind", NULL, 71);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "valid", &_1, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_0))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&current, this_ptr, "current", &_2, 347);
		zephir_check_call_status();
		zephir_array_append(&records, &current, PH_SEPARATE, "phalcon/mvc/model/resultset/complex.zep", 261);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "next", &_3, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&records);

}

/**
 * Serializing a resultset will dump all related rows into a big array
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, serialize) {

	zval _0;
	zval records, cache, columnTypes, hydrateMode, serialized;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&columnTypes);
	ZVAL_UNDEF(&hydrateMode);
	ZVAL_UNDEF(&serialized);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&records, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&cache);
	zephir_read_property(&cache, this_ptr, SL("_cache"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&columnTypes);
	zephir_read_property(&columnTypes, this_ptr, SL("_columnTypes"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&hydrateMode);
	zephir_read_property(&hydrateMode, this_ptr, SL("_hydrateMode"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("cache"), &cache, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("rows"), &records, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("columnTypes"), &columnTypes, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("hydrateMode"), &hydrateMode, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&serialized, "serialize", NULL, 60, &_0);
	zephir_check_call_status();
	RETURN_CCTOR(&serialized);

}

/**
 * Unserializing a resultset will allow to only works on the rows present in the saved state
 */
PHP_METHOD(Phalcon_Mvc_Model_Resultset_Complex, unserialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, __$true, __$false, resultset, _0, _1, _2, _3, _4, _5;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

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


	if (1) {
		zephir_update_property_zval(this_ptr, SL("_disableHydration"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_disableHydration"), &__$false);
	}
	ZEPHIR_CALL_FUNCTION(&resultset, "unserialize", NULL, 61, &data);
	zephir_check_call_status();
	if (Z_TYPE_P(&resultset) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data", "phalcon/mvc/model/resultset/complex.zep", 308);
		return;
	}
	zephir_array_fetch_string(&_0, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 311 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_rows"), &_0);
	zephir_array_fetch_string(&_1, &resultset, SL("rows"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 312 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, zephir_fast_count_int(&_1 TSRMLS_CC));
	zephir_update_property_zval(this_ptr, SL("_count"), &_2);
	zephir_array_fetch_string(&_3, &resultset, SL("cache"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 313 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_cache"), &_3);
	zephir_array_fetch_string(&_4, &resultset, SL("columnTypes"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 314 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_columnTypes"), &_4);
	zephir_array_fetch_string(&_5, &resultset, SL("hydrateMode"), PH_NOISY | PH_READONLY, "phalcon/mvc/model/resultset/complex.zep", 315 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_hydrateMode"), &_5);
	ZEPHIR_MM_RESTORE();

}

