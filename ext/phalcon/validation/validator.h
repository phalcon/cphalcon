
extern zend_class_entry *phalcon_validation_validator_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator);

PHP_METHOD(Phalcon_Validation_Validator, getOptions);
PHP_METHOD(Phalcon_Validation_Validator, setOptions);
PHP_METHOD(Phalcon_Validation_Validator, __construct);
PHP_METHOD(Phalcon_Validation_Validator, isSetOption);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_setoptions, 0, 0, 1)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_issetoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_method_entry) {
	PHP_ME(Phalcon_Validation_Validator, getOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator, setOptions, arginfo_phalcon_validation_validator_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator, __construct, arginfo_phalcon_validation_validator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Validation_Validator, isSetOption, arginfo_phalcon_validation_validator_issetoption, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
