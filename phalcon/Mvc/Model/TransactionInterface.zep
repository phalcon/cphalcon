
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\Transaction\ManagerInterface;

/**
 * Phalcon\Mvc\Model\TransactionInterface
 *
 * Interface for Phalcon\Mvc\Model\Transaction
 */
interface TransactionInterface
{
    /**
     * Starts the transaction
     */
    public function begin() -> bool;

    /**
     * Commits the transaction
     */
    public function commit() -> bool;

    /**
     * Returns connection related to transaction
     */
    public function getConnection() -> <\Phalcon\Db\Adapter\AdapterInterface>;

    /**
     * Returns validations messages from last save try
     */
    public function getMessages() -> array;

    /**
     * Checks whether transaction is managed by a transaction manager
     */
    public function isManaged() -> bool;

    /**
     * Checks whether internal connection is under an active transaction
     */
    public function isValid() -> bool;

    /**
     * Rollbacks the transaction
     */
    public function rollback(string rollbackMessage = null, <ModelInterface> rollbackRecord = null) -> bool;

    /**
     * Sets if is a reused transaction or new once
     */
    public function setIsNewTransaction(bool isNew) -> void;

    /**
     * Sets flag to rollback on abort the HTTP connection
     */
    public function setRollbackOnAbort(bool rollbackOnAbort) -> void;

    /**
     * Sets object which generates rollback action
     */
    public function setRollbackedRecord(<ModelInterface> record) -> void;

    /**
     * Sets transaction manager related to the transaction
     */
    public function setTransactionManager(<ManagerInterface> manager) -> void;

    /**
     * Enables throwing exception
     */
    public function throwRollbackException(bool status) -> <TransactionInterface>;
}
