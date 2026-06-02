
extern zend_class_entry *phalcon_container_resolver_lazy_env_ce;

ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_Env);

PHP_METHOD(Phalcon_Container_Resolver_Lazy_Env, __construct);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_Env, resolve);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_Env, cast);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_Env, getEnv);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_container_resolver_lazy_env___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, varname, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, vartype, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_lazy_env_resolve, 0, 1, IS_MIXED, 0)
	ZEND_ARG_INFO(0, container)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_lazy_env_cast, 0, 1, IS_MIXED, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_lazy_env_getenv, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_container_resolver_lazy_env_method_entry) {
	PHP_ME(Phalcon_Container_Resolver_Lazy_Env, __construct, arginfo_phalcon_container_resolver_lazy_env___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Container_Resolver_Lazy_Env, resolve, arginfo_phalcon_container_resolver_lazy_env_resolve, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Resolver_Lazy_Env, cast, arginfo_phalcon_container_resolver_lazy_env_cast, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Container_Resolver_Lazy_Env, getEnv, arginfo_phalcon_container_resolver_lazy_env_getenv, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
