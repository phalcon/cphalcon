
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
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"


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

	zend_declare_property_long(phalcon_crypt_ce, SL("_padding"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_crypt_ce, SL("_mode"), "cbc", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_crypt_ce, SL("_cipher"), "rijndael-256", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_DEFAULT"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ANSI_X_923"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_PKCS7"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ISO_10126"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ISO_IEC_7816_4"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_ZERO"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_crypt_ce, SL("PADDING_SPACE"), 6 TSRMLS_CC);

	zend_class_implements(phalcon_crypt_ce TSRMLS_CC, 1, phalcon_cryptinterface_ce);
	return SUCCESS;

}

/**
 * @brief Phalcon\CryptInterface Phalcon\Crypt::setPadding(int $scheme)
 *
 * @param int scheme Padding scheme
 */
PHP_METHOD(Phalcon_Crypt, setPadding) {

	zval *scheme_param = NULL, *_0;
	int scheme;

	zephir_fetch_params(0, 1, 0, &scheme_param);

	if (unlikely(Z_TYPE_P(scheme_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'scheme' must be a long/integer") TSRMLS_CC);
		RETURN_NULL();
	}

	scheme = Z_LVAL_P(scheme_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, scheme);
	zephir_update_property_this(this_ptr, SL("_padding"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets the cipher algorithm
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

	if (likely(Z_TYPE_P(cipher_param) == IS_STRING)) {
		zephir_get_strval(cipher, cipher_param);
	} else {
		ZEPHIR_INIT_VAR(cipher);
		ZVAL_EMPTY_STRING(cipher);
	}


	zephir_update_property_this(this_ptr, SL("_cipher"), cipher TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the current cipher
 */
PHP_METHOD(Phalcon_Crypt, getCipher) {


	RETURN_MEMBER(this_ptr, "_cipher");

}

/**
 * Sets the encrypt/decrypt mode
 */
PHP_METHOD(Phalcon_Crypt, setMode) {

	zval *mode_param = NULL;
	zval *mode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mode_param);

	if (unlikely(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(mode);
		ZVAL_EMPTY_STRING(mode);
	}


	zephir_update_property_this(this_ptr, SL("_mode"), mode TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the current encryption mode
 */
PHP_METHOD(Phalcon_Crypt, getMode) {


	RETURN_MEMBER(this_ptr, "_mode");

}

/**
 * Sets the encryption key
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

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_update_property_this(this_ptr, SL("_key"), key TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the encryption key
 */
PHP_METHOD(Phalcon_Crypt, getKey) {


	RETURN_MEMBER(this_ptr, "_key");

}

/**
 * Adds padding @a padding_type to @a text
 *
 * @param return_value Result, possibly padded
 * @param text Message to be padded
 * @param mode Encryption mode; padding is applied only in CBC or ECB mode
 * @param block_size Cipher block size
 * @param padding_type Padding scheme
 * @see http://www.di-mgt.com.au/cryptopad.html
 */
PHP_METHOD(Phalcon_Crypt, _cryptPadText) {

	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_10 = NULL;
	zend_bool _0, _7;
	int blockSize, paddingType, i, paddingSize = 0, ZEPHIR_LAST_CALL_STATUS, _8, _9;
	zval *text_param = NULL, *mode_param = NULL, *blockSize_param = NULL, *paddingType_param = NULL, *padding = NULL, _1 = zval_used_for_init, *_2 = NULL, *_4 = NULL, *_6 = NULL, _11 = zval_used_for_init, *_12;
	zval *text = NULL, *mode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &text_param, &mode_param, &blockSize_param, &paddingType_param);

	zephir_get_strval(text, text_param);
	if (unlikely(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(mode);
		ZVAL_EMPTY_STRING(mode);
	}
	if (unlikely(Z_TYPE_P(blockSize_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'blockSize' must be a long/integer") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	blockSize = Z_LVAL_P(blockSize_param);
	if (unlikely(Z_TYPE_P(paddingType_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'paddingType' must be a long/integer") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	paddingType = Z_LVAL_P(paddingType_param);
	ZEPHIR_INIT_VAR(padding);
	ZVAL_NULL(padding);


	_0 = ZEPHIR_IS_STRING(mode, "cbc");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING(mode, "ecb");
	}
	if (_0) {
		paddingSize = (blockSize - (zephir_safe_mod_long_long(zephir_fast_strlen_ev(text), blockSize TSRMLS_CC)));
		if (paddingSize >= 256) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Block size is bigger than 256", "phalcon/crypt.zep", 147);
			return;
		}
		do {
			if (paddingType == 1) {
				ZEPHIR_SINIT_VAR(_1);
				ZVAL_LONG(&_1, 0);
				ZEPHIR_CALL_FUNCTION(&_2, "chr", &_3, 65, &_1);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, (paddingSize - 1));
				ZEPHIR_CALL_FUNCTION(&_4, "str_repeat", &_5, 66, _2, &_1);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, paddingSize);
				ZEPHIR_CALL_FUNCTION(&_6, "chr", &_3, 65, &_1);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(padding);
				ZEPHIR_CONCAT_VV(padding, _4, _6);
				break;
			}
			if (paddingType == 2) {
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, paddingSize);
				ZEPHIR_CALL_FUNCTION(&_2, "chr", &_3, 65, &_1);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, paddingSize);
				ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", &_5, 66, _2, &_1);
				zephir_check_call_status();
				break;
			}
			if (paddingType == 3) {
				ZEPHIR_INIT_NVAR(padding);
				ZVAL_STRING(padding, "", 1);
				_9 = (paddingSize - 2);
				_8 = 0;
				_7 = 0;
				if (_8 <= _9) {
					while (1) {
						if (_7) {
							_8++;
							if (!(_8 <= _9)) {
								break;
							}
						} else {
							_7 = 1;
						}
						i = _8;
						ZEPHIR_CALL_FUNCTION(&_2, "rand", &_10, 40);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_4, "chr", &_3, 65, _2);
						zephir_check_call_status();
						zephir_concat_self(&padding, _4 TSRMLS_CC);
					}
				}
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, paddingSize);
				ZEPHIR_CALL_FUNCTION(&_6, "chr", &_3, 65, &_1);
				zephir_check_call_status();
				zephir_concat_self(&padding, _6 TSRMLS_CC);
				break;
			}
			if (paddingType == 4) {
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, 0x80);
				ZEPHIR_CALL_FUNCTION(&_2, "chr", &_3, 65, &_1);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, 0);
				ZEPHIR_CALL_FUNCTION(&_4, "chr", &_3, 65, &_1);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, (paddingSize - 1));
				ZEPHIR_CALL_FUNCTION(&_6, "str_repeat", &_5, 66, _4, &_1);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(padding);
				ZEPHIR_CONCAT_VV(padding, _2, _6);
				break;
			}
			if (paddingType == 5) {
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, 0);
				ZEPHIR_CALL_FUNCTION(&_2, "chr", &_3, 65, &_1);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_LONG(&_1, paddingSize);
				ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", &_5, 66, _2, &_1);
				zephir_check_call_status();
				break;
			}
			if (paddingType == 6) {
				ZEPHIR_SINIT_NVAR(_1);
				ZVAL_STRING(&_1, " ", 0);
				ZEPHIR_SINIT_VAR(_11);
				ZVAL_LONG(&_11, paddingSize);
				ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", &_5, 66, &_1, &_11);
				zephir_check_call_status();
				break;
			}
			paddingSize = 0;
			break;
		} while(0);

	}
	if (!(paddingSize)) {
		RETURN_CTOR(text);
	}
	if (paddingSize > blockSize) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Invalid padding size", "phalcon/crypt.zep", 191);
		return;
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_NVAR(_11);
	ZVAL_LONG(&_11, paddingSize);
	ZEPHIR_INIT_VAR(_12);
	zephir_substr(_12, padding, 0 , zephir_get_intval(&_11), 0);
	ZEPHIR_CONCAT_VV(return_value, text, _12);
	RETURN_MM();

}

/**
 * Removes padding @a padding_type from @a text
 * If the function detects that the text was not padded, it will return it unmodified
 *
 * @param return_value Result, possibly unpadded
 * @param text Message to be unpadded
 * @param mode Encryption mode; unpadding is applied only in CBC or ECB mode
 * @param block_size Cipher block size
 * @param padding_type Padding scheme
 */
PHP_METHOD(Phalcon_Crypt, _cryptUnpadText) {

	unsigned char _14, _16;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL, *_11 = NULL;
	zend_bool _0, _1, _2, _13, _15;
	long length;
	int blockSize, paddingType, i, paddingSize = 0, ord, ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *mode_param = NULL, *blockSize_param = NULL, *paddingType_param = NULL, *padding = NULL, *last = NULL, _3 = zval_used_for_init, _4 = zval_used_for_init, *_5 = NULL, _7 = zval_used_for_init, *_8 = NULL, *_10 = NULL, *_12 = NULL;
	zval *text = NULL, *mode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &text_param, &mode_param, &blockSize_param, &paddingType_param);

	zephir_get_strval(text, text_param);
	if (unlikely(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(mode);
		ZVAL_EMPTY_STRING(mode);
	}
	if (unlikely(Z_TYPE_P(blockSize_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'blockSize' must be a long/integer") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	blockSize = Z_LVAL_P(blockSize_param);
	if (unlikely(Z_TYPE_P(paddingType_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'paddingType' must be a long/integer") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	paddingType = Z_LVAL_P(paddingType_param);


	length = zephir_fast_strlen_ev(text);
	_0 = length > 0;
	if (_0) {
		_0 = (zephir_safe_mod_long_long(length, blockSize TSRMLS_CC) == 0);
	}
	_1 = _0;
	if (_1) {
		_2 = ZEPHIR_IS_STRING(mode, "cbc");
		if (!(_2)) {
			_2 = ZEPHIR_IS_STRING(mode, "ecb");
		}
		_1 = _2;
	}
	if (_1) {
		do {
			if (paddingType == 1) {
				ZEPHIR_SINIT_VAR(_3);
				ZVAL_LONG(&_3, (length - 1));
				ZEPHIR_SINIT_VAR(_4);
				ZVAL_LONG(&_4, 1);
				ZEPHIR_INIT_VAR(last);
				zephir_substr(last, text, zephir_get_intval(&_3), 1 , 0);
				ZEPHIR_CALL_FUNCTION(&_5, "ord", &_6, 67, last);
				zephir_check_call_status();
				ord = zephir_get_intval(_5);
				if (ord <= blockSize) {
					paddingSize = ord;
					ZEPHIR_SINIT_VAR(_7);
					ZVAL_LONG(&_7, 0);
					ZEPHIR_CALL_FUNCTION(&_8, "chr", &_9, 65, &_7);
					zephir_check_call_status();
					ZEPHIR_SINIT_NVAR(_7);
					ZVAL_LONG(&_7, (paddingSize - 1));
					ZEPHIR_CALL_FUNCTION(&_10, "str_repeat", &_11, 66, _8, &_7);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(padding);
					ZEPHIR_CONCAT_VV(padding, _10, last);
					ZEPHIR_SINIT_NVAR(_7);
					ZVAL_LONG(&_7, (length - paddingSize));
					ZEPHIR_INIT_VAR(_12);
					zephir_substr(_12, text, zephir_get_intval(&_7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					if (!ZEPHIR_IS_EQUAL(_12, padding)) {
						paddingSize = 0;
					}
				}
				break;
			}
			if (paddingType == 2) {
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_LONG(&_3, (length - 1));
				ZEPHIR_SINIT_NVAR(_4);
				ZVAL_LONG(&_4, 1);
				ZEPHIR_INIT_NVAR(last);
				zephir_substr(last, text, zephir_get_intval(&_3), 1 , 0);
				ZEPHIR_CALL_FUNCTION(&_5, "ord", &_6, 67, last);
				zephir_check_call_status();
				ord = zephir_get_intval(_5);
				if (ord <= blockSize) {
					paddingSize = ord;
					ZEPHIR_SINIT_NVAR(_7);
					ZVAL_LONG(&_7, paddingSize);
					ZEPHIR_CALL_FUNCTION(&_8, "chr", &_9, 65, &_7);
					zephir_check_call_status();
					ZEPHIR_SINIT_NVAR(_7);
					ZVAL_LONG(&_7, paddingSize);
					ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", &_11, 66, _8, &_7);
					zephir_check_call_status();
					ZEPHIR_SINIT_NVAR(_7);
					ZVAL_LONG(&_7, (length - paddingSize));
					ZEPHIR_INIT_NVAR(_12);
					zephir_substr(_12, text, zephir_get_intval(&_7), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					if (!ZEPHIR_IS_EQUAL(_12, padding)) {
						paddingSize = 0;
					}
				}
				break;
			}
			if (paddingType == 3) {
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_LONG(&_3, (length - 1));
				ZEPHIR_SINIT_NVAR(_4);
				ZVAL_LONG(&_4, 1);
				ZEPHIR_INIT_NVAR(last);
				zephir_substr(last, text, zephir_get_intval(&_3), 1 , 0);
				ZEPHIR_CALL_FUNCTION(&_5, "ord", &_6, 67, last);
				zephir_check_call_status();
				paddingSize = zephir_get_intval(_5);
				break;
			}
			if (paddingType == 4) {
				i = (length - 1);
				while (1) {
					_13 = i > 0;
					if (_13) {
						_14 = ZEPHIR_STRING_OFFSET(text, i);
						_13 = _14 == 0x00;
					}
					_15 = _13;
					if (_15) {
						_15 = paddingSize < blockSize;
					}
					if (!(_15)) {
						break;
					}
					paddingSize++;
					i--;
				}
				_16 = ZEPHIR_STRING_OFFSET(text, i);
				if (_16 == 0x80) {
					paddingSize++;
				} else {
					paddingSize = 0;
				}
				break;
			}
			if (paddingType == 5) {
				i = (length - 1);
				while (1) {
					_13 = i >= 0;
					if (_13) {
						_14 = ZEPHIR_STRING_OFFSET(text, i);
						_13 = _14 == 0x00;
					}
					_15 = _13;
					if (_15) {
						_15 = paddingSize <= blockSize;
					}
					if (!(_15)) {
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
					_13 = i >= 0;
					if (_13) {
						_14 = ZEPHIR_STRING_OFFSET(text, i);
						_13 = _14 == 0x20;
					}
					_15 = _13;
					if (_15) {
						_15 = paddingSize <= blockSize;
					}
					if (!(_15)) {
						break;
					}
					paddingSize++;
					i--;
				}
				break;
			}
			break;
		} while(0);

		_13 = (paddingSize) ? 1 : 0;
		if (_13) {
			_13 = paddingSize <= blockSize;
		}
		if (_13) {
			if (paddingSize < length) {
				ZEPHIR_SINIT_NVAR(_3);
				ZVAL_LONG(&_3, 0);
				ZEPHIR_SINIT_NVAR(_4);
				ZVAL_LONG(&_4, (length - paddingSize));
				zephir_substr(return_value, text, 0 , zephir_get_intval(&_4), 0);
				RETURN_MM();
			}
			RETURN_MM_STRING("", 1);
		} else {
			paddingSize = 0;
		}
	}
	if (!(paddingSize)) {
		RETURN_CTOR(text);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Encrypts a text
 *
 *<code>
 *	$encrypted = $crypt->encrypt("Ultra-secret text", "encrypt password");
 *</code>
 */
PHP_METHOD(Phalcon_Crypt, encrypt) {

	zend_bool _3, _4;
	int ZEPHIR_LAST_CALL_STATUS, _2;
	zval *text_param = NULL, *key_param = NULL, *encryptKey = NULL, *ivSize = NULL, *iv = NULL, *cipher, *mode, *blockSize = NULL, *paddingType, *padded = NULL, _0, *_1 = NULL;
	zval *text = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key_param);

	if (unlikely(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(text, text_param);
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	} else {
	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}
	}


	if (!((zephir_function_exists_ex(SS("mcrypt_get_iv_size") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "mcrypt extension is required", "phalcon/crypt.zep", 307);
		return;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(key, "")) {
		ZEPHIR_OBS_VAR(encryptKey);
		zephir_read_property_this(&encryptKey, this_ptr, SL("_key"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(encryptKey, key);
	}
	if (ZEPHIR_IS_EMPTY(encryptKey)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Encryption key cannot be empty", "phalcon/crypt.zep", 317);
		return;
	}
	ZEPHIR_OBS_VAR(cipher);
	zephir_read_property_this(&cipher, this_ptr, SL("_cipher"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(mode);
	zephir_read_property_this(&mode, this_ptr, SL("_mode"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&ivSize, "mcrypt_get_iv_size", NULL, 68, cipher, mode);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(ivSize, zephir_fast_strlen_ev(encryptKey))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Size of key is too large for this algorithm", "phalcon/crypt.zep", 325);
		return;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(&iv, "mcrypt_create_iv", NULL, 69, ivSize, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(iv) != IS_STRING) {
		ZEPHIR_CALL_FUNCTION(&_1, "strval", NULL, 57, iv);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(iv, _1);
	}
	ZEPHIR_CALL_FUNCTION(&blockSize, "mcrypt_get_block_size", NULL, 70, cipher, mode);
	zephir_check_call_status();
	if (Z_TYPE_P(blockSize) != IS_LONG) {
		_2 = zephir_get_intval(blockSize);
		ZEPHIR_INIT_NVAR(blockSize);
		ZVAL_LONG(blockSize, _2);
	}
	ZEPHIR_OBS_VAR(paddingType);
	zephir_read_property_this(&paddingType, this_ptr, SL("_padding"), PH_NOISY_CC);
	_3 = !ZEPHIR_IS_LONG(paddingType, 0);
	if (_3) {
		_4 = ZEPHIR_IS_STRING(mode, "cbc");
		if (!(_4)) {
			_4 = ZEPHIR_IS_STRING(mode, "ecb");
		}
		_3 = _4;
	}
	if (_3) {
		ZEPHIR_CALL_METHOD(&padded, this_ptr, "_cryptpadtext", NULL, 0, text, mode, blockSize, paddingType);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(padded, text);
	}
	ZEPHIR_CALL_FUNCTION(&_1, "mcrypt_encrypt", NULL, 71, cipher, encryptKey, padded, mode, iv);
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
 */
PHP_METHOD(Phalcon_Crypt, decrypt) {

	zend_bool _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *key = NULL, *decryptKey = NULL, *ivSize = NULL, *cipher, *mode, *keySize, *length, *blockSize = NULL, *paddingType, *decrypted = NULL, *_0, _1, *_2;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key);

	if (unlikely(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(text, text_param);
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}


	if (!((zephir_function_exists_ex(SS("mcrypt_get_iv_size") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "mcrypt extension is required", "phalcon/crypt.zep", 361);
		return;
	}
	if (Z_TYPE_P(key) == IS_NULL) {
		ZEPHIR_OBS_VAR(decryptKey);
		zephir_read_property_this(&decryptKey, this_ptr, SL("_key"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(decryptKey, key);
	}
	if (ZEPHIR_IS_EMPTY(decryptKey)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Decryption key cannot be empty", "phalcon/crypt.zep", 371);
		return;
	}
	ZEPHIR_OBS_VAR(cipher);
	zephir_read_property_this(&cipher, this_ptr, SL("_cipher"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(mode);
	zephir_read_property_this(&mode, this_ptr, SL("_mode"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&ivSize, "mcrypt_get_iv_size", NULL, 68, cipher, mode);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(keySize);
	ZVAL_LONG(keySize, zephir_fast_strlen_ev(decryptKey));
	if (ZEPHIR_GT(keySize, ivSize)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Size of key is too large for this algorithm", "phalcon/crypt.zep", 380);
		return;
	}
	ZEPHIR_INIT_VAR(length);
	ZVAL_LONG(length, zephir_fast_strlen_ev(text));
	if (ZEPHIR_GT(keySize, length)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Size of IV is larger than text to decrypt", "phalcon/crypt.zep", 385);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_substr(_0, text, zephir_get_intval(ivSize), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_INIT_VAR(_2);
	zephir_substr(_2, text, 0 , zephir_get_intval(ivSize), 0);
	ZEPHIR_CALL_FUNCTION(&decrypted, "mcrypt_decrypt", NULL, 72, cipher, decryptKey, _0, mode, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&blockSize, "mcrypt_get_block_size", NULL, 70, cipher, mode);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(paddingType);
	zephir_read_property_this(&paddingType, this_ptr, SL("_padding"), PH_NOISY_CC);
	_3 = ZEPHIR_IS_STRING(mode, "cbc");
	if (!(_3)) {
		_3 = ZEPHIR_IS_STRING(mode, "ecb");
	}
	if (_3) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "_cryptunpadtext", NULL, 0, decrypted, mode, blockSize, paddingType);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(decrypted);

}

/**
 * Encrypts a text returning the result as a base64 string
 */
PHP_METHOD(Phalcon_Crypt, encryptBase64) {

	zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool safe;
	zval *text_param = NULL, *key = NULL, *safe_param = NULL, *_0 = NULL, *_2 = NULL, _4, _5;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &text_param, &key, &safe_param);

	if (unlikely(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(text, text_param);
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}
	if (!safe_param) {
		safe = 0;
	} else {
	if (unlikely(Z_TYPE_P(safe_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'safe' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	safe = Z_BVAL_P(safe_param);
	}


	if (safe == 1) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "encrypt", &_1, 0, text, key);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_2, "base64_encode", &_3, 45, _0);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "+/", 0);
		ZEPHIR_SINIT_VAR(_5);
		ZVAL_STRING(&_5, "-_", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 73, _2, &_4, &_5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "encrypt", &_1, 0, text, key);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", &_3, 45, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decrypt a text that is coded as a base64 string
 */
PHP_METHOD(Phalcon_Crypt, decryptBase64) {

	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool safe;
	zval *text_param = NULL, *key = NULL, *safe_param = NULL, _0, _1, *_2 = NULL, *_3 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &text_param, &key, &safe_param);

	if (unlikely(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(text, text_param);
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}
	if (!safe_param) {
		safe = 0;
	} else {
	if (unlikely(Z_TYPE_P(safe_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'safe' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	safe = Z_BVAL_P(safe_param);
	}


	if (safe == 1) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_STRING(&_0, "-_", 0);
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "+/", 0);
		ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 73, text, &_0, &_1);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_3, "base64_decode", &_4, 46, _2);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "decrypt", &_5, 0, _3, key);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_2, "base64_decode", &_4, 46, text);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "decrypt", &_5, 0, _2, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a list of available cyphers
 */
PHP_METHOD(Phalcon_Crypt, getAvailableCiphers) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("mcrypt_list_algorithms", NULL, 74);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a list of available modes
 */
PHP_METHOD(Phalcon_Crypt, getAvailableModes) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("mcrypt_list_modes", NULL, 75);
	zephir_check_call_status();
	RETURN_MM();

}

