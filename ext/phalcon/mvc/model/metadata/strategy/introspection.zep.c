
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
#include "kernel/array.h"


/**
 * Phalcon\Mvc\Model\MetaData\Strategy\Introspection
 *
 * Queries the table meta-data in order to introspect the model's metadata
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

	zend_bool _16$$9;
	HashTable *_8;
	HashPosition _7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, *dependencyInjector, *schema = NULL, *table = NULL, *readConnection = NULL, *columns = NULL, *attributes = NULL, *primaryKeys = NULL, *nonPrimaryKeys = NULL, *completeTable = NULL, *numericTyped = NULL, *notNull = NULL, *fieldTypes = NULL, *automaticDefault = NULL, *identityField = NULL, *fieldBindTypes = NULL, *defaultValues = NULL, *column = NULL, *fieldName = NULL, *defaultValue = NULL, *emptyStringValues = NULL, *_0 = NULL, **_9, *_1$$3, *_2$$3, *_3$$3, *_4$$6, *_5$$6, *_6$$6, *_10$$9 = NULL, *_11$$9 = NULL, *_12$$9 = NULL, *_13$$9 = NULL, *_14$$9 = NULL, *_15$$9 = NULL, *_17$$9 = NULL, *_18$$15 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);



	ZEPHIR_CALL_METHOD(&schema, model, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&table, model, "getsource", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&readConnection, model, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, readConnection, "tableexists", NULL, 0, table, schema);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		if (zephir_is_true(schema)) {
			ZEPHIR_INIT_VAR(completeTable);
			ZEPHIR_CONCAT_VSV(completeTable, schema, "'.'", table);
		} else {
			ZEPHIR_CPY_WRT(completeTable, table);
		}
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_get_class(_2$$3, model, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SVSV(_3$$3, "Table '", completeTable, "' doesn't exist in database when dumping meta-data for ", _2$$3);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/mvc/model/metadata/strategy/introspection.zep", 68 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&columns, readConnection, "describecolumns", NULL, 0, table, schema);
	zephir_check_call_status();
	if (!(zephir_fast_count_int(columns TSRMLS_CC))) {
		if (zephir_is_true(schema)) {
			ZEPHIR_INIT_NVAR(completeTable);
			ZEPHIR_CONCAT_VSV(completeTable, schema, "'.'", table);
		} else {
			ZEPHIR_CPY_WRT(completeTable, table);
		}
		ZEPHIR_INIT_VAR(_4$$6);
		object_init_ex(_4$$6, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_5$$6);
		zephir_get_class(_5$$6, model, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_6$$6);
		ZEPHIR_CONCAT_SVSV(_6$$6, "Cannot obtain table columns for the mapped source '", completeTable, "' used in model ", _5$$6);
		ZEPHIR_CALL_METHOD(NULL, _4$$6, "__construct", NULL, 9, _6$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$6, "phalcon/mvc/model/metadata/strategy/introspection.zep", 88 TSRMLS_CC);
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
	ZEPHIR_INIT_VAR(emptyStringValues);
	array_init(emptyStringValues);
	zephir_is_iterable(columns, &_8, &_7, 0, 0, "phalcon/mvc/model/metadata/strategy/introspection.zep", 165);
	for (
	  ; zend_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
	  ; zend_hash_move_forward_ex(_8, &_7)
	) {
		ZEPHIR_GET_HVALUE(column, _9);
		ZEPHIR_CALL_METHOD(&fieldName, column, "getname", NULL, 0);
		zephir_check_call_status();
		zephir_array_append(&attributes, fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 109);
		ZEPHIR_CALL_METHOD(&_10$$9, column, "isprimary", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(_10$$9)) {
			zephir_array_append(&primaryKeys, fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 115);
		} else {
			zephir_array_append(&nonPrimaryKeys, fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 117);
		}
		ZEPHIR_CALL_METHOD(&_11$$9, column, "isnumeric", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(_11$$9)) {
			zephir_array_update_zval(&numericTyped, fieldName, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_CALL_METHOD(&_12$$9, column, "isnotnull", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(_12$$9)) {
			zephir_array_append(&notNull, fieldName, PH_SEPARATE, "phalcon/mvc/model/metadata/strategy/introspection.zep", 131);
		}
		ZEPHIR_CALL_METHOD(&_13$$9, column, "isautoincrement", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(_13$$9)) {
			ZEPHIR_CPY_WRT(identityField, fieldName);
		}
		ZEPHIR_CALL_METHOD(&_14$$9, column, "gettype", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_zval(&fieldTypes, fieldName, &_14$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_15$$9, column, "getbindtype", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_zval(&fieldBindTypes, fieldName, &_15$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		_16$$9 = Z_TYPE_P(defaultValue) != IS_NULL;
		if (!(_16$$9)) {
			ZEPHIR_CALL_METHOD(&_17$$9, column, "isnotnull", NULL, 0);
			zephir_check_call_status();
			_16$$9 = ZEPHIR_IS_FALSE_IDENTICAL(_17$$9);
		}
		if (_16$$9) {
			ZEPHIR_CALL_METHOD(&_18$$15, column, "isautoincrement", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(_18$$15))) {
				zephir_array_update_zval(&defaultValues, fieldName, &defaultValue, PH_COPY | PH_SEPARATE);
			}
		}
	}
	zephir_create_array(return_value, 12, 0 TSRMLS_CC);
	zephir_array_update_long(&return_value, 0, &attributes, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 1, &primaryKeys, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 2, &nonPrimaryKeys, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 3, &notNull, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 4, &fieldTypes, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 5, &numericTyped, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 8, &identityField, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 9, &fieldBindTypes, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 10, &automaticDefault, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 11, &automaticDefault, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 12, &defaultValues, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_update_long(&return_value, 13, &emptyStringValues, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	RETURN_MM();

}

/**
 * Read the model's column map, this can't be inferred
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getColumnMaps) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, *dependencyInjector, *orderedColumnMap = NULL, *userColumnMap = NULL, *reversedColumnMap = NULL, *name = NULL, *userName = NULL, **_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);



	ZEPHIR_INIT_VAR(orderedColumnMap);
	ZVAL_NULL(orderedColumnMap);
	ZEPHIR_INIT_VAR(reversedColumnMap);
	ZVAL_NULL(reversedColumnMap);
	if ((zephir_method_exists_ex(model, SS("columnmap") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&userColumnMap, model, "columnmap", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(userColumnMap) != IS_ARRAY) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "columnMap() not returned an array", "phalcon/mvc/model/metadata/strategy/introspection.zep", 198);
			return;
		}
		ZEPHIR_INIT_NVAR(reversedColumnMap);
		array_init(reversedColumnMap);
		ZEPHIR_CPY_WRT(orderedColumnMap, userColumnMap);
		zephir_is_iterable(userColumnMap, &_1$$3, &_0$$3, 0, 0, "phalcon/mvc/model/metadata/strategy/introspection.zep", 205);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HMKEY(name, _1$$3, _0$$3);
			ZEPHIR_GET_HVALUE(userName, _2$$3);
			zephir_array_update_zval(&reversedColumnMap, userName, &name, PH_COPY | PH_SEPARATE);
		}
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, orderedColumnMap);
	zephir_array_fast_append(return_value, reversedColumnMap);
	RETURN_MM();

}

