
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
 * Class Order
 *
 * @package Phalcon\Support\Arr
 */
class Order
{
    const ORDER_ASC  = 1;
    const ORDER_DESC = 2;

    /**
     * Sorts a collection of arrays or objects by key
     *
     * @param array $collection
     * @param mixed $attribute
     * @param int   $order
     * @param int   $flags
     *
     * @return array
     */
    public function __invoke(
        array collection,
        var attribute,
        int order = self::ORDER_ASC,
        int flags = 0
    ) -> array {
        var item, sorted;

        let sorted = [];
        for item in collection {
            let sorted = this->checkObject(sorted, attribute, item),
                sorted = this->checkNonObject(sorted, attribute, item);
        }

        if self::ORDER_ASC === order {
            ksort(sorted, flags);
        } else {
            krsort(sorted, flags);
        }

        return array_values(sorted);
    }

    /**
     * @param array $sorted
     * @param mixed $attribute
     * @param mixed $item
     *
     * @return array
     */
    private function checkObject(array sorted, var attribute, var item) -> array
    {
        var key;

        if typeof item === "object" {
            let key         = item->{attribute},
                sorted[key] = item;
        }

        return sorted;
    }

    /**
     * @param array $sorted
     * @param mixed $attribute
     * @param mixed $item
     *
     * @return array
     */
    private function checkNonObject(array sorted, var attribute, var item) -> array
    {
        var key;

        if typeof item !== "object" {
            let key         = item[attribute],
                sorted[key] = item;
        }

        return sorted;
    }
}
