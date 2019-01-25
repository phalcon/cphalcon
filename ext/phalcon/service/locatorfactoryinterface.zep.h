
extern zend_class_entry *phalcon_service_locatorfactoryinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Service_LocatorFactoryInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_service_locatorfactoryinterface_newinstance, 0, 0, Phalcon\\Service\\LocatorInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_service_locatorfactoryinterface_newinstance, 0, 0, IS_OBJECT, "Phalcon\\Service\\LocatorInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_service_locatorfactoryinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Service_LocatorFactoryInterface, newInstance, arginfo_phalcon_service_locatorfactoryinterface_newinstance)
	PHP_FE_END
};
