
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/concat.h"


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
/**
 * Phalcon\Debug
 *
 * Provides debug capabilities to Phalcon applications
 */
ZEPHIR_INIT_CLASS(Phalcon_Debug) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Debug, phalcon, debug, phalcon_debug_method_entry, 0);

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
 * @param string uri
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, setUri) {

	zval *uri;

	zephir_fetch_params(0, 1, 0, &uri);



	zephir_update_property_this(this_ptr, SL("_uri"), uri TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets if files the exception"s backtrace must be showed
 *
 * @param boolean showBackTrace
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, setShowBackTrace) {

	zval *showBackTrace_param = NULL;
	zend_bool showBackTrace;

	zephir_fetch_params(0, 1, 0, &showBackTrace_param);

	showBackTrace = zephir_get_boolval(showBackTrace_param);


	zephir_update_property_this(this_ptr, SL("_showBackTrace"), showBackTrace ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Set if files part of the backtrace must be shown in the output
 *
 * @param boolean showFiles
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, setShowFiles) {

	zval *showFiles_param = NULL;
	zend_bool showFiles;

	zephir_fetch_params(0, 1, 0, &showFiles_param);

	showFiles = zephir_get_boolval(showFiles_param);


	zephir_update_property_this(this_ptr, SL("_showFiles"), showFiles ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets if files must be completely opened and showed in the output
 * or just the fragment related to the exception
 *
 * @param boolean showFileFragment
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, setShowFileFragment) {

	zval *showFileFragment;

	zephir_fetch_params(0, 1, 0, &showFileFragment);



	zephir_update_property_this(this_ptr, SL("_showFileFragment"), showFileFragment TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Listen for uncaught exceptions and unsilent notices or warnings
 *
 * @param boolean exceptions
 * @param boolean lowSeverity
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, listen) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptions = NULL, *lowSeverity = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &exceptions, &lowSeverity);

	if (!exceptions) {
		exceptions = ZEPHIR_GLOBAL(global_true);
	}
	if (!lowSeverity) {
		lowSeverity = ZEPHIR_GLOBAL(global_false);
	}


	if (zephir_is_true(exceptions)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "listenexceptions", NULL);
		zephir_check_call_status();
	}
	if (zephir_is_true(lowSeverity)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "listenlowseverity", NULL);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Listen for uncaught exceptions
 *
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, listenExceptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_1;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "onUncaughtException", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", &_2, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Listen for unsilent notices or warnings
 *
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, listenLowSeverity) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_1;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "onUncaughtLowSeverity", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", &_2, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Adds a variable to the debug output
 *
 * @param mixed var
 * @param string key
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, debugVar) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0;
	zval *varz, *key = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &varz, &key);

	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 5);
	zephir_array_fast_append(_0, varz);
	ZEPHIR_CALL_FUNCTION(&_1, "debug_backtrace", &_2);
	zephir_check_call_status();
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(&_1, "time", NULL);
	zephir_check_call_status();
	zephir_array_fast_append(_0, _1);
	zephir_update_property_array_append(this_ptr, SL("_data"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Clears are variables added previously
 *
 * @return Phalcon\Debug
 */
PHP_METHOD(Phalcon_Debug, clearVars) {


	zephir_update_property_this(this_ptr, SL("_data"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Escapes a string with htmlentities
 *
 * @param string value
 * @return string
 */
PHP_METHOD(Phalcon_Debug, _escapeString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	zval *value, *_0, _1, _2, _3, _4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_STRING) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "\n", 0);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "\\n", 0);
		zephir_fast_str_replace(_0, &_1, &_2, value);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_LONG(&_3, 2);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "utf-8", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("htmlentities", &_5, _0, &_3, &_4);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * Produces a recursive representation of an array
 *
 * @param array argument
 * @return string
 */
PHP_METHOD(Phalcon_Debug, _getArrayDump) {

	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *argument, *n = NULL, *numberArguments, *dump, *varDump = NULL, *k = NULL, *v = NULL, **_2, *_3 = NULL, *_5 = NULL, *_7 = NULL, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &argument, &n);

	if (!n) {
		ZEPHIR_INIT_VAR(n);
		ZVAL_LONG(n, 0);
	}


	ZEPHIR_INIT_VAR(numberArguments);
	ZVAL_LONG(numberArguments, zephir_fast_count_int(argument TSRMLS_CC));
	if (ZEPHIR_LT_LONG(n, 3)) {
		if (ZEPHIR_GT_LONG(numberArguments, 0)) {
			if (ZEPHIR_LT_LONG(numberArguments, 10)) {
				ZEPHIR_INIT_VAR(dump);
				array_init(dump);
				zephir_is_iterable(argument, &_1, &_0, 0, 0, "phalcon/debug.zep", 217);
				for (
				  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
				  ; zephir_hash_move_forward_ex(_1, &_0)
				) {
					ZEPHIR_GET_HMKEY(k, _1, _0);
					ZEPHIR_GET_HVALUE(v, _2);
					ZEPHIR_CALL_FUNCTION(&_3, "is_scalar", &_4, v);
					zephir_check_call_status();
					if (zephir_is_true(_3)) {
						ZEPHIR_INIT_NVAR(varDump);
						if (ZEPHIR_IS_STRING(v, "")) {
							ZEPHIR_CONCAT_SVS(varDump, "[", k, "] =&gt; (empty string)");
						} else {
							ZEPHIR_CALL_METHOD(&_5, this_ptr, "_escapestring", &_6, v);
							zephir_check_call_status();
							ZEPHIR_CONCAT_SVSV(varDump, "[", k, "] =&gt; ", _5);
						}
						zephir_array_append(&dump, varDump, PH_SEPARATE, "phalcon/debug.zep", 195);
					} else {
						if (Z_TYPE_P(v) == IS_ARRAY) {
							ZEPHIR_INIT_NVAR(_7);
							ZVAL_LONG(_7, (zephir_get_numberval(n) + 1));
							ZEPHIR_CALL_METHOD(&_5, this_ptr, "_getarraydump", &_8, v, _7);
							zephir_check_call_status();
							ZEPHIR_INIT_LNVAR(_9);
							ZEPHIR_CONCAT_SVSVS(_9, "[", k, "] =&gt; Array(", _5, ")");
							zephir_array_append(&dump, _9, PH_SEPARATE, "phalcon/debug.zep", 199);
							continue;
						}
						if (Z_TYPE_P(v) == IS_OBJECT) {
							ZEPHIR_INIT_NVAR(_7);
							zephir_get_class(_7, v, 0 TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_9);
							ZEPHIR_CONCAT_SVSVS(_9, "[", k, "] =&gt; Object(", _7, ")");
							zephir_array_append(&dump, _9, PH_SEPARATE, "phalcon/debug.zep", 204);
							continue;
						}
						if (Z_TYPE_P(v) == IS_NULL) {
							ZEPHIR_INIT_LNVAR(_9);
							ZEPHIR_CONCAT_SVS(_9, "[", k, "] =&gt; null");
							zephir_array_append(&dump, _9, PH_SEPARATE, "phalcon/debug.zep", 209);
							continue;
						}
						ZEPHIR_INIT_LNVAR(_9);
						ZEPHIR_CONCAT_SVSV(_9, "[", k, "] =&gt; ", v);
						zephir_array_append(&dump, _9, PH_SEPARATE, "phalcon/debug.zep", 213);
					}
				}
				zephir_fast_join_str(return_value, SL(", "), dump TSRMLS_CC);
				RETURN_MM();
			}
			RETURN_CCTOR(numberArguments);
		}
	}
	RETURN_MM_NULL();

}

/**
 * Produces an string representation of a variable
 *
 * @param mixed variable
 * @return string
 */
PHP_METHOD(Phalcon_Debug, _getVarDump) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *variable, *className, *dumpedObject = NULL, *dump, *_0 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &variable);



	ZEPHIR_CALL_FUNCTION(&_0, "is_scalar", &_1, variable);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		if (Z_TYPE_P(variable) == IS_BOOL) {
			if (zephir_is_true(variable)) {
				RETURN_MM_STRING("true", 1);
			} else {
				RETURN_MM_STRING("false", 1);
			}
		}
		if (Z_TYPE_P(variable) == IS_STRING) {
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_escapestring", NULL, variable);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETVAL_ZVAL(variable, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(className);
		zephir_get_class(className, variable, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(dump);
		if ((zephir_method_exists_ex(variable, SS("dump") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&dumpedObject, variable, "dump",  NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_2, this_ptr, "_getarraydump", NULL, dumpedObject);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVSVS(dump, "Object(", className, ": ", _2, ")");
		} else {
			ZEPHIR_CONCAT_SVS(dump, "Object(", className, ")</span>");
		}
		RETURN_CCTOR(dump);
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "_getarraydump", NULL, variable);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "Array(", _2, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		RETURN_MM_STRING("null", 1);
	}
	zephir_gettype(return_value, variable TSRMLS_CC);
	RETURN_MM();

}

/**
 * Returns the major framework"s version
 *
 * @return string
 */
PHP_METHOD(Phalcon_Debug, getMajorVersion) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *parts, *_0 = NULL, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(parts);
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_version_ce, "get", &_1);
	zephir_check_call_status();
	zephir_fast_explode_str(parts, SL(" "), _0, LONG_MAX TSRMLS_CC);
	zephir_array_fetch_long(&_2, parts, 0, PH_NOISY | PH_READONLY, "phalcon/debug.zep", 317 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * Generates a link to the current version documentation
 *
 * @return string
 */
PHP_METHOD(Phalcon_Debug, getVersion) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmajorversion",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_version_ce, "get", &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "<div class=\"version\">Phalcon Framework <a target=\"_new\" href=\"http://docs.phalconphp.com/en/", _0, "/\">", _1, "</a></div>");
	RETURN_MM();

}

/**
 * Returns the css sources
 *
 * @return string
 */
PHP_METHOD(Phalcon_Debug, getCssSources) {

	zval *uri, *sources, *_0;

	ZEPHIR_MM_GROW();

	uri = zephir_fetch_nproperty_this(this_ptr, SL("_uri"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(sources);
	ZEPHIR_CONCAT_SVS(sources, "<link href=\"", uri, "jquery/jquery-ui.css\" type=\"text/css\" rel=\"stylesheet\" />");
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "<link href=\"", uri, "themes/default/style.css\" type=\"text/css\" rel=\"stylesheet\" />");
	zephir_concat_self(&sources, _0 TSRMLS_CC);
	RETURN_CCTOR(sources);

}

/**
 * Returns the javascript sources
 *
 * @return string
 */
PHP_METHOD(Phalcon_Debug, getJsSources) {

	zval *uri, *sources, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	uri = zephir_fetch_nproperty_this(this_ptr, SL("_uri"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(sources);
	ZEPHIR_CONCAT_SVS(sources, "<script type=\"text/javascript\" src=\"", uri, "jquery/jquery.js\"></script>");
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "<script type=\"text/javascript\" src=\"", uri, "jquery/jquery-ui.js\"></script>");
	zephir_concat_self(&sources, _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "<script type=\"text/javascript\" src=\"", uri, "jquery/jquery.scrollTo.js\"></script>");
	zephir_concat_self(&sources, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVS(_2, "<script type=\"text/javascript\" src=\"", uri, "prettify/prettify.js\"></script>");
	zephir_concat_self(&sources, _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, "<script type=\"text/javascript\" src=\"", uri, "pretty.js\"></script>");
	zephir_concat_self(&sources, _3 TSRMLS_CC);
	RETURN_CCTOR(sources);

}

/**
 * Shows a backtrace item
 *
 * @param int n
 * @param array trace
 */
PHP_METHOD(Phalcon_Debug, showTraceItem) {

	zephir_fcall_cache_entry *_12 = NULL;
	HashTable *_10;
	HashPosition _9;
	zend_class_entry *_4, *_8;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_13 = NULL, *_18 = NULL;
	int firstLine, i, ZEPHIR_LAST_CALL_STATUS;
	zval *n, *trace, *space, *twoSpaces, *underscore, *minus, *className, *namespaceSeparator, *prepareInternalClass, *preparedFunctionName, *html, *classReflection, *prepareUriClass, *functionName, *functionReflection, *traceArgs, *arguments, *argument = NULL, *filez, *line, *showFiles, *lines = NULL, *numberLines, *showFileFragment, *beforeLine, *afterLine, *lastLine = NULL, *commentPattern, *utf8, *entCompat, *tab, *comment, linePosition = zval_used_for_init, *currentLine = NULL, *_0 = NULL, *_1 = NULL, *_3 = NULL, *_5 = NULL, *_6 = NULL, *_7, **_11, _14 = zval_used_for_init, _15, *_16, *_17 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &n, &trace);



	ZEPHIR_INIT_VAR(space);
	ZVAL_STRING(space, " ", 1);
	ZEPHIR_INIT_VAR(twoSpaces);
	ZVAL_STRING(twoSpaces, "  ", 1);
	ZEPHIR_INIT_VAR(underscore);
	ZVAL_STRING(underscore, "_", 1);
	ZEPHIR_INIT_VAR(minus);
	ZVAL_STRING(minus, "-", 1);
	ZEPHIR_INIT_VAR(html);
	ZEPHIR_CONCAT_SVS(html, "<tr><td align=\"right\" valign=\"top\" class=\"error-number\">#", n, "</td><td>");
	if (zephir_array_isset_string(trace, SS("class"))) {
		ZEPHIR_OBS_VAR(className);
		zephir_array_fetch_string(&className, trace, SL("class"), PH_NOISY, "phalcon/debug.zep", 393 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "/^Phalcon/", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "preg_match", &_2, _0, className);
		zephir_check_temp_parameter(_0);
		zephir_check_call_status();
		if (zephir_is_true(_1)) {
			ZEPHIR_INIT_VAR(namespaceSeparator);
			ZVAL_STRING(namespaceSeparator, "\\", 1);
			ZEPHIR_INIT_VAR(prepareUriClass);
			zephir_fast_str_replace(prepareUriClass, namespaceSeparator, underscore, className);
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_CONCAT_SVSVS(_3, "<span class=\"error-class\"><a target=\"_new\" href=\"http://docs.phalconphp.com/en/latest/api/", prepareUriClass, ".html\">", className, "</a></span>");
			zephir_concat_self(&html, _3 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(classReflection);
			_4 = zend_fetch_class(SL("ReflectionClass"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(classReflection, _4);
			ZEPHIR_CALL_METHOD(NULL, classReflection, "__construct", NULL, className);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5, classReflection, "isinternal",  NULL);
			zephir_check_call_status();
			if (zephir_is_true(_5)) {
				ZEPHIR_INIT_VAR(prepareInternalClass);
				ZEPHIR_INIT_NVAR(_0);
				zephir_fast_strtolower(_0, className);
				zephir_fast_str_replace(prepareInternalClass, underscore, minus, _0);
				ZEPHIR_INIT_LNVAR(_3);
				ZEPHIR_CONCAT_SVSVS(_3, "<span class=\"error-class\"><a target=\"_new\" href=\"http://php.net/manual/en/class.", prepareInternalClass, ".php\">", className, "</a></span>");
				zephir_concat_self(&html, _3 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(_6);
				ZEPHIR_CONCAT_SVS(_6, "<span class=\"error-class\">", className, "</span>");
				zephir_concat_self(&html, _6 TSRMLS_CC);
			}
		}
		zephir_array_fetch_string(&_7, trace, SL("type"), PH_NOISY | PH_READONLY, "phalcon/debug.zep", 434 TSRMLS_CC);
		zephir_concat_self(&html, _7 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(functionName);
	zephir_array_fetch_string(&functionName, trace, SL("function"), PH_NOISY, "phalcon/debug.zep", 440 TSRMLS_CC);
	if (zephir_array_isset_string(trace, SS("class"))) {
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SVS(_3, "<span class=\"error-function\">", functionName, "</span>");
		zephir_concat_self(&html, _3 TSRMLS_CC);
	} else {
		if ((zephir_function_exists(functionName TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_INIT_VAR(functionReflection);
			_8 = zend_fetch_class(SL("ReflectionFunction"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(functionReflection, _8);
			ZEPHIR_CALL_METHOD(NULL, functionReflection, "__construct", NULL, functionName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_1, functionReflection, "isinternal",  NULL);
			zephir_check_call_status();
			if (zephir_is_true(_1)) {
				ZEPHIR_INIT_VAR(preparedFunctionName);
				zephir_fast_str_replace(preparedFunctionName, underscore, minus, functionName);
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SVSVS(_6, "<span class=\"error-function\"><a target=\"_new\" href=\"http://php.net/manual/en/function.", preparedFunctionName, ".php\">", functionName, "</a></span>");
				zephir_concat_self(&html, _6 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SVS(_6, "<span class=\"error-function\">", functionName, "</span>");
				zephir_concat_self(&html, _6 TSRMLS_CC);
			}
		} else {
			ZEPHIR_INIT_LNVAR(_3);
			ZEPHIR_CONCAT_SVS(_3, "<span class=\"error-function\">", functionName, "</span>");
			zephir_concat_self(&html, _3 TSRMLS_CC);
		}
	}
	if (zephir_array_isset_string(trace, SS("args"))) {
		ZEPHIR_OBS_VAR(traceArgs);
		zephir_array_fetch_string(&traceArgs, trace, SL("args"), PH_NOISY, "phalcon/debug.zep", 474 TSRMLS_CC);
		if (zephir_fast_count_int(traceArgs TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(arguments);
			array_init(arguments);
			zephir_is_iterable(traceArgs, &_10, &_9, 0, 0, "phalcon/debug.zep", 489);
			for (
			  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
			  ; zephir_hash_move_forward_ex(_10, &_9)
			) {
				ZEPHIR_GET_HVALUE(argument, _11);
				ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getvardump", &_12, argument);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_3);
				ZEPHIR_CONCAT_SVS(_3, "<span class=\"error-parameter\">", _1, "</span>");
				zephir_array_append(&arguments, _3, PH_SEPARATE, "phalcon/debug.zep", 483);
			}
			ZEPHIR_INIT_NVAR(_0);
			zephir_fast_join_str(_0, SL(", "), arguments TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_6);
			ZEPHIR_CONCAT_SVS(_6, "(", _0, ")");
			zephir_concat_self(&html, _6 TSRMLS_CC);
		} else {
			zephir_concat_self_str(&html, SL("()") TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(filez);
	if (zephir_array_isset_string_fetch(&filez, trace, SS("file"), 0 TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(line);
		zephir_array_fetch_string(&line, trace, SL("line"), PH_NOISY, "phalcon/debug.zep", 500 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SVSVS(_3, "<br/><div class=\"error-file\">", filez, " (", line, ")</div>");
		zephir_concat_self(&html, _3 TSRMLS_CC);
		ZEPHIR_OBS_VAR(showFiles);
		zephir_read_property_this(&showFiles, this_ptr, SL("_showFiles"), PH_NOISY_CC);
		if (zephir_is_true(showFiles)) {
			ZEPHIR_CALL_FUNCTION(&lines, "file", &_13, filez);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(numberLines);
			ZVAL_LONG(numberLines, zephir_fast_count_int(lines TSRMLS_CC));
			ZEPHIR_OBS_VAR(showFileFragment);
			zephir_read_property_this(&showFileFragment, this_ptr, SL("_showFileFragment"), PH_NOISY_CC);
			if (zephir_is_true(showFileFragment)) {
				ZEPHIR_INIT_VAR(beforeLine);
				ZVAL_LONG(beforeLine, (zephir_get_numberval(line) - 7));
				if (ZEPHIR_LT_LONG(beforeLine, 1)) {
					firstLine = 1;
				} else {
					firstLine = zephir_get_numberval(beforeLine);
				}
				ZEPHIR_INIT_VAR(afterLine);
				ZVAL_LONG(afterLine, (zephir_get_numberval(line) + 5));
				if (ZEPHIR_GT(afterLine, numberLines)) {
					ZEPHIR_CPY_WRT(lastLine, numberLines);
				} else {
					ZEPHIR_CPY_WRT(lastLine, afterLine);
				}
				ZEPHIR_SINIT_VAR(_14);
				ZVAL_LONG(&_14, firstLine);
				ZEPHIR_SINIT_VAR(_15);
				ZVAL_LONG(&_15, firstLine);
				ZEPHIR_INIT_VAR(_16);
				ZEPHIR_CONCAT_SVSVSVS(_16, "<pre class=\"prettyprint highlight:", &_14, ":", line, " linenums:", &_15, "\">");
				zephir_concat_self(&html, _16 TSRMLS_CC);
			} else {
				firstLine = 1;
				ZEPHIR_CPY_WRT(lastLine, numberLines);
				ZEPHIR_SINIT_NVAR(_14);
				ZVAL_LONG(&_14, firstLine);
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SVSVS(_6, "<pre class=\"prettyprint highlight:", &_14, ":", line, " linenums error-scroll\">");
				zephir_concat_self(&html, _6 TSRMLS_CC);
			}
			ZEPHIR_INIT_VAR(commentPattern);
			ZVAL_STRING(commentPattern, "#\\*\\/#", 1);
			ZEPHIR_INIT_VAR(utf8);
			ZVAL_STRING(utf8, "UTF-8", 1);
			ZEPHIR_INIT_VAR(entCompat);
			ZVAL_LONG(entCompat, 2);
			ZEPHIR_INIT_VAR(tab);
			ZVAL_STRING(tab, "\t", 1);
			ZEPHIR_INIT_VAR(comment);
			ZVAL_STRING(comment, "* /", 1);
			i = firstLine;
			while (1) {
				if (!(ZEPHIR_GE_LONG(lastLine, i))) {
					break;
				}
				ZEPHIR_SINIT_NVAR(linePosition);
				ZVAL_LONG(&linePosition, (i - 1));
				ZEPHIR_OBS_NVAR(currentLine);
				zephir_array_fetch(&currentLine, lines, &linePosition, PH_NOISY, "phalcon/debug.zep", 588 TSRMLS_CC);
				if (zephir_is_true(showFileFragment)) {
					if (i == firstLine) {
						ZEPHIR_INIT_NVAR(_0);
						zephir_fast_trim(_0, currentLine, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
						ZEPHIR_CALL_FUNCTION(&_1, "preg_match", &_2, commentPattern, _0);
						zephir_check_call_status();
						if (zephir_is_true(_1)) {
							ZEPHIR_INIT_NVAR(_17);
							zephir_fast_str_replace(_17, comment, space, currentLine);
							ZEPHIR_CPY_WRT(currentLine, _17);
						}
					}
				}
				if (ZEPHIR_IS_STRING(currentLine, "\n")) {
					zephir_concat_self_str(&html, SL("&nbsp;\n") TSRMLS_CC);
				} else {
					if (ZEPHIR_IS_STRING(currentLine, "\r\n")) {
						zephir_concat_self_str(&html, SL("&nbsp;\n") TSRMLS_CC);
					} else {
						ZEPHIR_INIT_NVAR(_17);
						zephir_fast_str_replace(_17, tab, twoSpaces, currentLine);
						ZEPHIR_CALL_FUNCTION(&_5, "htmlentities", &_18, _17, entCompat, utf8);
						zephir_check_call_status();
						zephir_concat_self(&html, _5 TSRMLS_CC);
					}
				}
				i++;
			}
			zephir_concat_self_str(&html, SL("</pre>") TSRMLS_CC);
		}
	}
	zephir_concat_self_str(&html, SL("</td></tr>") TSRMLS_CC);
	RETURN_CCTOR(html);

}

/**
 * Handles uncaught exceptions
 *
 * @param \Exception exception
 * @return boolean
 */
PHP_METHOD(Phalcon_Debug, onUncaughtException) {

	zephir_fcall_cache_entry *_15 = NULL, *_33 = NULL;
	HashTable *_12, *_17, *_21, *_25, *_29;
	HashPosition _11, _16, _20, _24, _28;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL, *_23 = NULL, *_27 = NULL;
	zval *exception, *obLevel = NULL, *className, *escapedMessage = NULL, *html, *showBackTrace, *dataVars, *n = NULL, *traceItem = NULL, *keyRequest = NULL, *value = NULL, *keyServer = NULL, *keyFile = NULL, *keyVar = NULL, *dataVar = NULL, *_2, *_3 = NULL, *_4, *_5 = NULL, *_6, *_7 = NULL, *_8 = NULL, *_9, *_10 = NULL, **_13, *_14 = NULL, *_REQUEST, **_18, *_19 = NULL, *_SERVER, **_22, **_26, **_30, *_31 = NULL, *_32, *_34 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &exception);



	ZEPHIR_CALL_FUNCTION(&obLevel, "ob_get_level", &_0);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(obLevel, 0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", &_1);
		zephir_check_call_status();
	}
	_2 = zephir_fetch_static_property_ce(phalcon_debug_ce, SL("_isActive") TSRMLS_CC);
	if (zephir_is_true(_2)) {
		ZEPHIR_CALL_METHOD(&_3, exception, "getmessage",  NULL);
		zephir_check_call_status();
		zend_print_zval(_3, 0);
		RETURN_MM_NULL();
	}
	zephir_update_static_property_ce(phalcon_debug_ce, SL("_isActive"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, exception, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&escapedMessage, exception, "getmessage",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(html);
	ZEPHIR_CONCAT_SVSVS(html, "<html><head><title>", className, ": ", escapedMessage, "</title>");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getcsssources",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VS(_4, _3, "</head><body>");
	zephir_concat_self(&html, _4 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getversion",  NULL);
	zephir_check_call_status();
	zephir_concat_self(&html, _5 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("<div align=\"center\"><div class=\"error-main\">") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SVSVS(_6, "<h1>", className, ": ", escapedMessage, "</h1>");
	zephir_concat_self(&html, _6 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_7, exception, "getfile",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, exception, "getline",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_CONCAT_SVSVS(_9, "<span class=\"error-file\">", _7, " (", _8, ")</span>");
	zephir_concat_self(&html, _9 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("</div>") TSRMLS_CC);
	ZEPHIR_OBS_VAR(showBackTrace);
	zephir_read_property_this(&showBackTrace, this_ptr, SL("_showBackTrace"), PH_NOISY_CC);
	if (zephir_is_true(showBackTrace)) {
		ZEPHIR_OBS_VAR(dataVars);
		zephir_read_property_this(&dataVars, this_ptr, SL("_data"), PH_NOISY_CC);
		zephir_concat_self_str(&html, SL("<div class=\"error-info\"><div id=\"tabs\"><ul>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-1\">Backtrace</a></li>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-2\">Request</a></li>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-3\">Server</a></li>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-4\">Included Files</a></li>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-5\">Memory</a></li>") TSRMLS_CC);
		if (Z_TYPE_P(dataVars) == IS_ARRAY) {
			zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-6\">Variables</a></li>") TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</ul>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-1\"><table cellspacing=\"0\" align=\"center\" width=\"100%\">") TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_10, exception, "gettrace",  NULL);
		zephir_check_call_status();
		zephir_is_iterable(_10, &_12, &_11, 0, 0, "phalcon/debug.zep", 718);
		for (
		  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
		  ; zephir_hash_move_forward_ex(_12, &_11)
		) {
			ZEPHIR_GET_HMKEY(n, _12, _11);
			ZEPHIR_GET_HVALUE(traceItem, _13);
			ZEPHIR_CALL_METHOD(&_14, this_ptr, "showtraceitem", &_15, n, traceItem);
			zephir_check_call_status();
			zephir_concat_self(&html, _14 TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-2\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
		zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
		zephir_is_iterable(_REQUEST, &_17, &_16, 0, 0, "phalcon/debug.zep", 728);
		for (
		  ; zephir_hash_get_current_data_ex(_17, (void**) &_18, &_16) == SUCCESS
		  ; zephir_hash_move_forward_ex(_17, &_16)
		) {
			ZEPHIR_GET_HMKEY(keyRequest, _17, _16);
			ZEPHIR_GET_HVALUE(value, _18);
			ZEPHIR_INIT_LNVAR(_19);
			ZEPHIR_CONCAT_SVSVS(_19, "<tr><td class=\"key\">", keyRequest, "</td><td>", value, "</td></tr>");
			zephir_concat_self(&html, _19 TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-3\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		zephir_is_iterable(_SERVER, &_21, &_20, 0, 0, "phalcon/debug.zep", 738);
		for (
		  ; zephir_hash_get_current_data_ex(_21, (void**) &_22, &_20) == SUCCESS
		  ; zephir_hash_move_forward_ex(_21, &_20)
		) {
			ZEPHIR_GET_HMKEY(keyServer, _21, _20);
			ZEPHIR_GET_HVALUE(value, _22);
			ZEPHIR_INIT_LNVAR(_19);
			ZEPHIR_CONCAT_SVSVS(_19, "<tr><td class=\"key\">", keyServer, "</td><td>", value, "</td></tr>");
			zephir_concat_self(&html, _19 TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-4\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<tr><th>#</th><th>Path</th></tr>") TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_14, "get_included_files", &_23);
		zephir_check_call_status();
		zephir_is_iterable(_14, &_25, &_24, 0, 0, "phalcon/debug.zep", 749);
		for (
		  ; zephir_hash_get_current_data_ex(_25, (void**) &_26, &_24) == SUCCESS
		  ; zephir_hash_move_forward_ex(_25, &_24)
		) {
			ZEPHIR_GET_HMKEY(keyFile, _25, _24);
			ZEPHIR_GET_HVALUE(value, _26);
			ZEPHIR_INIT_LNVAR(_19);
			ZEPHIR_CONCAT_SVSVS(_19, "<tr><td>", keyFile, "</th><td>", value, "</td></tr>");
			zephir_concat_self(&html, _19 TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-5\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_14, "memory_get_usage", &_27, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_19);
		ZEPHIR_CONCAT_SVS(_19, "<tr><th colspan=\"2\">Memory</th></tr><tr><td>Usage</td><td>", _14, "</td></tr>");
		zephir_concat_self(&html, _19 TSRMLS_CC);
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		if (Z_TYPE_P(dataVars) == IS_ARRAY) {
			zephir_concat_self_str(&html, SL("<div id=\"error-tabs-6\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
			zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
			zephir_is_iterable(dataVars, &_29, &_28, 0, 0, "phalcon/debug.zep", 767);
			for (
			  ; zephir_hash_get_current_data_ex(_29, (void**) &_30, &_28) == SUCCESS
			  ; zephir_hash_move_forward_ex(_29, &_28)
			) {
				ZEPHIR_GET_HMKEY(keyVar, _29, _28);
				ZEPHIR_GET_HVALUE(dataVar, _30);
				zephir_array_fetch_long(&_32, dataVar, 0, PH_NOISY | PH_READONLY, "phalcon/debug.zep", 765 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_31, this_ptr, "_getvardump", &_33, _32);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_34);
				ZEPHIR_CONCAT_SVSVS(_34, "<tr><td class=\"key\">", keyVar, "</td><td>", _31, "</td></tr>");
				zephir_concat_self(&html, _34 TSRMLS_CC);
			}
			zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</div>") TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getjssources",  NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_19);
	ZEPHIR_CONCAT_VS(_19, _3, "</div></body></html>");
	zephir_concat_self(&html, _19 TSRMLS_CC);
	zend_print_zval(html, 0);
	zephir_update_static_property_ce(phalcon_debug_ce, SL("_isActive"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

