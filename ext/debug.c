
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
#include "Zend/zend_builtin_functions.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/output.h"

/**
 * Phalcon\Debug
 *
 * Provides debug capabilities to Phalcon applications
 */


/**
 * Phalcon\Debug initializer
 */
PHALCON_INIT_CLASS(Phalcon_Debug){

	PHALCON_REGISTER_CLASS(Phalcon, Debug, debug, phalcon_debug_method_entry, 0);

	zend_declare_property_string(phalcon_debug_ce, SL("_uri"), "http://static.phalconphp.com/debug/1.2.0/", ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_string(phalcon_debug_ce, SL("_theme"), "default", ZEND_ACC_PUBLIC TSRMLS_CC);
	zend_declare_property_bool(phalcon_debug_ce, SL("_hideDocumentRoot"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_debug_ce, SL("_showBackTrace"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_debug_ce, SL("_showFiles"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_debug_ce, SL("_showFileFragment"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_debug_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_debug_ce, SL("_isActive"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;
}

/**
 * Change the base URI for static resources
 *
 * @param string $uri
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, setUri){

	zval *uri;

	phalcon_fetch_params(0, 1, 0, &uri);
	
	phalcon_update_property_this(this_ptr, SL("_uri"), uri TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Sets if files the exception's backtrace must be showed
 *
 * @param boolean $showBackTrace
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, setShowBackTrace){

	zval *show_back_trace;

	phalcon_fetch_params(0, 1, 0, &show_back_trace);
	
	phalcon_update_property_this(this_ptr, SL("_showBackTrace"), show_back_trace TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Set if files part of the backtrace must be shown in the output
 *
 * @param boolean $showFiles
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, setShowFiles){

	zval *show_files;

	phalcon_fetch_params(0, 1, 0, &show_files);
	
	phalcon_update_property_this(this_ptr, SL("_showFiles"), show_files TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Sets if files must be completely opened and showed in the output
 * or just the fragment related to the exception
 *
 * @param boolean $showFileFragment
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, setShowFileFragment){

	zval *show_file_fragment;

	phalcon_fetch_params(0, 1, 0, &show_file_fragment);
	
	phalcon_update_property_this(this_ptr, SL("_showFileFragment"), show_file_fragment TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Listen for uncaught exceptions and unsilent notices or warnings
 *
 * @param boolean $exceptions
 * @param boolean $lowSeverity
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, listen){

	zval *exceptions = NULL, *low_severity = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &exceptions, &low_severity);
	
	if (!exceptions) {
		PHALCON_INIT_VAR(exceptions);
		ZVAL_BOOL(exceptions, 1);
	}
	
	if (!low_severity) {
		PHALCON_INIT_VAR(low_severity);
		ZVAL_BOOL(low_severity, 0);
	}
	
	if (zend_is_true(exceptions)) {
		phalcon_call_method_noret(this_ptr, "listenexceptions");
	}
	if (zend_is_true(low_severity)) {
		phalcon_call_method_noret(this_ptr, "listenlowseverity");
	}
	
	RETURN_THIS();
}

/**
 * Listen for uncaught exceptions
 *
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, listenExceptions){

	zval *handler;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(handler);
	array_init_size(handler, 2);
	phalcon_array_append(&handler, this_ptr, PH_SEPARATE);
	add_next_index_stringl(handler, SL("onUncaughtException"), 1);
	phalcon_call_func_p1_noret("set_exception_handler", handler);
	RETURN_THIS();
}

/**
 * Listen for unsilent notices or warnings
 *
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, listenLowSeverity){

	zval *handler;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(handler);
	array_init_size(handler, 2);
	phalcon_array_append(&handler, this_ptr, PH_SEPARATE);
	add_next_index_stringl(handler, SL("onUncaughtLowSeverity"), 1);
	phalcon_call_func_p1_noret("set_exception_handler", handler);
	RETURN_THIS();
}

/**
 * Adds a variable to the debug output
 *
 * @param mixed $var
 * @param string $key
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, debugVar){

	zval *var, *key = NULL, *ztime, *backtrace, *data;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &var, &key);
	
	if (!key) {
		PHALCON_INIT_VAR(key);
	}
	
	PHALCON_INIT_VAR(ztime);
	ZVAL_LONG(ztime, (long) time(NULL));
	
	PHALCON_INIT_VAR(backtrace);
#if PHP_VERSION_ID < 50400
	zend_fetch_debug_backtrace(backtrace, 0, DEBUG_BACKTRACE_PROVIDE_OBJECT, 0 TSRMLS_CC);
#else
	zend_fetch_debug_backtrace(backtrace, 0, DEBUG_BACKTRACE_PROVIDE_OBJECT, 0 TSRMLS_CC);
#endif
	
	PHALCON_INIT_VAR(data);
	array_init_size(data, 3);
	phalcon_array_append(&data, var, PH_SEPARATE);
	phalcon_array_append(&data, backtrace, PH_SEPARATE);
	phalcon_array_append(&data, ztime, PH_SEPARATE);
	phalcon_update_property_array_append(this_ptr, SL("_data"), data TSRMLS_CC);
	RETURN_THIS();
}

/**
 * Clears are variables added previously
 *
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, clearVars){


	phalcon_update_property_null(this_ptr, SL("_data") TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Escapes a string with htmlentities
 *
 * @param string $value
 * @return string
 */
PHP_METHOD(Phalcon_Debug, _escapeString){

	zval *value, *charset, *ent_compat, *line_break;
	zval *escaped_line_break, *replaced_value;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &value);
	
	if (Z_TYPE_P(value) == IS_STRING) {
		PHALCON_INIT_VAR(charset);
		ZVAL_STRING(charset, "utf-8", 1);
	
		PHALCON_INIT_VAR(ent_compat);
		ZVAL_LONG(ent_compat, 2);
	
		PHALCON_INIT_VAR(line_break);
		ZVAL_STRING(line_break, "\n", 1);
	
		PHALCON_INIT_VAR(escaped_line_break);
		ZVAL_STRING(escaped_line_break, "\\n", 1);
	
		PHALCON_INIT_VAR(replaced_value);
		phalcon_fast_str_replace(replaced_value, line_break, escaped_line_break, value);
		phalcon_call_func_p3(return_value, "htmlentities", replaced_value, ent_compat, charset);
		RETURN_MM();
	}
	
	RETURN_CCTOR(value);
}

/**
 * Produces a recursive representation of an array
 *
 * @param array $argument
 * @return string
 */
PHP_METHOD(Phalcon_Debug, _getArrayDump){

	zval *argument, *n = NULL, *number_arguments, *one, *dump;
	zval *v = NULL, *k = NULL, *var_dump = NULL, *escaped_string = NULL, *next = NULL, *array_dump = NULL;
	zval *class_name = NULL, *joined_dump;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &argument, &n);
	
	if (!n) {
		PHALCON_INIT_VAR(n);
		ZVAL_LONG(n, 0);
	}
	
	PHALCON_INIT_VAR(number_arguments);
	phalcon_fast_count(number_arguments, argument TSRMLS_CC);
	if (PHALCON_LT_LONG(n, 3)) {
		if (PHALCON_GT_LONG(number_arguments, 0)) {
			if (PHALCON_LT_LONG(number_arguments, 10)) {
	
				PHALCON_INIT_VAR(one);
				ZVAL_LONG(one, 1);
	
				PHALCON_INIT_VAR(dump);
				array_init(dump);
	
				phalcon_is_iterable(argument, &ah0, &hp0, 0, 0);
	
				while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
					PHALCON_GET_HKEY(k, ah0, hp0);
					PHALCON_GET_HVALUE(v);
	
					if (PHALCON_IS_SCALAR(v)) {
						if (PHALCON_IS_STRING(v, "")) {
							PHALCON_INIT_NVAR(var_dump);
							PHALCON_CONCAT_SVS(var_dump, "[", k, "] =&gt; (empty string)");
						} else {
							PHALCON_INIT_NVAR(escaped_string);
							phalcon_call_method_p1(escaped_string, this_ptr, "_escapestring", v);
	
							PHALCON_INIT_NVAR(var_dump);
							PHALCON_CONCAT_SVSV(var_dump, "[", k, "] =&gt; ", escaped_string);
						}
						phalcon_array_append(&dump, var_dump, PH_SEPARATE);
					} else {
						if (Z_TYPE_P(v) == IS_ARRAY) { 
							PHALCON_INIT_NVAR(next);
							phalcon_add_function(next, n, one TSRMLS_CC);
	
							PHALCON_INIT_NVAR(array_dump);
							phalcon_call_method_p2(array_dump, this_ptr, "_getarraydump", v, next);
	
							PHALCON_INIT_NVAR(var_dump);
							PHALCON_CONCAT_SVSVS(var_dump, "[", k, "] =&gt; Array(", array_dump, ")");
							phalcon_array_append(&dump, var_dump, PH_SEPARATE);
							zend_hash_move_forward_ex(ah0, &hp0);
							continue;
						}
						if (Z_TYPE_P(v) == IS_OBJECT) {
							PHALCON_INIT_NVAR(class_name);
							phalcon_get_class(class_name, v, 0 TSRMLS_CC);
	
							PHALCON_INIT_NVAR(var_dump);
							PHALCON_CONCAT_SVSVS(var_dump, "[", k, "] =&gt; Object(", class_name, ")");
							phalcon_array_append(&dump, var_dump, PH_SEPARATE);
							zend_hash_move_forward_ex(ah0, &hp0);
							continue;
						}
	
						if (Z_TYPE_P(v) == IS_NULL) {
							PHALCON_INIT_NVAR(var_dump);
							PHALCON_CONCAT_SVS(var_dump, "[", k, "] =&gt; null");
							phalcon_array_append(&dump, var_dump, PH_SEPARATE);
							zend_hash_move_forward_ex(ah0, &hp0);
							continue;
						}
	
						PHALCON_INIT_NVAR(var_dump);
						PHALCON_CONCAT_SVSV(var_dump, "[", k, "] =&gt; ", v);
						phalcon_array_append(&dump, var_dump, PH_SEPARATE);
					}
	
					zend_hash_move_forward_ex(ah0, &hp0);
				}
	
				PHALCON_INIT_VAR(joined_dump);
				phalcon_fast_join_str(joined_dump, SL(", "), dump TSRMLS_CC);
	
				RETURN_CTOR(joined_dump);
			}
	
			RETURN_NCTOR(number_arguments);
		}
	}
	
	RETURN_MM_NULL();
}

/**
 * Produces an string representation of a variable
 *
 * @param mixed $variable
 * @return string
 */
PHP_METHOD(Phalcon_Debug, _getVarDump){

	zval *variable, *class_name, *dumped_object;
	zval *array_dump = NULL, *dump = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &variable);
	
	if (PHALCON_IS_SCALAR(variable)) {
	
		/** 
		 * Boolean variables are represented as 'true'/'false'
		 */
		if (Z_TYPE_P(variable) == IS_BOOL) {
			if (zend_is_true(variable)) {
				RETURN_MM_STRING("true", 1);
			} else {
				RETURN_MM_STRING("false", 1);
			}
		}
	
		/** 
		 * String variables are escaped to avoid XSS injections
		 */
		if (Z_TYPE_P(variable) == IS_STRING) {
			phalcon_call_method_p1(return_value, this_ptr, "_escapestring", variable);
			RETURN_MM();
		}
	
		/** 
		 * Other scalar variables are just converted to strings
		 */
	
		RETURN_CCTOR(variable);
	}
	
	/** 
	 * If the variable is an object print its class name
	 */
	if (Z_TYPE_P(variable) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(class_name);
		phalcon_get_class(class_name, variable, 0 TSRMLS_CC);
	
		/** 
		 * Try to check for a 'dump' method, this surely produces a better printable
		 * representation
		 */
		if (phalcon_method_exists_ex(variable, SS("dump") TSRMLS_CC) == SUCCESS) {
			PHALCON_INIT_VAR(dumped_object);
			phalcon_call_method(dumped_object, variable, "dump");
	
			/** 
			 * dump() must return an array, generate a recursive representation using
			 * getArrayDump
			 */
			PHALCON_INIT_VAR(array_dump);
			phalcon_call_method_p1(array_dump, this_ptr, "_getarraydump", dumped_object);
	
			PHALCON_INIT_VAR(dump);
			PHALCON_CONCAT_SVSVS(dump, "Object(", class_name, ": ", array_dump, ")");
		} else {
			/** 
			 * If dump() is not available just print the class name
			 */
			PHALCON_INIT_NVAR(dump);
			PHALCON_CONCAT_SVS(dump, "Object(", class_name, ")</span>");
		}
	
		RETURN_CTOR(dump);
	}
	
	/** 
	 * Recursively process the array and enclose it in Array()
	 */
	if (Z_TYPE_P(variable) == IS_ARRAY) { 
		PHALCON_INIT_NVAR(array_dump);
		phalcon_call_method_p1(array_dump, this_ptr, "_getarraydump", variable);
		PHALCON_CONCAT_SVS(return_value, "Array(", array_dump, ")");
		RETURN_MM();
	}
	
	/** 
	 * Null variables are represented as 'null'
	 * Other types are represented by its type
	 */
	RETURN_MM_STRING(zend_zval_type_name(variable), 1);
}

/**
 * Returns the major framework's version
 *
 * @return string
 */
PHP_METHOD(Phalcon_Debug, getMajorVersion){

	zval *version, *parts, *major;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(version);
	PHALCON_CALL_STATIC(version, "phalcon\\version", "get");
	
	PHALCON_INIT_VAR(parts);
	phalcon_fast_explode_str(parts, SL(" "), version);
	
	PHALCON_OBS_VAR(major);
	phalcon_array_fetch_long(&major, parts, 0, PH_NOISY);
	RETURN_CCTOR(major);
}

/**
 * Generates a link to the current version documentation
 *
 * @return string
 */
PHP_METHOD(Phalcon_Debug, getVersion){

	zval *version;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(version);
	phalcon_call_method(version, this_ptr, "getmajorversion");
	PHALCON_CONCAT_SVSVS(return_value, "<div class=\"version\">Phalcon Framework <a target=\"_new\" href=\"http://docs.phalconphp.com/en/", version, "/\">", version, "</a></div>");
	RETURN_MM();
}

/**
 * Returns the css sources
 *
 * @return string
 */
PHP_METHOD(Phalcon_Debug, getCssSources){

	zval *uri, *sources;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(uri);
	phalcon_read_property_this(&uri, this_ptr, SL("_uri"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sources);
	PHALCON_CONCAT_SVS(sources, "<link href=\"", uri, "jquery/jquery-ui.css\" type=\"text/css\" rel=\"stylesheet\" />");
	PHALCON_SCONCAT_SVS(sources, "<link href=\"", uri, "themes/default/style.css\" type=\"text/css\" rel=\"stylesheet\" />");
	RETURN_CTOR(sources);
}

/**
 * Returns the javascript sources
 *
 * @return string
 */
PHP_METHOD(Phalcon_Debug, getJsSources){

	zval *uri, *sources;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(uri);
	phalcon_read_property_this(&uri, this_ptr, SL("_uri"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sources);
	PHALCON_CONCAT_SVS(sources, "<script type=\"text/javascript\" src=\"", uri, "jquery/jquery.js\"></script>");
	PHALCON_SCONCAT_SVS(sources, "<script type=\"text/javascript\" src=\"", uri, "jquery/jquery-ui.js\"></script>");
	PHALCON_SCONCAT_SVS(sources, "<script type=\"text/javascript\" src=\"", uri, "jquery/jquery.scrollTo.js\"></script>");
	PHALCON_SCONCAT_SVS(sources, "<script type=\"text/javascript\" src=\"", uri, "prettify/prettify.js\"></script>");
	PHALCON_SCONCAT_SVS(sources, "<script type=\"text/javascript\" src=\"", uri, "pretty.js\"></script>");
	RETURN_CTOR(sources);
}

/**
 * Shows a backtrace item
 *
 * @param int $n
 * @param array $trace
 */
PHP_METHOD(Phalcon_Debug, showTraceItem){

	zval *n, *trace, *space, *two_spaces, *underscore;
	zval *minus, *html, *class_name, *pattern, *is_phalcon_class;
	zval *namespace_separator, *prepare_uri_class;
	zval *class_reflection, *is_internal = NULL, *lower_class_name;
	zval *prepare_internal_class, *type, *function_name = NULL;
	zval *function_reflection, *prepared_function_name;
	zval *trace_args, *arguments, *argument = NULL, *dumped_argument = NULL;
	zval *span_argument = NULL, *joined_arguments, *one;
	zval *file, *line, *show_files, *lines, *number_lines;
	zval *show_file_fragment, *seven, *before_line;
	zval *first_line = NULL, *five, *after_line, *last_line = NULL;
	zval *comment_pattern, *utf8, *ent_compat, *tab;
	zval *comment, *i = NULL, *line_position = NULL, *current_line = NULL;
	zval *trimmed = NULL, *is_comment = NULL, *spaced_current_line = NULL;
	zval *escaped_line = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &n, &trace);
	
	PHALCON_INIT_VAR(space);
	ZVAL_STRING(space, " ", 1);
	
	PHALCON_INIT_VAR(two_spaces);
	ZVAL_STRING(two_spaces, "  ", 1);
	
	PHALCON_INIT_VAR(underscore);
	ZVAL_STRING(underscore, "_", 1);
	
	PHALCON_INIT_VAR(minus);
	ZVAL_STRING(minus, "-", 1);
	
	/** 
	 * Every trace in the backtrace have a unique number
	 */
	PHALCON_INIT_VAR(html);
	PHALCON_CONCAT_SVS(html, "<tr><td align=\"right\" valign=\"top\" class=\"error-number\">#", n, "</td><td>");
	if (phalcon_array_isset_string(trace, SS("class"))) {
	
		PHALCON_OBS_VAR(class_name);
		phalcon_array_fetch_string(&class_name, trace, SL("class"), PH_NOISY);
	
		PHALCON_INIT_VAR(pattern);
		ZVAL_STRING(pattern, "/^Phalcon/", 1);
	
		PHALCON_INIT_VAR(is_phalcon_class);
	
		#if HAVE_BUNDLED_PCRE
		phalcon_preg_match(is_phalcon_class, pattern, class_name, NULL TSRMLS_CC);
		#else
		phalcon_call_func_p2(is_phalcon_class, "preg_match", pattern, class_name);
		#endif
	
		/** 
		 * We assume that classes starting by Phalcon are framework's classes
		 */
		if (zend_is_true(is_phalcon_class)) {
			PHALCON_INIT_VAR(namespace_separator);
			ZVAL_STRING(namespace_separator, "\\", 1);
	
			/** 
			 * Prepare the class name according to the Phalcon's conventions
			 */
			PHALCON_INIT_VAR(prepare_uri_class);
			phalcon_fast_str_replace(prepare_uri_class, namespace_separator, underscore, class_name);
	
			/** 
			 * Generate a link to the official docs
			 */
			PHALCON_SCONCAT_SVSVS(html, "<span class=\"error-class\"><a target=\"_new\" href=\"http://docs.phalconphp.com/en/latest/api/", prepare_uri_class, ".html\">", class_name, "</a></span>");
		} else {
			ce0 = zend_fetch_class(SL("ReflectionClass"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			PHALCON_INIT_VAR(class_reflection);
			object_init_ex(class_reflection, ce0);
			if (phalcon_has_constructor(class_reflection TSRMLS_CC)) {
				phalcon_call_method_p1_noret(class_reflection, "__construct", class_name);
			}
	
			/** 
			 * Check if classes are PHP's classes
			 */
			PHALCON_INIT_VAR(is_internal);
			phalcon_call_method(is_internal, class_reflection, "isinternal");
			if (zend_is_true(is_internal)) {
				PHALCON_INIT_VAR(lower_class_name);
				phalcon_fast_strtolower(lower_class_name, class_name);
	
				PHALCON_INIT_VAR(prepare_internal_class);
				phalcon_fast_str_replace(prepare_internal_class, underscore, minus, lower_class_name);
	
				/** 
				 * Generate a link to the official docs
				 */
				PHALCON_SCONCAT_SVSVS(html, "<span class=\"error-class\"><a target=\"_new\" href=\"http://php.net/manual/en/class.", prepare_internal_class, ".php\">", class_name, "</a></span>");
			} else {
				PHALCON_SCONCAT_SVS(html, "<span class=\"error-class\">", class_name, "</span>");
			}
		}
	
		/** 
		 * Object access operator: static/instance
		 */
		PHALCON_OBS_VAR(type);
		phalcon_array_fetch_string(&type, trace, SL("type"), PH_NOISY);
		phalcon_concat_self(&html, type TSRMLS_CC);
	}
	
	/** 
	 * Normally the backtrace contains only classes
	 */
	if (phalcon_array_isset_string(trace, SS("class"))) {
		PHALCON_OBS_VAR(function_name);
		phalcon_array_fetch_string(&function_name, trace, SL("function"), PH_NOISY);
		PHALCON_SCONCAT_SVS(html, "<span class=\"error-function\">", function_name, "</span>");
	} else {
		PHALCON_OBS_NVAR(function_name);
		phalcon_array_fetch_string(&function_name, trace, SL("function"), PH_NOISY);
	
		/** 
		 * Check if the function exists
		 */
		if (phalcon_function_exists(function_name TSRMLS_CC) == SUCCESS) {
			ce1 = zend_fetch_class(SL("ReflectionFunction"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			PHALCON_INIT_VAR(function_reflection);
			object_init_ex(function_reflection, ce1);
			if (phalcon_has_constructor(function_reflection TSRMLS_CC)) {
				phalcon_call_method_p1_noret(function_reflection, "__construct", function_name);
			}
	
			PHALCON_INIT_NVAR(is_internal);
			phalcon_call_method(is_internal, function_reflection, "isinternal");
	
			/** 
			 * Internal functions links to the PHP documentation
			 */
			if (zend_is_true(is_internal)) {
				/** 
				 * Prepare function's name according to the conventions in the docs
				 */
				PHALCON_INIT_VAR(prepared_function_name);
				phalcon_fast_str_replace(prepared_function_name, underscore, minus, function_name);
				PHALCON_SCONCAT_SVSVS(html, "<span class=\"error-function\"><a target=\"_new\" href=\"http://php.net/manual/en/function.", prepared_function_name, ".php\">", function_name, "</a></span>");
			} else {
				PHALCON_SCONCAT_SVS(html, "<span class=\"error-function\">", function_name, "</span>");
			}
		} else {
			PHALCON_SCONCAT_SVS(html, "<span class=\"error-function\">", function_name, "</span>");
		}
	}
	
	/** 
	 * Check for arguments in the function
	 */
	if (phalcon_array_isset_string(trace, SS("args"))) {
	
		PHALCON_OBS_VAR(trace_args);
		phalcon_array_fetch_string(&trace_args, trace, SL("args"), PH_NOISY);
		if (phalcon_fast_count_ev(trace_args TSRMLS_CC)) {
	
			PHALCON_INIT_VAR(arguments);
			array_init(arguments);
	
			phalcon_is_iterable(trace_args, &ah0, &hp0, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HVALUE(argument);
	
				/** 
				 * Every argument is generated using _getVarDump
				 */
				PHALCON_INIT_NVAR(dumped_argument);
				phalcon_call_method_p1(dumped_argument, this_ptr, "_getvardump", argument);
	
				PHALCON_INIT_NVAR(span_argument);
				PHALCON_CONCAT_SVS(span_argument, "<span class=\"error-parameter\">", dumped_argument, "</span>");
	
				/** 
				 * Append the HTML generated to the argument's list
				 */
				phalcon_array_append(&arguments, span_argument, PH_SEPARATE);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			/** 
			 * Join all the arguments
			 */
			PHALCON_INIT_VAR(joined_arguments);
			phalcon_fast_join_str(joined_arguments, SL(", "), arguments TSRMLS_CC);
			PHALCON_SCONCAT_SVS(html, "(", joined_arguments, ")");
		} else {
			phalcon_concat_self_str(&html, SL("()") TSRMLS_CC);
		}
	}
	
	/** 
	 * When 'file' is present, it usually means the function is provided by the user
	 */
	if (phalcon_array_isset_string(trace, SS("file"))) {
	
		PHALCON_INIT_VAR(one);
		ZVAL_LONG(one, 1);
	
		PHALCON_OBS_VAR(file);
		phalcon_array_fetch_string(&file, trace, SL("file"), PH_NOISY);
	
		PHALCON_OBS_VAR(line);
		phalcon_array_fetch_string(&line, trace, SL("line"), PH_NOISY);
	
		/** 
		 * Realpath to the file and its line using a special header
		 */
		PHALCON_SCONCAT_SVSVS(html, "<br/><div class=\"error-file\">", file, " (", line, ")</div>");
	
		PHALCON_OBS_VAR(show_files);
		phalcon_read_property_this(&show_files, this_ptr, SL("_showFiles"), PH_NOISY_CC);
	
		/** 
		 * The developer can change if the files must be opened or not
		 */
		if (zend_is_true(show_files)) {
	
			/** 
			 * Open the file to an array using 'file', this respects the openbase-dir directive
			 */
			PHALCON_INIT_VAR(lines);
			phalcon_call_func_p1(lines, "file", file);
	
			PHALCON_INIT_VAR(number_lines);
			phalcon_fast_count(number_lines, lines TSRMLS_CC);
	
			PHALCON_OBS_VAR(show_file_fragment);
			phalcon_read_property_this(&show_file_fragment, this_ptr, SL("_showFileFragment"), PH_NOISY_CC);
	
			/** 
			 * File fragments just show a piece of the file where the exception is located
			 */
			if (zend_is_true(show_file_fragment)) {
	
				/** 
				 * Take seven lines back to the current exception's line, @TODO add an option for
				 * this
				 */
				PHALCON_INIT_VAR(seven);
				ZVAL_LONG(seven, 7);
	
				PHALCON_INIT_VAR(before_line);
				sub_function(before_line, line, seven TSRMLS_CC);
	
				/** 
				 * Check for overflows
				 */
				if (PHALCON_LT_LONG(before_line, 1)) {
					PHALCON_CPY_WRT(first_line, one);
				} else {
					PHALCON_CPY_WRT(first_line, before_line);
				}
	
				/** 
				 * Take five lines after the current exception's line, @TODO add an option for this
				 */
				PHALCON_INIT_VAR(five);
				ZVAL_LONG(five, 5);
	
				PHALCON_INIT_VAR(after_line);
				phalcon_add_function(after_line, line, five TSRMLS_CC);
	
				/** 
				 * Check for overflows
				 */
				if (PHALCON_GT(after_line, number_lines)) {
					PHALCON_CPY_WRT(last_line, number_lines);
				} else {
					PHALCON_CPY_WRT(last_line, after_line);
				}
	
				PHALCON_SCONCAT_SVSVSVS(html, "<pre class='prettyprint highlight:", first_line, ":", line, " linenums:", first_line, "'>");
			} else {
				PHALCON_CPY_WRT(first_line, one);
				PHALCON_CPY_WRT(last_line, number_lines);
				PHALCON_SCONCAT_SVSVS(html, "<pre class='prettyprint highlight:", first_line, ":", line, " linenums error-scroll'>");
			}
	
			PHALCON_INIT_VAR(comment_pattern);
			ZVAL_STRING(comment_pattern, "#\\*\\/$#", 1);
	
			/** 
			 * We assume the file is utf-8 encoded, @TODO add an option for this
			 */
			PHALCON_INIT_VAR(utf8);
			ZVAL_STRING(utf8, "UTF-8", 1);
	
			/** 
			 * Don't escape quotes
			 */
			PHALCON_INIT_VAR(ent_compat);
			ZVAL_LONG(ent_compat, 2);
	
			PHALCON_INIT_VAR(tab);
			ZVAL_STRING(tab, "\t", 1);
	
			PHALCON_INIT_VAR(comment);
			ZVAL_STRING(comment, "* /", 1);
			PHALCON_CPY_WRT(i, first_line);
	
			while (1) {
	
				if (PHALCON_LE(i, last_line)) {
				} else {
					break;
				}
	
				/** 
				 * Current line in the file
				 */
				PHALCON_INIT_NVAR(line_position);
				sub_function(line_position, i, one TSRMLS_CC);
	
				/** 
				 * Current line content in the piece of file
				 */
				PHALCON_OBS_NVAR(current_line);
				phalcon_array_fetch(&current_line, lines, line_position, PH_NOISY);
	
				/** 
				 * File fragments are cleaned, removing tabs and comments
				 */
				if (zend_is_true(show_file_fragment)) {
					if (PHALCON_IS_EQUAL(i, first_line)) {
	
						PHALCON_INIT_NVAR(trimmed);
						phalcon_fast_trim(trimmed, current_line, PHALCON_TRIM_RIGHT TSRMLS_CC);
	
						PHALCON_INIT_NVAR(is_comment);
	
						#if HAVE_BUNDLED_PCRE
						phalcon_preg_match(is_comment, comment_pattern, current_line, NULL TSRMLS_CC);
						#else
						phalcon_call_func_p2(is_comment, "preg_match", comment_pattern, current_line);
						#endif
	
						if (zend_is_true(is_comment)) {
							PHALCON_INIT_NVAR(spaced_current_line);
							phalcon_fast_str_replace(spaced_current_line, comment, space, current_line);
							PHALCON_CPY_WRT(current_line, spaced_current_line);
						}
					}
				}
	
				/** 
				 * Print a non break space if the current line is a line break, this allows to show
				 * the html zebra properly
				 */
				if (PHALCON_IS_STRING(current_line, "\n")) {
					phalcon_concat_self_str(&html, SL("&nbsp;\n") TSRMLS_CC);
				} else {
					if (PHALCON_IS_STRING(current_line, "\r\n")) {
						phalcon_concat_self_str(&html, SL("&nbsp;\n") TSRMLS_CC);
					} else {
						PHALCON_INIT_NVAR(spaced_current_line);
						phalcon_fast_str_replace(spaced_current_line, tab, two_spaces, current_line);
	
						PHALCON_INIT_NVAR(escaped_line);
						phalcon_call_func_p3(escaped_line, "htmlentities", spaced_current_line, ent_compat, utf8);
						phalcon_concat_self(&html, escaped_line TSRMLS_CC);
					}
				}
	
				PHALCON_SEPARATE(i);
				phalcon_increment(i);
			}
			phalcon_concat_self_str(&html, SL("</pre>") TSRMLS_CC);
		}
	}
	
	phalcon_concat_self_str(&html, SL("</td></tr>") TSRMLS_CC);
	
	RETURN_CTOR(html);
}

/**
 * Handles uncaught exceptions
 *
 * @param \Exception $exception
 * @return boolean
 */
PHP_METHOD(Phalcon_Debug, onUncaughtException){

	zval *exception, *is_active = NULL, *message = NULL;
	zval *class_name, *css_sources, *escaped_message = NULL;
	zval *html, *version, *file, *line, *show_back_trace;
	zval *data_vars, *trace, *trace_item = NULL, *n = NULL, *html_item = NULL;
	zval *_REQUEST, *value = NULL, *key_request = NULL, *_SERVER;
	zval *key_server = NULL, *files, *key_file = NULL;
	zval *memory, *data_var = NULL, *key_var = NULL, *variable = NULL, *dumped_argument = NULL;
	zval *js_sources;
	HashTable *ah0, *ah1, *ah2, *ah3, *ah4;
	HashPosition hp0, hp1, hp2, hp3, hp4;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &exception);
	
	/** 
	 * Cancel the output buffer if active
	 */
	if (phalcon_ob_get_level(TSRMLS_C) > 0) {
		phalcon_ob_end_clean(TSRMLS_C);
	}
	
	PHALCON_OBS_VAR(is_active);
	phalcon_read_static_property(&is_active, SL("phalcon\\debug"), SL("_isActive") TSRMLS_CC);
	
	/** 
	 * Avoid that multiple exceptions being showed
	 */
	if (zend_is_true(is_active)) {
		PHALCON_INIT_VAR(message);
		phalcon_call_method(message, exception, "getmessage");
		zend_print_zval(message, 0);
	}
	
	PHALCON_INIT_NVAR(is_active);
	ZVAL_BOOL(is_active, 1);
	
	/** 
	 * Globally block the debug component to avoid other exceptions must be shown
	 */
	phalcon_update_static_property(SL("phalcon\\debug"), SL("_isActive"), is_active TSRMLS_CC);
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, exception, 0 TSRMLS_CC);
	
	PHALCON_INIT_NVAR(message);
	phalcon_call_method(message, exception, "getmessage");
	
	/** 
	 * CSS static sources to style the error presentation
	 */
	PHALCON_INIT_VAR(css_sources);
	phalcon_call_method(css_sources, this_ptr, "getcsssources");
	
	/** 
	 * Escape the exception's message avoiding possible XSS injections?
	 */
	PHALCON_CPY_WRT(escaped_message, message);
	
	/** 
	 * Use the exception info as document's title
	 */
	PHALCON_INIT_VAR(html);
	PHALCON_CONCAT_SVSVS(html, "<html><head><title>", class_name, ": ", escaped_message, "</title>");
	PHALCON_SCONCAT_VS(html, css_sources, "</head><body>");
	
	/** 
	 * Get the version link
	 */
	PHALCON_INIT_VAR(version);
	phalcon_call_method(version, this_ptr, "getversion");
	phalcon_concat_self(&html, version TSRMLS_CC);
	
	PHALCON_INIT_VAR(file);
	phalcon_call_method(file, exception, "getfile");
	
	PHALCON_INIT_VAR(line);
	phalcon_call_method(line, exception, "getline");
	
	/** 
	 * Main exception info
	 */
	phalcon_concat_self_str(&html, SL("<div align=\"center\"><div class=\"error-main\">") TSRMLS_CC);
	PHALCON_SCONCAT_SVSVS(html, "<h1>", class_name, ": ", escaped_message, "</h1>");
	PHALCON_SCONCAT_SVSVS(html, "<span class=\"error-file\">", file, " (", line, ")</span>");
	phalcon_concat_self_str(&html, SL("</div>") TSRMLS_CC);
	
	PHALCON_OBS_VAR(show_back_trace);
	phalcon_read_property_this(&show_back_trace, this_ptr, SL("_showBackTrace"), PH_NOISY_CC);
	
	/** 
	 * Check if the developer wants to show the backtrace or not
	 */
	if (zend_is_true(show_back_trace)) {
	
		PHALCON_OBS_VAR(data_vars);
		phalcon_read_property_this(&data_vars, this_ptr, SL("_data"), PH_NOISY_CC);
	
		/** 
		 * Create the tabs in the page
		 */
		phalcon_concat_self_str(&html, SL("<div class=\"error-info\"><div id=\"tabs\"><ul>") TSRMLS_CC);
		phalcon_concat_self_str(&html, SL("<li><a href=\"#error-tabs-1\">Backtrace</a></li>") TSRMLS_CC);
		phalcon_concat_self_str(&html, SL("<li><a href=\"#error-tabs-2\">Request</a></li>") TSRMLS_CC);
		phalcon_concat_self_str(&html, SL("<li><a href=\"#error-tabs-3\">Server</a></li>") TSRMLS_CC);
		phalcon_concat_self_str(&html, SL("<li><a href=\"#error-tabs-4\">Included Files</a></li>") TSRMLS_CC);
		phalcon_concat_self_str(&html, SL("<li><a href=\"#error-tabs-5\">Memory</a></li>") TSRMLS_CC);
		if (Z_TYPE_P(data_vars) == IS_ARRAY) { 
			phalcon_concat_self_str(&html, SL("<li><a href=\"#error-tabs-6\">Variables</a></li>") TSRMLS_CC);
		}
	
		phalcon_concat_self_str(&html, SL("</ul>") TSRMLS_CC);
	
		/** 
		 * Print backtrace
		 */
		phalcon_concat_self_str(&html, SL("<div id=\"error-tabs-1\"><table cellspacing=\"0\" align=\"center\" width=\"100%\">") TSRMLS_CC);
	
		PHALCON_INIT_VAR(trace);
		phalcon_call_method(trace, exception, "gettrace");
	
		phalcon_is_iterable(trace, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HKEY(n, ah0, hp0);
			PHALCON_GET_HVALUE(trace_item);
	
			/** 
			 * Every line in the trace is rendered using 'showTraceItem'
			 */
			PHALCON_INIT_NVAR(html_item);
			phalcon_call_method_p2(html_item, this_ptr, "showtraceitem", n, trace_item);
			phalcon_concat_self(&html, html_item TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		phalcon_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
	
		/** 
		 * Print _REQUEST superglobal
		 */
		phalcon_concat_self_str(&html, SL("<div id=\"error-tabs-2\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		phalcon_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
		phalcon_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	
		phalcon_is_iterable(_REQUEST, &ah1, &hp1, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_HKEY(key_request, ah1, hp1);
			PHALCON_GET_HVALUE(value);
	
			PHALCON_SCONCAT_SVSVS(html, "<tr><td class=\"key\">", key_request, "</td><td>", value, "</td></tr>");
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
	
		phalcon_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
	
		/** 
		 * Print _SERVER superglobal
		 */
		phalcon_concat_self_str(&html, SL("<div id=\"error-tabs-3\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		phalcon_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
		phalcon_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	
		phalcon_is_iterable(_SERVER, &ah2, &hp2, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
			PHALCON_GET_HKEY(key_server, ah2, hp2);
			PHALCON_GET_HVALUE(value);
	
			PHALCON_SCONCAT_SVSVS(html, "<tr><td class=\"key\">", key_server, "</td><td>", value, "</td></tr>");
	
			zend_hash_move_forward_ex(ah2, &hp2);
		}
	
		phalcon_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
	
		/** 
		 * Show included files
		 */
		PHALCON_INIT_VAR(files);
		phalcon_call_func(files, "get_included_files");
		phalcon_concat_self_str(&html, SL("<div id=\"error-tabs-4\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		phalcon_concat_self_str(&html, SL("<tr><th>#</th><th>Path</th></tr>") TSRMLS_CC);
	
		phalcon_is_iterable(files, &ah3, &hp3, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah3, (void**) &hd, &hp3) == SUCCESS) {
	
			PHALCON_GET_HKEY(key_file, ah3, hp3);
			PHALCON_GET_HVALUE(value);
	
			PHALCON_SCONCAT_SVSVS(html, "<tr><td>", key_file, "</th><td>", value, "</td></tr>");
	
			zend_hash_move_forward_ex(ah3, &hp3);
		}
	
		phalcon_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
	
		/** 
		 * Memory usage
		 */
		PHALCON_INIT_VAR(memory);
		ZVAL_LONG(memory, zend_memory_usage(1 TSRMLS_CC));
		phalcon_concat_self_str(&html, SL("<div id=\"error-tabs-5\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		PHALCON_SCONCAT_SVS(html, "<tr><th colspan=\"2\">Memory</th></tr><tr><td>Usage</td><td>", memory, "</td></tr>");
		phalcon_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
	
		/** 
		 * Print extra variables passed to the component
		 */
		if (Z_TYPE_P(data_vars) == IS_ARRAY) { 
			phalcon_concat_self_str(&html, SL("<div id=\"error-tabs-6\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
			phalcon_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
	
			phalcon_is_iterable(data_vars, &ah4, &hp4, 0, 0);
	
			while (zend_hash_get_current_data_ex(ah4, (void**) &hd, &hp4) == SUCCESS) {
	
				PHALCON_GET_HKEY(key_var, ah4, hp4);
				PHALCON_GET_HVALUE(data_var);
	
				PHALCON_OBS_NVAR(variable);
				phalcon_array_fetch_long(&variable, data_var, 0, PH_NOISY);
	
				PHALCON_INIT_NVAR(dumped_argument);
				phalcon_call_method_p1(dumped_argument, this_ptr, "_getvardump", variable);
				PHALCON_SCONCAT_SVSVS(html, "<tr><td class=\"key\">", key_var, "</td><td>", dumped_argument, "</td></tr>");
	
				zend_hash_move_forward_ex(ah4, &hp4);
			}
	
			phalcon_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		}
	
		phalcon_concat_self_str(&html, SL("</div>") TSRMLS_CC);
	}
	
	/** 
	 * Get Javascript sources
	 */
	PHALCON_INIT_VAR(js_sources);
	phalcon_call_method(js_sources, this_ptr, "getjssources");
	PHALCON_SCONCAT_VS(html, js_sources, "</div></body></html>");
	
	/** 
	 * Print the HTML, @TODO, add an option to store the html
	 */
	zend_print_zval(html, 0);
	
	PHALCON_INIT_NVAR(is_active);
	ZVAL_BOOL(is_active, 0);
	
	/** 
	 * Unlock the exception renderer
	 */
	phalcon_update_static_property(SL("phalcon\\debug"), SL("_isActive"), is_active TSRMLS_CC);
	RETURN_MM_TRUE;
}

