
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/array.h"
#include "kernel/operators.h"

/**
 * Phalcon\Mvc\Model\MetaData\Strategy\Instrospection
 *
 * Queries the table meta-data in order to instrospect the model's metadata
 */


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
	zval *schema, *table, *read_connection, *exists;
	zval *complete_table = NULL, *exception_message = NULL;
	zval *columns, *attributes, *primary_keys, *non_primary_keys;
	zval *numeric_typed, *not_null, *field_types;
	zval *field_bind_types, *automatic_default;
	zval *identity_field = NULL, *column = NULL, *field_name = NULL, *feature = NULL;
	zval *type = NULL, *bind_type = NULL, *model_metadata;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &dependency_injector);
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model, 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(schema);
	phalcon_call_method(schema, model, "getschema");
	
	PHALCON_INIT_VAR(table);
	phalcon_call_method(table, model, "getsource");
	
	/** 
	 * Check if the mapped table exists on the database
	 */
	PHALCON_INIT_VAR(read_connection);
	phalcon_call_method(read_connection, model, "getreadconnection");
	
	PHALCON_INIT_VAR(exists);
	phalcon_call_method_p2(exists, read_connection, "tableexists", table, schema);
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
	PHALCON_INIT_VAR(columns);
	phalcon_call_method_p2(columns, read_connection, "describecolumns", table, schema);
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
	ZVAL_BOOL(identity_field, 0);
	
	phalcon_is_iterable(columns, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(column);
	
		PHALCON_INIT_NVAR(field_name);
		phalcon_call_method(field_name, column, "getname");
		phalcon_array_append(&attributes, field_name, PH_SEPARATE TSRMLS_CC);
	
		/** 
		 * To mark fields as primary keys
		 */
		PHALCON_INIT_NVAR(feature);
		phalcon_call_method(feature, column, "isprimary");
		if (PHALCON_IS_TRUE(feature)) {
			phalcon_array_append(&primary_keys, field_name, PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_append(&non_primary_keys, field_name, PH_SEPARATE TSRMLS_CC);
		}
	
		/** 
		 * To mark fields as numeric
		 */
		PHALCON_INIT_NVAR(feature);
		phalcon_call_method(feature, column, "isnumeric");
		if (PHALCON_IS_TRUE(feature)) {
			phalcon_array_update_zval_bool(&numeric_typed, field_name, 1, PH_SEPARATE TSRMLS_CC);
		}
	
		/** 
		 * To mark fields as not null
		 */
		PHALCON_INIT_NVAR(feature);
		phalcon_call_method(feature, column, "isnotnull");
		if (PHALCON_IS_TRUE(feature)) {
			phalcon_array_append(&not_null, field_name, PH_SEPARATE TSRMLS_CC);
		}
	
		/** 
		 * To mark fields as identity columns
		 */
		PHALCON_INIT_NVAR(feature);
		phalcon_call_method(feature, column, "isautoincrement");
		if (PHALCON_IS_TRUE(feature)) {
			PHALCON_CPY_WRT(identity_field, field_name);
		}
	
		/** 
		 * To get the internal types
		 */
		PHALCON_INIT_NVAR(type);
		phalcon_call_method(type, column, "gettype");
		phalcon_array_update_zval(&field_types, field_name, &type, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		/** 
		 * To mark how the fields must be escaped
		 */
		PHALCON_INIT_NVAR(bind_type);
		phalcon_call_method(bind_type, column, "getbindtype");
		phalcon_array_update_zval(&field_bind_types, field_name, &bind_type, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Create an array using the MODELS_* constants as indexes
	 */
	PHALCON_INIT_VAR(model_metadata);
	array_init(model_metadata);
	phalcon_array_update_long(&model_metadata, 0, &attributes, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_long(&model_metadata, 1, &primary_keys, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_long(&model_metadata, 2, &non_primary_keys, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_long(&model_metadata, 3, &not_null, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_long(&model_metadata, 4, &field_types, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_long(&model_metadata, 5, &numeric_typed, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_long(&model_metadata, 8, &identity_field, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_long(&model_metadata, 9, &field_bind_types, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_long(&model_metadata, 10, &automatic_default, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_long(&model_metadata, 11, &automatic_default, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	RETURN_CTOR(model_metadata);
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
	zval *reversed_column_map = NULL, *user_column_map;
	zval *user_name = NULL, *name = NULL, *model_column_map;
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
	
		PHALCON_INIT_VAR(user_column_map);
		phalcon_call_method(user_column_map, model, "columnmap");
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
	
			phalcon_array_update_zval(&reversed_column_map, user_name, &name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	/** 
	 * Store the column map
	 */
	PHALCON_INIT_VAR(model_column_map);
	array_init(model_column_map);
	phalcon_array_update_long(&model_column_map, 0, &ordered_column_map, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_long(&model_column_map, 1, &reversed_column_map, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	RETURN_CTOR(model_column_map);
}

