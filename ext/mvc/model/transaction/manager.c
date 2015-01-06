
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

#include "mvc/model/transaction/manager.h"
#include "mvc/model/transaction/managerinterface.h"
#include "mvc/model/transaction.h"
#include "mvc/model/transaction/exception.h"
#include "di.h"
#include "diinterface.h"
#include "di/injectionawareinterface.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/file.h"
#include "kernel/operators.h"

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
 *}
 *catch(Phalcon\Mvc\Model\Transaction\Failed $e){
 *  echo 'Failed, reason: ', $e->getMessage();
 *}
 *
 *</code>
 *
 */
zend_class_entry *phalcon_mvc_model_transaction_manager_ce;

PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDI);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDI);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDbService);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDbService);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setRollbackPendent);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getRollbackPendent);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, has);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, get);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getOrCreateTransaction);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, commit);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollback);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyRollback);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyCommit);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, _collectTransaction);
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, dependencyInjector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_setdbservice, 0, 0, 1)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_setrollbackpendent, 0, 0, 1)
	ZEND_ARG_INFO(0, rollbackPendent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction_manager_getorcreatetransaction, 0, 0, 0)
	ZEND_ARG_INFO(0, autoBegin)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_transaction_manager_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, __construct, arginfo_phalcon_mvc_model_transaction_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, setDI, arginfo_phalcon_di_injectionawareinterface_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, getDI, arginfo_phalcon_di_injectionawareinterface_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, setDbService, arginfo_phalcon_mvc_model_transaction_manager_setdbservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, getDbService, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, setRollbackPendent, arginfo_phalcon_mvc_model_transaction_manager_setrollbackpendent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, getRollbackPendent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, has, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, get, arginfo_phalcon_mvc_model_transaction_managerinterface_get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, getOrCreateTransaction, arginfo_phalcon_mvc_model_transaction_manager_getorcreatetransaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, rollback, arginfo_phalcon_mvc_model_transaction_managerinterface_rollback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, notifyRollback, arginfo_phalcon_mvc_model_transaction_managerinterface_notifyrollback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, notifyCommit, arginfo_phalcon_mvc_model_transaction_managerinterface_notifycommit, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, _collectTransaction, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Model\Transaction\Manager initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Manager){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Transaction, Manager, mvc_model_transaction_manager, phalcon_mvc_model_transaction_manager_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_transaction_manager_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_transaction_manager_ce, SL("_initialized"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_transaction_manager_ce, SL("_rollbackPendent"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_transaction_manager_ce, SL("_number"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_model_transaction_manager_ce, SL("_service"), "db", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_transaction_manager_ce, SL("_transactions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_transaction_manager_ce TSRMLS_CC, 2, phalcon_mvc_model_transaction_managerinterface_ce, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Transaction\Manager constructor
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, __construct){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &dependency_injector);
	
	if (!dependency_injector || Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		dependency_injector = NULL;
		PHALCON_CALL_CE_STATIC(&dependency_injector, phalcon_di_ce, "getdefault");
	}

	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_mvc_model_transaction_exception_ce, 1);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	PHALCON_VERIFY_INTERFACE_EX(dependency_injector, phalcon_diinterface_ce, phalcon_mvc_model_transaction_exception_ce, 0);
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
}

/**
 * Returns the dependency injection container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets the database service used to run the isolated transactions
 *
 * @param string $service
 * @return Phalcon\Mvc\Model\Transaction\Manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDbService){

	zval *service;

	phalcon_fetch_params(0, 1, 0, &service);
	
	phalcon_update_property_this(this_ptr, SL("_service"), service TSRMLS_CC);
	RETURN_THISW();
}

/**
 * Returns the database service used to isolate the transaction
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDbService){


	RETURN_MEMBER(this_ptr, "_service");
}

/**
 * Set if the transaction manager must register a shutdown function to clean up pendent transactions
 *
 * @param boolean $rollbackPendent
 * @return Phalcon\Mvc\Model\Transaction\Manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setRollbackPendent){

	zval *rollback_pendent;

	phalcon_fetch_params(0, 1, 0, &rollback_pendent);
	
	phalcon_update_property_this(this_ptr, SL("_rollbackPendent"), rollback_pendent TSRMLS_CC);
	
}

/**
 * Check if the transaction manager is registering a shutdown function to clean up pendent transactions
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getRollbackPendent){


	RETURN_MEMBER(this_ptr, "_rollbackPendent");
}

/**
 * Checks whether the manager has an active transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, has){

	zval *z_zero, *number;

	z_zero = PHALCON_GLOBAL(z_zero);
	
	number = phalcon_fetch_nproperty_this(this_ptr, SL("_number"), PH_NOISY TSRMLS_CC);
	is_smaller_function(return_value, z_zero, number TSRMLS_CC);
}

/**
 * Returns a new Phalcon\Mvc\Model\Transaction or an already created once
 * This method registers a shutdown function to rollback active connections
 *
 * @param boolean $autoBegin
 * @return Phalcon\Mvc\Model\TransactionInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, get){

	zval *auto_begin = NULL, *initialized, *rollback_pendent = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &auto_begin);
	
	if (!auto_begin) {
		auto_begin = PHALCON_GLOBAL(z_true);
	}
	
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY TSRMLS_CC);
	if (zend_is_true(initialized)) {
	
		PHALCON_OBS_VAR(rollback_pendent);
		phalcon_read_property_this(&rollback_pendent, this_ptr, SL("_rollbackPendent"), PH_NOISY TSRMLS_CC);
		if (zend_is_true(rollback_pendent)) {
			PHALCON_INIT_NVAR(rollback_pendent);
			array_init_size(rollback_pendent, 2);
			phalcon_array_append(&rollback_pendent, this_ptr, PH_SEPARATE);
			add_next_index_stringl(rollback_pendent, SL("rollbackPendent"), 1);
			PHALCON_CALL_FUNCTION(NULL, "register_shutdown_function", rollback_pendent);
		}
	
		phalcon_update_property_bool(this_ptr, SL("_initialized"), 1 TSRMLS_CC);
	}
	
	PHALCON_RETURN_CALL_METHOD(this_ptr, "getorcreatetransaction");
	RETURN_MM();
}

/**
 * Create/Returns a new transaction or an existing one
 *
 * @param boolean $autoBegin
 * @return Phalcon\Mvc\Model\TransactionInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getOrCreateTransaction){

	zval *auto_begin = NULL, *dependency_injector, *number;
	zval *transactions, *transaction = NULL, *false_value = NULL;
	zval *service;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &auto_begin);
	
	if (!auto_begin) {
		auto_begin = PHALCON_GLOBAL(z_true);
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_transaction_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_OBS_VAR(number);
	phalcon_read_property_this(&number, this_ptr, SL("_number"), PH_NOISY TSRMLS_CC);
	if (zend_is_true(number)) {
	
		PHALCON_OBS_VAR(transactions);
		phalcon_read_property_this(&transactions, this_ptr, SL("_transactions"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(transactions) == IS_ARRAY) { 
	
			phalcon_is_iterable(transactions, &ah0, &hp0, 0, 1);
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_HVALUE(transaction);
	
				if (Z_TYPE_P(transaction) == IS_OBJECT) {
					false_value = PHALCON_GLOBAL(z_false);
					PHALCON_CALL_METHOD(NULL, transaction, "setisnewtransaction", false_value);
					RETURN_CTOR(transaction);
				}
	
				zend_hash_move_backwards_ex(ah0, &hp0);
			}
	
		}
	}
	
	PHALCON_OBS_VAR(service);
	phalcon_read_property_this(&service, this_ptr, SL("_service"), PH_NOISY TSRMLS_CC);
	
	PHALCON_INIT_VAR(transaction);
	object_init_ex(transaction, phalcon_mvc_model_transaction_ce);
	PHALCON_CALL_METHOD(NULL, transaction, "__construct", dependency_injector, auto_begin, service);
	
	PHALCON_CALL_METHOD(NULL, transaction, "settransactionmanager", this_ptr);
	phalcon_update_property_array_append(this_ptr, SL("_transactions"), transaction TSRMLS_CC);
	phalcon_property_incr(this_ptr, SL("_number") TSRMLS_CC);
	
	RETURN_CTOR(transaction);
}

/**
 * Rollbacks active transactions within the manager
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent){


	PHALCON_MM_GROW();

	PHALCON_CALL_METHOD(NULL, this_ptr, "rollback");
	
	PHALCON_MM_RESTORE();
}

/**
 * Commmits active transactions within the manager
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, commit){

	zval *transactions, *transaction = NULL, *connection = NULL;
	zval *is_under_transaction = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(transactions);
	phalcon_read_property_this(&transactions, this_ptr, SL("_transactions"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(transactions) == IS_ARRAY) { 
	
		phalcon_is_iterable(transactions, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(transaction);
	
			PHALCON_CALL_METHOD(&connection, transaction, "getconnection");
			PHALCON_CALL_METHOD(&is_under_transaction, connection, "isundertransaction");
			if (zend_is_true(is_under_transaction)) {
				PHALCON_CALL_METHOD(NULL, connection, "commit");
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Rollbacks active transactions within the manager
 * Collect will remove transaction from the manager
 *
 * @param boolean $collect
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollback){

	zval *collect = NULL, *transactions, *transaction = NULL, *connection = NULL;
	zval *is_under_transaction = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &collect);
	
	if (!collect) {
		collect = PHALCON_GLOBAL(z_true);
	}
	
	PHALCON_OBS_VAR(transactions);
	phalcon_read_property_this(&transactions, this_ptr, SL("_transactions"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(transactions) == IS_ARRAY) { 
	
		phalcon_is_iterable(transactions, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(transaction);
	
			PHALCON_CALL_METHOD(&connection, transaction, "getconnection");
			PHALCON_CALL_METHOD(&is_under_transaction, connection, "isundertransaction");
			if (zend_is_true(is_under_transaction)) {
				PHALCON_CALL_METHOD(NULL, connection, "rollback");
				PHALCON_CALL_METHOD(NULL, connection, "close");
			}
	
			if (zend_is_true(collect)) {
				PHALCON_CALL_METHOD(NULL, this_ptr, "_collecttransaction", transaction);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Notifies the manager about a rollbacked transaction
 *
 * @param Phalcon\Mvc\Model\TransactionInterface $transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyRollback){

	zval *transaction;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &transaction);
	
	PHALCON_CALL_METHOD(NULL, this_ptr, "_collecttransaction", transaction);
	
	PHALCON_MM_RESTORE();
}

/**
 * Notifies the manager about a commited transaction
 *
 * @param Phalcon\Mvc\Model\TransactionInterface $transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyCommit){

	zval *transaction;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &transaction);
	
	PHALCON_CALL_METHOD(NULL, this_ptr, "_collecttransaction", transaction);
	
	PHALCON_MM_RESTORE();
}

/**
 * Removes transactions from the TransactionManager
 *
 * @param Phalcon\Mvc\Model\TransactionInterface $transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, _collectTransaction){

	zval *transaction, *transactions, *new_transactions;
	zval *managed_transaction = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &transaction);
	
	PHALCON_OBS_VAR(transactions);
	phalcon_read_property_this(&transactions, this_ptr, SL("_transactions"), PH_NOISY TSRMLS_CC);
	if (phalcon_fast_count_ev(transactions TSRMLS_CC)) {
	
		PHALCON_INIT_VAR(new_transactions);
		array_init(new_transactions);
	
		phalcon_is_iterable(transactions, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(managed_transaction);
	
			if (PHALCON_IS_EQUAL(managed_transaction, transaction)) {
				phalcon_array_append(&new_transactions, transaction, PH_SEPARATE);
				phalcon_property_decr(this_ptr, SL("_number") TSRMLS_CC);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		phalcon_update_property_this(this_ptr, SL("_transactions"), new_transactions TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Remove all the transactions from the manager
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions){

	zval *transactions, *managed_transaction = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(transactions);
	phalcon_read_property_this(&transactions, this_ptr, SL("_transactions"), PH_NOISY TSRMLS_CC);
	if (phalcon_fast_count_ev(transactions TSRMLS_CC)) {
	
		phalcon_is_iterable(transactions, &ah0, &hp0, 0, 0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_HVALUE(managed_transaction);
	
			phalcon_property_decr(this_ptr, SL("_number") TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		phalcon_update_property_null(this_ptr, SL("_transactions") TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}
