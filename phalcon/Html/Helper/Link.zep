
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
     * @param string $url
     * @param array  $attributes
     */
    public function add(string url, array attributes = [])
    {
        let this->store[] = [
            "renderTag",
            [
                this->getTag(),
                this->getAttributes(url, attributes),
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
     * @param string $url
     * @param array  $attributes
     *
     * @return array
     */
    protected function getAttributes(string url, array attributes) -> array
    {
        array required;

        let required = [
            "href" : url
        ];

        unset(attributes["href"]);

        return array_merge(required, attributes);
    }
}
