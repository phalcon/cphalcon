
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(varz)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zval template, _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&template);
	ZEPHIR_CONCAT_SVS(&template, "\n    <link href='", &_0, "%s'\n          rel='stylesheet'\n          type='text/css' />");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "assets/jquery-ui/themes/ui-lightness/jquery-ui.min.css");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 73, &template, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "assets/jquery-ui/themes/ui-lightness/theme.css");
	ZEPHIR_CALL_FUNCTION(&_3, "sprintf", NULL, 73, &template, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "themes/default/style.css");
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", NULL, 73, &template, &_1);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVV(return_value, &_2, &_3, &_4);
	RETURN_MM();
}

/**
 * Returns the JavaScript sources
 */
PHP_METHOD(Phalcon_Support_Debug, getJsSources)
{
	zval template, _0, _1, _2, _3, _4, _5, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("uri"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&template);
	ZEPHIR_CONCAT_SVS(&template, "\n    <script type='application/javascript'\n            src='", &_0, "%s'></script>");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "assets/jquery/dist/jquery.min.js");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 73, &template, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "assets/jquery-ui/jquery-ui.min.js");
	ZEPHIR_CALL_FUNCTION(&_3, "sprintf", NULL, 73, &template, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "assets/jquery.scrollTo/jquery.scrollTo.min.js");
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", NULL, 73, &template, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "prettify/prettify.js");
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 73, &template, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "pretty.js");
	ZEPHIR_CALL_FUNCTION(&_6, "sprintf", NULL, 73, &template, &_1);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVVVV(return_value, &_2, &_3, &_4, &_5, &_6);
	RETURN_MM();
}

/**
 * Generates a link to the current version documentation
 */
PHP_METHOD(Phalcon_Support_Debug, getVersion)
{
	zval version, link, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
	ZEPHIR_CONCAT_SVSVS(&link, "https://docs.phalcon.io/", &_0, ".", &_2, "/");
	ZEPHIR_CALL_METHOD(&_3, &version, "get", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSVS(return_value, "<div class='version'>\n    Phalcon Framework <a href='", &link, "' target='_new'>", &_3, "</a>\n</div>");
	RETURN_MM();
}

/**
 * Halts the request showing a backtrace
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Support_Debug, halt)
{

	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalcon_support_debug_exception_ce, "Halted request", "phalcon/Support/Debug.zep", 145);
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

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(exceptions)
		Z_PARAM_BOOL(lowSeverity)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &exceptions_param, &lowSeverity_param);
	if (!exceptions_param) {
		exceptions = 1;
	} else {
		}
	if (!lowSeverity_param) {
		lowSeverity = 0;
	} else {
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "onUncaughtLowSeverity");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 137, &_0);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &exception);
	ZEPHIR_CALL_FUNCTION(&obLevel, "ob_get_level", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&obLevel, 0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 500);
		zephir_check_call_status();
	}
	zephir_read_static_property_ce(&_0, phalcon_support_debug_ce, SL("isActive"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		zephir_update_static_property_ce(phalcon_support_debug_ce, ZEND_STRL("isActive"), &__$true);
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "renderhtml", NULL, 0, exception);
		zephir_check_call_status();
		zend_print_zval(&_1$$4, 0);
		zephir_update_static_property_ce(phalcon_support_debug_ce, ZEND_STRL("isActive"), &__$false);
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(&_2, exception, "getmessage", NULL, 0);
	zephir_check_call_status();
	zend_print_zval(&_2, 0);
	RETURN_MM_BOOL(0);
}

/**
 * Throws an exception when a notice or warning is raised
 */
PHP_METHOD(Phalcon_Support_Debug, onUncaughtLowSeverity)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *severity, severity_sub, *message, message_sub, *file, file_sub, *line, line_sub, _0, _1, _2$$3, _3$$3;

	ZVAL_UNDEF(&severity_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_ZVAL(severity)
		Z_PARAM_ZVAL(message)
		Z_PARAM_ZVAL(file)
		Z_PARAM_ZVAL(line)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &severity, &message, &file, &line);
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
		zephir_throw_exception_debug(&_2$$3, "phalcon/Support/Debug.zep", 244);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, _REQUEST, _SERVER, className, escapedMessage, html, _0, _1, _2, _3, _4, _5, _6, _15, _7$$3, _8$$3, _9$$3, _10$$3, _11$$3, _12$$3, _13$$3, _14$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&escapedMessage);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	ZEPHIR_CONCAT_SVSVSVS(&html, "<!DOCTYPE html>\n<html lang='en'>\n<head>\n    <title>", &className, ":", &escapedMessage, "</title>", &_1, "\n</head>\n<body>\n");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getversion", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&html, &_2);
	ZEPHIR_CALL_METHOD(&_3, exception, "getfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, exception, "getline", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVSVSVSVS(&_5, "\n<div align='center'>\n    <div class='error-main'>\n        <h1>", &className, ": ", &escapedMessage, "</h1>\n        <span class='error-file'>", &_3, " (", &_4, ")</span>\n    </div>");
	zephir_concat_self(&html, &_5);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("showBackTrace"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_6)) {
		zephir_concat_self_str(&html, SL("\n\n    <div class='error-info'>\n        <div id='tabs'>\n            <ul>\n                <li><a href='#backtrace'>Backtrace</a></li>\n                <li><a href='#request'>Request</a></li>\n                <li><a href='#server'>Server</a></li>\n                <li><a href='#files'>Included Files</a></li>\n                <li><a href='#memory'>Memory</a></li>"));
		zephir_memory_observe(&_7$$3);
		zephir_read_property(&_7$$3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(&_7$$3))) {
			zephir_concat_self_str(&html, SL("\n                <li><a href='#variables'>Variables</a></li>"));
		}
		zephir_concat_self_str(&html, SL("\n            </ul>"));
		ZEPHIR_CALL_METHOD(&_8$$3, this_ptr, "printbacktrace", NULL, 0, exception);
		zephir_check_call_status();
		zephir_concat_self(&html, &_8$$3);
		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "request");
		ZEPHIR_CALL_METHOD(&_9$$3, this_ptr, "printsuperglobal", NULL, 0, &_REQUEST, &_10$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_9$$3);
		ZEPHIR_INIT_NVAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "server");
		ZEPHIR_CALL_METHOD(&_11$$3, this_ptr, "printsuperglobal", NULL, 0, &_SERVER, &_10$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_11$$3);
		ZEPHIR_CALL_METHOD(&_12$$3, this_ptr, "printincludedfiles", NULL, 0);
		zephir_check_call_status();
		zephir_concat_self(&html, &_12$$3);
		ZEPHIR_CALL_METHOD(&_13$$3, this_ptr, "printmemoryusage", NULL, 0);
		zephir_check_call_status();
		zephir_concat_self(&html, &_13$$3);
		ZEPHIR_CALL_METHOD(&_14$$3, this_ptr, "printextravariables", NULL, 0);
		zephir_check_call_status();
		zephir_concat_self(&html, &_14$$3);
		zephir_concat_self_str(&html, SL("\n            </div>"));
	}
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "getjssources", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVS(return_value, &html, &_15, "\n        </div>\n    </body>\n</html>");
	RETURN_MM();
}

/**
 * Sets if files the exception's backtrace must be showed
 *
 * @param array $blacklist
 */
PHP_METHOD(Phalcon_Support_Debug, setBlacklist)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *blacklist_param = NULL, area, result, subArray, value, _0, _1, *_2, _3, _9, *_10, _11, _4$$3, _6$$3, _7$$4, _8$$4, _12$$5, _13$$5, _14$$6, _15$$6;
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
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(blacklist, blacklist_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_is_iterable(&area, 0, "phalcon/Support/Debug.zep", 354);
	if (Z_TYPE_P(&area) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&area), _2)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			ZEPHIR_CALL_FUNCTION(&_4$$3, "mb_strtolower", &_5, 7, &value);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value, &_4$$3);
			ZEPHIR_INIT_NVAR(&_6$$3);
			ZVAL_LONG(&_6$$3, 1);
			zephir_array_update_zval(&subArray, &value, &_6$$3, PH_COPY | PH_SEPARATE);
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
				ZEPHIR_CALL_FUNCTION(&_7$$4, "mb_strtolower", &_5, 7, &value);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&value, &_7$$4);
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZVAL_LONG(&_8$$4, 1);
				zephir_array_update_zval(&subArray, &value, &_8$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &area, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	zephir_array_update_string(&result, SL("request"), &subArray, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "server");
	ZEPHIR_CALL_METHOD(&area, this_ptr, "getarrval", NULL, 0, &blacklist, &_9, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&subArray);
	array_init(&subArray);
	zephir_is_iterable(&area, 0, "phalcon/Support/Debug.zep", 363);
	if (Z_TYPE_P(&area) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&area), _10)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _10);
			ZEPHIR_CALL_FUNCTION(&_12$$5, "mb_strtolower", &_5, 7, &value);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value, &_12$$5);
			ZEPHIR_INIT_NVAR(&_13$$5);
			ZVAL_LONG(&_13$$5, 1);
			zephir_array_update_zval(&subArray, &value, &_13$$5, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &area, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_11, &area, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &area, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_14$$6, "mb_strtolower", &_5, 7, &value);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&value, &_14$$6);
				ZEPHIR_INIT_NVAR(&_15$$6);
				ZVAL_LONG(&_15$$6, 1);
				zephir_array_update_zval(&subArray, &value, &_15$$6, PH_COPY | PH_SEPARATE);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(showBackTrace)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &showBackTrace_param);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(showFileFragment)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &showFileFragment_param);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(showFiles)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &showFiles_param);
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
	zval uri_zv;
	zend_string *uri = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&uri_zv, uri);
	zephir_update_property_zval(this_ptr, ZEND_STRL("uri"), &uri_zv);
	RETURN_THISW();
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
	zval value_zv, _0, _1, _2, _3, _4;
	zend_string *value = NULL;

	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&value_zv, value);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\n");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\\n");
	zephir_fast_str_replace(&_0, &_1, &_2, &value_zv);
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
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(argument, argument_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(n)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
	zephir_is_iterable(&argument, 0, "phalcon/Support/Debug.zep", 474);
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
			zephir_array_append(&dump, &_10$$5, PH_SEPARATE, "phalcon/Support/Debug.zep", 471);
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
				zephir_array_append(&dump, &_14$$12, PH_SEPARATE, "phalcon/Support/Debug.zep", 471);
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(variable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
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
 * @param int   $number
 * @param array $trace
 *
 * @return string
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Support_Debug, showTraceItem)
{
	zend_bool _31$$25, _40$$25;
	zval _24$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_17 = NULL, *_47 = NULL;
	zval trace;
	zval *number_param = NULL, *trace_param = NULL, className, prepareInternalClass, preparedFunctionName, html, classReflection, prepareUriClass, functionName, functionReflection, traceArgs, arguments, argument, file, line, lines, numberLines, firstLine, lastLine, linePosition, currentLine, classNameWithLink, functionNameWithLink, parts, _13, _0$$3, _1$$3, _8$$3, _9$$3, _2$$4, _3$$4, _4$$5, _5$$6, _6$$6, _7$$6, _10$$10, _11$$11, _12$$11, *_14$$14, _15$$14, _21$$14, _22$$14, _16$$15, _18$$15, _19$$16, _20$$16, _23$$17, _25$$17, _26$$17, _27$$18, _28$$19, _29$$24, _30$$25, _32$$26, _33$$26, _34$$26, _35$$26, _36$$26, _37$$27, _38$$27, _39$$27, _41$$29, _42$$29, _43$$29, _44$$29, _45$$29, _46$$29;
	zend_long number, ZEPHIR_LAST_CALL_STATUS, i = 0, beforeLine$$19, afterLine$$19;
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
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&numberLines);
	ZVAL_UNDEF(&firstLine);
	ZVAL_UNDEF(&lastLine);
	ZVAL_UNDEF(&linePosition);
	ZVAL_UNDEF(&currentLine);
	ZVAL_UNDEF(&classNameWithLink);
	ZVAL_UNDEF(&functionNameWithLink);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_16$$15);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$16);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$24);
	ZVAL_UNDEF(&_30$$25);
	ZVAL_UNDEF(&_32$$26);
	ZVAL_UNDEF(&_33$$26);
	ZVAL_UNDEF(&_34$$26);
	ZVAL_UNDEF(&_35$$26);
	ZVAL_UNDEF(&_36$$26);
	ZVAL_UNDEF(&_37$$27);
	ZVAL_UNDEF(&_38$$27);
	ZVAL_UNDEF(&_39$$27);
	ZVAL_UNDEF(&_41$$29);
	ZVAL_UNDEF(&_42$$29);
	ZVAL_UNDEF(&_43$$29);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_45$$29);
	ZVAL_UNDEF(&_46$$29);
	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&_24$$17);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(number)
		ZEPHIR_Z_PARAM_ARRAY(trace, trace_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &number_param, &trace_param);
	ZEPHIR_OBS_COPY_OR_DUP(&trace, trace_param);
	ZEPHIR_INIT_VAR(&html);
	ZVAL_STRING(&html, "\n                    <tr>\n                        <td style='text-align: right; vertical-align: top'\n                            class='error-number'>\n                            #\n                        </td>\n                        <td>");
	zephir_memory_observe(&className);
	if (zephir_array_isset_string_fetch(&className, &trace, SL("class"), 0)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "Phalcon");
		ZEPHIR_CALL_FUNCTION(&_1$$3, "str_starts_with", NULL, 340, &className, &_0$$3);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$3)) {
			ZEPHIR_INIT_VAR(&parts);
			zephir_fast_explode_str(&parts, SL("\\"), &className, LONG_MAX);
			zephir_array_fetch_long(&_2$$4, &parts, 0, PH_NOISY | PH_READONLY, "phalcon/Support/Debug.zep", 585);
			zephir_array_fetch_long(&_3$$4, &parts, 1, PH_NOISY | PH_READONLY, "phalcon/Support/Debug.zep", 585);
			ZEPHIR_INIT_VAR(&prepareUriClass);
			ZEPHIR_CONCAT_VSV(&prepareUriClass, &_2$$4, "_", &_3$$4);
			ZEPHIR_INIT_VAR(&classNameWithLink);
			ZEPHIR_CONCAT_SSVSVS(&classNameWithLink, "<a target='_new' ", "href='https://docs.phalcon.io/5.0/en/api/", &prepareUriClass, "'>", &className, "</a>");
		} else {
			ZEPHIR_INIT_VAR(&classReflection);
			object_init_ex(&classReflection, zephir_get_internal_ce(SL("reflectionclass")));
			ZEPHIR_CALL_METHOD(NULL, &classReflection, "__construct", NULL, 156, &className);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$5, &classReflection, "isinternal", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_4$$5)) {
				ZEPHIR_CALL_FUNCTION(&_5$$6, "mb_strtolower", NULL, 7, &className);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_6$$6);
				ZVAL_STRING(&_6$$6, "_");
				ZEPHIR_INIT_VAR(&_7$$6);
				ZVAL_STRING(&_7$$6, "-");
				ZEPHIR_INIT_VAR(&prepareInternalClass);
				zephir_fast_str_replace(&prepareInternalClass, &_6$$6, &_7$$6, &_5$$6);
				ZEPHIR_INIT_NVAR(&classNameWithLink);
				ZEPHIR_CONCAT_SSVSVS(&classNameWithLink, "<a target='_new' ", "href='https://secure.php.net/manual/en/class.", &prepareInternalClass, ".php'>", &className, "</a>");
			} else {
				ZEPHIR_CPY_WRT(&classNameWithLink, &className);
			}
		}
		ZEPHIR_INIT_VAR(&_8$$3);
		ZEPHIR_CONCAT_SVS(&_8$$3, "\n                        <span class='error-class'>\n                            ", &classNameWithLink, "\n                        </span>");
		zephir_concat_self(&html, &_8$$3);
		zephir_array_fetch_string(&_9$$3, &trace, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Support/Debug.zep", 622);
		zephir_concat_self(&html, &_9$$3);
	}
	zephir_memory_observe(&functionName);
	zephir_array_fetch_string(&functionName, &trace, SL("function"), PH_NOISY, "phalcon/Support/Debug.zep", 628);
	if (zephir_array_isset_string(&trace, SL("class"))) {
		ZEPHIR_CPY_WRT(&functionNameWithLink, &functionName);
	} else {
		if (1 == (zephir_function_exists(&functionName) == SUCCESS)) {
			ZEPHIR_INIT_VAR(&functionReflection);
			object_init_ex(&functionReflection, zephir_get_internal_ce(SL("reflectionfunction")));
			ZEPHIR_CALL_METHOD(NULL, &functionReflection, "__construct", NULL, 153, &functionName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_10$$10, &functionReflection, "isinternal", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_10$$10)) {
				ZEPHIR_INIT_VAR(&_11$$11);
				ZVAL_STRING(&_11$$11, "_");
				ZEPHIR_INIT_VAR(&_12$$11);
				ZVAL_STRING(&_12$$11, "-");
				ZEPHIR_INIT_VAR(&preparedFunctionName);
				zephir_fast_str_replace(&preparedFunctionName, &_11$$11, &_12$$11, &functionName);
				ZEPHIR_INIT_NVAR(&functionNameWithLink);
				ZEPHIR_CONCAT_SSVSVS(&functionNameWithLink, "<a target='_new' ", "href='https://secure.php.net/manual/en/function.", &preparedFunctionName, ".php'>", &functionName, "</a>");
			} else {
				ZEPHIR_CPY_WRT(&functionNameWithLink, &functionName);
			}
		} else {
			ZEPHIR_CPY_WRT(&functionNameWithLink, &functionName);
		}
	}
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_CONCAT_SVS(&_13, "\n                        <span class='error-function'>\n                            ", &functionNameWithLink, "\n                        </span>");
	zephir_concat_self(&html, &_13);
	zephir_memory_observe(&traceArgs);
	if (zephir_array_isset_string_fetch(&traceArgs, &trace, SL("args"), 0)) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
		zephir_is_iterable(&traceArgs, 0, "phalcon/Support/Debug.zep", 682);
		if (Z_TYPE_P(&traceArgs) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&traceArgs), _14$$14)
			{
				ZEPHIR_INIT_NVAR(&argument);
				ZVAL_COPY(&argument, _14$$14);
				ZEPHIR_CALL_METHOD(&_16$$15, this_ptr, "getvardump", &_17, 0, &argument);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_18$$15);
				ZEPHIR_CONCAT_SVS(&_18$$15, "\n                        <span class='error-parameter'>\n                            ", &_16$$15, "\n                        </span>");
				zephir_array_append(&arguments, &_18$$15, PH_SEPARATE, "phalcon/Support/Debug.zep", 676);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &traceArgs, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_15$$14, &traceArgs, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_15$$14)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&argument, &traceArgs, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_19$$16, this_ptr, "getvardump", &_17, 0, &argument);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_20$$16);
					ZEPHIR_CONCAT_SVS(&_20$$16, "\n                        <span class='error-parameter'>\n                            ", &_19$$16, "\n                        </span>");
					zephir_array_append(&arguments, &_20$$16, PH_SEPARATE, "phalcon/Support/Debug.zep", 676);
				ZEPHIR_CALL_METHOD(NULL, &traceArgs, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&argument);
		ZEPHIR_INIT_VAR(&_21$$14);
		zephir_fast_join_str(&_21$$14, SL(", "), &arguments);
		ZEPHIR_INIT_VAR(&_22$$14);
		ZEPHIR_CONCAT_SVS(&_22$$14, "(", &_21$$14, ")");
		zephir_concat_self(&html, &_22$$14);
	}
	if (zephir_array_isset_string(&trace, SL("file"))) {
		zephir_memory_observe(&file);
		zephir_array_fetch_string(&file, &trace, SL("file"), PH_NOISY, "phalcon/Support/Debug.zep", 690);
		zephir_memory_observe(&_23$$17);
		zephir_array_fetch_string(&_23$$17, &trace, SL("line"), PH_NOISY, "phalcon/Support/Debug.zep", 691);
		zephir_cast_to_string(&_24$$17, &_23$$17);
		ZEPHIR_CPY_WRT(&line, &_24$$17);
		ZEPHIR_INIT_VAR(&_25$$17);
		ZEPHIR_CONCAT_SVSVS(&_25$$17, "\n                        <br/>\n                        <div class='error-file'>\n                            ", &file, " (", &line, ")\n                        </div>");
		zephir_concat_self(&html, &_25$$17);
		zephir_read_property(&_26$$17, this_ptr, ZEND_STRL("showFiles"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_26$$17)) {
			ZEPHIR_CALL_FUNCTION(&lines, "file", NULL, 0, &file);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&numberLines);
			ZVAL_LONG(&numberLines, zephir_fast_count_int(&lines));
			zephir_read_property(&_27$$18, this_ptr, ZEND_STRL("showFileFragment"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_27$$18)) {
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
				ZEPHIR_INIT_VAR(&_28$$19);
				ZEPHIR_CONCAT_SVSVSVS(&_28$$19, "\n                        <pre class='prettyprint highlight:", &firstLine, ":", &line, " linenums:", &firstLine, "'>");
				zephir_concat_self(&html, &_28$$19);
			} else {
				ZEPHIR_INIT_NVAR(&firstLine);
				ZVAL_LONG(&firstLine, 1);
				ZEPHIR_CPY_WRT(&lastLine, &numberLines);
				ZEPHIR_INIT_VAR(&_29$$24);
				ZEPHIR_CONCAT_SVSVS(&_29$$24, "\n                        <pre class='prettyprint highlight:", &firstLine, ":", &line, " linenums error-scroll'>");
				zephir_concat_self(&html, &_29$$24);
			}
			i = zephir_get_numberval(&firstLine);
			while (1) {
				if (!(ZEPHIR_GE_LONG(&lastLine, i))) {
					break;
				}
				ZEPHIR_INIT_NVAR(&linePosition);
				ZVAL_LONG(&linePosition, (i - 1));
				ZEPHIR_OBS_NVAR(&currentLine);
				zephir_array_fetch(&currentLine, &lines, &linePosition, PH_NOISY, "phalcon/Support/Debug.zep", 760);
				zephir_read_property(&_30$$25, this_ptr, ZEND_STRL("showFileFragment"), PH_NOISY_CC | PH_READONLY);
				_31$$25 = zephir_is_true(&_30$$25);
				if (_31$$25) {
					_31$$25 = ZEPHIR_IS_LONG(&firstLine, i);
				}
				if (_31$$25) {
					ZEPHIR_INIT_NVAR(&_32$$26);
					ZEPHIR_INIT_NVAR(&_33$$26);
					zephir_fast_trim(&_33$$26, &currentLine, NULL , ZEPHIR_TRIM_RIGHT);
					ZEPHIR_INIT_NVAR(&_34$$26);
					ZVAL_STRING(&_34$$26, "#\\*\\/#");
					ZEPHIR_INIT_NVAR(&_35$$26);
					ZEPHIR_INIT_NVAR(&_36$$26);
					ZVAL_STRING(&_36$$26, "#\\*\\/#");
					zephir_preg_match(&_35$$26, &_36$$26, &_33$$26, &_32$$26, 0, 0 , 0 );
					if (zephir_is_true(&_35$$26)) {
						ZEPHIR_INIT_NVAR(&_37$$27);
						ZEPHIR_INIT_NVAR(&_38$$27);
						ZVAL_STRING(&_38$$27, "* /");
						ZEPHIR_INIT_NVAR(&_39$$27);
						ZVAL_STRING(&_39$$27, " ");
						zephir_fast_str_replace(&_37$$27, &_38$$27, &_39$$27, &currentLine);
						ZEPHIR_CPY_WRT(&currentLine, &_37$$27);
					}
				}
				_40$$25 = ZEPHIR_IS_STRING(&currentLine, "\n");
				if (!(_40$$25)) {
					_40$$25 = ZEPHIR_IS_STRING(&currentLine, "\r\n");
				}
				if (_40$$25) {
					zephir_concat_self_str(&html, SL("&nbsp;\n"));
				} else {
					ZEPHIR_INIT_NVAR(&_41$$29);
					ZEPHIR_INIT_NVAR(&_42$$29);
					ZVAL_STRING(&_42$$29, "\t");
					ZEPHIR_INIT_NVAR(&_43$$29);
					ZVAL_STRING(&_43$$29, "  ");
					zephir_fast_str_replace(&_41$$29, &_42$$29, &_43$$29, &currentLine);
					ZVAL_LONG(&_44$$29, 2);
					ZEPHIR_INIT_NVAR(&_45$$29);
					ZVAL_STRING(&_45$$29, "UTF-8");
					ZEPHIR_CALL_FUNCTION(&_46$$29, "htmlentities", &_47, 0, &_41$$29, &_44$$29, &_45$$29);
					zephir_check_call_status();
					zephir_concat_self(&html, &_46$$29);
				}
				i++;
			}
			zephir_concat_self_str(&html, SL("\n                            </pre>"));
		}
	}
	ZEPHIR_CONCAT_VS(return_value, &html, "\n                    </td>\n                </tr>");
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug, closeTable)
{

	RETURN_STRING("\n                </tbody>\n            </table>\n        </div>");
}

/**
 * @param Throwable $exception
 *
 * @return string
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Support_Debug, printBacktrace)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, html, trace, number, item, *_0, _1, _7, _4$$3, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &exception);
	ZEPHIR_INIT_VAR(&html);
	ZVAL_STRING(&html, "\n\n        <div id='backtrace'>\n            <table style='border-collapse: collapse; border-spacing: 0; text-align=center; width:100%'>\n                <tbody>");
	ZEPHIR_CALL_METHOD(&trace, exception, "gettrace", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&trace, 0, "phalcon/Support/Debug.zep", 832);
	if (Z_TYPE_P(&trace) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&trace), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&number);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&number, _3);
			} else {
				ZVAL_LONG(&number, _2);
			}
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "showtraceitem", &_5, 0, &number, &item);
			zephir_check_call_status();
			zephir_concat_self(&html, &_4$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &trace, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &trace, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&number, &trace, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&item, &trace, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "showtraceitem", &_5, 0, &number, &item);
				zephir_check_call_status();
				zephir_concat_self(&html, &_6$$4);
			ZEPHIR_CALL_METHOD(NULL, &trace, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&number);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "closetable", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &html, &_7);
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug, printExtraVariables)
{
	zend_string *_9$$3;
	zend_ulong _8$$3;
	zval html, key, value, _0, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, *_6$$3, _7$$3, _17$$3, _10$$4, _11$$4, _13$$4, _14$$5, _15$$5, _16$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&html);
	ZVAL_STRING(&html, "");
	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_0))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "variables");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Key");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Value");
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "printtableheader", NULL, 0, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_1$$3);
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_5$$3, 0, "phalcon/Support/Debug.zep", 854);
		if (Z_TYPE_P(&_5$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_5$$3), _8$$3, _9$$3, _6$$3)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_9$$3 != NULL) { 
					ZVAL_STR_COPY(&key, _9$$3);
				} else {
					ZVAL_LONG(&key, _8$$3);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _6$$3);
				zephir_array_fetch_long(&_11$$4, &value, 0, PH_NOISY | PH_READONLY, "phalcon/Support/Debug.zep", 850);
				ZEPHIR_CALL_METHOD(&_10$$4, this_ptr, "getvardump", &_12, 0, &_11$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_13$$4);
				ZEPHIR_CONCAT_SVSVS(&_13$$4, "<tr><td class=\"key\">", &key, "</td><td>", &_10$$4, "</td></tr>");
				zephir_concat_self(&html, &_13$$4);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_5$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_7$$3, &_5$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &_5$$3, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&value, &_5$$3, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_fetch_long(&_15$$5, &value, 0, PH_NOISY | PH_READONLY, "phalcon/Support/Debug.zep", 850);
					ZEPHIR_CALL_METHOD(&_14$$5, this_ptr, "getvardump", &_12, 0, &_15$$5);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_16$$5);
					ZEPHIR_CONCAT_SVSVS(&_16$$5, "<tr><td class=\"key\">", &key, "</td><td>", &_14$$5, "</td></tr>");
					zephir_concat_self(&html, &_16$$5);
				ZEPHIR_CALL_METHOD(NULL, &_5$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		ZEPHIR_CALL_METHOD(&_17$$3, this_ptr, "closetable", NULL, 0);
		zephir_check_call_status();
		zephir_concat_self(&html, &_17$$3);
	}
	RETURN_CCTOR(&html);
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug, printIncludedFiles)
{
	zend_string *_7;
	zend_ulong _6;
	zval html, key, value, _0, _1, _2, _3, *_4, _5, _10, _8$$3, _9$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "files");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "#");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Path");
	ZEPHIR_CALL_METHOD(&html, this_ptr, "printtableheader", NULL, 0, &_0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "get_included_files", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_3, 0, "phalcon/Support/Debug.zep", 873);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_3), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&key, _7);
			} else {
				ZVAL_LONG(&key, _6);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _4);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZEPHIR_CONCAT_SVSVS(&_8$$3, "\n                        <tr>\n                            <td>", &key, "</td>\n                            <td>", &value, "</td>\n                        </tr>");
			zephir_concat_self(&html, &_8$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_3, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &_3, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &_3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZEPHIR_CONCAT_SVSVS(&_9$$4, "\n                        <tr>\n                            <td>", &key, "</td>\n                            <td>", &value, "</td>\n                        </tr>");
				zephir_concat_self(&html, &_9$$4);
			ZEPHIR_CALL_METHOD(NULL, &_3, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "closetable", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &html, &_10);
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug, printMemoryUsage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, _0, _1, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "memory");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Memory");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "printtableheader", NULL, 0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "memory_get_usage", NULL, 0, &__$true);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVS(return_value, &_0, "\n                    <tr>\n                        <td>\n                            Usage\n                        </td>\n                        <td>", &_4, "</td>\n                    </tr>\n                </tbody>\n                </table>\n            </div>");
	RETURN_MM();
}

/**
 * @param array  $source
 * @param string $div
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug, printSuperglobal)
{
	zend_ulong _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *div = NULL, *_6;
	zval *source_param = NULL, div_zv, html, filter, key, value, _0, _1, _2, *_3, _4, _7$$3, _9$$4, _11$$4, _12$$5, _13$$6, _14$$6;
	zval source;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&div_zv);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(source, source_param)
		Z_PARAM_STR(div)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	source_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&source, source_param);
	ZVAL_STR_COPY(&div_zv, div);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Key");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Value");
	ZEPHIR_CALL_METHOD(&html, this_ptr, "printtableheader", NULL, 0, &div_zv, &_0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("blacklist"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_0);
	array_init(&_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "server");
	ZEPHIR_CALL_METHOD(&filter, this_ptr, "getarrval", NULL, 0, &_2, &_1, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&source, 0, "phalcon/Support/Debug.zep", 906);
	if (Z_TYPE_P(&source) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&source), _5, _6, _3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_6 != NULL) { 
				ZVAL_STR_COPY(&key, _6);
			} else {
				ZVAL_LONG(&key, _5);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3);
			ZEPHIR_CALL_FUNCTION(&_7$$3, "mb_strtolower", &_8, 7, &key);
			zephir_check_call_status();
			if (!(zephir_array_isset(&filter, &_7$$3))) {
				ZEPHIR_CALL_METHOD(&_9$$4, this_ptr, "getvardump", &_10, 0, &value);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_11$$4);
				ZEPHIR_CONCAT_SVSVS(&_11$$4, "\n                    <tr>\n                        <td class='key'>", &key, "</td>\n                        <td>", &_9$$4, "</td>\n                    </tr>");
				zephir_concat_self(&html, &_11$$4);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &source, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &source, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &source, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &source, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_12$$5, "mb_strtolower", &_8, 7, &key);
				zephir_check_call_status();
				if (!(zephir_array_isset(&filter, &_12$$5))) {
					ZEPHIR_CALL_METHOD(&_13$$6, this_ptr, "getvardump", &_10, 0, &value);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_14$$6);
					ZEPHIR_CONCAT_SVSVS(&_14$$6, "\n                    <tr>\n                        <td class='key'>", &key, "</td>\n                        <td>", &_13$$6, "</td>\n                    </tr>");
					zephir_concat_self(&html, &_14$$6);
				}
			ZEPHIR_CALL_METHOD(NULL, &source, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CONCAT_VS(return_value, &html, "\n                    </tbody>\n                </table>\n            </div>");
	RETURN_MM();
}

/**
 * @param string $divId
 * @param string $headerOne
 * @param string $headerTwo
 * @param string $colspan
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug, printTableHeader)
{
	zval _0$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval divId_zv, headerOne_zv, headerTwo_zv, colspan_zv, span;
	zend_string *divId = NULL, *headerOne = NULL, *headerTwo = NULL, *colspan = NULL;

	ZVAL_UNDEF(&divId_zv);
	ZVAL_UNDEF(&headerOne_zv);
	ZVAL_UNDEF(&headerTwo_zv);
	ZVAL_UNDEF(&colspan_zv);
	ZVAL_UNDEF(&span);
	ZVAL_UNDEF(&_0$$4);
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(divId)
		Z_PARAM_STR(headerOne)
		Z_PARAM_STR(headerTwo)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(colspan)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&divId_zv, divId);
	ZVAL_STR_COPY(&headerOne_zv, headerOne);
	ZVAL_STR_COPY(&headerTwo_zv, headerTwo);
	if (!colspan) {
		colspan = zend_string_init(ZEND_STRL(""), 0);
		ZVAL_STR(&colspan_zv, colspan);
	} else {
		ZVAL_STR_COPY(&colspan_zv, colspan);
	}
	ZEPHIR_INIT_VAR(&span);
	if (ZEPHIR_IS_EMPTY(&colspan_zv)) {
		ZVAL_STRING(&span, "");
	} else {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_CONCAT_SVS(&_0$$4, " colspan=\"", &colspan_zv, "\"");
		ZEPHIR_CPY_WRT(&span, &_0$$4);
	}
	ZEPHIR_CONCAT_SVSVSVSVS(return_value, "\n        <div id='", &divId_zv, "'>\n            <table style='border-collapse: collapse; border-spacing: 0; text-align: center'\n                   class='superglobal-detail'>\n                <thead>\n                <tr>\n                    <th", &span, ">", &headerOne_zv, "</th>\n                </tr>\n                <tr>\n                    <th>", &headerTwo_zv, "</th>\n                </tr>\n                </thead>\n                <tbody>");
	RETURN_MM();
}

/**
 * @todo Remove this when we get traits
 */
PHP_METHOD(Phalcon_Support_Debug, getArrVal)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *collection_param = NULL, *index, index_sub, *defaultValue = NULL, defaultValue_sub, __$null, value;
	zval collection;

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &collection_param, &index, &defaultValue);
	ZEPHIR_OBS_COPY_OR_DUP(&collection, collection_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	zephir_memory_observe(&value);
	if (UNEXPECTED(!(zephir_array_isset_fetch(&value, &collection, index, 0)))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	RETURN_CCTOR(&value);
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
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
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

