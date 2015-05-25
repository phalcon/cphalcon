
extern zend_class_entry *phalcon_mvc_model_validationfailed_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ValidationFailed);

PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, __construct);
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getModel);
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getMessages);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validationfailed___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
	ZEND_ARG_ARRAY_INFO(0, validationMessages, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validationfailed_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_ValidationFailed, __construct, arginfo_phalcon_mvc_model_validationfailed___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_ValidationFailed, getModel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_ValidationFailed, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
