
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
 * Igbinary based wrapper methods
 */
trait IgbinaryTrait
{
    /**
     * @param mixed $value
     *
     * @return string|null
     *
     * @link https://php.net/manual/en/function.igbinary-serialize.php
     */
    protected static function phpIgbinarySerialize(var value) -> string | null
    {
        return igbinary_serialize(value);
    }

    /**
     * @param string $value
     *
     * @return mixed|false
     *
     * @link https://php.net/manual/en/function.igbinary-unserialize.php
     */
    protected static function phpIgbinaryUnserialize(var value)
    {
        return igbinary_unserialize(value);
    }
}
