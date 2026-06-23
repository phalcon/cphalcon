
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Collects the runtime data for an exception (backtrace, superglobals, included
 * files, memory, variables) into an ExceptionReport. Holds no presentation
 * logic.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Debug_ReportBuilder)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Debug, ReportBuilder, phalcon, support_debug_reportbuilder, phalcon_support_debug_reportbuilder_method_entry, 0);

	return SUCCESS;
}

/**
 * @param Throwable $exception
 * @param array     $blacklist
 * @param bool      $showBackTrace
 * @param bool      $showFiles
 * @param bool      $showFileFragment
 * @param string    $uri
 * @param array     $data
 *
 * @return ExceptionReport
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, build)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *uri = NULL;
	zend_bool showBackTrace, showFiles, showFileFragment, _11;
	zval blacklist, data;
	zval *exception, exception_sub, *blacklist_param = NULL, *showBackTrace_param = NULL, *showFiles_param = NULL, *showFileFragment_param = NULL, uri_zv, *data_param = NULL, _REQUEST, _SERVER, __$true, report, items, trace, item, getter, _0, _1, _2, _3, _4, *_5, _10, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _6$$4, _7$$4, _8$$4, _12$$5, _13$$5, _14$$5;
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
	ZVAL_UNDEF(&getter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&blacklist);
	ZVAL_UNDEF(&data);
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
	ZEPHIR_INIT_VAR(&report);
	object_init_ex(&report, phalcon_support_debug_report_exceptionreport_ce);
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, exception, 0);
	ZEPHIR_CALL_METHOD(&_1, exception, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, exception, "getfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, exception, "getline", NULL, 0);
	zephir_check_call_status();
	if (showBackTrace) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &report, "__construct", NULL, 0, &_0, &_1, &_2, &_3, &_4, &uri_zv);
	zephir_check_call_status();
	if (showBackTrace != 1) {
		RETURN_CCTOR(&report);
	}
	ZEPHIR_INIT_VAR(&items);
	array_init(&items);
	ZEPHIR_CALL_METHOD(&trace, exception, "gettrace", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&trace, 0, "phalcon/Support/Debug/ReportBuilder.zep", 71);
	if (Z_TYPE_P(&trace) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&trace), _5)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _5);
			if (showFiles) {
				ZVAL_BOOL(&_7$$4, 1);
			} else {
				ZVAL_BOOL(&_7$$4, 0);
			}
			if (showFileFragment) {
				ZVAL_BOOL(&_8$$4, 1);
			} else {
				ZVAL_BOOL(&_8$$4, 0);
			}
			ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "builditem", &_9, 0, &item, &_7$$4, &_8$$4);
			zephir_check_call_status();
			zephir_array_append(&items, &_6$$4, PH_SEPARATE, "phalcon/Support/Debug/ReportBuilder.zep", 68);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &trace, "rewind", NULL, 0);
		zephir_check_call_status();
		_11 = 1;
		while (1) {
			if (_11) {
				_11 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &trace, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_10, &trace, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_10)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &trace, "current", NULL, 0);
			zephir_check_call_status();
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
				ZEPHIR_CALL_METHOD(&_12$$5, this_ptr, "builditem", &_9, 0, &item, &_13$$5, &_14$$5);
				zephir_check_call_status();
				zephir_array_append(&items, &_12$$5, PH_SEPARATE, "phalcon/Support/Debug/ReportBuilder.zep", 68);
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_VAR(&getter);
	object_init_ex(&getter, phalcon_support_helper_arr_get_ce);
	if (zephir_has_constructor(&getter)) {
		ZEPHIR_CALL_METHOD(NULL, &getter, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(NULL, &report, "setbacktrace", NULL, 0, &items);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_17);
	array_init(&_17);
	ZEPHIR_INIT_VAR(&_18);
	ZVAL_STRING(&_18, "request");
	ZEPHIR_CALL_METHOD(&_16, &getter, "__invoke", NULL, 16, &blacklist, &_18, &_17);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "filter", NULL, 0, &_REQUEST, &_16);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &report, "setrequest", NULL, 0, &_15);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_18);
	array_init(&_18);
	ZEPHIR_INIT_VAR(&_21);
	ZVAL_STRING(&_21, "server");
	ZEPHIR_CALL_METHOD(&_20, &getter, "__invoke", NULL, 16, &blacklist, &_21, &_18);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_19, this_ptr, "filter", NULL, 0, &_SERVER, &_20);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &report, "setserver", NULL, 0, &_19);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_22, "get_included_files", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &report, "setincludedfiles", NULL, 0, &_22);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_23, "memory_get_usage", NULL, 0, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &report, "setmemoryusage", NULL, 0, &_23);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_24, "memory_get_peak_usage", NULL, 0, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &report, "setpeakmemoryusage", NULL, 0, &_24);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &report, "setvariables", NULL, 0, &data);
	zephir_check_call_status();
	RETURN_CCTOR(&report);
}

/**
 * @param string $file
 * @param int    $line
 * @param bool   $showFileFragment
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, buildFragment)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool showFileFragment;
	zend_long line, ZEPHIR_LAST_CALL_STATUS;
	zval file_zv, *line_param = NULL, *showFileFragment_param = NULL, lines, numberLines, firstLine, lastLine, mode, beforeLine, afterLine, _0;
	zend_string *file = NULL;

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&numberLines);
	ZVAL_UNDEF(&firstLine);
	ZVAL_UNDEF(&lastLine);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&beforeLine);
	ZVAL_UNDEF(&afterLine);
	ZVAL_UNDEF(&_0);
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
	ZEPHIR_CALL_FUNCTION(&lines, "file", NULL, 0, &file_zv);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&lines)) {
		ZEPHIR_INIT_NVAR(&lines);
		array_init(&lines);
	}
	ZEPHIR_INIT_VAR(&numberLines);
	ZVAL_LONG(&numberLines, zephir_fast_count_int(&lines));
	ZEPHIR_INIT_VAR(&firstLine);
	ZEPHIR_INIT_VAR(&mode);
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
		if (ZEPHIR_GT(&afterLine, &numberLines)) {
			ZEPHIR_CPY_WRT(&lastLine, &numberLines);
		} else {
			ZEPHIR_CPY_WRT(&lastLine, &afterLine);
		}
		ZVAL_STRING(&mode, "fragment");
	} else {
		ZVAL_LONG(&firstLine, 1);
		ZEPHIR_CPY_WRT(&lastLine, &numberLines);
		ZVAL_STRING(&mode, "full");
	}
	zephir_create_array(return_value, 5, 0);
	zephir_array_update_string(return_value, SL("mode"), &mode, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("firstLine"), &firstLine, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, line);
	zephir_array_update_string(return_value, SL("line"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("lastLine"), &lastLine, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("lines"), &lines, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

/**
 * @param array $trace
 * @param bool  $showFiles
 * @param bool  $showFileFragment
 *
 * @return BacktraceItem
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, buildItem)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool showFiles, showFileFragment, hasArgs = 0;
	zval *trace_param = NULL, *showFiles_param = NULL, *showFileFragment_param = NULL, className, classLink, type, functionLink, functionName, args, file, line, fragment, _1, _0$$8;
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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$8);
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
	if (zephir_array_isset_value_string(&trace, SL("class"))) {
		ZEPHIR_OBS_NVAR(&className);
		zephir_array_fetch_string(&className, &trace, SL("class"), PH_NOISY, "phalcon/Support/Debug/ReportBuilder.zep", 150);
		if (zephir_array_isset_value_string(&trace, SL("type"))) {
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_string(&type, &trace, SL("type"), PH_NOISY, "phalcon/Support/Debug/ReportBuilder.zep", 153);
		}
		ZEPHIR_CALL_METHOD(&classLink, this_ptr, "resolveclasslink", NULL, 0, &className);
		zephir_check_call_status();
	}
	zephir_memory_observe(&functionName);
	zephir_array_fetch_string(&functionName, &trace, SL("function"), PH_NOISY, "phalcon/Support/Debug/ReportBuilder.zep", 159);
	if (!(zephir_array_isset_value_string(&trace, SL("class")))) {
		ZEPHIR_CALL_METHOD(&functionLink, this_ptr, "resolvefunctionlink", NULL, 0, &functionName);
		zephir_check_call_status();
	}
	hasArgs = zephir_array_isset_value_string(&trace, SL("args"));
	if (hasArgs) {
		ZEPHIR_OBS_NVAR(&args);
		zephir_array_fetch_string(&args, &trace, SL("args"), PH_NOISY, "phalcon/Support/Debug/ReportBuilder.zep", 167);
	}
	if (zephir_array_isset_value_string(&trace, SL("file"))) {
		ZEPHIR_OBS_NVAR(&file);
		zephir_array_fetch_string(&file, &trace, SL("file"), PH_NOISY, "phalcon/Support/Debug/ReportBuilder.zep", 171);
		ZEPHIR_OBS_NVAR(&line);
		zephir_array_fetch_string(&line, &trace, SL("line"), PH_NOISY, "phalcon/Support/Debug/ReportBuilder.zep", 172);
		if (showFiles == 1) {
			if (showFileFragment) {
				ZVAL_BOOL(&_0$$8, 1);
			} else {
				ZVAL_BOOL(&_0$$8, 0);
			}
			ZEPHIR_CALL_METHOD(&fragment, this_ptr, "buildfragment", NULL, 0, &file, &line, &_0$$8);
			zephir_check_call_status();
		}
	}
	object_init_ex(return_value, phalcon_support_debug_report_backtraceitem_ce);
	if (hasArgs) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &functionName, &type, &className, &classLink, &functionLink, &_1, &args, &file, &line, &fragment);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param array $source
 * @param array $blacklist
 *
 * @return array
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, filter)
{
	zend_bool _6;
	zend_string *_2;
	zend_ulong _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, *blacklist_param = NULL, result, key, value, *_0, _5, _3$$3, _7$$5;
	zval source, blacklist;

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&blacklist);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$5);
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
	zephir_is_iterable(&source, 0, "phalcon/Support/Debug/ReportBuilder.zep", 211);
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
			ZEPHIR_CALL_FUNCTION(&_3$$3, "mb_strtolower", &_4, 15, &key);
			zephir_check_call_status();
			if (!(zephir_array_isset_value(&blacklist, &_3$$3))) {
				zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &source, "rewind", NULL, 0);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &source, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_5, &source, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &source, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &source, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_7$$5, "mb_strtolower", &_4, 15, &key);
				zephir_check_call_status();
				if (!(zephir_array_isset_value(&blacklist, &_7$$5))) {
					zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);
}

/**
 * @param string $className
 *
 * @return string|null
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, resolveClassLink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, parts, reflection, prepared, _0, _1, _4, _2$$3, _3$$3, _5$$4, _6$$4, _7$$4;
	zend_string *className = NULL;

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&prepared);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Phalcon");
	ZEPHIR_CALL_FUNCTION(&_1, "str_starts_with", NULL, 0, &className_zv, &_0);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&parts);
		zephir_fast_explode_str(&parts, SL("\\"), &className_zv, LONG_MAX);
		zephir_array_fetch_long(&_2$$3, &parts, 0, PH_NOISY | PH_READONLY, "phalcon/Support/Debug/ReportBuilder.zep", 227);
		zephir_array_fetch_long(&_3$$3, &parts, 1, PH_NOISY | PH_READONLY, "phalcon/Support/Debug/ReportBuilder.zep", 227);
		ZEPHIR_CONCAT_SVSV(return_value, "https://docs.phalcon.io/5.0/en/api/", &_2$$3, "_", &_3$$3);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 223, &className_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, &reflection, "isinternal", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_4)) {
		ZEPHIR_CALL_FUNCTION(&_5$$4, "mb_strtolower", NULL, 15, &className_zv);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "_");
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "-");
		ZEPHIR_INIT_VAR(&prepared);
		zephir_fast_str_replace(&prepared, &_6$$4, &_7$$4, &_5$$4);
		ZEPHIR_CONCAT_SVS(return_value, "https://secure.php.net/manual/en/class.", &prepared, ".php");
		RETURN_MM();
	}
	RETURN_MM_NULL();
}

/**
 * @param string $functionName
 *
 * @return string|null
 * @throws ReflectionException
 */
PHP_METHOD(Phalcon_Support_Debug_ReportBuilder, resolveFunctionLink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval functionName_zv, reflection, prepared, _0, _1, _2;
	zend_string *functionName = NULL;

	ZVAL_UNDEF(&functionName_zv);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&prepared);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(functionName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&functionName_zv);
	ZVAL_STR_COPY(&functionName_zv, functionName);
	if ((zephir_function_exists(&functionName_zv) == SUCCESS) != 1) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&reflection);
	object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionfunction")));
	ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 220, &functionName_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &reflection, "isinternal", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "_");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "-");
	ZEPHIR_INIT_VAR(&prepared);
	zephir_fast_str_replace(&prepared, &_1, &_2, &functionName_zv);
	ZEPHIR_CONCAT_SVS(return_value, "https://secure.php.net/manual/en/function.", &prepared, ".php");
	RETURN_MM();
}

