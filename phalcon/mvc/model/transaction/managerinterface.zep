
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

namespace Phalcon\Mvc\Model\Transaction;

/**
 * Phalcon\Mvc\Model\Transaction\ManagerInterface
 *
 * Interface for Phalcon\Mvc\Model\Transaction\Manager
 */
interface ManagerInterface
{

	/**
	 * Phalcon\Mvc\Model\Transaction\Manager
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function __construct(dependencyInjector=null);

	/**
	 * Checks whether manager has an active transaction
	 *
	 * @return boolean
	 */
	public function has();

	/**
	 * Returns a new Phalcon\Mvc\Model\Transaction or an already created once
	 *
	 * @param boolean autoBegin
	 * @return Phalcon\Mvc\Model\TransactionInterface
	 */
	public function get(autoBegin=true);

	/**
	 * Rollbacks active transactions within the manager
	 *
	 */
	public function rollbackPendent();

	/**
	 * Commmits active transactions within the manager
	 *
	 */
	public function commit();

	/**
	 * Rollbacks active transactions within the manager
	 * Collect will remove transaction from the manager
	 *
	 * @param boolean collect
	 */
	public function rollback(collect=false);

	/**
	 * Notifies the manager about a rollbacked transaction
	 *
	 * @param Phalcon\Mvc\Model\TransactionInterface transaction
	 */
	public function notifyRollback(transaction);

	/**
	 * Notifies the manager about a commited transaction
	 *
	 * @param Phalcon\Mvc\Model\TransactionInterface transaction
	 */
	public function notifyCommit(transaction);

	/**
	 * Remove all the transactions from the manager
	 *
	 */
	public function collectTransactions();

}