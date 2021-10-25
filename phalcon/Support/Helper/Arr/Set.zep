
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
 * Class Set
 *
 * @package Phalcon\Support\Arr
 */
class Set
{
    /**
     * Helper method to set an array element
     *
     * @param array $collection
     * @param mixed $value
     * @param mixed $index
     *
     * @return array
     */
    public function __invoke(
        array collection,
        var value,
        var index = null
    ) -> array {
        var source;

        let source = this->checkNull(collection, value, index);

        return this->checkNotNull(source, value, index);
    }

    /**
     * @param array $collection
     * @param mixed $value
     * @param mixed $index
     *
     * @return array
     */
    private function checkNull(array collection, var value, var index) -> array
    {
        if null === index {
            let collection[] = value;
        }

        return collection;
    }

    /**
     * @param array $collection
     * @param mixed $value
     * @param mixed $index
     *
     * @return array<int|string,mixed>
     */
    private function checkNotNull(array collection, var value, var index) -> array
    {
        if null !== index {
            let collection[index] = value;
        }

        return collection;
    }
}
