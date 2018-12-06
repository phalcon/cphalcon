
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Formatter;

use Phalcon\Logger\Formatter\Formatter;
use Phalcon\Logger\Item;

/**
 * Phalcon\Logger\Formatter\Line
 *
 * Formats messages using an one-line string
 */
class Line extends AbstractFormatter
{
	/**
	 * Default date format
	 *
	 * @var string
	 */
	protected dateFormat = "D, d M y H:i:s O" { get, set };

	/**
	 * Format applied to each message
	 *
	 * @var string
	 */
	protected format = "[%date%][%type%] %message%" { get, set };

	/**
	 * Phalcon\Logger\Formatter\Line construct
	 *
	 * @param string format
	 * @param string dateFormat
	 */
	public function __construct(string format = "", string dateFormat = "") -> void
	{
		if format {
			let this->format = format;
		}
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
		var format;

		let format = this->format;

		/**
		 * Check if the format has the %date% placeholder
		 */
		if memstr(format, "%date%") {
			let format = str_replace("%date%", date(this->dateFormat, item->getTime()), format);
		}

		/**
		 * Check if the format has the %type% placeholder
		 */
		if memstr(format, "%type%") {
			let format = str_replace("%type%", item->getName(), format);
		}

		let format = str_replace("%message%", item->getMessage(), format) . PHP_EOL;

		if typeof item->getContext() === "array" {
			return this->interpolate(format, item->getContext());
		}

		return format;
	}
}
