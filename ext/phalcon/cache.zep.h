
extern zend_class_entry *phalcon_cache_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache);

PHP_METHOD(Phalcon_Cache, getAdapter);
PHP_METHOD(Phalcon_Cache, __construct);
PHP_METHOD(Phalcon_Cache, clear);
PHP_METHOD(Phalcon_Cache, delete);
PHP_METHOD(Phalcon_Cache, deleteMultiple);
PHP_METHOD(Phalcon_Cache, get);
PHP_METHOD(Phalcon_Cache, getMultiple);
PHP_METHOD(Phalcon_Cache, has);
PHP_METHOD(Phalcon_Cache, set);
PHP_METHOD(Phalcon_Cache, setMultiple);
PHP_METHOD(Phalcon_Cache, checkKey);
PHP_METHOD(Phalcon_Cache, checkKeys);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_getadapter, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, adapter, Phalcon\\Cache\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_clear, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_delete, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_deletemultiple, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_getmultiple, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_set, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_setmultiple, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_checkkey, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_cache_checkkeys, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Cache, getAdapter, arginfo_phalcon_cache_getadapter, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Cache, getAdapter, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Cache, __construct, arginfo_phalcon_cache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Cache, clear, arginfo_phalcon_cache_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache, delete, arginfo_phalcon_cache_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache, deleteMultiple, arginfo_phalcon_cache_deletemultiple, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache, get, arginfo_phalcon_cache_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache, getMultiple, arginfo_phalcon_cache_getmultiple, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache, has, arginfo_phalcon_cache_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache, set, arginfo_phalcon_cache_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache, setMultiple, arginfo_phalcon_cache_setmultiple, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache, checkKey, arginfo_phalcon_cache_checkkey, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Cache, checkKeys, arginfo_phalcon_cache_checkkeys, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
