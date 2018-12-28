
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
 * Phalcon\Forms\Element\Check
 *
 * Component INPUT[type=check] for forms
 */
class Check extends Element
{

	/**
	 * Renders the element widget returning html
	 */
	public function render(array attributes = []) -> string
	{
		return Tag::checkField(this->prepareAttributes(attributes, true));
	}
}
