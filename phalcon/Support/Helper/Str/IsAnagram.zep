
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

/**
 * Class IsAnagram
 *
 * @package Phalcon\Support\Str
 */
class IsAnagram
{
    /**
     * Compare two strings and returns true if both strings are anagram,
     * false otherwise.
     *
     * @param string $first
     * @param string $second
     *
     * @return bool
     */
    public function __invoke(string first, string second) -> bool
    {
        return count_chars(first, 1) === count_chars(second, 1);
    }
}
