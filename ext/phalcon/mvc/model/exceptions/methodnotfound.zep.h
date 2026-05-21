
extern zend_class_entry *phalcon_mvc_model_exceptions_methodnotfound_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Exceptions_MethodNotFound);

PHP_METHOD(Phalcon_Mvc_Model_Exceptions_MethodNotFound, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_exceptions_methodnotfound___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modelName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_exceptions_methodnotfound_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_Exceptions_MethodNotFound, __construct, arginfo_phalcon_mvc_model_exceptions_methodnotfound___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
