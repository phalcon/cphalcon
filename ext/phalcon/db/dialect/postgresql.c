
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
 |          Rack Lin <racklin@gmail.com>                                  |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Db\Dialect\Postgresql
 *
 * Generates database specific SQL for the PostgreSQL RBDM
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Postgresql) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Postgresql, phalcon, db_dialect_postgresql, phalcon_db_dialect_ce, phalcon_db_dialect_postgresql_method_entry, 0);

	zend_declare_property_string(phalcon_db_dialect_postgresql_ce, SL("_escapeChar"), "\'", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Gets the column name in PostgreSQL
 *
 * @param Phalcon\Db\ColumnInterface column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getColumnDefinition) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1, *_4;
	zval *column, *size = NULL, *columnType = NULL, *columnSql = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	if (Z_TYPE_P(column) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0);
		_1 = zend_fetch_class(SL("Phalcon\\Db\\Dialect\\Phalcon\\Db\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_0, _1);
		if (zephir_has_constructor(_0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_2);
			ZVAL_STRING(_2, "Column definition must be an object compatible with Phalcon\Db\ColumnInterface", 0);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_0, "phalcon/db/dialect/postgresql.zep", 43 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&size, column, "getsize",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnType, column, "gettype",  NULL);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(columnType, 0)) {
			ZEPHIR_INIT_VAR(columnSql);
			ZVAL_STRING(columnSql, "INT", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 1)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZVAL_STRING(columnSql, "DATE", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 2)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZEPHIR_CONCAT_SVS(columnSql, "CHARACTER VARYING(", size, ")");
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 3)) {
			ZEPHIR_CALL_METHOD(&_3, column, "getscale",  NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(columnSql);
			ZEPHIR_CONCAT_SVSVS(columnSql, "NUMERIC(", size, ",", _3, ")");
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 4)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZVAL_STRING(columnSql, "TIMESTAMP", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 5)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZEPHIR_CONCAT_SVS(columnSql, "CHARACTER(", size, ")");
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 6)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZVAL_STRING(columnSql, "TEXT", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 7)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZVAL_STRING(columnSql, "FLOAT", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 8)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZVAL_STRING(columnSql, "SMALLINT(1)", 1);
			break;
		}
		ZEPHIR_INIT_LNVAR(_0);
		_4 = zend_fetch_class(SL("Phalcon\\Db\\Dialect\\Phalcon\\Db\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_0, _4);
		if (zephir_has_constructor(_0 TSRMLS_CC)) {
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "Unrecognized PostgreSQL data type", 0);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_0, "phalcon/db/dialect/postgresql.zep", 78 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
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
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addColumn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *tableName, *schemaName, *column, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName, &schemaName, &column);



	ZEPHIR_INIT_VAR(_0);
	_1 = zend_fetch_class(SL("Phalcon\\Db\\Dialect\\Phalcon\\Db\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_0, _1);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "Not implemented yet", 0);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_0, "phalcon/db/dialect/postgresql.zep", 110 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Generates SQL to modify a column in a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	Phalcon\Db\ColumnInterface column
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, modifyColumn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *tableName, *schemaName, *column, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName, &schemaName, &column);



	ZEPHIR_INIT_VAR(_0);
	_1 = zend_fetch_class(SL("Phalcon\\Db\\Dialect\\Phalcon\\Db\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_0, _1);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "Not implemented yet", 0);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_0, "phalcon/db/dialect/postgresql.zep", 139 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Generates SQL to delete a column from a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	string columnName
 * @return 	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropColumn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *tableName, *schemaName, *columnName, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName, &schemaName, &columnName);



	ZEPHIR_INIT_VAR(_0);
	_1 = zend_fetch_class(SL("Phalcon\\Db\\Dialect\\Phalcon\\Db\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_0, _1);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "Not implemented yet", 0);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_0, "phalcon/db/dialect/postgresql.zep", 159 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Generates SQL to add an index to a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	Phalcon\Db\Index index
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addIndex) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *tableName, *schemaName, *index, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName, &schemaName, &index);



	ZEPHIR_INIT_VAR(_0);
	_1 = zend_fetch_class(SL("Phalcon\\Db\\Dialect\\Phalcon\\Db\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_0, _1);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "Not implemented yet", 0);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_0, "phalcon/db/dialect/postgresql.zep", 185 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Generates SQL to delete an index from a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	string indexName
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropIndex) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *tableName, *schemaName, *indexName, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName, &schemaName, &indexName);



	ZEPHIR_INIT_VAR(_0);
	_1 = zend_fetch_class(SL("Phalcon\\Db\\Dialect\\Phalcon\\Db\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_0, _1);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "Not implemented yet", 0);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_0, "phalcon/db/dialect/postgresql.zep", 205 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Generates SQL to add the primary key to a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	Phalcon\Db\Index index
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addPrimaryKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *tableName, *schemaName, *index, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName, &schemaName, &index);



	ZEPHIR_INIT_VAR(_0);
	_1 = zend_fetch_class(SL("Phalcon\\Db\\Dialect\\Phalcon\\Db\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_0, _1);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "Not implemented yet", 0);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_0, "phalcon/db/dialect/postgresql.zep", 230 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Generates SQL to delete primary key from a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *tableName, *schemaName, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName, &schemaName);



	ZEPHIR_INIT_VAR(_0);
	_1 = zend_fetch_class(SL("Phalcon\\Db\\Dialect\\Phalcon\\Db\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_0, _1);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "Not implemented yet", 0);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_0, "phalcon/db/dialect/postgresql.zep", 248 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Generates SQL to add an index to a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	Phalcon\Db\ReferenceInterface reference
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addForeignKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *tableName, *schemaName, *reference, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName, &schemaName, &reference);



	ZEPHIR_INIT_VAR(_0);
	_1 = zend_fetch_class(SL("Phalcon\\Db\\Dialect\\Phalcon\\Db\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_0, _1);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "Not implemented yet", 0);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_0, "phalcon/db/dialect/postgresql.zep", 277 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Generates SQL to delete a foreign key from a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	string referenceName
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropForeignKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *tableName, *schemaName, *referenceName, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName, &schemaName, &referenceName);



	ZEPHIR_INIT_VAR(_0);
	_1 = zend_fetch_class(SL("Phalcon\\Db\\Dialect\\Phalcon\\Db\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_0, _1);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "Not implemented yet", 0);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_0, "phalcon/db/dialect/postgresql.zep", 297 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Generates SQL to add the table creation options
 *
 * @param	array definition
 * @return	array
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, _getTableOptions) {

	zval *definition;

	zephir_fetch_params(0, 1, 0, &definition);



	array_init(return_value);
	return;

}

/**
 * Generates SQL to create a table in PostgreSQL
 *
 * @param 	string tableName
 * @param	string schemaName
 * @param	array definition
 * @return 	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createTable) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *tableName, *schemaName, *definition, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName, &schemaName, &definition);



	ZEPHIR_INIT_VAR(_0);
	_1 = zend_fetch_class(SL("Phalcon\\Db\\Dialect\\Phalcon\\Db\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(_0, _1);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "Not implemented yet", 0);
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(_0, "phalcon/db/dialect/postgresql.zep", 382 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Generates SQL to drop a table
 *
 * @param  string tableName
 * @param  string schemaName
 * @param  boolean ifExists
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropTable) {

	zval *tableName, *schemaName, *ifExists = NULL, *table = NULL, *sql;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &tableName, &schemaName, &ifExists);

	if (!ifExists) {
		ifExists = ZEPHIR_GLOBAL(global_true);
	}


	if (zephir_is_true(schemaName)) {
		ZEPHIR_INIT_VAR(table);
		ZEPHIR_CONCAT_VSV(table, schemaName, ".", tableName);
	} else {
		ZEPHIR_CPY_WRT(table, tableName);
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createView) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *viewName, *definition, *schemaName, *viewSql, *view = NULL, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &viewName, &definition, &schemaName);



	if (!zephir_array_isset_string(definition, SS("sql"))) {
		ZEPHIR_INIT_VAR(_0);
		_1 = zend_fetch_class(SL("Phalcon\\Db\\Dialect\\Phalcon\\Db\\Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
		object_init_ex(_0, _1);
		if (zephir_has_constructor(_0 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(_2);
			ZVAL_STRING(_2, "The index \"sql\" is required in the definition array", 0);
			ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _2);
			zephir_check_temp_parameter(_2);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(_0, "phalcon/db/dialect/postgresql.zep", 423 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_fetch_string(&viewSql, definition, SL("sql"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if (zephir_is_true(schemaName)) {
		ZEPHIR_INIT_VAR(view);
		ZEPHIR_CONCAT_VSV(view, viewName, ".", schemaName);
	} else {
		ZEPHIR_CPY_WRT(view, viewName);
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropView) {

	zval *viewName, *schemaName, *ifExists = NULL, *view = NULL, *sql;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &viewName, &schemaName, &ifExists);

	if (!ifExists) {
		ifExists = ZEPHIR_GLOBAL(global_true);
	}


	if (zephir_is_true(schemaName)) {
		ZEPHIR_INIT_VAR(view);
		ZEPHIR_CONCAT_VSV(view, viewName, ".", schemaName);
	} else {
		ZEPHIR_CPY_WRT(view, viewName);
	}
	ZEPHIR_INIT_VAR(sql);
	if (zephir_is_true(ifExists)) {
		ZEPHIR_CONCAT_SV(sql, "DROP VIEW IF EXISTS ", view);
	} else {
		ZEPHIR_CONCAT_SV(sql, "DROP VIEW ", view);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * <code>echo dialect->tableExists("posts", "blog")</code>
 * <code>echo dialect->tableExists("posts")</code>
 *
 * @param string tableName
 * @param string schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableExists) {

	zval *tableName, *schemaName = NULL, *sql;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tableName, &schemaName);

	if (!schemaName) {
		schemaName = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(sql);
	if (zephir_is_true(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(sql, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = \"", schemaName, "\" AND table_name=\"", tableName, "\"");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = \"public\" AND table_name=\"", tableName, "\"");
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 * @param string viewName
 * @param string schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, viewExists) {

	zval *viewName, *schemaName = NULL, *sql;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewName, &schemaName);

	if (!schemaName) {
		schemaName = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(sql);
	if (zephir_is_true(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(sql, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname=\"", viewName, "\" AND schemaname=\"", schemaName, "\"");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname=\"", viewName, "\"");
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates a SQL describing a table
 *
 * <code>print_r(dialect->describeColumns("posts") ?></code>
 *
 * @param string table
 * @param string schema
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeColumns) {

	zval *table, *schema = NULL, *sql;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &schema);

	if (!schema) {
		schema = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(sql);
	if (zephir_is_true(schema)) {
		ZEPHIR_CONCAT_SVSVS(sql, "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN \"PRI\" ELSE \"\" END AS Key, CASE WHEN c.data_type LIKE \"%int%\" AND c.column_default LIKE \"%nextval%\" THEN \"auto_increment\" ELSE \"\" END AS Extra, c.ordinal_position AS Position FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name = tc.table_name and kcu.table_schema = tc.table_schema) WHERE tc.constraint_type = \"PRIMARY KEY\") pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name = pkc.table_name) WHERE c.table_schema = \"", schema, "\" AND c.table_name=\"", table, "\" ORDER BY c.ordinal_position");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN \"PRI\" ELSE \"\" END AS Key, CASE WHEN c.data_type LIKE \"%int%\" AND c.column_default LIKE \"%nextval%\" THEN \"auto_increment\" ELSE \"\" END AS Extra, c.ordinal_position AS Position FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name = tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type = \"PRIMARY KEY\") pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name = pkc.table_name) WHERE c.table_schema = \"public\" AND c.table_name=\"", table, "\" ORDER BY c.ordinal_position");
	}
	RETURN_CCTOR(sql);

}

/**
 * List all tables on database
 *
 *<code>
 *	print_r(dialect->listTables("blog")) ?>
 *</code>
 *
 * @param       string schemaName
 * @return      array
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listTables) {

	zval *schemaName = NULL, *sql;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName);

	if (!schemaName) {
		schemaName = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(sql);
	if (zephir_is_true(schemaName)) {
		ZEPHIR_CONCAT_SVS(sql, "SELECT table_name FROM information_schema.tables WHERE table_schema = \"", schemaName, "\" ORDER BY table_name");
	} else {
		ZVAL_STRING(sql, "SELECT table_name FROM information_schema.tables WHERE table_schema = \"public\" ORDER BY table_name", 1);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates the SQL to list all views of a schema or user
 *
 * @param string schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listViews) {

	zval *schemaName = NULL, *sql;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName);

	if (!schemaName) {
		schemaName = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(sql);
	if (zephir_is_true(schemaName)) {
		ZEPHIR_CONCAT_SVS(sql, "SELECT viewname AS view_name FROM pg_views WHERE schemaname = \"", schemaName, "\" ORDER BY view_name");
	} else {
		ZVAL_STRING(sql, "SELECT viewname AS view_name FROM pg_views WHERE schemaname = \"public\" ORDER BY view_name", 1);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to query indexes on a table
 *
 * @param	string table
 * @param	string schema
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeIndexes) {

	zval *table, *schema = NULL;

	zephir_fetch_params(0, 1, 1, &table, &schema);

	if (!schema) {
		schema = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CONCAT_SVS(return_value, "SELECT 0 as c0, t.relname as table_name, i.relname as key_name, 3 as c3, a.attname as column_name FROM pg_class t, pg_class i, pg_index ix, pg_attribute a WHERE t.oid = ix.indrelid AND i.oid = ix.indexrelid AND a.attrelid = t.oid AND a.attnum = ANY(ix.indkey) AND t.relkind = \"r\" AND t.relname = \"", table, "\" ORDER BY t.relname, i.relname;");
	return;

}

/**
 * Generates SQL to query foreign keys on a table
 *
 * @param	string table
 * @param	string schema
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeReferences) {

	zval *table, *schema = NULL, *sql, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &schema);

	if (!schema) {
		schema = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT tc.table_name as TABLE_NAME, kcu.column_name as COLUMN_NAME, tc.constraint_name as CONSTRAINT_NAME, tc.table_catalog as REFERENCED_TABLE_SCHEMA, ccu.table_name AS REFERENCED_TABLE_NAME, ccu.column_name AS REFERENCED_COLUMN_NAME FROM information_schema.table_constraints AS tc JOIN information_schema.key_column_usage AS kcu ON tc.constraint_name = kcu.constraint_name JOIN information_schema.constraint_column_usage AS ccu ON ccu.constraint_name = tc.constraint_name WHERE constraint_type = \"FOREIGN KEY\" AND ", 1);
	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "tc.table_schema = \"", schema, "\" AND tc.table_name=\"", table, "\"");
		zephir_concat_self(&sql, _0 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "tc.table_name=\"", table, "\"");
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableOptions) {

	zval *table, *schema = NULL;

	zephir_fetch_params(0, 1, 1, &table, &schema);

	if (!schema) {
		schema = ZEPHIR_GLOBAL(global_null);
	}


	RETURN_STRING("", 1);

}

