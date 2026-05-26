
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Security;

use Phalcon\Encryption\Security\Exceptions\InvalidRandomInput;

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
class Random
{
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
    public function base58(int len = 16) -> string
    {
        return this->base(
            "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz",
            58,
            len
        );
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
    public function base62(int len = 16) -> string
    {
        return this->base(
            "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",
            62,
            len
        );
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
    public function base64(int len = 16) -> string
    {
        return base64_encode(
            this->bytes(len)
        );
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
    public function base64Safe(int len = 16, bool padding = false) -> string
    {
        var s;

        let s = strtr(
            base64_encode(
                this->base64(len)
            ),
            "+/",
            "-_"
        );

        let s = preg_replace(
            "#[^a-z0-9_=-]+#i",
            "",
            s
        );

        if !padding {
            return rtrim(s, "=");
        }

        return s;
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
    public function bytes(int len = 16) -> string
    {
        if len <= 0 {
            let len = 16;
        }

        return random_bytes(len);
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
    public function hex(int len = 16) -> string
    {
        return array_shift(
            unpack(
                "H*",
                this->bytes(len)
            )
        );
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
    public function number(int len) -> int
    {
        if unlikely len <= 0 {
            throw new InvalidRandomInput();
        }

        return random_int(0, len);
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
    public function uuid() -> string
    {
        return (string) (new Uuid())->v4();
    }


    /**
     * Generates a random string based on the number ($base) of characters
     * ($alphabet).
     *
     * @throws Exception If secure random number generator is not available or unexpected partial read
     */
    protected function base(string alphabet, int base, number = 16) -> string
    {
        var bytes, idx;
        string byteString = "";

        let bytes = unpack(
            "C*",
            this->bytes(number)
        );

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
