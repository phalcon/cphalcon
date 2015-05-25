
extern zend_class_entry *phalcon_mvc_model_validator_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Validator);

PHP_METHOD(Phalcon_Mvc_Model_Validator, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Validator, appendMessage);
PHP_METHOD(Phalcon_Mvc_Model_Validator, getMessages);
PHP_METHOD(Phalcon_Mvc_Model_Validator, getOptions);
PHP_METHOD(Phalcon_Mvc_Model_Validator, getOption);
PHP_METHOD(Phalcon_Mvc_Model_Validator, isSetOption);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_appendmessage, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_getoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validator_issetoption, 0, 0, 1)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validator_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Validator, __construct, arginfo_phalcon_mvc_model_validator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Validator, appendMessage, arginfo_phalcon_mvc_model_validator_appendmessage, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Validator, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Validator, getOptions, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Validator, getOption, arginfo_phalcon_mvc_model_validator_getoption, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Validator, isSetOption, arginfo_phalcon_mvc_model_validator_issetoption, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
