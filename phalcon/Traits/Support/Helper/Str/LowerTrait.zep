
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
 * Lowercases a string using mbstring
 */
trait LowerTrait
{
    /**
     * @param string $text
     * @param string $encoding
     *
     * @return string
     */
    protected static function toLower(
        string text,
        string encoding = "UTF-8"
    ) -> string {
        return mb_convert_case(text, MB_CASE_LOWER, encoding);
    }
}
