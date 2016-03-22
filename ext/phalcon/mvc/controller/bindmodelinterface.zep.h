
extern zend_class_entry *phalcon_mvc_controller_bindmodelinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Controller_BindModelInterface);

ZEPHIR_INIT_FUNCS(phalcon_mvc_controller_bindmodelinterface_method_entry) {
	ZEND_FENTRY(getModelName, NULL, NULL, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
