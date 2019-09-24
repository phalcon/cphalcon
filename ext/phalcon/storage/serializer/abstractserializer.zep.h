
extern zend_class_entry *phalcon_storage_serializer_abstractserializer_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_Serializer_AbstractSerializer);

PHP_METHOD(Phalcon_Storage_Serializer_AbstractSerializer, __construct);
PHP_METHOD(Phalcon_Storage_Serializer_AbstractSerializer, isSerializable);
PHP_METHOD(Phalcon_Storage_Serializer_AbstractSerializer, getData);
PHP_METHOD(Phalcon_Storage_Serializer_AbstractSerializer, setData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_serializer_abstractserializer___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_abstractserializer_isserializable, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_abstractserializer_isserializable, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_abstractserializer_setdata, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializer_abstractserializer_setdata, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_serializer_abstractserializer_setdata, 0, 0, 1)
#define arginfo_phalcon_storage_serializer_abstractserializer_setdata NULL
#endif

	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_serializer_abstractserializer_method_entry) {
	PHP_ME(Phalcon_Storage_Serializer_AbstractSerializer, __construct, arginfo_phalcon_storage_serializer_abstractserializer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Storage_Serializer_AbstractSerializer, isSerializable, arginfo_phalcon_storage_serializer_abstractserializer_isserializable, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_Serializer_AbstractSerializer, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_Serializer_AbstractSerializer, setData, arginfo_phalcon_storage_serializer_abstractserializer_setdata, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
