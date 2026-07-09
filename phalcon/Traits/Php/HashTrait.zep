
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
 * Hashing method wrappers
 */
trait HashTrait
{
    /**
     * @param string $algorithm
     * @param string $data
     * @param bool   $binary
     *
     * @return string
     *
     * @link https://php.net/manual/en/function.hash.php
     */
    protected static function phpHash(string algorithm, string data, bool binary = false) -> string
    {
        return hash(algorithm, data, binary);
    }

    /**
     * @param string $knownString
     * @param string $userString
     *
     * @return bool
     *
     * @link https://php.net/manual/en/function.hash-equals.php
     */
    protected static function phpHashEquals(string knownString, string userString) -> bool
    {
        return hash_equals(knownString, userString);
    }

    /**
     * @param string $algorithm
     * @param string $data
     * @param string $key
     * @param bool   $binary
     *
     * @return string
     *
     * @link https://php.net/manual/en/function.hash-hmac.php
     */
    protected static function phpHashHmac(string algorithm, string data, string key, bool binary = false) -> string
    {
        return hash_hmac(algorithm, data, key, binary);
    }
}
