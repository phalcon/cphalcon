
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
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_support_debug_report_exceptionreport_ce, SL("backtrace"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_support_debug_report_exceptionreport_ce, SL("className"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_support_debug_report_exceptionreport_ce, SL("file"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_support_debug_report_exceptionreport_ce, SL("includedFiles"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_support_debug_report_exceptionreport_ce, SL("line"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_LONG, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_support_debug_report_exceptionreport_ce, SL("memoryUsage"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_LONG, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_support_debug_report_exceptionreport_ce, SL("message"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_LONG(&_zc0, 0);
		zephir_declare_typed_property(phalcon_support_debug_report_exceptionreport_ce, SL("peakMemoryUsage"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_LONG, NULL, 0);
	}

	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_support_debug_report_exceptionreport_ce, SL("request"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_support_debug_report_exceptionreport_ce, SL("server"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_support_debug_report_exceptionreport_ce, SL("showBackTrace"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_BOOL, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_support_debug_report_exceptionreport_ce, SL("uri"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_support_debug_report_exceptionreport_ce, SL("variables"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	static zend_string *_zephir_prop_3 = NULL;
	static zend_string *_zephir_prop_4 = NULL;
	static zend_string *_zephir_prop_5 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("className", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("message", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("file", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_3)) {
		_zephir_prop_3 = zend_string_init("line", 4, 1);
	}
	if (UNEXPECTED(!_zephir_prop_4)) {
		_zephir_prop_4 = zend_string_init("showBackTrace", 13, 1);
	}
	if (UNEXPECTED(!_zephir_prop_5)) {
		_zephir_prop_5 = zend_string_init("uri", 3, 1);
	}

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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1359, &className_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 1360, &message_zv);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 1361, &file_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, line);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_3, 1362, &_0);
	if (showBackTrace) {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1363, &__$true);
	} else {
		zephir_update_property_zval_cached(this_ptr, _zephir_prop_4, 1363, &__$false);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_5, 1364, &uri_zv);
}

/**
 * @return BacktraceItem[]
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getBacktrace)
{

	RETURN_MEMBER_TYPED(getThis(), "backtrace", IS_ARRAY);
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getClassName)
{

	RETURN_MEMBER_TYPED(getThis(), "className", IS_STRING);
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getFile)
{

	RETURN_MEMBER_TYPED(getThis(), "file", IS_STRING);
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getIncludedFiles)
{

	RETURN_MEMBER_TYPED(getThis(), "includedFiles", IS_ARRAY);
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getLine)
{

	RETURN_MEMBER_TYPED(getThis(), "line", IS_LONG);
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getMemoryUsage)
{

	RETURN_MEMBER_TYPED(getThis(), "memoryUsage", IS_LONG);
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getMessage)
{

	RETURN_MEMBER_TYPED(getThis(), "message", IS_STRING);
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getPeakMemoryUsage)
{

	RETURN_MEMBER_TYPED(getThis(), "peakMemoryUsage", IS_LONG);
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getRequest)
{

	RETURN_MEMBER_TYPED(getThis(), "request", IS_ARRAY);
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getServer)
{

	RETURN_MEMBER_TYPED(getThis(), "server", IS_ARRAY);
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getUri)
{

	RETURN_MEMBER_TYPED(getThis(), "uri", IS_STRING);
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, getVariables)
{

	RETURN_MEMBER_TYPED(getThis(), "variables", IS_ARRAY);
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, hasVariables)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("variables", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&_0);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1365, PH_NOISY_CC);
	RETURN_MM_BOOL(!(ZEPHIR_IS_EMPTY(&_0)));
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, isShowBackTrace)
{

	RETURN_MEMBER(getThis(), "showBackTrace");
}

/**
 * @param BacktraceItem[] $backtrace
 */
PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, setBacktrace)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *backtrace_param = NULL;
	zval backtrace;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&backtrace);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("backtrace", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(backtrace, backtrace_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &backtrace_param);
	zephir_get_arrval(&backtrace, backtrace_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1366, &backtrace);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, setIncludedFiles)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *includedFiles_param = NULL;
	zval includedFiles;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&includedFiles);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("includedFiles", 13, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(includedFiles, includedFiles_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &includedFiles_param);
	zephir_get_arrval(&includedFiles, includedFiles_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1367, &includedFiles);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, setMemoryUsage)
{
	zval *memoryUsage_param = NULL, _0;
	zend_long memoryUsage;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("memoryUsage", 11, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(memoryUsage)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &memoryUsage_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, memoryUsage);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1368, &_0);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, setPeakMemoryUsage)
{
	zval *peakMemoryUsage_param = NULL, _0;
	zend_long peakMemoryUsage;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("peakMemoryUsage", 15, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(peakMemoryUsage)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &peakMemoryUsage_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, peakMemoryUsage);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1369, &_0);
	RETURN_THISW();
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, setRequest)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *request_param = NULL;
	zval request;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("request", 7, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(request, request_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &request_param);
	zephir_get_arrval(&request, request_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1370, &request);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, setServer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *server_param = NULL;
	zval server;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&server);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("server", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(server, server_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &server_param);
	zephir_get_arrval(&server, server_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1371, &server);
	RETURN_THIS();
}

PHP_METHOD(Phalcon_Support_Debug_Report_ExceptionReport, setVariables)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *variables_param = NULL;
	zval variables;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variables);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("variables", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(variables, variables_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &variables_param);
	zephir_get_arrval(&variables, variables_param);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1365, &variables);
	RETURN_THIS();
}

