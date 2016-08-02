
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

	HashTable *_10$$37;
	HashPosition _9$$37;
	zephir_fcall_cache_entry *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
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
				  ; zephir_hash_get_current_data_ex(_10$$37, (void**) &_11$$37, &_9$$37) == SUCCESS
				  ; zephir_hash_move_forward_ex(_10$$37, &_9$$37)
				) {
					ZEPHIR_GET_HVALUE(value$$37, _11$$37);
					ZEPHIR_SINIT_NVAR(_12$$38);
					ZVAL_STRING(&_12$$38, "\"", 0);
					ZEPHIR_CALL_FUNCTION(&_13$$38, "addcslashes", &_14, 151, value$$37, &_12$$38);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_15$$38);
					ZEPHIR_CONCAT_SVS(_15$$38, "\"", _13$$38, "\", ");
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
				ZVAL_STRING(&_20$$39, "\"", 0);
				ZEPHIR_CALL_FUNCTION(&_21$$39, "addcslashes", &_14, 151, typeValues, &_20$$39);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_22$$39);
				ZEPHIR_CONCAT_SVS(_22$$39, "(\"", _21$$39, "\")");
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *sql = NULL, *defaultValue = NULL, *columnDefinition = NULL, *_0 = NULL, *_1 = NULL, *_2, *_3 = NULL, *_11 = NULL, *_4$$3, *_5$$3, *_6$$4 = NULL, *_7$$4, _8$$6, *_9$$6 = NULL, *_10$$6;
	zval *tableName = NULL, *schemaName = NULL;

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
		ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4$$3);
		zephir_fast_strtoupper(_4$$3, columnDefinition);
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_fast_strtoupper(_5$$3, defaultValue);
		if (zephir_memnstr_str(_4$$3, SL("BOOLEAN"), "phalcon/db/dialect/postgresql.zep", 185)) {
			ZEPHIR_INIT_VAR(_6$$4);
			if (zephir_is_true(defaultValue)) {
				ZEPHIR_INIT_NVAR(_6$$4);
				ZVAL_STRING(_6$$4, "true", 1);
			} else {
				ZEPHIR_INIT_NVAR(_6$$4);
				ZVAL_STRING(_6$$4, "false", 1);
			}
			ZEPHIR_INIT_VAR(_7$$4);
			ZEPHIR_CONCAT_SV(_7$$4, " DEFAULT ", _6$$4);
			zephir_concat_self(&sql, _7$$4 TSRMLS_CC);
		} else if (zephir_memnstr_str(_5$$3, SL("CURRENT_TIMESTAMP"), "phalcon/db/dialect/postgresql.zep", 187)) {
			zephir_concat_self_str(&sql, SL(" DEFAULT CURRENT_TIMESTAMP") TSRMLS_CC);
		} else {
			ZEPHIR_SINIT_VAR(_8$$6);
			ZVAL_STRING(&_8$$6, "\"", 0);
			ZEPHIR_CALL_FUNCTION(&_9$$6, "addcslashes", NULL, 151, defaultValue, &_8$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_10$$6);
			ZEPHIR_CONCAT_SVS(_10$$6, " DEFAULT \"", _9$$6, "\"");
			zephir_concat_self(&sql, _10$$6 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_11, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_11)) {
		zephir_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to modify a column in a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, modifyColumn) {

	zend_bool _21$$8;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *currentColumn = NULL, *sql = NULL, *sqlAlterTable = NULL, *defaultValue = NULL, *columnDefinition = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_7 = NULL, *_8 = NULL, *_11 = NULL, *_12 = NULL, *_18 = NULL, *_19 = NULL, *_4$$3 = NULL, *_5$$3 = NULL, *_6$$3, *_9$$4 = NULL, *_10$$4, *_13$$5 = NULL, *_14$$6 = NULL, *_15$$6, *_16$$7 = NULL, *_17$$7, *_20$$8 = NULL, *_22$$8 = NULL, *_25$$8 = NULL, *_23$$9 = NULL, *_24$$9, *_26$$10, *_27$$10, *_28$$11 = NULL, *_29$$11 = NULL, *_30$$11, *_31$$12 = NULL, *_32$$12, *_33$$13 = NULL, _34$$13, *_35$$13 = NULL, *_36$$13;
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
	ZEPHIR_INIT_VAR(_1);
	if (Z_TYPE_P(currentColumn) == IS_NULL) {
		ZEPHIR_CPY_WRT(_1, column);
	} else {
		ZEPHIR_CPY_WRT(_1, currentColumn);
	}
	ZEPHIR_CPY_WRT(currentColumn, _1);
	ZEPHIR_CALL_METHOD(&_2, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, currentColumn, "getname", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_2, _3)) {
		ZEPHIR_CALL_METHOD(&_4$$3, currentColumn, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6$$3);
		ZEPHIR_CONCAT_VSVSVS(_6$$3, sqlAlterTable, " RENAME COLUMN \"", _4$$3, "\" TO \"", _5$$3, "\";");
		zephir_concat_self(&sql, _6$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_7, column, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, currentColumn, "gettype", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_7, _8)) {
		ZEPHIR_CALL_METHOD(&_9$$4, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_10$$4);
		ZEPHIR_CONCAT_VSVSVS(_10$$4, sqlAlterTable, " ALTER COLUMN \"", _9$$4, "\" TYPE ", columnDefinition, ";");
		zephir_concat_self(&sql, _10$$4 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_11, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, currentColumn, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_11, _12)) {
		ZEPHIR_CALL_METHOD(&_13$$5, column, "isnotnull", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_13$$5)) {
			ZEPHIR_CALL_METHOD(&_14$$6, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_15$$6);
			ZEPHIR_CONCAT_VSVS(_15$$6, sqlAlterTable, " ALTER COLUMN \"", _14$$6, "\" SET NOT NULL;");
			zephir_concat_self(&sql, _15$$6 TSRMLS_CC);
		} else {
			ZEPHIR_CALL_METHOD(&_16$$7, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_17$$7);
			ZEPHIR_CONCAT_VSVS(_17$$7, sqlAlterTable, " ALTER COLUMN \"", _16$$7, "\" DROP NOT NULL;");
			zephir_concat_self(&sql, _17$$7 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_18, column, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_19, currentColumn, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_EQUAL(_18, _19)) {
		ZEPHIR_CALL_METHOD(&_20$$8, column, "hasdefault", NULL, 0);
		zephir_check_call_status();
		_21$$8 = !zephir_is_true(_20$$8);
		if (_21$$8) {
			ZEPHIR_CALL_METHOD(&_22$$8, currentColumn, "getdefault", NULL, 0);
			zephir_check_call_status();
			_21$$8 = !(ZEPHIR_IS_EMPTY(_22$$8));
		}
		if (_21$$8) {
			ZEPHIR_CALL_METHOD(&_23$$9, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_24$$9);
			ZEPHIR_CONCAT_VSVS(_24$$9, sqlAlterTable, " ALTER COLUMN \"", _23$$9, "\" DROP DEFAULT;");
			zephir_concat_self(&sql, _24$$9 TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_25$$8, column, "hasdefault", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_25$$8)) {
			ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_26$$10);
			zephir_fast_strtoupper(_26$$10, columnDefinition);
			ZEPHIR_INIT_VAR(_27$$10);
			zephir_fast_strtoupper(_27$$10, defaultValue);
			if (zephir_memnstr_str(_26$$10, SL("BOOLEAN"), "phalcon/db/dialect/postgresql.zep", 239)) {
				ZEPHIR_CALL_METHOD(&_28$$11, column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_29$$11);
				if (zephir_is_true(defaultValue)) {
					ZEPHIR_INIT_NVAR(_29$$11);
					ZVAL_STRING(_29$$11, "true", 1);
				} else {
					ZEPHIR_INIT_NVAR(_29$$11);
					ZVAL_STRING(_29$$11, "false", 1);
				}
				ZEPHIR_INIT_VAR(_30$$11);
				ZEPHIR_CONCAT_SVSV(_30$$11, " ALTER COLUMN \"", _28$$11, "\" SET DEFAULT ", _29$$11);
				zephir_concat_self(&sql, _30$$11 TSRMLS_CC);
			} else if (zephir_memnstr_str(_27$$10, SL("CURRENT_TIMESTAMP"), "phalcon/db/dialect/postgresql.zep", 241)) {
				ZEPHIR_CALL_METHOD(&_31$$12, column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_32$$12);
				ZEPHIR_CONCAT_VSVS(_32$$12, sqlAlterTable, " ALTER COLUMN \"", _31$$12, "\" SET DEFAULT CURRENT_TIMESTAMP");
				zephir_concat_self(&sql, _32$$12 TSRMLS_CC);
			} else {
				ZEPHIR_CALL_METHOD(&_33$$13, column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_SINIT_VAR(_34$$13);
				ZVAL_STRING(&_34$$13, "\"", 0);
				ZEPHIR_CALL_FUNCTION(&_35$$13, "addcslashes", NULL, 151, defaultValue, &_34$$13);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_36$$13);
				ZEPHIR_CONCAT_VSVSVS(_36$$13, sqlAlterTable, " ALTER COLUMN \"", _33$$13, "\" SET DEFAULT \"", _35$$13, "\"");
				zephir_concat_self(&sql, _36$$13 TSRMLS_CC);
			}
		}
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete a column from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropColumn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL, *_0 = NULL;
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", _0, " DROP COLUMN \"", columnName, "\"");
	RETURN_MM();

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addIndex) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *sql = NULL, *indexType = NULL, *_0 = NULL, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_6 = NULL, *_7, *_1$$4;
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
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumnlist", NULL, 54, _6);
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
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *_0 = NULL, *_1 = NULL, *_2 = NULL;
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcolumnlist", NULL, 54, _2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", _0, " ADD CONSTRAINT \"PRIMARY\" PRIMARY KEY (", _1, ")");
	RETURN_MM();

}

/**
 * Generates SQL to delete primary key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *_0 = NULL;
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "ALTER TABLE ", _0, " DROP CONSTRAINT \"PRIMARY\"");
	RETURN_MM();

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addForeignKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, *sql = NULL, *onDelete = NULL, *onUpdate = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7$$3, *_8$$4;
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, reference, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, reference, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcolumnlist", NULL, 54, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, reference, "getreferencedtable", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, reference, "getreferencedcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumnlist", NULL, 54, _6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(sql);
	ZEPHIR_CONCAT_SVSVSVSSVSVS(sql, "ALTER TABLE ", _0, " ADD CONSTRAINT \"", _1, "\" FOREIGN KEY (", _2, ")", " REFERENCES \"", _4, "\" (", _5, ")");
	ZEPHIR_CALL_METHOD(&onDelete, reference, "getondelete", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(onDelete))) {
		ZEPHIR_INIT_VAR(_7$$3);
		ZEPHIR_CONCAT_SV(_7$$3, " ON DELETE ", onDelete);
		zephir_concat_self(&sql, _7$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&onUpdate, reference, "getonupdate", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(onUpdate))) {
		ZEPHIR_INIT_VAR(_8$$4);
		ZEPHIR_CONCAT_SV(_8$$4, " ON UPDATE ", onUpdate);
		zephir_concat_self(&sql, _8$$4 TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropForeignKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName_param = NULL, *_0 = NULL;
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", _0, " DROP CONSTRAINT \"", referenceName, "\"");
	RETURN_MM();

}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createTable) {

	HashTable *_1, *_20$$15, *_33$$22;
	HashPosition _0, _19$$15, _32$$22;
	zephir_fcall_cache_entry *_3 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *definition = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, *temporary = NULL, *options = NULL, *table = NULL, *createLines = NULL, *columns = NULL, *column = NULL, *indexes = NULL, *index = NULL, *reference = NULL, *references = NULL, *indexName = NULL, *indexSql = NULL, *indexSqlAfterCreate = NULL, *sql = NULL, *columnLine = NULL, *indexType = NULL, *referenceSql = NULL, *onDelete = NULL, *onUpdate = NULL, *defaultValue = NULL, *primaryColumns = NULL, *columnDefinition = NULL, **_2, *_45, *_46, *_49, *_4$$7 = NULL, *_5$$7 = NULL, *_14$$7 = NULL, *_15$$7 = NULL, *_6$$8 = NULL, *_7$$8 = NULL, *_8$$9 = NULL, *_9$$9 = NULL, _10$$11 = zval_used_for_init, *_11$$11 = NULL, *_13$$11 = NULL, *_16$$13 = NULL, *_17$$14 = NULL, *_18$$14, **_21$$15, *_22$$17 = NULL, *_23$$17 = NULL, *_24$$19 = NULL, *_25$$19 = NULL, *_26$$20 = NULL, *_27$$20 = NULL, *_28$$20 = NULL, *_29$$20 = NULL, *_30$$20 = NULL, *_31$$20 = NULL, **_34$$22, *_35$$23 = NULL, *_36$$23 = NULL, *_37$$23 = NULL, *_38$$23 = NULL, *_39$$23 = NULL, *_40$$23 = NULL, *_41$$23 = NULL, *_42$$23 = NULL, *_43$$24 = NULL, *_44$$25 = NULL, *_47$$26 = NULL, *_48$$26;
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


	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, definition, SS("columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array", "phalcon/db/dialect/postgresql.zep", 351);
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
	zephir_is_iterable(columns, &_1, &_0, 0, 0, "phalcon/db/dialect/postgresql.zep", 407);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
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
			ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_6$$8);
			zephir_fast_strtoupper(_6$$8, columnDefinition);
			ZEPHIR_INIT_NVAR(_7$$8);
			zephir_fast_strtoupper(_7$$8, defaultValue);
			if (zephir_memnstr_str(_6$$8, SL("BOOLEAN"), "phalcon/db/dialect/postgresql.zep", 382)) {
				ZEPHIR_INIT_LNVAR(_8$$9);
				if (zephir_is_true(defaultValue)) {
					ZEPHIR_INIT_NVAR(_8$$9);
					ZVAL_STRING(_8$$9, "true", 1);
				} else {
					ZEPHIR_INIT_NVAR(_8$$9);
					ZVAL_STRING(_8$$9, "false", 1);
				}
				ZEPHIR_INIT_LNVAR(_9$$9);
				ZEPHIR_CONCAT_SV(_9$$9, " DEFAULT ", _8$$9);
				zephir_concat_self(&sql, _9$$9 TSRMLS_CC);
			} else if (zephir_memnstr_str(_7$$8, SL("CURRENT_TIMESTAMP"), "phalcon/db/dialect/postgresql.zep", 384)) {
				zephir_concat_self_str(&columnLine, SL(" DEFAULT CURRENT_TIMESTAMP") TSRMLS_CC);
			} else {
				ZEPHIR_SINIT_NVAR(_10$$11);
				ZVAL_STRING(&_10$$11, "\"", 0);
				ZEPHIR_CALL_FUNCTION(&_11$$11, "addcslashes", &_12, 151, defaultValue, &_10$$11);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_13$$11);
				ZEPHIR_CONCAT_SVS(_13$$11, " DEFAULT \"", _11$$11, "\"");
				zephir_concat_self(&columnLine, _13$$11 TSRMLS_CC);
			}
		}
		ZEPHIR_CALL_METHOD(&_14$$7, column, "isnotnull", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_14$$7)) {
			zephir_concat_self_str(&columnLine, SL(" NOT NULL") TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_15$$7, column, "isprimary", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_15$$7)) {
			ZEPHIR_CALL_METHOD(&_16$$13, column, "getname", NULL, 0);
			zephir_check_call_status();
			zephir_array_append(&primaryColumns, _16$$13, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 402);
		}
		zephir_array_append(&createLines, columnLine, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 405);
	}
	if (!(ZEPHIR_IS_EMPTY(primaryColumns))) {
		ZEPHIR_CALL_METHOD(&_17$$14, this_ptr, "getcolumnlist", NULL, 54, primaryColumns);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_18$$14);
		ZEPHIR_CONCAT_SVS(_18$$14, "PRIMARY KEY (", _17$$14, ")");
		zephir_array_append(&createLines, _18$$14, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 408);
	}
	ZEPHIR_INIT_VAR(indexSqlAfterCreate);
	ZVAL_STRING(indexSqlAfterCreate, "", 1);
	ZEPHIR_OBS_VAR(indexes);
	if (zephir_array_isset_string_fetch(&indexes, definition, SS("indexes"), 0 TSRMLS_CC)) {
		zephir_is_iterable(indexes, &_20$$15, &_19$$15, 0, 0, "phalcon/db/dialect/postgresql.zep", 442);
		for (
		  ; zephir_hash_get_current_data_ex(_20$$15, (void**) &_21$$15, &_19$$15) == SUCCESS
		  ; zephir_hash_move_forward_ex(_20$$15, &_19$$15)
		) {
			ZEPHIR_GET_HVALUE(index, _21$$15);
			ZEPHIR_CALL_METHOD(&indexName, index, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&indexType, index, "gettype", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(indexSql);
			ZVAL_STRING(indexSql, "", 1);
			if (ZEPHIR_IS_STRING(indexName, "PRIMARY")) {
				ZEPHIR_CALL_METHOD(&_23$$17, index, "getcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_22$$17, this_ptr, "getcolumnlist", NULL, 54, _23$$17);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(indexSql);
				ZEPHIR_CONCAT_SVS(indexSql, "CONSTRAINT \"PRIMARY\" PRIMARY KEY (", _22$$17, ")");
			} else {
				if (!(ZEPHIR_IS_EMPTY(indexType))) {
					ZEPHIR_CALL_METHOD(&_25$$19, index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_24$$19, this_ptr, "getcolumnlist", NULL, 54, _25$$19);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(indexSql);
					ZEPHIR_CONCAT_SVSVSVS(indexSql, "CONSTRAINT \"", indexName, "\" ", indexType, " (", _24$$19, ")");
				} else {
					ZEPHIR_CALL_METHOD(&_26$$20, index, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_27$$20, this_ptr, "preparetable", NULL, 0, tableName, schemaName);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_28$$20);
					ZEPHIR_CONCAT_SVSV(_28$$20, "CREATE INDEX \"", _26$$20, "\" ON ", _27$$20);
					zephir_concat_self(&indexSqlAfterCreate, _28$$20 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_30$$20, index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_29$$20, this_ptr, "getcolumnlist", NULL, 54, _30$$20);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_31$$20);
					ZEPHIR_CONCAT_SVS(_31$$20, " (", _29$$20, ");");
					zephir_concat_self(&indexSqlAfterCreate, _31$$20 TSRMLS_CC);
				}
			}
			if (!(ZEPHIR_IS_EMPTY(indexSql))) {
				zephir_array_append(&createLines, indexSql, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 439);
			}
		}
	}
	ZEPHIR_OBS_VAR(references);
	if (zephir_array_isset_string_fetch(&references, definition, SS("references"), 0 TSRMLS_CC)) {
		zephir_is_iterable(references, &_33$$22, &_32$$22, 0, 0, "phalcon/db/dialect/postgresql.zep", 467);
		for (
		  ; zephir_hash_get_current_data_ex(_33$$22, (void**) &_34$$22, &_32$$22) == SUCCESS
		  ; zephir_hash_move_forward_ex(_33$$22, &_32$$22)
		) {
			ZEPHIR_GET_HVALUE(reference, _34$$22);
			ZEPHIR_CALL_METHOD(&_35$$23, reference, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_37$$23, reference, "getcolumns", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_36$$23, this_ptr, "getcolumnlist", NULL, 54, _37$$23);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(referenceSql);
			ZEPHIR_CONCAT_SVSVS(referenceSql, "CONSTRAINT \"", _35$$23, "\" FOREIGN KEY (", _36$$23, ") REFERENCES ");
			ZEPHIR_CALL_METHOD(&_39$$23, reference, "getreferencedtable", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_38$$23, this_ptr, "preparetable", NULL, 0, _39$$23, schemaName);
			zephir_check_call_status();
			zephir_concat_self(&referenceSql, _38$$23 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_41$$23, reference, "getreferencedcolumns", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_40$$23, this_ptr, "getcolumnlist", NULL, 54, _41$$23);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_42$$23);
			ZEPHIR_CONCAT_SVS(_42$$23, " (", _40$$23, ")");
			zephir_concat_self(&referenceSql, _42$$23 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&onDelete, reference, "getondelete", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(onDelete))) {
				ZEPHIR_INIT_LNVAR(_43$$24);
				ZEPHIR_CONCAT_SV(_43$$24, " ON DELETE ", onDelete);
				zephir_concat_self(&referenceSql, _43$$24 TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&onUpdate, reference, "getonupdate", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(onUpdate))) {
				ZEPHIR_INIT_LNVAR(_44$$25);
				ZEPHIR_CONCAT_SV(_44$$25, " ON UPDATE ", onUpdate);
				zephir_concat_self(&referenceSql, _44$$25 TSRMLS_CC);
			}
			zephir_array_append(&createLines, referenceSql, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 465);
		}
	}
	ZEPHIR_INIT_VAR(_45);
	zephir_fast_join_str(_45, SL(",\n\t"), createLines TSRMLS_CC);
	ZEPHIR_INIT_VAR(_46);
	ZEPHIR_CONCAT_VS(_46, _45, "\n)");
	zephir_concat_self(&sql, _46 TSRMLS_CC);
	if (zephir_array_isset_string(definition, SS("options"))) {
		ZEPHIR_CALL_METHOD(&_47$$26, this_ptr, "_gettableoptions", NULL, 0, definition);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_48$$26);
		ZEPHIR_CONCAT_SV(_48$$26, " ", _47$$26);
		zephir_concat_self(&sql, _48$$26 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_49);
	ZEPHIR_CONCAT_SV(_49, ";", indexSqlAfterCreate);
	zephir_concat_self(&sql, _49 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to drop a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropTable) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *table = NULL, *sql = NULL;
	zval *tableName = NULL, *schemaName = NULL;

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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *definition = NULL;
	zval *viewName_param = NULL, *definition_param = NULL, *schemaName_param = NULL, *viewSql = NULL, *_0 = NULL;
	zval *viewName = NULL, *schemaName = NULL;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array", "phalcon/db/dialect/postgresql.zep", 504);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *view = NULL, *sql = NULL;
	zval *viewName = NULL, *schemaName = NULL;

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


	if (!(!schemaName) && Z_STRLEN_P(schemaName)) {
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

	zval *table_param = NULL, *schema_param = NULL, *sql = NULL;
	zval *table = NULL, *schema = NULL, *_0$$3, *_1$$4;

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
	if (!(!schema) && Z_STRLEN_P(schema)) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_CONCAT_SVSVS(_0$$3, "tc.table_schema = '", schema, "' AND tc.table_name='", table, "'");
		zephir_concat_self(&sql, _0$$3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(_1$$4);
		ZEPHIR_CONCAT_SVS(_1$$4, "tc.table_name='", table, "'");
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

