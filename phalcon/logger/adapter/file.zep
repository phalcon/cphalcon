
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
	 * @var resource|null
	 */
	protected fileHandler = null;

	/**
	 * The file open mode. Defaults to "ab"
	 *
	 * @var string
	 */
	protected mode = "ab";

	/**
	 * File name
	 *
	 * @var string
	 */
	protected name { get };

	/**
	 * Path options
	 *
	 * @var array
	 */
	protected options;

	/**
	 * Constructor. Accepts the name and some options
	 */
	public function __construct(string! name, array options = [])
	{
		var mode;

		/**
		 * Mode
		 */
		if fetch mode, options["mode"] {
			if memstr(mode, "r") {
				throw new Exception("Adapter cannot be opened in read mode");
			}
		}

		if mode === null {
			let mode = "ab";
		}

		let this->name = name,
			this->mode = mode;
	}

	/**
	 * Closes the stream
	 */
	public function close() -> bool
	{
		bool result = true;

		if is_resource(this->fileHandler) {
			let result = fclose(this->fileHandler);
		}

		let this->fileHandler = null;

		return result;
	}

	/**
	 * Processes the message i.e. writes it to the file
	 */
	public function process(<Item> item)
	{
		var formatter, formattedMessage;

		if !is_resource(this->fileHandler) {
			let this->fileHandler = fopen(this->name, this->mode);

            if !is_resource(this->fileHandler) {
                let $this->fileHandler = null;
                throw new \UnexpectedValueException(
                	sprintf("The file '%s' cannot be opened with mode '%s'", this->name, this->mode)
				);
            }
		}

		let formatter        = this->getFormatter(),
			formattedMessage = formatter->format(item);

		fwrite(this->fileHandler, formattedMessage);
	}
}
