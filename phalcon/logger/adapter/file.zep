
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

namespace Phalcon\Logger\Adapter;

use Phalcon\Logger\Adapter;
use Phalcon\Logger\AdapterInterface;
use Phalcon\Logger\Exception;
use Phalcon\Logger\FormatterInterface;
use Phalcon\Logger\Formatter\Line as LineFormatter;

/**
 * Phalcon\Logger\Adapter\File
 *
 * Adapter to store logs in plain text files
 *
 *<code>
 *	$logger = new \Phalcon\Logger\Adapter\File("app/logs/test.log");
 *	$logger->log("This is a message");
 *	$logger->log("This is an error", \Phalcon\Logger::ERROR);
 *	$logger->error("This is another error");
 *	$logger->close();
 *</code>
 */
class File extends Adapter implements AdapterInterface
{

	/**
	 * File handler resource
	 *
	 * @var resource
	 */
	protected _fileHandler;

	/**
	 * File Path
	 */
	protected _path { get };

	/**
	 * Path options
	 */
	protected _options;

	/**
	 * Phalcon\Logger\Adapter\File constructor
	 *
	 * @param string name
	 * @param array options
	 */
	public function __construct(string! name, options = null)
	{
		var mode = null, handler;

		if typeof options === "array" {
			if fetch mode, options["mode"] {
				if memstr(mode, "r") {
					throw new Exception("Logger must be opened in append or write mode");
				}
			}
		}

		if mode === null {
			let mode = "ab";
		}

		/**
		 * We use 'fopen' to respect to open-basedir directive
		 */
		let handler = fopen(name, mode);
		if typeof handler != "resource" {
			throw new Exception("Can't open log file at '" . name . "'");
		}

		let this->_path = name,
			this->_options = options,
			this->_fileHandler = handler;
	}

	/**
	 * Returns the internal formatter
	 */
	public function getFormatter() -> <FormatterInterface>
	{
		if typeof this->_formatter !== "object" {
			let this->_formatter = new LineFormatter();
		}

		return this->_formatter;
	}

	/**
	 * Writes the log to the file itself
	 */
	public function logInternal(string message, int type, int time, array context) -> void
	{
		var fileHandler;

		let fileHandler = this->_fileHandler;
		if typeof fileHandler !== "resource" {
			throw new Exception("Cannot send message to the log because it is invalid");
		}

		fwrite(fileHandler, this->getFormatter()->format(message, type, time, context) . PHP_EOL);
	}

	/**
 	 * Closes the logger
 	 */
	public function close() -> boolean
	{
		return fclose(this->_fileHandler);
	}

	/**
	 * Opens the internal file handler after unserialization
	 */
	public function __wakeup()
	{
		var path, mode;

		let path = this->_path;
		if typeof path !== "string" {
			throw new Exception("Invalid data passed to Phalcon\\Logger\\Adapter\\File::__wakeup()");
		}

		if !fetch mode, this->_options["mode"] {
			let mode = "ab";
		}

		if typeof mode !== "string" {
			throw new Exception("Invalid data passed to Phalcon\\Logger\\Adapter\\File::__wakeup()");
		}

		if memstr(mode, "r") {
			throw new Exception("Logger must be opened in append or write mode");
		}

		/**
		 * Re-open the file handler if the logger was serialized
		 */
		let this->_fileHandler = fopen(path, mode);
	}
}
