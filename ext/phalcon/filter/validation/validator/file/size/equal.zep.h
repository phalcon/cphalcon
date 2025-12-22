
extern zend_class_entry *phalcon_filter_validation_validator_file_size_equal_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_File_Size_Equal);

PHP_METHOD(Phalcon_Filter_Validation_Validator_File_Size_Equal, validate);
PHP_METHOD(Phalcon_Filter_Validation_Validator_File_Size_Equal, getConditional);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_validator_file_size_equal_validate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Filter\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_validator_file_size_equal_getconditional, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, source, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, target, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, included, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_validation_validator_file_size_equal_method_entry) {
	PHP_ME(Phalcon_Filter_Validation_Validator_File_Size_Equal, validate, arginfo_phalcon_filter_validation_validator_file_size_equal_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation_Validator_File_Size_Equal, getConditional, arginfo_phalcon_filter_validation_validator_file_size_equal_getconditional, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
