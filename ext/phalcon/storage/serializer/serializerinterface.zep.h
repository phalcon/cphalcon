
extern zend_class_entry *phalcon_storage_serializer_serializerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_SerializerInterface);

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_serializerinterface_setdata, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_serializerinterface_setdata, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_serializer_serializerinterface_setdata, 0, 0, 1)
#define arginfo_phalcon_storage_serializer_serializerinterface_setdata NULL
#endif

	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_serializer_serializerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Storage_Serializer_SerializerInterface, getData, NULL)
	PHP_ABSTRACT_ME(Phalcon_Storage_Serializer_SerializerInterface, setData, arginfo_phalcon_storage_serializer_serializerinterface_setdata)
	PHP_FE_END
};
