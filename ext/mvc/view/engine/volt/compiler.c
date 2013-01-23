
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "mvc/view/engine/volt/scanner.h"
#include "mvc/view/engine/volt/volt.h"

/**
 * Phalcon\Mvc\View\Engine\Volt\Compiler
 *
 * This class reads and compiles Volt templates into PHP plain code
 *
 *<code>
 *	$compiler = new \Phalcon\Mvc\View\Engine\Volt\Compiler();
 *	$compiler->compile('views/partials/header.volt');
 *	require $compiler->getCompiledTemplatePath();
 *</code>
 */


/**
 * Phalcon\Mvc\View\Engine\Volt\Compiler initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Compiler){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\View\\Engine\\Volt, Compiler, mvc_view_engine_volt_compiler, phalcon_mvc_view_engine_volt_compiler_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_view"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_arrayHelpers"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_view_engine_volt_compiler_ce, SL("_level"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_view_engine_volt_compiler_ce, SL("_extended"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_view_engine_volt_compiler_ce, SL("_autoescape"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_extendedBlocks"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_currentBlock"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_blocks"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_functions"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_filters"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_currentPath"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_compiler_ce, SL("_compiledTemplatePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_view_engine_volt_compiler_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\View\Engine\Volt\Compiler
 *
 * @param Phalcon\Mvc\ViewInterface $view
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, __construct){

	zval *view = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &view) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!view) {
		PHALCON_INIT_VAR(view);
	}
	
	if (Z_TYPE_P(view) == IS_OBJECT) {
		phalcon_update_property_zval(this_ptr, SL("_view"), view TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the compiler options
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setOptions){

	zval *options;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &options) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_options"), options TSRMLS_CC);
	
}

/**
 * Returns the compiler options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getOptions){


	RETURN_MEMBER(this_ptr, "_options");
}

/**
 * Sets the dependency injector
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, setDI){

	zval *dependency_injector;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Dependency Injector is invalid");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal dependency injector
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Register a new function in the compiler
 *
 * @param string $name
 * @param Closure|string $definition
 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFunction){

	zval *name, *definition;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &name, &definition) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The function name must be an string");
		return;
	}
	phalcon_update_property_array(this_ptr, SL("_functions"), name, definition TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Register the user registered functions
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFunctions){


	RETURN_MEMBER(this_ptr, "_functions");
}

/**
 * Register a new filter in the compiler
 *
 * @param string $name
 * @param Closure|string $definition
 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, addFilter){

	zval *name, *definition;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &name, &definition) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(name) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The function name must be a string");
		return;
	}
	phalcon_update_property_array(this_ptr, SL("_filters"), name, definition TSRMLS_CC);
	
	RETURN_THIS();
}

/**
 * Register the user registered filters
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getFilters){


	RETURN_MEMBER(this_ptr, "_filters");
}

/**
 * Resolves attribute reading
 *
 * @param array $expr
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, attributeReader){

	zval *expr, *expr_code, *left, *left_type, *variable;
	zval *dependency_injector, *is_service, *left_code;
	zval *right, *right_type, *member, *right_code;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &expr) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(expr) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted function call");
		return;
	}
	
	PHALCON_INIT_VAR(expr_code);
	
	PHALCON_OBS_VAR(left);
	phalcon_array_fetch_string(&left, expr, SL("left"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(left_type);
	phalcon_array_fetch_string(&left_type, left, SL("type"), PH_NOISY_CC);
	if (PHALCON_IS_LONG(left_type, 265)) {
	
		PHALCON_OBS_VAR(variable);
		phalcon_array_fetch_string(&variable, left, SL("value"), PH_NOISY_CC);
	
		/** 
		 * Services registered in the dependency injector container are availables always
		 */
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (Z_TYPE_P(dependency_injector) == IS_OBJECT) {
	
			PHALCON_INIT_VAR(is_service);
			PHALCON_CALL_METHOD_PARAMS_1(is_service, dependency_injector, "has", variable);
			if (zend_is_true(is_service)) {
				PHALCON_SCONCAT_SV(expr_code, "$this->", variable);
			} else {
				PHALCON_SCONCAT_SV(expr_code, "$", variable);
			}
		} else {
			PHALCON_SCONCAT_SV(expr_code, "$", variable);
		}
	} else {
		PHALCON_INIT_VAR(left_code);
		PHALCON_CALL_METHOD_PARAMS_1(left_code, this_ptr, "expression", left);
		if (!PHALCON_IS_LONG(left_type, 46)) {
			if (!PHALCON_IS_LONG(left_type, 350)) {
				PHALCON_SCONCAT_SVS(expr_code, "(", left_code, ")");
			} else {
				phalcon_concat_self(&expr_code, left_code TSRMLS_CC);
			}
		} else {
			phalcon_concat_self(&expr_code, left_code TSRMLS_CC);
		}
	}
	
	phalcon_concat_self_str(&expr_code, SL("->") TSRMLS_CC);
	
	PHALCON_OBS_VAR(right);
	phalcon_array_fetch_string(&right, expr, SL("right"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(right_type);
	phalcon_array_fetch_string(&right_type, right, SL("type"), PH_NOISY_CC);
	if (PHALCON_IS_LONG(right_type, 265)) {
		PHALCON_OBS_VAR(member);
		phalcon_array_fetch_string(&member, right, SL("value"), PH_NOISY_CC);
		phalcon_concat_self(&expr_code, member TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(right_code);
		PHALCON_CALL_METHOD_PARAMS_1(right_code, this_ptr, "expression", right);
		phalcon_concat_self(&expr_code, right_code TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(expr_code);
}

/**
 * Resolves function intermediate code into PHP function calls
 *
 * @param array $expr
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, functionCall){

	zval *expr, *code = NULL, *func_arguments = NULL, *arguments = NULL;
	zval *name_expr, *name_type, *name = NULL, *functions;
	zval *definition, *parameters, *line = NULL, *file = NULL, *exception_message = NULL;
	zval *extended_blocks, *current_block, *block;
	zval *escaped_code = NULL, *str_code, *camelized, *method;
	zval *class_name, *array_helpers = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &expr) == FAILURE) {
		RETURN_MM_NULL();
	}

	/** 
	 * Valid filters are always arrays
	 */
	if (Z_TYPE_P(expr) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted function call");
		return;
	}
	
	PHALCON_INIT_VAR(code);
	
	PHALCON_INIT_VAR(func_arguments);
	if (phalcon_array_isset_string(expr, SS("arguments"))) {
		PHALCON_OBS_NVAR(func_arguments);
		phalcon_array_fetch_string(&func_arguments, expr, SL("arguments"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(arguments);
		PHALCON_CALL_METHOD_PARAMS_1(arguments, this_ptr, "expression", func_arguments);
	} else {
		PHALCON_INIT_NVAR(arguments);
		ZVAL_STRING(arguments, "", 1);
	}
	
	PHALCON_OBS_VAR(name_expr);
	phalcon_array_fetch_string(&name_expr, expr, SL("name"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(name_type);
	phalcon_array_fetch_string(&name_type, name_expr, SL("type"), PH_NOISY_CC);
	
	/** 
	 * Check if it's a single function
	 */
	if (PHALCON_IS_LONG(name_type, 265)) {
	
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_string(&name, name_expr, SL("value"), PH_NOISY_CC);
	
		/** 
		 * Check if it's a user defined function
		 */
		PHALCON_OBS_VAR(functions);
		phalcon_read_property(&functions, this_ptr, SL("_functions"), PH_NOISY_CC);
		if (Z_TYPE_P(functions) == IS_ARRAY) { 
			if (phalcon_array_isset(functions, name)) {
	
				PHALCON_OBS_VAR(definition);
				phalcon_array_fetch(&definition, functions, name, PH_NOISY_CC);
				if (Z_TYPE_P(definition) == IS_STRING) {
					RETURN_CCTOR(definition);
				}
	
				if (Z_TYPE_P(definition) == IS_OBJECT) {
					if (phalcon_is_instance_of(definition, SL("Closure") TSRMLS_CC)) {
						PHALCON_INIT_VAR(parameters);
						array_init_size(parameters, 2);
						phalcon_array_append(&parameters, arguments, PH_SEPARATE TSRMLS_CC);
						phalcon_array_append(&parameters, func_arguments, PH_SEPARATE TSRMLS_CC);
	
						PHALCON_CALL_FUNC_PARAMS_2(code, "call_user_func_array", definition, parameters);
						RETURN_CCTOR(code);
					}
				}
	
				PHALCON_OBS_VAR(line);
				phalcon_array_fetch_string(&line, expr, SL("line"), PH_NOISY_CC);
	
				PHALCON_OBS_VAR(file);
				phalcon_array_fetch_string(&file, expr, SL("file"), PH_NOISY_CC);
	
				PHALCON_INIT_VAR(exception_message);
				PHALCON_CONCAT_SVSVSV(exception_message, "Invalid definition for user function '", name, "' in ", file, " on line ", line);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
				return;
			}
		}
	
		/** 
		 * This function includes the previous rendering stage
		 */
		if (PHALCON_IS_STRING(name, "get_content")) {
			PHALCON_INIT_NVAR(code);
			ZVAL_STRING(code, "$this->getContent()", 1);
			RETURN_CCTOR(code);
		}
	
		/** 
		 * Alias of 'get_content'
		 */
		if (PHALCON_IS_STRING(name, "content")) {
			PHALCON_INIT_NVAR(code);
			ZVAL_STRING(code, "$this->getContent()", 1);
			RETURN_CCTOR(code);
		}
	
		/** 
		 * This function includes views of volt or others template engines dynamically
		 */
		if (PHALCON_IS_STRING(name, "partial")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "$this->partial(", arguments, ")");
			RETURN_CCTOR(code);
		}
	
		/** 
		 * This function embeds the parent block in the current block
		 */
		if (PHALCON_IS_STRING(name, "super")) {
	
			PHALCON_OBS_VAR(extended_blocks);
			phalcon_read_property(&extended_blocks, this_ptr, SL("_extendedBlocks"), PH_NOISY_CC);
			if (Z_TYPE_P(extended_blocks) == IS_ARRAY) { 
	
				PHALCON_OBS_VAR(current_block);
				phalcon_read_property(&current_block, this_ptr, SL("_currentBlock"), PH_NOISY_CC);
				if (phalcon_array_isset(extended_blocks, current_block)) {
	
					PHALCON_OBS_VAR(block);
					phalcon_array_fetch(&block, extended_blocks, current_block, PH_NOISY_CC);
					if (Z_TYPE_P(block) == IS_ARRAY) { 
						PHALCON_INIT_NVAR(code);
						PHALCON_CALL_METHOD_PARAMS_1(code, this_ptr, "_statementlistorextends", block);
	
						PHALCON_INIT_VAR(escaped_code);
						PHALCON_CALL_FUNC_PARAMS_1(escaped_code, "addslashes", code);
					} else {
						PHALCON_INIT_NVAR(escaped_code);
						PHALCON_CALL_FUNC_PARAMS_1(escaped_code, "addslashes", block);
					}
	
					PHALCON_INIT_VAR(str_code);
					PHALCON_CONCAT_SVS(str_code, "'", escaped_code, "'");
	
					RETURN_CTOR(str_code);
				}
			}
	
			PHALCON_MM_RESTORE();
			RETURN_STRING("''", 1);
		}
	
		PHALCON_INIT_VAR(camelized);
		phalcon_camelize(camelized, name TSRMLS_CC);
	
		PHALCON_INIT_VAR(method);
		PHALCON_CALL_FUNC_PARAMS_1(method, "lcfirst", camelized);
	
		PHALCON_INIT_VAR(class_name);
		ZVAL_STRING(class_name, "Phalcon\\Tag", 1);
	
		/** 
		 * Check if it's a method in Phalcon\Tag
		 */
		if (phalcon_method_exists(class_name, method TSRMLS_CC) == SUCCESS) {
	
			PHALCON_OBS_VAR(array_helpers);
			phalcon_read_property(&array_helpers, this_ptr, SL("_arrayHelpers"), PH_NOISY_CC);
			if (Z_TYPE_P(array_helpers) != IS_ARRAY) { 
				PHALCON_INIT_NVAR(array_helpers);
				array_init_size(array_helpers, 13);
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
	
			if (phalcon_array_isset(array_helpers, name)) {
				PHALCON_INIT_NVAR(code);
				PHALCON_CONCAT_SVSVS(code, "Phalcon\\Tag::", method, "(array(", arguments, "))");
			} else {
				PHALCON_INIT_NVAR(code);
				PHALCON_CONCAT_SVSVS(code, "Phalcon\\Tag::", method, "(", arguments, ")");
			}
	
	
			RETURN_CCTOR(code);
		}
	
		if (PHALCON_IS_STRING(name, "url")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "$this->url->get(", arguments, ")");
			RETURN_CCTOR(code);
		}
	
		if (PHALCON_IS_STRING(name, "date")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "date(", arguments, ")");
			RETURN_CCTOR(code);
		}
	
		if (PHALCON_IS_STRING(name, "time")) {
			PHALCON_INIT_NVAR(code);
			ZVAL_STRING(code, "time()", 1);
			RETURN_CCTOR(code);
		}
	
		if (PHALCON_IS_STRING(name, "dump")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "var_dump(", arguments, ")");
			RETURN_CCTOR(code);
		}
	
		if (PHALCON_IS_STRING(name, "version")) {
			PHALCON_INIT_NVAR(code);
			ZVAL_STRING(code, "Phalcon\\Version::get()", 1);
			RETURN_CCTOR(code);
		}
	
		if (PHALCON_IS_STRING(name, "version_id")) {
			PHALCON_INIT_NVAR(code);
			ZVAL_STRING(code, "Phalcon\\Version::getId()", 1);
			RETURN_CCTOR(code);
		}
	
		/** 
		 * Read PHP constants in templates
		 */
		if (PHALCON_IS_STRING(name, "constant")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "constant(", arguments, ")");
			RETURN_CCTOR(code);
		}
	
		/** 
		 * The function doesn't exist throw an exception
		 */
		PHALCON_OBS_NVAR(line);
		phalcon_array_fetch_string(&line, expr, SL("line"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(file);
		phalcon_array_fetch_string(&file, expr, SL("file"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(exception_message);
		PHALCON_CONCAT_SVSVSV(exception_message, "Undefined function '", name, "' in ", file, " on line ", line);
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
		return;
	} else {
		PHALCON_INIT_NVAR(name);
		PHALCON_CALL_METHOD_PARAMS_1(name, this_ptr, "expression", name_expr);
	
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_VSVS(code, name, "(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Resolves filter intermediate code into a valid PHP expression
 *
 * @param array $test
 * @param string $left
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveTest){

	zval *test, *left, *type, *name = NULL, *code = NULL, *test_name, *test_arguments = NULL;
	zval *arguments = NULL, *right_code;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &test, &left) == FAILURE) {
		RETURN_MM_NULL();
	}

	/** 
	 * Valid tests are always arrays
	 */
	if (Z_TYPE_P(test) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted test");
		return;
	}
	
	PHALCON_OBS_VAR(type);
	phalcon_array_fetch_string(&type, test, SL("type"), PH_NOISY_CC);
	
	/** 
	 * Check if right part is a single identifier
	 */
	if (PHALCON_IS_LONG(type, 265)) {
	
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_string(&name, test, SL("value"), PH_NOISY_CC);
	
		/** 
		 * Empty uses the PHP's empty operator
		 */
		if (PHALCON_IS_STRING(name, "empty")) {
			PHALCON_INIT_VAR(code);
			PHALCON_CONCAT_SVS(code, "empty(", left, ")");
			RETURN_CTOR(code);
		}
	
		/** 
		 * Check if a value is even
		 */
		if (PHALCON_IS_STRING(name, "even")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "(((", left, ") % 2) == 0)");
			RETURN_CTOR(code);
		}
	
		/** 
		 * Check if a value is odd
		 */
		if (PHALCON_IS_STRING(name, "odd")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "(((", left, ") % 2) != 0)");
			RETURN_CTOR(code);
		}
	
		/** 
		 * Check if a value is numeric
		 */
		if (PHALCON_IS_STRING(name, "numeric")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "is_numeric(", left, ")");
			RETURN_CTOR(code);
		}
	
		/** 
		 * Check if a value is scalar
		 */
		if (PHALCON_IS_STRING(name, "scalar")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVS(code, "is_scalar(", left, ")");
			RETURN_CTOR(code);
		}
	
		/** 
		 * Check if a value is iterable
		 */
		if (PHALCON_IS_STRING(name, "iterable")) {
			PHALCON_INIT_NVAR(code);
			PHALCON_CONCAT_SVSVS(code, "(is_array(", left, ") || (", left, ") instanceof Traversable)");
			RETURN_CTOR(code);
		}
	}
	
	/** 
	 * Check if right part is a function call
	 */
	if (PHALCON_IS_LONG(type, 350)) {
	
		PHALCON_OBS_VAR(test_name);
		phalcon_array_fetch_string(&test_name, test, SL("name"), PH_NOISY_CC);
		if (phalcon_array_isset_string(test_name, SS("value"))) {
	
			/** 
			 * Checks if a value is divisible by other
			 */
			PHALCON_OBS_NVAR(name);
			phalcon_array_fetch_string(&name, test_name, SL("value"), PH_NOISY_CC);
			if (PHALCON_IS_STRING(name, "divisibleby")) {
				PHALCON_OBS_VAR(test_arguments);
				phalcon_array_fetch_string(&test_arguments, test, SL("arguments"), PH_NOISY_CC);
	
				PHALCON_INIT_VAR(arguments);
				PHALCON_CALL_METHOD_PARAMS_1(arguments, this_ptr, "expression", test_arguments);
	
				PHALCON_INIT_NVAR(code);
				PHALCON_CONCAT_SVSVS(code, "(((", left, ") % (", arguments, ")) == 0)");
				RETURN_CTOR(code);
			}
	
			/** 
			 * Checks if a value is equals to other
			 */
			if (PHALCON_IS_STRING(name, "sameas")) {
				PHALCON_OBS_NVAR(test_arguments);
				phalcon_array_fetch_string(&test_arguments, test, SL("arguments"), PH_NOISY_CC);
	
				PHALCON_INIT_NVAR(arguments);
				PHALCON_CALL_METHOD_PARAMS_1(arguments, this_ptr, "expression", test_arguments);
	
				PHALCON_INIT_NVAR(code);
				PHALCON_CONCAT_SVSVS(code, "(", left, ") === (", arguments, ")");
				RETURN_CTOR(code);
			}
		}
	}
	
	/** 
	 * Fall back to the equals operator
	 */
	PHALCON_INIT_VAR(right_code);
	PHALCON_CALL_METHOD_PARAMS_1(right_code, this_ptr, "expression", test);
	
	PHALCON_INIT_NVAR(code);
	PHALCON_CONCAT_VSV(code, left, " == ", right_code);
	
	RETURN_CTOR(code);
}

/**
 * Resolves filter intermediate code into PHP function calls
 *
 * @param array $filter
 * @param string $left
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, resolveFilter){

	zval *filter, *left, *code = NULL, *type, *name = NULL, *function_name;
	zval *line = NULL, *file = NULL, *exception_message = NULL, *func_arguments = NULL;
	zval *arguments = NULL, *resolved_expr, *resolved_param;
	zval *filters, *definition, *parameters;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &filter, &left) == FAILURE) {
		RETURN_MM_NULL();
	}

	/** 
	 * Valid filters are always arrays
	 */
	if (Z_TYPE_P(filter) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted filter");
		return;
	}
	
	PHALCON_INIT_VAR(code);
	
	PHALCON_OBS_VAR(type);
	phalcon_array_fetch_string(&type, filter, SL("type"), PH_NOISY_CC);
	
	/** 
	 * Check if the filter is a single identifier
	 */
	if (PHALCON_IS_LONG(type, 265)) {
		PHALCON_OBS_VAR(name);
		phalcon_array_fetch_string(&name, filter, SL("value"), PH_NOISY_CC);
	} else {
		if (PHALCON_IS_LONG(type, 350)) {
			PHALCON_OBS_VAR(function_name);
			phalcon_array_fetch_string(&function_name, filter, SL("name"), PH_NOISY_CC);
	
			PHALCON_OBS_NVAR(name);
			phalcon_array_fetch_string(&name, function_name, SL("value"), PH_NOISY_CC);
		} else {
			/** 
			 * Unknown filter throw an exception
			 */
			PHALCON_OBS_VAR(line);
			phalcon_array_fetch_string(&line, filter, SL("line"), PH_NOISY_CC);
	
			PHALCON_OBS_VAR(file);
			phalcon_array_fetch_string(&file, filter, SL("file"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVSV(exception_message, "Unknown filter type in ", file, " on line ", line);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
			return;
		}
	}
	
	PHALCON_INIT_VAR(func_arguments);
	
	PHALCON_INIT_VAR(arguments);
	
	/** 
	 * Resolve arguments
	 */
	if (phalcon_array_isset_string(filter, SS("arguments"))) {
	
		PHALCON_OBS_NVAR(file);
		phalcon_array_fetch_string(&file, filter, SL("file"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(line);
		phalcon_array_fetch_string(&line, filter, SL("line"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(func_arguments);
		phalcon_array_fetch_string(&func_arguments, filter, SL("arguments"), PH_NOISY_CC);
	
		/** 
		 * 'default' filter is not the first argument, improve this!
		 */
		if (!PHALCON_IS_STRING(name, "default")) {
			PHALCON_INIT_VAR(resolved_expr);
			array_init_size(resolved_expr, 4);
			add_assoc_long_ex(resolved_expr, SS("type"), 364);
			phalcon_array_update_string(&resolved_expr, SL("value"), &left, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&resolved_expr, SL("file"), &file, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&resolved_expr, SL("line"), &line, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
			PHALCON_INIT_VAR(resolved_param);
			array_init_size(resolved_param, 3);
			phalcon_array_update_string(&resolved_param, SL("expr"), &resolved_expr, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&resolved_param, SL("file"), &file, PH_COPY | PH_SEPARATE TSRMLS_CC);
			phalcon_array_update_string(&resolved_param, SL("line"), &line, PH_COPY | PH_SEPARATE TSRMLS_CC);
			Z_SET_ISREF_P(func_arguments);
			PHALCON_CALL_FUNC_PARAMS_2_NORETURN("array_unshift", func_arguments, resolved_param);
			Z_UNSET_ISREF_P(func_arguments);
		}
	
		PHALCON_CALL_METHOD_PARAMS_1(arguments, this_ptr, "expression", func_arguments);
	} else {
		PHALCON_CPY_WRT(arguments, left);
	}
	
	/** 
	 * Check if it's a user defined filter
	 */
	PHALCON_OBS_VAR(filters);
	phalcon_read_property(&filters, this_ptr, SL("_filters"), PH_NOISY_CC);
	if (Z_TYPE_P(filters) == IS_ARRAY) { 
		if (phalcon_array_isset(filters, name)) {
	
			PHALCON_OBS_VAR(definition);
			phalcon_array_fetch(&definition, filters, name, PH_NOISY_CC);
	
			/** 
			 * The definition is a string
			 */
			if (Z_TYPE_P(definition) == IS_STRING) {
				PHALCON_CONCAT_VSVS(code, definition, "(", arguments, ")");
				RETURN_CCTOR(code);
			}
	
			/** 
			 * The definition is a closure
			 */
			if (Z_TYPE_P(definition) == IS_OBJECT) {
				if (phalcon_is_instance_of(definition, SL("Closure") TSRMLS_CC)) {
					PHALCON_INIT_VAR(parameters);
					array_init_size(parameters, 2);
					phalcon_array_append(&parameters, arguments, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&parameters, func_arguments, PH_SEPARATE TSRMLS_CC);
	
					PHALCON_INIT_NVAR(code);
					PHALCON_CALL_FUNC_PARAMS_2(code, "call_user_func_array", definition, parameters);
					RETURN_CCTOR(code);
				}
			}
	
			/** 
			 * Invalid filter definition throw an exception
			 */
			PHALCON_OBS_NVAR(line);
			phalcon_array_fetch_string(&line, filter, SL("line"), PH_NOISY_CC);
	
			PHALCON_OBS_NVAR(file);
			phalcon_array_fetch_string(&file, filter, SL("file"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVSVSV(exception_message, "Invalid definition for user filter '", name, "' in ", file, " on line ", line);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
			return;
		}
	}
	
	/** 
	 * 'length' uses the length method implemented in the Volt adapter
	 */
	if (PHALCON_IS_STRING(name, "length")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "$this->length(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'e' filter uses the escaper component
	 */
	if (PHALCON_IS_STRING(name, "e")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "$this->escaper->escapeHtml(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'escape' filter uses the escaper component
	 */
	if (PHALCON_IS_STRING(name, "escape")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "$this->escaper->escapeHtml(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'escapecss' filter uses the escaper component to filter css
	 */
	if (PHALCON_IS_STRING(name, "escape_css")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "$this->escaper->escapeCss(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'escapejs' filter uses the escaper component to escape javascript
	 */
	if (PHALCON_IS_STRING(name, "escape_js")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "$this->escaper->escapeJs(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'escapeattr' filter uses the escaper component to escape html attributes
	 */
	if (PHALCON_IS_STRING(name, "escape_attr")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "$this->escaper->escapeHtmlAttr(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'trim' calls the "trim" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "trim")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "trim(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'striptags' calls the "strip_tags" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "striptags")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "strip_tags(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'urlencode' calls the "urlencode" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "url_encode")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "urlencode(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'slashes' calls the "addslashes" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "slashes")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "addslashes(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'stripslashes' calls the "stripslashes" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "stripslashes")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "stripslashes(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'nl2br' calls the "nl2br" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "nl2br")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "nl2br(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'keys' uses calls the "array_keys" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "keys")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "array_keys(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'join' uses calls the "join" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "join")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "join(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'lowercase' calls the "strtolower" function or "mb_strtolower" if the mbstring
	 * extension is loaded
	 */
	if (PHALCON_IS_STRING(name, "lowercase")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "Phalcon\\Text::lower(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'lowercase' calls the "strtolower" function or "mb_strtolower" if the mbstring
	 * extension is loaded
	 */
	if (PHALCON_IS_STRING(name, "lower")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "Phalcon\\Text::lower(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'uppercase' calls the "strtouppwer" function or "mb_strtoupper" if the mbstring
	 * extension is loaded
	 */
	if (PHALCON_IS_STRING(name, "uppercase")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "Phalcon\\Text::upper(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'uppercase' calls the "strtouppwer" function or "mb_strtoupper" if the mbstring
	 * extension is loaded
	 */
	if (PHALCON_IS_STRING(name, "upper")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "Phalcon\\Text::upper(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'sort' calls the "asort" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "sort")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "asort(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'json_encode' calls the "json_encode" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "json_encode")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "json_encode(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'json_decode' calls the "json_decode" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "json_decode")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "json_decode(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'format' calls the "sprintf" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "format")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "sprintf(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'abs' calls the "abs" function in the PHP userland
	 */
	if (PHALCON_IS_STRING(name, "abs")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "abs(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'slice' slices string/arrays/traversable objects
	 */
	if (PHALCON_IS_STRING(name, "slice")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "$this->slice(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * 'default' checks if a variable is empty
	 */
	if (PHALCON_IS_STRING(name, "default")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVSVSVS(code, "(empty(", left, ") ? (", arguments, ") : (", left, "))");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * This function uses mbstring or iconv to convert strings from one chartset to
	 * another
	 */
	if (PHALCON_IS_STRING(name, "convert_encoding")) {
		PHALCON_INIT_NVAR(code);
		PHALCON_CONCAT_SVS(code, "$this->convertEncoding(", arguments, ")");
		RETURN_CCTOR(code);
	}
	
	/** 
	 * Unknown filter throw an exception
	 */
	PHALCON_OBS_NVAR(line);
	phalcon_array_fetch_string(&line, filter, SL("line"), PH_NOISY_CC);
	
	PHALCON_OBS_NVAR(file);
	phalcon_array_fetch_string(&file, filter, SL("file"), PH_NOISY_CC);
	
	PHALCON_INIT_NVAR(exception_message);
	PHALCON_CONCAT_SVSVSV(exception_message, "Unknown filter \"", name, "\" in ", file, " on line ", line);
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
	return;
}

/**
 * Resolves an expression node in an AST volt tree
 *
 * @param array $expr
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, expression){

	zval *expr, *expr_code = NULL, *items, *single_expr = NULL, *single_expr_expr = NULL;
	zval *single_expr_code = NULL, *name = NULL, *parameter = NULL, *type;
	zval *left, *left_code, *right_code = NULL, *right, *value = NULL;
	zval *single_quote, *escaped_quoute, *escaped_string;
	zval *start, *start_code = NULL, *end, *end_code = NULL, *line, *file;
	zval *exception_message;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &expr) == FAILURE) {
		RETURN_MM_NULL();
	}

	/** 
	 * Valid expressions are always arrays
	 */
	if (Z_TYPE_P(expr) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted expression");
		return;
	}
	
	PHALCON_INIT_VAR(expr_code);
	if (!phalcon_array_isset_string(expr, SS("type"))) {
	
		PHALCON_INIT_VAR(items);
		array_init(items);
	
		if (!phalcon_is_iterable(expr, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(single_expr);
	
			PHALCON_OBS_NVAR(single_expr_expr);
			phalcon_array_fetch_string(&single_expr_expr, single_expr, SL("expr"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(single_expr_code);
			PHALCON_CALL_METHOD_PARAMS_1(single_expr_code, this_ptr, "expression", single_expr_expr);
			if (phalcon_array_isset_string(single_expr, SS("name"))) {
				PHALCON_OBS_NVAR(name);
				phalcon_array_fetch_string(&name, single_expr, SL("name"), PH_NOISY_CC);
	
				PHALCON_INIT_NVAR(parameter);
				PHALCON_CONCAT_SVSV(parameter, "'", name, "' => ", single_expr_code);
				phalcon_array_append(&items, parameter, PH_SEPARATE TSRMLS_CC);
			} else {
				phalcon_array_append(&items, single_expr_code, PH_SEPARATE TSRMLS_CC);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		phalcon_fast_join_str(expr_code, SL(", "), items TSRMLS_CC);
	
		RETURN_CCTOR(expr_code);
	}
	
	PHALCON_OBS_VAR(type);
	phalcon_array_fetch_string(&type, expr, SL("type"), PH_NOISY_CC);
	
	/** 
	 * Attribute reading needs special handling
	 */
	if (PHALCON_IS_LONG(type, 46)) {
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CALL_METHOD_PARAMS_1(expr_code, this_ptr, "attributereader", expr);
		RETURN_CCTOR(expr_code);
	}
	
	/** 
	 * Left part of expression is always resolved
	 */
	if (phalcon_array_isset_string(expr, SS("left"))) {
		PHALCON_OBS_VAR(left);
		phalcon_array_fetch_string(&left, expr, SL("left"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(left_code);
		PHALCON_CALL_METHOD_PARAMS_1(left_code, this_ptr, "expression", left);
	}
	
	/** 
	 * Operator 'is' also needs special handling
	 */
	if (PHALCON_IS_LONG(type, 311)) {
		PHALCON_OBS_VAR(right_code);
		phalcon_array_fetch_string(&right_code, expr, SL("right"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CALL_METHOD_PARAMS_2(expr_code, this_ptr, "resolvetest", right_code, left_code);
		RETURN_CCTOR(expr_code);
	}
	
	/** 
	 * We don't resolve the right expression for filters
	 */
	if (PHALCON_IS_LONG(type, 124)) {
		PHALCON_OBS_NVAR(right_code);
		phalcon_array_fetch_string(&right_code, expr, SL("right"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(expr_code);
		PHALCON_CALL_METHOD_PARAMS_2(expr_code, this_ptr, "resolvefilter", right_code, left_code);
		RETURN_CCTOR(expr_code);
	}
	
	/** 
	 * From here, right part of expression is always resolved
	 */
	if (phalcon_array_isset_string(expr, SS("right"))) {
		PHALCON_OBS_VAR(right);
		phalcon_array_fetch_string(&right, expr, SL("right"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(right_code);
		PHALCON_CALL_METHOD_PARAMS_1(right_code, this_ptr, "expression", right);
	}
	
	PHALCON_INIT_NVAR(expr_code);
	
	switch (phalcon_get_intval(type)) {
	
		case 33:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_SV(expr_code, "!", right_code);
			break;
	
		case 42:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " * ", right_code);
			break;
	
		case 43:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " + ", right_code);
			break;
	
		case 45:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " - ", right_code);
			break;
	
		case 47:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " / ", right_code);
			break;
	
		case 37:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " % ", right_code);
			break;
	
		case 60:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " < ", right_code);
			break;
	
		case 61:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " > ", right_code);
			break;
	
		case 62:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " > ", right_code);
			break;
	
		case 126:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " . ", right_code);
			break;
	
		case 360:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_SVS(expr_code, "array(", left_code, ")");
			break;
	
		case 258:
			PHALCON_OBS_NVAR(expr_code);
			phalcon_array_fetch_string(&expr_code, expr, SL("value"), PH_NOISY_CC);
			break;
	
		case 259:
			PHALCON_OBS_NVAR(expr_code);
			phalcon_array_fetch_string(&expr_code, expr, SL("value"), PH_NOISY_CC);
			break;
	
		case 260:
			PHALCON_OBS_VAR(value);
			phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(single_quote);
			ZVAL_STRING(single_quote, "'", 1);
	
			PHALCON_INIT_VAR(escaped_quoute);
			ZVAL_STRING(escaped_quoute, "\\'", 1);
	
			PHALCON_INIT_VAR(escaped_string);
			phalcon_fast_str_replace(escaped_string, single_quote, escaped_quoute, value TSRMLS_CC);
	
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_SVS(expr_code, "'", escaped_string, "'");
			break;
	
		case 261:
			PHALCON_INIT_NVAR(expr_code);
			ZVAL_STRING(expr_code, "null", 1);
			break;
	
		case 262:
			PHALCON_INIT_NVAR(expr_code);
			ZVAL_STRING(expr_code, "false", 1);
			break;
	
		case 263:
			PHALCON_INIT_NVAR(expr_code);
			ZVAL_STRING(expr_code, "true", 1);
			break;
	
		case 265:
			PHALCON_OBS_NVAR(value);
			phalcon_array_fetch_string(&value, expr, SL("value"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_SV(expr_code, "$", value);
			break;
	
		case 266:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " && ", right_code);
			break;
	
		case 267:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " || ", right_code);
			break;
	
		case 270:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " <= ", right_code);
			break;
	
		case 271:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " >= ", right_code);
			break;
	
		case 272:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " == ", right_code);
			break;
	
		case 273:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " != ", right_code);
			break;
	
		case 274:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " === ", right_code);
			break;
	
		case 275:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSV(expr_code, left_code, " !== ", right_code);
			break;
	
		case 276:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_SVSVS(expr_code, "range(", left_code, ", ", right_code, ")");
			break;
	
		case 350:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CALL_METHOD_PARAMS_1(expr_code, this_ptr, "functioncall", expr);
			break;
	
		case 356:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_SVS(expr_code, "(", left_code, ")");
			break;
	
		case 361:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_VSVS(expr_code, left_code, "[", right_code, "]");
			break;
	
		case 365:
			/** 
			 * Evaluate the start part of the slice
			 */
			if (phalcon_array_isset_string(expr, SS("start"))) {
				PHALCON_OBS_VAR(start);
				phalcon_array_fetch_string(&start, expr, SL("start"), PH_NOISY_CC);
	
				PHALCON_INIT_VAR(start_code);
				PHALCON_CALL_METHOD_PARAMS_1(start_code, this_ptr, "expression", start);
			} else {
				PHALCON_INIT_NVAR(start_code);
				ZVAL_STRING(start_code, "null", 1);
			}
	
			/** 
			 * Evaluate the end part of the slice
			 */
			if (phalcon_array_isset_string(expr, SS("end"))) {
				PHALCON_OBS_VAR(end);
				phalcon_array_fetch_string(&end, expr, SL("end"), PH_NOISY_CC);
	
				PHALCON_INIT_VAR(end_code);
				PHALCON_CALL_METHOD_PARAMS_1(end_code, this_ptr, "expression", end);
			} else {
				PHALCON_INIT_NVAR(end_code);
				ZVAL_STRING(end_code, "null", 1);
			}
	
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_SVSVSVS(expr_code, "$this->slice(", left_code, ", ", start_code, ", ", end_code, ")");
			break;
	
		case 362:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_SVS(expr_code, "!isset(", left_code, ")");
			break;
	
		case 363:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_SVS(expr_code, "isset(", left_code, ")");
			break;
	
		case 367:
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CONCAT_SV(expr_code, "-", right_code);
			break;
	
		case 364:
			PHALCON_OBS_NVAR(expr_code);
			phalcon_array_fetch_string(&expr_code, expr, SL("value"), PH_NOISY_CC);
			break;
	
		default:
			PHALCON_OBS_VAR(line);
			phalcon_array_fetch_string(&line, expr, SL("line"), PH_NOISY_CC);
	
			PHALCON_OBS_VAR(file);
			phalcon_array_fetch_string(&file, expr, SL("file"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVSVSV(exception_message, "Unknown expression ", type, " in ", file, " on line ", line);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
			return;
	
	}
	
	RETURN_CCTOR(expr_code);
}

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementListOrExtends){

	zval *statements, *is_statement_list = NULL, *statement = NULL;
	zval *code;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &statements) == FAILURE) {
		RETURN_MM_NULL();
	}

	/** 
	 * Resolve the statement list as normal
	 */
	if (Z_TYPE_P(statements) != IS_ARRAY) { 
		RETURN_CCTOR(statements);
	}
	
	/** 
	 * If all elements in the statement list are arrays we resolve this as a
	 * statementList
	 */
	PHALCON_INIT_VAR(is_statement_list);
	ZVAL_BOOL(is_statement_list, 1);
	if (!phalcon_array_isset_string(statements, SS("type"))) {
	
		if (!phalcon_is_iterable(statements, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(statement);
	
			if (Z_TYPE_P(statement) != IS_ARRAY) { 
				PHALCON_INIT_NVAR(is_statement_list);
				ZVAL_BOOL(is_statement_list, 0);
				break;
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	/** 
	 * Resolve the statement list as normal
	 */
	if (PHALCON_IS_TRUE(is_statement_list)) {
		PHALCON_INIT_VAR(code);
		PHALCON_CALL_METHOD_PARAMS_1(code, this_ptr, "_statementlist", statements);
		RETURN_CCTOR(code);
	}
	
	/** 
	 * Is an array but not an statement list?
	 */
	
	RETURN_CCTOR(statements);
}

/**
 * Traverses a statement list compiling each of its nodes
 *
 * @param array $statement
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _statementList){

	zval *statements, *extends_mode = NULL, *extended = NULL, *block_mode = NULL;
	zval *compilation = NULL, *statement = NULL, *expr = NULL, *expr_code = NULL;
	zval *line = NULL, *file = NULL, *exception_message = NULL, *type = NULL, *code = NULL;
	zval *block_statements = NULL, *variable = NULL, *key = NULL, *if_expr = NULL;
	zval *if_expr_code = NULL, *autoescape = NULL, *block_name = NULL;
	zval *blocks = NULL, *path = NULL, *view = NULL, *views_dir = NULL, *final_path = NULL;
	zval *sub_compiler = NULL, *sub_compilation = NULL, *compiled_path = NULL;
	zval *lifetime = NULL, *old_autoescape = NULL, *level;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &statements, &extends_mode) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!extends_mode) {
		PHALCON_INIT_VAR(extends_mode);
		ZVAL_BOOL(extends_mode, 0);
	}
	
	/** 
	 * Nothing to compile
	 */
	if (!phalcon_fast_count_ev(statements TSRMLS_CC)) {
		PHALCON_MM_RESTORE();
		RETURN_EMPTY_STRING();
	}
	
	/** 
	 * Increase the statement recursion level in extends mode
	 */
	PHALCON_OBS_VAR(extended);
	phalcon_read_property(&extended, this_ptr, SL("_extended"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(block_mode);
	ZVAL_BOOL(block_mode, zend_is_true(extended) || zend_is_true(extends_mode));
	if (PHALCON_IS_TRUE(block_mode)) {
		phalcon_property_incr(this_ptr, SL("_level") TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(compilation);
	
	if (!phalcon_is_iterable(statements, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(statement);
	
		/** 
		 * All statements must be arrays
		 */
		if (Z_TYPE_P(statement) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Corrupted statement");
			return;
		}
	
		/** 
		 * Evaluate common expressions
		 */
		if (phalcon_array_isset_string(statement, SS("expr"))) {
			PHALCON_OBS_NVAR(expr);
			phalcon_array_fetch_string(&expr, statement, SL("expr"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(expr_code);
			PHALCON_CALL_METHOD_PARAMS_1(expr_code, this_ptr, "expression", expr);
		}
	
		/** 
		 * Check if the statement is valid
		 */
		if (!phalcon_array_isset_string(statement, SS("type"))) {
			PHALCON_OBS_NVAR(line);
			phalcon_array_fetch_string(&line, statement, SL("line"), PH_NOISY_CC);
	
			PHALCON_OBS_NVAR(file);
			phalcon_array_fetch_string(&file, statement, SL("file"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVSV(exception_message, "Invalid statement in ", file, " on line ", line);
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
			return;
		}
	
		PHALCON_OBS_NVAR(type);
		phalcon_array_fetch_string(&type, statement, SL("type"), PH_NOISY_CC);
	
		switch (phalcon_get_intval(type)) {
	
			case 357:
				/** 
				 * Raw output statement
				 */
				PHALCON_OBS_NVAR(code);
				phalcon_array_fetch_string(&code, statement, SL("value"), PH_NOISY_CC);
				phalcon_concat_self(&compilation, code TSRMLS_CC);
				break;
	
			case 300:
				/** 
				 * 'If' statement
				 */
				PHALCON_SCONCAT_SVS(compilation, "<?php if (", expr_code, ") { ?>");
				PHALCON_OBS_NVAR(block_statements);
				phalcon_array_fetch_string(&block_statements, statement, SL("true_statements"), PH_NOISY_CC);
	
				/** 
				 * Process statements in the 'true' block
				 */
				PHALCON_INIT_NVAR(code);
				PHALCON_CALL_METHOD_PARAMS_2(code, this_ptr, "_statementlist", block_statements, extends_mode);
				phalcon_concat_self(&compilation, code TSRMLS_CC);
	
				/** 
				 * Check for a 'else'/'elseif' block
				 */
				if (phalcon_array_isset_string(statement, SS("false_statements"))) {
					phalcon_concat_self_str(&compilation, SL("<?php } else { ?>") TSRMLS_CC);
	
					/** 
					 * Process statements in the 'false' block
					 */
					PHALCON_OBS_NVAR(block_statements);
					phalcon_array_fetch_string(&block_statements, statement, SL("false_statements"), PH_NOISY_CC);
	
					PHALCON_INIT_NVAR(code);
					PHALCON_CALL_METHOD_PARAMS_2(code, this_ptr, "_statementlist", block_statements, extends_mode);
					phalcon_concat_self(&compilation, code TSRMLS_CC);
				}
	
				phalcon_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
				break;
	
			case 302:
				/** 
				 * 'elseif' statement
				 */
				PHALCON_SCONCAT_SVS(compilation, "<?php } elseif (", expr_code, ") { ?>");
				break;
	
			case 304:
				/** 
				 * Foreach statement
				 */
				PHALCON_OBS_NVAR(variable);
				phalcon_array_fetch_string(&variable, statement, SL("variable"), PH_NOISY_CC);
	
				/** 
				 * Check if a 'key' variable needs to be calculated
				 */
				if (phalcon_array_isset_string(statement, SS("key"))) {
					PHALCON_OBS_NVAR(key);
					phalcon_array_fetch_string(&key, statement, SL("key"), PH_NOISY_CC);
					PHALCON_SCONCAT_SVSVSVS(compilation, "<?php foreach (", expr_code, " as $", key, " => $", variable, ") { ");
				} else {
					PHALCON_SCONCAT_SVSVS(compilation, "<?php foreach (", expr_code, " as $", variable, ") { ");
				}
	
				/** 
				 * Check for an 'if' expr in the block
				 */
				if (phalcon_array_isset_string(statement, SS("if_expr"))) {
					PHALCON_OBS_NVAR(if_expr);
					phalcon_array_fetch_string(&if_expr, statement, SL("if_expr"), PH_NOISY_CC);
	
					PHALCON_INIT_NVAR(if_expr_code);
					PHALCON_CALL_METHOD_PARAMS_1(if_expr_code, this_ptr, "expression", if_expr);
					PHALCON_SCONCAT_SVS(compilation, "if (", if_expr_code, ") { ?>");
				} else {
					phalcon_concat_self_str(&compilation, SL("?>") TSRMLS_CC);
				}
	
				/** 
				 * Process the block statements
				 */
				PHALCON_OBS_NVAR(block_statements);
				phalcon_array_fetch_string(&block_statements, statement, SL("block_statements"), PH_NOISY_CC);
	
				PHALCON_INIT_NVAR(code);
				PHALCON_CALL_METHOD_PARAMS_2(code, this_ptr, "_statementlist", block_statements, extends_mode);
				phalcon_concat_self(&compilation, code TSRMLS_CC);
				if (phalcon_array_isset_string(statement, SS("if_expr"))) {
					phalcon_concat_self_str(&compilation, SL("<?php } } ?>") TSRMLS_CC);
				} else {
					phalcon_concat_self_str(&compilation, SL("<?php } ?>") TSRMLS_CC);
				}
	
				break;
	
			case 306:
				/** 
				 * Set statement
				 */
				PHALCON_OBS_NVAR(variable);
				phalcon_array_fetch_string(&variable, statement, SL("variable"), PH_NOISY_CC);
				PHALCON_SCONCAT_SVSVS(compilation, "<?php $", variable, " = ", expr_code, "; ?>");
				break;
	
			case 359:
				/** 
				 * Echo statement
				 */
				PHALCON_OBS_NVAR(autoescape);
				phalcon_read_property(&autoescape, this_ptr, SL("_autoescape"), PH_NOISY_CC);
				if (zend_is_true(autoescape)) {
					PHALCON_SCONCAT_SVS(compilation, "<?php echo $this->escaper->escapeHtml(", expr_code, "); ?>");
				} else {
					PHALCON_SCONCAT_SVS(compilation, "<?php echo ", expr_code, "; ?>");
				}
	
				break;
	
			case 307:
				/** 
				 * Block statement
				 */
				PHALCON_OBS_NVAR(block_name);
				phalcon_array_fetch_string(&block_name, statement, SL("name"), PH_NOISY_CC);
				if (phalcon_array_isset_string(statement, SS("block_statements"))) {
					PHALCON_OBS_NVAR(block_statements);
					phalcon_array_fetch_string(&block_statements, statement, SL("block_statements"), PH_NOISY_CC);
				} else {
					PHALCON_INIT_NVAR(block_statements);
				}
	
				PHALCON_OBS_NVAR(blocks);
				phalcon_read_property(&blocks, this_ptr, SL("_blocks"), PH_NOISY_CC);
				if (zend_is_true(block_mode)) {
					if (Z_TYPE_P(blocks) != IS_ARRAY) { 
						PHALCON_INIT_NVAR(blocks);
						array_init(blocks);
					}
	
					/** 
					 * Create a unamed block
					 */
					if (Z_TYPE_P(compilation) != IS_NULL) {
						phalcon_array_append(&blocks, compilation, PH_SEPARATE TSRMLS_CC);
	
						PHALCON_INIT_NVAR(compilation);
					}
	
					/** 
					 * In extends mode we add the block statements to the blocks variable
					 */
					phalcon_array_update_zval(&blocks, block_name, &block_statements, PH_COPY | PH_SEPARATE TSRMLS_CC);
					phalcon_update_property_zval(this_ptr, SL("_blocks"), blocks TSRMLS_CC);
				} else {
					if (Z_TYPE_P(block_statements) == IS_ARRAY) { 
						PHALCON_INIT_NVAR(code);
						PHALCON_CALL_METHOD_PARAMS_2(code, this_ptr, "_statementlist", block_statements, extends_mode);
						phalcon_concat_self(&compilation, code TSRMLS_CC);
					}
				}
	
				break;
	
			case 310:
				/** 
				 * Extends statement
				 */
				PHALCON_OBS_NVAR(path);
				phalcon_array_fetch_string(&path, statement, SL("path"), PH_NOISY_CC);
	
				PHALCON_OBS_NVAR(view);
				phalcon_read_property(&view, this_ptr, SL("_view"), PH_NOISY_CC);
				if (Z_TYPE_P(view) == IS_OBJECT) {
					PHALCON_INIT_NVAR(views_dir);
					PHALCON_CALL_METHOD(views_dir, view, "getviewsdir");
	
					PHALCON_INIT_NVAR(final_path);
					PHALCON_CONCAT_VV(final_path, views_dir, path);
				} else {
					PHALCON_CPY_WRT(final_path, path);
				}
	
				PHALCON_INIT_NVAR(extended);
				ZVAL_BOOL(extended, 1);
	
				/** 
				 * Perform a subcompilation of the extended file
				 */
				PHALCON_INIT_NVAR(sub_compiler);
				if (phalcon_clone(sub_compiler, this_ptr TSRMLS_CC) == FAILURE) {
					return;
				}
	
				PHALCON_INIT_NVAR(sub_compilation);
				PHALCON_CALL_METHOD_PARAMS_2(sub_compilation, sub_compiler, "compile", final_path, extended);
	
				/** 
				 * If the compilation doesn't return anything we include the compiled path
				 */
				if (Z_TYPE_P(sub_compilation) == IS_NULL) {
					PHALCON_INIT_NVAR(compiled_path);
					PHALCON_CALL_METHOD(compiled_path, sub_compiler, "getcompiledtemplatepath");
	
					PHALCON_INIT_NVAR(sub_compilation);
					PHALCON_CALL_FUNC_PARAMS_1(sub_compilation, "file_get_contents", compiled_path);
				}
	
				phalcon_update_property_bool(this_ptr, SL("_extended"), 1 TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_extendedBlocks"), sub_compilation TSRMLS_CC);
				PHALCON_CPY_WRT(block_mode, extended);
				break;
	
			case 313:
				/** 
				 * Include statement
				 */
				PHALCON_OBS_NVAR(path);
				phalcon_array_fetch_string(&path, statement, SL("path"), PH_NOISY_CC);
	
				PHALCON_OBS_NVAR(view);
				phalcon_read_property(&view, this_ptr, SL("_view"), PH_NOISY_CC);
				if (Z_TYPE_P(view) == IS_OBJECT) {
					PHALCON_INIT_NVAR(views_dir);
					PHALCON_CALL_METHOD(views_dir, view, "getviewsdir");
	
					PHALCON_INIT_NVAR(final_path);
					PHALCON_CONCAT_VV(final_path, views_dir, path);
				} else {
					PHALCON_CPY_WRT(final_path, path);
				}
	
				/** 
				 * Perform a subcompilation of the included file
				 */
				PHALCON_INIT_NVAR(extended);
				ZVAL_BOOL(extended, 0);
	
				PHALCON_INIT_NVAR(sub_compiler);
				if (phalcon_clone(sub_compiler, this_ptr TSRMLS_CC) == FAILURE) {
					return;
				}
	
				PHALCON_INIT_NVAR(sub_compilation);
				PHALCON_CALL_METHOD_PARAMS_2(sub_compilation, sub_compiler, "compile", final_path, extended);
	
				/** 
				 * If the compilation doesn't return anything we include the compiled path
				 */
				if (Z_TYPE_P(sub_compilation) == IS_NULL) {
					PHALCON_INIT_NVAR(compiled_path);
					PHALCON_CALL_METHOD(compiled_path, sub_compiler, "getcompiledtemplatepath");
	
					PHALCON_INIT_NVAR(sub_compilation);
					PHALCON_CALL_FUNC_PARAMS_1(sub_compilation, "file_get_contents", compiled_path);
				}
	
				phalcon_concat_self(&compilation, sub_compilation TSRMLS_CC);
				break;
	
			case 314:
				/** 
				 * Cache statement
				 */
				PHALCON_SCONCAT_SVS(compilation, "<?php $_cache[", expr_code, "] = $this->di->get('viewCache'); ");
				PHALCON_SCONCAT_SVSVSVS(compilation, "$_cacheKey[", expr_code, "] = $_cache[", expr_code, "]->start(", expr_code, "); ");
				PHALCON_SCONCAT_SVS(compilation, "if ($_cacheKey[", expr_code, "] === null) { ?>");
				/** 
				 * Get the code in the block
				 */
				PHALCON_OBS_NVAR(block_statements);
				phalcon_array_fetch_string(&block_statements, statement, SL("block_statements"), PH_NOISY_CC);
	
				PHALCON_INIT_NVAR(code);
				PHALCON_CALL_METHOD_PARAMS_2(code, this_ptr, "_statementlist", block_statements, extends_mode);
				phalcon_concat_self(&compilation, code TSRMLS_CC);
	
				/** 
				 * Check if the cache has a lifetime
				 */
				if (phalcon_array_isset_string(statement, SS("lifetime"))) {
					PHALCON_OBS_NVAR(lifetime);
					phalcon_array_fetch_string(&lifetime, statement, SL("lifetime"), PH_NOISY_CC);
					PHALCON_SCONCAT_SVSVSVS(compilation, "<?php $_cache[", expr_code, "]->save(", expr_code, ", null, ", lifetime, "); ");
					PHALCON_SCONCAT_SVS(compilation, "} else { echo $_cacheKey[", expr_code, "]; } ?>");
				} else {
					PHALCON_SCONCAT_SVSVSVS(compilation, "<?php $_cache[", expr_code, "]->save(", expr_code, "); } else { echo $_cacheKey[", expr_code, "]; } ?>");
				}
	
				break;
	
			case 316:
				PHALCON_SCONCAT_SVS(compilation, "<?php ", expr_code, "; ?>");
				break;
	
			case 317:
				PHALCON_OBS_NVAR(old_autoescape);
				phalcon_read_property(&old_autoescape, this_ptr, SL("_autoescape"), PH_NOISY_CC);
	
				PHALCON_OBS_NVAR(autoescape);
				phalcon_array_fetch_string(&autoescape, statement, SL("enable"), PH_NOISY_CC);
				phalcon_update_property_zval(this_ptr, SL("_autoescape"), autoescape TSRMLS_CC);
	
				PHALCON_OBS_NVAR(block_statements);
				phalcon_array_fetch_string(&block_statements, statement, SL("block_statements"), PH_NOISY_CC);
	
				PHALCON_INIT_NVAR(code);
				PHALCON_CALL_METHOD_PARAMS_2(code, this_ptr, "_statementlist", block_statements, extends_mode);
				phalcon_concat_self(&compilation, code TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_autoescape"), old_autoescape TSRMLS_CC);
				break;
	
			case 319:
				phalcon_concat_self_str(&compilation, SL("<?php continue; ?>") TSRMLS_CC);
				break;
	
			case 320:
				phalcon_concat_self_str(&compilation, SL("<?php break; ?>") TSRMLS_CC);
				break;
	
			default:
				PHALCON_OBS_NVAR(line);
				phalcon_array_fetch_string(&line, statement, SL("line"), PH_NOISY_CC);
	
				PHALCON_OBS_NVAR(file);
				phalcon_array_fetch_string(&file, statement, SL("file"), PH_NOISY_CC);
	
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVSVSV(exception_message, "Unknown statement ", type, " in ", file, " on line ", line);
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
				return;
	
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Reduce the statement level nesting
	 */
	if (PHALCON_IS_TRUE(block_mode)) {
	
		PHALCON_OBS_VAR(level);
		phalcon_read_property(&level, this_ptr, SL("_level"), PH_NOISY_CC);
		if (PHALCON_IS_LONG(level, 1)) {
			if (Z_TYPE_P(compilation) != IS_NULL) {
				phalcon_update_property_array_append(this_ptr, SL("_blocks"), compilation TSRMLS_CC);
			}
		}
	
		phalcon_property_decr(this_ptr, SL("_level") TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(compilation);
}

/**
 * Compiles a Volt source code returning a PHP plain version
 *
 * @param string $viewCode
 * @param boolean $extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, _compileSource){

	zval *view_code, *extends_mode = NULL, *current_path;
	zval *intermediate, *compilation, *extended;
	zval *final_compilation = NULL, *blocks = NULL, *extended_blocks;
	zval *block = NULL, *name = NULL, *local_block = NULL, *block_compilation = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &view_code, &extends_mode) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!extends_mode) {
		PHALCON_INIT_VAR(extends_mode);
		ZVAL_BOOL(extends_mode, 0);
	}
	
	PHALCON_OBS_VAR(current_path);
	phalcon_read_property(&current_path, this_ptr, SL("_currentPath"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(intermediate);
	if (phvolt_parse_view(intermediate, view_code, current_path TSRMLS_CC) == FAILURE) {
		return;
	}
	if (Z_TYPE_P(intermediate) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(compilation);
		PHALCON_CALL_METHOD_PARAMS_2(compilation, this_ptr, "_statementlist", intermediate, extends_mode);
	
		/** 
		 * Check if the template is extending another
		 */
		PHALCON_OBS_VAR(extended);
		phalcon_read_property(&extended, this_ptr, SL("_extended"), PH_NOISY_CC);
		if (PHALCON_IS_TRUE(extended)) {
	
			/** 
			 * Multiple-Inheritance is allowed
			 */
			if (PHALCON_IS_TRUE(extends_mode)) {
				PHALCON_INIT_VAR(final_compilation);
				array_init(final_compilation);
			} else {
				PHALCON_INIT_NVAR(final_compilation);
			}
	
			PHALCON_OBS_VAR(blocks);
			phalcon_read_property(&blocks, this_ptr, SL("_blocks"), PH_NOISY_CC);
	
			PHALCON_OBS_VAR(extended_blocks);
			phalcon_read_property(&extended_blocks, this_ptr, SL("_extendedBlocks"), PH_NOISY_CC);
	
			if (!phalcon_is_iterable(extended_blocks, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_KEY(name, ah0, hp0);
				PHALCON_GET_FOREACH_VALUE(block);
	
				/** 
				 * If name is a string then is a block name
				 */
				if (Z_TYPE_P(name) == IS_STRING) {
					if (Z_TYPE_P(block) == IS_ARRAY) { 
						if (phalcon_array_isset(blocks, name)) {
							/** 
							 * The block is set in the local template
							 */
							PHALCON_OBS_NVAR(local_block);
							phalcon_array_fetch(&local_block, blocks, name, PH_NOISY_CC);
							phalcon_update_property_zval(this_ptr, SL("_currentBlock"), name TSRMLS_CC);
	
							PHALCON_INIT_NVAR(block_compilation);
							PHALCON_CALL_METHOD_PARAMS_1(block_compilation, this_ptr, "_statementlist", local_block);
						} else {
							/** 
							 * The block is not set local only in the extended template
							 */
							PHALCON_INIT_NVAR(block_compilation);
							PHALCON_CALL_METHOD_PARAMS_1(block_compilation, this_ptr, "_statementlist", block);
						}
					} else {
						if (phalcon_array_isset(blocks, name)) {
							/** 
							 * The block is set in the local template
							 */
							PHALCON_OBS_NVAR(local_block);
							phalcon_array_fetch(&local_block, blocks, name, PH_NOISY_CC);
							phalcon_update_property_zval(this_ptr, SL("_currentBlock"), name TSRMLS_CC);
	
							PHALCON_INIT_NVAR(block_compilation);
							PHALCON_CALL_METHOD_PARAMS_1(block_compilation, this_ptr, "_statementlist", local_block);
						} else {
							PHALCON_INIT_NVAR(block_compilation);
						}
					}
					if (PHALCON_IS_TRUE(extends_mode)) {
						phalcon_array_update_zval(&final_compilation, name, &block_compilation, PH_COPY | PH_SEPARATE TSRMLS_CC);
					} else {
						phalcon_concat_self(&final_compilation, block_compilation TSRMLS_CC);
					}
				} else {
					/** 
					 * Here the block is an already compiled text
					 */
					if (PHALCON_IS_TRUE(extends_mode)) {
						phalcon_array_append(&final_compilation, block, PH_SEPARATE TSRMLS_CC);
					} else {
						phalcon_concat_self(&final_compilation, block TSRMLS_CC);
					}
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
	
			RETURN_CCTOR(final_compilation);
		}
	
		if (PHALCON_IS_TRUE(extends_mode)) {
			/** 
			 * In extends mode we return the template blocks instead of the compilation
			 */
			PHALCON_OBS_NVAR(blocks);
			phalcon_read_property(&blocks, this_ptr, SL("_blocks"), PH_NOISY_CC);
			RETURN_CCTOR(blocks);
		}
	
	
		RETURN_CCTOR(compilation);
	}
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Invalid intermediate representation");
	return;
}

/**
 * Compiles a template into a string
 *
 *<code>
 * echo $compiler->compileString('{{ "hello world" }}');
 *</code>
 *
 * @param string $viewCode
 * @param boolean $extendsMode
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileString){

	zval *view_code, *extends_mode = NULL, *current_path;
	zval *compilation;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &view_code, &extends_mode) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!extends_mode) {
		PHALCON_INIT_VAR(extends_mode);
		ZVAL_BOOL(extends_mode, 0);
	}
	
	if (Z_TYPE_P(view_code) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The code must be string");
		return;
	}
	
	PHALCON_INIT_VAR(current_path);
	ZVAL_STRING(current_path, "eval code", 1);
	phalcon_update_property_zval(this_ptr, SL("_currentPath"), current_path TSRMLS_CC);
	
	PHALCON_INIT_VAR(compilation);
	PHALCON_CALL_METHOD_PARAMS_2(compilation, this_ptr, "_compilesource", view_code, extends_mode);
	
	RETURN_CCTOR(compilation);
}

/**
 * Compiles a template into a file forcing the destination path
 *
 *<code>
 *	$compiler->compile('views/layouts/main.volt', 'views/layouts/main.volt.php');
 *</code>
 *
 * @param string $path
 * @param string $compiledPath
 * @param boolean $extendsMode
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compileFile){

	zval *path, *compiled_path, *extends_mode = NULL, *view_code;
	zval *exception_message, *compilation, *final_compilation = NULL;
	zval *status;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &path, &compiled_path, &extends_mode) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!extends_mode) {
		PHALCON_INIT_VAR(extends_mode);
		ZVAL_BOOL(extends_mode, 0);
	}
	
	if (PHALCON_IS_EQUAL(path, compiled_path)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Template path and compilation template path cannot be the same");
		return;
	}
	
	/** 
	 * Always use file_get_contents instead of read the file directly, this respect the
	 * open_basedir directive
	 */
	PHALCON_INIT_VAR(view_code);
	PHALCON_CALL_FUNC_PARAMS_1(view_code, "file_get_contents", path);
	if (PHALCON_IS_FALSE(view_code)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Template file ", path, " could not be opened");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
		return;
	}
	
	phalcon_update_property_zval(this_ptr, SL("_currentPath"), path TSRMLS_CC);
	
	PHALCON_INIT_VAR(compilation);
	PHALCON_CALL_METHOD_PARAMS_2(compilation, this_ptr, "_compilesource", view_code, extends_mode);
	
	/** 
	 * We store the file serialized if it's an array of blocks
	 */
	if (Z_TYPE_P(compilation) == IS_ARRAY) { 
		PHALCON_INIT_VAR(final_compilation);
		PHALCON_CALL_FUNC_PARAMS_1(final_compilation, "serialize", compilation);
	} else {
		PHALCON_CPY_WRT(final_compilation, compilation);
	}
	
	/** 
	 * Always use file_put_contents to write files instead of write the file directly,
	 * this respect the open_basedir directive
	 */
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_FUNC_PARAMS_2(status, "file_put_contents", compiled_path, final_compilation);
	if (PHALCON_IS_FALSE(status)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Volt directory can't be written");
		return;
	}
	
	
	RETURN_CCTOR(compilation);
}

/**
 * Compiles a template into a file applying the compiler options
 * This method does not return the compiled path if the template was not compiled
 *
 *<code>
 *	$compiler->compile('views/layouts/main.volt');
 *	require $compiler->getCompiledTemplatePath();
 *</code>
 *
 * @param string $templatePath
 * @param boolean $extendsMode
 * @return string|array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, compile){

	zval *template_path, *extends_mode = NULL, *stat = NULL, *compile_always = NULL;
	zval *compiled_path = NULL, *prefix = NULL, *compiled_separator = NULL;
	zval *compiled_extension = NULL, *compilation = NULL, *options;
	zval *win_separator, *unix_separator, *template_win_path;
	zval *template_sep_path = NULL, *compiled_template_path = NULL;
	zval *blocks_code, *exception_message = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &template_path, &extends_mode) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!extends_mode) {
		PHALCON_INIT_VAR(extends_mode);
		ZVAL_BOOL(extends_mode, 0);
	}
	
	/** 
	 * Re-initialize some properties already initialized when the object is cloned
	 */
	phalcon_update_property_bool(this_ptr, SL("_extended"), 0 TSRMLS_CC);
	phalcon_update_property_bool(this_ptr, SL("_extendedBlocks"), 0 TSRMLS_CC);
	phalcon_update_property_null(this_ptr, SL("_blocks") TSRMLS_CC);
	phalcon_update_property_long(this_ptr, SL("_level"), 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(stat);
	ZVAL_BOOL(stat, 1);
	
	PHALCON_INIT_VAR(compile_always);
	ZVAL_BOOL(compile_always, 0);
	
	PHALCON_INIT_VAR(compiled_path);
	
	PHALCON_INIT_VAR(prefix);
	
	PHALCON_INIT_VAR(compiled_separator);
	ZVAL_STRING(compiled_separator, "%%", 1);
	
	PHALCON_INIT_VAR(compiled_extension);
	ZVAL_STRING(compiled_extension, ".php", 1);
	
	PHALCON_INIT_VAR(compilation);
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) { 
	
		/** 
		 * This makes that templates will be compiled always
		 */
		if (phalcon_array_isset_string(options, SS("compileAlways"))) {
	
			PHALCON_OBS_NVAR(compile_always);
			phalcon_array_fetch_string(&compile_always, options, SL("compileAlways"), PH_NOISY_CC);
			if (Z_TYPE_P(compile_always) != IS_BOOL) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compileAlways must be a bool value");
				return;
			}
		}
	
		/** 
		 * Prefix is prepended to the template name
		 */
		if (phalcon_array_isset_string(options, SS("prefix"))) {
	
			PHALCON_OBS_NVAR(prefix);
			phalcon_array_fetch_string(&prefix, options, SL("prefix"), PH_NOISY_CC);
			if (Z_TYPE_P(prefix) != IS_STRING) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "prefix must be a string");
				return;
			}
		}
	
		/** 
		 * Compiled path is a directory where the compiled templates will be located
		 */
		if (phalcon_array_isset_string(options, SS("compiledPath"))) {
	
			PHALCON_OBS_NVAR(compiled_path);
			phalcon_array_fetch_string(&compiled_path, options, SL("compiledPath"), PH_NOISY_CC);
			if (Z_TYPE_P(compiled_path) != IS_STRING) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledPath must be a string");
				return;
			}
		}
	
		/** 
		 * There is no compiled separator by default
		 */
		if (phalcon_array_isset_string(options, SS("compiledSeparator"))) {
	
			PHALCON_OBS_NVAR(compiled_separator);
			phalcon_array_fetch_string(&compiled_separator, options, SL("compiledSeparator"), PH_NOISY_CC);
			if (Z_TYPE_P(compiled_separator) != IS_STRING) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledSeparator must be a string");
				return;
			}
		}
	
		/** 
		 * By default the compile extension is .php
		 */
		if (phalcon_array_isset_string(options, SS("compiledExtension"))) {
	
			PHALCON_OBS_NVAR(compiled_extension);
			phalcon_array_fetch_string(&compiled_extension, options, SL("compiledExtension"), PH_NOISY_CC);
			if (Z_TYPE_P(compiled_extension) != IS_STRING) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledExtension must be a string");
				return;
			}
		}
	
		/** 
		 * Stat option assumes the compilation of the file
		 */
		if (phalcon_array_isset_string(options, SS("stat"))) {
			PHALCON_OBS_NVAR(stat);
			phalcon_array_fetch_string(&stat, options, SL("stat"), PH_NOISY_CC);
		}
	}
	
	if (Z_TYPE_P(compiled_path) != IS_NULL) {
		PHALCON_INIT_VAR(win_separator);
		ZVAL_STRING(win_separator, "\\", 1);
	
		PHALCON_INIT_VAR(unix_separator);
		ZVAL_STRING(unix_separator, "/", 1);
	
		PHALCON_INIT_VAR(template_win_path);
		phalcon_fast_str_replace(template_win_path, win_separator, compiled_separator, template_path TSRMLS_CC);
	
		PHALCON_INIT_VAR(template_sep_path);
		phalcon_fast_str_replace(template_sep_path, unix_separator, compiled_separator, template_win_path TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(template_sep_path, template_path);
	}
	
	/** 
	 * In extends mode we add an additional 'e' suffix to the file
	 */
	if (PHALCON_IS_TRUE(extends_mode)) {
		PHALCON_INIT_VAR(compiled_template_path);
		PHALCON_CONCAT_VVVVSVV(compiled_template_path, compiled_path, prefix, template_sep_path, compiled_separator, "e", compiled_separator, compiled_extension);
	} else {
		PHALCON_INIT_NVAR(compiled_template_path);
		PHALCON_CONCAT_VVVV(compiled_template_path, compiled_path, prefix, template_sep_path, compiled_extension);
	}
	
	if (zend_is_true(compile_always)) {
		/** 
		 * Compile always must be used only in the development stage
		 */
		PHALCON_CALL_METHOD_PARAMS_3(compilation, this_ptr, "compilefile", template_path, compiled_template_path, extends_mode);
	} else {
		if (PHALCON_IS_TRUE(stat)) {
			if (phalcon_file_exists(compiled_template_path TSRMLS_CC) == SUCCESS) {
	
				/** 
				 * Compare modification timestamps to check if the file needs to be recompiled
				 */
				if (phalcon_compare_mtime(template_path, compiled_template_path TSRMLS_CC)) {
					PHALCON_INIT_NVAR(compilation);
					PHALCON_CALL_METHOD_PARAMS_3(compilation, this_ptr, "compilefile", template_path, compiled_template_path, extends_mode);
				} else {
					if (PHALCON_IS_TRUE(extends_mode)) {
	
						/** 
						 * In extends mode we read the file that must contains a serialized array of blocks
						 */
						PHALCON_INIT_VAR(blocks_code);
						PHALCON_CALL_FUNC_PARAMS_1(blocks_code, "file_get_contents", compiled_template_path);
						if (PHALCON_IS_FALSE(blocks_code)) {
							PHALCON_INIT_VAR(exception_message);
							PHALCON_CONCAT_SVS(exception_message, "Extends compilation file ", compiled_template_path, " could not be opened");
							PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
							return;
						}
	
						/** 
						 * Unserialize the array blocks code
						 */
						if (zend_is_true(blocks_code)) {
							PHALCON_INIT_NVAR(compilation);
							PHALCON_CALL_FUNC_PARAMS_1(compilation, "unserialize", blocks_code);
						} else {
							PHALCON_INIT_NVAR(compilation);
							array_init(compilation);
						}
					}
				}
			} else {
				/** 
				 * The file doesn't exist so we compile the php version for the first time
				 */
				PHALCON_INIT_NVAR(compilation);
				PHALCON_CALL_METHOD_PARAMS_3(compilation, this_ptr, "compilefile", template_path, compiled_template_path, extends_mode);
			}
		} else {
			/** 
			 * Stat is off but the compiled file doesn't exist
			 */
			if (phalcon_file_exists(compiled_template_path TSRMLS_CC) == FAILURE) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Compiled template file ", compiled_template_path, " does not exist");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
				return;
			}
		}
	}
	
	phalcon_update_property_zval(this_ptr, SL("_compiledTemplatePath"), compiled_template_path TSRMLS_CC);
	
	RETURN_CCTOR(compilation);
}

/**
 * Returns the path to the last compiled template
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, getCompiledTemplatePath){


	RETURN_MEMBER(this_ptr, "_compiledTemplatePath");
}

/**
 * Parses a Volt template returning its intermediate representation
 *
 *<code>
 *	print_r($compiler->parse('{{ 3 + 2 }}'));
 *</code>
 *
 * @param string $viewCode
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Compiler, parse){

	zval *view_code, *current_path, *intermediate;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &view_code) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(current_path);
	ZVAL_STRING(current_path, "eval code", 1);
	
	PHALCON_INIT_VAR(intermediate);
	if (phvolt_parse_view(intermediate, view_code, current_path TSRMLS_CC) == FAILURE) {
		return;
	}
	RETURN_CTOR(intermediate);
}

