
extern zend_class_entry *phalcon_cache_multiple_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Multiple);

PHP_METHOD(Phalcon_Cache_Multiple, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_multiple___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, backends)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_multiple_method_entry) {
	PHP_ME(Phalcon_Cache_Multiple, __construct, arginfo_phalcon_cache_multiple___construct, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
