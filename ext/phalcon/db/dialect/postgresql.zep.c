
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/string.h"
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
 * Generates database specific SQL for the PostgreSQL RDBMS
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Postgresql)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Postgresql, phalcon, db_dialect_postgresql, phalcon_db_dialect_ce, phalcon_db_dialect_postgresql_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_dialect_postgresql_ce, SL("escapeChar"), "\"", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_dialect_postgresql_ce, SL("supportedOperators"), ZEND_ACC_PROTECTED);
	phalcon_db_dialect_postgresql_ce->create_object = zephir_init_properties_Phalcon_Db_Dialect_Postgresql;

	return SUCCESS;
}

/**
 * Generates SQL to add a column to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addColumn)
{
	zend_bool _8;
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *column, column_sub, columnDefinition, _0, _1, _2, _3, _4, _5, _6, _7, _9, _12, _10$$3, _11$$3;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getgeneratedclause", NULL, 0, column, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&columnDefinition);
	ZEPHIR_CONCAT_VV(&columnDefinition, &_0, &_1);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVS(&_4, "ALTER TABLE ", &_3, " ADD COLUMN ");
	zephir_get_strval(&sql, &_4);
	ZEPHIR_CALL_METHOD(&_5, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVSV(&_6, "\"", &_5, "\" ", &columnDefinition);
	zephir_concat_self(&sql, &_6);
	ZEPHIR_CALL_METHOD(&_7, column, "isgenerated", NULL, 0);
	zephir_check_call_status();
	_8 = !zephir_is_true(&_7);
	if (_8) {
		ZEPHIR_CALL_METHOD(&_9, column, "hasdefault", NULL, 0);
		zephir_check_call_status();
		_8 = zephir_is_true(&_9);
	}
	if (_8) {
		ZEPHIR_CALL_METHOD(&_10$$3, this_ptr, "castdefault", NULL, 0, column);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_11$$3);
		ZEPHIR_CONCAT_SV(&_11$$3, " DEFAULT ", &_10$$3);
		zephir_concat_self(&sql, &_11$$3);
	}
	ZEPHIR_CALL_METHOD(&_12, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_12)) {
		zephir_concat_self_str(&sql, " NOT NULL", sizeof(" NOT NULL") - 1);
	} else {
		zephir_concat_self_str(&sql, " NULL", sizeof(" NULL") - 1);
	}
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to add a CHECK constraint to an existing table.
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addCheck)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *check, check_sub, _0, _1, _2;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&check_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\"");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcheckclause", NULL, 0, check, &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSV(return_value, "ALTER TABLE ", &_0, " ADD ", &_1);
	RETURN_MM();
}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addForeignKey)
{
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *reference, reference_sub, onDelete, onUpdate, _0, _1, _2, _5, _6, _7, _8, _9, _10, _3$$3, _4$$3, _11$$4, _12$$5;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&reference_sub);
	ZVAL_UNDEF(&onDelete);
	ZVAL_UNDEF(&onUpdate);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&sql);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "ALTER TABLE ", &_0, " ADD");
	zephir_get_strval(&sql, &_1);
	ZEPHIR_CALL_METHOD(&_2, reference, "getname", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD(&_3$$3, reference, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SVS(&_4$$3, " CONSTRAINT \"", &_3$$3, "\"");
		zephir_concat_self(&sql, &_4$$3);
	}
	ZEPHIR_CALL_METHOD(&_6, reference, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumnlist", NULL, 103, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, reference, "getreferencedtable", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, reference, "getreferencedcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "getcolumnlist", NULL, 103, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_SVSSVSVS(&_10, " FOREIGN KEY (", &_5, ")", " REFERENCES \"", &_7, "\" (", &_8, ")");
	zephir_concat_self(&sql, &_10);
	ZEPHIR_CALL_METHOD(&onDelete, reference, "getondelete", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
		ZEPHIR_INIT_VAR(&_11$$4);
		ZEPHIR_CONCAT_SV(&_11$$4, " ON DELETE ", &onDelete);
		zephir_concat_self(&sql, &_11$$4);
	}
	ZEPHIR_CALL_METHOD(&onUpdate, reference, "getonupdate", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
		ZEPHIR_INIT_VAR(&_12$$5);
		ZEPHIR_CONCAT_SV(&_12$$5, " ON UPDATE ", &onUpdate);
		zephir_concat_self(&sql, &_12$$5);
	}
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addIndex)
{
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *index, index_sub, indexType, _0, _2, _3, _4, _5, _6, _7, _8, _1$$4, _9$$6, _10$$6;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
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
	ZEPHIR_CALL_METHOD(&_0, index, "getname", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING_IDENTICAL(&_0, "PRIMARY")) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "addprimarykey", NULL, 0, &tableName_zv, &schemaName_zv, index);
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
		zephir_concat_self(&sql, &_1$$4);
	}
	zephir_concat_self_str(&sql, " INDEX", sizeof(" INDEX") - 1);
	ZEPHIR_CALL_METHOD(&_2, index, "isconcurrent", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		zephir_concat_self_str(&sql, " CONCURRENTLY", sizeof(" CONCURRENTLY") - 1);
	}
	ZEPHIR_CALL_METHOD(&_3, index, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVSV(&_5, " \"", &_3, "\" ON ", &_4);
	zephir_concat_self(&sql, &_5);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getindexcolumnlist", NULL, 0, index);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SVS(&_7, " (", &_6, ")");
	zephir_concat_self(&sql, &_7);
	ZEPHIR_CALL_METHOD(&_8, index, "getwhere", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_8, "")) {
		ZEPHIR_CALL_METHOD(&_9$$6, index, "getwhere", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$6);
		ZEPHIR_CONCAT_SV(&_10$$6, " WHERE ", &_9$$6);
		zephir_concat_self(&sql, &_10$$6);
	}
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to add the primary key to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addPrimaryKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *index, index_sub, _0, _1, _2;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcolumnlist", NULL, 103, &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVSVS(return_value, "ALTER TABLE ", &_0, " ADD CONSTRAINT \"", &tableName_zv, "_PRIMARY\" PRIMARY KEY (", &_1, ")");
	RETURN_MM();
}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createTable)
{
	zend_bool _27, _11$$7, _34$$13, _62$$20, _85$$33, _102$$40;
	zval indexSql, indexSqlAfterCreate, columnLine, referenceSql, sql, _113;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_14 = NULL, *_52 = NULL, *_100 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition, createLines, primaryColumns;
	zval tableName_zv, schemaName_zv, *definition_param = NULL, temporary, options, table, columns, column, indexes, index, reference, references, indexName, indexType, onDelete, onUpdate, columnDefinition, checks, check, tableComment, *_2, _26, _105, _106, _0$$5, _1$$6, _3$$7, _5$$7, _6$$7, _8$$7, _9$$7, _10$$7, _12$$7, _16$$7, _17$$7, _19$$7, _13$$8, _15$$8, _18$$11, _20$$12, _21$$12, _22$$12, _23$$12, _24$$12, _25$$12, _28$$13, _29$$13, _30$$13, _31$$13, _32$$13, _33$$13, _35$$13, _38$$13, _39$$13, _41$$13, _36$$14, _37$$14, _40$$17, _42$$18, _43$$18, _44$$18, _45$$18, _46$$18, _47$$18, _48$$19, _49$$19, *_50$$20, _61$$20, _51$$22, _53$$22, _54$$24, _55$$24, _56$$25, _57$$25, _58$$25, _59$$25, _60$$25, _63$$28, _64$$28, _65$$30, _66$$30, _67$$31, _68$$31, _69$$31, _70$$31, _71$$31, *_72$$33, _84$$33, _73$$34, _74$$34, _75$$34, _76$$34, _77$$34, _78$$34, _79$$34, _80$$34, _81$$34, _82$$35, _83$$36, _86$$37, _87$$37, _88$$37, _89$$37, _90$$37, _91$$37, _92$$37, _93$$37, _94$$37, _95$$38, _96$$39, *_97$$40, _101$$40, _98$$41, _99$$41, _103$$42, _104$$42, _107$$43, _108$$43, _109$$44, _110$$44, _111$$44, _112$$44;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&temporary);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&column);
	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&reference);
	ZVAL_UNDEF(&references);
	ZVAL_UNDEF(&indexName);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&onDelete);
	ZVAL_UNDEF(&onUpdate);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&checks);
	ZVAL_UNDEF(&check);
	ZVAL_UNDEF(&tableComment);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_105);
	ZVAL_UNDEF(&_106);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_28$$13);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_38$$13);
	ZVAL_UNDEF(&_39$$13);
	ZVAL_UNDEF(&_41$$13);
	ZVAL_UNDEF(&_36$$14);
	ZVAL_UNDEF(&_37$$14);
	ZVAL_UNDEF(&_40$$17);
	ZVAL_UNDEF(&_42$$18);
	ZVAL_UNDEF(&_43$$18);
	ZVAL_UNDEF(&_44$$18);
	ZVAL_UNDEF(&_45$$18);
	ZVAL_UNDEF(&_46$$18);
	ZVAL_UNDEF(&_47$$18);
	ZVAL_UNDEF(&_48$$19);
	ZVAL_UNDEF(&_49$$19);
	ZVAL_UNDEF(&_61$$20);
	ZVAL_UNDEF(&_51$$22);
	ZVAL_UNDEF(&_53$$22);
	ZVAL_UNDEF(&_54$$24);
	ZVAL_UNDEF(&_55$$24);
	ZVAL_UNDEF(&_56$$25);
	ZVAL_UNDEF(&_57$$25);
	ZVAL_UNDEF(&_58$$25);
	ZVAL_UNDEF(&_59$$25);
	ZVAL_UNDEF(&_60$$25);
	ZVAL_UNDEF(&_63$$28);
	ZVAL_UNDEF(&_64$$28);
	ZVAL_UNDEF(&_65$$30);
	ZVAL_UNDEF(&_66$$30);
	ZVAL_UNDEF(&_67$$31);
	ZVAL_UNDEF(&_68$$31);
	ZVAL_UNDEF(&_69$$31);
	ZVAL_UNDEF(&_70$$31);
	ZVAL_UNDEF(&_71$$31);
	ZVAL_UNDEF(&_84$$33);
	ZVAL_UNDEF(&_73$$34);
	ZVAL_UNDEF(&_74$$34);
	ZVAL_UNDEF(&_75$$34);
	ZVAL_UNDEF(&_76$$34);
	ZVAL_UNDEF(&_77$$34);
	ZVAL_UNDEF(&_78$$34);
	ZVAL_UNDEF(&_79$$34);
	ZVAL_UNDEF(&_80$$34);
	ZVAL_UNDEF(&_81$$34);
	ZVAL_UNDEF(&_82$$35);
	ZVAL_UNDEF(&_83$$36);
	ZVAL_UNDEF(&_86$$37);
	ZVAL_UNDEF(&_87$$37);
	ZVAL_UNDEF(&_88$$37);
	ZVAL_UNDEF(&_89$$37);
	ZVAL_UNDEF(&_90$$37);
	ZVAL_UNDEF(&_91$$37);
	ZVAL_UNDEF(&_92$$37);
	ZVAL_UNDEF(&_93$$37);
	ZVAL_UNDEF(&_94$$37);
	ZVAL_UNDEF(&_95$$38);
	ZVAL_UNDEF(&_96$$39);
	ZVAL_UNDEF(&_101$$40);
	ZVAL_UNDEF(&_98$$41);
	ZVAL_UNDEF(&_99$$41);
	ZVAL_UNDEF(&_103$$42);
	ZVAL_UNDEF(&_104$$42);
	ZVAL_UNDEF(&_107$$43);
	ZVAL_UNDEF(&_108$$43);
	ZVAL_UNDEF(&_109$$44);
	ZVAL_UNDEF(&_110$$44);
	ZVAL_UNDEF(&_111$$44);
	ZVAL_UNDEF(&_112$$44);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&createLines);
	ZVAL_UNDEF(&primaryColumns);
	ZVAL_UNDEF(&indexSql);
	ZVAL_UNDEF(&indexSqlAfterCreate);
	ZVAL_UNDEF(&columnLine);
	ZVAL_UNDEF(&referenceSql);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_113);
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
	zephir_memory_observe(&columns);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_missingdefinitionkey_ce, "columns", "phalcon/Db/Dialect/Postgresql.zep", 162);
		return;
	}
	ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&temporary);
	ZVAL_BOOL(&temporary, 0);
	zephir_memory_observe(&options);
	if (zephir_array_isset_string_fetch(&options, &definition, SL("options"), 0)) {
		ZEPHIR_OBS_NVAR(&temporary);
		zephir_array_isset_string_fetch(&temporary, &options, SL("temporary"), 0);
		zephir_memory_observe(&tableComment);
		zephir_array_isset_string_fetch(&tableComment, &options, SL("TABLE_COMMENT"), 0);
	}
	if (zephir_is_true(&temporary)) {
		ZEPHIR_INIT_VAR(&_0$$5);
		ZEPHIR_CONCAT_SVS(&_0$$5, "CREATE TEMPORARY TABLE ", &table, " (\n\t");
		zephir_get_strval(&sql, &_0$$5);
	} else {
		ZEPHIR_INIT_VAR(&_1$$6);
		ZEPHIR_CONCAT_SVS(&_1$$6, "CREATE TABLE ", &table, " (\n\t");
		zephir_get_strval(&sql, &_1$$6);
	}
	ZEPHIR_INIT_VAR(&indexSqlAfterCreate);
	ZVAL_STRING(&indexSqlAfterCreate, "");
	ZEPHIR_INIT_VAR(&createLines);
	array_init(&createLines);
	ZEPHIR_INIT_VAR(&primaryColumns);
	array_init(&primaryColumns);
	zephir_is_iterable(&columns, 0, "phalcon/Db/Dialect/Postgresql.zep", 228);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _2)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _2);
			ZEPHIR_CALL_METHOD(&_3$$7, this_ptr, "getcolumndefinition", &_4, 0, &column);
			zephir_check_call_status();
			ZVAL_BOOL(&_6$$7, 1);
			ZEPHIR_CALL_METHOD(&_5$$7, this_ptr, "getgeneratedclause", &_7, 0, &column, &_6$$7);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&columnDefinition);
			ZEPHIR_CONCAT_VV(&columnDefinition, &_3$$7, &_5$$7);
			ZEPHIR_CALL_METHOD(&_8$$7, &column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_9$$7);
			ZEPHIR_CONCAT_SVSV(&_9$$7, "\"", &_8$$7, "\" ", &columnDefinition);
			zephir_get_strval(&columnLine, &_9$$7);
			ZEPHIR_CALL_METHOD(&_10$$7, &column, "isgenerated", NULL, 0);
			zephir_check_call_status();
			_11$$7 = !zephir_is_true(&_10$$7);
			if (_11$$7) {
				ZEPHIR_CALL_METHOD(&_12$$7, &column, "hasdefault", NULL, 0);
				zephir_check_call_status();
				_11$$7 = zephir_is_true(&_12$$7);
			}
			if (_11$$7) {
				ZEPHIR_CALL_METHOD(&_13$$8, this_ptr, "castdefault", &_14, 0, &column);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$8);
				ZEPHIR_CONCAT_SV(&_15$$8, " DEFAULT ", &_13$$8);
				zephir_concat_self(&columnLine, &_15$$8);
			}
			ZEPHIR_CALL_METHOD(&_16$$7, &column, "isnotnull", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_16$$7)) {
				zephir_concat_self_str(&columnLine, " NOT NULL", sizeof(" NOT NULL") - 1);
			} else {
				zephir_concat_self_str(&columnLine, " NULL", sizeof(" NULL") - 1);
			}
			ZEPHIR_CALL_METHOD(&_17$$7, &column, "isprimary", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_17$$7)) {
				ZEPHIR_CALL_METHOD(&_18$$11, &column, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_array_append(&primaryColumns, &_18$$11, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 215);
			}
			zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 218);
			ZEPHIR_CALL_METHOD(&_19$$7, &column, "getcomment", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_19$$7)) {
				ZEPHIR_CALL_METHOD(&_20$$12, &column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_21$$12);
				ZEPHIR_CALL_METHOD(&_22$$12, &column, "getcomment", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_23$$12);
				ZVAL_STRING(&_23$$12, "'");
				ZEPHIR_INIT_NVAR(&_24$$12);
				ZVAL_STRING(&_24$$12, "''");
				zephir_fast_str_replace(&_21$$12, &_23$$12, &_24$$12, &_22$$12);
				ZEPHIR_INIT_NVAR(&_25$$12);
				ZEPHIR_CONCAT_SVSVSVS(&_25$$12, " COMMENT ON COLUMN ", &table, ".\"", &_20$$12, "\" IS '", &_21$$12, "';");
				zephir_concat_self(&indexSqlAfterCreate, &_25$$12);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
		zephir_check_call_status();
		_27 = 1;
		while (1) {
			if (_27) {
				_27 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_26, &columns, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_26)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&column, &columns, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_28$$13, this_ptr, "getcolumndefinition", &_4, 0, &column);
				zephir_check_call_status();
				ZVAL_BOOL(&_30$$13, 1);
				ZEPHIR_CALL_METHOD(&_29$$13, this_ptr, "getgeneratedclause", &_7, 0, &column, &_30$$13);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&columnDefinition);
				ZEPHIR_CONCAT_VV(&columnDefinition, &_28$$13, &_29$$13);
				ZEPHIR_CALL_METHOD(&_31$$13, &column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_32$$13);
				ZEPHIR_CONCAT_SVSV(&_32$$13, "\"", &_31$$13, "\" ", &columnDefinition);
				zephir_get_strval(&columnLine, &_32$$13);
				ZEPHIR_CALL_METHOD(&_33$$13, &column, "isgenerated", NULL, 0);
				zephir_check_call_status();
				_34$$13 = !zephir_is_true(&_33$$13);
				if (_34$$13) {
					ZEPHIR_CALL_METHOD(&_35$$13, &column, "hasdefault", NULL, 0);
					zephir_check_call_status();
					_34$$13 = zephir_is_true(&_35$$13);
				}
				if (_34$$13) {
					ZEPHIR_CALL_METHOD(&_36$$14, this_ptr, "castdefault", &_14, 0, &column);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_37$$14);
					ZEPHIR_CONCAT_SV(&_37$$14, " DEFAULT ", &_36$$14);
					zephir_concat_self(&columnLine, &_37$$14);
				}
				ZEPHIR_CALL_METHOD(&_38$$13, &column, "isnotnull", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_38$$13)) {
					zephir_concat_self_str(&columnLine, " NOT NULL", sizeof(" NOT NULL") - 1);
				} else {
					zephir_concat_self_str(&columnLine, " NULL", sizeof(" NULL") - 1);
				}
				ZEPHIR_CALL_METHOD(&_39$$13, &column, "isprimary", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_39$$13)) {
					ZEPHIR_CALL_METHOD(&_40$$17, &column, "getname", NULL, 0);
					zephir_check_call_status();
					zephir_array_append(&primaryColumns, &_40$$17, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 215);
				}
				zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 218);
				ZEPHIR_CALL_METHOD(&_41$$13, &column, "getcomment", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_41$$13)) {
					ZEPHIR_CALL_METHOD(&_42$$18, &column, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_43$$18);
					ZEPHIR_CALL_METHOD(&_44$$18, &column, "getcomment", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_45$$18);
					ZVAL_STRING(&_45$$18, "'");
					ZEPHIR_INIT_NVAR(&_46$$18);
					ZVAL_STRING(&_46$$18, "''");
					zephir_fast_str_replace(&_43$$18, &_45$$18, &_46$$18, &_44$$18);
					ZEPHIR_INIT_NVAR(&_47$$18);
					ZEPHIR_CONCAT_SVSVSVS(&_47$$18, " COMMENT ON COLUMN ", &table, ".\"", &_42$$18, "\" IS '", &_43$$18, "';");
					zephir_concat_self(&indexSqlAfterCreate, &_47$$18);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	if (!(ZEPHIR_IS_EMPTY(&primaryColumns))) {
		ZEPHIR_CALL_METHOD(&_48$$19, this_ptr, "getcolumnlist", NULL, 103, &primaryColumns);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_49$$19);
		ZEPHIR_CONCAT_SVS(&_49$$19, "PRIMARY KEY (", &_48$$19, ")");
		zephir_array_append(&createLines, &_49$$19, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 229);
	}
	zephir_memory_observe(&indexes);
	if (zephir_array_isset_string_fetch(&indexes, &definition, SL("indexes"), 0)) {
		zephir_is_iterable(&indexes, 0, "phalcon/Db/Dialect/Postgresql.zep", 259);
		if (Z_TYPE_P(&indexes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&indexes), _50$$20)
			{
				ZEPHIR_INIT_NVAR(&index);
				ZVAL_COPY(&index, _50$$20);
				ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&indexSql);
				ZVAL_STRING(&indexSql, "");
				if (ZEPHIR_IS_STRING(&indexName, "PRIMARY")) {
					ZEPHIR_CALL_METHOD(&_51$$22, this_ptr, "getindexcolumnlist", &_52, 0, &index);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_53$$22);
					ZEPHIR_CONCAT_SVS(&_53$$22, "CONSTRAINT \"PRIMARY\" PRIMARY KEY (", &_51$$22, ")");
					zephir_get_strval(&indexSql, &_53$$22);
				} else {
					if (!(ZEPHIR_IS_EMPTY(&indexType))) {
						ZEPHIR_CALL_METHOD(&_54$$24, this_ptr, "getindexcolumnlist", &_52, 0, &index);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_55$$24);
						ZEPHIR_CONCAT_SVSVSVS(&_55$$24, "CONSTRAINT \"", &indexName, "\" ", &indexType, " (", &_54$$24, ")");
						zephir_get_strval(&indexSql, &_55$$24);
					} else {
						ZEPHIR_CALL_METHOD(&_56$$25, &index, "getname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_57$$25, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_58$$25);
						ZEPHIR_CONCAT_SVSV(&_58$$25, "CREATE INDEX \"", &_56$$25, "\" ON ", &_57$$25);
						zephir_concat_self(&indexSqlAfterCreate, &_58$$25);
						ZEPHIR_CALL_METHOD(&_59$$25, this_ptr, "getindexcolumnlist", &_52, 0, &index);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_60$$25);
						ZEPHIR_CONCAT_SVS(&_60$$25, " (", &_59$$25, ");");
						zephir_concat_self(&indexSqlAfterCreate, &_60$$25);
					}
				}
				if (!(ZEPHIR_IS_EMPTY(&indexSql))) {
					zephir_array_append(&createLines, &indexSql, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 256);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &indexes, "rewind", NULL, 0);
			zephir_check_call_status();
			_62$$20 = 1;
			while (1) {
				if (_62$$20) {
					_62$$20 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &indexes, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_61$$20, &indexes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_61$$20)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&index, &indexes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&indexSql);
					ZVAL_STRING(&indexSql, "");
					if (ZEPHIR_IS_STRING(&indexName, "PRIMARY")) {
						ZEPHIR_CALL_METHOD(&_63$$28, this_ptr, "getindexcolumnlist", &_52, 0, &index);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_64$$28);
						ZEPHIR_CONCAT_SVS(&_64$$28, "CONSTRAINT \"PRIMARY\" PRIMARY KEY (", &_63$$28, ")");
						zephir_get_strval(&indexSql, &_64$$28);
					} else {
						if (!(ZEPHIR_IS_EMPTY(&indexType))) {
							ZEPHIR_CALL_METHOD(&_65$$30, this_ptr, "getindexcolumnlist", &_52, 0, &index);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_66$$30);
							ZEPHIR_CONCAT_SVSVSVS(&_66$$30, "CONSTRAINT \"", &indexName, "\" ", &indexType, " (", &_65$$30, ")");
							zephir_get_strval(&indexSql, &_66$$30);
						} else {
							ZEPHIR_CALL_METHOD(&_67$$31, &index, "getname", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_68$$31, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_69$$31);
							ZEPHIR_CONCAT_SVSV(&_69$$31, "CREATE INDEX \"", &_67$$31, "\" ON ", &_68$$31);
							zephir_concat_self(&indexSqlAfterCreate, &_69$$31);
							ZEPHIR_CALL_METHOD(&_70$$31, this_ptr, "getindexcolumnlist", &_52, 0, &index);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_71$$31);
							ZEPHIR_CONCAT_SVS(&_71$$31, " (", &_70$$31, ");");
							zephir_concat_self(&indexSqlAfterCreate, &_71$$31);
						}
					}
					if (!(ZEPHIR_IS_EMPTY(&indexSql))) {
						zephir_array_append(&createLines, &indexSql, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 256);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&index);
	}
	zephir_memory_observe(&references);
	if (zephir_array_isset_string_fetch(&references, &definition, SL("references"), 0)) {
		zephir_is_iterable(&references, 0, "phalcon/Db/Dialect/Postgresql.zep", 287);
		if (Z_TYPE_P(&references) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&references), _72$$33)
			{
				ZEPHIR_INIT_NVAR(&reference);
				ZVAL_COPY(&reference, _72$$33);
				ZEPHIR_CALL_METHOD(&_73$$34, &reference, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_75$$34, &reference, "getcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_74$$34, this_ptr, "getcolumnlist", NULL, 103, &_75$$34);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_76$$34);
				ZEPHIR_CONCAT_SVSVS(&_76$$34, "CONSTRAINT \"", &_73$$34, "\" FOREIGN KEY (", &_74$$34, ") REFERENCES ");
				zephir_get_strval(&referenceSql, &_76$$34);
				ZEPHIR_CALL_METHOD(&_78$$34, &reference, "getreferencedtable", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_77$$34, this_ptr, "preparetable", NULL, 0, &_78$$34, &schemaName_zv);
				zephir_check_call_status();
				zephir_concat_self(&referenceSql, &_77$$34);
				ZEPHIR_CALL_METHOD(&_80$$34, &reference, "getreferencedcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_79$$34, this_ptr, "getcolumnlist", NULL, 103, &_80$$34);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_81$$34);
				ZEPHIR_CONCAT_SVS(&_81$$34, " (", &_79$$34, ")");
				zephir_concat_self(&referenceSql, &_81$$34);
				ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
					ZEPHIR_INIT_NVAR(&_82$$35);
					ZEPHIR_CONCAT_SV(&_82$$35, " ON DELETE ", &onDelete);
					zephir_concat_self(&referenceSql, &_82$$35);
				}
				ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
					ZEPHIR_INIT_NVAR(&_83$$36);
					ZEPHIR_CONCAT_SV(&_83$$36, " ON UPDATE ", &onUpdate);
					zephir_concat_self(&referenceSql, &_83$$36);
				}
				zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 285);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &references, "rewind", NULL, 0);
			zephir_check_call_status();
			_85$$33 = 1;
			while (1) {
				if (_85$$33) {
					_85$$33 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &references, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_84$$33, &references, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_84$$33)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&reference, &references, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_86$$37, &reference, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_88$$37, &reference, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_87$$37, this_ptr, "getcolumnlist", NULL, 103, &_88$$37);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_89$$37);
					ZEPHIR_CONCAT_SVSVS(&_89$$37, "CONSTRAINT \"", &_86$$37, "\" FOREIGN KEY (", &_87$$37, ") REFERENCES ");
					zephir_get_strval(&referenceSql, &_89$$37);
					ZEPHIR_CALL_METHOD(&_91$$37, &reference, "getreferencedtable", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_90$$37, this_ptr, "preparetable", NULL, 0, &_91$$37, &schemaName_zv);
					zephir_check_call_status();
					zephir_concat_self(&referenceSql, &_90$$37);
					ZEPHIR_CALL_METHOD(&_93$$37, &reference, "getreferencedcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_92$$37, this_ptr, "getcolumnlist", NULL, 103, &_93$$37);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_94$$37);
					ZEPHIR_CONCAT_SVS(&_94$$37, " (", &_92$$37, ")");
					zephir_concat_self(&referenceSql, &_94$$37);
					ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
						ZEPHIR_INIT_NVAR(&_95$$38);
						ZEPHIR_CONCAT_SV(&_95$$38, " ON DELETE ", &onDelete);
						zephir_concat_self(&referenceSql, &_95$$38);
					}
					ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
						ZEPHIR_INIT_NVAR(&_96$$39);
						ZEPHIR_CONCAT_SV(&_96$$39, " ON UPDATE ", &onUpdate);
						zephir_concat_self(&referenceSql, &_96$$39);
					}
					zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 285);
			}
		}
		ZEPHIR_INIT_NVAR(&reference);
	}
	zephir_memory_observe(&checks);
	if (zephir_array_isset_string_fetch(&checks, &definition, SL("checks"), 0)) {
		zephir_is_iterable(&checks, 0, "phalcon/Db/Dialect/Postgresql.zep", 296);
		if (Z_TYPE_P(&checks) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&checks), _97$$40)
			{
				ZEPHIR_INIT_NVAR(&check);
				ZVAL_COPY(&check, _97$$40);
				ZEPHIR_INIT_NVAR(&_99$$41);
				ZVAL_STRING(&_99$$41, "\"");
				ZEPHIR_CALL_METHOD(&_98$$41, this_ptr, "getcheckclause", &_100, 0, &check, &_99$$41);
				zephir_check_call_status();
				zephir_array_append(&createLines, &_98$$41, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 294);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &checks, "rewind", NULL, 0);
			zephir_check_call_status();
			_102$$40 = 1;
			while (1) {
				if (_102$$40) {
					_102$$40 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &checks, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_101$$40, &checks, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_101$$40)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&check, &checks, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_104$$42);
					ZVAL_STRING(&_104$$42, "\"");
					ZEPHIR_CALL_METHOD(&_103$$42, this_ptr, "getcheckclause", &_100, 0, &check, &_104$$42);
					zephir_check_call_status();
					zephir_array_append(&createLines, &_103$$42, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 294);
			}
		}
		ZEPHIR_INIT_NVAR(&check);
	}
	ZEPHIR_INIT_VAR(&_105);
	zephir_fast_join_str(&_105, SL(",\n\t"), &createLines);
	ZEPHIR_INIT_VAR(&_106);
	ZEPHIR_CONCAT_VS(&_106, &_105, "\n)");
	zephir_concat_self(&sql, &_106);
	if (zephir_array_isset_value_string(&definition, SL("options"))) {
		ZEPHIR_CALL_METHOD(&_107$$43, this_ptr, "gettableoptions", NULL, 0, &definition);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_108$$43);
		ZEPHIR_CONCAT_SV(&_108$$43, " ", &_107$$43);
		zephir_concat_self(&sql, &_108$$43);
	}
	if (zephir_is_true(&tableComment)) {
		ZEPHIR_INIT_VAR(&_109$$44);
		ZEPHIR_INIT_VAR(&_110$$44);
		ZVAL_STRING(&_110$$44, "'");
		ZEPHIR_INIT_VAR(&_111$$44);
		ZVAL_STRING(&_111$$44, "''");
		zephir_fast_str_replace(&_109$$44, &_110$$44, &_111$$44, &tableComment);
		ZEPHIR_INIT_VAR(&_112$$44);
		ZEPHIR_CONCAT_SVSVS(&_112$$44, " COMMENT ON TABLE ", &table, " IS '", &_109$$44, "';");
		zephir_concat_self(&indexSqlAfterCreate, &_112$$44);
	}
	ZEPHIR_INIT_VAR(&_113);
	ZEPHIR_CONCAT_SV(&_113, ";", &indexSqlAfterCreate);
	zephir_concat_self(&sql, &_113);
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to create a materialized view.
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createMaterializedView)
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_missingdefinitionkey_ce, "sql", "phalcon/Db/Dialect/Postgresql.zep", 319);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &viewName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSV(return_value, "CREATE MATERIALIZED VIEW ", &_0, " AS ", &viewSql);
	RETURN_MM();
}

/**
 * Generates SQL to create a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createView)
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_missingdefinitionkey_ce, "sql", "phalcon/Db/Dialect/Postgresql.zep", 335);
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeColumns)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval schema;
	zval table_zv, *schema_param = NULL;
	zend_string *table = NULL;

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(schema_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		schema_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
	} else {
		zephir_get_strval(&schema, schema_param);
	}
	if (ZEPHIR_IS_NULL(&schema)) {
		ZEPHIR_INIT_NVAR(&schema);
		ZVAL_STRING(&schema, "public");
	}
	ZEPHIR_CONCAT_SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSVSSVSS(return_value, "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, ", "c.character_maximum_length AS Size, ", "c.numeric_precision AS NumericSize, ", "c.numeric_scale AS NumericScale, c.is_nullable AS Null, ", "CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, ", "CASE WHEN c.data_type LIKE '%int%' AND ", "c.column_default LIKE '%nextval%' THEN 'auto_increment' ", "ELSE '' END AS Extra, c.ordinal_position AS Position, ", "c.column_default, des.description, ", "c.is_generated AS IsGenerated, ", "c.generation_expression AS GenerationExpression ", "FROM information_schema.columns c ", "LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, ", "kcu.table_schema FROM information_schema.table_constraints tc ", "INNER JOIN information_schema.key_column_usage kcu on ", "(kcu.constraint_name = tc.constraint_name and ", "kcu.table_name=tc.table_name and ", "kcu.table_schema=tc.table_schema) ", "WHERE tc.constraint_type='PRIMARY KEY') pkc ", "ON (c.column_name=pkc.column_name AND ", "c.table_schema = pkc.table_schema AND ", "c.table_name=pkc.table_name) ", "LEFT JOIN ( SELECT objsubid, description, relname, nspname ", "FROM pg_description ", "JOIN pg_class ON pg_description.objoid = pg_class.oid ", "JOIN pg_namespace ON pg_class.relnamespace = pg_namespace.oid ", ") des ON ( des.objsubid = C.ordinal_position ", "AND C.table_schema = des.nspname ", "AND C.TABLE_NAME = des.relname ) ", "WHERE c.table_schema='", &schema, "' ", "AND c.table_name='", &table_zv, "' ", "ORDER BY c.ordinal_position");
	RETURN_MM();
}

/**
 * Generates SQL to query indexes on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeIndexes)
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
	ZEPHIR_CONCAT_SVS(return_value, "SELECT 0 as c0, t.relname as table_name, i.relname as key_name, 3 as c3, a.attname as column_name FROM pg_class t, pg_class i, pg_index ix, pg_attribute a WHERE t.oid = ix.indrelid AND i.oid = ix.indexrelid AND a.attrelid = t.oid AND a.attnum = ANY(ix.indkey) AND t.relkind = 'r' AND t.relname = '", &table_zv, "' ORDER BY t.relname, i.relname;");
	RETURN_MM();
}

/**
 * Generates SQL to query foreign keys on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeReferences)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval schema;
	zval table_zv, *schema_param = NULL;
	zend_string *table = NULL;

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(schema_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		schema_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
	} else {
		zephir_get_strval(&schema, schema_param);
	}
	if (ZEPHIR_IS_NULL(&schema)) {
		ZEPHIR_INIT_NVAR(&schema);
		ZVAL_STRING(&schema, "public");
	}
	ZEPHIR_CONCAT_SVSVS(return_value, "SELECT DISTINCT tc.table_name AS TABLE_NAME, kcu.column_name AS COLUMN_NAME, tc.constraint_name AS CONSTRAINT_NAME, tc.table_catalog AS REFERENCED_TABLE_SCHEMA, ccu.table_name AS REFERENCED_TABLE_NAME, ccu.column_name AS REFERENCED_COLUMN_NAME, rc.update_rule AS UPDATE_RULE, rc.delete_rule AS DELETE_RULE FROM information_schema.table_constraints AS tc JOIN information_schema.key_column_usage AS kcu ON tc.constraint_name = kcu.constraint_name JOIN information_schema.constraint_column_usage AS ccu ON ccu.constraint_name = tc.constraint_name JOIN information_schema.referential_constraints rc ON tc.constraint_catalog = rc.constraint_catalog AND tc.constraint_schema = rc.constraint_schema AND tc.constraint_name = rc.constraint_name AND tc.constraint_type = 'FOREIGN KEY' WHERE constraint_type = 'FOREIGN KEY' AND tc.table_schema = '", &schema, "' AND tc.table_name='", &table_zv, "'");
	RETURN_MM();
}

/**
 * Generates SQL to delete a column from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropColumn)
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
 * Generates SQL to delete a CHECK constraint from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropCheck)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, checkName_zv, _0;
	zend_string *tableName = NULL, *schemaName = NULL, *checkName = NULL;
	zval *this_ptr = getThis();

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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP CONSTRAINT \"", &checkName_zv, "\"");
	RETURN_MM();
}

/**
 * Generates SQL to delete a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropForeignKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, referenceName_zv, _0;
	zend_string *tableName = NULL, *schemaName = NULL, *referenceName = NULL;
	zval *this_ptr = getThis();

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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP CONSTRAINT \"", &referenceName_zv, "\"");
	RETURN_MM();
}

/**
 * Generates SQL to delete an index from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropIndex)
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
	ZEPHIR_CONCAT_SVS(return_value, "DROP INDEX \"", &indexName_zv, "\"");
	return;
}

/**
 * Generates SQL to delete primary key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, _0;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

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
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP CONSTRAINT \"", &tableName_zv, "_PRIMARY\"");
	RETURN_MM();
}

/**
 * Generates SQL to drop a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropTable)
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
 * Generates SQL to drop a materialized view.
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropMaterializedView)
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
		ZEPHIR_CONCAT_SV(return_value, "DROP MATERIALIZED VIEW IF EXISTS ", &view);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SV(return_value, "DROP MATERIALIZED VIEW ", &view);
	RETURN_MM();
}

/**
 * Generates SQL to drop a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropView)
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
 * Generates SQL to refresh a materialized view. When `concurrent` is
 * true, emits `REFRESH MATERIALIZED VIEW CONCURRENTLY ...` (avoids
 * blocking concurrent SELECTs; requires a unique index on the view).
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, refreshMaterializedView)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool concurrent;
	zval viewName_zv, schemaName_zv, *concurrent_param = NULL, view;
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
		Z_PARAM_BOOL(concurrent)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		concurrent_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&viewName_zv);
	ZVAL_STR_COPY(&viewName_zv, viewName);
	if (!schemaName) {
		ZEPHIR_INIT_VAR(&schemaName_zv);
	} else {
		zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	}
	if (!concurrent_param) {
		concurrent = 0;
	} else {
		}
	ZEPHIR_CALL_METHOD(&view, this_ptr, "preparetable", NULL, 0, &viewName_zv, &schemaName_zv);
	zephir_check_call_status();
	if (concurrent) {
		ZEPHIR_CONCAT_SV(return_value, "REFRESH MATERIALIZED VIEW CONCURRENTLY ", &view);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SV(return_value, "REFRESH MATERIALIZED VIEW ", &view);
	RETURN_MM();
}

/**
 * Gets the column name in PostgreSQL
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getColumnDefinition)
{
	zend_bool _14$$76;
	zval valueSql$$76;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, columnType, columnSql, typeValues, _25, _0$$4, _1$$9, _2$$15, _3$$20, _4$$35, _5$$74, _6$$74, _7$$74, value$$76, *_8$$76, _13$$76, _18$$76, _19$$76, _20$$76, _21$$76, _9$$77, _10$$77, _12$$77, _15$$78, _16$$78, _17$$78, _22$$79, _23$$79, _24$$79;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&columnSql);
	ZVAL_UNDEF(&typeValues);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$9);
	ZVAL_UNDEF(&_2$$15);
	ZVAL_UNDEF(&_3$$20);
	ZVAL_UNDEF(&_4$$35);
	ZVAL_UNDEF(&_5$$74);
	ZVAL_UNDEF(&_6$$74);
	ZVAL_UNDEF(&_7$$74);
	ZVAL_UNDEF(&value$$76);
	ZVAL_UNDEF(&_13$$76);
	ZVAL_UNDEF(&_18$$76);
	ZVAL_UNDEF(&_19$$76);
	ZVAL_UNDEF(&_20$$76);
	ZVAL_UNDEF(&_21$$76);
	ZVAL_UNDEF(&_9$$77);
	ZVAL_UNDEF(&_10$$77);
	ZVAL_UNDEF(&_12$$77);
	ZVAL_UNDEF(&_15$$78);
	ZVAL_UNDEF(&_16$$78);
	ZVAL_UNDEF(&_17$$78);
	ZVAL_UNDEF(&_22$$79);
	ZVAL_UNDEF(&_23$$79);
	ZVAL_UNDEF(&_24$$79);
	ZVAL_UNDEF(&valueSql$$76);
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
				ZEPHIR_CALL_METHOD(&_0$$4, column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_0$$4)) {
					zephir_concat_self_str(&columnSql, SL("BIGSERIAL"));
				} else {
					zephir_concat_self_str(&columnSql, SL("BIGINT"));
				}
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 8)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("BOOLEAN"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 5)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHARACTER"));
			}
			ZEPHIR_CALL_METHOD(&_1$$9, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_1$$9);
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
				zephir_concat_self_str(&columnSql, SL("TIMESTAMP"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 3)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("NUMERIC"));
			}
			ZEPHIR_CALL_METHOD(&_2$$15, this_ptr, "getcolumnsizeandscale", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_2$$15);
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
				ZEPHIR_CALL_METHOD(&_3$$20, column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_3$$20)) {
					zephir_concat_self_str(&columnSql, SL("SERIAL"));
				} else {
					zephir_concat_self_str(&columnSql, SL("INT"));
				}
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 22)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("SMALLINT"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 15)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("JSON"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 16)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("JSONB"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 17)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TIMESTAMP"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 6)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TEXT"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 29)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("UUID"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 2)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHARACTER VARYING"));
			}
			ZEPHIR_CALL_METHOD(&_4$$35, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_4$$35);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 30)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("BYTEA"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 31)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("INET"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 32)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CIDR"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 33)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("MACADDR"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 34)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("INT4RANGE"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 35)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("INT8RANGE"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 36)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("NUMRANGE"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 37)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TSRANGE"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 38)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TSTZRANGE"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 39)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DATERANGE"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 40)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("GEOMETRY"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 41)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("POINT"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 42)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("LINESTRING"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 43)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("POLYGON"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 44)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("MULTIPOINT"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 45)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("MULTILINESTRING"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 46)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("MULTIPOLYGON"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 47)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("GEOMETRYCOLLECTION"));
			}
			break;
		}
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&columnSql))) {
			ZEPHIR_INIT_VAR(&_5$$74);
			object_init_ex(&_5$$74, phalcon_db_exceptions_unrecognizeddatatype_ce);
			ZEPHIR_CALL_METHOD(&_6$$74, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_7$$74);
			ZVAL_STRING(&_7$$74, "PostgreSQL");
			ZEPHIR_CALL_METHOD(NULL, &_5$$74, "__construct", NULL, 435, &_7$$74, &_6$$74);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$74, "phalcon/Db/Dialect/Postgresql.zep", 786);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&typeValues, column, "gettypevalues", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&typeValues))) {
			if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(&valueSql$$76);
				ZVAL_STRING(&valueSql$$76, "");
				zephir_is_iterable(&typeValues, 0, "phalcon/Db/Dialect/Postgresql.zep", 801);
				if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&typeValues), _8$$76)
					{
						ZEPHIR_INIT_NVAR(&value$$76);
						ZVAL_COPY(&value$$76, _8$$76);
						ZEPHIR_INIT_NVAR(&_9$$77);
						ZVAL_STRING(&_9$$77, "\'");
						ZEPHIR_CALL_FUNCTION(&_10$$77, "addcslashes", &_11, 432, &value$$76, &_9$$77);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_12$$77);
						ZEPHIR_CONCAT_SVS(&_12$$77, "'", &_10$$77, "', ");
						zephir_concat_self(&valueSql$$76, &_12$$77);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &typeValues, "rewind", NULL, 0);
					zephir_check_call_status();
					_14$$76 = 1;
					while (1) {
						if (_14$$76) {
							_14$$76 = 0;
						} else {
							ZEPHIR_CALL_METHOD(NULL, &typeValues, "next", NULL, 0);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(&_13$$76, &typeValues, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_13$$76)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&value$$76, &typeValues, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_15$$78);
							ZVAL_STRING(&_15$$78, "\'");
							ZEPHIR_CALL_FUNCTION(&_16$$78, "addcslashes", &_11, 432, &value$$76, &_15$$78);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_17$$78);
							ZEPHIR_CONCAT_SVS(&_17$$78, "'", &_16$$78, "', ");
							zephir_concat_self(&valueSql$$76, &_17$$78);
					}
				}
				ZEPHIR_INIT_NVAR(&value$$76);
				ZVAL_LONG(&_18$$76, 0);
				ZVAL_LONG(&_19$$76, -2);
				ZEPHIR_INIT_VAR(&_20$$76);
				zephir_substr(&_20$$76, &valueSql$$76, 0 , -2 , 0);
				ZEPHIR_INIT_VAR(&_21$$76);
				ZEPHIR_CONCAT_SVS(&_21$$76, "(", &_20$$76, ")");
				zephir_concat_self(&columnSql, &_21$$76);
			} else {
				ZEPHIR_INIT_VAR(&_22$$79);
				ZVAL_STRING(&_22$$79, "\'");
				ZEPHIR_CALL_FUNCTION(&_23$$79, "addcslashes", &_11, 432, &typeValues, &_22$$79);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_24$$79);
				ZEPHIR_CONCAT_SVS(&_24$$79, "('", &_23$$79, "')");
				zephir_concat_self(&columnSql, &_24$$79);
			}
		}
	} while(0);

	ZEPHIR_CALL_METHOD(&_25, column, "isarray", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_25)) {
		zephir_concat_self_str(&columnSql, SL("[]"));
	}
	RETURN_CCTOR(&columnSql);
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listTables)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *schemaName_param = NULL;
	zval schemaName;

	ZVAL_UNDEF(&schemaName);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(schemaName_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &schemaName_param);
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}
	if (ZEPHIR_IS_NULL(&schemaName)) {
		ZEPHIR_INIT_NVAR(&schemaName);
		ZVAL_STRING(&schemaName, "public");
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT table_name FROM information_schema.tables WHERE table_schema = '", &schemaName, "' ORDER BY table_name");
	RETURN_MM();
}

/**
 * Generates the SQL to list all views of a schema or user
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, listViews)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *schemaName_param = NULL;
	zval schemaName;

	ZVAL_UNDEF(&schemaName);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(schemaName_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &schemaName_param);
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}
	if (ZEPHIR_IS_NULL(&schemaName)) {
		ZEPHIR_INIT_NVAR(&schemaName);
		ZVAL_STRING(&schemaName, "public");
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT viewname AS view_name FROM pg_views WHERE schemaname = '", &schemaName, "' ORDER BY view_name");
	RETURN_MM();
}

/**
 * Generates SQL to modify a column in a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, modifyColumn)
{
	zend_bool _29$$10;
	zval sql, sqlAlterTable;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, defaultValue, columnDefinition, _0, _1, _2, _3, _7, _8, _11, _12, _18, _26, _27, _4$$4, _5$$4, _6$$4, _9$$5, _10$$5, _13$$6, _14$$7, _15$$7, _16$$8, _17$$8, _19$$9, _20$$9, _21$$9, _22$$9, _23$$9, _24$$9, _25$$9, _28$$10, _30$$10, _33$$10, _31$$11, _32$$11, _34$$12, _35$$12;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&currentColumn_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_30$$10);
	ZVAL_UNDEF(&_33$$10);
	ZVAL_UNDEF(&_31$$11);
	ZVAL_UNDEF(&_32$$11);
	ZVAL_UNDEF(&_34$$12);
	ZVAL_UNDEF(&_35$$12);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&sqlAlterTable);
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
		ZEPHIR_CPY_WRT(currentColumn, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(currentColumn);
	}
	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "");
	ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "ALTER TABLE ", &_0);
	zephir_get_strval(&sqlAlterTable, &_1);
	if (Z_TYPE_P(currentColumn) != IS_OBJECT) {
		ZEPHIR_CPY_WRT(currentColumn, column);
	}
	ZEPHIR_CALL_METHOD(&_2, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, currentColumn, "getname", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_2, &_3)) {
		ZEPHIR_CALL_METHOD(&_4$$4, currentColumn, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$4, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$4);
		ZEPHIR_CONCAT_VSVSVS(&_6$$4, &sqlAlterTable, " RENAME COLUMN \"", &_4$$4, "\" TO \"", &_5$$4, "\";");
		zephir_concat_self(&sql, &_6$$4);
	}
	ZEPHIR_CALL_METHOD(&_7, column, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, currentColumn, "gettype", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_7, &_8)) {
		ZEPHIR_CALL_METHOD(&_9$$5, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$5);
		ZEPHIR_CONCAT_VSVSVS(&_10$$5, &sqlAlterTable, " ALTER COLUMN \"", &_9$$5, "\" TYPE ", &columnDefinition, ";");
		zephir_concat_self(&sql, &_10$$5);
	}
	ZEPHIR_CALL_METHOD(&_11, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, currentColumn, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_11, &_12)) {
		ZEPHIR_CALL_METHOD(&_13$$6, column, "isnotnull", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_13$$6)) {
			ZEPHIR_CALL_METHOD(&_14$$7, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_15$$7);
			ZEPHIR_CONCAT_VSVS(&_15$$7, &sqlAlterTable, " ALTER COLUMN \"", &_14$$7, "\" SET NOT NULL;");
			zephir_concat_self(&sql, &_15$$7);
		} else {
			ZEPHIR_CALL_METHOD(&_16$$8, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_17$$8);
			ZEPHIR_CONCAT_VSVS(&_17$$8, &sqlAlterTable, " ALTER COLUMN \"", &_16$$8, "\" DROP NOT NULL;");
			zephir_concat_self(&sql, &_17$$8);
		}
	}
	ZEPHIR_CALL_METHOD(&_18, column, "getcomment", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_18)) {
		ZEPHIR_CALL_METHOD(&_19$$9, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_20$$9, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_21$$9);
		ZEPHIR_CALL_METHOD(&_22$$9, column, "getcomment", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_23$$9);
		ZVAL_STRING(&_23$$9, "'");
		ZEPHIR_INIT_VAR(&_24$$9);
		ZVAL_STRING(&_24$$9, "''");
		zephir_fast_str_replace(&_21$$9, &_23$$9, &_24$$9, &_22$$9);
		ZEPHIR_INIT_VAR(&_25$$9);
		ZEPHIR_CONCAT_SVSVSVS(&_25$$9, "COMMENT ON COLUMN ", &_19$$9, ".\"", &_20$$9, "\" IS '", &_21$$9, "';");
		zephir_concat_self(&sql, &_25$$9);
	}
	ZEPHIR_CALL_METHOD(&_26, column, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_27, currentColumn, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_26, &_27)) {
		ZEPHIR_CALL_METHOD(&_28$$10, column, "hasdefault", NULL, 0);
		zephir_check_call_status();
		_29$$10 = !zephir_is_true(&_28$$10);
		if (_29$$10) {
			ZEPHIR_CALL_METHOD(&_30$$10, currentColumn, "hasdefault", NULL, 0);
			zephir_check_call_status();
			_29$$10 = zephir_is_true(&_30$$10);
		}
		if (_29$$10) {
			ZEPHIR_CALL_METHOD(&_31$$11, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_32$$11);
			ZEPHIR_CONCAT_VSVS(&_32$$11, &sqlAlterTable, " ALTER COLUMN \"", &_31$$11, "\" DROP DEFAULT;");
			zephir_concat_self(&sql, &_32$$11);
		}
		ZEPHIR_CALL_METHOD(&_33$$10, column, "hasdefault", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_33$$10)) {
			ZEPHIR_CALL_METHOD(&defaultValue, this_ptr, "castdefault", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_34$$12, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_35$$12);
			ZEPHIR_CONCAT_VSVSV(&_35$$12, &sqlAlterTable, " ALTER COLUMN \"", &_34$$12, "\" SET DEFAULT ", &defaultValue);
			zephir_concat_self(&sql, &_35$$12);
		}
	}
	RETURN_CTOR(&sql);
}

/**
 * Appends a `RETURNING` clause to the supplied INSERT/UPDATE/DELETE
 * statement. Pass `["*"]` for `RETURNING *`, or a list of column names.
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, returning)
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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 437);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Db/Dialect/Postgresql.zep", 910);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_fast_count_int(&columns) == 1) {
		zephir_memory_observe(&_1$$4);
		zephir_array_fetch_long(&_1$$4, &columns, 0, PH_NOISY, "phalcon/Db/Dialect/Postgresql.zep", 914);
		zephir_cast_to_string(&_2$$4, &_1$$4);
		ZEPHIR_CPY_WRT(&first, &_2$$4);
		if (ZEPHIR_IS_STRING(&first, "*")) {
			ZEPHIR_CONCAT_VS(return_value, &sqlQuery_zv, " RETURNING *");
			RETURN_MM();
		}
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getcolumnlist", NULL, 103, &columns);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &sqlQuery_zv, " RETURNING ", &_3);
	RETURN_MM();
}

/**
 * Returns a SQL modified with a `FOR SHARE` clause - PostgreSQL's
 * equivalent of MySQL's `LOCK IN SHARE MODE`. The optional `modifier`
 * appends a row-lock disposition keyword (pass `Dialect::LOCK_NOWAIT`
 * or `Dialect::LOCK_SKIP_LOCKED`).
 *
 *```php
 * echo $dialect->sharedLock("SELECT * FROM robots");
 * // SELECT * FROM robots FOR SHARE
 *
 * echo $dialect->sharedLock(
 *     "SELECT * FROM robots",
 *     Dialect::LOCK_NOWAIT
 * );
 * // SELECT * FROM robots FOR SHARE NOWAIT
 *```
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, sharedLock)
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
	if (!ZEPHIR_IS_STRING_IDENTICAL(&modifier_zv, "")) {
		ZEPHIR_CONCAT_VSV(return_value, &sqlQuery_zv, " FOR SHARE ", &modifier_zv);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_VS(return_value, &sqlQuery_zv, " FOR SHARE");
	RETURN_MM();
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval schemaName;
	zval tableName_zv, *schemaName_param = NULL;
	zend_string *tableName = NULL;

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(tableName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(schemaName_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		schemaName_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}
	if (ZEPHIR_IS_NULL(&schemaName)) {
		ZEPHIR_INIT_NVAR(&schemaName);
		ZVAL_STRING(&schemaName, "public");
	}
	ZEPHIR_CONCAT_SVSVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = '", &schemaName, "' AND table_name='", &tableName_zv, "'");
	RETURN_MM();
}

/**
 * Generates the SQL to describe the table creation options
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableOptions)
{
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval table_zv, schema_zv;
	zend_string *table = NULL, *schema = NULL;

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_UNDEF(&sql);
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
	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CONCAT_SVS(&sql, "SELECT obj_description(c.oid, 'pg_class') AS table_comment FROM pg_class c JOIN pg_namespace n ON n.oid = c.relnamespace WHERE c.relname = '", &table_zv, "' AND ");
	if (!(ZEPHIR_IS_EMPTY(&schema_zv))) {
		ZEPHIR_CONCAT_VSVS(return_value, &sql, "n.nspname = '", &schema_zv, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_VS(return_value, &sql, "n.nspname = current_schema()");
	RETURN_MM();
}

/**
 * Generates SQL to truncate a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, truncateTable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, table;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

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
		ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName_zv, &schemaName_zv);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName_zv);
		zephir_check_call_status();
	}
	ZEPHIR_CONCAT_SV(return_value, "TRUNCATE TABLE ", &table);
	RETURN_MM();
}

/**
 * Generates SQL checking for the existence of a schema.view
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, viewExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval schemaName;
	zval viewName_zv, *schemaName_param = NULL;
	zend_string *viewName = NULL;

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(viewName)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(schemaName_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		schemaName_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&viewName_zv);
	ZVAL_STR_COPY(&viewName_zv, viewName);
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}
	if (ZEPHIR_IS_NULL(&schemaName)) {
		ZEPHIR_INIT_NVAR(&schemaName);
		ZVAL_STRING(&schemaName, "public");
	}
	ZEPHIR_CONCAT_SVSVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='", &viewName_zv, "' AND schemaname='", &schemaName, "'");
	RETURN_MM();
}

PHP_METHOD(Phalcon_Db_Dialect_Postgresql, castDefault)
{
	zend_bool _0, _7, _8, _9, _10, _4$$4, _5$$4;
	zval preparedValue, _2$$4, _11$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, defaultValue, columnDefinition, columnType, _1, _6, boolStr$$4, _3$$4, _12$$7, _13$$7, _14$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&boolStr$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&preparedValue);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_11$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &column);
	ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
	zephir_check_call_status();
	_0 = Z_TYPE_P(&defaultValue) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(&defaultValue, phalcon_db_rawvalue_ce);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(&defaultValue, "getvalue", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnType, column, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtoupper(&_1, &columnDefinition);
	if (zephir_memnstr_str(&_1, SL("BOOLEAN"), "phalcon/Db/Dialect/Postgresql.zep", 1031)) {
		zephir_cast_to_string(&_2$$4, &defaultValue);
		ZEPHIR_INIT_VAR(&boolStr$$4);
		zephir_fast_strtolower(&boolStr$$4, &_2$$4);
		ZEPHIR_CPY_WRT(&boolStr$$4, &boolStr$$4);
		ZEPHIR_INIT_VAR(&_3$$4);
		_4$$4 = ZEPHIR_IS_STRING(&boolStr$$4, "false");
		if (!(_4$$4)) {
			_4$$4 = ZEPHIR_IS_STRING(&boolStr$$4, "0");
		}
		_5$$4 = _4$$4;
		if (!(_5$$4)) {
			_5$$4 = ZEPHIR_IS_STRING(&boolStr$$4, "");
		}
		if (_5$$4) {
			ZEPHIR_INIT_NVAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "false");
		} else {
			ZEPHIR_INIT_NVAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "true");
		}
		RETURN_CCTOR(&_3$$4);
	}
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_strtoupper(&_6, &defaultValue);
	if (zephir_memnstr_str(&_6, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Postgresql.zep", 1037)) {
		RETURN_MM_STRING("CURRENT_TIMESTAMP");
	}
	_7 = ZEPHIR_IS_LONG_IDENTICAL(&columnType, 0);
	if (!(_7)) {
		_7 = ZEPHIR_IS_LONG_IDENTICAL(&columnType, 14);
	}
	_8 = _7;
	if (!(_8)) {
		_8 = ZEPHIR_IS_LONG_IDENTICAL(&columnType, 3);
	}
	_9 = _8;
	if (!(_9)) {
		_9 = ZEPHIR_IS_LONG_IDENTICAL(&columnType, 7);
	}
	_10 = _9;
	if (!(_10)) {
		_10 = ZEPHIR_IS_LONG_IDENTICAL(&columnType, 9);
	}
	if (_10) {
		zephir_cast_to_string(&_11$$6, &defaultValue);
		ZEPHIR_CPY_WRT(&preparedValue, &_11$$6);
	} else {
		ZEPHIR_INIT_VAR(&_12$$7);
		ZVAL_STRING(&_12$$7, "\'");
		ZEPHIR_CALL_FUNCTION(&_13$$7, "addcslashes", NULL, 432, &defaultValue, &_12$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_14$$7);
		ZEPHIR_CONCAT_SVS(&_14$$7, "'", &_13$$7, "'");
		zephir_get_strval(&preparedValue, &_14$$7);
	}
	RETURN_CTOR(&preparedValue);
}

PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getTableOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *definition_param = NULL;
	zval definition;

	ZVAL_UNDEF(&definition);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(definition, definition_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &definition_param);
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	RETURN_MM_STRING("");
}

zend_object *zephir_init_properties_Phalcon_Db_Dialect_Postgresql(zend_class_entry *class_type)
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
			zephir_create_array(&_6$$5, 9, 0);
			ZEPHIR_INIT_VAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "@@");
			zephir_array_fast_append(&_6$$5, &_7$$5);
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "@>");
			zephir_array_fast_append(&_6$$5, &_7$$5);
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "<@");
			zephir_array_fast_append(&_6$$5, &_7$$5);
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "&&");
			zephir_array_fast_append(&_6$$5, &_7$$5);
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "||");
			zephir_array_fast_append(&_6$$5, &_7$$5);
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "->");
			zephir_array_fast_append(&_6$$5, &_7$$5);
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "->>");
			zephir_array_fast_append(&_6$$5, &_7$$5);
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "#>");
			zephir_array_fast_append(&_6$$5, &_7$$5);
			ZEPHIR_INIT_NVAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "#>>");
			zephir_array_fast_append(&_6$$5, &_7$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("supportedOperators"), &_6$$5);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

