
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\Di\DiInterface;
use Phalcon\Escaper\EscaperInterface;
use Phalcon\Escaper\Exception;

/**
 * Phalcon\Escaper
 *
 * Escapes different kinds of text securing them. By using this component you
 * may prevent XSS attacks.
 *
 * This component only works with UTF-8. The PREG extension needs to be compiled
 * with UTF-8 support.
 *
 *```php
 * $escaper = new \Phalcon\Escaper();
 *
 * $escaped = $escaper->escapeCss("font-family: <Verdana>");
 *
 * echo $escaped; // font\2D family\3A \20 \3C Verdana\3E
 *```
 */
class Escaper implements EscaperInterface
{
    /**
     * @var bool
     */
    protected doubleEncode = true;

    /**
     * @var string
     */
    protected encoding = "utf-8";

    protected htmlEscapeMap = null;

    protected htmlQuoteType = 3;

    /**
     * Detect the character encoding of a string to be handled by an encoder.
     * Special-handling for chr(172) and chr(128) to chr(159) which fail to be
     * detected by mb_detect_encoding()
     */
    final public function detectEncoding(string str) -> string | null
    {
        var charset;

        /**
        * Check if charset is ASCII or ISO-8859-1
        */
        let charset = phalcon_is_basic_charset(str);

        if typeof charset == "string" {
            return charset;
        }

        /**
        * We require mbstring extension here
        */
        if !function_exists("mb_detect_encoding") {
            return null;
        }

        /**
         * Strict encoding detection with fallback to non-strict detection.
         * Check encoding
         */
        for charset in ["UTF-32", "UTF-8", "ISO-8859-1", "ASCII"] {
            if mb_detect_encoding(str, charset, true) {
                return charset;
            }
        }

        /**
         * Fallback to global detection
         */
        return mb_detect_encoding(str);
    }

    /**
     * Escape CSS strings by replacing non-alphanumeric chars by their
     * hexadecimal escaped representation
     */
    public function escapeCss(string css) -> string
    {
        /**
         * Normalize encoding to UTF-32
         * Escape the string
         */
        return phalcon_escape_css(
            this->normalizeEncoding(css)
        );
    }

    /**
     * Escape javascript strings by replacing non-alphanumeric chars by their
     * hexadecimal escaped representation
     */
    public function escapeJs(string js) -> string
    {
        /**
         * Normalize encoding to UTF-32
         * Escape the string
         */
        return phalcon_escape_js(
            this->normalizeEncoding(js)
        );
    }

    /**
     * Escapes a HTML string. Internally uses htmlspecialchars
     */
    public function escapeHtml(string text = null) -> string
    {
        return htmlspecialchars(
            text,
            this->htmlQuoteType,
            this->encoding,
            this->doubleEncode
        );
    }

    /**
     * Escapes a HTML attribute string
     */
    public function escapeHtmlAttr(string attribute = null) -> string
    {
        return htmlspecialchars(
            attribute,
            ENT_QUOTES,
            this->encoding,
            this->doubleEncode
        );
    }

    /**
     * Escapes a URL. Internally uses rawurlencode
     */
    public function escapeUrl(string url) -> string
    {
        return rawurlencode(url);
    }

    /**
     * Returns the internal encoding used by the escaper
     */
    public function getEncoding() -> string
    {
        return this->encoding;
    }

    /**
     * Utility to normalize a string's encoding to UTF-32.
     */
    final public function normalizeEncoding(string str) -> string
    {
        /**
         * mbstring is required here
         */
        if unlikely !function_exists("mb_convert_encoding") {
            throw new Exception("Extension 'mbstring' is required");
        }

        /**
         * Convert to UTF-32 (4 byte characters, regardless of actual number of
         * bytes in the character).
         */
        return mb_convert_encoding(
            str,
            "UTF-32",
            this->detectEncoding(str)
        );
    }

    /**
     * Sets the double_encode to be used by the escaper
     *
     *```php
     * $escaper->setDoubleEncode(false);
     *```
     */
    public function setDoubleEncode(bool doubleEncode) -> void
    {
        let this->doubleEncode = doubleEncode;
    }

    /**
     * Sets the encoding to be used by the escaper
     *
     *```php
     * $escaper->setEncoding("utf-8");
     *```
     */
    public function setEncoding(string encoding) -> void
    {
        let this->encoding = encoding;
    }

    /**
     * Sets the HTML quoting type for htmlspecialchars
     *
     *```php
     * $escaper->setHtmlQuoteType(ENT_XHTML);
     *```
     */
    public function setHtmlQuoteType(int quoteType) -> void
    {
        let this->htmlQuoteType = quoteType;
    }
}
