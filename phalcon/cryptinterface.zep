
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

namespace Phalcon;

/**
 * Phalcon\CryptInterface
 *
 * Interface for Phalcon\Crypt
 */
interface CryptInterface
{

	/**
	 * Sets the cipher algorithm
	 *
	 * @param string cipher
	 * @return Phalcon\EncryptInterface
	 */
	public function setCipher(cipher);

	/**
	 * Returns the current cipher
	 *
	 * @return string
	 */
	public function getCipher();

	/**
	 * Sets the encrypt/decrypt mode
	 *
	 * @param string cipher
	 * @return Phalcon\EncryptInterface
	 */
	public function setMode(mode);

	/**
	 * Returns the current encryption mode
	 *
	 * @return string
	 */
	public function getMode();

	/**
	 * Sets the encryption key
	 *
	 * @param string key
	 * @return Phalcon\EncryptInterface
	 */
	public function setKey(key);

	/**
	 * Returns the encryption key
	 *
	 * @return string
	 */
	public function getKey();

	/**
	 * Encrypts a text
	 *
	 * @param string text
	 * @param string key
	 * @return string
	 */
	public function encrypt(text, key=null);

	/**
	 * Decrypts a text
	 *
	 * @param string text
	 * @param string key
	 * @return string
	 */
	public function decrypt(text, key=null);

	/**
	 * Encrypts a text returning the result as a base64 string
	 *
	 * @param string text
	 * @param string key
	 * @return string
	 */
	public function encryptBase64(text, key=null);

	/**
	 * Decrypt a text that is coded as a base64 string
	 *
	 * @param string text
	 * @param string key
	 * @return string
	 */
	public function decryptBase64(text, key=null);

	/**
	 * Returns a list of available cyphers
	 *
	 * @return array
	 */
	public function getAvailableCiphers();

	/**
	 * Returns a list of available modes
	 *
	 * @return array
	 */
	public function getAvailableModes();

}
