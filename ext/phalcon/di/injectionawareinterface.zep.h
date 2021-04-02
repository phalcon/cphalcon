
extern zend_class_entry *phalcon_di_injectionawareinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_InjectionAwareInterface);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_di_injectionawareinterface_setdi, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, container, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_di_injectionawareinterface_getdi, 0, 0, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_injectionawareinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Di_InjectionAwareInterface, setDI, arginfo_phalcon_di_injectionawareinterface_setdi)
	PHP_ABSTRACT_ME(Phalcon_Di_InjectionAwareInterface, getDI, arginfo_phalcon_di_injectionawareinterface_getdi)
	PHP_FE_END
};
