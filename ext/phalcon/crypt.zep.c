
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Provides encryption capabilities to Phalcon applications.
 *
 * ```php
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
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Crypt) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Crypt, phalcon, crypt, phalcon_crypt_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_crypt_ce, SL("authTag"), ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_crypt_ce, SL("authData"), "", ZEND_ACC_PROTECTED);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_crypt_ce, SL("authTagLength"), 16, ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_crypt_ce, SL("key"), "", ZEND_ACC_PROTECTED);

	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_crypt_ce, SL("padding"), 0, ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_crypt_ce, SL("cipher"), "aes-256-cfb", ZEND_ACC_PROTECTED);

	/**
	 * Available cipher methods.
	 * @var array
	 */
	zend_declare_property_null(phalcon_crypt_ce, SL("availableCiphers"), ZEND_ACC_PROTECTED);

	/**
	 * The cipher iv length.
	 * @var int
	 */
	zend_declare_property_long(phalcon_crypt_ce, SL("ivLength"), 16, ZEND_ACC_PROTECTED);

	/**
	 * The name of hashing algorithm.
	 * @var string
	 */
	zend_declare_property_string(phalcon_crypt_ce, SL("hashAlgo"), "sha256", ZEND_ACC_PROTECTED);

	/**
	 * Whether calculating message digest enabled or not.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_crypt_ce, SL("useSigning"), 1, ZEND_ACC_PROTECTED);

	zephir_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ANSI_X_923"), 1);

	zephir_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_DEFAULT"), 0);

	zephir_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ISO_10126"), 3);

	zephir_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ISO_IEC_7816_4"), 4);

	zephir_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_PKCS7"), 2);

	zephir_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_SPACE"), 6);

	zephir_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ZERO"), 5);

	zend_class_implements(phalcon_crypt_ce, 1, phalcon_crypt_cryptinterface_ce);
	return SUCCESS;

}

/**
 */
PHP_METHOD(Phalcon_Crypt, getAuthTag) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "authTag");

}

/**
 */
PHP_METHOD(Phalcon_Crypt, getAuthData) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "authData");

}

/**
 */
PHP_METHOD(Phalcon_Crypt, getAuthTagLength) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "authTagLength");

}

/**
 * Phalcon\Crypt constructor.
 */
PHP_METHOD(Phalcon_Crypt, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool useSigning;
	zval *cipher_param = NULL, *useSigning_param = NULL, _0;
	zval cipher;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(cipher)
		Z_PARAM_BOOL(useSigning)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &cipher_param, &useSigning_param);

	if (!cipher_param) {
		ZEPHIR_INIT_VAR(&cipher);
		ZVAL_STRING(&cipher, "aes-256-cfb");
	} else {
	if (UNEXPECTED(Z_TYPE_P(cipher_param) != IS_STRING && Z_TYPE_P(cipher_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cipher' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cipher_param) == IS_STRING)) {
		zephir_get_strval(&cipher, cipher_param);
	} else {
		ZEPHIR_INIT_VAR(&cipher);
		ZVAL_EMPTY_STRING(&cipher);
	}
	}
	if (!useSigning_param) {
		useSigning = 0;
	} else {
		useSigning = zephir_get_boolval(useSigning_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initializeavailableciphers", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcipher", NULL, 0, &cipher);
	zephir_check_call_status();
	if (useSigning) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "usesigning", NULL, 0, &_0);
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
 */
PHP_METHOD(Phalcon_Crypt, decrypt) {

	zend_bool _23, _25, _29, _12$$8, _14$$8, _18$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *key_param = NULL, __$true, __$null, authData, authTag, decryptKey, ivLength, cipher, mode, blockSize, decrypted, ciphertext, hashAlgo, hashLength, iv, hash, _0, _1, _2, _3, _7, _22, _24, _26, _4$$7, _5$$7, _6$$7, _8$$8, _9$$8, _10$$8, _11$$8, _13$$8, _15$$8, _21$$8, _16$$9, _17$$10, _19$$11, _20$$11, _27$$13, _28$$14, _30$$15, _31$$15;
	zval text, key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&key);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&authData);
	ZVAL_UNDEF(&authTag);
	ZVAL_UNDEF(&decryptKey);
	ZVAL_UNDEF(&ivLength);
	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&blockSize);
	ZVAL_UNDEF(&decrypted);
	ZVAL_UNDEF(&ciphertext);
	ZVAL_UNDEF(&hashAlgo);
	ZVAL_UNDEF(&hashLength);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_31$$15);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(key)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}
	}


	if (EXPECTED(ZEPHIR_IS_EMPTY(&key))) {
		ZEPHIR_OBS_VAR(&decryptKey);
		zephir_read_property(&decryptKey, this_ptr, ZEND_STRL("key"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(&decryptKey, &key);
	}
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&decryptKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Decryption key cannot be empty", "phalcon/Crypt.zep", 133);
		return;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cipher, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "-");
	ZEPHIR_CALL_FUNCTION(&_2, "strrpos", NULL, 117, &cipher, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_0, (zephir_get_numberval(&_2) - zephir_fast_strlen_ev(&cipher)));
	ZEPHIR_INIT_NVAR(&_1);
	zephir_substr(&_1, &cipher, zephir_get_intval(&_0), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_VAR(&mode);
	zephir_fast_strtolower(&mode, &_1);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("authData"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&authData, &_3);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("authTag"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&authTag, &_3);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertcipherisavailable", NULL, 0, &cipher);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("ivLength"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ivLength, &_3);
	if (EXPECTED(ZEPHIR_GT_LONG(&ivLength, 0))) {
		ZEPHIR_CPY_WRT(&blockSize, &ivLength);
	} else {
		ZEPHIR_INIT_VAR(&_4$$7);
		ZEPHIR_CONCAT_SV(&_4$$7, "-", &mode);
		ZEPHIR_INIT_VAR(&_5$$7);
		ZVAL_STRING(&_5$$7, "");
		ZEPHIR_CALL_FUNCTION(&_6$$7, "str_ireplace", NULL, 184, &_4$$7, &_5$$7, &cipher);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&blockSize, this_ptr, "getivlength", NULL, 0, &_6$$7);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_3, 0);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "8bit");
	ZEPHIR_CALL_FUNCTION(&iv, "mb_substr", NULL, 185, &text, &_3, &ivLength, &_7);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("useSigning"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_3)) {
		ZEPHIR_CALL_METHOD(&hashAlgo, this_ptr, "gethashalgo", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$8);
		ZVAL_STRING(&_8$$8, "");
		ZEPHIR_CALL_FUNCTION(&_9$$8, "hash", NULL, 186, &hashAlgo, &_8$$8, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&hashLength);
		ZVAL_LONG(&hashLength, zephir_fast_strlen_ev(&_9$$8));
		ZEPHIR_INIT_NVAR(&_8$$8);
		ZVAL_STRING(&_8$$8, "8bit");
		ZEPHIR_CALL_FUNCTION(&hash, "mb_substr", NULL, 185, &text, &ivLength, &hashLength, &_8$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$8);
		zephir_add_function(&_10$$8, &ivLength, &hashLength);
		ZEPHIR_INIT_NVAR(&_8$$8);
		ZVAL_STRING(&_8$$8, "8bit");
		ZEPHIR_CALL_FUNCTION(&ciphertext, "mb_substr", NULL, 185, &text, &_10$$8, &__$null, &_8$$8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_11$$8);
		ZVAL_STRING(&_11$$8, "-gcm");
		_12$$8 = ZEPHIR_IS_IDENTICAL(&_11$$8, &mode);
		if (!(_12$$8)) {
			ZEPHIR_INIT_VAR(&_13$$8);
			ZVAL_STRING(&_13$$8, "-ccm");
			_12$$8 = ZEPHIR_IS_IDENTICAL(&_13$$8, &mode);
		}
		_14$$8 = _12$$8;
		if (_14$$8) {
			zephir_read_property(&_15$$8, this_ptr, ZEND_STRL("authData"), PH_NOISY_CC | PH_READONLY);
			_14$$8 = !(ZEPHIR_IS_EMPTY(&_15$$8));
		}
		if (_14$$8) {
			ZVAL_LONG(&_16$$9, 1);
			ZEPHIR_CALL_FUNCTION(&decrypted, "openssl_decrypt", NULL, 187, &ciphertext, &cipher, &decryptKey, &_16$$9, &iv, &authTag, &authData);
			zephir_check_call_status();
		} else {
			ZVAL_LONG(&_17$$10, 1);
			ZEPHIR_CALL_FUNCTION(&decrypted, "openssl_decrypt", NULL, 187, &ciphertext, &cipher, &decryptKey, &_17$$10, &iv);
			zephir_check_call_status();
		}
		_18$$8 = ZEPHIR_IS_STRING(&mode, "-cbc");
		if (!(_18$$8)) {
			_18$$8 = ZEPHIR_IS_STRING(&mode, "-ecb");
		}
		if (_18$$8) {
			zephir_read_property(&_20$$11, this_ptr, ZEND_STRL("padding"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_19$$11, this_ptr, "cryptunpadtext", NULL, 0, &decrypted, &mode, &blockSize, &_20$$11);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&decrypted, &_19$$11);
		}
		ZEPHIR_CALL_FUNCTION(&_21$$8, "hash_hmac", NULL, 188, &hashAlgo, &decrypted, &decryptKey, &__$true);
		zephir_check_call_status();
		if (UNEXPECTED(!ZEPHIR_IS_IDENTICAL(&_21$$8, &hash))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_mismatch_ce, "Hash does not match.", "phalcon/Crypt.zep", 187);
			return;
		}
		RETURN_CCTOR(&decrypted);
	}
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "8bit");
	ZEPHIR_CALL_FUNCTION(&ciphertext, "mb_substr", NULL, 185, &text, &ivLength, &__$null, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_22);
	ZVAL_STRING(&_22, "-gcm");
	_23 = ZEPHIR_IS_IDENTICAL(&_22, &mode);
	if (!(_23)) {
		ZEPHIR_INIT_VAR(&_24);
		ZVAL_STRING(&_24, "-ccm");
		_23 = ZEPHIR_IS_IDENTICAL(&_24, &mode);
	}
	_25 = _23;
	if (_25) {
		zephir_read_property(&_26, this_ptr, ZEND_STRL("authData"), PH_NOISY_CC | PH_READONLY);
		_25 = !(ZEPHIR_IS_EMPTY(&_26));
	}
	if (_25) {
		ZVAL_LONG(&_27$$13, 1);
		ZEPHIR_CALL_FUNCTION(&decrypted, "openssl_decrypt", NULL, 187, &ciphertext, &cipher, &decryptKey, &_27$$13, &iv, &authTag, &authData);
		zephir_check_call_status();
	} else {
		ZVAL_LONG(&_28$$14, 1);
		ZEPHIR_CALL_FUNCTION(&decrypted, "openssl_decrypt", NULL, 187, &ciphertext, &cipher, &decryptKey, &_28$$14, &iv);
		zephir_check_call_status();
	}
	_29 = ZEPHIR_IS_STRING(&mode, "-cbc");
	if (!(_29)) {
		_29 = ZEPHIR_IS_STRING(&mode, "-ecb");
	}
	if (_29) {
		zephir_read_property(&_31$$15, this_ptr, ZEND_STRL("padding"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_30$$15, this_ptr, "cryptunpadtext", NULL, 0, &decrypted, &mode, &blockSize, &_31$$15);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&decrypted, &_30$$15);
	}
	RETURN_CCTOR(&decrypted);

}

/**
 * Decrypt a text that is coded as a base64 string.
 *
 * @throws \Phalcon\Crypt\Mismatch
 */
PHP_METHOD(Phalcon_Crypt, decryptBase64) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool safe;
	zval *text_param = NULL, *key = NULL, key_sub, *safe_param = NULL, __$null, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(key)
		Z_PARAM_BOOL(safe)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &text_param, &key, &safe_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!key) {
		key = &key_sub;
		key = &__$null;
	}
	if (!safe_param) {
		safe = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(safe_param) != IS_TRUE && Z_TYPE_P(safe_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'safe' must be of the type bool"));
		RETURN_MM_NULL();
	}
	safe = (Z_TYPE_P(safe_param) == IS_TRUE);
	}


	if (safe) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "-_");
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "+/");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "strtr", NULL, 5, &text, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "===");
		ZVAL_DOUBLE(&_3$$3, zephir_safe_mod_long_long(((zephir_fast_strlen_ev(&text) + 3)), 4));
		ZEPHIR_INIT_NVAR(&_1$$3);
		zephir_substr(&_1$$3, &_0$$3, zephir_get_intval(&_3$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_VV(&_4$$3, &_2$$3, &_1$$3);
		zephir_get_strval(&text, &_4$$3);
	}
	ZEPHIR_CALL_FUNCTION(&_5, "base64_decode", NULL, 189, &text);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "decrypt", NULL, 0, &_5, key);
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
 */
PHP_METHOD(Phalcon_Crypt, encrypt) {

	zend_bool _7, _8, _10, _12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *key_param = NULL, __$true, authData, authTag, authTagLength, encryptKey, ivLength, iv, cipher, mode, blockSize, paddingType, padded, encrypted, _0, _1, _2, _3, _9, _11, _15, _4$$7, _5$$7, _6$$7, _13$$10, _14$$11, digest$$12, hashAlgo$$12;
	zval text, key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&key);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&authData);
	ZVAL_UNDEF(&authTag);
	ZVAL_UNDEF(&authTagLength);
	ZVAL_UNDEF(&encryptKey);
	ZVAL_UNDEF(&ivLength);
	ZVAL_UNDEF(&iv);
	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&blockSize);
	ZVAL_UNDEF(&paddingType);
	ZVAL_UNDEF(&padded);
	ZVAL_UNDEF(&encrypted);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&digest$$12);
	ZVAL_UNDEF(&hashAlgo$$12);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(key)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!key_param) {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_STRING(&key, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}
	}


	if (EXPECTED(ZEPHIR_IS_EMPTY(&key))) {
		ZEPHIR_OBS_VAR(&encryptKey);
		zephir_read_property(&encryptKey, this_ptr, ZEND_STRL("key"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(&encryptKey, &key);
	}
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&encryptKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Encryption key cannot be empty", "phalcon/Crypt.zep", 266);
		return;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("cipher"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&cipher, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "-");
	ZEPHIR_CALL_FUNCTION(&_2, "strrpos", NULL, 117, &cipher, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_0, (zephir_get_numberval(&_2) - zephir_fast_strlen_ev(&cipher)));
	ZEPHIR_INIT_NVAR(&_1);
	zephir_substr(&_1, &cipher, zephir_get_intval(&_0), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_VAR(&mode);
	zephir_fast_strtolower(&mode, &_1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertcipherisavailable", NULL, 0, &cipher);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("ivLength"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ivLength, &_3);
	if (EXPECTED(ZEPHIR_GT_LONG(&ivLength, 0))) {
		ZEPHIR_CPY_WRT(&blockSize, &ivLength);
	} else {
		ZEPHIR_INIT_VAR(&_4$$7);
		ZEPHIR_CONCAT_SV(&_4$$7, "-", &mode);
		ZEPHIR_INIT_VAR(&_5$$7);
		ZVAL_STRING(&_5$$7, "");
		ZEPHIR_CALL_FUNCTION(&_6$$7, "str_ireplace", NULL, 184, &_4$$7, &_5$$7, &cipher);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&blockSize, this_ptr, "getivlength", NULL, 0, &_6$$7);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&iv, "openssl_random_pseudo_bytes", NULL, 190, &ivLength);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&paddingType);
	zephir_read_property(&paddingType, this_ptr, ZEND_STRL("padding"), PH_NOISY_CC);
	_7 = !ZEPHIR_IS_LONG(&paddingType, 0);
	if (_7) {
		_8 = ZEPHIR_IS_STRING(&mode, "-cbc");
		if (!(_8)) {
			_8 = ZEPHIR_IS_STRING(&mode, "-ecb");
		}
		_7 = _8;
	}
	if (_7) {
		ZEPHIR_CALL_METHOD(&padded, this_ptr, "cryptpadtext", NULL, 0, &text, &mode, &blockSize, &paddingType);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&padded, &text);
	}
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "-gcm");
	_10 = ZEPHIR_IS_IDENTICAL(&_9, &mode);
	if (!(_10)) {
		ZEPHIR_INIT_VAR(&_11);
		ZVAL_STRING(&_11, "-ccm");
		_10 = ZEPHIR_IS_IDENTICAL(&_11, &mode);
	}
	_12 = _10;
	if (_12) {
		zephir_read_property(&_3, this_ptr, ZEND_STRL("authData"), PH_NOISY_CC | PH_READONLY);
		_12 = !(ZEPHIR_IS_EMPTY(&_3));
	}
	if (_12) {
		zephir_read_property(&_13$$10, this_ptr, ZEND_STRL("authData"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&authData, &_13$$10);
		zephir_read_property(&_13$$10, this_ptr, ZEND_STRL("authTag"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&authTag, &_13$$10);
		zephir_read_property(&_13$$10, this_ptr, ZEND_STRL("authTagLength"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&authTagLength, &_13$$10);
		ZVAL_LONG(&_13$$10, 1);
		ZEPHIR_MAKE_REF(&authTag);
		ZEPHIR_CALL_FUNCTION(&encrypted, "openssl_encrypt", NULL, 191, &padded, &cipher, &encryptKey, &_13$$10, &iv, &authTag, &authData, &authTagLength);
		ZEPHIR_UNREF(&authTag);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("authTag"), &authTag);
	} else {
		ZVAL_LONG(&_14$$11, 1);
		ZEPHIR_CALL_FUNCTION(&encrypted, "openssl_encrypt", NULL, 191, &padded, &cipher, &encryptKey, &_14$$11, &iv);
		zephir_check_call_status();
	}
	zephir_read_property(&_15, this_ptr, ZEND_STRL("useSigning"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_15)) {
		ZEPHIR_CALL_METHOD(&hashAlgo$$12, this_ptr, "gethashalgo", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&digest$$12, "hash_hmac", NULL, 188, &hashAlgo$$12, &padded, &encryptKey, &__$true);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVV(return_value, &iv, &digest$$12, &encrypted);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_VV(return_value, &iv, &encrypted);
	RETURN_MM();

}

/**
 * Encrypts a text returning the result as a base64 string.
 */
PHP_METHOD(Phalcon_Crypt, encryptBase64) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool safe;
	zval *text_param = NULL, *key = NULL, key_sub, *safe_param = NULL, __$null, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5;
	zval text;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(key)
		Z_PARAM_BOOL(safe)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &text_param, &key, &safe_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(&text, text_param);
	} else {
		ZEPHIR_INIT_VAR(&text);
		ZVAL_EMPTY_STRING(&text);
	}
	if (!key) {
		key = &key_sub;
		key = &__$null;
	}
	if (!safe_param) {
		safe = 0;
	} else {
	if (UNEXPECTED(Z_TYPE_P(safe_param) != IS_TRUE && Z_TYPE_P(safe_param) != IS_FALSE)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'safe' must be of the type bool"));
		RETURN_MM_NULL();
	}
	safe = (Z_TYPE_P(safe_param) == IS_TRUE);
	}


	if (safe == 1) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "encrypt", NULL, 0, &text, key);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_1$$3, "base64_encode", NULL, 192, &_0$$3);
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
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "encrypt", NULL, 0, &text, key);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 192, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a list of available ciphers.
 */
PHP_METHOD(Phalcon_Crypt, getAvailableCiphers) {

	zval availableCiphers, _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&availableCiphers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("availableCiphers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&availableCiphers, &_0);
	if (UNEXPECTED(Z_TYPE_P(&availableCiphers) != IS_ARRAY)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initializeavailableciphers", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("availableCiphers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&availableCiphers, &_1$$3);
	}
	RETURN_CCTOR(&availableCiphers);

}

/**
 * Return a list of registered hashing algorithms suitable for hash_hmac.
 */
PHP_METHOD(Phalcon_Crypt, getAvailableHashAlgos) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	if (EXPECTED((zephir_function_exists_ex(ZEND_STRL("hash_hmac_algos")) == SUCCESS))) {
		ZEPHIR_RETURN_CALL_FUNCTION("hash_hmac_algos", NULL, 193);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_FUNCTION("hash_algos", NULL, 194);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the current cipher
 */
PHP_METHOD(Phalcon_Crypt, getCipher) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "cipher");

}

/**
 * Get the name of hashing algorithm.
 */
PHP_METHOD(Phalcon_Crypt, getHashAlgo) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "hashAlgo");

}

/**
 * Returns the encryption key
 */
PHP_METHOD(Phalcon_Crypt, getKey) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "key");

}

PHP_METHOD(Phalcon_Crypt, setAuthTag) {

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

	if (UNEXPECTED(Z_TYPE_P(tag_param) != IS_STRING && Z_TYPE_P(tag_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tag' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tag_param) == IS_STRING)) {
		zephir_get_strval(&tag, tag_param);
	} else {
		ZEPHIR_INIT_VAR(&tag);
		ZVAL_EMPTY_STRING(&tag);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("authTag"), &tag);
	RETURN_THIS();

}

PHP_METHOD(Phalcon_Crypt, setAuthData) {

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

	if (UNEXPECTED(Z_TYPE_P(data_param) != IS_STRING && Z_TYPE_P(data_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(data_param) == IS_STRING)) {
		zephir_get_strval(&data, data_param);
	} else {
		ZEPHIR_INIT_VAR(&data);
		ZVAL_EMPTY_STRING(&data);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("authData"), &data);
	RETURN_THIS();

}

PHP_METHOD(Phalcon_Crypt, setAuthTagLength) {

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

	if (UNEXPECTED(Z_TYPE_P(length_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'length' must be of the type int"));
		RETURN_NULL();
	}
	length = Z_LVAL_P(length_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, length);
	zephir_update_property_zval(this_ptr, ZEND_STRL("authTagLength"), &_0);
	RETURN_THISW();

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
PHP_METHOD(Phalcon_Crypt, setCipher) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cipher_param = NULL, _0;
	zval cipher;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(cipher)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cipher_param);

	if (UNEXPECTED(Z_TYPE_P(cipher_param) != IS_STRING && Z_TYPE_P(cipher_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cipher' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cipher_param) == IS_STRING)) {
		zephir_get_strval(&cipher, cipher_param);
	} else {
		ZEPHIR_INIT_VAR(&cipher);
		ZVAL_EMPTY_STRING(&cipher);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertcipherisavailable", NULL, 0, &cipher);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getivlength", NULL, 0, &cipher);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("ivLength"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("cipher"), &cipher);
	RETURN_THIS();

}

/**
 * Set the name of hashing algorithm.
 *
 * @throws \Phalcon\Crypt\Exception
 */
PHP_METHOD(Phalcon_Crypt, setHashAlgo) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *hashAlgo_param = NULL;
	zval hashAlgo;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hashAlgo);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(hashAlgo)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &hashAlgo_param);

	if (UNEXPECTED(Z_TYPE_P(hashAlgo_param) != IS_STRING && Z_TYPE_P(hashAlgo_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'hashAlgo' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(hashAlgo_param) == IS_STRING)) {
		zephir_get_strval(&hashAlgo, hashAlgo_param);
	} else {
		ZEPHIR_INIT_VAR(&hashAlgo);
		ZVAL_EMPTY_STRING(&hashAlgo);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "asserthashalgorithmavailable", NULL, 0, &hashAlgo);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("hashAlgo"), &hashAlgo);
	RETURN_THIS();

}

/**
 * Sets the encryption key.
 *
 * The `$key' should have been previously generated in a cryptographically
 * safe way.
 *
 * Bad key:
 * "le password"
 *
 * Better (but still unsafe):
 * "#1dj8$=dp?.ak//j1V$~%*0X"
 *
 * Good key:
 * "T4\xb1\x8d\xa9\x98\x05\\\x8c\xbe\x1d\x07&[\x99\x18\xa4~Lc1\xbeW\xb3"
 */
PHP_METHOD(Phalcon_Crypt, setKey) {

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

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("key"), &key);
	RETURN_THIS();

}

/**
 * Changes the padding scheme used.
 */
PHP_METHOD(Phalcon_Crypt, setPadding) {

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

	if (UNEXPECTED(Z_TYPE_P(scheme_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'scheme' must be of the type int"));
		RETURN_NULL();
	}
	scheme = Z_LVAL_P(scheme_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, scheme);
	zephir_update_property_zval(this_ptr, ZEND_STRL("padding"), &_0);
	RETURN_THISW();

}

/**
 * Sets if the calculating message digest must used.
 */
PHP_METHOD(Phalcon_Crypt, useSigning) {

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
 * Assert the cipher is available.
 */
PHP_METHOD(Phalcon_Crypt, assertCipherIsAvailable) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cipher_param = NULL, availableCiphers, _0, _1$$3, _2$$3, _3$$3;
	zval cipher;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&availableCiphers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(cipher)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cipher_param);

	if (UNEXPECTED(Z_TYPE_P(cipher_param) != IS_STRING && Z_TYPE_P(cipher_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cipher' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cipher_param) == IS_STRING)) {
		zephir_get_strval(&cipher, cipher_param);
	} else {
		ZEPHIR_INIT_VAR(&cipher);
		ZVAL_EMPTY_STRING(&cipher);
	}


	ZEPHIR_CALL_METHOD(&availableCiphers, this_ptr, "getavailableciphers", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtoupper(&_0, &cipher);
	if (UNEXPECTED(!(zephir_fast_in_array(&_0, &availableCiphers)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_crypt_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "The cipher algorithm \"%s\" is not supported on this system.");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 195, &_2$$3, &cipher);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 8, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Crypt.zep", 534);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Assert the hash algorithm is available.
 */
PHP_METHOD(Phalcon_Crypt, assertHashAlgorithmAvailable) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *hashAlgo_param = NULL, availableAlgorithms, _0$$3, _1$$3, _2$$3;
	zval hashAlgo;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hashAlgo);
	ZVAL_UNDEF(&availableAlgorithms);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(hashAlgo)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &hashAlgo_param);

	if (UNEXPECTED(Z_TYPE_P(hashAlgo_param) != IS_STRING && Z_TYPE_P(hashAlgo_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'hashAlgo' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(hashAlgo_param) == IS_STRING)) {
		zephir_get_strval(&hashAlgo, hashAlgo_param);
	} else {
		ZEPHIR_INIT_VAR(&hashAlgo);
		ZVAL_EMPTY_STRING(&hashAlgo);
	}


	ZEPHIR_CALL_METHOD(&availableAlgorithms, this_ptr, "getavailablehashalgos", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!(zephir_fast_in_array(&hashAlgo, &availableAlgorithms)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_crypt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "The hash algorithm \"%s\" is not supported on this system.");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "sprintf", NULL, 195, &_1$$3, &hashAlgo);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 8, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Crypt.zep", 553);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Initialize available cipher algorithms.
 */
PHP_METHOD(Phalcon_Crypt, getIvLength) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cipher_param = NULL;
	zval cipher;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cipher);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(cipher)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cipher_param);

	if (UNEXPECTED(Z_TYPE_P(cipher_param) != IS_STRING && Z_TYPE_P(cipher_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cipher' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cipher_param) == IS_STRING)) {
		zephir_get_strval(&cipher, cipher_param);
	} else {
		ZEPHIR_INIT_VAR(&cipher);
		ZVAL_EMPTY_STRING(&cipher);
	}


	if (UNEXPECTED(!((zephir_function_exists_ex(ZEND_STRL("openssl_cipher_iv_length")) == SUCCESS)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "openssl extension is required", "phalcon/Crypt.zep", 563);
		return;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_cipher_iv_length", NULL, 196, &cipher);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Initialize available cipher algorithms.
 */
PHP_METHOD(Phalcon_Crypt, initializeAvailableCiphers) {

	zend_bool _3$$4, _5$$4, _7$$4, _9$$4, _13$$6, _15$$6, _17$$6, _19$$6;
	zval allowedCiphers;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, availableCiphers, cipher, *_0, _1, _2$$4, _4$$4, _6$$4, _8$$4, _10$$4, _11$$5, _12$$6, _14$$6, _16$$6, _18$$6, _20$$6, _21$$7;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&availableCiphers);
	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&allowedCiphers);


	ZEPHIR_MM_GROW();

	if (UNEXPECTED(!((zephir_function_exists_ex(ZEND_STRL("openssl_get_cipher_methods")) == SUCCESS)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "openssl extension is required", "phalcon/Crypt.zep", 578);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&availableCiphers, "openssl_get_cipher_methods", NULL, 197, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&allowedCiphers);
	array_init(&allowedCiphers);
	zephir_is_iterable(&availableCiphers, 0, "phalcon/Crypt.zep", 594);
	if (Z_TYPE_P(&availableCiphers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&availableCiphers), _0)
		{
			ZEPHIR_INIT_NVAR(&cipher);
			ZVAL_COPY(&cipher, _0);
			ZEPHIR_INIT_NVAR(&_2$$4);
			zephir_fast_strtolower(&_2$$4, &cipher);
			_3$$4 = zephir_start_with_str(&_2$$4, SL("des"));
			if (!(_3$$4)) {
				ZEPHIR_INIT_NVAR(&_4$$4);
				zephir_fast_strtolower(&_4$$4, &cipher);
				_3$$4 = zephir_start_with_str(&_4$$4, SL("rc2"));
			}
			_5$$4 = _3$$4;
			if (!(_5$$4)) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				zephir_fast_strtolower(&_6$$4, &cipher);
				_5$$4 = zephir_start_with_str(&_6$$4, SL("rc4"));
			}
			_7$$4 = _5$$4;
			if (!(_7$$4)) {
				ZEPHIR_INIT_NVAR(&_8$$4);
				zephir_fast_strtolower(&_8$$4, &cipher);
				_7$$4 = zephir_start_with_str(&_8$$4, SL("des"));
			}
			_9$$4 = _7$$4;
			if (!(_9$$4)) {
				ZEPHIR_INIT_NVAR(&_10$$4);
				zephir_fast_strtolower(&_10$$4, &cipher);
				_9$$4 = zephir_end_with_str(&_10$$4, SL("ecb"));
			}
			if (!(_9$$4)) {
				ZEPHIR_INIT_NVAR(&_11$$5);
				zephir_fast_strtoupper(&_11$$5, &cipher);
				zephir_array_append(&allowedCiphers, &_11$$5, PH_SEPARATE, "phalcon/Crypt.zep", 590);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &availableCiphers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &availableCiphers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&cipher, &availableCiphers, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_12$$6);
				zephir_fast_strtolower(&_12$$6, &cipher);
				_13$$6 = zephir_start_with_str(&_12$$6, SL("des"));
				if (!(_13$$6)) {
					ZEPHIR_INIT_NVAR(&_14$$6);
					zephir_fast_strtolower(&_14$$6, &cipher);
					_13$$6 = zephir_start_with_str(&_14$$6, SL("rc2"));
				}
				_15$$6 = _13$$6;
				if (!(_15$$6)) {
					ZEPHIR_INIT_NVAR(&_16$$6);
					zephir_fast_strtolower(&_16$$6, &cipher);
					_15$$6 = zephir_start_with_str(&_16$$6, SL("rc4"));
				}
				_17$$6 = _15$$6;
				if (!(_17$$6)) {
					ZEPHIR_INIT_NVAR(&_18$$6);
					zephir_fast_strtolower(&_18$$6, &cipher);
					_17$$6 = zephir_start_with_str(&_18$$6, SL("des"));
				}
				_19$$6 = _17$$6;
				if (!(_19$$6)) {
					ZEPHIR_INIT_NVAR(&_20$$6);
					zephir_fast_strtolower(&_20$$6, &cipher);
					_19$$6 = zephir_end_with_str(&_20$$6, SL("ecb"));
				}
				if (!(_19$$6)) {
					ZEPHIR_INIT_NVAR(&_21$$7);
					zephir_fast_strtoupper(&_21$$7, &cipher);
					zephir_array_append(&allowedCiphers, &_21$$7, PH_SEPARATE, "phalcon/Crypt.zep", 590);
				}
			ZEPHIR_CALL_METHOD(NULL, &availableCiphers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&cipher);
	zephir_update_property_zval(this_ptr, ZEND_STRL("availableCiphers"), &allowedCiphers);
	ZEPHIR_MM_RESTORE();

}

/**
 * Pads texts before encryption. See [cryptopad](http://www.di-mgt.com.au/cryptopad.html)
 */
PHP_METHOD(Phalcon_Crypt, cryptPadText) {

	zend_bool _0, _7$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long blockSize, paddingType, ZEPHIR_LAST_CALL_STATUS, i = 0, paddingSize, _8$$7, _9$$7;
	zval *text_param = NULL, *mode_param = NULL, *blockSize_param = NULL, *paddingType_param = NULL, padding, _23, _24, _25, _1$$5, _2$$5, _3$$5, _4$$5, _5$$6, _6$$6, _13$$7, _14$$7, _10$$8, _12$$8, _15$$9, _16$$9, _17$$9, _18$$9, _19$$10, _20$$10, _21$$11, _22$$11;
	zval text, mode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&padding);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$11);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(text)
		Z_PARAM_STR(mode)
		Z_PARAM_LONG(blockSize)
		Z_PARAM_LONG(paddingType)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &text_param, &mode_param, &blockSize_param, &paddingType_param);

	zephir_get_strval(&text, text_param);
	if (UNEXPECTED(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(&mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_EMPTY_STRING(&mode);
	}
	if (UNEXPECTED(Z_TYPE_P(blockSize_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'blockSize' must be of the type int"));
		RETURN_MM_NULL();
	}
	blockSize = Z_LVAL_P(blockSize_param);
	if (UNEXPECTED(Z_TYPE_P(paddingType_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'paddingType' must be of the type int"));
		RETURN_MM_NULL();
	}
	paddingType = Z_LVAL_P(paddingType_param);


	paddingSize = 0;
	ZEPHIR_INIT_VAR(&padding);
	ZVAL_NULL(&padding);
	_0 = ZEPHIR_IS_STRING(&mode, "cbc");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING(&mode, "ecb");
	}
	if (_0) {
		paddingSize = (blockSize - (zephir_safe_mod_long_long(zephir_fast_strlen_ev(&text), blockSize)));
		if (UNEXPECTED(paddingSize >= 256)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Block size is bigger than 256", "phalcon/Crypt.zep", 609);
			return;
		}
		do {
			if (paddingType == 1) {
				ZVAL_LONG(&_1$$5, 0);
				ZEPHIR_CALL_FUNCTION(&_2$$5, "chr", NULL, 198, &_1$$5);
				zephir_check_call_status();
				ZVAL_LONG(&_1$$5, (paddingSize - 1));
				ZEPHIR_CALL_FUNCTION(&_3$$5, "str_repeat", NULL, 1, &_2$$5, &_1$$5);
				zephir_check_call_status();
				ZVAL_LONG(&_1$$5, paddingSize);
				ZEPHIR_CALL_FUNCTION(&_4$$5, "chr", NULL, 198, &_1$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&padding);
				ZEPHIR_CONCAT_VV(&padding, &_3$$5, &_4$$5);
				break;
			}
			if (paddingType == 2) {
				ZVAL_LONG(&_5$$6, paddingSize);
				ZEPHIR_CALL_FUNCTION(&_6$$6, "chr", NULL, 198, &_5$$6);
				zephir_check_call_status();
				ZVAL_LONG(&_5$$6, paddingSize);
				ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", NULL, 1, &_6$$6, &_5$$6);
				zephir_check_call_status();
				break;
			}
			if (paddingType == 3) {
				ZEPHIR_INIT_NVAR(&padding);
				ZVAL_STRING(&padding, "");
				_9$$7 = (paddingSize - 2);
				_8$$7 = 0;
				_7$$7 = 0;
				if (_8$$7 <= _9$$7) {
					while (1) {
						if (_7$$7) {
							_8$$7++;
							if (!(_8$$7 <= _9$$7)) {
								break;
							}
						} else {
							_7$$7 = 1;
						}
						i = _8$$7;
						ZEPHIR_CALL_FUNCTION(&_10$$8, "rand", &_11, 199);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_12$$8, "chr", NULL, 198, &_10$$8);
						zephir_check_call_status();
						zephir_concat_self(&padding, &_12$$8);
					}
				}
				ZVAL_LONG(&_13$$7, paddingSize);
				ZEPHIR_CALL_FUNCTION(&_14$$7, "chr", NULL, 198, &_13$$7);
				zephir_check_call_status();
				zephir_concat_self(&padding, &_14$$7);
				break;
			}
			if (paddingType == 4) {
				ZVAL_LONG(&_15$$9, 0x80);
				ZEPHIR_CALL_FUNCTION(&_16$$9, "chr", NULL, 198, &_15$$9);
				zephir_check_call_status();
				ZVAL_LONG(&_15$$9, 0);
				ZEPHIR_CALL_FUNCTION(&_17$$9, "chr", NULL, 198, &_15$$9);
				zephir_check_call_status();
				ZVAL_LONG(&_15$$9, (paddingSize - 1));
				ZEPHIR_CALL_FUNCTION(&_18$$9, "str_repeat", NULL, 1, &_17$$9, &_15$$9);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&padding);
				ZEPHIR_CONCAT_VV(&padding, &_16$$9, &_18$$9);
				break;
			}
			if (paddingType == 5) {
				ZVAL_LONG(&_19$$10, 0);
				ZEPHIR_CALL_FUNCTION(&_20$$10, "chr", NULL, 198, &_19$$10);
				zephir_check_call_status();
				ZVAL_LONG(&_19$$10, paddingSize);
				ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", NULL, 1, &_20$$10, &_19$$10);
				zephir_check_call_status();
				break;
			}
			if (paddingType == 6) {
				ZEPHIR_INIT_VAR(&_21$$11);
				ZVAL_STRING(&_21$$11, " ");
				ZVAL_LONG(&_22$$11, paddingSize);
				ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", NULL, 1, &_21$$11, &_22$$11);
				zephir_check_call_status();
				break;
			}
			paddingSize = 0;
			break;
		} while(0);

	}
	if (!(paddingSize)) {
		RETURN_CTOR(&text);
	}
	if (UNEXPECTED(paddingSize > blockSize)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Invalid padding size", "phalcon/Crypt.zep", 656);
		return;
	}
	ZVAL_LONG(&_23, 0);
	ZVAL_LONG(&_24, paddingSize);
	ZEPHIR_INIT_VAR(&_25);
	zephir_substr(&_25, &padding, 0 , zephir_get_intval(&_24), 0);
	ZEPHIR_CONCAT_VV(return_value, &text, &_25);
	RETURN_MM();

}

/**
 * Removes a padding from a text.
 *
 * If the function detects that the text was not padded, it will return it
 * unmodified.
 */
PHP_METHOD(Phalcon_Crypt, cryptUnpadText) {

	unsigned char _20$$11, _22$$11, _24$$15, _27$$17;
	zend_bool _0, _1, _2, _19$$11, _21$$11, _23$$15, _25$$15, _26$$17, _28$$17, _29$$3;
	long length = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long blockSize, paddingType, ZEPHIR_LAST_CALL_STATUS, i = 0, paddingSize, ord = 0;
	zval *text_param = NULL, *mode_param = NULL, *blockSize_param = NULL, *paddingType_param = NULL, padding, last, _3$$4, _4$$4, _5$$4, _6$$5, _7$$5, _8$$5, _9$$5, _10$$7, _11$$7, _12$$7, _13$$8, _14$$8, _15$$8, _16$$10, _17$$10, _18$$10, _30$$21, _31$$21;
	zval text, mode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&padding);
	ZVAL_UNDEF(&last);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_30$$21);
	ZVAL_UNDEF(&_31$$21);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_STR(text)
		Z_PARAM_STR(mode)
		Z_PARAM_LONG(blockSize)
		Z_PARAM_LONG(paddingType)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &text_param, &mode_param, &blockSize_param, &paddingType_param);

	zephir_get_strval(&text, text_param);
	if (UNEXPECTED(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(&mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_EMPTY_STRING(&mode);
	}
	if (UNEXPECTED(Z_TYPE_P(blockSize_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'blockSize' must be of the type int"));
		RETURN_MM_NULL();
	}
	blockSize = Z_LVAL_P(blockSize_param);
	if (UNEXPECTED(Z_TYPE_P(paddingType_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'paddingType' must be of the type int"));
		RETURN_MM_NULL();
	}
	paddingType = Z_LVAL_P(paddingType_param);


	paddingSize = 0;
	length = zephir_fast_strlen_ev(&text);
	_0 = length > 0;
	if (_0) {
		_0 = (zephir_safe_mod_long_long(length, blockSize) == 0);
	}
	_1 = _0;
	if (_1) {
		_2 = ZEPHIR_IS_STRING(&mode, "cbc");
		if (!(_2)) {
			_2 = ZEPHIR_IS_STRING(&mode, "ecb");
		}
		_1 = _2;
	}
	if (_1) {
		do {
			if (paddingType == 1) {
				ZVAL_LONG(&_3$$4, (length - 1));
				ZVAL_LONG(&_4$$4, 1);
				ZEPHIR_INIT_VAR(&last);
				zephir_substr(&last, &text, zephir_get_intval(&_3$$4), 1 , 0);
				ZEPHIR_CALL_FUNCTION(&_5$$4, "ord", NULL, 200, &last);
				zephir_check_call_status();
				ord = zephir_get_intval(&_5$$4);
				if (ord <= blockSize) {
					paddingSize = ord;
					ZVAL_LONG(&_6$$5, 0);
					ZEPHIR_CALL_FUNCTION(&_7$$5, "chr", NULL, 198, &_6$$5);
					zephir_check_call_status();
					ZVAL_LONG(&_6$$5, (paddingSize - 1));
					ZEPHIR_CALL_FUNCTION(&_8$$5, "str_repeat", NULL, 1, &_7$$5, &_6$$5);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(&padding);
					ZEPHIR_CONCAT_VV(&padding, &_8$$5, &last);
					ZVAL_LONG(&_6$$5, (length - paddingSize));
					ZEPHIR_INIT_VAR(&_9$$5);
					zephir_substr(&_9$$5, &text, zephir_get_intval(&_6$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					if (!ZEPHIR_IS_EQUAL(&_9$$5, &padding)) {
						paddingSize = 0;
					}
				}
				break;
			}
			if (paddingType == 2) {
				ZVAL_LONG(&_10$$7, (length - 1));
				ZVAL_LONG(&_11$$7, 1);
				ZEPHIR_INIT_NVAR(&last);
				zephir_substr(&last, &text, zephir_get_intval(&_10$$7), 1 , 0);
				ZEPHIR_CALL_FUNCTION(&_12$$7, "ord", NULL, 200, &last);
				zephir_check_call_status();
				ord = zephir_get_intval(&_12$$7);
				if (ord <= blockSize) {
					paddingSize = ord;
					ZVAL_LONG(&_13$$8, paddingSize);
					ZEPHIR_CALL_FUNCTION(&_14$$8, "chr", NULL, 198, &_13$$8);
					zephir_check_call_status();
					ZVAL_LONG(&_13$$8, paddingSize);
					ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", NULL, 1, &_14$$8, &_13$$8);
					zephir_check_call_status();
					ZVAL_LONG(&_13$$8, (length - paddingSize));
					ZEPHIR_INIT_VAR(&_15$$8);
					zephir_substr(&_15$$8, &text, zephir_get_intval(&_13$$8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					if (!ZEPHIR_IS_EQUAL(&_15$$8, &padding)) {
						paddingSize = 0;
					}
				}
				break;
			}
			if (paddingType == 3) {
				ZVAL_LONG(&_16$$10, (length - 1));
				ZVAL_LONG(&_17$$10, 1);
				ZEPHIR_INIT_NVAR(&last);
				zephir_substr(&last, &text, zephir_get_intval(&_16$$10), 1 , 0);
				ZEPHIR_CALL_FUNCTION(&_18$$10, "ord", NULL, 200, &last);
				zephir_check_call_status();
				paddingSize = zephir_get_intval(&_18$$10);
				break;
			}
			if (paddingType == 4) {
				i = (length - 1);
				while (1) {
					_19$$11 = i > 0;
					if (_19$$11) {
						_20$$11 = ZEPHIR_STRING_OFFSET(&text, i);
						_19$$11 = _20$$11 == 0x00;
					}
					_21$$11 = _19$$11;
					if (_21$$11) {
						_21$$11 = paddingSize < blockSize;
					}
					if (!(_21$$11)) {
						break;
					}
					paddingSize++;
					i--;
				}
				_22$$11 = ZEPHIR_STRING_OFFSET(&text, i);
				if (_22$$11 == 0x80) {
					paddingSize++;
				} else {
					paddingSize = 0;
				}
				break;
			}
			if (paddingType == 5) {
				i = (length - 1);
				while (1) {
					_23$$15 = i >= 0;
					if (_23$$15) {
						_24$$15 = ZEPHIR_STRING_OFFSET(&text, i);
						_23$$15 = _24$$15 == 0x00;
					}
					_25$$15 = _23$$15;
					if (_25$$15) {
						_25$$15 = paddingSize <= blockSize;
					}
					if (!(_25$$15)) {
						break;
					}
					paddingSize++;
					i--;
				}
				break;
			}
			if (paddingType == 6) {
				i = (length - 1);
				while (1) {
					_26$$17 = i >= 0;
					if (_26$$17) {
						_27$$17 = ZEPHIR_STRING_OFFSET(&text, i);
						_26$$17 = _27$$17 == 0x20;
					}
					_28$$17 = _26$$17;
					if (_28$$17) {
						_28$$17 = paddingSize <= blockSize;
					}
					if (!(_28$$17)) {
						break;
					}
					paddingSize++;
					i--;
				}
				break;
			}
			break;
		} while(0);

		_29$$3 = ((paddingSize) ? 1 : 0);
		if (_29$$3) {
			_29$$3 = paddingSize <= blockSize;
		}
		if (_29$$3) {
			if (paddingSize < length) {
				ZVAL_LONG(&_30$$21, 0);
				ZVAL_LONG(&_31$$21, (length - paddingSize));
				zephir_substr(return_value, &text, 0 , zephir_get_intval(&_31$$21), 0);
				RETURN_MM();
			}
			RETURN_MM_STRING("");
		} else {
			paddingSize = 0;
		}
	}
	if (!(paddingSize)) {
		RETURN_CTOR(&text);
	}
	ZEPHIR_MM_RESTORE();

}

