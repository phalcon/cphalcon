
extern zend_class_entry *phalcon_mvc_viewbaseinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_ViewBaseInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_setviewsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, viewsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_setparamtoview, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_setvar, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_cache, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_viewbaseinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, setViewsDir, arginfo_phalcon_mvc_viewbaseinterface_setviewsdir)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, getViewsDir, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, setParamToView, arginfo_phalcon_mvc_viewbaseinterface_setparamtoview)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, setVar, arginfo_phalcon_mvc_viewbaseinterface_setvar)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, getParamsToView, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, getCache, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, cache, arginfo_phalcon_mvc_viewbaseinterface_cache)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, setContent, arginfo_phalcon_mvc_viewbaseinterface_setcontent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, getContent, NULL)
	PHP_FE_END
};
