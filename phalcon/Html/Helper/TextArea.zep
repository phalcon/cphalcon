
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Helper\AbstractHelper;

/**
 * Phalcon\Html\Helper\TextArea
 *
 * Creates a textarea tag
 */
class TextArea extends AbstractHelper
{
    /**
     * @var string text       The text for the anchor
     * @var array  attributes Any additional attributes
     */
    public function __invoke(string! text, array attributes = []) -> string
    {
        return this->renderElement("textarea", text, attributes);
    }
}
