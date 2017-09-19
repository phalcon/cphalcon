
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Serghei Iakovlev <serghei@phalconphp.com>                     |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Security;

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
 * - openssl, libressl
 * - /dev/urandom
 *
 * `Phalcon\Security\Random` could be mainly useful for:
 *
 * - Key generation (e.g. generation of complicated keys)
 * - Generating random passwords for new user accounts
 * - Encryption systems
 *
 *<code>
 * $random = new \Phalcon\Security\Random();
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
 * // Random UUID
 * echo $random->uuid(); // db082997-2572-4e2c-a046-5eefe97b1235
 * echo $random->uuid(); // da2aa0e2-b4d0-4e3c-99f5-f5ef62c57fe2
 * echo $random->uuid(); // 75e6b628-c562-4117-bb76-61c4153455a9
 * echo $random->uuid(); // dc446df1-0848-4d05-b501-4af3c220c13d
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
 *</code>
 *
 * This class partially borrows SecureRandom library from Ruby
 *
 * @link http://ruby-doc.org/stdlib-2.2.2/libdoc/securerandom/rdoc/SecureRandom.html
 */
class Random
{
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
	 * $random = new \Phalcon\Security\Random();
	 *
	 * $bytes = $random->bytes();
	 * var_dump(bin2hex($bytes));
	 * // Possible output: string(32) "00f6c04b144b41fad6a59111c126e1ee"
	 *</code>
	 *
	 * @throws Exception If secure random number generator is not available or unexpected partial read
	 */
	public function bytes(int len = 16) -> string
	{
		var handle, ret;

		if len <= 0 {
			let len = 16;
		}

		if function_exists("random_bytes") {
			return random_bytes(len);
		}

		if function_exists("\\Sodium\\randombytes_buf") {
			return \\Sodium\\randombytes_buf(len);
		}

		if function_exists("openssl_random_pseudo_bytes") {
			return openssl_random_pseudo_bytes(len);
		}

		if file_exists("/dev/urandom") {
			let handle = fopen("/dev/urandom", "rb");

			if handle !== false {
				stream_set_read_buffer(handle, 0);
				let ret = fread(handle, len);
				fclose(handle);

				if strlen(ret) != len {
					throw new Exception("Unexpected partial read from random device");
				}

				return ret;
			}
		}

		throw new Exception("No random device available");
	}

	/**
	 * Generates a random hex string
	 *
	 * If $len is not specified, 16 is assumed. It may be larger in future.
	 * The length of the result string is usually greater of $len.
	 *
	 *<code>
	 * $random = new \Phalcon\Security\Random();
	 *
	 * echo $random->hex(10); // a29f470508d5ccb8e289
	 *</code>
	 *
	 * @throws Exception If secure random number generator is not available or unexpected partial read
	 */
	public function hex(int len = null) -> string
	{
		return array_shift(unpack("H*", this->bytes(len)));
	}

	/**
	 * Generates a random base58 string
	 *
	 * If $len is not specified, 16 is assumed. It may be larger in future.
	 * The result may contain alphanumeric characters except 0, O, I and l.
	 *
	 * It is similar to `Phalcon\Security\Random:base64` but has been modified to avoid both non-alphanumeric
	 * characters and letters which might look ambiguous when printed.
	 *
	 *<code>
	 * $random = new \Phalcon\Security\Random();
	 *
	 * echo $random->base58(); // 4kUgL2pdQMSCQtjE
	 *</code>
	 *
	 * @see    \Phalcon\Security\Random:base64
	 * @link   https://en.wikipedia.org/wiki/Base58
	 * @throws Exception If secure random number generator is not available or unexpected partial read
	 */
	public function base58(int len = null) -> string
	{
		return this->base("123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz", 58, len);
	}

	/**
	 * Generates a random base62 string
	 *
	 * If $len is not specified, 16 is assumed. It may be larger in future.
	 *
	 * It is similar to `Phalcon\Security\Random:base58` but has been modified to provide the largest value that can
	 * safely be used in URLs without needing to take extra characters into consideration because it is [A-Za-z0-9].
	 *
	 *<code>
	 * $random = new \Phalcon\Security\Random();
	 *
	 * echo $random->base62(); // z0RkwHfh8ErDM1xw
	 *</code>
	 *
	 * @see    \Phalcon\Security\Random:base58
	 * @throws Exception If secure random number generator is not available or unexpected partial read
	 */
	public function base62(int len = null) -> string
	{
		return this->base("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", 62, len);
	}

	/**
	 * Generates a random base64 string
	 *
	 * If $len is not specified, 16 is assumed. It may be larger in future.
	 * The length of the result string is usually greater of $len.
	 * Size formula: 4 * ($len / 3) and this need to be rounded up to a multiple of 4.
	 *
	 *<code>
	 * $random = new \Phalcon\Security\Random();
	 *
	 * echo $random->base64(12); // 3rcq39QzGK9fUqh8
	 *</code>
	 *
	 * @throws Exception If secure random number generator is not available or unexpected partial read
	 */
	public function base64(int len = null) -> string
	{
		return base64_encode(this->bytes(len));
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
	 * $random = new \Phalcon\Security\Random();
	 *
	 * echo $random->base64Safe(); // GD8JojhzSTrqX7Q8J6uug
	 *</code>
	 *
	 * @link https://www.ietf.org/rfc/rfc3548.txt
	 * @throws Exception If secure random number generator is not available or unexpected partial read
	 */
	public function base64Safe(int len = null, boolean padding = false) -> string
	{
		var s;

		let s = strtr(base64_encode(this->base64(len)), "+/", "-_");
		let s = preg_replace("#[^a-z0-9_=-]+#i", "", s);

		if !padding {
			return rtrim(s, "=");
		}

		return s;
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
	 * $random = new \Phalcon\Security\Random();
	 *
	 * echo $random->uuid(); // 1378c906-64bb-4f81-a8d6-4ae1bfcdec22
	 *</code>
	 *
	 * @link https://www.ietf.org/rfc/rfc4122.txt
	 * @throws Exception If secure random number generator is not available or unexpected partial read
	 */
	public function uuid() -> string
	{
		var ary;

		let ary = array_values(unpack("N1a/n1b/n1c/n1d/n1e/N1f", this->bytes(16)));
		let ary[2] = (ary[2] & 0x0fff) | 0x4000,
			ary[3] = (ary[3] & 0x3fff) | 0x8000;

		array_unshift(ary, "%08x-%04x-%04x-%04x-%04x%08x");

		return call_user_func_array("sprintf", ary);
	}

	/**
	 * Generates a random number between 0 and $len
	 *
	 * Returns an integer: 0 <= result <= $len.
	 *
	 *<code>
	 * $random = new \Phalcon\Security\Random();
	 *
	 * echo $random->number(16); // 8
	 *</code>
	 * @throws Exception If secure random number generator is not available, unexpected partial read or $len <= 0
	 */
	public function number(int len) -> int
	{
		var hex, mask, rnd, ret;
		string bin = "";

		if len <= 0 {
			throw new Exception("Require a positive integer > 0");
		}

		if function_exists("random_int") {
			return random_int(0, len);
		}

		if function_exists("\\Sodium\\randombytes_uniform") {
			// \Sodium\randombytes_uniform will return a random integer between 0 and len - 1
			return \\Sodium\\randombytes_uniform(len) + 1;
		}

		let hex = dechex(len);

		if (strlen(hex) & 1) == 1 {
			let hex = "0" . hex;
		}

		let bin .= pack("H*", hex);

		let mask = ord(bin[0]);
		let mask = mask | (mask >> 1);
		let mask = mask | (mask >> 2);
		let mask = mask | (mask >> 4);

		do {
			let rnd = this->bytes(strlen(bin));
			let rnd = substr_replace(rnd, chr(ord(substr(rnd, 0, 1)) & mask), 0, 1);
		} while bin < rnd;

		let ret = unpack("H*", rnd);

		return hexdec(array_shift(ret));
	}

	/**
	 * Generates a random string based on the number ($base) of characters ($alphabet).
	 *
	 * If $n is not specified, 16 is assumed. It may be larger in future.
	 *
	 * @throws Exception If secure random number generator is not available or unexpected partial read
	 */
	protected function base(string alphabet, int base, n = null) -> string
	{
		var bytes, idx;
		string byteString = "";

		let bytes = unpack("C*", this->bytes(n));

		for idx in bytes {
			let idx = idx % 64;

			if idx >= base {
				let idx = this->number(base - 1);
			}

			let byteString .= alphabet[(int) idx];
		}

		return byteString;
	}
}
