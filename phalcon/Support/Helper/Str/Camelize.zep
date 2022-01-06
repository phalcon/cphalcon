
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
 * Converts strings to upperCamelCase or lowerCamelCase
 */
class Camelize extends PascalCase
{
    /**
     * @param string      $text
     * @param string|null $delimiters
     * @param bool        $lowerFirst
     *
     * @return string
     */
    public function __invoke(
        string text,
        string delimiters = null,
        bool lowerFirst = false
    ) -> string {
        var result;

        let result = parent::__invoke(text, delimiters);

        if (lowerFirst === true) {
            let result = lcfirst(result);
        }

        return result;
    }
}
