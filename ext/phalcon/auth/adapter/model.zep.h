
extern zend_class_entry *phalcon_auth_adapter_model_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Adapter_Model);

PHP_METHOD(Phalcon_Auth_Adapter_Model, __construct);
PHP_METHOD(Phalcon_Auth_Adapter_Model, fromOptions);
PHP_METHOD(Phalcon_Auth_Adapter_Model, createRememberToken);
PHP_METHOD(Phalcon_Auth_Adapter_Model, retrieveByCredentials);
PHP_METHOD(Phalcon_Auth_Adapter_Model, retrieveById);
PHP_METHOD(Phalcon_Auth_Adapter_Model, retrieveByToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_adapter_model___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, hasher, Phalcon\\Contracts\\Encryption\\Security\\Security, 0)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Auth\\Adapter\\Config\\ModelAdapterConfig, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_adapter_model_fromoptions, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_OBJ_INFO(0, hasher, Phalcon\\Contracts\\Encryption\\Security\\Security, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_model_createremembertoken, 0, 1, Phalcon\\Contracts\\Auth\\RememberToken, 0)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Contracts\\Auth\\AuthUser, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_model_retrievebycredentials, 0, 1, Phalcon\\Contracts\\Auth\\AuthUser, 1)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_model_retrievebyid, 0, 1, Phalcon\\Contracts\\Auth\\AuthUser, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_auth_adapter_model_retrievebytoken, 0, 2, Phalcon\\Contracts\\Auth\\AuthUser, 1)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_TYPE_INFO(0, token, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userAgent, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_adapter_model_method_entry) {
	PHP_ME(Phalcon_Auth_Adapter_Model, __construct, arginfo_phalcon_auth_adapter_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Adapter_Model, fromOptions, arginfo_phalcon_auth_adapter_model_fromoptions, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Auth_Adapter_Model, createRememberToken, arginfo_phalcon_auth_adapter_model_createremembertoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_Model, retrieveByCredentials, arginfo_phalcon_auth_adapter_model_retrievebycredentials, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_Model, retrieveById, arginfo_phalcon_auth_adapter_model_retrievebyid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Adapter_Model, retrieveByToken, arginfo_phalcon_auth_adapter_model_retrievebytoken, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
