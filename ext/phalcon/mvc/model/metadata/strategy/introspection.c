
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/array.h"


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
 * Phalcon\Mvc\Model\MetaData\Strategy\Instrospection
 *
 * Queries the table meta-data in order to instrospect the model's metadata
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_Introspection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\MetaData\\Strategy, Introspection, phalcon, mvc_model_metadata_strategy_introspection, phalcon_mvc_model_metadata_strategy_introspection_method_entry, 0);

	return SUCCESS;

}

/**
 * The meta-data is obtained by reading the column descriptions from the database information schema
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param Phalcon\DiInterface dependencyInjector
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getMetaData) {

	HashTable *_5;
	HashPosition _4;
	zend_bool identityField;
	zval *model, *dependencyInjector, *schema, *table, *readConnection, *columns, *attributes, *primaryKeys, *nonPrimaryKeys, *completeTable = NULL, *numericTyped, *notNull, *fieldTypes, *automaticDefault, *fieldBindTypes, *column = NULL, *fieldName = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, **_6, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);



	if (!(zephir_is_instance_of(model, SL("Phalcon\\Mvc\\ModelInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'");
		return;
	}
	if (!(zephir_is_instance_of(dependencyInjector, SL("Phalcon\\DiInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'");
		return;
	}
	ZEPHIR_INIT_VAR(schema);
	zephir_call_method(schema, model, "getschema");
	ZEPHIR_INIT_VAR(table);
	zephir_call_method(table, model, "getsource");
	ZEPHIR_INIT_VAR(readConnection);
	zephir_call_method(readConnection, model, "getreadconnection");
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p2(_0, readConnection, "tableexists", table, schema);
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
		ZEPHIR_CONCAT_SVSV(_3, "Table '", completeTable, "' doesn't exist on database when dumping meta-data for ", _2);
		zephir_call_method_p1_noret(_1, "__construct", _3);
		zephir_throw_exception(_1 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(columns);
	zephir_call_method_p2(columns, readConnection, "describecolumns", table, schema);
	if (!(zephir_fast_count_int(columns TSRMLS_CC))) {
		if (zephir_is_true(schema)) {
			ZEPHIR_INIT_NVAR(completeTable);
			ZEPHIR_CONCAT_VSV(completeTable, schema, "'.'", table);
		} else {
			ZEPHIR_CPY_WRT(completeTable, table);
		}
		ZEPHIR_INIT_LNVAR(_1);
		object_init_ex(_1, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_NVAR(_2);
		zephir_get_class(_2, model, 0 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SVSV(_3, "Cannot obtain table columns for the mapped source '", completeTable, "' used in model ", _2);
		zephir_call_method_p1_noret(_1, "__construct", _3);
		zephir_throw_exception(_1 TSRMLS_CC);
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
	identityField = 0;
	zephir_is_iterable(columns, &_5, &_4, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(column, _6);
		ZEPHIR_INIT_NVAR(fieldName);
		zephir_call_method(fieldName, column, "getname");
		zephir_array_append(&attributes, fieldName, PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_method(_2, column, "isprimary");
		if (ZEPHIR_IS_TRUE(_2)) {
			zephir_array_append(&primaryKeys, fieldName, PH_SEPARATE);
		} else {
			zephir_array_append(&nonPrimaryKeys, fieldName, PH_SEPARATE);
		}
		ZEPHIR_INIT_NVAR(_7);
		zephir_call_method(_7, column, "isnumeric");
		if (ZEPHIR_IS_TRUE(_7)) {
			zephir_array_update_zval(&numericTyped, fieldName, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_INIT_NVAR(_8);
		zephir_call_method(_8, column, "isnotnull");
		if (ZEPHIR_IS_TRUE(_8)) {
			zephir_array_append(&notNull, fieldName, PH_SEPARATE);
		}
		ZEPHIR_INIT_NVAR(_9);
		zephir_call_method(_9, column, "isautoincrement");
		if (ZEPHIR_IS_TRUE(_9)) {
			identityField = zephir_is_true(fieldName);
		}
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_method(_10, column, "gettype");
		zephir_array_update_zval(&fieldTypes, fieldName, &_10, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_11);
		zephir_call_method(_11, column, "getbindtype");
		zephir_array_update_zval(&fieldBindTypes, fieldName, &_11, PH_COPY | PH_SEPARATE);
	}
	array_init_size(return_value, 13);
	zephir_array_update_long(&return_value, 0, &attributes, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 156);
	zephir_array_update_long(&return_value, 1, &primaryKeys, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 156);
	zephir_array_update_long(&return_value, 2, &nonPrimaryKeys, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 156);
	zephir_array_update_long(&return_value, 3, &notNull, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 156);
	zephir_array_update_long(&return_value, 4, &fieldTypes, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 156);
	zephir_array_update_long(&return_value, 5, &numericTyped, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 156);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_BOOL(_2, identityField);
	zephir_array_update_long(&return_value, 8, &_2, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 156);
	zephir_array_update_long(&return_value, 9, &fieldBindTypes, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 156);
	zephir_array_update_long(&return_value, 10, &automaticDefault, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 156);
	zephir_array_update_long(&return_value, 11, &automaticDefault, PH_COPY, "phalcon/mvc/model/metadata/strategy/introspection.zep", 156);
	RETURN_MM();

}

/**
 * Read the model's column map, this can't be infered
 *
 * @param Phalcon\Mvc\ModelInterface model
 * @param Phalcon\DiInterface dependencyInjector
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getColumnMaps) {

	HashTable *_1;
	HashPosition _0;
	zval *model, *dependencyInjector, *orderedColumnMap = NULL, *userColumnMap, *reversedColumnMap, *name = NULL, *userName = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &dependencyInjector);



	if (!(zephir_is_instance_of(model, SL("Phalcon\\Mvc\\ModelInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\ModelInterface'");
		return;
	}
	if (!(zephir_is_instance_of(dependencyInjector, SL("Phalcon\\DiInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'");
		return;
	}
	ZEPHIR_INIT_VAR(orderedColumnMap);
	ZVAL_NULL(orderedColumnMap);
	ZEPHIR_INIT_VAR(reversedColumnMap);
	ZVAL_NULL(reversedColumnMap);
	if ((zephir_method_exists_ex(model, SS("columnmap") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(userColumnMap);
		zephir_call_method(userColumnMap, model, "columnmap");
		if ((Z_TYPE_P(userColumnMap) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "columnMap() not returned an array");
			return;
		}
		ZEPHIR_INIT_BNVAR(reversedColumnMap);
		array_init(reversedColumnMap);
		ZEPHIR_CPY_WRT(orderedColumnMap, userColumnMap);
		zephir_is_iterable(userColumnMap, &_1, &_0, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(name, _1, _0);
			ZEPHIR_GET_HVALUE(userName, _2);
			zephir_array_update_zval(&reversedColumnMap, userName, &name, PH_COPY | PH_SEPARATE);
		}
	}
	array_init_size(return_value, 3);
	zephir_array_fast_append(return_value, orderedColumnMap);
	zephir_array_fast_append(return_value, reversedColumnMap);
	RETURN_MM();

}

