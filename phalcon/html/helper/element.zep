
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
 * Phalcon\Html\Helper\Address
 *
 * Creates an element
 */
class Element extends AbstractHelper
{
	/**
	 * @var string tag        The tag name
	 * @var string text       The text for the anchor
	 * @var array  attributes Any additional attributes
	 */
	public function __invoke()
	{
		var arguments, attributes, tag, text;

		let arguments = func_get_args();

		/**
		 * Check parameters passed
		 */
		if (count(arguments) >= 2 &&
			typeof arguments[0] === "string" &&
			typeof arguments[1] === "string") {

			if (true === isset(arguments[2]) && typeof arguments[2] === "array") {
				let attributes = arguments[2];
			} else {
				let attributes = [];
			}
			let tag  = arguments[0],
				text = arguments[1];

			return this->renderElement(tag, text, attributes);
		} else {
			throw new \InvalidArgumentException("Incorrect passed arguments");
		}
	}
}
