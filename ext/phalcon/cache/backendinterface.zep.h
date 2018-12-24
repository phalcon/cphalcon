
extern zend_class_entry *phalcon_cache_backendinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_BackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_start, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_stop, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, stopBuffer, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, stopBuffer)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cache_backendinterface_getfrontend, 0, 0, Phalcon\\Cache\\FrontendInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_getfrontend, 0, 0, IS_OBJECT, "Phalcon\\Cache\\FrontendInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_getoptions, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_getoptions, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_isfresh, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_isfresh, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_isstarted, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_isstarted, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_setlastkey, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lastKey, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, lastKey)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_getlastkey, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_getlastkey, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backendinterface_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, keyName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, keyName)
#endif
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_save, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_save, 0, 0, _IS_BOOL, NULL, 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_delete, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_delete, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_querykeys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_querykeys, 0, 0, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, prefix)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_exists, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_backendinterface_exists, 0, 0, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, keyName)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, lifetime, IS_LONG, 1)
#else
	ZEND_ARG_INFO(0, lifetime)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backendinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, start, arginfo_phalcon_cache_backendinterface_start)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, stop, arginfo_phalcon_cache_backendinterface_stop)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, getFrontend, arginfo_phalcon_cache_backendinterface_getfrontend)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, getOptions, arginfo_phalcon_cache_backendinterface_getoptions)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, isFresh, arginfo_phalcon_cache_backendinterface_isfresh)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, isStarted, arginfo_phalcon_cache_backendinterface_isstarted)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, setLastKey, arginfo_phalcon_cache_backendinterface_setlastkey)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, getLastKey, arginfo_phalcon_cache_backendinterface_getlastkey)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, get, arginfo_phalcon_cache_backendinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, save, arginfo_phalcon_cache_backendinterface_save)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, delete, arginfo_phalcon_cache_backendinterface_delete)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, queryKeys, arginfo_phalcon_cache_backendinterface_querykeys)
	PHP_ABSTRACT_ME(Phalcon_Cache_BackendInterface, exists, arginfo_phalcon_cache_backendinterface_exists)
	PHP_FE_END
};
