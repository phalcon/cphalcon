
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

namespace Phalcon\Html\Helper;

use Phalcon\Contracts\Html\HtmlTypes;
use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Mvc\Url\UrlInterface;
use Phalcon\Traits\Support\Helper\Str\InterpolateTrait;

/**
 * This component offers an easy way to create breadcrumbs for your application.
 * The resulting HTML when calling `render()` will have each breadcrumb enclosed
 * in `<li>` tags, while the whole string is enclosed in `<nav>` and `<ol>` tags.
 *
 * @phpstan-import-type html_breadcrumb_attributes from HtmlTypes
 * @phpstan-import-type html_breadcrumb_data from HtmlTypes
 * @phpstan-import-type html_breadcrumb_element from HtmlTypes
 * @phpstan-import-type html_breadcrumb_template from HtmlTypes
 */
class Breadcrumbs extends AbstractHelper
{
    use InterpolateTrait;

    /**
     * @phpstan-var html_breadcrumb_attributes
     */
    private array attributes = [];
    /**
     * Keeps all the breadcrumbs.
     *
     * @var html_breadcrumb_data
     */
    private array data = [];
    /**
     * Link prefix prepended to every non-empty link during rendering.
     * Auto-populated from the Url service when one is injected.
     */
    private string prefix = "";
    /**
     * Crumb separator.
     */
    private string separator = "<li>/</li>";
    /**
     * The HTML template to use to render the breadcrumbs.
     *
     * @phpstan-var html_breadcrumb_template
     */
    private template = [
        "main": "
<nav%attributes%>
    <ol>
%items%
    </ol>
</nav>",
        "line": "<li%attributes%><a href=\"%link%\">%icon%%text%</a></li>",
        "last": "<li><span%attributes%>%text%</span></li>"
    ];

    /**
     * Optional Url service used to resolve links via get().
     * When set, takes priority over the string prefix.
     */
    private ?<UrlInterface> url = null;

    /**
     * AbstractHelper constructor.
     */
    public function __construct(
        <EscaperInterface> escaper,
        <UrlInterface> url = null
    ) {
        parent::__construct(escaper);

        let this->url = url;
    }

    /**
     * Sets the indent and delimiter and returns the object back.
     */
    public function __invoke(
        string indent = "    ",
        string delimiter = null
    ) -> <static> {
        let this->delimiter = delimiter === null ? PHP_EOL : delimiter,
            this->indent    = indent;

        return this;
    }

    /**
     * Adds a new crumb.
     *
     * ```php
     * // Adding a crumb with a link
     * $breadcrumbs->add("Home", "/");
     *
     * // Adding a crumb with added attributes
     * $breadcrumbs->add("Home", "/", ["class" => "main"]);
     *
     * // Adding a crumb without a link (normally the last one)
     * $breadcrumbs->add("Users");
     * ```
     *
     * @phpstan-param html_breadcrumb_attributes $attributes
     */
    public function add(
        string text,
        string link = "",
        string icon = "",
        array attributes = []
    ) -> <static> {
        var count;

        let count = count(this->data) + 1;
        let this->data[count] = [
            "attributes": attributes,
            "icon"      : icon,
            "link"      : link,
            "text"      : text
        ];

        return this;
    }

    /**
     * Clears the crumbs
     *
     * ```php
     * $breadcrumbs->clear()
     * ```
     */
    public function clear() -> void
    {
        let this->data = [];
    }

    /**
     * Clear the attributes of the parent element
     */
    public function clearAttributes() -> <static>
    {
        let this->attributes = [];

        return this;
    }

    /**
     * Get the attributes of the parent element
     *
     * @phpstan-return html_breadcrumb_attributes
     */
    public function getAttributes() -> array
    {
        return this->attributes;
    }

    /**
     * Returns the link prefix.
     */
    public function getPrefix() -> string
    {
        return this->prefix;
    }

    /**
     * Returns the separator.
     */
    public function getSeparator() -> string
    {
        return this->separator;
    }

    /**
     * Return the current template.
     *
     * @phpstan-return html_breadcrumb_template
     */
    public function getTemplate() -> array
    {
        return this->template;
    }

    /**
     * Removes crumb by url.
     *
     * ```php
     * // Remove the second element
     * $breadcrumbs->remove(2);
     * ```
     */
    public function remove(int index) -> void
    {
        var elements;

        let elements = this->data;
        unset elements[index];

        let this->data = elements;
    }

    /**
     * Renders and outputs breadcrumbs based on previously set template.
     *
     * ```php
     * echo $breadcrumbs->render();
     * ```
     */
    public function render() -> string
    {
        var data, lastUrl, lastElement, element;
        array output;
        /*
         * Early exit for empty data
         */
        if empty this->data {
            return "";
        }

        let data        = this->data,
            output      = [],
            lastUrl     = array_key_last(data),
            lastElement = data[lastUrl];

        unset data[lastUrl];

        for element in data {
            let output[] = this->getLink(this->template["line"], element);
        }

        /*
         * Last element
         */
        let output[] = this->getLink(this->template["last"], lastElement);

        return this->toInterpolate(
            this->template["main"],
            [
                "attributes" : this->processAttributes(this->attributes),
                "delimiter"  : this->delimiter,
                "indent"     : this->indent,
                "items"      : implode(
                    this->indent . this->separator . this->delimiter,
                    output
                )
            ]
        );
    }

    /**
     * Set the attributes for the parent element
     *
     * @phpstan-param html_breadcrumb_attributes $attributes
     */
    public function setAttributes(array attributes) -> <static>
    {
        let this->attributes = attributes;

        return this;
    }

    /**
     * Set the link prefix prepended to every non-empty link during rendering.
     * When a Url service was injected, calling this method replaces it.
     */
    public function setPrefix(string prefix) -> <static>
    {
        let this->prefix = prefix,
            this->url    = null;

        return this;
    }

    /**
     * Set the separator
     */
    public function setSeparator(string separator) -> <static>
    {
        let this->separator = separator;

        return this;
    }

    /**
     * Set the HTML template
     */
    public function setTemplate(
        string main,
        string line,
        string last
    ) -> <static> {
        let this->template = [
            "main": main,
            "line": line,
            "last": last
        ];

        return this;
    }

    /**
     * Returns the internal breadcrumbs array
     *
     * @phpstan-return html_breadcrumb_data
     */
    public function toArray() -> array
    {
        return this->data;
    }

    /**
     * @phpstan-param html_breadcrumb_element $element
     */
    private function getLink(
        string template,
        array element
    ) -> string {
        var link;

        if !empty element["link"] && this->url !== null {
            let link = this->url->get(element["link"]);
        } elseif !empty element["link"] && !empty this->prefix {
            let link = this->prefix . element["link"];
        } else {
            let link = element["link"];
        }

        return this->indent
            . this->toInterpolate(
                template,
                [
                    "attributes" : this->processAttributes(element["attributes"]),
                    "icon"       : element["icon"],
                    "text"       : this->escaper->html(element["text"]),
                    "link"       : this->escaper->attributes(link)
                ]
            )
            .this->delimiter;
    }

    /**
     * Processes attributes
     *
     * @phpstan-param html_breadcrumb_attributes $attributes
     */
    private function processAttributes(array attributes) -> string
    {
        var attributesRendered;

        let attributesRendered = this->renderAttributes(attributes);

        return rtrim(!empty(attributesRendered) ? " " . attributesRendered : "");
    }
}
