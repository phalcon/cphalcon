
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


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
/**
 * Phalcon\Mvc\Model\Transaction\Manager
 *
 * A transaction acts on a single database connection. If you have multiple class-specific
 * databases, the transaction will not protect interaction among them.
 *
 * This class manages the objects that compose a transaction.
 * A trasaction produces a unique connection that is passed to every
 * object part of the transaction.
 *
 *<code>
 *try {
 *
 *  use Phalcon\Mvc\Model\Transaction\Manager as TransactionManager;
 *
 *  $transactionManager = new TransactionManager();
 *
 *  $transaction = $transactionManager->get();
 *
 *  $robot = new Robots();
 *  $robot->setTransaction($transaction);
 *  $robot->name = 'WALL·E';
 *  $robot->created_at = date('Y-m-d');
 *  if($robot->save()==false){
 *    $transaction->rollback("Can't save robot");
 *  }
 *
 *  $robotPart = new RobotParts();
 *  $robotPart->setTransaction($transaction);
 *  $robotPart->type = 'head';
 *  if($robotPart->save()==false){
 *    $transaction->rollback("Can't save robot part");
 *  }
 *
 *  $transaction->commit();
 *
 *} catch (Phalcon\Mvc\Model\Transaction\Failed $e) {
 *  echo 'Failed, reason: ', $e->getMessage();
 *}
 *
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Manager) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Transaction, Manager, phalcon, mvc_model_transaction_manager, NULL, 0);

	zend_declare_property_null(phalcon_mvc_model_transaction_manager_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_transaction_manager_ce, SL("_initialized"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_transaction_manager_ce, SL("_rollbackPendent"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_transaction_manager_ce, SL("_number"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_model_transaction_manager_ce, SL("_service"), "db", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_transaction_manager_ce, SL("_transactions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

