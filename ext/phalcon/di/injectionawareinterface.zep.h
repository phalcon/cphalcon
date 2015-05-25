
extern zend_class_entry *phalcon_di_injectionawareinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Di_InjectionAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_di_injectionawareinterface_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_di_injectionawareinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Di_InjectionAwareInterface, setDI, arginfo_phalcon_di_injectionawareinterface_setdi)
	PHP_ABSTRACT_ME(Phalcon_Di_InjectionAwareInterface, getDI, NULL)
	PHP_FE_END
};
