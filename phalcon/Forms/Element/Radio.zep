
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Element;

use Phalcon\Tag;

/**
 * Phalcon\Forms\Element\Radio
 *
 * Component INPUT[type=radio] for forms
 */
class Radio extends AbstractElement
{
    /**
     * Renders the element widget returning HTML
     */
    public function render(array attributes = []) -> string
    {
        return Tag::radioField(
            this->prepareAttributes(attributes, true)
        );
    }
}
