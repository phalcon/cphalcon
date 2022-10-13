
extern zend_class_entry *phalcon_encryption_security_jwt_validator_ce;

ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_JWT_Validator);

PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, __construct);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, getErrors);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, get);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, set);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, setToken);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, validateAudience);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, validateExpiration);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, validateId);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, validateIssuedAt);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, validateIssuer);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, validateNotBefore);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, validateSignature);
PHP_METHOD(Phalcon_Encryption_Security_JWT_Validator, getTimestamp);
zend_object *zephir_init_properties_Phalcon_Encryption_Security_JWT_Validator(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encryption_security_jwt_validator___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, token, Phalcon\\Encryption\\Security\\JWT\\Token\\Token, 0)
	ZEND_ARG_TYPE_INFO(0, timeShift, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_jwt_validator_geterrors, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_jwt_validator_get, 0, 1, IS_MIXED, 1)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encryption_security_jwt_validator_get, 0, 0, 1)
#endif
	ZEND_ARG_TYPE_INFO(0, claim, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_validator_set, 0, 2, Phalcon\\Encryption\\Security\\JWT\\Validator, 0)
	ZEND_ARG_TYPE_INFO(0, claim, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_validator_settoken, 0, 1, Phalcon\\Encryption\\Security\\JWT\\Validator, 0)
	ZEND_ARG_OBJ_INFO(0, token, Phalcon\\Encryption\\Security\\JWT\\Token\\Token, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_validator_validateaudience, 0, 1, Phalcon\\Encryption\\Security\\JWT\\Validator, 0)
	ZEND_ARG_INFO(0, audience)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_validator_validateexpiration, 0, 1, Phalcon\\Encryption\\Security\\JWT\\Validator, 0)
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_validator_validateid, 0, 1, Phalcon\\Encryption\\Security\\JWT\\Validator, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_validator_validateissuedat, 0, 1, Phalcon\\Encryption\\Security\\JWT\\Validator, 0)
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_validator_validateissuer, 0, 1, Phalcon\\Encryption\\Security\\JWT\\Validator, 0)
	ZEND_ARG_TYPE_INFO(0, issuer, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_validator_validatenotbefore, 0, 1, Phalcon\\Encryption\\Security\\JWT\\Validator, 0)
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_jwt_validator_validatesignature, 0, 2, Phalcon\\Encryption\\Security\\JWT\\Validator, 0)
	ZEND_ARG_OBJ_INFO(0, signer, Phalcon\\Encryption\\Security\\JWT\\Signer\\SignerInterface, 0)
	ZEND_ARG_TYPE_INFO(0, passphrase, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_jwt_validator_gettimestamp, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encryption_security_jwt_validator_zephir_init_properties_phalcon_encryption_security_jwt_validator, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_encryption_security_jwt_validator_method_entry) {
	PHP_ME(Phalcon_Encryption_Security_JWT_Validator, __construct, arginfo_phalcon_encryption_security_jwt_validator___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Encryption_Security_JWT_Validator, getErrors, arginfo_phalcon_encryption_security_jwt_validator_geterrors, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Validator, get, arginfo_phalcon_encryption_security_jwt_validator_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Validator, set, arginfo_phalcon_encryption_security_jwt_validator_set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Validator, setToken, arginfo_phalcon_encryption_security_jwt_validator_settoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Validator, validateAudience, arginfo_phalcon_encryption_security_jwt_validator_validateaudience, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Validator, validateExpiration, arginfo_phalcon_encryption_security_jwt_validator_validateexpiration, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Validator, validateId, arginfo_phalcon_encryption_security_jwt_validator_validateid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Validator, validateIssuedAt, arginfo_phalcon_encryption_security_jwt_validator_validateissuedat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Validator, validateIssuer, arginfo_phalcon_encryption_security_jwt_validator_validateissuer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Validator, validateNotBefore, arginfo_phalcon_encryption_security_jwt_validator_validatenotbefore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Validator, validateSignature, arginfo_phalcon_encryption_security_jwt_validator_validatesignature, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security_JWT_Validator, getTimestamp, arginfo_phalcon_encryption_security_jwt_validator_gettimestamp, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
