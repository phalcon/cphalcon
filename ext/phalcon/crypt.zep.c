
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Crypt) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Crypt, phalcon, crypt, phalcon_crypt_method_entry, 0);

	zend_declare_property_null(phalcon_crypt_ce, SL("_key"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_crypt_ce, SL("_mode"), "cbc", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_crypt_ce, SL("_cipher"), "rijndael-256", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_crypt_ce TSRMLS_CC, 1, phalcon_cryptinterface_ce);
	return SUCCESS;

}

/**
 * Sets the cipher algorithm
 *
 * @param string cipher
 * @return Phalcon\Crypt
 */
PHP_METHOD(Phalcon_Crypt, setCipher) {

	zval *cipher_param = NULL;
	zval *cipher = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cipher_param);

	if (unlikely(Z_TYPE_P(cipher_param) != IS_STRING && Z_TYPE_P(cipher_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cipher' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(cipher_param) == IS_STRING)) {
		cipher = cipher_param;
	} else {
		ZEPHIR_INIT_VAR(cipher);
		ZVAL_EMPTY_STRING(cipher);
	}


	zephir_update_property_this(this_ptr, SL("_cipher"), cipher TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the current cipher
 *
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, getCipher) {


	RETURN_MEMBER(this_ptr, "_cipher");

}

/**
 * Sets the encrypt/decrypt mode
 *
 * @param string cipher
 * @return Phalcon\Crypt
 */
PHP_METHOD(Phalcon_Crypt, setMode) {

	zval *mode;

	zephir_fetch_params(0, 1, 0, &mode);



	zephir_update_property_this(this_ptr, SL("_mode"), mode TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns the current encryption mode
 *
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, getMode) {


	RETURN_MEMBER(this_ptr, "_mode");

}

/**
 * Sets the encryption key
 *
 * @param string key
 * @return Phalcon\Crypt
 */
PHP_METHOD(Phalcon_Crypt, setKey) {

	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(key_param) == IS_STRING)) {
		key = key_param;
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_update_property_this(this_ptr, SL("_key"), key TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the encryption key
 *
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, getKey) {


	RETURN_MEMBER(this_ptr, "_key");

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
PHP_METHOD(Phalcon_Crypt, encrypt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *key = NULL, *encryptKey = NULL, *ivSize = NULL, *iv = NULL, *cipher, *mode, _0, *_1 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key);

	if (unlikely(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(text_param) == IS_STRING)) {
		text = text_param;
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}


	if (!((zephir_function_exists_ex(SS("mcrypt_get_iv_size") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "mcrypt extension is required", "phalcon/crypt.zep", 131);
		return;
	}
	if (Z_TYPE_P(key) == IS_NULL) {
		ZEPHIR_OBS_VAR(encryptKey);
		zephir_read_property_this(&encryptKey, this_ptr, SL("_key"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(encryptKey, key);
	}
	if (ZEPHIR_IS_EMPTY(encryptKey)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Encryption key cannot be empty", "phalcon/crypt.zep", 141);
		return;
	}
	ZEPHIR_OBS_VAR(cipher);
	zephir_read_property_this(&cipher, this_ptr, SL("_cipher"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(mode);
	zephir_read_property_this(&mode, this_ptr, SL("_mode"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&ivSize, "mcrypt_get_iv_size", NULL, cipher, mode);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(ivSize, zephir_fast_strlen_ev(encryptKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Size of key is too large for this algorithm", "phalcon/crypt.zep", 148);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&iv, "mcrypt_create_iv", NULL, ivSize, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "mcrypt_encrypt", NULL, cipher, encryptKey, text, mode, iv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, iv, _1);
	RETURN_MM();

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
PHP_METHOD(Phalcon_Crypt, decrypt) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *key = NULL, *decryptKey = NULL, *ivSize = NULL, *cipher, *mode, *keySize, *_0 = NULL, _2, *_3 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key);

	if (unlikely(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(text_param) == IS_STRING)) {
		text = text_param;
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}


	if (!((zephir_function_exists_ex(SS("mcrypt_get_iv_size") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "mcrypt extension is required", "phalcon/crypt.zep", 171);
		return;
	}
	if (Z_TYPE_P(key) == IS_NULL) {
		ZEPHIR_OBS_VAR(decryptKey);
		zephir_read_property_this(&decryptKey, this_ptr, SL("_key"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(decryptKey, key);
	}
	if (ZEPHIR_IS_EMPTY(decryptKey)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Decryption key cannot be empty", "phalcon/crypt.zep", 181);
		return;
	}
	ZEPHIR_OBS_VAR(cipher);
	zephir_read_property_this(&cipher, this_ptr, SL("_cipher"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(mode);
	zephir_read_property_this(&mode, this_ptr, SL("_mode"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&ivSize, "mcrypt_get_iv_size", NULL, cipher, mode);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(keySize);
	ZVAL_LONG(keySize, zephir_fast_strlen_ev(decryptKey));
	if (ZEPHIR_GT(keySize, ivSize)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Size of key is too large for this algorithm", "phalcon/crypt.zep", 190);
		return;
	}
	if (ZEPHIR_GT_LONG(keySize, zephir_fast_strlen_ev(text))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Size of IV is larger than text to decrypt", "phalcon/crypt.zep", 194);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_0, "substr", &_1, text, ivSize);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, 0);
	ZEPHIR_CALL_FUNCTION(&_3, "substr", &_1, text, &_2, ivSize);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("mcrypt_decrypt", NULL, cipher, decryptKey, _0, mode, _3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Encrypts a text returning the result as a base64 string
 *
 * @param string text
 * @param string key
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, encryptBase64) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *key = NULL, *_0 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key);

	if (unlikely(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(text_param) == IS_STRING)) {
		text = text_param;
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "encrypt", NULL, text, key);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", &_1, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decrypt a text that is coded as a base64 string
 *
 * @param string text
 * @param string key
 * @return string
 */
PHP_METHOD(Phalcon_Crypt, decryptBase64) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *text_param = NULL, *key = NULL, *_0 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key);

	if (unlikely(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(text_param) == IS_STRING)) {
		text = text_param;
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "base64_decode", &_1, text);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "decrypt", NULL, _0, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a list of available cyphers
 *
 * @return array
 */
PHP_METHOD(Phalcon_Crypt, getAvailableCiphers) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("mcrypt_list_algorithms", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a list of available modes
 *
 * @return array
 */
PHP_METHOD(Phalcon_Crypt, getAvailableModes) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("mcrypt_list_modes", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

