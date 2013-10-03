
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"


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
/**
 * Phalcon\Db\Dialect\Mysql
 *
 * Generates database specific SQL for the MySQL RBDM
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_MySQL) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, MySQL, phalcon, db_dialect_mysql, phalcon_db_dialect_ce, phalcon_db_dialect_mysql_method_entry, 0);

	zend_declare_property_string(phalcon_db_dialect_mysql_ce, SL("_escapeChar"), "`", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Gets the column name in MySQL
 *
 * @param Phalcon\Db\ColumnInterface column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, getColumnDefinition) {

	zval *column, *columnSql = NULL, *size, *scale, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	if ((Z_TYPE_P(column) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column definition must be an object compatible with Phalcon\\Db\\ColumnInterface");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, column, "gettype");
	do {
		if (ZEPHIR_IS_LONG(_0, 0)) {
			ZEPHIR_INIT_VAR(_1);
			zephir_call_method(_1, column, "getsize");
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_CONCAT_SV(_2, "INT(", _1);
			ZEPHIR_INIT_VAR(columnSql);
			ZEPHIR_CONCAT_VS(columnSql, _2, ")");
			ZEPHIR_INIT_VAR(_3);
			zephir_call_method(_3, column, "isunsigned");
			if (zephir_is_true(_3)) {
				zephir_concat_self_str(&columnSql, SL(" UNSIGNED") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 1)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZVAL_STRING(columnSql, "DATE", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 2)) {
			ZEPHIR_INIT_NVAR(_1);
			zephir_call_method(_1, column, "getsize");
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_SV(_2, "VARCHAR(", _1);
			ZEPHIR_INIT_NVAR(columnSql);
			ZEPHIR_CONCAT_VS(columnSql, _2, ")");
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 3)) {
			ZEPHIR_INIT_NVAR(_1);
			zephir_call_method(_1, column, "getsize");
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_SV(_2, "DECIMAL(", _1);
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_CONCAT_VS(_4, _2, ",");
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_method(_3, column, "getscale");
			ZEPHIR_INIT_VAR(_5);
			concat_function(_5, _4, _3 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(columnSql);
			ZEPHIR_CONCAT_VS(columnSql, _5, ")");
			ZEPHIR_INIT_VAR(_6);
			zephir_call_method(_6, column, "isunsigned");
			if (zephir_is_true(_6)) {
				zephir_concat_self_str(&columnSql, SL(" UNSIGNED") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 4)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZVAL_STRING(columnSql, "DATETIME", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 5)) {
			ZEPHIR_INIT_NVAR(_1);
			zephir_call_method(_1, column, "getsize");
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_SV(_2, "CHAR(", _1);
			ZEPHIR_INIT_NVAR(columnSql);
			ZEPHIR_CONCAT_VS(columnSql, _2, ")");
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 6)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZVAL_STRING(columnSql, "TEXT", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 7)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZVAL_STRING(columnSql, "FLOAT", 1);
			ZEPHIR_INIT_VAR(size);
			zephir_call_method(size, column, "getsize");
			if (zephir_is_true(size)) {
				ZEPHIR_INIT_VAR(scale);
				zephir_call_method(scale, column, "getscale");
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_SV(_2, "(", size);
				zephir_concat_self(&columnSql, _2 TSRMLS_CC);
				if (zephir_is_true(scale)) {
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SV(_4, ",", scale);
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_VS(_5, _4, ")");
					zephir_concat_self(&columnSql, _5 TSRMLS_CC);
				} else {
					zephir_concat_self_str(&columnSql, SL(")") TSRMLS_CC);
				}
			}
			ZEPHIR_INIT_NVAR(_1);
			zephir_call_method(_1, column, "isunsigned");
			if (zephir_is_true(_1)) {
				zephir_concat_self_str(&columnSql, SL(" UNSIGNED") TSRMLS_CC);
			}
			break;
		}
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Unrecognized MySQL data type");
		return;
	} while(0);

	RETURN_CCTOR(columnSql);

}

/**
 * Generates SQL to add a column to a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	Phalcon\Db\ColumnInterface column
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, addColumn) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *afterPosition, *sql, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4, *_5, *_6;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &column);

		zephir_get_strval(tableName, tableName_param);
		zephir_get_strval(schemaName, schemaName_param);


	if ((Z_TYPE_P(column) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column definition must be an object compatible with Phalcon\\Db\\ColumnInterface");
		return;
	}
	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", schemaName);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "`.`");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, tableName TSRMLS_CC);
		ZEPHIR_CONCAT_VS(sql, _2, "` ADD ");
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", tableName);
		ZEPHIR_CONCAT_VS(sql, _0, "` ADD ");
	}
	ZEPHIR_INIT_VAR(_3);
	zephir_call_method(_3, column, "getname");
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "`", _3);
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "` ");
	ZEPHIR_INIT_VAR(_4);
	zephir_call_method_p1(_4, this_ptr, "getcolumndefinition", column);
	ZEPHIR_INIT_LNVAR(_2);
	concat_function(_2, _1, _4 TSRMLS_CC);
	zephir_concat_self(&sql, _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	zephir_call_method(_5, column, "isnotnull");
	if (zephir_is_true(_5)) {
		zephir_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_6);
	zephir_call_method(_6, column, "isfirst");
	if (zephir_is_true(_6)) {
		zephir_concat_self_str(&sql, SL(" FIRST") TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(afterPosition);
		zephir_call_method(afterPosition, column, "getafterposition");
		if (zephir_is_true(afterPosition)) {
			ZEPHIR_INIT_LNVAR(_0);
			ZEPHIR_CONCAT_SV(_0, " AFTER ", afterPosition);
			zephir_concat_self(&sql, _0 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to modify a column in a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	Phalcon\Db\ColumnInterface column
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, modifyColumn) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *sql, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4, *_5;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &column);

		zephir_get_strval(tableName, tableName_param);
		zephir_get_strval(schemaName, schemaName_param);


	if ((Z_TYPE_P(column) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column definition must be an object compatible with Phalcon\\Db\\ColumnInterface");
		return;
	}
	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", schemaName);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "`.`");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, tableName TSRMLS_CC);
		ZEPHIR_CONCAT_VS(sql, _2, "` MODIFY ");
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", tableName);
		ZEPHIR_CONCAT_VS(sql, _0, "` MODIFY ");
	}
	ZEPHIR_INIT_VAR(_3);
	zephir_call_method(_3, column, "getname");
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "`", _3);
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "` ");
	ZEPHIR_INIT_VAR(_4);
	zephir_call_method_p1(_4, this_ptr, "getcolumndefinition", column);
	ZEPHIR_INIT_LNVAR(_2);
	concat_function(_2, _1, _4 TSRMLS_CC);
	zephir_concat_self(&sql, _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	zephir_call_method(_5, column, "isnotnull");
	if (zephir_is_true(_5)) {
		zephir_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete a column from a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	string columnName
 * @return 	string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropColumn) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL, *sql, *_0 = NULL, *_1 = NULL, *_2;
	zval *tableName = NULL, *schemaName = NULL, *columnName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &columnName_param);

		zephir_get_strval(tableName, tableName_param);
		zephir_get_strval(schemaName, schemaName_param);
		zephir_get_strval(columnName, columnName_param);


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", schemaName);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "`.`");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, tableName TSRMLS_CC);
		ZEPHIR_CONCAT_VS(sql, _2, "` DROP COLUMN ");
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", tableName);
		ZEPHIR_CONCAT_VS(sql, _0, "` DROP COLUMN ");
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "`", columnName);
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "`");
	zephir_concat_self(&sql, _1 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to add an index to a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	Phalcon\Db\IndexInterface index
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, addIndex) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *sql, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4, *_5, *_6;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

		zephir_get_strval(tableName, tableName_param);
		zephir_get_strval(schemaName, schemaName_param);


	if ((Z_TYPE_P(index) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Index parameter must be an object compatible with Phalcon\\Db\\IndexInterface");
		return;
	}
	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", schemaName);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "`.`");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, tableName TSRMLS_CC);
		ZEPHIR_CONCAT_VS(sql, _2, "` ADD INDEX ");
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", tableName);
		ZEPHIR_CONCAT_VS(sql, _0, "` ADD INDEX ");
	}
	ZEPHIR_INIT_VAR(_3);
	zephir_call_method(_3, index, "getname");
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "`", _3);
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "` (");
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_INIT_VAR(_5);
	zephir_call_method(_5, index, "getcolumns");
	zephir_call_method_p1(_4, this_ptr, "getcolumnlist", _5);
	ZEPHIR_INIT_LNVAR(_2);
	concat_function(_2, _1, _4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_VS(_6, _2, ")");
	zephir_concat_self(&sql, _6 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete an index from a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	string indexName
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropIndex) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName_param = NULL, *sql, *_0 = NULL, *_1 = NULL, *_2;
	zval *tableName = NULL, *schemaName = NULL, *indexName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &indexName_param);

		zephir_get_strval(tableName, tableName_param);
		zephir_get_strval(schemaName, schemaName_param);
		zephir_get_strval(indexName, indexName_param);


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", schemaName);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "`.`");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, tableName TSRMLS_CC);
		ZEPHIR_CONCAT_VS(sql, _2, "` DROP INDEX ");
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", tableName);
		ZEPHIR_CONCAT_VS(sql, _0, "` DROP INDEX ");
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "`", indexName);
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "`");
	zephir_concat_self(&sql, _1 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to add the primary key to a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	Phalcon\Db\IndexInterface index
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, addPrimaryKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *sql, *_0 = NULL, *_1 = NULL, *_2, *_3, *_4;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

		zephir_get_strval(tableName, tableName_param);
		zephir_get_strval(schemaName, schemaName_param);


	if ((Z_TYPE_P(index) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Index parameter must be an object compatible with Phalcon\\Db\\IndexInterface");
		return;
	}
	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", schemaName);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "`.`");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, tableName TSRMLS_CC);
		ZEPHIR_CONCAT_VS(sql, _2, "` ADD PRIMARY KEY ");
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", tableName);
		ZEPHIR_CONCAT_VS(sql, _0, "` ADD PRIMARY KEY ");
	}
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_INIT_VAR(_4);
	zephir_call_method(_4, index, "getcolumns");
	zephir_call_method_p1(_3, this_ptr, "getcolumnlist", _4);
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "(", _3);
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, ")");
	zephir_concat_self(&sql, _1 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete primary key from a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropPrimaryKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *sql, *_0 = NULL, *_1, *_2;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);

		zephir_get_strval(tableName, tableName_param);
		zephir_get_strval(schemaName, schemaName_param);


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", schemaName);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "`.`");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, tableName TSRMLS_CC);
		ZEPHIR_CONCAT_VS(sql, _2, "` DROP PRIMARY KEY");
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", tableName);
		ZEPHIR_CONCAT_VS(sql, _0, "` DROP PRIMARY KEY");
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to add an index to a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	Phalcon\Db\ReferenceInterface reference
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, addForeignKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, *sql, *referencedSchema, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4, *_5, *_6, *_7 = NULL, *_8, *_9, *_10, *_11;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &reference);

		zephir_get_strval(tableName, tableName_param);
		zephir_get_strval(schemaName, schemaName_param);


	if ((Z_TYPE_P(reference) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Index parameter must be an object compatible with Phalcon\\Db\\ReferenceInterface");
		return;
	}
	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", schemaName);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "`.`");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, tableName TSRMLS_CC);
		ZEPHIR_CONCAT_VS(sql, _2, "` ADD FOREIGN KEY ");
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", tableName);
		ZEPHIR_CONCAT_VS(sql, _0, "` ADD FOREIGN KEY ");
	}
	ZEPHIR_INIT_VAR(_3);
	zephir_call_method(_3, reference, "getname");
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "`", _3);
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "`(");
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_INIT_VAR(_5);
	zephir_call_method(_5, reference, "getcolumns");
	zephir_call_method_p1(_4, this_ptr, "getcolumnlist", _5);
	ZEPHIR_INIT_LNVAR(_2);
	concat_function(_2, _1, _4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_VS(_6, _2, ") REFERENCES ");
	zephir_concat_self(&sql, _6 TSRMLS_CC);
	ZEPHIR_INIT_VAR(referencedSchema);
	zephir_call_method(referencedSchema, reference, "getreferencedschema");
	if (zephir_is_true(referencedSchema)) {
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SV(_7, "`", referencedSchema);
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_CONCAT_VS(_8, _7, "`.");
		zephir_concat_self(&sql, _8 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_9);
	zephir_call_method(_9, reference, "getreferencedtable");
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "`", _9);
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "`(");
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_INIT_VAR(_11);
	zephir_call_method(_11, reference, "getreferencedcolumns");
	zephir_call_method_p1(_10, this_ptr, "getcolumnlist", _11);
	ZEPHIR_INIT_LNVAR(_2);
	concat_function(_2, _1, _10 TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_7);
	ZEPHIR_CONCAT_VS(_7, _2, ")");
	zephir_concat_self(&sql, _7 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete a foreign key from a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	string referenceName
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropForeignKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName, *sql, *_0 = NULL, *_1 = NULL, *_2;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &referenceName);

		zephir_get_strval(tableName, tableName_param);
		zephir_get_strval(schemaName, schemaName_param);


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", schemaName);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "`.`");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, tableName TSRMLS_CC);
		ZEPHIR_CONCAT_VS(sql, _2, "` DROP FOREIGN KEY ");
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", tableName);
		ZEPHIR_CONCAT_VS(sql, _0, "` DROP FOREIGN KEY ");
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "`", referenceName);
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, "`");
	zephir_concat_self(&sql, _1 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to add the table creation options
 *
 * @param	array definition
 * @return	array
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, _getTableOptions) {

	zval *definition, *options, *engine, *autoIncrement, *tableCollation, *collationParts, *tableOptions, *_0 = NULL, _1 = zval_used_for_init, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition);



	if (zephir_array_isset_string_fetch(&options, definition, SS("options"), 1 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(tableOptions);
		array_init(tableOptions);
		if (zephir_array_isset_string_fetch(&engine, options, SS("ENGINE"), 1 TSRMLS_CC)) {
			if (zephir_is_true(engine)) {
				ZEPHIR_INIT_VAR(_0);
				ZEPHIR_CONCAT_SV(_0, "ENGINE=", engine);
				zephir_array_append(&tableOptions, _0, PH_SEPARATE);
			}
		}
		if (zephir_array_isset_string_fetch(&autoIncrement, options, SS("AUTO_INCREMENT"), 1 TSRMLS_CC)) {
			if (zephir_is_true(autoIncrement)) {
				ZEPHIR_INIT_LNVAR(_0);
				ZEPHIR_CONCAT_SV(_0, "AUTO_INCREMENT=", autoIncrement);
				zephir_array_append(&tableOptions, _0, PH_SEPARATE);
			}
		}
		if (zephir_array_isset_string_fetch(&tableCollation, options, SS("TABLE_COLLATION"), 1 TSRMLS_CC)) {
			if (zephir_is_true(tableCollation)) {
				ZEPHIR_SINIT_VAR(_1);
				ZVAL_STRING(&_1, "_", 0);
				ZEPHIR_INIT_VAR(collationParts);
				zephir_call_func_p2(collationParts, "explode", &_1, tableCollation);
				ZEPHIR_OBS_VAR(_2);
				zephir_array_fetch_long(&_2, collationParts, 0, PH_NOISY TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_0);
				ZEPHIR_CONCAT_SV(_0, "DEFAULT CHARSET=", _2);
				zephir_array_append(&tableOptions, _0, PH_SEPARATE);
				ZEPHIR_INIT_VAR(_3);
				ZEPHIR_CONCAT_SV(_3, "COLLATE=", tableCollation);
				zephir_array_append(&tableOptions, _3, PH_SEPARATE);
			}
		}
		if (zephir_fast_count_int(tableOptions TSRMLS_CC)) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_STRING(&_1, " ", 0);
			zephir_call_func_p2(return_value, "join", &_1, tableOptions);
			RETURN_MM();
		}
	}
	RETURN_MM_NULL();

}

/**
 * Generates SQL to create a table in MySQL
 *
 * @param 	string tableName
 * @param	string schemaName
 * @param	array definition
 * @return 	string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, createTable) {

	zend_function *_7 = NULL, *_9 = NULL, *_11 = NULL, *_13 = NULL, *_15 = NULL, *_19 = NULL, *_20 = NULL, *_21 = NULL, *_22 = NULL, *_23 = NULL, *_28 = NULL, *_29 = NULL, *_31 = NULL, *_34 = NULL, *_35 = NULL;
	HashTable *_4, *_17, *_26;
	HashPosition _3, _16, _25;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition, *temporary = NULL, *options, *table, *createLines, *columns, *column = NULL, *indexes, *index = NULL, *reference = NULL, *references, *indexName = NULL, *indexSql = NULL, *sql, *columnLine = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, **_5, *_6 = NULL, *_8 = NULL, *_10 = NULL, *_12 = NULL, *_14 = NULL, **_18, *_24 = NULL, **_27, *_30 = NULL, *_32 = NULL, *_33 = NULL, *_36 = NULL, *_37 = NULL, _38;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition);

		zephir_get_strval(tableName, tableName_param);
		zephir_get_strval(schemaName, schemaName_param);


	if (!(zephir_array_isset_string_fetch(&columns, definition, SS("columns"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array");
		return;
	}
	ZEPHIR_INIT_VAR(table);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "`", schemaName);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "`.`");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, tableName TSRMLS_CC);
		ZEPHIR_CONCAT_VS(table, _2, "`");
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "`", tableName);
		ZEPHIR_CONCAT_VS(table, _0, "`");
	}
	ZEPHIR_INIT_VAR(temporary);
	ZVAL_BOOL(temporary, 0);
	if (zephir_array_isset_string_fetch(&options, definition, SS("options"), 1 TSRMLS_CC)) {
		ZEPHIR_OBS_NVAR(temporary);
	}
	ZEPHIR_INIT_VAR(sql);
	if (zephir_is_true(temporary)) {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "CREATE TEMPORARY TABLE ", table);
		ZEPHIR_CONCAT_VS(sql, _0, " (\n\t");
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "CREATE TABLE ", table);
		ZEPHIR_CONCAT_VS(sql, _0, " (\n\t");
	}
	ZEPHIR_INIT_VAR(createLines);
	array_init(createLines);
	zephir_is_iterable(columns, &_4, &_3, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(column, _5);
		ZEPHIR_INIT_NVAR(_6);
		zephir_call_method_cache(_6, column, "getname", &_7);
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "`", _6);
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "` ");
		ZEPHIR_INIT_NVAR(_8);
		zephir_call_method_p1_cache(_8, this_ptr, "getcolumndefinition", &_9, column);
		ZEPHIR_INIT_NVAR(columnLine);
		concat_function(columnLine, _1, _8 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_10);
		zephir_call_method_cache(_10, column, "isnotnull", &_11);
		if (zephir_is_true(_10)) {
			zephir_concat_self_str(&columnLine, SL(" NOT NULL") TSRMLS_CC);
		}
		ZEPHIR_INIT_NVAR(_12);
		zephir_call_method_cache(_12, column, "isautoincrement", &_13);
		if (zephir_is_true(_12)) {
			zephir_concat_self_str(&columnLine, SL(" AUTO_INCREMENT") TSRMLS_CC);
		}
		ZEPHIR_INIT_NVAR(_14);
		zephir_call_method_cache(_14, column, "isprimary", &_15);
		if (zephir_is_true(_14)) {
			zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY") TSRMLS_CC);
		}
		zephir_array_append(&createLines, columnLine, PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&indexes, definition, SS("indexes"), 1 TSRMLS_CC)) {
		zephir_is_iterable(indexes, &_17, &_16, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_17, (void**) &_18, &_16) == SUCCESS
			; zend_hash_move_forward_ex(_17, &_16)
		) {
			ZEPHIR_GET_HVALUE(index, _18);
			ZEPHIR_INIT_NVAR(indexName);
			zephir_call_method_cache(indexName, index, "getname", &_19);
			ZEPHIR_INIT_NVAR(indexSql);
			if (ZEPHIR_IS_STRING(indexName, "PRIMARY")) {
				ZEPHIR_INIT_NVAR(_6);
				ZEPHIR_INIT_NVAR(_8);
				zephir_call_method_cache(_8, index, "getcolumns", &_20);
				zephir_call_method_p1_cache(_6, this_ptr, "getcolumnlist", &_21, _8);
				ZEPHIR_INIT_LNVAR(_0);
				ZEPHIR_CONCAT_SV(_0, "PRIMARY KEY (", _6);
				ZEPHIR_CONCAT_VS(indexSql, _0, ")");
			} else {
				ZEPHIR_INIT_LNVAR(_1);
				ZEPHIR_CONCAT_SV(_1, "KEY `", indexName);
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_VS(_2, _1, "` (");
				ZEPHIR_INIT_NVAR(_10);
				ZEPHIR_INIT_NVAR(_12);
				zephir_call_method_cache(_12, index, "getcolumns", &_22);
				zephir_call_method_p1_cache(_10, this_ptr, "getcolumnlist", &_23, _12);
				ZEPHIR_INIT_LNVAR(_24);
				concat_function(_24, _2, _10 TSRMLS_CC);
				ZEPHIR_CONCAT_VS(indexSql, _24, ")");
			}
			zephir_array_append(&createLines, indexSql, PH_SEPARATE);
		}
	}
	if (zephir_array_isset_string_fetch(&references, definition, SS("references"), 1 TSRMLS_CC)) {
		zephir_is_iterable(references, &_26, &_25, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_26, (void**) &_27, &_25) == SUCCESS
			; zend_hash_move_forward_ex(_26, &_25)
		) {
			ZEPHIR_GET_HVALUE(reference, _27);
			ZEPHIR_INIT_NVAR(_6);
			zephir_call_method_cache(_6, reference, "getname", &_28);
			ZEPHIR_INIT_LNVAR(_0);
			ZEPHIR_CONCAT_SV(_0, "CONSTRAINT `", _6);
			ZEPHIR_INIT_LNVAR(_1);
			ZEPHIR_CONCAT_VS(_1, _0, "` FOREIGN KEY (");
			ZEPHIR_INIT_NVAR(_8);
			zephir_call_method_p1_cache(_8, this_ptr, "getcolumnlist", &_29, columns);
			ZEPHIR_INIT_LNVAR(_2);
			concat_function(_2, _1, _8 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_24);
			ZEPHIR_CONCAT_VS(_24, _2, ")");
			ZEPHIR_INIT_LNVAR(_30);
			ZEPHIR_CONCAT_VS(_30, _24, " REFERENCES `");
			ZEPHIR_INIT_NVAR(_10);
			zephir_call_method_cache(_10, reference, "getreferencedtable", &_31);
			ZEPHIR_INIT_LNVAR(_32);
			concat_function(_32, _30, _10 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_33);
			ZEPHIR_CONCAT_VS(_33, _32, "`(");
			ZEPHIR_INIT_NVAR(_12);
			ZEPHIR_INIT_NVAR(_14);
			zephir_call_method_cache(_14, reference, "getreferencedcolumns", &_34);
			zephir_call_method_p1_cache(_12, this_ptr, "getcolumnlist", &_35, _14);
			ZEPHIR_INIT_LNVAR(_36);
			concat_function(_36, _33, _12 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_37);
			ZEPHIR_CONCAT_VS(_37, _36, ")");
			zephir_array_append(&createLines, _37, PH_SEPARATE);
		}
	}
	ZEPHIR_SINIT_VAR(_38);
	ZVAL_STRING(&_38, ",\n\t", 0);
	ZEPHIR_INIT_NVAR(_6);
	zephir_call_func_p2(_6, "join", &_38, createLines);
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_VS(_0, _6, "\n)");
	zephir_concat_self(&sql, _0 TSRMLS_CC);
	if (zephir_array_isset_string(definition, SS("options"))) {
		ZEPHIR_INIT_NVAR(_8);
		zephir_call_method_p1(_8, this_ptr, "_gettableoptions", definition);
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_SV(_1, " ", _8);
		zephir_concat_self(&sql, _1 TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to drop a table
 *
 * @param  string tableName
 * @param  string schemaName
 * @param  boolean ifExists
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropTable) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists = NULL, *sql, *table, *_0 = NULL, *_1, *_2;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &tableName_param, &schemaName_param, &ifExists);

		zephir_get_strval(tableName, tableName_param);
		zephir_get_strval(schemaName, schemaName_param);
	if (!ifExists) {
		ZEPHIR_CPY_WRT(ifExists, ZEPHIR_GLOBAL(global_true));
	}


	ZEPHIR_INIT_VAR(table);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "`", schemaName);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "`.`");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, tableName TSRMLS_CC);
		ZEPHIR_CONCAT_VS(table, _2, "`");
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "`", tableName);
		ZEPHIR_CONCAT_VS(table, _0, "`");
	}
	ZEPHIR_INIT_VAR(sql);
	if (zephir_is_true(ifExists)) {
		ZEPHIR_CONCAT_SV(sql, "DROP TABLE IF EXISTS ", table);
	} else {
		ZEPHIR_CONCAT_SV(sql, "DROP TABLE ", table);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to create a view
 *
 * @param string viewName
 * @param array definition
 * @param string schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, createView) {

	zval *viewName_param = NULL, *definition, *schemaName_param = NULL, *view, *viewSql, *_0 = NULL, *_1 = NULL, *_2;
	zval *viewName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &viewName_param, &definition, &schemaName_param);

		zephir_get_strval(viewName, viewName_param);
		zephir_get_strval(schemaName, schemaName_param);


	if (zephir_array_isset_string_fetch(&viewSql, definition, SS("sql"), 1 TSRMLS_CC)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array");
		return;
	}
	ZEPHIR_INIT_VAR(view);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "`", schemaName);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "`.`");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, viewName TSRMLS_CC);
		ZEPHIR_CONCAT_VS(view, _2, "`");
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "`", viewName);
		ZEPHIR_CONCAT_VS(view, _0, "`");
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "CREATE VIEW ", view);
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, " AS ");
	concat_function(return_value, _1, viewSql TSRMLS_CC);
	RETURN_MM();

}

/**
 * Generates SQL to drop a view
 *
 * @param string viewName
 * @param string schemaName
 * @param boolean ifExists
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropView) {

	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *sql, *view = NULL, *_0;
	zval *viewName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &viewName_param, &schemaName_param, &ifExists_param);

		zephir_get_strval(viewName, viewName_param);
		zephir_get_strval(schemaName, schemaName_param);
	if (!ifExists_param) {
		ifExists = 1;
	} else {
		ifExists = zephir_get_boolval(ifExists_param);
	}


	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VS(_0, schemaName, ".");
		ZEPHIR_INIT_VAR(view);
		concat_function(view, _0, viewName TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(view, viewName);
	}
	ZEPHIR_INIT_VAR(sql);
	if (ifExists) {
		ZEPHIR_CONCAT_SV(sql, "DROP VIEW IF EXISTS ", view);
	} else {
		ZEPHIR_CONCAT_SV(sql, "DROP VIEW ", view);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * <code>
 * echo $dialect->tableExists("posts", "blog");
 * echo $dialect->tableExists("posts");
 * </code>
 *
 * @param string tableName
 * @param string schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, tableExists) {

	zval *tableName_param = NULL, *schemaName = NULL, *_0 = NULL, *_1, *_2;
	zval *tableName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tableName_param, &schemaName);

		zephir_get_strval(tableName, tableName_param);
	if (!schemaName) {
		ZEPHIR_CPY_WRT(schemaName, ZEPHIR_GLOBAL(global_null));
	}


	if (zephir_is_true(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", tableName);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "' AND `TABLE_SCHEMA` = '");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, schemaName TSRMLS_CC);
		ZEPHIR_CONCAT_VS(return_value, _2, "'");
		RETURN_MM();
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME` = '", tableName);
	ZEPHIR_CONCAT_VS(return_value, _0, "'");
	RETURN_MM();

}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 * @param string viewName
 * @param string schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, viewExists) {

	zval *viewName_param = NULL, *schemaName = NULL, *_0 = NULL, *_1, *_2;
	zval *viewName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewName_param, &schemaName);

		zephir_get_strval(viewName, viewName_param);
	if (!schemaName) {
		ZEPHIR_CPY_WRT(schemaName, ZEPHIR_GLOBAL(global_null));
	}


	if (zephir_is_true(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`= '", viewName);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "' AND `TABLE_SCHEMA`='");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, schemaName TSRMLS_CC);
		ZEPHIR_CONCAT_VS(return_value, _2, "'");
		RETURN_MM();
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`='", viewName);
	ZEPHIR_CONCAT_VS(return_value, _0, "'");
	RETURN_MM();

}

/**
 * Generates SQL describing a table
 *
 *<code>
 *	print_r($dialect->describeColumns("posts"));
 *</code>
 *
 * @param string table
 * @param string schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, describeColumns) {

	zval *table_param = NULL, *schema = NULL, *_0 = NULL, *_1, *_2;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema);

		zephir_get_strval(table, table_param);
	if (!schema) {
		ZEPHIR_CPY_WRT(schema, ZEPHIR_GLOBAL(global_null));
	}


	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "DESCRIBE `", schema);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "`.`");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, table TSRMLS_CC);
		ZEPHIR_CONCAT_VS(return_value, _2, "`");
		RETURN_MM();
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "DESCRIBE `", table);
	ZEPHIR_CONCAT_VS(return_value, _0, "`");
	RETURN_MM();

}

/**
 * List all tables on database
 *
 *<code>
 *	print_r($dialect->listTables("blog"))
 *</code>
 *
 * @param       string schemaName
 * @return      array
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, listTables) {

	zval *schemaName = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName);

	if (!schemaName) {
		ZEPHIR_CPY_WRT(schemaName, ZEPHIR_GLOBAL(global_null));
	}


	if (zephir_is_true(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "SHOW TABLES FROM `", schemaName);
		ZEPHIR_CONCAT_VS(return_value, _0, "`");
		RETURN_MM();
	}
	RETURN_MM_STRING("SHOW TABLES", 1);

}

/**
 * Generates the SQL to list all views of a schema or user
 *
 * @param string schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, listViews) {

	zval *schemaName = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName);

	if (!schemaName) {
		ZEPHIR_CPY_WRT(schemaName, ZEPHIR_GLOBAL(global_null));
	}


	if (zephir_is_true(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = '", schemaName);
		ZEPHIR_CONCAT_VS(return_value, _0, "' ORDER BY view_name");
		RETURN_MM();
	}
	RETURN_MM_STRING("SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` ORDER BY view_name", 1);

}

/**
 * Generates SQL to query indexes on a table
 *
 * @param	string table
 * @param	string schema
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, describeIndexes) {

	zval *table_param = NULL, *schema = NULL, *_0 = NULL, *_1, *_2;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema);

		zephir_get_strval(table, table_param);
	if (!schema) {
		ZEPHIR_CPY_WRT(schema, ZEPHIR_GLOBAL(global_null));
	}


	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "SHOW INDEXES FROM `", schema);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "`.`");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, table TSRMLS_CC);
		ZEPHIR_CONCAT_VS(return_value, _2, "`");
		RETURN_MM();
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SV(_0, "SHOW INDEXES FROM `", table);
	ZEPHIR_CONCAT_VS(return_value, _0, "`");
	RETURN_MM();

}

/**
 * Generates SQL to query foreign keys on a table
 *
 * @param	string table
 * @param	string schema
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, describeReferences) {

	zval *table, *schema = NULL, *sql, *_0 = NULL, *_1 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &schema);

	if (!schema) {
		ZEPHIR_CPY_WRT(schema, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT TABLE_NAME,COLUMN_NAME,CONSTRAINT_NAME,REFERENCED_TABLE_SCHEMA,REFERENCED_TABLE_NAME,REFERENCED_COLUMN_NAME FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE WHERE REFERENCED_TABLE_NAME IS NOT NULL AND ", 1);


	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "CONSTRAINT_SCHEMA = '", schema);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "' AND TABLE_NAME = '");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, table TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_VS(_3, _2, "'");
		zephir_concat_self(&sql, _3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "TABLE_NAME = '", table);
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "'");
		zephir_concat_self(&sql, _1 TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates the SQL to describe the table creation options
 *
 * @param	string table
 * @param	string schema
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, tableOptions) {

	zval *table, *schema = NULL, *sql, *_0 = NULL, *_1 = NULL, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &schema);

	if (!schema) {
		ZEPHIR_CPY_WRT(schema, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT TABLES.TABLE_TYPE AS table_type,TABLES.AUTO_INCREMENT AS auto_increment,TABLES.ENGINE AS engine,TABLES.TABLE_COLLATION AS table_collation FROM INFORMATION_SCHEMA.TABLES WHERE ", 1);


	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "TABLES.TABLE_SCHEMA = '", schema);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "' AND TABLES.TABLE_NAME = '");
		ZEPHIR_INIT_VAR(_2);
		concat_function(_2, _1, table TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_VS(_3, _2, "'");
		zephir_concat_self(&sql, _3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "TABLES.TABLE_NAME = '", table);
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_VS(_1, _0, "'");
		zephir_concat_self(&sql, _1 TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

