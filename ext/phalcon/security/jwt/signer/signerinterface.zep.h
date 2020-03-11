
extern zend_class_entry *phalcon_security_jwt_signer_signerinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_Security_JWT_Signer_SignerInterface);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_signer_signerinterface_getalgheader, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_signer_signerinterface_getalgheader, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_signer_signerinterface_getalgorithm, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_signer_signerinterface_getalgorithm, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_signer_signerinterface_sign, 0, 2, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_signer_signerinterface_sign, 0, 2, IS_STRING, NULL, 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_signer_signerinterface_verify, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_signer_signerinterface_verify, 0, 3, _IS_BOOL, NULL, 0)
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

ZEPHIR_INIT_FUNCS(phalcon_security_jwt_signer_signerinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_Security_JWT_Signer_SignerInterface, getAlgHeader, arginfo_phalcon_security_jwt_signer_signerinterface_getalgheader)
	PHP_ABSTRACT_ME(Phalcon_Security_JWT_Signer_SignerInterface, getAlgorithm, arginfo_phalcon_security_jwt_signer_signerinterface_getalgorithm)
	PHP_ABSTRACT_ME(Phalcon_Security_JWT_Signer_SignerInterface, sign, arginfo_phalcon_security_jwt_signer_signerinterface_sign)
	PHP_ABSTRACT_ME(Phalcon_Security_JWT_Signer_SignerInterface, verify, arginfo_phalcon_security_jwt_signer_signerinterface_verify)
	PHP_FE_END
};
