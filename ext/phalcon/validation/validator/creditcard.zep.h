
extern zend_class_entry *phalcon_validation_validator_creditcard_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_CreditCard);

PHP_METHOD(Phalcon_Validation_Validator_CreditCard, validate);
PHP_METHOD(Phalcon_Validation_Validator_CreditCard, verifyByLuhnAlgorithm);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_creditcard_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_creditcard_verifybyluhnalgorithm, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_creditcard_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_CreditCard, validate, arginfo_phalcon_validation_validator_creditcard_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator_CreditCard, verifyByLuhnAlgorithm, arginfo_phalcon_validation_validator_creditcard_verifybyluhnalgorithm, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
