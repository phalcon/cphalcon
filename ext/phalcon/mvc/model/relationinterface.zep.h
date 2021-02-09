
extern zend_class_entry *phalcon_mvc_model_relationinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_RelationInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_getfields, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_getforeignkey, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_getintermediatefields, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_getintermediatemodel, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_getintermediatemodel, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_getintermediatereferencedfields, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_getoption, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_getoptions, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_getoptions, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_getparams, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_getreferencedfields, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_getreferencedmodel, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_getreferencedmodel, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_gettype, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_gettype, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_isforeignkey, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_isforeignkey, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_isreusable, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_isreusable, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_isthrough, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_isthrough, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_setintermediaterelation, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediateFields)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, intermediateModel, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, intermediateModel)
#endif
	ZEND_ARG_INFO(0, intermediateReferencedFields)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_relationinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getFields, arginfo_phalcon_mvc_model_relationinterface_getfields)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getForeignKey, arginfo_phalcon_mvc_model_relationinterface_getforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getIntermediateFields, arginfo_phalcon_mvc_model_relationinterface_getintermediatefields)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getIntermediateModel, arginfo_phalcon_mvc_model_relationinterface_getintermediatemodel)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getIntermediateReferencedFields, arginfo_phalcon_mvc_model_relationinterface_getintermediatereferencedfields)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getOption, arginfo_phalcon_mvc_model_relationinterface_getoption)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getOptions, arginfo_phalcon_mvc_model_relationinterface_getoptions)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getParams, arginfo_phalcon_mvc_model_relationinterface_getparams)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getReferencedFields, arginfo_phalcon_mvc_model_relationinterface_getreferencedfields)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getReferencedModel, arginfo_phalcon_mvc_model_relationinterface_getreferencedmodel)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getType, arginfo_phalcon_mvc_model_relationinterface_gettype)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, isForeignKey, arginfo_phalcon_mvc_model_relationinterface_isforeignkey)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, isReusable, arginfo_phalcon_mvc_model_relationinterface_isreusable)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, isThrough, arginfo_phalcon_mvc_model_relationinterface_isthrough)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, setIntermediateRelation, arginfo_phalcon_mvc_model_relationinterface_setintermediaterelation)
	PHP_FE_END
};
