
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Transaction\Manager
 *
 * A transaction acts on a single database connection. If you have multiple class-specific
 * databases, the transaction will not protect interaction among them.
 *
 * This class manages the objects that compose a transaction.
 * A transaction produces a unique connection that is passed to every
 * object part of the transaction.
 *
 * <code>
 * use Phalcon\Mvc\Model\Transaction\Failed;
 * use Phalcon\Mvc\Model\Transaction\Manager;
 *
 * try {
 *    $transactionManager = new Manager();
 *
 *    $transaction = $transactionManager->get();
 *
 *    $robot = new Robots();
 *
 *    $robot->setTransaction($transaction);
 *
 *    $robot->name       = "WALL·E";
 *    $robot->created_at = date("Y-m-d");
 *
 *    if ($robot->save() === false){
 *        $transaction->rollback("Can't save robot");
 *    }
 *
 *    $robotPart = new RobotParts();
 *
 *    $robotPart->setTransaction($transaction);
 *
 *    $robotPart->type = "head";
 *
 *    if ($robotPart->save() === false) {
 *        $transaction->rollback("Can't save robot part");
 *    }
 *
 *    $transaction->commit();
 * } catch (Failed $e) {
 *    echo "Failed, reason: ", $e->getMessage();
 * }
 *</code>
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
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *dependencyInjector = NULL, dependencyInjector_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		dependencyInjector = &dependencyInjector_sub;
		ZEPHIR_CPY_WRT(dependencyInjector, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(dependencyInjector);
	}


	if (!(zephir_is_true(dependencyInjector))) {
		ZEPHIR_CALL_CE_STATIC(dependencyInjector, phalcon_di_ce, "getdefault", &_0, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_transaction_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model/transaction/manager.zep", 93);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDI) {

	zval *dependencyInjector, dependencyInjector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets the database service used to run the isolated transactions
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDbService) {

	zval *service_param = NULL;
	zval service;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&service);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &service_param);

	if (UNEXPECTED(Z_TYPE_P(service_param) != IS_STRING && Z_TYPE_P(service_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'service' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(service_param) == IS_STRING)) {
		zephir_get_strval(&service, service_param);
	} else {
		ZEPHIR_INIT_VAR(&service);
		ZVAL_EMPTY_STRING(&service);
	}


	zephir_update_property_zval(this_ptr, SL("_service"), &service);
	RETURN_THIS();

}

/**
 * Returns the database service used to isolate the transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDbService) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_service");

}

/**
 * Set if the transaction manager must register a shutdown function to clean up pendent transactions
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setRollbackPendent) {

	zval *rollbackPendent_param = NULL, __$true, __$false;
	zend_bool rollbackPendent;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &rollbackPendent_param);

	rollbackPendent = zephir_get_boolval(rollbackPendent_param);


	if (rollbackPendent) {
		zephir_update_property_zval(this_ptr, SL("_rollbackPendent"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_rollbackPendent"), &__$false);
	}
	RETURN_THISW();

}

/**
 * Check if the transaction manager is registering a shutdown function to clean up pendent transactions
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getRollbackPendent) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_rollbackPendent");

}

/**
 * Checks whether the manager has an active transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, has) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_number"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_GT_LONG(&_0, 0));

}

/**
 * Returns a new \Phalcon\Mvc\Model\Transaction or an already created once
 * This method registers a shutdown function to rollback active connections
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, get) {

	zval _2$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *autoBegin_param = NULL, __$true, __$false, _0, _4, _1$$3, _3$$4;
	zend_bool autoBegin;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &autoBegin_param);

	if (!autoBegin_param) {
		autoBegin = 1;
	} else {
		autoBegin = zephir_get_boolval(autoBegin_param);
	}


	zephir_read_property(&_0, this_ptr, SL("_initialized"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, SL("_rollbackPendent"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_1$$3)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_create_array(&_2$$4, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&_2$$4, this_ptr);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "rollbackPendent");
			zephir_array_fast_append(&_2$$4, &_3$$4);
			ZEPHIR_CALL_FUNCTION(NULL, "register_shutdown_function", NULL, 373, &_2$$4);
			zephir_check_call_status();
		}
		if (1) {
			zephir_update_property_zval(this_ptr, SL("_initialized"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_initialized"), &__$false);
		}
	}
	if (autoBegin) {
		ZVAL_BOOL(&_4, 1);
	} else {
		ZVAL_BOOL(&_4, 0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getorcreatetransaction", NULL, 0, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Create/Returns a new transaction or an existing one
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getOrCreateTransaction) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *autoBegin_param = NULL, dependencyInjector, transaction, transactions, _0, _5, _6, *_1$$5, _2$$5, _3$$7, _4$$9;
	zend_bool autoBegin;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&transactions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &autoBegin_param);

	if (!autoBegin_param) {
		autoBegin = 1;
	} else {
		autoBegin = zephir_get_boolval(autoBegin_param);
	}


	zephir_read_property(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_0);
	if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_transaction_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model/transaction/manager.zep", 179);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("_number"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_OBS_VAR(&transactions);
		zephir_read_property(&transactions, this_ptr, SL("_transactions"), PH_NOISY_CC);
		if (Z_TYPE_P(&transactions) == IS_ARRAY) {
			zephir_is_iterable(&transactions, 0, "phalcon/mvc/model/transaction/manager.zep", 191);
			if (Z_TYPE_P(&transactions) == IS_ARRAY) {
				ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(&transactions), _1$$5)
				{
					ZEPHIR_INIT_NVAR(&transaction);
					ZVAL_COPY(&transaction, _1$$5);
					if (Z_TYPE_P(&transaction) == IS_OBJECT) {
						ZVAL_BOOL(&_3$$7, 0);
						ZEPHIR_CALL_METHOD(NULL, &transaction, "setisnewtransaction", NULL, 0, &_3$$7);
						zephir_check_call_status();
						RETURN_CCTOR(&transaction);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &transactions, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_2$$5, &transactions, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_2$$5)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&transaction, &transactions, "current", NULL, 0);
					zephir_check_call_status();
						if (Z_TYPE_P(&transaction) == IS_OBJECT) {
							ZVAL_BOOL(&_4$$9, 0);
							ZEPHIR_CALL_METHOD(NULL, &transaction, "setisnewtransaction", NULL, 0, &_4$$9);
							zephir_check_call_status();
							RETURN_CCTOR(&transaction);
						}
					ZEPHIR_CALL_METHOD(NULL, &transactions, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&transaction);
		}
	}
	ZEPHIR_INIT_NVAR(&transaction);
	object_init_ex(&transaction, phalcon_mvc_model_transaction_ce);
	zephir_read_property(&_5, this_ptr, SL("_service"), PH_NOISY_CC | PH_READONLY);
	if (autoBegin) {
		ZVAL_BOOL(&_6, 1);
	} else {
		ZVAL_BOOL(&_6, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &transaction, "__construct", NULL, 374, &dependencyInjector, &_6, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &transaction, "settransactionmanager", NULL, 375, this_ptr);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_transactions"), &transaction);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("_number") TSRMLS_CC));
	RETURN_CCTOR(&transaction);

}

/**
 * Rollbacks active transactions within the manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Commits active transactions within the manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, commit) {

	zval transactions, transaction, connection, *_0$$3, _1$$3, _2$$4, _3$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transactions);
	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&transactions);
	zephir_read_property(&transactions, this_ptr, SL("_transactions"), PH_NOISY_CC);
	if (Z_TYPE_P(&transactions) == IS_ARRAY) {
		zephir_is_iterable(&transactions, 0, "phalcon/mvc/model/transaction/manager.zep", 224);
		if (Z_TYPE_P(&transactions) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&transactions), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&transaction);
				ZVAL_COPY(&transaction, _0$$3);
				ZEPHIR_CALL_METHOD(&connection, &transaction, "getconnection", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_2$$4, &connection, "isundertransaction", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_2$$4)) {
					ZEPHIR_CALL_METHOD(NULL, &connection, "commit", NULL, 0);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &transactions, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &transactions, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&transaction, &transactions, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&connection, &transaction, "getconnection", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_3$$6, &connection, "isundertransaction", NULL, 0);
					zephir_check_call_status();
					if (zephir_is_true(&_3$$6)) {
						ZEPHIR_CALL_METHOD(NULL, &connection, "commit", NULL, 0);
						zephir_check_call_status();
					}
				ZEPHIR_CALL_METHOD(NULL, &transactions, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&transaction);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Rollbacks active transactions within the manager
 * Collect will remove the transaction from the manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollback) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collect_param = NULL, transactions, transaction, connection, *_0$$3, _1$$3, _2$$4, _4$$7;
	zend_bool collect;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transactions);
	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &collect_param);

	if (!collect_param) {
		collect = 1;
	} else {
		collect = zephir_get_boolval(collect_param);
	}


	ZEPHIR_OBS_VAR(&transactions);
	zephir_read_property(&transactions, this_ptr, SL("_transactions"), PH_NOISY_CC);
	if (Z_TYPE_P(&transactions) == IS_ARRAY) {
		zephir_is_iterable(&transactions, 0, "phalcon/mvc/model/transaction/manager.zep", 247);
		if (Z_TYPE_P(&transactions) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&transactions), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&transaction);
				ZVAL_COPY(&transaction, _0$$3);
				ZEPHIR_CALL_METHOD(&connection, &transaction, "getconnection", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_2$$4, &connection, "isundertransaction", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_2$$4)) {
					ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &connection, "close", NULL, 0);
					zephir_check_call_status();
				}
				if (collect) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_collecttransaction", &_3, 0, &transaction);
					zephir_check_call_status();
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &transactions, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &transactions, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&transaction, &transactions, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&connection, &transaction, "getconnection", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_4$$7, &connection, "isundertransaction", NULL, 0);
					zephir_check_call_status();
					if (zephir_is_true(&_4$$7)) {
						ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &connection, "close", NULL, 0);
						zephir_check_call_status();
					}
					if (collect) {
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "_collecttransaction", &_3, 0, &transaction);
						zephir_check_call_status();
					}
				ZEPHIR_CALL_METHOD(NULL, &transactions, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&transaction);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Notifies the manager about a rollbacked transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyRollback) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *transaction, transaction_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transaction_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &transaction);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_collecttransaction", NULL, 0, transaction);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Notifies the manager about a committed transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyCommit) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *transaction, transaction_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transaction_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &transaction);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_collecttransaction", NULL, 0, transaction);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Removes transactions from the TransactionManager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, _collectTransaction) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *transaction, transaction_sub, transactions, newTransactions, managedTransaction, *_0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transaction_sub);
	ZVAL_UNDEF(&transactions);
	ZVAL_UNDEF(&newTransactions);
	ZVAL_UNDEF(&managedTransaction);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &transaction);



	ZEPHIR_OBS_VAR(&transactions);
	zephir_read_property(&transactions, this_ptr, SL("_transactions"), PH_NOISY_CC);
	if (zephir_fast_count_int(&transactions TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&newTransactions);
		array_init(&newTransactions);
		zephir_is_iterable(&transactions, 0, "phalcon/mvc/model/transaction/manager.zep", 284);
		if (Z_TYPE_P(&transactions) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&transactions), _0$$3)
			{
				ZEPHIR_INIT_NVAR(&managedTransaction);
				ZVAL_COPY(&managedTransaction, _0$$3);
				if (!ZEPHIR_IS_EQUAL(&managedTransaction, transaction)) {
					zephir_array_append(&newTransactions, transaction, PH_SEPARATE, "phalcon/mvc/model/transaction/manager.zep", 278);
				} else {
					RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_number") TSRMLS_CC));
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &transactions, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &transactions, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&managedTransaction, &transactions, "current", NULL, 0);
				zephir_check_call_status();
					if (!ZEPHIR_IS_EQUAL(&managedTransaction, transaction)) {
						zephir_array_append(&newTransactions, transaction, PH_SEPARATE, "phalcon/mvc/model/transaction/manager.zep", 278);
					} else {
						RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_number") TSRMLS_CC));
					}
				ZEPHIR_CALL_METHOD(NULL, &transactions, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&managedTransaction);
		zephir_update_property_zval(this_ptr, SL("_transactions"), &newTransactions);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Remove all the transactions from the manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions) {

	zval __$null, transactions, _0$$3, *_1$$3, _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&transactions);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&transactions);
	zephir_read_property(&transactions, this_ptr, SL("_transactions"), PH_NOISY_CC);
	if (zephir_fast_count_int(&transactions TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_is_iterable(&transactions, 0, "phalcon/mvc/model/transaction/manager.zep", 300);
		if (Z_TYPE_P(&transactions) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&transactions), _1$$3)
			{
				ZEPHIR_INIT_NVAR(&_0$$3);
				ZVAL_COPY(&_0$$3, _1$$3);
				RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_number") TSRMLS_CC));
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &transactions, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_2$$3, &transactions, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_2$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&_0$$3, &transactions, "current", NULL, 0);
				zephir_check_call_status();
					RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("_number") TSRMLS_CC));
				ZEPHIR_CALL_METHOD(NULL, &transactions, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&_0$$3);
		zephir_update_property_zval(this_ptr, SL("_transactions"), &__$null);
	}
	ZEPHIR_MM_RESTORE();

}

