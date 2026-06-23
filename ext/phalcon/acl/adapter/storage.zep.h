
extern zend_class_entry *phalcon_acl_adapter_storage_ce;

ZEPHIR_INIT_CLASS(Phalcon_Acl_Adapter_Storage);

PHP_METHOD(Phalcon_Acl_Adapter_Storage, __construct);
PHP_METHOD(Phalcon_Acl_Adapter_Storage, load);
PHP_METHOD(Phalcon_Acl_Adapter_Storage, save);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_acl_adapter_storage___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storage, Phalcon\\Storage\\Adapter\\AdapterInterface, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, key, IS_STRING, 0, "'acl-data'")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_storage_load, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_acl_adapter_storage_save, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_acl_adapter_storage_method_entry) {
	PHP_ME(Phalcon_Acl_Adapter_Storage, __construct, arginfo_phalcon_acl_adapter_storage___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Acl_Adapter_Storage, load, arginfo_phalcon_acl_adapter_storage_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Acl_Adapter_Storage, save, arginfo_phalcon_acl_adapter_storage_save, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
