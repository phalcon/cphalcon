
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
     *
     * @param string      $input
     * @param string|null $key
     *
     * @return string
     */
    public function decrypt(string input, string key = null) -> string;

    /**
     * Decrypt a text that is coded as a base64 string
     *
     * @param string      $input
     * @param strubg|null $key
     *
     * @return string
     */
    public function decryptBase64(string input, string key = null) -> string;

    /**
     * Encrypts a text
     *
     * @param string      $input
     * @param string|null $key
     *
     * @return string
     */
    public function encrypt(string input, string key = null) -> string;

    /**
     * Encrypts a text returning the result as a base64 string
     *
     * @param string      $input
     * @param strubg|null $key
     *
     * @return string
     */
    public function encryptBase64(string input, string key = null) -> string;

    /**
     * Returns a list of available cyphers
     *
     * @return array
     */
    public function getAvailableCiphers() -> array;

    /**
     * Returns the authentication tag
     *
     * @return string
     */
    public function getAuthTag() -> string;

    /**
     * Returns authentication data
     *
     * @return string
     */
    public function getAuthData() -> string;

    /**
     * Returns the authentication tag length
     *
     * @return int
     */
    public function getAuthTagLength() -> int;

    /**
     * Returns the current cipher
     *
     * @return string
     */
    public function getCipher() -> string;

    /**
     * Returns the encryption key
     *
     * @return string
     */
    public function getKey() -> string;

    /**
     * Sets the authentication tag
     *
     * @param string $tag
     *
     * @return CryptInterface
     */
    public function setAuthTag(string tag) -> <CryptInterface>;

    /**
     * Sets authentication data
     *
     * @param string $data
     *
     * @return CryptInterface
     */
    public function setAuthData(string data) -> <CryptInterface>;

    /**
     * Sets the authentication tag length
     *
     * @param int $length
     *
     * @return CryptInterface
     */
    public function setAuthTagLength(int length) -> <CryptInterface>;

    /**
     * Sets the cipher algorithm
     *
     * @param string $cipher
     *
     * @return CryptInterface
     */
    public function setCipher(string cipher) -> <CryptInterface>;

    /**
     * Sets the encryption key
     *
     * @param string $key
     *
     * @return CryptInterface
     */
    public function setKey(string key) -> <CryptInterface>;

    /**
     * Changes the padding scheme used.
     *
     * @param int $scheme
     *
     * @return CryptInterface
     */
    public function setPadding(int scheme) -> <CryptInterface>;

    /**
     * Sets if the calculating message digest must be used.
     *
     * @param bool $useSigning
     *
     * @return CryptInterface
     */
    public function useSigning(bool useSigning) -> <CryptInterface>;
}
