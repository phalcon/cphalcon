
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/file.h"

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


/**
 * Phalcon\Mvc\Model\Transaction\Manager initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Manager){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Transaction, Manager, mvc_model_transaction_manager, phalcon_mvc_model_transaction_manager_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_transaction_manager_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_transaction_manager_ce, SL("_initialized"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_transaction_manager_ce, SL("_number"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_transaction_manager_ce, SL("_transactions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_transaction_manager_ce TSRMLS_CC, 2, phalcon_mvc_model_transaction_managerinterface_ce, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Transaction\Manager
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, __construct){

	zval *dependency_injector = NULL;

	PHALCON_MM_GROW();

	phalcon_update_property_empty_array(phalcon_mvc_model_transaction_manager_ce, this_ptr, SL("_transactions") TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &dependency_injector) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!dependency_injector) {
		PHALCON_INIT_NVAR(dependency_injector);
	} else {
		PHALCON_SEPARATE_PARAM(dependency_injector);
	}
	
	if (zend_is_true(dependency_injector)) {
		phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(dependency_injector);
		PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
		phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	}
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDI){

	zval *dependency_injector;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
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
 * Checks whether manager has an active transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, has){

	zval *number, *zero, *has_transactions;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(number);
	phalcon_read_property(&number, this_ptr, SL("_number"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(zero);
	ZVAL_LONG(zero, 0);
	
	PHALCON_INIT_VAR(has_transactions);
	is_smaller_function(has_transactions, zero, number TSRMLS_CC);
	RETURN_NCTOR(has_transactions);
}

/**
 * Returns a new Phalcon\Mvc\Model\Transaction or an already created once
 *
 * @param boolean $autoBegin
 * @return Phalcon\Mvc\Model\TransactionInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, get){

	zval *auto_begin = NULL, *initialized, *rollback_pendent;
	zval *dependency_injector, *number, *transaction = NULL;
	zval *one, *position, *false_value;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &auto_begin) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!auto_begin) {
		PHALCON_INIT_NVAR(auto_begin);
		ZVAL_BOOL(auto_begin, 1);
	}
	
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (zend_is_true(initialized)) {
		PHALCON_INIT_VAR(rollback_pendent);
		array_init_size(rollback_pendent, 2);
		phalcon_array_append(&rollback_pendent, this_ptr, PH_SEPARATE TSRMLS_CC);
		add_next_index_stringl(rollback_pendent, SL("rollbackPendent"), 1);
		PHALCON_CALL_FUNC_PARAMS_1_NORETURN("register_shutdown_function", rollback_pendent);
		phalcon_update_property_bool(this_ptr, SL("_initialized"), 1 TSRMLS_CC);
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	PHALCON_OBS_VAR(number);
	phalcon_read_property(&number, this_ptr, SL("_number"), PH_NOISY_CC);
	if (!zend_is_true(number)) {
		PHALCON_INIT_VAR(transaction);
		object_init_ex(transaction, phalcon_mvc_model_transaction_ce);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(transaction, "__construct", dependency_injector, auto_begin);
	
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(transaction, "settransactionmanager", this_ptr);
		phalcon_update_property_array_append(this_ptr, SL("_transactions"), transaction TSRMLS_CC);
		phalcon_property_incr(this_ptr, SL("_number") TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(one);
		ZVAL_LONG(one, 1);
	
		PHALCON_INIT_VAR(position);
		sub_function(position, number, one TSRMLS_CC);
	
		PHALCON_OBS_VAR(t0);
		phalcon_read_property(&t0, this_ptr, SL("_transactions"), PH_NOISY_CC);
	
		PHALCON_OBS_NVAR(transaction);
		phalcon_array_fetch(&transaction, t0, position, PH_NOISY_CC);
	
		PHALCON_INIT_VAR(false_value);
		ZVAL_BOOL(false_value, 0);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(transaction, "setisnewtransaction", false_value);
	}
	
	
	RETURN_CCTOR(transaction);
}

/**
 * Rollbacks active transactions within the manager
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent){


	PHALCON_MM_GROW();

	PHALCON_CALL_METHOD_NORETURN(this_ptr, "rollback");
	
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
	phalcon_read_property(&transactions, this_ptr, SL("_transactions"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(transactions TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(transactions);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(transaction);
	
		PHALCON_INIT_NVAR(connection);
		PHALCON_CALL_METHOD(connection, transaction, "getconnection");
	
		PHALCON_INIT_NVAR(is_under_transaction);
		PHALCON_CALL_METHOD(is_under_transaction, connection, "isundertransaction");
		if (zend_is_true(is_under_transaction)) {
			PHALCON_CALL_METHOD_NORETURN(connection, "commit");
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &collect) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!collect) {
		PHALCON_INIT_NVAR(collect);
		ZVAL_BOOL(collect, 0);
	}
	
	PHALCON_OBS_VAR(transactions);
	phalcon_read_property(&transactions, this_ptr, SL("_transactions"), PH_NOISY_CC);
	
	if (!phalcon_valid_foreach(transactions TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(transactions);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(transaction);
	
		PHALCON_INIT_NVAR(connection);
		PHALCON_CALL_METHOD(connection, transaction, "getconnection");
	
		PHALCON_INIT_NVAR(is_under_transaction);
		PHALCON_CALL_METHOD(is_under_transaction, connection, "isundertransaction");
		if (zend_is_true(is_under_transaction)) {
			PHALCON_CALL_METHOD_NORETURN(connection, "rollback");
			PHALCON_CALL_METHOD_NORETURN(connection, "close");
		}
	
		if (zend_is_true(collect)) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_collecttransaction", transaction);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &transaction) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_collecttransaction", transaction);
	
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

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &transaction) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "_collecttransaction", transaction);
	
	PHALCON_MM_RESTORE();
}

/**
 * Removes transactions from the TransactionManager
 *
 * @param Phalcon\Mvc\Model\TransactionInterface $transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, _collectTransaction){

	zval *transaction, *transactions = NULL, *number, *managed_transaction = NULL;
	zval *r0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &transaction) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(transactions);
	phalcon_read_property(&transactions, this_ptr, SL("_transactions"), PH_NOISY_CC);
	if (phalcon_fast_count_ev(transactions TSRMLS_CC)) {
	
		PHALCON_INIT_VAR(number);
		ZVAL_LONG(number, 0);
	
		if (!phalcon_valid_foreach(transactions TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(transactions);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(managed_transaction);
	
			PHALCON_INIT_NVAR(r0);
			is_equal_function(r0, managed_transaction, transaction TSRMLS_CC);
			if (zend_is_true(r0)) {
				phalcon_property_decr(this_ptr, SL("_number") TSRMLS_CC);
			}
			PHALCON_SEPARATE(number);
			increment_function(number);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		PHALCON_INIT_NVAR(transactions);
		array_init(transactions);
	
		if (!phalcon_valid_foreach(transactions TSRMLS_CC)) {
			return;
		}
	
		ALLOC_HASHTABLE(ah1);
		zend_hash_init(ah1, 0, NULL, NULL, 0);
		zend_hash_copy(ah1, Z_ARRVAL_P(transactions), NULL, NULL, sizeof(zval*));
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
	
		while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(managed_transaction);
	
			phalcon_array_append(&transactions, managed_transaction, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah1, &hp1);
		}
		zend_hash_destroy(ah1);
		efree(ah1);
	
		phalcon_update_property_zval(this_ptr, SL("_transactions"), transactions TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Remove all the transactions from the manager
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions){

	zval *transactions, *number, *managed_transaction = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(transactions);
	phalcon_read_property(&transactions, this_ptr, SL("_transactions"), PH_NOISY_CC);
	if (phalcon_fast_count_ev(transactions TSRMLS_CC)) {
	
		PHALCON_INIT_VAR(number);
		ZVAL_LONG(number, 0);
	
		if (!phalcon_valid_foreach(transactions TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(transactions);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(managed_transaction);
	
			phalcon_property_decr(this_ptr, SL("_number") TSRMLS_CC);
			PHALCON_SEPARATE(number);
			increment_function(number);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_MM_RESTORE();
}

