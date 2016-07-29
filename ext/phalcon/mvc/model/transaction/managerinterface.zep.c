
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 * Checks whether manager has an active transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, has);

/**
 * Returns a new \Phalcon\Mvc\Model\Transaction or an already created once
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, get);

/**
 * Rollbacks active transactions within the manager
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollbackPendent);

/**
 * Commits active transactions within the manager
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, commit);

/**
 * Rollbacks active transactions within the manager
 * Collect will remove transaction from the manager
 *
 * @param boolean collect
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollback);

/**
 * Notifies the manager about a rollbacked transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyRollback);

/**
 * Notifies the manager about a committed transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyCommit);

/**
 * Remove all the transactions from the manager
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, collectTransactions);

