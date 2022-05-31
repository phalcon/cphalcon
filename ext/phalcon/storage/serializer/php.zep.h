
extern zend_class_entry *phalcon_storage_serializer_php_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Php);

PHP_METHOD(Phalcon_Storage_Serializer_Php, serialize);
PHP_METHOD(Phalcon_Storage_Serializer_Php, unserialize);
PHP_METHOD(Phalcon_Storage_Serializer_Php, phpUnserialize);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_php_serialize, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_php_unserialize, 0, 1, IS_VOID, 0)
    ZEND_ARG_TYPE_INFO(0, serialized, IS_STRING, 0)
ZEND_END_ARG_INFO()
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_php_unserialize, 0, 1, IS_VOID, 0)
    ZEND_ARG_INFO(0, serialized)
ZEND_END_ARG_INFO()
#endif

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_php_phpunserialize, 0, 1, IS_MIXED, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_php_phpunserialize, 0, 1, IS_NULL, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_serializer_php_method_entry) {
	PHP_ME(Phalcon_Storage_Serializer_Php, serialize, arginfo_phalcon_storage_serializer_php_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Serializer_Php, unserialize, arginfo_phalcon_storage_serializer_php_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Serializer_Php, phpUnserialize, arginfo_phalcon_storage_serializer_php_phpunserialize, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
