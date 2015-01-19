
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


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
 * Phalcon\Mvc\Model\Transaction\Manager
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, __construct);

/**
 * Checks whether manager has an active transaction
 *
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, has);

/**
 * Returns a new \Phalcon\Mvc\Model\Transaction or an already created once
 *
 * @param boolean autoBegin
 * @return Phalcon\Mvc\Model\TransactionInterface
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, get);

/**
 * Rollbacks active transactions within the manager
 *
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollbackPendent);

/**
 * Commmits active transactions within the manager
 *
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
 *
 * @param Phalcon\Mvc\Model\TransactionInterface transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyRollback);

/**
 * Notifies the manager about a commited transaction
 *
 * @param Phalcon\Mvc\Model\TransactionInterface transaction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyCommit);

/**
 * Remove all the transactions from the manager
 *
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, collectTransactions);

