
extern zend_class_entry *phalcon_mvc_model_resultinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ResultInterface);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_TYPE_MASK_EX(arginfo_phalcon_mvc_model_resultinterface_setdirtystate, 0, 1, Phalcon\\Mvc\\ModelInterface, MAY_BE_BOOL)
	ZEND_ARG_TYPE_INFO(0, dirtyState, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_resultinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultInterface, setDirtyState, arginfo_phalcon_mvc_model_resultinterface_setdirtystate)
	PHP_FE_END
};
