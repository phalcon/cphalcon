
extern zend_class_entry *phalcon_filter_validation_validator_files_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_Files);

PHP_METHOD(Phalcon_Filter_Validation_Validator_Files, isAllowEmpty);
PHP_METHOD(Phalcon_Filter_Validation_Validator_Files, validate);
PHP_METHOD(Phalcon_Filter_Validation_Validator_Files, normalizeFiles);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_validator_files_isallowempty, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Filter\\Validation, 0)
	ZEND_ARG_TYPE_INFO(0, field, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_validator_files_validate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Filter\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_validator_files_normalizefiles, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_validation_validator_files_method_entry) {
	PHP_ME(Phalcon_Filter_Validation_Validator_Files, isAllowEmpty, arginfo_phalcon_filter_validation_validator_files_isallowempty, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation_Validator_Files, validate, arginfo_phalcon_filter_validation_validator_files_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation_Validator_Files, normalizeFiles, arginfo_phalcon_filter_validation_validator_files_normalizefiles, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
