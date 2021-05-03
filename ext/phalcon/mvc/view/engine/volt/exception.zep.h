
extern zend_class_entry *phalcon_mvc_view_engine_volt_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Exception);

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Exception, __construct);
PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Exception, getStatement);
zend_object *zephir_init_properties_Phalcon_Mvc_View_Engine_Volt_Exception(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_exception___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, statement, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, previous, Exception, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_exception_getstatement, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_exception_zephir_init_properties_phalcon_mvc_view_engine_volt_exception, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_volt_exception_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Exception, __construct, arginfo_phalcon_mvc_view_engine_volt_exception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Exception, getStatement, arginfo_phalcon_mvc_view_engine_volt_exception_getstatement, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
