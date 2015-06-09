
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


/**
 * Phalcon\Db\Dialect\Sqlite
 *
 * Generates database specific SQL for the Sqlite RDBMS
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Sqlite) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Sqlite, phalcon, db_dialect_sqlite, phalcon_db_dialect_ce, phalcon_db_dialect_sqlite_method_entry, 0);

	zend_declare_property_string(phalcon_db_dialect_sqlite_ce, SL("_escapeChar"), "\"", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Gets the column name in SQLite
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, getColumnDefinition) {

	zephir_fcall_cache_entry *_7 = NULL;
	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *column, *columnSql, *type = NULL, *typeValues = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *value = NULL, *valueSql, **_5, _6 = zval_used_for_init, _8 = zval_used_for_init, *_9, *_10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_INIT_VAR(columnSql);
	ZVAL_STRING(columnSql, "", 1);
	ZEPHIR_CALL_METHOD(&type, column, "gettype", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(type) == IS_STRING) {
		zephir_concat_self(&columnSql, type TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&type, column, "gettypereference", NULL, 0);
		zephir_check_call_status();
	}
	do {
		if (ZEPHIR_IS_LONG(type, 0)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("INT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 1)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DATE") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 2)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("VARCHAR") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_0, column, "getsize", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_1);
			ZEPHIR_CONCAT_SVS(_1, "(", _0, ")");
			zephir_concat_self(&columnSql, _1 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 3)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("NUMERIC") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_0, column, "getsize", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_2, column, "getscale", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_1);
			ZEPHIR_CONCAT_SVSVS(_1, "(", _0, ",", _2, ")");
			zephir_concat_self(&columnSql, _1 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 4)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TIMESTAMP") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 5)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHARACTER") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_0, column, "getsize", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_1);
			ZEPHIR_CONCAT_SVS(_1, "(", _0, ")");
			zephir_concat_self(&columnSql, _1 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 6)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TEXT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 7)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("FLOAT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_EMPTY(columnSql)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Unrecognized SQLite data type", "phalcon/db/dialect/sqlite.zep", 112);
			return;
		}
		ZEPHIR_CALL_METHOD(&typeValues, column, "gettypevalues", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(typeValues))) {
			if (Z_TYPE_P(typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(valueSql);
				ZVAL_STRING(valueSql, "", 1);
				zephir_is_iterable(typeValues, &_4, &_3, 0, 0, "phalcon/db/dialect/sqlite.zep", 123);
				for (
				  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
				  ; zephir_hash_move_forward_ex(_4, &_3)
				) {
					ZEPHIR_GET_HVALUE(value, _5);
					ZEPHIR_SINIT_NVAR(_6);
					ZVAL_STRING(&_6, "\"", 0);
					ZEPHIR_CALL_FUNCTION(&_0, "addcslashes", &_7, 109, value, &_6);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_1);
					ZEPHIR_CONCAT_SVS(_1, "\"", _0, "\", ");
					zephir_concat_self(&valueSql, _1 TSRMLS_CC);
				}
				ZEPHIR_SINIT_NVAR(_6);
				ZVAL_LONG(&_6, 0);
				ZEPHIR_SINIT_VAR(_8);
				ZVAL_LONG(&_8, -2);
				ZEPHIR_INIT_VAR(_9);
				zephir_substr(_9, valueSql, 0 , -2 , 0);
				ZEPHIR_INIT_VAR(_10);
				ZEPHIR_CONCAT_SVS(_10, "(", _9, ")");
				zephir_concat_self(&columnSql, _10 TSRMLS_CC);
			} else {
				ZEPHIR_SINIT_NVAR(_8);
				ZVAL_STRING(&_8, "\"", 0);
				ZEPHIR_CALL_FUNCTION(&_2, "addcslashes", &_7, 109, typeValues, &_8);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_10);
				ZEPHIR_CONCAT_SVS(_10, "(\"", _2, "\")");
				zephir_concat_self(&columnSql, _10 TSRMLS_CC);
			}
		}
	} while(0);

	RETURN_CCTOR(columnSql);

}

/**
 * Generates SQL to add a column to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addColumn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *sql = NULL, *defaultValue = NULL, *_1 = NULL, *_2 = NULL, *_3, _4, *_5 = NULL, *_6;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &column);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE \"", schemaName, "\".\"", tableName, "\" ADD COLUMN ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE \"", tableName, "\" ADD COLUMN ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_CALL_METHOD(&_1, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVSV(_3, "\"", _1, "\" ", _2);
	zephir_concat_self(&sql, _3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(defaultValue))) {
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "\"", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "addcslashes", NULL, 109, defaultValue, &_4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CONCAT_SVS(_6, " DEFAULT \"", _5, "\"");
		zephir_concat_self(&sql, _6 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_5, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		zephir_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_5, column, "isautoincrement", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		zephir_concat_self_str(&sql, SL(" PRIMARY KEY AUTOINCREMENT") TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to modify a column in a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, modifyColumn) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *currentColumn = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &tableName_param, &schemaName_param, &column, &currentColumn);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	if (!currentColumn) {
		currentColumn = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Altering a DB column is not supported by SQLite", "phalcon/db/dialect/sqlite.zep", 169);
	return;

}

/**
 * Generates SQL to delete a column from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropColumn) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL;
	zval *tableName = NULL, *schemaName = NULL, *columnName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &columnName_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	if (unlikely(Z_TYPE_P(columnName_param) != IS_STRING && Z_TYPE_P(columnName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'columnName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(columnName_param) == IS_STRING)) {
		zephir_get_strval(columnName, columnName_param);
	} else {
		ZEPHIR_INIT_VAR(columnName);
		ZVAL_EMPTY_STRING(columnName);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Dropping DB column is not supported by SQLite", "phalcon/db/dialect/sqlite.zep", 177);
	return;

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addIndex) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *sql, *indexType = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	ZEPHIR_CALL_METHOD(&indexType, index, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(sql);
	if (!(ZEPHIR_IS_EMPTY(indexType))) {
		ZEPHIR_CONCAT_SVS(sql, "CREATE ", indexType, " INDEX \"");
	} else {
		ZVAL_STRING(sql, "CREATE INDEX \"", 1);
	}
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CALL_METHOD(&_0, index, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VSVSVS(_1, schemaName, "\".\"", _0, "\" ON \"", tableName, "\" (");
		zephir_concat_self(&sql, _1 TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&_0, index, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_VSVS(_1, _0, "\" ON \"", tableName, "\" (");
		zephir_concat_self(&sql, _1 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_2, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcolumnlist", NULL, 100, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VS(_1, _0, ")");
	zephir_concat_self(&sql, _1 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete an index from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropIndex) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName_param = NULL, *sql = NULL;
	zval *tableName = NULL, *schemaName = NULL, *indexName = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &indexName_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	if (unlikely(Z_TYPE_P(indexName_param) != IS_STRING && Z_TYPE_P(indexName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'indexName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(indexName_param) == IS_STRING)) {
		zephir_get_strval(indexName, indexName_param);
	} else {
		ZEPHIR_INIT_VAR(indexName);
		ZVAL_EMPTY_STRING(indexName);
	}


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "DROP INDEX \"", schemaName, "\".\"", indexName, "\"");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "DROP INDEX \"", indexName, "\"");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to add the primary key to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addPrimaryKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *index;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Adding a primary key after table has been created is not supported by SQLite", "phalcon/db/dialect/sqlite.zep", 224);
	return;

}

/**
 * Generates SQL to delete primary key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropPrimaryKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Removing a primary key after table has been created is not supported by SQLite", "phalcon/db/dialect/sqlite.zep", 232);
	return;

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addForeignKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *reference;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &reference);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Adding a foreign key constraint to an existing table is not supported by SQLite", "phalcon/db/dialect/sqlite.zep", 240);
	return;

}

/**
 * Generates SQL to delete a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropForeignKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName_param = NULL;
	zval *tableName = NULL, *schemaName = NULL, *referenceName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &referenceName_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	if (unlikely(Z_TYPE_P(referenceName_param) != IS_STRING && Z_TYPE_P(referenceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(referenceName_param) == IS_STRING)) {
		zephir_get_strval(referenceName, referenceName_param);
	} else {
		ZEPHIR_INIT_VAR(referenceName);
		ZVAL_EMPTY_STRING(referenceName);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Dropping a foreign key constraint is not supported by SQLite", "phalcon/db/dialect/sqlite.zep", 248);
	return;

}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createTable) {

	zval *definition = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	definition = definition_param;



	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/sqlite.zep", 256);
	return;

}

/**
 * Generates SQL to drop a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropTable) {

	zend_bool ifExists;
	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *sql, *table = NULL;
	zval *tableName = NULL, *schemaName = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &tableName_param, &schemaName_param, &ifExists_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
		zephir_get_strval(schemaName, schemaName_param);
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
	if (unlikely(Z_TYPE_P(ifExists_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ifExists' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	ifExists = Z_BVAL_P(ifExists_param);
	}


	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VSV(_0, schemaName, "\".\"", tableName);
		ZEPHIR_CPY_WRT(table, _0);
	} else {
		ZEPHIR_CPY_WRT(table, tableName);
	}
	ZEPHIR_INIT_VAR(sql);
	if (ifExists) {
		ZEPHIR_CONCAT_SVS(sql, "DROP TABLE IF EXISTS \"", table, "\"");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "DROP TABLE \"", table, "\"");
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to create a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createView) {

	zval *definition = NULL;
	zval *viewName_param = NULL, *definition_param = NULL, *schemaName_param = NULL, *view = NULL, *viewSql;
	zval *viewName = NULL, *schemaName = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &viewName_param, &definition_param, &schemaName_param);

	if (unlikely(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(viewName);
		ZVAL_EMPTY_STRING(viewName);
	}
	definition = definition_param;

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
		zephir_get_strval(schemaName, schemaName_param);
	}


	ZEPHIR_OBS_VAR(viewSql);
	if (!(zephir_array_isset_string_fetch(&viewSql, definition, SS("sql"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array", "phalcon/db/dialect/sqlite.zep", 289);
		return;
	}
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VSV(_0, schemaName, "\".\"", viewName);
		ZEPHIR_CPY_WRT(view, _0);
	} else {
		ZEPHIR_CPY_WRT(view, viewName);
	}
	ZEPHIR_CONCAT_SVSV(return_value, "CREATE VIEW \"", view, "\" AS ", viewSql);
	RETURN_MM();

}

/**
 * Generates SQL to drop a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropView) {

	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *sql, *view = NULL;
	zval *viewName = NULL, *schemaName = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &viewName_param, &schemaName_param, &ifExists_param);

	if (unlikely(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(viewName);
		ZVAL_EMPTY_STRING(viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
		zephir_get_strval(schemaName, schemaName_param);
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
	if (unlikely(Z_TYPE_P(ifExists_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ifExists' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	ifExists = Z_BVAL_P(ifExists_param);
	}


	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VSV(_0, schemaName, "\".\"", viewName);
		ZEPHIR_CPY_WRT(view, _0);
	} else {
		ZEPHIR_CPY_WRT(view, viewName);
	}
	ZEPHIR_INIT_VAR(sql);
	if (ifExists) {
		ZEPHIR_CONCAT_SVS(sql, "DROP VIEW IF EXISTS \"", view, "\"");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "DROP VIEW \"", view, "\"");
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * <code>
 *    echo $dialect->tableExists("posts", "blog");
 *    echo $dialect->tableExists("posts");
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, tableExists) {

	zval *tableName_param = NULL, *schemaName_param = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tableName_param, &schemaName_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
		zephir_get_strval(schemaName, schemaName_param);
	}


	ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='table' AND tbl_name='", tableName, "'");
	RETURN_MM();

}

/**
 * Generates SQL checking for the existence of a schema.view
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, viewExists) {

	zval *viewName_param = NULL, *schemaName_param = NULL;
	zval *viewName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewName_param, &schemaName_param);

	if (unlikely(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(viewName);
		ZVAL_EMPTY_STRING(viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
		zephir_get_strval(schemaName, schemaName_param);
	}


	ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='view' AND tbl_name='", viewName, "'");
	RETURN_MM();

}

/**
 * Generates SQL describing a table
 *
 * <code>
 *    print_r($dialect->describeColumns("posts"));
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeColumns) {

	zval *table_param = NULL, *schema_param = NULL;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	} else {
		zephir_get_strval(schema, schema_param);
	}


	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA table_info('", table, "')");
	RETURN_MM();

}

/**
 * List all tables in database
 *
 * <code>
 *     print_r($dialect->listTables("blog"))
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listTables) {

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


	RETURN_MM_STRING("SELECT tbl_name FROM sqlite_master WHERE type = 'table' ORDER BY tbl_name", 1);

}

/**
 * Generates the SQL to list all views of a schema or user
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listViews) {

	zval *schemaName_param = NULL;
	zval *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	}


	RETURN_MM_STRING("SELECT tbl_name FROM sqlite_master WHERE type = 'view' ORDER BY tbl_name", 1);

}

/**
 * Generates SQL to query indexes on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndexes) {

	zval *table_param = NULL, *schema_param = NULL;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	} else {
		zephir_get_strval(schema, schema_param);
	}


	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA index_list('", table, "')");
	RETURN_MM();

}

/**
 * Generates SQL to query indexes detail on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndex) {

	zval *index_param = NULL;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (unlikely(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(index, index_param);
	} else {
		ZEPHIR_INIT_VAR(index);
		ZVAL_EMPTY_STRING(index);
	}


	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA index_info('", index, "')");
	RETURN_MM();

}

/**
 * Generates SQL to query foreign keys on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeReferences) {

	zval *table_param = NULL, *schema_param = NULL;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	} else {
		zephir_get_strval(schema, schema_param);
	}


	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA foreign_key_list('", table, "')");
	RETURN_MM();

}

/**
 * Generates the SQL to describe the table creation options
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, tableOptions) {

	zval *table_param = NULL, *schema_param = NULL;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	} else {
		zephir_get_strval(schema, schema_param);
	}


	RETURN_MM_STRING("", 1);

}

