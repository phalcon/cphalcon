
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Flash;

use Phalcon\Flash as FlashBase;

/**
 * Phalcon\Flash\Direct
 *
 * This is a variant of the Phalcon\Flash that immediately outputs any message passed to it
 */
class Direct extends FlashBase
{

	/**
	 * Outputs a message
	 */
	public function message(string type, var message) -> string
	{
		return this->outputMessage(type, message);
	}

	/**
	 * Prints the messages accumulated in the flasher
	 */
	public function output(bool remove = true) -> void
	{
		var message, messages;

		let messages = this->_messages;
		if typeof messages == "array" {
			for message in messages {
				echo message;
			}
		}

		if remove {
			parent::clear();
		}
	}
}
