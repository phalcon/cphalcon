
extern zend_class_entry *phalcon_storage_serializer_base64_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Base64);

PHP_METHOD(Phalcon_Storage_Serializer_Base64, serialize);
PHP_METHOD(Phalcon_Storage_Serializer_Base64, unserialize);
PHP_METHOD(Phalcon_Storage_Serializer_Base64, phpBase64Decode);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_base64_serialize, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_base64_unserialize, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, serialized, IS_STRING, 0)
ZEND_END_ARG_INFO()
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_base64_unserialize, 0, 1, IS_VOID, 0)
    ZEND_ARG_INFO(0, serialized)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_serializer_base64_phpbase64decode, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, strict, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_serializer_base64_method_entry) {
	PHP_ME(Phalcon_Storage_Serializer_Base64, serialize, arginfo_phalcon_storage_serializer_base64_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Serializer_Base64, unserialize, arginfo_phalcon_storage_serializer_base64_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Serializer_Base64, phpBase64Decode, arginfo_phalcon_storage_serializer_base64_phpbase64decode, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
