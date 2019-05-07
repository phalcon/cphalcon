
extern zend_class_entry *phalcon_cache_frontend_data_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Data);

PHP_METHOD(Phalcon_Cache_Frontend_Data, __construct);
PHP_METHOD(Phalcon_Cache_Frontend_Data, getLifetime);
PHP_METHOD(Phalcon_Cache_Frontend_Data, isBuffering);
PHP_METHOD(Phalcon_Cache_Frontend_Data, start);
PHP_METHOD(Phalcon_Cache_Frontend_Data, getContent);
PHP_METHOD(Phalcon_Cache_Frontend_Data, stop);
PHP_METHOD(Phalcon_Cache_Frontend_Data, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_Data, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_data___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, frontendOptions, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_data_getlifetime, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_data_getlifetime, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_data_isbuffering, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_data_isbuffering, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_data_beforestore, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_data_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontend_data_method_entry) {
	PHP_ME(Phalcon_Cache_Frontend_Data, __construct, arginfo_phalcon_cache_frontend_data___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Frontend_Data, getLifetime, arginfo_phalcon_cache_frontend_data_getlifetime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, isBuffering, arginfo_phalcon_cache_frontend_data_isbuffering, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, stop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, beforeStore, arginfo_phalcon_cache_frontend_data_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Data, afterRetrieve, arginfo_phalcon_cache_frontend_data_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
