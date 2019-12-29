
extern zend_class_entry *phalcon_validation_validator_url_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Url);

PHP_METHOD(Phalcon_Validation_Validator_Url, __construct);
PHP_METHOD(Phalcon_Validation_Validator_Url, validate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validator_url___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_url_validate, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_validator_url_validate, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_validator_url_method_entry) {
	PHP_ME(Phalcon_Validation_Validator_Url, __construct, arginfo_phalcon_validation_validator_url___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Validation_Validator_Url, validate, arginfo_phalcon_validation_validator_url_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
