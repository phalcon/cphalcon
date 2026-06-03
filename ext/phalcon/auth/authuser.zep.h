
extern zend_class_entry *phalcon_auth_authuser_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_AuthUser);

PHP_METHOD(Phalcon_Auth_AuthUser, __construct);
PHP_METHOD(Phalcon_Auth_AuthUser, getAuthIdentifier);
PHP_METHOD(Phalcon_Auth_AuthUser, getAuthPassword);
PHP_METHOD(Phalcon_Auth_AuthUser, toArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_authuser___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_authuser_getauthidentifier, 0, 0, MAY_BE_LONG|MAY_BE_STRING)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_authuser_getauthpassword, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_authuser_toarray, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_authuser_method_entry) {
	PHP_ME(Phalcon_Auth_AuthUser, __construct, arginfo_phalcon_auth_authuser___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_AuthUser, getAuthIdentifier, arginfo_phalcon_auth_authuser_getauthidentifier, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_AuthUser, getAuthPassword, arginfo_phalcon_auth_authuser_getauthpassword, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_AuthUser, toArray, arginfo_phalcon_auth_authuser_toarray, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
