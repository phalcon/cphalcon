
extern zend_class_entry *phalcon_mvc_model_relation_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Relation);

PHP_METHOD(Phalcon_Mvc_Model_Relation, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Relation, setIntermediateRelation);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getType);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedModel);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getFields);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getReferencedFields);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getOptions);
PHP_METHOD(Phalcon_Mvc_Model_Relation, isForeignKey);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getForeignKey);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getParams);
PHP_METHOD(Phalcon_Mvc_Model_Relation, isThrough);
PHP_METHOD(Phalcon_Mvc_Model_Relation, isReusable);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateFields);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateModel);
PHP_METHOD(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relation___construct, 0, 0, 4)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relation_setintermediaterelation, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateModel)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_relation_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Relation, __construct, arginfo_phalcon_mvc_model_relation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Relation, setIntermediateRelation, arginfo_phalcon_mvc_model_relation_setintermediaterelation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getReferencedModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getReferencedFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, isForeignKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getForeignKey, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, isThrough, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, isReusable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Relation, getIntermediateReferencedFields, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
