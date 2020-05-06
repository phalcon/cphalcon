
extern zend_class_entry *phalcon_mvc_model_resultsetinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ResultsetInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_delete, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_delete, 0, 0, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, conditionCallback, Closure, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_filter, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_filter, 0, 1, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, filter)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_getcache, 0, 0, Phalcon\\Cache\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_getcache, 0, 0, IS_OBJECT, "Phalcon\\Cache\\Adapter\\AdapterInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_gethydratemode, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_gethydratemode, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_getlast, 0, 0, Phalcon\\Mvc\\ModelInterface, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_getlast, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\ModelInterface", 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_getmessages, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_getmessages, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_gettype, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_gettype, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_isfresh, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_isfresh, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_sethydratemode, 0, 1, Phalcon\\Mvc\\Model\\ResultsetInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_sethydratemode, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\ResultsetInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, hydrateMode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, hydrateMode)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_setisfresh, 0, 1, Phalcon\\Mvc\\Model\\ResultsetInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_setisfresh, 0, 1, IS_OBJECT, "Phalcon\\Mvc\\Model\\ResultsetInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, isFresh, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, isFresh)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_toarray, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_toarray, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_update, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_resultsetinterface_update, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_OBJ_INFO(0, conditionCallback, Closure, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_resultsetinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, delete, arginfo_phalcon_mvc_model_resultsetinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, filter, arginfo_phalcon_mvc_model_resultsetinterface_filter)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getCache, arginfo_phalcon_mvc_model_resultsetinterface_getcache)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getFirst, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getHydrateMode, arginfo_phalcon_mvc_model_resultsetinterface_gethydratemode)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getLast, arginfo_phalcon_mvc_model_resultsetinterface_getlast)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getMessages, arginfo_phalcon_mvc_model_resultsetinterface_getmessages)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, getType, arginfo_phalcon_mvc_model_resultsetinterface_gettype)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, isFresh, arginfo_phalcon_mvc_model_resultsetinterface_isfresh)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, setHydrateMode, arginfo_phalcon_mvc_model_resultsetinterface_sethydratemode)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, setIsFresh, arginfo_phalcon_mvc_model_resultsetinterface_setisfresh)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, toArray, arginfo_phalcon_mvc_model_resultsetinterface_toarray)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultsetInterface, update, arginfo_phalcon_mvc_model_resultsetinterface_update)
	PHP_FE_END
};
