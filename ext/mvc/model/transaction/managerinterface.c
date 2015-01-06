
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/model/transaction/managerinterface.h"
#include "kernel/main.h"

zend_class_entry *phalcon_mvc_model_transaction_managerinterface_ce;

static const zend_function_entry phalcon_mvc_model_transaction_managerinterface_method_entry[] = {
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, has, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, get, arginfo_phalcon_mvc_model_transaction_managerinterface_get)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollbackPendent, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, commit, NULL)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollback, arginfo_phalcon_mvc_model_transaction_managerinterface_rollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyRollback, arginfo_phalcon_mvc_model_transaction_managerinterface_notifyrollback)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyCommit, arginfo_phalcon_mvc_model_transaction_managerinterface_notifycommit)
	PHP_ABSTRACT_ME(Phalcon_Mvc_Model_Transaction_ManagerInterface, collectTransactions, NULL)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Transaction\ManagerInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_ManagerInterface){

	PHALCON_REGISTER_INTERFACE(Phalcon\\Mvc\\Model\\Transaction, ManagerInterface, mvc_model_transaction_managerinterface, phalcon_mvc_model_transaction_managerinterface_method_entry);

	return SUCCESS;
}

/**
 * Checks whether manager has an active transaction
 *
 * @return boolean
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, has);

/**
 * Returns a new Phalcon\Mvc\Model\Transaction or an already created once
 *
 * @param boolean $autoBegin
 * @return Phalcon\Mvc\Model\TransactionInterface
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, get);

/**
 * Rollbacks active transactions within the manager
 *
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollbackPendent);

/**
 * Commmits active transactions within the manager
 *
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, commit);

/**
 * Rollbacks active transactions within the manager
 * Collect will remove transaction from the manager
 *
 * @param boolean $collect
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, rollback);

/**
 * Notifies the manager about a rollbacked transaction
 *
 * @param Phalcon\Mvc\Model\TransactionInterface $transaction
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyRollback);

/**
 * Notifies the manager about a commited transaction
 *
 * @param Phalcon\Mvc\Model\TransactionInterface $transaction
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, notifyCommit);

/**
 * Remove all the transactions from the manager
 *
 */
PHALCON_DOC_METHOD(Phalcon_Mvc_Model_Transaction_ManagerInterface, collectTransactions);

