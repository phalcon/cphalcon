
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Logger\Adapter;

use Phalcon\Logger\Exception;
use Phalcon\Logger\Adapter;
use Phalcon\Logger\AdapterInterface;
use Phalcon\Logger\FormatterInterface;


/**
 * Phalcon\Logger\Adapter\Stream
 *
 * Sends logs to a valid PHP stream
 *
 *<code>
 *	$logger = new \Phalcon\Logger\Adapter\Stream("php://stderr");
 *	$logger->log("This is a message");
 *	$logger->log("This is an error", \Phalcon\Logger::ERROR);
 *	$logger->error("This is another error");
 *</code>
 */
class Stream extends Adapter implements AdapterInterface
{

	/**
	 * File handler resource
	 *
	 * @var resource
	 */
	protected _stream;

	/**
	 * Phalcon\Logger\Adapter\Stream constructor
	 *
	 * @param string name
	 * @param array options
	 */
	public function __construct(string! name, options=null)
	{
		var mode, stream;

		if fetch mode, options["mode"] {
			if memstr(mode, "r") {
				throw new Exception("Stream must be opened in append or write mode");
			}
		} else {
			let mode = "ab";
		}

		/**
		 * We use 'fopen' to respect to open-basedir directive
		 */
		let stream = fopen(name, mode);
		if !stream {
			throw new Exception("Can't open stream '" . name . "'");
		}

		let this->_stream = stream;
	}

	/**
	 * Returns the internal formatter
	 *
	 * @return Phalcon\Logger\Formatter\Line
	 */
	public function getFormatter() -> <FormatterInterface>
	{
		if typeof this->_formatter !== "object" {
			let this->_formatter = new \Phalcon\Logger\Formatter\Line();
		}

		return this->_formatter;
	}

	/**
	 * Writes the log to the stream itself
	 *
	 * @param string message
	 * @param int type
	 * @param int time
	 * @param array $context
	 */
	public function logInternal(string message, int type, int time, array context)
	{
		var stream;

		let stream = this->_stream;
		if typeof stream != "resource" {
			throw new Exception("Cannot send message to the log because it is invalid");
		}

		fwrite(stream, this->getFormatter()->format(message, type, time, context));
	}

	/**
 	 * Closes the logger
 	 *
 	 * @return boolean
 	 */
	public function close() -> boolean
	{
		return fclose(this->_stream);
	}

}
