
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

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
 * Canonical contract for Phalcon\Encryption\Crypt.
 *
 * The encrypted payload produced by `encrypt()` uses the wire format:
 *
 *     iv ‖ hmac ‖ ciphertext ‖ tag
 *
 * where `hmac` is present only when signing is enabled (`useSigning(true)`,
 * the default) and `tag` is present only for AEAD ciphers (`gcm`/`ccm`).
 *
 * The AEAD parameters (`authData`, `authTag`, `authTagLength`) are instance
 * state set through the relevant setters and shared across every
 * `encrypt()`/`decrypt()` call on the instance. A `Crypt` service shared
 * through the DI container is therefore not safe for interleaved AEAD
 * operations.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Encryption_Crypt_Crypt)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Encryption\\Crypt, Crypt, phalcon, contracts_encryption_crypt_crypt, phalcon_contracts_encryption_crypt_crypt_method_entry);

	return SUCCESS;
}

/**
 * Decrypts a text
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, decrypt);
/**
 * Decrypt a text that is coded as a base64 string
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, decryptBase64);
/**
 * Encrypts a text
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, encrypt);
/**
 * Encrypts a text returning the result as a base64 string
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, encryptBase64);
/**
 * Returns authentication data
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, getAuthData);
/**
 * Returns the authentication tag
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, getAuthTag);
/**
 * Returns the authentication tag length
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, getAuthTagLength);
/**
 * Returns a list of available cyphers
 *
 * @phpstan-return array<array-key, string>
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, getAvailableCiphers);
/**
 * Returns the current cipher
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, getCipher);
/**
 * Returns the encryption key
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, getKey);
/**
 * Sets authentication data
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, setAuthData);
/**
 * Sets the authentication tag
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, setAuthTag);
/**
 * Sets the authentication tag length
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, setAuthTagLength);
/**
 * Sets the cipher algorithm
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, setCipher);
/**
 * Sets the encryption key
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, setKey);
/**
 * Changes the padding scheme used.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, setPadding);
/**
 * Sets if the calculating message digest must be used.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Crypt_Crypt, useSigning);
