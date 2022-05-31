
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
 * Returns `true` if the given string is a palindrome, `false` otherwise.
 */
class IsPalindrome
{
    /**
     * @param string $text
     *
     * @return bool
     */
    public function __invoke(string text) -> bool
    {
        return strrev(text) === text;
    }
}
