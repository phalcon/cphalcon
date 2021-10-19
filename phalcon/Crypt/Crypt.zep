
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Crypt;

use Phalcon\Crypt\Exception\Exception;
use Phalcon\Crypt\Exception\Mismatch;
use Phalcon\Crypt\PadFactory;

/**
 * Provides encryption capabilities to Phalcon applications.
 *
 * ```php
 * use Phalcon\Crypt;
 *
 * $crypt = new Crypt();
 *
 * $crypt->setCipher("aes-256-ctr");
 *
 * $key  =
 * "T4\xb1\x8d\xa9\x98\x05\\\x8c\xbe\x1d\x07&[\x99\x18\xa4~Lc1\xbeW\xb3";
 * $input = "The message to be encrypted";
 *
 * $encrypted = $crypt->encrypt($input, $key);
 *
 * echo $crypt->decrypt($encrypted, $key);
 * ```
 */
class Crypt implements CryptInterface
{
    /**
     * Defaults
     */
    const DEFAULT_ALGORITHM = "sha256";
    const DEFAULT_CIPHER    = "aes-256-cfb";

    /**
     * Padding
     */
    const PADDING_ANSI_X_923     = 1;
    const PADDING_DEFAULT        = 0;
    const PADDING_ISO_10126      = 3;
    const PADDING_ISO_IEC_7816_4 = 4;
    const PADDING_PKCS7          = 2;
    const PADDING_SPACE          = 6;
    const PADDING_ZERO           = 5;

    /**
     * @var string
     */
    protected authData = "";

    /**
     * @var string
     */
    protected authTag = "";

    /**
     * @var int
     */
    protected authTagLength = 16;

    /**
     * Available cipher methods.
     *
     * @var array
     */
    protected availableCiphers = [];

    /**
     * @var string
     */
    protected cipher = self::DEFAULT_CIPHER;

    /**
     * The name of hashing algorithm.
     *
     * @var string
     */
    protected hashAlgorithm = self::DEFAULT_ALGORITHM;

    /**
     * The cipher iv length.
     *
     * @var int
     */
    protected ivLength = 16;

    /**
     * @var string
     */
    protected key = "";

    /**
     * @var int
     */
    protected padding = 0;

    /**
     * @var PadFactory
     */
    protected padFactory;

    /**
     * Whether calculating message digest enabled or not.
     *
     * @var bool
     */
    protected useSigning = true;

    /**
     * Crypt constructor.
     *
     * @param string          $cipher
     * @param bool            $useSigning
     * @param PadFactory|null $padFactory
     *
     * @throws Exception
     */
    public function __construct(
        string cipher = self::DEFAULT_CIPHER,
        bool useSigning = true,
        <PadFactory> padFactory = null
    ) {
        if null === padFactory {
            let padFactory = new PadFactory();
        }

        let this->padFactory    = padFactory,
            this->hashAlgorithm = self::DEFAULT_ALGORITHM;

        this
            ->initializeAvailableCiphers()
            ->setCipher(cipher)
            ->useSigning(useSigning)
        ;
    }

    /**
     * Decrypts an encrypted text.
     *
     * ```php
     * $encrypted = $crypt->decrypt(
     *     $encrypted,
     *     "T4\xb1\x8d\xa9\x98\x05\\\x8c\xbe\x1d\x07&[\x99\x18\xa4~Lc1\xbeW\xb3"
     * );
     * ```
     *
     * @param string      $input
     * @param string|null $key
     *
     * @return string
     * @throws Exception
     * @throws Mismatch
     */
    public function decrypt(string input, string key = null) -> string
    {
        var blockSize, cipher, cipherText, decrypted, decryptKey, digest,
            hashAlgorithm, hashLength, iv, ivLength, mode, padded;

        let decryptKey = this->key;
        if true !== empty(key) {
            let decryptKey = key;
        }

        if true === empty(decryptKey) {
            throw new Exception("Decryption key cannot be empty");
        }

        let cipher   = this->cipher,
            ivLength = this->ivLength;

        this->checkCipherHashIsAvailable(cipher, "cipher");

        let mode      = this->getMode(),
            blockSize = this->getBlockSize(mode),
            iv        = mb_substr(input, 0, ivLength, "8bit");

        /**
         * Check if we have chosen to sign and use the hash
         */
        let digest        = "",
            hashAlgorithm = this->getHashAlgorithm();
        if true === this->useSigning {
            let hashLength = strlen(hash(hashAlgorithm, "", true)),
                digest     = mb_substr(input, ivLength, hashLength, "8bit"),
                cipherText = mb_substr(input, ivLength + hashLength, null, "8bit");
        } else {
            let cipherText = mb_substr(input, ivLength, null, "8bit");
        }

        let decrypted = this->decryptGcmCcmAuth(
            mode,
            cipherText,
            decryptKey,
            iv
        );

        /**
         * The variable below keeps the string (not unpadded). It will be used
         * to compare the hash if we use a digest (signed)
         */
        let padded = decrypted;

        let decrypted = this->decryptUnpadCbcEcb(
            mode,
            blockSize,
            decrypted
        );

        if true === this->useSigning {
            /**
             * Checks on the decrypted message digest using the HMAC method.
             */
            if digest !== hash_hmac(hashAlgorithm, padded, decryptKey, true) {
                throw new Mismatch("Hash does not match.");
            }
        }

        return decrypted;
    }

    /**
     * Decrypt a text that is coded as a base64 string.
     *
     * @param string     $input
     * @param mixed|null $key
     * @param bool       $safe
     *
     * @return string
     * @throws Exception
     * @throws Mismatch
     */
    public function decryptBase64(
        string input,
        string key = null,
        bool safe = false
    ) -> string {
        if safe {
            let input = strtr(input, "-_", "+/")
                . substr("===", (strlen(input) + 3) % 4);
        }

        return this->decrypt(base64_decode(input), key);
    }

    /**
     * Encrypts a text.
     *
     * ```php
     * $encrypted = $crypt->encrypt(
     *     "Top secret",
     *     "T4\xb1\x8d\xa9\x98\x05\\\x8c\xbe\x1d\x07&[\x99\x18\xa4~Lc1\xbeW\xb3"
     * );
     * ```
     *
     * @param string      $input
     * @param string|null $key
     *
     * @return string
     * @throws Exception
     */
    public function encrypt(string input, string key = null) -> string
    {
        var blockSize, cipher, digest, encryptKey, encrypted, iv, ivLength,
            mode, padded;

        let encryptKey = this->key;
        if true !== empty(key) {
            let encryptKey = key;
        }

        if true === empty(encryptKey) {
            throw new Exception("Encryption key cannot be empty");
        }

        let cipher   = this->cipher,
            ivLength = this->ivLength;

        this->checkCipherHashIsAvailable(cipher, "cipher");

        let mode      = this->getMode(),
            blockSize = this->getBlockSize(mode),
            iv        = openssl_random_pseudo_bytes(ivLength);

        if false === iv {
            throw new Exception("Cannot calculate Random Pseudo Bytes");
        }

        let padded = this->encryptGetPadded(mode, input, blockSize);

        /**
         * If the mode is "gcm" or "ccm" and auth data has been passed call it
         * with that data
         */
        let encrypted = this->encryptGcmCcm(mode, padded, encryptKey, iv);

        if true === this->useSigning {
            let digest = hash_hmac(
                this->getHashAlgorithm(),
                padded,
                encryptKey,
                true
            );

            return iv . digest . encrypted;
        }

        return iv . encrypted;
    }

    /**
     * Encrypts a text returning the result as a base64 string.
     *
     * @param string     $input
     * @param mixed|null $key
     * @param bool       $safe
     *
     * @return string
     * @throws Exception
     */
    public function encryptBase64(
        string input,
        string key = null,
        bool safe = false
    ) -> string {
        if safe {
            return rtrim(
                strtr(
                    base64_encode(
                        this->encrypt(input, key)
                    ),
                    "+/",
                    "-_"
                ),
                "="
            );
        }

        return base64_encode(this->encrypt(input, key));
    }

    /**
     * Returns a list of available ciphers.
     *
     * @return array
     */
    public function getAvailableCiphers() -> array
    {
        return this->availableCiphers;
    }

    /**
     * Returns the auth data
     *
     * @return string
     */
    public function getAuthData() -> string
    {
        return this->authData;
    }

    /**
     * Returns the auth tag
     *
     * @return string
     */
    public function getAuthTag() -> string
    {
        return this->authTag;
    }

    /**
     * Returns the auth tag length
     *
     * @return int
     */
    public function getAuthTagLength() -> int
    {
        return this->authTagLength;
    }

    /**
     * Return a list of registered hashing algorithms suitable for hash_hmac.
     *
     * @return array
     */
    public function getAvailableHashAlgorithms() -> array
    {
        if true === function_exists("hash_hmac_algos") {
            return hash_hmac_algos();
        }

        return hash_algos();
    }

    /**
     * Get the name of hashing algorithm.
     *
     * @return string
     */
    public function getHashAlgorithm() -> string
    {
        return this->hashAlgorithm;
    }

    /**
     * Returns the current cipher
     *
     * @return string
     */
    public function getCipher() -> string
    {
        return this->cipher;
    }

    /**
     * Returns the encryption key
     *
     * @return string
     */
    public function getKey() -> string
    {
        return this->key;
    }

    /**
     * @param string $data
     *
     * @return CryptInterface
     */
    public function setAuthData(string data) -> <CryptInterface>
    {
        let this->authData = data;

        return this;
    }

    /**
     * @param string $tag
     *
     * @return CryptInterface
     */
    public function setAuthTag(string tag) -> <CryptInterface>
    {
        let this->authTag = tag;

        return this;
    }

    /**
     * @param int $length
     *
     * @return CryptInterface
     */
    public function setAuthTagLength(int length) -> <CryptInterface>
    {
        let this->authTagLength = length;

        return this;
    }

    /**
     * Sets the cipher algorithm for data encryption and decryption.
     *
     * @param string $cipher
     *
     * @return CryptInterface
     * @throws Exception
     */
    public function setCipher(string cipher) -> <CryptInterface>
    {
        this->checkCipherHashIsAvailable(cipher, "cipher");

        let this->ivLength = this->getIvLength(cipher),
            this->cipher   = cipher;

        return this;
    }

    /**
     * Sets the encryption key.
     *
     * The `$key` should have been previously generated in a cryptographically
     * safe way.
     *
     * Bad key:
     * "le password"
     *
     * Better (but still unsafe) ->
     * "#1dj8$=dp?.ak//j1V$~%*0X"
     *
     * Good key:
     * "T4\xb1\x8d\xa9\x98\x05\\\x8c\xbe\x1d\x07&[\x99\x18\xa4~Lc1\xbeW\xb3"
     *
     * @param string $key
     *
     * @return CryptInterface
     */
    public function setKey(string key) -> <CryptInterface>
    {
        let this->key = key;

        return this;
    }

    /**
     * Set the name of hashing algorithm.
     *
     * @param string $hashAlgorithm
     *
     * @return CryptInterface
     * @throws Exception
     */
    public function setHashAlgorithm(string hashAlgorithm) -> <CryptInterface>
    {
        this->checkCipherHashIsAvailable(hashAlgorithm, "hash");

        let this->hashAlgorithm = hashAlgorithm;

        return this;
    }

    /**
     * Changes the padding scheme used.
     *
     * @param int $scheme
     *
     * @return CryptInterface
     */
    public function setPadding(int scheme) -> <CryptInterface>
    {
        let this->padding = scheme;

        return this;
    }

    /**
     * Sets if the calculating message digest must used.
     *
     * @param bool $useSigning
     *
     * @return CryptInterface
     */
    public function useSigning(bool useSigning) -> <CryptInterface>
    {
        let this->useSigning = useSigning;

        return this;
    }

    /**
     * Checks if a cipher or a hash algorithm is available
     *
     * @param string $cipher
     * @param string $type
     *
     * @throws Exception
     */
    protected function checkCipherHashIsAvailable(string cipher, string type) -> void
    {
        var available, lower, method;

        if "hash" === cipher {
            let method = "getAvailableHashAlgorithms";
        } else {
            let method = "getAvailableCiphers";
        }

        let available = this->{method}(),
            lower     = mb_strtolower(cipher);
        if true !== isset(available[lower]) {
            throw new Exception(
                sprintf(
                    "The %s algorithm '%s' is not supported on this system.",
                    type,
                    cipher
                )
            );
        }
    }

    /**
     * Pads texts before encryption. See
     * [cryptopad](https://www.di-mgt.com.au/cryptopad.html)
     *
     * @param string $input
     * @param string $mode
     * @param int    $blockSize
     * @param int    $paddingType
     *
     * @return string
     * @throws Exception
     */
    protected function cryptPadText(
        string input,
        string mode,
        int blockSize,
        int paddingType
    ) -> string {
        var padding, paddingSize, service;

        let padding     = "",
            paddingSize = 0;

        if true === this->checkIsMode(["cbc", "ecb"], mode) {
            let paddingSize = blockSize - (mb_strlen(input) % blockSize);

            if paddingSize >= 256 || paddingSize < 0 {
                throw new Exception(
                    "Padding size cannot be less than 0 or greater than 256"
                );
            }

            let service = this->padFactory->padNumberToService(paddingType),
                padding = this->padFactory->newInstance(service)
                                          ->pad(paddingSize);
        }

        if 0 === paddingSize {
            return input;
        }

        return input . substr(padding, 0, paddingSize);
    }

    /**
     * Removes a padding from a text.
     *
     * If the function detects that the text was not padded, it will return it
     * unmodified.
     *
     * @param string $input
     * @param string $mode
     * @param int    $blockSize
     * @param int    $paddingType
     *
     * @return string
     * @throws Exception
     */
    protected function cryptUnpadText(
        string input,
        string mode,
        int blockSize,
        int paddingType
    ) -> string {
        var length, paddingSize, service;

        let length      = strlen(input),
            paddingSize = 0;

        if (
            length > 0 &&
            (length % blockSize === 0) &&
            true === this->checkIsMode(["cbc", "ecb"], mode)
        ) {
            let service     = this->padFactory->padNumberToService(paddingType),
                paddingSize = this->padFactory->newInstance(service)
                                              ->unpad(input, blockSize);

            if paddingSize > 0 {
                if paddingSize <= blockSize {
                    if paddingSize < length {
                        return substr(input, 0, length - paddingSize);
                    }

                    return "";
                }

                let paddingSize = 0;
            }
        }

        if 0 === paddingSize {
            return input;
        }

        return "";
    }

    /**
     * @param string $mode
     * @param string $cipherText
     * @param string $decryptKey
     * @param string $iv
     *
     * @return string
     * @throws Exception
     */
    protected function decryptGcmCcmAuth(
        string mode,
        string cipherText,
        string decryptKey,
        string iv
    ) -> string {
        var authData, authTag, authTagLength, cipher, encrypted, decrypted;

        let cipher = this->cipher;

        if true === this->checkIsMode(["ccm", "gcm"], mode) {
            let authData      = this->authData,
                authTagLength = this->authTagLength,
                authTag       = substr(cipherText, -authTagLength),
                encrypted     = str_replace(authTag, "", cipherText);

            let decrypted = openssl_decrypt(
                encrypted,
                cipher,
                decryptKey,
                OPENSSL_RAW_DATA,
                iv,
                authTag,
                authData
            );
        } else {
            let decrypted = openssl_decrypt(
                cipherText,
                cipher,
                decryptKey,
                OPENSSL_RAW_DATA,
                iv
            );
        }

        if (false === decrypted) {
            throw new Exception("Could not decrypt data");
        }

        return decrypted;
    }

    /**
     * @param string $mode
     * @param int    $blockSize
     * @param string $cryptText
     *
     * @return string
     * @throws Exception
     */
    protected function decryptUnpadCbcEcb(
        string mode,
        int blockSize,
        string decrypted
    ) -> string {
        var cryptText, padding;

        if true === this->checkIsMode(["cbc", "ecb"], mode) {
            let padding   = this->padding,
                cryptText = this->cryptUnpadText(
                    cryptText,
                    mode,
                    blockSize,
                    padding
                )
            ;
        }

        return cryptText;
    }

    /**
     * @param string $mode
     * @param string $input
     * @param int    $blockSize
     *
     * @return string
     * @throws Exception
     */
    protected function encryptGetPadded(
        string mode,
        string input,
        int blockSize
    ) -> string {
        if (
            0 !== this->padding &&
            true === this->checkIsMode(["cbc", "ecb"], mode)
        ) {
            return this->cryptPadText(input, mode, blockSize, this->padding);
        }

        return input;
    }

    /**
     * @param string $mode
     * @param string $padded
     * @param string $encryptKey
     * @param string $iv
     *
     * @return string
     * @throws Exception
     */
    protected function encryptGcmCcm(
        string mode,
        string padded,
        string encryptKey,
        string iv
    ) -> string {
        var authData, authTag, authTagLength, cipher, encrypted;

        let cipher  = this->cipher,
            authTag = "";

        /**
         * If the mode is "gcm" or "ccm" and auth data has been passed call it
         * with that data
         */
        if true === this->checkIsMode(["ccm", "gcm"], mode) {
            let authData = this->authData;

            if true === empty(authData) {
                throw new Exception(
                    "Auth data must be provided when using AEAD mode"
                );
            }

            let authTag       = this->authTag,
                authTagLength = this->authTagLength;

            let encrypted = openssl_encrypt(
                padded,
                cipher,
                encryptKey,
                OPENSSL_RAW_DATA,
                iv,
                authTag,
                authData,
                authTagLength
            );

            let this->authTag = authTag;
        } else {
            let encrypted = openssl_encrypt(
                padded,
                cipher,
                encryptKey,
                OPENSSL_RAW_DATA,
                iv
            );
        }

        if (false === encrypted) {
            throw new Exception("Could not encrypt data");
        }

        /**
         * Store the tag with encrypted data and return it. In the non AEAD
         * mode this is an empty string
         */
        return encrypted . authTag;
    }

    /**
     * Initialize available cipher algorithms.
     *
     * @return Crypt
     * @throws Exception
     */
    protected function initializeAvailableCiphers() -> <Crypt>
    {
        var available, cipher;
        array allowed;

        if true !== function_exists("openssl_get_cipher_methods") {
            throw new Exception("This class requires the openssl extension for PHP");
        }

        let available = openssl_get_cipher_methods(true),
            allowed   = [];

        for cipher in available {
            if (
                true !== starts_with(cipher, "des") &&
                true !== starts_with(cipher, "rc2") &&
                true !== starts_with(cipher, "rc4") &&
                true !== ends_with(cipher, "ecb")
            ) {
                let allowed[cipher] = cipher;
            }
        }

        let this->availableCiphers = allowed;

        return this;
    }

    /**
     * Checks if a mode (string) is in the values to compare (modes array)
     *
     * @param array  $modes
     * @param string $mode
     *
     * @return bool
     */
    private function checkIsMode(array modes, string mode) -> bool
    {
        return in_array(mode, modes);
    }

    /**
     * Returns the block size
     *
     * @param string $mode
     *
     * @return int
     * @throws Exception
     */
    private function getBlockSize(string mode) -> int
    {
        if this->ivLength > 0 {
            return this->ivLength;
        }

        return this->getIvLength(
            str_ireplace("-" . mode, "", this->cipher)
        );
    }

    /**
     * Initialize available cipher algorithms.
     *
     * @param string $cipher
     *
     * @return int
     * @throws Exception
     */
    private function getIvLength(string cipher) -> int
    {
        var length;

        let length = openssl_cipher_iv_length(cipher);
        if false === length {
            throw new Exception(
                "Cannot calculate the initialization vector (IV) length of the cipher"
            );
        }

        return length;
    }

    /**
     * Returns the mode (last few characters of the cipher)
     *
     * @return string
     */
    private function getMode() -> string
    {
        var position;
        let position = intval(strrpos(this->cipher, "-"));

        return mb_strtolower(
            substr(this->cipher, position - strlen(this->cipher) + 1)
        );
    }
}
