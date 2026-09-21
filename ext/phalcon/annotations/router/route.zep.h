
extern zend_class_entry *phalcon_annotations_router_route_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Router_Route);

PHP_METHOD(Phalcon_Annotations_Router_Route, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_annotations_router_route___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, route, IS_STRING, 0)
	ZEND_ARG_INFO(0, methods)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, name, IS_STRING, 1, "null")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, paths, IS_ARRAY, 0, "[]")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, converters, IS_ARRAY, 0, "[]")
	ZEND_ARG_INFO(0, beforeMatch)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_annotations_router_route_method_entry) {
	PHP_ME(Phalcon_Annotations_Router_Route, __construct, arginfo_phalcon_annotations_router_route___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
