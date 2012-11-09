
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

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "mvc/view/engine/volt/scanner.h"
#include "mvc/view/engine/volt/compiler.h"

/**
 * Phalcon\Mvc\View\Engine\Volt\Compiler
 *
 * This class reads and compiles volt templates into PHP plain code
 */


PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI){

	zval *di;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &di) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), di TSRMLS_CC);
	
}

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Resolves function intermediate code into PHP function calls
 *
 * @param array $expr
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _functionCall){

	zval *expr, *extends_mode, *code = NULL, *func_arguments;
	zval *arguments = NULL, *name, *camelized, *method, *class_name;
	zval *array_helpers = NULL, *exception_message;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &expr, &extends_mode) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(code);
	eval_int = phalcon_array_isset_string(expr, SS("arguments"));
	if (eval_int) {
		PHALCON_INIT_VAR(func_arguments);
		phalcon_array_fetch_string(&func_arguments, expr, SL("arguments"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(arguments);
		PHALCON_CALL_METHOD_PARAMS_2(arguments, this_ptr, "_expression", func_arguments, extends_mode, PH_NO_CHECK);
	} else {
		PHALCON_INIT_NVAR(arguments);
		ZVAL_STRING(arguments, "", 1);
	}
	
	PHALCON_INIT_VAR(name);
	phalcon_array_fetch_string(&name, expr, SL("name"), PH_NOISY_CC);
	if (PHALCON_COMPARE_STRING(name, "content")) {
		ZVAL_STRING(code, "$this->getContent()", 1);
		
		RETURN_CCTOR(code);
	}
	
	if (PHALCON_COMPARE_STRING(name, "partial")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "$this->partial(", arguments, ")");
		
		RETURN_CCTOR(code);
	}
	
	PHALCON_INIT_VAR(camelized);
	phalcon_camelize(camelized, name TSRMLS_CC);
	
	PHALCON_INIT_VAR(method);
	PHALCON_CALL_FUNC_PARAMS_1(method, "lcfirst", camelized);
	
	PHALCON_INIT_VAR(class_name);
	ZVAL_STRING(class_name, "Phalcon\\Tag", 1);
	if (phalcon_method_exists(class_name, method TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(array_helpers);
		phalcon_read_property(&array_helpers, this_ptr, SL("_arrayHelpers"), PH_NOISY_CC);
		if (Z_TYPE_P(array_helpers) != IS_ARRAY) { 
			PHALCON_INIT_NVAR(array_helpers);
			array_init(array_helpers);
			add_assoc_bool_ex(array_helpers, SS("link_to"), 1);
			add_assoc_bool_ex(array_helpers, SS("image"), 1);
			add_assoc_bool_ex(array_helpers, SS("form"), 1);
			add_assoc_bool_ex(array_helpers, SS("select"), 1);
			add_assoc_bool_ex(array_helpers, SS("select_static"), 1);
			add_assoc_bool_ex(array_helpers, SS("submit_button"), 1);
			add_assoc_bool_ex(array_helpers, SS("radio_field"), 1);
			add_assoc_bool_ex(array_helpers, SS("checkbox_field"), 1);
			add_assoc_bool_ex(array_helpers, SS("file_field"), 1);
			add_assoc_bool_ex(array_helpers, SS("hidden_field"), 1);
			add_assoc_bool_ex(array_helpers, SS("password_field"), 1);
			add_assoc_bool_ex(array_helpers, SS("text_area"), 1);
			add_assoc_bool_ex(array_helpers, SS("text_field"), 1);
			phalcon_update_property_zval(this_ptr, SL("_arrayHelpers"), array_helpers TSRMLS_CC);
		}
		
		eval_int = phalcon_array_isset(array_helpers, name);
		if (eval_int) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVSVS(code, "Phalcon\\Tag::", method, "(array(", arguments, "))");
		} else {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVSVS(code, "Phalcon\\Tag::", method, "(", arguments, ")");
		}
		
		
		RETURN_CCTOR(code);
	}
	
	if (PHALCON_COMPARE_STRING(name, "date")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "date(", arguments, ")");
		
		RETURN_CCTOR(code);
	}
	
	if (PHALCON_COMPARE_STRING(name, "time")) {
		PHALCON_INIT_NVAR(code);
		ZVAL_STRING(code, "time()", 1);
		
		RETURN_CCTOR(code);
	}
	
	if (PHALCON_COMPARE_STRING(name, "dump")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "var_dump(", arguments, ")");
		
		RETURN_CCTOR(code);
	}
	
	if (PHALCON_COMPARE_STRING(name, "version")) {
		PHALCON_INIT_NVAR(code);
		ZVAL_STRING(code, "Phalcon\\Version::get()", 1);
		
		RETURN_CCTOR(code);
	}
	
	if (PHALCON_COMPARE_STRING(name, "version_id")) {
		PHALCON_INIT_NVAR(code);
		ZVAL_STRING(code, "Phalcon\\Version::getId()", 1);
		
		RETURN_CCTOR(code);
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

	zval *filter, *left, *exists = NULL, *type, *code = NULL, *name, *exception_message = NULL;

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
			PHALCON_CONCAT_SVS(code, "$this->length(", left, ")");
			
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
		
		if (PHALCON_COMPARE_STRING(name, "nl2br")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "nl2br(", left, ")");
			
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
		
		if (PHALCON_COMPARE_STRING(name, "uppercase")) {
			if (phalcon_function_exists_ex(SS("mb_strtoupper") TSRMLS_CC) == SUCCESS) {
				PHALCON_INIT_NVAR(code);
				PHALCON_CONCAT_SVS(code, "mb_strtoupper(", left, ")");
			} else {
				PHALCON_INIT_NVAR(code);
				PHALCON_CONCAT_SVS(code, "strtoupper(", left, ")");
			}
			
			ZVAL_BOOL(exists, 1);
		}
		
		if (PHALCON_COMPARE_STRING(name, "sort")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "asort(", left, ")");
			
			ZVAL_BOOL(exists, 1);
		}
		
		if (PHALCON_IS_TRUE(exists)) {
			
			RETURN_CCTOR(code);
		}
		
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SV(exception_message, "Unknown filter ", name);
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
		return;
	}
	
	PHALCON_INIT_NVAR(exception_message);
	PHALCON_CONCAT_SV(exception_message, "Unknown filter type ", type);
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
	return;
}

/**
 * Resolves an expression node in an AST volt tree
 *
 * @param array $expr
 * @param bool $extendsMode
 * @param bool $prependDollar
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _expression){

	zval *expr, *extends_mode, *prepend_dollar = NULL, *expr_code = NULL;
	zval *items, *exprs = NULL, *single_expr = NULL, *single_expr_expr = NULL;
	zval *single_expr_code = NULL, *name = NULL, *parameter = NULL, *joined_items;
	zval *type, *left, *left_code, *right_code = NULL, *right;
	zval *applied_filter, *qualified, *qualified_code;
	zval *qualified_arrow, *value, *exception_message;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &expr, &extends_mode, &prepend_dollar) == FAILURE) {
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
		ZVAL_STRING(expr_code, "", 1);
		
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
		
			if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_VALUE(single_expr);
			
			PHALCON_INIT_NVAR(single_expr_expr);
			phalcon_array_fetch_string(&single_expr_expr, single_expr, SL("expr"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(single_expr_code);
			PHALCON_CALL_METHOD_PARAMS_2(single_expr_code, this_ptr, "_expression", single_expr_expr, extends_mode, PH_NO_CHECK);
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
		phalcon_concat_self(expr_code, joined_items TSRMLS_CC);
		
		RETURN_CCTOR(expr_code);
	}
	
	PHALCON_INIT_VAR(type);
	phalcon_array_fetch_string(&type, expr, SL("type"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(expr, SS("left"));
	if (eval_int) {
		PHALCON_INIT_VAR(left);
		phalcon_array_fetch_string(&left, expr, SL("left"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(left_code);
		PHALCON_CALL_METHOD_PARAMS_2(left_code, this_ptr, "_expression", left, extends_mode, PH_NO_CHECK);
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
			PHALCON_CALL_METHOD_PARAMS_2(right_code, this_ptr, "_expression", right, extends_mode, PH_NO_CHECK);
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
			PHALCON_CALL_METHOD_PARAMS_3(qualified_code, this_ptr, "_expression", qualified, extends_mode, prepend_dollar, PH_NO_CHECK);
			
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
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_SVS(expr_code, "array(", left_code, ")");
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
	
	if (phalcon_compare_strict_long(type, 261 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		ZVAL_STRING(expr_code, "null", 1);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 262 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		ZVAL_STRING(expr_code, "false", 1);
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 263 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		ZVAL_STRING(expr_code, "true", 1);
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
		PHALCON_CALL_METHOD_PARAMS_2(expr_code, this_ptr, "_functioncall", expr, extends_mode, PH_NO_CHECK);
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
	
	if (phalcon_compare_strict_long(type, 362 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_SVS(expr_code, "!isset(", left_code, ")");
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 363 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_SVS(expr_code, "isset(", left_code, ")");
		goto ph_end_1;
	}
	
	if (phalcon_compare_strict_long(type, 367 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CONCAT_SV(expr_code, "-", right_code);
		goto ph_end_1;
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SV(exception_message, "Unknown expression ", type);
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
	return;
	
	ph_end_1:
	
	RETURN_CCTOR(expr_code);
}

/**
 * Traverses a statement list compiling each of its nodes
 *
 * @param array $statement
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementList){

	zval *statements, *extends_mode, *exec_statements = NULL;
	zval *compilation, *statement = NULL, *expr = NULL, *expr_code = NULL;
	zval *type = NULL, *code = NULL, *block_statements = NULL, *qualified = NULL;
	zval *qualified_code = NULL, *block_name = NULL, *blocks = NULL, *exception_message = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &statements, &extends_mode) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!phalcon_fast_count_ev(statements TSRMLS_CC)) {
		PHALCON_MM_RESTORE();
		RETURN_STRING("", 1);
	}
	eval_int = phalcon_array_isset_long(statements, 0);
	if (!eval_int) {
		PHALCON_INIT_VAR(exec_statements);
		array_init(exec_statements);
		phalcon_array_append(&exec_statements, statements, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(exec_statements, statements);
	}
	
	PHALCON_INIT_VAR(compilation);
	ZVAL_STRING(compilation, "", 1);
	
	if (!phalcon_valid_foreach(exec_statements TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(exec_statements);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
		
		PHALCON_GET_FOREACH_VALUE(statement);
		
		eval_int = phalcon_array_isset_string(statement, SS("expr"));
		if (eval_int) {
			PHALCON_INIT_NVAR(expr);
			phalcon_array_fetch_string(&expr, statement, SL("expr"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CALL_METHOD_PARAMS_2(expr_code, this_ptr, "_expression", expr, extends_mode, PH_NO_CHECK);
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
			PHALCON_CALL_METHOD_PARAMS_2(code, this_ptr, "_statementlist", block_statements, extends_mode, PH_NO_CHECK);
			phalcon_concat_self(compilation, code TSRMLS_CC);
			eval_int = phalcon_array_isset_string(statement, SS("false_statements"));
			if (eval_int) {
				phalcon_concat_self_str(compilation, SL("<?php } else { ?>") TSRMLS_CC);
				
				PHALCON_INIT_NVAR(block_statements);
				phalcon_array_fetch_string(&block_statements, statement, SL("false_statements"), PH_NOISY_CC);
				
				PHALCON_INIT_NVAR(code);
				PHALCON_CALL_METHOD_PARAMS_2(code, this_ptr, "_statementlist", block_statements, extends_mode, PH_NO_CHECK);
				phalcon_concat_self(compilation, code TSRMLS_CC);
			}
			
			phalcon_concat_self_str(compilation, SL("<?php } ?>") TSRMLS_CC);
			goto ph_end_1;
		}
		
		if (phalcon_compare_strict_long(type, 304 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(qualified);
			phalcon_array_fetch_string(&qualified, statement, SL("qualified"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(qualified_code);
			PHALCON_CALL_METHOD_PARAMS_2(qualified_code, this_ptr, "_expression", qualified, extends_mode, PH_NO_CHECK);
			PHALCON_SCONCAT_SVSVS(compilation, "<?php foreach (", expr_code, " as ", qualified_code, ") { ?>");
			
			PHALCON_INIT_NVAR(block_statements);
			phalcon_array_fetch_string(&block_statements, statement, SL("block_statements"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(code);
			PHALCON_CALL_METHOD_PARAMS_2(code, this_ptr, "_statementlist", block_statements, extends_mode, PH_NO_CHECK);
			phalcon_concat_self(compilation, code TSRMLS_CC);
			phalcon_concat_self_str(compilation, SL("<?php } ?>") TSRMLS_CC);
			goto ph_end_1;
		}
		
		if (phalcon_compare_strict_long(type, 306 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(qualified);
			phalcon_array_fetch_string(&qualified, statement, SL("qualified"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(qualified_code);
			PHALCON_CALL_METHOD_PARAMS_2(qualified_code, this_ptr, "_expression", qualified, extends_mode, PH_NO_CHECK);
			PHALCON_SCONCAT_SVSVS(compilation, "<?php ", qualified_code, " = ", expr_code, "; ?>");
			goto ph_end_1;
		}
		
		if (phalcon_compare_strict_long(type, 359 TSRMLS_CC)) {
			PHALCON_SCONCAT_SVS(compilation, "<?php echo ", expr_code, "; ?>");
			goto ph_end_1;
		}
		
		if (phalcon_compare_strict_long(type, 307 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(block_name);
			phalcon_array_fetch_string(&block_name, statement, SL("name"), PH_NOISY_CC);
			eval_int = phalcon_array_isset_string(statement, SS("block_statements"));
			if (eval_int) {
				PHALCON_INIT_NVAR(block_statements);
				phalcon_array_fetch_string(&block_statements, statement, SL("block_statements"), PH_NOISY_CC);
			} else {
				PHALCON_INIT_NVAR(block_statements);
			}
			
			PHALCON_INIT_NVAR(blocks);
			phalcon_read_property(&blocks, this_ptr, SL("_blocks"), PH_NOISY_CC);
			if (Z_TYPE_P(blocks) != IS_ARRAY) { 
				PHALCON_INIT_NVAR(blocks);
				array_init(blocks);
			}
			
			if (PHALCON_IS_FALSE(extends_mode)) {
				if (Z_TYPE_P(block_statements) == IS_ARRAY) { 
					PHALCON_INIT_NVAR(code);
					PHALCON_CALL_METHOD_PARAMS_2(code, this_ptr, "_statementlist", block_statements, extends_mode, PH_NO_CHECK);
					phalcon_array_update_zval(&blocks, block_name, &code, PH_COPY | PH_SEPARATE TSRMLS_CC);
				} else {
					phalcon_array_update_zval(&blocks, block_name, &block_statements, PH_COPY | PH_SEPARATE TSRMLS_CC);
				}
				phalcon_update_property_zval(this_ptr, SL("_blocks"), blocks TSRMLS_CC);
			} else {
				PHALCON_INIT_NVAR(blocks);
				phalcon_read_property(&blocks, this_ptr, SL("_blocks"), PH_NOISY_CC);
				eval_int = phalcon_array_isset(blocks, block_name);
				if (eval_int) {
					PHALCON_INIT_NVAR(code);
					phalcon_array_fetch(&code, blocks, block_name, PH_NOISY_CC);
					phalcon_concat_self(compilation, code TSRMLS_CC);
				} else {
					if (Z_TYPE_P(block_statements) == IS_ARRAY) { 
						PHALCON_INIT_NVAR(code);
						PHALCON_CALL_METHOD_PARAMS_2(code, this_ptr, "_statementlist", block_statements, extends_mode, PH_NO_CHECK);
						phalcon_concat_self(compilation, code TSRMLS_CC);
					}
				}
			}
			
			goto ph_end_1;
		}
		
		if (phalcon_compare_strict_long(type, 310 TSRMLS_CC)) {
			phalcon_update_property_zval(this_ptr, SL("_extendsNode"), statement TSRMLS_CC);
			phalcon_update_property_bool(this_ptr, SL("_extendsMode"), 1 TSRMLS_CC);
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

/**
 * Compiles a Volt source code returning a PHP plain version
 *
 * @param string $viewCode
 * @param boolean $extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _compileSource){

	zval *view_code, *extends_mode = NULL, *intermediate;
	zval *compilation = NULL, *views_dir = NULL, *dependency_injector;
	zval *service, *view, *path, *view_path, *exception_message;
	zval *extended, *extends_view_code;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &view_code, &extends_mode) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!extends_mode) {
		PHALCON_INIT_NVAR(extends_mode);
		ZVAL_BOOL(extends_mode, 0);
	} else {
		PHALCON_SEPARATE_PARAM(extends_mode);
	}
	
	PHALCON_INIT_VAR(intermediate);
	if (phvolt_parse_view(intermediate, view_code TSRMLS_CC) == FAILURE) {
		return;
	}
	if (Z_TYPE_P(intermediate) == IS_ARRAY) { 
		phalcon_update_property_null(this_ptr, SL("_extendsNode") TSRMLS_CC);
		
		PHALCON_INIT_VAR(compilation);
		PHALCON_CALL_METHOD_PARAMS_2(compilation, this_ptr, "_statementlist", intermediate, extends_mode, PH_NO_CHECK);
		if (PHALCON_IS_FALSE(extends_mode)) {
			PHALCON_INIT_NVAR(extends_mode);
			phalcon_read_property(&extends_mode, this_ptr, SL("_extendsNode"), PH_NOISY_CC);
			if (Z_TYPE_P(extends_mode) != IS_NULL) {
				PHALCON_INIT_VAR(views_dir);
				
				PHALCON_INIT_VAR(dependency_injector);
				phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
				if (Z_TYPE_P(dependency_injector) == IS_OBJECT) {
					PHALCON_INIT_VAR(service);
					ZVAL_STRING(service, "view", 1);
					
					PHALCON_INIT_VAR(view);
					PHALCON_CALL_METHOD_PARAMS_1(view, dependency_injector, "get", service, PH_NO_CHECK);
					
					PHALCON_CALL_METHOD(views_dir, view, "getviewsdir", PH_NO_CHECK);
				}
				
				PHALCON_INIT_VAR(path);
				phalcon_array_fetch_string(&path, extends_mode, SL("path"), PH_NOISY_CC);
				
				PHALCON_INIT_VAR(view_path);
				PHALCON_CONCAT_VV(view_path, views_dir, path);
				if (phalcon_file_exists(view_path TSRMLS_CC) == FAILURE) {
					PHALCON_INIT_VAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Template view to extend '", view_path, "' doesn't exists");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
					return;
				}
				
				PHALCON_INIT_VAR(extended);
				ZVAL_BOOL(extended, 1);
				
				PHALCON_INIT_VAR(extends_view_code);
				PHALCON_CALL_FUNC_PARAMS_1(extends_view_code, "file_get_contents", view_path);
				
				PHALCON_INIT_NVAR(compilation);
				PHALCON_CALL_METHOD_PARAMS_2(compilation, this_ptr, "_compilesource", extends_view_code, extended, PH_NO_CHECK);
			}
		}
		
		
		RETURN_CCTOR(compilation);
	}
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Invalid intermediate representation");
	return;
}

/**
 * Compiles a template in a string
 *
 * @param string $viewCode
 * @param boolean $extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString){

	zval *view_code, *extends_mode = NULL, *compilation;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &view_code, &extends_mode) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!extends_mode) {
		PHALCON_INIT_NVAR(extends_mode);
		ZVAL_BOOL(extends_mode, 0);
	}
	
	if (Z_TYPE_P(view_code) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The code must be string");
		return;
	}
	
	PHALCON_INIT_VAR(compilation);
	PHALCON_CALL_METHOD_PARAMS_1(compilation, this_ptr, "_compilesource", view_code, PH_NO_CHECK);
	
	RETURN_CCTOR(compilation);
}

/**
 * Compiles a template into a file
 *
 * @param string $path
 * @param string $compiledPath
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compile){

	zval *path, *compiled_path, *same, *view_code, *compilation;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &path, &compiled_path) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(same);
	is_equal_function(same, path, compiled_path TSRMLS_CC);
	if (PHALCON_IS_TRUE(same)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Template path and compilation path cannot be the same");
		return;
	}
	
	PHALCON_INIT_VAR(view_code);
	PHALCON_CALL_FUNC_PARAMS_1(view_code, "file_get_contents", path);
	
	PHALCON_INIT_VAR(compilation);
	PHALCON_CALL_METHOD_PARAMS_1(compilation, this_ptr, "_compilesource", view_code, PH_NO_CHECK);
	PHALCON_CALL_FUNC_PARAMS_2_NORETURN("file_put_contents", compiled_path, compilation);
	
	PHALCON_MM_RESTORE();
}

/**
 * Parses a Volt template returning its intermediate representation
 *
 * @param string $viewCode
 * @return array
 */
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

