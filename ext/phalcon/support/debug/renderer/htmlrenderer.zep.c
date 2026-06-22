
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
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
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Renders an ExceptionReport as the HTML debug page using embedded, overridable
 * template strings filled by strtr. All styling and interactivity (theme, tabs,
 * syntax highlighting, copy/editor links) are provided by the external
 * debug.css / debug.js assets.
 */
ZEPHIR_INIT_CLASS(Phalcon_Support_Debug_Renderer_HtmlRenderer)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Support\\Debug\\Renderer, HtmlRenderer, phalcon, support_debug_renderer_htmlrenderer, phalcon_support_debug_renderer_htmlrenderer_method_entry, 0);

	/**
	 * Template overrides keyed by name.
	 *
	 * @todo Move getTemplate()/setTemplate()/templates into a shared trait once
	 *       Zephir supports traits (mirrors
	 *       Phalcon\Support\Debug\Traits\TemplateAwareTrait in the PHP source).
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_support_debug_renderer_htmlrenderer_ce, SL("templates"), ZEND_ACC_PROTECTED);
	phalcon_support_debug_renderer_htmlrenderer_ce->create_object = zephir_init_properties_Phalcon_Support_Debug_Renderer_HtmlRenderer;

	zend_class_implements(phalcon_support_debug_renderer_htmlrenderer_ce, 1, phalcon_contracts_support_debug_renderer_ce);
	return SUCCESS;
}

/**
 * @param string $uri
 *
 * @return string
 */
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "cssLink");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_update_string(&_2, SL("%uri%"), &uri_zv, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&_2, SL("%path%"), SL("debug.css"));
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 4, &_0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $uri
 *
 * @return string
 */
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&uri_zv);
	ZVAL_STR_COPY(&uri_zv, uri);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "jsLink");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	zephir_array_update_string(&_2, SL("%uri%"), &uri_zv, PH_COPY | PH_SEPARATE);
	add_assoc_stringl_ex(&_2, SL("%path%"), SL("debug.js"));
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 4, &_0, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the template for the given name (override if set, default
 * otherwise).
 *
 * @param string $name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, getTemplate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, template, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_memory_observe(&template);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("templates"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&template, &_0, &name_zv, 0)) {
		RETURN_CCTOR(&template);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "defaulttemplate", NULL, 0, &name_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
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
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "version");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "gettemplate", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 2, 0);
	zephir_array_update_string(&_5, SL("%link%"), &link, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_6, &version, "get", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_5, SL("%version%"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 4, &_3, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param ExceptionReport $report
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, render)
{
	zval _11;
	zval _3, _6, _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *report, report_sub, className, escapedMessage, html, _0, _1, _2, _4, _5, _7, _8, _10, _12, _13, _27, _28, _29, _30, _14$$3, _15$$3, _16$$3, _17$$3, _18$$3, _19$$3, _20$$3, _21$$3, _22$$3, _23$$3, _24$$3, _25$$3, _26$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&report_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&escapedMessage);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
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
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(report, phalcon_support_debug_report_exceptionreport_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &report);
	ZEPHIR_CALL_METHOD(&className, report, "getclassname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, report, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&escapedMessage, this_ptr, "escapestring", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "document");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "gettemplate", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 3, 0);
	zephir_array_update_string(&_3, SL("%className%"), &className, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("%escapedMessage%"), &escapedMessage, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_5, report, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getcsssources", NULL, 0, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_3, SL("%cssSources%"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&html, "strtr", NULL, 4, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "masthead");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "gettemplate", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getversion", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_6, SL("%version%"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_7, "strtr", NULL, 4, &_4, &_6);
	zephir_check_call_status();
	zephir_concat_self(&html, &_7);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "errorMain");
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "gettemplate", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 5, 0);
	zephir_array_update_string(&_9, SL("%className%"), &className, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_9, SL("%escapedMessage%"), &escapedMessage, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_10, report, "getfile", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_9, SL("%file%"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_10, report, "getline", NULL, 0);
	zephir_check_call_status();
	zephir_cast_to_string(&_11, &_10);
	zephir_array_update_string(&_9, SL("%line%"), &_11, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_GET_CONSTANT(&_2, "PHP_VERSION");
	zephir_array_update_string(&_9, SL("%phpVersion%"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_12, "strtr", NULL, 4, &_8, &_9);
	zephir_check_call_status();
	zephir_concat_self(&html, &_12);
	ZEPHIR_CALL_METHOD(&_13, report, "isshowbacktrace", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_13)) {
		ZEPHIR_CALL_METHOD(&_14$$3, this_ptr, "rendertabs", NULL, 0, report);
		zephir_check_call_status();
		zephir_concat_self(&html, &_14$$3);
		ZEPHIR_CALL_METHOD(&_16$$3, report, "getbacktrace", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_15$$3, this_ptr, "renderbacktrace", NULL, 0, &_16$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_15$$3);
		ZEPHIR_CALL_METHOD(&_18$$3, report, "getrequest", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_19$$3);
		ZVAL_STRING(&_19$$3, "request");
		ZEPHIR_CALL_METHOD(&_17$$3, this_ptr, "rendersuperglobal", NULL, 0, &_19$$3, &_18$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_17$$3);
		ZEPHIR_CALL_METHOD(&_21$$3, report, "getserver", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_19$$3);
		ZVAL_STRING(&_19$$3, "server");
		ZEPHIR_CALL_METHOD(&_20$$3, this_ptr, "rendersuperglobal", NULL, 0, &_19$$3, &_21$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_20$$3);
		ZEPHIR_CALL_METHOD(&_23$$3, report, "getincludedfiles", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_22$$3, this_ptr, "renderincludedfiles", NULL, 0, &_23$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_22$$3);
		ZEPHIR_CALL_METHOD(&_24$$3, this_ptr, "rendermemory", NULL, 0, report);
		zephir_check_call_status();
		zephir_concat_self(&html, &_24$$3);
		ZEPHIR_CALL_METHOD(&_26$$3, report, "getvariables", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_25$$3, this_ptr, "rendervariables", NULL, 0, &_26$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_25$$3);
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "wrapClose");
	ZEPHIR_CALL_METHOD(&_27, this_ptr, "gettemplate", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_29, report, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_28, this_ptr, "getjssources", NULL, 0, &_29);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "documentClose");
	ZEPHIR_CALL_METHOD(&_30, this_ptr, "gettemplate", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVVV(return_value, &html, &_27, &_28, &_30);
	RETURN_MM();
}

/**
 * Overrides the template for the given name.
 *
 * @param string $name
 * @param string $template
 *
 * @return static
 */
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
	RETURN_THISW();
}

/**
 * Returns the embedded default template for the given name.
 *
 * @param string $name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, defaultTemplate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name_zv, defaults, template;
	zend_string *name = NULL;

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&defaults);
	ZVAL_UNDEF(&template);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_INIT_VAR(&defaults);
	zephir_create_array(&defaults, 25, 0);
	add_assoc_stringl_ex(&defaults, SL("cssLink"), SL("\n    <link href='%uri%%path%'\n          rel='stylesheet'\n          type='text/css' />"));
	add_assoc_stringl_ex(&defaults, SL("jsLink"), SL("\n    <script src='%uri%%path%'></script>"));
	add_assoc_stringl_ex(&defaults, SL("version"), SL("<a class='version-badge' href='%link%' target='_new'><b>v%version%</b></a>"));
	add_assoc_stringl_ex(&defaults, SL("document"), SL("<!DOCTYPE html>\n<html lang='en' data-theme='light'>\n<head>\n    <meta charset='utf-8'>\n    <meta name='viewport' content='width=device-width, initial-scale=1'>\n    <title>%className%:%escapedMessage%</title>%cssSources%\n</head>\n<body>\n<div class='wrap'>"));
	add_assoc_stringl_ex(&defaults, SL("masthead"), SL("\n    <div class='masthead'>\n        <div class='brand'><img class='logo' src='https://assets.phalcon.io/phalcon/images/svg/logo--tablet.svg' alt='Phalcon' /><span>Phalcon Debug</span></div>\n        <div class='actions-top'>\n            <button class='btn' data-action='copy-trace'>Copy trace</button>\n            <button class='btn' data-action='toggle-theme' title='Toggle theme'>Theme</button>\n            %version%\n        </div>\n    </div>"));
	add_assoc_stringl_ex(&defaults, SL("errorMain"), SL("\n    <div class='error-card'>\n        <span class='error-type'>%className%</span>\n        <h1 class='error-message'>%escapedMessage%</h1>\n        <div class='meta'>\n            <span class='item'><code>%file%</code> : <code>%line%</code></span>\n            <span class='sep'>|</span><span class='item'>PHP <code>%phpVersion%</code></span>\n        </div>\n    </div>"));
	add_assoc_stringl_ex(&defaults, SL("tabs"), SL("\n    <div class='tabs' role='tablist'>\n        <button class='tab is-active' data-tab='backtrace'>Backtrace <span class='count'>%backtraceCount%</span></button>\n        <button class='tab' data-tab='request'>Request <span class='count'>%requestCount%</span></button>\n        <button class='tab' data-tab='server'>Server <span class='count'>%serverCount%</span></button>\n        <button class='tab' data-tab='files'>Included Files <span class='count'>%filesCount%</span></button>\n        <button class='tab' data-tab='memory'>Memory</button>%variablesTab%\n    </div>"));
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
	add_assoc_stringl_ex(&defaults, SL("tableOpen"), SL("<table class='grid'><thead><tr><th>%headerOne%</th><th>%headerTwo%</th></tr></thead><tbody>"));
	add_assoc_stringl_ex(&defaults, SL("gridRow"), SL("<tr><td class='k'>%key%</td><td class='v'>%value%</td></tr>"));
	add_assoc_stringl_ex(&defaults, SL("tableClose"), SL("</tbody></table>"));
	add_assoc_stringl_ex(&defaults, SL("memory"), SL("\n        <div class='stats'>\n            <div class='stat'><div class='label'>Memory usage (real)</div><div class='value'>%memory% <small>MB</small></div></div>\n            <div class='stat'><div class='label'>Peak usage</div><div class='value'>%peak% <small>MB</small></div></div>\n        </div>"));
	zephir_memory_observe(&template);
	if (zephir_array_isset_fetch(&template, &defaults, &name_zv, 0)) {
		RETURN_CCTOR(&template);
	}
	RETURN_MM_STRING("");
}

/**
 * Escapes a string with htmlentities
 *
 * @param string $value
 *
 * @return string
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
 * @param array $argument
 * @param int   $n
 *
 * @return string|null
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, getArrayDump)
{
	zval _1$$4;
	zend_string *_4;
	zend_ulong _3;
	zend_bool _0, _12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zend_long number, ZEPHIR_LAST_CALL_STATUS;
	zval *argument_param = NULL, *number_param = NULL, numberArguments, dump, varDump, key, value, *_2, _11, _6$$8, _7$$8, _9$$9, _10$$5, _13$$15, _14$$15, _15$$16, _16$$12;
	zval argument;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argument);
	ZVAL_UNDEF(&numberArguments);
	ZVAL_UNDEF(&dump);
	ZVAL_UNDEF(&varDump);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_13$$15);
	ZVAL_UNDEF(&_14$$15);
	ZVAL_UNDEF(&_15$$16);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_1$$4);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(argument, argument_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(number)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &argument_param, &number_param);
	zephir_get_arrval(&argument, argument_param);
	if (!number_param) {
		number = 0;
	} else {
		}
	ZEPHIR_INIT_VAR(&numberArguments);
	ZVAL_LONG(&numberArguments, zephir_fast_count_int(&argument));
	_0 = number >= 3;
	if (!(_0)) {
		_0 = ZEPHIR_IS_LONG(&numberArguments, 0);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	if (ZEPHIR_GE_LONG(&numberArguments, 10)) {
		zephir_cast_to_string(&_1$$4, &numberArguments);
		RETURN_CTOR(&_1$$4);
	}
	ZEPHIR_INIT_VAR(&dump);
	array_init(&dump);
	zephir_is_iterable(&argument, 0, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 274);
	if (Z_TYPE_P(&argument) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&argument), _3, _4, _2)
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
				ZEPHIR_CALL_METHOD(&varDump, this_ptr, "escapestring", &_5, 0, &value);
				zephir_check_call_status();
			} else if (Z_TYPE_P(&value) == IS_ARRAY) {
				ZVAL_LONG(&_7$$8, (number + 1));
				ZEPHIR_CALL_METHOD(&_6$$8, this_ptr, "getarraydump", &_8, 0, &value, &_7$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&varDump);
				ZEPHIR_CONCAT_SVS(&varDump, "Array(", &_6$$8, ")");
			} else if (Z_TYPE_P(&value) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&_9$$9);
				zephir_get_class(&_9$$9, &value, 0);
				ZEPHIR_INIT_NVAR(&varDump);
				ZEPHIR_CONCAT_SVS(&varDump, "Object(", &_9$$9, ")");
			} else if (Z_TYPE_P(&value) == IS_NULL) {
				ZEPHIR_INIT_NVAR(&varDump);
				ZVAL_STRING(&varDump, "null");
			} else {
				ZEPHIR_CPY_WRT(&varDump, &value);
			}
			ZEPHIR_INIT_NVAR(&_10$$5);
			ZEPHIR_CONCAT_SVSV(&_10$$5, "[", &key, "] =&gt; ", &varDump);
			zephir_array_append(&dump, &_10$$5, PH_SEPARATE, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 271);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &argument, "rewind", NULL, 0);
		zephir_check_call_status();
		_12 = 1;
		while (1) {
			if (_12) {
				_12 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &argument, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_11, &argument, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &argument, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &argument, "current", NULL, 0);
			zephir_check_call_status();
				if (ZEPHIR_IS_STRING_IDENTICAL(&value, "")) {
					ZEPHIR_INIT_NVAR(&varDump);
					ZVAL_STRING(&varDump, "(empty string)");
				} else if (zephir_is_scalar(&value)) {
					ZEPHIR_CALL_METHOD(&varDump, this_ptr, "escapestring", &_5, 0, &value);
					zephir_check_call_status();
				} else if (Z_TYPE_P(&value) == IS_ARRAY) {
					ZVAL_LONG(&_14$$15, (number + 1));
					ZEPHIR_CALL_METHOD(&_13$$15, this_ptr, "getarraydump", &_8, 0, &value, &_14$$15);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&varDump);
					ZEPHIR_CONCAT_SVS(&varDump, "Array(", &_13$$15, ")");
				} else if (Z_TYPE_P(&value) == IS_OBJECT) {
					ZEPHIR_INIT_NVAR(&_15$$16);
					zephir_get_class(&_15$$16, &value, 0);
					ZEPHIR_INIT_NVAR(&varDump);
					ZEPHIR_CONCAT_SVS(&varDump, "Object(", &_15$$16, ")");
				} else if (Z_TYPE_P(&value) == IS_NULL) {
					ZEPHIR_INIT_NVAR(&varDump);
					ZVAL_STRING(&varDump, "null");
				} else {
					ZEPHIR_CPY_WRT(&varDump, &value);
				}
				ZEPHIR_INIT_NVAR(&_16$$12);
				ZEPHIR_CONCAT_SVSV(&_16$$12, "[", &key, "] =&gt; ", &varDump);
				zephir_array_append(&dump, &_16$$12, PH_SEPARATE, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 271);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	zephir_fast_join_str(return_value, SL(", "), &dump);
	RETURN_MM();
}

/**
 * Produces a string representation of a variable
 *
 * @param mixed $variable
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, getVarDump)
{
	zval _0$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variable, variable_sub, className, dumpedObject, _1$$8, _2$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variable_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&dumpedObject);
	ZVAL_UNDEF(&_1$$8);
	ZVAL_UNDEF(&_2$$9);
	ZVAL_UNDEF(&_0$$6);
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
		zephir_cast_to_string(&_0$$6, variable);
		RETURN_CTOR(&_0$$6);
	}
	if (Z_TYPE_P(variable) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&className);
		zephir_get_class(&className, variable, 0);
		if ((zephir_method_exists_ex(variable, ZEND_STRL("dump")) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(&dumpedObject, variable, "dump", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_1$$8, this_ptr, "getarraydump", NULL, 0, &dumpedObject);
			zephir_check_call_status();
			ZEPHIR_CONCAT_SVSVS(return_value, "Object(", &className, ": ", &_1$$8, ")");
			RETURN_MM();
		}
		ZEPHIR_CONCAT_SVS(return_value, "Object(", &className, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_2$$9, this_ptr, "getarraydump", NULL, 0, variable);
		zephir_check_call_status();
		ZEPHIR_CONCAT_SVS(return_value, "Array(", &_2$$9, ")");
		RETURN_MM();
	}
	if (Z_TYPE_P(variable) == IS_NULL) {
		RETURN_MM_STRING("null");
	}
	zephir_gettype(return_value, variable);
	RETURN_MM();
}

/**
 * @param int $bytes
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, formatBytes)
{
	double amount = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *bytes_param = NULL, _0, _1;
	zend_long bytes, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(bytes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &bytes_param);
	amount =  (zephir_safe_div_long_long(bytes, 1048576));
	ZVAL_DOUBLE(&_0, amount);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("number_format", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Frames whose file lives outside a vendor directory are application code.
 *
 * @param string|null $file
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, isApp)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *file, file_sub, _0, _1;

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(file)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &file);
	if (Z_TYPE_P(file) == IS_NULL) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/vendor/");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, file, &_0, 0 );
	RETURN_MM_BOOL(ZEPHIR_IS_FALSE_IDENTICAL(&_1));
}

/**
 * @param BacktraceItem[] $backtrace
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderBacktrace)
{
	zend_bool _7;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *backtrace_param = NULL, html, index, item, _0, *_1, _6, _9, _4$$3, _8$$4;
	zval backtrace;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&backtrace);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_8$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(backtrace, backtrace_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &backtrace_param);
	zephir_get_arrval(&backtrace, backtrace_param);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "backtracePanel");
	ZEPHIR_CALL_METHOD(&html, this_ptr, "gettemplate", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&backtrace, 0, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 372);
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
			ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "rendertraceitem", &_5, 0, &index, &item);
			zephir_check_call_status();
			zephir_concat_self(&html, &_4$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &backtrace, "rewind", NULL, 0);
		zephir_check_call_status();
		_7 = 1;
		while (1) {
			if (_7) {
				_7 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &backtrace, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_6, &backtrace, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, &backtrace, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&item, &backtrace, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "rendertraceitem", &_5, 0, &index, &item);
				zephir_check_call_status();
				zephir_concat_self(&html, &_8$$4);
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "panelClose");
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "gettemplate", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &html, &_9);
	RETURN_MM();
}

/**
 * @param array $fragment
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderFragment)
{
	zval _10$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fragment_param = NULL, firstLine, lastLine, line, lines, html, counter, currentLine, hlClass, source, index, _0, _13, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _8$$3, _11$$3;
	zval fragment, _9$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fragment);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&firstLine);
	ZVAL_UNDEF(&lastLine);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&counter);
	ZVAL_UNDEF(&currentLine);
	ZVAL_UNDEF(&hlClass);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_10$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(fragment, fragment_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &fragment_param);
	zephir_get_arrval(&fragment, fragment_param);
	zephir_memory_observe(&firstLine);
	zephir_array_fetch_string(&firstLine, &fragment, SL("firstLine"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 384);
	zephir_memory_observe(&lastLine);
	zephir_array_fetch_string(&lastLine, &fragment, SL("lastLine"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 385);
	zephir_memory_observe(&line);
	zephir_array_fetch_string(&line, &fragment, SL("line"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 386);
	zephir_memory_observe(&lines);
	zephir_array_fetch_string(&lines, &fragment, SL("lines"), PH_NOISY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 387);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "codeOpen");
	ZEPHIR_CALL_METHOD(&html, this_ptr, "gettemplate", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&counter, &firstLine);
	while (1) {
		if (!(ZEPHIR_LE(&counter, &lastLine))) {
			break;
		}
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_LONG(&index, (zephir_get_numberval(&counter) - 1));
		ZEPHIR_OBS_NVAR(&currentLine);
		if (!(zephir_array_isset_fetch(&currentLine, &lines, &index, 0))) {
			ZEPHIR_INIT_NVAR(&currentLine);
			ZVAL_STRING(&currentLine, "");
		}
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "\r\n");
		zephir_fast_trim(&_1$$3, &currentLine, &_2$$3, ZEPHIR_TRIM_RIGHT);
		ZEPHIR_CPY_WRT(&currentLine, &_1$$3);
		if (ZEPHIR_IS_IDENTICAL(&counter, &line)) {
			ZEPHIR_INIT_NVAR(&hlClass);
			ZVAL_STRING(&hlClass, " class='hl'");
		} else {
			ZEPHIR_INIT_NVAR(&hlClass);
			ZVAL_STRING(&hlClass, "");
		}
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "\t");
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "  ");
		zephir_fast_str_replace(&_1$$3, &_3$$3, &_4$$3, &currentLine);
		ZVAL_LONG(&_5$$3, 2);
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "UTF-8");
		ZEPHIR_CALL_FUNCTION(&source, "htmlentities", &_7, 0, &_1$$3, &_5$$3, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "codeRow");
		ZEPHIR_CALL_METHOD(&_8$$3, this_ptr, "gettemplate", NULL, 0, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_9$$3);
		zephir_create_array(&_9$$3, 3, 0);
		zephir_array_update_string(&_9$$3, SL("%hlClass%"), &hlClass, PH_COPY | PH_SEPARATE);
		zephir_cast_to_string(&_10$$3, &counter);
		zephir_array_update_string(&_9$$3, SL("%num%"), &_10$$3, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_9$$3, SL("%src%"), &source, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_11$$3, "strtr", &_12, 4, &_8$$3, &_9$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_11$$3);
		SEPARATE_ZVAL(&counter);
		zephir_increment(&counter);
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "codeClose");
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "gettemplate", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &html, &_13);
	RETURN_MM();
}

/**
 * @param array $files
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderIncludedFiles)
{
	zval _13$$3, _21$$4;
	zend_bool _17;
	zend_string *_9;
	zend_ulong _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_15 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *files_param = NULL, html, key, value, _0, _1, _3, _4, _6, *_7, _16, _23, _24, _10$$3, _11$$3, _14$$3, _18$$4, _19$$4, _22$$4;
	zval files, _2, _5, _12$$3, _20$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_21$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(files, files_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &files_param);
	zephir_get_arrval(&files, files_param);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "panelOpen");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0);
	add_assoc_stringl_ex(&_2, SL("%id%"), SL("files"));
	ZEPHIR_CALL_FUNCTION(&_3, "strtr", NULL, 4, &_0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tableOpen");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 2, 0);
	add_assoc_stringl_ex(&_5, SL("%headerOne%"), SL("#"));
	add_assoc_stringl_ex(&_5, SL("%headerTwo%"), SL("Path"));
	ZEPHIR_CALL_FUNCTION(&_6, "strtr", NULL, 4, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&html);
	ZEPHIR_CONCAT_VV(&html, &_3, &_6);
	zephir_is_iterable(&files, 0, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 447);
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
			ZEPHIR_INIT_NVAR(&_11$$3);
			ZVAL_STRING(&_11$$3, "gridRow");
			ZEPHIR_CALL_METHOD(&_10$$3, this_ptr, "gettemplate", NULL, 0, &_11$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_12$$3);
			zephir_create_array(&_12$$3, 2, 0);
			zephir_cast_to_string(&_13$$3, &key);
			zephir_array_update_string(&_12$$3, SL("%key%"), &_13$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_14$$3, this_ptr, "escapestring", &_15, 0, &value);
			zephir_check_call_status();
			zephir_array_update_string(&_12$$3, SL("%value%"), &_14$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_14$$3, "strtr", NULL, 4, &_10$$3, &_12$$3);
			zephir_check_call_status();
			zephir_concat_self(&html, &_14$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &files, "rewind", NULL, 0);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &files, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_16, &files, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &files, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &files, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_19$$4);
				ZVAL_STRING(&_19$$4, "gridRow");
				ZEPHIR_CALL_METHOD(&_18$$4, this_ptr, "gettemplate", NULL, 0, &_19$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_20$$4);
				zephir_create_array(&_20$$4, 2, 0);
				zephir_cast_to_string(&_21$$4, &key);
				zephir_array_update_string(&_20$$4, SL("%key%"), &_21$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_22$$4, this_ptr, "escapestring", &_15, 0, &value);
				zephir_check_call_status();
				zephir_array_update_string(&_20$$4, SL("%value%"), &_22$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_22$$4, "strtr", NULL, 4, &_18$$4, &_20$$4);
				zephir_check_call_status();
				zephir_concat_self(&html, &_22$$4);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tableClose");
	ZEPHIR_CALL_METHOD(&_23, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "panelClose");
	ZEPHIR_CALL_METHOD(&_24, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVV(return_value, &html, &_23, &_24);
	RETURN_MM();
}

/**
 * @param ExceptionReport $report
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderMemory)
{
	zval _2, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *report, report_sub, _0, _1, _3, _4, _6, _7, _8, _9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&report_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(report, phalcon_support_debug_report_exceptionreport_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &report);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "panelOpen");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0);
	add_assoc_stringl_ex(&_2, SL("%id%"), SL("memory"));
	ZEPHIR_CALL_FUNCTION(&_3, "strtr", NULL, 4, &_0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "memory");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 2, 0);
	ZEPHIR_CALL_METHOD(&_7, report, "getmemoryusage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "formatbytes", NULL, 0, &_7);
	zephir_check_call_status();
	zephir_array_update_string(&_5, SL("%memory%"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_8, report, "getpeakmemoryusage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "formatbytes", NULL, 0, &_8);
	zephir_check_call_status();
	zephir_array_update_string(&_5, SL("%peak%"), &_6, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_6, "strtr", NULL, 4, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "panelClose");
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVV(return_value, &_3, &_6, &_9);
	RETURN_MM();
}

/**
 * @param BacktraceItem $item
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderSignature)
{
	zend_bool _20$$8;
	zval _4$$4, _12$$6;
	zval _7$$3, _8$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, html, name, link, classHtml, fnName, fnLink, functionHtml, arguments, argument, _0, _9, _13, _14, _1$$3, _5$$3, _6$$3, _2$$4, _3$$4, _10$$6, _11$$6, _15$$8, *_16$$8, _19$$8, _22$$8, _23$$8, _17$$9, _21$$10;
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
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_12$$6);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_support_debug_report_backtraceitem_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &item);
	ZEPHIR_INIT_VAR(&html);
	ZVAL_STRING(&html, "");
	ZEPHIR_CALL_METHOD(&_0, item, "getclassname", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&_1$$3, item, "getclassname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&name, this_ptr, "escapestring", NULL, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&link, item, "getclasslink", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&link) != IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "link");
			ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "gettemplate", NULL, 0, &_3$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_4$$4);
			zephir_create_array(&_4$$4, 2, 0);
			zephir_array_update_string(&_4$$4, SL("%url%"), &link, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_4$$4, SL("%name%"), &name, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&classHtml, "strtr", NULL, 4, &_2$$4, &_4$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&classHtml, &name);
		}
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_SVS(&_5$$3, "<span class='cls'>", &classHtml, "</span>");
		zephir_concat_self(&html, &_5$$3);
		ZEPHIR_CALL_METHOD(&_6$$3, item, "gettype", NULL, 0);
		zephir_check_call_status();
		zephir_cast_to_string(&_7$$3, &_6$$3);
		ZEPHIR_INIT_VAR(&_8$$3);
		ZEPHIR_CONCAT_SVS(&_8$$3, "<span class='op'>", &_7$$3, "</span>");
		zephir_concat_self(&html, &_8$$3);
	}
	ZEPHIR_CALL_METHOD(&_9, item, "getfunctionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&fnName, this_ptr, "escapestring", NULL, 0, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&fnLink, item, "getfunctionlink", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&fnLink) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_11$$6);
		ZVAL_STRING(&_11$$6, "link");
		ZEPHIR_CALL_METHOD(&_10$$6, this_ptr, "gettemplate", NULL, 0, &_11$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_12$$6);
		zephir_create_array(&_12$$6, 2, 0);
		zephir_array_update_string(&_12$$6, SL("%url%"), &fnLink, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_12$$6, SL("%name%"), &fnName, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&functionHtml, "strtr", NULL, 4, &_10$$6, &_12$$6);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&functionHtml, &fnName);
	}
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_CONCAT_SVS(&_13, "<span class='fn'>", &functionHtml, "</span>");
	zephir_concat_self(&html, &_13);
	ZEPHIR_CALL_METHOD(&_14, item, "hasargs", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_14)) {
		ZEPHIR_INIT_VAR(&arguments);
		array_init(&arguments);
		ZEPHIR_CALL_METHOD(&_15$$8, item, "getargs", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(&_15$$8, 0, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 517);
		if (Z_TYPE_P(&_15$$8) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_15$$8), _16$$8)
			{
				ZEPHIR_INIT_NVAR(&argument);
				ZVAL_COPY(&argument, _16$$8);
				ZEPHIR_CALL_METHOD(&_17$$9, this_ptr, "getvardump", &_18, 0, &argument);
				zephir_check_call_status();
				zephir_array_append(&arguments, &_17$$9, PH_SEPARATE, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 514);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_15$$8, "rewind", NULL, 0);
			zephir_check_call_status();
			_20$$8 = 1;
			while (1) {
				if (_20$$8) {
					_20$$8 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_15$$8, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_19$$8, &_15$$8, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_19$$8)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&argument, &_15$$8, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_21$$10, this_ptr, "getvardump", &_18, 0, &argument);
					zephir_check_call_status();
					zephir_array_append(&arguments, &_21$$10, PH_SEPARATE, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 514);
			}
		}
		ZEPHIR_INIT_NVAR(&argument);
		ZEPHIR_INIT_VAR(&_22$$8);
		zephir_fast_join_str(&_22$$8, SL(", "), &arguments);
		ZEPHIR_INIT_VAR(&_23$$8);
		ZEPHIR_CONCAT_SVS(&_23$$8, "<span class='op'>(</span>", &_22$$8, "<span class='op'>)</span>");
		zephir_concat_self(&html, &_23$$8);
	}
	RETURN_CCTOR(&html);
}

/**
 * @param string $div
 * @param array  $source
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderSuperglobal)
{
	zval _14$$3, _23$$4;
	zend_bool _18;
	zend_ulong _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_15 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval source, _2, _5, _12$$3, _21$$4;
	zval div_zv, *source_param = NULL, html, key, value, _0, _1, _3, _4, _6, *_7, _17, _24, _25, _10$$3, _11$$3, _13$$3, _19$$4, _20$$4, _22$$4;
	zend_string *div = NULL, *_9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&div_zv);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_22$$4);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_21$$4);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_23$$4);
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
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "panelOpen");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0);
	zephir_array_update_string(&_2, SL("%id%"), &div_zv, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_3, "strtr", NULL, 4, &_0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tableOpen");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 2, 0);
	add_assoc_stringl_ex(&_5, SL("%headerOne%"), SL("Key"));
	add_assoc_stringl_ex(&_5, SL("%headerTwo%"), SL("Value"));
	ZEPHIR_CALL_FUNCTION(&_6, "strtr", NULL, 4, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&html);
	ZEPHIR_CONCAT_VV(&html, &_3, &_6);
	zephir_is_iterable(&source, 0, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 549);
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
			ZEPHIR_INIT_NVAR(&_11$$3);
			ZVAL_STRING(&_11$$3, "gridRow");
			ZEPHIR_CALL_METHOD(&_10$$3, this_ptr, "gettemplate", NULL, 0, &_11$$3);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_12$$3);
			zephir_create_array(&_12$$3, 2, 0);
			zephir_cast_to_string(&_14$$3, &key);
			ZEPHIR_CALL_METHOD(&_13$$3, this_ptr, "escapestring", &_15, 0, &_14$$3);
			zephir_check_call_status();
			zephir_array_update_string(&_12$$3, SL("%key%"), &_13$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_13$$3, this_ptr, "getvardump", &_16, 0, &value);
			zephir_check_call_status();
			zephir_array_update_string(&_12$$3, SL("%value%"), &_13$$3, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_13$$3, "strtr", NULL, 4, &_10$$3, &_12$$3);
			zephir_check_call_status();
			zephir_concat_self(&html, &_13$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &source, "rewind", NULL, 0);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &source, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_17, &source, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &source, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &source, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_20$$4);
				ZVAL_STRING(&_20$$4, "gridRow");
				ZEPHIR_CALL_METHOD(&_19$$4, this_ptr, "gettemplate", NULL, 0, &_20$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_21$$4);
				zephir_create_array(&_21$$4, 2, 0);
				zephir_cast_to_string(&_23$$4, &key);
				ZEPHIR_CALL_METHOD(&_22$$4, this_ptr, "escapestring", &_15, 0, &_23$$4);
				zephir_check_call_status();
				zephir_array_update_string(&_21$$4, SL("%key%"), &_22$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_22$$4, this_ptr, "getvardump", &_16, 0, &value);
				zephir_check_call_status();
				zephir_array_update_string(&_21$$4, SL("%value%"), &_22$$4, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_22$$4, "strtr", NULL, 4, &_19$$4, &_21$$4);
				zephir_check_call_status();
				zephir_concat_self(&html, &_22$$4);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tableClose");
	ZEPHIR_CALL_METHOD(&_24, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "panelClose");
	ZEPHIR_CALL_METHOD(&_25, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVV(return_value, &html, &_24, &_25);
	RETURN_MM();
}

/**
 * @param ExceptionReport $report
 *
 * @return string
 */
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
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(report, phalcon_support_debug_report_exceptionreport_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &report);
	ZEPHIR_INIT_VAR(&variablesTab);
	ZVAL_STRING(&variablesTab, "");
	ZEPHIR_CALL_METHOD(&_0, report, "hasvariables", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$3, report, "getvariables", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&variablesCount);
		ZVAL_LONG(&variablesCount, zephir_fast_count_int(&_1$$3));
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "variablesTab");
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "gettemplate", NULL, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_create_array(&_4$$3, 1, 0);
		zephir_cast_to_string(&_5$$3, &variablesCount);
		zephir_array_update_string(&_4$$3, SL("%variablesCount%"), &_5$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&variablesTab, "strtr", NULL, 4, &_2$$3, &_4$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_6, report, "getbacktrace", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&backtraceCount);
	ZVAL_LONG(&backtraceCount, zephir_fast_count_int(&_6));
	ZEPHIR_CALL_METHOD(&_7, report, "getrequest", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&requestCount);
	ZVAL_LONG(&requestCount, zephir_fast_count_int(&_7));
	ZEPHIR_CALL_METHOD(&_8, report, "getserver", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&serverCount);
	ZVAL_LONG(&serverCount, zephir_fast_count_int(&_8));
	ZEPHIR_CALL_METHOD(&_9, report, "getincludedfiles", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&filesCount);
	ZVAL_LONG(&filesCount, zephir_fast_count_int(&_9));
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "tabs");
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "gettemplate", NULL, 0, &_11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_12);
	zephir_create_array(&_12, 5, 0);
	zephir_cast_to_string(&_13, &backtraceCount);
	zephir_array_update_string(&_12, SL("%backtraceCount%"), &_13, PH_COPY | PH_SEPARATE);
	zephir_cast_to_string(&_14, &requestCount);
	zephir_array_update_string(&_12, SL("%requestCount%"), &_14, PH_COPY | PH_SEPARATE);
	zephir_cast_to_string(&_15, &serverCount);
	zephir_array_update_string(&_12, SL("%serverCount%"), &_15, PH_COPY | PH_SEPARATE);
	zephir_cast_to_string(&_16, &filesCount);
	zephir_array_update_string(&_12, SL("%filesCount%"), &_16, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_12, SL("%variablesTab%"), &variablesTab, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 4, &_10, &_12);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param int           $index
 * @param BacktraceItem $item
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderTraceItem)
{
	zval _4, _10$$3;
	zval _3, _8$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *index_param = NULL, *item, item_sub, html, isApp, appClass, openAttr, appTag, fragment, frameNumber, _0, _1, _2, _5, _13, _6$$3, _7$$3, _9$$3, _11$$3, _12$$4;
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
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_10$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_OBJECT_OF_CLASS(item, phalcon_support_debug_report_backtraceitem_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &index_param, &item);
	ZEPHIR_INIT_VAR(&frameNumber);
	ZVAL_LONG(&frameNumber, index);
	ZEPHIR_CALL_METHOD(&_0, item, "getfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&isApp, this_ptr, "isapp", NULL, 0, &_0);
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
		ZEPHIR_CALL_METHOD(&appTag, this_ptr, "gettemplate", NULL, 0, &_1);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&appTag);
		ZVAL_STRING(&appTag, "");
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "frameOpen");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 5, 0);
	zephir_array_update_string(&_3, SL("%appClass%"), &appClass, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("%open%"), &openAttr, PH_COPY | PH_SEPARATE);
	zephir_cast_to_string(&_4, &frameNumber);
	zephir_array_update_string(&_3, SL("%num%"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "rendersignature", NULL, 0, item);
	zephir_check_call_status();
	zephir_array_update_string(&_3, SL("%signature%"), &_5, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("%appTag%"), &appTag, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&html, "strtr", NULL, 4, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, item, "getfile", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&_5) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "frameFile");
		ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "gettemplate", NULL, 0, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$3);
		zephir_create_array(&_8$$3, 2, 0);
		ZEPHIR_CALL_METHOD(&_9$$3, item, "getfile", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_8$$3, SL("%file%"), &_9$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_9$$3, item, "getline", NULL, 0);
		zephir_check_call_status();
		zephir_cast_to_string(&_10$$3, &_9$$3);
		zephir_array_update_string(&_8$$3, SL("%line%"), &_10$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_FUNCTION(&_11$$3, "strtr", NULL, 4, &_6$$3, &_8$$3);
		zephir_check_call_status();
		zephir_concat_self(&html, &_11$$3);
		ZEPHIR_CALL_METHOD(&fragment, item, "getfragment", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&fragment) != IS_NULL) {
			ZEPHIR_CALL_METHOD(&_12$$4, this_ptr, "renderfragment", NULL, 0, &fragment);
			zephir_check_call_status();
			zephir_concat_self(&html, &_12$$4);
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "frameClose");
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &html, &_13);
	RETURN_MM();
}

/**
 * @param array $variables
 *
 * @return string
 */
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderVariables)
{
	zval _14$$4, _24$$5;
	zend_bool _19;
	zend_string *_9;
	zend_ulong _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_15 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *variables_param = NULL, html, key, value, _0, _1, _3, _4, _6, *_7, _18, _26, _27, _10$$4, _11$$4, _13$$4, _16$$4, _20$$5, _21$$5, _23$$5, _25$$5;
	zval variables, _2, _5, _12$$4, _22$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&variables);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_22$$5);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_23$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_24$$5);
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
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "panelOpen");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0);
	add_assoc_stringl_ex(&_2, SL("%id%"), SL("variables"));
	ZEPHIR_CALL_FUNCTION(&_3, "strtr", NULL, 4, &_0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tableOpen");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 2, 0);
	add_assoc_stringl_ex(&_5, SL("%headerOne%"), SL("Key"));
	add_assoc_stringl_ex(&_5, SL("%headerTwo%"), SL("Value"));
	ZEPHIR_CALL_FUNCTION(&_6, "strtr", NULL, 4, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&html);
	ZEPHIR_CONCAT_VV(&html, &_3, &_6);
	zephir_is_iterable(&variables, 0, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 663);
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
			ZEPHIR_INIT_NVAR(&_11$$4);
			ZVAL_STRING(&_11$$4, "gridRow");
			ZEPHIR_CALL_METHOD(&_10$$4, this_ptr, "gettemplate", NULL, 0, &_11$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_12$$4);
			zephir_create_array(&_12$$4, 2, 0);
			zephir_cast_to_string(&_14$$4, &key);
			ZEPHIR_CALL_METHOD(&_13$$4, this_ptr, "escapestring", &_15, 0, &_14$$4);
			zephir_check_call_status();
			zephir_array_update_string(&_12$$4, SL("%key%"), &_13$$4, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_long(&_16$$4, &value, 0, PH_NOISY | PH_READONLY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 658);
			ZEPHIR_CALL_METHOD(&_13$$4, this_ptr, "getvardump", &_17, 0, &_16$$4);
			zephir_check_call_status();
			zephir_array_update_string(&_12$$4, SL("%value%"), &_13$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_13$$4, "strtr", NULL, 4, &_10$$4, &_12$$4);
			zephir_check_call_status();
			zephir_concat_self(&html, &_13$$4);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &variables, "rewind", NULL, 0);
		zephir_check_call_status();
		_19 = 1;
		while (1) {
			if (_19) {
				_19 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &variables, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_18, &variables, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_18)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &variables, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &variables, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_21$$5);
				ZVAL_STRING(&_21$$5, "gridRow");
				ZEPHIR_CALL_METHOD(&_20$$5, this_ptr, "gettemplate", NULL, 0, &_21$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_22$$5);
				zephir_create_array(&_22$$5, 2, 0);
				zephir_cast_to_string(&_24$$5, &key);
				ZEPHIR_CALL_METHOD(&_23$$5, this_ptr, "escapestring", &_15, 0, &_24$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_22$$5, SL("%key%"), &_23$$5, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_long(&_25$$5, &value, 0, PH_NOISY | PH_READONLY, "phalcon/Support/Debug/Renderer/HtmlRenderer.zep", 658);
				ZEPHIR_CALL_METHOD(&_23$$5, this_ptr, "getvardump", &_17, 0, &_25$$5);
				zephir_check_call_status();
				zephir_array_update_string(&_22$$5, SL("%value%"), &_23$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_FUNCTION(&_23$$5, "strtr", NULL, 4, &_20$$5, &_22$$5);
				zephir_check_call_status();
				zephir_concat_self(&html, &_23$$5);
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "tableClose");
	ZEPHIR_CALL_METHOD(&_26, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "panelClose");
	ZEPHIR_CALL_METHOD(&_27, this_ptr, "gettemplate", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVV(return_value, &html, &_26, &_27);
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Support_Debug_Renderer_HtmlRenderer(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("templates"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("templates"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

