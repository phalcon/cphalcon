
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Interface for Phalcon\Crypt
 */
ZEPHIR_INIT_CLASS(Phalcon_Crypt_CryptInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Crypt, CryptInterface, phalcon, crypt_cryptinterface, phalcon_crypt_cryptinterface_method_entry);

	return SUCCESS;
}

/**
 * Decrypts a text
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, decrypt);
/**
 * Decrypt a text that is coded as a base64 string
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, decryptBase64);
/**
 * Encrypts a text
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, encrypt);
/**
 * Encrypts a text returning the result as a base64 string
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, encryptBase64);
/**
 * Returns a list of available cyphers
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, getAvailableCiphers);
/**
 * Returns the authentication tag
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, getAuthTag);
/**
 * Returns authentication data
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, getAuthData);
/**
 * Returns the authentication tag length
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, getAuthTagLength);
/**
 * Returns the current cipher
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, getCipher);
/**
 * Returns the encryption key
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, getKey);
/**
 * Sets the authentication tag
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, setAuthTag);
/**
 * Sets authentication data
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, setAuthData);
/**
 * Sets the authentication tag length
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, setAuthTagLength);
/**
 * Sets the cipher algorithm
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, setCipher);
/**
 * Sets the encryption key
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, setKey);
/**
 * Changes the padding scheme used.
 */
ZEPHIR_DOC_METHOD(Phalcon_Crypt_CryptInterface, setPadding);
