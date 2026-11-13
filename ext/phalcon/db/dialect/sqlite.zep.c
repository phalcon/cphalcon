
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Generates database specific SQL for the SQLite RDBMS
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Sqlite)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Sqlite, phalcon, db_dialect_sqlite, phalcon_db_dialect_ce, phalcon_db_dialect_sqlite_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_dialect_sqlite_ce, SL("escapeChar"), "\"", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 *
	 * @phpstan-var list<string>
	 */
	zend_declare_property_null(phalcon_db_dialect_sqlite_ce, SL("supportedOperators"), ZEND_ACC_PROTECTED);
	phalcon_db_dialect_sqlite_ce->create_object = zephir_init_properties_Phalcon_Db_Dialect_Sqlite;

	return SUCCESS;
}

/**
 * Generates SQL to add a column to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addColumn)
{
	zend_bool _7, _17, _9$$3;
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *column, column_sub, defaultValue, _0, _1, _2, _3, _4, _5, _6, _8, _15, _16, _18, _10$$3, _11$$4, _12$$4, _13$$6, _14$$6;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&sql);
	ZEND_TLS zephir_method_cache _zephir_call_cache[12];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	column = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "prepareTable", &_zephir_call_cache[0], &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "ALTER TABLE ", &_0, " ADD COLUMN ");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&sql, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, column, "getName", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "getColumnDefinition", &_zephir_call_cache[2], column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_4, this_ptr, "getGeneratedClause", &_zephir_call_cache[3], column);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVSVV(&_5, "\"", &_2, "\" ", &_3, &_4);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_concat_self(&sql, &_5);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_6, column, "isGenerated", &_zephir_call_cache[4]);
	zephir_check_call_status();
	_7 = !zephir_is_true(&_6);
	if (_7) {
		ZEPHIR_CALL_METHOD_CACHED(&_8, column, "hasDefault", &_zephir_call_cache[5]);
		zephir_check_call_status();
		_7 = zephir_is_true(&_8);
	}
	if (_7) {
		ZEPHIR_CALL_METHOD_CACHED(&defaultValue, column, "getDefault", &_zephir_call_cache[6]);
		zephir_check_call_status();
		_9$$3 = Z_TYPE_P(&defaultValue) == IS_OBJECT;
		if (_9$$3) {
			_9$$3 = zephir_instance_of_ev(&defaultValue, phalcon_db_rawvalue_ce);
		}
		if (_9$$3) {
			ZEPHIR_CALL_METHOD_CACHED(&_11$$4, &defaultValue, "getValue", &_zephir_call_cache[7]);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_12$$4);
			ZEPHIR_CONCAT_SV(&_12$$4, " DEFAULT ", &_11$$4);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_concat_self(&sql, &_12$$4);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_INIT_VAR(&_10$$3);
			zephir_fast_strtoupper(&_10$$3, &defaultValue);
			if (zephir_memnstr_str(&_10$$3, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Sqlite.zep", 69)) {
				zephir_concat_self_str(&sql, " DEFAULT CURRENT_TIMESTAMP", sizeof(" DEFAULT CURRENT_TIMESTAMP") - 1);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CALL_METHOD_CACHED(&_13$$6, this_ptr, "escapeStringLiteral", &_zephir_call_cache[8], &defaultValue);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_14$$6);
				ZEPHIR_CONCAT_SVS(&_14$$6, " DEFAULT '", &_13$$6, "'");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&sql, &_14$$6);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_15, column, "isNotNull", &_zephir_call_cache[9]);
	zephir_check_call_status();
	if (zephir_is_true(&_15)) {
		zephir_concat_self_str(&sql, " NOT NULL", sizeof(" NOT NULL") - 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		zephir_concat_self_str(&sql, " NULL", sizeof(" NULL") - 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_16, column, "isGenerated", &_zephir_call_cache[10]);
	zephir_check_call_status();
	_17 = !zephir_is_true(&_16);
	if (_17) {
		ZEPHIR_CALL_METHOD_CACHED(&_18, column, "isAutoincrement", &_zephir_call_cache[11]);
		zephir_check_call_status();
		_17 = zephir_is_true(&_18);
	}
	if (_17) {
		zephir_concat_self_str(&sql, " PRIMARY KEY AUTOINCREMENT", sizeof(" PRIMARY KEY AUTOINCREMENT") - 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(&sql);
}

/**
 * SQLite cannot ALTER an existing table to add a CHECK constraint;
 * the constraint must be declared at CREATE TABLE time.
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addCheck)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *check, check_sub, _0;
	zend_string *tableName = NULL, *schemaName = NULL;

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&check_sub);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(check, phalcon_db_checkinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	check = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_db_exceptions_sqlitealterchecknotsupported_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 95);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addForeignKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *reference, reference_sub, _0;
	zend_string *tableName = NULL, *schemaName = NULL;

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&reference_sub);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(reference, phalcon_db_referenceinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	reference = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_db_exceptions_sqlitealterforeignkeynotsupported_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 103);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addIndex)
{
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *index, index_sub, indexType, _5, _6, _7, _8, _0$$3, _1$$5, _2$$5, _3$$6, _4$$6, _9$$7, _10$$7;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&sql);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(index, phalcon_db_indexinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	index = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	ZEPHIR_CALL_METHOD_CACHED(&indexType, index, "getType", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&indexType))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SVS(&_0$$3, "CREATE ", &indexType, " INDEX ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_get_strval(&sql, &_0$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&sql);
		ZVAL_STRING(&sql, "CREATE INDEX ");
	}
	if (!(ZEPHIR_IS_EMPTY(&schemaName_zv))) {
		ZEPHIR_CALL_METHOD_CACHED(&_1$$5, index, "getName", &_zephir_call_cache[1]);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$5);
		ZEPHIR_CONCAT_SVSVS(&_2$$5, "\"", &schemaName_zv, "\".\"", &_1$$5, "\"");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&sql, &_2$$5);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD_CACHED(&_3$$6, index, "getName", &_zephir_call_cache[2]);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$6);
		ZEPHIR_CONCAT_SVS(&_4$$6, "\"", &_3$$6, "\"");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&sql, &_4$$6);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZVAL_BOOL(&_6, 0);
	ZEPHIR_CALL_METHOD_CACHED(&_5, this_ptr, "getIndexColumnList", &_zephir_call_cache[3], index, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SVSVS(&_7, " ON \"", &tableName_zv, "\" (", &_5, ")");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_concat_self(&sql, &_7);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_8, index, "getWhere", &_zephir_call_cache[4]);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_8, "")) {
		ZEPHIR_CALL_METHOD_CACHED(&_9$$7, index, "getWhere", &_zephir_call_cache[5]);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$7);
		ZEPHIR_CONCAT_SV(&_10$$7, " WHERE ", &_9$$7);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&sql, &_10$$7);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to add the primary key to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addPrimaryKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *index, index_sub, _0;
	zend_string *tableName = NULL, *schemaName = NULL;

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(index, phalcon_db_indexinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	index = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_db_exceptions_sqlitealterprimarykeynotsupported_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 143);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createTable)
{
	zval sql;
	zend_bool hasPrimary = 0, _0, _2, _25, _42, _66, _88, _1$$3, _13$$8, _15$$8, _17$$11, _31$$18, _33$$18, _35$$21, _56$$27, _46$$28, _47$$28, _57$$31, _58$$31, _79$$34, _95$$41;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval tableName_zv, schemaName_zv, *definition_param = NULL, columns, table, temporary, options, createLines, columnLine, column, indexes, index, indexName, indexType, references, reference, defaultValue, referenceSql, onDelete, onUpdate, checks, check, *_5, _6, *_7, _24, _98, _99, _3$$5, _4$$6, _8$$7, _9$$7, _10$$7, _11$$7, _23$$7, _12$$8, _14$$8, _16$$8, _18$$11, _19$$12, _20$$12, _21$$14, _22$$14, _26$$17, _27$$17, _28$$17, _29$$17, _41$$17, _30$$18, _32$$18, _34$$18, _36$$21, _37$$22, _38$$22, _39$$24, _40$$24, *_43$$27, _44$$27, *_45$$27, _55$$27, _48$$28, _49$$29, _50$$29, _51$$29, _52$$30, _53$$30, _54$$30, _59$$31, _60$$32, _61$$32, _62$$32, _63$$33, _64$$33, _65$$33, *_67$$34, _68$$34, *_69$$34, _78$$34, _70$$35, _71$$35, _72$$35, _73$$35, _74$$35, _75$$35, _76$$36, _77$$37, _80$$38, _81$$38, _82$$38, _83$$38, _84$$38, _85$$38, _86$$39, _87$$40, *_89$$41, _90$$41, *_91$$41, _94$$41, _92$$42, _93$$42, _96$$43, _97$$43;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&temporary);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&createLines);
	ZVAL_UNDEF(&columnLine);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&indexName);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&references);
	ZVAL_UNDEF(&reference);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&referenceSql);
	ZVAL_UNDEF(&onDelete);
	ZVAL_UNDEF(&onUpdate);
	ZVAL_UNDEF(&checks);
	ZVAL_UNDEF(&check);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_98);
	ZVAL_UNDEF(&_99);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_29$$17);
	ZVAL_UNDEF(&_41$$17);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_32$$18);
	ZVAL_UNDEF(&_34$$18);
	ZVAL_UNDEF(&_36$$21);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_38$$22);
	ZVAL_UNDEF(&_39$$24);
	ZVAL_UNDEF(&_40$$24);
	ZVAL_UNDEF(&_44$$27);
	ZVAL_UNDEF(&_55$$27);
	ZVAL_UNDEF(&_48$$28);
	ZVAL_UNDEF(&_49$$29);
	ZVAL_UNDEF(&_50$$29);
	ZVAL_UNDEF(&_51$$29);
	ZVAL_UNDEF(&_52$$30);
	ZVAL_UNDEF(&_53$$30);
	ZVAL_UNDEF(&_54$$30);
	ZVAL_UNDEF(&_59$$31);
	ZVAL_UNDEF(&_60$$32);
	ZVAL_UNDEF(&_61$$32);
	ZVAL_UNDEF(&_62$$32);
	ZVAL_UNDEF(&_63$$33);
	ZVAL_UNDEF(&_64$$33);
	ZVAL_UNDEF(&_65$$33);
	ZVAL_UNDEF(&_68$$34);
	ZVAL_UNDEF(&_78$$34);
	ZVAL_UNDEF(&_70$$35);
	ZVAL_UNDEF(&_71$$35);
	ZVAL_UNDEF(&_72$$35);
	ZVAL_UNDEF(&_73$$35);
	ZVAL_UNDEF(&_74$$35);
	ZVAL_UNDEF(&_75$$35);
	ZVAL_UNDEF(&_76$$36);
	ZVAL_UNDEF(&_77$$37);
	ZVAL_UNDEF(&_80$$38);
	ZVAL_UNDEF(&_81$$38);
	ZVAL_UNDEF(&_82$$38);
	ZVAL_UNDEF(&_83$$38);
	ZVAL_UNDEF(&_84$$38);
	ZVAL_UNDEF(&_85$$38);
	ZVAL_UNDEF(&_86$$39);
	ZVAL_UNDEF(&_87$$40);
	ZVAL_UNDEF(&_90$$41);
	ZVAL_UNDEF(&_94$$41);
	ZVAL_UNDEF(&_92$$42);
	ZVAL_UNDEF(&_93$$42);
	ZVAL_UNDEF(&_96$$43);
	ZVAL_UNDEF(&_97$$43);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&sql);
	ZEND_TLS zephir_method_cache _zephir_call_cache[65];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		ZEPHIR_Z_PARAM_ARRAY(definition, definition_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_get_arrval(&definition, definition_param);
	ZEPHIR_CALL_METHOD_CACHED(&table, this_ptr, "prepareTable", &_zephir_call_cache[0], &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&temporary);
	ZVAL_BOOL(&temporary, 0);
	zephir_memory_observe(&options);
	_0 = zephir_array_isset_string_fetch(&options, &definition, SL("options"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		ZEPHIR_OBS_NVAR(&temporary);
		_1$$3 = zephir_array_isset_string_fetch(&temporary, &options, SL("temporary"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_1$$3;
	}
	zephir_memory_observe(&columns);
	_2 = zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_missingdefinitionkey_ce, "columns", "phalcon/Db/Dialect/Sqlite.zep", 165);
		return;
	}
	if (zephir_is_true(&temporary)) {
		ZEPHIR_INIT_VAR(&_3$$5);
		ZEPHIR_CONCAT_SV(&_3$$5, "CREATE TEMPORARY TABLE ", &table);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_get_strval(&sql, &_3$$5);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&_4$$6);
		ZEPHIR_CONCAT_SV(&_4$$6, "CREATE TABLE ", &table);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_get_strval(&sql, &_4$$6);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_concat_self_str(&sql, " (\n\t", sizeof(" (\n\t") - 1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	hasPrimary = 0;
	ZEPHIR_INIT_VAR(&createLines);
	array_init(&createLines);
	if (Z_TYPE_P(&columns) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_6);
		zephir_string_to_char_array(&_6, &columns);
		_5 = &_6;
	} else {
		_5 = &columns;
	}
	zephir_is_iterable(_5, 0, "phalcon/Db/Dialect/Sqlite.zep", 234);
	if (Z_TYPE_P(_5) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_5), _7)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _7);
			ZEPHIR_CALL_METHOD_CACHED(&_8$$7, &column, "getName", &_zephir_call_cache[1]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&_9$$7, this_ptr, "getColumnDefinition", &_zephir_call_cache[2], &column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&_10$$7, this_ptr, "getGeneratedClause", &_zephir_call_cache[3], &column);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&columnLine);
			ZEPHIR_CONCAT_SVSVV(&columnLine, "`", &_8$$7, "` ", &_9$$7, &_10$$7);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_11$$7, &column, "isGenerated", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!(zephir_is_true(&_11$$7))) {
				ZEPHIR_CALL_METHOD_CACHED(&_12$$8, &column, "isPrimary", &_zephir_call_cache[5]);
				zephir_check_call_status();
				_13$$8 = zephir_is_true(&_12$$8);
				if (_13$$8) {
					_13$$8 = !hasPrimary;
				}
				if (_13$$8) {
					zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					hasPrimary = 1;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_14$$8, &column, "isAutoIncrement", &_zephir_call_cache[6]);
				zephir_check_call_status();
				_15$$8 = zephir_is_true(&_14$$8);
				if (_15$$8) {
					_15$$8 = hasPrimary;
				}
				if (_15$$8) {
					zephir_concat_self_str(&columnLine, SL(" AUTOINCREMENT"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_CALL_METHOD_CACHED(&_16$$8, &column, "hasDefault", &_zephir_call_cache[7]);
				zephir_check_call_status();
				if (zephir_is_true(&_16$$8)) {
					ZEPHIR_CALL_METHOD_CACHED(&defaultValue, &column, "getDefault", &_zephir_call_cache[8]);
					zephir_check_call_status();
					_17$$11 = Z_TYPE_P(&defaultValue) == IS_OBJECT;
					if (_17$$11) {
						_17$$11 = zephir_instance_of_ev(&defaultValue, phalcon_db_rawvalue_ce);
					}
					if (_17$$11) {
						ZEPHIR_CALL_METHOD_CACHED(&_19$$12, &defaultValue, "getValue", &_zephir_call_cache[9]);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_20$$12);
						ZEPHIR_CONCAT_SV(&_20$$12, " DEFAULT ", &_19$$12);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&columnLine, &_20$$12);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_18$$11);
						zephir_fast_strtoupper(&_18$$11, &defaultValue);
						if (zephir_memnstr_str(&_18$$11, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Sqlite.zep", 211)) {
							zephir_concat_self_str(&columnLine, SL(" DEFAULT CURRENT_TIMESTAMP"));
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_CALL_METHOD_CACHED(&_21$$14, this_ptr, "escapeStringLiteral", &_zephir_call_cache[10], &defaultValue);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_22$$14);
							ZEPHIR_CONCAT_SVS(&_22$$14, " DEFAULT '", &_21$$14, "'");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_concat_self(&columnLine, &_22$$14);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
				}
			}
			ZEPHIR_CALL_METHOD_CACHED(&_23$$7, &column, "isNotNull", &_zephir_call_cache[11]);
			zephir_check_call_status();
			if (zephir_is_true(&_23$$7)) {
				zephir_concat_self_str(&columnLine, SL(" NOT NULL"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				zephir_concat_self_str(&columnLine, SL(" NULL"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 228);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "rewind", &_zephir_call_cache[12]);
		zephir_check_call_status();
		_25 = 1;
		while (1) {
			if (_25) {
				_25 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "next", &_zephir_call_cache[13]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_24, _5, "valid", &_zephir_call_cache[14]);
			zephir_check_call_status();
			if (!zend_is_true(&_24)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&column, _5, "current", &_zephir_call_cache[15]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_26$$17, &column, "getName", &_zephir_call_cache[16]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_27$$17, this_ptr, "getColumnDefinition", &_zephir_call_cache[17], &column);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_28$$17, this_ptr, "getGeneratedClause", &_zephir_call_cache[18], &column);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&columnLine);
				ZEPHIR_CONCAT_SVSVV(&columnLine, "`", &_26$$17, "` ", &_27$$17, &_28$$17);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_29$$17, &column, "isGenerated", &_zephir_call_cache[19]);
				zephir_check_call_status();
				if (!(zephir_is_true(&_29$$17))) {
					ZEPHIR_CALL_METHOD_CACHED(&_30$$18, &column, "isPrimary", &_zephir_call_cache[20]);
					zephir_check_call_status();
					_31$$18 = zephir_is_true(&_30$$18);
					if (_31$$18) {
						_31$$18 = !hasPrimary;
					}
					if (_31$$18) {
						zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						hasPrimary = 1;
					}
					ZEPHIR_CALL_METHOD_CACHED(&_32$$18, &column, "isAutoIncrement", &_zephir_call_cache[21]);
					zephir_check_call_status();
					_33$$18 = zephir_is_true(&_32$$18);
					if (_33$$18) {
						_33$$18 = hasPrimary;
					}
					if (_33$$18) {
						zephir_concat_self_str(&columnLine, SL(" AUTOINCREMENT"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					ZEPHIR_CALL_METHOD_CACHED(&_34$$18, &column, "hasDefault", &_zephir_call_cache[22]);
					zephir_check_call_status();
					if (zephir_is_true(&_34$$18)) {
						ZEPHIR_CALL_METHOD_CACHED(&defaultValue, &column, "getDefault", &_zephir_call_cache[23]);
						zephir_check_call_status();
						_35$$21 = Z_TYPE_P(&defaultValue) == IS_OBJECT;
						if (_35$$21) {
							_35$$21 = zephir_instance_of_ev(&defaultValue, phalcon_db_rawvalue_ce);
						}
						if (_35$$21) {
							ZEPHIR_CALL_METHOD_CACHED(&_37$$22, &defaultValue, "getValue", &_zephir_call_cache[24]);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_38$$22);
							ZEPHIR_CONCAT_SV(&_38$$22, " DEFAULT ", &_37$$22);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_concat_self(&columnLine, &_38$$22);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_INIT_NVAR(&_36$$21);
							zephir_fast_strtoupper(&_36$$21, &defaultValue);
							if (zephir_memnstr_str(&_36$$21, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Sqlite.zep", 211)) {
								zephir_concat_self_str(&columnLine, SL(" DEFAULT CURRENT_TIMESTAMP"));
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_CALL_METHOD_CACHED(&_39$$24, this_ptr, "escapeStringLiteral", &_zephir_call_cache[25], &defaultValue);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_40$$24);
								ZEPHIR_CONCAT_SVS(&_40$$24, " DEFAULT '", &_39$$24, "'");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_concat_self(&columnLine, &_40$$24);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						}
					}
				}
				ZEPHIR_CALL_METHOD_CACHED(&_41$$17, &column, "isNotNull", &_zephir_call_cache[26]);
				zephir_check_call_status();
				if (zephir_is_true(&_41$$17)) {
					zephir_concat_self_str(&columnLine, SL(" NOT NULL"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					zephir_concat_self_str(&columnLine, SL(" NULL"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 228);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	zephir_memory_observe(&indexes);
	_42 = zephir_array_isset_string_fetch(&indexes, &definition, SL("indexes"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_42) {
		if (Z_TYPE_P(&indexes) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_44$$27);
			zephir_string_to_char_array(&_44$$27, &indexes);
			_43$$27 = &_44$$27;
		} else {
			_43$$27 = &indexes;
		}
		zephir_is_iterable(_43$$27, 0, "phalcon/Db/Dialect/Sqlite.zep", 250);
		if (Z_TYPE_P(_43$$27) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_43$$27), _45$$27)
			{
				ZEPHIR_INIT_NVAR(&index);
				ZVAL_COPY(&index, _45$$27);
				ZEPHIR_CALL_METHOD_CACHED(&indexName, &index, "getName", &_zephir_call_cache[27]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&indexType, &index, "getType", &_zephir_call_cache[28]);
				zephir_check_call_status();
				_46$$28 = ZEPHIR_IS_STRING(&indexName, "PRIMARY");
				if (_46$$28) {
					_46$$28 = !hasPrimary;
				}
				if (_46$$28) {
					ZVAL_BOOL(&_50$$29, 0);
					ZEPHIR_CALL_METHOD_CACHED(&_49$$29, this_ptr, "getIndexColumnList", &_zephir_call_cache[29], &index, &_50$$29);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_51$$29);
					ZEPHIR_CONCAT_SVS(&_51$$29, "PRIMARY KEY (", &_49$$29, ")");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&createLines, &_51$$29, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 244);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					_47$$28 = !(ZEPHIR_IS_EMPTY(&indexType));
					if (_47$$28) {
						ZEPHIR_INIT_NVAR(&_48$$28);
						zephir_fast_strtoupper(&_48$$28, &indexType);
						_47$$28 = zephir_memnstr_str(&_48$$28, SL("UNIQUE"), "phalcon/Db/Dialect/Sqlite.zep", 245);
					}
					if (_47$$28) {
						ZVAL_BOOL(&_53$$30, 0);
						ZEPHIR_CALL_METHOD_CACHED(&_52$$30, this_ptr, "getIndexColumnList", &_zephir_call_cache[30], &index, &_53$$30);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_54$$30);
						ZEPHIR_CONCAT_SVS(&_54$$30, "UNIQUE (", &_52$$30, ")");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&createLines, &_54$$30, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 247);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _43$$27, "rewind", &_zephir_call_cache[31]);
			zephir_check_call_status();
			_56$$27 = 1;
			while (1) {
				if (_56$$27) {
					_56$$27 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _43$$27, "next", &_zephir_call_cache[32]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_55$$27, _43$$27, "valid", &_zephir_call_cache[33]);
				zephir_check_call_status();
				if (!zend_is_true(&_55$$27)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&index, _43$$27, "current", &_zephir_call_cache[34]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&indexName, &index, "getName", &_zephir_call_cache[35]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&indexType, &index, "getType", &_zephir_call_cache[36]);
					zephir_check_call_status();
					_57$$31 = ZEPHIR_IS_STRING(&indexName, "PRIMARY");
					if (_57$$31) {
						_57$$31 = !hasPrimary;
					}
					if (_57$$31) {
						ZVAL_BOOL(&_61$$32, 0);
						ZEPHIR_CALL_METHOD_CACHED(&_60$$32, this_ptr, "getIndexColumnList", &_zephir_call_cache[37], &index, &_61$$32);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_62$$32);
						ZEPHIR_CONCAT_SVS(&_62$$32, "PRIMARY KEY (", &_60$$32, ")");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&createLines, &_62$$32, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 244);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						_58$$31 = !(ZEPHIR_IS_EMPTY(&indexType));
						if (_58$$31) {
							ZEPHIR_INIT_NVAR(&_59$$31);
							zephir_fast_strtoupper(&_59$$31, &indexType);
							_58$$31 = zephir_memnstr_str(&_59$$31, SL("UNIQUE"), "phalcon/Db/Dialect/Sqlite.zep", 245);
						}
						if (_58$$31) {
							ZVAL_BOOL(&_64$$33, 0);
							ZEPHIR_CALL_METHOD_CACHED(&_63$$33, this_ptr, "getIndexColumnList", &_zephir_call_cache[38], &index, &_64$$33);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_65$$33);
							ZEPHIR_CONCAT_SVS(&_65$$33, "UNIQUE (", &_63$$33, ")");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&createLines, &_65$$33, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 247);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&index);
	}
	zephir_memory_observe(&references);
	_66 = zephir_array_isset_string_fetch(&references, &definition, SL("references"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_66) {
		if (Z_TYPE_P(&references) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_68$$34);
			zephir_string_to_char_array(&_68$$34, &references);
			_67$$34 = &_68$$34;
		} else {
			_67$$34 = &references;
		}
		zephir_is_iterable(_67$$34, 0, "phalcon/Db/Dialect/Sqlite.zep", 272);
		if (Z_TYPE_P(_67$$34) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_67$$34), _69$$34)
			{
				ZEPHIR_INIT_NVAR(&reference);
				ZVAL_COPY(&reference, _69$$34);
				ZEPHIR_CALL_METHOD_CACHED(&_70$$35, &reference, "getName", &_zephir_call_cache[39]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_72$$35, &reference, "getColumns", &_zephir_call_cache[40]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_71$$35, this_ptr, "getColumnList", &_zephir_call_cache[41], &_72$$35);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_73$$35, &reference, "getReferencedTable", &_zephir_call_cache[42]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_75$$35, &reference, "getReferencedColumns", &_zephir_call_cache[43]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_74$$35, this_ptr, "getColumnList", &_zephir_call_cache[44], &_75$$35);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&referenceSql);
				ZEPHIR_CONCAT_SVSVSSVSVS(&referenceSql, "CONSTRAINT `", &_70$$35, "` FOREIGN KEY (", &_71$$35, ")", " REFERENCES `", &_73$$35, "`(", &_74$$35, ")");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&onDelete, &reference, "getOnDelete", &_zephir_call_cache[45]);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
					ZEPHIR_INIT_NVAR(&_76$$36);
					ZEPHIR_CONCAT_SV(&_76$$36, " ON DELETE ", &onDelete);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&referenceSql, &_76$$36);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_CALL_METHOD_CACHED(&onUpdate, &reference, "getOnUpdate", &_zephir_call_cache[46]);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
					ZEPHIR_INIT_NVAR(&_77$$37);
					ZEPHIR_CONCAT_SV(&_77$$37, " ON UPDATE ", &onUpdate);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&referenceSql, &_77$$37);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 270);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _67$$34, "rewind", &_zephir_call_cache[47]);
			zephir_check_call_status();
			_79$$34 = 1;
			while (1) {
				if (_79$$34) {
					_79$$34 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _67$$34, "next", &_zephir_call_cache[48]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_78$$34, _67$$34, "valid", &_zephir_call_cache[49]);
				zephir_check_call_status();
				if (!zend_is_true(&_78$$34)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&reference, _67$$34, "current", &_zephir_call_cache[50]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_80$$38, &reference, "getName", &_zephir_call_cache[51]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_82$$38, &reference, "getColumns", &_zephir_call_cache[52]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_81$$38, this_ptr, "getColumnList", &_zephir_call_cache[53], &_82$$38);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_83$$38, &reference, "getReferencedTable", &_zephir_call_cache[54]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_85$$38, &reference, "getReferencedColumns", &_zephir_call_cache[55]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_84$$38, this_ptr, "getColumnList", &_zephir_call_cache[56], &_85$$38);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&referenceSql);
					ZEPHIR_CONCAT_SVSVSSVSVS(&referenceSql, "CONSTRAINT `", &_80$$38, "` FOREIGN KEY (", &_81$$38, ")", " REFERENCES `", &_83$$38, "`(", &_84$$38, ")");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&onDelete, &reference, "getOnDelete", &_zephir_call_cache[57]);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
						ZEPHIR_INIT_NVAR(&_86$$39);
						ZEPHIR_CONCAT_SV(&_86$$39, " ON DELETE ", &onDelete);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&referenceSql, &_86$$39);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					ZEPHIR_CALL_METHOD_CACHED(&onUpdate, &reference, "getOnUpdate", &_zephir_call_cache[58]);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
						ZEPHIR_INIT_NVAR(&_87$$40);
						ZEPHIR_CONCAT_SV(&_87$$40, " ON UPDATE ", &onUpdate);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&referenceSql, &_87$$40);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 270);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&reference);
	}
	zephir_memory_observe(&checks);
	_88 = zephir_array_isset_string_fetch(&checks, &definition, SL("checks"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_88) {
		if (Z_TYPE_P(&checks) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_90$$41);
			zephir_string_to_char_array(&_90$$41, &checks);
			_89$$41 = &_90$$41;
		} else {
			_89$$41 = &checks;
		}
		zephir_is_iterable(_89$$41, 0, "phalcon/Db/Dialect/Sqlite.zep", 281);
		if (Z_TYPE_P(_89$$41) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_89$$41), _91$$41)
			{
				ZEPHIR_INIT_NVAR(&check);
				ZVAL_COPY(&check, _91$$41);
				ZEPHIR_INIT_NVAR(&_93$$42);
				ZVAL_STRING(&_93$$42, "`");
				ZEPHIR_CALL_METHOD_CACHED(&_92$$42, this_ptr, "getCheckClause", &_zephir_call_cache[59], &check, &_93$$42);
				zephir_check_call_status();
				zephir_array_append(&createLines, &_92$$42, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 279);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _89$$41, "rewind", &_zephir_call_cache[60]);
			zephir_check_call_status();
			_95$$41 = 1;
			while (1) {
				if (_95$$41) {
					_95$$41 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _89$$41, "next", &_zephir_call_cache[61]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_94$$41, _89$$41, "valid", &_zephir_call_cache[62]);
				zephir_check_call_status();
				if (!zend_is_true(&_94$$41)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&check, _89$$41, "current", &_zephir_call_cache[63]);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_97$$43);
					ZVAL_STRING(&_97$$43, "`");
					ZEPHIR_CALL_METHOD_CACHED(&_96$$43, this_ptr, "getCheckClause", &_zephir_call_cache[64], &check, &_97$$43);
					zephir_check_call_status();
					zephir_array_append(&createLines, &_96$$43, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 279);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&check);
	}
	ZEPHIR_INIT_VAR(&_98);
	zephir_fast_join_str(&_98, SL(",\n\t"), &createLines);
	ZEPHIR_INIT_VAR(&_99);
	ZEPHIR_CONCAT_VS(&_99, &_98, "\n)");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_concat_self(&sql, &_99);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to create a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createView)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval viewName_zv, *definition_param = NULL, schemaName_zv, viewSql, _1;
	zend_string *viewName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&viewSql);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&definition);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(viewName)
		ZEPHIR_Z_PARAM_ARRAY(definition, definition_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&viewName_zv);
	ZVAL_STR_COPY(&viewName_zv, viewName);
	zephir_get_arrval(&definition, definition_param);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	zephir_memory_observe(&viewSql);
	_0 = zephir_array_isset_string_fetch(&viewSql, &definition, SL("sql"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_missingdefinitionkey_ce, "sql", "phalcon/Db/Dialect/Sqlite.zep", 296);
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "prepareTable", &_zephir_call_cache[0], &viewName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSV(return_value, "CREATE VIEW ", &_1, " AS ", &viewSql);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL describing a table
 *
 * ```php
 * print_r(
 *     $dialect->describeColumns("posts")
 * );
 * ```
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeColumns)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, _0;
	zend_string *table = NULL, *schema = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
	if (!schema) {
		ZEPHIR_INIT_VAR(&schema_zv);
	} else {
		zephir_memory_observe(&schema_zv);
	ZVAL_STR_COPY(&schema_zv, schema);
	}
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "escapeStringLiteral", &_zephir_call_cache[0], &table_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA table_xinfo('", &_0, "')");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL to query indexes detail on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval index_zv, _0;
	zend_string *index = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_zv);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&index_zv);
	ZVAL_STR_COPY(&index_zv, index);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "escapeStringLiteral", &_zephir_call_cache[0], &index_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA index_info('", &_0, "')");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL to query indexes on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndexes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, _0;
	zend_string *table = NULL, *schema = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
	if (!schema) {
		ZEPHIR_INIT_VAR(&schema_zv);
	} else {
		zephir_memory_observe(&schema_zv);
	ZVAL_STR_COPY(&schema_zv, schema);
	}
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "escapeStringLiteral", &_zephir_call_cache[0], &table_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA index_list('", &_0, "')");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL to query foreign keys on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeReferences)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, _0;
	zend_string *table = NULL, *schema = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
	if (!schema) {
		ZEPHIR_INIT_VAR(&schema_zv);
	} else {
		zephir_memory_observe(&schema_zv);
	ZVAL_STR_COPY(&schema_zv, schema);
	}
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "escapeStringLiteral", &_zephir_call_cache[0], &table_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA foreign_key_list('", &_0, "')");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL to delete a column from a table.
 *
 * SQLite 3.35+ supports `ALTER TABLE ... DROP COLUMN ...` directly. On
 * older versions the server rejects the statement at execution time;
 * cphalcon no longer pre-empts that rejection at the dialect level so
 * callers on 3.35+ can use the feature.
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropColumn)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, columnName_zv, _0;
	zend_string *tableName = NULL, *schemaName = NULL, *columnName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&columnName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_STR(columnName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_memory_observe(&columnName_zv);
	ZVAL_STR_COPY(&columnName_zv, columnName);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "prepareTable", &_zephir_call_cache[0], &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP COLUMN \"", &columnName_zv, "\"");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * SQLite cannot DROP a CHECK constraint from an existing table.
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropCheck)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, checkName_zv, _0;
	zend_string *tableName = NULL, *schemaName = NULL, *checkName = NULL;

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&checkName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_STR(checkName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_memory_observe(&checkName_zv);
	ZVAL_STR_COPY(&checkName_zv, checkName);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_db_exceptions_sqlitedropchecknotsupported_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 368);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Generates SQL to delete a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropForeignKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, referenceName_zv, _0;
	zend_string *tableName = NULL, *schemaName = NULL, *referenceName = NULL;

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&referenceName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_STR(referenceName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_memory_observe(&referenceName_zv);
	ZVAL_STR_COPY(&referenceName_zv, referenceName);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_db_exceptions_sqlitedropforeignkeynotsupported_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 376);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Generates SQL to delete an index from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropIndex)
{
	zval tableName_zv, schemaName_zv, indexName_zv;
	zend_string *tableName = NULL, *schemaName = NULL, *indexName = NULL;

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&indexName_zv);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_STR(indexName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&tableName_zv, tableName);
	ZVAL_STR(&schemaName_zv, schemaName);
	ZVAL_STR(&indexName_zv, indexName);
	if (!(ZEPHIR_IS_EMPTY(&schemaName_zv))) {
		ZEPHIR_CONCAT_SVSVS(return_value, "DROP INDEX \"", &schemaName_zv, "\".\"", &indexName_zv, "\"");
		if (UNEXPECTED(EG(exception))) {
			return;
		}
		return;
	}
	ZEPHIR_CONCAT_SVS(return_value, "DROP INDEX \"", &indexName_zv, "\"");
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	return;
}

/**
 * Generates SQL to delete primary key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropPrimaryKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, _0;
	zend_string *tableName = NULL, *schemaName = NULL;

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_db_exceptions_sqlitedropprimarykeynotsupported_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 396);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Generates SQL to drop a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropTable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval tableName_zv, schemaName_zv, *ifExists_param = NULL, table;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&table);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
		Z_PARAM_BOOL(ifExists)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		ifExists_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
		}
	ZEPHIR_CALL_METHOD_CACHED(&table, this_ptr, "prepareTable", &_zephir_call_cache[0], &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	if (ifExists) {
		ZEPHIR_CONCAT_SV(return_value, "DROP TABLE IF EXISTS ", &table);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SV(return_value, "DROP TABLE ", &table);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL to drop a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropView)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval viewName_zv, schemaName_zv, *ifExists_param = NULL, view;
	zend_string *viewName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&view);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(viewName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
		Z_PARAM_BOOL(ifExists)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		ifExists_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&viewName_zv);
	ZVAL_STR_COPY(&viewName_zv, viewName);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	if (!ifExists_param) {
		ifExists = 1;
	} else {
		}
	ZEPHIR_CALL_METHOD_CACHED(&view, this_ptr, "prepareTable", &_zephir_call_cache[0], &viewName_zv, &schemaName_zv);
	zephir_check_call_status();
	if (ifExists) {
		ZEPHIR_CONCAT_SV(return_value, "DROP VIEW IF EXISTS ", &view);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SV(return_value, "DROP VIEW ", &view);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Returns a SQL modified with a FOR UPDATE clause. SQLite has no
 * row-level locking, so the original query is returned unchanged
 * regardless of the `modifier` argument (`NOWAIT` / `SKIP LOCKED` are
 * silently ignored).
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, forUpdate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval sqlQuery_zv, modifier_zv;
	zend_string *sqlQuery = NULL, *modifier = NULL;

	ZVAL_UNDEF(&sqlQuery_zv);
	ZVAL_UNDEF(&modifier_zv);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(sqlQuery)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(modifier)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&sqlQuery_zv);
	ZVAL_STR_COPY(&sqlQuery_zv, sqlQuery);
	if (!modifier) {
		modifier = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&modifier_zv);
		ZVAL_STR(&modifier_zv, modifier);
	} else {
		zephir_memory_observe(&modifier_zv);
	ZVAL_STR_COPY(&modifier_zv, modifier);
	}
	RETURN_MM_STR(zend_string_copy(sqlQuery));
}

/**
 * Gets the column name in SQLite
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, getColumnDefinition)
{
	zend_bool _14$$40;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, columnType, columnSql, typeValues, _0$$3, _1$$10, _2$$16, _3$$18, _4$$35, _5$$38, _6$$38, _7$$38, value$$40, valueSql$$40, *_8$$40, _9$$40, *_10$$40, _13$$40, _17$$40, _18$$40, _19$$40, _20$$40, _11$$41, _12$$41, _15$$42, _16$$42, _21$$43, _22$$43;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&columnSql);
	ZVAL_UNDEF(&typeValues);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$10);
	ZVAL_UNDEF(&_2$$16);
	ZVAL_UNDEF(&_3$$18);
	ZVAL_UNDEF(&_4$$35);
	ZVAL_UNDEF(&_5$$38);
	ZVAL_UNDEF(&_6$$38);
	ZVAL_UNDEF(&_7$$38);
	ZVAL_UNDEF(&value$$40);
	ZVAL_UNDEF(&valueSql$$40);
	ZVAL_UNDEF(&_9$$40);
	ZVAL_UNDEF(&_13$$40);
	ZVAL_UNDEF(&_17$$40);
	ZVAL_UNDEF(&_18$$40);
	ZVAL_UNDEF(&_19$$40);
	ZVAL_UNDEF(&_20$$40);
	ZVAL_UNDEF(&_11$$41);
	ZVAL_UNDEF(&_12$$41);
	ZVAL_UNDEF(&_15$$42);
	ZVAL_UNDEF(&_16$$42);
	ZVAL_UNDEF(&_21$$43);
	ZVAL_UNDEF(&_22$$43);
	ZEND_TLS zephir_method_cache _zephir_call_cache[17];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &column);
	ZEPHIR_CALL_METHOD_CACHED(&columnSql, this_ptr, "checkColumnTypeSql", &_zephir_call_cache[0], column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&columnType, this_ptr, "checkColumnType", &_zephir_call_cache[1], column);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&columnType, 14)) { goto zephir_switch_0_clause_0; }
	if (ZEPHIR_IS_LONG(&columnType, 11)) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_LONG(&columnType, 8)) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_LONG(&columnType, 5)) { goto zephir_switch_0_clause_3; }
	if (ZEPHIR_IS_LONG(&columnType, 1)) { goto zephir_switch_0_clause_4; }
	if (ZEPHIR_IS_LONG(&columnType, 4)) { goto zephir_switch_0_clause_5; }
	if (ZEPHIR_IS_LONG(&columnType, 3)) { goto zephir_switch_0_clause_6; }
	if (ZEPHIR_IS_LONG(&columnType, 9)) { goto zephir_switch_0_clause_7; }
	if (ZEPHIR_IS_LONG(&columnType, 7)) { goto zephir_switch_0_clause_8; }
	if (ZEPHIR_IS_LONG(&columnType, 0)) { goto zephir_switch_0_clause_9; }
	if (ZEPHIR_IS_LONG(&columnType, 13)) { goto zephir_switch_0_clause_10; }
	if (ZEPHIR_IS_LONG(&columnType, 12)) { goto zephir_switch_0_clause_11; }
	if (ZEPHIR_IS_LONG(&columnType, 6)) { goto zephir_switch_0_clause_12; }
	if (ZEPHIR_IS_LONG(&columnType, 17)) { goto zephir_switch_0_clause_13; }
	if (ZEPHIR_IS_LONG(&columnType, 10)) { goto zephir_switch_0_clause_14; }
	if (ZEPHIR_IS_LONG(&columnType, 2)) { goto zephir_switch_0_clause_15; }
	goto zephir_switch_0_clause_16;
	zephir_switch_0_clause_0: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("BIGINT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_0$$3, column, "isUnsigned", &_zephir_call_cache[2]);
		zephir_check_call_status();
		if (zephir_is_true(&_0$$3)) {
			zephir_concat_self_str(&columnSql, SL(" UNSIGNED"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_1: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("BLOB"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_2: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("TINYINT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_3: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("CHARACTER"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_1$$10, this_ptr, "getColumnSize", &_zephir_call_cache[3], column);
		zephir_check_call_status();
		zephir_concat_self(&columnSql, &_1$$10);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_4: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("DATE"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_5: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("DATETIME"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_6: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("NUMERIC"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_2$$16, this_ptr, "getColumnSizeAndScale", &_zephir_call_cache[4], column);
		zephir_check_call_status();
		zephir_concat_self(&columnSql, &_2$$16);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_7: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("DOUBLE"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_3$$18, column, "isUnsigned", &_zephir_call_cache[5]);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$18)) {
			zephir_concat_self_str(&columnSql, SL(" UNSIGNED"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_8: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("FLOAT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_9: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("INTEGER"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_10: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("LONGBLOB"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_11: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("MEDIUMBLOB"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_12: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("TEXT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_13: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("TIMESTAMP"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_14: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("TINYBLOB"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_15: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("VARCHAR"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_4$$35, this_ptr, "getColumnSize", &_zephir_call_cache[6], column);
		zephir_check_call_status();
		zephir_concat_self(&columnSql, &_4$$35);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_16: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			ZEPHIR_INIT_VAR(&_5$$38);
			object_init_ex(&_5$$38, phalcon_db_exceptions_unrecognizeddatatype_ce);
			ZEPHIR_CALL_METHOD_CACHED(&_6$$38, column, "getName", &_zephir_call_cache[7]);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_7$$38);
			ZVAL_STRING(&_7$$38, "SQLite");
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_5$$38, "__construct", &_zephir_call_cache[8], &_7$$38, &_6$$38);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$38, "phalcon/Db/Dialect/Sqlite.zep", 585);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&typeValues, column, "getTypeValues", &_zephir_call_cache[9]);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&typeValues))) {
			if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(&valueSql$$40);
				ZVAL_STRING(&valueSql$$40, "");
				if (Z_TYPE_P(&typeValues) == IS_STRING) {
					ZEPHIR_INIT_VAR(&_9$$40);
					zephir_string_to_char_array(&_9$$40, &typeValues);
					_8$$40 = &_9$$40;
				} else {
					_8$$40 = &typeValues;
				}
				zephir_is_iterable(_8$$40, 0, "phalcon/Db/Dialect/Sqlite.zep", 599);
				if (Z_TYPE_P(_8$$40) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_8$$40), _10$$40)
					{
						ZEPHIR_INIT_NVAR(&value$$40);
						ZVAL_COPY(&value$$40, _10$$40);
						ZEPHIR_CALL_METHOD_CACHED(&_11$$41, this_ptr, "escapeStringLiteral", &_zephir_call_cache[10], &value$$40);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_12$$41);
						ZEPHIR_CONCAT_SVS(&_12$$41, "'", &_11$$41, "', ");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&valueSql$$40, &_12$$41);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _8$$40, "rewind", &_zephir_call_cache[11]);
					zephir_check_call_status();
					_14$$40 = 1;
					while (1) {
						if (_14$$40) {
							_14$$40 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _8$$40, "next", &_zephir_call_cache[12]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_13$$40, _8$$40, "valid", &_zephir_call_cache[13]);
						zephir_check_call_status();
						if (!zend_is_true(&_13$$40)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&value$$40, _8$$40, "current", &_zephir_call_cache[14]);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&_15$$42, this_ptr, "escapeStringLiteral", &_zephir_call_cache[15], &value$$40);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_16$$42);
							ZEPHIR_CONCAT_SVS(&_16$$42, "'", &_15$$42, "', ");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_concat_self(&valueSql$$40, &_16$$42);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&value$$40);
				ZVAL_LONG(&_17$$40, 0);
				ZVAL_LONG(&_18$$40, -2);
				ZEPHIR_INIT_VAR(&_19$$40);
				zephir_substr(&_19$$40, &valueSql$$40, 0 , -2 , 0);
				ZEPHIR_INIT_VAR(&_20$$40);
				ZEPHIR_CONCAT_SVS(&_20$$40, "(", &_19$$40, ")");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&columnSql, &_20$$40);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CALL_METHOD_CACHED(&_21$$43, this_ptr, "escapeStringLiteral", &_zephir_call_cache[16], &typeValues);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_22$$43);
				ZEPHIR_CONCAT_SVS(&_22$$43, "('", &_21$$43, "')");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&columnSql, &_22$$43);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		}
	zephir_switch_0_end: ;

	RETURN_CCTOR(&columnSql);
}

/**
 * Generates the SQL to get query list of indexes
 *
 * ```php
 * print_r(
 *     $dialect->listIndexesSql("blog")
 * );
 * ```
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listIndexesSql)
{
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, keyName_zv, _0, _1, _2$$3, _3$$3;
	zend_string *table = NULL, *schema = NULL, *keyName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_UNDEF(&keyName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&sql);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
		Z_PARAM_STR_OR_NULL(keyName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
	if (!schema) {
		ZEPHIR_INIT_VAR(&schema_zv);
	} else {
		zephir_memory_observe(&schema_zv);
	ZVAL_STR_COPY(&schema_zv, schema);
	}
	if (!keyName) {
		ZEPHIR_INIT_VAR(&keyName_zv);
	} else {
		zephir_memory_observe(&keyName_zv);
	ZVAL_STR_COPY(&keyName_zv, keyName);
	}
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "escape", &_zephir_call_cache[0], &table_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "SELECT sql FROM sqlite_master WHERE type = 'index' AND tbl_name = ", &_0, " COLLATE NOCASE");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&sql, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(ZEPHIR_IS_EMPTY(&keyName_zv))) {
		ZEPHIR_CALL_METHOD_CACHED(&_2$$3, this_ptr, "escape", &_zephir_call_cache[1], &keyName_zv);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, " AND name = ", &_2$$3, " COLLATE NOCASE");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&sql, &_3$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(&sql);
}

/**
 * List all tables in database
 *
 * ```php
 * print_r(
 *     $dialect->listTables("blog")
 * );
 * ```
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listTables)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval schemaName_zv;
	zend_string *schemaName = NULL;

	ZVAL_UNDEF(&schemaName_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	RETURN_MM_STRING("SELECT tbl_name FROM sqlite_master WHERE type = 'table' ORDER BY tbl_name");
}

/**
 * Generates the SQL to list all views of a schema or user
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listViews)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval schemaName_zv;
	zend_string *schemaName = NULL;

	ZVAL_UNDEF(&schemaName_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	RETURN_MM_STRING("SELECT tbl_name FROM sqlite_master WHERE type = 'view' ORDER BY tbl_name");
}

/**
 * Generates SQL to modify a column in a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, modifyColumn)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, _0;
	zend_string *tableName = NULL, *schemaName = NULL;

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&currentColumn_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(currentColumn, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	column = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		currentColumn = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	if (!currentColumn) {
		currentColumn = &currentColumn_sub;
		currentColumn = &__$null;
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_db_exceptions_sqlitealtercolumnnotsupported_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 658);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Appends a `RETURNING` clause to the supplied INSERT/UPDATE/DELETE
 * statement. Supported by SQLite 3.35+. Pass `["*"]` for `RETURNING *`,
 * or a list of column names.
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, returning)
{
	zval _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval columns;
	zval sqlQuery_zv, *columns_param = NULL, first, _3, _0$$3, _1$$4;
	zend_string *sqlQuery = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery_zv);
	ZVAL_UNDEF(&first);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_2$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(sqlQuery)
		ZEPHIR_Z_PARAM_ARRAY(columns, columns_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	columns_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&sqlQuery_zv);
	ZVAL_STR_COPY(&sqlQuery_zv, sqlQuery);
	zephir_get_arrval(&columns, columns_param);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&columns))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_db_exceptions_returningrequirescolumn_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_0$$3, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Db/Dialect/Sqlite.zep", 671);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_fast_count_int(&columns) == 1) {
		zephir_memory_observe(&_1$$4);
		zephir_array_fetch_long(&_1$$4, &columns, 0, PH_NOISY, "phalcon/Db/Dialect/Sqlite.zep", 675);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_cast_to_string(&_2$$4, &_1$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&first, &_2$$4);
		if (ZEPHIR_IS_STRING(&first, "*")) {
			ZEPHIR_CONCAT_VS(return_value, &sqlQuery_zv, " RETURNING *");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "getColumnList", &_zephir_call_cache[1], &columns);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &sqlQuery_zv, " RETURNING ", &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * SQLite cannot modify existing columns or add/drop foreign keys, primary
 * keys, or check constraints through `ALTER TABLE`; those operations throw
 * a dedicated `Sqlite*NotSupported` exception.
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, supportsAlterTable)
{

	RETURN_BOOL(0);
}

/**
 * SQLite (3.35+) supports the `RETURNING` clause.
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, supportsReturning)
{

	RETURN_BOOL(1);
}

/**
 * SQLite has no row-level shared-lock construct, so the original query
 * is returned unchanged regardless of the `modifier` argument.
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, sharedLock)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval sqlQuery_zv, modifier_zv;
	zend_string *sqlQuery = NULL, *modifier = NULL;

	ZVAL_UNDEF(&sqlQuery_zv);
	ZVAL_UNDEF(&modifier_zv);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(sqlQuery)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(modifier)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&sqlQuery_zv);
	ZVAL_STR_COPY(&sqlQuery_zv, sqlQuery);
	if (!modifier) {
		modifier = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&modifier_zv);
		ZVAL_STR(&modifier_zv, modifier);
	} else {
		zephir_memory_observe(&modifier_zv);
	ZVAL_STR_COPY(&modifier_zv, modifier);
	}
	RETURN_MM_STR(zend_string_copy(sqlQuery));
}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * ```php
 * echo $dialect->tableExists("posts", "blog");
 *
 * echo $dialect->tableExists("posts");
 * ```
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, tableExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, _0;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(tableName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "escapeStringLiteral", &_zephir_call_cache[0], &tableName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='table' AND tbl_name='", &_0, "'");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates the SQL to describe the table creation options
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, tableOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval table_zv, schema_zv;
	zend_string *table = NULL, *schema = NULL;

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
	if (!schema) {
		ZEPHIR_INIT_VAR(&schema_zv);
	} else {
		zephir_memory_observe(&schema_zv);
	ZVAL_STR_COPY(&schema_zv, schema);
	}
	RETURN_MM_STRING("");
}

/**
 * Generates SQL to truncate a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, truncateTable)
{
	zval table;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval tableName_zv, schemaName_zv;
	zend_string *tableName = NULL, *schemaName = NULL;

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&table);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	if (!(ZEPHIR_IS_EMPTY(&schemaName_zv))) {
		ZEPHIR_INIT_VAR(&table);
		ZEPHIR_CONCAT_SVSVS(&table, "\"", &schemaName_zv, "\".\"", &tableName_zv, "\"");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&table);
		ZEPHIR_CONCAT_SVS(&table, "\"", &tableName_zv, "\"");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CONCAT_SV(return_value, "DELETE FROM ", &table);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL checking for the existence of a schema.view
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, viewExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval viewName_zv, schemaName_zv, _0;
	zend_string *viewName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(viewName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&viewName_zv);
	ZVAL_STR_COPY(&viewName_zv, viewName);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "escapeStringLiteral", &_zephir_call_cache[0], &viewName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='view' AND tbl_name='", &_0, "'");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Db_Dialect_Sqlite(zend_class_entry *class_type)
{
		zval _1$$3, _6$$5;
	zval _0, _3, _5, _2$$3, _4$$4, _7$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$5);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("guardedOperators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 9, 0);
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "@@");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "@>");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "<@");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "&&");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "||");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "->");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "->>");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "#>");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "#>>");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("guardedOperators"), &_1$$3);
		}
		zephir_read_property_ex(&_3, this_ptr, ZEND_STRL("customFunctions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_3) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_4$$4);
			array_init(&_4$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("customFunctions"), &_4$$4);
		}
		zephir_read_property_ex(&_5, this_ptr, ZEND_STRL("supportedOperators"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_5) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_6$$5);
			zephir_create_array(&_6$$5, 3, 0);
			ZEPHIR_INIT_VAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "||");
			zephir_array_fast_append(&_6$$5, &_7$$5);
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "->");
			zephir_array_fast_append(&_6$$5, &_7$$5);
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "->>");
			zephir_array_fast_append(&_6$$5, &_7$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("supportedOperators"), &_6$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

