
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

#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/string.h"

/**
 * Phalcon\Db\Adapter\Pdo\Sqlite
 *
 * Specific functions for the Sqlite database system
 * <code>
 *
 * $config = array(
 *  "dbname" => "/tmp/test.sqlite"
 * );
 *
 * $connection = new Phalcon\Db\Adapter\Pdo\Sqlite($config);
 *
 * </code>
 */


/**
 * Phalcon\Db\Adapter\Pdo\Sqlite initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Sqlite){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Sqlite, db_adapter_pdo_sqlite, "phalcon\\db\\adapter\\pdo", phalcon_db_adapter_pdo_sqlite_method_entry, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_sqlite_ce, SL("_type"), "sqlite", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_db_adapter_pdo_sqlite_ce, SL("_dialectType"), "sqlite", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_adapter_pdo_sqlite_ce TSRMLS_CC, 1, phalcon_db_adapterinterface_ce);

	return SUCCESS;
}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection.
 *
 * @param array $descriptor
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, connect){

	zval *descriptor = NULL, *dbname;

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
	if (!phalcon_array_isset_string(descriptor, SS("dbname"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "dbname must be specified");
		return;
	} else {
		PHALCON_OBS_VAR(dbname);
		phalcon_array_fetch_string(&dbname, descriptor, SL("dbname"), PH_NOISY_CC);
		phalcon_array_update_string(&descriptor, SL("dsn"), &dbname, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_CALL_PARENT_PARAMS_1_NORETURN(this_ptr, "Phalcon\\Db\\Adapter\\Pdo\\Sqlite", "connect", descriptor);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns an array of Phalcon\Db\Column objects describing a table
 *
 * <code>
 * print_r($connection->describeColumns("posts")); ?>
 * </code>
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\Column[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeColumns){

	zval *table, *schema = NULL, *columns, *dialect, *size_pattern;
	zval *sql, *fetch_assoc, *describe, *old_column = NULL;
	zval *field = NULL, *definition = NULL, *column_type = NULL, *pos = NULL, *attribute = NULL;
	zval *matches = NULL, *match_one = NULL, *column_name = NULL, *column = NULL;
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
	
	PHALCON_INIT_VAR(size_pattern);
	ZVAL_STRING(size_pattern, "#\\(([0-9]+)(,[0-9]+)*\\)#", 1);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "describecolumns", table, schema);
	
	PHALCON_INIT_VAR(fetch_assoc);
	phalcon_get_class_constant(fetch_assoc, phalcon_db_ce, SS("FETCH_ASSOC") TSRMLS_CC);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, fetch_assoc);
	
	PHALCON_INIT_VAR(old_column);
	
	if (!phalcon_is_iterable(describe, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(field);
	
		PHALCON_INIT_NVAR(definition);
		array_init_size(definition, 1);
		add_assoc_long_ex(definition, SS("bindType"), 2);
	
		PHALCON_OBS_NVAR(column_type);
		phalcon_array_fetch_string(&column_type, field, SL("type"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(pos);
		phalcon_fast_stripos_str(pos, column_type, SL("int") TSRMLS_CC);
		if (PHALCON_IS_NOT_FALSE(pos)) {
			phalcon_array_update_string_long(&definition, SL("type"), 0, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string_long(&definition, SL("bindType"), 1, PH_SEPARATE TSRMLS_CC);
	
			PHALCON_OBS_NVAR(attribute);
			phalcon_array_fetch_string(&attribute, field, SL("pk"), PH_NOISY_CC);
			if (zend_is_true(attribute)) {
				phalcon_array_update_string_bool(&definition, SL("autoIncrement"), 1, PH_SEPARATE TSRMLS_CC);
			}
		} else {
			if (phalcon_memnstr_str(column_type, SL("varchar") TSRMLS_CC)) {
				phalcon_array_update_string_long(&definition, SL("type"), 2, PH_SEPARATE TSRMLS_CC);
			} else {
				if (phalcon_memnstr_str(column_type, SL("date") TSRMLS_CC)) {
					phalcon_array_update_string_long(&definition, SL("type"), 1, PH_SEPARATE TSRMLS_CC);
				} else {
					if (phalcon_memnstr_str(column_type, SL("decimal") TSRMLS_CC)) {
						phalcon_array_update_string_long(&definition, SL("type"), 3, PH_SEPARATE TSRMLS_CC);
						phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
						phalcon_array_update_string_long(&definition, SL("bindType"), 32, PH_SEPARATE TSRMLS_CC);
					} else {
						if (phalcon_memnstr_str(column_type, SL("char") TSRMLS_CC)) {
							phalcon_array_update_string_long(&definition, SL("type"), 5, PH_SEPARATE TSRMLS_CC);
						} else {
							if (phalcon_memnstr_str(column_type, SL("datetime") TSRMLS_CC)) {
								phalcon_array_update_string_long(&definition, SL("type"), 4, PH_SEPARATE TSRMLS_CC);
							} else {
								if (phalcon_memnstr_str(column_type, SL("text") TSRMLS_CC)) {
									phalcon_array_update_string_long(&definition, SL("type"), 6, PH_SEPARATE TSRMLS_CC);
								} else {
									if (phalcon_memnstr_str(column_type, SL("float") TSRMLS_CC)) {
										phalcon_array_update_string_long(&definition, SL("type"), 7, PH_SEPARATE TSRMLS_CC);
										phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
										phalcon_array_update_string_long(&definition, SL("bindType"), 32, PH_SEPARATE TSRMLS_CC);
									} else {
										if (phalcon_memnstr_str(column_type, SL("enum") TSRMLS_CC)) {
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
	
		if (phalcon_memnstr_str(column_type, SL("(") TSRMLS_CC)) {
	
			PHALCON_INIT_NVAR(matches);
			array_init(matches);
			Z_SET_ISREF_P(matches);
	
			PHALCON_INIT_NVAR(pos);
			PHALCON_CALL_FUNC_PARAMS_3(pos, "preg_match", size_pattern, column_type, matches);
			Z_UNSET_ISREF_P(matches);
			if (zend_is_true(pos)) {
				if (phalcon_array_isset_long(matches, 1)) {
					PHALCON_OBS_NVAR(match_one);
					phalcon_array_fetch_long(&match_one, matches, 1, PH_NOISY_CC);
					phalcon_array_update_string(&definition, SL("size"), &match_one, PH_COPY | PH_SEPARATE TSRMLS_CC);
				}
			}
		}
	
		if (phalcon_memnstr_str(column_type, SL("unsigned") TSRMLS_CC)) {
			phalcon_array_update_string_bool(&definition, SL("unsigned"), 1, PH_SEPARATE TSRMLS_CC);
		}
	
		if (!zend_is_true(old_column)) {
			phalcon_array_update_string_bool(&definition, SL("first"), 1, PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_string(&definition, SL("after"), &old_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_string(&attribute, field, SL("pk"), PH_NOISY_CC);
		if (zend_is_true(attribute)) {
			phalcon_array_update_string_bool(&definition, SL("primary"), 1, PH_SEPARATE TSRMLS_CC);
		}
	
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_string(&attribute, field, SL("notnull"), PH_NOISY_CC);
		if (zend_is_true(attribute)) {
			phalcon_array_update_string_bool(&definition, SL("notNull"), 1, PH_SEPARATE TSRMLS_CC);
		}
	
		PHALCON_OBS_NVAR(column_name);
		phalcon_array_fetch_string(&column_name, field, SL("name"), PH_NOISY_CC);
	
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
 * Lists table indexes
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\Index[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeIndexes){

	zval *table, *schema = NULL, *dialect, *fetch_assoc, *sql;
	zval *describe, *indexes, *index = NULL, *key_name = NULL, *empty_arr = NULL;
	zval *sql_index_describe = NULL, *describe_index = NULL;
	zval *index_column = NULL, *column_name = NULL, *index_objects;
	zval *index_columns = NULL, *name = NULL;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table, &schema) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!schema) {
		PHALCON_INIT_VAR(schema);
	}
	
	PHALCON_OBS_VAR(dialect);
	phalcon_read_property(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(fetch_assoc);
	phalcon_get_class_constant(fetch_assoc, phalcon_db_ce, SS("FETCH_ASSOC") TSRMLS_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "describeindexes", table, schema);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, fetch_assoc);
	
	PHALCON_INIT_VAR(indexes);
	array_init(indexes);
	
	if (!phalcon_is_iterable(describe, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(index);
	
		PHALCON_OBS_NVAR(key_name);
		phalcon_array_fetch_string(&key_name, index, SL("name"), PH_NOISY_CC);
		if (!phalcon_array_isset(indexes, key_name)) {
			PHALCON_INIT_NVAR(empty_arr);
			array_init(empty_arr);
			phalcon_array_update_zval(&indexes, key_name, &empty_arr, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		PHALCON_INIT_NVAR(sql_index_describe);
		PHALCON_CALL_METHOD_PARAMS_1(sql_index_describe, dialect, "describeindex", key_name);
	
		PHALCON_INIT_NVAR(describe_index);
		PHALCON_CALL_METHOD_PARAMS_2(describe_index, this_ptr, "fetchall", sql_index_describe, fetch_assoc);
	
		if (!phalcon_is_iterable(describe_index, &ah1, &hp1, 0, 0 TSRMLS_CC)) {
			return;
		}
	
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(index_column);
	
			PHALCON_OBS_NVAR(column_name);
			phalcon_array_fetch_string(&column_name, index_column, SL("name"), PH_NOISY_CC);
			phalcon_array_update_append_multi_2(&indexes, key_name, column_name, 0 TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_INIT_VAR(index_objects);
	array_init(index_objects);
	
	if (!phalcon_is_iterable(indexes, &ah2, &hp2, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	
	while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
		PHALCON_GET_FOREACH_KEY(name, ah2, hp2);
		PHALCON_GET_FOREACH_VALUE(index_columns);
	
		PHALCON_INIT_NVAR(index);
		object_init_ex(index, phalcon_db_index_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(index, "__construct", name, index_columns);
	
		phalcon_array_update_zval(&index_objects, name, &index, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah2, &hp2);
	}
	
	
	RETURN_CTOR(index_objects);
}

/**
 * Lists table references
 *
 * @param string $table
 * @param string $schema
 * @return Phalcon\Db\Reference[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeReferences){

	zval *table, *schema = NULL, *dialect, *sql, *fetch_assoc;
	zval *describe, *reference_objects, *reference_describe = NULL;
	zval *number = NULL, *constraint_name = NULL, *referenced_table = NULL;
	zval *from = NULL, *to = NULL, *columns = NULL, *referenced_columns = NULL;
	zval *reference_array = NULL, *reference = NULL;
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
	
	PHALCON_OBS_VAR(dialect);
	phalcon_read_property(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "describereferences", table, schema);
	
	PHALCON_INIT_VAR(fetch_assoc);
	phalcon_get_class_constant(fetch_assoc, phalcon_db_ce, SS("FETCH_ASSOC") TSRMLS_CC);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, fetch_assoc);
	
	PHALCON_INIT_VAR(reference_objects);
	array_init(reference_objects);
	
	if (!phalcon_is_iterable(describe, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_KEY(number, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(reference_describe);
	
		PHALCON_INIT_NVAR(constraint_name);
		PHALCON_CONCAT_SV(constraint_name, "foreign_key_", number);
	
		PHALCON_OBS_NVAR(referenced_table);
		phalcon_array_fetch_string(&referenced_table, reference_describe, SL("table"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(from);
		phalcon_array_fetch_string(&from, reference_describe, SL("from"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(to);
		phalcon_array_fetch_string(&to, reference_describe, SL("to"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(columns);
		array_init_size(columns, 1);
		phalcon_array_append(&columns, from, PH_SEPARATE TSRMLS_CC);
	
		PHALCON_INIT_NVAR(referenced_columns);
		array_init_size(referenced_columns, 1);
		phalcon_array_append(&referenced_columns, to, PH_SEPARATE TSRMLS_CC);
	
		PHALCON_INIT_NVAR(reference_array);
		array_init_size(reference_array, 4);
		add_assoc_null_ex(reference_array, SS("referencedSchema"));
		phalcon_array_update_string(&reference_array, SL("referencedTable"), &referenced_table, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&reference_array, SL("columns"), &columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&reference_array, SL("referencedColumns"), &referenced_columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		PHALCON_INIT_NVAR(reference);
		object_init_ex(reference, phalcon_db_reference_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(reference, "__construct", constraint_name, reference_array);
	
		phalcon_array_update_zval(&reference_objects, constraint_name, &reference, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	RETURN_CTOR(reference_objects);
}

