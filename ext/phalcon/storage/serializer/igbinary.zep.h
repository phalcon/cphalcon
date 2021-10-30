
extern zend_class_entry *phalcon_storage_serializer_igbinary_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Igbinary);

PHP_METHOD(Phalcon_Storage_Serializer_Igbinary, serialize);
PHP_METHOD(Phalcon_Storage_Serializer_Igbinary, unserialize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_serializer_igbinary_serialize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_igbinary_unserialize, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_serializer_igbinary_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Storage_Serializer_Igbinary, serialize, arginfo_phalcon_storage_serializer_igbinary_serialize, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Storage_Serializer_Igbinary, serialize, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Storage_Serializer_Igbinary, unserialize, arginfo_phalcon_storage_serializer_igbinary_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
