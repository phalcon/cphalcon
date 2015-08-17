
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
 * - libsodium
 * - openssl
 * - /dev/urandom
 *
 *<code>
 *	$random = new \Phalcon\Security\Random();
 *
 *	// Random binary string
 *	$bytes = $random->bytes();
 *
 *	// Random hex string
 *	echo $random->hex(10); // a29f470508d5ccb8e289
 *	echo $random->hex(10); // 533c2f08d5eee750e64a
 *	echo $random->hex(11); // f362ef96cb9ffef150c9cd
 *	echo $random->hex(12); // 95469d667475125208be45c4
 *	echo $random->hex(13); // 05475e8af4a34f8f743ab48761
 *
 *	// Random base64 string
 *	echo $random->base64(12); // XfIN81jGGuKkcE1E
 *	echo $random->base64(12); // 3rcq39QzGK9fUqh8
 *	echo $random->base64();   // DRcfbngL/iOo9hGGvy1TcQ==
 *	echo $random->base64(16); // SvdhPcIHDZFad838Bb0Swg==
 *
 *	// Random URL-safe base64 string
 *	echo $random->base64Safe();           // PcV6jGbJ6vfVw7hfKIFDGA
 *	echo $random->base64Safe();           // GD8JojhzSTrqX7Q8J6uug
 *	echo $random->base64Safe(8);          // mGyy0evy3ok
 *	echo $random->base64Safe(null, true); // DRrAgOFkS4rvRiVHFefcQ==
 *
 *	// Random UUID
 *	echo $random->uuid(); // db082997-2572-4e2c-a046-5eefe97b1235
 *	echo $random->uuid(); // da2aa0e2-b4d0-4e3c-99f5-f5ef62c57fe2
 *	echo $random->uuid(); // 75e6b628-c562-4117-bb76-61c4153455a9
 *	echo $random->uuid(); // dc446df1-0848-4d05-b501-4af3c220c13d
 *
 *	// Random number between 0 and $len
 *	echo $random->number(256); // 84
 *	echo $random->number(256); // 79
 *	echo $random->number(100); // 29
 *	echo $random->number(300); // 40
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
 * If $len is not specified, 16 is assumed. It may be larger in future.
 * The result may contain any byte: "x00" - "xFF".
 *
 *<code>
 *	$random = new \Phalcon\Security\Random();
 *
 *	$bytes = $random->bytes();
 *</code>
 *
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Security_Random, bytes) {

	zval *len_param = NULL, *handle = NULL, *ret = NULL, *_0 = NULL, _1, _2 = zval_used_for_init, _3;
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
	if ((zephir_function_exists_ex(SS("\\sodium\\randombytes_buf") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_LONG(_0, len);
		ZEPHIR_RETURN_CALL_FUNCTION("\\sodium\\randombytes_buf", NULL, 0, _0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if ((zephir_function_exists_ex(SS("openssl_random_pseudo_bytes") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_LONG(_0, len);
		ZEPHIR_RETURN_CALL_FUNCTION("openssl_random_pseudo_bytes", NULL, 400, _0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "/dev/urandom", 0);
	if ((zephir_file_exists(&_1 TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_STRING(&_2, "/dev/urandom", 0);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "rb", 0);
		ZEPHIR_CALL_FUNCTION(&handle, "fopen", NULL, 285, &_2, &_3);
		zephir_check_call_status();
		if (!ZEPHIR_IS_FALSE_IDENTICAL(handle)) {
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, 0);
			ZEPHIR_CALL_FUNCTION(NULL, "stream_set_read_buffer", NULL, 403, handle, &_2);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, len);
			ZEPHIR_CALL_FUNCTION(&ret, "fread", NULL, 388, handle, &_2);
			zephir_check_call_status();
			zephir_fclose(handle TSRMLS_CC);
			if (zephir_fast_strlen_ev(ret) != len) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "Unexpected partial read from random device", "phalcon/security/random.zep", 117);
				return;
			}
			RETURN_CCTOR(ret);
		}
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "No random device", "phalcon/security/random.zep", 124);
	return;

}

/**
 * Generates a random hex string
 *
 * If $len is not specified, 16 is assumed. It may be larger in future.
 * The length of the result string is usually greater of $len.
 *
 *<code>
 *	$random = new \Phalcon\Security\Random();
 *
 *	echo $random->hex(10); // a29f470508d5ccb8e289
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
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 404, &_2, _0);
	zephir_check_call_status();
	Z_SET_ISREF_P(_3);
	ZEPHIR_RETURN_CALL_FUNCTION("array_shift", NULL, 121, _3);
	Z_UNSET_ISREF_P(_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Generates a random base64 string
 *
 * If $len is not specified, 16 is assumed. It may be larger in future.
 * The length of the result string is usually greater of $len.
 *
 *<code>
 *	$random = new \Phalcon\Security\Random();
 *
 *	echo $random->base64(12); // 3rcq39QzGK9fUqh8
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
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 114, _0);
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
 *	$random = new \Phalcon\Security\Random();
 *
 *	echo $random->base64Safe(); // GD8JojhzSTrqX7Q8J6uug
 *</code>
 *
 * @link https://www.ietf.org/rfc/rfc3548.txt
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Security_Random, base64Safe) {

	zend_bool padding;
	zval *len_param = NULL, *padding_param = NULL, *s = NULL, *_0 = NULL, *_1 = NULL, *_2, _3;
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
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "=", 0);
		zephir_fast_trim(return_value, s, &_3, ZEPHIR_TRIM_BOTH TSRMLS_CC);
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
 *	$random = new \Phalcon\Security\Random();
 *
 *	echo $random->uuid(); // 1378c906-64bb-4f81-a8d6-4ae1bfcdec22
 *</code>
 *
 * @link https://www.ietf.org/rfc/rfc4122.txt
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Security_Random, uuid) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *ary = NULL, *_0 = NULL, *_1 = NULL, _2 = zval_used_for_init, *_3 = NULL, *_4, *_5, *_6, *_7;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 16);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "bytes", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "N1a/n1b/n1c/n1d/n1e/N1f", 0);
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 404, &_2, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&ary, "array_values", NULL, 215, _3);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, ary, 2, PH_NOISY | PH_READONLY, "phalcon/security/random.zep", 222 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, ((((int) (zephir_get_numberval(_4)) & 0x0fff)) | 0x4000));
	zephir_array_update_long(&ary, 2, &_1, PH_COPY | PH_SEPARATE, "phalcon/security/random.zep", 222);
	zephir_array_fetch_long(&_5, ary, 3, PH_NOISY | PH_READONLY, "phalcon/security/random.zep", 223 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, ((((int) (zephir_get_numberval(_5)) & 0x3fff)) | 0x8000));
	zephir_array_update_long(&ary, 3, &_6, PH_COPY | PH_SEPARATE, "phalcon/security/random.zep", 223);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "%08x-%04x-%04x-%04x-%04x%08x", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(ary);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 379, ary, _7);
	zephir_check_temp_parameter(_7);
	Z_UNSET_ISREF_P(ary);
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
 *<code>
 *	$random = new \Phalcon\Security\Random();
 *
 *	echo $random->number(16); // 8
 *</code>
 * @throws Exception If secure random number generator is not available, unexpected partial read or $len <= 0
 */
PHP_METHOD(Phalcon_Security_Random, number) {

	zephir_fcall_cache_entry *_4 = NULL, *_9 = NULL, *_14 = NULL, *_18 = NULL;
	zval *len_param = NULL, *hex = NULL, *bin = NULL, *mask = NULL, *rnd = NULL, *ret = NULL, *first = NULL, _0 = zval_used_for_init, *_1, _2, *_3, *_8 = NULL, _10 = zval_used_for_init, _11 = zval_used_for_init, _12 = zval_used_for_init, *_13 = NULL, _15 = zval_used_for_init, _16 = zval_used_for_init, *_17 = NULL;
	int len, ZEPHIR_LAST_CALL_STATUS, _5, _6, _7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &len_param);

	len = zephir_get_intval(len_param);


	if (len > 0) {
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, len);
		ZEPHIR_CALL_FUNCTION(&hex, "dechex", NULL, 405, &_0);
		zephir_check_call_status();
		if (((zephir_fast_strlen_ev(hex) & 1)) == 1) {
			ZEPHIR_INIT_VAR(_1);
			ZEPHIR_CONCAT_SV(_1, "0", hex);
			ZEPHIR_CPY_WRT(hex, _1);
		}
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, "H*", 0);
		ZEPHIR_CALL_FUNCTION(&bin, "pack", NULL, 406, &_0, hex);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_LONG(&_0, 0);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, 1);
		ZEPHIR_INIT_VAR(_3);
		zephir_substr(_3, bin, 0 , 1 , 0);
		ZEPHIR_CALL_FUNCTION(&mask, "ord", &_4, 132, _3);
		zephir_check_call_status();
		_5 = ((int) (zephir_get_numberval(mask)) | (((int) (zephir_get_numberval(mask)) >> 1)));
		ZEPHIR_INIT_NVAR(mask);
		ZVAL_LONG(mask, _5);
		_6 = ((int) (zephir_get_numberval(mask)) | (((int) (zephir_get_numberval(mask)) >> 2)));
		ZEPHIR_INIT_NVAR(mask);
		ZVAL_LONG(mask, _6);
		_7 = ((int) (zephir_get_numberval(mask)) | (((int) (zephir_get_numberval(mask)) >> 4)));
		ZEPHIR_INIT_NVAR(mask);
		ZVAL_LONG(mask, _7);
		do {
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, zephir_fast_strlen_ev(bin));
			ZEPHIR_CALL_METHOD(&rnd, this_ptr, "bytes", &_9, 0, _8);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_10);
			ZVAL_LONG(&_10, 0);
			ZEPHIR_SINIT_NVAR(_11);
			ZVAL_LONG(&_11, 1);
			ZEPHIR_INIT_NVAR(_8);
			zephir_substr(_8, rnd, 0 , 1 , 0);
			ZEPHIR_CALL_FUNCTION(&first, "ord", &_4, 132, _8);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_12);
			zephir_bitwise_and_function(&_12, first, mask TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_13, "chr", &_14, 130, &_12);
			zephir_check_call_status();
			ZEPHIR_SINIT_NVAR(_15);
			ZVAL_LONG(&_15, 0);
			ZEPHIR_SINIT_NVAR(_16);
			ZVAL_LONG(&_16, 1);
			ZEPHIR_CALL_FUNCTION(&_17, "substr_replace", &_18, 407, rnd, _13, &_15, &_16);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(rnd, _17);
		} while (ZEPHIR_LT(bin, rnd));
		ZEPHIR_SINIT_NVAR(_10);
		ZVAL_STRING(&_10, "H*", 0);
		ZEPHIR_CALL_FUNCTION(&ret, "unpack", NULL, 404, &_10, rnd);
		zephir_check_call_status();
		Z_SET_ISREF_P(ret);
		ZEPHIR_CALL_FUNCTION(&_13, "array_shift", NULL, 121, ret);
		Z_UNSET_ISREF_P(ret);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_FUNCTION("hexdec", NULL, 408, _13);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_security_exception_ce, "Require a positive integer > 0", "phalcon/security/random.zep", 269);
	return;

}

