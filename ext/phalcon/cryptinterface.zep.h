
<<<<<<< HEAD:ext/phalcon/cryptinterface.zep.h
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

#ifndef PHALCON_CRYPTINTERFACE_H
#define PHALCON_CRYPTINTERFACE_H

#include "php_phalcon.h"

>>>>>>> master:ext/cryptinterface.h
extern zend_class_entry *phalcon_cryptinterface_ce;

ZEPHIR_INIT_CLASS(Phalcon_CryptInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_setcipher, 0, 0, 1)
	ZEND_ARG_INFO(0, cipher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_setmode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_setkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_encrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_decrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_encryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, safe)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_cryptinterface_decryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, safe)
ZEND_END_ARG_INFO()

<<<<<<< HEAD:ext/phalcon/cryptinterface.zep.h
ZEPHIR_INIT_FUNCS(phalcon_cryptinterface_method_entry) {
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, setCipher, arginfo_phalcon_cryptinterface_setcipher)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getCipher, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, setMode, arginfo_phalcon_cryptinterface_setmode)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getMode, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, setKey, arginfo_phalcon_cryptinterface_setkey)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getKey, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, encrypt, arginfo_phalcon_cryptinterface_encrypt)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, decrypt, arginfo_phalcon_cryptinterface_decrypt)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, encryptBase64, arginfo_phalcon_cryptinterface_encryptbase64)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, decryptBase64, arginfo_phalcon_cryptinterface_decryptbase64)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getAvailableCiphers, NULL)
	PHP_ABSTRACT_ME(Phalcon_CryptInterface, getAvailableModes, NULL)
  PHP_FE_END
};
=======
#endif /* PHALCON_CRYPTINTERFACE_H */
>>>>>>> master:ext/cryptinterface.h
