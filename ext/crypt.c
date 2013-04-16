
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
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"

/**
 * Phalcon\Crypt
 *
 * Provides encryption facilities to phalcon applications
 */


/**
 * Phalcon\Crypt initializer
 */
PHALCON_INIT_CLASS(Phalcon_Crypt){

	PHALCON_REGISTER_CLASS(Phalcon, Crypt, crypt, phalcon_crypt_method_entry, 0);

	zend_declare_property_null(phalcon_crypt_ce, SL("_key"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_crypt_ce, SL("_mode"), "cbc", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_crypt_ce, SL("_cipher"), "rijndael-256", ZEND_ACC_PROTECTED TSRMLS_CC);

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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &cipher) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_cipher"), cipher TSRMLS_CC);
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &mode) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_mode"), mode TSRMLS_CC);
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &key) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_key"), key TSRMLS_CC);
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
 * Encrypts a text
 *
 * @param string $text
 * @param string $key
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, encrypt){

	zval *text, *key = NULL, *cipher, *mode, *iv_size, *key_size;
	zval *too_large, *rand, *iv, *encrypt, *final_encrypt;
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &text, &key) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!key) {
		PHALCON_INIT_VAR(key);
	} else {
		PHALCON_SEPARATE_PARAM(key);
	}
	
	if (Z_TYPE_P(key) == IS_NULL) {
		PHALCON_OBS_NVAR(key);
		phalcon_read_property_this(&key, this_ptr, SL("_key"), PH_NOISY_CC);
	}
	
	PHALCON_OBS_VAR(cipher);
	phalcon_read_property_this(&cipher, this_ptr, SL("_cipher"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(mode);
	phalcon_read_property_this(&mode, this_ptr, SL("_mode"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(iv_size);
	PHALCON_CALL_FUNC_PARAMS_2(iv_size, "mcrypt_get_iv_size", cipher, mode);
	
	PHALCON_INIT_VAR(key_size);
	phalcon_fast_strlen(key_size, key);
	
	PHALCON_INIT_VAR(too_large);
	is_smaller_function(too_large, iv_size, key_size TSRMLS_CC);
	if (PHALCON_IS_TRUE(too_large)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_exception_ce, "Size of key is too large for this algorithm");
		return;
	}
	
	PHALCON_INIT_VAR(rand);
	ZVAL_LONG(rand, 2);
	
	PHALCON_INIT_VAR(iv);
	PHALCON_CALL_FUNC_PARAMS_2(iv, "mcrypt_create_iv", iv_size, rand);
	
	p0[0] = cipher;
	p0[1] = key;
	p0[2] = text;
	p0[3] = mode;
	p0[4] = iv;
	
	PHALCON_INIT_VAR(encrypt);
	PHALCON_CALL_FUNC_PARAMS(encrypt, "mcrypt_encrypt", 5, p0);
	
	PHALCON_INIT_VAR(final_encrypt);
	PHALCON_CONCAT_VV(final_encrypt, iv, encrypt);
	
	RETURN_CTOR(final_encrypt);
}

/**
 * Decrypts a text
 *
 * @param string $text
 * @param string $key
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, decrypt){

	zval *text, *key = NULL, *cipher, *mode, *iv_size, *key_size;
	zval *too_large, *zero, *iv, *text_to_decipher;
	zval *decrypted;
	zval *p0[] = { NULL, NULL, NULL, NULL, NULL };

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &text, &key) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!key) {
		PHALCON_INIT_VAR(key);
	} else {
		PHALCON_SEPARATE_PARAM(key);
	}
	
	if (Z_TYPE_P(key) == IS_NULL) {
		PHALCON_OBS_NVAR(key);
		phalcon_read_property_this(&key, this_ptr, SL("_key"), PH_NOISY_CC);
	}
	
	PHALCON_OBS_VAR(cipher);
	phalcon_read_property_this(&cipher, this_ptr, SL("_cipher"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(mode);
	phalcon_read_property_this(&mode, this_ptr, SL("_mode"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(iv_size);
	PHALCON_CALL_FUNC_PARAMS_2(iv_size, "mcrypt_get_iv_size", cipher, mode);
	
	PHALCON_INIT_VAR(key_size);
	phalcon_fast_strlen(key_size, key);
	
	PHALCON_INIT_VAR(too_large);
	is_smaller_function(too_large, iv_size, key_size TSRMLS_CC);
	if (PHALCON_IS_TRUE(too_large)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_exception_ce, "Size of key is too large for this algorithm");
		return;
	}
	
	PHALCON_INIT_VAR(zero);
	ZVAL_LONG(zero, 0);
	
	PHALCON_INIT_VAR(iv);
	PHALCON_CALL_FUNC_PARAMS_3(iv, "substr", text, zero, iv_size);
	
	PHALCON_INIT_VAR(text_to_decipher);
	PHALCON_CALL_FUNC_PARAMS_2(text_to_decipher, "substr", text, iv_size);
	
	p0[0] = cipher;
	p0[1] = key;
	p0[2] = text_to_decipher;
	p0[3] = mode;
	p0[4] = iv;
	
	PHALCON_INIT_VAR(decrypted);
	PHALCON_CALL_FUNC_PARAMS(decrypted, "mcrypt_decrypt", 5, p0);
	
	RETURN_CCTOR(decrypted);
}

/**
 * Encrypts a text returning the result as a base64 string
 *
 * @param string $text
 * @param string $key
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, encryptBase64){

	zval *text, *key = NULL, *encrypted, *encoded;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &text, &key) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!key) {
		PHALCON_INIT_VAR(key);
	}
	
	PHALCON_INIT_VAR(encrypted);
	PHALCON_CALL_METHOD_PARAMS_2(encrypted, this_ptr, "encrypt", text, key);
	
	PHALCON_INIT_VAR(encoded);
	PHALCON_CALL_FUNC_PARAMS_1(encoded, "base64_encode", encrypted);
	RETURN_CCTOR(encoded);
}

/**
 * Decrypt a text that is coded as a base64 string
 *
 * @param string $text
 * @param string $key
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, decryptBase64){

	zval *text, *key = NULL, *decrypt_text, *decrypted;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &text, &key) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!key) {
		PHALCON_INIT_VAR(key);
	}
	
	PHALCON_INIT_VAR(decrypt_text);
	PHALCON_CALL_FUNC_PARAMS_1(decrypt_text, "base64_decode", text);
	
	PHALCON_INIT_VAR(decrypted);
	PHALCON_CALL_METHOD_PARAMS_2(decrypted, this_ptr, "decrypt", decrypt_text, key);
	RETURN_CCTOR(decrypted);
}

PHP_METHOD(Phalcon_Crypt, getAvailableCiphers){


	
}

