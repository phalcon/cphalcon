
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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

