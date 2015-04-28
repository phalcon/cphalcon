
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Mvc\Model\Transaction;

use Phalcon\DiInterface;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Mvc\Model\Transaction\ManagerInterface;
use Phalcon\Mvc\Model\Transaction\Exception;
use Phalcon\Mvc\Model\Transaction;
use Phalcon\Mvc\Model\TransactionInterface;

/**
 * Phalcon\Mvc\Model\Transaction\Manager
 *
 * A transaction acts on a single database connection. If you have multiple class-specific
 * databases, the transaction will not protect interaction among them.
 *
 * This class manages the objects that compose a transaction.
 * A trasaction produces a unique connection that is passed to every
 * object part of the transaction.
 *
 *<code>
 *try {
 *
 *  use Phalcon\Mvc\Model\Transaction\Manager as TransactionManager;
 *
 *  $transactionManager = new TransactionManager();
 *
 *  $transaction = $transactionManager->get();
 *
 *  $robot = new Robots();
 *  $robot->setTransaction($transaction);
 *  $robot->name = 'WALL·E';
 *  $robot->created_at = date('Y-m-d');
 *  if($robot->save()==false){
 *    $transaction->rollback("Can't save robot");
 *  }
 *
 *  $robotPart = new RobotParts();
 *  $robotPart->setTransaction($transaction);
 *  $robotPart->type = 'head';
 *  if($robotPart->save()==false){
 *    $transaction->rollback("Can't save robot part");
 *  }
 *
 *  $transaction->commit();
 *
 *} catch (Phalcon\Mvc\Model\Transaction\Failed $e) {
 *  echo 'Failed, reason: ', $e->getMessage();
 *}
 *
 *</code>
 *
 */
class Manager implements ManagerInterface, InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _initialized = false;

	protected _rollbackPendent = true;

	protected _number = 0;

	protected _service = "db";

	protected _transactions;

	/**
	 * Phalcon\Mvc\Model\Transaction\Manager constructor
	 */
	public function __construct(<DiInterface> dependencyInjector = null)
	{
		if dependencyInjector {
			let this->_dependencyInjector = dependencyInjector;
		} else {
			let dependencyInjector = \Phalcon\Di::getDefault(),
				this->_dependencyInjector = dependencyInjector;
		}

		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injector container is required to obtain the services related to the ORM");
		}
	}

	/**
	 * Sets the dependency injection container
	 */
	public function setDI(<DiInterface> dependencyInjector)
	{
		let this->_dependencyInjector = dependencyInjector;
	}

	/**
	 * Returns the dependency injection container
	 */
	public function getDI() -> <DiInterface>
	{
		return this->_dependencyInjector;
	}

	/**
	 * Sets the database service used to run the isolated transactions
	 */
	public function setDbService(string! service) -> <Manager>
	{
		let this->_service = service;
		return this;
	}

	/**
	 * Returns the database service used to isolate the transaction
	 *
	 * @return string
	 */
	public function getDbService()
	{
		return this->_service;
	}

	/**
	 * Set if the transaction manager must register a shutdown function to clean up pendent transactions
	 */
	public function setRollbackPendent(boolean rollbackPendent) -> <Manager>
	{
		let this->_rollbackPendent = rollbackPendent;
		return this;
	}

	/**
	 * Check if the transaction manager is registering a shutdown function to clean up pendent transactions
	 */
	public function getRollbackPendent() -> boolean
	{
		return this->_rollbackPendent;
	}

	/**
	 * Checks whether the manager has an active transaction
	 */
	public function has() -> boolean
	{
		return this->_number > 0;
	}

	/**
	 * Returns a new \Phalcon\Mvc\Model\Transaction or an already created once
	 * This method registers a shutdown function to rollback active connections
	 */
	public function get(boolean autoBegin = true) -> <TransactionInterface>
	{
		if !this->_initialized {
			if this->_rollbackPendent {
				register_shutdown_function([this, "rollbackPendent"]);
			}
			let this->_initialized = true;
		}
		return this->getOrCreateTransaction();
	}

	/**
	 * Create/Returns a new transaction or an existing one
	 */
	public function getOrCreateTransaction(boolean autoBegin = true) -> <TransactionInterface>
	{
		var dependencyInjector, transaction, transactions;

		let dependencyInjector = <DiInterface> this->_dependencyInjector;
		if typeof dependencyInjector != "object" {
			throw new Exception("A dependency injector container is required to obtain the services related to the ORM");
		}

		if this->_number {
			let transactions = this->_transactions;
			if typeof transactions == "array" {
				for transaction in reverse transactions {
					if typeof transaction == "object" {
						transaction->setIsNewTransaction(false);
						return transaction;
					}
				}
			}
		}

		let transaction = new Transaction(dependencyInjector, autoBegin, this->_service);
			transaction->setTransactionManager(this);

		let this->_transactions[] = transaction, this->_number++;

		return transaction;
	}

	/**
	 * Rollbacks active transactions within the manager
	 */
	public function rollbackPendent()
	{
		this->rollback();
	}

	/**
	 * Commmits active transactions within the manager
	 */
	public function commit()
	{
		var transactions, transaction, connection;
		let transactions = this->_transactions;
		if typeof transactions == "array" {
			for transaction in transactions {
				let connection = transaction->getConnection();
				if connection->isUnderTransaction() {
					connection->commit();
				}
			}
		}
	}

	/**
	 * Rollbacks active transactions within the manager
	 * Collect will remove the transaction from the manager
	 *
	 * @param boolean collect
	 */
	public function rollback(collect = true)
	{
		var transactions, transaction, connection;

		let transactions = this->_transactions;
		if typeof transactions == "array" {
			for transaction in transactions {
				let connection = transaction->getConnection();
				if connection->isUnderTransaction() {
					connection->rollback();
					connection->close();
				}
				if collect {
					this->_collectTransaction(transaction);
				}
			}
		}
	}

	/**
	 * Notifies the manager about a rollbacked transaction
	 */
	public function notifyRollback(<TransactionInterface> transaction)
	{
		this->_collectTransaction(transaction);
	}

	/**
	 * Notifies the manager about a commited transaction
	 */
	public function notifyCommit(<TransactionInterface> transaction)
	{
		this->_collectTransaction(transaction);
	}

	/**
	 * Removes transactions from the TransactionManager
	 */
	protected function _collectTransaction(<TransactionInterface> transaction)
	{
		var transactions, newTransactions, managedTransaction;

		let transactions = this->_transactions;
		if count(transactions) {
			let newTransactions = [];
			for managedTransaction in transactions {
				if managedTransaction == transaction {
					let newTransactions[] = transaction,
						this->_number--;
				}
			}
			let this->_transactions = newTransactions;
		}
	}

	/**
	 * Remove all the transactions from the manager
	 */
	public function collectTransactions()
	{
		var transactions;

		let transactions = this->_transactions;
		if count(transactions) {
			for _ in transactions {
				let this->_number--;
			}
			let this->_transactions = null;
		}
	}
}
