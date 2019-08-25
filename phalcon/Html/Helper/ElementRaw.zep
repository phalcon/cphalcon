
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Exception;

/**
 * Phalcon\Html\Helper\ElementRaw
 *
 * Creates an element raw
 */
class ElementRaw extends AbstractHelper
{
    /**
     * @param string $tag        The tag for the anchor
     * @param string $text       The text for the anchor
     * @param array  $attributes Any additional attributes
     *
     * @return string
     * @throws Exception
     */
    public function __invoke(string! tag, string! text, array! attributes = []) -> string
    {
        return this->renderFullElement(tag, text, attributes, true);
    }
}
