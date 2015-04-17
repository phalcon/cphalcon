
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
 * Phalcon\Logger\Formatter\Syslog
 *
 * Prepares a message to be used in a Syslog backend
 */
class Syslog extends Formatter implements FormatterInterface
{

	/**
	 * Applies a format to a message before sent it to the internal log
	 *
	 * @param string message
	 * @param int type
	 * @param int timestamp
	 * @param array $context
	 * @return array
	 */
	public function format(message, int type, int timestamp, var context = null) -> array
	{
		if typeof context === "array" {
			let message = this->interpolate(message, context);
		}
		return [type, message];
	}
}
