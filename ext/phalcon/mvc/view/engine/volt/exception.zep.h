
extern zend_class_entry *phalcon_mvc_view_engine_volt_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Exception);

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Exception, __construct);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Exception, getStatement);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_exception___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, code)
#endif
	ZEND_ARG_OBJ_INFO(0, previous, Exception, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_exception_getstatement, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_exception_getstatement, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_volt_exception_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Exception, __construct, arginfo_phalcon_mvc_view_engine_volt_exception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Exception, getStatement, arginfo_phalcon_mvc_view_engine_volt_exception_getstatement, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
