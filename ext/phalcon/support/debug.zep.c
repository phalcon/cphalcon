
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/time.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Support_Debug)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support, Debug, phalcon, support_debug, phalcon_support_debug_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_support_debug_ce, SL("blacklist"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_support_debug_ce, SL("data"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_support_debug_ce, SL("hideDocumentRoot"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_support_debug_ce, SL("isActive"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_support_debug_ce, SL("showBackTrace"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_support_debug_ce, SL("showFileFragment"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_support_debug_ce, SL("showFiles"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_support_debug_ce, SL("uri"), "https://assets.phalcon.io/debug/5.0.x/", ZEND_ACC_PROTECTED);
	phalcon_support_debug_ce->create_object = zephir_init_properties_Phalcon_Support_Debug;

	return SUCCESS;
}

/**
 * Clears are variables added previously
 */
PHP_METHOD(Phalcon_Support_Debug, clearVars)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &_0);
	RETURN_THIS();
}

/**
 * Adds a variable to the debug output
 *
 * @param mixed $variable
 */
PHP_METHOD(Phalcon_Support_Debug, debugVar)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *varz, varz_sub, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&varz_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(varz)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &varz);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	zephir_array_fast_append(&_0, varz);
	ZEPHIR_CALL_FUNCTION(&_1, "debug_backtrace", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_time(&_2);
	zephir_array_fast_append(&_0, &_2);
	zephir_update_property_array_append(this_ptr, SL("data"), &_0);
	RETURN_THIS();
}

/**
 * Returns the CSS sources
 */
PHP_METHOD(Phalcon_Support_Debug, getCssSources)
{
	zval uri, sources, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&sources);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uri, &_0);
	ZEPHIR_INIT_VAR(&sources);
	ZEPHIR_CONCAT_SVSSVSSVS(&sources, "<link rel=\"stylesheet\" type=\"text/css\" href=\"", &uri, "assets/jquery-ui/themes/ui-lightness/jquery-ui.min.css\" />", "<link rel=\"stylesheet\" type=\"text/css\" href=\"", &uri, "assets/jquery-ui/themes/ui-lightness/theme.css\" />", "<link rel=\"stylesheet\" type=\"text/css\" href=\"", &uri, "themes/default/style.css\" />");
	RETURN_CCTOR(&sources);
}

/**
 * Returns the JavaScript sources
 */
PHP_METHOD(Phalcon_Support_Debug, getJsSources)
{
	zval uri, sources, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&sources);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&uri, &_0);
	ZEPHIR_INIT_VAR(&sources);
	ZEPHIR_CONCAT_SVSSVSSVSSVSSVS(&sources, "<script type=\"application/javascript\" src=\"", &uri, "assets/jquery/dist/jquery.min.js\"></script>", "<script type=\"application/javascript\" src=\"", &uri, "assets/jquery-ui/jquery-ui.min.js\"></script>", "<script type=\"application/javascript\" src=\"", &uri, "assets/jquery.scrollTo/jquery.scrollTo.min.js\"></script>", "<script type=\"application/javascript\" src=\"", &uri, "prettify/prettify.js\"></script>", "<script type=\"application/javascript\" src=\"", &uri, "pretty.js\"></script>");
	RETURN_CCTOR(&sources);
}

/**
 * Generates a link to the current version documentation
 */
PHP_METHOD(Phalcon_Support_Debug, getVersion)
{
	zval link, version, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&version);
	object_init_ex(&version, phalcon_support_version_ce);
	if (zephir_has_constructor(&version)) {
		ZEPHIR_CALL_METHOD(NULL, &version, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD(&_0, &version, "getpart", NULL, 0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_METHOD(&_2, &version, "getpart", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&link);
	ZEPHIR_CONCAT_SVSVS(&link, "https://docs.phalcon.io/", &_0, ".", &_2, "/en/");
	ZEPHIR_CALL_METHOD(&_3, &version, "get", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SSVSVS(return_value, "<div class=\"version\">Phalcon Framework ", "<a href=\"", &link, "\" target=\"_new\">", &_3, "</a></div>");
	RETURN_MM();
}

/**
 * Halts the request showing a backtrace
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Support_Debug, halt)
{
	zval *this_ptr = getThis();



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_support_debug_exception_ce, "Halted request", "phalcon/Support/Debug.zep", 159);
	return;
}

/**
 * Listen for uncaught exceptions and non silent notices or warnings
 *
 * @param bool $exceptions
 * @param bool $lowSeverity
 */
PHP_METHOD(Phalcon_Support_Debug, listen)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exceptions_param = NULL, *lowSeverity_param = NULL;
	zend_bool exceptions, lowSeverity;
	zval *this_ptr = getThis();

#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(exceptions)
		Z_PARAM_BOOL(lowSeverity)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
PHP_METHOD(Phalcon_Support_Debug, listenExceptions)
{
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
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Listen for non silent notices or warnings
 */
PHP_METHOD(Phalcon_Support_Debug, listenLowSeverity)
{
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
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 89, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_fast_append(&_2, this_ptr);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "onUncaughtException");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_THIS();
}

/**
 * Handles uncaught exceptions
 */
PHP_METHOD(Phalcon_Support_Debug, onUncaughtException)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, __$true, __$false, obLevel, _0, _2, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&obLevel);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &exception);


	ZEPHIR_CALL_FUNCTION(&obLevel, "ob_get_level", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&obLevel, 0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_static_property_ce(&_0, phalcon_support_debug_ce, SL("isActive"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$4, exception, "getmessage", NULL, 0);
		zephir_check_call_status();
		zend_print_zval(&_1$$4, 0);
		RETURN_MM_NULL();
	}
	zephir_update_static_property_ce(phalcon_support_debug_ce, ZEND_STRL("isActive"), &__$true);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "renderhtml", NULL, 0, exception);
	zephir_check_call_status();
	zend_print_zval(&_2, 0);
	zephir_update_static_property_ce(phalcon_support_debug_ce, ZEND_STRL("isActive"), &__$false);
	RETURN_MM_BOOL(1);
}

/**
 * Throws an exception when a notice or warning is raised
 */
PHP_METHOD(Phalcon_Support_Debug, onUncaughtLowSeverity)
{
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_ZVAL(severity)
		Z_PARAM_ZVAL(message)
		Z_PARAM_ZVAL(file)
		Z_PARAM_ZVAL(line)
		Z_PARAM_ZVAL(context)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 5, 0, &severity, &message, &file, &line, &context);


	ZEPHIR_CALL_FUNCTION(&_0, "error_reporting", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_bitwise_and_function(&_1, &_0, severity);
	if (UNEXPECTED(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, zend_ce_error_exception);
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0, message, &_3$$3, severity, file, line);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Support/Debug.zep", 258);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Render exception to html format.
 *
 * @param Throwable $exception
 *
 * @return string
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Support_Debug, renderHtml)
{
	zend_string *_12$$3, *_23$$3, *_39$$3, *_52$$3, *_61$$21;
	zend_ulong _11$$3, _22$$3, _38$$3, _51$$3, _60$$21;
	zval _7$$3, _16$$3, _33$$3, _47$$3, _57$$21;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL, *_27 = NULL, *_42 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, _REQUEST, __$true, _SERVER, blacklist, className, dataVar, dataVars, escapedMessage, html, keyFile, keyRequest, keyServer, keyVar, n, showBackTrace, traceItem, value, _0, _1, _2, _3, _4, _5, _6, _68, _69, _8$$3, *_9$$3, _10$$3, _17$$3, _18$$3, _19$$3, *_20$$3, _21$$3, _34$$3, _35$$3, *_36$$3, _37$$3, _48$$3, *_49$$3, _50$$3, _55$$3, _56$$3, _13$$5, _15$$6, _24$$7, _25$$9, _26$$10, _28$$10, _29$$11, _30$$13, _31$$14, _32$$14, _40$$15, _41$$16, _43$$16, _44$$17, _45$$18, _46$$18, _53$$19, _54$$20, *_58$$21, _59$$21, _62$$22, _63$$22, _64$$22, _65$$23, _66$$23, _67$$23;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_SERVER);
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
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_68);
	ZVAL_UNDEF(&_69);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_34$$3);
	ZVAL_UNDEF(&_35$$3);
	ZVAL_UNDEF(&_37$$3);
	ZVAL_UNDEF(&_48$$3);
	ZVAL_UNDEF(&_50$$3);
	ZVAL_UNDEF(&_55$$3);
	ZVAL_UNDEF(&_56$$3);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_24$$7);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$14);
	ZVAL_UNDEF(&_32$$14);
	ZVAL_UNDEF(&_40$$15);
	ZVAL_UNDEF(&_41$$16);
	ZVAL_UNDEF(&_43$$16);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_45$$18);
	ZVAL_UNDEF(&_46$$18);
	ZVAL_UNDEF(&_53$$19);
	ZVAL_UNDEF(&_54$$20);
	ZVAL_UNDEF(&_59$$21);
	ZVAL_UNDEF(&_62$$22);
	ZVAL_UNDEF(&_63$$22);
	ZVAL_UNDEF(&_64$$22);
	ZVAL_UNDEF(&_65$$23);
	ZVAL_UNDEF(&_66$$23);
	ZVAL_UNDEF(&_67$$23);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_33$$3);
	ZVAL_UNDEF(&_47$$3);
	ZVAL_UNDEF(&_57$$21);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_fetch_params(1, 1, 0, &exception);


	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, exception, 0);
	ZEPHIR_CALL_METHOD(&_0, exception, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&escapedMessage, this_ptr, "escapestring", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcsssources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&html);
	ZEPHIR_CONCAT_SSVSVSVS(&html, "<html><head>", "<title>", &className, ": ", &escapedMessage, "</title>", &_1, "</head><body>");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getversion", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&html, &_2);
	ZEPHIR_CALL_METHOD(&_3, exception, "getfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, exception, "getline", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SSSVSVSSVSVSS(&_5, "<div align=\"center\">", "<div class=\"error-main\">", "<h1>", &className, ": ", &escapedMessage, "</h1>", "<span class=\"error-file\">", &_3, " (", &_4, ")</span>", "</div>");
	zephir_concat_self(&html, &_5);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("showBackTrace"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&showBackTrace, &_6);
	if (zephir_is_true(&showBackTrace)) {
		ZEPHIR_OBS_VAR(&dataVars);
		zephir_read_property(&dataVars, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZEPHIR_CONCAT_SSSSSS(&_7$$3, "<div class=\"error-info\"><div id=\"tabs\"><ul>", "<li><a href=\"#error-tabs-1\">Backtrace</a></li>", "<li><a href=\"#error-tabs-2\">Request</a></li>", "<li><a href=\"#error-tabs-3\">Server</a></li>", "<li><a href=\"#error-tabs-4\">Included Files</a></li>", "<li><a href=\"#error-tabs-5\">Memory</a></li>");
		zephir_concat_self(&html, &_7$$3);
		if (!(ZEPHIR_IS_EMPTY(&dataVars))) {
			zephir_concat_self_str(&html, SL("<li><a href=\"#error-tabs-6\">Variables</a></li>"));
		}
		zephir_concat_self_str(&html, SL("</ul>"));
		zephir_concat_self_str(&html, SL("<div id=\"error-tabs-1\"><table cellspacing=\"0\" align=\"center\" width=\"100%\">"));
		ZEPHIR_CALL_METHOD(&_8$$3, exception, "gettrace", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&_8$$3, 0, "phalcon/Support/Debug.zep", 344);
		if (Z_TYPE_P(&_8$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_8$$3), _11$$3, _12$$3, _9$$3)
			{
				ZEPHIR_INIT_NVAR(&n);
				if (_12$$3 != NULL) { 
					ZVAL_STR_COPY(&n, _12$$3);
				} else {
					ZVAL_LONG(&n, _11$$3);
				}
				ZEPHIR_INIT_NVAR(&traceItem);
				ZVAL_COPY(&traceItem, _9$$3);
				ZEPHIR_CALL_METHOD(&_13$$5, this_ptr, "showtraceitem", &_14, 0, &n, &traceItem);
				zephir_check_call_status();
				zephir_concat_self(&html, &_13$$5);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_8$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_10$$3, &_8$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_10$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&n, &_8$$3, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&traceItem, &_8$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_15$$6, this_ptr, "showtraceitem", &_14, 0, &n, &traceItem);
					zephir_check_call_status();
					zephir_concat_self(&html, &_15$$6);
				ZEPHIR_CALL_METHOD(NULL, &_8$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&traceItem);
		ZEPHIR_INIT_NVAR(&n);
		zephir_concat_self_str(&html, SL("</table></div>"));
		ZEPHIR_INIT_VAR(&_16$$3);
		ZEPHIR_CONCAT_SSS(&_16$$3, "<div id=\"error-tabs-2\">", "<table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">", "<tr><th>Key</th><th>Value</th></tr>");
		zephir_concat_self(&html, &_16$$3);
		zephir_read_property(&_17$$3, this_ptr, ZEND_STRL("blacklist"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_18$$3);
		array_init(&_18$$3);
		ZEPHIR_INIT_VAR(&_19$$3);
		ZVAL_STRING(&_19$$3, "request");
		ZEPHIR_CALL_METHOD(&blacklist, this_ptr, "getarrval", NULL, 0, &_17$$3, &_19$$3, &_18$$3);
		zephir_check_call_status();
		zephir_is_iterable(&_REQUEST, 0, "phalcon/Support/Debug.zep", 364);
		if (Z_TYPE_P(&_REQUEST) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_REQUEST), _22$$3, _23$$3, _20$$3)
			{
				ZEPHIR_INIT_NVAR(&keyRequest);
				if (_23$$3 != NULL) { 
					ZVAL_STR_COPY(&keyRequest, _23$$3);
				} else {
					ZVAL_LONG(&keyRequest, _22$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _20$$3);
				ZEPHIR_INIT_NVAR(&_24$$7);
				zephir_fast_strtolower(&_24$$7, &keyRequest);
				if (1 != zephir_array_isset(&blacklist, &_24$$7)) {
					if (Z_TYPE_P(&value) != IS_ARRAY) {
						ZEPHIR_INIT_NVAR(&_25$$9);
						ZEPHIR_CONCAT_SVSVS(&_25$$9, "<tr><td class=\"key\">", &keyRequest, "</td><td>", &value, "</td></tr>");
						zephir_concat_self(&html, &_25$$9);
					} else {
						ZEPHIR_CALL_FUNCTION(&_26$$10, "print_r", &_27, 0, &value, &__$true);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_28$$10);
						ZEPHIR_CONCAT_SVSVS(&_28$$10, "<tr><td class=\"key\">", &keyRequest, "</td><td>", &_26$$10, "</td></tr>");
						zephir_concat_self(&html, &_28$$10);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_REQUEST, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_21$$3, &_REQUEST, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_21$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&keyRequest, &_REQUEST, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &_REQUEST, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_29$$11);
					zephir_fast_strtolower(&_29$$11, &keyRequest);
					if (1 != zephir_array_isset(&blacklist, &_29$$11)) {
						if (Z_TYPE_P(&value) != IS_ARRAY) {
							ZEPHIR_INIT_NVAR(&_30$$13);
							ZEPHIR_CONCAT_SVSVS(&_30$$13, "<tr><td class=\"key\">", &keyRequest, "</td><td>", &value, "</td></tr>");
							zephir_concat_self(&html, &_30$$13);
						} else {
							ZEPHIR_CALL_FUNCTION(&_31$$14, "print_r", &_27, 0, &value, &__$true);
							zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_32$$14);
							ZEPHIR_CONCAT_SVSVS(&_32$$14, "<tr><td class=\"key\">", &keyRequest, "</td><td>", &_31$$14, "</td></tr>");
							zephir_concat_self(&html, &_32$$14);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &_REQUEST, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&keyRequest);
		zephir_concat_self_str(&html, SL("</table></div>"));
		ZEPHIR_INIT_VAR(&_33$$3);
		ZEPHIR_CONCAT_SSS(&_33$$3, "<div id=\"error-tabs-3\">", "<table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">", "<tr><th>Key</th><th>Value</th></tr>");
		zephir_concat_self(&html, &_33$$3);
		zephir_read_property(&_34$$3, this_ptr, ZEND_STRL("blacklist"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_19$$3);
		array_init(&_19$$3);
		ZEPHIR_INIT_VAR(&_35$$3);
		ZVAL_STRING(&_35$$3, "server");
		ZEPHIR_CALL_METHOD(&blacklist, this_ptr, "getarrval", NULL, 0, &_34$$3, &_35$$3, &_19$$3);
		zephir_check_call_status();
		zephir_is_iterable(&_SERVER, 0, "phalcon/Support/Debug.zep", 380);
		if (Z_TYPE_P(&_SERVER) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_SERVER), _38$$3, _39$$3, _36$$3)
			{
				ZEPHIR_INIT_NVAR(&keyServer);
				if (_39$$3 != NULL) { 
					ZVAL_STR_COPY(&keyServer, _39$$3);
				} else {
					ZVAL_LONG(&keyServer, _38$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _36$$3);
				ZEPHIR_INIT_NVAR(&_40$$15);
				zephir_fast_strtolower(&_40$$15, &keyServer);
				if (1 != zephir_array_isset(&blacklist, &_40$$15)) {
					ZEPHIR_CALL_METHOD(&_41$$16, this_ptr, "getvardump", &_42, 0, &value);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_43$$16);
					ZEPHIR_CONCAT_SVSVS(&_43$$16, "<tr><td class=\"key\">", &keyServer, "</td><td>", &_41$$16, "</td></tr>");
					zephir_concat_self(&html, &_43$$16);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_SERVER, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_37$$3, &_SERVER, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_37$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&keyServer, &_SERVER, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &_SERVER, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_44$$17);
					zephir_fast_strtolower(&_44$$17, &keyServer);
					if (1 != zephir_array_isset(&blacklist, &_44$$17)) {
						ZEPHIR_CALL_METHOD(&_45$$18, this_ptr, "getvardump", &_42, 0, &value);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_46$$18);
						ZEPHIR_CONCAT_SVSVS(&_46$$18, "<tr><td class=\"key\">", &keyServer, "</td><td>", &_45$$18, "</td></tr>");
						zephir_concat_self(&html, &_46$$18);
					}
				ZEPHIR_CALL_METHOD(NULL, &_SERVER, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&keyServer);
		zephir_concat_self_str(&html, SL("</table></div>"));
		ZEPHIR_INIT_VAR(&_47$$3);
		ZEPHIR_CONCAT_SSS(&_47$$3, "<div id=\"error-tabs-4\">", "<table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">", "<tr><th>#</th><th>Path</th></tr>");
		zephir_concat_self(&html, &_47$$3);
		ZEPHIR_CALL_FUNCTION(&_48$$3, "get_included_files", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&_48$$3, 0, "phalcon/Support/Debug.zep", 393);
		if (Z_TYPE_P(&_48$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_48$$3), _51$$3, _52$$3, _49$$3)
			{
				ZEPHIR_INIT_NVAR(&keyFile);
				if (_52$$3 != NULL) { 
					ZVAL_STR_COPY(&keyFile, _52$$3);
				} else {
					ZVAL_LONG(&keyFile, _51$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _49$$3);
				ZEPHIR_INIT_NVAR(&_53$$19);
				ZEPHIR_CONCAT_SVSVS(&_53$$19, "<tr><td>", &keyFile, "</th><td>", &value, "</td></tr>");
				zephir_concat_self(&html, &_53$$19);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_48$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_50$$3, &_48$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_50$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&keyFile, &_48$$3, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &_48$$3, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_54$$20);
					ZEPHIR_CONCAT_SVSVS(&_54$$20, "<tr><td>", &keyFile, "</th><td>", &value, "</td></tr>");
					zephir_concat_self(&html, &_54$$20);
				ZEPHIR_CALL_METHOD(NULL, &_48$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&keyFile);
		zephir_concat_self_str(&html, SL("</table></div>"));
		ZEPHIR_CALL_FUNCTION(&_55$$3, "memory_get_usage", NULL, 0, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_56$$3);
		ZEPHIR_CONCAT_SSSVSS(&_56$$3, "<div id=\"error-tabs-5\">", "<table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">", "<tr><th colspan=\"2\">Memory</th></tr><tr><td>Usage</td><td>", &_55$$3, "</td></tr>", "</table></div>");
		zephir_concat_self(&html, &_56$$3);
		if (!(ZEPHIR_IS_EMPTY(&dataVars))) {
			ZEPHIR_INIT_VAR(&_57$$21);
			ZEPHIR_CONCAT_SSS(&_57$$21, "<div id=\"error-tabs-6\">", "<table cellspacing=\"0\" align=\"center\" class=\"superglobal-detail\">", "<tr><th>Key</th><th>Value</th></tr>");
			zephir_concat_self(&html, &_57$$21);
			zephir_is_iterable(&dataVars, 0, "phalcon/Support/Debug.zep", 415);
			if (Z_TYPE_P(&dataVars) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&dataVars), _60$$21, _61$$21, _58$$21)
				{
					ZEPHIR_INIT_NVAR(&keyVar);
					if (_61$$21 != NULL) { 
						ZVAL_STR_COPY(&keyVar, _61$$21);
					} else {
						ZVAL_LONG(&keyVar, _60$$21);
					}
					ZEPHIR_INIT_NVAR(&dataVar);
					ZVAL_COPY(&dataVar, _58$$21);
					zephir_array_fetch_long(&_63$$22, &dataVar, 0, PH_NOISY | PH_READONLY, "phalcon/Support/Debug.zep", 412);
					ZEPHIR_CALL_METHOD(&_62$$22, this_ptr, "getvardump", &_42, 0, &_63$$22);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_64$$22);
					ZEPHIR_CONCAT_SVSVS(&_64$$22, "<tr><td class=\"key\">", &keyVar, "</td><td>", &_62$$22, "</td></tr>");
					zephir_concat_self(&html, &_64$$22);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &dataVars, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_59$$21, &dataVars, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_59$$21)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&keyVar, &dataVars, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&dataVar, &dataVars, "current", NULL, 0);
					zephir_check_call_status();
						zephir_array_fetch_long(&_66$$23, &dataVar, 0, PH_NOISY | PH_READONLY, "phalcon/Support/Debug.zep", 412);
						ZEPHIR_CALL_METHOD(&_65$$23, this_ptr, "getvardump", &_42, 0, &_66$$23);
						zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_67$$23);
						ZEPHIR_CONCAT_SVSVS(&_67$$23, "<tr><td class=\"key\">", &keyVar, "</td><td>", &_65$$23, "</td></tr>");
						zephir_concat_self(&html, &_67$$23);
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
	ZEPHIR_CALL_METHOD(&_68, this_ptr, "getjssources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_69);
	ZEPHIR_CONCAT_VS(&_69, &_68, "</div></body></html>");
	zephir_concat_self(&html, &_69);
	RETURN_CCTOR(&html);
}

/**
 * Sets if files the exception's backtrace must be showed
 *
 * @param array $blacklist
 */
PHP_METHOD(Phalcon_Support_Debug, setBlacklist)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *blacklist_param = NULL, area, result, subArray, value, _0, _1, *_2, _3, _6, *_7, _8, _4$$3, _5$$4, _9$$5, _10$$6;
	zval blacklist;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&blacklist);
	ZVAL_UNDEF(&area);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&subArray);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(blacklist)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &blacklist_param);
	zephir_get_arrval(&blacklist, blacklist_param);


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&area, this_ptr, "getarrval", NULL, 0, &blacklist, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&subArray);
	array_init(&subArray);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&area, 0, "phalcon/Support/Debug.zep", 447);
	if (Z_TYPE_P(&area) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&area), _2)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_fast_strtolower(&_4$$3, &value);
			ZEPHIR_CPY_WRT(&value, &_4$$3);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZVAL_LONG(&_4$$3, 1);
			zephir_array_update_zval(&subArray, &value, &_4$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &area, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &area, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &area, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$4);
				zephir_fast_strtolower(&_5$$4, &value);
				ZEPHIR_CPY_WRT(&value, &_5$$4);
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZVAL_LONG(&_5$$4, 1);
				zephir_array_update_zval(&subArray, &value, &_5$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &area, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	zephir_array_update_string(&result, SL("request"), &subArray, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "server");
	ZEPHIR_CALL_METHOD(&area, this_ptr, "getarrval", NULL, 0, &blacklist, &_6, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&subArray);
	array_init(&subArray);
	zephir_is_iterable(&area, 0, "phalcon/Support/Debug.zep", 456);
	if (Z_TYPE_P(&area) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&area), _7)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _7);
			ZEPHIR_INIT_NVAR(&_9$$5);
			zephir_fast_strtolower(&_9$$5, &value);
			ZEPHIR_CPY_WRT(&value, &_9$$5);
			ZEPHIR_INIT_NVAR(&_9$$5);
			ZVAL_LONG(&_9$$5, 1);
			zephir_array_update_zval(&subArray, &value, &_9$$5, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &area, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &area, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &area, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$6);
				zephir_fast_strtolower(&_10$$6, &value);
				ZEPHIR_CPY_WRT(&value, &_10$$6);
				ZEPHIR_INIT_NVAR(&_10$$6);
				ZVAL_LONG(&_10$$6, 1);
				zephir_array_update_zval(&subArray, &value, &_10$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &area, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	zephir_array_update_string(&result, SL("server"), &subArray, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("blacklist"), &result);
	RETURN_THIS();
}

/**
 * Sets if files the exception's backtrace must be showed
 *
 * @param bool $showBackTrace
 */
PHP_METHOD(Phalcon_Support_Debug, setShowBackTrace)
{
	zval *showBackTrace_param = NULL, __$true, __$false;
	zend_bool showBackTrace;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(showBackTrace)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &showBackTrace_param);
	showBackTrace = zephir_get_boolval(showBackTrace_param);


	if (showBackTrace) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("showBackTrace"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("showBackTrace"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Sets if files must be completely opened and showed in the output
 * or just the fragment related to the exception
 *
 * @param bool $showFileFragment
 */
PHP_METHOD(Phalcon_Support_Debug, setShowFileFragment)
{
	zval *showFileFragment_param = NULL, __$true, __$false;
	zend_bool showFileFragment;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(showFileFragment)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &showFileFragment_param);
	showFileFragment = zephir_get_boolval(showFileFragment_param);


	if (showFileFragment) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("showFileFragment"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("showFileFragment"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Set if files part of the backtrace must be shown in the output
 *
 * @param bool $showFiles
 */
PHP_METHOD(Phalcon_Support_Debug, setShowFiles)
{
	zval *showFiles_param = NULL, __$true, __$false;
	zend_bool showFiles;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(showFiles)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &showFiles_param);
	showFiles = zephir_get_boolval(showFiles_param);


	if (showFiles) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("showFiles"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("showFiles"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Change the base URI for static resources
 *
 * @param string $uri
 */
PHP_METHOD(Phalcon_Support_Debug, setUri)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *uri_param = NULL;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("uri"), &uri);
	RETURN_THIS();
}

/**
 * Escapes a string with htmlentities
 *
 * @param string $value
 */
PHP_METHOD(Phalcon_Support_Debug, escapeString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, _0, _1, _2, _3, _4;
	zval value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);
	zephir_get_strval(&value, value_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\n");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\\n");
	zephir_fast_str_replace(&_0, &_1, &_2, &value);
	ZVAL_LONG(&_3, 2);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "utf-8");
	ZEPHIR_RETURN_CALL_FUNCTION("htmlentities", NULL, 0, &_0, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Produces a recursive representation of an array
 *
 * @param array $arguments
 * @param int   $number
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Support_Debug, getArrayDump)
{
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(argument)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(n)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	zephir_is_iterable(&argument, 0, "phalcon/Support/Debug.zep", 567);
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
				ZEPHIR_CALL_METHOD(&_6$$8, this_ptr, "getarraydump", &_8, 0, &v, &_7$$8);
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
			zephir_array_append(&dump, &_10$$5, PH_SEPARATE, "phalcon/Support/Debug.zep", 564);
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
					ZEPHIR_CALL_METHOD(&_11$$15, this_ptr, "getarraydump", &_8, 0, &v, &_12$$15);
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
				zephir_array_append(&dump, &_14$$12, PH_SEPARATE, "phalcon/Support/Debug.zep", 564);
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
PHP_METHOD(Phalcon_Support_Debug, getVarDump)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, className, dumpedObject, _0$$8, _1$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&dumpedObject);
	ZVAL_UNDEF(&_0$$8);
	ZVAL_UNDEF(&_1$$10);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(variable)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
		ZEPHIR_CALL_METHOD(&_1$$10, this_ptr, "getarraydump", NULL, 0, variable);
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
 *
 * @param int   $n
 * @param array $trace
 *
 * @return string
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Support_Debug, showTraceItem)
{
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_ARRAY(trace)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &n_param, &trace_param);
	n = zephir_get_intval(n_param);
	ZEPHIR_OBS_COPY_OR_DUP(&trace, trace_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, n);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "<tr><td align=\"right\" valign=\"top\" class=\"error-number\">#", &_0, "</td><td>");
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
			zephir_array_fetch_long(&_6$$4, &parts, 0, PH_NOISY | PH_READONLY, "phalcon/Support/Debug.zep", 678);
			zephir_array_fetch_long(&_7$$4, &parts, 1, PH_NOISY | PH_READONLY, "phalcon/Support/Debug.zep", 678);
			ZEPHIR_INIT_VAR(&prepareUriClass);
			ZEPHIR_CONCAT_VSV(&prepareUriClass, &_6$$4, "_", &_7$$4);
			ZEPHIR_INIT_VAR(&classNameWithLink);
			ZEPHIR_CONCAT_SVSVS(&classNameWithLink, "<a target=\"_new\" href=\"https://docs.phalcon.io/4.0/en/api/", &prepareUriClass, "\">", &className, "</a>");
		} else {
			ZEPHIR_INIT_VAR(&classReflection);
			object_init_ex(&classReflection, zephir_get_internal_ce(SL("reflectionclass")));
			ZEPHIR_CALL_METHOD(NULL, &classReflection, "__construct", NULL, 178, &className);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_8$$5, &classReflection, "isinternal", NULL, 0);
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
				ZEPHIR_CONCAT_SVSVS(&classNameWithLink, "<a target=\"_new\" href=\"https://secure.php.net/manual/en/class.", &prepareInternalClass, ".php\">", &className, "</a>");
			} else {
				ZEPHIR_CPY_WRT(&classNameWithLink, &className);
			}
		}
		ZEPHIR_INIT_VAR(&_12$$3);
		ZEPHIR_CONCAT_SVS(&_12$$3, "<span class=\"error-class\">", &classNameWithLink, "</span>");
		zephir_concat_self(&html, &_12$$3);
		zephir_array_fetch_string(&_13$$3, &trace, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Support/Debug.zep", 711);
		zephir_concat_self(&html, &_13$$3);
	}
	ZEPHIR_OBS_VAR(&functionName);
	zephir_array_fetch_string(&functionName, &trace, SL("function"), PH_NOISY, "phalcon/Support/Debug.zep", 717);
	if (zephir_array_isset_string(&trace, SL("class"))) {
		ZEPHIR_CPY_WRT(&functionNameWithLink, &functionName);
	} else {
		if ((zephir_function_exists(&functionName) == SUCCESS)) {
			ZEPHIR_INIT_VAR(&functionReflection);
			object_init_ex(&functionReflection, zephir_get_internal_ce(SL("reflectionfunction")));
			ZEPHIR_CALL_METHOD(NULL, &functionReflection, "__construct", NULL, 172, &functionName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_14$$10, &functionReflection, "isinternal", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_14$$10)) {
				ZEPHIR_INIT_VAR(&_15$$11);
				ZVAL_STRING(&_15$$11, "_");
				ZEPHIR_INIT_VAR(&_16$$11);
				ZVAL_STRING(&_16$$11, "-");
				ZEPHIR_INIT_VAR(&preparedFunctionName);
				zephir_fast_str_replace(&preparedFunctionName, &_15$$11, &_16$$11, &functionName);
				ZEPHIR_INIT_NVAR(&functionNameWithLink);
				ZEPHIR_CONCAT_SVSVS(&functionNameWithLink, "<a target=\"_new\" href=\"https://secure.php.net/manual/en/function.", &preparedFunctionName, ".php\">", &functionName, "</a>");
			} else {
				ZEPHIR_CPY_WRT(&functionNameWithLink, &functionName);
			}
		} else {
			ZEPHIR_CPY_WRT(&functionNameWithLink, &functionName);
		}
	}
	ZEPHIR_INIT_VAR(&_17);
	ZEPHIR_CONCAT_SVS(&_17, "<span class=\"error-function\">", &functionNameWithLink, "</span>");
	zephir_concat_self(&html, &_17);
	ZEPHIR_OBS_VAR(&traceArgs);
	if (zephir_array_isset_string_fetch(&traceArgs, &trace, SL("args"), 0)) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
		zephir_is_iterable(&traceArgs, 0, "phalcon/Support/Debug.zep", 770);
		if (Z_TYPE_P(&traceArgs) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&traceArgs), _18$$14)
			{
				ZEPHIR_INIT_NVAR(&argument);
				ZVAL_COPY(&argument, _18$$14);
				ZEPHIR_CALL_METHOD(&_20$$15, this_ptr, "getvardump", &_21, 0, &argument);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_22$$15);
				ZEPHIR_CONCAT_SVS(&_22$$15, "<span class=\"error-parameter\">", &_20$$15, "</span>");
				zephir_array_append(&arguments, &_22$$15, PH_SEPARATE, "phalcon/Support/Debug.zep", 764);
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
					ZEPHIR_CONCAT_SVS(&_24$$16, "<span class=\"error-parameter\">", &_23$$16, "</span>");
					zephir_array_append(&arguments, &_24$$16, PH_SEPARATE, "phalcon/Support/Debug.zep", 764);
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
		zephir_array_fetch_string(&_27$$17, &trace, SL("line"), PH_NOISY, "phalcon/Support/Debug.zep", 778);
		zephir_cast_to_string(&_28$$17, &_27$$17);
		ZEPHIR_CPY_WRT(&line, &_28$$17);
		ZEPHIR_INIT_VAR(&_29$$17);
		ZEPHIR_CONCAT_SVSVS(&_29$$17, "<br/><div class=\"error-file\">", &filez, " (", &line, ")</div>");
		zephir_concat_self(&html, &_29$$17);
		zephir_read_property(&_30$$17, this_ptr, ZEND_STRL("showFiles"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&showFiles, &_30$$17);
		if (zephir_is_true(&showFiles)) {
			ZEPHIR_CALL_FUNCTION(&lines, "file", NULL, 0, &filez);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&numberLines);
			ZVAL_LONG(&numberLines, zephir_fast_count_int(&lines));
			zephir_read_property(&_31$$18, this_ptr, ZEND_STRL("showFileFragment"), PH_NOISY_CC | PH_READONLY);
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
				ZEPHIR_CONCAT_SVSVSVS(&_32$$19, "<pre class=\"prettyprint highlight:", &firstLine, ":", &line, " linenums:", &firstLine, "\">");
				zephir_concat_self(&html, &_32$$19);
			} else {
				ZEPHIR_INIT_NVAR(&firstLine);
				ZVAL_LONG(&firstLine, 1);
				ZEPHIR_CPY_WRT(&lastLine, &numberLines);
				ZEPHIR_INIT_VAR(&_33$$24);
				ZEPHIR_CONCAT_SVSVS(&_33$$24, "<pre class=\"prettyprint highlight:", &firstLine, ":", &line, " linenums error-scroll\">");
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
				zephir_array_fetch(&currentLine, &lines, &linePosition, PH_NOISY, "phalcon/Support/Debug.zep", 851);
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
					ZEPHIR_CALL_FUNCTION(&_48$$30, "htmlentities", &_49, 0, &_43$$30, &_46$$30, &_47$$30);
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

/**
 * @todo Remove this when we get traits
 */
PHP_METHOD(Phalcon_Support_Debug, getArrVal)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *collection_param = NULL, *index, index_sub, *defaultValue = NULL, defaultValue_sub, __$null, value;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ARRAY(collection)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &collection_param, &index, &defaultValue);
	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	if (UNEXPECTED(!(zephir_array_isset_fetch(&value, &collection, index, 1)))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CTOR(&value);
}

zend_object *zephir_init_properties_Phalcon_Support_Debug(zend_class_entry *class_type)
{
		zval _3$$4;
	zval _0, _2, _1$$3, _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("data"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("blacklist"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 2, 0);
			ZEPHIR_INIT_VAR(&_4$$4);
			array_init(&_4$$4);
			zephir_array_update_string(&_3$$4, SL("request"), &_4$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_4$$4);
			array_init(&_4$$4);
			zephir_array_update_string(&_3$$4, SL("server"), &_4$$4, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("blacklist"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

