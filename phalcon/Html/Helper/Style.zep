
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Exception;

/**
 * Class Style
 */
class Style extends AbstractSeries
{
    /**
     * @var bool
     */
    private isStyle = false;

    /**
     * Add an element to the list
     *
     * @param string $url
     * @param array  $attributes
     *
     * @return static
     * @throws Exception
     */
    public function add(string url, array attributes = [], int position = -1) -> <static>
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
            position
        );

        return this;
    }

    /**
     * Sets if this is a style or link tag
     *
     * @param bool $flag
     */
    public function setStyle(bool flag) -> <static>
    {
        let this->isStyle = flag;

        return this;
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
            "rel"   : "stylesheet",
            "href"  : url,
            "type"  : "text/css",
            "media" : "screen"
        ];

        if (true === this->isStyle) {
            unset(required["rel"]);
        }

        unset attributes["href"];

        return array_merge(required, attributes);
    }

    /**
     * @return string
     */
    protected function getTag() -> string
    {
        return true === this->isStyle ? "style" : "link";
    }
}
