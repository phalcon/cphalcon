
extern zend_class_entry *phalcon_validation_validator_creditcard_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_CreditCard);

PHP_METHOD(Phalcon_Validation_Validator_CreditCard, validate);
PHP_METHOD(Phalcon_Validation_Validator_CreditCard, verifyByLuhnAlgorithm);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_creditcard_validate, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_creditcard_validate, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_creditcard_verifybyluhnalgorithm, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_creditcard_verifybyluhnalgorithm, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, number, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, number)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_creditcard_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_CreditCard, validate, arginfo_phalcon_validation_validator_creditcard_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator_CreditCard, verifyByLuhnAlgorithm, arginfo_phalcon_validation_validator_creditcard_verifybyluhnalgorithm, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
