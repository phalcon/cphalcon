
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
  |          Marcio Paiva <mpaivabarbosa@gmail.com>                        |
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Db\Adapter\Pdo\Oracle
 *
 * Specific functions for the Oracle database system
 * <code>
 *
 * $config = array(
 *  "dbname" => "//localhost/dbname",
 *  "username" => "oracle",
 *  "password" => "oracle"
 * );
 *
 * $connection = new Phalcon\Db\Adapter\Pdo\Oracle($config);
 *
 * </code>
 */


/**
 * Phalcon\Db\Adapter\Pdo\Oracle initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Oracle){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Oracle, db_adapter_pdo_oracle, "phalcon\\db\\adapter\\pdo", phalcon_db_adapter_pdo_oracle_method_entry, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_oracle_ce, SL("_type"), "oci", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_db_adapter_pdo_oracle_ce, SL("_dialectType"), "oracle", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_adapter_pdo_oracle_ce TSRMLS_CC, 1, phalcon_db_adapterinterface_ce);

	return SUCCESS;
}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection.
 *
 * @param array $descriptor
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, connect){

	zval *descriptor = NULL, *startup, *value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &descriptor);
	
	if (!descriptor) {
		PHALCON_INIT_VAR(descriptor);
	} else {
		PHALCON_SEPARATE_PARAM(descriptor);
	}
	
	if (!zend_is_true(descriptor)) {
		PHALCON_OBS_NVAR(descriptor);
		phalcon_read_property_this(&descriptor, this_ptr, SL("_descriptor"), PH_NOISY_CC);
	}
	
	/** 
	 * Connect
	 */
	PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon\\Db\\Adapter\\Pdo\\Oracle", "connect", descriptor);
	
	/** 
	 * Database session settings initiated with each HTTP request. Oracle behaviour
	 * depends on particular NLS* parameter. Check if the developer has defined custom
	 * startup or create one from scratch
	 */
	if (phalcon_array_isset_string(descriptor, SS("startup"))) {
	
		PHALCON_OBS_VAR(startup);
		phalcon_array_fetch_string(&startup, descriptor, SL("startup"), PH_NOISY);
		if (Z_TYPE_P(startup) == IS_ARRAY) { 
	
			phalcon_is_iterable(startup, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HVALUE(value);
	
				phalcon_call_method_p1_noret(this_ptr, "execute", value);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, describeColumns){

	zval *table, *schema = NULL, *columns, *dialect, *sql, *fetch_num;
	zval *describe, *old_column = NULL, *field = NULL, *definition = NULL;
	zval *column_size = NULL, *column_precision = NULL, *column_scale = NULL;
	zval *column_type = NULL, *attribute = NULL, *column_name = NULL;
	zval *column = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table, &schema);
	
	if (!schema) {
		PHALCON_INIT_VAR(schema);
	}
	
	PHALCON_INIT_VAR(columns);
	array_init(columns);
	
	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	phalcon_call_method_p2(sql, dialect, "describecolumns", table, schema);
	
	/** 
	 * We're using FETCH_NUM to fetch the columns
	 */
	PHALCON_INIT_VAR(fetch_num);
	ZVAL_LONG(fetch_num, 3);
	
	PHALCON_INIT_VAR(describe);
	phalcon_call_method_p2(describe, this_ptr, "fetchall", sql, fetch_num);
	
	/** 
	 *  0:column_name, 1:data_type, 2:data_length, 3:data_precision, 4:data_scale,
	 * 5:nullable, 6:constraint_type, 7:default, 8:position;
	 */
	PHALCON_INIT_VAR(old_column);
	
	phalcon_is_iterable(describe, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(field);
	
		PHALCON_INIT_NVAR(definition);
		array_init_size(definition, 1);
		add_assoc_long_ex(definition, SS("bindType"), 2);
	
		PHALCON_OBS_NVAR(column_size);
		phalcon_array_fetch_long(&column_size, field, 2, PH_NOISY);
	
		PHALCON_OBS_NVAR(column_precision);
		phalcon_array_fetch_long(&column_precision, field, 3, PH_NOISY);
	
		PHALCON_OBS_NVAR(column_scale);
		phalcon_array_fetch_long(&column_scale, field, 4, PH_NOISY);
	
		PHALCON_OBS_NVAR(column_type);
		phalcon_array_fetch_long(&column_type, field, 1, PH_NOISY);
	
		/** 
		 * Check the column type to get the correct Phalcon type
		 */
		if (phalcon_memnstr_str(column_type, SL("NUMBER"))) {
			phalcon_array_update_string_long(&definition, SL("type"), 3, PH_SEPARATE);
			phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE);
			phalcon_array_update_string(&definition, SL("size"), &column_precision, PH_COPY | PH_SEPARATE);
			phalcon_array_update_string(&definition, SL("scale"), &column_scale, PH_COPY | PH_SEPARATE);
			phalcon_array_update_string_long(&definition, SL("bindType"), 32, PH_SEPARATE);
		} else {
			if (phalcon_memnstr_str(column_type, SL("INTEGER"))) {
				phalcon_array_update_string_long(&definition, SL("type"), 0, PH_SEPARATE);
				phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE);
				phalcon_array_update_string(&definition, SL("size"), &column_precision, PH_COPY | PH_SEPARATE);
				phalcon_array_update_string_long(&definition, SL("bindType"), 1, PH_SEPARATE);
			} else {
				if (phalcon_memnstr_str(column_type, SL("VARCHAR2"))) {
					phalcon_array_update_string_long(&definition, SL("type"), 2, PH_SEPARATE);
					phalcon_array_update_string(&definition, SL("size"), &column_size, PH_COPY | PH_SEPARATE);
				} else {
					if (phalcon_memnstr_str(column_type, SL("FLOAT"))) {
						phalcon_array_update_string_long(&definition, SL("type"), 7, PH_SEPARATE);
						phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE);
						phalcon_array_update_string(&definition, SL("size"), &column_size, PH_COPY | PH_SEPARATE);
						phalcon_array_update_string(&definition, SL("scale"), &column_scale, PH_COPY | PH_SEPARATE);
						phalcon_array_update_string_long(&definition, SL("bindType"), 32, PH_SEPARATE);
					} else {
						if (phalcon_memnstr_str(column_type, SL("TIMESTAMP"))) {
							phalcon_array_update_string_long(&definition, SL("type"), 1, PH_SEPARATE);
						} else {
							if (phalcon_memnstr_str(column_type, SL("RAW"))) {
								phalcon_array_update_string_long(&definition, SL("type"), 6, PH_SEPARATE);
							} else {
								if (phalcon_memnstr_str(column_type, SL("BLOB"))) {
									phalcon_array_update_string_long(&definition, SL("type"), 6, PH_SEPARATE);
								} else {
									if (phalcon_memnstr_str(column_type, SL("CLOB"))) {
										phalcon_array_update_string_long(&definition, SL("type"), 6, PH_SEPARATE);
									} else {
										if (phalcon_memnstr_str(column_type, SL("VARCHAR2"))) {
											phalcon_array_update_string_long(&definition, SL("type"), 2, PH_SEPARATE);
											phalcon_array_update_string(&definition, SL("size"), &column_size, PH_COPY | PH_SEPARATE);
										} else {
											if (phalcon_memnstr_str(column_type, SL("CHAR"))) {
												phalcon_array_update_string_long(&definition, SL("type"), 5, PH_SEPARATE);
												phalcon_array_update_string(&definition, SL("size"), &column_size, PH_COPY | PH_SEPARATE);
											} else {
												phalcon_array_update_string_long(&definition, SL("type"), 6, PH_SEPARATE);
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
	
		if (Z_TYPE_P(old_column) == IS_NULL) {
			phalcon_array_update_string_bool(&definition, SL("first"), 1, PH_SEPARATE);
		} else {
			phalcon_array_update_string(&definition, SL("after"), &old_column, PH_COPY | PH_SEPARATE);
		}
	
		/** 
		 * Check if the field is primary key
		 */
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_long(&attribute, field, 6, PH_NOISY);
		if (PHALCON_IS_STRING(attribute, "P")) {
			phalcon_array_update_string_bool(&definition, SL("primary"), 1, PH_SEPARATE);
		}
	
		/** 
		 * Check if the column allows null values
		 */
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_long(&attribute, field, 5, PH_NOISY);
		if (PHALCON_IS_STRING(attribute, "N")) {
			phalcon_array_update_string_bool(&definition, SL("notNull"), 1, PH_SEPARATE);
		}
	
		PHALCON_OBS_NVAR(column_name);
		phalcon_array_fetch_long(&column_name, field, 0, PH_NOISY);
	
		/** 
		 * Create a Phalcon\Db\Column to abstract the column
		 */
		PHALCON_INIT_NVAR(column);
		object_init_ex(column, phalcon_db_column_ce);
		phalcon_call_method_p2_noret(column, "__construct", column_name, definition);
	
		phalcon_array_append(&columns, column, PH_SEPARATE);
		PHALCON_CPY_WRT(old_column, column_name);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_CTOR(columns);
}

/**
 * Returns the insert id for the auto_increment/serial column inserted in the lastest executed SQL statement
 *
 *<code>
 * //Inserting a new robot
 * $success = $connection->insert(
 *     "robots",
 *     array("Astro Boy", 1952),
 *     array("name", "year")
 * );
 *
 * //Getting the generated id
 * $id = $connection->lastInsertId();
 *</code>
 *
 * @param string $sequenceName
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, lastInsertId){

	zval *sequence_name = NULL, *sql, *fetch_num, *ret, *insert_id;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &sequence_name);
	
	if (!sequence_name) {
		PHALCON_INIT_VAR(sequence_name);
	}
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_SVS(sql, "SELECT ", sequence_name, ".CURRVAL FROM dual");
	
	PHALCON_INIT_VAR(fetch_num);
	ZVAL_LONG(fetch_num, 3);
	
	PHALCON_INIT_VAR(ret);
	phalcon_call_method_p2(ret, this_ptr, "fetchall", sql, fetch_num);
	
	PHALCON_OBS_VAR(insert_id);
	phalcon_array_fetch_long(&insert_id, ret, 0, PH_NOISY);
	RETURN_CCTOR(insert_id);
}

/**
 * Check whether the database system requires an explicit value for identity columns
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, useExplicitIdValue){


	RETURN_FALSE;
}

/**
 * Return the default identity value to insert in an identity column
 *
 * @return Phalcon\Db\RawValue
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, getDefaultIdValue){

	zval *null_value, *default_value;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(null_value);
	ZVAL_STRING(null_value, "default", 1);
	
	PHALCON_INIT_VAR(default_value);
	object_init_ex(default_value, phalcon_db_rawvalue_ce);
	phalcon_call_method_p1_noret(default_value, "__construct", null_value);
	
	RETURN_CTOR(default_value);
}

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, supportSequences){


	RETURN_TRUE;
}

