
extern zend_class_entry *phalcon_http_jwt_token_signature_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_JWT_Token_Signature);

PHP_METHOD(Phalcon_Http_JWT_Token_Signature, __construct);
PHP_METHOD(Phalcon_Http_JWT_Token_Signature, getHash);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_jwt_token_signature___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, hash, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, hash)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, encoded, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, encoded)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_token_signature_gethash, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_token_signature_gethash, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_jwt_token_signature_method_entry) {
	PHP_ME(Phalcon_Http_JWT_Token_Signature, __construct, arginfo_phalcon_http_jwt_token_signature___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_JWT_Token_Signature, getHash, arginfo_phalcon_http_jwt_token_signature_gethash, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
