
extern zend_class_entry *phalcon_logger_adapter_file_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_File);

PHP_METHOD(Phalcon_Logger_Adapter_File, getPath);
PHP_METHOD(Phalcon_Logger_Adapter_File, __construct);
PHP_METHOD(Phalcon_Logger_Adapter_File, getFormatter);
PHP_METHOD(Phalcon_Logger_Adapter_File, logInternal);
PHP_METHOD(Phalcon_Logger_Adapter_File, close);
PHP_METHOD(Phalcon_Logger_Adapter_File, __wakeup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_file_loginternal, 0, 0, 4)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapter_file_method_entry) {
	PHP_ME(Phalcon_Logger_Adapter_File, getPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_File, __construct, arginfo_phalcon_logger_adapter_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_Adapter_File, getFormatter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_File, logInternal, arginfo_phalcon_logger_adapter_file_loginternal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_File, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_File, __wakeup, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
