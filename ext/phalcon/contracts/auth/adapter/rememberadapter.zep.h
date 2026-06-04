
extern zend_class_entry *phalcon_contracts_auth_adapter_rememberadapter_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Adapter_RememberAdapter);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_adapter_rememberadapter_createremembertoken, 0, 1, Phalcon\\Contracts\\Auth\\RememberToken, 0)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Contracts\\Auth\\AuthUser, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_adapter_rememberadapter_retrievebytoken, 0, 2, Phalcon\\Contracts\\Auth\\AuthUser, 1)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_TYPE_INFO(0, token, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userAgent, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_auth_adapter_rememberadapter_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Adapter_RememberAdapter, createRememberToken, arginfo_phalcon_contracts_auth_adapter_rememberadapter_createremembertoken)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Adapter_RememberAdapter, retrieveByToken, arginfo_phalcon_contracts_auth_adapter_rememberadapter_retrievebytoken)
	PHP_FE_END
};
