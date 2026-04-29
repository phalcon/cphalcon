
extern zend_class_entry *phalcon_storage_adapter_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Memory);

PHP_METHOD(Phalcon_Storage_Adapter_Memory, __construct);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, clear);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, getKeys);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, setForever);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, doDecrement);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, doDelete);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, doGetData);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, doHas);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, doIncrement);
PHP_METHOD(Phalcon_Storage_Adapter_Memory, doSet);
zend_object *zephir_init_properties_Phalcon_Storage_Adapter_Memory(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_memory___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Storage\\SerializerFactory, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_memory_clear, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_memory_getkeys, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prefix, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_memory_setforever, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_memory_dodecrement, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, value, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_memory_dodelete, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_memory_dogetdata, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_memory_dohas, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_memory_doincrement, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, value, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_memory_doset, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_memory_zephir_init_properties_phalcon_storage_adapter_memory, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_adapter_memory_method_entry) {
	PHP_ME(Phalcon_Storage_Adapter_Memory, __construct, arginfo_phalcon_storage_adapter_memory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Storage_Adapter_Memory, clear, arginfo_phalcon_storage_adapter_memory_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Memory, getKeys, arginfo_phalcon_storage_adapter_memory_getkeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Memory, setForever, arginfo_phalcon_storage_adapter_memory_setforever, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Memory, doDecrement, arginfo_phalcon_storage_adapter_memory_dodecrement, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Memory, doDelete, arginfo_phalcon_storage_adapter_memory_dodelete, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Memory, doGetData, arginfo_phalcon_storage_adapter_memory_dogetdata, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Memory, doHas, arginfo_phalcon_storage_adapter_memory_dohas, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Memory, doIncrement, arginfo_phalcon_storage_adapter_memory_doincrement, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Memory, doSet, arginfo_phalcon_storage_adapter_memory_doset, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
