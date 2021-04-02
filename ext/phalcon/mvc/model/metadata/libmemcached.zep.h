
extern zend_class_entry *phalcon_mvc_model_metadata_libmemcached_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Libmemcached);

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Libmemcached, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_libmemcached___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Phalcon\\Cache\\AdapterFactory, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_libmemcached_reset, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_libmemcached_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Libmemcached, __construct, arginfo_phalcon_mvc_model_metadata_libmemcached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Libmemcached, reset, arginfo_phalcon_mvc_model_metadata_libmemcached_reset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
