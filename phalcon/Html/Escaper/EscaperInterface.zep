
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Escaper;

/**
 * Interface for Phalcon\Html\Escaper
 */
interface EscaperInterface
{
    /**
     * Escapes a HTML attribute string
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
     * Escapes a HTML string
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
    public function setHtmlQuoteType(int flags) -> <EscaperInterface>;

    /**
     * Escapes a URL. Internally uses rawurlencode
     *
     * @param string $input
     *
     * @return string
     */
    public function url(string input) -> string;
}
