
extern zend_class_entry *phalcon_cache_backend_memcache_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Memcache);

PHP_METHOD(Phalcon_Cache_Backend_Memcache, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memcache___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontend)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_memcache_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_Memcache, __construct, arginfo_phalcon_cache_backend_memcache___construct, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
