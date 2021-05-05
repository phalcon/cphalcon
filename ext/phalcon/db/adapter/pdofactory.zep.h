
extern zend_class_entry *phalcon_db_adapter_pdofactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_PdoFactory);

PHP_METHOD(Phalcon_Db_Adapter_PdoFactory, __construct);
PHP_METHOD(Phalcon_Db_Adapter_PdoFactory, load);
PHP_METHOD(Phalcon_Db_Adapter_PdoFactory, newInstance);
PHP_METHOD(Phalcon_Db_Adapter_PdoFactory, getAdapters);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_adapter_pdofactory___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, services, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_pdofactory_load, 0, 1, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_db_adapter_pdofactory_newinstance, 0, 1, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_db_adapter_pdofactory_getadapters, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_db_adapter_pdofactory_method_entry) {
	PHP_ME(Phalcon_Db_Adapter_PdoFactory, __construct, arginfo_phalcon_db_adapter_pdofactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Adapter_PdoFactory, load, arginfo_phalcon_db_adapter_pdofactory_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_PdoFactory, newInstance, arginfo_phalcon_db_adapter_pdofactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Adapter_PdoFactory, getAdapters, arginfo_phalcon_db_adapter_pdofactory_getadapters, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
