
extern zend_class_entry *phalcon_auth_guard_userremember_ce;

ZEPHIR_INIT_CLASS(Phalcon_Auth_Guard_UserRemember);

PHP_METHOD(Phalcon_Auth_Guard_UserRemember, __construct);
PHP_METHOD(Phalcon_Auth_Guard_UserRemember, getId);
PHP_METHOD(Phalcon_Auth_Guard_UserRemember, getToken);
PHP_METHOD(Phalcon_Auth_Guard_UserRemember, getUserAgent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_auth_guard_userremember___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, payload)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_auth_guard_userremember_getid, 0, 0, MAY_BE_NULL|MAY_BE_LONG|MAY_BE_STRING)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_userremember_gettoken, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_auth_guard_userremember_getuseragent, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_auth_guard_userremember_method_entry) {
	PHP_ME(Phalcon_Auth_Guard_UserRemember, __construct, arginfo_phalcon_auth_guard_userremember___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Auth_Guard_UserRemember, getId, arginfo_phalcon_auth_guard_userremember_getid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_UserRemember, getToken, arginfo_phalcon_auth_guard_userremember_gettoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Auth_Guard_UserRemember, getUserAgent, arginfo_phalcon_auth_guard_userremember_getuseragent, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
