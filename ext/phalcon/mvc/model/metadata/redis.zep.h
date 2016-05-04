
extern zend_class_entry *phalcon_mvc_model_metadata_redis_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Redis);

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, write);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Redis, reset);
zend_object_value zephir_init_properties_Phalcon_Mvc_Model_MetaData_Redis(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_redis___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_redis_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_redis_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_redis_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Redis, __construct, arginfo_phalcon_mvc_model_metadata_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Redis, read, arginfo_phalcon_mvc_model_metadata_redis_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Redis, write, arginfo_phalcon_mvc_model_metadata_redis_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Redis, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
