
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
 * Interface for Phalcon\Html\Escaper.
 *
 * This declares the stable context-escaping surface. The concrete
 * {@see \Phalcon\Html\Escaper} facade also exposes members that are not part
 * of this contract - `setDoubleEncode()`, `getFlags()`, and the per-context
 * sub-escaper getters/setters (`getHtmlEscaper()`, `setAttributeEscaper()`,
 * and the rest). Type against the concrete class to reach those.
 */
interface EscaperInterface
{
    /**
     * Escapes a HTML attribute string.
     *
     * The concrete {@see \Phalcon\Html\Escaper} also accepts an array of
     * attribute pairs and tolerates `null`: an array is rendered as escaped
     * `key="value"` pairs, `null` and `false` values are skipped, and `true`
     * renders as a bare key. Callers typed against this interface pass a
     * string. The widened signature lands in the next major.
     *
     * @param string $input
     *
     * @return string
     */
    public function attributes(string input) -> string;

    /**
     * Escape CSS strings by replacing non-alphanumeric chars by their
     * hexadecimal representation
     *
     * @param string $input
     *
     * @return string
     */
    public function css(string input) -> string;

    /**
     * Returns the internal encoding used by the escaper
     *
     * @return string
     */
    public function getEncoding() -> string;

    /**
     * Escapes a HTML string.
     *
     * The concrete {@see \Phalcon\Html\Escaper} tolerates `null`, returning an
     * empty string for it. The nullable signature lands in the next major.
     *
     * @param string $input
     *
     * @return string
     */
    public function html(string input) -> string;

    /**
     * Escape Javascript strings by replacing non-alphanumeric chars by their
     * hexadecimal representation
     *
     * @param string $input
     *
     * @return string
     */
    public function js(string input) -> string;

    /**
     * Sets the encoding to be used by the escaper
     *
     * @param string $encoding
     */
    public function setEncoding(string encoding) -> <EscaperInterface>;

    /**
     * Sets the HTML quoting type for htmlspecialchars
     *
     * @param int $flags
     */
    public function setFlags(int flags) -> <EscaperInterface>;

    /**
     * Escapes a URL. Internally uses rawurlencode
     *
     * @param string $input
     *
     * @return string
     */
    public function url(string input) -> string;
}
