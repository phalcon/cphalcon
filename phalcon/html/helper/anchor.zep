
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
	public function __invoke(string! href, string! text, array attributes = []) -> string
	{
		var escapedText, overrides;

		let overrides = ["href" : href];

		/**
		 * Avoid duplicate "href" and ignore it if it is passed in the attributes
		 */
		unset(attributes["href"]);

		let overrides   = this->orderAttributes(overrides, attributes),
			escapedText = this->escaper->escapeHtml(text);

		return "<a " . rtrim(this->renderAttributes(overrides)) . ">" . escapedText . "</a>";
	}
}
