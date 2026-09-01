
extern zend_class_entry *phalcon_contracts_auth_guard_basicauth_ce;

ZEPHIR_INIT_CLASS(Phalcon_Contracts_Auth_Guard_BasicAuth);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_contracts_auth_guard_basicauth_basic, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, field, IS_STRING, 0, "'email'")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extraConditions, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_TYPE_MASK_EX(arginfo_phalcon_contracts_auth_guard_basicauth_oncebasic, 0, 0, Phalcon\\Contracts\\Auth\\AuthUser, MAY_BE_FALSE)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, field, IS_STRING, 0, "'email'")
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extraConditions, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_contracts_auth_guard_basicauth_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Guard_BasicAuth, basic, arginfo_phalcon_contracts_auth_guard_basicauth_basic)
	PHP_ABSTRACT_ME(Phalcon_Contracts_Auth_Guard_BasicAuth, onceBasic, arginfo_phalcon_contracts_auth_guard_basicauth_oncebasic)
	PHP_FE_END
};
