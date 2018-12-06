
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Formatter;

use Phalcon\Logger\Formatter;

/**
 * Phalcon\Logger\Formatter\Syslog
 *
 * Prepares a message to be used in a Syslog backend
 */
class Syslog extends Formatter
{
	/**
	 * Applies a format to a message before sent it to the internal log
	 *
	 * @param <Item> item
	 *
	 * @return array
	 */
	public function format(<Item> item) -> array
	{
	    var message = item->getMessage(),
	        type    = item->getType();

		if typeof context === "array" {
			let message = this->interpolate(item->getMessage(), item->getContext());
		}

		return [type, message];
	}
}
