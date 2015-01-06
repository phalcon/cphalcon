/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "db/adapter/pdo/mysql.h"
#include "db/adapter/pdo.h"
#include "db/adapterinterface.h"
#include "db/column.h"

#include "ext/pdo/php_pdo_driver.h"

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
 *
 *<code>
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
 *</code>
 */
zend_class_entry *phalcon_db_adapter_pdo_mysql_ce;

PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, escapeIdentifier);
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns);

static const zend_function_entry phalcon_db_adapter_pdo_mysql_method_entry[] = {
	PHP_ME(Phalcon_Db_Adapter_Pdo_Mysql, escapeIdentifier, arginfo_phalcon_db_adapterinterface_escapeidentifier, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns, arginfo_phalcon_db_adapterinterface_describecolumns, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Db\Adapter\Pdo\Mysql initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Mysql){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Mysql, db_adapter_pdo_mysql, phalcon_db_adapter_pdo_ce, phalcon_db_adapter_pdo_mysql_method_entry, 0);

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

	zval *identifier, *domain, *name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &identifier);
	
	if (Z_TYPE_P(identifier) == IS_ARRAY) { 
	
		PHALCON_OBS_VAR(domain);
		phalcon_array_fetch_long(&domain, identifier, 0, PH_NOISY);
	
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_long(&name, identifier, 1, PH_NOISY);
		if (PHALCON_GLOBAL(db).escape_identifiers) {
			PHALCON_CONCAT_SVSVS(return_value, "`", domain, "`.`", name, "`");
			RETURN_MM();
		}
	
		PHALCON_CONCAT_VSV(return_value, domain, ".", name);
	
		RETURN_MM();
	}
	if (PHALCON_GLOBAL(db).escape_identifiers) {
		PHALCON_CONCAT_SVS(return_value, "`", identifier, "`");
		RETURN_MM();
	}
	
	RETURN_CTOR(identifier);
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

	zval *table, *schema = NULL, *dialect, *sql = NULL, *fetch_num;
	zval *describe = NULL, *old_column = NULL, *size_pattern, *columns;
	zval *field = NULL, *definition = NULL, *column_type = NULL, *matches = NULL;
	zval *pos = NULL, *match_one = NULL, *match_two = NULL, *attribute = NULL, *column_name = NULL;
	zval *column = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &table, &schema);
	
	if (!schema) {
		schema = PHALCON_GLOBAL(z_null);
	}
	
	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY TSRMLS_CC);
	
	/** 
	 * Get the SQL to describe a table
	 */
	PHALCON_CALL_METHOD(&sql, dialect, "describecolumns", table, schema);
	
	/** 
	 * We're using FETCH_NUM to fetch the columns
	 */
	PHALCON_INIT_VAR(fetch_num);
	ZVAL_LONG(fetch_num, PDO_FETCH_NUM);
	
	/** 
	 * Get the describe
	 */
	PHALCON_CALL_METHOD(&describe, this_ptr, "fetchall", sql, fetch_num);
	
	PHALCON_INIT_VAR(old_column);
	
	PHALCON_INIT_VAR(size_pattern);
	ZVAL_STRING(size_pattern, "#\\(([0-9]++)(?:,\\s*([0-9]++))?\\)#", 1);
	
	PHALCON_INIT_VAR(columns);
	array_init(columns);
	
	/** 
	 * Field Indexes: 0:name, 1:type, 2:not null, 3:key, 4:default, 5:extra
	 */
	phalcon_is_iterable(describe, &ah0, &hp0, 0, 0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_HVALUE(field);
	
		/** 
		 * By default the bind types is two
		 */
		PHALCON_INIT_NVAR(definition);
		array_init_size(definition, 1);
		add_assoc_long_ex(definition, SS("bindType"), 2);
	
		/** 
		 * By checking every column type we convert it to a Phalcon\Db\Column
		 */
		PHALCON_OBS_NVAR(column_type);
		phalcon_array_fetch_long(&column_type, field, 1, PH_NOISY);
	
		/** 
		 * Check the column type to get the correct Phalcon type
		 */
		while (1) {

			/**
			 * Point are varchars
			 */
			if (phalcon_memnstr_str(column_type, SL("point"))) {
				phalcon_array_update_string_long(&definition, SL("type"), 2, 0);
				break;
			}

			/**
			 * Enum are treated as char
			 */
			if (phalcon_memnstr_str(column_type, SL("enum"))) {
				phalcon_array_update_string_long(&definition, SL("type"), 5, 0);
				break;
			}

			/**
			 * Smallint/Bigint/Integers/Int are int
			 */
			if (phalcon_memnstr_str(column_type, SL("int"))) {
				phalcon_array_update_string_long(&definition, SL("type"), 0, 0);
				phalcon_array_update_string(&definition, SL("isNumeric"), PHALCON_GLOBAL(z_true), PH_COPY);
				phalcon_array_update_string_long(&definition, SL("bindType"), 1, 0);
				break;
			}

			/**
			 * Varchar are varchars
			 */
			if (phalcon_memnstr_str(column_type, SL("varchar"))) {
				phalcon_array_update_string_long(&definition, SL("type"), 2, 0);
				break;
			}

			/**
			 * Special type for datetime
			 */
			if (phalcon_memnstr_str(column_type, SL("datetime"))) {
				phalcon_array_update_string_long(&definition, SL("type"), 4, 0);
				break;
			}

			/**
			 * Decimals are floats
			 */
			if (phalcon_memnstr_str(column_type, SL("decimal"))) {
				phalcon_array_update_string_long(&definition, SL("type"), 3, 0);
				phalcon_array_update_string(&definition, SL("isNumeric"), PHALCON_GLOBAL(z_true), PH_COPY);
				phalcon_array_update_string_long(&definition, SL("bindType"), 32, 0);
				break;
			}

			/**
			 * Chars are chars
			 */
			if (phalcon_memnstr_str(column_type, SL("char"))) {
				phalcon_array_update_string_long(&definition, SL("type"), 5, 0);
				break;
			}

			/**
			 * Date/Datetime are varchars
			 */
			if (phalcon_memnstr_str(column_type, SL("date"))) {
				phalcon_array_update_string_long(&definition, SL("type"), 1, 0);
				break;
			}

			/**
			 * Timestamp as date
			 */
			if (phalcon_memnstr_str(column_type, SL("timestamp"))) {
				phalcon_array_update_string_long(&definition, SL("type"), 1, 0);
				break;
			}

			/**
			 * Text are varchars
			 */
			if (phalcon_memnstr_str(column_type, SL("text"))) {
				phalcon_array_update_string_long(&definition, SL("type"), 6, 0);
				break;
			}

			/**
			 * Float/Smallfloats/Decimals are float
			 */
			if (phalcon_memnstr_str(column_type, SL("float"))) {
				phalcon_array_update_string_long(&definition, SL("type"), 7, 0);
				phalcon_array_update_string(&definition, SL("isNumeric"), PHALCON_GLOBAL(z_true), PH_COPY);
				phalcon_array_update_string_long(&definition, SL("bindType"), 32, 0);
				break;
			}

			/**
			 * Double are floats
			 */
			if (phalcon_memnstr_str(column_type, SL("double"))) {
				phalcon_array_update_string_long(&definition, SL("type"), 9, 0);
				phalcon_array_update_string(&definition, SL("isNumeric"), PHALCON_GLOBAL(z_true), PH_COPY);
				phalcon_array_update_string_long(&definition, SL("bindType"), 32, 0);
				break;
			}

			/**
			 * By default is string
			 */
			phalcon_array_update_string_long(&definition, SL("type"), 2, 0);
			break;
		}
	
		/** 
		 * If the column type has a parentheses we try to get the column size from it
		 */
		if (phalcon_memnstr_str(column_type, SL("("))) {
	
			PHALCON_INIT_NVAR(matches);
	
			PHALCON_INIT_NVAR(pos);
			RETURN_MM_ON_FAILURE(phalcon_preg_match(pos, size_pattern, column_type, matches TSRMLS_CC));

			if (zend_is_true(pos)) {
				if (phalcon_array_isset_long(matches, 1)) {
					PHALCON_OBS_NVAR(match_one);
					phalcon_array_fetch_long(&match_one, matches, 1, PH_NOISY);
					phalcon_array_update_string(&definition, SL("size"), match_one, PH_COPY | PH_SEPARATE);
				}
				if (phalcon_array_isset_long(matches, 2)) {
					PHALCON_OBS_NVAR(match_two);
					phalcon_array_fetch_long(&match_two, matches, 2, PH_NOISY);
					phalcon_array_update_string(&definition, SL("scale"), match_two, PH_COPY | PH_SEPARATE);
				}
			}
		}
	
		/** 
		 * Check if the column is unsigned, only MySQL support this
		 */
		if (phalcon_memnstr_str(column_type, SL("unsigned"))) {
			phalcon_array_update_string(&definition, SL("unsigned"), PHALCON_GLOBAL(z_true), PH_COPY);
		}
	
		/** 
		 * Positions
		 */
		if (!zend_is_true(old_column)) {
			phalcon_array_update_string(&definition, SL("first"), PHALCON_GLOBAL(z_true), PH_COPY);
		} else {
			phalcon_array_update_string(&definition, SL("after"), old_column, PH_COPY);
		}
	
		/** 
		 * Check if the field is primary key
		 */
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_long(&attribute, field, 3, PH_NOISY);
		if (PHALCON_IS_STRING(attribute, "PRI")) {
			phalcon_array_update_string(&definition, SL("primary"), PHALCON_GLOBAL(z_true), PH_COPY);
		}
	
		/** 
		 * Check if the column allows null values
		 */
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_long(&attribute, field, 2, PH_NOISY);
		if (PHALCON_IS_STRING(attribute, "NO")) {
			phalcon_array_update_string(&definition, SL("notNull"), PHALCON_GLOBAL(z_true), PH_COPY);
		}
	
		/** 
		 * Check if the column is auto increment
		 */
		PHALCON_OBS_NVAR(attribute);
		phalcon_array_fetch_long(&attribute, field, 5, PH_NOISY);
		if (PHALCON_IS_STRING(attribute, "auto_increment")) {
			phalcon_array_update_string(&definition, SL("autoIncrement"), PHALCON_GLOBAL(z_true), PH_COPY);
		}
	
		PHALCON_OBS_NVAR(column_name);
		phalcon_array_fetch_long(&column_name, field, 0, PH_NOISY);
	
		/** 
		 * Every route is stored as a Phalcon\Db\Column
		 */
		PHALCON_INIT_NVAR(column);
		object_init_ex(column, phalcon_db_column_ce);
		PHALCON_CALL_METHOD(NULL, column, "__construct", column_name, definition);
	
		phalcon_array_append(&columns, column, PH_SEPARATE);
		PHALCON_CPY_WRT(old_column, column_name);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	RETURN_CTOR(columns);
}
