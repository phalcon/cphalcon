
extern zend_class_entry *phalcon_cache_abstractcache_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_AbstractCache);

PHP_METHOD(Phalcon_Cache_AbstractCache, __construct);
PHP_METHOD(Phalcon_Cache_AbstractCache, getAdapter);
PHP_METHOD(Phalcon_Cache_AbstractCache, checkKey);
PHP_METHOD(Phalcon_Cache_AbstractCache, checkKeys);
PHP_METHOD(Phalcon_Cache_AbstractCache, doClear);
PHP_METHOD(Phalcon_Cache_AbstractCache, doDelete);
PHP_METHOD(Phalcon_Cache_AbstractCache, doDeleteMultiple);
PHP_METHOD(Phalcon_Cache_AbstractCache, doGet);
PHP_METHOD(Phalcon_Cache_AbstractCache, doGetMultiple);
PHP_METHOD(Phalcon_Cache_AbstractCache, doHas);
PHP_METHOD(Phalcon_Cache_AbstractCache, doSet);
PHP_METHOD(Phalcon_Cache_AbstractCache, doSetMultiple);
PHP_METHOD(Phalcon_Cache_AbstractCache, getExceptionClass);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_abstractcache___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, adapter, Phalcon\\Cache\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_cache_abstractcache_getadapter, 0, 0, Phalcon\\Cache\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_abstractcache_checkkey, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_abstractcache_checkkeys, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_abstractcache_doclear, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_abstractcache_dodelete, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_abstractcache_dodeletemultiple, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_abstractcache_doget, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_abstractcache_dogetmultiple, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_abstractcache_dohas, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_abstractcache_doset, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_abstractcache_dosetmultiple, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_abstractcache_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_abstractcache_method_entry) {
	PHP_ME(Phalcon_Cache_AbstractCache, __construct, arginfo_phalcon_cache_abstractcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache_AbstractCache, getAdapter, arginfo_phalcon_cache_abstractcache_getadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_AbstractCache, checkKey, arginfo_phalcon_cache_abstractcache_checkkey, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cache_AbstractCache, checkKeys, arginfo_phalcon_cache_abstractcache_checkkeys, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cache_AbstractCache, doClear, arginfo_phalcon_cache_abstractcache_doclear, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cache_AbstractCache, doDelete, arginfo_phalcon_cache_abstractcache_dodelete, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cache_AbstractCache, doDeleteMultiple, arginfo_phalcon_cache_abstractcache_dodeletemultiple, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cache_AbstractCache, doGet, arginfo_phalcon_cache_abstractcache_doget, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cache_AbstractCache, doGetMultiple, arginfo_phalcon_cache_abstractcache_dogetmultiple, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cache_AbstractCache, doHas, arginfo_phalcon_cache_abstractcache_dohas, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cache_AbstractCache, doSet, arginfo_phalcon_cache_abstractcache_doset, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cache_AbstractCache, doSetMultiple, arginfo_phalcon_cache_abstractcache_dosetmultiple, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cache_AbstractCache, getExceptionClass, arginfo_phalcon_cache_abstractcache_getexceptionclass, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_FE_END
};
