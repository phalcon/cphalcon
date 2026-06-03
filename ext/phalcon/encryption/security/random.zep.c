
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Encryption\Security\Random
 *
 * Secure random number generator class.
 *
 * Provides secure random number generator which is suitable for generating
 * session key in HTTP cookies, etc.
 *
 * `Phalcon\Encryption\Security\Random` could be mainly useful for:
 *
 * - Key generation (e.g. generation of complicated keys)
 * - Generating random passwords for new user accounts
 * - Encryption systems
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * // Random binary string
 * $bytes = $random->bytes();
 *
 * // Random hex string
 * echo $random->hex(10); // a29f470508d5ccb8e289
 * echo $random->hex(10); // 533c2f08d5eee750e64a
 * echo $random->hex(11); // f362ef96cb9ffef150c9cd
 * echo $random->hex(12); // 95469d667475125208be45c4
 * echo $random->hex(13); // 05475e8af4a34f8f743ab48761
 *
 * // Random base62 string
 * echo $random->base62(); // z0RkwHfh8ErDM1xw
 *
 * // Random base64 string
 * echo $random->base64(12); // XfIN81jGGuKkcE1E
 * echo $random->base64(12); // 3rcq39QzGK9fUqh8
 * echo $random->base64();   // DRcfbngL/iOo9hGGvy1TcQ==
 * echo $random->base64(16); // SvdhPcIHDZFad838Bb0Swg==
 *
 * // Random URL-safe base64 string
 * echo $random->base64Safe();           // PcV6jGbJ6vfVw7hfKIFDGA
 * echo $random->base64Safe();           // GD8JojhzSTrqX7Q8J6uug
 * echo $random->base64Safe(8);          // mGyy0evy3ok
 * echo $random->base64Safe(null, true); // DRrAgOFkS4rvRiVHFefcQ==
 *
 * // Random UUID (version 4) — returns a string
 * echo $random->uuid(); // db082997-2572-4e2c-a046-5eefe97b1235
 * echo $random->uuid(); // da2aa0e2-b4d0-4e3c-99f5-f5ef62c57fe2
 *
 * // For other UUID versions (1, 3, 5, 6, 7) or object-based access use the
 * // Phalcon\Encryption\Security\Uuid factory instead:
 * //
 * // $uuid = new \Phalcon\Encryption\Security\Uuid();
 * // echo $uuid->v1(); // time-based
 * // echo $uuid->v6(); // reordered time-based (sortable)
 * // echo $uuid->v7(); // Unix-timestamp based (sortable)
 *
 * // Random number between 0 and $len
 * echo $random->number(256); // 84
 * echo $random->number(256); // 79
 * echo $random->number(100); // 29
 * echo $random->number(300); // 40
 *
 * // Random base58 string
 * echo $random->base58();   // 4kUgL2pdQMSCQtjE
 * echo $random->base58();   // Umjxqf7ZPwh765yR
 * echo $random->base58(24); // qoXcgmw4A9dys26HaNEdCRj9
 * echo $random->base58(7);  // 774SJD3vgP
 *```
 *
 * This class partially borrows SecureRandom library from Ruby
 *
 * @link https://ruby-doc.org/stdlib-2.2.2/libdoc/securerandom/rdoc/SecureRandom.html
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Random)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Security, Random, phalcon, encryption_security_random, phalcon_encryption_security_random_method_entry, 0);

	return SUCCESS;
}

/**
 * Generates a random base58 string
 *
 * The result may contain alphanumeric characters except 0, O, I and l.
 *
 * It is similar to `Phalcon\Encryption\Security\Random::base64()` but has been
 * modified to avoid both non-alphanumeric characters and letters which
 * might look ambiguous when printed.
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * echo $random->base58(); // 4kUgL2pdQMSCQtjE
 *```
 *
 * @see    \Phalcon\Encryption\Security\Random:base64
 * @link   https://en.wikipedia.org/wiki/Base58
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Encryption_Security_Random, base58)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *len_param = NULL, _0, _1, _2;
	zend_long len, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(len)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &len_param);
	if (!len_param) {
		len = 16;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz");
	ZVAL_LONG(&_1, 58);
	ZVAL_LONG(&_2, len);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "base", NULL, 0, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a random base62 string
 *
 * It is similar to `Phalcon\Encryption\Security\Random::base58()` but has been
 * modified to provide the largest value that can safely be used in URLs
 * without needing to take extra characters into consideration because it is
 * [A-Za-z0-9].
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * echo $random->base62(); // z0RkwHfh8ErDM1xw
 *```
 *
 * @see    \Phalcon\Encryption\Security\Random:base58
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Encryption_Security_Random, base62)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *len_param = NULL, _0, _1, _2;
	zend_long len, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(len)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &len_param);
	if (!len_param) {
		len = 16;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	ZVAL_LONG(&_1, 62);
	ZVAL_LONG(&_2, len);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "base", NULL, 0, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a random base64 string
 *
 * The length of the result string is usually greater of $len.
 * Size formula: 4 * ($len / 3) rounded up to a multiple of 4.
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * echo $random->base64(12); // 3rcq39QzGK9fUqh8
 *```
 *
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Encryption_Security_Random, base64)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *len_param = NULL, _0, _1;
	zend_long len, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(len)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &len_param);
	if (!len_param) {
		len = 16;
	} else {
		}
	ZVAL_LONG(&_1, len);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "bytes", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_encode", NULL, 474, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a random URL-safe base64 string
 *
 * The length of the result string is usually greater of $len.
 *
 * By default, padding is not generated because "=" may be used as a URL
 * delimiter. The result may contain A-Z, a-z, 0-9, "-" and "_". "=" is also
 * used if $padding is true. See RFC 3548 for the definition of URL-safe
 * base64.
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * echo $random->base64Safe(); // GD8JojhzSTrqX7Q8J6uug
 *```
 *
 * @link https://www.ietf.org/rfc/rfc3548.txt
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Encryption_Security_Random, base64Safe)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool padding;
	zval *len_param = NULL, *padding_param = NULL, s, _0, _1, _2, _3, _4, _5, _6$$3;
	zend_long len, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(len)
		Z_PARAM_BOOL(padding)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 2, &len_param, &padding_param);
	if (!len_param) {
		len = 16;
	} else {
		}
	if (!padding_param) {
		padding = 0;
	} else {
		}
	ZVAL_LONG(&_1, len);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "base64", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "base64_encode", NULL, 474, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "+/");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "-_");
	ZEPHIR_CALL_FUNCTION(&s, "strtr", NULL, 6, &_2, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "#[^a-z0-9_=-]+#i");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "");
	ZEPHIR_CALL_FUNCTION(&_5, "preg_replace", NULL, 76, &_3, &_4, &s);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&s, &_5);
	if (!(padding)) {
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "=");
		zephir_fast_trim(return_value, &s, &_6$$3, ZEPHIR_TRIM_RIGHT);
		RETURN_MM();
	}
	RETURN_CCTOR(&s);
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
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * $bytes = $random->bytes();
 * var_dump(bin2hex($bytes));
 * // Possible output: string(32) "00f6c04b144b41fad6a59111c126e1ee"
 *```
 *
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Encryption_Security_Random, bytes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *len_param = NULL, _0;
	zend_long len, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(len)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &len_param);
	if (!len_param) {
		len = 16;
	} else {
		}
	if (len <= 0) {
		len = 16;
	}
	ZVAL_LONG(&_0, len);
	ZEPHIR_RETURN_CALL_FUNCTION("random_bytes", NULL, 299, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a random hex string
 *
 * The length of the result string is usually greater of $len.
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * echo $random->hex(10); // a29f470508d5ccb8e289
 *```
 *
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Encryption_Security_Random, hex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *len_param = NULL, _0, _1, _2, _3;
	zend_long len, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(len)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &len_param);
	if (!len_param) {
		len = 16;
	} else {
		}
	ZVAL_LONG(&_1, len);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "bytes", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "H*");
	ZEPHIR_CALL_FUNCTION(&_3, "unpack", NULL, 0, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&_3);
	ZEPHIR_RETURN_CALL_FUNCTION("array_shift", NULL, 40, &_3);
	ZEPHIR_UNREF(&_3);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a random number between 0 and $len
 *
 * Returns an integer: 0 <= result <= $len.
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * echo $random->number(16); // 8
 *```
 * @throws Exception If secure random number generator is not available,
 *                   unexpected partial read or $len <= 0
 */
PHP_METHOD(Phalcon_Encryption_Security_Random, number)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *len_param = NULL, _0$$3, _1, _2;
	zend_long len, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(len)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &len_param);
	if (UNEXPECTED(len <= 0)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_encryption_security_exceptions_invalidrandominput_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Encryption/Security/Random.zep", 274);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_LONG(&_1, 0);
	ZVAL_LONG(&_2, len);
	ZEPHIR_RETURN_CALL_FUNCTION("random_int", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Generates a v4 random UUID (Universally Unique IDentifier)
 *
 * The version 4 UUID is purely random (except the version). It does not
 * contain meaningful information such as MAC address, time, etc. See RFC
 * 4122 for details of UUID.
 *
 * Delegates to `Phalcon\Encryption\Security\Uuid::v4()`. For other UUID
 * versions or object-based access use that class directly.
 *
 *```php
 * $random = new \Phalcon\Encryption\Security\Random();
 *
 * echo $random->uuid(); // 1378c906-64bb-4f81-a8d6-4ae1bfcdec22
 *```
 *
 * @link https://www.ietf.org/rfc/rfc4122.txt
 */
PHP_METHOD(Phalcon_Encryption_Security_Random, uuid)
{
	zval _2;
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_encryption_security_uuid_ce);
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(&_1, &_0, "v4", NULL, 0);
	zephir_check_call_status();
	zephir_cast_to_string(&_2, &_1);
	RETURN_CTOR(&_2);
}

/**
 * Generates a random string based on the number ($base) of characters
 * ($alphabet).
 *
 * @throws Exception If secure random number generator is not available or unexpected partial read
 */
PHP_METHOD(Phalcon_Encryption_Security_Random, base)
{
	unsigned char _6$$3, _11$$5;
	double _3$$3, _9$$5;
	zend_bool _8;
	zval byteString;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long base, ZEPHIR_LAST_CALL_STATUS;
	zval alphabet_zv, *base_param = NULL, *number = NULL, number_sub, bytes, idx, _0, _1, *_2, _7, _4$$4, _10$$6;
	zend_string *alphabet = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alphabet_zv);
	ZVAL_UNDEF(&number_sub);
	ZVAL_UNDEF(&bytes);
	ZVAL_UNDEF(&idx);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&byteString);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(alphabet)
		Z_PARAM_LONG(base)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(number)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	base_param = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		number = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_memory_observe(&alphabet_zv);
	ZVAL_STR_COPY(&alphabet_zv, alphabet);
	if (!number) {
		number = &number_sub;
		ZEPHIR_INIT_VAR(number);
		ZVAL_LONG(number, 16);
	}
	ZEPHIR_INIT_VAR(&byteString);
	ZVAL_STRING(&byteString, "");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "bytes", NULL, 0, number);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "C*");
	ZEPHIR_CALL_FUNCTION(&bytes, "unpack", NULL, 0, &_1, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&bytes, 0, "phalcon/Encryption/Security/Random.zep", 330);
	if (Z_TYPE_P(&bytes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&bytes), _2)
		{
			ZEPHIR_INIT_NVAR(&idx);
			ZVAL_COPY(&idx, _2);
			_3$$3 = zephir_safe_mod_zval_long(&idx, 64);
			ZEPHIR_INIT_NVAR(&idx);
			ZVAL_DOUBLE(&idx, _3$$3);
			if (ZEPHIR_GE_LONG(&idx, base)) {
				ZVAL_LONG(&_4$$4, (base - 1));
				ZEPHIR_CALL_METHOD(&idx, this_ptr, "number", &_5, 0, &_4$$4);
				zephir_check_call_status();
			}
			_6$$3 = ZEPHIR_STRING_OFFSET(&alphabet_zv, zephir_get_intval(&idx));
			zephir_concat_self_char(&byteString, _6$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &bytes, "rewind", NULL, 0);
		zephir_check_call_status();
		_8 = 1;
		while (1) {
			if (_8) {
				_8 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &bytes, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_7, &bytes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_7)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&idx, &bytes, "current", NULL, 0);
			zephir_check_call_status();
				_9$$5 = zephir_safe_mod_zval_long(&idx, 64);
				ZEPHIR_INIT_NVAR(&idx);
				ZVAL_DOUBLE(&idx, _9$$5);
				if (ZEPHIR_GE_LONG(&idx, base)) {
					ZVAL_LONG(&_10$$6, (base - 1));
					ZEPHIR_CALL_METHOD(&idx, this_ptr, "number", &_5, 0, &_10$$6);
					zephir_check_call_status();
				}
				_11$$5 = ZEPHIR_STRING_OFFSET(&alphabet_zv, zephir_get_intval(&idx));
				zephir_concat_self_char(&byteString, _11$$5);
		}
	}
	ZEPHIR_INIT_NVAR(&idx);
	RETURN_CTOR(&byteString);
}

