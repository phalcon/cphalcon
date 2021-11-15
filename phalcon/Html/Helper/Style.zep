
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Exception;

/**
 * Class Style
 */
class Style extends AbstractSeries
{

    /**
     * Add an element to the list
     *
     * @param string $url
     * @param array  $attributes
     *
     * @return $this
     * @throws Exception
     */
    public function add(string url, array attributes = [])
    {
        let this->store[] = [
            "renderFullElement",
            [
                this->getTag(),
                "",
                this->getAttributes(url, attributes)
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
        return "style";
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

        unset attributes["href"];

        return array_merge(required, attributes);
    }
}
