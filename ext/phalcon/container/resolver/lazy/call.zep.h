
extern zend_class_entry *phalcon_container_resolver_lazy_call_ce;

ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_Call);

PHP_METHOD(Phalcon_Container_Resolver_Lazy_Call, __construct);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_Call, resolve);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_container_resolver_lazy_call___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, callableObject)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_lazy_call_resolve, 0, 1, IS_MIXED, 0)
	ZEND_ARG_INFO(0, ioc)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_container_resolver_lazy_call_method_entry) {
	PHP_ME(Phalcon_Container_Resolver_Lazy_Call, __construct, arginfo_phalcon_container_resolver_lazy_call___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Container_Resolver_Lazy_Call, resolve, arginfo_phalcon_container_resolver_lazy_call_resolve, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
