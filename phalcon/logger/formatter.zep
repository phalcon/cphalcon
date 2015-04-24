
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

namespace Phalcon\Logger;

use Phalcon\Logger;

/**
 * Phalcon\Logger\Formatter
 *
 * This is a base class for logger formatters
 */
abstract class Formatter
{

	/**
	 * Returns the string meaning of a logger constant
	 */
	public function getTypeString(int type) -> string
	{
		switch type {

			case Logger::DEBUG:
				return "DEBUG";

			case Logger::ERROR:
				return "ERROR";

			case Logger::WARNING:
				return "WARNING";

			case Logger::CRITICAL:
				return "CRITICAL";

			case Logger::CUSTOM:
				return "CUSTOM";

			case Logger::ALERT:
				return "ALERT";

			case Logger::NOTICE:
				return "NOTICE";

			case Logger::INFO:
				return "INFO";

			case Logger::EMERGENCY:
				return "EMERGENCY";

			case Logger::SPECIAL:
				return "SPECIAL";
		}

		return "CUSTOM";
	}

	/**
	 * Interpolates context values into the message placeholders
	 *
	 * @see http://www.php-fig.org/psr/psr-3/ Section 1.2 Message
	 * @param string $message
	 * @param array $context
	 */
	public function interpolate(string message, var context = null)
	{
		var replace, key, value;

		if typeof context == "array" && count(context) > 0 {
			let replace = [];
			for key, value in context {
				let replace["{" . key . "}"] = value;
			}
			return strtr(message, replace);
		}
		return message;
	}
}
