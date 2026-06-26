
extern zend_class_entry *phalcon_support_debug_renderer_htmlrenderer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Debug_Renderer_HtmlRenderer);

PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, getCssSources);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, getJsSources);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, getTemplate);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, getVersion);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, render);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, setTemplate);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, defaultTemplate);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, escapeString);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, getArrayDump);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, getVarDump);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, formatBytes);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, isApp);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderBacktrace);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderFragment);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderIncludedFiles);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderMemory);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderSignature);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderSuperglobal);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderTabs);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderTraceItem);
PHP_METHOD(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderVariables);
zend_object *zephir_init_properties_Phalcon_Support_Debug_Renderer_HtmlRenderer(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_getcsssources, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_getjssources, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_gettemplate, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_getversion, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_render, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, report, Phalcon\\Support\\Debug\\Report\\ExceptionReport, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_settemplate, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, template, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_defaulttemplate, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_escapestring, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_getarraydump, 0, 1, IS_STRING, 1)
	ZEND_ARG_ARRAY_INFO(0, argument, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, number, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_getvardump, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, variable)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_formatbytes, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, bytes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_isapp, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_renderbacktrace, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, backtrace, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_renderfragment, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, fragment, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_renderincludedfiles, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, files, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_rendermemory, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, report, Phalcon\\Support\\Debug\\Report\\ExceptionReport, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_rendersignature, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Support\\Debug\\Report\\BacktraceItem, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_rendersuperglobal, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, div, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, source, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_rendertabs, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, report, Phalcon\\Support\\Debug\\Report\\ExceptionReport, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_rendertraceitem, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Support\\Debug\\Report\\BacktraceItem, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_rendervariables, 0, 1, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, variables, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_support_debug_renderer_htmlrenderer_zephir_init_properties_phalcon_support_debug_renderer_htmlrenderer, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_debug_renderer_htmlrenderer_method_entry) {
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, getCssSources, arginfo_phalcon_support_debug_renderer_htmlrenderer_getcsssources, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, getJsSources, arginfo_phalcon_support_debug_renderer_htmlrenderer_getjssources, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, getTemplate, arginfo_phalcon_support_debug_renderer_htmlrenderer_gettemplate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, getVersion, arginfo_phalcon_support_debug_renderer_htmlrenderer_getversion, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, render, arginfo_phalcon_support_debug_renderer_htmlrenderer_render, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, setTemplate, arginfo_phalcon_support_debug_renderer_htmlrenderer_settemplate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, defaultTemplate, arginfo_phalcon_support_debug_renderer_htmlrenderer_defaulttemplate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, escapeString, arginfo_phalcon_support_debug_renderer_htmlrenderer_escapestring, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, getArrayDump, arginfo_phalcon_support_debug_renderer_htmlrenderer_getarraydump, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, getVarDump, arginfo_phalcon_support_debug_renderer_htmlrenderer_getvardump, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, formatBytes, arginfo_phalcon_support_debug_renderer_htmlrenderer_formatbytes, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, isApp, arginfo_phalcon_support_debug_renderer_htmlrenderer_isapp, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderBacktrace, arginfo_phalcon_support_debug_renderer_htmlrenderer_renderbacktrace, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderFragment, arginfo_phalcon_support_debug_renderer_htmlrenderer_renderfragment, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderIncludedFiles, arginfo_phalcon_support_debug_renderer_htmlrenderer_renderincludedfiles, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderMemory, arginfo_phalcon_support_debug_renderer_htmlrenderer_rendermemory, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderSignature, arginfo_phalcon_support_debug_renderer_htmlrenderer_rendersignature, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderSuperglobal, arginfo_phalcon_support_debug_renderer_htmlrenderer_rendersuperglobal, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderTabs, arginfo_phalcon_support_debug_renderer_htmlrenderer_rendertabs, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderTraceItem, arginfo_phalcon_support_debug_renderer_htmlrenderer_rendertraceitem, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Debug_Renderer_HtmlRenderer, renderVariables, arginfo_phalcon_support_debug_renderer_htmlrenderer_rendervariables, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
