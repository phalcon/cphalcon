
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/output.h"
#include "kernel/hash.h"
#include "kernel/require.h"
#include "kernel/string.h"
#include "kernel/array.h"

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

	phalcon_fetch_params(0, 1, 0, &options);
	
	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "Options parameter must be an array");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);
	
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
	phalcon_read_property_this(&compiler, this_ptr, SL("_compiler"), PH_NOISY_CC);
	if (Z_TYPE_P(compiler) != IS_OBJECT) {
	
		PHALCON_OBS_VAR(view);
		phalcon_read_property_this(&view, this_ptr, SL("_view"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(options);
		phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(compiler);
		object_init_ex(compiler, phalcon_mvc_view_engine_volt_compiler_ce);
		phalcon_call_method_p1_noret(compiler, "__construct", view);
	
		/** 
		 * Pass the IoC to the compiler only of it's an object
		 */
		if (Z_TYPE_P(dependency_injector) == IS_OBJECT) {
			phalcon_call_method_p1_noret(compiler, "setdi", dependency_injector);
		}
	
		/** 
		 * Pass the options to the compiler only if they're an array
		 */
		if (Z_TYPE_P(options) == IS_ARRAY) { 
			phalcon_call_method_p1_noret(compiler, "setoptions", options);
		}
	
		phalcon_update_property_this(this_ptr, SL("_compiler"), compiler TSRMLS_CC);
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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &template_path, &params, &must_clean);
	
	if (!must_clean) {
		PHALCON_INIT_VAR(must_clean);
		ZVAL_BOOL(must_clean, 0);
	}
	
	if (PHALCON_IS_TRUE(must_clean)) {
		phalcon_ob_clean(TSRMLS_C);
	}
	
	/** 
	 * The compilation process is done by Phalcon\Mvc\View\Engine\Volt\Compiler
	 */
	PHALCON_INIT_VAR(compiler);
	phalcon_call_method(compiler, this_ptr, "getcompiler");
	phalcon_call_method_p1_noret(compiler, "compile", template_path);
	
	PHALCON_INIT_VAR(compiled_template_path);
	phalcon_call_method(compiled_template_path, compiler, "getcompiledtemplatepath");
	
	/** 
	 * Export the variables the current symbol table
	 */
	if (Z_TYPE_P(params) == IS_ARRAY) { 
	
		phalcon_is_iterable(params, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(key, ah0, hp0);
			PHALCON_GET_HVALUE(value);
	
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
		phalcon_ob_get_contents(contents TSRMLS_CC);
	
		PHALCON_OBS_VAR(view);
		phalcon_read_property_this(&view, this_ptr, SL("_view"), PH_NOISY_CC);
		phalcon_call_method_p1_noret(view, "setcontent", contents);
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

	phalcon_fetch_params(1, 1, 0, &item);
	
	PHALCON_INIT_VAR(length);
	ZVAL_LONG(length, 0);
	if (Z_TYPE_P(item) == IS_OBJECT) {
		phalcon_fast_count(length, item TSRMLS_CC);
	} else {
		if (Z_TYPE_P(item) == IS_ARRAY) { 
			PHALCON_INIT_NVAR(length);
			phalcon_fast_count(length, item TSRMLS_CC);
		} else {
			if (phalcon_function_exists_ex(SS("mb_strlen") TSRMLS_CC) == SUCCESS) {
				PHALCON_INIT_NVAR(length);
				phalcon_call_func_p1(length, "mb_strlen", item);
			} else {
				PHALCON_INIT_NVAR(length);
				phalcon_fast_strlen(length, item);
			}
		}
	}
	
	RETURN_CCTOR(length);
}

/**
 * Checks if the needle is included in the haystack
 *
 * @param mixed $needle
 * @param mixed $haystack
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, isIncluded){

	zval *needle, *haystack;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &needle, &haystack);
	
	if (Z_TYPE_P(haystack) == IS_ARRAY) { 
		phalcon_call_func_p2(return_value, "in_array", needle, haystack);
		RETURN_MM();
	}
	if (Z_TYPE_P(haystack) == IS_STRING) {
		if (phalcon_function_exists_ex(SS("mb_strpos") TSRMLS_CC) == SUCCESS) {
			phalcon_call_func_p2(return_value, "mb_strpos", haystack, needle);
			RETURN_MM();
		}
		phalcon_fast_strpos(return_value, haystack, needle);
		RETURN_MM();
	}
	
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Invalid haystack");
	return;
}

/**
 * Performs a string conversion
 *
 * @param string $text
 * @param string $from
 * @param string $to
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, convertEncoding){

	zval *text, *from, *to;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 3, 0, &text, &from, &to);
	
	/** 
	 * Try to use utf8_encode if conversion is 'latin1' to 'utf8'
	 */
	if (PHALCON_IS_STRING(from, "latin1")) {
		if (PHALCON_IS_STRING(to, "utf8")) {
			phalcon_call_func_p1(return_value, "utf8_encode", text);
			RETURN_MM();
		}
	}
	
	/** 
	 * Try to use utf8_decode if conversion is 'utf8' to 'latin1'
	 */
	if (PHALCON_IS_STRING(to, "latin1")) {
		if (PHALCON_IS_STRING(from, "utf8")) {
			phalcon_call_func_p1(return_value, "utf8_decode", text);
			RETURN_MM();
		}
	}
	
	/** 
	 * Fallback to mb_convert_encoding
	 */
	if (phalcon_function_exists_ex(SS("mb_convert_encoding") TSRMLS_CC) == SUCCESS) {
		phalcon_call_func_p3(return_value, "mb_convert_encoding", text, from, to);
		RETURN_MM();
	}
	
	/** 
	 * Fallback to iconv
	 */
	if (phalcon_function_exists_ex(SS("iconv") TSRMLS_CC) == SUCCESS) {
		phalcon_call_func_p3(return_value, "iconv", from, to, text);
		RETURN_MM();
	}
	
	/** 
	 * There are no enough extensions available
	 */
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "Any of 'mbstring' or 'iconv' is required to perform the charset conversion");
	return;
}

/**
 * Extracts a slice from a string/array/traversable object value
 *
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, slice){

	zval *value, *start, *end = NULL, *slice, *length = NULL, *position;
	zval *current = NULL, *one, *range;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &value, &start, &end);
	
	if (!end) {
		PHALCON_INIT_VAR(end);
	}
	
	/** 
	 * Objects must implement a Traversable interface
	 */
	if (Z_TYPE_P(value) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(slice);
		array_init(slice);
		if (Z_TYPE_P(end) == IS_NULL) {
			PHALCON_INIT_VAR(length);
			phalcon_fast_count(length, value TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(length, end);
		}
	
		PHALCON_INIT_VAR(position);
		ZVAL_LONG(position, 0);
		phalcon_call_method_noret(value, "rewind");
	
		while (1) {
	
			PHALCON_INIT_NVAR(r0);
			phalcon_call_method(r0, value, "valid");
			if (zend_is_true(r0)) {
			} else {
				break;
			}
	
			if (PHALCON_GE(position, start)) {
				if (PHALCON_LE(position, length)) {
					PHALCON_INIT_NVAR(current);
					phalcon_call_method(current, value, "current");
					phalcon_array_append(&slice, current, PH_SEPARATE);
				}
			}
			phalcon_call_method_noret(value, "next");
			PHALCON_SEPARATE(position);
			phalcon_increment(position);
		}
	
		RETURN_CTOR(slice);
	}
	
	/** 
	 * Calculate the slice length
	 */
	if (Z_TYPE_P(end) != IS_NULL) {
		PHALCON_INIT_VAR(one);
		ZVAL_LONG(one, 1);
	
		PHALCON_INIT_VAR(range);
		sub_function(range, end, start TSRMLS_CC);
	
		PHALCON_INIT_NVAR(length);
		phalcon_add_function(length, range, one TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(length);
	}
	
	/** 
	 * Use array_slice on arrays
	 */
	if (Z_TYPE_P(value) == IS_ARRAY) { 
		phalcon_call_func_p3(return_value, "array_slice", value, start, length);
		RETURN_MM();
	}
	
	/** 
	 * Use mb_substr if available
	 */
	if (phalcon_function_exists_ex(SS("mb_substr") TSRMLS_CC) == SUCCESS) {
		if (Z_TYPE_P(length) != IS_NULL) {
			phalcon_call_func_p3(return_value, "mb_substr", value, start, length);
			RETURN_MM();
		}
		phalcon_call_func_p2(return_value, "mb_substr", value, start);
		RETURN_MM();
	}
	
	/** 
	 * Use the standard substr function
	 */
	if (Z_TYPE_P(length) != IS_NULL) {
		phalcon_call_func_p3(return_value, "substr", value, start, length);
		RETURN_MM();
	}
	
	phalcon_call_func_p2(return_value, "substr", value, start);
	RETURN_MM();
}

/**
 * Sorts an array
 *
 * @param array $value
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, sort){

	zval *value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &value);
	
	Z_SET_ISREF_P(value);
	phalcon_call_func_p1_noret("asort", value);
	Z_UNSET_ISREF_P(value);
	RETURN_CCTOR(value);
}

