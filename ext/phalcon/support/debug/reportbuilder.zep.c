
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Collects the runtime data for an exception (backtrace, superglobals, included
 * files, memory, variables) into an ExceptionReport. Holds no presentation
 * logic.
 *
 * @phpstan-import-type support_debug_blacklist from SupportTypes
 * @phpstan-import-type support_debug_fragment from SupportTypes
 * @phpstan-import-type support_debug_superglobal from SupportTypes
 * @phpstan-import-type support_debug_trace from SupportTypes
 * @phpstan-import-type support_debug_variables from SupportTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Debug_ReportBuilder)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Debug, ReportBuilder, phalcon, support_debug_reportbuilder, phalcon_support_debug_reportbuilder_method_entry, 0);

	/**
	 * The lines of each file that the current report read
	 *
	 * @var array<string, array<int, string>>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_support_debug_reportbuilder_ce, SL("fileLines"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

/**
 * @phpstan-param support_debug_blacklist $blacklist
 * @phpstan-param support_debug_variables $data
 *
 * @return ExceptionReport
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, build)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *uri = NULL;
	zend_bool showBackTrace, showFiles, showFileFragment, _16;
	zval blacklist, data, _6$$3;
	zval *exception, exception_sub, *blacklist_param = NULL, *showBackTrace_param = NULL, *showFiles_param = NULL, *showFileFragment_param = NULL, uri_zv, *data_param = NULL, _REQUEST, _SERVER, __$true, report, items, trace, item, previous, previousExceptions, _0, _1, _2, _3, _4, _5, *_9, _10, *_11, _15, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _7$$3, _8$$3, _12$$5, _13$$5, _14$$5, _17$$6, _18$$6, _19$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&uri_zv);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&report);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&previous);
	ZVAL_UNDEF(&previousExceptions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&blacklist);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_6$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[28];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("fileLines", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
		ZEPHIR_Z_PARAM_ARRAY(blacklist, blacklist_param)
		Z_PARAM_BOOL(showBackTrace)
		Z_PARAM_BOOL(showFiles)
		Z_PARAM_BOOL(showFileFragment)
		Z_PARAM_STR(uri)
		ZEPHIR_Z_PARAM_ARRAY(data, data_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	exception = ZEND_CALL_ARG(execute_data, 1);
	blacklist_param = ZEND_CALL_ARG(execute_data, 2);
	showBackTrace_param = ZEND_CALL_ARG(execute_data, 3);
	showFiles_param = ZEND_CALL_ARG(execute_data, 4);
	showFileFragment_param = ZEND_CALL_ARG(execute_data, 5);
	data_param = ZEND_CALL_ARG(execute_data, 7);
	zephir_get_arrval(&blacklist, blacklist_param);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	zephir_get_arrval(&data, data_param);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1403, &_0);
	ZEPHIR_INIT_VAR(&report);
	object_init_ex(&report, phalcon_support_debug_report_exceptionreport_ce);
	ZEPHIR_INIT_VAR(&_1);
	zephir_get_class(&_1, exception, 0);
	ZEPHIR_CALL_METHOD_CACHED(&_2, exception, "getMessage", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_3, exception, "getFile", &_zephir_call_cache[1]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_4, exception, "getLine", &_zephir_call_cache[2]);
	zephir_check_call_status();
	if (showBackTrace) {
		ZVAL_BOOL(&_5, 1);
	} else {
		ZVAL_BOOL(&_5, 0);
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &report, "__construct", &_zephir_call_cache[3], &_1, &_2, &_3, &_4, &_5, &uri_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&previousExceptions);
	array_init(&previousExceptions);
	ZEPHIR_CALL_METHOD_CACHED(&previous, exception, "getPrevious", &_zephir_call_cache[4]);
	zephir_check_call_status();
	while (1) {
		if (!(Z_TYPE_P(&previous) != IS_NULL)) {
			break;
		}
		ZEPHIR_INIT_NVAR(&_6$$3);
		zephir_create_array(&_6$$3, 4, 0);
		ZEPHIR_INIT_NVAR(&_7$$3);
		zephir_get_class(&_7$$3, &previous, 0);
		zephir_array_update_string(&_6$$3, SL("className"), &_7$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(&_8$$3, &previous, "getMessage", &_zephir_call_cache[5]);
		zephir_check_call_status();
		zephir_array_update_string(&_6$$3, SL("message"), &_8$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(&_8$$3, &previous, "getFile", &_zephir_call_cache[6]);
		zephir_check_call_status();
		zephir_array_update_string(&_6$$3, SL("file"), &_8$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(&_8$$3, &previous, "getLine", &_zephir_call_cache[7]);
		zephir_check_call_status();
		zephir_array_update_string(&_6$$3, SL("line"), &_8$$3, PH_COPY | PH_SEPARATE);
		zephir_array_append(&previousExceptions, &_6$$3, PH_SEPARATE, "phalcon/Support/Debug/ReportBuilder.zep", 84);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_8$$3, &previous, "getPrevious", &_zephir_call_cache[8]);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&previous, &_8$$3);
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, &report, "setPreviousExceptions", &_zephir_call_cache[9], &previousExceptions);
	zephir_check_call_status();
	if (showBackTrace != 1) {
		RETURN_CCTOR(&report);
	}
	ZEPHIR_INIT_VAR(&items);
	array_init(&items);
	ZEPHIR_CALL_METHOD_CACHED(&trace, exception, "getTrace", &_zephir_call_cache[10]);
	zephir_check_call_status();
	if (Z_TYPE_P(&trace) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_10);
		zephir_string_to_char_array(&_10, &trace);
		_9 = &_10;
	} else {
		_9 = &trace;
	}
	zephir_is_iterable(_9, 0, "phalcon/Support/Debug/ReportBuilder.zep", 101);
	if (Z_TYPE_P(_9) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_9), _11)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _11);
			if (showFiles) {
				ZVAL_BOOL(&_13$$5, 1);
			} else {
				ZVAL_BOOL(&_13$$5, 0);
			}
			if (showFileFragment) {
				ZVAL_BOOL(&_14$$5, 1);
			} else {
				ZVAL_BOOL(&_14$$5, 0);
			}
			ZEPHIR_CALL_METHOD_CACHED(&_12$$5, this_ptr, "buildItem", &_zephir_call_cache[11], &item, &_13$$5, &_14$$5);
			zephir_check_call_status();
			zephir_array_append(&items, &_12$$5, PH_SEPARATE, "phalcon/Support/Debug/ReportBuilder.zep", 98);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _9, "rewind", &_zephir_call_cache[12]);
		zephir_check_call_status();
		_16 = 1;
		while (1) {
			if (_16) {
				_16 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _9, "next", &_zephir_call_cache[13]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_15, _9, "valid", &_zephir_call_cache[14]);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&item, _9, "current", &_zephir_call_cache[15]);
			zephir_check_call_status();
				if (showFiles) {
					ZVAL_BOOL(&_18$$6, 1);
				} else {
					ZVAL_BOOL(&_18$$6, 0);
				}
				if (showFileFragment) {
					ZVAL_BOOL(&_19$$6, 1);
				} else {
					ZVAL_BOOL(&_19$$6, 0);
				}
				ZEPHIR_CALL_METHOD_CACHED(&_17$$6, this_ptr, "buildItem", &_zephir_call_cache[16], &item, &_18$$6, &_19$$6);
				zephir_check_call_status();
				zephir_array_append(&items, &_17$$6, PH_SEPARATE, "phalcon/Support/Debug/ReportBuilder.zep", 98);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_CALL_METHOD_CACHED(NULL, &report, "setBacktrace", &_zephir_call_cache[17], &items);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_22);
	array_init(&_22);
	ZEPHIR_INIT_VAR(&_23);
	ZVAL_STRING(&_23, "request");
	ZEPHIR_CALL_METHOD_CACHED(&_21, this_ptr, "getArrVal", &_zephir_call_cache[18], &blacklist, &_23, &_22);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_20, this_ptr, "filter", &_zephir_call_cache[19], &_REQUEST, &_21);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &report, "setRequest", &_zephir_call_cache[20], &_20);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_23);
	array_init(&_23);
	ZEPHIR_INIT_VAR(&_26);
	ZVAL_STRING(&_26, "server");
	ZEPHIR_CALL_METHOD_CACHED(&_25, this_ptr, "getArrVal", &_zephir_call_cache[21], &blacklist, &_26, &_23);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_24, this_ptr, "filter", &_zephir_call_cache[22], &_SERVER, &_25);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &report, "setServer", &_zephir_call_cache[23], &_24);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_27, "get_included_files", NULL, 272);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &report, "setIncludedFiles", &_zephir_call_cache[24], &_27);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_28, "memory_get_usage", NULL, 249, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &report, "setMemoryUsage", &_zephir_call_cache[25], &_28);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_29, "memory_get_peak_usage", NULL, 273, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &report, "setPeakMemoryUsage", &_zephir_call_cache[26], &_29);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(NULL, &report, "setVariables", &_zephir_call_cache[27], &data);
	zephir_check_call_status();
	RETURN_CCTOR(&report);
}

/**
 * @phpstan-return support_debug_fragment
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, buildFragment)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool showFileFragment, _0$$3;
	zend_long line, ZEPHIR_LAST_CALL_STATUS;
	zval file_zv, *line_param = NULL, *showFileFragment_param = NULL, lines, numberLines, firstLine, lastLine, beforeLine, afterLine, _1;
	zend_string *file = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&numberLines);
	ZVAL_UNDEF(&firstLine);
	ZVAL_UNDEF(&lastLine);
	ZVAL_UNDEF(&beforeLine);
	ZVAL_UNDEF(&afterLine);
	ZVAL_UNDEF(&_1);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(file)
		Z_PARAM_LONG(line)
		Z_PARAM_BOOL(showFileFragment)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	line_param = ZEND_CALL_ARG(execute_data, 2);
	showFileFragment_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	ZEPHIR_CALL_METHOD_CACHED(&lines, this_ptr, "readLines", &_zephir_call_cache[0], &file_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&numberLines);
	ZVAL_LONG(&numberLines, zephir_fast_count_int(&lines));
	ZEPHIR_INIT_VAR(&firstLine);
	if (showFileFragment == 1) {
		ZEPHIR_INIT_VAR(&beforeLine);
		ZVAL_LONG(&beforeLine, (line - 7));
		if (ZEPHIR_LT_LONG(&beforeLine, 1)) {
			ZVAL_LONG(&firstLine, 1);
		} else {
			ZEPHIR_CPY_WRT(&firstLine, &beforeLine);
		}
		ZEPHIR_INIT_VAR(&afterLine);
		ZVAL_LONG(&afterLine, (line + 5));
		_0$$3 = ZEPHIR_GT(&afterLine, &numberLines);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_0$$3) {
			ZEPHIR_CPY_WRT(&lastLine, &numberLines);
		} else {
			ZEPHIR_CPY_WRT(&lastLine, &afterLine);
		}
	} else {
		ZVAL_LONG(&firstLine, 1);
		ZEPHIR_CPY_WRT(&lastLine, &numberLines);
	}
	zephir_create_array(return_value, 4, 0);
	zephir_array_update_string(return_value, SL("firstLine"), &firstLine, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, line);
	zephir_array_update_string(return_value, SL("line"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("lastLine"), &lastLine, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("lines"), &lines, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * @phpstan-param support_debug_trace $trace
 *
 * @param array<array-key, mixed> $trace
 * @param bool                    $showFiles
 * @param bool                    $showFileFragment
 *
 * @return BacktraceItem
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, buildItem)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool showFiles, showFileFragment, hasArgs = 0, _0, _2, _3, _4, _1$$3;
	zval *trace_param = NULL, *showFiles_param = NULL, *showFileFragment_param = NULL, className, classLink, type, functionLink, functionName, args, file, line, fragment, _6, _5$$8;
	zval trace;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&classLink);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&functionLink);
	ZVAL_UNDEF(&functionName);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&fragment);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_5$$8);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(trace, trace_param)
		Z_PARAM_BOOL(showFiles)
		Z_PARAM_BOOL(showFileFragment)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &trace_param, &showFiles_param, &showFileFragment_param);
	zephir_get_arrval(&trace, trace_param);
	ZEPHIR_INIT_VAR(&className);
	ZVAL_NULL(&className);
	ZEPHIR_INIT_VAR(&classLink);
	ZVAL_NULL(&classLink);
	ZEPHIR_INIT_VAR(&type);
	ZVAL_NULL(&type);
	ZEPHIR_INIT_VAR(&functionLink);
	ZVAL_NULL(&functionLink);
	ZEPHIR_INIT_VAR(&file);
	ZVAL_NULL(&file);
	ZEPHIR_INIT_VAR(&line);
	ZVAL_NULL(&line);
	ZEPHIR_INIT_VAR(&fragment);
	ZVAL_NULL(&fragment);
	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	_0 = zephir_array_isset_value_string(&trace, SL("class"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		ZEPHIR_OBS_NVAR(&className);
		zephir_array_fetch_string(&className, &trace, SL("class"), PH_NOISY, "phalcon/Support/Debug/ReportBuilder.zep", 169);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_1$$3 = zephir_array_isset_value_string(&trace, SL("type"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_1$$3) {
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_string(&type, &trace, SL("type"), PH_NOISY, "phalcon/Support/Debug/ReportBuilder.zep", 172);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_CALL_METHOD_CACHED(&classLink, this_ptr, "resolveClassLink", &_zephir_call_cache[0], &className);
		zephir_check_call_status();
	}
	zephir_memory_observe(&functionName);
	zephir_array_fetch_string(&functionName, &trace, SL("function"), PH_NOISY, "phalcon/Support/Debug/ReportBuilder.zep", 178);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_array_isset_value_string(&trace, SL("class"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_2)) {
		ZEPHIR_CALL_METHOD_CACHED(&functionLink, this_ptr, "resolveFunctionLink", &_zephir_call_cache[1], &functionName);
		zephir_check_call_status();
	}
	_3 = zephir_array_isset_value_string(&trace, SL("args"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	hasArgs = _3;
	if (hasArgs) {
		ZEPHIR_OBS_NVAR(&args);
		zephir_array_fetch_string(&args, &trace, SL("args"), PH_NOISY, "phalcon/Support/Debug/ReportBuilder.zep", 186);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_4 = zephir_array_isset_value_string(&trace, SL("file"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_4) {
		ZEPHIR_OBS_NVAR(&file);
		zephir_array_fetch_string(&file, &trace, SL("file"), PH_NOISY, "phalcon/Support/Debug/ReportBuilder.zep", 190);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&line);
		zephir_array_fetch_string(&line, &trace, SL("line"), PH_NOISY, "phalcon/Support/Debug/ReportBuilder.zep", 191);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (showFiles == 1) {
			if (showFileFragment) {
				ZVAL_BOOL(&_5$$8, 1);
			} else {
				ZVAL_BOOL(&_5$$8, 0);
			}
			ZEPHIR_CALL_METHOD_CACHED(&fragment, this_ptr, "buildFragment", &_zephir_call_cache[2], &file, &line, &_5$$8);
			zephir_check_call_status();
		}
	}
	object_init_ex(return_value, phalcon_support_debug_report_backtraceitem_ce);
	if (hasArgs) {
		ZVAL_BOOL(&_6, 1);
	} else {
		ZVAL_BOOL(&_6, 0);
	}
	ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[3], &functionName, &type, &className, &classLink, &functionLink, &_6, &args, &file, &line, &fragment);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @phpstan-param  support_debug_superglobal $source
 * @phpstan-param  array<string, int>        $blacklist
 * @phpstan-return support_debug_superglobal
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, filter)
{
	zend_bool _8, _5$$3, _10$$6;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, *blacklist_param = NULL, result, key, value, *_0, _7, _3$$3, _6$$5, _9$$6, _11$$8;
	zval source, blacklist;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&blacklist);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_11$$8);
	ZEND_TLS zephir_method_cache _zephir_call_cache[7];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(source, source_param)
		ZEPHIR_Z_PARAM_ARRAY(blacklist, blacklist_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &source_param, &blacklist_param);
	zephir_get_arrval(&source, source_param);
	zephir_get_arrval(&blacklist, blacklist_param);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&source, 0, "phalcon/Support/Debug/ReportBuilder.zep", 233);
	if (Z_TYPE_P(&source) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&source), _1, _2, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2 != NULL) { 
				ZVAL_STR_COPY(&key, _2);
			} else {
				ZVAL_LONG(&key, _1);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_CALL_FUNCTION(&_3$$3, "mb_strtolower", &_4, 9, &key);
			zephir_check_call_status();
			_5$$3 = zephir_array_isset_value(&blacklist, &_3$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_5$$3)) {
				if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD_CACHED(&_6$$5, this_ptr, "filter", &_zephir_call_cache[0], &value, &blacklist);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&value, &_6$$5);
				}
				zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &source, "rewind", &_zephir_call_cache[1]);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &source, "next", &_zephir_call_cache[2]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_7, &source, "valid", &_zephir_call_cache[3]);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, &source, "key", &_zephir_call_cache[4]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &source, "current", &_zephir_call_cache[5]);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_9$$6, "mb_strtolower", &_4, 9, &key);
				zephir_check_call_status();
				_10$$6 = zephir_array_isset_value(&blacklist, &_9$$6);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_10$$6)) {
					if (Z_TYPE_P(&value) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD_CACHED(&_11$$8, this_ptr, "filter", &_zephir_call_cache[6], &value, &blacklist);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&value, &_11$$8);
					}
					zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);
}

/**
 * Reads each file one time for each report. It reads the file only if it
 * exists and is readable. This prevents a warning for eval()'d code.
 *
 * @return array<int, string>
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, readLines)
{
	zend_bool _1, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval file_zv, lines, _0, _5, _6, _2$$3, _4$$3;
	zend_string *file = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("fileLines", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(file)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1403, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_value(&_0, &file_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		ZEPHIR_INIT_VAR(&lines);
		ZVAL_BOOL(&lines, 0);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "is_file", NULL, 113, &file_zv);
		zephir_check_call_status();
		_3$$3 = zephir_is_true(&_2$$3);
		if (_3$$3) {
			ZEPHIR_CALL_FUNCTION(&_4$$3, "is_readable", NULL, 162, &file_zv);
			zephir_check_call_status();
			_3$$3 = zephir_is_true(&_4$$3);
		}
		if (_3$$3) {
			ZEPHIR_CALL_FUNCTION(&lines, "file", NULL, 274, &file_zv);
			zephir_check_call_status();
		}
		if (ZEPHIR_IS_FALSE_IDENTICAL(&lines)) {
			ZEPHIR_INIT_NVAR(&lines);
			array_init(&lines);
		}
		zephir_update_property_array(this_ptr, SL("fileLines"), &file_zv, &lines);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_0, 1403, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_6);
	zephir_array_fetch(&_6, &_5, &file_zv, PH_NOISY, "phalcon/Support/Debug/ReportBuilder.zep", 259);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&_6);
}

/**
 * @phpstan-param class-string $className
 *
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, resolveClassLink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, parts, reflection, prepared, version, _0, _1, _10, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _11$$4, _12$$4, _13$$4;
	zend_string *className = NULL;

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&prepared);
	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Phalcon\\");
	ZEPHIR_CALL_FUNCTION(&_1, "str_starts_with", NULL, 171, &className_zv, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&parts);
		zephir_fast_explode_str(&parts, SL("\\"), &className_zv, NULL);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&version);
		object_init_ex(&version, phalcon_support_version_ce);
		if (zephir_has_constructor(&version)) {
			ZEPHIR_CALL_METHOD_CACHED(NULL, &version, "__construct", &_zephir_call_cache[0]);
			zephir_check_call_status();
		}

		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_CALL_METHOD_CACHED(&_2$$3, &version, "getPart", &_zephir_call_cache[1], &_3$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_3$$3, 1);
		ZEPHIR_CALL_METHOD_CACHED(&_4$$3, &version, "getPart", &_zephir_call_cache[2], &_3$$3);
		zephir_check_call_status();
		zephir_memory_observe(&_5$$3);
		zephir_array_fetch_long(&_5$$3, &parts, 0, PH_NOISY, "phalcon/Support/Debug/ReportBuilder.zep", 280);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_6$$3);
		zephir_array_fetch_long(&_6$$3, &parts, 1, PH_NOISY, "phalcon/Support/Debug/ReportBuilder.zep", 280);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_7$$3);
		ZEPHIR_CONCAT_VSV(&_7$$3, &_5$$3, "_", &_6$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_FUNCTION(&_8$$3, "mb_strtolower", &_9, 9, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVSVSVS(return_value, "https://docs.phalcon.io/", &_2$$3, ".", &_4$$3, "/api/", &_8$$3, "/");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD_CACHED(NULL, &reflection, "__construct", &_zephir_call_cache[3], &className_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_10, &reflection, "isInternal", &_zephir_call_cache[4]);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_10)) {
		ZEPHIR_CALL_FUNCTION(&_11$$4, "mb_strtolower", &_9, 9, &className_zv);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_12$$4);
		ZVAL_STRING(&_12$$4, "_");
		ZEPHIR_INIT_VAR(&_13$$4);
		ZVAL_STRING(&_13$$4, "-");
		ZEPHIR_INIT_VAR(&prepared);
		zephir_fast_str_replace(&prepared, &_12$$4, &_13$$4, &_11$$4);
		ZEPHIR_CONCAT_SVS(return_value, "https://secure.php.net/manual/en/class.", &prepared, ".php");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	RETURN_MM_NULL();
}

/**
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, resolveFunctionLink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval functionName_zv, reflection, prepared, _0, _1, _2, _3;
	zend_string *functionName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&functionName_zv);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&prepared);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(functionName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&functionName_zv);
	ZVAL_STR_COPY(&functionName_zv, functionName);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "phpFunctionExists", &_zephir_call_cache[0], &functionName_zv);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionfunction")));
	ZEPHIR_CALL_METHOD_CACHED(NULL, &reflection, "__construct", &_zephir_call_cache[1], &functionName_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_1, &reflection, "isInternal", &_zephir_call_cache[2]);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "_");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "-");
	ZEPHIR_INIT_VAR(&prepared);
	zephir_fast_str_replace(&prepared, &_2, &_3, &functionName_zv);
	ZEPHIR_CONCAT_SVS(return_value, "https://secure.php.net/manual/en/function.", &prepared, ".php");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * @param array       $collection
 * @param mixed       $index
 * @param mixed|null  $defaultValue
 * @param string|null $cast
 *
 * @return mixed|null
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, getArrVal)
{
	zend_bool _0;
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
	_0 = zephir_array_isset_value(&collection, index);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (1 == _0) {
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_fetch(&value, &collection, index, PH_NOISY, "phalcon/Traits/Support/Helper/Arr/GetTrait.zep", 38);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (!(ZEPHIR_IS_EMPTY(&cast_zv))) {
		ZEPHIR_MAKE_REF(&value);
		ZEPHIR_CALL_FUNCTION(NULL, "settype", NULL, 10, &value, &cast_zv);
		ZEPHIR_UNREF(&value);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&value);
}

/**
 * Find out whether an extension is loaded
 *
 * @param string $name
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.extension-loaded.php
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, phpExtensionLoaded)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 114, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Return true if the given function has been defined
 *
 * @param string $functionName
 *
 * @return bool
 *
 * @link https://php.net/manual/en/function.function-exists.php
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, phpFunctionExists)
{
	zval functionName_zv;
	zend_string *functionName = NULL;

	ZVAL_UNDEF(&functionName_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(functionName)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&functionName_zv, functionName);
	RETURN_BOOL((zephir_function_exists(&functionName_zv) == SUCCESS));
}

