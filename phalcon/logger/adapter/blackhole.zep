
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Logger\Adapter;

use Phalcon\Logger\Adapter;
use Phalcon\Logger\Formatter\Line;
use Phalcon\Logger\FormatterInterface;

/**
 * Phalcon\Logger\Adapter\Blackhole
 *
 * Any record it can handle will be thrown away.
 */
class Blackhole extends Adapter
{
	/**
	 * Returns the internal formatter
	 */
	public function getFormatter() -> <FormatterInterface>
	{
		if typeof this->_formatter !== "object" {
			let this->_formatter = new Line();
		}

		return this->_formatter;
	}

	/**
	 * Writes the log to the blackhole
	 */
	public function logInternal(string message, int type, int time, array context) -> void
	{
	}

	/**
	 * Closes the logger
	 */
	public function close() -> boolean
	{
	}
}
