
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Adapter;

use Phalcon\Logger\Exceptions\DeserializationFailed;
use Phalcon\Logger\Exceptions\SerializationFailed;
use Phalcon\Logger\Exceptions\TransactionAlreadyActive;
use Phalcon\Logger\Exceptions\TransactionNotActive;
use Phalcon\Logger\Formatter\FormatterInterface;
use Phalcon\Logger\Formatter\Line;
use Phalcon\Logger\Item;

/**
 * Class AbstractAdapter
 *
 * @property string             $defaultFormatter
 * @property FormatterInterface $formatter
 * @property bool               $inTransaction
 * @property array              $queue
 */
abstract class AbstractAdapter implements AdapterInterface
{
    /**
     * Name of the default formatter class
     *
     * @var string
     */
    protected defaultFormatter = "Phalcon\\Logger\Formatter\\Line";

    /**
     * Formatter
     *
     * @var FormatterInterface|null
     */
    protected formatter = null;

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
     *
     * @throws TransactionAlreadyActive
     */
    public function __destruct()
    {
        if this->inTransaction {
            throw new TransactionAlreadyActive();
        }

        this->close();
    }

    /**
     * Prevent serialization
     */
    public function __serialize() -> array
    {
        throw new SerializationFailed();
    }

    /**
     * Prevent unserialization
     */
    public function __unserialize(array data) -> void
    {
        throw new DeserializationFailed();
    }

    /**
     * Adds a message to the queue
     *
     * @param Item $item
     *
     * @return AdapterInterface
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
     *
     * @return AdapterInterface
     * @throws Exception
     */
    public function commit() -> <AdapterInterface>
    {
        var item, queue;

        this->checkTransaction();

        let queue = this->queue;

        /**
         * Check if the queue has something to log
         */
        for item in queue {
            this->process(item);
        }

        // Clear logger queue at commit
        this->resetTransaction();

        return this;
    }

    /**
     * @return FormatterInterface
     */
    public function getFormatter() -> <FormatterInterface>
    {
        if null === this->formatter {
            let this->formatter = create_instance(this->defaultFormatter);
        }

        return this->formatter;
    }

    /**
     * Returns the whether the logger is currently in an active transaction or
     * not
     */
    public function inTransaction() -> bool
    {
        return this->inTransaction;
    }

    /**
     * Processes the message in the adapter
     *
     * @param Item $item
     */
    abstract public function process(<Item> item) -> void;

    /**
     * Rollbacks the internal transaction
     *
     * @return AdapterInterface
     * @throws Exception
     */
    public function rollback() -> <AdapterInterface>
    {
        this->checkTransaction();
        this->resetTransaction();

        return this;
    }

    /**
     * Sets the message formatter
     *
     * @param FormatterInterface $formatter
     *
     * @return AdapterInterface
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

        return formatter->format(item);
    }

    /**
     * Checks if the transaction is active
     *
     * @throws TransactionNotActive
     */
    private function checkTransaction() -> void
    {
        if (true !== this->inTransaction) {
            throw new TransactionNotActive();
        }
    }

    /**
     * Resets the transaction flag and queue array
     */
    private function resetTransaction() -> void
    {
        let this->queue         = [],
            this->inTransaction = false;
    }
}
