
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */

namespace Phalcon\Html\Escaper;

/**
 * Escapes a string for use inside a JavaScript context by replacing
 * non-alphanumeric characters with their hexadecimal escape sequence.
 */
class JsEscaper extends AbstractEscaper
{
    /**
     * @param string $input
     *
     * @return string
     */
    public function __invoke(string input) -> string
    {
        return this->escape(input);
    }

    /**
     * @param string $input
     *
     * @return string
     */
    public function escape(string input) -> string
    {
        var result;

        if unlikely empty input {
            return "";
        }

        /**
         * The C escaper keeps a backslash as is. Double it first so it cannot
         * escape the delimiter of the surrounding JavaScript string.
         */
        let result = this->doEscapeJs(
            this->normalizeEncoding(str_replace("\\", "\\\\", input))
        );

        if typeof result != "string" {
            return "";
        }

        return result;
    }

    /**
     * @param string $input
     *
     * @return string
     */
    private function doEscapeJs(string input) -> string
    {
        return phalcon_escape_js(input);
    }
}
