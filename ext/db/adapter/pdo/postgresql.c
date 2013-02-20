
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
#include "kernel/string.h"
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
 * Phalcon\Db\Adapter\Pdo\Postgresql initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Postgresql){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Postgresql, db_adapter_pdo_postgresql, "phalcon\\db\\adapter\\pdo", phalcon_db_adapter_pdo_postgresql_method_entry, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("_type"), "pgsql", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("_dialectType"), "postgresql", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_adapter_pdo_postgresql_ce TSRMLS_CC, 1, phalcon_db_adapterinterface_ce);

	return SUCCESS;
}

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

	zval *descriptor = NULL, *schema = NULL, *sql;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &descriptor) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!descriptor) {
		PHALCON_INIT_VAR(descriptor);
	} else {
		PHALCON_SEPARATE_PARAM(descriptor);
	}
	
	if (!zend_is_true(descriptor)) {
		PHALCON_OBS_NVAR(descriptor);
		phalcon_read_property(&descriptor, this_ptr, SL("_descriptor"), PH_NOISY_CC);
	}
	
	PHALCON_INIT_VAR(schema);
	if (phalcon_array_isset_string(descriptor, SS("schema"))) {
		PHALCON_OBS_NVAR(schema);
		phalcon_array_fetch_string(&schema, descriptor, SL("schema"), PH_NOISY_CC);
		phalcon_array_unset_string(&descriptor, SS("schema"), PH_SEPARATE);
	}
	
	PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon\\Db\\Adapter\\Pdo\\Postgresql", "connect", descriptor);
	
	/** 
	 * Execute the search path in the after connect
	 */
	if (Z_TYPE_P(schema) == IS_STRING) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVS(sql, "SET search_path TO '", schema, "'");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "execute", sql);
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

	zval *table, *schema = NULL, *columns, *dialect, *sql, *fetch_num;
	zval *describe, *old_column = NULL, *field = NULL, *definition = NULL;
	zval *char_size = NULL, *numeric_size = NULL, *column_type = NULL;
	zval *attribute = NULL, *column_name = NULL, *column = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!schema) {
		PHALCON_INIT_VAR(schema);
	}
	
	PHALCON_INIT_VAR(columns);
	array_init(columns);
	
	PHALCON_OBS_VAR(dialect);
	phalcon_read_property(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "describecolumns", table, schema);
	
	/** 
	 * We're using FETCH_NUM to fetch the columns
	 */
	PHALCON_INIT_VAR(fetch_num);
	ZVAL_LONG(fetch_num, 3);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, fetch_num);
	
	/** 
	 * Field Indexes: 0:name, 1:type, 2:size, 3:numericsize, 4: null, 5: key, 6: extra,
	 * 7: position
	 */
	PHALCON_INIT_VAR(old_column);
	
	if (!phalcon_is_iterable(describe, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(field);
	
		PHALCON_INIT_NVAR(definition);
		array_init_size(definition, 1);
		add_assoc_long_ex(definition, SS("bindType"), 2);
	
		PHALCON_OBS_NVAR(char_size);
		phalcon_array_fetch_long(&char_size, field, 2, PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(numeric_size);
		phalcon_array_fetch_long(&numeric_size, field, 3, PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(column_type);
		phalcon_array_fetch_long(&column_type, field, 1, PH_NOISY_CC);
		if (phalcon_memnstr_str(column_type, SL("int") TSRMLS_CC)) {
			phalcon_array_update_string_long(&definition, SL("type"), 0, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&definition, SL("size"), &numeric_size, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string_long(&definition, SL("bindType"), 1, PH_SEPARATE TSRMLS_CC);
		} else {
			if (phalcon_memnstr_str(column_type, SL("varying") TSRMLS_CC)) {
				phalcon_array_update_string_long(&definition, SL("type"), 2, PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&definition, SL("size"), &char_size, PH_COPY | PH_SEPARATE TSRMLS_CC);
			} else {
				if (phalcon_memnstr_str(column_type, SL("date") TSRMLS_CC)) {
					phalcon_array_update_string_long(&definition, SL("type"), 1, PH_SEPARATE TSRMLS_CC);
					phalcon_array_update_string_long(&definition, SL("size"), 0, PH_SEPARATE TSRMLS_CC);
				} else {
					if (phalcon_memnstr_str(column_type, SL("numeric") TSRMLS_CC)) {
						phalcon_array_update_string_long(&definition, SL("type"), 3, PH_SEPARATE TSRMLS_CC);
						phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
						phalcon_array_update_string(&definition, SL("size"), &numeric_size, PH_COPY | PH_SEPARATE TSRMLS_CC);
						phalcon_array_update_string_long(&definition, SL("bindType"), 32, PH_SEPARATE TSRMLS_CC);
					} else {
						if (phalcon_memnstr_str(column_type, SL("char") TSRMLS_CC)) {
							phalcon_array_update_string_long(&definition, SL("type"), 5, PH_SEPARATE TSRMLS_CC);
							phalcon_array_update_string(&definition, SL("size"), &char_size, PH_COPY | PH_SEPARATE TSRMLS_CC);
						} else {
							if (phalcon_memnstr_str(column_type, SL("timestamp") TSRMLS_CC)) {
								phalcon_array_update_string_long(&definition, SL("type"), 4, PH_SEPARATE TSRMLS_CC);
								phalcon_array_update_string_long(&definition, SL("size"), 0, PH_SEPARATE TSRMLS_CC);
							} else {
								if (phalcon_memnstr_str(column_type, SL("text") TSRMLS_CC)) {
									phalcon_array_update_string_long(&definition, SL("type"), 6, PH_SEPARATE TSRMLS_CC);
									phalcon_array_update_string(&definition, SL("size"), &char_size, PH_COPY | PH_SEPARATE TSRMLS_CC);
								} else {
									if (phalcon_memnstr_str(column_type, SL("float") TSRMLS_CC)) {
										phalcon_array_update_string_long(&definition, SL("type"), 7, PH_SEPARATE TSRMLS_CC);
										phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
										phalcon_array_update_string(&definition, SL("size"), &numeric_size, PH_COPY | PH_SEPARATE TSRMLS_CC);
										phalcon_array_update_string_long(&definition, SL("bindType"), 32, PH_SEPARATE TSRMLS_CC);
									} else {
										if (phalcon_memnstr_str(column_type, SL("bool") TSRMLS_CC)) {
											phalcon_array_update_string_long(&definition, SL("type"), 8, PH_SEPARATE TSRMLS_CC);
											phalcon_array_update_string_long(&definition, SL("size"), 0, PH_SEPARATE TSRMLS_CC);
											phalcon_array_update_string_long(&definition, SL("bindType"), 5, PH_SEPARATE TSRMLS_CC);
										} else {
											if (phalcon_memnstr_str(column_type, SL("uuid") TSRMLS_CC)) {
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
		}
	
		if (phalcon_memnstr_str(column_type, SL("unsigned") TSRMLS_CC)) {
			phalcon_array_update_string_bool(&definition, SL("unsigned"), 1, PH_SEPARATE TSRMLS_CC);
		}
	
		if (Z_TYPE_P(old_column) == IS_NULL) {
			phalcon_array_update_string_bool(&definition, SL("first"), 1, PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_string(&definition, SL("after"), &old_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		/** 
		 * Check if the field is primary key
		 */
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_long(&attribute, field, 5, PH_NOISY_CC);
		if (PHALCON_IS_STRING(attribute, "PRI")) {
			phalcon_array_update_string_bool(&definition, SL("primary"), 1, PH_SEPARATE TSRMLS_CC);
		}
	
		/** 
		 * Check if the column allows null values
		 */
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_long(&attribute, field, 4, PH_NOISY_CC);
		if (PHALCON_IS_STRING(attribute, "NO")) {
			phalcon_array_update_string_bool(&definition, SL("notNull"), 1, PH_SEPARATE TSRMLS_CC);
		}
	
		/** 
		 * Check if the column is auto increment
		 */
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_long(&attribute, field, 6, PH_NOISY_CC);
		if (PHALCON_IS_STRING(attribute, "auto_increment")) {
			phalcon_array_update_string_bool(&definition, SL("autoIncrement"), 1, PH_SEPARATE TSRMLS_CC);
		}
	
		PHALCON_OBS_NVAR(column_name);
		phalcon_array_fetch_long(&column_name, field, 0, PH_NOISY_CC);
	
		/** 
		 * Create a Phalcon\Db\Column to abstract the column
		 */
		PHALCON_INIT_NVAR(column);
		object_init_ex(column, phalcon_db_column_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(column, "__construct", column_name, definition);
	
		phalcon_array_append(&columns, column, PH_SEPARATE TSRMLS_CC);
		PHALCON_CPY_WRT(old_column, column_name);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	RETURN_CTOR(columns);
}

/**
 * Return the default identity value to insert in an identity column
 *
 * @return Phalcon\Db\RawValue
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue){

	zval *null_value, *default_value;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(null_value);
	ZVAL_STRING(null_value, "default", 1);
	
	PHALCON_INIT_VAR(default_value);
	object_init_ex(default_value, phalcon_db_rawvalue_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(default_value, "__construct", null_value);
	
	RETURN_CTOR(default_value);
}

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences){


	RETURN_TRUE;
}

