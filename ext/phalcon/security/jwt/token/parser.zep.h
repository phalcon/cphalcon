
extern zend_class_entry *phalcon_security_jwt_token_parser_ce;

ZEPHIR_INIT_CLASS(Phalcon_Security_JWT_Token_Parser);

PHP_METHOD(Phalcon_Security_JWT_Token_Parser, parse);
PHP_METHOD(Phalcon_Security_JWT_Token_Parser, decodeClaims);
PHP_METHOD(Phalcon_Security_JWT_Token_Parser, decodeHeaders);
PHP_METHOD(Phalcon_Security_JWT_Token_Parser, decodeSignature);
PHP_METHOD(Phalcon_Security_JWT_Token_Parser, parseToken);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_token_parser_parse, 0, 1, Phalcon\\Security\\JWT\\Token\\Token, 0)
	ZEND_ARG_TYPE_INFO(0, token, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_token_parser_decodeclaims, 0, 1, Phalcon\\Security\\JWT\\Token\\Item, 0)
	ZEND_ARG_TYPE_INFO(0, claims, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_token_parser_decodeheaders, 0, 1, Phalcon\\Security\\JWT\\Token\\Item, 0)
	ZEND_ARG_TYPE_INFO(0, headers, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_token_parser_decodesignature, 0, 2, Phalcon\\Security\\JWT\\Token\\Signature, 0)
	ZEND_ARG_OBJ_INFO(0, headers, Phalcon\\Security\\JWT\\Token\\Item, 0)
	ZEND_ARG_TYPE_INFO(0, signature, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_token_parser_parsetoken, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, token, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_security_jwt_token_parser_method_entry) {
	PHP_ME(Phalcon_Security_JWT_Token_Parser, parse, arginfo_phalcon_security_jwt_token_parser_parse, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Token_Parser, decodeClaims, arginfo_phalcon_security_jwt_token_parser_decodeclaims, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Security_JWT_Token_Parser, decodeHeaders, arginfo_phalcon_security_jwt_token_parser_decodeheaders, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Security_JWT_Token_Parser, decodeSignature, arginfo_phalcon_security_jwt_token_parser_decodesignature, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Security_JWT_Token_Parser, parseToken, arginfo_phalcon_security_jwt_token_parser_parsetoken, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
