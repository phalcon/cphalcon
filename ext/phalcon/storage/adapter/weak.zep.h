
extern zend_class_entry *phalcon_storage_adapter_weak_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Weak);

PHP_METHOD(Phalcon_Storage_Adapter_Weak, __construct);
PHP_METHOD(Phalcon_Storage_Adapter_Weak, clear);
PHP_METHOD(Phalcon_Storage_Adapter_Weak, decrement);
PHP_METHOD(Phalcon_Storage_Adapter_Weak, delete);
PHP_METHOD(Phalcon_Storage_Adapter_Weak, getKeys);
PHP_METHOD(Phalcon_Storage_Adapter_Weak, increment);
PHP_METHOD(Phalcon_Storage_Adapter_Weak, get);
PHP_METHOD(Phalcon_Storage_Adapter_Weak, has);
PHP_METHOD(Phalcon_Storage_Adapter_Weak, set);
PHP_METHOD(Phalcon_Storage_Adapter_Weak, setForever);
PHP_METHOD(Phalcon_Storage_Adapter_Weak, setDefaultSerializer);
zend_object *zephir_init_properties_Phalcon_Storage_Adapter_Weak(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_weak___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Storage\\SerializerFactory, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_weak_clear, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_weak_decrement, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_weak_delete, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_weak_getkeys, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_weak_increment, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_weak_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_weak_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_weak_set, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_weak_setforever, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_weak_setdefaultserializer, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, serializer, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_weak_zephir_init_properties_phalcon_storage_adapter_weak, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_adapter_weak_method_entry) {
	PHP_ME(Phalcon_Storage_Adapter_Weak, __construct, arginfo_phalcon_storage_adapter_weak___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Storage_Adapter_Weak, clear, arginfo_phalcon_storage_adapter_weak_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Weak, decrement, arginfo_phalcon_storage_adapter_weak_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Weak, delete, arginfo_phalcon_storage_adapter_weak_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Weak, getKeys, arginfo_phalcon_storage_adapter_weak_getkeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Weak, increment, arginfo_phalcon_storage_adapter_weak_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Weak, get, arginfo_phalcon_storage_adapter_weak_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Weak, has, arginfo_phalcon_storage_adapter_weak_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Weak, set, arginfo_phalcon_storage_adapter_weak_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Weak, setForever, arginfo_phalcon_storage_adapter_weak_setforever, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Weak, setDefaultSerializer, arginfo_phalcon_storage_adapter_weak_setdefaultserializer, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
