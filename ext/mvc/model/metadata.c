
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/operators.h"

/**
 * Phalcon\Mvc\Model\MetaData
 *
 * <p>Because Phalcon\Mvc\Model requires meta-data like field names, data types, primary keys, etc.
 * this component collect them and store for further querying by Phalcon\Model\Base.
 * Phalcon\Mvc\Model\MetaData can also use adapters to store temporarily or permanently the meta-data.</p>
 *
 * <p>A standard Phalcon\Mvc\Model\MetaData can be used to query model attributes:</p>
 *
 * <code>
 *	$metaData = new Phalcon\Mvc\Model\MetaData\Memory();
 *	$attributes = $metaData->getAttributes(new Robots());
 *	print_r($attributes);
 * </code>
 *
 */

/**
 * Initialize the metadata for certain table
 *
 * @param Phalcon\Mvc\Model $model
 * @param string $table
 * @param string $schema
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, _initializeMetaData){

	zval *model, *table, *schema, *key, *meta_data, *connection;
	zval *exists, *complete_table = NULL, *class_name = NULL, *exception_message = NULL;
	zval *attributes, *primary_keys, *non_primary_keys;
	zval *numeric_typed, *not_null, *field_types;
	zval *field_bind_types, *identity_field = NULL, *columns;
	zval *number_columns, *column = NULL, *field_name = NULL, *feature = NULL;
	zval *type = NULL, *bind_type = NULL, *table_metadata, *changed;
	zval *registered, *handler;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &model, &table, &schema) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, schema, table);
	
	PHALCON_INIT_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(meta_data, key);
	if (!eval_int) {
		PHALCON_INIT_VAR(connection);
		PHALCON_CALL_METHOD(connection, model, "getconnection", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(exists);
		PHALCON_CALL_METHOD_PARAMS_2(exists, connection, "tableexists", table, schema, PH_NO_CHECK);
		if (!zend_is_true(exists)) {
			if (zend_is_true(schema)) {
				PHALCON_INIT_VAR(complete_table);
				PHALCON_CONCAT_VSV(complete_table, schema, "\".\"", table);
			} else {
				PHALCON_CPY_WRT(complete_table, table);
			}
			
			PHALCON_INIT_VAR(class_name);
			phalcon_get_class(class_name, model TSRMLS_CC);
			
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVSV(exception_message, "Table \"", complete_table, "\" doesn't exist on database when dumping meta-data for ", class_name);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
		
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
		
		PHALCON_INIT_VAR(identity_field);
		ZVAL_BOOL(identity_field, 0);
		
		PHALCON_INIT_VAR(columns);
		PHALCON_CALL_METHOD_PARAMS_2(columns, connection, "describecolumns", table, schema, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(number_columns);
		phalcon_fast_count(number_columns, columns TSRMLS_CC);
		if (phalcon_compare_strict_long(number_columns, 0 TSRMLS_CC)) {
			if (zend_is_true(schema)) {
				PHALCON_INIT_NVAR(complete_table);
				PHALCON_CONCAT_VSV(complete_table, schema, "\".\"", table);
			} else {
				PHALCON_CPY_WRT(complete_table, table);
			}
			
			PHALCON_INIT_NVAR(class_name);
			phalcon_get_class(class_name, model TSRMLS_CC);
			
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVSV(exception_message, "Cannot obtain table columns for the mapped source \"", complete_table, "\" used in model ", class_name);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
		
		
		if (!phalcon_valid_foreach(columns TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(columns);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_VALUE(column);
			
			PHALCON_INIT_NVAR(field_name);
			PHALCON_CALL_METHOD(field_name, column, "getname", PH_NO_CHECK);
			phalcon_array_append(&attributes, field_name, PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_NVAR(feature);
			PHALCON_CALL_METHOD(feature, column, "isprimary", PH_NO_CHECK);
			if (PHALCON_IS_TRUE(feature)) {
				phalcon_array_append(&primary_keys, field_name, PH_SEPARATE TSRMLS_CC);
			} else {
				phalcon_array_append(&non_primary_keys, field_name, PH_SEPARATE TSRMLS_CC);
			}
			
			PHALCON_INIT_NVAR(feature);
			PHALCON_CALL_METHOD(feature, column, "isnumeric", PH_NO_CHECK);
			if (PHALCON_IS_TRUE(feature)) {
				phalcon_array_update_zval_bool(&numeric_typed, field_name, 1, PH_SEPARATE TSRMLS_CC);
			}
			
			PHALCON_INIT_NVAR(feature);
			PHALCON_CALL_METHOD(feature, column, "isnotnull", PH_NO_CHECK);
			if (PHALCON_IS_TRUE(feature)) {
				phalcon_array_append(&not_null, field_name, PH_SEPARATE TSRMLS_CC);
			}
			
			PHALCON_INIT_NVAR(feature);
			PHALCON_CALL_METHOD(feature, column, "isautoincrement", PH_NO_CHECK);
			if (PHALCON_IS_TRUE(feature)) {
				PHALCON_CPY_WRT(identity_field, field_name);
			}
			
			PHALCON_INIT_NVAR(type);
			PHALCON_CALL_METHOD(type, column, "gettype", PH_NO_CHECK);
			phalcon_array_update_zval(&field_types, field_name, &type, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_NVAR(bind_type);
			PHALCON_CALL_METHOD(bind_type, column, "getbindtype", PH_NO_CHECK);
			phalcon_array_update_zval(&field_bind_types, field_name, &bind_type, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
			
		ph_cycle_end_0:
		
		PHALCON_INIT_VAR(table_metadata);
		array_init(table_metadata);
		phalcon_array_update_long(&table_metadata, 0, &attributes, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_long(&table_metadata, 1, &primary_keys, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_long(&table_metadata, 2, &non_primary_keys, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_long(&table_metadata, 3, &not_null, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_long(&table_metadata, 4, &field_types, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_long(&table_metadata, 5, &numeric_typed, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_long(&table_metadata, 8, &identity_field, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_long(&table_metadata, 9, &field_bind_types, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_VAR(t0);
		phalcon_read_property(&t0, this_ptr, SL("_metaData"), PH_NOISY_CC);
		phalcon_array_update_zval(&t0, key, &table_metadata, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_metaData"), t0 TSRMLS_CC);
		
		PHALCON_INIT_VAR(changed);
		phalcon_read_property(&changed, this_ptr, SL("_changed"), PH_NOISY_CC);
		if (!zend_is_true(changed)) {
			PHALCON_INIT_VAR(registered);
			phalcon_read_property(&registered, this_ptr, SL("_registered"), PH_NOISY_CC);
			if (PHALCON_IS_FALSE(registered)) {
				PHALCON_INIT_VAR(handler);
				array_init(handler);
				phalcon_array_append(&handler, this_ptr, PH_SEPARATE TSRMLS_CC);
				add_next_index_stringl(handler, SL("storeMetaData"), 1);
				PHALCON_CALL_FUNC_PARAMS_1_NORETURN("register_shutdown_function", handler);
				phalcon_update_property_bool(this_ptr, SL("_registered"), 1 TSRMLS_CC);
			}
			
			phalcon_update_property_bool(this_ptr, SL("_changed"), 1 TSRMLS_CC);
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns table attributes names (fields)
 *
 * @param Phalcon\Mvc\Model $model
 * @return 	array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAttributes){

	zval *model, *table, *schema, *key, *meta_data, *attributes;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A model instance is required to retrieve the meta-data");
		return;
	}
	
	PHALCON_INIT_VAR(table);
	PHALCON_CALL_METHOD(table, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, schema, table);
	
	PHALCON_INIT_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(r0);
	phalcon_array_fetch(&r0, meta_data, key, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(attributes);
	phalcon_array_fetch_long(&attributes, r0, 0, PH_NOISY_CC);
	
	RETURN_CCTOR(attributes);
}

/**
 * Returns an array of fields which are part of the primary key
 *
 * @param Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getPrimaryKeyAttributes){

	zval *model, *table, *schema, *key, *meta_data, *attributes;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A model instance is required to retrieve the meta-data");
		return;
	}
	
	PHALCON_INIT_VAR(table);
	PHALCON_CALL_METHOD(table, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, schema, table);
	
	PHALCON_INIT_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(r0);
	phalcon_array_fetch(&r0, meta_data, key, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(attributes);
	phalcon_array_fetch_long(&attributes, r0, 1, PH_NOISY_CC);
	
	RETURN_CCTOR(attributes);
}

/**
 * Returns an arrau of fields which are not part of the primary key
 *
 * @param Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes){

	zval *model, *table, *schema, *key, *meta_data, *attributes;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A model instance is required to retrieve the meta-data");
		return;
	}
	
	PHALCON_INIT_VAR(table);
	PHALCON_CALL_METHOD(table, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, schema, table);
	
	PHALCON_INIT_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(r0);
	phalcon_array_fetch(&r0, meta_data, key, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(attributes);
	phalcon_array_fetch_long(&attributes, r0, 2, PH_NOISY_CC);
	
	RETURN_CCTOR(attributes);
}

/**
 * Returns an array of not null attributes
 *
 * @param Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNotNullAttributes){

	zval *model, *table, *schema, *key, *meta_data, *attributes;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A model instance is required to retrieve the meta-data");
		return;
	}
	
	PHALCON_INIT_VAR(table);
	PHALCON_CALL_METHOD(table, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, schema, table);
	
	PHALCON_INIT_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(r0);
	phalcon_array_fetch(&r0, meta_data, key, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(attributes);
	phalcon_array_fetch_long(&attributes, r0, 3, PH_NOISY_CC);
	
	RETURN_CCTOR(attributes);
}

/**
 * Returns attributes and their data types
 *
 * @param Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypes){

	zval *model, *table, *schema, *key, *meta_data, *attributes;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A model instance is required to retrieve the meta-data");
		return;
	}
	
	PHALCON_INIT_VAR(table);
	PHALCON_CALL_METHOD(table, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, schema, table);
	
	PHALCON_INIT_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(r0);
	phalcon_array_fetch(&r0, meta_data, key, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(attributes);
	phalcon_array_fetch_long(&attributes, r0, 4, PH_NOISY_CC);
	
	RETURN_CCTOR(attributes);
}

/**
 * Returns attributes and their bind data types
 *
 * @param Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getBindTypes){

	zval *model, *table, *schema, *key, *meta_data, *attributes;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A model instance is required to retrieve the meta-data");
		return;
	}
	
	PHALCON_INIT_VAR(table);
	PHALCON_CALL_METHOD(table, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, schema, table);
	
	PHALCON_INIT_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(r0);
	phalcon_array_fetch(&r0, meta_data, key, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(attributes);
	phalcon_array_fetch_long(&attributes, r0, 9, PH_NOISY_CC);
	
	RETURN_CCTOR(attributes);
}

/**
 * Returns attributes which types are numerical
 *
 * @param  Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypesNumeric){

	zval *model, *table, *schema, *key, *meta_data, *attributes;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A model instance is required to retrieve the meta-data");
		return;
	}
	
	PHALCON_INIT_VAR(table);
	PHALCON_CALL_METHOD(table, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, schema, table);
	
	PHALCON_INIT_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(r0);
	phalcon_array_fetch(&r0, meta_data, key, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(attributes);
	phalcon_array_fetch_long(&attributes, r0, 5, PH_NOISY_CC);
	
	RETURN_CCTOR(attributes);
}

/**
 * Returns the name of identity field (if one is present)
 *
 * @param  Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getIdentityField){

	zval *model, *table, *schema, *key, *meta_data, *attributes;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A model instance is required to retrieve the meta-data");
		return;
	}
	
	PHALCON_INIT_VAR(table);
	PHALCON_CALL_METHOD(table, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_VV(key, schema, table);
	
	PHALCON_INIT_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(r0);
	phalcon_array_fetch(&r0, meta_data, key, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(attributes);
	phalcon_array_fetch_long(&attributes, r0, 8, PH_NOISY_CC);
	
	RETURN_CCTOR(attributes);
}

/**
 * Stores meta-data using to the internal adapter
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, storeMetaData){

	zval *changed, *meta_data;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(changed);
	phalcon_read_property(&changed, this_ptr, SL("_changed"), PH_NOISY_CC);
	if (zend_is_true(changed)) {
		PHALCON_INIT_VAR(meta_data);
		phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "write", meta_data, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if the internal meta-data container is empty
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, isEmpty){

	zval *meta_data, *number, *is_empty;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number);
	phalcon_fast_count(number, meta_data TSRMLS_CC);
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 0);
	
	PHALCON_INIT_VAR(is_empty);
	is_equal_function(is_empty, number, t0 TSRMLS_CC);
	
	RETURN_NCTOR(is_empty);
}

/**
 * Resets internal meta-data in order to regenerate it
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, reset){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, SL("_metaData"), a0 TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_changed"), 1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_MetaData, write){


	
}

