
extern zend_class_entry *phalcon_container_resolver_lazy_lazy_ce;

ZEPHIR_INIT_CLASS(Phalcon_Container_Resolver_Lazy_Lazy);

PHP_METHOD(Phalcon_Container_Resolver_Lazy_Lazy, __invoke);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_Lazy, resolve);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_Lazy, resolveArgument);
PHP_METHOD(Phalcon_Container_Resolver_Lazy_Lazy, resolveArguments);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazy___invoke, 0, 1, IS_MIXED, 0)
	ZEND_ARG_INFO(0, container)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazy_resolve, 0, 1, IS_MIXED, 0)
	ZEND_ARG_INFO(0, container)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazy_resolveargument, 0, 2, IS_MIXED, 0)
	ZEND_ARG_INFO(0, container)
	ZEND_ARG_INFO(0, argument)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_container_resolver_lazy_lazy_resolvearguments, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, container)
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_container_resolver_lazy_lazy_method_entry) {
	PHP_ME(Phalcon_Container_Resolver_Lazy_Lazy, __invoke, arginfo_phalcon_container_resolver_lazy_lazy___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Resolver_Lazy_Lazy, resolve, arginfo_phalcon_container_resolver_lazy_lazy_resolve, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Container_Resolver_Lazy_Lazy, resolveArgument, arginfo_phalcon_container_resolver_lazy_lazy_resolveargument, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Container_Resolver_Lazy_Lazy, resolveArguments, arginfo_phalcon_container_resolver_lazy_lazy_resolvearguments, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
