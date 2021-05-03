
extern zend_class_entry *phalcon_validation_validator_numericality_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Numericality);

PHP_METHOD(Phalcon_Validation_Validator_Numericality, __construct);
PHP_METHOD(Phalcon_Validation_Validator_Numericality, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_numericality___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_numericality_validate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_numericality_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Numericality, __construct, arginfo_phalcon_validation_validator_numericality___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Validation_Validator_Numericality, validate, arginfo_phalcon_validation_validator_numericality_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
