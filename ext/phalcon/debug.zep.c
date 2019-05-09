
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/time.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Debug
 *
 * Provides debug capabilities to Phalcon applications
 */
ZEPHIR_INIT_CLASS(Phalcon_Debug) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Debug, phalcon, debug, phalcon_debug_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_debug_ce, SL("blacklist"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_debug_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_debug_ce, SL("hideDocumentRoot"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_debug_ce, SL("isActive"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_debug_ce, SL("showBackTrace"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_debug_ce, SL("showFileFragment"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_debug_ce, SL("showFiles"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_debug_ce, SL("uri"), "https://assets.phalconphp.com/debug/4.0.x/", ZEND_ACC_PROTECTED TSRMLS_CC);

	phalcon_debug_ce->create_object = zephir_init_properties_Phalcon_Debug;
	return SUCCESS;

}

/**
 * Clears are variables added previously
 */
PHP_METHOD(Phalcon_Debug, clearVars) {

	zval __$null;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);


	zephir_update_property_zval(this_ptr, SL("data"), &__$null);
	RETURN_THISW();

}

/**
 * Adds a variable to the debug output
 */
PHP_METHOD(Phalcon_Debug, debugVar) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval key;
	zval *varz, varz_sub, *key_param = NULL, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&varz_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &varz, &key_param);

	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
		zephir_get_strval(&key, key_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, varz);
	ZEPHIR_CALL_FUNCTION(&_1, "debug_backtrace", NULL, 171);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_time(&_2);
	zephir_array_fast_append(&_0, &_2);
	zephir_update_property_array_append(this_ptr, SL("data"), &_0 TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the css sources
 */
PHP_METHOD(Phalcon_Debug, getCssSources) {

	zval uri, sources, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&sources);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uri, &_0);
	ZEPHIR_INIT_VAR(&sources);
	ZEPHIR_CONCAT_SVS(&sources, "<link rel='stylesheet' type='text/css' href='", &uri, "bower_components/jquery-ui/themes/ui-lightness/jquery-ui.min.css' />");
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "<link rel='stylesheet' type='text/css' href='", &uri, "bower_components/jquery-ui/themes/ui-lightness/theme.css' />");
	zephir_concat_self(&sources, &_1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "<link rel='stylesheet' type='text/css' href='", &uri, "themes/default/style.css' />");
	zephir_concat_self(&sources, &_2 TSRMLS_CC);
	RETURN_CCTOR(&sources);

}

/**
 * Returns the javascript sources
 */
PHP_METHOD(Phalcon_Debug, getJsSources) {

	zval uri, sources, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&sources);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uri, &_0);
	ZEPHIR_INIT_VAR(&sources);
	ZEPHIR_CONCAT_SVS(&sources, "<script type='text/javascript' src='", &uri, "bower_components/jquery/dist/jquery.min.js'></script>");
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "<script type='text/javascript' src='", &uri, "bower_components/jquery-ui/jquery-ui.min.js'></script>");
	zephir_concat_self(&sources, &_1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_SVS(&_2, "<script type='text/javascript' src='", &uri, "bower_components/jquery.scrollTo/jquery.scrollTo.min.js'></script>");
	zephir_concat_self(&sources, &_2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVS(&_3, "<script type='text/javascript' src='", &uri, "prettify/prettify.js'></script>");
	zephir_concat_self(&sources, &_3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVS(&_4, "<script type='text/javascript' src='", &uri, "pretty.js'></script>");
	zephir_concat_self(&sources, &_4 TSRMLS_CC);
	RETURN_CCTOR(&sources);

}

/**
 * Generates a link to the current version documentation
 */
PHP_METHOD(Phalcon_Debug, getVersion) {

	zval __$false, link, _0, _2, _3, _4, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL, *_7 = NULL;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&link);
	zephir_create_array(&link, 4, 0 TSRMLS_CC);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_version_ce, "getpart", &_1, 0, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_CE_STATIC(&_3, phalcon_version_ce, "getpart", &_1, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVSVS(&_4, "https://docs.phalconphp.com/", &_0, ".", &_3, "/en/");
	zephir_array_update_string(&link, SL("action"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_CE_STATIC(&_5, phalcon_version_ce, "get", &_6, 0);
	zephir_check_call_status();
	zephir_array_update_string(&link, SL("text"), &_5, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&link, SL("local"), &__$false, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&link, SL("target"), SL("_new"));
	ZEPHIR_CALL_CE_STATIC(&_5, phalcon_tag_ce, "linkto", &_7, 0, &link);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVS(return_value, "<div class='version'>Phalcon Framework ", &_5, "</div>");
	RETURN_MM();

}

/**
 * Halts the request showing a backtrace
 */
PHP_METHOD(Phalcon_Debug, halt) {

	zval *this_ptr = getThis();


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_exception_ce, "Halted request", "phalcon/Debug.zep", 139);
	return;

}

/**
 * Listen for uncaught exceptions and unsilent notices or warnings
 */
PHP_METHOD(Phalcon_Debug, listen) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exceptions_param = NULL, *lowSeverity_param = NULL;
	zend_bool exceptions, lowSeverity;
	zval *this_ptr = getThis();


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

	zval _1;
	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "onUncaughtException");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 172, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Listen for unsilent notices or warnings
 */
PHP_METHOD(Phalcon_Debug, listenLowSeverity) {

	zval _1;
	zval _0, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "onUncaughtLowSeverity");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 57, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, this_ptr);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "onUncaughtException");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 172, &_2);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Handles uncaught exceptions
 */
PHP_METHOD(Phalcon_Debug, onUncaughtException) {

	zend_string *_14$$5, *_23$$5, *_33$$5, *_41$$5, *_47$$15;
	zend_ulong _13$$5, _22$$5, _32$$5, _40$$5, _46$$15;
	zephir_fcall_cache_entry *_16 = NULL, *_17 = NULL, *_27 = NULL, *_36 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, __$true, *_REQUEST, *_SERVER, __$false, blacklist, className, dataVar, dataVars, escapedMessage, html, keyFile, keyRequest, keyServer, keyVar, n, showBackTrace, traceItem, obLevel, value, _0, _2, _3, _4, _5, _6, _7, _8, _9, _10, _51, _52, _1$$4, _11$$5, *_12$$5, _18$$5, _19$$5, _20$$5, *_21$$5, _29$$5, _30$$5, *_31$$5, _38$$5, *_39$$5, _43$$5, _44$$5, _15$$7, _24$$8, _25$$10, _26$$11, _28$$11, _34$$12, _35$$13, _37$$13, _42$$14, *_45$$15, _48$$16, _49$$16, _50$$16;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&blacklist);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&dataVar);
	ZVAL_UNDEF(&dataVars);
	ZVAL_UNDEF(&escapedMessage);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&keyFile);
	ZVAL_UNDEF(&keyRequest);
	ZVAL_UNDEF(&keyServer);
	ZVAL_UNDEF(&keyVar);
	ZVAL_UNDEF(&n);
	ZVAL_UNDEF(&showBackTrace);
	ZVAL_UNDEF(&traceItem);
	ZVAL_UNDEF(&obLevel);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_51);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_29$$5);
	ZVAL_UNDEF(&_30$$5);
	ZVAL_UNDEF(&_38$$5);
	ZVAL_UNDEF(&_43$$5);
	ZVAL_UNDEF(&_44$$5);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_34$$12);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_42$$14);
	ZVAL_UNDEF(&_48$$16);
	ZVAL_UNDEF(&_49$$16);
	ZVAL_UNDEF(&_50$$16);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_fetch_params(1, 1, 0, &exception);



	ZEPHIR_CALL_FUNCTION(&obLevel, "ob_get_level", NULL, 173);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&obLevel, 0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 174);
		zephir_check_call_status();
	}
	zephir_read_static_property_ce(&_0, phalcon_debug_ce, SL("isActive"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$4, exception, "getmessage", NULL, 0);
		zephir_check_call_status();
		zend_print_zval(&_1$$4, 0);
		RETURN_MM_NULL();
	}
	zend_update_static_property(phalcon_debug_ce, ZEND_STRL("isActive"), &__$true);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, exception, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, exception, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&escapedMessage, this_ptr, "escapestring", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&html);
	ZEPHIR_CONCAT_SVSVS(&html, "<html><head><title>", &className, ": ", &escapedMessage, "</title>");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getcsssources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VS(&_4, &_3, "</head><body>");
	zephir_concat_self(&html, &_4 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "getversion", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&html, &_5 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("<div align='center'><div class='error-main'>") TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_SVSVS(&_6, "<h1>", &className, ": ", &escapedMessage, "</h1>");
	zephir_concat_self(&html, &_6 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_7, exception, "getfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, exception, "getline", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_SVSVS(&_9, "<span class='error-file'>", &_7, " (", &_8, ")</span>");
	zephir_concat_self(&html, &_9 TSRMLS_CC);
	zephir_concat_self_str(&html, SL("</div>") TSRMLS_CC);
	zephir_read_property(&_10, this_ptr, SL("showBackTrace"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&showBackTrace, &_10);
	if (zephir_is_true(&showBackTrace)) {
		ZEPHIR_OBS_VAR(&dataVars);
		zephir_read_property(&dataVars, this_ptr, SL("data"), PH_NOISY_CC);
		zephir_concat_self_str(&html, SL("<div class='error-info'><div id='tabs'><ul>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<li><a href='#error-tabs-1'>Backtrace</a></li>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<li><a href='#error-tabs-2'>Request</a></li>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<li><a href='#error-tabs-3'>Server</a></li>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<li><a href='#error-tabs-4'>Included Files</a></li>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<li><a href='#error-tabs-5'>Memory</a></li>") TSRMLS_CC);
		if (Z_TYPE_P(&dataVars) == IS_ARRAY) {
			zephir_concat_self_str(&html, SL("<li><a href='#error-tabs-6'>Variables</a></li>") TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</ul>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id='error-tabs-1'><table cellspacing='0' align='center' width='100%'>") TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_11$$5, exception, "gettrace", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&_11$$5, 0, "phalcon/Debug.zep", 283);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_11$$5), _13$$5, _14$$5, _12$$5)
		{
			ZEPHIR_INIT_NVAR(&n);
			if (_14$$5 != NULL) { 
				ZVAL_STR_COPY(&n, _14$$5);
			} else {
				ZVAL_LONG(&n, _13$$5);
			}
			ZEPHIR_INIT_NVAR(&traceItem);
			ZVAL_COPY(&traceItem, _12$$5);
			ZEPHIR_CALL_METHOD(&_15$$7, this_ptr, "showtraceitem", &_16, 175, &n, &traceItem);
			zephir_check_call_status();
			zephir_concat_self(&html, &_15$$7 TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&traceItem);
		ZEPHIR_INIT_NVAR(&n);
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id='error-tabs-2'><table cellspacing='0' align='center' class='superglobal-detail'>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
		zephir_read_property(&_18$$5, this_ptr, SL("blacklist"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_19$$5);
		array_init(&_19$$5);
		ZEPHIR_INIT_VAR(&_20$$5);
		ZVAL_STRING(&_20$$5, "request");
		ZEPHIR_CALL_CE_STATIC(&blacklist, phalcon_helper_arr_ce, "get", &_17, 5, &_18$$5, &_20$$5, &_19$$5);
		zephir_check_call_status();
		zephir_is_iterable(_REQUEST, 0, "phalcon/Debug.zep", 302);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_REQUEST), _22$$5, _23$$5, _21$$5)
		{
			ZEPHIR_INIT_NVAR(&keyRequest);
			if (_23$$5 != NULL) { 
				ZVAL_STR_COPY(&keyRequest, _23$$5);
			} else {
				ZVAL_LONG(&keyRequest, _22$$5);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _21$$5);
			ZEPHIR_INIT_NVAR(&_24$$8);
			zephir_fast_strtolower(&_24$$8, &keyRequest);
			if (1 != zephir_array_isset(&blacklist, &_24$$8)) {
				if (Z_TYPE_P(&value) != IS_ARRAY) {
					ZEPHIR_INIT_LNVAR(_25$$10);
					ZEPHIR_CONCAT_SVSVS(&_25$$10, "<tr><td class='key'>", &keyRequest, "</td><td>", &value, "</td></tr>");
					zephir_concat_self(&html, &_25$$10 TSRMLS_CC);
				} else {
					ZEPHIR_CALL_FUNCTION(&_26$$11, "print_r", &_27, 176, &value, &__$true);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_28$$11);
					ZEPHIR_CONCAT_SVSVS(&_28$$11, "<tr><td class='key'>", &keyRequest, "</td><td>", &_26$$11, "</td></tr>");
					zephir_concat_self(&html, &_28$$11 TSRMLS_CC);
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&keyRequest);
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id='error-tabs-3'><table cellspacing='0' align='center' class='superglobal-detail'>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
		zephir_read_property(&_29$$5, this_ptr, SL("blacklist"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_20$$5);
		array_init(&_20$$5);
		ZEPHIR_INIT_VAR(&_30$$5);
		ZVAL_STRING(&_30$$5, "server");
		ZEPHIR_CALL_CE_STATIC(&blacklist, phalcon_helper_arr_ce, "get", &_17, 5, &_29$$5, &_30$$5, &_20$$5);
		zephir_check_call_status();
		zephir_is_iterable(_SERVER, 0, "phalcon/Debug.zep", 317);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_SERVER), _32$$5, _33$$5, _31$$5)
		{
			ZEPHIR_INIT_NVAR(&keyServer);
			if (_33$$5 != NULL) { 
				ZVAL_STR_COPY(&keyServer, _33$$5);
			} else {
				ZVAL_LONG(&keyServer, _32$$5);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _31$$5);
			ZEPHIR_INIT_NVAR(&_34$$12);
			zephir_fast_strtolower(&_34$$12, &keyServer);
			if (1 != zephir_array_isset(&blacklist, &_34$$12)) {
				ZEPHIR_CALL_METHOD(&_35$$13, this_ptr, "getvardump", &_36, 0, &value);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_37$$13);
				ZEPHIR_CONCAT_SVSVS(&_37$$13, "<tr><td class='key'>", &keyServer, "</td><td>", &_35$$13, "</td></tr>");
				zephir_concat_self(&html, &_37$$13 TSRMLS_CC);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&keyServer);
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id='error-tabs-4'><table cellspacing='0' align='center' class='superglobal-detail'>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<tr><th>#</th><th>Path</th></tr>") TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_38$$5, "get_included_files", NULL, 177);
		zephir_check_call_status();
		zephir_is_iterable(&_38$$5, 0, "phalcon/Debug.zep", 329);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_38$$5), _40$$5, _41$$5, _39$$5)
		{
			ZEPHIR_INIT_NVAR(&keyFile);
			if (_41$$5 != NULL) { 
				ZVAL_STR_COPY(&keyFile, _41$$5);
			} else {
				ZVAL_LONG(&keyFile, _40$$5);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _39$$5);
			ZEPHIR_INIT_LNVAR(_42$$14);
			ZEPHIR_CONCAT_SVSVS(&_42$$14, "<tr><td>", &keyFile, "</th><td>", &value, "</td></tr>");
			zephir_concat_self(&html, &_42$$14 TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&keyFile);
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		zephir_concat_self_str(&html, SL("<div id='error-tabs-5'><table cellspacing='0' align='center' class='superglobal-detail'>") TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_43$$5, "memory_get_usage", NULL, 178, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_44$$5);
		ZEPHIR_CONCAT_SVS(&_44$$5, "<tr><th colspan='2'>Memory</th></tr><tr><td>Usage</td><td>", &_43$$5, "</td></tr>");
		zephir_concat_self(&html, &_44$$5 TSRMLS_CC);
		zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		if (Z_TYPE_P(&dataVars) == IS_ARRAY) {
			zephir_concat_self_str(&html, SL("<div id='error-tabs-6'><table cellspacing='0' align='center' class='superglobal-detail'>") TSRMLS_CC);
			zephir_concat_self_str(&html, SL("<tr><th>Key</th><th>Value</th></tr>") TSRMLS_CC);
			zephir_is_iterable(&dataVars, 0, "phalcon/Debug.zep", 349);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&dataVars), _46$$15, _47$$15, _45$$15)
			{
				ZEPHIR_INIT_NVAR(&keyVar);
				if (_47$$15 != NULL) { 
					ZVAL_STR_COPY(&keyVar, _47$$15);
				} else {
					ZVAL_LONG(&keyVar, _46$$15);
				}
				ZEPHIR_INIT_NVAR(&dataVar);
				ZVAL_COPY(&dataVar, _45$$15);
				zephir_array_fetch_long(&_49$$16, &dataVar, 0, PH_NOISY | PH_READONLY, "phalcon/Debug.zep", 346 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_48$$16, this_ptr, "getvardump", &_36, 0, &_49$$16);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_50$$16);
				ZEPHIR_CONCAT_SVSVS(&_50$$16, "<tr><td class='key'>", &keyVar, "</td><td>", &_48$$16, "</td></tr>");
				zephir_concat_self(&html, &_50$$16 TSRMLS_CC);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&dataVar);
			ZEPHIR_INIT_NVAR(&keyVar);
			zephir_concat_self_str(&html, SL("</table></div>") TSRMLS_CC);
		}
		zephir_concat_self_str(&html, SL("</div>") TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_51, this_ptr, "getjssources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_52);
	ZEPHIR_CONCAT_VS(&_52, &_51, "</div></body></html>");
	zephir_concat_self(&html, &_52 TSRMLS_CC);
	zend_print_zval(&html, 0);
	zend_update_static_property(phalcon_debug_ce, ZEND_STRL("isActive"), &__$false);
	RETURN_MM_BOOL(1);

}

/**
 * Throws an exception when a notice or warning is raised
 */
PHP_METHOD(Phalcon_Debug, onUncaughtLowSeverity) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *severity, severity_sub, *message, message_sub, *file, file_sub, *line, line_sub, *context, context_sub, _0, _1, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&severity_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &severity, &message, &file, &line, &context);



	ZEPHIR_CALL_FUNCTION(&_0, "error_reporting", NULL, 179);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	zephir_bitwise_and_function(&_1, &_0, severity TSRMLS_CC);
	if (UNEXPECTED(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, zephir_get_internal_ce(SL("errorexception")));
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 180, message, &_3$$3, severity, file, line);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Debug.zep", 379 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets if files the exception's backtrace must be showed
 */
PHP_METHOD(Phalcon_Debug, setBlacklist) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *blacklist_param = NULL, area, result, subArray, value, _1, _2, *_3, _5, *_6, _4$$3, _7$$4;
	zval blacklist;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&blacklist);
	ZVAL_UNDEF(&area);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&subArray);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &blacklist_param);

	zephir_get_arrval(&blacklist, blacklist_param);


	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "request");
	ZEPHIR_CALL_CE_STATIC(&area, phalcon_helper_arr_ce, "get", &_0, 5, &blacklist, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&subArray);
	array_init(&subArray);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&area, 0, "phalcon/Debug.zep", 399);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&area), _3)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _3);
		ZEPHIR_INIT_NVAR(&_4$$3);
		zephir_fast_strtolower(&_4$$3, &value);
		ZEPHIR_CPY_WRT(&value, &_4$$3);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_LONG(&_4$$3, 1);
		zephir_array_update_zval(&subArray, &value, &_4$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	zephir_array_update_string(&result, SL("request"), &subArray, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	array_init(&_2);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "server");
	ZEPHIR_CALL_CE_STATIC(&area, phalcon_helper_arr_ce, "get", &_0, 5, &blacklist, &_5, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&subArray);
	array_init(&subArray);
	zephir_is_iterable(&area, 0, "phalcon/Debug.zep", 408);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&area), _6)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _6);
		ZEPHIR_INIT_NVAR(&_7$$4);
		zephir_fast_strtolower(&_7$$4, &value);
		ZEPHIR_CPY_WRT(&value, &_7$$4);
		ZEPHIR_INIT_NVAR(&_7$$4);
		ZVAL_LONG(&_7$$4, 1);
		zephir_array_update_zval(&subArray, &value, &_7$$4, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	zephir_array_update_string(&result, SL("server"), &subArray, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("blacklist"), &result);
	RETURN_THIS();

}

/**
 * Sets if files the exception's backtrace must be showed
 */
PHP_METHOD(Phalcon_Debug, setShowBackTrace) {

	zval *showBackTrace_param = NULL, __$true, __$false;
	zend_bool showBackTrace;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &showBackTrace_param);

	showBackTrace = zephir_get_boolval(showBackTrace_param);


	if (showBackTrace) {
		zephir_update_property_zval(this_ptr, SL("showBackTrace"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("showBackTrace"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Sets if files must be completely opened and showed in the output
 * or just the fragment related to the exception
 */
PHP_METHOD(Phalcon_Debug, setShowFileFragment) {

	zval *showFileFragment_param = NULL, __$true, __$false;
	zend_bool showFileFragment;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &showFileFragment_param);

	showFileFragment = zephir_get_boolval(showFileFragment_param);


	if (showFileFragment) {
		zephir_update_property_zval(this_ptr, SL("showFileFragment"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("showFileFragment"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Set if files part of the backtrace must be shown in the output
 */
PHP_METHOD(Phalcon_Debug, setShowFiles) {

	zval *showFiles_param = NULL, __$true, __$false;
	zend_bool showFiles;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &showFiles_param);

	showFiles = zephir_get_boolval(showFiles_param);


	if (showFiles) {
		zephir_update_property_zval(this_ptr, SL("showFiles"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("showFiles"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Change the base URI for static resources
 */
PHP_METHOD(Phalcon_Debug, setUri) {

	zval *uri_param = NULL;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(&uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_EMPTY_STRING(&uri);
	}


	zephir_update_property_zval(this_ptr, SL("uri"), &uri);
	RETURN_THIS();

}

/**
 * Escapes a string with htmlentities
 */
PHP_METHOD(Phalcon_Debug, escapeString) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "\n");
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "\\n");
		zephir_fast_str_replace(&_0$$3, &_1$$3, &_2$$3, value TSRMLS_CC);
		ZVAL_LONG(&_3$$3, 2);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "utf-8");
		ZEPHIR_RETURN_CALL_FUNCTION("htmlentities", NULL, 181, &_0$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * Produces a recursive representation of an array
 */
PHP_METHOD(Phalcon_Debug, getArrayDump) {

	zend_string *_3;
	zend_ulong _2;
	zend_bool _0;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argument_param = NULL, *n = NULL, n_sub, numberArguments, dump, varDump, k, v, *_1, _5$$8, _6$$8, _8$$9, _9$$5;
	zval argument;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&n_sub);
	ZVAL_UNDEF(&numberArguments);
	ZVAL_UNDEF(&dump);
	ZVAL_UNDEF(&varDump);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &argument_param, &n);

	ZEPHIR_OBS_COPY_OR_DUP(&argument, argument_param);
	if (!n) {
		n = &n_sub;
		ZEPHIR_INIT_VAR(n);
		ZVAL_LONG(n, 0);
	}


	ZEPHIR_INIT_VAR(&numberArguments);
	ZVAL_LONG(&numberArguments, zephir_fast_count_int(&argument TSRMLS_CC));
	_0 = ZEPHIR_GE_LONG(n, 3);
	if (!(_0)) {
		_0 = ZEPHIR_IS_LONG(&numberArguments, 0);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	if (ZEPHIR_GE_LONG(&numberArguments, 10)) {
		RETURN_CCTOR(&numberArguments);
	}
	ZEPHIR_INIT_VAR(&dump);
	array_init(&dump);
	zephir_is_iterable(&argument, 0, "phalcon/Debug.zep", 508);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&argument), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&k);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&k, _3);
		} else {
			ZVAL_LONG(&k, _2);
		}
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _1);
		if (ZEPHIR_IS_STRING(&v, "")) {
			ZEPHIR_INIT_NVAR(&varDump);
			ZVAL_STRING(&varDump, "(empty string)");
		} else if (zephir_is_scalar(&v)) {
			ZEPHIR_CALL_METHOD(&varDump, this_ptr, "escapestring", &_4, 0, &v);
			zephir_check_call_status();
		} else if (Z_TYPE_P(&v) == IS_ARRAY) {
			ZVAL_LONG(&_6$$8, (zephir_get_numberval(n) + 1));
			ZEPHIR_CALL_METHOD(&_5$$8, this_ptr, "getarraydump", &_7, 182, &v, &_6$$8);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&varDump);
			ZEPHIR_CONCAT_SVS(&varDump, "Array(", &_5$$8, ")");
		} else if (Z_TYPE_P(&v) == IS_OBJECT) {
			ZEPHIR_INIT_NVAR(&_8$$9);
			zephir_get_class(&_8$$9, &v, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&varDump);
			ZEPHIR_CONCAT_SVS(&varDump, "Object(", &_8$$9, ")");
		} else if (Z_TYPE_P(&v) == IS_NULL) {
			ZEPHIR_INIT_NVAR(&varDump);
			ZVAL_STRING(&varDump, "null");
		} else {
			ZEPHIR_CPY_WRT(&varDump, &v);
		}
		ZEPHIR_INIT_LNVAR(_9$$5);
		ZEPHIR_CONCAT_SVSV(&_9$$5, "[", &k, "] =&gt; ", &varDump);
		zephir_array_append(&dump, &_9$$5, PH_SEPARATE, "phalcon/Debug.zep", 505);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_fast_join_str(return_value, SL(", "), &dump TSRMLS_CC);
	RETURN_MM();

}

/**
 * Produces an string representation of a variable
 */
PHP_METHOD(Phalcon_Debug, getVarDump) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, className, dumpedObject, _0$$8, _1$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&dumpedObject);
	ZVAL_UNDEF(&_0$$8);
	ZVAL_UNDEF(&_1$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &variable);



	if (ZEPHIR_IS_TRUE(variable)) {
		RETURN_MM_STRING("true");
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(variable)) {
		RETURN_MM_STRING("false");
	}
	if (Z_TYPE_P(variable) == IS_STRING) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "escapestring", NULL, 0, variable);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_is_scalar(variable)) {
		RETVAL_ZVAL(variable, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&className);
		zephir_get_class(&className, variable, 0 TSRMLS_CC);
		if ((zephir_method_exists_ex(variable, SL("dump") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&dumpedObject, variable, "dump", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_0$$8, this_ptr, "getarraydump", NULL, 0, &dumpedObject);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVSVS(return_value, "Object(", &className, ": ", &_0$$8, ")");
			RETURN_MM();
		} else {
			ZEPHIR_CONCAT_SVS(return_value, "Object(", &className, ")");
			RETURN_MM();
		}
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_1$$10, this_ptr, "getarraydump", NULL, 182, variable);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "Array(", &_1$$10, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		RETURN_MM_STRING("null");
	}
	zephir_gettype(return_value, variable TSRMLS_CC);
	RETURN_MM();

}

/**
 * Shows a backtrace item
 */
PHP_METHOD(Phalcon_Debug, showTraceItem) {

	zend_bool _39$$24;
	zval _1, _25$$16;
	zephir_fcall_cache_entry *_20 = NULL, *_46 = NULL;
	zval trace;
	zval *n_param = NULL, *trace_param = NULL, className, prepareInternalClass, preparedFunctionName, html, classReflection, prepareUriClass, functionName, functionReflection, traceArgs, arguments, argument, filez, line, showFiles, lines, numberLines, showFileFragment, firstLine, lastLine, linePosition, currentLine, classNameWithLink, functionNameWithLink, _0, _17, _2$$3, _3$$3, _4$$3, _5$$3, _12$$3, _13$$3, _6$$4, _7$$4, _8$$5, _9$$6, _10$$6, _11$$6, _14$$10, _15$$11, _16$$11, *_18$$14, _22$$14, _23$$14, _19$$15, _21$$15, _24$$16, _26$$16, _27$$16, _28$$17, _29$$18, _30$$23, _31$$26, _32$$26, _33$$26, _34$$26, _35$$26, _36$$27, _37$$27, _38$$27, _40$$29, _41$$29, _42$$29, _43$$29, _44$$29, _45$$29;
	zend_long n, ZEPHIR_LAST_CALL_STATUS, i = 0, beforeLine$$18, afterLine$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&prepareInternalClass);
	ZVAL_UNDEF(&preparedFunctionName);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&classReflection);
	ZVAL_UNDEF(&prepareUriClass);
	ZVAL_UNDEF(&functionName);
	ZVAL_UNDEF(&functionReflection);
	ZVAL_UNDEF(&traceArgs);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&filez);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&showFiles);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&numberLines);
	ZVAL_UNDEF(&showFileFragment);
	ZVAL_UNDEF(&firstLine);
	ZVAL_UNDEF(&lastLine);
	ZVAL_UNDEF(&linePosition);
	ZVAL_UNDEF(&currentLine);
	ZVAL_UNDEF(&classNameWithLink);
	ZVAL_UNDEF(&functionNameWithLink);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_30$$23);
	ZVAL_UNDEF(&_31$$26);
	ZVAL_UNDEF(&_32$$26);
	ZVAL_UNDEF(&_33$$26);
	ZVAL_UNDEF(&_34$$26);
	ZVAL_UNDEF(&_35$$26);
	ZVAL_UNDEF(&_36$$27);
	ZVAL_UNDEF(&_37$$27);
	ZVAL_UNDEF(&_38$$27);
	ZVAL_UNDEF(&_40$$29);
	ZVAL_UNDEF(&_41$$29);
	ZVAL_UNDEF(&_42$$29);
	ZVAL_UNDEF(&_43$$29);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_45$$29);
	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_25$$16);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &n_param, &trace_param);

	n = zephir_get_intval(n_param);
	ZEPHIR_OBS_COPY_OR_DUP(&trace, trace_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, n);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "<tr><td align='right' valign='top' class='error-number'>#", &_0, "</td><td>");
	ZEPHIR_CPY_WRT(&html, &_1);
	ZEPHIR_OBS_VAR(&className);
	if (zephir_array_isset_string_fetch(&className, &trace, SL("class"), 0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "/^Phalcon/");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "/^Phalcon/");
		zephir_preg_match(&_4$$3, &_5$$3, &className, &_2$$3, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(&_4$$3)) {
			ZEPHIR_INIT_VAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "\\");
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "_");
			ZEPHIR_INIT_VAR(&prepareUriClass);
			zephir_fast_str_replace(&prepareUriClass, &_6$$4, &_7$$4, &className TSRMLS_CC);
			ZEPHIR_INIT_VAR(&classNameWithLink);
			ZEPHIR_CONCAT_SVSVS(&classNameWithLink, "<a target='_new' href='https://docs.phalconphp.com/4.0/en/api/", &prepareUriClass, "'>", &className, "</a>");
		} else {
			ZEPHIR_INIT_VAR(&classReflection);
			object_init_ex(&classReflection, zephir_get_internal_ce(SL("reflectionclass")));
			ZEPHIR_CALL_METHOD(NULL, &classReflection, "__construct", NULL, 120, &className);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8$$5, &classReflection, "isinternal", NULL, 183);
			zephir_check_call_status();
			if (zephir_is_true(&_8$$5)) {
				ZEPHIR_INIT_VAR(&_9$$6);
				zephir_fast_strtolower(&_9$$6, &className);
				ZEPHIR_INIT_VAR(&_10$$6);
				ZVAL_STRING(&_10$$6, "_");
				ZEPHIR_INIT_VAR(&_11$$6);
				ZVAL_STRING(&_11$$6, "-");
				ZEPHIR_INIT_VAR(&prepareInternalClass);
				zephir_fast_str_replace(&prepareInternalClass, &_10$$6, &_11$$6, &_9$$6 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&classNameWithLink);
				ZEPHIR_CONCAT_SVSVS(&classNameWithLink, "<a target='_new' href='https://secure.php.net/manual/en/class.", &prepareInternalClass, ".php'>", &className, "</a>");
			} else {
				ZEPHIR_CPY_WRT(&classNameWithLink, &className);
			}
		}
		ZEPHIR_INIT_VAR(&_12$$3);
		ZEPHIR_CONCAT_SVS(&_12$$3, "<span class='error-class'>", &classNameWithLink, "</span>");
		zephir_concat_self(&html, &_12$$3 TSRMLS_CC);
		zephir_array_fetch_string(&_13$$3, &trace, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Debug.zep", 646 TSRMLS_CC);
		zephir_concat_self(&html, &_13$$3 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&functionName);
	zephir_array_fetch_string(&functionName, &trace, SL("function"), PH_NOISY, "phalcon/Debug.zep", 652 TSRMLS_CC);
	if (zephir_array_isset_string(&trace, SL("class"))) {
		ZEPHIR_CPY_WRT(&functionNameWithLink, &functionName);
	} else {
		if ((zephir_function_exists(&functionName TSRMLS_CC)  == SUCCESS)) {
			ZEPHIR_INIT_VAR(&functionReflection);
			object_init_ex(&functionReflection, zephir_get_internal_ce(SL("reflectionfunction")));
			ZEPHIR_CALL_METHOD(NULL, &functionReflection, "__construct", NULL, 115, &functionName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_14$$10, &functionReflection, "isinternal", NULL, 184);
			zephir_check_call_status();
			if (zephir_is_true(&_14$$10)) {
				ZEPHIR_INIT_VAR(&_15$$11);
				ZVAL_STRING(&_15$$11, "_");
				ZEPHIR_INIT_VAR(&_16$$11);
				ZVAL_STRING(&_16$$11, "-");
				ZEPHIR_INIT_VAR(&preparedFunctionName);
				zephir_fast_str_replace(&preparedFunctionName, &_15$$11, &_16$$11, &functionName TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&functionNameWithLink);
				ZEPHIR_CONCAT_SVSVS(&functionNameWithLink, "<a target='_new' href='https://secure.php.net/manual/en/function.", &preparedFunctionName, ".php'>", &functionName, "</a>");
			} else {
				ZEPHIR_CPY_WRT(&functionNameWithLink, &functionName);
			}
		} else {
			ZEPHIR_CPY_WRT(&functionNameWithLink, &functionName);
		}
	}
	ZEPHIR_INIT_VAR(&_17);
	ZEPHIR_CONCAT_SVS(&_17, "<span class='error-function'>", &functionNameWithLink, "</span>");
	zephir_concat_self(&html, &_17 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&traceArgs);
	if (zephir_array_isset_string_fetch(&traceArgs, &trace, SL("args"), 0)) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
		zephir_is_iterable(&traceArgs, 0, "phalcon/Debug.zep", 704);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&traceArgs), _18$$14)
		{
			ZEPHIR_INIT_NVAR(&argument);
			ZVAL_COPY(&argument, _18$$14);
			ZEPHIR_CALL_METHOD(&_19$$15, this_ptr, "getvardump", &_20, 0, &argument);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_21$$15);
			ZEPHIR_CONCAT_SVS(&_21$$15, "<span class='error-parameter'>", &_19$$15, "</span>");
			zephir_array_append(&arguments, &_21$$15, PH_SEPARATE, "phalcon/Debug.zep", 698);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&argument);
		ZEPHIR_INIT_VAR(&_22$$14);
		zephir_fast_join_str(&_22$$14, SL(", "), &arguments TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_23$$14);
		ZEPHIR_CONCAT_SVS(&_23$$14, "(", &_22$$14, ")");
		zephir_concat_self(&html, &_23$$14 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(&filez);
	if (zephir_array_isset_string_fetch(&filez, &trace, SL("file"), 0)) {
		ZEPHIR_OBS_VAR(&_24$$16);
		zephir_array_fetch_string(&_24$$16, &trace, SL("line"), PH_NOISY, "phalcon/Debug.zep", 712 TSRMLS_CC);
		zephir_get_strval(&_25$$16, &_24$$16);
		ZEPHIR_CPY_WRT(&line, &_25$$16);
		ZEPHIR_INIT_VAR(&_26$$16);
		ZEPHIR_CONCAT_SVSVS(&_26$$16, "<br/><div class='error-file'>", &filez, " (", &line, ")</div>");
		zephir_concat_self(&html, &_26$$16 TSRMLS_CC);
		zephir_read_property(&_27$$16, this_ptr, SL("showFiles"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&showFiles, &_27$$16);
		if (zephir_is_true(&showFiles)) {
			ZEPHIR_CALL_FUNCTION(&lines, "file", NULL, 185, &filez);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&numberLines);
			ZVAL_LONG(&numberLines, zephir_fast_count_int(&lines TSRMLS_CC));
			zephir_read_property(&_28$$17, this_ptr, SL("showFileFragment"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&showFileFragment, &_28$$17);
			if (zephir_is_true(&showFileFragment)) {
				beforeLine$$18 = (zephir_get_numberval(&line) - 7);
				if (beforeLine$$18 < 1) {
					ZEPHIR_INIT_VAR(&firstLine);
					ZVAL_LONG(&firstLine, 1);
				} else {
					ZEPHIR_INIT_NVAR(&firstLine);
					ZVAL_LONG(&firstLine, beforeLine$$18);
				}
				afterLine$$18 = (zephir_get_numberval(&line) + 5);
				if (ZEPHIR_LT_LONG(&numberLines, afterLine$$18)) {
					ZEPHIR_CPY_WRT(&lastLine, &numberLines);
				} else {
					ZEPHIR_INIT_NVAR(&lastLine);
					ZVAL_LONG(&lastLine, afterLine$$18);
				}
				ZEPHIR_INIT_VAR(&_29$$18);
				ZEPHIR_CONCAT_SVSVSVS(&_29$$18, "<pre class='prettyprint highlight:", &firstLine, ":", &line, " linenums:", &firstLine, "'>");
				zephir_concat_self(&html, &_29$$18 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(&firstLine);
				ZVAL_LONG(&firstLine, 1);
				ZEPHIR_CPY_WRT(&lastLine, &numberLines);
				ZEPHIR_INIT_VAR(&_30$$23);
				ZEPHIR_CONCAT_SVSVS(&_30$$23, "<pre class='prettyprint highlight:", &firstLine, ":", &line, " linenums error-scroll'>");
				zephir_concat_self(&html, &_30$$23 TSRMLS_CC);
			}
			i = zephir_get_numberval(&firstLine);
			while (1) {
				if (!(ZEPHIR_GE_LONG(&lastLine, i))) {
					break;
				}
				ZEPHIR_INIT_NVAR(&linePosition);
				ZVAL_LONG(&linePosition, (i - 1));
				ZEPHIR_OBS_NVAR(&currentLine);
				zephir_array_fetch(&currentLine, &lines, &linePosition, PH_NOISY, "phalcon/Debug.zep", 785 TSRMLS_CC);
				if (zephir_is_true(&showFileFragment)) {
					if (ZEPHIR_IS_LONG(&firstLine, i)) {
						ZEPHIR_INIT_NVAR(&_31$$26);
						ZEPHIR_INIT_NVAR(&_32$$26);
						zephir_fast_trim(&_32$$26, &currentLine, NULL , ZEPHIR_TRIM_RIGHT TSRMLS_CC);
						ZEPHIR_INIT_NVAR(&_33$$26);
						ZVAL_STRING(&_33$$26, "#\\*\\/#");
						ZEPHIR_INIT_NVAR(&_34$$26);
						ZEPHIR_INIT_NVAR(&_35$$26);
						ZVAL_STRING(&_35$$26, "#\\*\\/#");
						zephir_preg_match(&_34$$26, &_35$$26, &_32$$26, &_31$$26, 0, 0 , 0  TSRMLS_CC);
						if (zephir_is_true(&_34$$26)) {
							ZEPHIR_INIT_NVAR(&_36$$27);
							ZEPHIR_INIT_NVAR(&_37$$27);
							ZVAL_STRING(&_37$$27, "* /");
							ZEPHIR_INIT_NVAR(&_38$$27);
							ZVAL_STRING(&_38$$27, " ");
							zephir_fast_str_replace(&_36$$27, &_37$$27, &_38$$27, &currentLine TSRMLS_CC);
							ZEPHIR_CPY_WRT(&currentLine, &_36$$27);
						}
					}
				}
				_39$$24 = ZEPHIR_IS_STRING(&currentLine, "\n");
				if (!(_39$$24)) {
					_39$$24 = ZEPHIR_IS_STRING(&currentLine, "\r\n");
				}
				if (_39$$24) {
					zephir_concat_self_str(&html, SL("&nbsp;\n") TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(&_40$$29);
					ZEPHIR_INIT_NVAR(&_41$$29);
					ZVAL_STRING(&_41$$29, "\t");
					ZEPHIR_INIT_NVAR(&_42$$29);
					ZVAL_STRING(&_42$$29, "  ");
					zephir_fast_str_replace(&_40$$29, &_41$$29, &_42$$29, &currentLine TSRMLS_CC);
					ZVAL_LONG(&_43$$29, 2);
					ZEPHIR_INIT_NVAR(&_44$$29);
					ZVAL_STRING(&_44$$29, "UTF-8");
					ZEPHIR_CALL_FUNCTION(&_45$$29, "htmlentities", &_46, 181, &_40$$29, &_43$$29, &_44$$29);
					zephir_check_call_status();
					zephir_concat_self(&html, &_45$$29 TSRMLS_CC);
				}
				i++;
			}
			zephir_concat_self_str(&html, SL("</pre>") TSRMLS_CC);
		}
	}
	zephir_concat_self_str(&html, SL("</td></tr>") TSRMLS_CC);
	RETURN_CCTOR(&html);

}

zend_object *zephir_init_properties_Phalcon_Debug(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0, _2$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("blacklist"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_2$$3);
			array_init(&_2$$3);
			zephir_array_update_string(&_1$$3, SL("request"), &_2$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_2$$3);
			array_init(&_2$$3);
			zephir_array_update_string(&_1$$3, SL("server"), &_2$$3, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("blacklist"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

