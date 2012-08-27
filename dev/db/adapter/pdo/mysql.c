
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

#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"

/**
 * Phalcon\Db\Adapter\Pdo\Mysql
 *
 * Specific functions for the Mysql database system
 * 
 */

/**
 * Returns an array of Phalcon\Db\Column objects describing a table
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\Column[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns){

	zval *table = NULL, *schema = NULL, *columns = NULL, *dialect = NULL, *sql = NULL, *describe = NULL;
	zval *old_column = NULL, *field = NULL, *definition = NULL, *column_type = NULL;
	zval *pos = NULL, *matches = NULL, *match_one = NULL, *attribute = NULL, *column_name = NULL;
	zval *column = NULL;
	zval *t0 = NULL;
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
	
	PHALCON_INIT_VAR(dialect);
	phalcon_read_property(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "describecolumns", table, schema, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_db_ce, SL("FETCH_ASSOC") TSRMLS_CC);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, t0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(old_column);
	ZVAL_NULL(old_column);
	if (!phalcon_valid_foreach(describe TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(describe);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_ecef_0:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_ecef_0;
		}
		
		PHALCON_INIT_VAR(field);
		ZVAL_ZVAL(field, *hd, 1, 0);
		PHALCON_INIT_VAR(definition);
		array_init(definition);
		
		PHALCON_INIT_VAR(column_type);
		phalcon_array_fetch_string(&column_type, field, SL("type"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(pos);
		phalcon_fast_strpos_str(pos, column_type, SL("int") TSRMLS_CC);
		if (Z_TYPE_P(pos) != IS_BOOL || (Z_TYPE_P(pos) == IS_BOOL && Z_BVAL_P(pos))) {
			phalcon_array_update_string_long(&definition, SL("type"), 0, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(pos);
			phalcon_fast_strpos_str(pos, column_type, SL("varchar") TSRMLS_CC);
			if (Z_TYPE_P(pos) != IS_BOOL || (Z_TYPE_P(pos) == IS_BOOL && Z_BVAL_P(pos))) {
				phalcon_array_update_string_long(&definition, SL("type"), 2, PH_SEPARATE TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(pos);
				phalcon_fast_strpos_str(pos, column_type, SL("date") TSRMLS_CC);
				if (Z_TYPE_P(pos) != IS_BOOL || (Z_TYPE_P(pos) == IS_BOOL && Z_BVAL_P(pos))) {
					phalcon_array_update_string_long(&definition, SL("type"), 1, PH_SEPARATE TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(pos);
					phalcon_fast_strpos_str(pos, column_type, SL("decimal") TSRMLS_CC);
					if (Z_TYPE_P(pos) != IS_BOOL || (Z_TYPE_P(pos) == IS_BOOL && Z_BVAL_P(pos))) {
						phalcon_array_update_string_long(&definition, SL("type"), 3, PH_SEPARATE TSRMLS_CC);
						phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(pos);
						phalcon_fast_strpos_str(pos, column_type, SL("char") TSRMLS_CC);
						if (Z_TYPE_P(pos) != IS_BOOL || (Z_TYPE_P(pos) == IS_BOOL && Z_BVAL_P(pos))) {
							phalcon_array_update_string_long(&definition, SL("type"), 5, PH_SEPARATE TSRMLS_CC);
						} else {
							PHALCON_INIT_VAR(pos);
							phalcon_fast_strpos_str(pos, column_type, SL("datetime") TSRMLS_CC);
							if (Z_TYPE_P(pos) != IS_BOOL || (Z_TYPE_P(pos) == IS_BOOL && Z_BVAL_P(pos))) {
								phalcon_array_update_string_long(&definition, SL("type"), 4, PH_SEPARATE TSRMLS_CC);
							} else {
								PHALCON_INIT_VAR(pos);
								phalcon_fast_strpos_str(pos, column_type, SL("text") TSRMLS_CC);
								if (Z_TYPE_P(pos) != IS_BOOL || (Z_TYPE_P(pos) == IS_BOOL && Z_BVAL_P(pos))) {
									phalcon_array_update_string_long(&definition, SL("type"), 6, PH_SEPARATE TSRMLS_CC);
								} else {
									PHALCON_INIT_VAR(pos);
									phalcon_fast_strpos_str(pos, column_type, SL("float") TSRMLS_CC);
									if (Z_TYPE_P(pos) != IS_BOOL || (Z_TYPE_P(pos) == IS_BOOL && Z_BVAL_P(pos))) {
										phalcon_array_update_string_long(&definition, SL("type"), 7, PH_SEPARATE TSRMLS_CC);
										phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
									} else {
										PHALCON_INIT_VAR(pos);
										phalcon_fast_strpos_str(pos, column_type, SL("enum") TSRMLS_CC);
										if (Z_TYPE_P(pos) != IS_BOOL || (Z_TYPE_P(pos) == IS_BOOL && Z_BVAL_P(pos))) {
											phalcon_array_update_string_long(&definition, SL("type"), 5, PH_SEPARATE TSRMLS_CC);
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
		}
		
		PHALCON_INIT_VAR(pos);
		phalcon_fast_strpos_str(pos, column_type, SL("(") TSRMLS_CC);
		if (Z_TYPE_P(pos) != IS_BOOL || (Z_TYPE_P(pos) == IS_BOOL && Z_BVAL_P(pos))) {
			PHALCON_INIT_VAR(matches);
			array_init(matches);
			
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "#\\(([0-9]+)(,[0-9]+)*\\)#", 1);
			Z_SET_ISREF_P(matches);
			
			PHALCON_INIT_VAR(pos);
			PHALCON_CALL_FUNC_PARAMS_3(pos, "preg_match", c0, column_type, matches);
			Z_UNSET_ISREF_P(matches);
			if (zend_is_true(pos)) {
				eval_int = phalcon_array_isset_long(matches, 1);
				if (eval_int) {
					PHALCON_INIT_VAR(match_one);
					phalcon_array_fetch_long(&match_one, matches, 1, PH_NOISY_CC);
					phalcon_array_update_string(&definition, SL("size"), &match_one, PH_COPY | PH_SEPARATE TSRMLS_CC);
				}
			}
		}
		
		PHALCON_INIT_VAR(pos);
		phalcon_fast_strpos_str(pos, column_type, SL("unsigned") TSRMLS_CC);
		if (Z_TYPE_P(pos) != IS_BOOL || (Z_TYPE_P(pos) == IS_BOOL && Z_BVAL_P(pos))) {
			phalcon_array_update_string_bool(&definition, SL("unsigned"), 1, PH_SEPARATE TSRMLS_CC);
		}
		
		if (!zend_is_true(old_column)) {
			phalcon_array_update_string_bool(&definition, SL("first"), 1, PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_string(&definition, SL("after"), &old_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(attribute);
		phalcon_array_fetch_string(&attribute, field, SL("key"), PH_NOISY_CC);
		if (PHALCON_COMPARE_STRING(attribute, "PRI")) {
			phalcon_array_update_string_bool(&definition, SL("primary"), 1, PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(attribute);
		phalcon_array_fetch_string(&attribute, field, SL("null"), PH_NOISY_CC);
		if (PHALCON_COMPARE_STRING(attribute, "NO")) {
			phalcon_array_update_string_bool(&definition, SL("notNull"), 1, PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(attribute);
		phalcon_array_fetch_string(&attribute, field, SL("extra"), PH_NOISY_CC);
		if (PHALCON_COMPARE_STRING(attribute, "auto_increment")) {
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
		goto fes_ecef_0;
	fee_ecef_0:
	
	
	RETURN_CTOR(columns);
}

/**
 * Lists table indexes
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\Index[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeIndexes){

	zval *table = NULL, *schema = NULL, *dialect = NULL, *sql = NULL, *describe = NULL, *indexes = NULL;
	zval *index = NULL, *key_name = NULL, *column_name = NULL, *index_objects = NULL;
	zval *index_columns = NULL, *name = NULL;
	zval *t0 = NULL;
	zval *a0 = NULL;
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
	
	PHALCON_INIT_VAR(dialect);
	phalcon_read_property(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "describeindexes", table, schema, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_db_ce, SL("FETCH_ASSOC") TSRMLS_CC);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, t0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(indexes);
	array_init(indexes);
	if (!phalcon_valid_foreach(describe TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(describe);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_ecef_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_ecef_1;
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
		
		PHALCON_INIT_VAR(column_name);
		phalcon_array_fetch_string(&column_name, index, SL("column_name"), PH_NOISY_CC);
		phalcon_array_update_multi_append_2(&indexes, key_name, column_name, 0 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_ecef_1;
	fee_ecef_1:
	
	PHALCON_INIT_VAR(index_objects);
	array_init(index_objects);
	if (!phalcon_valid_foreach(indexes TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(indexes);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	fes_ecef_2:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_ecef_2;
		}
		
		PHALCON_INIT_VAR(name);
		PHALCON_GET_FOREACH_KEY(name, ah1, hp1);
		PHALCON_INIT_VAR(index_columns);
		ZVAL_ZVAL(index_columns, *hd, 1, 0);
		PHALCON_INIT_VAR(index);
		object_init_ex(index, phalcon_db_index_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(index, "__construct", name, index_columns, PH_CHECK);
		phalcon_array_update_zval(&index_objects, name, &index, PH_COPY | PH_SEPARATE TSRMLS_CC);
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_ecef_2;
	fee_ecef_2:
	
	
	RETURN_CTOR(index_objects);
}

/**
 * Lists table references
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\Reference[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeReferences){

	zval *table = NULL, *schema = NULL, *dialect = NULL, *sql = NULL, *references = NULL;
	zval *describe = NULL, *reference = NULL, *constraint_name = NULL;
	zval *referenced_schema = NULL, *referenced_table = NULL;
	zval *column_name = NULL, *referenced_columns = NULL, *reference_objects = NULL;
	zval *array_reference = NULL, *name = NULL, *columns = NULL, *definition = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *a0 = NULL, *a1 = NULL, *a2 = NULL;
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
	
	PHALCON_INIT_VAR(dialect);
	phalcon_read_property(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "describereferences", table, schema, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(references);
	array_init(references);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_db_ce, SL("FETCH_ASSOC") TSRMLS_CC);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, t0, PH_NO_CHECK);
	if (!phalcon_valid_foreach(describe TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(describe);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_ecef_3:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_ecef_3;
		}
		
		PHALCON_INIT_VAR(reference);
		ZVAL_ZVAL(reference, *hd, 1, 0);
		PHALCON_INIT_VAR(constraint_name);
		phalcon_array_fetch_string(&constraint_name, reference, SL("constraint_name"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(references, constraint_name);
		if (!eval_int) {
			PHALCON_INIT_VAR(referenced_schema);
			phalcon_array_fetch_string(&referenced_schema, reference, SL("referenced_table_schema"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(referenced_table);
			phalcon_array_fetch_string(&referenced_table, reference, SL("referenced_table_name"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(a0);
			array_init(a0);
			phalcon_array_update_string(&a0, SL("referencedSchema"), &referenced_schema, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&a0, SL("referencedTable"), &referenced_table, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(a1);
			array_init(a1);
			phalcon_array_update_string(&a0, SL("columns"), &a1, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(a2);
			array_init(a2);
			phalcon_array_update_string(&a0, SL("referencedColumns"), &a2, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&references, constraint_name, &a0, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		PHALCON_INIT_VAR(column_name);
		phalcon_array_fetch_string(&column_name, reference, SL("column_name"), PH_NOISY_CC);
		if (Z_TYPE_P(references) == IS_ARRAY) {
			PHALCON_INIT_VAR(t1);
			phalcon_array_fetch(&t1, references, constraint_name, PH_SILENT_CC);
		}
		if (Z_REFCOUNT_P(t1) > 1) {
			phalcon_array_update_zval(&references, constraint_name, &t1, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t1) != IS_ARRAY) {
			convert_to_array(t1);
			phalcon_array_update_zval(&references, constraint_name, &t1, PH_COPY TSRMLS_CC);
		}
		if (Z_TYPE_P(t1) == IS_ARRAY) {
			PHALCON_INIT_VAR(t2);
			phalcon_array_fetch_string(&t2, t1, SL("columns"), PH_SILENT_CC);
		}
		if (Z_REFCOUNT_P(t2) > 1) {
			phalcon_array_update_string(&t1, SL("columns"), &t2, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t2) != IS_ARRAY) {
			convert_to_array(t2);
			phalcon_array_update_string(&t1, SL("columns"), &t2, PH_COPY TSRMLS_CC);
		}
		phalcon_array_append(&t2, column_name, 0 TSRMLS_CC);
		
		PHALCON_INIT_VAR(referenced_columns);
		phalcon_array_fetch_string(&referenced_columns, reference, SL("referenced_column_name"), PH_NOISY_CC);
		if (Z_TYPE_P(references) == IS_ARRAY) {
			PHALCON_INIT_VAR(t3);
			phalcon_array_fetch(&t3, references, constraint_name, PH_SILENT_CC);
		}
		if (Z_REFCOUNT_P(t3) > 1) {
			phalcon_array_update_zval(&references, constraint_name, &t3, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t3) != IS_ARRAY) {
			convert_to_array(t3);
			phalcon_array_update_zval(&references, constraint_name, &t3, PH_COPY TSRMLS_CC);
		}
		if (Z_TYPE_P(t3) == IS_ARRAY) {
			PHALCON_INIT_VAR(t4);
			phalcon_array_fetch_string(&t4, t3, SL("referencedColumns"), PH_SILENT_CC);
		}
		if (Z_REFCOUNT_P(t4) > 1) {
			phalcon_array_update_string(&t3, SL("referencedColumns"), &t4, PH_COPY | PH_CTOR TSRMLS_CC);
		}
		if (Z_TYPE_P(t4) != IS_ARRAY) {
			convert_to_array(t4);
			phalcon_array_update_string(&t3, SL("referencedColumns"), &t4, PH_COPY TSRMLS_CC);
		}
		phalcon_array_append(&t4, referenced_columns, 0 TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_ecef_3;
	fee_ecef_3:
	
	PHALCON_INIT_VAR(reference_objects);
	array_init(reference_objects);
	if (!phalcon_valid_foreach(references TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(references);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	fes_ecef_4:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_ecef_4;
		}
		
		PHALCON_INIT_VAR(name);
		PHALCON_GET_FOREACH_KEY(name, ah1, hp1);
		PHALCON_INIT_VAR(array_reference);
		ZVAL_ZVAL(array_reference, *hd, 1, 0);
		PHALCON_INIT_VAR(referenced_schema);
		phalcon_array_fetch_string(&referenced_schema, array_reference, SL("referencedSchema"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(referenced_table);
		phalcon_array_fetch_string(&referenced_table, array_reference, SL("referencedTable"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(columns);
		phalcon_array_fetch_string(&columns, array_reference, SL("columns"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(referenced_columns);
		phalcon_array_fetch_string(&referenced_columns, array_reference, SL("referencedColumns"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(definition);
		array_init(definition);
		phalcon_array_update_string(&definition, SL("referencedSchema"), &referenced_schema, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&definition, SL("referencedTable"), &referenced_table, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&definition, SL("columns"), &columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&definition, SL("referencedColumns"), &referenced_columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_VAR(reference);
		object_init_ex(reference, phalcon_db_reference_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(reference, "__construct", name, definition, PH_CHECK);
		phalcon_array_update_zval(&reference_objects, name, &reference, PH_COPY | PH_SEPARATE TSRMLS_CC);
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_ecef_4;
	fee_ecef_4:
	
	
	RETURN_CTOR(reference_objects);
}

/**
 * Gets creation options from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, tableOptions){

	zval *table_name = NULL, *schema_name = NULL, *dialect = NULL, *sql = NULL;
	zval *describe = NULL, *first = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table_name, &schema_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!schema_name) {
		PHALCON_ALLOC_ZVAL_MM(schema_name);
		ZVAL_NULL(schema_name);
	}
	
	PHALCON_INIT_VAR(dialect);
	phalcon_read_property(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "tableoptions", table_name, schema_name, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_db_ce, SL("FETCH_ASSOC") TSRMLS_CC);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, t0, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(first);
	phalcon_array_fetch_long(&first, describe, 0, PH_NOISY_CC);
	
	RETURN_CCTOR(first);
}

