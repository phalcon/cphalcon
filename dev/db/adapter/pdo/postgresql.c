
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
 * Phalcon\Db\Adapter\Pdo\Postgresql
 *
 * Specific functions for the Postgresql database system
 * 
 */

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection.
 *
 * Support set search_path after connectted if schema is specified in config.
 *
 * @param array $descriptor
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, connect){

	zval *descriptor = NULL, *schema = NULL, *sql = NULL;
	int has_schema;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &descriptor) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!descriptor) {
		PHALCON_ALLOC_ZVAL_MM(descriptor);
		ZVAL_NULL(descriptor);
	} else {
		PHALCON_SEPARATE_PARAM(descriptor);
	}

	if (!zend_is_true(descriptor)) {
		PHALCON_INIT_VAR(descriptor);
		phalcon_read_property(&descriptor, this_ptr, SL("_descriptor"), PH_NOISY_CC);
	}

	has_schema = phalcon_array_isset_string(descriptor, SL("schema")+1);
	if (has_schema) {
		PHALCON_INIT_VAR(schema);
		phalcon_array_fetch_string(&schema, descriptor, SL("schema"), PH_NOISY_CC);
		PHALCON_SEPARATE_PARAM(descriptor);
		phalcon_array_unset_string(descriptor, SL("schema")+1);
	}

    PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon\\Db\\Adapter\\Pdo\\Postgresql", "connect", descriptor);

	if (has_schema) {
        PHALCON_INIT_VAR(sql);
        PHALCON_CONCAT_SVS(sql, "SET search_path TO '", schema, "'");
        PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "execute", sql, PH_NO_CHECK);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Returns an array of Phalcon\Db\Column objects describing a table
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\Column[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns){

	zval *table = NULL, *schema = NULL, *columns = NULL, *sql = NULL, *describe = NULL, *old_column = NULL;
	zval *field = NULL, *definition = NULL, *column_type = NULL, *matches = NULL;
	zval *column_name = NULL, *column = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL;
	zval *c0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema) {
		PHALCON_ALLOC_ZVAL_MM(schema);
		ZVAL_NULL(schema);
	}
	
	PHALCON_INIT_VAR(columns);
	array_init(columns);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, t0, "describecolumns", table, schema, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_db_ce, SL("FETCH_ASSOC") TSRMLS_CC);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, t1, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(old_column);
	ZVAL_NULL(old_column);
	if (!phalcon_valid_foreach(describe TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(describe);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_0ac0_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_0ac0_0;
		}
		
		PHALCON_INIT_VAR(field);
		ZVAL_ZVAL(field, *hd, 1, 0);
		PHALCON_INIT_VAR(definition);
		array_init(definition);
		
		PHALCON_INIT_VAR(column_type);
		phalcon_array_fetch_string(&column_type, field, SL("type"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(r0);
		phalcon_fast_strpos_str(r0, column_type, SL("int") TSRMLS_CC);
		if (Z_TYPE_P(r0) != IS_BOOL || (Z_TYPE_P(r0) == IS_BOOL && Z_BVAL_P(r0))) {
			phalcon_array_update_string_long(&definition, SL("type"), 0, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(r1);
			phalcon_fast_strpos_str(r1, column_type, SL("varying") TSRMLS_CC);
			if (Z_TYPE_P(r1) != IS_BOOL || (Z_TYPE_P(r1) == IS_BOOL && Z_BVAL_P(r1))) {
				phalcon_array_update_string_long(&definition, SL("type"), 2, PH_SEPARATE TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(r2);
				phalcon_fast_strpos_str(r2, column_type, SL("date") TSRMLS_CC);
				if (Z_TYPE_P(r2) != IS_BOOL || (Z_TYPE_P(r2) == IS_BOOL && Z_BVAL_P(r2))) {
					phalcon_array_update_string_long(&definition, SL("type"), 1, PH_SEPARATE TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(r3);
					phalcon_fast_strpos_str(r3, column_type, SL("numeric") TSRMLS_CC);
					if (Z_TYPE_P(r3) != IS_BOOL || (Z_TYPE_P(r3) == IS_BOOL && Z_BVAL_P(r3))) {
						phalcon_array_update_string_long(&definition, SL("type"), 3, PH_SEPARATE TSRMLS_CC);
						phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(r4);
						phalcon_fast_strpos_str(r4, column_type, SL("char") TSRMLS_CC);
						if (Z_TYPE_P(r4) != IS_BOOL || (Z_TYPE_P(r4) == IS_BOOL && Z_BVAL_P(r4))) {
							phalcon_array_update_string_long(&definition, SL("type"), 5, PH_SEPARATE TSRMLS_CC);
						} else {
							PHALCON_INIT_VAR(r5);
							phalcon_fast_strpos_str(r5, column_type, SL("timestamp") TSRMLS_CC);
							if (Z_TYPE_P(r5) != IS_BOOL || (Z_TYPE_P(r5) == IS_BOOL && Z_BVAL_P(r5))) {
								phalcon_array_update_string_long(&definition, SL("type"), 4, PH_SEPARATE TSRMLS_CC);
							} else {
								PHALCON_INIT_VAR(r6);
								phalcon_fast_strpos_str(r6, column_type, SL("text") TSRMLS_CC);
								if (Z_TYPE_P(r6) != IS_BOOL || (Z_TYPE_P(r6) == IS_BOOL && Z_BVAL_P(r6))) {
									phalcon_array_update_string_long(&definition, SL("type"), 6, PH_SEPARATE TSRMLS_CC);
								} else {
									PHALCON_INIT_VAR(r7);
									phalcon_fast_strpos_str(r7, column_type, SL("float") TSRMLS_CC);
									if (Z_TYPE_P(r7) != IS_BOOL || (Z_TYPE_P(r7) == IS_BOOL && Z_BVAL_P(r7))) {
										phalcon_array_update_string_long(&definition, SL("type"), 7, PH_SEPARATE TSRMLS_CC);
										phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
									} else {
										phalcon_array_update_string_long(&definition, SL("type"), 2, PH_SEPARATE TSRMLS_CC);
									}
								}
							}
						}
					}
				}
			}
		}
		
		PHALCON_INIT_VAR(r8);
		phalcon_fast_strpos_str(r8, column_type, SL("(") TSRMLS_CC);
		if (Z_TYPE_P(r8) != IS_BOOL || (Z_TYPE_P(r8) == IS_BOOL && Z_BVAL_P(r8))) {
			PHALCON_INIT_VAR(matches);
			array_init(matches);
			
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "#\\(([0-9]+)(,[0-9]+)*\\)#", 1);
			Z_SET_ISREF_P(matches);
			
			PHALCON_INIT_VAR(r9);
			PHALCON_CALL_FUNC_PARAMS_3(r9, "preg_match", c0, column_type, matches);
			Z_UNSET_ISREF_P(matches);
			if (zend_is_true(r9)) {
				eval_int = phalcon_array_isset_long(matches, 1);
				if (eval_int) {
					PHALCON_INIT_VAR(r10);
					phalcon_array_fetch_long(&r10, matches, 1, PH_NOISY_CC);
					phalcon_array_update_string(&definition, SL("size"), &r10, PH_COPY | PH_SEPARATE TSRMLS_CC);
				}
			}
		}
		
		PHALCON_INIT_VAR(r11);
		phalcon_fast_strpos_str(r11, column_type, SL("unsigned") TSRMLS_CC);
		if (zend_is_true(r11)) {
			phalcon_array_update_string_bool(&definition, SL("unsigned"), 1, PH_SEPARATE TSRMLS_CC);
		}
		
		if (!zend_is_true(old_column)) {
			phalcon_array_update_string_bool(&definition, SL("first"), 1, PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_string(&definition, SL("after"), &old_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(r12);
		phalcon_array_fetch_string(&r12, field, SL("key"), PH_NOISY_CC);
		if (PHALCON_COMPARE_STRING(r12, "PRI")) {
			phalcon_array_update_string_bool(&definition, SL("primary"), 1, PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(r13);
		phalcon_array_fetch_string(&r13, field, SL("null"), PH_NOISY_CC);
		if (PHALCON_COMPARE_STRING(r13, "NO")) {
			phalcon_array_update_string_bool(&definition, SL("notNull"), 1, PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(r14);
		phalcon_array_fetch_string(&r14, field, SL("extra"), PH_NOISY_CC);
		if (PHALCON_COMPARE_STRING(r14, "auto_increment")) {
			phalcon_array_update_string_bool(&definition, SL("autoIncrement"), 1, PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(column_name);
		phalcon_array_fetch_string(&column_name, field, SL("field"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(column);
		object_init_ex(column, phalcon_db_column_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(column, "__construct", column_name, definition, PH_CHECK);
		phalcon_array_append(&columns, column, PH_SEPARATE TSRMLS_CC);
		PHALCON_CPY_WRT(old_column, column_name);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_0ac0_0;
	fee_0ac0_0:
	
	
	RETURN_CTOR(columns);
}

/**
 * Lists table indexes
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\Index[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeIndexes){

	zval *table = NULL, *schema = NULL, *sql = NULL, *describe = NULL, *indexes = NULL, *index = NULL;
	zval *key_name = NULL, *index_objects = NULL, *index_columns = NULL;
	zval *name = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL;
	zval *i0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema) {
		PHALCON_ALLOC_ZVAL_MM(schema);
		ZVAL_NULL(schema);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, t0, "describeindexes", table, schema, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_db_ce, SL("FETCH_ASSOC") TSRMLS_CC);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, t1, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(indexes);
	array_init(indexes);
	if (!phalcon_valid_foreach(describe TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(describe);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_0ac0_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_0ac0_1;
		}
		
		PHALCON_INIT_VAR(index);
		ZVAL_ZVAL(index, *hd, 1, 0);
		PHALCON_INIT_VAR(key_name);
		phalcon_array_fetch_string(&key_name, index, SL("key_name"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(indexes, key_name);
		if (!eval_int) {
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			phalcon_array_update_zval(&indexes, key_name, &a0, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch_string(&r0, index, SL("column_name"), PH_NOISY_CC);
		phalcon_array_update_multi_append_2(&indexes, key_name, r0, 0 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_0ac0_1;
	fee_0ac0_1:
	
	PHALCON_INIT_VAR(index_objects);
	array_init(index_objects);
	if (!phalcon_valid_foreach(indexes TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(indexes);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	fes_0ac0_2:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_0ac0_2;
		}
		
		PHALCON_INIT_VAR(name);
		PHALCON_GET_FOREACH_KEY(name, ah1, hp1);
		PHALCON_INIT_VAR(index_columns);
		ZVAL_ZVAL(index_columns, *hd, 1, 0);
		PHALCON_INIT_VAR(i0);
		object_init_ex(i0, phalcon_db_index_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", name, index_columns, PH_CHECK);
		phalcon_array_update_zval(&index_objects, name, &i0, PH_COPY | PH_SEPARATE TSRMLS_CC);
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_0ac0_2;
	fee_0ac0_2:
	
	
	RETURN_CTOR(index_objects);
}

/**
 * Lists table references
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\Reference[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeReferences){

	zval *table = NULL, *schema = NULL, *sql = NULL, *references = NULL, *describe = NULL;
	zval *reference = NULL, *constraint_name = NULL, *reference_objects = NULL;
	zval *array_reference = NULL, *name = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *i0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema) {
		PHALCON_ALLOC_ZVAL_MM(schema);
		ZVAL_NULL(schema);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, t0, "describereferences", table, schema, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(references);
	array_init(references);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_db_ce, SL("FETCH_ASSOC") TSRMLS_CC);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, t1, PH_NO_CHECK);
	if (!phalcon_valid_foreach(describe TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(describe);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_0ac0_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_0ac0_3;
		}
		
		PHALCON_INIT_VAR(reference);
		ZVAL_ZVAL(reference, *hd, 1, 0);
		PHALCON_INIT_VAR(constraint_name);
		phalcon_array_fetch_string(&constraint_name, reference, SL("constraint_name"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(references, constraint_name);
		if (!eval_int) {
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			PHALCON_INIT_VAR(r0);
			phalcon_array_fetch_string(&r0, reference, SL("referenced_table_schema"), PH_NOISY_CC);
			phalcon_array_update_string(&a0, SL("referencedSchema"), &r0, PH_COPY | PH_SEPARATE TSRMLS_CC);
			PHALCON_INIT_VAR(r1);
			phalcon_array_fetch_string(&r1, reference, SL("referenced_table_name"), PH_NOISY_CC);
			phalcon_array_update_string(&a0, SL("referencedTable"), &r1, PH_COPY | PH_SEPARATE TSRMLS_CC);
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			phalcon_array_update_string(&a0, SL("columns"), &a1, PH_COPY | PH_SEPARATE TSRMLS_CC);
			PHALCON_INIT_VAR(a2);
			array_init(a2);
			phalcon_array_update_string(&a0, SL("referencedColumns"), &a2, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&references, constraint_name, &a0, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch_string(&r2, reference, SL("column_name"), PH_NOISY_CC);
		if (Z_TYPE_P(references) == IS_ARRAY) {
			PHALCON_INIT_VAR(t2);
			phalcon_array_fetch(&t2, references, constraint_name, PH_SILENT_CC);
		}
		if (Z_REFCOUNT_P(t2) > 1) {
			phalcon_array_update_zval(&references, constraint_name, &t2, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t2) != IS_ARRAY) {
			convert_to_array(t2);
			phalcon_array_update_zval(&references, constraint_name, &t2, PH_COPY TSRMLS_CC);
		}
		if (Z_TYPE_P(t2) == IS_ARRAY) {
			PHALCON_INIT_VAR(t3);
			phalcon_array_fetch_string(&t3, t2, SL("columns"), PH_SILENT_CC);
		}
		if (Z_REFCOUNT_P(t3) > 1) {
			phalcon_array_update_string(&t2, SL("columns"), &t3, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t3) != IS_ARRAY) {
			convert_to_array(t3);
			phalcon_array_update_string(&t2, SL("columns"), &t3, PH_COPY TSRMLS_CC);
		}
		phalcon_array_append(&t3, r2, 0 TSRMLS_CC);
		
		PHALCON_INIT_VAR(r3);
		phalcon_array_fetch_string(&r3, reference, SL("referenced_column_name"), PH_NOISY_CC);
		if (Z_TYPE_P(references) == IS_ARRAY) {
			PHALCON_INIT_VAR(t4);
			phalcon_array_fetch(&t4, references, constraint_name, PH_SILENT_CC);
		}
		if (Z_REFCOUNT_P(t4) > 1) {
			phalcon_array_update_zval(&references, constraint_name, &t4, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t4) != IS_ARRAY) {
			convert_to_array(t4);
			phalcon_array_update_zval(&references, constraint_name, &t4, PH_COPY TSRMLS_CC);
		}
		if (Z_TYPE_P(t4) == IS_ARRAY) {
			PHALCON_INIT_VAR(t5);
			phalcon_array_fetch_string(&t5, t4, SL("referencedColumns"), PH_SILENT_CC);
		}
		if (Z_REFCOUNT_P(t5) > 1) {
			phalcon_array_update_string(&t4, SL("referencedColumns"), &t5, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t5) != IS_ARRAY) {
			convert_to_array(t5);
			phalcon_array_update_string(&t4, SL("referencedColumns"), &t5, PH_COPY TSRMLS_CC);
		}
		phalcon_array_append(&t5, r3, 0 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_0ac0_3;
	fee_0ac0_3:
	
	PHALCON_INIT_VAR(reference_objects);
	array_init(reference_objects);
	if (!phalcon_valid_foreach(references TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(references);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	fes_0ac0_4:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_0ac0_4;
		}
		
		PHALCON_INIT_VAR(name);
		PHALCON_GET_FOREACH_KEY(name, ah1, hp1);
		PHALCON_INIT_VAR(array_reference);
		ZVAL_ZVAL(array_reference, *hd, 1, 0);
		PHALCON_INIT_VAR(i0);
		object_init_ex(i0, phalcon_db_reference_ce);
		PHALCON_INIT_VAR(a3);
		array_init(a3);
		PHALCON_INIT_VAR(r4);
		phalcon_array_fetch_string(&r4, array_reference, SL("referencedSchema"), PH_NOISY_CC);
		phalcon_array_update_string(&a3, SL("referencedSchema"), &r4, PH_COPY | PH_SEPARATE TSRMLS_CC);
		PHALCON_INIT_VAR(r5);
		phalcon_array_fetch_string(&r5, array_reference, SL("referencedTable"), PH_NOISY_CC);
		phalcon_array_update_string(&a3, SL("referencedTable"), &r5, PH_COPY | PH_SEPARATE TSRMLS_CC);
		PHALCON_INIT_VAR(r6);
		phalcon_array_fetch_string(&r6, array_reference, SL("columns"), PH_NOISY_CC);
		phalcon_array_update_string(&a3, SL("columns"), &r6, PH_COPY | PH_SEPARATE TSRMLS_CC);
		PHALCON_INIT_VAR(r7);
		phalcon_array_fetch_string(&r7, array_reference, SL("referencedColumns"), PH_NOISY_CC);
		phalcon_array_update_string(&a3, SL("referencedColumns"), &r7, PH_COPY | PH_SEPARATE TSRMLS_CC);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", name, a3, PH_CHECK);
		phalcon_array_update_zval(&reference_objects, name, &i0, PH_COPY | PH_SEPARATE TSRMLS_CC);
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_0ac0_4;
	fee_0ac0_4:
	
	
	RETURN_CTOR(reference_objects);
}

/**
 * Gets creation options from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, tableOptions){

	zval *table_name = NULL, *schema_name = NULL, *sql = NULL, *references = NULL;
	zval *describe = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		PHALCON_ALLOC_ZVAL_MM(schema_name);
		ZVAL_NULL(schema_name);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, t0, "tableoptions", table_name, schema_name, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(references);
	array_init(references);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_db_ce, SL("FETCH_ASSOC") TSRMLS_CC);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, t1, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_long(&r0, describe, 0, PH_NOISY_CC);
	
	RETURN_CCTOR(r0);
}

