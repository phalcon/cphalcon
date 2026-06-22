
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Carries all data collected for an exception, ready to be rendered. Holds no
 * presentation logic.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Debug_Report_ExceptionReport)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Debug\\Report, ExceptionReport, phalcon, support_debug_report_exceptionreport, phalcon_support_debug_report_exceptionreport_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var BacktraceItem[]
	 */
	zend_declare_property_null(phalcon_support_debug_report_exceptionreport_ce, SL("backtrace"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_support_debug_report_exceptionreport_ce, SL("className"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_support_debug_report_exceptionreport_ce, SL("file"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_support_debug_report_exceptionreport_ce, SL("includedFiles"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_null(phalcon_support_debug_report_exceptionreport_ce, SL("line"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_support_debug_report_exceptionreport_ce, SL("memoryUsage"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_support_debug_report_exceptionreport_ce, SL("message"), ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_support_debug_report_exceptionreport_ce, SL("peakMemoryUsage"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_support_debug_report_exceptionreport_ce, SL("request"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_support_debug_report_exceptionreport_ce, SL("server"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_null(phalcon_support_debug_report_exceptionreport_ce, SL("showBackTrace"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_support_debug_report_exceptionreport_ce, SL("uri"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_support_debug_report_exceptionreport_ce, SL("variables"), ZEND_ACC_PROTECTED);
	phalcon_support_debug_report_exceptionreport_ce->create_object = zephir_init_properties_Phalcon_Support_Debug_Report_ExceptionReport;

	return SUCCESS;
}

/**
 * @param string $className
 * @param string $message
 * @param string $file
 * @param int    $line
 * @param bool   $showBackTrace
 * @param string $uri
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, __construct)
{
	zend_bool showBackTrace;
	zend_long line;
	zval className_zv, message_zv, file_zv, *line_param = NULL, *showBackTrace_param = NULL, uri_zv, __$true, __$false, _0;
	zend_string *className = NULL, *message = NULL, *file = NULL, *uri = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&message_zv);
	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&uri_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_STR(className)
		Z_PARAM_STR(message)
		Z_PARAM_STR(file)
		Z_PARAM_LONG(line)
		Z_PARAM_BOOL(showBackTrace)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	line_param = ZEND_CALL_ARG(execute_data, 4);
	showBackTrace_param = ZEND_CALL_ARG(execute_data, 5);
	ZVAL_STR(&className_zv, className);
	ZVAL_STR(&message_zv, message);
	ZVAL_STR(&file_zv, file);
	ZVAL_STR(&uri_zv, uri);
	zephir_update_property_zval(this_ptr, ZEND_STRL("className"), &className_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("message"), &message_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("file"), &file_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, line);
	zephir_update_property_zval(this_ptr, ZEND_STRL("line"), &_0);
	if (showBackTrace) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("showBackTrace"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("showBackTrace"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("uri"), &uri_zv);
}

/**
 * @return BacktraceItem[]
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getBacktrace)
{

	RETURN_MEMBER_TYPED(getThis(), "backtrace", IS_ARRAY);
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getClassName)
{

	RETURN_MEMBER_TYPED(getThis(), "className", IS_STRING);
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getFile)
{

	RETURN_MEMBER_TYPED(getThis(), "file", IS_STRING);
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getIncludedFiles)
{

	RETURN_MEMBER_TYPED(getThis(), "includedFiles", IS_ARRAY);
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getLine)
{

	RETURN_MEMBER_TYPED(getThis(), "line", IS_LONG);
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getMemoryUsage)
{

	RETURN_MEMBER_TYPED(getThis(), "memoryUsage", IS_LONG);
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getMessage)
{

	RETURN_MEMBER_TYPED(getThis(), "message", IS_STRING);
}

/**
 * @return int
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getPeakMemoryUsage)
{

	RETURN_MEMBER_TYPED(getThis(), "peakMemoryUsage", IS_LONG);
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getRequest)
{

	RETURN_MEMBER_TYPED(getThis(), "request", IS_ARRAY);
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getServer)
{

	RETURN_MEMBER_TYPED(getThis(), "server", IS_ARRAY);
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getUri)
{

	RETURN_MEMBER_TYPED(getThis(), "uri", IS_STRING);
}

/**
 * @return array
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getVariables)
{

	RETURN_MEMBER_TYPED(getThis(), "variables", IS_ARRAY);
}

/**
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, hasVariables)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("variables"), PH_NOISY_CC);
	RETURN_MM_BOOL(!(ZEPHIR_IS_EMPTY(&_0)));
}

/**
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, isShowBackTrace)
{

	RETURN_MEMBER(getThis(), "showBackTrace");
}

/**
 * @param BacktraceItem[] $backtrace
 *
 * @return static
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, setBacktrace)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *backtrace_param = NULL;
	zval backtrace;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&backtrace);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(backtrace, backtrace_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &backtrace_param);
	zephir_get_arrval(&backtrace, backtrace_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("backtrace"), &backtrace);
	RETURN_THIS();
}

/**
 * @param array $includedFiles
 *
 * @return static
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, setIncludedFiles)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *includedFiles_param = NULL;
	zval includedFiles;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&includedFiles);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(includedFiles, includedFiles_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &includedFiles_param);
	zephir_get_arrval(&includedFiles, includedFiles_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("includedFiles"), &includedFiles);
	RETURN_THIS();
}

/**
 * @param int $memoryUsage
 *
 * @return static
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, setMemoryUsage)
{
	zval *memoryUsage_param = NULL, _0;
	zend_long memoryUsage;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(memoryUsage)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &memoryUsage_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, memoryUsage);
	zephir_update_property_zval(this_ptr, ZEND_STRL("memoryUsage"), &_0);
	RETURN_THISW();
}

/**
 * @param int $peakMemoryUsage
 *
 * @return static
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, setPeakMemoryUsage)
{
	zval *peakMemoryUsage_param = NULL, _0;
	zend_long peakMemoryUsage;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(peakMemoryUsage)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &peakMemoryUsage_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, peakMemoryUsage);
	zephir_update_property_zval(this_ptr, ZEND_STRL("peakMemoryUsage"), &_0);
	RETURN_THISW();
}

/**
 * @param array $request
 *
 * @return static
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, setRequest)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *request_param = NULL;
	zval request;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(request, request_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &request_param);
	zephir_get_arrval(&request, request_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("request"), &request);
	RETURN_THIS();
}

/**
 * @param array $server
 *
 * @return static
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, setServer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *server_param = NULL;
	zval server;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&server);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(server, server_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &server_param);
	zephir_get_arrval(&server, server_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("server"), &server);
	RETURN_THIS();
}

/**
 * @param array $variables
 *
 * @return static
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, setVariables)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *variables_param = NULL;
	zval variables;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variables);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(variables, variables_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &variables_param);
	zephir_get_arrval(&variables, variables_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("variables"), &variables);
	RETURN_THIS();
}

zend_object *zephir_init_properties_Phalcon_Support_Debug_Report_ExceptionReport(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _8, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("variables"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("variables"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("server"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("server"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("request"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("request"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("includedFiles"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("includedFiles"), &_7$$6);
		}
		zephir_read_property_ex(&_8, this_ptr, ZEND_STRL("backtrace"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("backtrace"), &_9$$7);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

