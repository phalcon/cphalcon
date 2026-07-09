
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Traits\Php;

/**
 * Multibyte case conversion wrapper method
 */
trait MbCaseTrait
{
    /**
     * Converts the case of a string using `mb_convert_case()` when the
     * `mbstring` extension is available, otherwise applies the passed fallback
     * function to the `utf8_decode()`d input.
     *
     * @param string $input
     * @param int    $mode
     * @param string $fallback
     *
     * @return string
     *
     * @link https://php.net/manual/en/function.mb-convert-case.php
     */
    protected static function phpMbConvertCase(string input, int mode, string fallback) -> string
    {
        if true === function_exists("mb_convert_case") {
            return mb_convert_case(input, mode, "UTF-8");
        }

        return {fallback}(utf8_decode(input));
    }
}
