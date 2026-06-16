
extern zend_class_entry *phalcon_contracts_logger_adapter_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Logger_Adapter_Adapter);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_logger_adapter_adapter_add, 0, 1, Phalcon\\Contracts\\Logger\\Adapter\\Adapter, 0)
	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Logger\\Item, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_logger_adapter_adapter_begin, 0, 0, Phalcon\\Contracts\\Logger\\Adapter\\Adapter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_adapter_adapter_close, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_logger_adapter_adapter_commit, 0, 0, Phalcon\\Contracts\\Logger\\Adapter\\Adapter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_logger_adapter_adapter_getformatter, 0, 0, Phalcon\\Logger\\Formatter\\FormatterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_adapter_adapter_intransaction, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_logger_adapter_adapter_process, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Logger\\Item, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_logger_adapter_adapter_rollback, 0, 0, Phalcon\\Contracts\\Logger\\Adapter\\Adapter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_logger_adapter_adapter_setformatter, 0, 1, Phalcon\\Contracts\\Logger\\Adapter\\Adapter, 0)
	ZEND_ARG_OBJ_INFO(0, formatter, Phalcon\\Logger\\Formatter\\FormatterInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_logger_adapter_adapter_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Adapter_Adapter, add, arginfo_phalcon_contracts_logger_adapter_adapter_add)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Adapter_Adapter, begin, arginfo_phalcon_contracts_logger_adapter_adapter_begin)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Adapter_Adapter, close, arginfo_phalcon_contracts_logger_adapter_adapter_close)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Adapter_Adapter, commit, arginfo_phalcon_contracts_logger_adapter_adapter_commit)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Adapter_Adapter, getFormatter, arginfo_phalcon_contracts_logger_adapter_adapter_getformatter)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Adapter_Adapter, inTransaction, arginfo_phalcon_contracts_logger_adapter_adapter_intransaction)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Adapter_Adapter, process, arginfo_phalcon_contracts_logger_adapter_adapter_process)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Adapter_Adapter, rollback, arginfo_phalcon_contracts_logger_adapter_adapter_rollback)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Logger_Adapter_Adapter, setFormatter, arginfo_phalcon_contracts_logger_adapter_adapter_setformatter)
	PHP_FE_END
};
