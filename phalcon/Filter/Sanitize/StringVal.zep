
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Sanitize;

/**
 * Sanitizes a value to string
 */
class StringVal
{
    /**
     * @param string $input The text to sanitize
     * @param int    $flags The flags for `htmlspecialchars()`
     *
     * @return string
     */
    public function __invoke(string input, int flags = 11) -> string
    {
        return htmlspecialchars(input, flags);
    }
}
