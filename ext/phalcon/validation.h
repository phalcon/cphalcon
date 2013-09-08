
extern zend_class_entry *phalcon_validation_ce;

ZEPHIR_INIT_CLASS(Phalcon_Validation);

PHP_METHOD(Phalcon_Validation, __construct);
PHP_METHOD(Phalcon_Validation, validate);
PHP_METHOD(Phalcon_Validation, add);
PHP_METHOD(Phalcon_Validation, setFilters);
PHP_METHOD(Phalcon_Validation, getFilters);
PHP_METHOD(Phalcon_Validation, getValidators);
PHP_METHOD(Phalcon_Validation, getEntity);
PHP_METHOD(Phalcon_Validation, getMessages);
PHP_METHOD(Phalcon_Validation, appendMessage);
PHP_METHOD(Phalcon_Validation, bind);
PHP_METHOD(Phalcon_Validation, getValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, validators)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_validate, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, entity)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_add, 0, 0, 0)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, validator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_setfilters, 0, 0, 0)
	ZEND_ARG_INFO(0, attribute)
	ZEND_ARG_INFO(0, filters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_getfilters, 0, 0, 0)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_appendmessage, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_bind, 0, 0, 0)
	ZEND_ARG_INFO(0, entity)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_validation_getvalue, 0, 0, 0)
	ZEND_ARG_INFO(0, attribute)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_validation_method_entry) {
	PHP_ME(Phalcon_Validation, __construct, arginfo_phalcon_validation___construct, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, validate, arginfo_phalcon_validation_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, add, arginfo_phalcon_validation_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, setFilters, arginfo_phalcon_validation_setfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getFilters, arginfo_phalcon_validation_getfilters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getValidators, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getEntity, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, appendMessage, arginfo_phalcon_validation_appendmessage, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, bind, arginfo_phalcon_validation_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Validation, getValue, arginfo_phalcon_validation_getvalue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
