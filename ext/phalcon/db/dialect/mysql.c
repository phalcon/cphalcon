
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
#include "kernel/string.h"


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

	zval *column, *columnSql = NULL, *size, *scale, *_0, *_1 = NULL, *_2 = NULL, *_3, *_4, *_5;

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

	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *afterPosition, *sql, *_0, *_1, *_2, *_3, *_4, *_5;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &column);

		if (Z_TYPE_P(tableName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		}

		tableName = tableName_param;
		if (Z_TYPE_P(schemaName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		}

		schemaName = schemaName_param;


	if ((Z_TYPE_P(column) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column definition must be an object compatible with Phalcon\\Db\\ColumnInterface");
		return;
	}
	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(sql, "ALTER TABLE `", schemaName, "`.`", tableName, "` ADD ");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "ALTER TABLE `", tableName, "` ADD ");
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, column, "getname");
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method_p1(_1, this_ptr, "getcolumndefinition", column);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVSV(_2, "`", _0, "` ", _1);
	zephir_concat_self(&sql, _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_method(_3, column, "isnotnull");
	if (zephir_is_true(_3)) {
		zephir_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_call_method(_4, column, "isfirst");
	if (zephir_is_true(_4)) {
		zephir_concat_self_str(&sql, SL(" FIRST") TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(afterPosition);
		zephir_call_method(afterPosition, column, "getafterposition");
		if (zephir_is_true(afterPosition)) {
			ZEPHIR_INIT_VAR(_5);
			ZEPHIR_CONCAT_SV(_5, " AFTER ", afterPosition);
			zephir_concat_self(&sql, _5 TSRMLS_CC);
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *sql, *_0, *_1, *_2, *_3;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &column);

		if (Z_TYPE_P(tableName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		}

		tableName = tableName_param;
		if (Z_TYPE_P(schemaName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		}

		schemaName = schemaName_param;


	if ((Z_TYPE_P(column) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column definition must be an object compatible with Phalcon\\Db\\ColumnInterface");
		return;
	}
	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(sql, "ALTER TABLE `", schemaName, "`.`", tableName, "` MODIFY ");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "ALTER TABLE `", tableName, "` MODIFY ");
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, column, "getname");
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method_p1(_1, this_ptr, "getcolumndefinition", column);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVSV(_2, "`", _0, "` ", _1);
	zephir_concat_self(&sql, _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_call_method(_3, column, "isnotnull");
	if (zephir_is_true(_3)) {
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL, *sql, *_0;
	zval *tableName = NULL, *schemaName = NULL, *columnName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &columnName_param);

		if (Z_TYPE_P(tableName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		}

		tableName = tableName_param;
		if (Z_TYPE_P(schemaName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		}

		schemaName = schemaName_param;
		zephir_get_strval(columnName, columnName_param);


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(sql, "ALTER TABLE `", schemaName, "`.`", tableName, "` DROP COLUMN ");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "ALTER TABLE `", tableName, "` DROP COLUMN ");
	}
	ZEPHIR_INIT_VAR(_0);
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *sql, *_0, *_1, *_2, *_3;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

		if (Z_TYPE_P(tableName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		}

		tableName = tableName_param;
		if (Z_TYPE_P(schemaName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		}

		schemaName = schemaName_param;


	if ((Z_TYPE_P(index) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Index parameter must be an object compatible with Phalcon\\Db\\IndexInterface");
		return;
	}
	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(sql, "ALTER TABLE `", schemaName, "`.`", tableName, "` ADD INDEX ");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "ALTER TABLE `", tableName, "` ADD INDEX ");
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, index, "getname");
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_method(_2, index, "getcolumns");
	zephir_call_method_p1(_1, this_ptr, "getcolumnlist", _2);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVSVS(_3, "`", _0, "` (", _1, ")");
	zephir_concat_self(&sql, _3 TSRMLS_CC);
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName_param = NULL, *sql, *_0;
	zval *tableName = NULL, *schemaName = NULL, *indexName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &indexName_param);

		if (Z_TYPE_P(tableName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		}

		tableName = tableName_param;
		if (Z_TYPE_P(schemaName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		}

		schemaName = schemaName_param;
		if (Z_TYPE_P(indexName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'indexName' must be a string") TSRMLS_CC);
		}

		indexName = indexName_param;


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(sql, "ALTER TABLE `", schemaName, "`.`", tableName, "` DROP INDEX ");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "ALTER TABLE `", tableName, "` DROP INDEX ");
	}
	ZEPHIR_INIT_VAR(_0);
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *sql, *_0, *_1, *_2;
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
		ZEPHIR_CONCAT_SVSVS(sql, "ALTER TABLE `", schemaName, "`.`", tableName, "` ADD PRIMARY KEY ");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "ALTER TABLE `", tableName, "` ADD PRIMARY KEY ");
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, index, "getcolumns");
	zephir_call_method_p1(_0, this_ptr, "getcolumnlist", _1);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVS(_2, "(", _0, ")");
	zephir_concat_self(&sql, _2 TSRMLS_CC);
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *sql;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);

		if (Z_TYPE_P(tableName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		}

		tableName = tableName_param;
		if (Z_TYPE_P(schemaName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		}

		schemaName = schemaName_param;


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(sql, "ALTER TABLE `", schemaName, "`.`", tableName, "` DROP PRIMARY KEY");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "ALTER TABLE `", tableName, "` DROP PRIMARY KEY");
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, *sql, *referencedSchema, *_0, *_1, *_2, *_3, *_4 = NULL, *_5, *_6, *_7;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &reference);

		if (Z_TYPE_P(tableName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		}

		tableName = tableName_param;
		if (Z_TYPE_P(schemaName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		}

		schemaName = schemaName_param;


	if ((Z_TYPE_P(reference) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Index parameter must be an object compatible with Phalcon\\Db\\ReferenceInterface");
		return;
	}
	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(sql, "ALTER TABLE `", schemaName, "`.`", tableName, "` ADD FOREIGN KEY ");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "ALTER TABLE `", tableName, "` ADD FOREIGN KEY ");
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, reference, "getname");
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_method(_2, reference, "getcolumns");
	zephir_call_method_p1(_1, this_ptr, "getcolumnlist", _2);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVSVS(_3, "`", _0, "`(", _1, ") REFERENCES ");
	zephir_concat_self(&sql, _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(referencedSchema);
	zephir_call_method(referencedSchema, reference, "getreferencedschema");
	if (zephir_is_true(referencedSchema)) {
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SVS(_4, "`", referencedSchema, "`.");
		zephir_concat_self(&sql, _4 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_call_method(_5, reference, "getreferencedtable");
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_INIT_VAR(_7);
	zephir_call_method(_7, reference, "getreferencedcolumns");
	zephir_call_method_p1(_6, this_ptr, "getcolumnlist", _7);
	ZEPHIR_INIT_LNVAR(_4);
	ZEPHIR_CONCAT_SVSVS(_4, "`", _5, "`(", _6, ")");
	zephir_concat_self(&sql, _4 TSRMLS_CC);
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName, *sql, *_0;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &referenceName);

		if (Z_TYPE_P(tableName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		}

		tableName = tableName_param;
		if (Z_TYPE_P(schemaName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		}

		schemaName = schemaName_param;


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(sql, "ALTER TABLE `", schemaName, "`.`", tableName, "` DROP FOREIGN KEY ");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "ALTER TABLE `", tableName, "` DROP FOREIGN KEY ");
	}
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "`", referenceName, "`");
	zephir_concat_self(&sql, _0 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to add the table creation options
 *
 * @param	array definition
 * @return	array
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, _getTableOptions) {

	zval *definition, *options, *engine, *autoIncrement, *tableCollation, *collationParts, *tableOptions, *_0 = NULL, _1, *_2, *_3;

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
				zephir_array_fetch_long(&_2, collationParts, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_0);
				ZEPHIR_CONCAT_SV(_0, "DEFAULT CHARSET=", _2);
				zephir_array_append(&tableOptions, _0, PH_SEPARATE);
				ZEPHIR_INIT_VAR(_3);
				ZEPHIR_CONCAT_SV(_3, "COLLATE=", tableCollation);
				zephir_array_append(&tableOptions, _3, PH_SEPARATE);
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

	zend_function *_4 = NULL, *_6 = NULL, *_8 = NULL, *_10 = NULL, *_12 = NULL, *_16 = NULL, *_17 = NULL, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_24 = NULL, *_25 = NULL, *_26 = NULL, *_27 = NULL, *_28 = NULL;
	HashTable *_1, *_14, *_22;
	HashPosition _0, _13, _21;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition, *temporary = NULL, *options, *table, *createLines, *columns, *column = NULL, *indexes, *index = NULL, *reference = NULL, *references, *indexName = NULL, *indexSql = NULL, *sql, *columnLine = NULL, **_2, *_3 = NULL, *_5 = NULL, *_7 = NULL, *_9 = NULL, *_11 = NULL, **_15, **_23, *_29 = NULL, *_30;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition);

		if (Z_TYPE_P(tableName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		}

		tableName = tableName_param;
		if (Z_TYPE_P(schemaName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		}

		schemaName = schemaName_param;


	if (!(zephir_array_isset_string_fetch(&columns, definition, SS("columns"), 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array");
		return;
	}
	ZEPHIR_INIT_VAR(table);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(table, "`", schemaName, "`.`", tableName, "`");
	} else {
		ZEPHIR_CONCAT_SVS(table, "`", tableName, "`");
	}
	ZEPHIR_INIT_VAR(temporary);
	ZVAL_BOOL(temporary, 0);
	if (zephir_array_isset_string_fetch(&options, definition, SS("options"), 1 TSRMLS_CC)) {
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
	zephir_is_iterable(columns, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(column, _2);
		ZEPHIR_INIT_NVAR(_3);
		zephir_call_method_cache(_3, column, "getname", &_4);
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_method_p1_cache(_5, this_ptr, "getcolumndefinition", &_6, column);
		ZEPHIR_INIT_NVAR(columnLine);
		ZEPHIR_CONCAT_SVSV(columnLine, "`", _3, "` ", _5);
		ZEPHIR_INIT_NVAR(_7);
		zephir_call_method_cache(_7, column, "isnotnull", &_8);
		if (zephir_is_true(_7)) {
			zephir_concat_self_str(&columnLine, SL(" NOT NULL") TSRMLS_CC);
		}
		ZEPHIR_INIT_NVAR(_9);
		zephir_call_method_cache(_9, column, "isautoincrement", &_10);
		if (zephir_is_true(_9)) {
			zephir_concat_self_str(&columnLine, SL(" AUTO_INCREMENT") TSRMLS_CC);
		}
		ZEPHIR_INIT_NVAR(_11);
		zephir_call_method_cache(_11, column, "isprimary", &_12);
		if (zephir_is_true(_11)) {
			zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY") TSRMLS_CC);
		}
		zephir_array_append(&createLines, columnLine, PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&indexes, definition, SS("indexes"), 1 TSRMLS_CC)) {
		zephir_is_iterable(indexes, &_14, &_13, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_14, (void**) &_15, &_13) == SUCCESS
			; zend_hash_move_forward_ex(_14, &_13)
		) {
			ZEPHIR_GET_HVALUE(index, _15);
			ZEPHIR_INIT_NVAR(indexName);
			zephir_call_method_cache(indexName, index, "getname", &_16);
			ZEPHIR_INIT_NVAR(indexSql);
			if (ZEPHIR_IS_STRING(indexName, "PRIMARY")) {
				ZEPHIR_INIT_NVAR(_3);
				ZEPHIR_INIT_NVAR(_5);
				zephir_call_method_cache(_5, index, "getcolumns", &_17);
				zephir_call_method_p1_cache(_3, this_ptr, "getcolumnlist", &_18, _5);
				ZEPHIR_CONCAT_SVS(indexSql, "PRIMARY KEY (", _3, ")");
			} else {
				ZEPHIR_INIT_NVAR(_7);
				ZEPHIR_INIT_NVAR(_9);
				zephir_call_method_cache(_9, index, "getcolumns", &_19);
				zephir_call_method_p1_cache(_7, this_ptr, "getcolumnlist", &_20, _9);
				ZEPHIR_CONCAT_SVSVS(indexSql, "KEY `", indexName, "` (", _7, ")");
			}
			zephir_array_append(&createLines, indexSql, PH_SEPARATE);
		}
	}
	if (zephir_array_isset_string_fetch(&references, definition, SS("references"), 1 TSRMLS_CC)) {
		zephir_is_iterable(references, &_22, &_21, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_22, (void**) &_23, &_21) == SUCCESS
			; zend_hash_move_forward_ex(_22, &_21)
		) {
			ZEPHIR_GET_HVALUE(reference, _23);
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_method_cache(_3, reference, "getname", &_24);
			ZEPHIR_INIT_NVAR(_5);
			zephir_call_method_p1_cache(_5, this_ptr, "getcolumnlist", &_25, columns);
			ZEPHIR_INIT_NVAR(_7);
			zephir_call_method_cache(_7, reference, "getreferencedtable", &_26);
			ZEPHIR_INIT_NVAR(_9);
			ZEPHIR_INIT_NVAR(_11);
			zephir_call_method_cache(_11, reference, "getreferencedcolumns", &_27);
			zephir_call_method_p1_cache(_9, this_ptr, "getcolumnlist", &_28, _11);
			ZEPHIR_INIT_LNVAR(_29);
			ZEPHIR_CONCAT_SVSVSSVSVS(_29, "CONSTRAINT `", _3, "` FOREIGN KEY (", _5, ")", " REFERENCES `", _7, "`(", _9, ")");
			zephir_array_append(&createLines, _29, PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(_3);
	zephir_fast_join_str(_3, SL(",\n\t"), createLines TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_29);
	ZEPHIR_CONCAT_VS(_29, _3, "\n)");
	zephir_concat_self(&sql, _29 TSRMLS_CC);
	if (zephir_array_isset_string(definition, SS("options"))) {
		ZEPHIR_INIT_NVAR(_5);
		zephir_call_method_p1(_5, this_ptr, "_gettableoptions", definition);
		ZEPHIR_INIT_VAR(_30);
		ZEPHIR_CONCAT_SV(_30, " ", _5);
		zephir_concat_self(&sql, _30 TSRMLS_CC);
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

	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists = NULL, *sql, *table;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &tableName_param, &schemaName_param, &ifExists);

		if (Z_TYPE_P(tableName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		}

		tableName = tableName_param;
		if (Z_TYPE_P(schemaName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		}

		schemaName = schemaName_param;
	if (!ifExists) {
		ZEPHIR_CPY_WRT(ifExists, ZEPHIR_GLOBAL(global_true));
	}


	ZEPHIR_INIT_VAR(table);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(table, "`", schemaName, "`.`", tableName, "`");
	} else {
		ZEPHIR_CONCAT_SVS(table, "`", tableName, "`");
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

	zval *viewName_param = NULL, *definition, *schemaName_param = NULL, *view, *viewSql;
	zval *viewName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &viewName_param, &definition, &schemaName_param);

		if (Z_TYPE_P(viewName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		}

		viewName = viewName_param;
		if (Z_TYPE_P(schemaName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		}

		schemaName = schemaName_param;


	if (zephir_array_isset_string_fetch(&viewSql, definition, SS("sql"), 1 TSRMLS_CC)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array");
		return;
	}
	ZEPHIR_INIT_VAR(view);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(view, "`", schemaName, "`.`", viewName, "`");
	} else {
		ZEPHIR_CONCAT_SVS(view, "`", viewName, "`");
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
	zval *viewName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &viewName_param, &schemaName_param, &ifExists_param);

		if (Z_TYPE_P(viewName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		}

		viewName = viewName_param;
		if (Z_TYPE_P(schemaName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		}

		schemaName = schemaName_param;
	if (!ifExists_param) {
		ifExists = 1;
	} else {
		ifExists = zephir_get_boolval(ifExists_param);
	}


	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(view);
		ZEPHIR_CONCAT_VSV(view, schemaName, ".", viewName);
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

		if (Z_TYPE_P(tableName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		}

		tableName = tableName_param;
	if (!schemaName) {
		ZEPHIR_CPY_WRT(schemaName, ZEPHIR_GLOBAL(global_null));
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

		if (Z_TYPE_P(viewName_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		}

		viewName = viewName_param;
	if (!schemaName) {
		ZEPHIR_CPY_WRT(schemaName, ZEPHIR_GLOBAL(global_null));
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

		if (Z_TYPE_P(table_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		}

		table = table_param;
	if (!schema) {
		ZEPHIR_CPY_WRT(schema, ZEPHIR_GLOBAL(global_null));
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
		zephir_get_strval(schemaName, schemaName_param);
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
		zephir_get_strval(schemaName, schemaName_param);
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

		if (Z_TYPE_P(table_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		}

		table = table_param;
	if (!schema) {
		ZEPHIR_CPY_WRT(schema, ZEPHIR_GLOBAL(global_null));
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

	zval *table_param = NULL, *schema = NULL, *sql, *_0 = NULL;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema);

		if (Z_TYPE_P(table_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		}

		table = table_param;
	if (!schema) {
		ZEPHIR_CPY_WRT(schema, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT TABLE_NAME,COLUMN_NAME,CONSTRAINT_NAME,REFERENCED_TABLE_SCHEMA,REFERENCED_TABLE_NAME,REFERENCED_COLUMN_NAME FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE WHERE REFERENCED_TABLE_NAME IS NOT NULL AND ", 1);


	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "CONSTRAINT_SCHEMA = '", schema, "' AND TABLE_NAME = '", table, "'");
		zephir_concat_self(&sql, _0 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "TABLE_NAME = '", table, "'");
		zephir_concat_self(&sql, _0 TSRMLS_CC);
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

	zval *table_param = NULL, *schema = NULL, *sql, *_0 = NULL;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema);

		if (Z_TYPE_P(table_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		}

		table = table_param;
	if (!schema) {
		ZEPHIR_CPY_WRT(schema, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT TABLES.TABLE_TYPE AS table_type,TABLES.AUTO_INCREMENT AS auto_increment,TABLES.ENGINE AS engine,TABLES.TABLE_COLLATION AS table_collation FROM INFORMATION_SCHEMA.TABLES WHERE ", 1);


	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "TABLES.TABLE_SCHEMA = '", schema, "' AND TABLES.TABLE_NAME = '", table, "'");
		zephir_concat_self(&sql, _0 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "TABLES.TABLE_NAME = '", table, "'");
		zephir_concat_self(&sql, _0 TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

