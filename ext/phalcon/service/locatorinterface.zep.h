
extern zend_class_entry *phalcon_service_locatorinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Service_LocatorInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_service_locatorinterface_get, 0, 1, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_service_locatorinterface_get, 0, 1, IS_OBJECT, "NULL", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_service_locatorinterface_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_service_locatorinterface_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_service_locatorinterface_set, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, helper)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_service_locatorinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Service_LocatorInterface, get, arginfo_phalcon_service_locatorinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Service_LocatorInterface, has, arginfo_phalcon_service_locatorinterface_has)
	PHP_ABSTRACT_ME(Phalcon_Service_LocatorInterface, set, arginfo_phalcon_service_locatorinterface_set)
	PHP_FE_END
};
