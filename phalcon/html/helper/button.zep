
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
 * Phalcon\Html\Helper\Button
 *
 * Creates a button tag
 */
class Button extends AbstractHelper
{
	/**
	 * @var string text       The text for the anchor
	 * @var array  attributes Any additional attributes
	 */
	public function __invoke()
	{
		var arguments, attributes, text;

		let arguments = func_get_args();

		/**
		 * Check parameters passed
		 */
		if (count(arguments) >= 1 && typeof arguments[0] === "string") {
			if (true === isset(arguments[1]) && typeof arguments[1] === "array") {
				let attributes = arguments[1];
			} else {
				let attributes = [];
			}
			let text = arguments[0];

			return this->renderElement("button", text, attributes);
		} else {
			throw new \InvalidArgumentException("Incorrect passed arguments");
		}
	}
}
