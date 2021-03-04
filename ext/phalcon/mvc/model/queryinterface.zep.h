
extern zend_class_entry *phalcon_mvc_model_queryinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_QueryInterface);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_cache, 0, 1, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, cacheOptions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_execute, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_getbindparams, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_getcacheoptions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_getbindtypes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_getsql, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_getsingleresult, 0, 0, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_getuniquerow, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_parse, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_setbindparams, 0, 1, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, bindParams, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_setbindtypes, 0, 1, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, bindTypes, 0)
	ZEND_ARG_TYPE_INFO(0, merge, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_setsharedlock, 0, 0, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_TYPE_INFO(0, sharedLock, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_queryinterface_setuniquerow, 0, 1, Phalcon\\Mvc\\Model\\QueryInterface, 0)
	ZEND_ARG_TYPE_INFO(0, uniqueRow, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_queryinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, cache, arginfo_phalcon_mvc_model_queryinterface_cache)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, execute, arginfo_phalcon_mvc_model_queryinterface_execute)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, getBindParams, arginfo_phalcon_mvc_model_queryinterface_getbindparams)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, getCacheOptions, arginfo_phalcon_mvc_model_queryinterface_getcacheoptions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, getBindTypes, arginfo_phalcon_mvc_model_queryinterface_getbindtypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, getSql, arginfo_phalcon_mvc_model_queryinterface_getsql)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, getSingleResult, arginfo_phalcon_mvc_model_queryinterface_getsingleresult)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, getUniqueRow, arginfo_phalcon_mvc_model_queryinterface_getuniquerow)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, parse, arginfo_phalcon_mvc_model_queryinterface_parse)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, setBindParams, arginfo_phalcon_mvc_model_queryinterface_setbindparams)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, setBindTypes, arginfo_phalcon_mvc_model_queryinterface_setbindtypes)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, setSharedLock, arginfo_phalcon_mvc_model_queryinterface_setsharedlock)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_QueryInterface, setUniqueRow, arginfo_phalcon_mvc_model_queryinterface_setuniquerow)
	PHP_FE_END
};
