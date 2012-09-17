
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
  |          Rack Lin <racklin@gmail.com>                                  |
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Db\Adapter\Pdo\Postgresql
 *
 * Specific functions for the Postgresql database system
 * <code>
 *
 * $config = array(
 *  "host" => "192.168.0.11",
 *  "dbname" => "blog",
 *  "username" => "postgres",
 *  "password" => ""
 * );
 *
 * $connection = new Phalcon\Db\Adapter\Pdo\Postgresql($config);
 *
 * </code>
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
	int eval_int;

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
	
	PHALCON_INIT_VAR(schema);
	ZVAL_NULL(schema);
	eval_int = phalcon_array_isset_string(descriptor, SS("schema"));
	if (eval_int) {
		PHALCON_INIT_VAR(schema);
		phalcon_array_fetch_string(&schema, descriptor, SL("schema"), PH_NOISY_CC);
		PHALCON_SEPARATE_PARAM(descriptor);
		phalcon_array_unset_string(descriptor, SS("schema"));
	}
	
	PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon\\Db\\Adapter\\Pdo\\Postgresql", "connect", descriptor);
	if (Z_TYPE_P(schema) == IS_STRING) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVS(sql, "SET search_path TO '", schema, "'");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "execute", sql, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns an array of Phalcon\Db\Column objects describing a table
 *
 * <code>print_r($connection->describeColumns("posts")); ?></code>
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\Column[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns){

	zval *table = NULL, *schema = NULL, *columns = NULL, *sql = NULL, *fetch_assoc = NULL;
	zval *describe = NULL, *old_column = NULL, *field = NULL, *definition = NULL;
	zval *char_size = NULL, *numeric_size = NULL, *column_type = NULL;
	zval *status = NULL, *attribute = NULL, *column_name = NULL, *column = NULL;
	zval *t0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

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
	
	PHALCON_INIT_VAR(fetch_assoc);
	phalcon_get_class_constant(fetch_assoc, phalcon_db_ce, SL("FETCH_ASSOC") TSRMLS_CC);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, fetch_assoc, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(old_column);
	ZVAL_NULL(old_column);
	
	if (!phalcon_valid_foreach(describe TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(describe);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(field);
		
		PHALCON_INIT_VAR(definition);
		array_init(definition);
		
		PHALCON_INIT_VAR(char_size);
		phalcon_array_fetch_string(&char_size, field, SL("size"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(numeric_size);
		phalcon_array_fetch_string(&numeric_size, field, SL("numericsize"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(column_type);
		phalcon_array_fetch_string(&column_type, field, SL("type"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(status);
		phalcon_fast_strpos_str(status, column_type, SL("int") TSRMLS_CC);
		if (PHALCON_IS_NOT_FALSE(status)) {
			phalcon_array_update_string_long(&definition, SL("type"), 0, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&definition, SL("size"), &numeric_size, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(status);
			phalcon_fast_strpos_str(status, column_type, SL("varying") TSRMLS_CC);
			if (PHALCON_IS_NOT_FALSE(status)) {
				phalcon_array_update_string_long(&definition, SL("type"), 2, PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&definition, SL("size"), &char_size, PH_COPY | PH_SEPARATE TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(status);
				phalcon_fast_strpos_str(status, column_type, SL("date") TSRMLS_CC);
				if (PHALCON_IS_NOT_FALSE(status)) {
					phalcon_array_update_string_long(&definition, SL("type"), 1, PH_SEPARATE TSRMLS_CC);
					phalcon_array_update_string_long(&definition, SL("size"), 0, PH_SEPARATE TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(status);
					phalcon_fast_strpos_str(status, column_type, SL("numeric") TSRMLS_CC);
					if (PHALCON_IS_NOT_FALSE(status)) {
						phalcon_array_update_string_long(&definition, SL("type"), 3, PH_SEPARATE TSRMLS_CC);
						phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
						phalcon_array_update_string(&definition, SL("size"), &numeric_size, PH_COPY | PH_SEPARATE TSRMLS_CC);
					} else {
						PHALCON_INIT_VAR(status);
						phalcon_fast_strpos_str(status, column_type, SL("char") TSRMLS_CC);
						if (PHALCON_IS_NOT_FALSE(status)) {
							phalcon_array_update_string_long(&definition, SL("type"), 5, PH_SEPARATE TSRMLS_CC);
							phalcon_array_update_string(&definition, SL("size"), &char_size, PH_COPY | PH_SEPARATE TSRMLS_CC);
						} else {
							PHALCON_INIT_VAR(status);
							phalcon_fast_strpos_str(status, column_type, SL("timestamp") TSRMLS_CC);
							if (PHALCON_IS_NOT_FALSE(status)) {
								phalcon_array_update_string_long(&definition, SL("type"), 4, PH_SEPARATE TSRMLS_CC);
								phalcon_array_update_string_long(&definition, SL("size"), 0, PH_SEPARATE TSRMLS_CC);
							} else {
								PHALCON_INIT_VAR(status);
								phalcon_fast_strpos_str(status, column_type, SL("text") TSRMLS_CC);
								if (PHALCON_IS_NOT_FALSE(status)) {
									phalcon_array_update_string_long(&definition, SL("type"), 6, PH_SEPARATE TSRMLS_CC);
									phalcon_array_update_string(&definition, SL("size"), &char_size, PH_COPY | PH_SEPARATE TSRMLS_CC);
								} else {
									PHALCON_INIT_VAR(status);
									phalcon_fast_strpos_str(status, column_type, SL("float") TSRMLS_CC);
									if (PHALCON_IS_NOT_FALSE(status)) {
										phalcon_array_update_string_long(&definition, SL("type"), 7, PH_SEPARATE TSRMLS_CC);
										phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
										phalcon_array_update_string(&definition, SL("size"), &numeric_size, PH_COPY | PH_SEPARATE TSRMLS_CC);
									} else {
										PHALCON_INIT_VAR(status);
										phalcon_fast_strpos_str(status, column_type, SL("uuid") TSRMLS_CC);
										if (PHALCON_IS_NOT_FALSE(status)) {
											phalcon_array_update_string_long(&definition, SL("type"), 5, PH_SEPARATE TSRMLS_CC);
											phalcon_array_update_string_long(&definition, SL("size"), 36, PH_SEPARATE TSRMLS_CC);
										} else {
											phalcon_array_update_string_long(&definition, SL("type"), 5, PH_SEPARATE TSRMLS_CC);
											phalcon_array_update_string(&definition, SL("size"), &char_size, PH_COPY | PH_SEPARATE TSRMLS_CC);
										}
									}
								}
							}
						}
					}
				}
			}
		}
		
		PHALCON_INIT_VAR(status);
		phalcon_fast_strpos_str(status, column_type, SL("unsigned") TSRMLS_CC);
		if (PHALCON_IS_NOT_FALSE(status)) {
			phalcon_array_update_string_bool(&definition, SL("unsigned"), 1, PH_SEPARATE TSRMLS_CC);
		}
		
		if (Z_TYPE_P(old_column) == IS_NULL) {
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
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	
	RETURN_CTOR(columns);
}

