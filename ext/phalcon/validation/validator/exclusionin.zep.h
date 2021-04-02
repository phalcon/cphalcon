
extern zend_class_entry *phalcon_validation_validator_exclusionin_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_ExclusionIn);

PHP_METHOD(Phalcon_Validation_Validator_ExclusionIn, __construct);
PHP_METHOD(Phalcon_Validation_Validator_ExclusionIn, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_exclusionin___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_exclusionin_validate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_exclusionin_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_ExclusionIn, __construct, arginfo_phalcon_validation_validator_exclusionin___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Validation_Validator_ExclusionIn, validate, arginfo_phalcon_validation_validator_exclusionin_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
