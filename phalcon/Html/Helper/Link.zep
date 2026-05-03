
/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
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
    public function add(string url, array attributes = [], int pos = -1)
    {
        this->pushOrPlace(
            [
                "renderTag",
                [
                    this->getTag(),
                    this->getAttributes(url, attributes),
                    "/"
                ],
                this->indent()
            ],
            pos
        );

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
