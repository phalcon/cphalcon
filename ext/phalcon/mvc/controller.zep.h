
extern zend_class_entry *phalcon_mvc_controller_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Controller);

PHP_METHOD(Phalcon_Mvc_Controller, __construct);

ZEPHIR_INIT_FUNCS(phalcon_mvc_controller_method_entry) {
	PHP_ME(Phalcon_Mvc_Controller, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_FINAL|ZEND_ACC_CTOR)
	PHP_FE_END
};
