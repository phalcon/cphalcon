
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
class File extends Phalcon\Logger\Adapter implements Phalcon\Logger\AdapterInterface
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
	protected _path;

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
	public function __construct(string! name, options=null)
	{
		var mode, handler;

		if typeof options == "array" {
			if fetch mode, options["mode"] {
				if memstr(mode, "r") {
					throw new Phalcon\Logger\Exception("Logger must be opened in append or write mode");
				}
			}
		} else {
			let mode = "ab";
		}

		/**
		 * We use 'fopen' to respect to open-basedir directive
		 */
		let handler = fopen(name, mode);
		if !handler {
			throw new Phalcon\Logger\Exception("Can't open log file at '" . name . "'");
		}

		let this->_path = name,
			this->_options = options,
			this->_fileHandler = handler;
	}

	/**
	 * Returns the internal formatter
	 *
	 * @return Phalcon\Logger\FormatterInterface
	 */
	public function getFormatter() -> <Phalcon\Logger\FormatterInterface>
	{
		var formatter;

		let formatter = this->_formatter;
		if typeof formatter != "object" {
			let formatter = new Phalcon\Logger\Formatter\Line(),
				this->_formatter = formatter;
		}
		return formatter;
	}

	/**
	 * Writes the log to the file itself
	 *
	 * @param string message
	 * @param int type
	 * @param int time
	 */
	public function logInternal(string! message, int type, int time)
	{
		var fileHandler, formatter;

		let fileHandler = this->_fileHandler;
		if !fileHandler {
			throw new Phalcon\Logger\Exception("Cannot send message to the log because it is invalid");
		}

		let formatter = this->getFormatter();
		fwrite(fileHandler, formatter->format(message, type, time));
	}

	/**
 	 * Closes the logger
 	 *
 	 * @return boolean
 	 */
	public function close() -> boolean
	{
		return fclose(this->_fileHandler);
	}

	/**
	 * Opens the internal file handler after unserialization
	 *
	 */
	public function __wakeup()
	{
		var path, options, mode;

		let path = this->_path;
		if typeof path != "string" {
			throw new Phalcon\Logger\Exception("Invalid data passed to Phalcon\\Logger\\Adapter\\File::__wakeup()");
		}

		let options = this->_options;
		if !fetch mode, options["mode"] {
			let mode = "ab";
		}

		if typeof mode != "string" {
			throw new Phalcon\Logger\Exception("Invalid data passed to Phalcon\\Logger\\Adapter\\File::__wakeup()");
		}

		if memstr(mode, "r") {
			throw new Phalcon\Logger\Exception("Logger must be opened in append or write mode");
		}

		/**
		 * Re-open the file handler if the logger was serialized
		 */
		let this->_fileHandler = fopen(path, mode);
	}

}
