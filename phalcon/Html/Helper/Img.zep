
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
 * Class Img
 */
class Img extends AbstractHelper
{
    /**
     * Produce a <img> tag.
     *
     * @param string $src
     * @param array  $attributes
     *
     * @return string
     * @throws Exception
     */
    public function __invoke(string src, array attributes = []) -> string
    {
        var overrides;

        let overrides = ["src" : src];

        /**
         * Avoid duplicate "src" and ignore it if it is passed in the attributes
         */
        unset attributes["src"];

        let overrides = array_merge(overrides, attributes);

        return this->selfClose("img", overrides);
    }
}
