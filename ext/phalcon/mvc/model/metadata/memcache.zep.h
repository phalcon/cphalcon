
extern zend_class_entry *phalcon_mvc_model_metadata_memcache_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Memcache);

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memcache, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memcache, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memcache, write);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memcache, reset);
zend_object_value zephir_init_properties_Phalcon_Mvc_Model_MetaData_Memcache(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_memcache___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_memcache_read, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_memcache_write, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_memcache_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memcache, __construct, arginfo_phalcon_mvc_model_metadata_memcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memcache, read, arginfo_phalcon_mvc_model_metadata_memcache_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memcache, write, arginfo_phalcon_mvc_model_metadata_memcache_write, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memcache, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
