
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
 * <p>Phalcon\Mvc\Model connects business objects and database tables to create
 * a persistable domain model where logic and data are presented in one wrapping.
 * It‘s an implementation of the object-relational mapping (ORM).</p>
 *
 * <p>A model represents the information (data) of the application and the rules to manipulate that data.
 * Models are primarily used for managing the rules of interaction with a corresponding database table.
 * In most cases, each table in your database will correspond to one model in your application.
 * The bulk of your application's business logic will be concentrated in the models.</p>
 *
 * <p>Phalcon\Mvc\Model is the first ORM written in C-language for PHP, giving to developers high performance
 * when interacting with databases while is also easy to use.</p>
 *
 * <code>
 *
 * $robot = new Robots();
 * $robot->type = 'mechanical';
 * $robot->name = 'Astro Boy';
 * $robot->year = 1952;
 * if ($robot->save() == false) {
 *  echo "Umh, We can store robots: ";
 *  foreach ($robot->getMessages() as $message) {
 *    echo message;
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

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_NONE"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_CREATE"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_UPDATE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_DELETE"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_PERSISTENT"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_TRANSIENT"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("DIRTY_STATE_DETACHED"), 2 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_mvc_modelinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_mvc_model_resultinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 1, zend_ce_serializable);
	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model constructor
 */
PHP_METHOD(Phalcon_Mvc_Model, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *dependencyInjector = NULL, *modelsManager = NULL, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &dependencyInjector, &modelsManager);

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


	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 147);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model.zep", 135);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "modelsManager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(modelsManager, _1);
		if (Z_TYPE_P(modelsManager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/mvc/model.zep", 146);
			return;
		}
	}
	zephir_update_property_this(this_ptr, SL("_modelsManager"), modelsManager TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, modelsManager, "initialize", NULL, 0, this_ptr);
	zephir_check_call_status();
	if ((zephir_method_exists_ex(this_ptr, SS("onconstruct") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
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



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the dependency injection container
 */
PHP_METHOD(Phalcon_Mvc_Model, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets a custom events manager
 */
PHP_METHOD(Phalcon_Mvc_Model, setEventsManager) {

	int ZEPHIR_LAST_CALL_STATUS;
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *metaData = NULL, *dependencyInjector = NULL, *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_modelsMetaData"), PH_NOISY_CC);
	if (Z_TYPE_P(metaData) != IS_OBJECT) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(dependencyInjector, _0);
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model.zep", 215);
			return;
		}
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(metaData, _1);
		if (Z_TYPE_P(metaData) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsMetadata' is not valid", "phalcon/mvc/model.zep", 223);
			return;
		}
		zephir_update_property_this(this_ptr, SL("_modelsMetaData"), metaData TSRMLS_CC);
	}
	RETURN_CCTOR(metaData);

}

/**
 * Returns the models manager related to the entity instance
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsManager) {


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
 *    $transaction->rollback("Can't save robot");
 *  }
 *
 *  $robotPart = new RobotParts();
 *  $robotPart->setTransaction($transaction);
 *  $robotPart->type = 'head';
 *  if ($robotPart->save() == false) {
 *    $transaction->rollback("Robot part cannot be saved");
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

	zval *transaction;

	zephir_fetch_params(0, 1, 0, &transaction);



	zephir_update_property_this(this_ptr, SL("_transaction"), transaction TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Sets table name which model should be mapped
 */
PHP_METHOD(Phalcon_Mvc_Model, setSource) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, *_0;
	zval *source = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &source_param);

	if (unlikely(Z_TYPE_P(source_param) != IS_STRING && Z_TYPE_P(source_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'source' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(source_param) == IS_STRING)) {
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
 * Returns table name mapped in the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getSource) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getmodelsource", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets schema name where table mapped is located
 */
PHP_METHOD(Phalcon_Mvc_Model, setSchema) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *schema_param = NULL, *_0;
	zval *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &schema_param);

	if (unlikely(Z_TYPE_P(schema_param) != IS_STRING && Z_TYPE_P(schema_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(schema_param) == IS_STRING)) {
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
 * Returns schema name where table mapped is located
 */
PHP_METHOD(Phalcon_Mvc_Model, getSchema) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, *_0;
	zval *connectionService = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, *_0;
	zval *connectionService = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *connectionService_param = NULL, *_0;
	zval *connectionService = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

	if (unlikely(Z_TYPE_P(connectionService_param) != IS_STRING && Z_TYPE_P(connectionService_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'connectionService' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(connectionService_param) == IS_STRING)) {
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

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
	int dirtyState;

	zephir_fetch_params(0, 1, 0, &dirtyState_param);

	dirtyState = zephir_get_intval(dirtyState_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, dirtyState);
	zephir_update_property_this(this_ptr, SL("_dirtyState"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns one of the DIRTY_STATE_* constants telling if the record exists in the database or not
 */
PHP_METHOD(Phalcon_Mvc_Model, getDirtyState) {


	RETURN_MEMBER(this_ptr, "_dirtyState");

}

/**
 * Gets the connection used to read data for the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getreadconnection", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets the connection used to write data to the model
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *transaction = NULL, *_0;

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
 * $robot->assign(array(
 *    'type' => 'mechanical',
 *    'name' => 'Astro Boy',
 *    'year' => 1952
 * ));
 *
 * //assign by db row, column map needed
 * $robot->assign($dbRow, array(
 *    'db_type' => 'type',
 *    'db_name' => 'name',
 *    'db_year' => 'year'
 * ));
 *
 * //allow assign only name and year
 * $robot->assign($_POST, null, array('name', 'year');
 *
 *</code>
 *
 * @param array data
 * @param array dataColumnMap array to transform keys of data to another
 * @param array whiteList
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, assign) {

	zephir_fcall_cache_entry *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1, *_5;
	HashPosition _0, _4;
	zval *data_param = NULL, *dataColumnMap = NULL, *whiteList = NULL, *key = NULL, *keyMapped = NULL, *value = NULL, *attribute = NULL, *attributeField = NULL, *possibleSetter = NULL, *metaData = NULL, *columnMap = NULL, *dataMapped = NULL, **_2, *_3 = NULL, **_6, *_7 = NULL, *_8 = NULL;
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


	if (Z_TYPE_P(dataColumnMap) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(dataMapped);
		array_init(dataMapped);
		zephir_is_iterable(data, &_1, &_0, 0, 0, "phalcon/mvc/model.zep", 438);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(key, _1, _0);
			ZEPHIR_GET_HVALUE(value, _2);
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
	zephir_is_iterable(_3, &_5, &_4, 0, 0, "phalcon/mvc/model.zep", 486);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(attribute, _6);
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, columnMap, attribute, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_7);
				object_init_ex(_7, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_8);
				ZEPHIR_CONCAT_SVS(_8, "Column '", attribute, "' doesn\\'t make part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _7, "__construct", &_9, 2, _8);
				zephir_check_call_status();
				zephir_throw_exception_debug(_7, "phalcon/mvc/model.zep", 459 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
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
			ZEPHIR_INIT_NVAR(possibleSetter);
			ZEPHIR_CONCAT_SV(possibleSetter, "set", attributeField);
			if ((zephir_method_exists(this_ptr, possibleSetter TSRMLS_CC)  == SUCCESS)) {
				ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, possibleSetter, NULL, 0, value);
				zephir_check_call_status();
			} else {
				zephir_update_property_zval_zval(this_ptr, attributeField, value TSRMLS_CC);
			}
		}
	}
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
 * @param Phalcon\Mvc\ModelInterface|Phalcon\Mvc\Model\Row base
 * @param array data
 * @param array columnMap
 * @param int dirtyState
 * @param boolean keepSnapshots
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMap) {

	zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_2;
	HashPosition _1;
	zend_bool keepSnapshots;
	int dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *base, *data_param = NULL, *columnMap, *dirtyState_param = NULL, *keepSnapshots_param = NULL, *instance, *attribute = NULL, *key = NULL, *value = NULL, *_0 = NULL, **_3, *_4 = NULL;

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
	zephir_is_iterable(data, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 543);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (Z_TYPE_P(key) == IS_STRING) {
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attribute);
				if (zephir_array_isset_fetch(&attribute, columnMap, key, 0 TSRMLS_CC)) {
					zephir_update_property_zval_zval(instance, attribute, value TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(_0);
					object_init_ex(_0, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SVS(_4, "Column '", key, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_5, 2, _4);
					zephir_check_call_status();
					zephir_throw_exception_debug(_0, "phalcon/mvc/model.zep", 532 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				zephir_update_property_zval_zval(instance, key, value TSRMLS_CC);
			}
		}
	}
	if (keepSnapshots) {
		ZEPHIR_CALL_METHOD(NULL, instance, "setsnapshotdata", NULL, 0, data, columnMap);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(instance, SS("afterfetch") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "afterfetch", NULL, 0);
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

	zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_1;
	HashPosition _0;
	int hydrationMode, ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *columnMap, *hydrationMode_param = NULL, *hydrateArray, *hydrateObject, *key = NULL, *value = NULL, *attribute = NULL, **_2, *_3 = NULL, *_4 = NULL;
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
	zephir_is_iterable(data, &_1, &_0, 0, 0, "phalcon/mvc/model.zep", 613);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if (Z_TYPE_P(key) == IS_STRING) {
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, key, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_3);
					object_init_ex(_3, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SVS(_4, "Column '", key, "' doesn't make part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, 2, _4);
					zephir_check_call_status();
					zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 595 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (hydrationMode == 1) {
					zephir_array_update_zval(&hydrateArray, attribute, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_update_property_zval_zval(hydrateObject, attribute, value TSRMLS_CC);
				}
			} else {
				if (hydrationMode == 1) {
					zephir_array_update_zval(&hydrateArray, key, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_update_property_zval_zval(hydrateObject, key, value TSRMLS_CC);
				}
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
 *$robot = Phalcon\Mvc\Model::cloneResult(new Robots(), array(
 *  'type' => 'mechanical',
 *  'name' => 'Astro Boy',
 *  'year' => 1952
 *));
 *</code>
 *
 * @param Phalcon\Mvc\ModelInterface $base
 * @param array data
 * @param int dirtyState
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResult) {

	HashTable *_2;
	HashPosition _1;
	int dirtyState, ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *base, *data_param = NULL, *dirtyState_param = NULL, *instance, *key = NULL, *value = NULL, *_0, **_3;

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
	zephir_is_iterable(data, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 660);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if (Z_TYPE_P(key) != IS_STRING) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Invalid key in array data provided to dumpResult()", "phalcon/mvc/model.zep", 652);
			return;
		}
		zephir_update_property_zval_zval(instance, key, value TSRMLS_CC);
	}
	if ((zephir_method_exists_ex(instance, SS("afterfetch") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, instance, "afterfetch", NULL, 0);
		zephir_check_call_status();
	}
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
	zval *parameters = NULL, *params = NULL, *builder = NULL, *query = NULL, *bindParams, *bindTypes = NULL, *cache, *resultset = NULL, *hydration, *dependencyInjector = NULL, *manager = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 147);
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
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/mvc/model.zep", 705);
		}
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_CALL_METHOD(&builder, manager, "createbuilder", NULL, 0, params);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	zephir_get_called_class(_2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, builder, "from", NULL, 0, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&query, builder, "getquery", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, params, SS("bind"), 0 TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(bindTypes);
		zephir_array_isset_string_fetch(&bindTypes, params, SS("bindTypes"), 0 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(bindTypes);
		ZVAL_NULL(bindTypes);
	}
	ZEPHIR_OBS_VAR(cache);
	if (zephir_array_isset_string_fetch(&cache, params, SS("cache"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, query, "cache", NULL, 0, cache);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&resultset, query, "execute", NULL, 0, bindParams, bindTypes);
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
 * @param array parameters
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, findFirst) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *parameters = NULL, *params = NULL, *builder = NULL, *query = NULL, *bindParams = NULL, *bindTypes = NULL, *cache, *resultset = NULL, *hydration, *dependencyInjector = NULL, *manager = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 147);
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
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/mvc/model.zep", 783);
		}
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_CALL_METHOD(&builder, manager, "createbuilder", NULL, 0, params);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	zephir_get_called_class(_2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, builder, "from", NULL, 0, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 1);
	ZEPHIR_CALL_METHOD(NULL, builder, "limit", NULL, 0, _3);
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
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_BOOL(_3, 1);
	ZEPHIR_CALL_METHOD(NULL, query, "setuniquerow", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&resultset, query, "execute", NULL, 0, bindParams, bindTypes);
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
 * Create a criteria for a specific model
 */
PHP_METHOD(Phalcon_Mvc_Model, query) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *dependencyInjector = NULL, *criteria = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		ZEPHIR_CPY_WRT(dependencyInjector, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(dependencyInjector);
	}


	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 147);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(criteria);
	if (zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "Phalcon\\Mvc\\Model\\Criteria", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "get", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(criteria, _1);
	} else {
		object_init_ex(criteria, phalcon_mvc_model_criteria_ce);
		if (zephir_has_constructor(criteria TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, criteria, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, criteria, "setdi", NULL, 294, dependencyInjector);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	zephir_get_called_class(_2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, criteria, "setmodelname", NULL, 295, _2);
	zephir_check_call_status();
	RETURN_CCTOR(criteria);

}

/**
 * Checks if the current record already exists or not
 *
 * @param Phalcon\Mvc\Model\MetadataInterface metaData
 * @param Phalcon\Db\AdapterInterface connection
 * @param string|array table
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _exists) {

	zend_bool _6;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	HashTable *_1;
	HashPosition _0;
	int numberEmpty, numberPrimary, ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, *connection, *table = NULL, *uniqueParams = NULL, *uniqueTypes = NULL, *uniqueKey = NULL, *columnMap = NULL, *primaryKeys = NULL, *wherePk, *field = NULL, *attributeField = NULL, *value = NULL, *bindDataTypes = NULL, *joinWhere, *num = NULL, *type = NULL, *schema = NULL, *source = NULL, **_2, *_3 = NULL, *_4 = NULL, *_7 = NULL, *_9 = NULL, *_10, *_11, *_12;

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
		zephir_is_iterable(primaryKeys, &_1, &_0, 0, 0, "phalcon/mvc/model.zep", 956);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(field, _2);
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_3);
					object_init_ex(_3, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SVS(_4, "Column '", field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, 2, _4);
					zephir_check_call_status();
					zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 920 TSRMLS_CC);
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
				_6 = Z_TYPE_P(value) == IS_NULL;
				if (!(_6)) {
					_6 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
				}
				if (_6) {
					numberEmpty++;
				}
				zephir_array_append(&uniqueParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 938);
			} else {
				zephir_array_append(&uniqueParams, ZEPHIR_GLOBAL(global_null), PH_SEPARATE, "phalcon/mvc/model.zep", 941);
				numberEmpty++;
			}
			ZEPHIR_OBS_NVAR(type);
			if (!(zephir_array_isset_fetch(&type, bindDataTypes, field, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_3);
				object_init_ex(_3, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "Column '", field, "' isn't part of the table columns");
				ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, 2, _4);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 946 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&uniqueTypes, type, PH_SEPARATE, "phalcon/mvc/model.zep", 949);
			ZEPHIR_CALL_METHOD(&_7, connection, "escapeidentifier", &_8, 0, field);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_9);
			ZEPHIR_CONCAT_VS(_9, _7, " = ?");
			zephir_array_append(&wherePk, _9, PH_SEPARATE, "phalcon/mvc/model.zep", 950);
		}
		if (numberPrimary == numberEmpty) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(joinWhere);
		zephir_fast_join_str(joinWhere, SL(" AND "), wherePk TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_uniqueKey"), joinWhere TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_uniqueParams"), uniqueParams TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_uniqueTypes"), uniqueTypes TSRMLS_CC);
		ZEPHIR_CPY_WRT(uniqueKey, joinWhere);
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("_dirtyState"), PH_NOISY_CC);
	if (!(zephir_is_true(_10))) {
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
	ZEPHIR_CALL_METHOD(&_7, connection, "escapeidentifier", NULL, 0, table);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_9);
	ZEPHIR_CONCAT_SVSV(_9, "SELECT COUNT(*) \"rowcount\" FROM ", _7, " WHERE ", uniqueKey);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_NULL(_3);
	ZEPHIR_CALL_METHOD(&num, connection, "fetchone", NULL, 0, _9, _3, uniqueParams, uniqueTypes);
	zephir_check_call_status();
	zephir_array_fetch_string(&_11, num, SL("rowcount"), PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1006 TSRMLS_CC);
	if (zephir_is_true(_11)) {
		ZEPHIR_INIT_ZVAL_NREF(_12);
		ZVAL_LONG(_12, 0);
		zephir_update_property_this(this_ptr, SL("_dirtyState"), _12 TSRMLS_CC);
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_12);
		ZVAL_LONG(_12, 1);
		zephir_update_property_this(this_ptr, SL("_dirtyState"), _12 TSRMLS_CC);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Generate a PHQL SELECT statement for an aggregate
 *
 * @param string function
 * @param string alias
 * @param array parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, _groupResult) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *functionName_param = NULL, *alias_param = NULL, *parameters, *params = NULL, *distinctColumn, *groupColumn = NULL, *columns = NULL, *bindParams = NULL, *bindTypes = NULL, *resultset = NULL, *cache, *firstRow = NULL, *groupColumns, *builder = NULL, *query = NULL, *dependencyInjector = NULL, *manager = NULL, *_1 = NULL, *_2 = NULL, *_3;
	zval *functionName = NULL, *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &functionName_param, &alias_param, &parameters);

	if (unlikely(Z_TYPE_P(functionName_param) != IS_STRING && Z_TYPE_P(functionName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'functionName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(functionName_param) == IS_STRING)) {
		zephir_get_strval(functionName, functionName_param);
	} else {
		ZEPHIR_INIT_VAR(functionName);
		ZVAL_EMPTY_STRING(functionName);
	}
	if (unlikely(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_EMPTY_STRING(alias);
	}


	ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 147);
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
			zephir_array_append(&params, parameters, PH_SEPARATE, "phalcon/mvc/model.zep", 1035);
		}
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_OBS_VAR(groupColumn);
	if (!(zephir_array_isset_string_fetch(&groupColumn, params, SS("column"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(groupColumn);
		ZVAL_LONG(groupColumn, '*');
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
 * Allows to count how many records match the specified conditions
 *
 * <code>
 *
 * //How many robots are there?
 * $number = Robots::count();
 * echo "There are ", $number, "\n";
 *
 * //How many mechanical robots are there?
 * $number = Robots::count("type='mechanical'");
 * echo "There are ", $number, " mechanical robots\n";
 *
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, count) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *parameters = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		parameters = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "COUNT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "rowcount", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_RETURN_CALL_SELF("_groupresult", NULL, 0, _0, _1, parameters);
	zephir_check_temp_parameter(_0);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	RETURN_MM();

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
 * $sum = Robots::sum(array("type='mechanical'", 'column' => 'price'));
 * echo "The total price of mechanical robots is  ", $sum, "\n";
 *
 * </code>
 *
 * @param array parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, sum) {

	int ZEPHIR_LAST_CALL_STATUS;
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, *_0;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

	if (unlikely(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(eventName_param) == IS_STRING)) {
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, *_0 = NULL, *_1;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

	if (unlikely(Z_TYPE_P(eventName_param) != IS_STRING && Z_TYPE_P(eventName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'eventName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(eventName_param) == IS_STRING)) {
		zephir_get_strval(eventName, eventName_param);
	} else {
		ZEPHIR_INIT_VAR(eventName);
		ZVAL_EMPTY_STRING(eventName);
	}


	if ((zephir_method_exists(this_ptr, eventName TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(&_0, this_ptr, eventName,  NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
			RETURN_MM_BOOL(0);
		}
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, _1, "notifyevent", NULL, 0, eventName, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Cancel the current operation
 */
PHP_METHOD(Phalcon_Mvc_Model, _cancelOperation) {

	zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_operationMade"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_0, 3)) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "notDeleted", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_2, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "notSaved", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_2, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Appends a customized message on the validation process
 *
 * <code>
 * use \Phalcon\Mvc\Model\Message as Message;
 *
 * class Robots extends \Phalcon\Mvc\Model
 * {
 *
 *   public function beforeSave()
 *   {
 *     if ($this->name == 'Peter') {
 *        $message = new Message("Sorry, but a robot cannot be named Peter");
 *        $this->appendMessage($message);
 *     }
 *   }
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
 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 *class Subscriptors extends \Phalcon\Mvc\Model
 *{
 *
 *	public function validation()
 *  {
 * 		$this->validate(new ExclusionIn(array(
 *			'field' => 'status',
 *			'domain' => array('A', 'I')
 *		)));
 *		if ($this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, validate) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *validator, *message = NULL, *_0 = NULL, *_1 = NULL, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &validator);



	ZEPHIR_CALL_METHOD(&_0, validator, "validate", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		ZEPHIR_CALL_METHOD(&_1, validator, "getmessages", NULL, 0);
		zephir_check_call_status();
		zephir_is_iterable(_1, &_3, &_2, 0, 0, "phalcon/mvc/model.zep", 1330);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(message, _4);
			zephir_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);
		}
	}
	RETURN_THIS();

}

/**
 * Check whether validation process has generated any messages
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionIn;
 *
 *class Subscriptors extends \Phalcon\Mvc\Model
 *{
 *
 *	public function validation()
 *  {
 * 		$this->validate(new ExclusionIn(array(
 *			'field' => 'status',
 *			'domain' => array('A', 'I')
 *		)));
 *		if ($this->validationHasFailed() == true) {
 *			return false;
 *		}
 *	}
 *
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, validationHasFailed) {

	zval *errorMessages;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(errorMessages);
	zephir_read_property_this(&errorMessages, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
	if (Z_TYPE_P(errorMessages) == IS_ARRAY) {
		RETURN_MM_BOOL(zephir_fast_count_int(errorMessages TSRMLS_CC) > 0);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns all the validation messages
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

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_3;
	HashPosition _2;
	zend_bool _0;
	zval *filter = NULL, *filtered, *message = NULL, *_1, **_4, *_5 = NULL;

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
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_errorMessages"), PH_NOISY_CC);
		zephir_is_iterable(_1, &_3, &_2, 0, 0, "phalcon/mvc/model.zep", 1397);
		for (
		  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		  ; zephir_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(message, _4);
			ZEPHIR_CALL_METHOD(&_5, message, "getfield", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_EQUAL(_5, filter)) {
				zephir_array_append(&filtered, message, PH_SEPARATE, "phalcon/mvc/model.zep", 1394);
			}
		}
		RETURN_CCTOR(filtered);
	}
	RETURN_MM_MEMBER(this_ptr, "_errorMessages");

}

/**
 * Reads "belongs to" relations and check the virtual foreign keys when inserting or updating records
 * to verify that inserted/updated values are present in the related entity
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysRestrict) {

	zval *_14 = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_18 = NULL, *_19 = NULL;
	HashTable *_2, *_8;
	HashPosition _1, _7;
	zend_bool error, validateWithNulls = 0, _12;
	int action, numberNull, ZEPHIR_LAST_CALL_STATUS;
	zval *manager = NULL, *belongsTo = NULL, *foreignKey = NULL, *relation = NULL, *conditions = NULL, *position = NULL, *bindParams = NULL, *extraConditions = NULL, *message = NULL, *fields = NULL, *referencedFields = NULL, *field = NULL, *referencedModel = NULL, *value = NULL, *allowNulls = NULL, *_0, **_3, *_4 = NULL, *_5 = NULL, **_9, *_10, *_11 = NULL, *_13 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_CALL_METHOD(&belongsTo, manager, "getbelongsto", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (zephir_fast_count_int(belongsTo TSRMLS_CC)) {
		error = 0;
		zephir_is_iterable(belongsTo, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 1540);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(relation, _3);
			ZEPHIR_CALL_METHOD(&foreignKey, relation, "getforeignkey", NULL, 0);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(foreignKey)) {
				action = 1;
				if (Z_TYPE_P(foreignKey) == IS_ARRAY) {
					if (zephir_array_isset_string(foreignKey, SS("action"))) {
						ZEPHIR_OBS_NVAR(_4);
						zephir_array_fetch_string(&_4, foreignKey, SL("action"), PH_NOISY, "phalcon/mvc/model.zep", 1441 TSRMLS_CC);
						action = zephir_get_intval(_4);
					}
				}
				if (action == 1) {
					ZEPHIR_CALL_METHOD(&_5, relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, manager, "load", &_6, 0, _5);
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
						zephir_is_iterable(fields, &_8, &_7, 0, 0, "phalcon/mvc/model.zep", 1477);
						for (
						  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
						  ; zephir_hash_move_forward_ex(_8, &_7)
						) {
							ZEPHIR_GET_HMKEY(position, _8, _7);
							ZEPHIR_GET_HVALUE(field, _9);
							ZEPHIR_OBS_NVAR(value);
							zephir_fetch_property_zval(&value, this_ptr, field, PH_SILENT_CC);
							zephir_array_fetch(&_10, referencedFields, position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1470 TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_11);
							ZEPHIR_CONCAT_SVSV(_11, "[", _10, "] = ?", position);
							zephir_array_append(&conditions, _11, PH_SEPARATE, "phalcon/mvc/model.zep", 1470);
							zephir_array_append(&bindParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 1471);
							if (Z_TYPE_P(value) == IS_NULL) {
								numberNull++;
							}
						}
						validateWithNulls = numberNull == zephir_fast_count_int(fields TSRMLS_CC);
					} else {
						ZEPHIR_OBS_NVAR(value);
						zephir_fetch_property_zval(&value, this_ptr, fields, PH_SILENT_CC);
						ZEPHIR_INIT_LNVAR(_11);
						ZEPHIR_CONCAT_SVS(_11, "[", referencedFields, "] = ?0");
						zephir_array_append(&conditions, _11, PH_SEPARATE, "phalcon/mvc/model.zep", 1482);
						zephir_array_append(&bindParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 1483);
						if (Z_TYPE_P(value) == IS_NULL) {
							validateWithNulls = 1;
						}
					}
					ZEPHIR_OBS_NVAR(extraConditions);
					if (zephir_array_isset_string_fetch(&extraConditions, foreignKey, SS("conditions"), 0 TSRMLS_CC)) {
						zephir_array_append(&conditions, extraConditions, PH_SEPARATE, "phalcon/mvc/model.zep", 1494);
					}
					if (validateWithNulls) {
						ZEPHIR_OBS_NVAR(allowNulls);
						if (zephir_array_isset_string_fetch(&allowNulls, foreignKey, SS("allowNulls"), 0 TSRMLS_CC)) {
							validateWithNulls = zephir_get_boolval(allowNulls);
						} else {
							validateWithNulls = 0;
						}
					}
					_12 = !validateWithNulls;
					if (_12) {
						ZEPHIR_INIT_NVAR(_14);
						zephir_create_array(_14, 2, 0 TSRMLS_CC);
						ZEPHIR_INIT_NVAR(_15);
						zephir_fast_join_str(_15, SL(" AND "), conditions TSRMLS_CC);
						zephir_array_fast_append(_14, _15);
						zephir_array_update_string(&_14, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
						ZEPHIR_CALL_METHOD(&_13, referencedModel, "count", NULL, 0, _14);
						zephir_check_call_status();
						_12 = !zephir_is_true(_13);
					}
					if (_12) {
						ZEPHIR_OBS_NVAR(message);
						if (!(zephir_array_isset_string_fetch(&message, foreignKey, SS("message"), 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(message);
							if (Z_TYPE_P(fields) == IS_ARRAY) {
								ZEPHIR_INIT_NVAR(_15);
								zephir_fast_join_str(_15, SL(", "), fields TSRMLS_CC);
								ZEPHIR_CONCAT_SVS(message, "Value of fields \"", _15, "\" does not exist on referenced table");
							} else {
								ZEPHIR_CONCAT_SVS(message, "Value of field \"", fields, "\" does not exist on referenced table");
							}
						}
						ZEPHIR_INIT_NVAR(_16);
						object_init_ex(_16, phalcon_mvc_model_message_ce);
						ZEPHIR_INIT_NVAR(_17);
						ZVAL_STRING(_17, "ConstraintViolation", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, _16, "__construct", &_18, 296, message, fields, _17);
						zephir_check_temp_parameter(_17);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_19, 0, _16);
						zephir_check_call_status();
						error = 1;
						break;
					}
				}
			}
		}
		if (error == 1) {
			if (ZEPHIR_GLOBAL(orm).events) {
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_STRING(_15, "onValidationFails", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _15);
				zephir_check_temp_parameter(_15);
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

	zval *_12 = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_2, *_8;
	HashPosition _1, _7;
	int action, ZEPHIR_LAST_CALL_STATUS;
	zval *manager = NULL, *relations = NULL, *relation = NULL, *foreignKey = NULL, *resultset = NULL, *conditions = NULL, *bindParams = NULL, *referencedModel = NULL, *referencedFields = NULL, *fields = NULL, *field = NULL, *position = NULL, *value = NULL, *extraConditions = NULL, *_0, **_3, *_4 = NULL, *_5 = NULL, **_9, *_10, *_11 = NULL, *_13 = NULL, *_14 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_CALL_METHOD(&relations, manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (zephir_fast_count_int(relations TSRMLS_CC)) {
		zephir_is_iterable(relations, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 1654);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(relation, _3);
			ZEPHIR_CALL_METHOD(&foreignKey, relation, "getforeignkey", NULL, 0);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(foreignKey)) {
				action = 0;
				if (Z_TYPE_P(foreignKey) == IS_ARRAY) {
					if (zephir_array_isset_string(foreignKey, SS("action"))) {
						ZEPHIR_OBS_NVAR(_4);
						zephir_array_fetch_string(&_4, foreignKey, SL("action"), PH_NOISY, "phalcon/mvc/model.zep", 1593 TSRMLS_CC);
						action = zephir_get_intval(_4);
					}
				}
				if (action == 2) {
					ZEPHIR_CALL_METHOD(&_5, relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, manager, "load", &_6, 0, _5);
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
						zephir_is_iterable(fields, &_8, &_7, 0, 0, "phalcon/mvc/model.zep", 1621);
						for (
						  ; zephir_hash_get_current_data_ex(_8, (void**) &_9, &_7) == SUCCESS
						  ; zephir_hash_move_forward_ex(_8, &_7)
						) {
							ZEPHIR_GET_HMKEY(position, _8, _7);
							ZEPHIR_GET_HVALUE(field, _9);
							ZEPHIR_OBS_NVAR(value);
							zephir_fetch_property_zval(&value, this_ptr, field, PH_SILENT_CC);
							zephir_array_fetch(&_10, referencedFields, position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1618 TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_11);
							ZEPHIR_CONCAT_SVSV(_11, "[", _10, "] = ?", position);
							zephir_array_append(&conditions, _11, PH_SEPARATE, "phalcon/mvc/model.zep", 1618);
							zephir_array_append(&bindParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 1619);
						}
					} else {
						ZEPHIR_OBS_NVAR(value);
						zephir_fetch_property_zval(&value, this_ptr, fields, PH_SILENT_CC);
						ZEPHIR_INIT_LNVAR(_11);
						ZEPHIR_CONCAT_SVS(_11, "[", referencedFields, "] = ?0");
						zephir_array_append(&conditions, _11, PH_SEPARATE, "phalcon/mvc/model.zep", 1623);
						zephir_array_append(&bindParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 1624);
					}
					ZEPHIR_OBS_NVAR(extraConditions);
					if (zephir_array_isset_string_fetch(&extraConditions, foreignKey, SS("conditions"), 0 TSRMLS_CC)) {
						zephir_array_append(&conditions, extraConditions, PH_SEPARATE, "phalcon/mvc/model.zep", 1631);
					}
					ZEPHIR_INIT_NVAR(_12);
					zephir_create_array(_12, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_13);
					zephir_fast_join_str(_13, SL(" AND "), conditions TSRMLS_CC);
					zephir_array_fast_append(_12, _13);
					zephir_array_update_string(&_12, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&resultset, referencedModel, "find", NULL, 0, _12);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_14, resultset, "delete", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_FALSE_IDENTICAL(_14)) {
						RETURN_MM_BOOL(0);
					}
				}
			}
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (restrict) when deleting records
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseRestrict) {

	zval *_12 = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_15 = NULL, *_16 = NULL;
	HashTable *_2, *_7;
	HashPosition _1, _6;
	int action, ZEPHIR_LAST_CALL_STATUS;
	zval *manager = NULL, *relations = NULL, *foreignKey = NULL, *relation = NULL, *relationClass = NULL, *referencedModel = NULL, *fields = NULL, *referencedFields = NULL, *conditions = NULL, *bindParams = NULL, *position = NULL, *field = NULL, *value = NULL, *extraConditions = NULL, *message = NULL, *_0, **_3, *_4 = NULL, **_8, *_9, *_10 = NULL, *_11 = NULL, *_13 = NULL, *_14 = NULL;
	zend_bool error;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_CALL_METHOD(&relations, manager, "gethasoneandhasmany", NULL, 0, this_ptr);
	zephir_check_call_status();
	if (zephir_fast_count_int(relations TSRMLS_CC)) {
		error = 0;
		zephir_is_iterable(relations, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 1773);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(relation, _3);
			ZEPHIR_CALL_METHOD(&foreignKey, relation, "getforeignkey", NULL, 0);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(foreignKey)) {
				action = 1;
				if (Z_TYPE_P(foreignKey) == IS_ARRAY) {
					if (zephir_array_isset_string(foreignKey, SS("action"))) {
						ZEPHIR_OBS_NVAR(_4);
						zephir_array_fetch_string(&_4, foreignKey, SL("action"), PH_NOISY, "phalcon/mvc/model.zep", 1701 TSRMLS_CC);
						action = zephir_get_intval(_4);
					}
				}
				if (action == 1) {
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
						zephir_is_iterable(fields, &_7, &_6, 0, 0, "phalcon/mvc/model.zep", 1733);
						for (
						  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
						  ; zephir_hash_move_forward_ex(_7, &_6)
						) {
							ZEPHIR_GET_HMKEY(position, _7, _6);
							ZEPHIR_GET_HVALUE(field, _8);
							ZEPHIR_OBS_NVAR(value);
							zephir_fetch_property_zval(&value, this_ptr, field, PH_SILENT_CC);
							zephir_array_fetch(&_9, referencedFields, position, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 1729 TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_10);
							ZEPHIR_CONCAT_SVSV(_10, "[", _9, "] = ?", position);
							zephir_array_append(&conditions, _10, PH_SEPARATE, "phalcon/mvc/model.zep", 1729);
							zephir_array_append(&bindParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 1730);
						}
					} else {
						ZEPHIR_OBS_NVAR(value);
						zephir_fetch_property_zval(&value, this_ptr, fields, PH_SILENT_CC);
						ZEPHIR_INIT_LNVAR(_10);
						ZEPHIR_CONCAT_SVS(_10, "[", referencedFields, "] = ?0");
						zephir_array_append(&conditions, _10, PH_SEPARATE, "phalcon/mvc/model.zep", 1735);
						zephir_array_append(&bindParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 1736);
					}
					ZEPHIR_OBS_NVAR(extraConditions);
					if (zephir_array_isset_string_fetch(&extraConditions, foreignKey, SS("conditions"), 0 TSRMLS_CC)) {
						zephir_array_append(&conditions, extraConditions, PH_SEPARATE, "phalcon/mvc/model.zep", 1743);
					}
					ZEPHIR_INIT_NVAR(_12);
					zephir_create_array(_12, 2, 0 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_13);
					zephir_fast_join_str(_13, SL(" AND "), conditions TSRMLS_CC);
					zephir_array_fast_append(_12, _13);
					zephir_array_update_string(&_12, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_11, referencedModel, "count", NULL, 0, _12);
					zephir_check_call_status();
					if (zephir_is_true(_11)) {
						ZEPHIR_OBS_NVAR(message);
						if (!(zephir_array_isset_string_fetch(&message, foreignKey, SS("message"), 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(message);
							ZEPHIR_CONCAT_SV(message, "Record is referenced by model ", relationClass);
						}
						ZEPHIR_INIT_NVAR(_13);
						object_init_ex(_13, phalcon_mvc_model_message_ce);
						ZEPHIR_INIT_NVAR(_14);
						ZVAL_STRING(_14, "ConstraintViolation", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, _13, "__construct", &_15, 296, message, fields, _14);
						zephir_check_temp_parameter(_14);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_16, 0, _13);
						zephir_check_call_status();
						error = 1;
						break;
					}
				}
			}
		}
		if (error == 1) {
			if (ZEPHIR_GLOBAL(orm).events) {
				ZEPHIR_INIT_NVAR(_13);
				ZVAL_STRING(_13, "onValidationFails", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _13);
				zephir_check_temp_parameter(_13);
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

	HashTable *_5;
	HashPosition _4;
	zephir_fcall_cache_entry *_2 = NULL, *_8 = NULL, *_11 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool exists, error, isNull, _9;
	zval *metaData, *exists_param = NULL, *identityField, *notNull = NULL, *columnMap = NULL, *dataTypeNumeric = NULL, *automaticAttributes = NULL, *defaultValues = NULL, *field = NULL, *attributeField = NULL, *value = NULL, *emptyStringValues = NULL, *_0 = NULL, *_1 = NULL, *_3 = NULL, **_6, *_7 = NULL, *_10 = NULL, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &metaData, &exists_param, &identityField);

	exists = zephir_get_boolval(exists_param);


	if (ZEPHIR_GLOBAL(orm).events) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "beforeValidation", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "fireeventcancel", &_2, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
			RETURN_MM_BOOL(0);
		}
		if (!(exists)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "beforeValidationOnCreate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_3, this_ptr, "fireeventcancel", &_2, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "beforeValidationOnUpdate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_3, this_ptr, "fireeventcancel", &_2, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "_checkforeignkeysrestrict", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
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
				ZEPHIR_CALL_METHOD(&defaultValues, metaData, "getdefaultvalues", NULL, 0, this_ptr);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&emptyStringValues, metaData, "getemptystringattributes", NULL, 0, this_ptr);
			zephir_check_call_status();
			error = 0;
			zephir_is_iterable(notNull, &_5, &_4, 0, 0, "phalcon/mvc/model.zep", 1939);
			for (
			  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_5, &_4)
			) {
				ZEPHIR_GET_HVALUE(field, _6);
				if (!(zephir_array_isset(automaticAttributes, field))) {
					isNull = 0;
					if (Z_TYPE_P(columnMap) == IS_ARRAY) {
						ZEPHIR_OBS_NVAR(attributeField);
						if (!(zephir_array_isset_fetch(&attributeField, columnMap, field, 0 TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(_1);
							object_init_ex(_1, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_7);
							ZEPHIR_CONCAT_SVS(_7, "Column '", field, "' isn't part of the column map");
							ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_8, 2, _7);
							zephir_check_call_status();
							zephir_throw_exception_debug(_1, "phalcon/mvc/model.zep", 1875 TSRMLS_CC);
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
									_9 = Z_TYPE_P(value) == IS_NULL;
									if (!(_9)) {
										_9 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
									}
									if (_9) {
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
						ZEPHIR_INIT_NVAR(_1);
						object_init_ex(_1, phalcon_mvc_model_message_ce);
						ZEPHIR_INIT_LNVAR(_7);
						ZEPHIR_CONCAT_VS(_7, attributeField, " is required");
						ZEPHIR_INIT_NVAR(_10);
						ZVAL_STRING(_10, "PresenceOf", ZEPHIR_TEMP_PARAM_COPY);
						ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_11, 296, _7, attributeField, _10);
						zephir_check_temp_parameter(_10);
						zephir_check_call_status();
						zephir_update_property_array_append(this_ptr, SL("_errorMessages"), _1 TSRMLS_CC);
						error = 1;
					}
				}
			}
			if (error == 1) {
				if (ZEPHIR_GLOBAL(orm).events) {
					ZEPHIR_INIT_NVAR(_1);
					ZVAL_STRING(_1, "onValidationFails", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_12, 0, _1);
					zephir_check_temp_parameter(_1);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
					zephir_check_call_status();
				}
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "validation", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fireeventcancel", &_2, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
		if (ZEPHIR_GLOBAL(orm).events) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "onValidationFails", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_12, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
		}
		RETURN_MM_BOOL(0);
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (!(exists)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "afterValidationOnCreate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_0, this_ptr, "fireeventcancel", &_2, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_0)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "afterValidationOnUpdate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_3, this_ptr, "fireeventcancel", &_2, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "afterValidation", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "fireeventcancel", &_2, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "beforeSave", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, this_ptr, "fireeventcancel", &_2, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
			RETURN_MM_BOOL(0);
		}
		zephir_update_property_this(this_ptr, SL("_skipped"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		if (exists) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "beforeUpdate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_3, this_ptr, "fireeventcancel", &_2, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_STRING(_1, "beforeCreate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_3, this_ptr, "fireeventcancel", &_2, 0, _1);
			zephir_check_temp_parameter(_1);
			zephir_check_call_status();
			if (ZEPHIR_IS_FALSE_IDENTICAL(_3)) {
				RETURN_MM_BOOL(0);
			}
		}
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_skipped"), PH_NOISY_CC);
		if (ZEPHIR_IS_TRUE_IDENTICAL(_13)) {
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
	zval *success_param = NULL, *exists_param = NULL, *_0 = NULL;
	zend_bool success, exists;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &success_param, &exists_param);

	success = zephir_get_boolval(success_param);
	exists = zephir_get_boolval(exists_param);


	if (success == 1) {
		if (exists) {
			ZEPHIR_INIT_VAR(_0);
			ZVAL_STRING(_0, "afterUpdate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_1, 0, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "afterCreate", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_1, 0, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
		}
	}
	RETURN_MM_BOOL(success);

}

/**
 * Sends a pre-build INSERT SQL statement to the relational database system
 *
 * @param Phalcon\Mvc\Model\MetadataInterface metaData
 * @param Phalcon\Db\AdapterInterface connection
 * @param string|array table
 * @param boolean|string identityField
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowInsert) {

	zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool useExplicitIdentity, _6;
	zval *metaData, *connection, *table, *identityField, *bindSkip, *fields, *values, *bindTypes, *attributes = NULL, *bindDataTypes = NULL, *automaticAttributes = NULL, *field = NULL, *columnMap = NULL, *value = NULL, *attributeField = NULL, *success = NULL, *bindType = NULL, *defaultValue = NULL, *sequenceName = NULL, *defaultValues = NULL, *source = NULL, *schema = NULL, **_2, *_3 = NULL, *_4 = NULL, *_7 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &metaData, &connection, &table, &identityField);



	ZEPHIR_INIT_VAR(bindSkip);
	ZVAL_LONG(bindSkip, 1024);
	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	ZEPHIR_INIT_VAR(values);
	array_init(values);
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
	zephir_is_iterable(attributes, &_1, &_0, 0, 0, "phalcon/mvc/model.zep", 2121);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(field, _2);
		if (!(zephir_array_isset(automaticAttributes, field))) {
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_3);
					object_init_ex(_3, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SVS(_4, "Column '", field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, 2, _4);
					zephir_check_call_status();
					zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 2077 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, field);
			}
			if (!ZEPHIR_IS_EQUAL(field, identityField)) {
				zephir_array_append(&fields, field, PH_SEPARATE, "phalcon/mvc/model.zep", 2088);
				ZEPHIR_OBS_NVAR(value);
				if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
					_6 = Z_TYPE_P(value) == IS_NULL;
					if (_6) {
						_6 = zephir_array_isset(defaultValues, field);
					}
					if (_6) {
						ZEPHIR_OBS_NVAR(value);
						zephir_array_fetch(&value, defaultValues, field, PH_NOISY, "phalcon/mvc/model.zep", 2096 TSRMLS_CC);
					}
					ZEPHIR_OBS_NVAR(bindType);
					if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, field, 0 TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(_3);
						object_init_ex(_3, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_4);
						ZEPHIR_CONCAT_SVS(_4, "Column '", field, "' have not defined a bind data type");
						ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, 2, _4);
						zephir_check_call_status();
						zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 2103 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&values, value, PH_SEPARATE, "phalcon/mvc/model.zep", 2106);
					zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 2106);
				} else {
					zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 2109);
					ZEPHIR_OBS_NVAR(value);
					zephir_array_isset_fetch(&value, defaultValues, field, 0 TSRMLS_CC);
					zephir_array_append(&values, value, PH_SEPARATE, "phalcon/mvc/model.zep", 2112);
				}
			}
		}
	}
	if (!ZEPHIR_IS_FALSE_IDENTICAL(identityField)) {
		ZEPHIR_CALL_METHOD(&defaultValue, connection, "getdefaultidvalue", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7, connection, "useexplicitidvalue", NULL, 0);
		zephir_check_call_status();
		useExplicitIdentity = zephir_get_boolval(_7);
		if (useExplicitIdentity) {
			zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/mvc/model.zep", 2130);
		}
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, columnMap, identityField, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_3);
				object_init_ex(_3, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "Identity column '", identityField, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, 2, _4);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 2138 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(attributeField, identityField);
		}
		ZEPHIR_OBS_NVAR(value);
		if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
			_6 = Z_TYPE_P(value) == IS_NULL;
			if (!(_6)) {
				_6 = ZEPHIR_IS_STRING_IDENTICAL(value, "");
			}
			if (_6) {
				if (useExplicitIdentity) {
					zephir_array_append(&values, defaultValue, PH_SEPARATE, "phalcon/mvc/model.zep", 2151);
					zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 2151);
				}
			} else {
				if (!(useExplicitIdentity)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE, "phalcon/mvc/model.zep", 2159);
				}
				ZEPHIR_OBS_NVAR(bindType);
				if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, identityField, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_3);
					object_init_ex(_3, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SVS(_4, "Identity column '", identityField, "' isn\\'t part of the table columns");
					ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, 2, _4);
					zephir_check_call_status();
					zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 2166 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, value, PH_SEPARATE, "phalcon/mvc/model.zep", 2169);
				zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 2169);
			}
		} else {
			if (useExplicitIdentity) {
				zephir_array_append(&values, defaultValue, PH_SEPARATE, "phalcon/mvc/model.zep", 2173);
				zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 2173);
			}
		}
	}
	ZEPHIR_CALL_METHOD(&success, connection, "insert", NULL, 0, table, values, fields, bindTypes);
	zephir_check_call_status();
	_6 = zephir_is_true(success);
	if (_6) {
		_6 = !ZEPHIR_IS_FALSE_IDENTICAL(identityField);
	}
	if (_6) {
		ZEPHIR_INIT_VAR(sequenceName);
		ZVAL_NULL(sequenceName);
		ZEPHIR_CALL_METHOD(&_7, connection, "supportsequences", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_TRUE_IDENTICAL(_7)) {
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
		ZEPHIR_CALL_METHOD(&_8, connection, "lastinsertid", NULL, 0, sequenceName);
		zephir_check_call_status();
		zephir_update_property_zval_zval(this_ptr, attributeField, _8 TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_uniqueParams"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	}
	RETURN_CCTOR(success);

}

/**
 * Sends a pre-build UPDATE SQL statement to the relational database system
 *
 * @param Phalcon\Mvc\Model\MetaDataInterface metaData
 * @param Phalcon\Db\AdapterInterface connection
 * @param string|array table
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowUpdate) {

	zval *_15;
	zval *_10 = NULL, *_11 = NULL;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	HashTable *_3, *_13;
	HashPosition _2, _12;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool useDynamicUpdate, changed;
	zval *metaData, *connection, *table, *bindSkip, *fields, *values, *bindTypes, *manager = NULL, *bindDataTypes = NULL, *field = NULL, *automaticAttributes = NULL, *snapshotValue = NULL, *uniqueKey, *uniqueParams = NULL, *uniqueTypes, *snapshot, *nonPrimary = NULL, *columnMap = NULL, *attributeField = NULL, *value = NULL, *primaryKeys = NULL, *bindType = NULL, *_0, *_1 = NULL, **_4, *_5 = NULL, *_6 = NULL, *_9 = NULL, **_14;

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
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_CALL_METHOD(&_1, manager, "isusingdynamicupdate", NULL, 0, this_ptr);
	zephir_check_call_status();
	useDynamicUpdate = zephir_get_boolval(_1);
	if (useDynamicUpdate) {
		ZEPHIR_OBS_VAR(snapshot);
		zephir_read_property_this(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
		if (Z_TYPE_P(snapshot) != IS_ARRAY) {
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
		ZEPHIR_INIT_NVAR(columnMap);
		ZVAL_NULL(columnMap);
	}
	zephir_is_iterable(nonPrimary, &_3, &_2, 0, 0, "phalcon/mvc/model.zep", 2368);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(field, _4);
		if (!(zephir_array_isset(automaticAttributes, field))) {
			ZEPHIR_OBS_NVAR(bindType);
			if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, field, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_5);
				object_init_ex(_5, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SVS(_6, "Column '", field, "' have not defined a bind data type");
				ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_7, 2, _6);
				zephir_check_call_status();
				zephir_throw_exception_debug(_5, "phalcon/mvc/model.zep", 2272 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_5);
					object_init_ex(_5, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_6);
					ZEPHIR_CONCAT_SVS(_6, "Column '", field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_7, 2, _6);
					zephir_check_call_status();
					zephir_throw_exception_debug(_5, "phalcon/mvc/model.zep", 2280 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, field);
			}
			ZEPHIR_OBS_NVAR(value);
			if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
				if (!(useDynamicUpdate)) {
					zephir_array_append(&fields, field, PH_SEPARATE, "phalcon/mvc/model.zep", 2296);
					zephir_array_append(&values, value, PH_SEPARATE, "phalcon/mvc/model.zep", 2296);
					zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 2297);
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
								do {
									if (ZEPHIR_IS_LONG(bindType, 8)) {
										changed = zephir_get_boolval(snapshotValue) != zephir_get_boolval(value);
										break;
									}
									if (ZEPHIR_IS_LONG(bindType, 0)) {
										changed = zephir_get_intval(snapshotValue) != zephir_get_intval(value);
										break;
									}
									if (ZEPHIR_IS_LONG(bindType, 3) || ZEPHIR_IS_LONG(bindType, 7)) {
										ZEPHIR_CALL_FUNCTION(&_1, "floatval", &_8, 297, snapshotValue);
										zephir_check_call_status();
										ZEPHIR_CALL_FUNCTION(&_9, "floatval", &_8, 297, value);
										zephir_check_call_status();
										changed = !ZEPHIR_IS_IDENTICAL(_1, _9);
										break;
									}
									if (ZEPHIR_IS_LONG(bindType, 1) || ZEPHIR_IS_LONG(bindType, 2) || ZEPHIR_IS_LONG(bindType, 4) || ZEPHIR_IS_LONG(bindType, 5) || ZEPHIR_IS_LONG(bindType, 6) || ZEPHIR_IS_LONG(bindType, 2)) {
										zephir_get_strval(_10, snapshotValue);
										zephir_get_strval(_11, value);
										changed = !ZEPHIR_IS_IDENTICAL(_10, _11);
										break;
									}
									changed = !ZEPHIR_IS_EQUAL(value, snapshotValue);
								} while(0);

							}
						}
					}
					if (changed) {
						zephir_array_append(&fields, field, PH_SEPARATE, "phalcon/mvc/model.zep", 2354);
						zephir_array_append(&values, value, PH_SEPARATE, "phalcon/mvc/model.zep", 2354);
						zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 2355);
					}
				}
			} else {
				zephir_array_append(&fields, field, PH_SEPARATE, "phalcon/mvc/model.zep", 2360);
				zephir_array_append(&values, ZEPHIR_GLOBAL(global_null), PH_SEPARATE, "phalcon/mvc/model.zep", 2360);
				zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE, "phalcon/mvc/model.zep", 2360);
			}
		}
	}
	if (!(zephir_fast_count_int(fields TSRMLS_CC))) {
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
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation", "phalcon/mvc/model.zep", 2387);
			return;
		}
		ZEPHIR_INIT_NVAR(uniqueParams);
		array_init(uniqueParams);
		zephir_is_iterable(primaryKeys, &_13, &_12, 0, 0, "phalcon/mvc/model.zep", 2411);
		for (
		  ; zephir_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
		  ; zephir_hash_move_forward_ex(_13, &_12)
		) {
			ZEPHIR_GET_HVALUE(field, _14);
			if (Z_TYPE_P(columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field, 0 TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_5);
					object_init_ex(_5, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_6);
					ZEPHIR_CONCAT_SVS(_6, "Column '", field, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, _5, "__construct", &_7, 2, _6);
					zephir_check_call_status();
					zephir_throw_exception_debug(_5, "phalcon/mvc/model.zep", 2398 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, field);
			}
			ZEPHIR_OBS_NVAR(value);
			if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
				zephir_array_append(&uniqueParams, value, PH_SEPARATE, "phalcon/mvc/model.zep", 2405);
			} else {
				zephir_array_append(&uniqueParams, ZEPHIR_GLOBAL(global_null), PH_SEPARATE, "phalcon/mvc/model.zep", 2407);
			}
		}
	}
	ZEPHIR_INIT_VAR(_15);
	zephir_create_array(_15, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_15, SL("conditions"), &uniqueKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_15, SL("bind"), &uniqueParams, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_15, SL("bindTypes"), &uniqueTypes, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(connection, "update", NULL, 0, table, fields, values, _15, bindTypes);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Saves related records that must be stored prior to save the master record
 *
 * @param Phalcon\Db\AdapterInterface connection
 * @param Phalcon\Mvc\ModelInterface[] related
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _preSaveRelatedRecords) {

	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_6 = NULL, *_11 = NULL, *_12 = NULL;
	HashTable *_2, *_9;
	HashPosition _1, _8;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool nesting;
	zval *connection, *related, *className, *manager = NULL, *type = NULL, *relation = NULL, *columns = NULL, *referencedFields = NULL, *referencedModel = NULL, *message = NULL, *name = NULL, *record = NULL, *_0 = NULL, **_3, *_7 = NULL, **_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &related);



	nesting = 0;
	ZEPHIR_CALL_METHOD(NULL, connection, "begin", NULL, 0, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(manager, _0);
	zephir_is_iterable(related, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 2517);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(name, _2, _1);
		ZEPHIR_GET_HVALUE(record, _3);
		ZEPHIR_CALL_METHOD(&_0, manager, "getrelationbyalias", &_4, 0, className, name);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(relation, _0);
		if (Z_TYPE_P(relation) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&type, relation, "gettype", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(type, 0)) {
				if (Z_TYPE_P(record) != IS_OBJECT) {
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_5, 0, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
					zephir_check_call_status();
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects can be stored as part of belongs-to relations", "phalcon/mvc/model.zep", 2466);
					return;
				}
				ZEPHIR_CALL_METHOD(&columns, relation, "getfields", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedModel, relation, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
				zephir_check_call_status();
				if (Z_TYPE_P(columns) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_6, 0, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
					zephir_check_call_status();
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/mvc/model.zep", 2475);
					return;
				}
				ZEPHIR_CALL_METHOD(&_0, record, "save", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(_0))) {
					ZEPHIR_CALL_METHOD(&_7, record, "getmessages", NULL, 0);
					zephir_check_call_status();
					zephir_is_iterable(_7, &_9, &_8, 0, 0, "phalcon/mvc/model.zep", 2504);
					for (
					  ; zephir_hash_get_current_data_ex(_9, (void**) &_10, &_8) == SUCCESS
					  ; zephir_hash_move_forward_ex(_9, &_8)
					) {
						ZEPHIR_GET_HVALUE(message, _10);
						if (Z_TYPE_P(message) == IS_OBJECT) {
							ZEPHIR_CALL_METHOD(NULL, message, "setmodel", NULL, 0, record);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_11, 0, message);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_12, 0, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
					zephir_check_call_status();
					RETURN_MM_BOOL(0);
				}
				ZEPHIR_CALL_METHOD(&_7, record, "readattribute", NULL, 0, referencedFields);
				zephir_check_call_status();
				zephir_update_property_zval_zval(this_ptr, columns, _7 TSRMLS_CC);
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

	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_11 = NULL, *_20 = NULL, *_21 = NULL, *_22 = NULL, *_27 = NULL, *_28 = NULL;
	HashTable *_2, *_14, *_18, *_25;
	HashPosition _1, _13, _17, _24;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool nesting, isThrough, _5;
	zval *connection, *related, *className, *manager = NULL, *relation = NULL, *name = NULL, *record = NULL, *message = NULL, *columns = NULL, *referencedModel = NULL, *referencedFields = NULL, *relatedRecords = NULL, *value = NULL, *recordAfter = NULL, *intermediateModel = NULL, *intermediateFields = NULL, *intermediateValue = NULL, *intermediateModelName = NULL, *intermediateReferencedFields = NULL, *_0 = NULL, **_3, *_9 = NULL, *_10 = NULL, *_12 = NULL, **_15, *_16 = NULL, **_19, *_23 = NULL, **_26;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &related);



	nesting = 0;
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(manager, _0);
	zephir_is_iterable(related, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 2706);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(name, _2, _1);
		ZEPHIR_GET_HVALUE(record, _3);
		ZEPHIR_CALL_METHOD(&_0, manager, "getrelationbyalias", &_4, 0, className, name);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(relation, _0);
		if (Z_TYPE_P(relation) == IS_OBJECT) {
			ZEPHIR_CALL_METHOD(&_0, relation, "gettype", NULL, 0);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(_0, 0)) {
				continue;
			}
			_5 = Z_TYPE_P(record) != IS_OBJECT;
			if (_5) {
				_5 = Z_TYPE_P(record) != IS_ARRAY;
			}
			if (_5) {
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_6, 0, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_check_call_status();
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Only objects/arrays can be stored as part of has-many/has-one/has-many-to-many relations", "phalcon/mvc/model.zep", 2556);
				return;
			}
			ZEPHIR_CALL_METHOD(&columns, relation, "getfields", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedModel, relation, "getreferencedmodel", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&referencedFields, relation, "getreferencedfields", NULL, 0);
			zephir_check_call_status();
			if (Z_TYPE_P(columns) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_7, 0, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_check_call_status();
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Not implemented", "phalcon/mvc/model.zep", 2565);
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
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_8, 0, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_9);
				object_init_ex(_9, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_10);
				ZEPHIR_CONCAT_SVS(_10, "The column '", columns, "' needs to be present in the model");
				ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_11, 2, _10);
				zephir_check_call_status();
				zephir_throw_exception_debug(_9, "phalcon/mvc/model.zep", 2579 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_12, relation, "isthrough", NULL, 0);
			zephir_check_call_status();
			isThrough = zephir_get_boolval(_12);
			if (isThrough) {
				ZEPHIR_CALL_METHOD(&intermediateModelName, relation, "getintermediatemodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&intermediateFields, relation, "getintermediatefields", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&intermediateReferencedFields, relation, "getintermediatereferencedfields", NULL, 0);
				zephir_check_call_status();
			}
			zephir_is_iterable(relatedRecords, &_14, &_13, 0, 0, "phalcon/mvc/model.zep", 2695);
			for (
			  ; zephir_hash_get_current_data_ex(_14, (void**) &_15, &_13) == SUCCESS
			  ; zephir_hash_move_forward_ex(_14, &_13)
			) {
				ZEPHIR_GET_HVALUE(recordAfter, _15);
				if (!(isThrough)) {
					ZEPHIR_CALL_METHOD(NULL, recordAfter, "writeattribute", NULL, 0, referencedFields, value);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_12, recordAfter, "save", NULL, 0);
				zephir_check_call_status();
				if (!(zephir_is_true(_12))) {
					ZEPHIR_CALL_METHOD(&_16, recordAfter, "getmessages", NULL, 0);
					zephir_check_call_status();
					zephir_is_iterable(_16, &_18, &_17, 0, 0, "phalcon/mvc/model.zep", 2637);
					for (
					  ; zephir_hash_get_current_data_ex(_18, (void**) &_19, &_17) == SUCCESS
					  ; zephir_hash_move_forward_ex(_18, &_17)
					) {
						ZEPHIR_GET_HVALUE(message, _19);
						if (Z_TYPE_P(message) == IS_OBJECT) {
							ZEPHIR_CALL_METHOD(NULL, message, "setmodel", NULL, 0, record);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_20, 0, message);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_21, 0, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
					zephir_check_call_status();
					RETURN_MM_BOOL(0);
				}
				if (isThrough) {
					ZEPHIR_INIT_NVAR(_9);
					ZVAL_BOOL(_9, 1);
					ZEPHIR_CALL_METHOD(&intermediateModel, manager, "load", &_22, 0, intermediateModelName, _9);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, intermediateModel, "writeattribute", NULL, 0, intermediateFields, value);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&intermediateValue, recordAfter, "readattribute", NULL, 0, referencedFields);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, intermediateModel, "writeattribute", NULL, 0, intermediateReferencedFields, intermediateValue);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_16, intermediateModel, "save", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_is_true(_16))) {
						ZEPHIR_CALL_METHOD(&_23, intermediateModel, "getmessages", NULL, 0);
						zephir_check_call_status();
						zephir_is_iterable(_23, &_25, &_24, 0, 0, "phalcon/mvc/model.zep", 2689);
						for (
						  ; zephir_hash_get_current_data_ex(_25, (void**) &_26, &_24) == SUCCESS
						  ; zephir_hash_move_forward_ex(_25, &_24)
						) {
							ZEPHIR_GET_HVALUE(message, _26);
							if (Z_TYPE_P(message) == IS_OBJECT) {
								ZEPHIR_CALL_METHOD(NULL, message, "setmodel", NULL, 0, record);
								zephir_check_call_status();
							}
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "appendmessage", &_20, 0, message);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_27, 0, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
						zephir_check_call_status();
						RETURN_MM_BOOL(0);
					}
				}
			}
		} else {
			if (Z_TYPE_P(record) != IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, connection, "rollback", &_28, 0, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_9);
				object_init_ex(_9, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_10);
				ZEPHIR_CONCAT_SVSVS(_10, "There are no defined relations for the model '", className, "' using alias '", name, "'");
				ZEPHIR_CALL_METHOD(NULL, _9, "__construct", &_11, 2, _10);
				zephir_check_call_status();
				zephir_throw_exception_debug(_9, "phalcon/mvc/model.zep", 2698 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_CALL_METHOD(NULL, connection, "commit", NULL, 0, (nesting ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
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

	zephir_fcall_cache_entry *_5 = NULL;
	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *whiteList = NULL, *metaData = NULL, *related, *schema = NULL, *writeConnection = NULL, *readConnection = NULL, *source = NULL, *table = NULL, *identityField = NULL, *exists = NULL, *success = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL;

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
		ZEPHIR_INIT_VAR(_1);
		ZVAL_NULL(_1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, data, _1, whiteList);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(related);
	zephir_read_property_this(&related, this_ptr, SL("_related"), PH_NOISY_CC);
	if (Z_TYPE_P(related) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "_presaverelatedrecords", NULL, 0, writeConnection, related);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
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
		ZEPHIR_INIT_ZVAL_NREF(_3);
		ZVAL_LONG(_3, 2);
		zephir_update_property_this(this_ptr, SL("_operationMade"), _3 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_3);
		ZVAL_LONG(_3, 1);
		zephir_update_property_this(this_ptr, SL("_operationMade"), _3 TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_errorMessages"), _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&identityField, metaData, "getidentityfield", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "_presave", NULL, 0, metaData, exists, identityField);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
		if (Z_TYPE_P(related) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(_4);
			ZVAL_BOOL(_4, 0);
			ZEPHIR_CALL_METHOD(NULL, writeConnection, "rollback", NULL, 0, _4);
			zephir_check_call_status();
		}
		if (ZEPHIR_GLOBAL(orm).exception_on_failed_save) {
			ZEPHIR_INIT_NVAR(_4);
			object_init_ex(_4, phalcon_mvc_model_validationfailed_ce);
			_3 = zephir_fetch_nproperty_this(this_ptr, SL("_errorMessages"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 298, this_ptr, _3);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4, "phalcon/mvc/model.zep", 2810 TSRMLS_CC);
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
		ZEPHIR_INIT_ZVAL_NREF(_3);
		ZVAL_LONG(_3, 0);
		zephir_update_property_this(this_ptr, SL("_dirtyState"), _3 TSRMLS_CC);
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "_postsave", NULL, 0, success, exists);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(success, _2);
	}
	if (Z_TYPE_P(related) == IS_ARRAY) {
		if (ZEPHIR_IS_FALSE_IDENTICAL(success)) {
			ZEPHIR_INIT_NVAR(_1);
			ZVAL_BOOL(_1, 0);
			ZEPHIR_CALL_METHOD(NULL, writeConnection, "rollback", NULL, 0, _1);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(&success, this_ptr, "_postsaverelatedrecords", NULL, 0, writeConnection, related);
			zephir_check_call_status();
		}
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(success)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "notSave", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_5, 0, _1);
		zephir_check_temp_parameter(_1);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_canceloperation", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "afterSave", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", &_5, 0, _1);
		zephir_check_temp_parameter(_1);
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
 *      'type' => 'mechanical',
 *      'name' => 'Astroy Boy',
 *      'year' => 1952
 *  ));
 *</code>
 *
 * @param array data
 * @param array whiteList
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, create) {

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *whiteList = NULL, *metaData = NULL, *_0 = NULL, *_1 = NULL, *_3, *_4, *_5, *_6;

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
		ZEPHIR_INIT_VAR(_2);
		zephir_create_array(_2, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, phalcon_mvc_model_message_ce);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "Record cannot be created because it already exists", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_5);
		ZVAL_NULL(_5);
		ZEPHIR_INIT_VAR(_6);
		ZVAL_STRING(_6, "InvalidCreateAttempt", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 296, _4, _5, _6);
		zephir_check_temp_parameter(_4);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		zephir_array_fast_append(_2, _3);
		zephir_update_property_this(this_ptr, SL("_errorMessages"), _2 TSRMLS_CC);
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
 *
 * @param array data
 * @param array whiteList
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, update) {

	zval *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, *whiteList = NULL, *metaData = NULL, *_0, *_1 = NULL, *_2 = NULL, *_4, *_5, *_6, *_7;

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
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getreadconnection", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "_exists", NULL, 0, metaData, _2);
		zephir_check_call_status();
		if (zephir_is_true(_1)) {
			ZEPHIR_INIT_VAR(_3);
			zephir_create_array(_3, 1, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_4);
			object_init_ex(_4, phalcon_mvc_model_message_ce);
			ZEPHIR_INIT_VAR(_5);
			ZVAL_STRING(_5, "Record cannot be updated because it does not exist", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_VAR(_6);
			ZVAL_NULL(_6);
			ZEPHIR_INIT_VAR(_7);
			ZVAL_STRING(_7, "InvalidUpdateAttempt", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 296, _5, _6, _7);
			zephir_check_temp_parameter(_5);
			zephir_check_temp_parameter(_7);
			zephir_check_call_status();
			zephir_array_fast_append(_3, _4);
			zephir_update_property_this(this_ptr, SL("_errorMessages"), _3 TSRMLS_CC);
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

	zephir_fcall_cache_entry *_8 = NULL, *_9 = NULL;
	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *metaData = NULL, *writeConnection = NULL, *values, *bindTypes, *primaryKeys = NULL, *bindDataTypes = NULL, *columnMap = NULL, *attributeField = NULL, *conditions, *primaryKey = NULL, *bindType = NULL, *value = NULL, *schema = NULL, *source = NULL, *table = NULL, *success = NULL, *_0, *_1, *_2 = NULL, **_5, *_6 = NULL, *_7 = NULL, *_10;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 3);
	zephir_update_property_this(this_ptr, SL("_operationMade"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_errorMessages"), _1 TSRMLS_CC);
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "_checkforeignkeysreverserestrict", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A primary key must be defined in the model in order to perform the operation", "phalcon/mvc/model.zep", 3003);
		return;
	}
	zephir_is_iterable(primaryKeys, &_4, &_3, 0, 0, "phalcon/mvc/model.zep", 3044);
	for (
	  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
	  ; zephir_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(primaryKey, _5);
		ZEPHIR_OBS_NVAR(bindType);
		if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, primaryKey, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_6);
			object_init_ex(_6, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_7);
			ZEPHIR_CONCAT_SVS(_7, "Column '", primaryKey, "' have not defined a bind data type");
			ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_8, 2, _7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6, "phalcon/mvc/model.zep", 3015 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, columnMap, primaryKey, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_6);
				object_init_ex(_6, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_SVS(_7, "Column '", primaryKey, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_8, 2, _7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_6, "phalcon/mvc/model.zep", 3023 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(attributeField, primaryKey);
		}
		ZEPHIR_OBS_NVAR(value);
		if (!(zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC))) {
			ZEPHIR_INIT_NVAR(_6);
			object_init_ex(_6, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_7);
			ZEPHIR_CONCAT_SVS(_7, "Cannot delete the record because the primary key attribute: '", attributeField, "' wasn't set");
			ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_8, 2, _7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6, "phalcon/mvc/model.zep", 3033 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_append(&values, value, PH_SEPARATE, "phalcon/mvc/model.zep", 3039);
		ZEPHIR_CALL_METHOD(&_2, writeConnection, "escapeidentifier", &_9, 0, primaryKey);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_7);
		ZEPHIR_CONCAT_VS(_7, _2, " = ?");
		zephir_array_append(&conditions, _7, PH_SEPARATE, "phalcon/mvc/model.zep", 3040);
		zephir_array_append(&bindTypes, bindType, PH_SEPARATE, "phalcon/mvc/model.zep", 3041);
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		zephir_update_property_this(this_ptr, SL("_skipped"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_6);
		ZVAL_STRING(_6, "beforeDelete", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "fireeventcancel", NULL, 0, _6);
		zephir_check_temp_parameter(_6);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
			RETURN_MM_BOOL(0);
		} else {
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("_skipped"), PH_NOISY_CC);
			if (ZEPHIR_IS_TRUE_IDENTICAL(_0)) {
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
	ZEPHIR_INIT_NVAR(_6);
	zephir_fast_join_str(_6, SL(" AND "), conditions TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&success, writeConnection, "delete", NULL, 0, table, _6, values, bindTypes);
	zephir_check_call_status();
	if (ZEPHIR_GLOBAL(orm).virtual_foreign_keys) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "_checkforeignkeysreversecascade", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(_2)) {
			RETURN_MM_BOOL(0);
		}
	}
	if (ZEPHIR_GLOBAL(orm).events) {
		if (zephir_is_true(success)) {
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "afterDelete", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "fireevent", NULL, 0, _6);
			zephir_check_temp_parameter(_6);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_ZVAL_NREF(_10);
	ZVAL_LONG(_10, 2);
	zephir_update_property_this(this_ptr, SL("_dirtyState"), _10 TSRMLS_CC);
	RETURN_CCTOR(success);

}

/**
 * Returns the type of the latest operation performed by the ORM
 * Returns one of the OP_* class constants
 */
PHP_METHOD(Phalcon_Mvc_Model, getOperationMade) {


	RETURN_MEMBER(this_ptr, "_operationMade");

}

/**
 * Refreshes the model attributes re-querying the record from the database
 */
PHP_METHOD(Phalcon_Mvc_Model, refresh) {

	zval *_5 = NULL;
	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *metaData = NULL, *readConnection = NULL, *schema = NULL, *source = NULL, *table = NULL, *uniqueKey = NULL, *tables = NULL, *uniqueParams, *dialect = NULL, *row = NULL, *fields, *attribute = NULL, *_0, *_1 = NULL, **_4, *_6, *_7;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dirtyState"), PH_NOISY_CC);
	if (!ZEPHIR_IS_LONG(_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/mvc/model.zep", 3119);
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
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "_exists", NULL, 0, metaData, readConnection, table);
		zephir_check_call_status();
		if (!(zephir_is_true(_1))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/mvc/model.zep", 3141);
			return;
		}
		ZEPHIR_OBS_NVAR(uniqueKey);
		zephir_read_property_this(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(uniqueParams);
	zephir_read_property_this(&uniqueParams, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	if (Z_TYPE_P(uniqueParams) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record cannot be refreshed because it does not exist or is deleted", "phalcon/mvc/model.zep", 3149);
		return;
	}
	ZEPHIR_INIT_VAR(fields);
	array_init(fields);
	ZEPHIR_CALL_METHOD(&_1, metaData, "getattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(_1, &_3, &_2, 0, 0, "phalcon/mvc/model.zep", 3163);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(attribute, _4);
		ZEPHIR_INIT_NVAR(_5);
		zephir_create_array(_5, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_5, attribute);
		zephir_array_append(&fields, _5, PH_SEPARATE, "phalcon/mvc/model.zep", 3157);
	}
	ZEPHIR_CALL_METHOD(&dialect, readConnection, "getdialect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_5);
	zephir_create_array(_5, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_5, SL("columns"), &fields, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_1, readConnection, "escapeidentifier", NULL, 0, table);
	zephir_check_call_status();
	zephir_array_update_string(&_5, SL("tables"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_5, SL("where"), &uniqueKey, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&tables, dialect, "select", NULL, 0, _5);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueTypes"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, 2);
	ZEPHIR_CALL_METHOD(&row, readConnection, "fetchone", NULL, 0, tables, _7, uniqueParams, _6);
	zephir_check_call_status();
	if (Z_TYPE_P(row) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_1, metaData, "getcolumnmap", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "assign", NULL, 0, row, _1);
		zephir_check_call_status();
	}
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


	zephir_update_property_this(this_ptr, SL("_skipped"), skip ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

/**
 * Reads an attribute value by its name
 *
 * <code>
 * echo $robot->readAttribute('name');
 * </code>
 */
PHP_METHOD(Phalcon_Mvc_Model, readAttribute) {

	zval *attribute_param = NULL, *_0;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attribute_param);

	if (unlikely(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(attribute_param) == IS_STRING)) {
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
 * 	$robot->writeAttribute('name', 'Rosey');
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, writeAttribute) {

	zval *attribute_param = NULL, *value;
	zval *attribute = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &attribute_param, &value);

	if (unlikely(Z_TYPE_P(attribute_param) != IS_STRING && Z_TYPE_P(attribute_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attribute' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(attribute_param) == IS_STRING)) {
		zephir_get_strval(attribute, attribute_param);
	} else {
		ZEPHIR_INIT_VAR(attribute);
		ZVAL_EMPTY_STRING(attribute);
	}


	zephir_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
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
 *       $this->skipAttributes(array('price'));
 *   }
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributes) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *attributes_param = NULL, *keysAttributes, *metaData = NULL, *attribute = NULL, **_2;
	zval *attributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	attributes = attributes_param;



	ZEPHIR_INIT_VAR(keysAttributes);
	array_init(keysAttributes);
	zephir_is_iterable(attributes, &_1, &_0, 0, 0, "phalcon/mvc/model.zep", 3244);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(attribute, _2);
		zephir_array_update_zval(&keysAttributes, attribute, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, metaData, "setautomaticcreateattributes", NULL, 0, this_ptr, keysAttributes);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, metaData, "setautomaticupdateattributes", NULL, 0, this_ptr, keysAttributes);
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
 *       $this->skipAttributesOnCreate(array('created_at'));
 *   }
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnCreate) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *attributes_param = NULL, *keysAttributes, *attribute = NULL, **_2, *_3 = NULL;
	zval *attributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	attributes = attributes_param;



	ZEPHIR_INIT_VAR(keysAttributes);
	array_init(keysAttributes);
	zephir_is_iterable(attributes, &_1, &_0, 0, 0, "phalcon/mvc/model.zep", 3275);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
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
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->skipAttributesOnUpdate(array('modified_in'));
 *   }
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnUpdate) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *attributes_param = NULL, *keysAttributes, *attribute = NULL, **_2, *_3 = NULL;
	zval *attributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	attributes = attributes_param;



	ZEPHIR_INIT_VAR(keysAttributes);
	array_init(keysAttributes);
	zephir_is_iterable(attributes, &_1, &_0, 0, 0, "phalcon/mvc/model.zep", 3304);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
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
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->allowEmptyStringValues(array('name'));
 *   }
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, allowEmptyStringValues) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *attributes_param = NULL, *keysAttributes, *attribute = NULL, **_2, *_3 = NULL;
	zval *attributes = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &attributes_param);

	attributes = attributes_param;



	ZEPHIR_INIT_VAR(keysAttributes);
	array_init(keysAttributes);
	zephir_is_iterable(attributes, &_1, &_0, 0, 0, "phalcon/mvc/model.zep", 3333);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(attribute, _2);
		zephir_array_update_zval(&keysAttributes, attribute, &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
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
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->hasOne('id', 'RobotsDescription', 'robots_id');
 *   }
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, hasOne) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *referenceModel = NULL;
	zval *fields, *referenceModel_param = NULL, *referencedFields, *options = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
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
 *       $this->belongsTo('robots_id', 'Robots', 'id');
 *   }
 *
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, belongsTo) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *referenceModel = NULL;
	zval *fields, *referenceModel_param = NULL, *referencedFields, *options = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
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
 *       $this->hasMany('id', 'RobotsParts', 'robots_id');
 *   }
 *}
 *</code>
 */
PHP_METHOD(Phalcon_Mvc_Model, hasMany) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *referenceModel = NULL;
	zval *fields, *referenceModel_param = NULL, *referencedFields, *options = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &fields, &referenceModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
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
 *       //Setup a many-to-many relation to Parts through RobotsParts
 *       $this->hasManyToMany(
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
	zval *intermediateModel = NULL, *referenceModel = NULL;
	zval *fields, *intermediateModel_param = NULL, *intermediateFields, *intermediateReferencedFields, *referenceModel_param = NULL, *referencedFields, *options = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 6, 1, &fields, &intermediateModel_param, &intermediateFields, &intermediateReferencedFields, &referenceModel_param, &referencedFields, &options);

	if (unlikely(Z_TYPE_P(intermediateModel_param) != IS_STRING && Z_TYPE_P(intermediateModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'intermediateModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(intermediateModel_param) == IS_STRING)) {
		zephir_get_strval(intermediateModel, intermediateModel_param);
	} else {
		ZEPHIR_INIT_VAR(intermediateModel);
		ZVAL_EMPTY_STRING(intermediateModel);
	}
	if (unlikely(Z_TYPE_P(referenceModel_param) != IS_STRING && Z_TYPE_P(referenceModel_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'referenceModel' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(referenceModel_param) == IS_STRING)) {
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
 *<?php
 *
 *use Phalcon\Mvc\Model\Behavior\Timestampable;
 *
 *class Robots extends \Phalcon\Mvc\Model
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
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
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
	zval *keepSnapshot_param = NULL, *_0;
	zend_bool keepSnapshot;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keepSnapshot_param);

	keepSnapshot = zephir_get_boolval(keepSnapshot_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "keepsnapshots", NULL, 0, this_ptr, (keepSnapshot ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
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

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_1;
	HashPosition _0;
	zval *data_param = NULL, *columnMap = NULL, *key = NULL, *value = NULL, *snapshot, *attribute = NULL, **_2, *_3 = NULL, *_4 = NULL;
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
		zephir_is_iterable(data, &_1, &_0, 0, 0, "phalcon/mvc/model.zep", 3533);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(key, _1, _0);
			ZEPHIR_GET_HVALUE(value, _2);
			if (Z_TYPE_P(key) != IS_STRING) {
				continue;
			}
			ZEPHIR_OBS_NVAR(attribute);
			if (!(zephir_array_isset_fetch(&attribute, columnMap, key, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_3);
				object_init_ex(_3, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SVS(_4, "Column '", key, "' doesn't make part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, 2, _4);
				zephir_check_call_status();
				zephir_throw_exception_debug(_3, "phalcon/mvc/model.zep", 3527 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_zval(&snapshot, attribute, &value, PH_COPY | PH_SEPARATE);
		}
		zephir_update_property_this(this_ptr, SL("_snapshot"), snapshot TSRMLS_CC);
		RETURN_MM_NULL();
	}
	zephir_update_property_this(this_ptr, SL("_snapshot"), data TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if the object has internal snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, hasSnapshotData) {

	zval *snapshot;


	snapshot = zephir_fetch_nproperty_this(this_ptr, SL("_snapshot"), PH_NOISY_CC);
	RETURN_BOOL(Z_TYPE_P(snapshot) == IS_ARRAY);

}

/**
 * Returns the internal snapshot data
 */
PHP_METHOD(Phalcon_Mvc_Model, getSnapshotData) {


	RETURN_MEMBER(this_ptr, "_snapshot");

}

/**
 * Check if a specific attribute has changed
 * This only works if the model is keeping data snapshots
 *
 * @param string|array fieldName
 */
PHP_METHOD(Phalcon_Mvc_Model, hasChanged) {

	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *fieldName = NULL, *snapshot, *metaData = NULL, *columnMap = NULL, *allAttributes = NULL, *value = NULL, *originalValue = NULL, *name = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, **_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &fieldName);

	if (!fieldName) {
		fieldName = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_OBS_VAR(snapshot);
	zephir_read_property_this(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
	if (Z_TYPE_P(snapshot) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record doesn't have a valid data snapshot", "phalcon/mvc/model.zep", 3572);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dirtyState"), PH_NOISY_CC);
	if (!ZEPHIR_IS_LONG(_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Change checking cannot be performed because the object has not been persisted or is deleted", "phalcon/mvc/model.zep", 3579);
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
	if (Z_TYPE_P(fieldName) == IS_STRING) {
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			if (!(zephir_array_isset(columnMap, fieldName))) {
				ZEPHIR_INIT_VAR(_1);
				object_init_ex(_1, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_VAR(_2);
				ZEPHIR_CONCAT_SVS(_2, "The field '", fieldName, "' is not part of the model");
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1, "phalcon/mvc/model.zep", 3611 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			if (!(zephir_array_isset(allAttributes, fieldName))) {
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_SVS(_2, "The field '", fieldName, "' is not part of the model");
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1, "phalcon/mvc/model.zep", 3615 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_OBS_VAR(value);
		if (!(zephir_fetch_property_zval(&value, this_ptr, fieldName, PH_SILENT_CC))) {
			ZEPHIR_INIT_NVAR(_1);
			object_init_ex(_1, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_SVS(_2, "The field '", fieldName, "' is not defined on the model");
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1, "phalcon/mvc/model.zep", 3623 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_VAR(originalValue);
		if (!(zephir_array_isset_fetch(&originalValue, snapshot, fieldName, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_1);
			object_init_ex(_1, phalcon_mvc_model_exception_ce);
			ZEPHIR_INIT_VAR(_3);
			ZEPHIR_CONCAT_SVS(_3, "The field '", fieldName, "' was not found in the snapshot");
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _3);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1, "phalcon/mvc/model.zep", 3630 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_MM_BOOL(!ZEPHIR_IS_EQUAL(value, originalValue));
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_is_iterable(allAttributes, &_5, &_4, 0, 0, "phalcon/mvc/model.zep", 3666);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(name, _5, _4);
		ZEPHIR_GET_HVALUE(_1, _6);
		ZEPHIR_OBS_NVAR(originalValue);
		if (!(zephir_array_isset_fetch(&originalValue, snapshot, name, 0 TSRMLS_CC))) {
			RETURN_MM_BOOL(1);
		}
		ZEPHIR_OBS_NVAR(value);
		if (!(zephir_fetch_property_zval(&value, this_ptr, name, PH_SILENT_CC))) {
			RETURN_MM_BOOL(1);
		}
		if (!ZEPHIR_IS_EQUAL(value, originalValue)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Returns a list of changed values
 */
PHP_METHOD(Phalcon_Mvc_Model, getChangedFields) {

	HashTable *_3;
	HashPosition _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *metaData = NULL, *changed, *name = NULL, *snapshot, *columnMap = NULL, *allAttributes = NULL, *value = NULL, *_0, *_1 = NULL, **_4, *_5;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(snapshot);
	zephir_read_property_this(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
	if (Z_TYPE_P(snapshot) != IS_ARRAY) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The record doesn't have a valid data snapshot", "phalcon/mvc/model.zep", 3679);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dirtyState"), PH_NOISY_CC);
	if (!ZEPHIR_IS_LONG(_0, 0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "Change checking cannot be performed because the object has not been persisted or is deleted", "phalcon/mvc/model.zep", 3686);
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
	ZEPHIR_INIT_VAR(_1);
	zephir_is_iterable(allAttributes, &_3, &_2, 0, 0, "phalcon/mvc/model.zep", 3740);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HMKEY(name, _3, _2);
		ZEPHIR_GET_HVALUE(_1, _4);
		if (!(zephir_array_isset(snapshot, name))) {
			zephir_array_append(&changed, name, PH_SEPARATE, "phalcon/mvc/model.zep", 3719);
			continue;
		}
		ZEPHIR_OBS_NVAR(value);
		if (!(zephir_fetch_property_zval(&value, this_ptr, name, PH_SILENT_CC))) {
			zephir_array_append(&changed, name, PH_SEPARATE, "phalcon/mvc/model.zep", 3727);
			continue;
		}
		zephir_array_fetch(&_5, snapshot, name, PH_NOISY | PH_READONLY, "phalcon/mvc/model.zep", 3734 TSRMLS_CC);
		if (!ZEPHIR_IS_EQUAL(value, _5)) {
			zephir_array_append(&changed, name, PH_SEPARATE, "phalcon/mvc/model.zep", 3735);
			continue;
		}
	}
	RETURN_CCTOR(changed);

}

/**
 * Sets if a model must use dynamic update instead of the all-field update
 *
 *<code>
 *<?php
 *
 *class Robots extends \Phalcon\Mvc\Model
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
	zval *dynamicUpdate_param = NULL, *_0;
	zend_bool dynamicUpdate;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dynamicUpdate_param);

	dynamicUpdate = zephir_get_boolval(dynamicUpdate_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _0, "usedynamicupdate", NULL, 0, this_ptr, (dynamicUpdate ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns related records based on defined relations
 *
 * @param string alias
 * @param array arguments
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getRelated) {

	zval *_4, *_5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, *arguments = NULL, *relation = NULL, *className, *manager = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3;
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
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVSVS(_3, "There is no defined relations for the model '", className, "' using alias '", alias, "'");
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 2, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2, "phalcon/mvc/model.zep", 3782 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_4, manager);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "getRelationRecords", 1);
	zephir_array_fast_append(_4, _2);
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(_5, relation);
	zephir_array_fast_append(_5, ZEPHIR_GLOBAL(global_null));
	zephir_array_fast_append(_5, this_ptr);
	zephir_array_fast_append(_5, arguments);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _4, _5);
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

	zval *_4, *_5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *modelName_param = NULL, *method_param = NULL, *arguments, *manager = NULL, *relation = NULL, *queryMethod = NULL, *extraArgs, *_0, *_1 = NULL, _2 = zval_used_for_init, *_3 = NULL;
	zval *modelName = NULL, *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &modelName_param, &method_param, &arguments);

	if (unlikely(Z_TYPE_P(modelName_param) != IS_STRING && Z_TYPE_P(modelName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modelName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modelName_param) == IS_STRING)) {
		zephir_get_strval(modelName, modelName_param);
	} else {
		ZEPHIR_INIT_VAR(modelName);
		ZVAL_EMPTY_STRING(modelName);
	}
	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
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
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_LONG(&_2, 3);
		ZEPHIR_INIT_VAR(_3);
		zephir_substr(_3, method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CALL_METHOD(&_1, manager, "getrelationbyalias", NULL, 0, modelName, _3);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(relation, _1);
	}
	if (Z_TYPE_P(relation) != IS_OBJECT) {
		if (zephir_start_with_str(method, SL("count"))) {
			ZEPHIR_INIT_NVAR(queryMethod);
			ZVAL_STRING(queryMethod, "count", 1);
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, 5);
			ZEPHIR_INIT_NVAR(_3);
			zephir_substr(_3, method, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CALL_METHOD(&_1, manager, "getrelationbyalias", NULL, 0, modelName, _3);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(relation, _1);
		}
	}
	if (Z_TYPE_P(relation) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(extraArgs);
		zephir_array_isset_long_fetch(&extraArgs, arguments, 0, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_4);
		zephir_create_array(_4, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_4, manager);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "getRelationRecords", 1);
		zephir_array_fast_append(_4, _3);
		ZEPHIR_INIT_VAR(_5);
		zephir_create_array(_5, 4, 0 TSRMLS_CC);
		zephir_array_fast_append(_5, relation);
		zephir_array_fast_append(_5, queryMethod);
		zephir_array_fast_append(_5, this_ptr);
		zephir_array_fast_append(_5, extraArgs);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _4, _5);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

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
	zval *method_param = NULL, *arguments = NULL, *modelName, *status = NULL, *records = NULL, *_0, *_1, *_2;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	zephir_get_strval(method, method_param);
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(modelName);
	zephir_get_class(modelName, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&records, this_ptr, "_getrelatedrecords", NULL, 0, modelName, method, arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(records) != IS_NULL) {
		RETURN_CCTOR(records);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&status, _0, "missingmethod", NULL, 0, this_ptr, method, arguments);
	zephir_check_call_status();
	if (Z_TYPE_P(status) != IS_NULL) {
		RETURN_CCTOR(status);
	}
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, phalcon_mvc_model_exception_ce);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_SVSVS(_2, "The method '", method, "' doesn't exist on model '", modelName, "'");
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "phalcon/mvc/model.zep", 3874 TSRMLS_CC);
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

	zval *_6, *_7;
	zend_class_entry *_5, *_8;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *arguments = NULL, *extraMethod = NULL, *type = NULL, *modelName, *value, *model, *attributes = NULL, *field = NULL, *extraMethodFirst = NULL, *metaData = NULL, _0 = zval_used_for_init, *_1 = NULL, *_2 = NULL, *_4 = NULL;
	zval *method = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &arguments);

	zephir_get_strval(method, method_param);
	if (!arguments) {
		arguments = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(extraMethod);
	ZVAL_NULL(extraMethod);
	if (zephir_start_with_str(method, SL("findFirstBy"))) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "findFirst", 1);
		ZEPHIR_SINIT_VAR(_0);
		ZVAL_LONG(&_0, 11);
		ZEPHIR_INIT_NVAR(extraMethod);
		zephir_substr(extraMethod, method, 11 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	}
	if (Z_TYPE_P(extraMethod) == IS_NULL) {
		if (zephir_start_with_str(method, SL("findBy"))) {
			ZEPHIR_INIT_NVAR(type);
			ZVAL_STRING(type, "find", 1);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 6);
			ZEPHIR_INIT_NVAR(extraMethod);
			zephir_substr(extraMethod, method, 6 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		}
	}
	if (Z_TYPE_P(extraMethod) == IS_NULL) {
		if (zephir_start_with_str(method, SL("countBy"))) {
			ZEPHIR_INIT_NVAR(type);
			ZVAL_STRING(type, "count", 1);
			ZEPHIR_SINIT_NVAR(_0);
			ZVAL_LONG(&_0, 7);
			ZEPHIR_INIT_NVAR(extraMethod);
			zephir_substr(extraMethod, method, 7 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		}
	}
	ZEPHIR_INIT_VAR(modelName);
	zephir_get_called_class(modelName TSRMLS_CC);
	if (!(zephir_is_true(extraMethod))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVSVS(_2, "The static method '", method, "' doesn't exist on model '", modelName, "'");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/mvc/model.zep", 3925 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(value);
	if (!(zephir_array_isset_long_fetch(&value, arguments, 0, 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, phalcon_mvc_model_exception_ce);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SVS(_3, "The static method '", method, "' requires one argument");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalcon/mvc/model.zep", 3929 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(model);
	zephir_fetch_safe_class(_4, modelName);
	_5 = zend_fetch_class(Z_STRVAL_P(_4), Z_STRLEN_P(_4), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(model, _5);
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
		ZEPHIR_CALL_FUNCTION(&extraMethodFirst, "lcfirst", NULL, 144, extraMethod);
		zephir_check_call_status();
		if (zephir_array_isset(attributes, extraMethodFirst)) {
			ZEPHIR_CPY_WRT(field, extraMethodFirst);
		} else {
			ZEPHIR_INIT_NVAR(field);
			zephir_uncamelize(field, extraMethod);
			if (!(zephir_array_isset(attributes, field))) {
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_2);
				ZEPHIR_CONCAT_SVS(_2, "Cannot resolve attribute '", extraMethod, "' in the model");
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 2, _2);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1, "phalcon/mvc/model.zep", 3963 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	}
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_2);
	ZEPHIR_CONCAT_VS(_2, field, " = ?0");
	zephir_array_update_string(&_6, SL("conditions"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_7);
	zephir_create_array(_7, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(_7, value);
	zephir_array_update_string(&_6, SL("bind"), &_7, PH_COPY | PH_SEPARATE);
	_8 = zephir_fetch_class(modelName TSRMLS_CC);
	ZEPHIR_RETURN_CALL_CE_STATIC_ZVAL(_8, type, NULL, 0, _6);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Magic method to assign values to the the model
 *
 * @param string property
 * @param mixed value
 */
PHP_METHOD(Phalcon_Mvc_Model, __set) {

	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *value, *lowerProperty = NULL, *related, *modelName, *manager = NULL, *lowerKey = NULL, *relation = NULL, *referencedModel = NULL, *key = NULL, *item = NULL, *_0, **_3, *_4 = NULL;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &property_param, &value);

	zephir_get_strval(property, property_param);


	if (Z_TYPE_P(value) == IS_OBJECT) {
		if (zephir_instance_of_ev(value, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(lowerProperty);
			zephir_fast_strtolower(lowerProperty, property);
			zephir_update_property_zval_zval(this_ptr, lowerProperty, value TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("_related"), lowerProperty, value TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_0);
			ZVAL_LONG(_0, 1);
			zephir_update_property_this(this_ptr, SL("_dirtyState"), _0 TSRMLS_CC);
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
		zephir_is_iterable(value, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 4027);
		for (
		  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		  ; zephir_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HMKEY(key, _2, _1);
			ZEPHIR_GET_HVALUE(item, _3);
			if (Z_TYPE_P(item) == IS_OBJECT) {
				if (zephir_instance_of_ev(item, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
					zephir_array_append(&related, item, PH_SEPARATE, "phalcon/mvc/model.zep", 4014);
				}
			} else {
				ZEPHIR_INIT_NVAR(lowerKey);
				zephir_fast_strtolower(lowerKey, key);
				zephir_update_property_zval_zval(this_ptr, lowerKey, item TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_4, manager, "getrelationbyalias", &_5, 0, modelName, lowerProperty);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(relation, _4);
				if (Z_TYPE_P(relation) == IS_OBJECT) {
					ZEPHIR_CALL_METHOD(&_4, relation, "getreferencedmodel", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&referencedModel, manager, "load", &_6, 0, _4);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, referencedModel, "writeattribute", NULL, 0, lowerKey, item);
					zephir_check_call_status();
				}
			}
		}
		if (zephir_fast_count_int(related TSRMLS_CC) > 0) {
			zephir_update_property_array(this_ptr, SL("_related"), lowerProperty, related TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_0);
			ZVAL_LONG(_0, 1);
			zephir_update_property_this(this_ptr, SL("_dirtyState"), _0 TSRMLS_CC);
		}
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	zephir_update_property_zval_zval(this_ptr, property, value TSRMLS_CC);
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * Magic method to get related records using the relation alias as a property
 *
 * @param string property
 * @return Phalcon\Mvc\Model\Resultset|Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, __get) {

	zephir_fcall_cache_entry *_4 = NULL;
	zval *_1, *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *modelName, *manager = NULL, *lowerProperty, *relation = NULL, *result, *method, *_0 = NULL, *_2, *_5;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (unlikely(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(property_param) == IS_STRING)) {
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
		ZEPHIR_INIT_VAR(_1);
		zephir_create_array(_1, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_1, manager);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "getRelationRecords", 1);
		zephir_array_fast_append(_1, _2);
		ZEPHIR_INIT_VAR(_3);
		zephir_create_array(_3, 4, 0 TSRMLS_CC);
		zephir_array_fast_append(_3, relation);
		zephir_array_fast_append(_3, ZEPHIR_GLOBAL(global_null));
		zephir_array_fast_append(_3, this_ptr);
		zephir_array_fast_append(_3, ZEPHIR_GLOBAL(global_null));
		ZEPHIR_INIT_VAR(result);
		ZEPHIR_CALL_USER_FUNC_ARRAY(result, _1, _3);
		zephir_check_call_status();
		if (Z_TYPE_P(result) == IS_OBJECT) {
			zephir_update_property_zval_zval(this_ptr, lowerProperty, result TSRMLS_CC);
			if (zephir_instance_of_ev(result, phalcon_mvc_modelinterface_ce TSRMLS_CC)) {
				zephir_update_property_array(this_ptr, SL("_related"), lowerProperty, result TSRMLS_CC);
			}
		}
		RETURN_CCTOR(result);
	}
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_text_ce, "camelize", &_4, 299, property);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(method);
	ZEPHIR_CONCAT_SV(method, "get", _0);
	if ((zephir_method_exists(this_ptr, method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SVSV(_5, "Access to undefined property ", modelName, "::", property);
	ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 148, _5);
	zephir_check_call_status();
	RETURN_MM_NULL();

}

/**
 * Magic method to check if a property is a valid relation
 */
PHP_METHOD(Phalcon_Mvc_Model, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, *modelName, *manager = NULL, *relation = NULL, *_0 = NULL;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (unlikely(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(property_param) == IS_STRING)) {
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("serialize", NULL, 11, _0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Unserializes the object from a serialized string
 */
PHP_METHOD(Phalcon_Mvc_Model, unserialize) {

	HashTable *_4;
	HashPosition _3;
	zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *attributes = NULL, *dependencyInjector = NULL, *manager = NULL, *key = NULL, *value = NULL, *_1 = NULL, *_2, **_5;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	if (unlikely(Z_TYPE_P(data_param) != IS_STRING && Z_TYPE_P(data_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'data' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(data_param) == IS_STRING)) {
		zephir_get_strval(data, data_param);
	} else {
		ZEPHIR_INIT_VAR(data);
		ZVAL_EMPTY_STRING(data);
	}


	ZEPHIR_CALL_FUNCTION(&attributes, "unserialize", NULL, 10, data);
	zephir_check_call_status();
	if (Z_TYPE_P(attributes) == IS_ARRAY) {
		ZEPHIR_CALL_CE_STATIC(&dependencyInjector, phalcon_di_ce, "getdefault", &_0, 147);
		zephir_check_call_status();
		if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/model.zep", 4151);
			return;
		}
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "modelsManager", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_1, dependencyInjector, "getshared", NULL, 0, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(manager, _1);
		if (Z_TYPE_P(manager) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid", "phalcon/mvc/model.zep", 4164);
			return;
		}
		zephir_update_property_this(this_ptr, SL("_modelsManager"), manager TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, manager, "initialize", NULL, 0, this_ptr);
		zephir_check_call_status();
		zephir_is_iterable(attributes, &_4, &_3, 0, 0, "phalcon/mvc/model.zep", 4183);
		for (
		  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HMKEY(key, _4, _3);
			ZEPHIR_GET_HVALUE(value, _5);
			zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
		}
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

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("get_object_vars", NULL, 60, this_ptr);
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

	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *columns = NULL, *data, *metaData = NULL, *columnMap = NULL, *attribute = NULL, *attributeField = NULL, *value = NULL, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL;

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
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalcon/mvc/model.zep", 4242);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(attribute, _3);
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, columnMap, attribute, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_4);
				object_init_ex(_4, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_SVS(_5, "Column '", attribute, "' doesn't make part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_6, 2, _5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_4, "phalcon/mvc/model.zep", 4223 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
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
 * Enables/disables options in the ORM
 */
PHP_METHOD(Phalcon_Mvc_Model, setup) {

	zval *options_param = NULL, *disableEvents, *columnRenaming, *notNullValidations, *exceptionOnFailedSave, *phqlLiterals, *virtualForeignKeys, *lateStateBinding;
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
	ZEPHIR_MM_RESTORE();

}

/**
 * Reset a model instance data
 */
PHP_METHOD(Phalcon_Mvc_Model, reset) {


	zephir_update_property_this(this_ptr, SL("_uniqueParams"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_snapshot"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);

}

