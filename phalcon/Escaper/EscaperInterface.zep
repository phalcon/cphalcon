
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Escaper;

/**
 * Interface for Phalcon\Escaper
 */
interface EscaperInterface
{
    /**
     * Escape CSS strings by replacing non-alphanumeric chars by their
     * hexadecimal representation
     */
    public function escapeCss(string css) -> string;

    /**
     * Escapes a HTML string
     */
    public function escapeHtml(string text) -> string;

    /**
     * Escapes a HTML attribute string
     */
    public function escapeHtmlAttr(string text) -> string;

    /**
     * Escape Javascript strings by replacing non-alphanumeric chars by their
     * hexadecimal representation
     */
    public function escapeJs(string js) -> string;

    /**
     * Escapes a URL. Internally uses rawurlencode
     */
    public function escapeUrl(string url) -> string;

    /**
     * Returns the internal encoding used by the escaper
     */
    public function getEncoding() -> string;

    /**
     * Sets the encoding to be used by the escaper
     */
    public function setEncoding(string encoding) -> void;

    /**
     * Sets the HTML quoting type for htmlspecialchars
     */
    public function setHtmlQuoteType(int quoteType) -> void;
}
