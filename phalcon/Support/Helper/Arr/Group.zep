
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Arr;

use Phalcon\Traits\Php\InfoTrait;

/**
 * Groups the elements of an array based on the passed callable
 */
class Group
{
    use InfoTrait;

    /**
     * @param array<array-key, mixed> $collection
     * @param callable|string         $method
     *
     * @return array<array-key, mixed>
     */
    public function __invoke(array collection, var method) -> array
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

    private function isCallable(var method) -> bool
    {
        return (
            is_callable(method) ||
            (typeof method === "string" && true === this->phpFunctionExists(method))
        );
    }

    /**
     * @param mixed $element
     *
     * @return bool
     */
    private function isObject(var element) -> bool
    {
        return typeof element === "object";
    }

    /**
     * @param array<array-key, mixed> $filtered
     * @param callable|string         $method
     * @param mixed                   $element
     *
     * @return array<array-key, mixed>
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
     * @param array<array-key, mixed> $filtered
     * @param callable|string         $method
     * @param mixed                   $element
     *
     * @return array<array-key, mixed>
     */
    private function processObject(array filtered, var method, var element) -> array
    {
        var output;

        let output = filtered;
        if (
            true !== this->isCallable(method) &&
            true === this->isObject(element)
        ) {
            var key;

            let key           = element->{method},
                output[key][] = element;
        }

        return output;
    }

    /**
     * @param array<array-key, mixed> $filtered
     * @param callable|string         $method
     * @param mixed                   $element
     *
     * @return array<array-key, mixed>
     */
    private function processOther(array filtered, var method, var element) -> array
    {
        var output;

        let output = filtered;
        if (
            true !== this->isCallable(method) &&
            true !== this->isObject(element) &&
            true === isset(element[method])
        ) {
            var key;

            let key           = element[method],
                output[key][] = element;
        }

        return output;
    }
}
