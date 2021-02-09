
extern zend_class_entry *phalcon_storage_adapter_redis_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Redis);

PHP_METHOD(Phalcon_Storage_Adapter_Redis, __construct);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, clear);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, decrement);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, delete);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, get);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, getAdapter);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, getKeys);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, has);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, increment);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, set);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, setSerializer);
zend_object *zephir_init_properties_Phalcon_Storage_Adapter_Redis(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_redis___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Storage\\SerializerFactory, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_clear, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_clear, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_redis_decrement, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_delete, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_delete, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_redis_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_redis_getadapter, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_getkeys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_getkeys, 0, 0, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, prefix)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_redis_increment, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, value)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_set, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_set, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_redis_setserializer, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, connection, Redis, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_redis_zephir_init_properties_phalcon_storage_adapter_redis, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_adapter_redis_method_entry) {
	PHP_ME(Phalcon_Storage_Adapter_Redis, __construct, arginfo_phalcon_storage_adapter_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Storage_Adapter_Redis, clear, arginfo_phalcon_storage_adapter_redis_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Redis, decrement, arginfo_phalcon_storage_adapter_redis_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Redis, delete, arginfo_phalcon_storage_adapter_redis_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Redis, get, arginfo_phalcon_storage_adapter_redis_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Redis, getAdapter, arginfo_phalcon_storage_adapter_redis_getadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Redis, getKeys, arginfo_phalcon_storage_adapter_redis_getkeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Redis, has, arginfo_phalcon_storage_adapter_redis_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Redis, increment, arginfo_phalcon_storage_adapter_redis_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Redis, set, arginfo_phalcon_storage_adapter_redis_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Redis, setSerializer, arginfo_phalcon_storage_adapter_redis_setserializer, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
