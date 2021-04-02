
extern zend_class_entry *phalcon_storage_serializer_msgpack_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Msgpack);

PHP_METHOD(Phalcon_Storage_Serializer_Msgpack, serialize);
PHP_METHOD(Phalcon_Storage_Serializer_Msgpack, unserialize);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_msgpack_serialize, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_msgpack_unserialize, 0, 1, IS_VOID, 0)

	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_serializer_msgpack_method_entry) {
	PHP_ME(Phalcon_Storage_Serializer_Msgpack, serialize, arginfo_phalcon_storage_serializer_msgpack_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Serializer_Msgpack, unserialize, arginfo_phalcon_storage_serializer_msgpack_unserialize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
