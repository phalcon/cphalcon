
extern zend_class_entry *phalcon_logger_adapter_blackhole_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Blackhole);

PHP_METHOD(Phalcon_Logger_Adapter_Blackhole, getFormatter);
PHP_METHOD(Phalcon_Logger_Adapter_Blackhole, logInternal);
PHP_METHOD(Phalcon_Logger_Adapter_Blackhole, close);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_blackhole_loginternal, 0, 0, 4)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapter_blackhole_method_entry) {
	PHP_ME(Phalcon_Logger_Adapter_Blackhole, getFormatter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Blackhole, logInternal, arginfo_phalcon_logger_adapter_blackhole_loginternal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Blackhole, close, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
