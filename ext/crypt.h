
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

/**
 * @brief mcrypt default padding
 */
#define PHALCON_CRYPT_PADDING_DEFAULT        0
/**
 * @brief ANSI X.923 padding
 * @see http://en.wikipedia.org/wiki/Padding_%28cryptography%29#ANSI_X.923
 */
#define PHALCON_CRYPT_PADDING_ANSI_X_923     1
/**
 * @brief PKCS7 padding
 * @see http://en.wikipedia.org/wiki/Padding_%28cryptography%29#PKCS7
 */
#define PHALCON_CRYPT_PADDING_PKCS7          2
/**
 * @brief ISO 10126 padding
 * @see http://en.wikipedia.org/wiki/Padding_%28cryptography%29#ISO_10126
 */
#define PHALCON_CRYPT_PADDING_ISO_10126      3
/**
 * @brief ISO/IEC 7816-4 padding
 * @see http://en.wikipedia.org/wiki/Padding_%28cryptography%29#ISO.2FIEC_7816-4
 */
#define PHALCON_CRYPT_PADDING_ISO_IEC_7816_4 4
/**
 * @brief Zero padding
 * @see http://en.wikipedia.org/wiki/Padding_%28cryptography%29#Zero_padding
 */
#define PHALCON_CRYPT_PADDING_ZERO           5
#define PHALCON_CRYPT_PADDING_SPACE          6

extern zend_class_entry *phalcon_crypt_ce;

PHALCON_INIT_CLASS(Phalcon_Crypt);

PHP_METHOD(Phalcon_Crypt, setCipher);
PHP_METHOD(Phalcon_Crypt, getCipher);
PHP_METHOD(Phalcon_Crypt, setMode);
PHP_METHOD(Phalcon_Crypt, getMode);
PHP_METHOD(Phalcon_Crypt, setKey);
PHP_METHOD(Phalcon_Crypt, getKey);
PHP_METHOD(Phalcon_Crypt, setPadding);
PHP_METHOD(Phalcon_Crypt, getPadding);
PHP_METHOD(Phalcon_Crypt, encrypt);
PHP_METHOD(Phalcon_Crypt, decrypt);
PHP_METHOD(Phalcon_Crypt, encryptBase64);
PHP_METHOD(Phalcon_Crypt, decryptBase64);
PHP_METHOD(Phalcon_Crypt, getAvailableCiphers);
PHP_METHOD(Phalcon_Crypt, getAvailableModes);

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
	ZEND_ARG_INFO(0, safe)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_decryptbase64, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, safe)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_getpadding, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_crypt_setpadding, 0, 0, 1)
	ZEND_ARG_INFO(0, scheme)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_crypt_method_entry){
	PHP_ME(Phalcon_Crypt, setCipher, arginfo_phalcon_crypt_setcipher, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, getCipher, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, setMode, arginfo_phalcon_crypt_setmode, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, getMode, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, setKey, arginfo_phalcon_crypt_setkey, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, getKey, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, setPadding, arginfo_phalcon_crypt_setpadding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, getPadding, arginfo_phalcon_crypt_getpadding, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Crypt, encrypt, arginfo_phalcon_crypt_encrypt, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, decrypt, arginfo_phalcon_crypt_decrypt, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, encryptBase64, arginfo_phalcon_crypt_encryptbase64, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, decryptBase64, arginfo_phalcon_crypt_decryptbase64, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, getAvailableCiphers, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Crypt, getAvailableModes, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

