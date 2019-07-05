
extern zend_class_entry *phalcon_validation_abstractvalidatorcomposite_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation_AbstractValidatorComposite);

PHP_METHOD(Phalcon_Validation_AbstractValidatorComposite, getValidators);
PHP_METHOD(Phalcon_Validation_AbstractValidatorComposite, validate);
zend_object *zephir_init_properties_Phalcon_Validation_AbstractValidatorComposite(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_abstractvalidatorcomposite_getvalidators, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_abstractvalidatorcomposite_getvalidators, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_abstractvalidatorcomposite_validate, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_validation_abstractvalidatorcomposite_validate, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, validation, Phalcon\\Validation, 0)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_abstractvalidatorcomposite_method_entry) {
	PHP_ME(Phalcon_Validation_AbstractValidatorComposite, getValidators, arginfo_phalcon_validation_abstractvalidatorcomposite_getvalidators, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation_AbstractValidatorComposite, validate, arginfo_phalcon_validation_abstractvalidatorcomposite_validate, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
