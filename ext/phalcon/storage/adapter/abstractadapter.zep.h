
extern zend_class_entry *phalcon_storage_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getDefaultSerializer);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, setDefaultSerializer);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getPrefix);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, __construct);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, clear);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, decrement);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, delete);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, get);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getAdapter);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getKeys);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, has);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, increment);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, set);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getPrefixedKey);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getSerializedData);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getTtl);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getUnserializedData);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, initSerializer);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getdefaultserializer, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getdefaultserializer, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_setdefaultserializer, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, defaultSerializer, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, defaultSerializer)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getprefix, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getprefix, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Storage\\SerializerFactory, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_clear, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_clear, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_decrement, 0, 0, 1)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_delete, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_delete, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getkeys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getkeys, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_increment, 0, 0, 1)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_set, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_set, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getprefixedkey, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getprefixedkey, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getserializeddata, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getttl, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getttl, 0, 1, IS_LONG, NULL, 0)
#endif
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getunserializeddata, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_initserializer, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_initserializer, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_phalcon_storage_adapter_abstractadapter_initserializer NULL
#endif

ZEPHIR_INIT_FUNCS(phalcon_storage_adapter_abstractadapter_method_entry) {
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getDefaultSerializer, arginfo_phalcon_storage_adapter_abstractadapter_getdefaultserializer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, setDefaultSerializer, arginfo_phalcon_storage_adapter_abstractadapter_setdefaultserializer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getPrefix, arginfo_phalcon_storage_adapter_abstractadapter_getprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, __construct, arginfo_phalcon_storage_adapter_abstractadapter___construct, ZEND_ACC_PROTECTED|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, clear, arginfo_phalcon_storage_adapter_abstractadapter_clear, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, decrement, arginfo_phalcon_storage_adapter_abstractadapter_decrement, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, delete, arginfo_phalcon_storage_adapter_abstractadapter_delete, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, get, arginfo_phalcon_storage_adapter_abstractadapter_get, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getAdapter, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getKeys, arginfo_phalcon_storage_adapter_abstractadapter_getkeys, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, has, arginfo_phalcon_storage_adapter_abstractadapter_has, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, increment, arginfo_phalcon_storage_adapter_abstractadapter_increment, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, set, arginfo_phalcon_storage_adapter_abstractadapter_set, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getPrefixedKey, arginfo_phalcon_storage_adapter_abstractadapter_getprefixedkey, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getSerializedData, arginfo_phalcon_storage_adapter_abstractadapter_getserializeddata, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getTtl, arginfo_phalcon_storage_adapter_abstractadapter_getttl, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getUnserializedData, arginfo_phalcon_storage_adapter_abstractadapter_getunserializeddata, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, initSerializer, arginfo_phalcon_storage_adapter_abstractadapter_initserializer, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
