
extern zend_class_entry *phalcon_auth_adapter_abstractadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_AbstractAdapter);

PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, __construct);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, getConfig);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, getModel);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, validateCredentials);
PHP_METHOD(Phalcon_Auth_Adapter_AbstractAdapter, burnHash);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, hasher, Phalcon\\Contracts\\Encryption\\Security\\Security, 0)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Contracts\\Auth\\Adapter\\AdapterConfig, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter_getconfig, 0, 0, Phalcon\\Contracts\\Auth\\Adapter\\AdapterConfig, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter_getmodel, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter_validatecredentials, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Contracts\\Auth\\AuthUser, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_adapter_abstractadapter_burnhash, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_abstractadapter_method_entry) {
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, __construct, arginfo_phalcon_auth_adapter_abstractadapter___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, getConfig, arginfo_phalcon_auth_adapter_abstractadapter_getconfig, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, getModel, arginfo_phalcon_auth_adapter_abstractadapter_getmodel, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, validateCredentials, arginfo_phalcon_auth_adapter_abstractadapter_validatecredentials, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_AbstractAdapter, burnHash, arginfo_phalcon_auth_adapter_abstractadapter_burnhash, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
