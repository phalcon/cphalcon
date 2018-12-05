
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Adapter;

use Phalcon\Logger\Adapter;
use Phalcon\Logger\Exception;
use Phalcon\Logger\Formatter\FormatterInterface;
use Phalcon\Logger\Item;

/**
 * Phalcon\Logger\Adapter\File
 *
 * Adapter to store logs in plain text files
 *
 *<code>
 * $logger = new \Phalcon\Logger\Adapter\File("app/logs/test.log");
 *
 * $logger->log("This is a message");
 * $logger->log(\Phalcon\Logger::ERROR, "This is an error");
 * $logger->error("This is another error");
 *
 * $logger->close();
 *</code>
 */
class File extends AbstractAdapter
{
	/**
	 * File handler resource
	 *
	 * @var resource
	 */
	protected fileHandler;

	/**
	 * The file open mode. Defaults to "ab"
	 *
	 * @var string
	 */
	protected mode = "ab";

	/**
	 * Path options
	 *
	 * @var array
	 */
	protected options;

	/**
	 * File Path
	 *
	 * @var string
	 */
	protected path { get };

	public function __construct(string! name, array options = [])
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

		let this->path        = name,
			this->mode        = mode,
			this->options     = options,
			this->fileHandler = handler;
	}

	public function __wakeup()
	{
		var path, mode;

		let path = this->path;
		if typeof path !== "string" {
			throw new Exception("Invalid data passed to Phalcon\\Logger\\Adapter\\File::__wakeup()");
		}

		if !fetch mode, this->options["mode"] {
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
		let this->fileHandler = fopen(path, mode);
	}

	public function close() -> boolean
	{
		return true;
	}

	public function process(<Item> item)
	{
		var handler, formatter;

		let formatter = this->getFormatter();

		/**
		 * We use 'fopen' to respect to open-basedir directive
		 */
		let handler = fopen(this->path, this->mode);
		if typeof handler != "resource" {
			throw new Exception("Can't open log file at '" . this->path . "'");
		}

		fwrite(handler, formatter->format(item));
		fclose(handler);
	}
}
