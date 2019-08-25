
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Helper\AbstractHelper;

/**
 * Phalcon\Html\Helper\AnchorRaw
 *
 * Creates a raw anchor
 */
class AnchorRaw extends AbstractHelper
{
    /**
     * @var string href       The href tag
     * @var string text       The text for the anchor
     * @var array  attributes Any additional attributes
     */
    public function __invoke(string! href, string! text, array attributes = []) -> string
    {
        var overrides;

        let overrides = ["href" : href];

        /**
         * Avoid duplicate "href" and ignore it if it is passed in the attributes
         */
        unset attributes["href"];

        let overrides = array_merge(overrides, attributes);

        return this->renderFullElement("a", text, overrides, true);
    }
}
