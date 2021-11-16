
extern zend_class_entry *phalcon_support_helper_str_friendly_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_Friendly);

PHP_METHOD(Phalcon_Support_Helper_Str_Friendly, __invoke);
PHP_METHOD(Phalcon_Support_Helper_Str_Friendly, checkReplace);
PHP_METHOD(Phalcon_Support_Helper_Str_Friendly, getMatrix);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_friendly___invoke, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, separator, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, lowercase, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_friendly_checkreplace, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_friendly_getmatrix, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, replace, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_str_friendly_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Str_Friendly, __invoke, arginfo_phalcon_support_helper_str_friendly___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Support_Helper_Str_Friendly, checkReplace, arginfo_phalcon_support_helper_str_friendly_checkreplace, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Support_Helper_Str_Friendly, getMatrix, arginfo_phalcon_support_helper_str_friendly_getmatrix, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
