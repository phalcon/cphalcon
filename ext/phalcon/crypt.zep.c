
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
	int scheme;

	zephir_fetch_params(0, 1, 0, &scheme_param);

	if (unlikely(Z_TYPE_P(scheme_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'scheme' must be a int") TSRMLS_CC);
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
 * Pads texts before encryption
 *
 * @see http://www.di-mgt.com.au/cryptopad.html
 */
PHP_METHOD(Phalcon_Crypt, _cryptPadText) {

	zend_bool _0, _9$$7;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_13 = NULL;
	int blockSize, paddingType, ZEPHIR_LAST_CALL_STATUS, i = 0, paddingSize, _10$$7, _11$$7;
	zval *text_param = NULL, *mode_param = NULL, *blockSize_param = NULL, *paddingType_param = NULL, *padding = NULL, _25, _26, *_27, _1$$5 = zval_used_for_init, *_2$$5 = NULL, *_4$$5 = NULL, *_6$$5 = NULL, _7$$6 = zval_used_for_init, *_8$$6 = NULL, _15$$7, *_16$$7 = NULL, *_12$$8 = NULL, *_14$$8 = NULL, _17$$9 = zval_used_for_init, *_18$$9 = NULL, *_19$$9 = NULL, *_20$$9 = NULL, _21$$10 = zval_used_for_init, *_22$$10 = NULL, _23$$11, _24$$11;
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'blockSize' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	blockSize = Z_LVAL_P(blockSize_param);
	if (unlikely(Z_TYPE_P(paddingType_param) != IS_LONG)) {
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
				ZEPHIR_CALL_FUNCTION(&_2$$5, "chr", &_3, 139, &_1$$5);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_1$$5);
				ZVAL_LONG(&_1$$5, (paddingSize - 1));
				ZEPHIR_CALL_FUNCTION(&_4$$5, "str_repeat", &_5, 140, _2$$5, &_1$$5);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_1$$5);
				ZVAL_LONG(&_1$$5, paddingSize);
				ZEPHIR_CALL_FUNCTION(&_6$$5, "chr", &_3, 139, &_1$$5);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(padding);
				ZEPHIR_CONCAT_VV(padding, _4$$5, _6$$5);
				break;
			}
			if (paddingType == 2) {
				ZEPHIR_SINIT_VAR(_7$$6);
				ZVAL_LONG(&_7$$6, paddingSize);
				ZEPHIR_CALL_FUNCTION(&_8$$6, "chr", &_3, 139, &_7$$6);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_7$$6);
				ZVAL_LONG(&_7$$6, paddingSize);
				ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", &_5, 140, _8$$6, &_7$$6);
				zephir_check_call_status();
				break;
			}
			if (paddingType == 3) {
				ZEPHIR_INIT_NVAR(padding);
				ZVAL_STRING(padding, "", 1);
				_11$$7 = (paddingSize - 2);
				_10$$7 = 0;
				_9$$7 = 0;
				if (_10$$7 <= _11$$7) {
					while (1) {
						if (_9$$7) {
							_10$$7++;
							if (!(_10$$7 <= _11$$7)) {
								break;
							}
						} else {
							_9$$7 = 1;
						}
						i = _10$$7;
						ZEPHIR_CALL_FUNCTION(&_12$$8, "rand", &_13, 118);
						zephir_check_call_status();
						ZEPHIR_CALL_FUNCTION(&_14$$8, "chr", &_3, 139, _12$$8);
						zephir_check_call_status();
						zephir_concat_self(&padding, _14$$8 TSRMLS_CC);
					}
				}
				ZEPHIR_SINIT_VAR(_15$$7);
				ZVAL_LONG(&_15$$7, paddingSize);
				ZEPHIR_CALL_FUNCTION(&_16$$7, "chr", &_3, 139, &_15$$7);
				zephir_check_call_status();
				zephir_concat_self(&padding, _16$$7 TSRMLS_CC);
				break;
			}
			if (paddingType == 4) {
				ZEPHIR_SINIT_VAR(_17$$9);
				ZVAL_LONG(&_17$$9, 0x80);
				ZEPHIR_CALL_FUNCTION(&_18$$9, "chr", &_3, 139, &_17$$9);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_17$$9);
				ZVAL_LONG(&_17$$9, 0);
				ZEPHIR_CALL_FUNCTION(&_19$$9, "chr", &_3, 139, &_17$$9);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_17$$9);
				ZVAL_LONG(&_17$$9, (paddingSize - 1));
				ZEPHIR_CALL_FUNCTION(&_20$$9, "str_repeat", &_5, 140, _19$$9, &_17$$9);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(padding);
				ZEPHIR_CONCAT_VV(padding, _18$$9, _20$$9);
				break;
			}
			if (paddingType == 5) {
				ZEPHIR_SINIT_VAR(_21$$10);
				ZVAL_LONG(&_21$$10, 0);
				ZEPHIR_CALL_FUNCTION(&_22$$10, "chr", &_3, 139, &_21$$10);
				zephir_check_call_status();
				ZEPHIR_SINIT_NVAR(_21$$10);
				ZVAL_LONG(&_21$$10, paddingSize);
				ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", &_5, 140, _22$$10, &_21$$10);
				zephir_check_call_status();
				break;
			}
			if (paddingType == 6) {
				ZEPHIR_SINIT_VAR(_23$$11);
				ZVAL_STRING(&_23$$11, " ", 0);
				ZEPHIR_SINIT_VAR(_24$$11);
				ZVAL_LONG(&_24$$11, paddingSize);
				ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", &_5, 140, &_23$$11, &_24$$11);
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
	ZEPHIR_SINIT_VAR(_25);
	ZVAL_LONG(&_25, 0);
	ZEPHIR_SINIT_VAR(_26);
	ZVAL_LONG(&_26, paddingSize);
	ZEPHIR_INIT_VAR(_27);
	zephir_substr(_27, padding, 0 , zephir_get_intval(&_26), 0);
	ZEPHIR_CONCAT_VV(return_value, text, _27);
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

	unsigned char _23$$11, _25$$11, _27$$15, _30$$17;
	zend_bool _0, _1, _2, _22$$11, _24$$11, _26$$15, _28$$15, _29$$17, _31$$17, _32$$3;
	long length = 0;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL, *_11 = NULL;
	int blockSize, paddingType, ZEPHIR_LAST_CALL_STATUS, i = 0, paddingSize, ord = 0;
	zval *text_param = NULL, *mode_param = NULL, *blockSize_param = NULL, *paddingType_param = NULL, *padding = NULL, *last = NULL, _3$$4, _4$$4, *_5$$4 = NULL, _7$$5 = zval_used_for_init, *_8$$5 = NULL, *_10$$5 = NULL, *_12$$5, _13$$7, _14$$7, *_15$$7 = NULL, _16$$8 = zval_used_for_init, *_17$$8 = NULL, *_18$$8, _19$$10, _20$$10, *_21$$10 = NULL, _33$$21, _34$$21;
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'blockSize' must be a int") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	blockSize = Z_LVAL_P(blockSize_param);
	if (unlikely(Z_TYPE_P(paddingType_param) != IS_LONG)) {
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
				ZEPHIR_CALL_FUNCTION(&_5$$4, "ord", &_6, 141, last);
				zephir_check_call_status();
				ord = zephir_get_intval(_5$$4);
				if (ord <= blockSize) {
					paddingSize = ord;
					ZEPHIR_SINIT_VAR(_7$$5);
					ZVAL_LONG(&_7$$5, 0);
					ZEPHIR_CALL_FUNCTION(&_8$$5, "chr", &_9, 139, &_7$$5);
					zephir_check_call_status();
					ZEPHIR_SINIT_NVAR(_7$$5);
					ZVAL_LONG(&_7$$5, (paddingSize - 1));
					ZEPHIR_CALL_FUNCTION(&_10$$5, "str_repeat", &_11, 140, _8$$5, &_7$$5);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(padding);
					ZEPHIR_CONCAT_VV(padding, _10$$5, last);
					ZEPHIR_SINIT_NVAR(_7$$5);
					ZVAL_LONG(&_7$$5, (length - paddingSize));
					ZEPHIR_INIT_VAR(_12$$5);
					zephir_substr(_12$$5, text, zephir_get_intval(&_7$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					if (!ZEPHIR_IS_EQUAL(_12$$5, padding)) {
						paddingSize = 0;
					}
				}
				break;
			}
			if (paddingType == 2) {
				ZEPHIR_SINIT_VAR(_13$$7);
				ZVAL_LONG(&_13$$7, (length - 1));
				ZEPHIR_SINIT_VAR(_14$$7);
				ZVAL_LONG(&_14$$7, 1);
				ZEPHIR_INIT_NVAR(last);
				zephir_substr(last, text, zephir_get_intval(&_13$$7), 1 , 0);
				ZEPHIR_CALL_FUNCTION(&_15$$7, "ord", &_6, 141, last);
				zephir_check_call_status();
				ord = zephir_get_intval(_15$$7);
				if (ord <= blockSize) {
					paddingSize = ord;
					ZEPHIR_SINIT_VAR(_16$$8);
					ZVAL_LONG(&_16$$8, paddingSize);
					ZEPHIR_CALL_FUNCTION(&_17$$8, "chr", &_9, 139, &_16$$8);
					zephir_check_call_status();
					ZEPHIR_SINIT_NVAR(_16$$8);
					ZVAL_LONG(&_16$$8, paddingSize);
					ZEPHIR_CALL_FUNCTION(&padding, "str_repeat", &_11, 140, _17$$8, &_16$$8);
					zephir_check_call_status();
					ZEPHIR_SINIT_NVAR(_16$$8);
					ZVAL_LONG(&_16$$8, (length - paddingSize));
					ZEPHIR_INIT_VAR(_18$$8);
					zephir_substr(_18$$8, text, zephir_get_intval(&_16$$8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					if (!ZEPHIR_IS_EQUAL(_18$$8, padding)) {
						paddingSize = 0;
					}
				}
				break;
			}
			if (paddingType == 3) {
				ZEPHIR_SINIT_VAR(_19$$10);
				ZVAL_LONG(&_19$$10, (length - 1));
				ZEPHIR_SINIT_VAR(_20$$10);
				ZVAL_LONG(&_20$$10, 1);
				ZEPHIR_INIT_NVAR(last);
				zephir_substr(last, text, zephir_get_intval(&_19$$10), 1 , 0);
				ZEPHIR_CALL_FUNCTION(&_21$$10, "ord", &_6, 141, last);
				zephir_check_call_status();
				paddingSize = zephir_get_intval(_21$$10);
				break;
			}
			if (paddingType == 4) {
				i = (length - 1);
				while (1) {
					_22$$11 = i > 0;
					if (_22$$11) {
						_23$$11 = ZEPHIR_STRING_OFFSET(text, i);
						_22$$11 = _23$$11 == 0x00;
					}
					_24$$11 = _22$$11;
					if (_24$$11) {
						_24$$11 = paddingSize < blockSize;
					}
					if (!(_24$$11)) {
						break;
					}
					paddingSize++;
					i--;
				}
				_25$$11 = ZEPHIR_STRING_OFFSET(text, i);
				if (_25$$11 == 0x80) {
					paddingSize++;
				} else {
					paddingSize = 0;
				}
				break;
			}
			if (paddingType == 5) {
				i = (length - 1);
				while (1) {
					_26$$15 = i >= 0;
					if (_26$$15) {
						_27$$15 = ZEPHIR_STRING_OFFSET(text, i);
						_26$$15 = _27$$15 == 0x00;
					}
					_28$$15 = _26$$15;
					if (_28$$15) {
						_28$$15 = paddingSize <= blockSize;
					}
					if (!(_28$$15)) {
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
					_29$$17 = i >= 0;
					if (_29$$17) {
						_30$$17 = ZEPHIR_STRING_OFFSET(text, i);
						_29$$17 = _30$$17 == 0x20;
					}
					_31$$17 = _29$$17;
					if (_31$$17) {
						_31$$17 = paddingSize <= blockSize;
					}
					if (!(_31$$17)) {
						break;
					}
					paddingSize++;
					i--;
				}
				break;
			}
			break;
		} while(0);

		_32$$3 = (paddingSize) ? 1 : 0;
		if (_32$$3) {
			_32$$3 = paddingSize <= blockSize;
		}
		if (_32$$3) {
			if (paddingSize < length) {
				ZEPHIR_SINIT_VAR(_33$$21);
				ZVAL_LONG(&_33$$21, 0);
				ZEPHIR_SINIT_VAR(_34$$21);
				ZVAL_LONG(&_34$$21, (length - paddingSize));
				zephir_substr(return_value, text, 0 , zephir_get_intval(&_34$$21), 0);
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

	zend_bool _8, _9;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *key_param = NULL, *encryptKey = NULL, *ivSize = NULL, *iv = NULL, *cipher = NULL, *mode = NULL, *blockSize = NULL, *paddingType = NULL, *padded = NULL, _0 = zval_used_for_init, *_1 = NULL, *_2, *_3 = NULL, _10, *_11 = NULL, *_5$$9, *_6$$9, *_7$$9 = NULL;
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
	ZEPHIR_CALL_FUNCTION(&_1, "strrpos", NULL, 142, cipher, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(_1) - zephir_fast_strlen_ev(cipher)));
	ZEPHIR_INIT_VAR(_2);
	zephir_substr(_2, cipher, zephir_get_intval(&_0), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_VAR(mode);
	zephir_fast_strtolower(mode, _2);
	ZEPHIR_CALL_FUNCTION(&_3, "openssl_get_cipher_methods", NULL, 143);
	zephir_check_call_status();
	if (!(zephir_fast_in_array(cipher, _3 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Cipher algorithm is unknown", "phalcon/crypt.zep", 297);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&ivSize, "openssl_cipher_iv_length", &_4, 144, cipher);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(ivSize, 0)) {
		ZEPHIR_CPY_WRT(blockSize, ivSize);
	} else {
		ZEPHIR_INIT_VAR(_5$$9);
		ZEPHIR_CONCAT_SV(_5$$9, "-", mode);
		ZEPHIR_INIT_VAR(_6$$9);
		ZVAL_STRING(_6$$9, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_7$$9, "str_ireplace", NULL, 145, _5$$9, _6$$9, cipher);
		zephir_check_temp_parameter(_6$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&blockSize, "openssl_cipher_iv_length", &_4, 144, _7$$9);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&iv, "openssl_random_pseudo_bytes", NULL, 146, ivSize);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(paddingType);
	zephir_read_property_this(&paddingType, this_ptr, SL("_padding"), PH_NOISY_CC);
	_8 = !ZEPHIR_IS_LONG(paddingType, 0);
	if (_8) {
		_9 = ZEPHIR_IS_STRING(mode, "cbc");
		if (!(_9)) {
			_9 = ZEPHIR_IS_STRING(mode, "ecb");
		}
		_8 = _9;
	}
	if (_8) {
		ZEPHIR_CALL_METHOD(&padded, this_ptr, "_cryptpadtext", NULL, 0, text, mode, blockSize, paddingType);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(padded, text);
	}
	ZEPHIR_SINIT_VAR(_10);
	ZVAL_LONG(&_10, 1);
	ZEPHIR_CALL_FUNCTION(&_11, "openssl_encrypt", NULL, 147, padded, cipher, encryptKey, &_10, iv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, iv, _11);
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

	zend_bool _12;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *text_param = NULL, *key = NULL, *decryptKey = NULL, *ivSize = NULL, *cipher = NULL, *mode = NULL, *blockSize = NULL, *paddingType = NULL, *decrypted = NULL, _0 = zval_used_for_init, *_1 = NULL, *_2, *_3 = NULL, *_8, _9, *_10, _11, *_5$$9, *_6$$9, *_7$$9 = NULL;
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
	ZEPHIR_CALL_FUNCTION(&_1, "strrpos", NULL, 142, cipher, &_0);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, (zephir_get_numberval(_1) - zephir_fast_strlen_ev(cipher)));
	ZEPHIR_INIT_VAR(_2);
	zephir_substr(_2, cipher, zephir_get_intval(&_0), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_VAR(mode);
	zephir_fast_strtolower(mode, _2);
	ZEPHIR_CALL_FUNCTION(&_3, "openssl_get_cipher_methods", NULL, 143);
	zephir_check_call_status();
	if (!(zephir_fast_in_array(cipher, _3 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_crypt_exception_ce, "Cipher algorithm is unknown", "phalcon/crypt.zep", 348);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&ivSize, "openssl_cipher_iv_length", &_4, 144, cipher);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(ivSize, 0)) {
		ZEPHIR_CPY_WRT(blockSize, ivSize);
	} else {
		ZEPHIR_INIT_VAR(_5$$9);
		ZEPHIR_CONCAT_SV(_5$$9, "-", mode);
		ZEPHIR_INIT_VAR(_6$$9);
		ZVAL_STRING(_6$$9, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_7$$9, "str_ireplace", NULL, 145, _5$$9, _6$$9, cipher);
		zephir_check_temp_parameter(_6$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&blockSize, "openssl_cipher_iv_length", &_4, 144, _7$$9);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_8);
	zephir_substr(_8, text, zephir_get_intval(ivSize), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, 0);
	ZEPHIR_INIT_VAR(_10);
	zephir_substr(_10, text, 0 , zephir_get_intval(ivSize), 0);
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, 1);
	ZEPHIR_CALL_FUNCTION(&decrypted, "openssl_decrypt", NULL, 148, _8, cipher, decryptKey, &_11, _10);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(paddingType);
	zephir_read_property_this(&paddingType, this_ptr, SL("_padding"), PH_NOISY_CC);
	_12 = ZEPHIR_IS_STRING(mode, "cbc");
	if (!(_12)) {
		_12 = ZEPHIR_IS_STRING(mode, "ecb");
	}
	if (_12) {
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
	zval *text_param = NULL, *key = NULL, *safe_param = NULL, *_0$$3 = NULL, *_2$$3 = NULL, _4$$3, _5$$3, *_6 = NULL;
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
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "encrypt", &_1, 0, text, key);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_2$$3, "base64_encode", &_3, 123, _0$$3);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_4$$3);
		ZVAL_STRING(&_4$$3, "+/", 0);
		ZEPHIR_SINIT_VAR(_5$$3);
		ZVAL_STRING(&_5$$3, "-_", 0);
		ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 26, _2$$3, &_4$$3, &_5$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "encrypt", &_1, 0, text, key);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", &_3, 123, _6);
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
	zval *text_param = NULL, *key = NULL, *safe_param = NULL, _0$$3, _1$$3, *_2$$3 = NULL, *_3$$3 = NULL, *_6 = NULL;
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
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_STRING(&_0$$3, "-_", 0);
		ZEPHIR_SINIT_VAR(_1$$3);
		ZVAL_STRING(&_1$$3, "+/", 0);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "strtr", NULL, 26, text, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_3$$3, "base64_decode", &_4, 124, _2$$3);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "decrypt", &_5, 0, _3$$3, key);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_6, "base64_decode", &_4, 124, text);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "decrypt", &_5, 0, _6, key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns a list of available ciphers
 */
PHP_METHOD(Phalcon_Crypt, getAvailableCiphers) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("openssl_get_cipher_methods", NULL, 143);
	zephir_check_call_status();
	RETURN_MM();

}

