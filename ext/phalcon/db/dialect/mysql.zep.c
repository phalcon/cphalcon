
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
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
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
 * Generates database specific SQL for the MySQL RDBMS
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Mysql)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Mysql, phalcon, db_dialect_mysql, phalcon_db_dialect_ce, phalcon_db_dialect_mysql_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_dialect_mysql_ce, SL("escapeChar"), "`", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Generates SQL to add a column to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addColumn)
{
	zend_bool _6$$5, _7$$5, _8$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, afterPosition, defaultValue, upperDefaultValue, _0, _1, _2, _3, _4, _5, _14, _15, _9$$5, _10$$6, _11$$7, _12$$7, _13$$7, _16$$11;
	zval tableName, schemaName, sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&afterPosition);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&upperDefaultValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_16$$11);
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVSVSV(&_3, "ALTER TABLE ", &_0, " ADD `", &_1, "` ", &_2);
	zephir_get_strval(&sql, &_3);
	ZEPHIR_CALL_METHOD(&_4, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		zephir_concat_self_str(&sql, " NOT NULL", sizeof(" NOT NULL") - 1);
	} else {
		zephir_concat_self_str(&sql, " NULL", sizeof(" NULL") - 1);
	}
	ZEPHIR_CALL_METHOD(&_5, column, "hasdefault", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&upperDefaultValue);
		zephir_fast_strtoupper(&upperDefaultValue, &defaultValue);
		_6$$5 = zephir_memnstr_str(&upperDefaultValue, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Mysql.zep", 54);
		if (!(_6$$5)) {
			_6$$5 = zephir_memnstr_str(&upperDefaultValue, SL("NULL"), "phalcon/Db/Dialect/Mysql.zep", 54);
		}
		_7$$5 = _6$$5;
		if (!(_7$$5)) {
			_7$$5 = Z_TYPE_P(&defaultValue) == IS_LONG;
		}
		_8$$5 = _7$$5;
		if (!(_8$$5)) {
			ZEPHIR_CALL_FUNCTION(&_9$$5, "is_float", NULL, 227, &defaultValue);
			zephir_check_call_status();
			_8$$5 = zephir_is_true(&_9$$5);
		}
		if (_8$$5) {
			ZEPHIR_INIT_VAR(&_10$$6);
			ZEPHIR_CONCAT_SV(&_10$$6, " DEFAULT ", &defaultValue);
			zephir_concat_self(&sql, &_10$$6);
		} else {
			ZEPHIR_INIT_VAR(&_11$$7);
			ZVAL_STRING(&_11$$7, "\"");
			ZEPHIR_CALL_FUNCTION(&_12$$7, "addcslashes", NULL, 228, &defaultValue, &_11$$7);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_13$$7);
			ZEPHIR_CONCAT_SVS(&_13$$7, " DEFAULT \"", &_12$$7, "\"");
			zephir_concat_self(&sql, &_13$$7);
		}
	}
	ZEPHIR_CALL_METHOD(&_14, column, "isautoincrement", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_14)) {
		zephir_concat_self_str(&sql, " AUTO_INCREMENT", sizeof(" AUTO_INCREMENT") - 1);
	}
	ZEPHIR_CALL_METHOD(&_15, column, "isfirst", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_15)) {
		zephir_concat_self_str(&sql, " FIRST", sizeof(" FIRST") - 1);
	} else {
		ZEPHIR_CALL_METHOD(&afterPosition, column, "getafterposition", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&afterPosition)) {
			ZEPHIR_INIT_VAR(&_16$$11);
			ZEPHIR_CONCAT_SVS(&_16$$11, " AFTER `", &afterPosition, "`");
			zephir_concat_self(&sql, &_16$$11);
		}
	}
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addForeignKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, reference_sub, onDelete, onUpdate, _0, _1, _2, _5, _6, _7, _8, _9, _10, _11, _12, _3$$3, _4$$3, _13$$4, _14$$5;
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
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$5);
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
		ZEPHIR_CONCAT_SVS(&_4$$3, " CONSTRAINT `", &_3$$3, "`");
		zephir_concat_self(&sql, &_4$$3);
	}
	ZEPHIR_CALL_METHOD(&_6, reference, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumnlist", NULL, 66, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, reference, "getreferencedtable", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, reference, "getreferencedschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "preparetable", NULL, 0, &_8, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_11, reference, "getreferencedcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "getcolumnlist", NULL, 66, &_11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_SVSVSVS(&_12, " FOREIGN KEY (", &_5, ") REFERENCES ", &_7, "(", &_10, ")");
	zephir_concat_self(&sql, &_12);
	ZEPHIR_CALL_METHOD(&onDelete, reference, "getondelete", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
		ZEPHIR_INIT_VAR(&_13$$4);
		ZEPHIR_CONCAT_SV(&_13$$4, " ON DELETE ", &onDelete);
		zephir_concat_self(&sql, &_13$$4);
	}
	ZEPHIR_CALL_METHOD(&onUpdate, reference, "getonupdate", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
		ZEPHIR_INIT_VAR(&_14$$5);
		ZEPHIR_CONCAT_SV(&_14$$5, " ON UPDATE ", &onUpdate);
		zephir_concat_self(&sql, &_14$$5);
	}
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addIndex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, index_sub, indexType, _0, _1, _3, _4, _5, _6, _2$$3;
	zval tableName, schemaName, sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
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
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "ALTER TABLE ", &_0);
	zephir_get_strval(&sql, &_1);
	ZEPHIR_CALL_METHOD(&indexType, index, "gettype", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&indexType))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, " ADD ", &indexType, " INDEX ");
		zephir_concat_self(&sql, &_2$$3);
	} else {
		zephir_concat_self_str(&sql, " ADD INDEX ", sizeof(" ADD INDEX ") - 1);
	}
	ZEPHIR_CALL_METHOD(&_3, index, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getcolumnlist", NULL, 66, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVSVS(&_6, "`", &_3, "` (", &_4, ")");
	zephir_concat_self(&sql, &_6);
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to add the primary key to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addPrimaryKey)
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
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcolumnlist", NULL, 66, &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " ADD PRIMARY KEY (", &_1, ")");
	RETURN_MM();
}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, createTable)
{
	zend_bool _9$$10, _10$$10, _11$$10, _28$$19, _29$$19, _30$$19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_13 = NULL, *_17 = NULL, *_45 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition, createLines;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, temporary, options, table, columns, column, indexes, index, reference, references, indexName, columnLine, indexType, onDelete, onUpdate, defaultValue, upperDefaultValue, *_2, _3, _86, _87, _0$$5, _1$$6, _4$$7, _5$$7, _7$$7, _8$$7, _19$$7, _20$$7, _21$$7, _12$$10, _14$$11, _15$$12, _16$$12, _18$$12, _22$$15, _23$$15, _24$$16, _25$$16, _26$$16, _27$$16, _36$$16, _37$$16, _38$$16, _31$$19, _32$$20, _33$$21, _34$$21, _35$$21, _39$$24, _40$$24, *_41$$25, _42$$25, _43$$27, _44$$27, _46$$27, _47$$29, _48$$29, _49$$29, _50$$30, _51$$30, _52$$30, _53$$32, _54$$32, _55$$32, _56$$34, _57$$34, _58$$34, _59$$35, _60$$35, _61$$35, *_62$$36, _63$$36, _64$$37, _65$$37, _66$$37, _67$$37, _68$$37, _69$$37, _70$$37, _71$$37, _72$$37, _73$$38, _74$$39, _75$$40, _76$$40, _77$$40, _78$$40, _79$$40, _80$$40, _81$$40, _82$$40, _83$$40, _84$$41, _85$$42, _88$$43, _89$$43;
	zval tableName, schemaName, indexSql, referenceSql, sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&indexSql);
	ZVAL_UNDEF(&referenceSql);
	ZVAL_UNDEF(&sql);
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
	ZVAL_UNDEF(&columnLine);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&onDelete);
	ZVAL_UNDEF(&onUpdate);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&upperDefaultValue);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_86);
	ZVAL_UNDEF(&_87);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_36$$16);
	ZVAL_UNDEF(&_37$$16);
	ZVAL_UNDEF(&_38$$16);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_33$$21);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_35$$21);
	ZVAL_UNDEF(&_39$$24);
	ZVAL_UNDEF(&_40$$24);
	ZVAL_UNDEF(&_42$$25);
	ZVAL_UNDEF(&_43$$27);
	ZVAL_UNDEF(&_44$$27);
	ZVAL_UNDEF(&_46$$27);
	ZVAL_UNDEF(&_47$$29);
	ZVAL_UNDEF(&_48$$29);
	ZVAL_UNDEF(&_49$$29);
	ZVAL_UNDEF(&_50$$30);
	ZVAL_UNDEF(&_51$$30);
	ZVAL_UNDEF(&_52$$30);
	ZVAL_UNDEF(&_53$$32);
	ZVAL_UNDEF(&_54$$32);
	ZVAL_UNDEF(&_55$$32);
	ZVAL_UNDEF(&_56$$34);
	ZVAL_UNDEF(&_57$$34);
	ZVAL_UNDEF(&_58$$34);
	ZVAL_UNDEF(&_59$$35);
	ZVAL_UNDEF(&_60$$35);
	ZVAL_UNDEF(&_61$$35);
	ZVAL_UNDEF(&_63$$36);
	ZVAL_UNDEF(&_64$$37);
	ZVAL_UNDEF(&_65$$37);
	ZVAL_UNDEF(&_66$$37);
	ZVAL_UNDEF(&_67$$37);
	ZVAL_UNDEF(&_68$$37);
	ZVAL_UNDEF(&_69$$37);
	ZVAL_UNDEF(&_70$$37);
	ZVAL_UNDEF(&_71$$37);
	ZVAL_UNDEF(&_72$$37);
	ZVAL_UNDEF(&_73$$38);
	ZVAL_UNDEF(&_74$$39);
	ZVAL_UNDEF(&_75$$40);
	ZVAL_UNDEF(&_76$$40);
	ZVAL_UNDEF(&_77$$40);
	ZVAL_UNDEF(&_78$$40);
	ZVAL_UNDEF(&_79$$40);
	ZVAL_UNDEF(&_80$$40);
	ZVAL_UNDEF(&_81$$40);
	ZVAL_UNDEF(&_82$$40);
	ZVAL_UNDEF(&_83$$40);
	ZVAL_UNDEF(&_84$$41);
	ZVAL_UNDEF(&_85$$42);
	ZVAL_UNDEF(&_88$$43);
	ZVAL_UNDEF(&_89$$43);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&createLines);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array", "phalcon/Db/Dialect/Mysql.zep", 151);
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
	ZEPHIR_INIT_VAR(&createLines);
	array_init(&createLines);
	zephir_is_iterable(&columns, 0, "phalcon/Db/Dialect/Mysql.zep", 228);
	if (Z_TYPE_P(&columns) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _2)
		{
			ZEPHIR_INIT_NVAR(&column);
			ZVAL_COPY(&column, _2);
			ZEPHIR_CALL_METHOD(&_4$$7, &column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5$$7, this_ptr, "getcolumndefinition", &_6, 0, &column);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&columnLine);
			ZEPHIR_CONCAT_SVSV(&columnLine, "`", &_4$$7, "` ", &_5$$7);
			ZEPHIR_CALL_METHOD(&_7$$7, &column, "isnotnull", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_7$$7)) {
				zephir_concat_self_str(&columnLine, SL(" NOT NULL"));
			} else {
				zephir_concat_self_str(&columnLine, SL(" NULL"));
			}
			ZEPHIR_CALL_METHOD(&_8$$7, &column, "hasdefault", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_8$$7)) {
				ZEPHIR_CALL_METHOD(&defaultValue, &column, "getdefault", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&upperDefaultValue);
				zephir_fast_strtoupper(&upperDefaultValue, &defaultValue);
				_9$$10 = zephir_memnstr_str(&upperDefaultValue, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Mysql.zep", 194);
				if (!(_9$$10)) {
					_9$$10 = zephir_memnstr_str(&upperDefaultValue, SL("NULL"), "phalcon/Db/Dialect/Mysql.zep", 194);
				}
				_10$$10 = _9$$10;
				if (!(_10$$10)) {
					_10$$10 = Z_TYPE_P(&defaultValue) == IS_LONG;
				}
				_11$$10 = _10$$10;
				if (!(_11$$10)) {
					ZEPHIR_CALL_FUNCTION(&_12$$10, "is_float", &_13, 227, &defaultValue);
					zephir_check_call_status();
					_11$$10 = zephir_is_true(&_12$$10);
				}
				if (_11$$10) {
					ZEPHIR_INIT_NVAR(&_14$$11);
					ZEPHIR_CONCAT_SV(&_14$$11, " DEFAULT ", &defaultValue);
					zephir_concat_self(&columnLine, &_14$$11);
				} else {
					ZEPHIR_INIT_NVAR(&_15$$12);
					ZVAL_STRING(&_15$$12, "\"");
					ZEPHIR_CALL_FUNCTION(&_16$$12, "addcslashes", &_17, 228, &defaultValue, &_15$$12);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_18$$12);
					ZEPHIR_CONCAT_SVS(&_18$$12, " DEFAULT \"", &_16$$12, "\"");
					zephir_concat_self(&columnLine, &_18$$12);
				}
			}
			ZEPHIR_CALL_METHOD(&_19$$7, &column, "isautoincrement", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_19$$7)) {
				zephir_concat_self_str(&columnLine, SL(" AUTO_INCREMENT"));
			}
			ZEPHIR_CALL_METHOD(&_20$$7, &column, "isprimary", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_20$$7)) {
				zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY"));
			}
			ZEPHIR_CALL_METHOD(&_21$$7, &column, "getcomment", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_21$$7)) {
				ZEPHIR_CALL_METHOD(&_22$$15, &column, "getcomment", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_23$$15);
				ZEPHIR_CONCAT_SVS(&_23$$15, " COMMENT '", &_22$$15, "'");
				zephir_concat_self(&columnLine, &_23$$15);
			}
			zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 222);
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
				ZEPHIR_CALL_METHOD(&_24$$16, &column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_25$$16, this_ptr, "getcolumndefinition", &_6, 0, &column);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&columnLine);
				ZEPHIR_CONCAT_SVSV(&columnLine, "`", &_24$$16, "` ", &_25$$16);
				ZEPHIR_CALL_METHOD(&_26$$16, &column, "isnotnull", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_26$$16)) {
					zephir_concat_self_str(&columnLine, SL(" NOT NULL"));
				} else {
					zephir_concat_self_str(&columnLine, SL(" NULL"));
				}
				ZEPHIR_CALL_METHOD(&_27$$16, &column, "hasdefault", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_27$$16)) {
					ZEPHIR_CALL_METHOD(&defaultValue, &column, "getdefault", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&upperDefaultValue);
					zephir_fast_strtoupper(&upperDefaultValue, &defaultValue);
					_28$$19 = zephir_memnstr_str(&upperDefaultValue, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Mysql.zep", 194);
					if (!(_28$$19)) {
						_28$$19 = zephir_memnstr_str(&upperDefaultValue, SL("NULL"), "phalcon/Db/Dialect/Mysql.zep", 194);
					}
					_29$$19 = _28$$19;
					if (!(_29$$19)) {
						_29$$19 = Z_TYPE_P(&defaultValue) == IS_LONG;
					}
					_30$$19 = _29$$19;
					if (!(_30$$19)) {
						ZEPHIR_CALL_FUNCTION(&_31$$19, "is_float", &_13, 227, &defaultValue);
						zephir_check_call_status();
						_30$$19 = zephir_is_true(&_31$$19);
					}
					if (_30$$19) {
						ZEPHIR_INIT_NVAR(&_32$$20);
						ZEPHIR_CONCAT_SV(&_32$$20, " DEFAULT ", &defaultValue);
						zephir_concat_self(&columnLine, &_32$$20);
					} else {
						ZEPHIR_INIT_NVAR(&_33$$21);
						ZVAL_STRING(&_33$$21, "\"");
						ZEPHIR_CALL_FUNCTION(&_34$$21, "addcslashes", &_17, 228, &defaultValue, &_33$$21);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_35$$21);
						ZEPHIR_CONCAT_SVS(&_35$$21, " DEFAULT \"", &_34$$21, "\"");
						zephir_concat_self(&columnLine, &_35$$21);
					}
				}
				ZEPHIR_CALL_METHOD(&_36$$16, &column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_36$$16)) {
					zephir_concat_self_str(&columnLine, SL(" AUTO_INCREMENT"));
				}
				ZEPHIR_CALL_METHOD(&_37$$16, &column, "isprimary", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_37$$16)) {
					zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY"));
				}
				ZEPHIR_CALL_METHOD(&_38$$16, &column, "getcomment", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_38$$16)) {
					ZEPHIR_CALL_METHOD(&_39$$24, &column, "getcomment", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_40$$24);
					ZEPHIR_CONCAT_SVS(&_40$$24, " COMMENT '", &_39$$24, "'");
					zephir_concat_self(&columnLine, &_40$$24);
				}
				zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 222);
			ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	ZEPHIR_OBS_VAR(&indexes);
	if (zephir_array_isset_string_fetch(&indexes, &definition, SL("indexes"), 0)) {
		zephir_is_iterable(&indexes, 0, "phalcon/Db/Dialect/Mysql.zep", 248);
		if (Z_TYPE_P(&indexes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&indexes), _41$$25)
			{
				ZEPHIR_INIT_NVAR(&index);
				ZVAL_COPY(&index, _41$$25);
				ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_STRING(&indexName, "PRIMARY")) {
					ZEPHIR_CALL_METHOD(&_44$$27, &index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_43$$27, this_ptr, "getcolumnlist", &_45, 66, &_44$$27);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_46$$27);
					ZEPHIR_CONCAT_SVS(&_46$$27, "PRIMARY KEY (", &_43$$27, ")");
					zephir_get_strval(&indexSql, &_46$$27);
				} else {
					if (!(ZEPHIR_IS_EMPTY(&indexType))) {
						ZEPHIR_CALL_METHOD(&_48$$29, &index, "getcolumns", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_47$$29, this_ptr, "getcolumnlist", &_45, 66, &_48$$29);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_49$$29);
						ZEPHIR_CONCAT_VSVSVS(&_49$$29, &indexType, " KEY `", &indexName, "` (", &_47$$29, ")");
						zephir_get_strval(&indexSql, &_49$$29);
					} else {
						ZEPHIR_CALL_METHOD(&_51$$30, &index, "getcolumns", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_50$$30, this_ptr, "getcolumnlist", &_45, 66, &_51$$30);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_52$$30);
						ZEPHIR_CONCAT_SVSVS(&_52$$30, "KEY `", &indexName, "` (", &_50$$30, ")");
						zephir_get_strval(&indexSql, &_52$$30);
					}
				}
				zephir_array_append(&createLines, &indexSql, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 246);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &indexes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_42$$25, &indexes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_42$$25)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&index, &indexes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_STRING(&indexName, "PRIMARY")) {
						ZEPHIR_CALL_METHOD(&_54$$32, &index, "getcolumns", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_53$$32, this_ptr, "getcolumnlist", &_45, 66, &_54$$32);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_55$$32);
						ZEPHIR_CONCAT_SVS(&_55$$32, "PRIMARY KEY (", &_53$$32, ")");
						zephir_get_strval(&indexSql, &_55$$32);
					} else {
						if (!(ZEPHIR_IS_EMPTY(&indexType))) {
							ZEPHIR_CALL_METHOD(&_57$$34, &index, "getcolumns", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_56$$34, this_ptr, "getcolumnlist", &_45, 66, &_57$$34);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_58$$34);
							ZEPHIR_CONCAT_VSVSVS(&_58$$34, &indexType, " KEY `", &indexName, "` (", &_56$$34, ")");
							zephir_get_strval(&indexSql, &_58$$34);
						} else {
							ZEPHIR_CALL_METHOD(&_60$$35, &index, "getcolumns", NULL, 0);
							zephir_check_call_status();
							ZEPHIR_CALL_METHOD(&_59$$35, this_ptr, "getcolumnlist", &_45, 66, &_60$$35);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_61$$35);
							ZEPHIR_CONCAT_SVSVS(&_61$$35, "KEY `", &indexName, "` (", &_59$$35, ")");
							zephir_get_strval(&indexSql, &_61$$35);
						}
					}
					zephir_array_append(&createLines, &indexSql, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 246);
				ZEPHIR_CALL_METHOD(NULL, &indexes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&index);
	}
	ZEPHIR_OBS_VAR(&references);
	if (zephir_array_isset_string_fetch(&references, &definition, SL("references"), 0)) {
		zephir_is_iterable(&references, 0, "phalcon/Db/Dialect/Mysql.zep", 270);
		if (Z_TYPE_P(&references) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&references), _62$$36)
			{
				ZEPHIR_INIT_NVAR(&reference);
				ZVAL_COPY(&reference, _62$$36);
				ZEPHIR_CALL_METHOD(&_64$$37, &reference, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_66$$37, &reference, "getcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_65$$37, this_ptr, "getcolumnlist", &_45, 66, &_66$$37);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_68$$37, &reference, "getreferencedtable", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_69$$37, &reference, "getreferencedschema", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_67$$37, this_ptr, "preparetable", NULL, 0, &_68$$37, &_69$$37);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_71$$37, &reference, "getreferencedcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_70$$37, this_ptr, "getcolumnlist", &_45, 66, &_71$$37);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_72$$37);
				ZEPHIR_CONCAT_SVSVSSVSVS(&_72$$37, "CONSTRAINT `", &_64$$37, "` FOREIGN KEY (", &_65$$37, ")", " REFERENCES ", &_67$$37, " (", &_70$$37, ")");
				zephir_get_strval(&referenceSql, &_72$$37);
				ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
					ZEPHIR_INIT_NVAR(&_73$$38);
					ZEPHIR_CONCAT_SV(&_73$$38, " ON DELETE ", &onDelete);
					zephir_concat_self(&referenceSql, &_73$$38);
				}
				ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
					ZEPHIR_INIT_NVAR(&_74$$39);
					ZEPHIR_CONCAT_SV(&_74$$39, " ON UPDATE ", &onUpdate);
					zephir_concat_self(&referenceSql, &_74$$39);
				}
				zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 268);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &references, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_63$$36, &references, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_63$$36)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&reference, &references, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_75$$40, &reference, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_77$$40, &reference, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_76$$40, this_ptr, "getcolumnlist", &_45, 66, &_77$$40);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_79$$40, &reference, "getreferencedtable", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_80$$40, &reference, "getreferencedschema", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_78$$40, this_ptr, "preparetable", NULL, 0, &_79$$40, &_80$$40);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_82$$40, &reference, "getreferencedcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_81$$40, this_ptr, "getcolumnlist", &_45, 66, &_82$$40);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_83$$40);
					ZEPHIR_CONCAT_SVSVSSVSVS(&_83$$40, "CONSTRAINT `", &_75$$40, "` FOREIGN KEY (", &_76$$40, ")", " REFERENCES ", &_78$$40, " (", &_81$$40, ")");
					zephir_get_strval(&referenceSql, &_83$$40);
					ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
						ZEPHIR_INIT_NVAR(&_84$$41);
						ZEPHIR_CONCAT_SV(&_84$$41, " ON DELETE ", &onDelete);
						zephir_concat_self(&referenceSql, &_84$$41);
					}
					ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
						ZEPHIR_INIT_NVAR(&_85$$42);
						ZEPHIR_CONCAT_SV(&_85$$42, " ON UPDATE ", &onUpdate);
						zephir_concat_self(&referenceSql, &_85$$42);
					}
					zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 268);
				ZEPHIR_CALL_METHOD(NULL, &references, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&reference);
	}
	ZEPHIR_INIT_VAR(&_86);
	zephir_fast_join_str(&_86, SL(",\n\t"), &createLines);
	ZEPHIR_INIT_VAR(&_87);
	ZEPHIR_CONCAT_VS(&_87, &_86, "\n)");
	zephir_concat_self(&sql, &_87);
	if (zephir_array_isset_string(&definition, SL("options"))) {
		ZEPHIR_CALL_METHOD(&_88$$43, this_ptr, "gettableoptions", NULL, 0, &definition);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_89$$43);
		ZEPHIR_CONCAT_SV(&_89$$43, " ", &_88$$43);
		zephir_concat_self(&sql, &_89$$43);
	}
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to create a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, createView)
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array", "phalcon/Db/Dialect/Mysql.zep", 291);
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeColumns)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, _0;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_0);
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, "SHOW FULL COLUMNS FROM ", &_0);
	RETURN_MM();
}

/**
 * Generates SQL to query indexes on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeIndexes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, _0;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_0);
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, "SHOW INDEXES FROM ", &_0);
	RETURN_MM();
}

/**
 * Generates SQL to query foreign keys on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeReferences)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema, sql, _0$$3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
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


	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "SELECT DISTINCT KCU.TABLE_NAME, KCU.COLUMN_NAME, KCU.CONSTRAINT_NAME, KCU.REFERENCED_TABLE_SCHEMA, KCU.REFERENCED_TABLE_NAME, KCU.REFERENCED_COLUMN_NAME, RC.UPDATE_RULE, RC.DELETE_RULE FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE AS KCU LEFT JOIN INFORMATION_SCHEMA.REFERENTIAL_CONSTRAINTS AS RC ON RC.CONSTRAINT_NAME = KCU.CONSTRAINT_NAME AND RC.CONSTRAINT_SCHEMA = KCU.CONSTRAINT_SCHEMA WHERE KCU.REFERENCED_TABLE_NAME IS NOT NULL AND ");
	if (!(ZEPHIR_IS_EMPTY(&schema))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SVSVS(&_0$$3, "KCU.CONSTRAINT_SCHEMA = '", &schema, "' AND KCU.TABLE_NAME = '", &table, "'");
		zephir_concat_self(&sql, &_0$$3);
	} else {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_CONCAT_SVS(&_1$$4, "KCU.CONSTRAINT_SCHEMA = DATABASE() AND KCU.TABLE_NAME = '", &table, "'");
		zephir_concat_self(&sql, &_1$$4);
	}
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to delete a column from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropColumn)
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
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP COLUMN `", &columnName, "`");
	RETURN_MM();
}

/**
 * Generates SQL to delete a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropForeignKey)
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
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP FOREIGN KEY `", &referenceName, "`");
	RETURN_MM();
}

/**
 * Generates SQL to delete an index from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropIndex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName_param = NULL, _0;
	zval tableName, schemaName, indexName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&indexName);
	ZVAL_UNDEF(&_0);
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP INDEX `", &indexName, "`");
	RETURN_MM();
}

/**
 * Generates SQL to delete primary key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropPrimaryKey)
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
	ZEPHIR_CONCAT_SVS(return_value, "ALTER TABLE ", &_0, " DROP PRIMARY KEY");
	RETURN_MM();
}

/**
 * Generates SQL to drop a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropTable)
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropView)
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
 * Gets the column name in MySQL
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getColumnDefinition)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_41 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, columnType, columnSql, typeValues, _0$$3, _1$$3, _2$$3, _3$$5, _4$$11, _5$$15, _6$$17, _7$$18, _8$$18, _9$$18, _10$$20, _11$$20, _12$$20, _13$$22, _14$$24, _15$$24, _16$$24, _17$$26, _18$$26, _19$$26, _20$$36, _21$$36, _22$$36, _23$$40, _24$$40, _25$$40, _26$$44, _27$$46, _28$$47, _29$$49, _30$$52, _31$$52, _32$$52, _33$$56, _34$$59, _35$$59, _36$$59, value$$61, valueSql$$61, *_37$$61, _38$$61, _46$$61, _47$$61, _48$$61, _49$$61, _39$$62, _40$$62, _42$$62, _43$$63, _44$$63, _45$$63, _50$$64, _51$$64, _52$$64;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&columnSql);
	ZVAL_UNDEF(&typeValues);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&_5$$15);
	ZVAL_UNDEF(&_6$$17);
	ZVAL_UNDEF(&_7$$18);
	ZVAL_UNDEF(&_8$$18);
	ZVAL_UNDEF(&_9$$18);
	ZVAL_UNDEF(&_10$$20);
	ZVAL_UNDEF(&_11$$20);
	ZVAL_UNDEF(&_12$$20);
	ZVAL_UNDEF(&_13$$22);
	ZVAL_UNDEF(&_14$$24);
	ZVAL_UNDEF(&_15$$24);
	ZVAL_UNDEF(&_16$$24);
	ZVAL_UNDEF(&_17$$26);
	ZVAL_UNDEF(&_18$$26);
	ZVAL_UNDEF(&_19$$26);
	ZVAL_UNDEF(&_20$$36);
	ZVAL_UNDEF(&_21$$36);
	ZVAL_UNDEF(&_22$$36);
	ZVAL_UNDEF(&_23$$40);
	ZVAL_UNDEF(&_24$$40);
	ZVAL_UNDEF(&_25$$40);
	ZVAL_UNDEF(&_26$$44);
	ZVAL_UNDEF(&_27$$46);
	ZVAL_UNDEF(&_28$$47);
	ZVAL_UNDEF(&_29$$49);
	ZVAL_UNDEF(&_30$$52);
	ZVAL_UNDEF(&_31$$52);
	ZVAL_UNDEF(&_32$$52);
	ZVAL_UNDEF(&_33$$56);
	ZVAL_UNDEF(&_34$$59);
	ZVAL_UNDEF(&_35$$59);
	ZVAL_UNDEF(&_36$$59);
	ZVAL_UNDEF(&value$$61);
	ZVAL_UNDEF(&valueSql$$61);
	ZVAL_UNDEF(&_38$$61);
	ZVAL_UNDEF(&_46$$61);
	ZVAL_UNDEF(&_47$$61);
	ZVAL_UNDEF(&_48$$61);
	ZVAL_UNDEF(&_49$$61);
	ZVAL_UNDEF(&_39$$62);
	ZVAL_UNDEF(&_40$$62);
	ZVAL_UNDEF(&_42$$62);
	ZVAL_UNDEF(&_43$$63);
	ZVAL_UNDEF(&_44$$63);
	ZVAL_UNDEF(&_45$$63);
	ZVAL_UNDEF(&_50$$64);
	ZVAL_UNDEF(&_51$$64);
	ZVAL_UNDEF(&_52$$64);
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
				zephir_concat_self_str(&columnSql, SL("BIGINT"));
			}
			ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "checkcolumnunsigned", NULL, 229, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_2$$3);
			ZEPHIR_CONCAT_VV(&_2$$3, &_0$$3, &_1$$3);
			zephir_concat_self(&columnSql, &_2$$3);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 19)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("BIT"));
			}
			ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_3$$5);
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
				zephir_concat_self_str(&columnSql, SL("TINYINT(1)"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 5)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHAR"));
			}
			ZEPHIR_CALL_METHOD(&_4$$11, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_4$$11);
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
			ZEPHIR_CALL_METHOD(&_5$$15, column, "getsize", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_GT_LONG(&_5$$15, 0)) {
				ZEPHIR_CALL_METHOD(&_6$$17, this_ptr, "getcolumnsize", NULL, 0, column);
				zephir_check_call_status();
				zephir_concat_self(&columnSql, &_6$$17);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 3)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DECIMAL"));
			}
			ZEPHIR_CALL_METHOD(&_7$$18, this_ptr, "getcolumnsizeandscale", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8$$18, this_ptr, "checkcolumnunsigned", NULL, 229, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_9$$18);
			ZEPHIR_CONCAT_VV(&_9$$18, &_7$$18, &_8$$18);
			zephir_concat_self(&columnSql, &_9$$18);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 9)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DOUBLE"));
			}
			ZEPHIR_CALL_METHOD(&_10$$20, this_ptr, "checkcolumnsizeandscale", NULL, 230, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_11$$20, this_ptr, "checkcolumnunsigned", NULL, 229, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_12$$20);
			ZEPHIR_CONCAT_VV(&_12$$20, &_10$$20, &_11$$20);
			zephir_concat_self(&columnSql, &_12$$20);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 18)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("ENUM"));
			}
			ZEPHIR_CALL_METHOD(&_13$$22, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_13$$22);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 7)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("FLOAT"));
			}
			ZEPHIR_CALL_METHOD(&_14$$24, this_ptr, "checkcolumnsizeandscale", NULL, 230, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_15$$24, this_ptr, "checkcolumnunsigned", NULL, 229, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_16$$24);
			ZEPHIR_CONCAT_VV(&_16$$24, &_14$$24, &_15$$24);
			zephir_concat_self(&columnSql, &_16$$24);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 0)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("INT"));
			}
			ZEPHIR_CALL_METHOD(&_17$$26, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_18$$26, this_ptr, "checkcolumnunsigned", NULL, 229, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_19$$26);
			ZEPHIR_CONCAT_VV(&_19$$26, &_17$$26, &_18$$26);
			zephir_concat_self(&columnSql, &_19$$26);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 15)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("JSON"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 13)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("LONGBLOB"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 24)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("LONGTEXT"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 12)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("MEDIUMBLOB"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 21)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("MEDIUMINT"));
			}
			ZEPHIR_CALL_METHOD(&_20$$36, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21$$36, this_ptr, "checkcolumnunsigned", NULL, 229, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_22$$36);
			ZEPHIR_CONCAT_VV(&_22$$36, &_20$$36, &_21$$36);
			zephir_concat_self(&columnSql, &_22$$36);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 23)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("MEDIUMTEXT"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 22)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("SMALLINT"));
			}
			ZEPHIR_CALL_METHOD(&_23$$40, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_24$$40, this_ptr, "checkcolumnunsigned", NULL, 229, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_25$$40);
			ZEPHIR_CONCAT_VV(&_25$$40, &_23$$40, &_24$$40);
			zephir_concat_self(&columnSql, &_25$$40);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 6)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TEXT"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 20)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TIME"));
			}
			ZEPHIR_CALL_METHOD(&_26$$44, column, "getsize", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_GT_LONG(&_26$$44, 0)) {
				ZEPHIR_CALL_METHOD(&_27$$46, this_ptr, "getcolumnsize", NULL, 0, column);
				zephir_check_call_status();
				zephir_concat_self(&columnSql, &_27$$46);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 17)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TIMESTAMP"));
			}
			ZEPHIR_CALL_METHOD(&_28$$47, column, "getsize", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_GT_LONG(&_28$$47, 0)) {
				ZEPHIR_CALL_METHOD(&_29$$49, this_ptr, "getcolumnsize", NULL, 0, column);
				zephir_check_call_status();
				zephir_concat_self(&columnSql, &_29$$49);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 10)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TINYBLOB"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 26)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TINYINT"));
			}
			ZEPHIR_CALL_METHOD(&_30$$52, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_31$$52, this_ptr, "checkcolumnunsigned", NULL, 229, column);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_32$$52);
			ZEPHIR_CONCAT_VV(&_32$$52, &_30$$52, &_31$$52);
			zephir_concat_self(&columnSql, &_32$$52);
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 25)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TINYTEXT"));
			}
			break;
		}
		if (ZEPHIR_IS_LONG(&columnType, 2)) {
			if (ZEPHIR_IS_EMPTY(&columnSql)) {
				zephir_concat_self_str(&columnSql, SL("VARCHAR"));
			}
			ZEPHIR_CALL_METHOD(&_33$$56, this_ptr, "getcolumnsize", NULL, 0, column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_33$$56);
			break;
		}
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&columnSql))) {
			ZEPHIR_INIT_VAR(&_34$$59);
			object_init_ex(&_34$$59, phalcon_db_exception_ce);
			ZEPHIR_CALL_METHOD(&_35$$59, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_36$$59);
			ZEPHIR_CONCAT_SV(&_36$$59, "Unrecognized MySQL data type at column ", &_35$$59);
			ZEPHIR_CALL_METHOD(NULL, &_34$$59, "__construct", NULL, 30, &_36$$59);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_34$$59, "phalcon/Db/Dialect/Mysql.zep", 635);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&typeValues, column, "gettypevalues", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&typeValues))) {
			if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(&valueSql$$61);
				ZVAL_STRING(&valueSql$$61, "");
				zephir_is_iterable(&typeValues, 0, "phalcon/Db/Dialect/Mysql.zep", 649);
				if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&typeValues), _37$$61)
					{
						ZEPHIR_INIT_NVAR(&value$$61);
						ZVAL_COPY(&value$$61, _37$$61);
						ZEPHIR_INIT_NVAR(&_39$$62);
						ZVAL_STRING(&_39$$62, "\"");
						ZEPHIR_CALL_FUNCTION(&_40$$62, "addcslashes", &_41, 228, &value$$61, &_39$$62);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_42$$62);
						ZEPHIR_CONCAT_SVS(&_42$$62, "\"", &_40$$62, "\", ");
						zephir_concat_self(&valueSql$$61, &_42$$62);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &typeValues, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_38$$61, &typeValues, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_38$$61)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&value$$61, &typeValues, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_43$$63);
							ZVAL_STRING(&_43$$63, "\"");
							ZEPHIR_CALL_FUNCTION(&_44$$63, "addcslashes", &_41, 228, &value$$61, &_43$$63);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_45$$63);
							ZEPHIR_CONCAT_SVS(&_45$$63, "\"", &_44$$63, "\", ");
							zephir_concat_self(&valueSql$$61, &_45$$63);
						ZEPHIR_CALL_METHOD(NULL, &typeValues, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&value$$61);
				ZVAL_LONG(&_46$$61, 0);
				ZVAL_LONG(&_47$$61, -2);
				ZEPHIR_INIT_VAR(&_48$$61);
				zephir_substr(&_48$$61, &valueSql$$61, 0 , -2 , 0);
				ZEPHIR_INIT_VAR(&_49$$61);
				ZEPHIR_CONCAT_SVS(&_49$$61, "(", &_48$$61, ")");
				zephir_concat_self(&columnSql, &_49$$61);
			} else {
				ZEPHIR_INIT_VAR(&_50$$64);
				ZVAL_STRING(&_50$$64, "\"");
				ZEPHIR_CALL_FUNCTION(&_51$$64, "addcslashes", &_41, 228, &typeValues, &_50$$64);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_52$$64);
				ZEPHIR_CONCAT_SVS(&_52$$64, "(\"", &_51$$64, "\")");
				zephir_concat_self(&columnSql, &_52$$64);
			}
		}
	} while(0);

	RETURN_CCTOR(&columnSql);
}

/**
 * Generates SQL to check DB parameter FOREIGN_KEY_CHECKS.
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getForeignKeyChecks)
{
	zval *this_ptr = getThis();



	RETURN_STRING("SELECT @@foreign_key_checks");
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, listTables)
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


	if (!(ZEPHIR_IS_EMPTY(&schemaName))) {
		ZEPHIR_CONCAT_SVS(return_value, "SHOW TABLES FROM `", &schemaName, "`");
		RETURN_MM();
	}
	RETURN_MM_STRING("SHOW TABLES");
}

/**
 * Generates the SQL to list all views of a schema or user
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, listViews)
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
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
	}
	}


	if (!(ZEPHIR_IS_EMPTY(&schemaName))) {
		ZEPHIR_CONCAT_SVS(return_value, "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = '", &schemaName, "' ORDER BY view_name");
		RETURN_MM();
	}
	RETURN_MM_STRING("SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = DATABASE() ORDER BY view_name");
}

/**
 * Generates SQL to modify a column in a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, modifyColumn)
{
	zend_bool _11$$8, _12$$8, _13$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, afterPosition, defaultValue, upperDefaultValue, columnDefinition, _0, _1, _2, _3, _9, _10, _19, _20, _23, _4$$4, _5$$4, _6$$4, _7$$5, _8$$5, _14$$8, _15$$9, _16$$10, _17$$10, _18$$10, _21$$12, _22$$12, _24$$15;
	zval tableName, schemaName, sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&currentColumn_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&afterPosition);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&upperDefaultValue);
	ZVAL_UNDEF(&columnDefinition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_24$$15);
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


	ZEPHIR_CALL_METHOD(&columnDefinition, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "ALTER TABLE ", &_0);
	zephir_get_strval(&sql, &_1);
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
		ZEPHIR_CONCAT_SVSVSV(&_6$$4, " CHANGE COLUMN `", &_4$$4, "` `", &_5$$4, "` ", &columnDefinition);
		zephir_concat_self(&sql, &_6$$4);
	} else {
		ZEPHIR_CALL_METHOD(&_7$$5, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$5);
		ZEPHIR_CONCAT_SVSV(&_8$$5, " MODIFY `", &_7$$5, "` ", &columnDefinition);
		zephir_concat_self(&sql, &_8$$5);
	}
	ZEPHIR_CALL_METHOD(&_9, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_9)) {
		zephir_concat_self_str(&sql, " NOT NULL", sizeof(" NOT NULL") - 1);
	} else {
		zephir_concat_self_str(&sql, " NULL", sizeof(" NULL") - 1);
	}
	ZEPHIR_CALL_METHOD(&_10, column, "hasdefault", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_10)) {
		ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&upperDefaultValue);
		zephir_fast_strtoupper(&upperDefaultValue, &defaultValue);
		_11$$8 = zephir_memnstr_str(&upperDefaultValue, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Mysql.zep", 731);
		if (!(_11$$8)) {
			_11$$8 = zephir_memnstr_str(&upperDefaultValue, SL("NULL"), "phalcon/Db/Dialect/Mysql.zep", 731);
		}
		_12$$8 = _11$$8;
		if (!(_12$$8)) {
			_12$$8 = Z_TYPE_P(&defaultValue) == IS_LONG;
		}
		_13$$8 = _12$$8;
		if (!(_13$$8)) {
			ZEPHIR_CALL_FUNCTION(&_14$$8, "is_float", NULL, 227, &defaultValue);
			zephir_check_call_status();
			_13$$8 = zephir_is_true(&_14$$8);
		}
		if (_13$$8) {
			ZEPHIR_INIT_VAR(&_15$$9);
			ZEPHIR_CONCAT_SV(&_15$$9, " DEFAULT ", &defaultValue);
			zephir_concat_self(&sql, &_15$$9);
		} else {
			ZEPHIR_INIT_VAR(&_16$$10);
			ZVAL_STRING(&_16$$10, "\"");
			ZEPHIR_CALL_FUNCTION(&_17$$10, "addcslashes", NULL, 228, &defaultValue, &_16$$10);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_18$$10);
			ZEPHIR_CONCAT_SVS(&_18$$10, " DEFAULT \"", &_17$$10, "\"");
			zephir_concat_self(&sql, &_18$$10);
		}
	}
	ZEPHIR_CALL_METHOD(&_19, column, "isautoincrement", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_19)) {
		zephir_concat_self_str(&sql, " AUTO_INCREMENT", sizeof(" AUTO_INCREMENT") - 1);
	}
	ZEPHIR_CALL_METHOD(&_20, column, "getcomment", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_20)) {
		ZEPHIR_CALL_METHOD(&_21$$12, column, "getcomment", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_22$$12);
		ZEPHIR_CONCAT_SVS(&_22$$12, " COMMENT '", &_21$$12, "'");
		zephir_concat_self(&sql, &_22$$12);
	}
	ZEPHIR_CALL_METHOD(&_23, column, "isfirst", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_23)) {
		zephir_concat_self_str(&sql, " FIRST", sizeof(" FIRST") - 1);
	} else {
		ZEPHIR_CALL_METHOD(&afterPosition, column, "getafterposition", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&afterPosition)) {
			ZEPHIR_INIT_VAR(&_24$$15);
			ZEPHIR_CONCAT_SVS(&_24$$15, " AFTER `", &afterPosition, "`");
			zephir_concat_self(&sql, &_24$$15);
		}
	}
	RETURN_CTOR(&sql);
}

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 *
 *```php
 * $sql = $dialect->sharedLock("SELECT * FROM robots");
 *
 * echo $sql; // SELECT * FROM robots LOCK IN SHARE MODE
 *```
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, sharedLock)
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


	ZEPHIR_CONCAT_VS(return_value, &sqlQuery, " LOCK IN SHARE MODE");
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableExists)
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


	if (!(ZEPHIR_IS_EMPTY(&schemaName))) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", &tableName, "' AND `TABLE_SCHEMA` = '", &schemaName, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME` = '", &tableName, "' AND `TABLE_SCHEMA` = DATABASE()");
	RETURN_MM();
}

/**
 * Generates the SQL to describe the table creation options
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema, sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&sql);
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


	ZEPHIR_INIT_VAR(&sql);
	ZVAL_STRING(&sql, "SELECT TABLES.TABLE_TYPE AS table_type,TABLES.AUTO_INCREMENT AS auto_increment,TABLES.ENGINE AS engine,TABLES.TABLE_COLLATION AS table_collation FROM INFORMATION_SCHEMA.TABLES WHERE ");
	if (!(ZEPHIR_IS_EMPTY(&schema))) {
		ZEPHIR_CONCAT_VSVSVS(return_value, &sql, "TABLES.TABLE_SCHEMA = '", &schema, "' AND TABLES.TABLE_NAME = '", &table, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_VSVS(return_value, &sql, "TABLES.TABLE_SCHEMA = DATABASE() AND TABLES.TABLE_NAME = '", &table, "'");
	RETURN_MM();
}

/**
 * Generates SQL to truncate a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, truncateTable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL;
	zval tableName, schemaName, table;
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
		ZEPHIR_INIT_VAR(&table);
		ZEPHIR_CONCAT_SVSVS(&table, "`", &schemaName, "`.`", &tableName, "`");
	} else {
		ZEPHIR_INIT_NVAR(&table);
		ZEPHIR_CONCAT_SVS(&table, "`", &tableName, "`");
	}
	ZEPHIR_CONCAT_SV(return_value, "TRUNCATE TABLE ", &table);
	RETURN_MM();
}

/**
 * Generates SQL checking for the existence of a schema.view
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, viewExists)
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


	if (!(ZEPHIR_IS_EMPTY(&schemaName))) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`= '", &viewName, "' AND `TABLE_SCHEMA`='", &schemaName, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`='", &viewName, "' AND `TABLE_SCHEMA` = DATABASE()");
	RETURN_MM();
}

/**
 * Generates SQL to add the table creation options
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getTableOptions)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *definition_param = NULL, options, engine, autoIncrement, tableCollation, collationParts, _0$$5, _1$$7, _2$$9, _3$$9, _4$$9;
	zval definition, tableOptions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&tableOptions);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&engine);
	ZVAL_UNDEF(&autoIncrement);
	ZVAL_UNDEF(&tableCollation);
	ZVAL_UNDEF(&collationParts);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$7);
	ZVAL_UNDEF(&_2$$9);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$9);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(definition)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition_param);
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);


	ZEPHIR_OBS_VAR(&options);
	if (!(zephir_array_isset_string_fetch(&options, &definition, SL("options"), 0))) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_INIT_VAR(&tableOptions);
	array_init(&tableOptions);
	ZEPHIR_OBS_VAR(&engine);
	if (zephir_array_isset_string_fetch(&engine, &options, SL("ENGINE"), 0)) {
		if (zephir_is_true(&engine)) {
			ZEPHIR_INIT_VAR(&_0$$5);
			ZEPHIR_CONCAT_SV(&_0$$5, "ENGINE=", &engine);
			zephir_array_append(&tableOptions, &_0$$5, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 857);
		}
	}
	ZEPHIR_OBS_VAR(&autoIncrement);
	if (zephir_array_isset_string_fetch(&autoIncrement, &options, SL("AUTO_INCREMENT"), 0)) {
		if (zephir_is_true(&autoIncrement)) {
			ZEPHIR_INIT_VAR(&_1$$7);
			ZEPHIR_CONCAT_SV(&_1$$7, "AUTO_INCREMENT=", &autoIncrement);
			zephir_array_append(&tableOptions, &_1$$7, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 866);
		}
	}
	ZEPHIR_OBS_VAR(&tableCollation);
	if (zephir_array_isset_string_fetch(&tableCollation, &options, SL("TABLE_COLLATION"), 0)) {
		if (zephir_is_true(&tableCollation)) {
			ZEPHIR_INIT_VAR(&collationParts);
			zephir_fast_explode_str(&collationParts, SL("_"), &tableCollation, LONG_MAX);
			zephir_array_fetch_long(&_2$$9, &collationParts, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Dialect/Mysql.zep", 876);
			ZEPHIR_INIT_VAR(&_3$$9);
			ZEPHIR_CONCAT_SV(&_3$$9, "DEFAULT CHARSET=", &_2$$9);
			zephir_array_append(&tableOptions, &_3$$9, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 876);
			ZEPHIR_INIT_VAR(&_4$$9);
			ZEPHIR_CONCAT_SV(&_4$$9, "COLLATE=", &tableCollation);
			zephir_array_append(&tableOptions, &_4$$9, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 877);
		}
	}
	zephir_fast_join_str(return_value, SL(" "), &tableOptions);
	RETURN_MM();
}

/**
 * Checks if the size and/or scale are present and encloses those values
 * in parentheses if need be
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, checkColumnSizeAndScale)
{
	zval columnSql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, _0, _1$$3, _2$$3, _3$$3, _4$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&columnSql);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);


	ZEPHIR_CALL_METHOD(&_0, column, "getsize", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$3, column, "getsize", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "(", &_1$$3);
		zephir_concat_self(&columnSql, &_2$$3);
		ZEPHIR_CALL_METHOD(&_3$$3, column, "getscale", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$3)) {
			ZEPHIR_CALL_METHOD(&_4$$4, column, "getscale", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_5$$4);
			ZEPHIR_CONCAT_SVS(&_5$$4, ",", &_4$$4, ")");
			zephir_concat_self(&columnSql, &_5$$4);
		} else {
			zephir_concat_self_str(&columnSql, ")", sizeof(")") - 1);
		}
	}
	RETURN_CTOR(&columnSql);
}

/**
 * Checks if a column is unsigned or not and returns the relevant SQL syntax
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, checkColumnUnsigned)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);


	ZEPHIR_CALL_METHOD(&_0, column, "isunsigned", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_STRING(" UNSIGNED");
	}
	RETURN_MM_STRING("");
}

