
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Traits\Support\Helper\Str;

/**
 * Check if a string ends with a given string
 */
trait EndsWithTrait
{
    /**
     * @param string $haystack
     * @param string $needle
     * @param bool   $ignoreCase
     *
     * @return bool
     */
    protected static function toEndsWith(
        string haystack,
        string needle,
        bool ignoreCase = true
    ) -> bool {
        var child, parent;

        if ("" === haystack) {
            return false;
        }

        if likely ignoreCase {
            let child  = mb_strtolower(needle),
                parent = mb_strtolower(haystack);
        } else {
            let child  = needle,
                parent = haystack;
        }

        return ends_with(parent, child);
    }
}
