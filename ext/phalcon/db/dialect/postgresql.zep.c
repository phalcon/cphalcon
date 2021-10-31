
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"


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
	return SUCCESS;
}

/**
 * Generates SQL to add a column to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addColumn)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, columnDefinition, _0, _1, _2, _3, _4, _7, _5$$3, _6$$3;
	zval tableName, schemaName, sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &column);
	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "ALTER TABLE ", &_0, " ADD COLUMN ");
	zephir_get_strval(&sql, &_1);
	ZEPHIR_CALL_METHOD(&_2, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVSV(&_3, "\"", &_2, "\" ", &columnDefinition);
	zephir_concat_self(&sql, &_3);
	ZEPHIR_CALL_METHOD(&_4, column, "hasdefault", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		ZEPHIR_CALL_METHOD(&_5$$3, this_ptr, "castdefault", NULL, 0, column);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SV(&_6$$3, " DEFAULT ", &_5$$3);
		zephir_concat_self(&sql, &_6$$3);
	}
	ZEPHIR_CALL_METHOD(&_7, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		zephir_concat_self_str(&sql, " NOT NULL", sizeof(" NOT NULL") - 1);
	} else {
		zephir_concat_self_str(&sql, " NULL", sizeof(" NULL") - 1);
	}
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addForeignKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, reference_sub, onDelete, onUpdate, _0, _1, _2, _5, _6, _7, _8, _9, _10, _3$$3, _4$$3, _11$$4, _12$$5;
	zval tableName, schemaName, sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(reference, phalcon_db_referenceinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &reference);
	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
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
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumnlist", NULL, 67, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, reference, "getreferencedtable", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, reference, "getreferencedcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "getcolumnlist", NULL, 67, &_9);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, index_sub, indexType, _0, _2, _3, _4, _5, _6, _7, _1$$4;
	zval tableName, schemaName, sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(index, phalcon_db_indexinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);
	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
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
		zephir_concat_self(&sql, &_1$$4);
	}
	ZEPHIR_CALL_METHOD(&_2, index, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVSV(&_4, " INDEX \"", &_2, "\" ON ", &_3);
	zephir_concat_self(&sql, &_4);
	ZEPHIR_CALL_METHOD(&_6, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumnlist", NULL, 67, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SVS(&_7, " (", &_5, ")");
	zephir_concat_self(&sql, &_7);
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to add the primary key to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, addPrimaryKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(index, phalcon_db_indexinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);
	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcolumnlist", NULL, 67, &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVSVS(return_value, "ALTER TABLE ", &_0, " ADD CONSTRAINT \"", &tableName, "_PRIMARY\" PRIMARY KEY (", &_1, ")");
	RETURN_MM();
}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createTable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition, createLines, primaryColumns;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, temporary, options, table, columns, column, indexes, index, reference, references, indexName, indexType, onDelete, onUpdate, columnDefinition, *_2, _3, _82, _83, _0$$5, _1$$6, _5$$7, _6$$7, _7$$7, _11$$7, _12$$7, _14$$7, _8$$8, _10$$8, _13$$11, _15$$12, _16$$12, _17$$12, _18$$13, _19$$13, _20$$13, _23$$13, _24$$13, _26$$13, _21$$14, _22$$14, _25$$17, _27$$18, _28$$18, _29$$18, _30$$19, _31$$19, *_32$$20, _33$$20, _34$$22, _35$$22, _36$$22, _37$$24, _38$$24, _39$$24, _40$$25, _41$$25, _42$$25, _43$$25, _44$$25, _45$$25, _46$$28, _47$$28, _48$$28, _49$$30, _50$$30, _51$$30, _52$$31, _53$$31, _54$$31, _55$$31, _56$$31, _57$$31, *_58$$33, _59$$33, _60$$34, _61$$34, _62$$34, _63$$34, _64$$34, _65$$34, _66$$34, _67$$34, _68$$34, _69$$35, _70$$36, _71$$37, _72$$37, _73$$37, _74$$37, _75$$37, _76$$37, _77$$37, _78$$37, _79$$37, _80$$38, _81$$39, _84$$40, _85$$40;
	zval tableName, schemaName, indexSql, indexSqlAfterCreate, columnLine, referenceSql, sql, _86;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&indexSql);
	ZVAL_UNDEF(&indexSqlAfterCreate);
	ZVAL_UNDEF(&columnLine);
	ZVAL_UNDEF(&referenceSql);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_86);
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_82);
	ZVAL_UNDEF(&_83);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_33$$20);
	ZVAL_UNDEF(&_34$$22);
	ZVAL_UNDEF(&_35$$22);
	ZVAL_UNDEF(&_36$$22);
	ZVAL_UNDEF(&_37$$24);
	ZVAL_UNDEF(&_38$$24);
	ZVAL_UNDEF(&_39$$24);
	ZVAL_UNDEF(&_40$$25);
	ZVAL_UNDEF(&_41$$25);
	ZVAL_UNDEF(&_42$$25);
	ZVAL_UNDEF(&_43$$25);
	ZVAL_UNDEF(&_44$$25);
	ZVAL_UNDEF(&_45$$25);
	ZVAL_UNDEF(&_46$$28);
	ZVAL_UNDEF(&_47$$28);
	ZVAL_UNDEF(&_48$$28);
	ZVAL_UNDEF(&_49$$30);
	ZVAL_UNDEF(&_50$$30);
	ZVAL_UNDEF(&_51$$30);
	ZVAL_UNDEF(&_52$$31);
	ZVAL_UNDEF(&_53$$31);
	ZVAL_UNDEF(&_54$$31);
	ZVAL_UNDEF(&_55$$31);
	ZVAL_UNDEF(&_56$$31);
	ZVAL_UNDEF(&_57$$31);
	ZVAL_UNDEF(&_59$$33);
	ZVAL_UNDEF(&_60$$34);
	ZVAL_UNDEF(&_61$$34);
	ZVAL_UNDEF(&_62$$34);
	ZVAL_UNDEF(&_63$$34);
	ZVAL_UNDEF(&_64$$34);
	ZVAL_UNDEF(&_65$$34);
	ZVAL_UNDEF(&_66$$34);
	ZVAL_UNDEF(&_67$$34);
	ZVAL_UNDEF(&_68$$34);
	ZVAL_UNDEF(&_69$$35);
	ZVAL_UNDEF(&_70$$36);
	ZVAL_UNDEF(&_71$$37);
	ZVAL_UNDEF(&_72$$37);
	ZVAL_UNDEF(&_73$$37);
	ZVAL_UNDEF(&_74$$37);
	ZVAL_UNDEF(&_75$$37);
	ZVAL_UNDEF(&_76$$37);
	ZVAL_UNDEF(&_77$$37);
	ZVAL_UNDEF(&_78$$37);
	ZVAL_UNDEF(&_79$$37);
	ZVAL_UNDEF(&_80$$38);
	ZVAL_UNDEF(&_81$$39);
	ZVAL_UNDEF(&_84$$40);
	ZVAL_UNDEF(&_85$$40);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&createLines);
	ZVAL_UNDEF(&primaryColumns);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_ARRAY(definition)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition_param);
	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);


	ZEPHIR_OBS_VAR(&columns);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array", "phalcon/Db/Dialect/Postgresql.zep", 134);
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
	ZEPHIR_INIT_VAR(&createLines);
	array_init(&createLines);
	ZEPHIR_INIT_VAR(&primaryColumns);
	array_init(&primaryColumns);
	zephir_is_iterable(&columns, 0, "phalcon/Db/Dialect/Postgresql.zep", 198);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _2)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _2);
			ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", &_4, 0, &column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5$$7, &column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_6$$7);
			ZEPHIR_CONCAT_SVSV(&_6$$7, "\"", &_5$$7, "\" ", &columnDefinition);
			zephir_get_strval(&columnLine, &_6$$7);
			ZEPHIR_CALL_METHOD(&_7$$7, &column, "hasdefault", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_7$$7)) {
				ZEPHIR_CALL_METHOD(&_8$$8, this_ptr, "castdefault", &_9, 0, &column);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$8);
				ZEPHIR_CONCAT_SV(&_10$$8, " DEFAULT ", &_8$$8);
				zephir_concat_self(&columnLine, &_10$$8);
			}
			ZEPHIR_CALL_METHOD(&_11$$7, &column, "isnotnull", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_11$$7)) {
				zephir_concat_self_str(&columnLine, " NOT NULL", sizeof(" NOT NULL") - 1);
			} else {
				zephir_concat_self_str(&columnLine, " NULL", sizeof(" NULL") - 1);
			}
			ZEPHIR_CALL_METHOD(&_12$$7, &column, "isprimary", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_12$$7)) {
				ZEPHIR_CALL_METHOD(&_13$$11, &column, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_array_append(&primaryColumns, &_13$$11, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 185);
			}
			zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 188);
			ZEPHIR_CALL_METHOD(&_14$$7, &column, "getcomment", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_14$$7)) {
				ZEPHIR_CALL_METHOD(&_15$$12, &column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_16$$12, &column, "getcomment", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_17$$12);
				ZEPHIR_CONCAT_SVSVSVS(&_17$$12, " COMMENT ON COLUMN ", &table, ".\"", &_15$$12, "\" IS '", &_16$$12, "';");
				zephir_concat_self(&indexSqlAfterCreate, &_17$$12);
			}
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
				ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", &_4, 0, &column);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_18$$13, &column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_19$$13);
				ZEPHIR_CONCAT_SVSV(&_19$$13, "\"", &_18$$13, "\" ", &columnDefinition);
				zephir_get_strval(&columnLine, &_19$$13);
				ZEPHIR_CALL_METHOD(&_20$$13, &column, "hasdefault", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_20$$13)) {
					ZEPHIR_CALL_METHOD(&_21$$14, this_ptr, "castdefault", &_9, 0, &column);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_22$$14);
					ZEPHIR_CONCAT_SV(&_22$$14, " DEFAULT ", &_21$$14);
					zephir_concat_self(&columnLine, &_22$$14);
				}
				ZEPHIR_CALL_METHOD(&_23$$13, &column, "isnotnull", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_23$$13)) {
					zephir_concat_self_str(&columnLine, " NOT NULL", sizeof(" NOT NULL") - 1);
				} else {
					zephir_concat_self_str(&columnLine, " NULL", sizeof(" NULL") - 1);
				}
				ZEPHIR_CALL_METHOD(&_24$$13, &column, "isprimary", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_24$$13)) {
					ZEPHIR_CALL_METHOD(&_25$$17, &column, "getname", NULL, 0);
					zephir_check_call_status();
					zephir_array_append(&primaryColumns, &_25$$17, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 185);
				}
				zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 188);
				ZEPHIR_CALL_METHOD(&_26$$13, &column, "getcomment", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_26$$13)) {
					ZEPHIR_CALL_METHOD(&_27$$18, &column, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_28$$18, &column, "getcomment", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_29$$18);
					ZEPHIR_CONCAT_SVSVSVS(&_29$$18, " COMMENT ON COLUMN ", &table, ".\"", &_27$$18, "\" IS '", &_28$$18, "';");
					zephir_concat_self(&indexSqlAfterCreate, &_29$$18);
				}
			ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	if (!(ZEPHIR_IS_EMPTY(&primaryColumns))) {
		ZEPHIR_CALL_METHOD(&_30$$19, this_ptr, "getcolumnlist", NULL, 67, &primaryColumns);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_31$$19);
		ZEPHIR_CONCAT_SVS(&_31$$19, "PRIMARY KEY (", &_30$$19, ")");
		zephir_array_append(&createLines, &_31$$19, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 199);
	}
	ZEPHIR_OBS_VAR(&indexes);
	if (zephir_array_isset_string_fetch(&indexes, &definition, SL("indexes"), 0)) {
		zephir_is_iterable(&indexes, 0, "phalcon/Db/Dialect/Postgresql.zep", 227);
		if (Z_TYPE_P(&indexes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&indexes), _32$$20)
			{
				ZEPHIR_INIT_NVAR(&index);
				ZVAL_COPY(&index, _32$$20);
				ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&indexSql);
				if (ZEPHIR_IS_STRING(&indexName, "PRIMARY")) {
					ZEPHIR_CALL_METHOD(&_35$$22, &index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_34$$22, this_ptr, "getcolumnlist", NULL, 67, &_35$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_36$$22);
					ZEPHIR_CONCAT_SVS(&_36$$22, "CONSTRAINT \"PRIMARY\" PRIMARY KEY (", &_34$$22, ")");
					zephir_get_strval(&indexSql, &_36$$22);
				} else {
					if (!(ZEPHIR_IS_EMPTY(&indexType))) {
						ZEPHIR_CALL_METHOD(&_38$$24, &index, "getcolumns", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_37$$24, this_ptr, "getcolumnlist", NULL, 67, &_38$$24);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_39$$24);
						ZEPHIR_CONCAT_SVSVSVS(&_39$$24, "CONSTRAINT \"", &indexName, "\" ", &indexType, " (", &_37$$24, ")");
						zephir_get_strval(&indexSql, &_39$$24);
					} else {
						ZEPHIR_CALL_METHOD(&_40$$25, &index, "getname", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_41$$25, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_42$$25);
						ZEPHIR_CONCAT_SVSV(&_42$$25, "CREATE INDEX \"", &_40$$25, "\" ON ", &_41$$25);
						zephir_concat_self(&indexSqlAfterCreate, &_42$$25);
						ZEPHIR_CALL_METHOD(&_44$$25, &index, "getcolumns", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_43$$25, this_ptr, "getcolumnlist", NULL, 67, &_44$$25);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_45$$25);
						ZEPHIR_CONCAT_SVS(&_45$$25, " (", &_43$$25, ");");
						zephir_concat_self(&indexSqlAfterCreate, &_45$$25);
					}
				}
				if (!(ZEPHIR_IS_EMPTY(&indexSql))) {
					zephir_array_append(&createLines, &indexSql, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 224);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &indexes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_33$$20, &indexes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_33$$20)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&index, &indexes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&indexSql);
					if (ZEPHIR_IS_STRING(&indexName, "PRIMARY")) {
						ZEPHIR_CALL_METHOD(&_47$$28, &index, "getcolumns", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_46$$28, this_ptr, "getcolumnlist", NULL, 67, &_47$$28);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_48$$28);
						ZEPHIR_CONCAT_SVS(&_48$$28, "CONSTRAINT \"PRIMARY\" PRIMARY KEY (", &_46$$28, ")");
						zephir_get_strval(&indexSql, &_48$$28);
					} else {
						if (!(ZEPHIR_IS_EMPTY(&indexType))) {
							ZEPHIR_CALL_METHOD(&_50$$30, &index, "getcolumns", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_49$$30, this_ptr, "getcolumnlist", NULL, 67, &_50$$30);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_51$$30);
							ZEPHIR_CONCAT_SVSVSVS(&_51$$30, "CONSTRAINT \"", &indexName, "\" ", &indexType, " (", &_49$$30, ")");
							zephir_get_strval(&indexSql, &_51$$30);
						} else {
							ZEPHIR_CALL_METHOD(&_52$$31, &index, "getname", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_53$$31, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_54$$31);
							ZEPHIR_CONCAT_SVSV(&_54$$31, "CREATE INDEX \"", &_52$$31, "\" ON ", &_53$$31);
							zephir_concat_self(&indexSqlAfterCreate, &_54$$31);
							ZEPHIR_CALL_METHOD(&_56$$31, &index, "getcolumns", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_55$$31, this_ptr, "getcolumnlist", NULL, 67, &_56$$31);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_57$$31);
							ZEPHIR_CONCAT_SVS(&_57$$31, " (", &_55$$31, ");");
							zephir_concat_self(&indexSqlAfterCreate, &_57$$31);
						}
					}
					if (!(ZEPHIR_IS_EMPTY(&indexSql))) {
						zephir_array_append(&createLines, &indexSql, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 224);
					}
				ZEPHIR_CALL_METHOD(NULL, &indexes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&index);
	}
	ZEPHIR_OBS_VAR(&references);
	if (zephir_array_isset_string_fetch(&references, &definition, SL("references"), 0)) {
		zephir_is_iterable(&references, 0, "phalcon/Db/Dialect/Postgresql.zep", 255);
		if (Z_TYPE_P(&references) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&references), _58$$33)
			{
				ZEPHIR_INIT_NVAR(&reference);
				ZVAL_COPY(&reference, _58$$33);
				ZEPHIR_CALL_METHOD(&_60$$34, &reference, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_62$$34, &reference, "getcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_61$$34, this_ptr, "getcolumnlist", NULL, 67, &_62$$34);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_63$$34);
				ZEPHIR_CONCAT_SVSVS(&_63$$34, "CONSTRAINT \"", &_60$$34, "\" FOREIGN KEY (", &_61$$34, ") REFERENCES ");
				zephir_get_strval(&referenceSql, &_63$$34);
				ZEPHIR_CALL_METHOD(&_65$$34, &reference, "getreferencedtable", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_64$$34, this_ptr, "preparetable", NULL, 0, &_65$$34, &schemaName);
				zephir_check_call_status();
				zephir_concat_self(&referenceSql, &_64$$34);
				ZEPHIR_CALL_METHOD(&_67$$34, &reference, "getreferencedcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_66$$34, this_ptr, "getcolumnlist", NULL, 67, &_67$$34);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_68$$34);
				ZEPHIR_CONCAT_SVS(&_68$$34, " (", &_66$$34, ")");
				zephir_concat_self(&referenceSql, &_68$$34);
				ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
					ZEPHIR_INIT_NVAR(&_69$$35);
					ZEPHIR_CONCAT_SV(&_69$$35, " ON DELETE ", &onDelete);
					zephir_concat_self(&referenceSql, &_69$$35);
				}
				ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
					ZEPHIR_INIT_NVAR(&_70$$36);
					ZEPHIR_CONCAT_SV(&_70$$36, " ON UPDATE ", &onUpdate);
					zephir_concat_self(&referenceSql, &_70$$36);
				}
				zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 253);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &references, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_59$$33, &references, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_59$$33)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&reference, &references, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_71$$37, &reference, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_73$$37, &reference, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_72$$37, this_ptr, "getcolumnlist", NULL, 67, &_73$$37);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_74$$37);
					ZEPHIR_CONCAT_SVSVS(&_74$$37, "CONSTRAINT \"", &_71$$37, "\" FOREIGN KEY (", &_72$$37, ") REFERENCES ");
					zephir_get_strval(&referenceSql, &_74$$37);
					ZEPHIR_CALL_METHOD(&_76$$37, &reference, "getreferencedtable", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_75$$37, this_ptr, "preparetable", NULL, 0, &_76$$37, &schemaName);
					zephir_check_call_status();
					zephir_concat_self(&referenceSql, &_75$$37);
					ZEPHIR_CALL_METHOD(&_78$$37, &reference, "getreferencedcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_77$$37, this_ptr, "getcolumnlist", NULL, 67, &_78$$37);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_79$$37);
					ZEPHIR_CONCAT_SVS(&_79$$37, " (", &_77$$37, ")");
					zephir_concat_self(&referenceSql, &_79$$37);
					ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
						ZEPHIR_INIT_NVAR(&_80$$38);
						ZEPHIR_CONCAT_SV(&_80$$38, " ON DELETE ", &onDelete);
						zephir_concat_self(&referenceSql, &_80$$38);
					}
					ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
						ZEPHIR_INIT_NVAR(&_81$$39);
						ZEPHIR_CONCAT_SV(&_81$$39, " ON UPDATE ", &onUpdate);
						zephir_concat_self(&referenceSql, &_81$$39);
					}
					zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Postgresql.zep", 253);
				ZEPHIR_CALL_METHOD(NULL, &references, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&reference);
	}
	ZEPHIR_INIT_VAR(&_82);
	zephir_fast_join_str(&_82, SL(",\n\t"), &createLines);
	ZEPHIR_INIT_VAR(&_83);
	ZEPHIR_CONCAT_VS(&_83, &_82, "\n)");
	zephir_concat_self(&sql, &_83);
	if (zephir_array_isset_string(&definition, SL("options"))) {
		ZEPHIR_CALL_METHOD(&_84$$40, this_ptr, "gettableoptions", NULL, 0, &definition);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_85$$40);
		ZEPHIR_CONCAT_SV(&_85$$40, " ", &_84$$40);
		zephir_concat_self(&sql, &_85$$40);
	}
	ZEPHIR_INIT_VAR(&_86);
	ZEPHIR_CONCAT_SV(&_86, ";", &indexSqlAfterCreate);
	zephir_concat_self(&sql, &_86);
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to create a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, createView)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(viewName)
		Z_PARAM_ARRAY(definition)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &viewName_param, &definition_param, &schemaName_param);
	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	ZEPHIR_OBS_VAR(&viewSql);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&viewSql, &definition, SL("sql"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array", "phalcon/Db/Dialect/Postgresql.zep", 276);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &viewName, &schemaName);
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
	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);
	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	if (ZEPHIR_IS_NULL(&schema)) {
		ZEPHIR_INIT_NVAR(&schema);
		ZVAL_STRING(&schema, "public");
	}
	ZEPHIR_CONCAT_SVSVS(return_value, "SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, c.numeric_scale AS NumericScale, c.is_nullable AS Null, CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, c.column_default, des.description FROM information_schema.columns c LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema FROM information_schema.table_constraints tc INNER JOIN information_schema.key_column_usage kcu on (kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND c.table_name=pkc.table_name) LEFT JOIN ( SELECT objsubid, description, relname, nspname FROM pg_description JOIN pg_class ON pg_description.objoid = pg_class.oid JOIN pg_namespace ON pg_class.relnamespace = pg_namespace.oid ) des ON ( des.objsubid = C.ordinal_position AND C.table_schema = des.nspname AND C.TABLE_NAME = des.relname ) WHERE c.table_schema='", &schema, "' AND c.table_name='", &table, "' ORDER BY c.ordinal_position");
	RETURN_MM();
}

/**
 * Generates SQL to query indexes on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeIndexes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);
	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_CONCAT_SVS(return_value, "SELECT 0 as c0, t.relname as table_name, i.relname as key_name, 3 as c3, a.attname as column_name FROM pg_class t, pg_class i, pg_index ix, pg_attribute a WHERE t.oid = ix.indrelid AND i.oid = ix.indexrelid AND a.attrelid = t.oid AND a.attnum = ANY(ix.indkey) AND t.relkind = 'r' AND t.relname = '", &table, "' ORDER BY t.relname, i.relname;");
	RETURN_MM();
}

/**
 * Generates SQL to query foreign keys on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, describeReferences)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);
	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	if (ZEPHIR_IS_NULL(&schema)) {
		ZEPHIR_INIT_NVAR(&schema);
		ZVAL_STRING(&schema, "public");
	}
	ZEPHIR_CONCAT_SVSVS(return_value, "SELECT DISTINCT tc.table_name AS TABLE_NAME, kcu.column_name AS COLUMN_NAME, tc.constraint_name AS CONSTRAINT_NAME, tc.table_catalog AS REFERENCED_TABLE_SCHEMA, ccu.table_name AS REFERENCED_TABLE_NAME, ccu.column_name AS REFERENCED_COLUMN_NAME, rc.update_rule AS UPDATE_RULE, rc.delete_rule AS DELETE_RULE FROM information_schema.table_constraints AS tc JOIN information_schema.key_column_usage AS kcu ON tc.constraint_name = kcu.constraint_name JOIN information_schema.constraint_column_usage AS ccu ON ccu.constraint_name = tc.constraint_name JOIN information_schema.referential_constraints rc ON tc.constraint_catalog = rc.constraint_catalog AND tc.constraint_schema = rc.constraint_schema AND tc.constraint_name = rc.constraint_name AND tc.constraint_type = 'FOREIGN KEY' WHERE constraint_type = 'FOREIGN KEY' AND tc.table_schema = '", &schema, "' AND tc.table_name='", &table, "'");
	RETURN_MM();
}

/**
 * Generates SQL to delete a column from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropColumn)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL, _0;
	zval tableName, schemaName, columnName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_STR(columnName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &columnName_param);
	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(columnName_param) != IS_STRING && Z_TYPE_P(columnName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'columnName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(columnName_param) == IS_STRING)) {
		zephir_get_strval(&columnName, columnName_param);
	} else {
		ZEPHIR_INIT_VAR(&columnName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP COLUMN \"", &columnName, "\"");
	RETURN_MM();
}

/**
 * Generates SQL to delete a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropForeignKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName_param = NULL, _0;
	zval tableName, schemaName, referenceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&referenceName);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_STR(referenceName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &referenceName_param);
	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(referenceName_param) != IS_STRING && Z_TYPE_P(referenceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceName_param) == IS_STRING)) {
		zephir_get_strval(&referenceName, referenceName_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP CONSTRAINT \"", &referenceName, "\"");
	RETURN_MM();
}

/**
 * Generates SQL to delete an index from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropIndex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName_param = NULL;
	zval tableName, schemaName, indexName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&indexName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_STR(indexName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &indexName_param);
	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(indexName_param) != IS_STRING && Z_TYPE_P(indexName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'indexName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(indexName_param) == IS_STRING)) {
		zephir_get_strval(&indexName, indexName_param);
	} else {
		ZEPHIR_INIT_VAR(&indexName);
	}


	ZEPHIR_CONCAT_SVS(return_value, "DROP INDEX \"", &indexName, "\"");
	RETURN_MM();
}

/**
 * Generates SQL to delete primary key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropPrimaryKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, _0;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);
	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP CONSTRAINT \"", &tableName, "_PRIMARY\"");
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
	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, table;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&table);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
		Z_PARAM_BOOL(ifExists)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &tableName_param, &schemaName_param, &ifExists_param);
	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
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


	ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
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
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, dropView)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, view;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&view);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(viewName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
		Z_PARAM_BOOL(ifExists)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &viewName_param, &schemaName_param, &ifExists_param);
	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
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


	ZEPHIR_CALL_METHOD(&view, this_ptr, "preparetable", NULL, 0, &viewName, &schemaName);
	zephir_check_call_status();
	if (ifExists) {
		ZEPHIR_CONCAT_SV(return_value, "DROP VIEW IF EXISTS ", &view);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SV(return_value, "DROP VIEW ", &view);
	RETURN_MM();
}

/**
 * Gets the column name in PostgreSQL
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getColumnDefinition)
{
	zval valueSql$$38;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, columnType, columnSql, typeValues, _0$$4, _1$$9, _2$$15, _3$$20, _4$$33, _5$$36, _6$$36, _7$$36, value$$38, *_8$$38, _9$$38, _17$$38, _18$$38, _19$$38, _20$$38, _10$$39, _11$$39, _13$$39, _14$$40, _15$$40, _16$$40, _21$$41, _22$$41, _23$$41;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&columnSql);
	ZVAL_UNDEF(&typeValues);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$9);
	ZVAL_UNDEF(&_2$$15);
	ZVAL_UNDEF(&_3$$20);
	ZVAL_UNDEF(&_4$$33);
	ZVAL_UNDEF(&_5$$36);
	ZVAL_UNDEF(&_6$$36);
	ZVAL_UNDEF(&_7$$36);
	ZVAL_UNDEF(&value$$38);
	ZVAL_UNDEF(&_9$$38);
	ZVAL_UNDEF(&_17$$38);
	ZVAL_UNDEF(&_18$$38);
	ZVAL_UNDEF(&_19$$38);
	ZVAL_UNDEF(&_20$$38);
	ZVAL_UNDEF(&_10$$39);
	ZVAL_UNDEF(&_11$$39);
	ZVAL_UNDEF(&_13$$39);
	ZVAL_UNDEF(&_14$$40);
	ZVAL_UNDEF(&_15$$40);
	ZVAL_UNDEF(&_16$$40);
	ZVAL_UNDEF(&_21$$41);
	ZVAL_UNDEF(&_22$$41);
	ZVAL_UNDEF(&_23$$41);
	ZVAL_UNDEF(&valueSql$$38);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
		if (ZEPHIR_IS_LONG(&columnType, 2)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHARACTER VARYING"));
			}
			ZEPHIR_CALL_METHOD(&_4$$33, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_4$$33);
			break;
		}
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&columnSql))) {
			ZEPHIR_INIT_VAR(&_5$$36);
			object_init_ex(&_5$$36, phalcon_db_exception_ce);
			ZEPHIR_CALL_METHOD(&_6$$36, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_7$$36);
			ZEPHIR_CONCAT_SV(&_7$$36, "Unrecognized PostgreSQL data type at column ", &_6$$36);
			ZEPHIR_CALL_METHOD(NULL, &_5$$36, "__construct", NULL, 8, &_7$$36);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$36, "phalcon/Db/Dialect/Postgresql.zep", 511);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&typeValues, column, "gettypevalues", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&typeValues))) {
			if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(&valueSql$$38);
				zephir_is_iterable(&typeValues, 0, "phalcon/Db/Dialect/Postgresql.zep", 526);
				if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&typeValues), _8$$38)
					{
						ZEPHIR_INIT_NVAR(&value$$38);
						ZVAL_COPY(&value$$38, _8$$38);
						ZEPHIR_INIT_NVAR(&_10$$39);
						ZVAL_STRING(&_10$$39, "\'");
						ZEPHIR_CALL_FUNCTION(&_11$$39, "addcslashes", &_12, 206, &value$$38, &_10$$39);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_13$$39);
						ZEPHIR_CONCAT_SVS(&_13$$39, "'", &_11$$39, "', ");
						zephir_concat_self(&valueSql$$38, &_13$$39);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &typeValues, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_9$$38, &typeValues, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_9$$38)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&value$$38, &typeValues, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_14$$40);
							ZVAL_STRING(&_14$$40, "\'");
							ZEPHIR_CALL_FUNCTION(&_15$$40, "addcslashes", &_12, 206, &value$$38, &_14$$40);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_16$$40);
							ZEPHIR_CONCAT_SVS(&_16$$40, "'", &_15$$40, "', ");
							zephir_concat_self(&valueSql$$38, &_16$$40);
						ZEPHIR_CALL_METHOD(NULL, &typeValues, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&value$$38);
				ZVAL_LONG(&_17$$38, 0);
				ZVAL_LONG(&_18$$38, -2);
				ZEPHIR_INIT_VAR(&_19$$38);
				zephir_substr(&_19$$38, &valueSql$$38, 0 , -2 , 0);
				ZEPHIR_INIT_VAR(&_20$$38);
				ZEPHIR_CONCAT_SVS(&_20$$38, "(", &_19$$38, ")");
				zephir_concat_self(&columnSql, &_20$$38);
			} else {
				ZEPHIR_INIT_VAR(&_21$$41);
				ZVAL_STRING(&_21$$41, "\'");
				ZEPHIR_CALL_FUNCTION(&_22$$41, "addcslashes", &_12, 206, &typeValues, &_21$$41);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_23$$41);
				ZEPHIR_CONCAT_SVS(&_23$$41, "('", &_22$$41, "')");
				zephir_concat_self(&columnSql, &_23$$41);
			}
		}
	} while(0);

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
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schemaName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
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
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schemaName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
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
	zend_bool _26$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, defaultValue, columnDefinition, _0, _1, _2, _3, _7, _8, _11, _12, _18, _23, _24, _4$$4, _5$$4, _6$$4, _9$$5, _10$$5, _13$$6, _14$$7, _15$$7, _16$$8, _17$$8, _19$$9, _20$$9, _21$$9, _22$$9, _25$$10, _27$$10, _30$$10, _28$$11, _29$$11, _31$$12, _32$$13, _33$$13, _34$$14, _35$$14;
	zval tableName, schemaName, sql, sqlAlterTable;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&sqlAlterTable);
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
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
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
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_30$$10);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_35$$14);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(currentColumn, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &tableName_param, &schemaName_param, &column, &currentColumn);
	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
	}
	if (!currentColumn) {
		currentColumn = &currentColumn_sub;
		ZEPHIR_CPY_WRT(currentColumn, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(currentColumn);
	}


	ZEPHIR_INIT_VAR(&sql);
	ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
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
		ZEPHIR_CALL_METHOD(&_19$$9, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_20$$9, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_21$$9, column, "getcomment", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_22$$9);
		ZEPHIR_CONCAT_SVSVSVS(&_22$$9, "COMMENT ON COLUMN ", &_19$$9, ".\"", &_20$$9, "\" IS '", &_21$$9, "';");
		zephir_concat_self(&sql, &_22$$9);
	}
	ZEPHIR_CALL_METHOD(&_23, column, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_24, currentColumn, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_23, &_24)) {
		ZEPHIR_CALL_METHOD(&_25$$10, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		_26$$10 = ZEPHIR_IS_EMPTY(&_25$$10);
		if (_26$$10) {
			ZEPHIR_CALL_METHOD(&_27$$10, currentColumn, "getdefault", NULL, 0);
			zephir_check_call_status();
			_26$$10 = !(ZEPHIR_IS_EMPTY(&_27$$10));
		}
		if (_26$$10) {
			ZEPHIR_CALL_METHOD(&_28$$11, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_29$$11);
			ZEPHIR_CONCAT_VSVS(&_29$$11, &sqlAlterTable, " ALTER COLUMN \"", &_28$$11, "\" DROP DEFAULT;");
			zephir_concat_self(&sql, &_29$$11);
		}
		ZEPHIR_CALL_METHOD(&_30$$10, column, "hasdefault", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_30$$10)) {
			ZEPHIR_CALL_METHOD(&defaultValue, this_ptr, "castdefault", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_31$$12);
			zephir_fast_strtoupper(&_31$$12, &columnDefinition);
			if (zephir_memnstr_str(&_31$$12, SL("BOOLEAN"), "phalcon/Db/Dialect/Postgresql.zep", 616)) {
				ZEPHIR_CALL_METHOD(&_32$$13, column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_33$$13);
				ZEPHIR_CONCAT_SVSV(&_33$$13, " ALTER COLUMN \"", &_32$$13, "\" SET DEFAULT ", &defaultValue);
				zephir_concat_self(&sql, &_33$$13);
			} else {
				ZEPHIR_CALL_METHOD(&_34$$14, column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_35$$14);
				ZEPHIR_CONCAT_VSVSV(&_35$$14, &sqlAlterTable, " ALTER COLUMN \"", &_34$$14, "\" SET DEFAULT ", &defaultValue);
				zephir_concat_self(&sql, &_35$$14);
			}
		}
	}
	RETURN_CTOR(&sql);
}

/**
 * Returns a SQL modified a shared lock statement. For now this method
 * returns the original query
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, sharedLock)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sqlQuery_param = NULL;
	zval sqlQuery;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(sqlQuery)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sqlQuery_param);
	if (UNEXPECTED(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(&sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(&sqlQuery);
	}


	RETURN_CTOR(&sqlQuery);
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
	zval *tableName_param = NULL, *schemaName_param = NULL;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(tableName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tableName_param, &schemaName_param);
	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	if (ZEPHIR_IS_NULL(&schemaName)) {
		ZEPHIR_INIT_NVAR(&schemaName);
		ZVAL_STRING(&schemaName, "public");
	}
	ZEPHIR_CONCAT_SVSVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM information_schema.tables WHERE table_schema = '", &schemaName, "' AND table_name='", &tableName, "'");
	RETURN_MM();
}

/**
 * Generates the SQL to describe the table creation options
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, tableOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);
	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	RETURN_MM_STRING("");
}

/**
 * Generates SQL to truncate a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Postgresql, truncateTable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, table;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&table);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tableName_param, &schemaName_param);
	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
	}


	if (!(ZEPHIR_IS_EMPTY(&schemaName))) {
		ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName);
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
	zval *viewName_param = NULL, *schemaName_param = NULL;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(viewName)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schemaName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &viewName_param, &schemaName_param);
	if (UNEXPECTED(Z_TYPE_P(viewName_param) != IS_STRING && Z_TYPE_P(viewName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'viewName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(viewName_param) == IS_STRING)) {
		zephir_get_strval(&viewName, viewName_param);
	} else {
		ZEPHIR_INIT_VAR(&viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	if (ZEPHIR_IS_NULL(&schemaName)) {
		ZEPHIR_INIT_NVAR(&schemaName);
		ZVAL_STRING(&schemaName, "public");
	}
	ZEPHIR_CONCAT_SVSVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM pg_views WHERE viewname='", &viewName, "' AND schemaname='", &schemaName, "'");
	RETURN_MM();
}

PHP_METHOD(Phalcon_Db_Dialect_Postgresql, castDefault)
{
	zend_bool _2, _3, _4, _5;
	zval preparedValue, _6$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, defaultValue, columnDefinition, columnType, _0, _1, _7$$6, _8$$6, _9$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&preparedValue);
	ZVAL_UNDEF(&_6$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	if (zephir_memnstr_str(&_0, SL("BOOLEAN"), "phalcon/Db/Dialect/Postgresql.zep", 699)) {
		RETURN_CCTOR(&defaultValue);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtoupper(&_1, &defaultValue);
	if (zephir_memnstr_str(&_1, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Postgresql.zep", 703)) {
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
	if (_5) {
		zephir_cast_to_string(&_6$$5, &defaultValue);
		ZEPHIR_CPY_WRT(&preparedValue, &_6$$5);
	} else {
		ZEPHIR_INIT_VAR(&_7$$6);
		ZVAL_STRING(&_7$$6, "\'");
		ZEPHIR_CALL_FUNCTION(&_8$$6, "addcslashes", NULL, 206, &defaultValue, &_7$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$6);
		ZEPHIR_CONCAT_SVS(&_9$$6, "'", &_8$$6, "'");
		zephir_get_strval(&preparedValue, &_9$$6);
	}
	RETURN_CTOR(&preparedValue);
}

PHP_METHOD(Phalcon_Db_Dialect_Postgresql, getTableOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *definition_param = NULL;
	zval definition;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(definition)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition_param);
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);


	RETURN_MM_STRING("");
}

