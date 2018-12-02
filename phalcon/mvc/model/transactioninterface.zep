
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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
	 * Sets transaction manager related to the transaction
	 */
	public function setTransactionManager(<ManagerInterface> manager);

	/**
	 * Starts the transaction
	 */
	public function begin() -> boolean;

	/**
	 * Commits the transaction
	 */
	public function commit() -> boolean;

	/**
	 * Rollbacks the transaction
	 */
	public function rollback(rollbackMessage = null, <ModelInterface> rollbackRecord = null);

	/**
	 * Returns connection related to transaction
	 */
	public function getConnection() -> <\Phalcon\Db\AdapterInterface>;

	/**
	 * Sets if is a reused transaction or new once
	 */
	public function setIsNewTransaction(boolean isNew);

	/**
	 * Sets flag to rollback on abort the HTTP connection
	 */
	public function setRollbackOnAbort(boolean rollbackOnAbort);

	/**
	 * Checks whether transaction is managed by a transaction manager
	 */
	public function isManaged() -> boolean;

	/**
	 * Returns validations messages from last save try
	 */
	public function getMessages() -> array;

	/**
	 * Checks whether internal connection is under an active transaction
	 */
	public function isValid() -> boolean;

	/**
	 * Sets object which generates rollback action
	 */
	public function setRollbackedRecord(<ModelInterface> record);
}
