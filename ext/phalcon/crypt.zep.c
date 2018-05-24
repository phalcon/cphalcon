
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
#include "kernel/array.h"


/**
 * Phalcon\Crypt
 *
 * Provides encryption facilities to phalcon applications
 *
 *<code>
 * $crypt = new \Phalcon\Crypt();
 *
 * $key  = "le password";
 * $text = "This is a secret text";
 *
 * $encrypted = $crypt->encrypt($text, $key);
 *
 * echo $crypt->decrypt($encrypted, $key);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Crypt) {

	ZEPHIR_REGISTER_CLASS(Phalcon, Crypt, phalcon, crypt, phalcon_crypt_method_entry, 0);

	zend_declare_property_null(phalcon_crypt_ce, SL("_key"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_crypt_ce, SL("_padding"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_crypt_ce, SL("_cipher"), "aes-256-cfb", ZEND_ACC_PROTECTED TSRMLS_CC);

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
 * Changes the padding scheme used
 */
PHP_METHOD(Phalcon_Crypt, setPadding) {

	zval *scheme_param = NULL, *_0;
	zend_long scheme;

	zephir_fetch_params(0, 1, 0, &scheme_param);

	if (UNEXPECTED(Z_TYPE_P(scheme_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'scheme' must be a int") TSRMLS_CC);
		RETURN_NULL();
	}
	scheme = Z_LVAL_P(scheme_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, scheme);
	zephir_update_property_this(getThis(), SL("_padding"), _0 TSRMLS_CC);
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

	if (UNEXPECTED(Z_TYPE_P(cipher_param) != IS_STRING && Z_TYPE_P(cipher_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'cipher' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(cipher_param) == IS_STRING)) {
		zephir_get_strval(cipher, cipher_param);
	} else {
		ZEPHIR_INIT_VAR(cipher);
		ZVAL_EMPTY_STRING(cipher);
	}


	zephir_update_property_this(getThis(), SL("_cipher"), cipher TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the current cipher
 */
PHP_METHOD(Phalcon_Crypt, getCipher) {

	

	RETURN_MEMBER(getThis(), "_cipher");

}

/**
 * Sets the encryption key
 */
PHP_METHOD(Phalcon_Crypt, setKey) {

	zval *key_param = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	zephir_update_property_this(getThis(), SL("_key"), key TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the encryption key
 */
PHP_METHOD(Phalcon_Crypt, getKey) {

	

	RETURN_MEMBER(getThis(), "_key");

}

/**
 * Pads texts before encryption
 *
 * @see http://www.di-mgt.com.au/cryptopad.html
 */
PHP_METHOD(Phalcon_Crypt, _cryptPadText) {

	zend_bool _0, _7$$7;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_long blockSize, paddingType, ZEPHIR_LAST_CALL_STATUS, i = 0, paddingSize, _8$$7, _9$$7;
	zval *text_param = NULL, *mode_param = NULL, *blockSize_param = NULL, *paddingType_param = NULL, *padding = NULL, _23, _24, *_25, _1$$5 = zval_used_for_init, *_2$$5 = NULL, *_3$$5 = NULL, *_4$$5 = NULL, _5$$6 = zval_used_for_init, *_6$$6 = NULL, _13$$7, *_14$$7 = NULL, *_10$$8 = NULL, *_12$$8 = NULL, _15$$9 = zval_used_for_init, *_16$$9 = NULL, *_17$$9 = NULL, *_18$$9 = NULL, _19$$10 = zval_used_for_init, *_20$$10 = NULL, _21$$11, _22$$11;
	zval *text = NULL, *mode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &text_param, &mode_param, &blockSize_param, &paddingType_param);

	zephir_get_strval(text, text_param);
	if (UNEXPECTED(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(mode);
		ZVAL_EMPTY_STRING(mode);
	}
	if (UNEXPECTED(Z_TYPE_P(blockSize_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'blockSize' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	blockSize = Z_LVAL_P(blockSize_param);
	if (UNEXPECTED(Z_TYPE_P(paddingType_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'paddingType' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	paddingType = Z_LVAL_P(paddingType_param);


	paddingSize = 0;
	ZEPHIR_INIT_VAR(padding);
	ZVAL_NULL(padding);
	_0 = ZEPHIR_IS_STRING(mode, "cbc");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING(mode, "ecb");
	}
	if (_0) {
		paddingSize = (blockSize - (zephir_safe_mod_long_long(zephir_fast_strlen_ev(text), blockSize TSRMLS_CC)));
		if (paddingSize >= 256) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Block size is bigger than 256", "phalcon/crypt.zep", 121);
			return;
		}
		do {
			if (paddingType == 1) {
				ZEPHIR_SINIT_VAR(_1$$5);
				ZVAL_LONG(&_1$$5, 0);
				ZEPHIR_CALL_FUNCTION(&_2$$5, "chr", NULL, 146, &_1$$5);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_1$$5);
				ZVAL_LONG(&_1$$5, (paddingSize - 1));
				ZEPHIR_CALL_FUNCTION(&_3$$5, "str_repeat", NULL, 147, _2$$5, &_1$$5);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_1$$5);
				ZVAL_LONG(&_1$$5, paddingSize);
				ZEPHIR_CALL_FUNCTION(&_4$$5, "chr", NULL, 146, &_1$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(padding);
				ZEPHIR_CONCAT_VV(padding, _3$$5, _4$$5);
				break;
			}
			if (paddingType == 2) {
				ZEPHIR_SINIT_VAR(_5$$6);
				ZVAL_LONG(&_5$$6, paddingSize);
				ZEPHIR_CALL_FUNCTION(&_6$$6, "chr", NULL, 146, &_5$$6);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_5$$6);
				ZVAL_LONG(&_5$$6, paddingSize);
				ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", NULL, 147, _6$$6, &_5$$6);
				zephir_check_call_status();
				break;
			}
			if (paddingType == 3) {
				ZEPHIR_INIT_NVAR(padding);
				ZVAL_STRING(padding, "", 1);
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
						ZEPHIR_CALL_FUNCTION(&_10$$8, "rand", &_11, 123);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_12$$8, "chr", NULL, 146, _10$$8);
						zephir_check_call_status();
						zephir_concat_self(&padding, _12$$8 TSRMLS_CC);
					}
				}
				ZEPHIR_SINIT_VAR(_13$$7);
				ZVAL_LONG(&_13$$7, paddingSize);
				ZEPHIR_CALL_FUNCTION(&_14$$7, "chr", NULL, 146, &_13$$7);
				zephir_check_call_status();
				zephir_concat_self(&padding, _14$$7 TSRMLS_CC);
				break;
			}
			if (paddingType == 4) {
				ZEPHIR_SINIT_VAR(_15$$9);
				ZVAL_LONG(&_15$$9, 0x80);
				ZEPHIR_CALL_FUNCTION(&_16$$9, "chr", NULL, 146, &_15$$9);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_15$$9);
				ZVAL_LONG(&_15$$9, 0);
				ZEPHIR_CALL_FUNCTION(&_17$$9, "chr", NULL, 146, &_15$$9);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_15$$9);
				ZVAL_LONG(&_15$$9, (paddingSize - 1));
				ZEPHIR_CALL_FUNCTION(&_18$$9, "str_repeat", NULL, 147, _17$$9, &_15$$9);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(padding);
				ZEPHIR_CONCAT_VV(padding, _16$$9, _18$$9);
				break;
			}
			if (paddingType == 5) {
				ZEPHIR_SINIT_VAR(_19$$10);
				ZVAL_LONG(&_19$$10, 0);
				ZEPHIR_CALL_FUNCTION(&_20$$10, "chr", NULL, 146, &_19$$10);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_19$$10);
				ZVAL_LONG(&_19$$10, paddingSize);
				ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", NULL, 147, _20$$10, &_19$$10);
				zephir_check_call_status();
				break;
			}
			if (paddingType == 6) {
				ZEPHIR_SINIT_VAR(_21$$11);
				ZVAL_STRING(&_21$$11, " ", 0);
				ZEPHIR_SINIT_VAR(_22$$11);
				ZVAL_LONG(&_22$$11, paddingSize);
				ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", NULL, 147, &_21$$11, &_22$$11);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Invalid padding size", "phalcon/crypt.zep", 165);
		return;
	}
	ZEPHIR_SINIT_VAR(_23);
	ZVAL_LONG(&_23, 0);
	ZEPHIR_SINIT_VAR(_24);
	ZVAL_LONG(&_24, paddingSize);
	ZEPHIR_INIT_VAR(_25);
	zephir_substr(_25, padding, 0 , zephir_get_intval(&_24), 0);
	ZEPHIR_CONCAT_VV(return_value, text, _25);
	RETURN_MM();

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
PHP_METHOD(Phalcon_Crypt, _cryptUnpadText) {

	unsigned char _20$$11, _22$$11, _24$$15, _27$$17;
	zend_bool _0, _1, _2, _19$$11, _21$$11, _23$$15, _25$$15, _26$$17, _28$$17, _29$$3;
	long length = 0;
	zend_long blockSize, paddingType, ZEPHIR_LAST_CALL_STATUS, i = 0, paddingSize, ord = 0;
	zval *text_param = NULL, *mode_param = NULL, *blockSize_param = NULL, *paddingType_param = NULL, *padding = NULL, *last = NULL, _3$$4, _4$$4, *_5$$4 = NULL, _6$$5 = zval_used_for_init, *_7$$5 = NULL, *_8$$5 = NULL, *_9$$5, _10$$7, _11$$7, *_12$$7 = NULL, _13$$8 = zval_used_for_init, *_14$$8 = NULL, *_15$$8, _16$$10, _17$$10, *_18$$10 = NULL, _30$$21, _31$$21;
	zval *text = NULL, *mode = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &text_param, &mode_param, &blockSize_param, &paddingType_param);

	zephir_get_strval(text, text_param);
	if (UNEXPECTED(Z_TYPE_P(mode_param) != IS_STRING && Z_TYPE_P(mode_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'mode' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(mode_param) == IS_STRING)) {
		zephir_get_strval(mode, mode_param);
	} else {
		ZEPHIR_INIT_VAR(mode);
		ZVAL_EMPTY_STRING(mode);
	}
	if (UNEXPECTED(Z_TYPE_P(blockSize_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'blockSize' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	blockSize = Z_LVAL_P(blockSize_param);
	if (UNEXPECTED(Z_TYPE_P(paddingType_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'paddingType' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	paddingType = Z_LVAL_P(paddingType_param);


	paddingSize = 0;
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
				ZEPHIR_SINIT_VAR(_3$$4);
				ZVAL_LONG(&_3$$4, (length - 1));
				ZEPHIR_SINIT_VAR(_4$$4);
				ZVAL_LONG(&_4$$4, 1);
				ZEPHIR_INIT_VAR(last);
				zephir_substr(last, text, zephir_get_intval(&_3$$4), 1 , 0);
				ZEPHIR_CALL_FUNCTION(&_5$$4, "ord", NULL, 148, last);
				zephir_check_call_status();
				ord = zephir_get_intval(_5$$4);
				if (ord <= blockSize) {
					paddingSize = ord;
					ZEPHIR_SINIT_VAR(_6$$5);
					ZVAL_LONG(&_6$$5, 0);
					ZEPHIR_CALL_FUNCTION(&_7$$5, "chr", NULL, 146, &_6$$5);
					zephir_check_call_status();
					ZEPHIR_SINIT_NVAR(_6$$5);
					ZVAL_LONG(&_6$$5, (paddingSize - 1));
					ZEPHIR_CALL_FUNCTION(&_8$$5, "str_repeat", NULL, 147, _7$$5, &_6$$5);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(padding);
					ZEPHIR_CONCAT_VV(padding, _8$$5, last);
					ZEPHIR_SINIT_NVAR(_6$$5);
					ZVAL_LONG(&_6$$5, (length - paddingSize));
					ZEPHIR_INIT_VAR(_9$$5);
					zephir_substr(_9$$5, text, zephir_get_intval(&_6$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					if (!ZEPHIR_IS_EQUAL(_9$$5, padding)) {
						paddingSize = 0;
					}
				}
				break;
			}
			if (paddingType == 2) {
				ZEPHIR_SINIT_VAR(_10$$7);
				ZVAL_LONG(&_10$$7, (length - 1));
				ZEPHIR_SINIT_VAR(_11$$7);
				ZVAL_LONG(&_11$$7, 1);
				ZEPHIR_INIT_NVAR(last);
				zephir_substr(last, text, zephir_get_intval(&_10$$7), 1 , 0);
				ZEPHIR_CALL_FUNCTION(&_12$$7, "ord", NULL, 148, last);
				zephir_check_call_status();
				ord = zephir_get_intval(_12$$7);
				if (ord <= blockSize) {
					paddingSize = ord;
					ZEPHIR_SINIT_VAR(_13$$8);
					ZVAL_LONG(&_13$$8, paddingSize);
					ZEPHIR_CALL_FUNCTION(&_14$$8, "chr", NULL, 146, &_13$$8);
					zephir_check_call_status();
					ZEPHIR_SINIT_NVAR(_13$$8);
					ZVAL_LONG(&_13$$8, paddingSize);
					ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", NULL, 147, _14$$8, &_13$$8);
					zephir_check_call_status();
					ZEPHIR_SINIT_NVAR(_13$$8);
					ZVAL_LONG(&_13$$8, (length - paddingSize));
					ZEPHIR_INIT_VAR(_15$$8);
					zephir_substr(_15$$8, text, zephir_get_intval(&_13$$8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					if (!ZEPHIR_IS_EQUAL(_15$$8, padding)) {
						paddingSize = 0;
					}
				}
				break;
			}
			if (paddingType == 3) {
				ZEPHIR_SINIT_VAR(_16$$10);
				ZVAL_LONG(&_16$$10, (length - 1));
				ZEPHIR_SINIT_VAR(_17$$10);
				ZVAL_LONG(&_17$$10, 1);
				ZEPHIR_INIT_NVAR(last);
				zephir_substr(last, text, zephir_get_intval(&_16$$10), 1 , 0);
				ZEPHIR_CALL_FUNCTION(&_18$$10, "ord", NULL, 148, last);
				zephir_check_call_status();
				paddingSize = zephir_get_intval(_18$$10);
				break;
			}
			if (paddingType == 4) {
				i = (length - 1);
				while (1) {
					_19$$11 = i > 0;
					if (_19$$11) {
						_20$$11 = ZEPHIR_STRING_OFFSET(text, i);
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
				_22$$11 = ZEPHIR_STRING_OFFSET(text, i);
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
						_24$$15 = ZEPHIR_STRING_OFFSET(text, i);
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
						_27$$17 = ZEPHIR_STRING_OFFSET(text, i);
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
				ZEPHIR_SINIT_VAR(_30$$21);
				ZVAL_LONG(&_30$$21, 0);
				ZEPHIR_SINIT_VAR(_31$$21);
				ZVAL_LONG(&_31$$21, (length - paddingSize));
				zephir_substr(return_value, text, 0 , zephir_get_intval(&_31$$21), 0);
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
 * $encrypted = $crypt->encrypt("Ultra-secret text", "encrypt password");
 *</code>
 */
PHP_METHOD(Phalcon_Crypt, encrypt) {

	zend_bool _7, _8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *key_param = NULL, *encryptKey = NULL, *ivSize = NULL, *iv = NULL, *cipher = NULL, *mode = NULL, *blockSize = NULL, *paddingType = NULL, *padded = NULL, _0 = zval_used_for_init, *_1 = NULL, *_2, *_3 = NULL, _9, *_10 = NULL, *_4$$9, *_5$$9, *_6$$9 = NULL;
	zval *text = NULL, *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(text, text_param);
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	if (!key_param) {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	} else {
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}
	}


	if (!((zephir_function_exists_ex(SS("openssl_cipher_iv_length") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "openssl extension is required", "phalcon/crypt.zep", 280);
		return;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(key, "")) {
		ZEPHIR_OBS_VAR(encryptKey);
		zephir_read_property_this(&encryptKey, this_ptr, SL("_key"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(encryptKey, key);
	}
	if (ZEPHIR_IS_EMPTY(encryptKey)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Encryption key cannot be empty", "phalcon/crypt.zep", 290);
		return;
	}
	ZEPHIR_OBS_VAR(cipher);
	zephir_read_property_this(&cipher, this_ptr, SL("_cipher"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "-", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "strrpos", NULL, 149, cipher, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(_1) - zephir_fast_strlen_ev(cipher)));
	ZEPHIR_INIT_VAR(_2);
	zephir_substr(_2, cipher, zephir_get_intval(&_0), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_VAR(mode);
	zephir_fast_strtolower(mode, _2);
	ZEPHIR_CALL_FUNCTION(&_3, "openssl_get_cipher_methods", NULL, 150, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (!(zephir_fast_in_array(cipher, _3 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Cipher algorithm is unknown", "phalcon/crypt.zep", 297);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&ivSize, "openssl_cipher_iv_length", NULL, 151, cipher);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(ivSize, 0)) {
		ZEPHIR_CPY_WRT(blockSize, ivSize);
	} else {
		ZEPHIR_INIT_VAR(_4$$9);
		ZEPHIR_CONCAT_SV(_4$$9, "-", mode);
		ZEPHIR_INIT_VAR(_5$$9);
		ZVAL_STRING(_5$$9, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_6$$9, "str_ireplace", NULL, 152, _4$$9, _5$$9, cipher);
		zephir_check_temp_parameter(_5$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&blockSize, "openssl_cipher_iv_length", NULL, 151, _6$$9);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&iv, "openssl_random_pseudo_bytes", NULL, 153, ivSize);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(paddingType);
	zephir_read_property_this(&paddingType, this_ptr, SL("_padding"), PH_NOISY_CC);
	_7 = !ZEPHIR_IS_LONG(paddingType, 0);
	if (_7) {
		_8 = ZEPHIR_IS_STRING(mode, "cbc");
		if (!(_8)) {
			_8 = ZEPHIR_IS_STRING(mode, "ecb");
		}
		_7 = _8;
	}
	if (_7) {
		ZEPHIR_CALL_METHOD(&padded, this_ptr, "_cryptpadtext", NULL, 0, text, mode, blockSize, paddingType);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(padded, text);
	}
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, 1);
	ZEPHIR_CALL_FUNCTION(&_10, "openssl_encrypt", NULL, 154, padded, cipher, encryptKey, &_9, iv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, iv, _10);
	RETURN_MM();

}

/**
 * Decrypts an encrypted text
 *
 *<code>
 * echo $crypt->decrypt($encrypted, "decrypt password");
 *</code>
 */
PHP_METHOD(Phalcon_Crypt, decrypt) {

	zend_bool _11;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *key = NULL, *decryptKey = NULL, *ivSize = NULL, *cipher = NULL, *mode = NULL, *blockSize = NULL, *paddingType = NULL, *decrypted = NULL, _0 = zval_used_for_init, *_1 = NULL, *_2, *_3 = NULL, *_7, _8, *_9, _10, *_4$$9, *_5$$9, *_6$$9 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &key);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(text, text_param);
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}


	if (!((zephir_function_exists_ex(SS("openssl_cipher_iv_length") TSRMLS_CC) == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "openssl extension is required", "phalcon/crypt.zep", 331);
		return;
	}
	if (Z_TYPE_P(key) == IS_NULL) {
		ZEPHIR_OBS_VAR(decryptKey);
		zephir_read_property_this(&decryptKey, this_ptr, SL("_key"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(decryptKey, key);
	}
	if (ZEPHIR_IS_EMPTY(decryptKey)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Decryption key cannot be empty", "phalcon/crypt.zep", 341);
		return;
	}
	ZEPHIR_OBS_VAR(cipher);
	zephir_read_property_this(&cipher, this_ptr, SL("_cipher"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "-", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "strrpos", NULL, 149, cipher, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(_1) - zephir_fast_strlen_ev(cipher)));
	ZEPHIR_INIT_VAR(_2);
	zephir_substr(_2, cipher, zephir_get_intval(&_0), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_VAR(mode);
	zephir_fast_strtolower(mode, _2);
	ZEPHIR_CALL_FUNCTION(&_3, "openssl_get_cipher_methods", NULL, 150, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (!(zephir_fast_in_array(cipher, _3 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Cipher algorithm is unknown", "phalcon/crypt.zep", 348);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&ivSize, "openssl_cipher_iv_length", NULL, 151, cipher);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(ivSize, 0)) {
		ZEPHIR_CPY_WRT(blockSize, ivSize);
	} else {
		ZEPHIR_INIT_VAR(_4$$9);
		ZEPHIR_CONCAT_SV(_4$$9, "-", mode);
		ZEPHIR_INIT_VAR(_5$$9);
		ZVAL_STRING(_5$$9, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_6$$9, "str_ireplace", NULL, 152, _4$$9, _5$$9, cipher);
		zephir_check_temp_parameter(_5$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&blockSize, "openssl_cipher_iv_length", NULL, 151, _6$$9);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_7);
	zephir_substr(_7, text, zephir_get_intval(ivSize), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 0);
	ZEPHIR_INIT_VAR(_9);
	zephir_substr(_9, text, 0 , zephir_get_intval(ivSize), 0);
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, 1);
	ZEPHIR_CALL_FUNCTION(&decrypted, "openssl_decrypt", NULL, 155, _7, cipher, decryptKey, &_10, _9);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(paddingType);
	zephir_read_property_this(&paddingType, this_ptr, SL("_padding"), PH_NOISY_CC);
	_11 = ZEPHIR_IS_STRING(mode, "cbc");
	if (!(_11)) {
		_11 = ZEPHIR_IS_STRING(mode, "ecb");
	}
	if (_11) {
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool safe;
	zval *text_param = NULL, *key = NULL, *safe_param = NULL, *_0$$3 = NULL, *_1$$3 = NULL, _2$$3 = zval_used_for_init, _3$$3, *_4$$3 = NULL, *_5 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &text_param, &key, &safe_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
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
	if (UNEXPECTED(Z_TYPE_P(safe_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'safe' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	safe = Z_BVAL_P(safe_param);
	}


	if (safe == 1) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "encrypt", NULL, 0, text, key);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_1$$3, "base64_encode", NULL, 128, _0$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_STRING(&_2$$3, "+/", 0);
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_STRING(&_3$$3, "-_", 0);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "strtr", NULL, 27, _1$$3, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_2$$3);
		ZVAL_STRING(&_2$$3, "=", 0);
		zephir_fast_trim(return_value, _4$$3, &_2$$3, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "encrypt", NULL, 0, text, key);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 128, _5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Decrypt a text that is coded as a base64 string
 */
PHP_METHOD(Phalcon_Crypt, decryptBase64) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool safe;
	zval *text_param = NULL, *key = NULL, *safe_param = NULL, _0$$3 = zval_used_for_init, _1$$3 = zval_used_for_init, *_2$$3 = NULL, *_3$$3, *_4$$3, *_5$$3 = NULL, *_6 = NULL;
	zval *text = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &text_param, &key, &safe_param);

	if (UNEXPECTED(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(text_param) == IS_STRING)) {
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
	if (UNEXPECTED(Z_TYPE_P(safe_param) != IS_BOOL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'safe' must be a bool") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	safe = Z_BVAL_P(safe_param);
	}


	if (safe == 1) {
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "-_", 0);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_STRING(&_1$$3, "+/", 0);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "strtr", NULL, 27, text, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0$$3);
		ZVAL_STRING(&_0$$3, "===", 0);
		ZEPHIR_SINIT_NVAR(_1$$3);
		ZVAL_DOUBLE(&_1$$3, zephir_safe_mod_long_long(((zephir_fast_strlen_ev(text) + 3)), 4 TSRMLS_CC));
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_substr(_3$$3, &_0$$3, zephir_get_intval(&_1$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_CONCAT_VV(_4$$3, _2$$3, _3$$3);
		ZEPHIR_CALL_FUNCTION(&_5$$3, "base64_decode", NULL, 129, _4$$3);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "decrypt", NULL, 0, _5$$3, key);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_6, "base64_decode", NULL, 129, text);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "decrypt", NULL, 0, _6, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a list of available ciphers
 */
PHP_METHOD(Phalcon_Crypt, getAvailableCiphers) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("openssl_get_cipher_methods", NULL, 150, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	RETURN_MM();

}

