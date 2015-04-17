
<<<<<<< HEAD:ext/phalcon/security.zep.h
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
PHP_METHOD(Phalcon_Security, computeHmac);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setworkfactor, 0, 0, 1)
	ZEND_ARG_INFO(0, workFactor)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setdi, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_setrandombytes, 0, 0, 1)
	ZEND_ARG_INFO(0, randomBytes)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_islegacyhash, 0, 0, 2)
	ZEND_ARG_INFO(0, password)
	ZEND_ARG_INFO(0, passwordHash)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_gettokenkey, 0, 0, 0)
	ZEND_ARG_INFO(0, numberBytes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_gettoken, 0, 0, 0)
	ZEND_ARG_INFO(0, numberBytes)
ZEND_END_ARG_INFO()
=======
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_SECURITY_H
#define PHALCON_SECURITY_H

#include "php_phalcon.h"

extern zend_class_entry *phalcon_security_ce;
>>>>>>> master:ext/security.h

#define PHALCON_SECURITY_CRYPT_DEFAULT          0
#define PHALCON_SECURITY_CRYPT_STD_DES          1
#define PHALCON_SECURITY_CRYPT_EXT_DES          2
#define PHALCON_SECURITY_CRYPT_MD5              3
#define PHALCON_SECURITY_CRYPT_BLOWFISH         4
#define PHALCON_SECURITY_CRYPT_BLOWFISH_X       5
#define PHALCON_SECURITY_CRYPT_BLOWFISH_Y       6
#define PHALCON_SECURITY_CRYPT_SHA256           7
#define PHALCON_SECURITY_CRYPT_SHA512           8

<<<<<<< HEAD:ext/phalcon/security.zep.h
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_security_computehmac, 0, 0, 3)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, algo)
	ZEND_ARG_INFO(0, raw)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_security_method_entry) {
	PHP_ME(Phalcon_Security, setWorkFactor, arginfo_phalcon_security_setworkfactor, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getWorkFactor, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, setDI, arginfo_phalcon_security_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, setRandomBytes, arginfo_phalcon_security_setrandombytes, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getRandomBytes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getSaltBytes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, hash, arginfo_phalcon_security_hash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, checkHash, arginfo_phalcon_security_checkhash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, isLegacyHash, arginfo_phalcon_security_islegacyhash, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getTokenKey, arginfo_phalcon_security_gettokenkey, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getToken, arginfo_phalcon_security_gettoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, checkToken, arginfo_phalcon_security_checktoken, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, getSessionToken, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Security, computeHmac, arginfo_phalcon_security_computehmac, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
=======
PHALCON_INIT_CLASS(Phalcon_Security);

#endif /* PHALCON_SECURITY_H */
>>>>>>> master:ext/security.h
