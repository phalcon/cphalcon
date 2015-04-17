
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Logger\Formatter;

use Phalcon\Logger\Formatter;
use Phalcon\Logger\FormatterInterface;

/**
 * Phalcon\Logger\Formatter\Line
 *
 * Formats messages using an one-line string
 */
class Line extends Formatter implements FormatterInterface
{

	/**
	 * Default date format
	 *
	 * @var string
	 */
	protected _dateFormat = "D, d M y H:i:s O" { get, set };

	/**
	 * Format applied to each message
	 *
	 * @var string
	 */
	protected _format = "[%date%][%type%] %message%" { get, set };

	/**
	 * Phalcon\Logger\Formatter\Line construct
	 *
	 * @param string format
	 * @param string dateFormat
	 */
	public function __construct(format = null, dateFormat = null)
	{
		if format {
			let this->_format = format;
		}
		if dateFormat {
			let this->_dateFormat = dateFormat;
		}
	}

	/**
	 * Applies a format to a message before sent it to the internal log
	 *
	 * @param string message
	 * @param int type
	 * @param int timestamp
	 * @param array $context
	 * @return string
	 */
	public function format(string message, int type, int timestamp, var context = null) -> string
	{
		var format;

		let format = this->_format;

		/**
		 * Check if the format has the %date% placeholder
		 */
		if memstr(format, "%date%") {
			let format = str_replace("%date%", date(this->_dateFormat, timestamp), format);
		}

		/**
		 * Check if the format has the %type% placeholder
		 */
		if memstr(format, "%type%") {
			let format = str_replace("%type%", this->getTypeString(type), format);
		}

		let format = str_replace("%message%", message, format);

		if typeof context === "array" {
			return this->interpolate(format, context);
		}

		return format;
	}
}