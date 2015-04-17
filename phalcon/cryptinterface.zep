
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
	 */
	public function setCipher(string! cipher) -> <CryptInterface>;

	/**
	 * Returns the current cipher
	 */
	public function getCipher() -> string;

	/**
	 * Sets the encrypt/decrypt mode
	 */
	public function setMode(string! mode) -> <CryptInterface>;

	/**
	 * Returns the current encryption mode
	 */
	public function getMode() -> string;

	/**
	 * Sets the encryption key
	 */
	public function setKey(string! key) -> <CryptInterface>;

	/**
	 * Returns the encryption key
	 */
	public function getKey() -> string;

	/**
	 * Encrypts a text
	 */
	public function encrypt(string! text, key = null) -> string;

	/**
	 * Decrypts a text
	 */
	public function decrypt(string! text, string! key = null) -> string;

	/**
	 * Encrypts a text returning the result as a base64 string
	 */
	public function encryptBase64(string! text, key = null) -> string;

	/**
	 * Decrypt a text that is coded as a base64 string
	 */
	public function decryptBase64(string! text, key = null) -> string;

	/**
	 * Returns a list of available cyphers
	 */
	public function getAvailableCiphers() -> array;

	/**
	 * Returns a list of available modes
	 */
	public function getAvailableModes() -> array;
}
