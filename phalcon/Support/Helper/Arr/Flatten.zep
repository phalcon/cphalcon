
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
 * Flattens an array up to the one level depth, unless `$deep` is set to
 * `true`
 */
class Flatten
{
    /**
     * @param array $collection
     * @param bool  $deep
     *
     * @return array
     */
    public function __invoke(array collection, bool deep = false) -> array
    {
        var data, item;

        let data = [];

        for item in collection {
            let data = this->processNotArray(data, item),
                data = this->processArrayDeep(data, item, deep),
                data = this->processArray(data, item, deep);
        }

        return data;
    }

    /**
     * @param array $data
     * @param mixed $item
     *
     * @return array
     */
    private function processNotArray(array data, item) -> array
    {
        if typeof item !== "array" {
            let data[] = item;
        }

        return data;
    }

    /**
     * @param array $data
     * @param mixed $item
     * @param bool  $deep
     *
     * @return array
     */
    private function processArray(array data, var item, bool deep) -> array
    {
        if typeof item === "array" && !deep {
            let data = array_merge(data, array_values(item));
        }

        return data;
    }

    /**
     * @param array $data
     * @param mixed $item
     * @param bool  $deep
     *
     * @return array
     */
    private function processArrayDeep(array data, var item, bool deep) -> array
    {
        if typeof item === "array" && deep {
            let data = array_merge(data, this->__invoke(item, true));
        }

        return data;
    }
}
