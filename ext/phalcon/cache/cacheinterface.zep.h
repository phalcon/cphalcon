
extern zend_class_entry *phalcon_cache_cacheinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_CacheInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_cacheinterface_clear, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_cacheinterface_delete, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_cacheinterface_deletemultiple, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_cacheinterface_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_cacheinterface_getmultiple, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_cacheinterface_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_cacheinterface_set, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_cacheinterface_setmultiple, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_cacheinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Cache_CacheInterface, clear, arginfo_phalcon_cache_cacheinterface_clear)
	PHP_ABSTRACT_ME(Phalcon_Cache_CacheInterface, delete, arginfo_phalcon_cache_cacheinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Cache_CacheInterface, deleteMultiple, arginfo_phalcon_cache_cacheinterface_deletemultiple)
	PHP_ABSTRACT_ME(Phalcon_Cache_CacheInterface, get, arginfo_phalcon_cache_cacheinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Cache_CacheInterface, getMultiple, arginfo_phalcon_cache_cacheinterface_getmultiple)
	PHP_ABSTRACT_ME(Phalcon_Cache_CacheInterface, has, arginfo_phalcon_cache_cacheinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Cache_CacheInterface, set, arginfo_phalcon_cache_cacheinterface_set)
	PHP_ABSTRACT_ME(Phalcon_Cache_CacheInterface, setMultiple, arginfo_phalcon_cache_cacheinterface_setmultiple)
	PHP_FE_END
};
