
extern zend_class_entry *phalcon_mvc_model_validationfailed_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_ValidationFailed);

PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, __construct);
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getMessages);
PHP_METHOD(Phalcon_Mvc_Model_ValidationFailed, getModel);
zend_object *zephir_init_properties_Phalcon_Mvc_Model_ValidationFailed(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_validationfailed___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\ModelInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, validationMessages, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_validationfailed_getmessages, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_validationfailed_getmessages, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_mvc_model_validationfailed_getmodel, 0, 0, Phalcon\\Mvc\\ModelInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_validationfailed_getmodel, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\ModelInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_validationfailed_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_ValidationFailed, __construct, arginfo_phalcon_mvc_model_validationfailed___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_ValidationFailed, getMessages, arginfo_phalcon_mvc_model_validationfailed_getmessages, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_ValidationFailed, getModel, arginfo_phalcon_mvc_model_validationfailed_getmodel, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
