
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

extern zend_class_entry *phalcon_crypt_ce;

PHALCON_INIT_CLASS(Phalcon_Crypt);

PHP_METHOD(Phalcon_Crypt, setCipher);
PHP_METHOD(Phalcon_Crypt, getCipher);
PHP_METHOD(Phalcon_Crypt, setMode);
PHP_METHOD(Phalcon_Crypt, getMode);
PHP_METHOD(Phalcon_Crypt, setKey);
PHP_METHOD(Phalcon_Crypt, getKey);
PHP_METHOD(Phalcon_Crypt, encrypt);
PHP_METHOD(Phalcon_Crypt, decrypt);
PHP_METHOD(Phalcon_Crypt, encryptBase64);
PHP_METHOD(Phalcon_Crypt, decryptBase64);
PHP_METHOD(Phalcon_Crypt, getAvailableCiphers);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_setcipher, 0, 0, 1)
	ZEND_ARG_INFO(0, cipher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_setmode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_setkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_encrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_decrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_encryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_decryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_crypt_method_entry){
	PHP_ME(Phalcon_Crypt, setCipher, arginfo_phalcon_crypt_setcipher, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, getCipher, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, setMode, arginfo_phalcon_crypt_setmode, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, getMode, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, setKey, arginfo_phalcon_crypt_setkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, getKey, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, encrypt, arginfo_phalcon_crypt_encrypt, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, decrypt, arginfo_phalcon_crypt_decrypt, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, encryptBase64, arginfo_phalcon_crypt_encryptbase64, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, decryptBase64, arginfo_phalcon_crypt_decryptbase64, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, getAvailableCiphers, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

