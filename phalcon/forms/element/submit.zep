
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Element;

use Phalcon\Tag;
use Phalcon\Forms\Element;

/**
 * Phalcon\Forms\Element\Submit
 *
 * Component INPUT[type=submit] for forms
 */
class Submit extends Element
{

	/**
	 * Renders the element widget
	 */
	public function render(array attributes = []) -> string
	{
		/**
		 * Merged passed attributes with previously defined ones
		 */
		return Tag::submitButton(this->prepareAttributes(attributes));
	}
}
