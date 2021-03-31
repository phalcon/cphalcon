
extern zend_class_entry *phalcon_logger_adapter_noop_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_Noop);

PHP_METHOD(Phalcon_Logger_Adapter_Noop, close);
PHP_METHOD(Phalcon_Logger_Adapter_Noop, process);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_noop_close, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_noop_process, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Logger\\Item, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapter_noop_method_entry) {
	PHP_ME(Phalcon_Logger_Adapter_Noop, close, arginfo_phalcon_logger_adapter_noop_close, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_Noop, process, arginfo_phalcon_logger_adapter_noop_process, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
