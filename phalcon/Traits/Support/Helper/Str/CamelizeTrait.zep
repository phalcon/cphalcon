
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
 * Converts strings to upperCamelCase or lowerCamelCase
 */
trait CamelizeTrait
{
    /**
     * @param string $text
     * @param string $delimiters
     * @param bool   $lowerFirst
     *
     * @return string
     */
    public static function toCamelize(
        string text,
        string delimiters = "-_",
        bool lowerFirst = false
    ) -> string {
        var result;

        let result = camelize(text, delimiters);

        if (lowerFirst === true) {
            let result = lcfirst(result);
        }

        return result;
    }
}
