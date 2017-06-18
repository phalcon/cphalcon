
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
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
	public function output(boolean remove = true) -> void
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
