
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter;

use Phalcon\Contracts\Filter\FilterTypes;

/**
 * Lazy loads, stores and exposes sanitizer objects
 *
 * @phpstan-import-type filter_sanitizers from FilterTypes
 */
interface FilterInterface
{
    /**
     * Sanitizes a value with a specified single or set of sanitizers
     *
     * Array policy: when `$value` is an array and `$noRecursive` is `false`
     * (the default), each element is sanitized individually and an array is
     * returned - recursion is one level deep only. When `$noRecursive` is
     * `true`, the whole array is passed to the sanitizer as a single value.
     *
     * @param mixed $value
     * @param mixed $sanitizers
     * @param bool  $noRecursive
     *
     * @phpstan-param filter_sanitizers|string $sanitizers
     *
     * @return mixed
     */
    public function sanitize(var value, var sanitizers, bool noRecursive = false) -> var;
}
