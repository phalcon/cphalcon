
extern zend_class_entry *phalcon_support_helper_number_isbetween_ce;

ZEPHIR_INIT_CLASS(Phalcon_Support_Helper_Number_IsBetween);

PHP_METHOD(Phalcon_Support_Helper_Number_IsBetween, __invoke);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_support_helper_number_isbetween___invoke, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, start, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, end, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_support_helper_number_isbetween_method_entry) {
	PHP_ME(Phalcon_Support_Helper_Number_IsBetween, __invoke, arginfo_phalcon_support_helper_number_isbetween___invoke, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
