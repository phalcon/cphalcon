
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Arr;

/**
 * Class Get
 *
 * @package Phalcon\Support\Arr
 */
class Get
{
    /**
     * Helper method to get an array element or a default
     *
     * @param array       $collection
     * @param mixed       $index
     * @param mixed|null  $defaultValue
     * @param string|null $cast
     *
     * @return mixed|null
     */
    public function __invoke(
        array collection,
        var index,
        var defaultValue = null,
        string cast = null
    ) -> var {
        var value;

        let value = defaultValue;
        if true === isset(collection[index]) {
            let value = collection[index];
        }

        if cast {
            settype(value, cast);
        }

        return value;
    }
}
