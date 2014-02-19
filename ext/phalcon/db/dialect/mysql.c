
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/hash.h"


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

	zval *column, *columnSql = NULL, *size, *scale, *_0, *_1 = NULL, *_2 = NULL, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	if (!(zephir_is_instance_of(column, SL("Phalcon\\Db\\ColumnInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'column' must be an instance of 'Phalcon\\Db\\ColumnInterface'");
		return;
	}
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
			ZEPHIR_INIT_VAR(columnSql);
			ZEPHIR_CONCAT_SVS(columnSql, "INT(", _1, ")");
			ZEPHIR_INIT_VAR(_2);
			zephir_call_method(_2, column, "isunsigned");
			if (zephir_is_true(_2)) {
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
			ZEPHIR_INIT_NVAR(columnSql);
			ZEPHIR_CONCAT_SVS(columnSql, "VARCHAR(", _1, ")");
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 3)) {
			ZEPHIR_INIT_NVAR(_1);
			zephir_call_method(_1, column, "getsize");
			ZEPHIR_INIT_NVAR(_2);
			zephir_call_method(_2, column, "getscale");
			ZEPHIR_INIT_NVAR(columnSql);
			ZEPHIR_CONCAT_SVSVS(columnSql, "DECIMAL(", _1, ",", _2, ")");
			ZEPHIR_INIT_VAR(_3);
			zephir_call_method(_3, column, "isunsigned");
			if (zephir_is_true(_3)) {
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
			ZEPHIR_INIT_NVAR(columnSql);
			ZEPHIR_CONCAT_SVS(columnSql, "CHAR(", _1, ")");
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
				ZEPHIR_INIT_VAR(_4);
				ZEPHIR_CONCAT_SV(_4, "(", size);
				zephir_concat_self(&columnSql, _4 TSRMLS_CC);
				if (zephir_is_true(scale)) {
					ZEPHIR_INIT_VAR(_5);
					ZEPHIR_CONCAT_SVS(_5, ",", scale, ")");
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *afterPosition, *sql = NULL, *_1, *_2, *_3, *_4, *_5, *_6;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &column);

	if (Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(tableName_param) == IS_STRING) {
		tableName = tableName_param;
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(schemaName_param) == IS_STRING) {
		schemaName = schemaName_param;
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	if (!(zephir_is_instance_of(column, SL("Phalcon\\Db\\ColumnInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'column' must be an instance of 'Phalcon\\Db\\ColumnInterface'");
		return;
	}
	if ((Z_TYPE_P(column) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column definition must be an object compatible with Phalcon\\Db\\ColumnInterface");
		return;
	}
	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` ADD ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` ADD ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, column, "getname");
	ZEPHIR_INIT_VAR(_2);
	zephir_call_method_p1(_2, this_ptr, "getcolumndefinition", column);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVSV(_3, "`", _1, "` ", _2);
	zephir_concat_self(&sql, _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_call_method(_4, column, "isnotnull");
	if (zephir_is_true(_4)) {
		zephir_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_call_method(_5, column, "isfirst");
	if (zephir_is_true(_5)) {
		zephir_concat_self_str(&sql, SL(" FIRST") TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(afterPosition);
		zephir_call_method(afterPosition, column, "getafterposition");
		if (zephir_is_true(afterPosition)) {
			ZEPHIR_INIT_VAR(_6);
			ZEPHIR_CONCAT_SV(_6, " AFTER ", afterPosition);
			zephir_concat_self(&sql, _6 TSRMLS_CC);
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *sql = NULL, *_1, *_2, *_3, *_4;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &column);

	if (Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(tableName_param) == IS_STRING) {
		tableName = tableName_param;
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(schemaName_param) == IS_STRING) {
		schemaName = schemaName_param;
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	if (!(zephir_is_instance_of(column, SL("Phalcon\\Db\\ColumnInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'column' must be an instance of 'Phalcon\\Db\\ColumnInterface'");
		return;
	}
	if ((Z_TYPE_P(column) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column definition must be an object compatible with Phalcon\\Db\\ColumnInterface");
		return;
	}
	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` MODIFY ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` MODIFY ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, column, "getname");
	ZEPHIR_INIT_VAR(_2);
	zephir_call_method_p1(_2, this_ptr, "getcolumndefinition", column);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVSV(_3, "`", _1, "` ", _2);
	zephir_concat_self(&sql, _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_call_method(_4, column, "isnotnull");
	if (zephir_is_true(_4)) {
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL, *sql = NULL;
	zval *tableName = NULL, *schemaName = NULL, *columnName = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &columnName_param);

	if (Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(tableName_param) == IS_STRING) {
		tableName = tableName_param;
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(schemaName_param) == IS_STRING) {
		schemaName = schemaName_param;
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	zephir_get_strval(columnName, columnName_param);


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` DROP COLUMN ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` DROP COLUMN ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "`", columnName, "`");
	zephir_concat_self(&sql, _0 TSRMLS_CC);
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *sql = NULL, *_1, *_2, *_3, *_4;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(tableName_param) == IS_STRING) {
		tableName = tableName_param;
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(schemaName_param) == IS_STRING) {
		schemaName = schemaName_param;
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	if (!(zephir_is_instance_of(index, SL("Phalcon\\Db\\IndexInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'index' must be an instance of 'Phalcon\\Db\\IndexInterface'");
		return;
	}
	if ((Z_TYPE_P(index) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Index parameter must be an object compatible with Phalcon\\Db\\IndexInterface");
		return;
	}
	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` ADD INDEX ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` ADD INDEX ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, index, "getname");
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_method(_3, index, "getcolumns");
	zephir_call_method_p1(_2, this_ptr, "getcolumnlist", _3);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVSVS(_4, "`", _1, "` (", _2, ")");
	zephir_concat_self(&sql, _4 TSRMLS_CC);
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName_param = NULL, *sql = NULL;
	zval *tableName = NULL, *schemaName = NULL, *indexName = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &indexName_param);

	if (Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(tableName_param) == IS_STRING) {
		tableName = tableName_param;
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(schemaName_param) == IS_STRING) {
		schemaName = schemaName_param;
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	if (Z_TYPE_P(indexName_param) != IS_STRING && Z_TYPE_P(indexName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'indexName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(indexName_param) == IS_STRING) {
		indexName = indexName_param;
	} else {
		ZEPHIR_INIT_VAR(indexName);
		ZVAL_EMPTY_STRING(indexName);
	}


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` DROP INDEX ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` DROP INDEX ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "`", indexName, "`");
	zephir_concat_self(&sql, _0 TSRMLS_CC);
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *sql = NULL, *_1, *_2, *_3;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	zephir_get_strval(tableName, tableName_param);
	zephir_get_strval(schemaName, schemaName_param);


	if (!(zephir_is_instance_of(index, SL("Phalcon\\Db\\IndexInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'index' must be an instance of 'Phalcon\\Db\\IndexInterface'");
		return;
	}
	if ((Z_TYPE_P(index) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Index parameter must be an object compatible with Phalcon\\Db\\IndexInterface");
		return;
	}
	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` ADD PRIMARY KEY ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` ADD PRIMARY KEY ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_method(_2, index, "getcolumns");
	zephir_call_method_p1(_1, this_ptr, "getcolumnlist", _2);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, "(", _1, ")");
	zephir_concat_self(&sql, _3 TSRMLS_CC);
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *sql = NULL;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);

	if (Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(tableName_param) == IS_STRING) {
		tableName = tableName_param;
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(schemaName_param) == IS_STRING) {
		schemaName = schemaName_param;
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` DROP PRIMARY KEY");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` DROP PRIMARY KEY");
		ZEPHIR_CPY_WRT(sql, _0);
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, *sql = NULL, *referencedSchema, *_1, *_2, *_3, *_4, *_5 = NULL, *_6, *_7, *_8;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &reference);

	if (Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(tableName_param) == IS_STRING) {
		tableName = tableName_param;
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(schemaName_param) == IS_STRING) {
		schemaName = schemaName_param;
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	if (!(zephir_is_instance_of(reference, SL("Phalcon\\Db\\ReferenceInterface") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(spl_ce_InvalidArgumentException, "Parameter 'reference' must be an instance of 'Phalcon\\Db\\ReferenceInterface'");
		return;
	}
	if ((Z_TYPE_P(reference) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Index parameter must be an object compatible with Phalcon\\Db\\ReferenceInterface");
		return;
	}
	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` ADD FOREIGN KEY ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` ADD FOREIGN KEY ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, reference, "getname");
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_method(_3, reference, "getcolumns");
	zephir_call_method_p1(_2, this_ptr, "getcolumnlist", _3);
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVSVS(_4, "`", _1, "`(", _2, ") REFERENCES ");
	zephir_concat_self(&sql, _4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(referencedSchema);
	zephir_call_method(referencedSchema, reference, "getreferencedschema");
	if (zephir_is_true(referencedSchema)) {
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_SVS(_5, "`", referencedSchema, "`.");
		zephir_concat_self(&sql, _5 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_6);
	zephir_call_method(_6, reference, "getreferencedtable");
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_INIT_VAR(_8);
	zephir_call_method(_8, reference, "getreferencedcolumns");
	zephir_call_method_p1(_7, this_ptr, "getcolumnlist", _8);
	ZEPHIR_INIT_LNVAR(_5);
	ZEPHIR_CONCAT_SVSVS(_5, "`", _6, "`(", _7, ")");
	zephir_concat_self(&sql, _5 TSRMLS_CC);
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName, *sql = NULL, *_1;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &referenceName);

	if (Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(tableName_param) == IS_STRING) {
		tableName = tableName_param;
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(schemaName_param) == IS_STRING) {
		schemaName = schemaName_param;
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` DROP FOREIGN KEY ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` DROP FOREIGN KEY ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "`", referenceName, "`");
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

	zval *definition, *options, *engine, *autoIncrement, *tableCollation, *collationParts, *tableOptions, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition);



	ZEPHIR_OBS_VAR(options);
	if (zephir_array_isset_string_fetch(&options, definition, SS("options"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(tableOptions);
		array_init(tableOptions);
		ZEPHIR_OBS_VAR(engine);
		if (zephir_array_isset_string_fetch(&engine, options, SS("ENGINE"), 0 TSRMLS_CC)) {
			if (zephir_is_true(engine)) {
				ZEPHIR_INIT_VAR(_0);
				ZEPHIR_CONCAT_SV(_0, "ENGINE=", engine);
				zephir_array_append(&tableOptions, _0, PH_SEPARATE);
			}
		}
		ZEPHIR_OBS_VAR(autoIncrement);
		if (zephir_array_isset_string_fetch(&autoIncrement, options, SS("AUTO_INCREMENT"), 0 TSRMLS_CC)) {
			if (zephir_is_true(autoIncrement)) {
				ZEPHIR_INIT_LNVAR(_0);
				ZEPHIR_CONCAT_SV(_0, "AUTO_INCREMENT=", autoIncrement);
				zephir_array_append(&tableOptions, _0, PH_SEPARATE);
			}
		}
		ZEPHIR_OBS_VAR(tableCollation);
		if (zephir_array_isset_string_fetch(&tableCollation, options, SS("TABLE_COLLATION"), 0 TSRMLS_CC)) {
			if (zephir_is_true(tableCollation)) {
				ZEPHIR_INIT_VAR(collationParts);
				zephir_fast_explode_str(collationParts, SL("_"), tableCollation, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_1, collationParts, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_0);
				ZEPHIR_CONCAT_SV(_0, "DEFAULT CHARSET=", _1);
				zephir_array_append(&tableOptions, _0, PH_SEPARATE);
				ZEPHIR_INIT_VAR(_2);
				ZEPHIR_CONCAT_SV(_2, "COLLATE=", tableCollation);
				zephir_array_append(&tableOptions, _2, PH_SEPARATE);
			}
		}
		if (zephir_fast_count_int(tableOptions TSRMLS_CC)) {
			zephir_fast_join_str(return_value, SL(" "), tableOptions TSRMLS_CC);
			RETURN_MM();
		}
	}
	RETURN_MM_STRING("", 1);

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

	zend_function *_6 = NULL, *_13 = NULL, *_14 = NULL, *_18 = NULL, *_19 = NULL;
	HashTable *_2, *_11, *_16;
	HashPosition _1, _10, _15;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition, *temporary = NULL, *options, *table = NULL, *createLines, *columns, *column = NULL, *indexes, *index = NULL, *reference = NULL, *references, *indexName = NULL, *indexSql = NULL, *sql, *columnLine = NULL, **_3, *_4 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, **_12, **_17, *_20 = NULL, *_21;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition);

	if (Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(tableName_param) == IS_STRING) {
		tableName = tableName_param;
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(schemaName_param) == IS_STRING) {
		schemaName = schemaName_param;
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, definition, SS("columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array");
		return;
	}
	ZEPHIR_INIT_VAR(table);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "`", schemaName, "`.`", tableName, "`");
		ZEPHIR_CPY_WRT(table, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "`", tableName, "`");
		ZEPHIR_CPY_WRT(table, _0);
	}
	ZEPHIR_INIT_VAR(temporary);
	ZVAL_BOOL(temporary, 0);
	ZEPHIR_OBS_VAR(options);
	if (zephir_array_isset_string_fetch(&options, definition, SS("options"), 0 TSRMLS_CC)) {
		ZEPHIR_OBS_NVAR(temporary);
	}
	ZEPHIR_INIT_VAR(sql);
	if (zephir_is_true(temporary)) {
		ZEPHIR_CONCAT_SVS(sql, "CREATE TEMPORARY TABLE ", table, " (\n\t");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "CREATE TABLE ", table, " (\n\t");
	}
	ZEPHIR_INIT_VAR(createLines);
	array_init(createLines);
	zephir_is_iterable(columns, &_2, &_1, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(column, _3);
		ZEPHIR_INIT_NVAR(_4);
		zephir_call_method(_4, column, "getname");
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_method_p1_cache(_5, this_ptr, "getcolumndefinition", &_6, column);
		ZEPHIR_INIT_NVAR(columnLine);
		ZEPHIR_CONCAT_SVSV(columnLine, "`", _4, "` ", _5);
		ZEPHIR_INIT_NVAR(_7);
		zephir_call_method(_7, column, "isnotnull");
		if (zephir_is_true(_7)) {
			zephir_concat_self_str(&columnLine, SL(" NOT NULL") TSRMLS_CC);
		}
		ZEPHIR_INIT_NVAR(_8);
		zephir_call_method(_8, column, "isautoincrement");
		if (zephir_is_true(_8)) {
			zephir_concat_self_str(&columnLine, SL(" AUTO_INCREMENT") TSRMLS_CC);
		}
		ZEPHIR_INIT_NVAR(_9);
		zephir_call_method(_9, column, "isprimary");
		if (zephir_is_true(_9)) {
			zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY") TSRMLS_CC);
		}
		zephir_array_append(&createLines, columnLine, PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(indexes);
	if (zephir_array_isset_string_fetch(&indexes, definition, SS("indexes"), 0 TSRMLS_CC)) {
		zephir_is_iterable(indexes, &_11, &_10, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
		  ; zephir_hash_move_forward_ex(_11, &_10)
		) {
			ZEPHIR_GET_HVALUE(index, _12);
			ZEPHIR_INIT_NVAR(indexName);
			zephir_call_method(indexName, index, "getname");
			ZEPHIR_INIT_NVAR(indexSql);
			if (ZEPHIR_IS_STRING(indexName, "PRIMARY")) {
				ZEPHIR_INIT_NVAR(_4);
				ZEPHIR_INIT_NVAR(_5);
				zephir_call_method(_5, index, "getcolumns");
				zephir_call_method_p1_cache(_4, this_ptr, "getcolumnlist", &_13, _5);
				ZEPHIR_CONCAT_SVS(indexSql, "PRIMARY KEY (", _4, ")");
			} else {
				ZEPHIR_INIT_NVAR(_7);
				ZEPHIR_INIT_NVAR(_8);
				zephir_call_method(_8, index, "getcolumns");
				zephir_call_method_p1_cache(_7, this_ptr, "getcolumnlist", &_14, _8);
				ZEPHIR_CONCAT_SVSVS(indexSql, "KEY `", indexName, "` (", _7, ")");
			}
			zephir_array_append(&createLines, indexSql, PH_SEPARATE);
		}
	}
	ZEPHIR_OBS_VAR(references);
	if (zephir_array_isset_string_fetch(&references, definition, SS("references"), 0 TSRMLS_CC)) {
		zephir_is_iterable(references, &_16, &_15, 0, 0);
		for (
		  ; zephir_hash_get_current_data_ex(_16, (void**) &_17, &_15) == SUCCESS
		  ; zephir_hash_move_forward_ex(_16, &_15)
		) {
			ZEPHIR_GET_HVALUE(reference, _17);
			ZEPHIR_INIT_NVAR(_4);
			zephir_call_method(_4, reference, "getname");
			ZEPHIR_INIT_NVAR(_5);
			zephir_call_method_p1_cache(_5, this_ptr, "getcolumnlist", &_18, columns);
			ZEPHIR_INIT_NVAR(_7);
			zephir_call_method(_7, reference, "getreferencedtable");
			ZEPHIR_INIT_NVAR(_8);
			ZEPHIR_INIT_NVAR(_9);
			zephir_call_method(_9, reference, "getreferencedcolumns");
			zephir_call_method_p1_cache(_8, this_ptr, "getcolumnlist", &_19, _9);
			ZEPHIR_INIT_LNVAR(_20);
			ZEPHIR_CONCAT_SVSVSSVSVS(_20, "CONSTRAINT `", _4, "` FOREIGN KEY (", _5, ")", " REFERENCES `", _7, "`(", _8, ")");
			zephir_array_append(&createLines, _20, PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(_4);
	zephir_fast_join_str(_4, SL(",\n\t"), createLines TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_20);
	ZEPHIR_CONCAT_VS(_20, _4, "\n)");
	zephir_concat_self(&sql, _20 TSRMLS_CC);
	if (zephir_array_isset_string(definition, SS("options"))) {
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_method_p1(_5, this_ptr, "_gettableoptions", definition);
		ZEPHIR_INIT_VAR(_21);
		ZEPHIR_CONCAT_SV(_21, " ", _5);
		zephir_concat_self(&sql, _21 TSRMLS_CC);
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists = NULL, *sql, *table = NULL;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &tableName_param, &schemaName_param, &ifExists);

	if (Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(tableName_param) == IS_STRING) {
		tableName = tableName_param;
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(schemaName_param) == IS_STRING) {
		schemaName = schemaName_param;
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	if (!ifExists) {
		ifExists = ZEPHIR_GLOBAL(global_true);
	}


	ZEPHIR_INIT_VAR(table);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "`", schemaName, "`.`", tableName, "`");
		ZEPHIR_CPY_WRT(table, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "`", tableName, "`");
		ZEPHIR_CPY_WRT(table, _0);
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

	zval *viewName_param = NULL, *definition, *schemaName_param = NULL, *view = NULL, *viewSql;
	zval *viewName = NULL, *schemaName = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &viewName_param, &definition, &schemaName_param);

	if (Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(viewName_param) == IS_STRING) {
		viewName = viewName_param;
	} else {
		ZEPHIR_INIT_VAR(viewName);
		ZVAL_EMPTY_STRING(viewName);
	}
	if (Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(schemaName_param) == IS_STRING) {
		schemaName = schemaName_param;
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	ZEPHIR_OBS_VAR(viewSql);
	if (!(zephir_array_isset_string_fetch(&viewSql, definition, SS("sql"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array");
		return;
	}
	ZEPHIR_INIT_VAR(view);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "`", schemaName, "`.`", viewName, "`");
		ZEPHIR_CPY_WRT(view, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "`", viewName, "`");
		ZEPHIR_CPY_WRT(view, _0);
	}
	ZEPHIR_CONCAT_SVSV(return_value, "CREATE VIEW ", view, " AS ", viewSql);
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
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *sql, *view = NULL;
	zval *viewName = NULL, *schemaName = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &viewName_param, &schemaName_param, &ifExists_param);

	if (Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(viewName_param) == IS_STRING) {
		viewName = viewName_param;
	} else {
		ZEPHIR_INIT_VAR(viewName);
		ZVAL_EMPTY_STRING(viewName);
	}
	if (Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(schemaName_param) == IS_STRING) {
		schemaName = schemaName_param;
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
		ifExists = zephir_get_boolval(ifExists_param);
	}


	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VSV(_0, schemaName, ".", viewName);
		ZEPHIR_CPY_WRT(view, _0);
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

	zval *tableName_param = NULL, *schemaName = NULL;
	zval *tableName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tableName_param, &schemaName);

	if (Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(tableName_param) == IS_STRING) {
		tableName = tableName_param;
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (!schemaName) {
		schemaName = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_is_true(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", tableName, "' AND `TABLE_SCHEMA` = '", schemaName, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME` = '", tableName, "'");
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

	zval *viewName_param = NULL, *schemaName = NULL;
	zval *viewName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewName_param, &schemaName);

	if (Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(viewName_param) == IS_STRING) {
		viewName = viewName_param;
	} else {
		ZEPHIR_INIT_VAR(viewName);
		ZVAL_EMPTY_STRING(viewName);
	}
	if (!schemaName) {
		schemaName = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_is_true(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`= '", viewName, "' AND `TABLE_SCHEMA`='", schemaName, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT IF(COUNT(*)>0, 1 , 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`='", viewName, "'");
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

	zval *table_param = NULL, *schema = NULL;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema);

	if (Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(table_param) == IS_STRING) {
		table = table_param;
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema) {
		schema = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_is_true(schema)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "DESCRIBE `", schema, "`.`", table, "`");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "DESCRIBE `", table, "`");
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

	zval *schemaName_param = NULL;
	zval *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
	if (Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(schemaName_param) == IS_STRING) {
		schemaName = schemaName_param;
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	}


	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVS(return_value, "SHOW TABLES FROM `", schemaName, "`");
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

	zval *schemaName_param = NULL;
	zval *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
	if (Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(schemaName_param) == IS_STRING) {
		schemaName = schemaName_param;
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	}


	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVS(return_value, "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = '", schemaName, "' ORDER BY view_name");
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

	zval *table_param = NULL, *schema = NULL;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema);

	if (Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(table_param) == IS_STRING) {
		table = table_param;
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema) {
		schema = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_is_true(schema)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SHOW INDEXES FROM `", schema, "`.`", table, "`");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SHOW INDEXES FROM `", table, "`");
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

	zval *table_param = NULL, *schema = NULL, *sql, *_0;
	zval *table = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema);

	if (Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(table_param) == IS_STRING) {
		table = table_param;
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema) {
		schema = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT TABLE_NAME,COLUMN_NAME,CONSTRAINT_NAME,REFERENCED_TABLE_SCHEMA,REFERENCED_TABLE_NAME,REFERENCED_COLUMN_NAME FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE WHERE REFERENCED_TABLE_NAME IS NOT NULL AND ", 1);


	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "CONSTRAINT_SCHEMA = '", schema, "' AND TABLE_NAME = '", table, "'");
		zephir_concat_self(&sql, _0 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "TABLE_NAME = '", table, "'");
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

	zval *table_param = NULL, *schema = NULL, *sql, *_0;
	zval *table = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema);

	if (Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(table_param) == IS_STRING) {
		table = table_param;
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema) {
		schema = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT TABLES.TABLE_TYPE AS table_type,TABLES.AUTO_INCREMENT AS auto_increment,TABLES.ENGINE AS engine,TABLES.TABLE_COLLATION AS table_collation FROM INFORMATION_SCHEMA.TABLES WHERE ", 1);


	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "TABLES.TABLE_SCHEMA = '", schema, "' AND TABLES.TABLE_NAME = '", table, "'");
		zephir_concat_self(&sql, _0 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "TABLES.TABLE_NAME = '", table, "'");
		zephir_concat_self(&sql, _1 TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

