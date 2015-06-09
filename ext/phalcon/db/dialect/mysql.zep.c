
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


/**
 * Phalcon\Db\Dialect\Mysql
 *
 * Generates database specific SQL for the MySQL RDBMS
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_MySQL) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, MySQL, phalcon, db_dialect_mysql, phalcon_db_dialect_ce, phalcon_db_dialect_mysql_method_entry, 0);

	zend_declare_property_string(phalcon_db_dialect_mysql_ce, SL("_escapeChar"), "`", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Gets the column name in MySQL
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, getColumnDefinition) {

	zephir_fcall_cache_entry *_9 = NULL;
	HashTable *_6;
	HashPosition _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *column, *columnSql, *size = NULL, *scale = NULL, *type = NULL, *typeValues = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *value = NULL, *valueSql, **_7, _8 = zval_used_for_init, _10 = zval_used_for_init, *_11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_INIT_VAR(columnSql);
	ZVAL_STRING(columnSql, "", 1);
	ZEPHIR_CALL_METHOD(&type, column, "gettype", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(type) == IS_STRING) {
		zephir_concat_self(&columnSql, type TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&type, column, "gettypereference", NULL, 0);
		zephir_check_call_status();
	}
	do {
		if (ZEPHIR_IS_LONG(type, 0)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("INT") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_0, column, "getsize", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_1);
			ZEPHIR_CONCAT_SVS(_1, "(", _0, ")");
			zephir_concat_self(&columnSql, _1 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_2, column, "isunsigned", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(_2)) {
				zephir_concat_self_str(&columnSql, SL(" UNSIGNED") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 1)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DATE") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 2)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("VARCHAR") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_0, column, "getsize", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_1);
			ZEPHIR_CONCAT_SVS(_1, "(", _0, ")");
			zephir_concat_self(&columnSql, _1 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 3)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DECIMAL") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_0, column, "getsize", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_2, column, "getscale", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_1);
			ZEPHIR_CONCAT_SVSVS(_1, "(", _0, ",", _2, ")");
			zephir_concat_self(&columnSql, _1 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3, column, "isunsigned", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(_3)) {
				zephir_concat_self_str(&columnSql, SL(" UNSIGNED") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 4)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("DATETIME") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 5)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("CHAR") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_0, column, "getsize", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_1);
			ZEPHIR_CONCAT_SVS(_1, "(", _0, ")");
			zephir_concat_self(&columnSql, _1 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 6)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TEXT") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 7)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("FLOAT") TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&size, column, "getsize", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(size)) {
				ZEPHIR_CALL_METHOD(&scale, column, "getscale", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_1);
				ZEPHIR_CONCAT_SV(_1, "(", size);
				zephir_concat_self(&columnSql, _1 TSRMLS_CC);
				if (zephir_is_true(scale)) {
					ZEPHIR_INIT_VAR(_4);
					ZEPHIR_CONCAT_SVS(_4, ",", scale, ")");
					zephir_concat_self(&columnSql, _4 TSRMLS_CC);
				} else {
					zephir_concat_self_str(&columnSql, SL(")") TSRMLS_CC);
				}
			}
			ZEPHIR_CALL_METHOD(&_0, column, "isunsigned", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(_0)) {
				zephir_concat_self_str(&columnSql, SL(" UNSIGNED") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_LONG(type, 8)) {
			if (ZEPHIR_IS_EMPTY(columnSql)) {
				zephir_concat_self_str(&columnSql, SL("TINYINT(1)") TSRMLS_CC);
			}
			break;
		}
		if (ZEPHIR_IS_EMPTY(columnSql)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Unrecognized MySQL data type", "phalcon/db/dialect/mysql.zep", 136);
			return;
		}
		ZEPHIR_CALL_METHOD(&typeValues, column, "gettypevalues", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(typeValues))) {
			if (Z_TYPE_P(typeValues) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(valueSql);
				ZVAL_STRING(valueSql, "", 1);
				zephir_is_iterable(typeValues, &_6, &_5, 0, 0, "phalcon/db/dialect/mysql.zep", 147);
				for (
				  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
				  ; zephir_hash_move_forward_ex(_6, &_5)
				) {
					ZEPHIR_GET_HVALUE(value, _7);
					ZEPHIR_SINIT_NVAR(_8);
					ZVAL_STRING(&_8, "\"", 0);
					ZEPHIR_CALL_FUNCTION(&_0, "addcslashes", &_9, 109, value, &_8);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_1);
					ZEPHIR_CONCAT_SVS(_1, "\"", _0, "\", ");
					zephir_concat_self(&valueSql, _1 TSRMLS_CC);
				}
				ZEPHIR_SINIT_NVAR(_8);
				ZVAL_LONG(&_8, 0);
				ZEPHIR_SINIT_VAR(_10);
				ZVAL_LONG(&_10, -2);
				ZEPHIR_INIT_VAR(_11);
				zephir_substr(_11, valueSql, 0 , -2 , 0);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "(", _11, ")");
				zephir_concat_self(&columnSql, _4 TSRMLS_CC);
			} else {
				ZEPHIR_SINIT_NVAR(_10);
				ZVAL_STRING(&_10, "\"", 0);
				ZEPHIR_CALL_FUNCTION(&_2, "addcslashes", &_9, 109, typeValues, &_10);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "(\"", _2, "\")");
				zephir_concat_self(&columnSql, _4 TSRMLS_CC);
			}
		}
	} while(0);

	RETURN_CCTOR(columnSql);

}

/**
 * Generates SQL to add a column to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, addColumn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *afterPosition = NULL, *sql = NULL, *defaultValue = NULL, *_1 = NULL, *_2 = NULL, *_3, _4, *_5 = NULL, *_6 = NULL;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` ADD ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` ADD ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_CALL_METHOD(&_1, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVSV(_3, "`", _1, "` ", _2);
	zephir_concat_self(&sql, _3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(defaultValue))) {
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "\"", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "addcslashes", NULL, 109, defaultValue, &_4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CONCAT_SVS(_6, " DEFAULT \"", _5, "\"");
		zephir_concat_self(&sql, _6 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_5, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		zephir_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_5, column, "isfirst", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		zephir_concat_self_str(&sql, SL(" FIRST") TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&afterPosition, column, "getafterposition", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(afterPosition)) {
			ZEPHIR_INIT_LNVAR(_6);
			ZEPHIR_CONCAT_SV(_6, " AFTER ", afterPosition);
			zephir_concat_self(&sql, _6 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to modify a column in a table
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, modifyColumn) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *currentColumn = NULL, *sql = NULL, *defaultValue = NULL, *_1 = NULL, *_2 = NULL, *_3, _4, *_5 = NULL, *_6;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

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
		currentColumn = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` MODIFY ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` MODIFY ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_CALL_METHOD(&_1, column, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcolumndefinition", NULL, 0, column);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVSV(_3, "`", _1, "` ", _2);
	zephir_concat_self(&sql, _3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(defaultValue))) {
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "\"", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "addcslashes", NULL, 109, defaultValue, &_4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CONCAT_SVS(_6, " DEFAULT \"", _5, "\"");
		zephir_concat_self(&sql, _6 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_5, column, "isnotnull", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		zephir_concat_self_str(&sql, SL(" NOT NULL") TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete a column from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropColumn) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL, *sql = NULL;
	zval *tableName = NULL, *schemaName = NULL, *columnName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` DROP COLUMN ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` DROP COLUMN ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "`", columnName, "`");
	zephir_concat_self(&sql, _0 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, addIndex) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *sql = NULL, *indexType = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSV(_0, "ALTER TABLE `", schemaName, "`.`", tableName);
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SV(_0, "ALTER TABLE `", tableName);
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_CALL_METHOD(&indexType, index, "gettype", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(indexType))) {
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "` ADD ", indexType, " INDEX ");
		zephir_concat_self(&sql, _1 TSRMLS_CC);
	} else {
		zephir_concat_self_str(&sql, SL("` ADD INDEX ") TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_2, index, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getcolumnlist", NULL, 100, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_SVSVS(_1, "`", _2, "` (", _3, ")");
	zephir_concat_self(&sql, _1 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete an index from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropIndex) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName_param = NULL, *sql = NULL;
	zval *tableName = NULL, *schemaName = NULL, *indexName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` DROP INDEX ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` DROP INDEX ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_INIT_LNVAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "`", indexName, "`");
	zephir_concat_self(&sql, _0 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to add the primary key to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, addPrimaryKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *index, *sql = NULL, *_1 = NULL, *_2 = NULL, *_3;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` ADD PRIMARY KEY ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` ADD PRIMARY KEY ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_CALL_METHOD(&_2, index, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcolumnlist", NULL, 100, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, "(", _1, ")");
	zephir_concat_self(&sql, _3 TSRMLS_CC);
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete primary key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropPrimaryKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *sql = NULL;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` DROP PRIMARY KEY");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` DROP PRIMARY KEY");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, addForeignKey) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, *sql = NULL, *referencedSchema = NULL, *onDelete = NULL, *onUpdate = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` ADD FOREIGN KEY ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` ADD FOREIGN KEY ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_CALL_METHOD(&_1, reference, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, reference, "getcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcolumnlist", NULL, 100, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVSVS(_4, "`", _1, "`(", _2, ") REFERENCES ");
	zephir_concat_self(&sql, _4 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&referencedSchema, reference, "getreferencedschema", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(referencedSchema)) {
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_SVS(_5, "`", referencedSchema, "`.");
		zephir_concat_self(&sql, _5 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_6, reference, "getreferencedtable", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, reference, "getreferencedcolumns", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getcolumnlist", NULL, 100, _8);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_5);
	ZEPHIR_CONCAT_SVSVS(_5, "`", _6, "`(", _7, ")");
	zephir_concat_self(&sql, _5 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&onDelete, reference, "getondelete", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(onDelete))) {
		ZEPHIR_INIT_VAR(_9);
		ZEPHIR_CONCAT_SV(_9, " ON DELETE ", onDelete);
		zephir_concat_self(&sql, _9 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&onUpdate, reference, "getonupdate", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(onUpdate))) {
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_SV(_5, " ON UPDATE ", onUpdate);
		zephir_concat_self(&sql, _5 TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to delete a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropForeignKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName_param = NULL, *sql = NULL;
	zval *tableName = NULL, *schemaName = NULL, *referenceName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(sql);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "ALTER TABLE `", schemaName, "`.`", tableName, "` DROP FOREIGN KEY ");
		ZEPHIR_CPY_WRT(sql, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "ALTER TABLE `", tableName, "` DROP FOREIGN KEY ");
		ZEPHIR_CPY_WRT(sql, _0);
	}
	ZEPHIR_CONCAT_VSVS(return_value, sql, "`", referenceName, "`");
	RETURN_MM();

}

/**
 * Generates SQL to create a table
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, createTable) {

	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2, *_12, *_18;
	HashPosition _1, _11, _17;
	zval *definition = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, *temporary = NULL, *options, *table = NULL, *createLines, *columns, *column = NULL, *indexes, *index = NULL, *reference = NULL, *references, *indexName = NULL, *indexSql = NULL, *sql, *columnLine = NULL, *indexType = NULL, *referenceSql = NULL, *onDelete = NULL, *onUpdate = NULL, *defaultValue = NULL, **_3, *_4 = NULL, *_5 = NULL, _7 = zval_used_for_init, *_8 = NULL, *_10 = NULL, **_13, *_15 = NULL, *_16 = NULL, **_19, *_20 = NULL, *_21 = NULL, *_22;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array", "phalcon/db/dialect/mysql.zep", 368);
		return;
	}
	ZEPHIR_INIT_VAR(table);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "`", schemaName, "`.`", tableName, "`");
		ZEPHIR_CPY_WRT(table, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "`", tableName, "`");
		ZEPHIR_CPY_WRT(table, _0);
	}
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
	zephir_is_iterable(columns, &_2, &_1, 0, 0, "phalcon/db/dialect/mysql.zep", 431);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(column, _3);
		ZEPHIR_CALL_METHOD(&_4, column, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumndefinition", &_6, 0, column);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(columnLine);
		ZEPHIR_CONCAT_SVSV(columnLine, "`", _4, "` ", _5);
		ZEPHIR_CALL_METHOD(&defaultValue, column, "getdefault", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(defaultValue))) {
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_STRING(&_7, "\"", 0);
			ZEPHIR_CALL_FUNCTION(&_8, "addcslashes", &_9, 109, defaultValue, &_7);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_10);
			ZEPHIR_CONCAT_SVS(_10, " DEFAULT \"", _8, "\"");
			zephir_concat_self(&columnLine, _10 TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_8, column, "isnotnull", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_8)) {
			zephir_concat_self_str(&columnLine, SL(" NOT NULL") TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_8, column, "isautoincrement", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_8)) {
			zephir_concat_self_str(&columnLine, SL(" AUTO_INCREMENT") TSRMLS_CC);
		}
		ZEPHIR_CALL_METHOD(&_8, column, "isprimary", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(_8)) {
			zephir_concat_self_str(&columnLine, SL(" PRIMARY KEY") TSRMLS_CC);
		}
		zephir_array_append(&createLines, columnLine, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 425);
	}
	ZEPHIR_OBS_VAR(indexes);
	if (zephir_array_isset_string_fetch(&indexes, definition, SS("indexes"), 0 TSRMLS_CC)) {
		zephir_is_iterable(indexes, &_12, &_11, 0, 0, "phalcon/db/dialect/mysql.zep", 453);
		for (
		  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
		  ; zephir_hash_move_forward_ex(_12, &_11)
		) {
			ZEPHIR_GET_HVALUE(index, _13);
			ZEPHIR_CALL_METHOD(&indexName, index, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&indexType, index, "gettype", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_STRING(indexName, "PRIMARY")) {
				ZEPHIR_CALL_METHOD(&_5, index, "getcolumns", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4, this_ptr, "getcolumnlist", &_14, 100, _5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(indexSql);
				ZEPHIR_CONCAT_SVS(indexSql, "PRIMARY KEY (", _4, ")");
			} else {
				ZEPHIR_INIT_NVAR(indexSql);
				if (!(ZEPHIR_IS_EMPTY(indexType))) {
					ZEPHIR_CALL_METHOD(&_15, index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_8, this_ptr, "getcolumnlist", &_14, 100, _15);
					zephir_check_call_status();
					ZEPHIR_CONCAT_VSVSVS(indexSql, indexType, " KEY `", indexName, "` (", _8, ")");
				} else {
					ZEPHIR_CALL_METHOD(&_16, index, "getcolumns", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_15, this_ptr, "getcolumnlist", &_14, 100, _16);
					zephir_check_call_status();
					ZEPHIR_CONCAT_SVSVS(indexSql, "KEY `", indexName, "` (", _15, ")");
				}
			}
			zephir_array_append(&createLines, indexSql, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 451);
		}
	}
	ZEPHIR_OBS_VAR(references);
	if (zephir_array_isset_string_fetch(&references, definition, SS("references"), 0 TSRMLS_CC)) {
		zephir_is_iterable(references, &_18, &_17, 0, 0, "phalcon/db/dialect/mysql.zep", 475);
		for (
		  ; zephir_hash_get_current_data_ex(_18, (void**) &_19, &_17) == SUCCESS
		  ; zephir_hash_move_forward_ex(_18, &_17)
		) {
			ZEPHIR_GET_HVALUE(reference, _19);
			ZEPHIR_CALL_METHOD(&_4, reference, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8, reference, "getcolumns", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "getcolumnlist", &_14, 100, _8);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_15, reference, "getreferencedtable", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_20, reference, "getreferencedcolumns", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_16, this_ptr, "getcolumnlist", &_14, 100, _20);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(referenceSql);
			ZEPHIR_CONCAT_SVSVSSVSVS(referenceSql, "CONSTRAINT `", _4, "` FOREIGN KEY (", _5, ")", " REFERENCES `", _15, "`(", _16, ")");
			ZEPHIR_CALL_METHOD(&onDelete, reference, "getondelete", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(onDelete))) {
				ZEPHIR_INIT_LNVAR(_10);
				ZEPHIR_CONCAT_SV(_10, " ON DELETE ", onDelete);
				zephir_concat_self(&referenceSql, _10 TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&onUpdate, reference, "getonupdate", NULL, 0);
			zephir_check_call_status();
			if (!(ZEPHIR_IS_EMPTY(onUpdate))) {
				ZEPHIR_INIT_LNVAR(_21);
				ZEPHIR_CONCAT_SV(_21, " ON UPDATE ", onUpdate);
				zephir_concat_self(&referenceSql, _21 TSRMLS_CC);
			}
			zephir_array_append(&createLines, referenceSql, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 473);
		}
	}
	ZEPHIR_INIT_VAR(_22);
	zephir_fast_join_str(_22, SL(",\n\t"), createLines TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_10);
	ZEPHIR_CONCAT_VS(_10, _22, "\n)");
	zephir_concat_self(&sql, _10 TSRMLS_CC);
	if (zephir_array_isset_string(definition, SS("options"))) {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "_gettableoptions", NULL, 0, definition);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_21);
		ZEPHIR_CONCAT_SV(_21, " ", _4);
		zephir_concat_self(&sql, _21 TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates SQL to drop a table
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropTable) {

	zend_bool ifExists;
	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *sql, *table = NULL;
	zval *tableName = NULL, *schemaName = NULL, *_0 = NULL;

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


	ZEPHIR_INIT_VAR(table);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "`", schemaName, "`.`", tableName, "`");
		ZEPHIR_CPY_WRT(table, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "`", tableName, "`");
		ZEPHIR_CPY_WRT(table, _0);
	}
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
PHP_METHOD(Phalcon_Db_Dialect_MySQL, createView) {

	zval *definition = NULL;
	zval *viewName_param = NULL, *definition_param = NULL, *schemaName_param = NULL, *view = NULL, *viewSql;
	zval *viewName = NULL, *schemaName = NULL, *_0 = NULL;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array", "phalcon/db/dialect/mysql.zep", 515);
		return;
	}
	ZEPHIR_INIT_VAR(view);
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "`", schemaName, "`.`", viewName, "`");
		ZEPHIR_CPY_WRT(view, _0);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "`", viewName, "`");
		ZEPHIR_CPY_WRT(view, _0);
	}
	ZEPHIR_CONCAT_SVSV(return_value, "CREATE VIEW ", view, " AS ", viewSql);
	RETURN_MM();

}

/**
 * Generates SQL to drop a view
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, dropView) {

	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *sql, *view = NULL;
	zval *viewName = NULL, *schemaName = NULL, *_0;

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


	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VSV(_0, schemaName, ".", viewName);
		ZEPHIR_CPY_WRT(view, _0);
	} else {
		ZEPHIR_CPY_WRT(view, viewName);
	}
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
PHP_METHOD(Phalcon_Db_Dialect_MySQL, tableExists) {

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


	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME`= '", tableName, "' AND `TABLE_SCHEMA` = '", schemaName, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`TABLES` WHERE `TABLE_NAME` = '", tableName, "' AND `TABLE_SCHEMA` = DATABASE()");
	RETURN_MM();

}

/**
 * Generates SQL checking for the existence of a schema.view
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, viewExists) {

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


	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`= '", viewName, "' AND `TABLE_SCHEMA`='", schemaName, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SELECT IF(COUNT(*) > 0, 1, 0) FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_NAME`='", viewName, "'");
	RETURN_MM();

}

/**
 * Generates SQL describing a table
 *
 * <code>
 *    print_r($dialect->describeColumns("posts"));
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, describeColumns) {

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


	if (schema && Z_STRLEN_P(schema)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "DESCRIBE `", schema, "`.`", table, "`");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "DESCRIBE `", table, "`");
	RETURN_MM();

}

/**
 * List all tables in database
 *
 * <code>
 *     print_r($dialect->listTables("blog"))
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, listTables) {

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


	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVS(return_value, "SHOW TABLES FROM `", schemaName, "`");
		RETURN_MM();
	}
	RETURN_MM_STRING("SHOW TABLES", 1);

}

/**
 * Generates the SQL to list all views of a schema or user
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, listViews) {

	zval *schemaName_param = NULL;
	zval *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
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
	}


	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CONCAT_SVS(return_value, "SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` WHERE `TABLE_SCHEMA` = '", schemaName, "' ORDER BY view_name");
		RETURN_MM();
	}
	RETURN_MM_STRING("SELECT `TABLE_NAME` AS view_name FROM `INFORMATION_SCHEMA`.`VIEWS` ORDER BY view_name", 1);

}

/**
 * Generates SQL to query indexes on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, describeIndexes) {

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


	if (schema && Z_STRLEN_P(schema)) {
		ZEPHIR_CONCAT_SVSVS(return_value, "SHOW INDEXES FROM `", schema, "`.`", table, "`");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_SVS(return_value, "SHOW INDEXES FROM `", table, "`");
	RETURN_MM();

}

/**
 * Generates SQL to query foreign keys on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, describeReferences) {

	zval *table_param = NULL, *schema_param = NULL, *sql;
	zval *table = NULL, *schema = NULL, *_0 = NULL;

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
	ZVAL_STRING(sql, "SELECT TABLE_NAME,COLUMN_NAME,CONSTRAINT_NAME,REFERENCED_TABLE_SCHEMA,REFERENCED_TABLE_NAME,REFERENCED_COLUMN_NAME FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE WHERE REFERENCED_TABLE_NAME IS NOT NULL AND ", 1);


	if (schema && Z_STRLEN_P(schema)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SVSVS(_0, "CONSTRAINT_SCHEMA = '", schema, "' AND TABLE_NAME = '", table, "'");
		zephir_concat_self(&sql, _0 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_LNVAR(_0);
		ZEPHIR_CONCAT_SVS(_0, "TABLE_NAME = '", table, "'");
		zephir_concat_self(&sql, _0 TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates the SQL to describe the table creation options
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, tableOptions) {

	zval *table_param = NULL, *schema_param = NULL, *sql;
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
	ZEPHIR_INIT_VAR(sql);
	ZVAL_STRING(sql, "SELECT TABLES.TABLE_TYPE AS table_type,TABLES.AUTO_INCREMENT AS auto_increment,TABLES.ENGINE AS engine,TABLES.TABLE_COLLATION AS table_collation FROM INFORMATION_SCHEMA.TABLES WHERE ", 1);


	if (schema && Z_STRLEN_P(schema)) {
		ZEPHIR_CONCAT_VSVSVS(return_value, sql, "TABLES.TABLE_SCHEMA = '", schema, "' AND TABLES.TABLE_NAME = '", table, "'");
		RETURN_MM();
	}
	ZEPHIR_CONCAT_VSVS(return_value, sql, "TABLES.TABLE_NAME = '", table, "'");
	RETURN_MM();

}

/**
 * Generates SQL to add the table creation options
 */
PHP_METHOD(Phalcon_Db_Dialect_MySQL, _getTableOptions) {

	zval *definition_param = NULL, *options, *engine, *autoIncrement, *tableCollation, *collationParts, *tableOptions, *_0 = NULL, *_1, *_2;
	zval *definition = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &definition_param);

	definition = definition_param;



	ZEPHIR_OBS_VAR(options);
	if (zephir_array_isset_string_fetch(&options, definition, SS("options"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(tableOptions);
		array_init(tableOptions);
		ZEPHIR_OBS_VAR(engine);
		if (zephir_array_isset_string_fetch(&engine, options, SS("ENGINE"), 0 TSRMLS_CC)) {
			if (zephir_is_true(engine)) {
				ZEPHIR_INIT_VAR(_0);
				ZEPHIR_CONCAT_SV(_0, "ENGINE=", engine);
				zephir_array_append(&tableOptions, _0, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 671);
			}
		}
		ZEPHIR_OBS_VAR(autoIncrement);
		if (zephir_array_isset_string_fetch(&autoIncrement, options, SS("AUTO_INCREMENT"), 0 TSRMLS_CC)) {
			if (zephir_is_true(autoIncrement)) {
				ZEPHIR_INIT_LNVAR(_0);
				ZEPHIR_CONCAT_SV(_0, "AUTO_INCREMENT=", autoIncrement);
				zephir_array_append(&tableOptions, _0, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 680);
			}
		}
		ZEPHIR_OBS_VAR(tableCollation);
		if (zephir_array_isset_string_fetch(&tableCollation, options, SS("TABLE_COLLATION"), 0 TSRMLS_CC)) {
			if (zephir_is_true(tableCollation)) {
				ZEPHIR_INIT_VAR(collationParts);
				zephir_fast_explode_str(collationParts, SL("_"), tableCollation, LONG_MAX TSRMLS_CC);
				zephir_array_fetch_long(&_1, collationParts, 0, PH_NOISY | PH_READONLY, "phalcon/db/dialect/mysql.zep", 690 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_0);
				ZEPHIR_CONCAT_SV(_0, "DEFAULT CHARSET=", _1);
				zephir_array_append(&tableOptions, _0, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 690);
				ZEPHIR_INIT_VAR(_2);
				ZEPHIR_CONCAT_SV(_2, "COLLATE=", tableCollation);
				zephir_array_append(&tableOptions, _2, PH_SEPARATE, "phalcon/db/dialect/mysql.zep", 691);
			}
		}
		if (zephir_fast_count_int(tableOptions TSRMLS_CC)) {
			zephir_fast_join_str(return_value, SL(" "), tableOptions TSRMLS_CC);
			RETURN_MM();
		}
	}
	RETURN_MM_STRING("", 1);

}

