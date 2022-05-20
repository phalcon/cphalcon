
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Element;

/**
 * Phalcon\Forms\Element\Check
 *
 * Component INPUT[type=check] for forms
 */
class Check extends AbstractElement
{
    /**
     * @var string
     */
    protected method = "inputCheckbox";
//    /**
//     * Renders the element widget returning HTML
//     */
//    public function render(array attributes = []) -> string
//    {
//        return Tag::checkField(
//            this->prepareAttributes(attributes, true)
//        );
//    }
}
