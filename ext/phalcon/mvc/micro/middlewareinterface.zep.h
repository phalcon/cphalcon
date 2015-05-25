
extern zend_class_entry *phalcon_mvc_micro_middlewareinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_MiddlewareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_middlewareinterface_call, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, application, Phalcon\\Mvc\\Micro, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_micro_middlewareinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Micro_MiddlewareInterface, call, arginfo_phalcon_mvc_micro_middlewareinterface_call)
	PHP_FE_END
};
