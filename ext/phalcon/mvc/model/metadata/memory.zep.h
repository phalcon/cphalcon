
extern zend_class_entry *phalcon_mvc_model_metadata_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_MetaData_Memory);

PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memory, __construct);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memory, read);
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Memory, write);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_metadata_memory___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_memory_read, 0, 1, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_model_metadata_memory_write, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_model_metadata_memory_method_entry) {
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memory, __construct, arginfo_phalcon_mvc_model_metadata_memory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memory, read, arginfo_phalcon_mvc_model_metadata_memory_read, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_MetaData_Memory, write, arginfo_phalcon_mvc_model_metadata_memory_write, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
