
extern zend_class_entry *phalcon_storage_serializerfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Storage_SerializerFactory);

PHP_METHOD(Phalcon_Storage_SerializerFactory, __construct);
PHP_METHOD(Phalcon_Storage_SerializerFactory, newInstance);
PHP_METHOD(Phalcon_Storage_SerializerFactory, getExceptionClass);
PHP_METHOD(Phalcon_Storage_SerializerFactory, getServices);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_storage_serializerfactory___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, services, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_storage_serializerfactory_newinstance, 0, 1, Phalcon\\Storage\\Serializer\\SerializerInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializerfactory_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_storage_serializerfactory_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_storage_serializerfactory_method_entry) {
	PHP_ME(Phalcon_Storage_SerializerFactory, __construct, arginfo_phalcon_storage_serializerfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Storage_SerializerFactory, newInstance, arginfo_phalcon_storage_serializerfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Storage_SerializerFactory, getExceptionClass, arginfo_phalcon_storage_serializerfactory_getexceptionclass, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Storage_SerializerFactory, getServices, arginfo_phalcon_storage_serializerfactory_getservices, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
