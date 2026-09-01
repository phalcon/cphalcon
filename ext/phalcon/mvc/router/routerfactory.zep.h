
extern zend_class_entry *phalcon_mvc_router_routerfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_RouterFactory);

PHP_METHOD(Phalcon_Mvc_Router_RouterFactory, load);
PHP_METHOD(Phalcon_Mvc_Router_RouterFactory, newInstance);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_routerfactory_load, 0, 1, Phalcon\\Mvc\\RouterInterface, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_router_routerfactory_newinstance, 0, 0, Phalcon\\Mvc\\RouterInterface, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, defaultRoutes, _IS_BOOL, 0, "true")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_router_routerfactory_method_entry) {
	PHP_ME(Phalcon_Mvc_Router_RouterFactory, load, arginfo_phalcon_mvc_router_routerfactory_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Router_RouterFactory, newInstance, arginfo_phalcon_mvc_router_routerfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
