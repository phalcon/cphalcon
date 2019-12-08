
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
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Provides debug capabilities to Phalcon applications
 */
ZEPHIR_INIT_CLASS(Phalcon_Debug) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Debug, phalcon, debug, phalcon_debug_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_debug_ce, SL("blacklist"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_debug_ce, SL("data"), ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_debug_ce, SL("hideDocumentRoot"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_debug_ce, SL("isActive"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_debug_ce, SL("showBackTrace"), 1, ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_debug_ce, SL("showFileFragment"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_debug_ce, SL("showFiles"), 1, ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_debug_ce, SL("uri"), "https://assets.phalcon.io/debug/4.0.x/", ZEND_ACC_PROTECTED);

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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_create_array(&_0, 3, 0);
	zephir_array_fast_append(&_0, varz);
	ZEPHIR_CALL_FUNCTION(&_1, "debug_backtrace", NULL, 194);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_time(&_2);
	zephir_array_fast_append(&_0, &_2);
	zephir_update_property_array_append(this_ptr, SL("data"), &_0);
	RETURN_THIS();

}

/**
 * Returns the css sources
 */
PHP_METHOD(Phalcon_Debug, getCssSources) {

	zval uri, sources, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&sources);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uri, &_0);
	ZEPHIR_INIT_VAR(&sources);
	ZEPHIR_CONCAT_SVSSVSSVS(&sources, "<link rel='stylesheet' type='text/css' href='", &uri, "bower_components/jquery-ui/themes/ui-lightness/jquery-ui.min.css' />", "<link rel='stylesheet' type='text/css' href='", &uri, "bower_components/jquery-ui/themes/ui-lightness/theme.css' />", "<link rel='stylesheet' type='text/css' href='", &uri, "themes/default/style.css' />");
	RETURN_CCTOR(&sources);

}

/**
 * Returns the javascript sources
 */
PHP_METHOD(Phalcon_Debug, getJsSources) {

	zval uri, sources, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&sources);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uri, &_0);
	ZEPHIR_INIT_VAR(&sources);
	ZEPHIR_CONCAT_SVSSVSSVSSVSSVS(&sources, "<script type='text/javascript' src='", &uri, "bower_components/jquery/dist/jquery.min.js'></script>", "<script type='text/javascript' src='", &uri, "bower_components/jquery-ui/jquery-ui.min.js'></script>", "<script type='text/javascript' src='", &uri, "bower_components/jquery.scrollTo/jquery.scrollTo.min.js'></script>", "<script type='text/javascript' src='", &uri, "prettify/prettify.js'></script>", "<script type='text/javascript' src='", &uri, "pretty.js'></script>");
	RETURN_CCTOR(&sources);

}

/**
 * Generates a link to the current version documentation
 */
PHP_METHOD(Phalcon_Debug, getVersion) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_create_array(&link, 4, 0);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_version_ce, "getpart", &_1, 0, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 1);
	ZEPHIR_CALL_CE_STATIC(&_3, phalcon_version_ce, "getpart", &_1, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVSVS(&_4, "https://docs.phalcon.io/", &_0, ".", &_3, "/en/");
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


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_exception_ce, "Halted request", "phalcon/Debug.zep", 150);
	return;

}

/**
 * Listen for uncaught exceptions and unsilent notices or warnings
 */
PHP_METHOD(Phalcon_Debug, listen) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "onUncaughtException");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 195, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Listen for unsilent notices or warnings
 */
PHP_METHOD(Phalcon_Debug, listenLowSeverity) {

	zval _1;
	zval _0, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "onUncaughtLowSeverity");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 83, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_fast_append(&_2, this_ptr);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "onUncaughtException");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 195, &_2);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Handles uncaught exceptions
 */
PHP_METHOD(Phalcon_Debug, onUncaughtException) {

	zend_string *_14$$5, *_26$$5, *_42$$5, *_55$$5, *_64$$23;
	zend_ulong _13$$5, _25$$5, _41$$5, _54$$5, _63$$23;
	zval _9$$5, _18$$5, _36$$5, _50$$5, _60$$23;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_16 = NULL, *_19 = NULL, *_30 = NULL, *_45 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, __$true, _REQUEST, _SERVER, __$false, blacklist, className, dataVar, dataVars, escapedMessage, html, keyFile, keyRequest, keyServer, keyVar, n, showBackTrace, traceItem, obLevel, value, _0, _2, _3, _4, _5, _6, _7, _8, _71, _72, _1$$4, _10$$5, *_11$$5, _12$$5, _20$$5, _21$$5, _22$$5, *_23$$5, _24$$5, _37$$5, _38$$5, *_39$$5, _40$$5, _51$$5, *_52$$5, _53$$5, _58$$5, _59$$5, _15$$7, _17$$8, _27$$9, _28$$11, _29$$12, _31$$12, _32$$13, _33$$15, _34$$16, _35$$16, _43$$17, _44$$18, _46$$18, _47$$19, _48$$20, _49$$20, _56$$21, _57$$22, *_61$$23, _62$$23, _65$$24, _66$$24, _67$$24, _68$$25, _69$$25, _70$$25;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_UNDEF(&_SERVER);
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
	ZVAL_UNDEF(&_71);
	ZVAL_UNDEF(&_72);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_37$$5);
	ZVAL_UNDEF(&_38$$5);
	ZVAL_UNDEF(&_40$$5);
	ZVAL_UNDEF(&_51$$5);
	ZVAL_UNDEF(&_53$$5);
	ZVAL_UNDEF(&_58$$5);
	ZVAL_UNDEF(&_59$$5);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$15);
	ZVAL_UNDEF(&_34$$16);
	ZVAL_UNDEF(&_35$$16);
	ZVAL_UNDEF(&_43$$17);
	ZVAL_UNDEF(&_44$$18);
	ZVAL_UNDEF(&_46$$18);
	ZVAL_UNDEF(&_47$$19);
	ZVAL_UNDEF(&_48$$20);
	ZVAL_UNDEF(&_49$$20);
	ZVAL_UNDEF(&_56$$21);
	ZVAL_UNDEF(&_57$$22);
	ZVAL_UNDEF(&_62$$23);
	ZVAL_UNDEF(&_65$$24);
	ZVAL_UNDEF(&_66$$24);
	ZVAL_UNDEF(&_67$$24);
	ZVAL_UNDEF(&_68$$25);
	ZVAL_UNDEF(&_69$$25);
	ZVAL_UNDEF(&_70$$25);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_36$$5);
	ZVAL_UNDEF(&_50$$5);
	ZVAL_UNDEF(&_60$$23);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_fetch_params(1, 1, 0, &exception);



	ZEPHIR_CALL_FUNCTION(&obLevel, "ob_get_level", NULL, 196);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&obLevel, 0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 197);
		zephir_check_call_status();
	}
	zephir_read_static_property_ce(&_0, phalcon_debug_ce, SL("isActive"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$4, exception, "getmessage", NULL, 0);
		zephir_check_call_status();
		zend_print_zval(&_1$$4, 0);
		RETURN_MM_NULL();
	}
	zephir_update_static_property_ce(phalcon_debug_ce, ZEND_STRL("isActive"), &__$true);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, exception, 0);
	ZEPHIR_CALL_METHOD(&_2, exception, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&escapedMessage, this_ptr, "escapestring", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getcsssources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&html);
	ZEPHIR_CONCAT_SSVSVSVS(&html, "<html><head>", "<title>", &className, ": ", &escapedMessage, "</title>", &_3, "</head><body>");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getversion", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&html, &_4);
	ZEPHIR_CALL_METHOD(&_5, exception, "getfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, exception, "getline", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SSSVSVSSVSVSS(&_7, "<div align='center'>", "<div class='error-main'>", "<h1>", &className, ": ", &escapedMessage, "</h1>", "<span class='error-file'>", &_5, " (", &_6, ")</span>", "</div>");
	zephir_concat_self(&html, &_7);
	zephir_read_property(&_8, this_ptr, SL("showBackTrace"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&showBackTrace, &_8);
	if (zephir_is_true(&showBackTrace)) {
		ZEPHIR_OBS_VAR(&dataVars);
		zephir_read_property(&dataVars, this_ptr, SL("data"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_9$$5);
		ZEPHIR_CONCAT_SSSSSS(&_9$$5, "<div class='error-info'><div id='tabs'><ul>", "<li><a href='#error-tabs-1'>Backtrace</a></li>", "<li><a href='#error-tabs-2'>Request</a></li>", "<li><a href='#error-tabs-3'>Server</a></li>", "<li><a href='#error-tabs-4'>Included Files</a></li>", "<li><a href='#error-tabs-5'>Memory</a></li>");
		zephir_concat_self(&html, &_9$$5);
		if (Z_TYPE_P(&dataVars) == IS_ARRAY) {
			zephir_concat_self_str(&html, SL("<li><a href='#error-tabs-6'>Variables</a></li>"));
		}
		zephir_concat_self_str(&html, SL("</ul>"));
		zephir_concat_self_str(&html, SL("<div id='error-tabs-1'><table cellspacing='0' align='center' width='100%'>"));
		ZEPHIR_CALL_METHOD(&_10$$5, exception, "gettrace", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&_10$$5, 0, "phalcon/Debug.zep", 297);
		if (Z_TYPE_P(&_10$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_10$$5), _13$$5, _14$$5, _11$$5)
			{
				ZEPHIR_INIT_NVAR(&n);
				if (_14$$5 != NULL) { 
					ZVAL_STR_COPY(&n, _14$$5);
				} else {
					ZVAL_LONG(&n, _13$$5);
				}
				ZEPHIR_INIT_NVAR(&traceItem);
				ZVAL_COPY(&traceItem, _11$$5);
				ZEPHIR_CALL_METHOD(&_15$$7, this_ptr, "showtraceitem", &_16, 198, &n, &traceItem);
				zephir_check_call_status();
				zephir_concat_self(&html, &_15$$7);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_10$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_12$$5, &_10$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_12$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&n, &_10$$5, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&traceItem, &_10$$5, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_17$$8, this_ptr, "showtraceitem", &_16, 198, &n, &traceItem);
					zephir_check_call_status();
					zephir_concat_self(&html, &_17$$8);
				ZEPHIR_CALL_METHOD(NULL, &_10$$5, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&traceItem);
		ZEPHIR_INIT_NVAR(&n);
		zephir_concat_self_str(&html, SL("</table></div>"));
		ZEPHIR_INIT_VAR(&_18$$5);
		ZEPHIR_CONCAT_SSS(&_18$$5, "<div id='error-tabs-2'>", "<table cellspacing='0' align='center' class='superglobal-detail'>", "<tr><th>Key</th><th>Value</th></tr>");
		zephir_concat_self(&html, &_18$$5);
		zephir_read_property(&_20$$5, this_ptr, SL("blacklist"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_21$$5);
		array_init(&_21$$5);
		ZEPHIR_INIT_VAR(&_22$$5);
		ZVAL_STRING(&_22$$5, "request");
		ZEPHIR_CALL_CE_STATIC(&blacklist, phalcon_helper_arr_ce, "get", &_19, 15, &_20$$5, &_22$$5, &_21$$5);
		zephir_check_call_status();
		zephir_is_iterable(&_REQUEST, 0, "phalcon/Debug.zep", 317);
		if (Z_TYPE_P(&_REQUEST) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_REQUEST), _25$$5, _26$$5, _23$$5)
			{
				ZEPHIR_INIT_NVAR(&keyRequest);
				if (_26$$5 != NULL) { 
					ZVAL_STR_COPY(&keyRequest, _26$$5);
				} else {
					ZVAL_LONG(&keyRequest, _25$$5);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _23$$5);
				ZEPHIR_INIT_NVAR(&_27$$9);
				zephir_fast_strtolower(&_27$$9, &keyRequest);
				if (1 != zephir_array_isset(&blacklist, &_27$$9)) {
					if (Z_TYPE_P(&value) != IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_28$$11);
						ZEPHIR_CONCAT_SVSVS(&_28$$11, "<tr><td class='key'>", &keyRequest, "</td><td>", &value, "</td></tr>");
						zephir_concat_self(&html, &_28$$11);
					} else {
						ZEPHIR_CALL_FUNCTION(&_29$$12, "print_r", &_30, 199, &value, &__$true);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_31$$12);
						ZEPHIR_CONCAT_SVSVS(&_31$$12, "<tr><td class='key'>", &keyRequest, "</td><td>", &_29$$12, "</td></tr>");
						zephir_concat_self(&html, &_31$$12);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_REQUEST, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_24$$5, &_REQUEST, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_24$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&keyRequest, &_REQUEST, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &_REQUEST, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_32$$13);
					zephir_fast_strtolower(&_32$$13, &keyRequest);
					if (1 != zephir_array_isset(&blacklist, &_32$$13)) {
						if (Z_TYPE_P(&value) != IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_33$$15);
							ZEPHIR_CONCAT_SVSVS(&_33$$15, "<tr><td class='key'>", &keyRequest, "</td><td>", &value, "</td></tr>");
							zephir_concat_self(&html, &_33$$15);
						} else {
							ZEPHIR_CALL_FUNCTION(&_34$$16, "print_r", &_30, 199, &value, &__$true);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_35$$16);
							ZEPHIR_CONCAT_SVSVS(&_35$$16, "<tr><td class='key'>", &keyRequest, "</td><td>", &_34$$16, "</td></tr>");
							zephir_concat_self(&html, &_35$$16);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &_REQUEST, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&keyRequest);
		zephir_concat_self_str(&html, SL("</table></div>"));
		ZEPHIR_INIT_VAR(&_36$$5);
		ZEPHIR_CONCAT_SSS(&_36$$5, "<div id='error-tabs-3'>", "<table cellspacing='0' align='center' class='superglobal-detail'>", "<tr><th>Key</th><th>Value</th></tr>");
		zephir_concat_self(&html, &_36$$5);
		zephir_read_property(&_37$$5, this_ptr, SL("blacklist"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_22$$5);
		array_init(&_22$$5);
		ZEPHIR_INIT_VAR(&_38$$5);
		ZVAL_STRING(&_38$$5, "server");
		ZEPHIR_CALL_CE_STATIC(&blacklist, phalcon_helper_arr_ce, "get", &_19, 15, &_37$$5, &_38$$5, &_22$$5);
		zephir_check_call_status();
		zephir_is_iterable(&_SERVER, 0, "phalcon/Debug.zep", 333);
		if (Z_TYPE_P(&_SERVER) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_SERVER), _41$$5, _42$$5, _39$$5)
			{
				ZEPHIR_INIT_NVAR(&keyServer);
				if (_42$$5 != NULL) { 
					ZVAL_STR_COPY(&keyServer, _42$$5);
				} else {
					ZVAL_LONG(&keyServer, _41$$5);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _39$$5);
				ZEPHIR_INIT_NVAR(&_43$$17);
				zephir_fast_strtolower(&_43$$17, &keyServer);
				if (1 != zephir_array_isset(&blacklist, &_43$$17)) {
					ZEPHIR_CALL_METHOD(&_44$$18, this_ptr, "getvardump", &_45, 0, &value);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_46$$18);
					ZEPHIR_CONCAT_SVSVS(&_46$$18, "<tr><td class='key'>", &keyServer, "</td><td>", &_44$$18, "</td></tr>");
					zephir_concat_self(&html, &_46$$18);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_SERVER, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_40$$5, &_SERVER, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_40$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&keyServer, &_SERVER, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &_SERVER, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_47$$19);
					zephir_fast_strtolower(&_47$$19, &keyServer);
					if (1 != zephir_array_isset(&blacklist, &_47$$19)) {
						ZEPHIR_CALL_METHOD(&_48$$20, this_ptr, "getvardump", &_45, 0, &value);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_49$$20);
						ZEPHIR_CONCAT_SVSVS(&_49$$20, "<tr><td class='key'>", &keyServer, "</td><td>", &_48$$20, "</td></tr>");
						zephir_concat_self(&html, &_49$$20);
					}
				ZEPHIR_CALL_METHOD(NULL, &_SERVER, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&keyServer);
		zephir_concat_self_str(&html, SL("</table></div>"));
		ZEPHIR_INIT_VAR(&_50$$5);
		ZEPHIR_CONCAT_SSS(&_50$$5, "<div id='error-tabs-4'>", "<table cellspacing='0' align='center' class='superglobal-detail'>", "<tr><th>#</th><th>Path</th></tr>");
		zephir_concat_self(&html, &_50$$5);
		ZEPHIR_CALL_FUNCTION(&_51$$5, "get_included_files", NULL, 200);
		zephir_check_call_status();
		zephir_is_iterable(&_51$$5, 0, "phalcon/Debug.zep", 346);
		if (Z_TYPE_P(&_51$$5) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_51$$5), _54$$5, _55$$5, _52$$5)
			{
				ZEPHIR_INIT_NVAR(&keyFile);
				if (_55$$5 != NULL) { 
					ZVAL_STR_COPY(&keyFile, _55$$5);
				} else {
					ZVAL_LONG(&keyFile, _54$$5);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _52$$5);
				ZEPHIR_INIT_NVAR(&_56$$21);
				ZEPHIR_CONCAT_SVSVS(&_56$$21, "<tr><td>", &keyFile, "</th><td>", &value, "</td></tr>");
				zephir_concat_self(&html, &_56$$21);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_51$$5, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_53$$5, &_51$$5, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_53$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&keyFile, &_51$$5, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &_51$$5, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_57$$22);
					ZEPHIR_CONCAT_SVSVS(&_57$$22, "<tr><td>", &keyFile, "</th><td>", &value, "</td></tr>");
					zephir_concat_self(&html, &_57$$22);
				ZEPHIR_CALL_METHOD(NULL, &_51$$5, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&keyFile);
		zephir_concat_self_str(&html, SL("</table></div>"));
		ZEPHIR_CALL_FUNCTION(&_58$$5, "memory_get_usage", NULL, 201, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_59$$5);
		ZEPHIR_CONCAT_SSSVSS(&_59$$5, "<div id='error-tabs-5'>", "<table cellspacing='0' align='center' class='superglobal-detail'>", "<tr><th colspan='2'>Memory</th></tr><tr><td>Usage</td><td>", &_58$$5, "</td></tr>", "</table></div>");
		zephir_concat_self(&html, &_59$$5);
		if (Z_TYPE_P(&dataVars) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_60$$23);
			ZEPHIR_CONCAT_SSS(&_60$$23, "<div id='error-tabs-6'>", "<table cellspacing='0' align='center' class='superglobal-detail'>", "<tr><th>Key</th><th>Value</th></tr>");
			zephir_concat_self(&html, &_60$$23);
			zephir_is_iterable(&dataVars, 0, "phalcon/Debug.zep", 368);
			if (Z_TYPE_P(&dataVars) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&dataVars), _63$$23, _64$$23, _61$$23)
				{
					ZEPHIR_INIT_NVAR(&keyVar);
					if (_64$$23 != NULL) { 
						ZVAL_STR_COPY(&keyVar, _64$$23);
					} else {
						ZVAL_LONG(&keyVar, _63$$23);
					}
					ZEPHIR_INIT_NVAR(&dataVar);
					ZVAL_COPY(&dataVar, _61$$23);
					zephir_array_fetch_long(&_66$$24, &dataVar, 0, PH_NOISY | PH_READONLY, "phalcon/Debug.zep", 365);
					ZEPHIR_CALL_METHOD(&_65$$24, this_ptr, "getvardump", &_45, 0, &_66$$24);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_67$$24);
					ZEPHIR_CONCAT_SVSVS(&_67$$24, "<tr><td class='key'>", &keyVar, "</td><td>", &_65$$24, "</td></tr>");
					zephir_concat_self(&html, &_67$$24);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &dataVars, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_62$$23, &dataVars, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_62$$23)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&keyVar, &dataVars, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&dataVar, &dataVars, "current", NULL, 0);
					zephir_check_call_status();
						zephir_array_fetch_long(&_69$$25, &dataVar, 0, PH_NOISY | PH_READONLY, "phalcon/Debug.zep", 365);
						ZEPHIR_CALL_METHOD(&_68$$25, this_ptr, "getvardump", &_45, 0, &_69$$25);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_70$$25);
						ZEPHIR_CONCAT_SVSVS(&_70$$25, "<tr><td class='key'>", &keyVar, "</td><td>", &_68$$25, "</td></tr>");
						zephir_concat_self(&html, &_70$$25);
					ZEPHIR_CALL_METHOD(NULL, &dataVars, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&dataVar);
			ZEPHIR_INIT_NVAR(&keyVar);
			zephir_concat_self_str(&html, SL("</table></div>"));
		}
		zephir_concat_self_str(&html, SL("</div>"));
	}
	ZEPHIR_CALL_METHOD(&_71, this_ptr, "getjssources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_72);
	ZEPHIR_CONCAT_VS(&_72, &_71, "</div></body></html>");
	zephir_concat_self(&html, &_72);
	zend_print_zval(&html, 0);
	zephir_update_static_property_ce(phalcon_debug_ce, ZEND_STRL("isActive"), &__$false);
	RETURN_MM_BOOL(1);

}

/**
 * Throws an exception when a notice or warning is raised
 */
PHP_METHOD(Phalcon_Debug, onUncaughtLowSeverity) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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



	ZEPHIR_CALL_FUNCTION(&_0, "error_reporting", NULL, 202);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_bitwise_and_function(&_1, &_0, severity);
	if (UNEXPECTED(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, zephir_get_internal_ce(SL("errorexception")));
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 203, message, &_3$$3, severity, file, line);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Debug.zep", 398);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets if files the exception's backtrace must be showed
 */
PHP_METHOD(Phalcon_Debug, setBlacklist) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *blacklist_param = NULL, area, result, subArray, value, _1, _2, *_3, _4, _7, *_8, _9, _5$$3, _6$$4, _10$$5, _11$$6;
	zval blacklist;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&blacklist);
	ZVAL_UNDEF(&area);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&subArray);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &blacklist_param);

	zephir_get_arrval(&blacklist, blacklist_param);


	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "request");
	ZEPHIR_CALL_CE_STATIC(&area, phalcon_helper_arr_ce, "get", &_0, 15, &blacklist, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&subArray);
	array_init(&subArray);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&area, 0, "phalcon/Debug.zep", 418);
	if (Z_TYPE_P(&area) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&area), _3)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			ZEPHIR_INIT_NVAR(&_5$$3);
			zephir_fast_strtolower(&_5$$3, &value);
			ZEPHIR_CPY_WRT(&value, &_5$$3);
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZVAL_LONG(&_5$$3, 1);
			zephir_array_update_zval(&subArray, &value, &_5$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &area, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &area, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &area, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_6$$4);
				zephir_fast_strtolower(&_6$$4, &value);
				ZEPHIR_CPY_WRT(&value, &_6$$4);
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZVAL_LONG(&_6$$4, 1);
				zephir_array_update_zval(&subArray, &value, &_6$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &area, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	zephir_array_update_string(&result, SL("request"), &subArray, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	array_init(&_2);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "server");
	ZEPHIR_CALL_CE_STATIC(&area, phalcon_helper_arr_ce, "get", &_0, 15, &blacklist, &_7, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&subArray);
	array_init(&subArray);
	zephir_is_iterable(&area, 0, "phalcon/Debug.zep", 427);
	if (Z_TYPE_P(&area) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&area), _8)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _8);
			ZEPHIR_INIT_NVAR(&_10$$5);
			zephir_fast_strtolower(&_10$$5, &value);
			ZEPHIR_CPY_WRT(&value, &_10$$5);
			ZEPHIR_INIT_NVAR(&_10$$5);
			ZVAL_LONG(&_10$$5, 1);
			zephir_array_update_zval(&subArray, &value, &_10$$5, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &area, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_9, &area, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_9)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &area, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$6);
				zephir_fast_strtolower(&_11$$6, &value);
				ZEPHIR_CPY_WRT(&value, &_11$$6);
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZVAL_LONG(&_11$$6, 1);
				zephir_array_update_zval(&subArray, &value, &_11$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &area, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
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

	zephir_fetch_params_without_memory_grow(1, 0, &showBackTrace_param);

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

	zephir_fetch_params_without_memory_grow(1, 0, &showFileFragment_param);

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

	zephir_fetch_params_without_memory_grow(1, 0, &showFiles_param);

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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *uri_param = NULL;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (UNEXPECTED(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be of the type string"));
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		zephir_fast_str_replace(&_0$$3, &_1$$3, &_2$$3, value);
		ZVAL_LONG(&_3$$3, 2);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "utf-8");
		ZEPHIR_RETURN_CALL_FUNCTION("htmlentities", NULL, 204, &_0$$3, &_3$$3, &_4$$3);
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

	zend_string *_4;
	zend_ulong _3;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argument_param = NULL, *n = NULL, n_sub, numberArguments, dump, varDump, k, v, *_1, _2, _6$$8, _7$$8, _9$$9, _10$$5, _11$$15, _12$$15, _13$$16, _14$$12;
	zval argument;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&n_sub);
	ZVAL_UNDEF(&numberArguments);
	ZVAL_UNDEF(&dump);
	ZVAL_UNDEF(&varDump);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$15);
	ZVAL_UNDEF(&_12$$15);
	ZVAL_UNDEF(&_13$$16);
	ZVAL_UNDEF(&_14$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &argument_param, &n);

	ZEPHIR_OBS_COPY_OR_DUP(&argument, argument_param);
	if (!n) {
		n = &n_sub;
		ZEPHIR_INIT_VAR(n);
		ZVAL_LONG(n, 0);
	}


	ZEPHIR_INIT_VAR(&numberArguments);
	ZVAL_LONG(&numberArguments, zephir_fast_count_int(&argument));
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
	zephir_is_iterable(&argument, 0, "phalcon/Debug.zep", 527);
	if (Z_TYPE_P(&argument) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&argument), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&k, _4);
			} else {
				ZVAL_LONG(&k, _3);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _1);
			if (ZEPHIR_IS_STRING(&v, "")) {
				ZEPHIR_INIT_NVAR(&varDump);
				ZVAL_STRING(&varDump, "(empty string)");
			} else if (zephir_is_scalar(&v)) {
				ZEPHIR_CALL_METHOD(&varDump, this_ptr, "escapestring", &_5, 0, &v);
				zephir_check_call_status();
			} else if (Z_TYPE_P(&v) == IS_ARRAY) {
				ZVAL_LONG(&_7$$8, (zephir_get_numberval(n) + 1));
				ZEPHIR_CALL_METHOD(&_6$$8, this_ptr, "getarraydump", &_8, 205, &v, &_7$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&varDump);
				ZEPHIR_CONCAT_SVS(&varDump, "Array(", &_6$$8, ")");
			} else if (Z_TYPE_P(&v) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_9$$9);
				zephir_get_class(&_9$$9, &v, 0);
				ZEPHIR_INIT_NVAR(&varDump);
				ZEPHIR_CONCAT_SVS(&varDump, "Object(", &_9$$9, ")");
			} else if (Z_TYPE_P(&v) == IS_NULL) {
				ZEPHIR_INIT_NVAR(&varDump);
				ZVAL_STRING(&varDump, "null");
			} else {
				ZEPHIR_CPY_WRT(&varDump, &v);
			}
			ZEPHIR_INIT_NVAR(&_10$$5);
			ZEPHIR_CONCAT_SVSV(&_10$$5, "[", &k, "] =&gt; ", &varDump);
			zephir_array_append(&dump, &_10$$5, PH_SEPARATE, "phalcon/Debug.zep", 524);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &argument, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &argument, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, &argument, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, &argument, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_STRING(&v, "")) {
					ZEPHIR_INIT_NVAR(&varDump);
					ZVAL_STRING(&varDump, "(empty string)");
				} else if (zephir_is_scalar(&v)) {
					ZEPHIR_CALL_METHOD(&varDump, this_ptr, "escapestring", &_5, 0, &v);
					zephir_check_call_status();
				} else if (Z_TYPE_P(&v) == IS_ARRAY) {
					ZVAL_LONG(&_12$$15, (zephir_get_numberval(n) + 1));
					ZEPHIR_CALL_METHOD(&_11$$15, this_ptr, "getarraydump", &_8, 205, &v, &_12$$15);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&varDump);
					ZEPHIR_CONCAT_SVS(&varDump, "Array(", &_11$$15, ")");
				} else if (Z_TYPE_P(&v) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_13$$16);
					zephir_get_class(&_13$$16, &v, 0);
					ZEPHIR_INIT_NVAR(&varDump);
					ZEPHIR_CONCAT_SVS(&varDump, "Object(", &_13$$16, ")");
				} else if (Z_TYPE_P(&v) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&varDump);
					ZVAL_STRING(&varDump, "null");
				} else {
					ZEPHIR_CPY_WRT(&varDump, &v);
				}
				ZEPHIR_INIT_NVAR(&_14$$12);
				ZEPHIR_CONCAT_SVSV(&_14$$12, "[", &k, "] =&gt; ", &varDump);
				zephir_array_append(&dump, &_14$$12, PH_SEPARATE, "phalcon/Debug.zep", 524);
			ZEPHIR_CALL_METHOD(NULL, &argument, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_fast_join_str(return_value, SL(", "), &dump);
	RETURN_MM();

}

/**
 * Produces an string representation of a variable
 */
PHP_METHOD(Phalcon_Debug, getVarDump) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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



	if (ZEPHIR_IS_TRUE_IDENTICAL(variable)) {
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
		zephir_get_class(&className, variable, 0);
		if ((zephir_method_exists_ex(variable, ZEND_STRL("dump")) == SUCCESS)) {
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
		ZEPHIR_CALL_METHOD(&_1$$10, this_ptr, "getarraydump", NULL, 205, variable);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "Array(", &_1$$10, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		RETURN_MM_STRING("null");
	}
	zephir_gettype(return_value, variable);
	RETURN_MM();

}

/**
 * Shows a backtrace item
 */
PHP_METHOD(Phalcon_Debug, showTraceItem) {

	zend_bool _42$$25;
	zval _1, _28$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_21 = NULL, *_49 = NULL;
	zval trace;
	zval *n_param = NULL, *trace_param = NULL, className, prepareInternalClass, preparedFunctionName, html, classReflection, prepareUriClass, functionName, functionReflection, traceArgs, arguments, argument, filez, line, showFiles, lines, numberLines, showFileFragment, firstLine, lastLine, linePosition, currentLine, classNameWithLink, functionNameWithLink, parts, _0, _17, _2$$3, _3$$3, _4$$3, _5$$3, _12$$3, _13$$3, _6$$4, _7$$4, _8$$5, _9$$6, _10$$6, _11$$6, _14$$10, _15$$11, _16$$11, *_18$$14, _19$$14, _25$$14, _26$$14, _20$$15, _22$$15, _23$$16, _24$$16, _27$$17, _29$$17, _30$$17, _31$$18, _32$$19, _33$$24, _34$$27, _35$$27, _36$$27, _37$$27, _38$$27, _39$$28, _40$$28, _41$$28, _43$$30, _44$$30, _45$$30, _46$$30, _47$$30, _48$$30;
	zend_long n, ZEPHIR_LAST_CALL_STATUS, i = 0, beforeLine$$19, afterLine$$19;
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
	ZVAL_UNDEF(&parts);
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
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_29$$17);
	ZVAL_UNDEF(&_30$$17);
	ZVAL_UNDEF(&_31$$18);
	ZVAL_UNDEF(&_32$$19);
	ZVAL_UNDEF(&_33$$24);
	ZVAL_UNDEF(&_34$$27);
	ZVAL_UNDEF(&_35$$27);
	ZVAL_UNDEF(&_36$$27);
	ZVAL_UNDEF(&_37$$27);
	ZVAL_UNDEF(&_38$$27);
	ZVAL_UNDEF(&_39$$28);
	ZVAL_UNDEF(&_40$$28);
	ZVAL_UNDEF(&_41$$28);
	ZVAL_UNDEF(&_43$$30);
	ZVAL_UNDEF(&_44$$30);
	ZVAL_UNDEF(&_45$$30);
	ZVAL_UNDEF(&_46$$30);
	ZVAL_UNDEF(&_47$$30);
	ZVAL_UNDEF(&_48$$30);
	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_28$$17);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &n_param, &trace_param);

	n = zephir_get_intval(n_param);
	ZEPHIR_OBS_COPY_OR_DUP(&trace, trace_param);


	ZEPHIR_INIT_VAR(&_0);
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
		zephir_preg_match(&_4$$3, &_5$$3, &className, &_2$$3, 0, 0 , 0 );
		if (zephir_is_true(&_4$$3)) {
			ZEPHIR_INIT_VAR(&parts);
			zephir_fast_explode_str(&parts, SL("\\"), &className, LONG_MAX);
			zephir_array_fetch_long(&_6$$4, &parts, 0, PH_NOISY | PH_READONLY, "phalcon/Debug.zep", 633);
			zephir_array_fetch_long(&_7$$4, &parts, 1, PH_NOISY | PH_READONLY, "phalcon/Debug.zep", 633);
			ZEPHIR_INIT_VAR(&prepareUriClass);
			ZEPHIR_CONCAT_VSV(&prepareUriClass, &_6$$4, "_", &_7$$4);
			ZEPHIR_INIT_VAR(&classNameWithLink);
			ZEPHIR_CONCAT_SVSVS(&classNameWithLink, "<a target='_new' href='https://docs.phalcon.io/4.0/en/api/", &prepareUriClass, "'>", &className, "</a>");
		} else {
			ZEPHIR_INIT_VAR(&classReflection);
			object_init_ex(&classReflection, zephir_get_internal_ce(SL("reflectionclass")));
			ZEPHIR_CALL_METHOD(NULL, &classReflection, "__construct", NULL, 141, &className);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8$$5, &classReflection, "isinternal", NULL, 206);
			zephir_check_call_status();
			if (zephir_is_true(&_8$$5)) {
				ZEPHIR_INIT_VAR(&_9$$6);
				zephir_fast_strtolower(&_9$$6, &className);
				ZEPHIR_INIT_VAR(&_10$$6);
				ZVAL_STRING(&_10$$6, "_");
				ZEPHIR_INIT_VAR(&_11$$6);
				ZVAL_STRING(&_11$$6, "-");
				ZEPHIR_INIT_VAR(&prepareInternalClass);
				zephir_fast_str_replace(&prepareInternalClass, &_10$$6, &_11$$6, &_9$$6);
				ZEPHIR_INIT_NVAR(&classNameWithLink);
				ZEPHIR_CONCAT_SVSVS(&classNameWithLink, "<a target='_new' href='https://secure.php.net/manual/en/class.", &prepareInternalClass, ".php'>", &className, "</a>");
			} else {
				ZEPHIR_CPY_WRT(&classNameWithLink, &className);
			}
		}
		ZEPHIR_INIT_VAR(&_12$$3);
		ZEPHIR_CONCAT_SVS(&_12$$3, "<span class='error-class'>", &classNameWithLink, "</span>");
		zephir_concat_self(&html, &_12$$3);
		zephir_array_fetch_string(&_13$$3, &trace, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Debug.zep", 666);
		zephir_concat_self(&html, &_13$$3);
	}
	ZEPHIR_OBS_VAR(&functionName);
	zephir_array_fetch_string(&functionName, &trace, SL("function"), PH_NOISY, "phalcon/Debug.zep", 672);
	if (zephir_array_isset_string(&trace, SL("class"))) {
		ZEPHIR_CPY_WRT(&functionNameWithLink, &functionName);
	} else {
		if ((zephir_function_exists(&functionName)  == SUCCESS)) {
			ZEPHIR_INIT_VAR(&functionReflection);
			object_init_ex(&functionReflection, zephir_get_internal_ce(SL("reflectionfunction")));
			ZEPHIR_CALL_METHOD(NULL, &functionReflection, "__construct", NULL, 136, &functionName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_14$$10, &functionReflection, "isinternal", NULL, 207);
			zephir_check_call_status();
			if (zephir_is_true(&_14$$10)) {
				ZEPHIR_INIT_VAR(&_15$$11);
				ZVAL_STRING(&_15$$11, "_");
				ZEPHIR_INIT_VAR(&_16$$11);
				ZVAL_STRING(&_16$$11, "-");
				ZEPHIR_INIT_VAR(&preparedFunctionName);
				zephir_fast_str_replace(&preparedFunctionName, &_15$$11, &_16$$11, &functionName);
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
	zephir_concat_self(&html, &_17);
	ZEPHIR_OBS_VAR(&traceArgs);
	if (zephir_array_isset_string_fetch(&traceArgs, &trace, SL("args"), 0)) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
		zephir_is_iterable(&traceArgs, 0, "phalcon/Debug.zep", 724);
		if (Z_TYPE_P(&traceArgs) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&traceArgs), _18$$14)
			{
				ZEPHIR_INIT_NVAR(&argument);
				ZVAL_COPY(&argument, _18$$14);
				ZEPHIR_CALL_METHOD(&_20$$15, this_ptr, "getvardump", &_21, 0, &argument);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_22$$15);
				ZEPHIR_CONCAT_SVS(&_22$$15, "<span class='error-parameter'>", &_20$$15, "</span>");
				zephir_array_append(&arguments, &_22$$15, PH_SEPARATE, "phalcon/Debug.zep", 718);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &traceArgs, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_19$$14, &traceArgs, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_19$$14)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&argument, &traceArgs, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_23$$16, this_ptr, "getvardump", &_21, 0, &argument);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_24$$16);
					ZEPHIR_CONCAT_SVS(&_24$$16, "<span class='error-parameter'>", &_23$$16, "</span>");
					zephir_array_append(&arguments, &_24$$16, PH_SEPARATE, "phalcon/Debug.zep", 718);
				ZEPHIR_CALL_METHOD(NULL, &traceArgs, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&argument);
		ZEPHIR_INIT_VAR(&_25$$14);
		zephir_fast_join_str(&_25$$14, SL(", "), &arguments);
		ZEPHIR_INIT_VAR(&_26$$14);
		ZEPHIR_CONCAT_SVS(&_26$$14, "(", &_25$$14, ")");
		zephir_concat_self(&html, &_26$$14);
	}
	ZEPHIR_OBS_VAR(&filez);
	if (zephir_array_isset_string_fetch(&filez, &trace, SL("file"), 0)) {
		ZEPHIR_OBS_VAR(&_27$$17);
		zephir_array_fetch_string(&_27$$17, &trace, SL("line"), PH_NOISY, "phalcon/Debug.zep", 732);
		zephir_get_strval(&_28$$17, &_27$$17);
		ZEPHIR_CPY_WRT(&line, &_28$$17);
		ZEPHIR_INIT_VAR(&_29$$17);
		ZEPHIR_CONCAT_SVSVS(&_29$$17, "<br/><div class='error-file'>", &filez, " (", &line, ")</div>");
		zephir_concat_self(&html, &_29$$17);
		zephir_read_property(&_30$$17, this_ptr, SL("showFiles"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&showFiles, &_30$$17);
		if (zephir_is_true(&showFiles)) {
			ZEPHIR_CALL_FUNCTION(&lines, "file", NULL, 208, &filez);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&numberLines);
			ZVAL_LONG(&numberLines, zephir_fast_count_int(&lines));
			zephir_read_property(&_31$$18, this_ptr, SL("showFileFragment"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&showFileFragment, &_31$$18);
			if (zephir_is_true(&showFileFragment)) {
				beforeLine$$19 = (zephir_get_numberval(&line) - 7);
				if (beforeLine$$19 < 1) {
					ZEPHIR_INIT_VAR(&firstLine);
					ZVAL_LONG(&firstLine, 1);
				} else {
					ZEPHIR_INIT_NVAR(&firstLine);
					ZVAL_LONG(&firstLine, beforeLine$$19);
				}
				afterLine$$19 = (zephir_get_numberval(&line) + 5);
				if (ZEPHIR_LT_LONG(&numberLines, afterLine$$19)) {
					ZEPHIR_CPY_WRT(&lastLine, &numberLines);
				} else {
					ZEPHIR_INIT_NVAR(&lastLine);
					ZVAL_LONG(&lastLine, afterLine$$19);
				}
				ZEPHIR_INIT_VAR(&_32$$19);
				ZEPHIR_CONCAT_SVSVSVS(&_32$$19, "<pre class='prettyprint highlight:", &firstLine, ":", &line, " linenums:", &firstLine, "'>");
				zephir_concat_self(&html, &_32$$19);
			} else {
				ZEPHIR_INIT_NVAR(&firstLine);
				ZVAL_LONG(&firstLine, 1);
				ZEPHIR_CPY_WRT(&lastLine, &numberLines);
				ZEPHIR_INIT_VAR(&_33$$24);
				ZEPHIR_CONCAT_SVSVS(&_33$$24, "<pre class='prettyprint highlight:", &firstLine, ":", &line, " linenums error-scroll'>");
				zephir_concat_self(&html, &_33$$24);
			}
			i = zephir_get_numberval(&firstLine);
			while (1) {
				if (!(ZEPHIR_GE_LONG(&lastLine, i))) {
					break;
				}
				ZEPHIR_INIT_NVAR(&linePosition);
				ZVAL_LONG(&linePosition, (i - 1));
				ZEPHIR_OBS_NVAR(&currentLine);
				zephir_array_fetch(&currentLine, &lines, &linePosition, PH_NOISY, "phalcon/Debug.zep", 805);
				if (zephir_is_true(&showFileFragment)) {
					if (ZEPHIR_IS_LONG(&firstLine, i)) {
						ZEPHIR_INIT_NVAR(&_34$$27);
						ZEPHIR_INIT_NVAR(&_35$$27);
						zephir_fast_trim(&_35$$27, &currentLine, NULL , ZEPHIR_TRIM_RIGHT);
						ZEPHIR_INIT_NVAR(&_36$$27);
						ZVAL_STRING(&_36$$27, "#\\*\\/#");
						ZEPHIR_INIT_NVAR(&_37$$27);
						ZEPHIR_INIT_NVAR(&_38$$27);
						ZVAL_STRING(&_38$$27, "#\\*\\/#");
						zephir_preg_match(&_37$$27, &_38$$27, &_35$$27, &_34$$27, 0, 0 , 0 );
						if (zephir_is_true(&_37$$27)) {
							ZEPHIR_INIT_NVAR(&_39$$28);
							ZEPHIR_INIT_NVAR(&_40$$28);
							ZVAL_STRING(&_40$$28, "* /");
							ZEPHIR_INIT_NVAR(&_41$$28);
							ZVAL_STRING(&_41$$28, " ");
							zephir_fast_str_replace(&_39$$28, &_40$$28, &_41$$28, &currentLine);
							ZEPHIR_CPY_WRT(&currentLine, &_39$$28);
						}
					}
				}
				_42$$25 = ZEPHIR_IS_STRING(&currentLine, "\n");
				if (!(_42$$25)) {
					_42$$25 = ZEPHIR_IS_STRING(&currentLine, "\r\n");
				}
				if (_42$$25) {
					zephir_concat_self_str(&html, SL("&nbsp;\n"));
				} else {
					ZEPHIR_INIT_NVAR(&_43$$30);
					ZEPHIR_INIT_NVAR(&_44$$30);
					ZVAL_STRING(&_44$$30, "\t");
					ZEPHIR_INIT_NVAR(&_45$$30);
					ZVAL_STRING(&_45$$30, "  ");
					zephir_fast_str_replace(&_43$$30, &_44$$30, &_45$$30, &currentLine);
					ZVAL_LONG(&_46$$30, 2);
					ZEPHIR_INIT_NVAR(&_47$$30);
					ZVAL_STRING(&_47$$30, "UTF-8");
					ZEPHIR_CALL_FUNCTION(&_48$$30, "htmlentities", &_49, 204, &_43$$30, &_46$$30, &_47$$30);
					zephir_check_call_status();
					zephir_concat_self(&html, &_48$$30);
				}
				i++;
			}
			zephir_concat_self_str(&html, SL("</pre>"));
		}
	}
	zephir_concat_self_str(&html, SL("</td></tr>"));
	RETURN_CCTOR(&html);

}

zend_object *zephir_init_properties_Phalcon_Debug(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
			zephir_create_array(&_1$$3, 2, 0);
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

