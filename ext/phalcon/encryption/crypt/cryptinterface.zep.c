
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

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
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_CryptInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Encryption\\Crypt, CryptInterface, phalcon, encryption_crypt_cryptinterface, phalcon_encryption_crypt_cryptinterface_method_entry);

	return SUCCESS;
}

/**
 * Decrypts a text
 *
 * @param string      $input
 * @param string|null $key
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, decrypt);
/**
 * Decrypt a text that is coded as a base64 string
 *
 * @param string      $input
 * @param string|null $key
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, decryptBase64);
/**
 * Encrypts a text
 *
 * @param string      $input
 * @param string|null $key
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, encrypt);
/**
 * Encrypts a text returning the result as a base64 string
 *
 * @param string      $input
 * @param string|null $key
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, encryptBase64);
/**
 * Returns a list of available cyphers
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, getAvailableCiphers);
/**
 * Returns the authentication tag
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, getAuthTag);
/**
 * Returns authentication data
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, getAuthData);
/**
 * Returns the authentication tag length
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, getAuthTagLength);
/**
 * Returns the current cipher
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, getCipher);
/**
 * Returns the encryption key
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, getKey);
/**
 * Sets the authentication tag
 *
 * @param string $tag
 *
 * @return CryptInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, setAuthTag);
/**
 * Sets authentication data
 *
 * @param string $data
 *
 * @return CryptInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, setAuthData);
/**
 * Sets the authentication tag length
 *
 * @param int $length
 *
 * @return CryptInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, setAuthTagLength);
/**
 * Sets the cipher algorithm
 *
 * @param string $cipher
 *
 * @return CryptInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, setCipher);
/**
 * Sets the encryption key
 *
 * @param string $key
 *
 * @return CryptInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, setKey);
/**
 * Changes the padding scheme used.
 *
 * @param int $scheme
 *
 * @return CryptInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, setPadding);
/**
 * Sets if the calculating message digest must be used.
 *
 * @param bool $useSigning
 *
 * @return CryptInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_CryptInterface, useSigning);
