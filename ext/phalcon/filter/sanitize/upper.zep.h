
extern zend_class_entry *phalcon_filter_sanitize_upper_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Sanitize_Upper);

PHP_METHOD(Phalcon_Filter_Sanitize_Upper, __invoke);
PHP_METHOD(Phalcon_Filter_Sanitize_Upper, phpExtensionLoaded);
PHP_METHOD(Phalcon_Filter_Sanitize_Upper, phpFunctionExists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_sanitize_upper___invoke, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_sanitize_upper_phpextensionloaded, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_sanitize_upper_phpfunctionexists, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, functionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_sanitize_upper_method_entry) {
	PHP_ME(Phalcon_Filter_Sanitize_Upper, __invoke, arginfo_phalcon_filter_sanitize_upper___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Sanitize_Upper, phpExtensionLoaded, arginfo_phalcon_filter_sanitize_upper_phpextensionloaded, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Filter_Sanitize_Upper, phpFunctionExists, arginfo_phalcon_filter_sanitize_upper_phpfunctionexists, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
