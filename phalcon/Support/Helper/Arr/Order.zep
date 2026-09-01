
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
 * Sorts a collection of arrays or objects by an attribute of the object. It
 * supports ascending/descending sorts but also flags that are identical to
 * the ones used by `ksort` and `krsort`
 */
class Order
{
    /**
     * @var int
     */
    const ORDER_ASC  = 1;
    /**
     * @var int
     */
    const ORDER_DESC = 2;

    /**
     * @param array<array-key, mixed> $collection
     *
     * @return array<array-key, mixed>
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
     * @param array<array-key, mixed> $sorted
     * @param string                  $attribute
     * @param mixed                   $item
     *
     * @return array<array-key, mixed>
     */
    private function checkNonObject(
        array sorted,
        string attribute,
        var item
    ) -> array {
        var key;

        if typeof item !== "object" {
            let key         = item[attribute],
                sorted[key] = item;
        }

        return sorted;
    }

    /**
     * @param array<array-key, mixed> $sorted
     * @param string                  $attribute
     * @param mixed                   $item
     *
     * @return array<array-key, mixed>
     */
    private function checkObject(
        array sorted,
        string attribute,
        var item
    ) -> array {
        var key;
        
        if typeof item === "object" {
            let key         = item->{attribute},
                sorted[key] = item;
        }

        return sorted;
    }
}
