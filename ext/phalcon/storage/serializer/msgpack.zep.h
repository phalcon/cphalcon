
extern zend_class_entry *phalcon_storage_serializer_msgpack_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_Msgpack);

PHP_METHOD(Phalcon_Storage_Serializer_Msgpack, doSerialize);
PHP_METHOD(Phalcon_Storage_Serializer_Msgpack, doUnserialize);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_msgpack_doserialize, 0, 1, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_serializer_msgpack_dounserialize, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_serializer_msgpack_method_entry) {
	PHP_ME(Phalcon_Storage_Serializer_Msgpack, doSerialize, arginfo_phalcon_storage_serializer_msgpack_doserialize, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Serializer_Msgpack, doUnserialize, arginfo_phalcon_storage_serializer_msgpack_dounserialize, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
