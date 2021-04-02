
extern zend_class_entry *phalcon_storage_adapter_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Memory);

PHP_METHOD(Phalcon_Storage_Adapter_Memory, __construct);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, clear);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, decrement);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, delete);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, get);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, getAdapter);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, getKeys);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, has);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, increment);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, set);
zend_object *zephir_init_properties_Phalcon_Storage_Adapter_Memory(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_memory___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Storage\\SerializerFactory, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_memory_clear, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_memory_decrement, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_memory_delete, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_memory_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_memory_getadapter, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_memory_getkeys, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_memory_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_memory_increment, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_memory_set, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_memory_zephir_init_properties_phalcon_storage_adapter_memory, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_adapter_memory_method_entry) {
	PHP_ME(Phalcon_Storage_Adapter_Memory, __construct, arginfo_phalcon_storage_adapter_memory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Storage_Adapter_Memory, clear, arginfo_phalcon_storage_adapter_memory_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Memory, decrement, arginfo_phalcon_storage_adapter_memory_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Memory, delete, arginfo_phalcon_storage_adapter_memory_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Memory, get, arginfo_phalcon_storage_adapter_memory_get, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Storage_Adapter_Memory, getAdapter, arginfo_phalcon_storage_adapter_memory_getadapter, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Storage_Adapter_Memory, getAdapter, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Storage_Adapter_Memory, getKeys, arginfo_phalcon_storage_adapter_memory_getkeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Memory, has, arginfo_phalcon_storage_adapter_memory_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Memory, increment, arginfo_phalcon_storage_adapter_memory_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Memory, set, arginfo_phalcon_storage_adapter_memory_set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
