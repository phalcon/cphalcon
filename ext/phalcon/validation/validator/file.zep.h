
extern zend_class_entry *phalcon_validation_validator_file_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_File);

PHP_METHOD(Phalcon_Validation_Validator_File, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_file_validate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_file_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_File, validate, arginfo_phalcon_validation_validator_file_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
