
extern zend_class_entry *phalcon_cache_backend_redis_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Redis);

PHP_METHOD(Phalcon_Cache_Backend_Redis, __construct);
PHP_METHOD(Phalcon_Cache_Backend_Redis, connect);
PHP_METHOD(Phalcon_Cache_Backend_Redis, get);
PHP_METHOD(Phalcon_Cache_Backend_Redis, save);
PHP_METHOD(Phalcon_Cache_Backend_Redis, delete);
PHP_METHOD(Phalcon_Cache_Backend_Redis, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Redis, exists);
PHP_METHOD(Phalcon_Cache_Backend_Redis, increment);
PHP_METHOD(Phalcon_Cache_Backend_Redis, decrement);
PHP_METHOD(Phalcon_Cache_Backend_Redis, flush);
PHP_METHOD(Phalcon_Cache_Backend_Redis, getPrefixedKey);
PHP_METHOD(Phalcon_Cache_Backend_Redis, getStoreKey);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_redis___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, frontend, Phalcon\\Cache\\FrontendInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_redis_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, keyName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, keyName)
#endif
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_save, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_save, 0, 0, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, stopBuffer, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, stopBuffer)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_delete, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_delete, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_querykeys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_querykeys, 0, 0, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, prefix)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_exists, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_exists, 0, 0, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, keyName)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, lifetime)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_increment, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_increment, 0, 0, IS_LONG, NULL, 0)
#endif
	ZEND_ARG_INFO(0, keyName)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_decrement, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_decrement, 0, 0, IS_LONG, NULL, 0)
#endif
	ZEND_ARG_INFO(0, keyName)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_flush, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_flush, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_getprefixedkey, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_getprefixedkey, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, keyName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, keyName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_getstorekey, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_redis_getstorekey, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, keyName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, keyName)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_redis_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_Redis, __construct, arginfo_phalcon_cache_backend_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend_Redis, connect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, get, arginfo_phalcon_cache_backend_redis_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, save, arginfo_phalcon_cache_backend_redis_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, delete, arginfo_phalcon_cache_backend_redis_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, queryKeys, arginfo_phalcon_cache_backend_redis_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, exists, arginfo_phalcon_cache_backend_redis_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, increment, arginfo_phalcon_cache_backend_redis_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, decrement, arginfo_phalcon_cache_backend_redis_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, flush, arginfo_phalcon_cache_backend_redis_flush, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Redis, getPrefixedKey, arginfo_phalcon_cache_backend_redis_getprefixedkey, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Cache_Backend_Redis, getStoreKey, arginfo_phalcon_cache_backend_redis_getstorekey, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
