
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/view/engine/volt.h"
#include "mvc/view/engine/volt/compiler.h"
#include "mvc/view/engine.h"
#include "mvc/view/engineinterface.h"
#include "mvc/view/engine/helpers.h"
#include "mvc/view/exception.h"

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
zend_class_entry *phalcon_mvc_view_engine_volt_ce;

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, setOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getOptions);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, getCompiler);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, render);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, length);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, isIncluded);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, convertEncoding);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, slice);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, sort);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_length, 0, 0, 1)
	ZEND_ARG_INFO(0, item)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_isincluded, 0, 0, 2)
	ZEND_ARG_INFO(0, needle)
	ZEND_ARG_INFO(0, haystack)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_convertencoding, 0, 0, 3)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, to)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_slice, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, end)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_sort, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_view_engine_volt_method_entry[] = {
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, setOptions, arginfo_phalcon_mvc_view_engine_volt_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, getCompiler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, render, arginfo_phalcon_mvc_view_engineinterface_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, length, arginfo_phalcon_mvc_view_engine_volt_length, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, isIncluded, arginfo_phalcon_mvc_view_engine_volt_isincluded, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, convertEncoding, arginfo_phalcon_mvc_view_engine_volt_convertencoding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, slice, arginfo_phalcon_mvc_view_engine_volt_slice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt, sort, arginfo_phalcon_mvc_view_engine_volt_sort, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\View\Engine\Volt initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\View\\Engine, Volt, mvc_view_engine_volt, phalcon_mvc_view_engine_ce, phalcon_mvc_view_engine_volt_method_entry, 0);

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
	phalcon_read_property_this(&compiler, this_ptr, SL("_compiler"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(compiler) != IS_OBJECT) {
	
		PHALCON_OBS_VAR(view);
		phalcon_read_property_this(&view, this_ptr, SL("_view"), PH_NOISY TSRMLS_CC);
	
		PHALCON_OBS_VAR(options);
		phalcon_read_property_this(&options, this_ptr, SL("_options"), PH_NOISY TSRMLS_CC);
	
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	
		PHALCON_INIT_NVAR(compiler);
		object_init_ex(compiler, phalcon_mvc_view_engine_volt_compiler_ce);
		PHALCON_CALL_METHOD(NULL, compiler, "__construct", view);
	
		/** 
		 * Pass the IoC to the compiler only of it's an object
		 */
		if (Z_TYPE_P(dependency_injector) == IS_OBJECT) {
			PHALCON_CALL_METHOD(NULL, compiler, "setdi", dependency_injector);
		}
	
		/** 
		 * Pass the options to the compiler only if they're an array
		 */
		if (Z_TYPE_P(options) == IS_ARRAY) { 
			PHALCON_CALL_METHOD(NULL, compiler, "setoptions", options);
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

	zval **template_path, **params, **must_clean = NULL, *compiler = NULL;
	zval *compiled_template_path = NULL, *contents;
	zval *view;
	int clean;

	phalcon_fetch_params_ex(2, 1, &template_path, &params, &must_clean);
	PHALCON_ENSURE_IS_STRING(template_path);
	
	if (!must_clean) {
		clean = 0;
	}
	else {
		clean = PHALCON_IS_TRUE(*must_clean);
	}
	
	if (clean) {
		phalcon_ob_clean(TSRMLS_C);
	}

	PHALCON_MM_GROW();

	/** 
	 * The compilation process is done by Phalcon\Mvc\View\Engine\Volt\Compiler
	 */
	PHALCON_CALL_METHOD(&compiler, this_ptr, "getcompiler");
	PHALCON_CALL_METHOD(NULL, compiler, "compile", *template_path);
	PHALCON_CALL_METHOD(&compiled_template_path, compiler, "getcompiledtemplatepath");
	
	/** 
	 * Export the variables into the current symbol table
	 */
	if (Z_TYPE_PP(params) == IS_ARRAY) {
		if (!EG(active_symbol_table)) {
			zend_rebuild_symbol_table(TSRMLS_C);
		}

		zend_hash_merge_ex(
			EG(active_symbol_table),
			Z_ARRVAL_PP(params),
			(copy_ctor_func_t)zval_add_ref,
			sizeof(zval*),
			phalcon_mvc_view_engine_php_symtable_merger
#ifdef ZTS
			TSRMLS_CC
#else
			, NULL
#endif
		);
	}
	
	convert_to_string(compiled_template_path);
	if (phalcon_require(Z_STRVAL_P(compiled_template_path) TSRMLS_CC) == FAILURE) {
		RETVAL_FALSE;
		RETURN_MM();
	}

	if (clean) {
		PHALCON_INIT_VAR(contents);
		phalcon_ob_get_contents(contents TSRMLS_CC);
	
		view = phalcon_fetch_nproperty_this(this_ptr, SL("_view"), PH_NOISY TSRMLS_CC);
		PHALCON_CALL_METHOD(NULL, view, "setcontent", contents);
	}
	
	RETVAL_TRUE;
	PHALCON_MM_RESTORE();
}

/**
 * Length filter. If an array/object is passed a count is performed otherwise a strlen/mb_strlen
 *
 * @param mixed $item
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt, length){

	zval *item;

	phalcon_fetch_params(0, 1, 0, &item);
	
	if (Z_TYPE_P(item) == IS_OBJECT || Z_TYPE_P(item) == IS_ARRAY) {
		phalcon_fast_count(return_value, item TSRMLS_CC);
	} else if (phalcon_function_exists_ex(SS("mb_strlen") TSRMLS_CC) == SUCCESS) {
		PHALCON_RETURN_CALL_FUNCTIONW("mb_strlen", item);
	} else {
		phalcon_fast_strlen(return_value, item);
	}
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

	phalcon_fetch_params(0, 2, 0, &needle, &haystack);
	
	if (Z_TYPE_P(haystack) == IS_ARRAY) { 
		RETURN_BOOL(phalcon_fast_in_array(needle, haystack TSRMLS_CC));
	}

	if (Z_TYPE_P(haystack) == IS_STRING) {
		if (phalcon_function_exists_ex(SS("mb_strpos") TSRMLS_CC) == SUCCESS) {
			PHALCON_RETURN_CALL_FUNCTIONW("mb_strpos", haystack, needle);
			return;
		}

		phalcon_fast_strpos(return_value, haystack, needle);
	}
	
	PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_view_exception_ce, "Invalid haystack");
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
			PHALCON_RETURN_CALL_FUNCTION("utf8_encode", text);
			RETURN_MM();
		}
	}
	
	/** 
	 * Try to use utf8_decode if conversion is 'utf8' to 'latin1'
	 */
	if (PHALCON_IS_STRING(to, "latin1")) {
		if (PHALCON_IS_STRING(from, "utf8")) {
			PHALCON_RETURN_CALL_FUNCTION("utf8_decode", text);
			RETURN_MM();
		}
	}
	
	/** 
	 * Fallback to mb_convert_encoding
	 */
	if (phalcon_function_exists_ex(SS("mb_convert_encoding") TSRMLS_CC) == SUCCESS) {
		PHALCON_RETURN_CALL_FUNCTION("mb_convert_encoding", text, from, to);
		RETURN_MM();
	}
	
	/** 
	 * Fallback to iconv
	 */
	if (phalcon_function_exists_ex(SS("iconv") TSRMLS_CC) == SUCCESS) {
		PHALCON_RETURN_CALL_FUNCTION("iconv", from, to, text);
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
	zval *current = NULL, *range;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &value, &start, &end);
	
	if (!end) {
		end = PHALCON_GLOBAL(z_null);
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
		PHALCON_CALL_METHOD(NULL, value, "rewind");
	
		while (1) {
			PHALCON_CALL_METHOD(&r0, value, "valid");
			if (zend_is_true(r0)) {
			} else {
				break;
			}
	
			if (PHALCON_GE(position, start)) {
				if (PHALCON_LE(position, length)) {
					PHALCON_CALL_METHOD(&current, value, "current");
					phalcon_array_append(&slice, current, PH_SEPARATE);
				}
			}
			PHALCON_CALL_METHOD(NULL, value, "next");
			phalcon_increment(position);
		}
	
		RETURN_CTOR(slice);
	}
	
	/** 
	 * Calculate the slice length
	 */
	if (Z_TYPE_P(end) != IS_NULL) {
		PHALCON_INIT_VAR(range);
		sub_function(range, end, start TSRMLS_CC);
	
		PHALCON_INIT_NVAR(length);
		phalcon_add_function(length, range, PHALCON_GLOBAL(z_one) TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(length);
	}
	
	/** 
	 * Use array_slice on arrays
	 */
	if (Z_TYPE_P(value) == IS_ARRAY) { 
		PHALCON_RETURN_CALL_FUNCTION("array_slice", value, start, length);
		RETURN_MM();
	}
	
	/** 
	 * Use mb_substr if available
	 */
	if (phalcon_function_exists_ex(SS("mb_substr") TSRMLS_CC) == SUCCESS) {
		if (Z_TYPE_P(length) != IS_NULL) {
			PHALCON_RETURN_CALL_FUNCTION("mb_substr", value, start, length);
			RETURN_MM();
		}
		PHALCON_RETURN_CALL_FUNCTION("mb_substr", value, start);
		RETURN_MM();
	}
	
	/** 
	 * Use the standard substr function
	 */
	if (Z_TYPE_P(length) != IS_NULL) {
		PHALCON_RETURN_CALL_FUNCTION("substr", value, start, length);
		RETURN_MM();
	}
	
	PHALCON_RETURN_CALL_FUNCTION("substr", value, start);
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
	PHALCON_SEPARATE_PARAM(value);
	
	Z_SET_ISREF_P(value);
	PHALCON_CALL_FUNCTION(NULL, "asort", value);
	Z_UNSET_ISREF_P(value);
	RETURN_CTOR(value);
}
