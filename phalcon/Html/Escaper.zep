
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html;

use Phalcon\Html\Escaper\AttributeEscaper;
use Phalcon\Html\Escaper\CssEscaper;
use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Html\Escaper\HtmlEscaper;
use Phalcon\Html\Escaper\JsEscaper;
use Phalcon\Html\Escaper\UrlEscaper;

/**
 * Phalcon\Html\Escaper
 *
 * Escapes different kinds of text securing them. By using this component you
 * may prevent XSS attacks.
 *
 * The class is a façade over five per-context escapers (`HtmlEscaper`,
 * `AttributeEscaper`, `CssEscaper`, `JsEscaper`, `UrlEscaper`). Each can be
 * retrieved via the matching `getXxxEscaper()` accessor and substituted via
 * the matching `setXxxEscaper()` setter. The legacy `setEncoding`,
 * `setFlags`, and `setDoubleEncode` continue to fan out to all sub-objects
 * so existing code keeps working.
 *
 * This component only works with UTF-8. The PREG extension needs to be compiled
 * with UTF-8 support.
 *
 *```php
 * $escaper = new \Phalcon\Html\Escaper();
 *
 * $escaped = $escaper->css("font-family: <Verdana>");
 *
 * echo $escaped; // font\2D family\3A \20 \3C Verdana\3E
 *```
 *
 * @property AttributeEscaper $attributeEscaper
 * @property CssEscaper       $cssEscaper
 * @property HtmlEscaper      $htmlEscaper
 * @property JsEscaper        $jsEscaper
 * @property UrlEscaper       $urlEscaper
 */
class Escaper implements EscaperInterface
{
    /**
     * @var AttributeEscaper
     */
    protected attributeEscaper;

    /**
     * @var CssEscaper
     */
    protected cssEscaper;

    /**
     * @var HtmlEscaper
     */
    protected htmlEscaper;

    /**
     * @var JsEscaper
     */
    protected jsEscaper;

    /**
     * @var UrlEscaper
     */
    protected urlEscaper;

    public function __construct()
    {
        let this->attributeEscaper = new AttributeEscaper(),
            this->cssEscaper       = new CssEscaper(),
            this->htmlEscaper      = new HtmlEscaper(),
            this->jsEscaper        = new JsEscaper(),
            this->urlEscaper       = new UrlEscaper();
    }

    /**
     * Escapes a HTML attribute string or array. Delegates to the configured
     * `AttributeEscaper`.
     *
     * @param array|string $input
     *
     * @return string
     */
    public function attributes(var input) -> string
    {
        return this->attributeEscaper->escape(input);
    }

    /**
     * Escape CSS strings. Delegates to the configured `CssEscaper`.
     *
     * @param string $input
     *
     * @return string
     */
    public function css(string input) -> string
    {
        return this->cssEscaper->escape(input);
    }

    /**
     * @param string $input
     *
     * @return string|null
     */
    final public function detectEncoding(string input) -> string | null
    {
        return this->htmlEscaper->detectEncoding(input);
    }

    /**
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
     * @return AttributeEscaper
     */
    public function getAttributeEscaper() -> <AttributeEscaper>
    {
        return this->attributeEscaper;
    }

    /**
     * @return CssEscaper
     */
    public function getCssEscaper() -> <CssEscaper>
    {
        return this->cssEscaper;
    }

    /**
     * @return string
     */
    public function getEncoding() -> string
    {
        return this->htmlEscaper->getEncoding();
    }

    /**
     * @return int
     */
    public function getFlags() -> int
    {
        return this->htmlEscaper->getFlags();
    }

    /**
     * @return HtmlEscaper
     */
    public function getHtmlEscaper() -> <HtmlEscaper>
    {
        return this->htmlEscaper;
    }

    /**
     * @return JsEscaper
     */
    public function getJsEscaper() -> <JsEscaper>
    {
        return this->jsEscaper;
    }

    /**
     * @return UrlEscaper
     */
    public function getUrlEscaper() -> <UrlEscaper>
    {
        return this->urlEscaper;
    }

    /**
     * Escapes a HTML string. Delegates to the configured `HtmlEscaper`.
     *
     * @param string|null $input
     *
     * @return string
     */
    public function html(string input = null) -> string
    {
        return this->htmlEscaper->escape(input);
    }

    /**
     * Escape javascript strings. Delegates to the configured `JsEscaper`.
     *
     * @param string $input
     *
     * @return string
     */
    public function js(string input) -> string
    {
        return this->jsEscaper->escape(input);
    }

    /**
     * @param string $input
     *
     * @return string
     */
    final public function normalizeEncoding(string input) -> string
    {
        return this->htmlEscaper->normalizeEncoding(input);
    }

    /**
     * @param AttributeEscaper $escaper
     *
     * @return Escaper
     */
    public function setAttributeEscaper(<AttributeEscaper> escaper) -> <Escaper>
    {
        let this->attributeEscaper = escaper;

        return this;
    }

    /**
     * @param CssEscaper $escaper
     *
     * @return Escaper
     */
    public function setCssEscaper(<CssEscaper> escaper) -> <Escaper>
    {
        let this->cssEscaper = escaper;

        return this;
    }

    /**
     * Sets the double_encode flag. Fans out to all sub-objects.
     *
     * @param bool $doubleEncode
     */
    public function setDoubleEncode(bool doubleEncode) -> <Escaper>
    {
        this->attributeEscaper->setDoubleEncode(doubleEncode);
        this->cssEscaper->setDoubleEncode(doubleEncode);
        this->htmlEscaper->setDoubleEncode(doubleEncode);
        this->jsEscaper->setDoubleEncode(doubleEncode);
        this->urlEscaper->setDoubleEncode(doubleEncode);

        return this;
    }

    /**
     * Sets the encoding. Fans out to all sub-objects.
     *
     * @param string $encoding
     */
    public function setEncoding(string encoding) -> <EscaperInterface>
    {
        this->attributeEscaper->setEncoding(encoding);
        this->cssEscaper->setEncoding(encoding);
        this->htmlEscaper->setEncoding(encoding);
        this->jsEscaper->setEncoding(encoding);
        this->urlEscaper->setEncoding(encoding);

        return this;
    }

    /**
     * Sets the htmlspecialchars flags. Fans out to all sub-objects.
     *
     * @param int $flags
     */
    public function setFlags(int flags) -> <EscaperInterface>
    {
        this->attributeEscaper->setFlags(flags);
        this->cssEscaper->setFlags(flags);
        this->htmlEscaper->setFlags(flags);
        this->jsEscaper->setFlags(flags);
        this->urlEscaper->setFlags(flags);

        return this;
    }

    /**
     * @param HtmlEscaper $escaper
     *
     * @return Escaper
     */
    public function setHtmlEscaper(<HtmlEscaper> escaper) -> <Escaper>
    {
        let this->htmlEscaper = escaper;

        return this;
    }

    /**
     * @param int $flags
     *
     * @deprecated
     */
    public function setHtmlQuoteType(int flags) -> <EscaperInterface>
    {
        return this->setFlags(flags);
    }

    /**
     * @param JsEscaper $escaper
     *
     * @return Escaper
     */
    public function setJsEscaper(<JsEscaper> escaper) -> <Escaper>
    {
        let this->jsEscaper = escaper;

        return this;
    }

    /**
     * @param UrlEscaper $escaper
     *
     * @return Escaper
     */
    public function setUrlEscaper(<UrlEscaper> escaper) -> <Escaper>
    {
        let this->urlEscaper = escaper;

        return this;
    }

    /**
     * Escapes a URL. Delegates to the configured `UrlEscaper`.
     *
     * @param string $input
     *
     * @return string
     */
    public function url(string input) -> string
    {
        return this->urlEscaper->escape(input);
    }
}
