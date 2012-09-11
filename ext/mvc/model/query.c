
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/operators.h"

/**
 * Phalcon\Mvc\Model\Query
 *
 * This class takes a PHQL intermediate representation and executes it.
 *
 * <code>
 *
 * </code>
 *
 */


/**
 * Phalcon\Mvc\Model\Query constructor
 *
 * @param string $phql
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, __construct){

	zval *phql = NULL, *ast = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &phql) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(ast);
	PHALCON_CALL_STATIC_PARAMS_1(ast, "phalcon\\mvc\\model\\query\\lang", "parsephql", phql);
	phalcon_update_property_zval(this_ptr, SL("_ast"), ast TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, setDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the dependency injection container
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, getDI){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Replaces the model's name to its source name in a qualifed-name expression
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getQualified){

	zval *expr = NULL, *sql_aliases = NULL, *column_domain = NULL, *exception_message = NULL;
	zval *exception = NULL, *column_name = NULL, *source = NULL, *source_column = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &expr, &sql_aliases) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(expr, SS("domain"));
	if (eval_int) {
		PHALCON_INIT_VAR(column_domain);
		phalcon_array_fetch_string(&column_domain, expr, SL("domain"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(sql_aliases, column_domain);
		if (!eval_int) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Unknown table or alias '", column_domain, "'");
			
			PHALCON_INIT_VAR(exception);
			object_init_ex(exception, phalcon_mvc_model_exception_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
			phalcon_throw_exception(exception TSRMLS_CC);
			return;
		}
		
		PHALCON_INIT_VAR(column_name);
		phalcon_array_fetch_string(&column_name, expr, SL("name"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(source);
		phalcon_array_fetch(&source, sql_aliases, column_domain, PH_NOISY_CC);
		
		PHALCON_INIT_VAR(source_column);
		PHALCON_CONCAT_VSV(source_column, source, ".", column_name);
		
		RETURN_CTOR(source_column);
	}
	
	PHALCON_INIT_VAR(column_name);
	phalcon_array_fetch_string(&column_name, expr, SL("name"), PH_NOISY_CC);
	
	RETURN_CCTOR(column_name);
}

/**
 * Resolves a expression in a single call argument
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getCallArgument){

	zval *argument = NULL, *sql_aliases = NULL, *argument_type = NULL;
	zval *argument_expr = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &argument, &sql_aliases) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(argument_type);
	phalcon_array_fetch_string(&argument_type, argument, SL("type"), PH_NOISY_CC);
	if (phalcon_compare_strict_long(argument_type, 352 TSRMLS_CC)) {
		PHALCON_INIT_VAR(argument_expr);
		ZVAL_STRING(argument_expr, "*", 1);
	} else {
		PHALCON_INIT_VAR(argument_expr);
		PHALCON_CALL_METHOD_PARAMS_2(argument_expr, this_ptr, "_getexpression", argument, sql_aliases, PH_NO_CHECK);
	}
	
	
	RETURN_CCTOR(argument_expr);
}

/**
 * Resolves a expression in a single call argument
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getFunctionCall){

	zval *expr = NULL, *sql_aliases = NULL, *name = NULL, *arguments = NULL, *arguments_expr = NULL;
	zval *argument = NULL, *argument_expr = NULL, *comma = NULL, *function_args = NULL;
	zval *function_call = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &expr, &sql_aliases) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(name);
	phalcon_array_fetch_string(&name, expr, SL("name"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(expr, SS("arguments"));
	if (eval_int) {
		PHALCON_INIT_VAR(arguments);
		phalcon_array_fetch_string(&arguments, expr, SL("arguments"), PH_NOISY_CC);
		eval_int = phalcon_array_isset_long(arguments, 0);
		if (eval_int) {
			PHALCON_INIT_VAR(arguments_expr);
			array_init(arguments_expr);
			
			if (!phalcon_valid_foreach(arguments TSRMLS_CC)) {
				return;
			}
			
			ah0 = Z_ARRVAL_P(arguments);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			
			ph_cycle_start_0:
			
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto ph_cycle_end_0;
				}
				
				PHALCON_GET_FOREACH_VALUE(argument);
				
				PHALCON_INIT_VAR(argument_expr);
				PHALCON_CALL_METHOD_PARAMS_2(argument_expr, this_ptr, "_getcallargument", argument, sql_aliases, PH_NO_CHECK);
				phalcon_array_append(&arguments_expr, argument_expr, PH_SEPARATE TSRMLS_CC);
				
				zend_hash_move_forward_ex(ah0, &hp0);
				goto ph_cycle_start_0;
			
			ph_cycle_end_0:
			
			PHALCON_INIT_VAR(comma);
			ZVAL_STRING(comma, ",", 1);
			
			PHALCON_INIT_VAR(function_args);
			phalcon_fast_join(function_args, comma, arguments_expr TSRMLS_CC);
		} else {
			PHALCON_INIT_VAR(argument_expr);
			PHALCON_CALL_METHOD_PARAMS_2(argument_expr, this_ptr, "_getcallargument", arguments, sql_aliases, PH_NO_CHECK);
			PHALCON_CPY_WRT(function_args, argument_expr);
		}
		
		PHALCON_INIT_VAR(function_call);
		PHALCON_CONCAT_VSVS(function_call, name, "(", function_args, ")");
	} else {
		PHALCON_INIT_VAR(function_call);
		PHALCON_CONCAT_VS(function_call, name, "()");
	}
	
	
	RETURN_CTOR(function_call);
}

/**
 * Resolves an expression from its intermediate code into a string
 *
 * @param array $expr
 * @param array $sqlAliases
 * @param boolean $quoting
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getExpression){

	zval *expr = NULL, *sql_aliases = NULL, *quoting = NULL, *expr_left = NULL;
	zval *left = NULL, *expr_right = NULL, *right = NULL, *expr_type = NULL, *expr_return = NULL;
	zval *value = NULL, *question_mark = NULL, *empty_string = NULL, *numeric_place = NULL;
	zval *expression_message = NULL, *expression = NULL, *expr_domain = NULL;
	zval *list_items = NULL, *expr_list_item = NULL, *expr_item = NULL;
	zval *joined_list = NULL;
	zval *c0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &expr, &sql_aliases, &quoting) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!quoting) {
		PHALCON_ALLOC_ZVAL_MM(quoting);
		ZVAL_BOOL(quoting, 1);
	}
	
	eval_int = phalcon_array_isset_string(expr, SS("type"));
	if (eval_int) {
		eval_int = phalcon_array_isset_string(expr, SS("left"));
		if (eval_int) {
			PHALCON_INIT_VAR(expr_left);
			phalcon_array_fetch_string(&expr_left, expr, SL("left"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(left);
			PHALCON_CALL_METHOD_PARAMS_2(left, this_ptr, "_getexpression", expr_left, sql_aliases, PH_NO_CHECK);
		}
		eval_int = phalcon_array_isset_string(expr, SS("right"));
		if (eval_int) {
			PHALCON_INIT_VAR(expr_right);
			phalcon_array_fetch_string(&expr_right, expr, SL("right"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(right);
			PHALCON_CALL_METHOD_PARAMS_2(right, this_ptr, "_getexpression", expr_right, sql_aliases, PH_NO_CHECK);
		}
		
		PHALCON_INIT_VAR(expr_type);
		phalcon_array_fetch_string(&expr_type, expr, SL("type"), PH_NOISY_CC);
		
		if (phalcon_compare_strict_long(expr_type, 60 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "<", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 61 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "=", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 62 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, ">", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 270 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "<>", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 271 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "<=", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 272 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, ">=", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 266 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, " AND ", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 267 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, " OR ", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 43 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "+", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 45 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "-", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 42 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "*", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 47 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "/", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 37 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "%", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 356 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_SVS(expr_return, "(", left, ")");
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 367 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_SV(expr_return, "-", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 355 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CALL_METHOD_PARAMS_2(expr_return, this_ptr, "_getqualified", expr, sql_aliases, PH_NO_CHECK);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 258 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			phalcon_array_fetch_string(&expr_return, expr, SL("value"), PH_NOISY_CC);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 259 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			phalcon_array_fetch_string(&expr_return, expr, SL("value"), PH_NOISY_CC);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 260 TSRMLS_CC)) {
			PHALCON_INIT_VAR(value);
			phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
			if (PHALCON_IS_TRUE(quoting)) {
				PHALCON_INIT_VAR(expr_return);
				PHALCON_CONCAT_SVS(expr_return, "'", value, "'");
			} else {
				PHALCON_CPY_WRT(expr_return, value);
			}
			
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 273 TSRMLS_CC)) {
			PHALCON_INIT_VAR(value);
			phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(question_mark);
			ZVAL_STRING(question_mark, "?", 1);
			
			PHALCON_INIT_VAR(empty_string);
			ZVAL_STRING(empty_string, "", 1);
			
			PHALCON_INIT_VAR(numeric_place);
			phalcon_fast_str_replace(numeric_place, question_mark, empty_string, value TSRMLS_CC);
			
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_SV(expr_return, ":", numeric_place);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 274 TSRMLS_CC)) {
			PHALCON_INIT_VAR(value);
			phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_SV(expr_return, ":", value);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 322 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			ZVAL_STRING(expr_return, "NULL", 1);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 268 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, " LIKE ", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 351 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, " NOT LIKE ", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 33 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_SV(expr_return, "NOT ", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 365 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VS(expr_return, left, " IS NULL");
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 366 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VS(expr_return, left, " IS NOT NULL");
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 315 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, " IN ", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 323 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, " NOT IN ", right);
			goto ph_end_0;
		}
		
		if (phalcon_compare_strict_long(expr_type, 350 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CALL_METHOD_PARAMS_2(expr_return, this_ptr, "_getfunctioncall", expr, sql_aliases, PH_NO_CHECK);
			goto ph_end_0;
		}
		
		PHALCON_INIT_VAR(expression_message);
		PHALCON_CONCAT_SV(expression_message, "Unkown expression type ", expr_type);
		
		PHALCON_INIT_VAR(expression);
		object_init_ex(expression, phalcon_mvc_model_exception_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(expression, "__construct", expression_message, PH_CHECK);
		phalcon_throw_exception(expression TSRMLS_CC);
		return;
		
		ph_end_0:
		
		RETURN_CCTOR(expr_return);
	}
	eval_int = phalcon_array_isset_string(expr, SS("domain"));
	if (eval_int) {
		PHALCON_INIT_VAR(expr_domain);
		PHALCON_CALL_METHOD_PARAMS_2(expr_domain, this_ptr, "_getqualified", expr, sql_aliases, PH_NO_CHECK);
		
		RETURN_CCTOR(expr_domain);
	}
	
	eval_int = phalcon_array_isset_long(expr, 0);
	if (eval_int) {
		PHALCON_INIT_VAR(list_items);
		array_init(list_items);
		
		if (!phalcon_valid_foreach(expr TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(expr);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_1:
		
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto ph_cycle_end_1;
			}
			
			PHALCON_GET_FOREACH_VALUE(expr_list_item);
			
			PHALCON_INIT_VAR(expr_item);
			PHALCON_CALL_METHOD_PARAMS_2(expr_item, this_ptr, "_getexpression", expr_list_item, sql_aliases, PH_NO_CHECK);
			phalcon_array_append(&list_items, expr_item, PH_SEPARATE TSRMLS_CC);
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_1;
		
		ph_cycle_end_1:
		
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, ",", 1);
		
		PHALCON_INIT_VAR(joined_list);
		phalcon_fast_join(joined_list, c0, list_items TSRMLS_CC);
		
		PHALCON_INIT_VAR(expr_return);
		PHALCON_CONCAT_SVS(expr_return, "(", joined_list, ")");
		
		RETURN_CCTOR(expr_return);
	}
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Unknown expression");
	return;
}

/**
 * Resolves a column from its intermediate representation into an array used to determine
 * if the resulset produced will be simple or complex
 *
 * @param array $column
 * @param array $models
 * @param array $sqlAliases
 * @param array $sqlAliasesModels
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getSelectColumn){

	zval *column = NULL, *models = NULL, *sql_aliases = NULL, *sql_aliases_models = NULL;
	zval *sql_columns = NULL, *column_type = NULL, *source = NULL, *model_name = NULL;
	zval *sql_column_alias = NULL, *sql_column = NULL, *column_domain = NULL;
	zval *exception_message = NULL, *exception = NULL, *type = NULL, *name = NULL;
	zval *sql_expr_column = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &column, &models, &sql_aliases, &sql_aliases_models) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(column);
	
	eval_int = phalcon_array_isset_string(column, SS("type"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	PHALCON_INIT_VAR(sql_columns);
	array_init(sql_columns);
	
	PHALCON_INIT_VAR(column_type);
	phalcon_array_fetch_string(&column_type, column, SL("type"), PH_NOISY_CC);
	if (phalcon_compare_strict_long(column_type, 352 TSRMLS_CC)) {
		
		if (!phalcon_valid_foreach(models TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(models);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto ph_cycle_end_0;
			}
			
			PHALCON_INIT_VAR(model_name);
			PHALCON_GET_FOREACH_KEY(model_name, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(source);
			
			PHALCON_CPY_WRT(sql_column_alias, source);
			
			PHALCON_INIT_VAR(sql_column);
			array_init(sql_column);
			add_assoc_stringl_ex(sql_column, SS("type"), SL("object"), 1);
			phalcon_array_update_string(&sql_column, SL("model"), &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&sql_column, SL("column"), &sql_column_alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_columns, sql_column, PH_SEPARATE TSRMLS_CC);
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
		
		ph_cycle_end_0:
		
		
		RETURN_CTOR(sql_columns);
	}
	
	eval_int = phalcon_array_isset_string(column, SS("column"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	if (phalcon_compare_strict_long(column_type, 353 TSRMLS_CC)) {
		PHALCON_INIT_VAR(column_domain);
		phalcon_array_fetch_string(&column_domain, column, SL("column"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(sql_aliases, column_domain);
		if (!eval_int) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Unknown table or alias '", column_domain, "'");
			
			PHALCON_INIT_VAR(exception);
			object_init_ex(exception, phalcon_mvc_model_exception_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
			phalcon_throw_exception(exception TSRMLS_CC);
			return;
		}
		
		PHALCON_INIT_VAR(source);
		phalcon_array_fetch(&source, sql_aliases, column_domain, PH_NOISY_CC);
		PHALCON_CPY_WRT(sql_column_alias, source);
		
		PHALCON_INIT_VAR(model_name);
		phalcon_array_fetch(&model_name, sql_aliases_models, column_domain, PH_NOISY_CC);
		
		PHALCON_INIT_VAR(sql_column);
		array_init(sql_column);
		add_assoc_stringl_ex(sql_column, SS("type"), SL("object"), 1);
		phalcon_array_update_string(&sql_column, SL("model"), &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&sql_column, SL("column"), &sql_column_alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&sql_columns, sql_column, PH_SEPARATE TSRMLS_CC);
		
		RETURN_CTOR(sql_columns);
	}
	
	if (phalcon_compare_strict_long(column_type, 354 TSRMLS_CC)) {
		PHALCON_INIT_VAR(sql_column);
		array_init(sql_column);
		add_assoc_stringl_ex(sql_column, SS("type"), SL("scalar"), 1);
		
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, column, SL("column"), PH_NOISY_CC);
		PHALCON_CPY_WRT(column, r0);
		eval_int = phalcon_array_isset_string(column, SS("type"));
		if (eval_int) {
			PHALCON_INIT_VAR(type);
			phalcon_array_fetch_string(&type, column, SL("type"), PH_NOISY_CC);
			if (phalcon_compare_strict_long(type, 355 TSRMLS_CC)) {
				PHALCON_INIT_VAR(name);
				phalcon_array_fetch_string(&name, column, SL("name"), PH_NOISY_CC);
				phalcon_array_update_string(&sql_column, SL("balias"), &name, PH_COPY | PH_SEPARATE TSRMLS_CC);
			}
		}
		
		PHALCON_INIT_VAR(sql_expr_column);
		PHALCON_CALL_METHOD_PARAMS_2(sql_expr_column, this_ptr, "_getexpression", column, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_column, SL("column"), &sql_expr_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&sql_columns, sql_column, PH_SEPARATE TSRMLS_CC);
		
		RETURN_CTOR(sql_columns);
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SV(exception_message, "Unknown type of column ", column_type);
	
	PHALCON_INIT_VAR(exception);
	object_init_ex(exception, phalcon_mvc_model_exception_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
	phalcon_throw_exception(exception TSRMLS_CC);
	return;
}

/**
 * Resolves a table in a SELECT statement checking if the model exists
 *
 * @param Phalcon\Mvc\Model $manager
 * @param array $qualifiedName
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getTable){

	zval *manager = NULL, *qualified_name = NULL, *model_name = NULL;
	zval *model = NULL, *source = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &manager, &qualified_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(qualified_name, SS("name"));
	if (eval_int) {
		PHALCON_INIT_VAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(model);
		PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(source);
		PHALCON_CALL_METHOD(source, model, "getsource", PH_NO_CHECK);
		
		RETURN_CCTOR(source);
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
	return;
}

/**
 * Resolves a JOIN clause checking if the associated models exist
 *
 * @param Phalcon\Mvc\Model $manager
 * @param array $join
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoin){

	zval *manager = NULL, *join = NULL, *qualified = NULL, *qualified_type = NULL;
	zval *model_name = NULL, *model = NULL, *source = NULL, *data = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &manager, &join) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(join, SS("qualifiedName"));
	if (eval_int) {
		PHALCON_INIT_VAR(qualified);
		phalcon_array_fetch_string(&qualified, join, SL("qualifiedName"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(qualified_type);
		phalcon_array_fetch_string(&qualified_type, qualified, SL("type"), PH_NOISY_CC);
		if (phalcon_compare_strict_long(qualified_type, 355 TSRMLS_CC)) {
			PHALCON_INIT_VAR(model_name);
			phalcon_array_fetch_string(&model_name, qualified, SL("name"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(model);
			PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(source);
			PHALCON_CALL_METHOD(source, model, "getsource", PH_NO_CHECK);
			
			PHALCON_INIT_VAR(data);
			array_init(data);
			phalcon_array_update_string(&data, SL("source"), &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&data, SL("model"), &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			RETURN_CTOR(data);
		}
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
	return;
}

/**
 * Resolves a JOIN type
 *
 * @param array $join
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoinType){

	zval *join = NULL, *type = NULL, *join_type = NULL, *exception_message = NULL;
	zval *exception = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &join) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(join, SS("type"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	PHALCON_INIT_VAR(type);
	phalcon_array_fetch_string(&type, join, SL("type"), PH_NOISY_CC);
	
	if (phalcon_compare_strict_long(type, 360 TSRMLS_CC)) {
		PHALCON_INIT_VAR(join_type);
		ZVAL_STRING(join_type, "INNER", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 361 TSRMLS_CC)) {
		PHALCON_INIT_VAR(join_type);
		ZVAL_STRING(join_type, "LEFT", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 362 TSRMLS_CC)) {
		PHALCON_INIT_VAR(join_type);
		ZVAL_STRING(join_type, "RIGHT", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 363 TSRMLS_CC)) {
		PHALCON_INIT_VAR(join_type);
		ZVAL_STRING(join_type, "CROSS", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 364 TSRMLS_CC)) {
		PHALCON_INIT_VAR(join_type);
		ZVAL_STRING(join_type, "FULL OUTER", 1);
		goto ph_end_0;
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SV(exception_message, "Unknown join type ", type);
	
	PHALCON_INIT_VAR(exception);
	object_init_ex(exception, phalcon_mvc_model_exception_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
	phalcon_throw_exception(exception TSRMLS_CC);
	return;
	
	ph_end_0:
	
	RETURN_CTOR(join_type);
}

/**
 * Resolves all the JOINS in a SELECT statement
 *
 * @param array $select
 * @param Phalcon\Mvc\Model $manager
 * @param array $models
 * @param array $sqlModels
 * @param array $sqlAliases
 * @param array $sqlAliasesModels
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoins){

	zval *select = NULL, *manager = NULL, *models = NULL, *sql_models = NULL, *sql_aliases = NULL;
	zval *sql_aliases_models = NULL, *sql_joins = NULL, *join_models = NULL;
	zval *join_sources = NULL, *join_types = NULL, *join_pre_condition = NULL;
	zval *joins = NULL, *select_joins = NULL, *join_item = NULL, *join = NULL, *join_data = NULL;
	zval *source = NULL, *model_name = NULL, *join_type = NULL, *alias = NULL, *source_alias = NULL;
	zval *join_expr = NULL, *pre_condition = NULL, *join_alias = NULL;
	zval *join_model = NULL, *has_relations = NULL, *sql_join_conditions = NULL;
	zval *relations = NULL, *fields = NULL, *referenced_fields = NULL;
	zval *sql_join_condition = NULL, *join_source = NULL, *sql_join = NULL;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzzzz", &select, &manager, &models, &sql_models, &sql_aliases, &sql_aliases_models) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(sql_models);
	
	PHALCON_SEPARATE_PARAM(sql_aliases);
	
	PHALCON_SEPARATE_PARAM(sql_aliases_models);
	
	PHALCON_INIT_VAR(sql_joins);
	array_init(sql_joins);
	
	PHALCON_INIT_VAR(join_models);
	array_init(join_models);
	
	PHALCON_INIT_VAR(join_sources);
	array_init(join_sources);
	
	PHALCON_INIT_VAR(join_types);
	array_init(join_types);
	
	PHALCON_INIT_VAR(join_pre_condition);
	array_init(join_pre_condition);
	
	PHALCON_INIT_VAR(joins);
	phalcon_array_fetch_string(&joins, select, SL("joins"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(joins, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(select_joins);
		array_init(select_joins);
		phalcon_array_append(&select_joins, joins, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(select_joins, joins);
	}
	
	
	if (!phalcon_valid_foreach(select_joins TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(select_joins);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(join_item);
		
		PHALCON_INIT_VAR(join);
		phalcon_array_fetch_string(&join, join_item, SL("join"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(join_data);
		PHALCON_CALL_METHOD_PARAMS_2(join_data, this_ptr, "_getjoin", manager, join, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(source);
		phalcon_array_fetch_string(&source, join_data, SL("source"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(model_name);
		phalcon_array_fetch_string(&model_name, join_data, SL("model"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(join_type);
		PHALCON_CALL_METHOD_PARAMS_1(join_type, this_ptr, "_getjointype", join, PH_NO_CHECK);
		phalcon_array_update_zval(&join_types, model_name, &join_type, PH_COPY | PH_SEPARATE TSRMLS_CC);
		eval_int = phalcon_array_isset_string(joins, SS("alias"));
		if (eval_int) {
			PHALCON_INIT_VAR(alias);
			phalcon_array_fetch_string(&alias, joins, SL("alias"), PH_NOISY_CC);
			phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&join_models, model_name, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(source_alias);
			PHALCON_CONCAT_VSV(source_alias, source, " ", alias);
			phalcon_array_update_zval(&join_sources, model_name, &source_alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&sql_aliases_models, alias, &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&join_models, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&join_sources, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&sql_aliases_models, model_name, &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		phalcon_array_append(&sql_models, model_name, PH_SEPARATE TSRMLS_CC);
		eval_int = phalcon_array_isset_string(join, SS("expr"));
		if (eval_int) {
			PHALCON_INIT_VAR(join_expr);
			phalcon_array_fetch_string(&join_expr, join, SL("expr"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(pre_condition);
			PHALCON_CALL_METHOD_PARAMS_2(pre_condition, this_ptr, "_getexpression", join_expr, sql_aliases, PH_NO_CHECK);
			phalcon_array_update_zval(&join_pre_condition, model_name, &pre_condition, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	
	if (!phalcon_valid_foreach(join_models TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(join_models);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
	ph_cycle_start_1:
	
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto ph_cycle_end_1;
		}
		
		PHALCON_INIT_VAR(join_model);
		PHALCON_GET_FOREACH_KEY(join_model, ah1, hp1);
		PHALCON_GET_FOREACH_VALUE(join_alias);
		
		PHALCON_INIT_VAR(has_relations);
		ZVAL_BOOL(has_relations, 0);
		
		if (!phalcon_valid_foreach(models TSRMLS_CC)) {
			return;
		}
		
		ah2 = Z_ARRVAL_P(models);
		zend_hash_internal_pointer_reset_ex(ah2, &hp2);
		
		ph_cycle_start_2:
		
			if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
				goto ph_cycle_end_2;
			}
			
			PHALCON_INIT_VAR(model_name);
			PHALCON_GET_FOREACH_KEY(model_name, ah2, hp2);
			PHALCON_GET_FOREACH_VALUE(source);
			
			PHALCON_INIT_VAR(sql_join_conditions);
			array_init(sql_join_conditions);
			eval_int = phalcon_array_isset(join_pre_condition, join_model);
			if (!eval_int) {
				PHALCON_INIT_VAR(relations);
				PHALCON_CALL_METHOD_PARAMS_2(relations, manager, "getrelations", model_name, join_model, PH_NO_CHECK);
				if (PHALCON_IS_NOT_FALSE(relations)) {
					PHALCON_INIT_VAR(fields);
					phalcon_array_fetch_string(&fields, relations, SL("fi"), PH_NOISY_CC);
					
					PHALCON_INIT_VAR(referenced_fields);
					phalcon_array_fetch_string(&referenced_fields, relations, SL("rf"), PH_NOISY_CC);
					if (Z_TYPE_P(fields) == IS_ARRAY) { 
						PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Not implemented yet");
						return;
					} else {
						PHALCON_INIT_VAR(sql_join_condition);
						PHALCON_CONCAT_VSVSVSV(sql_join_condition, source, ".", fields, "=", join_alias, ".", referenced_fields);
						phalcon_array_append(&sql_join_conditions, sql_join_condition, PH_SEPARATE TSRMLS_CC);
					}
				}
			} else {
				PHALCON_INIT_VAR(pre_condition);
				phalcon_array_fetch(&pre_condition, join_pre_condition, join_model, PH_NOISY_CC);
				phalcon_array_append(&sql_join_conditions, pre_condition, PH_SEPARATE TSRMLS_CC);
			}
			
			PHALCON_INIT_VAR(join_type);
			phalcon_array_fetch(&join_type, join_types, join_model, PH_NOISY_CC);
			
			PHALCON_INIT_VAR(join_source);
			phalcon_array_fetch(&join_source, join_sources, join_model, PH_NOISY_CC);
			
			PHALCON_INIT_VAR(sql_join);
			array_init(sql_join);
			phalcon_array_update_string(&sql_join, SL("type"), &join_type, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&sql_join, SL("source"), &join_source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&sql_join, SL("conditions"), &sql_join_conditions, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_joins, sql_join, PH_SEPARATE TSRMLS_CC);
			
			zend_hash_move_forward_ex(ah2, &hp2);
			goto ph_cycle_start_2;
		
		ph_cycle_end_2:
		
		
		zend_hash_move_forward_ex(ah1, &hp1);
		goto ph_cycle_start_1;
	
	ph_cycle_end_1:
	
	phalcon_update_property_zval(this_ptr, SL("_tempSQLModels"), sql_models TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_tempSQLAliases"), sql_aliases TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_tempSQLAliasesModels"), sql_aliases_models TSRMLS_CC);
	
	RETURN_CTOR(sql_joins);
}

/**
 * Returns a processed limit clause for a SELECT statement
 *
 * @param array $limit
 * @param array $sqlAliases
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getLimitClause){

	zval *limit = NULL, *sql_aliases = NULL, *limit_expr = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &limit, &sql_aliases) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(limit_expr);
	PHALCON_CALL_METHOD_PARAMS_2(limit_expr, this_ptr, "_getexpression", limit, sql_aliases, PH_NO_CHECK);
	
	RETURN_CCTOR(limit_expr);
}

/**
 * Returns a processed order clause for a SELECT statement
 *
 * @param array $order
 * @param array $sqlAliases
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getOrderClause){

	zval *order = NULL, *sql_aliases = NULL, *order_columns = NULL, *order_parts = NULL;
	zval *order_item = NULL, *order_column = NULL, *order_part_expr = NULL;
	zval *order_sort = NULL, *order_part_sort = NULL, *order_expr = NULL;
	zval *c0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &order, &sql_aliases) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_long(order, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(order_columns);
		array_init(order_columns);
		phalcon_array_append(&order_columns, order, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(order_columns, order);
	}
	
	PHALCON_INIT_VAR(order_parts);
	array_init(order_parts);
	
	if (!phalcon_valid_foreach(order_columns TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(order_columns);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(order_item);
		
		PHALCON_INIT_VAR(order_column);
		phalcon_array_fetch_string(&order_column, order_item, SL("column"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(order_part_expr);
		PHALCON_CALL_METHOD_PARAMS_2(order_part_expr, this_ptr, "_getexpression", order_column, sql_aliases, PH_NO_CHECK);
		eval_int = phalcon_array_isset_string(order_item, SS("sort"));
		if (eval_int) {
			PHALCON_INIT_VAR(order_sort);
			phalcon_array_fetch_string(&order_sort, order_item, SL("sort"), PH_NOISY_CC);
			if (phalcon_compare_strict_long(order_sort, 327 TSRMLS_CC)) {
				PHALCON_INIT_VAR(order_part_sort);
				PHALCON_CONCAT_VS(order_part_sort, order_part_expr, " ASC");
			} else {
				PHALCON_INIT_VAR(order_part_sort);
				PHALCON_CONCAT_VS(order_part_sort, order_part_expr, " DESC");
			}
			
			phalcon_array_append(&order_parts, order_part_sort, PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_append(&order_parts, order_part_expr, PH_SEPARATE TSRMLS_CC);
		}
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, ",", 1);
	
	PHALCON_INIT_VAR(order_expr);
	phalcon_fast_join(order_expr, c0, order_parts TSRMLS_CC);
	
	RETURN_CTOR(order_expr);
}

/**
 * Returns a processed group clause for a SELECT statement
 *
 * @param array $order
 * @param array $sqlAliases
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _getGroupClause){

	zval *order = NULL, *sql_aliases = NULL, *order_parts = NULL, *order_item = NULL;
	zval *order_part_expr = NULL, *order_expr = NULL;
	zval *c0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &order, &sql_aliases) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_long(order, 0);
	if (eval_int) {
		PHALCON_INIT_VAR(order_parts);
		array_init(order_parts);
		
		if (!phalcon_valid_foreach(order TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(order);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_VALUE(order_item);
			
			PHALCON_INIT_VAR(order_part_expr);
			PHALCON_CALL_METHOD_PARAMS_2(order_part_expr, this_ptr, "_getexpression", order_item, sql_aliases, PH_NO_CHECK);
			phalcon_array_append(&order_parts, order_part_expr, PH_SEPARATE TSRMLS_CC);
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
		
		ph_cycle_end_0:
		
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, ",", 1);
		
		PHALCON_INIT_VAR(order_expr);
		phalcon_fast_join(order_expr, c0, order_parts TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(order_expr);
		PHALCON_CALL_METHOD_PARAMS_2(order_expr, this_ptr, "_getexpression", order, sql_aliases, PH_NO_CHECK);
	}
	
	RETURN_CCTOR(order_expr);
}

/**
 * Analyzes a SELECT intermediate code and produces an array to be executed later
 *
 * @param Phalcon\Mvc\Model $manager
 * @param array $ast
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareSelect){

	zval *manager = NULL, *ast = NULL, *select = NULL, *sql_models = NULL, *sql_tables = NULL;
	zval *sql_aliases = NULL, *sql_aliases_models = NULL, *models = NULL;
	zval *tables = NULL, *select_tables = NULL, *table = NULL, *qualified_name = NULL;
	zval *model_name = NULL, *source = NULL, *alias = NULL, *source_alias = NULL;
	zval *sql_joins = NULL, *sql_columns = NULL, *columns = NULL, *select_columns = NULL;
	zval *position = NULL, *column = NULL, *sql_column_group = NULL, *sql_column = NULL;
	zval *type = NULL, *sql_select = NULL, *number_joins = NULL, *where = NULL;
	zval *where_expr = NULL, *group_by = NULL, *sql_group = NULL, *having = NULL;
	zval *having_expr = NULL, *order = NULL, *sql_order = NULL, *limit = NULL, *sql_limit = NULL;
	zval *r0 = NULL;
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL, NULL };
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &manager, &ast) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(select);
	phalcon_array_fetch_string(&select, ast, SL("select"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(select, SS("tables"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	eval_int = phalcon_array_isset_string(select, SS("columns"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	PHALCON_INIT_VAR(sql_models);
	array_init(sql_models);
	
	PHALCON_INIT_VAR(sql_tables);
	array_init(sql_tables);
	
	PHALCON_INIT_VAR(sql_aliases);
	array_init(sql_aliases);
	
	PHALCON_INIT_VAR(sql_aliases_models);
	array_init(sql_aliases_models);
	
	PHALCON_INIT_VAR(models);
	array_init(models);
	
	PHALCON_INIT_VAR(tables);
	phalcon_array_fetch_string(&tables, select, SL("tables"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(tables, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(select_tables);
		array_init(select_tables);
		phalcon_array_append(&select_tables, tables, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(select_tables, tables);
	}
	
	
	if (!phalcon_valid_foreach(select_tables TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(select_tables);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(table);
		
		PHALCON_INIT_VAR(qualified_name);
		phalcon_array_fetch_string(&qualified_name, table, SL("qualifiedName"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(source);
		PHALCON_CALL_METHOD_PARAMS_2(source, this_ptr, "_gettable", manager, qualified_name, PH_NO_CHECK);
		eval_int = phalcon_array_isset_string(table, SS("alias"));
		if (eval_int) {
			PHALCON_INIT_VAR(alias);
			phalcon_array_fetch_string(&alias, table, SL("alias"), PH_NOISY_CC);
			phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&sql_aliases_models, alias, &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(source_alias);
			PHALCON_CONCAT_VSV(source_alias, source, " ", alias);
			phalcon_array_append(&sql_tables, source_alias, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&models, model_name, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&sql_aliases_models, model_name, &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_tables, source, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&models, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		phalcon_array_append(&sql_models, model_name, PH_SEPARATE TSRMLS_CC);
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	eval_int = phalcon_array_isset_string(select, SS("joins"));
	if (eval_int) {
		p0[0] = select;
		p0[1] = manager;
		p0[2] = models;
		p0[3] = sql_models;
		p0[4] = sql_aliases;
		p0[5] = sql_aliases_models;
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_getjoins", 6, p0, PH_NO_CHECK);
		PHALCON_CPY_WRT(sql_joins, r0);
		
		PHALCON_INIT_VAR(sql_aliases);
		phalcon_read_property(&sql_aliases, this_ptr, SL("_tempSQLAliases"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(sql_aliases_models);
		phalcon_read_property(&sql_aliases_models, this_ptr, SL("_tempSQLAliasesModels"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(sql_models);
		phalcon_read_property(&sql_models, this_ptr, SL("_tempSQLModels"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(sql_joins);
		array_init(sql_joins);
	}
	
	PHALCON_INIT_VAR(sql_columns);
	array_init(sql_columns);
	
	PHALCON_INIT_VAR(columns);
	phalcon_array_fetch_string(&columns, select, SL("columns"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(columns, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(select_columns);
		array_init(select_columns);
		phalcon_array_append(&select_columns, columns, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(select_columns, columns);
	}
	
	PHALCON_INIT_VAR(position);
	ZVAL_LONG(position, 0);
	
	if (!phalcon_valid_foreach(select_columns TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(select_columns);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
	ph_cycle_start_1:
	
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto ph_cycle_end_1;
		}
		
		PHALCON_GET_FOREACH_VALUE(column);
		
		PHALCON_INIT_VAR(sql_column_group);
		PHALCON_CALL_METHOD_PARAMS_4(sql_column_group, this_ptr, "_getselectcolumn", column, models, sql_aliases, sql_aliases_models, PH_NO_CHECK);
		
		if (!phalcon_valid_foreach(sql_column_group TSRMLS_CC)) {
			return;
		}
		
		ah2 = Z_ARRVAL_P(sql_column_group);
		zend_hash_internal_pointer_reset_ex(ah2, &hp2);
		
		ph_cycle_start_2:
		
			if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
				goto ph_cycle_end_2;
			}
			
			PHALCON_GET_FOREACH_VALUE(sql_column);
			
			eval_int = phalcon_array_isset_string(column, SS("alias"));
			if (eval_int) {
				PHALCON_INIT_VAR(alias);
				phalcon_array_fetch_string(&alias, column, SL("alias"), PH_NOISY_CC);
				phalcon_array_update_string(&sql_column, SL("balias"), &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_zval(&sql_columns, alias, &sql_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
			} else {
				eval_int = phalcon_array_isset_string(sql_column, SS("balias"));
				if (eval_int) {
					PHALCON_INIT_VAR(alias);
					phalcon_array_fetch_string(&alias, sql_column, SL("balias"), PH_NOISY_CC);
					phalcon_array_update_zval(&sql_columns, alias, &sql_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
				} else {
					PHALCON_INIT_VAR(type);
					phalcon_array_fetch_string(&type, sql_column, SL("type"), PH_NOISY_CC);
					if (PHALCON_COMPARE_STRING(type, "scalar")) {
						PHALCON_INIT_VAR(alias);
						PHALCON_CONCAT_SV(alias, "_", position);
						phalcon_array_update_zval(&sql_columns, alias, &sql_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
					} else {
						phalcon_array_append(&sql_columns, sql_column, PH_SEPARATE TSRMLS_CC);
					}
				}
			}
			PHALCON_SEPARATE(position);
			increment_function(position);
			
			zend_hash_move_forward_ex(ah2, &hp2);
			goto ph_cycle_start_2;
		
		ph_cycle_end_2:
		
		
		zend_hash_move_forward_ex(ah1, &hp1);
		goto ph_cycle_start_1;
	
	ph_cycle_end_1:
	
	PHALCON_INIT_VAR(sql_select);
	array_init(sql_select);
	phalcon_array_update_string(&sql_select, SL("models"), &sql_models, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_select, SL("tables"), &sql_tables, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_select, SL("columns"), &sql_columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(number_joins);
	phalcon_fast_count(number_joins, sql_joins TSRMLS_CC);
	if (!phalcon_compare_strict_long(number_joins, 0 TSRMLS_CC)) {
		phalcon_array_update_string(&sql_select, SL("joins"), &sql_joins, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(ast, SS("where"));
	if (eval_int) {
		PHALCON_INIT_VAR(where);
		phalcon_array_fetch_string(&where, ast, SL("where"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(where_expr);
		PHALCON_CALL_METHOD_PARAMS_2(where_expr, this_ptr, "_getexpression", where, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_select, SL("where"), &where_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(ast, SS("groupBy"));
	if (eval_int) {
		PHALCON_INIT_VAR(group_by);
		phalcon_array_fetch_string(&group_by, ast, SL("groupBy"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(sql_group);
		PHALCON_CALL_METHOD_PARAMS_2(sql_group, this_ptr, "_getgroupclause", group_by, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_select, SL("group"), &sql_group, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(ast, SS("having"));
	if (eval_int) {
		PHALCON_INIT_VAR(having);
		phalcon_array_fetch_string(&having, ast, SL("having"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(having_expr);
		PHALCON_CALL_METHOD_PARAMS_2(having_expr, this_ptr, "_getexpression", having, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_select, SL("having"), &having_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(ast, SS("orderBy"));
	if (eval_int) {
		PHALCON_INIT_VAR(order);
		phalcon_array_fetch_string(&order, ast, SL("orderBy"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(sql_order);
		PHALCON_CALL_METHOD_PARAMS_2(sql_order, this_ptr, "_getorderclause", order, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_select, SL("order"), &sql_order, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(ast, SS("limit"));
	if (eval_int) {
		PHALCON_INIT_VAR(limit);
		phalcon_array_fetch_string(&limit, ast, SL("limit"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(sql_limit);
		PHALCON_CALL_METHOD_PARAMS_2(sql_limit, this_ptr, "_getlimitclause", limit, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_select, SL("limit"), &sql_limit, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	
	RETURN_CTOR(sql_select);
}

/**
 * Analyzes an INSERT intermediate code and produces an array to be executed later
 *
 * @param Phalcon\Mvc\Model $manager
 * @param array $ast
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareInsert){

	zval *manager = NULL, *ast = NULL, *qualified_name = NULL, *model_name = NULL;
	zval *source = NULL, *sql_aliases = NULL, *expr_values = NULL, *values = NULL;
	zval *not_quoting = NULL, *expr_value = NULL, *expr_insert = NULL;
	zval *expr_type = NULL, *value = NULL, *sql_insert = NULL, *sql_fields = NULL;
	zval *fields = NULL, *field = NULL, *name = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &manager, &ast) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(ast, SS("qualifiedName"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST");
		return;
	}
	eval_int = phalcon_array_isset_string(ast, SS("values"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST");
		return;
	}
	
	PHALCON_INIT_VAR(qualified_name);
	phalcon_array_fetch_string(&qualified_name, ast, SL("qualifiedName"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(model_name);
	phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD_PARAMS_2(source, this_ptr, "_gettable", manager, qualified_name, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(sql_aliases);
	array_init(sql_aliases);
	
	PHALCON_INIT_VAR(expr_values);
	array_init(expr_values);
	
	PHALCON_INIT_VAR(values);
	phalcon_array_fetch_string(&values, ast, SL("values"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(not_quoting);
	ZVAL_BOOL(not_quoting, 0);
	
	if (!phalcon_valid_foreach(values TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(values);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(expr_value);
		
		PHALCON_INIT_VAR(expr_insert);
		PHALCON_CALL_METHOD_PARAMS_3(expr_insert, this_ptr, "_getexpression", expr_value, sql_aliases, not_quoting, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(expr_type);
		phalcon_array_fetch_string(&expr_type, expr_value, SL("type"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(value);
		array_init(value);
		phalcon_array_update_string(&value, SL("type"), &expr_type, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&value, SL("value"), &expr_insert, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&expr_values, value, PH_SEPARATE TSRMLS_CC);
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(sql_insert);
	array_init(sql_insert);
	phalcon_array_update_string(&sql_insert, SL("model"), &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_insert, SL("table"), &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
	eval_int = phalcon_array_isset_string(ast, SS("fields"));
	if (eval_int) {
		PHALCON_INIT_VAR(sql_fields);
		array_init(sql_fields);
		
		PHALCON_INIT_VAR(fields);
		phalcon_array_fetch_string(&fields, ast, SL("fields"), PH_NOISY_CC);
		
		if (!phalcon_valid_foreach(fields TSRMLS_CC)) {
			return;
		}
		
		ah1 = Z_ARRVAL_P(fields);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		
		ph_cycle_start_1:
		
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto ph_cycle_end_1;
			}
			
			PHALCON_GET_FOREACH_VALUE(field);
			
			PHALCON_INIT_VAR(name);
			phalcon_array_fetch_string(&name, field, SL("name"), PH_NOISY_CC);
			phalcon_array_append(&sql_fields, name, PH_SEPARATE TSRMLS_CC);
			
			zend_hash_move_forward_ex(ah1, &hp1);
			goto ph_cycle_start_1;
		
		ph_cycle_end_1:
		
		phalcon_array_update_string(&sql_insert, SL("fields"), &sql_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	phalcon_array_update_string(&sql_insert, SL("values"), &expr_values, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	RETURN_CTOR(sql_insert);
}

/**
 * Analyzes an UPDATE intermediate code and produces an array to be executed later
 *
 * @param Phalcon\Mvc\Model $manager
 * @param array $ast
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareUpdate){

	zval *manager = NULL, *ast = NULL, *update = NULL, *models = NULL, *sql_aliases = NULL;
	zval *sql_tables = NULL, *tables = NULL, *update_tables = NULL, *table = NULL;
	zval *qualified_name = NULL, *model_name = NULL, *source = NULL, *alias = NULL;
	zval *source_alias = NULL, *sql_fields = NULL, *sql_values = NULL;
	zval *values = NULL, *update_values = NULL, *not_quoting = NULL, *update_value = NULL;
	zval *column = NULL, *sql_column = NULL, *expr_column = NULL, *expr_value = NULL;
	zval *type = NULL, *value = NULL, *sql_update = NULL, *where = NULL, *where_expr = NULL;
	zval *limit = NULL, *sql_limit = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &manager, &ast) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(ast, SS("update"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST");
		return;
	}
	
	PHALCON_INIT_VAR(update);
	phalcon_array_fetch_string(&update, ast, SL("update"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(update, SS("tables"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST");
		return;
	}
	
	eval_int = phalcon_array_isset_string(update, SS("values"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST");
		return;
	}
	
	PHALCON_INIT_VAR(models);
	array_init(models);
	
	PHALCON_INIT_VAR(sql_aliases);
	array_init(sql_aliases);
	
	PHALCON_INIT_VAR(sql_tables);
	array_init(sql_tables);
	
	PHALCON_INIT_VAR(tables);
	phalcon_array_fetch_string(&tables, update, SL("tables"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(tables, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(update_tables);
		array_init(update_tables);
		phalcon_array_append(&update_tables, tables, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(update_tables, tables);
	}
	
	
	if (!phalcon_valid_foreach(update_tables TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(update_tables);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(table);
		
		PHALCON_INIT_VAR(qualified_name);
		phalcon_array_fetch_string(&qualified_name, table, SL("qualifiedName"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(source);
		PHALCON_CALL_METHOD_PARAMS_2(source, this_ptr, "_gettable", manager, qualified_name, PH_NO_CHECK);
		eval_int = phalcon_array_isset_string(table, SS("alias"));
		if (eval_int) {
			PHALCON_INIT_VAR(alias);
			phalcon_array_fetch_string(&alias, table, SL("alias"), PH_NOISY_CC);
			phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(source_alias);
			PHALCON_CONCAT_VSV(source_alias, source, " ", alias);
			phalcon_array_append(&sql_tables, source_alias, PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_tables, source, PH_SEPARATE TSRMLS_CC);
		}
		
		phalcon_array_append(&models, model_name, PH_SEPARATE TSRMLS_CC);
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(sql_fields);
	array_init(sql_fields);
	
	PHALCON_INIT_VAR(sql_values);
	array_init(sql_values);
	
	PHALCON_INIT_VAR(values);
	phalcon_array_fetch_string(&values, update, SL("values"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(values, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(update_values);
		array_init(update_values);
		phalcon_array_append(&update_values, values, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(update_values, values);
	}
	
	PHALCON_INIT_VAR(not_quoting);
	ZVAL_BOOL(not_quoting, 0);
	
	if (!phalcon_valid_foreach(update_values TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(update_values);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
	ph_cycle_start_1:
	
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto ph_cycle_end_1;
		}
		
		PHALCON_GET_FOREACH_VALUE(update_value);
		
		PHALCON_INIT_VAR(column);
		phalcon_array_fetch_string(&column, update_value, SL("column"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(sql_column);
		PHALCON_CALL_METHOD_PARAMS_3(sql_column, this_ptr, "_getexpression", column, sql_aliases, not_quoting, PH_NO_CHECK);
		phalcon_array_append(&sql_fields, sql_column, PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_VAR(expr_column);
		phalcon_array_fetch_string(&expr_column, update_value, SL("expr"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(expr_value);
		PHALCON_CALL_METHOD_PARAMS_3(expr_value, this_ptr, "_getexpression", expr_column, sql_aliases, not_quoting, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(type);
		phalcon_array_fetch_string(&type, expr_column, SL("type"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(value);
		array_init(value);
		phalcon_array_update_string(&value, SL("type"), &type, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&value, SL("value"), &expr_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&sql_values, value, PH_SEPARATE TSRMLS_CC);
		
		zend_hash_move_forward_ex(ah1, &hp1);
		goto ph_cycle_start_1;
	
	ph_cycle_end_1:
	
	PHALCON_INIT_VAR(sql_update);
	array_init(sql_update);
	phalcon_array_update_string(&sql_update, SL("tables"), &sql_tables, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_update, SL("models"), &models, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_update, SL("fields"), &sql_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_update, SL("values"), &sql_values, PH_COPY | PH_SEPARATE TSRMLS_CC);
	eval_int = phalcon_array_isset_string(ast, SS("where"));
	if (eval_int) {
		PHALCON_INIT_VAR(where);
		phalcon_array_fetch_string(&where, ast, SL("where"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(where_expr);
		PHALCON_CALL_METHOD_PARAMS_2(where_expr, this_ptr, "_getexpression", where, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_update, SL("where"), &where_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(ast, SS("limit"));
	if (eval_int) {
		PHALCON_INIT_VAR(limit);
		phalcon_array_fetch_string(&limit, ast, SL("limit"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(sql_limit);
		PHALCON_CALL_METHOD_PARAMS_2(sql_limit, this_ptr, "_getlimitclause", limit, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_update, SL("limit"), &sql_limit, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	
	RETURN_CTOR(sql_update);
}

/**
 * Analyzes a DELETE intermediate code and produces an array to be executed later
 *
 * @param Phalcon\Mvc\Model $manager
 * @param array $ast
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _prepareDelete){

	zval *manager = NULL, *ast = NULL, *delete = NULL, *models = NULL, *sql_aliases = NULL;
	zval *sql_tables = NULL, *tables = NULL, *delete_tables = NULL, *table = NULL;
	zval *qualified_name = NULL, *model_name = NULL, *source = NULL, *alias = NULL;
	zval *source_alias = NULL, *sql_delete = NULL, *where = NULL, *where_expr = NULL;
	zval *limit = NULL, *sql_limit = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &manager, &ast) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(ast, SS("delete"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST");
		return;
	}
	
	PHALCON_INIT_VAR(delete);
	phalcon_array_fetch_string(&delete, ast, SL("delete"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(delete, SS("tables"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST");
		return;
	}
	
	PHALCON_INIT_VAR(models);
	array_init(models);
	
	PHALCON_INIT_VAR(sql_aliases);
	array_init(sql_aliases);
	
	PHALCON_INIT_VAR(sql_tables);
	array_init(sql_tables);
	
	PHALCON_INIT_VAR(tables);
	phalcon_array_fetch_string(&tables, delete, SL("tables"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(tables, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(delete_tables);
		array_init(delete_tables);
		phalcon_array_append(&delete_tables, tables, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(delete_tables, tables);
	}
	
	
	if (!phalcon_valid_foreach(delete_tables TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(delete_tables);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(table);
		
		PHALCON_INIT_VAR(qualified_name);
		phalcon_array_fetch_string(&qualified_name, table, SL("qualifiedName"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(source);
		PHALCON_CALL_METHOD_PARAMS_2(source, this_ptr, "_gettable", manager, qualified_name, PH_NO_CHECK);
		eval_int = phalcon_array_isset_string(table, SS("alias"));
		if (eval_int) {
			PHALCON_INIT_VAR(alias);
			phalcon_array_fetch_string(&alias, table, SL("alias"), PH_NOISY_CC);
			phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(source_alias);
			PHALCON_CONCAT_VSV(source_alias, source, " ", alias);
			phalcon_array_append(&sql_tables, source_alias, PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_tables, source, PH_SEPARATE TSRMLS_CC);
		}
		
		phalcon_array_append(&models, model_name, PH_SEPARATE TSRMLS_CC);
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(sql_delete);
	array_init(sql_delete);
	phalcon_array_update_string(&sql_delete, SL("tables"), &sql_tables, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_delete, SL("models"), &models, PH_COPY | PH_SEPARATE TSRMLS_CC);
	eval_int = phalcon_array_isset_string(ast, SS("where"));
	if (eval_int) {
		PHALCON_INIT_VAR(where);
		phalcon_array_fetch_string(&where, ast, SL("where"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(where_expr);
		PHALCON_CALL_METHOD_PARAMS_2(where_expr, this_ptr, "_getexpression", where, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_delete, SL("where"), &where_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(ast, SS("limit"));
	if (eval_int) {
		PHALCON_INIT_VAR(limit);
		phalcon_array_fetch_string(&limit, ast, SL("limit"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(sql_limit);
		PHALCON_CALL_METHOD_PARAMS_2(sql_limit, this_ptr, "_getlimitclause", limit, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_delete, SL("limit"), &sql_limit, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	
	RETURN_CTOR(sql_delete);
}

/**
 * Parses the intermediate code produced by Phalcon\Mvc\Model\Query\Lang generating another
 * intermediate representation that could be executed by Phalcon\Mvc\Model\Query
 *
 * @param Phalcon\Mvc\Model $manager
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, parse){

	zval *manager = NULL, *parsedph_ql = NULL, *ast = NULL, *dependency_injector = NULL;
	zval *type = NULL, *exception_message = NULL, *exception = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &manager) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!manager) {
		PHALCON_ALLOC_ZVAL_MM(manager);
		ZVAL_NULL(manager);
	} else {
		PHALCON_SEPARATE_PARAM(manager);
	}
	
	PHALCON_INIT_VAR(parsedph_ql);
	ZVAL_NULL(parsedph_ql);
	
	PHALCON_INIT_VAR(ast);
	phalcon_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	if (Z_TYPE_P(ast) == IS_ARRAY) { 
		eval_int = phalcon_array_isset_string(ast, SS("type"));
		if (eval_int) {
			if (Z_TYPE_P(manager) != IS_OBJECT) {
				PHALCON_INIT_VAR(dependency_injector);
				phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the models-manager service");
					return;
				}
				
				PHALCON_INIT_VAR(c0);
				ZVAL_STRING(c0, "modelsManager", 1);
				
				PHALCON_INIT_VAR(manager);
				PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", c0, PH_NO_CHECK);
			}
			
			PHALCON_INIT_VAR(type);
			phalcon_array_fetch_string(&type, ast, SL("type"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_type"), type TSRMLS_CC);
			
			if (phalcon_compare_strict_long(type, 309 TSRMLS_CC)) {
				PHALCON_INIT_VAR(parsedph_ql);
				PHALCON_CALL_METHOD_PARAMS_2(parsedph_ql, this_ptr, "_prepareselect", manager, ast, PH_NO_CHECK);
				goto ph_end_0;
			}
			
			if (phalcon_compare_strict_long(type, 306 TSRMLS_CC)) {
				PHALCON_INIT_VAR(parsedph_ql);
				PHALCON_CALL_METHOD_PARAMS_2(parsedph_ql, this_ptr, "_prepareinsert", manager, ast, PH_NO_CHECK);
				goto ph_end_0;
			}
			
			if (phalcon_compare_strict_long(type, 300 TSRMLS_CC)) {
				PHALCON_INIT_VAR(parsedph_ql);
				PHALCON_CALL_METHOD_PARAMS_2(parsedph_ql, this_ptr, "_prepareupdate", manager, ast, PH_NO_CHECK);
				goto ph_end_0;
			}
			
			if (phalcon_compare_strict_long(type, 303 TSRMLS_CC)) {
				PHALCON_INIT_VAR(parsedph_ql);
				PHALCON_CALL_METHOD_PARAMS_2(parsedph_ql, this_ptr, "_preparedelete", manager, ast, PH_NO_CHECK);
				goto ph_end_0;
			}
			
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SV(exception_message, "Unknown statement ", type);
			
			PHALCON_INIT_VAR(exception);
			object_init_ex(exception, phalcon_mvc_model_exception_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
			phalcon_throw_exception(exception TSRMLS_CC);
			return;
			
			ph_end_0:
			if(0){}
		}
	}
	
	if (Z_TYPE_P(parsedph_ql) == IS_NULL) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted AST");
		return;
	}
	
	
	RETURN_CCTOR(parsedph_ql);
}

/**
 * Executes the SELECT intermediate representation producing a Phalcon\Mvc\Query\Resultset
 *
 * @param Phalcon\Mvc\Model $manager
 * @param Phalcon\Mvc\Model\Metada $metaData
 * @param array $intermediate
 * @param array $placeholders
 * @return Phalcon\Mvc\Query\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeSelect){

	zval *manager = NULL, *meta_data = NULL, *intermediate = NULL, *placeholders = NULL;
	zval *models_instances = NULL, *models = NULL, *number_models = NULL;
	zval *model_name = NULL, *model = NULL, *connection = NULL, *connections = NULL;
	zval *type = NULL, *connection_types = NULL, *columns = NULL, *have_objects = NULL;
	zval *have_scalars = NULL, *is_complex = NULL, *number_objects = NULL;
	zval *column = NULL, *column_type = NULL, *is_simple_std = NULL, *select_columns = NULL;
	zval *alias = NULL, *sql_column = NULL, *instance = NULL, *attributes = NULL;
	zval *attribute = NULL, *column_alias = NULL, *dialect = NULL, *sql_select = NULL;
	zval *processed = NULL, *value = NULL, *wildcard = NULL, *string_wildcard = NULL;
	zval *result = NULL, *count = NULL, *result_data = NULL, *cache = NULL, *result_object = NULL;
	zval *resultset = NULL;
	HashTable *ah0, *ah1, *ah2, *ah3, *ah4;
	HashPosition hp0, hp1, hp2, hp3, hp4;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &manager, &meta_data, &intermediate, &placeholders) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(intermediate);
	
	PHALCON_INIT_VAR(models_instances);
	array_init(models_instances);
	
	PHALCON_INIT_VAR(models);
	phalcon_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number_models);
	phalcon_fast_count(number_models, models TSRMLS_CC);
	if (phalcon_compare_strict_long(number_models, 1 TSRMLS_CC)) {
		PHALCON_INIT_VAR(model_name);
		phalcon_array_fetch_long(&model_name, models, 0, PH_NOISY_CC);
		
		PHALCON_INIT_VAR(model);
		PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(connection);
		PHALCON_CALL_METHOD(connection, model, "getconnection", PH_NO_CHECK);
		phalcon_array_update_zval(&models_instances, model_name, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(connections);
		array_init(connections);
		
		if (!phalcon_valid_foreach(models TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(models);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_VALUE(model_name);
			
			PHALCON_INIT_VAR(model);
			PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(connection);
			PHALCON_CALL_METHOD(connection, model, "getconnection", PH_NO_CHECK);
			
			PHALCON_INIT_VAR(type);
			PHALCON_CALL_METHOD(type, connection, "gettype", PH_NO_CHECK);
			phalcon_array_update_zval_bool(&connections, type, 1, PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(connection_types);
			phalcon_fast_count(connection_types, connections TSRMLS_CC);
			if (phalcon_compare_strict_long(connection_types, 2 TSRMLS_CC)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Cannot use models of different database sytem in the same query");
				return;
			}
			
			phalcon_array_update_zval(&models_instances, model_name, &model, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
		
		ph_cycle_end_0:
		if(0){}
		
	}
	
	PHALCON_INIT_VAR(columns);
	phalcon_array_fetch_string(&columns, intermediate, SL("columns"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(have_objects);
	ZVAL_BOOL(have_objects, 0);
	
	PHALCON_INIT_VAR(have_scalars);
	ZVAL_BOOL(have_scalars, 0);
	
	PHALCON_INIT_VAR(is_complex);
	ZVAL_BOOL(is_complex, 0);
	
	PHALCON_INIT_VAR(number_objects);
	ZVAL_LONG(number_objects, 0);
	
	if (!phalcon_valid_foreach(columns TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(columns);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
	ph_cycle_start_1:
	
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto ph_cycle_end_1;
		}
		
		PHALCON_GET_FOREACH_VALUE(column);
		
		PHALCON_INIT_VAR(column_type);
		phalcon_array_fetch_string(&column_type, column, SL("type"), PH_NOISY_CC);
		if (PHALCON_COMPARE_STRING(column_type, "scalar")) {
			eval_int = phalcon_array_isset_string(column, SS("balias"));
			if (!eval_int) {
				PHALCON_INIT_VAR(is_complex);
				ZVAL_BOOL(is_complex, 1);
			}
			
			PHALCON_INIT_VAR(have_scalars);
			ZVAL_BOOL(have_scalars, 1);
		} else {
			PHALCON_INIT_VAR(have_objects);
			ZVAL_BOOL(have_objects, 1);
			PHALCON_SEPARATE(number_objects);
			increment_function(number_objects);
		}
		
		zend_hash_move_forward_ex(ah1, &hp1);
		goto ph_cycle_start_1;
	
	ph_cycle_end_1:
	
	if (PHALCON_IS_FALSE(is_complex)) {
		if (PHALCON_IS_TRUE(have_objects)) {
			if (PHALCON_IS_TRUE(have_scalars)) {
				PHALCON_INIT_VAR(is_complex);
				ZVAL_BOOL(is_complex, 1);
			} else {
				if (phalcon_compare_strict_long(number_objects, 1 TSRMLS_CC)) {
					PHALCON_INIT_VAR(is_simple_std);
					ZVAL_BOOL(is_simple_std, 0);
				} else {
					PHALCON_INIT_VAR(is_complex);
					ZVAL_BOOL(is_complex, 1);
				}
			}
		} else {
			PHALCON_INIT_VAR(is_simple_std);
			ZVAL_BOOL(is_simple_std, 1);
		}
	}
	
	PHALCON_INIT_VAR(select_columns);
	array_init(select_columns);
	
	if (!phalcon_valid_foreach(columns TSRMLS_CC)) {
		return;
	}
	
	ALLOC_HASHTABLE(ah2);
	zend_hash_init(ah2, 0, NULL, NULL, 0);
	zend_hash_copy(ah2, Z_ARRVAL_P(columns), NULL, NULL, sizeof(zval*));
	zend_hash_internal_pointer_reset_ex(ah2, &hp2);
	
	ph_cycle_start_2:
	
		if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
			goto ph_cycle_end_2;
		}
		
		PHALCON_INIT_VAR(alias);
		PHALCON_GET_FOREACH_KEY(alias, ah2, hp2);
		PHALCON_GET_FOREACH_VALUE(column);
		
		PHALCON_INIT_VAR(sql_column);
		phalcon_array_fetch_string(&sql_column, column, SL("column"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(type);
		phalcon_array_fetch_string(&type, column, SL("type"), PH_NOISY_CC);
		if (PHALCON_COMPARE_STRING(type, "object")) {
			PHALCON_INIT_VAR(model_name);
			phalcon_array_fetch_string(&model_name, column, SL("model"), PH_NOISY_CC);
			if (PHALCON_IS_TRUE(is_complex)) {
				PHALCON_INIT_VAR(instance);
				phalcon_array_fetch(&instance, models_instances, model_name, PH_NOISY_CC);
				
				PHALCON_INIT_VAR(attributes);
				PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", instance, PH_NO_CHECK);
				
				if (!phalcon_valid_foreach(attributes TSRMLS_CC)) {
					return;
				}
				
				ah3 = Z_ARRVAL_P(attributes);
				zend_hash_internal_pointer_reset_ex(ah3, &hp3);
				
				ph_cycle_start_3:
				
					if(zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) != SUCCESS){
						goto ph_cycle_end_3;
					}
					
					PHALCON_GET_FOREACH_VALUE(attribute);
					
					PHALCON_INIT_VAR(column_alias);
					PHALCON_CONCAT_VSVSVSV(column_alias, sql_column, ".", attribute, " AS _", sql_column, "_", attribute);
					phalcon_array_append(&select_columns, column_alias, PH_SEPARATE TSRMLS_CC);
					
					zend_hash_move_forward_ex(ah3, &hp3);
					goto ph_cycle_start_3;
				
				ph_cycle_end_3:
				
				phalcon_array_update_string_multi_2(&columns, alias, SL("instance"), &instance, 0 TSRMLS_CC);
				phalcon_array_update_string_multi_2(&columns, alias, SL("attributes"), &attributes, 0 TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(column_alias);
				PHALCON_CONCAT_VS(column_alias, sql_column, ".*");
				phalcon_array_append(&select_columns, column_alias, PH_SEPARATE TSRMLS_CC);
			}
		} else {
			if (Z_TYPE_P(alias) == IS_LONG) {
				phalcon_array_append(&select_columns, sql_column, PH_SEPARATE TSRMLS_CC);
			} else {
				PHALCON_INIT_VAR(column_alias);
				PHALCON_CONCAT_VSV(column_alias, sql_column, " AS ", alias);
				phalcon_array_append(&select_columns, column_alias, PH_SEPARATE TSRMLS_CC);
			}
		}
		
		zend_hash_move_forward_ex(ah2, &hp2);
		goto ph_cycle_start_2;
	
	ph_cycle_end_2:
	zend_hash_destroy(ah2);
	efree(ah2);
	
	phalcon_array_update_string(&intermediate, SL("columns"), &select_columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(dialect);
	PHALCON_CALL_METHOD(dialect, connection, "getdialect", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(sql_select);
	PHALCON_CALL_METHOD_PARAMS_1(sql_select, dialect, "select", intermediate, PH_NO_CHECK);
	if (Z_TYPE_P(placeholders) == IS_ARRAY) { 
		PHALCON_INIT_VAR(processed);
		array_init(processed);
		
		if (!phalcon_valid_foreach(placeholders TSRMLS_CC)) {
			return;
		}
		
		ah4 = Z_ARRVAL_P(placeholders);
		zend_hash_internal_pointer_reset_ex(ah4, &hp4);
		
		ph_cycle_start_4:
		
			if(zend_hash_get_current_data_ex(ah4, (void**) &hd, &hp4) != SUCCESS){
				goto ph_cycle_end_4;
			}
			
			PHALCON_INIT_VAR(wildcard);
			PHALCON_GET_FOREACH_KEY(wildcard, ah4, hp4);
			PHALCON_GET_FOREACH_VALUE(value);
			
			if (Z_TYPE_P(wildcard) == IS_LONG) {
				PHALCON_INIT_VAR(string_wildcard);
				PHALCON_CONCAT_SV(string_wildcard, ":", wildcard);
				phalcon_array_update_zval(&processed, string_wildcard, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
			} else {
				phalcon_array_update_zval(&processed, wildcard, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
			}
			
			zend_hash_move_forward_ex(ah4, &hp4);
			goto ph_cycle_start_4;
		
		ph_cycle_end_4:
		if(0){}
		
	} else {
		PHALCON_CPY_WRT(processed, placeholders);
	}
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_METHOD_PARAMS_2(result, connection, "query", sql_select, processed, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(count);
	PHALCON_CALL_METHOD_PARAMS_1(count, result, "numrows", result, PH_NO_CHECK);
	if (zend_is_true(count)) {
		PHALCON_CPY_WRT(result_data, result);
	} else {
		PHALCON_INIT_VAR(result_data);
		ZVAL_BOOL(result_data, 0);
	}
	
	PHALCON_INIT_VAR(cache);
	ZVAL_NULL(cache);
	if (PHALCON_IS_FALSE(is_complex)) {
		if (PHALCON_IS_TRUE(is_simple_std)) {
			PHALCON_INIT_VAR(result_object);
			object_init_ex(result_object, phalcon_mvc_model_row_ce);
		} else {
			PHALCON_CPY_WRT(result_object, model);
		}
		
		PHALCON_INIT_VAR(resultset);
		object_init_ex(resultset, phalcon_mvc_model_resultset_simple_ce);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(resultset, "__construct", result_object, result_data, cache, PH_CHECK);
		
		RETURN_CTOR(resultset);
	}
	
	PHALCON_INIT_VAR(resultset);
	object_init_ex(resultset, phalcon_mvc_model_resultset_complex_ce);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(resultset, "__construct", columns, result_data, cache, PH_CHECK);
	
	RETURN_CTOR(resultset);
}

/**
 * Executes the INSERT intermediate representation producing a Phalcon\Mvc\Query\Status
 *
 * @param Phalcon\Mvc\Model $manager
 * @param Phalcon\Mvc\Model\Metada $metaData
 * @param array $intermediate
 * @param array $placeholders
 * @return Phalcon\Mvc\Query\Status
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeInsert){

	zval *manager = NULL, *meta_data = NULL, *intermediate = NULL, *placeholders = NULL;
	zval *model_name = NULL, *model = NULL, *connection = NULL, *attributes = NULL;
	zval *fields = NULL, *values = NULL, *number_fields = NULL, *number_values = NULL;
	zval *not_equal = NULL, *null_value = NULL, *insert_values = NULL;
	zval *value = NULL, *number = NULL, *type = NULL, *expr_value = NULL, *insert_value = NULL;
	zval *exception_message = NULL, *exception = NULL, *field_name = NULL;
	zval *attribute = NULL, *insert_model = NULL, *success = NULL, *status = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &manager, &meta_data, &intermediate, &placeholders) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(model_name);
	phalcon_array_fetch_string(&model_name, intermediate, SL("model"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(model);
	PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, model, "getconnection", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(attributes);
	PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", model, PH_NO_CHECK);
	eval_int = phalcon_array_isset_string(intermediate, SS("fields"));
	if (eval_int) {
		PHALCON_INIT_VAR(fields);
		phalcon_array_fetch_string(&fields, intermediate, SL("fields"), PH_NOISY_CC);
	} else {
		PHALCON_CPY_WRT(fields, attributes);
	}
	
	PHALCON_INIT_VAR(values);
	phalcon_array_fetch_string(&values, intermediate, SL("values"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number_fields);
	phalcon_fast_count(number_fields, fields TSRMLS_CC);
	
	PHALCON_INIT_VAR(number_values);
	phalcon_fast_count(number_values, values TSRMLS_CC);
	
	PHALCON_INIT_VAR(not_equal);
	is_identical_function(not_equal, number_values, number_fields TSRMLS_CC);
	if (PHALCON_IS_FALSE(not_equal)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The columns count does not match the values count");
		return;
	}
	
	PHALCON_INIT_VAR(null_value);
	ZVAL_NULL(null_value);
	
	PHALCON_INIT_VAR(insert_values);
	array_init(insert_values);
	
	if (!phalcon_valid_foreach(values TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(values);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}
		
		PHALCON_INIT_VAR(number);
		PHALCON_GET_FOREACH_KEY(number, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(value);
		
		PHALCON_INIT_VAR(type);
		phalcon_array_fetch_string(&type, value, SL("type"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(expr_value);
		phalcon_array_fetch_string(&expr_value, value, SL("value"), PH_NOISY_CC);
		
		if (phalcon_compare_strict_long(type, 260 TSRMLS_CC)) {
			PHALCON_CPY_WRT(insert_value, expr_value);
			goto ph_end_1;
		}
		
		if (phalcon_compare_strict_long(type, 258 TSRMLS_CC)) {
			PHALCON_CPY_WRT(insert_value, expr_value);
			goto ph_end_1;
		}
		
		if (phalcon_compare_strict_long(type, 259 TSRMLS_CC)) {
			PHALCON_CPY_WRT(insert_value, expr_value);
			goto ph_end_1;
		}
		
		if (phalcon_compare_strict_long(type, 322 TSRMLS_CC)) {
			PHALCON_CPY_WRT(insert_value, null_value);
			goto ph_end_1;
		}
		
		if (phalcon_compare_strict_long(type, 274 TSRMLS_CC)) {
			if (Z_TYPE_P(placeholders) == IS_ARRAY) { 
				eval_int = phalcon_array_isset(placeholders, expr_value);
				if (eval_int) {
					PHALCON_INIT_VAR(insert_value);
					phalcon_array_fetch(&insert_value, placeholders, expr_value, PH_NOISY_CC);
				} else {
					PHALCON_INIT_VAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Bound parameter '", expr_value, "' cannot be replaced because it's not in the placeholders list");
					
					PHALCON_INIT_VAR(exception);
					object_init_ex(exception, phalcon_mvc_model_exception_ce);
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
					phalcon_throw_exception(exception TSRMLS_CC);
					return;
				}
			} else {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Bound parameter cannot be replaced because placeholders is not an array");
				return;
			}
			goto ph_end_1;
		}
		
		PHALCON_INIT_VAR(insert_value);
		object_init_ex(insert_value, phalcon_db_rawvalue_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(insert_value, "__construct", expr_value, PH_CHECK);
		goto ph_end_1;
		
		ph_end_1:
		
		PHALCON_INIT_VAR(field_name);
		phalcon_array_fetch(&field_name, fields, number, PH_NOISY_CC);
		phalcon_array_update_zval(&insert_values, field_name, &insert_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	
	if (!phalcon_valid_foreach(attributes TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(attributes);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
	ph_cycle_start_2:
	
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto ph_cycle_end_2;
		}
		
		PHALCON_GET_FOREACH_VALUE(attribute);
		
		eval_int = phalcon_array_isset(insert_values, attribute);
		if (!eval_int) {
			phalcon_array_update_zval(&insert_values, attribute, &null_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		zend_hash_move_forward_ex(ah1, &hp1);
		goto ph_cycle_start_2;
	
	ph_cycle_end_2:
	
	PHALCON_INIT_VAR(insert_model);
	PHALCON_CALL_STATIC_PARAMS_2(insert_model, "phalcon\\mvc\\model", "dumpresult", model, insert_values);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD(success, insert_model, "create", PH_NO_CHECK);
	
	PHALCON_INIT_VAR(status);
	object_init_ex(status, phalcon_mvc_model_query_status_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, insert_model, PH_CHECK);
	
	RETURN_CTOR(status);
}

/**
 * Executes the UPDATE intermediate representation producing a Phalcon\Mvc\Query\Status
 *
 * @param Phalcon\Mvc\Model $manager
 * @param Phalcon\Mvc\Model\Metada $metaData
 * @param array $intermediate
 * @param array $placeholders
 * @return Phalcon\Mvc\Query\Status
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeUpdate){

	zval *manager = NULL, *meta_data = NULL, *intermediate = NULL, *placeholders = NULL;
	zval *models = NULL, *model_name = NULL, *model = NULL, *where_conditions = NULL;
	zval *records = NULL, *fields = NULL, *values = NULL, *null_value = NULL, *record = NULL;
	zval *field = NULL, *number = NULL, *value = NULL, *type = NULL, *expr_value = NULL, *update_value = NULL;
	zval *success = NULL, *status = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &manager, &meta_data, &intermediate, &placeholders) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(models);
	phalcon_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(models, 1);
	if (eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Updating several models at the same time is still not supported");
		return;
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_array_fetch_long(&model_name, models, 0, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(model);
	PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name, PH_NO_CHECK);
	eval_int = phalcon_array_isset_string(intermediate, SS("where"));
	if (eval_int) {
		PHALCON_INIT_VAR(where_conditions);
		phalcon_array_fetch_string(&where_conditions, intermediate, SL("where"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(records);
		PHALCON_CALL_METHOD_PARAMS_1(records, model, "find", where_conditions, PH_NO_CHECK);
	} else {
		PHALCON_INIT_VAR(records);
		PHALCON_CALL_METHOD(records, model, "find", PH_NO_CHECK);
	}
	
	PHALCON_INIT_VAR(fields);
	phalcon_array_fetch_string(&fields, intermediate, SL("fields"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(values);
	phalcon_array_fetch_string(&values, intermediate, SL("values"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(null_value);
	ZVAL_NULL(null_value);
	PHALCON_CALL_METHOD_NORETURN(records, "rewind", PH_NO_CHECK);
	ph_cycle_start_0:
		
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, records, "valid", PH_NO_CHECK);
		if (PHALCON_IS_NOT_TRUE(r0)) {
			goto ph_cycle_end_0;
		}
		PHALCON_INIT_VAR(record);
		PHALCON_CALL_METHOD(record, records, "current", PH_NO_CHECK);
		
		if (!phalcon_valid_foreach(fields TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(fields);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_1:
		
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto ph_cycle_end_1;
			}
			
			PHALCON_INIT_VAR(number);
			PHALCON_GET_FOREACH_KEY(number, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(field);
			
			PHALCON_INIT_VAR(value);
			phalcon_array_fetch(&value, values, number, PH_NOISY_CC);
			
			PHALCON_INIT_VAR(type);
			phalcon_array_fetch_string(&type, value, SL("type"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(expr_value);
			phalcon_array_fetch_string(&expr_value, value, SL("value"), PH_NOISY_CC);
			
			if (phalcon_compare_strict_long(type, 260 TSRMLS_CC)) {
				PHALCON_CPY_WRT(update_value, expr_value);
				goto ph_end_2;
			}
			
			if (phalcon_compare_strict_long(type, 258 TSRMLS_CC)) {
				PHALCON_CPY_WRT(update_value, expr_value);
				goto ph_end_2;
			}
			
			if (phalcon_compare_strict_long(type, 259 TSRMLS_CC)) {
				PHALCON_CPY_WRT(update_value, expr_value);
				goto ph_end_2;
			}
			
			if (phalcon_compare_strict_long(type, 322 TSRMLS_CC)) {
				PHALCON_CPY_WRT(update_value, null_value);
				goto ph_end_2;
			}
			
			PHALCON_INIT_VAR(update_value);
			object_init_ex(update_value, phalcon_db_rawvalue_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(update_value, "__construct", expr_value, PH_CHECK);
			goto ph_end_2;
			
			ph_end_2:
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(record, "writeattribute", field, update_value, PH_NO_CHECK);
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_1;
		
		ph_cycle_end_1:
		
		PHALCON_INIT_VAR(success);
		PHALCON_CALL_METHOD(success, record, "update", PH_NO_CHECK);
		if (PHALCON_IS_FALSE(success)) {
			PHALCON_INIT_VAR(status);
			object_init_ex(status, phalcon_mvc_model_query_status_ce);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, record, PH_CHECK);
			
			RETURN_CTOR(status);
		}
		
		PHALCON_CALL_METHOD_NORETURN(records, "next", PH_NO_CHECK);
		goto ph_cycle_start_0;
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(success);
	ZVAL_BOOL(success, 1);
	
	PHALCON_INIT_VAR(status);
	object_init_ex(status, phalcon_mvc_model_query_status_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, null_value, PH_CHECK);
	
	RETURN_CTOR(status);
}

/**
 * Executes the DELETE intermediate representation producing a Phalcon\Mvc\Query\Status
 *
 * @param Phalcon\Mvc\Model $manager
 * @param Phalcon\Mvc\Model\Metada $metaData
 * @param array $intermediate
 * @param array $placeholders
 * @return Phalcon\Mvc\Query\Status
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, _executeDelete){

	zval *manager = NULL, *meta_data = NULL, *intermediate = NULL, *placeholders = NULL;
	zval *models = NULL, *model_name = NULL, *model = NULL, *where_conditions = NULL;
	zval *records = NULL, *record = NULL, *success = NULL, *status = NULL, *null_value = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &manager, &meta_data, &intermediate, &placeholders) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(models);
	phalcon_array_fetch_string(&models, intermediate, SL("models"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(models, 1);
	if (eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Updating several models at the same time is still not supported");
		return;
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_array_fetch_long(&model_name, models, 0, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(model);
	PHALCON_CALL_METHOD_PARAMS_1(model, manager, "load", model_name, PH_NO_CHECK);
	eval_int = phalcon_array_isset_string(intermediate, SS("where"));
	if (eval_int) {
		PHALCON_INIT_VAR(where_conditions);
		phalcon_array_fetch_string(&where_conditions, intermediate, SL("where"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(records);
		PHALCON_CALL_METHOD_PARAMS_1(records, model, "find", where_conditions, PH_NO_CHECK);
	} else {
		PHALCON_INIT_VAR(records);
		PHALCON_CALL_METHOD(records, model, "find", PH_NO_CHECK);
	}
	
	PHALCON_CALL_METHOD_NORETURN(records, "rewind", PH_NO_CHECK);
	ph_cycle_start_0:
		
		PHALCON_INIT_VAR(r0);
		PHALCON_CALL_METHOD(r0, records, "valid", PH_NO_CHECK);
		if (PHALCON_IS_NOT_TRUE(r0)) {
			goto ph_cycle_end_0;
		}
		PHALCON_INIT_VAR(record);
		PHALCON_CALL_METHOD(record, records, "current", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(success);
		PHALCON_CALL_METHOD(success, record, "delete", PH_NO_CHECK);
		if (PHALCON_IS_FALSE(success)) {
			PHALCON_INIT_VAR(status);
			object_init_ex(status, phalcon_mvc_model_query_status_ce);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, record, PH_CHECK);
			
			RETURN_CTOR(status);
		}
		
		PHALCON_CALL_METHOD_NORETURN(records, "next", PH_NO_CHECK);
		goto ph_cycle_start_0;
	ph_cycle_end_0:
	
	PHALCON_INIT_VAR(success);
	ZVAL_BOOL(success, 1);
	
	PHALCON_INIT_VAR(null_value);
	ZVAL_BOOL(null_value, 1);
	
	PHALCON_INIT_VAR(status);
	object_init_ex(status, phalcon_mvc_model_query_status_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(status, "__construct", success, null_value, PH_CHECK);
	
	RETURN_CTOR(status);
}

/**
 * Executes a parsed PHQL statement
 *
 * @param array $placeholders
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model_Query, execute){

	zval *placeholders = NULL, *dependency_injector = NULL;
	zval *service = NULL, *manager = NULL, *meta_data = NULL, *intermediate = NULL;
	zval *type = NULL, *result = NULL, *exception_message = NULL, *exception = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &placeholders) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!placeholders) {
		PHALCON_ALLOC_ZVAL_MM(placeholders);
		ZVAL_NULL(placeholders);
	}
	
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the models-manager service");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsManager", 1);
	
	PHALCON_INIT_VAR(manager);
	PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "modelsMetadata", 1);
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", service, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(intermediate);
	PHALCON_CALL_METHOD_PARAMS_1(intermediate, this_ptr, "parse", manager, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(type);
	phalcon_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	
	if (phalcon_compare_strict_long(type, 309 TSRMLS_CC)) {
		PHALCON_INIT_VAR(result);
		PHALCON_CALL_METHOD_PARAMS_4(result, this_ptr, "_executeselect", manager, meta_data, intermediate, placeholders, PH_NO_CHECK);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 306 TSRMLS_CC)) {
		PHALCON_INIT_VAR(result);
		PHALCON_CALL_METHOD_PARAMS_4(result, this_ptr, "_executeinsert", manager, meta_data, intermediate, placeholders, PH_NO_CHECK);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 300 TSRMLS_CC)) {
		PHALCON_INIT_VAR(result);
		PHALCON_CALL_METHOD_PARAMS_4(result, this_ptr, "_executeupdate", manager, meta_data, intermediate, placeholders, PH_NO_CHECK);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 303 TSRMLS_CC)) {
		PHALCON_INIT_VAR(result);
		PHALCON_CALL_METHOD_PARAMS_4(result, this_ptr, "_executedelete", manager, meta_data, intermediate, placeholders, PH_NO_CHECK);
		goto ph_end_0;
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SV(exception_message, "Unknown statement ", type);
	
	PHALCON_INIT_VAR(exception);
	object_init_ex(exception, phalcon_mvc_model_exception_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
	phalcon_throw_exception(exception TSRMLS_CC);
	return;
	
	ph_end_0:
	
	RETURN_CCTOR(result);
}

