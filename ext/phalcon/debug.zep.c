
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
#include "kernel/concat.h"


/**
 * Phalcon\Debug
 *
 * Provides debug capabilities to Phalcon applications
 */
ZEPHIR_INIT_CLASS(Phalcon_Debug) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Debug, phalcon, debug, phalcon_debug_method_entry, 0);

	zend_declare_property_string(phalcon_debug_ce, SL("_uri"), "//static.phalconphp.com/www/debug/3.0.x/", ZEND_ACC_PUBLIC TSRMLS_CC);

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

	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	}


	zephir_update_property_this(getThis(), SL("_uri"), uri TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Sets if files the exception's backtrace must be showed
 */
PHP_METHOD(Phalcon_Debug, setShowBackTrace) {

	zval *showBackTrace_param = NULL;
	zend_bool showBackTrace;

	zephir_fetch_params(0, 1, 0, &showBackTrace_param);

	showBackTrace = zephir_get_boolval(showBackTrace_param);


	if (showBackTrace) {
		zephir_update_property_this(getThis(), SL("_showBackTrace"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_showBackTrace"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
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


	if (showFiles) {
		zephir_update_property_this(getThis(), SL("_showFiles"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_showFiles"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
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


	if (showFileFragment) {
		zephir_update_property_this(getThis(), SL("_showFileFragment"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_showFileFragment"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	RETURN_THISW();

}

/**
 * Listen for uncaught exceptions and unsilent notices or warnings
 */
PHP_METHOD(Phalcon_Debug, listen) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
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

	zval *_1;
	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "onUncaughtException", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 174, _0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Listen for unsilent notices or warnings
 */
PHP_METHOD(Phalcon_Debug, listenLowSeverity) {

	zval *_1 = NULL;
	zval *_0, *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, this_ptr);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "onUncaughtLowSeverity", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 175, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_2, this_ptr);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "onUncaughtException", 1);
	zephir_array_fast_append(_2, _1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 174, _2);
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

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
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
	ZEPHIR_CALL_FUNCTION(&_1, "debug_backtrace", NULL, 176);
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

	

	zephir_update_property_this(getThis(), SL("_data"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Escapes a string with htmlentities
 */
PHP_METHOD(Phalcon_Debug, _escapeString) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0$$3, _1$$3, _2$$3, _3$$3, _4$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_STRING) {
		ZEPHIR_INIT_VAR(_0$$3);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_STRING(&_1$$3, "\n", 0);
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "\\n", 0);
		zephir_fast_str_replace(&_0$$3, &_1$$3, &_2$$3, value TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_LONG(&_3$$3, 2);
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_STRING(&_4$$3, "utf-8", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("htmlentities", NULL, 177, _0$$3, &_3$$3, &_4$$3);
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

	HashTable *_2;
	HashPosition _1;
	zend_bool _0;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argument_param = NULL, *n = NULL, *numberArguments = NULL, *dump = NULL, *varDump = NULL, *k = NULL, *v = NULL, **_3, *_5$$8 = NULL, *_6$$8 = NULL, *_8$$9 = NULL, *_9$$5 = NULL;
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
	zephir_is_iterable(argument, &_2, &_1, 0, 0, "phalcon/debug.zep", 189);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(k, _2, _1);
		ZEPHIR_GET_HVALUE(v, _3);
		if (ZEPHIR_IS_STRING(v, "")) {
			ZEPHIR_INIT_NVAR(varDump);
			ZVAL_STRING(varDump, "(empty string)", 1);
		} else if (zephir_is_scalar(v)) {
			ZEPHIR_CALL_METHOD(&varDump, this_ptr, "_escapestring", &_4, 0, v);
			zephir_check_call_status();
		} else if (Z_TYPE_P(v) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_6$$8);
			ZVAL_LONG(_6$$8, (zephir_get_numberval(n) + 1));
			ZEPHIR_CALL_METHOD(&_5$$8, this_ptr, "_getarraydump", &_7, 178, v, _6$$8);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(varDump);
			ZEPHIR_CONCAT_SVS(varDump, "Array(", _5$$8, ")");
		} else if (Z_TYPE_P(v) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(_8$$9);
			zephir_get_class(_8$$9, v, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(varDump);
			ZEPHIR_CONCAT_SVS(varDump, "Object(", _8$$9, ")");
		} else if (Z_TYPE_P(v) == IS_NULL) {
			ZEPHIR_INIT_NVAR(varDump);
			ZVAL_STRING(varDump, "null", 1);
		} else {
			ZEPHIR_CPY_WRT(varDump, v);
		}
		ZEPHIR_INIT_LNVAR(_9$$5);
		ZEPHIR_CONCAT_SVSV(_9$$5, "[", k, "] =&gt; ", varDump);
		zephir_array_append(&dump, _9$$5, PH_SEPARATE, "phalcon/debug.zep", 186);
	}
	zephir_fast_join_str(return_value, SL(", "), dump TSRMLS_CC);
	RETURN_MM();

}

/**
 * Produces an string representation of a variable
 */
PHP_METHOD(Phalcon_Debug, _getVarDump) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variable, *className = NULL, *dumpedObject = NULL, *_0$$9 = NULL, *_1$$11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &variable);



	if (zephir_is_scalar(variable)) {
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
		if ((zephir_method_exists_ex(variable, SS("dump") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&dumpedObject, variable, "dump", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_0$$9, this_ptr, "_getarraydump", NULL, 0, dumpedObject);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVSVS(return_value, "Object(", className, ": ", _0$$9, ")");
			RETURN_MM();
		} else {
			ZEPHIR_CONCAT_SVS(return_value, "Object(", className, ")");
			RETURN_MM();
		}
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_1$$11, this_ptr, "_getarraydump", NULL, 178, variable);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "Array(", _1$$11, ")");
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
 *
 * @deprecated Will be removed in 4.0.0
 * @see Phalcon\Version::getPart()
 */
PHP_METHOD(Phalcon_Debug, getMajorVersion) {

	zval *parts = NULL, *_0 = NULL, *_2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_version_ce, "get", &_1, 179);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(parts);
	zephir_fast_explode_str(parts, SL(" "), _0, LONG_MAX TSRMLS_CC);
	zephir_array_fetch_long(&_2, parts, 0, PH_NOISY | PH_READONLY, "phalcon/debug.zep", 281 TSRMLS_CC);
	RETURN_CTOR(_2);

}

/**
 * Generates a link to the current version documentation
 */
PHP_METHOD(Phalcon_Debug, getVersion) {

	zval *link = NULL, *_0 = NULL, *_2, *_3, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_5 = NULL, *_6 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(link);
	zephir_create_array(link, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_version_ce, "getpart", &_1, 180, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVS(_3, "https://docs.phalconphp.com/en/", _0, ".0.0/");
	zephir_array_update_string(&link, SL("action"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_CE_STATIC(&_4, phalcon_version_ce, "get", &_5, 179);
	zephir_check_call_status();
	zephir_array_update_string(&link, SL("text"), &_4, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&link, SL("local"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(link, SS("target"), SL("_new"), 1);
	ZEPHIR_CALL_CE_STATIC(&_4, phalcon_tag_ce, "linkto", &_6, 181, link);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<div class='version'>Phalcon Framework ", _4, "</div>");
	RETURN_MM();

}

/**
 * Returns the css sources
 */
PHP_METHOD(Phalcon_Debug, getCssSources) {

	zval *uri = NULL, *sources = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();

	uri = zephir_fetch_nproperty_this(this_ptr, SL("_uri"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(sources);
	ZEPHIR_CONCAT_SVS(sources, "<link href=\"", uri, "bower_components/jquery-ui/themes/ui-lightness/jquery-ui.min.css\" type=\"text/css\" rel=\"stylesheet\" />");
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "<link href=\"", uri, "bower_components/jquery-ui/themes/ui-lightness/theme.css\" type=\"text/css\" rel=\"stylesheet\" />");
	zephir_concat_self(&sources, _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "<link href=\"", uri, "themes/default/style.css\" type=\"text/css\" rel=\"stylesheet\" />");
	zephir_concat_self(&sources, _1 TSRMLS_CC);
	RETURN_CCTOR(sources);

}

/**
 * Returns the javascript sources
 */
PHP_METHOD(Phalcon_Debug, getJsSources) {

	zval *uri = NULL, *sources = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	uri = zephir_fetch_nproperty_this(this_ptr, SL("_uri"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(sources);
	ZEPHIR_CONCAT_SVS(sources, "<script type=\"text/javascript\" src=\"", uri, "bower_components/jquery/dist/jquery.min.js\"></script>");
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_CONCAT_SVS(_0, "<script type=\"text/javascript\" src=\"", uri, "bower_components/jquery-ui/jquery-ui.min.js\"></script>");
	zephir_concat_self(&sources, _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "<script type=\"text/javascript\" src=\"", uri, "bower_components/jquery.scrollTo/jquery.scrollTo.min.js\"></script>");
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

	zend_bool _37$$24;
	HashTable *_18$$14;
	HashPosition _17$$14;
	zval *_1, *_26$$16 = NULL;
	zephir_fcall_cache_entry *_21 = NULL, *_44 = NULL;
	zval *trace = NULL;
	zval *n_param = NULL, *trace_param = NULL, *className = NULL, *prepareInternalClass = NULL, *preparedFunctionName = NULL, *html = NULL, *classReflection = NULL, *prepareUriClass = NULL, *functionName = NULL, *functionReflection = NULL, *traceArgs = NULL, *arguments = NULL, *argument = NULL, *filez = NULL, *line = NULL, *showFiles = NULL, *lines = NULL, *numberLines = NULL, *showFileFragment = NULL, *firstLine = NULL, *lastLine = NULL, *linePosition = NULL, *currentLine = NULL, *classNameWithLink = NULL, *functionNameWithLink = NULL, _0, *_16, *_2$$3, *_3$$3, _4$$3, *_11$$3, *_12$$3, _5$$4, _6$$4, *_7$$5 = NULL, *_8$$6, _9$$6, _10$$6, *_13$$10 = NULL, _14$$11, _15$$11, **_19$$14, *_23$$14, *_24$$14, *_20$$15 = NULL, *_22$$15 = NULL, *_25$$16, *_27$$16, *_28$$18, *_29$$23, *_30$$26 = NULL, *_31$$26 = NULL, *_32$$26 = NULL, _33$$26 = zval_used_for_init, *_34$$27 = NULL, _35$$27 = zval_used_for_init, _36$$27 = zval_used_for_init, *_38$$29 = NULL, _39$$29 = zval_used_for_init, _40$$29 = zval_used_for_init, _41$$29 = zval_used_for_init, _42$$29 = zval_used_for_init, *_43$$29 = NULL;
	zend_long n, ZEPHIR_LAST_CALL_STATUS, i = 0, beforeLine$$18, afterLine$$18;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &n_param, &trace_param);

	n = zephir_get_intval(n_param);
	trace = trace_param;


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, n);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "<tr><td align=\"right\" valign=\"top\" class=\"error-number\">#", &_0, "</td><td>");
	ZEPHIR_CPY_WRT(html, _1);
	ZEPHIR_OBS_VAR(className);
	if (zephir_array_isset_string_fetch(&className, trace, SS("class"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_STRING(&_4$$3, "/^Phalcon/", 0);
		zephir_preg_match(_3$$3, &_4$$3, className, _2$$3, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(_3$$3)) {
			ZEPHIR_SINIT_VAR(_5$$4);
			ZVAL_STRING(&_5$$4, "\\", 0);
			ZEPHIR_SINIT_VAR(_6$$4);
			ZVAL_STRING(&_6$$4, "/", 0);
			ZEPHIR_INIT_VAR(prepareUriClass);
			zephir_fast_str_replace(&prepareUriClass, &_5$$4, &_6$$4, className TSRMLS_CC);
			ZEPHIR_INIT_VAR(classNameWithLink);
			ZEPHIR_CONCAT_SVSVS(classNameWithLink, "<a target=\"_new\" href=\"//api.phalconphp.com/class/", prepareUriClass, ".html\">", className, "</a>");
		} else {
			ZEPHIR_INIT_VAR(classReflection);
			object_init_ex(classReflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, classReflection, "__construct", NULL, 98, className);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7$$5, classReflection, "isinternal", NULL, 182);
			zephir_check_call_status();
			if (zephir_is_true(_7$$5)) {
				ZEPHIR_INIT_VAR(_8$$6);
				zephir_fast_strtolower(_8$$6, className);
				ZEPHIR_SINIT_VAR(_9$$6);
				ZVAL_STRING(&_9$$6, "_", 0);
				ZEPHIR_SINIT_VAR(_10$$6);
				ZVAL_STRING(&_10$$6, "-", 0);
				ZEPHIR_INIT_VAR(prepareInternalClass);
				zephir_fast_str_replace(&prepareInternalClass, &_9$$6, &_10$$6, _8$$6 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(classNameWithLink);
				ZEPHIR_CONCAT_SVSVS(classNameWithLink, "<a target=\"_new\" href=\"http://php.net/manual/en/class.", prepareInternalClass, ".php\">", className, "</a>");
			} else {
				ZEPHIR_CPY_WRT(classNameWithLink, className);
			}
		}
		ZEPHIR_INIT_VAR(_11$$3);
		ZEPHIR_CONCAT_SVS(_11$$3, "<span class=\"error-class\">", classNameWithLink, "</span>");
		zephir_concat_self(&html, _11$$3 TSRMLS_CC);
		zephir_array_fetch_string(&_12$$3, trace, SL("type"), PH_NOISY | PH_READONLY, "phalcon/debug.zep", 388 TSRMLS_CC);
		zephir_concat_self(&html, _12$$3 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(functionName);
	zephir_array_fetch_string(&functionName, trace, SL("function"), PH_NOISY, "phalcon/debug.zep", 394 TSRMLS_CC);
	if (zephir_array_isset_string(trace, SS("class"))) {
		ZEPHIR_CPY_WRT(functionNameWithLink, functionName);
	} else {
		if ((zephir_function_exists(functionName TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_INIT_VAR(functionReflection);
			object_init_ex(functionReflection, zephir_get_internal_ce(SS("reflectionfunction") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, functionReflection, "__construct", NULL, 87, functionName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_13$$10, functionReflection, "isinternal", NULL, 183);
			zephir_check_call_status();
			if (zephir_is_true(_13$$10)) {
				ZEPHIR_SINIT_VAR(_14$$11);
				ZVAL_STRING(&_14$$11, "_", 0);
				ZEPHIR_SINIT_VAR(_15$$11);
				ZVAL_STRING(&_15$$11, "-", 0);
				ZEPHIR_INIT_VAR(preparedFunctionName);
				zephir_fast_str_replace(&preparedFunctionName, &_14$$11, &_15$$11, functionName TSRMLS_CC);
				ZEPHIR_INIT_NVAR(functionNameWithLink);
				ZEPHIR_CONCAT_SVSVS(functionNameWithLink, "<a target=\"_new\" href=\"http://php.net/manual/en/function.", preparedFunctionName, ".php\">", functionName, "</a>");
			} else {
				ZEPHIR_CPY_WRT(functionNameWithLink, functionName);
			}
		} else {
			ZEPHIR_CPY_WRT(functionNameWithLink, functionName);
		}
	}
	ZEPHIR_INIT_VAR(_16);
	ZEPHIR_CONCAT_SVS(_16, "<span class=\"error-function\">", functionNameWithLink, "</span>");
	zephir_concat_self(&html, _16 TSRMLS_CC);
	ZEPHIR_OBS_VAR(traceArgs);
	if (zephir_array_isset_string_fetch(&traceArgs, trace, SS("args"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(arguments);
		array_init(arguments);
		zephir_is_iterable(traceArgs, &_18$$14, &_17$$14, 0, 0, "phalcon/debug.zep", 443);
		for (
		  ; zend_hash_get_current_data_ex(_18$$14, (void**) &_19$$14, &_17$$14) == SUCCESS
		  ; zend_hash_move_forward_ex(_18$$14, &_17$$14)
		) {
			ZEPHIR_GET_HVALUE(argument, _19$$14);
			ZEPHIR_CALL_METHOD(&_20$$15, this_ptr, "_getvardump", &_21, 0, argument);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_22$$15);
			ZEPHIR_CONCAT_SVS(_22$$15, "<span class=\"error-parameter\">", _20$$15, "</span>");
			zephir_array_append(&arguments, _22$$15, PH_SEPARATE, "phalcon/debug.zep", 437);
		}
		ZEPHIR_INIT_VAR(_23$$14);
		zephir_fast_join_str(_23$$14, SL(", "), arguments TSRMLS_CC);
		ZEPHIR_INIT_VAR(_24$$14);
		ZEPHIR_CONCAT_SVS(_24$$14, "(", _23$$14, ")");
		zephir_concat_self(&html, _24$$14 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(filez);
	if (zephir_array_isset_string_fetch(&filez, trace, SS("file"), 0 TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_25$$16);
		zephir_array_fetch_string(&_25$$16, trace, SL("line"), PH_NOISY, "phalcon/debug.zep", 451 TSRMLS_CC);
		zephir_get_strval(_26$$16, _25$$16);
		ZEPHIR_CPY_WRT(line, _26$$16);
		ZEPHIR_INIT_VAR(_27$$16);
		ZEPHIR_CONCAT_SVSVS(_27$$16, "<br/><div class=\"error-file\">", filez, " (", line, ")</div>");
		zephir_concat_self(&html, _27$$16 TSRMLS_CC);
		ZEPHIR_OBS_VAR(showFiles);
		zephir_read_property_this(&showFiles, this_ptr, SL("_showFiles"), PH_NOISY_CC);
		if (zephir_is_true(showFiles)) {
			ZEPHIR_CALL_FUNCTION(&lines, "file", NULL, 184, filez);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(numberLines);
			ZVAL_LONG(numberLines, zephir_fast_count_int(lines TSRMLS_CC));
			ZEPHIR_OBS_VAR(showFileFragment);
			zephir_read_property_this(&showFileFragment, this_ptr, SL("_showFileFragment"), PH_NOISY_CC);
			if (zephir_is_true(showFileFragment)) {
				beforeLine$$18 = (zephir_get_numberval(line) - 7);
				if (beforeLine$$18 < 1) {
					ZEPHIR_INIT_VAR(firstLine);
					ZVAL_LONG(firstLine, 1);
				} else {
					ZEPHIR_INIT_NVAR(firstLine);
					ZVAL_LONG(firstLine, beforeLine$$18);
				}
				afterLine$$18 = (zephir_get_numberval(line) + 5);
				if (ZEPHIR_LT_LONG(numberLines, afterLine$$18)) {
					ZEPHIR_CPY_WRT(lastLine, numberLines);
				} else {
					ZEPHIR_INIT_NVAR(lastLine);
					ZVAL_LONG(lastLine, afterLine$$18);
				}
				ZEPHIR_INIT_VAR(_28$$18);
				ZEPHIR_CONCAT_SVSVSVS(_28$$18, "<pre class=\"prettyprint highlight:", firstLine, ":", line, " linenums:", firstLine, "\">");
				zephir_concat_self(&html, _28$$18 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(firstLine);
				ZVAL_LONG(firstLine, 1);
				ZEPHIR_CPY_WRT(lastLine, numberLines);
				ZEPHIR_INIT_VAR(_29$$23);
				ZEPHIR_CONCAT_SVSVS(_29$$23, "<pre class=\"prettyprint highlight:", firstLine, ":", line, " linenums error-scroll\">");
				zephir_concat_self(&html, _29$$23 TSRMLS_CC);
			}
			i = zephir_get_numberval(firstLine);
			while (1) {
				if (!(ZEPHIR_GE_LONG(lastLine, i))) {
					break;
				}
				ZEPHIR_INIT_NVAR(linePosition);
				ZVAL_LONG(linePosition, (i - 1));
				ZEPHIR_OBS_NVAR(currentLine);
				zephir_array_fetch(&currentLine, lines, linePosition, PH_NOISY, "phalcon/debug.zep", 523 TSRMLS_CC);
				if (zephir_is_true(showFileFragment)) {
					if (ZEPHIR_IS_LONG(firstLine, i)) {
						ZEPHIR_INIT_NVAR(_30$$26);
						ZEPHIR_INIT_NVAR(_31$$26);
						ZEPHIR_INIT_NVAR(_32$$26);
						zephir_fast_trim(_32$$26, currentLine, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
						ZEPHIR_SINIT_NVAR(_33$$26);
						ZVAL_STRING(&_33$$26, "#\\*\\/#", 0);
						zephir_preg_match(_31$$26, &_33$$26, _32$$26, _30$$26, 0, 0 , 0  TSRMLS_CC);
						if (zephir_is_true(_31$$26)) {
							ZEPHIR_INIT_NVAR(_34$$27);
							ZEPHIR_SINIT_NVAR(_35$$27);
							ZVAL_STRING(&_35$$27, "* /", 0);
							ZEPHIR_SINIT_NVAR(_36$$27);
							ZVAL_STRING(&_36$$27, " ", 0);
							zephir_fast_str_replace(&_34$$27, &_35$$27, &_36$$27, currentLine TSRMLS_CC);
							ZEPHIR_CPY_WRT(currentLine, _34$$27);
						}
					}
				}
				_37$$24 = ZEPHIR_IS_STRING(currentLine, "\n");
				if (!(_37$$24)) {
					_37$$24 = ZEPHIR_IS_STRING(currentLine, "\r\n");
				}
				if (_37$$24) {
					zephir_concat_self_str(&html, SL("&nbsp;\n") TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(_38$$29);
					ZEPHIR_SINIT_NVAR(_39$$29);
					ZVAL_STRING(&_39$$29, "\t", 0);
					ZEPHIR_SINIT_NVAR(_40$$29);
					ZVAL_STRING(&_40$$29, "  ", 0);
					zephir_fast_str_replace(&_38$$29, &_39$$29, &_40$$29, currentLine TSRMLS_CC);
					ZEPHIR_SINIT_NVAR(_41$$29);
					ZVAL_LONG(&_41$$29, 2);
					ZEPHIR_SINIT_NVAR(_42$$29);
					ZVAL_STRING(&_42$$29, "UTF-8", 0);
					ZEPHIR_CALL_FUNCTION(&_43$$29, "htmlentities", &_44, 177, _38$$29, &_41$$29, &_42$$29);
					zephir_check_call_status();
					zephir_concat_self(&html, _43$$29 TSRMLS_CC);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *severity, *message, *file, *line, *context, *_0 = NULL, _1, *_2$$3, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &severity, &message, &file, &line, &context);



	ZEPHIR_CALL_FUNCTION(&_0, "error_reporting", NULL, 185);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	zephir_bitwise_and_function(&_1, _0, severity TSRMLS_CC);
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, zephir_get_internal_ce(SS("errorexception") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_LONG(_3$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 186, message, _3$$3, severity, file, line);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "phalcon/debug.zep", 566 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Handles uncaught exceptions
 */
PHP_METHOD(Phalcon_Debug, onUncaughtException) {

	HashTable *_12$$5, *_17$$5, *_24$$5, *_31$$5, *_37$$13;
	HashPosition _11$$5, _16$$5, _23$$5, _30$$5, _36$$13;
	zephir_fcall_cache_entry *_15 = NULL, *_21 = NULL, *_27 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, *_REQUEST, *_SERVER, *obLevel = NULL, *className = NULL, *escapedMessage = NULL, *html = NULL, *showBackTrace = NULL, *dataVars = NULL, *n = NULL, *traceItem = NULL, *keyRequest = NULL, *value = NULL, *keyServer = NULL, *keyFile = NULL, *keyVar = NULL, *dataVar = NULL, *_0, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_6, *_7 = NULL, *_8 = NULL, *_9, *_42 = NULL, *_43, *_1$$4 = NULL, *_10$$5 = NULL, **_13$$5, **_18$$5, **_25$$5, *_29$$5 = NULL, **_32$$5, *_34$$5 = NULL, *_35$$5, *_14$$7 = NULL, *_19$$9 = NULL, *_20$$10 = NULL, *_22$$10 = NULL, *_26$$11 = NULL, *_28$$11 = NULL, *_33$$12 = NULL, **_38$$13, *_39$$14 = NULL, *_40$$14, *_41$$14 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
	zephir_get_global(&_REQUEST, SS("_REQUEST") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &exception);



	ZEPHIR_CALL_FUNCTION(&obLevel, "ob_get_level", NULL, 187);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(obLevel, 0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 142);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_static_property_ce(phalcon_debug_ce, SL("_isActive") TSRMLS_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&_1$$4, exception, "getmessage", NULL, 0);
		zephir_check_call_status();
		zend_print_zval(_1$$4, 0);
		RETURN_MM_NULL();
	}
	zephir_update_static_property_ce(phalcon_debug_ce, SL("_isActive"), &ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, exception, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, exception, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&escapedMessage, this_ptr, "_escapestring", NULL, 0, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(html);
	ZEPHIR_CONCAT_SVSVS(html, "<html><head><title>", className, ": ", escapedMessage, "</title>");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getcsssources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VS(_4, _3, "</head><body>");
	zephir_concat_self(&html, _4 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getversion", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&html, _5 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("<div align=\"center\"><div class=\"error-main\">") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_SVSVS(_6, "<h1>", className, ": ", escapedMessage, "</h1>");
	zephir_concat_self(&html, _6 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_7, exception, "getfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, exception, "getline", NULL, 0);
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
		ZEPHIR_CALL_METHOD(&_10$$5, exception, "gettrace", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(_10$$5, &_12$$5, &_11$$5, 0, 0, "phalcon/debug.zep", 660);
		for (
		  ; zend_hash_get_current_data_ex(_12$$5, (void**) &_13$$5, &_11$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_12$$5, &_11$$5)
		) {
			ZEPHIR_GET_HMKEY(n, _12$$5, _11$$5);
			ZEPHIR_GET_HVALUE(traceItem, _13$$5);
			ZEPHIR_CALL_METHOD(&_14$$7, this_ptr, "showtraceitem", &_15, 188, n, traceItem);
			zephir_check_call_status();
			zephir_concat_self(&html, _14$$7 TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-2\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
		zephir_is_iterable(_REQUEST, &_17$$5, &_16$$5, 0, 0, "phalcon/debug.zep", 674);
		for (
		  ; zend_hash_get_current_data_ex(_17$$5, (void**) &_18$$5, &_16$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_17$$5, &_16$$5)
		) {
			ZEPHIR_GET_HMKEY(keyRequest, _17$$5, _16$$5);
			ZEPHIR_GET_HVALUE(value, _18$$5);
			if (Z_TYPE_P(value) != IS_ARRAY) {
				ZEPHIR_INIT_LNVAR(_19$$9);
				ZEPHIR_CONCAT_SVSVS(_19$$9, "<tr><td class=\"key\">", keyRequest, "</td><td>", value, "</td></tr>");
				zephir_concat_self(&html, _19$$9 TSRMLS_CC);
			} else {
				ZEPHIR_CALL_FUNCTION(&_20$$10, "print_r", &_21, 189, value, ZEPHIR_GLOBAL(global_true));
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_22$$10);
				ZEPHIR_CONCAT_SVSVS(_22$$10, "<tr><td class=\"key\">", keyRequest, "</td><td>", _20$$10, "</td></tr>");
				zephir_concat_self(&html, _22$$10 TSRMLS_CC);
			}
		}
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-3\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
		zephir_is_iterable(_SERVER, &_24$$5, &_23$$5, 0, 0, "phalcon/debug.zep", 684);
		for (
		  ; zend_hash_get_current_data_ex(_24$$5, (void**) &_25$$5, &_23$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_24$$5, &_23$$5)
		) {
			ZEPHIR_GET_HMKEY(keyServer, _24$$5, _23$$5);
			ZEPHIR_GET_HVALUE(value, _25$$5);
			ZEPHIR_CALL_METHOD(&_26$$11, this_ptr, "_getvardump", &_27, 0, value);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_28$$11);
			ZEPHIR_CONCAT_SVSVS(_28$$11, "<tr><td class=\"key\">", keyServer, "</td><td>", _26$$11, "</td></tr>");
			zephir_concat_self(&html, _28$$11 TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-4\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<tr><th>#</th><th>Path</th></tr>") TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_29$$5, "get_included_files", NULL, 190);
		zephir_check_call_status();
		zephir_is_iterable(_29$$5, &_31$$5, &_30$$5, 0, 0, "phalcon/debug.zep", 694);
		for (
		  ; zend_hash_get_current_data_ex(_31$$5, (void**) &_32$$5, &_30$$5) == SUCCESS
		  ; zend_hash_move_forward_ex(_31$$5, &_30$$5)
		) {
			ZEPHIR_GET_HMKEY(keyFile, _31$$5, _30$$5);
			ZEPHIR_GET_HVALUE(value, _32$$5);
			ZEPHIR_INIT_LNVAR(_33$$12);
			ZEPHIR_CONCAT_SVSVS(_33$$12, "<tr><td>", keyFile, "</th><td>", value, "</td></tr>");
			zephir_concat_self(&html, _33$$12 TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-5\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_34$$5, "memory_get_usage", NULL, 191, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_35$$5);
		ZEPHIR_CONCAT_SVS(_35$$5, "<tr><th colspan=\"2\">Memory</th></tr><tr><td>Usage</td><td>", _34$$5, "</td></tr>");
		zephir_concat_self(&html, _35$$5 TSRMLS_CC);
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		if (Z_TYPE_P(dataVars) == IS_ARRAY) {
			zephir_concat_self_str(&html, SL("<div id=\"error-tabs-6\"><table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">") TSRMLS_CC);
			zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
			zephir_is_iterable(dataVars, &_37$$13, &_36$$13, 0, 0, "phalcon/debug.zep", 712);
			for (
			  ; zend_hash_get_current_data_ex(_37$$13, (void**) &_38$$13, &_36$$13) == SUCCESS
			  ; zend_hash_move_forward_ex(_37$$13, &_36$$13)
			) {
				ZEPHIR_GET_HMKEY(keyVar, _37$$13, _36$$13);
				ZEPHIR_GET_HVALUE(dataVar, _38$$13);
				zephir_array_fetch_long(&_40$$14, dataVar, 0, PH_NOISY | PH_READONLY, "phalcon/debug.zep", 710 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_39$$14, this_ptr, "_getvardump", &_27, 0, _40$$14);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_41$$14);
				ZEPHIR_CONCAT_SVSVS(_41$$14, "<tr><td class=\"key\">", keyVar, "</td><td>", _39$$14, "</td></tr>");
				zephir_concat_self(&html, _41$$14 TSRMLS_CC);
			}
			zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</div>") TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_42, this_ptr, "getjssources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_43);
	ZEPHIR_CONCAT_VS(_43, _42, "</div></body></html>");
	zephir_concat_self(&html, _43 TSRMLS_CC);
	zend_print_zval(html, 0);
	zephir_update_static_property_ce(phalcon_debug_ce, SL("_isActive"), &ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

