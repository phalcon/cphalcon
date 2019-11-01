
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

/**
 * Phalcon\Html\Helper\Body
 *
 * Creates a body tag
 */
class Body extends AbstractHelper
{
    /**
     * @var array  attributes Any additional attributes
     */
    public function __invoke(array attributes = []) -> string
    {
        return this->renderElement("body", attributes);
    }
}
