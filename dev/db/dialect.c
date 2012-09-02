
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
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/operators.h"

/**
 * Phalcon\Db\Dialect
 */

/**
 * Generates the SQL for LIMIT clause
 *
 * @param string $sqlQuery
 * @param int $number
 * @return string
 */
PHP_METHOD(Phalcon_Db_Dialect, limit){

	zval *sql_query = NULL, *number = NULL, *is_numeric = NULL, *limit = NULL, *sql_limit = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &sql_query, &number) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(is_numeric);
	PHALCON_CALL_FUNC_PARAMS_1(is_numeric, "is_numeric", number);
	if (Z_TYPE_P(is_numeric) == IS_BOOL && Z_BVAL_P(is_numeric)) {
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

	zval *sql_query = NULL, *sql = NULL;

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

	zval *sql_query = NULL, *sql = NULL;

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

	zval *definition = NULL, *columns = NULL, *columns_sql = NULL, *tables = NULL;
	zval *tables_sql = NULL, *sql = NULL, *joins = NULL, *join = NULL, *type = NULL, *source = NULL;
	zval *sql_join = NULL, *join_conditions_array = NULL, *join_conditions = NULL;
	zval *on_join = NULL, *where_conditions = NULL, *where_clause = NULL;
	zval *group_fields = NULL, *group_clause = NULL, *having_conditions = NULL;
	zval *having_clause = NULL, *order_fields = NULL, *order_clause = NULL;
	zval *limit_value = NULL, *limit_clause = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &definition) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(definition, SL("tables")+1);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'tables' is required in the definition array");
		return;
	}
	eval_int = phalcon_array_isset_string(definition, SL("columns")+1);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The index 'columns' is required in the definition array");
		return;
	}
	
	PHALCON_INIT_VAR(columns);
	phalcon_array_fetch_string(&columns, definition, SL("columns"), PH_NOISY_CC);
	if (Z_TYPE_P(columns) == IS_ARRAY) { 
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, ",", 1);
		PHALCON_INIT_VAR(columns_sql);
		phalcon_fast_join(columns_sql, c0, columns TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(columns_sql, columns);
	}
	
	PHALCON_INIT_VAR(tables);
	phalcon_array_fetch_string(&tables, definition, SL("tables"), PH_NOISY_CC);
	if (Z_TYPE_P(tables) == IS_ARRAY) { 
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, ",", 1);
		PHALCON_INIT_VAR(tables_sql);
		phalcon_fast_join(tables_sql, c1, tables TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(tables_sql, tables);
	}
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CONCAT_SVSV(sql, "SELECT ", columns_sql, " FROM ", tables_sql);
	eval_int = phalcon_array_isset_string(definition, SL("joins")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(joins);
		phalcon_array_fetch_string(&joins, definition, SL("joins"), PH_NOISY_CC);
		if (!phalcon_valid_foreach(joins TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(joins);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_62b2_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_62b2_0;
			}
			
			PHALCON_INIT_VAR(join);
			ZVAL_ZVAL(join, *hd, 1, 0);
			PHALCON_INIT_VAR(type);
			phalcon_array_fetch_string(&type, join, SL("type"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(source);
			phalcon_array_fetch_string(&source, join, SL("source"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(sql_join);
			PHALCON_CONCAT_SVSV(sql_join, " ", type, " JOIN ", source);
			eval_int = phalcon_array_isset_string(join, SL("conditions")+1);
			if (eval_int) {
				PHALCON_INIT_VAR(join_conditions_array);
				phalcon_array_fetch_string(&join_conditions_array, join, SL("conditions"), PH_NOISY_CC);
				
				PHALCON_INIT_VAR(c2);
				ZVAL_STRING(c2, " AND ", 1);
				
				PHALCON_INIT_VAR(join_conditions);
				phalcon_fast_join(join_conditions, c2, join_conditions_array TSRMLS_CC);
				
				PHALCON_INIT_VAR(on_join);
				PHALCON_CONCAT_SV(on_join, " ON ", join_conditions);
				phalcon_concat_self(&sql_join, on_join TSRMLS_CC);
			}
			
			phalcon_concat_self(&sql, sql_join TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_62b2_0;
		fee_62b2_0:
		if(0){}
		
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("where")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(where_conditions);
		phalcon_array_fetch_string(&where_conditions, definition, SL("where"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(where_clause);
		PHALCON_CONCAT_SV(where_clause, " WHERE ", where_conditions);
		phalcon_concat_self(&sql, where_clause TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("group")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(group_fields);
		phalcon_array_fetch_string(&group_fields, definition, SL("group"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(group_clause);
		PHALCON_CONCAT_SV(group_clause, " GROUP BY ", group_fields);
		phalcon_concat_self(&sql, group_clause TSRMLS_CC);
		eval_int = phalcon_array_isset_string(definition, SL("having")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(having_conditions);
			phalcon_array_fetch_string(&having_conditions, definition, SL("having"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(having_clause);
			PHALCON_CONCAT_SV(having_clause, " HAVING ", having_conditions);
			phalcon_concat_self(&sql, having_clause TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("order")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(order_fields);
		phalcon_array_fetch_string(&order_fields, definition, SL("order"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(order_clause);
		PHALCON_CONCAT_SV(order_clause, " ORDER BY ", order_fields);
		phalcon_concat_self(&sql, order_clause TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("limit")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(limit_value);
		phalcon_array_fetch_string(&limit_value, definition, SL("limit"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(limit_clause);
		PHALCON_CONCAT_SV(limit_clause, " LIMIT ", limit_value);
		phalcon_concat_self(&sql, limit_clause TSRMLS_CC);
	}
	
	
	RETURN_CTOR(sql);
}

