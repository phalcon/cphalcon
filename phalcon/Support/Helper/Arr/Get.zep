
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
 * Gets an array element by key and if it does not exist returns the default.
 * It also allows for casting the returned value to a specific type using
 * `settype` internally
 */
class Get
{
    /**
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
