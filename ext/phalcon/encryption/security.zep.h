
extern zend_class_entry *phalcon_encryption_security_ce;

ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security);

PHP_METHOD(Phalcon_Encryption_Security, getWorkFactor);
PHP_METHOD(Phalcon_Encryption_Security, __construct);
PHP_METHOD(Phalcon_Encryption_Security, checkHash);
PHP_METHOD(Phalcon_Encryption_Security, checkToken);
PHP_METHOD(Phalcon_Encryption_Security, computeHmac);
PHP_METHOD(Phalcon_Encryption_Security, destroyToken);
PHP_METHOD(Phalcon_Encryption_Security, getDefaultHash);
PHP_METHOD(Phalcon_Encryption_Security, getHashInformation);
PHP_METHOD(Phalcon_Encryption_Security, getRandom);
PHP_METHOD(Phalcon_Encryption_Security, getRandomBytes);
PHP_METHOD(Phalcon_Encryption_Security, getRequestToken);
PHP_METHOD(Phalcon_Encryption_Security, getSessionToken);
PHP_METHOD(Phalcon_Encryption_Security, getSaltBytes);
PHP_METHOD(Phalcon_Encryption_Security, getToken);
PHP_METHOD(Phalcon_Encryption_Security, getTokenKey);
PHP_METHOD(Phalcon_Encryption_Security, hash);
PHP_METHOD(Phalcon_Encryption_Security, isLegacyHash);
PHP_METHOD(Phalcon_Encryption_Security, setDefaultHash);
PHP_METHOD(Phalcon_Encryption_Security, setRandomBytes);
PHP_METHOD(Phalcon_Encryption_Security, setWorkFactor);
PHP_METHOD(Phalcon_Encryption_Security, getLocalService);
PHP_METHOD(Phalcon_Encryption_Security, processAlgorithm);
PHP_METHOD(Phalcon_Encryption_Security, processArgonOptions);
PHP_METHOD(Phalcon_Encryption_Security, processCost);
PHP_METHOD(Phalcon_Encryption_Security, processTokenKey);
PHP_METHOD(Phalcon_Encryption_Security, processUserToken);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_getworkfactor, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encryption_security___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, session, Phalcon\\Session\\ManagerInterface, 1)
	ZEND_ARG_OBJ_INFO(0, request, Phalcon\\Http\\RequestInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_checkhash, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, password, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, passwordHash, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, maxPassLength, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_checktoken, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tokenKey, IS_STRING, 1)
	ZEND_ARG_INFO(0, tokenValue)
	ZEND_ARG_TYPE_INFO(0, destroyIfValid, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_computehmac, 0, 3, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, algo, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, raw, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_destroytoken, 0, 0, Phalcon\\Encryption\\Security, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_getdefaulthash, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_gethashinformation, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, hash, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_getrandom, 0, 0, Phalcon\\Encryption\\Security\\Random, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_getrandombytes, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_getrequesttoken, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_getsessiontoken, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_getsaltbytes, 0, 0, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, numberBytes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_gettoken, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_gettokenkey, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_hash, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, password, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_islegacyhash, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, passwordHash, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_setdefaulthash, 0, 1, Phalcon\\Encryption\\Security, 0)
	ZEND_ARG_TYPE_INFO(0, defaultHash, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_setrandombytes, 0, 1, Phalcon\\Encryption\\Security, 0)
	ZEND_ARG_TYPE_INFO(0, randomBytes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_encryption_security_setworkfactor, 0, 1, Phalcon\\Encryption\\Security, 0)
	ZEND_ARG_TYPE_INFO(0, workFactor, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encryption_security_getlocalservice, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_processalgorithm, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_processargonoptions, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_processcost, 0, 0, IS_LONG, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, options, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, options, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_processtokenkey, 0, 0, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, tokenKey, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_encryption_security_processusertoken, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, tokenKey, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, tokenValue, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_encryption_security_method_entry) {
	PHP_ME(Phalcon_Encryption_Security, getWorkFactor, arginfo_phalcon_encryption_security_getworkfactor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, __construct, arginfo_phalcon_encryption_security___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Encryption_Security, checkHash, arginfo_phalcon_encryption_security_checkhash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, checkToken, arginfo_phalcon_encryption_security_checktoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, computeHmac, arginfo_phalcon_encryption_security_computehmac, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, destroyToken, arginfo_phalcon_encryption_security_destroytoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, getDefaultHash, arginfo_phalcon_encryption_security_getdefaulthash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, getHashInformation, arginfo_phalcon_encryption_security_gethashinformation, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, getRandom, arginfo_phalcon_encryption_security_getrandom, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, getRandomBytes, arginfo_phalcon_encryption_security_getrandombytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, getRequestToken, arginfo_phalcon_encryption_security_getrequesttoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, getSessionToken, arginfo_phalcon_encryption_security_getsessiontoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, getSaltBytes, arginfo_phalcon_encryption_security_getsaltbytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, getToken, arginfo_phalcon_encryption_security_gettoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, getTokenKey, arginfo_phalcon_encryption_security_gettokenkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, hash, arginfo_phalcon_encryption_security_hash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, isLegacyHash, arginfo_phalcon_encryption_security_islegacyhash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, setDefaultHash, arginfo_phalcon_encryption_security_setdefaulthash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, setRandomBytes, arginfo_phalcon_encryption_security_setrandombytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, setWorkFactor, arginfo_phalcon_encryption_security_setworkfactor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Encryption_Security, getLocalService, arginfo_phalcon_encryption_security_getlocalservice, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Encryption_Security, processAlgorithm, arginfo_phalcon_encryption_security_processalgorithm, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Encryption_Security, processArgonOptions, arginfo_phalcon_encryption_security_processargonoptions, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Encryption_Security, processCost, arginfo_phalcon_encryption_security_processcost, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Encryption_Security, processTokenKey, arginfo_phalcon_encryption_security_processtokenkey, ZEND_ACC_PRIVATE)
	PHP_ME(Phalcon_Encryption_Security, processUserToken, arginfo_phalcon_encryption_security_processusertoken, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
