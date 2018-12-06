
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Adapter;

use Phalcon\Logger;
use Phalcon\Logger\Adapter\AdapterInterface;
use Phalcon\Logger\Exception;
use Phalcon\Logger\Formatter\FormatterInterface;
use Phalcon\Logger\Item;

abstract class AbstractAdapter implements AdapterInterface
{
	/**
	 * Name of the default formatter class
	 *
	 * @var string
	 */
	protected defaultFormatter = "Line";

	/**
	 * Formatter
	 *
	 * @var <FormatterInterface>
	 */
	protected formatter;

	/**
	 * Tells if there is an active transaction or not
	 *
	 * @var boolean
	 */
	protected inTransaction = false;

	/**
	 * Array with messages queued in the transaction
	 *
	 * @var array
	 */
	protected queue = [];

	/**
	 * Destructor cleanup
	 */
	public function __destruct()
	{
		if this->inTransaction {
			this->commit();
		}

		this->close();
	}

	/**
 	 * Adds a message to the queue
 	 */
	public function add(<Item> item) -> void
	{
		let this->queue[] = item;
	}

	/**
 	 * Starts a transaction
 	 */
	public function begin() -> <AdapterInterface>
	{
		let this->inTransaction = true;

		return this;
	}

	/**
 	 * Commits the internal transaction
 	 */
	public function commit() -> <AdapterInterface>
	{
		var item;

		if !this->inTransaction {
			throw new Exception("There is no active transaction");
		}

		let this->inTansaction = false;

		/**
		 * Check if the queue has something to log
		 */
		for item in this->queue {
			this->process(item);
		}

		// Clear logger queue at commit
		let this->queue = [];

		return this;
	}

	public function getFormatter() -> <FormatterInterface>
	{
		string className;

		if typeof this->formatter !== "object" {
			let className = "Phalcon\\Logger\\Formatter\\" . this->defaultFormatter;
			let this->formatter = new {className}();
		}

		return this->formatter;
	}

	/**
	 * Returns the whether the logger is currently in an active transaction or not
	 */
	public function inTransaction() -> boolean
	{
		return this->inTransaction;
	}

	/**
 	 * Processes the message in the adapter
 	 */
	public function process(<Item> item) -> boolean
	{
		throw new Exception("This method cannot be called directly in the adapter");
	}

	/**
 	 * Rollbacks the internal transaction
 	 */
	public function rollback() -> <AdapterInterface>
	{
		var transaction;

		let transaction = this->inTransaction;
		if !transaction {
			throw new Exception("There is no active transaction");
		}

		let this->inTransaction = false,
			this->queue         = [];

		return this;
	}

	/**
	 * Sets the message formatter
	 */
	public function setFormatter(<FormatterInterface> formatter) -> <AdapterInterface>
	{
		let this->formatter = formatter;

		return this;
	}
}
