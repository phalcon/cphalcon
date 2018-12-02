
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

	HashTable *_10$$37;
	HashPosition _9$$37;
	zephir_fcall_cache_entry *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, *size = NULL, *columnType = NULL, *columnSql = NULL, *typeValues = NULL, *_0$$5 = NULL, *_1$$10, *_2$$12 = NULL, *_3$$12, *_4$$18, *_5$$25 = NULL, *_6$$35, *_7$$35 = NULL, *_8$$35, *value$$37 = NULL, *valueSql$$37 = NULL, **_11$$37, _16$$37, _17$$37, *_18$$37, *_19$$37, _12$$38 = zval_used_for_init, *_13$$38 = NULL, *_15$$38 = NULL, _20$$39, *_21$$39 = NULL, *_22$$39;

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
				ZEPHIR_CALL_METHOD(&_0$$5, column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(_0$$5)) {
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
			ZEPHIR_INIT_VAR(_1$$10);
			ZEPHIR_CONCAT_SVS(_1$$10, "(", size, ")");
			zephir_concat_self(&columnSql, _1$$10 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 3)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("NUMERIC") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_2$$12, column, "getscale", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_3$$12);
			ZEPHIR_CONCAT_SVSVS(_3$$12, "(", size, ",", _2$$12, ")");
			zephir_concat_self(&columnSql, _3$$12 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 4)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TIMESTAMP") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 17)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TIMESTAMP") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 5)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHARACTER") TSRMLS_CC);
			}
			ZEPHIR_INIT_VAR(_4$$18);
			ZEPHIR_CONCAT_SVS(_4$$18, "(", size, ")");
			zephir_concat_self(&columnSql, _4$$18 TSRMLS_CC);
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
		if (ZEPHIR_IS_LONG(columnType, 14)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				ZEPHIR_CALL_METHOD(&_5$$25, column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(_5$$25)) {
					zephir_concat_self_str(&columnSql, SL("BIGSERIAL") TSRMLS_CC);
				} else {
					zephir_concat_self_str(&columnSql, SL("BIGINT") TSRMLS_CC);
				}
			}
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 15)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("JSON") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 16)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("JSONB") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(columnType, 8)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("BOOLEAN") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_EMPTY(columnSql)) {
			ZEPHIR_INIT_VAR(_6$$35);
			object_init_ex(_6$$35, phalcon_db_exception_ce);
			ZEPHIR_CALL_METHOD(&_7$$35, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_8$$35);
			ZEPHIR_CONCAT_SV(_8$$35, "Unrecognized PostgreSQL data type at column ", _7$$35);
			ZEPHIR_CALL_METHOD(NULL, _6$$35, "__construct", NULL, 9, _8$$35);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6$$35, "phalcon/db/dialect/postgresql.zep", 150 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&typeValues, column, "gettypevalues", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(typeValues))) {
			if (Z_TYPE_P(typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(valueSql$$37);
				ZVAL_STRING(valueSql$$37, "", 1);
				zephir_is_iterable(typeValues, &_10$$37, &_9$$37, 0, 0, "phalcon/db/dialect/postgresql.zep", 161);
				for (
				  ; zend_hash_get_current_data_ex(_10$$37, (void**) &_11$$37, &_9$$37) == SUCCESS
				  ; zend_hash_move_forward_ex(_10$$37, &_9$$37)
				) {
					ZEPHIR_GET_HVALUE(value$$37, _11$$37);
					ZEPHIR_SINIT_NVAR(_12$$38);
					ZVAL_STRING(&_12$$38, "\\'", 0);
					ZEPHIR_CALL_FUNCTION(&_13$$38, "addcslashes", &_14, 169, value$$37, &_12$$38);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_15$$38);
					ZEPHIR_CONCAT_SVS(_15$$38, "'", _13$$38, "', ");
					zephir_concat_self(&valueSql$$37, _15$$38 TSRMLS_CC);
				}
				ZEPHIR_SINIT_VAR(_16$$37);
				ZVAL_LONG(&_16$$37, 0);
				ZEPHIR_SINIT_VAR(_17$$37);
				ZVAL_LONG(&_17$$37, -2);
				ZEPHIR_INIT_VAR(_18$$37);
				zephir_substr(_18$$37, valueSql$$37, 0 , -2 , 0);
				ZEPHIR_INIT_VAR(_19$$37);
				ZEPHIR_CONCAT_SVS(_19$$37, "(", _18$$37, ")");
				zephir_concat_self(&columnSql, _19$$37 TSRMLS_CC);
			} else {
				ZEPHIR_SINIT_VAR(_20$$39);
				ZVAL_STRING(&_20$$39, "\\'", 0);
				ZEPHIR_CALL_FUNCTION(&_21$$39, "addcslashes", &_14, 169, typeValues, &_20$$39);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_22$$39);
				ZEPHIR_CONCAT_SVS(_22$$39, "('", _21$$39, "')");
				zephir_concat_self(&columnSql, _22$$39 TSRMLS_CC);
			}
		}
	} while(0);

	RETURN_CCTOR(columnSql);

}

/**
 * Generates SQL to add a column to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addColumn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *sql = NULL, *columnDefinition = NULL, *_0 = NULL, *_1 = NULL, *_2, *_3 = NULL, *_6 = NULL, *_4$$3 = NULL, *_5$$3;
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


	ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVS(sql, "ALTER TABLE ", _0, " ADD COLUMN ");
	ZEPHIR_CALL_METHOD(&_1, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVSV(_2, "\"", _1, "\" ", columnDefinition);
	zephir_concat_self(&sql, _2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, column, "hasdefault", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "_castdefault", NULL, 0, column);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5$$3);
		ZEPHIR_CONCAT_SV(_5$$3, " DEFAULT ", _4$$3);
		zephir_concat_self(&sql, _5$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_6, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_6)) {
		zephir_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	} else {
		zephir_concat_self_str(&sql, SL(" NULL") TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to modify a column in a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, modifyColumn) {

	zend_bool _20$$9;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *currentColumn = NULL, *sql = NULL, *sqlAlterTable = NULL, *defaultValue = NULL, *columnDefinition = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_6 = NULL, *_7 = NULL, *_10 = NULL, *_11 = NULL, *_17 = NULL, *_18 = NULL, *_3$$4 = NULL, *_4$$4 = NULL, *_5$$4, *_8$$5 = NULL, *_9$$5, *_12$$6 = NULL, *_13$$7 = NULL, *_14$$7, *_15$$8 = NULL, *_16$$8, *_19$$9 = NULL, *_21$$9 = NULL, *_24$$9 = NULL, *_22$$10 = NULL, *_23$$10, *_25$$11, *_26$$12 = NULL, *_27$$12, *_28$$13 = NULL, *_29$$13;
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
		ZEPHIR_CPY_WRT(currentColumn, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(currentColumn);
	}


	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "", 1);
	ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(sqlAlterTable);
	ZEPHIR_CONCAT_SV(sqlAlterTable, "ALTER TABLE ", _0);
	if (Z_TYPE_P(currentColumn) != IS_OBJECT) {
		ZEPHIR_CPY_WRT(currentColumn, column);
	}
	ZEPHIR_CALL_METHOD(&_1, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, currentColumn, "getname", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(_1, _2)) {
		ZEPHIR_CALL_METHOD(&_3$$4, currentColumn, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5$$4);
		ZEPHIR_CONCAT_VSVSVS(_5$$4, sqlAlterTable, " RENAME COLUMN \"", _3$$4, "\" TO \"", _4$$4, "\";");
		zephir_concat_self(&sql, _5$$4 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_6, column, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, currentColumn, "gettype", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(_6, _7)) {
		ZEPHIR_CALL_METHOD(&_8$$5, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_9$$5);
		ZEPHIR_CONCAT_VSVSVS(_9$$5, sqlAlterTable, " ALTER COLUMN \"", _8$$5, "\" TYPE ", columnDefinition, ";");
		zephir_concat_self(&sql, _9$$5 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_10, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_11, currentColumn, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(_10, _11)) {
		ZEPHIR_CALL_METHOD(&_12$$6, column, "isnotnull", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_12$$6)) {
			ZEPHIR_CALL_METHOD(&_13$$7, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_14$$7);
			ZEPHIR_CONCAT_VSVS(_14$$7, sqlAlterTable, " ALTER COLUMN \"", _13$$7, "\" SET NOT NULL;");
			zephir_concat_self(&sql, _14$$7 TSRMLS_CC);
		} else {
			ZEPHIR_CALL_METHOD(&_15$$8, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_16$$8);
			ZEPHIR_CONCAT_VSVS(_16$$8, sqlAlterTable, " ALTER COLUMN \"", _15$$8, "\" DROP NOT NULL;");
			zephir_concat_self(&sql, _16$$8 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_17, column, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_18, currentColumn, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(_17, _18)) {
		ZEPHIR_CALL_METHOD(&_19$$9, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		_20$$9 = ZEPHIR_IS_EMPTY(_19$$9);
		if (_20$$9) {
			ZEPHIR_CALL_METHOD(&_21$$9, currentColumn, "getdefault", NULL, 0);
			zephir_check_call_status();
			_20$$9 = !(ZEPHIR_IS_EMPTY(_21$$9));
		}
		if (_20$$9) {
			ZEPHIR_CALL_METHOD(&_22$$10, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_23$$10);
			ZEPHIR_CONCAT_VSVS(_23$$10, sqlAlterTable, " ALTER COLUMN \"", _22$$10, "\" DROP DEFAULT;");
			zephir_concat_self(&sql, _23$$10 TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_24$$9, column, "hasdefault", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_24$$9)) {
			ZEPHIR_CALL_METHOD(&defaultValue, this_ptr, "_castdefault", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_25$$11);
			zephir_fast_strtoupper(_25$$11, columnDefinition);
			if (zephir_memnstr_str(_25$$11, SL("BOOLEAN"), "phalcon/db/dialect/postgresql.zep", 237)) {
				ZEPHIR_CALL_METHOD(&_26$$12, column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_27$$12);
				ZEPHIR_CONCAT_SVSV(_27$$12, " ALTER COLUMN \"", _26$$12, "\" SET DEFAULT ", defaultValue);
				zephir_concat_self(&sql, _27$$12 TSRMLS_CC);
			} else {
				ZEPHIR_CALL_METHOD(&_28$$13, column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_29$$13);
				ZEPHIR_CONCAT_VSVSV(_29$$13, sqlAlterTable, " ALTER COLUMN \"", _28$$13, "\" SET DEFAULT ", defaultValue);
				zephir_concat_self(&sql, _29$$13 TSRMLS_CC);
			}
		}
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete a column from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropColumn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL, *_0 = NULL;
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", _0, " DROP COLUMN \"", columnName, "\"");
	RETURN_MM();

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addIndex) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *sql = NULL, *indexType = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_6 = NULL, *_7, *_1$$4;
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
		ZEPHIR_INIT_VAR(_1$$4);
		ZEPHIR_CONCAT_SV(_1$$4, " ", indexType);
		zephir_concat_self(&sql, _1$$4 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_2, index, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVSV(_4, " INDEX \"", _2, "\" ON ", _3);
	zephir_concat_self(&sql, _4 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_6, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumnlist", NULL, 57, _6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SVS(_7, " (", _5, ")");
	zephir_concat_self(&sql, _7 TSRMLS_CC);
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


	ZEPHIR_CONCAT_SVS(return_value, "DROP INDEX \"", indexName, "\"");
	RETURN_MM();

}

/**
 * Generates SQL to add the primary key to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addPrimaryKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *_0 = NULL, *_1 = NULL, *_2 = NULL;
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcolumnlist", NULL, 57, _2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", _0, " ADD CONSTRAINT \"PRIMARY\" PRIMARY KEY (", _1, ")");
	RETURN_MM();

}

/**
 * Generates SQL to delete primary key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *_0 = NULL;
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "ALTER TABLE ", _0, " DROP CONSTRAINT \"PRIMARY\"");
	RETURN_MM();

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addForeignKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, *sql = NULL, *onDelete = NULL, *onUpdate = NULL, *_0 = NULL, *_1 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9, *_2$$3 = NULL, *_3$$3, *_10$$4, *_11$$5;
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVS(sql, "ALTER TABLE ", _0, " ADD");
	ZEPHIR_CALL_METHOD(&_1, reference, "getname", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_CALL_METHOD(&_2$$3, reference, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SVS(_3$$3, " CONSTRAINT \"", _2$$3, "\"");
		zephir_concat_self(&sql, _3$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_5, reference, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getcolumnlist", NULL, 57, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, reference, "getreferencedtable", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, reference, "getreferencedcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getcolumnlist", NULL, 57, _8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_CONCAT_SVSSVSVS(_9, " FOREIGN KEY (", _4, ")", " REFERENCES \"", _6, "\" (", _7, ")");
	zephir_concat_self(&sql, _9 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&onDelete, reference, "getondelete", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(onDelete))) {
		ZEPHIR_INIT_VAR(_10$$4);
		ZEPHIR_CONCAT_SV(_10$$4, " ON DELETE ", onDelete);
		zephir_concat_self(&sql, _10$$4 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&onUpdate, reference, "getonupdate", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(onUpdate))) {
		ZEPHIR_INIT_VAR(_11$$5);
		ZEPHIR_CONCAT_SV(_11$$5, " ON UPDATE ", onUpdate);
		zephir_concat_self(&sql, _11$$5 TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropForeignKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName_param = NULL, *_0 = NULL;
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", _0, " DROP CONSTRAINT \"", referenceName, "\"");
	RETURN_MM();

}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createTable) {

	HashTable *_1, *_15$$13, *_28$$20;
	HashPosition _0, _14$$13, _27$$20;
	zephir_fcall_cache_entry *_3 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *definition = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, *temporary = NULL, *options = NULL, *table = NULL, *createLines = NULL, *columns = NULL, *column = NULL, *indexes = NULL, *index = NULL, *reference = NULL, *references = NULL, *indexName = NULL, *indexSql = NULL, *indexSqlAfterCreate = NULL, *sql = NULL, *columnLine = NULL, *indexType = NULL, *referenceSql = NULL, *onDelete = NULL, *onUpdate = NULL, *primaryColumns = NULL, *columnDefinition = NULL, **_2, *_40, *_41, *_44, *_4$$7 = NULL, *_5$$7 = NULL, *_9$$7 = NULL, *_10$$7 = NULL, *_6$$8 = NULL, *_8$$8 = NULL, *_11$$11 = NULL, *_12$$12 = NULL, *_13$$12, **_16$$13, *_17$$15 = NULL, *_18$$15 = NULL, *_19$$17 = NULL, *_20$$17 = NULL, *_21$$18 = NULL, *_22$$18 = NULL, *_23$$18 = NULL, *_24$$18 = NULL, *_25$$18 = NULL, *_26$$18 = NULL, **_29$$20, *_30$$21 = NULL, *_31$$21 = NULL, *_32$$21 = NULL, *_33$$21 = NULL, *_34$$21 = NULL, *_35$$21 = NULL, *_36$$21 = NULL, *_37$$21 = NULL, *_38$$22 = NULL, *_39$$23 = NULL, *_42$$24 = NULL, *_43$$24;
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


	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, definition, SS("columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array", "phalcon/db/dialect/postgresql.zep", 350);
		return;
	}
	ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
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
	zephir_is_iterable(columns, &_1, &_0, 0, 0, "phalcon/db/dialect/postgresql.zep", 401);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(column, _2);
		ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", &_3, 0, column);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$7, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(columnLine);
		ZEPHIR_CONCAT_SVSV(columnLine, "\"", _4$$7, "\" ", columnDefinition);
		ZEPHIR_CALL_METHOD(&_5$$7, column, "hasdefault", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_5$$7)) {
			ZEPHIR_CALL_METHOD(&_6$$8, this_ptr, "_castdefault", &_7, 0, column);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_8$$8);
			ZEPHIR_CONCAT_SV(_8$$8, " DEFAULT ", _6$$8);
			zephir_concat_self(&columnLine, _8$$8 TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_9$$7, column, "isnotnull", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_9$$7)) {
			zephir_concat_self_str(&columnLine, SL(" NOT NULL") TSRMLS_CC);
		} else {
			zephir_concat_self_str(&columnLine, SL(" NULL") TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_10$$7, column, "isprimary", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_10$$7)) {
			ZEPHIR_CALL_METHOD(&_11$$11, column, "getname", NULL, 0);
			zephir_check_call_status();
			zephir_array_append(&primaryColumns, _11$$11, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 396);
		}
		zephir_array_append(&createLines, columnLine, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 399);
	}
	if (!(ZEPHIR_IS_EMPTY(primaryColumns))) {
		ZEPHIR_CALL_METHOD(&_12$$12, this_ptr, "getcolumnlist", NULL, 57, primaryColumns);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_13$$12);
		ZEPHIR_CONCAT_SVS(_13$$12, "PRIMARY KEY (", _12$$12, ")");
		zephir_array_append(&createLines, _13$$12, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 402);
	}
	ZEPHIR_INIT_VAR(indexSqlAfterCreate);
	ZVAL_STRING(indexSqlAfterCreate, "", 1);
	ZEPHIR_OBS_VAR(indexes);
	if (zephir_array_isset_string_fetch(&indexes, definition, SS("indexes"), 0 TSRMLS_CC)) {
		zephir_is_iterable(indexes, &_15$$13, &_14$$13, 0, 0, "phalcon/db/dialect/postgresql.zep", 436);
		for (
		  ; zend_hash_get_current_data_ex(_15$$13, (void**) &_16$$13, &_14$$13) == SUCCESS
		  ; zend_hash_move_forward_ex(_15$$13, &_14$$13)
		) {
			ZEPHIR_GET_HVALUE(index, _16$$13);
			ZEPHIR_CALL_METHOD(&indexName, index, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&indexType, index, "gettype", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(indexSql);
			ZVAL_STRING(indexSql, "", 1);
			if (ZEPHIR_IS_STRING(indexName, "PRIMARY")) {
				ZEPHIR_CALL_METHOD(&_18$$15, index, "getcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_17$$15, this_ptr, "getcolumnlist", NULL, 57, _18$$15);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(indexSql);
				ZEPHIR_CONCAT_SVS(indexSql, "CONSTRAINT \"PRIMARY\" PRIMARY KEY (", _17$$15, ")");
			} else {
				if (!(ZEPHIR_IS_EMPTY(indexType))) {
					ZEPHIR_CALL_METHOD(&_20$$17, index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_19$$17, this_ptr, "getcolumnlist", NULL, 57, _20$$17);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(indexSql);
					ZEPHIR_CONCAT_SVSVSVS(indexSql, "CONSTRAINT \"", indexName, "\" ", indexType, " (", _19$$17, ")");
				} else {
					ZEPHIR_CALL_METHOD(&_21$$18, index, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_22$$18, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_23$$18);
					ZEPHIR_CONCAT_SVSV(_23$$18, "CREATE INDEX \"", _21$$18, "\" ON ", _22$$18);
					zephir_concat_self(&indexSqlAfterCreate, _23$$18 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_25$$18, index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_24$$18, this_ptr, "getcolumnlist", NULL, 57, _25$$18);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_26$$18);
					ZEPHIR_CONCAT_SVS(_26$$18, " (", _24$$18, ");");
					zephir_concat_self(&indexSqlAfterCreate, _26$$18 TSRMLS_CC);
				}
			}
			if (!(ZEPHIR_IS_EMPTY(indexSql))) {
				zephir_array_append(&createLines, indexSql, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 433);
			}
		}
	}
	ZEPHIR_OBS_VAR(references);
	if (zephir_array_isset_string_fetch(&references, definition, SS("references"), 0 TSRMLS_CC)) {
		zephir_is_iterable(references, &_28$$20, &_27$$20, 0, 0, "phalcon/db/dialect/postgresql.zep", 461);
		for (
		  ; zend_hash_get_current_data_ex(_28$$20, (void**) &_29$$20, &_27$$20) == SUCCESS
		  ; zend_hash_move_forward_ex(_28$$20, &_27$$20)
		) {
			ZEPHIR_GET_HVALUE(reference, _29$$20);
			ZEPHIR_CALL_METHOD(&_30$$21, reference, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_32$$21, reference, "getcolumns", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_31$$21, this_ptr, "getcolumnlist", NULL, 57, _32$$21);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(referenceSql);
			ZEPHIR_CONCAT_SVSVS(referenceSql, "CONSTRAINT \"", _30$$21, "\" FOREIGN KEY (", _31$$21, ") REFERENCES ");
			ZEPHIR_CALL_METHOD(&_34$$21, reference, "getreferencedtable", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_33$$21, this_ptr, "preparetable", NULL, 0, _34$$21, schemaName);
			zephir_check_call_status();
			zephir_concat_self(&referenceSql, _33$$21 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_36$$21, reference, "getreferencedcolumns", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_35$$21, this_ptr, "getcolumnlist", NULL, 57, _36$$21);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_37$$21);
			ZEPHIR_CONCAT_SVS(_37$$21, " (", _35$$21, ")");
			zephir_concat_self(&referenceSql, _37$$21 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&onDelete, reference, "getondelete", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(onDelete))) {
				ZEPHIR_INIT_LNVAR(_38$$22);
				ZEPHIR_CONCAT_SV(_38$$22, " ON DELETE ", onDelete);
				zephir_concat_self(&referenceSql, _38$$22 TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&onUpdate, reference, "getonupdate", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(onUpdate))) {
				ZEPHIR_INIT_LNVAR(_39$$23);
				ZEPHIR_CONCAT_SV(_39$$23, " ON UPDATE ", onUpdate);
				zephir_concat_self(&referenceSql, _39$$23 TSRMLS_CC);
			}
			zephir_array_append(&createLines, referenceSql, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 459);
		}
	}
	ZEPHIR_INIT_VAR(_40);
	zephir_fast_join_str(_40, SL(",\n\t"), createLines TSRMLS_CC);
	ZEPHIR_INIT_VAR(_41);
	ZEPHIR_CONCAT_VS(_41, _40, "\n)");
	zephir_concat_self(&sql, _41 TSRMLS_CC);
	if (zephir_array_isset_string(definition, SS("options"))) {
		ZEPHIR_CALL_METHOD(&_42$$24, this_ptr, "_gettableoptions", NULL, 0, definition);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_43$$24);
		ZEPHIR_CONCAT_SV(_43$$24, " ", _42$$24);
		zephir_concat_self(&sql, _43$$24 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_44);
	ZEPHIR_CONCAT_SV(_44, ";", indexSqlAfterCreate);
	zephir_concat_self(&sql, _44 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to truncate a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, truncateTable) {

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
		ZEPHIR_CONCAT_VSV(_0$$3, schemaName, ".", tableName);
		ZEPHIR_CPY_WRT(table, _0$$3);
	} else {
		ZEPHIR_CPY_WRT(table, tableName);
	}
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SV(sql, "TRUNCATE TABLE ", table);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to drop a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropTable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *table = NULL, *sql = NULL;
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createView) {

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array", "phalcon/db/dialect/postgresql.zep", 516);
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *view = NULL, *sql = NULL;
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
 *
 * echo $dialect->tableExists("posts");
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableExists) {

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


	if (!(!schemaName) && Z_STRLEN_P(schemaName)) {
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


	if (!(!schemaName) && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='", viewName, "' AND schemaname='", schemaName, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='", viewName, "' AND schemaname='public'");
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeColumns) {

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


	if (!(!schema) && Z_STRLEN_P(schema)) {
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
 * print_r(
 *     $dialect->listTables("blog")
 * );
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


	if (!(!schemaName) && Z_STRLEN_P(schemaName)) {
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


	ZEPHIR_CONCAT_SVS(return_value, "SELECT 0 as c0, t.relname as table_name, i.relname as key_name, 3 as c3, a.attname as column_name FROM pg_class t, pg_class i, pg_index ix, pg_attribute a WHERE t.oid = ix.indrelid AND i.oid = ix.indexrelid AND a.attrelid = t.oid AND a.attnum = ANY(ix.indkey) AND t.relkind = 'r' AND t.relname = '", table, "' ORDER BY t.relname, i.relname;");
	RETURN_MM();

}

/**
 * Generates SQL to query foreign keys on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeReferences) {

	zval *table_param = NULL, *schema_param = NULL, *sql = NULL;
	zval *table = NULL, *schema = NULL, *_0$$3, *_1$$4;

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


	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT DISTINCT tc.table_name as TABLE_NAME, kcu.column_name as COLUMN_NAME, tc.constraint_name as CONSTRAINT_NAME, tc.table_catalog as REFERENCED_TABLE_SCHEMA, ccu.table_name AS REFERENCED_TABLE_NAME, ccu.column_name AS REFERENCED_COLUMN_NAME FROM information_schema.table_constraints AS tc JOIN information_schema.key_column_usage AS kcu ON tc.constraint_name = kcu.constraint_name JOIN information_schema.constraint_column_usage AS ccu ON ccu.constraint_name = tc.constraint_name WHERE constraint_type = 'FOREIGN KEY' AND ", 1);
	if (!(!schema) && Z_STRLEN_P(schema)) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_CONCAT_SVSVS(_0$$3, "tc.table_schema = '", schema, "' AND tc.table_name='", table, "'");
		zephir_concat_self(&sql, _0$$3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_1$$4);
		ZEPHIR_CONCAT_SVS(_1$$4, "tc.table_schema = 'public' AND tc.table_name='", table, "'");
		zephir_concat_self(&sql, _1$$4 TSRMLS_CC);
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

PHP_METHOD(Phalcon_Db_Dialect_Postgresql, _castDefault) {

	zval *_6$$5 = NULL;
	zend_bool _2, _3, _4, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, *defaultValue = NULL, *preparedValue = NULL, *columnDefinition = NULL, *columnType = NULL, *_0, *_1, _7$$6, *_8$$6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnType, column, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_fast_strtoupper(_0, columnDefinition);
	if (zephir_memnstr_str(_0, SL("BOOLEAN"), "phalcon/db/dialect/postgresql.zep", 656)) {
		RETURN_CCTOR(defaultValue);
	}
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtoupper(_1, defaultValue);
	if (zephir_memnstr_str(_1, SL("CURRENT_TIMESTAMP"), "phalcon/db/dialect/postgresql.zep", 660)) {
		RETURN_MM_STRING("CURRENT_TIMESTAMP", 1);
	}
	_2 = ZEPHIR_IS_LONG_IDENTICAL(columnType, 0);
	if (!(_2)) {
		_2 = ZEPHIR_IS_LONG_IDENTICAL(columnType, 14);
	}
	_3 = _2;
	if (!(_3)) {
		_3 = ZEPHIR_IS_LONG_IDENTICAL(columnType, 3);
	}
	_4 = _3;
	if (!(_4)) {
		_4 = ZEPHIR_IS_LONG_IDENTICAL(columnType, 7);
	}
	_5 = _4;
	if (!(_5)) {
		_5 = ZEPHIR_IS_LONG_IDENTICAL(columnType, 9);
	}
	ZEPHIR_INIT_VAR(preparedValue);
	if (_5) {
		zephir_get_strval(_6$$5, defaultValue);
		ZEPHIR_CPY_WRT(preparedValue, _6$$5);
	} else {
		ZEPHIR_SINIT_VAR(_7$$6);
		ZVAL_STRING(&_7$$6, "\\'", 0);
		ZEPHIR_CALL_FUNCTION(&_8$$6, "addcslashes", NULL, 169, defaultValue, &_7$$6);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(preparedValue, "'", _8$$6, "'");
	}
	RETURN_CCTOR(preparedValue);

}

PHP_METHOD(Phalcon_Db_Dialect_Postgresql, _getTableOptions) {

	zval *definition_param = NULL;
	zval *definition = NULL;

	zephir_fetch_params(0, 1, 0, &definition_param);

	definition = definition_param;


	RETURN_STRING("", 1);

}

/**
 * Returns a SQL modified a shared lock statement. For now this method
 * returns the original query
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, sharedLock) {

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

