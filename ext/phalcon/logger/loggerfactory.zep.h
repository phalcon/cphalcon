
extern zend_class_entry *phalcon_logger_loggerfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_LoggerFactory);

PHP_METHOD(Phalcon_Logger_LoggerFactory, newInstance);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_loggerfactory_newinstance, 0, 1, Phalcon\\Logger\\Logger, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_loggerfactory_newinstance, 0, 1, IS_OBJECT, "Phalcon\\Logger\\Logger", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_ARRAY_INFO(0, adapters, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_loggerfactory_method_entry) {
	PHP_ME(Phalcon_Logger_LoggerFactory, newInstance, arginfo_phalcon_logger_loggerfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
