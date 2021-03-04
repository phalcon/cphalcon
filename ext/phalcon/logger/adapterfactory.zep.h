
extern zend_class_entry *phalcon_logger_adapterfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_AdapterFactory);

PHP_METHOD(Phalcon_Logger_AdapterFactory, __construct);
PHP_METHOD(Phalcon_Logger_AdapterFactory, newInstance);
PHP_METHOD(Phalcon_Logger_AdapterFactory, getAdapters);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterfactory___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, services, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapterfactory_newinstance, 0, 2, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, fileName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapterfactory_getadapters, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapterfactory_method_entry) {
	PHP_ME(Phalcon_Logger_AdapterFactory, __construct, arginfo_phalcon_logger_adapterfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_AdapterFactory, newInstance, arginfo_phalcon_logger_adapterfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_AdapterFactory, getAdapters, arginfo_phalcon_logger_adapterfactory_getadapters, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
