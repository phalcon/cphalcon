
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Transaction
 *
 * Transactions are protective blocks where SQL statements are only permanent if
 * they can all succeed as one atomic action. Phalcon\Transaction is intended to
 * be used with Phalcon_Model_Base. Phalcon Transactions should be created using
 * Phalcon\Transaction\Manager.
 *
 * ```php
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
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model, Transaction, phalcon, mvc_model_transaction, phalcon_mvc_model_transaction_method_entry, 0);

	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_transaction_ce, SL("activeTransaction"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var AdapterInterface
	 */
	zend_declare_property_null(phalcon_mvc_model_transaction_ce, SL("connection"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_transaction_ce, SL("isNewTransaction"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var ManagerInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_transaction_ce, SL("manager"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_transaction_ce, SL("messages"), ZEND_ACC_PROTECTED);
	/**
	 * @var ModelInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_transaction_ce, SL("rollbackRecord"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_transaction_ce, SL("rollbackOnAbort"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_transaction_ce, SL("rollbackThrowException"), 0, ZEND_ACC_PROTECTED);
	phalcon_mvc_model_transaction_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_Transaction;

	zend_class_implements(phalcon_mvc_model_transaction_ce, 1, phalcon_mvc_model_transactioninterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Transaction constructor
 *
 * @param DiInterface container
 * @param bool autoBegin
 * @param string service
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval service;
	zend_bool autoBegin;
	zval *container, container_sub, *autoBegin_param = NULL, *service_param = NULL, connection, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&service);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(autoBegin)
		Z_PARAM_STR(service)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &container, &autoBegin_param, &service_param);
	if (!autoBegin_param) {
		autoBegin = 0;
	} else {
		autoBegin = zephir_get_boolval(autoBegin_param);
	}
	if (!service_param) {
		ZEPHIR_INIT_VAR(&service);
		ZVAL_STRING(&service, "db");
	} else {
		zephir_get_strval(&service, service_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("messages"), &_0);
	ZEPHIR_CALL_METHOD(&connection, container, "get", NULL, 0, &service);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("connection"), &connection);
	if (autoBegin) {
		ZEPHIR_CALL_METHOD(NULL, &connection, "begin", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Starts the transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, begin)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "begin", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Commits the transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, commit)
{
	zval manager, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	if (Z_TYPE_P(&manager) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, &manager, "notifycommit", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "commit", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the connection related to transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getConnection)
{
	zval _0, _1$$3, _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("rollbackOnAbort"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_FUNCTION(&_1$$3, "connection_aborted", NULL, 492);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$3)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "The request was aborted");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0, &_2$$4);
			zephir_check_call_status();
		}
	}
	RETURN_MM_MEMBER(getThis(), "connection");
}

/**
 * Returns validations messages from last save try
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, getMessages)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "messages");
}

/**
 * Checks whether transaction is managed by a transaction manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isManaged)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC);
	RETURN_MM_BOOL(Z_TYPE_P(&_0) == IS_OBJECT);
}

/**
 * Checks whether internal connection is under an active transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, isValid)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "isundertransaction", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Rollbacks the transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, rollback)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rollbackMessage_param = NULL, *rollbackRecord = NULL, rollbackRecord_sub, __$null, manager, connection, _0, _1, _2$$4, _3$$7, _4$$7;
	zval rollbackMessage;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rollbackMessage);
	ZVAL_UNDEF(&rollbackRecord_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(rollbackMessage)
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(rollbackRecord, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &rollbackMessage_param, &rollbackRecord);
	if (!rollbackMessage_param) {
		ZEPHIR_INIT_VAR(&rollbackMessage);
	} else {
		zephir_get_strval(&rollbackMessage, rollbackMessage_param);
	}
	if (!rollbackRecord) {
		rollbackRecord = &rollbackRecord_sub;
		rollbackRecord = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	if (Z_TYPE_P(&manager) == IS_OBJECT) {
		ZEPHIR_CALL_METHOD(NULL, &manager, "notifyrollback", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&connection, &_0);
	ZEPHIR_CALL_METHOD(&_1, &connection, "rollback", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_1))) {
		if (!(!(ZEPHIR_IS_EMPTY(&rollbackMessage)))) {
			ZEPHIR_INIT_NVAR(&rollbackMessage);
			ZVAL_STRING(&rollbackMessage, "Transaction aborted");
		}
		if (Z_TYPE_P(rollbackRecord) == IS_OBJECT) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("rollbackRecord"), rollbackRecord);
		}
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("rollbackThrowException"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_2$$4)) {
			ZEPHIR_INIT_VAR(&_3$$7);
			object_init_ex(&_3$$7, phalcon_mvc_model_transaction_failed_ce);
			zephir_read_property(&_4$$7, this_ptr, ZEND_STRL("rollbackRecord"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_3$$7, "__construct", NULL, 493, &rollbackMessage, &_4$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$7, "phalcon/Mvc/Model/Transaction.zep", 215);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_MM_BOOL(1);
}

/**
 * Sets if is a reused transaction or new once
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setIsNewTransaction)
{
	zval *isNew_param = NULL, __$true, __$false;
	zend_bool isNew;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(isNew)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &isNew_param);
	isNew = zephir_get_boolval(isNew_param);


	if (isNew) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isNewTransaction"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isNewTransaction"), &__$false);
	}
}

/**
 * Sets flag to rollback on abort the HTTP connection
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackOnAbort)
{
	zval *rollbackOnAbort_param = NULL, __$true, __$false;
	zend_bool rollbackOnAbort;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(rollbackOnAbort)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &rollbackOnAbort_param);
	rollbackOnAbort = zephir_get_boolval(rollbackOnAbort_param);


	if (rollbackOnAbort) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("rollbackOnAbort"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("rollbackOnAbort"), &__$false);
	}
}

/**
 * Sets object which generates rollback action
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setRollbackedRecord)
{
	zval *record, record_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&record_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(record, phalcon_mvc_modelinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &record);


	zephir_update_property_zval(this_ptr, ZEND_STRL("rollbackRecord"), record);
}

/**
 * Sets transaction manager related to the transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, setTransactionManager)
{
	zval *manager, manager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(manager, phalcon_mvc_model_transaction_managerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &manager);


	zephir_update_property_zval(this_ptr, ZEND_STRL("manager"), manager);
}

/**
 * Enables throwing exception
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction, throwRollbackException)
{
	zval *status_param = NULL, __$true, __$false;
	zend_bool status;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(status)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &status_param);
	status = zephir_get_boolval(status_param);


	if (status) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("rollbackThrowException"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("rollbackThrowException"), &__$false);
	}
	RETURN_THISW();
}

zend_object *zephir_init_properties_Phalcon_Mvc_Model_Transaction(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("messages"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

