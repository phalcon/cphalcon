
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
 * Phalcon\Html\Helper\Label
 *
 * Creates a label
 */
class Label extends AbstractHelper
{
    /**
     * @param array $attributes Any additional attributes
     *
     * @return string
     * @throws Exception
     */
    public function __invoke(array! attributes = []) -> string
    {
        return this->renderElement("label", attributes);
    }
}
