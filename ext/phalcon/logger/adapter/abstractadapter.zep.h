
extern zend_class_entry *phalcon_logger_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, __destruct);
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, add);
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, begin);
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, commit);
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, getFormatter);
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, inTransaction);
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, process);
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, rollback);
PHP_METHOD(Phalcon_Logger_Adapter_AbstractAdapter, setFormatter);
zend_object *zephir_init_properties_Phalcon_Logger_Adapter_AbstractAdapter(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_abstractadapter___destruct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapter_abstractadapter_add, 0, 1, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Logger\\Item, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapter_abstractadapter_begin, 0, 0, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapter_abstractadapter_commit, 0, 0, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapter_abstractadapter_getformatter, 0, 0, Phalcon\\Logger\\Formatter\\FormatterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_abstractadapter_intransaction, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_abstractadapter_process, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Logger\\Item, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapter_abstractadapter_rollback, 0, 0, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapter_abstractadapter_setformatter, 0, 1, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_OBJ_INFO(0, formatter, Phalcon\\Logger\\Formatter\\FormatterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_abstractadapter_zephir_init_properties_phalcon_logger_adapter_abstractadapter, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapter_abstractadapter_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Logger_Adapter_AbstractAdapter, __destruct, arginfo_phalcon_logger_adapter_abstractadapter___destruct, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
#else
	PHP_ME(Phalcon_Logger_Adapter_AbstractAdapter, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
#endif
	PHP_ME(Phalcon_Logger_Adapter_AbstractAdapter, add, arginfo_phalcon_logger_adapter_abstractadapter_add, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_AbstractAdapter, begin, arginfo_phalcon_logger_adapter_abstractadapter_begin, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_AbstractAdapter, commit, arginfo_phalcon_logger_adapter_abstractadapter_commit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_AbstractAdapter, getFormatter, arginfo_phalcon_logger_adapter_abstractadapter_getformatter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_AbstractAdapter, inTransaction, arginfo_phalcon_logger_adapter_abstractadapter_intransaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_AbstractAdapter, process, arginfo_phalcon_logger_adapter_abstractadapter_process, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_AbstractAdapter, rollback, arginfo_phalcon_logger_adapter_abstractadapter_rollback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_Adapter_AbstractAdapter, setFormatter, arginfo_phalcon_logger_adapter_abstractadapter_setformatter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
