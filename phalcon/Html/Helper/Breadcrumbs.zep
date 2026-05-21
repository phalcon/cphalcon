
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

use Phalcon\Html\Escaper\EscaperInterface;
use Phalcon\Mvc\Url\UrlInterface;
use Phalcon\Support\Helper\Str\Interpolate;

/**
 * This component offers an easy way to create breadcrumbs for your application.
 * The resulting HTML when calling `render()` will have each breadcrumb enclosed
 * in `<li>` tags, while the whole string is enclosed in `<nav>` and `<ol>` tags.
 *
 * @phpstan-type TTemplate array{
 *      main: string,
 *      line: string,
 *      last: string
 *  }
 * @phpstan-type TElement array{
 *      attributes: array<string, string>,
 *      icon: string,
 *      link: string,
 *      text: string
 *  }
 */
class Breadcrumbs extends AbstractHelper
{
    /**
     * @var array<string, string>
     */
    private attributes = [];
    /**
     * Link prefix prepended to every non-empty link during rendering.
     * Auto-populated from the Url service when one is injected.
     *
     * @var string
     */
    private prefix = "";
    /**
     * Optional Url service used to resolve links via get().
     * When set, takes priority over the string prefix.
     *
     * @var UrlInterface|null
     */
    private url = null;
    /**
     * Keeps all the breadcrumbs.
     *
     * @var array<int, TElement>
     */
    private data = [];
    /**
     * Crumb separator.
     *
     * @var string
     */
    private separator = "<li>/</li>";
    /**
     * The HTML template to use to render the breadcrumbs.
     *
     * @var TTemplate
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
     * The HTML template to use to render the breadcrumbs.
     *
     * @var Interpolate
     */
    private interpolator;

    /**
     * AbstractHelper constructor.
     *
     * @param EscaperInterface $escaper
     * @param UrlInterface|null $url
     */
    public function __construct(<EscaperInterface> escaper, <UrlInterface> url = null)
    {
        parent::__construct(escaper);

        let this->interpolator = new Interpolate(),
            this->url          = url;
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
     * Clears the crumbs.
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
     * Clear the attributes of the parent element.
     */
    public function clearAttributes() -> <static>
    {
        let this->attributes = [];

        return this;
    }

    /**
     * Get the attributes of the parent element.
     *
     * @return array<string, string>
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
     * @return TTemplate
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
        var lastUrl, lastElement, element;
        array output;
        /*
         * Early exit for empty data
         */
        if empty this->data {
            return "";
        }

        let output = [];
        let lastUrl = array_key_last(this->data);
        let lastElement = this->data[lastUrl];

        unset this->data[lastUrl];

        for element in this->data {
            let output[] = this->getLink(this->template["line"], element);
        }

        /*
         * Last element
         */
        let output[] = this->getLink(this->template["last"], lastElement);

        return this->interpolator->__invoke(
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
     * Set the attributes for the parent element.
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
     * Set the separator.
     */
    public function setSeparator(string separator) -> <static>
    {
        let this->separator = separator;

        return this;
    }

    /**
     * Set the HTML template.
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
     * Returns the internal breadcrumbs array.
     *
     * @return array<int, TElement>
     */
    public function toArray() -> array
    {
        return this->data;
    }

    /**
     * @param TElement $element
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
            .this->interpolator->__invoke(
                template,
                [
                    "attributes" : this->processAttributes(element["attributes"]),
                    "icon"       : element["icon"],
                    "text"       : this->escaper->html(element["text"]),
                    "link"       : link
                ]
            )
            .this->delimiter;
    }

    /**
     * Processes attributes
     */
    private function processAttributes(array attributes) -> string
    {
        var attributesRendered;

        let attributesRendered = this->renderAttributes(attributes);

        return rtrim(!empty(attributesRendered) ? " " . attributesRendered : "");
    }
}
