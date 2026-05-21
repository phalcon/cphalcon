
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
#include "ext/spl/spl_exceptions.h"


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
	return SUCCESS;
}

/**
 * Generates SQL to add a column to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addColumn)
{
	zend_bool _7, _18, _9$$3;
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *column, column_sub, defaultValue, _0, _1, _2, _3, _4, _5, _6, _8, _16, _17, _19, _10$$3, _11$$4, _12$$4, _13$$6, _14$$6, _15$$6;
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
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
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
		ZEPHIR_INIT_VAR(&_10$$3);
		zephir_fast_strtoupper(&_10$$3, &defaultValue);
		if (_9$$3) {
			ZEPHIR_CALL_METHOD(&_11$$4, &defaultValue, "getvalue", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_12$$4);
			ZEPHIR_CONCAT_SV(&_12$$4, " DEFAULT ", &_11$$4);
			zephir_concat_self(&sql, &_12$$4);
		} else if (zephir_memnstr_str(&_10$$3, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Sqlite.zep", 62)) {
			zephir_concat_self_str(&sql, " DEFAULT CURRENT_TIMESTAMP", sizeof(" DEFAULT CURRENT_TIMESTAMP") - 1);
		} else {
			ZEPHIR_INIT_VAR(&_13$$6);
			ZVAL_STRING(&_13$$6, "\"");
			ZEPHIR_CALL_FUNCTION(&_14$$6, "addcslashes", NULL, 342, &defaultValue, &_13$$6);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_15$$6);
			ZEPHIR_CONCAT_SVS(&_15$$6, " DEFAULT \"", &_14$$6, "\"");
			zephir_concat_self(&sql, &_15$$6);
		}
	}
	ZEPHIR_CALL_METHOD(&_16, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_16)) {
		zephir_concat_self_str(&sql, " NOT NULL", sizeof(" NOT NULL") - 1);
	} else {
		zephir_concat_self_str(&sql, " NULL", sizeof(" NULL") - 1);
	}
	ZEPHIR_CALL_METHOD(&_17, column, "isgenerated", NULL, 0);
	zephir_check_call_status();
	_18 = !zephir_is_true(&_17);
	if (_18) {
		ZEPHIR_CALL_METHOD(&_19, column, "isautoincrement", NULL, 0);
		zephir_check_call_status();
		_18 = zephir_is_true(&_19);
	}
	if (_18) {
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 348);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 88);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 349);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 96);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 350);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 136);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createTable)
{
	zval sql;
	zend_bool hasPrimary = 0, _11$$8, _13$$8, _15$$11, _29$$18, _31$$18, _33$$21, _43$$28, _44$$28, _53$$31, _54$$31;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_21 = NULL, *_48 = NULL, *_67 = NULL, *_85 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval tableName_zv, schemaName_zv, *definition_param = NULL, columns, table, temporary, options, createLines, columnLine, column, indexes, index, indexName, indexType, references, reference, defaultValue, referenceSql, onDelete, onUpdate, checks, check, *_2, _3, _88, _89, _0$$5, _1$$6, _4$$7, _5$$7, _7$$7, _9$$7, _23$$7, _10$$8, _12$$8, _14$$8, _16$$11, _17$$12, _18$$12, _19$$14, _20$$14, _22$$14, _24$$17, _25$$17, _26$$17, _27$$17, _40$$17, _28$$18, _30$$18, _32$$18, _34$$21, _35$$22, _36$$22, _37$$24, _38$$24, _39$$24, *_41$$27, _42$$27, _45$$28, _46$$29, _47$$29, _49$$29, _50$$30, _51$$30, _52$$30, _55$$31, _56$$32, _57$$32, _58$$32, _59$$33, _60$$33, _61$$33, *_62$$34, _63$$34, _64$$35, _65$$35, _66$$35, _68$$35, _69$$35, _70$$35, _71$$36, _72$$37, _73$$38, _74$$38, _75$$38, _76$$38, _77$$38, _78$$38, _79$$39, _80$$40, *_81$$41, _82$$41, _83$$42, _84$$42, _86$$43, _87$$43;
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_88);
	ZVAL_UNDEF(&_89);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_40$$17);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_32$$18);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_35$$22);
	ZVAL_UNDEF(&_36$$22);
	ZVAL_UNDEF(&_37$$24);
	ZVAL_UNDEF(&_38$$24);
	ZVAL_UNDEF(&_39$$24);
	ZVAL_UNDEF(&_42$$27);
	ZVAL_UNDEF(&_45$$28);
	ZVAL_UNDEF(&_46$$29);
	ZVAL_UNDEF(&_47$$29);
	ZVAL_UNDEF(&_49$$29);
	ZVAL_UNDEF(&_50$$30);
	ZVAL_UNDEF(&_51$$30);
	ZVAL_UNDEF(&_52$$30);
	ZVAL_UNDEF(&_55$$31);
	ZVAL_UNDEF(&_56$$32);
	ZVAL_UNDEF(&_57$$32);
	ZVAL_UNDEF(&_58$$32);
	ZVAL_UNDEF(&_59$$33);
	ZVAL_UNDEF(&_60$$33);
	ZVAL_UNDEF(&_61$$33);
	ZVAL_UNDEF(&_63$$34);
	ZVAL_UNDEF(&_64$$35);
	ZVAL_UNDEF(&_65$$35);
	ZVAL_UNDEF(&_66$$35);
	ZVAL_UNDEF(&_68$$35);
	ZVAL_UNDEF(&_69$$35);
	ZVAL_UNDEF(&_70$$35);
	ZVAL_UNDEF(&_71$$36);
	ZVAL_UNDEF(&_72$$37);
	ZVAL_UNDEF(&_73$$38);
	ZVAL_UNDEF(&_74$$38);
	ZVAL_UNDEF(&_75$$38);
	ZVAL_UNDEF(&_76$$38);
	ZVAL_UNDEF(&_77$$38);
	ZVAL_UNDEF(&_78$$38);
	ZVAL_UNDEF(&_79$$39);
	ZVAL_UNDEF(&_80$$40);
	ZVAL_UNDEF(&_82$$41);
	ZVAL_UNDEF(&_83$$42);
	ZVAL_UNDEF(&_84$$42);
	ZVAL_UNDEF(&_86$$43);
	ZVAL_UNDEF(&_87$$43);
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
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_missingdefinitionkey_ce, "columns", "phalcon/Db/Dialect/Sqlite.zep", 158);
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
	zephir_is_iterable(&columns, 0, "phalcon/Db/Dialect/Sqlite.zep", 227);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _2)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _2);
			ZEPHIR_CALL_METHOD(&_4$$7, &column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5$$7, this_ptr, "getcolumndefinition", &_6, 0, &column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7$$7, this_ptr, "getgeneratedclause", &_8, 0, &column);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&columnLine);
			ZEPHIR_CONCAT_SVSVV(&columnLine, "`", &_4$$7, "` ", &_5$$7, &_7$$7);
			ZEPHIR_CALL_METHOD(&_9$$7, &column, "isgenerated", NULL, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_9$$7))) {
				ZEPHIR_CALL_METHOD(&_10$$8, &column, "isprimary", NULL, 0);
				zephir_check_call_status();
				_11$$8 = zephir_is_true(&_10$$8);
				if (_11$$8) {
					_11$$8 = !hasPrimary;
				}
				if (_11$$8) {
					zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY"));
					hasPrimary = 1;
				}
				ZEPHIR_CALL_METHOD(&_12$$8, &column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				_13$$8 = zephir_is_true(&_12$$8);
				if (_13$$8) {
					_13$$8 = hasPrimary;
				}
				if (_13$$8) {
					zephir_concat_self_str(&columnLine, SL(" AUTOINCREMENT"));
				}
				ZEPHIR_CALL_METHOD(&_14$$8, &column, "hasdefault", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_14$$8)) {
					ZEPHIR_CALL_METHOD(&defaultValue, &column, "getdefault", NULL, 0);
					zephir_check_call_status();
					_15$$11 = Z_TYPE_P(&defaultValue) == IS_OBJECT;
					if (_15$$11) {
						_15$$11 = zephir_instance_of_ev(&defaultValue, phalcon_db_rawvalue_ce);
					}
					ZEPHIR_INIT_NVAR(&_16$$11);
					zephir_fast_strtoupper(&_16$$11, &defaultValue);
					if (_15$$11) {
						ZEPHIR_CALL_METHOD(&_17$$12, &defaultValue, "getvalue", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_18$$12);
						ZEPHIR_CONCAT_SV(&_18$$12, " DEFAULT ", &_17$$12);
						zephir_concat_self(&columnLine, &_18$$12);
					} else if (zephir_memnstr_str(&_16$$11, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Sqlite.zep", 204)) {
						zephir_concat_self_str(&columnLine, SL(" DEFAULT CURRENT_TIMESTAMP"));
					} else {
						ZEPHIR_INIT_NVAR(&_19$$14);
						ZVAL_STRING(&_19$$14, "\"");
						ZEPHIR_CALL_FUNCTION(&_20$$14, "addcslashes", &_21, 342, &defaultValue, &_19$$14);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_22$$14);
						ZEPHIR_CONCAT_SVS(&_22$$14, " DEFAULT \"", &_20$$14, "\"");
						zephir_concat_self(&columnLine, &_22$$14);
					}
				}
			}
			ZEPHIR_CALL_METHOD(&_23$$7, &column, "isnotnull", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_23$$7)) {
				zephir_concat_self_str(&columnLine, SL(" NOT NULL"));
			} else {
				zephir_concat_self_str(&columnLine, SL(" NULL"));
			}
			zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 221);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &columns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &columns, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_24$$17, &column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_25$$17, this_ptr, "getcolumndefinition", &_6, 0, &column);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_26$$17, this_ptr, "getgeneratedclause", &_8, 0, &column);
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
						ZEPHIR_INIT_NVAR(&_34$$21);
						zephir_fast_strtoupper(&_34$$21, &defaultValue);
						if (_33$$21) {
							ZEPHIR_CALL_METHOD(&_35$$22, &defaultValue, "getvalue", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_36$$22);
							ZEPHIR_CONCAT_SV(&_36$$22, " DEFAULT ", &_35$$22);
							zephir_concat_self(&columnLine, &_36$$22);
						} else if (zephir_memnstr_str(&_34$$21, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Sqlite.zep", 204)) {
							zephir_concat_self_str(&columnLine, SL(" DEFAULT CURRENT_TIMESTAMP"));
						} else {
							ZEPHIR_INIT_NVAR(&_37$$24);
							ZVAL_STRING(&_37$$24, "\"");
							ZEPHIR_CALL_FUNCTION(&_38$$24, "addcslashes", &_21, 342, &defaultValue, &_37$$24);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_39$$24);
							ZEPHIR_CONCAT_SVS(&_39$$24, " DEFAULT \"", &_38$$24, "\"");
							zephir_concat_self(&columnLine, &_39$$24);
						}
					}
				}
				ZEPHIR_CALL_METHOD(&_40$$17, &column, "isnotnull", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_40$$17)) {
					zephir_concat_self_str(&columnLine, SL(" NOT NULL"));
				} else {
					zephir_concat_self_str(&columnLine, SL(" NULL"));
				}
				zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 221);
			ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	zephir_memory_observe(&indexes);
	if (zephir_array_isset_string_fetch(&indexes, &definition, SL("indexes"), 0)) {
		zephir_is_iterable(&indexes, 0, "phalcon/Db/Dialect/Sqlite.zep", 243);
		if (Z_TYPE_P(&indexes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&indexes), _41$$27)
			{
				ZEPHIR_INIT_NVAR(&index);
				ZVAL_COPY(&index, _41$$27);
				ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
				zephir_check_call_status();
				_43$$28 = ZEPHIR_IS_STRING(&indexName, "PRIMARY");
				if (_43$$28) {
					_43$$28 = !hasPrimary;
				}
				_44$$28 = !(ZEPHIR_IS_EMPTY(&indexType));
				if (_44$$28) {
					ZEPHIR_INIT_NVAR(&_45$$28);
					zephir_fast_strtoupper(&_45$$28, &indexType);
					_44$$28 = zephir_memnstr_str(&_45$$28, SL("UNIQUE"), "phalcon/Db/Dialect/Sqlite.zep", 238);
				}
				if (_43$$28) {
					ZVAL_BOOL(&_47$$29, 0);
					ZEPHIR_CALL_METHOD(&_46$$29, this_ptr, "getindexcolumnlist", &_48, 0, &index, &_47$$29);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_49$$29);
					ZEPHIR_CONCAT_SVS(&_49$$29, "PRIMARY KEY (", &_46$$29, ")");
					zephir_array_append(&createLines, &_49$$29, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 237);
				} else if (_44$$28) {
					ZVAL_BOOL(&_51$$30, 0);
					ZEPHIR_CALL_METHOD(&_50$$30, this_ptr, "getindexcolumnlist", &_48, 0, &index, &_51$$30);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_52$$30);
					ZEPHIR_CONCAT_SVS(&_52$$30, "UNIQUE (", &_50$$30, ")");
					zephir_array_append(&createLines, &_52$$30, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 240);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &indexes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_42$$27, &indexes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_42$$27)) {
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
					_54$$31 = !(ZEPHIR_IS_EMPTY(&indexType));
					if (_54$$31) {
						ZEPHIR_INIT_NVAR(&_55$$31);
						zephir_fast_strtoupper(&_55$$31, &indexType);
						_54$$31 = zephir_memnstr_str(&_55$$31, SL("UNIQUE"), "phalcon/Db/Dialect/Sqlite.zep", 238);
					}
					if (_53$$31) {
						ZVAL_BOOL(&_57$$32, 0);
						ZEPHIR_CALL_METHOD(&_56$$32, this_ptr, "getindexcolumnlist", &_48, 0, &index, &_57$$32);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_58$$32);
						ZEPHIR_CONCAT_SVS(&_58$$32, "PRIMARY KEY (", &_56$$32, ")");
						zephir_array_append(&createLines, &_58$$32, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 237);
					} else if (_54$$31) {
						ZVAL_BOOL(&_60$$33, 0);
						ZEPHIR_CALL_METHOD(&_59$$33, this_ptr, "getindexcolumnlist", &_48, 0, &index, &_60$$33);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_61$$33);
						ZEPHIR_CONCAT_SVS(&_61$$33, "UNIQUE (", &_59$$33, ")");
						zephir_array_append(&createLines, &_61$$33, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 240);
					}
				ZEPHIR_CALL_METHOD(NULL, &indexes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&index);
	}
	zephir_memory_observe(&references);
	if (zephir_array_isset_string_fetch(&references, &definition, SL("references"), 0)) {
		zephir_is_iterable(&references, 0, "phalcon/Db/Dialect/Sqlite.zep", 265);
		if (Z_TYPE_P(&references) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&references), _62$$34)
			{
				ZEPHIR_INIT_NVAR(&reference);
				ZVAL_COPY(&reference, _62$$34);
				ZEPHIR_CALL_METHOD(&_64$$35, &reference, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_66$$35, &reference, "getcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_65$$35, this_ptr, "getcolumnlist", &_67, 99, &_66$$35);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_68$$35, &reference, "getreferencedtable", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_70$$35, &reference, "getreferencedcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_69$$35, this_ptr, "getcolumnlist", &_67, 99, &_70$$35);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&referenceSql);
				ZEPHIR_CONCAT_SVSVSSVSVS(&referenceSql, "CONSTRAINT `", &_64$$35, "` FOREIGN KEY (", &_65$$35, ")", " REFERENCES `", &_68$$35, "`(", &_69$$35, ")");
				ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
					ZEPHIR_INIT_NVAR(&_71$$36);
					ZEPHIR_CONCAT_SV(&_71$$36, " ON DELETE ", &onDelete);
					zephir_concat_self(&referenceSql, &_71$$36);
				}
				ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
					ZEPHIR_INIT_NVAR(&_72$$37);
					ZEPHIR_CONCAT_SV(&_72$$37, " ON UPDATE ", &onUpdate);
					zephir_concat_self(&referenceSql, &_72$$37);
				}
				zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 263);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &references, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_63$$34, &references, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_63$$34)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&reference, &references, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_73$$38, &reference, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_75$$38, &reference, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_74$$38, this_ptr, "getcolumnlist", &_67, 99, &_75$$38);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_76$$38, &reference, "getreferencedtable", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_78$$38, &reference, "getreferencedcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_77$$38, this_ptr, "getcolumnlist", &_67, 99, &_78$$38);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&referenceSql);
					ZEPHIR_CONCAT_SVSVSSVSVS(&referenceSql, "CONSTRAINT `", &_73$$38, "` FOREIGN KEY (", &_74$$38, ")", " REFERENCES `", &_76$$38, "`(", &_77$$38, ")");
					ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
						ZEPHIR_INIT_NVAR(&_79$$39);
						ZEPHIR_CONCAT_SV(&_79$$39, " ON DELETE ", &onDelete);
						zephir_concat_self(&referenceSql, &_79$$39);
					}
					ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
						ZEPHIR_INIT_NVAR(&_80$$40);
						ZEPHIR_CONCAT_SV(&_80$$40, " ON UPDATE ", &onUpdate);
						zephir_concat_self(&referenceSql, &_80$$40);
					}
					zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 263);
				ZEPHIR_CALL_METHOD(NULL, &references, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&reference);
	}
	zephir_memory_observe(&checks);
	if (zephir_array_isset_string_fetch(&checks, &definition, SL("checks"), 0)) {
		zephir_is_iterable(&checks, 0, "phalcon/Db/Dialect/Sqlite.zep", 274);
		if (Z_TYPE_P(&checks) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&checks), _81$$41)
			{
				ZEPHIR_INIT_NVAR(&check);
				ZVAL_COPY(&check, _81$$41);
				ZEPHIR_INIT_NVAR(&_84$$42);
				ZVAL_STRING(&_84$$42, "`");
				ZEPHIR_CALL_METHOD(&_83$$42, this_ptr, "getcheckclause", &_85, 0, &check, &_84$$42);
				zephir_check_call_status();
				zephir_array_append(&createLines, &_83$$42, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 272);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &checks, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_82$$41, &checks, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_82$$41)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&check, &checks, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_87$$43);
					ZVAL_STRING(&_87$$43, "`");
					ZEPHIR_CALL_METHOD(&_86$$43, this_ptr, "getcheckclause", &_85, 0, &check, &_87$$43);
					zephir_check_call_status();
					zephir_array_append(&createLines, &_86$$43, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 272);
				ZEPHIR_CALL_METHOD(NULL, &checks, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&check);
	}
	ZEPHIR_INIT_VAR(&_88);
	zephir_fast_join_str(&_88, SL(",\n\t"), &createLines);
	ZEPHIR_INIT_VAR(&_89);
	ZEPHIR_CONCAT_VS(&_89, &_88, "\n)");
	zephir_concat_self(&sql, &_89);
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
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	zephir_memory_observe(&viewSql);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&viewSql, &definition, SL("sql"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_missingdefinitionkey_ce, "sql", "phalcon/Db/Dialect/Sqlite.zep", 289);
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
	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA table_xinfo('", &table_zv, "')");
	RETURN_MM();
}

/**
 * Generates SQL to query indexes detail on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndex)
{
	zval index_zv;
	zend_string *index = NULL;

	ZVAL_UNDEF(&index_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(index)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&index_zv, index);
	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA index_info('", &index_zv, "')");
	return;
}

/**
 * Generates SQL to query indexes on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndexes)
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
	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA index_list('", &table_zv, "')");
	RETURN_MM();
}

/**
 * Generates SQL to query foreign keys on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeReferences)
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
	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA foreign_key_list('", &table_zv, "')");
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 351);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 361);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 352);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 369);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 353);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 389);
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
	if (UNEXPECTED(Z_TYPE_P(ifExists_param) != IS_TRUE && Z_TYPE_P(ifExists_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ifExists' must be of the type bool"));
		RETURN_MM_NULL();
	}
	ifExists = (Z_TYPE_P(ifExists_param) == IS_TRUE);
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
	if (UNEXPECTED(Z_TYPE_P(ifExists_param) != IS_TRUE && Z_TYPE_P(ifExists_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ifExists' must be of the type bool"));
		RETURN_MM_NULL();
	}
	ifExists = (Z_TYPE_P(ifExists_param) == IS_TRUE);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, columnType, columnSql, typeValues, _0$$3, _1$$10, _2$$16, _3$$18, _4$$35, _5$$38, _6$$38, _7$$38, value$$40, valueSql$$40, *_8$$40, _9$$40, _17$$40, _18$$40, _19$$40, _20$$40, _10$$41, _11$$41, _13$$41, _14$$42, _15$$42, _16$$42, _21$$43, _22$$43, _23$$43;
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
	ZVAL_UNDEF(&_17$$40);
	ZVAL_UNDEF(&_18$$40);
	ZVAL_UNDEF(&_19$$40);
	ZVAL_UNDEF(&_20$$40);
	ZVAL_UNDEF(&_10$$41);
	ZVAL_UNDEF(&_11$$41);
	ZVAL_UNDEF(&_13$$41);
	ZVAL_UNDEF(&_14$$42);
	ZVAL_UNDEF(&_15$$42);
	ZVAL_UNDEF(&_16$$42);
	ZVAL_UNDEF(&_21$$43);
	ZVAL_UNDEF(&_22$$43);
	ZVAL_UNDEF(&_23$$43);
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
			ZEPHIR_CALL_METHOD(NULL, &_5$$38, "__construct", NULL, 345, &_7$$38, &_6$$38);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$38, "phalcon/Db/Dialect/Sqlite.zep", 578);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&typeValues, column, "gettypevalues", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&typeValues))) {
			if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(&valueSql$$40);
				ZVAL_STRING(&valueSql$$40, "");
				zephir_is_iterable(&typeValues, 0, "phalcon/Db/Dialect/Sqlite.zep", 592);
				if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&typeValues), _8$$40)
					{
						ZEPHIR_INIT_NVAR(&value$$40);
						ZVAL_COPY(&value$$40, _8$$40);
						ZEPHIR_INIT_NVAR(&_10$$41);
						ZVAL_STRING(&_10$$41, "\"");
						ZEPHIR_CALL_FUNCTION(&_11$$41, "addcslashes", &_12, 342, &value$$40, &_10$$41);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_13$$41);
						ZEPHIR_CONCAT_SVS(&_13$$41, "\"", &_11$$41, "\", ");
						zephir_concat_self(&valueSql$$40, &_13$$41);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &typeValues, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_9$$40, &typeValues, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_9$$40)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&value$$40, &typeValues, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_14$$42);
							ZVAL_STRING(&_14$$42, "\"");
							ZEPHIR_CALL_FUNCTION(&_15$$42, "addcslashes", &_12, 342, &value$$40, &_14$$42);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_16$$42);
							ZEPHIR_CONCAT_SVS(&_16$$42, "\"", &_15$$42, "\", ");
							zephir_concat_self(&valueSql$$40, &_16$$42);
						ZEPHIR_CALL_METHOD(NULL, &typeValues, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&value$$40);
				ZVAL_LONG(&_17$$40, 0);
				ZVAL_LONG(&_18$$40, -2);
				ZEPHIR_INIT_VAR(&_19$$40);
				zephir_substr(&_19$$40, &valueSql$$40, 0 , -2 , 0);
				ZEPHIR_INIT_VAR(&_20$$40);
				ZEPHIR_CONCAT_SVS(&_20$$40, "(", &_19$$40, ")");
				zephir_concat_self(&columnSql, &_20$$40);
			} else {
				ZEPHIR_INIT_VAR(&_21$$43);
				ZVAL_STRING(&_21$$43, "\"");
				ZEPHIR_CALL_FUNCTION(&_22$$43, "addcslashes", &_12, 342, &typeValues, &_21$$43);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_23$$43);
				ZEPHIR_CONCAT_SVS(&_23$$43, "(\"", &_22$$43, "\")");
				zephir_concat_self(&columnSql, &_23$$43);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "escape", NULL, 95, &table_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "SELECT sql FROM sqlite_master WHERE type = 'index' AND tbl_name = ", &_0, " COLLATE NOCASE");
	zephir_get_strval(&sql, &_1);
	if (!(ZEPHIR_IS_EMPTY(&keyName_zv))) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "escape", NULL, 95, &keyName_zv);
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
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 354);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Sqlite.zep", 651);
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
	ZEPHIR_OBS_COPY_OR_DUP(&columns, columns_param);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&columns))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_db_exceptions_returningrequirescolumn_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 347);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Db/Dialect/Sqlite.zep", 664);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_fast_count_int(&columns) == 1) {
		zephir_memory_observe(&_1$$4);
		zephir_array_fetch_long(&_1$$4, &columns, 0, PH_NOISY, "phalcon/Db/Dialect/Sqlite.zep", 668);
		zephir_cast_to_string(&_2$$4, &_1$$4);
		ZEPHIR_CPY_WRT(&first, &_2$$4);
		if (ZEPHIR_IS_STRING(&first, "*")) {
			ZEPHIR_CONCAT_VS(return_value, &sqlQuery_zv, " RETURNING *");
			RETURN_MM();
		}
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getcolumnlist", NULL, 99, &columns);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &sqlQuery_zv, " RETURNING ", &_3);
	RETURN_MM();
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
	zval tableName_zv, schemaName_zv;
	zend_string *tableName = NULL, *schemaName = NULL;

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
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
	ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='table' AND tbl_name='", &tableName_zv, "'");
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
	zval viewName_zv, schemaName_zv;
	zend_string *viewName = NULL, *schemaName = NULL;

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName_zv);
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
	ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='view' AND tbl_name='", &viewName_zv, "'");
	RETURN_MM();
}

