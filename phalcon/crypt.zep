
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
class Crypt implements \Phalcon\CryptInterface
{

	protected _key;

	protected _mode = "cbc";

	protected _cipher = "rijndael-256";

	/**
	 * Sets the cipher algorithm
	 *
	 * @param string cipher
	 * @return Phalcon\Crypt
	 */
	public function setCipher(string! cipher) -> <\Phalcon\Crypt>
	{
		let this->_cipher = cipher;
		return this;
	}

	/**
	 * Returns the current cipher
	 *
	 * @return string
	 */
	public function getCipher() -> string
	{
		return this->_cipher;
	}

	/**
	 * Sets the encrypt/decrypt mode
	 *
	 * @param string cipher
	 * @return Phalcon\Crypt
	 */
	public function setMode(mode) -> <\Phalcon\Crypt>
	{
		let this->_mode = mode;
		return this;
	}

	/**
	 * Returns the current encryption mode
	 *
	 * @return string
	 */
	public function getMode() -> string
	{
		return this->_mode;
	}

	/**
	 * Sets the encryption key
	 *
	 * @param string key
	 * @return Phalcon\Crypt
	 */
	public function setKey(string! key) -> <\Phalcon\Crypt>
	{
		let this->_key = key;
		return this;
	}

	/**
	 * Returns the encryption key
	 *
	 * @return string
	 */
	public function getKey() -> string
	{
		return this->_key;
	}

	/**
	 * Encrypts a text
	 *
	 *<code>
	 *	$encrypted = $crypt->encrypt("Ultra-secret text", "encrypt password");
	 *</code>
	 *
	 * @param string text
	 * @param string key
	 * @return string
	 */
	public function encrypt(string! text, key=null) -> string
	{
		var encryptKey, ivSize, iv, cipher, mode;

		if !function_exists("mcrypt_get_iv_size") {
			throw new Exception("mcrypt extension is required");
		}

		if key === null {
			let encryptKey = this->_key;
		} else {
			let encryptKey = key;
		}

		if empty encryptKey {
			throw new Exception("Encryption key cannot be empty");
		}

		let cipher = this->_cipher, mode = this->_mode;

		let ivSize = mcrypt_get_iv_size(cipher, mode);
		if strlen(encryptKey) > ivSize {
			throw new Exception("Size of key is too large for this algorithm");
		}

		let iv = mcrypt_create_iv(ivSize, MCRYPT_RAND);
		return iv . mcrypt_encrypt(cipher, encryptKey, text, mode, iv);
	}

	/**
	 * Decrypts an encrypted text
	 *
	 *<code>
	 *	echo $crypt->decrypt($encrypted, "decrypt password");
	 *</code>
	 *
	 * @param string text
	 * @param string key
	 * @return string
	 */
	public function decrypt(string! text, key=null) -> string
	{
		var decryptKey, ivSize, cipher, mode, keySize;

		if !function_exists("mcrypt_get_iv_size") {
			throw new Exception("mcrypt extension is required");
		}

		if key === null {
			let decryptKey = this->_key;
		} else {
			let decryptKey = $key;
		}

		if empty decryptKey {
			throw new Exception("Decryption key cannot be empty");
		}

		let cipher = this->_cipher, mode = this->_mode;

		let ivSize = mcrypt_get_iv_size(cipher, mode);

		let keySize = strlen(decryptKey);
		if keySize > ivSize {
			throw new Exception("Size of key is too large for this algorithm");
		}

		if keySize > strlen(text) {
			throw new Exception("Size of IV is larger than text to decrypt");
		}

		return mcrypt_decrypt(cipher, decryptKey, substr(text, ivSize), mode, substr(text, 0, ivSize));
	}

	/**
	 * Encrypts a text returning the result as a base64 string
	 *
	 * @param string text
	 * @param string key
	 * @return string
	 */
	public function encryptBase64(string! text, key=null) -> string
	{
		return base64_encode($this->encrypt(text, key));
	}

	/**
	 * Decrypt a text that is coded as a base64 string
	 *
	 * @param string text
	 * @param string key
	 * @return string
	 */
	public function decryptBase64(string! text, key=null) -> string
	{
		return this->decrypt(base64_decode(text), $key);
	}

	/**
	 * Returns a list of available cyphers
	 *
	 * @return array
	 */
	public function getAvailableCiphers()
	{
		return mcrypt_list_algorithms();
	}

	/**
	 * Returns a list of available modes
	 *
	 * @return array
	 */
	public function getAvailableModes()
	{
		return mcrypt_list_modes();
	}

}