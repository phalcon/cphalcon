
extern zend_class_entry *phalcon_contracts_support_debug_renderer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Support_Debug_Renderer);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_debug_renderer_getcsssources, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_debug_renderer_getjssources, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_debug_renderer_getversion, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_support_debug_renderer_render, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, report, Phalcon\\Support\\Debug\\Report\\ExceptionReport, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_support_debug_renderer_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Debug_Renderer, getCssSources, arginfo_phalcon_contracts_support_debug_renderer_getcsssources)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Debug_Renderer, getJsSources, arginfo_phalcon_contracts_support_debug_renderer_getjssources)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Debug_Renderer, getVersion, arginfo_phalcon_contracts_support_debug_renderer_getversion)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Support_Debug_Renderer, render, arginfo_phalcon_contracts_support_debug_renderer_render)
	PHP_FE_END
};
