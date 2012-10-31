
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/string.h"

/**
 * Phalcon\Db\Dialect
 *
 * This is the base class to each database dialect. This implements
 * common methods to transform intermediate code into its RDBM related syntax
 */


/**
 * Generates the SQL for LIMIT clause
 *
 * @param string $sqlQuery
 * @param int $number
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, limit){

	zval *sql_query, *number, *is_numeric, *limit, *sql_limit;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &sql_query, &number) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(is_numeric);
	PHALCON_CALL_FUNC_PARAMS_1(is_numeric, "is_numeric", number);
	if (PHALCON_IS_TRUE(is_numeric)) {
		PHALCON_INIT_VAR(limit);
		PHALCON_CALL_FUNC_PARAMS_1(limit, "intval", number);
		
		PHALCON_INIT_VAR(sql_limit);
		PHALCON_CONCAT_VSV(sql_limit, sql_query, " LIMIT ", limit);
		
		RETURN_CTOR(sql_limit);
	}
	
	
	RETURN_CCTOR(sql_query);
}

/**
 * Returns a SQL modified with a FOR UPDATE clause
 *
 * @param string $sqlQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, forUpdate){

	zval *sql_query, *sql;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_query) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_VS(sql, sql_query, " FOR UPDATE");
	
	RETURN_CTOR(sql);
}

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 *
 * @param string $sqlQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, sharedLock){

	zval *sql_query, *sql;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_query) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_VS(sql, sql_query, " LOCK IN SHARE MODE");
	
	RETURN_CTOR(sql);
}

/**
 * Builds a SELECT statement
 *
 * @param array $definition
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, select){

	zval *definition, *columns, *columns_sql = NULL, *tables;
	zval *tables_sql = NULL, *sql, *joins, *join = NULL, *type = NULL, *source = NULL;
	zval *sql_join = NULL, *join_conditions_array = NULL, *join_conditions = NULL;
	zval *where_conditions, *group_fields, *group_clause;
	zval *having_conditions, *order_fields, *limit_value;
	zval *number, *offset;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &definition) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(definition, SS("tables"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'tables' is required in the definition array");
		return;
	}
	eval_int = phalcon_array_isset_string(definition, SS("columns"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array");
		return;
	}
	
	PHALCON_INIT_VAR(columns);
	phalcon_array_fetch_string(&columns, definition, SL("columns"), PH_NOISY_CC);
	if (Z_TYPE_P(columns) == IS_ARRAY) { 
		PHALCON_INIT_VAR(columns_sql);
		phalcon_fast_join_str(columns_sql, SL(","), columns TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(columns_sql, columns);
	}
	
	PHALCON_INIT_VAR(tables);
	phalcon_array_fetch_string(&tables, definition, SL("tables"), PH_NOISY_CC);
	if (Z_TYPE_P(tables) == IS_ARRAY) { 
		PHALCON_INIT_VAR(tables_sql);
		phalcon_fast_join_str(tables_sql, SL(","), tables TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(tables_sql, tables);
	}
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_SVSV(sql, "SELECT ", columns_sql, " FROM ", tables_sql);
	eval_int = phalcon_array_isset_string(definition, SS("joins"));
	if (eval_int) {
		PHALCON_INIT_VAR(joins);
		phalcon_array_fetch_string(&joins, definition, SL("joins"), PH_NOISY_CC);
		
		if (!phalcon_valid_foreach(joins TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(joins);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_VALUE(join);
			
			PHALCON_INIT_NVAR(type);
			phalcon_array_fetch_string(&type, join, SL("type"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(source);
			phalcon_array_fetch_string(&source, join, SL("source"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(sql_join);
			PHALCON_CONCAT_SVSV(sql_join, " ", type, " JOIN ", source);
			eval_int = phalcon_array_isset_string(join, SS("conditions"));
			if (eval_int) {
				PHALCON_INIT_NVAR(join_conditions_array);
				phalcon_array_fetch_string(&join_conditions_array, join, SL("conditions"), PH_NOISY_CC);
				
				PHALCON_INIT_NVAR(join_conditions);
				phalcon_fast_join_str(join_conditions, SL(" AND "), join_conditions_array TSRMLS_CC);
				PHALCON_SCONCAT_SV(sql_join, " ON ", join_conditions);
			}
			
			phalcon_concat_self(sql, sql_join TSRMLS_CC);
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
			
		ph_cycle_end_0:
		if(0){}
		
	}
	
	eval_int = phalcon_array_isset_string(definition, SS("where"));
	if (eval_int) {
		PHALCON_INIT_VAR(where_conditions);
		phalcon_array_fetch_string(&where_conditions, definition, SL("where"), PH_NOISY_CC);
		PHALCON_SCONCAT_SV(sql, " WHERE ", where_conditions);
	}
	
	eval_int = phalcon_array_isset_string(definition, SS("group"));
	if (eval_int) {
		PHALCON_INIT_VAR(group_fields);
		phalcon_array_fetch_string(&group_fields, definition, SL("group"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(group_clause);
		PHALCON_CONCAT_SV(group_clause, " GROUP BY ", group_fields);
		phalcon_concat_self(sql, group_clause TSRMLS_CC);
		eval_int = phalcon_array_isset_string(definition, SS("having"));
		if (eval_int) {
			PHALCON_INIT_VAR(having_conditions);
			phalcon_array_fetch_string(&having_conditions, definition, SL("having"), PH_NOISY_CC);
			PHALCON_SCONCAT_SV(sql, " HAVING ", having_conditions);
		}
	}
	
	eval_int = phalcon_array_isset_string(definition, SS("order"));
	if (eval_int) {
		PHALCON_INIT_VAR(order_fields);
		phalcon_array_fetch_string(&order_fields, definition, SL("order"), PH_NOISY_CC);
		PHALCON_SCONCAT_SV(sql, " ORDER BY ", order_fields);
	}
	
	eval_int = phalcon_array_isset_string(definition, SS("limit"));
	if (eval_int) {
		PHALCON_INIT_VAR(limit_value);
		phalcon_array_fetch_string(&limit_value, definition, SL("limit"), PH_NOISY_CC);
		if (Z_TYPE_P(limit_value) == IS_ARRAY) { 
			PHALCON_INIT_VAR(number);
			phalcon_array_fetch_string(&number, limit_value, SL("number"), PH_NOISY_CC);
			eval_int = phalcon_array_isset_string(limit_value, SS("offset"));
			if (eval_int) {
				PHALCON_INIT_VAR(offset);
				phalcon_array_fetch_string(&offset, limit_value, SL("offset"), PH_NOISY_CC);
				PHALCON_SCONCAT_SVSV(sql, " LIMIT ", number, " OFFSET ", offset);
			} else {
				PHALCON_SCONCAT_SV(sql, " LIMIT ", number);
			}
		} else {
			PHALCON_SCONCAT_SV(sql, " LIMIT ", limit_value);
		}
	}
	
	
	RETURN_CTOR(sql);
}

