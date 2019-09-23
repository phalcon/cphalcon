
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Crypt;

/**
 * Interface for Phalcon\Crypt
 */
interface CryptInterface
{
    /**
     * Decrypts a text
     */
    public function decrypt(string! text, string! key = null) -> string;

    /**
     * Decrypt a text that is coded as a base64 string
     */
    public function decryptBase64(string! text, key = null) -> string;

    /**
     * Encrypts a text
     */
    public function encrypt(string! text, string! key = null) -> string;

    /**
     * Encrypts a text returning the result as a base64 string
     */
    public function encryptBase64(string! text, key = null) -> string;

    /**
     * Returns a list of available cyphers
     */
    public function getAvailableCiphers() -> array;

    /**
     * Returns the authentication tag
     */
    public function getAuthTag() -> string;

    /**
     * Returns authentication data
     */
    public function getAuthData() -> string;

    /**
     * Returns the authentication tag length
     */
    public function getAuthTagLength() -> int;

    /**
     * Returns the current cipher
     */
    public function getCipher() -> string;

    /**
     * Returns the encryption key
     */
    public function getKey() -> string;

    /**
     * Sets the authentication tag
     */
    public function setAuthTag(string! tag) -> <CryptInterface>;

    /**
     * Sets authentication data
     */
    public function setAuthData(string! data) -> <CryptInterface>;

    /**
     * Sets the authentication tag length
     */
    public function setAuthTagLength(int! length) -> <CryptInterface>;

    /**
     * Sets the cipher algorithm
     */
    public function setCipher(string! cipher) -> <CryptInterface>;

    /**
     * Sets the encryption key
     */
    public function setKey(string! key) -> <CryptInterface>;

    /**
     * Changes the padding scheme used.
     */
    public function setPadding(int! scheme) -> <CryptInterface>;
}
