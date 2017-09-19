
extern zend_class_entry *phalcon_mvc_model_binderinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_BinderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_binderinterface_setcache, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cache, Phalcon\\Cache\\BackendInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_binderinterface_bindtohandler, 0, 0, 3)
	ZEND_ARG_INFO(0, handler)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
	ZEND_ARG_INFO(0, cacheKey)
	ZEND_ARG_INFO(0, methodName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_binderinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_BinderInterface, getBoundModels, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_BinderInterface, getCache, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_BinderInterface, setCache, arginfo_phalcon_mvc_model_binderinterface_setcache)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_BinderInterface, bindToHandler, arginfo_phalcon_mvc_model_binderinterface_bindtohandler)
	PHP_FE_END
};
