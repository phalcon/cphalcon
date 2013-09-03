
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
 * Phalcon\Mvc\Model\TransactionInterface
 *
 * Interface for Phalcon\Mvc\Model\Transaction
 */
interface TransactionInterface
{

	/**
	 * Phalcon\Mvc\Model\Transaction constructor
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 * @param boolean autoBegin
	 * @param string service
	 */
	public function __construct(dependencyInjector, autoBegin=false, service=null);

	/**
	 * Sets transaction manager related to the transaction
	 *
	 * @param Phalcon\Mvc\Model\Transaction\ManagerInterface manager
	 */
	public function setTransactionManager(manager);

	/**
	 * Starts the transaction
	 *
	 * @return boolean
	 */
	public function begin();

	/**
	 * Commits the transaction
	 *
	 * @return boolean
	 */
	public function commit();

	/**
	 * Rollbacks the transaction
	 *
	 * @param  string rollbackMessage
	 * @param  Phalcon\Mvc\ModelInterface rollbackRecord
	 * @return boolean
	 */
	public function rollback(rollbackMessage=null, rollbackRecord=null);

	/**
	 * Returns connection related to transaction
	 *
	 * @return string
	 */
	public function getConnection();

	/**
	 * Sets if is a reused transaction or new once
	 *
	 * @param boolean isNew
	 */
	public function setIsNewTransaction(isNew);

	/**
	 * Sets flag to rollback on abort the HTTP connection
	 *
	 * @param boolean rollbackOnAbort
	 */
	public function setRollbackOnAbort(rollbackOnAbort);

	/**
	 * Checks whether transaction is managed by a transaction manager
	 *
	 * @return boolean
	 */
	public function isManaged();

	/**
	 * Returns validations messages from last save try
	 *
	 * @return array
	 */
	public function getMessages();

	/**
	 * Checks whether internal connection is under an active transaction
	 *
	 * @return boolean
	 */
	public function isValid();

	/**
	 * Sets object which generates rollback action
	 *
	 * @param Phalcon\Mvc\ModelInterface record
	 */
	public function setRollbackedRecord(record);

}
