
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
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Mvc\Model\Transaction\Manager
 *
 * A transaction acts on a single database connection. If you have multiple
 * class-specific databases, the transaction will not protect interaction among
 * them.
 *
 * This class manages the objects that compose a transaction.
 * A transaction produces a unique connection that is passed to every object
 * part of the transaction.
 *
 * ```php
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
 *    if ($robot->save() === false) {
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
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Transaction_Manager)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Transaction, Manager, phalcon, mvc_model_transaction_manager, phalcon_mvc_model_transaction_manager_method_entry, 0);

	/**
	 * @var DiInterface|null
	 */
	zend_declare_property_null(phalcon_mvc_model_transaction_manager_ce, SL("container"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_transaction_manager_ce, SL("initialized"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var int
	 */
	zend_declare_property_long(phalcon_mvc_model_transaction_manager_ce, SL("number"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_mvc_model_transaction_manager_ce, SL("rollbackPendent"), 1, ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_mvc_model_transaction_manager_ce, SL("service"), "db", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_mvc_model_transaction_manager_ce, SL("transactions"), ZEND_ACC_PROTECTED);
	phalcon_mvc_model_transaction_manager_ce->create_object = zephir_init_properties_Phalcon_Mvc_Model_Transaction_Manager;

	zend_class_implements(phalcon_mvc_model_transaction_manager_ce, 1, phalcon_mvc_model_transaction_managerinterface_ce);
	zend_class_implements(phalcon_mvc_model_transaction_manager_ce, 1, phalcon_di_injectionawareinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model\Transaction\Manager constructor
 *
 * @param DiInterface|null container
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container = NULL, container_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &container);
	if (!container) {
		container = &container_sub;
		ZEPHIR_CPY_WRT(container, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(container);
	}
	if (!(zephir_is_true(container))) {
		ZEPHIR_CALL_CE_STATIC(container, phalcon_di_di_ce, "getdefault", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
	if (UNEXPECTED(Z_TYPE_P(container) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_transaction_exception_ce, "A dependency injection container is required to access the services related to the ORM", "phalcon/Mvc/Model/Transaction/Manager.zep", 114);
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Remove all the transactions from the manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, collectTransactions)
{
	zval transactions, _0, _1, *_2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transactions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("transactions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&transactions, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_is_iterable(&transactions, 0, "phalcon/Mvc/Model/Transaction/Manager.zep", 131);
	if (Z_TYPE_P(&transactions) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&transactions), _2)
		{
			ZEPHIR_INIT_NVAR(&_1);
			ZVAL_COPY(&_1, _2);
			RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("number")));
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &transactions, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &transactions, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&_1, &transactions, "current", NULL, 0);
			zephir_check_call_status();
				RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("number")));
			ZEPHIR_CALL_METHOD(NULL, &transactions, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	zephir_update_property_zval(this_ptr, ZEND_STRL("transactions"), &_4);
	ZEPHIR_MM_RESTORE();
}

/**
 * Commits active transactions within the manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, commit)
{
	zval transactions, transaction, connection, _0, *_1, _2, _3$$3, _4$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transactions);
	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("transactions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&transactions, &_0);
	zephir_is_iterable(&transactions, 0, "phalcon/Mvc/Model/Transaction/Manager.zep", 150);
	if (Z_TYPE_P(&transactions) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&transactions), _1)
		{
			ZEPHIR_INIT_NVAR(&transaction);
			ZVAL_COPY(&transaction, _1);
			ZEPHIR_CALL_METHOD(&connection, &transaction, "getconnection", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_3$$3, &connection, "isundertransaction", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_3$$3)) {
				ZEPHIR_CALL_METHOD(NULL, &connection, "commit", NULL, 0);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &transactions, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &transactions, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&transaction, &transactions, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&connection, &transaction, "getconnection", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4$$5, &connection, "isundertransaction", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_4$$5)) {
					ZEPHIR_CALL_METHOD(NULL, &connection, "commit", NULL, 0);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &transactions, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&transaction);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns a new \Phalcon\Mvc\Model\Transaction or an already created once
 * This method registers a shutdown function to rollback active connections
 *
 * @param bool autoBegin
 *
 * @return TransactionInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, get)
{
	zval _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(autoBegin)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &autoBegin_param);
	if (!autoBegin_param) {
		autoBegin = 1;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("initialized"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("rollbackPendent"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_1$$3)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_create_array(&_2$$4, 2, 0);
			zephir_array_fast_append(&_2$$4, this_ptr);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "rollbackPendent");
			zephir_array_fast_append(&_2$$4, &_3$$4);
			ZEPHIR_CALL_FUNCTION(NULL, "register_shutdown_function", NULL, 486, &_2$$4);
			zephir_check_call_status();
		}
		if (1) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("initialized"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("initialized"), &__$false);
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
 * Returns the database service used to isolate the transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDbService)
{

	RETURN_MEMBER(getThis(), "service");
}

/**
 * Returns the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getDI)
{

	RETURN_MEMBER(getThis(), "container");
}

/**
 * Create/Returns a new transaction or an existing one
 *
 * @param bool autoBegin
 *
 * @return TransactionInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getOrCreateTransaction)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *autoBegin_param = NULL, container, transaction, transactions, _0, _6, _7, _1$$4, *_2$$4, _3$$4, _4$$6, _5$$8;
	zend_bool autoBegin;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container);
	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&transactions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$8);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(autoBegin)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &autoBegin_param);
	if (!autoBegin_param) {
		autoBegin = 1;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&container, &_0);
	if (UNEXPECTED(Z_TYPE_P(&container) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_transaction_exception_ce, "A dependency injection container is required to access the services related to the ORM", "phalcon/Mvc/Model/Transaction/Manager.zep", 210);
		return;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("number"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("transactions"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&transactions, &_1$$4);
		zephir_is_iterable(&transactions, 0, "phalcon/Mvc/Model/Transaction/Manager.zep", 223);
		if (Z_TYPE_P(&transactions) == IS_ARRAY) {
			ZEND_HASH_REVERSE_FOREACH_VAL(Z_ARRVAL_P(&transactions), _2$$4)
			{
				ZEPHIR_INIT_NVAR(&transaction);
				ZVAL_COPY(&transaction, _2$$4);
				if (Z_TYPE_P(&transaction) == IS_OBJECT) {
					ZVAL_BOOL(&_4$$6, 0);
					ZEPHIR_CALL_METHOD(NULL, &transaction, "setisnewtransaction", NULL, 0, &_4$$6);
					zephir_check_call_status();
					RETURN_CCTOR(&transaction);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &transactions, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_3$$4, &transactions, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_3$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&transaction, &transactions, "current", NULL, 0);
				zephir_check_call_status();
					if (Z_TYPE_P(&transaction) == IS_OBJECT) {
						ZVAL_BOOL(&_5$$8, 0);
						ZEPHIR_CALL_METHOD(NULL, &transaction, "setisnewtransaction", NULL, 0, &_5$$8);
						zephir_check_call_status();
						RETURN_CCTOR(&transaction);
					}
				ZEPHIR_CALL_METHOD(NULL, &transactions, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&transaction);
	}
	ZEPHIR_INIT_NVAR(&transaction);
	object_init_ex(&transaction, phalcon_mvc_model_transaction_ce);
	zephir_read_property(&_6, this_ptr, ZEND_STRL("service"), PH_NOISY_CC | PH_READONLY);
	if (autoBegin) {
		ZVAL_BOOL(&_7, 1);
	} else {
		ZVAL_BOOL(&_7, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &transaction, "__construct", NULL, 487, &container, &_7, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &transaction, "settransactionmanager", NULL, 488, this_ptr);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("transactions"), &transaction);
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("number")));
	RETURN_CCTOR(&transaction);
}

/**
 * Check if the transaction manager is registering a shutdown function to
 * clean up pendent transactions
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, getRollbackPendent)
{

	RETURN_MEMBER(getThis(), "rollbackPendent");
}

/**
 * Checks whether the manager has an active transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, has)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("number"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_GT_LONG(&_0, 0));
}

/**
 * Notifies the manager about a committed transaction
 *
 * @param TransactionInterface transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyCommit)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *transaction, transaction_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transaction_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(transaction, phalcon_mvc_model_transactioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &transaction);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "collecttransaction", NULL, 0, transaction);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Notifies the manager about a rollbacked transaction
 *
 * @param TransactionInterface transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, notifyRollback)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *transaction, transaction_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transaction_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(transaction, phalcon_mvc_model_transactioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &transaction);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "collecttransaction", NULL, 0, transaction);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Rollbacks active transactions within the manager
 * Collect will remove the transaction from the manager
 *
 * @param bool collect
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollback)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *collect_param = NULL, transactions, transaction, connection, _0, *_1, _2, _3$$3, _5$$6;
	zend_bool collect;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transactions);
	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$6);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(collect)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &collect_param);
	if (!collect_param) {
		collect = 1;
	} else {
		}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("transactions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&transactions, &_0);
	zephir_is_iterable(&transactions, 0, "phalcon/Mvc/Model/Transaction/Manager.zep", 294);
	if (Z_TYPE_P(&transactions) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&transactions), _1)
		{
			ZEPHIR_INIT_NVAR(&transaction);
			ZVAL_COPY(&transaction, _1);
			ZEPHIR_CALL_METHOD(&connection, &transaction, "getconnection", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_3$$3, &connection, "isundertransaction", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_3$$3)) {
				ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &connection, "close", NULL, 0);
				zephir_check_call_status();
			}
			if (collect) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "collecttransaction", &_4, 0, &transaction);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &transactions, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &transactions, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&transaction, &transactions, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&connection, &transaction, "getconnection", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$6, &connection, "isundertransaction", NULL, 0);
				zephir_check_call_status();
				if (zephir_is_true(&_5$$6)) {
					ZEPHIR_CALL_METHOD(NULL, &connection, "rollback", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &connection, "close", NULL, 0);
					zephir_check_call_status();
				}
				if (collect) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "collecttransaction", &_4, 0, &transaction);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &transactions, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&transaction);
	ZEPHIR_MM_RESTORE();
}

/**
 * Rollbacks active transactions within the manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, rollbackPendent)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Sets the database service used to run the isolated transactions
 *
 * @param string service
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDbService)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *service_param = NULL;
	zval service;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&service);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(service)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &service_param);
	if (UNEXPECTED(Z_TYPE_P(service_param) != IS_STRING && Z_TYPE_P(service_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'service' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(service_param) == IS_STRING)) {
		zephir_get_strval(&service, service_param);
	} else {
		ZEPHIR_INIT_VAR(&service);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("service"), &service);
	RETURN_THIS();
}

/**
 * Sets the dependency injection container
 *
 * @param DiInterface container
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setDI)
{
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(container, phalcon_di_diinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &container);
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), container);
}

/**
 * Set if the transaction manager must register a shutdown function to clean
 * up pendent transactions
 *
 * @param bool rollbackPendent
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, setRollbackPendent)
{
	zval *rollbackPendent_param = NULL, __$true, __$false;
	zend_bool rollbackPendent;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(rollbackPendent)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &rollbackPendent_param);
	if (rollbackPendent) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("rollbackPendent"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("rollbackPendent"), &__$false);
	}
	RETURN_THISW();
}

/**
 * Removes transactions from the TransactionManager
 *
 * @param TransactionInterface transaction
 */
PHP_METHOD(Phalcon_Mvc_Model_Transaction_Manager, collectTransaction)
{
	zval newTransactions;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *transaction, transaction_sub, managedTransaction, _0, *_1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&transaction_sub);
	ZVAL_UNDEF(&managedTransaction);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&newTransactions);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(transaction, phalcon_mvc_model_transactioninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &transaction);
	ZEPHIR_INIT_VAR(&newTransactions);
	array_init(&newTransactions);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("transactions"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalcon/Mvc/Model/Transaction/Manager.zep", 359);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&managedTransaction);
			ZVAL_COPY(&managedTransaction, _1);
			if (!ZEPHIR_IS_EQUAL(&managedTransaction, transaction)) {
				zephir_array_append(&newTransactions, transaction, PH_SEPARATE, "phalcon/Mvc/Model/Transaction/Manager.zep", 353);
			} else {
				RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("number")));
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&managedTransaction, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (!ZEPHIR_IS_EQUAL(&managedTransaction, transaction)) {
					zephir_array_append(&newTransactions, transaction, PH_SEPARATE, "phalcon/Mvc/Model/Transaction/Manager.zep", 353);
				} else {
					RETURN_ON_FAILURE(zephir_property_decr(this_ptr, SL("number")));
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&managedTransaction);
	zephir_update_property_zval(this_ptr, ZEND_STRL("transactions"), &newTransactions);
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_Phalcon_Mvc_Model_Transaction_Manager(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("transactions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("transactions"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

