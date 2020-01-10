
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
 * Class Anchor
 */
class Anchor extends AbstractHelper
{
    /**
     * Produce a <a> tag
     *
     * @param string $href
     * @param string $text
     * @param array  $attributes
     * @param bool   $raw
     *
     * @return string
     * @throws Exception
     */
    public function __invoke(
        string href,
        string text,
        array attributes = [],
        bool raw = false
    ) -> string {
        var overrides;

        let overrides = this->processAttributes(href, attributes);

        return this->renderFullElement("a", text, overrides, raw);
    }

    /**
     * @param string $href
     * @param array  $attributes
     *
     * @return array
     */
    protected function processAttributes(string href, array attributes) -> array
    {
        var overrides;

        let overrides = ["href" : href];

        /**
         * Avoid duplicate "href" and ignore it if it is passed in the attributes
         */
        unset attributes["href"];

        return array_merge(overrides, attributes);
    }
}
