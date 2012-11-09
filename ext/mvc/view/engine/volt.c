
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
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/require.h"

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

	return SUCCESS;
}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, setDI){

	zval *dependency_injector;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
}

/**
 * Returns the dependency injection container
 *
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
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
		PHALCON_MM_RESTORE();
		RETURN_NULL();
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
 * Renders a view using the template engine
 *
 * @param string $templatePath
 * @param array $params
 * @param bool $mustClean
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, render){

	zval *template_path, *params, *must_clean, *stat = NULL;
	zval *compiled_path = NULL, *compiled_separator = NULL;
	zval *compiled_extension = NULL, *options, *win_separator;
	zval *unix_separator, *template_win_path;
	zval *template_sep_path = NULL, *compiled_template_path;
	zval *compiler = NULL, *exception_message, *value = NULL, *key = NULL;
	zval *contents, *view;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &template_path, &params, &must_clean) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (PHALCON_IS_TRUE(must_clean)) {
		PHALCON_CALL_FUNC_NORETURN("ob_clean");
	}
	
	PHALCON_INIT_VAR(stat);
	ZVAL_BOOL(stat, 1);
	
	PHALCON_INIT_VAR(compiled_path);
	
	PHALCON_INIT_VAR(compiled_separator);
	ZVAL_STRING(compiled_separator, "%%", 1);
	
	PHALCON_INIT_VAR(compiled_extension);
	ZVAL_STRING(compiled_extension, ".php", 1);
	
	PHALCON_INIT_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		eval_int = phalcon_array_isset_string(options, SS("compiledPath"));
		if (eval_int) {
			phalcon_array_fetch_string(&compiled_path, options, SL("compiledPath"), PH_NOISY_CC);
			if (Z_TYPE_P(compiled_path) != IS_STRING) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledPath must be a string");
				return;
			}
		}
		eval_int = phalcon_array_isset_string(options, SS("compiledSeparator"));
		if (eval_int) {
			PHALCON_INIT_NVAR(compiled_separator);
			phalcon_array_fetch_string(&compiled_separator, options, SL("compiledSeparator"), PH_NOISY_CC);
			if (Z_TYPE_P(compiled_separator) != IS_STRING) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledSeparator must be a string");
				return;
			}
		}
	
		eval_int = phalcon_array_isset_string(options, SS("compiledExtension"));
		if (eval_int) {
			PHALCON_INIT_NVAR(compiled_extension);
			phalcon_array_fetch_string(&compiled_extension, options, SL("compiledExtension"), PH_NOISY_CC);
			if (Z_TYPE_P(compiled_extension) != IS_STRING) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "compiledExtension must be a string");
				return;
			}
		}
	
		eval_int = phalcon_array_isset_string(options, SS("stat"));
		if (eval_int) {
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
	
	PHALCON_INIT_VAR(compiled_template_path);
	PHALCON_CONCAT_VVV(compiled_template_path, compiled_path, template_sep_path, compiled_extension);
	if (PHALCON_IS_TRUE(stat)) {
		if (phalcon_file_exists(compiled_template_path TSRMLS_CC) == SUCCESS) {
			if (phalcon_compare_mtime(template_path, compiled_template_path TSRMLS_CC)) {
				PHALCON_INIT_VAR(compiler);
				object_init_ex(compiler, phalcon_mvc_view_engine_volt_compiler_ce);
				PHALCON_CALL_METHOD_PARAMS_2_NORETURN(compiler, "compile", template_path, compiled_template_path, PH_NO_CHECK);
			}
		} else {
			PHALCON_INIT_NVAR(compiler);
			object_init_ex(compiler, phalcon_mvc_view_engine_volt_compiler_ce);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(compiler, "compile", template_path, compiled_template_path, PH_NO_CHECK);
		}
	} else {
		if (phalcon_file_exists(compiled_template_path TSRMLS_CC) == FAILURE) {
			PHALCON_INIT_VAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Compiled template file ", compiled_template_path, " does not exist");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
			return;
		}
	}
	
	
	if (!phalcon_valid_foreach(params TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(params);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
	
		PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(value);
	
		if (phalcon_set_symbol(key, value TSRMLS_CC) == FAILURE){
			return;
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	
	if (phalcon_require(compiled_template_path TSRMLS_CC) == FAILURE) {
		return;
	}
	if (PHALCON_IS_TRUE(must_clean)) {
		PHALCON_INIT_VAR(contents);
		PHALCON_CALL_FUNC(contents, "ob_get_contents");
	
		PHALCON_INIT_VAR(view);
		phalcon_read_property(&view, this_ptr, SL("_view"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(view, "setcontent", contents, PH_NO_CHECK);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Length filter
 *
 * @param mixed $item
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, length){

	zval *item, *length = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &item) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(item) == IS_STRING) {
		PHALCON_INIT_VAR(length);
		phalcon_fast_strlen(length, item);
	} else {
		PHALCON_INIT_NVAR(length);
		phalcon_fast_count(length, item TSRMLS_CC);
	}
	
	RETURN_CCTOR(length);
}

