
extern zend_class_entry *phalcon_storage_serializer_json_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Json);

PHP_METHOD(Phalcon_Storage_Serializer_Json, serialize);
PHP_METHOD(Phalcon_Storage_Serializer_Json, unserialize);
PHP_METHOD(Phalcon_Storage_Serializer_Json, getDecode);
PHP_METHOD(Phalcon_Storage_Serializer_Json, getEncode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_serializer_json_serialize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_json_unserialize, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_serializer_json_getdecode, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, associative, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_json_getencode, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_serializer_json_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Storage_Serializer_Json, serialize, arginfo_phalcon_storage_serializer_json_serialize, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Storage_Serializer_Json, serialize, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Storage_Serializer_Json, unserialize, arginfo_phalcon_storage_serializer_json_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Serializer_Json, getDecode, arginfo_phalcon_storage_serializer_json_getdecode, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Storage_Serializer_Json, getEncode, arginfo_phalcon_storage_serializer_json_getencode, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
