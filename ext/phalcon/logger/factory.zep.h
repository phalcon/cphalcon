
extern zend_class_entry *phalcon_logger_factory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Logger_Factory);

PHP_METHOD(Phalcon_Logger_Factory, load);
PHP_METHOD(Phalcon_Logger_Factory, loadClass);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_logger_factory_load, 0, 1, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_logger_factory_load, 0, 1, IS_OBJECT, "NULL", 0)
#endif
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_logger_factory_loadclass, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, objectName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, objectName)
#endif
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_logger_factory_method_entry) {
	PHP_ME(Phalcon_Logger_Factory, load, arginfo_phalcon_logger_factory_load, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Logger_Factory, loadClass, arginfo_phalcon_logger_factory_loadclass, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
