
extern zend_class_entry *phalcon_auth_adapter_memory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Memory);

PHP_METHOD(Phalcon_Auth_Adapter_Memory, __construct);
PHP_METHOD(Phalcon_Auth_Adapter_Memory, fromOptions);
PHP_METHOD(Phalcon_Auth_Adapter_Memory, retrieveById);
PHP_METHOD(Phalcon_Auth_Adapter_Memory, loadUsers);
zend_object *zephir_init_properties_Phalcon_Auth_Adapter_Memory(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_memory___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, hasher, Phalcon\\Contracts\\Encryption\\Security\\Security, 0)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Auth\\Adapter\\Config\\MemoryAdapterConfig, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_adapter_memory_fromoptions, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_OBJ_INFO(0, hasher, Phalcon\\Contracts\\Encryption\\Security\\Security, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_memory_retrievebyid, 0, 1, Phalcon\\Contracts\\Auth\\AuthUser, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_memory_loadusers, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_memory_zephir_init_properties_phalcon_auth_adapter_memory, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_memory_method_entry) {
	PHP_ME(Phalcon_Auth_Adapter_Memory, __construct, arginfo_phalcon_auth_adapter_memory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Adapter_Memory, fromOptions, arginfo_phalcon_auth_adapter_memory_fromoptions, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Auth_Adapter_Memory, retrieveById, arginfo_phalcon_auth_adapter_memory_retrievebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_Memory, loadUsers, arginfo_phalcon_auth_adapter_memory_loadusers, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
