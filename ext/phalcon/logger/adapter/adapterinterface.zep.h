
extern zend_class_entry *phalcon_logger_adapter_adapterinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Adapter_AdapterInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_add, 0, 1, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_add, 0, 1, IS_OBJECT, "Phalcon\\Logger\\Adapter\\AdapterInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Logger\\Item, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_begin, 0, 0, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_begin, 0, 0, IS_OBJECT, "Phalcon\\Logger\\Adapter\\AdapterInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_close, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_close, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_commit, 0, 0, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_commit, 0, 0, IS_OBJECT, "Phalcon\\Logger\\Adapter\\AdapterInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_getformatter, 0, 0, Phalcon\\Logger\\Formatter\\FormatterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_getformatter, 0, 0, IS_OBJECT, "Phalcon\\Logger\\Formatter\\FormatterInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_intransaction, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_intransaction, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_process, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_process, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_process, 0, 0, 1)
#define arginfo_phalcon_logger_adapter_adapterinterface_process NULL
#endif

	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Logger\\Item, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_rollback, 0, 0, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_rollback, 0, 0, IS_OBJECT, "Phalcon\\Logger\\Adapter\\AdapterInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_setformatter, 0, 1, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapter_adapterinterface_setformatter, 0, 1, IS_OBJECT, "Phalcon\\Logger\\Adapter\\AdapterInterface", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, formatter, Phalcon\\Logger\\Formatter\\FormatterInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapter_adapterinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Logger_Adapter_AdapterInterface, add, arginfo_phalcon_logger_adapter_adapterinterface_add)
	PHP_ABSTRACT_ME(Phalcon_Logger_Adapter_AdapterInterface, begin, arginfo_phalcon_logger_adapter_adapterinterface_begin)
	PHP_ABSTRACT_ME(Phalcon_Logger_Adapter_AdapterInterface, close, arginfo_phalcon_logger_adapter_adapterinterface_close)
	PHP_ABSTRACT_ME(Phalcon_Logger_Adapter_AdapterInterface, commit, arginfo_phalcon_logger_adapter_adapterinterface_commit)
	PHP_ABSTRACT_ME(Phalcon_Logger_Adapter_AdapterInterface, getFormatter, arginfo_phalcon_logger_adapter_adapterinterface_getformatter)
	PHP_ABSTRACT_ME(Phalcon_Logger_Adapter_AdapterInterface, inTransaction, arginfo_phalcon_logger_adapter_adapterinterface_intransaction)
	PHP_ABSTRACT_ME(Phalcon_Logger_Adapter_AdapterInterface, process, arginfo_phalcon_logger_adapter_adapterinterface_process)
	PHP_ABSTRACT_ME(Phalcon_Logger_Adapter_AdapterInterface, rollback, arginfo_phalcon_logger_adapter_adapterinterface_rollback)
	PHP_ABSTRACT_ME(Phalcon_Logger_Adapter_AdapterInterface, setFormatter, arginfo_phalcon_logger_adapter_adapterinterface_setformatter)
	PHP_FE_END
};
