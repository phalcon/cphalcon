
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
 * Escapes a string for use as HTML body content via `htmlspecialchars`.
 */
class HtmlEscaper extends AbstractEscaper
{
    /**
     * @param string|null $input
     *
     * @return string
     */
    public function __invoke(string input = null) -> string
    {
        return this->escape(input);
    }

    /**
     * @param string|null $input
     *
     * @return string
     */
    public function escape(string input = null) -> string
    {
        if null === input {
            return "";
        }

        return htmlspecialchars(
            input,
            this->flags,
            this->encoding,
            this->doubleEncode
        );
    }
}
