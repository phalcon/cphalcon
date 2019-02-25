
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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

	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, columnType, columnSql, typeValues, _0$$4, _1$$9, _2$$15, _3$$20, _4$$31, _5$$34, _6$$34, _7$$34, value$$36, valueSql$$36, *_8$$36, _13$$36, _14$$36, _15$$36, _16$$36, _9$$37, _10$$37, _12$$37, _17$$38, _18$$38, _19$$38;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&columnSql);
	ZVAL_UNDEF(&typeValues);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$9);
	ZVAL_UNDEF(&_2$$15);
	ZVAL_UNDEF(&_3$$20);
	ZVAL_UNDEF(&_4$$31);
	ZVAL_UNDEF(&_5$$34);
	ZVAL_UNDEF(&_6$$34);
	ZVAL_UNDEF(&_7$$34);
	ZVAL_UNDEF(&value$$36);
	ZVAL_UNDEF(&valueSql$$36);
	ZVAL_UNDEF(&_13$$36);
	ZVAL_UNDEF(&_14$$36);
	ZVAL_UNDEF(&_15$$36);
	ZVAL_UNDEF(&_16$$36);
	ZVAL_UNDEF(&_9$$37);
	ZVAL_UNDEF(&_10$$37);
	ZVAL_UNDEF(&_12$$37);
	ZVAL_UNDEF(&_17$$38);
	ZVAL_UNDEF(&_18$$38);
	ZVAL_UNDEF(&_19$$38);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_CALL_METHOD(&columnSql, this_ptr, "checkcolumntypesql", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnType, this_ptr, "checkcolumntype", NULL, 0, column);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(&columnType, 14)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				ZEPHIR_CALL_METHOD(&_0$$4, column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_0$$4)) {
					zephir_concat_self_str(&columnSql, SL("BIGSERIAL") TSRMLS_CC);
				} else {
					zephir_concat_self_str(&columnSql, SL("BIGINT") TSRMLS_CC);
				}
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 8)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("BOOLEAN") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 5)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHARACTER") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_1$$9, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_1$$9 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 1)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DATE") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 4)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TIMESTAMP") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 3)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("NUMERIC") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_2$$15, this_ptr, "getcolumnsizeandscale", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_2$$15 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 7)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("FLOAT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 0)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				ZEPHIR_CALL_METHOD(&_3$$20, column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_3$$20)) {
					zephir_concat_self_str(&columnSql, SL("SERIAL") TSRMLS_CC);
				} else {
					zephir_concat_self_str(&columnSql, SL("INT") TSRMLS_CC);
				}
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 15)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("JSON") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 16)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("JSONB") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 17)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TIMESTAMP") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 6)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TEXT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 2)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHARACTER VARYING") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_4$$31, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_4$$31 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			ZEPHIR_INIT_VAR(&_5$$34);
			object_init_ex(&_5$$34, phalcon_db_exception_ce);
			ZEPHIR_CALL_METHOD(&_6$$34, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_7$$34);
			ZEPHIR_CONCAT_SV(&_7$$34, "Unrecognized PostgreSQL data type at column ", &_6$$34);
			ZEPHIR_CALL_METHOD(NULL, &_5$$34, "__construct", NULL, 4, &_7$$34);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$34, "phalcon/db/dialect/postgresql.zep", 135 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&typeValues, column, "gettypevalues", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&typeValues))) {
			if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(&valueSql$$36);
				ZVAL_STRING(&valueSql$$36, "");
				zephir_is_iterable(&typeValues, 0, "phalcon/db/dialect/postgresql.zep", 146);
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&typeValues), _8$$36)
				{
					ZEPHIR_INIT_NVAR(&value$$36);
					ZVAL_COPY(&value$$36, _8$$36);
					ZEPHIR_INIT_NVAR(&_9$$37);
					ZVAL_STRING(&_9$$37, "\\'");
					ZEPHIR_CALL_FUNCTION(&_10$$37, "addcslashes", &_11, 147, &value$$36, &_9$$37);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_12$$37);
					ZEPHIR_CONCAT_SVS(&_12$$37, "'", &_10$$37, "', ");
					zephir_concat_self(&valueSql$$36, &_12$$37 TSRMLS_CC);
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&value$$36);
				ZVAL_LONG(&_13$$36, 0);
				ZVAL_LONG(&_14$$36, -2);
				ZEPHIR_INIT_VAR(&_15$$36);
				zephir_substr(&_15$$36, &valueSql$$36, 0 , -2 , 0);
				ZEPHIR_INIT_VAR(&_16$$36);
				ZEPHIR_CONCAT_SVS(&_16$$36, "(", &_15$$36, ")");
				zephir_concat_self(&columnSql, &_16$$36 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(&_17$$38);
				ZVAL_STRING(&_17$$38, "\\'");
				ZEPHIR_CALL_FUNCTION(&_18$$38, "addcslashes", &_11, 147, &typeValues, &_17$$38);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_19$$38);
				ZEPHIR_CONCAT_SVS(&_19$$38, "('", &_18$$38, "')");
				zephir_concat_self(&columnSql, &_19$$38 TSRMLS_CC);
			}
		}
	} while(0);

	RETURN_CCTOR(&columnSql);

}

/**
 * Generates SQL to add a column to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addColumn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, sql, columnDefinition, _0, _1, _2, _3, _6, _4$$3, _5$$3;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &column);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVS(&sql, "ALTER TABLE ", &_0, " ADD COLUMN ");
	ZEPHIR_CALL_METHOD(&_1, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVSV(&_2, "\"", &_1, "\" ", &columnDefinition);
	zephir_concat_self(&sql, &_2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, column, "hasdefault", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "_castdefault", NULL, 0, column);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_SV(&_5$$3, " DEFAULT ", &_4$$3);
		zephir_concat_self(&sql, &_5$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_6, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_6)) {
		zephir_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	RETURN_CCTOR(&sql);

}

/**
 * Generates SQL to modify a column in a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, modifyColumn) {

	zend_bool _20$$9;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, sql, sqlAlterTable, defaultValue, columnDefinition, _0, _1, _2, _6, _7, _10, _11, _17, _18, _3$$4, _4$$4, _5$$4, _8$$5, _9$$5, _12$$6, _13$$7, _14$$7, _15$$8, _16$$8, _19$$9, _21$$9, _24$$9, _22$$10, _23$$10, _25$$11, _26$$12, _27$$12, _28$$13, _29$$13;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&currentColumn_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&sqlAlterTable);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$13);
	ZVAL_UNDEF(&_29$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &tableName_param, &schemaName_param, &column, &currentColumn);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (!currentColumn) {
		currentColumn = &currentColumn_sub;
		ZEPHIR_CPY_WRT(currentColumn, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(currentColumn);
	}


	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "");
	ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sqlAlterTable);
	ZEPHIR_CONCAT_SV(&sqlAlterTable, "ALTER TABLE ", &_0);
	if (Z_TYPE_P(currentColumn) != IS_OBJECT) {
		ZEPHIR_CPY_WRT(currentColumn, column);
	}
	ZEPHIR_CALL_METHOD(&_1, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, currentColumn, "getname", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_1, &_2)) {
		ZEPHIR_CALL_METHOD(&_3$$4, currentColumn, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_VSVSVS(&_5$$4, &sqlAlterTable, " RENAME COLUMN \"", &_3$$4, "\" TO \"", &_4$$4, "\";");
		zephir_concat_self(&sql, &_5$$4 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_6, column, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, currentColumn, "gettype", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_6, &_7)) {
		ZEPHIR_CALL_METHOD(&_8$$5, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$5);
		ZEPHIR_CONCAT_VSVSVS(&_9$$5, &sqlAlterTable, " ALTER COLUMN \"", &_8$$5, "\" TYPE ", &columnDefinition, ";");
		zephir_concat_self(&sql, &_9$$5 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_10, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_11, currentColumn, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_10, &_11)) {
		ZEPHIR_CALL_METHOD(&_12$$6, column, "isnotnull", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_12$$6)) {
			ZEPHIR_CALL_METHOD(&_13$$7, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_14$$7);
			ZEPHIR_CONCAT_VSVS(&_14$$7, &sqlAlterTable, " ALTER COLUMN \"", &_13$$7, "\" SET NOT NULL;");
			zephir_concat_self(&sql, &_14$$7 TSRMLS_CC);
		} else {
			ZEPHIR_CALL_METHOD(&_15$$8, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_16$$8);
			ZEPHIR_CONCAT_VSVS(&_16$$8, &sqlAlterTable, " ALTER COLUMN \"", &_15$$8, "\" DROP NOT NULL;");
			zephir_concat_self(&sql, &_16$$8 TSRMLS_CC);
		}
	}
	ZEPHIR_CALL_METHOD(&_17, column, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_18, currentColumn, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_17, &_18)) {
		ZEPHIR_CALL_METHOD(&_19$$9, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		_20$$9 = ZEPHIR_IS_EMPTY(&_19$$9);
		if (_20$$9) {
			ZEPHIR_CALL_METHOD(&_21$$9, currentColumn, "getdefault", NULL, 0);
			zephir_check_call_status();
			_20$$9 = !(ZEPHIR_IS_EMPTY(&_21$$9));
		}
		if (_20$$9) {
			ZEPHIR_CALL_METHOD(&_22$$10, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_23$$10);
			ZEPHIR_CONCAT_VSVS(&_23$$10, &sqlAlterTable, " ALTER COLUMN \"", &_22$$10, "\" DROP DEFAULT;");
			zephir_concat_self(&sql, &_23$$10 TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_24$$9, column, "hasdefault", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_24$$9)) {
			ZEPHIR_CALL_METHOD(&defaultValue, this_ptr, "_castdefault", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_25$$11);
			zephir_fast_strtoupper(&_25$$11, &columnDefinition);
			if (zephir_memnstr_str(&_25$$11, SL("BOOLEAN"), "phalcon/db/dialect/postgresql.zep", 220)) {
				ZEPHIR_CALL_METHOD(&_26$$12, column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_27$$12);
				ZEPHIR_CONCAT_SVSV(&_27$$12, " ALTER COLUMN \"", &_26$$12, "\" SET DEFAULT ", &defaultValue);
				zephir_concat_self(&sql, &_27$$12 TSRMLS_CC);
			} else {
				ZEPHIR_CALL_METHOD(&_28$$13, column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_29$$13);
				ZEPHIR_CONCAT_VSVSV(&_29$$13, &sqlAlterTable, " ALTER COLUMN \"", &_28$$13, "\" SET DEFAULT ", &defaultValue);
				zephir_concat_self(&sql, &_29$$13 TSRMLS_CC);
			}
		}
	}
	RETURN_CCTOR(&sql);

}

/**
 * Generates SQL to delete a column from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropColumn) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL, _0;
	zval tableName, schemaName, columnName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &columnName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(columnName_param) != IS_STRING && Z_TYPE_P(columnName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'columnName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(columnName_param) == IS_STRING)) {
		zephir_get_strval(&columnName, columnName_param);
	} else {
		ZEPHIR_INIT_VAR(&columnName);
		ZVAL_EMPTY_STRING(&columnName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP COLUMN \"", &columnName, "\"");
	RETURN_MM();

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addIndex) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, index_sub, sql, indexType, _0, _2, _3, _4, _5, _6, _7, _1$$4;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, index, "getname", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING_IDENTICAL(&_0, "PRIMARY")) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addprimarykey", NULL, 0, &tableName, &schemaName, index);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "CREATE");
	ZEPHIR_CALL_METHOD(&indexType, index, "gettype", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&indexType))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_SV(&_1$$4, " ", &indexType);
		zephir_concat_self(&sql, &_1$$4 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_2, index, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVSV(&_4, " INDEX \"", &_2, "\" ON ", &_3);
	zephir_concat_self(&sql, &_4 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_6, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumnlist", NULL, 40, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SVS(&_7, " (", &_5, ")");
	zephir_concat_self(&sql, &_7 TSRMLS_CC);
	RETURN_CCTOR(&sql);

}

/**
 * Generates SQL to delete an index from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropIndex) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName_param = NULL;
	zval tableName, schemaName, indexName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&indexName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &indexName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(indexName_param) != IS_STRING && Z_TYPE_P(indexName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'indexName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(indexName_param) == IS_STRING)) {
		zephir_get_strval(&indexName, indexName_param);
	} else {
		ZEPHIR_INIT_VAR(&indexName);
		ZVAL_EMPTY_STRING(&indexName);
	}


	ZEPHIR_CONCAT_SVS(return_value, "DROP INDEX \"", &indexName, "\"");
	RETURN_MM();

}

/**
 * Generates SQL to add the primary key to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addPrimaryKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, index_sub, _0, _1, _2;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcolumnlist", NULL, 40, &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVSVS(return_value, "ALTER TABLE ", &_0, " ADD CONSTRAINT \"", &tableName, "_PRIMARY\" PRIMARY KEY (", &_1, ")");
	RETURN_MM();

}

/**
 * Generates SQL to delete primary key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, _0;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP CONSTRAINT \"", &tableName, "_PRIMARY\"");
	RETURN_MM();

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addForeignKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, reference_sub, sql, onDelete, onUpdate, _0, _1, _4, _5, _6, _7, _8, _9, _2$$3, _3$$3, _10$$4, _11$$5;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&reference_sub);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&onDelete);
	ZVAL_UNDEF(&onUpdate);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &reference);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVS(&sql, "ALTER TABLE ", &_0, " ADD");
	ZEPHIR_CALL_METHOD(&_1, reference, "getname", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_METHOD(&_2$$3, reference, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, " CONSTRAINT \"", &_2$$3, "\"");
		zephir_concat_self(&sql, &_3$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_5, reference, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getcolumnlist", NULL, 40, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, reference, "getreferencedtable", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, reference, "getreferencedcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getcolumnlist", NULL, 40, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_SVSSVSVS(&_9, " FOREIGN KEY (", &_4, ")", " REFERENCES \"", &_6, "\" (", &_7, ")");
	zephir_concat_self(&sql, &_9 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&onDelete, reference, "getondelete", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
		ZEPHIR_INIT_VAR(&_10$$4);
		ZEPHIR_CONCAT_SV(&_10$$4, " ON DELETE ", &onDelete);
		zephir_concat_self(&sql, &_10$$4 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&onUpdate, reference, "getonupdate", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
		ZEPHIR_INIT_VAR(&_11$$5);
		ZEPHIR_CONCAT_SV(&_11$$5, " ON UPDATE ", &onUpdate);
		zephir_concat_self(&sql, &_11$$5 TSRMLS_CC);
	}
	RETURN_CCTOR(&sql);

}

/**
 * Generates SQL to delete a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropForeignKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName_param = NULL, _0;
	zval tableName, schemaName, referenceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&referenceName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &referenceName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(referenceName_param) != IS_STRING && Z_TYPE_P(referenceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceName_param) == IS_STRING)) {
		zephir_get_strval(&referenceName, referenceName_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceName);
		ZVAL_EMPTY_STRING(&referenceName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP CONSTRAINT \"", &referenceName, "\"");
	RETURN_MM();

}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createTable) {

	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, temporary, options, table, createLines, columns, column, indexes, index, reference, references, indexName, indexSql, indexSqlAfterCreate, sql, columnLine, indexType, referenceSql, onDelete, onUpdate, primaryColumns, columnDefinition, *_0, _34, _35, _38, _2$$7, _3$$7, _7$$7, _8$$7, _4$$8, _6$$8, _9$$10, _10$$11, _11$$11, *_12$$12, _13$$14, _14$$14, _15$$16, _16$$16, _17$$17, _18$$17, _19$$17, _20$$17, _21$$17, _22$$17, *_23$$19, _24$$20, _25$$20, _26$$20, _27$$20, _28$$20, _29$$20, _30$$20, _31$$20, _32$$21, _33$$22, _36$$23, _37$$23;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&temporary);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&createLines);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&reference);
	ZVAL_UNDEF(&references);
	ZVAL_UNDEF(&indexName);
	ZVAL_UNDEF(&indexSql);
	ZVAL_UNDEF(&indexSqlAfterCreate);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&columnLine);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&referenceSql);
	ZVAL_UNDEF(&onDelete);
	ZVAL_UNDEF(&onUpdate);
	ZVAL_UNDEF(&primaryColumns);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$17);
	ZVAL_UNDEF(&_18$$17);
	ZVAL_UNDEF(&_19$$17);
	ZVAL_UNDEF(&_20$$17);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_26$$20);
	ZVAL_UNDEF(&_27$$20);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_29$$20);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_32$$21);
	ZVAL_UNDEF(&_33$$22);
	ZVAL_UNDEF(&_36$$23);
	ZVAL_UNDEF(&_37$$23);
	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);


	ZEPHIR_OBS_VAR(&columns);
	if (!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array", "phalcon/db/dialect/postgresql.zep", 333);
		return;
	}
	ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&temporary);
	ZVAL_BOOL(&temporary, 0);
	ZEPHIR_OBS_VAR(&options);
	if (zephir_array_isset_string_fetch(&options, &definition, SL("options"), 0)) {
		ZEPHIR_OBS_NVAR(&temporary);
		zephir_array_isset_string_fetch(&temporary, &options, SL("temporary"), 0);
	}
	ZEPHIR_INIT_VAR(&sql);
	if (zephir_is_true(&temporary)) {
		ZEPHIR_CONCAT_SVS(&sql, "CREATE TEMPORARY TABLE ", &table, " (\n\t");
	} else {
		ZEPHIR_CONCAT_SVS(&sql, "CREATE TABLE ", &table, " (\n\t");
	}
	ZEPHIR_INIT_VAR(&createLines);
	array_init(&createLines);
	ZEPHIR_INIT_VAR(&primaryColumns);
	array_init(&primaryColumns);
	zephir_is_iterable(&columns, 0, "phalcon/db/dialect/postgresql.zep", 382);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _0)
	{
		ZEPHIR_INIT_NVAR(&column);
		ZVAL_COPY(&column, _0);
		ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", &_1, 0, &column);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$7, &column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&columnLine);
		ZEPHIR_CONCAT_SVSV(&columnLine, "\"", &_2$$7, "\" ", &columnDefinition);
		ZEPHIR_CALL_METHOD(&_3$$7, &column, "hasdefault", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$7)) {
			ZEPHIR_CALL_METHOD(&_4$$8, this_ptr, "_castdefault", &_5, 0, &column);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_6$$8);
			ZEPHIR_CONCAT_SV(&_6$$8, " DEFAULT ", &_4$$8);
			zephir_concat_self(&columnLine, &_6$$8 TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_7$$7, &column, "isnotnull", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_7$$7)) {
			zephir_concat_self_str(&columnLine, SL(" NOT NULL") TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_8$$7, &column, "isprimary", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_8$$7)) {
			ZEPHIR_CALL_METHOD(&_9$$10, &column, "getname", NULL, 0);
			zephir_check_call_status();
			zephir_array_append(&primaryColumns, &_9$$10, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 377);
		}
		zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 380);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&column);
	if (!(ZEPHIR_IS_EMPTY(&primaryColumns))) {
		ZEPHIR_CALL_METHOD(&_10$$11, this_ptr, "getcolumnlist", NULL, 40, &primaryColumns);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_11$$11);
		ZEPHIR_CONCAT_SVS(&_11$$11, "PRIMARY KEY (", &_10$$11, ")");
		zephir_array_append(&createLines, &_11$$11, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 383);
	}
	ZEPHIR_INIT_VAR(&indexSqlAfterCreate);
	ZVAL_STRING(&indexSqlAfterCreate, "");
	ZEPHIR_OBS_VAR(&indexes);
	if (zephir_array_isset_string_fetch(&indexes, &definition, SL("indexes"), 0)) {
		zephir_is_iterable(&indexes, 0, "phalcon/db/dialect/postgresql.zep", 417);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&indexes), _12$$12)
		{
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _12$$12);
			ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&indexSql);
			ZVAL_STRING(&indexSql, "");
			if (ZEPHIR_IS_STRING(&indexName, "PRIMARY")) {
				ZEPHIR_CALL_METHOD(&_14$$14, &index, "getcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_13$$14, this_ptr, "getcolumnlist", NULL, 40, &_14$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&indexSql);
				ZEPHIR_CONCAT_SVS(&indexSql, "CONSTRAINT \"PRIMARY\" PRIMARY KEY (", &_13$$14, ")");
			} else {
				if (!(ZEPHIR_IS_EMPTY(&indexType))) {
					ZEPHIR_CALL_METHOD(&_16$$16, &index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_15$$16, this_ptr, "getcolumnlist", NULL, 40, &_16$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&indexSql);
					ZEPHIR_CONCAT_SVSVSVS(&indexSql, "CONSTRAINT \"", &indexName, "\" ", &indexType, " (", &_15$$16, ")");
				} else {
					ZEPHIR_CALL_METHOD(&_17$$17, &index, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_18$$17, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_19$$17);
					ZEPHIR_CONCAT_SVSV(&_19$$17, "CREATE INDEX \"", &_17$$17, "\" ON ", &_18$$17);
					zephir_concat_self(&indexSqlAfterCreate, &_19$$17 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&_21$$17, &index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_20$$17, this_ptr, "getcolumnlist", NULL, 40, &_21$$17);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_22$$17);
					ZEPHIR_CONCAT_SVS(&_22$$17, " (", &_20$$17, ");");
					zephir_concat_self(&indexSqlAfterCreate, &_22$$17 TSRMLS_CC);
				}
			}
			if (!(ZEPHIR_IS_EMPTY(&indexSql))) {
				zephir_array_append(&createLines, &indexSql, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 414);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&index);
	}
	ZEPHIR_OBS_VAR(&references);
	if (zephir_array_isset_string_fetch(&references, &definition, SL("references"), 0)) {
		zephir_is_iterable(&references, 0, "phalcon/db/dialect/postgresql.zep", 442);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&references), _23$$19)
		{
			ZEPHIR_INIT_NVAR(&reference);
			ZVAL_COPY(&reference, _23$$19);
			ZEPHIR_CALL_METHOD(&_24$$20, &reference, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_26$$20, &reference, "getcolumns", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_25$$20, this_ptr, "getcolumnlist", NULL, 40, &_26$$20);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&referenceSql);
			ZEPHIR_CONCAT_SVSVS(&referenceSql, "CONSTRAINT \"", &_24$$20, "\" FOREIGN KEY (", &_25$$20, ") REFERENCES ");
			ZEPHIR_CALL_METHOD(&_28$$20, &reference, "getreferencedtable", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_27$$20, this_ptr, "preparetable", NULL, 0, &_28$$20, &schemaName);
			zephir_check_call_status();
			zephir_concat_self(&referenceSql, &_27$$20 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_30$$20, &reference, "getreferencedcolumns", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_29$$20, this_ptr, "getcolumnlist", NULL, 40, &_30$$20);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_31$$20);
			ZEPHIR_CONCAT_SVS(&_31$$20, " (", &_29$$20, ")");
			zephir_concat_self(&referenceSql, &_31$$20 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
				ZEPHIR_INIT_LNVAR(_32$$21);
				ZEPHIR_CONCAT_SV(&_32$$21, " ON DELETE ", &onDelete);
				zephir_concat_self(&referenceSql, &_32$$21 TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
				ZEPHIR_INIT_LNVAR(_33$$22);
				ZEPHIR_CONCAT_SV(&_33$$22, " ON UPDATE ", &onUpdate);
				zephir_concat_self(&referenceSql, &_33$$22 TSRMLS_CC);
			}
			zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/db/dialect/postgresql.zep", 440);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&reference);
	}
	ZEPHIR_INIT_VAR(&_34);
	zephir_fast_join_str(&_34, SL(",\n\t"), &createLines TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_35);
	ZEPHIR_CONCAT_VS(&_35, &_34, "\n)");
	zephir_concat_self(&sql, &_35 TSRMLS_CC);
	if (zephir_array_isset_string(&definition, SL("options"))) {
		ZEPHIR_CALL_METHOD(&_36$$23, this_ptr, "_gettableoptions", NULL, 0, &definition);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_37$$23);
		ZEPHIR_CONCAT_SV(&_37$$23, " ", &_36$$23);
		zephir_concat_self(&sql, &_37$$23 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&_38);
	ZEPHIR_CONCAT_SV(&_38, ";", &indexSqlAfterCreate);
	zephir_concat_self(&sql, &_38 TSRMLS_CC);
	RETURN_CCTOR(&sql);

}

/**
 * Generates SQL to truncate a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, truncateTable) {

	zval *tableName_param = NULL, *schemaName_param = NULL, sql, table;
	zval tableName, schemaName, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&table);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	if (!(Z_TYPE_P(&schemaName) == IS_UNDEF) && Z_STRLEN_P(&schemaName)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_VSV(&_0$$3, &schemaName, ".", &tableName);
		ZEPHIR_CPY_WRT(&table, &_0$$3);
	} else {
		ZEPHIR_CPY_WRT(&table, &tableName);
	}
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SV(&sql, "TRUNCATE TABLE ", &table);
	RETURN_CCTOR(&sql);

}

/**
 * Generates SQL to drop a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropTable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, table, sql;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&sql);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &tableName_param, &schemaName_param, &ifExists_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(ifExists_param) != IS_TRUE && Z_TYPE_P(ifExists_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ifExists' must be of the type bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ifExists = (Z_TYPE_P(ifExists_param) == IS_TRUE);
	}


	ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sql);
	if (ifExists) {
		ZEPHIR_CONCAT_SV(&sql, "DROP TABLE IF EXISTS ", &table);
	} else {
		ZEPHIR_CONCAT_SV(&sql, "DROP TABLE ", &table);
	}
	RETURN_CCTOR(&sql);

}

/**
 * Generates SQL to create a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *viewName_param = NULL, *definition_param = NULL, *schemaName_param = NULL, viewSql, _0;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&viewSql);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &viewName_param, &definition_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
		ZVAL_EMPTY_STRING(&viewName);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	ZEPHIR_OBS_VAR(&viewSql);
	if (!(zephir_array_isset_string_fetch(&viewSql, &definition, SL("sql"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array", "phalcon/db/dialect/postgresql.zep", 497);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &viewName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSV(return_value, "CREATE VIEW ", &_0, " AS ", &viewSql);
	RETURN_MM();

}

/**
 * Generates SQL to drop a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, view, sql;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&view);
	ZVAL_UNDEF(&sql);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &viewName_param, &schemaName_param, &ifExists_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
		ZVAL_EMPTY_STRING(&viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
	if (UNEXPECTED(Z_TYPE_P(ifExists_param) != IS_TRUE && Z_TYPE_P(ifExists_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ifExists' must be of the type bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ifExists = (Z_TYPE_P(ifExists_param) == IS_TRUE);
	}


	ZEPHIR_CALL_METHOD(&view, this_ptr, "preparetable", NULL, 0, &viewName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&sql);
	if (ifExists) {
		ZEPHIR_CONCAT_SV(&sql, "DROP VIEW IF EXISTS ", &view);
	} else {
		ZEPHIR_CONCAT_SV(&sql, "DROP VIEW ", &view);
	}
	RETURN_CCTOR(&sql);

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
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tableName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	if (!(Z_TYPE_P(&schemaName) == IS_UNDEF) && Z_STRLEN_P(&schemaName)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = '", &schemaName, "' AND table_name='", &tableName, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = 'public' AND table_name='", &tableName, "'");
	RETURN_MM();

}

/**
 * Generates SQL checking for the existence of a schema.view
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, viewExists) {

	zval *viewName_param = NULL, *schemaName_param = NULL;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewName_param, &schemaName_param);

	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
		ZVAL_EMPTY_STRING(&viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	if (!(Z_TYPE_P(&schemaName) == IS_UNDEF) && Z_STRLEN_P(&schemaName)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='", &viewName, "' AND schemaname='", &schemaName, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='", &viewName, "' AND schemaname='public'");
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
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	if (!(Z_TYPE_P(&schema) == IS_UNDEF) && Z_STRLEN_P(&schema)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, c.column_default FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='", &schema, "' AND c.table_name='", &table, "' ORDER BY c.ordinal_position");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, c.column_default FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) WHERE c.table_schema='public' AND c.table_name='", &table, "' ORDER BY c.ordinal_position");
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
	zval schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schemaName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	if (!(Z_TYPE_P(&schemaName) == IS_UNDEF) && Z_STRLEN_P(&schemaName)) {
		ZEPHIR_CONCAT_SVS(return_value, "SELECT table_name FROM information_schema.tables WHERE table_schema = '", &schemaName, "' ORDER BY table_name");
		RETURN_MM();
	}
	RETURN_MM_STRING("SELECT table_name FROM information_schema.tables WHERE table_schema = 'public' ORDER BY table_name");

}

/**
 * Generates the SQL to list all views of a schema or user
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listViews) {

	zval *schemaName_param = NULL;
	zval schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schemaName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	if (!(Z_TYPE_P(&schemaName) == IS_UNDEF) && Z_STRLEN_P(&schemaName)) {
		ZEPHIR_CONCAT_SVS(return_value, "SELECT viewname AS view_name FROM pg_views WHERE schemaname = '", &schemaName, "' ORDER BY view_name");
		RETURN_MM();
	}
	RETURN_MM_STRING("SELECT viewname AS view_name FROM pg_views WHERE schemaname = 'public' ORDER BY view_name");

}

/**
 * Generates SQL to query indexes on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeIndexes) {

	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_CONCAT_SVS(return_value, "SELECT 0 as c0, t.relname as table_name, i.relname as key_name, 3 as c3, a.attname as column_name FROM pg_class t, pg_class i, pg_index ix, pg_attribute a WHERE t.oid = ix.indrelid AND i.oid = ix.indexrelid AND a.attrelid = t.oid AND a.attnum = ANY(ix.indkey) AND t.relkind = 'r' AND t.relname = '", &table, "' ORDER BY t.relname, i.relname;");
	RETURN_MM();

}

/**
 * Generates SQL to query foreign keys on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeReferences) {

	zval *table_param = NULL, *schema_param = NULL, sql;
	zval table, schema, _0$$3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&sql);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "SELECT DISTINCT tc.table_name AS TABLE_NAME, kcu.column_name AS COLUMN_NAME, tc.constraint_name AS CONSTRAINT_NAME, tc.table_catalog AS REFERENCED_TABLE_SCHEMA, ccu.table_name AS REFERENCED_TABLE_NAME, ccu.column_name AS REFERENCED_COLUMN_NAME, rc.update_rule AS UPDATE_RULE, rc.delete_rule AS DELETE_RULE FROM information_schema.table_constraints AS tc JOIN information_schema.key_column_usage AS kcu ON tc.constraint_name = kcu.constraint_name JOIN information_schema.constraint_column_usage AS ccu ON ccu.constraint_name = tc.constraint_name JOIN information_schema.referential_constraints rc ON tc.constraint_catalog = rc.constraint_catalog AND tc.constraint_schema = rc.constraint_schema AND tc.constraint_name = rc.constraint_name AND tc.constraint_type = 'FOREIGN KEY' WHERE constraint_type = 'FOREIGN KEY' AND ");
	if (!(Z_TYPE_P(&schema) == IS_UNDEF) && Z_STRLEN_P(&schema)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SVSVS(&_0$$3, "tc.table_schema = '", &schema, "' AND tc.table_name='", &table, "'");
		zephir_concat_self(&sql, &_0$$3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_SVS(&_1$$4, "tc.table_schema = 'public' AND tc.table_name='", &table, "'");
		zephir_concat_self(&sql, &_1$$4 TSRMLS_CC);
	}
	RETURN_CCTOR(&sql);

}

/**
 * Generates the SQL to describe the table creation options
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableOptions) {

	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	RETURN_MM_STRING("");

}

PHP_METHOD(Phalcon_Db_Dialect_Postgresql, _castDefault) {

	zval _6$$5;
	zend_bool _2, _3, _4, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, defaultValue, preparedValue, columnDefinition, columnType, _0, _1, _7$$6, _8$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&preparedValue);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnType, column, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtoupper(&_0, &columnDefinition);
	if (zephir_memnstr_str(&_0, SL("BOOLEAN"), "phalcon/db/dialect/postgresql.zep", 634)) {
		RETURN_CCTOR(&defaultValue);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtoupper(&_1, &defaultValue);
	if (zephir_memnstr_str(&_1, SL("CURRENT_TIMESTAMP"), "phalcon/db/dialect/postgresql.zep", 638)) {
		RETURN_MM_STRING("CURRENT_TIMESTAMP");
	}
	_2 = ZEPHIR_IS_LONG_IDENTICAL(&columnType, 0);
	if (!(_2)) {
		_2 = ZEPHIR_IS_LONG_IDENTICAL(&columnType, 14);
	}
	_3 = _2;
	if (!(_3)) {
		_3 = ZEPHIR_IS_LONG_IDENTICAL(&columnType, 3);
	}
	_4 = _3;
	if (!(_4)) {
		_4 = ZEPHIR_IS_LONG_IDENTICAL(&columnType, 7);
	}
	_5 = _4;
	if (!(_5)) {
		_5 = ZEPHIR_IS_LONG_IDENTICAL(&columnType, 9);
	}
	ZEPHIR_INIT_VAR(&preparedValue);
	if (_5) {
		zephir_get_strval(&_6$$5, &defaultValue);
		ZEPHIR_CPY_WRT(&preparedValue, &_6$$5);
	} else {
		ZEPHIR_INIT_VAR(&_7$$6);
		ZVAL_STRING(&_7$$6, "\\'");
		ZEPHIR_CALL_FUNCTION(&_8$$6, "addcslashes", NULL, 147, &defaultValue, &_7$$6);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(&preparedValue, "'", &_8$$6, "'");
	}
	RETURN_CCTOR(&preparedValue);

}

PHP_METHOD(Phalcon_Db_Dialect_Postgresql, _getTableOptions) {

	zval *definition_param = NULL;
	zval definition;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition_param);

	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);


	RETURN_MM_STRING("");

}

/**
 * Returns a SQL modified a shared lock statement. For now this method
 * returns the original query
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, sharedLock) {

	zval *sqlQuery_param = NULL;
	zval sqlQuery;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);

	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(&sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlQuery);
		ZVAL_EMPTY_STRING(&sqlQuery);
	}


	RETURN_CTOR(&sqlQuery);

}

