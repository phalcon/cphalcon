
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


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

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Transaction, Manager, phalcon, mvc_model_transaction_manager, phalcon_mvc_model_transaction_manager_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_transaction_manager_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_transaction_manager_ce, SL("_initialized"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_transaction_manager_ce, SL("_rollbackPendent"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_transaction_manager_ce, SL("_number"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_model_transaction_manager_ce, SL("_service"), "db", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_transaction_manager_ce, SL("_transactions"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_transaction_manager_ce TSRMLS_CC, 1, phalcon_mvc_model_transaction_managerinterface_ce);
	zend_class_implements(phalcon_mvc_model_transaction_manager_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model\Transaction\Manager constructor
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, __construct) {

	zval *dependencyInjector = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dependencyInjector);

	if (!dependencyInjector || Z_TYPE_P(dependencyInjector) == IS_NULL) {
		ZEPHIR_CPY_WRT(dependencyInjector, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(dependencyInjector);


	if (zephir_is_true(dependencyInjector)) {
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(dependencyInjector);
		zephir_call_static(dependencyInjector, "Phalcon\\Di", "getdefault");
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_transaction_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the dependency injection container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the database service used to run the isolated transactions
 *
 * @param string service
 * @return Phalcon\Mvc\Model\Transaction\Manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDbService) {

	zval *service_param = NULL;
	zval *service = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &service_param);

		if (Z_TYPE_P(service_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'service' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		service = service_param;



	zephir_update_property_this(this_ptr, SL("_service"), service TSRMLS_CC);
	RETURN_THIS();

}

/**
 * Returns the database service used to isolate the transaction
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDbService) {


	RETURN_MEMBER(this_ptr, "_service");

}

/**
 * Set if the transaction manager must register a shutdown function to clean up pendent transactions
 *
 * @param boolean rollbackPendent
 * @return Phalcon\Mvc\Model\Transaction\Manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setRollbackPendent) {

	zval *rollbackPendent_param = NULL;
	zend_bool rollbackPendent;

	zephir_fetch_params(0, 1, 0, &rollbackPendent_param);

		rollbackPendent = zephir_get_boolval(rollbackPendent_param);


	zephir_update_property_this(this_ptr, SL("_rollbackPendent"), rollbackPendent ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Check if the transaction manager is registering a shutdown function to clean up pendent transactions
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getRollbackPendent) {


	RETURN_MEMBER(this_ptr, "_rollbackPendent");

}

/**
 * Checks whether the manager has an active transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, has) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_number"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_GT_LONG(_0, 0));

}

/**
 * Returns a new Phalcon\Mvc\Model\Transaction or an already created once
 * This method registers a shutdown function to rollback active connections
 *
 * @param boolean autoBegin
 * @return Phalcon\Mvc\Model\TransactionInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, get) {

	zval *autoBegin_param = NULL, *_0, *_1, *_2, *_3;
	zend_bool autoBegin;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &autoBegin_param);

	if (!autoBegin_param || Z_TYPE_P(autoBegin_param) == IS_NULL) {
		autoBegin = 1;
	} else {
		autoBegin = zephir_get_boolval(autoBegin_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_rollbackPendent"), PH_NOISY_CC);
		if (zephir_is_true(_1)) {
			ZEPHIR_INIT_VAR(_2);
			array_init(_2);
			zephir_array_fast_append(_2, this_ptr);
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "rollbackPendent", 1);
			zephir_array_fast_append(_2, _3);
			zephir_call_func_p1_noret("register_shutdown_function", _2);
		}
		zephir_update_property_this(this_ptr, SL("_initialized"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	zephir_call_method(return_value, this_ptr, "getorcreatetransaction");
	RETURN_MM();

}

/**
 * Create/Returns a new transaction or an existing one
 *
 * @param boolean autoBegin
 * @return Phalcon\Mvc\Model\TransactionInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getOrCreateTransaction) {

	zend_function *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	zval *autoBegin_param = NULL, *dependencyInjector = NULL, *transaction = NULL, *transactions, *_0, **_3, *_5;
	zend_bool autoBegin;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &autoBegin_param);

	if (!autoBegin_param || Z_TYPE_P(autoBegin_param) == IS_NULL) {
		autoBegin = 1;
	} else {
		autoBegin = zephir_get_boolval(autoBegin_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(dependencyInjector, _0);
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_transaction_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_number"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		transactions = zephir_fetch_nproperty_this(this_ptr, SL("_transactions"), PH_NOISY_CC);
		if ((Z_TYPE_P(transactions) == IS_ARRAY)) {
			zephir_is_iterable(transactions, &_2, &_1, 0, 1);
			for (
				; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
				; zend_hash_move_backwards_ex(_2, &_1)
			) {
				ZEPHIR_GET_HVALUE(transaction, _3);
				if ((Z_TYPE_P(transaction) == IS_OBJECT)) {
					zephir_call_method_p1_cache_noret(transaction, "setisnewtransaction", &_4, ZEPHIR_GLOBAL(global_false));
					RETURN_CCTOR(transaction);
				}
			}
		}
	}
	ZEPHIR_INIT_VAR(transaction);
	object_init_ex(transaction, phalcon_mvc_model_transaction_ce);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_service"), PH_NOISY_CC);
	zephir_call_method_p3_noret(transaction, "__construct", dependencyInjector, (autoBegin ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)), _5);
	zephir_call_method_p1_noret(transaction, "settransactionmanager", this_ptr);
	zephir_update_property_array_append(this_ptr, SL("_transactions"), transaction TSRMLS_CC);
	RETURN_CCTOR(transaction);

}

/**
 * Rollbacks active transactions within the manager
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent) {

	ZEPHIR_MM_GROW();

	zephir_call_method_noret(this_ptr, "rollback");
	ZEPHIR_MM_RESTORE();

}

/**
 * Commmits active transactions within the manager
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, commit) {

	zend_function *_3 = NULL, *_5 = NULL, *_6 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *transactions, *transaction = NULL, *connection = NULL, **_2, *_4 = NULL;

	ZEPHIR_MM_GROW();

	transactions = zephir_fetch_nproperty_this(this_ptr, SL("_transactions"), PH_NOISY_CC);
	if ((Z_TYPE_P(transactions) == IS_ARRAY)) {
		zephir_is_iterable(transactions, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(transaction, _2);
			ZEPHIR_INIT_NVAR(connection);
			zephir_call_method_cache(connection, transaction, "getconnection", &_3);
			ZEPHIR_INIT_NVAR(_4);
			zephir_call_method_cache(_4, connection, "isundertransaction", &_5);
			if (zephir_is_true(_4)) {
				zephir_call_method_cache_noret(connection, "commit", &_6);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Rollbacks active transactions within the manager
 * Collect will remove the transaction from the manager
 *
 * @param boolean collect
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollback) {

	zend_function *_3 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *collect = NULL, *transactions, *transaction = NULL, *connection = NULL, **_2, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &collect);

	if (!collect || Z_TYPE_P(collect) == IS_NULL) {
		collect = ZEPHIR_GLOBAL(global_true);
	}


	transactions = zephir_fetch_nproperty_this(this_ptr, SL("_transactions"), PH_NOISY_CC);
	if ((Z_TYPE_P(transactions) == IS_ARRAY)) {
		zephir_is_iterable(transactions, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(transaction, _2);
			ZEPHIR_INIT_NVAR(connection);
			zephir_call_method_cache(connection, transaction, "getconnection", &_3);
			ZEPHIR_INIT_NVAR(_4);
			zephir_call_method_cache(_4, connection, "isundertransaction", &_5);
			if (zephir_is_true(_4)) {
				zephir_call_method_cache_noret(connection, "rollback", &_6);
				zephir_call_method_cache_noret(connection, "close", &_7);
			}
			if (zephir_is_true(collect)) {
				zephir_call_method_p1_cache_noret(this_ptr, "_collecttransaction", &_8, transaction);
			}
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Notifies the manager about a rollbacked transaction
 *
 * @param Phalcon\Mvc\Model\TransactionInterface transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyRollback) {

	zval *transaction;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &transaction);



	zephir_call_method_p1_noret(this_ptr, "_collecttransaction", transaction);
	ZEPHIR_MM_RESTORE();

}

/**
 * Notifies the manager about a commited transaction
 *
 * @param Phalcon\Mvc\Model\TransactionInterface transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyCommit) {

	zval *transaction;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &transaction);



	zephir_call_method_p1_noret(this_ptr, "_collecttransaction", transaction);
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes transactions from the TransactionManager
 *
 * @param Phalcon\Mvc\Model\TransactionInterface transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, _collectTransaction) {

	HashTable *_1;
	HashPosition _0;
	zval *transaction, *transactions, *newTransactions, *managedTransaction = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &transaction);



	transactions = zephir_fetch_nproperty_this(this_ptr, SL("_transactions"), PH_NOISY_CC);
	if (zephir_fast_count_int(transactions TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(newTransactions);
		array_init(newTransactions);
		zephir_is_iterable(transactions, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(managedTransaction, _2);
			if (ZEPHIR_IS_EQUAL(managedTransaction, transaction)) {
				zephir_array_append(&newTransactions, transaction, PH_SEPARATE);
			}
		}
		zephir_update_property_this(this_ptr, SL("_transactions"), newTransactions TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Remove all the transactions from the manager
 *
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions) {

	HashTable *_1;
	HashPosition _0;
	zval *transactions, *managedTransaction = NULL, **_2;


	transactions = zephir_fetch_nproperty_this(this_ptr, SL("_transactions"), PH_NOISY_CC);
	if (zephir_fast_count_int(transactions TSRMLS_CC)) {
		zephir_is_iterable(transactions, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(managedTransaction, _2);
		}
		zephir_update_property_this(this_ptr, SL("_transactions"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	}

}

