
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2016 Phalcon Team (http://www.phalconphp.com)       |
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

use Phalcon\CryptInterface;
use Phalcon\Crypt\Exception;

/**
 * Phalcon\Crypt
 *
 * Provides encryption facilities to phalcon applications
 *
 *<code>
 *	$crypt = new \Phalcon\Crypt();
 *
 *	$key = 'le password';
 *	$text = 'This is a secret text';
 *
 *	$encrypted = $crypt->encrypt($text, $key);
 *
 *	echo $crypt->decrypt($encrypted, $key);
 *</code>
 */
class Crypt implements CryptInterface
{

	protected _key;

	protected _padding = 0;

	protected _cipher = "aes-256-cfb";

	const PADDING_DEFAULT = 0;

	const PADDING_ANSI_X_923 = 1;

	const PADDING_PKCS7 = 2;

	const PADDING_ISO_10126 = 3;

	const PADDING_ISO_IEC_7816_4 = 4;

	const PADDING_ZERO = 5;

	const PADDING_SPACE = 6;

	/**
	 * Changes the padding scheme used	 
	 */
	public function setPadding(int! scheme) -> <CryptInterface>
	{
		let this->_padding = scheme;
		return this;
	}

	/**
	 * Sets the cipher algorithm
	 */
	public function setCipher(string! cipher) -> <Crypt>
	{
		let this->_cipher = cipher;
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
	 * Sets the encryption key
	 */
	public function setKey(string! key) -> <Crypt>
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
	 * Pads texts before encryption
	 *
	 * @see http://www.di-mgt.com.au/cryptopad.html
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
	 * Removes padding @a padding_type from @a text
	 * If the function detects that the text was not padded, it will return it unmodified
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
	 * Encrypts a text
	 *
	 *<code>
	 *	$encrypted = $crypt->encrypt("Ultra-secret text", "encrypt password");
	 *</code>
	 */
	public function encrypt(string! text, string! key = null) -> string
	{
		var encryptKey, ivSize, iv, cipher, mode, blockSize, paddingType, padded;

		if !function_exists("openssl_cipher_iv_length") {
			throw new Exception("openssl extension is required");
		}

		if key === null {
			let encryptKey = this->_key;
		} else {
			let encryptKey = key;
		}

		if empty encryptKey {
			throw new Exception("Encryption key cannot be empty");
		}

		let cipher = this->_cipher;
		let mode = strtolower(substr(cipher, strrpos(cipher, "-") - strlen(cipher)));
		
		if !in_array(cipher, openssl_get_cipher_methods()) {
			throw new Exception("Cipher algorithm is unknown");
		}
		
		let ivSize = openssl_cipher_iv_length(cipher);
		if ivSize > 0 {
			let blockSize = ivSize;
		} else {
			let blockSize = openssl_cipher_iv_length(str_ireplace("-" . mode, "", cipher));
		}

		let iv = openssl_random_pseudo_bytes(ivSize);
		let paddingType = this->_padding;

		if paddingType != 0 && (mode == "cbc" || mode == "ecb") {
			let padded = this->_cryptPadText(text, mode, blockSize, paddingType);
		} else {
			let padded = text;
		}

		return iv . openssl_encrypt(padded, cipher, encryptKey, OPENSSL_RAW_DATA, iv);
	}

	/**
	 * Decrypts an encrypted text
	 *
	 *<code>
	 *	echo $crypt->decrypt($encrypted, "decrypt password");
	 *</code>
	 */
	public function decrypt(string! text, key = null) -> string
	{
		var decryptKey, ivSize, cipher, mode, blockSize, paddingType, decrypted;

		if !function_exists("openssl_cipher_iv_length") {
			throw new Exception("openssl extension is required");
		}

		if key === null {
			let decryptKey = this->_key;
		} else {
			let decryptKey = key;
		}

		if empty decryptKey {
			throw new Exception("Decryption key cannot be empty");
		}

		let cipher = this->_cipher;
		let mode = strtolower(substr(cipher, strrpos(cipher, "-") - strlen(cipher)));
		
		if !in_array(cipher, openssl_get_cipher_methods()) {
			throw new Exception("Cipher algorithm is unknown");
		}

		let ivSize = openssl_cipher_iv_length(cipher);
		if ivSize > 0 {
			let blockSize = ivSize;
		} else {
			let blockSize = openssl_cipher_iv_length(str_ireplace("-" . mode, "", cipher));
		}

		let decrypted = openssl_decrypt(substr(text, ivSize), cipher, decryptKey, OPENSSL_RAW_DATA, substr(text, 0, ivSize));

		let paddingType = this->_padding;

		if mode == "cbc" || mode == "ecb" {
			return this->_cryptUnpadText(decrypted, mode, blockSize, paddingType);
		}

		return decrypted;
	}

	/**
	 * Encrypts a text returning the result as a base64 string
	 */
	public function encryptBase64(string! text, key = null, boolean! safe = false) -> string
	{
		if safe == true {
			return strtr(base64_encode(this->encrypt(text, key)), "+/", "-_");
		}
		return base64_encode(this->encrypt(text, key));
	}

	/**
	 * Decrypt a text that is coded as a base64 string
	 */
	public function decryptBase64(string! text, key = null, boolean! safe = false) -> string
	{
		if safe == true {
			return this->decrypt(base64_decode(strtr(text, "-_", "+/")), key);
		}
		return this->decrypt(base64_decode(text), key);
	}

	/**
	 * Returns a list of available ciphers
	 */
	public function getAvailableCiphers() -> array
	{
		return openssl_get_cipher_methods();
	}
}
