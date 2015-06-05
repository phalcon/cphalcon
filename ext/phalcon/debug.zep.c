
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/time.h"
#include "kernel/string.h"
#include "kernel/hash.h"
#include "kernel/concat.h"


/**
 * Phalcon\Debug
 *
 * Provides debug capabilities to Phalcon applications
 */
ZEPHIR_INIT_CLASS(Phalcon_Debug) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Debug, phalcon, debug, phalcon_debug_method_entry, 0);

	zend_declare_property_string(phalcon_debug_ce, SL("_uri"), "http://static.phalconphp.com/debug/2.0.0/", ZEND_ACC_PUBLIC TSRMLS_CC);

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
 */
PHP_METHOD(Phalcon_Debug, setUri) {

	zval *uri_param = NULL;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (unlikely(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	}


	zephir_update_property_this(this_ptr, SL("_uri"), uri TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets if files the exception"s backtrace must be showed
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
 */
PHP_METHOD(Phalcon_Debug, setShowFileFragment) {

	zval *showFileFragment_param = NULL;
	zend_bool showFileFragment;

	zephir_fetch_params(0, 1, 0, &showFileFragment_param);

	showFileFragment = zephir_get_boolval(showFileFragment_param);


	zephir_update_property_this(this_ptr, SL("_showFileFragment"), showFileFragment ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Listen for uncaught exceptions and unsilent notices or warnings
 */
PHP_METHOD(Phalcon_Debug, listen) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *exceptions_param = NULL, *lowSeverity_param = NULL;
	zend_bool exceptions, lowSeverity;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &exceptions_param, &lowSeverity_param);

	if (!exceptions_param) {
		exceptions = 1;
	} else {
		exceptions = zephir_get_boolval(exceptions_param);
	}
	if (!lowSeverity_param) {
		lowSeverity = 0;
	} else {
		lowSeverity = zephir_get_boolval(lowSeverity_param);
	}


	if (exceptions) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "listenexceptions", NULL, 0);
		zephir_check_call_status();
	}
	if (lowSeverity) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "listenlowseverity", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Listen for uncaught exceptions
 */
PHP_METHOD(Phalcon_Debug, listenExceptions) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "onUncaughtException", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 115, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Listen for unsilent notices or warnings
 */
PHP_METHOD(Phalcon_Debug, listenLowSeverity) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_1 = NULL;
	zval *_0, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "onUncaughtLowSeverity", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 116, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_2, this_ptr);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "onUncaughtException", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 115, _2);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Halts the request showing a backtrace
 */
PHP_METHOD(Phalcon_Debug, halt) {


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_exception_ce, "Halted request", "phalcon/debug.zep", 120);
	return;

}

/**
 * Adds a variable to the debug output
 */
PHP_METHOD(Phalcon_Debug, debugVar) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *key = NULL;
	zval *varz, *key_param = NULL, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &varz, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	} else {
		zephir_get_strval(key, key_param);
	}


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, varz);
	ZEPHIR_CALL_FUNCTION(&_1, "debug_backtrace", NULL, 117);
	zephir_check_call_status();
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_VAR(_2);
	zephir_time(_2);
	zephir_array_fast_append(_0, _2);
	zephir_update_property_array_append(this_ptr, SL("_data"), _0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Clears are variables added previously
 */
PHP_METHOD(Phalcon_Debug, clearVars) {


	zephir_update_property_this(this_ptr, SL("_data"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Escapes a string with htmlentities
 */
PHP_METHOD(Phalcon_Debug, _escapeString) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0, _1, _2, _3, _4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_STRING) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "\n", 0);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "\\n", 0);
		zephir_fast_str_replace(&_0, &_1, &_2, value TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_LONG(&_3, 2);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "utf-8", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("htmlentities", NULL, 118, _0, &_3, &_4);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * Produces a recursive representation of an array
 */
PHP_METHOD(Phalcon_Debug, _getArrayDump) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_9 = NULL;
	HashTable *_2;
	HashPosition _1;
	zend_bool _0;
	zval *argument_param = NULL, *n = NULL, *numberArguments, *dump, *varDump = NULL, *k = NULL, *v = NULL, **_3, *_4 = NULL, *_6 = NULL, *_8 = NULL, *_10 = NULL;
	zval *argument = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &argument_param, &n);

	argument = argument_param;

	if (!n) {
		ZEPHIR_INIT_VAR(n);
		ZVAL_LONG(n, 0);
	}


	ZEPHIR_INIT_VAR(numberArguments);
	ZVAL_LONG(numberArguments, zephir_fast_count_int(argument TSRMLS_CC));
	_0 = ZEPHIR_GE_LONG(n, 3);
	if (!(_0)) {
		_0 = ZEPHIR_IS_LONG(numberArguments, 0);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	if (ZEPHIR_GE_LONG(numberArguments, 10)) {
		RETURN_CCTOR(numberArguments);
	}
	ZEPHIR_INIT_VAR(dump);
	array_init(dump);
	zephir_is_iterable(argument, &_2, &_1, 0, 0, "phalcon/debug.zep", 200);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		ZEPHIR_CALL_FUNCTION(&_4, "is_scalar", &_5, 119, v);
		zephir_check_call_status();
		if (zephir_is_true(_4)) {
			ZEPHIR_INIT_NVAR(varDump);
			if (ZEPHIR_IS_STRING(v, "")) {
				ZEPHIR_CONCAT_SVS(varDump, "[", k, "] =&gt; (empty string)");
			} else {
				ZEPHIR_CALL_METHOD(&_6, this_ptr, "_escapestring", &_7, 0, v);
				zephir_check_call_status();
				ZEPHIR_CONCAT_SVSV(varDump, "[", k, "] =&gt; ", _6);
			}
			zephir_array_append(&dump, varDump, PH_SEPARATE, "phalcon/debug.zep", 178);
			continue;
		}
		if (Z_TYPE_P(v) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, (zephir_get_numberval(n) + 1));
			ZEPHIR_CALL_METHOD(&_6, this_ptr, "_getarraydump", &_9, 120, v, _8);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_10);
			ZEPHIR_CONCAT_SVSVS(_10, "[", k, "] =&gt; Array(", _6, ")");
			zephir_array_append(&dump, _10, PH_SEPARATE, "phalcon/debug.zep", 183);
			continue;
		}
		if (Z_TYPE_P(v) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_8);
			zephir_get_class(_8, v, 0 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_10);
			ZEPHIR_CONCAT_SVSVS(_10, "[", k, "] =&gt; Object(", _8, ")");
			zephir_array_append(&dump, _10, PH_SEPARATE, "phalcon/debug.zep", 188);
			continue;
		}
		if (Z_TYPE_P(v) == IS_NULL) {
			ZEPHIR_INIT_LNVAR(_10);
			ZEPHIR_CONCAT_SVS(_10, "[", k, "] =&gt; null");
			zephir_array_append(&dump, _10, PH_SEPARATE, "phalcon/debug.zep", 193);
			continue;
		}
		ZEPHIR_INIT_LNVAR(_10);
		ZEPHIR_CONCAT_SVSV(_10, "[", k, "] =&gt; ", v);
		zephir_array_append(&dump, _10, PH_SEPARATE, "phalcon/debug.zep", 197);
	}
	zephir_fast_join_str(return_value, SL(", "), dump TSRMLS_CC);
	RETURN_MM();

}

/**
 * Produces an string representation of a variable
 */
PHP_METHOD(Phalcon_Debug, _getVarDump) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *variable, *className, *dumpedObject = NULL, *dump, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &variable);



	ZEPHIR_CALL_FUNCTION(&_0, "is_scalar", NULL, 119, variable);
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
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_escapestring", NULL, 0, variable);
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
			ZEPHIR_CALL_METHOD(&dumpedObject, variable, "dump", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getarraydump", &_2, 0, dumpedObject);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVSVS(dump, "Object(", className, ": ", _1, ")");
		} else {
			ZEPHIR_CONCAT_SVS(dump, "Object(", className, ")</span>");
		}
		RETURN_CCTOR(dump);
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "_getarraydump", &_2, 120, variable);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "Array(", _1, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		RETURN_MM_STRING("null", 1);
	}
	zephir_gettype(return_value, variable TSRMLS_CC);
	RETURN_MM();

}

/**
 * Returns the major framework's version
 */
PHP_METHOD(Phalcon_Debug, getMajorVersion) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *parts, *_0 = NULL, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_version_ce, "get", &_1, 121);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(parts);
	zephir_fast_explode_str(parts, SL(" "), _0, LONG_MAX TSRMLS_CC);
	zephir_array_fetch_long(&_2, parts, 0, PH_NOISY | PH_READONLY, "phalcon/debug.zep", 290 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * Generates a link to the current version documentation
 */
PHP_METHOD(Phalcon_Debug, getVersion) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmajorversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_1, phalcon_version_ce, "get", &_2, 121);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "<div class=\"version\">Phalcon Framework <a target=\"_new\" href=\"http://docs.phalconphp.com/en/", _0, "/\">", _1, "</a></div>");
	RETURN_MM();

}

/**
 * Returns the css sources
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
 */
PHP_METHOD(Phalcon_Debug, showTraceItem) {

	zephir_fcall_cache_entry *_13 = NULL, *_20 = NULL;
	HashTable *_11;
	HashPosition _10;
	zval *_1, *_15 = NULL;
	zval *trace = NULL;
	zval *n_param = NULL, *trace_param = NULL, *space, *twoSpaces, *underscore, *minus, *className, *namespaceSeparator, *prepareInternalClass, *preparedFunctionName, *html = NULL, *classReflection, *prepareUriClass, *functionName, *functionReflection, *traceArgs, *arguments, *argument = NULL, *filez, *line = NULL, *showFiles, *lines = NULL, *numberLines, *showFileFragment, *beforeLine, *afterLine, *lastLine = NULL, *commentPattern, *utf8, *entCompat, *tab, *comment, linePosition = zval_used_for_init, *currentLine = NULL, _0, *_2, *_3 = NULL, _4 = zval_used_for_init, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9, **_12, *_14, _16 = zval_used_for_init, *_17, *_18 = NULL, *_19 = NULL;
	int n, firstLine, i, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &n_param, &trace_param);

	n = zephir_get_intval(n_param);
	trace = trace_param;



	ZEPHIR_INIT_VAR(space);
	ZVAL_STRING(space, " ", 1);
	ZEPHIR_INIT_VAR(twoSpaces);
	ZVAL_STRING(twoSpaces, "  ", 1);
	ZEPHIR_INIT_VAR(underscore);
	ZVAL_STRING(underscore, "_", 1);
	ZEPHIR_INIT_VAR(minus);
	ZVAL_STRING(minus, "-", 1);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, n);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "<tr><td align=\"right\" valign=\"top\" class=\"error-number\">#", &_0, "</td><td>");
	ZEPHIR_CPY_WRT(html, _1);
	if (zephir_array_isset_string(trace, SS("class"))) {
		ZEPHIR_OBS_VAR(className);
		zephir_array_fetch_string(&className, trace, SL("class"), PH_NOISY, "phalcon/debug.zep", 356 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "/^Phalcon/", 0);
		zephir_preg_match(_3, &_4, className, _2, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(_3)) {
			ZEPHIR_INIT_VAR(namespaceSeparator);
			ZVAL_STRING(namespaceSeparator, "\\", 1);
			ZEPHIR_INIT_VAR(prepareUriClass);
			zephir_fast_str_replace(&prepareUriClass, namespaceSeparator, underscore, className TSRMLS_CC);
			ZEPHIR_INIT_VAR(_5);
			ZEPHIR_CONCAT_SVSVS(_5, "<span class=\"error-class\"><a target=\"_new\" href=\"http://docs.phalconphp.com/en/latest/api/", prepareUriClass, ".html\">", className, "</a></span>");
			zephir_concat_self(&html, _5 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(classReflection);
			object_init_ex(classReflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, classReflection, "__construct", NULL, 15, className);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6, classReflection, "isinternal", NULL, 122);
			zephir_check_call_status();
			if (zephir_is_true(_6)) {
				ZEPHIR_INIT_VAR(_7);
				zephir_fast_strtolower(_7, className);
				ZEPHIR_INIT_VAR(prepareInternalClass);
				zephir_fast_str_replace(&prepareInternalClass, underscore, minus, _7 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_SVSVS(_5, "<span class=\"error-class\"><a target=\"_new\" href=\"http://php.net/manual/en/class.", prepareInternalClass, ".php\">", className, "</a></span>");
				zephir_concat_self(&html, _5 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_VAR(_8);
				ZEPHIR_CONCAT_SVS(_8, "<span class=\"error-class\">", className, "</span>");
				zephir_concat_self(&html, _8 TSRMLS_CC);
			}
		}
		zephir_array_fetch_string(&_9, trace, SL("type"), PH_NOISY | PH_READONLY, "phalcon/debug.zep", 397 TSRMLS_CC);
		zephir_concat_self(&html, _9 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(functionName);
	zephir_array_fetch_string(&functionName, trace, SL("function"), PH_NOISY, "phalcon/debug.zep", 403 TSRMLS_CC);
	if (zephir_array_isset_string(trace, SS("class"))) {
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_SVS(_5, "<span class=\"error-function\">", functionName, "</span>");
		zephir_concat_self(&html, _5 TSRMLS_CC);
	} else {
		if ((zephir_function_exists(functionName TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_INIT_VAR(functionReflection);
			object_init_ex(functionReflection, zephir_get_internal_ce(SS("reflectionfunction") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, functionReflection, "__construct", NULL, 123, functionName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6, functionReflection, "isinternal", NULL, 124);
			zephir_check_call_status();
			if (zephir_is_true(_6)) {
				ZEPHIR_INIT_VAR(preparedFunctionName);
				zephir_fast_str_replace(&preparedFunctionName, underscore, minus, functionName TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_8);
				ZEPHIR_CONCAT_SVSVS(_8, "<span class=\"error-function\"><a target=\"_new\" href=\"http://php.net/manual/en/function.", preparedFunctionName, ".php\">", functionName, "</a></span>");
				zephir_concat_self(&html, _8 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_LNVAR(_8);
				ZEPHIR_CONCAT_SVS(_8, "<span class=\"error-function\">", functionName, "</span>");
				zephir_concat_self(&html, _8 TSRMLS_CC);
			}
		} else {
			ZEPHIR_INIT_LNVAR(_5);
			ZEPHIR_CONCAT_SVS(_5, "<span class=\"error-function\">", functionName, "</span>");
			zephir_concat_self(&html, _5 TSRMLS_CC);
		}
	}
	if (zephir_array_isset_string(trace, SS("args"))) {
		ZEPHIR_OBS_VAR(traceArgs);
		zephir_array_fetch_string(&traceArgs, trace, SL("args"), PH_NOISY, "phalcon/debug.zep", 437 TSRMLS_CC);
		if (zephir_fast_count_int(traceArgs TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(arguments);
			array_init(arguments);
			zephir_is_iterable(traceArgs, &_11, &_10, 0, 0, "phalcon/debug.zep", 452);
			for (
			  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
			  ; zephir_hash_move_forward_ex(_11, &_10)
			) {
				ZEPHIR_GET_HVALUE(argument, _12);
				ZEPHIR_CALL_METHOD(&_6, this_ptr, "_getvardump", &_13, 0, argument);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_SVS(_5, "<span class=\"error-parameter\">", _6, "</span>");
				zephir_array_append(&arguments, _5, PH_SEPARATE, "phalcon/debug.zep", 446);
			}
			ZEPHIR_INIT_NVAR(_3);
			zephir_fast_join_str(_3, SL(", "), arguments TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_8);
			ZEPHIR_CONCAT_SVS(_8, "(", _3, ")");
			zephir_concat_self(&html, _8 TSRMLS_CC);
		} else {
			zephir_concat_self_str(&html, SL("()") TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(filez);
	if (zephir_array_isset_string_fetch(&filez, trace, SS("file"), 0 TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_14);
		zephir_array_fetch_string(&_14, trace, SL("line"), PH_NOISY, "phalcon/debug.zep", 463 TSRMLS_CC);
		zephir_get_strval(_15, _14);
		ZEPHIR_CPY_WRT(line, _15);
		ZEPHIR_INIT_LNVAR(_5);
		ZEPHIR_CONCAT_SVSVS(_5, "<br/><div class=\"error-file\">", filez, " (", line, ")</div>");
		zephir_concat_self(&html, _5 TSRMLS_CC);
		ZEPHIR_OBS_VAR(showFiles);
		zephir_read_property_this(&showFiles, this_ptr, SL("_showFiles"), PH_NOISY_CC);
		if (zephir_is_true(showFiles)) {
			ZEPHIR_CALL_FUNCTION(&lines, "file", NULL, 125, filez);
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
				ZEPHIR_SINIT_NVAR(_4);
				ZVAL_LONG(&_4, firstLine);
				ZEPHIR_SINIT_VAR(_16);
				ZVAL_LONG(&_16, firstLine);
				ZEPHIR_INIT_VAR(_17);
				ZEPHIR_CONCAT_SVSVSVS(_17, "<pre class=\"prettyprint highlight:", &_4, ":", line, " linenums:", &_16, "\">");
				zephir_concat_self(&html, _17 TSRMLS_CC);
			} else {
				firstLine = 1;
				ZEPHIR_CPY_WRT(lastLine, numberLines);
				ZEPHIR_SINIT_NVAR(_16);
				ZVAL_LONG(&_16, firstLine);
				ZEPHIR_INIT_LNVAR(_8);
				ZEPHIR_CONCAT_SVSVS(_8, "<pre class=\"prettyprint highlight:", &_16, ":", line, " linenums error-scroll\">");
				zephir_concat_self(&html, _8 TSRMLS_CC);
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
				zephir_array_fetch(&currentLine, lines, &linePosition, PH_NOISY, "phalcon/debug.zep", 551 TSRMLS_CC);
				if (zephir_is_true(showFileFragment)) {
					if (i == firstLine) {
						ZEPHIR_INIT_NVAR(_18);
						ZEPHIR_INIT_NVAR(_3);
						ZEPHIR_INIT_NVAR(_7);
						zephir_fast_trim(_7, currentLine, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
						zephir_preg_match(_3, commentPattern, _7, _18, 0, 0 , 0  TSRMLS_CC);
						if (zephir_is_true(_3)) {
							ZEPHIR_INIT_NVAR(_19);
							zephir_fast_str_replace(&_19, comment, space, currentLine TSRMLS_CC);
							ZEPHIR_CPY_WRT(currentLine, _19);
						}
					}
				}
				if (ZEPHIR_IS_STRING(currentLine, "\n")) {
					zephir_concat_self_str(&html, SL("&nbsp;\n") TSRMLS_CC);
				} else {
					if (ZEPHIR_IS_STRING(currentLine, "\r\n")) {
						zephir_concat_self_str(&html, SL("&nbsp;\n") TSRMLS_CC);
					} else {
						ZEPHIR_INIT_NVAR(_19);
						zephir_fast_str_replace(&_19, tab, twoSpaces, currentLine TSRMLS_CC);
						ZEPHIR_CALL_FUNCTION(&_6, "htmlentities", &_20, 118, _19, entCompat, utf8);
						zephir_check_call_status();
						zephir_concat_self(&html, _6 TSRMLS_CC);
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
 * Throws an exception when a notice or warning is raised
 */
PHP_METHOD(Phalcon_Debug, onUncaughtLowSeverity) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *severity, *message, *file, *line, *_0 = NULL, _1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &severity, &message, &file, &line);



	ZEPHIR_CALL_FUNCTION(&_0, "error_reporting", NULL, 126);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	zephir_bitwise_and_function(&_1, _0, severity TSRMLS_CC);
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, zephir_get_internal_ce(SS("errorexception") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 127, message, _3, severity, file, line);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "phalcon/debug.zep", 594 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles uncaught exceptions
 */
PHP_METHOD(Phalcon_Debug, onUncaughtException) {

	zephir_fcall_cache_entry *_14 = NULL, *_19 = NULL, *_32 = NULL;
	HashTable *_11, *_16, *_21, *_24, *_28;
	HashPosition _10, _15, _20, _23, _27;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *exception, *obLevel = NULL, *className, *escapedMessage = NULL, *html, *showBackTrace, *dataVars, *n = NULL, *traceItem = NULL, *keyRequest = NULL, *value = NULL, *keyServer = NULL, *keyFile = NULL, *keyVar = NULL, *dataVar = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL, *_5, *_6 = NULL, *_7 = NULL, *_8, *_9 = NULL, **_12, *_13 = NULL, *_REQUEST, **_17, *_18 = NULL, *_SERVER, **_22, **_25, *_26 = NULL, **_29, *_30 = NULL, *_31, *_33 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &exception);



	ZEPHIR_CALL_FUNCTION(&obLevel, "ob_get_level", NULL, 128);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(obLevel, 0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 51);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_static_property_ce(phalcon_debug_ce, SL("_isActive") TSRMLS_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&_1, exception, "getmessage", NULL, 0);
		zephir_check_call_status();
		zend_print_zval(_1, 0);
		RETURN_MM_NULL();
	}
	zephir_update_static_property_ce(phalcon_debug_ce, SL("_isActive"), &(ZEPHIR_GLOBAL(global_true)) TSRMLS_CC);
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, exception, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, exception, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&escapedMessage, this_ptr, "_escapestring", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(html);
	ZEPHIR_CONCAT_SVSVS(html, "<html><head><title>", className, ": ", escapedMessage, "</title>");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcsssources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VS(_3, _2, "</head><body>");
	zephir_concat_self(&html, _3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getversion", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&html, _4 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("<div align=\"center\"><div class=\"error-main\">") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SVSVS(_5, "<h1>", className, ": ", escapedMessage, "</h1>");
	zephir_concat_self(&html, _5 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_6, exception, "getfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, exception, "getline", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_CONCAT_SVSVS(_8, "<span class=\"error-file\">", _6, " (", _7, ")</span>");
	zephir_concat_self(&html, _8 TSRMLS_CC);
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
		ZEPHIR_CALL_METHOD(&_9, exception, "gettrace", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(_9, &_11, &_10, 0, 0, "phalcon/debug.zep", 688);
		for (
		  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
		  ; zephir_hash_move_forward_ex(_11, &_10)
		) {
			ZEPHIR_GET_HMKEY(n, _11, _10);
			ZEPHIR_GET_HVALUE(traceItem, _12);
			ZEPHIR_CALL_METHOD(&_13, this_ptr, "showtraceitem", &_14, 129, n, traceItem);
			zephir_check_call_status();
			zephir_concat_self(&html, _13 TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-2\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
		zephir_is_iterable(_REQUEST, &_16, &_15, 0, 0, "phalcon/debug.zep", 702);
		for (
		  ; zephir_hash_get_current_data_ex(_16, (void**) &_17, &_15) == SUCCESS
		  ; zephir_hash_move_forward_ex(_16, &_15)
		) {
			ZEPHIR_GET_HMKEY(keyRequest, _16, _15);
			ZEPHIR_GET_HVALUE(value, _17);
			if (Z_TYPE_P(value) != IS_ARRAY) {
				ZEPHIR_INIT_LNVAR(_18);
				ZEPHIR_CONCAT_SVSVS(_18, "<tr><td class=\"key\">", keyRequest, "</td><td>", value, "</td></tr>");
				zephir_concat_self(&html, _18 TSRMLS_CC);
			} else {
				ZEPHIR_CALL_FUNCTION(&_13, "print_r", &_19, 130, value, ZEPHIR_GLOBAL(global_true));
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_18);
				ZEPHIR_CONCAT_SVSVS(_18, "<tr><td class=\"key\">", keyRequest, "</td><td>", _13, "</td></tr>");
				zephir_concat_self(&html, _18 TSRMLS_CC);
			}
		}
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-3\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
		zephir_is_iterable(_SERVER, &_21, &_20, 0, 0, "phalcon/debug.zep", 712);
		for (
		  ; zephir_hash_get_current_data_ex(_21, (void**) &_22, &_20) == SUCCESS
		  ; zephir_hash_move_forward_ex(_21, &_20)
		) {
			ZEPHIR_GET_HMKEY(keyServer, _21, _20);
			ZEPHIR_GET_HVALUE(value, _22);
			ZEPHIR_INIT_LNVAR(_18);
			ZEPHIR_CONCAT_SVSVS(_18, "<tr><td class=\"key\">", keyServer, "</td><td>", value, "</td></tr>");
			zephir_concat_self(&html, _18 TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-4\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<tr><th>#</th><th>Path</th></tr>") TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_13, "get_included_files", NULL, 131);
		zephir_check_call_status();
		zephir_is_iterable(_13, &_24, &_23, 0, 0, "phalcon/debug.zep", 722);
		for (
		  ; zephir_hash_get_current_data_ex(_24, (void**) &_25, &_23) == SUCCESS
		  ; zephir_hash_move_forward_ex(_24, &_23)
		) {
			ZEPHIR_GET_HMKEY(keyFile, _24, _23);
			ZEPHIR_GET_HVALUE(value, _25);
			ZEPHIR_INIT_LNVAR(_26);
			ZEPHIR_CONCAT_SVSVS(_26, "<tr><td>", keyFile, "</th><td>", value, "</td></tr>");
			zephir_concat_self(&html, _26 TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-5\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_13, "memory_get_usage", NULL, 132, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_26);
		ZEPHIR_CONCAT_SVS(_26, "<tr><th colspan=\"2\">Memory</th></tr><tr><td>Usage</td><td>", _13, "</td></tr>");
		zephir_concat_self(&html, _26 TSRMLS_CC);
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		if (Z_TYPE_P(dataVars) == IS_ARRAY) {
			zephir_concat_self_str(&html, SL("<div id=\"error-tabs-6\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
			zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
			zephir_is_iterable(dataVars, &_28, &_27, 0, 0, "phalcon/debug.zep", 740);
			for (
			  ; zephir_hash_get_current_data_ex(_28, (void**) &_29, &_27) == SUCCESS
			  ; zephir_hash_move_forward_ex(_28, &_27)
			) {
				ZEPHIR_GET_HMKEY(keyVar, _28, _27);
				ZEPHIR_GET_HVALUE(dataVar, _29);
				zephir_array_fetch_long(&_31, dataVar, 0, PH_NOISY | PH_READONLY, "phalcon/debug.zep", 738 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_30, this_ptr, "_getvardump", &_32, 0, _31);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_33);
				ZEPHIR_CONCAT_SVSVS(_33, "<tr><td class=\"key\">", keyVar, "</td><td>", _30, "</td></tr>");
				zephir_concat_self(&html, _33 TSRMLS_CC);
			}
			zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</div>") TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getjssources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_18);
	ZEPHIR_CONCAT_VS(_18, _1, "</div></body></html>");
	zephir_concat_self(&html, _18 TSRMLS_CC);
	zend_print_zval(html, 0);
	zephir_update_static_property_ce(phalcon_debug_ce, SL("_isActive"), &(ZEPHIR_GLOBAL(global_false)) TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

