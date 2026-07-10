
extern zend_class_entry *phalcon_filter_validation_validator_file_ce;

ZEPHIR_INIT_CLASS(Phalcon_Filter_Validation_Validator_File);

PHP_METHOD(Phalcon_Filter_Validation_Validator_File, __construct);
PHP_METHOD(Phalcon_Filter_Validation_Validator_File, getArrVal);
PHP_METHOD(Phalcon_Filter_Validation_Validator_File, getValidators);
PHP_METHOD(Phalcon_Filter_Validation_Validator_File, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_validator_file___construct, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_filter_validation_validator_file_getarrval, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, cast, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_validator_file_getvalidators, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_filter_validation_validator_file_validate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Filter\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_filter_validation_validator_file_method_entry) {
	PHP_ME(Phalcon_Filter_Validation_Validator_File, __construct, arginfo_phalcon_filter_validation_validator_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Filter_Validation_Validator_File, getArrVal, arginfo_phalcon_filter_validation_validator_file_getarrval, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Filter_Validation_Validator_File, getValidators, arginfo_phalcon_filter_validation_validator_file_getvalidators, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Filter_Validation_Validator_File, validate, arginfo_phalcon_filter_validation_validator_file_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
