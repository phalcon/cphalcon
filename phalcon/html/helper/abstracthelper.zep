
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Exception;
use Phalcon\EscaperInterface;

/**
 * Phalcon\Html\Helper\AbstractHelper
 *
 * Abstract class for all html helpers
 */
abstract class AbstractHelper
{
	/**
	 * @var <EscaperInterface>
	 */
	protected escaper;

	/**
	 * Constructor
	 */
	public function __construct(<EscaperInterface> escaper)
	{
		let this->escaper = escaper;
	}

	/**
	 * Keeps all the attributes sorted - same order all the tome
	 */
	protected function orderAttributes(array attributes) -> array
	{
		var order, intersect, results;

		let order = [
			"rel"    : null,
			"type"   : null,
			"for"    : null,
			"src"    : null,
			"href"   : null,
			"action" : null,
			"id"     : null,
			"name"   : null,
			"value"  : null,
			"class"  : null
		];

		let intersect = array_intersect_key(order, attributes),
			results   = array_merge(intersect, attributes);
		/**
		 * Just in case remove the "escape" attribute
		 */
		unset results["escape"];

		return results;
	}

	/**
	 * Renders all the attributes
	 */
	protected function renderAttributes(array attributes) -> string
	{
		var key, result, value;

		let result = "";
		for key, value in attributes {
			if typeof key == "string" && value !== null {
				if typeof value == "array" || typeof value == "resource" {
					throw new Exception(
						"Value at index: '" . key . "' type: '" . gettype(value) . "' cannot be rendered"
					);
				}

				let result .= key . "=\"" . this->escaper->escapeHtmlAttr(value) . "\" ";

			}
		}

		return result;
	}
}
