
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

	zval *source, *modelsManager;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &source);



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

	zval *schema, *modelsManager = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &schema);



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

	zval *parameters = NULL, *params = NULL, *builder, *query, *bindParams = NULL, *bindTypes, *cache, *resultset, *hydration, *_0;

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

