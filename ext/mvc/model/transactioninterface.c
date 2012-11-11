
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Mvc\Model\TransactionInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_TransactionInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, TransactionInterface, mvc_model_transactioninterface, phalcon_mvc_model_transactioninterface_method_entry);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Transaction constructor
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @param boolean $autoBegin
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, __construct);
/**
 * Sets transaction manager related to the transaction
 *
 * @param Phalcon\Mvc\Model\Transaction\ManagerInterface $manager
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, setTransactionManager);
/**
 * Starts the transaction
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, begin);
/**
 * Commits the transaction
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, commit);
/**
 * Rollbacks the transaction
 *
 * @param  string $rollbackMessage
 * @param  Phalcon\Mvc\ModelInterface $rollbackRecord
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, rollback);
/**
 * Returns connection related to transaction
 *
 * @return string
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, getConnection);
/**
 * Sets if is a reused transaction or new once
 *
 * @param boolean $isNew
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, setIsNewTransaction);
/**
 * Sets flag to rollback on abort the HTTP connection
 *
 * @param boolean $rollbackOnAbort
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, setRollbackOnAbort);
/**
 * Checks whether transaction is managed by a transaction manager
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, isManaged);
/**
 * Returns validations messages from last save try
 *
 * @return array
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, getMessages);
/**
 * Checks whether internal connection is under an active transaction
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, isValid);
/**
 * Sets object which generates rollback action
 *
 * @param Phalcon\Mvc\ModelInterface $record
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, setRollbackedRecord);
