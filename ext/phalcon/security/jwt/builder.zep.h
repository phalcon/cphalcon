
extern zend_class_entry *phalcon_security_jwt_builder_ce;

ZEPHIR_INIT_CLASS(Phalcon_Security_JWT_Builder);

PHP_METHOD(Phalcon_Security_JWT_Builder, __construct);
PHP_METHOD(Phalcon_Security_JWT_Builder, init);
PHP_METHOD(Phalcon_Security_JWT_Builder, getAudience);
PHP_METHOD(Phalcon_Security_JWT_Builder, getClaims);
PHP_METHOD(Phalcon_Security_JWT_Builder, getContentType);
PHP_METHOD(Phalcon_Security_JWT_Builder, getExpirationTime);
PHP_METHOD(Phalcon_Security_JWT_Builder, getHeaders);
PHP_METHOD(Phalcon_Security_JWT_Builder, getId);
PHP_METHOD(Phalcon_Security_JWT_Builder, getIssuedAt);
PHP_METHOD(Phalcon_Security_JWT_Builder, getIssuer);
PHP_METHOD(Phalcon_Security_JWT_Builder, getNotBefore);
PHP_METHOD(Phalcon_Security_JWT_Builder, getSubject);
PHP_METHOD(Phalcon_Security_JWT_Builder, getToken);
PHP_METHOD(Phalcon_Security_JWT_Builder, getPassphrase);
PHP_METHOD(Phalcon_Security_JWT_Builder, setAudience);
PHP_METHOD(Phalcon_Security_JWT_Builder, setContentType);
PHP_METHOD(Phalcon_Security_JWT_Builder, setExpirationTime);
PHP_METHOD(Phalcon_Security_JWT_Builder, setId);
PHP_METHOD(Phalcon_Security_JWT_Builder, setIssuedAt);
PHP_METHOD(Phalcon_Security_JWT_Builder, setIssuer);
PHP_METHOD(Phalcon_Security_JWT_Builder, setNotBefore);
PHP_METHOD(Phalcon_Security_JWT_Builder, setSubject);
PHP_METHOD(Phalcon_Security_JWT_Builder, setPassphrase);
PHP_METHOD(Phalcon_Security_JWT_Builder, setClaim);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_jwt_builder___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, signer, Phalcon\\Security\\JWT\\Signer\\SignerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_builder_init, 0, 0, Phalcon\\Security\\JWT\\Builder, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_jwt_builder_getaudience, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_builder_getclaims, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_builder_getcontenttype, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_builder_getexpirationtime, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_builder_getheaders, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_builder_getid, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_builder_getissuedat, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_builder_getissuer, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_builder_getnotbefore, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_builder_getsubject, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_builder_gettoken, 0, 0, Phalcon\\Security\\JWT\\Token\\Token, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_jwt_builder_getpassphrase, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_builder_setaudience, 0, 1, Phalcon\\Security\\JWT\\Builder, 0)
	ZEND_ARG_INFO(0, audience)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_builder_setcontenttype, 0, 1, Phalcon\\Security\\JWT\\Builder, 0)
	ZEND_ARG_TYPE_INFO(0, contentType, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_builder_setexpirationtime, 0, 1, Phalcon\\Security\\JWT\\Builder, 0)
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_builder_setid, 0, 1, Phalcon\\Security\\JWT\\Builder, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_builder_setissuedat, 0, 1, Phalcon\\Security\\JWT\\Builder, 0)
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_builder_setissuer, 0, 1, Phalcon\\Security\\JWT\\Builder, 0)
	ZEND_ARG_TYPE_INFO(0, issuer, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_builder_setnotbefore, 0, 1, Phalcon\\Security\\JWT\\Builder, 0)
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_builder_setsubject, 0, 1, Phalcon\\Security\\JWT\\Builder, 0)
	ZEND_ARG_TYPE_INFO(0, subject, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_builder_setpassphrase, 0, 1, Phalcon\\Security\\JWT\\Builder, 0)
	ZEND_ARG_TYPE_INFO(0, passphrase, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_jwt_builder_setclaim, 0, 2, Phalcon\\Security\\JWT\\Builder, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_security_jwt_builder_method_entry) {
	PHP_ME(Phalcon_Security_JWT_Builder, __construct, arginfo_phalcon_security_jwt_builder___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Security_JWT_Builder, init, arginfo_phalcon_security_jwt_builder_init, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(Phalcon_Security_JWT_Builder, getAudience, arginfo_phalcon_security_jwt_builder_getaudience, ZEND_ACC_PUBLIC)
#else
	PHP_ME(Phalcon_Security_JWT_Builder, getAudience, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(Phalcon_Security_JWT_Builder, getClaims, arginfo_phalcon_security_jwt_builder_getclaims, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, getContentType, arginfo_phalcon_security_jwt_builder_getcontenttype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, getExpirationTime, arginfo_phalcon_security_jwt_builder_getexpirationtime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, getHeaders, arginfo_phalcon_security_jwt_builder_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, getId, arginfo_phalcon_security_jwt_builder_getid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, getIssuedAt, arginfo_phalcon_security_jwt_builder_getissuedat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, getIssuer, arginfo_phalcon_security_jwt_builder_getissuer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, getNotBefore, arginfo_phalcon_security_jwt_builder_getnotbefore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, getSubject, arginfo_phalcon_security_jwt_builder_getsubject, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, getToken, arginfo_phalcon_security_jwt_builder_gettoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, getPassphrase, arginfo_phalcon_security_jwt_builder_getpassphrase, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, setAudience, arginfo_phalcon_security_jwt_builder_setaudience, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, setContentType, arginfo_phalcon_security_jwt_builder_setcontenttype, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, setExpirationTime, arginfo_phalcon_security_jwt_builder_setexpirationtime, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, setId, arginfo_phalcon_security_jwt_builder_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, setIssuedAt, arginfo_phalcon_security_jwt_builder_setissuedat, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, setIssuer, arginfo_phalcon_security_jwt_builder_setissuer, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, setNotBefore, arginfo_phalcon_security_jwt_builder_setnotbefore, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, setSubject, arginfo_phalcon_security_jwt_builder_setsubject, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, setPassphrase, arginfo_phalcon_security_jwt_builder_setpassphrase, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security_JWT_Builder, setClaim, arginfo_phalcon_security_jwt_builder_setclaim, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
