
extern zend_class_entry *phalcon_di_serviceproviderinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_ServiceProviderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_serviceproviderinterface_register, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_serviceproviderinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Di_ServiceProviderInterface, register, arginfo_phalcon_di_serviceproviderinterface_register)
	PHP_FE_END
};
