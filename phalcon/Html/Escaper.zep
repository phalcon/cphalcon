
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html;

use Phalcon\Di\DiInterface;
use Phalcon\Html\Escaper\EscaperInterface;

/**
 * Phalcon\Html\Escaper
 *
 * Escapes different kinds of text securing them. By using this component you
 * may prevent XSS attacks.
 *
 * This component only works with UTF-8. The PREG extension needs to be compiled
 * with UTF-8 support.
 *
 *```php
 * $escaper = new \Phalcon\Html\Escaper();
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
    protected encoding = "utf-8" { get };

    /**
     * @var int
     */
    protected flags = 3 { get };

    /**
     * Escapes a HTML attribute string
     *
     * @param string $input
     *
     * @return string
     */
    public function attributes(string input) -> string
    {
        return htmlspecialchars(
            input,
            ENT_QUOTES,
            this->encoding,
            this->doubleEncode
        );
    }

    /**
     * Escape CSS strings by replacing non-alphanumeric chars by their
     * hexadecimal escaped representation
     *
     * @param string $input
     *
     * @return string
     */
    public function css(string input) -> string
    {
        /**
         * Normalize encoding to UTF-32
         * Escape the string
         */
        return this->doEscapeCss(this->normalizeEncoding(input));
    }

    /**
     * Detect the character encoding of a string to be handled by an encoder.
     * Special-handling for chr(172) and chr(128) to chr(159) which fail to be
     * detected by mb_detect_encoding()
     *
     * @param string $input
     *
     * @return string|null
     */
    final public function detectEncoding(string input) -> string | null
    {
        var charset;

        /**
        * Check if charset is ASCII or ISO-8859-1
        */
        let charset = phalcon_is_basic_charset(input);

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
            if (false !== mb_detect_encoding(input, charset, true)) {
                return charset;
            }
        }

        /**
         * Fallback to global detection
         */
        return mb_detect_encoding(input);
    }

    /**
     * Escape CSS strings by replacing non-alphanumeric chars by their
     * hexadecimal escaped representation
     *
     * @param string $input
     *
     * @return string
     * @deprecated
     */
    public function escapeCss(string input) -> string
    {
        return this->css(input);
    }

    /**
     * Escape JavaScript strings by replacing non-alphanumeric chars by their
     * hexadecimal escaped representation
     *
     * @param string $input
     *
     * @return string
     * @deprecated
     */
    public function escapeJs(string input) -> string
    {
        return this->js(input);
    }

    /**
     * Escapes a HTML string. Internally uses htmlspecialchars
     *
     * @param string|null $input
     *
     * @return string
     * @deprecated
     */
    public function escapeHtml(string input = null) -> string
    {
        return this->html((string) input);
    }

    /**
     * Escapes a HTML attribute string
     *
     * @param string|null $input
     *
     * @return string
     * @deprecated
     */
    public function escapeHtmlAttr(string input = null) -> string
    {
        return this->attributes((string) input);
    }

    /**
     * Escapes a URL. Internally uses rawurlencode
     *
     * @param string $input
     *
     * @return string
     * @deprecated
     */
    public function escapeUrl(string input) -> string
    {
        return this->url(input);
    }

    /**
     * Escapes a HTML string. Internally uses htmlspecialchars
     *
     * @param string|null $input
     *
     * @return string
     */
    public function html(string input = null) -> string
    {
        if !input {
            return "";
        }
        return htmlspecialchars(
            input,
            this->flags,
            this->encoding,
            this->doubleEncode
        );
    }

    /**
     * Escape javascript strings by replacing non-alphanumeric chars by their
     * hexadecimal escaped representation
     *
     * @param string $input
     *
     * @return string
     */
    public function js(string input) -> string
    {
        /**
         * Normalize encoding to UTF-32
         * Escape the string
         */
        return this->doEscapeJs(this->normalizeEncoding(input));
    }

    /**
     * Utility to normalize a string's encoding to UTF-32.
     *
     * @param string $input
     *
     * @return string
     */
    final public function normalizeEncoding(string input) -> string
    {
        /**
         * Convert to UTF-32 (4 byte characters, regardless of actual number of
         * bytes in the character).
         */
        return mb_convert_encoding(
            input,
            "UTF-32",
            this->detectEncoding(input)
        );
    }

    /**
     * Sets the double_encode to be used by the escaper
     *
     *```php
     * $escaper->setDoubleEncode(false);
     *```
     *
     * @param bool $doubleEncode
     */
    public function setDoubleEncode(bool doubleEncode) -> <Escaper>
    {
        let this->doubleEncode = doubleEncode;

        return this;
    }

    /**
     * Sets the encoding to be used by the escaper
     *
     *```php
     * $escaper->setEncoding("utf-8");
     *```
     *
     * @param string $encoding
     */
    public function setEncoding(string encoding) -> <EscaperInterface>
    {
        let this->encoding = encoding;

        return this;
    }

    /**
     * Sets the HTML quoting type for htmlspecialchars
     *
     *```php
     * $escaper->setFlags(ENT_XHTML);
     *```
     *
     * @param int $flags
     */
    public function setFlags(int flags) -> <Escaper>
    {
        let this->flags = flags;

        return this;
    }

    /**
     * Sets the HTML quoting type for htmlspecialchars
     *
     *```php
     * $escaper->setHtmlQuoteType(ENT_XHTML);
     *```
     *
     * @param int $flags
     * @deprecated
     */
    public function setHtmlQuoteType(int flags) -> <EscaperInterface>
    {
        return this->setFlags(flags);
    }

    /**
     * Escapes a URL. Internally uses rawurlencode
     *
     * @param string $input
     *
     * @return string
     */
    public function url(string input) -> string
    {
        return rawurlencode(input);
    }

    /**
     * @param string $input
     *
     * @return string
     */
    private function doEscapeCss(string input) -> string
    {
        return phalcon_escape_css(input);
    }

    /**
     * @param string $input
     *
     * @return string
     */
    private function doEscapeJs(string $input) -> string
    {
        return phalcon_escape_js(input);
    }
}
