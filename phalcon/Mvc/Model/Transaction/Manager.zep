
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Transaction;

use Phalcon\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\Model\Transaction;
use Phalcon\Mvc\Model\TransactionInterface;

/**
 * Phalcon\Mvc\Model\Transaction\Manager
 *
 * A transaction acts on a single database connection. If you have multiple
 * class-specific databases, the transaction will not protect interaction among
 * them.
 *
 * This class manages the objects that compose a transaction.
 * A transaction produces a unique connection that is passed to every object
 * part of the transaction.
 *
 * ```php
 * use Phalcon\Mvc\Model\Transaction\Failed;
 * use Phalcon\Mvc\Model\Transaction\Manager;
 *
 * try {
 *    $transactionManager = new Manager();
 *
 *    $transaction = $transactionManager->get();
 *
 *    $robot = new Robots();
 *
 *    $robot->setTransaction($transaction);
 *
 *    $robot->name       = "WALL·E";
 *    $robot->created_at = date("Y-m-d");
 *
 *    if ($robot->save() === false) {
 *        $transaction->rollback("Can't save robot");
 *    }
 *
 *    $robotPart = new RobotParts();
 *
 *    $robotPart->setTransaction($transaction);
 *
 *    $robotPart->type = "head";
 *
 *    if ($robotPart->save() === false) {
 *        $transaction->rollback("Can't save robot part");
 *    }
 *
 *    $transaction->commit();
 * } catch (Failed $e) {
 *    echo "Failed, reason: ", $e->getMessage();
 * }
 *```
 */
class Manager implements ManagerInterface, InjectionAwareInterface
{
    /**
     * @var DiInterface|null
     */
    protected container;

    /**
     * @var bool
     */
    protected initialized = false;

    /**
     * @var int
     */
    protected number = 0;

    /**
     * @var bool
     */
    protected rollbackPendent = true;

    /**
     * @var string
     */
    protected service = "db";

    /**
     * @var array
     */
    protected transactions = [];

    /**
     * Phalcon\Mvc\Model\Transaction\Manager constructor
     *
     * @param DiInterface|null container
     */
    public function __construct(<DiInterface> container = null)
    {
        if !container {
            let container = Di::getDefault();
        }

        let this->container = container;

        if unlikely typeof container != "object" {
            throw new Exception(
                "A dependency injection container is required to access the services related to the ORM"
            );
        }
    }

    /**
     * Remove all the transactions from the manager
     */
    public function collectTransactions() -> void
    {
        var transactions;

        let transactions = this->transactions;

        for _ in transactions {
            let this->number--;
        }

        let this->transactions = [];
    }

    /**
     * Commits active transactions within the manager
     */
    public function commit()
    {
        var transactions, transaction, connection;

        let transactions = this->transactions;

        for transaction in transactions {
            let connection = transaction->getConnection();

            if connection->isUnderTransaction() {
                connection->commit();
            }
        }
    }

    /**
     * Returns a new \Phalcon\Mvc\Model\Transaction or an already created once
     * This method registers a shutdown function to rollback active connections
     *
     * @param bool autoBegin
     *
     * @return TransactionInterface
     */
    public function get(bool autoBegin = true) -> <TransactionInterface>
    {
        if !this->initialized {
            if this->rollbackPendent {
                register_shutdown_function(
                    [
                        this,
                        "rollbackPendent"
                    ]
                );
            }

            let this->initialized = true;
        }

        return this->getOrCreateTransaction(autoBegin);
    }

    /**
     * Returns the database service used to isolate the transaction
     */
    public function getDbService() -> string
    {
        return this->service;
    }

    /**
     * Returns the dependency injection container
     */
    public function getDI() -> <DiInterface>
    {
        return this->container;
    }

    /**
     * Create/Returns a new transaction or an existing one
     *
     * @param bool autoBegin
     *
     * @return TransactionInterface
     */
    public function getOrCreateTransaction(bool autoBegin = true) -> <TransactionInterface>
    {
        var container, transaction, transactions;

        let container = <DiInterface> this->container;

        if unlikely typeof container != "object" {
            throw new Exception(
                "A dependency injection container is required to access the services related to the ORM"
            );
        }

        if this->number {
            let transactions = this->transactions;

            for transaction in reverse transactions {
                if typeof transaction == "object" {
                    transaction->setIsNewTransaction(false);

                    return transaction;
                }
            }
        }

        let transaction = new Transaction(container, autoBegin, this->service);
            transaction->setTransactionManager(this);

        let this->transactions[] = transaction, this->number++;

        return transaction;
    }

    /**
     * Check if the transaction manager is registering a shutdown function to
     * clean up pendent transactions
     */
    public function getRollbackPendent() -> bool
    {
        return this->rollbackPendent;
    }

    /**
     * Checks whether the manager has an active transaction
     */
    public function has() -> bool
    {
        return this->number > 0;
    }

    /**
     * Notifies the manager about a committed transaction
     *
     * @param TransactionInterface transaction
     */
    public function notifyCommit(<TransactionInterface> transaction) -> void
    {
        this->collectTransaction(transaction);
    }

    /**
     * Notifies the manager about a rollbacked transaction
     *
     * @param TransactionInterface transaction
     */
    public function notifyRollback(<TransactionInterface> transaction) -> void
    {
        this->collectTransaction(transaction);
    }

    /**
     * Rollbacks active transactions within the manager
     * Collect will remove the transaction from the manager
     *
     * @param bool collect
     */
    public function rollback(bool collect = true) -> void
    {
        var transactions, transaction, connection;

        let transactions = this->transactions;

        for transaction in transactions {
            let connection = transaction->getConnection();

            if connection->isUnderTransaction() {
                connection->rollback();
                connection->close();
            }

            if collect {
                this->collectTransaction(transaction);
            }
        }
    }

    /**
     * Rollbacks active transactions within the manager
     */
    public function rollbackPendent() -> void
    {
        this->rollback();
    }

    /**
     * Sets the database service used to run the isolated transactions
     *
     * @param string service
     */
    public function setDbService(string! service) -> <ManagerInterface>
    {
        let this->service = service;

        return this;
    }

    /**
     * Sets the dependency injection container
     *
     * @param DiInterface container
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->container = container;
    }

    /**
     * Set if the transaction manager must register a shutdown function to clean
     * up pendent transactions
     *
     * @param bool rollbackPendent
     */
    public function setRollbackPendent(bool rollbackPendent) -> <ManagerInterface>
    {
        let this->rollbackPendent = rollbackPendent;

        return this;
    }

    /**
     * Removes transactions from the TransactionManager
     *
     * @param TransactionInterface transaction
     */
    protected function collectTransaction(<TransactionInterface> transaction) -> void
    {
        var managedTransaction;
        array newTransactions;

        let newTransactions = [];

        for managedTransaction in this->transactions {
            if managedTransaction != transaction {
                let newTransactions[] = transaction;
            } else {
                let this->number--;
            }
        }

        let this->transactions = newTransactions;
    }
}
