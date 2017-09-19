
extern zend_class_entry *phalcon_cache_backend_apcu_ce;

ZEPHIR_INIT_CLASS(Phalcon_Cache_Backend_Apcu);

PHP_METHOD(Phalcon_Cache_Backend_Apcu, get);
PHP_METHOD(Phalcon_Cache_Backend_Apcu, save);
PHP_METHOD(Phalcon_Cache_Backend_Apcu, increment);
PHP_METHOD(Phalcon_Cache_Backend_Apcu, decrement);
PHP_METHOD(Phalcon_Cache_Backend_Apcu, delete);
PHP_METHOD(Phalcon_Cache_Backend_Apcu, queryKeys);
PHP_METHOD(Phalcon_Cache_Backend_Apcu, exists);
PHP_METHOD(Phalcon_Cache_Backend_Apcu, flush);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apcu_get, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apcu_save, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, lifetime)
	ZEND_ARG_INFO(0, stopBuffer)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apcu_increment, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apcu_decrement, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apcu_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apcu_querykeys, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cache_backend_apcu_exists, 0, 0, 0)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_cache_backend_apcu_method_entry) {
	PHP_ME(Phalcon_Cache_Backend_Apcu, get, arginfo_phalcon_cache_backend_apcu_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Apcu, save, arginfo_phalcon_cache_backend_apcu_save, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Apcu, increment, arginfo_phalcon_cache_backend_apcu_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Apcu, decrement, arginfo_phalcon_cache_backend_apcu_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Apcu, delete, arginfo_phalcon_cache_backend_apcu_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Apcu, queryKeys, arginfo_phalcon_cache_backend_apcu_querykeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Apcu, exists, arginfo_phalcon_cache_backend_apcu_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Cache_Backend_Apcu, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
