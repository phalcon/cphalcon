
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
 * Component INPUT[type=submit] for forms
 */
class Submit extends AbstractElement
{
    /**
     * Renders the element widget
     */
    public function render(array attributes = []) -> string
    {
        /**
         * Merged passed attributes with previously defined ones
         */
        return Tag::submitButton(
            this->prepareAttributes(attributes)
        );
    }
}
