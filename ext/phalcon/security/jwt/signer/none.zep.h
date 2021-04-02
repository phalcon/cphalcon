
extern zend_class_entry *phalcon_security_jwt_signer_none_ce;

ZEPHIR_INIT_CLASS(Phalcon_Security_JWT_Signer_None);

PHP_METHOD(Phalcon_Security_JWT_Signer_None, getAlgHeader);
PHP_METHOD(Phalcon_Security_JWT_Signer_None, getAlgorithm);
PHP_METHOD(Phalcon_Security_JWT_Signer_None, sign);
PHP_METHOD(Phalcon_Security_JWT_Signer_None, verify);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_signer_none_getalgheader, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_signer_none_getalgorithm, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_signer_none_sign, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, payload, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, passphrase, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_signer_none_verify, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, source, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, payload, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, passphrase, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_security_jwt_signer_none_method_entry) {
	PHP_ME(Phalcon_Security_JWT_Signer_None, getAlgHeader, arginfo_phalcon_security_jwt_signer_none_getalgheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Signer_None, getAlgorithm, arginfo_phalcon_security_jwt_signer_none_getalgorithm, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Signer_None, sign, arginfo_phalcon_security_jwt_signer_none_sign, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Signer_None, verify, arginfo_phalcon_security_jwt_signer_none_verify, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
