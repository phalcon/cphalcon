
extern zend_class_entry *phalcon_datamapper_pdo_connectionlocator_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_ConnectionLocator);

PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, __construct);
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, getMaster);
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, getRead);
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, getWrite);
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, setMaster);
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, setRead);
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, setWrite);
PHP_METHOD(Phalcon_DataMapper_Pdo_ConnectionLocator, getConnection);
zend_object *zephir_init_properties_Phalcon_DataMapper_Pdo_ConnectionLocator(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocator___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, master, Phalcon\\DataMapper\\Pdo\\Connection\\ConnectionInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, read, 0)
	ZEND_ARG_ARRAY_INFO(0, write, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocator_getmaster, 0, 0, Phalcon\\DataMapper\\Pdo\\Connection\\ConnectionInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocator_getmaster, 0, 0, IS_OBJECT, "Phalcon\\DataMapper\\Pdo\\Connection\\ConnectionInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocator_getread, 0, 0, Phalcon\\DataMapper\\Pdo\\Connection\\ConnectionInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocator_getread, 0, 0, IS_OBJECT, "Phalcon\\DataMapper\\Pdo\\Connection\\ConnectionInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocator_getwrite, 0, 0, Phalcon\\DataMapper\\Pdo\\Connection\\ConnectionInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocator_getwrite, 0, 0, IS_OBJECT, "Phalcon\\DataMapper\\Pdo\\Connection\\ConnectionInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocator_setmaster, 0, 1, Phalcon\\DataMapper\\Pdo\\ConnectionLocatorInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocator_setmaster, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Pdo\\ConnectionLocatorInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, callableObject, Phalcon\\DataMapper\\Pdo\\Connection\\ConnectionInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocator_setread, 0, 2, Phalcon\\DataMapper\\Pdo\\ConnectionLocatorInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocator_setread, 0, 2, IS_OBJECT, "Phalcon\\DataMapper\\Pdo\\ConnectionLocatorInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, callableObject)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocator_setwrite, 0, 2, Phalcon\\DataMapper\\Pdo\\ConnectionLocatorInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocator_setwrite, 0, 2, IS_OBJECT, "Phalcon\\DataMapper\\Pdo\\ConnectionLocatorInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, callableObject)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocator_getconnection, 0, 1, Phalcon\\DataMapper\\Pdo\\Connection\\ConnectionInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocator_getconnection, 0, 1, IS_OBJECT, "Phalcon\\DataMapper\\Pdo\\Connection\\ConnectionInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, type)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_pdo_connectionlocator_method_entry) {
	PHP_ME(Phalcon_DataMapper_Pdo_ConnectionLocator, __construct, arginfo_phalcon_datamapper_pdo_connectionlocator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_DataMapper_Pdo_ConnectionLocator, getMaster, arginfo_phalcon_datamapper_pdo_connectionlocator_getmaster, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_ConnectionLocator, getRead, arginfo_phalcon_datamapper_pdo_connectionlocator_getread, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_ConnectionLocator, getWrite, arginfo_phalcon_datamapper_pdo_connectionlocator_getwrite, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_ConnectionLocator, setMaster, arginfo_phalcon_datamapper_pdo_connectionlocator_setmaster, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_ConnectionLocator, setRead, arginfo_phalcon_datamapper_pdo_connectionlocator_setread, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_ConnectionLocator, setWrite, arginfo_phalcon_datamapper_pdo_connectionlocator_setwrite, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_DataMapper_Pdo_ConnectionLocator, getConnection, arginfo_phalcon_datamapper_pdo_connectionlocator_getconnection, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
