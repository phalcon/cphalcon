
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model;

/**
 * Phalcon\Mvc\Model\Transaction
 *
 * Transactions are protective blocks where SQL statements are only permanent if they can
 * all succeed as one atomic action. Phalcon\Transaction is intended to be used with Phalcon_Model_Base.
 * Phalcon Transactions should be created using Phalcon\Transaction\Manager.
 *
 *<code>
 *try {
 *
 *  $manager = new Phalcon\Mvc\Model\Transaction\Manager();
 *
 *  $transaction = $manager->get();
 *
 *  $robot = new Robots();
 *  $robot->setTransaction($transaction);
 *  $robot->name = 'WALL·E';
 *  $robot->created_at = date('Y-m-d');
 *  if ($robot->save() == false) {
 *    $transaction->rollback("Can't save robot");
 *  }
 *
 *  $robotPart = new RobotParts();
 *  $robotPart->setTransaction($transaction);
 *  $robotPart->type = 'head';
 *  if ($robotPart->save() == false) {
 *    $transaction->rollback("Can't save robot part");
 *  }
 *
 *  $transaction->commit();
 *
 *} catch(Phalcon\Mvc\Model\Transaction\Failed $e) {
 *  echo 'Failed, reason: ', $e->getMessage();
 *}
 *
 *</code>
 */
class Transaction implements Phalcon\Mvc\Model\TransactionInterface
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
	 *
	 * @param Phalcon\DiInterface $ependencyInjector
	 * @param boolean autoBegin
	 * @param string service
	 */
	public function __construct(<Phalcon\DiInterface> dependencyInjector, boolean autoBegin=false, service=null)
	{
		var connection;

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
	 *
	 * @param Phalcon\Mvc\Model\Transaction\ManagerInterface $manager
	 */
	public function setTransactionManager(<Phalcon\Mvc\Model\Transaction\ManagerInterface> manager)
	{
		let this->_manager = manager;
	}

	/**
	 * Starts the transaction
	 *
	 * @return boolean
	 */
	public function begin()
	{
		var connection;
		let connection = this->_connection;
		return connection->begin();
	}

	/**
	 * Commits the transaction
	 *
	 * @return boolean
	 */
	public function commit() -> boolean
	{
		var manager, connection;

		let manager = this->_manager;
		if typeof manager == "object" {
			call_user_func_array([manager, "notifyCommit"], [this]);
		}

		let connection = this->_connection;
		return connection->commit();
	}

	/**
	 * Rollbacks the transaction
	 *
	 * @param  string rollbackMessage
	 * @param  Phalcon\Mvc\ModelInterface rollbackRecord
	 * @return boolean
	 */
	public function rollback(rollbackMessage=null, rollbackRecord=null) -> boolean
	{
		var manager, connection;

		let manager = this->_manager;
		if typeof manager == "object" {
			call_user_func_array([manager, "notifyRollback"], [this]);
		}

		let connection = this->_connection;
		if connection->rollback() {
			if !rollbackMessage {
				let rollbackMessage = "Transaction aborted";
			}
			if typeof rollbackRecord == "object" {
				let this->_rollbackRecord = rollbackRecord;
			}
			throw new Phalcon\Mvc\Model\Transaction\Failed(rollbackMessage, this->_rollbackRecord);
		}
	}

	/**
	 * Returns the connection related to transaction
	 *
	 * @return Phalcon\Db\AdapterInterface
	 */
	public function getConnection()
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
	 *
	 * @param boolean isNew
	 */
	public function setIsNewTransaction(boolean isNew)
	{
		let this->_isNewTransaction = isNew;
	}

	/**
	 * Sets flag to rollback on abort the HTTP connection
	 *
	 * @param boolean $rollbackOnAbort
	 */
	public function setRollbackOnAbort(boolean rollbackOnAbort)
	{
		let this->_rollbackOnAbort = rollbackOnAbort;
	}

	/**
	 * Checks whether transaction is managed by a transaction manager
	 *
	 * @return boolean
	 */
	public function isManaged() -> boolean
	{
		return !this->_manager;
	}

	/**
	 * Returns validations messages from last save try
	 *
	 * @return array
	 */
	public function getMessages()
	{
		return this->_messages;
	}

	/**
	 * Checks whether internal connection is under an active transaction
	 *
	 * @return boolean
	 */
	public function isValid() -> boolean
	{
		var connection;
		let connection = this->_connection;
		return connection->isUnderTransaction();
	}

	/**
	 * Sets object which generates rollback action
	 *
	 * @param Phalcon\Mvc\ModelInterface $record
	 */
	public function setRollbackedRecord(<Phalcon\Mvc\ModelInterface> record)
	{
		let this->_rollbackRecord = record;
	}

}
