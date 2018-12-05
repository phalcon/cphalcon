
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Adapter;

use Phalcon\Logger\Exception;
use Phalcon\Logger\Adapter\AbstractAdapter;
use Phalcon\Logger\Formatter\FormatterInterface;
use Phalcon\Logger\Item;

/**
 * Phalcon\Logger\Adapter\Stream
 *
 * Sends logs to a valid PHP stream
 *
 * <code>
 * use Phalcon\Logger;
 * use Phalcon\Logger\Adapter\Stream;
 *
 * $logger = new Stream("php://stderr");
 *
 * $logger->log("This is a message");
 * $logger->log(Logger::ERROR, "This is an error");
 * $logger->error("This is another error");
 * </code>
 */
class Stream extends AbstractAdapter
{
	/**
	 * File handler resource
	 *
	 * @var resource
	 */
	protected stream;

	public function __construct(string! name, array options = [])
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

		let this->stream = stream;
	}

	public function close() -> bool
	{
		return fclose(this->stream);
	}

	public function process(<Item> item)
	{
		var stream, formatter;

		let stream    = this->stream,
			formatter = this->getFormatter();

		if typeof stream !== "resource" {
			throw new Exception("Cannot send message to the log because it is invalid");
		}

		fwrite(stream, formatter->format(item));
	}
}
