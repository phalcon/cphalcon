
extern zend_class_entry *phalcon_security_ce;

ZEPHIR_INIT_CLASS(Phalcon_Security);

PHP_METHOD(Phalcon_Security, getWorkFactor);
PHP_METHOD(Phalcon_Security, __construct);
PHP_METHOD(Phalcon_Security, checkHash);
PHP_METHOD(Phalcon_Security, checkToken);
PHP_METHOD(Phalcon_Security, computeHmac);
PHP_METHOD(Phalcon_Security, destroyToken);
PHP_METHOD(Phalcon_Security, getDefaultHash);
PHP_METHOD(Phalcon_Security, getRandom);
PHP_METHOD(Phalcon_Security, getRandomBytes);
PHP_METHOD(Phalcon_Security, getRequestToken);
PHP_METHOD(Phalcon_Security, getSessionToken);
PHP_METHOD(Phalcon_Security, getSaltBytes);
PHP_METHOD(Phalcon_Security, getToken);
PHP_METHOD(Phalcon_Security, getTokenKey);
PHP_METHOD(Phalcon_Security, hash);
PHP_METHOD(Phalcon_Security, isLegacyHash);
PHP_METHOD(Phalcon_Security, setDefaultHash);
PHP_METHOD(Phalcon_Security, setRandomBytes);
PHP_METHOD(Phalcon_Security, setWorkFactor);
PHP_METHOD(Phalcon_Security, getLocalRequest);
PHP_METHOD(Phalcon_Security, getLocalSession);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_getworkfactor, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, session, Phalcon\\Session\\ManagerInterface, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_checkhash, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, password, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, passwordHash, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, maxPassLength, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_checktoken, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, tokenKey)
	ZEND_ARG_INFO(0, tokenValue)
	ZEND_ARG_TYPE_INFO(0, destroyIfValid, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_computehmac, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, algo, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_destroytoken, 0, 0, Phalcon\\Security, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_getdefaulthash, 0, 0, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_getrandom, 0, 0, Phalcon\\Security\\Random, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_getrandombytes, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_getrequesttoken, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_getsessiontoken, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_getsaltbytes, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, numberBytes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_gettoken, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_gettokenkey, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_hash, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, password, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, workFactor, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_security_islegacyhash, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, passwordHash, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_setdefaulthash, 0, 1, Phalcon\\Security, 0)
	ZEND_ARG_TYPE_INFO(0, defaultHash, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_setrandombytes, 0, 1, Phalcon\\Security, 0)
	ZEND_ARG_TYPE_INFO(0, randomBytes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_setworkfactor, 0, 1, Phalcon\\Security, 0)
	ZEND_ARG_TYPE_INFO(0, workFactor, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_getlocalrequest, 0, 0, Phalcon\\Http\\RequestInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_security_getlocalsession, 0, 0, Phalcon\\Session\\ManagerInterface, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_security_method_entry) {
	PHP_ME(Phalcon_Security, getWorkFactor, arginfo_phalcon_security_getworkfactor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, __construct, arginfo_phalcon_security___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Security, checkHash, arginfo_phalcon_security_checkhash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, checkToken, arginfo_phalcon_security_checktoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, computeHmac, arginfo_phalcon_security_computehmac, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, destroyToken, arginfo_phalcon_security_destroytoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getDefaultHash, arginfo_phalcon_security_getdefaulthash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getRandom, arginfo_phalcon_security_getrandom, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getRandomBytes, arginfo_phalcon_security_getrandombytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getRequestToken, arginfo_phalcon_security_getrequesttoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getSessionToken, arginfo_phalcon_security_getsessiontoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getSaltBytes, arginfo_phalcon_security_getsaltbytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getToken, arginfo_phalcon_security_gettoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getTokenKey, arginfo_phalcon_security_gettokenkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, hash, arginfo_phalcon_security_hash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, isLegacyHash, arginfo_phalcon_security_islegacyhash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, setDefaultHash, arginfo_phalcon_security_setdefaulthash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, setRandomBytes, arginfo_phalcon_security_setrandombytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, setWorkFactor, arginfo_phalcon_security_setworkfactor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getLocalRequest, arginfo_phalcon_security_getlocalrequest, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Security, getLocalSession, arginfo_phalcon_security_getlocalsession, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
