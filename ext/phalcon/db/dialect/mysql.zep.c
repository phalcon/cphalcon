
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
#include "kernel/array.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Generates database specific SQL for the MySQL RDBMS
 *
 * @phpstan-import-type db_table_options from DbTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Mysql)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Mysql, phalcon, db_dialect_mysql, phalcon_db_dialect_ce, phalcon_db_dialect_mysql_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_dialect_mysql_ce, SL("escapeChar"), "`", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 *
	 * @phpstan-var list<string>
	 */
	zend_declare_property_null(phalcon_db_dialect_mysql_ce, SL("supportedOperators"), ZEND_ACC_PROTECTED);
	phalcon_db_dialect_mysql_ce->create_object = zephir_init_properties_Phalcon_Db_Dialect_Mysql;

	return SUCCESS;
}

/**
 * Generates SQL to add a column to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addColumn)
{
	zend_bool _9$$7, _12$$9, _13$$9, _14$$9;
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *column, column_sub, afterPosition, defaultValue, upperDefaultValue, _0, _1, _2, _3, _4, _5, _6, _7, _20, _8$$6, _19$$6, _10$$8, _11$$8, _15$$9, _16$$10, _17$$11, _18$$11, _21$$15;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
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
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&sql);
	ZEND_TLS zephir_method_cache _zephir_call_cache[14];
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
	ZEPHIR_CALL_METHOD_CACHED(&_1, column, "getName", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "getColumnDefinition", &_zephir_call_cache[2], column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "getGeneratedClause", &_zephir_call_cache[3], column);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVSVSVV(&_4, "ALTER TABLE ", &_0, " ADD `", &_1, "` ", &_2, &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&sql, &_4);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_5, column, "isNotNull", &_zephir_call_cache[4]);
	zephir_check_call_status();
	if (zephir_is_true(&_5)) {
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
	ZEPHIR_CALL_METHOD_CACHED(&_6, column, "isInvisible", &_zephir_call_cache[5]);
	zephir_check_call_status();
	if (zephir_is_true(&_6)) {
		zephir_concat_self_str(&sql, " INVISIBLE", sizeof(" INVISIBLE") - 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_7, column, "isGenerated", &_zephir_call_cache[6]);
	zephir_check_call_status();
	if (!(zephir_is_true(&_7))) {
		ZEPHIR_CALL_METHOD_CACHED(&_8$$6, column, "hasDefault", &_zephir_call_cache[7]);
		zephir_check_call_status();
		if (zephir_is_true(&_8$$6)) {
			ZEPHIR_CALL_METHOD_CACHED(&defaultValue, column, "getDefault", &_zephir_call_cache[8]);
			zephir_check_call_status();
			_9$$7 = Z_TYPE_P(&defaultValue) == IS_OBJECT;
			if (_9$$7) {
				_9$$7 = zephir_instance_of_ev(&defaultValue, phalcon_db_rawvalue_ce);
			}
			if (_9$$7) {
				ZEPHIR_CALL_METHOD_CACHED(&_10$$8, &defaultValue, "getValue", &_zephir_call_cache[9]);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_11$$8);
				ZEPHIR_CONCAT_SV(&_11$$8, " DEFAULT ", &_10$$8);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&sql, &_11$$8);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_INIT_VAR(&upperDefaultValue);
				zephir_fast_strtoupper(&upperDefaultValue, &defaultValue);
				_12$$9 = zephir_memnstr_str(&upperDefaultValue, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Mysql.zep", 81);
				if (!(_12$$9)) {
					_12$$9 = zephir_memnstr_str(&upperDefaultValue, SL("NULL"), "phalcon/Db/Dialect/Mysql.zep", 81);
				}
				_13$$9 = _12$$9;
				if (!(_13$$9)) {
					_13$$9 = (Z_TYPE_P(&defaultValue) == IS_LONG);
				}
				_14$$9 = _13$$9;
				if (!(_14$$9)) {
					ZEPHIR_CALL_FUNCTION(&_15$$9, "is_float", NULL, 19, &defaultValue);
					zephir_check_call_status();
					_14$$9 = zephir_is_true(&_15$$9);
				}
				if (_14$$9) {
					ZEPHIR_INIT_VAR(&_16$$10);
					ZEPHIR_CONCAT_SV(&_16$$10, " DEFAULT ", &defaultValue);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&sql, &_16$$10);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CALL_METHOD_CACHED(&_17$$11, this_ptr, "escapeStringLiteral", &_zephir_call_cache[10], &defaultValue);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(&_18$$11);
					ZEPHIR_CONCAT_SVS(&_18$$11, " DEFAULT '", &_17$$11, "'");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&sql, &_18$$11);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_19$$6, column, "isAutoIncrement", &_zephir_call_cache[11]);
		zephir_check_call_status();
		if (zephir_is_true(&_19$$6)) {
			zephir_concat_self_str(&sql, " AUTO_INCREMENT", sizeof(" AUTO_INCREMENT") - 1);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_20, column, "isFirst", &_zephir_call_cache[12]);
	zephir_check_call_status();
	if (zephir_is_true(&_20)) {
		zephir_concat_self_str(&sql, " FIRST", sizeof(" FIRST") - 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD_CACHED(&afterPosition, column, "getAfterPosition", &_zephir_call_cache[13]);
		zephir_check_call_status();
		if (zephir_is_true(&afterPosition)) {
			ZEPHIR_INIT_VAR(&_21$$15);
			ZEPHIR_CONCAT_SVS(&_21$$15, " AFTER `", &afterPosition, "`");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_concat_self(&sql, &_21$$15);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to add a CHECK constraint to an existing table.
 * Enforced by MySQL 8.0.16+.
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addCheck)
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "prepareTable", &_zephir_call_cache[0], &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "`");
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "getCheckClause", &_zephir_call_cache[1], check, &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSV(return_value, "ALTER TABLE ", &_0, " ADD ", &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addForeignKey)
{
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *reference, reference_sub, onDelete, onUpdate, _0, _1, _2, _5, _6, _7, _8, _9, _10, _11, _12, _3$$3, _4$$3, _13$$4, _14$$5;
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
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&sql);
	ZEND_TLS zephir_method_cache _zephir_call_cache[12];
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "prepareTable", &_zephir_call_cache[0], &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "ALTER TABLE ", &_0, " ADD");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&sql, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, reference, "getName", &_zephir_call_cache[1]);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD_CACHED(&_3$$3, reference, "getName", &_zephir_call_cache[2]);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SVS(&_4$$3, " CONSTRAINT `", &_3$$3, "`");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&sql, &_4$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_6, reference, "getColumns", &_zephir_call_cache[3]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_5, this_ptr, "getColumnList", &_zephir_call_cache[4], &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_8, reference, "getReferencedTable", &_zephir_call_cache[5]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_9, reference, "getReferencedSchema", &_zephir_call_cache[6]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_7, this_ptr, "prepareTable", &_zephir_call_cache[7], &_8, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_11, reference, "getReferencedColumns", &_zephir_call_cache[8]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_10, this_ptr, "getColumnList", &_zephir_call_cache[9], &_11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_SVSVSVS(&_12, " FOREIGN KEY (", &_5, ") REFERENCES ", &_7, "(", &_10, ")");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_concat_self(&sql, &_12);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&onDelete, reference, "getOnDelete", &_zephir_call_cache[10]);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
		ZEPHIR_INIT_VAR(&_13$$4);
		ZEPHIR_CONCAT_SV(&_13$$4, " ON DELETE ", &onDelete);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&sql, &_13$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&onUpdate, reference, "getOnUpdate", &_zephir_call_cache[11]);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
		ZEPHIR_INIT_VAR(&_14$$5);
		ZEPHIR_CONCAT_SV(&_14$$5, " ON UPDATE ", &onUpdate);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&sql, &_14$$5);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addIndex)
{
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *index, index_sub, indexType, _0, _1, _3, _4, _5, _6, _2$$3;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&sql);
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "prepareTable", &_zephir_call_cache[0], &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "ALTER TABLE ", &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&sql, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&indexType, index, "getType", &_zephir_call_cache[1]);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&indexType))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, " ADD ", &indexType, " INDEX ");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&sql, &_2$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		zephir_concat_self_str(&sql, " ADD INDEX ", sizeof(" ADD INDEX ") - 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_3, index, "getName", &_zephir_call_cache[2]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_4, this_ptr, "getIndexColumnList", &_zephir_call_cache[3], index);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVSVS(&_5, "`", &_3, "` (", &_4, ")");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_concat_self(&sql, &_5);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_6, index, "isInvisible", &_zephir_call_cache[4]);
	zephir_check_call_status();
	if (zephir_is_true(&_6)) {
		zephir_concat_self_str(&sql, " INVISIBLE", sizeof(" INVISIBLE") - 1);
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, addPrimaryKey)
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
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "prepareTable", &_zephir_call_cache[0], &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_2, index, "getColumns", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "getColumnList", &_zephir_call_cache[2], &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " ADD PRIMARY KEY (", &_1, ")");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, createTable)
{
	zend_bool _0, _1, _33, _57, _77, _105, _117, _2$$4, _15$$12, _18$$14, _19$$14, _20$$14, _41$$25, _44$$27, _45$$27, _46$$27, _69$$33, _93$$46, _112$$53;
	zval indexSql, referenceSql, sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_22 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition, createLines;
	zval tableName_zv, schemaName_zv, *definition_param = NULL, temporary, options, table, columns, column, indexes, index, reference, references, indexName, columnLine, indexType, onDelete, onUpdate, defaultValue, upperDefaultValue, checks, check, *_5, _6, *_7, _32, _115, _116, _3$$5, _4$$6, _8$$7, _9$$7, _10$$7, _11$$7, _12$$7, _13$$7, _27$$7, _28$$7, _14$$11, _26$$11, _16$$13, _17$$13, _21$$14, _23$$15, _24$$16, _25$$16, _29$$19, _30$$19, _31$$19, _34$$20, _35$$20, _36$$20, _37$$20, _38$$20, _39$$20, _52$$20, _53$$20, _40$$24, _51$$24, _42$$26, _43$$26, _47$$27, _48$$28, _49$$29, _50$$29, _54$$32, _55$$32, _56$$32, *_58$$33, _59$$33, *_60$$33, _68$$33, _61$$35, _62$$35, _63$$37, _64$$37, _65$$38, _66$$38, _67$$36, _70$$41, _71$$41, _72$$43, _73$$43, _74$$44, _75$$44, _76$$42, *_78$$46, _79$$46, *_80$$46, _92$$46, _81$$47, _82$$47, _83$$47, _84$$47, _85$$47, _86$$47, _87$$47, _88$$47, _89$$47, _90$$48, _91$$49, _94$$50, _95$$50, _96$$50, _97$$50, _98$$50, _99$$50, _100$$50, _101$$50, _102$$50, _103$$51, _104$$52, *_106$$53, _107$$53, *_108$$53, _111$$53, _109$$54, _110$$54, _113$$55, _114$$55, _118$$56, _119$$56;
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
	ZVAL_UNDEF(&columnLine);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&onDelete);
	ZVAL_UNDEF(&onUpdate);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&upperDefaultValue);
	ZVAL_UNDEF(&checks);
	ZVAL_UNDEF(&check);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_115);
	ZVAL_UNDEF(&_116);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_35$$20);
	ZVAL_UNDEF(&_36$$20);
	ZVAL_UNDEF(&_37$$20);
	ZVAL_UNDEF(&_38$$20);
	ZVAL_UNDEF(&_39$$20);
	ZVAL_UNDEF(&_52$$20);
	ZVAL_UNDEF(&_53$$20);
	ZVAL_UNDEF(&_40$$24);
	ZVAL_UNDEF(&_51$$24);
	ZVAL_UNDEF(&_42$$26);
	ZVAL_UNDEF(&_43$$26);
	ZVAL_UNDEF(&_47$$27);
	ZVAL_UNDEF(&_48$$28);
	ZVAL_UNDEF(&_49$$29);
	ZVAL_UNDEF(&_50$$29);
	ZVAL_UNDEF(&_54$$32);
	ZVAL_UNDEF(&_55$$32);
	ZVAL_UNDEF(&_56$$32);
	ZVAL_UNDEF(&_59$$33);
	ZVAL_UNDEF(&_68$$33);
	ZVAL_UNDEF(&_61$$35);
	ZVAL_UNDEF(&_62$$35);
	ZVAL_UNDEF(&_63$$37);
	ZVAL_UNDEF(&_64$$37);
	ZVAL_UNDEF(&_65$$38);
	ZVAL_UNDEF(&_66$$38);
	ZVAL_UNDEF(&_67$$36);
	ZVAL_UNDEF(&_70$$41);
	ZVAL_UNDEF(&_71$$41);
	ZVAL_UNDEF(&_72$$43);
	ZVAL_UNDEF(&_73$$43);
	ZVAL_UNDEF(&_74$$44);
	ZVAL_UNDEF(&_75$$44);
	ZVAL_UNDEF(&_76$$42);
	ZVAL_UNDEF(&_79$$46);
	ZVAL_UNDEF(&_92$$46);
	ZVAL_UNDEF(&_81$$47);
	ZVAL_UNDEF(&_82$$47);
	ZVAL_UNDEF(&_83$$47);
	ZVAL_UNDEF(&_84$$47);
	ZVAL_UNDEF(&_85$$47);
	ZVAL_UNDEF(&_86$$47);
	ZVAL_UNDEF(&_87$$47);
	ZVAL_UNDEF(&_88$$47);
	ZVAL_UNDEF(&_89$$47);
	ZVAL_UNDEF(&_90$$48);
	ZVAL_UNDEF(&_91$$49);
	ZVAL_UNDEF(&_94$$50);
	ZVAL_UNDEF(&_95$$50);
	ZVAL_UNDEF(&_96$$50);
	ZVAL_UNDEF(&_97$$50);
	ZVAL_UNDEF(&_98$$50);
	ZVAL_UNDEF(&_99$$50);
	ZVAL_UNDEF(&_100$$50);
	ZVAL_UNDEF(&_101$$50);
	ZVAL_UNDEF(&_102$$50);
	ZVAL_UNDEF(&_103$$51);
	ZVAL_UNDEF(&_104$$52);
	ZVAL_UNDEF(&_107$$53);
	ZVAL_UNDEF(&_111$$53);
	ZVAL_UNDEF(&_109$$54);
	ZVAL_UNDEF(&_110$$54);
	ZVAL_UNDEF(&_113$$55);
	ZVAL_UNDEF(&_114$$55);
	ZVAL_UNDEF(&_118$$56);
	ZVAL_UNDEF(&_119$$56);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&createLines);
	ZVAL_UNDEF(&indexSql);
	ZVAL_UNDEF(&referenceSql);
	ZVAL_UNDEF(&sql);
	ZEND_TLS zephir_method_cache _zephir_call_cache[82];
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
	zephir_memory_observe(&columns);
	_0 = zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_missingdefinitionkey_ce, "columns", "phalcon/Db/Dialect/Mysql.zep", 193);
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&table, this_ptr, "prepareTable", &_zephir_call_cache[0], &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&temporary);
	ZVAL_BOOL(&temporary, 0);
	zephir_memory_observe(&options);
	_1 = zephir_array_isset_string_fetch(&options, &definition, SL("options"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		ZEPHIR_OBS_NVAR(&temporary);
		_2$$4 = zephir_array_isset_string_fetch(&temporary, &options, SL("temporary"), 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_2$$4;
	}
	if (zephir_is_true(&temporary)) {
		ZEPHIR_INIT_VAR(&_3$$5);
		ZEPHIR_CONCAT_SVS(&_3$$5, "CREATE TEMPORARY TABLE ", &table, " (\n\t");
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
		ZEPHIR_CONCAT_SVS(&_4$$6, "CREATE TABLE ", &table, " (\n\t");
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
	ZEPHIR_INIT_VAR(&createLines);
	array_init(&createLines);
	if (Z_TYPE_P(&columns) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_6);
		zephir_string_to_char_array(&_6, &columns);
		_5 = &_6;
	} else {
		_5 = &columns;
	}
	zephir_is_iterable(_5, 0, "phalcon/Db/Dialect/Mysql.zep", 283);
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
			ZEPHIR_CALL_METHOD_CACHED(&_11$$7, &column, "isNotNull", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (zephir_is_true(&_11$$7)) {
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
			ZEPHIR_CALL_METHOD_CACHED(&_12$$7, &column, "isInvisible", &_zephir_call_cache[5]);
			zephir_check_call_status();
			if (zephir_is_true(&_12$$7)) {
				zephir_concat_self_str(&columnLine, SL(" INVISIBLE"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_CALL_METHOD_CACHED(&_13$$7, &column, "isGenerated", &_zephir_call_cache[6]);
			zephir_check_call_status();
			if (!(zephir_is_true(&_13$$7))) {
				ZEPHIR_CALL_METHOD_CACHED(&_14$$11, &column, "hasDefault", &_zephir_call_cache[7]);
				zephir_check_call_status();
				if (zephir_is_true(&_14$$11)) {
					ZEPHIR_CALL_METHOD_CACHED(&defaultValue, &column, "getDefault", &_zephir_call_cache[8]);
					zephir_check_call_status();
					_15$$12 = Z_TYPE_P(&defaultValue) == IS_OBJECT;
					if (_15$$12) {
						_15$$12 = zephir_instance_of_ev(&defaultValue, phalcon_db_rawvalue_ce);
					}
					if (_15$$12) {
						ZEPHIR_CALL_METHOD_CACHED(&_16$$13, &defaultValue, "getValue", &_zephir_call_cache[9]);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_17$$13);
						ZEPHIR_CONCAT_SV(&_17$$13, " DEFAULT ", &_16$$13);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&columnLine, &_17$$13);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&upperDefaultValue);
						zephir_fast_strtoupper(&upperDefaultValue, &defaultValue);
						_18$$14 = zephir_memnstr_str(&upperDefaultValue, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Mysql.zep", 247);
						if (!(_18$$14)) {
							_18$$14 = zephir_memnstr_str(&upperDefaultValue, SL("NULL"), "phalcon/Db/Dialect/Mysql.zep", 247);
						}
						_19$$14 = _18$$14;
						if (!(_19$$14)) {
							_19$$14 = (Z_TYPE_P(&defaultValue) == IS_LONG);
						}
						_20$$14 = _19$$14;
						if (!(_20$$14)) {
							ZEPHIR_CALL_FUNCTION(&_21$$14, "is_float", &_22, 19, &defaultValue);
							zephir_check_call_status();
							_20$$14 = zephir_is_true(&_21$$14);
						}
						if (_20$$14) {
							ZEPHIR_INIT_NVAR(&_23$$15);
							ZEPHIR_CONCAT_SV(&_23$$15, " DEFAULT ", &defaultValue);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_concat_self(&columnLine, &_23$$15);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_CALL_METHOD_CACHED(&_24$$16, this_ptr, "escapeStringLiteral", &_zephir_call_cache[10], &defaultValue);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_25$$16);
							ZEPHIR_CONCAT_SVS(&_25$$16, " DEFAULT '", &_24$$16, "'");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_concat_self(&columnLine, &_25$$16);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
				}
				ZEPHIR_CALL_METHOD_CACHED(&_26$$11, &column, "isAutoIncrement", &_zephir_call_cache[11]);
				zephir_check_call_status();
				if (zephir_is_true(&_26$$11)) {
					zephir_concat_self_str(&columnLine, SL(" AUTO_INCREMENT"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			ZEPHIR_CALL_METHOD_CACHED(&_27$$7, &column, "isPrimary", &_zephir_call_cache[12]);
			zephir_check_call_status();
			if (zephir_is_true(&_27$$7)) {
				zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_CALL_METHOD_CACHED(&_28$$7, &column, "getComment", &_zephir_call_cache[13]);
			zephir_check_call_status();
			if (zephir_is_true(&_28$$7)) {
				ZEPHIR_CALL_METHOD_CACHED(&_30$$19, &column, "getComment", &_zephir_call_cache[14]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_29$$19, this_ptr, "escapeStringLiteral", &_zephir_call_cache[15], &_30$$19);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_31$$19);
				ZEPHIR_CONCAT_SVS(&_31$$19, " COMMENT '", &_29$$19, "'");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&columnLine, &_31$$19);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 277);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "rewind", &_zephir_call_cache[16]);
		zephir_check_call_status();
		_33 = 1;
		while (1) {
			if (_33) {
				_33 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _5, "next", &_zephir_call_cache[17]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_32, _5, "valid", &_zephir_call_cache[18]);
			zephir_check_call_status();
			if (!zend_is_true(&_32)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&column, _5, "current", &_zephir_call_cache[19]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_34$$20, &column, "getName", &_zephir_call_cache[20]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_35$$20, this_ptr, "getColumnDefinition", &_zephir_call_cache[21], &column);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_36$$20, this_ptr, "getGeneratedClause", &_zephir_call_cache[22], &column);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&columnLine);
				ZEPHIR_CONCAT_SVSVV(&columnLine, "`", &_34$$20, "` ", &_35$$20, &_36$$20);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_37$$20, &column, "isNotNull", &_zephir_call_cache[23]);
				zephir_check_call_status();
				if (zephir_is_true(&_37$$20)) {
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
				ZEPHIR_CALL_METHOD_CACHED(&_38$$20, &column, "isInvisible", &_zephir_call_cache[24]);
				zephir_check_call_status();
				if (zephir_is_true(&_38$$20)) {
					zephir_concat_self_str(&columnLine, SL(" INVISIBLE"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_CALL_METHOD_CACHED(&_39$$20, &column, "isGenerated", &_zephir_call_cache[25]);
				zephir_check_call_status();
				if (!(zephir_is_true(&_39$$20))) {
					ZEPHIR_CALL_METHOD_CACHED(&_40$$24, &column, "hasDefault", &_zephir_call_cache[26]);
					zephir_check_call_status();
					if (zephir_is_true(&_40$$24)) {
						ZEPHIR_CALL_METHOD_CACHED(&defaultValue, &column, "getDefault", &_zephir_call_cache[27]);
						zephir_check_call_status();
						_41$$25 = Z_TYPE_P(&defaultValue) == IS_OBJECT;
						if (_41$$25) {
							_41$$25 = zephir_instance_of_ev(&defaultValue, phalcon_db_rawvalue_ce);
						}
						if (_41$$25) {
							ZEPHIR_CALL_METHOD_CACHED(&_42$$26, &defaultValue, "getValue", &_zephir_call_cache[28]);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_43$$26);
							ZEPHIR_CONCAT_SV(&_43$$26, " DEFAULT ", &_42$$26);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_concat_self(&columnLine, &_43$$26);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_INIT_NVAR(&upperDefaultValue);
							zephir_fast_strtoupper(&upperDefaultValue, &defaultValue);
							_44$$27 = zephir_memnstr_str(&upperDefaultValue, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Mysql.zep", 247);
							if (!(_44$$27)) {
								_44$$27 = zephir_memnstr_str(&upperDefaultValue, SL("NULL"), "phalcon/Db/Dialect/Mysql.zep", 247);
							}
							_45$$27 = _44$$27;
							if (!(_45$$27)) {
								_45$$27 = (Z_TYPE_P(&defaultValue) == IS_LONG);
							}
							_46$$27 = _45$$27;
							if (!(_46$$27)) {
								ZEPHIR_CALL_FUNCTION(&_47$$27, "is_float", &_22, 19, &defaultValue);
								zephir_check_call_status();
								_46$$27 = zephir_is_true(&_47$$27);
							}
							if (_46$$27) {
								ZEPHIR_INIT_NVAR(&_48$$28);
								ZEPHIR_CONCAT_SV(&_48$$28, " DEFAULT ", &defaultValue);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_concat_self(&columnLine, &_48$$28);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							} else {
								ZEPHIR_CALL_METHOD_CACHED(&_49$$29, this_ptr, "escapeStringLiteral", &_zephir_call_cache[29], &defaultValue);
								zephir_check_call_status();
								ZEPHIR_INIT_NVAR(&_50$$29);
								ZEPHIR_CONCAT_SVS(&_50$$29, " DEFAULT '", &_49$$29, "'");
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
								zephir_concat_self(&columnLine, &_50$$29);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						}
					}
					ZEPHIR_CALL_METHOD_CACHED(&_51$$24, &column, "isAutoIncrement", &_zephir_call_cache[30]);
					zephir_check_call_status();
					if (zephir_is_true(&_51$$24)) {
						zephir_concat_self_str(&columnLine, SL(" AUTO_INCREMENT"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
				ZEPHIR_CALL_METHOD_CACHED(&_52$$20, &column, "isPrimary", &_zephir_call_cache[31]);
				zephir_check_call_status();
				if (zephir_is_true(&_52$$20)) {
					zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_CALL_METHOD_CACHED(&_53$$20, &column, "getComment", &_zephir_call_cache[32]);
				zephir_check_call_status();
				if (zephir_is_true(&_53$$20)) {
					ZEPHIR_CALL_METHOD_CACHED(&_55$$32, &column, "getComment", &_zephir_call_cache[33]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_54$$32, this_ptr, "escapeStringLiteral", &_zephir_call_cache[34], &_55$$32);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_56$$32);
					ZEPHIR_CONCAT_SVS(&_56$$32, " COMMENT '", &_54$$32, "'");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&columnLine, &_56$$32);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_append(&createLines, &columnLine, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 277);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&column);
	zephir_memory_observe(&indexes);
	_57 = zephir_array_isset_string_fetch(&indexes, &definition, SL("indexes"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_57) {
		if (Z_TYPE_P(&indexes) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_59$$33);
			zephir_string_to_char_array(&_59$$33, &indexes);
			_58$$33 = &_59$$33;
		} else {
			_58$$33 = &indexes;
		}
		zephir_is_iterable(_58$$33, 0, "phalcon/Db/Dialect/Mysql.zep", 307);
		if (Z_TYPE_P(_58$$33) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_58$$33), _60$$33)
			{
				ZEPHIR_INIT_NVAR(&index);
				ZVAL_COPY(&index, _60$$33);
				ZEPHIR_CALL_METHOD_CACHED(&indexName, &index, "getName", &_zephir_call_cache[35]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&indexType, &index, "getType", &_zephir_call_cache[36]);
				zephir_check_call_status();
				if (ZEPHIR_IS_STRING(&indexName, "PRIMARY")) {
					ZEPHIR_CALL_METHOD_CACHED(&_61$$35, this_ptr, "getIndexColumnList", &_zephir_call_cache[37], &index);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_62$$35);
					ZEPHIR_CONCAT_SVS(&_62$$35, "PRIMARY KEY (", &_61$$35, ")");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_get_strval(&indexSql, &_62$$35);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					if (!(ZEPHIR_IS_EMPTY(&indexType))) {
						ZEPHIR_CALL_METHOD_CACHED(&_63$$37, this_ptr, "getIndexColumnList", &_zephir_call_cache[38], &index);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_64$$37);
						ZEPHIR_CONCAT_VSVSVS(&_64$$37, &indexType, " KEY `", &indexName, "` (", &_63$$37, ")");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_get_strval(&indexSql, &_64$$37);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CALL_METHOD_CACHED(&_65$$38, this_ptr, "getIndexColumnList", &_zephir_call_cache[39], &index);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_66$$38);
						ZEPHIR_CONCAT_SVSVS(&_66$$38, "KEY `", &indexName, "` (", &_65$$38, ")");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_get_strval(&indexSql, &_66$$38);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					ZEPHIR_CALL_METHOD_CACHED(&_67$$36, &index, "isInvisible", &_zephir_call_cache[40]);
					zephir_check_call_status();
					if (zephir_is_true(&_67$$36)) {
						zephir_concat_self_str(&indexSql, " INVISIBLE", sizeof(" INVISIBLE") - 1);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
				zephir_array_append(&createLines, &indexSql, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 305);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _58$$33, "rewind", &_zephir_call_cache[41]);
			zephir_check_call_status();
			_69$$33 = 1;
			while (1) {
				if (_69$$33) {
					_69$$33 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _58$$33, "next", &_zephir_call_cache[42]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_68$$33, _58$$33, "valid", &_zephir_call_cache[43]);
				zephir_check_call_status();
				if (!zend_is_true(&_68$$33)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&index, _58$$33, "current", &_zephir_call_cache[44]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&indexName, &index, "getName", &_zephir_call_cache[45]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&indexType, &index, "getType", &_zephir_call_cache[46]);
					zephir_check_call_status();
					if (ZEPHIR_IS_STRING(&indexName, "PRIMARY")) {
						ZEPHIR_CALL_METHOD_CACHED(&_70$$41, this_ptr, "getIndexColumnList", &_zephir_call_cache[47], &index);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_71$$41);
						ZEPHIR_CONCAT_SVS(&_71$$41, "PRIMARY KEY (", &_70$$41, ")");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_get_strval(&indexSql, &_71$$41);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						if (!(ZEPHIR_IS_EMPTY(&indexType))) {
							ZEPHIR_CALL_METHOD_CACHED(&_72$$43, this_ptr, "getIndexColumnList", &_zephir_call_cache[48], &index);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_73$$43);
							ZEPHIR_CONCAT_VSVSVS(&_73$$43, &indexType, " KEY `", &indexName, "` (", &_72$$43, ")");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_get_strval(&indexSql, &_73$$43);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							ZEPHIR_CALL_METHOD_CACHED(&_74$$44, this_ptr, "getIndexColumnList", &_zephir_call_cache[49], &index);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_75$$44);
							ZEPHIR_CONCAT_SVSVS(&_75$$44, "KEY `", &indexName, "` (", &_74$$44, ")");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_get_strval(&indexSql, &_75$$44);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						ZEPHIR_CALL_METHOD_CACHED(&_76$$42, &index, "isInvisible", &_zephir_call_cache[50]);
						zephir_check_call_status();
						if (zephir_is_true(&_76$$42)) {
							zephir_concat_self_str(&indexSql, " INVISIBLE", sizeof(" INVISIBLE") - 1);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
					zephir_array_append(&createLines, &indexSql, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 305);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&index);
	}
	zephir_memory_observe(&references);
	_77 = zephir_array_isset_string_fetch(&references, &definition, SL("references"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_77) {
		if (Z_TYPE_P(&references) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_79$$46);
			zephir_string_to_char_array(&_79$$46, &references);
			_78$$46 = &_79$$46;
		} else {
			_78$$46 = &references;
		}
		zephir_is_iterable(_78$$46, 0, "phalcon/Db/Dialect/Mysql.zep", 329);
		if (Z_TYPE_P(_78$$46) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_78$$46), _80$$46)
			{
				ZEPHIR_INIT_NVAR(&reference);
				ZVAL_COPY(&reference, _80$$46);
				ZEPHIR_CALL_METHOD_CACHED(&_81$$47, &reference, "getName", &_zephir_call_cache[51]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_83$$47, &reference, "getColumns", &_zephir_call_cache[52]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_82$$47, this_ptr, "getColumnList", &_zephir_call_cache[53], &_83$$47);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_85$$47, &reference, "getReferencedTable", &_zephir_call_cache[54]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_86$$47, &reference, "getReferencedSchema", &_zephir_call_cache[55]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_84$$47, this_ptr, "prepareTable", &_zephir_call_cache[56], &_85$$47, &_86$$47);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_88$$47, &reference, "getReferencedColumns", &_zephir_call_cache[57]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_87$$47, this_ptr, "getColumnList", &_zephir_call_cache[58], &_88$$47);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_89$$47);
				ZEPHIR_CONCAT_SVSVSSVSVS(&_89$$47, "CONSTRAINT `", &_81$$47, "` FOREIGN KEY (", &_82$$47, ")", " REFERENCES ", &_84$$47, " (", &_87$$47, ")");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_get_strval(&referenceSql, &_89$$47);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&onDelete, &reference, "getOnDelete", &_zephir_call_cache[59]);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
					ZEPHIR_INIT_NVAR(&_90$$48);
					ZEPHIR_CONCAT_SV(&_90$$48, " ON DELETE ", &onDelete);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&referenceSql, &_90$$48);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_CALL_METHOD_CACHED(&onUpdate, &reference, "getOnUpdate", &_zephir_call_cache[60]);
				zephir_check_call_status();
				if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
					ZEPHIR_INIT_NVAR(&_91$$49);
					ZEPHIR_CONCAT_SV(&_91$$49, " ON UPDATE ", &onUpdate);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&referenceSql, &_91$$49);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 327);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _78$$46, "rewind", &_zephir_call_cache[61]);
			zephir_check_call_status();
			_93$$46 = 1;
			while (1) {
				if (_93$$46) {
					_93$$46 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _78$$46, "next", &_zephir_call_cache[62]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_92$$46, _78$$46, "valid", &_zephir_call_cache[63]);
				zephir_check_call_status();
				if (!zend_is_true(&_92$$46)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&reference, _78$$46, "current", &_zephir_call_cache[64]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_94$$50, &reference, "getName", &_zephir_call_cache[65]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_96$$50, &reference, "getColumns", &_zephir_call_cache[66]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_95$$50, this_ptr, "getColumnList", &_zephir_call_cache[67], &_96$$50);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_98$$50, &reference, "getReferencedTable", &_zephir_call_cache[68]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_99$$50, &reference, "getReferencedSchema", &_zephir_call_cache[69]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_97$$50, this_ptr, "prepareTable", &_zephir_call_cache[70], &_98$$50, &_99$$50);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_101$$50, &reference, "getReferencedColumns", &_zephir_call_cache[71]);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_100$$50, this_ptr, "getColumnList", &_zephir_call_cache[72], &_101$$50);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_102$$50);
					ZEPHIR_CONCAT_SVSVSSVSVS(&_102$$50, "CONSTRAINT `", &_94$$50, "` FOREIGN KEY (", &_95$$50, ")", " REFERENCES ", &_97$$50, " (", &_100$$50, ")");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_get_strval(&referenceSql, &_102$$50);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CALL_METHOD_CACHED(&onDelete, &reference, "getOnDelete", &_zephir_call_cache[73]);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onDelete))) {
						ZEPHIR_INIT_NVAR(&_103$$51);
						ZEPHIR_CONCAT_SV(&_103$$51, " ON DELETE ", &onDelete);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&referenceSql, &_103$$51);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					ZEPHIR_CALL_METHOD_CACHED(&onUpdate, &reference, "getOnUpdate", &_zephir_call_cache[74]);
					zephir_check_call_status();
					if (!(ZEPHIR_IS_EMPTY(&onUpdate))) {
						ZEPHIR_INIT_NVAR(&_104$$52);
						ZEPHIR_CONCAT_SV(&_104$$52, " ON UPDATE ", &onUpdate);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&referenceSql, &_104$$52);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					zephir_array_append(&createLines, &referenceSql, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 327);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&reference);
	}
	zephir_memory_observe(&checks);
	_105 = zephir_array_isset_string_fetch(&checks, &definition, SL("checks"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_105) {
		if (Z_TYPE_P(&checks) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_107$$53);
			zephir_string_to_char_array(&_107$$53, &checks);
			_106$$53 = &_107$$53;
		} else {
			_106$$53 = &checks;
		}
		zephir_is_iterable(_106$$53, 0, "phalcon/Db/Dialect/Mysql.zep", 338);
		if (Z_TYPE_P(_106$$53) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_106$$53), _108$$53)
			{
				ZEPHIR_INIT_NVAR(&check);
				ZVAL_COPY(&check, _108$$53);
				ZEPHIR_INIT_NVAR(&_110$$54);
				ZVAL_STRING(&_110$$54, "`");
				ZEPHIR_CALL_METHOD_CACHED(&_109$$54, this_ptr, "getCheckClause", &_zephir_call_cache[75], &check, &_110$$54);
				zephir_check_call_status();
				zephir_array_append(&createLines, &_109$$54, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 336);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _106$$53, "rewind", &_zephir_call_cache[76]);
			zephir_check_call_status();
			_112$$53 = 1;
			while (1) {
				if (_112$$53) {
					_112$$53 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _106$$53, "next", &_zephir_call_cache[77]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_111$$53, _106$$53, "valid", &_zephir_call_cache[78]);
				zephir_check_call_status();
				if (!zend_is_true(&_111$$53)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&check, _106$$53, "current", &_zephir_call_cache[79]);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_114$$55);
					ZVAL_STRING(&_114$$55, "`");
					ZEPHIR_CALL_METHOD_CACHED(&_113$$55, this_ptr, "getCheckClause", &_zephir_call_cache[80], &check, &_114$$55);
					zephir_check_call_status();
					zephir_array_append(&createLines, &_113$$55, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 336);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&check);
	}
	ZEPHIR_INIT_VAR(&_115);
	zephir_fast_join_str(&_115, SL(",\n\t"), &createLines);
	ZEPHIR_INIT_VAR(&_116);
	ZEPHIR_CONCAT_VS(&_116, &_115, "\n)");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_concat_self(&sql, &_116);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_117 = zephir_array_isset_value_string(&definition, SL("options"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_117) {
		ZEPHIR_CALL_METHOD_CACHED(&_118$$56, this_ptr, "getTableOptions", &_zephir_call_cache[81], &definition);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_119$$56);
		ZEPHIR_CONCAT_SV(&_119$$56, " ", &_118$$56);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&sql, &_119$$56);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to create a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, createView)
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exceptions_missingdefinitionkey_ce, "sql", "phalcon/Db/Dialect/Mysql.zep", 357);
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeColumns)
{
	zval sql, schemaClause;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, _2, _3, _0$$3, _1$$3;
	zend_string *table = NULL, *schema = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&schemaClause);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
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
	if (!(ZEPHIR_IS_EMPTY(&schema_zv))) {
		ZEPHIR_CALL_METHOD_CACHED(&_0$$3, this_ptr, "escapeStringLiteral", &_zephir_call_cache[0], &schema_zv);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVS(&_1$$3, "'", &_0$$3, "'");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_get_strval(&schemaClause, &_1$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&schemaClause);
		ZVAL_STRING(&schemaClause, "DATABASE()");
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "escapeStringLiteral", &_zephir_call_cache[1], &table_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SSSSSSSSVSSVSS(&_3, "SELECT COLUMN_NAME AS `Field`, COLUMN_TYPE AS `Type`, ", "COLLATION_NAME AS `Collation`, IS_NULLABLE AS `Null`, ", "COLUMN_KEY AS `Key`, COLUMN_DEFAULT AS `Default`, ", "EXTRA AS `Extra`, PRIVILEGES AS `Privileges`, ", "COLUMN_COMMENT AS `Comment`, ", "GENERATION_EXPRESSION AS `GenerationExpression` ", "FROM `INFORMATION_SCHEMA`.`COLUMNS` ", "WHERE `TABLE_SCHEMA` = ", &schemaClause, " ", "AND `TABLE_NAME` = '", &_2, "' ", "ORDER BY `ORDINAL_POSITION`");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&sql, &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&sql);
}

/**
 * Generates SQL to query indexes on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeIndexes)
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "prepareTable", &_zephir_call_cache[0], &table_zv, &schema_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, "SHOW INDEXES FROM ", &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL to query foreign keys on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, describeReferences)
{
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, _0$$3, _1$$3, _2$$3, _3$$4, _4$$4;
	zend_string *table = NULL, *schema = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&sql);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
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
	ZVAL_STRING(&sql, "SELECT DISTINCT KCU.TABLE_NAME, KCU.COLUMN_NAME, KCU.CONSTRAINT_NAME, KCU.REFERENCED_TABLE_SCHEMA, KCU.REFERENCED_TABLE_NAME, KCU.REFERENCED_COLUMN_NAME, RC.UPDATE_RULE, RC.DELETE_RULE FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE AS KCU LEFT JOIN INFORMATION_SCHEMA.REFERENTIAL_CONSTRAINTS AS RC ON RC.CONSTRAINT_NAME = KCU.CONSTRAINT_NAME AND RC.CONSTRAINT_SCHEMA = KCU.CONSTRAINT_SCHEMA WHERE KCU.REFERENCED_TABLE_NAME IS NOT NULL AND ");
	if (!(ZEPHIR_IS_EMPTY(&schema_zv))) {
		ZEPHIR_CALL_METHOD_CACHED(&_0$$3, this_ptr, "escapeStringLiteral", &_zephir_call_cache[0], &schema_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "escapeStringLiteral", &_zephir_call_cache[1], &table_zv);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVSVS(&_2$$3, "KCU.CONSTRAINT_SCHEMA = '", &_0$$3, "' AND KCU.TABLE_NAME = '", &_1$$3, "'");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&sql, &_2$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD_CACHED(&_3$$4, this_ptr, "escapeStringLiteral", &_zephir_call_cache[2], &table_zv);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CONCAT_SVS(&_4$$4, "KCU.CONSTRAINT_SCHEMA = DATABASE() AND KCU.TABLE_NAME = '", &_3$$4, "'");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&sql, &_4$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP COLUMN `", &columnName_zv, "`");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL to delete a CHECK constraint from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropCheck)
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "prepareTable", &_zephir_call_cache[0], &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP CHECK `", &checkName_zv, "`");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL to delete a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropForeignKey)
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "prepareTable", &_zephir_call_cache[0], &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP FOREIGN KEY `", &referenceName_zv, "`");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL to delete an index from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropIndex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, indexName_zv, _0;
	zend_string *tableName = NULL, *schemaName = NULL, *indexName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&indexName_zv);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_STR(indexName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_memory_observe(&indexName_zv);
	ZVAL_STR_COPY(&indexName_zv, indexName);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "prepareTable", &_zephir_call_cache[0], &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "ALTER TABLE ", &_0, " DROP INDEX `", &indexName_zv, "`");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL to delete primary key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropPrimaryKey)
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "prepareTable", &_zephir_call_cache[0], &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "ALTER TABLE ", &_0, " DROP PRIMARY KEY");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
PHP_METHOD(Phalcon_Db_Dialect_Mysql, dropView)
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
 * Gets the column name in MySQL
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getColumnDefinition)
{
	zend_bool _43$$77;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *column, column_sub, columnType, columnSql, typeValues, _0$$3, _1$$3, _2$$3, _3$$5, _4$$11, _5$$15, _6$$17, _7$$18, _8$$18, _9$$18, _10$$20, _11$$20, _12$$20, _13$$22, _14$$24, _15$$24, _16$$24, _17$$26, _18$$26, _19$$26, _20$$36, _21$$36, _22$$36, _23$$40, _24$$40, _25$$40, _26$$44, _27$$46, _28$$47, _29$$49, _30$$52, _31$$52, _32$$52, _33$$56, _34$$75, _35$$75, _36$$75, value$$77, valueSql$$77, *_37$$77, _38$$77, *_39$$77, _42$$77, _46$$77, _47$$77, _48$$77, _49$$77, _40$$78, _41$$78, _44$$79, _45$$79, _50$$80, _51$$80;
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
	ZVAL_UNDEF(&_34$$75);
	ZVAL_UNDEF(&_35$$75);
	ZVAL_UNDEF(&_36$$75);
	ZVAL_UNDEF(&value$$77);
	ZVAL_UNDEF(&valueSql$$77);
	ZVAL_UNDEF(&_38$$77);
	ZVAL_UNDEF(&_42$$77);
	ZVAL_UNDEF(&_46$$77);
	ZVAL_UNDEF(&_47$$77);
	ZVAL_UNDEF(&_48$$77);
	ZVAL_UNDEF(&_49$$77);
	ZVAL_UNDEF(&_40$$78);
	ZVAL_UNDEF(&_41$$78);
	ZVAL_UNDEF(&_44$$79);
	ZVAL_UNDEF(&_45$$79);
	ZVAL_UNDEF(&_50$$80);
	ZVAL_UNDEF(&_51$$80);
	ZEND_TLS zephir_method_cache _zephir_call_cache[38];
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
	if (ZEPHIR_IS_LONG(&columnType, 19)) { goto zephir_switch_0_clause_1; }
	if (ZEPHIR_IS_LONG(&columnType, 11)) { goto zephir_switch_0_clause_2; }
	if (ZEPHIR_IS_LONG(&columnType, 8)) { goto zephir_switch_0_clause_3; }
	if (ZEPHIR_IS_LONG(&columnType, 5)) { goto zephir_switch_0_clause_4; }
	if (ZEPHIR_IS_LONG(&columnType, 1)) { goto zephir_switch_0_clause_5; }
	if (ZEPHIR_IS_LONG(&columnType, 4)) { goto zephir_switch_0_clause_6; }
	if (ZEPHIR_IS_LONG(&columnType, 3)) { goto zephir_switch_0_clause_7; }
	if (ZEPHIR_IS_LONG(&columnType, 9)) { goto zephir_switch_0_clause_8; }
	if (ZEPHIR_IS_LONG(&columnType, 18)) { goto zephir_switch_0_clause_9; }
	if (ZEPHIR_IS_LONG(&columnType, 7)) { goto zephir_switch_0_clause_10; }
	if (ZEPHIR_IS_LONG(&columnType, 0)) { goto zephir_switch_0_clause_11; }
	if (ZEPHIR_IS_LONG(&columnType, 15)) { goto zephir_switch_0_clause_12; }
	if (ZEPHIR_IS_LONG(&columnType, 13)) { goto zephir_switch_0_clause_13; }
	if (ZEPHIR_IS_LONG(&columnType, 24)) { goto zephir_switch_0_clause_14; }
	if (ZEPHIR_IS_LONG(&columnType, 12)) { goto zephir_switch_0_clause_15; }
	if (ZEPHIR_IS_LONG(&columnType, 21)) { goto zephir_switch_0_clause_16; }
	if (ZEPHIR_IS_LONG(&columnType, 23)) { goto zephir_switch_0_clause_17; }
	if (ZEPHIR_IS_LONG(&columnType, 22)) { goto zephir_switch_0_clause_18; }
	if (ZEPHIR_IS_LONG(&columnType, 6)) { goto zephir_switch_0_clause_19; }
	if (ZEPHIR_IS_LONG(&columnType, 20)) { goto zephir_switch_0_clause_20; }
	if (ZEPHIR_IS_LONG(&columnType, 17)) { goto zephir_switch_0_clause_21; }
	if (ZEPHIR_IS_LONG(&columnType, 10)) { goto zephir_switch_0_clause_22; }
	if (ZEPHIR_IS_LONG(&columnType, 26)) { goto zephir_switch_0_clause_23; }
	if (ZEPHIR_IS_LONG(&columnType, 25)) { goto zephir_switch_0_clause_24; }
	if (ZEPHIR_IS_LONG(&columnType, 2)) { goto zephir_switch_0_clause_25; }
	if (ZEPHIR_IS_LONG(&columnType, 40)) { goto zephir_switch_0_clause_26; }
	if (ZEPHIR_IS_LONG(&columnType, 41)) { goto zephir_switch_0_clause_27; }
	if (ZEPHIR_IS_LONG(&columnType, 42)) { goto zephir_switch_0_clause_28; }
	if (ZEPHIR_IS_LONG(&columnType, 43)) { goto zephir_switch_0_clause_29; }
	if (ZEPHIR_IS_LONG(&columnType, 44)) { goto zephir_switch_0_clause_30; }
	if (ZEPHIR_IS_LONG(&columnType, 45)) { goto zephir_switch_0_clause_31; }
	if (ZEPHIR_IS_LONG(&columnType, 46)) { goto zephir_switch_0_clause_32; }
	if (ZEPHIR_IS_LONG(&columnType, 47)) { goto zephir_switch_0_clause_33; }
	goto zephir_switch_0_clause_34;
	zephir_switch_0_clause_0: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("BIGINT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_0$$3, this_ptr, "getColumnSize", &_zephir_call_cache[2], column);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "checkColumnUnsigned", &_zephir_call_cache[3], column);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_VV(&_2$$3, &_0$$3, &_1$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&columnSql, &_2$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_1: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("BIT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_3$$5, this_ptr, "getColumnSize", &_zephir_call_cache[4], column);
		zephir_check_call_status();
		zephir_concat_self(&columnSql, &_3$$5);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_2: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("BLOB"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_3: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("TINYINT(1)"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_4: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("CHAR"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_4$$11, this_ptr, "getColumnSize", &_zephir_call_cache[5], column);
		zephir_check_call_status();
		zephir_concat_self(&columnSql, &_4$$11);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_5: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("DATE"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_6: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("DATETIME"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_5$$15, column, "getSize", &_zephir_call_cache[6]);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(&_5$$15, 0)) {
			ZEPHIR_CALL_METHOD_CACHED(&_6$$17, this_ptr, "getColumnSize", &_zephir_call_cache[7], column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_6$$17);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_7: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("DECIMAL"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_7$$18, this_ptr, "getColumnSizeAndScale", &_zephir_call_cache[8], column);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_8$$18, this_ptr, "checkColumnUnsigned", &_zephir_call_cache[9], column);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$18);
		ZEPHIR_CONCAT_VV(&_9$$18, &_7$$18, &_8$$18);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&columnSql, &_9$$18);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_8: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("DOUBLE"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_10$$20, this_ptr, "checkColumnSizeAndScale", &_zephir_call_cache[10], column);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_11$$20, this_ptr, "checkColumnUnsigned", &_zephir_call_cache[11], column);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_12$$20);
		ZEPHIR_CONCAT_VV(&_12$$20, &_10$$20, &_11$$20);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&columnSql, &_12$$20);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_9: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("ENUM"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_13$$22, this_ptr, "getColumnSize", &_zephir_call_cache[12], column);
		zephir_check_call_status();
		zephir_concat_self(&columnSql, &_13$$22);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_10: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("FLOAT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_14$$24, this_ptr, "checkColumnSizeAndScale", &_zephir_call_cache[13], column);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_15$$24, this_ptr, "checkColumnUnsigned", &_zephir_call_cache[14], column);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_16$$24);
		ZEPHIR_CONCAT_VV(&_16$$24, &_14$$24, &_15$$24);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&columnSql, &_16$$24);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_11: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("INT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_17$$26, this_ptr, "getColumnSize", &_zephir_call_cache[15], column);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_18$$26, this_ptr, "checkColumnUnsigned", &_zephir_call_cache[16], column);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_19$$26);
		ZEPHIR_CONCAT_VV(&_19$$26, &_17$$26, &_18$$26);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&columnSql, &_19$$26);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_12: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("JSON"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_13: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("LONGBLOB"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_14: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("LONGTEXT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_15: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("MEDIUMBLOB"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_16: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("MEDIUMINT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_20$$36, this_ptr, "getColumnSize", &_zephir_call_cache[17], column);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_21$$36, this_ptr, "checkColumnUnsigned", &_zephir_call_cache[18], column);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_22$$36);
		ZEPHIR_CONCAT_VV(&_22$$36, &_20$$36, &_21$$36);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&columnSql, &_22$$36);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_17: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("MEDIUMTEXT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_18: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("SMALLINT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_23$$40, this_ptr, "getColumnSize", &_zephir_call_cache[19], column);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_24$$40, this_ptr, "checkColumnUnsigned", &_zephir_call_cache[20], column);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_25$$40);
		ZEPHIR_CONCAT_VV(&_25$$40, &_23$$40, &_24$$40);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&columnSql, &_25$$40);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_19: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("TEXT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_20: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("TIME"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_26$$44, column, "getSize", &_zephir_call_cache[21]);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(&_26$$44, 0)) {
			ZEPHIR_CALL_METHOD_CACHED(&_27$$46, this_ptr, "getColumnSize", &_zephir_call_cache[22], column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_27$$46);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_21: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("TIMESTAMP"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_28$$47, column, "getSize", &_zephir_call_cache[23]);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(&_28$$47, 0)) {
			ZEPHIR_CALL_METHOD_CACHED(&_29$$49, this_ptr, "getColumnSize", &_zephir_call_cache[24], column);
			zephir_check_call_status();
			zephir_concat_self(&columnSql, &_29$$49);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_22: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("TINYBLOB"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_23: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("TINYINT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_30$$52, this_ptr, "getColumnSize", &_zephir_call_cache[25], column);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_31$$52, this_ptr, "checkColumnUnsigned", &_zephir_call_cache[26], column);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_32$$52);
		ZEPHIR_CONCAT_VV(&_32$$52, &_30$$52, &_31$$52);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&columnSql, &_32$$52);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_24: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("TINYTEXT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_25: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("VARCHAR"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_33$$56, this_ptr, "getColumnSize", &_zephir_call_cache[27], column);
		zephir_check_call_status();
		zephir_concat_self(&columnSql, &_33$$56);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_26: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("GEOMETRY"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_27: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("POINT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_28: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("LINESTRING"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_29: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("POLYGON"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_30: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("MULTIPOINT"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_31: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("MULTILINESTRING"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_32: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("MULTIPOLYGON"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_33: ;
		if (ZEPHIR_IS_EMPTY(&columnSql)) {
			zephir_concat_self_str(&columnSql, SL("GEOMETRYCOLLECTION"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		goto zephir_switch_0_end;
	zephir_switch_0_clause_34: ;
		if (UNEXPECTED(ZEPHIR_IS_EMPTY(&columnSql))) {
			ZEPHIR_INIT_VAR(&_34$$75);
			object_init_ex(&_34$$75, phalcon_db_exceptions_unrecognizeddatatype_ce);
			ZEPHIR_CALL_METHOD_CACHED(&_35$$75, column, "getName", &_zephir_call_cache[28]);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_36$$75);
			ZVAL_STRING(&_36$$75, "MySQL");
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_34$$75, "__construct", &_zephir_call_cache[29], &_36$$75, &_35$$75);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_34$$75, "phalcon/Db/Dialect/Mysql.zep", 793);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&typeValues, column, "getTypeValues", &_zephir_call_cache[30]);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&typeValues))) {
			if (Z_TYPE_P(&typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(&valueSql$$77);
				ZVAL_STRING(&valueSql$$77, "");
				if (Z_TYPE_P(&typeValues) == IS_STRING) {
					ZEPHIR_INIT_VAR(&_38$$77);
					zephir_string_to_char_array(&_38$$77, &typeValues);
					_37$$77 = &_38$$77;
				} else {
					_37$$77 = &typeValues;
				}
				zephir_is_iterable(_37$$77, 0, "phalcon/Db/Dialect/Mysql.zep", 807);
				if (Z_TYPE_P(_37$$77) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_37$$77), _39$$77)
					{
						ZEPHIR_INIT_NVAR(&value$$77);
						ZVAL_COPY(&value$$77, _39$$77);
						ZEPHIR_CALL_METHOD_CACHED(&_40$$78, this_ptr, "escapeStringLiteral", &_zephir_call_cache[31], &value$$77);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_41$$78);
						ZEPHIR_CONCAT_SVS(&_41$$78, "'", &_40$$78, "', ");
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_concat_self(&valueSql$$77, &_41$$78);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _37$$77, "rewind", &_zephir_call_cache[32]);
					zephir_check_call_status();
					_43$$77 = 1;
					while (1) {
						if (_43$$77) {
							_43$$77 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _37$$77, "next", &_zephir_call_cache[33]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_42$$77, _37$$77, "valid", &_zephir_call_cache[34]);
						zephir_check_call_status();
						if (!zend_is_true(&_42$$77)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&value$$77, _37$$77, "current", &_zephir_call_cache[35]);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD_CACHED(&_44$$79, this_ptr, "escapeStringLiteral", &_zephir_call_cache[36], &value$$77);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_45$$79);
							ZEPHIR_CONCAT_SVS(&_45$$79, "'", &_44$$79, "', ");
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_concat_self(&valueSql$$77, &_45$$79);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&value$$77);
				ZVAL_LONG(&_46$$77, 0);
				ZVAL_LONG(&_47$$77, -2);
				ZEPHIR_INIT_VAR(&_48$$77);
				zephir_substr(&_48$$77, &valueSql$$77, 0 , -2 , 0);
				ZEPHIR_INIT_VAR(&_49$$77);
				ZEPHIR_CONCAT_SVS(&_49$$77, "(", &_48$$77, ")");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&columnSql, &_49$$77);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CALL_METHOD_CACHED(&_50$$80, this_ptr, "escapeStringLiteral", &_zephir_call_cache[37], &typeValues);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_51$$80);
				ZEPHIR_CONCAT_SVS(&_51$$80, "('", &_50$$80, "')");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&columnSql, &_51$$80);
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
 * Generates SQL to check DB parameter FOREIGN_KEY_CHECKS.
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getForeignKeyChecks)
{

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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval schemaName_zv, _0$$3;
	zend_string *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (!(ZEPHIR_IS_EMPTY(&schemaName_zv))) {
		ZEPHIR_CALL_METHOD_CACHED(&_0$$3, this_ptr, "escape", &_zephir_call_cache[0], &schemaName_zv);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SV(return_value, "SHOW TABLES FROM ", &_0$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval schemaName_zv, _0$$3;
	zend_string *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
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
	if (!(ZEPHIR_IS_EMPTY(&schemaName_zv))) {
		ZEPHIR_CALL_METHOD_CACHED(&_0$$3, this_ptr, "escapeStringLiteral", &_zephir_call_cache[0], &schemaName_zv);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = '", &_0$$3, "' ORDER BY view_name");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	RETURN_MM_STRING("SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = DATABASE() ORDER BY view_name");
}

/**
 * Generates SQL to modify a column in a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, modifyColumn)
{
	zend_bool _15$$10, _18$$12, _19$$12, _20$$12;
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, afterPosition, defaultValue, upperDefaultValue, columnDefinition, _0, _1, _2, _3, _4, _5, _11, _12, _13, _26, _30, _6$$4, _7$$4, _8$$4, _9$$5, _10$$5, _14$$9, _25$$9, _16$$11, _17$$11, _21$$12, _22$$13, _23$$14, _24$$14, _27$$16, _28$$16, _29$$16, _31$$19;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&sql);
	ZEND_TLS zephir_method_cache _zephir_call_cache[21];
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
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getColumnDefinition", &_zephir_call_cache[0], column);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "getGeneratedClause", &_zephir_call_cache[1], column);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&columnDefinition);
	ZEPHIR_CONCAT_VV(&columnDefinition, &_0, &_1);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "prepareTable", &_zephir_call_cache[2], &tableName_zv, &schemaName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SV(&_3, "ALTER TABLE ", &_2);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_get_strval(&sql, &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(currentColumn) != IS_OBJECT) {
		ZEPHIR_CPY_WRT(currentColumn, column);
	}
	ZEPHIR_CALL_METHOD_CACHED(&_4, column, "getName", &_zephir_call_cache[3]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_5, currentColumn, "getName", &_zephir_call_cache[4]);
	zephir_check_call_status();
	if (!ZEPHIR_IS_IDENTICAL(&_4, &_5)) {
		ZEPHIR_CALL_METHOD_CACHED(&_6$$4, currentColumn, "getName", &_zephir_call_cache[5]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_7$$4, column, "getName", &_zephir_call_cache[6]);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$4);
		ZEPHIR_CONCAT_SVSVSV(&_8$$4, " CHANGE COLUMN `", &_6$$4, "` `", &_7$$4, "` ", &columnDefinition);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&sql, &_8$$4);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD_CACHED(&_9$$5, column, "getName", &_zephir_call_cache[7]);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$5);
		ZEPHIR_CONCAT_SVSV(&_10$$5, " MODIFY `", &_9$$5, "` ", &columnDefinition);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&sql, &_10$$5);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_11, column, "isNotNull", &_zephir_call_cache[8]);
	zephir_check_call_status();
	if (zephir_is_true(&_11)) {
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
	ZEPHIR_CALL_METHOD_CACHED(&_12, column, "isInvisible", &_zephir_call_cache[9]);
	zephir_check_call_status();
	if (zephir_is_true(&_12)) {
		zephir_concat_self_str(&sql, " INVISIBLE", sizeof(" INVISIBLE") - 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_13, column, "isGenerated", &_zephir_call_cache[10]);
	zephir_check_call_status();
	if (!(zephir_is_true(&_13))) {
		ZEPHIR_CALL_METHOD_CACHED(&_14$$9, column, "hasDefault", &_zephir_call_cache[11]);
		zephir_check_call_status();
		if (zephir_is_true(&_14$$9)) {
			ZEPHIR_CALL_METHOD_CACHED(&defaultValue, column, "getDefault", &_zephir_call_cache[12]);
			zephir_check_call_status();
			_15$$10 = Z_TYPE_P(&defaultValue) == IS_OBJECT;
			if (_15$$10) {
				_15$$10 = zephir_instance_of_ev(&defaultValue, phalcon_db_rawvalue_ce);
			}
			if (_15$$10) {
				ZEPHIR_CALL_METHOD_CACHED(&_16$$11, &defaultValue, "getValue", &_zephir_call_cache[13]);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_17$$11);
				ZEPHIR_CONCAT_SV(&_17$$11, " DEFAULT ", &_16$$11);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_concat_self(&sql, &_17$$11);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_INIT_VAR(&upperDefaultValue);
				zephir_fast_strtoupper(&upperDefaultValue, &defaultValue);
				_18$$12 = zephir_memnstr_str(&upperDefaultValue, SL("CURRENT_TIMESTAMP"), "phalcon/Db/Dialect/Mysql.zep", 899);
				if (!(_18$$12)) {
					_18$$12 = zephir_memnstr_str(&upperDefaultValue, SL("NULL"), "phalcon/Db/Dialect/Mysql.zep", 899);
				}
				_19$$12 = _18$$12;
				if (!(_19$$12)) {
					_19$$12 = (Z_TYPE_P(&defaultValue) == IS_LONG);
				}
				_20$$12 = _19$$12;
				if (!(_20$$12)) {
					ZEPHIR_CALL_FUNCTION(&_21$$12, "is_float", NULL, 19, &defaultValue);
					zephir_check_call_status();
					_20$$12 = zephir_is_true(&_21$$12);
				}
				if (_20$$12) {
					ZEPHIR_INIT_VAR(&_22$$13);
					ZEPHIR_CONCAT_SV(&_22$$13, " DEFAULT ", &defaultValue);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&sql, &_22$$13);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CALL_METHOD_CACHED(&_23$$14, this_ptr, "escapeStringLiteral", &_zephir_call_cache[14], &defaultValue);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(&_24$$14);
					ZEPHIR_CONCAT_SVS(&_24$$14, " DEFAULT '", &_23$$14, "'");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_concat_self(&sql, &_24$$14);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&_25$$9, column, "isAutoIncrement", &_zephir_call_cache[15]);
		zephir_check_call_status();
		if (zephir_is_true(&_25$$9)) {
			zephir_concat_self_str(&sql, " AUTO_INCREMENT", sizeof(" AUTO_INCREMENT") - 1);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_26, column, "getComment", &_zephir_call_cache[16]);
	zephir_check_call_status();
	if (zephir_is_true(&_26)) {
		ZEPHIR_CALL_METHOD_CACHED(&_28$$16, column, "getComment", &_zephir_call_cache[17]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_27$$16, this_ptr, "escapeStringLiteral", &_zephir_call_cache[18], &_28$$16);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_29$$16);
		ZEPHIR_CONCAT_SVS(&_29$$16, " COMMENT '", &_27$$16, "'");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&sql, &_29$$16);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_30, column, "isFirst", &_zephir_call_cache[19]);
	zephir_check_call_status();
	if (zephir_is_true(&_30)) {
		zephir_concat_self_str(&sql, " FIRST", sizeof(" FIRST") - 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD_CACHED(&afterPosition, column, "getAfterPosition", &_zephir_call_cache[20]);
		zephir_check_call_status();
		if (zephir_is_true(&afterPosition)) {
			ZEPHIR_INIT_VAR(&_31$$19);
			ZEPHIR_CONCAT_SVS(&_31$$19, " AFTER `", &afterPosition, "`");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_concat_self(&sql, &_31$$19);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	RETURN_CTOR(&sql);
}

/**
 * MySQL does not support the SQL-standard `ON CONFLICT DO UPDATE`
 * upsert syntax - it has its own `INSERT ... ON DUPLICATE KEY UPDATE`
 * which requires PHQL grammar work (deferred). The base helper is
 * overridden here to throw, preventing accidental emission of invalid
 * SQL on MySQL connections.
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, onConflictUpdate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval conflictColumns, updateColumns;
	zval sqlQuery_zv, *conflictColumns_param = NULL, *updateColumns_param = NULL, _0;
	zend_string *sqlQuery = NULL;

	ZVAL_UNDEF(&sqlQuery_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&conflictColumns);
	ZVAL_UNDEF(&updateColumns);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(sqlQuery)
		ZEPHIR_Z_PARAM_ARRAY(conflictColumns, conflictColumns_param)
		ZEPHIR_Z_PARAM_ARRAY(updateColumns, updateColumns_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	conflictColumns_param = ZEND_CALL_ARG(execute_data, 2);
	updateColumns_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&sqlQuery_zv);
	ZVAL_STR_COPY(&sqlQuery_zv, sqlQuery);
	zephir_get_arrval(&conflictColumns, conflictColumns_param);
	zephir_get_arrval(&updateColumns, updateColumns_param);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_db_exceptions_mysqlonconflictnotsupported_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &_0, "__construct", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Db/Dialect/Mysql.zep", 941);
	ZEPHIR_MM_RESTORE();
	return;
}

/**
 * MySQL does not support the SQL-standard `ON CONFLICT (...) DO UPDATE`
 * upsert clause; `onConflictUpdate()` throws.
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, supportsOnConflictUpdate)
{

	RETURN_BOOL(0);
}

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause. The `modifier`
 * argument is accepted for signature parity with the contract but is
 * silently ignored on MySQL - its legacy `LOCK IN SHARE MODE` syntax has
 * no `NOWAIT` / `SKIP LOCKED` variant. Callers needing those modifiers
 * should target PostgreSQL or stay on `forUpdate()`.
 *
 *```php
 * $sql = $dialect->sharedLock("SELECT * FROM co_invoices");
 *
 * echo $sql; // SELECT * FROM co_invoices LOCK IN SHARE MODE
 *```
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, sharedLock)
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
	ZEPHIR_CONCAT_VS(return_value, &sqlQuery_zv, " LOCK IN SHARE MODE");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
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
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, _0$$3, _1$$3, _2;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
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
	if (!(ZEPHIR_IS_EMPTY(&schemaName_zv))) {
		ZEPHIR_CALL_METHOD_CACHED(&_0$$3, this_ptr, "escapeStringLiteral", &_zephir_call_cache[0], &tableName_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "escapeStringLiteral", &_zephir_call_cache[1], &schemaName_zv);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", &_0$$3, "' AND `TABLE_SCHEMA` = '", &_1$$3, "'");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "escapeStringLiteral", &_zephir_call_cache[2], &tableName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME` = '", &_2, "' AND `TABLE_SCHEMA` = DATABASE()");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates the SQL to describe the table creation options
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, tableOptions)
{
	zval sql;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, _2, _0$$3, _1$$3;
	zend_string *table = NULL, *schema = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&sql);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
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
	ZEPHIR_CONCAT_SSS(&sql, "SELECT TABLES.TABLE_TYPE AS table_type,TABLES.AUTO_INCREMENT AS auto_increment,", "TABLES.ENGINE AS engine,TABLES.TABLE_COLLATION AS table_collation,", "TABLES.TABLE_COMMENT AS table_comment FROM INFORMATION_SCHEMA.TABLES WHERE ");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(ZEPHIR_IS_EMPTY(&schema_zv))) {
		ZEPHIR_CALL_METHOD_CACHED(&_0$$3, this_ptr, "escapeStringLiteral", &_zephir_call_cache[0], &schema_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "escapeStringLiteral", &_zephir_call_cache[1], &table_zv);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSVSVS(return_value, &sql, "TABLES.TABLE_SCHEMA = '", &_0$$3, "' AND TABLES.TABLE_NAME = '", &_1$$3, "'");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "escapeStringLiteral", &_zephir_call_cache[2], &table_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVS(return_value, &sql, "TABLES.TABLE_SCHEMA = DATABASE() AND TABLES.TABLE_NAME = '", &_2, "'");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL to truncate a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, truncateTable)
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
		ZEPHIR_CONCAT_SVSVS(&table, "`", &schemaName_zv, "`.`", &tableName_zv, "`");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&table);
		ZEPHIR_CONCAT_SVS(&table, "`", &tableName_zv, "`");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CONCAT_SV(return_value, "TRUNCATE TABLE ", &table);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Generates SQL checking for the existence of a schema.view
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, viewExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval viewName_zv, schemaName_zv, _0$$3, _1$$3, _2;
	zend_string *viewName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
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
	if (!(ZEPHIR_IS_EMPTY(&schemaName_zv))) {
		ZEPHIR_CALL_METHOD_CACHED(&_0$$3, this_ptr, "escapeStringLiteral", &_zephir_call_cache[0], &viewName_zv);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "escapeStringLiteral", &_zephir_call_cache[1], &schemaName_zv);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`= '", &_0$$3, "' AND `TABLE_SCHEMA`='", &_1$$3, "'");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "escapeStringLiteral", &_zephir_call_cache[2], &viewName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`='", &_2, "' AND `TABLE_SCHEMA` = DATABASE()");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Escape a string literal for a single quoted SQL string. MySQL treats the
 * backslash as an escape character, so it must be doubled together with the
 * single quote.
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, escapeStringLiteral)
{
	zval _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval value_zv, _1;
	zend_string *value = NULL;

	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\\");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "'");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "\\\\");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "''");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_fast_str_replace(&_1, &_0, &_2, &value_zv);
	RETURN_CCTOR(&_1);
}

/**
 * Generates SQL to add the table creation options. The caller emits the
 * clause only when the definition carries the options, so the shape
 * below is narrower than `db_table_definition`.
 *
 * @phpstan-param array{options: db_table_options} $definition
 */
PHP_METHOD(Phalcon_Db_Dialect_Mysql, getTableOptions)
{
	zend_bool _0, _1, _3, _5, _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *definition_param = NULL, options, engine, autoIncrement, tableCollation, collationParts, tableComment, _2$$5, _4$$7, _6$$9, _7$$9, _8$$9, _10$$11, _11$$11, _12$$11, _13$$11;
	zval definition, tableOptions;

	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&tableOptions);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&engine);
	ZVAL_UNDEF(&autoIncrement);
	ZVAL_UNDEF(&tableCollation);
	ZVAL_UNDEF(&collationParts);
	ZVAL_UNDEF(&tableComment);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(definition, definition_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &definition_param);
	zephir_get_arrval(&definition, definition_param);
	zephir_memory_observe(&options);
	_0 = zephir_array_isset_string_fetch(&options, &definition, SL("options"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_INIT_VAR(&tableOptions);
	array_init(&tableOptions);
	zephir_memory_observe(&engine);
	_1 = zephir_array_isset_string_fetch(&engine, &options, SL("ENGINE"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		if (zephir_is_true(&engine)) {
			ZEPHIR_INIT_VAR(&_2$$5);
			ZEPHIR_CONCAT_SV(&_2$$5, "ENGINE=", &engine);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&tableOptions, &_2$$5, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 1076);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_memory_observe(&autoIncrement);
	_3 = zephir_array_isset_string_fetch(&autoIncrement, &options, SL("AUTO_INCREMENT"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_3) {
		if (zephir_is_true(&autoIncrement)) {
			ZEPHIR_INIT_VAR(&_4$$7);
			ZEPHIR_CONCAT_SV(&_4$$7, "AUTO_INCREMENT=", &autoIncrement);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&tableOptions, &_4$$7, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 1085);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_memory_observe(&tableCollation);
	_5 = zephir_array_isset_string_fetch(&tableCollation, &options, SL("TABLE_COLLATION"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_5) {
		if (zephir_is_true(&tableCollation)) {
			ZEPHIR_INIT_VAR(&collationParts);
			zephir_fast_explode_str(&collationParts, SL("_"), &tableCollation, NULL);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_memory_observe(&_6$$9);
			zephir_array_fetch_long(&_6$$9, &collationParts, 0, PH_NOISY, "phalcon/Db/Dialect/Mysql.zep", 1095);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_7$$9);
			ZEPHIR_CONCAT_SV(&_7$$9, "DEFAULT CHARSET=", &_6$$9);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&tableOptions, &_7$$9, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 1095);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_8$$9);
			ZEPHIR_CONCAT_SV(&_8$$9, "COLLATE=", &tableCollation);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&tableOptions, &_8$$9, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 1096);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	zephir_memory_observe(&tableComment);
	_9 = zephir_array_isset_string_fetch(&tableComment, &options, SL("TABLE_COMMENT"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_9) {
		if (zephir_is_true(&tableComment)) {
			ZEPHIR_INIT_VAR(&_10$$11);
			ZEPHIR_INIT_VAR(&_11$$11);
			ZVAL_STRING(&_11$$11, "'");
			ZEPHIR_INIT_VAR(&_12$$11);
			ZVAL_STRING(&_12$$11, "''");
			zephir_fast_str_replace(&_10$$11, &_11$$11, &_12$$11, &tableComment);
			ZEPHIR_INIT_VAR(&_13$$11);
			ZEPHIR_CONCAT_SVS(&_13$$11, "COMMENT='", &_10$$11, "'");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&tableOptions, &_13$$11, PH_SEPARATE, "phalcon/Db/Dialect/Mysql.zep", 1105);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&columnSql);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &column);
	ZEPHIR_INIT_VAR(&columnSql);
	ZVAL_STRING(&columnSql, "");
	ZEPHIR_CALL_METHOD_CACHED(&_0, column, "getSize", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, column, "getSize", &_zephir_call_cache[1]);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "(", &_1$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&columnSql, &_2$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_3$$3, column, "getScale", &_zephir_call_cache[2]);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$3)) {
			ZEPHIR_CALL_METHOD_CACHED(&_4$$4, column, "getScale", &_zephir_call_cache[3]);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_5$$4);
			ZEPHIR_CONCAT_SVS(&_5$$4, ",", &_4$$4, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_concat_self(&columnSql, &_5$$4);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			zephir_concat_self_str(&columnSql, ")", sizeof(")") - 1);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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

	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &column);
	ZEPHIR_CALL_METHOD_CACHED(&_0, column, "isUnsigned", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_STRING(" UNSIGNED");
	}
	RETURN_MM_STRING("");
}

zend_object *zephir_init_properties_Phalcon_Db_Dialect_Mysql(zend_class_entry *class_type)
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
			zephir_create_array(&_6$$5, 2, 0);
			ZEPHIR_INIT_VAR(&_7$$5);
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

