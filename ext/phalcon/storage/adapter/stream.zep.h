
extern zend_class_entry *phalcon_storage_adapter_stream_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Adapter_Stream);

PHP_METHOD(Phalcon_Storage_Adapter_Stream, __construct);
PHP_METHOD(Phalcon_Storage_Adapter_Stream, clear);
PHP_METHOD(Phalcon_Storage_Adapter_Stream, decrement);
PHP_METHOD(Phalcon_Storage_Adapter_Stream, delete);
PHP_METHOD(Phalcon_Storage_Adapter_Stream, get);
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getAdapter);
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getKeys);
PHP_METHOD(Phalcon_Storage_Adapter_Stream, has);
PHP_METHOD(Phalcon_Storage_Adapter_Stream, increment);
PHP_METHOD(Phalcon_Storage_Adapter_Stream, set);
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getDir);
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getFilepath);
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getIterator);
PHP_METHOD(Phalcon_Storage_Adapter_Stream, getPayload);
PHP_METHOD(Phalcon_Storage_Adapter_Stream, isExpired);
zend_object *zephir_init_properties_Phalcon_Storage_Adapter_Stream(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_stream___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Storage\\SerializerFactory, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_clear, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_clear, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_stream_decrement, 0, 0, 1)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_delete, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_delete, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_stream_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_getkeys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_getkeys, 0, 0, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, prefix)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_adapter_stream_increment, 0, 0, 1)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_set, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_set, 0, 2, _IS_BOOL, NULL, 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_getdir, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_getdir, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_getfilepath, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_getfilepath, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_storage_adapter_stream_getiterator, 0, 1, Iterator, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_getiterator, 0, 1, IS_OBJECT, "Iterator", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, dir, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, dir)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_getpayload, 0, 1, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_getpayload, 0, 1, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filepath, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filepath)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_isexpired, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_adapter_stream_isexpired, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, payload, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_adapter_stream_method_entry) {
	PHP_ME(Phalcon_Storage_Adapter_Stream, __construct, arginfo_phalcon_storage_adapter_stream___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Storage_Adapter_Stream, clear, arginfo_phalcon_storage_adapter_stream_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Stream, decrement, arginfo_phalcon_storage_adapter_stream_decrement, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Stream, delete, arginfo_phalcon_storage_adapter_stream_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Stream, get, arginfo_phalcon_storage_adapter_stream_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Stream, getAdapter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Stream, getKeys, arginfo_phalcon_storage_adapter_stream_getkeys, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Stream, has, arginfo_phalcon_storage_adapter_stream_has, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Stream, increment, arginfo_phalcon_storage_adapter_stream_increment, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Stream, set, arginfo_phalcon_storage_adapter_stream_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Adapter_Stream, getDir, arginfo_phalcon_storage_adapter_stream_getdir, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Storage_Adapter_Stream, getFilepath, arginfo_phalcon_storage_adapter_stream_getfilepath, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Storage_Adapter_Stream, getIterator, arginfo_phalcon_storage_adapter_stream_getiterator, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Storage_Adapter_Stream, getPayload, arginfo_phalcon_storage_adapter_stream_getpayload, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Storage_Adapter_Stream, isExpired, arginfo_phalcon_storage_adapter_stream_isexpired, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
