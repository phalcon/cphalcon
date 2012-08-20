
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

#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/exception.h"

/**
 * Phalcon\Mvc\Model\MetaData
 *
 * Because Phalcon\Mvc\Model requires meta-data like field names, data types, primary keys, etc.
 * this component collect them and store for further querying by Phalcon\Model\Base.
 * Phalcon\Mvc\Model\MetaData can also use adapters to store temporarily or permanently the meta-data.
 *
 * A standard Phalcon\Mvc\Model\MetaData can be used to query model attributes:
 *
 * 
 *
 */

/**
 * Phalcon\Mvc\Model\MetaData constructor
 *
 * @param string $adapter
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, __construct){

	zval *options = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
		array_init(options);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "read", PH_NO_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_metaData"), r0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Initialize the metadata for certain table
 *
 * @param Phalcon\Mvc\Model $model
 * @param string $table
 * @param string $schema
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, _initializeMetaData){

	zval *model = NULL, *table = NULL, *schema = NULL, *key = NULL, *connection = NULL, *exists = NULL;
	zval *complete_table = NULL, *attributes = NULL, *primary_keys = NULL;
	zval *non_primary_keys = NULL, *numeric_typed = NULL, *not_null = NULL;
	zval *field_types = NULL, *identity_field = NULL, *columns = NULL;
	zval *column = NULL, *field_name = NULL, *table_metadata = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *a0 = NULL;
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
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_metaData"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, key);
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
			
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_mvc_model_exception_ce);
			
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_get_class(r0, model TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CONCAT_SVSV(r1, "Table \"", complete_table, "\" doesn't exist on database when dumping meta-data for ", r0);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r1, PH_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
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
		
		PHALCON_INIT_VAR(identity_field);
		ZVAL_BOOL(identity_field, 0);
		
		PHALCON_INIT_VAR(columns);
		PHALCON_CALL_METHOD_PARAMS_2(columns, connection, "describecolumns", table, schema, PH_NO_CHECK);
		if (!phalcon_valid_foreach(columns TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(columns);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_c40c_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_c40c_0;
			}
			
			PHALCON_INIT_VAR(column);
			ZVAL_ZVAL(column, *hd, 1, 0);
			PHALCON_INIT_VAR(field_name);
			PHALCON_CALL_METHOD(field_name, column, "getname", PH_NO_CHECK);
			phalcon_array_append(&attributes, field_name, PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(r2);
			PHALCON_CALL_METHOD(r2, column, "isprimary", PH_NO_CHECK);
			if (zend_is_true(r2)) {
				phalcon_array_append(&primary_keys, field_name, PH_SEPARATE TSRMLS_CC);
			} else {
				phalcon_array_append(&non_primary_keys, field_name, PH_SEPARATE TSRMLS_CC);
			}
			
			PHALCON_INIT_VAR(r3);
			PHALCON_CALL_METHOD(r3, column, "isnumeric", PH_NO_CHECK);
			if (zend_is_true(r3)) {
				phalcon_array_update_zval_bool(&numeric_typed, field_name, 1, PH_SEPARATE TSRMLS_CC);
			}
			
			PHALCON_INIT_VAR(r4);
			PHALCON_CALL_METHOD(r4, column, "isnotnull", PH_NO_CHECK);
			if (zend_is_true(r4)) {
				phalcon_array_append(&not_null, field_name, PH_SEPARATE TSRMLS_CC);
			}
			
			PHALCON_INIT_VAR(r5);
			PHALCON_CALL_METHOD(r5, column, "isautoincrement", PH_NO_CHECK);
			if (zend_is_true(r5)) {
				PHALCON_CPY_WRT(identity_field, field_name);
			}
			
			PHALCON_INIT_VAR(r6);
			PHALCON_CALL_METHOD(r6, column, "gettype", PH_NO_CHECK);
			phalcon_array_update_zval(&field_types, field_name, &r6, PH_COPY | PH_SEPARATE TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_c40c_0;
		fee_c40c_0:
		
		PHALCON_INIT_VAR(table_metadata);
		array_init(table_metadata);
		phalcon_array_update_long(&table_metadata, 0, &attributes, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_long(&table_metadata, 1, &primary_keys, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_long(&table_metadata, 2, &non_primary_keys, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_long(&table_metadata, 3, &not_null, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_long(&table_metadata, 4, &field_types, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_long(&table_metadata, 5, &numeric_typed, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_long(&table_metadata, 8, &identity_field, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_metaData"), PH_NOISY_CC);
		phalcon_array_update_zval(&t1, key, &table_metadata, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_metaData"), t1 TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, SL("_changed"), PH_NOISY_CC);
		if (!zend_is_true(t2)) {
			PHALCON_ALLOC_ZVAL_MM(a0);
			array_init(a0);
			phalcon_array_append(&a0, this_ptr, PH_SEPARATE TSRMLS_CC);
			add_next_index_stringl(a0, SL("storeMetaData"), 1);
			PHALCON_CALL_FUNC_PARAMS_1_NORETURN("register_shutdown_function", a0);
			phalcon_update_property_bool(this_ptr, SL("_changed"), 1 TSRMLS_CC);
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns table attributes names (fields)
 *
 * @param Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getAttributes){

	zval *model = NULL, *table = NULL, *schema = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(table);
	PHALCON_CALL_METHOD(table, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_VV(r0, schema, table);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t0, r0, PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, r1, 0, PH_NOISY_CC);
	
	RETURN_CCTOR(r2);
}

/**
 * Returns an array of fields which are part of the primary key
 *
 * @param Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getPrimaryKeyAttributes){

	zval *model = NULL, *table = NULL, *schema = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(table);
	PHALCON_CALL_METHOD(table, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_VV(r0, schema, table);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t0, r0, PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, r1, 1, PH_NOISY_CC);
	
	RETURN_CCTOR(r2);
}

/**
 * Returns an arrau of fields which are not part of the primary key
 *
 * @param Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNonPrimaryKeyAttributes){

	zval *model = NULL, *table = NULL, *schema = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(table);
	PHALCON_CALL_METHOD(table, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_VV(r0, schema, table);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t0, r0, PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, r1, 2, PH_NOISY_CC);
	
	RETURN_CCTOR(r2);
}

/**
 * Returns an array of not null attributes
 *
 * @param Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getNotNullAttributes){

	zval *model = NULL, *table = NULL, *schema = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(table);
	PHALCON_CALL_METHOD(table, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_VV(r0, schema, table);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t0, r0, PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, r1, 3, PH_NOISY_CC);
	
	RETURN_CCTOR(r2);
}

/**
 * Returns attributes and their data types
 *
 * @param Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypes){

	zval *model = NULL, *table = NULL, *schema = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(table);
	PHALCON_CALL_METHOD(table, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_VV(r0, schema, table);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t0, r0, PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, r1, 4, PH_NOISY_CC);
	
	RETURN_CCTOR(r2);
}

/**
 * Returns attributes which types are numerical
 *
 * @param  Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getDataTypesNumeric){

	zval *model = NULL, *table = NULL, *schema = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(table);
	PHALCON_CALL_METHOD(table, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_VV(r0, schema, table);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t0, r0, PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, r1, 5, PH_NOISY_CC);
	
	RETURN_CCTOR(r2);
}

/**
 * Returns the name of identity field (if one is present)
 *
 * @param  Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, getIdentityField){

	zval *model = NULL, *table = NULL, *schema = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(table);
	PHALCON_CALL_METHOD(table, model, "getsource", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, model, "getschema", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_VV(r0, schema, table);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_metaData"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, t0, r0, PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	phalcon_array_fetch_long(&r2, r1, 8, PH_NOISY_CC);
	
	RETURN_CCTOR(r2);
}

/**
 * Stores meta-data using to the internal adapter
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, storeMetaData){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_changed"), PH_NOISY_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_metaData"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "write", t1, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if the internal meta-data container is empty
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, isEmpty){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_metaData"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, t0 TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t1 TSRMLS_CC);
	
	RETURN_NCTOR(r1);
}

/**
 * Resets internal meta-data in order to regenerate it
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData, reset){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, SL("_metaData"), a0 TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_changed"), 1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

