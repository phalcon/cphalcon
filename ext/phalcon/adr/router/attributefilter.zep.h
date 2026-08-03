
extern zend_class_entry *phalcon_adr_router_attributefilter_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Router_AttributeFilter);

PHP_METHOD(Phalcon_ADR_Router_AttributeFilter, filter);
PHP_METHOD(Phalcon_ADR_Router_AttributeFilter, cast);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_attributefilter_filter, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, actionClass, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, attributes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_adr_router_attributefilter_cast, 0, 2, MAY_BE_DOUBLE|MAY_BE_LONG|MAY_BE_STRING)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_router_attributefilter_method_entry) {
	PHP_ME(Phalcon_ADR_Router_AttributeFilter, filter, arginfo_phalcon_adr_router_attributefilter_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_AttributeFilter, cast, arginfo_phalcon_adr_router_attributefilter_cast, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
