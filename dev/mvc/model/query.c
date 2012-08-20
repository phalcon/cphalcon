
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
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Mvc\Model\Query
 *
 * Phalcon\Mvc\Model\Query is designed to simplify building of search on models.
 * It provides a set of helpers to generate searchs in a dynamic way to support differents databases.
 *
 * 
 *
 */

PHP_METHOD(Phalcon_Mvc_Model_Query, __construct){

	zval *phql = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &phql) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_STATIC_PARAMS_1(r0, "phalcon\\mvc\\model\\query\\lang", "parsephql", phql);
	phalcon_update_property_zval(this_ptr, SL("_ast"), r0 TSRMLS_CC);
	
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

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

PHP_METHOD(Phalcon_Mvc_Model_Query, _getQualified){

	zval *expr = NULL, *sql_aliases = NULL, *column_domain = NULL, *column_name = NULL;
	zval *source = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &expr, &sql_aliases) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(expr, SL("domain")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(column_domain);
		phalcon_array_fetch_string(&column_domain, expr, SL("domain"), PH_NOISY_CC);
		eval_int = phalcon_array_isset(sql_aliases, column_domain);
		if (!eval_int) {
			PHALCON_ALLOC_ZVAL_MM(i0);
			object_init_ex(i0, phalcon_mvc_model_exception_ce);
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CONCAT_SVS(r0, "Unknown table or alias '", column_domain, "'");
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PH_CHECK);
			phalcon_throw_exception(i0 TSRMLS_CC);
			return;
		}
		
		PHALCON_INIT_VAR(column_name);
		phalcon_array_fetch_string(&column_name, expr, SL("name"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(source);
		phalcon_array_fetch(&source, sql_aliases, column_domain, PH_NOISY_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_CONCAT_VSV(r1, source, ".", column_name);
		
		RETURN_CTOR(r1);
	}
	
	PHALCON_INIT_VAR(column_name);
	phalcon_array_fetch_string(&column_name, expr, SL("name"), PH_NOISY_CC);
	
	RETURN_CCTOR(column_name);
}

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

PHP_METHOD(Phalcon_Mvc_Model_Query, _getFunctionCall){

	zval *expr = NULL, *sql_aliases = NULL, *name = NULL, *arguments = NULL, *arguments_expr = NULL;
	zval *argument = NULL, *argument_expr = NULL, *function_args = NULL;
	zval *function_call = NULL;
	zval *c0 = NULL;
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
	eval_int = phalcon_array_isset_string(expr, SL("arguments")+1);
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
			fes_111d_0:
				if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
					goto fee_111d_0;
				}
				
				PHALCON_INIT_VAR(argument);
				ZVAL_ZVAL(argument, *hd, 1, 0);
				PHALCON_INIT_VAR(argument_expr);
				PHALCON_CALL_METHOD_PARAMS_2(argument_expr, this_ptr, "_getcallargument", argument, sql_aliases, PH_NO_CHECK);
				phalcon_array_append(&arguments_expr, argument_expr, PH_SEPARATE TSRMLS_CC);
				zend_hash_move_forward_ex(ah0, &hp0);
				goto fes_111d_0;
			fee_111d_0:
			
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, ",", 1);
			
			PHALCON_INIT_VAR(function_args);
			phalcon_fast_join(function_args, c0, arguments_expr TSRMLS_CC);
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

PHP_METHOD(Phalcon_Mvc_Model_Query, _getExpression){

	zval *expr = NULL, *sql_aliases = NULL, *expr_left = NULL, *left = NULL, *expr_right = NULL;
	zval *right = NULL, *expr_type = NULL, *expr_return = NULL, *value = NULL, *numeric_place = NULL;
	zval *expr_domain = NULL, *list_items = NULL, *expr_list_item = NULL;
	zval *expr_item = NULL, *joined_list = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &expr, &sql_aliases) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(expr, SL("type")+1);
	if (eval_int) {
		eval_int = phalcon_array_isset_string(expr, SL("left")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(expr_left);
			phalcon_array_fetch_string(&expr_left, expr, SL("left"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(left);
			PHALCON_CALL_METHOD_PARAMS_2(left, this_ptr, "_getexpression", expr_left, sql_aliases, PH_NO_CHECK);
		}
		eval_int = phalcon_array_isset_string(expr, SL("right")+1);
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
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 61 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "=", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 62 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, ">", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 270 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "<>", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 271 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "<=", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 272 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, ">=", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 266 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, " AND ", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 267 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, " OR ", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 43 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "+", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 45 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "-", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 42 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "*", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 47 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "/", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 37 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, "%", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 356 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_SVS(expr_return, "(", left, ")");
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 367 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_SV(expr_return, "-", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 355 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CALL_METHOD_PARAMS_2(expr_return, this_ptr, "_getqualified", expr, sql_aliases, PH_NO_CHECK);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 258 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			phalcon_array_fetch_string(&expr_return, expr, SL("value"), PH_NOISY_CC);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 259 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			phalcon_array_fetch_string(&expr_return, expr, SL("value"), PH_NOISY_CC);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 260 TSRMLS_CC)) {
			PHALCON_INIT_VAR(value);
			phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_SVS(expr_return, "'", value, "'");
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 273 TSRMLS_CC)) {
			PHALCON_INIT_VAR(value);
			phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(c0);
			ZVAL_STRING(c0, "?", 1);
			
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, "", 1);
			
			PHALCON_INIT_VAR(numeric_place);
			phalcon_fast_str_replace(numeric_place, c0, c1, value TSRMLS_CC);
			
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_SV(expr_return, ":", numeric_place);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 274 TSRMLS_CC)) {
			PHALCON_INIT_VAR(value);
			phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_SV(expr_return, ":", value);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 322 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			ZVAL_STRING(expr_return, "NULL", 1);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 268 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_SV(expr_return, "LIKE ", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 351 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_SV(expr_return, "NOT LIKE ", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 33 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_SV(expr_return, "NOT ", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 365 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VS(expr_return, left, " IS NULL");
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 366 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VS(expr_return, left, " IS NOT NULL");
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 315 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, " IN ", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 323 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CONCAT_VSV(expr_return, left, " NOT IN ", right);
			goto se_111d_1;
		}
		if (phalcon_compare_strict_long(expr_type, 350 TSRMLS_CC)) {
			PHALCON_INIT_VAR(expr_return);
			PHALCON_CALL_METHOD_PARAMS_2(expr_return, this_ptr, "_getfunctioncall", expr, sql_aliases, PH_NO_CHECK);
			goto se_111d_1;
		}
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_mvc_model_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CONCAT_SV(r0, "Unkown expression type ", expr_type);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PH_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
		se_111d_1:
		
		RETURN_CCTOR(expr_return);
	}
	eval_int = phalcon_array_isset_string(expr, SL("domain")+1);
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
		fes_111d_2:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_111d_2;
			}
			
			PHALCON_INIT_VAR(expr_list_item);
			ZVAL_ZVAL(expr_list_item, *hd, 1, 0);
			PHALCON_INIT_VAR(expr_item);
			PHALCON_CALL_METHOD_PARAMS_2(expr_item, this_ptr, "_getexpression", expr_list_item, sql_aliases, PH_NO_CHECK);
			phalcon_array_append(&list_items, expr_item, PH_SEPARATE TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_111d_2;
		fee_111d_2:
		
		PHALCON_INIT_VAR(c2);
		ZVAL_STRING(c2, ",", 1);
		
		PHALCON_INIT_VAR(joined_list);
		phalcon_fast_join(joined_list, c2, list_items TSRMLS_CC);
		
		PHALCON_INIT_VAR(expr_return);
		PHALCON_CONCAT_SVS(expr_return, "(", joined_list, ")");
		
		RETURN_CCTOR(expr_return);
	}
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Unknown expression");
	return;
}

PHP_METHOD(Phalcon_Mvc_Model_Query, _getSelectColumn){

	zval *column = NULL, *sql_aliases = NULL, *column_type = NULL, *sql_column = NULL;
	zval *column_domain = NULL, *source = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &column, &sql_aliases) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(column);
	
	eval_int = phalcon_array_isset_string(column, SL("type")+1);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	PHALCON_INIT_VAR(column_type);
	phalcon_array_fetch_string(&column_type, column, SL("type"), PH_NOISY_CC);
	if (phalcon_compare_strict_long(column_type, 352 TSRMLS_CC)) {
		PHALCON_INIT_VAR(sql_column);
		ZVAL_STRING(sql_column, "*", 1);
	} else {
		if (phalcon_compare_strict_long(column_type, 353 TSRMLS_CC)) {
			eval_int = phalcon_array_isset_string(column, SL("column")+1);
			if (eval_int) {
				PHALCON_INIT_VAR(column_domain);
				phalcon_array_fetch_string(&column_domain, column, SL("column"), PH_NOISY_CC);
				eval_int = phalcon_array_isset(sql_aliases, column_domain);
				if (!eval_int) {
					PHALCON_ALLOC_ZVAL_MM(i0);
					object_init_ex(i0, phalcon_mvc_model_exception_ce);
					PHALCON_ALLOC_ZVAL_MM(r0);
					PHALCON_CONCAT_SVS(r0, "Unknown table or alias '", column_domain, "'");
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PH_CHECK);
					phalcon_throw_exception(i0 TSRMLS_CC);
					return;
				}
				
				PHALCON_INIT_VAR(source);
				phalcon_array_fetch(&source, sql_aliases, column_domain, PH_NOISY_CC);
				
				PHALCON_INIT_VAR(sql_column);
				PHALCON_CONCAT_VS(sql_column, source, ".*");
			} else {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
				return;
			}
		} else {
			if (phalcon_compare_strict_long(column_type, 354 TSRMLS_CC)) {
				eval_int = phalcon_array_isset_string(column, SL("column")+1);
				if (eval_int) {
					PHALCON_ALLOC_ZVAL_MM(r1);
					phalcon_array_fetch_string(&r1, column, SL("column"), PH_NOISY_CC);
					PHALCON_CPY_WRT(column, r1);
					
					PHALCON_INIT_VAR(sql_column);
					PHALCON_CALL_METHOD_PARAMS_2(sql_column, this_ptr, "_getexpression", column, sql_aliases, PH_NO_CHECK);
				} else {
					PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
					return;
				}
			} else {
				PHALCON_ALLOC_ZVAL_MM(i1);
				object_init_ex(i1, phalcon_mvc_model_exception_ce);
				PHALCON_ALLOC_ZVAL_MM(r2);
				PHALCON_CONCAT_SV(r2, "Unknown type of column ", column_type);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r2, PH_CHECK);
				phalcon_throw_exception(i1 TSRMLS_CC);
				return;
			}
		}
	}
	
	
	RETURN_CCTOR(sql_column);
}

PHP_METHOD(Phalcon_Mvc_Model_Query, _getTable){

	zval *manager = NULL, *qualified_name = NULL, *model_name = NULL;
	zval *model = NULL, *source = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &manager, &qualified_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(qualified_name, SL("name")+1);
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

PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoin){

	zval *manager = NULL, *join = NULL, *qualified = NULL, *qualified_type = NULL;
	zval *model_name = NULL, *model = NULL, *source = NULL, *data = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &manager, &join) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(join, SL("qualifiedName")+1);
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

PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoinType){

	zval *join = NULL, *type = NULL, *join_type = NULL;
	zval *i0 = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &join) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(join, SL("type")+1);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	PHALCON_INIT_VAR(type);
	phalcon_array_fetch_string(&type, join, SL("type"), PH_NOISY_CC);
	if (phalcon_compare_strict_long(type, 360 TSRMLS_CC)) {
		PHALCON_INIT_VAR(join_type);
		ZVAL_STRING(join_type, "INNER", 1);
		goto se_111d_3;
	}
	if (phalcon_compare_strict_long(type, 361 TSRMLS_CC)) {
		PHALCON_INIT_VAR(join_type);
		ZVAL_STRING(join_type, "LEFT", 1);
		goto se_111d_3;
	}
	if (phalcon_compare_strict_long(type, 362 TSRMLS_CC)) {
		PHALCON_INIT_VAR(join_type);
		ZVAL_STRING(join_type, "RIGHT", 1);
		goto se_111d_3;
	}
	if (phalcon_compare_strict_long(type, 363 TSRMLS_CC)) {
		PHALCON_INIT_VAR(join_type);
		ZVAL_STRING(join_type, "CROSS", 1);
		goto se_111d_3;
	}
	if (phalcon_compare_strict_long(type, 364 TSRMLS_CC)) {
		PHALCON_INIT_VAR(join_type);
		ZVAL_STRING(join_type, "FULL OUTER", 1);
		goto se_111d_3;
	}
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_mvc_model_exception_ce);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_SV(r0, "Unknown join type ", type);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r0, PH_CHECK);
	phalcon_throw_exception(i0 TSRMLS_CC);
	return;
	se_111d_3:
	
	RETURN_CTOR(join_type);
}

PHP_METHOD(Phalcon_Mvc_Model_Query, _getJoins){

	zval *select = NULL, *manager = NULL, *models = NULL, *sql_aliases = NULL, *sql_joins = NULL;
	zval *join_models = NULL, *join_sources = NULL, *join_types = NULL;
	zval *join_pre_condition = NULL, *joins = NULL, *join_item = NULL;
	zval *join = NULL, *join_data = NULL, *source = NULL, *model_name = NULL, *join_type = NULL;
	zval *alias = NULL, *source_alias = NULL, *join_expr = NULL, *pre_condition = NULL;
	zval *join_alias = NULL, *join_model = NULL, *has_relations = NULL;
	zval *sql_join_conditions = NULL, *relations = NULL, *fields = NULL;
	zval *referenced_fields = NULL, *sql_join_condition = NULL;
	zval *join_source = NULL, *sql_join = NULL;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &select, &manager, &models, &sql_aliases) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(sql_aliases);
	
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
	if (eval_int) {
		if (!phalcon_valid_foreach(joins TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(joins);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_111d_4:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_111d_4;
			}
			
			PHALCON_INIT_VAR(join_item);
			ZVAL_ZVAL(join_item, *hd, 1, 0);
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
			eval_int = phalcon_array_isset_string(joins, SL("alias")+1);
			if (eval_int) {
				PHALCON_INIT_VAR(alias);
				phalcon_array_fetch_string(&alias, joins, SL("alias"), PH_NOISY_CC);
				phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_zval(&join_models, model_name, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
				
				PHALCON_INIT_VAR(source_alias);
				PHALCON_CONCAT_VSV(source_alias, source, " ", alias);
				phalcon_array_update_zval(&join_sources, model_name, &source_alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			} else {
				phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_zval(&join_models, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_zval(&join_sources, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			}
			
			eval_int = phalcon_array_isset_string(join, SL("expr")+1);
			if (eval_int) {
				PHALCON_INIT_VAR(join_expr);
				phalcon_array_fetch_string(&join_expr, join, SL("expr"), PH_NOISY_CC);
				
				PHALCON_INIT_VAR(pre_condition);
				PHALCON_CALL_METHOD_PARAMS_2(pre_condition, this_ptr, "_getexpression", join_expr, sql_aliases, PH_NO_CHECK);
				phalcon_array_update_zval(&join_pre_condition, model_name, &pre_condition, PH_COPY | PH_SEPARATE TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_111d_4;
		fee_111d_4:
		if(0){}
		
	} else {
		PHALCON_INIT_VAR(join);
		phalcon_array_fetch_string(&join, joins, SL("join"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(join_data);
		PHALCON_CALL_METHOD_PARAMS_2(join_data, this_ptr, "_getjoin", manager, join, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(source);
		phalcon_array_fetch_string(&source, join_data, SL("source"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(model_name);
		phalcon_array_fetch_string(&model_name, join_data, SL("model"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(join_type);
		PHALCON_CALL_METHOD_PARAMS_1(join_type, this_ptr, "_getjointype", join, PH_NO_CHECK);
		phalcon_array_update_zval(&join_types, model_name, &join_type, PH_COPY | PH_SEPARATE TSRMLS_CC);
		eval_int = phalcon_array_isset_string(joins, SL("alias")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(alias);
			phalcon_array_fetch_string(&alias, joins, SL("alias"), PH_NOISY_CC);
			phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&join_models, model_name, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(source_alias);
			PHALCON_CONCAT_VSV(source_alias, source, " ", alias);
			phalcon_array_update_zval(&join_sources, model_name, &source_alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&join_models, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&join_sources, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
		
		eval_int = phalcon_array_isset_string(join, SL("expr")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(join_expr);
			phalcon_array_fetch_string(&join_expr, join, SL("expr"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(pre_condition);
			PHALCON_CALL_METHOD_PARAMS_2(pre_condition, this_ptr, "_getexpression", join_expr, sql_aliases, PH_NO_CHECK);
			phalcon_array_update_zval(&join_pre_condition, model_name, &pre_condition, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	}
	
	if (!phalcon_valid_foreach(join_models TSRMLS_CC)) {
		return;
	}
	
	ah1 = Z_ARRVAL_P(join_models);
	zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	fes_111d_5:
		if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
			goto fee_111d_5;
		}
		
		PHALCON_INIT_VAR(join_model);
		PHALCON_GET_FOREACH_KEY(join_model, ah1, hp1);
		PHALCON_INIT_VAR(join_alias);
		ZVAL_ZVAL(join_alias, *hd, 1, 0);
		PHALCON_INIT_VAR(has_relations);
		ZVAL_BOOL(has_relations, 0);
		if (!phalcon_valid_foreach(models TSRMLS_CC)) {
			return;
		}
		
		ah2 = Z_ARRVAL_P(models);
		zend_hash_internal_pointer_reset_ex(ah2, &hp2);
		fes_111d_6:
			if(zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) != SUCCESS){
				goto fee_111d_6;
			}
			
			PHALCON_INIT_VAR(model_name);
			PHALCON_GET_FOREACH_KEY(model_name, ah2, hp2);
			PHALCON_INIT_VAR(source);
			ZVAL_ZVAL(source, *hd, 1, 0);
			PHALCON_INIT_VAR(sql_join_conditions);
			array_init(sql_join_conditions);
			eval_int = phalcon_array_isset(join_pre_condition, join_model);
			if (!eval_int) {
				PHALCON_INIT_VAR(relations);
				PHALCON_CALL_METHOD_PARAMS_2(relations, manager, "getrelations", model_name, join_model, PH_NO_CHECK);
				if (Z_TYPE_P(relations) != IS_BOOL || (Z_TYPE_P(relations) == IS_BOOL && Z_BVAL_P(relations))) {
					PHALCON_INIT_VAR(fields);
					phalcon_array_fetch_string(&fields, relations, SL("fi"), PH_NOISY_CC);
					
					PHALCON_INIT_VAR(referenced_fields);
					phalcon_array_fetch_string(&referenced_fields, relations, SL("rf"), PH_NOISY_CC);
					if (Z_TYPE_P(fields) == IS_ARRAY) { 
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
			goto fes_111d_6;
		fee_111d_6:
		if(0){}
		
		zend_hash_move_forward_ex(ah1, &hp1);
		goto fes_111d_5;
	fee_111d_5:
	
	phalcon_update_property_zval(this_ptr, SL("_tempSQLAliases"), sql_aliases TSRMLS_CC);
	
	RETURN_CTOR(sql_joins);
}

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

PHP_METHOD(Phalcon_Mvc_Model_Query, _getOrderClause){

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
		fes_111d_7:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_111d_7;
			}
			
			PHALCON_INIT_VAR(order_item);
			ZVAL_ZVAL(order_item, *hd, 1, 0);
			PHALCON_INIT_VAR(order_part_expr);
			PHALCON_CALL_METHOD_PARAMS_2(order_part_expr, this_ptr, "_getexpression", order_item, sql_aliases, PH_NO_CHECK);
			phalcon_array_append(&order_parts, order_part_expr, PH_SEPARATE TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_111d_7;
		fee_111d_7:
		
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
		fes_111d_8:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_111d_8;
			}
			
			PHALCON_INIT_VAR(order_item);
			ZVAL_ZVAL(order_item, *hd, 1, 0);
			PHALCON_INIT_VAR(order_part_expr);
			PHALCON_CALL_METHOD_PARAMS_2(order_part_expr, this_ptr, "_getexpression", order_item, sql_aliases, PH_NO_CHECK);
			phalcon_array_append(&order_parts, order_part_expr, PH_SEPARATE TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_111d_8;
		fee_111d_8:
		
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

PHP_METHOD(Phalcon_Mvc_Model_Query, _executeSelect){

	zval *manager = NULL, *ast = NULL, *select = NULL, *sql_tables = NULL, *sql_aliases = NULL;
	zval *models = NULL, *tables = NULL, *table = NULL, *qualified_name = NULL;
	zval *model_name = NULL, *source = NULL, *alias = NULL, *source_alias = NULL;
	zval *sql_joins = NULL, *sql_columns = NULL, *columns = NULL, *column = NULL;
	zval *sql_column = NULL, *column_alias = NULL, *sql_select = NULL;
	zval *where = NULL, *where_expr = NULL, *group_by = NULL, *sql_group = NULL;
	zval *having = NULL, *having_expr = NULL, *order = NULL, *sql_order = NULL;
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

	PHALCON_INIT_VAR(select);
	phalcon_array_fetch_string(&select, ast, SL("select"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(select, SL("tables")+1);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	PHALCON_INIT_VAR(sql_tables);
	array_init(sql_tables);
	
	PHALCON_INIT_VAR(sql_aliases);
	array_init(sql_aliases);
	
	PHALCON_INIT_VAR(models);
	array_init(models);
	
	PHALCON_INIT_VAR(tables);
	phalcon_array_fetch_string(&tables, select, SL("tables"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(tables, 0);
	if (eval_int) {
		if (!phalcon_valid_foreach(tables TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(tables);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_111d_9:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_111d_9;
			}
			
			PHALCON_INIT_VAR(table);
			ZVAL_ZVAL(table, *hd, 1, 0);
			PHALCON_INIT_VAR(qualified_name);
			phalcon_array_fetch_string(&qualified_name, table, SL("qualifiedName"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(model_name);
			phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(source);
			PHALCON_CALL_METHOD_PARAMS_2(source, this_ptr, "_gettable", manager, qualified_name, PH_NO_CHECK);
			eval_int = phalcon_array_isset_string(table, SL("alias")+1);
			if (eval_int) {
				PHALCON_INIT_VAR(alias);
				phalcon_array_fetch_string(&alias, table, SL("alias"), PH_NOISY_CC);
				phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
				
				PHALCON_INIT_VAR(source_alias);
				PHALCON_CONCAT_VSV(source_alias, source, " ", alias);
				phalcon_array_append(&sql_tables, source_alias, PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_zval(&models, model_name, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			} else {
				phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
				phalcon_array_append(&sql_tables, source, PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_zval(&models, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_111d_9;
		fee_111d_9:
		if(0){}
		
	} else {
		PHALCON_INIT_VAR(qualified_name);
		phalcon_array_fetch_string(&qualified_name, tables, SL("qualifiedName"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(source);
		PHALCON_CALL_METHOD_PARAMS_2(source, this_ptr, "_gettable", manager, qualified_name, PH_NO_CHECK);
		eval_int = phalcon_array_isset_string(tables, SL("alias")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(alias);
			phalcon_array_fetch_string(&alias, tables, SL("alias"), PH_NOISY_CC);
			phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(source_alias);
			PHALCON_CONCAT_VSV(source_alias, source, " ", alias);
			phalcon_array_append(&sql_tables, source_alias, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&models, model_name, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_tables, source, PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_zval(&models, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	}
	
	eval_int = phalcon_array_isset_string(select, SL("joins")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(sql_joins);
		PHALCON_CALL_METHOD_PARAMS_4(sql_joins, this_ptr, "_getjoins", select, manager, models, sql_aliases, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(sql_aliases);
		phalcon_read_property(&sql_aliases, this_ptr, SL("_tempSQLAliases"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(sql_joins);
		array_init(sql_joins);
	}
	
	eval_int = phalcon_array_isset_string(select, SL("columns")+1);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted SELECT AST");
		return;
	}
	
	PHALCON_INIT_VAR(sql_columns);
	array_init(sql_columns);
	
	PHALCON_INIT_VAR(columns);
	phalcon_array_fetch_string(&columns, select, SL("columns"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(columns, 0);
	if (eval_int) {
		if (!phalcon_valid_foreach(columns TSRMLS_CC)) {
			return;
		}
		
		ah1 = Z_ARRVAL_P(columns);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_111d_10:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_111d_10;
			}
			
			PHALCON_INIT_VAR(column);
			ZVAL_ZVAL(column, *hd, 1, 0);
			PHALCON_INIT_VAR(sql_column);
			PHALCON_CALL_METHOD_PARAMS_2(sql_column, this_ptr, "_getselectcolumn", column, sql_aliases, PH_NO_CHECK);
			eval_int = phalcon_array_isset_string(column, SL("alias")+1);
			if (eval_int) {
				PHALCON_INIT_VAR(column_alias);
				phalcon_array_fetch_string(&column_alias, column, SL("alias"), PH_NOISY_CC);
				phalcon_array_update_zval(&sql_columns, column_alias, &sql_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
			} else {
				phalcon_array_append(&sql_columns, sql_column, PH_SEPARATE TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_111d_10;
		fee_111d_10:
		if(0){}
		
	} else {
		PHALCON_INIT_VAR(sql_column);
		PHALCON_CALL_METHOD_PARAMS_2(sql_column, this_ptr, "_getselectcolumn", columns, sql_aliases, PH_NO_CHECK);
		eval_int = phalcon_array_isset_string(columns, SL("alias")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(column_alias);
			phalcon_array_fetch_string(&column_alias, columns, SL("alias"), PH_NOISY_CC);
			phalcon_array_update_zval(&sql_columns, column_alias, &sql_column, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_append(&sql_columns, sql_column, PH_SEPARATE TSRMLS_CC);
		}
	}
	
	PHALCON_INIT_VAR(sql_select);
	array_init(sql_select);
	phalcon_array_update_string(&sql_select, SL("columns"), &sql_columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_select, SL("tables"), &sql_tables, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_select, SL("joins"), &sql_joins, PH_COPY | PH_SEPARATE TSRMLS_CC);
	eval_int = phalcon_array_isset_string(ast, SL("where")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(where);
		phalcon_array_fetch_string(&where, ast, SL("where"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(where_expr);
		PHALCON_CALL_METHOD_PARAMS_2(where_expr, this_ptr, "_getexpression", where, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_select, SL("where"), &where_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(ast, SL("groupBy")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(group_by);
		phalcon_array_fetch_string(&group_by, ast, SL("groupBy"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(sql_group);
		PHALCON_CALL_METHOD_PARAMS_2(sql_group, this_ptr, "_getgroupclause", group_by, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_select, SL("group"), &sql_group, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(ast, SL("having")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(having);
		phalcon_array_fetch_string(&having, ast, SL("having"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(having_expr);
		PHALCON_CALL_METHOD_PARAMS_2(having_expr, this_ptr, "_getexpression", having, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_select, SL("having"), &having_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(ast, SL("orderBy")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(order);
		phalcon_array_fetch_string(&order, ast, SL("orderBy"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(sql_order);
		PHALCON_CALL_METHOD_PARAMS_2(sql_order, this_ptr, "_getorderclause", order, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_select, SL("orderBy"), &sql_order, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(ast, SL("limit")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(limit);
		phalcon_array_fetch_string(&limit, ast, SL("limit"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(sql_limit);
		PHALCON_CALL_METHOD_PARAMS_2(sql_limit, this_ptr, "_getlimitclause", limit, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_select, SL("limit"), &sql_limit, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	
	RETURN_CTOR(sql_select);
}

PHP_METHOD(Phalcon_Mvc_Model_Query, _executeInsert){

	zval *manager = NULL, *ast = NULL, *qualified_name = NULL, *model_name = NULL;
	zval *source = NULL, *sql_aliases = NULL, *expr_values = NULL, *values = NULL;
	zval *expr_value = NULL, *expr_insert = NULL, *sql_insert = NULL;
	zval *sql_fields = NULL, *fields = NULL, *field = NULL, *name = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &manager, &ast) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(ast, SL("qualifiedName")+1);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted INSERT AST");
		return;
	}
	eval_int = phalcon_array_isset_string(ast, SL("values")+1);
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
	if (!phalcon_valid_foreach(values TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(values);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_111d_11:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_111d_11;
		}
		
		PHALCON_INIT_VAR(expr_value);
		ZVAL_ZVAL(expr_value, *hd, 1, 0);
		PHALCON_INIT_VAR(expr_insert);
		PHALCON_CALL_METHOD_PARAMS_2(expr_insert, this_ptr, "_getexpression", expr_value, sql_aliases, PH_NO_CHECK);
		phalcon_array_append(&expr_values, expr_insert, PH_SEPARATE TSRMLS_CC);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_111d_11;
	fee_111d_11:
	
	PHALCON_INIT_VAR(sql_insert);
	array_init(sql_insert);
	phalcon_array_update_string(&sql_insert, SL("model"), &model_name, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_insert, SL("table"), &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
	eval_int = phalcon_array_isset_string(ast, SL("fields")+1);
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
		fes_111d_12:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_111d_12;
			}
			
			PHALCON_INIT_VAR(field);
			ZVAL_ZVAL(field, *hd, 1, 0);
			PHALCON_INIT_VAR(name);
			phalcon_array_fetch_string(&name, field, SL("name"), PH_NOISY_CC);
			phalcon_array_append(&sql_fields, name, PH_SEPARATE TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_111d_12;
		fee_111d_12:
		
		phalcon_array_update_string(&sql_insert, SL("fields"), &sql_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	phalcon_array_update_string(&sql_insert, SL("values"), &expr_values, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	RETURN_CTOR(sql_insert);
}

PHP_METHOD(Phalcon_Mvc_Model_Query, _executeUpdate){

	zval *manager = NULL, *ast = NULL, *update = NULL, *models = NULL, *sql_aliases = NULL;
	zval *sql_tables = NULL, *tables = NULL, *table = NULL, *qualified_name = NULL;
	zval *model_name = NULL, *source = NULL, *alias = NULL, *source_alias = NULL;
	zval *sql_fields = NULL, *sql_values = NULL, *values = NULL, *update_value = NULL;
	zval *column = NULL, *sql_column = NULL, *expr_column = NULL, *expr_value = NULL;
	zval *sql_update = NULL, *where = NULL, *where_expr = NULL, *limit = NULL, *sql_limit = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &manager, &ast) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(ast, SL("update")+1);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST");
		return;
	}
	
	PHALCON_INIT_VAR(update);
	phalcon_array_fetch_string(&update, ast, SL("update"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(update, SL("tables")+1);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted UPDATE AST");
		return;
	}
	
	eval_int = phalcon_array_isset_string(update, SL("values")+1);
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
	if (eval_int) {
		if (!phalcon_valid_foreach(tables TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(tables);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_111d_13:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_111d_13;
			}
			
			PHALCON_INIT_VAR(table);
			ZVAL_ZVAL(table, *hd, 1, 0);
			PHALCON_INIT_VAR(qualified_name);
			phalcon_array_fetch_string(&qualified_name, table, SL("qualifiedName"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(model_name);
			phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(source);
			PHALCON_CALL_METHOD_PARAMS_2(source, this_ptr, "_gettable", manager, qualified_name, PH_NO_CHECK);
			eval_int = phalcon_array_isset_string(table, SL("alias")+1);
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
			goto fes_111d_13;
		fee_111d_13:
		if(0){}
		
	} else {
		PHALCON_INIT_VAR(qualified_name);
		phalcon_array_fetch_string(&qualified_name, tables, SL("qualifiedName"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(source);
		PHALCON_CALL_METHOD_PARAMS_2(source, this_ptr, "_gettable", manager, qualified_name, PH_NO_CHECK);
		eval_int = phalcon_array_isset_string(tables, SL("alias")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(alias);
			phalcon_array_fetch_string(&alias, tables, SL("alias"), PH_NOISY_CC);
			phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(source_alias);
			PHALCON_CONCAT_VSV(source_alias, source, " ", alias);
			phalcon_array_append(&sql_tables, source_alias, PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_tables, source, PH_SEPARATE TSRMLS_CC);
		}
		
		phalcon_array_append(&models, model_name, PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(sql_fields);
	array_init(sql_fields);
	
	PHALCON_INIT_VAR(sql_values);
	array_init(sql_values);
	
	PHALCON_INIT_VAR(values);
	phalcon_array_fetch_string(&values, update, SL("values"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_long(values, 0);
	if (eval_int) {
		if (!phalcon_valid_foreach(values TSRMLS_CC)) {
			return;
		}
		
		ah1 = Z_ARRVAL_P(values);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_111d_14:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_111d_14;
			}
			
			PHALCON_INIT_VAR(update_value);
			ZVAL_ZVAL(update_value, *hd, 1, 0);
			PHALCON_INIT_VAR(column);
			phalcon_array_fetch_string(&column, update_value, SL("column"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(sql_column);
			PHALCON_CALL_METHOD_PARAMS_2(sql_column, this_ptr, "_getexpression", column, sql_aliases, PH_NO_CHECK);
			phalcon_array_append(&sql_fields, sql_column, PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(expr_column);
			phalcon_array_fetch_string(&expr_column, update_value, SL("expr"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(expr_value);
			PHALCON_CALL_METHOD_PARAMS_2(expr_value, this_ptr, "_getexpression", expr_column, sql_aliases, PH_NO_CHECK);
			phalcon_array_append(&sql_values, expr_value, PH_SEPARATE TSRMLS_CC);
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_111d_14;
		fee_111d_14:
		if(0){}
		
	} else {
		PHALCON_INIT_VAR(column);
		phalcon_array_fetch_string(&column, values, SL("column"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(sql_column);
		PHALCON_CALL_METHOD_PARAMS_2(sql_column, this_ptr, "_getexpression", column, sql_aliases, PH_NO_CHECK);
		phalcon_array_append(&sql_fields, sql_column, PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_VAR(expr_column);
		phalcon_array_fetch_string(&expr_column, values, SL("expr"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(expr_value);
		PHALCON_CALL_METHOD_PARAMS_2(expr_value, this_ptr, "_getexpression", expr_column, sql_aliases, PH_NO_CHECK);
		phalcon_array_append(&sql_values, expr_value, PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(sql_update);
	array_init(sql_update);
	phalcon_array_update_string(&sql_update, SL("tables"), &sql_tables, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_update, SL("models"), &models, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_update, SL("fields"), &sql_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_update, SL("values"), &sql_values, PH_COPY | PH_SEPARATE TSRMLS_CC);
	eval_int = phalcon_array_isset_string(ast, SL("where")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(where);
		phalcon_array_fetch_string(&where, ast, SL("where"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(where_expr);
		PHALCON_CALL_METHOD_PARAMS_2(where_expr, this_ptr, "_getexpression", where, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_update, SL("where"), &where_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(ast, SL("limit")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(limit);
		phalcon_array_fetch_string(&limit, ast, SL("limit"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(sql_limit);
		PHALCON_CALL_METHOD_PARAMS_2(sql_limit, this_ptr, "_getlimitclause", limit, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_update, SL("limit"), &sql_limit, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	
	RETURN_CTOR(sql_update);
}

PHP_METHOD(Phalcon_Mvc_Model_Query, _executeDelete){

	zval *manager = NULL, *ast = NULL, *delete = NULL, *models = NULL, *sql_aliases = NULL;
	zval *sql_tables = NULL, *tables = NULL, *table = NULL, *qualified_name = NULL;
	zval *model_name = NULL, *source = NULL, *alias = NULL, *source_alias = NULL;
	zval *sql_delete = NULL, *where = NULL, *where_expr = NULL, *limit = NULL, *sql_limit = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &manager, &ast) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(ast, SL("delete")+1);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Corrupted DELETE AST");
		return;
	}
	
	PHALCON_INIT_VAR(delete);
	phalcon_array_fetch_string(&delete, ast, SL("delete"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(delete, SL("tables")+1);
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
	if (eval_int) {
		if (!phalcon_valid_foreach(tables TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(tables);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_111d_15:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_111d_15;
			}
			
			PHALCON_INIT_VAR(table);
			ZVAL_ZVAL(table, *hd, 1, 0);
			PHALCON_INIT_VAR(qualified_name);
			phalcon_array_fetch_string(&qualified_name, table, SL("qualifiedName"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(model_name);
			phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(source);
			PHALCON_CALL_METHOD_PARAMS_2(source, this_ptr, "_gettable", manager, qualified_name, PH_NO_CHECK);
			eval_int = phalcon_array_isset_string(table, SL("alias")+1);
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
			goto fes_111d_15;
		fee_111d_15:
		if(0){}
		
	} else {
		PHALCON_INIT_VAR(qualified_name);
		phalcon_array_fetch_string(&qualified_name, tables, SL("qualifiedName"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(model_name);
		phalcon_array_fetch_string(&model_name, qualified_name, SL("name"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(source);
		PHALCON_CALL_METHOD_PARAMS_2(source, this_ptr, "_gettable", manager, qualified_name, PH_NO_CHECK);
		eval_int = phalcon_array_isset_string(tables, SL("alias")+1);
		if (eval_int) {
			PHALCON_INIT_VAR(alias);
			phalcon_array_fetch_string(&alias, tables, SL("alias"), PH_NOISY_CC);
			phalcon_array_update_zval(&sql_aliases, alias, &alias, PH_COPY | PH_SEPARATE TSRMLS_CC);
			
			PHALCON_INIT_VAR(source_alias);
			PHALCON_CONCAT_VSV(source_alias, source, " ", alias);
			phalcon_array_append(&sql_tables, source_alias, PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&sql_aliases, model_name, &source, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&sql_tables, source, PH_SEPARATE TSRMLS_CC);
		}
		
		phalcon_array_append(&models, model_name, PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(sql_delete);
	array_init(sql_delete);
	phalcon_array_update_string(&sql_delete, SL("tables"), &sql_tables, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&sql_delete, SL("models"), &models, PH_COPY | PH_SEPARATE TSRMLS_CC);
	eval_int = phalcon_array_isset_string(ast, SL("where")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(where);
		phalcon_array_fetch_string(&where, ast, SL("where"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(where_expr);
		PHALCON_CALL_METHOD_PARAMS_2(where_expr, this_ptr, "_getexpression", where, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_delete, SL("where"), &where_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(ast, SL("limit")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(limit);
		phalcon_array_fetch_string(&limit, ast, SL("limit"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(sql_limit);
		PHALCON_CALL_METHOD_PARAMS_2(sql_limit, this_ptr, "_getlimitclause", limit, sql_aliases, PH_NO_CHECK);
		phalcon_array_update_string(&sql_delete, SL("limit"), &sql_limit, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	
	RETURN_CTOR(sql_delete);
}

PHP_METHOD(Phalcon_Mvc_Model_Query, parse){

	zval *parsedph_ql = NULL, *ast = NULL, *dependency_injector = NULL;
	zval *manager = NULL, *type = NULL, *exception_message = NULL, *exception = NULL;
	zval *c0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(parsedph_ql);
	ZVAL_NULL(parsedph_ql);
	
	PHALCON_INIT_VAR(ast);
	phalcon_read_property(&ast, this_ptr, SL("_ast"), PH_NOISY_CC);
	if (Z_TYPE_P(ast) == IS_ARRAY) { 
		eval_int = phalcon_array_isset_string(ast, SL("type")+1);
		if (eval_int) {
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
			
			PHALCON_INIT_VAR(type);
			phalcon_array_fetch_string(&type, ast, SL("type"), PH_NOISY_CC);
			if (phalcon_compare_strict_long(type, 309 TSRMLS_CC)) {
				PHALCON_INIT_VAR(parsedph_ql);
				PHALCON_CALL_METHOD_PARAMS_2(parsedph_ql, this_ptr, "_executeselect", manager, ast, PH_NO_CHECK);
				goto se_111d_16;
			}
			if (phalcon_compare_strict_long(type, 306 TSRMLS_CC)) {
				PHALCON_INIT_VAR(parsedph_ql);
				PHALCON_CALL_METHOD_PARAMS_2(parsedph_ql, this_ptr, "_executeinsert", manager, ast, PH_NO_CHECK);
				goto se_111d_16;
			}
			if (phalcon_compare_strict_long(type, 300 TSRMLS_CC)) {
				PHALCON_INIT_VAR(parsedph_ql);
				PHALCON_CALL_METHOD_PARAMS_2(parsedph_ql, this_ptr, "_executeupdate", manager, ast, PH_NO_CHECK);
				goto se_111d_16;
			}
			if (phalcon_compare_strict_long(type, 303 TSRMLS_CC)) {
				PHALCON_INIT_VAR(parsedph_ql);
				PHALCON_CALL_METHOD_PARAMS_2(parsedph_ql, this_ptr, "_executedelete", manager, ast, PH_NO_CHECK);
				goto se_111d_16;
			}
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SV(exception_message, "Unknown statement ", type);
			
			PHALCON_INIT_VAR(exception);
			object_init_ex(exception, phalcon_mvc_model_exception_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
			phalcon_throw_exception(exception TSRMLS_CC);
			return;
			se_111d_16:
			if(0){}
		}
	}
	
	if (Z_TYPE_P(parsedph_ql) == IS_NULL) {
		PHALCON_INIT_VAR(exception_message);
		ZVAL_STRING(exception_message, "Corrupted AST", 1);
		
		PHALCON_INIT_VAR(exception);
		object_init_ex(exception, phalcon_mvc_model_exception_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
		phalcon_throw_exception(exception TSRMLS_CC);
		return;
	}
	
	
	RETURN_CCTOR(parsedph_ql);
}

PHP_METHOD(Phalcon_Mvc_Model_Query, execute){

	zval *sql_statement = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(sql_statement);
	PHALCON_CALL_METHOD(sql_statement, this_ptr, "parse", PH_NO_CHECK);
	
	PHALCON_MM_RESTORE();
}

