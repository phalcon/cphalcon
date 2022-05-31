
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

/**
 * Determines whether a string includes another string or not.
 */
class Includes
{
    /**
     * @param string $haystack
     * @param string $needle
     *
     * @return bool
     */
    public function __invoke(
        string haystack,
        string needle
    ) -> bool {
        return false !== mb_strpos(haystack, needle);
    }
}
