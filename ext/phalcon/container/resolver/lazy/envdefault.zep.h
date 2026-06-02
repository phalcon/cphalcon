
extern zend_class_entry *phalcon_container_resolver_lazy_envdefault_ce;

ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_EnvDefault);

PHP_METHOD(Phalcon_Container_Resolver_Lazy_EnvDefault, __construct);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_EnvDefault, resolve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_container_resolver_lazy_envdefault___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, varname, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, vartype, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_lazy_envdefault_resolve, 0, 1, IS_MIXED, 0)
	ZEND_ARG_INFO(0, ioc)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_container_resolver_lazy_envdefault_method_entry) {
	PHP_ME(Phalcon_Container_Resolver_Lazy_EnvDefault, __construct, arginfo_phalcon_container_resolver_lazy_envdefault___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Container_Resolver_Lazy_EnvDefault, resolve, arginfo_phalcon_container_resolver_lazy_envdefault_resolve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
