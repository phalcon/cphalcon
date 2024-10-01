
extern zend_class_entry *phalcon_filter_validation_validator_file_size_min_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_File_Size_Min);

PHP_METHOD(Phalcon_Filter_Validation_Validator_File_Size_Min, getConditional);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_validator_file_size_min_getconditional, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, source, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, target, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, included, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_validation_validator_file_size_min_method_entry) {
	PHP_ME(Phalcon_Filter_Validation_Validator_File_Size_Min, getConditional, arginfo_phalcon_filter_validation_validator_file_size_min_getconditional, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
