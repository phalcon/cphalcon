
extern zend_class_entry *phalcon_cache_backend_mongo_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Mongo);

PHP_METHOD(Phalcon_Cache_Backend_Mongo, __construct);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, _getCollection);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, get);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, save);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, delete);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, exists);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, gc);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, increment);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, decrement);
PHP_METHOD(Phalcon_Cache_Backend_Mongo, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, frontend, Phalcon\\Cache\\FrontendInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_mongo_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, keyName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, keyName)
#endif
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_mongo_save, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_mongo_save, 0, 0, _IS_BOOL, NULL, 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_mongo_delete, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_mongo_delete, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_mongo_querykeys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_mongo_querykeys, 0, 0, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, prefix)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_mongo_exists, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_mongo_exists, 0, 0, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, keyName)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, lifetime)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_mongo_increment, 0, 1, IS_LONG, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_mongo_increment, 0, 1, IS_LONG, NULL, 1)
#endif
	ZEND_ARG_INFO(0, keyName)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_mongo_decrement, 0, 1, IS_LONG, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_mongo_decrement, 0, 1, IS_LONG, NULL, 1)
#endif
	ZEND_ARG_INFO(0, keyName)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_mongo_flush, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_mongo_flush, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_mongo_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_Mongo, __construct, arginfo_phalcon_cache_backend_mongo___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_Backend_Mongo, _getCollection, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_ME(Phalcon_Cache_Backend_Mongo, get, arginfo_phalcon_cache_backend_mongo_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, save, arginfo_phalcon_cache_backend_mongo_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, delete, arginfo_phalcon_cache_backend_mongo_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, queryKeys, arginfo_phalcon_cache_backend_mongo_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, exists, arginfo_phalcon_cache_backend_mongo_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, gc, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, increment, arginfo_phalcon_cache_backend_mongo_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, decrement, arginfo_phalcon_cache_backend_mongo_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Mongo, flush, arginfo_phalcon_cache_backend_mongo_flush, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
