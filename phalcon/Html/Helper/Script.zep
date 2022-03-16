
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Exception;
/**
 * Class Script
 */
class Script extends AbstractSeries
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
            "src"  : url,
            "type" : "application/javascript"
        ];

        unset attributes["src"];

        return array_merge(required, attributes);
    }

    /**
     * @return string
     */
    protected function getTag() -> string
    {
        return "script";
    }
}
