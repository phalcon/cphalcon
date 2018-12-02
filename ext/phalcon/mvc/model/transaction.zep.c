
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * Phalcon\Mvc\Model\Transaction
 *
 * Transactions are protective blocks where SQL statements are only permanent if they can
 * all succeed as one atomic action. Phalcon\Transaction is intended to be used with Phalcon_Model_Base.
 * Phalcon Transactions should be created using Phalcon\Transaction\Manager.
 *
 * <code>
 * use Phalcon\Mvc\Model\Transaction\Failed;
 * use Phalcon\Mvc\Model\Transaction\Manager;
 *
 * try {
 *     $manager = new Manager();
 *
 *     $transaction = $manager->get();
 *
 *     $robot = new Robots();
 *
 *     $robot->setTransaction($transaction);
 *
 *     $robot->name       = "WALL·E";
 *     $robot->created_at = date("Y-m-d");
 *
 *     if ($robot->save() === false) {
 *         $transaction->rollback("Can't save robot");
 *     }
 *
 *     $robotPart = new RobotParts();
 *
 *     $robotPart->setTransaction($transaction);
 *
 *     $robotPart->type = "head";
 *
 *     if ($robotPart->save() === false) {
 *         $transaction->rollback("Can't save robot part");
 *     }
 *
 *     $transaction->commit();
 * } catch(Failed $e) {
 *     echo "Failed, reason: ", $e->getMessage();
 * }
 * </code>
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *service = NULL;
	zend_bool autoBegin;
	zval *dependencyInjector, *autoBegin_param = NULL, *service_param = NULL, *connection = NULL, *_0, *_1$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &dependencyInjector, &autoBegin_param, &service_param);

	if (!autoBegin_param) {
		autoBegin = 0;
	} else {
		autoBegin = zephir_get_boolval(autoBegin_param);
	}
	if (!service_param) {
		ZEPHIR_INIT_VAR(service);
		ZVAL_EMPTY_STRING(service);
	} else {
		zephir_get_strval(service, service_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(getThis(), SL("_messages"), _0 TSRMLS_CC);
	if (!(!service) && Z_STRLEN_P(service)) {
		ZEPHIR_CALL_METHOD(&connection, dependencyInjector, "get", NULL, 0, service);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_1$$4);
		ZVAL_STRING(_1$$4, "db", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&connection, dependencyInjector, "get", NULL, 0, _1$$4);
		zephir_check_temp_parameter(_1$$4);
		zephir_check_call_status();
	}
	zephir_update_property_this(getThis(), SL("_connection"), connection TSRMLS_CC);
	if (autoBegin) {
		ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets transaction manager related to the transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setTransactionManager) {

	zval *manager;

	zephir_fetch_params(0, 1, 0, &manager);



	zephir_update_property_this(getThis(), SL("_manager"), manager TSRMLS_CC);

}

/**
 * Starts the transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, begin) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "begin", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Commits the transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, commit) {

	zval *manager = NULL, *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	if (Z_TYPE_P(manager) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, manager, "notifycommit", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "commit", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Rollbacks the transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, rollback) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rollbackMessage = NULL, *rollbackRecord = NULL, *manager = NULL, *connection = NULL, *_0 = NULL, *_1$$4, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &rollbackMessage, &rollbackRecord);

	if (!rollbackMessage) {
		ZEPHIR_CPY_WRT(rollbackMessage, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(rollbackMessage);
	}
	if (!rollbackRecord) {
		rollbackRecord = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_manager"), PH_NOISY_CC);
	if (Z_TYPE_P(manager) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, manager, "notifyrollback", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(connection);
	zephir_read_property_this(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, connection, "rollback", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		if (!(zephir_is_true(rollbackMessage))) {
			ZEPHIR_INIT_NVAR(rollbackMessage);
			ZVAL_STRING(rollbackMessage, "Transaction aborted", 1);
		}
		if (Z_TYPE_P(rollbackRecord) == IS_OBJECT) {
			zephir_update_property_this(getThis(), SL("_rollbackRecord"), rollbackRecord TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(_1$$4);
		object_init_ex(_1$$4, phalcon_mvc_model_transaction_failed_ce);
		_2$$4 = zephir_fetch_nproperty_this(this_ptr, SL("_rollbackRecord"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 392, rollbackMessage, _2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$4, "phalcon/mvc/model/transaction.zep", 159 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

/**
 * Returns the connection related to transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getConnection) {

	zval *_0, *_1$$3 = NULL, *_2$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_rollbackOnAbort"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "connection_aborted", NULL, 393);
		zephir_check_call_status();
		if (zephir_is_true(_1$$3)) {
			ZEPHIR_INIT_VAR(_2$$4);
			ZVAL_STRING(_2$$4, "The request was aborted", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0, _2$$4);
			zephir_check_temp_parameter(_2$$4);
			zephir_check_call_status();
		}
	}
	RETURN_MM_MEMBER(getThis(), "_connection");

}

/**
 * Sets if is a reused transaction or new once
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setIsNewTransaction) {

	zval *isNew_param = NULL;
	zend_bool isNew;

	zephir_fetch_params(0, 1, 0, &isNew_param);

	isNew = zephir_get_boolval(isNew_param);


	if (isNew) {
		zephir_update_property_this(getThis(), SL("_isNewTransaction"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_isNewTransaction"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}

}

/**
 * Sets flag to rollback on abort the HTTP connection
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackOnAbort) {

	zval *rollbackOnAbort_param = NULL;
	zend_bool rollbackOnAbort;

	zephir_fetch_params(0, 1, 0, &rollbackOnAbort_param);

	rollbackOnAbort = zephir_get_boolval(rollbackOnAbort_param);


	if (rollbackOnAbort) {
		zephir_update_property_this(getThis(), SL("_rollbackOnAbort"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_rollbackOnAbort"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}

}

/**
 * Checks whether transaction is managed by a transaction manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isManaged) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_manager"), PH_NOISY_CC);
	RETURN_MM_BOOL(Z_TYPE_P(_0) == IS_OBJECT);

}

/**
 * Returns validations messages from last save try
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getMessages) {

	

	RETURN_MEMBER(getThis(), "_messages");

}

/**
 * Checks whether internal connection is under an active transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isValid) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_connection"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "isundertransaction", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets object which generates rollback action
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackedRecord) {

	zval *record;

	zephir_fetch_params(0, 1, 0, &record);



	zephir_update_property_this(getThis(), SL("_rollbackRecord"), record TSRMLS_CC);

}

