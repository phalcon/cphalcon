
extern zend_class_entry *phalcon_utils_slug_ce;

ZEPHIR_INIT_CLASS(Phalcon_Utils_Slug);

PHP_METHOD(Phalcon_Utils_Slug, generate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_utils_slug_generate, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_ARRAY_INFO(0, replace, 1)
	ZEND_ARG_INFO(0, delimiter)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_utils_slug_method_entry) {
	PHP_ME(Phalcon_Utils_Slug, generate, arginfo_phalcon_utils_slug_generate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
