
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Adapter;

use Phalcon\Logger;
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
     * @var FormatterInterface
     */
    protected formatter;

    /**
     * Tells if there is an active transaction or not
     *
     * @var bool
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
    public function add(<Item> item) -> <AdapterInterface>
    {
        let this->queue[] = item;

        return this;
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
        var inTransaction, item, queue;

        let inTransaction = this->inTransaction,
            queue         = this->queue;

        if !inTransaction {
            throw new Exception("There is no active transaction");
        }

        /**
         * Check if the queue has something to log
         */
        for item in queue {
            this->process(item);
        }

        // Clear logger queue at commit
        let inTransaction       = false,
            this->queue         = [],
            this->inTransaction = inTransaction;

        return this;
    }

    public function getFormatter() -> <FormatterInterface>
    {
        string className;

        if typeof this->formatter !== "object" {
            let className = "Phalcon\\Logger\\Formatter\\" . this->defaultFormatter;

            let this->formatter = create_instance(className);
        }

        return this->formatter;
    }

    /**
     * Returns the whether the logger is currently in an active transaction or not
     */
    public function inTransaction() -> bool
    {
        return this->inTransaction;
    }

    /**
      * Processes the message in the adapter
      */
    abstract public function process(<Item> item) -> void;

    /**
     * Rollbacks the internal transaction
     */
    public function rollback() -> <AdapterInterface>
    {
        var inTransaction;

        let inTransaction = this->inTransaction;

        if !inTransaction {
            throw new Exception("There is no active transaction");
        }

        let this->queue         = [],
            inTransaction       = false,
            this->inTransaction = inTransaction;

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

    /**
     * Returns the formatted item
     */
    protected function getFormattedItem(<Item> item) -> string
    {
        var formatter;

        let formatter = this->getFormatter();

        return formatter->format(item) . PHP_EOL;
    }
}
