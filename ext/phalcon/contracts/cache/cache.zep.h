
extern zend_class_entry *phalcon_contracts_cache_cache_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Cache_Cache);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_cache_cache_clear, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_cache_cache_delete, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_cache_cache_deletemultiple, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_cache_cache_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_contracts_cache_cache_getmultiple, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_cache_cache_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_cache_cache_set, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_cache_cache_setmultiple, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, values)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_cache_cache_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cache_Cache, clear, arginfo_phalcon_contracts_cache_cache_clear)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cache_Cache, delete, arginfo_phalcon_contracts_cache_cache_delete)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cache_Cache, deleteMultiple, arginfo_phalcon_contracts_cache_cache_deletemultiple)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cache_Cache, get, arginfo_phalcon_contracts_cache_cache_get)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cache_Cache, getMultiple, arginfo_phalcon_contracts_cache_cache_getmultiple)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cache_Cache, has, arginfo_phalcon_contracts_cache_cache_has)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cache_Cache, set, arginfo_phalcon_contracts_cache_cache_set)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Cache_Cache, setMultiple, arginfo_phalcon_contracts_cache_cache_setmultiple)
	PHP_FE_END
};
