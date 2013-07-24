
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

#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"

/**
 * Phalcon\Mvc\Model\Transaction
 *
 * Transactions are protective blocks where SQL statements are only permanent if they can
 * all succeed as one atomic action. Phalcon\Transaction is intended to be used with Phalcon_Model_Base.
 * Phalcon Transactions should be created using Phalcon\Transaction\Manager.
 *
 *<code>
 *try {
 *
 *  $manager = new Phalcon\Mvc\Model\Transaction\Manager();
 *
 *  $transaction = $manager->get();
 *
 *  $robot = new Robots();
 *  $robot->setTransaction($transaction);
 *  $robot->name = 'WALL·E';
 *  $robot->created_at = date('Y-m-d');
 *  if ($robot->save() == false) {
 *    $transaction->rollback("Can't save robot");
 *  }
 *
 *  $robotPart = new RobotParts();
 *  $robotPart->setTransaction($transaction);
 *  $robotPart->type = 'head';
 *  if ($robotPart->save() == false) {
 *    $transaction->rollback("Can't save robot part");
 *  }
 *
 *  $transaction->commit();
 *
 *} catch(Phalcon\Mvc\Model\Transaction\Failed $e) {
 *  echo 'Failed, reason: ', $e->getMessage();
 *}
 *
 *</code>
 */


/**
 * Phalcon\Mvc\Model\Transaction initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Transaction){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Transaction, mvc_model_transaction, phalcon_mvc_model_transaction_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_transaction_ce, SL("_connection"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_transaction_ce, SL("_activeTransaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_transaction_ce, SL("_isNewTransaction"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_transaction_ce, SL("_rollbackOnAbort"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_transaction_ce, SL("_manager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_transaction_ce, SL("_messages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_transaction_ce, SL("_rollbackRecord"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_transaction_ce TSRMLS_CC, 1, phalcon_mvc_model_transactioninterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Transaction constructor
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @param boolean $autoBegin
 * @param string $service
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, __construct){

	zval *dependency_injector, *auto_begin = NULL, *service = NULL;
	zval *connection;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &dependency_injector, &auto_begin, &service);
	
	if (!auto_begin) {
		PHALCON_INIT_VAR(auto_begin);
		ZVAL_BOOL(auto_begin, 0);
	}
	
	if (!service) {
		PHALCON_INIT_VAR(service);
	} else {
		PHALCON_SEPARATE_PARAM(service);
	}
	
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_transaction_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	if (Z_TYPE_P(service) != IS_STRING) {
		PHALCON_INIT_NVAR(service);
		ZVAL_STRING(service, "db", 1);
	}
	
	PHALCON_INIT_VAR(connection);
	phalcon_call_method_p1(connection, dependency_injector, "get", service);
	phalcon_update_property_this(this_ptr, SL("_connection"), connection TSRMLS_CC);
	if (zend_is_true(auto_begin)) {
		phalcon_call_method_noret(connection, "begin");
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets transaction manager related to the transaction
 *
 * @param Phalcon\Mvc\Model\Transaction\ManagerInterface $manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setTransactionManager){

	zval *manager;

	phalcon_fetch_params(0, 1, 0, &manager);
	
	if (Z_TYPE_P(manager) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_transaction_exception_ce, "Manager must be an Object");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_manager"), manager TSRMLS_CC);
	
}

/**
 * Starts the transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, begin){

	zval *connection;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(connection);
	phalcon_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	phalcon_call_method(return_value, connection, "begin");
	RETURN_MM();
}

/**
 * Commits the transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, commit){

	zval *manager, *call_object, *arguments, *connection;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(manager);
	phalcon_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	if (Z_TYPE_P(manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(call_object);
		array_init_size(call_object, 2);
		phalcon_array_append(&call_object, manager, PH_SEPARATE);
		add_next_index_stringl(call_object, SL("notifyCommit"), 1);
	
		PHALCON_INIT_VAR(arguments);
		array_init_size(arguments, 1);
		phalcon_array_append(&arguments, this_ptr, PH_SEPARATE);
		phalcon_call_func_p2_noret("call_user_func_array", call_object, arguments);
	}
	
	PHALCON_OBS_VAR(connection);
	phalcon_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	phalcon_call_method(return_value, connection, "commit");
	RETURN_MM();
}

/**
 * Rollbacks the transaction
 *
 * @param  string $rollbackMessage
 * @param  Phalcon\Mvc\ModelInterface $rollbackRecord
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, rollback){

	zval *rollback_message = NULL, *rollback_record = NULL;
	zval *manager, *call_object, *arguments, *connection;
	zval *success;
	zval *i0 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &rollback_message, &rollback_record);
	
	if (!rollback_message) {
		PHALCON_INIT_VAR(rollback_message);
	} else {
		PHALCON_SEPARATE_PARAM(rollback_message);
	}
	
	if (!rollback_record) {
		PHALCON_INIT_VAR(rollback_record);
	} else {
		PHALCON_SEPARATE_PARAM(rollback_record);
	}
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	if (Z_TYPE_P(manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(call_object);
		array_init_size(call_object, 2);
		phalcon_array_append(&call_object, manager, PH_SEPARATE);
		add_next_index_stringl(call_object, SL("notifyRollback"), 1);
	
		PHALCON_INIT_VAR(arguments);
		array_init_size(arguments, 1);
		phalcon_array_append(&arguments, this_ptr, PH_SEPARATE);
		phalcon_call_func_p2_noret("call_user_func_array", call_object, arguments);
	}
	
	PHALCON_OBS_VAR(connection);
	phalcon_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(success);
	phalcon_call_method(success, connection, "rollback");
	if (zend_is_true(success)) {
		if (!zend_is_true(rollback_message)) {
			PHALCON_INIT_NVAR(rollback_message);
			ZVAL_STRING(rollback_message, "Transaction aborted", 1);
		}
		if (Z_TYPE_P(rollback_record) == IS_OBJECT) {
			phalcon_update_property_this(this_ptr, SL("_rollbackRecord"), rollback_record TSRMLS_CC);
		}
	
		PHALCON_OBS_NVAR(rollback_record);
		phalcon_read_property_this(&rollback_record, this_ptr, SL("_rollbackRecord"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(i0);
		object_init_ex(i0, phalcon_mvc_model_transaction_failed_ce);
		phalcon_call_method_p2_noret(i0, "__construct", rollback_message, rollback_record);
	
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the connection related to transaction
 *
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getConnection){

	zval *rollback_on_abort, *was_aborted, *message;
	zval *connection;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(rollback_on_abort);
	phalcon_read_property_this(&rollback_on_abort, this_ptr, SL("_rollbackOnAbort"), PH_NOISY_CC);
	if (zend_is_true(rollback_on_abort)) {
	
		PHALCON_INIT_VAR(was_aborted);
		phalcon_call_func(was_aborted, "connection_aborted");
		if (zend_is_true(was_aborted)) {
			PHALCON_INIT_VAR(message);
			ZVAL_STRING(message, "The request was aborted", 1);
			phalcon_call_method_p1_noret(this_ptr, "rollback", message);
		}
	}
	
	PHALCON_OBS_VAR(connection);
	phalcon_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	
	RETURN_CCTOR(connection);
}

/**
 * Sets if is a reused transaction or new once
 *
 * @param boolean $isNew
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setIsNewTransaction){

	zval *is_new;

	phalcon_fetch_params(0, 1, 0, &is_new);
	
	phalcon_update_property_this(this_ptr, SL("_isNewTransaction"), is_new TSRMLS_CC);
	
}

/**
 * Sets flag to rollback on abort the HTTP connection
 *
 * @param boolean $rollbackOnAbort
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackOnAbort){

	zval *rollback_on_abort;

	phalcon_fetch_params(0, 1, 0, &rollback_on_abort);
	
	phalcon_update_property_this(this_ptr, SL("_rollbackOnAbort"), rollback_on_abort TSRMLS_CC);
	
}

/**
 * Checks whether transaction is managed by a transaction manager
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isManaged){

	zval *manager;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(manager);
	phalcon_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	boolean_not_function(r0, manager TSRMLS_CC);
	RETURN_NCTOR(r0);
}

/**
 * Returns validations messages from last save try
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getMessages){


	RETURN_MEMBER(this_ptr, "_messages");
}

/**
 * Checks whether internal connection is under an active transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isValid){

	zval *connection;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(connection);
	phalcon_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	phalcon_call_method(return_value, connection, "isundertransaction");
	RETURN_MM();
}

/**
 * Sets object which generates rollback action
 *
 * @param Phalcon\Mvc\ModelInterface $record
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackedRecord){

	zval *record;

	phalcon_fetch_params(0, 1, 0, &record);
	
	phalcon_update_property_this(this_ptr, SL("_rollbackRecord"), record TSRMLS_CC);
	
}

