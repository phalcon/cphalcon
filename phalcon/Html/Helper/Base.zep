
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
 * Class Base
 */
class Base extends AbstractHelper
{
    /**
     * Produce a `<base/>` tag.
     *
     * @param string $href
     * @param array  $attributes
     *
     * @return string
     * @throws Exception
     */
    public function __invoke(string href, array attributes = []) -> string
    {
        var overrides = [];

        if !empty href {
            let overrides = ["href" : href];
        }

        /**
         * Avoid duplicate "href" and ignore it if it is passed in the attributes
         */
        unset attributes["href"];

        let overrides = array_merge(overrides, attributes);

        return this->renderElement("base", overrides);
    }
}
