
extern zend_class_entry *phalcon_validation_validator_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator);

PHP_METHOD(Phalcon_Validation_Validator, __construct);
PHP_METHOD(Phalcon_Validation_Validator, isSetOption);
PHP_METHOD(Phalcon_Validation_Validator, hasOption);
PHP_METHOD(Phalcon_Validation_Validator, getOption);
PHP_METHOD(Phalcon_Validation_Validator, setOption);
PHP_METHOD(Phalcon_Validation_Validator, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_issetoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_hasoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_method_entry) {
	PHP_ME(Phalcon_Validation_Validator, __construct, arginfo_phalcon_validation_validator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Validation_Validator, isSetOption, arginfo_phalcon_validation_validator_issetoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator, hasOption, arginfo_phalcon_validation_validator_hasoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator, getOption, arginfo_phalcon_validation_validator_getoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator, setOption, arginfo_phalcon_validation_validator_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_Validator, validate, arginfo_phalcon_validation_validator_validate, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
