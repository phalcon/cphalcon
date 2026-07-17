
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
     * Converts the case of a string using `mb_convert_case()`
     *
     * @param string $input
     * @param int    $mode
     *
     * @return string
     *
     * @link https://php.net/manual/en/function.mb-convert-case.php
     */
    protected static function phpMbConvertCase(string input, int mode) -> string
    {
        return mb_convert_case(input, mode, "UTF-8");
    }
}
