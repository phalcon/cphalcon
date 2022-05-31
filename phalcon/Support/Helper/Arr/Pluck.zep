
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Arr;

/**
 * Returns a subset of the collection based on the values of the collection
 */
class Pluck
{
    /**
     * @param array  $collection
     * @param string $element
     *
     * @return array
     */
    public function __invoke(array collection, string element) -> array
    {
        var item;
        array filtered;

        let filtered = [];

        for item in collection {
            if typeof item === "object" && isset item->{element} {
                let filtered[] = item->{element};
            } elseif typeof item === "array" && isset item[element] {
                let filtered[] = item[element];
            }
        }

        return filtered;
    }
}
