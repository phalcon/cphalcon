
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\DiInterface;
use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\Transaction\Failed as TxFailed;
use Phalcon\Mvc\Model\Transaction\ManagerInterface;
use Phalcon\Mvc\Model\TransactionInterface;

/**
 * Phalcon\Mvc\Model\Transaction
 *
 * Transactions are protective blocks where SQL statements are only permanent if they can
 * all succeed as one atomic action. Phalcon\Transaction is intended to be used with Phalcon_Model_Base.
 * Phalcon Transactions should be created using Phalcon\Transaction\Manager.
 *
 * <code>
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
 * </code>
 */
class Transaction implements TransactionInterface
{
	protected _connection;

	protected _activeTransaction = false;

	protected _isNewTransaction = true;

	protected _rollbackOnAbort = false;

	protected _manager;

	protected _messages;

	protected _rollbackRecord;

	/**
	 * Phalcon\Mvc\Model\Transaction constructor
	 */
	public function __construct(<DiInterface> dependencyInjector, bool autoBegin = false, string service = null)
	{
		var connection;

		let this->_messages = [];

		if service {
			let connection = dependencyInjector->get(service);
		} else {
			let connection = dependencyInjector->get("db");
		}

		let this->_connection = connection;
		if autoBegin {
			connection->begin();
		}
	}

	/**
	 * Sets transaction manager related to the transaction
	 */
	public function setTransactionManager(<ManagerInterface> manager)
	{
		let this->_manager = manager;
	}

	/**
	 * Starts the transaction
	 */
	public function begin() -> bool
	{
		return this->_connection->begin();
	}

	/**
	 * Commits the transaction
	 */
	public function commit() -> bool
	{
		var manager;

		let manager = this->_manager;
		if typeof manager == "object" {
			manager->notifyCommit(this);
		}

		return this->_connection->commit();
	}

	/**
	 * Rollbacks the transaction
	 */
	public function rollback(string rollbackMessage = null, <ModelInterface> rollbackRecord = null) -> bool
	{
		var manager, connection;

		let manager = this->_manager;
		if typeof manager == "object" {
			manager->notifyRollback(this);
		}

		let connection = this->_connection;
		if connection->rollback() {
			if !rollbackMessage {
				let rollbackMessage = "Transaction aborted";
			}
			if typeof rollbackRecord == "object" {
				let this->_rollbackRecord = rollbackRecord;
			}
			throw new TxFailed(rollbackMessage, this->_rollbackRecord);
		}

		return true;
	}

	/**
	 * Returns the connection related to transaction
	 */
	public function getConnection() -> <\Phalcon\Db\AdapterInterface>
	{
		if this->_rollbackOnAbort {
			if connection_aborted() {
				this->rollback("The request was aborted");
			}
		}
		return this->_connection;
	}

	/**
	 * Sets if is a reused transaction or new once
	 */
	public function setIsNewTransaction(bool isNew)
	{
		let this->_isNewTransaction = isNew;
	}

	/**
	 * Sets flag to rollback on abort the HTTP connection
	 */
	public function setRollbackOnAbort(bool rollbackOnAbort)
	{
		let this->_rollbackOnAbort = rollbackOnAbort;
	}

	/**
	 * Checks whether transaction is managed by a transaction manager
	 */
	public function isManaged() -> bool
	{
		return typeof this->_manager == "object";
	}

	/**
	 * Returns validations messages from last save try
	 */
	public function getMessages() -> array
	{
		return this->_messages;
	}

	/**
	 * Checks whether internal connection is under an active transaction
	 */
	public function isValid() -> bool
	{
		return this->_connection->isUnderTransaction();
	}

	/**
	 * Sets object which generates rollback action
	 */
	public function setRollbackedRecord(<ModelInterface> record)
	{
		let this->_rollbackRecord = record;
	}
}
