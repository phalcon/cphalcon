
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

namespace Phalcon\Html;

/**
 * Phalcon\Html\Breadcrumbs
 *
 * This component offers an easy way to create breadcrumbs for your application.
 * The resulting HTML when calling `render()` will have each breadcrumb enclosed
 * in `<dt>` tags, while the whole string is enclosed in `<dl>` tags.
 *
 * @deprecated Will be removed in future version
 * Use {@see Phalcon\Html\Helper\Breadcrumbs} instead.
 */
class Breadcrumbs
{
    /**
     * Keeps all the breadcrumbs
     *
     * @var array
     */
    private elements = [];

    /**
     * Crumb separator
     *
     * @var string
     */
    private separator = " / ";

    /**
     * The HTML template to use to render the breadcrumbs.
     *
     * @var string
     */
    private template = "<dt><a href=\"%link%\">%label%</a></dt>";

    /**
     * Adds a new crumb.
     *
     * ```php
     * // Adding a crumb with a link
     * $breadcrumbs->add("Home", "/");
     *
     * // Adding a crumb without a link (normally the last one)
     * $breadcrumbs->add("Users");
     * ```
     *
     * Crumbs are stored keyed by their link, so adding two crumbs that share
     * the same link - including two link-less crumbs, which share the empty
     * string key - keeps only the last one.
     */
    public function add(string label, string link = "") -> <static>
    {
        let this->elements[link] = label;

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
        let this->elements = [];
    }

    /**
     * Crumb separator
     *
     * @return string
     */
    public function getSeparator() -> string
    {
        return this->separator;
    }

    /**
     * Removes crumb by url.
     *
     * ```php
     * $breadcrumbs->remove("/admin/user/create");
     *
     * // remove a crumb without an url (last link)
     * $breadcrumbs->remove();
     * ```
     */
    public function remove(string link) -> void
    {
        var elements;

        let elements = this->elements;

        unset(elements[link]);

        let this->elements = elements;
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
        var element, elements, lastLabel, lastUrl, output, template, url, urls;

        let elements = this->elements;

        /**
         * Nothing to render - guard against end([]) returning false and
         * indexing elements[false]
         */
        if empty elements {
            return "";
        }

        let output    = [],
            template  = this->template,
            urls      = array_keys(elements),
            lastUrl   = end(urls),
            lastLabel = elements[lastUrl];

        unset(elements[lastUrl]);

        for url, element in elements {
            let output[] = str_replace(
                [
                    "%label%",
                    "%link%"
                ],
                [
                    element,
                    url
                ],
                template
            );
        }

        /**
         * Check if this is the "Home" element i.e. count() = 0
         */
        if 0 !== count(elements) {
            let output[] = "<dt>" . lastLabel . "</dt>";
        } else {
            let output[] = str_replace(
                [
                    "%label%",
                    "%link%"
                ],
                [
                    lastLabel,
                    lastUrl
                ],
                template
            );
        }

        return "<dl>" . implode("<dt>" . this->separator . "</dt>", output) . "</dl>";
    }

    /**
     * @param string $separator
     *
     * @return static
     */
    public function setSeparator(string separator) -> <static>
    {
        let this->separator = separator;

        return this;
    }
    /**
     * Returns the internal breadcrumbs array
     */
    public function toArray() -> array
    {
        return this->elements;
    }
}
