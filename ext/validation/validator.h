
extern zend_class_entry *phalcon_validation_validator_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator);

PHP_METHOD(Phalcon_Validation_Validator, __construct);
PHP_METHOD(Phalcon_Validation_Validator, isSetOption);
PHP_METHOD(Phalcon_Validation_Validator, getOption);
PHP_METHOD(Phalcon_Validation_Validator, setOption);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_isSetOption, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_getOption, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_setOption, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_method_entry) {
	PHP_ME(Phalcon_Validation_Validator, __construct, arginfo_phalcon_validation_validator___construct, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator, isSetOption, arginfo_phalcon_validation_validator_isSetOption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator, getOption, arginfo_phalcon_validation_validator_getOption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator, setOption, arginfo_phalcon_validation_validator_setOption, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
