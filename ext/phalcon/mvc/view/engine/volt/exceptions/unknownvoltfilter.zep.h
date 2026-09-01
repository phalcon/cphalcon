
extern zend_class_entry *phalcon_mvc_view_engine_volt_exceptions_unknownvoltfilter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Exceptions_UnknownVoltFilter);

PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Exceptions_UnknownVoltFilter, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_exceptions_unknownvoltfilter___construct, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, line, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_volt_exceptions_unknownvoltfilter_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Exceptions_UnknownVoltFilter, __construct, arginfo_phalcon_mvc_view_engine_volt_exceptions_unknownvoltfilter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
