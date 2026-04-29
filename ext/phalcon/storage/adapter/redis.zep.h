
extern zend_class_entry *phalcon_storage_adapter_redis_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Redis);

PHP_METHOD(Phalcon_Storage_Adapter_Redis, __construct);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, clear);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, getAdapter);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, getKeys);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, setForever);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, doDecrement);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, doDelete);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, doDeleteMultiple);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, doHas);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, doIncrement);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, doSet);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, checkAuth);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, checkConnect);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, checkIndex);
PHP_METHOD(Phalcon_Storage_Adapter_Redis, setSerializer);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_redis___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Storage\\SerializerFactory, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_clear, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_redis_getadapter, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_getkeys, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prefix, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_setforever, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_redis_dodecrement, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, value, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_dodelete, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_dodeletemultiple, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_dohas, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_redis_doincrement, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, value, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_doset, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_storage_adapter_redis_checkauth, 0, 1, Phalcon\\Storage\\Adapter\\Redis, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Redis, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_storage_adapter_redis_checkconnect, 0, 1, Phalcon\\Storage\\Adapter\\Redis, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Redis, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_storage_adapter_redis_checkindex, 0, 1, Phalcon\\Storage\\Adapter\\Redis, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Redis, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_redis_setserializer, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, connection, Redis, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_adapter_redis_method_entry) {
	PHP_ME(Phalcon_Storage_Adapter_Redis, __construct, arginfo_phalcon_storage_adapter_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Storage_Adapter_Redis, clear, arginfo_phalcon_storage_adapter_redis_clear, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_Storage_Adapter_Redis, getAdapter, arginfo_phalcon_storage_adapter_redis_getadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Redis, getKeys, arginfo_phalcon_storage_adapter_redis_getkeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Redis, setForever, arginfo_phalcon_storage_adapter_redis_setforever, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Redis, doDecrement, arginfo_phalcon_storage_adapter_redis_dodecrement, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Redis, doDelete, arginfo_phalcon_storage_adapter_redis_dodelete, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Redis, doDeleteMultiple, arginfo_phalcon_storage_adapter_redis_dodeletemultiple, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Redis, doHas, arginfo_phalcon_storage_adapter_redis_dohas, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Redis, doIncrement, arginfo_phalcon_storage_adapter_redis_doincrement, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Redis, doSet, arginfo_phalcon_storage_adapter_redis_doset, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Redis, checkAuth, arginfo_phalcon_storage_adapter_redis_checkauth, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Storage_Adapter_Redis, checkConnect, arginfo_phalcon_storage_adapter_redis_checkconnect, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Storage_Adapter_Redis, checkIndex, arginfo_phalcon_storage_adapter_redis_checkindex, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Storage_Adapter_Redis, setSerializer, arginfo_phalcon_storage_adapter_redis_setserializer, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
