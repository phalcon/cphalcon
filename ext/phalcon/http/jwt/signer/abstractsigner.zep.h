
extern zend_class_entry *phalcon_http_jwt_signer_abstractsigner_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_JWT_Signer_AbstractSigner);

PHP_METHOD(Phalcon_Http_JWT_Signer_AbstractSigner, getAlgorithm);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_signer_abstractsigner_getalgorithm, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_signer_abstractsigner_getalgorithm, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_jwt_signer_abstractsigner_method_entry) {
	PHP_ME(Phalcon_Http_JWT_Signer_AbstractSigner, getAlgorithm, arginfo_phalcon_http_jwt_signer_abstractsigner_getalgorithm, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
