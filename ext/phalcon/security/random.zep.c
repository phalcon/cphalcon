
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/concat.h"


/**
 * Phalcon\Security\Random
 *
 * Secure random number generator class.
 *
 * Provides secure random number generator which is suitable for generating
 * session key in HTTP cookies, etc.
 *
 * It supports following secure random number generators:
 *
 * - random_bytes (PHP 7)
 * - libsodium
 * - openssl
 * - /dev/urandom
 *
 * A `Phalcon\Security\Random` could be mainly useful for:
 *
 * - Key generation (e.g. generation of complicated keys)
 * - Creating random passwords for new user accounts
 * - Encryption systems
 *
 *<code>
 *  $random = new \Phalcon\Security\Random();
 *
 *  // Random binary string
 *  $bytes = $random->bytes();
 *
 *  // Random hex string
 *  echo $random->hex(10); // a29f470508d5ccb8e289
 *  echo $random->hex(10); // 533c2f08d5eee750e64a
 *  echo $random->hex(11); // f362ef96cb9ffef150c9cd
 *  echo $random->hex(12); // 95469d667475125208be45c4
 *  echo $random->hex(13); // 05475e8af4a34f8f743ab48761
 *
 *  // Random base64 string
 *  echo $random->base64(12); // XfIN81jGGuKkcE1E
 *  echo $random->base64(12); // 3rcq39QzGK9fUqh8
 *  echo $random->base64();   // DRcfbngL/iOo9hGGvy1TcQ==
 *  echo $random->base64(16); // SvdhPcIHDZFad838Bb0Swg==
 *
 *  // Random URL-safe base64 string
 *  echo $random->base64Safe();           // PcV6jGbJ6vfVw7hfKIFDGA
 *  echo $random->base64Safe();           // GD8JojhzSTrqX7Q8J6uug
 *  echo $random->base64Safe(8);          // mGyy0evy3ok
 *  echo $random->base64Safe(null, true); // DRrAgOFkS4rvRiVHFefcQ==
 *
 *  // Random UUID
 *  echo $random->uuid(); // db082997-2572-4e2c-a046-5eefe97b1235
 *  echo $random->uuid(); // da2aa0e2-b4d0-4e3c-99f5-f5ef62c57fe2
 *  echo $random->uuid(); // 75e6b628-c562-4117-bb76-61c4153455a9
 *  echo $random->uuid(); // dc446df1-0848-4d05-b501-4af3c220c13d
 *
 *  // Random number between 0 and $len
 *  echo $random->number(256); // 84
 *  echo $random->number(256); // 79
 *  echo $random->number(100); // 29
 *  echo $random->number(300); // 40
 *
 *  // Random base58 string
 *  echo $random->base58();   // 4kUgL2pdQMSCQtjE
 *  echo $random->base58();   // Umjxqf7ZPwh765yR
 *  echo $random->base58(24); // qoXcgmw4A9dys26HaNEdCRj9
 *  echo $random->base58(7);  // 774SJD3vgP
 *</code>
 *
 * This class partially borrows SecureRandom library from Ruby
 *
 * @link http://ruby-doc.org/stdlib-2.2.2/libdoc/securerandom/rdoc/SecureRandom.html
 */
ZEPHIR_INIT_CLASS(Phalcon_Security_Random) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Security, Random, phalcon, security_random, phalcon_security_random_method_entry, 0);

	return SUCCESS;

}

/**
 * Generates a random binary string
 *
 * The `Random::bytes` method returns a string and accepts as input an int
 * representing the length in bytes to be returned.
 *
 * If $len is not specified, 16 is assumed. It may be larger in future.
 * The result may contain any byte: "x00" - "xFF".
 *
 *<code>
 *  $random = new \Phalcon\Security\Random();
 *
 *  $bytes = $random->bytes();
 *  var_dump(bin2hex($bytes));
 *  // possible output: string(32) "00f6c04b144b41fad6a59111c126e1ee"
 *</code>
 *
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Security_Random, bytes) {

	zval *len_param = NULL, *handle = NULL, *ret = NULL, _3, _0$$4, *_1$$5, *_2$$6, _4$$7, _5$$7, _6$$8 = zval_used_for_init;
	int len, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &len_param);

	if (!len_param) {
		len = 16;
	} else {
		len = zephir_get_intval(len_param);
	}


	if (len <= 0) {
		len = 16;
	}
	if ((zephir_function_exists_ex(SS("random_bytes") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_SINIT_VAR(_0$$4);
		ZVAL_LONG(&_0$$4, len);
		ZEPHIR_RETURN_CALL_FUNCTION("random_bytes", NULL, 417, &_0$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(SS("\\sodium\\randombytes_buf") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(_1$$5);
		ZVAL_LONG(_1$$5, len);
		ZEPHIR_RETURN_CALL_FUNCTION("\\sodium\\randombytes_buf", NULL, 0, _1$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(SS("openssl_random_pseudo_bytes") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(_2$$6);
		ZVAL_LONG(_2$$6, len);
		ZEPHIR_RETURN_CALL_FUNCTION("openssl_random_pseudo_bytes", NULL, 143, _2$$6);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "/dev/urandom", 0);
	if ((zephir_file_exists(&_3 TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_SINIT_VAR(_4$$7);
		ZVAL_STRING(&_4$$7, "/dev/urandom", 0);
		ZEPHIR_SINIT_VAR(_5$$7);
		ZVAL_STRING(&_5$$7, "rb", 0);
		ZEPHIR_CALL_FUNCTION(&handle, "fopen", NULL, 290, &_4$$7, &_5$$7);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(handle)) {
			ZEPHIR_SINIT_VAR(_6$$8);
			ZVAL_LONG(&_6$$8, 0);
			ZEPHIR_CALL_FUNCTION(NULL, "stream_set_read_buffer", NULL, 418, handle, &_6$$8);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_6$$8);
			ZVAL_LONG(&_6$$8, len);
			ZEPHIR_CALL_FUNCTION(&ret, "fread", NULL, 419, handle, &_6$$8);
			zephir_check_call_status();
			zephir_fclose(handle TSRMLS_CC);
			if (zephir_fast_strlen_ev(ret) != len) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "Unexpected partial read from random device", "phalcon/security/random.zep", 140);
				return;
			}
			RETURN_CCTOR(ret);
		}
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "No random device", "phalcon/security/random.zep", 147);
	return;

}

/**
 * Generates a random hex string
 *
 * If $len is not specified, 16 is assumed. It may be larger in future.
 * The length of the result string is usually greater of $len.
 *
 *<code>
 *  $random = new \Phalcon\Security\Random();
 *
 *  echo $random->hex(10); // a29f470508d5ccb8e289
 *</code>
 *
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Security_Random, hex) {

	zval *len_param = NULL, *_0 = NULL, *_1, _2, *_3 = NULL;
	int len, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &len_param);

	if (!len_param) {
		len = 0;
	} else {
		len = zephir_get_intval(len_param);
	}


	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, len);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "bytes", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "H*", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 420, &_2, _0);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(_3);
	ZEPHIR_RETURN_CALL_FUNCTION("array_shift", NULL, 128, _3);
	ZEPHIR_UNREF(_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generates a random base58 string
 *
 * If $len is not specified, 16 is assumed. It may be larger in future.
 * The result may contain alphanumeric characters except 0, O, I and l.
 *
 * It is similar to Base64 but has been modified to avoid both non-alphanumeric
 * characters and letters which might look ambiguous when printed.
 *
 *<code>
 *  $random = new \Phalcon\Security\Random();
 *
 *  echo $random->base58(); // 4kUgL2pdQMSCQtjE
 *</code>
 *
 * @link https://en.wikipedia.org/wiki/Base58
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Security_Random, base58) {

	unsigned char _8$$3;
	double _5$$3;
	HashTable *_3;
	HashPosition _2;
	zval *byteString, *alphabet;
	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *n = NULL, *bytes = NULL, *idx = NULL, *_0 = NULL, _1, **_4, *_6$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &n);

	if (!n) {
		n = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(byteString);
	ZVAL_EMPTY_STRING(byteString);
	ZEPHIR_INIT_VAR(alphabet);
	ZVAL_STRING(alphabet, "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz", 1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "bytes", NULL, 0, n);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "C*", 0);
	ZEPHIR_CALL_FUNCTION(&bytes, "unpack", NULL, 420, &_1, _0);
	zephir_check_call_status();
	zephir_is_iterable(bytes, &_3, &_2, 0, 0, "phalcon/security/random.zep", 205);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(idx, _4);
		_5$$3 = zephir_safe_mod_zval_long(idx, 64 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(idx);
		ZVAL_DOUBLE(idx, _5$$3);
		if (ZEPHIR_GE_LONG(idx, 58)) {
			ZEPHIR_INIT_NVAR(_6$$4);
			ZVAL_LONG(_6$$4, 57);
			ZEPHIR_CALL_METHOD(&idx, this_ptr, "number", &_7, 0, _6$$4);
			zephir_check_call_status();
		}
		_8$$3 = ZEPHIR_STRING_OFFSET(alphabet, zephir_get_intval(idx));
		zephir_concat_self_char(&byteString, _8$$3 TSRMLS_CC);
	}
	RETURN_CTOR(byteString);

}

/**
 * Generates a random base64 string
 *
 * If $len is not specified, 16 is assumed. It may be larger in future.
 * The length of the result string is usually greater of $len.
 * Size formula: 4 *( $len / 3) and this need to be rounded up to a multiple of 4.
 *
 *<code>
 *  $random = new \Phalcon\Security\Random();
 *
 *  echo $random->base64(12); // 3rcq39QzGK9fUqh8
 *</code>
 *
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Security_Random, base64) {

	zval *len_param = NULL, *_0 = NULL, *_1;
	int len, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &len_param);

	if (!len_param) {
		len = 0;
	} else {
		len = zephir_get_intval(len_param);
	}


	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, len);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "bytes", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 121, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generates a random URL-safe base64 string
 *
 * If $len is not specified, 16 is assumed. It may be larger in future.
 * The length of the result string is usually greater of $len.
 *
 * By default, padding is not generated because "=" may be used as a URL delimiter.
 * The result may contain A-Z, a-z, 0-9, "-" and "_". "=" is also used if $padding is true.
 * See RFC 3548 for the definition of URL-safe base64.
 *
 *<code>
 *  $random = new \Phalcon\Security\Random();
 *
 *  echo $random->base64Safe(); // GD8JojhzSTrqX7Q8J6uug
 *</code>
 *
 * @link https://www.ietf.org/rfc/rfc3548.txt
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Security_Random, base64Safe) {

	zend_bool padding;
	zval *len_param = NULL, *padding_param = NULL, *s = NULL, *_0 = NULL, *_1 = NULL, *_2, _3$$3;
	int len, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &len_param, &padding_param);

	if (!len_param) {
		len = 0;
	} else {
		len = zephir_get_intval(len_param);
	}
	if (!padding_param) {
		padding = 0;
	} else {
		padding = zephir_get_boolval(padding_param);
	}


	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, len);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "base64", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "#[^a-z0-9_=-]+#i", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&s, "preg_replace", NULL, 29, _1, _2, _0);
	zephir_check_temp_parameter(_1);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!(padding)) {
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_STRING(&_3$$3, "=", 0);
		zephir_fast_trim(return_value, s, &_3$$3, ZEPHIR_TRIM_BOTH TSRMLS_CC);
		RETURN_MM();
	}
	RETURN_CCTOR(s);

}

/**
 * Generates a v4 random UUID (Universally Unique IDentifier)
 *
 * The version 4 UUID is purely random (except the version). It doesn't contain meaningful
 * information such as MAC address, time, etc. See RFC 4122 for details of UUID.
 *
 * This algorithm sets the version number (4 bits) as well as two reserved bits.
 * All other bits (the remaining 122 bits) are set using a random or pseudorandom data source.
 * Version 4 UUIDs have the form xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx where x is any hexadecimal
 * digit and y is one of 8, 9, A, or B (e.g., f47ac10b-58cc-4372-a567-0e02b2c3d479).
 *
 *<code>
 *  $random = new \Phalcon\Security\Random();
 *
 *  echo $random->uuid(); // 1378c906-64bb-4f81-a8d6-4ae1bfcdec22
 *</code>
 *
 * @link https://www.ietf.org/rfc/rfc4122.txt
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Security_Random, uuid) {

	zval *ary = NULL, *_0 = NULL, *_1 = NULL, _2 = zval_used_for_init, *_3 = NULL, *_4, *_5, *_6, *_7;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 16);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "bytes", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "N1a/n1b/n1c/n1d/n1e/N1f", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 420, &_2, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&ary, "array_values", NULL, 219, _3);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, ary, 2, PH_NOISY | PH_READONLY, "phalcon/security/random.zep", 285 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, ((((int) (zephir_get_numberval(_4)) & 0x0fff)) | 0x4000));
	zephir_array_update_long(&ary, 2, &_1, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_array_fetch_long(&_5, ary, 3, PH_NOISY | PH_READONLY, "phalcon/security/random.zep", 286 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, ((((int) (zephir_get_numberval(_5)) & 0x3fff)) | 0x8000));
	zephir_array_update_long(&ary, 3, &_6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "%08x-%04x-%04x-%04x-%04x%08x", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_MAKE_REF(ary);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 393, ary, _7);
	zephir_check_temp_parameter(_7);
	ZEPHIR_UNREF(ary);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_STRING(&_2, "sprintf", 0);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_2, ary);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generates a random number between 0 and $len
 *
 * Returns an integer: 0 <= result <= $len.
 *
 *<code>
 *  $random = new \Phalcon\Security\Random();
 *
 *  echo $random->number(16); // 8
 *</code>
 * @throws Exception If secure random number generator is not available, unexpected partial read or $len <= 0
 */
PHP_METHOD(Phalcon_Security_Random, number) {

	unsigned char _7;
	zval *bin;
	zephir_fcall_cache_entry *_8 = NULL, *_13 = NULL, *_18 = NULL, *_22 = NULL;
	zval *len_param = NULL, *hex = NULL, *mask = NULL, *rnd = NULL, *ret = NULL, _4 = zval_used_for_init, *_6 = NULL, *_23 = NULL, _0$$4, _1$$4, *_2$$5, *_3$$5 = NULL, *_5$$6, *_12$$7 = NULL, _14$$7 = zval_used_for_init, _15$$7 = zval_used_for_init, *_16$$7 = NULL, _17$$7 = zval_used_for_init, _19$$7 = zval_used_for_init, _20$$7 = zval_used_for_init, *_21$$7 = NULL;
	int len, ZEPHIR_LAST_CALL_STATUS, _9, _10, _11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &len_param);

	len = zephir_get_intval(len_param);


	ZEPHIR_INIT_VAR(bin);
	ZVAL_EMPTY_STRING(bin);
	if (len <= 0) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "Require a positive integer > 0", "phalcon/security/random.zep", 311);
		return;
	}
	if ((zephir_function_exists_ex(SS("random_int") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_SINIT_VAR(_0$$4);
		ZVAL_LONG(&_0$$4, 0);
		ZEPHIR_SINIT_VAR(_1$$4);
		ZVAL_LONG(&_1$$4, len);
		ZEPHIR_RETURN_CALL_FUNCTION("random_int", NULL, 421, &_0$$4, &_1$$4);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(SS("\\sodium\\randombytes_uniform") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(_2$$5);
		ZVAL_LONG(_2$$5, len);
		ZEPHIR_CALL_FUNCTION(&_3$$5, "\\sodium\\randombytes_uniform", NULL, 0, _2$$5);
		zephir_check_call_status();
		RETURN_MM_LONG((zephir_get_numberval(_3$$5) + 1));
	}
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, len);
	ZEPHIR_CALL_FUNCTION(&hex, "dechex", NULL, 422, &_4);
	zephir_check_call_status();
	if (((zephir_fast_strlen_ev(hex) & 1)) == 1) {
		ZEPHIR_INIT_VAR(_5$$6);
		ZEPHIR_CONCAT_SV(_5$$6, "0", hex);
		ZEPHIR_CPY_WRT(hex, _5$$6);
	}
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_STRING(&_4, "H*", 0);
	ZEPHIR_CALL_FUNCTION(&_6, "pack", NULL, 423, &_4, hex);
	zephir_check_call_status();
	zephir_concat_self(&bin, _6 TSRMLS_CC);
	_7 = ZEPHIR_STRING_OFFSET(bin, 0);
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_LONG(&_4, _7);
	ZEPHIR_CALL_FUNCTION(&mask, "ord", &_8, 138, &_4);
	zephir_check_call_status();
	_9 = ((int) (zephir_get_numberval(mask)) | (((int) (zephir_get_numberval(mask)) >> 1)));
	ZEPHIR_INIT_NVAR(mask);
	ZVAL_LONG(mask, _9);
	_10 = ((int) (zephir_get_numberval(mask)) | (((int) (zephir_get_numberval(mask)) >> 2)));
	ZEPHIR_INIT_NVAR(mask);
	ZVAL_LONG(mask, _10);
	_11 = ((int) (zephir_get_numberval(mask)) | (((int) (zephir_get_numberval(mask)) >> 4)));
	ZEPHIR_INIT_NVAR(mask);
	ZVAL_LONG(mask, _11);
	do {
		ZEPHIR_INIT_NVAR(_12$$7);
		ZVAL_LONG(_12$$7, zephir_fast_strlen_ev(bin));
		ZEPHIR_CALL_METHOD(&rnd, this_ptr, "bytes", &_13, 0, _12$$7);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_14$$7);
		ZVAL_LONG(&_14$$7, 0);
		ZEPHIR_SINIT_NVAR(_15$$7);
		ZVAL_LONG(&_15$$7, 1);
		ZEPHIR_INIT_NVAR(_12$$7);
		zephir_substr(_12$$7, rnd, 0 , 1 , 0);
		ZEPHIR_CALL_FUNCTION(&_16$$7, "ord", &_8, 138, _12$$7);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_17$$7);
		zephir_bitwise_and_function(&_17$$7, _16$$7, mask TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_16$$7, "chr", &_18, 136, &_17$$7);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_19$$7);
		ZVAL_LONG(&_19$$7, 0);
		ZEPHIR_SINIT_NVAR(_20$$7);
		ZVAL_LONG(&_20$$7, 1);
		ZEPHIR_CALL_FUNCTION(&_21$$7, "substr_replace", &_22, 424, rnd, _16$$7, &_19$$7, &_20$$7);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(rnd, _21$$7);
	} while (ZEPHIR_LT(bin, rnd));
	ZEPHIR_SINIT_NVAR(_4);
	ZVAL_STRING(&_4, "H*", 0);
	ZEPHIR_CALL_FUNCTION(&ret, "unpack", NULL, 420, &_4, rnd);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(ret);
	ZEPHIR_CALL_FUNCTION(&_23, "array_shift", NULL, 128, ret);
	ZEPHIR_UNREF(ret);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("hexdec", NULL, 425, _23);
	zephir_check_call_status();
	RETURN_MM();

}

