
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
 * Generates database specific SQL for the SQLite RDBMS
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Sqlite) {

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
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addColumn) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, defaultValue, _0, _1, _2, _3, _4, _5, _10, _11, _6$$3, _7$$5, _8$$5, _9$$5;
	zval tableName, schemaName, sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);

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
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
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
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "ALTER TABLE ", &_0, " ADD COLUMN ");
	zephir_get_strval(&sql, &_1);
	ZEPHIR_CALL_METHOD(&_2, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVSV(&_4, "\"", &_2, "\" ", &_3);
	zephir_concat_self(&sql, &_4);
	ZEPHIR_CALL_METHOD(&_5, column, "hasdefault", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
		ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_fast_strtoupper(&_6$$3, &defaultValue);
		if (zephir_memnstr_str(&_6$$3, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Sqlite.zep", 46)) {
			zephir_concat_self_str(&sql, " DEFAULT CURRENT_TIMESTAMP", sizeof(" DEFAULT CURRENT_TIMESTAMP") - 1);
		} else {
			ZEPHIR_INIT_VAR(&_7$$5);
			ZVAL_STRING(&_7$$5, "\"");
			ZEPHIR_CALL_FUNCTION(&_8$$5, "addcslashes", NULL, 189, &defaultValue, &_7$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_9$$5);
			ZEPHIR_CONCAT_SVS(&_9$$5, " DEFAULT \"", &_8$$5, "\"");
			zephir_concat_self(&sql, &_9$$5);
		}
	}
	ZEPHIR_CALL_METHOD(&_10, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_10)) {
		zephir_concat_self_str(&sql, " NOT NULL", sizeof(" NOT NULL") - 1);
	}
	ZEPHIR_CALL_METHOD(&_11, column, "isautoincrement", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_11)) {
		zephir_concat_self_str(&sql, " PRIMARY KEY AUTOINCREMENT", sizeof(" PRIMARY KEY AUTOINCREMENT") - 1);
	}
	RETURN_CTOR(&sql);

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addForeignKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, reference_sub;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&reference_sub);

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
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Adding a foreign key constraint to an existing table is not supported by SQLite", "phalcon/Db/Dialect/Sqlite.zep", 71);
	return;

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addIndex) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, index_sub, indexType, _5, _6, _7, _0$$3, _1$$5, _2$$5, _3$$6, _4$$6;
	zval tableName, schemaName, sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);

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
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


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
	if (!(Z_TYPE_P(&schemaName) == IS_UNDEF) && Z_STRLEN_P(&schemaName)) {
		ZEPHIR_CALL_METHOD(&_1$$5, index, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$5);
		ZEPHIR_CONCAT_SVSVS(&_2$$5, "\"", &schemaName, "\".\"", &_1$$5, "\"");
		zephir_concat_self(&sql, &_2$$5);
	} else {
		ZEPHIR_CALL_METHOD(&_3$$6, index, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$6);
		ZEPHIR_CONCAT_SVS(&_4$$6, "\"", &_3$$6, "\"");
		zephir_concat_self(&sql, &_4$$6);
	}
	ZEPHIR_CALL_METHOD(&_6, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumnlist", NULL, 65, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SVSVS(&_7, " ON \"", &tableName, "\" (", &_5, ")");
	zephir_concat_self(&sql, &_7);
	RETURN_CTOR(&sql);

}

/**
 * Generates SQL to add the primary key to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, addPrimaryKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, index_sub;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&index_sub);

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
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Adding a primary key after table has been created is not supported by SQLite", "phalcon/Db/Dialect/Sqlite.zep", 108);
	return;

}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createTable) {

	zend_bool hasPrimary = 0, _8$$7, _10$$7, _21$$14, _23$$14, _32$$22, _33$$22, _42$$25, _43$$25;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_15 = NULL, *_37 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, columns, table, temporary, options, createLines, columnLine, column, indexes, index, indexName, indexType, references, reference, defaultValue, referenceSql, onDelete, onUpdate, *_2, _3, _69, _70, _0$$5, _1$$6, _4$$7, _5$$7, _7$$7, _9$$7, _11$$7, _17$$7, _12$$10, _13$$12, _14$$12, _16$$12, _18$$14, _19$$14, _20$$14, _22$$14, _24$$14, _29$$14, _25$$17, _26$$19, _27$$19, _28$$19, *_30$$21, _31$$21, _34$$22, _35$$23, _36$$23, _38$$23, _39$$24, _40$$24, _41$$24, _44$$25, _45$$26, _46$$26, _47$$26, _48$$27, _49$$27, _50$$27, *_51$$28, _52$$28, _53$$29, _54$$29, _55$$29, _56$$29, _57$$29, _58$$29, _59$$30, _60$$31, _61$$32, _62$$32, _63$$32, _64$$32, _65$$32, _66$$32, _67$$33, _68$$34;
	zval tableName, schemaName, sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_69);
	ZVAL_UNDEF(&_70);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_18$$14);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_29$$14);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_31$$21);
	ZVAL_UNDEF(&_34$$22);
	ZVAL_UNDEF(&_35$$23);
	ZVAL_UNDEF(&_36$$23);
	ZVAL_UNDEF(&_38$$23);
	ZVAL_UNDEF(&_39$$24);
	ZVAL_UNDEF(&_40$$24);
	ZVAL_UNDEF(&_41$$24);
	ZVAL_UNDEF(&_44$$25);
	ZVAL_UNDEF(&_45$$26);
	ZVAL_UNDEF(&_46$$26);
	ZVAL_UNDEF(&_47$$26);
	ZVAL_UNDEF(&_48$$27);
	ZVAL_UNDEF(&_49$$27);
	ZVAL_UNDEF(&_50$$27);
	ZVAL_UNDEF(&_52$$28);
	ZVAL_UNDEF(&_53$$29);
	ZVAL_UNDEF(&_54$$29);
	ZVAL_UNDEF(&_55$$29);
	ZVAL_UNDEF(&_56$$29);
	ZVAL_UNDEF(&_57$$29);
	ZVAL_UNDEF(&_58$$29);
	ZVAL_UNDEF(&_59$$30);
	ZVAL_UNDEF(&_60$$31);
	ZVAL_UNDEF(&_61$$32);
	ZVAL_UNDEF(&_62$$32);
	ZVAL_UNDEF(&_63$$32);
	ZVAL_UNDEF(&_64$$32);
	ZVAL_UNDEF(&_65$$32);
	ZVAL_UNDEF(&_66$$32);
	ZVAL_UNDEF(&_67$$33);
	ZVAL_UNDEF(&_68$$34);
	ZVAL_UNDEF(&definition);

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
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);


	ZEPHIR_CALL_METHOD(&table, this_ptr, "preparetable", NULL, 0, &tableName, &schemaName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&temporary);
	ZVAL_BOOL(&temporary, 0);
	ZEPHIR_OBS_VAR(&options);
	if (zephir_array_isset_string_fetch(&options, &definition, SL("options"), 0)) {
		ZEPHIR_OBS_NVAR(&temporary);
		zephir_array_isset_string_fetch(&temporary, &options, SL("temporary"), 0);
	}
	ZEPHIR_OBS_VAR(&columns);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array", "phalcon/Db/Dialect/Sqlite.zep", 132);
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
	zephir_is_iterable(&columns, 0, "phalcon/Db/Dialect/Sqlite.zep", 193);
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
			ZEPHIR_CALL_METHOD(&_7$$7, &column, "isprimary", NULL, 0);
			zephir_check_call_status();
			_8$$7 = zephir_is_true(&_7$$7);
			if (_8$$7) {
				_8$$7 = !hasPrimary;
			}
			if (_8$$7) {
				zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY"));
				hasPrimary = 1;
			}
			ZEPHIR_CALL_METHOD(&_9$$7, &column, "isautoincrement", NULL, 0);
			zephir_check_call_status();
			_10$$7 = zephir_is_true(&_9$$7);
			if (_10$$7) {
				_10$$7 = hasPrimary;
			}
			if (_10$$7) {
				zephir_concat_self_str(&columnLine, SL(" AUTOINCREMENT"));
			}
			ZEPHIR_CALL_METHOD(&_11$$7, &column, "hasdefault", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_11$$7)) {
				ZEPHIR_CALL_METHOD(&defaultValue, &column, "getdefault", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$10);
				zephir_fast_strtoupper(&_12$$10, &defaultValue);
				if (zephir_memnstr_str(&_12$$10, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Sqlite.zep", 173)) {
					zephir_concat_self_str(&columnLine, SL(" DEFAULT CURRENT_TIMESTAMP"));
				} else {
					ZEPHIR_INIT_NVAR(&_13$$12);
					ZVAL_STRING(&_13$$12, "\"");
					ZEPHIR_CALL_FUNCTION(&_14$$12, "addcslashes", &_15, 189, &defaultValue, &_13$$12);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_16$$12);
					ZEPHIR_CONCAT_SVS(&_16$$12, " DEFAULT \"", &_14$$12, "\"");
					zephir_concat_self(&columnLine, &_16$$12);
				}
			}
			ZEPHIR_CALL_METHOD(&_17$$7, &column, "isnotnull", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_17$$7)) {
				zephir_concat_self_str(&columnLine, SL(" NOT NULL"));
			}
			zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 187);
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
				ZEPHIR_CALL_METHOD(&_18$$14, &column, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_19$$14, this_ptr, "getcolumndefinition", &_6, 0, &column);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&columnLine);
				ZEPHIR_CONCAT_SVSV(&columnLine, "`", &_18$$14, "` ", &_19$$14);
				ZEPHIR_CALL_METHOD(&_20$$14, &column, "isprimary", NULL, 0);
				zephir_check_call_status();
				_21$$14 = zephir_is_true(&_20$$14);
				if (_21$$14) {
					_21$$14 = !hasPrimary;
				}
				if (_21$$14) {
					zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY"));
					hasPrimary = 1;
				}
				ZEPHIR_CALL_METHOD(&_22$$14, &column, "isautoincrement", NULL, 0);
				zephir_check_call_status();
				_23$$14 = zephir_is_true(&_22$$14);
				if (_23$$14) {
					_23$$14 = hasPrimary;
				}
				if (_23$$14) {
					zephir_concat_self_str(&columnLine, SL(" AUTOINCREMENT"));
				}
				ZEPHIR_CALL_METHOD(&_24$$14, &column, "hasdefault", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_24$$14)) {
					ZEPHIR_CALL_METHOD(&defaultValue, &column, "getdefault", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_25$$17);
					zephir_fast_strtoupper(&_25$$17, &defaultValue);
					if (zephir_memnstr_str(&_25$$17, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Sqlite.zep", 173)) {
						zephir_concat_self_str(&columnLine, SL(" DEFAULT CURRENT_TIMESTAMP"));
					} else {
						ZEPHIR_INIT_NVAR(&_26$$19);
						ZVAL_STRING(&_26$$19, "\"");
						ZEPHIR_CALL_FUNCTION(&_27$$19, "addcslashes", &_15, 189, &defaultValue, &_26$$19);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_28$$19);
						ZEPHIR_CONCAT_SVS(&_28$$19, " DEFAULT \"", &_27$$19, "\"");
						zephir_concat_self(&columnLine, &_28$$19);
					}
				}
				ZEPHIR_CALL_METHOD(&_29$$14, &column, "isnotnull", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_29$$14)) {
					zephir_concat_self_str(&columnLine, SL(" NOT NULL"));
				}
				zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 187);
			ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	ZEPHIR_OBS_VAR(&indexes);
	if (zephir_array_isset_string_fetch(&indexes, &definition, SL("indexes"), 0)) {
		zephir_is_iterable(&indexes, 0, "phalcon/Db/Dialect/Sqlite.zep", 207);
		if (Z_TYPE_P(&indexes) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&indexes), _30$$21)
			{
				ZEPHIR_INIT_NVAR(&index);
				ZVAL_COPY(&index, _30$$21);
				ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
				zephir_check_call_status();
				_32$$22 = ZEPHIR_IS_STRING(&indexName, "PRIMARY");
				if (_32$$22) {
					_32$$22 = !hasPrimary;
				}
				_33$$22 = !(ZEPHIR_IS_EMPTY(&indexType));
				if (_33$$22) {
					ZEPHIR_INIT_NVAR(&_34$$22);
					zephir_fast_strtoupper(&_34$$22, &indexType);
					_33$$22 = zephir_memnstr_str(&_34$$22, SL("UNIQUE"), "phalcon/Db/Dialect/Sqlite.zep", 203);
				}
				if (_32$$22) {
					ZEPHIR_CALL_METHOD(&_36$$23, &index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_35$$23, this_ptr, "getcolumnlist", &_37, 65, &_36$$23);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_38$$23);
					ZEPHIR_CONCAT_SVS(&_38$$23, "PRIMARY KEY (", &_35$$23, ")");
					zephir_array_append(&createLines, &_38$$23, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 202);
				} else if (_33$$22) {
					ZEPHIR_CALL_METHOD(&_40$$24, &index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_39$$24, this_ptr, "getcolumnlist", &_37, 65, &_40$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_41$$24);
					ZEPHIR_CONCAT_SVS(&_41$$24, "UNIQUE (", &_39$$24, ")");
					zephir_array_append(&createLines, &_41$$24, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 204);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &indexes, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_31$$21, &indexes, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_31$$21)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&index, &indexes, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&indexName, &index, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&indexType, &index, "gettype", NULL, 0);
					zephir_check_call_status();
					_42$$25 = ZEPHIR_IS_STRING(&indexName, "PRIMARY");
					if (_42$$25) {
						_42$$25 = !hasPrimary;
					}
					_43$$25 = !(ZEPHIR_IS_EMPTY(&indexType));
					if (_43$$25) {
						ZEPHIR_INIT_NVAR(&_44$$25);
						zephir_fast_strtoupper(&_44$$25, &indexType);
						_43$$25 = zephir_memnstr_str(&_44$$25, SL("UNIQUE"), "phalcon/Db/Dialect/Sqlite.zep", 203);
					}
					if (_42$$25) {
						ZEPHIR_CALL_METHOD(&_46$$26, &index, "getcolumns", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_45$$26, this_ptr, "getcolumnlist", &_37, 65, &_46$$26);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_47$$26);
						ZEPHIR_CONCAT_SVS(&_47$$26, "PRIMARY KEY (", &_45$$26, ")");
						zephir_array_append(&createLines, &_47$$26, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 202);
					} else if (_43$$25) {
						ZEPHIR_CALL_METHOD(&_49$$27, &index, "getcolumns", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_48$$27, this_ptr, "getcolumnlist", &_37, 65, &_49$$27);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_50$$27);
						ZEPHIR_CONCAT_SVS(&_50$$27, "UNIQUE (", &_48$$27, ")");
						zephir_array_append(&createLines, &_50$$27, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 204);
					}
				ZEPHIR_CALL_METHOD(NULL, &indexes, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&index);
	}
	ZEPHIR_OBS_VAR(&references);
	if (zephir_array_isset_string_fetch(&references, &definition, SL("references"), 0)) {
		zephir_is_iterable(&references, 0, "phalcon/Db/Dialect/Sqlite.zep", 229);
		if (Z_TYPE_P(&references) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&references), _51$$28)
			{
				ZEPHIR_INIT_NVAR(&reference);
				ZVAL_COPY(&reference, _51$$28);
				ZEPHIR_CALL_METHOD(&_53$$29, &reference, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_55$$29, &reference, "getcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_54$$29, this_ptr, "getcolumnlist", &_37, 65, &_55$$29);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_56$$29, &reference, "getreferencedtable", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_58$$29, &reference, "getreferencedcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_57$$29, this_ptr, "getcolumnlist", &_37, 65, &_58$$29);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&referenceSql);
				ZEPHIR_CONCAT_SVSVSSVSVS(&referenceSql, "CONSTRAINT `", &_53$$29, "` FOREIGN KEY (", &_54$$29, ")", " REFERENCES `", &_56$$29, "`(", &_57$$29, ")");
				ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
					ZEPHIR_INIT_NVAR(&_59$$30);
					ZEPHIR_CONCAT_SV(&_59$$30, " ON DELETE ", &onDelete);
					zephir_concat_self(&referenceSql, &_59$$30);
				}
				ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
					ZEPHIR_INIT_NVAR(&_60$$31);
					ZEPHIR_CONCAT_SV(&_60$$31, " ON UPDATE ", &onUpdate);
					zephir_concat_self(&referenceSql, &_60$$31);
				}
				zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 227);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &references, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_52$$28, &references, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_52$$28)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&reference, &references, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_61$$32, &reference, "getname", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_63$$32, &reference, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_62$$32, this_ptr, "getcolumnlist", &_37, 65, &_63$$32);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_64$$32, &reference, "getreferencedtable", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_66$$32, &reference, "getreferencedcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_65$$32, this_ptr, "getcolumnlist", &_37, 65, &_66$$32);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&referenceSql);
					ZEPHIR_CONCAT_SVSVSSVSVS(&referenceSql, "CONSTRAINT `", &_61$$32, "` FOREIGN KEY (", &_62$$32, ")", " REFERENCES `", &_64$$32, "`(", &_65$$32, ")");
					ZEPHIR_CALL_METHOD(&onDelete, &reference, "getondelete", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
						ZEPHIR_INIT_NVAR(&_67$$33);
						ZEPHIR_CONCAT_SV(&_67$$33, " ON DELETE ", &onDelete);
						zephir_concat_self(&referenceSql, &_67$$33);
					}
					ZEPHIR_CALL_METHOD(&onUpdate, &reference, "getonupdate", NULL, 0);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
						ZEPHIR_INIT_NVAR(&_68$$34);
						ZEPHIR_CONCAT_SV(&_68$$34, " ON UPDATE ", &onUpdate);
						zephir_concat_self(&referenceSql, &_68$$34);
					}
					zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Sqlite.zep", 227);
				ZEPHIR_CALL_METHOD(NULL, &references, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&reference);
	}
	ZEPHIR_INIT_VAR(&_69);
	zephir_fast_join_str(&_69, SL(",\n\t"), &createLines);
	ZEPHIR_INIT_VAR(&_70);
	ZEPHIR_CONCAT_VS(&_70, &_69, "\n)");
	zephir_concat_self(&sql, &_70);
	RETURN_CTOR(&sql);

}

/**
 * Generates SQL to create a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, createView) {

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
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&viewSql, &definition, SL("sql"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array", "phalcon/Db/Dialect/Sqlite.zep", 246);
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
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeColumns) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);

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
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA table_info('", &table, "')");
	RETURN_MM();

}

/**
 * Generates SQL to query indexes detail on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndex) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *index_param = NULL;
	zval index;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	if (UNEXPECTED(Z_TYPE_P(index_param) != IS_STRING && Z_TYPE_P(index_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'index' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(index_param) == IS_STRING)) {
		zephir_get_strval(&index, index_param);
	} else {
		ZEPHIR_INIT_VAR(&index);
		ZVAL_EMPTY_STRING(&index);
	}


	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA index_info('", &index, "')");
	RETURN_MM();

}

/**
 * Generates SQL to query indexes on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeIndexes) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);

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
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA index_list('", &table, "')");
	RETURN_MM();

}

/**
 * Generates SQL to query foreign keys on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, describeReferences) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);

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
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_CONCAT_SVS(return_value, "PRAGMA foreign_key_list('", &table, "')");
	RETURN_MM();

}

/**
 * Generates SQL to delete a column from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropColumn) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL;
	zval tableName, schemaName, columnName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&columnName);

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
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(columnName_param) != IS_STRING && Z_TYPE_P(columnName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'columnName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(columnName_param) == IS_STRING)) {
		zephir_get_strval(&columnName, columnName_param);
	} else {
		ZEPHIR_INIT_VAR(&columnName);
		ZVAL_EMPTY_STRING(&columnName);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Dropping DB column is not supported by SQLite", "phalcon/Db/Dialect/Sqlite.zep", 295);
	return;

}

/**
 * Generates SQL to delete a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropForeignKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName_param = NULL;
	zval tableName, schemaName, referenceName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&referenceName);

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
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(referenceName_param) != IS_STRING && Z_TYPE_P(referenceName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceName_param) == IS_STRING)) {
		zephir_get_strval(&referenceName, referenceName_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceName);
		ZVAL_EMPTY_STRING(&referenceName);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Dropping a foreign key constraint is not supported by SQLite", "phalcon/Db/Dialect/Sqlite.zep", 305);
	return;

}

/**
 * Generates SQL to delete an index from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropIndex) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName_param = NULL;
	zval tableName, schemaName, indexName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&indexName);

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
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (UNEXPECTED(Z_TYPE_P(indexName_param) != IS_STRING && Z_TYPE_P(indexName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'indexName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(indexName_param) == IS_STRING)) {
		zephir_get_strval(&indexName, indexName_param);
	} else {
		ZEPHIR_INIT_VAR(&indexName);
		ZVAL_EMPTY_STRING(&indexName);
	}


	if (!(Z_TYPE_P(&schemaName) == IS_UNDEF) && Z_STRLEN_P(&schemaName)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "DROP INDEX \"", &schemaName, "\".\"", &indexName, "\"");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "DROP INDEX \"", &indexName, "\"");
	RETURN_MM();

}

/**
 * Generates SQL to delete primary key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropPrimaryKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);

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
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Removing a primary key after table has been created is not supported by SQLite", "phalcon/Db/Dialect/Sqlite.zep", 327);
	return;

}

/**
 * Generates SQL to drop a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropTable) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, table;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&table);

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
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, dropView) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, view;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&view);

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
 * Returns a SQL modified with a FOR UPDATE clause. For SQLite it returns
 * the original query
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, forUpdate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sqlQuery_param = NULL;
	zval sqlQuery;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery);

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
		ZVAL_EMPTY_STRING(&sqlQuery);
	}


	RETURN_CTOR(&sqlQuery);

}

/**
 * Gets the column name in SQLite
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, getColumnDefinition) {

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
			object_init_ex(&_5$$38, phalcon_db_exception_ce);
			ZEPHIR_CALL_METHOD(&_6$$38, column, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_7$$38);
			ZEPHIR_CONCAT_SV(&_7$$38, "Unrecognized SQLite data type at column ", &_6$$38);
			ZEPHIR_CALL_METHOD(NULL, &_5$$38, "__construct", NULL, 6, &_7$$38);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$38, "phalcon/Db/Dialect/Sqlite.zep", 516);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(&typeValues, column, "gettypevalues", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&typeValues))) {
			if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(&valueSql$$40);
				ZVAL_STRING(&valueSql$$40, "");
				zephir_is_iterable(&typeValues, 0, "phalcon/Db/Dialect/Sqlite.zep", 530);
				if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&typeValues), _8$$40)
					{
						ZEPHIR_INIT_NVAR(&value$$40);
						ZVAL_COPY(&value$$40, _8$$40);
						ZEPHIR_INIT_NVAR(&_10$$41);
						ZVAL_STRING(&_10$$41, "\"");
						ZEPHIR_CALL_FUNCTION(&_11$$41, "addcslashes", &_12, 189, &value$$40, &_10$$41);
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
							ZEPHIR_CALL_FUNCTION(&_15$$42, "addcslashes", &_12, 189, &value$$40, &_14$$42);
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
				ZEPHIR_CALL_FUNCTION(&_22$$43, "addcslashes", &_12, 189, &typeValues, &_21$$43);
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
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listIndexesSql) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *keyName_param = NULL, _0, _1, _2$$3, _3$$3;
	zval table, schema, keyName, sql;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &table_param, &schema_param, &keyName_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string"));
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
	if (!keyName_param) {
		ZEPHIR_INIT_VAR(&keyName);
		ZVAL_STRING(&keyName, "");
	} else {
		zephir_get_strval(&keyName, keyName_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "escape", NULL, 64, &table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "SELECT sql FROM sqlite_master WHERE type = 'index' AND tbl_name = ", &_0, " COLLATE NOCASE");
	zephir_get_strval(&sql, &_1);
	if (!(Z_TYPE_P(&keyName) == IS_UNDEF) && Z_STRLEN_P(&keyName)) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "escape", NULL, 64, &keyName);
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
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listTables) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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


	RETURN_MM_STRING("SELECT tbl_name FROM sqlite_master WHERE type = 'table' ORDER BY tbl_name");

}

/**
 * Generates the SQL to list all views of a schema or user
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, listViews) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	}


	RETURN_MM_STRING("SELECT tbl_name FROM sqlite_master WHERE type = 'view' ORDER BY tbl_name");

}

/**
 * Generates SQL to modify a column in a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, modifyColumn) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&currentColumn_sub);
	ZVAL_NULL(&__$null);

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
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
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
		currentColumn = &__$null;
	}


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Altering a DB column is not supported by SQLite", "phalcon/Db/Dialect/Sqlite.zep", 589);
	return;

}

/**
 * Returns a SQL modified a shared lock statement. For now this method
 * returns the original query
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, sharedLock) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sqlQuery_param = NULL;
	zval sqlQuery;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sqlQuery);

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
		ZVAL_EMPTY_STRING(&sqlQuery);
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
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, tableExists) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);

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
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='table' AND tbl_name='", &tableName, "'");
	RETURN_MM();

}

/**
 * Generates the SQL to describe the table creation options
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, tableOptions) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *table_param = NULL, *schema_param = NULL;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);

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

/**
 * Generates SQL to truncate a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, truncateTable) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL;
	zval tableName, schemaName, table;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&table);

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
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}


	if (!(Z_TYPE_P(&schemaName) == IS_UNDEF) && Z_STRLEN_P(&schemaName)) {
		ZEPHIR_INIT_VAR(&table);
		ZEPHIR_CONCAT_SVSVS(&table, "\"", &schemaName, "\".\"", &tableName, "\"");
	} else {
		ZEPHIR_INIT_NVAR(&table);
		ZEPHIR_CONCAT_SVS(&table, "\"", &tableName, "\"");
	}
	ZEPHIR_CONCAT_SV(return_value, "DELETE FROM ", &table);
	RETURN_MM();

}

/**
 * Generates SQL checking for the existence of a schema.view
 */
PHP_METHOD(Phalcon_Db_Dialect_Sqlite, viewExists) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *viewName_param = NULL, *schemaName_param = NULL;
	zval viewName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName);
	ZVAL_UNDEF(&schemaName);

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
		ZVAL_EMPTY_STRING(&viewName);
	}
	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_STRING(&schemaName, "");
	} else {
		zephir_get_strval(&schemaName, schemaName_param);
	}


	ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END FROM sqlite_master WHERE type='view' AND tbl_name='", &viewName, "'");
	RETURN_MM();

}

