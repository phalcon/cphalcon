
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Di\DiInterface;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\Transaction\Failed as TxFailed;
use Phalcon\Mvc\Model\Transaction\ManagerInterface;
use Phalcon\Mvc\Model\TransactionInterface;

/**
 * Phalcon\Mvc\Model\Transaction
 *
 * Transactions are protective blocks where SQL statements are only permanent if
 * they can all succeed as one atomic action. Phalcon\Transaction is intended to
 * be used with Phalcon_Model_Base. Phalcon Transactions should be created using
 * Phalcon\Transaction\Manager.
 *
 * ```php
 * use Phalcon\Mvc\Model\Transaction\Failed;
 * use Phalcon\Mvc\Model\Transaction\Manager;
 *
 * try {
 *     $manager = new Manager();
 *
 *     $transaction = $manager->get();
 *
 *     $robot = new Robots();
 *
 *     $robot->setTransaction($transaction);
 *
 *     $robot->name       = "WALL·E";
 *     $robot->created_at = date("Y-m-d");
 *
 *     if ($robot->save() === false) {
 *         $transaction->rollback("Can't save robot");
 *     }
 *
 *     $robotPart = new RobotParts();
 *
 *     $robotPart->setTransaction($transaction);
 *
 *     $robotPart->type = "head";
 *
 *     if ($robotPart->save() === false) {
 *         $transaction->rollback("Can't save robot part");
 *     }
 *
 *     $transaction->commit();
 * } catch(Failed $e) {
 *     echo "Failed, reason: ", $e->getMessage();
 * }
 * ```
 */
class Transaction implements TransactionInterface
{
    protected activeTransaction = false;

    protected connection;

    protected isNewTransaction = true;

    protected manager;

    protected messages = [];

    protected rollbackRecord;

    protected rollbackOnAbort = false;

    protected rollbackThrowException = false;

    /**
     * Phalcon\Mvc\Model\Transaction constructor
     */
    public function __construct(<DiInterface> container, bool autoBegin = false, string service = "db")
    {
        var connection;

        let this->messages = [];

        let connection = container->get(service);

        let this->connection = connection;

        if autoBegin {
            connection->begin();
        }
    }

    /**
     * Starts the transaction
     */
    public function begin() -> bool
    {
        return this->connection->begin();
    }

    /**
     * Commits the transaction
     */
    public function commit() -> bool
    {
        var manager;

        let manager = this->manager;

        if typeof manager == "object" {
            manager->notifyCommit(this);
        }

        return this->connection->commit();
    }

    /**
     * Returns the connection related to transaction
     */
    public function getConnection() -> <\Phalcon\Db\Adapter\AdapterInterface>
    {
        if this->rollbackOnAbort {
            if connection_aborted() {
                this->rollback("The request was aborted");
            }
        }

        return this->connection;
    }

    /**
     * Returns validations messages from last save try
     */
    public function getMessages() -> array
    {
        return this->messages;
    }

    /**
     * Checks whether transaction is managed by a transaction manager
     */
    public function isManaged() -> bool
    {
        return typeof this->manager == "object";
    }

    /**
     * Checks whether internal connection is under an active transaction
     */
    public function isValid() -> bool
    {
        return this->connection->isUnderTransaction();
    }

    /**
     * Rollbacks the transaction
     */
    public function rollback(string rollbackMessage = null, <ModelInterface> rollbackRecord = null) -> bool
    {
        var manager, connection;

        let manager = this->manager;

        if typeof manager == "object" {
            manager->notifyRollback(this);
        }

        let connection = this->connection;

        if unlikely connection->rollback() {
            if !rollbackMessage {
                let rollbackMessage = "Transaction aborted";
            }

            if typeof rollbackRecord == "object" {
                let this->rollbackRecord = rollbackRecord;
            }

            if this->rollbackThrowException {
                throw new TxFailed(rollbackMessage, this->rollbackRecord);
            }
        }

        return true;
    }

    /**
     * Sets if is a reused transaction or new once
     */
    public function setIsNewTransaction(bool isNew) -> void
    {
        let this->isNewTransaction = isNew;
    }

    /**
     * Sets flag to rollback on abort the HTTP connection
     */
    public function setRollbackOnAbort(bool rollbackOnAbort) -> void
    {
        let this->rollbackOnAbort = rollbackOnAbort;
    }

    /**
     * Sets object which generates rollback action
     */
    public function setRollbackedRecord(<ModelInterface> record) -> void
    {
        let this->rollbackRecord = record;
    }

    /**
     * Sets transaction manager related to the transaction
     */
    public function setTransactionManager(<ManagerInterface> manager) -> void
    {
        let this->manager = manager;
    }

    /**
     * Enables throwing exception
     */
    public function throwRollbackException(bool status) -> <TransactionInterface>
    {
        let this->rollbackThrowException = status;

        return this;
    }
}
