
extern zend_class_entry *phalcon_filterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_FilterInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_filterinterface_add, 0, 2, Phalcon\\FilterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filterinterface_add, 0, 2, IS_OBJECT, "Phalcon\\FilterInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filterinterface_sanitize, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filterinterface_getfilters, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filterinterface_getfilters, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_FilterInterface, add, arginfo_phalcon_filterinterface_add)
	PHP_ABSTRACT_ME(Phalcon_FilterInterface, sanitize, arginfo_phalcon_filterinterface_sanitize)
	PHP_ABSTRACT_ME(Phalcon_FilterInterface, getFilters, arginfo_phalcon_filterinterface_getfilters)
	PHP_FE_END
};
