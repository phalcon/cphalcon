
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Renders an ExceptionReport as the HTML debug page using embedded, overridable
 * template strings filled by the interpolator. All styling and interactivity
 * (theme, tabs, syntax highlighting, copy/editor links) are provided by the
 * external debug.css / debug.js assets.
 *
 * @phpstan-import-type support_debug_args from SupportTypes
 * @phpstan-import-type support_debug_fragment from SupportTypes
 * @phpstan-import-type support_debug_included_files from SupportTypes
 * @phpstan-import-type support_debug_previous from SupportTypes
 * @phpstan-import-type support_debug_superglobal from SupportTypes
 * @phpstan-import-type support_debug_variables from SupportTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Debug_Renderer_HtmlRenderer)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Debug\\Renderer, HtmlRenderer, phalcon, support_debug_renderer_htmlrenderer, phalcon_support_debug_renderer_htmlrenderer_method_entry, 0);

	/**
	 * @phpstan-var support_debug_templates
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_support_debug_renderer_htmlrenderer_ce, SL("templates"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	zend_class_implements(phalcon_support_debug_renderer_htmlrenderer_ce, 1, phalcon_contracts_support_debug_renderer_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, getCssSources)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, _0, _1;
	zend_string *uri = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "cssLink");
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getTemplate", &_zephir_call_cache[0], &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_update_string(&_2, SL("uri"), &uri_zv, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&_2, SL("path"), SL("debug.css"));
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "toInterpolate", &_zephir_call_cache[1], &_0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, getJsSources)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri_zv, _0, _1;
	zend_string *uri = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "jsLink");
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getTemplate", &_zephir_call_cache[0], &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_update_string(&_2, SL("uri"), &uri_zv, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&_2, SL("path"), SL("debug.js"));
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "toInterpolate", &_zephir_call_cache[1], &_0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, getVersion)
{
	zval _5;
	zval version, link, _0, _1, _2, _3, _4, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&version);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[6];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&version);
	object_init_ex(&version, phalcon_support_version_ce);
	if (zephir_has_constructor(&version)) {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &version, "__construct", &_zephir_call_cache[0]);
		zephir_check_call_status();
	}

	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_METHOD_CACHED(&_0, &version, "getPart", &_zephir_call_cache[1], &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_METHOD_CACHED(&_2, &version, "getPart", &_zephir_call_cache[2], &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&link);
	ZEPHIR_CONCAT_SVSVS(&link, "https://docs.phalcon.io/", &_0, ".", &_2, "/");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "version");
	ZEPHIR_CALL_METHOD_CACHED(&_3, this_ptr, "getTemplate", &_zephir_call_cache[3], &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 2, 0);
	zephir_array_update_string(&_5, SL("link"), &link, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&_6, &version, "get", &_zephir_call_cache[4]);
	zephir_check_call_status();
	zephir_array_update_string(&_5, SL("version"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "toInterpolate", &_zephir_call_cache[5], &_3, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, render)
{
	zval _14;
	zval _4, _8, _11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *report, report_sub, className, escapedMessage, html, _0, _1, _2, _3, _5, _6, _7, _9, _10, _12, _13, _15, _16, _30, _31, _32, _33, _17$$3, _18$$3, _19$$3, _20$$3, _21$$3, _22$$3, _23$$3, _24$$3, _25$$3, _26$$3, _27$$3, _28$$3, _29$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&report_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&escapedMessage);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_21$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_24$$3);
	ZVAL_UNDEF(&_25$$3);
	ZVAL_UNDEF(&_26$$3);
	ZVAL_UNDEF(&_27$$3);
	ZVAL_UNDEF(&_28$$3);
	ZVAL_UNDEF(&_29$$3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_14);
	ZEND_TLS zephir_method_cache _zephir_call_cache[35];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(report, phalcon_support_debug_report_exceptionreport_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &report);
	ZEPHIR_CALL_METHOD_CACHED(&_0, report, "getClassName", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&className, this_ptr, "escapeString", &_zephir_call_cache[1], &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_1, report, "getMessage", &_zephir_call_cache[2]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&escapedMessage, this_ptr, "escapeString", &_zephir_call_cache[3], &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "document");
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "getTemplate", &_zephir_call_cache[4], &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 3, 0);
	zephir_array_update_string(&_4, SL("className"), &className, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_4, SL("escapedMessage"), &escapedMessage, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&_6, report, "getUri", &_zephir_call_cache[5]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_5, this_ptr, "getCssSources", &_zephir_call_cache[6], &_6);
	zephir_check_call_status();
	zephir_array_update_string(&_4, SL("cssSources"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&html, this_ptr, "toInterpolate", &_zephir_call_cache[7], &_2, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "masthead");
	ZEPHIR_CALL_METHOD_CACHED(&_7, this_ptr, "getTemplate", &_zephir_call_cache[8], &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	zephir_create_array(&_8, 1, 0);
	ZEPHIR_CALL_METHOD_CACHED(&_9, this_ptr, "getVersion", &_zephir_call_cache[9]);
	zephir_check_call_status();
	zephir_array_update_string(&_8, SL("version"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&_5, this_ptr, "toInterpolate", &_zephir_call_cache[10], &_7, &_8);
	zephir_check_call_status();
	zephir_concat_self(&html, &_5);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "errorMain");
	ZEPHIR_CALL_METHOD_CACHED(&_10, this_ptr, "getTemplate", &_zephir_call_cache[11], &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	zephir_create_array(&_11, 6, 0);
	zephir_array_update_string(&_11, SL("className"), &className, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_11, SL("escapedMessage"), &escapedMessage, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&_13, report, "getFile", &_zephir_call_cache[12]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_12, this_ptr, "escapeString", &_zephir_call_cache[13], &_13);
	zephir_check_call_status();
	zephir_array_update_string(&_11, SL("file"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&_12, report, "getLine", &_zephir_call_cache[14]);
	zephir_check_call_status();
	zephir_cast_to_string(&_14, &_12);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&_11, SL("line"), &_14, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_3);
	ZEPHIR_GET_CONSTANT(&_3, "PHP_VERSION");
	zephir_array_update_string(&_11, SL("phpVersion"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&_16, report, "getPreviousExceptions", &_zephir_call_cache[15]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_15, this_ptr, "renderPreviousExceptions", &_zephir_call_cache[16], &_16);
	zephir_check_call_status();
	zephir_array_update_string(&_11, SL("previous"), &_15, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&_9, this_ptr, "toInterpolate", &_zephir_call_cache[17], &_10, &_11);
	zephir_check_call_status();
	zephir_concat_self(&html, &_9);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_15, report, "isShowBackTrace", &_zephir_call_cache[18]);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_15)) {
		ZEPHIR_CALL_METHOD_CACHED(&_17$$3, this_ptr, "renderTabs", &_zephir_call_cache[19], report);
		zephir_check_call_status();
		zephir_concat_self(&html, &_17$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_19$$3, report, "getBacktrace", &_zephir_call_cache[20]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_18$$3, this_ptr, "renderBacktrace", &_zephir_call_cache[21], &_19$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_18$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_21$$3, report, "getRequest", &_zephir_call_cache[22]);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_22$$3);
		ZVAL_STRING(&_22$$3, "request");
		ZEPHIR_CALL_METHOD_CACHED(&_20$$3, this_ptr, "renderSuperglobal", &_zephir_call_cache[23], &_22$$3, &_21$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_20$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_24$$3, report, "getServer", &_zephir_call_cache[24]);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_22$$3);
		ZVAL_STRING(&_22$$3, "server");
		ZEPHIR_CALL_METHOD_CACHED(&_23$$3, this_ptr, "renderSuperglobal", &_zephir_call_cache[25], &_22$$3, &_24$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_23$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_26$$3, report, "getIncludedFiles", &_zephir_call_cache[26]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_25$$3, this_ptr, "renderIncludedFiles", &_zephir_call_cache[27], &_26$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_25$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_27$$3, this_ptr, "renderMemory", &_zephir_call_cache[28], report);
		zephir_check_call_status();
		zephir_concat_self(&html, &_27$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_29$$3, report, "getVariables", &_zephir_call_cache[29]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_28$$3, this_ptr, "renderVariables", &_zephir_call_cache[30], &_29$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_28$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "wrapClose");
	ZEPHIR_CALL_METHOD_CACHED(&_30, this_ptr, "getTemplate", &_zephir_call_cache[31], &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_32, report, "getUri", &_zephir_call_cache[32]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_31, this_ptr, "getJsSources", &_zephir_call_cache[33], &_32);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "documentClose");
	ZEPHIR_CALL_METHOD_CACHED(&_33, this_ptr, "getTemplate", &_zephir_call_cache[34], &_3);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVVV(return_value, &html, &_30, &_31, &_33);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * Returns the embedded default template for the given name.
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, defaultTemplate)
{
	zend_bool _1;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, defaults, template;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_INIT_VAR(&defaults);
	zephir_create_array(&defaults, 26, 0);
	add_assoc_stringl_ex(&defaults, SL("cssLink"), SL("\n    <link href='%uri%%path%'\n          rel='stylesheet'\n          type='text/css' />"));
	add_assoc_stringl_ex(&defaults, SL("jsLink"), SL("\n    <script src='%uri%%path%'></script>"));
	add_assoc_stringl_ex(&defaults, SL("version"), SL("<a class='version-badge' href='%link%' target='_new'><b>v%version%</b></a>"));
	add_assoc_stringl_ex(&defaults, SL("document"), SL("<!DOCTYPE html>\n<html lang='en' data-theme='light'>\n<head>\n    <meta charset='utf-8'>\n    <meta name='viewport' content='width=device-width, initial-scale=1'>\n    <title>%className%:%escapedMessage%</title>%cssSources%\n</head>\n<body>\n<div class='wrap'>"));
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SSS(&_0, "\n    <div class='masthead'>\n        <div class='brand'><img class='logo'", " src='https://assets.phalcon.io/phalcon/images/svg/logo--tablet.svg'", " alt='Phalcon' /><span>Phalcon Debug</span></div>\n        <div class='actions-top'>\n            <button class='btn' data-action='copy-trace'>Copy trace</button>\n            <button class='btn' data-action='toggle-theme' title='Toggle theme'>Theme</button>\n            %version%\n        </div>\n    </div>");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&defaults, SL("masthead"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&defaults, SL("errorMain"), SL("\n    <div class='error-card'>\n        <span class='error-type'>%className%</span>\n        <h1 class='error-message'>%escapedMessage%</h1>\n        <div class='meta'>\n            <span class='item'><code>%file%</code> : <code>%line%</code></span>\n            <span class='sep'>|</span><span class='item'>PHP <code>%phpVersion%</code></span>\n        </div>%previous%\n    </div>"));
	add_assoc_stringl_ex(&defaults, SL("previousException"), SL("\n        <div class='meta'>\n            <span class='item'>Previous: <code>%className%</code> %escapedMessage%</span>\n            <span class='sep'>|</span><span class='item'><code>%file%</code> : <code>%line%</code></span>\n        </div>"));
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_CONCAT_SS(&_0, "\n    <div class='tabs' role='tablist'>\n        <button class='tab is-active' data-tab='backtrace'>Backtrace ", "<span class='count'>%backtraceCount%</span></button>\n        <button class='tab' data-tab='request'>Request <span class='count'>%requestCount%</span></button>\n        <button class='tab' data-tab='server'>Server <span class='count'>%serverCount%</span></button>\n        <button class='tab' data-tab='files'>Included Files <span class='count'>%filesCount%</span></button>\n        <button class='tab' data-tab='memory'>Memory</button>%variablesTab%\n    </div>");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&defaults, SL("tabs"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&defaults, SL("variablesTab"), SL("\n        <button class='tab' data-tab='variables'>Variables <span class='count'>%variablesCount%</span></button>"));
	add_assoc_stringl_ex(&defaults, SL("backtracePanel"), SL("\n    <div class='panel is-active' id='backtrace'>\n        <div class='bt-tools'>\n            <button class='btn' data-action='expand-all'>Expand all</button>\n            <button class='btn' data-action='collapse-all'>Collapse all</button>\n        </div>"));
	add_assoc_stringl_ex(&defaults, SL("panelOpen"), SL("\n    <div class='panel' id='%id%'>"));
	add_assoc_stringl_ex(&defaults, SL("panelClose"), SL("\n    </div>"));
	add_assoc_stringl_ex(&defaults, SL("wrapClose"), SL("\n</div>"));
	add_assoc_stringl_ex(&defaults, SL("documentClose"), SL("\n</body>\n</html>"));
	add_assoc_stringl_ex(&defaults, SL("frameOpen"), SL("\n        <details class='frame %appClass%'%open%>\n            <summary><div class='frame-head'>\n                <span class='frame-num'>#%num%</span>\n                <span class='frame-call'>%signature%</span>%appTag%\n                <span class='chev'>&#9656;</span>\n            </div></summary>"));
	add_assoc_stringl_ex(&defaults, SL("appTag"), SL("<span class='tag-app'>app</span>"));
	add_assoc_stringl_ex(&defaults, SL("frameFile"), SL("\n            <div class='frame-file' data-file='%file%' data-line='%line%'>\n                <span class='path'><b>%file%</b> : %line%</span>\n            </div>"));
	add_assoc_stringl_ex(&defaults, SL("frameClose"), SL("\n        </details>"));
	add_assoc_stringl_ex(&defaults, SL("codeOpen"), SL("\n            <div class='code'><table>"));
	add_assoc_stringl_ex(&defaults, SL("codeRow"), SL("<tr%hlClass%><td class='ln'>%num%</td><td class='src'>%src%</td></tr>"));
	add_assoc_stringl_ex(&defaults, SL("codeClose"), SL("</table></div>"));
	add_assoc_stringl_ex(&defaults, SL("link"), SL("<a href='%url%' target='_new'>%name%</a>"));
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_CONCAT_SS(&_0, "<table class='grid'><thead><tr><th>%headerOne%</th><th>%headerTwo%</th></tr>", "</thead><tbody>");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&defaults, SL("tableOpen"), &_0, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&defaults, SL("gridRow"), SL("<tr><td class='k'>%key%</td><td class='v'>%value%</td></tr>"));
	add_assoc_stringl_ex(&defaults, SL("tableClose"), SL("</tbody></table>"));
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_CONCAT_SSS(&_0, "\n        <div class='stats'>\n            <div class='stat'><div class='label'>Memory usage (real)</div>", "<div class='value'>%memory% <small>MB</small></div></div>\n            <div class='stat'><div class='label'>Peak usage</div>", "<div class='value'>%peak% <small>MB</small></div></div>\n        </div>");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&defaults, SL("memory"), &_0, PH_COPY | PH_SEPARATE);
	zephir_memory_observe(&template);
	_1 = zephir_array_isset_fetch(&template, &defaults, &name_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		RETURN_CCTOR(&template);
	}
	RETURN_MM_STRING("");
}

/**
 * Escapes a string with htmlentities
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, escapeString)
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
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\n");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\\n");
	zephir_fast_str_replace(&_0, &_1, &_2, &value_zv);
	ZVAL_LONG(&_3, (3 | 8));
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "utf-8");
	ZEPHIR_RETURN_CALL_FUNCTION("htmlentities", NULL, 269, &_0, &_3, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Produces a recursive representation of an array
 *
 * @phpstan-param support_debug_args $arguments
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, getArrayDump)
{
	zval _1$$4, _10$$5, _19$$12;
	zend_string *_4;
	zend_ulong _3;
	zend_bool _0, _13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long number, ZEPHIR_LAST_CALL_STATUS;
	zval *arguments_param = NULL, *number_param = NULL, numberArguments, dump, varDump, key, value, *_2, _12, _5$$8, _6$$8, _7$$9, _8$$9, _9$$5, _11$$5, _14$$15, _15$$15, _16$$16, _17$$16, _18$$12, _20$$12;
	zval arguments;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&numberArguments);
	ZVAL_UNDEF(&dump);
	ZVAL_UNDEF(&varDump);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$15);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_19$$12);
	ZEND_TLS zephir_method_cache _zephir_call_cache[13];
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(arguments, arguments_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(number)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &arguments_param, &number_param);
	zephir_get_arrval(&arguments, arguments_param);
	if (!number_param) {
		number = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&numberArguments);
	ZVAL_LONG(&numberArguments, zephir_fast_count_int(&arguments));
	_0 = number >= 3;
	if (!(_0)) {
		_0 = ZEPHIR_IS_LONG(&numberArguments, 0);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	if (ZEPHIR_GE_LONG(&numberArguments, 10)) {
		zephir_cast_to_string(&_1$$4, &numberArguments);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CTOR(&_1$$4);
	}
	ZEPHIR_INIT_VAR(&dump);
	array_init(&dump);
	zephir_is_iterable(&arguments, 0, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 222);
	if (Z_TYPE_P(&arguments) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&arguments), _3, _4, _2)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2);
			if (ZEPHIR_IS_STRING_IDENTICAL(&value, "")) {
				ZEPHIR_INIT_NVAR(&varDump);
				ZVAL_STRING(&varDump, "(empty string)");
			} else if (zephir_is_scalar(&value)) {
				ZEPHIR_CALL_METHOD_CACHED(&varDump, this_ptr, "escapeString", &_zephir_call_cache[0], &value);
				zephir_check_call_status();
			} else if (Z_TYPE_P(&value) == IS_ARRAY) {
				ZVAL_LONG(&_6$$8, (number + 1));
				ZEPHIR_CALL_METHOD_CACHED(&_5$$8, this_ptr, "getArrayDump", &_zephir_call_cache[1], &value, &_6$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&varDump);
				ZEPHIR_CONCAT_SVS(&varDump, "Array(", &_5$$8, ")");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (Z_TYPE_P(&value) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_8$$9);
				zephir_get_class(&_8$$9, &value, 0);
				ZEPHIR_CALL_METHOD_CACHED(&_7$$9, this_ptr, "escapeString", &_zephir_call_cache[2], &_8$$9);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&varDump);
				ZEPHIR_CONCAT_SVS(&varDump, "Object(", &_7$$9, ")");
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (Z_TYPE_P(&value) == IS_NULL) {
				ZEPHIR_INIT_NVAR(&varDump);
				ZVAL_STRING(&varDump, "null");
			} else {
				ZEPHIR_CPY_WRT(&varDump, &value);
			}
			zephir_cast_to_string(&_10$$5, &key);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_9$$5, this_ptr, "escapeString", &_zephir_call_cache[3], &_10$$5);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_11$$5);
			ZEPHIR_CONCAT_SVSV(&_11$$5, "[", &_9$$5, "] =&gt; ", &varDump);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&dump, &_11$$5, PH_SEPARATE, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 219);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &arguments, "rewind", &_zephir_call_cache[4]);
		zephir_check_call_status();
		_13 = 1;
		while (1) {
			if (_13) {
				_13 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &arguments, "next", &_zephir_call_cache[5]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_12, &arguments, "valid", &_zephir_call_cache[6]);
			zephir_check_call_status();
			if (!zend_is_true(&_12)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, &arguments, "key", &_zephir_call_cache[7]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &arguments, "current", &_zephir_call_cache[8]);
			zephir_check_call_status();
				if (ZEPHIR_IS_STRING_IDENTICAL(&value, "")) {
					ZEPHIR_INIT_NVAR(&varDump);
					ZVAL_STRING(&varDump, "(empty string)");
				} else if (zephir_is_scalar(&value)) {
					ZEPHIR_CALL_METHOD_CACHED(&varDump, this_ptr, "escapeString", &_zephir_call_cache[9], &value);
					zephir_check_call_status();
				} else if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZVAL_LONG(&_15$$15, (number + 1));
					ZEPHIR_CALL_METHOD_CACHED(&_14$$15, this_ptr, "getArrayDump", &_zephir_call_cache[10], &value, &_15$$15);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&varDump);
					ZEPHIR_CONCAT_SVS(&varDump, "Array(", &_14$$15, ")");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (Z_TYPE_P(&value) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_17$$16);
					zephir_get_class(&_17$$16, &value, 0);
					ZEPHIR_CALL_METHOD_CACHED(&_16$$16, this_ptr, "escapeString", &_zephir_call_cache[11], &_17$$16);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&varDump);
					ZEPHIR_CONCAT_SVS(&varDump, "Object(", &_16$$16, ")");
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (Z_TYPE_P(&value) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&varDump);
					ZVAL_STRING(&varDump, "null");
				} else {
					ZEPHIR_CPY_WRT(&varDump, &value);
				}
				zephir_cast_to_string(&_19$$12, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_18$$12, this_ptr, "escapeString", &_zephir_call_cache[12], &_19$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_20$$12);
				ZEPHIR_CONCAT_SVSV(&_20$$12, "[", &_18$$12, "] =&gt; ", &varDump);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&dump, &_20$$12, PH_SEPARATE, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 219);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_fast_join_str(return_value, SL(", "), &dump);
	RETURN_MM();
}

/**
 * Produces a string representation of a variable
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, getVarDump)
{
	zval _0$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, _1$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&_1$$8);
	ZVAL_UNDEF(&_0$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
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
		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "escapeString", &_zephir_call_cache[0], variable);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (zephir_is_scalar(variable)) {
		zephir_cast_to_string(&_0$$6, variable);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CTOR(&_0$$6);
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "dumpObject", &_zephir_call_cache[1], variable);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD_CACHED(&_1$$8, this_ptr, "getArrayDump", &_zephir_call_cache[2], variable);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "Array(", &_1$$8, ")");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		RETURN_MM_STRING("null");
	}
	zephir_gettype(return_value, variable);
	RETURN_MM();
}

/**
 * Returns true when the dump() method of the object is public, is not
 * static, and has no required parameters
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, canCallDump)
{
	zend_bool _2, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, method, _0, _1, _3, _5;

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(variable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &variable);
	ZEPHIR_INIT_VAR(&method);
	object_init_ex(&method, zephir_get_internal_ce(SL("reflectionmethod")));
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "dump");
	ZEPHIR_CALL_METHOD_CACHED(NULL, &method, "__construct", &_zephir_call_cache[0], variable, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_1, &method, "isPublic", &_zephir_call_cache[1]);
	zephir_check_call_status();
	_2 = ZEPHIR_IS_TRUE_IDENTICAL(&_1);
	if (_2) {
		ZEPHIR_CALL_METHOD_CACHED(&_3, &method, "isStatic", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_2 = !ZEPHIR_IS_TRUE_IDENTICAL(&_3);
	}
	_4 = _2;
	if (_4) {
		ZEPHIR_CALL_METHOD_CACHED(&_5, &method, "getNumberOfRequiredParameters", &_zephir_call_cache[3]);
		zephir_check_call_status();
		_4 = ZEPHIR_IS_LONG_IDENTICAL(&_5, 0);
	}
	RETURN_MM_BOOL(_4);
}

/**
 * Uses the result of dump() only if it is an array
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, dumpObject)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, className, dumpedObject, _0, _2, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&dumpedObject);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT(variable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &variable);
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, variable, 0);
	ZEPHIR_CALL_METHOD_CACHED(&className, this_ptr, "escapeString", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	_1 = (zephir_method_exists_ex(variable, ZEND_STRL("dump")) == SUCCESS);
	if (_1) {
		ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "canCallDump", &_zephir_call_cache[1], variable);
		zephir_check_call_status();
		_1 = zephir_is_true(&_2);
	}
	if (_1) {
		ZEPHIR_CALL_METHOD_CACHED(&dumpedObject, variable, "dump", &_zephir_call_cache[2]);
		zephir_check_call_status();
		if (Z_TYPE_P(&dumpedObject) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD_CACHED(&_3$$4, this_ptr, "getArrayDump", &_zephir_call_cache[3], &dumpedObject);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVSVS(return_value, "Object(", &className, ": ", &_3$$4, ")");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			RETURN_MM();
		}
	}
	ZEPHIR_CONCAT_SVS(return_value, "Object(", &className, ")");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, formatBytes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *bytes_param = NULL, amount, _0;
	zend_long bytes, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&amount);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(bytes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &bytes_param);
	ZEPHIR_INIT_VAR(&amount);
	zephir_div_long_long(&amount, bytes, 1048576);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_LONG(&_0, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("number_format", NULL, 271, &amount, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Frames whose file lives outside a vendor directory are application code.
 * The check also finds the Windows form, `\vendor\`.
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, isApp)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval file_zv, _0, _1, _3, _4;
	zend_string *file = NULL;

	ZVAL_UNDEF(&file_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(file)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!file) {
		ZEPHIR_INIT_VAR(&file_zv);
	} else {
		zephir_memory_observe(&file_zv);
	ZVAL_STR_COPY(&file_zv, file);
	}
	if (Z_TYPE_P(&file_zv) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/vendor/");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &file_zv, &_0, 0 );
	_2 = ZEPHIR_IS_FALSE_IDENTICAL(&_1);
	if (_2) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "\\vendor\\");
		ZEPHIR_INIT_VAR(&_4);
		zephir_fast_strpos(&_4, &file_zv, &_3, 0 );
		_2 = ZEPHIR_IS_FALSE_IDENTICAL(&_4);
	}
	RETURN_MM_BOOL(_2);
}

/**
 * @param BacktraceItem[] $backtrace
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderBacktrace)
{
	zend_bool _6;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *backtrace_param = NULL, html, index, item, _0, *_1, _5, _8, _4$$3, _7$$4;
	zval backtrace;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&backtrace);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(backtrace, backtrace_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &backtrace_param);
	zephir_get_arrval(&backtrace, backtrace_param);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "backtracePanel");
	ZEPHIR_CALL_METHOD_CACHED(&html, this_ptr, "getTemplate", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	zephir_is_iterable(&backtrace, 0, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 332);
	if (Z_TYPE_P(&backtrace) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&backtrace), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&index);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&index, _3);
			} else {
				ZVAL_LONG(&index, _2);
			}
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _1);
			ZEPHIR_CALL_METHOD_CACHED(&_4$$3, this_ptr, "renderTraceItem", &_zephir_call_cache[1], &index, &item);
			zephir_check_call_status();
			zephir_concat_self(&html, &_4$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &backtrace, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &backtrace, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_5, &backtrace, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&index, &backtrace, "key", &_zephir_call_cache[5]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&item, &backtrace, "current", &_zephir_call_cache[6]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&_7$$4, this_ptr, "renderTraceItem", &_zephir_call_cache[7], &index, &item);
				zephir_check_call_status();
				zephir_concat_self(&html, &_7$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "panelClose");
	ZEPHIR_CALL_METHOD_CACHED(&_8, this_ptr, "getTemplate", &_zephir_call_cache[8], &_0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &html, &_8);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * @phpstan-param support_debug_fragment $fragment
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderFragment)
{
	zval _13$$3;
	zend_bool _1, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fragment_param = NULL, firstLine, lastLine, line, lines, html, counter, currentLine, _0, _20, _2$$3, _3$$3, _4$$3, _6$$3, _7$$3, _8$$3, _9$$3, _10$$3, _12$$3, _14$$3, _15$$3, _16$$3, _17$$3, _18$$3;
	zval fragment, _11$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fragment);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&firstLine);
	ZVAL_UNDEF(&lastLine);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&counter);
	ZVAL_UNDEF(&currentLine);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_13$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[4];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(fragment, fragment_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &fragment_param);
	zephir_get_arrval(&fragment, fragment_param);
	zephir_memory_observe(&firstLine);
	zephir_array_fetch_string(&firstLine, &fragment, SL("firstLine"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 342);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&lastLine);
	zephir_array_fetch_string(&lastLine, &fragment, SL("lastLine"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 343);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&line);
	zephir_array_fetch_string(&line, &fragment, SL("line"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 344);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&lines);
	zephir_array_fetch_string(&lines, &fragment, SL("lines"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 345);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "codeOpen");
	ZEPHIR_CALL_METHOD_CACHED(&html, this_ptr, "getTemplate", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&counter, &firstLine);
	while (1) {
		_1 = ZEPHIR_LE(&counter, &lastLine);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (!(_1)) {
			break;
		}
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_LONG(&_3$$3, 1);
		ZEPHIR_INIT_NVAR(&_4$$3);
		zephir_sub_function(&_4$$3, &counter, &_3$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_5$$3 = zephir_array_isset_value(&lines, &_4$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_5$$3) {
			ZEPHIR_OBS_NVAR(&_2$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_LONG(&_3$$3, 1);
			ZEPHIR_INIT_NVAR(&_6$$3);
			zephir_sub_function(&_6$$3, &counter, &_3$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_fetch(&_2$$3, &lines, &_6$$3, PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 351);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "");
		}
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "\r\n");
		ZEPHIR_INIT_NVAR(&currentLine);
		zephir_fast_trim(&currentLine, &_2$$3, &_7$$3, ZEPHIR_TRIM_RIGHT);
		ZEPHIR_INIT_NVAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "codeRow");
		ZEPHIR_CALL_METHOD_CACHED(&_9$$3, this_ptr, "getTemplate", &_zephir_call_cache[1], &_10$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_11$$3);
		zephir_create_array(&_11$$3, 3, 0);
		ZEPHIR_INIT_NVAR(&_12$$3);
		if (ZEPHIR_IS_IDENTICAL(&counter, &line)) {
			ZEPHIR_INIT_NVAR(&_12$$3);
			ZVAL_STRING(&_12$$3, " class='hl'");
		} else {
			ZEPHIR_INIT_NVAR(&_12$$3);
			ZVAL_STRING(&_12$$3, "");
		}
		zephir_array_update_string(&_11$$3, SL("hlClass"), &_12$$3, PH_COPY | PH_SEPARATE);
		zephir_cast_to_string(&_13$$3, &counter);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_11$$3, SL("num"), &_13$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_10$$3);
		ZEPHIR_INIT_NVAR(&_14$$3);
		ZVAL_STRING(&_14$$3, "\t");
		ZEPHIR_INIT_NVAR(&_15$$3);
		ZVAL_STRING(&_15$$3, "  ");
		zephir_fast_str_replace(&_10$$3, &_14$$3, &_15$$3, &currentLine);
		ZVAL_LONG(&_16$$3, (3 | 8));
		ZEPHIR_INIT_NVAR(&_17$$3);
		ZVAL_STRING(&_17$$3, "UTF-8");
		ZEPHIR_CALL_FUNCTION(&_18$$3, "htmlentities", &_19, 269, &_10$$3, &_16$$3, &_17$$3);
		zephir_check_call_status();
		zephir_array_update_string(&_11$$3, SL("src"), &_18$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(&_8$$3, this_ptr, "toInterpolate", &_zephir_call_cache[2], &_9$$3, &_11$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_8$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		SEPARATE_ZVAL(&counter);
		zephir_increment(&counter);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "codeClose");
	ZEPHIR_CALL_METHOD_CACHED(&_20, this_ptr, "getTemplate", &_zephir_call_cache[3], &_0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &html, &_20);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * @phpstan-param support_debug_included_files $files
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderIncludedFiles)
{
	zval _14$$3, _22$$4;
	zend_bool _17;
	zend_string *_9;
	zend_ulong _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *files_param = NULL, html, key, value, _0, _1, _2, _4, _5, *_7, _16, _24, _25, _10$$3, _11$$3, _12$$3, _15$$3, _18$$4, _19$$4, _20$$4, _23$$4;
	zval files, _3, _6, _13$$3, _21$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_23$$4);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_22$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[17];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(files, files_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &files_param);
	zephir_get_arrval(&files, files_param);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "panelOpen");
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "getTemplate", &_zephir_call_cache[0], &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0);
	add_assoc_stringl_ex(&_3, SL("id"), SL("files"));
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "toInterpolate", &_zephir_call_cache[1], &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "tableOpen");
	ZEPHIR_CALL_METHOD_CACHED(&_5, this_ptr, "getTemplate", &_zephir_call_cache[2], &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0);
	add_assoc_stringl_ex(&_6, SL("headerOne"), SL("#"));
	add_assoc_stringl_ex(&_6, SL("headerTwo"), SL("Path"));
	ZEPHIR_CALL_METHOD_CACHED(&_4, this_ptr, "toInterpolate", &_zephir_call_cache[3], &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&html);
	ZEPHIR_CONCAT_VV(&html, &_0, &_4);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_is_iterable(&files, 0, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 395);
	if (Z_TYPE_P(&files) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&files), _8, _9, _7)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&key, _9);
			} else {
				ZVAL_LONG(&key, _8);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _7);
			ZEPHIR_INIT_NVAR(&_12$$3);
			ZVAL_STRING(&_12$$3, "gridRow");
			ZEPHIR_CALL_METHOD_CACHED(&_11$$3, this_ptr, "getTemplate", &_zephir_call_cache[4], &_12$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_13$$3);
			zephir_create_array(&_13$$3, 2, 0);
			zephir_cast_to_string(&_14$$3, &key);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&_13$$3, SL("key"), &_14$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD_CACHED(&_15$$3, this_ptr, "escapeString", &_zephir_call_cache[5], &value);
			zephir_check_call_status();
			zephir_array_update_string(&_13$$3, SL("value"), &_15$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD_CACHED(&_10$$3, this_ptr, "toInterpolate", &_zephir_call_cache[6], &_11$$3, &_13$$3);
			zephir_check_call_status();
			zephir_concat_self(&html, &_10$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &files, "rewind", &_zephir_call_cache[7]);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &files, "next", &_zephir_call_cache[8]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_16, &files, "valid", &_zephir_call_cache[9]);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, &files, "key", &_zephir_call_cache[10]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &files, "current", &_zephir_call_cache[11]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_20$$4);
				ZVAL_STRING(&_20$$4, "gridRow");
				ZEPHIR_CALL_METHOD_CACHED(&_19$$4, this_ptr, "getTemplate", &_zephir_call_cache[12], &_20$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_21$$4);
				zephir_create_array(&_21$$4, 2, 0);
				zephir_cast_to_string(&_22$$4, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&_21$$4, SL("key"), &_22$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_23$$4, this_ptr, "escapeString", &_zephir_call_cache[13], &value);
				zephir_check_call_status();
				zephir_array_update_string(&_21$$4, SL("value"), &_23$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_18$$4, this_ptr, "toInterpolate", &_zephir_call_cache[14], &_19$$4, &_21$$4);
				zephir_check_call_status();
				zephir_concat_self(&html, &_18$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "tableClose");
	ZEPHIR_CALL_METHOD_CACHED(&_24, this_ptr, "getTemplate", &_zephir_call_cache[15], &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "panelClose");
	ZEPHIR_CALL_METHOD_CACHED(&_25, this_ptr, "getTemplate", &_zephir_call_cache[16], &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVV(return_value, &html, &_24, &_25);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderMemory)
{
	zval _3, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *report, report_sub, _0, _1, _2, _4, _5, _7, _8, _9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&report_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[9];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(report, phalcon_support_debug_report_exceptionreport_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &report);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "panelOpen");
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "getTemplate", &_zephir_call_cache[0], &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0);
	add_assoc_stringl_ex(&_3, SL("id"), SL("memory"));
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "toInterpolate", &_zephir_call_cache[1], &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "memory");
	ZEPHIR_CALL_METHOD_CACHED(&_5, this_ptr, "getTemplate", &_zephir_call_cache[2], &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0);
	ZEPHIR_CALL_METHOD_CACHED(&_8, report, "getMemoryUsage", &_zephir_call_cache[3]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_7, this_ptr, "formatBytes", &_zephir_call_cache[4], &_8);
	zephir_check_call_status();
	zephir_array_update_string(&_6, SL("memory"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&_9, report, "getPeakMemoryUsage", &_zephir_call_cache[5]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_7, this_ptr, "formatBytes", &_zephir_call_cache[6], &_9);
	zephir_check_call_status();
	zephir_array_update_string(&_6, SL("peak"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&_4, this_ptr, "toInterpolate", &_zephir_call_cache[7], &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "panelClose");
	ZEPHIR_CALL_METHOD_CACHED(&_7, this_ptr, "getTemplate", &_zephir_call_cache[8], &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVV(return_value, &_0, &_4, &_7);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * @phpstan-param list<support_debug_previous> $previousExceptions
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderPreviousExceptions)
{
	zval _10$$3, _22$$4;
	zend_bool _12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *previousExceptions_param = NULL, html, previous, *_0, _11, _1$$3, _2$$3, _3$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _13$$4, _14$$4, _15$$4, _17$$4, _18$$4, _19$$4, _20$$4, _21$$4;
	zval previousExceptions, _4$$3, _16$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&previousExceptions);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&previous);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_22$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[14];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(previousExceptions, previousExceptions_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &previousExceptions_param);
	zephir_get_arrval(&previousExceptions, previousExceptions_param);
	ZEPHIR_INIT_VAR(&html);
	ZVAL_STRING(&html, "");
	zephir_is_iterable(&previousExceptions, 0, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 431);
	if (Z_TYPE_P(&previousExceptions) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&previousExceptions), _0)
		{
			ZEPHIR_INIT_NVAR(&previous);
			ZVAL_COPY(&previous, _0);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "previousException");
			ZEPHIR_CALL_METHOD_CACHED(&_2$$3, this_ptr, "getTemplate", &_zephir_call_cache[0], &_3$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_create_array(&_4$$3, 4, 0);
			ZEPHIR_OBS_NVAR(&_6$$3);
			zephir_array_fetch_string(&_6$$3, &previous, SL("className"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 423);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_5$$3, this_ptr, "escapeString", &_zephir_call_cache[1], &_6$$3);
			zephir_check_call_status();
			zephir_array_update_string(&_4$$3, SL("className"), &_5$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_7$$3);
			zephir_array_fetch_string(&_7$$3, &previous, SL("message"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 424);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_5$$3, this_ptr, "escapeString", &_zephir_call_cache[2], &_7$$3);
			zephir_check_call_status();
			zephir_array_update_string(&_4$$3, SL("escapedMessage"), &_5$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_8$$3);
			zephir_array_fetch_string(&_8$$3, &previous, SL("file"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 425);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_5$$3, this_ptr, "escapeString", &_zephir_call_cache[3], &_8$$3);
			zephir_check_call_status();
			zephir_array_update_string(&_4$$3, SL("file"), &_5$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_9$$3);
			zephir_array_fetch_string(&_9$$3, &previous, SL("line"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 427);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_cast_to_string(&_10$$3, &_9$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_string(&_4$$3, SL("line"), &_10$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD_CACHED(&_1$$3, this_ptr, "toInterpolate", &_zephir_call_cache[4], &_2$$3, &_4$$3);
			zephir_check_call_status();
			zephir_concat_self(&html, &_1$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &previousExceptions, "rewind", &_zephir_call_cache[5]);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &previousExceptions, "next", &_zephir_call_cache[6]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_11, &previousExceptions, "valid", &_zephir_call_cache[7]);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&previous, &previousExceptions, "current", &_zephir_call_cache[8]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_15$$4);
				ZVAL_STRING(&_15$$4, "previousException");
				ZEPHIR_CALL_METHOD_CACHED(&_14$$4, this_ptr, "getTemplate", &_zephir_call_cache[9], &_15$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$4);
				zephir_create_array(&_16$$4, 4, 0);
				ZEPHIR_OBS_NVAR(&_18$$4);
				zephir_array_fetch_string(&_18$$4, &previous, SL("className"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 423);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_17$$4, this_ptr, "escapeString", &_zephir_call_cache[10], &_18$$4);
				zephir_check_call_status();
				zephir_array_update_string(&_16$$4, SL("className"), &_17$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_19$$4);
				zephir_array_fetch_string(&_19$$4, &previous, SL("message"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 424);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_17$$4, this_ptr, "escapeString", &_zephir_call_cache[11], &_19$$4);
				zephir_check_call_status();
				zephir_array_update_string(&_16$$4, SL("escapedMessage"), &_17$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_20$$4);
				zephir_array_fetch_string(&_20$$4, &previous, SL("file"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 425);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_17$$4, this_ptr, "escapeString", &_zephir_call_cache[12], &_20$$4);
				zephir_check_call_status();
				zephir_array_update_string(&_16$$4, SL("file"), &_17$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_21$$4);
				zephir_array_fetch_string(&_21$$4, &previous, SL("line"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 427);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_22$$4, &_21$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&_16$$4, SL("line"), &_22$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_13$$4, this_ptr, "toInterpolate", &_zephir_call_cache[13], &_14$$4, &_16$$4);
				zephir_check_call_status();
				zephir_concat_self(&html, &_13$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&previous);
	RETURN_CCTOR(&html);
}

PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderSignature)
{
	zend_bool _21$$8;
	zval _4$$4, _12$$6;
	zval _7$$3, _8$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, html, name, link, classHtml, fnName, fnLink, functionHtml, arguments, argument, _0, _9, _13, _14, _1$$3, _5$$3, _6$$3, _2$$4, _3$$4, _10$$6, _11$$6, _15$$8, *_16$$8, _17$$8, *_18$$8, _20$$8, _23$$8, _24$$8, _19$$9, _22$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&classHtml);
	ZVAL_UNDEF(&fnName);
	ZVAL_UNDEF(&fnLink);
	ZVAL_UNDEF(&functionHtml);
	ZVAL_UNDEF(&arguments);
	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_12$$6);
	ZEND_TLS zephir_method_cache _zephir_call_cache[20];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_support_debug_report_backtraceitem_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &item);
	ZEPHIR_INIT_VAR(&html);
	ZVAL_STRING(&html, "");
	ZEPHIR_CALL_METHOD_CACHED(&_0, item, "getClassName", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) != IS_NULL) {
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, item, "getClassName", &_zephir_call_cache[1]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&name, this_ptr, "escapeString", &_zephir_call_cache[2], &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&link, item, "getClassLink", &_zephir_call_cache[3]);
		zephir_check_call_status();
		if (Z_TYPE_P(&link) != IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "link");
			ZEPHIR_CALL_METHOD_CACHED(&_2$$4, this_ptr, "getTemplate", &_zephir_call_cache[4], &_3$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_4$$4);
			zephir_create_array(&_4$$4, 2, 0);
			zephir_array_update_string(&_4$$4, SL("url"), &link, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4$$4, SL("name"), &name, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD_CACHED(&classHtml, this_ptr, "toInterpolate", &_zephir_call_cache[5], &_2$$4, &_4$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&classHtml, &name);
		}
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_SVS(&_5$$3, "<span class='cls'>", &classHtml, "</span>");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&html, &_5$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&_6$$3, item, "getType", &_zephir_call_cache[6]);
		zephir_check_call_status();
		zephir_cast_to_string(&_7$$3, &_6$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_8$$3);
		ZEPHIR_CONCAT_SVS(&_8$$3, "<span class='op'>", &_7$$3, "</span>");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&html, &_8$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_METHOD_CACHED(&_9, item, "getFunctionName", &_zephir_call_cache[7]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&fnName, this_ptr, "escapeString", &_zephir_call_cache[8], &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&fnLink, item, "getFunctionLink", &_zephir_call_cache[9]);
	zephir_check_call_status();
	if (Z_TYPE_P(&fnLink) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_11$$6);
		ZVAL_STRING(&_11$$6, "link");
		ZEPHIR_CALL_METHOD_CACHED(&_10$$6, this_ptr, "getTemplate", &_zephir_call_cache[10], &_11$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_12$$6);
		zephir_create_array(&_12$$6, 2, 0);
		zephir_array_update_string(&_12$$6, SL("url"), &fnLink, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_12$$6, SL("name"), &fnName, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(&functionHtml, this_ptr, "toInterpolate", &_zephir_call_cache[11], &_10$$6, &_12$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&functionHtml, &fnName);
	}
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_CONCAT_SVS(&_13, "<span class='fn'>", &functionHtml, "</span>");
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_concat_self(&html, &_13);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_14, item, "hasArgs", &_zephir_call_cache[12]);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_14)) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
		ZEPHIR_CALL_METHOD_CACHED(&_15$$8, item, "getArgs", &_zephir_call_cache[13]);
		zephir_check_call_status();
		if (Z_TYPE_P(&_15$$8) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_17$$8);
			zephir_string_to_char_array(&_17$$8, &_15$$8);
			_16$$8 = &_17$$8;
		} else {
			_16$$8 = &_15$$8;
		}
		zephir_is_iterable(_16$$8, 0, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 478);
		if (Z_TYPE_P(_16$$8) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_16$$8), _18$$8)
			{
				ZEPHIR_INIT_NVAR(&argument);
				ZVAL_COPY(&argument, _18$$8);
				ZEPHIR_CALL_METHOD_CACHED(&_19$$9, this_ptr, "getVarDump", &_zephir_call_cache[14], &argument);
				zephir_check_call_status();
				zephir_array_append(&arguments, &_19$$9, PH_SEPARATE, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 475);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _16$$8, "rewind", &_zephir_call_cache[15]);
			zephir_check_call_status();
			_21$$8 = 1;
			while (1) {
				if (_21$$8) {
					_21$$8 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _16$$8, "next", &_zephir_call_cache[16]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_20$$8, _16$$8, "valid", &_zephir_call_cache[17]);
				zephir_check_call_status();
				if (!zend_is_true(&_20$$8)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&argument, _16$$8, "current", &_zephir_call_cache[18]);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD_CACHED(&_22$$10, this_ptr, "getVarDump", &_zephir_call_cache[19], &argument);
					zephir_check_call_status();
					zephir_array_append(&arguments, &_22$$10, PH_SEPARATE, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 475);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&argument);
		ZEPHIR_INIT_VAR(&_23$$8);
		zephir_fast_join_str(&_23$$8, SL(", "), &arguments);
		ZEPHIR_INIT_VAR(&_24$$8);
		ZEPHIR_CONCAT_SVS(&_24$$8, "<span class='op'>(</span>", &_23$$8, "<span class='op'>)</span>");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_concat_self(&html, &_24$$8);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&html);
}

/**
 * @phpstan-param support_debug_superglobal $source
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderSuperglobal)
{
	zval _15$$3, _23$$4;
	zend_bool _17;
	zend_ulong _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval source, _3, _6, _13$$3, _21$$4;
	zval div_zv, *source_param = NULL, html, key, value, _0, _1, _2, _4, _5, *_7, _16, _24, _25, _10$$3, _11$$3, _12$$3, _14$$3, _18$$4, _19$$4, _20$$4, _22$$4;
	zend_string *div = NULL, *_9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&div_zv);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_23$$4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[19];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(div)
		ZEPHIR_Z_PARAM_ARRAY(source, source_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	source_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&div_zv);
	ZVAL_STR_COPY(&div_zv, div);
	zephir_get_arrval(&source, source_param);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "panelOpen");
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "getTemplate", &_zephir_call_cache[0], &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0);
	zephir_array_update_string(&_3, SL("id"), &div_zv, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "toInterpolate", &_zephir_call_cache[1], &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "tableOpen");
	ZEPHIR_CALL_METHOD_CACHED(&_5, this_ptr, "getTemplate", &_zephir_call_cache[2], &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0);
	add_assoc_stringl_ex(&_6, SL("headerOne"), SL("Key"));
	add_assoc_stringl_ex(&_6, SL("headerTwo"), SL("Value"));
	ZEPHIR_CALL_METHOD_CACHED(&_4, this_ptr, "toInterpolate", &_zephir_call_cache[3], &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&html);
	ZEPHIR_CONCAT_VV(&html, &_0, &_4);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_is_iterable(&source, 0, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 507);
	if (Z_TYPE_P(&source) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&source), _8, _9, _7)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&key, _9);
			} else {
				ZVAL_LONG(&key, _8);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _7);
			ZEPHIR_INIT_NVAR(&_12$$3);
			ZVAL_STRING(&_12$$3, "gridRow");
			ZEPHIR_CALL_METHOD_CACHED(&_11$$3, this_ptr, "getTemplate", &_zephir_call_cache[4], &_12$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_13$$3);
			zephir_create_array(&_13$$3, 2, 0);
			zephir_cast_to_string(&_15$$3, &key);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_14$$3, this_ptr, "escapeString", &_zephir_call_cache[5], &_15$$3);
			zephir_check_call_status();
			zephir_array_update_string(&_13$$3, SL("key"), &_14$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD_CACHED(&_14$$3, this_ptr, "getVarDump", &_zephir_call_cache[6], &value);
			zephir_check_call_status();
			zephir_array_update_string(&_13$$3, SL("value"), &_14$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD_CACHED(&_10$$3, this_ptr, "toInterpolate", &_zephir_call_cache[7], &_11$$3, &_13$$3);
			zephir_check_call_status();
			zephir_concat_self(&html, &_10$$3);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &source, "rewind", &_zephir_call_cache[8]);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &source, "next", &_zephir_call_cache[9]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_16, &source, "valid", &_zephir_call_cache[10]);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, &source, "key", &_zephir_call_cache[11]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &source, "current", &_zephir_call_cache[12]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_20$$4);
				ZVAL_STRING(&_20$$4, "gridRow");
				ZEPHIR_CALL_METHOD_CACHED(&_19$$4, this_ptr, "getTemplate", &_zephir_call_cache[13], &_20$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_21$$4);
				zephir_create_array(&_21$$4, 2, 0);
				zephir_cast_to_string(&_23$$4, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_22$$4, this_ptr, "escapeString", &_zephir_call_cache[14], &_23$$4);
				zephir_check_call_status();
				zephir_array_update_string(&_21$$4, SL("key"), &_22$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_22$$4, this_ptr, "getVarDump", &_zephir_call_cache[15], &value);
				zephir_check_call_status();
				zephir_array_update_string(&_21$$4, SL("value"), &_22$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_18$$4, this_ptr, "toInterpolate", &_zephir_call_cache[16], &_19$$4, &_21$$4);
				zephir_check_call_status();
				zephir_concat_self(&html, &_18$$4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "tableClose");
	ZEPHIR_CALL_METHOD_CACHED(&_24, this_ptr, "getTemplate", &_zephir_call_cache[17], &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "panelClose");
	ZEPHIR_CALL_METHOD_CACHED(&_25, this_ptr, "getTemplate", &_zephir_call_cache[18], &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVV(return_value, &html, &_24, &_25);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderTabs)
{
	zval _13, _14, _15, _16, _5$$3;
	zval _12, _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *report, report_sub, variablesTab, variablesCount, backtraceCount, requestCount, serverCount, filesCount, _0, _6, _7, _8, _9, _10, _11, _1$$3, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&report_sub);
	ZVAL_UNDEF(&variablesTab);
	ZVAL_UNDEF(&variablesCount);
	ZVAL_UNDEF(&backtraceCount);
	ZVAL_UNDEF(&requestCount);
	ZVAL_UNDEF(&serverCount);
	ZVAL_UNDEF(&filesCount);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_5$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[10];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(report, phalcon_support_debug_report_exceptionreport_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &report);
	ZEPHIR_INIT_VAR(&variablesTab);
	ZVAL_STRING(&variablesTab, "");
	ZEPHIR_CALL_METHOD_CACHED(&_0, report, "hasVariables", &_zephir_call_cache[0]);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD_CACHED(&_1$$3, report, "getVariables", &_zephir_call_cache[1]);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&variablesCount);
		ZVAL_LONG(&variablesCount, zephir_fast_count_int(&_1$$3));
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "variablesTab");
		ZEPHIR_CALL_METHOD_CACHED(&_2$$3, this_ptr, "getTemplate", &_zephir_call_cache[2], &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_create_array(&_4$$3, 1, 0);
		zephir_cast_to_string(&_5$$3, &variablesCount);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_4$$3, SL("variablesCount"), &_5$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(&variablesTab, this_ptr, "toInterpolate", &_zephir_call_cache[3], &_2$$3, &_4$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD_CACHED(&_6, report, "getBacktrace", &_zephir_call_cache[4]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&backtraceCount);
	ZVAL_LONG(&backtraceCount, zephir_fast_count_int(&_6));
	ZEPHIR_CALL_METHOD_CACHED(&_7, report, "getRequest", &_zephir_call_cache[5]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&requestCount);
	ZVAL_LONG(&requestCount, zephir_fast_count_int(&_7));
	ZEPHIR_CALL_METHOD_CACHED(&_8, report, "getServer", &_zephir_call_cache[6]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&serverCount);
	ZVAL_LONG(&serverCount, zephir_fast_count_int(&_8));
	ZEPHIR_CALL_METHOD_CACHED(&_9, report, "getIncludedFiles", &_zephir_call_cache[7]);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&filesCount);
	ZVAL_LONG(&filesCount, zephir_fast_count_int(&_9));
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "tabs");
	ZEPHIR_CALL_METHOD_CACHED(&_10, this_ptr, "getTemplate", &_zephir_call_cache[8], &_11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_12);
	zephir_create_array(&_12, 5, 0);
	zephir_cast_to_string(&_13, &backtraceCount);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&_12, SL("backtraceCount"), &_13, PH_COPY | PH_SEPARATE);
	zephir_cast_to_string(&_14, &requestCount);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&_12, SL("requestCount"), &_14, PH_COPY | PH_SEPARATE);
	zephir_cast_to_string(&_15, &serverCount);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&_12, SL("serverCount"), &_15, PH_COPY | PH_SEPARATE);
	zephir_cast_to_string(&_16, &filesCount);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&_12, SL("filesCount"), &_16, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_12, SL("variablesTab"), &variablesTab, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD_CACHED(this_ptr, "toInterpolate", &_zephir_call_cache[9], &_10, &_12);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderTraceItem)
{
	zval _4, _12$$3;
	zval _3, _9$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *index_param = NULL, *item, item_sub, html, isApp, appClass, openAttr, appTag, fragment, frameNumber, _0, _1, _2, _5, _14, _6$$3, _7$$3, _8$$3, _10$$3, _11$$3, _13$$4;
	zend_long index, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&isApp);
	ZVAL_UNDEF(&appClass);
	ZVAL_UNDEF(&openAttr);
	ZVAL_UNDEF(&appTag);
	ZVAL_UNDEF(&fragment);
	ZVAL_UNDEF(&frameNumber);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_12$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[15];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_support_debug_report_backtraceitem_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &index_param, &item);
	ZEPHIR_INIT_VAR(&frameNumber);
	ZVAL_LONG(&frameNumber, index);
	ZEPHIR_CALL_METHOD_CACHED(&_0, item, "getFile", &_zephir_call_cache[0]);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&isApp, this_ptr, "isApp", &_zephir_call_cache[1], &_0);
	zephir_check_call_status();
	if (zephir_is_true(&isApp)) {
		ZEPHIR_INIT_VAR(&appClass);
		ZVAL_STRING(&appClass, "app");
	} else {
		ZEPHIR_INIT_NVAR(&appClass);
		ZVAL_STRING(&appClass, "vendor");
	}
	if (ZEPHIR_IS_LONG(&frameNumber, 0)) {
		ZEPHIR_INIT_VAR(&openAttr);
		ZVAL_STRING(&openAttr, " open");
	} else {
		ZEPHIR_INIT_NVAR(&openAttr);
		ZVAL_STRING(&openAttr, "");
	}
	if (zephir_is_true(&isApp)) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_STRING(&_1, "appTag");
		ZEPHIR_CALL_METHOD_CACHED(&appTag, this_ptr, "getTemplate", &_zephir_call_cache[2], &_1);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&appTag);
		ZVAL_STRING(&appTag, "");
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "frameOpen");
	ZEPHIR_CALL_METHOD_CACHED(&_2, this_ptr, "getTemplate", &_zephir_call_cache[3], &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 5, 0);
	zephir_array_update_string(&_3, SL("appClass"), &appClass, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("open"), &openAttr, PH_COPY | PH_SEPARATE);
	zephir_cast_to_string(&_4, &frameNumber);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_array_update_string(&_3, SL("num"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&_5, this_ptr, "renderSignature", &_zephir_call_cache[4], item);
	zephir_check_call_status();
	zephir_array_update_string(&_3, SL("signature"), &_5, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("appTag"), &appTag, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD_CACHED(&html, this_ptr, "toInterpolate", &_zephir_call_cache[5], &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&_5, item, "getFile", &_zephir_call_cache[6]);
	zephir_check_call_status();
	if (Z_TYPE_P(&_5) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "frameFile");
		ZEPHIR_CALL_METHOD_CACHED(&_7$$3, this_ptr, "getTemplate", &_zephir_call_cache[7], &_8$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$3);
		zephir_create_array(&_9$$3, 2, 0);
		ZEPHIR_CALL_METHOD_CACHED(&_11$$3, item, "getFile", &_zephir_call_cache[8]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&_10$$3, this_ptr, "escapeString", &_zephir_call_cache[9], &_11$$3);
		zephir_check_call_status();
		zephir_array_update_string(&_9$$3, SL("file"), &_10$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(&_10$$3, item, "getLine", &_zephir_call_cache[10]);
		zephir_check_call_status();
		zephir_cast_to_string(&_12$$3, &_10$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_9$$3, SL("line"), &_12$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(&_6$$3, this_ptr, "toInterpolate", &_zephir_call_cache[11], &_7$$3, &_9$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_6$$3);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(&fragment, item, "getFragment", &_zephir_call_cache[12]);
		zephir_check_call_status();
		if (Z_TYPE_P(&fragment) != IS_NULL) {
			ZEPHIR_CALL_METHOD_CACHED(&_13$$4, this_ptr, "renderFragment", &_zephir_call_cache[13], &fragment);
			zephir_check_call_status();
			zephir_concat_self(&html, &_13$$4);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "frameClose");
	ZEPHIR_CALL_METHOD_CACHED(&_14, this_ptr, "getTemplate", &_zephir_call_cache[14], &_1);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &html, &_14);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * @phpstan-param support_debug_variables $variables
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderVariables)
{
	zval _15$$4, _24$$5;
	zend_bool _18;
	zend_string *_9;
	zend_ulong _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variables_param = NULL, html, key, value, _0, _1, _2, _4, _5, *_7, _17, _26, _27, _10$$4, _11$$4, _12$$4, _14$$4, _16$$4, _19$$5, _20$$5, _21$$5, _23$$5, _25$$5;
	zval variables, _3, _6, _13$$4, _22$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variables);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_24$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[19];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(variables, variables_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &variables_param);
	zephir_get_arrval(&variables, variables_param);
	if (ZEPHIR_IS_EMPTY(&variables)) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "panelOpen");
	ZEPHIR_CALL_METHOD_CACHED(&_1, this_ptr, "getTemplate", &_zephir_call_cache[0], &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0);
	add_assoc_stringl_ex(&_3, SL("id"), SL("variables"));
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "toInterpolate", &_zephir_call_cache[1], &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "tableOpen");
	ZEPHIR_CALL_METHOD_CACHED(&_5, this_ptr, "getTemplate", &_zephir_call_cache[2], &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0);
	add_assoc_stringl_ex(&_6, SL("headerOne"), SL("Key"));
	add_assoc_stringl_ex(&_6, SL("headerTwo"), SL("Value"));
	ZEPHIR_CALL_METHOD_CACHED(&_4, this_ptr, "toInterpolate", &_zephir_call_cache[3], &_5, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&html);
	ZEPHIR_CONCAT_VV(&html, &_0, &_4);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_is_iterable(&variables, 0, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 608);
	if (Z_TYPE_P(&variables) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&variables), _8, _9, _7)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_9 != NULL) { 
				ZVAL_STR_COPY(&key, _9);
			} else {
				ZVAL_LONG(&key, _8);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _7);
			ZEPHIR_INIT_NVAR(&_12$$4);
			ZVAL_STRING(&_12$$4, "gridRow");
			ZEPHIR_CALL_METHOD_CACHED(&_11$$4, this_ptr, "getTemplate", &_zephir_call_cache[4], &_12$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_13$$4);
			zephir_create_array(&_13$$4, 2, 0);
			zephir_cast_to_string(&_15$$4, &key);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_14$$4, this_ptr, "escapeString", &_zephir_call_cache[5], &_15$$4);
			zephir_check_call_status();
			zephir_array_update_string(&_13$$4, SL("key"), &_14$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_16$$4);
			zephir_array_fetch_long(&_16$$4, &value, 0, PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 603);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_14$$4, this_ptr, "getVarDump", &_zephir_call_cache[6], &_16$$4);
			zephir_check_call_status();
			zephir_array_update_string(&_13$$4, SL("value"), &_14$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD_CACHED(&_10$$4, this_ptr, "toInterpolate", &_zephir_call_cache[7], &_11$$4, &_13$$4);
			zephir_check_call_status();
			zephir_concat_self(&html, &_10$$4);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &variables, "rewind", &_zephir_call_cache[8]);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &variables, "next", &_zephir_call_cache[9]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_17, &variables, "valid", &_zephir_call_cache[10]);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, &variables, "key", &_zephir_call_cache[11]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &variables, "current", &_zephir_call_cache[12]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_21$$5);
				ZVAL_STRING(&_21$$5, "gridRow");
				ZEPHIR_CALL_METHOD_CACHED(&_20$$5, this_ptr, "getTemplate", &_zephir_call_cache[13], &_21$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_22$$5);
				zephir_create_array(&_22$$5, 2, 0);
				zephir_cast_to_string(&_24$$5, &key);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_23$$5, this_ptr, "escapeString", &_zephir_call_cache[14], &_24$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_22$$5, SL("key"), &_23$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_25$$5);
				zephir_array_fetch_long(&_25$$5, &value, 0, PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 603);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_23$$5, this_ptr, "getVarDump", &_zephir_call_cache[15], &_25$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_22$$5, SL("value"), &_23$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD_CACHED(&_19$$5, this_ptr, "toInterpolate", &_zephir_call_cache[16], &_20$$5, &_22$$5);
				zephir_check_call_status();
				zephir_concat_self(&html, &_19$$5);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "tableClose");
	ZEPHIR_CALL_METHOD_CACHED(&_26, this_ptr, "getTemplate", &_zephir_call_cache[17], &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "panelClose");
	ZEPHIR_CALL_METHOD_CACHED(&_27, this_ptr, "getTemplate", &_zephir_call_cache[18], &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVV(return_value, &html, &_26, &_27);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

/**
 * @param string   $input
 * @param string[] $context
 * @param string   $left
 * @param string   $right
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, toInterpolate)
{
	zend_bool _6;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context, replace;
	zval input_zv, *context_param = NULL, left_zv, right_zv, key, value, _0, *_1, _5, _4$$5, _7$$6;
	zend_string *input = NULL, *left = NULL, *right = NULL, *_3;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&left_zv);
	ZVAL_UNDEF(&right_zv);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&replace);
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
	ZEND_PARSE_PARAMETERS_START(1, 4)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(context, context_param)
		Z_PARAM_STR(left)
		Z_PARAM_STR(right)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		context_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}
	if (!left) {
		left = zend_string_init(ZEND_STRL("%"), 0);
		zephir_memory_observe(&left_zv);
		ZVAL_STR(&left_zv, left);
	} else {
		zephir_memory_observe(&left_zv);
	ZVAL_STR_COPY(&left_zv, left);
	}
	if (!right) {
		right = zend_string_init(ZEND_STRL("%"), 0);
		zephir_memory_observe(&right_zv);
		ZVAL_STR(&right_zv, right);
	} else {
		zephir_memory_observe(&right_zv);
	ZVAL_STR_COPY(&right_zv, right);
	}
	ZEPHIR_INIT_VAR(&replace);
	array_init(&replace);
	if (ZEPHIR_IS_EMPTY(&context)) {
		RETURN_MM_STR(zend_string_copy(input));
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strpos(&_0, &input_zv, &left_zv, 0 );
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		RETURN_MM_STR(zend_string_copy(input));
	}
	zephir_is_iterable(&context, 0, "phalcon/Traits/Support/Helper/Str/InterpolateTrait.zep", 49);
	if (Z_TYPE_P(&context) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&context), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			ZEPHIR_INIT_NVAR(&_4$$5);
			ZEPHIR_CONCAT_VVV(&_4$$5, &left_zv, &key, &right_zv);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&replace, &_4$$5, &value, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &context, "rewind", &_zephir_call_cache[0]);
		zephir_check_call_status();
		_6 = 1;
		while (1) {
			if (_6) {
				_6 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &context, "next", &_zephir_call_cache[1]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_5, &context, "valid", &_zephir_call_cache[2]);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&key, &context, "key", &_zephir_call_cache[3]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&value, &context, "current", &_zephir_call_cache[4]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_7$$6);
				ZEPHIR_CONCAT_VVV(&_7$$6, &left_zv, &key, &right_zv);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_zval(&replace, &_7$$6, &value, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 1, &input_zv, &replace);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, getTemplate)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, _0, _1, _3;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("templates", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 1378, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_2 = zephir_array_isset_value(&_1, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_2) {
		zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 1378, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch(&_0, &_3, &name_zv, PH_NOISY, "phalcon/Support/Debug/Traits/TemplateAwareTrait.zep", 33);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "defaultTemplate", &_zephir_call_cache[0], &name_zv);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);
}

PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, setTemplate)
{
	zval name_zv, template_zv;
	zend_string *name = NULL, *template = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&template_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_STR(template)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	ZVAL_STR(&template_zv, template);
	zephir_update_property_array(this_ptr, SL("templates"), &name_zv, &template_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_THISW();
}

