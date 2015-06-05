
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"


/**
 * Phalcon\Db\Dialect\Oracle
 *
 * Generates database specific SQL for the Oracle RDBMS
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Dialect_Oracle) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Dialect, Oracle, phalcon, db_dialect_oracle, phalcon_db_dialect_ce, phalcon_db_dialect_oracle_method_entry, 0);

	zend_declare_property_string(phalcon_db_dialect_oracle_ce, SL("_escapeChar"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Generates the SQL for LIMIT clause
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, limit) {

	int limit, offset = 0;
	zval *sqlQuery_param = NULL, *number, *_0 = NULL, *_1, _2 = zval_used_for_init, *_3, _4 = zval_used_for_init, _6;
	zval *sqlQuery = NULL, *_5, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sqlQuery_param, &number);

	if (unlikely(Z_TYPE_P(sqlQuery_param) != IS_STRING && Z_TYPE_P(sqlQuery_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'sqlQuery' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(sqlQuery_param) == IS_STRING)) {
		zephir_get_strval(sqlQuery, sqlQuery_param);
	} else {
		ZEPHIR_INIT_VAR(sqlQuery);
		ZVAL_EMPTY_STRING(sqlQuery);
	}


	if (Z_TYPE_P(number) == IS_ARRAY) {
		if (zephir_array_isset_long(number, 1)) {
			ZEPHIR_INIT_VAR(_0);
			zephir_array_fetch_long(&_1, number, 1, PH_NOISY | PH_READONLY, "phalcon/db/dialect/oracle.zep", 51 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_2);
			ZVAL_STRING(&_2, "'", 0);
			zephir_fast_trim(_0, _1, &_2, ZEPHIR_TRIM_BOTH TSRMLS_CC);
			offset = zephir_get_intval(_0);
		}
		ZEPHIR_INIT_NVAR(_0);
		zephir_array_fetch_long(&_1, number, 0, PH_NOISY | PH_READONLY, "phalcon/db/dialect/oracle.zep", 54 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_STRING(&_2, "'", 0);
		zephir_fast_trim(_0, _1, &_2, ZEPHIR_TRIM_BOTH TSRMLS_CC);
		limit = (zephir_get_intval(_0) + offset);
	} else {
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "'", 0);
		zephir_fast_trim(_3, number, &_4, ZEPHIR_TRIM_BOTH TSRMLS_CC);
		limit = zephir_get_intval(_3);
	}
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, limit);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SVSVS(_5, "SELECT * FROM (SELECT Z1.*, ROWNUM PHALCON_RN FROM (", sqlQuery, ") Z1 WHERE ROWNUM <= ", &_4, ")");
	ZEPHIR_CPY_WRT(sqlQuery, _5);
	if (offset != 0) {
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_LONG(&_6, offset);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SV(_7, " WHERE PHALCON_RN >= ", &_6);
		zephir_concat_self(&sqlQuery, _7 TSRMLS_CC);
	}
	RETURN_CTOR(sqlQuery);

}

/**
 * Gets the column name in Oracle
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, getColumnDefinition) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *column, *columnSql = NULL, *size = NULL, *scale = NULL, *type = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &column);



	ZEPHIR_CALL_METHOD(&type, column, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&size, column, "getsize", NULL, 0);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(type, 0)) {
			ZEPHIR_INIT_VAR(columnSql);
			ZVAL_STRING(columnSql, "INTEGER", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 1)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZVAL_STRING(columnSql, "DATE", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 2)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZEPHIR_CONCAT_SVS(columnSql, "VARCHAR2(", size, ")");
			break;
		}
		if (ZEPHIR_IS_LONG(type, 3)) {
			ZEPHIR_CALL_METHOD(&scale, column, "getscale", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(columnSql);
			ZEPHIR_CONCAT_SVSVS(columnSql, "NUMBER(", size, ",", scale, ")");
			break;
		}
		if (ZEPHIR_IS_LONG(type, 4)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZVAL_STRING(columnSql, "TIMESTAMP", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 5)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZEPHIR_CONCAT_SVS(columnSql, "CHAR(", size, ")");
			break;
		}
		if (ZEPHIR_IS_LONG(type, 6)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZVAL_STRING(columnSql, "TEXT", 1);
			break;
		}
		if (ZEPHIR_IS_LONG(type, 7)) {
			ZEPHIR_CALL_METHOD(&scale, column, "getscale", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(columnSql);
			ZEPHIR_CONCAT_SVSVS(columnSql, "FLOAT(", size, ",", scale, ")");
			break;
		}
		if (ZEPHIR_IS_LONG(type, 8)) {
			ZEPHIR_INIT_NVAR(columnSql);
			ZVAL_STRING(columnSql, "TINYINT(1)", 1);
			break;
		}
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Unrecognized Oracle data type", "phalcon/db/dialect/oracle.zep", 120);
		return;
	} while(0);

	RETURN_CCTOR(columnSql);

}

/**
 * Generates SQL to add a column to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addColumn) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *column;
	zval *tableName = NULL, *schemaName = NULL;

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


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/oracle.zep", 131);
	return;

}

/**
 * Generates SQL to modify a column in a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, modifyColumn) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *currentColumn = NULL;
	zval *tableName = NULL, *schemaName = NULL;

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


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/oracle.zep", 139);
	return;

}

/**
 * Generates SQL to delete a column from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropColumn) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *columnName_param = NULL;
	zval *tableName = NULL, *schemaName = NULL, *columnName = NULL;

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
	zephir_get_strval(columnName, columnName_param);


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/oracle.zep", 147);
	return;

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addIndex) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *index;
	zval *tableName = NULL, *schemaName = NULL;

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


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/oracle.zep", 155);
	return;

}

/**
 /**
 * Generates SQL to delete an index from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropIndex) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *indexName_param = NULL;
	zval *tableName = NULL, *schemaName = NULL, *indexName = NULL;

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


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/oracle.zep", 164);
	return;

}

/**
 * Generates SQL to add the primary key to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addPrimaryKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *index;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &index);

	zephir_get_strval(tableName, tableName_param);
	zephir_get_strval(schemaName, schemaName_param);


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/oracle.zep", 172);
	return;

}

/**
 * Generates SQL to delete primary key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropPrimaryKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL;
	zval *tableName = NULL, *schemaName = NULL;

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


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/oracle.zep", 180);
	return;

}

/**
 * Generates SQL to add an index to a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, addForeignKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *reference;
	zval *tableName = NULL, *schemaName = NULL;

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


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/oracle.zep", 188);
	return;

}

/**
 * Generates SQL to delete a foreign key from a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropForeignKey) {

	zval *tableName_param = NULL, *schemaName_param = NULL, *referenceName_param = NULL;
	zval *tableName = NULL, *schemaName = NULL, *referenceName = NULL;

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


	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/oracle.zep", 196);
	return;

}

/**
 * Generates SQL to create a table in Oracle
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, createTable) {

	zval *definition = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL;
	zval *tableName = NULL, *schemaName = NULL;

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



	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Not implemented yet", "phalcon/db/dialect/oracle.zep", 204);
	return;

}

/**
 * Generates SQL to drop a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropTable) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_bool ifExists;
	zval *tableName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *table = NULL, *_0 = NULL, *_1 = NULL, *_3 = NULL, *_4 = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &tableName_param, &schemaName_param, &ifExists_param);

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
		ZEPHIR_CALL_CE_STATIC(&_1, phalcon_text_ce, "upper", &_2, 110, schemaName);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "escape", NULL, 99, _1);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_4, phalcon_text_ce, "upper", &_2, 110, tableName);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "escape", NULL, 99, _4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(table);
		ZEPHIR_CONCAT_VSV(table, _0, ".", _3);
	} else {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_2, 110, tableName);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&table, this_ptr, "escape", NULL, 99, _0);
		zephir_check_call_status();
	}
	if (ifExists) {
		ZEPHIR_CONCAT_SV(return_value, "DROP TABLE IF EXISTS ", table);
		RETURN_MM();
	} else {
		ZEPHIR_CONCAT_SV(return_value, "DROP TABLE ", table);
		RETURN_MM();
	}

}

/**
 * Generates SQL to create a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, createView) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *definition = NULL;
	zval *viewName_param = NULL, *definition_param = NULL, *schemaName_param = NULL, *view = NULL, *viewSql, *_0 = NULL, *_2 = NULL, *_3;
	zval *viewName = NULL, *schemaName = NULL;

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The index 'sql' is required in the definition array", "phalcon/db/dialect/oracle.zep", 235);
		return;
	}
	if (schemaName && Z_STRLEN_P(schemaName)) {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, schemaName);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_2, phalcon_text_ce, "upper", &_1, 110, viewName);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_VSV(_3, _0, ".", _2);
		ZEPHIR_CALL_METHOD(&view, this_ptr, "escape", NULL, 99, _3);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, viewName);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&view, this_ptr, "escape", NULL, 99, _0);
		zephir_check_call_status();
	}
	ZEPHIR_CONCAT_SVSV(return_value, "CREATE VIEW ", view, " AS ", viewSql);
	RETURN_MM();

}

/**
 * Generates SQL to drop a view
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, dropView) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_bool ifExists;
	zval *viewName_param = NULL, *schemaName_param = NULL, *ifExists_param = NULL, *view = NULL, *_0 = NULL, *_2 = NULL, *_3;
	zval *viewName = NULL, *schemaName = NULL;

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
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, schemaName);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_2, phalcon_text_ce, "upper", &_1, 110, viewName);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_VSV(_3, _0, ".", _2);
		ZEPHIR_CALL_METHOD(&view, this_ptr, "escape", NULL, 99, _3);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, viewName);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&view, this_ptr, "escape", NULL, 99, _0);
		zephir_check_call_status();
	}
	if (ifExists) {
		ZEPHIR_CONCAT_SV(return_value, "DROP VIEW IF EXISTS ", view);
		RETURN_MM();
	} else {
		ZEPHIR_CONCAT_SV(return_value, "DROP VIEW ", view);
		RETURN_MM();
	}

}

/**
 * Generates SQL checking for the existence of a schema.view
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, viewExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *viewName_param = NULL, *schemaName_param = NULL, *_0 = NULL, *_2 = NULL;
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


	if (!ZEPHIR_IS_STRING(schemaName, "")) {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, viewName);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_2, phalcon_text_ce, "upper", &_1, 110, schemaName);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END RET FROM ALL_VIEWS WHERE VIEW_NAME='", _0, "' AND OWNER='", _2, "'");
		RETURN_MM();
	} else {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, viewName);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END RET FROM ALL_VIEWS WHERE VIEW_NAME='", _0, "'");
		RETURN_MM();
	}

}

/**
 * Generates the SQL to list all views of a schema or user
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, listViews) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *schemaName_param = NULL, *_0 = NULL;
	zval *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
		zephir_get_strval(schemaName, schemaName_param);
	}


	if (!ZEPHIR_IS_STRING(schemaName, "")) {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, schemaName);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "SELECT VIEW_NAME FROM ALL_VIEWS WHERE OWNER='", _0, "' ORDER BY VIEW_NAME");
		RETURN_MM();
	} else {
		RETURN_MM_STRING("SELECT VIEW_NAME FROM ALL_VIEWS VIEW_NAME", 1);
	}

}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * <code>
 *    echo $dialect->tableExists("posts", "blog");
 *    echo $dialect->tableExists("posts");
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, tableExists) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *_0 = NULL, *_2 = NULL;
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


	if (!ZEPHIR_IS_STRING(schemaName, "")) {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, tableName);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_2, phalcon_text_ce, "upper", &_1, 110, schemaName);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END RET FROM ALL_TABLES WHERE TABLE_NAME='", _0, "' AND OWNER = '", _2, "'");
		RETURN_MM();
	} else {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, tableName);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END RET FROM ALL_TABLES WHERE TABLE_NAME='", _0, "'");
		RETURN_MM();
	}

}

/**
 * Generates SQL describing a table
 *
 * <code>
 *    print_r($dialect->describeColumns("posts"));
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, describeColumns) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *table_param = NULL, *schema_param = NULL, *_0 = NULL, *_2 = NULL;
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


	if (!ZEPHIR_IS_STRING(schema, "")) {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, table);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_2, phalcon_text_ce, "upper", &_1, 110, schema);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT TC.COLUMN_NAME, TC.DATA_TYPE, TC.DATA_LENGTH, TC.DATA_PRECISION, TC.DATA_SCALE, TC.NULLABLE, C.CONSTRAINT_TYPE, TC.DATA_DEFAULT, CC.POSITION FROM ALL_TAB_COLUMNS TC LEFT JOIN (ALL_CONS_COLUMNS CC JOIN ALL_CONSTRAINTS C ON (CC.CONSTRAINT_NAME = C.CONSTRAINT_NAME AND CC.TABLE_NAME = C.TABLE_NAME AND CC.OWNER = C.OWNER AND C.CONSTRAINT_TYPE = 'P')) ON TC.TABLE_NAME = CC.TABLE_NAME AND TC.COLUMN_NAME = CC.COLUMN_NAME WHERE TC.TABLE_NAME = '", _0, "' AND TC.OWNER = '", _2, "' ORDER BY TC.COLUMN_ID");
		RETURN_MM();
	} else {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, table);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "SELECT TC.COLUMN_NAME, TC.DATA_TYPE, TC.DATA_LENGTH, TC.DATA_PRECISION, TC.DATA_SCALE, TC.NULLABLE, C.CONSTRAINT_TYPE, TC.DATA_DEFAULT, CC.POSITION FROM ALL_TAB_COLUMNS TC LEFT JOIN (ALL_CONS_COLUMNS CC JOIN ALL_CONSTRAINTS C ON (CC.CONSTRAINT_NAME = C.CONSTRAINT_NAME AND CC.TABLE_NAME = C.TABLE_NAME AND CC.OWNER = C.OWNER AND C.CONSTRAINT_TYPE = 'P')) ON TC.TABLE_NAME = CC.TABLE_NAME AND TC.COLUMN_NAME = CC.COLUMN_NAME WHERE TC.TABLE_NAME = '", _0, "' ORDER BY TC.COLUMN_ID");
		RETURN_MM();
	}

}

/**
 * List all tables in database
 *
 * <code>
 *    print_r($dialect->listTables("blog"))
 * </code>
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, listTables) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *schemaName_param = NULL, *_0 = NULL;
	zval *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &schemaName_param);

	if (!schemaName_param) {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	} else {
		zephir_get_strval(schemaName, schemaName_param);
	}


	if (!ZEPHIR_IS_STRING(schemaName, "")) {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, schemaName);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "SELECT TABLE_NAME, OWNER FROM ALL_TABLES WHERE OWNER='", _0, "' ORDER BY OWNER, TABLE_NAME");
		RETURN_MM();
	} else {
		RETURN_MM_STRING("SELECT TABLE_NAME, OWNER FROM ALL_TABLES ORDER BY OWNER, TABLE_NAME", 1);
	}

}

/**
 * Generates SQL to query indexes on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, describeIndexes) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *table_param = NULL, *schema_param = NULL, *_0 = NULL, *_2 = NULL;
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


	if (!ZEPHIR_IS_STRING(schema, "")) {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, table);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_2, phalcon_text_ce, "upper", &_1, 110, schema);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVSVS(return_value, "SELECT I.TABLE_NAME, 0 AS C0, I.INDEX_NAME, IC.COLUMN_POSITION, IC.COLUMN_NAME FROM ALL_INDEXES I JOIN ALL_IND_COLUMNS IC ON I.INDEX_NAME = IC.INDEX_NAME WHERE  I.TABLE_NAME = '", _0, "' AND IC.INDEX_OWNER = '", _2, "'");
		RETURN_MM();
	} else {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, table);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "SELECT I.TABLE_NAME, 0 AS C0, I.INDEX_NAME, IC.COLUMN_POSITION, IC.COLUMN_NAME FROM ALL_INDEXES I JOIN ALL_IND_COLUMNS IC ON I.INDEX_NAME = IC.INDEX_NAME WHERE  I.TABLE_NAME = '", _0, "'");
		RETURN_MM();
	}

}

/**
 * Generates SQL to query foreign keys on a table
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, describeReferences) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *table_param = NULL, *schema_param = NULL, *sql, *_0 = NULL, *_2 = NULL, *_3 = NULL;
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
	ZVAL_STRING(sql, "SELECT AC.TABLE_NAME, CC.COLUMN_NAME, AC.CONSTRAINT_NAME, AC.R_OWNER, RCC.TABLE_NAME R_TABLE_NAME, RCC.COLUMN_NAME R_COLUMN_NAME FROM ALL_CONSTRAINTS AC JOIN ALL_CONS_COLUMNS CC ON AC.CONSTRAINT_NAME = CC.CONSTRAINT_NAME JOIN ALL_CONS_COLUMNS RCC ON AC.R_OWNER = RCC.OWNER AND AC.R_CONSTRAINT_NAME = RCC.CONSTRAINT_NAME WHERE AC.CONSTRAINT_TYPE='R' ", 1);
	if (!ZEPHIR_IS_STRING(schema, "")) {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, schema);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_2, phalcon_text_ce, "upper", &_1, 110, table);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVSVS(_3, "AND AC.OWNER='", _0, "' AND AC.TABLE_NAME = '", _2, "'");
		zephir_concat_self(&sql, _3 TSRMLS_CC);
	} else {
		ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "upper", &_1, 110, table);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SVS(_3, "AND AC.TABLE_NAME = '", _0, "'");
		zephir_concat_self(&sql, _3 TSRMLS_CC);
	}
	RETURN_CCTOR(sql);

}

/**
 * Generates the SQL to describe the table creation options
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, tableOptions) {

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


	RETURN_MM_STRING("", 1);

}

/**
 * Checks whether the platform supports savepoints
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, supportsSavepoints) {


	RETURN_BOOL(0);

}

/**
 * Checks whether the platform supports releasing savepoints.
 */
PHP_METHOD(Phalcon_Db_Dialect_Oracle, supportsReleaseSavepoints) {


	RETURN_BOOL(0);

}

