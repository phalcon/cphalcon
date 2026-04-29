
extern zend_class_entry *phalcon_storage_adapter_libmemcached_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Libmemcached);

PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, __construct);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, clear);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, getAdapter);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, getKeys);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, setForever);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, doDecrement);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, doDelete);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, doDeleteMultiple);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, doHas);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, doIncrement);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, doSet);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, setOptions);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, setSasl);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, setSerializer);
PHP_METHOD(Phalcon_Storage_Adapter_Libmemcached, setServers);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Storage\\SerializerFactory, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_clear, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_getadapter, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_getkeys, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, prefix, IS_STRING, 0, "''")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_setforever, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_dodecrement, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, value, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_dodelete, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_dodeletemultiple, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_dohas, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_doincrement, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, value, IS_LONG, 0, "1")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_doset, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_setoptions, 0, 2, Phalcon\\Storage\\Adapter\\Libmemcached, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Memcached, 0)
	ZEND_ARG_ARRAY_INFO(0, client, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_setsasl, 0, 3, Phalcon\\Storage\\Adapter\\Libmemcached, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Memcached, 0)
	ZEND_ARG_TYPE_INFO(0, saslUser, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, saslPass, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_setserializer, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, connection, Memcached, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_storage_adapter_libmemcached_setservers, 0, 2, Phalcon\\Storage\\Adapter\\Libmemcached, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Memcached, 0)
	ZEND_ARG_ARRAY_INFO(0, servers, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_adapter_libmemcached_method_entry) {
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, __construct, arginfo_phalcon_storage_adapter_libmemcached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, clear, arginfo_phalcon_storage_adapter_libmemcached_clear, ZEND_ACC_PUBLIC)
PHP_ME(Phalcon_Storage_Adapter_Libmemcached, getAdapter, arginfo_phalcon_storage_adapter_libmemcached_getadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, getKeys, arginfo_phalcon_storage_adapter_libmemcached_getkeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, setForever, arginfo_phalcon_storage_adapter_libmemcached_setforever, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, doDecrement, arginfo_phalcon_storage_adapter_libmemcached_dodecrement, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, doDelete, arginfo_phalcon_storage_adapter_libmemcached_dodelete, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, doDeleteMultiple, arginfo_phalcon_storage_adapter_libmemcached_dodeletemultiple, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, doHas, arginfo_phalcon_storage_adapter_libmemcached_dohas, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, doIncrement, arginfo_phalcon_storage_adapter_libmemcached_doincrement, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, doSet, arginfo_phalcon_storage_adapter_libmemcached_doset, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, setOptions, arginfo_phalcon_storage_adapter_libmemcached_setoptions, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, setSasl, arginfo_phalcon_storage_adapter_libmemcached_setsasl, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, setSerializer, arginfo_phalcon_storage_adapter_libmemcached_setserializer, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Storage_Adapter_Libmemcached, setServers, arginfo_phalcon_storage_adapter_libmemcached_setservers, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
