
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
 * Class Pluck
 *
 * @package Phalcon\Support\Arr
 */
class Pluck
{
    /**
     * Retrieves all the values for a given key:
     *
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
