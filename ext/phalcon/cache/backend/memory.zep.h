
extern zend_class_entry *phalcon_cache_backend_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Memory);

PHP_METHOD(Phalcon_Cache_Backend_Memory, get);
PHP_METHOD(Phalcon_Cache_Backend_Memory, save);
PHP_METHOD(Phalcon_Cache_Backend_Memory, delete);
PHP_METHOD(Phalcon_Cache_Backend_Memory, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Memory, exists);
PHP_METHOD(Phalcon_Cache_Backend_Memory, increment);
PHP_METHOD(Phalcon_Cache_Backend_Memory, decrement);
PHP_METHOD(Phalcon_Cache_Backend_Memory, flush);
PHP_METHOD(Phalcon_Cache_Backend_Memory, serialize);
PHP_METHOD(Phalcon_Cache_Backend_Memory, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, keyName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, keyName)
#endif
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_save, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_save, 0, 0, _IS_BOOL, NULL, 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_delete, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_delete, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_querykeys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_querykeys, 0, 0, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, prefix)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_exists, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_exists, 0, 0, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, keyName)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, lifetime)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_increment, 0, 0, IS_LONG, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_increment, 0, 0, IS_LONG, NULL, 1)
#endif
	ZEND_ARG_INFO(0, keyName)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_decrement, 0, 0, IS_LONG, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_decrement, 0, 0, IS_LONG, NULL, 1)
#endif
	ZEND_ARG_INFO(0, keyName)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_flush, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_flush, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_serialize, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backend_memory_serialize, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_memory_unserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_memory_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_Memory, get, arginfo_phalcon_cache_backend_memory_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, save, arginfo_phalcon_cache_backend_memory_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, delete, arginfo_phalcon_cache_backend_memory_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, queryKeys, arginfo_phalcon_cache_backend_memory_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, exists, arginfo_phalcon_cache_backend_memory_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, increment, arginfo_phalcon_cache_backend_memory_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, decrement, arginfo_phalcon_cache_backend_memory_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, flush, arginfo_phalcon_cache_backend_memory_flush, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, serialize, arginfo_phalcon_cache_backend_memory_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Memory, unserialize, arginfo_phalcon_cache_backend_memory_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
