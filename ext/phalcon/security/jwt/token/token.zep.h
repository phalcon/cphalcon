
extern zend_class_entry *phalcon_security_jwt_token_token_ce;

ZEPHIR_INIT_CLASS(Phalcon_Security_JWT_Token_Token);

PHP_METHOD(Phalcon_Security_JWT_Token_Token, getClaims);
PHP_METHOD(Phalcon_Security_JWT_Token_Token, getHeaders);
PHP_METHOD(Phalcon_Security_JWT_Token_Token, getSignature);
PHP_METHOD(Phalcon_Security_JWT_Token_Token, __construct);
PHP_METHOD(Phalcon_Security_JWT_Token_Token, getPayload);
PHP_METHOD(Phalcon_Security_JWT_Token_Token, getToken);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_jwt_token_token_getclaims, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_jwt_token_token_getheaders, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_jwt_token_token_getsignature, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_jwt_token_token___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, headers, Phalcon\\Security\\JWT\\Token\\Item, 0)
	ZEND_ARG_OBJ_INFO(0, claims, Phalcon\\Security\\JWT\\Token\\Item, 0)
	ZEND_ARG_OBJ_INFO(0, signature, Phalcon\\Security\\JWT\\Token\\Signature, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_token_token_getpayload, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_token_token_gettoken, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_security_jwt_token_token_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Security_JWT_Token_Token, getClaims, arginfo_phalcon_security_jwt_token_token_getclaims, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Security_JWT_Token_Token, getClaims, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Security_JWT_Token_Token, getHeaders, arginfo_phalcon_security_jwt_token_token_getheaders, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Security_JWT_Token_Token, getHeaders, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Security_JWT_Token_Token, getSignature, arginfo_phalcon_security_jwt_token_token_getsignature, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Security_JWT_Token_Token, getSignature, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Security_JWT_Token_Token, __construct, arginfo_phalcon_security_jwt_token_token___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Security_JWT_Token_Token, getPayload, arginfo_phalcon_security_jwt_token_token_getpayload, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Token_Token, getToken, arginfo_phalcon_security_jwt_token_token_gettoken, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
