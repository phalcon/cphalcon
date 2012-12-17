
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/require.h"
#include "kernel/string.h"

/**
 * Phalcon\Mvc\View\Engine\Volt
 *
 * Designer friendly and fast template engine for PHP written in C
 */


/**
 * Phalcon\Mvc\View\Engine\Volt initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine, Volt, mvc_view_engine_volt, "phalcon\\mvc\\view\\engine", phalcon_mvc_view_engine_volt_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_view_engine_volt_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_engine_volt_ce, SL("_compiler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_view_engine_volt_ce TSRMLS_CC, 1, phalcon_mvc_view_engineinterface_ce);

	return SUCCESS;
}

/**
 * Set Volt's options
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, setOptions){

	zval *options;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Options parameter must be an array");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_options"), options TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Return Volt's options
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getOptions){


	RETURN_MEMBER(this_ptr, "_options");
}

/**
 * Returns the Volt's compiler
 *
 * @return Phalcon\Mvc\View\Engine\Volt\Compiler
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getCompiler){

	zval *compiler = NULL, *view, *options, *dependency_injector;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(compiler);
	phalcon_read_property(&compiler, this_ptr, SL("_compiler"), PH_NOISY_CC);
	if (Z_TYPE_P(compiler) != IS_OBJECT) {
	
		PHALCON_OBS_VAR(view);
		phalcon_read_property(&view, this_ptr, SL("_view"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(options);
		phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(compiler);
		object_init_ex(compiler, phalcon_mvc_view_engine_volt_compiler_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(compiler, "__construct", view);
	
		if (Z_TYPE_P(dependency_injector) == IS_OBJECT) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(compiler, "setdi", dependency_injector);
		}
	
		if (Z_TYPE_P(options) == IS_ARRAY) { 
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(compiler, "setoptions", options);
		}
	
		phalcon_update_property_zval(this_ptr, SL("_compiler"), compiler TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(compiler);
}

/**
 * Renders a view using the template engine
 *
 * @param string $templatePath
 * @param array $params
 * @param boolean $mustClean
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, render){

	zval *template_path, *params, *must_clean = NULL, *compiler;
	zval *compiled_template_path, *value = NULL, *key = NULL, *contents;
	zval *view;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &template_path, &params, &must_clean) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!must_clean) {
		PHALCON_INIT_NVAR(must_clean);
		ZVAL_BOOL(must_clean, 0);
	}
	
	if (PHALCON_IS_TRUE(must_clean)) {
		PHALCON_CALL_FUNC_NORETURN("ob_clean");
	}
	
	/** 
	 * The compilation process is done by Phalcon\Mvc\View\Engine\Volt\Compiler
	 */
	PHALCON_INIT_VAR(compiler);
	PHALCON_CALL_METHOD(compiler, this_ptr, "getcompiler");
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(compiler, "compile", template_path);
	
	PHALCON_INIT_VAR(compiled_template_path);
	PHALCON_CALL_METHOD(compiled_template_path, compiler, "getcompiledtemplatepath");
	
	/** 
	 * Export the variables the current symbol table
	 */
	if (Z_TYPE_P(params) == IS_ARRAY) { 
	
		if (!phalcon_valid_foreach(params TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(params);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(value);
	
			if (phalcon_set_symbol(key, value TSRMLS_CC) == FAILURE){
				return;
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	if (phalcon_require(compiled_template_path TSRMLS_CC) == FAILURE) {
		return;
	}
	if (PHALCON_IS_TRUE(must_clean)) {
		PHALCON_INIT_VAR(contents);
		PHALCON_CALL_FUNC(contents, "ob_get_contents");
	
		PHALCON_OBS_VAR(view);
		phalcon_read_property(&view, this_ptr, SL("_view"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(view, "setcontent", contents);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Length filter. If an array/object is passed a count is performed otherwise a strlen/mb_strlen
 *
 * @param mixed $item
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, length){

	zval *item, *length = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &item) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(item) == IS_OBJECT) {
		PHALCON_INIT_VAR(length);
		phalcon_fast_count(length, item TSRMLS_CC);
	} else {
		if (Z_TYPE_P(item) == IS_OBJECT) {
			PHALCON_INIT_NVAR(length);
			phalcon_fast_count(length, item TSRMLS_CC);
		} else {
			if (phalcon_function_exists_ex(SS("mb_strlen") TSRMLS_CC) == SUCCESS) {
				PHALCON_INIT_NVAR(length);
				PHALCON_CALL_FUNC_PARAMS_1(length, "mb_strlen", item);
			} else {
				PHALCON_INIT_NVAR(length);
				phalcon_fast_strlen(length, item);
			}
		}
	}
	
	RETURN_CCTOR(length);
}

/**
 * Performs a string conversion
 *
 * @param string $text
 * @param string $from
 * @param string $to
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, converEncoding){

	zval *text, *from, *to, *converted = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &text, &from, &to) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (phalcon_function_exists_ex(SS("mb_convert_encoding") TSRMLS_CC) == SUCCESS) {
		PHALCON_INIT_VAR(converted);
		PHALCON_CALL_FUNC_PARAMS_3(converted, "mb_convert_encoding", text, from, to);
		RETURN_CCTOR(converted);
	} else {
		if (phalcon_function_exists_ex(SS("iconv") TSRMLS_CC) == SUCCESS) {
			PHALCON_INIT_NVAR(converted);
			PHALCON_CALL_FUNC_PARAMS_3(converted, "iconv", from, to, text);
			RETURN_CCTOR(converted);
		}
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Any of 'mbstring' or 'iconv' is required to perform the charset conversion");
	return;
}

