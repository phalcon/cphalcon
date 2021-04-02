
extern zend_class_entry *phalcon_security_jwt_token_signature_ce;

ZEPHIR_INIT_CLASS(Phalcon_Security_JWT_Token_Signature);

PHP_METHOD(Phalcon_Security_JWT_Token_Signature, __construct);
PHP_METHOD(Phalcon_Security_JWT_Token_Signature, getHash);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_jwt_token_signature___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, hash, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, encoded, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_token_signature_gethash, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_security_jwt_token_signature_method_entry) {
	PHP_ME(Phalcon_Security_JWT_Token_Signature, __construct, arginfo_phalcon_security_jwt_token_signature___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Security_JWT_Token_Signature, getHash, arginfo_phalcon_security_jwt_token_signature_gethash, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
