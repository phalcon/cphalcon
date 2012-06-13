
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_Model_MetaData
 *
 * Because Phalcon_Model requires meta-data like field names, data types, primary keys, etc.
 * this component collect them and store for further querying by Phalcon_Model_Base.
 * Phalcon_Model_MetaData can also use adapters to store temporarily or permanently the meta-data.
 *
 * A standard Phalcon_Model_MetaData can be used to query model attributes:
 *
 * 
 *
 */

/**
 * Phalcon_Model_MetaData constructor
 *
 * @param string $adapter
 * @param array $options
 */
PHP_METHOD(Phalcon_Model_MetaData, __construct){

	zval *adapter = NULL, *options = NULL, *adapter_class = NULL, *adapter_object = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &adapter, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(options, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_SV(r0, "Phalcon_Model_MetaData_", adapter);
	PHALCON_CPY_WRT(adapter_class, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", adapter_class, 0x012);
	if (zend_is_true(r1)) {
		ce0 = phalcon_fetch_class(adapter_class TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, ce0);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", options, PHALCON_CHECK);
		PHALCON_CPY_WRT(adapter_object, i0);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, adapter_object, "read", PHALCON_NO_CHECK);
		phalcon_update_property_zval(this_ptr, "_metaData", strlen("_metaData"), r2 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_adapter", strlen("_adapter"), adapter_object TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_model_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_SVS(r3, "Meta-data adapter '", adapter, "' could not found");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r3, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Model_MetaData, _initializeMetaData){

	zval *model = NULL, *table = NULL, *schema = NULL, *key = NULL, *connection = NULL, *is_view = NULL;
	zval *exists = NULL, *meta_datas = NULL, *attributes = NULL, *primary_keys = NULL;
	zval *non_primary_keys = NULL, *numeric_typed = NULL, *not_null = NULL;
	zval *field_types = NULL, *identity_field = NULL, *meta_data = NULL;
	zval *field_name = NULL, *type = NULL, *table_metadata = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL, *a4 = NULL, *a5 = NULL, *a6 = NULL;
	zval *a7 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &model, &table, &schema) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_VV(r0, schema, table);
	PHALCON_CPY_WRT(key, r0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY TSRMLS_CC);
	eval_int = phalcon_array_isset(t0, key);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CALL_METHOD(r1, model, "getconnection", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(connection, r1);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, model, "isview", PHALCON_NO_CHECK);
		PHALCON_CPY_WRT(is_view, r2);
		if (!zend_is_true(is_view)) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_CALL_METHOD_PARAMS_2(r3, connection, "tableexists", table, schema, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(exists, r3);
		} else {
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_METHOD_PARAMS_2(r4, connection, "viewexists", table, schema, PHALCON_NO_CHECK);
			PHALCON_CPY_WRT(exists, r4);
		}
		
		if (!zend_is_true(exists)) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_model_exception_ce);
			PHALCON_ALLOC_ZVAL_MM(r5);
			PHALCON_ALLOC_ZVAL_MM(r6);
			phalcon_get_class(r6, model TSRMLS_CC);
			PHALCON_CONCAT_SVSVSV(r5, "Table \"", schema, "\".\"", table, "\" doesn't exist on database when dumping information for ", r6);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r5, PHALCON_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
			return;
		} else {
			if (zend_is_true(is_view)) {
				PHALCON_ALLOC_ZVAL_MM(r7);
				PHALCON_CALL_METHOD_PARAMS_2(r7, connection, "describeview", table, schema, PHALCON_NO_CHECK);
				PHALCON_CPY_WRT(meta_datas, r7);
			} else {
				PHALCON_ALLOC_ZVAL_MM(r8);
				PHALCON_CALL_METHOD_PARAMS_2(r8, connection, "describetable", table, schema, PHALCON_NO_CHECK);
				PHALCON_CPY_WRT(meta_datas, r8);
			}
			
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			PHALCON_CPY_WRT(attributes, a0);
			
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			PHALCON_CPY_WRT(primary_keys, a1);
			
			PHALCON_INIT_VAR(a2);
			array_init(a2);
			PHALCON_CPY_WRT(non_primary_keys, a2);
			
			PHALCON_INIT_VAR(a3);
			array_init(a3);
			PHALCON_CPY_WRT(numeric_typed, a3);
			
			PHALCON_INIT_VAR(a4);
			array_init(a4);
			PHALCON_CPY_WRT(not_null, a4);
			
			PHALCON_INIT_VAR(a5);
			array_init(a5);
			PHALCON_CPY_WRT(field_types, a5);
			
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
				PHALCON_INIT_VAR(r9);
				phalcon_array_fetch_string(&r9, meta_data, "Field", strlen("Field"), PHALCON_NOISY TSRMLS_CC);
				PHALCON_CPY_WRT(field_name, r9);
				phalcon_array_append(&attributes, field_name, PHALCON_SEPARATE_PLZ TSRMLS_CC);
				
				PHALCON_INIT_VAR(r10);
				phalcon_array_fetch_string(&r10, meta_data, "Key", strlen("Key"), PHALCON_NOISY TSRMLS_CC);
				if (PHALCON_COMPARE_STRING(r10, "PRI")) {
					phalcon_array_append(&primary_keys, field_name, PHALCON_SEPARATE_PLZ TSRMLS_CC);
				} else {
					phalcon_array_append(&non_primary_keys, field_name, PHALCON_SEPARATE_PLZ TSRMLS_CC);
				}
				
				PHALCON_INIT_VAR(r11);
				phalcon_array_fetch_string(&r11, meta_data, "Type", strlen("Type"), PHALCON_NOISY TSRMLS_CC);
				PHALCON_CPY_WRT(type, r11);
				phalcon_array_update(&field_types, field_name, &type, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, "int", 1);
				
				PHALCON_INIT_VAR(r12);
				phalcon_fast_strpos(r12, type, c0 TSRMLS_CC);
				if (Z_TYPE_P(r12) != IS_BOOL || (Z_TYPE_P(r12) == IS_BOOL && Z_BVAL_P(r12))) {
					PHALCON_INIT_VAR(t1);
					ZVAL_BOOL(t1, 1);
					phalcon_array_update(&numeric_typed, field_name, &t1, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(c1);
					ZVAL_STRING(c1, "decimal", 1);
					PHALCON_INIT_VAR(r13);
					phalcon_fast_strpos(r13, type, c1 TSRMLS_CC);
					if (Z_TYPE_P(r13) != IS_BOOL || (Z_TYPE_P(r13) == IS_BOOL && Z_BVAL_P(r13))) {
						PHALCON_INIT_VAR(t2);
						ZVAL_BOOL(t2, 1);
						phalcon_array_update(&numeric_typed, field_name, &t2, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
					}
				}
				
				PHALCON_INIT_VAR(r14);
				phalcon_array_fetch_string(&r14, meta_data, "Null", strlen("Null"), PHALCON_NOISY TSRMLS_CC);
				if (PHALCON_COMPARE_STRING(r14, "NO")) {
					phalcon_array_append(&not_null, field_name, PHALCON_SEPARATE_PLZ TSRMLS_CC);
				}
				
				PHALCON_INIT_VAR(r15);
				phalcon_array_fetch_string(&r15, meta_data, "Extra", strlen("Extra"), PHALCON_NOISY TSRMLS_CC);
				if (PHALCON_COMPARE_STRING(r15, "auto_increment")) {
					PHALCON_CPY_WRT(identity_field, field_name);
				}
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_f5c6_0;
				fee_f5c6_0:
				if(0){}
			} else {
				return;
			}
			
			PHALCON_INIT_VAR(a6);
			array_init(a6);
			PHALCON_CPY_WRT(table_metadata, a6);
			phalcon_array_update_long(&table_metadata, 0, &attributes, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			phalcon_array_update_long(&table_metadata, 1, &primary_keys, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			phalcon_array_update_long(&table_metadata, 2, &non_primary_keys, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			phalcon_array_update_long(&table_metadata, 3, &not_null, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			phalcon_array_update_long(&table_metadata, 4, &field_types, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			phalcon_array_update_long(&table_metadata, 5, &numeric_typed, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			phalcon_array_update_long(&table_metadata, 8, &identity_field, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(t3);
			phalcon_read_property(&t3, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY TSRMLS_CC);
			phalcon_array_update(&t3, key, &table_metadata, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_metaData", strlen("_metaData"), t3 TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(t4);
			phalcon_read_property(&t4, this_ptr, "_changed", sizeof("_changed")-1, PHALCON_NOISY TSRMLS_CC);
			if (!zend_is_true(t4)) {
				PHALCON_INIT_VAR(a7);
				array_init(a7);
				phalcon_array_append(&a7, this_ptr, PHALCON_SEPARATE_PLZ TSRMLS_CC);
				add_next_index_stringl(a7, "storeMetaData", strlen("storeMetaData"), 1);
				PHALCON_CALL_FUNC_PARAMS_1_NORETURN("register_shutdown_function", a7, 0x044);
				phalcon_update_property_bool(this_ptr, "_changed", strlen("_changed"), 1 TSRMLS_CC);
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
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, model, "getsource", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(table, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, model, "getschema", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(schema, r1);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_VV(r2, schema, table);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 0, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns an array of fields which are part of the primary key
 *
 * @param Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getPrimaryKeyAttributes){

	zval *model = NULL, *table = NULL, *schema = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, model, "getsource", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(table, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, model, "getschema", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(schema, r1);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_VV(r2, schema, table);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns an arrau of fields which are not part of the primary key
 *
     * @param Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getNonPrimaryKeyAttributes){

	zval *model = NULL, *table = NULL, *schema = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, model, "getsource", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(table, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, model, "getschema", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(schema, r1);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_VV(r2, schema, table);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 2, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns an array of not null attributes
 *
     * @param Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getNotNullAttributes){

	zval *model = NULL, *table = NULL, *schema = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, model, "getsource", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(table, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, model, "getschema", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(schema, r1);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_VV(r2, schema, table);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 3, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns attributes and their data types
 *
     * @param Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getDataTypes){

	zval *model = NULL, *table = NULL, *schema = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, model, "getsource", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(table, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, model, "getschema", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(schema, r1);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_VV(r2, schema, table);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 4, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns attributes which types are numerical
 *
     * @param  Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getDataTypesNumeric){

	zval *model = NULL, *table = NULL, *schema = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, model, "getsource", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(table, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, model, "getschema", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(schema, r1);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_VV(r2, schema, table);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 5, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Returns the name of identity field (if one is present)
 *
 * @param  Phalcon_Model_Base $model
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData, getIdentityField){

	zval *model = NULL, *table = NULL, *schema = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, model, "getsource", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(table, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_METHOD(r1, model, "getschema", PHALCON_NO_CHECK);
	PHALCON_CPY_WRT(schema, r1);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(this_ptr, "_initializemetadata", model, table, schema, PHALCON_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CONCAT_VV(r2, schema, table);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_array_fetch(&r3, t0, r2, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	phalcon_array_fetch_long(&r4, r3, 8, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(r4);
}

/**
 * Stores meta-data using to the internal adapter
 */
PHP_METHOD(Phalcon_Model_MetaData, storeMetaData){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_changed", sizeof("_changed")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, "_adapter", sizeof("_adapter")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(t1, "write", t2, PHALCON_NO_CHECK);
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
	phalcon_read_property(&t0, this_ptr, "_metaData", sizeof("_metaData")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_fast_count(r0, t0 TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_LONG(t1, 0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, r0, t1 TSRMLS_CC);
	
	PHALCON_RETURN_NCTOR(r1);
}

/**
 * Resets internal meta-data to regenerate it
 */
PHP_METHOD(Phalcon_Model_MetaData, reset){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, "_metaData", strlen("_metaData"), a0 TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, "_changed", strlen("_changed"), 1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

