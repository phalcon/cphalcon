
extern zend_class_entry *phalcon_contracts_auth_adapter_adapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Adapter_Adapter);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_contracts_auth_adapter_adapter_fromoptions, 0, 2, MAY_BE_STATIC)
	ZEND_ARG_OBJ_INFO(0, hasher, Phalcon\\Contracts\\Encryption\\Security\\Security, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_adapter_adapter_retrievebycredentials, 0, 1, Phalcon\\Contracts\\Auth\\AuthUser, 1)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_adapter_adapter_retrievebyid, 0, 1, Phalcon\\Contracts\\Auth\\AuthUser, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_adapter_adapter_validatecredentials, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Contracts\\Auth\\AuthUser, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_auth_adapter_adapter_method_entry) {
	ZEND_FENTRY(fromOptions, NULL, arginfo_phalcon_contracts_auth_adapter_adapter_fromoptions, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Adapter_Adapter, retrieveByCredentials, arginfo_phalcon_contracts_auth_adapter_adapter_retrievebycredentials)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Adapter_Adapter, retrieveById, arginfo_phalcon_contracts_auth_adapter_adapter_retrievebyid)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Adapter_Adapter, validateCredentials, arginfo_phalcon_contracts_auth_adapter_adapter_validatecredentials)
	PHP_FE_END
};
