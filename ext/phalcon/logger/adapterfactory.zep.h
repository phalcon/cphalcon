
extern zend_class_entry *phalcon_logger_adapterfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_AdapterFactory);

PHP_METHOD(Phalcon_Logger_AdapterFactory, __construct);
PHP_METHOD(Phalcon_Logger_AdapterFactory, newInstance);
PHP_METHOD(Phalcon_Logger_AdapterFactory, getExceptionClass);
PHP_METHOD(Phalcon_Logger_AdapterFactory, getServices);
PHP_METHOD(Phalcon_Logger_AdapterFactory, getCachedInstance);
PHP_METHOD(Phalcon_Logger_AdapterFactory, getService);
PHP_METHOD(Phalcon_Logger_AdapterFactory, init);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_adapterfactory___construct, 0, 0, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_adapterfactory_newinstance, 0, 2, Phalcon\\Logger\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, fileName, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapterfactory_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapterfactory_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_logger_adapterfactory_getcachedinstance, 0, 1, MAY_BE_OBJECT)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_VARIADIC_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapterfactory_getservice, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_adapterfactory_init, 0, 0, IS_VOID, 0)

ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_adapterfactory_method_entry) {
	PHP_ME(Phalcon_Logger_AdapterFactory, __construct, arginfo_phalcon_logger_adapterfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Logger_AdapterFactory, newInstance, arginfo_phalcon_logger_adapterfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Logger_AdapterFactory, getExceptionClass, arginfo_phalcon_logger_adapterfactory_getexceptionclass, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Logger_AdapterFactory, getServices, arginfo_phalcon_logger_adapterfactory_getservices, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Logger_AdapterFactory, getCachedInstance, arginfo_phalcon_logger_adapterfactory_getcachedinstance, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Logger_AdapterFactory, getService, arginfo_phalcon_logger_adapterfactory_getservice, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Logger_AdapterFactory, init, arginfo_phalcon_logger_adapterfactory_init, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
