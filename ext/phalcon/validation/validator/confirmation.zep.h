
extern zend_class_entry *phalcon_validation_validator_confirmation_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Confirmation);

PHP_METHOD(Phalcon_Validation_Validator_Confirmation, validate);
PHP_METHOD(Phalcon_Validation_Validator_Confirmation, compare);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_confirmation_validate, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_confirmation_validate, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_confirmation_compare, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_confirmation_compare, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, a, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, a)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, b, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, b)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_confirmation_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Confirmation, validate, arginfo_phalcon_validation_validator_confirmation_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator_Confirmation, compare, arginfo_phalcon_validation_validator_confirmation_compare, ZEND_ACC_PROTECTED|ZEND_ACC_FINAL)
	PHP_FE_END
};
