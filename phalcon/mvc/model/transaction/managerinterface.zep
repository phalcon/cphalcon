
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Transaction;

use Phalcon\Mvc\Model\TransactionInterface;

/**
 * Phalcon\Mvc\Model\Transaction\ManagerInterface
 *
 * Interface for Phalcon\Mvc\Model\Transaction\Manager
 */
interface ManagerInterface
{
	/**
	 * Checks whether manager has an active transaction
	 */
	public function has() -> bool;

	/**
	 * Returns a new \Phalcon\Mvc\Model\Transaction or an already created once
	 */
	public function get(bool autoBegin = true) -> <\Phalcon\Mvc\Model\TransactionInterface>;

	/**
	 * Rollbacks active transactions within the manager
	 */
	public function rollbackPendent();

	/**
	 * Commits active transactions within the manager
	 */
	public function commit();

	/**
	 * Rollbacks active transactions within the manager
	 * Collect will remove transaction from the manager
	 */
	public function rollback(bool collect = false);

	/**
	 * Notifies the manager about a rollbacked transaction
	 */
	public function notifyRollback(<TransactionInterface> transaction);

	/**
	 * Notifies the manager about a committed transaction
	 */
	public function notifyCommit(<TransactionInterface> transaction);

	/**
	 * Remove all the transactions from the manager
	 */
	public function collectTransactions();

	/**
	 * Sets the database service used to run the isolated transactions
	 */
	public function setDbService(string! service) -> <ManagerInterface>;

	/**
	 * Returns the database service used to isolate the transaction
	 */
	public function getDbService() -> string;

	/**
	 * Set if the transaction manager must register a shutdown function to clean up pendent transactions
	 */
	public function setRollbackPendent(bool rollbackPendent) -> <ManagerInterface>;

	/**
	 * Check if the transaction manager is registering a shutdown function to clean up pendent transactions
	 */
	public function getRollbackPendent() -> bool;
}
