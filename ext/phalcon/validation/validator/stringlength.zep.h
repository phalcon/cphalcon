
extern zend_class_entry *phalcon_validation_validator_stringlength_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_StringLength);

PHP_METHOD(Phalcon_Validation_Validator_StringLength, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_stringlength___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_stringlength_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_StringLength, __construct, arginfo_phalcon_validation_validator_stringlength___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
