
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

#include "mvc/model/metadata/strategy/introspection.h"
#include "mvc/model/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/hash.h"

/**
 * Phalcon\Mvc\Model\MetaData\Strategy\Instrospection
 *
 * Queries the table meta-data in order to instrospect the model's metadata
 */
zend_class_entry *phalcon_mvc_model_metadata_strategy_introspection_ce;

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getMetaData);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getColumnMaps);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_strategy_introspection_getmetadata, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_strategy_introspection_getcolumnmaps, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_metadata_strategy_introspection_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getMetaData, arginfo_phalcon_mvc_model_metadata_strategy_introspection_getmetadata, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getColumnMaps, arginfo_phalcon_mvc_model_metadata_strategy_introspection_getcolumnmaps, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\MetaData\Strategy\Introspection initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Strategy_Introspection){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model\\MetaData\\Strategy, Introspection, mvc_model_metadata_strategy_introspection, phalcon_mvc_model_metadata_strategy_introspection_method_entry, 0);

	return SUCCESS;
}

/**
 * The meta-data is obtained by reading the column descriptions from the database information schema
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param Phalcon\DiInterface $dependencyInjector
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getMetaData){

	zval *model, *dependency_injector, *class_name;
	zval *schema = NULL, *table = NULL, *read_connection = NULL, *exists = NULL;
	zval *complete_table = NULL, *exception_message = NULL;
	zval *columns = NULL, *attributes, *primary_keys, *non_primary_keys;
	zval *numeric_typed, *not_null, *field_types;
	zval *field_bind_types, *automatic_default;
	zval *identity_field = NULL, *column = NULL, *field_name = NULL, *feature = NULL;
	zval *type = NULL, *bind_type = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &dependency_injector);
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model, 0 TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&schema, model, "getschema");
	PHALCON_CALL_METHOD(&table, model, "getsource");
	
	/** 
	 * Check if the mapped table exists on the database
	 */
	PHALCON_CALL_METHOD(&read_connection, model, "getreadconnection");
	PHALCON_CALL_METHOD(&exists, read_connection, "tableexists", table, schema);
	if (!zend_is_true(exists)) {
		if (zend_is_true(schema)) {
			PHALCON_INIT_VAR(complete_table);
			PHALCON_CONCAT_VSV(complete_table, schema, "\".\"", table);
		} else {
			PHALCON_CPY_WRT(complete_table, table);
		}
	
		/** 
		 * The table not exists
		 */
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVSV(exception_message, "Table \"", complete_table, "\" doesn't exist on database when dumping meta-data for ", class_name);
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
		return;
	}
	
	/** 
	 * Try to describe the table
	 */
	PHALCON_CALL_METHOD(&columns, read_connection, "describecolumns", table, schema);
	if (!phalcon_fast_count_ev(columns TSRMLS_CC)) {
		if (zend_is_true(schema)) {
			PHALCON_INIT_NVAR(complete_table);
			PHALCON_CONCAT_VSV(complete_table, schema, "\".\"", table);
		} else {
			PHALCON_CPY_WRT(complete_table, table);
		}
	
		/** 
		 * The table not exists
		 */
		PHALCON_INIT_NVAR(exception_message);
		PHALCON_CONCAT_SVSV(exception_message, "Cannot obtain table columns for the mapped source \"", complete_table, "\" used in model ", class_name);
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
		return;
	}
	
	/** 
	 * Initialize meta-data
	 */
	PHALCON_INIT_VAR(attributes);
	array_init(attributes);
	
	PHALCON_INIT_VAR(primary_keys);
	array_init(primary_keys);
	
	PHALCON_INIT_VAR(non_primary_keys);
	array_init(non_primary_keys);
	
	PHALCON_INIT_VAR(numeric_typed);
	array_init(numeric_typed);
	
	PHALCON_INIT_VAR(not_null);
	array_init(not_null);
	
	PHALCON_INIT_VAR(field_types);
	array_init(field_types);
	
	PHALCON_INIT_VAR(field_bind_types);
	array_init(field_bind_types);
	
	PHALCON_INIT_VAR(automatic_default);
	array_init(automatic_default);
	
	PHALCON_INIT_VAR(identity_field);
	ZVAL_FALSE(identity_field);
	
	phalcon_is_iterable(columns, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(column);
	
		PHALCON_CALL_METHOD(&field_name, column, "getname");
		phalcon_array_append(&attributes, field_name, PH_SEPARATE);
	
		/** 
		 * To mark fields as primary keys
		 */
		PHALCON_CALL_METHOD(&feature, column, "isprimary");
		if (PHALCON_IS_TRUE(feature)) {
			phalcon_array_append(&primary_keys, field_name, PH_SEPARATE);
		} else {
			phalcon_array_append(&non_primary_keys, field_name, PH_SEPARATE);
		}
	
		/** 
		 * To mark fields as numeric
		 */
		PHALCON_CALL_METHOD(&feature, column, "isnumeric");
		if (PHALCON_IS_TRUE(feature)) {
			phalcon_array_update_zval_bool(&numeric_typed, field_name, 1, PH_SEPARATE);
		}
	
		/** 
		 * To mark fields as not null
		 */
		PHALCON_CALL_METHOD(&feature, column, "isnotnull");
		if (PHALCON_IS_TRUE(feature)) {
			phalcon_array_append(&not_null, field_name, PH_SEPARATE);
		}
	
		/** 
		 * To mark fields as identity columns
		 */
		PHALCON_CALL_METHOD(&feature, column, "isautoincrement");
		if (PHALCON_IS_TRUE(feature)) {
			PHALCON_CPY_WRT(identity_field, field_name);
		}
	
		/** 
		 * To get the internal types
		 */
		PHALCON_CALL_METHOD(&type, column, "gettype");
		phalcon_array_update_zval(&field_types, field_name, type, PH_COPY);
	
		/** 
		 * To mark how the fields must be escaped
		 */
		PHALCON_CALL_METHOD(&bind_type, column, "getbindtype");
		phalcon_array_update_zval(&field_bind_types, field_name, bind_type, PH_COPY);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Create an array using the MODELS_* constants as indexes
	 */
	array_init_size(return_value, 10);
	phalcon_array_update_long(&return_value, 0,  attributes, PH_COPY);
	phalcon_array_update_long(&return_value, 1,  primary_keys, PH_COPY);
	phalcon_array_update_long(&return_value, 2,  non_primary_keys, PH_COPY);
	phalcon_array_update_long(&return_value, 3,  not_null, PH_COPY);
	phalcon_array_update_long(&return_value, 4,  field_types, PH_COPY);
	phalcon_array_update_long(&return_value, 5,  numeric_typed, PH_COPY);
	phalcon_array_update_long(&return_value, 8,  identity_field, PH_COPY);
	phalcon_array_update_long(&return_value, 9,  field_bind_types, PH_COPY);
	phalcon_array_update_long(&return_value, 10, automatic_default, PH_COPY);
	phalcon_array_update_long(&return_value, 11, automatic_default, PH_COPY);
	
	PHALCON_MM_RESTORE();
}

/**
 * Read the model's column map, this can't be infered
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param Phalcon\DiInterface $dependencyInjector
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Strategy_Introspection, getColumnMaps){

	zval *model, *dependency_injector, *ordered_column_map = NULL;
	zval *reversed_column_map = NULL, *user_column_map = NULL;
	zval *user_name = NULL, *name = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &dependency_injector);
	
	PHALCON_INIT_VAR(ordered_column_map);
	
	PHALCON_INIT_VAR(reversed_column_map);
	
	/** 
	 * Check for a columnMap() method on the model
	 */
	if (phalcon_method_exists_ex(model, SS("columnmap") TSRMLS_CC) == SUCCESS) {
	
		PHALCON_CALL_METHOD(&user_column_map, model, "columnmap");
		if (Z_TYPE_P(user_column_map) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "columnMap() not returned an array");
			return;
		}
	
		array_init(reversed_column_map);
		PHALCON_CPY_WRT(ordered_column_map, user_column_map);
	
		phalcon_is_iterable(user_column_map, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(name, ah0, hp0);
			PHALCON_GET_HVALUE(user_name);
	
			phalcon_array_update_zval(&reversed_column_map, user_name, name, PH_COPY);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	/** 
	 * Store the column map
	 */
	array_init_size(return_value, 2);
	phalcon_array_update_long(&return_value, 0, ordered_column_map, PH_COPY);
	phalcon_array_update_long(&return_value, 1, reversed_column_map, PH_COPY);
	
	PHALCON_MM_RESTORE();
}
