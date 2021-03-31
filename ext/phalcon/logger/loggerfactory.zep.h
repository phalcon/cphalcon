
extern zend_class_entry *phalcon_logger_loggerfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_LoggerFactory);

PHP_METHOD(Phalcon_Logger_LoggerFactory, __construct);
PHP_METHOD(Phalcon_Logger_LoggerFactory, load);
PHP_METHOD(Phalcon_Logger_LoggerFactory, newInstance);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_loggerfactory___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Logger\\AdapterFactory, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_loggerfactory_load, 0, 1, Phalcon\\Logger, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_loggerfactory_newinstance, 0, 1, Phalcon\\Logger, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, adapters, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_loggerfactory_method_entry) {
	PHP_ME(Phalcon_Logger_LoggerFactory, __construct, arginfo_phalcon_logger_loggerfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_LoggerFactory, load, arginfo_phalcon_logger_loggerfactory_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_LoggerFactory, newInstance, arginfo_phalcon_logger_loggerfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
