
extern zend_class_entry *phalcon_adr_router_routermatch_ce;

ZEPHIR_INIT_CLASS(Phalcon_ADR_Router_RouterMatch);

PHP_METHOD(Phalcon_ADR_Router_RouterMatch, __construct);
PHP_METHOD(Phalcon_ADR_Router_RouterMatch, getAction);
PHP_METHOD(Phalcon_ADR_Router_RouterMatch, getAttributes);
PHP_METHOD(Phalcon_ADR_Router_RouterMatch, getMiddleware);
PHP_METHOD(Phalcon_ADR_Router_RouterMatch, getName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_adr_router_routermatch___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, action, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, attributes, IS_ARRAY, 0, "[]")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, middleware, IS_ARRAY, 0, "[]")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, name, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_routermatch_getaction, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_routermatch_getattributes, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_routermatch_getmiddleware, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_adr_router_routermatch_getname, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_adr_router_routermatch_method_entry) {
	PHP_ME(Phalcon_ADR_Router_RouterMatch, __construct, arginfo_phalcon_adr_router_routermatch___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_ADR_Router_RouterMatch, getAction, arginfo_phalcon_adr_router_routermatch_getaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_RouterMatch, getAttributes, arginfo_phalcon_adr_router_routermatch_getattributes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_RouterMatch, getMiddleware, arginfo_phalcon_adr_router_routermatch_getmiddleware, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_ADR_Router_RouterMatch, getName, arginfo_phalcon_adr_router_routermatch_getname, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
