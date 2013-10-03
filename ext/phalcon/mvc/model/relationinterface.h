
extern zend_class_entry *phalcon_mvc_model_relationinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_RelationInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface___construct, 0, 0, 4)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, referencedModel)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, referencedFields)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_relationinterface_setintermediaterelation, 0, 0, 3)
	ZEND_ARG_INFO(0, intermediateFields)
	ZEND_ARG_INFO(0, intermediateModel)
	ZEND_ARG_INFO(0, intermediateReferencedFields)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_relationinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, __construct, arginfo_phalcon_mvc_model_relationinterface___construct)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, setIntermediateRelation, arginfo_phalcon_mvc_model_relationinterface_setintermediaterelation)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, isReusable, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getType, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getReferencedModel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getFields, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getReferencedFields, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getOptions, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, isForeignKey, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getForeignKey, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, isThrough, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getIntermediateFields, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getIntermediateModel, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_RelationInterface, getIntermediateReferencedFields, NULL)
	PHP_FE_END
};
