
extern zend_class_entry *phalcon_logger_loggerfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_LoggerFactory);

PHP_METHOD(Phalcon_Logger_LoggerFactory, __construct);
PHP_METHOD(Phalcon_Logger_LoggerFactory, load);
PHP_METHOD(Phalcon_Logger_LoggerFactory, newInstance);
PHP_METHOD(Phalcon_Logger_LoggerFactory, getArrVal);
PHP_METHOD(Phalcon_Logger_LoggerFactory, getExceptionClass);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_loggerfactory___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Logger\\AdapterFactory, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_loggerfactory_load, 0, 1, Phalcon\\Logger\\Logger, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_loggerfactory_newinstance, 0, 1, Phalcon\\Logger\\Logger, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, adapters, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, adapters, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, timezone, DateTimeZone, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_loggerfactory_getarrval, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, collection, 0)
	ZEND_ARG_INFO(0, index)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_loggerfactory_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_loggerfactory_method_entry) {
	PHP_ME(Phalcon_Logger_LoggerFactory, __construct, arginfo_phalcon_logger_loggerfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_LoggerFactory, load, arginfo_phalcon_logger_loggerfactory_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_LoggerFactory, newInstance, arginfo_phalcon_logger_loggerfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_LoggerFactory, getArrVal, arginfo_phalcon_logger_loggerfactory_getarrval, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Logger_LoggerFactory, getExceptionClass, arginfo_phalcon_logger_loggerfactory_getexceptionclass, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
