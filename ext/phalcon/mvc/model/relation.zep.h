
extern zend_class_entry *phalcon_mvc_model_relation_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Relation);

PHP_METHOD(Phalcon_Mvc_Model_Relation, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getFields);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getForeignKey);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateFields);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateModel);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getOption);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getOptions);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getParams);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getType);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedFields);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedModel);
PHP_METHOD(Phalcon_Mvc_Model_Relation, isForeignKey);
PHP_METHOD(Phalcon_Mvc_Model_Relation, isThrough);
PHP_METHOD(Phalcon_Mvc_Model_Relation, isReusable);
PHP_METHOD(Phalcon_Mvc_Model_Relation, setIntermediateRelation);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relation___construct, 0, 0, 4)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, referencedModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relation_getfields, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relation_getforeignkey, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relation_getintermediatefields, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relation_getintermediatemodel, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relation_getintermediatereferencedfields, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relation_getoption, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relation_getoptions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relation_getparams, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relation_gettype, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relation_getreferencedfields, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relation_getreferencedmodel, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relation_isforeignkey, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relation_isthrough, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_relation_isreusable, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relation_setintermediaterelation, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_TYPE_INFO(0, intermediateModel, IS_STRING, 0)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_relation_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Relation, __construct, arginfo_phalcon_mvc_model_relation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Model_Relation, getFields, arginfo_phalcon_mvc_model_relation_getfields, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Model_Relation, getFields, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Model_Relation, getForeignKey, arginfo_phalcon_mvc_model_relation_getforeignkey, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Model_Relation, getForeignKey, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateFields, arginfo_phalcon_mvc_model_relation_getintermediatefields, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateFields, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateModel, arginfo_phalcon_mvc_model_relation_getintermediatemodel, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields, arginfo_phalcon_mvc_model_relation_getintermediatereferencedfields, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Model_Relation, getOption, arginfo_phalcon_mvc_model_relation_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getOptions, arginfo_phalcon_mvc_model_relation_getoptions, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Model_Relation, getParams, arginfo_phalcon_mvc_model_relation_getparams, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Model_Relation, getParams, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Model_Relation, getType, arginfo_phalcon_mvc_model_relation_gettype, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Model_Relation, getReferencedFields, arginfo_phalcon_mvc_model_relation_getreferencedfields, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Mvc_Model_Relation, getReferencedFields, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Mvc_Model_Relation, getReferencedModel, arginfo_phalcon_mvc_model_relation_getreferencedmodel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, isForeignKey, arginfo_phalcon_mvc_model_relation_isforeignkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, isThrough, arginfo_phalcon_mvc_model_relation_isthrough, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, isReusable, arginfo_phalcon_mvc_model_relation_isreusable, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, setIntermediateRelation, arginfo_phalcon_mvc_model_relation_setintermediaterelation, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
