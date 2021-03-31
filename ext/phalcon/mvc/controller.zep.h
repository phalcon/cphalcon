
extern zend_class_entry *phalcon_mvc_controller_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Controller);

PHP_METHOD(Phalcon_Mvc_Controller, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_controller___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_controller_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Mvc_Controller, __construct, arginfo_phalcon_mvc_controller___construct, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#else
	PHP_ME(Phalcon_Mvc_Controller, __construct, NULL, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#endif
	PHP_FE_END
};
