
extern zend_class_entry *phalcon_mvc_model_binderinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_BinderInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_binderinterface_bindtohandler, 0, 3, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_binderinterface_bindtohandler, 0, 3, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, cacheKey, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, cacheKey)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, methodName, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, methodName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_binderinterface_getboundmodels, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_binderinterface_getboundmodels, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_binderinterface_getcache, 0, 0, Phalcon\\Cache\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_binderinterface_getcache, 0, 0, IS_OBJECT, "Phalcon\\Cache\\Adapter\\AdapterInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_binderinterface_setcache, 0, 1, Phalcon\\Mvc\\Model\\BinderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_binderinterface_setcache, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\BinderInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, cache, Phalcon\\Cache\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_binderinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_BinderInterface, bindToHandler, arginfo_phalcon_mvc_model_binderinterface_bindtohandler)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_BinderInterface, getBoundModels, arginfo_phalcon_mvc_model_binderinterface_getboundmodels)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_BinderInterface, getCache, arginfo_phalcon_mvc_model_binderinterface_getcache)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_BinderInterface, setCache, arginfo_phalcon_mvc_model_binderinterface_setcache)
	PHP_FE_END
};
