
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Transaction\ManagerInterface
 *
 * Interface for Phalcon\Mvc\Model\Transaction\Manager
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction_ManagerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model\\Transaction, ManagerInterface, phalcon, mvc_model_transaction_managerinterface, phalcon_mvc_model_transaction_managerinterface_method_entry);

	return SUCCESS;

}

/**
 * Remove all the transactions from the manager
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, collectTransactions);
/**
 * Commits active transactions within the manager
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, commit);
/**
 * Returns a new \Phalcon\Mvc\Model\Transaction or an already created once
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, get);
/**
 * Returns the database service used to isolate the transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, getDbService);
/**
 * Check if the transaction manager is registering a shutdown function to clean up pendent transactions
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, getRollbackPendent);
/**
 * Checks whether manager has an active transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, has);
/**
 * Notifies the manager about a committed transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyCommit);
/**
 * Notifies the manager about a rollbacked transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyRollback);
/**
 * Rollbacks active transactions within the manager
 * Collect will remove transaction from the manager
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollback);
/**
 * Rollbacks active transactions within the manager
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollbackPendent);
/**
 * Sets the database service used to run the isolated transactions
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, setDbService);
/**
 * Set if the transaction manager must register a shutdown function to clean up pendent transactions
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, setRollbackPendent);
