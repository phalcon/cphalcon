
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "ext/spl/spl_exceptions.h"
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

	zend_declare_property_string(phalcon_db_dialect_postgresql_ce, SL("_escapeChar"), "\"", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_dialect_postgresql_ce TSRMLS_CC, 1, phalcon_db_dialectinterface_ce);
	return SUCCESS;

}

/**
 * Gets the column name in PostgreSQL
 *
 * @param Phalcon\Db\ColumnInterface column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getColumnDefinition) {

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *column, *size = NULL, *columnType = NULL, *columnSql, *typeValues = NULL, *_0 = NULL, *_1 = NULL, *value = NULL, *valueSql, **_4, _5 = zval_used_for_init, _7, *_8 = NULL, *_10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	if (!(zephir_instance_of_ev(column, phalcon_db_columninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'column' must be an instance of 'Phalcon\\Db\\ColumnInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(column) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Column definition must be an object compatible with Phalcon\\Db\\ColumnInterface", "phalcon/db/dialect/postgresql.zep", 50);
		return;
	}
	ZEPHIR_CALL_METHOD(&size, column, "getsize", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnType, column, "gettype", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(columnSql);
	ZVAL_STRING(columnSql, "", 1);
	if (Z_TYPE_P(columnType) == IS_STRING) {
		zephir_concat_self(&columnSql, columnType TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&columnType, column, "gettypereference", NULL);
		zephir_check_call_status();
	}
	do {
		if (ZEPHIR_IS_LONG(columnType, 0)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("INT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 1)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DATE") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 2)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHARACTER VARYING") TSRMLS_CC);
			}
			ZEPHIR_INIT_VAR(_0);
			ZEPHIR_CONCAT_SVS(_0, "(", size, ")");
			zephir_concat_self(&columnSql, _0 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 3)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("NUMERIC") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_1, column, "getscale", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_0);
			ZEPHIR_CONCAT_SVSVS(_0, "(", size, ",", _1, ")");
			zephir_concat_self(&columnSql, _0 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 4)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TIMESTAMP") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 5)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHARACTER") TSRMLS_CC);
			}
			ZEPHIR_INIT_LNVAR(_0);
			ZEPHIR_CONCAT_SVS(_0, "(", size, ")");
			zephir_concat_self(&columnSql, _0 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 6)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TEXT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 7)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("FLOAT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 8)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("SMALLINT(1)") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_EMPTY(columnSql)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Unrecognized PostgreSQL data type", "phalcon/db/dialect/postgresql.zep", 112);
			return;
		}
		ZEPHIR_CALL_METHOD(&typeValues, column, "gettypevalues", NULL);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(typeValues))) {
			if (Z_TYPE_P(typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(valueSql);
				ZVAL_STRING(valueSql, "", 1);
				zephir_is_iterable(typeValues, &_3, &_2, 0, 0, "phalcon/db/dialect/postgresql.zep", 123);
				for (
				  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
				  ; zephir_hash_move_forward_ex(_3, &_2)
				) {
					ZEPHIR_GET_HVALUE(value, _4);
					ZEPHIR_SINIT_NVAR(_5);
					ZVAL_STRING(&_5, "\"", 0);
					ZEPHIR_CALL_FUNCTION(&_1, "addcslashes", &_6, value, &_5);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_0);
					ZEPHIR_CONCAT_SVS(_0, "\"", _1, "\", ");
					zephir_concat_self(&valueSql, _0 TSRMLS_CC);
				}
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, 0);
				ZEPHIR_SINIT_VAR(_7);
				ZVAL_LONG(&_7, -2);
				ZEPHIR_CALL_FUNCTION(&_8, "substr", &_9, valueSql, &_5, &_7);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_10);
				ZEPHIR_CONCAT_SVS(_10, "(", _8, ")");
				zephir_concat_self(&columnSql, _10 TSRMLS_CC);
			} else {
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_STRING(&_5, "\"", 0);
				ZEPHIR_CALL_FUNCTION(&_8, "addcslashes", &_6, typeValues, &_5);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_10);
				ZEPHIR_CONCAT_SVS(_10, "(\"", _8, "\")");
				zephir_concat_self(&columnSql, _10 TSRMLS_CC);
			}
		}
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

	zval *tableName, *schemaName, *column;

	zephir_fetch_params(0, 3, 0, &tableName, &schemaName, &column);



	if (!(zephir_instance_of_ev(column, phalcon_db_columninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'column' must be an instance of 'Phalcon\\Db\\ColumnInterface'", "", 0);
		return;
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/postgresql.zep", 143);
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

	zval *tableName, *schemaName, *column;

	zephir_fetch_params(0, 3, 0, &tableName, &schemaName, &column);



	if (!(zephir_instance_of_ev(column, phalcon_db_columninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'column' must be an instance of 'Phalcon\\Db\\ColumnInterface'", "", 0);
		return;
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/postgresql.zep", 156);
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

	zval *tableName, *schemaName, *columnName;

	zephir_fetch_params(0, 3, 0, &tableName, &schemaName, &columnName);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/postgresql.zep", 169);
	return;

}

/**
 * Generates SQL to add an index to a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	Phalcon\Db\IndexInterface index
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addIndex) {

	zval *tableName, *schemaName, *index;

	zephir_fetch_params(0, 3, 0, &tableName, &schemaName, &index);



	if (!(zephir_instance_of_ev(index, phalcon_db_indexinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'index' must be an instance of 'Phalcon\\Db\\IndexInterface'", "", 0);
		return;
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/postgresql.zep", 182);
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

	zval *tableName, *schemaName, *indexName;

	zephir_fetch_params(0, 3, 0, &tableName, &schemaName, &indexName);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/postgresql.zep", 195);
	return;

}

/**
 * Generates SQL to add the primary key to a table
 *
 * @param	string tableName
 * @param	string schemaName
 * @param	Phalcon\Db\IndexInterface index
 * @return	string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addPrimaryKey) {

	zval *tableName, *schemaName, *index;

	zephir_fetch_params(0, 3, 0, &tableName, &schemaName, &index);



	if (!(zephir_instance_of_ev(index, phalcon_db_indexinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'index' must be an instance of 'Phalcon\\Db\\IndexInterface'", "", 0);
		return;
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/postgresql.zep", 208);
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

	zval *tableName, *schemaName;

	zephir_fetch_params(0, 2, 0, &tableName, &schemaName);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/postgresql.zep", 220);
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

	zval *tableName, *schemaName, *reference;

	zephir_fetch_params(0, 3, 0, &tableName, &schemaName, &reference);



	if (!(zephir_instance_of_ev(reference, phalcon_db_referenceinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'reference' must be an instance of 'Phalcon\\Db\\ReferenceInterface'", "", 0);
		return;
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/postgresql.zep", 233);
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

	zval *tableName, *schemaName, *referenceName;

	zephir_fetch_params(0, 3, 0, &tableName, &schemaName, &referenceName);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/postgresql.zep", 246);
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

	zval *definition = NULL;
	zval *tableName, *schemaName, *definition_param = NULL;

	zephir_fetch_params(0, 3, 0, &tableName, &schemaName, &definition_param);

	definition = definition_param;



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/postgresql.zep", 270);
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

	zval *viewName, *definition, *schemaName, *viewSql, *view = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &viewName, &definition, &schemaName);



	ZEPHIR_OBS_VAR(viewSql);
	if (!(zephir_array_isset_string_fetch(&viewSql, definition, SS("sql"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array", "phalcon/db/dialect/postgresql.zep", 311);
		return;
	}
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
		ZEPHIR_CONCAT_SVSVS(sql, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = '", schemaName, "' AND table_name='", tableName, "'");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = 'public' AND table_name='", tableName, "'");
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
		ZEPHIR_CONCAT_SVSVS(sql, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='", viewName, "' AND schemaname='", schemaName, "'");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='", viewName, "'");
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
		ZEPHIR_CONCAT_SVSVS(sql, "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, c.column_default FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='", schema, "' AND c.table_name='", table, "' ORDER BY c.ordinal_position");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, c.column_default FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='public' AND c.table_name='", table, "' ORDER BY c.ordinal_position");
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
		ZEPHIR_CONCAT_SVS(sql, "SELECT table_name FROM information_schema.tables WHERE table_schema = '", schemaName, "' ORDER BY table_name");
	} else {
		ZVAL_STRING(sql, "SELECT table_name FROM information_schema.tables WHERE table_schema = 'public' ORDER BY table_name", 1);
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
		ZEPHIR_CONCAT_SVS(sql, "SELECT viewname AS view_name FROM pg_views WHERE schemaname = '", schemaName, "' ORDER BY view_name");
	} else {
		ZVAL_STRING(sql, "SELECT viewname AS view_name FROM pg_views WHERE schemaname = 'public' ORDER BY view_name", 1);
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


	ZEPHIR_CONCAT_SVS(return_value, "SELECT 0 as c0, t.relname as table_name, i.relname as key_name, 3 as c3, a.attname as column_name FROM pg_class t, pg_class i, pg_index ix, pg_attribute a WHERE t.oid = ix.indrelid AND i.oid = ix.indexrelid AND a.attrelid = t.oid AND a.attnum = ANY(ix.indkey) AND t.relkind = 'r' AND t.relname = '", table, "' ORDER BY t.relname, i.relname;");
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
	ZVAL_STRING(sql, "SELECT tc.table_name as TABLE_NAME, kcu.column_name as COLUMN_NAME, tc.constraint_name as CONSTRAINT_NAME, tc.table_catalog as REFERENCED_TABLE_SCHEMA, ccu.table_name AS REFERENCED_TABLE_NAME, ccu.column_name AS REFERENCED_COLUMN_NAME FROM information_schema.table_constraints AS tc JOIN information_schema.key_column_usage AS kcu ON tc.constraint_name = kcu.constraint_name JOIN information_schema.constraint_column_usage AS ccu ON ccu.constraint_name = tc.constraint_name WHERE constraint_type = 'FOREIGN KEY' AND ", 1);
	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "tc.table_schema = '", schema, "' AND tc.table_name='", table, "'");
		zephir_concat_self(&sql, _0 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "tc.table_name='", table, "'");
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

