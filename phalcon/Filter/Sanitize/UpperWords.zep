
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
 * Phalcon\Filter\Sanitize\UpperWords
 *
 * Sanitizes a value to uppercase the first character of each word
 */
class UpperWords
{
    /**
     * @param string $input The text to sanitize
     *
     * @return false|string|string[]
     */
    public function __invoke(string! input)
    {
        if true === function_exists("mb_convert_case") {
            return mb_convert_case(input, MB_CASE_TITLE, "UTF-8");
        }

        return ucwords(utf8_decode(input));
    }
}
