
extern zend_class_entry *phalcon_auth_access_acl_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Access_Acl);

PHP_METHOD(Phalcon_Auth_Access_Acl, __construct);
PHP_METHOD(Phalcon_Auth_Access_Acl, isAllowed);
PHP_METHOD(Phalcon_Auth_Access_Acl, allowedIf);
PHP_METHOD(Phalcon_Auth_Access_Acl, resolveRole);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_access_acl___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, acl, Phalcon\\Acl\\Adapter\\AdapterInterface, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_acl_isallowed, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, guard, Phalcon\\Contracts\\Auth\\Guard\\Guard, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_acl_allowedif, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, guard, Phalcon\\Contracts\\Auth\\Guard\\Guard, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_acl_resolverole, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, guard, Phalcon\\Contracts\\Auth\\Guard\\Guard, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_access_acl_method_entry) {
	PHP_ME(Phalcon_Auth_Access_Acl, __construct, arginfo_phalcon_auth_access_acl___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Access_Acl, isAllowed, arginfo_phalcon_auth_access_acl_isallowed, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Access_Acl, allowedIf, arginfo_phalcon_auth_access_acl_allowedif, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Auth_Access_Acl, resolveRole, arginfo_phalcon_auth_access_acl_resolverole, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
