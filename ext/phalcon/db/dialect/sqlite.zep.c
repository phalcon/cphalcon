
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
 * For the full copyright and license information, please view the LICENSE.txt
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "ALTER TABLE ", &_0, " ADD COLUMN ");
	zephir_get_strval(&sql, &_1);
	ZEPHIR_CALL_METHOD(&_2, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getgeneratedclause", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVSVV(&_5, "\"", &_2, "\" ", &_3, &_4);
	zephir_concat_self(&sql, &_5);
	ZEPHIR_CALL_METHOD(&_6, column, "isgenerated", NULL, 0);
	zephir_check_call_status();
	_7 = !zephir_is_true(&_6);
	if (_7) {
		ZEPHIR_CALL_METHOD(&_8, column, "hasdefault", NULL, 0);
		zephir_check_call_status();
		_7 = zephir_is_true(&_8);
	}
	if (_7) {
		ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		_9$$3 = Z_TYPE_P(&defaultValue) == IS_OBJECT;
		if (_9$$3) {
			_9$$3 = zephir_instance_of_ev(&defaultValue, phalcon_db_rawvalue_ce);
		}
		if (_9$$3) {
			ZEPHIR_CALL_METHOD(&_11$$4, &defaultValue, "getvalue", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_12$$4);
			ZEPHIR_CONCAT_SV(&_12$$4, " DEFAULT ", &_11$$4);
			zephir_concat_self(&sql, &_12$$4);
		} else {
			ZEPHIR_INIT_VAR(&_10$$3);
			zephir_fast_strtoupper(&_10$$3, &defaultValue);
			if (zephir_memnstr_str(&_10$$3, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Sqlite.zep", 67)) {
				zephir_concat_self_str(&sql, " DEFAULT CURRENT_TIMESTAMP", sizeof(" DEFAULT CURRENT_TIMESTAMP") - 1);
			} else {
				ZEPHIR_CALL_METHOD(&_13$$6, this_ptr, "escapestringliteral", NULL, 0, &defaultValue);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_14$$6);
				ZEPHIR_CONCAT_SVS(&_14$$6, " DEFAULT '", &_13$$6, "'");
				zephir_concat_self(&sql, &_14$$6);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&_15, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_15)) {
		zephir_concat_self_str(&sql, " NOT NULL", sizeof(" NOT NULL") - 1);
	} else {
		zephir_concat_self_str(&sql, " NULL", sizeof(" NULL") - 1);
	}
	ZEPHIR_CALL_METHOD(&_16, column, "isgenerated", NULL, 0);
	zephir_check_call_status();
	_17 = !zephir_is_true(&_16);
	if (_17) {
		ZEPHIR_CALL_METHOD(&_18, column, "isautoincrement", NULL, 0);
		zephir_check_call_status();
		_17 = zephir_is_true(&_18);
	}
	if (_17) {
		zephir_concat_self_str(&sql, " PRIMARY KEY AUTOINCREMENT", sizeof(" PRIMARY KEY AUTOINCREMENT") - 1);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 93);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 101);
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
	ZEPHIR_CALL_METHOD(&indexType, index, "gettype", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&indexType))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SVS(&_0$$3, "CREATE ", &indexType, " INDEX ");
		zephir_get_strval(&sql, &_0$$3);
	} else {
		ZEPHIR_INIT_VAR(&sql);
		ZVAL_STRING(&sql, "CREATE INDEX ");
	}
	if (!(ZEPHIR_IS_EMPTY(&schemaName_zv))) {
		ZEPHIR_CALL_METHOD(&_1$$5, index, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$5);
		ZEPHIR_CONCAT_SVSVS(&_2$$5, "\"", &schemaName_zv, "\".\"", &_1$$5, "\"");
		zephir_concat_self(&sql, &_2$$5);
	} else {
		ZEPHIR_CALL_METHOD(&_3$$6, index, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$6);
		ZEPHIR_CONCAT_SVS(&_4$$6, "\"", &_3$$6, "\"");
		zephir_concat_self(&sql, &_4$$6);
	}
	ZVAL_BOOL(&_6, 0);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getindexcolumnlist", NULL, 0, index, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SVSVS(&_7, " ON \"", &tableName_zv, "\" (", &_5, ")");
	zephir_concat_self(&sql, &_7);
	ZEPHIR_CALL_METHOD(&_8, index, "getwhere", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_8, "")) {
		ZEPHIR_CALL_METHOD(&_9$$7, index, "getwhere", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$7);
		ZEPHIR_CONCAT_SV(&_10$$7, " WHERE ", &_9$$7);
		zephir_concat_self(&sql, &_10$$7);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 141);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createTable)
{
	zval sql;
	zend_bool hasPrimary = 0, _23, _10$$8, _12$$8, _14$$11, _29$$18, _31$$18, _33$$21, _52$$27, _41$$28, _42$$28, _53$$31, _54$$31, _73$$34, _87$$41;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_19 = NULL, *_46 = NULL, *_66 = NULL, *_85 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval tableName_zv, schemaName_zv, *definition_param = NULL, columns, table, temporary, options, createLines, columnLine, column, indexes, index, indexName, indexType, references, reference, defaultValue, referenceSql, onDelete, onUpdate, checks, check, *_2, _22, _90, _91, _0$$5, _1$$6, _3$$7, _4$$7, _6$$7, _8$$7, _21$$7, _9$$8, _11$$8, _13$$8, _15$$11, _16$$12, _17$$12, _18$$14, _20$$14, _24$$17, _25$$17, _26$$17, _27$$17, _39$$17, _28$$18, _30$$18, _32$$18, _34$$21, _35$$22, _36$$22, _37$$24, _38$$24, *_40$$27, _51$$27, _43$$28, _44$$29, _45$$29, _47$$29, _48$$30, _49$$30, _50$$30, _55$$31, _56$$32, _57$$32, _58$$32, _59$$33, _60$$33, _61$$33, *_62$$34, _72$$34, _63$$35, _64$$35, _65$$35, _67$$35, _68$$35, _69$$35, _70$$36, _71$$37, _74$$38, _75$$38, _76$$38, _77$$38, _78$$38, _79$$38, _80$$39, _81$$40, *_82$$41, _86$$41, _83$$42, _84$$42, _88$$43, _89$$43;
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
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_90);
	ZVAL_UNDEF(&_91);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_32$$18);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_35$$22);
	ZVAL_UNDEF(&_36$$22);
	ZVAL_UNDEF(&_37$$24);
	ZVAL_UNDEF(&_38$$24);
	ZVAL_UNDEF(&_51$$27);
	ZVAL_UNDEF(&_43$$28);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_45$$29);
	ZVAL_UNDEF(&_47$$29);
	ZVAL_UNDEF(&_48$$30);
	ZVAL_UNDEF(&_49$$30);
	ZVAL_UNDEF(&_50$$30);
	ZVAL_UNDEF(&_55$$31);
	ZVAL_UNDEF(&_56$$32);
	ZVAL_UNDEF(&_57$$32);
	ZVAL_UNDEF(&_58$$32);
	ZVAL_UNDEF(&_59$$33);
	ZVAL_UNDEF(&_60$$33);
	ZVAL_UNDEF(&_61$$33);
	ZVAL_UNDEF(&_72$$34);
	ZVAL_UNDEF(&_63$$35);
	ZVAL_UNDEF(&_64$$35);
	ZVAL_UNDEF(&_65$$35);
	ZVAL_UNDEF(&_67$$35);
	ZVAL_UNDEF(&_68$$35);
	ZVAL_UNDEF(&_69$$35);
	ZVAL_UNDEF(&_70$$36);
	ZVAL_UNDEF(&_71$$37);
	ZVAL_UNDEF(&_74$$38);
	ZVAL_UNDEF(&_75$$38);
	ZVAL_UNDEF(&_76$$38);
	ZVAL_UNDEF(&_77$$38);
	ZVAL_UNDEF(&_78$$38);
	ZVAL_UNDEF(&_79$$38);
	ZVAL_UNDEF(&_80$$39);
	ZVAL_UNDEF(&_81$$40);
	ZVAL_UNDEF(&_86$$41);
	ZVAL_UNDEF(&_83$$42);
	ZVAL_UNDEF(&_84$$42);
	ZVAL_UNDEF(&_88$$43);
	ZVAL_UNDEF(&_89$$43);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&sql);
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
	ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&temporary);
	ZVAL_BOOL(&temporary, 0);
	zephir_memory_observe(&options);
	if (zephir_array_isset_string_fetch(&options, &definition, SL("options"), 0)) {
		ZEPHIR_OBS_NVAR(&temporary);
		zephir_array_isset_string_fetch(&temporary, &options, SL("temporary"), 0);
	}
	zephir_memory_observe(&columns);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_missingdefinitionkey_ce, "columns", "phalcon/Db/Dialect/Sqlite.zep", 163);
		return;
	}
	if (zephir_is_true(&temporary)) {
		ZEPHIR_INIT_VAR(&_0$$5);
		ZEPHIR_CONCAT_SV(&_0$$5, "CREATE TEMPORARY TABLE ", &table);
		zephir_get_strval(&sql, &_0$$5);
	} else {
		ZEPHIR_INIT_VAR(&_1$$6);
		ZEPHIR_CONCAT_SV(&_1$$6, "CREATE TABLE ", &table);
		zephir_get_strval(&sql, &_1$$6);
	}
	zephir_concat_self_str(&sql, " (\n\t", sizeof(" (\n\t") - 1);
	hasPrimary = 0;
	ZEPHIR_INIT_VAR(&createLines);
	array_init(&createLines);
	zephir_is_iterable(&columns, 0, "phalcon/Db/Dialect/Sqlite.zep", 232);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _2)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _2);
			ZEPHIR_CALL_METHOD(&_3$$7, &column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$7, this_ptr, "getcolumndefinition", &_5, 0, &column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6$$7, this_ptr, "getgeneratedclause", &_7, 0, &column);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&columnLine);
			ZEPHIR_CONCAT_SVSVV(&columnLine, "`", &_3$$7, "` ", &_4$$7, &_6$$7);
			ZEPHIR_CALL_METHOD(&_8$$7, &column, "isgenerated", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_8$$7))) {
				ZEPHIR_CALL_METHOD(&_9$$8, &column, "isprimary", NULL, 0);
				zephir_check_call_status();
				_10$$8 = zephir_is_true(&_9$$8);
				if (_10$$8) {
					_10$$8 = !hasPrimary;
				}
				if (_10$$8) {
					zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY"));
					hasPrimary = 1;
				}
				ZEPHIR_CALL_METHOD(&_11$$8, &column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				_12$$8 = zephir_is_true(&_11$$8);
				if (_12$$8) {
					_12$$8 = hasPrimary;
				}
				if (_12$$8) {
					zephir_concat_self_str(&columnLine, SL(" AUTOINCREMENT"));
				}
				ZEPHIR_CALL_METHOD(&_13$$8, &column, "hasdefault", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_13$$8)) {
					ZEPHIR_CALL_METHOD(&defaultValue, &column, "getdefault", NULL, 0);
					zephir_check_call_status();
					_14$$11 = Z_TYPE_P(&defaultValue) == IS_OBJECT;
					if (_14$$11) {
						_14$$11 = zephir_instance_of_ev(&defaultValue, phalcon_db_rawvalue_ce);
					}
					if (_14$$11) {
						ZEPHIR_CALL_METHOD(&_16$$12, &defaultValue, "getvalue", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_17$$12);
						ZEPHIR_CONCAT_SV(&_17$$12, " DEFAULT ", &_16$$12);
						zephir_concat_self(&columnLine, &_17$$12);
					} else {
						ZEPHIR_INIT_NVAR(&_15$$11);
						zephir_fast_strtoupper(&_15$$11, &defaultValue);
						if (zephir_memnstr_str(&_15$$11, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Sqlite.zep", 209)) {
							zephir_concat_self_str(&columnLine, SL(" DEFAULT CURRENT_TIMESTAMP"));
						} else {
							ZEPHIR_CALL_METHOD(&_18$$14, this_ptr, "escapestringliteral", &_19, 0, &defaultValue);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_20$$14);
							ZEPHIR_CONCAT_SVS(&_20$$14, " DEFAULT '", &_18$$14, "'");
							zephir_concat_self(&columnLine, &_20$$14);
						}
					}
				}
			}
			ZEPHIR_CALL_METHOD(&_21$$7, &column, "isnotnull", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_21$$7)) {
				zephir_concat_self_str(&columnLine, SL(" NOT NULL"));
			} else {
				zephir_concat_self_str(&columnLine, SL(" NULL"));
			}
			zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 226);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
		zephir_check_call_status();
		_23 = 1;
		while (1) {
			if (_23) {
				_23 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_22, &columns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_22)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &columns, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_24$$17, &column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_25$$17, this_ptr, "getcolumndefinition", &_5, 0, &column);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_26$$17, this_ptr, "getgeneratedclause", &_7, 0, &column);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&columnLine);
				ZEPHIR_CONCAT_SVSVV(&columnLine, "`", &_24$$17, "` ", &_25$$17, &_26$$17);
				ZEPHIR_CALL_METHOD(&_27$$17, &column, "isgenerated", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_27$$17))) {
					ZEPHIR_CALL_METHOD(&_28$$18, &column, "isprimary", NULL, 0);
					zephir_check_call_status();
					_29$$18 = zephir_is_true(&_28$$18);
					if (_29$$18) {
						_29$$18 = !hasPrimary;
					}
					if (_29$$18) {
						zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY"));
						hasPrimary = 1;
					}
					ZEPHIR_CALL_METHOD(&_30$$18, &column, "isautoincrement", NULL, 0);
					zephir_check_call_status();
					_31$$18 = zephir_is_true(&_30$$18);
					if (_31$$18) {
						_31$$18 = hasPrimary;
					}
					if (_31$$18) {
						zephir_concat_self_str(&columnLine, SL(" AUTOINCREMENT"));
					}
					ZEPHIR_CALL_METHOD(&_32$$18, &column, "hasdefault", NULL, 0);
					zephir_check_call_status();
					if (zephir_is_true(&_32$$18)) {
						ZEPHIR_CALL_METHOD(&defaultValue, &column, "getdefault", NULL, 0);
						zephir_check_call_status();
						_33$$21 = Z_TYPE_P(&defaultValue) == IS_OBJECT;
						if (_33$$21) {
							_33$$21 = zephir_instance_of_ev(&defaultValue, phalcon_db_rawvalue_ce);
						}
						if (_33$$21) {
							ZEPHIR_CALL_METHOD(&_35$$22, &defaultValue, "getvalue", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_36$$22);
							ZEPHIR_CONCAT_SV(&_36$$22, " DEFAULT ", &_35$$22);
							zephir_concat_self(&columnLine, &_36$$22);
						} else {
							ZEPHIR_INIT_NVAR(&_34$$21);
							zephir_fast_strtoupper(&_34$$21, &defaultValue);
							if (zephir_memnstr_str(&_34$$21, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Sqlite.zep", 209)) {
								zephir_concat_self_str(&columnLine, SL(" DEFAULT CURRENT_TIMESTAMP"));
							} else {
								ZEPHIR_CALL_METHOD(&_37$$24, this_ptr, "escapestringliteral", &_19, 0, &defaultValue);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_38$$24);
								ZEPHIR_CONCAT_SVS(&_38$$24, " DEFAULT '", &_37$$24, "'");
								zephir_concat_self(&columnLine, &_38$$24);
							}
						}
					}
				}
				ZEPHIR_CALL_METHOD(&_39$$17, &column, "isnotnull", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_39$$17)) {
					zephir_concat_self_str(&columnLine, SL(" NOT NULL"));
				} else {
					zephir_concat_self_str(&columnLine, SL(" NULL"));
				}
				zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 226);
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	zephir_memory_observe(&indexes);
	if (zephir_array_isset_string_fetch(&indexes, &definition, SL("indexes"), 0)) {
		zephir_is_iterable(&indexes, 0, "phalcon/Db/Dialect/Sqlite.zep", 248);
		if (Z_TYPE_P(&indexes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&indexes), _40$$27)
			{
				ZEPHIR_INIT_NVAR(&index);
				ZVAL_COPY(&index, _40$$27);
				ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
				zephir_check_call_status();
				_41$$28 = ZEPHIR_IS_STRING(&indexName, "PRIMARY");
				if (_41$$28) {
					_41$$28 = !hasPrimary;
				}
				if (_41$$28) {
					ZVAL_BOOL(&_45$$29, 0);
					ZEPHIR_CALL_METHOD(&_44$$29, this_ptr, "getindexcolumnlist", &_46, 0, &index, &_45$$29);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_47$$29);
					ZEPHIR_CONCAT_SVS(&_47$$29, "PRIMARY KEY (", &_44$$29, ")");
					zephir_array_append(&createLines, &_47$$29, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 242);
				} else {
					_42$$28 = !(ZEPHIR_IS_EMPTY(&indexType));
					if (_42$$28) {
						ZEPHIR_INIT_NVAR(&_43$$28);
						zephir_fast_strtoupper(&_43$$28, &indexType);
						_42$$28 = zephir_memnstr_str(&_43$$28, SL("UNIQUE"), "phalcon/Db/Dialect/Sqlite.zep", 243);
					}
					if (_42$$28) {
						ZVAL_BOOL(&_49$$30, 0);
						ZEPHIR_CALL_METHOD(&_48$$30, this_ptr, "getindexcolumnlist", &_46, 0, &index, &_49$$30);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_50$$30);
						ZEPHIR_CONCAT_SVS(&_50$$30, "UNIQUE (", &_48$$30, ")");
						zephir_array_append(&createLines, &_50$$30, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 245);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &indexes, "rewind", NULL, 0);
			zephir_check_call_status();
			_52$$27 = 1;
			while (1) {
				if (_52$$27) {
					_52$$27 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &indexes, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_51$$27, &indexes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_51$$27)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&index, &indexes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
					zephir_check_call_status();
					_53$$31 = ZEPHIR_IS_STRING(&indexName, "PRIMARY");
					if (_53$$31) {
						_53$$31 = !hasPrimary;
					}
					if (_53$$31) {
						ZVAL_BOOL(&_57$$32, 0);
						ZEPHIR_CALL_METHOD(&_56$$32, this_ptr, "getindexcolumnlist", &_46, 0, &index, &_57$$32);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_58$$32);
						ZEPHIR_CONCAT_SVS(&_58$$32, "PRIMARY KEY (", &_56$$32, ")");
						zephir_array_append(&createLines, &_58$$32, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 242);
					} else {
						_54$$31 = !(ZEPHIR_IS_EMPTY(&indexType));
						if (_54$$31) {
							ZEPHIR_INIT_NVAR(&_55$$31);
							zephir_fast_strtoupper(&_55$$31, &indexType);
							_54$$31 = zephir_memnstr_str(&_55$$31, SL("UNIQUE"), "phalcon/Db/Dialect/Sqlite.zep", 243);
						}
						if (_54$$31) {
							ZVAL_BOOL(&_60$$33, 0);
							ZEPHIR_CALL_METHOD(&_59$$33, this_ptr, "getindexcolumnlist", &_46, 0, &index, &_60$$33);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_61$$33);
							ZEPHIR_CONCAT_SVS(&_61$$33, "UNIQUE (", &_59$$33, ")");
							zephir_array_append(&createLines, &_61$$33, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 245);
						}
					}
			}
		}
		ZEPHIR_INIT_NVAR(&index);
	}
	zephir_memory_observe(&references);
	if (zephir_array_isset_string_fetch(&references, &definition, SL("references"), 0)) {
		zephir_is_iterable(&references, 0, "phalcon/Db/Dialect/Sqlite.zep", 270);
		if (Z_TYPE_P(&references) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&references), _62$$34)
			{
				ZEPHIR_INIT_NVAR(&reference);
				ZVAL_COPY(&reference, _62$$34);
				ZEPHIR_CALL_METHOD(&_63$$35, &reference, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_65$$35, &reference, "getcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_64$$35, this_ptr, "getcolumnlist", &_66, 119, &_65$$35);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_67$$35, &reference, "getreferencedtable", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_69$$35, &reference, "getreferencedcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_68$$35, this_ptr, "getcolumnlist", &_66, 119, &_69$$35);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&referenceSql);
				ZEPHIR_CONCAT_SVSVSSVSVS(&referenceSql, "CONSTRAINT `", &_63$$35, "` FOREIGN KEY (", &_64$$35, ")", " REFERENCES `", &_67$$35, "`(", &_68$$35, ")");
				ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
					ZEPHIR_INIT_NVAR(&_70$$36);
					ZEPHIR_CONCAT_SV(&_70$$36, " ON DELETE ", &onDelete);
					zephir_concat_self(&referenceSql, &_70$$36);
				}
				ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
					ZEPHIR_INIT_NVAR(&_71$$37);
					ZEPHIR_CONCAT_SV(&_71$$37, " ON UPDATE ", &onUpdate);
					zephir_concat_self(&referenceSql, &_71$$37);
				}
				zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 268);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &references, "rewind", NULL, 0);
			zephir_check_call_status();
			_73$$34 = 1;
			while (1) {
				if (_73$$34) {
					_73$$34 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &references, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_72$$34, &references, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_72$$34)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&reference, &references, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_74$$38, &reference, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_76$$38, &reference, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_75$$38, this_ptr, "getcolumnlist", &_66, 119, &_76$$38);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_77$$38, &reference, "getreferencedtable", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_79$$38, &reference, "getreferencedcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_78$$38, this_ptr, "getcolumnlist", &_66, 119, &_79$$38);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&referenceSql);
					ZEPHIR_CONCAT_SVSVSSVSVS(&referenceSql, "CONSTRAINT `", &_74$$38, "` FOREIGN KEY (", &_75$$38, ")", " REFERENCES `", &_77$$38, "`(", &_78$$38, ")");
					ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
						ZEPHIR_INIT_NVAR(&_80$$39);
						ZEPHIR_CONCAT_SV(&_80$$39, " ON DELETE ", &onDelete);
						zephir_concat_self(&referenceSql, &_80$$39);
					}
					ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
						ZEPHIR_INIT_NVAR(&_81$$40);
						ZEPHIR_CONCAT_SV(&_81$$40, " ON UPDATE ", &onUpdate);
						zephir_concat_self(&referenceSql, &_81$$40);
					}
					zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 268);
			}
		}
		ZEPHIR_INIT_NVAR(&reference);
	}
	zephir_memory_observe(&checks);
	if (zephir_array_isset_string_fetch(&checks, &definition, SL("checks"), 0)) {
		zephir_is_iterable(&checks, 0, "phalcon/Db/Dialect/Sqlite.zep", 279);
		if (Z_TYPE_P(&checks) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&checks), _82$$41)
			{
				ZEPHIR_INIT_NVAR(&check);
				ZVAL_COPY(&check, _82$$41);
				ZEPHIR_INIT_NVAR(&_84$$42);
				ZVAL_STRING(&_84$$42, "`");
				ZEPHIR_CALL_METHOD(&_83$$42, this_ptr, "getcheckclause", &_85, 0, &check, &_84$$42);
				zephir_check_call_status();
				zephir_array_append(&createLines, &_83$$42, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 277);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &checks, "rewind", NULL, 0);
			zephir_check_call_status();
			_87$$41 = 1;
			while (1) {
				if (_87$$41) {
					_87$$41 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &checks, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_86$$41, &checks, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_86$$41)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&check, &checks, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_89$$43);
					ZVAL_STRING(&_89$$43, "`");
					ZEPHIR_CALL_METHOD(&_88$$43, this_ptr, "getcheckclause", &_85, 0, &check, &_89$$43);
					zephir_check_call_status();
					zephir_array_append(&createLines, &_88$$43, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 277);
			}
		}
		ZEPHIR_INIT_NVAR(&check);
	}
	ZEPHIR_INIT_VAR(&_90);
	zephir_fast_join_str(&_90, SL(",\n\t"), &createLines);
	ZEPHIR_INIT_VAR(&_91);
	ZEPHIR_CONCAT_VS(&_91, &_90, "\n)");
	zephir_concat_self(&sql, &_91);
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to create a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createView)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval viewName_zv, *definition_param = NULL, schemaName_zv, viewSql, _0;
	zend_string *viewName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&viewSql);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&definition);
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
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&viewSql, &definition, SL("sql"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_missingdefinitionkey_ce, "sql", "phalcon/Db/Dialect/Sqlite.zep", 294);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &viewName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSV(return_value, "CREATE VIEW ", &_0, " AS ", &viewSql);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "escapestringliteral", NULL, 0, &table_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA table_xinfo('", &_0, "')");
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&index_zv);
	ZVAL_STR_COPY(&index_zv, index);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "escapestringliteral", NULL, 0, &index_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA index_info('", &_0, "')");
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "escapestringliteral", NULL, 0, &table_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA index_list('", &_0, "')");
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "escapestringliteral", NULL, 0, &table_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA foreign_key_list('", &_0, "')");
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP COLUMN \"", &columnName_zv, "\"");
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 366);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 374);
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
		return;
	}
	ZEPHIR_CONCAT_SVS(return_value, "DROP INDEX \"", &indexName_zv, "\"");
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 394);
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
	ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	if (ifExists) {
		ZEPHIR_CONCAT_SV(return_value, "DROP TABLE IF EXISTS ", &table);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SV(return_value, "DROP TABLE ", &table);
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
	ZEPHIR_CALL_METHOD(&view, this_ptr, "preparetable", NULL, 0, &viewName_zv, &schemaName_zv);
	zephir_check_call_status();
	if (ifExists) {
		ZEPHIR_CONCAT_SV(return_value, "DROP VIEW IF EXISTS ", &view);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SV(return_value, "DROP VIEW ", &view);
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
	zend_bool _13$$40;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, columnType, columnSql, typeValues, _0$$3, _1$$10, _2$$16, _3$$18, _4$$35, _5$$38, _6$$38, _7$$38, value$$40, valueSql$$40, *_8$$40, _12$$40, _16$$40, _17$$40, _18$$40, _19$$40, _9$$41, _11$$41, _14$$42, _15$$42, _20$$43, _21$$43;
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
	ZVAL_UNDEF(&_12$$40);
	ZVAL_UNDEF(&_16$$40);
	ZVAL_UNDEF(&_17$$40);
	ZVAL_UNDEF(&_18$$40);
	ZVAL_UNDEF(&_19$$40);
	ZVAL_UNDEF(&_9$$41);
	ZVAL_UNDEF(&_11$$41);
	ZVAL_UNDEF(&_14$$42);
	ZVAL_UNDEF(&_15$$42);
	ZVAL_UNDEF(&_20$$43);
	ZVAL_UNDEF(&_21$$43);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &column);
	ZEPHIR_CALL_METHOD(&columnSql, this_ptr, "checkcolumntypesql", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnType, this_ptr, "checkcolumntype", NULL, 0, column);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(&columnType, 14)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("BIGINT"));
			}
			ZEPHIR_CALL_METHOD(&_0$$3, column, "isunsigned", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_0$$3)) {
				zephir_concat_self_str(&columnSql, SL(" UNSIGNED"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 11)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("BLOB"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 8)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TINYINT"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 5)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHARACTER"));
			}
			ZEPHIR_CALL_METHOD(&_1$$10, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_1$$10);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 1)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DATE"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 4)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DATETIME"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 3)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("NUMERIC"));
			}
			ZEPHIR_CALL_METHOD(&_2$$16, this_ptr, "getcolumnsizeandscale", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_2$$16);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 9)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DOUBLE"));
			}
			ZEPHIR_CALL_METHOD(&_3$$18, column, "isunsigned", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_3$$18)) {
				zephir_concat_self_str(&columnSql, SL(" UNSIGNED"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 7)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("FLOAT"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 0)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("INTEGER"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 13)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("LONGBLOB"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 12)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("MEDIUMBLOB"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 6)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TEXT"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 17)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TIMESTAMP"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 10)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TINYBLOB"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 2)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("VARCHAR"));
			}
			ZEPHIR_CALL_METHOD(&_4$$35, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_4$$35);
			break;
		}
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			ZEPHIR_INIT_VAR(&_5$$38);
			object_init_ex(&_5$$38, phalcon_db_exceptions_unrecognizeddatatype_ce);
			ZEPHIR_CALL_METHOD(&_6$$38, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_7$$38);
			ZVAL_STRING(&_7$$38, "SQLite");
			ZEPHIR_CALL_METHOD(NULL, &_5$$38, "__construct", NULL, 0, &_7$$38, &_6$$38);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$38, "phalcon/Db/Dialect/Sqlite.zep", 583);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&typeValues, column, "gettypevalues", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&typeValues))) {
			if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(&valueSql$$40);
				ZVAL_STRING(&valueSql$$40, "");
				zephir_is_iterable(&typeValues, 0, "phalcon/Db/Dialect/Sqlite.zep", 597);
				if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&typeValues), _8$$40)
					{
						ZEPHIR_INIT_NVAR(&value$$40);
						ZVAL_COPY(&value$$40, _8$$40);
						ZEPHIR_CALL_METHOD(&_9$$41, this_ptr, "escapestringliteral", &_10, 0, &value$$40);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_11$$41);
						ZEPHIR_CONCAT_SVS(&_11$$41, "'", &_9$$41, "', ");
						zephir_concat_self(&valueSql$$40, &_11$$41);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &typeValues, "rewind", NULL, 0);
					zephir_check_call_status();
					_13$$40 = 1;
					while (1) {
						if (_13$$40) {
							_13$$40 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &typeValues, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_12$$40, &typeValues, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_12$$40)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&value$$40, &typeValues, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_14$$42, this_ptr, "escapestringliteral", &_10, 0, &value$$40);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_15$$42);
							ZEPHIR_CONCAT_SVS(&_15$$42, "'", &_14$$42, "', ");
							zephir_concat_self(&valueSql$$40, &_15$$42);
					}
				}
				ZEPHIR_INIT_NVAR(&value$$40);
				ZVAL_LONG(&_16$$40, 0);
				ZVAL_LONG(&_17$$40, -2);
				ZEPHIR_INIT_VAR(&_18$$40);
				zephir_substr(&_18$$40, &valueSql$$40, 0 , -2 , 0);
				ZEPHIR_INIT_VAR(&_19$$40);
				ZEPHIR_CONCAT_SVS(&_19$$40, "(", &_18$$40, ")");
				zephir_concat_self(&columnSql, &_19$$40);
			} else {
				ZEPHIR_CALL_METHOD(&_20$$43, this_ptr, "escapestringliteral", &_10, 0, &typeValues);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_21$$43);
				ZEPHIR_CONCAT_SVS(&_21$$43, "('", &_20$$43, "')");
				zephir_concat_self(&columnSql, &_21$$43);
			}
		}
	} while(0);

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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "escape", NULL, 115, &table_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "SELECT sql FROM sqlite_master WHERE type = 'index' AND tbl_name = ", &_0, " COLLATE NOCASE");
	zephir_get_strval(&sql, &_1);
	if (!(ZEPHIR_IS_EMPTY(&keyName_zv))) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "escape", NULL, 115, &keyName_zv);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, " AND name = ", &_2$$3, " COLLATE NOCASE");
		zephir_concat_self(&sql, &_3$$3);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 656);
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Db/Dialect/Sqlite.zep", 669);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_fast_count_int(&columns) == 1) {
		zephir_memory_observe(&_1$$4);
		zephir_array_fetch_long(&_1$$4, &columns, 0, PH_NOISY, "phalcon/Db/Dialect/Sqlite.zep", 673);
		zephir_cast_to_string(&_2$$4, &_1$$4);
		ZEPHIR_CPY_WRT(&first, &_2$$4);
		if (ZEPHIR_IS_STRING(&first, "*")) {
			ZEPHIR_CONCAT_VS(return_value, &sqlQuery_zv, " RETURNING *");
			RETURN_MM();
		}
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getcolumnlist", NULL, 119, &columns);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &sqlQuery_zv, " RETURNING ", &_3);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "escapestringliteral", NULL, 0, &tableName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='table' AND tbl_name='", &_0, "'");
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
	} else {
		ZEPHIR_INIT_NVAR(&table);
		ZEPHIR_CONCAT_SVS(&table, "\"", &tableName_zv, "\"");
	}
	ZEPHIR_CONCAT_SV(return_value, "DELETE FROM ", &table);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "escapestringliteral", NULL, 0, &viewName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='view' AND tbl_name='", &_0, "'");
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

