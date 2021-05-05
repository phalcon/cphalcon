
extern zend_class_entry *phalcon_storage_adapter_libmemcached_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Libmemcached);

PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, __construct);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, clear);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, decrement);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, delete);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, get);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, getAdapter);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, getKeys);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, has);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, increment);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, set);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, setSerializer);
zend_object *zephir_init_properties_Phalcon_Storage_Adapter_Libmemcached(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Storage\\SerializerFactory, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_clear, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_decrement, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_delete, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_getadapter, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_getkeys, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_increment, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_set, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_setserializer, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, connection, Memcached, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_zephir_init_properties_phalcon_storage_adapter_libmemcached, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_adapter_libmemcached_method_entry) {
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, __construct, arginfo_phalcon_storage_adapter_libmemcached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, clear, arginfo_phalcon_storage_adapter_libmemcached_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, decrement, arginfo_phalcon_storage_adapter_libmemcached_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, delete, arginfo_phalcon_storage_adapter_libmemcached_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, get, arginfo_phalcon_storage_adapter_libmemcached_get, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, getAdapter, arginfo_phalcon_storage_adapter_libmemcached_getadapter, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, getAdapter, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, getKeys, arginfo_phalcon_storage_adapter_libmemcached_getkeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, has, arginfo_phalcon_storage_adapter_libmemcached_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, increment, arginfo_phalcon_storage_adapter_libmemcached_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, set, arginfo_phalcon_storage_adapter_libmemcached_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, setSerializer, arginfo_phalcon_storage_adapter_libmemcached_setserializer, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
