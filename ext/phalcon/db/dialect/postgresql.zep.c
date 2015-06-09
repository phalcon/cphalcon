
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


/**
 * Phalcon\Db\Dialect\Postgresql
 *
 * Generates database specific SQL for the PostgreSQL RDBMS
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Postgresql) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Postgresql, phalcon, db_dialect_postgresql, phalcon_db_dialect_ce, phalcon_db_dialect_postgresql_method_entry, 0);

	zend_declare_property_string(phalcon_db_dialect_postgresql_ce, SL("_escapeChar"), "\"", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Gets the column name in PostgreSQL
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getColumnDefinition) {

	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *column, *size = NULL, *columnType = NULL, *columnSql, *typeValues = NULL, *_0 = NULL, *_1 = NULL, *value = NULL, *valueSql, **_4, _5 = zval_used_for_init, _7 = zval_used_for_init, *_8, *_9 = NULL, *_10 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_CALL_METHOD(&size, column, "getsize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnType, column, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(columnSql);
	ZVAL_STRING(columnSql, "", 1);
	if (Z_TYPE_P(columnType) == IS_STRING) {
		zephir_concat_self(&columnSql, columnType TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&columnType, column, "gettypereference", NULL, 0);
		zephir_check_call_status();
	}
	do {
		if (ZEPHIR_IS_LONG(columnType, 0)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				ZEPHIR_CALL_METHOD(&_0, column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(_0)) {
					zephir_concat_self_str(&columnSql, SL("SERIAL") TSRMLS_CC);
				} else {
					zephir_concat_self_str(&columnSql, SL("INT") TSRMLS_CC);
				}
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
			ZEPHIR_INIT_VAR(_1);
			ZEPHIR_CONCAT_SVS(_1, "(", size, ")");
			zephir_concat_self(&columnSql, _1 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 3)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("NUMERIC") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_0, column, "getscale", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_1);
			ZEPHIR_CONCAT_SVSVS(_1, "(", size, ",", _0, ")");
			zephir_concat_self(&columnSql, _1 TSRMLS_CC);
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
			ZEPHIR_INIT_LNVAR(_1);
			ZEPHIR_CONCAT_SVS(_1, "(", size, ")");
			zephir_concat_self(&columnSql, _1 TSRMLS_CC);
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Unrecognized PostgreSQL data type", "phalcon/db/dialect/postgresql.zep", 121);
			return;
		}
		ZEPHIR_CALL_METHOD(&typeValues, column, "gettypevalues", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(typeValues))) {
			if (Z_TYPE_P(typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(valueSql);
				ZVAL_STRING(valueSql, "", 1);
				zephir_is_iterable(typeValues, &_3, &_2, 0, 0, "phalcon/db/dialect/postgresql.zep", 132);
				for (
				  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
				  ; zephir_hash_move_forward_ex(_3, &_2)
				) {
					ZEPHIR_GET_HVALUE(value, _4);
					ZEPHIR_SINIT_NVAR(_5);
					ZVAL_STRING(&_5, "\"", 0);
					ZEPHIR_CALL_FUNCTION(&_0, "addcslashes", &_6, 109, value, &_5);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_1);
					ZEPHIR_CONCAT_SVS(_1, "\"", _0, "\", ");
					zephir_concat_self(&valueSql, _1 TSRMLS_CC);
				}
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, 0);
				ZEPHIR_SINIT_VAR(_7);
				ZVAL_LONG(&_7, -2);
				ZEPHIR_INIT_VAR(_8);
				zephir_substr(_8, valueSql, 0 , -2 , 0);
				ZEPHIR_INIT_VAR(_9);
				ZEPHIR_CONCAT_SVS(_9, "(", _8, ")");
				zephir_concat_self(&columnSql, _9 TSRMLS_CC);
			} else {
				ZEPHIR_SINIT_NVAR(_7);
				ZVAL_STRING(&_7, "\"", 0);
				ZEPHIR_CALL_FUNCTION(&_10, "addcslashes", &_6, 109, typeValues, &_7);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_9);
				ZEPHIR_CONCAT_SVS(_9, "(\"", _10, "\")");
				zephir_concat_self(&columnSql, _9 TSRMLS_CC);
			}
		}
	} while(0);

	RETURN_CCTOR(columnSql);

}

/**
 * Generates SQL to add a column to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addColumn) {

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
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to modify a column in a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, modifyColumn) {

	zend_bool _10;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *currentColumn = NULL, *sql, *sqlAlterTable = NULL, *defaultValue = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, _11, *_12 = NULL;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

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
	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "", 1);


	ZEPHIR_INIT_VAR(sqlAlterTable);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE \"", schemaName, "\".\"", tableName, "\"");
		ZEPHIR_CPY_WRT(sqlAlterTable, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE \"", tableName, "\"");
		ZEPHIR_CPY_WRT(sqlAlterTable, _0);
	}
	ZEPHIR_CALL_METHOD(&_1, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, currentColumn, "getname", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_1, _2)) {
		ZEPHIR_CALL_METHOD(&_3, currentColumn, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_VSVSVS(_5, sqlAlterTable, " RENAME COLUMN \"", _3, "\" TO \"", _4, "\";");
		zephir_concat_self(&sql, _5 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_3, column, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, currentColumn, "gettype", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_3, _4)) {
		ZEPHIR_CALL_METHOD(&_6, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "getcolumndefinition", NULL, 0, column);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_VSVSVS(_5, sqlAlterTable, " ALTER COLUMN \"", _6, "\" TYPE ", _7, ";");
		zephir_concat_self(&sql, _5 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_3, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, currentColumn, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_3, _4)) {
		ZEPHIR_CALL_METHOD(&_6, column, "isnotnull", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_6)) {
			ZEPHIR_CALL_METHOD(&_7, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_VSVS(_5, sqlAlterTable, " ALTER COLUMN \"", _7, "\" SET NOT NULL;");
			zephir_concat_self(&sql, _5 TSRMLS_CC);
		} else {
			ZEPHIR_CALL_METHOD(&_8, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_9);
			ZEPHIR_CONCAT_VSVS(_9, sqlAlterTable, " ALTER COLUMN \"", _8, "\" DROP NOT NULL;");
			zephir_concat_self(&sql, _9 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_3, column, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, currentColumn, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_3, _4)) {
		ZEPHIR_CALL_METHOD(&_6, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		_10 = ZEPHIR_IS_EMPTY(_6);
		if (_10) {
			ZEPHIR_CALL_METHOD(&_7, currentColumn, "getdefault", NULL, 0);
			zephir_check_call_status();
			_10 = !(ZEPHIR_IS_EMPTY(_7));
		}
		if (_10) {
			ZEPHIR_CALL_METHOD(&_8, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_VSVS(_5, sqlAlterTable, " ALTER COLUMN \"", _8, "\" DROP DEFAULT;");
			zephir_concat_self(&sql, _5 TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(defaultValue))) {
			ZEPHIR_CALL_METHOD(&_8, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_SINIT_VAR(_11);
			ZVAL_STRING(&_11, "\"", 0);
			ZEPHIR_CALL_FUNCTION(&_12, "addcslashes", NULL, 109, defaultValue, &_11);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_VSVSVS(_9, sqlAlterTable, " ALTER COLUMN \"", _8, "\" SET DEFAULT \"", _12, "\"");
			zephir_concat_self(&sql, _9 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete a column from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropColumn) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL, *sql = NULL;
	zval *tableName = NULL, *schemaName = NULL, *columnName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE \"", schemaName, "\".\"", tableName, "\" ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE \"", tableName, "\" ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SVS(_0, " DROP COLUMN \"", columnName, "\"");
	zephir_concat_self(&sql, _0 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addIndex) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *sql, *indexType = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_4 = NULL, *_5 = NULL;
	zval *tableName = NULL, *schemaName = NULL, *_3 = NULL;

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


	ZEPHIR_CALL_METHOD(&_0, index, "getname", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING_IDENTICAL(_0, "PRIMARY")) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addprimarykey", NULL, 0, tableName, schemaName, index);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "CREATE", 1);
	ZEPHIR_CALL_METHOD(&indexType, index, "gettype", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(indexType))) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SV(_1, " ", indexType);
		zephir_concat_self(&sql, _1 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_2, index, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SVS(_1, " INDEX \"", _2, "\" ON");
	zephir_concat_self(&sql, _1 TSRMLS_CC);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVSVS(_3, " \"", schemaName, "\".\"", tableName, "\"");
		zephir_concat_self(&sql, _3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SVS(_3, " \"", tableName, "\"");
		zephir_concat_self(&sql, _3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_5, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getcolumnlist", NULL, 100, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SVS(_1, " (", _4, ")");
	zephir_concat_self(&sql, _1 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete an index from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropIndex) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName_param = NULL;
	zval *tableName = NULL, *schemaName = NULL, *indexName = NULL;

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


	ZEPHIR_CONCAT_SVS(return_value, "DROP INDEX \"", indexName, "\"");
	RETURN_MM();

}

/**
 * Generates SQL to add the primary key to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addPrimaryKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *sql = NULL, *_1 = NULL, *_2 = NULL, *_3;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE \"", schemaName, "\".\"", tableName, "\"");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE \"", tableName, "\"");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_CALL_METHOD(&_2, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcolumnlist", NULL, 100, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, " ADD CONSTRAINT \"PRIMARY\" PRIMARY KEY (", _1, ")");
	zephir_concat_self(&sql, _3 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete primary key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *sql = NULL;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE \"", schemaName, "\".\"", tableName, "\"");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE \"", tableName, "\"");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	zephir_concat_self_str(&sql, SL(" DROP CONSTRAINT \"PRIMARY\"") TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addForeignKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, *sql = NULL, *onDelete = NULL, *onUpdate = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7, *_8 = NULL;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE \"", schemaName, "\".\"", tableName, "\" ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE \"", tableName, "\" ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_CALL_METHOD(&_1, reference, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, reference, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcolumnlist", NULL, 100, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, reference, "getreferencedtable", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, reference, "getreferencedcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumnlist", NULL, 100, _6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SVSVSSVSVS(_7, "ADD CONSTRAINT \"", _1, "\" FOREIGN KEY (", _2, ")", " REFERENCES \"", _4, "\" (", _5, ")");
	zephir_concat_self(&sql, _7 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&onDelete, reference, "getondelete", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(onDelete))) {
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_CONCAT_SV(_8, " ON DELETE ", onDelete);
		zephir_concat_self(&sql, _8 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&onUpdate, reference, "getonupdate", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(onUpdate))) {
		ZEPHIR_INIT_LNVAR(_8);
		ZEPHIR_CONCAT_SV(_8, " ON UPDATE ", onUpdate);
		zephir_concat_self(&sql, _8 TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropForeignKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName_param = NULL, *sql = NULL;
	zval *tableName = NULL, *schemaName = NULL, *referenceName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE \"", schemaName, "\".\"", tableName, "\"");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE \"", tableName, "\"");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SVS(_0, " DROP CONSTRAINT \"", referenceName, "\"");
	zephir_concat_self(&sql, _0 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createTable) {

	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL, *_17 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2, *_15, *_24;
	HashPosition _1, _14, _23;
	zval *definition = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, *temporary = NULL, *options, *table = NULL, *createLines, *columns, *column = NULL, *indexes, *index = NULL, *reference = NULL, *references, *indexName = NULL, *indexSql = NULL, *indexSqlAfterCreate, *sql, *columnLine = NULL, *indexType = NULL, *referenceSql = NULL, *onDelete = NULL, *onUpdate = NULL, *defaultValue = NULL, *primaryColumns, **_3, *_4 = NULL, *_5 = NULL, _7 = zval_used_for_init, *_8 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, **_16, *_18 = NULL, *_20 = NULL, *_21 = NULL, *_22 = NULL, **_25, *_26 = NULL, *_27;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL, *_19 = NULL;

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



	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, definition, SS("columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array", "phalcon/db/dialect/postgresql.zep", 358);
		return;
	}
	ZEPHIR_INIT_VAR(table);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "\"", schemaName, "\".\"", tableName, "\"");
		ZEPHIR_CPY_WRT(table, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "\"", tableName, "\"");
		ZEPHIR_CPY_WRT(table, _0);
	}
	ZEPHIR_INIT_VAR(temporary);
	ZVAL_BOOL(temporary, 0);
	ZEPHIR_OBS_VAR(options);
	if (zephir_array_isset_string_fetch(&options, definition, SS("options"), 0 TSRMLS_CC)) {
		ZEPHIR_OBS_NVAR(temporary);
		zephir_array_isset_string_fetch(&temporary, options, SS("temporary"), 0 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(sql);
	if (zephir_is_true(temporary)) {
		ZEPHIR_CONCAT_SVS(sql, "CREATE TEMPORARY TABLE ", table, " (\n\t");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "CREATE TABLE ", table, " (\n\t");
	}
	ZEPHIR_INIT_VAR(createLines);
	array_init(createLines);
	ZEPHIR_INIT_VAR(primaryColumns);
	array_init(primaryColumns);
	zephir_is_iterable(columns, &_2, &_1, 0, 0, "phalcon/db/dialect/postgresql.zep", 418);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(column, _3);
		ZEPHIR_CALL_METHOD(&_4, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumndefinition", &_6, 0, column);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(columnLine);
		ZEPHIR_CONCAT_SVSV(columnLine, "\"", _4, "\" ", _5);
		ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(defaultValue))) {
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_STRING(&_7, "\"", 0);
			ZEPHIR_CALL_FUNCTION(&_8, "addcslashes", &_9, 109, defaultValue, &_7);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_10);
			ZEPHIR_CONCAT_SVS(_10, " DEFAULT \"", _8, "\"");
			zephir_concat_self(&columnLine, _10 TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_8, column, "isnotnull", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_8)) {
			zephir_concat_self_str(&columnLine, SL(" NOT NULL") TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_8, column, "isautoincrement", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_8)) {
		}
		ZEPHIR_CALL_METHOD(&_11, column, "isprimary", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_11)) {
			ZEPHIR_CALL_METHOD(&_12, column, "getname", NULL, 0);
			zephir_check_call_status();
			zephir_array_append(&primaryColumns, _12, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 413);
		}
		zephir_array_append(&createLines, columnLine, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 416);
	}
	if (!(ZEPHIR_IS_EMPTY(primaryColumns))) {
		ZEPHIR_INIT_VAR(_13);
		zephir_fast_join_str(_13, SL(","), primaryColumns TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_10);
		ZEPHIR_CONCAT_SVS(_10, "PRIMARY KEY (", _13, ")");
		zephir_array_append(&createLines, _10, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 419);
	}
	ZEPHIR_INIT_VAR(indexSqlAfterCreate);
	ZVAL_STRING(indexSqlAfterCreate, "", 1);
	ZEPHIR_OBS_VAR(indexes);
	if (zephir_array_isset_string_fetch(&indexes, definition, SS("indexes"), 0 TSRMLS_CC)) {
		zephir_is_iterable(indexes, &_15, &_14, 0, 0, "phalcon/db/dialect/postgresql.zep", 459);
		for (
		  ; zephir_hash_get_current_data_ex(_15, (void**) &_16, &_14) == SUCCESS
		  ; zephir_hash_move_forward_ex(_15, &_14)
		) {
			ZEPHIR_GET_HVALUE(index, _16);
			ZEPHIR_CALL_METHOD(&indexName, index, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&indexType, index, "gettype", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(indexSql);
			ZVAL_STRING(indexSql, "", 1);
			if (ZEPHIR_IS_STRING(indexName, "PRIMARY")) {
				ZEPHIR_CALL_METHOD(&_5, index, "getcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4, this_ptr, "getcolumnlist", &_17, 100, _5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(indexSql);
				ZEPHIR_CONCAT_SVS(indexSql, "CONSTRAINT \"PRIMARY\" PRIMARY KEY (", _4, ")");
			} else {
				if (!(ZEPHIR_IS_EMPTY(indexType))) {
					ZEPHIR_CALL_METHOD(&_11, index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_8, this_ptr, "getcolumnlist", &_17, 100, _11);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(indexSql);
					ZEPHIR_CONCAT_SVSVSVS(indexSql, "CONSTRAINT \"", indexName, "\" ", indexType, " (", _8, ")");
				} else {
					ZEPHIR_CALL_METHOD(&_12, index, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_18);
					ZEPHIR_CONCAT_SVS(_18, "CREATE INDEX \"", _12, "\" ON ");
					zephir_concat_self(&indexSqlAfterCreate, _18 TSRMLS_CC);
					if (schemaName && Z_STRLEN_P(schemaName)) {
						ZEPHIR_INIT_LNVAR(_0);
						ZEPHIR_CONCAT_SVSVS(_0, "\"", schemaName, "\".\"", tableName, "\"");
						zephir_concat_self(&indexSqlAfterCreate, _0 TSRMLS_CC);
					} else {
						ZEPHIR_INIT_LNVAR(_19);
						ZEPHIR_CONCAT_SVS(_19, "\"", tableName, "\"");
						zephir_concat_self(&indexSqlAfterCreate, _19 TSRMLS_CC);
					}
					ZEPHIR_CALL_METHOD(&_21, index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_20, this_ptr, "getcolumnlist", &_17, 100, _21);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_22);
					ZEPHIR_CONCAT_SVS(_22, " (", _20, ");");
					zephir_concat_self(&indexSqlAfterCreate, _22 TSRMLS_CC);
				}
			}
			if (!(ZEPHIR_IS_EMPTY(indexSql))) {
				zephir_array_append(&createLines, indexSql, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 456);
			}
		}
	}
	ZEPHIR_OBS_VAR(references);
	if (zephir_array_isset_string_fetch(&references, definition, SS("references"), 0 TSRMLS_CC)) {
		zephir_is_iterable(references, &_24, &_23, 0, 0, "phalcon/db/dialect/postgresql.zep", 488);
		for (
		  ; zephir_hash_get_current_data_ex(_24, (void**) &_25, &_23) == SUCCESS
		  ; zephir_hash_move_forward_ex(_24, &_23)
		) {
			ZEPHIR_GET_HVALUE(reference, _25);
			ZEPHIR_CALL_METHOD(&_4, reference, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8, reference, "getcolumns", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumnlist", &_17, 100, _8);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(referenceSql);
			ZEPHIR_CONCAT_SVSVS(referenceSql, "CONSTRAINT \"", _4, "\" FOREIGN KEY (", _5, ") REFERENCES ");
			if (schemaName && Z_STRLEN_P(schemaName)) {
				ZEPHIR_CALL_METHOD(&_11, reference, "getreferencedtable", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_10);
				ZEPHIR_CONCAT_SVSVS(_10, "\"", schemaName, "\".\"", _11, "\" ");
				zephir_concat_self(&referenceSql, _10 TSRMLS_CC);
			} else {
				ZEPHIR_CALL_METHOD(&_12, reference, "getreferencedtable", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_18);
				ZEPHIR_CONCAT_SVS(_18, "\"", _12, "\" ");
				zephir_concat_self(&referenceSql, _18 TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_21, reference, "getreferencedcolumns", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_20, this_ptr, "getcolumnlist", &_17, 100, _21);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_22);
			ZEPHIR_CONCAT_SVS(_22, "(", _20, ")");
			zephir_concat_self(&referenceSql, _22 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&onDelete, reference, "getondelete", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(onDelete))) {
				ZEPHIR_INIT_LNVAR(_26);
				ZEPHIR_CONCAT_SV(_26, " ON DELETE ", onDelete);
				zephir_concat_self(&referenceSql, _26 TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&onUpdate, reference, "getonupdate", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(onUpdate))) {
				ZEPHIR_INIT_LNVAR(_26);
				ZEPHIR_CONCAT_SV(_26, " ON UPDATE ", onUpdate);
				zephir_concat_self(&referenceSql, _26 TSRMLS_CC);
			}
			zephir_array_append(&createLines, referenceSql, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 486);
		}
	}
	ZEPHIR_INIT_NVAR(_13);
	zephir_fast_join_str(_13, SL(",\n\t"), createLines TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_10);
	ZEPHIR_CONCAT_VS(_10, _13, "\n)");
	zephir_concat_self(&sql, _10 TSRMLS_CC);
	if (zephir_array_isset_string(definition, SS("options"))) {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "_gettableoptions", NULL, 0, definition);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_26);
		ZEPHIR_CONCAT_SV(_26, " ", _4);
		zephir_concat_self(&sql, _26 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_27);
	ZEPHIR_CONCAT_SV(_27, ";", indexSqlAfterCreate);
	zephir_concat_self(&sql, _27 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to drop a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropTable) {

	zend_bool ifExists;
	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *table = NULL, *sql;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(table);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "\"", schemaName, "\".\"", tableName, "\"");
		ZEPHIR_CPY_WRT(table, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "\"", tableName, "\"");
		ZEPHIR_CPY_WRT(table, _0);
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createView) {

	zval *definition = NULL;
	zval *viewName_param = NULL, *definition_param = NULL, *schemaName_param = NULL, *viewSql, *view = NULL;
	zval *viewName = NULL, *schemaName = NULL, *_0 = NULL;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array", "phalcon/db/dialect/postgresql.zep", 529);
		return;
	}
	ZEPHIR_INIT_VAR(view);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "\"", schemaName, "\".\"", viewName, "\"");
		ZEPHIR_CPY_WRT(view, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "\"", viewName, "\"");
		ZEPHIR_CPY_WRT(view, _0);
	}
	ZEPHIR_CONCAT_SVSV(return_value, "CREATE VIEW ", view, " AS ", viewSql);
	RETURN_MM();

}

/**
 * Generates SQL to drop a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropView) {

	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *view = NULL, *sql;
	zval *viewName = NULL, *schemaName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(view);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "\"", schemaName, "\".\"", viewName, "\"");
		ZEPHIR_CPY_WRT(view, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "\"", viewName, "\"");
		ZEPHIR_CPY_WRT(view, _0);
	}
	ZEPHIR_INIT_VAR(sql);
	if (ifExists) {
		ZEPHIR_CONCAT_SVS(sql, "DROP VIEW IF EXISTS ", view, "");
	} else {
		ZEPHIR_CONCAT_SVS(sql, "DROP VIEW ", view, "");
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableExists) {

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


	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = '", schemaName, "' AND table_name='", tableName, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = 'public' AND table_name='", tableName, "'");
	RETURN_MM();

}

/**
 * Generates SQL checking for the existence of a schema.view
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, viewExists) {

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


	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='", viewName, "' AND schemaname='", schemaName, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='", viewName, "'");
	RETURN_MM();

}

/**
 * Generates SQL describing a table
 *
 * <code>
 *    print_r($dialect->describeColumns("posts"));
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeColumns) {

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


	if (schema && Z_STRLEN_P(schema)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, c.column_default FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='", schema, "' AND c.table_name='", table, "' ORDER BY c.ordinal_position");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, c.column_default FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='public' AND c.table_name='", table, "' ORDER BY c.ordinal_position");
	RETURN_MM();

}

/**
 * List all tables in database
 *
 * <code>
 *     print_r($dialect->listTables("blog"))
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listTables) {

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
		ZEPHIR_CONCAT_SVS(return_value, "SELECT table_name FROM information_schema.tables WHERE table_schema = '", schemaName, "' ORDER BY table_name");
		RETURN_MM();
	}
	RETURN_MM_STRING("SELECT table_name FROM information_schema.tables WHERE table_schema = 'public' ORDER BY table_name", 1);

}

/**
 * Generates the SQL to list all views of a schema or user
 *
 * @param string schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listViews) {

	zval *schemaName = NULL;

	zephir_fetch_params(0, 0, 1, &schemaName);

	if (!schemaName) {
		schemaName = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_is_true(schemaName)) {
		ZEPHIR_CONCAT_SVS(return_value, "SELECT viewname AS view_name FROM pg_views WHERE schemaname = '", schemaName, "' ORDER BY view_name");
		return;
	}
	RETURN_STRING("SELECT viewname AS view_name FROM pg_views WHERE schemaname = 'public' ORDER BY view_name", 1);

}

/**
 * Generates SQL to query indexes on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeIndexes) {

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


	ZEPHIR_CONCAT_SVS(return_value, "SELECT 0 as c0, t.relname as table_name, i.relname as key_name, 3 as c3, a.attname as column_name FROM pg_class t, pg_class i, pg_index ix, pg_attribute a WHERE t.oid = ix.indrelid AND i.oid = ix.indexrelid AND a.attrelid = t.oid AND a.attnum = ANY(ix.indkey) AND t.relkind = 'r' AND t.relname = '", table, "' ORDER BY t.relname, i.relname;");
	RETURN_MM();

}

/**
 * Generates SQL to query foreign keys on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeReferences) {

	zval *table_param = NULL, *schema_param = NULL, *sql;
	zval *table = NULL, *schema = NULL, *_0 = NULL;

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
	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT tc.table_name as TABLE_NAME, kcu.column_name as COLUMN_NAME, tc.constraint_name as CONSTRAINT_NAME, tc.table_catalog as REFERENCED_TABLE_SCHEMA, ccu.table_name AS REFERENCED_TABLE_NAME, ccu.column_name AS REFERENCED_COLUMN_NAME FROM information_schema.table_constraints AS tc JOIN information_schema.key_column_usage AS kcu ON tc.constraint_name = kcu.constraint_name JOIN information_schema.constraint_column_usage AS ccu ON ccu.constraint_name = tc.constraint_name WHERE constraint_type = 'FOREIGN KEY' AND ", 1);


	if (schema && Z_STRLEN_P(schema)) {
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
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableOptions) {

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

PHP_METHOD(Phalcon_Db_Dialect_Postgresql, _getTableOptions) {

	zval *definition_param = NULL;
	zval *definition = NULL;

	zephir_fetch_params(0, 1, 0, &definition_param);

	definition = definition_param;



	RETURN_STRING("", 1);

}

