
extern zend_class_entry *phalcon_cache_frontend_json_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Json);

PHP_METHOD(Phalcon_Cache_Frontend_Json, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_json___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontend_json_method_entry) {
	PHP_ME(Phalcon_Cache_Frontend_Json, __construct, arginfo_phalcon_cache_frontend_json___construct, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
