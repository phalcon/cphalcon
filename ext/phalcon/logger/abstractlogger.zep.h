
extern zend_class_entry *phalcon_logger_abstractlogger_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_AbstractLogger);

PHP_METHOD(Phalcon_Logger_AbstractLogger, __construct);
PHP_METHOD(Phalcon_Logger_AbstractLogger, addAdapter);
PHP_METHOD(Phalcon_Logger_AbstractLogger, excludeAdapters);
PHP_METHOD(Phalcon_Logger_AbstractLogger, getAdapter);
PHP_METHOD(Phalcon_Logger_AbstractLogger, getAdapters);
PHP_METHOD(Phalcon_Logger_AbstractLogger, getLogLevel);
PHP_METHOD(Phalcon_Logger_AbstractLogger, getName);
PHP_METHOD(Phalcon_Logger_AbstractLogger, removeAdapter);
PHP_METHOD(Phalcon_Logger_AbstractLogger, setAdapters);
PHP_METHOD(Phalcon_Logger_AbstractLogger, setLogLevel);
PHP_METHOD(Phalcon_Logger_AbstractLogger, addMessage);
PHP_METHOD(Phalcon_Logger_AbstractLogger, getLevelNumber);
PHP_METHOD(Phalcon_Logger_AbstractLogger, getLevels);
zend_object *zephir_init_properties_Phalcon_Logger_AbstractLogger(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_abstractlogger___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, adapters, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, adapters, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, timezone, DateTimeZone, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_abstractlogger_addadapter, 0, 2, Phalcon\\Logger\\AbstractLogger, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, adapter, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_abstractlogger_excludeadapters, 0, 0, Phalcon\\Logger\\AbstractLogger, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, adapters, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, adapters, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_abstractlogger_getadapter, 0, 1, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_abstractlogger_getadapters, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_abstractlogger_getloglevel, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_abstractlogger_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_abstractlogger_removeadapter, 0, 1, Phalcon\\Logger\\AbstractLogger, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_abstractlogger_setadapters, 0, 1, Phalcon\\Logger\\AbstractLogger, 0)
	ZEND_ARG_ARRAY_INFO(0, adapters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_abstractlogger_setloglevel, 0, 1, Phalcon\\Logger\\AbstractLogger, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_abstractlogger_addmessage, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_abstractlogger_getlevelnumber, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_abstractlogger_getlevels, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_abstractlogger_zephir_init_properties_phalcon_logger_abstractlogger, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_abstractlogger_method_entry) {
	PHP_ME(Phalcon_Logger_AbstractLogger, __construct, arginfo_phalcon_logger_abstractlogger___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_AbstractLogger, addAdapter, arginfo_phalcon_logger_abstractlogger_addadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_AbstractLogger, excludeAdapters, arginfo_phalcon_logger_abstractlogger_excludeadapters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_AbstractLogger, getAdapter, arginfo_phalcon_logger_abstractlogger_getadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_AbstractLogger, getAdapters, arginfo_phalcon_logger_abstractlogger_getadapters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_AbstractLogger, getLogLevel, arginfo_phalcon_logger_abstractlogger_getloglevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_AbstractLogger, getName, arginfo_phalcon_logger_abstractlogger_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_AbstractLogger, removeAdapter, arginfo_phalcon_logger_abstractlogger_removeadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_AbstractLogger, setAdapters, arginfo_phalcon_logger_abstractlogger_setadapters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_AbstractLogger, setLogLevel, arginfo_phalcon_logger_abstractlogger_setloglevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_AbstractLogger, addMessage, arginfo_phalcon_logger_abstractlogger_addmessage, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Logger_AbstractLogger, getLevelNumber, arginfo_phalcon_logger_abstractlogger_getlevelnumber, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Logger_AbstractLogger, getLevels, arginfo_phalcon_logger_abstractlogger_getlevels, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
