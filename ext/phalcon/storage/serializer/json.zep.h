
extern zend_class_entry *phalcon_storage_serializer_json_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Json);

PHP_METHOD(Phalcon_Storage_Serializer_Json, __construct);
PHP_METHOD(Phalcon_Storage_Serializer_Json, serialize);
PHP_METHOD(Phalcon_Storage_Serializer_Json, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_serializer_json___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_serializer_json_serialize, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_json_unserialize, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, serialized, IS_STRING, 0)
ZEND_END_ARG_INFO()
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_json_unserialize, 0, 1, IS_VOID, 0)
    ZEND_ARG_INFO(0, serialized)
ZEND_END_ARG_INFO()
#endif

ZEPHIR_INIT_FUNCS(phalcon_storage_serializer_json_method_entry) {
	PHP_ME(Phalcon_Storage_Serializer_Json, __construct, arginfo_phalcon_storage_serializer_json___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Storage_Serializer_Json, serialize, arginfo_phalcon_storage_serializer_json_serialize, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Storage_Serializer_Json, serialize, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Storage_Serializer_Json, unserialize, arginfo_phalcon_storage_serializer_json_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
