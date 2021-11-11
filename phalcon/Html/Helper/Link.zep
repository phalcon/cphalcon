
/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

/**
 * Creates <link> tags
 */
class Link extends Style
{
    /**
     * Add an element to the list
     *
     * @param string $href
     * @param array  $attributes
     *
     * @return Link
     */
    public function add(string href, array attributes = []) -> <Link>
    {
        let this->store[] = [
            "renderTag",
            [
                this->getTag(),
                this->getAttributes(href, attributes),
                "/"
            ],
            this->indent()
        ];

        return this;
    }

    /**
     * @return string
     */
    protected function getTag() -> string
    {
        return "link";
    }

    /**
     * Returns the necessary attributes
     *
     * @param string $href
     * @param array  $attributes
     *
     * @return array
     */
    protected function getAttributes(string href, array attributes) -> array
    {
        array required;

        let required = [
            "href" : href
        ];

        unset(attributes["href"]);

        return array_merge(required, attributes);
    }
}
