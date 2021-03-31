
extern zend_class_entry *phalcon_mvc_view_engine_engineinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_EngineInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_engineinterface_getcontent, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_engineinterface_partial, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, partialPath, IS_STRING, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_engineinterface_render, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
	ZEND_ARG_INFO(0, params)
	ZEND_ARG_TYPE_INFO(0, mustClean, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_engineinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_Engine_EngineInterface, getContent, arginfo_phalcon_mvc_view_engine_engineinterface_getcontent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_Engine_EngineInterface, partial, arginfo_phalcon_mvc_view_engine_engineinterface_partial)
	PHP_ABSTRACT_ME(Phalcon_Mvc_View_Engine_EngineInterface, render, arginfo_phalcon_mvc_view_engine_engineinterface_render)
	PHP_FE_END
};
