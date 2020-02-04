
extern zend_class_entry *phalcon_http_jwt_validator_ce;

ZEPHIR_INIT_CLASS(Phalcon_Http_JWT_Validator);

PHP_METHOD(Phalcon_Http_JWT_Validator, __construct);
PHP_METHOD(Phalcon_Http_JWT_Validator, setToken);
PHP_METHOD(Phalcon_Http_JWT_Validator, validateAudience);
PHP_METHOD(Phalcon_Http_JWT_Validator, validateExpiration);
PHP_METHOD(Phalcon_Http_JWT_Validator, validateId);
PHP_METHOD(Phalcon_Http_JWT_Validator, validateIssuedAt);
PHP_METHOD(Phalcon_Http_JWT_Validator, validateIssuer);
PHP_METHOD(Phalcon_Http_JWT_Validator, validateNotBefore);
PHP_METHOD(Phalcon_Http_JWT_Validator, validateSignature);
PHP_METHOD(Phalcon_Http_JWT_Validator, getTimestamp);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_http_jwt_validator___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, token, Phalcon\\Http\\JWT\\Token\\Token, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, timeShift, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, timeShift)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_jwt_validator_settoken, 0, 1, Phalcon\\Http\\JWT\\Validator, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_validator_settoken, 0, 1, IS_OBJECT, "Phalcon\\Http\\JWT\\Validator", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, token, Phalcon\\Http\\JWT\\Token\\Token, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_jwt_validator_validateaudience, 0, 1, Phalcon\\Http\\JWT\\Validator, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_validator_validateaudience, 0, 1, IS_OBJECT, "Phalcon\\Http\\JWT\\Validator", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, audience, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, audience)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_jwt_validator_validateexpiration, 0, 1, Phalcon\\Http\\JWT\\Validator, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_validator_validateexpiration, 0, 1, IS_OBJECT, "Phalcon\\Http\\JWT\\Validator", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, timestamp)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_jwt_validator_validateid, 0, 1, Phalcon\\Http\\JWT\\Validator, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_validator_validateid, 0, 1, IS_OBJECT, "Phalcon\\Http\\JWT\\Validator", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, id)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_jwt_validator_validateissuedat, 0, 1, Phalcon\\Http\\JWT\\Validator, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_validator_validateissuedat, 0, 1, IS_OBJECT, "Phalcon\\Http\\JWT\\Validator", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, timestamp)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_jwt_validator_validateissuer, 0, 1, Phalcon\\Http\\JWT\\Validator, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_validator_validateissuer, 0, 1, IS_OBJECT, "Phalcon\\Http\\JWT\\Validator", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, issuer, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, issuer)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_jwt_validator_validatenotbefore, 0, 1, Phalcon\\Http\\JWT\\Validator, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_validator_validatenotbefore, 0, 1, IS_OBJECT, "Phalcon\\Http\\JWT\\Validator", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, timestamp)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_http_jwt_validator_validatesignature, 0, 2, Phalcon\\Http\\JWT\\Validator, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_validator_validatesignature, 0, 2, IS_OBJECT, "Phalcon\\Http\\JWT\\Validator", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, signer, Phalcon\\Http\\JWT\\Signer\\SignerInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, passphrase, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, passphrase)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_validator_gettimestamp, 0, 1, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_http_jwt_validator_gettimestamp, 0, 1, IS_LONG, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, timestamp)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_http_jwt_validator_method_entry) {
	PHP_ME(Phalcon_Http_JWT_Validator, __construct, arginfo_phalcon_http_jwt_validator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Http_JWT_Validator, setToken, arginfo_phalcon_http_jwt_validator_settoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_JWT_Validator, validateAudience, arginfo_phalcon_http_jwt_validator_validateaudience, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_JWT_Validator, validateExpiration, arginfo_phalcon_http_jwt_validator_validateexpiration, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_JWT_Validator, validateId, arginfo_phalcon_http_jwt_validator_validateid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_JWT_Validator, validateIssuedAt, arginfo_phalcon_http_jwt_validator_validateissuedat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_JWT_Validator, validateIssuer, arginfo_phalcon_http_jwt_validator_validateissuer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_JWT_Validator, validateNotBefore, arginfo_phalcon_http_jwt_validator_validatenotbefore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_JWT_Validator, validateSignature, arginfo_phalcon_http_jwt_validator_validatesignature, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Http_JWT_Validator, getTimestamp, arginfo_phalcon_http_jwt_validator_gettimestamp, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
