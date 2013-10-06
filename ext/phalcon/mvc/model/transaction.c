
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Transaction, phalcon, mvc_model_transaction, phalcon_mvc_model_transaction_method_entry, 0);

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
 * @param Phalcon\DiInterface $ependencyInjector
 * @param boolean autoBegin
 * @param string service
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, __construct) {

	zend_bool autoBegin;
	zval *dependencyInjector, *autoBegin_param = NULL, *service = NULL, *connection, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &dependencyInjector, &autoBegin_param, &service);

	if (!autoBegin_param) {
		autoBegin = 0;
	} else {
		autoBegin = zephir_get_boolval(autoBegin_param);
	}
	if (!service) {
		ZEPHIR_CPY_WRT(service, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(connection);
	if (zephir_is_true(service)) {
		zephir_call_method_p1(connection, dependencyInjector, "get", service);
	} else {
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "db", 1);
		zephir_call_method_p1(connection, dependencyInjector, "get", _0);
	}
	zephir_update_property_this(this_ptr, SL("_connection"), connection TSRMLS_CC);
	if (autoBegin) {
		zephir_call_method_noret(connection, "begin");
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets transaction manager related to the transaction
 *
 * @param Phalcon\Mvc\Model\Transaction\ManagerInterface $manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setTransactionManager) {

	zval *manager;

	zephir_fetch_params(0, 1, 0, &manager);



	zephir_update_property_this(this_ptr, SL("_manager"), manager TSRMLS_CC);

}

/**
 * Starts the transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, begin) {

	zval *connection;

	ZEPHIR_MM_GROW();

	connection = zephir_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY_CC);
	zephir_call_method(return_value, connection, "begin");
	RETURN_MM();

}

/**
 * Commits the transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, commit) {

	zval *manager, *connection, *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	manager = zephir_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY_CC);
	if ((Z_TYPE_P(manager) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_0);
		array_init(_0);
		zephir_array_fast_append(_0, manager);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "notifyCommit", 1);
		zephir_array_fast_append(_0, _1);
		ZEPHIR_INIT_NVAR(_1);
		array_init(_1);
		zephir_array_fast_append(_1, this_ptr);
		zephir_call_func_p2_noret("call_user_func_array", _0, _1);
	}
	connection = zephir_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY_CC);
	zephir_call_method(return_value, connection, "commit");
	RETURN_MM();

}

/**
 * Rollbacks the transaction
 *
 * @param  string rollbackMessage
 * @param  Phalcon\Mvc\ModelInterface rollbackRecord
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, rollback) {

	zval *rollbackMessage = NULL, *rollbackRecord = NULL, *manager, *connection, *_0 = NULL, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &rollbackMessage, &rollbackRecord);

	if (!rollbackMessage) {
		ZEPHIR_CPY_WRT(rollbackMessage, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(rollbackMessage);
	if (!rollbackRecord) {
		ZEPHIR_CPY_WRT(rollbackRecord, ZEPHIR_GLOBAL(global_null));
	}


	manager = zephir_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY_CC);
	if ((Z_TYPE_P(manager) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_0);
		array_init(_0);
		zephir_array_fast_append(_0, manager);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "notifyRollback", 1);
		zephir_array_fast_append(_0, _1);
		ZEPHIR_INIT_NVAR(_1);
		array_init(_1);
		zephir_array_fast_append(_1, this_ptr);
		zephir_call_func_p2_noret("call_user_func_array", _0, _1);
	}
	connection = zephir_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_0);
	zephir_call_method(_0, connection, "rollback");
	if (zephir_is_true(_0)) {
		if (!(zephir_is_true(rollbackMessage))) {
			ZEPHIR_INIT_NVAR(rollbackMessage);
			ZVAL_STRING(rollbackMessage, "Transaction aborted", 1);
		}
		if ((Z_TYPE_P(rollbackRecord) == IS_OBJECT)) {
			zephir_update_property_this(this_ptr, SL("_rollbackRecord"), rollbackRecord TSRMLS_CC);
		}
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, phalcon_mvc_model_transaction_failed_ce);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_rollbackRecord"), PH_NOISY_CC);
		zephir_call_method_p2_noret(_1, "__construct", rollbackMessage, _2);
		zephir_throw_exception(_1 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

/**
 * Returns the connection related to transaction
 *
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getConnection) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_rollbackOnAbort"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func(_1, "connection_aborted");
		if (zephir_is_true(_1)) {
			ZEPHIR_INIT_VAR(_2);
			ZVAL_STRING(_2, "The request was aborted", 1);
			zephir_call_method_p1_noret(this_ptr, "rollback", _2);
		}
	}
	RETURN_MEMBER(this_ptr, "_connection");

}

/**
 * Sets if is a reused transaction or new once
 *
 * @param boolean isNew
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setIsNewTransaction) {

	zval *isNew_param = NULL, *_0;
	zend_bool isNew;

	zephir_fetch_params(0, 1, 0, &isNew_param);

		isNew = zephir_get_boolval(isNew_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_BOOL(_0, isNew);
	zephir_update_property_this(this_ptr, SL("_isNewTransaction"), _0 TSRMLS_CC);

}

/**
 * Sets flag to rollback on abort the HTTP connection
 *
 * @param boolean $rollbackOnAbort
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackOnAbort) {

	zval *rollbackOnAbort_param = NULL, *_0;
	zend_bool rollbackOnAbort;

	zephir_fetch_params(0, 1, 0, &rollbackOnAbort_param);

		rollbackOnAbort = zephir_get_boolval(rollbackOnAbort_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_BOOL(_0, rollbackOnAbort);
	zephir_update_property_this(this_ptr, SL("_rollbackOnAbort"), _0 TSRMLS_CC);

}

/**
 * Checks whether transaction is managed by a transaction manager
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isManaged) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_manager"), PH_NOISY_CC);
	RETURN_BOOL(!zephir_is_true(_0));

}

/**
 * Returns validations messages from last save try
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getMessages) {


	RETURN_MEMBER(this_ptr, "_messages");

}

/**
 * Checks whether internal connection is under an active transaction
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isValid) {

	zval *connection;

	ZEPHIR_MM_GROW();

	connection = zephir_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY_CC);
	zephir_call_method(return_value, connection, "isundertransaction");
	RETURN_MM();

}

/**
 * Sets object which generates rollback action
 *
 * @param Phalcon\Mvc\ModelInterface $record
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackedRecord) {

	zval *record;

	zephir_fetch_params(0, 1, 0, &record);



	zephir_update_property_this(this_ptr, SL("_rollbackRecord"), record TSRMLS_CC);

}

