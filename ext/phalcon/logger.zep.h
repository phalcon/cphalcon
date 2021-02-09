
extern zend_class_entry *phalcon_logger_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger);

PHP_METHOD(Phalcon_Logger, getLogLevel);
PHP_METHOD(Phalcon_Logger, __construct);
PHP_METHOD(Phalcon_Logger, addAdapter);
PHP_METHOD(Phalcon_Logger, alert);
PHP_METHOD(Phalcon_Logger, critical);
PHP_METHOD(Phalcon_Logger, debug);
PHP_METHOD(Phalcon_Logger, error);
PHP_METHOD(Phalcon_Logger, emergency);
PHP_METHOD(Phalcon_Logger, excludeAdapters);
PHP_METHOD(Phalcon_Logger, getAdapter);
PHP_METHOD(Phalcon_Logger, getAdapters);
PHP_METHOD(Phalcon_Logger, getName);
PHP_METHOD(Phalcon_Logger, info);
PHP_METHOD(Phalcon_Logger, log);
PHP_METHOD(Phalcon_Logger, notice);
PHP_METHOD(Phalcon_Logger, removeAdapter);
PHP_METHOD(Phalcon_Logger, setAdapters);
PHP_METHOD(Phalcon_Logger, setLogLevel);
PHP_METHOD(Phalcon_Logger, warning);
PHP_METHOD(Phalcon_Logger, addMessage);
PHP_METHOD(Phalcon_Logger, getLevels);
PHP_METHOD(Phalcon_Logger, getLevelNumber);
zend_object *zephir_init_properties_Phalcon_Logger(zend_class_entry *class_type);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_getloglevel, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_getloglevel, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, adapters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_addadapter, 0, 2, Phalcon\\Logger, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_addadapter, 0, 2, IS_OBJECT, "Phalcon\\Logger", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_OBJ_INFO(0, adapter, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_alert, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_alert, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_alert, 0, 0, 1)
#define arginfo_phalcon_logger_alert NULL
#endif

	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_critical, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_critical, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_critical, 0, 0, 1)
#define arginfo_phalcon_logger_critical NULL
#endif

	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_debug, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_debug, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_debug, 0, 0, 1)
#define arginfo_phalcon_logger_debug NULL
#endif

	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_error, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_error, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_error, 0, 0, 1)
#define arginfo_phalcon_logger_error NULL
#endif

	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_emergency, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_emergency, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_emergency, 0, 0, 1)
#define arginfo_phalcon_logger_emergency NULL
#endif

	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_excludeadapters, 0, 0, Phalcon\\Logger, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_excludeadapters, 0, 0, IS_OBJECT, "Phalcon\\Logger", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, adapters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_getadapter, 0, 1, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_getadapter, 0, 1, IS_OBJECT, "Phalcon\\Logger\\Adapter\\AdapterInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_getadapters, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_getadapters, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_info, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_info, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_info, 0, 0, 1)
#define arginfo_phalcon_logger_info NULL
#endif

	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_log, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_log, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_log, 0, 0, 2)
#define arginfo_phalcon_logger_log NULL
#endif

	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_notice, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_notice, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_notice, 0, 0, 1)
#define arginfo_phalcon_logger_notice NULL
#endif

	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_removeadapter, 0, 1, Phalcon\\Logger, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_removeadapter, 0, 1, IS_OBJECT, "Phalcon\\Logger", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_setadapters, 0, 1, Phalcon\\Logger, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_setadapters, 0, 1, IS_OBJECT, "Phalcon\\Logger", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, adapters, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_setloglevel, 0, 1, Phalcon\\Logger, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_setloglevel, 0, 1, IS_OBJECT, "Phalcon\\Logger", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, level)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_warning, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_warning, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_warning, 0, 0, 1)
#define arginfo_phalcon_logger_warning NULL
#endif

	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_addmessage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_addmessage, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, level)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_getlevels, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_getlevels, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_getlevelnumber, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_getlevelnumber, 0, 1, IS_LONG, NULL, 0)
#endif
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_zephir_init_properties_phalcon_logger, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_method_entry) {
	PHP_ME(Phalcon_Logger, getLogLevel, arginfo_phalcon_logger_getloglevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, __construct, arginfo_phalcon_logger___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger, addAdapter, arginfo_phalcon_logger_addadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, alert, arginfo_phalcon_logger_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, critical, arginfo_phalcon_logger_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, debug, arginfo_phalcon_logger_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, error, arginfo_phalcon_logger_error, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, emergency, arginfo_phalcon_logger_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, excludeAdapters, arginfo_phalcon_logger_excludeadapters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, getAdapter, arginfo_phalcon_logger_getadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, getAdapters, arginfo_phalcon_logger_getadapters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, getName, arginfo_phalcon_logger_getname, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, info, arginfo_phalcon_logger_info, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, log, arginfo_phalcon_logger_log, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, notice, arginfo_phalcon_logger_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, removeAdapter, arginfo_phalcon_logger_removeadapter, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, setAdapters, arginfo_phalcon_logger_setadapters, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, setLogLevel, arginfo_phalcon_logger_setloglevel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, warning, arginfo_phalcon_logger_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger, addMessage, arginfo_phalcon_logger_addmessage, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Logger, getLevels, arginfo_phalcon_logger_getlevels, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Logger, getLevelNumber, arginfo_phalcon_logger_getlevelnumber, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
