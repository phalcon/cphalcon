
extern zend_class_entry *phalcon_storage_serializer_php_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Php);

PHP_METHOD(Phalcon_Storage_Serializer_Php, serialize);
PHP_METHOD(Phalcon_Storage_Serializer_Php, unserialize);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_php_serialize, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_php_serialize, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_php_unserialize, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_php_unserialize, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_serializer_php_unserialize, 0, 0, 1)
#define arginfo_phalcon_storage_serializer_php_unserialize NULL
#endif

	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_serializer_php_method_entry) {
	PHP_ME(Phalcon_Storage_Serializer_Php, serialize, arginfo_phalcon_storage_serializer_php_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Serializer_Php, unserialize, arginfo_phalcon_storage_serializer_php_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
