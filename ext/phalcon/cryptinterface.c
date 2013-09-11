
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_test.h"
#include "test.h"

#include "kernel/main.h"


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
 * Phalcon\CryptInterface
 *
 * Interface for Phalcon\Crypt
 */
ZEPHIR_INIT_CLASS(Phalcon_CryptInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon, CryptInterface, phalcon, cryptinterface, phalcon_cryptinterface_method_entry);


	return SUCCESS;

}

/**
 * Sets the cipher algorithm
 *
 * @param string cipher
 * @return Phalcon\EncryptInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, setCipher);
/**
 * Returns the current cipher
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, getCipher);
/**
 * Sets the encrypt/decrypt mode
 *
 * @param string cipher
 * @return Phalcon\EncryptInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, setMode);
/**
 * Returns the current encryption mode
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, getMode);
/**
 * Sets the encryption key
 *
 * @param string key
 * @return Phalcon\EncryptInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, setKey);
/**
 * Returns the encryption key
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, getKey);
/**
 * Encrypts a text
 *
 * @param string text
 * @param string key
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, encrypt);
/**
 * Decrypts a text
 *
 * @param string text
 * @param string key
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, decrypt);
/**
 * Encrypts a text returning the result as a base64 string
 *
 * @param string text
 * @param string key
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, encryptBase64);
/**
 * Decrypt a text that is coded as a base64 string
 *
 * @param string text
 * @param string key
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, decryptBase64);
/**
 * Returns a list of available cyphers
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, getAvailableCiphers);
/**
 * Returns a list of available modes
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, getAvailableModes);
