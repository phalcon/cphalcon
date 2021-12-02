
extern zend_class_entry *phalcon_filter_validation_validator_file_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_File);

PHP_METHOD(Phalcon_Filter_Validation_Validator_File, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_validator_file___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_validation_validator_file_method_entry) {
	PHP_ME(Phalcon_Filter_Validation_Validator_File, __construct, arginfo_phalcon_filter_validation_validator_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
