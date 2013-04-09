
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

extern zend_class_entry *phalcon_encrypt_ce;

PHALCON_INIT_CLASS(Phalcon_Encrypt);

PHP_METHOD(Phalcon_Encrypt, setCipher);
PHP_METHOD(Phalcon_Encrypt, getCipher);
PHP_METHOD(Phalcon_Encrypt, setMode);
PHP_METHOD(Phalcon_Encrypt, getMode);
PHP_METHOD(Phalcon_Encrypt, setKey);
PHP_METHOD(Phalcon_Encrypt, getKey);
PHP_METHOD(Phalcon_Encrypt, encrypt);
PHP_METHOD(Phalcon_Encrypt, decrypt);
PHP_METHOD(Phalcon_Encrypt, encryptBase64);
PHP_METHOD(Phalcon_Encrypt, decryptBase64);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encrypt_setcipher, 0, 0, 1)
	ZEND_ARG_INFO(0, cipher)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encrypt_setmode, 0, 0, 1)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encrypt_setkey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encrypt_encrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encrypt_decrypt, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encrypt_encryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_encrypt_decryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_encrypt_method_entry){
	PHP_ME(Phalcon_Encrypt, setCipher, arginfo_phalcon_encrypt_setcipher, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Encrypt, getCipher, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Encrypt, setMode, arginfo_phalcon_encrypt_setmode, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Encrypt, getMode, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Encrypt, setKey, arginfo_phalcon_encrypt_setkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Encrypt, getKey, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Encrypt, encrypt, arginfo_phalcon_encrypt_encrypt, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Encrypt, decrypt, arginfo_phalcon_encrypt_decrypt, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Encrypt, encryptBase64, arginfo_phalcon_encrypt_encryptbase64, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Encrypt, decryptBase64, arginfo_phalcon_encrypt_decryptbase64, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

