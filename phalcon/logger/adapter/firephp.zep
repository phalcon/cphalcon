
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
 |          Ivan Zubok <chi@ukr.net>                                      |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Logger\Adapter;

use Phalcon\Logger\Adapter;
use Phalcon\Logger\Exception;
use Phalcon\Logger\FormatterInterface;
use Phalcon\Logger\Formatter\Firephp as FirePhpFormatter;

/**
 * Phalcon\Logger\Adapter\Firephp
 *
 * Sends logs to FirePHP
 *
 *<code>
 * use Phalcon\Logger\Adapter\Firephp;
 * use Phalcon\Logger;
 *
 * $logger = new Firephp();
 *
 * $logger->log(Logger::ERROR, "This is an error");
 * $logger->error("This is another error");
 *</code>
 *
 * @deprecated Will be removed in 4.0.0
 */
class Firephp extends Adapter
{
	private _initialized = false;

	private _index = 1;

	/**
	 * Returns the internal formatter
	 */
	public function getFormatter() -> <FormatterInterface>
	{
		if typeof this->_formatter !== "object" {
			let this->_formatter = new FirePhpFormatter();
		}

		return this->_formatter;
	}

	/**
	 * Writes the log to the stream itself
	 */
	public function logInternal(string message, int type, int time, array context) -> void
	{
		var chunk, format, chString, content, key, index;

		if !this->_initialized {
			header("X-Wf-Protocol-1: http://meta.wildfirehq.org/Protocol/JsonStream/0.2");
			header("X-Wf-1-Plugin-1: http://meta.firephp.org/Wildfire/Plugin/FirePHP/Library-FirePHPCore/0.3");
			header("X-Wf-Structure-1: http://meta.firephp.org/Wildfire/Structure/FirePHP/FirebugConsole/0.1");

			let this->_initialized = true;
		}

		let format = this->getFormatter()->format(message, type, time, context),
			chunk = str_split(format, 4500),
			index = this->_index;

		for key, chString in chunk {
			let content = "X-Wf-1-1-1-" . (string) index . ": " . chString;

			if isset(chunk[key + 1]) {
				let content .= "|\\";
			}

			header(content);

			let index++;
		}

		let this->_index = index;
	}

	/**
	 * Closes the logger
	 */
	public function close() -> boolean
	{
		return true;
	}
}
