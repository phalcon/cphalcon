
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\Model\TransactionInterface
 *
 * Interface for Phalcon\Mvc\Model\Transaction
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_TransactionInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, TransactionInterface, phalcon, mvc_model_transactioninterface, phalcon_mvc_model_transactioninterface_method_entry);

	return SUCCESS;

}

/**
 * Sets transaction manager related to the transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, setTransactionManager);

/**
 * Starts the transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, begin);

/**
 * Commits the transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, commit);

/**
 * Rollbacks the transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, rollback);

/**
 * Returns connection related to transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, getConnection);

/**
 * Sets if is a reused transaction or new once
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, setIsNewTransaction);

/**
 * Sets flag to rollback on abort the HTTP connection
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, setRollbackOnAbort);

/**
 * Checks whether transaction is managed by a transaction manager
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, isManaged);

/**
 * Returns validations messages from last save try
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, getMessages);

/**
 * Checks whether internal connection is under an active transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, isValid);

/**
 * Sets object which generates rollback action
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_TransactionInterface, setRollbackedRecord);

