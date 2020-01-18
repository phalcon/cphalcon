
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
     * @var string input The text to sanitize
     */
    public function __invoke(string! input)
    {
        return mb_convert_case(input, MB_CASE_TITLE, "UTF-8");
    }
}
