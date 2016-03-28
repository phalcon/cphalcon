
extern zend_class_entry *phalcon_validation_validator_date_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Date);

PHP_METHOD(Phalcon_Validation_Validator_Date, validate);
PHP_METHOD(Phalcon_Validation_Validator_Date, checkDate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_date_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_date_checkdate, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, format)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_date_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Date, validate, arginfo_phalcon_validation_validator_date_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator_Date, checkDate, arginfo_phalcon_validation_validator_date_checkdate, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
