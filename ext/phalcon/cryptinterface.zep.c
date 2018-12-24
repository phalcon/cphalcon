
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
 * Changes the padding scheme used.
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, setPadding);

/**
 * Sets the cipher algorithm
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, setCipher);

/**
 * Returns the current cipher
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, getCipher);

/**
 * Sets the encryption key
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, setKey);

/**
 * Returns the encryption key
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, getKey);

/**
 * Encrypts a text
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, encrypt);

/**
 * Decrypts a text
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, decrypt);

/**
 * Encrypts a text returning the result as a base64 string
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, encryptBase64);

/**
 * Decrypt a text that is coded as a base64 string
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, decryptBase64);

/**
 * Returns a list of available cyphers
 */
ZEPHIR_DOC_METHOD(Phalcon_CryptInterface, getAvailableCiphers);

