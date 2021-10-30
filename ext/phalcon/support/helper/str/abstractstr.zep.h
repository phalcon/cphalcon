
extern zend_class_entry *phalcon_support_helper_str_abstractstr_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Str_AbstractStr);

PHP_METHOD(Phalcon_Support_Helper_Str_AbstractStr, toEndsWith);
PHP_METHOD(Phalcon_Support_Helper_Str_AbstractStr, toInterpolate);
PHP_METHOD(Phalcon_Support_Helper_Str_AbstractStr, toLower);
PHP_METHOD(Phalcon_Support_Helper_Str_AbstractStr, toStartsWith);
PHP_METHOD(Phalcon_Support_Helper_Str_AbstractStr, toUpper);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_abstractstr_toendswith, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, haystack, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, needle, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, ignoreCase, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_abstractstr_tointerpolate, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, left, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, right, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_abstractstr_tolower, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, encoding, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_abstractstr_tostartswith, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, haystack, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, needle, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, ignoreCase, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_str_abstractstr_toupper, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, encoding, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_str_abstractstr_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Str_AbstractStr, toEndsWith, arginfo_phalcon_support_helper_str_abstractstr_toendswith, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_Helper_Str_AbstractStr, toInterpolate, arginfo_phalcon_support_helper_str_abstractstr_tointerpolate, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_Helper_Str_AbstractStr, toLower, arginfo_phalcon_support_helper_str_abstractstr_tolower, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_Helper_Str_AbstractStr, toStartsWith, arginfo_phalcon_support_helper_str_abstractstr_tostartswith, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Support_Helper_Str_AbstractStr, toUpper, arginfo_phalcon_support_helper_str_abstractstr_toupper, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
