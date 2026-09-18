
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
     */
    public function decrypt(string input, string key = null) -> string;

    /**
     * Decrypt a text that is coded as a base64 string
     */
    public function decryptBase64(string input, string key = null) -> string;

    /**
     * Encrypts a text
     */
    public function encrypt(string input, string key = null) -> string;

    /**
     * Encrypts a text returning the result as a base64 string
     */
    public function encryptBase64(string input, string key = null) -> string;

    /**
     * Returns authentication data
     */
    public function getAuthData() -> string;

    /**
     * Returns the authentication tag
     */
    public function getAuthTag() -> string;

    /**
     * Returns the authentication tag length
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
     */
    public function getCipher() -> string;

    /**
     * Returns the encryption key
     */
    public function getKey() -> string;

    /**
     * Sets authentication data
     */
    public function setAuthData(string data) -> <Crypt>;

    /**
     * Sets the authentication tag
     */
    public function setAuthTag(string tag) -> <Crypt>;

    /**
     * Sets the authentication tag length
     */
    public function setAuthTagLength(int length) -> <Crypt>;

    /**
     * Sets the cipher algorithm
     */
    public function setCipher(string cipher) -> <Crypt>;

    /**
     * Sets the encryption key
     */
    public function setKey(string key) -> <Crypt>;

    /**
     * Changes the padding scheme used.
     */
    public function setPadding(int scheme) -> <Crypt>;

    /**
     * Sets if the calculating message digest must be used.
     */
    public function useSigning(bool useSigning) -> <Crypt>;
}
