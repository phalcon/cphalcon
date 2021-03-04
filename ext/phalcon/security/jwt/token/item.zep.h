
extern zend_class_entry *phalcon_security_jwt_token_item_ce;

ZEPHIR_INIT_CLASS(Phalcon_Security_JWT_Token_Item);

PHP_METHOD(Phalcon_Security_JWT_Token_Item, __construct);
PHP_METHOD(Phalcon_Security_JWT_Token_Item, get);
PHP_METHOD(Phalcon_Security_JWT_Token_Item, getPayload);
PHP_METHOD(Phalcon_Security_JWT_Token_Item, has);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_jwt_token_item___construct, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, payload, 0)
	ZEND_ARG_TYPE_INFO(0, encoded, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_jwt_token_item_get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_token_item_getpayload, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_token_item_has, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_security_jwt_token_item_method_entry) {
	PHP_ME(Phalcon_Security_JWT_Token_Item, __construct, arginfo_phalcon_security_jwt_token_item___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Security_JWT_Token_Item, get, arginfo_phalcon_security_jwt_token_item_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Token_Item, getPayload, arginfo_phalcon_security_jwt_token_item_getpayload, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Token_Item, has, arginfo_phalcon_security_jwt_token_item_has, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
