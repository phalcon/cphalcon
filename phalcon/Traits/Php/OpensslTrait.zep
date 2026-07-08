
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Traits\Php;

/**
 * OpenSSL based wrapper methods
 */
trait OpensslTrait
{
    /**
     * @param string $cipher
     *
     * @return int|bool
     *
     * @link https://php.net/manual/en/function.openssl-cipher-iv-length.php
     */
    protected static function phpOpensslCipherIvLength(string cipher) -> int | bool
    {
        return openssl_cipher_iv_length(cipher);
    }

    /**
     * @param int $length
     *
     * @return string|false
     *
     * @link https://php.net/manual/en/function.openssl-random-pseudo-bytes.php
     */
    protected static function phpOpensslRandomPseudoBytes(int length)
    {
        return openssl_random_pseudo_bytes(length);
    }
}
