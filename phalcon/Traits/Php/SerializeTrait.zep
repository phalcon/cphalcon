
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
 * PHP serialize/unserialize wrapper methods
 */
trait SerializeTrait
{
    /**
     * @param mixed $value
     *
     * @return string
     *
     * @link https://php.net/manual/en/function.serialize.php
     */
    protected static function phpSerialize(var value) -> string
    {
        return serialize(value);
    }

    /**
     * @param string $data
     * @param array  $options
     *
     * @return mixed
     *
     * @link https://php.net/manual/en/function.unserialize.php
     */
    protected static function phpUnserialize(string data, array options = []) -> mixed
    {
        return unserialize(data, options);
    }
}
