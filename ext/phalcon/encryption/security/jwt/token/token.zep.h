
extern zend_class_entry *phalcon_encryption_security_jwt_token_token_ce;

ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_JWT_Token_Token);

PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, __construct);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, getClaims);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, getHeaders);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, getPayload);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, getSignature);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, getToken);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, validate);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Token, verify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encryption_security_jwt_token_token___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, headers, Phalcon\\Encryption\\Security\\JWT\\Token\\Item, 0)
	ZEND_ARG_OBJ_INFO(0, claims, Phalcon\\Encryption\\Security\\JWT\\Token\\Item, 0)
	ZEND_ARG_OBJ_INFO(0, signature, Phalcon\\Encryption\\Security\\JWT\\Token\\Signature, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_token_token_getclaims, 0, 0, Phalcon\\Encryption\\Security\\JWT\\Token\\Item, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_token_token_getheaders, 0, 0, Phalcon\\Encryption\\Security\\JWT\\Token\\Item, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_jwt_token_token_getpayload, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_token_token_getsignature, 0, 0, Phalcon\\Encryption\\Security\\JWT\\Token\\Signature, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_jwt_token_token_gettoken, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_jwt_token_token_validate, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, validator, Phalcon\\Encryption\\Security\\JWT\\Validator, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_jwt_token_token_verify, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, signer, Phalcon\\Encryption\\Security\\JWT\\Signer\\SignerInterface, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_encryption_security_jwt_token_token_method_entry) {
	PHP_ME(Phalcon_Encryption_Security_JWT_Token_Token, __construct, arginfo_phalcon_encryption_security_jwt_token_token___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Encryption_Security_JWT_Token_Token, getClaims, arginfo_phalcon_encryption_security_jwt_token_token_getclaims, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Token_Token, getHeaders, arginfo_phalcon_encryption_security_jwt_token_token_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Token_Token, getPayload, arginfo_phalcon_encryption_security_jwt_token_token_getpayload, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Token_Token, getSignature, arginfo_phalcon_encryption_security_jwt_token_token_getsignature, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Token_Token, getToken, arginfo_phalcon_encryption_security_jwt_token_token_gettoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Token_Token, validate, arginfo_phalcon_encryption_security_jwt_token_token_validate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Token_Token, verify, arginfo_phalcon_encryption_security_jwt_token_token_verify, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
