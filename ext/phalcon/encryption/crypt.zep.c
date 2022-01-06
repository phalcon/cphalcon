
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption, Crypt, phalcon, encryption_crypt, phalcon_encryption_crypt_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_encryption_crypt_ce, SL("authData"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_encryption_crypt_ce, SL("authTag"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_encryption_crypt_ce, SL("authTagLength"), 16, ZEND_ACC_PROTECTED);
	/**
	 * Available cipher methods.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_encryption_crypt_ce, SL("availableCiphers"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_encryption_crypt_ce, SL("cipher"), "aes-256-cfb", ZEND_ACC_PROTECTED);
	/**
	 * The name of hashing algorithm.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_encryption_crypt_ce, SL("hashAlgorithm"), "sha256", ZEND_ACC_PROTECTED);
	/**
	 * The cipher iv length.
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_encryption_crypt_ce, SL("ivLength"), 16, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_encryption_crypt_ce, SL("key"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_encryption_crypt_ce, SL("padding"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var PadFactory
	 */
	zend_declare_property_null(phalcon_encryption_crypt_ce, SL("padFactory"), ZEND_ACC_PROTECTED);
	/**
	 * Whether calculating message digest enabled or not.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_encryption_crypt_ce, SL("useSigning"), 1, ZEND_ACC_PROTECTED);
	phalcon_encryption_crypt_ce->create_object = zephir_init_properties_Phalcon_Encryption_Crypt;
	/**
	 * Defaults
	 */
	zephir_declare_class_constant_string(phalcon_encryption_crypt_ce, SL("DEFAULT_ALGORITHM"), "sha256");

	zephir_declare_class_constant_string(phalcon_encryption_crypt_ce, SL("DEFAULT_CIPHER"), "aes-256-cfb");

	/**
	 * Padding
	 */
	zephir_declare_class_constant_long(phalcon_encryption_crypt_ce, SL("PADDING_ANSI_X_923"), 1);

	zephir_declare_class_constant_long(phalcon_encryption_crypt_ce, SL("PADDING_DEFAULT"), 0);

	zephir_declare_class_constant_long(phalcon_encryption_crypt_ce, SL("PADDING_ISO_10126"), 3);

	zephir_declare_class_constant_long(phalcon_encryption_crypt_ce, SL("PADDING_ISO_IEC_7816_4"), 4);

	zephir_declare_class_constant_long(phalcon_encryption_crypt_ce, SL("PADDING_PKCS7"), 2);

	zephir_declare_class_constant_long(phalcon_encryption_crypt_ce, SL("PADDING_SPACE"), 6);

	zephir_declare_class_constant_long(phalcon_encryption_crypt_ce, SL("PADDING_ZERO"), 5);

	zend_class_implements(phalcon_encryption_crypt_ce, 1, phalcon_encryption_crypt_cryptinterface_ce);
	return SUCCESS;
}

/**
 * Crypt constructor.
 *
 * @param string          $cipher
 * @param bool            $useSigning
 * @param PadFactory|null $padFactory
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Encryption_Crypt, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool useSigning;
	zval *cipher_param = NULL, *useSigning_param = NULL, *padFactory = NULL, padFactory_sub, __$null, _0, _1, _2, _3;
	zval cipher;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&padFactory_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(cipher)
		Z_PARAM_BOOL(useSigning)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(padFactory, phalcon_encryption_crypt_padfactory_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &cipher_param, &useSigning_param, &padFactory);
	if (!cipher_param) {
		ZEPHIR_INIT_VAR(&cipher);
		ZVAL_STRING(&cipher, "aes-256-cfb");
	} else {
		zephir_get_strval(&cipher, cipher_param);
	}
	if (!useSigning_param) {
		useSigning = 1;
	} else {
		useSigning = zephir_get_boolval(useSigning_param);
	}
	if (!padFactory) {
		padFactory = &padFactory_sub;
		ZEPHIR_CPY_WRT(padFactory, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(padFactory);
	}


	if (Z_TYPE_P(padFactory) == IS_NULL) {
		ZEPHIR_INIT_NVAR(padFactory);
		object_init_ex(padFactory, phalcon_encryption_crypt_padfactory_ce);
		ZEPHIR_CALL_METHOD(NULL, padFactory, "__construct", NULL, 239);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("padFactory"), padFactory);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "sha256");
	zephir_update_property_zval(this_ptr, ZEND_STRL("hashAlgorithm"), &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "initializeavailableciphers", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_1, "setcipher", NULL, 0, &cipher);
	zephir_check_call_status();
	if (useSigning) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_2, "usesigning", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
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
PHP_METHOD(Phalcon_Encryption_Crypt, decrypt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, *key_param = NULL, __$true, __$null, blockSize, cipher, cipherText, decrypted, decryptKey, digest, hashAlgorithm, hashLength, iv, ivLength, mode, padded, _0, _1, _6, _7, _2$$5, _3$$5, _4$$5, _5$$6, _8$$7;
	zval input, key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&key);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&blockSize);
	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&cipherText);
	ZVAL_UNDEF(&decrypted);
	ZVAL_UNDEF(&decryptKey);
	ZVAL_UNDEF(&digest);
	ZVAL_UNDEF(&hashAlgorithm);
	ZVAL_UNDEF(&hashLength);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&ivLength);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&padded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_8$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &input_param, &key_param);
	zephir_get_strval(&input, input_param);
	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
	} else {
		zephir_get_strval(&key, key_param);
	}


	ZEPHIR_OBS_VAR(&decryptKey);
	zephir_read_property(&decryptKey, this_ptr, ZEND_STRL("key"), PH_NOISY_CC);
	if (1 != ZEPHIR_IS_EMPTY(&key)) {
		ZEPHIR_CPY_WRT(&decryptKey, &key);
	}
	if (1 == ZEPHIR_IS_EMPTY(&decryptKey)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_crypt_exception_exception_ce, "Decryption key cannot be empty", "phalcon/Encryption/Crypt.zep", 175);
		return;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cipher, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("ivLength"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ivLength, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "cipher");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcipherhashisavailable", NULL, 0, &cipher, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&mode, this_ptr, "getmode", NULL, 240);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&blockSize, this_ptr, "getblocksize", NULL, 241, &mode);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "8bit");
	ZEPHIR_CALL_FUNCTION(&iv, "mb_substr", NULL, 242, &input, &_0, &ivLength, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&digest);
	ZVAL_STRING(&digest, "");
	ZEPHIR_CALL_METHOD(&hashAlgorithm, this_ptr, "gethashalgorithm", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("useSigning"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "");
		ZEPHIR_CALL_FUNCTION(&_3$$5, "hash", NULL, 99, &hashAlgorithm, &_2$$5, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&hashLength);
		ZVAL_LONG(&hashLength, zephir_fast_strlen_ev(&_3$$5));
		ZEPHIR_INIT_NVAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "8bit");
		ZEPHIR_CALL_FUNCTION(&digest, "mb_substr", NULL, 242, &input, &ivLength, &hashLength, &_2$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$5);
		zephir_add_function(&_4$$5, &ivLength, &hashLength);
		ZEPHIR_INIT_NVAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "8bit");
		ZEPHIR_CALL_FUNCTION(&cipherText, "mb_substr", NULL, 242, &input, &_4$$5, &__$null, &_2$$5);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_5$$6);
		ZVAL_STRING(&_5$$6, "8bit");
		ZEPHIR_CALL_FUNCTION(&cipherText, "mb_substr", NULL, 242, &input, &ivLength, &__$null, &_5$$6);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&decrypted, this_ptr, "decryptgcmccmauth", NULL, 0, &mode, &cipherText, &decryptKey, &iv);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&padded, &decrypted);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "decryptgetunpadded", NULL, 0, &mode, &blockSize, &decrypted);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&decrypted, &_6);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("useSigning"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_7)) {
		ZEPHIR_CALL_FUNCTION(&_8$$7, "hash_hmac", NULL, 243, &hashAlgorithm, &padded, &decryptKey, &__$true);
		zephir_check_call_status();
		if (!ZEPHIR_IS_IDENTICAL(&digest, &_8$$7)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_crypt_exception_mismatch_ce, "Hash does not match.", "phalcon/Encryption/Crypt.zep", 224);
			return;
		}
	}
	RETURN_CCTOR(&decrypted);
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
PHP_METHOD(Phalcon_Encryption_Crypt, decryptBase64)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool safe;
	zval *input_param = NULL, *key_param = NULL, *safe_param = NULL, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5;
	zval input, key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(key)
		Z_PARAM_BOOL(safe)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &input_param, &key_param, &safe_param);
	zephir_get_strval(&input, input_param);
	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
	} else {
		zephir_get_strval(&key, key_param);
	}
	if (!safe_param) {
		safe = 0;
	} else {
		safe = zephir_get_boolval(safe_param);
	}


	if (safe) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "-_");
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "+/");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "strtr", NULL, 5, &input, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "===");
		ZVAL_DOUBLE(&_3$$3, zephir_safe_mod_long_long(((zephir_fast_strlen_ev(&input) + 3)), 4));
		ZEPHIR_INIT_NVAR(&_1$$3);
		zephir_substr(&_1$$3, &_0$$3, zephir_get_intval(&_3$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_VV(&_4$$3, &_2$$3, &_1$$3);
		zephir_get_strval(&input, &_4$$3);
	}
	ZEPHIR_CALL_FUNCTION(&_5, "base64_decode", NULL, 244, &input);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "decrypt", NULL, 0, &_5, &key);
	zephir_check_call_status();
	RETURN_MM();
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
PHP_METHOD(Phalcon_Encryption_Crypt, encrypt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, *key_param = NULL, __$true, blockSize, cipher, digest, encryptKey, encrypted, iv, ivLength, mode, padded, _0, _1, _2$$6;
	zval input, key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&key);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&blockSize);
	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&digest);
	ZVAL_UNDEF(&encryptKey);
	ZVAL_UNDEF(&encrypted);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&ivLength);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&padded);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &input_param, &key_param);
	zephir_get_strval(&input, input_param);
	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
	} else {
		zephir_get_strval(&key, key_param);
	}


	ZEPHIR_OBS_VAR(&encryptKey);
	zephir_read_property(&encryptKey, this_ptr, ZEND_STRL("key"), PH_NOISY_CC);
	if (1 != ZEPHIR_IS_EMPTY(&key)) {
		ZEPHIR_CPY_WRT(&encryptKey, &key);
	}
	if (1 == ZEPHIR_IS_EMPTY(&encryptKey)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_crypt_exception_exception_ce, "Encryption key cannot be empty", "phalcon/Encryption/Crypt.zep", 282);
		return;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cipher, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("ivLength"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ivLength, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "cipher");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcipherhashisavailable", NULL, 0, &cipher, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&mode, this_ptr, "getmode", NULL, 240);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&blockSize, this_ptr, "getblocksize", NULL, 241, &mode);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&iv, this_ptr, "phpopensslrandompseudobytes", NULL, 0, &ivLength);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&iv)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_crypt_exception_exception_ce, "Cannot calculate Random Pseudo Bytes", "phalcon/Encryption/Crypt.zep", 295);
		return;
	}
	ZEPHIR_CALL_METHOD(&padded, this_ptr, "encryptgetpadded", NULL, 0, &mode, &input, &blockSize);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&encrypted, this_ptr, "encryptgcmccm", NULL, 0, &mode, &padded, &encryptKey, &iv);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("useSigning"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_METHOD(&_2$$6, this_ptr, "gethashalgorithm", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&digest, "hash_hmac", NULL, 243, &_2$$6, &padded, &encryptKey, &__$true);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVV(return_value, &iv, &digest, &encrypted);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_VV(return_value, &iv, &encrypted);
	RETURN_MM();
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
PHP_METHOD(Phalcon_Encryption_Crypt, encryptBase64)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool safe;
	zval *input_param = NULL, *key_param = NULL, *safe_param = NULL, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5;
	zval input, key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(input)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(key)
		Z_PARAM_BOOL(safe)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &input_param, &key_param, &safe_param);
	zephir_get_strval(&input, input_param);
	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
	} else {
		zephir_get_strval(&key, key_param);
	}
	if (!safe_param) {
		safe = 0;
	} else {
		safe = zephir_get_boolval(safe_param);
	}


	if (safe) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "encrypt", NULL, 0, &input, &key);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_1$$3, "base64_encode", NULL, 245, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "+/");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "-_");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "strtr", NULL, 5, &_1$$3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "=");
		zephir_fast_trim(return_value, &_4$$3, &_2$$3, ZEPHIR_TRIM_RIGHT);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "encrypt", NULL, 0, &input, &key);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 245, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns a list of available ciphers.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Encryption_Crypt, getAvailableCiphers)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "availableCiphers");
}

/**
 * Returns the auth data
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Crypt, getAuthData)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "authData");
}

/**
 * Returns the auth tag
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Crypt, getAuthTag)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "authTag");
}

/**
 * Returns the auth tag length
 *
 * @return int
 */
PHP_METHOD(Phalcon_Encryption_Crypt, getAuthTagLength)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "authTagLength");
}

/**
 * Return a list of registered hashing algorithms suitable for hash_hmac.
 *
 * @return array
 */
PHP_METHOD(Phalcon_Encryption_Crypt, getAvailableHashAlgorithms)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "hash_hmac_algos");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpfunctionexists", NULL, 0, &_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_RETURN_CALL_FUNCTION("hash_hmac_algos", NULL, 246);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("hash_algos", NULL, 247);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get the name of hashing algorithm.
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Crypt, getHashAlgorithm)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "hashAlgorithm");
}

/**
 * Returns the current cipher
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Crypt, getCipher)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "cipher");
}

/**
 * Returns the encryption key
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Crypt, getKey)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "key");
}

/**
 * @param string $data
 *
 * @return CryptInterface
 */
PHP_METHOD(Phalcon_Encryption_Crypt, setAuthData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *data_param = NULL;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);
	zephir_get_strval(&data, data_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("authData"), &data);
	RETURN_THIS();
}

/**
 * @param string $tag
 *
 * @return CryptInterface
 */
PHP_METHOD(Phalcon_Encryption_Crypt, setAuthTag)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *tag_param = NULL;
	zval tag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tag);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(tag)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tag_param);
	zephir_get_strval(&tag, tag_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("authTag"), &tag);
	RETURN_THIS();
}

/**
 * @param int $length
 *
 * @return CryptInterface
 */
PHP_METHOD(Phalcon_Encryption_Crypt, setAuthTagLength)
{
	zval *length_param = NULL, _0;
	zend_long length;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &length_param);
	length = zephir_get_intval(length_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, length);
	zephir_update_property_zval(this_ptr, ZEND_STRL("authTagLength"), &_0);
	RETURN_THISW();
}

/**
 * Sets the cipher algorithm for data encryption and decryption.
 *
 * @param string $cipher
 *
 * @return CryptInterface
 * @throws Exception
 */
PHP_METHOD(Phalcon_Encryption_Crypt, setCipher)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cipher_param = NULL, _0, _1;
	zval cipher;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(cipher)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cipher_param);
	zephir_get_strval(&cipher, cipher_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "cipher");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcipherhashisavailable", NULL, 0, &cipher, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getivlength", NULL, 248, &cipher);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("ivLength"), &_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cipher"), &cipher);
	RETURN_THIS();
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
PHP_METHOD(Phalcon_Encryption_Crypt, setKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("key"), &key);
	RETURN_THIS();
}

/**
 * Set the name of hashing algorithm.
 *
 * @param string $hashAlgorithm
 *
 * @return CryptInterface
 * @throws Exception
 */
PHP_METHOD(Phalcon_Encryption_Crypt, setHashAlgorithm)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *hashAlgorithm_param = NULL, _0;
	zval hashAlgorithm;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hashAlgorithm);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(hashAlgorithm)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &hashAlgorithm_param);
	zephir_get_strval(&hashAlgorithm, hashAlgorithm_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "hash");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkcipherhashisavailable", NULL, 0, &hashAlgorithm, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("hashAlgorithm"), &hashAlgorithm);
	RETURN_THIS();
}

/**
 * Changes the padding scheme used.
 *
 * @param int $scheme
 *
 * @return CryptInterface
 */
PHP_METHOD(Phalcon_Encryption_Crypt, setPadding)
{
	zval *scheme_param = NULL, _0;
	zend_long scheme;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(scheme)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &scheme_param);
	scheme = zephir_get_intval(scheme_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, scheme);
	zephir_update_property_zval(this_ptr, ZEND_STRL("padding"), &_0);
	RETURN_THISW();
}

/**
 * Sets if the calculating message digest must used.
 *
 * @param bool $useSigning
 *
 * @return CryptInterface
 */
PHP_METHOD(Phalcon_Encryption_Crypt, useSigning)
{
	zval *useSigning_param = NULL, __$true, __$false;
	zend_bool useSigning;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(useSigning)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &useSigning_param);
	useSigning = zephir_get_boolval(useSigning_param);


	if (useSigning) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("useSigning"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("useSigning"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Checks if a cipher or a hash algorithm is available
 *
 * @param string $cipher
 * @param string $type
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Encryption_Crypt, checkCipherHashIsAvailable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cipher_param = NULL, *type_param = NULL, available, lower, method, _0, _1$$5, _2$$5, _3$$5;
	zval cipher, type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&available);
	ZVAL_UNDEF(&lower);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(cipher)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &cipher_param, &type_param);
	zephir_get_strval(&cipher, cipher_param);
	zephir_get_strval(&type, type_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "hash");
	ZEPHIR_INIT_VAR(&method);
	if (ZEPHIR_IS_IDENTICAL(&_0, &cipher)) {
		ZVAL_STRING(&method, "getAvailableHashAlgorithms");
	} else {
		ZVAL_STRING(&method, "getAvailableCiphers");
	}
	ZEPHIR_CALL_METHOD_ZVAL(&available, this_ptr, &method, NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&lower, "mb_strtolower", NULL, 10, &cipher);
	zephir_check_call_status();
	if (1 != zephir_array_isset(&available, &lower)) {
		ZEPHIR_INIT_VAR(&_1$$5);
		object_init_ex(&_1$$5, phalcon_encryption_crypt_exception_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "The %s algorithm '%s' is not supported on this system.");
		ZEPHIR_CALL_FUNCTION(&_3$$5, "sprintf", NULL, 140, &_2$$5, &type, &cipher);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 31, &_3$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$5, "phalcon/Encryption/Crypt.zep", 587);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
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
PHP_METHOD(Phalcon_Encryption_Crypt, cryptPadText)
{
	zend_bool _4$$3;
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long blockSize, paddingType, ZEPHIR_LAST_CALL_STATUS, paddingSize = 0;
	zval *input_param = NULL, *mode_param = NULL, *blockSize_param = NULL, *paddingType_param = NULL, padding, service, _0, _2, _9, _10, _3$$3, _5$$3, _6$$3, _7$$3, _8$$3;
	zval input, mode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&padding);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(input)
		Z_PARAM_STR(mode)
		Z_PARAM_LONG(blockSize)
		Z_PARAM_LONG(paddingType)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &input_param, &mode_param, &blockSize_param, &paddingType_param);
	zephir_get_strval(&input, input_param);
	zephir_get_strval(&mode, mode_param);
	blockSize = zephir_get_intval(blockSize_param);
	paddingType = zephir_get_intval(paddingType_param);


	ZEPHIR_INIT_VAR(&padding);
	ZVAL_STRING(&padding, "");
	paddingSize = 0;
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "cbc");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ecb");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkismode", NULL, 249, &_1, &mode);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_CALL_FUNCTION(&_3$$3, "mb_strlen", NULL, 250, &input);
		zephir_check_call_status();
		paddingSize = (blockSize - zephir_safe_mod_zval_long(&_3$$3, blockSize));
		_4$$3 = paddingSize >= 256;
		if (!(_4$$3)) {
			_4$$3 = paddingSize < 0;
		}
		if (_4$$3) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_crypt_exception_exception_ce, "Padding size cannot be less than 0 or greater than 256", "phalcon/Encryption/Crypt.zep", 620);
			return;
		}
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("padFactory"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_6$$3, paddingType);
		ZEPHIR_CALL_METHOD(&service, &_5$$3, "padnumbertoservice", NULL, 0, &_6$$3);
		zephir_check_call_status();
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("padFactory"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7$$3, &_6$$3, "newinstance", NULL, 0, &service);
		zephir_check_call_status();
		ZVAL_LONG(&_8$$3, paddingSize);
		ZEPHIR_CALL_METHOD(&padding, &_7$$3, "pad", NULL, 0, &_8$$3);
		zephir_check_call_status();
	}
	if (0 == paddingSize) {
		RETURN_CTOR(&input);
	}
	ZVAL_LONG(&_9, 0);
	ZVAL_LONG(&_10, paddingSize);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_substr(&_2, &padding, 0 , zephir_get_intval(&_10), 0);
	ZEPHIR_CONCAT_VV(return_value, &input, &_2);
	RETURN_MM();
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
PHP_METHOD(Phalcon_Encryption_Crypt, cryptUnpadText)
{
	zval _3;
	zend_bool _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long blockSize, paddingType, ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, *mode_param = NULL, *blockSize_param = NULL, *paddingType_param = NULL, length, paddingSize, service, _2, _4, _5$$3, _6$$3, _7$$3, _8$$3, _9$$6, _10$$6;
	zval input, mode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&paddingSize);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(input)
		Z_PARAM_STR(mode)
		Z_PARAM_LONG(blockSize)
		Z_PARAM_LONG(paddingType)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &input_param, &mode_param, &blockSize_param, &paddingType_param);
	zephir_get_strval(&input, input_param);
	zephir_get_strval(&mode, mode_param);
	blockSize = zephir_get_intval(blockSize_param);
	paddingType = zephir_get_intval(paddingType_param);


	ZEPHIR_INIT_VAR(&length);
	ZVAL_LONG(&length, zephir_fast_strlen_ev(&input));
	ZEPHIR_INIT_VAR(&paddingSize);
	ZVAL_LONG(&paddingSize, 0);
	_0 = ZEPHIR_GT_LONG(&length, 0);
	if (_0) {
		_0 = (zephir_safe_mod_zval_long(&length, blockSize) == 0);
	}
	_1 = _0;
	if (_1) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_create_array(&_3, 2, 0);
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "cbc");
		zephir_array_fast_append(&_3, &_4);
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_STRING(&_4, "ecb");
		zephir_array_fast_append(&_3, &_4);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "checkismode", NULL, 249, &_3, &mode);
		zephir_check_call_status();
		_1 = ZEPHIR_IS_TRUE_IDENTICAL(&_2);
	}
	if (_1) {
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("padFactory"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_6$$3, paddingType);
		ZEPHIR_CALL_METHOD(&service, &_5$$3, "padnumbertoservice", NULL, 0, &_6$$3);
		zephir_check_call_status();
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("padFactory"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7$$3, &_6$$3, "newinstance", NULL, 0, &service);
		zephir_check_call_status();
		ZVAL_LONG(&_8$$3, blockSize);
		ZEPHIR_CALL_METHOD(&paddingSize, &_7$$3, "unpad", NULL, 0, &input, &_8$$3);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(&paddingSize, 0)) {
			if (ZEPHIR_LE_LONG(&paddingSize, blockSize)) {
				if (ZEPHIR_LT(&paddingSize, &length)) {
					ZEPHIR_INIT_VAR(&_9$$6);
					zephir_sub_function(&_9$$6, &length, &paddingSize);
					ZVAL_LONG(&_10$$6, 0);
					zephir_substr(return_value, &input, 0 , zephir_get_intval(&_9$$6), 0);
					RETURN_MM();
				}
				RETURN_MM_STRING("");
			}
			ZEPHIR_INIT_NVAR(&paddingSize);
			ZVAL_LONG(&paddingSize, 0);
		}
	}
	if (ZEPHIR_IS_LONG_IDENTICAL(&paddingSize, 0)) {
		RETURN_CTOR(&input);
	}
	RETURN_MM_STRING("");
}

/**
 * @param string $mode
 * @param int    $blockSize
 * @param string $decrypted
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Crypt, decryptGetUnpadded)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long blockSize, ZEPHIR_LAST_CALL_STATUS;
	zval *mode_param = NULL, *blockSize_param = NULL, decrypted, *decrypted_param = NULL, padding, _0, _2, _3$$3, _4$$3;
	zval mode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&decrypted);
	ZVAL_UNDEF(&padding);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(mode)
		Z_PARAM_LONG(blockSize)
		Z_PARAM_STR(decrypted)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &mode_param, &blockSize_param, &decrypted_param);
	zephir_get_strval(&mode, mode_param);
	blockSize = zephir_get_intval(blockSize_param);
	zephir_get_strval(&decrypted, decrypted_param);


	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "cbc");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "ecb");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkismode", NULL, 249, &_1, &mode);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("padding"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&padding, &_3$$3);
		ZVAL_LONG(&_3$$3, blockSize);
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "cryptunpadtext", NULL, 0, &decrypted, &mode, &_3$$3, &padding);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&decrypted, &_4$$3);
	}
	RETURN_CCTOR(&decrypted);
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
PHP_METHOD(Phalcon_Encryption_Crypt, decryptGcmCcmAuth)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mode_param = NULL, *cipherText_param = NULL, *decryptKey_param = NULL, *iv_param = NULL, authData, authTag, authTagLength, cipher, encrypted, decrypted, _0, _1, _3, _4$$3, _5$$3, _6$$4;
	zval mode, cipherText, decryptKey, iv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&cipherText);
	ZVAL_UNDEF(&decryptKey);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&authData);
	ZVAL_UNDEF(&authTag);
	ZVAL_UNDEF(&authTagLength);
	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&encrypted);
	ZVAL_UNDEF(&decrypted);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(mode)
		Z_PARAM_STR(cipherText)
		Z_PARAM_STR(decryptKey)
		Z_PARAM_STR(iv)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &mode_param, &cipherText_param, &decryptKey_param, &iv_param);
	zephir_get_strval(&mode, mode_param);
	zephir_get_strval(&cipherText, cipherText_param);
	zephir_get_strval(&decryptKey, decryptKey_param);
	zephir_get_strval(&iv, iv_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cipher, &_0);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "ccm");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "gcm");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "checkismode", NULL, 249, &_2, &mode);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("authData"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&authData, &_4$$3);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("authTagLength"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&authTagLength, &_4$$3);
		zephir_negate(&authTagLength);
		ZEPHIR_INIT_VAR(&authTag);
		zephir_substr(&authTag, &cipherText, zephir_get_intval(&authTagLength), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "");
		ZEPHIR_INIT_VAR(&encrypted);
		zephir_fast_str_replace(&encrypted, &authTag, &_5$$3, &cipherText);
		ZVAL_LONG(&_4$$3, 1);
		ZEPHIR_CALL_FUNCTION(&decrypted, "openssl_decrypt", NULL, 251, &encrypted, &cipher, &decryptKey, &_4$$3, &iv, &authTag, &authData);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_6$$4, 1);
		ZEPHIR_CALL_FUNCTION(&decrypted, "openssl_decrypt", NULL, 251, &cipherText, &cipher, &decryptKey, &_6$$4, &iv);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(&decrypted)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_crypt_exception_exception_ce, "Could not decrypt data", "phalcon/Encryption/Crypt.zep", 761);
		return;
	}
	RETURN_CCTOR(&decrypted);
}

/**
 * @param string $mode
 * @param string $input
 * @param int    $blockSize
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Encryption_Crypt, encryptGetPadded)
{
	zval _3;
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long blockSize, ZEPHIR_LAST_CALL_STATUS;
	zval *mode_param = NULL, *input_param = NULL, *blockSize_param = NULL, _0, _2, _4, _5$$3, _6$$3;
	zval mode, input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(mode)
		Z_PARAM_STR(input)
		Z_PARAM_LONG(blockSize)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &mode_param, &input_param, &blockSize_param);
	zephir_get_strval(&mode, mode_param);
	zephir_get_strval(&input, input_param);
	blockSize = zephir_get_intval(blockSize_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("padding"), PH_NOISY_CC | PH_READONLY);
	_1 = !ZEPHIR_IS_LONG_IDENTICAL(&_0, 0);
	if (_1) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_create_array(&_3, 2, 0);
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "cbc");
		zephir_array_fast_append(&_3, &_4);
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_STRING(&_4, "ecb");
		zephir_array_fast_append(&_3, &_4);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "checkismode", NULL, 249, &_3, &mode);
		zephir_check_call_status();
		_1 = ZEPHIR_IS_TRUE_IDENTICAL(&_2);
	}
	if (_1) {
		zephir_read_property(&_5$$3, this_ptr, ZEND_STRL("padding"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_6$$3, blockSize);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "cryptpadtext", NULL, 0, &input, &mode, &_6$$3, &_5$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CTOR(&input);
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
PHP_METHOD(Phalcon_Encryption_Crypt, encryptGcmCcm)
{
	zval _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mode_param = NULL, *padded_param = NULL, *encryptKey_param = NULL, *iv_param = NULL, authData, authTag, authTagLength, cipher, encrypted, _0, _1, _3, _4$$3, _5$$5;
	zval mode, padded, encryptKey, iv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&padded);
	ZVAL_UNDEF(&encryptKey);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&authData);
	ZVAL_UNDEF(&authTag);
	ZVAL_UNDEF(&authTagLength);
	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&encrypted);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(mode)
		Z_PARAM_STR(padded)
		Z_PARAM_STR(encryptKey)
		Z_PARAM_STR(iv)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &mode_param, &padded_param, &encryptKey_param, &iv_param);
	zephir_get_strval(&mode, mode_param);
	zephir_get_strval(&padded, padded_param);
	zephir_get_strval(&encryptKey, encryptKey_param);
	zephir_get_strval(&iv, iv_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cipher, &_0);
	ZEPHIR_INIT_VAR(&authTag);
	ZVAL_STRING(&authTag, "");
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "ccm");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "gcm");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "checkismode", NULL, 249, &_2, &mode);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_1)) {
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("authData"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&authData, &_4$$3);
		if (1 == ZEPHIR_IS_EMPTY(&authData)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_crypt_exception_exception_ce, "Auth data must be provided when using AEAD mode", "phalcon/Encryption/Crypt.zep", 820);
			return;
		}
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("authTag"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&authTag, &_4$$3);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("authTagLength"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&authTagLength, &_4$$3);
		ZVAL_LONG(&_4$$3, 1);
		ZEPHIR_MAKE_REF(&authTag);
		ZEPHIR_CALL_FUNCTION(&encrypted, "openssl_encrypt", NULL, 252, &padded, &cipher, &encryptKey, &_4$$3, &iv, &authTag, &authData, &authTagLength);
		ZEPHIR_UNREF(&authTag);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("authTag"), &authTag);
	} else {
		ZVAL_LONG(&_5$$5, 1);
		ZEPHIR_CALL_FUNCTION(&encrypted, "openssl_encrypt", NULL, 252, &padded, &cipher, &encryptKey, &_5$$5, &iv);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(&encrypted)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_crypt_exception_exception_ce, "Could not encrypt data", "phalcon/Encryption/Crypt.zep", 849);
		return;
	}
	ZEPHIR_CONCAT_VV(return_value, &encrypted, &authTag);
	RETURN_MM();
}

/**
 * Initialize available cipher algorithms.
 *
 * @return Crypt
 * @throws Exception
 */
PHP_METHOD(Phalcon_Encryption_Crypt, initializeAvailableCiphers)
{
	zend_bool _4$$4, _5$$4, _6$$4, _7$$6, _8$$6, _9$$6;
	zval allowed;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, available, cipher, _0, _1, *_2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&available);
	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&allowed);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "openssl_get_cipher_methods");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "phpfunctionexists", NULL, 0, &_1);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_crypt_exception_exception_ce, "This class requires the openssl extension for PHP", "phalcon/Encryption/Crypt.zep", 871);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&available, "openssl_get_cipher_methods", NULL, 253, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&allowed);
	array_init(&allowed);
	zephir_is_iterable(&available, 0, "phalcon/Encryption/Crypt.zep", 888);
	if (Z_TYPE_P(&available) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&available), _2)
		{
			ZEPHIR_INIT_NVAR(&cipher);
			ZVAL_COPY(&cipher, _2);
			_4$$4 = 1 != zephir_start_with_str(&cipher, SL("des"));
			if (_4$$4) {
				_4$$4 = 1 != zephir_start_with_str(&cipher, SL("rc2"));
			}
			_5$$4 = _4$$4;
			if (_5$$4) {
				_5$$4 = 1 != zephir_start_with_str(&cipher, SL("rc4"));
			}
			_6$$4 = _5$$4;
			if (_6$$4) {
				_6$$4 = 1 != zephir_end_with_str(&cipher, SL("ecb"));
			}
			if (_6$$4) {
				zephir_array_update_zval(&allowed, &cipher, &cipher, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &available, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &available, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&cipher, &available, "current", NULL, 0);
			zephir_check_call_status();
				_7$$6 = 1 != zephir_start_with_str(&cipher, SL("des"));
				if (_7$$6) {
					_7$$6 = 1 != zephir_start_with_str(&cipher, SL("rc2"));
				}
				_8$$6 = _7$$6;
				if (_8$$6) {
					_8$$6 = 1 != zephir_start_with_str(&cipher, SL("rc4"));
				}
				_9$$6 = _8$$6;
				if (_9$$6) {
					_9$$6 = 1 != zephir_end_with_str(&cipher, SL("ecb"));
				}
				if (_9$$6) {
					zephir_array_update_zval(&allowed, &cipher, &cipher, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &available, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&cipher);
	zephir_update_property_zval(this_ptr, ZEND_STRL("availableCiphers"), &allowed);
	RETURN_THIS();
}

/**
 * Checks if a mode (string) is in the values to compare (modes array)
 *
 * @param array  $modes
 * @param string $mode
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Encryption_Crypt, checkIsMode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval mode;
	zval *modes_param = NULL, *mode_param = NULL;
	zval modes;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modes);
	ZVAL_UNDEF(&mode);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(modes)
		Z_PARAM_STR(mode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &modes_param, &mode_param);
	zephir_get_arrval(&modes, modes_param);
	zephir_get_strval(&mode, mode_param);


	RETURN_MM_BOOL(zephir_fast_in_array(&mode, &modes));
}

/**
 * Returns the block size
 *
 * @param string $mode
 *
 * @return int
 * @throws Exception
 */
PHP_METHOD(Phalcon_Encryption_Crypt, getBlockSize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mode_param = NULL, _0, _2, _3, _4;
	zval mode, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(mode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mode_param);
	zephir_get_strval(&mode, mode_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("ivLength"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_0, 0)) {
		RETURN_MM_MEMBER(getThis(), "ivLength");
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "-", &mode);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "");
	ZEPHIR_CALL_FUNCTION(&_4, "str_ireplace", NULL, 254, &_1, &_3, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getivlength", NULL, 248, &_4);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Initialize available cipher algorithms.
 *
 * @param string $cipher
 *
 * @return int
 * @throws Exception
 */
PHP_METHOD(Phalcon_Encryption_Crypt, getIvLength)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cipher_param = NULL, length;
	zval cipher;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&length);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(cipher)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cipher_param);
	zephir_get_strval(&cipher, cipher_param);


	ZEPHIR_CALL_FUNCTION(&length, "openssl_cipher_iv_length", NULL, 255, &cipher);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&length)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_encryption_crypt_exception_exception_ce, "Cannot calculate the initialization vector (IV) length of the cipher", "phalcon/Encryption/Crypt.zep", 941);
		return;
	}
	RETURN_CCTOR(&length);
}

/**
 * Returns the mode (last few characters of the cipher)
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Crypt, getMode)
{
	zval position, _0, _1, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "-");
	ZEPHIR_CALL_FUNCTION(&_2, "strrpos", NULL, 123, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&position);
	ZVAL_LONG(&position, zephir_get_intval(&_2));
	zephir_read_property(&_3, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_5, ((zephir_get_numberval(&position) - zephir_fast_strlen_ev(&_4)) + 1));
	ZEPHIR_INIT_NVAR(&_1);
	zephir_substr(&_1, &_3, zephir_get_intval(&_5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_strtolower", NULL, 10, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @todo to be removed when we get traits
 */
PHP_METHOD(Phalcon_Encryption_Crypt, phpFunctionExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);


	RETURN_MM_BOOL((zephir_function_exists(&name) == SUCCESS));
}

PHP_METHOD(Phalcon_Encryption_Crypt, phpOpensslRandomPseudoBytes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *length_param = NULL, _0;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &length_param);
	length = zephir_get_intval(length_param);


	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_random_pseudo_bytes", NULL, 256, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Encryption_Crypt(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("availableCiphers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("availableCiphers"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

