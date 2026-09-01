
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
 * APCu based wrapper methods
 */
trait ApcuTrait
{
    /**
     * @param mixed $key
     * @param int   $step
     *
     * @return bool|int
     *
     * @link https://php.net/manual/en/function.apcu-dec.php
     */
    protected static function phpApcuDec(var key, int step = 1) -> bool | int
    {
        return apcu_dec(key, step);
    }

    /**
     * @param mixed $key
     *
     * @return bool|array
     *
     * @link https://php.net/manual/en/function.apcu-delete.php
     */
    protected static function phpApcuDelete(var key) -> bool | array
    {
        return apcu_delete(key);
    }

    /**
     * @param mixed $key
     *
     * @return bool|array
     *
     * @link https://php.net/manual/en/function.apcu-exists.php
     */
    protected static function phpApcuExists(var key) -> bool | array
    {
        return apcu_exists(key);
    }

    /**
     * @param mixed $key
     *
     * @return mixed
     *
     * @link https://php.net/manual/en/function.apcu-fetch.php
     */
    protected static function phpApcuFetch(var key) -> var
    {
        return apcu_fetch(key);
    }

    /**
     * @param mixed $key
     * @param int   $step
     *
     * @return bool|int
     *
     * @link https://php.net/manual/en/function.apcu-inc.php
     */
    protected static function phpApcuInc(var key, int step = 1) -> bool | int
    {
        return apcu_inc(key, step);
    }

    /**
     * @param string $pattern
     *
     * @return \APCUIterator|bool
     *
     * @link https://php.net/manual/en/class.apcuiterator.php
     */
    protected static function phpApcuIterator(string pattern) -> <\APCUIterator> | bool
    {
        return new \APCUIterator(pattern);
    }

    /**
     * @param mixed $key
     * @param mixed $payload
     * @param int   $ttl
     *
     * @return bool|array
     *
     * @link https://php.net/manual/en/function.apcu-store.php
     */
    protected static function phpApcuStore(var key, var payload, int ttl = 0) -> bool | array
    {
        return apcu_store(key, payload, ttl);
    }
}
