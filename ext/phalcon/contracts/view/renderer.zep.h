
extern zend_class_entry *phalcon_contracts_view_renderer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_View_Renderer);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_view_renderer_render, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, template, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, data, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_view_renderer_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_View_Renderer, render, arginfo_phalcon_contracts_view_renderer_render)
	PHP_FE_END
};
