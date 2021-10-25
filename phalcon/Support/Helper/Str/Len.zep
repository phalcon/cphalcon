
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
 * Class Len
 *
 * @package Phalcon\Support\Str
 */
class Len
{
    /**
     * Calculates the length of the string using mbstring
     *
     * @param string $text
     * @param string $encoding
     *
     * @return int
     */
    public function __invoke(string text, string encoding = "UTF-8") -> int
    {
        return mb_strlen(text, encoding);
    }
}
