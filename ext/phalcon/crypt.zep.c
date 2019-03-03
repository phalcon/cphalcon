
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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
ZEPHIR_INIT_CLASS(Phalcon_Crypt) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Crypt, phalcon, crypt, phalcon_crypt_method_entry, 0);

	zend_declare_property_null(phalcon_crypt_ce, SL("_key"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_crypt_ce, SL("_padding"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_crypt_ce, SL("_cipher"), "aes-256-cfb", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Available cipher methods.
	 * @var array
	 */
	zend_declare_property_null(phalcon_crypt_ce, SL("availableCiphers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The cipher iv length.
	 * @var int
	 */
	zend_declare_property_long(phalcon_crypt_ce, SL("ivLength"), 16, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The name of hashing algorithm.
	 * @var string
	 */
	zend_declare_property_string(phalcon_crypt_ce, SL("hashAlgo"), "sha256", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Whether calculating message digest enabled or not.
	 * NOTE: This feature will be enabled by default in Phalcon 4.0.0
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_crypt_ce, SL("useSigning"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_DEFAULT"), 0);

	zephir_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ANSI_X_923"), 1);

	zephir_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_PKCS7"), 2);

	zephir_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ISO_10126"), 3);

	zephir_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ISO_IEC_7816_4"), 4);

	zephir_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ZERO"), 5);

	zephir_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_SPACE"), 6);

	zend_class_implements(phalcon_crypt_ce TSRMLS_CC, 1, phalcon_cryptinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Crypt constructor.
 */
PHP_METHOD(Phalcon_Crypt, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool useSigning;
	zval *cipher_param = NULL, *useSigning_param = NULL, _0;
	zval cipher;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &cipher_param, &useSigning_param);

	if (!cipher_param) {
		ZEPHIR_INIT_VAR(&cipher);
		ZVAL_STRING(&cipher, "aes-256-cfb");
	} else {
	if (UNEXPECTED(Z_TYPE_P(cipher_param) != IS_STRING && Z_TYPE_P(cipher_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cipher' must be of the type string") TSRMLS_CC);
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
 * Changes the padding scheme used.
 */
PHP_METHOD(Phalcon_Crypt, setPadding) {

	zval *scheme_param = NULL, _0;
	zend_long scheme;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &scheme_param);

	if (UNEXPECTED(Z_TYPE_P(scheme_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'scheme' must be of the type int") TSRMLS_CC);
		RETURN_NULL();
	}
	scheme = Z_LVAL_P(scheme_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, scheme);
	zephir_update_property_zval(this_ptr, SL("_padding"), &_0);
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cipher_param = NULL, _0;
	zval cipher;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cipher_param);

	if (UNEXPECTED(Z_TYPE_P(cipher_param) != IS_STRING && Z_TYPE_P(cipher_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cipher' must be of the type string") TSRMLS_CC);
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
	zephir_update_property_zval(this_ptr, SL("ivLength"), &_0);
	zephir_update_property_zval(this_ptr, SL("_cipher"), &cipher);
	RETURN_THIS();

}

/**
 * Returns the current cipher
 */
PHP_METHOD(Phalcon_Crypt, getCipher) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_cipher");

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
PHP_METHOD(Phalcon_Crypt, setKey) {

	zval *key_param = NULL;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_update_property_zval(this_ptr, SL("_key"), &key);
	RETURN_THIS();

}

/**
 * Returns the encryption key
 */
PHP_METHOD(Phalcon_Crypt, getKey) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_key");

}

/**
 * Set the name of hashing algorithm.
 *
 * @throws \Phalcon\Crypt\Exception
 */
PHP_METHOD(Phalcon_Crypt, setHashAlgo) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *hashAlgo_param = NULL;
	zval hashAlgo;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hashAlgo);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &hashAlgo_param);

	if (UNEXPECTED(Z_TYPE_P(hashAlgo_param) != IS_STRING && Z_TYPE_P(hashAlgo_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'hashAlgo' must be of the type string") TSRMLS_CC);
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
	zephir_update_property_zval(this_ptr, SL("hashAlgo"), &hashAlgo);
	RETURN_THIS();

}

/**
 * Get the name of hashing algorithm.
 */
PHP_METHOD(Phalcon_Crypt, getHashAlgo) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "hashAlgo");

}

/**
 * Sets if the calculating message digest must used.
 *
 * NOTE: This feature will be enabled by default in Phalcon 4.0.0
 */
PHP_METHOD(Phalcon_Crypt, useSigning) {

	zval *useSigning_param = NULL, __$true, __$false;
	zend_bool useSigning;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &useSigning_param);

	useSigning = zephir_get_boolval(useSigning_param);


	if (useSigning) {
		zephir_update_property_zval(this_ptr, SL("useSigning"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("useSigning"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Pads texts before encryption.
 *
 * @link http://www.di-mgt.com.au/cryptopad.html
 */
PHP_METHOD(Phalcon_Crypt, _cryptPadText) {

	zend_bool _0, _7$$7;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &text_param, &mode_param, &blockSize_param, &paddingType_param);

	zephir_get_strval(&text, text_param);
	if (UNEXPECTED(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(&mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_EMPTY_STRING(&mode);
	}
	if (UNEXPECTED(Z_TYPE_P(blockSize_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'blockSize' must be of the type int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	blockSize = Z_LVAL_P(blockSize_param);
	if (UNEXPECTED(Z_TYPE_P(paddingType_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'paddingType' must be of the type int") TSRMLS_CC);
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
		paddingSize = (blockSize - (zephir_safe_mod_long_long(zephir_fast_strlen_ev(&text), blockSize TSRMLS_CC)));
		if (paddingSize >= 256) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Block size is bigger than 256", "phalcon/crypt.zep", 209);
			return;
		}
		do {
			if (paddingType == 1) {
				ZVAL_LONG(&_1$$5, 0);
				ZEPHIR_CALL_FUNCTION(&_2$$5, "chr", NULL, 126, &_1$$5);
				zephir_check_call_status();
				ZVAL_LONG(&_1$$5, (paddingSize - 1));
				ZEPHIR_CALL_FUNCTION(&_3$$5, "str_repeat", NULL, 127, &_2$$5, &_1$$5);
				zephir_check_call_status();
				ZVAL_LONG(&_1$$5, paddingSize);
				ZEPHIR_CALL_FUNCTION(&_4$$5, "chr", NULL, 126, &_1$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&padding);
				ZEPHIR_CONCAT_VV(&padding, &_3$$5, &_4$$5);
				break;
			}
			if (paddingType == 2) {
				ZVAL_LONG(&_5$$6, paddingSize);
				ZEPHIR_CALL_FUNCTION(&_6$$6, "chr", NULL, 126, &_5$$6);
				zephir_check_call_status();
				ZVAL_LONG(&_5$$6, paddingSize);
				ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", NULL, 127, &_6$$6, &_5$$6);
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
						ZEPHIR_CALL_FUNCTION(&_10$$8, "rand", &_11, 105);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_12$$8, "chr", NULL, 126, &_10$$8);
						zephir_check_call_status();
						zephir_concat_self(&padding, &_12$$8 TSRMLS_CC);
					}
				}
				ZVAL_LONG(&_13$$7, paddingSize);
				ZEPHIR_CALL_FUNCTION(&_14$$7, "chr", NULL, 126, &_13$$7);
				zephir_check_call_status();
				zephir_concat_self(&padding, &_14$$7 TSRMLS_CC);
				break;
			}
			if (paddingType == 4) {
				ZVAL_LONG(&_15$$9, 0x80);
				ZEPHIR_CALL_FUNCTION(&_16$$9, "chr", NULL, 126, &_15$$9);
				zephir_check_call_status();
				ZVAL_LONG(&_15$$9, 0);
				ZEPHIR_CALL_FUNCTION(&_17$$9, "chr", NULL, 126, &_15$$9);
				zephir_check_call_status();
				ZVAL_LONG(&_15$$9, (paddingSize - 1));
				ZEPHIR_CALL_FUNCTION(&_18$$9, "str_repeat", NULL, 127, &_17$$9, &_15$$9);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&padding);
				ZEPHIR_CONCAT_VV(&padding, &_16$$9, &_18$$9);
				break;
			}
			if (paddingType == 5) {
				ZVAL_LONG(&_19$$10, 0);
				ZEPHIR_CALL_FUNCTION(&_20$$10, "chr", NULL, 126, &_19$$10);
				zephir_check_call_status();
				ZVAL_LONG(&_19$$10, paddingSize);
				ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", NULL, 127, &_20$$10, &_19$$10);
				zephir_check_call_status();
				break;
			}
			if (paddingType == 6) {
				ZEPHIR_INIT_VAR(&_21$$11);
				ZVAL_STRING(&_21$$11, " ");
				ZVAL_LONG(&_22$$11, paddingSize);
				ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", NULL, 127, &_21$$11, &_22$$11);
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
	if (paddingSize > blockSize) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Invalid padding size", "phalcon/crypt.zep", 253);
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
 * If the function detects that the text was not padded, it will return it unmodified.
 *
 * @param string text Message to be unpadded
 * @param string mode Encryption mode; unpadding is applied only in CBC or ECB mode
 * @param int blockSize Cipher block size
 * @param int paddingType Padding scheme
 */
PHP_METHOD(Phalcon_Crypt, _cryptUnpadText) {

	unsigned char _20$$11, _22$$11, _24$$15, _27$$17;
	zend_bool _0, _1, _2, _19$$11, _21$$11, _23$$15, _25$$15, _26$$17, _28$$17, _29$$3;
	long length = 0;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &text_param, &mode_param, &blockSize_param, &paddingType_param);

	zephir_get_strval(&text, text_param);
	if (UNEXPECTED(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(&mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(&mode);
		ZVAL_EMPTY_STRING(&mode);
	}
	if (UNEXPECTED(Z_TYPE_P(blockSize_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'blockSize' must be of the type int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	blockSize = Z_LVAL_P(blockSize_param);
	if (UNEXPECTED(Z_TYPE_P(paddingType_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'paddingType' must be of the type int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	paddingType = Z_LVAL_P(paddingType_param);


	paddingSize = 0;
	length = zephir_fast_strlen_ev(&text);
	_0 = length > 0;
	if (_0) {
		_0 = (zephir_safe_mod_long_long(length, blockSize TSRMLS_CC) == 0);
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
				ZEPHIR_CALL_FUNCTION(&_5$$4, "ord", NULL, 128, &last);
				zephir_check_call_status();
				ord = zephir_get_intval(&_5$$4);
				if (ord <= blockSize) {
					paddingSize = ord;
					ZVAL_LONG(&_6$$5, 0);
					ZEPHIR_CALL_FUNCTION(&_7$$5, "chr", NULL, 126, &_6$$5);
					zephir_check_call_status();
					ZVAL_LONG(&_6$$5, (paddingSize - 1));
					ZEPHIR_CALL_FUNCTION(&_8$$5, "str_repeat", NULL, 127, &_7$$5, &_6$$5);
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
				ZEPHIR_CALL_FUNCTION(&_12$$7, "ord", NULL, 128, &last);
				zephir_check_call_status();
				ord = zephir_get_intval(&_12$$7);
				if (ord <= blockSize) {
					paddingSize = ord;
					ZVAL_LONG(&_13$$8, paddingSize);
					ZEPHIR_CALL_FUNCTION(&_14$$8, "chr", NULL, 126, &_13$$8);
					zephir_check_call_status();
					ZVAL_LONG(&_13$$8, paddingSize);
					ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", NULL, 127, &_14$$8, &_13$$8);
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
				ZEPHIR_CALL_FUNCTION(&_18$$10, "ord", NULL, 128, &last);
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
PHP_METHOD(Phalcon_Crypt, encrypt) {

	zend_bool _7, _8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *key_param = NULL, __$true, encryptKey, ivLength, iv, cipher, mode, blockSize, paddingType, padded, encrypted, _0, _1, _2, _3, _4$$7, _5$$7, _6$$7, digest$$10, hashAlgo$$10;
	zval text, key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&key);
	ZVAL_BOOL(&__$true, 1);
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
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&digest$$10);
	ZVAL_UNDEF(&hashAlgo$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
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
		zephir_read_property(&encryptKey, this_ptr, SL("_key"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(&encryptKey, &key);
	}
	if (ZEPHIR_IS_EMPTY(&encryptKey)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Encryption key cannot be empty", "phalcon/crypt.zep", 378);
		return;
	}
	ZEPHIR_OBS_VAR(&cipher);
	zephir_read_property(&cipher, this_ptr, SL("_cipher"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "-");
	ZEPHIR_CALL_FUNCTION(&_1, "strrpos", NULL, 129, &cipher, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_2, (zephir_get_numberval(&_1) - zephir_fast_strlen_ev(&cipher)));
	ZEPHIR_INIT_NVAR(&_0);
	zephir_substr(&_0, &cipher, zephir_get_intval(&_2), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_VAR(&mode);
	zephir_fast_strtolower(&mode, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertcipherisavailable", NULL, 0, &cipher);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("ivLength"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ivLength, &_3);
	if (EXPECTED(ZEPHIR_GT_LONG(&ivLength, 0))) {
		ZEPHIR_CPY_WRT(&blockSize, &ivLength);
	} else {
		ZEPHIR_INIT_VAR(&_4$$7);
		ZEPHIR_CONCAT_SV(&_4$$7, "-", &mode);
		ZEPHIR_INIT_VAR(&_5$$7);
		ZVAL_STRING(&_5$$7, "");
		ZEPHIR_CALL_FUNCTION(&_6$$7, "str_ireplace", NULL, 130, &_4$$7, &_5$$7, &cipher);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&blockSize, this_ptr, "getivlength", NULL, 0, &_6$$7);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&iv, "openssl_random_pseudo_bytes", NULL, 131, &ivLength);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&paddingType);
	zephir_read_property(&paddingType, this_ptr, SL("_padding"), PH_NOISY_CC);
	_7 = !ZEPHIR_IS_LONG(&paddingType, 0);
	if (_7) {
		_8 = ZEPHIR_IS_STRING(&mode, "cbc");
		if (!(_8)) {
			_8 = ZEPHIR_IS_STRING(&mode, "ecb");
		}
		_7 = _8;
	}
	if (_7) {
		ZEPHIR_CALL_METHOD(&padded, this_ptr, "_cryptpadtext", NULL, 0, &text, &mode, &blockSize, &paddingType);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&padded, &text);
	}
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_FUNCTION(&encrypted, "openssl_encrypt", NULL, 132, &padded, &cipher, &encryptKey, &_3, &iv);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("useSigning"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_3)) {
		ZEPHIR_CALL_METHOD(&hashAlgo$$10, this_ptr, "gethashalgo", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&digest$$10, "hash_hmac", NULL, 133, &hashAlgo$$10, &padded, &encryptKey, &__$true);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VVV(return_value, &iv, &digest$$10, &encrypted);
		RETURN_MM();
	}
	ZEPHIR_CONCAT_VV(return_value, &iv, &encrypted);
	RETURN_MM();

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
PHP_METHOD(Phalcon_Crypt, decrypt) {

	zend_bool _17, _12$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *key_param = NULL, __$true, __$null, decryptKey, ivLength, cipher, mode, blockSize, decrypted, ciphertext, hashAlgo, hashLength, iv, hash, _0, _1, _2, _3, _7, _16, _4$$7, _5$$7, _6$$7, _8$$8, _9$$8, _10$$8, _11$$8, _15$$8, _13$$9, _14$$9, _18$$11, _19$$11;
	zval text, key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&text);
	ZVAL_UNDEF(&key);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
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
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
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
		zephir_read_property(&decryptKey, this_ptr, SL("_key"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(&decryptKey, &key);
	}
	if (ZEPHIR_IS_EMPTY(&decryptKey)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Decryption key cannot be empty", "phalcon/crypt.zep", 440);
		return;
	}
	ZEPHIR_OBS_VAR(&cipher);
	zephir_read_property(&cipher, this_ptr, SL("_cipher"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "-");
	ZEPHIR_CALL_FUNCTION(&_1, "strrpos", NULL, 129, &cipher, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_2, (zephir_get_numberval(&_1) - zephir_fast_strlen_ev(&cipher)));
	ZEPHIR_INIT_NVAR(&_0);
	zephir_substr(&_0, &cipher, zephir_get_intval(&_2), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_VAR(&mode);
	zephir_fast_strtolower(&mode, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "assertcipherisavailable", NULL, 0, &cipher);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("ivLength"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&ivLength, &_3);
	if (EXPECTED(ZEPHIR_GT_LONG(&ivLength, 0))) {
		ZEPHIR_CPY_WRT(&blockSize, &ivLength);
	} else {
		ZEPHIR_INIT_VAR(&_4$$7);
		ZEPHIR_CONCAT_SV(&_4$$7, "-", &mode);
		ZEPHIR_INIT_VAR(&_5$$7);
		ZVAL_STRING(&_5$$7, "");
		ZEPHIR_CALL_FUNCTION(&_6$$7, "str_ireplace", NULL, 130, &_4$$7, &_5$$7, &cipher);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&blockSize, this_ptr, "getivlength", NULL, 0, &_6$$7);
		zephir_check_call_status();
	}
	ZVAL_LONG(&_3, 0);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "8bit");
	ZEPHIR_CALL_FUNCTION(&iv, "mb_substr", NULL, 134, &text, &_3, &ivLength, &_7);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("useSigning"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_3)) {
		ZEPHIR_CALL_METHOD(&hashAlgo, this_ptr, "gethashalgo", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$8);
		ZVAL_STRING(&_8$$8, "");
		ZEPHIR_CALL_FUNCTION(&_9$$8, "hash", NULL, 135, &hashAlgo, &_8$$8, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&hashLength);
		ZVAL_LONG(&hashLength, zephir_fast_strlen_ev(&_9$$8));
		ZEPHIR_INIT_NVAR(&_8$$8);
		ZVAL_STRING(&_8$$8, "8bit");
		ZEPHIR_CALL_FUNCTION(&hash, "mb_substr", NULL, 134, &text, &ivLength, &hashLength, &_8$$8);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_10$$8);
		zephir_add_function(&_10$$8, &ivLength, &hashLength);
		ZEPHIR_INIT_NVAR(&_8$$8);
		ZVAL_STRING(&_8$$8, "8bit");
		ZEPHIR_CALL_FUNCTION(&ciphertext, "mb_substr", NULL, 134, &text, &_10$$8, &__$null, &_8$$8);
		zephir_check_call_status();
		ZVAL_LONG(&_11$$8, 1);
		ZEPHIR_CALL_FUNCTION(&decrypted, "openssl_decrypt", NULL, 136, &ciphertext, &cipher, &decryptKey, &_11$$8, &iv);
		zephir_check_call_status();
		_12$$8 = ZEPHIR_IS_STRING(&mode, "cbc");
		if (!(_12$$8)) {
			_12$$8 = ZEPHIR_IS_STRING(&mode, "ecb");
		}
		if (_12$$8) {
			zephir_read_property(&_14$$9, this_ptr, SL("_padding"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_13$$9, this_ptr, "_cryptunpadtext", NULL, 0, &decrypted, &mode, &blockSize, &_14$$9);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&decrypted, &_13$$9);
		}
		ZEPHIR_CALL_FUNCTION(&_15$$8, "hash_hmac", NULL, 133, &hashAlgo, &decrypted, &decryptKey, &__$true);
		zephir_check_call_status();
		if (!ZEPHIR_IS_IDENTICAL(&_15$$8, &hash)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_mismatch_ce, "Hash does not match.", "phalcon/crypt.zep", 472);
			return;
		}
		RETURN_CCTOR(&decrypted);
	}
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "8bit");
	ZEPHIR_CALL_FUNCTION(&ciphertext, "mb_substr", NULL, 134, &text, &ivLength, &__$null, &_7);
	zephir_check_call_status();
	ZVAL_LONG(&_16, 1);
	ZEPHIR_CALL_FUNCTION(&decrypted, "openssl_decrypt", NULL, 136, &ciphertext, &cipher, &decryptKey, &_16, &iv);
	zephir_check_call_status();
	_17 = ZEPHIR_IS_STRING(&mode, "cbc");
	if (!(_17)) {
		_17 = ZEPHIR_IS_STRING(&mode, "ecb");
	}
	if (_17) {
		zephir_read_property(&_19$$11, this_ptr, SL("_padding"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_18$$11, this_ptr, "_cryptunpadtext", NULL, 0, &decrypted, &mode, &blockSize, &_19$$11);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&decrypted, &_18$$11);
	}
	RETURN_CCTOR(&decrypted);

}

/**
 * Encrypts a text returning the result as a base64 string.
 */
PHP_METHOD(Phalcon_Crypt, encryptBase64) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &text_param, &key, &safe_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'safe' must be of the type bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	safe = (Z_TYPE_P(safe_param) == IS_TRUE);
	}


	if (safe == 1) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "encrypt", NULL, 0, &text, key);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_1$$3, "base64_encode", NULL, 108, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "+/");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "-_");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "strtr", NULL, 48, &_1$$3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "=");
		zephir_fast_trim(return_value, &_4$$3, &_2$$3, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "encrypt", NULL, 0, &text, key);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 108, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decrypt a text that is coded as a base64 string.
 *
 * @throws \Phalcon\Crypt\Mismatch
 */
PHP_METHOD(Phalcon_Crypt, decryptBase64) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool safe;
	zval *text_param = NULL, *key = NULL, key_sub, *safe_param = NULL, __$null, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6;
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
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &text_param, &key, &safe_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be of the type string") TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'safe' must be of the type bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	safe = (Z_TYPE_P(safe_param) == IS_TRUE);
	}


	if (safe == 1) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "-_");
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "+/");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "strtr", NULL, 48, &text, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "===");
		ZVAL_DOUBLE(&_3$$3, zephir_safe_mod_long_long(((zephir_fast_strlen_ev(&text) + 3)), 4 TSRMLS_CC));
		ZEPHIR_INIT_NVAR(&_1$$3);
		zephir_substr(&_1$$3, &_0$$3, zephir_get_intval(&_3$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_VV(&_4$$3, &_2$$3, &_1$$3);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "base64_decode", NULL, 109, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "decrypt", NULL, 0, &_5$$3, key);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_6, "base64_decode", NULL, 109, &text);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "decrypt", NULL, 0, &_6, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a list of available ciphers.
 */
PHP_METHOD(Phalcon_Crypt, getAvailableCiphers) {

	zval availableCiphers, _0, _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&availableCiphers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("availableCiphers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&availableCiphers, &_0);
	if (UNEXPECTED(Z_TYPE_P(&availableCiphers) != IS_ARRAY)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initializeavailableciphers", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_1$$3, this_ptr, SL("availableCiphers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&availableCiphers, &_1$$3);
	}
	RETURN_CCTOR(&availableCiphers);

}

/**
 * Return a list of registered hashing algorithms suitable for hash_hmac.
 */
PHP_METHOD(Phalcon_Crypt, getAvailableHashAlgos) {

	zval algos;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&algos);

	ZEPHIR_MM_GROW();

	if (EXPECTED((zephir_function_exists_ex(SL("hash_hmac_algos") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_CALL_FUNCTION(&algos, "hash_hmac_algos", NULL, 137);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(&algos, "hash_algos", NULL, 138);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&algos);

}

/**
 * Assert the cipher is available.
 *
 * @throws \Phalcon\Crypt\Exception
 */
PHP_METHOD(Phalcon_Crypt, assertCipherIsAvailable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cipher_param = NULL, availableCiphers, _0$$3, _1$$3, _2$$3;
	zval cipher;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cipher);
	ZVAL_UNDEF(&availableCiphers);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cipher_param);

	if (UNEXPECTED(Z_TYPE_P(cipher_param) != IS_STRING && Z_TYPE_P(cipher_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cipher' must be of the type string") TSRMLS_CC);
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
	if (!(zephir_fast_in_array(&cipher, &availableCiphers TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_crypt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "The cipher algorithm \"%s\" is not supported on this system.");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "sprintf", NULL, 139, &_1$$3, &cipher);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 4, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/crypt.zep", 561 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Assert the hash algorithm is available.
 *
 * @throws \Phalcon\Crypt\Exception
 */
PHP_METHOD(Phalcon_Crypt, assertHashAlgorithmAvailable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *hashAlgo_param = NULL, availableAlgorithms, _0$$3, _1$$3, _2$$3;
	zval hashAlgo;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&hashAlgo);
	ZVAL_UNDEF(&availableAlgorithms);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &hashAlgo_param);

	if (UNEXPECTED(Z_TYPE_P(hashAlgo_param) != IS_STRING && Z_TYPE_P(hashAlgo_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'hashAlgo' must be of the type string") TSRMLS_CC);
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
	if (!(zephir_fast_in_array(&hashAlgo, &availableAlgorithms TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_crypt_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "The hash algorithm \"%s\" is not supported on this system.");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "sprintf", NULL, 139, &_1$$3, &hashAlgo);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 4, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/crypt.zep", 582 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Initialize available cipher algorithms.
 *
 * @throws \Phalcon\Crypt\Exception
 */
PHP_METHOD(Phalcon_Crypt, getIvLength) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cipher_param = NULL;
	zval cipher;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cipher);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cipher_param);

	if (UNEXPECTED(Z_TYPE_P(cipher_param) != IS_STRING && Z_TYPE_P(cipher_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cipher' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cipher_param) == IS_STRING)) {
		zephir_get_strval(&cipher, cipher_param);
	} else {
		ZEPHIR_INIT_VAR(&cipher);
		ZVAL_EMPTY_STRING(&cipher);
	}


	if (!((zephir_function_exists_ex(SL("openssl_cipher_iv_length") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "openssl extension is required", "phalcon/crypt.zep", 594);
		return;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_cipher_iv_length", NULL, 140, &cipher);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Initialize available cipher algorithms.
 *
 * @throws \Phalcon\Crypt\Exception
 */
PHP_METHOD(Phalcon_Crypt, initializeAvailableCiphers) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$true, _0;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	if (!((zephir_function_exists_ex(SL("openssl_get_cipher_methods") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "openssl extension is required", "phalcon/crypt.zep", 608);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_0, "openssl_get_cipher_methods", NULL, 141, &__$true);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("availableCiphers"), &_0);
	ZEPHIR_MM_RESTORE();

}

