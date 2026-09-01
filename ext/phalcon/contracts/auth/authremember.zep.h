
extern zend_class_entry *phalcon_contracts_auth_authremember_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_AuthRemember);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_authremember_createremembertoken, 0, 1, Phalcon\\Contracts\\Auth\\RememberToken, 0)
	ZEND_ARG_TYPE_INFO(0, token, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, userAgent, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_contracts_auth_authremember_getremembertoken, 0, 1, Phalcon\\Contracts\\Auth\\RememberToken, 1)
	ZEND_ARG_TYPE_INFO(0, token, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_auth_authremember_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_AuthRemember, createRememberToken, arginfo_phalcon_contracts_auth_authremember_createremembertoken)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_AuthRemember, getRememberToken, arginfo_phalcon_contracts_auth_authremember_getremembertoken)
	PHP_FE_END
};
