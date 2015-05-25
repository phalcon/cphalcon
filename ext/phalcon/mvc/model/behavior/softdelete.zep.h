
extern zend_class_entry *phalcon_mvc_model_behavior_softdelete_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Behavior_SoftDelete);

PHP_METHOD(Phalcon_Mvc_Model_Behavior_SoftDelete, notify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_behavior_softdelete_notify, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_behavior_softdelete_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Behavior_SoftDelete, notify, arginfo_phalcon_mvc_model_behavior_softdelete_notify, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
