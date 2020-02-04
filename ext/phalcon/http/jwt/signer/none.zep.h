
extern zend_class_entry *phalcon_http_jwt_signer_none_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_JWT_Signer_None);

PHP_METHOD(Phalcon_Http_JWT_Signer_None, getAlgHeader);
PHP_METHOD(Phalcon_Http_JWT_Signer_None, getAlgorithm);
PHP_METHOD(Phalcon_Http_JWT_Signer_None, sign);
PHP_METHOD(Phalcon_Http_JWT_Signer_None, verify);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_signer_none_getalgheader, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_signer_none_getalgheader, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_signer_none_getalgorithm, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_signer_none_getalgorithm, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_signer_none_sign, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_signer_none_sign, 0, 2, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, payload, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, payload)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, passphrase, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, passphrase)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_signer_none_verify, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_signer_none_verify, 0, 3, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, source, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, source)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, payload, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, payload)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, passphrase, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, passphrase)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_jwt_signer_none_method_entry) {
	PHP_ME(Phalcon_Http_JWT_Signer_None, getAlgHeader, arginfo_phalcon_http_jwt_signer_none_getalgheader, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_JWT_Signer_None, getAlgorithm, arginfo_phalcon_http_jwt_signer_none_getalgorithm, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_JWT_Signer_None, sign, arginfo_phalcon_http_jwt_signer_none_sign, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_JWT_Signer_None, verify, arginfo_phalcon_http_jwt_signer_none_verify, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
