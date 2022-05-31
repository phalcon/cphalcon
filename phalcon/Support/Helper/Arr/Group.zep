
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
 * Groups the elements of an array based on the passed callable
 */
class Group
{
    /**
     * @param array           $collection
     * @param callable|string $method
     *
     * @return array
     */
    public function __invoke(array collection, method) -> array
    {
        var element, filtered;

        let filtered = [];

        for element in collection {
            let filtered = this->processCallable(filtered, method, element),
                filtered = this->processObject(filtered, method, element),
                filtered = this->processOther(filtered, method, element);
        }

        return filtered;
    }

    /**
     * @param mixed $method
     *
     * @return bool
     */
    private function isCallable(var method) -> bool
    {
        return (
            is_callable(method) ||
            (typeof method === "string" && true === function_exists(method))
        );
    }

    /**
     * @param array           $filtered
     * @param callable|string $method
     * @param mixed           $element
     *
     * @return array
     */
    private function processCallable(array filtered, var method, var element) -> array
    {
        var key, output;

        let output = filtered;
        if (true === this->isCallable(method)) {
            let key           = call_user_func(method, element),
                output[key][] = element;
        }

        return output;
    }

    /**
     * @param array           $filtered
     * @param callable|string $method
     * @param mixed           $element
     *
     * @return array
     */
    private function processObject(array filtered, var method, var element) -> array
    {
        var output;

        let output = filtered;
        if (
            true !== this->isCallable(method) &&
            typeof element === "object"
        ) {
            var key;

            let key           = element->{method},
                output[key][] = element;
        }

        return output;
    }

    /**
     * @param array           $filtered
     * @param callable|string $method
     * @param mixed           $element
     *
     * @return array
     */
    private function processOther(array filtered, var method, var element) -> array
    {
        var output;

        let output = filtered;
        if (
            true !== this->isCallable(method) &&
            typeof element !== "object" &&
            true === isset(element[method])
        ) {
            var key;

            let key           = element[method],
                output[key][] = element;
        }

        return output;
    }
}
