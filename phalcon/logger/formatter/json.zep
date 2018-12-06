
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Formatter;

use Phalcon\Logger\Formatter\AbstractFormatter;
use Phalcon\Logger\Item;

/**
 * Phalcon\Logger\Formatter\Json
 *
 * Formats messages using JSON encoding
 */
class Json extends AbstractFormatter
{
	/**
	 * Default date format
	 *
	 * @var string
	 */
	protected dateFormat = "D, d M y H:i:s O" { get, set };

	/**
	 * Phalcon\Logger\Formatter\Json construct
	 *
	 * @param string dateFormat
	 */
	public function __construct(string dateFormat = "") -> void
	{
		if dateFormat {
			let this->dateFormat = dateFormat;
		}
	}

	/**
	 * Applies a format to a message before sent it to the internal log
	 *
	 * @param <Item> item
	 *
	 * @return string
	 */
	public function format(<Item> item) -> string
	{
		var message;

		if typeof item->getContext() === "array" {
			let message = this->interpolate(item->getMessage(), item->getContext());
		} else {
			let message = item->getMessage();
		}

		return json_encode(
			[
				"type"      : item->getName(),
				"message"   : message,
				"timestamp" : date(this->dateFormat, item->getTime())
			]
		) . PHP_EOL;
	}
}
