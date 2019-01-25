
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
 * Phalcon\Html\Helper\Anchor
 *
 * Creates an anchor
 */
class Anchor extends AbstractHelper
{
	/**
	 * @var string href       The href tag
	 * @var string text       The text for the anchor
	 * @var array  attributes Any additional attributes
	 */
	public function __invoke()
	{
		var arguments, attributes, escapedText, href, overrides, text;

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

			let href      = arguments[0],
				overrides = ["href" : href],
				text      = arguments[1];

			/**
			 * Avoid duplicate "href" and ignore it if it is passed in the attributes
			 */
			unset(attributes["href"]);

			let overrides   = this->orderAttributes(overrides, attributes),
				escapedText = this->escaper->escapeHtml(text);

			return "<a " . rtrim(this->renderAttributes(overrides)) . ">" . escapedText . "</a>";
		} else {
			throw new \InvalidArgumentException("Incorrect passed arguments");
		}
	}
}
