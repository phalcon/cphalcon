
extern zend_class_entry *phalcon_container_resolver_lazy_getcall_ce;

ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_GetCall);

PHP_METHOD(Phalcon_Container_Resolver_Lazy_GetCall, __construct);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_GetCall, resolve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_container_resolver_lazy_getcall___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_lazy_getcall_resolve, 0, 1, IS_MIXED, 0)
	ZEND_ARG_INFO(0, container)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_container_resolver_lazy_getcall_method_entry) {
	PHP_ME(Phalcon_Container_Resolver_Lazy_GetCall, __construct, arginfo_phalcon_container_resolver_lazy_getcall___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Container_Resolver_Lazy_GetCall, resolve, arginfo_phalcon_container_resolver_lazy_getcall_resolve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
