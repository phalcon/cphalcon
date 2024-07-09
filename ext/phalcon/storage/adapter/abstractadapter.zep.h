
extern zend_class_entry *phalcon_storage_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, __construct);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, clear);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, decrement);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, delete);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, get);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getAdapter);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getDefaultSerializer);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getKeys);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getPrefix);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, has);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, increment);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, set);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, setDefaultSerializer);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, doGet);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getFilteredKeys);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getPrefixedKey);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getSerializedData);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getTtl);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getUnserializedData);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, initSerializer);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getArrVal);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, setEventsManager);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, getEventsManager);
PHP_METHOD(Phalcon_Storage_Adapter_AbstractAdapter, fire);
zend_object *zephir_init_properties_Phalcon_Storage_Adapter_AbstractAdapter(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Storage\\SerializerFactory, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_clear, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_decrement, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_delete, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getadapter, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getdefaultserializer, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getkeys, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getprefix, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_increment, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_set, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_setdefaultserializer, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, serializer, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_doget, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getfilteredkeys, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getprefixedkey, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getserializeddata, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getttl, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getunserializeddata, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_initserializer, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_getarrval, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO(0, cast, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_seteventsmanager, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_fire, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, eventName, IS_STRING, 0)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_abstractadapter_zephir_init_properties_phalcon_storage_adapter_abstractadapter, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_adapter_abstractadapter_method_entry) {
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, __construct, arginfo_phalcon_storage_adapter_abstractadapter___construct, ZEND_ACC_PROTECTED|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, clear, arginfo_phalcon_storage_adapter_abstractadapter_clear, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, decrement, arginfo_phalcon_storage_adapter_abstractadapter_decrement, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, delete, arginfo_phalcon_storage_adapter_abstractadapter_delete, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, get, arginfo_phalcon_storage_adapter_abstractadapter_get, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getAdapter, arginfo_phalcon_storage_adapter_abstractadapter_getadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getDefaultSerializer, arginfo_phalcon_storage_adapter_abstractadapter_getdefaultserializer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getKeys, arginfo_phalcon_storage_adapter_abstractadapter_getkeys, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getPrefix, arginfo_phalcon_storage_adapter_abstractadapter_getprefix, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, has, arginfo_phalcon_storage_adapter_abstractadapter_has, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, increment, arginfo_phalcon_storage_adapter_abstractadapter_increment, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, set, arginfo_phalcon_storage_adapter_abstractadapter_set, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, setDefaultSerializer, arginfo_phalcon_storage_adapter_abstractadapter_setdefaultserializer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, doGet, arginfo_phalcon_storage_adapter_abstractadapter_doget, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getFilteredKeys, arginfo_phalcon_storage_adapter_abstractadapter_getfilteredkeys, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getPrefixedKey, arginfo_phalcon_storage_adapter_abstractadapter_getprefixedkey, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getSerializedData, arginfo_phalcon_storage_adapter_abstractadapter_getserializeddata, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getTtl, arginfo_phalcon_storage_adapter_abstractadapter_getttl, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getUnserializedData, arginfo_phalcon_storage_adapter_abstractadapter_getunserializeddata, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, initSerializer, arginfo_phalcon_storage_adapter_abstractadapter_initserializer, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getArrVal, arginfo_phalcon_storage_adapter_abstractadapter_getarrval, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, setEventsManager, arginfo_phalcon_storage_adapter_abstractadapter_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, getEventsManager, arginfo_phalcon_storage_adapter_abstractadapter_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_AbstractAdapter, fire, arginfo_phalcon_storage_adapter_abstractadapter_fire, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
