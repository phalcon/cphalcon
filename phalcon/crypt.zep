
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2018 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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

use Phalcon\CryptInterface;
use Phalcon\Crypt\Exception;
use Phalcon\Crypt\Mismatch;

/**
 * Phalcon\Crypt
 *
 * Provides encryption facilities to Phalcon applications.
 *
 * <code>
 * use Phalcon\Crypt;
 *
 * $crypt = new Crypt();
 *
 * $crypt->setCipher('aes-256-ctr');
 *
 * $key  = "T4\xb1\x8d\xa9\x98\x05\\\x8c\xbe\x1d\x07&[\x99\x18\xa4~Lc1\xbeW\xb3";
 * $text = "The message to be encrypted";
 *
 * $encrypted = $crypt->encrypt($text, $key);
 *
 * echo $crypt->decrypt($encrypted, $key);
 * </code>
 */
class Crypt implements CryptInterface
{
	protected _key;

	protected _padding = 0;

	protected _cipher = "aes-256-cfb";

	/**
	 * Available cipher methods.
	 * @var array
     */
	protected availableCiphers;

	/**
	 * The cipher iv length.
	 * @var int
	 */
	protected ivLength = 16;

	/**
	 * The name of hashing algorithm.
	 * @var string
	 */
	protected hashAlgo = "sha256";

	/**
	 * Whether calculating message digest enabled or not.
	 * NOTE: This feature will be enabled by default in Phalcon 4.0.0
	 * @var bool
	 */
	protected useSigning = false;

	const PADDING_DEFAULT = 0;

	const PADDING_ANSI_X_923 = 1;

	const PADDING_PKCS7 = 2;

	const PADDING_ISO_10126 = 3;

	const PADDING_ISO_IEC_7816_4 = 4;

	const PADDING_ZERO = 5;

	const PADDING_SPACE = 6;

	/**
	 * Phalcon\Crypt constructor.
	 */
	public function __construct(string! cipher = "aes-256-cfb", boolean useSigning = false)
	{
		this->initializeAvailableCiphers();

		this->setCipher(cipher);
		this->useSigning(useSigning);
	}

	/**
	 * Changes the padding scheme used.
	 */
	public function setPadding(int! scheme) -> <CryptInterface>
	{
		let this->_padding = scheme;
		return this;
	}

	/**
	 * Sets the cipher algorithm for data encryption and decryption.
	 *
	 * The `aes-256-gcm' is the preferable cipher, but it is not usable
	 * until the openssl library is upgraded, which is available in PHP 7.1.
	 *
	 * The `aes-256-ctr' is arguably the best choice for cipher
	 * algorithm for current openssl library version.
	 */
	public function setCipher(string! cipher) -> <CryptInterface>
	{
		this->assertCipherIsAvailable(cipher);

		let this->ivLength = this->getIvLength(cipher),
			this->_cipher  = cipher;

		return this;
	}

	/**
	 * Returns the current cipher
	 */
	public function getCipher() -> string
	{
		return this->_cipher;
	}

	/**
	 * Sets the encryption key.
	 *
	 * The `$key' should have been previously generated in a cryptographically safe way.
	 *
	 * Bad key:
	 * "le password"
	 *
	 * Better (but still unsafe):
	 * "#1dj8$=dp?.ak//j1V$~%*0X"
	 *
	 * Good key:
	 * "T4\xb1\x8d\xa9\x98\x05\\\x8c\xbe\x1d\x07&[\x99\x18\xa4~Lc1\xbeW\xb3"
	 *
	 * @see \Phalcon\Security\Random
	 */
	public function setKey(string! key) -> <CryptInterface>
	{
		let this->_key = key;
		return this;
	}

	/**
	 * Returns the encryption key
	 */
	public function getKey() -> string
	{
		return this->_key;
	}

	/**
	 * Set the name of hashing algorithm.
	 *
	 * @throws \Phalcon\Crypt\Exception
	 */
	public function setHashAlgo(string! hashAlgo) -> <Crypt>
	{
		this->assertHashAlgorithmAvailable(hashAlgo);

		let this->hashAlgo = hashAlgo;

		return this;
	}

	/**
	 * Get the name of hashing algorithm.
	 */
	public function getHashAlgo() -> string
	{
		return this->hashAlgo;
	}

	/**
	 * Sets if the calculating message digest must used.
	 *
	 * NOTE: This feature will be enabled by default in Phalcon 4.0.0
	 */
	public function useSigning(boolean useSigning) -> <Crypt>
	{
		let this->useSigning = useSigning;

		return this;
	}

	/**
	 * Pads texts before encryption.
	 *
	 * @link http://www.di-mgt.com.au/cryptopad.html
	 */
	protected function _cryptPadText(string text, string! mode, int! blockSize, int! paddingType)
	{
		int i;
		var paddingSize = 0, padding = null;

		if mode == "cbc" || mode == "ecb" {

			let paddingSize = blockSize - (strlen(text) % blockSize);
			if paddingSize >= 256 {
				throw new Exception("Block size is bigger than 256");
			}

			switch paddingType {

				case self::PADDING_ANSI_X_923:
					let padding = str_repeat(chr(0), paddingSize - 1) . chr(paddingSize);
					break;

				case self::PADDING_PKCS7:
					let padding = str_repeat(chr(paddingSize), paddingSize);
					break;

				case self::PADDING_ISO_10126:
					let padding = "";
					for i in range(0, paddingSize - 2) {
						let padding .= chr(rand());
					}
					let padding .= chr(paddingSize);
					break;

				case self::PADDING_ISO_IEC_7816_4:
					let padding = chr(0x80) . str_repeat(chr(0), paddingSize - 1);
					break;

				case self::PADDING_ZERO:
					let padding = str_repeat(chr(0), paddingSize);
					break;

				case self::PADDING_SPACE:
					let padding = str_repeat(" ", paddingSize);
					break;

				default:
					let paddingSize = 0;
					break;
			}
		}

		if !paddingSize {
			return text;
		}

		if paddingSize > blockSize {
			throw new Exception("Invalid padding size");
		}

		return text . substr(padding, 0, paddingSize);
	}

	/**
	 * Removes a padding from a text.
	 *
	 * If the function detects that the text was not padded, it will return it unmodified.
	 *
	 * @param string text Message to be unpadded
	 * @param string mode Encryption mode; unpadding is applied only in CBC or ECB mode
	 * @param int blockSize Cipher block size
	 * @param int paddingType Padding scheme
	 */
	protected function _cryptUnpadText(string text, string! mode, int! blockSize, int! paddingType)
	{
		var padding, last;
		long length;
		int i, paddingSize = 0, ord;

		let length = strlen(text);
		if length > 0 && (length % blockSize == 0) && (mode == "cbc" || mode == "ecb") {

			switch paddingType {

				case self::PADDING_ANSI_X_923:
					let last = substr(text, length - 1, 1);
					let ord = (int) ord(last);
					if ord <= blockSize {
						let paddingSize = ord;
						let padding = str_repeat(chr(0), paddingSize - 1) . last;
						if substr(text, length - paddingSize) != padding {
							let paddingSize = 0;
						}
					}
					break;

				case self::PADDING_PKCS7:
					let last = substr(text, length - 1, 1);
					let ord = (int) ord(last);
					if ord <= blockSize {
						let paddingSize = ord;
						let padding = str_repeat(chr(paddingSize), paddingSize);
						if substr(text, length - paddingSize) != padding {
							let paddingSize = 0;
						}
					}
					break;

				case self::PADDING_ISO_10126:
					let last = substr(text, length - 1, 1);
					let paddingSize = (int) ord(last);
					break;

				case self::PADDING_ISO_IEC_7816_4:
					let i = length - 1;
					while i > 0 && text[i] == 0x00 && paddingSize < blockSize {
						let paddingSize++, i--;
					}
					if text[i] == 0x80 {
						let paddingSize++;
					} else {
						let paddingSize = 0;
					}
					break;

				case self::PADDING_ZERO:
					let i = length - 1;
					while i >= 0 && text[i] == 0x00 && paddingSize <= blockSize {
						let paddingSize++, i--;
					}
					break;

				case self::PADDING_SPACE:
					let i = length - 1;
					while i >= 0 && text[i] == 0x20 && paddingSize <= blockSize {
						let paddingSize++, i--;
					}
					break;

				default:
					break;
			}

			if paddingSize && paddingSize <= blockSize {

				if paddingSize < length {
					return substr(text, 0, length - paddingSize);
				}
				return "";

			} else {
				let paddingSize = 0;
			}

		}

		if !paddingSize {
			return text;
		}
	}

	/**
	 * Encrypts a text.
	 *
	 * <code>
	 * $encrypted = $crypt->encrypt(
	 *     "Top secret",
	 *     "T4\xb1\x8d\xa9\x98\x05\\\x8c\xbe\x1d\x07&[\x99\x18\xa4~Lc1\xbeW\xb3"
	 * );
	 * </code>
	 */
	public function encrypt(string! text, string! key = null) -> string
	{
		var encryptKey, ivLength, iv, cipher, mode, blockSize, paddingType, padded, encrypted;

		if likely empty key {
			let encryptKey = this->_key;
		} else {
			let encryptKey = key;
		}

		if empty encryptKey {
			throw new Exception("Encryption key cannot be empty");
		}

		let cipher = this->_cipher;
		let mode = strtolower(substr(cipher, strrpos(cipher, "-") - strlen(cipher)));

		this->assertCipherIsAvailable(cipher);

		let ivLength = this->ivLength;
		if likely ivLength > 0 {
			let blockSize = ivLength;
		} else {
			let blockSize = this->getIvLength(str_ireplace("-" . mode, "", cipher));
		}

		let iv = openssl_random_pseudo_bytes(ivLength);
		let paddingType = this->_padding;

		if paddingType != 0 && (mode == "cbc" || mode == "ecb") {
			let padded = this->_cryptPadText(text, mode, blockSize, paddingType);
		} else {
			let padded = text;
		}

		let encrypted = openssl_encrypt(padded, cipher, encryptKey, OPENSSL_RAW_DATA, iv);

		if this->useSigning {
			var digest, hashAlgo;

			let hashAlgo = this->getHashAlgo();
			let digest = hash_hmac(hashAlgo, padded, encryptKey, true);

			return iv . digest . encrypted;
		}

		return iv . encrypted;
	}

	/**
	 * Decrypts an encrypted text.
	 *
	 * <code>
	 * $encrypted = $crypt->decrypt(
	 *     $encrypted,
	 *     "T4\xb1\x8d\xa9\x98\x05\\\x8c\xbe\x1d\x07&[\x99\x18\xa4~Lc1\xbeW\xb3"
	 * );
	 * </code>
	 *
	 * @throws \Phalcon\Crypt\Mismatch
	 */
	public function decrypt(string! text, string! key = null) -> string
	{
		var decryptKey, ivLength, cipher, mode, blockSize, decrypted,
			ciphertext, hashAlgo, hashLength, iv, hash;

		if likely empty key {
			let decryptKey = this->_key;
		} else {
			let decryptKey = key;
		}

		if empty decryptKey {
			throw new Exception("Decryption key cannot be empty");
		}

		let cipher = this->_cipher;
		let mode = strtolower(substr(cipher, strrpos(cipher, "-") - strlen(cipher)));

		this->assertCipherIsAvailable(cipher);

		let ivLength = this->ivLength;
		if likely ivLength > 0 {
			let blockSize = ivLength;
		} else {
			let blockSize = this->getIvLength(str_ireplace("-" . mode, "", cipher));
		}

		let iv = mb_substr(text, 0, ivLength, "8bit");

		if this->useSigning {
			let hashAlgo = this->getHashAlgo();
			let hashLength = strlen(hash(hashAlgo, "", true));
			let hash = mb_substr(text, ivLength, hashLength, "8bit");
			let ciphertext = mb_substr(text, ivLength + hashLength, null, "8bit");
			let decrypted = openssl_decrypt(ciphertext, cipher, decryptKey, OPENSSL_RAW_DATA, iv);

			if mode == "cbc" || mode == "ecb" {
				let decrypted = this->_cryptUnpadText(decrypted, mode, blockSize, this->_padding);
			}

			/**
			 * Checkson the decrypted's message digest using the HMAC method.
			 */
			if hash_hmac(hashAlgo, decrypted, decryptKey, true) !== hash {
				throw new Mismatch("Hash does not match.");
			}

			return decrypted;
		}

		let ciphertext = mb_substr(text, ivLength, null, "8bit");
		let decrypted = openssl_decrypt(ciphertext, cipher, decryptKey, OPENSSL_RAW_DATA, iv);

		if mode == "cbc" || mode == "ecb" {
			let decrypted = this->_cryptUnpadText(decrypted, mode, blockSize, this->_padding);
		}

		return decrypted;
	}

	/**
	 * Encrypts a text returning the result as a base64 string.
	 */
	public function encryptBase64(string! text, key = null, boolean! safe = false) -> string
	{
		if safe == true {
			return rtrim(strtr(base64_encode(this->encrypt(text, key)), "+/", "-_"), "=");
		}
		return base64_encode(this->encrypt(text, key));
	}

	/**
	 * Decrypt a text that is coded as a base64 string.
	 *
	 * @throws \Phalcon\Crypt\Mismatch
	 */
	public function decryptBase64(string! text, key = null, boolean! safe = false) -> string
	{
		if safe == true {
			return this->decrypt(base64_decode(strtr(text, "-_", "+/") . substr("===", (strlen(text) + 3) % 4)), key);
		}
		return this->decrypt(base64_decode(text), key);
	}

	/**
	 * Returns a list of available ciphers.
	 */
	public function getAvailableCiphers() -> array
	{
		var availableCiphers;

		let availableCiphers = this->availableCiphers;
		if unlikely typeof availableCiphers !== "array" {
			this->initializeAvailableCiphers();
			let availableCiphers = this->availableCiphers;
		}

		return availableCiphers;
	}

	/**
	 * Return a list of registered hashing algorithms suitable for hash_hmac.
	 */
	public function getAvailableHashAlgos() -> array
	{
		var algos;

		if likely function_exists("hash_hmac_algos") {
			let algos = hash_hmac_algos();
		} else {
			let algos = hash_algos();
		}

		return algos;
	}

	/**
	 * Assert the cipher is available.
	 *
	 * @throws \Phalcon\Crypt\Exception
	 */
	protected function assertCipherIsAvailable(string! cipher) -> void
	{
		var availableCiphers;

		let availableCiphers = this->getAvailableCiphers();

		if !in_array(cipher, availableCiphers) {
			throw new Exception(
				sprintf(
					"The cipher algorithm \"%s\" is not supported on this system.",
					cipher
				)
			);
		}
	}

	/**
	 * Assert the hash algorithm is available.
	 *
	 * @throws \Phalcon\Crypt\Exception
	 */
	protected function assertHashAlgorithmAvailable(string! hashAlgo) -> void
	{
		var availableAlgorithms;

		let availableAlgorithms = this->getAvailableHashAlgos();

		if !in_array(hashAlgo, availableAlgorithms) {
			throw new Exception(
				sprintf(
					"The hash algorithm \"%s\" is not supported on this system.",
					hashAlgo
				)
			);
		}
	}

	/**
	 * Initialize available cipher algorithms.
	 *
	 * @throws \Phalcon\Crypt\Exception
	 */
	protected function getIvLength(string! cipher) -> int
	{
		if !function_exists("openssl_cipher_iv_length") {
			throw new Exception("openssl extension is required");
		}

		return openssl_cipher_iv_length(cipher);
	}

	/**
	 * Initialize available cipher algorithms.
	 *
	 * @throws \Phalcon\Crypt\Exception
	 */
	protected function initializeAvailableCiphers() -> void
	{
		if !function_exists("openssl_get_cipher_methods") {
			throw new Exception("openssl extension is required");
		}

		let this->availableCiphers = openssl_get_cipher_methods(true);
	}
}
