
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

#include "mvc/model/transaction.h"
#include "mvc/model/transactioninterface.h"
#include "mvc/model/transaction/exception.h"
#include "mvc/model/transaction/failed.h"
#include "mvc/model/transaction/managerinterface.h"

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
zend_class_entry *phalcon_mvc_model_transaction_ce;

PHP_METHOD(Phalcon_Mvc_Model_Transaction, __construct);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setTransactionManager);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, begin);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, commit);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, rollback);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getConnection);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setIsNewTransaction);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackOnAbort);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isManaged);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getMessages);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isValid);
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackedRecord);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_model_transaction___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dependencyInjector)
	ZEND_ARG_INFO(0, autoBegin)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_model_transaction_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Model_Transaction, __construct, arginfo_phalcon_mvc_model_transaction___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Model_Transaction, setTransactionManager, arginfo_phalcon_mvc_model_transactioninterface_settransactionmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, begin, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, commit, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, rollback, arginfo_phalcon_mvc_model_transactioninterface_rollback, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, getConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, setIsNewTransaction, arginfo_phalcon_mvc_model_transactioninterface_setisnewtransaction, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, setRollbackOnAbort, arginfo_phalcon_mvc_model_transactioninterface_setrollbackonabort, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, isManaged, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, getMessages, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, isValid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Model_Transaction, setRollbackedRecord, arginfo_phalcon_mvc_model_transactioninterface_setrollbackedrecord, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

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
	zval *connection = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &dependency_injector, &auto_begin, &service);
	
	if (!auto_begin) {
		auto_begin = PHALCON_GLOBAL(z_false);
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
	
	PHALCON_CALL_METHOD(&connection, dependency_injector, "get", service);
	phalcon_update_property_this(this_ptr, SL("_connection"), connection TSRMLS_CC);
	if (zend_is_true(auto_begin)) {
		PHALCON_CALL_METHOD(NULL, connection, "begin");
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
	PHALCON_VERIFY_INTERFACE_EX(manager, phalcon_mvc_model_transaction_managerinterface_ce, phalcon_mvc_model_transaction_exception_ce, 0);

	phalcon_update_property_this(this_ptr, SL("_manager"), manager TSRMLS_CC);
}

/**
 * Starts the transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, begin){

	zval *connection;

	connection = phalcon_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHODW(connection, "begin");
}

/**
 * Commits the transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, commit){

	zval *manager, *connection;

	manager = phalcon_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(manager) == IS_OBJECT) {
		PHALCON_CALL_METHODW(NULL, manager, "notifycommit", getThis());
	}
	
	connection = phalcon_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHODW(connection, "commit");
}

/**
 * Rolls back the transaction
 *
 * @param  string $rollbackMessage
 * @param  Phalcon\Mvc\ModelInterface $rollbackRecord
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, rollback){

	zval *rollback_message = NULL, *rollback_record = NULL;
	zval *manager, *connection;
	zval *success = NULL;
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
	
	manager = phalcon_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(manager) == IS_OBJECT) {
		PHALCON_CALL_METHOD(NULL, manager, "notifyrollback", getThis());
	}
	
	connection = phalcon_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY TSRMLS_CC);
	
	PHALCON_CALL_METHOD(&success, connection, "rollback");
	if (zend_is_true(success)) {
		if (!zend_is_true(rollback_message)) {
			PHALCON_INIT_NVAR(rollback_message);
			ZVAL_STRING(rollback_message, "Transaction aborted", 1);
		}
		if (Z_TYPE_P(rollback_record) == IS_OBJECT) {
			phalcon_update_property_this(this_ptr, SL("_rollbackRecord"), rollback_record TSRMLS_CC);
		}
	
		PHALCON_OBS_NVAR(rollback_record);
		phalcon_read_property_this(&rollback_record, this_ptr, SL("_rollbackRecord"), PH_NOISY TSRMLS_CC);
	
		PHALCON_INIT_VAR(i0);
		object_init_ex(i0, phalcon_mvc_model_transaction_failed_ce);
		PHALCON_CALL_METHOD(NULL, i0, "__construct", rollback_message, rollback_record);
	
		phalcon_throw_exception(i0 TSRMLS_CC);
		RETURN_MM();
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the connection related to transaction
 *
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getConnection){

	zval *rollback_on_abort, *message;
	zval *connection;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(rollback_on_abort);
	phalcon_read_property_this(&rollback_on_abort, this_ptr, SL("_rollbackOnAbort"), PH_NOISY TSRMLS_CC);
	if (zend_is_true(rollback_on_abort)) {
	
		if (PG(connection_status) & PHP_CONNECTION_ABORTED) {
			PHALCON_INIT_VAR(message);
			ZVAL_STRING(message, "The request was aborted", 1);
			PHALCON_CALL_METHOD(NULL, this_ptr, "rollback", message);
		}
	}
	
	PHALCON_OBS_VAR(connection);
	phalcon_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY TSRMLS_CC);
	
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

	manager = phalcon_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY TSRMLS_CC);
	boolean_not_function(return_value, manager TSRMLS_CC);
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

	connection = phalcon_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY TSRMLS_CC);
	PHALCON_RETURN_CALL_METHODW(connection, "isundertransaction");
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
