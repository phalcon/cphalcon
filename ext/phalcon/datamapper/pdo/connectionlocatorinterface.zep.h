
extern zend_class_entry *phalcon_datamapper_pdo_connectionlocatorinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_ConnectionLocatorInterface);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocatorinterface_getmaster, 0, 0, Phalcon\\DataMapper\\Pdo\\Connection\\ConnectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocatorinterface_getread, 0, 0, Phalcon\\DataMapper\\Pdo\\Connection\\ConnectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocatorinterface_getwrite, 0, 0, Phalcon\\DataMapper\\Pdo\\Connection\\ConnectionInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocatorinterface_setmaster, 0, 1, Phalcon\\DataMapper\\Pdo\\ConnectionLocatorInterface, 0)
	ZEND_ARG_OBJ_INFO(0, callableObject, Phalcon\\DataMapper\\Pdo\\Connection\\ConnectionInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocatorinterface_setread, 0, 2, Phalcon\\DataMapper\\Pdo\\ConnectionLocatorInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, callableObject)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_datamapper_pdo_connectionlocatorinterface_setwrite, 0, 2, Phalcon\\DataMapper\\Pdo\\ConnectionLocatorInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, callableObject)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_datamapper_pdo_connectionlocatorinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_ConnectionLocatorInterface, getMaster, arginfo_phalcon_datamapper_pdo_connectionlocatorinterface_getmaster)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_ConnectionLocatorInterface, getRead, arginfo_phalcon_datamapper_pdo_connectionlocatorinterface_getread)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_ConnectionLocatorInterface, getWrite, arginfo_phalcon_datamapper_pdo_connectionlocatorinterface_getwrite)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_ConnectionLocatorInterface, setMaster, arginfo_phalcon_datamapper_pdo_connectionlocatorinterface_setmaster)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_ConnectionLocatorInterface, setRead, arginfo_phalcon_datamapper_pdo_connectionlocatorinterface_setread)
	PHP_ABSTRACT_ME(Phalcon_DataMapper_Pdo_ConnectionLocatorInterface, setWrite, arginfo_phalcon_datamapper_pdo_connectionlocatorinterface_setwrite)
	PHP_FE_END
};
