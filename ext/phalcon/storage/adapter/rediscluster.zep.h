
extern zend_class_entry *phalcon_storage_adapter_rediscluster_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_RedisCluster);

PHP_METHOD(Phalcon_Storage_Adapter_RedisCluster, __construct);
PHP_METHOD(Phalcon_Storage_Adapter_RedisCluster, clear);
PHP_METHOD(Phalcon_Storage_Adapter_RedisCluster, getAdapter);
PHP_METHOD(Phalcon_Storage_Adapter_RedisCluster, getKeys);
PHP_METHOD(Phalcon_Storage_Adapter_RedisCluster, setSerializer);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_rediscluster___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Storage\\SerializerFactory, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_rediscluster_clear, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_rediscluster_getadapter, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_rediscluster_getkeys, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prefix, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_rediscluster_setserializer, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, connection, RedisCluster, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_adapter_rediscluster_method_entry) {
	PHP_ME(Phalcon_Storage_Adapter_RedisCluster, __construct, arginfo_phalcon_storage_adapter_rediscluster___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Storage_Adapter_RedisCluster, clear, arginfo_phalcon_storage_adapter_rediscluster_clear, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_Storage_Adapter_RedisCluster, getAdapter, arginfo_phalcon_storage_adapter_rediscluster_getadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_RedisCluster, getKeys, arginfo_phalcon_storage_adapter_rediscluster_getkeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_RedisCluster, setSerializer, arginfo_phalcon_storage_adapter_rediscluster_setserializer, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
