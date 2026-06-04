
extern zend_class_entry *phalcon_logger_adapter_exceptions_fileopenfailed_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Exceptions_FileOpenFailed);

PHP_METHOD(Phalcon_Logger_Adapter_Exceptions_FileOpenFailed, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_exceptions_fileopenfailed___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapter_exceptions_fileopenfailed_method_entry) {
	PHP_ME(Phalcon_Logger_Adapter_Exceptions_FileOpenFailed, __construct, arginfo_phalcon_logger_adapter_exceptions_fileopenfailed___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
