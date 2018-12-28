
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
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
	 * Changes the padding scheme used.
	 */
	public function setPadding(int! scheme) -> <CryptInterface>;

	/**
	 * Sets the cipher algorithm
	 */
	public function setCipher(string! cipher) -> <CryptInterface>;

	/**
	 * Returns the current cipher
	 */
	public function getCipher() -> string;

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
	public function encrypt(string! text, string! key = null) -> string;

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

}
