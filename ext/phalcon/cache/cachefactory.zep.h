
extern zend_class_entry *phalcon_cache_cachefactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_CacheFactory);

PHP_METHOD(Phalcon_Cache_CacheFactory, __construct);
PHP_METHOD(Phalcon_Cache_CacheFactory, load);
PHP_METHOD(Phalcon_Cache_CacheFactory, newInstance);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_cachefactory___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Cache\\AdapterFactory, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_cachefactory_load, 0, 0, 1)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cache_cachefactory_newinstance, 0, 1, Psr\\SimpleCache\\CacheInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_cachefactory_method_entry) {
	PHP_ME(Phalcon_Cache_CacheFactory, __construct, arginfo_phalcon_cache_cachefactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_CacheFactory, load, arginfo_phalcon_cache_cachefactory_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_CacheFactory, newInstance, arginfo_phalcon_cache_cachefactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
