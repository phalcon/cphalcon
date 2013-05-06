
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

#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"

/**
 * Phalcon\Db\Adapter\Pdo\Mysql
 *
 * Specific functions for the Mysql database system
 * <code>
 *
 *	$config = array(
 *		"host" => "192.168.0.11",
 *		"dbname" => "blog",
 *		"port" => 3306,
 *		"username" => "sigma",
 *		"password" => "secret"
 *	);
 *
 *	$connection = new Phalcon\Db\Adapter\Pdo\Mysql($config);
 *
 * </code>
 */


/**
 * Phalcon\Db\Adapter\Pdo\Mysql initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Mysql){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Mysql, db_adapter_pdo_mysql, "phalcon\\db\\adapter\\pdo", phalcon_db_adapter_pdo_mysql_method_entry, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("_type"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("_dialectType"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_adapter_pdo_mysql_ce TSRMLS_CC, 1, phalcon_db_adapterinterface_ce);

	return SUCCESS;
}

/**
 * Escapes a column/table/schema name
 *
 * @param string $identifier
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, escapeIdentifier){

	zval *identifier, *domain, *name, *escaped = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &identifier);
	
	if (Z_TYPE_P(identifier) == IS_ARRAY) { 
	
		PHALCON_OBS_VAR(domain);
		phalcon_array_fetch_long(&domain, identifier, 0, PH_NOISY_CC);
	
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_long(&name, identifier, 1, PH_NOISY_CC);
		if (PHALCON_GLOBAL(db).escape_identifiers) {
			PHALCON_INIT_VAR(escaped);
			PHALCON_CONCAT_SVSVS(escaped, "`", domain, "`.`", name, "`");
		} else {
			PHALCON_INIT_NVAR(escaped);
			PHALCON_CONCAT_VSV(escaped, domain, ".", name);
		}
	
	
		RETURN_CTOR(escaped);
	}
	if (PHALCON_GLOBAL(db).escape_identifiers) {
		PHALCON_INIT_NVAR(escaped);
		PHALCON_CONCAT_SVS(escaped, "`", identifier, "`");
		RETURN_CTOR(escaped);
	}
	
	
	RETURN_CCTOR(identifier);
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns){

	zval *table, *schema = NULL, *columns, *dialect, *sql, *fetch_num;
	zval *describe, *old_column = NULL, *size_pattern, *field = NULL;
	zval *definition = NULL, *column_type = NULL, *matches = NULL, *pos = NULL;
	zval *match_one = NULL, *attribute = NULL, *column_name = NULL, *column = NULL;
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
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "describecolumns", table, schema);
	
	/** 
	 * We're using FETCH_NUM to fetch the columns
	 */
	PHALCON_INIT_VAR(fetch_num);
	ZVAL_LONG(fetch_num, 3);
	
	PHALCON_INIT_VAR(describe);
	PHALCON_CALL_METHOD_PARAMS_2(describe, this_ptr, "fetchall", sql, fetch_num);
	
	PHALCON_INIT_VAR(old_column);
	
	PHALCON_INIT_VAR(size_pattern);
	ZVAL_STRING(size_pattern, "#\\(([0-9]+)(,[0-9]+)*\\)#", 1);
	
	/** 
	 * Field Indexes: 0:name, 1:type, 2:not null, 3:key, 4:default, 5:extra
	 */
	
	if (!phalcon_is_iterable(describe, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(field);
	
		PHALCON_INIT_NVAR(definition);
		array_init_size(definition, 1);
		add_assoc_long_ex(definition, SS("bindType"), 2);
	
		/** 
		 * By checking every column type we convert it to a Phalcon\Db\Column
		 */
		PHALCON_OBS_NVAR(column_type);
		phalcon_array_fetch_long(&column_type, field, 1, PH_NOISY_CC);
		if (phalcon_memnstr_str(column_type, SL("int") TSRMLS_CC)) {
			phalcon_array_update_string_long(&definition, SL("type"), 0, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string_long(&definition, SL("bindType"), 1, PH_SEPARATE TSRMLS_CC);
		} else {
			if (phalcon_memnstr_str(column_type, SL("varchar") TSRMLS_CC)) {
				phalcon_array_update_string_long(&definition, SL("type"), 2, PH_SEPARATE TSRMLS_CC);
			} else {
				if (phalcon_memnstr_str(column_type, SL("datetime") TSRMLS_CC)) {
					phalcon_array_update_string_long(&definition, SL("type"), 4, PH_SEPARATE TSRMLS_CC);
				} else {
					if (phalcon_memnstr_str(column_type, SL("decimal") TSRMLS_CC)) {
						phalcon_array_update_string_long(&definition, SL("type"), 3, PH_SEPARATE TSRMLS_CC);
						phalcon_array_update_string_bool(&definition, SL("isNumeric"), 1, PH_SEPARATE TSRMLS_CC);
						phalcon_array_update_string_long(&definition, SL("bindType"), 32, PH_SEPARATE TSRMLS_CC);
					} else {
						if (phalcon_memnstr_str(column_type, SL("char") TSRMLS_CC)) {
							phalcon_array_update_string_long(&definition, SL("type"), 5, PH_SEPARATE TSRMLS_CC);
						} else {
							if (phalcon_memnstr_str(column_type, SL("date") TSRMLS_CC)) {
								phalcon_array_update_string_long(&definition, SL("type"), 1, PH_SEPARATE TSRMLS_CC);
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
	
		/** 
		 * If the column type has a parentheses we try to get the column size from it
		 */
		if (phalcon_memnstr_str(column_type, SL("(") TSRMLS_CC)) {
	
			PHALCON_INIT_NVAR(matches);
	
			PHALCON_INIT_NVAR(pos);
	
			Z_SET_ISREF_P(matches);
	
			#if HAVE_BUNDLED_PCRE
			phalcon_preg_match(pos, size_pattern, column_type, matches TSRMLS_CC);
			#else
			PHALCON_CALL_FUNC_PARAMS_3(pos, "preg_match", size_pattern, column_type, matches);
			#endif
	
			Z_UNSET_ISREF_P(matches);
	
			if (zend_is_true(pos)) {
				if (phalcon_array_isset_long(matches, 1)) {
					PHALCON_OBS_NVAR(match_one);
					phalcon_array_fetch_long(&match_one, matches, 1, PH_NOISY_CC);
					phalcon_array_update_string(&definition, SL("size"), &match_one, PH_COPY | PH_SEPARATE TSRMLS_CC);
				}
			}
		}
	
		/** 
		 * Check if the column is unsigned, only MySQL support this
		 */
		if (phalcon_memnstr_str(column_type, SL("unsigned") TSRMLS_CC)) {
			phalcon_array_update_string_bool(&definition, SL("unsigned"), 1, PH_SEPARATE TSRMLS_CC);
		}
	
		if (!zend_is_true(old_column)) {
			phalcon_array_update_string_bool(&definition, SL("first"), 1, PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_string(&definition, SL("after"), &old_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		/** 
		 * Check if the field is primary key
		 */
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_long(&attribute, field, 3, PH_NOISY_CC);
		if (PHALCON_IS_STRING(attribute, "PRI")) {
			phalcon_array_update_string_bool(&definition, SL("primary"), 1, PH_SEPARATE TSRMLS_CC);
		}
	
		/** 
		 * Check if the column allows null values
		 */
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_long(&attribute, field, 2, PH_NOISY_CC);
		if (PHALCON_IS_STRING(attribute, "NO")) {
			phalcon_array_update_string_bool(&definition, SL("notNull"), 1, PH_SEPARATE TSRMLS_CC);
		}
	
		/** 
		 * Check if the column is auto increment
		 */
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_long(&attribute, field, 5, PH_NOISY_CC);
		if (PHALCON_IS_STRING(attribute, "auto_increment")) {
			phalcon_array_update_string_bool(&definition, SL("autoIncrement"), 1, PH_SEPARATE TSRMLS_CC);
		}
	
		PHALCON_OBS_NVAR(column_name);
		phalcon_array_fetch_long(&column_name, field, 0, PH_NOISY_CC);
	
		/** 
		 * Every route is stored as a Phalcon\Db\Column
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

