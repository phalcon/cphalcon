
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"

/**
 * Phalcon\Model\MetaData
 *
 * Because Phalcon\Model requires meta-data like field names, data types, primary keys, etc.
 * this component collect them and store for further querying by Phalcon\Model\Base.
 * Phalcon\Model\MetaData can also use adapters to store temporarily or permanently the meta-data.
 *
 * A standard Phalcon\Model\MetaData can be used to query model attributes:
 *
 * 
 *
 */

/**
 * Phalcon\Model\MetaData constructor
 *
 * @param string $adapter
 * @param array $options
 */
PHP_METHOD(Phalcon_Model_MetaData, __construct){

	zval *adapter = NULL, *options = NULL, *adapter_class = NULL, *adapter_object = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &adapter, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		PHALCON_CPY_WRT(options, a0);
	}
	
	PHALCON_INIT_VAR(adapter_class);
	PHALCON_CONCAT_SV(adapter_class, "Phalcon\\Model\\MetaData\\", adapter);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "class_exists", adapter_class);
	if (zend_is_true(r0)) {
		ce0 = phalcon_fetch_class(adapter_class TSRMLS_CC);
		PHALCON_INIT_VAR(adapter_object);
		object_init_ex(adapter_object, ce0);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(adapter_object, "__construct", options, PH_CHECK);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, adapter_object, "read", PH_NO_CHECK);
		phalcon_update_property_zval(this_ptr, SL("_metaData"), r1 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_adapter"), adapter_object TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_model_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_SVS(r2, "Meta-data adapter '", adapter, "' could not found");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r2, PH_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Model_MetaData, _initializeMetaData){

	zval *model = NULL, *table = NULL, *schema = NULL, *key = NULL, *connection = NULL, *is_view = NULL;
	zval *exists = NULL, *complete_table = NULL, *meta_datas = NULL, *attributes = NULL;
	zval *primary_keys = NULL, *non_primary_keys = NULL, *numeric_typed = NULL;
	zval *not_null = NULL, *field_types = NULL, *identity_field = NULL;
	zval *meta_data = NULL, *field_name = NULL, *type = NULL, *table_metadata = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;
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
		
		PHALCON_INIT_VAR(is_view);
		PHALCON_CALL_METHOD(is_view, model, "isview", PH_NO_CHECK);
		if (!zend_is_true(is_view)) {
			PHALCON_INIT_VAR(exists);
			PHALCON_CALL_METHOD_PARAMS_2(exists, connection, "tableexists", table, schema, PH_NO_CHECK);
		} else {
			PHALCON_INIT_VAR(exists);
			PHALCON_CALL_METHOD_PARAMS_2(exists, connection, "viewexists", table, schema, PH_NO_CHECK);
		}
		
		if (!zend_is_true(exists)) {
			if (zend_is_true(schema)) {
				PHALCON_INIT_VAR(complete_table);
				PHALCON_CONCAT_VSV(complete_table, schema, "\".\"", table);
			} else {
				PHALCON_CPY_WRT(complete_table, table);
			}
			
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_model_exception_ce);
			
			PHALCON_ALLOC_ZVAL_MM(r0);
			phalcon_get_class(r0, model TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CONCAT_SVSV(r1, "Table \"", complete_table, "\" doesn't exist on database when dumping meta-data for ", r0);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r1, PH_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
			return;
		} else {
			if (zend_is_true(is_view)) {
				PHALCON_INIT_VAR(meta_datas);
				PHALCON_CALL_METHOD_PARAMS_2(meta_datas, connection, "describeview", table, schema, PH_NO_CHECK);
			} else {
				PHALCON_INIT_VAR(meta_datas);
				PHALCON_CALL_METHOD_PARAMS_2(meta_datas, connection, "describetable", table, schema, PH_NO_CHECK);
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
			if (phalcon_valid_foreach(meta_datas TSRMLS_CC)) {
				ah0 = Z_ARRVAL_P(meta_datas);
				zend_hash_internal_pointer_reset_ex(ah0, &hp0);
				fes_f5c6_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_f5c6_0;
				}
				
				PHALCON_INIT_VAR(meta_data);
				ZVAL_ZVAL(meta_data, *hd, 1, 0);
				PHALCON_INIT_VAR(field_name);
				phalcon_array_fetch_string(&field_name, meta_data, SL("Field"), PH_NOISY_CC);
				phalcon_array_append(&attributes, field_name, PH_SEPARATE TSRMLS_CC);
				
				PHALCON_INIT_VAR(r2);
				phalcon_array_fetch_string(&r2, meta_data, SL("Key"), PH_NOISY_CC);
				if (PHALCON_COMPARE_STRING(r2, "PRI")) {
					phalcon_array_append(&primary_keys, field_name, PH_SEPARATE TSRMLS_CC);
				} else {
					phalcon_array_append(&non_primary_keys, field_name, PH_SEPARATE TSRMLS_CC);
				}
				
				PHALCON_INIT_VAR(type);
				phalcon_array_fetch_string(&type, meta_data, SL("Type"), PH_NOISY_CC);
				phalcon_array_update(&field_types, field_name, &type, PH_COPY | PH_SEPARATE TSRMLS_CC);
				
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, "char", 1);
				
				PHALCON_INIT_VAR(r3);
				phalcon_fast_strpos(r3, type, c0 TSRMLS_CC);
				if (Z_TYPE_P(r3) == IS_BOOL && !Z_BVAL_P(r3)) {
					PHALCON_INIT_VAR(c1);
					ZVAL_STRING(c1, "int", 1);
					PHALCON_INIT_VAR(r4);
					phalcon_fast_strpos(r4, type, c1 TSRMLS_CC);
					if (Z_TYPE_P(r4) != IS_BOOL || (Z_TYPE_P(r4) == IS_BOOL && Z_BVAL_P(r4))) {
						PHALCON_INIT_VAR(t1);
						ZVAL_BOOL(t1, 1);
						phalcon_array_update(&numeric_typed, field_name, &t1, PH_COPY | PH_SEPARATE TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(c2);
						ZVAL_STRING(c2, "decimal", 1);
						PHALCON_INIT_VAR(r5);
						phalcon_fast_strpos(r5, type, c2 TSRMLS_CC);
						if (Z_TYPE_P(r5) != IS_BOOL || (Z_TYPE_P(r5) == IS_BOOL && Z_BVAL_P(r5))) {
							PHALCON_INIT_VAR(t2);
							ZVAL_BOOL(t2, 1);
							phalcon_array_update(&numeric_typed, field_name, &t2, PH_COPY | PH_SEPARATE TSRMLS_CC);
						} else {
							PHALCON_INIT_VAR(c3);
							ZVAL_STRING(c3, "numeric", 1);
							PHALCON_INIT_VAR(r6);
							phalcon_fast_strpos(r6, type, c3 TSRMLS_CC);
							if (Z_TYPE_P(r6) != IS_BOOL || (Z_TYPE_P(r6) == IS_BOOL && Z_BVAL_P(r6))) {
								PHALCON_INIT_VAR(t3);
								ZVAL_BOOL(t3, 1);
								phalcon_array_update(&numeric_typed, field_name, &t3, PH_COPY | PH_SEPARATE TSRMLS_CC);
							}
						}
					}
				}
				
				PHALCON_INIT_VAR(r7);
				phalcon_array_fetch_string(&r7, meta_data, SL("Null"), PH_NOISY_CC);
				if (PHALCON_COMPARE_STRING(r7, "NO")) {
					phalcon_array_append(&not_null, field_name, PH_SEPARATE TSRMLS_CC);
				}
				
				PHALCON_INIT_VAR(r8);
				phalcon_array_fetch_string(&r8, meta_data, SL("Extra"), PH_NOISY_CC);
				if (PHALCON_COMPARE_STRING(r8, "auto_increment")) {
					PHALCON_CPY_WRT(identity_field, field_name);
				}
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_f5c6_0;
				fee_f5c6_0:
				if(0){}
			} else {
				return;
			}
			
			PHALCON_INIT_VAR(table_metadata);
			array_init(table_metadata);
			phalcon_array_update_long(&table_metadata, 0, &attributes, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_long(&table_metadata, 1, &primary_keys, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_long(&table_metadata, 2, &non_primary_keys, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_long(&table_metadata, 3, &not_null, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_long(&table_metadata, 4, &field_types, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_long(&table_metadata, 5, &numeric_typed, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_long(&table_metadata, 8, &identity_field, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_read_property(&t4, this_ptr, SL("_metaData"), PH_NOISY_CC);
			phalcon_array_update(&t4, key, &table_metadata, PH_COPY TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_metaData"), t4 TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(t5);
			phalcon_read_property(&t5, this_ptr, SL("_changed"), PH_NOISY_CC);
			if (!zend_is_true(t5)) {
				PHALCON_ALLOC_ZVAL_MM(a0);
				array_init(a0);
				phalcon_array_append(&a0, this_ptr, PH_SEPARATE TSRMLS_CC);
				add_next_index_stringl(a0, SL("storeMetaData"), 1);
				PHALCON_CALL_FUNC_PARAMS_1_NORETURN("register_shutdown_function", a0);
				phalcon_update_property_bool(this_ptr, SL("_changed"), 1 TSRMLS_CC);
			}
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns table attributes names (fields)
 *
 * @param Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getAttributes){

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
 * @param Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getPrimaryKeyAttributes){

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
 * @param Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getNonPrimaryKeyAttributes){

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
 * @param Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getNotNullAttributes){

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
 * @param Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getDataTypes){

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
 * @param  Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getDataTypesNumeric){

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
 * @param  Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getIdentityField){

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
PHP_METHOD(Phalcon_Model_MetaData, storeMetaData){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_changed"), PH_NOISY_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_adapter"), PH_NOISY_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, SL("_metaData"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(t1, "write", t2, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if the internal meta-data container is empty
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_MetaData, isEmpty){

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
PHP_METHOD(Phalcon_Model_MetaData, reset){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, SL("_metaData"), a0 TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_changed"), 1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

