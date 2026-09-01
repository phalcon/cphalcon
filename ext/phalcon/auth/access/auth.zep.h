
extern zend_class_entry *phalcon_auth_access_auth_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Access_Auth);

PHP_METHOD(Phalcon_Auth_Access_Auth, allowedIf);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_access_auth_allowedif, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, guard, Phalcon\\Contracts\\Auth\\Guard\\Guard, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_access_auth_method_entry) {
	PHP_ME(Phalcon_Auth_Access_Auth, allowedIf, arginfo_phalcon_auth_access_auth_allowedif, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
