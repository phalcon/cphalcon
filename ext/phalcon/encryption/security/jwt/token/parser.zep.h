
extern zend_class_entry *phalcon_encryption_security_jwt_token_parser_ce;

ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_JWT_Token_Parser);

PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Parser, parse);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Parser, decodeClaims);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Parser, decodeHeaders);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Parser, decodeSignature);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Parser, parseToken);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Parser, decode);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Token_Parser, decodeUrl);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_token_parser_parse, 0, 1, Phalcon\\Encryption\\Security\\JWT\\Token\\Token, 0)
	ZEND_ARG_TYPE_INFO(0, token, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_token_parser_decodeclaims, 0, 1, Phalcon\\Encryption\\Security\\JWT\\Token\\Item, 0)
	ZEND_ARG_TYPE_INFO(0, claims, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_token_parser_decodeheaders, 0, 1, Phalcon\\Encryption\\Security\\JWT\\Token\\Item, 0)
	ZEND_ARG_TYPE_INFO(0, headers, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_token_parser_decodesignature, 0, 2, Phalcon\\Encryption\\Security\\JWT\\Token\\Signature, 0)
	ZEND_ARG_OBJ_INFO(0, headers, Phalcon\\Encryption\\Security\\JWT\\Token\\Item, 0)
	ZEND_ARG_TYPE_INFO(0, signature, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_jwt_token_parser_parsetoken, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, token, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encryption_security_jwt_token_parser_decode, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, associative, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_jwt_token_parser_decodeurl, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_encryption_security_jwt_token_parser_method_entry) {
	PHP_ME(Phalcon_Encryption_Security_JWT_Token_Parser, parse, arginfo_phalcon_encryption_security_jwt_token_parser_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Token_Parser, decodeClaims, arginfo_phalcon_encryption_security_jwt_token_parser_decodeclaims, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Encryption_Security_JWT_Token_Parser, decodeHeaders, arginfo_phalcon_encryption_security_jwt_token_parser_decodeheaders, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Encryption_Security_JWT_Token_Parser, decodeSignature, arginfo_phalcon_encryption_security_jwt_token_parser_decodesignature, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Encryption_Security_JWT_Token_Parser, parseToken, arginfo_phalcon_encryption_security_jwt_token_parser_parsetoken, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Encryption_Security_JWT_Token_Parser, decode, arginfo_phalcon_encryption_security_jwt_token_parser_decode, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Encryption_Security_JWT_Token_Parser, decodeUrl, arginfo_phalcon_encryption_security_jwt_token_parser_decodeurl, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
