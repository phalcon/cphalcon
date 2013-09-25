
extern zend_class_entry *phalcon_cache_frontend_igbinary_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Igbinary);

PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, __construct);
PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, getLifetime);
PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, isBuffering);
PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, start);
PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, getContent);
PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, stop);
PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_Igbinary, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_igbinary___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, frontendOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_igbinary_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_igbinary_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontend_igbinary_method_entry) {
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, __construct, arginfo_phalcon_cache_frontend_igbinary___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, getLifetime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, isBuffering, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, stop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, beforeStore, arginfo_phalcon_cache_frontend_igbinary_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Igbinary, afterRetrieve, arginfo_phalcon_cache_frontend_igbinary_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
