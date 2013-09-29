
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
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/concat.h"


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
 * Phalcon\Mvc\Model
 *
 * <p>Phalcon\Mvc\Model connects business objects and database tables to create
 * a persistable domain model where logic and data are presented in one wrapping.
 * It‘s an implementation of the object-relational mapping (ORM).</p>
 *
 * <p>A model represents the information (data) of the application and the rules to manipulate that data.
 * Models are primarily used for managing the rules of interaction with a corresponding database table.
 * In most cases, each table in your database will correspond to one model in your application.
 * The bulk of your application’s business logic will be concentrated in the models.</p>
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

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc, Model, phalcon, mvc_model, phalcon_mvc_model_method_entry, 0);

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

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Model constructor
 *
 * @param Phalcon\DiInterface dependencyInjector
 * @param Phalcon\Mvc\Model\ManagerInterface modelsManager
 */
PHP_METHOD(Phalcon_Mvc_Model, __construct) {

	zval *dependencyInjector = NULL, *modelsManager = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &dependencyInjector, &modelsManager);

	if (!dependencyInjector) {
		ZEPHIR_CPY_WRT(dependencyInjector, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(dependencyInjector);
	if (!modelsManager) {
		ZEPHIR_CPY_WRT(modelsManager, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(modelsManager);


	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
	}
	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	if ((Z_TYPE_P(modelsManager) != IS_OBJECT)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "modelsManager", 1);
		zephir_call_method_p1(_0, dependencyInjector, "getshared", _1);
		ZEPHIR_CPY_WRT(modelsManager, _0);
		if ((Z_TYPE_P(modelsManager) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid");
			return;
		}
	}
	zephir_update_property_this(this_ptr, SL("_modelsManager"), modelsManager TSRMLS_CC);
	zephir_call_method_p1_noret(modelsManager, "initialize", this_ptr);
	if ((zephir_method_exists_str(this_ptr, SS("onconstruct") TSRMLS_CC) == SUCCESS)) {
		zephir_call_method_noret(this_ptr, "onconstruct");
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the dependency injection container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets a custom events manager
 *
 * @param Phalcon\Events\ManagerInterface eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Model, setEventsManager) {

	zval *eventsManager, *modelsManager;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventsManager);



	ZEPHIR_OBS_VAR(modelsManager);
	zephir_read_property_this(&modelsManager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	zephir_call_method_p2_noret(modelsManager, "setcustomeventsmanager", this_ptr, eventsManager);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the custom events manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getEventsManager) {

	zval *modelsManager;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(modelsManager);
	zephir_read_property_this(&modelsManager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	zephir_call_method_p1(return_value, modelsManager, "getcustomeventsmanager", this_ptr);
	RETURN_MM();

}

/**
 * Returns the models meta-data service related to the entity instance
 *
 * @return Phalcon\Mvc\Model\MetaDataInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsMetaData) {

	zval *metaData = NULL, *dependencyInjector = NULL, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(metaData);
	zephir_read_property_this(&metaData, this_ptr, SL("_modelsMetaData"), PH_NOISY_CC);
	if ((Z_TYPE_P(metaData) != IS_OBJECT)) {
		ZEPHIR_OBS_VAR(_0);
		zephir_read_property_this(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ZEPHIR_CPY_WRT(dependencyInjector, _0);
		if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
			return;
		}
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "modelsMetadata", 1);
		zephir_call_method_p1(_1, dependencyInjector, "getshared", _2);
		ZEPHIR_CPY_WRT(metaData, _1);
		if ((Z_TYPE_P(metaData) != IS_OBJECT)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsMetadata' is not valid");
			return;
		}
		zephir_update_property_this(this_ptr, SL("_modelsMetaData"), metaData TSRMLS_CC);
	}
	RETURN_CCTOR(metaData);

}

/**
 * Returns the models manager related to the entity instance
 *
 * @return Phalcon\Mvc\Model\ManagerInterface
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
 *
 * @param Phalcon\Mvc\Model\TransactionInterface $transaction
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setTransaction) {

	zval *transaction;

	zephir_fetch_params(0, 1, 0, &transaction);



	if ((Z_TYPE_P(transaction) == IS_OBJECT)) {
		zephir_update_property_this(this_ptr, SL("_transaction"), transaction TSRMLS_CC);
		RETURN_THISW();
	}
	ZEPHIR_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "Transaction should be an object");
	return;

}

/**
 * Sets table name which model should be mapped
 *
 * @param string source
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setSource) {

	zval *source_param = NULL, *modelsManager;
	zval *source = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &source_param);

		zephir_get_strval(source, source_param);


	ZEPHIR_OBS_VAR(modelsManager);
	zephir_read_property_this(&modelsManager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	zephir_call_method_p2_noret(modelsManager, "setmodelsource", this_ptr, source);
	RETURN_THIS();

}

/**
 * Returns table name mapped in the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getSource) {

	zval *modelsManager = NULL, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(modelsManager, _0);
	zephir_call_method_p1(return_value, modelsManager, "getmodelsource", this_ptr);
	RETURN_MM();

}

/**
 * Sets schema name where table mapped is located
 *
 * @param string schema
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setSchema) {

	zval *schema_param = NULL, *modelsManager = NULL, *_0;
	zval *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &schema_param);

		zephir_get_strval(schema, schema_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(modelsManager, _0);
	zephir_call_method_p2_noret(modelsManager, "setmodelschema", this_ptr, schema);
	RETURN_THIS();

}

/**
 * Returns schema name where table mapped is located
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getSchema) {

	zval *modelsManager = NULL, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(modelsManager, _0);
	zephir_call_method_p1(return_value, modelsManager, "getmodelschema", this_ptr);
	RETURN_MM();

}

/**
 * Sets the DependencyInjection connection service name
 *
 * @param string connectionService
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setConnectionService) {

	zval *connectionService_param = NULL, *modelsManager = NULL, *_0;
	zval *connectionService = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

		zephir_get_strval(connectionService, connectionService_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(modelsManager, _0);
	zephir_call_method_p2_noret(modelsManager, "setconnectionservice", this_ptr, connectionService);
	RETURN_THIS();

}

/**
 * Sets the DependencyInjection connection service name used to read data
 *
 * @param string connectionService
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setReadConnectionService) {

	zval *connectionService_param = NULL, *modelsManager = NULL, *_0;
	zval *connectionService = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

		zephir_get_strval(connectionService, connectionService_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(modelsManager, _0);
	zephir_call_method_p2_noret(modelsManager, "setreadconnectionservice", this_ptr, connectionService);
	RETURN_THIS();

}

/**
 * Sets the DependencyInjection connection service name used to write data
 *
 * @param string connectionService
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setWriteConnectionService) {

	zval *connectionService_param = NULL, *modelsManager = NULL, *_0;
	zval *connectionService = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connectionService_param);

		zephir_get_strval(connectionService, connectionService_param);


	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(modelsManager, _0);
	zephir_call_method_p2_noret(modelsManager, "setwriteconnectionservice", this_ptr, connectionService);
	RETURN_THIS();

}

/**
 * Returns the DependencyInjection connection service name used to read data related the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnectionService) {

	zval *modelsManager = NULL, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(modelsManager, _0);
	zephir_call_method_p1(return_value, modelsManager, "getreadconnectionservice", this_ptr);
	RETURN_MM();

}

/**
 * Returns the DependencyInjection connection service name used to write data related to the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnectionService) {

	zval *modelsManager = NULL, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(modelsManager, _0);
	zephir_call_method_p1(return_value, modelsManager, "getwriteconnectionservice", this_ptr);
	RETURN_MM();

}

/**
 * Sets the dirty state of the object using one of the DIRTY_STATE_* constants
 *
 * @param int dirtyState
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setDirtyState) {

	zval *dirtyState_param = NULL, *_0;
	int dirtyState;

	zephir_fetch_params(0, 1, 0, &dirtyState_param);

		dirtyState = zephir_get_intval(dirtyState_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, dirtyState);
	zephir_update_property_zval(this_ptr, SL("_dirtyState"), _0 TSRMLS_CC);
	RETURN_THISW();

}

/**
 * Returns one of the DIRTY_STATE_* constants telling if the record exists in the database or not
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model, getDirtyState) {


	RETURN_MEMBER(this_ptr, "_dirtyState");

}

/**
 * Gets the connection used to read data for the model
 *
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getReadConnection) {

	zval *modelsManager = NULL, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(modelsManager, _0);
	zephir_call_method_p1(return_value, modelsManager, "getreadconnection", this_ptr);
	RETURN_MM();

}

/**
 * Gets the connection used to write data to the model
 *
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getWriteConnection) {

	zval *modelsManager = NULL, *transaction = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_transaction"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(transaction, _0);
	if ((Z_TYPE_P(transaction) == IS_OBJECT)) {
		zephir_call_method(return_value, transaction, "getconnection");
		RETURN_MM();
	}
	ZEPHIR_OBS_NVAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(modelsManager, _0);
	zephir_call_method_p1(return_value, modelsManager, "getwriteconnection", this_ptr);
	RETURN_MM();

}

/**
 * Assigns values to a model from an array
 *
 *<code>
 *$robot->assign(array(
 *  'type' => 'mechanical',
 *  'name' => 'Astro Boy',
 *  'year' => 1952
 *));
 *</code>
 *
 * @param Phalcon\Mvc\Model object
 * @param array data
 * @param array columnMap
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, assign) {

	zend_function *_6 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *data, *columnMap = NULL, *key = NULL, *value = NULL, *attribute = NULL, **_2, *_3 = NULL, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &columnMap);

	if (!columnMap) {
		ZEPHIR_CPY_WRT(columnMap, ZEPHIR_GLOBAL(global_null));
	}


	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data to dump in the object must be an Array");
		return;
	}
	zephir_is_iterable(data, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
			ZEPHIR_OBS_NVAR(attribute);
			if (zephir_array_isset_fetch(&attribute, columnMap, key TSRMLS_CC)) {
				zephir_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(_3);
				object_init_ex(_3, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_SV(_4, "Column '", key);
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_VS(_5, _4, "' doesn\'t make part of the column map");
				zephir_call_method_p1_cache_noret(_3, "__construct", &_6, _5);
				zephir_throw_exception(_3 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			zephir_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

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
 * @param Phalcon\Mvc\Model base
 * @param array data
 * @param array columnMap
 * @param int dirtyState
 * @param boolean keepSnapshots
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResultMap) {

	zend_function *_6 = NULL;
	HashTable *_2;
	HashPosition _1;
	zend_bool keepSnapshots;
	int dirtyState;
	zval *base, *data, *columnMap, *dirtyState_param = NULL, *keepSnapshots_param = NULL, *object, *attribute = NULL, *key = NULL, *value = NULL, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &base, &data, &columnMap, &dirtyState_param, &keepSnapshots_param);

	if (!dirtyState_param) {
		dirtyState = 0;	} else {
		dirtyState = zephir_get_intval(dirtyState_param);
	}
	if (!keepSnapshots_param) {
		keepSnapshots = 0;
	} else {
		keepSnapshots = zephir_get_boolval(keepSnapshots_param);
	}


	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data to dump in the object must be an Array");
		return;
	}
	ZEPHIR_INIT_VAR(object);
	ZVAL_NULL(object);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, dirtyState);
	zephir_call_method_p1_noret(object, "setdirtystate", _0);
	zephir_is_iterable(data, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if ((Z_TYPE_P(key) == IS_STRING)) {
			if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
				ZEPHIR_OBS_NVAR(attribute);
				if (zephir_array_isset_fetch(&attribute, columnMap, key TSRMLS_CC)) {
					zephir_update_property_zval_zval(object, attribute, value TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(_0);
					object_init_ex(_0, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SV(_4, "Column '", key);
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_VS(_5, _4, "' doesn't make part of the column map");
					zephir_call_method_p1_cache_noret(_0, "__construct", &_6, _5);
					zephir_throw_exception(_0 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				zephir_update_property_zval_zval(object, key, value TSRMLS_CC);
			}
		}
	}
	if (keepSnapshots) {
		zephir_call_method_p2_noret(object, "setsnapshotdata", data, columnMap);
	}
	if ((zephir_method_exists_str(object, SS("afterfetch") TSRMLS_CC) == SUCCESS)) {
		zephir_call_method_noret(object, "afterfetch");
	}
	RETURN_CCTOR(object);

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

	zend_function *_6 = NULL;
	HashTable *_1;
	HashPosition _0;
	int hydrationMode;
	zval *data, *columnMap, *hydrationMode_param = NULL, *hydrate, *key = NULL, *value = NULL, *attribute = NULL, **_2, *_3 = NULL, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &data, &columnMap, &hydrationMode_param);

		hydrationMode = zephir_get_intval(hydrationMode_param);


	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data to hidrate must be an Array");
		return;
	}
	if ((Z_TYPE_P(columnMap) != IS_ARRAY)) {
		if ((hydrationMode == 1)) {
			RETURN_CCTOR(data);
		}
	}
	ZEPHIR_INIT_VAR(hydrate);
	if ((hydrationMode == 1)) {
		array_init(hydrate);
	} else {
		object_init(hydrate);
	}
	zephir_is_iterable(data, &_1, &_0, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(value, _2);
		if ((Z_TYPE_P(key) == IS_STRING)) {
			if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
				ZEPHIR_OBS_NVAR(attribute);
				if (!(zephir_array_isset_fetch(&attribute, columnMap, key TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_3);
					object_init_ex(_3, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_4);
					ZEPHIR_CONCAT_SV(_4, "Column '", key);
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_VS(_5, _4, "' doesn't make part of the column map");
					zephir_call_method_p1_cache_noret(_3, "__construct", &_6, _5);
					zephir_throw_exception(_3 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				if ((hydrationMode == 1)) {
					zephir_array_update_zval(&hydrate, attribute, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_update_property_zval_zval(hydrate, attribute, value TSRMLS_CC);
				}
			} else {
				if ((hydrationMode == 1)) {
					zephir_array_update_zval(&hydrate, key, &value, PH_COPY | PH_SEPARATE);
				} else {
					zephir_update_property_zval_zval(hydrate, key, value TSRMLS_CC);
				}
			}
		}
	}
	RETURN_CCTOR(hydrate);

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
 * @param Phalcon\Mvc\Model $base
 * @param array data
 * @param int dirtyState
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, cloneResult) {

	HashTable *_2;
	HashPosition _1;
	int dirtyState;
	zval *base, *data, *dirtyState_param = NULL, *object, *key = NULL, *value = NULL, *_0, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &base, &data, &dirtyState_param);

	if (!dirtyState_param) {
		dirtyState = 0;	} else {
		dirtyState = zephir_get_intval(dirtyState_param);
	}


	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data to dump in the object must be an Array");
		return;
	}
	ZEPHIR_INIT_VAR(object);
	ZVAL_NULL(object);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, dirtyState);
	zephir_call_method_p1_noret(object, "setdirtystate", _0);
	zephir_is_iterable(data, &_2, &_1, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
		; zend_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(key, _2, _1);
		ZEPHIR_GET_HVALUE(value, _3);
		if ((Z_TYPE_P(key) != IS_STRING)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid key in array data provided to dumpResult()");
			return;
		}
		zephir_update_property_zval_zval(object, key, value TSRMLS_CC);
	}
	if ((zephir_method_exists_str(object, SS("afterfetch") TSRMLS_CC) == SUCCESS)) {
		zephir_call_method_noret(object, "afterfetch");
	}
	RETURN_CCTOR(object);

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

	zval *parameters = NULL, *params = NULL, *builder, *query, *bindParams = NULL, *bindTypes = NULL, *cache, *resultset, *hydration, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	}


	if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
		if ((Z_TYPE_P(parameters) != IS_NULL)) {
			zephir_array_append(&params, parameters, PH_SEPARATE);
		}
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_INIT_VAR(builder);
	object_init_ex(builder, phalcon_mvc_model_query_builder_ce);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func(_0, "get_called_class");
	zephir_call_method_p1_noret(builder, "from", _0);
	ZEPHIR_INIT_VAR(query);
	zephir_call_method(query, builder, "getquery");
	ZEPHIR_INIT_VAR(bindParams);
	ZVAL_NULL(bindParams);
	ZEPHIR_INIT_VAR(bindTypes);
	ZVAL_NULL(bindTypes);
	ZEPHIR_OBS_NVAR(bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, params, SS("bind") TSRMLS_CC)) {
		ZEPHIR_OBS_NVAR(bindTypes);
	}
	ZEPHIR_OBS_VAR(cache);
	if (zephir_array_isset_string_fetch(&cache, params, SS("cache") TSRMLS_CC)) {
		zephir_call_method_p1_noret(query, "cache", cache);
	}
	ZEPHIR_INIT_VAR(resultset);
	zephir_call_method_p2(resultset, query, "execute", bindParams, bindTypes);
	if ((Z_TYPE_P(resultset) == IS_OBJECT)) {
		ZEPHIR_OBS_VAR(hydration);
		if (zephir_array_isset_string_fetch(&hydration, params, SS("hydration") TSRMLS_CC)) {
			zephir_call_method_p1_noret(resultset, "sethydratemode", hydration);
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

	zval *parameters = NULL, *params = NULL, *builder, *query, *bindParams = NULL, *bindTypes = NULL, *cache, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	}


	if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
		if ((Z_TYPE_P(parameters) != IS_NULL)) {
			zephir_array_append(&params, parameters, PH_SEPARATE);
		}
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_INIT_VAR(builder);
	object_init_ex(builder, phalcon_mvc_model_query_builder_ce);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func(_0, "get_called_class");
	zephir_call_method_p1_noret(builder, "from", _0);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	zephir_call_method_p1_noret(builder, "limit", _1);
	ZEPHIR_INIT_VAR(query);
	zephir_call_method(query, builder, "getquery");
	ZEPHIR_INIT_VAR(bindParams);
	ZVAL_NULL(bindParams);
	ZEPHIR_INIT_VAR(bindTypes);
	ZVAL_NULL(bindTypes);
	ZEPHIR_OBS_NVAR(bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, params, SS("bind") TSRMLS_CC)) {
		ZEPHIR_OBS_NVAR(bindTypes);
	}
	ZEPHIR_OBS_VAR(cache);
	if (zephir_array_isset_string_fetch(&cache, params, SS("cache") TSRMLS_CC)) {
		zephir_call_method_p1_noret(query, "cache", cache);
	}
	zephir_call_method_p1_noret(query, "setuniquerow", ZEPHIR_GLOBAL(global_true));
	zephir_call_method_p2(return_value, query, "execute", bindParams, bindTypes);
	RETURN_MM();

}

/**
 * Create a criteria for a specific model
 *
 * @param Phalcon\DiInterface dependencyInjector
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model, query) {

	zval *dependencyInjector = NULL, *criteria, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		ZEPHIR_CPY_WRT(dependencyInjector, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(dependencyInjector);


	if ((Z_TYPE_P(dependencyInjector) != IS_OBJECT)) {
	}
	ZEPHIR_INIT_VAR(criteria);
	object_init_ex(criteria, phalcon_mvc_model_criteria_ce);
	zephir_call_method_p1_noret(criteria, "setdi", dependencyInjector);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_func(_0, "get_called_class");
	zephir_call_method_p1_noret(criteria, "setmodelname", _0);
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

	zend_function *_7 = NULL, *_8 = NULL, *_9 = NULL;
	HashTable *_3;
	HashPosition _2;
	int numberEmpty, numberPrimary;
	zval *metaData, *connection, *table = NULL, *uniqueParams = NULL, *uniqueTypes = NULL, *uniqueKey = NULL, *columnMap, *primaryKeys, *wherePk, *field = NULL, *attributeField = NULL, *value = NULL, *bindDataTypes, *joinWhere, *num, *type = NULL, *schema, *source, *_0 = NULL, *_1, **_4, *_5 = NULL, *_6 = NULL, *_10 = NULL, _11, *_12, *_13, *_14, *_15, *_16;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &metaData, &connection, &table);

	if (!table) {
		ZEPHIR_CPY_WRT(table, ZEPHIR_GLOBAL(global_null));
	}
	ZEPHIR_SEPARATE_PARAM(table);


	ZEPHIR_INIT_VAR(uniqueParams);
	ZVAL_NULL(uniqueParams);
	ZEPHIR_INIT_VAR(uniqueTypes);
	ZVAL_NULL(uniqueTypes);
	ZEPHIR_OBS_VAR(uniqueKey);
	zephir_read_property_this(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	if ((Z_TYPE_P(uniqueKey) == IS_NULL)) {
		ZEPHIR_INIT_VAR(primaryKeys);
		zephir_call_method_p1(primaryKeys, metaData, "getprimarykeyattributes", this_ptr);
		ZEPHIR_INIT_VAR(bindDataTypes);
		zephir_call_method_p1(bindDataTypes, metaData, "getbindtypes", this_ptr);
		numberPrimary = zephir_fast_count_int(primaryKeys TSRMLS_CC);
		if (!(numberPrimary)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_VAR(columnMap);
		ZEPHIR_INIT_VAR(_0);
		ZVAL_STRING(_0, "orm.column_renaming", 1);
		ZEPHIR_INIT_VAR(_1);
		zephir_call_func_p1(_1, "globals_get", _0);
		if (zephir_is_true(_1)) {
			zephir_call_method_p1(columnMap, metaData, "getcolumnmap", this_ptr);
		} else {
			ZVAL_NULL(columnMap);
		}
		numberEmpty = 0;
		ZEPHIR_INIT_VAR(wherePk);
		array_init(wherePk);
		ZEPHIR_INIT_BNVAR(uniqueParams);
		array_init(uniqueParams);
		ZEPHIR_INIT_BNVAR(uniqueTypes);
		array_init(uniqueTypes);
		zephir_is_iterable(primaryKeys, &_3, &_2, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
			; zend_hash_move_forward_ex(_3, &_2)
		) {
			ZEPHIR_GET_HVALUE(field, _4);
			if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_0);
					object_init_ex(_0, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_SV(_5, "Column '", field);
					ZEPHIR_INIT_LNVAR(_6);
					ZEPHIR_CONCAT_VS(_6, _5, "' isn't part of the column map");
					zephir_call_method_p1_cache_noret(_0, "__construct", &_7, _6);
					zephir_throw_exception(_0 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, field);
			}
			ZEPHIR_INIT_NVAR(value);
			ZVAL_NULL(value);
			if (1) {
				if (0) {
					numberEmpty++;
				}
				zephir_array_append(&uniqueParams, value, PH_SEPARATE);
			} else {
				zephir_array_append(&uniqueParams, ZEPHIR_GLOBAL(global_null), PH_SEPARATE);
				numberEmpty++;
			}
			ZEPHIR_OBS_NVAR(type);
			if (!(zephir_array_isset_fetch(&type, bindDataTypes, field TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_0);
				object_init_ex(_0, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_SV(_5, "Column '", field);
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_VS(_6, _5, "' isn't part of the table columns");
				zephir_call_method_p1_cache_noret(_0, "__construct", &_8, _6);
				zephir_throw_exception(_0 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&uniqueTypes, type, PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_0);
			zephir_call_method_p1_cache(_0, connection, "escapeidentifier", &_9, field);
			ZEPHIR_INIT_LNVAR(_10);
			ZEPHIR_CONCAT_VS(_10, _0, " = ?");
			zephir_array_append(&wherePk, _10, PH_SEPARATE);
		}
		if ((numberPrimary == numberEmpty)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_SINIT_VAR(_11);
		ZVAL_STRING(&_11, " AND ", 0);
		ZEPHIR_INIT_VAR(joinWhere);
		zephir_call_func_p2(joinWhere, "join", &_11, wherePk);
		zephir_update_property_this(this_ptr, SL("_uniqueKey"), joinWhere TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_uniqueParams"), uniqueParams TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_uniqueTypes"), uniqueTypes TSRMLS_CC);
		ZEPHIR_CPY_WRT(uniqueKey, joinWhere);
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("_dirtyState"), PH_NOISY_CC);
	if (!(zephir_is_true(_12))) {
		RETURN_MM_BOOL(1);
	}
	if ((Z_TYPE_P(uniqueKey) == IS_NULL)) {
		ZEPHIR_OBS_NVAR(uniqueKey);
		zephir_read_property_this(&uniqueKey, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	}
	if ((Z_TYPE_P(uniqueParams) == IS_NULL)) {
		ZEPHIR_OBS_NVAR(uniqueParams);
		zephir_read_property_this(&uniqueParams, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	}
	if ((Z_TYPE_P(uniqueTypes) == IS_NULL)) {
		ZEPHIR_OBS_NVAR(uniqueTypes);
		zephir_read_property_this(&uniqueTypes, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC);
	}
	ZEPHIR_INIT_VAR(schema);
	zephir_call_method(schema, this_ptr, "getschema");
	ZEPHIR_INIT_VAR(source);
	zephir_call_method(source, this_ptr, "getsource");
	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_NVAR(table);
		array_init(table);
		zephir_array_append(&table, schema, 0);
		zephir_array_append(&table, source, 0);
	} else {
		ZEPHIR_CPY_WRT(table, source);
	}
	ZEPHIR_INIT_NVAR(_0);
	zephir_call_method_p1(_0, connection, "escapeidentifier", table);
	ZEPHIR_INIT_LNVAR(_10);
	ZEPHIR_CONCAT_SV(_10, "SELECT COUNT(*) \"rowcount\" FROM ", _0);
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_CONCAT_VS(_13, _10, " WHERE ");
	ZEPHIR_INIT_VAR(_14);
	concat_function(_14, _13, uniqueKey TSRMLS_CC);
	ZEPHIR_INIT_VAR(num);
	zephir_call_method_p4(num, connection, "fetchone", _14, ZEPHIR_GLOBAL(global_null), uniqueParams, uniqueTypes);
	zephir_array_fetch_string(&_15, num, SL("rowcount"), PH_NOISY | PH_READONLY TSRMLS_CC);
	if (zephir_is_true(_15)) {
		ZEPHIR_INIT_ZVAL_NREF(_16);
		ZVAL_LONG(_16, 0);
		zephir_update_property_this(this_ptr, SL("_dirtyState"), _16 TSRMLS_CC);
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_INIT_ZVAL_NREF(_16);
		ZVAL_LONG(_16, 1);
		zephir_update_property_this(this_ptr, SL("_dirtyState"), _16 TSRMLS_CC);
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

	zval *functionName_param = NULL, *alias_param = NULL, *parameters, *params = NULL, *distinctColumn, *groupColumn, *columns = NULL, *bindParams = NULL, *bindTypes = NULL, *resultset, *cache, *firstRow, *groupColumns, *builder, *query, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5, *_6;
	zval *functionName = NULL, *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &functionName_param, &alias_param, &parameters);

		zephir_get_strval(functionName, functionName_param);
		zephir_get_strval(alias, alias_param);


	if ((Z_TYPE_P(parameters) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
		if ((Z_TYPE_P(parameters) != IS_NULL)) {
			zephir_array_append(&params, parameters, PH_SEPARATE);
		}
	} else {
		ZEPHIR_CPY_WRT(params, parameters);
	}
	ZEPHIR_OBS_VAR(groupColumn);
	if (!(zephir_array_isset_string_fetch(&groupColumn, params, SS("column") TSRMLS_CC))) {
		ZEPHIR_INIT_BNVAR(groupColumn);
		ZVAL_LONG(groupColumn, '*');
	}
	ZEPHIR_OBS_VAR(distinctColumn);
	if (zephir_array_isset_string_fetch(&distinctColumn, params, SS("distinct") TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_VS(_0, functionName, "(DISTINCT ");
		ZEPHIR_INIT_VAR(_1);
		concat_function(_1, _0, distinctColumn TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_VS(_2, _1, ") AS ");
		ZEPHIR_INIT_VAR(columns);
		concat_function(columns, _2, alias TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(columns);
		ZEPHIR_OBS_VAR(groupColumns);
		if (zephir_array_isset_string_fetch(&groupColumns, params, SS("group") TSRMLS_CC)) {
			ZEPHIR_INIT_LNVAR(_0);
			ZEPHIR_CONCAT_VS(_0, groupColumns, ", ");
			ZEPHIR_INIT_LNVAR(_1);
			concat_function(_1, _0, functionName TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_VS(_2, _1, "(");
			ZEPHIR_INIT_VAR(_3);
			concat_function(_3, _2, groupColumn TSRMLS_CC);
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_CONCAT_VS(_4, _3, ") AS ");
			concat_function(columns, _4, alias TSRMLS_CC);
		} else {
			ZEPHIR_INIT_LNVAR(_3);
			ZEPHIR_CONCAT_VS(_3, functionName, "(");
			ZEPHIR_INIT_LNVAR(_4);
			concat_function(_4, _3, groupColumn TSRMLS_CC);
			ZEPHIR_INIT_VAR(_5);
			ZEPHIR_CONCAT_VS(_5, _4, ") AS ");
			concat_function(columns, _5, alias TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_VAR(builder);
	object_init_ex(builder, phalcon_mvc_model_query_builder_ce);
	zephir_call_method_p1_noret(builder, "columns", columns);
	ZEPHIR_INIT_VAR(_6);
	zephir_call_func(_6, "get_called_class");
	zephir_call_method_p1_noret(builder, "from", _6);
	ZEPHIR_INIT_VAR(query);
	zephir_call_method(query, builder, "getquery");
	ZEPHIR_INIT_VAR(bindParams);
	ZVAL_NULL(bindParams);
	ZEPHIR_INIT_VAR(bindTypes);
	ZVAL_NULL(bindTypes);
	ZEPHIR_OBS_NVAR(bindParams);
	if (zephir_array_isset_string_fetch(&bindParams, params, SS("bind") TSRMLS_CC)) {
		ZEPHIR_OBS_NVAR(bindTypes);
	}
	ZEPHIR_INIT_VAR(resultset);
	zephir_call_method_p2(resultset, query, "execute", bindParams, bindTypes);
	ZEPHIR_OBS_VAR(cache);
	if (zephir_array_isset_string_fetch(&cache, params, SS("cache") TSRMLS_CC)) {
		zephir_call_method_p1_noret(query, "cache", cache);
	}
	if (zephir_array_isset_string(params, SS("group"))) {
		RETURN_CCTOR(resultset);
	}
	ZEPHIR_INIT_VAR(firstRow);
	zephir_call_method(firstRow, resultset, "getfirst");
	RETURN_MM_NULL();

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

	zval *parameters = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "COUNT", 1);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "rowcount", 1);
	zephir_call_self_p3(return_value, this_ptr, "_groupresult", _0, _1, parameters);
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

	zval *parameters = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "SUM", 1);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "sumatory", 1);
	zephir_call_self_p3(return_value, this_ptr, "_groupresult", _0, _1, parameters);
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
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, maximum) {

	zval *parameters = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "MAX", 1);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "maximum", 1);
	zephir_call_self_p3(return_value, this_ptr, "_groupresult", _0, _1, parameters);
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

	zval *parameters = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "MIN", 1);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "minimum", 1);
	zephir_call_self_p3(return_value, this_ptr, "_groupresult", _0, _1, parameters);
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
 * @param array $parameters
 * @return double
 */
PHP_METHOD(Phalcon_Mvc_Model, average) {

	zval *parameters = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters);

	if (!parameters) {
		ZEPHIR_CPY_WRT(parameters, ZEPHIR_GLOBAL(global_null));
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "AVG", 1);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "average", 1);
	zephir_call_self_p3(return_value, this_ptr, "_groupresult", _0, _1, parameters);
	RETURN_MM();

}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 *
 * @param string eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEvent) {

	zval *eventName_param = NULL, *modelsManager = NULL, *_0;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

		zephir_get_strval(eventName, eventName_param);


	if ((zephir_method_exists(this_ptr, eventName TSRMLS_CC)  == SUCCESS)) {
		zephir_call_method_zval_noret(this_ptr, eventName);
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(modelsManager, _0);
	zephir_call_method_p2(return_value, modelsManager, "notifyevent", eventName, this_ptr);
	RETURN_MM();

}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 * This method stops if one of the callbacks/listeners returns boolean false
 *
 * @param string eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEventCancel) {

	zval *eventName_param = NULL, *modelsManager = NULL, *_0 = NULL, *_1;
	zval *eventName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eventName_param);

		zephir_get_strval(eventName, eventName_param);


	if ((zephir_method_exists(this_ptr, eventName TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_call_method_zval(_0, this_ptr, eventName);
		if (ZEPHIR_IS_FALSE(_0)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(modelsManager, _1);
	ZEPHIR_INIT_NVAR(_0);
	zephir_call_method_p2(_0, modelsManager, "notifyevent", eventName, this_ptr);
	if (ZEPHIR_IS_FALSE(_0)) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Cancel the current operation
 *
 */
PHP_METHOD(Phalcon_Mvc_Model, _cancelOperation) {

	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_operationMade"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG(_0, 3)) {
		ZEPHIR_INIT_VAR(_1);
		ZVAL_STRING(_1, "notDeleted", 1);
		zephir_call_method_p1_noret(this_ptr, "fireevent", _1);
	} else {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_STRING(_1, "notSaved", 1);
		zephir_call_method_p1_noret(this_ptr, "fireevent", _1);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Appends a customized message on the validation process
 *
 * <code>
 * use \Phalcon\Mvc\Model\Message as Message;
 *
 * class Robots extends Phalcon\Mvc\Model
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
 *
 * @param Phalcon\Mvc\Model\MessageInterface $message
 * @return Phalcon\Mvc\Model
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
 *class Subscriptors extends Phalcon\Mvc\Model
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
 *
 * @param object validator
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, validate) {

	HashTable *_3;
	HashPosition _2;
	zval *validator, *message = NULL, *_0, *_1, **_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &validator);



	if ((Z_TYPE_P(validator) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Validator must be an Object");
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, validator, "validate", this_ptr);
	if (ZEPHIR_IS_FALSE(_0)) {
		ZEPHIR_INIT_VAR(_1);
		zephir_call_method(_1, validator, "getmessages");
		zephir_is_iterable(_1, &_3, &_2, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
			; zend_hash_move_forward_ex(_3, &_2)
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
 *class Subscriptors extends Phalcon\Mvc\Model
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
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, validationHasFailed) {

	zval *errorMessages;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(errorMessages);
	zephir_read_property_this(&errorMessages, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
	if ((Z_TYPE_P(errorMessages) == IS_ARRAY)) {
		if (zephir_fast_count_int(errorMessages TSRMLS_CC)) {
			RETURN_MM_BOOL(1);
		}
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
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model, getMessages) {


	RETURN_MEMBER(this_ptr, "_errorMessages");

}

/**
 * Reads "belongs to" relations and check the virtual foreign keys when inserting or updating records
 * to verify that inserted/updated values are present in the related entity
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysRestrict) {

	zend_function *_4 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_20 = NULL, *_23 = NULL;
	HashTable *_2, *_11;
	HashPosition _1, _10;
	zend_bool error;
	zval *manager = NULL, *belongsTo, *foreignKey = NULL, *relation = NULL, *conditions = NULL, *position = NULL, *bindParams = NULL, *extraConditions = NULL, *message = NULL, *fields = NULL, *referencedFields = NULL, *field = NULL, *action = NULL, *referencedModel = NULL, *value = NULL, *_0 = NULL, **_3, *_5 = NULL, **_12, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL, _18 = zval_used_for_init, *_19 = NULL, *_21 = NULL, *_22 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_INIT_VAR(belongsTo);
	zephir_call_method_p1(belongsTo, manager, "getbelongsto", this_ptr);
	if (zephir_fast_count_int(belongsTo TSRMLS_CC)) {
		error = 0;
		zephir_is_iterable(belongsTo, &_2, &_1, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			; zend_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(relation, _3);
			ZEPHIR_INIT_NVAR(foreignKey);
			zephir_call_method_cache(foreignKey, relation, "getforeignkey", &_4);
			if (!ZEPHIR_IS_FALSE(foreignKey)) {
				ZEPHIR_INIT_NVAR(action);
				ZVAL_LONG(action, 1);
				if ((Z_TYPE_P(foreignKey) == IS_ARRAY)) {
					ZEPHIR_OBS_NVAR(action);
				}
				if (ZEPHIR_IS_LONG(action, 1)) {
					ZEPHIR_INIT_NVAR(_5);
					zephir_call_method_cache(_5, relation, "getreferencedmodel", &_6);
					ZEPHIR_INIT_NVAR(referencedModel);
					zephir_call_method_p1_cache(referencedModel, manager, "load", &_7, _5);
					ZEPHIR_INIT_NVAR(conditions);
					array_init(conditions);
					ZEPHIR_INIT_NVAR(bindParams);
					array_init(bindParams);
					ZEPHIR_INIT_NVAR(fields);
					zephir_call_method_cache(fields, relation, "getfields", &_8);
					ZEPHIR_INIT_NVAR(referencedFields);
					zephir_call_method_cache(referencedFields, relation, "getreferencedfields", &_9);
					if ((Z_TYPE_P(fields) == IS_ARRAY)) {
						zephir_is_iterable(fields, &_11, &_10, 0, 0);
						for (
							; zend_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
							; zend_hash_move_forward_ex(_11, &_10)
						) {
							ZEPHIR_GET_HMKEY(position, _11, _10);
							ZEPHIR_GET_HVALUE(field, _12);
							ZEPHIR_OBS_NVAR(value);
							ZEPHIR_OBS_NVAR(_0);
							zephir_array_fetch(&_0, referencedFields, position, PH_NOISY TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_13);
							ZEPHIR_CONCAT_SV(_13, "[", _0);
							ZEPHIR_INIT_LNVAR(_14);
							ZEPHIR_CONCAT_VS(_14, _13, "] = ?");
							ZEPHIR_INIT_LNVAR(_15);
							concat_function(_15, _14, position TSRMLS_CC);
							zephir_array_append(&conditions, _15, PH_SEPARATE);
							zephir_array_append(&bindParams, value, PH_SEPARATE);
						}
					} else {
						ZEPHIR_OBS_NVAR(value);
						ZEPHIR_INIT_LNVAR(_13);
						ZEPHIR_CONCAT_SV(_13, "[", referencedFields);
						ZEPHIR_INIT_LNVAR(_14);
						ZEPHIR_CONCAT_VS(_14, _13, "] = ?0");
						zephir_array_append(&conditions, _14, PH_SEPARATE);
						zephir_array_append(&bindParams, value, PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(extraConditions);
					if (zephir_array_isset_string_fetch(&extraConditions, foreignKey, SS("conditions") TSRMLS_CC)) {
						zephir_array_append(&conditions, extraConditions, PH_SEPARATE);
					}
					ZEPHIR_INIT_NVAR(_16);
					ZEPHIR_INIT_NVAR(_17);
					array_init(_17);
					ZEPHIR_SINIT_NVAR(_18);
					ZVAL_STRING(&_18, " AND ", 0);
					ZEPHIR_INIT_NVAR(_19);
					zephir_call_func_p2(_19, "join", &_18, conditions);
					zephir_array_append(&_17, _19, 0);
					zephir_array_update_string(&_17, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
					zephir_call_method_p1_cache(_16, referencedModel, "count", &_20, _17);
					if (!(zephir_is_true(_16))) {
						ZEPHIR_OBS_NVAR(message);
						if (!(zephir_array_isset_string_fetch(&message, foreignKey, SS("message") TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(message);
							if ((Z_TYPE_P(fields) == IS_ARRAY)) {
								ZEPHIR_SINIT_NVAR(_18);
								ZVAL_STRING(&_18, ", ", 0);
								ZEPHIR_INIT_NVAR(_19);
								zephir_call_func_p2(_19, "join", &_18, fields);
								ZEPHIR_INIT_LNVAR(_15);
								ZEPHIR_CONCAT_SV(_15, "Value of fields '", _19);
								ZEPHIR_CONCAT_VS(message, _15, "' does not exist on referenced table");
							} else {
								ZEPHIR_INIT_LNVAR(_21);
								ZEPHIR_CONCAT_SV(_21, "Value of field '", fields);
								ZEPHIR_CONCAT_VS(message, _21, "' does not exist on referenced table");
							}
						}
						ZEPHIR_INIT_NVAR(_22);
						object_init_ex(_22, phalcon_mvc_model_message_ce);
						zephir_call_method_p1_cache_noret(this_ptr, "appendmessage", &_23, _22);
						error = 1;
						break;
					}
				}
			}
		}
		if ((error == 1)) {
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_STRING(_5, "orm.events", 1);
			ZEPHIR_INIT_NVAR(_16);
			zephir_call_func_p1(_16, "globals_get", _5);
			if (zephir_is_true(_16)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_STRING(_5, "onValidationFails", 1);
				zephir_call_method_p1_noret(this_ptr, "fireevent", _5);
				zephir_call_method_noret(this_ptr, "_canceloperation");
			}
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys (cascade) when deleting records
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverseCascade) {

	zend_function *_4 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_19 = NULL, *_20 = NULL;
	HashTable *_2, *_11;
	HashPosition _1, _10;
	zval *manager = NULL, *relations, *relation = NULL, *foreignKey = NULL, *resulset = NULL, *conditions = NULL, *bindParams = NULL, *referencedModel = NULL, *referencedFields = NULL, *action = NULL, *fields = NULL, *field = NULL, *position = NULL, *value = NULL, *extraConditions = NULL, *_0 = NULL, **_3, *_5 = NULL, **_12, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, _17 = zval_used_for_init, *_18 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(manager, _0);
	ZEPHIR_INIT_VAR(relations);
	zephir_call_method_p1(relations, manager, "gethasoneandhasmany", this_ptr);
	if (zephir_fast_count_int(relations TSRMLS_CC)) {
		zephir_is_iterable(relations, &_2, &_1, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			; zend_hash_move_forward_ex(_2, &_1)
		) {
			ZEPHIR_GET_HVALUE(relation, _3);
			ZEPHIR_INIT_NVAR(foreignKey);
			zephir_call_method_cache(foreignKey, relation, "getforeignkey", &_4);
			if (!ZEPHIR_IS_FALSE(foreignKey)) {
				ZEPHIR_INIT_NVAR(action);
				ZVAL_LONG(action, 0);
				if ((Z_TYPE_P(foreignKey) == IS_ARRAY)) {
					ZEPHIR_OBS_NVAR(action);
				}
				if (ZEPHIR_IS_LONG(action, 2)) {
					ZEPHIR_INIT_NVAR(_5);
					zephir_call_method_cache(_5, relation, "getreferencedmodel", &_6);
					ZEPHIR_INIT_NVAR(referencedModel);
					zephir_call_method_p1_cache(referencedModel, manager, "load", &_7, _5);
					ZEPHIR_INIT_NVAR(fields);
					zephir_call_method_cache(fields, relation, "getfields", &_8);
					ZEPHIR_INIT_NVAR(referencedFields);
					zephir_call_method_cache(referencedFields, relation, "getreferencedfields", &_9);
					ZEPHIR_INIT_NVAR(conditions);
					array_init(conditions);
					ZEPHIR_INIT_NVAR(bindParams);
					array_init(bindParams);
					if ((Z_TYPE_P(fields) == IS_ARRAY)) {
						zephir_is_iterable(fields, &_11, &_10, 0, 0);
						for (
							; zend_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
							; zend_hash_move_forward_ex(_11, &_10)
						) {
							ZEPHIR_GET_HMKEY(position, _11, _10);
							ZEPHIR_GET_HVALUE(field, _12);
							ZEPHIR_OBS_NVAR(value);
							ZEPHIR_OBS_NVAR(_0);
							zephir_array_fetch(&_0, referencedFields, position, PH_NOISY TSRMLS_CC);
							ZEPHIR_INIT_LNVAR(_13);
							ZEPHIR_CONCAT_SV(_13, "[", _0);
							ZEPHIR_INIT_LNVAR(_14);
							ZEPHIR_CONCAT_VS(_14, _13, "] = ?");
							ZEPHIR_INIT_LNVAR(_15);
							concat_function(_15, _14, position TSRMLS_CC);
							zephir_array_append(&conditions, _15, PH_SEPARATE);
							zephir_array_append(&bindParams, value, PH_SEPARATE);
						}
					} else {
						ZEPHIR_OBS_NVAR(value);
						ZEPHIR_INIT_LNVAR(_13);
						ZEPHIR_CONCAT_SV(_13, "[", referencedFields);
						ZEPHIR_INIT_LNVAR(_14);
						ZEPHIR_CONCAT_VS(_14, _13, "] = ?0");
						zephir_array_append(&conditions, _14, PH_SEPARATE);
						zephir_array_append(&bindParams, value, PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(extraConditions);
					if (zephir_array_isset_string_fetch(&extraConditions, foreignKey, SS("conditions") TSRMLS_CC)) {
						zephir_array_append(&conditions, extraConditions, PH_SEPARATE);
					}
					ZEPHIR_INIT_NVAR(_16);
					array_init(_16);
					ZEPHIR_SINIT_NVAR(_17);
					ZVAL_STRING(&_17, " AND ", 0);
					ZEPHIR_INIT_NVAR(_18);
					zephir_call_func_p2(_18, "join", &_17, conditions);
					zephir_array_append(&_16, _18, 0);
					zephir_array_update_string(&_16, SL("bind"), &bindParams, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(resulset);
					zephir_call_method_p1_cache(resulset, referencedModel, "find", &_19, _16);
					ZEPHIR_INIT_NVAR(_18);
					zephir_call_method_cache(_18, resulset, "delete", &_20);
					if (ZEPHIR_IS_FALSE(_18)) {
						RETURN_MM_BOOL(0);
					}
				}
			}
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Executes internal hooks before save a record
 *
 * @param Phalcon\Mvc\Model\MetadataInterface metaData
 * @param boolean exists
 * @param string identityField
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _preSave) {

	zend_function *_10 = NULL;
	HashTable *_6;
	HashPosition _5;
	zend_bool exists, error, isNull;
	zval *metaData, *exists_param = NULL, *identityField, *notNull, *columnMap, *dataTypeNumeric, *automaticAttributes, *field = NULL, *attributeField = NULL, *value = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4 = NULL, **_7, *_8 = NULL, *_9 = NULL, *_11 = NULL, *_12, *_13;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &metaData, &exists_param, &identityField);

		exists = zephir_get_boolval(exists_param);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "orm.events", 1);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "globals_get", _0);
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_BNVAR(_0);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "beforeValidation", 1);
		zephir_call_method_p1(_0, this_ptr, "fireeventcancel", _2);
		if (ZEPHIR_IS_FALSE(_0)) {
			RETURN_MM_BOOL(0);
		}
		if (exists) {
			ZEPHIR_INIT_NVAR(_2);
			ZEPHIR_INIT_VAR(_3);
			ZVAL_STRING(_3, "beforeValidationOnCreate", 1);
			zephir_call_method_p1(_2, this_ptr, "fireeventcancel", _3);
			if (ZEPHIR_IS_FALSE(_2)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_NVAR(_3);
			ZEPHIR_INIT_VAR(_4);
			ZVAL_STRING(_4, "beforeValidationOnUpdate", 1);
			zephir_call_method_p1(_3, this_ptr, "fireeventcancel", _4);
			if (ZEPHIR_IS_FALSE(_3)) {
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "orm.virtual_foreign_keys", 1);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_func_p1(_3, "globals_get", _2);
	if (zephir_is_true(_3)) {
		ZEPHIR_INIT_NVAR(_2);
		zephir_call_method(_2, this_ptr, "_checkforeignkeysrestrict");
		if (ZEPHIR_IS_FALSE(_2)) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "orm.not_null_validations", 1);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_func_p1(_3, "globals_get", _2);
	if (zephir_is_true(_3)) {
		ZEPHIR_INIT_VAR(notNull);
		zephir_call_method_p1(notNull, metaData, "getnotnullattributes", this_ptr);
		if ((Z_TYPE_P(notNull) == IS_ARRAY)) {
			ZEPHIR_INIT_VAR(dataTypeNumeric);
			zephir_call_method_p1(dataTypeNumeric, metaData, "getdatatypesnumeric", this_ptr);
			ZEPHIR_INIT_VAR(columnMap);
			ZEPHIR_INIT_NVAR(_2);
			ZVAL_STRING(_2, "orm.column_renaming", 1);
			ZEPHIR_INIT_NVAR(_4);
			zephir_call_func_p1(_4, "globals_get", _2);
			if (zephir_is_true(_4)) {
				zephir_call_method_p1(columnMap, metaData, "getcolumnmap", this_ptr);
			} else {
				ZVAL_NULL(columnMap);
			}
			ZEPHIR_INIT_VAR(automaticAttributes);
			if (exists) {
				zephir_call_method_p1(automaticAttributes, metaData, "getautomaticupdateattributes", this_ptr);
			} else {
				zephir_call_method_p1(automaticAttributes, metaData, "getautomaticcreateattributes", this_ptr);
			}
			error = 0;
			zephir_is_iterable(notNull, &_6, &_5, 0, 0);
			for (
				; zend_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
				; zend_hash_move_forward_ex(_6, &_5)
			) {
				ZEPHIR_GET_HVALUE(field, _7);
				if (!(zephir_array_isset(automaticAttributes, field))) {
					isNull = 0;
					if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
						ZEPHIR_OBS_NVAR(attributeField);
						if (!(zephir_array_isset_fetch(&attributeField, columnMap, field TSRMLS_CC))) {
							ZEPHIR_INIT_NVAR(_2);
							object_init_ex(_2, phalcon_mvc_model_exception_ce);
							ZEPHIR_INIT_LNVAR(_8);
							ZEPHIR_CONCAT_SV(_8, "Column '", field);
							ZEPHIR_INIT_LNVAR(_9);
							ZEPHIR_CONCAT_VS(_9, _8, "' isn't part of the column map");
							zephir_call_method_p1_cache_noret(_2, "__construct", &_10, _9);
							zephir_throw_exception(_2 TSRMLS_CC);
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_CPY_WRT(attributeField, field);
					}
					ZEPHIR_OBS_NVAR(value);
					if (0) {
						if ((Z_TYPE_P(value) != IS_OBJECT)) {
							if (!(zephir_array_isset(dataTypeNumeric, field))) {
								if (0) {
									isNull = 1;
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
					if ((isNull == 1)) {
						if (!(exists)) {
							if (ZEPHIR_IS_EQUAL(field, identityField)) {
								continue;
							}
						}
						ZEPHIR_INIT_NVAR(_2);
						object_init_ex(_2, phalcon_mvc_model_message_ce);
						zephir_update_property_array_append(this_ptr, SL("_errorMessages"), _2 TSRMLS_CC);
						error = 1;
					}
				}
			}
			if ((error == 1)) {
				ZEPHIR_INIT_VAR(_11);
				ZVAL_STRING(_11, "orm.events", 1);
				ZEPHIR_INIT_VAR(_12);
				zephir_call_func_p1(_12, "globals_get", _11);
				if (zephir_is_true(_12)) {
					ZEPHIR_INIT_NVAR(_11);
					ZVAL_STRING(_11, "onValidationFails", 1);
					zephir_call_method_p1_noret(this_ptr, "fireevent", _11);
					zephir_call_method_noret(this_ptr, "_canceloperation");
				}
				RETURN_MM_BOOL(0);
			}
		}
	}
	ZEPHIR_INIT_NVAR(_2);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "validation", 1);
	zephir_call_method_p1(_2, this_ptr, "fireeventcancel", _3);
	if (ZEPHIR_IS_FALSE(_2)) {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "orm.events", 1);
		ZEPHIR_INIT_NVAR(_4);
		zephir_call_func_p1(_4, "globals_get", _3);
		if (zephir_is_true(_4)) {
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_STRING(_3, "onValidationFails", 1);
			zephir_call_method_p1_noret(this_ptr, "fireevent", _3);
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "orm.events", 1);
	ZEPHIR_INIT_NVAR(_3);
	zephir_call_func_p1(_3, "globals_get", _2);
	if (zephir_is_true(_3)) {
		if (!(exists)) {
			ZEPHIR_INIT_NVAR(_2);
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "afterValidationOnCreate", 1);
			zephir_call_method_p1(_2, this_ptr, "fireeventcancel", _4);
			if (ZEPHIR_IS_FALSE(_2)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_NVAR(_3);
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "afterValidationOnUpdate", 1);
			zephir_call_method_p1(_3, this_ptr, "fireeventcancel", _4);
			if (ZEPHIR_IS_FALSE(_3)) {
				RETURN_MM_BOOL(0);
			}
		}
		ZEPHIR_INIT_NVAR(_3);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "afterValidation", 1);
		zephir_call_method_p1(_3, this_ptr, "fireeventcancel", _4);
		if (ZEPHIR_IS_FALSE(_3)) {
			RETURN_MM_BOOL(0);
		}
		ZEPHIR_INIT_NVAR(_3);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "beforeSave", 1);
		zephir_call_method_p1(_3, this_ptr, "fireeventcancel", _4);
		if (ZEPHIR_IS_FALSE(_3)) {
			RETURN_MM_BOOL(0);
		}
		zephir_update_property_this(this_ptr, SL("_skipped"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		if (exists) {
			ZEPHIR_INIT_NVAR(_3);
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "beforeUpdate", 1);
			zephir_call_method_p1(_3, this_ptr, "fireeventcancel", _4);
			if (ZEPHIR_IS_FALSE(_3)) {
				RETURN_MM_BOOL(0);
			}
		} else {
			ZEPHIR_INIT_NVAR(_3);
			ZEPHIR_INIT_NVAR(_4);
			ZVAL_STRING(_4, "beforeCreate", 1);
			zephir_call_method_p1(_3, this_ptr, "fireeventcancel", _4);
			if (ZEPHIR_IS_FALSE(_3)) {
				RETURN_MM_BOOL(0);
			}
		}
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("_skipped"), PH_NOISY_CC);
		if (ZEPHIR_IS_TRUE(_13)) {
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(1);

}

/**
 * Executes internal events after save a record
 *
 * @param boolean success
 * @param boolean exists
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _postSave) {

	zval *success_param = NULL, *exists_param = NULL, *_0 = NULL;
	zend_bool success, exists;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &success_param, &exists_param);

		success = zephir_get_boolval(success_param);
		exists = zephir_get_boolval(exists_param);


	if ((success == 1)) {
		if (exists) {
			ZEPHIR_INIT_VAR(_0);
			ZVAL_STRING(_0, "afterUpdate", 1);
			zephir_call_method_p1_noret(this_ptr, "fireevent", _0);
		} else {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_STRING(_0, "afterCreate", 1);
			zephir_call_method_p1_noret(this_ptr, "fireevent", _0);
		}
		ZEPHIR_INIT_NVAR(_0);
		ZVAL_STRING(_0, "afterSave", 1);
		zephir_call_method_p1_noret(this_ptr, "fireevent", _0);
		RETURN_MM_BOOL(success);
	}
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "notSave", 1);
	zephir_call_method_p1_noret(this_ptr, "fireevent", _0);
	zephir_call_method_noret(this_ptr, "_canceloperation");
	RETURN_MM_BOOL(0);

}

/**
 * Sends a pre-build INSERT SQL statement to the relational database system
 *
 * @param Phalcon\Mvc\Model\MetadataInterface $metaData
 * @param Phalcon\Db\AdapterInterface $connection
 * @param string $table
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowInsert) {

	zend_function *_7 = NULL, *_8 = NULL;
	HashTable *_3;
	HashPosition _2;
	zend_bool useExplicitIdentity;
	zval *metaData, *connection, *table, *identityField, *bindSkip, *fields, *values, *bindTypes, *attributes, *bindDataTypes, *automaticAttributes, *field = NULL, *columnMap, *value = NULL, *attributeField = NULL, *success, *bindType = NULL, *defaultValue, *sequenceName = NULL, *_0 = NULL, *_1, **_4, *_5 = NULL, *_6 = NULL, *_9 = NULL;

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
	ZEPHIR_INIT_VAR(attributes);
	zephir_call_method_p1(attributes, metaData, "getattributes", this_ptr);
	ZEPHIR_INIT_VAR(bindDataTypes);
	zephir_call_method_p1(bindDataTypes, metaData, "getbindtypes", this_ptr);
	ZEPHIR_INIT_VAR(automaticAttributes);
	zephir_call_method_p1(automaticAttributes, metaData, "getautomaticcreateattributes", this_ptr);
	ZEPHIR_INIT_VAR(columnMap);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "orm.column_renaming", 1);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_func_p1(_1, "globals_get", _0);
	if (zephir_is_true(_1)) {
		zephir_call_method_p1(columnMap, metaData, "getcolumnmap", this_ptr);
	} else {
		ZVAL_NULL(columnMap);
	}
	zephir_is_iterable(attributes, &_3, &_2, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		; zend_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(field, _4);
		if (!(zephir_array_isset(automaticAttributes, field))) {
			if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_0);
					object_init_ex(_0, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_SV(_5, "Column '", field);
					ZEPHIR_INIT_LNVAR(_6);
					ZEPHIR_CONCAT_VS(_6, _5, "' isn't part of the column map");
					zephir_call_method_p1_cache_noret(_0, "__construct", &_7, _6);
					zephir_throw_exception(_0 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, field);
			}
			if (!ZEPHIR_IS_EQUAL(field, identityField)) {
				zephir_array_append(&fields, field, PH_SEPARATE);
				ZEPHIR_OBS_NVAR(value);
				if (0) {
					ZEPHIR_OBS_NVAR(bindType);
					if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, field TSRMLS_CC))) {
						ZEPHIR_INIT_NVAR(_0);
						object_init_ex(_0, phalcon_mvc_model_exception_ce);
						ZEPHIR_INIT_LNVAR(_5);
						ZEPHIR_CONCAT_SV(_5, "Column '", field);
						ZEPHIR_INIT_LNVAR(_6);
						ZEPHIR_CONCAT_VS(_6, _5, "' have not defined a bind data type");
						zephir_call_method_p1_cache_noret(_0, "__construct", &_8, _6);
						zephir_throw_exception(_0 TSRMLS_CC);
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&values, value, PH_SEPARATE);
					zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
				} else {
					zephir_array_append(&values, ZEPHIR_GLOBAL(global_null), PH_SEPARATE);
					zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE);
				}
			}
		}
	}
	if (!ZEPHIR_IS_FALSE(identityField)) {
		ZEPHIR_INIT_VAR(defaultValue);
		zephir_call_method(defaultValue, connection, "getdefaultidvalue");
		ZEPHIR_INIT_BNVAR(_0);
		zephir_call_method(_0, connection, "useexplicitidvalue");
		useExplicitIdentity = (zephir_get_boolval(_0)) ? 1 : 0;
		if (useExplicitIdentity) {
			zephir_array_append(&fields, identityField, PH_SEPARATE);
		}
		if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
			ZEPHIR_OBS_NVAR(attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, columnMap, identityField TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(_9);
				object_init_ex(_9, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_SV(_5, "Identity column '", identityField);
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_VS(_6, _5, "' isn't part of the column map");
				zephir_call_method_p1_noret(_9, "__construct", _6);
				zephir_throw_exception(_9 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(attributeField, identityField);
		}
		ZEPHIR_OBS_NVAR(value);
		if (0) {
			if (0) {
				if (useExplicitIdentity) {
					zephir_array_append(&values, defaultValue, PH_SEPARATE);
					zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE);
				}
			} else {
				if (!(useExplicitIdentity)) {
					zephir_array_append(&fields, identityField, PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(bindType);
				if (!(zephir_array_isset_fetch(&bindType, bindDataTypes, identityField TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_9);
					object_init_ex(_9, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_SV(_5, "Identity column '", identityField);
					ZEPHIR_INIT_LNVAR(_6);
					ZEPHIR_CONCAT_VS(_6, _5, "' isn\'t part of the table columns");
					zephir_call_method_p1_noret(_9, "__construct", _6);
					zephir_throw_exception(_9 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&values, value, PH_SEPARATE);
				zephir_array_append(&bindTypes, bindType, PH_SEPARATE);
			}
		} else {
			if (useExplicitIdentity) {
				zephir_array_append(&values, defaultValue, PH_SEPARATE);
				zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE);
			}
		}
	}
	ZEPHIR_INIT_VAR(success);
	zephir_call_method_p4(success, connection, "insert", table, values, fields, bindTypes);
	if (zephir_is_true(success) && !ZEPHIR_IS_FALSE(identityField)) {
		ZEPHIR_INIT_VAR(sequenceName);
		ZVAL_NULL(sequenceName);
		ZEPHIR_INIT_NVAR(_9);
		zephir_call_method(_9, connection, "supportsequences");
		if (ZEPHIR_IS_TRUE(_9)) {
			ZEPHIR_INIT_NVAR(sequenceName);
			if ((zephir_method_exists_str(this_ptr, SS("getsequencename") TSRMLS_CC) == SUCCESS)) {
				zephir_call_method(sequenceName, this_ptr, "getsequencename");
			} else {
				ZEPHIR_INIT_NVAR(_9);
				zephir_call_method(_9, this_ptr, "getsource");
				ZEPHIR_INIT_LNVAR(_5);
				ZEPHIR_CONCAT_VS(_5, _9, "_");
				ZEPHIR_INIT_LNVAR(_6);
				concat_function(_6, _5, identityField TSRMLS_CC);
				ZEPHIR_CONCAT_VS(sequenceName, _6, "_seq");
			}
		}
		ZEPHIR_INIT_NVAR(_9);
		zephir_call_method_p1(_9, connection, "lastinsertid", sequenceName);
		zephir_update_property_zval_zval(this_ptr, attributeField, _9 TSRMLS_CC);
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

	zend_class_entry *_11, *_15;
	zend_function *_8 = NULL, *_9 = NULL;
	HashTable *_4, *_13;
	HashPosition _3, _12;
	zend_bool useDynamicUpdate, changed;
	zval *metaData, *connection, *table, *bindSkip, *fields, *values, *bindTypes, *manager, *bindDataTypes, *field = NULL, *automaticAttributes, *snapshotValue = NULL, *uniqueKey, *uniqueParams, *uniqueTypes, *snapshot, *nonPrimary, *columnMap, *attributeField = NULL, *value = NULL, *primaryKeys, *_0, *_1 = NULL, *_2, **_5, *_6 = NULL, *_7 = NULL, *_10 = NULL, **_14;

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
	ZEPHIR_OBS_VAR(manager);
	zephir_read_property_this(&manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p1(_0, manager, "isusingdynamicupdate", this_ptr);
	useDynamicUpdate = (zephir_get_boolval(_0)) ? 1 : 0;
	if (useDynamicUpdate) {
		ZEPHIR_OBS_VAR(snapshot);
		zephir_read_property_this(&snapshot, this_ptr, SL("_snapshot"), PH_NOISY_CC);
		if ((Z_TYPE_P(snapshot) != IS_ARRAY)) {
			useDynamicUpdate = 0;
		}
	}
	ZEPHIR_INIT_VAR(bindDataTypes);
	zephir_call_method_p1(bindDataTypes, metaData, "getbindtypes", this_ptr);
	ZEPHIR_INIT_VAR(nonPrimary);
	zephir_call_method_p1(nonPrimary, metaData, "getnonprimarykeyattributes", this_ptr);
	ZEPHIR_INIT_VAR(automaticAttributes);
	zephir_call_method_p1(automaticAttributes, metaData, "getautomaticupdateattributes", this_ptr);
	ZEPHIR_INIT_VAR(columnMap);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "orm.column_renaming", 1);
	ZEPHIR_INIT_VAR(_2);
	zephir_call_func_p1(_2, "globals_get", _1);
	if (zephir_is_true(_2)) {
		zephir_call_method_p1(columnMap, metaData, "getcolumnmap", this_ptr);
	} else {
		ZVAL_NULL(columnMap);
	}
	zephir_is_iterable(nonPrimary, &_4, &_3, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		; zend_hash_move_forward_ex(_4, &_3)
	) {
		ZEPHIR_GET_HVALUE(field, _5);
		if (!(zephir_array_isset(automaticAttributes, field))) {
			if (!(zephir_array_isset(bindDataTypes, field))) {
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, phalcon_mvc_model_exception_ce);
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SV(_6, "Column '", field);
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_VS(_7, _6, "' have not defined a bind data type");
				zephir_call_method_p1_cache_noret(_1, "__construct", &_8, _7);
				zephir_throw_exception(_1 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_1);
					object_init_ex(_1, phalcon_mvc_model_exception_ce);
					ZEPHIR_INIT_LNVAR(_6);
					ZEPHIR_CONCAT_SV(_6, "Column '", field);
					ZEPHIR_INIT_LNVAR(_7);
					ZEPHIR_CONCAT_VS(_7, _6, "' isn't part of the column map");
					zephir_call_method_p1_cache_noret(_1, "__construct", &_9, _7);
					zephir_throw_exception(_1 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, field);
			}
			ZEPHIR_OBS_NVAR(value);
			if (0) {
				if (!(useDynamicUpdate)) {
					zephir_array_append(&fields, field, PH_SEPARATE);
					zephir_array_append(&values, value, PH_SEPARATE);
					ZEPHIR_OBS_NVAR(_10);
					zephir_array_fetch(&_10, bindDataTypes, field, PH_NOISY TSRMLS_CC);
					zephir_array_append(&bindTypes, _10, PH_SEPARATE);
				} else {
					ZEPHIR_OBS_NVAR(snapshotValue);
					if (!(zephir_array_isset_fetch(&snapshotValue, snapshot, attributeField TSRMLS_CC))) {
						changed = 1;
					} else {
						changed = !ZEPHIR_IS_EQUAL(value, snapshotValue);
					}
					if (changed) {
						zephir_array_append(&fields, field, PH_SEPARATE);
						zephir_array_append(&values, value, PH_SEPARATE);
						ZEPHIR_OBS_NVAR(_10);
						zephir_array_fetch(&_10, bindDataTypes, field, PH_NOISY TSRMLS_CC);
						zephir_array_append(&bindTypes, _10, PH_SEPARATE);
					}
				}
			} else {
				zephir_array_append(&fields, field, PH_SEPARATE);
				zephir_array_append(&values, ZEPHIR_GLOBAL(global_null), PH_SEPARATE);
				zephir_array_append(&bindTypes, bindSkip, PH_SEPARATE);
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
	if ((Z_TYPE_P(uniqueParams) != IS_ARRAY)) {
		ZEPHIR_INIT_VAR(primaryKeys);
		zephir_call_method_p1(primaryKeys, metaData, "getprimarykeyattributes", this_ptr);
		if (!(zephir_fast_count_int(primaryKeys TSRMLS_CC))) {
			ZEPHIR_INIT_BNVAR(_1);
			_11 = zend_fetch_class(SL("Phalcon_Mvc_Model_Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(_1, _11);
			zephir_throw_exception(_1 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_BNVAR(uniqueParams);
		array_init(uniqueParams);
		zephir_is_iterable(primaryKeys, &_13, &_12, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
			; zend_hash_move_forward_ex(_13, &_12)
		) {
			ZEPHIR_GET_HVALUE(field, _14);
			if ((Z_TYPE_P(columnMap) == IS_ARRAY)) {
				ZEPHIR_OBS_NVAR(attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, columnMap, field TSRMLS_CC))) {
					ZEPHIR_INIT_NVAR(_1);
					_15 = zend_fetch_class(SL("Phalcon_Mvc_Model_Exception"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
					object_init_ex(_1, _15);
					zephir_throw_exception(_1 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(attributeField, field);
			}
			ZEPHIR_OBS_NVAR(value);
			if (0) {
				zephir_array_append(&uniqueParams, value, PH_SEPARATE);
			} else {
				zephir_array_append(&uniqueParams, ZEPHIR_GLOBAL(global_null), PH_SEPARATE);
			}
		}
	}
	ZEPHIR_INIT_BNVAR(_1);
	array_init(_1);
	zephir_array_update_string(&_1, SL("conditions"), &uniqueKey, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("bind"), &uniqueParams, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("bindTypes"), &uniqueTypes, PH_COPY | PH_SEPARATE);
	zephir_call_method_p5(return_value, connection, "update", table, fields, values, _1, bindTypes);
	RETURN_MM();

}

