
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"

/**
 * Phalcon\Crypt
 *
 * Provides encryption facilities to phalcon applications
 *
 *<code>
 *	$crypt = new Phalcon\Crypt();
 *
 *	$key = 'le password';
 *	$text = 'This is a secret text';
 *
 *	$encrypted = $crypt->encrypt($text, $key);
 *
 *	echo $crypt->decrypt($encrypted, $key);
 *</code>
 */


/**
 * Phalcon\Crypt initializer
 */
PHALCON_INIT_CLASS(Phalcon_Crypt){

	PHALCON_REGISTER_CLASS(Phalcon, Crypt, crypt, phalcon_crypt_method_entry, 0);

	zend_declare_property_null(phalcon_crypt_ce, SL("_key"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_crypt_ce, SL("_mode"), "cbc", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_crypt_ce, SL("_cipher"), "rijndael-256", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_crypt_ce, SL("_padding"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_crypt_ce TSRMLS_CC, 1, phalcon_cryptinterface_ce);

	zend_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_DEFAULT"),        PHALCON_CRYPT_PADDING_DEFAULT        TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ANSI_X_923"),     PHALCON_CRYPT_PADDING_ANSI_X_923     TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_PKCS7"),          PHALCON_CRYPT_PADDING_PKCS7          TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ISO_10126"),      PHALCON_CRYPT_PADDING_ISO_10126      TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ISO_IEC_7816_4"), PHALCON_CRYPT_PADDING_ISO_IEC_7816_4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ZERO"),           PHALCON_CRYPT_PADDING_ZERO           TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_SPACE"),          PHALCON_CRYPT_PADDING_SPACE          TSRMLS_CC);

	return SUCCESS;
}

/**
 * Sets the cipher algorithm
 *
 * @param string $cipher
 * @return Phalcon\Encrypt
 */
PHP_METHOD(Phalcon_Crypt, setCipher){

	zval *cipher;

	phalcon_fetch_params(0, 1, 0, &cipher);
	
	phalcon_update_property_this(this_ptr, SL("_cipher"), cipher TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the current cipher
 *
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, getCipher){


	RETURN_MEMBER(this_ptr, "_cipher");
}

/**
 * Sets the encrypt/decrypt mode
 *
 * @param string $cipher
 * @return Phalcon\Encrypt
 */
PHP_METHOD(Phalcon_Crypt, setMode){

	zval *mode;

	phalcon_fetch_params(0, 1, 0, &mode);
	if (Z_TYPE_P(mode) != IS_STRING) {
		PHALCON_SEPARATE_PARAM_NMO(mode);
		convert_to_string(mode);
	}
	else {
		Z_ADDREF_P(mode);
	}

	phalcon_update_property_this(this_ptr, SL("_mode"), mode TSRMLS_CC);
	zval_ptr_dtor(&mode);
	RETURN_THISW();
}

/**
 * Returns the current encryption mode
 *
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, getMode){


	RETURN_MEMBER(this_ptr, "_mode");
}

/**
 * Sets the encryption key
 *
 * @param string $key
 * @return Phalcon\Encrypt
 */
PHP_METHOD(Phalcon_Crypt, setKey){

	zval *key;

	phalcon_fetch_params(0, 1, 0, &key);
	if (Z_TYPE_P(key) != IS_STRING) {
		PHALCON_SEPARATE_PARAM_NMO(key);
		convert_to_string(key);
	}
	else {
		Z_ADDREF_P(key);
	}

	phalcon_update_property_this(this_ptr, SL("_key"), key TSRMLS_CC);
	zval_ptr_dtor(&key);
	RETURN_THISW();
}


/**
 * Returns the encryption key
 *
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, getKey){


	RETURN_MEMBER(this_ptr, "_key");
}

/**
 * @brief Phalcon\CryptInterface Phalcon\Crypt::setPadding(int $scheme)
 *
 * @param int scheme Padding scheme
 * @return Phalcon\CryptInterface
 */
PHP_METHOD(Phalcon_Crypt, setPadding) {

	zval *scheme;

	phalcon_fetch_params(0, 1, 0, &scheme);
	if (Z_TYPE_P(scheme) != IS_LONG) {
		PHALCON_SEPARATE_PARAM_NMO(scheme);
		convert_to_long(scheme);
	}
	else {
		Z_ADDREF_P(scheme);
	}

	phalcon_update_property_this(this_ptr, SL("_padding"), scheme TSRMLS_CC);
	zval_ptr_dtor(&scheme);
	RETURN_THISW();
}

/**
 * Returns the padding scheme
 *
 * @brief int Phalcon\Crypt::getPadding()
 * @return int
 */
PHP_METHOD(Phalcon_Crypt, getPadding) {

	RETURN_MEMBER(this_ptr, "_padding");
}

/**
 * @brief Adds padding @a padding_type to @a text
 * @param return_value Result, possibly padded
 * @param text Message to be padded
 * @param mode Encryption mode; padding is applied only in CBC or ECB mode
 * @param block_size Cipher block size
 * @param padding_type Padding scheme
 * @see http://www.di-mgt.com.au/cryptopad.html
 */
static void phalcon_crypt_pad_text(zval *return_value, zval *text, zval *mode, uint block_size, int padding_type TSRMLS_DC)
{
	uint padding_size, i;
	char padding[256];
	char *str_mode;

	assert(Z_TYPE_P(text) == IS_STRING);
	assert(Z_TYPE_P(mode) == IS_STRING);

	padding_size = 0;
	str_mode = Z_STRVAL_P(mode);

	if (!strcmp(str_mode, "ecb") || !strcmp(str_mode, "cbc")) {
		padding_size = block_size - (Z_STRLEN_P(text) % block_size);

		switch (padding_type) {
			case PHALCON_CRYPT_PADDING_ANSI_X_923:
				memset(padding, 0, padding_size - 1);
				padding[padding_size-1] = (unsigned char)padding_size;
				break;

			case PHALCON_CRYPT_PADDING_PKCS7:
				memset(padding, padding_size, padding_size);
				break;

			case PHALCON_CRYPT_PADDING_ISO_10126:
				for (i=0; i<padding_size-1; ++i) {
					padding[i] = (unsigned char)rand();
				}

				padding[padding_size-1] = (unsigned char)padding_size;
				break;

			case PHALCON_CRYPT_PADDING_ISO_IEC_7816_4:
				padding[0] = 0x80;
				memset(padding + 1, 0, padding_size - 1);
				break;

			case PHALCON_CRYPT_PADDING_ZERO:
				memset(padding, 0, padding_size);
				break;

			case PHALCON_CRYPT_PADDING_SPACE:
				memset(padding, 0x20, padding_size);
				break;

			default:
				padding_size = 0;
				break;
		}
	}

	if (!padding_size) {
		ZVAL_ZVAL(return_value, text, 1, 0);
	}
	else {
		assert(padding_size <= block_size);
		phalcon_concat_vs(&return_value, text, padding, padding_size, 0 TSRMLS_CC);
	}
}

/**
 * @brief Removes padding @a padding_type from @a text
 * @param return_value Result, possibly unpadded
 * @param text Message to be unpadded
 * @param mode Encryption mode; unpadding is applied only in CBC or ECB mode
 * @param block_size Cipher block size
 * @param padding_type Padding scheme
 * @note If the function detects that the text was not padded, it will return it unmodified
 */
static void phalcon_crypt_unpad_text(zval *return_value, zval *text, zval *mode, uint block_size, int padding_type TSRMLS_DC)
{
	uint padding_size;
	char padding[256];
	int i;
	char *str_mode;
	char *str_text;
	int text_len;

	assert(Z_TYPE_P(text) == IS_STRING);
	assert(Z_TYPE_P(mode) == IS_STRING);

	padding_size = 0;
	str_mode = Z_STRVAL_P(mode);
	str_text = Z_STRVAL_P(text);
	text_len   = Z_STRLEN_P(text);

	if (text_len && (text_len % block_size == 0) && (!strcmp(str_mode, "ecb") || !strcmp(str_mode, "cbc"))) {
		switch (padding_type) {
			case PHALCON_CRYPT_PADDING_ANSI_X_923:
				if (str_text[text_len-1] <= block_size) {
					padding_size = str_text[text_len-1];

					memset(padding, 0, padding_size - 1);
					padding[padding_size-1] = (unsigned char)padding_size;

					if (memcmp(padding, str_text + text_len - padding_size, padding_size)) {
						padding_size = 0;
					}
				}

				break;

			case PHALCON_CRYPT_PADDING_PKCS7:
				if (str_text[text_len-1] <= block_size) {
					padding_size = str_text[text_len-1];

					memset(padding, padding_size, padding_size);

					if (memcmp(padding, str_text + text_len - padding_size, padding_size)) {
						padding_size = 0;
					}
				}

				break;

			case PHALCON_CRYPT_PADDING_ISO_10126:
				padding_size = str_text[text_len-1];
				break;

			case PHALCON_CRYPT_PADDING_ISO_IEC_7816_4:
				i = text_len - 1;
				while (i > 0 && str_text[i] == 0x00 && padding_size < block_size) {
					++padding_size;
					--i;
				}

				padding_size = ((unsigned char)str_text[i] == 0x80) ? (padding_size + 1) : 0;
				break;

			case PHALCON_CRYPT_PADDING_ZERO:
				i = text_len - 1;
				while (i >= 0 && str_text[i] == 0x00 && padding_size <= block_size) {
					++padding_size;
					--i;
				}

				break;

			case PHALCON_CRYPT_PADDING_SPACE:
				i = text_len - 1;
				while (i >= 0 && str_text[i] == 0x20 && padding_size <= block_size) {
					++padding_size;
					--i;
				}

				break;

			default:
				break;
		}

		if (padding_size && padding_size <= block_size) {
			assert(padding_size <= text_len);
			if (padding_size < text_len) {
				phalcon_substr(return_value, text, 0, text_len - padding_size);
			}
			else {
				ZVAL_EMPTY_STRING(return_value);
			}
		}
		else {
			padding_size = 0;
		}
	}

	if (!padding_size) {
		ZVAL_ZVAL(return_value, text, 1, 0);
	}
}

/**
 * Encrypts a text
 *
 *<code>
 *	$encrypted = $crypt->encrypt("Ultra-secret text", "encrypt password");
 *</code>
 *
 * @param string $text
 * @param string $key
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, encrypt){

	zval *source, *text, *key = NULL, *encrypt_key = NULL, *cipher, *mode, *padding_type, *iv_size;
	zval *rand, *iv, *encrypt, *block_size, *padded;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &source, &key);

	/* Do not use make_printable_zval() here: we need the conversion with type juggling */
	if (Z_TYPE_P(source) != IS_STRING) {
		PHALCON_INIT_VAR(text);
		phalcon_cast(text, source, IS_STRING);
	}
	else {
		text = source;
	}

	if (phalcon_function_exists_ex(SS("mcrypt_get_iv_size") TSRMLS_CC) == FAILURE) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_crypt_exception_ce, "mcrypt extension is required");
		return;
	}
	if (!key || Z_TYPE_P(key) == IS_NULL) {
		encrypt_key = phalcon_fetch_nproperty_this(this_ptr, SL("_key"), PH_NOISY_CC);
	} else {
		PHALCON_CPY_WRT(encrypt_key, key);
		if (Z_TYPE_P(encrypt_key) != IS_STRING) {
			convert_to_string(encrypt_key);
		}
	}
	
	if (PHALCON_IS_EMPTY(encrypt_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_crypt_exception_ce, "Encryption key cannot be empty");
		return;
	}
	
	cipher = phalcon_fetch_nproperty_this(this_ptr, SL("_cipher"), PH_NOISY_CC);
	mode   = phalcon_fetch_nproperty_this(this_ptr, SL("_mode"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(iv_size);
	phalcon_call_func_p2_ex(iv_size, &iv_size, "mcrypt_get_iv_size", cipher, mode);
	if (unlikely(Z_TYPE_P(iv_size) != IS_LONG)) {
		convert_to_long(iv_size);
	}
	
	if (Z_STRLEN_P(encrypt_key) > Z_LVAL_P(iv_size)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_crypt_exception_ce, "Size of key is too large for this algorithm");
		return;
	}
	
	PHALCON_INIT_VAR(rand);
	ZVAL_LONG(rand, 2);
	
	PHALCON_OBS_VAR(iv);
	phalcon_call_func_p2_ex(iv, &iv, "mcrypt_create_iv", iv_size, rand);
	if (unlikely(Z_TYPE_P(iv) != IS_STRING)) {
		convert_to_string(iv);
	}
	
	PHALCON_OBS_VAR(block_size);
	phalcon_call_func_p2_ex(block_size, &block_size, "mcrypt_get_block_size", cipher, mode);
	if (unlikely(Z_TYPE_P(block_size) != IS_LONG)) {
		convert_to_long(block_size);
	}

	padding_type = phalcon_fetch_nproperty_this(this_ptr, SL("_padding"), PH_NOISY_CC);

	assert(Z_TYPE_P(padding_type) == IS_LONG);
	assert(Z_TYPE_P(block_size) == IS_LONG);
	assert(Z_TYPE_P(mode) == IS_STRING);
	assert(Z_TYPE_P(text) == IS_STRING);

	PHALCON_INIT_VAR(padded);
	phalcon_crypt_pad_text(padded, text, mode, Z_LVAL_P(block_size), Z_LVAL_P(padding_type) TSRMLS_CC);
	assert(Z_TYPE_P(padded) == IS_STRING);

	PHALCON_OBS_VAR(encrypt);
	phalcon_call_func_p5_ex(encrypt, &encrypt, "mcrypt_encrypt", cipher, encrypt_key, padded, mode, iv);
	
	PHALCON_CONCAT_VV(return_value, iv, encrypt);
	RETURN_MM();
}

/**
 * Decrypts an encrypted text
 *
 *<code>
 *	echo $crypt->decrypt($encrypted, "decrypt password");
 *</code>
 *
 * @param string $text
 * @param string $key
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, decrypt){

	zval *text, *key = NULL, *decrypt_key = NULL, *cipher, *mode, *iv_size;
	zval *key_size, *text_size, *iv, *text_to_decipher, *decrypted;
	zval *padding_type, *block_size;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &text, &key);
	
	if (phalcon_function_exists_ex(SS("mcrypt_get_iv_size") TSRMLS_CC) == FAILURE) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_crypt_exception_ce, "mcrypt extension is required");
		return;
	}

	if (!key || Z_TYPE_P(key) == IS_NULL) {
		decrypt_key = phalcon_fetch_nproperty_this(this_ptr, SL("_key"), PH_NOISY_CC);
	} else {
		decrypt_key = key;
	}
	
	if (PHALCON_IS_EMPTY(decrypt_key)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_crypt_exception_ce, "Decryption key cannot be empty");
		return;
	}
	
	cipher = phalcon_fetch_nproperty_this(this_ptr, SL("_cipher"), PH_NOISY_CC);
	mode   = phalcon_fetch_nproperty_this(this_ptr, SL("_mode"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(iv_size);
	phalcon_call_func_p2_ex(iv_size, &iv_size, "mcrypt_get_iv_size", cipher, mode);
	if (unlikely(Z_TYPE_P(iv_size) != IS_LONG)) {
		convert_to_long(iv_size);
	}
	
	PHALCON_INIT_VAR(key_size);
	phalcon_fast_strlen(key_size, decrypt_key);
	if (PHALCON_GT(key_size, iv_size)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_crypt_exception_ce, "Size of key is too large for this algorithm");
		return;
	}
	
	PHALCON_INIT_VAR(text_size);
	phalcon_fast_strlen(text_size, text);
	if (PHALCON_GT(key_size, text_size)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_crypt_exception_ce, "Size of IV is larger than text to decrypt");
		return;
	}
	
	PHALCON_INIT_VAR(iv);
	phalcon_substr(iv, text, 0, Z_LVAL_P(iv_size));
	
	PHALCON_INIT_VAR(text_to_decipher);
	phalcon_substr(text_to_decipher, text, Z_LVAL_P(iv_size), 0);

	PHALCON_OBS_VAR(decrypted);
	phalcon_call_func_p5_ex(decrypted, &decrypted, "mcrypt_decrypt", cipher, decrypt_key, text_to_decipher, mode, iv);
	if (unlikely(Z_TYPE_P(decrypted) != IS_STRING)) {
		convert_to_string(decrypted);
	}

	PHALCON_OBS_VAR(block_size);
	phalcon_call_func_p2_ex(block_size, &block_size, "mcrypt_get_block_size", cipher, mode);
	if (unlikely(Z_TYPE_P(block_size) != IS_LONG)) {
		convert_to_long(block_size);
	}

	padding_type = phalcon_fetch_nproperty_this(this_ptr, SL("_padding"), PH_NOISY_CC);

	assert(Z_TYPE_P(padding_type) == IS_LONG);
	assert(Z_TYPE_P(block_size) == IS_LONG);
	assert(Z_TYPE_P(mode) == IS_STRING);
	assert(Z_TYPE_P(decrypted) == IS_STRING);

	phalcon_crypt_unpad_text(return_value, decrypted, mode, Z_LVAL_P(block_size), Z_LVAL_P(padding_type) TSRMLS_CC);
	RETURN_MM();
}

/**
 * Encrypts a text returning the result as a base64 string
 *
 * @param string $text
 * @param string $key
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, encryptBase64){

	zval *text, *key = NULL, *encrypted;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &text, &key);
	
	if (!key) {
		PHALCON_INIT_VAR(key);
	}
	
	PHALCON_OBS_VAR(encrypted);
	phalcon_call_method_p2_ex(encrypted, &encrypted, this_ptr, "encrypt", text, key);
	phalcon_base64_encode(return_value, encrypted);
	RETURN_MM();
}

/**
 * Decrypt a text that is coded as a base64 string
 *
 * @param string $text
 * @param string $key
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, decryptBase64){

	zval *text, *key = NULL, *decrypt_text;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &text, &key);
	
	if (!key) {
		PHALCON_INIT_VAR(key);
	}
	
	PHALCON_INIT_VAR(decrypt_text);
	phalcon_base64_decode(decrypt_text, text);
	phalcon_call_method_p2(return_value, this_ptr, "decrypt", decrypt_text, key);
	RETURN_MM();
}

/**
 * Returns a list of available cyphers
 *
 * @return array
 */
PHP_METHOD(Phalcon_Crypt, getAvailableCiphers){


	PHALCON_MM_GROW();

	phalcon_call_func(return_value, "mcrypt_list_algorithms");
	RETURN_MM();
}

/**
 * Returns a list of available modes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Crypt, getAvailableModes){


	PHALCON_MM_GROW();

	phalcon_call_func(return_value, "mcrypt_list_modes");
	RETURN_MM();
}
