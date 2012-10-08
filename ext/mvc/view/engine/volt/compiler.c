
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

#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "mvc/view/engine/volt/scanner.h"
#include "mvc/view/engine/volt/compiler.h"

/**
 * Phalcon\Mvc\View\Engine\Volt\Compiler
 *
 * This class reads and compiles volt templates into PHP plain code
 */

/**
 * Resolves function intermediate code into PHP function calls
 *
 * @param array $expr
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _functionCall){

	zval *expr, *func_arguments, *arguments = NULL, *name;
	zval *code = NULL, *camelized, *method, *class_name, *exception_message;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &expr) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(expr, SS("arguments"));
	if (eval_int) {
		PHALCON_INIT_VAR(func_arguments);
		phalcon_array_fetch_string(&func_arguments, expr, SL("arguments"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(arguments);
		PHALCON_CALL_METHOD_PARAMS_1(arguments, this_ptr, "_expression", func_arguments, PH_NO_CHECK);
	} else {
		PHALCON_INIT_NVAR(arguments);
		ZVAL_STRING(arguments, "", 1);
	}
	
	PHALCON_INIT_VAR(name);
	phalcon_array_fetch_string(&name, expr, SL("name"), PH_NOISY_CC);
	if (PHALCON_COMPARE_STRING(name, "content")) {
		PHALCON_INIT_VAR(code);
		ZVAL_STRING(code, "$this->getContent()", 1);
		
		RETURN_CTOR(code);
	}
	
	PHALCON_INIT_VAR(camelized);
	PHALCON_CALL_STATIC_PARAMS_1(camelized, "phalcon\\text", "camelize", name);
	
	PHALCON_INIT_VAR(method);
	PHALCON_CALL_FUNC_PARAMS_1(method, "lcfirst", camelized);
	
	PHALCON_INIT_VAR(class_name);
	ZVAL_STRING(class_name, "Phalcon\\Tag", 1);
	if (phalcon_method_exists(class_name, method TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVSVS(code, "Phalcon\\Tag::", method, "(", arguments, ")");
		
		RETURN_CTOR(code);
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SV(exception_message, "Undefined function ", name);
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
	return;
}

/**
 * Resolves filter intermediate code into PHP function calls
 *
 * @param array $expr
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _filter){

	zval *filter, *left, *exists = NULL, *type, *code = NULL, *name, *exception_message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &filter, &left) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(exists);
	ZVAL_BOOL(exists, 0);
	
	PHALCON_INIT_VAR(type);
	phalcon_array_fetch_string(&type, filter, SL("type"), PH_NOISY_CC);
	if (phalcon_compare_strict_long(type, 355 TSRMLS_CC)) {
		PHALCON_INIT_VAR(code);
		
		PHALCON_INIT_VAR(name);
		phalcon_array_fetch_string(&name, filter, SL("name"), PH_NOISY_CC);
		if (PHALCON_COMPARE_STRING(name, "length")) {
			PHALCON_CONCAT_SVS(code, "$this->count(", left, ")");
			
			ZVAL_BOOL(exists, 1);
		}
		
		if (PHALCON_COMPARE_STRING(name, "e")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "$this->escaper->escapeHtml(", left, ")");
			
			ZVAL_BOOL(exists, 1);
		}
		
		if (PHALCON_COMPARE_STRING(name, "escape")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "$this->escaper->escapeHtml(", left, ")");
			
			ZVAL_BOOL(exists, 1);
		}
		
		if (PHALCON_COMPARE_STRING(name, "trim")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "trim(", left, ")");
			
			ZVAL_BOOL(exists, 1);
		}
		
		if (PHALCON_COMPARE_STRING(name, "striptags")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "striptags(", left, ")");
			
			ZVAL_BOOL(exists, 1);
		}
		
		if (PHALCON_COMPARE_STRING(name, "slashes")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "addslashes(", left, ")");
			
			ZVAL_BOOL(exists, 1);
		}
		
		if (PHALCON_COMPARE_STRING(name, "stripslashes")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "stripslashes(", left, ")");
			
			ZVAL_BOOL(exists, 1);
		}
		
		if (PHALCON_COMPARE_STRING(name, "lowercase")) {
			if (phalcon_function_exists_ex(SS("mb_strtolower") TSRMLS_CC) == SUCCESS) {
				PHALCON_INIT_NVAR(code);
				PHALCON_CONCAT_SVS(code, "mb_strtolower(", left, ")");
			} else {
				PHALCON_INIT_NVAR(code);
				PHALCON_CONCAT_SVS(code, "strtolower(", left, ")");
			}
			
			ZVAL_BOOL(exists, 1);
		}
		
		if (PHALCON_COMPARE_STRING(name, "lowercase")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "strtolower(", left, ")");
			
			ZVAL_BOOL(exists, 1);
		}
		
		if (PHALCON_IS_TRUE(exists)) {
			
			RETURN_CCTOR(code);
		}
		
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "fak u filter");
		return;
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SV(exception_message, "Unknown filter type ", type);
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
	return;
}

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _expression){

	zval *expr, *prepend_dollar = NULL, *expr_code = NULL, *items;
	zval *exprs = NULL, *single_expr = NULL, *single_expr_expr = NULL;
	zval *single_expr_code = NULL, *name = NULL, *parameter = NULL, *joined_items;
	zval *type, *left, *left_code, *right_code = NULL, *right;
	zval *applied_filter, *qualified, *qualified_code;
	zval *qualified_arrow, *value, *exception_message;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &expr, &prepend_dollar) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!prepend_dollar) {
		PHALCON_INIT_NVAR(prepend_dollar);
		ZVAL_BOOL(prepend_dollar, 1);
	} else {
		PHALCON_SEPARATE_PARAM(prepend_dollar);
	}
	
	PHALCON_INIT_VAR(expr_code);
	eval_int = phalcon_array_isset_string(expr, SS("type"));
	if (!eval_int) {
		ZVAL_STRING(expr_code, "array(", 1);
		
		PHALCON_INIT_VAR(items);
		array_init(items);
		eval_int = phalcon_array_isset_long(expr, 0);
		if (!eval_int) {
			PHALCON_INIT_VAR(exprs);
			array_init(exprs);
			phalcon_array_append(&exprs, expr, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(exprs, expr);
		}
		
		
		if (!phalcon_valid_foreach(exprs TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(exprs);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_VALUE(single_expr);
			
			PHALCON_INIT_NVAR(single_expr_expr);
			phalcon_array_fetch_string(&single_expr_expr, single_expr, SL("expr"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(single_expr_code);
			PHALCON_CALL_METHOD_PARAMS_1(single_expr_code, this_ptr, "_expression", single_expr_expr, PH_NO_CHECK);
			eval_int = phalcon_array_isset_string(single_expr, SS("name"));
			if (eval_int) {
				PHALCON_INIT_NVAR(name);
				phalcon_array_fetch_string(&name, single_expr, SL("name"), PH_NOISY_CC);
				
				PHALCON_INIT_NVAR(parameter);
				PHALCON_CONCAT_SVSV(parameter, "'", name, "' => ", single_expr_code);
				phalcon_array_append(&items, parameter, PH_SEPARATE TSRMLS_CC);
			} else {
				phalcon_array_append(&items, single_expr_code, PH_SEPARATE TSRMLS_CC);
			}
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
			
		ph_cycle_end_0:
		
		PHALCON_INIT_VAR(joined_items);
		phalcon_fast_join_str(joined_items, SL(", "), items TSRMLS_CC);
		PHALCON_SCONCAT_VS(expr_code, joined_items, ")");
		
		RETURN_CCTOR(expr_code);
	}
	
	PHALCON_INIT_VAR(type);
	phalcon_array_fetch_string(&type, expr, SL("type"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(expr, SS("left"));
	if (eval_int) {
		PHALCON_INIT_VAR(left);
		phalcon_array_fetch_string(&left, expr, SL("left"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(left_code);
		PHALCON_CALL_METHOD_PARAMS_1(left_code, this_ptr, "_expression", left, PH_NO_CHECK);
	}
	
	if (phalcon_compare_strict_long(type, 124 TSRMLS_CC)) {
		PHALCON_INIT_VAR(right_code);
		phalcon_array_fetch_string(&right_code, expr, SL("right"), PH_NOISY_CC);
	} else {
		eval_int = phalcon_array_isset_string(expr, SS("right"));
		if (eval_int) {
			PHALCON_INIT_VAR(right);
			phalcon_array_fetch_string(&right, expr, SL("right"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(right_code);
			PHALCON_CALL_METHOD_PARAMS_1(right_code, this_ptr, "_expression", right, PH_NO_CHECK);
		}
	}
	
	PHALCON_INIT_NVAR(expr_code);
	
	if (phalcon_compare_strict_long(type, 33 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_SV(expr_code, "!", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 42 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " * ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 43 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " + ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 45 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " - ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 47 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " / ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 37 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " % ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 60 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " < ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 61 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " > ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 62 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " > ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 126 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " . ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 124 TSRMLS_CC)) {
		PHALCON_INIT_VAR(applied_filter);
		PHALCON_CALL_METHOD_PARAMS_2(applied_filter, this_ptr, "_filter", right_code, left_code, PH_NO_CHECK);
		PHALCON_CPY_WRT(expr_code, applied_filter);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 355 TSRMLS_CC)) {
		if (PHALCON_IS_TRUE(prepend_dollar)) {
			PHALCON_INIT_NVAR(expr_code);
			ZVAL_STRING(expr_code, "$", 1);
			
			PHALCON_INIT_NVAR(prepend_dollar);
			ZVAL_BOOL(prepend_dollar, 0);
		}
		eval_int = phalcon_array_isset_string(expr, SS("qualified"));
		if (eval_int) {
			PHALCON_INIT_VAR(qualified);
			phalcon_array_fetch_string(&qualified, expr, SL("qualified"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(qualified_code);
			PHALCON_CALL_METHOD_PARAMS_2(qualified_code, this_ptr, "_expression", qualified, prepend_dollar, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(qualified_arrow);
			PHALCON_CONCAT_VS(qualified_arrow, qualified_code, "->");
			phalcon_concat_self(expr_code, qualified_arrow TSRMLS_CC);
		}
		
		PHALCON_INIT_NVAR(name);
		phalcon_array_fetch_string(&name, expr, SL("name"), PH_NOISY_CC);
		phalcon_concat_self(expr_code, name TSRMLS_CC);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 360 TSRMLS_CC)) {
		PHALCON_CPY_WRT(expr_code, left_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 258 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		phalcon_array_fetch_string(&expr_code, expr, SL("value"), PH_NOISY_CC);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 259 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		phalcon_array_fetch_string(&expr_code, expr, SL("value"), PH_NOISY_CC);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 260 TSRMLS_CC)) {
		PHALCON_INIT_VAR(value);
		phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
		
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_SVS(expr_code, "'", value, "'");
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 263 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		ZVAL_STRING(expr_code, "true", 1);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 262 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		ZVAL_STRING(expr_code, "false", 1);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 266 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " && ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 270 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " <= ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 271 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " >= ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 272 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " == ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 273 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " != ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 274 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " === ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 275 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSV(expr_code, left_code, " !== ", right_code);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 276 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_SVSVS(expr_code, "range(", left_code, ", ", right_code, ")");
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 350 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CALL_METHOD_PARAMS_1(expr_code, this_ptr, "_functioncall", expr, PH_NO_CHECK);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 356 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_SVS(expr_code, "(", left_code, ")");
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 361 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_VSVS(expr_code, left_code, "[", right_code, "]");
		goto ph_end_1;
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SV(exception_message, "Unknown expression ", type);
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
	return;
	
	ph_end_1:
	
	RETURN_CCTOR(expr_code);
}

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementList){

	zval *statements, *number_elements, *compilation;
	zval *exec_statements = NULL, *statement = NULL, *expr = NULL, *expr_code = NULL;
	zval *type = NULL, *code = NULL, *block_statements = NULL, *qualified = NULL;
	zval *qualified_code = NULL, *exception_message = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &statements) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(number_elements);
	phalcon_fast_count(number_elements, statements TSRMLS_CC);
	if (phalcon_compare_strict_long(number_elements, 0 TSRMLS_CC)) {
		PHALCON_MM_RESTORE();
		RETURN_STRING("", 1);
	}
	
	PHALCON_INIT_VAR(compilation);
	ZVAL_STRING(compilation, "", 1);
	eval_int = phalcon_array_isset_long(statements, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(exec_statements);
		array_init(exec_statements);
		phalcon_array_append(&exec_statements, statements, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(exec_statements, statements);
	}
	
	
	if (!phalcon_valid_foreach(exec_statements TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(exec_statements);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(statement);
		
		eval_int = phalcon_array_isset_string(statement, SS("expr"));
		if (eval_int) {
			PHALCON_INIT_NVAR(expr);
			phalcon_array_fetch_string(&expr, statement, SL("expr"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CALL_METHOD_PARAMS_1(expr_code, this_ptr, "_expression", expr, PH_NO_CHECK);
		}
		eval_int = phalcon_array_isset_string(statement, SS("type"));
		if (!eval_int) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Invalid statement");
			return;
		}
		
		PHALCON_INIT_NVAR(type);
		phalcon_array_fetch_string(&type, statement, SL("type"), PH_NOISY_CC);
		
		if (phalcon_compare_strict_long(type, 357 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(code);
			phalcon_array_fetch_string(&code, statement, SL("value"), PH_NOISY_CC);
			phalcon_concat_self(compilation, code TSRMLS_CC);
			goto ph_end_1;
		}
		
		if (phalcon_compare_strict_long(type, 300 TSRMLS_CC)) {
			PHALCON_SCONCAT_SVS(compilation, "<?php if (", expr_code, ") { ?>");
			PHALCON_INIT_NVAR(block_statements);
			phalcon_array_fetch_string(&block_statements, statement, SL("true_statements"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(code);
			PHALCON_CALL_METHOD_PARAMS_1(code, this_ptr, "_statementlist", block_statements, PH_NO_CHECK);
			phalcon_concat_self(compilation, code TSRMLS_CC);
			eval_int = phalcon_array_isset_string(statement, SS("false_statements"));
			if (eval_int) {
				phalcon_concat_self_str(compilation, SL("<?php } else { ?>") TSRMLS_CC);
				
				PHALCON_INIT_NVAR(block_statements);
				phalcon_array_fetch_string(&block_statements, statement, SL("false_statements"), PH_NOISY_CC);
				
				PHALCON_INIT_NVAR(code);
				PHALCON_CALL_METHOD_PARAMS_1(code, this_ptr, "_statementlist", block_statements, PH_NO_CHECK);
				phalcon_concat_self(compilation, code TSRMLS_CC);
			}
			
			phalcon_concat_self_str(compilation, SL("<?php } ?>") TSRMLS_CC);
			goto ph_end_1;
		}
		
		if (phalcon_compare_strict_long(type, 304 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(qualified);
			phalcon_array_fetch_string(&qualified, statement, SL("qualified"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(qualified_code);
			PHALCON_CALL_METHOD_PARAMS_1(qualified_code, this_ptr, "_expression", qualified, PH_NO_CHECK);
			PHALCON_SCONCAT_SVSVS(compilation, "<?php foreach (", expr_code, " as ", qualified_code, ") { ?>");
			
			PHALCON_INIT_NVAR(block_statements);
			phalcon_array_fetch_string(&block_statements, statement, SL("block_statements"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(code);
			PHALCON_CALL_METHOD_PARAMS_1(code, this_ptr, "_statementlist", block_statements, PH_NO_CHECK);
			phalcon_concat_self(compilation, code TSRMLS_CC);
			phalcon_concat_self_str(compilation, SL("<?php } ?>") TSRMLS_CC);
			goto ph_end_1;
		}
		
		if (phalcon_compare_strict_long(type, 306 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(qualified);
			phalcon_array_fetch_string(&qualified, statement, SL("qualified"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(qualified_code);
			PHALCON_CALL_METHOD_PARAMS_1(qualified_code, this_ptr, "_expression", qualified, PH_NO_CHECK);
			PHALCON_SCONCAT_SVSVS(compilation, "<?php ", qualified_code, " = ", expr_code, "; ?>");
			goto ph_end_1;
		}
		
		if (phalcon_compare_strict_long(type, 359 TSRMLS_CC)) {
			PHALCON_SCONCAT_SVS(compilation, "<?php echo ", expr_code, "; ?>");
			goto ph_end_1;
		}
		
		PHALCON_INIT_NVAR(exception_message);
		PHALCON_CONCAT_SV(exception_message, "Unknown statement ", type);
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
		return;
		
		ph_end_1:
		if(0){}
		
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
		
	ph_cycle_end_0:
	
	
	RETURN_CTOR(compilation);
}

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString){

	zval *view_code, *intermediate, *compilation;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &view_code) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(view_code) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The code must be string");
		return;
	}
	
	PHALCON_INIT_VAR(intermediate);
	PHALCON_CALL_METHOD_PARAMS_1(intermediate, this_ptr, "parse", view_code, PH_NO_CHECK);
	if (Z_TYPE_P(intermediate) == IS_ARRAY) { 
		PHALCON_INIT_VAR(compilation);
		PHALCON_CALL_METHOD_PARAMS_1(compilation, this_ptr, "_statementlist", intermediate, PH_NO_CHECK);
		
		RETURN_CCTOR(compilation);
	}
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Invalid intermediate representation");
	return;
}

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compile){

	zval *path, *compiled_path, *view_code, *intermediate;
	zval *compilation;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &path, &compiled_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(r0);
	is_equal_function(r0, path, compiled_path TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Template path and compilation path cannot be the same");
		return;
	}
	
	PHALCON_INIT_VAR(view_code);
	PHALCON_CALL_FUNC_PARAMS_1(view_code, "file_get_contents", path);
	
	PHALCON_INIT_VAR(intermediate);
	PHALCON_CALL_METHOD_PARAMS_1(intermediate, this_ptr, "parse", view_code, PH_NO_CHECK);
	if (Z_TYPE_P(intermediate) == IS_ARRAY) { 
		PHALCON_INIT_VAR(compilation);
		PHALCON_CALL_METHOD_PARAMS_1(compilation, this_ptr, "_statementlist", intermediate, PH_NO_CHECK);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("file_put_contents", compiled_path, compilation);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Invalid intermediate representation");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, parse){

	zval *view_code, *intermediate;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &view_code) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(intermediate);
	if (phvolt_parse_view(intermediate, view_code TSRMLS_CC) == FAILURE) {
		return;
	}
	
	RETURN_CCTOR(intermediate);
}

