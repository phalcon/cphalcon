
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption;

use Phalcon\Contracts\Encryption\EncryptionTypes;
use Phalcon\Encryption\Crypt\CryptInterface;
use Phalcon\Encryption\Crypt\Exception\DecryptionFailed;
use Phalcon\Encryption\Crypt\Exception\EmptyDecryptionKey;
use Phalcon\Encryption\Crypt\Exception\EmptyEncryptionKey;
use Phalcon\Encryption\Crypt\Exception\EncryptionFailed;
use Phalcon\Encryption\Crypt\Exception\Exception;
use Phalcon\Encryption\Crypt\Exception\InvalidAuthTagLength;
use Phalcon\Encryption\Crypt\Exception\InvalidDecryptLength;
use Phalcon\Encryption\Crypt\Exception\InvalidPaddingSize;
use Phalcon\Encryption\Crypt\Exception\IvLengthCalculationFailed;
use Phalcon\Encryption\Crypt\Exception\Mismatch;
use Phalcon\Encryption\Crypt\Exception\MissingAuthData;
use Phalcon\Encryption\Crypt\Exception\MissingOpensslExtension;
use Phalcon\Encryption\Crypt\Exception\RandomBytesGenerationFailed;
use Phalcon\Encryption\Crypt\Exception\UnsupportedAlgorithm;
use Phalcon\Encryption\Crypt\PadFactory;
use Phalcon\Traits\Php\Base64Trait;
use Phalcon\Traits\Php\HashTrait;
use Phalcon\Traits\Php\InfoTrait;
use Phalcon\Traits\Php\OpensslTrait;

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
 *
 * @phpstan-import-type encryption_cipher_list from EncryptionTypes
 * @phpstan-import-type encryption_hash_algorithms from EncryptionTypes
 * @phpstan-import-type encryption_hash_length_cache from EncryptionTypes
 */
class Crypt implements CryptInterface
{
    use Base64Trait;
    use HashTrait;
    use InfoTrait;
    use OpensslTrait;

    /**
     * @var string
     */
    const DEFAULT_ALGORITHM = "sha256";
    /**
     * @var string
     */
    const DEFAULT_CIPHER    = "aes-256-cfb";

    /**
     * Padding
     *
     * @var int
     */
    const PADDING_ANSI_X_923     = 1;
    /**
     * @var int
     */
    const PADDING_DEFAULT        = 0;
    /**
     * @var int
     */
    const PADDING_ISO_10126      = 3;
    /**
     * @var int
     */
    const PADDING_ISO_IEC_7816_4 = 4;
    /**
     * @var int
     */
    const PADDING_PKCS7          = 2;
    /**
     * @var int
     */
    const PADDING_SPACE          = 6;
    /**
     * @var int
     */
    const PADDING_ZERO           = 5;

    protected string authData = "";
    protected string authTag = "";
    protected int authTagLength = 16;
    /**
     * Available cipher methods.
     *
     * @phpstan-var encryption_cipher_list
     */
    protected array availableCiphers = [];
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
     * Memoized `strlen(hash($algo, "", true))` results, keyed by
     * algorithm name. The hash output length is deterministic for a
     * given algorithm, so this collapses the per-decrypt strlen+hash
     * call to a single hash lookup after warm-up.
     *
     * @phpstan-var encryption_hash_length_cache
     */
    protected array hashLengthCache = [];
    /**
     * The cipher iv length.
     */
    protected int ivLength = 16;
    protected string key = "";
    protected int padding = 0;
    protected <PadFactory> padFactory;
    /**
     * Whether calculating message digest enabled or not.
     */
    protected bool useSigning = true;

    /**
     * Crypt constructor.
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
     * @throws Exception
     * @throws InvalidDecryptLength
     * @throws Mismatch
     */
    public function decrypt(string input, string key = null) -> string
    {
        var blockSize, cipher, cipherText, decrypted, decryptKey, digest,
            hashAlgorithm, hashLength, iv, ivLength, mode;

        let decryptKey = this->key;
        if true !== empty(key) {
            let decryptKey = key;
        }

        if true === empty(decryptKey) {
            throw new EmptyDecryptionKey();
        }

        let cipher   = this->cipher,
            ivLength = this->ivLength;

        this->checkCipherHashIsAvailable(cipher, "cipher");

        if true !== this->isValidDecryptLength(input) {
            throw new InvalidDecryptLength();
        }

        let mode      = this->getMode(),
            blockSize = this->getBlockSize(mode),
            iv        = mb_substr(input, 0, ivLength, "8bit");

        /**
         * Check if we have chosen signing and use the hash
         */
        let digest        = "",
            hashAlgorithm = this->getHashAlgorithm();
        if true === this->useSigning {
            if !fetch hashLength, this->hashLengthCache[hashAlgorithm] {
                let hashLength = strlen(this->phpHash(hashAlgorithm, "", true));
                let this->hashLengthCache[hashAlgorithm] = hashLength;
            }
            let digest     = mb_substr(input, ivLength, hashLength, "8bit"),
                cipherText = mb_substr(input, ivLength + hashLength, null, "8bit");
        } else {
            let cipherText = mb_substr(input, ivLength, null, "8bit");
        }

        if true === this->useSigning {
            /**
             * Blind the CBC padding oracle (CWE-649): an OpenSSL padding
             * failure and an HMAC mismatch must be indistinguishable. Tolerate
             * a decrypt failure, always compute the HMAC (over the padded
             * plaintext, before unpadding) so the timing does not leak which
             * one happened, and report a single generic error. On a failure
             * the HMAC runs over a dummy of the ciphertext length, so the
             * amount of work is the same on both paths. hash_equals() keeps
             * the comparison constant-time.
             */
            try {
                let decrypted = this->decryptGcmCcmAuth(
                    mode,
                    cipherText,
                    decryptKey,
                    iv
                );
            } catch DecryptionFailed {
                let decrypted = false;
            }

            if true !== this->phpHashEquals(
                    this->phpHashHmac(
                        hashAlgorithm,
                        false === decrypted ? str_repeat(chr(0), strlen(cipherText)) : decrypted,
                        decryptKey,
                        true
                    ),
                    digest
                ) || false === decrypted {
                throw new Mismatch("Hash does not match.");
            }

            return this->decryptGetUnpadded(
                mode,
                blockSize,
                decrypted
            );
        }

        let decrypted = this->decryptGcmCcmAuth(
            mode,
            cipherText,
            decryptKey,
            iv
        );

        return this->decryptGetUnpadded(
            mode,
            blockSize,
            decrypted
        );
    }

    /**
     * Decrypt a text that is coded as a base64 string.
     *
     * @throws Exception
     * @throws Mismatch
     */
    public function decryptBase64(
        string input,
        string key = null,
        bool safe = false
    ) -> string {
        if safe {
            return this->decrypt(this->doDecodeUrl(input), key);
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
            throw new EmptyEncryptionKey();
        }

        let cipher   = this->cipher,
            ivLength = this->ivLength;

        this->checkCipherHashIsAvailable(cipher, "cipher");

        let mode      = this->getMode(),
            blockSize = this->getBlockSize(mode);

        try {
            let iv = this->phpOpensslRandomPseudoBytes(ivLength);
        } catch \Throwable {
            throw new RandomBytesGenerationFailed();
        }

        let padded = this->encryptGetPadded(mode, input, blockSize);

        /**
         * If the mode is "gcm" or "ccm" and auth data has been passed call it
         * with that data
         */
        let encrypted = this->encryptGcmCcm(mode, padded, encryptKey, iv);

        if true === this->useSigning {
            let digest = this->phpHashHmac(
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
     * Returns the auth data
     */
    public function getAuthData() -> string
    {
        return this->authData;
    }

    /**
     * Returns the auth tag
     */
    public function getAuthTag() -> string
    {
        return this->authTag;
    }

    /**
     * Returns the auth tag length
     */
    public function getAuthTagLength() -> int
    {
        return this->authTagLength;
    }

    /**
     * Returns a list of available ciphers.
     *
     * @phpstan-return encryption_cipher_list
     */
    public function getAvailableCiphers() -> array
    {
        return this->availableCiphers;
    }

    /**
     * Return a list of registered hashing algorithms suitable for hash_hmac.
     *
     * @phpstan-return encryption_hash_algorithms
     */
    public function getAvailableHashAlgorithms() -> array
    {
        if true === this->phpFunctionExists("hash_hmac_algos") {
            return hash_hmac_algos();
        }

        return hash_algos();
    }

    /**
     * Returns the current cipher
     */
    public function getCipher() -> string
    {
        return this->cipher;
    }

    /**
     * Get the name of hashing algorithm.
     */
    public function getHashAlgorithm() -> string
    {
        return this->hashAlgorithm;
    }

    /**
     * Returns the encryption key
     */
    public function getKey() -> string
    {
        return this->key;
    }

    /**
     * Returns if the input length for decryption is valid or not
     * (number of bytes required by the cipher).
     */
    public function isValidDecryptLength(string input) -> bool
    {
        var length;

        let length = this->phpOpensslCipherIvLength(this->cipher);

        if length === false {
            return false;
        }

        return length <= strlen(input);
    }

    public function setAuthData(string data) -> <CryptInterface>
    {
        let this->authData = data;

        return this;
    }

    public function setAuthTag(string tag) -> <CryptInterface>
    {
        let this->authTag = tag;

        return this;
    }

    /**
     *
     * @throws InvalidAuthTagLength
     */
    public function setAuthTagLength(int length) -> <CryptInterface>
    {
        if length < 4 || length > 16 {
            throw new InvalidAuthTagLength();
        }

        let this->authTagLength = length;

        return this;
    }

    /**
     * Sets the cipher algorithm for data encryption and decryption.
     *
     *
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
     * Set the name of hashing algorithm.
     *
     *
     * @throws Exception
     */
    public function setHashAlgorithm(string hashAlgorithm) -> <static>
    {
        this->checkCipherHashIsAvailable(hashAlgorithm, "hash");

        let this->hashAlgorithm = hashAlgorithm;

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
     */
    public function setKey(string key) -> <CryptInterface>
    {
        let this->key = key;

        return this;
    }

    /**
     * Changes the padding scheme used.
     */
    public function setPadding(int scheme) -> <CryptInterface>
    {
        let this->padding = scheme;

        return this;
    }

    /**
     * Sets if the calculating message digest must used.
     */
    public function useSigning(bool useSigning) -> <CryptInterface>
    {
        let this->useSigning = useSigning;

        return this;
    }

    /**
     * Checks if a cipher or a hash algorithm is available
     *
     *
     * @throws Exception
     */
    protected function checkCipherHashIsAvailable(string cipher, string type) -> void
    {
        var available, lower, method;

        if "hash" === type {
            let method = "getAvailableHashAlgorithms";
        } else {
            let method = "getAvailableCiphers";
        }

        let available = this->{method}(),
            lower     = mb_strtolower(cipher);
        if true !== in_array(lower, available) {
            throw new UnsupportedAlgorithm(type, cipher);
        }
    }

    /**
     * Pads texts before encryption. See
     * [cryptopad](https://www.di-mgt.com.au/cryptopad.html)
     *
     *
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

        if true === this->checkIsMode(["cbc"], mode) {
            let paddingSize = blockSize - (strlen(input) % blockSize);

            if paddingSize >= 256 || paddingSize < 0 {
                throw new InvalidPaddingSize();
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
            true === this->checkIsMode(["cbc"], mode)
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
     * @throws Exception
     */
    protected function decryptGcmCcmAuth(
        string mode,
        string cipherText,
        string decryptKey,
        string iv
    ) -> string {
        var authData, authTag, authTagLength, cipher, cipherLength, encrypted,
            decrypted;

        let cipher = this->cipher;

        if true === this->checkIsMode(["ccm", "gcm"], mode) {
            let authData      = this->authData,
                authTagLength = this->authTagLength,
                cipherLength  = strlen(cipherText),
                authTag       = substr(cipherText, cipherLength - authTagLength),
                encrypted     = substr(cipherText, 0, cipherLength - authTagLength);

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
            throw new DecryptionFailed();
        }

        return decrypted;
    }

    protected function decryptGetUnpadded(
        string mode,
        int blockSize,
        string decrypted
    ) -> string {
        var localDecrypted, padding;

        let localDecrypted = decrypted;
        if true === this->checkIsMode(["cbc"], mode) {
            let padding   = this->padding,
                localDecrypted = this->cryptUnpadText(
                    decrypted,
                    mode,
                    blockSize,
                    padding
                );
        }

        return localDecrypted;
    }

    /**
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
                throw new MissingAuthData();
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
            throw new EncryptionFailed();
        }

        /**
         * Store the tag with encrypted data and return it. In the non AEAD
         * mode this is an empty string
         */
        return encrypted . authTag;
    }

    /**
     * @throws Exception
     */
    protected function encryptGetPadded(
        string mode,
        string input,
        int blockSize
    ) -> string {
        if (
            0 !== this->padding &&
            true === this->checkIsMode(["cbc"], mode)
        ) {
            return this->cryptPadText(input, mode, blockSize, this->padding);
        }

        return input;
    }

    /**
     * Initialize available cipher algorithms.
     *
     * @throws Exception
     */
    protected function initializeAvailableCiphers() -> <static>
    {
        var available, cipher;
        array allowed;

        if true !== this->phpFunctionExists("openssl_get_cipher_methods") {
            throw new MissingOpensslExtension();
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
     * @phpstan-param encryption_cipher_list $modes
     */
    private function checkIsMode(array modes, string mode) -> bool
    {
        return in_array(mode, modes);
    }

    /**
     * Returns the block size
     *
     *
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
     *
     * @throws Exception
     */
    private function getIvLength(string cipher) -> int
    {
        var length;

        let length = openssl_cipher_iv_length(cipher);
        if false === length {
            throw new IvLengthCalculationFailed();
        }

        return length;
    }

    /**
     * Returns the mode (last few characters of the cipher)
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
