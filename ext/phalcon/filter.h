
extern zend_class_entry *phalcon_filter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter);

PHP_METHOD(Phalcon_Filter, add);
PHP_METHOD(Phalcon_Filter, sanitize);
PHP_METHOD(Phalcon_Filter, _sanitize);
PHP_METHOD(Phalcon_Filter, getFilters);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_add, 0, 0, 2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_sanitize, 0, 0, 2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter__sanitize, 0, 0, 2)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_method_entry) {
	PHP_ME(Phalcon_Filter, add, arginfo_phalcon_filter_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter, sanitize, arginfo_phalcon_filter_sanitize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter, _sanitize, arginfo_phalcon_filter__sanitize, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Filter, getFilters, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
