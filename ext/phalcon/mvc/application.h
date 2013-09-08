
extern zend_class_entry *phalcon_mvc_application_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Application);

PHP_METHOD(Phalcon_Mvc_Application, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_application___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_application_method_entry) {
	PHP_ME(Phalcon_Mvc_Application, __construct, arginfo_phalcon_mvc_application___construct, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
