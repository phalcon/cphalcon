
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/array.h"


/**
 * Phalcon\Mvc\Model\MetaData\Strategy\Instrospection
 *
 * Queries the table meta-data in order to instrospect the model's metadata
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_Introspection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\MetaData\\Strategy, Introspection, phalcon, mvc_model_metadata_strategy_introspection, phalcon_mvc_model_metadata_strategy_introspection_method_entry, 0);

	zend_class_implements(phalcon_mvc_model_metadata_strategy_introspection_ce TSRMLS_CC, 1, phalcon_mvc_model_metadata_strategyinterface_ce);
	return SUCCESS;

}

/**
 * The meta-data is obtained by reading the column descriptions from the database information schema
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getMetaData) {

	zend_bool _14;
	HashTable *_6;
	HashPosition _5;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *dependencyInjector, *schema = NULL, *table = NULL, *readConnection = NULL, *columns = NULL, *attributes, *primaryKeys, *nonPrimaryKeys, *completeTable = NULL, *numericTyped, *notNull, *fieldTypes, *automaticDefault, *identityField = NULL, *fieldBindTypes, *defaultValues, *column = NULL, *fieldName = NULL, *defaultValue = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, **_7, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_15 = NULL, *_16 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);



	ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&table, model, "getsource", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&readConnection, model, "getreadconnection", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, readConnection, "tableexists", NULL, table, schema);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		if (zephir_is_true(schema)) {
			ZEPHIR_INIT_VAR(completeTable);
			ZEPHIR_CONCAT_VSV(completeTable, schema, "'.'", table);
		} else {
			ZEPHIR_CPY_WRT(completeTable, table);
		}
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		zephir_get_class(_2, model, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVSV(_3, "Table '", completeTable, "' doesn't exist in database when dumping meta-data for ", _2);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_4, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/mvc/model/metadata/strategy/introspection.zep", 63 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&columns, readConnection, "describecolumns", NULL, table, schema);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(columns TSRMLS_CC))) {
		if (zephir_is_true(schema)) {
			ZEPHIR_INIT_NVAR(completeTable);
			ZEPHIR_CONCAT_VSV(completeTable, schema, "'.'", table);
		} else {
			ZEPHIR_CPY_WRT(completeTable, table);
		}
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_NVAR(_2);
		zephir_get_class(_2, model, 0 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SVSV(_3, "Cannot obtain table columns for the mapped source '", completeTable, "' used in model ", _2);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_4, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/mvc/model/metadata/strategy/introspection.zep", 81 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(attributes);
	array_init(attributes);
	ZEPHIR_INIT_VAR(primaryKeys);
	array_init(primaryKeys);
	ZEPHIR_INIT_VAR(nonPrimaryKeys);
	array_init(nonPrimaryKeys);
	ZEPHIR_INIT_VAR(numericTyped);
	array_init(numericTyped);
	ZEPHIR_INIT_VAR(notNull);
	array_init(notNull);
	ZEPHIR_INIT_VAR(fieldTypes);
	array_init(fieldTypes);
	ZEPHIR_INIT_VAR(fieldBindTypes);
	array_init(fieldBindTypes);
	ZEPHIR_INIT_VAR(automaticDefault);
	array_init(automaticDefault);
	ZEPHIR_INIT_VAR(identityField);
	ZVAL_BOOL(identityField, 0);
	ZEPHIR_INIT_VAR(defaultValues);
	array_init(defaultValues);
	zephir_is_iterable(columns, &_6, &_5, 0, 0, "phalcon/mvc/model/metadata/strategy/introspection.zep", 157);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(column, _7);
		ZEPHIR_CALL_METHOD(&fieldName, column, "getname", NULL);
		zephir_check_call_status();
		zephir_array_append(&attributes, fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 101);
		ZEPHIR_CALL_METHOD(&_8, column, "isprimary", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(_8)) {
			zephir_array_append(&primaryKeys, fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 107);
		} else {
			zephir_array_append(&nonPrimaryKeys, fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 109);
		}
		ZEPHIR_CALL_METHOD(&_9, column, "isnumeric", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(_9)) {
			zephir_array_update_zval(&numericTyped, fieldName, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_CALL_METHOD(&_10, column, "isnotnull", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(_10)) {
			zephir_array_append(&notNull, fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 123);
		}
		ZEPHIR_CALL_METHOD(&_11, column, "isautoincrement", NULL);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(_11)) {
			ZEPHIR_CPY_WRT(identityField, fieldName);
		}
		ZEPHIR_CALL_METHOD(&_12, column, "gettype", NULL);
		zephir_check_call_status();
		zephir_array_update_zval(&fieldTypes, fieldName, &_12, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_13, column, "getbindtype", NULL);
		zephir_check_call_status();
		zephir_array_update_zval(&fieldBindTypes, fieldName, &_13, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL);
		zephir_check_call_status();
		_14 = Z_TYPE_P(defaultValue) != IS_NULL;
		if (!(_14)) {
			ZEPHIR_CALL_METHOD(&_15, column, "isnotnull", NULL);
			zephir_check_call_status();
			_14 = ZEPHIR_IS_FALSE_IDENTICAL(_15);
		}
		if (_14) {
			ZEPHIR_CALL_METHOD(&_16, column, "isautoincrement", NULL);
			zephir_check_call_status();
			if (!(zephir_is_true(_16))) {
				zephir_array_update_zval(&defaultValues, fieldName, &defaultValue, PH_COPY | PH_SEPARATE);
			}
		}
	}
	zephir_create_array(return_value, 11, 0 TSRMLS_CC);
	zephir_array_update_long(&return_value, 0, &attributes, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 169);
	zephir_array_update_long(&return_value, 1, &primaryKeys, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 169);
	zephir_array_update_long(&return_value, 2, &nonPrimaryKeys, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 169);
	zephir_array_update_long(&return_value, 3, &notNull, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 169);
	zephir_array_update_long(&return_value, 4, &fieldTypes, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 169);
	zephir_array_update_long(&return_value, 5, &numericTyped, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 169);
	zephir_array_update_long(&return_value, 8, &identityField, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 169);
	zephir_array_update_long(&return_value, 9, &fieldBindTypes, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 169);
	zephir_array_update_long(&return_value, 10, &automaticDefault, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 169);
	zephir_array_update_long(&return_value, 11, &automaticDefault, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 169);
	zephir_array_update_long(&return_value, 12, &defaultValues, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 169);
	RETURN_MM();

}

/**
 * Read the model's column map, this can't be inferred
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getColumnMaps) {

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *dependencyInjector, *orderedColumnMap = NULL, *userColumnMap = NULL, *reversedColumnMap = NULL, *name = NULL, *userName = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);



	ZEPHIR_INIT_VAR(orderedColumnMap);
	ZVAL_NULL(orderedColumnMap);
	ZEPHIR_INIT_VAR(reversedColumnMap);
	ZVAL_NULL(reversedColumnMap);
	if ((zephir_method_exists_ex(model, SS("columnmap") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&userColumnMap, model, "columnmap", NULL);
		zephir_check_call_status();
		if (Z_TYPE_P(userColumnMap) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "columnMap() not returned an array", "phalcon/mvc/model/metadata/strategy/introspection.zep", 189);
			return;
		}
		ZEPHIR_INIT_NVAR(reversedColumnMap);
		array_init(reversedColumnMap);
		ZEPHIR_CPY_WRT(orderedColumnMap, userColumnMap);
		zephir_is_iterable(userColumnMap, &_1, &_0, 0, 0, "phalcon/mvc/model/metadata/strategy/introspection.zep", 196);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(name, _1, _0);
			ZEPHIR_GET_HVALUE(userName, _2);
			zephir_array_update_zval(&reversedColumnMap, userName, &name, PH_COPY | PH_SEPARATE);
		}
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, orderedColumnMap);
	zephir_array_fast_append(return_value, reversedColumnMap);
	RETURN_MM();

}

