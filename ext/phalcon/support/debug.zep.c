
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/time.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Listens for uncaught exceptions and renders them. Acts as a thin coordinator
 * delegating data collection to ReportBuilder and presentation to a Renderer.
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
	 * @var Renderer
	 */
	zend_declare_property_null(phalcon_support_debug_ce, SL("renderer"), ZEND_ACC_PROTECTED);
	/**
	 * @var ReportBuilder
	 */
	zend_declare_property_null(phalcon_support_debug_ce, SL("reportBuilder"), ZEND_ACC_PROTECTED);
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

PHP_METHOD(Phalcon_Support_Debug, __construct)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("renderer", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("reportBuilder", 13, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_support_debug_renderer_htmlrenderer_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1313, &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_support_debug_reportbuilder_ce);
	if (zephir_has_constructor(&_1)) {
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1314, &_1);
	ZEPHIR_MM_RESTORE();
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("data", 4, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1315, &_0);
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
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("renderer", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("uri", 3, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1313, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1316, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getcsssources", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the JavaScript sources
 */
PHP_METHOD(Phalcon_Support_Debug, getJsSources)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("renderer", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("uri", 3, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1313, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1316, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getjssources", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the renderer used to produce the output
 */
PHP_METHOD(Phalcon_Support_Debug, getRenderer)
{

	RETURN_MEMBER(getThis(), "renderer");
}

/**
 * Generates a link to the current version documentation
 */
PHP_METHOD(Phalcon_Support_Debug, getVersion)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("renderer", 8, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1313, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getversion", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Halts the request showing a backtrace
 *
 * @throws RequestHalted
 */
PHP_METHOD(Phalcon_Support_Debug, halt)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_support_debug_exceptions_requesthalted_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "phalcon/Support/Debug.zep", 151);
	ZEPHIR_MM_RESTORE();
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
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 286, &_0);
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
 *
 * @throws ReflectionException
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
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 0);
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
		object_init_ex(&_2$$3, phalcon_support_debug_exceptions_runtimewarning_ce);
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0, message, &_3$$3, severity, file, line);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Support/Debug.zep", 252);
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
	zval *exception, exception_sub, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	static zend_string *_zephir_prop_6 = NULL;
	static zend_string *_zephir_prop_7 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("renderer", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("reportBuilder", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("blacklist", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("showBackTrace", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("showFiles", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("showFileFragment", 16, 1);
	}
	if (UNEXPECTED(!_zephir_prop_6)) {
		_zephir_prop_6 = zend_string_init("uri", 3, 1);
	}
	if (UNEXPECTED(!_zephir_prop_7)) {
		_zephir_prop_7 = zend_string_init("data", 4, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &exception);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1313, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 1314, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_2, 1317, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_3, 1318, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_4, 1319, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_6, this_ptr, _zephir_prop_5, 1320, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_7, this_ptr, _zephir_prop_6, 1316, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_8, this_ptr, _zephir_prop_7, 1315, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "build", NULL, 0, exception, &_3, &_4, &_5, &_6, &_7, &_8);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "render", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Sets if files the exception's backtrace must be showed
 *
 * @param array $blacklist
 */
PHP_METHOD(Phalcon_Support_Debug, setBlacklist)
{
	zend_bool _7, _15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *blacklist_param = NULL, area, result, subArray, value, _0, _1, *_2, _6, _10, *_11, _14, _3$$3, _5$$3, _8$$4, _9$$4, _12$$5, _13$$5, _16$$6, _17$$6;
	zval blacklist;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&blacklist);
	ZVAL_UNDEF(&area);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&subArray);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("blacklist", 9, 1);
	}

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
	zephir_is_iterable(&area, 0, "phalcon/Support/Debug.zep", 297);
	if (Z_TYPE_P(&area) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&area), _2)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			ZEPHIR_CALL_FUNCTION(&_3$$3, "mb_strtolower", &_4, 15, &value);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value, &_3$$3);
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZVAL_LONG(&_5$$3, 1);
			zephir_array_update_zval(&subArray, &value, &_5$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &area, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &area, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &area, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &area, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_8$$4, "mb_strtolower", &_4, 15, &value);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&value, &_8$$4);
				ZEPHIR_INIT_NVAR(&_9$$4);
				ZVAL_LONG(&_9$$4, 1);
				zephir_array_update_zval(&subArray, &value, &_9$$4, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	zephir_array_update_string(&result, SL("request"), &subArray, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "server");
	ZEPHIR_CALL_METHOD(&area, this_ptr, "getarrval", NULL, 0, &blacklist, &_10, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&subArray);
	array_init(&subArray);
	zephir_is_iterable(&area, 0, "phalcon/Support/Debug.zep", 306);
	if (Z_TYPE_P(&area) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&area), _11)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _11);
			ZEPHIR_CALL_FUNCTION(&_12$$5, "mb_strtolower", &_4, 15, &value);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&value, &_12$$5);
			ZEPHIR_INIT_NVAR(&_13$$5);
			ZVAL_LONG(&_13$$5, 1);
			zephir_array_update_zval(&subArray, &value, &_13$$5, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &area, "rewind", NULL, 0);
		zephir_check_call_status();
		_15 = 1;
		while (1) {
			if (_15) {
				_15 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &area, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_14, &area, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&value, &area, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_16$$6, "mb_strtolower", &_4, 15, &value);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&value, &_16$$6);
				ZEPHIR_INIT_NVAR(&_17$$6);
				ZVAL_LONG(&_17$$6, 1);
				zephir_array_update_zval(&subArray, &value, &_17$$6, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	zephir_array_update_string(&result, SL("server"), &subArray, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1317, &result);
	RETURN_THIS();
}

/**
 * Sets the renderer used to produce the output
 *
 * @param Renderer $renderer
 */
PHP_METHOD(Phalcon_Support_Debug, setRenderer)
{
	zval *renderer, renderer_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&renderer_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("renderer", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(renderer, phalcon_contracts_support_debug_renderer_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &renderer);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1313, renderer);
	RETURN_THISW();
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("showBackTrace", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(showBackTrace)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &showBackTrace_param);
	if (showBackTrace) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1318, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1318, &__$false);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("showFileFragment", 16, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(showFileFragment)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &showFileFragment_param);
	if (showFileFragment) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1320, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1320, &__$false);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("showFiles", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(showFiles)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &showFiles_param);
	if (showFiles) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1319, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1319, &__$false);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("uri", 3, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&uri_zv, uri);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1316, &uri_zv);
	RETURN_THISW();
}

/**
 * @param array       $collection
 * @param mixed       $index
 * @param mixed|null  $defaultValue
 * @param string|null $cast
 *
 * @return mixed|null
 */
PHP_METHOD(Phalcon_Support_Debug, getArrVal)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *cast = NULL;
	zval *collection_param = NULL, *index, index_sub, *defaultValue = NULL, defaultValue_sub, cast_zv, __$null, value;
	zval collection;

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_UNDEF(&cast_zv);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 4)
		ZEPHIR_Z_PARAM_ARRAY(collection, collection_param)
		Z_PARAM_ZVAL(index)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_STR_OR_NULL(cast)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	collection_param = ZEND_CALL_ARG(execute_data, 1);
	index = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		defaultValue = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_get_arrval(&collection, collection_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!cast) {
		ZEPHIR_INIT_VAR(&cast_zv);
	} else {
		zephir_memory_observe(&cast_zv);
	ZVAL_STR_COPY(&cast_zv, cast);
	}
	ZEPHIR_CPY_WRT(&value, defaultValue);
	if (1 == zephir_array_isset_value(&collection, index)) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_fetch(&value, &collection, index, PH_NOISY, "phalcon/Traits/Support/Helper/Arr/GetTrait.zep", 38);
	}
	if (!(ZEPHIR_IS_EMPTY(&cast_zv))) {
		ZEPHIR_MAKE_REF(&value);
		ZEPHIR_CALL_FUNCTION(NULL, "settype", NULL, 16, &value, &cast_zv);
		ZEPHIR_UNREF(&value);
		zephir_check_call_status();
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

