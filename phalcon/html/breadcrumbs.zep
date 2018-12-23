
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html;

use Phalcon\DiInterface;

/**
 * Phalcon\Html\Breadcrumbs
 *
 * Handles the breadcrumbs for the application.
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
    private separator = " / " { get, set };

    /**
     * Array holding output template
     * 
     * @var array
     */
    private template = "<li><a href=\"%link%\">%label%</a></li>";

    /**
     * Adds a new crumb.
     *
     * <code>
     * // Adding a crumb with a link
     * $breadcrumbs->add("Home", "/");
     *
     * // Adding a crumb without a link (normally the last one)
     * $breadcrumbs->add("Users");
     * </code>
     */
    public function add(string label, string link = "") -> <Breadcrumbs>
    {
		let this->elements[link] = label;

        return this;
    }

    /**
     * Clears the crumbx
     *
     * <code>
     * $$breadcrumbs->clear()
     * </code>
     */
    public function clear() -> void
    {
		let this->elements = [];
    }

    /**
     * Removes crumb by url.
     *
     * <core>
     * $breadcrumbs->remove("/admin/user/create");
     *
     * // remove a crumb without an url (last link)
     * $breadcrumbs->remove();
     * </code>
     */
    public function remove(string link) -> <Breadcrumbs>
    {
		unset(this->elements[link]);

        return this;
    }

    /**
     * Renders and outputs breadcrumbs based on previously set template.
     *
     * <code>
     * // Php Engine
     * $breadcrumbs->render();
     * </code>
     *
     * @return string
     */
    public function render()
    {
    	var element, elements, lastLabel, lastUrl, output, template, url, urls;

        let output    = [],
        	elements  = this->elements,
        	template  = this->template,
        	urls      = array_keys(elements),
        	lastUrl   = end(urls),
        	lastLabel = elements[lastUrl];

        unset(elements[lastUrl]);

		for url, element in elements {
			let output = str_replace(
				[
					"%label%",
					"%url%"
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
			let elements[] = lastLabel;
        } else {
			let elements[] = str_replace(
				[
					"%label%",
					"%url%"
				],
				[
					lastLabel,
					lastUrl
				],
				template
			);
		}

		return implode(this->separator, elements);
    }

    /**
     * Sets rendering template.
     *
     * <code>
     * $breadcrumbs->setTemplate(
     *     "<li><a href="%link%">%label%</a></li>"
     * );
     * </code>
     */
    public function setTemplate(string template = "") -> <Breadcrumbs>
    {
		let this->template = template;

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
