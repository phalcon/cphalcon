
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/file.h"

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
 * $robot->type = 'mechanical'
 * $robot->name = 'Astro Boy';
 * $robot->year = 1952;
 * if ($robot->save() == false) {
 *  echo "Umh, We can store robots: ";
 *  foreach ($robot->getMessages() as $message) {
 *    echo $message;
 *  }
 * } else {
 *  echo "Great, a new robot was saved successfully!";
 * }
 * </code>
 *
 */


/**
 * Phalcon\Mvc\Model initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, Model, mvc_model, phalcon_mvc_model_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_mvc_model_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_modelsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_modelsMetaData"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_schema"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_source"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_errorMessages"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_mvc_model_ce, SL("_operationMade"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_model_ce, SL("_forceExists"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_connection"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueKey"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_uniqueTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_ce, SL("_skipped"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_NONE"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_CREATE"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_UPDATE"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_mvc_model_ce, SL("OP_DELETE"), 3 TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_ce TSRMLS_CC, 4, phalcon_mvc_modelinterface_ce, phalcon_mvc_model_resultinterface_ce, phalcon_di_injectionawareinterface_ce, zend_ce_serializable);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\Model constructor
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @param Phalcon\Mvc\Model\ManagerInterface $modelsManager
 */
PHP_METHOD(Phalcon_Mvc_Model, __construct){

	zval *dependency_injector = NULL, *models_manager = NULL;
	zval *service_name;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &dependency_injector, &models_manager) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!dependency_injector) {
		PHALCON_INIT_VAR(dependency_injector);
	} else {
		PHALCON_SEPARATE_PARAM(dependency_injector);
	}
	
	if (!models_manager) {
		PHALCON_INIT_VAR(models_manager);
	} else {
		PHALCON_SEPARATE_PARAM(models_manager);
	}
	
	/** 
	 * We use a default DI if the user doesn't define one
	 */
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_NVAR(dependency_injector);
		PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
	}
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	/** 
	 * Inject the manager service from the DI
	 */
	if (Z_TYPE_P(models_manager) != IS_OBJECT) {
	
		PHALCON_INIT_VAR(service_name);
		ZVAL_STRING(service_name, "modelsManager", 1);
	
		PHALCON_INIT_NVAR(models_manager);
		PHALCON_CALL_METHOD_PARAMS_1(models_manager, dependency_injector, "getshared", service_name);
		if (Z_TYPE_P(models_manager) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid");
			return;
		}
	}
	
	/** 
	 * Update the models-manager
	 */
	phalcon_update_property_zval(this_ptr, SL("_modelsManager"), models_manager TSRMLS_CC);
	
	/** 
	 * The manager always initializes the object
	 */
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(models_manager, "initialize", this_ptr);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the dependency injection container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model, setDI){

	zval *dependency_injector;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
}

/**
 * Returns the dependency injection container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets a custom events manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Model, setEventsManager){

	zval *events_manager, *models_manager;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &events_manager) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(models_manager, "setcustomeventsmanager", this_ptr, events_manager);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the custom events manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getEventsManager){

	zval *models_manager, *events_manager;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(events_manager);
	PHALCON_CALL_METHOD_PARAMS_1(events_manager, models_manager, "getcustomeventsmanager", this_ptr);
	RETURN_CCTOR(events_manager);
}

/**
 * Returns the models meta-data service related to the entity instance
 *
 * @return Phalcon\Mvc\Model\MetaDataInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsMetaData){

	zval *meta_data = NULL, *dependency_injector, *service;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(meta_data);
	phalcon_read_property(&meta_data, this_ptr, SL("_modelsMetaData"), PH_NOISY_CC);
	if (Z_TYPE_P(meta_data) != IS_OBJECT) {
	
		/** 
		 * Check if the DI is valid
		 */
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
			return;
		}
	
		PHALCON_INIT_VAR(service);
		ZVAL_STRING(service, "modelsMetadata", 1);
	
		/** 
		 * Obtain the models-metadata service from the DI
		 */
		PHALCON_INIT_NVAR(meta_data);
		PHALCON_CALL_METHOD_PARAMS_1(meta_data, dependency_injector, "getshared", service);
		if (Z_TYPE_P(meta_data) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsMetadata' is not valid");
			return;
		}
	
		/** 
		 * Update the models-metada property
		 */
		phalcon_update_property_zval(this_ptr, SL("_modelsMetaData"), meta_data TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(meta_data);
}

/**
 * Returns the models manager related to the entity instance
 *
 * @return Phalcon\Mvc\Model\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getModelsManager){


	RETURN_MEMBER(this_ptr, "_modelsManager");
}

/**
 * Sets a transaction related to the Model instance
 *
 *<code>
 *try {
 *
 *  $transactionManager = new Phalcon\Mvc\Model\Transaction\Manager();
 *
 *  $transaction = $transactionManager->get();
 *
 *  $robot = new Robots();
 *  $robot->setTransaction($transaction);
 *  $robot->name = 'WALL·E';
 *  $robot->created_at = date('Y-m-d');
 *  if($robot->save()==false){
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
 *}
 *catch(Phalcon\Mvc\Model\Transaction\Failed $e){
 *  echo 'Failed, reason: ', $e->getMessage();
 *}
 *
 *</code>
 *
 * @param Phalcon\Mvc\Model\TransactionInterface $transaction
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setTransaction){

	zval *transaction, *connection;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &transaction) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(transaction) == IS_OBJECT) {
		PHALCON_INIT_VAR(connection);
		PHALCON_CALL_METHOD(connection, transaction, "getconnection");
		phalcon_update_property_zval(this_ptr, SL("_connection"), connection TSRMLS_CC);
		RETURN_CTOR(this_ptr);
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Transaction should be an object");
	return;
}

/**
 * Sets table name which model should be mapped (deprecated)
 *
 * @param string $source
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setSource){

	zval *source;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &source) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_source"), source TSRMLS_CC);
	RETURN_CTORW(this_ptr);
}

/**
 * Returns table name mapped in the model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getSource){

	zval *source = NULL, *class_name;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(source);
	phalcon_read_property(&source, this_ptr, SL("_source"), PH_NOISY_CC);
	if (!zend_is_true(source)) {
		PHALCON_INIT_VAR(class_name);
		phalcon_get_class_ns(class_name, this_ptr, 0 TSRMLS_CC);
	
		PHALCON_INIT_NVAR(source);
		phalcon_uncamelize(source, class_name TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_source"), source TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(source);
}

/**
 * Sets schema name where table mapped is located (deprecated)
 *
 * @param string $schema
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setSchema){

	zval *schema;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &schema) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_schema"), schema TSRMLS_CC);
	RETURN_CTORW(this_ptr);
}

/**
 * Returns schema name where table mapped is located
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getSchema){


	RETURN_MEMBER(this_ptr, "_schema");
}

/**
 * Sets the DependencyInjection connection service name
 *
 * @param string $connectionService
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, setConnectionService){

	zval *connection_service, *models_manager;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &connection_service) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(models_manager, "setconnectionservice", this_ptr, connection_service);
	RETURN_CTOR(this_ptr);
}

/**
 * Returns DependencyInjection connection service
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, getConnectionService){

	zval *models_manager, *connection_service;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(connection_service);
	PHALCON_CALL_METHOD_PARAMS_1(connection_service, models_manager, "getconnectionservice", this_ptr);
	RETURN_CCTOR(connection_service);
}

/**
 * Forces that model doesn't need to be checked if exists before store it
 *
 * @param boolean $forceExists
 */
PHP_METHOD(Phalcon_Mvc_Model, setForceExists){

	zval *force_exists;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &force_exists) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_forceExists"), force_exists TSRMLS_CC);
	
}

/**
 * Gets the internal database connection
 *
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getConnection){

	zval *connection = NULL, *models_manager;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(connection);
	phalcon_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(connection) != IS_OBJECT) {
		PHALCON_OBS_VAR(models_manager);
		phalcon_read_property(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
		PHALCON_INIT_NVAR(connection);
		PHALCON_CALL_METHOD_PARAMS_1(connection, models_manager, "getconnection", this_ptr);
		phalcon_update_property_zval(this_ptr, SL("_connection"), connection TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(connection);
}

/**
 * Assigns values to a model from an array returning a new model.
 *
 *<code>
 *$robot = Phalcon\Mvc\Model::dumpResult(new Robots(), array(
 *  'type' => 'mechanical',
 *  'name' => 'Astro Boy',
 *  'year' => 1952
 *));
 *</code>
 *
 * @param Phalcon\Mvc\Model $base
 * @param array $data
 * @param array $columnMap
 * @param boolean $forceExists
 * @return Phalcon\Mvc\Model $result
 */
PHP_METHOD(Phalcon_Mvc_Model, dumpResultMap){

	zval *base, *data, *column_map, *force_exists = NULL, *object;
	zval *value = NULL, *key = NULL, *attribute = NULL, *exception_message = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &base, &data, &column_map, &force_exists) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!force_exists) {
		PHALCON_INIT_VAR(force_exists);
		ZVAL_BOOL(force_exists, 1);
	}
	
	if (Z_TYPE_P(data) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(object);
		if (phalcon_clone(object, base TSRMLS_CC) == FAILURE) {
			return;
		}
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(object, "setforceexists", force_exists);
	
		if (!phalcon_is_iterable(data, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(value);
	
			if (Z_TYPE_P(key) == IS_STRING) {
	
				/** 
				 * Only string keys in the data are valid
				 */
				if (Z_TYPE_P(column_map) == IS_ARRAY) { 
	
					/** 
					 * Every field must be part of the column map
					 */
					if (phalcon_array_isset(column_map, key)) {
						PHALCON_OBS_NVAR(attribute);
						phalcon_array_fetch(&attribute, column_map, key, PH_NOISY_CC);
						phalcon_update_property_zval_zval(object, attribute, value TSRMLS_CC);
					} else {
						PHALCON_INIT_NVAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Column \"", key, "\" doesn't make part of the column map");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
				} else {
					phalcon_update_property_zval_zval(object, key, value TSRMLS_CC);
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	
		RETURN_CCTOR(object);
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data to dump in the object must be an Array");
	return;
}

/**
 * Assigns values to a model from an array returning a new model.
 *
 *<code>
 *$robot = Phalcon\Mvc\Model::dumpResult(new Robots(), array(
 *  'type' => 'mechanical',
 *  'name' => 'Astro Boy',
 *  'year' => 1952
 *));
 *</code>
 *
 * @param Phalcon\Mvc\Model $base
 * @param array $data
 * @param boolean $forceExists
 * @return Phalcon\Mvc\Model $result
 */
PHP_METHOD(Phalcon_Mvc_Model, dumpResult){

	zval *base, *data, *force_exists = NULL, *object, *value = NULL;
	zval *key = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &base, &data, &force_exists) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!force_exists) {
		PHALCON_INIT_VAR(force_exists);
		ZVAL_BOOL(force_exists, 1);
	}
	
	if (Z_TYPE_P(data) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(object);
		if (phalcon_clone(object, base TSRMLS_CC) == FAILURE) {
			return;
		}
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(object, "setforceexists", force_exists);
	
		if (!phalcon_is_iterable(data, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(value);
	
			if (Z_TYPE_P(key) == IS_STRING) {
				phalcon_update_property_zval_zval(object, key, value TSRMLS_CC);
			} else {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid key in array data provided to dumpResult()");
				return;
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	
		RETURN_CCTOR(object);
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data to dump in the object must be an Array");
	return;
}

/**
 * Allows to query a set of records that match the specified conditions
 *
 * <code>
 *
 * //How many robots are there?
 * $robots = Robots::find();
 * echo "There are ", count($robots);
 *
 * //How many mechanical robots are there?
 * $robots = Robots::find("type='mechanical'");
 * echo "There are ", count($robots);
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
 * @param 	array $parameters
 * @return  Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, find){

	zval *parameters = NULL, *model_name, *params = NULL, *builder;
	zval *query, *bind_params = NULL, *bind_types = NULL, *cache;
	zval *resultset;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_called_class(model_name  TSRMLS_CC);
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
	
		PHALCON_INIT_VAR(params);
		array_init(params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
		}
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	/** 
	 * Builds a query with the passed parameters
	 */
	PHALCON_INIT_VAR(builder);
	object_init_ex(builder, phalcon_mvc_model_query_builder_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(builder, "__construct", params);
	
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(builder, "from", model_name);
	
	PHALCON_INIT_VAR(query);
	PHALCON_CALL_METHOD(query, builder, "getquery");
	
	/** 
	 * Check for bind parameters
	 */
	PHALCON_INIT_VAR(bind_params);
	
	PHALCON_INIT_VAR(bind_types);
	if (phalcon_array_isset_string(params, SS("bind"))) {
	
		PHALCON_OBS_NVAR(bind_params);
		phalcon_array_fetch_string(&bind_params, params, SL("bind"), PH_NOISY_CC);
		if (phalcon_array_isset_string(params, SS("bindTypes"))) {
			PHALCON_OBS_NVAR(bind_types);
			phalcon_array_fetch_string(&bind_types, params, SL("bindTypes"), PH_NOISY_CC);
		}
	}
	
	/** 
	 * Pass the cache options to the query
	 */
	if (phalcon_array_isset_string(params, SS("cache"))) {
		PHALCON_OBS_VAR(cache);
		phalcon_array_fetch_string(&cache, params, SL("cache"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "cache", cache);
	}
	
	/** 
	 * Execute the query passing the bind-params and casting-types
	 */
	PHALCON_INIT_VAR(resultset);
	PHALCON_CALL_METHOD_PARAMS_2(resultset, query, "execute", bind_params, bind_types);
	
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
 * @param array $parameters
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model, findFirst){

	zval *parameters = NULL, *model_name, *params = NULL, *builder;
	zval *one, *query, *bind_params = NULL, *bind_types = NULL, *cache;
	zval *unique, *resultset;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_called_class(model_name  TSRMLS_CC);
	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
	
		PHALCON_INIT_VAR(params);
		array_init(params);
		if (Z_TYPE_P(parameters) != IS_NULL) {
			phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
		}
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	
	/** 
	 * Builds a query with the passed parameters
	 */
	PHALCON_INIT_VAR(builder);
	object_init_ex(builder, phalcon_mvc_model_query_builder_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(builder, "__construct", params);
	
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(builder, "from", model_name);
	
	/** 
	 * We only want we the first record
	 */
	PHALCON_INIT_VAR(one);
	ZVAL_LONG(one, 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(builder, "limit", one);
	
	PHALCON_INIT_VAR(query);
	PHALCON_CALL_METHOD(query, builder, "getquery");
	
	/** 
	 * Check for bind parameters
	 */
	PHALCON_INIT_VAR(bind_params);
	
	PHALCON_INIT_VAR(bind_types);
	if (phalcon_array_isset_string(params, SS("bind"))) {
	
		PHALCON_OBS_NVAR(bind_params);
		phalcon_array_fetch_string(&bind_params, params, SL("bind"), PH_NOISY_CC);
		if (phalcon_array_isset_string(params, SS("bindTypes"))) {
			PHALCON_OBS_NVAR(bind_types);
			phalcon_array_fetch_string(&bind_types, params, SL("bindTypes"), PH_NOISY_CC);
		}
	}
	
	/** 
	 * Pass the cache options to the query
	 */
	if (phalcon_array_isset_string(params, SS("cache"))) {
		PHALCON_OBS_VAR(cache);
		phalcon_array_fetch_string(&cache, params, SL("cache"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "cache", cache);
	}
	
	PHALCON_INIT_VAR(unique);
	ZVAL_BOOL(unique, 1);
	
	/** 
	 * Return only the first row
	 */
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "setuniquerow", unique);
	
	/** 
	 * Execute the query passing the bind-params and casting-types
	 */
	PHALCON_INIT_VAR(resultset);
	PHALCON_CALL_METHOD_PARAMS_2(resultset, query, "execute", bind_params, bind_types);
	
	RETURN_CCTOR(resultset);
}

/**
 * Create a criteria for a especific model
 *
 * @param Phalcon\DiInterface $dependencyInjector
 * @return Phalcon\Mvc\Model\Criteria
 */
PHP_METHOD(Phalcon_Mvc_Model, query){

	zval *dependency_injector = NULL, *model_name, *criteria;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &dependency_injector) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!dependency_injector) {
		PHALCON_INIT_VAR(dependency_injector);
	} else {
		PHALCON_SEPARATE_PARAM(dependency_injector);
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_called_class(model_name  TSRMLS_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_INIT_NVAR(dependency_injector);
		PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
	}
	
	PHALCON_INIT_VAR(criteria);
	object_init_ex(criteria, phalcon_mvc_model_criteria_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(criteria, "setdi", dependency_injector);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(criteria, "setmodelname", model_name);
	
	RETURN_CTOR(criteria);
}

/**
 * Checks if the current record already exists or not
 *
 * @param Phalcon\Mvc\Model\MetadataInterface $metaData
 * @param Phalcon\Db\AdapterInterface $connection
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _exists){

	zval *meta_data, *connection, *table = NULL, *unique_params = NULL;
	zval *unique_types = NULL, *unique_key = NULL, *primary_keys;
	zval *bind_data_types, *number_primary, *column_map = NULL;
	zval *null_value, *number_empty, *where_pk, *field = NULL;
	zval *attribute_field = NULL, *exception_message = NULL;
	zval *value = NULL, *escaped_field = NULL, *pk_condition = NULL, *type = NULL;
	zval *is_empty, *join_where, *force_exists, *schema;
	zval *source, *escaped_table, *null_mode, *select;
	zval *num, *row_count;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &meta_data, &connection, &table) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!table) {
		PHALCON_INIT_VAR(table);
	} else {
		PHALCON_SEPARATE_PARAM(table);
	}
	
	PHALCON_INIT_VAR(unique_params);
	
	PHALCON_INIT_VAR(unique_types);
	
	/** 
	 * Builds a unique primary key condition
	 */
	PHALCON_OBS_VAR(unique_key);
	phalcon_read_property(&unique_key, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	if (Z_TYPE_P(unique_key) == IS_NULL) {
	
		PHALCON_INIT_VAR(primary_keys);
		PHALCON_CALL_METHOD_PARAMS_1(primary_keys, meta_data, "getprimarykeyattributes", this_ptr);
	
		PHALCON_INIT_VAR(bind_data_types);
		PHALCON_CALL_METHOD_PARAMS_1(bind_data_types, meta_data, "getbindtypes", this_ptr);
	
		PHALCON_INIT_VAR(number_primary);
		phalcon_fast_count(number_primary, primary_keys TSRMLS_CC);
		if (zend_is_true(number_primary)) {
			if (PHALCON_GLOBAL(orm).column_renaming) {
				PHALCON_INIT_VAR(column_map);
				PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getcolumnmap", this_ptr);
			} else {
				PHALCON_INIT_NVAR(column_map);
			}
	
			PHALCON_INIT_VAR(null_value);
	
			PHALCON_INIT_VAR(number_empty);
			ZVAL_LONG(number_empty, 0);
	
			PHALCON_INIT_VAR(where_pk);
			array_init(where_pk);
	
			array_init(unique_params);
	
			array_init(unique_types);
	
			/** 
			 * We need to create a primary key based on the current data
			 */
	
			if (!phalcon_is_iterable(primary_keys, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(field);
	
				if (Z_TYPE_P(column_map) == IS_ARRAY) { 
					if (phalcon_array_isset(column_map, field)) {
						PHALCON_OBS_NVAR(attribute_field);
						phalcon_array_fetch(&attribute_field, column_map, field, PH_NOISY_CC);
					} else {
						PHALCON_INIT_NVAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Column '", field, "\" isn't part of the column map");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
				} else {
					PHALCON_CPY_WRT(attribute_field, field);
				}
	
				/** 
				 * If the primary key attribute is set append it to the conditions
				 */
				if (phalcon_isset_property_zval(this_ptr, attribute_field TSRMLS_CC)) {
	
					PHALCON_OBS_NVAR(value);
					phalcon_read_property_zval(&value, this_ptr, attribute_field, PH_NOISY_CC);
	
					/** 
					 * We count how many fields are empty, if all fields are empy we don't perform an
					 * 'exist' check
					 */
					if (PHALCON_IS_EMPTY(value)) {
						PHALCON_SEPARATE(number_empty);
						increment_function(number_empty);
					}
	
					phalcon_array_append(&unique_params, value, PH_SEPARATE TSRMLS_CC);
				} else {
					phalcon_array_append(&unique_params, null_value, PH_SEPARATE TSRMLS_CC);
					PHALCON_SEPARATE(number_empty);
					increment_function(number_empty);
				}
	
				PHALCON_INIT_NVAR(escaped_field);
				PHALCON_CALL_METHOD_PARAMS_1(escaped_field, connection, "escapeidentifier", field);
	
				PHALCON_INIT_NVAR(pk_condition);
				PHALCON_CONCAT_VS(pk_condition, escaped_field, " = ?");
				if (!phalcon_array_isset(bind_data_types, field)) {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Column '", field, "\" isn't part of the table columns");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
	
				PHALCON_OBS_NVAR(type);
				phalcon_array_fetch(&type, bind_data_types, field, PH_NOISY_CC);
				phalcon_array_append(&unique_types, type, PH_SEPARATE TSRMLS_CC);
				phalcon_array_append(&where_pk, pk_condition, PH_SEPARATE TSRMLS_CC);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			PHALCON_INIT_VAR(is_empty);
			is_equal_function(is_empty, number_primary, number_empty TSRMLS_CC);
			if (PHALCON_IS_FALSE(is_empty)) {
				PHALCON_INIT_VAR(join_where);
				phalcon_fast_join_str(join_where, SL(" AND "), where_pk TSRMLS_CC);
	
				/** 
				 * The unique key is composed of 3 parts _uniqueKey, uniqueParams, uniqueTypes
				 */
				phalcon_update_property_zval(this_ptr, SL("_uniqueKey"), join_where TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_uniqueParams"), unique_params TSRMLS_CC);
				phalcon_update_property_zval(this_ptr, SL("_uniqueTypes"), unique_types TSRMLS_CC);
				PHALCON_CPY_WRT(unique_key, join_where);
			} else {
				RETURN_MM_FALSE;
			}
		} else {
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * If we already know if the record exists we don't check it
	 */
	PHALCON_OBS_VAR(force_exists);
	phalcon_read_property(&force_exists, this_ptr, SL("_forceExists"), PH_NOISY_CC);
	if (PHALCON_IS_FALSE(force_exists)) {
		if (Z_TYPE_P(unique_key) == IS_NULL) {
			PHALCON_OBS_NVAR(unique_key);
			phalcon_read_property(&unique_key, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
		}
		if (Z_TYPE_P(unique_params) == IS_NULL) {
			PHALCON_OBS_NVAR(unique_params);
			phalcon_read_property(&unique_params, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
		}
	
		if (Z_TYPE_P(unique_types) == IS_NULL) {
			PHALCON_OBS_NVAR(unique_types);
			phalcon_read_property(&unique_types, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC);
		}
	
		PHALCON_INIT_VAR(schema);
		PHALCON_CALL_METHOD(schema, this_ptr, "getschema");
	
		PHALCON_INIT_VAR(source);
		PHALCON_CALL_METHOD(source, this_ptr, "getsource");
		if (zend_is_true(schema)) {
			PHALCON_INIT_NVAR(table);
			array_init_size(table, 2);
			phalcon_array_append(&table, schema, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&table, source, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(table, source);
		}
	
		PHALCON_INIT_VAR(escaped_table);
		PHALCON_CALL_METHOD_PARAMS_1(escaped_table, connection, "escapeidentifier", table);
	
		PHALCON_INIT_VAR(null_mode);
	
		/** 
		 * Here we use a single COUNT(*) without PHQL to make the execution faster
		 */
		PHALCON_INIT_VAR(select);
		PHALCON_CONCAT_SVSV(select, "SELECT COUNT(*) AS rowcount FROM ", escaped_table, " WHERE ", unique_key);
	
		PHALCON_INIT_VAR(num);
		PHALCON_CALL_METHOD_PARAMS_4(num, connection, "fetchone", select, null_mode, unique_params, unique_types);
	
		PHALCON_OBS_VAR(row_count);
		phalcon_array_fetch_string(&row_count, num, SL("rowcount"), PH_NOISY_CC);
		if (zend_is_true(row_count)) {
			phalcon_update_property_bool(this_ptr, SL("_forceExists"), 1 TSRMLS_CC);
			RETURN_MM_TRUE;
		} else {
			phalcon_update_property_bool(this_ptr, SL("_forceExists"), 0 TSRMLS_CC);
		}
	} else {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Generate a PHQL SELECT statement for an aggregate
 *
 * @param string $function
 * @param string $alias
 * @param array $parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, _groupResult){

	zval *function, *alias, *parameters, *params = NULL, *group_column = NULL;
	zval *distinct_column, *columns = NULL, *group_columns;
	zval *model_name, *builder, *query, *bind_params = NULL;
	zval *bind_types = NULL, *resultset, *cache, *number_rows;
	zval *first_row, *value;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &function, &alias, &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(parameters) != IS_ARRAY) { 
		if (Z_TYPE_P(parameters) != IS_NULL) {
			PHALCON_INIT_VAR(params);
			array_init_size(params, 1);
			phalcon_array_append(&params, parameters, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_INIT_NVAR(params);
			array_init(params);
		}
	} else {
		PHALCON_CPY_WRT(params, parameters);
	}
	if (phalcon_array_isset_string(params, SS("column"))) {
		PHALCON_OBS_VAR(group_column);
		phalcon_array_fetch_string(&group_column, params, SL("column"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(group_column);
		ZVAL_STRING(group_column, "*", 1);
	}
	
	/** 
	 * Builds the columns to query according to the received parameters
	 */
	if (phalcon_array_isset_string(params, SS("distinct"))) {
		PHALCON_OBS_VAR(distinct_column);
		phalcon_array_fetch_string(&distinct_column, params, SL("distinct"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(columns);
		PHALCON_CONCAT_VSVSV(columns, function, "(DISTINCT ", distinct_column, ") AS ", alias);
	} else {
		if (phalcon_array_isset_string(params, SS("group"))) {
			PHALCON_OBS_VAR(group_columns);
			phalcon_array_fetch_string(&group_columns, params, SL("group"), PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(columns);
			PHALCON_CONCAT_VSVSVSV(columns, group_columns, ", ", function, "(", group_column, ") AS ", alias);
		} else {
			PHALCON_INIT_NVAR(columns);
			PHALCON_CONCAT_VSVSV(columns, function, "(", group_column, ") AS ", alias);
		}
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_called_class(model_name  TSRMLS_CC);
	
	/** 
	 * Builds a query with the passed parameters
	 */
	PHALCON_INIT_VAR(builder);
	object_init_ex(builder, phalcon_mvc_model_query_builder_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(builder, "__construct", params);
	
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(builder, "columns", columns);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(builder, "from", model_name);
	
	PHALCON_INIT_VAR(query);
	PHALCON_CALL_METHOD(query, builder, "getquery");
	
	/** 
	 * Check for bind parameters
	 */
	PHALCON_INIT_VAR(bind_params);
	
	PHALCON_INIT_VAR(bind_types);
	if (phalcon_array_isset_string(params, SS("bind"))) {
	
		PHALCON_OBS_NVAR(bind_params);
		phalcon_array_fetch_string(&bind_params, params, SL("bind"), PH_NOISY_CC);
		if (phalcon_array_isset_string(params, SS("bindTypes"))) {
			PHALCON_OBS_NVAR(bind_types);
			phalcon_array_fetch_string(&bind_types, params, SL("bindTypes"), PH_NOISY_CC);
		}
	}
	
	PHALCON_INIT_VAR(resultset);
	PHALCON_CALL_METHOD_PARAMS_2(resultset, query, "execute", bind_params, bind_types);
	
	/** 
	 * Pass the cache options to the query
	 */
	if (phalcon_array_isset_string(params, SS("cache"))) {
		PHALCON_OBS_VAR(cache);
		phalcon_array_fetch_string(&cache, params, SL("cache"), PH_NOISY_CC);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "cache", cache);
	}
	
	if (phalcon_array_isset_string(params, SS("group"))) {
		/** 
		 * Return the full resultset if the query is grouped
		 */
		RETURN_CCTOR(resultset);
	} else {
		/** 
		 * Return only the value in the first result
		 */
		PHALCON_INIT_VAR(number_rows);
		phalcon_fast_count(number_rows, resultset TSRMLS_CC);
	
		PHALCON_INIT_VAR(first_row);
		PHALCON_CALL_METHOD(first_row, resultset, "getfirst");
	
		PHALCON_OBS_VAR(value);
		phalcon_read_property_zval(&value, first_row, alias, PH_NOISY_CC);
		RETURN_CCTOR(value);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Allows to count how many records match the specified conditions
 *
 * <code>
 *
 * //How many robots are there?
 * $number = Robots::count();
 * echo "There are ", $number;
 *
 * //How many mechanical robots are there?
 * $number = Robots::count("type='mechanical'");
 * echo "There are ", $number, " mechanical robots";
 *
 * </code>
 *
 * @param array $parameters
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model, count){

	zval *parameters = NULL, *function, *alias, *group;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	PHALCON_INIT_VAR(function);
	ZVAL_STRING(function, "COUNT", 1);
	
	PHALCON_INIT_VAR(alias);
	ZVAL_STRING(alias, "rowcount", 1);
	
	PHALCON_INIT_VAR(group);
	PHALCON_CALL_SELF_PARAMS_3(group, this_ptr, "_groupresult", function, alias, parameters);
	RETURN_CCTOR(group);
}

/**
 * Allows to calculate a summatory on a column that match the specified conditions
 *
 * <code>
 *
 * //How much are all robots?
 * $sum = Robots::sum(array('column' => 'price'));
 * echo "The total price of robots is ", $sum;
 *
 * //How much are mechanical robots?
 * $sum = Robots::sum(array("type='mechanical'", 'column' => 'price'));
 * echo "The total price of mechanical robots is  ", $sum;
 *
 * </code>
 *
 * @param array $parameters
 * @return double
 */
PHP_METHOD(Phalcon_Mvc_Model, sum){

	zval *parameters = NULL, *function, *alias, *group;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	PHALCON_INIT_VAR(function);
	ZVAL_STRING(function, "SUM", 1);
	
	PHALCON_INIT_VAR(alias);
	ZVAL_STRING(alias, "sumatory", 1);
	
	PHALCON_INIT_VAR(group);
	PHALCON_CALL_SELF_PARAMS_3(group, this_ptr, "_groupresult", function, alias, parameters);
	RETURN_CCTOR(group);
}

/**
 * Allows to get the maximum value of a column that match the specified conditions
 *
 * <code>
 *
 * //What is the maximum robot id?
 * $id = Robots::maximum(array('column' => 'id'));
 * echo "The maximum robot id is: ", $id;
 *
 * //What is the maximum id of mechanical robots?
 * $sum = Robots::maximum(array("type='mechanical'", 'column' => 'id'));
 * echo "The maximum robot id of mechanical robots is ", $id;
 *
 * </code>
 *
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, maximum){

	zval *parameters = NULL, *function, *alias, *group;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	PHALCON_INIT_VAR(function);
	ZVAL_STRING(function, "MAX", 1);
	
	PHALCON_INIT_VAR(alias);
	ZVAL_STRING(alias, "maximum", 1);
	
	PHALCON_INIT_VAR(group);
	PHALCON_CALL_SELF_PARAMS_3(group, this_ptr, "_groupresult", function, alias, parameters);
	RETURN_CCTOR(group);
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
 * @param array $parameters
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, minimum){

	zval *parameters = NULL, *function, *alias, *group;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	PHALCON_INIT_VAR(function);
	ZVAL_STRING(function, "MIN", 1);
	
	PHALCON_INIT_VAR(alias);
	ZVAL_STRING(alias, "minimum", 1);
	
	PHALCON_INIT_VAR(group);
	PHALCON_CALL_SELF_PARAMS_3(group, this_ptr, "_groupresult", function, alias, parameters);
	RETURN_CCTOR(group);
}

/**
 * Allows to calculate the average value on a column matching the specified conditions
 *
 * <code>
 *
 * //What's the average price of robots?
 * $average = Robots::average(array('column' => 'price'));
 * echo "The average price is ", $average;
 *
 * //What's the average price of mechanical robots?
 * $average = Robots::average(array("type='mechanical'", 'column' => 'price'));
 * echo "The average price of mechanical robots is ", $average;
 *
 * </code>
 *
 * @param array $parameters
 * @return double
 */
PHP_METHOD(Phalcon_Mvc_Model, average){

	zval *parameters = NULL, *function, *alias, *group;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	PHALCON_INIT_VAR(function);
	ZVAL_STRING(function, "AVG", 1);
	
	PHALCON_INIT_VAR(alias);
	ZVAL_STRING(alias, "average", 1);
	
	PHALCON_INIT_VAR(group);
	PHALCON_CALL_SELF_PARAMS_3(group, this_ptr, "_groupresult", function, alias, parameters);
	RETURN_CCTOR(group);
}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 *
 * @param string $eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEvent){

	zval *event_name, *models_manager, *success;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &event_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	/** 
	 * Check if there is a method with the same name of the event
	 */
	if (phalcon_method_exists(this_ptr, event_name TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD_NORETURN(this_ptr, Z_STRVAL_P(event_name));
	}
	
	/** 
	 * Send a notification to the events manager
	 */
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_2(success, models_manager, "notifyevent", event_name, this_ptr);
	
	RETURN_CCTOR(success);
}

/**
 * Fires an event, implicitly calls behaviors and listeners in the events manager are notified
 * This method stops if one of the callbacks/listeners returns boolean false
 *
 * @param string $eventName
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, fireEventCancel){

	zval *event_name, *status = NULL, *models_manager;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &event_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	/** 
	 * Check if there is a method with the same name of the event
	 */
	if (phalcon_method_exists(this_ptr, event_name TSRMLS_CC) == SUCCESS) {
	
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD(status, this_ptr, Z_STRVAL_P(event_name));
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Send a notification to the events manager
	 */
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
	PHALCON_INIT_NVAR(status);
	PHALCON_CALL_METHOD_PARAMS_2(status, models_manager, "notifyevent", event_name, this_ptr);
	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}
	
	RETURN_MM_TRUE;
}

/**
 * Cancel the current operation
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _cancelOperation){

	zval *operation_made, *event_name = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(operation_made);
	phalcon_read_property(&operation_made, this_ptr, SL("_operationMade"), PH_NOISY_CC);
	if (phalcon_compare_strict_long(operation_made, 3 TSRMLS_CC)) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "notDeleted", 1);
	} else {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "notSaved", 1);
	}
	
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "fireevent", event_name);
	
	PHALCON_MM_RESTORE();
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
 *     if (this->name == 'Peter') {
 *        $message = new Message("Sorry, but a robot cannot be named Peter");
 *        $this->appendMessage($message);
 *     }
 *   }
 * }
 * </code>
 *
 * @param Phalcon\Mvc\Model\MessageInterface $message
 */
PHP_METHOD(Phalcon_Mvc_Model, appendMessage){

	zval *message, *type, *exception_message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &message) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(message) != IS_OBJECT) {
		PHALCON_INIT_VAR(type);
		PHALCON_CALL_FUNC_PARAMS_1(type, "gettype", message);
	
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Invalid message format '", type, "'");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
		return;
	}
	phalcon_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
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
 * @param object $validator
 */
PHP_METHOD(Phalcon_Mvc_Model, validate){

	zval *validator, *status, *messages, *message = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &validator) == FAILURE) {
		RETURN_MM_NULL();
	}

	/** 
	 * Valid validators are objects
	 */
	if (Z_TYPE_P(validator) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Validator must be an Object");
		return;
	}
	
	/** 
	 * Call the validation, if it returns false we append the messages to the current
	 * object
	 */
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD_PARAMS_1(status, validator, "validate", this_ptr);
	if (PHALCON_IS_FALSE(status)) {
	
		PHALCON_INIT_VAR(messages);
		PHALCON_CALL_METHOD(messages, validator, "getmessages");
	
		if (!phalcon_is_iterable(messages, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(message);
	
			phalcon_update_property_array_append(this_ptr, SL("_errorMessages"), message TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_MM_RESTORE();
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
PHP_METHOD(Phalcon_Mvc_Model, validationHasFailed){

	zval *error_messages;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(error_messages);
	phalcon_read_property(&error_messages, this_ptr, SL("_errorMessages"), PH_NOISY_CC);
	if (Z_TYPE_P(error_messages) == IS_ARRAY) { 
		if (phalcon_fast_count_ev(error_messages TSRMLS_CC)) {
			RETURN_MM_TRUE;
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Returns all the validation messages
 *
 * <code>
 *$robot = new Robots();
 *$robot->type = 'mechanical';
 *$robot->name = 'Astro Boy';
 *$robot->year = 1952;
 *if ($robot->save() == false) {
 *  echo "Umh, We can't store robots right now ";
 *  foreach ($robot->getMessages() as $message) {
 *    echo $message;
 *  }
 *} else {
 *  echo "Great, a new robot was saved successfully!";
 *}
 * </code>
 *
 * @return Phalcon\Mvc\Model\MessageInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model, getMessages){


	RETURN_MEMBER(this_ptr, "_errorMessages");
}

/**
 * Reads "belongs to" relations and check the virtual foreign keys when inserting or updating records
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeys){

	zval *manager, *belongs_to, *relation = NULL, *foreign_key = NULL;
	zval *relation_class = NULL, *referenced_model = NULL, *conditions = NULL;
	zval *bind_params = NULL, *fields = NULL, *referenced_fields = NULL;
	zval *field = NULL, *position = NULL, *value = NULL, *referenced_field = NULL;
	zval *condition = NULL, *extra_conditions = NULL, *join_conditions = NULL;
	zval *parameters = NULL, *rowcount = NULL, *user_message = NULL, *joined_fields = NULL;
	zval *type = NULL, *message = NULL, *event_name;
	zend_bool error;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	/** 
	 * Get the models manager
	 */
	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
	/** 
	 * We check if some of the belongsTo relations act as virtual foreign key
	 */
	PHALCON_INIT_VAR(belongs_to);
	PHALCON_CALL_METHOD_PARAMS_1(belongs_to, manager, "getbelongsto", this_ptr);
	if (phalcon_fast_count_ev(belongs_to TSRMLS_CC)) {
		error = 0;
	
		if (!phalcon_is_iterable(belongs_to, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(relation);
	
			PHALCON_INIT_NVAR(foreign_key);
			PHALCON_CALL_METHOD(foreign_key, relation, "getforeignkey");
			if (PHALCON_IS_NOT_FALSE(foreign_key)) {
	
				PHALCON_INIT_NVAR(relation_class);
				PHALCON_CALL_METHOD(relation_class, relation, "getreferencedmodel");
	
				/** 
				 * Load the referenced model if needed
				 */
				PHALCON_INIT_NVAR(referenced_model);
				PHALCON_CALL_METHOD_PARAMS_1(referenced_model, manager, "load", relation_class);
	
				/** 
				 * Since relations can have multiple columns or a single one, we need to build a
				 * condition for each of these cases
				 */
				PHALCON_INIT_NVAR(conditions);
				array_init(conditions);
	
				PHALCON_INIT_NVAR(bind_params);
				array_init(bind_params);
	
				PHALCON_INIT_NVAR(fields);
				PHALCON_CALL_METHOD(fields, relation, "getfields");
	
				PHALCON_INIT_NVAR(referenced_fields);
				PHALCON_CALL_METHOD(referenced_fields, relation, "getreferencedfields");
				if (Z_TYPE_P(fields) == IS_ARRAY) { 
	
					/** 
					 * Create a compound condition
					 */
	
					if (!phalcon_is_iterable(fields, &ah1, &hp1, 0, 0 TSRMLS_CC)) {
						return;
					}
	
	
					while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
						PHALCON_GET_FOREACH_KEY(position, ah1, hp1);
						PHALCON_GET_FOREACH_VALUE(field);
	
						if (phalcon_isset_property_zval(this_ptr, field TSRMLS_CC)) {
							PHALCON_OBS_NVAR(value);
							phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY_CC);
						} else {
							PHALCON_INIT_NVAR(value);
						}
	
						PHALCON_OBS_NVAR(referenced_field);
						phalcon_array_fetch(&referenced_field, referenced_fields, position, PH_NOISY_CC);
	
						PHALCON_INIT_NVAR(condition);
						PHALCON_CONCAT_VSV(condition, referenced_field, " = ?", position);
						phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
						phalcon_array_append(&bind_params, value, PH_SEPARATE TSRMLS_CC);
	
						zend_hash_move_forward_ex(ah1, &hp1);
					}
	
				} else {
					/** 
					 * Create a simple condition
					 */
					if (phalcon_isset_property_zval(this_ptr, fields TSRMLS_CC)) {
						PHALCON_OBS_NVAR(value);
						phalcon_read_property_zval(&value, this_ptr, fields, PH_NOISY_CC);
					} else {
						PHALCON_INIT_NVAR(value);
					}
	
					PHALCON_INIT_NVAR(condition);
					PHALCON_CONCAT_VS(condition, referenced_fields, " = ?0");
					phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&bind_params, value, PH_SEPARATE TSRMLS_CC);
				}
	
				/** 
				 * Check if the virtual foreign key has extra conditions
				 */
				if (phalcon_array_isset_string(foreign_key, SS("conditions"))) {
					PHALCON_OBS_NVAR(extra_conditions);
					phalcon_array_fetch_string(&extra_conditions, foreign_key, SL("conditions"), PH_NOISY_CC);
					phalcon_array_append(&conditions, extra_conditions, PH_SEPARATE TSRMLS_CC);
				}
	
				/** 
				 * We don't trust the actual values in the object and pass the values using bound
				 * parameters
				 */
				PHALCON_INIT_NVAR(join_conditions);
				phalcon_fast_join_str(join_conditions, SL(" AND "), conditions TSRMLS_CC);
	
				PHALCON_INIT_NVAR(parameters);
				array_init_size(parameters, 2);
				phalcon_array_append(&parameters, join_conditions, PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&parameters, SL("bind"), &bind_params, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
				/** 
				 * Let's make the checking
				 */
				PHALCON_INIT_NVAR(rowcount);
				PHALCON_CALL_METHOD_PARAMS_1(rowcount, referenced_model, "count", parameters);
				if (!zend_is_true(rowcount)) {
	
					/** 
					 * Get the user message or produce a new one
					 */
					if (phalcon_array_isset_string(foreign_key, SS("message"))) {
						PHALCON_OBS_NVAR(user_message);
						phalcon_array_fetch_string(&user_message, foreign_key, SL("message"), PH_NOISY_CC);
					} else {
						if (Z_TYPE_P(fields) == IS_ARRAY) { 
							PHALCON_INIT_NVAR(joined_fields);
							phalcon_fast_join_str(joined_fields, SL(", "), fields TSRMLS_CC);
	
							PHALCON_INIT_NVAR(user_message);
							PHALCON_CONCAT_SVS(user_message, "Value of fields \"", joined_fields, "\" does not exist on referenced table");
						} else {
							PHALCON_INIT_NVAR(user_message);
							PHALCON_CONCAT_SVS(user_message, "Value of field \"", fields, "\" does not exist on referenced table");
						}
					}
	
					/** 
					 * Create a message
					 */
					PHALCON_INIT_NVAR(type);
					ZVAL_STRING(type, "ConstraintViolation", 1);
	
					PHALCON_INIT_NVAR(message);
					object_init_ex(message, phalcon_mvc_model_message_ce);
					PHALCON_CALL_METHOD_PARAMS_3_NORETURN(message, "__construct", user_message, fields, type);
	
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "appendmessage", message);
					error = 1;
					break;
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		/** 
		 * Call 'onValidationFails' if the validation fails
		 */
		if (error) {
			if (PHALCON_GLOBAL(orm).events) {
				PHALCON_INIT_VAR(event_name);
				ZVAL_STRING(event_name, "onValidationFails", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "fireevent", event_name);
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation");
			}
			RETURN_MM_FALSE;
		}
	}
	
	RETURN_MM_TRUE;
}

/**
 * Reads both "hasMany" and "hasOne" relations and checks the virtual foreign keys when deleting records
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _checkForeignKeysReverse){

	zval *manager, *relations, *error = NULL, *relation = NULL, *foreign_key = NULL;
	zval *relation_class = NULL, *referenced_model = NULL, *fields = NULL;
	zval *referenced_fields = NULL, *conditions = NULL, *bind_params = NULL;
	zval *field = NULL, *position = NULL, *value = NULL, *referenced_field = NULL;
	zval *condition = NULL, *extra_conditions = NULL, *join_conditions = NULL;
	zval *parameters = NULL, *rowcount = NULL, *user_message = NULL, *type = NULL;
	zval *message = NULL, *event_name;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	/** 
	 * Get the models manager
	 */
	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
	/** 
	 * We check if some of the hasOne/hasMany relations is a foreign key
	 */
	PHALCON_INIT_VAR(relations);
	PHALCON_CALL_METHOD_PARAMS_1(relations, manager, "gethasoneandhasmany", this_ptr);
	if (phalcon_fast_count_ev(relations TSRMLS_CC)) {
	
		PHALCON_INIT_VAR(error);
		ZVAL_BOOL(error, 0);
	
		if (!phalcon_is_iterable(relations, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(relation);
	
			/** 
			 * Check if the relation has a virtual foreign key
			 */
			PHALCON_INIT_NVAR(foreign_key);
			PHALCON_CALL_METHOD(foreign_key, relation, "getforeignkey");
			if (PHALCON_IS_NOT_FALSE(foreign_key)) {
	
				PHALCON_INIT_NVAR(relation_class);
				PHALCON_CALL_METHOD(relation_class, relation, "getreferencedmodel");
	
				/** 
				 * Load a plain instance from the models manager
				 */
				PHALCON_INIT_NVAR(referenced_model);
				PHALCON_CALL_METHOD_PARAMS_1(referenced_model, manager, "load", relation_class);
	
				PHALCON_INIT_NVAR(fields);
				PHALCON_CALL_METHOD(fields, relation, "getfields");
	
				PHALCON_INIT_NVAR(referenced_fields);
				PHALCON_CALL_METHOD(referenced_fields, relation, "getreferencedfields");
	
				/** 
				 * Create the checking conditions. A relation can has many fields or a single one
				 */
				PHALCON_INIT_NVAR(conditions);
				array_init(conditions);
	
				PHALCON_INIT_NVAR(bind_params);
				array_init(bind_params);
				if (Z_TYPE_P(fields) == IS_ARRAY) { 
	
					if (!phalcon_is_iterable(fields, &ah1, &hp1, 0, 0 TSRMLS_CC)) {
						return;
					}
	
	
					while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
						PHALCON_GET_FOREACH_KEY(position, ah1, hp1);
						PHALCON_GET_FOREACH_VALUE(field);
	
						if (phalcon_isset_property_zval(this_ptr, field TSRMLS_CC)) {
							PHALCON_OBS_NVAR(value);
							phalcon_read_property_zval(&value, this_ptr, field, PH_NOISY_CC);
						} else {
							PHALCON_INIT_NVAR(value);
						}
	
						PHALCON_OBS_NVAR(referenced_field);
						phalcon_array_fetch(&referenced_field, referenced_fields, position, PH_NOISY_CC);
	
						PHALCON_INIT_NVAR(condition);
						PHALCON_CONCAT_VSV(condition, referenced_field, " = ?", position);
						phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
						phalcon_array_append(&bind_params, value, PH_SEPARATE TSRMLS_CC);
	
						zend_hash_move_forward_ex(ah1, &hp1);
					}
	
				} else {
					if (phalcon_isset_property_zval(this_ptr, fields TSRMLS_CC)) {
						PHALCON_OBS_NVAR(value);
						phalcon_read_property_zval(&value, this_ptr, fields, PH_NOISY_CC);
					} else {
						PHALCON_INIT_NVAR(value);
					}
	
					PHALCON_INIT_NVAR(condition);
					PHALCON_CONCAT_VS(condition, referenced_fields, " = ?0");
					phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&bind_params, value, PH_SEPARATE TSRMLS_CC);
				}
	
				/** 
				 * Check if the virtual foreign key has extra conditions
				 */
				if (phalcon_array_isset_string(foreign_key, SS("conditions"))) {
					PHALCON_OBS_NVAR(extra_conditions);
					phalcon_array_fetch_string(&extra_conditions, foreign_key, SL("conditions"), PH_NOISY_CC);
					phalcon_array_append(&conditions, extra_conditions, PH_SEPARATE TSRMLS_CC);
				}
	
				/** 
				 * We don't trust the actual values in the object and then we're passing the values
				 * using bound parameters
				 */
				PHALCON_INIT_NVAR(join_conditions);
				phalcon_fast_join_str(join_conditions, SL(" AND "), conditions TSRMLS_CC);
	
				PHALCON_INIT_NVAR(parameters);
				array_init_size(parameters, 2);
				phalcon_array_append(&parameters, join_conditions, PH_SEPARATE TSRMLS_CC);
				phalcon_array_update_string(&parameters, SL("bind"), &bind_params, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
				/** 
				 * Let's make the checking
				 */
				PHALCON_INIT_NVAR(rowcount);
				PHALCON_CALL_METHOD_PARAMS_1(rowcount, referenced_model, "count", parameters);
				if (zend_is_true(rowcount)) {
	
					/** 
					 * Create a new message
					 */
					if (phalcon_array_isset_string(foreign_key, SS("message"))) {
						PHALCON_OBS_NVAR(user_message);
						phalcon_array_fetch_string(&user_message, foreign_key, SL("message"), PH_NOISY_CC);
					} else {
						PHALCON_INIT_NVAR(user_message);
						PHALCON_CONCAT_SV(user_message, "Record is referenced by model ", relation_class);
					}
	
					/** 
					 * Create a message
					 */
					PHALCON_INIT_NVAR(type);
					ZVAL_STRING(type, "ConstraintViolation", 1);
	
					PHALCON_INIT_NVAR(message);
					object_init_ex(message, phalcon_mvc_model_message_ce);
					PHALCON_CALL_METHOD_PARAMS_3_NORETURN(message, "__construct", user_message, fields, type);
	
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "appendmessage", message);
	
					PHALCON_INIT_NVAR(error);
					ZVAL_BOOL(error, 1);
					break;
				}
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		/** 
		 * Call validation fails event
		 */
		if (PHALCON_IS_TRUE(error)) {
			if (PHALCON_GLOBAL(orm).events) {
				PHALCON_INIT_VAR(event_name);
				ZVAL_STRING(event_name, "onValidationFails", 1);
				PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "fireevent", event_name);
				PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation");
			}
			RETURN_MM_FALSE;
		}
	}
	
	RETURN_MM_TRUE;
}

/**
 * Executes internal hooks before save a record
 *
 * @param Phalcon\Mvc\Model\MetadataInterface $metaData
 * @param boolean $exists
 * @param string $identityField
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _preSave){

	zval *meta_data, *exists, *identity_field, *event_name = NULL;
	zval *status = NULL, *not_null, *data_type_numeric;
	zval *column_map = NULL, *automatic_attributes = NULL, *error = NULL;
	zval *null_value, *field = NULL, *is_null = NULL, *attribute_field = NULL;
	zval *exception_message = NULL, *value = NULL, *is_numeric = NULL;
	zval *is_identity_field = NULL, *message = NULL, *type = NULL, *model_message = NULL;
	zval *skipped;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &meta_data, &exists, &identity_field) == FAILURE) {
		RETURN_MM_NULL();
	}

	/** 
	 * Run Validation Callbacks Before
	 */
	if (PHALCON_GLOBAL(orm).events) {
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "beforeValidation", 1);
	
		/** 
		 * Call the beforeValidation
		 */
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	
		if (!zend_is_true(exists)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "beforeValidationOnCreate", 1);
		} else {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "beforeValidationOnUpdate", 1);
		}
	
		/** 
		 * Call the specific beforeValidation event for the current action
		 */
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Check for Virtual foreign keys
	 */
	if (PHALCON_GLOBAL(orm).virtual_foreign_keys) {
	
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD(status, this_ptr, "_checkforeignkeys");
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Columns marked as not null are automatically validated by the ORM
	 */
	if (PHALCON_GLOBAL(orm).not_null_validations) {
	
		PHALCON_INIT_VAR(not_null);
		PHALCON_CALL_METHOD_PARAMS_1(not_null, meta_data, "getnotnullattributes", this_ptr);
		if (Z_TYPE_P(not_null) == IS_ARRAY) { 
	
			/** 
			 * Gets the fields that are numeric, these are validated in a diferent way
			 */
			PHALCON_INIT_VAR(data_type_numeric);
			PHALCON_CALL_METHOD_PARAMS_1(data_type_numeric, meta_data, "getdatatypesnumeric", this_ptr);
			if (PHALCON_GLOBAL(orm).column_renaming) {
				PHALCON_INIT_VAR(column_map);
				PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getcolumnmap", this_ptr);
			} else {
				PHALCON_INIT_NVAR(column_map);
			}
	
			/** 
			 * Get fields that must be omitted from the SQL generation
			 */
			if (zend_is_true(exists)) {
				PHALCON_INIT_VAR(automatic_attributes);
				PHALCON_CALL_METHOD_PARAMS_1(automatic_attributes, meta_data, "getautomaticupdateattributes", this_ptr);
			} else {
				PHALCON_INIT_NVAR(automatic_attributes);
				PHALCON_CALL_METHOD_PARAMS_1(automatic_attributes, meta_data, "getautomaticcreateattributes", this_ptr);
			}
	
			PHALCON_INIT_VAR(error);
			ZVAL_BOOL(error, 0);
	
			PHALCON_INIT_VAR(null_value);
	
			if (!phalcon_is_iterable(not_null, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(field);
	
				/** 
				 * We don't check fields that must be omitted
				 */
				if (!phalcon_array_isset(automatic_attributes, field)) {
	
					PHALCON_INIT_NVAR(is_null);
					ZVAL_BOOL(is_null, 0);
					if (Z_TYPE_P(column_map) == IS_ARRAY) { 
						if (phalcon_array_isset(column_map, field)) {
							PHALCON_OBS_NVAR(attribute_field);
							phalcon_array_fetch(&attribute_field, column_map, field, PH_NOISY_CC);
						} else {
							PHALCON_INIT_NVAR(exception_message);
							PHALCON_CONCAT_SVS(exception_message, "Column '", field, "\" isn't part of the column map");
							PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
							return;
						}
					} else {
						PHALCON_CPY_WRT(attribute_field, field);
					}
	
					/** 
					 * Field is null when: 1) is not set, 2) is numeric but its value is not numeric,
					 * 3) is null or 4) is empty string
					 */
					if (phalcon_isset_property_zval(this_ptr, attribute_field TSRMLS_CC)) {
	
						PHALCON_OBS_NVAR(value);
						phalcon_read_property_zval(&value, this_ptr, attribute_field, PH_NOISY_CC);
						if (Z_TYPE_P(value) != IS_OBJECT) {
							if (!phalcon_array_isset(data_type_numeric, field)) {
								if (PHALCON_IS_EMPTY(value)) {
									PHALCON_INIT_NVAR(is_null);
									ZVAL_BOOL(is_null, 1);
								}
							} else {
								PHALCON_INIT_NVAR(is_numeric);
								PHALCON_CALL_FUNC_PARAMS_1(is_numeric, "is_numeric", value);
								if (PHALCON_IS_FALSE(is_numeric)) {
									PHALCON_INIT_NVAR(is_null);
									ZVAL_BOOL(is_null, 1);
								}
							}
						}
					} else {
						PHALCON_INIT_NVAR(is_null);
						ZVAL_BOOL(is_null, 1);
					}
	
					if (PHALCON_IS_TRUE(is_null)) {
						if (!zend_is_true(exists)) {
	
							/** 
							 * The identity field can be null
							 */
							PHALCON_INIT_NVAR(is_identity_field);
							is_equal_function(is_identity_field, field, identity_field TSRMLS_CC);
							if (PHALCON_IS_TRUE(is_identity_field)) {
								zend_hash_move_forward_ex(ah0, &hp0);
								continue;
							}
						}
	
						PHALCON_INIT_NVAR(message);
						PHALCON_CONCAT_VS(message, attribute_field, " is required");
	
						PHALCON_INIT_NVAR(type);
						ZVAL_STRING(type, "PresenceOf", 1);
	
						/** 
						 * A implicit PresenceOf message is created
						 */
						PHALCON_INIT_NVAR(model_message);
						object_init_ex(model_message, phalcon_mvc_model_message_ce);
						PHALCON_CALL_METHOD_PARAMS_3_NORETURN(model_message, "__construct", message, attribute_field, type);
	
						phalcon_update_property_array_append(this_ptr, SL("_errorMessages"), model_message TSRMLS_CC);
	
						PHALCON_INIT_NVAR(error);
						ZVAL_BOOL(error, 1);
					}
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			if (PHALCON_IS_TRUE(error)) {
				if (PHALCON_GLOBAL(orm).events) {
					PHALCON_INIT_NVAR(event_name);
					ZVAL_STRING(event_name, "onValidationFails", 1);
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "fireevent", event_name);
					PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation");
				}
				RETURN_MM_FALSE;
			}
		}
	}
	
	PHALCON_INIT_NVAR(event_name);
	ZVAL_STRING(event_name, "validation", 1);
	
	PHALCON_INIT_NVAR(status);
	PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
	if (PHALCON_IS_FALSE(status)) {
		if (PHALCON_GLOBAL(orm).events) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "onValidationFails", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "fireevent", event_name);
		}
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Run Validation
	 */
	if (PHALCON_GLOBAL(orm).events) {
		if (!zend_is_true(exists)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterValidationOnCreate", 1);
		} else {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterValidationOnUpdate", 1);
		}
	
		/** 
		 * Run Validation Callbacks After
		 */
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "afterValidation", 1);
	
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "beforeSave", 1);
	
		/** 
		 * Run Before Callbacks
		 */
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		}
	
		if (zend_is_true(exists)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "beforeUpdate", 1);
		} else {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "beforeCreate", 1);
		}
	
		phalcon_update_property_bool(this_ptr, SL("_skipped"), 0 TSRMLS_CC);
	
		/** 
		 * The operation can be skipped here
		 */
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		} else {
			/** 
			 * Always return true if the operation is skipped
			 */
			PHALCON_OBS_VAR(skipped);
			phalcon_read_property(&skipped, this_ptr, SL("_skipped"), PH_NOISY_CC);
			if (PHALCON_IS_TRUE(skipped)) {
				RETURN_MM_TRUE;
			}
		}
	}
	
	RETURN_MM_TRUE;
}

/**
 * Executes internal events after save a record
 *
 * @param boolean $success
 * @param boolean $exists
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _postSave){

	zval *success, *exists, *event_name = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &success, &exists) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (PHALCON_IS_TRUE(success)) {
		if (zend_is_true(exists)) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "afterUpdate", 1);
		} else {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterCreate", 1);
		}
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "fireevent", event_name);
	
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "afterSave", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "fireevent", event_name);
	
		RETURN_CCTOR(success);
	}
	
	PHALCON_INIT_NVAR(event_name);
	ZVAL_STRING(event_name, "notSave", 1);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "fireevent", event_name);
	PHALCON_CALL_METHOD_NORETURN(this_ptr, "_canceloperation");
	RETURN_MM_FALSE;
}

/**
 * Sends a pre-build INSERT SQL statement to the relational database system
 *
 * @param Phalcon\Mvc\Model\MetadataInterface $metaData
 * @param Phalcon\Db\AdapterInterface $connection
 * @param string $table
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowInsert){

	zval *meta_data, *connection, *table, *identity_field;
	zval *null_value, *bind_skip, *fields, *values;
	zval *bind_types, *attributes, *bind_data_types;
	zval *automatic_attributes, *column_map = NULL, *field = NULL;
	zval *attribute_field = NULL, *exception_message = NULL;
	zval *is_not_identity_field = NULL, *value = NULL, *bind_type = NULL;
	zval *default_value, *success, *sequence_name = NULL;
	zval *support_sequences, *source, *last_insert_id;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &meta_data, &connection, &table, &identity_field) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(null_value);
	
	PHALCON_INIT_VAR(bind_skip);
	ZVAL_LONG(bind_skip, 1024);
	
	PHALCON_INIT_VAR(fields);
	array_init(fields);
	
	PHALCON_INIT_VAR(values);
	array_init(values);
	
	PHALCON_INIT_VAR(bind_types);
	array_init(bind_types);
	
	PHALCON_INIT_VAR(attributes);
	PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", this_ptr);
	
	PHALCON_INIT_VAR(bind_data_types);
	PHALCON_CALL_METHOD_PARAMS_1(bind_data_types, meta_data, "getbindtypes", this_ptr);
	
	PHALCON_INIT_VAR(automatic_attributes);
	PHALCON_CALL_METHOD_PARAMS_1(automatic_attributes, meta_data, "getautomaticcreateattributes", this_ptr);
	if (PHALCON_GLOBAL(orm).column_renaming) {
		PHALCON_INIT_VAR(column_map);
		PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getcolumnmap", this_ptr);
	} else {
		PHALCON_INIT_NVAR(column_map);
	}
	
	/** 
	 * All fields in the model makes part or the INSERT
	 */
	
	if (!phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(field);
	
		if (!phalcon_array_isset(automatic_attributes, field)) {
	
			/** 
			 * Check if the model has a column map
			 */
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
				if (phalcon_array_isset(column_map, field)) {
					PHALCON_OBS_NVAR(attribute_field);
					phalcon_array_fetch(&attribute_field, column_map, field, PH_NOISY_CC);
				} else {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Column '", field, "\" isn't part of the column map");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
			} else {
				PHALCON_CPY_WRT(attribute_field, field);
			}
	
			/** 
			 * Check every attribute in the model except identity field
			 */
			PHALCON_INIT_NVAR(is_not_identity_field);
			is_not_equal_function(is_not_identity_field, field, identity_field TSRMLS_CC);
			if (PHALCON_IS_TRUE(is_not_identity_field)) {
				phalcon_array_append(&fields, field, PH_SEPARATE TSRMLS_CC);
				if (phalcon_isset_property_zval(this_ptr, attribute_field TSRMLS_CC)) {
					if (!phalcon_array_isset(bind_data_types, field)) {
						PHALCON_INIT_NVAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Column '", field, "\" isn't part of the table columns");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
	
					PHALCON_OBS_NVAR(value);
					phalcon_read_property_zval(&value, this_ptr, attribute_field, PH_NOISY_CC);
					phalcon_array_append(&values, value, PH_SEPARATE TSRMLS_CC);
	
					PHALCON_OBS_NVAR(bind_type);
					phalcon_array_fetch(&bind_type, bind_data_types, field, PH_NOISY_CC);
					phalcon_array_append(&bind_types, bind_type, PH_SEPARATE TSRMLS_CC);
				} else {
					phalcon_array_append(&values, null_value, PH_SEPARATE TSRMLS_CC);
					phalcon_array_append(&bind_types, bind_skip, PH_SEPARATE TSRMLS_CC);
				}
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * If there is an identity field we add it using "null" or "default"
	 */
	if (PHALCON_IS_NOT_FALSE(identity_field)) {
	
		PHALCON_INIT_VAR(default_value);
		PHALCON_CALL_METHOD(default_value, connection, "getdefaultidvalue");
		phalcon_array_append(&fields, identity_field, PH_SEPARATE TSRMLS_CC);
	
		/** 
		 * Check if the model has a column map
		 */
		if (Z_TYPE_P(column_map) == IS_ARRAY) { 
			if (phalcon_array_isset(column_map, identity_field)) {
				PHALCON_OBS_NVAR(attribute_field);
				phalcon_array_fetch(&attribute_field, column_map, identity_field, PH_NOISY_CC);
			} else {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column '", identity_field, "\" isn't part of the column map");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
		} else {
			PHALCON_CPY_WRT(attribute_field, identity_field);
		}
	
		if (phalcon_isset_property_zval(this_ptr, attribute_field TSRMLS_CC)) {
	
			PHALCON_OBS_NVAR(value);
			phalcon_read_property_zval(&value, this_ptr, attribute_field, PH_NOISY_CC);
			if (PHALCON_IS_EMPTY(value)) {
				phalcon_array_append(&values, default_value, PH_SEPARATE TSRMLS_CC);
				phalcon_array_append(&bind_data_types, bind_skip, PH_SEPARATE TSRMLS_CC);
			} else {
				/** 
				 * The field is valid we look for a bind value (normally int)
				 */
				if (!phalcon_array_isset(bind_data_types, identity_field)) {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Identity column '", identity_field, "\" isn't part of the table columns");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
				phalcon_array_append(&values, value, PH_SEPARATE TSRMLS_CC);
	
				PHALCON_OBS_NVAR(bind_type);
				phalcon_array_fetch(&bind_type, bind_data_types, identity_field, PH_NOISY_CC);
				phalcon_array_append(&bind_types, bind_type, PH_SEPARATE TSRMLS_CC);
			}
		} else {
			phalcon_array_append(&values, default_value, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&bind_types, bind_skip, PH_SEPARATE TSRMLS_CC);
		}
	}
	
	/** 
	 * The low level insert is performed
	 */
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_4(success, connection, "insert", table, values, fields, bind_types);
	if (PHALCON_IS_NOT_FALSE(identity_field)) {
	
		/** 
		 * We check if the model have sequences
		 */
		PHALCON_INIT_VAR(sequence_name);
	
		PHALCON_INIT_VAR(support_sequences);
		PHALCON_CALL_METHOD(support_sequences, connection, "supportsequences");
		if (PHALCON_IS_TRUE(support_sequences)) {
			if (phalcon_method_exists_ex(this_ptr, SS("getsequencename") TSRMLS_CC) == SUCCESS) {
				PHALCON_CALL_METHOD(sequence_name, this_ptr, "getsequencename");
			} else {
				PHALCON_INIT_VAR(source);
				PHALCON_CALL_METHOD(source, this_ptr, "getsource");
	
				PHALCON_INIT_NVAR(sequence_name);
				PHALCON_CONCAT_VSVS(sequence_name, source, "_", identity_field, "_seq");
			}
		}
	
		/** 
		 * Recover the last "insert id" and assign it to the object
		 */
		PHALCON_INIT_VAR(last_insert_id);
		PHALCON_CALL_METHOD_PARAMS_1(last_insert_id, connection, "lastinsertid", sequence_name);
		phalcon_update_property_zval_zval(this_ptr, attribute_field, last_insert_id TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(success);
}

/**
 * Sends a pre-build UPDATE SQL statement to the relational database system
 *
 * @param Phalcon\Mvc\Model\MetadataInterface $metaData
 * @param Phalcon\Db\AdapterInterface $connection
 * @param string|array $table
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, _doLowUpdate){

	zval *meta_data, *connection, *table, *null_value;
	zval *bind_skip, *fields, *values, *bind_types;
	zval *bind_data_types, *non_primary, *automatic_attributes;
	zval *column_map = NULL, *field = NULL, *exception_message = NULL;
	zval *attribute_field = NULL, *value = NULL, *bind_type = NULL, *unique_key;
	zval *unique_params, *unique_types, *conditions;
	zval *success;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &meta_data, &connection, &table) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(null_value);
	
	PHALCON_INIT_VAR(bind_skip);
	ZVAL_LONG(bind_skip, 1024);
	
	PHALCON_INIT_VAR(fields);
	array_init(fields);
	
	PHALCON_INIT_VAR(values);
	array_init(values);
	
	PHALCON_INIT_VAR(bind_types);
	array_init(bind_types);
	
	PHALCON_INIT_VAR(bind_data_types);
	PHALCON_CALL_METHOD_PARAMS_1(bind_data_types, meta_data, "getbindtypes", this_ptr);
	
	PHALCON_INIT_VAR(non_primary);
	PHALCON_CALL_METHOD_PARAMS_1(non_primary, meta_data, "getnonprimarykeyattributes", this_ptr);
	
	PHALCON_INIT_VAR(automatic_attributes);
	PHALCON_CALL_METHOD_PARAMS_1(automatic_attributes, meta_data, "getautomaticupdateattributes", this_ptr);
	if (PHALCON_GLOBAL(orm).column_renaming) {
		PHALCON_INIT_VAR(column_map);
		PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getcolumnmap", this_ptr);
	} else {
		PHALCON_INIT_NVAR(column_map);
	}
	
	/** 
	 * We only make the update based on the non-primary attributes, values in primary
	 * key attributes are ignored
	 */
	
	if (!phalcon_is_iterable(non_primary, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(field);
	
		if (!phalcon_array_isset(automatic_attributes, field)) {
	
			/** 
			 * Check a bind type for field to update
			 */
			if (!phalcon_array_isset(bind_data_types, field)) {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column '", field, "\" isn't part of the table columns");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
			phalcon_array_append(&fields, field, PH_SEPARATE TSRMLS_CC);
	
			/** 
			 * Check if the model has a column map
			 */
			if (Z_TYPE_P(column_map) == IS_ARRAY) { 
				if (phalcon_array_isset(column_map, field)) {
					PHALCON_OBS_NVAR(attribute_field);
					phalcon_array_fetch(&attribute_field, column_map, field, PH_NOISY_CC);
				} else {
					PHALCON_INIT_NVAR(exception_message);
					PHALCON_CONCAT_SVS(exception_message, "Column '", field, "\" isn't part of the column map");
					PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
					return;
				}
			} else {
				PHALCON_CPY_WRT(attribute_field, field);
			}
	
			if (phalcon_isset_property_zval(this_ptr, attribute_field TSRMLS_CC)) {
				PHALCON_OBS_NVAR(value);
				phalcon_read_property_zval(&value, this_ptr, attribute_field, PH_NOISY_CC);
				phalcon_array_append(&values, value, PH_SEPARATE TSRMLS_CC);
	
				PHALCON_OBS_NVAR(bind_type);
				phalcon_array_fetch(&bind_type, bind_data_types, field, PH_NOISY_CC);
				phalcon_array_append(&bind_types, bind_type, PH_SEPARATE TSRMLS_CC);
			} else {
				phalcon_array_append(&values, null_value, PH_SEPARATE TSRMLS_CC);
				phalcon_array_append(&bind_types, bind_skip, PH_SEPARATE TSRMLS_CC);
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_OBS_VAR(unique_key);
	phalcon_read_property(&unique_key, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(unique_params);
	phalcon_read_property(&unique_params, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(unique_types);
	phalcon_read_property(&unique_types, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC);
	
	/** 
	 * We build the conditions as an array
	 */
	PHALCON_INIT_VAR(conditions);
	array_init_size(conditions, 3);
	phalcon_array_update_string(&conditions, SL("conditions"), &unique_key, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&conditions, SL("bind"), &unique_params, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&conditions, SL("bindTypes"), &unique_types, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * Perform the low level update
	 */
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_5(success, connection, "update", table, fields, values, conditions, bind_types);
	
	RETURN_CCTOR(success);
}

/**
 * Inserts or updates a model instance. Returning true on success or false otherwise.
 *
 *<code>
 *	//Creating a new robot
 *	$robot = new Robots();
 *	$robot->type = 'mechanical'
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
 * @param array $data
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, save){

	zval *data = NULL, *meta_data, *attributes, *attribute = NULL;
	zval *value = NULL, *possible_setter = NULL, *schema, *source;
	zval *table = NULL, *connection, *exists, *empty_array;
	zval *identity_field, *status, *success = NULL, *post_success;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &data) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!data) {
		PHALCON_INIT_VAR(data);
	}
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD(meta_data, this_ptr, "getmodelsmetadata");
	
	/** 
	 * Assign the values passed
	 */
	if (Z_TYPE_P(data) != IS_NULL) {
		if (Z_TYPE_P(data) == IS_ARRAY) { 
	
			PHALCON_INIT_VAR(attributes);
			PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", this_ptr);
	
			if (!phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(attribute);
	
				if (phalcon_array_isset(data, attribute)) {
	
					/** 
					 * We check if the field has a setter
					 */
					PHALCON_OBS_NVAR(value);
					phalcon_array_fetch(&value, data, attribute, PH_NOISY_CC);
	
					PHALCON_INIT_NVAR(possible_setter);
					PHALCON_CONCAT_SV(possible_setter, "set", attribute);
					if (phalcon_method_exists(this_ptr, possible_setter TSRMLS_CC) == SUCCESS) {
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, Z_STRVAL_P(possible_setter), value);
					} else {
						/** 
						 * Otherwise we assign the attribute directly
						 */
						phalcon_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
					}
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data passed to save() must be an array");
			return;
		}
	}
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, this_ptr, "getschema");
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD(source, this_ptr, "getsource");
	if (zend_is_true(schema)) {
		PHALCON_INIT_VAR(table);
		array_init_size(table, 2);
		phalcon_array_append(&table, schema, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&table, source, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(table, source);
	}
	
	/** 
	 * We need to check if the record exists
	 */
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, this_ptr, "getconnection");
	
	PHALCON_INIT_VAR(exists);
	PHALCON_CALL_METHOD_PARAMS_3(exists, this_ptr, "_exists", meta_data, connection, table);
	if (zend_is_true(exists)) {
		phalcon_update_property_long(this_ptr, SL("_operationMade"), 2 TSRMLS_CC);
	} else {
		phalcon_update_property_long(this_ptr, SL("_operationMade"), 1 TSRMLS_CC);
	}
	
	/** 
	 * Clean the messages
	 */
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	phalcon_update_property_zval(this_ptr, SL("_errorMessages"), empty_array TSRMLS_CC);
	
	/** 
	 * Query the identity field
	 */
	PHALCON_INIT_VAR(identity_field);
	PHALCON_CALL_METHOD_PARAMS_1(identity_field, meta_data, "getidentityfield", this_ptr);
	
	/** 
	 * _preSave() makes all the validations
	 */
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD_PARAMS_3(status, this_ptr, "_presave", meta_data, exists, identity_field);
	if (PHALCON_IS_FALSE(status)) {
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Depending if the record exists we do a an update or an insert operation
	 */
	if (zend_is_true(exists)) {
		PHALCON_INIT_VAR(success);
		PHALCON_CALL_METHOD_PARAMS_3(success, this_ptr, "_dolowupdate", meta_data, connection, table);
	} else {
		PHALCON_INIT_NVAR(success);
		PHALCON_CALL_METHOD_PARAMS_4(success, this_ptr, "_dolowinsert", meta_data, connection, table, identity_field);
	}
	
	/** 
	 * _postSave() makes all the validations
	 */
	if (PHALCON_GLOBAL(orm).events) {
		PHALCON_INIT_VAR(post_success);
		PHALCON_CALL_METHOD_PARAMS_2(post_success, this_ptr, "_postsave", success, exists);
		RETURN_CCTOR(post_success);
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
 *	$robot->type = 'mechanical'
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
 * @param array $data
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, create){

	zval *data = NULL, *meta_data, *column_map = NULL, *attributes;
	zval *attribute = NULL, *attribute_field = NULL, *exception_message = NULL;
	zval *value = NULL, *possible_setter = NULL, *connection, *exists;
	zval *field, *type, *message, *model_message, *messages;
	zval *success;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &data) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!data) {
		PHALCON_INIT_VAR(data);
	}
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD(meta_data, this_ptr, "getmodelsmetadata");
	
	/** 
	 * Assign the values passed
	 */
	if (Z_TYPE_P(data) != IS_NULL) {
		if (Z_TYPE_P(data) == IS_ARRAY) { 
			if (PHALCON_GLOBAL(orm).column_renaming) {
				PHALCON_INIT_VAR(column_map);
				PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getcolumnmap", this_ptr);
			} else {
				PHALCON_INIT_NVAR(column_map);
			}
	
			PHALCON_INIT_VAR(attributes);
			PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", this_ptr);
	
			if (!phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(attribute);
	
				/** 
				 * Check if we need to rename the field
				 */
				if (Z_TYPE_P(column_map) == IS_ARRAY) { 
					if (phalcon_array_isset(column_map, attribute)) {
						PHALCON_OBS_NVAR(attribute_field);
						phalcon_array_fetch(&attribute_field, column_map, attribute, PH_NOISY_CC);
					} else {
						PHALCON_INIT_NVAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Column '", attribute, "\" isn't part of the column map");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
				} else {
					PHALCON_CPY_WRT(attribute_field, attribute);
				}
	
				/** 
				 * Check if we there is data for the field
				 */
				if (phalcon_array_isset(data, attribute_field)) {
	
					PHALCON_OBS_NVAR(value);
					phalcon_array_fetch(&value, data, attribute_field, PH_NOISY_CC);
	
					PHALCON_INIT_NVAR(possible_setter);
					PHALCON_CONCAT_SV(possible_setter, "set", attribute_field);
					if (phalcon_method_exists(this_ptr, possible_setter TSRMLS_CC) == SUCCESS) {
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, Z_STRVAL_P(possible_setter), value);
					} else {
						phalcon_update_property_zval_zval(this_ptr, attribute_field, value TSRMLS_CC);
					}
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data passed to create() must be an array");
			return;
		}
	}
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, this_ptr, "getconnection");
	
	PHALCON_INIT_VAR(exists);
	PHALCON_CALL_METHOD_PARAMS_2(exists, this_ptr, "_exists", meta_data, connection);
	
	/** 
	 * If the record already exists we must throw an exception
	 */
	if (zend_is_true(exists)) {
		PHALCON_INIT_VAR(field);
	
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "InvalidCreateAttempt", 1);
	
		PHALCON_INIT_VAR(message);
		ZVAL_STRING(message, "Record cannot be created because it already exists", 1);
	
		PHALCON_INIT_VAR(model_message);
		object_init_ex(model_message, phalcon_mvc_model_message_ce);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(model_message, "__construct", message, field, type);
	
		PHALCON_INIT_VAR(messages);
		array_init_size(messages, 1);
		phalcon_array_append(&messages, model_message, PH_SEPARATE TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_errorMessages"), messages TSRMLS_CC);
		RETURN_MM_FALSE;
	}
	
	/** 
	 * Using save() anyways
	 */
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD(success, this_ptr, "save");
	
	RETURN_CCTOR(success);
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
 * @param array $data
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, update){

	zval *data = NULL, *meta_data = NULL, *column_map = NULL, *attributes;
	zval *attribute = NULL, *attribute_field = NULL, *exception_message = NULL;
	zval *value = NULL, *possible_setter = NULL, *force_exists;
	zval *connection, *exists, *field, *type, *message;
	zval *model_message, *messages, *success;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &data) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!data) {
		PHALCON_INIT_VAR(data);
	}
	
	PHALCON_INIT_VAR(meta_data);
	
	/** 
	 * Assign the values bassed on the passed
	 */
	if (Z_TYPE_P(data) != IS_NULL) {
		if (Z_TYPE_P(data) == IS_ARRAY) { 
	
			PHALCON_CALL_METHOD(meta_data, this_ptr, "getmodelsmetadata");
			if (PHALCON_GLOBAL(orm).column_renaming) {
				PHALCON_INIT_VAR(column_map);
				PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getcolumnmap", this_ptr);
			} else {
				PHALCON_INIT_NVAR(column_map);
			}
	
			PHALCON_INIT_VAR(attributes);
			PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", this_ptr);
	
			if (!phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(attribute);
	
				/** 
				 * Check if we need to rename the field
				 */
				if (Z_TYPE_P(column_map) == IS_ARRAY) { 
					if (phalcon_array_isset(column_map, attribute)) {
						PHALCON_OBS_NVAR(attribute_field);
						phalcon_array_fetch(&attribute_field, column_map, attribute, PH_NOISY_CC);
					} else {
						PHALCON_INIT_NVAR(exception_message);
						PHALCON_CONCAT_SVS(exception_message, "Column '", attribute, "\" isn't part of the column map");
						PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
						return;
					}
				} else {
					PHALCON_CPY_WRT(attribute_field, attribute);
				}
	
				/** 
				 * Check if we there is data for the field
				 */
				if (phalcon_array_isset(data, attribute_field)) {
	
					PHALCON_OBS_NVAR(value);
					phalcon_array_fetch(&value, data, attribute_field, PH_NOISY_CC);
	
					PHALCON_INIT_NVAR(possible_setter);
					PHALCON_CONCAT_SV(possible_setter, "set", attribute_field);
					if (phalcon_method_exists(this_ptr, possible_setter TSRMLS_CC) == SUCCESS) {
						PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, Z_STRVAL_P(possible_setter), value);
					} else {
						phalcon_update_property_zval_zval(this_ptr, attribute_field, value TSRMLS_CC);
					}
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Data passed to update() must be an array");
			return;
		}
	}
	
	/** 
	 * We don't check if the record exists if the record is already checked
	 */
	PHALCON_OBS_VAR(force_exists);
	phalcon_read_property(&force_exists, this_ptr, SL("_forceExists"), PH_NOISY_CC);
	if (!zend_is_true(force_exists)) {
		if (Z_TYPE_P(meta_data) == IS_NULL) {
			PHALCON_INIT_NVAR(meta_data);
			PHALCON_CALL_METHOD(meta_data, this_ptr, "getmodelsmetadata");
		}
	
		PHALCON_INIT_VAR(connection);
		PHALCON_CALL_METHOD(connection, this_ptr, "getconnection");
	
		PHALCON_INIT_VAR(exists);
		PHALCON_CALL_METHOD_PARAMS_2(exists, this_ptr, "_exists", meta_data, connection);
		if (!zend_is_true(exists)) {
			PHALCON_INIT_VAR(field);
	
			PHALCON_INIT_VAR(type);
			ZVAL_STRING(type, "InvalidUpdateAttempt", 1);
	
			PHALCON_INIT_VAR(message);
			ZVAL_STRING(message, "Record cannot be updated because it does not exist", 1);
	
			PHALCON_INIT_VAR(model_message);
			object_init_ex(model_message, phalcon_mvc_model_message_ce);
			PHALCON_CALL_METHOD_PARAMS_3_NORETURN(model_message, "__construct", message, field, type);
	
			PHALCON_INIT_VAR(messages);
			array_init_size(messages, 1);
			phalcon_array_append(&messages, model_message, PH_SEPARATE TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, SL("_errorMessages"), messages TSRMLS_CC);
			RETURN_MM_FALSE;
		}
	}
	
	/** 
	 * Call save() anyways
	 */
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD(success, this_ptr, "save");
	
	RETURN_CCTOR(success);
}

/**
 * Deletes a model instance. Returning true on success or false otherwise.
 *
 * <code>
 *$robot = Robots::findFirst("id=100");
 *$robot->delete();
 *
 *foreach(Robots::find("type = 'mechanical'") as $robot){
 *   $robot->delete();
 *}
 * </code>
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model, delete){

	zval *meta_data, *connection, *empty_array, *check_foreign_keys;
	zval *values, *bind_types, *conditions, *primary_keys;
	zval *bind_data_types, *column_map = NULL, *primary_key = NULL;
	zval *exception_message = NULL, *attribute_field = NULL;
	zval *value = NULL, *escaped_field = NULL, *primary_condition = NULL;
	zval *bind_type = NULL, *delete_conditions, *event_name = NULL;
	zval *status, *skipped, *schema, *source, *table = NULL, *success;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD(meta_data, this_ptr, "getmodelsmetadata");
	
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD(connection, this_ptr, "getconnection");
	
	/** 
	 * Operation made is OP_DELETE
	 */
	phalcon_update_property_long(this_ptr, SL("_operationMade"), 3 TSRMLS_CC);
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	phalcon_update_property_zval(this_ptr, SL("_errorMessages"), empty_array TSRMLS_CC);
	
	/** 
	 * Check if deleting the record violates a virtual foreign key
	 */
	if (PHALCON_GLOBAL(orm).virtual_foreign_keys) {
	
		PHALCON_INIT_VAR(check_foreign_keys);
		PHALCON_CALL_METHOD(check_foreign_keys, this_ptr, "_checkforeignkeysreverse");
		if (PHALCON_IS_FALSE(check_foreign_keys)) {
			RETURN_MM_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(values);
	array_init(values);
	
	PHALCON_INIT_VAR(bind_types);
	array_init(bind_types);
	
	PHALCON_INIT_VAR(conditions);
	array_init(conditions);
	
	PHALCON_INIT_VAR(primary_keys);
	PHALCON_CALL_METHOD_PARAMS_1(primary_keys, meta_data, "getprimarykeyattributes", this_ptr);
	
	PHALCON_INIT_VAR(bind_data_types);
	PHALCON_CALL_METHOD_PARAMS_1(bind_data_types, meta_data, "getbindtypes", this_ptr);
	if (PHALCON_GLOBAL(orm).column_renaming) {
		PHALCON_INIT_VAR(column_map);
		PHALCON_CALL_METHOD_PARAMS_1(column_map, meta_data, "getcolumnmap", this_ptr);
	} else {
		PHALCON_INIT_NVAR(column_map);
	}
	
	/** 
	 * Create a condition from the primary keys
	 */
	
	if (!phalcon_is_iterable(primary_keys, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(primary_key);
	
		/** 
		 * Every column part of the primary key must be in the bind data types
		 */
		if (!phalcon_array_isset(bind_data_types, primary_key)) {
			PHALCON_INIT_NVAR(exception_message);
			PHALCON_CONCAT_SVS(exception_message, "Column '", primary_key, "\" isn't part of the table columns");
			PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
			return;
		}
	
		/** 
		 * Take the column values based on the column map if any
		 */
		if (Z_TYPE_P(column_map) == IS_ARRAY) { 
			if (phalcon_array_isset(column_map, primary_key)) {
				PHALCON_OBS_NVAR(attribute_field);
				phalcon_array_fetch(&attribute_field, column_map, primary_key, PH_NOISY_CC);
			} else {
				PHALCON_INIT_NVAR(exception_message);
				PHALCON_CONCAT_SVS(exception_message, "Column '", primary_key, "\" isn't part of the column map");
				PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
				return;
			}
		} else {
			PHALCON_CPY_WRT(attribute_field, primary_key);
		}
	
		/** 
		 * If the attribute is currently set in the object add it to the conditions
		 */
		if (phalcon_isset_property_zval(this_ptr, attribute_field TSRMLS_CC)) {
			PHALCON_OBS_NVAR(value);
			phalcon_read_property_zval(&value, this_ptr, attribute_field, PH_NOISY_CC);
			phalcon_array_append(&values, value, PH_SEPARATE TSRMLS_CC);
	
			/** 
			 * Escape the column identifier
			 */
			PHALCON_INIT_NVAR(escaped_field);
			PHALCON_CALL_METHOD_PARAMS_1(escaped_field, connection, "escapeidentifier", primary_key);
	
			PHALCON_INIT_NVAR(primary_condition);
			PHALCON_CONCAT_VS(primary_condition, escaped_field, " = ?");
			phalcon_array_append(&conditions, primary_condition, PH_SEPARATE TSRMLS_CC);
	
			PHALCON_OBS_NVAR(bind_type);
			phalcon_array_fetch(&bind_type, bind_data_types, primary_key, PH_NOISY_CC);
			phalcon_array_append(&bind_types, bind_type, PH_SEPARATE TSRMLS_CC);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Cannot delete the record because one of the primary key attributes isn't set");
			return;
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Join the conditions in the array using an AND operator
	 */
	PHALCON_INIT_VAR(delete_conditions);
	phalcon_fast_join_str(delete_conditions, SL(" AND "), conditions TSRMLS_CC);
	if (PHALCON_GLOBAL(orm).events) {
		phalcon_update_property_bool(this_ptr, SL("_skipped"), 0 TSRMLS_CC);
	
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "beforeDelete", 1);
	
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_1(status, this_ptr, "fireeventcancel", event_name);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_FALSE;
		} else {
			/** 
			 * The operation can be skipped
			 */
			PHALCON_OBS_VAR(skipped);
			phalcon_read_property(&skipped, this_ptr, SL("_skipped"), PH_NOISY_CC);
			if (PHALCON_IS_TRUE(skipped)) {
				RETURN_MM_TRUE;
			}
		}
	}
	
	PHALCON_INIT_VAR(schema);
	PHALCON_CALL_METHOD(schema, this_ptr, "getschema");
	
	PHALCON_INIT_VAR(source);
	PHALCON_CALL_METHOD(source, this_ptr, "getsource");
	if (zend_is_true(schema)) {
		PHALCON_INIT_VAR(table);
		array_init_size(table, 2);
		phalcon_array_append(&table, schema, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&table, source, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_CPY_WRT(table, source);
	}
	
	/** 
	 * Do the deletion
	 */
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_4(success, connection, "delete", table, delete_conditions, values, bind_types);
	if (PHALCON_GLOBAL(orm).events) {
		if (zend_is_true(success)) {
			PHALCON_INIT_NVAR(event_name);
			ZVAL_STRING(event_name, "afterDelete", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "fireevent", event_name);
		}
	}
	
	/** 
	 * Force perform the record existence checking again
	 */
	phalcon_update_property_bool(this_ptr, SL("_forceExists"), 1 TSRMLS_CC);
	
	RETURN_CCTOR(success);
}

/**
 * Returns the type of the latest operation performed by the ORM
 * Returns one of the OP_* class constants
 *
 * @return int
 */
PHP_METHOD(Phalcon_Mvc_Model, getOperationMade){


	RETURN_MEMBER(this_ptr, "_operationMade");
}

/**
 * Skips the current operation forcing a success state
 *
 * @param boolean $skip
 */
PHP_METHOD(Phalcon_Mvc_Model, skipOperation){

	zval *skip;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &skip) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_skipped"), skip TSRMLS_CC);
	
}

/**
 * Reads an attribute value by its name
 *
 * <code>
 * echo $robot->readAttribute('name');
 * </code>
 *
 * @param string $attribute
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, readAttribute){

	zval *attribute, *attribute_value;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &attribute) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (phalcon_isset_property_zval(this_ptr, attribute TSRMLS_CC)) {
		PHALCON_OBS_VAR(attribute_value);
		phalcon_read_property_zval(&attribute_value, this_ptr, attribute, PH_NOISY_CC);
		RETURN_CCTOR(attribute_value);
	}
	RETURN_MM_NULL();
}

/**
 * Writes an attribute value by its name
 *
 * <code>
 * $robot->writeAttribute('name', 'Rosey');
 * </code>
 *
 * @param string $attribute
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Mvc_Model, writeAttribute){

	zval *attribute, *value;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &attribute, &value) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval_zval(this_ptr, attribute, value TSRMLS_CC);
	
}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT/UPDATE statement
 *
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->skipAttributes(array('price'));
 *   }
 *
 *}
 *</code>
 *
 * @param array $attributes
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributes){

	zval *attributes, *null_value, *keys_attributes;
	zval *attribute = NULL, *meta_data;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &attributes) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(attributes) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Attributes must be an array");
		return;
	}
	
	PHALCON_INIT_VAR(null_value);
	
	PHALCON_INIT_VAR(keys_attributes);
	array_init(keys_attributes);
	
	if (!phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(attribute);
	
		phalcon_array_update_zval(&keys_attributes, attribute, &null_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD(meta_data, this_ptr, "getmodelsmetadata");
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(meta_data, "setautomaticcreateattributes", this_ptr, keys_attributes);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(meta_data, "setautomaticupdateattributes", this_ptr, keys_attributes);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a list of attributes that must be skipped from the
 * generated INSERT statement
 *
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->skipAttributesOnUpdate(array('created_at'));
 *   }
 *
 *}
 *</code>
 *
 * @param array $attributes
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnCreate){

	zval *attributes, *null_value, *keys_attributes;
	zval *attribute = NULL, *meta_data;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &attributes) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(attributes) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Attributes must be an array");
		return;
	}
	
	PHALCON_INIT_VAR(null_value);
	
	PHALCON_INIT_VAR(keys_attributes);
	array_init(keys_attributes);
	
	if (!phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(attribute);
	
		phalcon_array_update_zval(&keys_attributes, attribute, &null_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD(meta_data, this_ptr, "getmodelsmetadata");
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(meta_data, "setautomaticcreateattributes", this_ptr, keys_attributes);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets a list of attributes that must be skipped from the
 * generated UPDATE statement
 *
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->skipAttributesOnUpdate(array('modified_in'));
 *   }
 *
 *}
 *</code>
 *
 * @param array $attributes
 */
PHP_METHOD(Phalcon_Mvc_Model, skipAttributesOnUpdate){

	zval *attributes, *null_value, *keys_attributes;
	zval *attribute = NULL, *meta_data;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &attributes) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(attributes) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Attributes must be an array");
		return;
	}
	
	PHALCON_INIT_VAR(null_value);
	
	PHALCON_INIT_VAR(keys_attributes);
	array_init(keys_attributes);
	
	if (!phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(attribute);
	
		phalcon_array_update_zval(&keys_attributes, attribute, &null_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD(meta_data, this_ptr, "getmodelsmetadata");
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(meta_data, "setautomaticupdateattributes", this_ptr, keys_attributes);
	
	PHALCON_MM_RESTORE();
}

/**
 * Setup a 1-1 relation between two models
 *
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->hasOne('id', 'RobotsDescription', 'robots_id');
 *   }
 *
 *}
 *</code>
 *
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param   array $options
 */
PHP_METHOD(Phalcon_Mvc_Model, hasOne){

	zval *fields, *reference_model, *referenced_fields;
	zval *options = NULL, *manager;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_5_NORETURN(manager, "addhasone", this_ptr, fields, reference_model, referenced_fields, options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Setup a relation reverse 1-1  between two models
 *
 *<code>
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
 *
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param   array $options
 */
PHP_METHOD(Phalcon_Mvc_Model, belongsTo){

	zval *fields, *reference_model, *referenced_fields;
	zval *options = NULL, *manager;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_5_NORETURN(manager, "addbelongsto", this_ptr, fields, reference_model, referenced_fields, options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Setup a relation 1-n between two models
 *
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       $this->hasMany('id', 'RobotsParts', 'robots_id');
 *   }
 *
 *}
 *</code>
 *
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param   array $options
 */
PHP_METHOD(Phalcon_Mvc_Model, hasMany){

	zval *fields, *reference_model, *referenced_fields;
	zval *options = NULL, *manager;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_5_NORETURN(manager, "addhasmany", this_ptr, fields, reference_model, referenced_fields, options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Setup a relation n-n between two models through an intermediate relation
 *
 *<code>
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *       //A reference relation must be set
 *       $this->hasMany('id', 'RobotsParts', 'robots_id');
 *
 *       //Setup a many-to-many relation to Parts through RobotsParts
 *       $this->hasManyThrough('Parts', 'RobotsParts');
 *   }
 *
 *}
 *</code>
 *
 * @param string $referenceModel
 * @param string $throughRelation
 * @param   array $options
 */
PHP_METHOD(Phalcon_Mvc_Model, hasManyThrough){

	zval *reference_model, *through_relation;
	zval *options = NULL, *manager;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &reference_model, &through_relation, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_3_NORETURN(manager, "addhasmanythrough", this_ptr, reference_model, options);
	
	PHALCON_MM_RESTORE();
}

/**
 * Setups a behavior in a model
 *
 *<code>
 *
 *use Phalcon\Mvc\Model\Behaviors\Timestampable;
 *
 *class Robots extends \Phalcon\Mvc\Model
 *{
 *
 *   public function initialize()
 *   {
 *		$this->addBehavior(new Timestampable(
 *			'onCreate' => array(
 *				'field' => 'created_at',
 *				'format' => 'Y-m-d'
 *			)
 *		));
 *   }
 *
 *}
 *</code>
 *
 * @param Phalcon\Mvc\Model\BehaviorInterface $behavior
 */
PHP_METHOD(Phalcon_Mvc_Model, addBehavior){

	zval *behavior, *manager;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &behavior) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(manager, "addbehavior", this_ptr, behavior);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns related records based on defined relations
 *
 * @param string $alias
 * @param array $arguments
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model, getRelated){

	zval *alias, *arguments = NULL, *manager, *class_name;
	zval *relation, *exception_message, *call_object;
	zval *model_args, *result;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &alias, &arguments) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!arguments) {
		PHALCON_INIT_VAR(arguments);
	}
	
	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, this_ptr, 0 TSRMLS_CC);
	
	/** 
	 * Query the relation by alias
	 */
	PHALCON_INIT_VAR(relation);
	PHALCON_CALL_METHOD_PARAMS_2(relation, manager, "getrelationbyalias", class_name, alias);
	if (Z_TYPE_P(relation) != IS_OBJECT) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVSVS(exception_message, "There is no defined relations for the model '", class_name, "\" with alias \"", alias, "'");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
		return;
	}
	
	/** 
	 * Call the 'getRelationRecords' in the models manager
	 */
	PHALCON_INIT_VAR(call_object);
	array_init_size(call_object, 2);
	phalcon_array_append(&call_object, manager, PH_SEPARATE TSRMLS_CC);
	add_next_index_stringl(call_object, SL("getRelationRecords"), 1);
	
	PHALCON_INIT_VAR(model_args);
	array_init_size(model_args, 4);
	phalcon_array_append(&model_args, relation, PH_SEPARATE TSRMLS_CC);
	add_next_index_null(model_args);
	phalcon_array_append(&model_args, this_ptr, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&model_args, arguments, PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_USER_FUNC_ARRAY(result, call_object, model_args);
	
	RETURN_CCTOR(result);
}

/**
 * Returns related records defined relations depending on the method name
 *
 * @param string $modelName
 * @param string $method
 * @param array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, _getRelatedRecords){

	zval *model_name, *method, *arguments, *manager;
	zval *relation = NULL, *query_method = NULL, *alias = NULL, *extra_args = NULL;
	zval *call_args, *call_object, *result;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &model_name, &method, &arguments) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(manager);
	phalcon_read_property(&manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(relation);
	ZVAL_BOOL(relation, 0);
	
	PHALCON_INIT_VAR(query_method);
	
	/** 
	 * Calling find/findFirst if the method starts with "get"
	 */
	if (phalcon_start_with_str(method, SL("get"))) {
		PHALCON_INIT_VAR(alias);
		phalcon_substr(alias, method, 3, 0 TSRMLS_CC);
	
		PHALCON_CALL_METHOD_PARAMS_2(relation, manager, "getrelationbyalias", model_name, alias);
	}
	
	/** 
	 * Calling count if the method starts with "count"
	 */
	if (Z_TYPE_P(relation) != IS_OBJECT) {
		if (phalcon_start_with_str(method, SL("count"))) {
			ZVAL_STRING(query_method, "count", 1);
	
			PHALCON_INIT_NVAR(alias);
			phalcon_substr(alias, method, 5, 0 TSRMLS_CC);
	
			PHALCON_INIT_NVAR(relation);
			PHALCON_CALL_METHOD_PARAMS_2(relation, manager, "getrelationbyalias", model_name, alias);
		}
	}
	
	/** 
	 * If the relation was found perform the query via the models manager
	 */
	if (Z_TYPE_P(relation) == IS_OBJECT) {
		if (phalcon_array_isset_long(arguments, 0)) {
			PHALCON_OBS_VAR(extra_args);
			phalcon_array_fetch_long(&extra_args, arguments, 0, PH_NOISY_CC);
		} else {
			PHALCON_INIT_NVAR(extra_args);
		}
	
		PHALCON_INIT_VAR(call_args);
		array_init_size(call_args, 4);
		phalcon_array_append(&call_args, relation, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&call_args, query_method, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&call_args, this_ptr, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&call_args, extra_args, PH_SEPARATE TSRMLS_CC);
	
		PHALCON_INIT_VAR(call_object);
		array_init_size(call_object, 2);
		phalcon_array_append(&call_object, manager, PH_SEPARATE TSRMLS_CC);
		add_next_index_stringl(call_object, SL("getRelationRecords"), 1);
	
		PHALCON_INIT_VAR(result);
		PHALCON_CALL_USER_FUNC_ARRAY(result, call_object, call_args);
	
		RETURN_CCTOR(result);
	}
	
	RETURN_MM_NULL();
}

/**
 * Handles methods when a method does not exist
 *
 * @param string $method
 * @param array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Model, __call){

	zval *method, *arguments = NULL, *model_name, *records;
	zval *models_manager, *status, *exception_message;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &method, &arguments) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!arguments) {
		PHALCON_INIT_VAR(arguments);
		array_init(arguments);
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, this_ptr, 0 TSRMLS_CC);
	
	/** 
	 * Check if there is a default action using the magic getter
	 */
	PHALCON_INIT_VAR(records);
	PHALCON_CALL_METHOD_PARAMS_3(records, this_ptr, "_getrelatedrecords", model_name, method, arguments);
	if (Z_TYPE_P(records) != IS_NULL) {
		RETURN_CCTOR(records);
	}
	
	PHALCON_OBS_VAR(models_manager);
	phalcon_read_property(&models_manager, this_ptr, SL("_modelsManager"), PH_NOISY_CC);
	
	/** 
	 * Try to find a replacement for the missing method in a behavior/listener
	 */
	PHALCON_INIT_VAR(status);
	PHALCON_CALL_METHOD_PARAMS_3(status, models_manager, "missingmethod", this_ptr, method, arguments);
	if (Z_TYPE_P(status) != IS_NULL) {
		RETURN_CCTOR(status);
	}
	
	/** 
	 * The method doesn't exist throw an exception
	 */
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SVSVS(exception_message, "The method \"", method, "\" doesn't exist on model \"", model_name, "\"");
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
	return;
}

/**
 * Serializes the object ignoring connections or static properties
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Model, serialize){

	zval *meta_data, *attributes, *null_value, *data;
	zval *attribute = NULL, *value = NULL, *serialize;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD(meta_data, this_ptr, "getmodelsmetadata");
	
	/** 
	 * We get the model's attributes to only serialize them
	 */
	PHALCON_INIT_VAR(attributes);
	PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", this_ptr);
	
	PHALCON_INIT_VAR(null_value);
	
	PHALCON_INIT_VAR(data);
	array_init(data);
	
	if (!phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(attribute);
	
		if (phalcon_isset_property_zval(this_ptr, attribute TSRMLS_CC)) {
			PHALCON_OBS_NVAR(value);
			phalcon_read_property_zval(&value, this_ptr, attribute, PH_NOISY_CC);
			phalcon_array_update_zval(&data, attribute, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&data, attribute, &null_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	/** 
	 * Use the standard serialize function to serialize the array data
	 */
	PHALCON_INIT_VAR(serialize);
	PHALCON_CALL_FUNC_PARAMS_1(serialize, "serialize", data);
	
	RETURN_CCTOR(serialize);
}

/**
 * Unserializes the object from a serialized string
 *
 * @param string $data
 */
PHP_METHOD(Phalcon_Mvc_Model, unserialize){

	zval *data, *attributes, *dependency_injector;
	zval *service, *manager, *value = NULL, *key = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(data) == IS_STRING) {
	
		PHALCON_INIT_VAR(attributes);
		PHALCON_CALL_FUNC_PARAMS_1(attributes, "unserialize", data);
		if (Z_TYPE_P(attributes) == IS_ARRAY) { 
	
			/** 
			 * Obtain the default DI
			 */
			PHALCON_INIT_VAR(dependency_injector);
			PHALCON_CALL_STATIC(dependency_injector, "phalcon\\di", "getdefault");
			if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
				return;
			}
	
			/** 
			 * Update the dependency injector
			 */
			phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
			/** 
			 * Gets the default modelsManager service
			 */
			PHALCON_INIT_VAR(service);
			ZVAL_STRING(service, "modelsManager", 1);
	
			PHALCON_INIT_VAR(manager);
			PHALCON_CALL_METHOD_PARAMS_1(manager, dependency_injector, "getshared", service);
			if (Z_TYPE_P(manager) != IS_OBJECT) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The injected service 'modelsManager' is not valid");
				return;
			}
	
			/** 
			 * Update the models manager
			 */
			phalcon_update_property_zval(this_ptr, SL("_modelsManager"), manager TSRMLS_CC);
	
			/** 
			 * Update the objects attributes
			 */
	
			if (!phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
				PHALCON_GET_FOREACH_VALUE(value);
	
				phalcon_update_property_zval_zval(this_ptr, key, value TSRMLS_CC);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
			RETURN_MM_NULL();
		}
	}
	PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid serialization data");
	return;
}

/**
 * Returns a simple representation of the object that can be used with var_dump
 *
 *<code>
 * var_dump($robot->dump());
 *</code>
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model, dump){

	zval *array_data;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(array_data);
	PHALCON_CALL_FUNC_PARAMS_1(array_data, "get_object_vars", this_ptr);
	RETURN_CCTOR(array_data);
}

/**
 * Returns the instance as an array representation
 *
 *<code>
 * print_r($robot->toArray());
 *</code>
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model, toArray){

	zval *meta_data, *data, *null_value, *attributes;
	zval *attribute = NULL, *value = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD(meta_data, this_ptr, "getmodelsmetadata");
	
	PHALCON_INIT_VAR(data);
	array_init(data);
	
	PHALCON_INIT_VAR(null_value);
	
	PHALCON_INIT_VAR(attributes);
	PHALCON_CALL_METHOD_PARAMS_1(attributes, meta_data, "getattributes", this_ptr);
	
	if (!phalcon_is_iterable(attributes, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(attribute);
	
		if (phalcon_isset_property_zval(this_ptr, attribute TSRMLS_CC)) {
			PHALCON_OBS_NVAR(value);
			phalcon_read_property_zval(&value, this_ptr, attribute, PH_NOISY_CC);
			phalcon_array_update_zval(&data, attribute, &value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		} else {
			phalcon_array_update_zval(&data, attribute, &null_value, PH_COPY | PH_SEPARATE TSRMLS_CC);
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	RETURN_CTOR(data);
}

/**
 * Enables/disables options in the ORM
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model, setup){

	zval *options, *disable_events, *virtual_foreign_keys;
	zval *column_renaming, *not_null_validations;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(options) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Options must be an array");
		return;
	}
	
	/** 
	 * Enables/Disables globally the internal events
	 */
	if (phalcon_array_isset_string(options, SS("events"))) {
		PHALCON_OBS_VAR(disable_events);
		phalcon_array_fetch_string(&disable_events, options, SL("events"), PH_NOISY_CC);
		PHALCON_GLOBAL(orm).events = zend_is_true(disable_events);
	}
	
	/** 
	 * Enables/Disables virtual foreign keys
	 */
	if (phalcon_array_isset_string(options, SS("virtualForeignKeys"))) {
		PHALCON_OBS_VAR(virtual_foreign_keys);
		phalcon_array_fetch_string(&virtual_foreign_keys, options, SL("virtualForeignKeys"), PH_NOISY_CC);
		PHALCON_GLOBAL(orm).virtual_foreign_keys = zend_is_true(virtual_foreign_keys);
	}
	
	/** 
	 * Enables/Disables column renaming
	 */
	if (phalcon_array_isset_string(options, SS("columnRenaming"))) {
		PHALCON_OBS_VAR(column_renaming);
		phalcon_array_fetch_string(&column_renaming, options, SL("columnRenaming"), PH_NOISY_CC);
		PHALCON_GLOBAL(orm).column_renaming = zend_is_true(column_renaming);
	}
	
	/** 
	 * Enables/Disables automatic not null validation
	 */
	if (phalcon_array_isset_string(options, SS("notNullValidations"))) {
		PHALCON_OBS_VAR(not_null_validations);
		phalcon_array_fetch_string(&not_null_validations, options, SL("notNullValidations"), PH_NOISY_CC);
		PHALCON_GLOBAL(orm).not_null_validations = zend_is_true(not_null_validations);
	}
	
	PHALCON_MM_RESTORE();
}

