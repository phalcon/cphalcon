
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Formatter;

use Phalcon\Logger;

abstract class AbstractFormatter implements FormatterInterface
{
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
