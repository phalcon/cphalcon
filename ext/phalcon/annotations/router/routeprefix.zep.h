
extern zend_class_entry *phalcon_annotations_router_routeprefix_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Router_RoutePrefix);

PHP_METHOD(Phalcon_Annotations_Router_RoutePrefix, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_router_routeprefix___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_router_routeprefix_method_entry) {
	PHP_ME(Phalcon_Annotations_Router_RoutePrefix, __construct, arginfo_phalcon_annotations_router_routeprefix___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
