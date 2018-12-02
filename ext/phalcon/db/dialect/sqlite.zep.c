
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

	HashTable *_13$$41;
	HashPosition _12$$41;
	zephir_fcall_cache_entry *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, *columnSql = NULL, *type = NULL, *typeValues = NULL, *_0$$8 = NULL, *_1$$8, *_2$$10 = NULL, *_3$$10 = NULL, *_4$$10, *_5$$16 = NULL, *_6$$16, *_7$$24 = NULL, *_8$$27 = NULL, *_9$$39, *_10$$39 = NULL, *_11$$39, *value$$41 = NULL, *valueSql$$41 = NULL, **_14$$41, _19$$41, _20$$41, *_21$$41, *_22$$41, _15$$42 = zval_used_for_init, *_16$$42 = NULL, *_18$$42 = NULL, _23$$43, *_24$$43 = NULL, *_25$$43;

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
				zephir_concat_self_str(&columnSql, SL("INTEGER") TSRMLS_CC);
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
			ZEPHIR_CALL_METHOD(&_0$$8, column, "getsize", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_1$$8);
			ZEPHIR_CONCAT_SVS(_1$$8, "(", _0$$8, ")");
			zephir_concat_self(&columnSql, _1$$8 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 3)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("NUMERIC") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_2$$10, column, "getsize", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_3$$10, column, "getscale", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_4$$10);
			ZEPHIR_CONCAT_SVSVS(_4$$10, "(", _2$$10, ",", _3$$10, ")");
			zephir_concat_self(&columnSql, _4$$10 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 4)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DATETIME") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 17)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TIMESTAMP") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 5)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHARACTER") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_5$$16, column, "getsize", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_6$$16);
			ZEPHIR_CONCAT_SVS(_6$$16, "(", _5$$16, ")");
			zephir_concat_self(&columnSql, _6$$16 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 6)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TEXT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 8)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TINYINT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 7)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("FLOAT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 9)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DOUBLE") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_7$$24, column, "isunsigned", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(_7$$24)) {
				zephir_concat_self_str(&columnSql, SL(" UNSIGNED") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 14)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("BIGINT") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_8$$27, column, "isunsigned", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(_8$$27)) {
				zephir_concat_self_str(&columnSql, SL(" UNSIGNED") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 10)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TINYBLOB") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 11)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("BLOB") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 12)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("MEDIUMBLOB") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 13)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("LONGBLOB") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_EMPTY(columnSql)) {
			ZEPHIR_INIT_VAR(_9$$39);
			object_init_ex(_9$$39, phalcon_db_exception_ce);
			ZEPHIR_CALL_METHOD(&_10$$39, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_11$$39);
			ZEPHIR_CONCAT_SV(_11$$39, "Unrecognized SQLite data type at column ", _10$$39);
			ZEPHIR_CALL_METHOD(NULL, _9$$39, "__construct", NULL, 9, _11$$39);
			zephir_check_call_status();
			zephir_throw_exception_debug(_9$$39, "phalcon/db/dialect/sqlite.zep", 169 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&typeValues, column, "gettypevalues", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(typeValues))) {
			if (Z_TYPE_P(typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(valueSql$$41);
				ZVAL_STRING(valueSql$$41, "", 1);
				zephir_is_iterable(typeValues, &_13$$41, &_12$$41, 0, 0, "phalcon/db/dialect/sqlite.zep", 180);
				for (
				  ; zend_hash_get_current_data_ex(_13$$41, (void**) &_14$$41, &_12$$41) == SUCCESS
				  ; zend_hash_move_forward_ex(_13$$41, &_12$$41)
				) {
					ZEPHIR_GET_HVALUE(value$$41, _14$$41);
					ZEPHIR_SINIT_NVAR(_15$$42);
					ZVAL_STRING(&_15$$42, "\"", 0);
					ZEPHIR_CALL_FUNCTION(&_16$$42, "addcslashes", &_17, 169, value$$41, &_15$$42);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_18$$42);
					ZEPHIR_CONCAT_SVS(_18$$42, "\"", _16$$42, "\", ");
					zephir_concat_self(&valueSql$$41, _18$$42 TSRMLS_CC);
				}
				ZEPHIR_SINIT_VAR(_19$$41);
				ZVAL_LONG(&_19$$41, 0);
				ZEPHIR_SINIT_VAR(_20$$41);
				ZVAL_LONG(&_20$$41, -2);
				ZEPHIR_INIT_VAR(_21$$41);
				zephir_substr(_21$$41, valueSql$$41, 0 , -2 , 0);
				ZEPHIR_INIT_VAR(_22$$41);
				ZEPHIR_CONCAT_SVS(_22$$41, "(", _21$$41, ")");
				zephir_concat_self(&columnSql, _22$$41 TSRMLS_CC);
			} else {
				ZEPHIR_SINIT_VAR(_23$$43);
				ZVAL_STRING(&_23$$43, "\"", 0);
				ZEPHIR_CALL_FUNCTION(&_24$$43, "addcslashes", &_17, 169, typeValues, &_23$$43);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_25$$43);
				ZEPHIR_CONCAT_SVS(_25$$43, "(\"", _24$$43, "\")");
				zephir_concat_self(&columnSql, _25$$43 TSRMLS_CC);
			}
		}
	} while(0);

	RETURN_CCTOR(columnSql);

}

/**
 * Generates SQL to add a column to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addColumn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *sql = NULL, *defaultValue = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL, *_9 = NULL, *_10 = NULL, *_5$$3, _6$$5, *_7$$5 = NULL, *_8$$5;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &column);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVS(sql, "ALTER TABLE ", _0, " ADD COLUMN ");
	ZEPHIR_CALL_METHOD(&_1, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVSV(_3, "\"", _1, "\" ", _2);
	zephir_concat_self(&sql, _3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, column, "hasdefault", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_4)) {
		ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_fast_strtoupper(_5$$3, defaultValue);
		if (zephir_memnstr_str(_5$$3, SL("CURRENT_TIMESTAMP"), "phalcon/db/dialect/sqlite.zep", 203)) {
			zephir_concat_self_str(&sql, SL(" DEFAULT CURRENT_TIMESTAMP") TSRMLS_CC);
		} else {
			ZEPHIR_SINIT_VAR(_6$$5);
			ZVAL_STRING(&_6$$5, "\"", 0);
			ZEPHIR_CALL_FUNCTION(&_7$$5, "addcslashes", NULL, 169, defaultValue, &_6$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_8$$5);
			ZEPHIR_CONCAT_SVS(_8$$5, " DEFAULT \"", _7$$5, "\"");
			zephir_concat_self(&sql, _8$$5 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_9, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_9)) {
		zephir_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_10, column, "isautoincrement", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_10)) {
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

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	if (!currentColumn) {
		currentColumn = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Altering a DB column is not supported by SQLite", "phalcon/db/dialect/sqlite.zep", 226);
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

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(columnName_param) != IS_STRING && Z_TYPE_P(columnName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'columnName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(columnName_param) == IS_STRING)) {
		zephir_get_strval(columnName, columnName_param);
	} else {
		ZEPHIR_INIT_VAR(columnName);
		ZVAL_EMPTY_STRING(columnName);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Dropping DB column is not supported by SQLite", "phalcon/db/dialect/sqlite.zep", 234);
	return;

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addIndex) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *sql = NULL, *indexType = NULL, *_4 = NULL, *_5 = NULL, *_6, *_0$$5 = NULL, *_1$$5, *_2$$6 = NULL, *_3$$6;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
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
	if (!(!schemaName) && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CALL_METHOD(&_0$$5, index, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_1$$5);
		ZEPHIR_CONCAT_VSVSVS(_1$$5, schemaName, "\".\"", _0$$5, "\" ON \"", tableName, "\" (");
		zephir_concat_self(&sql, _1$$5 TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&_2$$6, index, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$6);
		ZEPHIR_CONCAT_VSVS(_3$$6, _2$$6, "\" ON \"", tableName, "\" (");
		zephir_concat_self(&sql, _3$$6 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_5, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getcolumnlist", NULL, 57, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_VS(_6, _4, ")");
	zephir_concat_self(&sql, _6 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete an index from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropIndex) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName_param = NULL;
	zval *tableName = NULL, *schemaName = NULL, *indexName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &indexName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(indexName_param) != IS_STRING && Z_TYPE_P(indexName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'indexName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(indexName_param) == IS_STRING)) {
		zephir_get_strval(indexName, indexName_param);
	} else {
		ZEPHIR_INIT_VAR(indexName);
		ZVAL_EMPTY_STRING(indexName);
	}


	if (!(!schemaName) && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "DROP INDEX \"", schemaName, "\".\"", indexName, "\"");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "DROP INDEX \"", indexName, "\"");
	RETURN_MM();

}

/**
 * Generates SQL to add the primary key to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addPrimaryKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *index;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Adding a primary key after table has been created is not supported by SQLite", "phalcon/db/dialect/sqlite.zep", 278);
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

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Removing a primary key after table has been created is not supported by SQLite", "phalcon/db/dialect/sqlite.zep", 286);
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

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Adding a foreign key constraint to an existing table is not supported by SQLite", "phalcon/db/dialect/sqlite.zep", 294);
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

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(referenceName_param) != IS_STRING && Z_TYPE_P(referenceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceName_param) == IS_STRING)) {
		zephir_get_strval(referenceName, referenceName_param);
	} else {
		ZEPHIR_INIT_VAR(referenceName);
		ZVAL_EMPTY_STRING(referenceName);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Dropping a foreign key constraint is not supported by SQLite", "phalcon/db/dialect/sqlite.zep", 302);
	return;

}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createTable) {

	HashTable *_1, *_18$$14, *_31$$18;
	HashPosition _0, _17$$14, _30$$18;
	zend_bool hasPrimary = 0, _7$$7, _9$$7, _20$$15, _21$$15;
	zephir_fcall_cache_entry *_5 = NULL, *_14 = NULL, *_25 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *definition = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, *columns = NULL, *table = NULL, *temporary = NULL, *options = NULL, *createLines = NULL, *columnLine = NULL, *column = NULL, *indexes = NULL, *index = NULL, *indexName = NULL, *indexType = NULL, *references = NULL, *reference = NULL, *defaultValue = NULL, *referenceSql = NULL, *onDelete = NULL, *onUpdate = NULL, *sql = NULL, **_2, *_41, *_42, *_3$$7 = NULL, *_4$$7 = NULL, *_6$$7 = NULL, *_8$$7 = NULL, *_10$$7 = NULL, *_16$$7 = NULL, *_11$$10 = NULL, _12$$12 = zval_used_for_init, *_13$$12 = NULL, *_15$$12 = NULL, **_19$$14, *_22$$15 = NULL, *_23$$16 = NULL, *_24$$16 = NULL, *_26$$16 = NULL, *_27$$17 = NULL, *_28$$17 = NULL, *_29$$17 = NULL, **_32$$18, *_33$$19 = NULL, *_34$$19 = NULL, *_35$$19 = NULL, *_36$$19 = NULL, *_37$$19 = NULL, *_38$$19 = NULL, *_39$$20 = NULL, *_40$$21 = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	definition = definition_param;


	ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(temporary);
	ZVAL_BOOL(temporary, 0);
	ZEPHIR_OBS_VAR(options);
	if (zephir_array_isset_string_fetch(&options, definition, SS("options"), 0 TSRMLS_CC)) {
		ZEPHIR_OBS_NVAR(temporary);
		zephir_array_isset_string_fetch(&temporary, options, SS("temporary"), 0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, definition, SS("columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array", "phalcon/db/dialect/sqlite.zep", 322);
		return;
	}
	ZEPHIR_INIT_VAR(sql);
	if (zephir_is_true(temporary)) {
		ZEPHIR_CONCAT_SVS(sql, "CREATE TEMPORARY TABLE ", table, " (\n\t");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "CREATE TABLE ", table, " (\n\t");
	}
	hasPrimary = 0;
	ZEPHIR_INIT_VAR(createLines);
	array_init(createLines);
	zephir_is_iterable(columns, &_1, &_0, 0, 0, "phalcon/db/dialect/sqlite.zep", 380);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(column, _2);
		ZEPHIR_CALL_METHOD(&_3$$7, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$7, this_ptr, "getcolumndefinition", &_5, 0, column);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(columnLine);
		ZEPHIR_CONCAT_SVSV(columnLine, "`", _3$$7, "` ", _4$$7);
		ZEPHIR_CALL_METHOD(&_6$$7, column, "isprimary", NULL, 0);
		zephir_check_call_status();
		_7$$7 = zephir_is_true(_6$$7);
		if (_7$$7) {
			_7$$7 = !hasPrimary;
		}
		if (_7$$7) {
			zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY") TSRMLS_CC);
			hasPrimary = 1;
		}
		ZEPHIR_CALL_METHOD(&_8$$7, column, "isautoincrement", NULL, 0);
		zephir_check_call_status();
		_9$$7 = zephir_is_true(_8$$7);
		if (_9$$7) {
			_9$$7 = hasPrimary;
		}
		if (_9$$7) {
			zephir_concat_self_str(&columnLine, SL(" AUTOINCREMENT") TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_10$$7, column, "hasdefault", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_10$$7)) {
			ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_11$$10);
			zephir_fast_strtoupper(_11$$10, defaultValue);
			if (zephir_memnstr_str(_11$$10, SL("CURRENT_TIMESTAMP"), "phalcon/db/dialect/sqlite.zep", 360)) {
				zephir_concat_self_str(&columnLine, SL(" DEFAULT CURRENT_TIMESTAMP") TSRMLS_CC);
			} else {
				ZEPHIR_SINIT_NVAR(_12$$12);
				ZVAL_STRING(&_12$$12, "\"", 0);
				ZEPHIR_CALL_FUNCTION(&_13$$12, "addcslashes", &_14, 169, defaultValue, &_12$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_15$$12);
				ZEPHIR_CONCAT_SVS(_15$$12, " DEFAULT \"", _13$$12, "\"");
				zephir_concat_self(&columnLine, _15$$12 TSRMLS_CC);
			}
		}
		ZEPHIR_CALL_METHOD(&_16$$7, column, "isnotnull", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_16$$7)) {
			zephir_concat_self_str(&columnLine, SL(" NOT NULL") TSRMLS_CC);
		}
		zephir_array_append(&createLines, columnLine, PH_SEPARATE, "phalcon/db/dialect/sqlite.zep", 374);
	}
	ZEPHIR_OBS_VAR(indexes);
	if (zephir_array_isset_string_fetch(&indexes, definition, SS("indexes"), 0 TSRMLS_CC)) {
		zephir_is_iterable(indexes, &_18$$14, &_17$$14, 0, 0, "phalcon/db/dialect/sqlite.zep", 396);
		for (
		  ; zend_hash_get_current_data_ex(_18$$14, (void**) &_19$$14, &_17$$14) == SUCCESS
		  ; zend_hash_move_forward_ex(_18$$14, &_17$$14)
		) {
			ZEPHIR_GET_HVALUE(index, _19$$14);
			ZEPHIR_CALL_METHOD(&indexName, index, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&indexType, index, "gettype", NULL, 0);
			zephir_check_call_status();
			_20$$15 = ZEPHIR_IS_STRING(indexName, "PRIMARY");
			if (_20$$15) {
				_20$$15 = !hasPrimary;
			}
			_21$$15 = !(ZEPHIR_IS_EMPTY(indexType));
			if (_21$$15) {
				ZEPHIR_INIT_NVAR(_22$$15);
				zephir_fast_strtoupper(_22$$15, indexType);
				_21$$15 = zephir_memnstr_str(_22$$15, SL("UNIQUE"), "phalcon/db/dialect/sqlite.zep", 392);
			}
			if (_20$$15) {
				ZEPHIR_CALL_METHOD(&_24$$16, index, "getcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_23$$16, this_ptr, "getcolumnlist", &_25, 57, _24$$16);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_26$$16);
				ZEPHIR_CONCAT_SVS(_26$$16, "PRIMARY KEY (", _23$$16, ")");
				zephir_array_append(&createLines, _26$$16, PH_SEPARATE, "phalcon/db/dialect/sqlite.zep", 391);
			} else if (_21$$15) {
				ZEPHIR_CALL_METHOD(&_28$$17, index, "getcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_27$$17, this_ptr, "getcolumnlist", &_25, 57, _28$$17);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_29$$17);
				ZEPHIR_CONCAT_SVS(_29$$17, "UNIQUE (", _27$$17, ")");
				zephir_array_append(&createLines, _29$$17, PH_SEPARATE, "phalcon/db/dialect/sqlite.zep", 393);
			}
		}
	}
	ZEPHIR_OBS_VAR(references);
	if (zephir_array_isset_string_fetch(&references, definition, SS("references"), 0 TSRMLS_CC)) {
		zephir_is_iterable(references, &_31$$18, &_30$$18, 0, 0, "phalcon/db/dialect/sqlite.zep", 418);
		for (
		  ; zend_hash_get_current_data_ex(_31$$18, (void**) &_32$$18, &_30$$18) == SUCCESS
		  ; zend_hash_move_forward_ex(_31$$18, &_30$$18)
		) {
			ZEPHIR_GET_HVALUE(reference, _32$$18);
			ZEPHIR_CALL_METHOD(&_33$$19, reference, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_35$$19, reference, "getcolumns", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_34$$19, this_ptr, "getcolumnlist", &_25, 57, _35$$19);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_36$$19, reference, "getreferencedtable", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_38$$19, reference, "getreferencedcolumns", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_37$$19, this_ptr, "getcolumnlist", &_25, 57, _38$$19);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(referenceSql);
			ZEPHIR_CONCAT_SVSVSSVSVS(referenceSql, "CONSTRAINT `", _33$$19, "` FOREIGN KEY (", _34$$19, ")", " REFERENCES `", _36$$19, "`(", _37$$19, ")");
			ZEPHIR_CALL_METHOD(&onDelete, reference, "getondelete", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(onDelete))) {
				ZEPHIR_INIT_LNVAR(_39$$20);
				ZEPHIR_CONCAT_SV(_39$$20, " ON DELETE ", onDelete);
				zephir_concat_self(&referenceSql, _39$$20 TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&onUpdate, reference, "getonupdate", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(onUpdate))) {
				ZEPHIR_INIT_LNVAR(_40$$21);
				ZEPHIR_CONCAT_SV(_40$$21, " ON UPDATE ", onUpdate);
				zephir_concat_self(&referenceSql, _40$$21 TSRMLS_CC);
			}
			zephir_array_append(&createLines, referenceSql, PH_SEPARATE, "phalcon/db/dialect/sqlite.zep", 416);
		}
	}
	ZEPHIR_INIT_VAR(_41);
	zephir_fast_join_str(_41, SL(",\n\t"), createLines TSRMLS_CC);
	ZEPHIR_INIT_VAR(_42);
	ZEPHIR_CONCAT_VS(_42, _41, "\n)");
	zephir_concat_self(&sql, _42 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to truncate a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, truncateTable) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *sql = NULL, *table = NULL;
	zval *tableName = NULL, *schemaName = NULL, *_0$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}


	if (!(!schemaName) && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_CONCAT_VSV(_0$$3, schemaName, "\".\"", tableName);
		ZEPHIR_CPY_WRT(table, _0$$3);
	} else {
		ZEPHIR_CPY_WRT(table, tableName);
	}
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVS(sql, "DELETE FROM \"", table, "\"");
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to drop a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropTable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *sql = NULL, *table = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &tableName_param, &schemaName_param, &ifExists_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
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
	if (UNEXPECTED(Z_TYPE_P(ifExists_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ifExists' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ifExists = Z_BVAL_P(ifExists_param);
	}


	ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(sql);
	if (ifExists) {
		ZEPHIR_CONCAT_SV(sql, "DROP TABLE IF EXISTS ", table);
	} else {
		ZEPHIR_CONCAT_SV(sql, "DROP TABLE ", table);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to create a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *definition = NULL;
	zval *viewName_param = NULL, *definition_param = NULL, *schemaName_param = NULL, *viewSql = NULL, *_0 = NULL;
	zval *viewName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &viewName_param, &definition_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array", "phalcon/db/dialect/sqlite.zep", 469);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, viewName, schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSV(return_value, "CREATE VIEW ", _0, " AS ", viewSql);
	RETURN_MM();

}

/**
 * Generates SQL to drop a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *view = NULL;
	zval *viewName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &viewName_param, &schemaName_param, &ifExists_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
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
	if (UNEXPECTED(Z_TYPE_P(ifExists_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ifExists' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ifExists = Z_BVAL_P(ifExists_param);
	}


	ZEPHIR_CALL_METHOD(&view, this_ptr, "preparetable", NULL, 0, viewName, schemaName);
	zephir_check_call_status();
	if (ifExists) {
		ZEPHIR_CONCAT_SV(return_value, "DROP VIEW IF EXISTS ", view);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SV(return_value, "DROP VIEW ", view);
	RETURN_MM();

}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * <code>
 * echo $dialect->tableExists("posts", "blog");
 *
 * echo $dialect->tableExists("posts");
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, tableExists) {

	zval *tableName_param = NULL, *schemaName_param = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
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

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
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
 * print_r(
 *     $dialect->describeColumns("posts")
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeColumns) {

	zval *table_param = NULL, *schema_param = NULL;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
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
 * print_r(
 *     $dialect->listTables("blog")
 * );
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
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	}


	RETURN_MM_STRING("SELECT tbl_name FROM sqlite_master WHERE type = 'view' ORDER BY tbl_name", 1);

}

/**
 * Generates the SQL to get query list of indexes
 *
 * <code>
 * print_r(
 *     $dialect->listIndexesSql("blog")
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listIndexesSql) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *keyName_param = NULL, *_0 = NULL, *_1, *_2$$3 = NULL, *_3$$3;
	zval *table = NULL, *schema = NULL, *keyName = NULL, *sql = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &table_param, &schema_param, &keyName_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
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
	if (!keyName_param) {
		ZEPHIR_INIT_VAR(keyName);
		ZVAL_EMPTY_STRING(keyName);
	} else {
		zephir_get_strval(keyName, keyName_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "escape", NULL, 56, table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "SELECT sql FROM sqlite_master WHERE type = 'index' AND tbl_name = ", _0, " COLLATE NOCASE");
	zephir_get_strval(sql, _1);
	if (!(!keyName) && Z_STRLEN_P(keyName)) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "escape", NULL, 56, keyName);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SVS(_3$$3, " AND name = ", _2$$3, " COLLATE NOCASE");
		zephir_concat_self(&sql, _3$$3 TSRMLS_CC);
	}
	RETURN_CTOR(sql);

}

/**
 * Generates SQL to query indexes on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndexes) {

	zval *table_param = NULL, *schema_param = NULL;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
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

	if (UNEXPECTED(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(index_param) == IS_STRING)) {
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

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
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

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
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

/**
 * Returns a SQL modified a shared lock statement. For now this method
 * returns the original query
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, sharedLock) {

	zval *sqlQuery_param = NULL;
	zval *sqlQuery = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(sqlQuery);
		ZVAL_EMPTY_STRING(sqlQuery);
	}


	RETURN_CTOR(sqlQuery);

}

