
extern zend_class_entry *phalcon_validation_validator_uniqueness_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Uniqueness);

PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, validate);
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, isUniqueness);
PHP_METHOD(Phalcon_Validation_Validator_Uniqueness, getColumnNameReal);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_uniqueness_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_uniqueness_isuniqueness, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_uniqueness_getcolumnnamereal, 0, 0, 2)
	ZEND_ARG_INFO(0, record)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_uniqueness_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Uniqueness, validate, arginfo_phalcon_validation_validator_uniqueness_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator_Uniqueness, isUniqueness, arginfo_phalcon_validation_validator_uniqueness_isuniqueness, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Validation_Validator_Uniqueness, getColumnNameReal, arginfo_phalcon_validation_validator_uniqueness_getcolumnnamereal, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
