
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/iterator.h"


/**
 * Phalcon\Mvc\Model
 *
 * Phalcon\Mvc\Model connects business objects and database tables to create
 * a persistable domain model where logic and data are presented in one wrapping.
 * It‘s an implementation of the object-relational mapping (ORM).
 *
 * A model represents the information (data) of the application and the rules to manipulate that data.
 * Models are primarily used for managing the rules of interaction with a corresponding database table.
 * In most cases, each table in your database will correspond to one model in your application.
 * The bulk of your application's business logic will be concentrated in the models.
 *
 * Phalcon\Mvc\Model is the first ORM written in Zephir/C languages for PHP, giving to developers high performance
 * when interacting with databases while is also easy to use.
 *
 * <code>
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * if ($robot->save() === false) {
 *     echo "Umh, We can store robots: ";
 *
 *     $messages = $robot->getMessages();
 *
 *     foreach ($messages as $message) {
 *         echo $message;
 *     }
 * } else {
 *     echo "Great, a new robot was saved successfully!";
 * }
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc, Model, phalcon, mvc_model, phalcon_mvc_model_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_modelsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_modelsMetaData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_errorMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_model_ce, SL("_operationMade"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalcon_mvc_model_ce, SL("_dirtyState"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_transaction"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueKey"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueParams"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_skipped"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_related"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_snapshot"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_oldSnapshot"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(phalcon_mvc_model_ce, SL("TRANSACTION_INDEX"), "transaction" TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_NONE"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_CREATE"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_UPDATE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_DELETE"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_PERSISTENT"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_TRANSIENT"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_DETACHED"), 2 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_mvc_entityinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_mvc_modelinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_mvc_model_resultinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, zend_ce_serializable);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("jsonserializable") TSRMLS_CC));
	return SUCCESS;

}

PHP_METHOD(Phalcon_Mvc_Model, getTransaction) {

	

	RETURN_MEMBER(getThis(), "_transaction");

}

/**
 * Phalcon\Mvc\Model constructor
 */
PHP_METHOD(Phalcon_Mvc_Model, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *data = NULL, *dependencyInjector = NULL, *modelsManager = NULL, *_0, *_2$$5 = NULL, *_3$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &data, &dependencyInjector, &modelsManager);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}
	if (!dependencyInjector) {
		ZEPHIR_CPY_WRT(dependencyInjector, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(dependencyInjector);
	}
	if (!modelsManager) {
		ZEPHIR_CPY_WRT(modelsManager, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(modelsManager);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(getThis(), SL("_oldSnapshot"), _0 TSRMLS_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_1, 1);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model.zep", 147);
		return;
	}
	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_3$$5);
		ZVAL_STRING(_3$$5, "modelsManager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2$$5, dependencyInjector, "getshared", NULL, 0, _3$$5);
		zephir_check_temp_parameter(_3$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(modelsManager, _2$$5);
		if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/mvc/model.zep", 158);
			return;
		}
	}
	zephir_update_property_this(getThis(), SL("_modelsManager"), modelsManager TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, modelsManager, "initialize", NULL, 0, this_ptr);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, SS("onconstruct") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0, data);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, data);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model, getDI) {

	

	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

/**
 * Sets a custom events manager
 */
PHP_METHOD(Phalcon_Mvc_Model, setEventsManager) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventsManager, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventsManager);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setcustomeventsmanager", NULL, 0, this_ptr, eventsManager);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the custom events manager
 */
PHP_METHOD(Phalcon_Mvc_Model, getEventsManager) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getcustomeventsmanager", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the models meta-data service related to the entity instance
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsMetaData) {

	zval *metaData = NULL, *dependencyInjector = NULL, *_0$$3, *_1$$3 = NULL, *_2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_modelsMetaData"), PH_NOISY_CC);
	if (Z_TYPE_P(metaData) != IS_OBJECT) {
		_0$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(dependencyInjector, _0$$3);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1$$3, dependencyInjector, "getshared", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(metaData, _1$$3);
		if (Z_TYPE_P(metaData) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsMetadata' is not valid", "phalcon/mvc/model.zep", 233);
			return;
		}
		zephir_update_property_this(getThis(), SL("_modelsMetaData"), metaData TSRMLS_CC);
	}
	RETURN_CCTOR(metaData);

}

/**
 * Returns the models manager related to the entity instance
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsManager) {

	

	RETURN_MEMBER(getThis(), "_modelsManager");

}

/**
 * Sets a transaction related to the Model instance
 *
 *<code>
 * use Phalcon\Mvc\Model\Transaction\Manager as TxManager;
 * use Phalcon\Mvc\Model\Transaction\Failed as TxFailed;
 *
 * try {
 *     $txManager = new TxManager();
 *
 *     $transaction = $txManager->get();
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
 *         $transaction->rollback("Robot part cannot be saved");
 *     }
 *
 *     $transaction->commit();
 * } catch (TxFailed $e) {
 *     echo "Failed, reason: ", $e->getMessage();
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, setTransaction) {

	zval *transaction;

	zephir_fetch_params(0, 1, 0, &transaction);



	zephir_update_property_this(getThis(), SL("_transaction"), transaction TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets the table name to which model should be mapped
 */
PHP_METHOD(Phalcon_Mvc_Model, setSource) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, *_0;
	zval *source = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &source_param);

	if (UNEXPECTED(Z_TYPE_P(source_param) != IS_STRING && Z_TYPE_P(source_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(source_param) == IS_STRING)) {
		zephir_get_strval(source, source_param);
	} else {
		ZEPHIR_INIT_VAR(source);
		ZVAL_EMPTY_STRING(source);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setmodelsource", NULL, 0, this_ptr, source);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Returns the table name mapped in the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getSource) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getmodelsource", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets schema name where the mapped table is located
 */
PHP_METHOD(Phalcon_Mvc_Model, setSchema) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *schema_param = NULL, *_0;
	zval *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(schema_param) != IS_STRING && Z_TYPE_P(schema_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schema_param) == IS_STRING)) {
		zephir_get_strval(schema, schema_param);
	} else {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "setmodelschema", NULL, 0, this_ptr, schema);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns schema name where the mapped table is located
 */
PHP_METHOD(Phalcon_Mvc_Model, getSchema) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getmodelschema", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the DependencyInjection connection service name
 */
PHP_METHOD(Phalcon_Mvc_Model, setConnectionService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, *_0;
	zval *connectionService = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(connectionService);
		ZVAL_EMPTY_STRING(connectionService);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setconnectionservice", NULL, 0, this_ptr, connectionService);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets the DependencyInjection connection service name used to read data
 */
PHP_METHOD(Phalcon_Mvc_Model, setReadConnectionService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, *_0;
	zval *connectionService = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(connectionService);
		ZVAL_EMPTY_STRING(connectionService);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "setreadconnectionservice", NULL, 0, this_ptr, connectionService);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets the DependencyInjection connection service name used to write data
 */
PHP_METHOD(Phalcon_Mvc_Model, setWriteConnectionService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, *_0;
	zval *connectionService = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (UNEXPECTED(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(connectionService);
		ZVAL_EMPTY_STRING(connectionService);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "setwriteconnectionservice", NULL, 0, this_ptr, connectionService);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the DependencyInjection connection service name used to read data related the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnectionService) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getreadconnectionservice", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the DependencyInjection connection service name used to write data related to the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnectionService) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getwriteconnectionservice", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
 */
PHP_METHOD(Phalcon_Mvc_Model, setDirtyState) {

	zval *dirtyState_param = NULL, *_0;
	zend_long dirtyState;

	zephir_fetch_params(0, 1, 0, &dirtyState_param);

	dirtyState = zephir_get_intval(dirtyState_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, dirtyState);
	zephir_update_property_this(getThis(), SL("_dirtyState"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns one of the DIRTY_STATE_* constants telling if the record exists in the database or not
 */
PHP_METHOD(Phalcon_Mvc_Model, getDirtyState) {

	

	RETURN_MEMBER(getThis(), "_dirtyState");

}

/**
 * Gets the connection used to read data for the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnection) {

	zval *transaction = NULL, *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_transaction"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(transaction, _0);
	if (Z_TYPE_P(transaction) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getreadconnection", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets the connection used to write data to the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnection) {

	zval *transaction = NULL, *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_transaction"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(transaction, _0);
	if (Z_TYPE_P(transaction) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getwriteconnection", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Assigns values to a model from an array
 *
 * <code>
 * $robot->assign(
 *     [
 *         "type" => "mechanical",
 *         "name" => "Astro Boy",
 *         "year" => 1952,
 *     ]
 * );
 *
 * // Assign by db row, column map needed
 * $robot->assign(
 *     $dbRow,
 *     [
 *         "db_type" => "type",
 *         "db_name" => "name",
 *         "db_year" => "year",
 *     ]
 * );
 *
 * // Allow assign only name and year
 * $robot->assign(
 *     $_POST,
 *     null,
 *     [
 *         "name",
 *         "year",
 *     ]
 * );
 *
 * // By default assign method will use setters if exist, you can disable it by using ini_set to directly use properties
 *
 * ini_set("phalcon.orm.disable_assign_setters", true);
 *
 * $robot->assign(
 *     $_POST,
 *     null,
 *     [
 *         "name",
 *         "year",
 *     ]
 * );
 * </code>
 *
 * @param array data
 * @param array dataColumnMap array to transform keys of data to another
 * @param array whiteList
 * @return \Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, assign) {

	zend_bool _10$$16;
	HashTable *_5, *_1$$3;
	HashPosition _4, _0$$3;
	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *dataColumnMap = NULL, *whiteList = NULL, *key = NULL, *keyMapped = NULL, *value = NULL, *attribute = NULL, *attributeField = NULL, *metaData = NULL, *columnMap = NULL, *dataMapped = NULL, *disableAssignSetters = NULL, *_3 = NULL, **_6, **_2$$3, *_7$$13 = NULL, *_8$$13 = NULL, *_11$$16 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &data_param, &dataColumnMap, &whiteList);

	data = data_param;
	if (!dataColumnMap) {
		dataColumnMap = ZEPHIR_GLOBAL(global_null);
	}
	if (!whiteList) {
		whiteList = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(disableAssignSetters);
	ZVAL_BOOL(disableAssignSetters, ZEPHIR_GLOBAL(orm).disable_assign_setters);
	if (Z_TYPE_P(dataColumnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(dataMapped);
		array_init(dataMapped);
		zephir_is_iterable(data, &_1$$3, &_0$$3, 0, 0, "phalcon/mvc/model.zep", 484);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _1$$3, _0$$3);
			ZEPHIR_GET_HVALUE(value, _2$$3);
			ZEPHIR_OBS_NVAR(keyMapped);
			if (zephir_array_isset_fetch(&keyMapped, dataColumnMap, key, 0 TSRMLS_CC)) {
				zephir_array_update_zval(&dataMapped, keyMapped, &value, PH_COPY | PH_SEPARATE);
			}
		}
	} else {
		ZEPHIR_CPY_WRT(dataMapped, data);
	}
	if (zephir_fast_count_int(dataMapped TSRMLS_CC) == 0) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(columnMap);
		ZVAL_NULL(columnMap);
	}
	ZEPHIR_CALL_METHOD(&_3, metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "phalcon/mvc/model.zep", 533);
	for (
	  ; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(attribute, _6);
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, columnMap, attribute, 0 TSRMLS_CC))) {
				if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
					ZEPHIR_INIT_NVAR(_7$$13);
					object_init_ex(_7$$13, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_8$$13);
					ZEPHIR_CONCAT_SVS(_8$$13, "Column '", attribute, "' doesn\\'t make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _7$$13, "__construct", &_9, 9, _8$$13);
					zephir_check_call_status();
					zephir_throw_exception_debug(_7$$13, "phalcon/mvc/model.zep", 506 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					continue;
				}
			}
		} else {
			ZEPHIR_CPY_WRT(attributeField, attribute);
		}
		ZEPHIR_OBS_NVAR(value);
		if (zephir_array_isset_fetch(&value, dataMapped, attributeField, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(whiteList) == IS_ARRAY) {
				if (!(zephir_fast_in_array(attributeField, whiteList TSRMLS_CC))) {
					continue;
				}
			}
			_10$$16 = zephir_is_true(disableAssignSetters);
			if (!(_10$$16)) {
				ZEPHIR_CALL_METHOD(&_11$$16, this_ptr, "_possiblesetter", &_12, 330, attributeField, value);
				zephir_check_call_status();
				_10$$16 = !zephir_is_true(_11$$16);
			}
			if (_10$$16) {
				zephir_update_property_zval_zval(getThis(), attributeField, value TSRMLS_CC);
			}
		}
	}
	RETURN_THIS();

}

/**
 * Assigns values to a model from an array, returning a new model.
 *
 *<code>
 * $robot = \Phalcon\Mvc\Model::cloneResultMap(
 *     new Robots(),
 *     [
 *         "type" => "mechanical",
 *         "name" => "Astro Boy",
 *         "year" => 1952,
 *     ]
 * );
 *</code>
 *
 * @param \Phalcon\Mvc\ModelInterface|\Phalcon\Mvc\Model\Row base
 * @param array data
 * @param array columnMap
 * @param int dirtyState
 * @param boolean keepSnapshots
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMap) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL;
	zend_bool keepSnapshots, _7$$4;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *base, *data_param = NULL, *columnMap, *dirtyState_param = NULL, *keepSnapshots_param = NULL, *instance = NULL, *attribute = NULL, *key = NULL, *value = NULL, *castValue = NULL, *attributeName = NULL, *_0, **_3, *_4$$7 = NULL, *_5$$7 = NULL, *_8$$10, _9$$11 = zval_used_for_init, *_11$$15, *_12$$19;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &base, &data_param, &columnMap, &dirtyState_param, &keepSnapshots_param);

	data = data_param;
	if (!dirtyState_param) {
		dirtyState = 0;
	} else {
		dirtyState = zephir_get_intval(dirtyState_param);
	}
	if (!keepSnapshots_param) {
		keepSnapshots = 0;
	} else {
		keepSnapshots = zephir_get_boolval(keepSnapshots_param);
	}


	ZEPHIR_INIT_VAR(instance);
	if (zephir_clone(instance, base TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, instance, "setdirtystate", NULL, 0, _0);
	zephir_check_call_status();
	zephir_is_iterable(data, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 635);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (Z_TYPE_P(key) == IS_STRING) {
			if (Z_TYPE_P(columnMap) != IS_ARRAY) {
				zephir_update_property_zval_zval(instance, key, value TSRMLS_CC);
				continue;
			}
			ZEPHIR_OBS_NVAR(attribute);
			if (!(zephir_array_isset_fetch(&attribute, columnMap, key, 0 TSRMLS_CC))) {
				if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
					ZEPHIR_INIT_NVAR(_4$$7);
					object_init_ex(_4$$7, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5$$7);
					ZEPHIR_CONCAT_SVS(_5$$7, "Column '", key, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _4$$7, "__construct", &_6, 9, _5$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(_4$$7, "phalcon/mvc/model.zep", 578 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					continue;
				}
			}
			if (Z_TYPE_P(attribute) != IS_ARRAY) {
				zephir_update_property_zval_zval(instance, attribute, value TSRMLS_CC);
				continue;
			}
			_7$$4 = !ZEPHIR_IS_STRING(value, "");
			if (_7$$4) {
				_7$$4 = Z_TYPE_P(value) != IS_NULL;
			}
			if (_7$$4) {
				zephir_array_fetch_long(&_8$$10, attribute, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 590 TSRMLS_CC);
				do {
					if (ZEPHIR_IS_LONG(_8$$10, 0)) {
						ZEPHIR_SINIT_NVAR(_9$$11);
						ZVAL_LONG(&_9$$11, 10);
						ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_10, 39, value, &_9$$11);
						zephir_check_call_status();
						break;
					}
					if (ZEPHIR_IS_LONG(_8$$10, 9) || ZEPHIR_IS_LONG(_8$$10, 3) || ZEPHIR_IS_LONG(_8$$10, 7)) {
						ZEPHIR_INIT_NVAR(castValue);
						ZVAL_DOUBLE(castValue, zephir_get_doubleval(value));
						break;
					}
					if (ZEPHIR_IS_LONG(_8$$10, 8)) {
						ZEPHIR_INIT_NVAR(castValue);
						ZVAL_BOOL(castValue, zephir_get_boolval(value));
						break;
					}
					ZEPHIR_CPY_WRT(castValue, value);
					break;
				} while(0);

			} else {
				zephir_array_fetch_long(&_11$$15, attribute, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 611 TSRMLS_CC);
				do {
					if (ZEPHIR_IS_LONG(_11$$15, 0) || ZEPHIR_IS_LONG(_11$$15, 9) || ZEPHIR_IS_LONG(_11$$15, 3) || ZEPHIR_IS_LONG(_11$$15, 7) || ZEPHIR_IS_LONG(_11$$15, 8)) {
						ZEPHIR_INIT_NVAR(castValue);
						ZVAL_NULL(castValue);
						break;
					}
					ZEPHIR_CPY_WRT(castValue, value);
					break;
				} while(0);

			}
			ZEPHIR_OBS_NVAR(attributeName);
			zephir_array_fetch_long(&attributeName, attribute, 0, PH_NOISY, "phalcon/mvc/model.zep", 627 TSRMLS_CC);
			zephir_update_property_zval_zval(instance, attributeName, castValue TSRMLS_CC);
		}
	}
	if (keepSnapshots) {
		ZEPHIR_CALL_METHOD(NULL, instance, "setsnapshotdata", NULL, 0, data, columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, instance, "setoldsnapshotdata", NULL, 0, data, columnMap);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(instance, SS("fireevent") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(_12$$19);
		ZVAL_STRING(_12$$19, "afterFetch", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, instance, "fireevent", NULL, 0, _12$$19);
		zephir_check_temp_parameter(_12$$19);
		zephir_check_call_status();
	}
	RETURN_CCTOR(instance);

}

/**
 * Returns an hydrated result based on the data and the column map
 *
 * @param array data
 * @param array columnMap
 * @param int hydrationMode
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMapHydrate) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long hydrationMode, ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap, *hydrationMode_param = NULL, *hydrateArray = NULL, *hydrateObject = NULL, *key = NULL, *value = NULL, *attribute = NULL, *attributeName = NULL, **_2, *_3$$11 = NULL, *_4$$11 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data_param, &columnMap, &hydrationMode_param);

	data = data_param;
	hydrationMode = zephir_get_intval(hydrationMode_param);


	if (Z_TYPE_P(columnMap) != IS_ARRAY) {
		if (hydrationMode == 1) {
			RETURN_CTOR(data);
		}
	}
	if (hydrationMode == 1) {
		ZEPHIR_INIT_VAR(hydrateArray);
		array_init(hydrateArray);
	} else {
		ZEPHIR_INIT_VAR(hydrateObject);
		object_init(hydrateObject);
	}
	zephir_is_iterable(data, &_1, &_0, 0, 0, "phalcon/mvc/model.zep", 721);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (Z_TYPE_P(key) != IS_STRING) {
			continue;
		}
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(attribute);
			if (!(zephir_array_isset_fetch(&attribute, columnMap, key, 0 TSRMLS_CC))) {
				if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
					ZEPHIR_INIT_NVAR(_3$$11);
					object_init_ex(_3$$11, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4$$11);
					ZEPHIR_CONCAT_SVS(_4$$11, "Column '", key, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _3$$11, "__construct", &_5, 9, _4$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(_3$$11, "phalcon/mvc/model.zep", 692 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					continue;
				}
			}
			if (Z_TYPE_P(attribute) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeName);
				zephir_array_fetch_long(&attributeName, attribute, 0, PH_NOISY, "phalcon/mvc/model.zep", 702 TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(attributeName, attribute);
			}
			if (hydrationMode == 1) {
				zephir_array_update_zval(&hydrateArray, attributeName, &value, PH_COPY | PH_SEPARATE);
			} else {
				zephir_update_property_zval_zval(hydrateObject, attributeName, value TSRMLS_CC);
			}
		} else {
			if (hydrationMode == 1) {
				zephir_array_update_zval(&hydrateArray, key, &value, PH_COPY | PH_SEPARATE);
			} else {
				zephir_update_property_zval_zval(hydrateObject, key, value TSRMLS_CC);
			}
		}
	}
	if (hydrationMode == 1) {
		RETURN_CCTOR(hydrateArray);
	}
	RETURN_CCTOR(hydrateObject);

}

/**
 * Assigns values to a model from an array returning a new model
 *
 *<code>
 * $robot = Phalcon\Mvc\Model::cloneResult(
 *     new Robots(),
 *     [
 *         "type" => "mechanical",
 *         "name" => "Astro Boy",
 *         "year" => 1952,
 *     ]
 * );
 *</code>
 *
 * @param \Phalcon\Mvc\ModelInterface $base
 * @param array data
 * @param int dirtyState
 * @return \Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResult) {

	HashTable *_2;
	HashPosition _1;
	zend_long dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *base, *data_param = NULL, *dirtyState_param = NULL, *instance = NULL, *key = NULL, *value = NULL, *_0 = NULL, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &base, &data_param, &dirtyState_param);

	data = data_param;
	if (!dirtyState_param) {
		dirtyState = 0;
	} else {
		dirtyState = zephir_get_intval(dirtyState_param);
	}


	ZEPHIR_INIT_VAR(instance);
	if (zephir_clone(instance, base TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, instance, "setdirtystate", NULL, 0, _0);
	zephir_check_call_status();
	zephir_is_iterable(data, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 771);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (Z_TYPE_P(key) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid key in array data provided to dumpResult()", "phalcon/mvc/model.zep", 763);
			return;
		}
		zephir_update_property_zval_zval(instance, key, value TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "afterFetch", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, instance, "fireevent", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_CCTOR(instance);

}

/**
 * Query for a set of records that match the specified conditions
 *
 * <code>
 * // How many robots are there?
 * $robots = Robots::find();
 *
 * echo "There are ", count($robots), "\n";
 *
 * // How many mechanical robots are there?
 * $robots = Robots::find(
 *     "type = 'mechanical'"
 * );
 *
 * echo "There are ", count($robots), "\n";
 *
 * // Get and print virtual robots ordered by name
 * $robots = Robots::find(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *     ]
 * );
 *
 * foreach ($robots as $robot) {
 *	 echo $robot->name, "\n";
 * }
 *
 * // Get first 100 virtual robots ordered by name
 * $robots = Robots::find(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *         "limit" => 100,
 *     ]
 * );
 *
 * foreach ($robots as $robot) {
 *	 echo $robot->name, "\n";
 * }
 *
 * // encapsulate find it into an running transaction esp. useful for application unit-tests
 * // or complex business logic where we wanna control which transactions are used.
 *
 * $myTransaction = new Transaction(\Phalcon\Di::getDefault());
 * $myTransaction->begin();
 * $newRobot = new Robot();
 * $newRobot->setTransaction($myTransaction);
 * $newRobot->save(['name' => 'test', 'type' => 'mechanical', 'year' => 1944]);
 *
 * $resultInsideTransaction = Robot::find(['name' => 'test', Model::TRANSACTION_INDEX => $myTransaction]);
 * $resultOutsideTransaction = Robot::find(['name' => 'test']);
 *
 * foreach ($setInsideTransaction as $robot) {
 *     echo $robot->name, "\n";
 * }
 *
 * foreach ($setOutsideTransaction as $robot) {
 *     echo $robot->name, "\n";
 * }
 *
 * // reverts all not commited changes
 * $myTransaction->rollback();
 *
 * // creating two different transactions
 * $myTransaction1 = new Transaction(\Phalcon\Di::getDefault());
 * $myTransaction1->begin();
 * $myTransaction2 = new Transaction(\Phalcon\Di::getDefault());
 * $myTransaction2->begin();
 *
 *  // add a new robots
 * $firstNewRobot = new Robot();
 * $firstNewRobot->setTransaction($myTransaction1);
 * $firstNewRobot->save(['name' => 'first-transaction-robot', 'type' => 'mechanical', 'year' => 1944]);
 *
 * $secondNewRobot = new Robot();
 * $secondNewRobot->setTransaction($myTransaction2);
 * $secondNewRobot->save(['name' => 'second-transaction-robot', 'type' => 'fictional', 'year' => 1984]);
 *
 * // this transaction will find the robot.
 * $resultInFirstTransaction = Robot::find(['name' => 'first-transaction-robot', Model::TRANSACTION_INDEX => $myTransaction1]);
 * // this transaction won't find the robot.
 * $resultInSecondTransaction = Robot::find(['name' => 'first-transaction-robot', Model::TRANSACTION_INDEX => $myTransaction2]);
 * // this transaction won't find the robot.
 * $resultOutsideAnyExplicitTransaction = Robot::find(['name' => 'first-transaction-robot']);
 *
 * // this transaction won't find the robot.
 * $resultInFirstTransaction = Robot::find(['name' => 'second-transaction-robot', Model::TRANSACTION_INDEX => $myTransaction2]);
 * // this transaction will find the robot.
 * $resultInSecondTransaction = Robot::find(['name' => 'second-transaction-robot', Model::TRANSACTION_INDEX => $myTransaction1]);
 * // this transaction won't find the robot.
 * $resultOutsideAnyExplicitTransaction = Robot::find(['name' => 'second-transaction-robot']);
 *
 * $transaction1->rollback();
 * $transaction2->rollback();
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, find) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters = NULL, *params = NULL, *query = NULL, *resultset = NULL, *hydration = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/mvc/model.zep", 880);
		}
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_CALL_STATIC(&query, "getpreparedquery", &_0, 331, params);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&resultset, query, "execute", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(resultset) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(hydration);
		if (zephir_array_isset_string_fetch(&hydration, params, SS("hydration"), 0 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, resultset, "sethydratemode", NULL, 0, hydration);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(resultset);

}

/**
 * Query the first record that matches the specified conditions
 *
 * <code>
 * // What's the first robot in robots table?
 * $robot = Robots::findFirst();
 *
 * echo "The robot name is ", $robot->name;
 *
 * // What's the first mechanical robot in robots table?
 * $robot = Robots::findFirst(
 *	 "type = 'mechanical'"
 * );
 *
 * echo "The first mechanical robot name is ", $robot->name;
 *
 * // Get first virtual robot ordered by name
 * $robot = Robots::findFirst(
 *     [
 *         "type = 'virtual'",
 *         "order" => "name",
 *     ]
 * );
 *
 * echo "The first virtual robot name is ", $robot->name;
 *
 * // behaviour with transaction
 * $myTransaction = new Transaction(\Phalcon\Di::getDefault());
 * $myTransaction->begin();
 * $newRobot = new Robot();
 * $newRobot->setTransaction($myTransaction);
 * $newRobot->save(['name' => 'test', 'type' => 'mechanical', 'year' => 1944]);
 *
 * $findsARobot = Robot::findFirst(['name' => 'test', Model::TRANSACTION_INDEX => $myTransaction]);
 * $doesNotFindARobot = Robot::findFirst(['name' => 'test']);
 *
 * var_dump($findARobot);
 * var_dump($doesNotFindARobot);
 *
 * $transaction->commit();
 * $doesFindTheRobotNow = Robot::findFirst(['name' => 'test']);
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, findFirst) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters = NULL, *params = NULL, *query = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/mvc/model.zep", 955);
		}
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_STATIC(&query, "getpreparedquery", &_0, 331, params, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_METHOD(NULL, query, "setuniquerow", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(query, "execute", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * shared prepare query logic for find and findFirst method
 */
PHP_METHOD(Phalcon_Mvc_Model, getPreparedQuery) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *params, *limit = NULL, *builder = NULL, *bindParams = NULL, *bindTypes = NULL, *transaction = NULL, *cache = NULL, *manager = NULL, *query = NULL, *dependencyInjector = NULL, *_1 = NULL, *_2 = NULL, *_3$$5, *_4$$7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &params, &limit);

	if (!limit) {
		limit = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "modelsManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(manager, _1);
	ZEPHIR_CALL_METHOD(&builder, manager, "createbuilder", NULL, 0, params);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	zephir_get_called_class(_2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, builder, "from", NULL, 0, _2);
	zephir_check_call_status();
	if (Z_TYPE_P(limit) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, builder, "limit", NULL, 0, limit);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&query, builder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, params, SS("bind"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(bindParams) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_3$$5);
			ZVAL_BOOL(_3$$5, 1);
			ZEPHIR_CALL_METHOD(NULL, query, "setbindparams", NULL, 0, bindParams, _3$$5);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(bindTypes);
		if (zephir_array_isset_string_fetch(&bindTypes, params, SS("bindTypes"), 0 TSRMLS_CC)) {
			if (Z_TYPE_P(bindTypes) == IS_ARRAY) {
				ZEPHIR_INIT_VAR(_4$$7);
				ZVAL_BOOL(_4$$7, 1);
				ZEPHIR_CALL_METHOD(NULL, query, "setbindtypes", NULL, 0, bindTypes, _4$$7);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_OBS_VAR(transaction);
	if (zephir_array_isset_string_fetch(&transaction, params, SS("transaction"), 0 TSRMLS_CC)) {
		if (zephir_instance_of_ev(transaction, phalcon_mvc_model_transactioninterface_ce TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, query, "settransaction", NULL, 0, transaction);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(cache);
	if (zephir_array_isset_string_fetch(&cache, params, SS("cache"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, query, "cache", NULL, 0, cache);
		zephir_check_call_status();
	}
	RETURN_CCTOR(query);

}

/**
 * Create a criteria for a specific model
 */
PHP_METHOD(Phalcon_Mvc_Model, query) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *dependencyInjector = NULL, *criteria = NULL, *_3, *_1$$4 = NULL, *_2$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		ZEPHIR_CPY_WRT(dependencyInjector, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(dependencyInjector);
	}


	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(criteria);
	if (zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "Phalcon\\Mvc\\Model\\Criteria", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1$$4, dependencyInjector, "get", NULL, 0, _2$$4);
		zephir_check_temp_parameter(_2$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(criteria, _1$$4);
	} else {
		object_init_ex(criteria, phalcon_mvc_model_criteria_ce);
		if (zephir_has_constructor(criteria TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, criteria, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, criteria, "setdi", NULL, 332, dependencyInjector);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_3);
	zephir_get_called_class(_3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, criteria, "setmodelname", NULL, 333, _3);
	zephir_check_call_status();
	RETURN_CCTOR(criteria);

}

/**
 * Checks whether the current record already exists
 *
 * @param \Phalcon\Mvc\Model\MetaDataInterface metaData
 * @param \Phalcon\Db\AdapterInterface connection
 * @param string|array table
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _exists) {

	zend_bool _6$$11;
	HashTable *_1$$3;
	HashPosition _0$$3;
	zephir_fcall_cache_entry *_5 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberEmpty = 0, numberPrimary = 0;
	zval *metaData, *connection, *table = NULL, *uniqueParams = NULL, *uniqueTypes = NULL, *uniqueKey = NULL, *columnMap = NULL, *primaryKeys = NULL, *wherePk = NULL, *field = NULL, *attributeField = NULL, *value = NULL, *bindDataTypes = NULL, *joinWhere = NULL, *num = NULL, *type = NULL, *schema = NULL, *source = NULL, *_12, *_13 = NULL, *_14, *_15, *_16, **_2$$3, *_3$$9 = NULL, *_4$$9 = NULL, *_7$$14 = NULL, *_8$$14 = NULL, *_9$$7 = NULL, *_11$$7 = NULL, *_17$$22, *_18$$23;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &metaData, &connection, &table);

	if (!table) {
		ZEPHIR_CPY_WRT(table, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(table);
	}


	ZEPHIR_INIT_VAR(uniqueParams);
	ZVAL_NULL(uniqueParams);
	ZEPHIR_INIT_VAR(uniqueTypes);
	ZVAL_NULL(uniqueTypes);
	ZEPHIR_OBS_VAR(uniqueKey);
	zephir_read_property_this(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	if (Z_TYPE_P(uniqueKey) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, 0, this_ptr);
		zephir_check_call_status();
		numberPrimary = zephir_fast_count_int(primaryKeys TSRMLS_CC);
		if (!(numberPrimary)) {
			RETURN_MM_BOOL(0);
		}
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(columnMap);
			ZVAL_NULL(columnMap);
		}
		numberEmpty = 0;
		ZEPHIR_INIT_VAR(wherePk);
		array_init(wherePk);
		ZEPHIR_INIT_NVAR(uniqueParams);
		array_init(uniqueParams);
		ZEPHIR_INIT_NVAR(uniqueTypes);
		array_init(uniqueTypes);
		zephir_is_iterable(primaryKeys, &_1$$3, &_0$$3, 0, 0, "phalcon/mvc/model.zep", 1144);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(field, _2$$3);
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_3$$9);
					object_init_ex(_3$$9, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4$$9);
					ZEPHIR_CONCAT_SVS(_4$$9, "Column '", field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _3$$9, "__construct", &_5, 9, _4$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(_3$$9, "phalcon/mvc/model.zep", 1108 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, field);
			}
			ZEPHIR_INIT_NVAR(value);
			ZVAL_NULL(value);
			ZEPHIR_OBS_NVAR(value);
			if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
				_6$$11 = Z_TYPE_P(value) == IS_NULL;
				if (!(_6$$11)) {
					_6$$11 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
				}
				if (_6$$11) {
					numberEmpty++;
				}
				zephir_array_append(&uniqueParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 1126);
			} else {
				zephir_array_append(&uniqueParams, ZEPHIR_GLOBAL(global_null), PH_SEPARATE, "phalcon/mvc/model.zep", 1129);
				numberEmpty++;
			}
			ZEPHIR_OBS_NVAR(type);
			if (!(zephir_array_isset_fetch(&type, bindDataTypes, field, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_7$$14);
				object_init_ex(_7$$14, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_8$$14);
				ZEPHIR_CONCAT_SVS(_8$$14, "Column '", field, "' isn't part of the table columns");
				ZEPHIR_CALL_METHOD(NULL, _7$$14, "__construct", &_5, 9, _8$$14);
				zephir_check_call_status();
				zephir_throw_exception_debug(_7$$14, "phalcon/mvc/model.zep", 1134 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&uniqueTypes, type, PH_SEPARATE, "phalcon/mvc/model.zep", 1137);
			ZEPHIR_CALL_METHOD(&_9$$7, connection, "escapeidentifier", &_10, 0, field);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_11$$7);
			ZEPHIR_CONCAT_VS(_11$$7, _9$$7, " = ?");
			zephir_array_append(&wherePk, _11$$7, PH_SEPARATE, "phalcon/mvc/model.zep", 1138);
		}
		if (numberPrimary == numberEmpty) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(joinWhere);
		zephir_fast_join_str(joinWhere, SL(" AND "), wherePk TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_uniqueKey"), joinWhere TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_uniqueParams"), uniqueParams TSRMLS_CC);
		zephir_update_property_this(getThis(), SL("_uniqueTypes"), uniqueTypes TSRMLS_CC);
		ZEPHIR_CPY_WRT(uniqueKey, joinWhere);
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("_dirtyState"), PH_NOISY_CC);
	if (!(zephir_is_true(_12))) {
		RETURN_MM_BOOL(1);
	}
	if (Z_TYPE_P(uniqueKey) == IS_NULL) {
		ZEPHIR_OBS_NVAR(uniqueKey);
		zephir_read_property_this(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(uniqueParams) == IS_NULL) {
		ZEPHIR_OBS_NVAR(uniqueParams);
		zephir_read_property_this(&uniqueParams, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(uniqueTypes) == IS_NULL) {
		ZEPHIR_OBS_NVAR(uniqueTypes);
		zephir_read_property_this(&uniqueTypes, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC);
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_NVAR(table);
		zephir_create_array(table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(table, schema);
		zephir_array_fast_append(table, source);
	} else {
		ZEPHIR_CPY_WRT(table, source);
	}
	ZEPHIR_CALL_METHOD(&_13, connection, "escapeidentifier", NULL, 0, table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_CONCAT_SVSV(_14, "SELECT COUNT(*) \"rowcount\" FROM ", _13, " WHERE ", uniqueKey);
	ZEPHIR_INIT_VAR(_15);
	ZVAL_NULL(_15);
	ZEPHIR_CALL_METHOD(&num, connection, "fetchone", NULL, 0, _14, _15, uniqueParams, uniqueTypes);
	zephir_check_call_status();
	zephir_array_fetch_string(&_16, num, SL("rowcount"), PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1194 TSRMLS_CC);
	if (zephir_is_true(_16)) {
		ZEPHIR_INIT_ZVAL_NREF(_17$$22);
		ZVAL_LONG(_17$$22, 0);
		zephir_update_property_this(getThis(), SL("_dirtyState"), _17$$22 TSRMLS_CC);
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_18$$23);
		ZVAL_LONG(_18$$23, 1);
		zephir_update_property_this(getThis(), SL("_dirtyState"), _18$$23 TSRMLS_CC);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Generate a PHQL SELECT statement for an aggregate
 *
 * @param string function
 * @param string alias
 * @param array parameters
 * @return \Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, _groupResult) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *functionName_param = NULL, *alias_param = NULL, *parameters, *params = NULL, *distinctColumn = NULL, *groupColumn = NULL, *columns = NULL, *bindParams = NULL, *bindTypes = NULL, *resultset = NULL, *cache = NULL, *firstRow = NULL, *groupColumns = NULL, *builder = NULL, *query = NULL, *dependencyInjector = NULL, *manager = NULL, *_1 = NULL, *_2 = NULL, *_3;
	zval *functionName = NULL, *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &functionName_param, &alias_param, &parameters);

	if (UNEXPECTED(Z_TYPE_P(functionName_param) != IS_STRING && Z_TYPE_P(functionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'functionName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(functionName_param) == IS_STRING)) {
		zephir_get_strval(functionName, functionName_param);
	} else {
		ZEPHIR_INIT_VAR(functionName);
		ZVAL_EMPTY_STRING(functionName);
	}
	if (UNEXPECTED(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_EMPTY_STRING(alias);
	}


	ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "modelsManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(manager, _1);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/mvc/model.zep", 1224);
		}
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_OBS_VAR(groupColumn);
	if (!(zephir_array_isset_string_fetch(&groupColumn, params, SS("column"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(groupColumn);
		ZVAL_STRING(groupColumn, "*", 1);
	}
	ZEPHIR_OBS_VAR(distinctColumn);
	if (zephir_array_isset_string_fetch(&distinctColumn, params, SS("distinct"), 0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(columns);
		ZEPHIR_CONCAT_VSVSV(columns, functionName, "(DISTINCT ", distinctColumn, ") AS ", alias);
	} else {
		ZEPHIR_OBS_VAR(groupColumns);
		ZEPHIR_INIT_NVAR(columns);
		if (zephir_array_isset_string_fetch(&groupColumns, params, SS("group"), 0 TSRMLS_CC)) {
			ZEPHIR_CONCAT_VSVSVSV(columns, groupColumns, ", ", functionName, "(", groupColumn, ") AS ", alias);
		} else {
			ZEPHIR_CONCAT_VSVSV(columns, functionName, "(", groupColumn, ") AS ", alias);
		}
	}
	ZEPHIR_CALL_METHOD(&builder, manager, "createbuilder", NULL, 0, params);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, builder, "columns", NULL, 0, columns);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	zephir_get_called_class(_2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, builder, "from", NULL, 0, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, builder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(bindParams);
	ZVAL_NULL(bindParams);
	ZEPHIR_INIT_VAR(bindTypes);
	ZVAL_NULL(bindTypes);
	ZEPHIR_OBS_NVAR(bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, params, SS("bind"), 0 TSRMLS_CC)) {
		ZEPHIR_OBS_NVAR(bindTypes);
		zephir_array_isset_string_fetch(&bindTypes, params, SS("bindTypes"), 0 TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(cache);
	if (zephir_array_isset_string_fetch(&cache, params, SS("cache"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, query, "cache", NULL, 0, cache);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&resultset, query, "execute", NULL, 0, bindParams, bindTypes);
	zephir_check_call_status();
	if (zephir_array_isset_string(params, SS("group"))) {
		RETURN_CCTOR(resultset);
	}
	ZEPHIR_CALL_METHOD(&firstRow, resultset, "getfirst", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_zval(&_3, firstRow, alias, PH_NOISY_CC);
	RETURN_CCTOR(_3);

}

/**
 * Counts how many records match the specified conditions
 *
 * <code>
 * // How many robots are there?
 * $number = Robots::count();
 *
 * echo "There are ", $number, "\n";
 *
 * // How many mechanical robots are there?
 * $number = Robots::count("type = 'mechanical'");
 *
 * echo "There are ", $number, " mechanical robots\n";
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, count) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, *result = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "COUNT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "rowcount", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_SELF(&result, "_groupresult", NULL, 0, _0, _1, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (Z_TYPE_P(result) == IS_STRING) {
		RETURN_MM_LONG(zephir_get_intval(result));
	}
	RETURN_CCTOR(result);

}

/**
 * Calculates the sum on a column for a result-set of rows that match the specified conditions
 *
 * <code>
 * // How much are all robots?
 * $sum = Robots::sum(
 *     [
 *         "column" => "price",
 *     ]
 * );
 *
 * echo "The total price of robots is ", $sum, "\n";
 *
 * // How much are mechanical robots?
 * $sum = Robots::sum(
 *     [
 *         "type = 'mechanical'",
 *         "column" => "price",
 *     ]
 * );
 *
 * echo "The total price of mechanical robots is  ", $sum, "\n";
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, sum) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "SUM", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "sumatory", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, 0, _0, _1, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the maximum value of a column for a result-set of rows that match the specified conditions
 *
 * <code>
 * // What is the maximum robot id?
 * $id = Robots::maximum(
 *     [
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The maximum robot id is: ", $id, "\n";
 *
 * // What is the maximum id of mechanical robots?
 * $sum = Robots::maximum(
 *     [
 *         "type = 'mechanical'",
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The maximum robot id of mechanical robots is ", $id, "\n";
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, maximum) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "MAX", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "maximum", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, 0, _0, _1, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the minimum value of a column for a result-set of rows that match the specified conditions
 *
 * <code>
 * // What is the minimum robot id?
 * $id = Robots::minimum(
 *     [
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The minimum robot id is: ", $id;
 *
 * // What is the minimum id of mechanical robots?
 * $sum = Robots::minimum(
 *     [
 *         "type = 'mechanical'",
 *         "column" => "id",
 *     ]
 * );
 *
 * echo "The minimum robot id of mechanical robots is ", $id;
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, minimum) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "MIN", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "minimum", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, 0, _0, _1, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the average value on a column for a result-set of rows matching the specified conditions
 *
 * <code>
 * // What's the average price of robots?
 * $average = Robots::average(
 *     [
 *         "column" => "price",
 *     ]
 * );
 *
 * echo "The average price is ", $average, "\n";
 *
 * // What's the average price of mechanical robots?
 * $average = Robots::average(
 *     [
 *         "type = 'mechanical'",
 *         "column" => "price",
 *     ]
 * );
 *
 * echo "The average price of mechanical robots is ", $average, "\n";
 * </code>
 *
 * @param array parameters
 * @return double
 */
PHP_METHOD(Phalcon_Mvc_Model, average) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "AVG", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "average", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, 0, _0, _1, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEvent) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, *_0;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

	if (UNEXPECTED(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_EMPTY_STRING(eventName);
	}


	if ((zephir_method_exists(this_ptr, eventName TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, eventName, NULL, 0);
		zephir_check_call_status();
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "notifyevent", NULL, 0, eventName, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 * This method stops if one of the callbacks/listeners returns boolean false
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEventCancel) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, *_0$$3 = NULL, *_1, *_2 = NULL;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

	if (UNEXPECTED(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_EMPTY_STRING(eventName);
	}


	if ((zephir_method_exists(this_ptr, eventName TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(&_0$$3, this_ptr, eventName, NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "notifyevent", NULL, 0, eventName, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Cancel the current operation
 */
PHP_METHOD(Phalcon_Mvc_Model, _cancelOperation) {

	zval *_0, *_1$$3, *_2$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_operationMade"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_0, 3)) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "notDeleted", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_2$$4);
		ZVAL_STRING(_2$$4, "notSaved", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _2$$4);
		zephir_check_temp_parameter(_2$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Appends a customized message on the validation process
 *
 * <code>
 * use Phalcon\Mvc\Model;
 * use Phalcon\Mvc\Model\Message as Message;
 *
 * class Robots extends Model
 * {
 *     public function beforeSave()
 *     {
 *         if ($this->name === "Peter") {
 *             $message = new Message(
 *                 "Sorry, but a robot cannot be named Peter"
 *             );
 *
 *             $this->appendMessage($message);
 *         }
 *     }
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, appendMessage) {

	zval *message;

	zephir_fetch_params(0, 1, 0, &message);



	zephir_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Executes validators on every validation call
 *
 *<code>
 * use Phalcon\Mvc\Model;
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\ExclusionIn;
 *
 * class Subscriptors extends Model
 * {
 *     public function validation()
 *     {
 *         $validator = new Validation();
 *
 *         $validator->add(
 *             "status",
 *             new ExclusionIn(
 *                 [
 *                     "domain" => [
 *                         "A",
 *                         "I",
 *                     ],
 *                 ]
 *             )
 *         );
 *
 *         return $this->validate($validator);
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, validate) {

	zend_object_iterator *_1;
	zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validator, *messages = NULL, *message = NULL, *_0, *_2$$4 = NULL, *_3$$4 = NULL, *_4$$4 = NULL, *_5$$4 = NULL, *_6$$4 = NULL, *_7$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &validator);



	ZEPHIR_INIT_VAR(_0);
	ZVAL_NULL(_0);
	ZEPHIR_CALL_METHOD(&messages, validator, "validate", NULL, 0, _0, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(messages) == IS_BOOL) {
		RETURN_CCTOR(messages);
	}
	_1 = zephir_get_iterator(messages TSRMLS_CC);
	_1->funcs->rewind(_1 TSRMLS_CC);
	for (;_1->funcs->valid(_1 TSRMLS_CC) == SUCCESS && !EG(exception); _1->funcs->move_forward(_1 TSRMLS_CC)) {
		{
			zval **ZEPHIR_TMP_ITERATOR_PTR;
			_1->funcs->get_current_data(_1, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
			ZEPHIR_CPY_WRT(message, (*ZEPHIR_TMP_ITERATOR_PTR));
		}
		ZEPHIR_INIT_NVAR(_2$$4);
		object_init_ex(_2$$4, phalcon_mvc_model_message_ce);
		ZEPHIR_CALL_METHOD(&_3$$4, message, "getmessage", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, message, "getfield", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$4, message, "gettype", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$4, message, "getcode", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_7$$4);
		ZVAL_NULL(_7$$4);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", &_8, 8, _3$$4, _4$$4, _5$$4, _7$$4, _6$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_9, 0, _2$$4);
		zephir_check_call_status();
	}
	_1->funcs->dtor(_1 TSRMLS_CC);
	RETURN_MM_BOOL(!(zephir_fast_count_int(messages TSRMLS_CC)));

}

/**
 * Check whether validation process has generated any messages
 *
 *<code>
 * use Phalcon\Mvc\Model;
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\ExclusionIn;
 *
 * class Subscriptors extends Model
 * {
 *     public function validation()
 *     {
 *         $validator = new Validation();
 *
 *         $validator->validate(
 *             "status",
 *             new ExclusionIn(
 *                 [
 *                     "domain" => [
 *                         "A",
 *                         "I",
 *                     ],
 *                 ]
 *             )
 *         );
 *
 *         return $this->validate($validator);
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, validationHasFailed) {

	zval *errorMessages = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(errorMessages);
	zephir_read_property_this(&errorMessages, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
	if (Z_TYPE_P(errorMessages) == IS_ARRAY) {
		RETURN_MM_BOOL(zephir_fast_count_int(errorMessages TSRMLS_CC) > 0);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns array of validation messages
 *
 *<code>
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * if ($robot->save() === false) {
 *     echo "Umh, We can't store robots right now ";
 *
 *     $messages = $robot->getMessages();
 *
 *     foreach ($messages as $message) {
 *         echo $message;
 *     }
 * } else {
 *     echo "Great, a new robot was saved successfully!";
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, getMessages) {

	HashTable *_3$$3;
	HashPosition _2$$3;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filter = NULL, *filtered = NULL, *message = NULL, *_1$$3, **_4$$3, *_5$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &filter);

	if (!filter) {
		filter = ZEPHIR_GLOBAL(global_null);
	}


	_0 = Z_TYPE_P(filter) == IS_STRING;
	if (_0) {
		_0 = !(ZEPHIR_IS_EMPTY(filter));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(filtered);
		array_init(filtered);
		_1$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_errorMessages"), PH_NOISY_CC);
		zephir_is_iterable(_1$$3, &_3$$3, &_2$$3, 0, 0, "phalcon/mvc/model.zep", 1664);
		for (
		  ; zend_hash_get_current_data_ex(_3$$3, (void**) &_4$$3, &_2$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_3$$3, &_2$$3)
		) {
			ZEPHIR_GET_HVALUE(message, _4$$3);
			ZEPHIR_CALL_METHOD(&_5$$4, message, "getfield", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EQUAL(_5$$4, filter)) {
				zephir_array_append(&filtered, message, PH_SEPARATE, "phalcon/mvc/model.zep", 1661);
			}
		}
		RETURN_CCTOR(filtered);
	}
	RETURN_MM_MEMBER(getThis(), "_errorMessages");

}

/**
 * Reads "belongs to" relations and check the virtual foreign keys when inserting or updating records
 * to verify that inserted/updated values are present in the related entity
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysRestrict) {

	zval *_15$$3 = NULL;
	HashTable *_2, *_8$$8;
	HashPosition _1, _7$$8;
	zend_bool error = 0, validateWithNulls = 0, _13$$3;
	zval *manager = NULL, *belongsTo = NULL, *foreignKey = NULL, *relation = NULL, *conditions = NULL, *position = NULL, *bindParams = NULL, *extraConditions = NULL, *message = NULL, *fields = NULL, *referencedFields = NULL, *field = NULL, *referencedModel = NULL, *value = NULL, *allowNulls = NULL, *_0, **_3, *_4$$6 = NULL, *_5$$3 = NULL, *_14$$3 = NULL, *_16$$3 = NULL, **_9$$8, *_10$$9, *_11$$9 = NULL, *_12$$11 = NULL, *_17$$19 = NULL, *_18$$17 = NULL, *_19$$17 = NULL, *_22$$22;
	zephir_fcall_cache_entry *_6 = NULL, *_20 = NULL, *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, action = 0, numberNull = 0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_CALL_METHOD(&belongsTo, manager, "getbelongsto", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	zephir_is_iterable(belongsTo, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 1809);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(relation, _3);
		validateWithNulls = 0;
		ZEPHIR_CALL_METHOD(&foreignKey, relation, "getforeignkey", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(foreignKey)) {
			continue;
		}
		action = 1;
		if (Z_TYPE_P(foreignKey) == IS_ARRAY) {
			if (zephir_array_isset_string(foreignKey, SS("action"))) {
				ZEPHIR_OBS_NVAR(_4$$6);
				zephir_array_fetch_string(&_4$$6, foreignKey, SL("action"), PH_NOISY, "phalcon/mvc/model.zep", 1711 TSRMLS_CC);
				action = zephir_get_intval(_4$$6);
			}
		}
		if (action != 1) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&_5$$3, relation, "getreferencedmodel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&referencedModel, manager, "load", &_6, 0, _5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(conditions);
		array_init(conditions);
		ZEPHIR_INIT_NVAR(bindParams);
		array_init(bindParams);
		numberNull = 0;
		ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(fields) == IS_ARRAY) {
			zephir_is_iterable(fields, &_8$$8, &_7$$8, 0, 0, "phalcon/mvc/model.zep", 1749);
			for (
			  ; zend_hash_get_current_data_ex(_8$$8, (void**) &_9$$8, &_7$$8) == SUCCESS
			  ; zend_hash_move_forward_ex(_8$$8, &_7$$8)
			) {
				ZEPHIR_GET_HMKEY(position, _8$$8, _7$$8);
				ZEPHIR_GET_HVALUE(field, _9$$8);
				ZEPHIR_OBS_NVAR(value);
				zephir_fetch_property_zval(&value, this_ptr, field, PH_SILENT_CC);
				zephir_array_fetch(&_10$$9, referencedFields, position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1742 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_11$$9);
				ZEPHIR_CONCAT_SVSV(_11$$9, "[", _10$$9, "] = ?", position);
				zephir_array_append(&conditions, _11$$9, PH_SEPARATE, "phalcon/mvc/model.zep", 1742);
				zephir_array_append(&bindParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 1743);
				if (Z_TYPE_P(value) == IS_NULL) {
					numberNull++;
				}
			}
			validateWithNulls = numberNull == zephir_fast_count_int(fields TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(value);
			zephir_fetch_property_zval(&value, this_ptr, fields, PH_SILENT_CC);
			ZEPHIR_INIT_LNVAR(_12$$11);
			ZEPHIR_CONCAT_SVS(_12$$11, "[", referencedFields, "] = ?0");
			zephir_array_append(&conditions, _12$$11, PH_SEPARATE, "phalcon/mvc/model.zep", 1754);
			zephir_array_append(&bindParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 1755);
			if (Z_TYPE_P(value) == IS_NULL) {
				validateWithNulls = 1;
			}
		}
		ZEPHIR_OBS_NVAR(extraConditions);
		if (zephir_array_isset_string_fetch(&extraConditions, foreignKey, SS("conditions"), 0 TSRMLS_CC)) {
			zephir_array_append(&conditions, extraConditions, PH_SEPARATE, "phalcon/mvc/model.zep", 1766);
		}
		if (validateWithNulls) {
			ZEPHIR_OBS_NVAR(allowNulls);
			if (zephir_array_isset_string_fetch(&allowNulls, foreignKey, SS("allowNulls"), 0 TSRMLS_CC)) {
				validateWithNulls = zephir_get_boolval(allowNulls);
			} else {
				validateWithNulls = 0;
			}
		}
		_13$$3 = !validateWithNulls;
		if (_13$$3) {
			ZEPHIR_INIT_NVAR(_15$$3);
			zephir_create_array(_15$$3, 2, 0 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_16$$3);
			zephir_fast_join_str(_16$$3, SL(" AND "), conditions TSRMLS_CC);
			zephir_array_fast_append(_15$$3, _16$$3);
			zephir_array_update_string(&_15$$3, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(&_14$$3, referencedModel, "count", NULL, 0, _15$$3);
			zephir_check_call_status();
			_13$$3 = !zephir_is_true(_14$$3);
		}
		if (_13$$3) {
			ZEPHIR_OBS_NVAR(message);
			if (!(zephir_array_isset_string_fetch(&message, foreignKey, SS("message"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(message);
				if (Z_TYPE_P(fields) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(_17$$19);
					zephir_fast_join_str(_17$$19, SL(", "), fields TSRMLS_CC);
					ZEPHIR_CONCAT_SVS(message, "Value of fields \"", _17$$19, "\" does not exist on referenced table");
				} else {
					ZEPHIR_CONCAT_SVS(message, "Value of field \"", fields, "\" does not exist on referenced table");
				}
			}
			ZEPHIR_INIT_NVAR(_18$$17);
			object_init_ex(_18$$17, phalcon_mvc_model_message_ce);
			ZEPHIR_INIT_NVAR(_19$$17);
			ZVAL_STRING(_19$$17, "ConstraintViolation", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _18$$17, "__construct", &_20, 8, message, fields, _19$$17);
			zephir_check_temp_parameter(_19$$17);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_21, 0, _18$$17);
			zephir_check_call_status();
			error = 1;
			break;
		}
	}
	if (error == 1) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_VAR(_22$$22);
			ZVAL_STRING(_22$$22, "onValidationFails", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _22$$22);
			zephir_check_temp_parameter(_22$$22);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (cascade) when deleting records
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseCascade) {

	zval *_13$$3 = NULL;
	HashTable *_2, *_8$$8;
	HashPosition _1, _7$$8;
	zval *manager = NULL, *relations = NULL, *relation = NULL, *foreignKey = NULL, *resultset = NULL, *conditions = NULL, *bindParams = NULL, *referencedModel = NULL, *referencedFields = NULL, *fields = NULL, *field = NULL, *position = NULL, *value = NULL, *extraConditions = NULL, *_0, **_3, *_4$$6 = NULL, *_5$$3 = NULL, *_14$$3 = NULL, *_15$$3 = NULL, **_9$$8, *_10$$9, *_11$$9 = NULL, *_12$$10 = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, action = 0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_CALL_METHOD(&relations, manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(relations, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 1922);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(relation, _3);
		ZEPHIR_CALL_METHOD(&foreignKey, relation, "getforeignkey", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(foreignKey)) {
			continue;
		}
		action = 0;
		if (Z_TYPE_P(foreignKey) == IS_ARRAY) {
			if (zephir_array_isset_string(foreignKey, SS("action"))) {
				ZEPHIR_OBS_NVAR(_4$$6);
				zephir_array_fetch_string(&_4$$6, foreignKey, SL("action"), PH_NOISY, "phalcon/mvc/model.zep", 1861 TSRMLS_CC);
				action = zephir_get_intval(_4$$6);
			}
		}
		if (action != 2) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&_5$$3, relation, "getreferencedmodel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&referencedModel, manager, "load", &_6, 0, _5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(conditions);
		array_init(conditions);
		ZEPHIR_INIT_NVAR(bindParams);
		array_init(bindParams);
		if (Z_TYPE_P(fields) == IS_ARRAY) {
			zephir_is_iterable(fields, &_8$$8, &_7$$8, 0, 0, "phalcon/mvc/model.zep", 1891);
			for (
			  ; zend_hash_get_current_data_ex(_8$$8, (void**) &_9$$8, &_7$$8) == SUCCESS
			  ; zend_hash_move_forward_ex(_8$$8, &_7$$8)
			) {
				ZEPHIR_GET_HMKEY(position, _8$$8, _7$$8);
				ZEPHIR_GET_HVALUE(field, _9$$8);
				ZEPHIR_OBS_NVAR(value);
				zephir_fetch_property_zval(&value, this_ptr, field, PH_SILENT_CC);
				zephir_array_fetch(&_10$$9, referencedFields, position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1888 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_11$$9);
				ZEPHIR_CONCAT_SVSV(_11$$9, "[", _10$$9, "] = ?", position);
				zephir_array_append(&conditions, _11$$9, PH_SEPARATE, "phalcon/mvc/model.zep", 1888);
				zephir_array_append(&bindParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 1889);
			}
		} else {
			ZEPHIR_OBS_NVAR(value);
			zephir_fetch_property_zval(&value, this_ptr, fields, PH_SILENT_CC);
			ZEPHIR_INIT_LNVAR(_12$$10);
			ZEPHIR_CONCAT_SVS(_12$$10, "[", referencedFields, "] = ?0");
			zephir_array_append(&conditions, _12$$10, PH_SEPARATE, "phalcon/mvc/model.zep", 1893);
			zephir_array_append(&bindParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 1894);
		}
		ZEPHIR_OBS_NVAR(extraConditions);
		if (zephir_array_isset_string_fetch(&extraConditions, foreignKey, SS("conditions"), 0 TSRMLS_CC)) {
			zephir_array_append(&conditions, extraConditions, PH_SEPARATE, "phalcon/mvc/model.zep", 1901);
		}
		ZEPHIR_INIT_NVAR(_13$$3);
		zephir_create_array(_13$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_14$$3);
		zephir_fast_join_str(_14$$3, SL(" AND "), conditions TSRMLS_CC);
		zephir_array_fast_append(_13$$3, _14$$3);
		zephir_array_update_string(&_13$$3, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&resultset, referencedModel, "find", NULL, 0, _13$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_15$$3, resultset, "delete", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_15$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (restrict) when deleting records
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseRestrict) {

	zval *_13$$3 = NULL;
	HashTable *_2, *_7$$8;
	HashPosition _1, _6$$8;
	zval *manager = NULL, *relations = NULL, *foreignKey = NULL, *relation = NULL, *relationClass = NULL, *referencedModel = NULL, *fields = NULL, *referencedFields = NULL, *conditions = NULL, *bindParams = NULL, *position = NULL, *field = NULL, *value = NULL, *extraConditions = NULL, *message = NULL, *_0, **_3, *_4$$6 = NULL, **_8$$8, *_9$$9, *_10$$9 = NULL, *_11$$10 = NULL, *_12$$3 = NULL, *_14$$3 = NULL, *_15$$12 = NULL, *_16$$12 = NULL, *_19$$15;
	zend_bool error = 0;
	zephir_fcall_cache_entry *_5 = NULL, *_17 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, action = 0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_CALL_METHOD(&relations, manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	error = 0;
	zephir_is_iterable(relations, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 2040);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(relation, _3);
		ZEPHIR_CALL_METHOD(&foreignKey, relation, "getforeignkey", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(foreignKey)) {
			continue;
		}
		action = 1;
		if (Z_TYPE_P(foreignKey) == IS_ARRAY) {
			if (zephir_array_isset_string(foreignKey, SS("action"))) {
				ZEPHIR_OBS_NVAR(_4$$6);
				zephir_array_fetch_string(&_4$$6, foreignKey, SL("action"), PH_NOISY, "phalcon/mvc/model.zep", 1968 TSRMLS_CC);
				action = zephir_get_intval(_4$$6);
			}
		}
		if (action != 1) {
			continue;
		}
		ZEPHIR_CALL_METHOD(&relationClass, relation, "getreferencedmodel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&referencedModel, manager, "load", &_5, 0, relationClass);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&fields, relation, "getfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(conditions);
		array_init(conditions);
		ZEPHIR_INIT_NVAR(bindParams);
		array_init(bindParams);
		if (Z_TYPE_P(fields) == IS_ARRAY) {
			zephir_is_iterable(fields, &_7$$8, &_6$$8, 0, 0, "phalcon/mvc/model.zep", 2002);
			for (
			  ; zend_hash_get_current_data_ex(_7$$8, (void**) &_8$$8, &_6$$8) == SUCCESS
			  ; zend_hash_move_forward_ex(_7$$8, &_6$$8)
			) {
				ZEPHIR_GET_HMKEY(position, _7$$8, _6$$8);
				ZEPHIR_GET_HVALUE(field, _8$$8);
				ZEPHIR_OBS_NVAR(value);
				zephir_fetch_property_zval(&value, this_ptr, field, PH_SILENT_CC);
				zephir_array_fetch(&_9$$9, referencedFields, position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1998 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_10$$9);
				ZEPHIR_CONCAT_SVSV(_10$$9, "[", _9$$9, "] = ?", position);
				zephir_array_append(&conditions, _10$$9, PH_SEPARATE, "phalcon/mvc/model.zep", 1998);
				zephir_array_append(&bindParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 1999);
			}
		} else {
			ZEPHIR_OBS_NVAR(value);
			zephir_fetch_property_zval(&value, this_ptr, fields, PH_SILENT_CC);
			ZEPHIR_INIT_LNVAR(_11$$10);
			ZEPHIR_CONCAT_SVS(_11$$10, "[", referencedFields, "] = ?0");
			zephir_array_append(&conditions, _11$$10, PH_SEPARATE, "phalcon/mvc/model.zep", 2004);
			zephir_array_append(&bindParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 2005);
		}
		ZEPHIR_OBS_NVAR(extraConditions);
		if (zephir_array_isset_string_fetch(&extraConditions, foreignKey, SS("conditions"), 0 TSRMLS_CC)) {
			zephir_array_append(&conditions, extraConditions, PH_SEPARATE, "phalcon/mvc/model.zep", 2012);
		}
		ZEPHIR_INIT_NVAR(_13$$3);
		zephir_create_array(_13$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_14$$3);
		zephir_fast_join_str(_14$$3, SL(" AND "), conditions TSRMLS_CC);
		zephir_array_fast_append(_13$$3, _14$$3);
		zephir_array_update_string(&_13$$3, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(&_12$$3, referencedModel, "count", NULL, 0, _13$$3);
		zephir_check_call_status();
		if (zephir_is_true(_12$$3)) {
			ZEPHIR_OBS_NVAR(message);
			if (!(zephir_array_isset_string_fetch(&message, foreignKey, SS("message"), 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(message);
				ZEPHIR_CONCAT_SV(message, "Record is referenced by model ", relationClass);
			}
			ZEPHIR_INIT_NVAR(_15$$12);
			object_init_ex(_15$$12, phalcon_mvc_model_message_ce);
			ZEPHIR_INIT_NVAR(_16$$12);
			ZVAL_STRING(_16$$12, "ConstraintViolation", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _15$$12, "__construct", &_17, 8, message, fields, _16$$12);
			zephir_check_temp_parameter(_16$$12);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_18, 0, _15$$12);
			zephir_check_call_status();
			error = 1;
			break;
		}
	}
	if (error == 1) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_VAR(_19$$15);
			ZVAL_STRING(_19$$15, "onValidationFails", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _19$$15);
			zephir_check_temp_parameter(_19$$15);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Executes internal hooks before save a record
 */
PHP_METHOD(Phalcon_Mvc_Model, _preSave) {

	HashTable *_8$$12;
	HashPosition _7$$12;
	zephir_fcall_cache_entry *_12 = NULL, *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool exists, error = 0, isNull = 0, _13$$27, _14$$27, _15$$27;
	zval *metaData, *exists_param = NULL, *identityField, *notNull = NULL, *columnMap = NULL, *dataTypeNumeric = NULL, *automaticAttributes = NULL, *defaultValues = NULL, *field = NULL, *attributeField = NULL, *value = NULL, *emptyStringValues = NULL, *_22 = NULL, *_23, *_0$$3 = NULL, *_1$$3, *_2$$5 = NULL, *_3$$5, *_4$$7 = NULL, *_5$$7, *_6$$9 = NULL, **_9$$12, *_10$$20 = NULL, *_11$$20 = NULL, *_16$$27, *_17$$32 = NULL, *_18$$32 = NULL, *_19$$32 = NULL, *_21$$37, *_24$$39, *_25$$41 = NULL, *_26$$41, *_27$$43 = NULL, *_28$$43, *_29$$40 = NULL, *_30$$40 = NULL, *_31$$40 = NULL, *_36$$40, *_32$$47 = NULL, *_33$$47, *_34$$49 = NULL, *_35$$49;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &metaData, &exists_param, &identityField);

	exists = zephir_get_boolval(exists_param);


	if (ZEPHIR_GLOBAL(orm).events) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_STRING(_1$$3, "beforeValidation", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "fireeventcancel", NULL, 0, _1$$3);
		zephir_check_temp_parameter(_1$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0$$3)) {
			RETURN_MM_BOOL(0);
		}
		if (!(exists)) {
			ZEPHIR_INIT_VAR(_3$$5);
			ZVAL_STRING(_3$$5, "beforeValidationOnCreate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_2$$5, this_ptr, "fireeventcancel", NULL, 0, _3$$5);
			zephir_check_temp_parameter(_3$$5);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_2$$5)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_VAR(_5$$7);
			ZVAL_STRING(_5$$7, "beforeValidationOnUpdate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_4$$7, this_ptr, "fireeventcancel", NULL, 0, _5$$7);
			zephir_check_temp_parameter(_5$$7);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_4$$7)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_6$$9, this_ptr, "_checkforeignkeysrestrict", NULL, 334);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_6$$9)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GLOBAL(orm).not_null_validations) {
		ZEPHIR_CALL_METHOD(&notNull, metaData, "getnotnullattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (Z_TYPE_P(notNull) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&dataTypeNumeric, metaData, "getdatatypesnumeric", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_GLOBAL(orm).column_renaming) {
				ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(columnMap);
				ZVAL_NULL(columnMap);
			}
			if (exists) {
				ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticupdateattributes", NULL, 0, this_ptr);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticcreateattributes", NULL, 0, this_ptr);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&defaultValues, metaData, "getdefaultvalues", NULL, 0, this_ptr);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&emptyStringValues, metaData, "getemptystringattributes", NULL, 0, this_ptr);
			zephir_check_call_status();
			error = 0;
			zephir_is_iterable(notNull, &_8$$12, &_7$$12, 0, 0, "phalcon/mvc/model.zep", 2207);
			for (
			  ; zend_hash_get_current_data_ex(_8$$12, (void**) &_9$$12, &_7$$12) == SUCCESS
			  ; zend_hash_move_forward_ex(_8$$12, &_7$$12)
			) {
				ZEPHIR_GET_HVALUE(field, _9$$12);
				if (!(zephir_array_isset(automaticAttributes, field))) {
					isNull = 0;
					if (Z_TYPE_P(columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(attributeField);
						if (!(zephir_array_isset_fetch(&attributeField, columnMap, field, 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(_10$$20);
							object_init_ex(_10$$20, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_11$$20);
							ZEPHIR_CONCAT_SVS(_11$$20, "Column '", field, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, _10$$20, "__construct", &_12, 9, _11$$20);
							zephir_check_call_status();
							zephir_throw_exception_debug(_10$$20, "phalcon/mvc/model.zep", 2142 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(attributeField, field);
					}
					ZEPHIR_OBS_NVAR(value);
					if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
						if (Z_TYPE_P(value) != IS_OBJECT) {
							if (!(zephir_array_isset(dataTypeNumeric, field))) {
								if (zephir_array_isset(emptyStringValues, field)) {
									if (Z_TYPE_P(value) == IS_NULL) {
										isNull = 1;
									}
								} else {
									_13$$27 = Z_TYPE_P(value) == IS_NULL;
									if (!(_13$$27)) {
										_14$$27 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
										if (_14$$27) {
											_15$$27 = !(zephir_array_isset(defaultValues, field));
											if (!(_15$$27)) {
												zephir_array_fetch(&_16$$27, defaultValues, field, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 2165 TSRMLS_CC);
												_15$$27 = !ZEPHIR_IS_IDENTICAL(value, _16$$27);
											}
											_14$$27 = _15$$27;
										}
										_13$$27 = _14$$27;
									}
									if (_13$$27) {
										isNull = 1;
									}
								}
							} else {
								if (!(zephir_is_numeric(value))) {
									isNull = 1;
								}
							}
						}
					} else {
						isNull = 1;
					}
					if (isNull == 1) {
						if (!(exists)) {
							if (ZEPHIR_IS_EQUAL(field, identityField)) {
								continue;
							}
							if (zephir_array_isset(defaultValues, field)) {
								continue;
							}
						}
						ZEPHIR_INIT_NVAR(_17$$32);
						object_init_ex(_17$$32, phalcon_mvc_model_message_ce);
						ZEPHIR_INIT_LNVAR(_18$$32);
						ZEPHIR_CONCAT_VS(_18$$32, attributeField, " is required");
						ZEPHIR_INIT_NVAR(_19$$32);
						ZVAL_STRING(_19$$32, "PresenceOf", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, _17$$32, "__construct", &_20, 8, _18$$32, attributeField, _19$$32);
						zephir_check_temp_parameter(_19$$32);
						zephir_check_call_status();
						zephir_update_property_array_append(this_ptr, SL("_errorMessages"), _17$$32 TSRMLS_CC);
						error = 1;
					}
				}
			}
			if (error == 1) {
				if (ZEPHIR_GLOBAL(orm).events) {
					ZEPHIR_INIT_VAR(_21$$37);
					ZVAL_STRING(_21$$37, "onValidationFails", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _21$$37);
					zephir_check_temp_parameter(_21$$37);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
					zephir_check_call_status();
				}
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_VAR(_23);
	ZVAL_STRING(_23, "validation", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_22, this_ptr, "fireeventcancel", NULL, 0, _23);
	zephir_check_temp_parameter(_23);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_22)) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_VAR(_24$$39);
			ZVAL_STRING(_24$$39, "onValidationFails", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _24$$39);
			zephir_check_temp_parameter(_24$$39);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (!(exists)) {
			ZEPHIR_INIT_VAR(_26$$41);
			ZVAL_STRING(_26$$41, "afterValidationOnCreate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_25$$41, this_ptr, "fireeventcancel", NULL, 0, _26$$41);
			zephir_check_temp_parameter(_26$$41);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_25$$41)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_VAR(_28$$43);
			ZVAL_STRING(_28$$43, "afterValidationOnUpdate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_27$$43, this_ptr, "fireeventcancel", NULL, 0, _28$$43);
			zephir_check_temp_parameter(_28$$43);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_27$$43)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_INIT_VAR(_30$$40);
		ZVAL_STRING(_30$$40, "afterValidation", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_29$$40, this_ptr, "fireeventcancel", NULL, 0, _30$$40);
		zephir_check_temp_parameter(_30$$40);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_29$$40)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_30$$40);
		ZVAL_STRING(_30$$40, "beforeSave", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_31$$40, this_ptr, "fireeventcancel", NULL, 0, _30$$40);
		zephir_check_temp_parameter(_30$$40);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_31$$40)) {
			RETURN_MM_BOOL(0);
		}
		if (0) {
			zephir_update_property_this(getThis(), SL("_skipped"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_skipped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		if (exists) {
			ZEPHIR_INIT_VAR(_33$$47);
			ZVAL_STRING(_33$$47, "beforeUpdate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_32$$47, this_ptr, "fireeventcancel", NULL, 0, _33$$47);
			zephir_check_temp_parameter(_33$$47);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_32$$47)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_VAR(_35$$49);
			ZVAL_STRING(_35$$49, "beforeCreate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_34$$49, this_ptr, "fireeventcancel", NULL, 0, _35$$49);
			zephir_check_temp_parameter(_35$$49);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_34$$49)) {
				RETURN_MM_BOOL(0);
			}
		}
		_36$$40 = zephir_fetch_nproperty_this(this_ptr, SL("_skipped"), PH_NOISY_CC);
		if (ZEPHIR_IS_TRUE_IDENTICAL(_36$$40)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Executes internal events after save a record
 */
PHP_METHOD(Phalcon_Mvc_Model, _postSave) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *success_param = NULL, *exists_param = NULL, *_0$$4, *_1$$5;
	zend_bool success, exists;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &success_param, &exists_param);

	success = zephir_get_boolval(success_param);
	exists = zephir_get_boolval(exists_param);


	if (success == 1) {
		if (exists) {
			ZEPHIR_INIT_VAR(_0$$4);
			ZVAL_STRING(_0$$4, "afterUpdate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _0$$4);
			zephir_check_temp_parameter(_0$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(_1$$5);
			ZVAL_STRING(_1$$5, "afterCreate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _1$$5);
			zephir_check_temp_parameter(_1$$5);
			zephir_check_call_status();
		}
	}
	RETURN_MM_BOOL(success);

}

/**
 * Sends a pre-build INSERT SQL statement to the relational database system
 *
 * @param \Phalcon\Mvc\Model\MetaDataInterface metaData
 * @param \Phalcon\Db\AdapterInterface connection
 * @param string|array table
 * @param boolean|string identityField
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowInsert) {

	HashTable *_2;
	HashPosition _1;
	zend_bool useExplicitIdentity = 0, _19, _21, _23, _7$$11, _16$$23;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, *connection, *table, *identityField, *bindSkip = NULL, *fields = NULL, *values = NULL, *bindTypes = NULL, *attributes = NULL, *bindDataTypes = NULL, *automaticAttributes = NULL, *field = NULL, *columnMap = NULL, *value = NULL, *attributeField = NULL, *success = NULL, *bindType = NULL, *defaultValue = NULL, *sequenceName = NULL, *defaultValues = NULL, *source = NULL, *schema = NULL, *snapshot = NULL, *lastInsertedId = NULL, *manager = NULL, *_0, **_3, *_22 = NULL, *_4$$8 = NULL, *_5$$8 = NULL, *_9$$14 = NULL, *_10$$14 = NULL, *_11$$16 = NULL, *_13$$18 = NULL, *_14$$21, *_15$$21, *_17$$28, *_18$$28, *_20$$31 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &metaData, &connection, &table, &identityField);



	ZEPHIR_INIT_VAR(bindSkip);
	ZVAL_LONG(bindSkip, 1024);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	ZEPHIR_INIT_VAR(values);
	array_init(values);
	ZEPHIR_INIT_VAR(snapshot);
	array_init(snapshot);
	ZEPHIR_INIT_VAR(bindTypes);
	array_init(bindTypes);
	ZEPHIR_CALL_METHOD(&attributes, metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticcreateattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&defaultValues, metaData, "getdefaultvalues", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(columnMap);
		ZVAL_NULL(columnMap);
	}
	zephir_is_iterable(attributes, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 2400);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(field, _3);
		if (!(zephir_array_isset(automaticAttributes, field))) {
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_4$$8);
					object_init_ex(_4$$8, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5$$8);
					ZEPHIR_CONCAT_SVS(_5$$8, "Column '", field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _4$$8, "__construct", &_6, 9, _5$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(_4$$8, "phalcon/mvc/model.zep", 2347 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, field);
			}
			if (!ZEPHIR_IS_EQUAL(field, identityField)) {
				ZEPHIR_OBS_NVAR(value);
				if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
					_7$$11 = Z_TYPE_P(value) == IS_NULL;
					if (_7$$11) {
						_7$$11 = zephir_array_isset(defaultValues, field);
					}
					if (_7$$11) {
						zephir_array_update_zval(&snapshot, attributeField, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(&value, connection, "getdefaultvalue", &_8, 0);
						zephir_check_call_status();
					} else {
						zephir_array_update_zval(&snapshot, attributeField, &value, PH_COPY | PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(bindType);
					if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, field, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(_9$$14);
						object_init_ex(_9$$14, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_10$$14);
						ZEPHIR_CONCAT_SVS(_10$$14, "Column '", field, "' have not defined a bind data type");
						ZEPHIR_CALL_METHOD(NULL, _9$$14, "__construct", &_6, 9, _10$$14);
						zephir_check_call_status();
						zephir_throw_exception_debug(_9$$14, "phalcon/mvc/model.zep", 2374 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&fields, field, PH_SEPARATE, "phalcon/mvc/model.zep", 2377);
					zephir_array_append(&values, value, PH_SEPARATE, "phalcon/mvc/model.zep", 2377);
					zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 2377);
				} else {
					if (zephir_array_isset(defaultValues, field)) {
						ZEPHIR_CALL_METHOD(&_11$$16, connection, "getdefaultvalue", &_12, 0);
						zephir_check_call_status();
						zephir_array_append(&values, _11$$16, PH_SEPARATE, "phalcon/mvc/model.zep", 2381);
						zephir_array_update_zval(&snapshot, attributeField, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_append(&values, value, PH_SEPARATE, "phalcon/mvc/model.zep", 2387);
						zephir_array_update_zval(&snapshot, attributeField, &value, PH_COPY | PH_SEPARATE);
					}
					zephir_array_append(&fields, field, PH_SEPARATE, "phalcon/mvc/model.zep", 2391);
					zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 2391);
				}
			}
		}
	}
	if (!ZEPHIR_IS_FALSE_IDENTICAL(identityField)) {
		ZEPHIR_CALL_METHOD(&defaultValue, connection, "getdefaultidvalue", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_13$$18, connection, "useexplicitidvalue", NULL, 0);
		zephir_check_call_status();
		useExplicitIdentity = zephir_get_boolval(_13$$18);
		if (useExplicitIdentity) {
			zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/mvc/model.zep", 2409);
		}
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, columnMap, identityField, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_14$$21);
				object_init_ex(_14$$21, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(_15$$21);
				ZEPHIR_CONCAT_SVS(_15$$21, "Identity column '", identityField, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _14$$21, "__construct", &_6, 9, _15$$21);
				zephir_check_call_status();
				zephir_throw_exception_debug(_14$$21, "phalcon/mvc/model.zep", 2417 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(attributeField, identityField);
		}
		ZEPHIR_OBS_NVAR(value);
		if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
			_16$$23 = Z_TYPE_P(value) == IS_NULL;
			if (!(_16$$23)) {
				_16$$23 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
			}
			if (_16$$23) {
				if (useExplicitIdentity) {
					zephir_array_append(&values, defaultValue, PH_SEPARATE, "phalcon/mvc/model.zep", 2430);
					zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 2430);
				}
			} else {
				if (!(useExplicitIdentity)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/mvc/model.zep", 2438);
				}
				ZEPHIR_OBS_NVAR(bindType);
				if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, identityField, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_VAR(_17$$28);
					object_init_ex(_17$$28, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_VAR(_18$$28);
					ZEPHIR_CONCAT_SVS(_18$$28, "Identity column '", identityField, "' isn\\'t part of the table columns");
					ZEPHIR_CALL_METHOD(NULL, _17$$28, "__construct", &_6, 9, _18$$28);
					zephir_check_call_status();
					zephir_throw_exception_debug(_17$$28, "phalcon/mvc/model.zep", 2445 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, value, PH_SEPARATE, "phalcon/mvc/model.zep", 2448);
				zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 2448);
			}
		} else {
			if (useExplicitIdentity) {
				zephir_array_append(&values, defaultValue, PH_SEPARATE, "phalcon/mvc/model.zep", 2452);
				zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 2452);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&success, connection, "insert", NULL, 0, table, values, fields, bindTypes);
	zephir_check_call_status();
	_19 = zephir_is_true(success);
	if (_19) {
		_19 = !ZEPHIR_IS_FALSE_IDENTICAL(identityField);
	}
	if (_19) {
		ZEPHIR_INIT_VAR(sequenceName);
		ZVAL_NULL(sequenceName);
		ZEPHIR_CALL_METHOD(&_20$$31, connection, "supportsequences", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(_20$$31)) {
			if ((zephir_method_exists_ex(this_ptr, SS("getsequencename") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&sequenceName, this_ptr, "getsequencename", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(sequenceName);
				if (ZEPHIR_IS_EMPTY(schema)) {
					ZEPHIR_CONCAT_VSVS(sequenceName, source, "_", identityField, "_seq");
				} else {
					ZEPHIR_CONCAT_VSVSVS(sequenceName, schema, ".", source, "_", identityField, "_seq");
				}
			}
		}
		ZEPHIR_CALL_METHOD(&lastInsertedId, connection, "lastinsertid", NULL, 0, sequenceName);
		zephir_check_call_status();
		zephir_update_property_zval_zval(getThis(), attributeField, lastInsertedId TSRMLS_CC);
		zephir_array_update_zval(&snapshot, attributeField, &lastInsertedId, PH_COPY | PH_SEPARATE);
		zephir_update_property_this(getThis(), SL("_uniqueParams"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	}
	_21 = zephir_is_true(success);
	if (_21) {
		ZEPHIR_CALL_METHOD(&_22, manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_21 = zephir_is_true(_22);
	}
	_23 = _21;
	if (_23) {
		_23 = ZEPHIR_GLOBAL(orm).update_snapshot_on_save;
	}
	if (_23) {
		zephir_update_property_this(getThis(), SL("_snapshot"), snapshot TSRMLS_CC);
	}
	RETURN_CCTOR(success);

}

/**
 * Sends a pre-build UPDATE SQL statement to the relational database system
 *
 * @param \Phalcon\Mvc\Model\MetaDataInterface metaData
 * @param \Phalcon\Db\AdapterInterface connection
 * @param string|array table
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowUpdate) {

	zval *_15$$25 = NULL, *_16$$25 = NULL;
	zval *_22;
	HashTable *_3, *_18$$31;
	HashPosition _2, _17$$31;
	zend_bool useDynamicUpdate = 0, changed = 0, _23, _24;
	zephir_fcall_cache_entry *_7 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, *connection, *table, *bindSkip = NULL, *fields = NULL, *values = NULL, *dataType = NULL, *dataTypes = NULL, *bindTypes = NULL, *manager = NULL, *bindDataTypes = NULL, *field = NULL, *automaticAttributes = NULL, *snapshotValue = NULL, *uniqueKey = NULL, *uniqueParams = NULL, *uniqueTypes = NULL, *snapshot = NULL, *nonPrimary = NULL, *columnMap = NULL, *attributeField = NULL, *value = NULL, *primaryKeys = NULL, *bindType = NULL, *newSnapshot = NULL, *success = NULL, *_0, *_1 = NULL, **_4, *_5$$9 = NULL, *_6$$9 = NULL, *_8$$11 = NULL, *_9$$11 = NULL, *_10$$22 = NULL, *_11$$22 = NULL, *_12$$24 = NULL, *_14$$24 = NULL, **_19$$31, *_20$$35 = NULL, *_21$$35 = NULL, *_25$$40, *_26$$41;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &metaData, &connection, &table);



	ZEPHIR_INIT_VAR(bindSkip);
	ZVAL_LONG(bindSkip, 1024);
	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	ZEPHIR_INIT_VAR(values);
	array_init(values);
	ZEPHIR_INIT_VAR(bindTypes);
	array_init(bindTypes);
	ZEPHIR_INIT_VAR(newSnapshot);
	array_init(newSnapshot);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_CALL_METHOD(&_1, manager, "isusingdynamicupdate", NULL, 0, this_ptr);
	zephir_check_call_status();
	useDynamicUpdate = zephir_get_boolval(_1);
	ZEPHIR_OBS_VAR(snapshot);
	zephir_read_property_this(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
	if (useDynamicUpdate) {
		if (Z_TYPE_P(snapshot) != IS_ARRAY) {
			useDynamicUpdate = 0;
		}
	}
	ZEPHIR_CALL_METHOD(&dataTypes, metaData, "getdatatypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&nonPrimary, metaData, "getnonprimarykeyattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticupdateattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(columnMap);
		ZVAL_NULL(columnMap);
	}
	zephir_is_iterable(nonPrimary, &_3, &_2, 0, 0, "phalcon/mvc/model.zep", 2668);
	for (
	  ; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zend_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(field, _4);
		if (!(zephir_array_isset(automaticAttributes, field))) {
			ZEPHIR_OBS_NVAR(bindType);
			if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, field, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_5$$9);
				object_init_ex(_5$$9, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_6$$9);
				ZEPHIR_CONCAT_SVS(_6$$9, "Column '", field, "' have not defined a bind data type");
				ZEPHIR_CALL_METHOD(NULL, _5$$9, "__construct", &_7, 9, _6$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(_5$$9, "phalcon/mvc/model.zep", 2563 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_8$$11);
					object_init_ex(_8$$11, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_9$$11);
					ZEPHIR_CONCAT_SVS(_9$$11, "Column '", field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _8$$11, "__construct", &_7, 9, _9$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(_8$$11, "phalcon/mvc/model.zep", 2571 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, field);
			}
			ZEPHIR_OBS_NVAR(value);
			if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
				if (!(useDynamicUpdate)) {
					zephir_array_append(&fields, field, PH_SEPARATE, "phalcon/mvc/model.zep", 2587);
					zephir_array_append(&values, value, PH_SEPARATE, "phalcon/mvc/model.zep", 2587);
					zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 2588);
				} else {
					ZEPHIR_OBS_NVAR(snapshotValue);
					if (!(zephir_array_isset_fetch(&snapshotValue, snapshot, attributeField, 0 TSRMLS_CC))) {
						changed = 1;
					} else {
						if (Z_TYPE_P(value) == IS_NULL) {
							changed = Z_TYPE_P(snapshotValue) != IS_NULL;
						} else {
							if (Z_TYPE_P(snapshotValue) == IS_NULL) {
								changed = 1;
							} else {
								ZEPHIR_OBS_NVAR(dataType);
								if (!(zephir_array_isset_fetch(&dataType, dataTypes, field, 0 TSRMLS_CC))) {
									ZEPHIR_INIT_NVAR(_10$$22);
									object_init_ex(_10$$22, phalcon_mvc_model_exception_ce);
									ZEPHIR_INIT_LNVAR(_11$$22);
									ZEPHIR_CONCAT_SVS(_11$$22, "Column '", field, "' have not defined a data type");
									ZEPHIR_CALL_METHOD(NULL, _10$$22, "__construct", &_7, 9, _11$$22);
									zephir_check_call_status();
									zephir_throw_exception_debug(_10$$22, "phalcon/mvc/model.zep", 2613 TSRMLS_CC);
									ZEPHIR_MM_RESTORE();
									return;
								}
								do {
									if (ZEPHIR_IS_LONG(dataType, 8)) {
										changed = zephir_get_boolval(snapshotValue) != zephir_get_boolval(value);
										break;
									}
									if (ZEPHIR_IS_LONG(dataType, 3) || ZEPHIR_IS_LONG(dataType, 7)) {
										ZEPHIR_CALL_FUNCTION(&_12$$24, "floatval", &_13, 335, snapshotValue);
										zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_14$$24, "floatval", &_13, 335, value);
										zephir_check_call_status();
										changed = !ZEPHIR_IS_IDENTICAL(_12$$24, _14$$24);
										break;
									}
									if (ZEPHIR_IS_LONG(dataType, 0) || ZEPHIR_IS_LONG(dataType, 1) || ZEPHIR_IS_LONG(dataType, 2) || ZEPHIR_IS_LONG(dataType, 4) || ZEPHIR_IS_LONG(dataType, 5) || ZEPHIR_IS_LONG(dataType, 6) || ZEPHIR_IS_LONG(dataType, 2) || ZEPHIR_IS_LONG(dataType, 14)) {
										zephir_get_strval(_15$$25, snapshotValue);
										zephir_get_strval(_16$$25, value);
										changed = !ZEPHIR_IS_IDENTICAL(_15$$25, _16$$25);
										break;
									}
									changed = !ZEPHIR_IS_EQUAL(value, snapshotValue);
								} while(0);

							}
						}
					}
					if (changed) {
						zephir_array_append(&fields, field, PH_SEPARATE, "phalcon/mvc/model.zep", 2652);
						zephir_array_append(&values, value, PH_SEPARATE, "phalcon/mvc/model.zep", 2652);
						zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 2653);
					}
				}
				zephir_array_update_zval(&newSnapshot, attributeField, &value, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&newSnapshot, attributeField, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
				zephir_array_append(&fields, field, PH_SEPARATE, "phalcon/mvc/model.zep", 2660);
				zephir_array_append(&values, ZEPHIR_GLOBAL(global_null), PH_SEPARATE, "phalcon/mvc/model.zep", 2660);
				zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 2660);
			}
		}
	}
	if (!(zephir_fast_count_int(fields TSRMLS_CC))) {
		if (useDynamicUpdate) {
			zephir_update_property_this(getThis(), SL("_oldSnapshot"), snapshot TSRMLS_CC);
		}
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_OBS_VAR(uniqueKey);
	zephir_read_property_this(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(uniqueParams);
	zephir_read_property_this(&uniqueParams, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(uniqueTypes);
	zephir_read_property_this(&uniqueTypes, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC);
	if (Z_TYPE_P(uniqueParams) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (!(zephir_fast_count_int(primaryKeys TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation", "phalcon/mvc/model.zep", 2690);
			return;
		}
		ZEPHIR_INIT_NVAR(uniqueParams);
		array_init(uniqueParams);
		zephir_is_iterable(primaryKeys, &_18$$31, &_17$$31, 0, 0, "phalcon/mvc/model.zep", 2715);
		for (
		  ; zend_hash_get_current_data_ex(_18$$31, (void**) &_19$$31, &_17$$31) == SUCCESS
		  ; zend_hash_move_forward_ex(_18$$31, &_17$$31)
		) {
			ZEPHIR_GET_HVALUE(field, _19$$31);
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_20$$35);
					object_init_ex(_20$$35, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_21$$35);
					ZEPHIR_CONCAT_SVS(_21$$35, "Column '", field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _20$$35, "__construct", &_7, 9, _21$$35);
					zephir_check_call_status();
					zephir_throw_exception_debug(_20$$35, "phalcon/mvc/model.zep", 2701 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, field);
			}
			ZEPHIR_OBS_NVAR(value);
			if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
				zephir_array_update_zval(&newSnapshot, attributeField, &value, PH_COPY | PH_SEPARATE);
				zephir_array_append(&uniqueParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 2709);
			} else {
				zephir_array_update_zval(&newSnapshot, attributeField, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
				zephir_array_append(&uniqueParams, ZEPHIR_GLOBAL(global_null), PH_SEPARATE, "phalcon/mvc/model.zep", 2712);
			}
		}
	}
	ZEPHIR_INIT_VAR(_22);
	zephir_create_array(_22, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_22, SL("conditions"), &uniqueKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_22, SL("bind"), &uniqueParams, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_22, SL("bindTypes"), &uniqueTypes, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&success, connection, "update", NULL, 0, table, fields, values, _22, bindTypes);
	zephir_check_call_status();
	_23 = zephir_is_true(success);
	if (_23) {
		ZEPHIR_CALL_METHOD(&_1, manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		_23 = zephir_is_true(_1);
	}
	_24 = _23;
	if (_24) {
		_24 = ZEPHIR_GLOBAL(orm).update_snapshot_on_save;
	}
	if (_24) {
		if (Z_TYPE_P(snapshot) == IS_ARRAY) {
			zephir_update_property_this(getThis(), SL("_oldSnapshot"), snapshot TSRMLS_CC);
			ZEPHIR_INIT_VAR(_25$$40);
			zephir_fast_array_merge(_25$$40, &(snapshot), &(newSnapshot) TSRMLS_CC);
			zephir_update_property_this(getThis(), SL("_snapshot"), _25$$40 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(_26$$41);
			array_init(_26$$41);
			zephir_update_property_this(getThis(), SL("_oldSnapshot"), _26$$41 TSRMLS_CC);
			zephir_update_property_this(getThis(), SL("_snapshot"), newSnapshot TSRMLS_CC);
		}
	}
	RETURN_CCTOR(success);

}

/**
 * Saves related records that must be stored prior to save the master record
 *
 * @param \Phalcon\Db\AdapterInterface connection
 * @param \Phalcon\Mvc\ModelInterface[] related
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _preSaveRelatedRecords) {

	HashTable *_3, *_14$$8;
	HashPosition _2, _13$$8;
	zend_bool nesting = 0;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_10 = NULL, *_16 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, *related, *className = NULL, *manager = NULL, *type = NULL, *relation = NULL, *columns = NULL, *referencedFields = NULL, *referencedModel = NULL, *message = NULL, *name = NULL, *record = NULL, *_0, *_1 = NULL, **_4, *_5$$3 = NULL, *_7$$6 = NULL, *_9$$7 = NULL, *_11$$5 = NULL, *_19$$5 = NULL, *_12$$8 = NULL, **_15$$8, *_17$$8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &related);



	nesting = 0;
	ZEPHIR_INIT_VAR(_0);
	if (nesting) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(manager, _1);
	zephir_is_iterable(related, &_3, &_2, 0, 0, "phalcon/mvc/model.zep", 2833);
	for (
	  ; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zend_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(name, _3, _2);
		ZEPHIR_GET_HVALUE(record, _4);
		ZEPHIR_CALL_METHOD(&_5$$3, manager, "getrelationbyalias", &_6, 0, className, name);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(relation, _5$$3);
		if (Z_TYPE_P(relation) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&type, relation, "gettype", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(type, 0)) {
				if (Z_TYPE_P(record) != IS_OBJECT) {
					ZEPHIR_INIT_NVAR(_7$$6);
					if (nesting) {
						ZVAL_BOOL(_7$$6, 1);
					} else {
						ZVAL_BOOL(_7$$6, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_8, 0, _7$$6);
					zephir_check_call_status();
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects can be stored as part of belongs-to relations", "phalcon/mvc/model.zep", 2782);
					return;
				}
				ZEPHIR_CALL_METHOD(&columns, relation, "getfields", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(columns) == IS_ARRAY) {
					ZEPHIR_INIT_NVAR(_9$$7);
					if (nesting) {
						ZVAL_BOOL(_9$$7, 1);
					} else {
						ZVAL_BOOL(_9$$7, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_10, 0, _9$$7);
					zephir_check_call_status();
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/mvc/model.zep", 2791);
					return;
				}
				ZEPHIR_CALL_METHOD(&_11$$5, record, "save", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(_11$$5))) {
					ZEPHIR_CALL_METHOD(&_12$$8, record, "getmessages", NULL, 0);
					zephir_check_call_status();
					zephir_is_iterable(_12$$8, &_14$$8, &_13$$8, 0, 0, "phalcon/mvc/model.zep", 2820);
					for (
					  ; zend_hash_get_current_data_ex(_14$$8, (void**) &_15$$8, &_13$$8) == SUCCESS
					  ; zend_hash_move_forward_ex(_14$$8, &_13$$8)
					) {
						ZEPHIR_GET_HVALUE(message, _15$$8);
						if (Z_TYPE_P(message) == IS_OBJECT) {
							ZEPHIR_CALL_METHOD(NULL, message, "setmodel", NULL, 0, record);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_16, 0, message);
						zephir_check_call_status();
					}
					ZEPHIR_INIT_NVAR(_17$$8);
					if (nesting) {
						ZVAL_BOOL(_17$$8, 1);
					} else {
						ZVAL_BOOL(_17$$8, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_18, 0, _17$$8);
					zephir_check_call_status();
					RETURN_MM_BOOL(0);
				}
				ZEPHIR_CALL_METHOD(&_19$$5, record, "readattribute", NULL, 0, referencedFields);
				zephir_check_call_status();
				zephir_update_property_zval_zval(getThis(), columns, _19$$5 TSRMLS_CC);
			}
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Save the related records assigned in the has-one/has-many relations
 *
 * @param  Phalcon\Db\AdapterInterface connection
 * @param  Phalcon\Mvc\ModelInterface[] related
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _postSaveRelatedRecords) {

	HashTable *_2, *_19$$4, *_24$$14, *_34$$18;
	HashPosition _1, _18$$4, _23$$14, _33$$18;
	zend_bool nesting = 0, isThrough = 0, _7$$4;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL, *_11 = NULL, *_13 = NULL, *_16 = NULL, *_26 = NULL, *_28 = NULL, *_30 = NULL, *_37 = NULL, *_39 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, *related, *className = NULL, *manager = NULL, *relation = NULL, *name = NULL, *record = NULL, *message = NULL, *columns = NULL, *referencedModel = NULL, *referencedFields = NULL, *relatedRecords = NULL, *value = NULL, *recordAfter = NULL, *intermediateModel = NULL, *intermediateFields = NULL, *intermediateValue = NULL, *intermediateModelName = NULL, *intermediateReferencedFields = NULL, *_0 = NULL, **_3, *_42, *_4$$3 = NULL, *_6$$4 = NULL, *_17$$4 = NULL, **_20$$4, *_8$$6 = NULL, *_10$$7 = NULL, *_12$$10 = NULL, *_14$$10 = NULL, *_15$$10 = NULL, *_21$$12 = NULL, *_22$$14 = NULL, **_25$$14, *_27$$14 = NULL, *_29$$17 = NULL, *_31$$17 = NULL, *_32$$18 = NULL, **_35$$18, *_36$$18 = NULL, *_38$$22 = NULL, *_40$$22 = NULL, *_41$$22 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &related);



	nesting = 0;
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(manager, _0);
	zephir_is_iterable(related, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 3024);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(name, _2, _1);
		ZEPHIR_GET_HVALUE(record, _3);
		ZEPHIR_CALL_METHOD(&_4$$3, manager, "getrelationbyalias", &_5, 0, className, name);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(relation, _4$$3);
		if (Z_TYPE_P(relation) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_6$$4, relation, "gettype", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(_6$$4, 0)) {
				continue;
			}
			_7$$4 = Z_TYPE_P(record) != IS_OBJECT;
			if (_7$$4) {
				_7$$4 = Z_TYPE_P(record) != IS_ARRAY;
			}
			if (_7$$4) {
				ZEPHIR_INIT_NVAR(_8$$6);
				if (nesting) {
					ZVAL_BOOL(_8$$6, 1);
				} else {
					ZVAL_BOOL(_8$$6, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_9, 0, _8$$6);
				zephir_check_call_status();
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects/arrays can be stored as part of has-many/has-one/has-many-to-many relations", "phalcon/mvc/model.zep", 2872);
				return;
			}
			ZEPHIR_CALL_METHOD(&columns, relation, "getfields", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedModel, relation, "getreferencedmodel", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(columns) == IS_ARRAY) {
				ZEPHIR_INIT_NVAR(_10$$7);
				if (nesting) {
					ZVAL_BOOL(_10$$7, 1);
				} else {
					ZVAL_BOOL(_10$$7, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_11, 0, _10$$7);
				zephir_check_call_status();
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/mvc/model.zep", 2881);
				return;
			}
			if (Z_TYPE_P(record) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(relatedRecords);
				zephir_create_array(relatedRecords, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(relatedRecords, record);
			} else {
				ZEPHIR_CPY_WRT(relatedRecords, record);
			}
			ZEPHIR_OBS_NVAR(value);
			if (!(zephir_fetch_property_zval(&value, this_ptr, columns, PH_SILENT_CC))) {
				ZEPHIR_INIT_NVAR(_12$$10);
				if (nesting) {
					ZVAL_BOOL(_12$$10, 1);
				} else {
					ZVAL_BOOL(_12$$10, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_13, 0, _12$$10);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_14$$10);
				object_init_ex(_14$$10, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_15$$10);
				ZEPHIR_CONCAT_SVS(_15$$10, "The column '", columns, "' needs to be present in the model");
				ZEPHIR_CALL_METHOD(NULL, _14$$10, "__construct", &_16, 9, _15$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(_14$$10, "phalcon/mvc/model.zep", 2895 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_17$$4, relation, "isthrough", NULL, 0);
			zephir_check_call_status();
			isThrough = zephir_get_boolval(_17$$4);
			if (isThrough) {
				ZEPHIR_CALL_METHOD(&intermediateModelName, relation, "getintermediatemodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&intermediateFields, relation, "getintermediatefields", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&intermediateReferencedFields, relation, "getintermediatereferencedfields", NULL, 0);
				zephir_check_call_status();
			}
			zephir_is_iterable(relatedRecords, &_19$$4, &_18$$4, 0, 0, "phalcon/mvc/model.zep", 3010);
			for (
			  ; zend_hash_get_current_data_ex(_19$$4, (void**) &_20$$4, &_18$$4) == SUCCESS
			  ; zend_hash_move_forward_ex(_19$$4, &_18$$4)
			) {
				ZEPHIR_GET_HVALUE(recordAfter, _20$$4);
				if (!(isThrough)) {
					ZEPHIR_CALL_METHOD(NULL, recordAfter, "writeattribute", NULL, 0, referencedFields, value);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_21$$12, recordAfter, "save", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(_21$$12))) {
					ZEPHIR_CALL_METHOD(&_22$$14, recordAfter, "getmessages", NULL, 0);
					zephir_check_call_status();
					zephir_is_iterable(_22$$14, &_24$$14, &_23$$14, 0, 0, "phalcon/mvc/model.zep", 2952);
					for (
					  ; zend_hash_get_current_data_ex(_24$$14, (void**) &_25$$14, &_23$$14) == SUCCESS
					  ; zend_hash_move_forward_ex(_24$$14, &_23$$14)
					) {
						ZEPHIR_GET_HVALUE(message, _25$$14);
						if (Z_TYPE_P(message) == IS_OBJECT) {
							ZEPHIR_CALL_METHOD(NULL, message, "setmodel", NULL, 0, record);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, message);
						zephir_check_call_status();
					}
					ZEPHIR_INIT_NVAR(_27$$14);
					if (nesting) {
						ZVAL_BOOL(_27$$14, 1);
					} else {
						ZVAL_BOOL(_27$$14, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_28, 0, _27$$14);
					zephir_check_call_status();
					RETURN_MM_BOOL(0);
				}
				if (isThrough) {
					ZEPHIR_INIT_NVAR(_29$$17);
					ZVAL_BOOL(_29$$17, 1);
					ZEPHIR_CALL_METHOD(&intermediateModel, manager, "load", &_30, 0, intermediateModelName, _29$$17);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, intermediateModel, "writeattribute", NULL, 0, intermediateFields, value);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&intermediateValue, recordAfter, "readattribute", NULL, 0, referencedFields);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, intermediateModel, "writeattribute", NULL, 0, intermediateReferencedFields, intermediateValue);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_31$$17, intermediateModel, "save", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(_31$$17))) {
						ZEPHIR_CALL_METHOD(&_32$$18, intermediateModel, "getmessages", NULL, 0);
						zephir_check_call_status();
						zephir_is_iterable(_32$$18, &_34$$18, &_33$$18, 0, 0, "phalcon/mvc/model.zep", 3004);
						for (
						  ; zend_hash_get_current_data_ex(_34$$18, (void**) &_35$$18, &_33$$18) == SUCCESS
						  ; zend_hash_move_forward_ex(_34$$18, &_33$$18)
						) {
							ZEPHIR_GET_HVALUE(message, _35$$18);
							if (Z_TYPE_P(message) == IS_OBJECT) {
								ZEPHIR_CALL_METHOD(NULL, message, "setmodel", NULL, 0, record);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_26, 0, message);
							zephir_check_call_status();
						}
						ZEPHIR_INIT_NVAR(_36$$18);
						if (nesting) {
							ZVAL_BOOL(_36$$18, 1);
						} else {
							ZVAL_BOOL(_36$$18, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_37, 0, _36$$18);
						zephir_check_call_status();
						RETURN_MM_BOOL(0);
					}
				}
			}
		} else {
			if (Z_TYPE_P(record) != IS_ARRAY) {
				ZEPHIR_INIT_NVAR(_38$$22);
				if (nesting) {
					ZVAL_BOOL(_38$$22, 1);
				} else {
					ZVAL_BOOL(_38$$22, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_39, 0, _38$$22);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_40$$22);
				object_init_ex(_40$$22, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_41$$22);
				ZEPHIR_CONCAT_SVSVS(_41$$22, "There are no defined relations for the model '", className, "' using alias '", name, "'");
				ZEPHIR_CALL_METHOD(NULL, _40$$22, "__construct", &_16, 9, _41$$22);
				zephir_check_call_status();
				zephir_throw_exception_debug(_40$$22, "phalcon/mvc/model.zep", 3016 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_INIT_VAR(_42);
	if (nesting) {
		ZVAL_BOOL(_42, 1);
	} else {
		ZVAL_BOOL(_42, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0, _42);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * Inserts or updates a model instance. Returning true on success or false otherwise.
 *
 *<code>
 * // Creating a new robot
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * $robot->save();
 *
 * // Updating a robot name
 * $robot = Robots::findFirst("id = 100");
 *
 * $robot->name = "Biomass";
 *
 * $robot->save();
 *</code>
 *
 * @param array data
 * @param array whiteList
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, save) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *whiteList = NULL, *metaData = NULL, *related = NULL, *schema = NULL, *writeConnection = NULL, *readConnection = NULL, *source = NULL, *table = NULL, *identityField = NULL, *exists = NULL, *success = NULL, *_2 = NULL, *_6 = NULL, *_1$$3, *_3$$4 = NULL, *_4$$8, *_5$$9, *_7$$11, *_8$$12, *_9$$12 = NULL, *_10$$15, *_11$$17, *_12$$19 = NULL, *_13$$21;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &whiteList);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}
	if (!whiteList) {
		whiteList = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	_0 = Z_TYPE_P(data) == IS_ARRAY;
	if (_0) {
		_0 = zephir_fast_count_int(data TSRMLS_CC) > 0;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_1$$3);
		ZVAL_NULL(_1$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, data, _1$$3, whiteList);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "prepareSave", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(related);
	zephir_read_property_this(&related, this_ptr, SL("_related"), PH_NOISY_CC);
	if (Z_TYPE_P(related) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "_presaverelatedrecords", NULL, 0, writeConnection, related);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_3$$4)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(table);
		zephir_create_array(table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(table, schema);
		zephir_array_fast_append(table, source);
	} else {
		ZEPHIR_CPY_WRT(table, source);
	}
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&exists, this_ptr, "_exists", NULL, 0, metaData, readConnection, table);
	zephir_check_call_status();
	if (zephir_is_true(exists)) {
		ZEPHIR_INIT_ZVAL_NREF(_4$$8);
		ZVAL_LONG(_4$$8, 2);
		zephir_update_property_this(getThis(), SL("_operationMade"), _4$$8 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_5$$9);
		ZVAL_LONG(_5$$9, 1);
		zephir_update_property_this(getThis(), SL("_operationMade"), _5$$9 TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_2);
	array_init(_2);
	zephir_update_property_this(getThis(), SL("_errorMessages"), _2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&identityField, metaData, "getidentityfield", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "_presave", NULL, 0, metaData, exists, identityField);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_6)) {
		if (Z_TYPE_P(related) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_7$$11);
			ZVAL_BOOL(_7$$11, 0);
			ZEPHIR_CALL_METHOD(NULL, writeConnection, "rollback", NULL, 0, _7$$11);
			zephir_check_call_status();
		}
		if (ZEPHIR_GLOBAL(orm).exception_on_failed_save) {
			ZEPHIR_INIT_VAR(_8$$12);
			object_init_ex(_8$$12, phalcon_mvc_model_validationfailed_ce);
			ZEPHIR_CALL_METHOD(&_9$$12, this_ptr, "getmessages", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _8$$12, "__construct", NULL, 336, this_ptr, _9$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(_8$$12, "phalcon/mvc/model.zep", 3138 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(0);
	}
	if (zephir_is_true(exists)) {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "_dolowupdate", NULL, 0, metaData, writeConnection, table);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "_dolowinsert", NULL, 0, metaData, writeConnection, table, identityField);
		zephir_check_call_status();
	}
	if (zephir_is_true(success)) {
		ZEPHIR_INIT_ZVAL_NREF(_10$$15);
		ZVAL_LONG(_10$$15, 0);
		zephir_update_property_this(getThis(), SL("_dirtyState"), _10$$15 TSRMLS_CC);
	}
	if (Z_TYPE_P(related) == IS_ARRAY) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(success)) {
			ZEPHIR_INIT_VAR(_11$$17);
			ZVAL_BOOL(_11$$17, 0);
			ZEPHIR_CALL_METHOD(NULL, writeConnection, "rollback", NULL, 0, _11$$17);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&success, this_ptr, "_postsaverelatedrecords", NULL, 0, writeConnection, related);
			zephir_check_call_status();
		}
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		ZEPHIR_CALL_METHOD(&_12$$19, this_ptr, "_postsave", NULL, 0, success, exists);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(success, _12$$19);
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(success)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_13$$21);
		ZVAL_STRING(_13$$21, "afterSave", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _13$$21);
		zephir_check_temp_parameter(_13$$21);
		zephir_check_call_status();
	}
	RETURN_CCTOR(success);

}

/**
 * Inserts a model instance. If the instance already exists in the persistence it will throw an exception
 * Returning true on success or false otherwise.
 *
 *<code>
 * // Creating a new robot
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * $robot->create();
 *
 * // Passing an array to create
 * $robot = new Robots();
 *
 * $robot->create(
 *     [
 *         "type" => "mechanical",
 *         "name" => "Astro Boy",
 *         "year" => 1952,
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, create) {

	zval *_2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *whiteList = NULL, *metaData = NULL, *_0 = NULL, *_1 = NULL, *_3$$3, *_4$$3, *_5$$3, *_6$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &whiteList);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}
	if (!whiteList) {
		whiteList = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_exists", NULL, 0, metaData, _1);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_create_array(_2$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3$$3);
		object_init_ex(_3$$3, phalcon_mvc_model_message_ce);
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_STRING(_4$$3, "Record cannot be created because it already exists", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_5$$3);
		ZVAL_NULL(_5$$3);
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_STRING(_6$$3, "InvalidCreateAttempt", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "__construct", NULL, 8, _4$$3, _5$$3, _6$$3);
		zephir_check_temp_parameter(_4$$3);
		zephir_check_temp_parameter(_6$$3);
		zephir_check_call_status();
		zephir_array_fast_append(_2$$3, _3$$3);
		zephir_update_property_this(getThis(), SL("_errorMessages"), _2$$3 TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "save", NULL, 0, data, whiteList);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Updates a model instance. If the instance doesn't exist in the persistence it will throw an exception
 * Returning true on success or false otherwise.
 *
 *<code>
 * // Updating a robot name
 * $robot = Robots::findFirst("id = 100");
 *
 * $robot->name = "Biomass";
 *
 * $robot->update();
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, update) {

	zval *_3$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *whiteList = NULL, *metaData = NULL, *_0, *_1$$3 = NULL, *_2$$3 = NULL, *_4$$4, *_5$$4, *_6$$4, *_7$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &whiteList);

	if (!data) {
		data = ZEPHIR_GLOBAL(global_null);
	}
	if (!whiteList) {
		whiteList = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dirtyState"), PH_NOISY_CC);
	if (zephir_is_true(_0)) {
		ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getreadconnection", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "_exists", NULL, 0, metaData, _2$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(_1$$3))) {
			ZEPHIR_INIT_VAR(_3$$4);
			zephir_create_array(_3$$4, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_4$$4);
			object_init_ex(_4$$4, phalcon_mvc_model_message_ce);
			ZEPHIR_INIT_VAR(_5$$4);
			ZVAL_STRING(_5$$4, "Record cannot be updated because it does not exist", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_6$$4);
			ZVAL_NULL(_6$$4);
			ZEPHIR_INIT_VAR(_7$$4);
			ZVAL_STRING(_7$$4, "InvalidUpdateAttempt", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", NULL, 8, _5$$4, _6$$4, _7$$4);
			zephir_check_temp_parameter(_5$$4);
			zephir_check_temp_parameter(_7$$4);
			zephir_check_call_status();
			zephir_array_fast_append(_3$$4, _4$$4);
			zephir_update_property_this(getThis(), SL("_errorMessages"), _3$$4 TSRMLS_CC);
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "save", NULL, 0, data, whiteList);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 *
 * <code>
 * $robot = Robots::findFirst("id=100");
 *
 * $robot->delete();
 *
 * $robots = Robots::find("type = 'mechanical'");
 *
 * foreach ($robots as $robot) {
 *     $robot->delete();
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, delete) {

	HashTable *_4;
	HashPosition _3;
	zval *metaData = NULL, *writeConnection = NULL, *values = NULL, *bindTypes = NULL, *primaryKeys = NULL, *bindDataTypes = NULL, *columnMap = NULL, *attributeField = NULL, *conditions = NULL, *primaryKey = NULL, *bindType = NULL, *value = NULL, *schema = NULL, *source = NULL, *table = NULL, *success = NULL, *_0, *_1, **_5, *_19, *_2$$3 = NULL, *_6$$9 = NULL, *_7$$9 = NULL, *_9$$11 = NULL, *_10$$11 = NULL, *_11$$13 = NULL, *_12$$13 = NULL, *_13$$8 = NULL, *_15$$8 = NULL, *_16$$14 = NULL, *_17$$14, *_18$$16, *_20$$20 = NULL, *_21$$23;
	zephir_fcall_cache_entry *_8 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 3);
	zephir_update_property_this(getThis(), SL("_operationMade"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(getThis(), SL("_errorMessages"), _1 TSRMLS_CC);
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "_checkforeignkeysreverserestrict", NULL, 337);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_2$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(values);
	array_init(values);
	ZEPHIR_INIT_VAR(bindTypes);
	array_init(bindTypes);
	ZEPHIR_INIT_VAR(conditions);
	array_init(conditions);
	ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(columnMap);
		ZVAL_NULL(columnMap);
	}
	if (!(zephir_fast_count_int(primaryKeys TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation", "phalcon/mvc/model.zep", 3339);
		return;
	}
	zephir_is_iterable(primaryKeys, &_4, &_3, 0, 0, "phalcon/mvc/model.zep", 3382);
	for (
	  ; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(primaryKey, _5);
		ZEPHIR_OBS_NVAR(bindType);
		if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, primaryKey, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_6$$9);
			object_init_ex(_6$$9, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_7$$9);
			ZEPHIR_CONCAT_SVS(_7$$9, "Column '", primaryKey, "' have not defined a bind data type");
			ZEPHIR_CALL_METHOD(NULL, _6$$9, "__construct", &_8, 9, _7$$9);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6$$9, "phalcon/mvc/model.zep", 3351 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, columnMap, primaryKey, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_9$$11);
				object_init_ex(_9$$11, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_10$$11);
				ZEPHIR_CONCAT_SVS(_10$$11, "Column '", primaryKey, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _9$$11, "__construct", &_8, 9, _10$$11);
				zephir_check_call_status();
				zephir_throw_exception_debug(_9$$11, "phalcon/mvc/model.zep", 3359 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(attributeField, primaryKey);
		}
		ZEPHIR_OBS_NVAR(value);
		if (!(zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC))) {
			ZEPHIR_INIT_NVAR(_11$$13);
			object_init_ex(_11$$13, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_12$$13);
			ZEPHIR_CONCAT_SVS(_12$$13, "Cannot delete the record because the primary key attribute: '", attributeField, "' wasn't set");
			ZEPHIR_CALL_METHOD(NULL, _11$$13, "__construct", &_8, 9, _12$$13);
			zephir_check_call_status();
			zephir_throw_exception_debug(_11$$13, "phalcon/mvc/model.zep", 3371 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_append(&values, value, PH_SEPARATE, "phalcon/mvc/model.zep", 3377);
		ZEPHIR_CALL_METHOD(&_13$$8, writeConnection, "escapeidentifier", &_14, 0, primaryKey);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_15$$8);
		ZEPHIR_CONCAT_VS(_15$$8, _13$$8, " = ?");
		zephir_array_append(&conditions, _15$$8, PH_SEPARATE, "phalcon/mvc/model.zep", 3378);
		zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 3379);
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (0) {
			zephir_update_property_this(getThis(), SL("_skipped"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
		} else {
			zephir_update_property_this(getThis(), SL("_skipped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(_17$$14);
		ZVAL_STRING(_17$$14, "beforeDelete", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_16$$14, this_ptr, "fireeventcancel", NULL, 0, _17$$14);
		zephir_check_temp_parameter(_17$$14);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_16$$14)) {
			RETURN_MM_BOOL(0);
		} else {
			_18$$16 = zephir_fetch_nproperty_this(this_ptr, SL("_skipped"), PH_NOISY_CC);
			if (ZEPHIR_IS_TRUE_IDENTICAL(_18$$16)) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(table);
		zephir_create_array(table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(table, schema);
		zephir_array_fast_append(table, source);
	} else {
		ZEPHIR_CPY_WRT(table, source);
	}
	ZEPHIR_INIT_VAR(_19);
	zephir_fast_join_str(_19, SL(" AND "), conditions TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&success, writeConnection, "delete", NULL, 0, table, _19, values, bindTypes);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_20$$20, this_ptr, "_checkforeignkeysreversecascade", NULL, 338);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_20$$20)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (zephir_is_true(success)) {
			ZEPHIR_INIT_VAR(_21$$23);
			ZVAL_STRING(_21$$23, "afterDelete", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _21$$23);
			zephir_check_temp_parameter(_21$$23);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 2);
	zephir_update_property_this(getThis(), SL("_dirtyState"), _0 TSRMLS_CC);
	RETURN_CCTOR(success);

}

/**
 * Returns the type of the latest operation performed by the ORM
 * Returns one of the OP_* class constants
 */
PHP_METHOD(Phalcon_Mvc_Model, getOperationMade) {

	

	RETURN_MEMBER(getThis(), "_operationMade");

}

/**
 * Refreshes the model attributes re-querying the record from the database
 */
PHP_METHOD(Phalcon_Mvc_Model, refresh) {

	zval *_8, *_7$$9 = NULL;
	HashTable *_5;
	HashPosition _4;
	zval *metaData = NULL, *readConnection = NULL, *schema = NULL, *source = NULL, *table = NULL, *uniqueKey = NULL, *tables = NULL, *uniqueParams = NULL, *dialect = NULL, *row = NULL, *fields = NULL, *attribute = NULL, *manager = NULL, *columnMap = NULL, *_0, *_1, *_3 = NULL, **_6, *_9 = NULL, *_10 = NULL, *_2$$6 = NULL, *_11$$10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dirtyState"), PH_NOISY_CC);
	if (!ZEPHIR_IS_LONG(_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/mvc/model.zep", 3457);
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _1);
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(table);
		zephir_create_array(table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(table, schema);
		zephir_array_fast_append(table, source);
	} else {
		ZEPHIR_CPY_WRT(table, source);
	}
	ZEPHIR_OBS_VAR(uniqueKey);
	zephir_read_property_this(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	if (!(zephir_is_true(uniqueKey))) {
		ZEPHIR_CALL_METHOD(&_2$$6, this_ptr, "_exists", NULL, 0, metaData, readConnection, table);
		zephir_check_call_status();
		if (!(zephir_is_true(_2$$6))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/mvc/model.zep", 3480);
			return;
		}
		ZEPHIR_OBS_NVAR(uniqueKey);
		zephir_read_property_this(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(uniqueParams);
	zephir_read_property_this(&uniqueParams, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	if (Z_TYPE_P(uniqueParams) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/mvc/model.zep", 3488);
		return;
	}
	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	ZEPHIR_CALL_METHOD(&_3, metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "phalcon/mvc/model.zep", 3502);
	for (
	  ; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(attribute, _6);
		ZEPHIR_INIT_NVAR(_7$$9);
		zephir_create_array(_7$$9, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_7$$9, attribute);
		zephir_array_append(&fields, _7$$9, PH_SEPARATE, "phalcon/mvc/model.zep", 3496);
	}
	ZEPHIR_CALL_METHOD(&dialect, readConnection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_8);
	zephir_create_array(_8, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_8, SL("columns"), &fields, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_9, readConnection, "escapeidentifier", NULL, 0, table);
	zephir_check_call_status();
	zephir_array_update_string(&_8, SL("tables"), &_9, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_8, SL("where"), &uniqueKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&tables, dialect, "select", NULL, 0, _8);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueTypes"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_LONG(_10, 2);
	ZEPHIR_CALL_METHOD(&row, readConnection, "fetchone", NULL, 0, tables, _10, uniqueParams, _1);
	zephir_check_call_status();
	if (Z_TYPE_P(row) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, row, columnMap);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_11$$10, manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(_11$$10)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setsnapshotdata", NULL, 0, row, columnMap);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoldsnapshotdata", NULL, 0, row, columnMap);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "afterFetch", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _10);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Skips the current operation forcing a success state
 */
PHP_METHOD(Phalcon_Mvc_Model, skipOperation) {

	zval *skip_param = NULL;
	zend_bool skip;

	zephir_fetch_params(0, 1, 0, &skip_param);

	skip = zephir_get_boolval(skip_param);


	if (skip) {
		zephir_update_property_this(getThis(), SL("_skipped"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("_skipped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}

}

/**
 * Reads an attribute value by its name
 *
 * <code>
 * echo $robot->readAttribute("name");
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, readAttribute) {

	zval *attribute_param = NULL, *_0;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute_param);

	if (UNEXPECTED(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(attribute);
		ZVAL_EMPTY_STRING(attribute);
	}


	if (!(zephir_isset_property_zval(this_ptr, attribute TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_zval(&_0, this_ptr, attribute, PH_NOISY_CC);
	RETURN_CCTOR(_0);

}

/**
 * Writes an attribute value by its name
 *
 *<code>
 * $robot->writeAttribute("name", "Rosey");
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, writeAttribute) {

	zval *attribute_param = NULL, *value;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);

	if (UNEXPECTED(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(attribute);
		ZVAL_EMPTY_STRING(attribute);
	}


	zephir_update_property_zval_zval(getThis(), attribute, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT/UPDATE statement
 *
 *<code>
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->skipAttributes(
 *             [
 *                 "price",
 *             ]
 *         );
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributes) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL;
	zval *attributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	attributes = attributes_param;


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "skipattributesoncreate", NULL, 0, attributes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "skipattributesonupdate", NULL, 0, attributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT statement
 *
 *<code>
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->skipAttributesOnCreate(
 *             [
 *                 "created_at",
 *             ]
 *         );
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnCreate) {

	HashTable *_1;
	HashPosition _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, *keysAttributes = NULL, *attribute = NULL, **_2, *_3 = NULL;
	zval *attributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	attributes = attributes_param;


	ZEPHIR_INIT_VAR(keysAttributes);
	array_init(keysAttributes);
	zephir_is_iterable(attributes, &_1, &_0, 0, 0, "phalcon/mvc/model.zep", 3617);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(attribute, _2);
		zephir_array_update_zval(&keysAttributes, attribute, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _3, "setautomaticcreateattributes", NULL, 0, this_ptr, keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated UPDATE statement
 *
 *<code>
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->skipAttributesOnUpdate(
 *             [
 *                 "modified_in",
 *             ]
 *         );
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnUpdate) {

	HashTable *_1;
	HashPosition _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, *keysAttributes = NULL, *attribute = NULL, **_2, *_3 = NULL;
	zval *attributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	attributes = attributes_param;


	ZEPHIR_INIT_VAR(keysAttributes);
	array_init(keysAttributes);
	zephir_is_iterable(attributes, &_1, &_0, 0, 0, "phalcon/mvc/model.zep", 3648);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(attribute, _2);
		zephir_array_update_zval(&keysAttributes, attribute, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _3, "setautomaticupdateattributes", NULL, 0, this_ptr, keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated UPDATE statement
 *
 *<code>
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->allowEmptyStringValues(
 *             [
 *                 "name",
 *             ]
 *         );
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, allowEmptyStringValues) {

	HashTable *_1;
	HashPosition _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, *keysAttributes = NULL, *attribute = NULL, **_2, *_3 = NULL;
	zval *attributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	attributes = attributes_param;


	ZEPHIR_INIT_VAR(keysAttributes);
	array_init(keysAttributes);
	zephir_is_iterable(attributes, &_1, &_0, 0, 0, "phalcon/mvc/model.zep", 3679);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(attribute, _2);
		zephir_array_update_zval(&keysAttributes, attribute, &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _3, "setemptystringattributes", NULL, 0, this_ptr, keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Setup a 1-1 relation between two models
 *
 *<code>
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->hasOne("id", "RobotsDescription", "robots_id");
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, hasOne) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *referenceModel = NULL;
	zval *fields, *referenceModel_param = NULL, *referencedFields, *options = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);

	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(referenceModel);
		ZVAL_EMPTY_STRING(referenceModel);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "addhasone", NULL, 0, this_ptr, fields, referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setup a reverse 1-1 or n-1 relation between two models
 *
 *<code>
 *
 * class RobotsParts extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->belongsTo("robots_id", "Robots", "id");
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, belongsTo) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *referenceModel = NULL;
	zval *fields, *referenceModel_param = NULL, *referencedFields, *options = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);

	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(referenceModel);
		ZVAL_EMPTY_STRING(referenceModel);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "addbelongsto", NULL, 0, this_ptr, fields, referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setup a 1-n relation between two models
 *
 *<code>
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         $this->hasMany("id", "RobotsParts", "robots_id");
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, hasMany) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *referenceModel = NULL;
	zval *fields, *referenceModel_param = NULL, *referencedFields, *options = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);

	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(referenceModel);
		ZVAL_EMPTY_STRING(referenceModel);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "addhasmany", NULL, 0, this_ptr, fields, referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setup an n-n relation between two models, through an intermediate relation
 *
 *<code>
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *     public function initialize()
 *     {
 *         // Setup a many-to-many relation to Parts through RobotsParts
 *         $this->hasManyToMany(
 *             "id",
 *             "RobotsParts",
 *             "robots_id",
 *             "parts_id",
 *             "Parts",
 *             "id",
 *         );
 *     }
 * }
 *</code>
 *
 * @param	string|array fields
 * @param	string intermediateModel
 * @param	string|array intermediateFields
 * @param	string|array intermediateReferencedFields
 * @param	string referencedModel
 * @param   string|array referencedFields
 * @param   array options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model, hasManyToMany) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *intermediateModel = NULL, *referenceModel = NULL;
	zval *fields, *intermediateModel_param = NULL, *intermediateFields, *intermediateReferencedFields, *referenceModel_param = NULL, *referencedFields, *options = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 1, &fields, &intermediateModel_param, &intermediateFields, &intermediateReferencedFields, &referenceModel_param, &referencedFields, &options);

	if (UNEXPECTED(Z_TYPE_P(intermediateModel_param) != IS_STRING && Z_TYPE_P(intermediateModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'intermediateModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(intermediateModel_param) == IS_STRING)) {
		zephir_get_strval(intermediateModel, intermediateModel_param);
	} else {
		ZEPHIR_INIT_VAR(intermediateModel);
		ZVAL_EMPTY_STRING(intermediateModel);
	}
	if (UNEXPECTED(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(referenceModel);
		ZVAL_EMPTY_STRING(referenceModel);
	}
	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "addhasmanytomany", NULL, 0, this_ptr, fields, intermediateModel, intermediateFields, intermediateReferencedFields, referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setups a behavior in a model
 *
 *<code>
 *
 * use Phalcon\Mvc\Model;
 * use Phalcon\Mvc\Model\Behavior\Timestampable;
 *
 * class Robots extends Model
 * {
 *     public function initialize()
 *     {
 *         $this->addBehavior(
 *             new Timestampable(
 *                [
 *                    "onCreate" => [
 *                         "field"  => "created_at",
 *                         "format" => "Y-m-d",
 * 	                   ],
 *                 ]
 *             )
 *         );
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, addBehavior) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *behavior, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &behavior);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "addbehavior", NULL, 0, this_ptr, behavior);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets if the model must keep the original record snapshot in memory
 *
 *<code>
 *
 * use Phalcon\Mvc\Model;
 *
 * class Robots extends Model
 * {
 *     public function initialize()
 *     {
 *         $this->keepSnapshots(true);
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, keepSnapshots) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keepSnapshot_param = NULL, *_0, *_1;
	zend_bool keepSnapshot;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keepSnapshot_param);

	keepSnapshot = zephir_get_boolval(keepSnapshot_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	if (keepSnapshot) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, _0, "keepsnapshots", NULL, 0, this_ptr, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the record's snapshot data.
 * This method is used internally to set snapshot data when the model was set up to keep snapshot data
 *
 * @param array data
 * @param array columnMap
 */
PHP_METHOD(Phalcon_Mvc_Model, setSnapshotData) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, *key = NULL, *value = NULL, *snapshot = NULL, *attribute = NULL, *_8, **_2$$3, *_3$$7 = NULL, *_4$$7 = NULL, *_6$$11 = NULL, *_7$$11 = NULL, *_9$$14;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &columnMap);

	data = data_param;
	if (!columnMap) {
		columnMap = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(columnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(snapshot);
		array_init(snapshot);
		zephir_is_iterable(data, &_1$$3, &_0$$3, 0, 0, "phalcon/mvc/model.zep", 3898);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _1$$3, _0$$3);
			ZEPHIR_GET_HVALUE(value, _2$$3);
			if (Z_TYPE_P(key) != IS_STRING) {
				continue;
			}
			ZEPHIR_OBS_NVAR(attribute);
			if (!(zephir_array_isset_fetch(&attribute, columnMap, key, 0 TSRMLS_CC))) {
				if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
					ZEPHIR_INIT_NVAR(_3$$7);
					object_init_ex(_3$$7, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4$$7);
					ZEPHIR_CONCAT_SVS(_4$$7, "Column '", key, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _3$$7, "__construct", &_5, 9, _4$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(_3$$7, "phalcon/mvc/model.zep", 3880 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					continue;
				}
			}
			if (Z_TYPE_P(attribute) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attribute);
				if (!(zephir_array_isset_long_fetch(&attribute, attribute, 0, 0 TSRMLS_CC))) {
					if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
						ZEPHIR_INIT_NVAR(_6$$11);
						object_init_ex(_6$$11, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_7$$11);
						ZEPHIR_CONCAT_SVS(_7$$11, "Column '", key, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, _6$$11, "__construct", &_5, 9, _7$$11);
						zephir_check_call_status();
						zephir_throw_exception_debug(_6$$11, "phalcon/mvc/model.zep", 3889 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					} else {
						continue;
					}
				}
			}
			zephir_array_update_zval(&snapshot, attribute, &value, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_CPY_WRT(snapshot, data);
	}
	ZEPHIR_OBS_VAR(_8);
	zephir_read_property_this(&_8, this_ptr, SL("_snapshot"), PH_NOISY_CC);
	if (Z_TYPE_P(_8) == IS_ARRAY) {
		_9$$14 = zephir_fetch_nproperty_this(this_ptr, SL("_snapshot"), PH_NOISY_CC);
		zephir_update_property_this(getThis(), SL("_oldSnapshot"), _9$$14 TSRMLS_CC);
	}
	zephir_update_property_this(getThis(), SL("_snapshot"), snapshot TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the record's old snapshot data.
 * This method is used internally to set old snapshot data when the model was set up to keep snapshot data
 *
 * @param array data
 * @param array columnMap
 */
PHP_METHOD(Phalcon_Mvc_Model, setOldSnapshotData) {

	HashTable *_1$$3;
	HashPosition _0$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, *key = NULL, *value = NULL, *snapshot = NULL, *attribute = NULL, **_2$$3, *_3$$7 = NULL, *_4$$7 = NULL, *_6$$11 = NULL, *_7$$11 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &columnMap);

	data = data_param;
	if (!columnMap) {
		columnMap = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(columnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(snapshot);
		array_init(snapshot);
		zephir_is_iterable(data, &_1$$3, &_0$$3, 0, 0, "phalcon/mvc/model.zep", 3952);
		for (
		  ; zend_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _1$$3, _0$$3);
			ZEPHIR_GET_HVALUE(value, _2$$3);
			if (Z_TYPE_P(key) != IS_STRING) {
				continue;
			}
			ZEPHIR_OBS_NVAR(attribute);
			if (!(zephir_array_isset_fetch(&attribute, columnMap, key, 0 TSRMLS_CC))) {
				if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
					ZEPHIR_INIT_NVAR(_3$$7);
					object_init_ex(_3$$7, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4$$7);
					ZEPHIR_CONCAT_SVS(_4$$7, "Column '", key, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _3$$7, "__construct", &_5, 9, _4$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(_3$$7, "phalcon/mvc/model.zep", 3936 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					continue;
				}
			}
			if (Z_TYPE_P(attribute) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attribute);
				if (!(zephir_array_isset_long_fetch(&attribute, attribute, 0, 0 TSRMLS_CC))) {
					if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
						ZEPHIR_INIT_NVAR(_6$$11);
						object_init_ex(_6$$11, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_7$$11);
						ZEPHIR_CONCAT_SVS(_7$$11, "Column '", key, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, _6$$11, "__construct", &_5, 9, _7$$11);
						zephir_check_call_status();
						zephir_throw_exception_debug(_6$$11, "phalcon/mvc/model.zep", 3944 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					} else {
						continue;
					}
				}
			}
			zephir_array_update_zval(&snapshot, attribute, &value, PH_COPY | PH_SEPARATE);
		}
	} else {
		ZEPHIR_CPY_WRT(snapshot, data);
	}
	zephir_update_property_this(getThis(), SL("_oldSnapshot"), snapshot TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if the object has internal snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, hasSnapshotData) {

	zval *snapshot = NULL;


	snapshot = zephir_fetch_nproperty_this(this_ptr, SL("_snapshot"), PH_NOISY_CC);
	RETURN_BOOL(Z_TYPE_P(snapshot) == IS_ARRAY);

}

/**
 * Returns the internal snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, getSnapshotData) {

	

	RETURN_MEMBER(getThis(), "_snapshot");

}

/**
 * Returns the internal old snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, getOldSnapshotData) {

	

	RETURN_MEMBER(getThis(), "_oldSnapshot");

}

/**
 * Check if a specific attribute has changed
 * This only works if the model is keeping data snapshots
 *
 *<code>
 * $robot = new Robots();
 *
 * $robot->type = "mechanical";
 * $robot->name = "Astro Boy";
 * $robot->year = 1952;
 *
 * $robot->create();
 * $robot->type = "hydraulic";
 * $hasChanged = $robot->hasChanged("type"); // returns true
 * $hasChanged = $robot->hasChanged(["type", "name"]); // returns true
 * $hasChanged = $robot->hasChanged(["type", "name", true]); // returns false
 *</code>
 *
 * @param string|array fieldName
 * @param boolean allFields
 */
PHP_METHOD(Phalcon_Mvc_Model, hasChanged) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool allFields;
	zval *fieldName = NULL, *allFields_param = NULL, *changedFields = NULL, *_0$$5 = NULL, *_1$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fieldName, &allFields_param);

	if (!fieldName) {
		fieldName = ZEPHIR_GLOBAL(global_null);
	}
	if (!allFields_param) {
		allFields = 0;
	} else {
		allFields = zephir_get_boolval(allFields_param);
	}


	ZEPHIR_CALL_METHOD(&changedFields, this_ptr, "getchangedfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fieldName) == IS_STRING) {
		RETURN_MM_BOOL(zephir_fast_in_array(fieldName, changedFields TSRMLS_CC));
	} else if (Z_TYPE_P(fieldName) == IS_ARRAY) {
		if (allFields) {
			ZEPHIR_CALL_FUNCTION(&_0$$5, "array_intersect", NULL, 339, fieldName, changedFields);
			zephir_check_call_status();
			RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(_0$$5, fieldName));
		}
		ZEPHIR_CALL_FUNCTION(&_1$$4, "array_intersect", NULL, 339, fieldName, changedFields);
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_fast_count_int(_1$$4 TSRMLS_CC) > 0);
	}
	RETURN_MM_BOOL(zephir_fast_count_int(changedFields TSRMLS_CC) > 0);

}

/**
 * Check if a specific attribute was updated
 * This only works if the model is keeping data snapshots
 *
 * @param string|array fieldName
 */
PHP_METHOD(Phalcon_Mvc_Model, hasUpdated) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool allFields;
	zval *fieldName = NULL, *allFields_param = NULL, *updatedFields = NULL, *_0$$5 = NULL, *_1$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &fieldName, &allFields_param);

	if (!fieldName) {
		fieldName = ZEPHIR_GLOBAL(global_null);
	}
	if (!allFields_param) {
		allFields = 0;
	} else {
		allFields = zephir_get_boolval(allFields_param);
	}


	ZEPHIR_CALL_METHOD(&updatedFields, this_ptr, "getupdatedfields", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(fieldName) == IS_STRING) {
		RETURN_MM_BOOL(zephir_fast_in_array(fieldName, updatedFields TSRMLS_CC));
	} else if (Z_TYPE_P(fieldName) == IS_ARRAY) {
		if (allFields) {
			ZEPHIR_CALL_FUNCTION(&_0$$5, "array_intersect", NULL, 339, fieldName, updatedFields);
			zephir_check_call_status();
			RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(_0$$5, fieldName));
		}
		ZEPHIR_CALL_FUNCTION(&_1$$4, "array_intersect", NULL, 339, fieldName, updatedFields);
		zephir_check_call_status();
		RETURN_MM_BOOL(zephir_fast_count_int(_1$$4 TSRMLS_CC) > 0);
	}
	RETURN_MM_BOOL(zephir_fast_count_int(updatedFields TSRMLS_CC) > 0);

}

/**
 * Returns a list of changed values.
 *
 * <code>
 * $robots = Robots::findFirst();
 * print_r($robots->getChangedFields()); // []
 *
 * $robots->deleted = 'Y';
 *
 * $robots->getChangedFields();
 * print_r($robots->getChangedFields()); // ["deleted"]
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, getChangedFields) {

	HashTable *_2;
	HashPosition _1;
	zval *metaData = NULL, *changed = NULL, *name = NULL, *snapshot = NULL, *columnMap = NULL, *allAttributes = NULL, *value = NULL, *_0 = NULL, **_3, *_4$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(snapshot);
	zephir_read_property_this(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
	if (Z_TYPE_P(snapshot) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record doesn't have a valid data snapshot", "phalcon/mvc/model.zep", 4077);
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, metaData, "getreversecolumnmap", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(columnMap) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&allAttributes, metaData, "getdatatypes", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(allAttributes, columnMap);
	}
	ZEPHIR_INIT_VAR(changed);
	array_init(changed);
	ZEPHIR_INIT_VAR(_0);
	zephir_is_iterable(allAttributes, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 4130);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(name, _2, _1);
		ZEPHIR_GET_HVALUE(_0, _3);
		if (!(zephir_array_isset(snapshot, name))) {
			zephir_array_append(&changed, name, PH_SEPARATE, "phalcon/mvc/model.zep", 4109);
			continue;
		}
		ZEPHIR_OBS_NVAR(value);
		if (!(zephir_fetch_property_zval(&value, this_ptr, name, PH_SILENT_CC))) {
			zephir_array_append(&changed, name, PH_SEPARATE, "phalcon/mvc/model.zep", 4117);
			continue;
		}
		zephir_array_fetch(&_4$$6, snapshot, name, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 4124 TSRMLS_CC);
		if (!ZEPHIR_IS_IDENTICAL(value, _4$$6)) {
			zephir_array_append(&changed, name, PH_SEPARATE, "phalcon/mvc/model.zep", 4125);
			continue;
		}
	}
	RETURN_CCTOR(changed);

}

/**
 * Returns a list of updated values.
 *
 * <code>
 * $robots = Robots::findFirst();
 * print_r($robots->getChangedFields()); // []
 *
 * $robots->deleted = 'Y';
 *
 * $robots->getChangedFields();
 * print_r($robots->getChangedFields()); // ["deleted"]
 * $robots->save();
 * print_r($robots->getChangedFields()); // []
 * print_r($robots->getUpdatedFields()); // ["deleted"]
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, getUpdatedFields) {

	HashTable *_2;
	HashPosition _1;
	zval *updated = NULL, *name = NULL, *snapshot = NULL, *oldSnapshot = NULL, *value = NULL, *_0, **_3, *_4$$6;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(snapshot);
	zephir_read_property_this(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(oldSnapshot);
	zephir_read_property_this(&oldSnapshot, this_ptr, SL("_oldSnapshot"), PH_NOISY_CC);
	if (!(ZEPHIR_GLOBAL(orm).update_snapshot_on_save)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Update snapshot on save must be enabled for this method to work properly", "phalcon/mvc/model.zep", 4158);
		return;
	}
	if (Z_TYPE_P(snapshot) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record doesn't have a valid data snapshot", "phalcon/mvc/model.zep", 4162);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dirtyState"), PH_NOISY_CC);
	if (!ZEPHIR_IS_LONG(_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Change checking cannot be performed because the object has not been persisted or is deleted", "phalcon/mvc/model.zep", 4169);
		return;
	}
	ZEPHIR_INIT_VAR(updated);
	array_init(updated);
	zephir_is_iterable(snapshot, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 4189);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(name, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (!(zephir_array_isset(oldSnapshot, name))) {
			zephir_array_append(&updated, name, PH_SEPARATE, "phalcon/mvc/model.zep", 4179);
			continue;
		}
		zephir_array_fetch(&_4$$6, oldSnapshot, name, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 4183 TSRMLS_CC);
		if (!ZEPHIR_IS_IDENTICAL(value, _4$$6)) {
			zephir_array_append(&updated, name, PH_SEPARATE, "phalcon/mvc/model.zep", 4184);
			continue;
		}
	}
	RETURN_CCTOR(updated);

}

/**
 * Sets if a model must use dynamic update instead of the all-field update
 *
 *<code>
 *
 * use Phalcon\Mvc\Model;
 *
 * class Robots extends Model
 * {
 *     public function initialize()
 *     {
 *         $this->useDynamicUpdate(true);
 *     }
 * }
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, useDynamicUpdate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dynamicUpdate_param = NULL, *_0, *_1;
	zend_bool dynamicUpdate;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dynamicUpdate_param);

	dynamicUpdate = zephir_get_boolval(dynamicUpdate_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	if (dynamicUpdate) {
		ZVAL_BOOL(_1, 1);
	} else {
		ZVAL_BOOL(_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, _0, "usedynamicupdate", NULL, 0, this_ptr, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns related records based on defined relations
 *
 * @param string alias
 * @param array arguments
 * @return \Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getRelated) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, *arguments = NULL, *relation = NULL, *className = NULL, *manager = NULL, *_0, *_1 = NULL, *_4, *_2$$3, *_3$$3;
	zval *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &alias_param, &arguments);

	zephir_get_strval(alias, alias_param);
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, this_ptr, 0 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_CALL_METHOD(&_1, manager, "getrelationbyalias", NULL, 0, className, alias);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(relation, _1);
	if (Z_TYPE_P(relation) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SVSVS(_3$$3, "There is no defined relations for the model '", className, "' using alias '", alias, "'");
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 9, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "phalcon/mvc/model.zep", 4231 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_NULL(_4);
	ZEPHIR_RETURN_CALL_METHOD(manager, "getrelationrecords", NULL, 0, relation, _4, this_ptr, arguments);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns related records defined relations depending on the method name
 *
 * @param string modelName
 * @param string method
 * @param array arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, _getRelatedRecords) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *method_param = NULL, *arguments, *manager = NULL, *relation = NULL, *queryMethod = NULL, *extraArgs = NULL, *_0, *_1$$3 = NULL, _2$$3, *_3$$3, *_4$$4 = NULL, _5$$4, *_6$$4;
	zval *modelName = NULL, *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &modelName_param, &method_param, &arguments);

	if (UNEXPECTED(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_INIT_VAR(relation);
	ZVAL_BOOL(relation, 0);
	ZEPHIR_INIT_VAR(queryMethod);
	ZVAL_NULL(queryMethod);
	if (zephir_start_with_str(method, SL("get"))) {
		ZEPHIR_SINIT_VAR(_2$$3);
		ZVAL_LONG(&_2$$3, 3);
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_substr(_3$$3, method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(&_1$$3, manager, "getrelationbyalias", NULL, 0, modelName, _3$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(relation, _1$$3);
	} else if (zephir_start_with_str(method, SL("count"))) {
		ZEPHIR_INIT_NVAR(queryMethod);
		ZVAL_STRING(queryMethod, "count", 1);
		ZEPHIR_SINIT_VAR(_5$$4);
		ZVAL_LONG(&_5$$4, 5);
		ZEPHIR_INIT_VAR(_6$$4);
		zephir_substr(_6$$4, method, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(&_4$$4, manager, "getrelationbyalias", NULL, 0, modelName, _6$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(relation, _4$$4);
	}
	if (Z_TYPE_P(relation) != IS_OBJECT) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(extraArgs);
	zephir_array_isset_long_fetch(&extraArgs, arguments, 0, 0 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(manager, "getrelationrecords", NULL, 0, relation, queryMethod, this_ptr, extraArgs);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Try to check if the query must invoke a finder
 *
 * @param  string method
 * @param  array arguments
 * @return \Phalcon\Mvc\ModelInterface[]|\Phalcon\Mvc\ModelInterface|boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _invokeFinder) {

	zval *_9, *_11;
	zend_class_entry *_6, *_12;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method, *arguments, *extraMethod = NULL, *type = NULL, *modelName = NULL, *value = NULL, *model = NULL, *attributes = NULL, *field = NULL, *extraMethodFirst = NULL, *metaData = NULL, *_5 = NULL, *_10, _0$$3, _1$$4, _2$$5, *_3$$7, *_4$$7, *_7$$13, *_8$$13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method, &arguments);



	ZEPHIR_INIT_VAR(extraMethod);
	ZVAL_NULL(extraMethod);
	if (zephir_start_with_str(method, SL("findFirstBy"))) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "findFirst", 1);
		ZEPHIR_SINIT_VAR(_0$$3);
		ZVAL_LONG(&_0$$3, 11);
		ZEPHIR_INIT_NVAR(extraMethod);
		zephir_substr(extraMethod, method, 11 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	} else if (zephir_start_with_str(method, SL("findBy"))) {
		ZEPHIR_INIT_NVAR(type);
		ZVAL_STRING(type, "find", 1);
		ZEPHIR_SINIT_VAR(_1$$4);
		ZVAL_LONG(&_1$$4, 6);
		ZEPHIR_INIT_NVAR(extraMethod);
		zephir_substr(extraMethod, method, 6 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	} else if (zephir_start_with_str(method, SL("countBy"))) {
		ZEPHIR_INIT_NVAR(type);
		ZVAL_STRING(type, "count", 1);
		ZEPHIR_SINIT_VAR(_2$$5);
		ZVAL_LONG(&_2$$5, 7);
		ZEPHIR_INIT_NVAR(extraMethod);
		zephir_substr(extraMethod, method, 7 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	}
	ZEPHIR_INIT_VAR(modelName);
	zephir_get_called_class(modelName TSRMLS_CC);
	if (!(zephir_is_true(extraMethod))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(value);
	if (!(zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_3$$7);
		object_init_ex(_3$$7, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_4$$7);
		ZEPHIR_CONCAT_SVS(_4$$7, "The static method '", method, "' requires one argument");
		ZEPHIR_CALL_METHOD(NULL, _3$$7, "__construct", NULL, 9, _4$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$7, "phalcon/mvc/model.zep", 4337 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(model);
	zephir_fetch_safe_class(_5, modelName);
		_6 = zend_fetch_class(Z_STRVAL_P(_5), Z_STRLEN_P(_5), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(model, _6);
	if (zephir_has_constructor(model TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, model, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&metaData, model, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&attributes, metaData, "getreversecolumnmap", NULL, 0, model);
	zephir_check_call_status();
	if (Z_TYPE_P(attributes) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&attributes, metaData, "getdatatypes", NULL, 0, model);
		zephir_check_call_status();
	}
	if (zephir_array_isset(attributes, extraMethod)) {
		ZEPHIR_CPY_WRT(field, extraMethod);
	} else {
		ZEPHIR_CALL_FUNCTION(&extraMethodFirst, "lcfirst", NULL, 71, extraMethod);
		zephir_check_call_status();
		if (zephir_array_isset(attributes, extraMethodFirst)) {
			ZEPHIR_CPY_WRT(field, extraMethodFirst);
		} else {
			ZEPHIR_INIT_NVAR(field);
			zephir_uncamelize(field, extraMethod, NULL  );
			if (!(zephir_array_isset(attributes, field))) {
				ZEPHIR_INIT_VAR(_7$$13);
				object_init_ex(_7$$13, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(_8$$13);
				ZEPHIR_CONCAT_SVS(_8$$13, "Cannot resolve attribute '", extraMethod, "' in the model");
				ZEPHIR_CALL_METHOD(NULL, _7$$13, "__construct", NULL, 9, _8$$13);
				zephir_check_call_status();
				zephir_throw_exception_debug(_7$$13, "phalcon/mvc/model.zep", 4371 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_INIT_VAR(_9);
	zephir_create_array(_9, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_SVS(_10, "[", field, "] = ?0");
	zephir_array_update_string(&_9, SL("conditions"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_11);
	zephir_create_array(_11, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_11, value);
	zephir_array_update_string(&_9, SL("bind"), &_11, PH_COPY | PH_SEPARATE);
	_12 = zephir_fetch_class(modelName TSRMLS_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC_ZVAL(_12, type, NULL, 0, _9);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Handles method calls when a method is not implemented
 *
 * @param	string method
 * @param	array arguments
 * @return	mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *method_param = NULL, *arguments, *modelName = NULL, *status = NULL, *records = NULL, *_1, *_2, *_3;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &arguments);

	zephir_get_strval(method, method_param);


	ZEPHIR_CALL_SELF(&records, "_invokefinder", &_0, 340, method, arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(records) != IS_NULL) {
		RETURN_CCTOR(records);
	}
	ZEPHIR_INIT_VAR(modelName);
	zephir_get_class(modelName, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", NULL, 0, modelName, method, arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(records) != IS_NULL) {
		RETURN_CCTOR(records);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&status, _1, "missingmethod", NULL, 0, this_ptr, method, arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(status) != IS_NULL) {
		RETURN_CCTOR(status);
	}
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SVSVS(_3, "The method '", method, "' doesn't exist on model '", modelName, "'");
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 9, _3);
	zephir_check_call_status();
	zephir_throw_exception_debug(_2, "phalcon/mvc/model.zep", 4422 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Handles method calls when a static method is not implemented
 *
 * @param	string method
 * @param	array arguments
 * @return	mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, __callStatic) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *method_param = NULL, *arguments, *records = NULL, *_1$$3;
	zval *method = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &arguments);

	zephir_get_strval(method, method_param);


	ZEPHIR_CALL_SELF(&records, "_invokefinder", &_0, 340, method, arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(records) == IS_NULL) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SVS(_2$$3, "The static method '", method, "' doesn't exist");
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 9, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalcon/mvc/model.zep", 4438 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(records);

}

/**
 * Magic method to assign values to the the model
 *
 * @param string property
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_Model, __set) {

	HashTable *_2$$6;
	HashPosition _1$$6;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *value, *lowerProperty = NULL, *related = NULL, *modelName = NULL, *manager = NULL, *lowerKey = NULL, *relation = NULL, *referencedModel = NULL, *key = NULL, *item = NULL, *dirtyState = NULL, *_9 = NULL, *_10 = NULL, *_0$$4 = NULL, **_3$$6, *_4$$10 = NULL, *_6$$11 = NULL, *_8$$12, *_11$$14 = NULL, *_12$$15;
	zval *property = NULL, *_13$$15;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &value);

	zephir_get_strval(property, property_param);


	if (Z_TYPE_P(value) == IS_OBJECT) {
		if (zephir_instance_of_ev(value, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
			ZEPHIR_OBS_VAR(dirtyState);
			zephir_read_property_this(&dirtyState, this_ptr, SL("_dirtyState"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_0$$4, value, "getdirtystate", NULL, 0);
			zephir_check_call_status();
			if (!ZEPHIR_IS_EQUAL(_0$$4, dirtyState)) {
				ZEPHIR_INIT_NVAR(dirtyState);
				ZVAL_LONG(dirtyState, 1);
			}
			ZEPHIR_INIT_VAR(lowerProperty);
			zephir_fast_strtolower(lowerProperty, property);
			zephir_update_property_zval_zval(getThis(), lowerProperty, value TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("_related"), lowerProperty, value TSRMLS_CC);
			zephir_update_property_this(getThis(), SL("_dirtyState"), dirtyState TSRMLS_CC);
			RETVAL_ZVAL(value, 1, 0);
			RETURN_MM();
		}
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_NVAR(lowerProperty);
		zephir_fast_strtolower(lowerProperty, property);
		ZEPHIR_INIT_VAR(modelName);
		zephir_get_class(modelName, this_ptr, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(related);
		array_init(related);
		zephir_is_iterable(value, &_2$$6, &_1$$6, 0, 0, "phalcon/mvc/model.zep", 4498);
		for (
		  ; zend_hash_get_current_data_ex(_2$$6, (void**) &_3$$6, &_1$$6) == SUCCESS
		  ; zend_hash_move_forward_ex(_2$$6, &_1$$6)
		) {
			ZEPHIR_GET_HMKEY(key, _2$$6, _1$$6);
			ZEPHIR_GET_HVALUE(item, _3$$6);
			if (Z_TYPE_P(item) == IS_OBJECT) {
				if (zephir_instance_of_ev(item, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
					zephir_array_append(&related, item, PH_SEPARATE, "phalcon/mvc/model.zep", 4485);
				}
			} else {
				ZEPHIR_INIT_NVAR(lowerKey);
				zephir_fast_strtolower(lowerKey, key);
				zephir_update_property_zval_zval(getThis(), lowerKey, item TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_4$$10, manager, "getrelationbyalias", &_5, 0, modelName, lowerProperty);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(relation, _4$$10);
				if (Z_TYPE_P(relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&_6$$11, relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, manager, "load", &_7, 0, _6$$11);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, referencedModel, "writeattribute", NULL, 0, lowerKey, item);
					zephir_check_call_status();
				}
			}
		}
		if (zephir_fast_count_int(related TSRMLS_CC) > 0) {
			zephir_update_property_array(this_ptr, SL("_related"), lowerProperty, related TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_8$$12);
			ZVAL_LONG(_8$$12, 1);
			zephir_update_property_this(getThis(), SL("_dirtyState"), _8$$12 TSRMLS_CC);
		}
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "_possiblesetter", NULL, 330, property, value);
	zephir_check_call_status();
	if (zephir_is_true(_9)) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_10, "property_exists", NULL, 341, this_ptr, property);
	zephir_check_call_status();
	if (zephir_is_true(_10)) {
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_11$$14, manager, "isvisiblemodelproperty", NULL, 0, this_ptr, property);
		zephir_check_call_status();
		if (!(zephir_is_true(_11$$14))) {
			ZEPHIR_INIT_VAR(_12$$15);
			object_init_ex(_12$$15, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(_13$$15);
			ZEPHIR_CONCAT_SVS(_13$$15, "Property '", property, "' does not have a setter.");
			ZEPHIR_CALL_METHOD(NULL, _12$$15, "__construct", NULL, 9, _13$$15);
			zephir_check_call_status();
			zephir_throw_exception_debug(_12$$15, "phalcon/mvc/model.zep", 4515 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_update_property_zval_zval(getThis(), property, value TSRMLS_CC);
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * Check for, and attempt to use, possible setter.
 *
 * @param string property
 * @param mixed value
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, _possibleSetter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *value, *possibleSetter = NULL, *_0;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &value);

	zephir_get_strval(property, property_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_camelize(_0, property, NULL  );
	ZEPHIR_INIT_VAR(possibleSetter);
	ZEPHIR_CONCAT_SV(possibleSetter, "set", _0);
	if ((zephir_method_exists(this_ptr, possibleSetter TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, possibleSetter, NULL, 0, value);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Magic method to get related records using the relation alias as a property
 *
 * @param string property
 * @return \Phalcon\Mvc\Model\Resultset|Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, __get) {

	zend_bool _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *modelName = NULL, *manager = NULL, *lowerProperty = NULL, *relation = NULL, *result = NULL, *method = NULL, *_0 = NULL, *_6, *_7, *_2$$3, *_4$$3, *_5$$3, *_3$$4;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(property, property_param);
	} else {
		ZEPHIR_INIT_VAR(property);
		ZVAL_EMPTY_STRING(property);
	}


	ZEPHIR_INIT_VAR(modelName);
	zephir_get_class(modelName, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(lowerProperty);
	zephir_fast_strtolower(lowerProperty, property);
	ZEPHIR_CALL_METHOD(&_0, manager, "getrelationbyalias", NULL, 0, modelName, lowerProperty);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(relation, _0);
	if (Z_TYPE_P(relation) == IS_OBJECT) {
		_1$$3 = zephir_isset_property_zval(this_ptr, lowerProperty TSRMLS_CC);
		if (_1$$3) {
			ZEPHIR_OBS_VAR(_2$$3);
			zephir_read_property_zval(&_2$$3, this_ptr, lowerProperty, PH_NOISY_CC);
			_1$$3 = Z_TYPE_P(_2$$3) == IS_OBJECT;
		}
		if (_1$$3) {
			ZEPHIR_OBS_VAR(_3$$4);
			zephir_read_property_zval(&_3$$4, this_ptr, lowerProperty, PH_NOISY_CC);
			RETURN_CCTOR(_3$$4);
		}
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_NULL(_4$$3);
		ZEPHIR_INIT_VAR(_5$$3);
		ZVAL_NULL(_5$$3);
		ZEPHIR_CALL_METHOD(&result, manager, "getrelationrecords", NULL, 0, relation, _4$$3, this_ptr, _5$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(result) == IS_OBJECT) {
			zephir_update_property_zval_zval(getThis(), lowerProperty, result TSRMLS_CC);
			if (zephir_instance_of_ev(result, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
				zephir_update_property_array(this_ptr, SL("_related"), lowerProperty, result TSRMLS_CC);
			}
		}
		RETURN_CCTOR(result);
	}
	ZEPHIR_INIT_VAR(_6);
	zephir_camelize(_6, property, NULL  );
	ZEPHIR_INIT_VAR(method);
	ZEPHIR_CONCAT_SV(method, "get", _6);
	if ((zephir_method_exists(this_ptr, method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_SVSV(_7, "Access to undefined property ", modelName, "::", property);
	ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 2, _7);
	zephir_check_call_status();
	RETURN_MM_NULL();

}

/**
 * Magic method to check if a property is a valid relation
 */
PHP_METHOD(Phalcon_Mvc_Model, __isset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *modelName = NULL, *manager = NULL, *relation = NULL, *_0 = NULL;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(property, property_param);
	} else {
		ZEPHIR_INIT_VAR(property);
		ZVAL_EMPTY_STRING(property);
	}


	ZEPHIR_INIT_VAR(modelName);
	zephir_get_class(modelName, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_CALL_METHOD(&_0, manager, "getrelationbyalias", NULL, 0, modelName, property);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(relation, _0);
	RETURN_MM_BOOL(Z_TYPE_P(relation) == IS_OBJECT);

}

/**
 * Serializes the object ignoring connections, services, related objects or static properties
 */
PHP_METHOD(Phalcon_Mvc_Model, serialize) {

	zval *_2$$4;
	zend_bool _1$$3;
	zval *attributes = NULL, *snapshot = NULL, *manager = NULL, *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&attributes, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_CALL_METHOD(&_0, manager, "iskeepingsnapshots", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		ZEPHIR_OBS_VAR(snapshot);
		zephir_read_property_this(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
		_1$$3 = Z_TYPE_P(snapshot) != IS_NULL;
		if (_1$$3) {
			_1$$3 = !ZEPHIR_IS_EQUAL(attributes, snapshot);
		}
		if (_1$$3) {
			ZEPHIR_INIT_VAR(_2$$4);
			zephir_create_array(_2$$4, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&_2$$4, SL("_attributes"), &attributes, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_2$$4, SL("_snapshot"), &snapshot, PH_COPY | PH_SEPARATE);
			ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 68, _2$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 68, attributes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes the object from a serialized string
 */
PHP_METHOD(Phalcon_Mvc_Model, unserialize) {

	HashTable *_5$$3;
	HashPosition _4$$3;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, *attributes = NULL, *dependencyInjector = NULL, *manager = NULL, *key = NULL, *value = NULL, *snapshot = NULL, *_1$$3 = NULL, *_2$$3, **_6$$3, *_3$$7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_FUNCTION(&attributes, "unserialize", NULL, 69, data);
	zephir_check_call_status();
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
		zephir_check_call_status();
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model.zep", 4669);
			return;
		}
		zephir_update_property_this(getThis(), SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "modelsManager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1$$3, dependencyInjector, "getshared", NULL, 0, _2$$3);
		zephir_check_temp_parameter(_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(manager, _1$$3);
		if (Z_TYPE_P(manager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/mvc/model.zep", 4682);
			return;
		}
		zephir_update_property_this(getThis(), SL("_modelsManager"), manager TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, manager, "initialize", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, manager, "iskeepingsnapshots", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (zephir_is_true(_1$$3)) {
			if (zephir_array_isset_string_fetch(&snapshot, attributes, SS("_snapshot"), 1 TSRMLS_CC)) {
				zephir_update_property_this(getThis(), SL("_snapshot"), snapshot TSRMLS_CC);
				zephir_array_fetch_string(&_3$$7, attributes, SL("_attributes"), PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 4697 TSRMLS_CC);
				ZEPHIR_CPY_WRT(attributes, _3$$7);
			} else {
				zephir_update_property_this(getThis(), SL("_snapshot"), attributes TSRMLS_CC);
			}
		}
		zephir_is_iterable(attributes, &_5$$3, &_4$$3, 0, 0, "phalcon/mvc/model.zep", 4710);
		for (
		  ; zend_hash_get_current_data_ex(_5$$3, (void**) &_6$$3, &_4$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_5$$3, &_4$$3)
		) {
			ZEPHIR_GET_HMKEY(key, _5$$3, _4$$3);
			ZEPHIR_GET_HVALUE(value, _6$$3);
			zephir_update_property_zval_zval(getThis(), key, value TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a simple representation of the object that can be used with var_dump
 *
 *<code>
 * var_dump(
 *     $robot->dump()
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, dump) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 22, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the instance as an array representation
 *
 *<code>
 * print_r(
 *     $robot->toArray()
 * );
 *</code>
 *
 * @param array $columns
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model, toArray) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columns = NULL, *data = NULL, *metaData = NULL, *columnMap = NULL, *attribute = NULL, *attributeField = NULL, *value = NULL, *_0 = NULL, **_3, *_4$$6 = NULL, *_5$$6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &columns);

	if (!columns) {
		columns = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(data);
	array_init(data);
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 4778);
	for (
	  ; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(attribute, _3);
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, columnMap, attribute, 0 TSRMLS_CC))) {
				if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
					ZEPHIR_INIT_NVAR(_4$$6);
					object_init_ex(_4$$6, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5$$6);
					ZEPHIR_CONCAT_SVS(_5$$6, "Column '", attribute, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _4$$6, "__construct", &_6, 9, _5$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(_4$$6, "phalcon/mvc/model.zep", 4756 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					continue;
				}
			}
		} else {
			ZEPHIR_CPY_WRT(attributeField, attribute);
		}
		if (Z_TYPE_P(columns) == IS_ARRAY) {
			if (!(zephir_fast_in_array(attributeField, columns TSRMLS_CC))) {
				continue;
			}
		}
		ZEPHIR_OBS_NVAR(value);
		if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
			zephir_array_update_zval(&data, attributeField, &value, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&data, attributeField, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(data);

}

/**
 * Serializes the object for json_encode
 *
 *<code>
 * echo json_encode($robot);
 *</code>
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model, jsonSerialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Enables/disables options in the ORM
 */
PHP_METHOD(Phalcon_Mvc_Model, setup) {

	zval *options_param = NULL, *disableEvents = NULL, *columnRenaming = NULL, *notNullValidations = NULL, *exceptionOnFailedSave = NULL, *phqlLiterals = NULL, *virtualForeignKeys = NULL, *lateStateBinding = NULL, *castOnHydrate = NULL, *ignoreUnknownColumns = NULL, *updateSnapshotOnSave = NULL, *disableAssignSetters = NULL;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	options = options_param;


	ZEPHIR_OBS_VAR(disableEvents);
	if (zephir_array_isset_string_fetch(&disableEvents, options, SS("events"), 0 TSRMLS_CC)) {
		ZEPHIR_GLOBAL(orm).events = zend_is_true(disableEvents);
	}
	ZEPHIR_OBS_VAR(virtualForeignKeys);
	if (zephir_array_isset_string_fetch(&virtualForeignKeys, options, SS("virtualForeignKeys"), 0 TSRMLS_CC)) {
		ZEPHIR_GLOBAL(orm).virtual_foreign_keys = zend_is_true(virtualForeignKeys);
	}
	ZEPHIR_OBS_VAR(columnRenaming);
	if (zephir_array_isset_string_fetch(&columnRenaming, options, SS("columnRenaming"), 0 TSRMLS_CC)) {
		ZEPHIR_GLOBAL(orm).column_renaming = zend_is_true(columnRenaming);
	}
	ZEPHIR_OBS_VAR(notNullValidations);
	if (zephir_array_isset_string_fetch(&notNullValidations, options, SS("notNullValidations"), 0 TSRMLS_CC)) {
		ZEPHIR_GLOBAL(orm).not_null_validations = zend_is_true(notNullValidations);
	}
	ZEPHIR_OBS_VAR(exceptionOnFailedSave);
	if (zephir_array_isset_string_fetch(&exceptionOnFailedSave, options, SS("exceptionOnFailedSave"), 0 TSRMLS_CC)) {
		ZEPHIR_GLOBAL(orm).exception_on_failed_save = zend_is_true(exceptionOnFailedSave);
	}
	ZEPHIR_OBS_VAR(phqlLiterals);
	if (zephir_array_isset_string_fetch(&phqlLiterals, options, SS("phqlLiterals"), 0 TSRMLS_CC)) {
		ZEPHIR_GLOBAL(orm).enable_literals = zend_is_true(phqlLiterals);
	}
	ZEPHIR_OBS_VAR(lateStateBinding);
	if (zephir_array_isset_string_fetch(&lateStateBinding, options, SS("lateStateBinding"), 0 TSRMLS_CC)) {
		ZEPHIR_GLOBAL(orm).late_state_binding = zend_is_true(lateStateBinding);
	}
	ZEPHIR_OBS_VAR(castOnHydrate);
	if (zephir_array_isset_string_fetch(&castOnHydrate, options, SS("castOnHydrate"), 0 TSRMLS_CC)) {
		ZEPHIR_GLOBAL(orm).cast_on_hydrate = zend_is_true(castOnHydrate);
	}
	ZEPHIR_OBS_VAR(ignoreUnknownColumns);
	if (zephir_array_isset_string_fetch(&ignoreUnknownColumns, options, SS("ignoreUnknownColumns"), 0 TSRMLS_CC)) {
		ZEPHIR_GLOBAL(orm).ignore_unknown_columns = zend_is_true(ignoreUnknownColumns);
	}
	ZEPHIR_OBS_VAR(updateSnapshotOnSave);
	if (zephir_array_isset_string_fetch(&updateSnapshotOnSave, options, SS("updateSnapshotOnSave"), 0 TSRMLS_CC)) {
		ZEPHIR_GLOBAL(orm).update_snapshot_on_save = zend_is_true(updateSnapshotOnSave);
	}
	ZEPHIR_OBS_VAR(disableAssignSetters);
	if (zephir_array_isset_string_fetch(&disableAssignSetters, options, SS("disableAssignSetters"), 0 TSRMLS_CC)) {
		ZEPHIR_GLOBAL(orm).disable_assign_setters = zend_is_true(disableAssignSetters);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Reset a model instance data
 */
PHP_METHOD(Phalcon_Mvc_Model, reset) {

	

	zephir_update_property_this(getThis(), SL("_uniqueParams"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_snapshot"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);

}

