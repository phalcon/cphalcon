
extern zend_class_entry *phalcon_cache_frontend_base64_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Frontend_Base64);

PHP_METHOD(Phalcon_Cache_Frontend_Base64, __construct);
PHP_METHOD(Phalcon_Cache_Frontend_Base64, getLifetime);
PHP_METHOD(Phalcon_Cache_Frontend_Base64, isBuffering);
PHP_METHOD(Phalcon_Cache_Frontend_Base64, start);
PHP_METHOD(Phalcon_Cache_Frontend_Base64, getContent);
PHP_METHOD(Phalcon_Cache_Frontend_Base64, stop);
PHP_METHOD(Phalcon_Cache_Frontend_Base64, beforeStore);
PHP_METHOD(Phalcon_Cache_Frontend_Base64, afterRetrieve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_base64___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, frontendOptions, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_base64_getlifetime, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_base64_getlifetime, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_base64_isbuffering, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_base64_isbuffering, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_base64_beforestore, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_frontend_base64_beforestore, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_frontend_base64_afterretrieve, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_frontend_base64_method_entry) {
	PHP_ME(Phalcon_Cache_Frontend_Base64, __construct, arginfo_phalcon_cache_frontend_base64___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Frontend_Base64, getLifetime, arginfo_phalcon_cache_frontend_base64_getlifetime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Base64, isBuffering, arginfo_phalcon_cache_frontend_base64_isbuffering, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Base64, start, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Base64, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Base64, stop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Base64, beforeStore, arginfo_phalcon_cache_frontend_base64_beforestore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Frontend_Base64, afterRetrieve, arginfo_phalcon_cache_frontend_base64_afterretrieve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
