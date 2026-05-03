
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
 * Shared base for the per-context escaper objects. Holds the encoding,
 * htmlspecialchars flag, and double-encode toggle, plus the encoding
 * detection / normalization utilities used by the CSS and JS escapers.
 *
 * Each concrete context (`HtmlEscaper`, `AttributeEscaper`, `CssEscaper`,
 * `JsEscaper`, `UrlEscaper`) extends this so that callers can configure
 * one context without affecting the others.
 *
 * @property bool   $doubleEncode
 * @property string $encoding
 * @property int    $flags
 */
abstract class AbstractEscaper
{
    /**
     * @var bool
     */
    protected doubleEncode = true;

    /**
     * @var string
     */
    protected encoding = "utf-8";

    /**
     * ENT_QUOTES | ENT_SUBSTITUTE | ENT_HTML401
     *
     * @var int
     */
    protected flags = 11;

    /**
     * Detects the character encoding of a string. Special-handling for
     * chr(172) and chr(128) to chr(159) which fail to be detected by
     * `mb_detect_encoding()`.
     *
     * @param string $input
     *
     * @return string|null
     */
    final public function detectEncoding(string input) -> string | null
    {
        var charset;

        let charset = phalcon_is_basic_charset(input);
        if typeof charset == "string" {
            return charset;
        }

        if !function_exists("mb_detect_encoding") {
            return null;
        }

        for charset in ["UTF-32", "UTF-8", "ISO-8859-1", "ASCII"] {
            if (false !== mb_detect_encoding(input, charset, true)) {
                return charset;
            }
        }

        return mb_detect_encoding(input);
    }

    /**
     * @return bool
     */
    public function getDoubleEncode() -> bool
    {
        return this->doubleEncode;
    }

    /**
     * @return string
     */
    public function getEncoding() -> string
    {
        return this->encoding;
    }

    /**
     * @return int
     */
    public function getFlags() -> int
    {
        return this->flags;
    }

    /**
     * Normalizes a string's encoding to UTF-32, used by the CSS and JS
     * escapers before invoking the C-level escape routines.
     *
     * @param string $input
     *
     * @return string
     */
    final public function normalizeEncoding(string input) -> string
    {
        return mb_convert_encoding(
            input,
            "UTF-32",
            this->detectEncoding(input)
        );
    }

    /**
     * @param bool $doubleEncode
     */
    public function setDoubleEncode(bool doubleEncode)
    {
        let this->doubleEncode = doubleEncode;

        return this;
    }

    /**
     * @param string $encoding
     */
    public function setEncoding(string encoding)
    {
        let this->encoding = encoding;

        return this;
    }

    /**
     * @param int $flags
     */
    public function setFlags(int flags)
    {
        let this->flags = flags;

        return this;
    }
}
