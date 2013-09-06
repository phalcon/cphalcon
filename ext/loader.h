
extern zend_class_entry *phalcon_loader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Loader);

PHP_METHOD(Phalcon_Loader, __construct);

ZEPHIR_INIT_FUNCS(phalcon_loader_method_entry) {
	PHP_ME(Phalcon_Loader, __construct, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
