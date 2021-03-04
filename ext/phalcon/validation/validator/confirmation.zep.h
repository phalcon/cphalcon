
extern zend_class_entry *phalcon_validation_validator_confirmation_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Confirmation);

PHP_METHOD(Phalcon_Validation_Validator_Confirmation, __construct);
PHP_METHOD(Phalcon_Validation_Validator_Confirmation, validate);
PHP_METHOD(Phalcon_Validation_Validator_Confirmation, compare);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_confirmation___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_confirmation_validate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_confirmation_compare, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, a, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, b, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_confirmation_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Confirmation, __construct, arginfo_phalcon_validation_validator_confirmation___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Validation_Validator_Confirmation, validate, arginfo_phalcon_validation_validator_confirmation_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator_Confirmation, compare, arginfo_phalcon_validation_validator_confirmation_compare, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_FE_END
};
