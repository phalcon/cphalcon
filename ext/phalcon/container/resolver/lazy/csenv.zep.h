
extern zend_class_entry *phalcon_container_resolver_lazy_csenv_ce;

ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_CsEnv);

PHP_METHOD(Phalcon_Container_Resolver_Lazy_CsEnv, resolve);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_lazy_csenv_resolve, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, ioc)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_container_resolver_lazy_csenv_method_entry) {
	PHP_ME(Phalcon_Container_Resolver_Lazy_CsEnv, resolve, arginfo_phalcon_container_resolver_lazy_csenv_resolve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
