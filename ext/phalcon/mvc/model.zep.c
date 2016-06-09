
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
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"


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
 * $robot->type = 'mechanical';
 * $robot->name = 'Astro Boy';
 * $robot->year = 1952;
 * if ($robot->save() == false) {
 *  echo "Umh, We can store robots: ";
 *  foreach ($robot->getMessages() as $message) {
 *	 echo message;
 *  }
 * } else {
 *  echo "Great, a new robot was saved successfully!";
 * }
 * </code>
 *
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

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_NONE"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_CREATE"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_UPDATE"), 2);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_DELETE"), 3);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_PERSISTENT"), 0);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_TRANSIENT"), 1);

	zephir_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_DETACHED"), 2);

	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_mvc_entityinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_mvc_modelinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_mvc_model_resultinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, zend_ce_serializable);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("jsonserializable")));
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model constructor
 */
PHP_METHOD(Phalcon_Mvc_Model, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data = NULL, data_sub, *dependencyInjector = NULL, dependencyInjector_sub, *modelsManager = NULL, modelsManager_sub, __$null, _1$$5, _2$$5;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_UNDEF(&modelsManager_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &data, &dependencyInjector, &modelsManager);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!dependencyInjector) {
		dependencyInjector = &dependencyInjector_sub;
		ZEPHIR_CPY_WRT(dependencyInjector, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(dependencyInjector);
	}
	if (!modelsManager) {
		modelsManager = &modelsManager_sub;
		ZEPHIR_CPY_WRT(modelsManager, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(modelsManager);
	}


	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model.zep", 138);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);
	if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "modelsManager");
		ZEPHIR_CALL_METHOD(&_1$$5, dependencyInjector, "getshared", NULL, 0, &_2$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(modelsManager, &_1$$5);
		if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/mvc/model.zep", 149);
			return;
		}
	}
	zephir_update_property_zval(this_ptr, SL("_modelsManager"), modelsManager);
	ZEPHIR_CALL_METHOD(NULL, modelsManager, "initialize", NULL, 0, this_ptr);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, SL("onconstruct") TSRMLS_CC) == SUCCESS)) {
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

	zval *dependencyInjector, dependencyInjector_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dependencyInjector_sub);

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), dependencyInjector);

}

/**
 * Returns the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model, getDI) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets a custom events manager
 */
PHP_METHOD(Phalcon_Mvc_Model, setEventsManager) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *eventsManager, eventsManager_sub, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&eventsManager_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventsManager);



	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setcustomeventsmanager", NULL, 0, this_ptr, eventsManager);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the custom events manager
 */
PHP_METHOD(Phalcon_Mvc_Model, getEventsManager) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getcustomeventsmanager", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the models meta-data service related to the entity instance
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsMetaData) {

	zval metaData, dependencyInjector, _0$$3, _1$$3, _2$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&metaData);
	zephir_read_property(&metaData, this_ptr, SL("_modelsMetaData"), PH_NOISY_CC);
	if (Z_TYPE_P(&metaData) != IS_OBJECT) {
		zephir_read_property(&_0$$3, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&dependencyInjector, &_0$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "modelsMetadata");
		ZEPHIR_CALL_METHOD(&_1$$3, &dependencyInjector, "getshared", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&metaData, &_1$$3);
		if (Z_TYPE_P(&metaData) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsMetadata' is not valid", "phalcon/mvc/model.zep", 224);
			return;
		}
		zephir_update_property_zval(this_ptr, SL("_modelsMetaData"), &metaData);
	}
	RETURN_CCTOR(metaData);

}

/**
 * Returns the models manager related to the entity instance
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsManager) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_modelsManager");

}

/**
 * Sets a transaction related to the Model instance
 *
 *<code>
 *use Phalcon\Mvc\Model\Transaction\Manager as TxManager;
 *use Phalcon\Mvc\Model\Transaction\Failed as TxFailed;
 *
 *try {
 *
 *  $txManager = new TxManager();
 *
 *  $transaction = $txManager->get();
 *
 *  $robot = new Robots();
 *  $robot->setTransaction($transaction);
 *  $robot->name = 'WALL·E';
 *  $robot->created_at = date('Y-m-d');
 *  if ($robot->save() == false) {
 *	  $transaction->rollback("Can't save robot");
 *  }
 *
 *  $robotPart = new RobotParts();
 *  $robotPart->setTransaction($transaction);
 *  $robotPart->type = 'head';
 *  if ($robotPart->save() == false) {
 *	  $transaction->rollback("Robot part cannot be saved");
 *  }
 *
 *  $transaction->commit();
 *
 *} catch (TxFailed $e) {
 *  echo 'Failed, reason: ', $e->getMessage();
 *}
 *
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, setTransaction) {

	zval *transaction, transaction_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&transaction_sub);

	zephir_fetch_params(0, 1, 0, &transaction);



	zephir_update_property_zval(this_ptr, SL("_transaction"), transaction);
	RETURN_THISW();

}

/**
 * Sets table name which model should be mapped
 */
PHP_METHOD(Phalcon_Mvc_Model, setSource) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, _0;
	zval source;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &source_param);

	if (unlikely(Z_TYPE_P(source_param) != IS_STRING && Z_TYPE_P(source_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(source_param) == IS_STRING)) {
		zephir_get_strval(&source, source_param);
	} else {
		ZEPHIR_INIT_VAR(&source);
		ZVAL_EMPTY_STRING(&source);
	}


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setmodelsource", NULL, 0, this_ptr, &source);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Returns table name mapped in the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getSource) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getmodelsource", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets schema name where table mapped is located
 */
PHP_METHOD(Phalcon_Mvc_Model, setSchema) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *schema_param = NULL, _0;
	zval schema;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &schema_param);

	if (unlikely(Z_TYPE_P(schema_param) != IS_STRING && Z_TYPE_P(schema_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schema_param) == IS_STRING)) {
		zephir_get_strval(&schema, schema_param);
	} else {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_EMPTY_STRING(&schema);
	}


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "setmodelschema", NULL, 0, this_ptr, &schema);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns schema name where table mapped is located
 */
PHP_METHOD(Phalcon_Mvc_Model, getSchema) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getmodelschema", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the DependencyInjection connection service name
 */
PHP_METHOD(Phalcon_Mvc_Model, setConnectionService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, _0;
	zval connectionService;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&connectionService);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
		ZVAL_EMPTY_STRING(&connectionService);
	}


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setconnectionservice", NULL, 0, this_ptr, &connectionService);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets the DependencyInjection connection service name used to read data
 */
PHP_METHOD(Phalcon_Mvc_Model, setReadConnectionService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, _0;
	zval connectionService;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&connectionService);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
		ZVAL_EMPTY_STRING(&connectionService);
	}


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setreadconnectionservice", NULL, 0, this_ptr, &connectionService);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Sets the DependencyInjection connection service name used to write data
 */
PHP_METHOD(Phalcon_Mvc_Model, setWriteConnectionService) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, _0;
	zval connectionService;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&connectionService);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
		zephir_get_strval(&connectionService, connectionService_param);
	} else {
		ZEPHIR_INIT_VAR(&connectionService);
		ZVAL_EMPTY_STRING(&connectionService);
	}


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "setwriteconnectionservice", NULL, 0, this_ptr, &connectionService);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the DependencyInjection connection service name used to read data related the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnectionService) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getreadconnectionservice", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the DependencyInjection connection service name used to write data related to the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnectionService) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getwriteconnectionservice", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
 */
PHP_METHOD(Phalcon_Mvc_Model, setDirtyState) {

	zval *dirtyState_param = NULL, _0;
	int dirtyState;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &dirtyState_param);

	dirtyState = zephir_get_intval(dirtyState_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, dirtyState);
	zephir_update_property_zval(this_ptr, SL("_dirtyState"), &_0);
	RETURN_THISW();

}

/**
 * Returns one of the DIRTY_STATE_* constants telling if the record exists in the database or not
 */
PHP_METHOD(Phalcon_Mvc_Model, getDirtyState) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_dirtyState");

}

/**
 * Gets the connection used to read data for the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnection) {

	zval transaction, _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_transaction"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&transaction, &_0);
	if (Z_TYPE_P(&transaction) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(&transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getreadconnection", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets the connection used to write data to the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnection) {

	zval transaction, _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_transaction"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&transaction, &_0);
	if (Z_TYPE_P(&transaction) == IS_OBJECT) {
		ZEPHIR_RETURN_CALL_METHOD(&transaction, "getconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getwriteconnection", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Assigns values to a model from an array
 *
 * <code>
 * $robot->assign(array(
 *	'type' => 'mechanical',
 *	'name' => 'Astro Boy',
 *	'year' => 1952
 * ));
 *
 * //assign by db row, column map needed
 * $robot->assign($dbRow, array(
 *	'db_type' => 'type',
 *	'db_name' => 'name',
 *	'db_year' => 'year'
 * ));
 *
 * //allow assign only name and year
 * $robot->assign($_POST, null, array('name', 'year');
 *</code>
 *
 * @param array data
 * @param array dataColumnMap array to transform keys of data to another
 * @param array whiteList
 * @return \Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, assign) {

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_fcall_cache_entry *_7 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *dataColumnMap = NULL, dataColumnMap_sub, *whiteList = NULL, whiteList_sub, __$null, key, keyMapped, value, attribute, attributeField, metaData, columnMap, dataMapped, _3, *_4, *_0$$3, _5$$13, _6$$13, _8$$16;
	zval data;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&dataColumnMap_sub);
	ZVAL_UNDEF(&whiteList_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keyMapped);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&dataMapped);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$13);
	ZVAL_UNDEF(&_6$$13);
	ZVAL_UNDEF(&_8$$16);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &data_param, &dataColumnMap, &whiteList);

	ZEPHIR_OBS_VAR_ONCE(&data);
	ZVAL_COPY(&data, data_param);
	if (!dataColumnMap) {
		dataColumnMap = &dataColumnMap_sub;
		dataColumnMap = &__$null;
	}
	if (!whiteList) {
		whiteList = &whiteList_sub;
		whiteList = &__$null;
	}


	if (Z_TYPE_P(dataColumnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&dataMapped);
		array_init(&dataMapped);
		zephir_is_iterable(&data, 0, "phalcon/mvc/model.zep", 445);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _2$$3);
			} else {
				ZVAL_LONG(&key, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0$$3);
			ZEPHIR_OBS_NVAR(&keyMapped);
			if (zephir_array_isset_fetch(&keyMapped, dataColumnMap, &key, 0 TSRMLS_CC)) {
				zephir_array_update_zval(&dataMapped, &keyMapped, &value, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_CPY_WRT(&dataMapped, &data);
	}
	if (zephir_fast_count_int(&dataMapped TSRMLS_CC) == 0) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	ZEPHIR_CALL_METHOD(&_3, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_3, 0, "phalcon/mvc/model.zep", 494);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_3), _4)
	{
		ZEPHIR_INIT_NVAR(&attribute);
		ZVAL_COPY(&attribute, _4);
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0 TSRMLS_CC))) {
				if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
					ZEPHIR_INIT_NVAR(&_5$$13);
					object_init_ex(&_5$$13, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_6$$13);
					ZEPHIR_CONCAT_SVS(&_6$$13, "Column '", &attribute, "' doesn\\'t make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_5$$13, "__construct", &_7, 9, &_6$$13);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_5$$13, "phalcon/mvc/model.zep", 467 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					continue;
				}
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, &attribute);
		}
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_array_isset_fetch(&value, &dataMapped, &attributeField, 0 TSRMLS_CC)) {
			if (Z_TYPE_P(whiteList) == IS_ARRAY) {
				if (!(zephir_fast_in_array(&attributeField, whiteList TSRMLS_CC))) {
					continue;
				}
			}
			ZEPHIR_CALL_METHOD(&_8$$16, this_ptr, "_possiblesetter", &_9, 314, &attributeField, &value);
			zephir_check_call_status();
			if (!(zephir_is_true(&_8$$16))) {
				zephir_update_property_zval_zval(this_ptr, &attributeField, &value TSRMLS_CC);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&attribute);
	RETURN_THIS();

}

/**
 * Assigns values to a model from an array returning a new model.
 *
 *<code>
 *$robot = \Phalcon\Mvc\Model::cloneResultMap(new Robots(), array(
 *  'type' => 'mechanical',
 *  'name' => 'Astro Boy',
 *  'year' => 1952
 *));
 *</code>
 *
 * @param \Phalcon\Mvc\ModelInterface|\Phalcon\Mvc\Model\Row base
 * @param array data
 * @param array columnMap
 * @param int dirtyState
 * @param boolean keepSnapshots
 * @return \Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMap) {

	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_6 = NULL, *_10 = NULL;
	zend_bool keepSnapshots, _7$$4;
	int dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *columnMap, columnMap_sub, *dirtyState_param = NULL, *keepSnapshots_param = NULL, instance, attribute, key, value, castValue, attributeName, _0, *_1, _4$$7, _5$$7, _8$$10, _9$$11, _11$$15, _12$$19;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&castValue);
	ZVAL_UNDEF(&attributeName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_11$$15);
	ZVAL_UNDEF(&_12$$19);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &base, &data_param, &columnMap, &dirtyState_param, &keepSnapshots_param);

	ZEPHIR_OBS_VAR_ONCE(&data);
	ZVAL_COPY(&data, data_param);
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


	ZEPHIR_INIT_VAR(&instance);
	if (zephir_clone(&instance, base TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZVAL_LONG(&_0, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, &instance, "setdirtystate", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "phalcon/mvc/model.zep", 594);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		if (Z_TYPE_P(&key) == IS_STRING) {
			if (Z_TYPE_P(columnMap) != IS_ARRAY) {
				zephir_update_property_zval_zval(&instance, &key, &value TSRMLS_CC);
				continue;
			}
			ZEPHIR_OBS_NVAR(&attribute);
			if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0 TSRMLS_CC))) {
				if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
					ZEPHIR_INIT_NVAR(&_4$$7);
					object_init_ex(&_4$$7, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5$$7);
					ZEPHIR_CONCAT_SVS(&_5$$7, "Column '", &key, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", &_6, 9, &_5$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_4$$7, "phalcon/mvc/model.zep", 537 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					continue;
				}
			}
			if (Z_TYPE_P(&attribute) != IS_ARRAY) {
				zephir_update_property_zval_zval(&instance, &attribute, &value TSRMLS_CC);
				continue;
			}
			_7$$4 = !ZEPHIR_IS_STRING(&value, "");
			if (_7$$4) {
				_7$$4 = Z_TYPE_P(&value) != IS_NULL;
			}
			if (_7$$4) {
				zephir_array_fetch_long(&_8$$10, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 549 TSRMLS_CC);
				do {
					if (ZEPHIR_IS_LONG(&_8$$10, 0)) {
						ZVAL_LONG(&_9$$11, 10);
						ZEPHIR_CALL_FUNCTION(&castValue, "intval", &_10, 26, &value, &_9$$11);
						zephir_check_call_status();
						break;
					}
					if (ZEPHIR_IS_LONG(&_8$$10, 9) || ZEPHIR_IS_LONG(&_8$$10, 3) || ZEPHIR_IS_LONG(&_8$$10, 7)) {
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_DOUBLE(&castValue, zephir_get_doubleval(&value));
						break;
					}
					if (ZEPHIR_IS_LONG(&_8$$10, 8)) {
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_BOOL(&castValue, zephir_get_boolval(&value));
						break;
					}
					ZEPHIR_CPY_WRT(&castValue, &value);
					break;
				} while(0);

			} else {
				zephir_array_fetch_long(&_11$$15, &attribute, 1, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 570 TSRMLS_CC);
				do {
					if (ZEPHIR_IS_LONG(&_11$$15, 0) || ZEPHIR_IS_LONG(&_11$$15, 9) || ZEPHIR_IS_LONG(&_11$$15, 3) || ZEPHIR_IS_LONG(&_11$$15, 7) || ZEPHIR_IS_LONG(&_11$$15, 8)) {
						ZEPHIR_INIT_NVAR(&castValue);
						ZVAL_NULL(&castValue);
						break;
					}
					ZEPHIR_CPY_WRT(&castValue, &value);
					break;
				} while(0);

			}
			ZEPHIR_OBS_NVAR(&attributeName);
			zephir_array_fetch_long(&attributeName, &attribute, 0, PH_NOISY, "phalcon/mvc/model.zep", 586 TSRMLS_CC);
			zephir_update_property_zval_zval(&instance, &attributeName, &castValue TSRMLS_CC);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (keepSnapshots) {
		ZEPHIR_CALL_METHOD(NULL, &instance, "setsnapshotdata", NULL, 0, &data, columnMap);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(&instance, SL("fireevent") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_12$$19);
		ZVAL_STRING(&_12$$19, "afterFetch");
		ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_12$$19);
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

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_5 = NULL;
	int hydrationMode, ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap, columnMap_sub, *hydrationMode_param = NULL, hydrateArray, hydrateObject, key, value, attribute, *_0, _3$$11, _4$$11;
	zval data;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_UNDEF(&hydrateArray);
	ZVAL_UNDEF(&hydrateObject);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_3$$11);
	ZVAL_UNDEF(&_4$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data_param, &columnMap, &hydrationMode_param);

	ZEPHIR_OBS_VAR_ONCE(&data);
	ZVAL_COPY(&data, data_param);
	hydrationMode = zephir_get_intval(hydrationMode_param);


	if (Z_TYPE_P(columnMap) != IS_ARRAY) {
		if (hydrationMode == 1) {
			RETURN_CTOR(data);
		}
	}
	if (hydrationMode == 1) {
		ZEPHIR_INIT_VAR(&hydrateArray);
		array_init(&hydrateArray);
	} else {
		ZEPHIR_INIT_VAR(&hydrateObject);
		object_init(&hydrateObject);
	}
	zephir_is_iterable(&data, 0, "phalcon/mvc/model.zep", 668);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		if (Z_TYPE_P(&key) == IS_STRING) {
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0 TSRMLS_CC))) {
					if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
						ZEPHIR_INIT_NVAR(&_3$$11);
						object_init_ex(&_3$$11, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_4$$11);
						ZEPHIR_CONCAT_SVS(&_4$$11, "Column '", &key, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_3$$11, "__construct", &_5, 9, &_4$$11);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_3$$11, "phalcon/mvc/model.zep", 647 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					} else {
						continue;
					}
				}
				if (hydrationMode == 1) {
					zephir_array_update_zval(&hydrateArray, &attribute, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_update_property_zval_zval(&hydrateObject, &attribute, &value TSRMLS_CC);
				}
			} else {
				if (hydrationMode == 1) {
					zephir_array_update_zval(&hydrateArray, &key, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_update_property_zval_zval(&hydrateObject, &key, &value TSRMLS_CC);
				}
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	if (hydrationMode == 1) {
		RETURN_CCTOR(hydrateArray);
	}
	RETURN_CCTOR(hydrateObject);

}

/**
 * Assigns values to a model from an array returning a new model
 *
 *<code>
 *$robot = Phalcon\Mvc\Model::cloneResult(new Robots(), array(
 *  'type' => 'mechanical',
 *  'name' => 'Astro Boy',
 *  'year' => 1952
 *));
 *</code>
 *
 * @param \Phalcon\Mvc\ModelInterface $base
 * @param array data
 * @param int dirtyState
 * @return \Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResult) {

	zend_string *_3;
	zend_ulong _2;
	int dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *base, base_sub, *data_param = NULL, *dirtyState_param = NULL, instance, key, value, _0, *_1, _4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &base, &data_param, &dirtyState_param);

	ZEPHIR_OBS_VAR_ONCE(&data);
	ZVAL_COPY(&data, data_param);
	if (!dirtyState_param) {
		dirtyState = 0;
	} else {
		dirtyState = zephir_get_intval(dirtyState_param);
	}


	ZEPHIR_INIT_VAR(&instance);
	if (zephir_clone(&instance, base TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZVAL_LONG(&_0, dirtyState);
	ZEPHIR_CALL_METHOD(NULL, &instance, "setdirtystate", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "phalcon/mvc/model.zep", 715);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		if (Z_TYPE_P(&key) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid key in array data provided to dumpResult()", "phalcon/mvc/model.zep", 707);
			return;
		}
		zephir_update_property_zval_zval(&instance, &key, &value TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "afterFetch");
	ZEPHIR_CALL_METHOD(NULL, &instance, "fireevent", NULL, 0, &_4);
	zephir_check_call_status();
	RETURN_CCTOR(instance);

}

/**
 * Allows to query a set of records that match the specified conditions
 *
 * <code>
 *
 * //How many robots are there?
 * $robots = Robots::find();
 * echo "There are ", count($robots), "\n";
 *
 * //How many mechanical robots are there?
 * $robots = Robots::find("type='mechanical'");
 * echo "There are ", count($robots), "\n";
 *
 * //Get and print virtual robots ordered by name
 * $robots = Robots::find(array("type='virtual'", "order" => "name"));
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 *
 * //Get first 100 virtual robots ordered by name
 * $robots = Robots::find(array("type='virtual'", "order" => "name", "limit" => 100));
 * foreach ($robots as $robot) {
 *	   echo $robot->name, "\n";
 * }
 * </code>
 *
 * @param 	array parameters
 * @return  Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, find) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters = NULL, parameters_sub, __$null, params, builder, query, bindParams, bindTypes, cache, resultset, hydration, dependencyInjector, manager, _1, _2, _3$$7, _4$$9;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&hydration);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "modelsManager");
	ZEPHIR_CALL_METHOD(&_1, &dependencyInjector, "getshared", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/mvc/model.zep", 759);
		}
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_CALL_METHOD(&builder, &manager, "createbuilder", NULL, 0, &params);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	zephir_get_called_class(&_2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &builder, "from", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, &builder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, &params, SL("bind"), 0)) {
		if (Z_TYPE_P(&bindParams) == IS_ARRAY) {
			ZVAL_BOOL(&_3$$7, 1);
			ZEPHIR_CALL_METHOD(NULL, &query, "setbindparams", NULL, 0, &bindParams, &_3$$7);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(&bindTypes);
		if (zephir_array_isset_string_fetch(&bindTypes, &params, SL("bindTypes"), 0)) {
			if (Z_TYPE_P(&bindTypes) == IS_ARRAY) {
				ZVAL_BOOL(&_4$$9, 1);
				ZEPHIR_CALL_METHOD(NULL, &query, "setbindtypes", NULL, 0, &bindTypes, &_4$$9);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_OBS_VAR(&cache);
	if (zephir_array_isset_string_fetch(&cache, &params, SL("cache"), 0)) {
		ZEPHIR_CALL_METHOD(NULL, &query, "cache", NULL, 0, &cache);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&resultset, &query, "execute", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(&resultset) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(&hydration);
		if (zephir_array_isset_string_fetch(&hydration, &params, SL("hydration"), 0)) {
			ZEPHIR_CALL_METHOD(NULL, &resultset, "sethydratemode", NULL, 0, &hydration);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(resultset);

}

/**
 * Allows to query the first record that match the specified conditions
 *
 * <code>
 *
 * //What's the first robot in robots table?
 * $robot = Robots::findFirst();
 * echo "The robot name is ", $robot->name;
 *
 * //What's the first mechanical robot in robots table?
 * $robot = Robots::findFirst("type='mechanical'");
 * echo "The first mechanical robot name is ", $robot->name;
 *
 * //Get first virtual robot ordered by name
 * $robot = Robots::findFirst(array("type='virtual'", "order" => "name"));
 * echo "The first virtual robot name is ", $robot->name;
 *
 * </code>
 *
 * @param string|array parameters
 * @return static
 */
PHP_METHOD(Phalcon_Mvc_Model, findFirst) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters = NULL, parameters_sub, __$null, params, builder, query, bindParams, bindTypes, cache, dependencyInjector, manager, _1, _2, _3, _4$$7, _5$$9;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "modelsManager");
	ZEPHIR_CALL_METHOD(&_1, &dependencyInjector, "getshared", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/mvc/model.zep", 846);
		}
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_CALL_METHOD(&builder, &manager, "createbuilder", NULL, 0, &params);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	zephir_get_called_class(&_2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &builder, "from", NULL, 0, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &builder, "limit", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, &builder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, &params, SL("bind"), 0)) {
		if (Z_TYPE_P(&bindParams) == IS_ARRAY) {
			ZVAL_BOOL(&_4$$7, 1);
			ZEPHIR_CALL_METHOD(NULL, &query, "setbindparams", NULL, 0, &bindParams, &_4$$7);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(&bindTypes);
		if (zephir_array_isset_string_fetch(&bindTypes, &params, SL("bindTypes"), 0)) {
			if (Z_TYPE_P(&bindTypes) == IS_ARRAY) {
				ZVAL_BOOL(&_5$$9, 1);
				ZEPHIR_CALL_METHOD(NULL, &query, "setbindtypes", NULL, 0, &bindTypes, &_5$$9);
				zephir_check_call_status();
			}
		}
	}
	ZEPHIR_OBS_VAR(&cache);
	if (zephir_array_isset_string_fetch(&cache, &params, SL("cache"), 0)) {
		ZEPHIR_CALL_METHOD(NULL, &query, "cache", NULL, 0, &cache);
		zephir_check_call_status();
	}
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &query, "setuniquerow", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&query, "execute", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Create a criteria for a specific model
 */
PHP_METHOD(Phalcon_Mvc_Model, query) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *dependencyInjector = NULL, dependencyInjector_sub, __$null, criteria, _3, _1$$4, _2$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&criteria);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		dependencyInjector = &dependencyInjector_sub;
		ZEPHIR_CPY_WRT(dependencyInjector, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(dependencyInjector);
	}


	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&criteria);
	if (zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "Phalcon\\Mvc\\Model\\Criteria");
		ZEPHIR_CALL_METHOD(&_1$$4, dependencyInjector, "get", NULL, 0, &_2$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&criteria, &_1$$4);
	} else {
		object_init_ex(&criteria, phalcon_mvc_model_criteria_ce);
		if (zephir_has_constructor(&criteria TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &criteria, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, &criteria, "setdi", NULL, 315, dependencyInjector);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_get_called_class(&_3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &criteria, "setmodelname", NULL, 316, &_3);
	zephir_check_call_status();
	RETURN_CCTOR(criteria);

}

/**
 * Checks if the current record already exists or not
 *
 * @param \Phalcon\Mvc\Model\MetaDataInterface metaData
 * @param \Phalcon\Db\AdapterInterface connection
 * @param string|array table
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _exists) {

	zend_bool _4$$11;
	zephir_fcall_cache_entry *_3 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, numberEmpty = 0, numberPrimary = 0;
	zval *metaData, metaData_sub, *connection, connection_sub, *table = NULL, table_sub, __$null, uniqueParams, uniqueTypes, uniqueKey, columnMap, primaryKeys, wherePk, field, attributeField, value, bindDataTypes, joinWhere, num, type, schema, source, _10, _11, _12, _13, _14, *_0$$3, _1$$9, _2$$9, _5$$14, _6$$14, _7$$7, _9$$7, _15$$22, _16$$23;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&metaData_sub);
	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&table_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&uniqueParams);
	ZVAL_UNDEF(&uniqueTypes);
	ZVAL_UNDEF(&uniqueKey);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&wherePk);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&joinWhere);
	ZVAL_UNDEF(&num);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$9);
	ZVAL_UNDEF(&_2$$9);
	ZVAL_UNDEF(&_5$$14);
	ZVAL_UNDEF(&_6$$14);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_15$$22);
	ZVAL_UNDEF(&_16$$23);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &metaData, &connection, &table);

	if (!table) {
		table = &table_sub;
		ZEPHIR_CPY_WRT(table, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(table);
	}


	ZEPHIR_INIT_VAR(&uniqueParams);
	ZVAL_NULL(&uniqueParams);
	ZEPHIR_INIT_VAR(&uniqueTypes);
	ZVAL_NULL(&uniqueTypes);
	ZEPHIR_OBS_VAR(&uniqueKey);
	zephir_read_property(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	if (Z_TYPE_P(&uniqueKey) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, 0, this_ptr);
		zephir_check_call_status();
		numberPrimary = zephir_fast_count_int(&primaryKeys TSRMLS_CC);
		if (!(numberPrimary)) {
			RETURN_MM_BOOL(0);
		}
		if (ZEPHIR_GLOBAL(orm).column_renaming) {
			ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&columnMap);
			ZVAL_NULL(&columnMap);
		}
		numberEmpty = 0;
		ZEPHIR_INIT_VAR(&wherePk);
		array_init(&wherePk);
		ZEPHIR_INIT_NVAR(&uniqueParams);
		array_init(&uniqueParams);
		ZEPHIR_INIT_NVAR(&uniqueTypes);
		array_init(&uniqueTypes);
		zephir_is_iterable(&primaryKeys, 0, "phalcon/mvc/model.zep", 1017);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _0$$3)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _0$$3);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_1$$9);
					object_init_ex(&_1$$9, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_2$$9);
					ZEPHIR_CONCAT_SVS(&_2$$9, "Column '", &field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_1$$9, "__construct", &_3, 9, &_2$$9);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_1$$9, "phalcon/mvc/model.zep", 981 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &field);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_NULL(&value);
			ZEPHIR_OBS_NVAR(&value);
			if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
				_4$$11 = Z_TYPE_P(&value) == IS_NULL;
				if (!(_4$$11)) {
					_4$$11 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
				}
				if (_4$$11) {
					numberEmpty++;
				}
				zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 999);
			} else {
				zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/mvc/model.zep", 1002);
				numberEmpty++;
			}
			ZEPHIR_OBS_NVAR(&type);
			if (!(zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(&_5$$14);
				object_init_ex(&_5$$14, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_6$$14);
				ZEPHIR_CONCAT_SVS(&_6$$14, "Column '", &field, "' isn't part of the table columns");
				ZEPHIR_CALL_METHOD(NULL, &_5$$14, "__construct", &_3, 9, &_6$$14);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$14, "phalcon/mvc/model.zep", 1007 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalcon/mvc/model.zep", 1010);
			ZEPHIR_CALL_METHOD(&_7$$7, connection, "escapeidentifier", &_8, 0, &field);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_9$$7);
			ZEPHIR_CONCAT_VS(&_9$$7, &_7$$7, " = ?");
			zephir_array_append(&wherePk, &_9$$7, PH_SEPARATE, "phalcon/mvc/model.zep", 1011);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&field);
		if (numberPrimary == numberEmpty) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(&joinWhere);
		zephir_fast_join_str(&joinWhere, SL(" AND "), &wherePk TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_uniqueKey"), &joinWhere);
		zephir_update_property_zval(this_ptr, SL("_uniqueParams"), &uniqueParams);
		zephir_update_property_zval(this_ptr, SL("_uniqueTypes"), &uniqueTypes);
		ZEPHIR_CPY_WRT(&uniqueKey, &joinWhere);
	}
	zephir_read_property(&_10, this_ptr, SL("_dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_10))) {
		RETURN_MM_BOOL(1);
	}
	if (Z_TYPE_P(&uniqueKey) == IS_NULL) {
		ZEPHIR_OBS_NVAR(&uniqueKey);
		zephir_read_property(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(&uniqueParams) == IS_NULL) {
		ZEPHIR_OBS_NVAR(&uniqueParams);
		zephir_read_property(&uniqueParams, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(&uniqueTypes) == IS_NULL) {
		ZEPHIR_OBS_NVAR(&uniqueTypes);
		zephir_read_property(&uniqueTypes, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC);
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_NVAR(table);
		zephir_create_array(table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(table, &schema);
		zephir_array_fast_append(table, &source);
	} else {
		ZEPHIR_CPY_WRT(table, &source);
	}
	ZEPHIR_CALL_METHOD(&_11, connection, "escapeidentifier", NULL, 0, table);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_SVSV(&_12, "SELECT COUNT(*) \"rowcount\" FROM ", &_11, " WHERE ", &uniqueKey);
	ZVAL_NULL(&_13);
	ZEPHIR_CALL_METHOD(&num, connection, "fetchone", NULL, 0, &_12, &_13, &uniqueParams, &uniqueTypes);
	zephir_check_call_status();
	zephir_array_fetch_string(&_14, &num, SL("rowcount"), PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1067 TSRMLS_CC);
	if (zephir_is_true(&_14)) {
		ZEPHIR_INIT_ZVAL_NREF(_15$$22);
		ZVAL_LONG(&_15$$22, 0);
		zephir_update_property_zval(this_ptr, SL("_dirtyState"), &_15$$22);
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_16$$23);
		ZVAL_LONG(&_16$$23, 1);
		zephir_update_property_zval(this_ptr, SL("_dirtyState"), &_16$$23);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *functionName_param = NULL, *alias_param = NULL, *parameters, parameters_sub, params, distinctColumn, groupColumn, columns, bindParams, bindTypes, resultset, cache, firstRow, groupColumns, builder, query, dependencyInjector, manager, _1, _2, _3;
	zval functionName, alias;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&functionName);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&parameters_sub);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&distinctColumn);
	ZVAL_UNDEF(&groupColumn);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&firstRow);
	ZVAL_UNDEF(&groupColumns);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &functionName_param, &alias_param, &parameters);

	if (unlikely(Z_TYPE_P(functionName_param) != IS_STRING && Z_TYPE_P(functionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'functionName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(functionName_param) == IS_STRING)) {
		zephir_get_strval(&functionName, functionName_param);
	} else {
		ZEPHIR_INIT_VAR(&functionName);
		ZVAL_EMPTY_STRING(&functionName);
	}
	if (unlikely(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(&alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_EMPTY_STRING(&alias);
	}


	ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "modelsManager");
	ZEPHIR_CALL_METHOD(&_1, &dependencyInjector, "getshared", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	if (Z_TYPE_P(parameters) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/mvc/model.zep", 1097);
		}
	} else {
		ZEPHIR_CPY_WRT(&params, parameters);
	}
	ZEPHIR_OBS_VAR(&groupColumn);
	if (!(zephir_array_isset_string_fetch(&groupColumn, &params, SL("column"), 0))) {
		ZEPHIR_INIT_NVAR(&groupColumn);
		ZVAL_STRING(&groupColumn, "*");
	}
	ZEPHIR_OBS_VAR(&distinctColumn);
	if (zephir_array_isset_string_fetch(&distinctColumn, &params, SL("distinct"), 0)) {
		ZEPHIR_INIT_VAR(&columns);
		ZEPHIR_CONCAT_VSVSV(&columns, &functionName, "(DISTINCT ", &distinctColumn, ") AS ", &alias);
	} else {
		ZEPHIR_OBS_VAR(&groupColumns);
		ZEPHIR_INIT_NVAR(&columns);
		if (zephir_array_isset_string_fetch(&groupColumns, &params, SL("group"), 0)) {
			ZEPHIR_CONCAT_VSVSVSV(&columns, &groupColumns, ", ", &functionName, "(", &groupColumn, ") AS ", &alias);
		} else {
			ZEPHIR_CONCAT_VSVSV(&columns, &functionName, "(", &groupColumn, ") AS ", &alias);
		}
	}
	ZEPHIR_CALL_METHOD(&builder, &manager, "createbuilder", NULL, 0, &params);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &builder, "columns", NULL, 0, &columns);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	zephir_get_called_class(&_2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &builder, "from", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, &builder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&bindParams);
	ZVAL_NULL(&bindParams);
	ZEPHIR_INIT_VAR(&bindTypes);
	ZVAL_NULL(&bindTypes);
	ZEPHIR_OBS_NVAR(&bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, &params, SL("bind"), 0)) {
		ZEPHIR_OBS_NVAR(&bindTypes);
		zephir_array_isset_string_fetch(&bindTypes, &params, SL("bindTypes"), 0);
	}
	ZEPHIR_OBS_VAR(&cache);
	if (zephir_array_isset_string_fetch(&cache, &params, SL("cache"), 0)) {
		ZEPHIR_CALL_METHOD(NULL, &query, "cache", NULL, 0, &cache);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&resultset, &query, "execute", NULL, 0, &bindParams, &bindTypes);
	zephir_check_call_status();
	if (zephir_array_isset_string(&params, SL("group"))) {
		RETURN_CCTOR(resultset);
	}
	ZEPHIR_CALL_METHOD(&firstRow, &resultset, "getfirst", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property_zval(&_3, &firstRow, &alias, PH_NOISY_CC);
	RETURN_CCTOR(_3);

}

/**
 * Allows to count how many records match the specified conditions
 *
 * <code>
 *
 * //How many robots are there?
 * $number = Robots::count();
 * echo "There are ", $number, "\n";
 *
 * //How many mechanical robots are there?
 * $number = Robots::count("type = 'mechanical'");
 * echo "There are ", $number, " mechanical robots\n";
 *
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, count) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, result, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "COUNT");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "rowcount");
	ZEPHIR_CALL_SELF(&result, "_groupresult", NULL, 0, &_0, &_1, parameters);
	zephir_check_call_status();
	if (Z_TYPE_P(&result) == IS_STRING) {
		RETURN_MM_LONG(zephir_get_intval(&result));
	}
	RETURN_CCTOR(result);

}

/**
 * Allows to calculate a summatory on a column that match the specified conditions
 *
 * <code>
 *
 * //How much are all robots?
 * $sum = Robots::sum(array('column' => 'price'));
 * echo "The total price of robots is ", $sum, "\n";
 *
 * //How much are mechanical robots?
 * $sum = Robots::sum(array("type = 'mechanical'", 'column' => 'price'));
 * echo "The total price of mechanical robots is  ", $sum, "\n";
 *
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, sum) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "SUM");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "sumatory");
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, 0, &_0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to get the maximum value of a column that match the specified conditions
 *
 * <code>
 *
 * //What is the maximum robot id?
 * $id = Robots::maximum(array('column' => 'id'));
 * echo "The maximum robot id is: ", $id, "\n";
 *
 * //What is the maximum id of mechanical robots?
 * $sum = Robots::maximum(array("type='mechanical'", 'column' => 'id'));
 * echo "The maximum robot id of mechanical robots is ", $id, "\n";
 *
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, maximum) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "MAX");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "maximum");
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, 0, &_0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to get the minimum value of a column that match the specified conditions
 *
 * <code>
 *
 * //What is the minimum robot id?
 * $id = Robots::minimum(array('column' => 'id'));
 * echo "The minimum robot id is: ", $id;
 *
 * //What is the minimum id of mechanical robots?
 * $sum = Robots::minimum(array("type='mechanical'", 'column' => 'id'));
 * echo "The minimum robot id of mechanical robots is ", $id;
 *
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, minimum) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "MIN");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "minimum");
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, 0, &_0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Allows to calculate the average value on a column matching the specified conditions
 *
 * <code>
 *
 * //What's the average price of robots?
 * $average = Robots::average(array('column' => 'price'));
 * echo "The average price is ", $average, "\n";
 *
 * //What's the average price of mechanical robots?
 * $average = Robots::average(array("type='mechanical'", 'column' => 'price'));
 * echo "The average price of mechanical robots is ", $average, "\n";
 *
 * </code>
 *
 * @param array parameters
 * @return double
 */
PHP_METHOD(Phalcon_Mvc_Model, average) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, parameters_sub, __$null, _0, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&parameters_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = &parameters_sub;
		parameters = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "AVG");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "average");
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, 0, &_0, &_1, parameters);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEvent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, _0;
	zval eventName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

	if (unlikely(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(&eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(&eventName);
		ZVAL_EMPTY_STRING(&eventName);
	}


	if ((zephir_method_exists(this_ptr, &eventName TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &eventName, NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "notifyevent", NULL, 0, &eventName, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 * This method stops if one of the callbacks/listeners returns boolean false
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEventCancel) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, _0$$3, _1, _2;
	zval eventName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&eventName);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

	if (unlikely(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(&eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(&eventName);
		ZVAL_EMPTY_STRING(&eventName);
	}


	if ((zephir_method_exists(this_ptr, &eventName TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(&_0$$3, this_ptr, &eventName, NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	zephir_read_property(&_1, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "notifyevent", NULL, 0, &eventName, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_2)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Cancel the current operation
 */
PHP_METHOD(Phalcon_Mvc_Model, _cancelOperation) {

	zval _0, _1$$3, _3$$4;
	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_operationMade"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_LONG(&_0, 3)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "notDeleted");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_2, 0, &_1$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "notSaved");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_2, 0, &_3$$4);
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
 *
 *   public function beforeSave()
 *   {
 *	 if ($this->name == 'Peter') {
 *		$message = new Message("Sorry, but a robot cannot be named Peter");
 *		$this->appendMessage($message);
 *	 }
 *   }
 * }
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, appendMessage) {

	zval *message, message_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message_sub);

	zephir_fetch_params(0, 1, 0, &message);



	zephir_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Executes validators on every validation call
 *
 *<code>
 *use Phalcon\Mvc\Model;
 *use Phalcon\Validation;
 *use Phalcon\Validation\Validator\ExclusionIn;
 *
 *class Subscriptors extends Model
 *{
 *
 *	public function validation()
 *  {
 * 		$validator = new Validation();
 * 		$validator->add('status', new ExclusionIn(array(
 *			'domain' => array('A', 'I')
 *		)));
 *
 *		return $this->validate($validator);
 *	}
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, validate) {

	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL, *_6 = NULL, *_8 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *validator, validator_sub, messages, message, _0, _1$$3, _4$$4, _5$$4, _7$$4, _9$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&validator_sub);
	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &validator);



	ZVAL_NULL(&_0);
	ZEPHIR_CALL_METHOD(&messages, validator, "validate", NULL, 0, &_0, this_ptr);
	zephir_check_call_status();
	if (((Z_TYPE_P(&messages) == IS_TRUE || Z_TYPE_P(&messages) == IS_FALSE) != 1)) {
		ZEPHIR_CALL_METHOD(NULL, &messages, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1$$3, &messages, "valid", &_2, 0);
			zephir_check_call_status();
			if (!(zephir_is_true(&_1$$3))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&message, &messages, "current", &_3, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_4$$4);
			object_init_ex(&_4$$4, phalcon_mvc_model_message_ce);
			ZEPHIR_CALL_METHOD(&_5$$4, &message, "getmessage", &_6, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7$$4, &message, "getfield", &_8, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_9$$4, &message, "gettype", &_10, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", &_11, 8, &_5$$4, &_7$$4, &_9$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_12, 0, &_4$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &messages, "next", &_13, 0);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(!(zephir_fast_count_int(&messages TSRMLS_CC)));
	}
	RETURN_CCTOR(messages);

}

/**
 * Check whether validation process has generated any messages
 *
 *<code>
 *use Phalcon\Mvc\Model;
 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 *class Subscriptors extends Model
 *{
 *
 *	public function validation()
 *  {
 *      $validator = new Validation();
 *
 * 		$validator->validate('status', new ExclusionIn(array(
 *			'domain' => array('A', 'I')
 *		));

 *		return $this->validate($validator);
 *	}
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, validationHasFailed) {

	zval errorMessages;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&errorMessages);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&errorMessages);
	zephir_read_property(&errorMessages, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
	if (Z_TYPE_P(&errorMessages) == IS_ARRAY) {
		RETURN_MM_BOOL(zephir_fast_count_int(&errorMessages TSRMLS_CC) > 0);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns array of validation messages
 *
 *<code>
 *	$robot = new Robots();
 *	$robot->type = 'mechanical';
 *	$robot->name = 'Astro Boy';
 *	$robot->year = 1952;
 *	if ($robot->save() == false) {
 *  	echo "Umh, We can't store robots right now ";
 *  	foreach ($robot->getMessages() as $message) {
 *			echo $message;
 *		}
 *	} else {
 *  	echo "Great, a new robot was saved successfully!";
 *	}
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, getMessages) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *filter = NULL, filter_sub, __$null, filtered, message, _1$$3, *_2$$3, _3$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&filter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&filtered);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &filter);

	if (!filter) {
		filter = &filter_sub;
		filter = &__$null;
	}


	_0 = Z_TYPE_P(filter) == IS_STRING;
	if (_0) {
		_0 = !(ZEPHIR_IS_EMPTY(filter));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&filtered);
		array_init(&filtered);
		zephir_read_property(&_1$$3, this_ptr, SL("_errorMessages"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "phalcon/mvc/model.zep", 1485);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$3), _2$$3)
		{
			ZEPHIR_INIT_NVAR(&message);
			ZVAL_COPY(&message, _2$$3);
			ZEPHIR_CALL_METHOD(&_3$$4, &message, "getfield", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EQUAL(&_3$$4, filter)) {
				zephir_array_append(&filtered, &message, PH_SEPARATE, "phalcon/mvc/model.zep", 1482);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&message);
		RETURN_CCTOR(filtered);
	}
	RETURN_MM_MEMBER(this_ptr, "_errorMessages");

}

/**
 * Reads "belongs to" relations and check the virtual foreign keys when inserting or updating records
 * to verify that inserted/updated values are present in the related entity
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysRestrict) {

	zend_string *_7$$9;
	zend_ulong _6$$9;
	zval _13$$8;
	zend_bool error = 0, validateWithNulls, _11$$8;
	zval manager, belongsTo, foreignKey, relation, conditions, position, bindParams, extraConditions, message, fields, referencedFields, field, referencedModel, value, allowNulls, _0, *_1$$3, _2$$7, _3$$8, _12$$8, _14$$8, *_5$$9, _8$$10, _9$$10, _10$$12, _15$$20, _16$$18, _17$$18, _20$$23;
	zephir_fcall_cache_entry *_4 = NULL, *_18 = NULL, *_19 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, action = 0, numberNull = 0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&belongsTo);
	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&extraConditions);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&allowNulls);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_15$$20);
	ZVAL_UNDEF(&_16$$18);
	ZVAL_UNDEF(&_17$$18);
	ZVAL_UNDEF(&_20$$23);
	ZVAL_UNDEF(&_13$$8);

	ZEPHIR_MM_GROW();

	validateWithNulls = 0;
	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&belongsTo, &manager, "getbelongsto", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (zephir_fast_count_int(&belongsTo TSRMLS_CC)) {
		error = 0;
		zephir_is_iterable(&belongsTo, 0, "phalcon/mvc/model.zep", 1629);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&belongsTo), _1$$3)
		{
			ZEPHIR_INIT_NVAR(&relation);
			ZVAL_COPY(&relation, _1$$3);
			ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
				action = 1;
				if (Z_TYPE_P(&foreignKey) == IS_ARRAY) {
					if (zephir_array_isset_string(&foreignKey, SL("action"))) {
						ZEPHIR_OBS_NVAR(&_2$$7);
						zephir_array_fetch_string(&_2$$7, &foreignKey, SL("action"), PH_NOISY, "phalcon/mvc/model.zep", 1530 TSRMLS_CC);
						action = zephir_get_intval(&_2$$7);
					}
				}
				if (action == 1) {
					ZEPHIR_CALL_METHOD(&_3$$8, &relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_4, 0, &_3$$8);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&conditions);
					array_init(&conditions);
					ZEPHIR_INIT_NVAR(&bindParams);
					array_init(&bindParams);
					numberNull = 0;
					ZEPHIR_CALL_METHOD(&fields, &relation, "getfields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
					zephir_check_call_status();
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						zephir_is_iterable(&fields, 0, "phalcon/mvc/model.zep", 1566);
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _6$$9, _7$$9, _5$$9)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_7$$9 != NULL) { 
								ZVAL_STR_COPY(&position, _7$$9);
							} else {
								ZVAL_LONG(&position, _6$$9);
							}
							ZEPHIR_INIT_NVAR(&field);
							ZVAL_COPY(&field, _5$$9);
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_8$$10, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1559 TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_9$$10);
							ZEPHIR_CONCAT_SVSV(&_9$$10, "[", &_8$$10, "] = ?", &position);
							zephir_array_append(&conditions, &_9$$10, PH_SEPARATE, "phalcon/mvc/model.zep", 1559);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 1560);
							if (Z_TYPE_P(&value) == IS_NULL) {
								numberNull++;
							}
						} ZEND_HASH_FOREACH_END();
						ZEPHIR_INIT_NVAR(&field);
						ZEPHIR_INIT_NVAR(&position);
						validateWithNulls = numberNull == zephir_fast_count_int(&fields TSRMLS_CC);
					} else {
						ZEPHIR_OBS_NVAR(&value);
						zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
						ZEPHIR_INIT_LNVAR(_10$$12);
						ZEPHIR_CONCAT_SVS(&_10$$12, "[", &referencedFields, "] = ?0");
						zephir_array_append(&conditions, &_10$$12, PH_SEPARATE, "phalcon/mvc/model.zep", 1571);
						zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 1572);
						if (Z_TYPE_P(&value) == IS_NULL) {
							validateWithNulls = 1;
						}
					}
					ZEPHIR_OBS_NVAR(&extraConditions);
					if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
						zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/mvc/model.zep", 1583);
					}
					if (validateWithNulls) {
						ZEPHIR_OBS_NVAR(&allowNulls);
						if (zephir_array_isset_string_fetch(&allowNulls, &foreignKey, SL("allowNulls"), 0)) {
							validateWithNulls = zephir_get_boolval(&allowNulls);
						} else {
							validateWithNulls = 0;
						}
					}
					_11$$8 = !validateWithNulls;
					if (_11$$8) {
						ZEPHIR_INIT_NVAR(&_13$$8);
						zephir_create_array(&_13$$8, 2, 0 TSRMLS_CC);
						ZEPHIR_INIT_NVAR(&_14$$8);
						zephir_fast_join_str(&_14$$8, SL(" AND "), &conditions TSRMLS_CC);
						zephir_array_fast_append(&_13$$8, &_14$$8);
						zephir_array_update_string(&_13$$8, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(&_12$$8, &referencedModel, "count", NULL, 0, &_13$$8);
						zephir_check_call_status();
						_11$$8 = !zephir_is_true(&_12$$8);
					}
					if (_11$$8) {
						ZEPHIR_OBS_NVAR(&message);
						if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
							ZEPHIR_INIT_NVAR(&message);
							if (Z_TYPE_P(&fields) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(&_15$$20);
								zephir_fast_join_str(&_15$$20, SL(", "), &fields TSRMLS_CC);
								ZEPHIR_CONCAT_SVS(&message, "Value of fields \"", &_15$$20, "\" does not exist on referenced table");
							} else {
								ZEPHIR_CONCAT_SVS(&message, "Value of field \"", &fields, "\" does not exist on referenced table");
							}
						}
						ZEPHIR_INIT_NVAR(&_16$$18);
						object_init_ex(&_16$$18, phalcon_mvc_model_message_ce);
						ZEPHIR_INIT_NVAR(&_17$$18);
						ZVAL_STRING(&_17$$18, "ConstraintViolation");
						ZEPHIR_CALL_METHOD(NULL, &_16$$18, "__construct", &_18, 8, &message, &fields, &_17$$18);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_19, 0, &_16$$18);
						zephir_check_call_status();
						error = 1;
						break;
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&relation);
		if (error == 1) {
			if (ZEPHIR_GLOBAL(orm).events) {
				ZEPHIR_INIT_VAR(&_20$$23);
				ZVAL_STRING(&_20$$23, "onValidationFails");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_20$$23);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
				zephir_check_call_status();
			}
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (cascade) when deleting records
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseCascade) {

	zend_string *_7$$9;
	zend_ulong _6$$9;
	zval _11$$8;
	zval manager, relations, relation, foreignKey, resultset, conditions, bindParams, referencedModel, referencedFields, fields, field, position, value, extraConditions, _0, *_1$$3, _2$$7, _3$$8, _12$$8, _13$$8, *_5$$9, _8$$10, _9$$10, _10$$11;
	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, action = 0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&resultset);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&extraConditions);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$11);
	ZVAL_UNDEF(&_11$$8);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (zephir_fast_count_int(&relations TSRMLS_CC)) {
		zephir_is_iterable(&relations, 0, "phalcon/mvc/model.zep", 1743);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relations), _1$$3)
		{
			ZEPHIR_INIT_NVAR(&relation);
			ZVAL_COPY(&relation, _1$$3);
			ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
				action = 0;
				if (Z_TYPE_P(&foreignKey) == IS_ARRAY) {
					if (zephir_array_isset_string(&foreignKey, SL("action"))) {
						ZEPHIR_OBS_NVAR(&_2$$7);
						zephir_array_fetch_string(&_2$$7, &foreignKey, SL("action"), PH_NOISY, "phalcon/mvc/model.zep", 1682 TSRMLS_CC);
						action = zephir_get_intval(&_2$$7);
					}
				}
				if (action == 2) {
					ZEPHIR_CALL_METHOD(&_3$$8, &relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_4, 0, &_3$$8);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&fields, &relation, "getfields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&conditions);
					array_init(&conditions);
					ZEPHIR_INIT_NVAR(&bindParams);
					array_init(&bindParams);
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						zephir_is_iterable(&fields, 0, "phalcon/mvc/model.zep", 1710);
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _6$$9, _7$$9, _5$$9)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_7$$9 != NULL) { 
								ZVAL_STR_COPY(&position, _7$$9);
							} else {
								ZVAL_LONG(&position, _6$$9);
							}
							ZEPHIR_INIT_NVAR(&field);
							ZVAL_COPY(&field, _5$$9);
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_8$$10, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1707 TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_9$$10);
							ZEPHIR_CONCAT_SVSV(&_9$$10, "[", &_8$$10, "] = ?", &position);
							zephir_array_append(&conditions, &_9$$10, PH_SEPARATE, "phalcon/mvc/model.zep", 1707);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 1708);
						} ZEND_HASH_FOREACH_END();
						ZEPHIR_INIT_NVAR(&field);
						ZEPHIR_INIT_NVAR(&position);
					} else {
						ZEPHIR_OBS_NVAR(&value);
						zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
						ZEPHIR_INIT_LNVAR(_10$$11);
						ZEPHIR_CONCAT_SVS(&_10$$11, "[", &referencedFields, "] = ?0");
						zephir_array_append(&conditions, &_10$$11, PH_SEPARATE, "phalcon/mvc/model.zep", 1712);
						zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 1713);
					}
					ZEPHIR_OBS_NVAR(&extraConditions);
					if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
						zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/mvc/model.zep", 1720);
					}
					ZEPHIR_INIT_NVAR(&_11$$8);
					zephir_create_array(&_11$$8, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_12$$8);
					zephir_fast_join_str(&_12$$8, SL(" AND "), &conditions TSRMLS_CC);
					zephir_array_fast_append(&_11$$8, &_12$$8);
					zephir_array_update_string(&_11$$8, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&resultset, &referencedModel, "find", NULL, 0, &_11$$8);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_13$$8, &resultset, "delete", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(&_13$$8)) {
						RETURN_MM_BOOL(0);
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&relation);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (restrict) when deleting records
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseRestrict) {

	zval _11$$8;
	zend_string *_6$$9;
	zend_ulong _5$$9;
	zval manager, relations, foreignKey, relation, relationClass, referencedModel, fields, referencedFields, conditions, bindParams, position, field, value, extraConditions, message, _0, *_1$$3, _2$$7, *_4$$9, _7$$10, _8$$10, _9$$11, _10$$8, _12$$8, _13$$13, _14$$13, _17$$16;
	zend_bool error = 0;
	zephir_fcall_cache_entry *_3 = NULL, *_15 = NULL, *_16 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, action = 0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&foreignKey);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&relationClass);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bindParams);
	ZVAL_UNDEF(&position);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&extraConditions);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_17$$16);
	ZVAL_UNDEF(&_11$$8);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&relations, &manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (zephir_fast_count_int(&relations TSRMLS_CC)) {
		error = 0;
		zephir_is_iterable(&relations, 0, "phalcon/mvc/model.zep", 1862);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relations), _1$$3)
		{
			ZEPHIR_INIT_NVAR(&relation);
			ZVAL_COPY(&relation, _1$$3);
			ZEPHIR_CALL_METHOD(&foreignKey, &relation, "getforeignkey", NULL, 0);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&foreignKey)) {
				action = 1;
				if (Z_TYPE_P(&foreignKey) == IS_ARRAY) {
					if (zephir_array_isset_string(&foreignKey, SL("action"))) {
						ZEPHIR_OBS_NVAR(&_2$$7);
						zephir_array_fetch_string(&_2$$7, &foreignKey, SL("action"), PH_NOISY, "phalcon/mvc/model.zep", 1790 TSRMLS_CC);
						action = zephir_get_intval(&_2$$7);
					}
				}
				if (action == 1) {
					ZEPHIR_CALL_METHOD(&relationClass, &relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_3, 0, &relationClass);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&fields, &relation, "getfields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&conditions);
					array_init(&conditions);
					ZEPHIR_INIT_NVAR(&bindParams);
					array_init(&bindParams);
					if (Z_TYPE_P(&fields) == IS_ARRAY) {
						zephir_is_iterable(&fields, 0, "phalcon/mvc/model.zep", 1822);
						ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&fields), _5$$9, _6$$9, _4$$9)
						{
							ZEPHIR_INIT_NVAR(&position);
							if (_6$$9 != NULL) { 
								ZVAL_STR_COPY(&position, _6$$9);
							} else {
								ZVAL_LONG(&position, _5$$9);
							}
							ZEPHIR_INIT_NVAR(&field);
							ZVAL_COPY(&field, _4$$9);
							ZEPHIR_OBS_NVAR(&value);
							zephir_fetch_property_zval(&value, this_ptr, &field, PH_SILENT_CC);
							zephir_array_fetch(&_7$$10, &referencedFields, &position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1818 TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_8$$10);
							ZEPHIR_CONCAT_SVSV(&_8$$10, "[", &_7$$10, "] = ?", &position);
							zephir_array_append(&conditions, &_8$$10, PH_SEPARATE, "phalcon/mvc/model.zep", 1818);
							zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 1819);
						} ZEND_HASH_FOREACH_END();
						ZEPHIR_INIT_NVAR(&field);
						ZEPHIR_INIT_NVAR(&position);
					} else {
						ZEPHIR_OBS_NVAR(&value);
						zephir_fetch_property_zval(&value, this_ptr, &fields, PH_SILENT_CC);
						ZEPHIR_INIT_LNVAR(_9$$11);
						ZEPHIR_CONCAT_SVS(&_9$$11, "[", &referencedFields, "] = ?0");
						zephir_array_append(&conditions, &_9$$11, PH_SEPARATE, "phalcon/mvc/model.zep", 1824);
						zephir_array_append(&bindParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 1825);
					}
					ZEPHIR_OBS_NVAR(&extraConditions);
					if (zephir_array_isset_string_fetch(&extraConditions, &foreignKey, SL("conditions"), 0)) {
						zephir_array_append(&conditions, &extraConditions, PH_SEPARATE, "phalcon/mvc/model.zep", 1832);
					}
					ZEPHIR_INIT_NVAR(&_11$$8);
					zephir_create_array(&_11$$8, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_12$$8);
					zephir_fast_join_str(&_12$$8, SL(" AND "), &conditions TSRMLS_CC);
					zephir_array_fast_append(&_11$$8, &_12$$8);
					zephir_array_update_string(&_11$$8, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_10$$8, &referencedModel, "count", NULL, 0, &_11$$8);
					zephir_check_call_status();
					if (zephir_is_true(&_10$$8)) {
						ZEPHIR_OBS_NVAR(&message);
						if (!(zephir_array_isset_string_fetch(&message, &foreignKey, SL("message"), 0))) {
							ZEPHIR_INIT_NVAR(&message);
							ZEPHIR_CONCAT_SV(&message, "Record is referenced by model ", &relationClass);
						}
						ZEPHIR_INIT_NVAR(&_13$$13);
						object_init_ex(&_13$$13, phalcon_mvc_model_message_ce);
						ZEPHIR_INIT_NVAR(&_14$$13);
						ZVAL_STRING(&_14$$13, "ConstraintViolation");
						ZEPHIR_CALL_METHOD(NULL, &_13$$13, "__construct", &_15, 8, &message, &fields, &_14$$13);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_16, 0, &_13$$13);
						zephir_check_call_status();
						error = 1;
						break;
					}
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&relation);
		if (error == 1) {
			if (ZEPHIR_GLOBAL(orm).events) {
				ZEPHIR_INIT_VAR(&_17$$16);
				ZVAL_STRING(&_17$$16, "onValidationFails");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_17$$16);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
				zephir_check_call_status();
			}
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Executes internal hooks before save a record
 */
PHP_METHOD(Phalcon_Mvc_Model, _preSave) {

	zephir_fcall_cache_entry *_2 = NULL, *_11 = NULL, *_16 = NULL, *_18 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool exists, error = 0, isNull = 0, _12$$27;
	zval *metaData, metaData_sub, *exists_param = NULL, *identityField, identityField_sub, __$true, __$false, notNull, columnMap, dataTypeNumeric, automaticAttributes, defaultValues, field, attributeField, value, emptyStringValues, _19, _20, _0$$3, _1$$3, _3$$5, _4$$5, _5$$7, _6$$7, _7$$9, *_8$$12, _9$$20, _10$$20, _13$$32, _14$$32, _15$$32, _17$$37, _21$$39, _22$$41, _23$$41, _24$$43, _25$$43, _26$$40, _27$$40, _28$$40, _33$$40, _29$$47, _30$$47, _31$$49, _32$$49;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&metaData_sub);
	ZVAL_UNDEF(&identityField_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&notNull);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&dataTypeNumeric);
	ZVAL_UNDEF(&automaticAttributes);
	ZVAL_UNDEF(&defaultValues);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&emptyStringValues);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_9$$20);
	ZVAL_UNDEF(&_10$$20);
	ZVAL_UNDEF(&_13$$32);
	ZVAL_UNDEF(&_14$$32);
	ZVAL_UNDEF(&_15$$32);
	ZVAL_UNDEF(&_17$$37);
	ZVAL_UNDEF(&_21$$39);
	ZVAL_UNDEF(&_22$$41);
	ZVAL_UNDEF(&_23$$41);
	ZVAL_UNDEF(&_24$$43);
	ZVAL_UNDEF(&_25$$43);
	ZVAL_UNDEF(&_26$$40);
	ZVAL_UNDEF(&_27$$40);
	ZVAL_UNDEF(&_28$$40);
	ZVAL_UNDEF(&_33$$40);
	ZVAL_UNDEF(&_29$$47);
	ZVAL_UNDEF(&_30$$47);
	ZVAL_UNDEF(&_31$$49);
	ZVAL_UNDEF(&_32$$49);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &metaData, &exists_param, &identityField);

	exists = zephir_get_boolval(exists_param);


	if (ZEPHIR_GLOBAL(orm).events) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "beforeValidation");
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "fireeventcancel", &_2, 0, &_1$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_0$$3)) {
			RETURN_MM_BOOL(0);
		}
		if (!(exists)) {
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_STRING(&_4$$5, "beforeValidationOnCreate");
			ZEPHIR_CALL_METHOD(&_3$$5, this_ptr, "fireeventcancel", &_2, 0, &_4$$5);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$5)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_VAR(&_6$$7);
			ZVAL_STRING(&_6$$7, "beforeValidationOnUpdate");
			ZEPHIR_CALL_METHOD(&_5$$7, this_ptr, "fireeventcancel", &_2, 0, &_6$$7);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_5$$7)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_7$$9, this_ptr, "_checkforeignkeysrestrict", NULL, 317);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_7$$9)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GLOBAL(orm).not_null_validations) {
		ZEPHIR_CALL_METHOD(&notNull, metaData, "getnotnullattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (Z_TYPE_P(&notNull) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(&dataTypeNumeric, metaData, "getdatatypesnumeric", NULL, 0, this_ptr);
			zephir_check_call_status();
			if (ZEPHIR_GLOBAL(orm).column_renaming) {
				ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_NVAR(&columnMap);
				ZVAL_NULL(&columnMap);
			}
			if (exists) {
				ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticupdateattributes", NULL, 0, this_ptr);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&automaticAttributes, metaData, "getautomaticcreateattributes", NULL, 0, this_ptr);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&defaultValues, metaData, "getdefaultvalues", NULL, 0, this_ptr);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&emptyStringValues, metaData, "getemptystringattributes", NULL, 0, this_ptr);
			zephir_check_call_status();
			error = 0;
			zephir_is_iterable(&notNull, 0, "phalcon/mvc/model.zep", 2028);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&notNull), _8$$12)
			{
				ZEPHIR_INIT_NVAR(&field);
				ZVAL_COPY(&field, _8$$12);
				if (!(zephir_array_isset(&automaticAttributes, &field))) {
					isNull = 0;
					if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(&attributeField);
						if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(&_9$$20);
							object_init_ex(&_9$$20, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_10$$20);
							ZEPHIR_CONCAT_SVS(&_10$$20, "Column '", &field, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, &_9$$20, "__construct", &_11, 9, &_10$$20);
							zephir_check_call_status();
							zephir_throw_exception_debug(&_9$$20, "phalcon/mvc/model.zep", 1964 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(&attributeField, &field);
					}
					ZEPHIR_OBS_NVAR(&value);
					if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
						if (Z_TYPE_P(&value) != IS_OBJECT) {
							if (!(zephir_array_isset(&dataTypeNumeric, &field))) {
								if (zephir_array_isset(&emptyStringValues, &field)) {
									if (Z_TYPE_P(&value) == IS_NULL) {
										isNull = 1;
									}
								} else {
									_12$$27 = Z_TYPE_P(&value) == IS_NULL;
									if (!(_12$$27)) {
										_12$$27 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
									}
									if (_12$$27) {
										isNull = 1;
									}
								}
							} else {
								if (!(zephir_is_numeric(&value))) {
									isNull = 1;
								}
							}
						}
					} else {
						isNull = 1;
					}
					if (isNull == 1) {
						if (!(exists)) {
							if (ZEPHIR_IS_EQUAL(&field, identityField)) {
								continue;
							}
							if (zephir_array_isset(&defaultValues, &field)) {
								continue;
							}
						}
						ZEPHIR_INIT_NVAR(&_13$$32);
						object_init_ex(&_13$$32, phalcon_mvc_model_message_ce);
						ZEPHIR_INIT_LNVAR(_14$$32);
						ZEPHIR_CONCAT_VS(&_14$$32, &attributeField, " is required");
						ZEPHIR_INIT_NVAR(&_15$$32);
						ZVAL_STRING(&_15$$32, "PresenceOf");
						ZEPHIR_CALL_METHOD(NULL, &_13$$32, "__construct", &_16, 8, &_14$$32, &attributeField, &_15$$32);
						zephir_check_call_status();
						zephir_update_property_array_append(this_ptr, SL("_errorMessages"), &_13$$32 TSRMLS_CC);
						error = 1;
					}
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&field);
			if (error == 1) {
				if (ZEPHIR_GLOBAL(orm).events) {
					ZEPHIR_INIT_VAR(&_17$$37);
					ZVAL_STRING(&_17$$37, "onValidationFails");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_18, 0, &_17$$37);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
					zephir_check_call_status();
				}
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_VAR(&_20);
	ZVAL_STRING(&_20, "validation");
	ZEPHIR_CALL_METHOD(&_19, this_ptr, "fireeventcancel", &_2, 0, &_20);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_19)) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_VAR(&_21$$39);
			ZVAL_STRING(&_21$$39, "onValidationFails");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_18, 0, &_21$$39);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (!(exists)) {
			ZEPHIR_INIT_VAR(&_23$$41);
			ZVAL_STRING(&_23$$41, "afterValidationOnCreate");
			ZEPHIR_CALL_METHOD(&_22$$41, this_ptr, "fireeventcancel", &_2, 0, &_23$$41);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_22$$41)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_VAR(&_25$$43);
			ZVAL_STRING(&_25$$43, "afterValidationOnUpdate");
			ZEPHIR_CALL_METHOD(&_24$$43, this_ptr, "fireeventcancel", &_2, 0, &_25$$43);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_24$$43)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_INIT_VAR(&_27$$40);
		ZVAL_STRING(&_27$$40, "afterValidation");
		ZEPHIR_CALL_METHOD(&_26$$40, this_ptr, "fireeventcancel", &_2, 0, &_27$$40);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_26$$40)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(&_27$$40);
		ZVAL_STRING(&_27$$40, "beforeSave");
		ZEPHIR_CALL_METHOD(&_28$$40, this_ptr, "fireeventcancel", &_2, 0, &_27$$40);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_28$$40)) {
			RETURN_MM_BOOL(0);
		}
		if (0) {
			zephir_update_property_zval(this_ptr, SL("_skipped"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_skipped"), &__$false);
		}
		if (exists) {
			ZEPHIR_INIT_VAR(&_30$$47);
			ZVAL_STRING(&_30$$47, "beforeUpdate");
			ZEPHIR_CALL_METHOD(&_29$$47, this_ptr, "fireeventcancel", &_2, 0, &_30$$47);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_29$$47)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_VAR(&_32$$49);
			ZVAL_STRING(&_32$$49, "beforeCreate");
			ZEPHIR_CALL_METHOD(&_31$$49, this_ptr, "fireeventcancel", &_2, 0, &_32$$49);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_31$$49)) {
				RETURN_MM_BOOL(0);
			}
		}
		zephir_read_property(&_33$$40, this_ptr, SL("_skipped"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_33$$40)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Executes internal events after save a record
 */
PHP_METHOD(Phalcon_Mvc_Model, _postSave) {

	zephir_fcall_cache_entry *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *success_param = NULL, *exists_param = NULL, _0$$4, _2$$5;
	zend_bool success, exists;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &success_param, &exists_param);

	success = zephir_get_boolval(success_param);
	exists = zephir_get_boolval(exists_param);


	if (success == 1) {
		if (exists) {
			ZEPHIR_INIT_VAR(&_0$$4);
			ZVAL_STRING(&_0$$4, "afterUpdate");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_1, 0, &_0$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_2$$5);
			ZVAL_STRING(&_2$$5, "afterCreate");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_1, 0, &_2$$5);
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

	zend_bool useExplicitIdentity = 0, _16, _4$$11, _13$$22;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table, table_sub, *identityField, identityField_sub, __$null, bindSkip, fields, values, bindTypes, attributes, bindDataTypes, automaticAttributes, field, columnMap, value, attributeField, success, bindType, defaultValue, sequenceName, defaultValues, source, schema, *_0, _1$$8, _2$$8, _6$$13, _7$$13, _8$$15, _10$$17, _11$$20, _12$$20, _14$$27, _15$$27, _17$$30, _18$$30;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&metaData_sub);
	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&identityField_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&bindSkip);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&automaticAttributes);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&sequenceName);
	ZVAL_UNDEF(&defaultValues);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&_1$$8);
	ZVAL_UNDEF(&_2$$8);
	ZVAL_UNDEF(&_6$$13);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_8$$15);
	ZVAL_UNDEF(&_10$$17);
	ZVAL_UNDEF(&_11$$20);
	ZVAL_UNDEF(&_12$$20);
	ZVAL_UNDEF(&_14$$27);
	ZVAL_UNDEF(&_15$$27);
	ZVAL_UNDEF(&_17$$30);
	ZVAL_UNDEF(&_18$$30);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &metaData, &connection, &table, &identityField);



	ZEPHIR_INIT_VAR(&bindSkip);
	ZVAL_LONG(&bindSkip, 1024);
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&bindTypes);
	array_init(&bindTypes);
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
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	zephir_is_iterable(&attributes, 0, "phalcon/mvc/model.zep", 2212);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
	{
		ZEPHIR_INIT_NVAR(&field);
		ZVAL_COPY(&field, _0);
		if (!(zephir_array_isset(&automaticAttributes, &field))) {
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_1$$8);
					object_init_ex(&_1$$8, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_2$$8);
					ZEPHIR_CONCAT_SVS(&_2$$8, "Column '", &field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_1$$8, "__construct", &_3, 9, &_2$$8);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_1$$8, "phalcon/mvc/model.zep", 2166 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &field);
			}
			if (!ZEPHIR_IS_EQUAL(&field, identityField)) {
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
					_4$$11 = Z_TYPE_P(&value) == IS_NULL;
					if (_4$$11) {
						_4$$11 = zephir_array_isset(&defaultValues, &field);
					}
					if (_4$$11) {
						ZEPHIR_CALL_METHOD(&value, connection, "getdefaultvalue", &_5, 0);
						zephir_check_call_status();
					}
					ZEPHIR_OBS_NVAR(&bindType);
					if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(&_6$$13);
						object_init_ex(&_6$$13, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_7$$13);
						ZEPHIR_CONCAT_SVS(&_7$$13, "Column '", &field, "' have not defined a bind data type");
						ZEPHIR_CALL_METHOD(NULL, &_6$$13, "__construct", &_3, 9, &_7$$13);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_6$$13, "phalcon/mvc/model.zep", 2190 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/mvc/model.zep", 2193);
					zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2193);
					zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 2193);
				} else {
					if (zephir_array_isset(&defaultValues, &field)) {
						ZEPHIR_CALL_METHOD(&_8$$15, connection, "getdefaultvalue", &_9, 0);
						zephir_check_call_status();
						zephir_array_append(&values, &_8$$15, PH_SEPARATE, "phalcon/mvc/model.zep", 2198);
					} else {
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2200);
					}
					zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/mvc/model.zep", 2203);
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 2203);
				}
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&field);
	if (!ZEPHIR_IS_FALSE_IDENTICAL(identityField)) {
		ZEPHIR_CALL_METHOD(&defaultValue, connection, "getdefaultidvalue", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_10$$17, connection, "useexplicitidvalue", NULL, 0);
		zephir_check_call_status();
		useExplicitIdentity = zephir_get_boolval(&_10$$17);
		if (useExplicitIdentity) {
			zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/mvc/model.zep", 2221);
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, &columnMap, identityField, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(&_11$$20);
				object_init_ex(&_11$$20, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_12$$20);
				ZEPHIR_CONCAT_SVS(&_12$$20, "Identity column '", identityField, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, &_11$$20, "__construct", &_3, 9, &_12$$20);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$20, "phalcon/mvc/model.zep", 2229 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, identityField);
		}
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
			_13$$22 = Z_TYPE_P(&value) == IS_NULL;
			if (!(_13$$22)) {
				_13$$22 = ZEPHIR_IS_STRING_IDENTICAL(&value, "");
			}
			if (_13$$22) {
				if (useExplicitIdentity) {
					zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/mvc/model.zep", 2242);
					zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 2242);
				}
			} else {
				if (!(useExplicitIdentity)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/mvc/model.zep", 2250);
				}
				ZEPHIR_OBS_NVAR(&bindType);
				if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, identityField, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_VAR(&_14$$27);
					object_init_ex(&_14$$27, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_VAR(&_15$$27);
					ZEPHIR_CONCAT_SVS(&_15$$27, "Identity column '", identityField, "' isn\\'t part of the table columns");
					ZEPHIR_CALL_METHOD(NULL, &_14$$27, "__construct", &_3, 9, &_15$$27);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_14$$27, "phalcon/mvc/model.zep", 2257 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2260);
				zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 2260);
			}
		} else {
			if (useExplicitIdentity) {
				zephir_array_append(&values, &defaultValue, PH_SEPARATE, "phalcon/mvc/model.zep", 2264);
				zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 2264);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&success, connection, "insert", NULL, 0, table, &values, &fields, &bindTypes);
	zephir_check_call_status();
	_16 = zephir_is_true(&success);
	if (_16) {
		_16 = !ZEPHIR_IS_FALSE_IDENTICAL(identityField);
	}
	if (_16) {
		ZEPHIR_INIT_VAR(&sequenceName);
		ZVAL_NULL(&sequenceName);
		ZEPHIR_CALL_METHOD(&_17$$30, connection, "supportsequences", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(&_17$$30)) {
			if ((zephir_method_exists_ex(this_ptr, SL("getsequencename") TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_CALL_METHOD(&sequenceName, this_ptr, "getsequencename", NULL, 0);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&sequenceName);
				if (ZEPHIR_IS_EMPTY(&schema)) {
					ZEPHIR_CONCAT_VSVS(&sequenceName, &source, "_", identityField, "_seq");
				} else {
					ZEPHIR_CONCAT_VSVSVS(&sequenceName, &schema, ".", &source, "_", identityField, "_seq");
				}
			}
		}
		ZEPHIR_CALL_METHOD(&_18$$30, connection, "lastinsertid", NULL, 0, &sequenceName);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, &attributeField, &_18$$30 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_uniqueParams"), &__$null);
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

	zval _11$$25, _12$$25;
	zval _16;
	zend_bool useDynamicUpdate = 0, changed = 0;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, *table, table_sub, __$null, bindSkip, fields, values, bindTypes, manager, bindDataTypes, field, automaticAttributes, snapshotValue, uniqueKey, uniqueParams, uniqueTypes, snapshot, nonPrimary, columnMap, attributeField, value, primaryKeys, bindType, _0, _1, *_2, _3$$9, _4$$9, _6$$11, _7$$11, _8$$24, _10$$24, *_13$$30, _14$$34, _15$$34;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&metaData_sub);
	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&table_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&bindSkip);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&automaticAttributes);
	ZVAL_UNDEF(&snapshotValue);
	ZVAL_UNDEF(&uniqueKey);
	ZVAL_UNDEF(&uniqueParams);
	ZVAL_UNDEF(&uniqueTypes);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&nonPrimary);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$24);
	ZVAL_UNDEF(&_10$$24);
	ZVAL_UNDEF(&_14$$34);
	ZVAL_UNDEF(&_15$$34);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_11$$25);
	ZVAL_UNDEF(&_12$$25);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &metaData, &connection, &table);



	ZEPHIR_INIT_VAR(&bindSkip);
	ZVAL_LONG(&bindSkip, 1024);
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&bindTypes);
	array_init(&bindTypes);
	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_1, &manager, "isusingdynamicupdate", NULL, 0, this_ptr);
	zephir_check_call_status();
	useDynamicUpdate = zephir_get_boolval(&_1);
	if (useDynamicUpdate) {
		ZEPHIR_OBS_VAR(&snapshot);
		zephir_read_property(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
		if (Z_TYPE_P(&snapshot) != IS_ARRAY) {
			useDynamicUpdate = 0;
		}
	}
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
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	zephir_is_iterable(&nonPrimary, 0, "phalcon/mvc/model.zep", 2464);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&nonPrimary), _2)
	{
		ZEPHIR_INIT_NVAR(&field);
		ZVAL_COPY(&field, _2);
		if (!(zephir_array_isset(&automaticAttributes, &field))) {
			ZEPHIR_OBS_NVAR(&bindType);
			if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &field, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(&_3$$9);
				object_init_ex(&_3$$9, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_4$$9);
				ZEPHIR_CONCAT_SVS(&_4$$9, "Column '", &field, "' have not defined a bind data type");
				ZEPHIR_CALL_METHOD(NULL, &_3$$9, "__construct", &_5, 9, &_4$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$9, "phalcon/mvc/model.zep", 2363 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_6$$11);
					object_init_ex(&_6$$11, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_7$$11);
					ZEPHIR_CONCAT_SVS(&_7$$11, "Column '", &field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_6$$11, "__construct", &_5, 9, &_7$$11);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_6$$11, "phalcon/mvc/model.zep", 2371 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &field);
			}
			ZEPHIR_OBS_NVAR(&value);
			if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
				if (!(useDynamicUpdate)) {
					zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/mvc/model.zep", 2387);
					zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2387);
					zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 2388);
				} else {
					ZEPHIR_OBS_NVAR(&snapshotValue);
					if (!(zephir_array_isset_fetch(&snapshotValue, &snapshot, &attributeField, 0 TSRMLS_CC))) {
						changed = 1;
					} else {
						if (Z_TYPE_P(&value) == IS_NULL) {
							changed = Z_TYPE_P(&snapshotValue) != IS_NULL;
						} else {
							if (Z_TYPE_P(&snapshotValue) == IS_NULL) {
								changed = 1;
							} else {
								do {
									if (ZEPHIR_IS_LONG(&bindType, 8)) {
										changed = zephir_get_boolval(&snapshotValue) != zephir_get_boolval(&value);
										break;
									}
									if (ZEPHIR_IS_LONG(&bindType, 0)) {
										changed = zephir_get_intval(&snapshotValue) != zephir_get_intval(&value);
										break;
									}
									if (ZEPHIR_IS_LONG(&bindType, 3) || ZEPHIR_IS_LONG(&bindType, 7)) {
										ZEPHIR_CALL_FUNCTION(&_8$$24, "floatval", &_9, 318, &snapshotValue);
										zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_10$$24, "floatval", &_9, 318, &value);
										zephir_check_call_status();
										changed = !ZEPHIR_IS_IDENTICAL(&_8$$24, &_10$$24);
										break;
									}
									if (ZEPHIR_IS_LONG(&bindType, 1) || ZEPHIR_IS_LONG(&bindType, 2) || ZEPHIR_IS_LONG(&bindType, 4) || ZEPHIR_IS_LONG(&bindType, 5) || ZEPHIR_IS_LONG(&bindType, 6) || ZEPHIR_IS_LONG(&bindType, 2) || ZEPHIR_IS_LONG(&bindType, 14)) {
										zephir_get_strval(&_11$$25, &snapshotValue);
										zephir_get_strval(&_12$$25, &value);
										changed = !ZEPHIR_IS_IDENTICAL(&_11$$25, &_12$$25);
										break;
									}
									changed = !ZEPHIR_IS_EQUAL(&value, &snapshotValue);
								} while(0);

							}
						}
					}
					if (changed) {
						zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/mvc/model.zep", 2450);
						zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2450);
						zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 2451);
					}
				}
			} else {
				zephir_array_append(&fields, &field, PH_SEPARATE, "phalcon/mvc/model.zep", 2456);
				zephir_array_append(&values, &__$null, PH_SEPARATE, "phalcon/mvc/model.zep", 2456);
				zephir_array_append(&bindTypes, &bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 2456);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&field);
	if (!(zephir_fast_count_int(&fields TSRMLS_CC))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_OBS_VAR(&uniqueKey);
	zephir_read_property(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&uniqueParams);
	zephir_read_property(&uniqueParams, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&uniqueTypes);
	zephir_read_property(&uniqueTypes, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC);
	if (Z_TYPE_P(&uniqueParams) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&primaryKeys, metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
		zephir_check_call_status();
		if (!(zephir_fast_count_int(&primaryKeys TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation", "phalcon/mvc/model.zep", 2483);
			return;
		}
		ZEPHIR_INIT_NVAR(&uniqueParams);
		array_init(&uniqueParams);
		zephir_is_iterable(&primaryKeys, 0, "phalcon/mvc/model.zep", 2506);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _13$$30)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _13$$30);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(&_14$$34);
					object_init_ex(&_14$$34, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_15$$34);
					ZEPHIR_CONCAT_SVS(&_15$$34, "Column '", &field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_14$$34, "__construct", &_5, 9, &_15$$34);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_14$$34, "phalcon/mvc/model.zep", 2494 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &field);
			}
			ZEPHIR_OBS_NVAR(&value);
			if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
				zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 2501);
			} else {
				zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalcon/mvc/model.zep", 2503);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&field);
	}
	ZEPHIR_INIT_VAR(&_16);
	zephir_create_array(&_16, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_16, SL("conditions"), &uniqueKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_16, SL("bind"), &uniqueParams, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_16, SL("bindTypes"), &uniqueTypes, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(connection, "update", NULL, 0, table, &fields, &values, &_16, &bindTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Saves related records that must be stored prior to save the master record
 *
 * @param \Phalcon\Db\AdapterInterface connection
 * @param \Phalcon\Mvc\ModelInterface[] related
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _preSaveRelatedRecords) {

	zend_string *_4;
	zend_ulong _3;
	zend_bool nesting = 0;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_10 = NULL, *_14 = NULL, *_16 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, *related, related_sub, className, manager, type, relation, columns, referencedFields, referencedModel, message, name, record, _0, _1, *_2, _5$$3, _7$$6, _9$$7, _11$$5, _17$$5, _12$$8, *_13$$8, _15$$8;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&related_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_15$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &related);



	nesting = 0;
	if (nesting) {
		ZVAL_BOOL(&_0, 1);
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_1);
	zephir_is_iterable(related, 0, "phalcon/mvc/model.zep", 2612);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(related), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&name, _4);
		} else {
			ZVAL_LONG(&name, _3);
		}
		ZEPHIR_INIT_NVAR(&record);
		ZVAL_COPY(&record, _2);
		ZEPHIR_CALL_METHOD(&_5$$3, &manager, "getrelationbyalias", &_6, 0, &className, &name);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_5$$3);
		if (Z_TYPE_P(&relation) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&type, &relation, "gettype", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(&type, 0)) {
				if (Z_TYPE_P(&record) != IS_OBJECT) {
					if (nesting) {
						ZVAL_BOOL(&_7$$6, 1);
					} else {
						ZVAL_BOOL(&_7$$6, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_8, 0, &_7$$6);
					zephir_check_call_status();
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects can be stored as part of belongs-to relations", "phalcon/mvc/model.zep", 2561);
					return;
				}
				ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(&columns) == IS_ARRAY) {
					if (nesting) {
						ZVAL_BOOL(&_9$$7, 1);
					} else {
						ZVAL_BOOL(&_9$$7, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_10, 0, &_9$$7);
					zephir_check_call_status();
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/mvc/model.zep", 2570);
					return;
				}
				ZEPHIR_CALL_METHOD(&_11$$5, &record, "save", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_11$$5))) {
					ZEPHIR_CALL_METHOD(&_12$$8, &record, "getmessages", NULL, 0);
					zephir_check_call_status();
					zephir_is_iterable(&_12$$8, 0, "phalcon/mvc/model.zep", 2599);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_12$$8), _13$$8)
					{
						ZEPHIR_INIT_NVAR(&message);
						ZVAL_COPY(&message, _13$$8);
						if (Z_TYPE_P(&message) == IS_OBJECT) {
							ZEPHIR_CALL_METHOD(NULL, &message, "setmodel", NULL, 0, &record);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_14, 0, &message);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&message);
					if (nesting) {
						ZVAL_BOOL(&_15$$8, 1);
					} else {
						ZVAL_BOOL(&_15$$8, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_16, 0, &_15$$8);
					zephir_check_call_status();
					RETURN_MM_BOOL(0);
				}
				ZEPHIR_CALL_METHOD(&_17$$5, &record, "readattribute", NULL, 0, &referencedFields);
				zephir_check_call_status();
				zephir_update_property_zval_zval(this_ptr, &columns, &_17$$5 TSRMLS_CC);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&record);
	ZEPHIR_INIT_NVAR(&name);
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

	zend_string *_3;
	zend_ulong _2;
	zend_bool nesting = 0, isThrough = 0, _7$$4;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL, *_11 = NULL, *_13 = NULL, *_16 = NULL, *_22 = NULL, *_24 = NULL, *_26 = NULL, *_31 = NULL, *_33 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, *related, related_sub, className, manager, relation, name, record, message, columns, referencedModel, referencedFields, relatedRecords, value, recordAfter, intermediateModel, intermediateFields, intermediateValue, intermediateModelName, intermediateReferencedFields, _0, *_1, _36, _4$$3, _6$$4, _17$$4, *_18$$4, _8$$6, _10$$7, _12$$10, _14$$10, _15$$10, _19$$12, _20$$14, *_21$$14, _23$$14, _25$$17, _27$$17, _28$$18, *_29$$18, _30$$18, _32$$22, _34$$22, _35$$22;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&related_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&record);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&referencedFields);
	ZVAL_UNDEF(&relatedRecords);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&recordAfter);
	ZVAL_UNDEF(&intermediateModel);
	ZVAL_UNDEF(&intermediateFields);
	ZVAL_UNDEF(&intermediateValue);
	ZVAL_UNDEF(&intermediateModelName);
	ZVAL_UNDEF(&intermediateReferencedFields);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_32$$22);
	ZVAL_UNDEF(&_34$$22);
	ZVAL_UNDEF(&_35$$22);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &related);



	nesting = 0;
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	zephir_is_iterable(related, 0, "phalcon/mvc/model.zep", 2800);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(related), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&name, _3);
		} else {
			ZVAL_LONG(&name, _2);
		}
		ZEPHIR_INIT_NVAR(&record);
		ZVAL_COPY(&record, _1);
		ZEPHIR_CALL_METHOD(&_4$$3, &manager, "getrelationbyalias", &_5, 0, &className, &name);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_4$$3);
		if (Z_TYPE_P(&relation) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_6$$4, &relation, "gettype", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(&_6$$4, 0)) {
				continue;
			}
			_7$$4 = Z_TYPE_P(&record) != IS_OBJECT;
			if (_7$$4) {
				_7$$4 = Z_TYPE_P(&record) != IS_ARRAY;
			}
			if (_7$$4) {
				if (nesting) {
					ZVAL_BOOL(&_8$$6, 1);
				} else {
					ZVAL_BOOL(&_8$$6, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_9, 0, &_8$$6);
				zephir_check_call_status();
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects/arrays can be stored as part of has-many/has-one/has-many-to-many relations", "phalcon/mvc/model.zep", 2651);
				return;
			}
			ZEPHIR_CALL_METHOD(&columns, &relation, "getfields", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedModel, &relation, "getreferencedmodel", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedFields, &relation, "getreferencedfields", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(&columns) == IS_ARRAY) {
				if (nesting) {
					ZVAL_BOOL(&_10$$7, 1);
				} else {
					ZVAL_BOOL(&_10$$7, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_11, 0, &_10$$7);
				zephir_check_call_status();
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/mvc/model.zep", 2660);
				return;
			}
			if (Z_TYPE_P(&record) == IS_OBJECT) {
				ZEPHIR_INIT_NVAR(&relatedRecords);
				zephir_create_array(&relatedRecords, 1, 0 TSRMLS_CC);
				zephir_array_fast_append(&relatedRecords, &record);
			} else {
				ZEPHIR_CPY_WRT(&relatedRecords, &record);
			}
			ZEPHIR_OBS_NVAR(&value);
			if (!(zephir_fetch_property_zval(&value, this_ptr, &columns, PH_SILENT_CC))) {
				if (nesting) {
					ZVAL_BOOL(&_12$$10, 1);
				} else {
					ZVAL_BOOL(&_12$$10, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_13, 0, &_12$$10);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_14$$10);
				object_init_ex(&_14$$10, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_15$$10);
				ZEPHIR_CONCAT_SVS(&_15$$10, "The column '", &columns, "' needs to be present in the model");
				ZEPHIR_CALL_METHOD(NULL, &_14$$10, "__construct", &_16, 9, &_15$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_14$$10, "phalcon/mvc/model.zep", 2674 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_17$$4, &relation, "isthrough", NULL, 0);
			zephir_check_call_status();
			isThrough = zephir_get_boolval(&_17$$4);
			if (isThrough) {
				ZEPHIR_CALL_METHOD(&intermediateModelName, &relation, "getintermediatemodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&intermediateFields, &relation, "getintermediatefields", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&intermediateReferencedFields, &relation, "getintermediatereferencedfields", NULL, 0);
				zephir_check_call_status();
			}
			zephir_is_iterable(&relatedRecords, 0, "phalcon/mvc/model.zep", 2789);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relatedRecords), _18$$4)
			{
				ZEPHIR_INIT_NVAR(&recordAfter);
				ZVAL_COPY(&recordAfter, _18$$4);
				if (!(isThrough)) {
					ZEPHIR_CALL_METHOD(NULL, &recordAfter, "writeattribute", NULL, 0, &referencedFields, &value);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_19$$12, &recordAfter, "save", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(&_19$$12))) {
					ZEPHIR_CALL_METHOD(&_20$$14, &recordAfter, "getmessages", NULL, 0);
					zephir_check_call_status();
					zephir_is_iterable(&_20$$14, 0, "phalcon/mvc/model.zep", 2731);
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_20$$14), _21$$14)
					{
						ZEPHIR_INIT_NVAR(&message);
						ZVAL_COPY(&message, _21$$14);
						if (Z_TYPE_P(&message) == IS_OBJECT) {
							ZEPHIR_CALL_METHOD(NULL, &message, "setmodel", NULL, 0, &record);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_22, 0, &message);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
					ZEPHIR_INIT_NVAR(&message);
					if (nesting) {
						ZVAL_BOOL(&_23$$14, 1);
					} else {
						ZVAL_BOOL(&_23$$14, 0);
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_24, 0, &_23$$14);
					zephir_check_call_status();
					RETURN_MM_BOOL(0);
				}
				if (isThrough) {
					ZVAL_BOOL(&_25$$17, 1);
					ZEPHIR_CALL_METHOD(&intermediateModel, &manager, "load", &_26, 0, &intermediateModelName, &_25$$17);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateFields, &value);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&intermediateValue, &recordAfter, "readattribute", NULL, 0, &referencedFields);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &intermediateModel, "writeattribute", NULL, 0, &intermediateReferencedFields, &intermediateValue);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_27$$17, &intermediateModel, "save", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(&_27$$17))) {
						ZEPHIR_CALL_METHOD(&_28$$18, &intermediateModel, "getmessages", NULL, 0);
						zephir_check_call_status();
						zephir_is_iterable(&_28$$18, 0, "phalcon/mvc/model.zep", 2783);
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_28$$18), _29$$18)
						{
							ZEPHIR_INIT_NVAR(&message);
							ZVAL_COPY(&message, _29$$18);
							if (Z_TYPE_P(&message) == IS_OBJECT) {
								ZEPHIR_CALL_METHOD(NULL, &message, "setmodel", NULL, 0, &record);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_22, 0, &message);
							zephir_check_call_status();
						} ZEND_HASH_FOREACH_END();
						ZEPHIR_INIT_NVAR(&message);
						if (nesting) {
							ZVAL_BOOL(&_30$$18, 1);
						} else {
							ZVAL_BOOL(&_30$$18, 0);
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_31, 0, &_30$$18);
						zephir_check_call_status();
						RETURN_MM_BOOL(0);
					}
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&recordAfter);
		} else {
			if (Z_TYPE_P(&record) != IS_ARRAY) {
				if (nesting) {
					ZVAL_BOOL(&_32$$22, 1);
				} else {
					ZVAL_BOOL(&_32$$22, 0);
				}
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_33, 0, &_32$$22);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_34$$22);
				object_init_ex(&_34$$22, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_35$$22);
				ZEPHIR_CONCAT_SVSVS(&_35$$22, "There are no defined relations for the model '", &className, "' using alias '", &name, "'");
				ZEPHIR_CALL_METHOD(NULL, &_34$$22, "__construct", &_16, 9, &_35$$22);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_34$$22, "phalcon/mvc/model.zep", 2792 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&record);
	ZEPHIR_INIT_NVAR(&name);
	if (nesting) {
		ZVAL_BOOL(&_36, 1);
	} else {
		ZVAL_BOOL(&_36, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0, &_36);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

/**
 * Inserts or updates a model instance. Returning true on success or false otherwise.
 *
 *<code>
 *	//Creating a new robot
 *	$robot = new Robots();
 *	$robot->type = 'mechanical';
 *	$robot->name = 'Astro Boy';
 *	$robot->year = 1952;
 *	$robot->save();
 *
 *	//Updating a robot name
 *	$robot = Robots::findFirst("id=100");
 *	$robot->name = "Biomass";
 *	$robot->save();
 *</code>
 *
 * @param array data
 * @param array whiteList
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, save) {

	zend_bool _0;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *whiteList = NULL, whiteList_sub, __$null, metaData, related, schema, writeConnection, readConnection, source, table, identityField, exists, success, _2, _7, _1$$3, _4$$4, _5$$8, _6$$9, _8$$11, _9$$12, _10$$12, _11$$15, _12$$17, _13$$19, _14$$21;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&whiteList_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&related);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&writeConnection);
	ZVAL_UNDEF(&readConnection);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&identityField);
	ZVAL_UNDEF(&exists);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$12);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$15);
	ZVAL_UNDEF(&_12$$17);
	ZVAL_UNDEF(&_13$$19);
	ZVAL_UNDEF(&_14$$21);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &whiteList);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!whiteList) {
		whiteList = &whiteList_sub;
		whiteList = &__$null;
	}


	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	_0 = Z_TYPE_P(data) == IS_ARRAY;
	if (_0) {
		_0 = zephir_fast_count_int(data TSRMLS_CC) > 0;
	}
	if (_0) {
		ZVAL_NULL(&_1$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, data, &_1$$3, whiteList);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "prepareSave");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_3, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&related);
	zephir_read_property(&related, this_ptr, SL("_related"), PH_NOISY_CC);
	if (Z_TYPE_P(&related) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "_presaverelatedrecords", NULL, 0, &writeConnection, &related);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_4$$4)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&exists, this_ptr, "_exists", NULL, 0, &metaData, &readConnection, &table);
	zephir_check_call_status();
	if (zephir_is_true(&exists)) {
		ZEPHIR_INIT_ZVAL_NREF(_5$$8);
		ZVAL_LONG(&_5$$8, 2);
		zephir_update_property_zval(this_ptr, SL("_operationMade"), &_5$$8);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_6$$9);
		ZVAL_LONG(&_6$$9, 1);
		zephir_update_property_zval(this_ptr, SL("_operationMade"), &_6$$9);
	}
	ZEPHIR_INIT_NVAR(&_2);
	array_init(&_2);
	zephir_update_property_zval(this_ptr, SL("_errorMessages"), &_2);
	ZEPHIR_CALL_METHOD(&identityField, &metaData, "getidentityfield", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "_presave", NULL, 0, &metaData, &exists, &identityField);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_7)) {
		if (Z_TYPE_P(&related) == IS_ARRAY) {
			ZVAL_BOOL(&_8$$11, 0);
			ZEPHIR_CALL_METHOD(NULL, &writeConnection, "rollback", NULL, 0, &_8$$11);
			zephir_check_call_status();
		}
		if (ZEPHIR_GLOBAL(orm).exception_on_failed_save) {
			ZEPHIR_INIT_VAR(&_9$$12);
			object_init_ex(&_9$$12, phalcon_mvc_model_validationfailed_ce);
			ZEPHIR_CALL_METHOD(&_10$$12, this_ptr, "getmessages", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_9$$12, "__construct", NULL, 319, this_ptr, &_10$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$12, "phalcon/mvc/model.zep", 2910 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(0);
	}
	if (zephir_is_true(&exists)) {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "_dolowupdate", NULL, 0, &metaData, &writeConnection, &table);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&success, this_ptr, "_dolowinsert", NULL, 0, &metaData, &writeConnection, &table, &identityField);
		zephir_check_call_status();
	}
	if (zephir_is_true(&success)) {
		ZEPHIR_INIT_ZVAL_NREF(_11$$15);
		ZVAL_LONG(&_11$$15, 0);
		zephir_update_property_zval(this_ptr, SL("_dirtyState"), &_11$$15);
	}
	if (Z_TYPE_P(&related) == IS_ARRAY) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
			ZVAL_BOOL(&_12$$17, 0);
			ZEPHIR_CALL_METHOD(NULL, &writeConnection, "rollback", NULL, 0, &_12$$17);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&success, this_ptr, "_postsaverelatedrecords", NULL, 0, &writeConnection, &related);
			zephir_check_call_status();
		}
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		ZEPHIR_CALL_METHOD(&_13$$19, this_ptr, "_postsave", NULL, 0, &success, &exists);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&success, &_13$$19);
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(&success)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_14$$21);
		ZVAL_STRING(&_14$$21, "afterSave");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_3, 0, &_14$$21);
		zephir_check_call_status();
	}
	RETURN_CCTOR(success);

}

/**
 * Inserts a model instance. If the instance already exists in the persistance it will throw an exception
 * Returning true on success or false otherwise.
 *
 *<code>
 *	//Creating a new robot
 *	$robot = new Robots();
 *	$robot->type = 'mechanical';
 *	$robot->name = 'Astro Boy';
 *	$robot->year = 1952;
 *	$robot->create();
 *
 *  //Passing an array to create
 *  $robot = new Robots();
 *  $robot->create(array(
 *	  'type' => 'mechanical',
 *	  'name' => 'Astroy Boy',
 *	  'year' => 1952
 *  ));
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, create) {

	zval _2$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *whiteList = NULL, whiteList_sub, __$null, metaData, _0, _1, _3$$3, _4$$3, _5$$3, _6$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&whiteList_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &whiteList);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!whiteList) {
		whiteList = &whiteList_sub;
		whiteList = &__$null;
	}


	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_exists", NULL, 0, &metaData, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_mvc_model_message_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Record cannot be created because it already exists");
		ZVAL_NULL(&_5$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "InvalidCreateAttempt");
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 8, &_4$$3, &_5$$3, &_6$$3);
		zephir_check_call_status();
		zephir_array_fast_append(&_2$$3, &_3$$3);
		zephir_update_property_zval(this_ptr, SL("_errorMessages"), &_2$$3);
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "save", NULL, 0, data, whiteList);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Updates a model instance. If the instance doesn't exist in the persistance it will throw an exception
 * Returning true on success or false otherwise.
 *
 *<code>
 *	//Updating a robot name
 *	$robot = Robots::findFirst("id=100");
 *	$robot->name = "Biomass";
 *	$robot->update();
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, update) {

	zval _3$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *whiteList = NULL, whiteList_sub, __$null, metaData, _0, _1$$3, _2$$3, _4$$4, _5$$4, _6$$4, _7$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&whiteList_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &whiteList);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!whiteList) {
		whiteList = &whiteList_sub;
		whiteList = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getreadconnection", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "_exists", NULL, 0, &metaData, &_2$$3);
		zephir_check_call_status();
		if (!(zephir_is_true(&_1$$3))) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_4$$4);
			object_init_ex(&_4$$4, phalcon_mvc_model_message_ce);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "Record cannot be updated because it does not exist");
			ZVAL_NULL(&_6$$4);
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "InvalidUpdateAttempt");
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 8, &_5$$4, &_6$$4, &_7$$4);
			zephir_check_call_status();
			zephir_array_fast_append(&_3$$4, &_4$$4);
			zephir_update_property_zval(this_ptr, SL("_errorMessages"), &_3$$4);
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
 *$robot = Robots::findFirst("id=100");
 *$robot->delete();
 *
 *foreach (Robots::find("type = 'mechanical'") as $robot) {
 *   $robot->delete();
 *}
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, delete) {

	zval __$true, __$false, metaData, writeConnection, values, bindTypes, primaryKeys, bindDataTypes, columnMap, attributeField, conditions, primaryKey, bindType, value, schema, source, table, success, _0, _1, *_3, _17, _2$$3, _4$$9, _5$$9, _7$$11, _8$$11, _9$$13, _10$$13, _11$$8, _13$$8, _14$$14, _15$$14, _16$$16, _18$$20, _19$$23;
	zephir_fcall_cache_entry *_6 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&writeConnection);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&primaryKey);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&success);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_7$$11);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&_9$$13);
	ZVAL_UNDEF(&_10$$13);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$14);
	ZVAL_UNDEF(&_15$$14);
	ZVAL_UNDEF(&_16$$16);
	ZVAL_UNDEF(&_18$$20);
	ZVAL_UNDEF(&_19$$23);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 3);
	zephir_update_property_zval(this_ptr, SL("_operationMade"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, SL("_errorMessages"), &_1);
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "_checkforeignkeysreverserestrict", NULL, 320);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$3)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(&values);
	array_init(&values);
	ZEPHIR_INIT_VAR(&bindTypes);
	array_init(&bindTypes);
	ZEPHIR_INIT_VAR(&conditions);
	array_init(&conditions);
	ZEPHIR_CALL_METHOD(&primaryKeys, &metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, &metaData, "getbindtypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).column_renaming) {
		ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&columnMap);
		ZVAL_NULL(&columnMap);
	}
	if (!(zephir_fast_count_int(&primaryKeys TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation", "phalcon/mvc/model.zep", 3094);
		return;
	}
	zephir_is_iterable(&primaryKeys, 0, "phalcon/mvc/model.zep", 3135);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _3)
	{
		ZEPHIR_INIT_NVAR(&primaryKey);
		ZVAL_COPY(&primaryKey, _3);
		ZEPHIR_OBS_NVAR(&bindType);
		if (!(zephir_array_isset_fetch(&bindType, &bindDataTypes, &primaryKey, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(&_4$$9);
			object_init_ex(&_4$$9, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_5$$9);
			ZEPHIR_CONCAT_SVS(&_5$$9, "Column '", &primaryKey, "' have not defined a bind data type");
			ZEPHIR_CALL_METHOD(NULL, &_4$$9, "__construct", &_6, 9, &_5$$9);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$9, "phalcon/mvc/model.zep", 3106 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &primaryKey, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(&_7$$11);
				object_init_ex(&_7$$11, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_8$$11);
				ZEPHIR_CONCAT_SVS(&_8$$11, "Column '", &primaryKey, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, &_7$$11, "__construct", &_6, 9, &_8$$11);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$11, "phalcon/mvc/model.zep", 3114 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, &primaryKey);
		}
		ZEPHIR_OBS_NVAR(&value);
		if (!(zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC))) {
			ZEPHIR_INIT_NVAR(&_9$$13);
			object_init_ex(&_9$$13, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_10$$13);
			ZEPHIR_CONCAT_SVS(&_10$$13, "Cannot delete the record because the primary key attribute: '", &attributeField, "' wasn't set");
			ZEPHIR_CALL_METHOD(NULL, &_9$$13, "__construct", &_6, 9, &_10$$13);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$13, "phalcon/mvc/model.zep", 3124 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_append(&values, &value, PH_SEPARATE, "phalcon/mvc/model.zep", 3130);
		ZEPHIR_CALL_METHOD(&_11$$8, &writeConnection, "escapeidentifier", &_12, 0, &primaryKey);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_13$$8);
		ZEPHIR_CONCAT_VS(&_13$$8, &_11$$8, " = ?");
		zephir_array_append(&conditions, &_13$$8, PH_SEPARATE, "phalcon/mvc/model.zep", 3131);
		zephir_array_append(&bindTypes, &bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 3132);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&primaryKey);
	if (ZEPHIR_GLOBAL(orm).events) {
		if (0) {
			zephir_update_property_zval(this_ptr, SL("_skipped"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_skipped"), &__$false);
		}
		ZEPHIR_INIT_VAR(&_15$$14);
		ZVAL_STRING(&_15$$14, "beforeDelete");
		ZEPHIR_CALL_METHOD(&_14$$14, this_ptr, "fireeventcancel", NULL, 0, &_15$$14);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_14$$14)) {
			RETURN_MM_BOOL(0);
		} else {
			zephir_read_property(&_16$$16, this_ptr, SL("_skipped"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_TRUE_IDENTICAL(&_16$$16)) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_INIT_VAR(&_17);
	zephir_fast_join_str(&_17, SL(" AND "), &conditions TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&success, &writeConnection, "delete", NULL, 0, &table, &_17, &values, &bindTypes);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_18$$20, this_ptr, "_checkforeignkeysreversecascade", NULL, 321);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_18$$20)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (zephir_is_true(&success)) {
			ZEPHIR_INIT_VAR(&_19$$23);
			ZVAL_STRING(&_19$$23, "afterDelete");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, &_19$$23);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, 2);
	zephir_update_property_zval(this_ptr, SL("_dirtyState"), &_0);
	RETURN_CCTOR(success);

}

/**
 * Returns the type of the latest operation performed by the ORM
 * Returns one of the OP_* class constants
 */
PHP_METHOD(Phalcon_Mvc_Model, getOperationMade) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_operationMade");

}

/**
 * Refreshes the model attributes re-querying the record from the database
 */
PHP_METHOD(Phalcon_Mvc_Model, refresh) {

	zval _5, _4$$9;
	zval metaData, readConnection, schema, source, table, uniqueKey, tables, uniqueParams, dialect, row, fields, attribute, _0, _2, *_3, _6, _7, _8, _1$$6, _9$$10;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&readConnection);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&uniqueKey);
	ZVAL_UNDEF(&tables);
	ZVAL_UNDEF(&uniqueParams);
	ZVAL_UNDEF(&dialect);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_4$$9);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_LONG(&_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/mvc/model.zep", 3210);
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	ZEPHIR_OBS_VAR(&uniqueKey);
	zephir_read_property(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	if (!(zephir_is_true(&uniqueKey))) {
		ZEPHIR_CALL_METHOD(&_1$$6, this_ptr, "_exists", NULL, 0, &metaData, &readConnection, &table);
		zephir_check_call_status();
		if (!(zephir_is_true(&_1$$6))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/mvc/model.zep", 3232);
			return;
		}
		ZEPHIR_OBS_NVAR(&uniqueKey);
		zephir_read_property(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(&uniqueParams);
	zephir_read_property(&uniqueParams, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	if (Z_TYPE_P(&uniqueParams) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/mvc/model.zep", 3240);
		return;
	}
	ZEPHIR_INIT_VAR(&fields);
	array_init(&fields);
	ZEPHIR_CALL_METHOD(&_2, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_2, 0, "phalcon/mvc/model.zep", 3254);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2), _3)
	{
		ZEPHIR_INIT_NVAR(&attribute);
		ZVAL_COPY(&attribute, _3);
		ZEPHIR_INIT_NVAR(&_4$$9);
		zephir_create_array(&_4$$9, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_4$$9, &attribute);
		zephir_array_append(&fields, &_4$$9, PH_SEPARATE, "phalcon/mvc/model.zep", 3248);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&dialect, &readConnection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_5, SL("columns"), &fields, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_6, &readConnection, "escapeidentifier", NULL, 0, &table);
	zephir_check_call_status();
	zephir_array_update_string(&_5, SL("tables"), &_6, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("where"), &uniqueKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&tables, &dialect, "select", NULL, 0, &_5);
	zephir_check_call_status();
	zephir_read_property(&_7, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_8, 2);
	ZEPHIR_CALL_METHOD(&row, &readConnection, "fetchone", NULL, 0, &tables, &_8, &uniqueParams, &_7);
	zephir_check_call_status();
	if (Z_TYPE_P(&row) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_9$$10, &metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, &row, &_9$$10);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Skips the current operation forcing a success state
 */
PHP_METHOD(Phalcon_Mvc_Model, skipOperation) {

	zval *skip_param = NULL, __$true, __$false;
	zend_bool skip;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);

	zephir_fetch_params(0, 1, 0, &skip_param);

	skip = zephir_get_boolval(skip_param);


	if (skip) {
		zephir_update_property_zval(this_ptr, SL("_skipped"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_skipped"), &__$false);
	}

}

/**
 * Reads an attribute value by its name
 *
 * <code>
 * echo $robot->readAttribute('name');
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, readAttribute) {

	zval *attribute_param = NULL, _0;
	zval attribute;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute_param);

	if (unlikely(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(&attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(&attribute);
		ZVAL_EMPTY_STRING(&attribute);
	}


	if (!(zephir_isset_property_zval(this_ptr, &attribute TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property_zval(&_0, this_ptr, &attribute, PH_NOISY_CC);
	RETURN_CCTOR(_0);

}

/**
 * Writes an attribute value by its name
 *
 *<code>
 * 	$robot->writeAttribute('name', 'Rosey');
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, writeAttribute) {

	zval *attribute_param = NULL, *value, value_sub;
	zval attribute;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);

	if (unlikely(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(&attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(&attribute);
		ZVAL_EMPTY_STRING(&attribute);
	}


	zephir_update_property_zval_zval(this_ptr, &attribute, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT/UPDATE statement
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *	   $this->skipAttributes(array('price'));
 *   }
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributes) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$null, keysAttributes, metaData, attribute, *_0;
	zval attributes;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&attributes);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&attribute);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_VAR_ONCE(&attributes);
	ZVAL_COPY(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/mvc/model.zep", 3335);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
	{
		ZEPHIR_INIT_NVAR(&attribute);
		ZVAL_COPY(&attribute, _0);
		zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &metaData, "setautomaticcreateattributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &metaData, "setautomaticupdateattributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT statement
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *	   $this->skipAttributesOnCreate(array('created_at'));
 *   }
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnCreate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$null, keysAttributes, attribute, *_0, _1;
	zval attributes;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&attributes);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_VAR_ONCE(&attributes);
	ZVAL_COPY(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/mvc/model.zep", 3366);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
	{
		ZEPHIR_INIT_NVAR(&attribute);
		ZVAL_COPY(&attribute, _0);
		zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "setautomaticcreateattributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated UPDATE statement
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *	   $this->skipAttributesOnUpdate(array('modified_in'));
 *   }
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnUpdate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$null, keysAttributes, attribute, *_0, _1;
	zval attributes;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&attributes);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_VAR_ONCE(&attributes);
	ZVAL_COPY(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/mvc/model.zep", 3395);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
	{
		ZEPHIR_INIT_NVAR(&attribute);
		ZVAL_COPY(&attribute, _0);
		zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "setautomaticupdateattributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets a list of attributes that must be skipped from the
 * generated UPDATE statement
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *	   $this->allowEmptyStringValues(array('name'));
 *   }
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, allowEmptyStringValues) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *attributes_param = NULL, __$null, keysAttributes, attribute, *_0, _1;
	zval attributes;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&attributes);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&keysAttributes);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	ZEPHIR_OBS_VAR_ONCE(&attributes);
	ZVAL_COPY(&attributes, attributes_param);


	ZEPHIR_INIT_VAR(&keysAttributes);
	array_init(&keysAttributes);
	zephir_is_iterable(&attributes, 0, "phalcon/mvc/model.zep", 3424);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&attributes), _0)
	{
		ZEPHIR_INIT_NVAR(&attribute);
		ZVAL_COPY(&attribute, _0);
		zephir_array_update_zval(&keysAttributes, &attribute, &__$null, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&attribute);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "setemptystringattributes", NULL, 0, this_ptr, &keysAttributes);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Setup a 1-1 relation between two models
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *	   $this->hasOne('id', 'RobotsDescription', 'robots_id');
 *   }
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, hasOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval referenceModel;
	zval *fields, fields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&referenceModel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
		ZVAL_EMPTY_STRING(&referenceModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasone", NULL, 0, this_ptr, fields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setup a relation reverse 1-1  between two models
 *
 *<code>
 *<?php
 *
 *class RobotsParts extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *	   $this->belongsTo('robots_id', 'Robots', 'id');
 *   }
 *
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, belongsTo) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval referenceModel;
	zval *fields, fields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&referenceModel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
		ZVAL_EMPTY_STRING(&referenceModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addbelongsto", NULL, 0, this_ptr, fields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setup a relation 1-n between two models
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *	   $this->hasMany('id', 'RobotsParts', 'robots_id');
 *   }
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, hasMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval referenceModel;
	zval *fields, fields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&referenceModel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
		ZVAL_EMPTY_STRING(&referenceModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasmany", NULL, 0, this_ptr, fields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setup a relation n-n between two models through an intermediate relation
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *	   //Setup a many-to-many relation to Parts through RobotsParts
 *	   $this->hasManyToMany(
 *			'id',
 *			'RobotsParts',
 *			'robots_id',
 *			'parts_id',
 *			'Parts',
 *			'id'
 *		);
 *   }
 *}
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval intermediateModel, referenceModel;
	zval *fields, fields_sub, *intermediateModel_param = NULL, *intermediateFields, intermediateFields_sub, *intermediateReferencedFields, intermediateReferencedFields_sub, *referenceModel_param = NULL, *referencedFields, referencedFields_sub, *options = NULL, options_sub, __$null, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&intermediateFields_sub);
	ZVAL_UNDEF(&intermediateReferencedFields_sub);
	ZVAL_UNDEF(&referencedFields_sub);
	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&intermediateModel);
	ZVAL_UNDEF(&referenceModel);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 1, &fields, &intermediateModel_param, &intermediateFields, &intermediateReferencedFields, &referenceModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(intermediateModel_param) != IS_STRING && Z_TYPE_P(intermediateModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'intermediateModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(intermediateModel_param) == IS_STRING)) {
		zephir_get_strval(&intermediateModel, intermediateModel_param);
	} else {
		ZEPHIR_INIT_VAR(&intermediateModel);
		ZVAL_EMPTY_STRING(&intermediateModel);
	}
	if (unlikely(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
		zephir_get_strval(&referenceModel, referenceModel_param);
	} else {
		ZEPHIR_INIT_VAR(&referenceModel);
		ZVAL_EMPTY_STRING(&referenceModel);
	}
	if (!options) {
		options = &options_sub;
		options = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "addhasmanytomany", NULL, 0, this_ptr, fields, &intermediateModel, intermediateFields, intermediateReferencedFields, &referenceModel, referencedFields, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Setups a behavior in a model
 *
 *<code>
 *<?php
 *
 *use Phalcon\Mvc\Model;
 *use Phalcon\Mvc\Model\Behavior\Timestampable;
 *
 *class Robots extends Model
 *{
 *
 *   public function initialize()
 *   {
 *		$this->addBehavior(new Timestampable(array(
 *			'onCreate' => array(
 *				'field' => 'created_at',
 *				'format' => 'Y-m-d'
 *			)
 *		)));
 *   }
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, addBehavior) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *behavior, behavior_sub, _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&behavior_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &behavior);



	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "addbehavior", NULL, 0, this_ptr, behavior);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets if the model must keep the original record snapshot in memory
 *
 *<code>
 *<?php
 *use Phalcon\Mvc\Model;
 *
 *class Robots extends Model
 *{
 *
 *   public function initialize()
 *   {
 *		$this->keepSnapshots(true);
 *   }
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, keepSnapshots) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *keepSnapshot_param = NULL, _0, _1;
	zend_bool keepSnapshot;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keepSnapshot_param);

	keepSnapshot = zephir_get_boolval(keepSnapshot_param);


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	if (keepSnapshot) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "keepsnapshots", NULL, 0, this_ptr, &_1);
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

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap = NULL, columnMap_sub, __$null, key, value, snapshot, attribute, *_0$$3, _3$$7, _4$$7, _6$$11, _7$$11;
	zval data;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&columnMap_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_7$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &columnMap);

	ZEPHIR_OBS_VAR_ONCE(&data);
	ZVAL_COPY(&data, data_param);
	if (!columnMap) {
		columnMap = &columnMap_sub;
		columnMap = &__$null;
	}


	if (Z_TYPE_P(columnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&snapshot);
		array_init(&snapshot);
		zephir_is_iterable(&data, 0, "phalcon/mvc/model.zep", 3640);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _2$$3);
			} else {
				ZVAL_LONG(&key, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0$$3);
			if (Z_TYPE_P(&key) != IS_STRING) {
				continue;
			}
			ZEPHIR_OBS_NVAR(&attribute);
			if (!(zephir_array_isset_fetch(&attribute, columnMap, &key, 0 TSRMLS_CC))) {
				if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
					ZEPHIR_INIT_NVAR(&_3$$7);
					object_init_ex(&_3$$7, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4$$7);
					ZEPHIR_CONCAT_SVS(&_4$$7, "Column '", &key, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_3$$7, "__construct", &_5, 9, &_4$$7);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_3$$7, "phalcon/mvc/model.zep", 3621 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					continue;
				}
			}
			if (Z_TYPE_P(&attribute) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attribute);
				if (!(zephir_array_isset_long_fetch(&attribute, &attribute, 0, 0 TSRMLS_CC))) {
					if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
						ZEPHIR_INIT_NVAR(&_6$$11);
						object_init_ex(&_6$$11, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_7$$11);
						ZEPHIR_CONCAT_SVS(&_7$$11, "Column '", &key, "' doesn't make part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_6$$11, "__construct", &_5, 9, &_7$$11);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_6$$11, "phalcon/mvc/model.zep", 3630 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					} else {
						continue;
					}
				}
			}
			zephir_array_update_zval(&snapshot, &attribute, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
		zephir_update_property_zval(this_ptr, SL("_snapshot"), &snapshot);
		RETURN_MM_NULL();
	}
	zephir_update_property_zval(this_ptr, SL("_snapshot"), &data);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if the object has internal snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, hasSnapshotData) {

	zval snapshot;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&snapshot);


	zephir_read_property(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(Z_TYPE_P(&snapshot) == IS_ARRAY);

}

/**
 * Returns the internal snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, getSnapshotData) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_snapshot");

}

/**
 * Check if a specific attribute has changed
 * This only works if the model is keeping data snapshots
 *
 * @param string|array fieldName
 */
PHP_METHOD(Phalcon_Mvc_Model, hasChanged) {

	zend_string *_12;
	zend_ulong _11;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *fieldName = NULL, fieldName_sub, __$null, snapshot, metaData, columnMap, allAttributes, value, originalValue, name, _0, _9, *_10, _1$$9, _2$$9, _3$$11, _4$$11, _5$$12, _6$$12, _7$$13, _8$$13;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&fieldName_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&allAttributes);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&originalValue);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$9);
	ZVAL_UNDEF(&_2$$9);
	ZVAL_UNDEF(&_3$$11);
	ZVAL_UNDEF(&_4$$11);
	ZVAL_UNDEF(&_5$$12);
	ZVAL_UNDEF(&_6$$12);
	ZVAL_UNDEF(&_7$$13);
	ZVAL_UNDEF(&_8$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &fieldName);

	if (!fieldName) {
		fieldName = &fieldName_sub;
		fieldName = &__$null;
	}


	ZEPHIR_OBS_VAR(&snapshot);
	zephir_read_property(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
	if (Z_TYPE_P(&snapshot) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record doesn't have a valid data snapshot", "phalcon/mvc/model.zep", 3679);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("_dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_LONG(&_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Change checking cannot be performed because the object has not been persisted or is deleted", "phalcon/mvc/model.zep", 3686);
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getreversecolumnmap", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&columnMap) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&allAttributes, &metaData, "getdatatypes", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&allAttributes, &columnMap);
	}
	if (Z_TYPE_P(fieldName) == IS_STRING) {
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			if (!(zephir_array_isset(&columnMap, fieldName))) {
				ZEPHIR_INIT_VAR(&_1$$9);
				object_init_ex(&_1$$9, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_2$$9);
				ZEPHIR_CONCAT_SVS(&_2$$9, "The field '", fieldName, "' is not part of the model");
				ZEPHIR_CALL_METHOD(NULL, &_1$$9, "__construct", NULL, 9, &_2$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_1$$9, "phalcon/mvc/model.zep", 3718 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			if (!(zephir_array_isset(&allAttributes, fieldName))) {
				ZEPHIR_INIT_VAR(&_3$$11);
				object_init_ex(&_3$$11, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_4$$11);
				ZEPHIR_CONCAT_SVS(&_4$$11, "The field '", fieldName, "' is not part of the model");
				ZEPHIR_CALL_METHOD(NULL, &_3$$11, "__construct", NULL, 9, &_4$$11);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$11, "phalcon/mvc/model.zep", 3722 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_OBS_VAR(&value);
		if (!(zephir_fetch_property_zval(&value, this_ptr, fieldName, PH_SILENT_CC))) {
			ZEPHIR_INIT_VAR(&_5$$12);
			object_init_ex(&_5$$12, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_6$$12);
			ZEPHIR_CONCAT_SVS(&_6$$12, "The field '", fieldName, "' is not defined on the model");
			ZEPHIR_CALL_METHOD(NULL, &_5$$12, "__construct", NULL, 9, &_6$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$12, "phalcon/mvc/model.zep", 3730 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(&originalValue);
		if (!(zephir_array_isset_fetch(&originalValue, &snapshot, fieldName, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(&_7$$13);
			object_init_ex(&_7$$13, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(&_8$$13);
			ZEPHIR_CONCAT_SVS(&_8$$13, "The field '", fieldName, "' was not found in the snapshot");
			ZEPHIR_CALL_METHOD(NULL, &_7$$13, "__construct", NULL, 9, &_8$$13);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_7$$13, "phalcon/mvc/model.zep", 3737 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(!ZEPHIR_IS_EQUAL(&value, &originalValue));
	}
	ZEPHIR_INIT_VAR(&_9);
	zephir_is_iterable(&allAttributes, 0, "phalcon/mvc/model.zep", 3773);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&allAttributes), _11, _12, _10)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_12 != NULL) { 
			ZVAL_STR_COPY(&name, _12);
		} else {
			ZVAL_LONG(&name, _11);
		}
		ZEPHIR_INIT_NVAR(&_9);
		ZVAL_COPY(&_9, _10);
		ZEPHIR_OBS_NVAR(&originalValue);
		if (!(zephir_array_isset_fetch(&originalValue, &snapshot, &name, 0 TSRMLS_CC))) {
			RETURN_MM_BOOL(1);
		}
		ZEPHIR_OBS_NVAR(&value);
		if (!(zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC))) {
			RETURN_MM_BOOL(1);
		}
		if (!ZEPHIR_IS_EQUAL(&value, &originalValue)) {
			RETURN_MM_BOOL(1);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&_9);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_MM_BOOL(0);

}

/**
 * Returns a list of changed values
 */
PHP_METHOD(Phalcon_Mvc_Model, getChangedFields) {

	zend_string *_4;
	zend_ulong _3;
	zval metaData, changed, name, snapshot, columnMap, allAttributes, value, _0, _1, *_2, _5$$7;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&changed);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&snapshot);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&allAttributes);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$7);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&snapshot);
	zephir_read_property(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
	if (Z_TYPE_P(&snapshot) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record doesn't have a valid data snapshot", "phalcon/mvc/model.zep", 3786);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("_dirtyState"), PH_NOISY_CC | PH_READONLY);
	if (!ZEPHIR_IS_LONG(&_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Change checking cannot be performed because the object has not been persisted or is deleted", "phalcon/mvc/model.zep", 3793);
		return;
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getreversecolumnmap", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (Z_TYPE_P(&columnMap) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&allAttributes, &metaData, "getdatatypes", NULL, 0, this_ptr);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&allAttributes, &columnMap);
	}
	ZEPHIR_INIT_VAR(&changed);
	array_init(&changed);
	ZEPHIR_INIT_VAR(&_1);
	zephir_is_iterable(&allAttributes, 0, "phalcon/mvc/model.zep", 3847);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&allAttributes), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&name, _4);
		} else {
			ZVAL_LONG(&name, _3);
		}
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_COPY(&_1, _2);
		if (!(zephir_array_isset(&snapshot, &name))) {
			zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/mvc/model.zep", 3826);
			continue;
		}
		ZEPHIR_OBS_NVAR(&value);
		if (!(zephir_fetch_property_zval(&value, this_ptr, &name, PH_SILENT_CC))) {
			zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/mvc/model.zep", 3834);
			continue;
		}
		zephir_array_fetch(&_5$$7, &snapshot, &name, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 3841 TSRMLS_CC);
		if (!ZEPHIR_IS_EQUAL(&value, &_5$$7)) {
			zephir_array_append(&changed, &name, PH_SEPARATE, "phalcon/mvc/model.zep", 3842);
			continue;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(changed);

}

/**
 * Sets if a model must use dynamic update instead of the all-field update
 *
 *<code>
 *<?php
 *use Phalcon\Mvc\Model;
 *
 *class Robots extends Model
 *{
 *
 *   public function initialize()
 *   {
 *		$this->useDynamicUpdate(true);
 *   }
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, useDynamicUpdate) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *dynamicUpdate_param = NULL, _0, _1;
	zend_bool dynamicUpdate;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dynamicUpdate_param);

	dynamicUpdate = zephir_get_boolval(dynamicUpdate_param);


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	if (dynamicUpdate) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "usedynamicupdate", NULL, 0, this_ptr, &_1);
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

	zval _4, _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, *arguments = NULL, arguments_sub, __$null, relation, className, manager, _0, _1, _5, _2$$3, _3$$3;
	zval alias;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &alias_param, &arguments);

	zephir_get_strval(&alias, alias_param);
	if (!arguments) {
		arguments = &arguments_sub;
		arguments = &__$null;
	}


	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, this_ptr, 0 TSRMLS_CC);
	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_1, &manager, "getrelationbyalias", NULL, 0, &className, &alias);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_1);
	if (Z_TYPE_P(&relation) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVSVS(&_3$$3, "There is no defined relations for the model '", &className, "' using alias '", &alias, "'");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 9, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/mvc/model.zep", 3890 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_4, &manager);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "getRelationRecords");
	zephir_array_fast_append(&_4, &_5);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(&_6, &relation);
	zephir_array_fast_append(&_6, &__$null);
	zephir_array_fast_append(&_6, this_ptr);
	zephir_array_fast_append(&_6, arguments);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_4, &_6);
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

	zval _7$$6, _9$$6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *method_param = NULL, *arguments, arguments_sub, manager, relation, queryMethod, extraArgs, _0, _1$$3, _2$$3, _3$$3, _4$$5, _5$$5, _6$$5, _8$$6;
	zval modelName, method;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&queryMethod);
	ZVAL_UNDEF(&extraArgs);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &modelName_param, &method_param, &arguments);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(&modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(&modelName);
		ZVAL_EMPTY_STRING(&modelName);
	}
	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}


	zephir_read_property(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_INIT_VAR(&relation);
	ZVAL_BOOL(&relation, 0);
	ZEPHIR_INIT_VAR(&queryMethod);
	ZVAL_NULL(&queryMethod);
	if (zephir_start_with_str(&method, SL("get"))) {
		ZVAL_LONG(&_2$$3, 3);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_substr(&_3$$3, &method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(&_1$$3, &manager, "getrelationbyalias", NULL, 0, &modelName, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&relation, &_1$$3);
	}
	if (Z_TYPE_P(&relation) != IS_OBJECT) {
		if (zephir_start_with_str(&method, SL("count"))) {
			ZEPHIR_INIT_NVAR(&queryMethod);
			ZVAL_STRING(&queryMethod, "count");
			ZVAL_LONG(&_5$$5, 5);
			ZEPHIR_INIT_VAR(&_6$$5);
			zephir_substr(&_6$$5, &method, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CALL_METHOD(&_4$$5, &manager, "getrelationbyalias", NULL, 0, &modelName, &_6$$5);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&relation, &_4$$5);
		}
	}
	if (Z_TYPE_P(&relation) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(&extraArgs);
		zephir_array_isset_long_fetch(&extraArgs, arguments, 0, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_7$$6);
		zephir_create_array(&_7$$6, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_7$$6, &manager);
		ZEPHIR_INIT_VAR(&_8$$6);
		ZVAL_STRING(&_8$$6, "getRelationRecords");
		zephir_array_fast_append(&_7$$6, &_8$$6);
		ZEPHIR_INIT_VAR(&_9$$6);
		zephir_create_array(&_9$$6, 4, 0 TSRMLS_CC);
		zephir_array_fast_append(&_9$$6, &relation);
		zephir_array_fast_append(&_9$$6, &queryMethod);
		zephir_array_fast_append(&_9$$6, this_ptr);
		zephir_array_fast_append(&_9$$6, &extraArgs);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_7$$6, &_9$$6);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

/**
 * Try to check if the query must invoke a finder
 *
 * @param  string method
 * @param  array arguments
 * @return \Phalcon\Mvc\ModelInterface[]|\Phalcon\Mvc\ModelInterface|boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _invokeFinder) {

	zval _9, _11;
	zend_class_entry *_6, *_12;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method, method_sub, *arguments, arguments_sub, extraMethod, type, modelName, value, model, attributes, field, extraMethodFirst, metaData, _5, _10, _0$$3, _1$$5, _2$$7, _3$$9, _4$$9, _7$$15, _8$$15;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&method_sub);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_UNDEF(&extraMethod);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&extraMethodFirst);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_3$$9);
	ZVAL_UNDEF(&_4$$9);
	ZVAL_UNDEF(&_7$$15);
	ZVAL_UNDEF(&_8$$15);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method, &arguments);



	ZEPHIR_INIT_VAR(&extraMethod);
	ZVAL_NULL(&extraMethod);
	if (zephir_start_with_str(method, SL("findFirstBy"))) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "findFirst");
		ZVAL_LONG(&_0$$3, 11);
		ZEPHIR_INIT_NVAR(&extraMethod);
		zephir_substr(&extraMethod, method, 11 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	}
	if (Z_TYPE_P(&extraMethod) == IS_NULL) {
		if (zephir_start_with_str(method, SL("findBy"))) {
			ZEPHIR_INIT_NVAR(&type);
			ZVAL_STRING(&type, "find");
			ZVAL_LONG(&_1$$5, 6);
			ZEPHIR_INIT_NVAR(&extraMethod);
			zephir_substr(&extraMethod, method, 6 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		}
	}
	if (Z_TYPE_P(&extraMethod) == IS_NULL) {
		if (zephir_start_with_str(method, SL("countBy"))) {
			ZEPHIR_INIT_NVAR(&type);
			ZVAL_STRING(&type, "count");
			ZVAL_LONG(&_2$$7, 7);
			ZEPHIR_INIT_NVAR(&extraMethod);
			zephir_substr(&extraMethod, method, 7 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		}
	}
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_called_class(&modelName TSRMLS_CC);
	if (!(zephir_is_true(&extraMethod))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_OBS_VAR(&value);
	if (!(zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_3$$9);
		object_init_ex(&_3$$9, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$9);
		ZEPHIR_CONCAT_SVS(&_4$$9, "The static method '", method, "' requires one argument");
		ZEPHIR_CALL_METHOD(NULL, &_3$$9, "__construct", NULL, 9, &_4$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$9, "phalcon/mvc/model.zep", 4002 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&model);
	zephir_fetch_safe_class(&_5, &modelName);
	_6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_5), Z_STRLEN_P(&_5), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&model, _6);
	if (zephir_has_constructor(&model TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &model, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&metaData, &model, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&attributes, &metaData, "getreversecolumnmap", NULL, 0, &model);
	zephir_check_call_status();
	if (Z_TYPE_P(&attributes) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&attributes, &metaData, "getdatatypes", NULL, 0, &model);
		zephir_check_call_status();
	}
	if (zephir_array_isset(&attributes, &extraMethod)) {
		ZEPHIR_CPY_WRT(&field, &extraMethod);
	} else {
		ZEPHIR_CALL_FUNCTION(&extraMethodFirst, "lcfirst", NULL, 68, &extraMethod);
		zephir_check_call_status();
		if (zephir_array_isset(&attributes, &extraMethodFirst)) {
			ZEPHIR_CPY_WRT(&field, &extraMethodFirst);
		} else {
			ZEPHIR_INIT_NVAR(&field);
			zephir_uncamelize(&field, &extraMethod, NULL  );
			if (!(zephir_array_isset(&attributes, &field))) {
				ZEPHIR_INIT_VAR(&_7$$15);
				object_init_ex(&_7$$15, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(&_8$$15);
				ZEPHIR_CONCAT_SVS(&_8$$15, "Cannot resolve attribute '", &extraMethod, "' in the model");
				ZEPHIR_CALL_METHOD(NULL, &_7$$15, "__construct", NULL, 9, &_8$$15);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$15, "phalcon/mvc/model.zep", 4036 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_SVS(&_10, "[", &field, "] = ?0");
	zephir_array_update_string(&_9, SL("conditions"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_11);
	zephir_create_array(&_11, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_11, &value);
	zephir_array_update_string(&_9, SL("bind"), &_11, PH_COPY | PH_SEPARATE);
	_12 = zephir_fetch_class(&modelName TSRMLS_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC_ZVAL(_12, type, NULL, 0, &_9);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *method_param = NULL, *arguments, arguments_sub, modelName, status, records, _1, _2, _3;
	zval method;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &arguments);

	zephir_get_strval(&method, method_param);


	ZEPHIR_CALL_SELF(&records, "_invokefinder", &_0, 322, &method, arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(&records) != IS_NULL) {
		RETURN_CCTOR(records);
	}
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", NULL, 0, &modelName, &method, arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(&records) != IS_NULL) {
		RETURN_CCTOR(records);
	}
	zephir_read_property(&_1, this_ptr, SL("_modelsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&status, &_1, "missingmethod", NULL, 0, this_ptr, &method, arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(&status) != IS_NULL) {
		RETURN_CCTOR(status);
	}
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SVSVS(&_3, "The method '", &method, "' doesn't exist on model '", &modelName, "'");
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 9, &_3);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_2, "phalcon/mvc/model.zep", 4087 TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *method_param = NULL, *arguments, arguments_sub, records, _1$$3;
	zval method, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_UNDEF(&records);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &arguments);

	zephir_get_strval(&method, method_param);


	ZEPHIR_CALL_SELF(&records, "_invokefinder", &_0, 322, &method, arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(&records) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "The static method '", &method, "' doesn't exist");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 9, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/mvc/model.zep", 4103 TSRMLS_CC);
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

	zend_string *_3$$6;
	zend_ulong _2$$6;
	zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *value, value_sub, lowerProperty, related, modelName, manager, lowerKey, relation, referencedModel, key, item, dirtyState, _9, _10, _0$$4, *_1$$6, _4$$10, _6$$11, _8$$12, _11$$14;
	zval property, _12$$14;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&lowerProperty);
	ZVAL_UNDEF(&related);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&lowerKey);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&referencedModel);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&dirtyState);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_6$$11);
	ZVAL_UNDEF(&_8$$12);
	ZVAL_UNDEF(&_11$$14);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &value);

	zephir_get_strval(&property, property_param);


	if (Z_TYPE_P(value) == IS_OBJECT) {
		if (zephir_instance_of_ev(value, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
			ZEPHIR_OBS_VAR(&dirtyState);
			zephir_read_property(&dirtyState, this_ptr, SL("_dirtyState"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_0$$4, value, "getdirtystate", NULL, 0);
			zephir_check_call_status();
			if (!ZEPHIR_IS_EQUAL(&_0$$4, &dirtyState)) {
				ZEPHIR_INIT_NVAR(&dirtyState);
				ZVAL_LONG(&dirtyState, 1);
			}
			ZEPHIR_INIT_VAR(&lowerProperty);
			zephir_fast_strtolower(&lowerProperty, &property);
			zephir_update_property_zval_zval(this_ptr, &lowerProperty, value TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("_related"), &lowerProperty, value TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("_dirtyState"), &dirtyState);
			RETVAL_ZVAL(value, 1, 0);
			RETURN_MM();
		}
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&lowerProperty);
		zephir_fast_strtolower(&lowerProperty, &property);
		ZEPHIR_INIT_VAR(&modelName);
		zephir_get_class(&modelName, this_ptr, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&related);
		array_init(&related);
		zephir_is_iterable(value, 0, "phalcon/mvc/model.zep", 4163);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(value), _2$$6, _3$$6, _1$$6)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3$$6 != NULL) { 
				ZVAL_STR_COPY(&key, _3$$6);
			} else {
				ZVAL_LONG(&key, _2$$6);
			}
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _1$$6);
			if (Z_TYPE_P(&item) == IS_OBJECT) {
				if (zephir_instance_of_ev(&item, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
					zephir_array_append(&related, &item, PH_SEPARATE, "phalcon/mvc/model.zep", 4150);
				}
			} else {
				ZEPHIR_INIT_NVAR(&lowerKey);
				zephir_fast_strtolower(&lowerKey, &key);
				zephir_update_property_zval_zval(this_ptr, &lowerKey, &item TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_4$$10, &manager, "getrelationbyalias", &_5, 0, &modelName, &lowerProperty);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&relation, &_4$$10);
				if (Z_TYPE_P(&relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&_6$$11, &relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, &manager, "load", &_7, 0, &_6$$11);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &referencedModel, "writeattribute", NULL, 0, &lowerKey, &item);
					zephir_check_call_status();
				}
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&item);
		ZEPHIR_INIT_NVAR(&key);
		if (zephir_fast_count_int(&related TSRMLS_CC) > 0) {
			zephir_update_property_array(this_ptr, SL("_related"), &lowerProperty, &related TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_8$$12);
			ZVAL_LONG(&_8$$12, 1);
			zephir_update_property_zval(this_ptr, SL("_dirtyState"), &_8$$12);
		}
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "_possiblesetter", NULL, 314, &property, value);
	zephir_check_call_status();
	if (zephir_is_true(&_9)) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_10, this_ptr, "_isvisible", NULL, 323, &property);
	zephir_check_call_status();
	if (!(zephir_is_true(&_10))) {
		ZEPHIR_INIT_VAR(&_11$$14);
		object_init_ex(&_11$$14, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(&_12$$14);
		ZEPHIR_CONCAT_SVS(&_12$$14, "Property '", &property, "' does not have a setter.");
		ZEPHIR_CALL_METHOD(NULL, &_11$$14, "__construct", NULL, 9, &_12$$14);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$14, "phalcon/mvc/model.zep", 4178 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval_zval(this_ptr, &property, value TSRMLS_CC);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *value, value_sub, possibleSetter, _0;
	zval property;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&possibleSetter);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &value);

	zephir_get_strval(&property, property_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_camelize(&_0, &property, NULL  );
	ZEPHIR_INIT_VAR(&possibleSetter);
	ZEPHIR_CONCAT_SV(&possibleSetter, "set", &_0);
	if ((zephir_method_exists(this_ptr, &possibleSetter TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &possibleSetter, NULL, 0, value);
		zephir_check_call_status();
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Check whether a property is declared private or protected.
 * This is a stop-gap because we do not want to have to declare all properties.
 *
 * @param string property
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _isVisible) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property, property_sub, reflectionClass, reflectionProp, e, _0$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&property_sub);
	ZVAL_UNDEF(&reflectionClass);
	ZVAL_UNDEF(&reflectionProp);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property);



	ZEPHIR_INIT_VAR(&reflectionClass);
	object_init_ex(&reflectionClass, zephir_get_internal_ce(SL("reflectionclass")));
	ZEPHIR_CALL_METHOD(NULL, &reflectionClass, "__construct", NULL, 94, this_ptr);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&reflectionProp, &reflectionClass, "getproperty", NULL, 324, property);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_0$$3, &reflectionProp, "ispublic", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		if (!(zephir_is_true(&_0$$3))) {
			RETURN_MM_BOOL(0);
		}

	try_end_1:

	if (EG(exception)) {
		ZVAL_OBJ(&e, EG(exception));
		Z_ADDREF_P(&e);
		if (zephir_instance_of_ev(&e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Magic method to get related records using the relation alias as a property
 *
 * @param string property
 * @return \Phalcon\Mvc\Model\Resultset|Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, __get) {

	zval _1$$3, _3$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, __$null, modelName, manager, lowerProperty, relation, result, method, _0, _4, _5, _2$$3;
	zval property;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&property);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&lowerProperty);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (unlikely(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(&property, property_param);
	} else {
		ZEPHIR_INIT_VAR(&property);
		ZVAL_EMPTY_STRING(&property);
	}


	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&lowerProperty);
	zephir_fast_strtolower(&lowerProperty, &property);
	ZEPHIR_CALL_METHOD(&_0, &manager, "getrelationbyalias", NULL, 0, &modelName, &lowerProperty);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_0);
	if (Z_TYPE_P(&relation) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_1$$3, &manager);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "getRelationRecords");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 4, 0 TSRMLS_CC);
		zephir_array_fast_append(&_3$$3, &relation);
		zephir_array_fast_append(&_3$$3, &__$null);
		zephir_array_fast_append(&_3$$3, this_ptr);
		zephir_array_fast_append(&_3$$3, &__$null);
		ZEPHIR_INIT_VAR(&result);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&result, &_1$$3, &_3$$3);
		zephir_check_call_status();
		if (Z_TYPE_P(&result) == IS_OBJECT) {
			zephir_update_property_zval_zval(this_ptr, &lowerProperty, &result TSRMLS_CC);
			if (zephir_instance_of_ev(&result, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
				zephir_update_property_array(this_ptr, SL("_related"), &lowerProperty, &result TSRMLS_CC);
			}
		}
		RETURN_CCTOR(result);
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_camelize(&_4, &property, NULL  );
	ZEPHIR_INIT_VAR(&method);
	ZEPHIR_CONCAT_SV(&method, "get", &_4);
	if ((zephir_method_exists(this_ptr, &method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVSV(&_5, "Access to undefined property ", &modelName, "::", &property);
	ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 2, &_5);
	zephir_check_call_status();
	RETURN_MM_NULL();

}

/**
 * Magic method to check if a property is a valid relation
 */
PHP_METHOD(Phalcon_Mvc_Model, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, modelName, manager, relation, _0;
	zval property;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relation);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (unlikely(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(&property, property_param);
	} else {
		ZEPHIR_INIT_VAR(&property);
		ZVAL_EMPTY_STRING(&property);
	}


	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&manager, &_0);
	ZEPHIR_CALL_METHOD(&_0, &manager, "getrelationbyalias", NULL, 0, &modelName, &property);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&relation, &_0);
	RETURN_MM_BOOL(Z_TYPE_P(&relation) == IS_OBJECT);

}

/**
 * Serializes the object ignoring connections, services, related objects or static properties
 */
PHP_METHOD(Phalcon_Mvc_Model, serialize) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 65, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes the object from a serialized string
 */
PHP_METHOD(Phalcon_Mvc_Model, unserialize) {

	zend_string *_5$$3;
	zend_ulong _4$$3;
	zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, attributes, dependencyInjector, manager, key, value, _1$$3, _2$$3, *_3$$3;
	zval data;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	if (unlikely(Z_TYPE_P(data_param) != IS_STRING && Z_TYPE_P(data_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(data_param) == IS_STRING)) {
		zephir_get_strval(&data, data_param);
	} else {
		ZEPHIR_INIT_VAR(&data);
		ZVAL_EMPTY_STRING(&data);
	}


	ZEPHIR_CALL_FUNCTION(&attributes, "unserialize", NULL, 66, &data);
	zephir_check_call_status();
	if (Z_TYPE_P(&attributes) == IS_ARRAY) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 1);
		zephir_check_call_status();
		if (Z_TYPE_P(&dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model.zep", 4338);
			return;
		}
		zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), &dependencyInjector);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "modelsManager");
		ZEPHIR_CALL_METHOD(&_1$$3, &dependencyInjector, "getshared", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&manager, &_1$$3);
		if (Z_TYPE_P(&manager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/mvc/model.zep", 4351);
			return;
		}
		zephir_update_property_zval(this_ptr, SL("_modelsManager"), &manager);
		ZEPHIR_CALL_METHOD(NULL, &manager, "initialize", NULL, 0, this_ptr);
		zephir_check_call_status();
		zephir_is_iterable(&attributes, 0, "phalcon/mvc/model.zep", 4370);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&attributes), _4$$3, _5$$3, _3$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_5$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _5$$3);
			} else {
				ZVAL_LONG(&key, _4$$3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _3$$3);
			zephir_update_property_zval_zval(this_ptr, &key, &value TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a simple representation of the object that can be used with var_dump
 *
 *<code>
 * var_dump($robot->dump());
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, dump) {

	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 18, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the instance as an array representation
 *
 *<code>
 * print_r($robot->toArray());
 *</code>
 *
 * @param array $columns
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model, toArray) {

	zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *columns = NULL, columns_sub, __$null, data, metaData, columnMap, attribute, attributeField, value, _0, *_1, _2$$6, _3$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&columns_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&attribute);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &columns);

	if (!columns) {
		columns = &columns_sub;
		columns = &__$null;
	}


	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/mvc/model.zep", 4434);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&attribute);
		ZVAL_COPY(&attribute, _1);
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &attribute, 0 TSRMLS_CC))) {
				if (!(ZEPHIR_GLOBAL(orm).ignore_unknown_columns)) {
					ZEPHIR_INIT_NVAR(&_2$$6);
					object_init_ex(&_2$$6, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_3$$6);
					ZEPHIR_CONCAT_SVS(&_3$$6, "Column '", &attribute, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_2$$6, "__construct", &_4, 9, &_3$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_2$$6, "phalcon/mvc/model.zep", 4412 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				} else {
					continue;
				}
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, &attribute);
		}
		if (Z_TYPE_P(columns) == IS_ARRAY) {
			if (!(zephir_fast_in_array(&attributeField, columns TSRMLS_CC))) {
				continue;
			}
		}
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
			zephir_array_update_zval(&data, &attributeField, &value, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&data, &attributeField, &__$null, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&attribute);
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

	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Enables/disables options in the ORM
 */
PHP_METHOD(Phalcon_Mvc_Model, setup) {

	zval *options_param = NULL, disableEvents, columnRenaming, notNullValidations, exceptionOnFailedSave, phqlLiterals, virtualForeignKeys, lateStateBinding, castOnHydrate, ignoreUnknownColumns;
	zval options;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&disableEvents);
	ZVAL_UNDEF(&columnRenaming);
	ZVAL_UNDEF(&notNullValidations);
	ZVAL_UNDEF(&exceptionOnFailedSave);
	ZVAL_UNDEF(&phqlLiterals);
	ZVAL_UNDEF(&virtualForeignKeys);
	ZVAL_UNDEF(&lateStateBinding);
	ZVAL_UNDEF(&castOnHydrate);
	ZVAL_UNDEF(&ignoreUnknownColumns);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	ZEPHIR_OBS_VAR_ONCE(&options);
	ZVAL_COPY(&options, options_param);


	ZEPHIR_OBS_VAR(&disableEvents);
	if (zephir_array_isset_string_fetch(&disableEvents, &options, SL("events"), 0)) {
		ZEPHIR_GLOBAL(orm).events = zend_is_true(&disableEvents);
	}
	ZEPHIR_OBS_VAR(&virtualForeignKeys);
	if (zephir_array_isset_string_fetch(&virtualForeignKeys, &options, SL("virtualForeignKeys"), 0)) {
		ZEPHIR_GLOBAL(orm).virtual_foreign_keys = zend_is_true(&virtualForeignKeys);
	}
	ZEPHIR_OBS_VAR(&columnRenaming);
	if (zephir_array_isset_string_fetch(&columnRenaming, &options, SL("columnRenaming"), 0)) {
		ZEPHIR_GLOBAL(orm).column_renaming = zend_is_true(&columnRenaming);
	}
	ZEPHIR_OBS_VAR(&notNullValidations);
	if (zephir_array_isset_string_fetch(&notNullValidations, &options, SL("notNullValidations"), 0)) {
		ZEPHIR_GLOBAL(orm).not_null_validations = zend_is_true(&notNullValidations);
	}
	ZEPHIR_OBS_VAR(&exceptionOnFailedSave);
	if (zephir_array_isset_string_fetch(&exceptionOnFailedSave, &options, SL("exceptionOnFailedSave"), 0)) {
		ZEPHIR_GLOBAL(orm).exception_on_failed_save = zend_is_true(&exceptionOnFailedSave);
	}
	ZEPHIR_OBS_VAR(&phqlLiterals);
	if (zephir_array_isset_string_fetch(&phqlLiterals, &options, SL("phqlLiterals"), 0)) {
		ZEPHIR_GLOBAL(orm).enable_literals = zend_is_true(&phqlLiterals);
	}
	ZEPHIR_OBS_VAR(&lateStateBinding);
	if (zephir_array_isset_string_fetch(&lateStateBinding, &options, SL("lateStateBinding"), 0)) {
		ZEPHIR_GLOBAL(orm).late_state_binding = zend_is_true(&lateStateBinding);
	}
	ZEPHIR_OBS_VAR(&castOnHydrate);
	if (zephir_array_isset_string_fetch(&castOnHydrate, &options, SL("castOnHydrate"), 0)) {
		ZEPHIR_GLOBAL(orm).cast_on_hydrate = zend_is_true(&castOnHydrate);
	}
	ZEPHIR_OBS_VAR(&ignoreUnknownColumns);
	if (zephir_array_isset_string_fetch(&ignoreUnknownColumns, &options, SL("ignoreUnknownColumns"), 0)) {
		ZEPHIR_GLOBAL(orm).ignore_unknown_columns = zend_is_true(&ignoreUnknownColumns);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Reset a model instance data
 */
PHP_METHOD(Phalcon_Mvc_Model, reset) {

	zval __$null;
	ZEPHIR_INIT_THIS();

	ZVAL_NULL(&__$null);


	zephir_update_property_zval(this_ptr, SL("_uniqueParams"), &__$null);
	zephir_update_property_zval(this_ptr, SL("_snapshot"), &__$null);

}

