
extern zend_class_entry *phalcon_security_ce;

ZEPHIR_INIT_CLASS(Phalcon_Security);

PHP_METHOD(Phalcon_Security, setWorkFactor);
PHP_METHOD(Phalcon_Security, getWorkFactor);
PHP_METHOD(Phalcon_Security, setDI);
PHP_METHOD(Phalcon_Security, getDI);
PHP_METHOD(Phalcon_Security, setRandomBytes);
PHP_METHOD(Phalcon_Security, getRandomBytes);
PHP_METHOD(Phalcon_Security, getSaltBytes);
PHP_METHOD(Phalcon_Security, hash);
PHP_METHOD(Phalcon_Security, checkHash);
PHP_METHOD(Phalcon_Security, isLegacyHash);
PHP_METHOD(Phalcon_Security, getTokenKey);
PHP_METHOD(Phalcon_Security, getToken);
PHP_METHOD(Phalcon_Security, checkToken);
PHP_METHOD(Phalcon_Security, getSessionToken);
PHP_METHOD(Phalcon_Security, destroyToken);
PHP_METHOD(Phalcon_Security, computeHmac);
PHP_METHOD(Phalcon_Security, setDefaultHash);
PHP_METHOD(Phalcon_Security, getDefaultHash);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setworkfactor, 0, 0, 1)
	ZEND_ARG_INFO(0, workFactor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setrandombytes, 0, 0, 1)
	ZEND_ARG_INFO(0, randomBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_getsaltbytes, 0, 0, 0)
	ZEND_ARG_INFO(0, numberBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_hash, 0, 0, 1)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, workFactor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_checkhash, 0, 0, 2)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, passwordHash)
	ZEND_ARG_INFO(0, maxPassLength)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_islegacyhash, 0, 0, 1)
	ZEND_ARG_INFO(0, passwordHash)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_gettokenkey, 0, 0, 0)
	ZEND_ARG_INFO(0, numberBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_gettoken, 0, 0, 0)
	ZEND_ARG_INFO(0, numberBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_checktoken, 0, 0, 0)
	ZEND_ARG_INFO(0, tokenKey)
	ZEND_ARG_INFO(0, tokenValue)
	ZEND_ARG_INFO(0, destroyIfValid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_computehmac, 0, 0, 3)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, algo)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setdefaulthash, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultHash)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_security_method_entry) {
	PHP_ME(Phalcon_Security, setWorkFactor, arginfo_phalcon_security_setworkfactor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getWorkFactor, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, setDI, arginfo_phalcon_security_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, setRandomBytes, arginfo_phalcon_security_setrandombytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getRandomBytes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getSaltBytes, arginfo_phalcon_security_getsaltbytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, hash, arginfo_phalcon_security_hash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, checkHash, arginfo_phalcon_security_checkhash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, isLegacyHash, arginfo_phalcon_security_islegacyhash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getTokenKey, arginfo_phalcon_security_gettokenkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getToken, arginfo_phalcon_security_gettoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, checkToken, arginfo_phalcon_security_checktoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getSessionToken, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, destroyToken, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, computeHmac, arginfo_phalcon_security_computehmac, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, setDefaultHash, arginfo_phalcon_security_setdefaulthash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getDefaultHash, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
