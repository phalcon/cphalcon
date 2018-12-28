
extern zend_class_entry *phalcon_mvc_model_resultinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ResultInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_resultinterface_setdirtystate, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dirtyState, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, dirtyState)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_resultinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_ResultInterface, setDirtyState, arginfo_phalcon_mvc_model_resultinterface_setdirtystate)
	PHP_FE_END
};
