
extern zend_class_entry *phalcon_mvc_viewbaseinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_ViewBaseInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_setviewsdir, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, viewsDir, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, viewsDir)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_setparamtoview, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_setvar, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_getparamstoview, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_getparamstoview, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_getcache, 0, 0, Phalcon\\Cache\\BackendInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_getcache, 0, 0, IS_OBJECT, "Phalcon\\Cache\\BackendInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_cache, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_setcontent, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, content, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, content)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_getcontent, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_getcontent, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_viewbaseinterface_partial, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, partialPath, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, partialPath)
#endif
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_viewbaseinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, setViewsDir, arginfo_phalcon_mvc_viewbaseinterface_setviewsdir)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, getViewsDir, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, setParamToView, arginfo_phalcon_mvc_viewbaseinterface_setparamtoview)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, setVar, arginfo_phalcon_mvc_viewbaseinterface_setvar)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, getParamsToView, arginfo_phalcon_mvc_viewbaseinterface_getparamstoview)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, getCache, arginfo_phalcon_mvc_viewbaseinterface_getcache)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, cache, arginfo_phalcon_mvc_viewbaseinterface_cache)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, setContent, arginfo_phalcon_mvc_viewbaseinterface_setcontent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, getContent, arginfo_phalcon_mvc_viewbaseinterface_getcontent)
	PHP_ABSTRACT_ME(Phalcon_Mvc_ViewBaseInterface, partial, arginfo_phalcon_mvc_viewbaseinterface_partial)
	PHP_FE_END
};
