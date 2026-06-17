
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Encryption\Crypt;

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
interface Crypt
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
     * @param string|null $key
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
     * @param string|null $key
     *
     * @return string
     */
    public function encryptBase64(string input, string key = null) -> string;

    /**
     * Returns authentication data
     *
     * @return string
     */
    public function getAuthData() -> string;

    /**
     * Returns the authentication tag
     *
     * @return string
     */
    public function getAuthTag() -> string;

    /**
     * Returns the authentication tag length
     *
     * @return int
     */
    public function getAuthTagLength() -> int;

    /**
     * Returns a list of available cyphers
     *
     * @phpstan-return array<array-key, string>
     */
    public function getAvailableCiphers() -> array;

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
     * Sets authentication data
     *
     * @param string $data
     *
     * @return Crypt
     */
    public function setAuthData(string data) -> <Crypt>;

    /**
     * Sets the authentication tag
     *
     * @param string $tag
     *
     * @return Crypt
     */
    public function setAuthTag(string tag) -> <Crypt>;

    /**
     * Sets the authentication tag length
     *
     * @param int $length
     *
     * @return Crypt
     */
    public function setAuthTagLength(int length) -> <Crypt>;

    /**
     * Sets the cipher algorithm
     *
     * @param string $cipher
     *
     * @return Crypt
     */
    public function setCipher(string cipher) -> <Crypt>;

    /**
     * Sets the encryption key
     *
     * @param string $key
     *
     * @return Crypt
     */
    public function setKey(string key) -> <Crypt>;

    /**
     * Changes the padding scheme used.
     *
     * @param int $scheme
     *
     * @return Crypt
     */
    public function setPadding(int scheme) -> <Crypt>;

    /**
     * Sets if the calculating message digest must be used.
     *
     * @param bool $useSigning
     *
     * @return Crypt
     */
    public function useSigning(bool useSigning) -> <Crypt>;
}
