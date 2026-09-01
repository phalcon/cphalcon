
extern zend_class_entry *phalcon_logger_exceptions_adapternotfound_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Exceptions_AdapterNotFound);

PHP_METHOD(Phalcon_Logger_Exceptions_AdapterNotFound, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_exceptions_adapternotfound___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_exceptions_adapternotfound_method_entry) {
	PHP_ME(Phalcon_Logger_Exceptions_AdapterNotFound, __construct, arginfo_phalcon_logger_exceptions_adapternotfound___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
