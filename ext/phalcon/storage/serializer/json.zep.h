
extern zend_class_entry *phalcon_storage_serializer_json_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Json);

PHP_METHOD(Phalcon_Storage_Serializer_Json, serialize);
PHP_METHOD(Phalcon_Storage_Serializer_Json, unserialize);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_json_serialize, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_json_serialize, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_json_unserialize, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_json_unserialize, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_serializer_json_unserialize, 0, 0, 1)
#define arginfo_phalcon_storage_serializer_json_unserialize NULL
#endif

	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_serializer_json_method_entry) {
	PHP_ME(Phalcon_Storage_Serializer_Json, serialize, arginfo_phalcon_storage_serializer_json_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Serializer_Json, unserialize, arginfo_phalcon_storage_serializer_json_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
