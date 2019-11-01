
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
 * Phalcon\Forms\Element\Text
 *
 * Component INPUT[type=text] for forms
 */
class Text extends AbstractElement
{
    /**
     * Renders the element widget
     */
    public function render(array attributes = []) -> string
    {
        return Tag::textField(
            this->prepareAttributes(attributes)
        );
    }
}
