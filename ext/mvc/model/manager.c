
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Mvc\Model\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A ModelsManager is injected to a model via a Dependency Injector Container such as Phalcon\DI.
 *
 * <code>
 * $dependencyInjector = new Phalcon\DI();
 *
 * $dependencyInjector->set('modelsManager', function(){
 *      return new Phalcon\Mvc\Model\Manager();
 * });
 *
 * $robot = new Robots($dependencyInjector);
 * </code>
 */


/**
 * Phalcon\Mvc\Model\Manager initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Model_Manager){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Model, Manager, mvc_model_manager, phalcon_mvc_model_manager_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_customEventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_connectionServices"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_aliases"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasMany"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasManySingle"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasOne"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasOneSingle"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_belongsTo"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_belongsToSingle"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_initialized"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_behaviors"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_lastInitialized"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_lastQuery"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_model_manager_ce TSRMLS_CC, 3, phalcon_mvc_model_managerinterface_ce, phalcon_di_injectionawareinterface_ce, phalcon_events_eventsawareinterface_ce);

	return SUCCESS;
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setDI){

	zval *dependency_injector;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The dependency injector is invalid");
		return;
	}
	phalcon_update_property_zval(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets a global events manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setEventsManager){

	zval *events_manager;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &events_manager) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getEventsManager){


	RETURN_MEMBER(this_ptr, "_eventsManager");
}

/**
 * Sets a custom events manager for a specific model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setCustomEventsManager){

	zval *model, *events_manager, *class_name;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model, &events_manager) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_customEventsManager"), class_name, events_manager TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a custom events manager related to a model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getCustomEventsManager){

	zval *model, *custom_events_manager, *class_name;
	zval *events_manager;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(custom_events_manager);
	phalcon_read_property(&custom_events_manager, this_ptr, SL("_customEventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(custom_events_manager) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(class_name);
		phalcon_get_class(class_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(custom_events_manager, class_name)) {
			PHALCON_OBS_VAR(events_manager);
			phalcon_array_fetch(&events_manager, custom_events_manager, class_name, PH_NOISY_CC);
			RETURN_CCTOR(events_manager);
		}
	}
	
	RETURN_MM_NULL();
}

/**
 * Initializes a model in the model manager
 *
 * @param Phalcon\Mvc\ModelInterface $model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, initialize){

	zval *model, *class_name, *initialized, *events_manager;
	zval *event_name;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model, 1 TSRMLS_CC);
	
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	
	/** 
	 * Models are just initialized once per request
	 */
	if (phalcon_array_isset(initialized, class_name)) {
		RETURN_MM_NULL();
	}
	
	/** 
	 * Call the 'initialize' method if it's implemented
	 */
	if (phalcon_method_exists_ex(model, SS("initialize") TSRMLS_CC) == SUCCESS) {
		PHALCON_CALL_METHOD_NORETURN(model, "initialize");
	}
	
	/** 
	 * If an EventsManager is available we pass to it every initialized model
	 */
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "modelsManager:afterInitialize", 1);
		PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr);
	}
	
	phalcon_update_property_array(this_ptr, SL("_initialized"), class_name, model TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_lastInitialized"), model TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether a model is already initialized
 *
 * @param string $modelName
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isInitialized){

	zval *model_name, *initialized, *lowercased;
	zval *is_intitialized = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(lowercased);
	phalcon_fast_strtolower(lowercased, model_name);
	
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, phalcon_array_isset(initialized, lowercased));
	PHALCON_CPY_WRT(is_intitialized, r0);
	RETURN_NCTOR(is_intitialized);
}

/**
 * Get last initialized model
 *
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastInitialized){


	RETURN_MEMBER(this_ptr, "_lastInitialized");
}

/**
 * Loads a model throwing an exception if it doesn't exist
 *
 * @param  string $modelName
 * @param  boolean $newInstance
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, load){

	zval *model_name, *new_instance = NULL, *initialized;
	zval *lowercased, *model = NULL, *cloned, *dependency_injector;
	zval *exception_message;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &model_name, &new_instance) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!new_instance) {
		PHALCON_INIT_VAR(new_instance);
		ZVAL_BOOL(new_instance, 0);
	}
	
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(lowercased);
	phalcon_fast_strtolower(lowercased, model_name);
	
	/** 
	 * Check if a model with the same is already loaded
	 */
	if (phalcon_array_isset(initialized, lowercased)) {
	
		PHALCON_OBS_VAR(model);
		phalcon_array_fetch(&model, initialized, lowercased, PH_NOISY_CC);
		if (zend_is_true(new_instance)) {
			PHALCON_INIT_VAR(cloned);
			if (phalcon_clone(cloned, model TSRMLS_CC) == FAILURE) {
				return;
			}
			RETURN_CCTOR(cloned);
		}
	
	
		RETURN_CCTOR(model);
	}
	
	/** 
	 * Load it using an autoloader
	 */
	if (phalcon_class_exists(model_name TSRMLS_CC)) {
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
	
		PHALCON_INIT_NVAR(model);
		object_init_ex(model, ce0);
		if (phalcon_has_constructor(model TSRMLS_CC)) {
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(model, "__construct", dependency_injector, this_ptr);
		}
		RETURN_CCTOR(model);
	}
	
	/** 
	 * The model doesn't exist throw an exception
	 */
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SVS(exception_message, "The model '", model_name, "' could not be loaded");
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
	return;
}

/**
 * Set a connection service for a model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param string $connectionService
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setConnectionService){

	zval *model, *connection_service, *entity_name;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model, &connection_service) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_connectionServices"), entity_name, connection_service TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the connection related to a model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @return Phalcon\Db\AdapterInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getConnection){

	zval *model, *service = NULL, *connection_services;
	zval *entity_name, *dependency_injector, *connection;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "db", 1);
	
	PHALCON_OBS_VAR(connection_services);
	phalcon_read_property(&connection_services, this_ptr, SL("_connectionServices"), PH_NOISY_CC);
	if (Z_TYPE_P(connection_services) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
		/** 
		 * Check if the model has a custom connection service
		 */
		if (phalcon_array_isset(connection_services, entity_name)) {
			PHALCON_OBS_NVAR(service);
			phalcon_array_fetch(&service, connection_services, entity_name, PH_NOISY_CC);
		}
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	/** 
	 * Request the connection service from the DI
	 */
	PHALCON_INIT_VAR(connection);
	PHALCON_CALL_METHOD_PARAMS_1(connection, dependency_injector, "getshared", service);
	if (Z_TYPE_P(connection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid injected connection service");
		return;
	}
	
	
	RETURN_CCTOR(connection);
}

/**
 * Returns the service name related to a model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param string
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getConnectionService){

	zval *model, *connection_services, *entity_name;
	zval *connection;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(connection_services);
	phalcon_read_property(&connection_services, this_ptr, SL("_connectionServices"), PH_NOISY_CC);
	if (Z_TYPE_P(connection_services) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
		/** 
		 * Check if there is a custom service connection name
		 */
		if (phalcon_array_isset(connection_services, entity_name)) {
			PHALCON_OBS_VAR(connection);
			phalcon_array_fetch(&connection, connection_services, entity_name, PH_NOISY_CC);
			RETURN_CCTOR(connection);
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_STRING("db", 1);
}

/**
 * Receives events generated in the models and dispatches them to a events-manager if available
 * Notify the behaviors that are listening in the model
 *
 * @param string $eventName
 * @param Phalcon\Mvc\ModelInterface $model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, notifyEvent){

	zval *event_name, *model, *status = NULL, *behaviors, *entity_name = NULL;
	zval *models_behaviors, *behavior = NULL, *events_manager;
	zval *fire_event_name = NULL, *custom_events_manager;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &event_name, &model) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(status);
	
	/** 
	 * Dispatch events to the global events manager
	 */
	PHALCON_OBS_VAR(behaviors);
	phalcon_read_property(&behaviors, this_ptr, SL("_behaviors"), PH_NOISY_CC);
	if (Z_TYPE_P(behaviors) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(behaviors, entity_name)) {
	
			/** 
			 * Notify all the events on the behavior
			 */
			PHALCON_OBS_VAR(models_behaviors);
			phalcon_array_fetch(&models_behaviors, behaviors, entity_name, PH_NOISY_CC);
	
			if (!phalcon_is_iterable(models_behaviors, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(behavior);
	
				PHALCON_INIT_NVAR(status);
				PHALCON_CALL_METHOD_PARAMS_2(status, behavior, "notify", event_name, model);
				if (PHALCON_IS_FALSE(status)) {
					RETURN_CCTOR(status);
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	}
	
	/** 
	 * Dispatch events to the global events manager
	 */
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(fire_event_name);
		PHALCON_CONCAT_SV(fire_event_name, "model:", event_name);
	
		PHALCON_INIT_NVAR(status);
		PHALCON_CALL_METHOD_PARAMS_2(status, events_manager, "fire", fire_event_name, model);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_CCTOR(status);
		}
	}
	
	/** 
	 * A model can has an specific events manager for it
	 */
	PHALCON_OBS_VAR(custom_events_manager);
	phalcon_read_property(&custom_events_manager, this_ptr, SL("_customEventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(custom_events_manager) == IS_ARRAY) { 
	
		PHALCON_INIT_NVAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(custom_events_manager, entity_name)) {
	
			PHALCON_INIT_NVAR(fire_event_name);
			PHALCON_CONCAT_SV(fire_event_name, "model:", event_name);
	
			PHALCON_INIT_NVAR(status);
			PHALCON_CALL_METHOD_PARAMS_2(status, custom_events_manager, "fire", fire_event_name, model);
			if (PHALCON_IS_FALSE(status)) {
				RETURN_CCTOR(status);
			}
		}
	}
	
	
	RETURN_CCTOR(status);
}

/**
 * Dispatch a event to the listeners and behaviors
 * This method expects that the endpoint listeners/behaviors returns true
 * meaning that a least one is implemented
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param string $eventName
 * @param aray $data
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, missingMethod){

	zval *model, *event_name, *data, *behaviors, *entity_name;
	zval *models_behaviors, *behavior = NULL, *result = NULL, *events_manager;
	zval *fire_event_name, *status;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &model, &event_name, &data) == FAILURE) {
		RETURN_MM_NULL();
	}

	/** 
	 * Dispatch events to the global events manager
	 */
	PHALCON_OBS_VAR(behaviors);
	phalcon_read_property(&behaviors, this_ptr, SL("_behaviors"), PH_NOISY_CC);
	if (Z_TYPE_P(behaviors) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(behaviors, entity_name)) {
	
			/** 
			 * Notify all the events on the behavior
			 */
			PHALCON_OBS_VAR(models_behaviors);
			phalcon_array_fetch(&models_behaviors, behaviors, entity_name, PH_NOISY_CC);
	
			if (!phalcon_is_iterable(models_behaviors, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(behavior);
	
				PHALCON_INIT_NVAR(result);
				PHALCON_CALL_METHOD_PARAMS_3(result, behavior, "missingmethod", model, event_name, data);
				if (Z_TYPE_P(result) != IS_NULL) {
					RETURN_CCTOR(result);
				}
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	}
	
	/** 
	 * Dispatch events to the global events manager
	 */
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_VAR(fire_event_name);
		PHALCON_CONCAT_SV(fire_event_name, "model:", event_name);
	
		PHALCON_INIT_VAR(status);
		PHALCON_CALL_METHOD_PARAMS_3(status, events_manager, "fire", fire_event_name, model, data);
		RETURN_CCTOR(status);
	}
	
	RETURN_MM_NULL();
}

/**
 * Binds a behavior to a model
 *
 * @param Phalcon\Mvc\ModelInterface $model
 * @param Phalcon\Mvc\Model\BehaviorInterface $behavior
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBehavior){

	zval *model, *behavior, *entity_name, *behaviors;
	zval *models_behaviors = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model, &behavior) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(behavior) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "The behavior is invalid");
		return;
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
	/** 
	 * Get the current behaviors
	 */
	PHALCON_OBS_VAR(behaviors);
	phalcon_read_property(&behaviors, this_ptr, SL("_behaviors"), PH_NOISY_CC);
	if (phalcon_array_isset(behaviors, entity_name)) {
		PHALCON_OBS_VAR(models_behaviors);
		phalcon_array_fetch(&models_behaviors, behaviors, entity_name, PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(models_behaviors);
		array_init(models_behaviors);
	}
	
	/** 
	 * Append the behavior to the list of behaviors
	 */
	phalcon_array_append(&models_behaviors, behavior, PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * Update the behaviors list
	 */
	phalcon_update_property_array(this_ptr, SL("_behaviors"), entity_name, models_behaviors TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Setup a 1-1 relation between two models
 *
 * @param 	Phalcon\Mvc\Model $model
 * @param mixed $fields
 * @param string $referencedModel
 * @param mixed $referencedFields
 * @param array $options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasOne){

	zval *model, *fields, *referenced_model, *referenced_fields;
	zval *options = NULL, *entity_name, *referenced_entity;
	zval *key_relation, *has_one, *relations = NULL, *number_fields;
	zval *number_referenced, *diferent_fields;
	zval *type, *relation, *alias, *lower_alias = NULL, *key_alias;
	zval *has_one_single, *single_relations = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &referenced_model, &referenced_fields, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(referenced_entity);
	phalcon_fast_strtolower(referenced_entity, referenced_model);
	
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, entity_name, "$", referenced_entity);
	
	PHALCON_OBS_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if (!phalcon_array_isset(has_one, key_relation)) {
		PHALCON_INIT_VAR(relations);
		array_init(relations);
	} else {
		PHALCON_OBS_NVAR(relations);
		phalcon_array_fetch(&relations, has_one, key_relation, PH_NOISY_CC);
	}
	
	/** 
	 * Check if the number of fields are the same
	 */
	if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(number_fields);
		phalcon_fast_count(number_fields, fields TSRMLS_CC);
	
		PHALCON_INIT_VAR(number_referenced);
		phalcon_fast_count(number_referenced, referenced_fields TSRMLS_CC);
	
		PHALCON_INIT_VAR(diferent_fields);
		is_not_equal_function(diferent_fields, number_fields, number_referenced TSRMLS_CC);
		if (PHALCON_IS_TRUE(diferent_fields)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
			return;
		}
	}
	
	/** 
	 * Type '1' is 'has one'
	 */
	PHALCON_INIT_VAR(type);
	ZVAL_LONG(type, 1);
	
	/** 
	 * Create a relationship instance
	 */
	PHALCON_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	PHALCON_CALL_METHOD_PARAMS_5_NORETURN(relation, "__construct", type, referenced_model, fields, referenced_fields, options);
	
	/** 
	 * Check an alias for the relation
	 */
	if (phalcon_array_isset_string(options, SS("alias"))) {
		PHALCON_OBS_VAR(alias);
		phalcon_array_fetch_string(&alias, options, SL("alias"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(lower_alias);
		phalcon_fast_strtolower(lower_alias, alias);
	} else {
		PHALCON_CPY_WRT(lower_alias, referenced_entity);
	}
	
	/** 
	 * Append a new relationship
	 */
	phalcon_array_append(&relations, relation, PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * Update the global alias
	 */
	PHALCON_INIT_VAR(key_alias);
	PHALCON_CONCAT_VSV(key_alias, entity_name, "$", lower_alias);
	phalcon_update_property_array(this_ptr, SL("_aliases"), key_alias, relation TSRMLS_CC);
	
	/** 
	 * Update the relations
	 */
	phalcon_update_property_array(this_ptr, SL("_hasOne"), key_relation, relations TSRMLS_CC);
	
	/** 
	 * Get existing relations by model
	 */
	PHALCON_OBS_VAR(has_one_single);
	phalcon_read_property(&has_one_single, this_ptr, SL("_hasOneSingle"), PH_NOISY_CC);
	if (!phalcon_array_isset(has_one_single, entity_name)) {
		PHALCON_INIT_VAR(single_relations);
		array_init(single_relations);
	} else {
		PHALCON_OBS_NVAR(single_relations);
		phalcon_array_fetch(&single_relations, has_one_single, entity_name, PH_NOISY_CC);
	}
	
	/** 
	 * Append a new relationship
	 */
	phalcon_array_append(&single_relations, relation, PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * Update relations by model
	 */
	phalcon_update_property_array(this_ptr, SL("_hasOneSingle"), entity_name, single_relations TSRMLS_CC);
	
	RETURN_CTOR(relation);
}

/**
 * Setup a relation reverse many to one between two models
 *
 * @param 	Phalcon\Mvc\Model $model
 * @param mixed $fields
 * @param string $referencedModel
 * @param mixed $referencedFields
 * @param array $options
 * @return  Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBelongsTo){

	zval *model, *fields, *referenced_model, *referenced_fields;
	zval *options = NULL, *entity_name, *referenced_entity;
	zval *key_relation, *belongs_to, *relations = NULL;
	zval *number_fields, *number_referenced, *diferent_fields;
	zval *type, *relation, *alias, *lower_alias = NULL, *key_alias;
	zval *belongs_to_single, *single_relations = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &referenced_model, &referenced_fields, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(referenced_entity);
	phalcon_fast_strtolower(referenced_entity, referenced_model);
	
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, entity_name, "$", referenced_entity);
	
	PHALCON_OBS_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	if (!phalcon_array_isset(belongs_to, key_relation)) {
		PHALCON_INIT_VAR(relations);
		array_init(relations);
	} else {
		PHALCON_OBS_NVAR(relations);
		phalcon_array_fetch(&relations, belongs_to, key_relation, PH_NOISY_CC);
	}
	
	/** 
	 * Check if the number of fields are the same
	 */
	if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(number_fields);
		phalcon_fast_count(number_fields, fields TSRMLS_CC);
	
		PHALCON_INIT_VAR(number_referenced);
		phalcon_fast_count(number_referenced, referenced_fields TSRMLS_CC);
	
		PHALCON_INIT_VAR(diferent_fields);
		is_not_equal_function(diferent_fields, number_fields, number_referenced TSRMLS_CC);
		if (PHALCON_IS_TRUE(diferent_fields)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
			return;
		}
	}
	
	/** 
	 * Type '0' is 'belongs to'
	 */
	PHALCON_INIT_VAR(type);
	ZVAL_LONG(type, 0);
	
	/** 
	 * Create a relationship instance
	 */
	PHALCON_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	PHALCON_CALL_METHOD_PARAMS_5_NORETURN(relation, "__construct", type, referenced_model, fields, referenced_fields, options);
	
	/** 
	 * Check an alias for the relation
	 */
	if (phalcon_array_isset_string(options, SS("alias"))) {
		PHALCON_OBS_VAR(alias);
		phalcon_array_fetch_string(&alias, options, SL("alias"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(lower_alias);
		phalcon_fast_strtolower(lower_alias, alias);
	} else {
		PHALCON_CPY_WRT(lower_alias, referenced_entity);
	}
	
	/** 
	 * Append a new relationship
	 */
	phalcon_array_append(&relations, relation, PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * Update the global alias
	 */
	PHALCON_INIT_VAR(key_alias);
	PHALCON_CONCAT_VSV(key_alias, entity_name, "$", lower_alias);
	phalcon_update_property_array(this_ptr, SL("_aliases"), key_alias, relation TSRMLS_CC);
	
	/** 
	 * Update the relations
	 */
	phalcon_update_property_array(this_ptr, SL("_belongsTo"), key_relation, relations TSRMLS_CC);
	
	/** 
	 * Get existing relations by model
	 */
	PHALCON_OBS_VAR(belongs_to_single);
	phalcon_read_property(&belongs_to_single, this_ptr, SL("_belongsToSingle"), PH_NOISY_CC);
	if (!phalcon_array_isset(belongs_to_single, entity_name)) {
		PHALCON_INIT_VAR(single_relations);
		array_init(single_relations);
	} else {
		PHALCON_OBS_NVAR(single_relations);
		phalcon_array_fetch(&single_relations, belongs_to_single, entity_name, PH_NOISY_CC);
	}
	
	/** 
	 * Append a new relationship
	 */
	phalcon_array_append(&single_relations, relation, PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * Update relations by model
	 */
	phalcon_update_property_array(this_ptr, SL("_belongsToSingle"), entity_name, single_relations TSRMLS_CC);
	
	RETURN_CTOR(relation);
}

/**
 * Setup a relation 1-n between two models
 *
 * @param 	Phalcon\Mvc\ModelInterface $model
 * @param mixed $fields
 * @param string $referencedModel
 * @param mixed $referencedFields
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasMany){

	zval *model, *fields, *referenced_model, *referenced_fields;
	zval *options = NULL, *entity_name, *referenced_entity;
	zval *key_relation, *has_many, *relations = NULL, *number_fields;
	zval *number_referenced, *diferent_fields;
	zval *type, *relation, *alias, *lower_alias = NULL, *key_alias;
	zval *has_many_single, *single_relations = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &referenced_model, &referenced_fields, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(referenced_entity);
	phalcon_fast_strtolower(referenced_entity, referenced_model);
	
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, entity_name, "$", referenced_entity);
	
	PHALCON_OBS_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (!phalcon_array_isset(has_many, key_relation)) {
		PHALCON_INIT_VAR(relations);
		array_init(relations);
	} else {
		PHALCON_OBS_NVAR(relations);
		phalcon_array_fetch(&relations, has_many, key_relation, PH_NOISY_CC);
	}
	
	/** 
	 * Check if the number of fields are the same
	 */
	if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(number_fields);
		phalcon_fast_count(number_fields, fields TSRMLS_CC);
	
		PHALCON_INIT_VAR(number_referenced);
		phalcon_fast_count(number_referenced, referenced_fields TSRMLS_CC);
	
		PHALCON_INIT_VAR(diferent_fields);
		is_not_equal_function(diferent_fields, number_fields, number_referenced TSRMLS_CC);
		if (PHALCON_IS_TRUE(diferent_fields)) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
			return;
		}
	}
	
	/** 
	 * Type '2' is 'has many'
	 */
	PHALCON_INIT_VAR(type);
	ZVAL_LONG(type, 2);
	
	/** 
	 * Create a relationship instance
	 */
	PHALCON_INIT_VAR(relation);
	object_init_ex(relation, phalcon_mvc_model_relation_ce);
	PHALCON_CALL_METHOD_PARAMS_5_NORETURN(relation, "__construct", type, referenced_model, fields, referenced_fields, options);
	
	/** 
	 * Check an alias for the relation
	 */
	if (phalcon_array_isset_string(options, SS("alias"))) {
		PHALCON_OBS_VAR(alias);
		phalcon_array_fetch_string(&alias, options, SL("alias"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(lower_alias);
		phalcon_fast_strtolower(lower_alias, alias);
	} else {
		PHALCON_CPY_WRT(lower_alias, referenced_entity);
	}
	
	/** 
	 * Append a new relationship
	 */
	phalcon_array_append(&relations, relation, PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * Update the global alias
	 */
	PHALCON_INIT_VAR(key_alias);
	PHALCON_CONCAT_VSV(key_alias, entity_name, "$", lower_alias);
	phalcon_update_property_array(this_ptr, SL("_aliases"), key_alias, relation TSRMLS_CC);
	
	/** 
	 * Update the relations
	 */
	phalcon_update_property_array(this_ptr, SL("_hasMany"), key_relation, relations TSRMLS_CC);
	
	/** 
	 * Get existing relations by model
	 */
	PHALCON_OBS_VAR(has_many_single);
	phalcon_read_property(&has_many_single, this_ptr, SL("_hasManySingle"), PH_NOISY_CC);
	if (!phalcon_array_isset(has_many_single, entity_name)) {
		PHALCON_INIT_VAR(single_relations);
		array_init(single_relations);
	} else {
		PHALCON_OBS_NVAR(single_relations);
		phalcon_array_fetch(&single_relations, has_many_single, entity_name, PH_NOISY_CC);
	}
	
	/** 
	 * Append a new relationship
	 */
	phalcon_array_append(&single_relations, relation, PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * Update relations by model
	 */
	phalcon_update_property_array(this_ptr, SL("_hasManySingle"), entity_name, single_relations TSRMLS_CC);
	
	RETURN_CTOR(relation);
}

PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasManyThrough){


	
}

/**
 * Checks whether a model has a belongsTo relation with another model
 *
 * @param 	string $modelName
 * @param 	string $modelRelation
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsBelongsTo){

	zval *model_name, *model_relation, *initialized;
	zval *entity_name, *entity_relation, *key_relation;
	zval *belongs_to;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model_name, &model_relation) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_fast_strtolower(entity_name, model_name);
	
	PHALCON_INIT_VAR(entity_relation);
	phalcon_fast_strtolower(entity_relation, model_relation);
	
	/** 
	 * Relationship unique key
	 */
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, entity_name, "$", entity_relation);
	
	/** 
	 * Initialize the model first
	 */
	if (!phalcon_array_isset(initialized, entity_name)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "load", model_name);
	}
	
	PHALCON_OBS_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	if (phalcon_array_isset(belongs_to, key_relation)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Checks whether a model has a hasMany relation with another model
 *
 * @param 	string $modelName
 * @param 	string $modelRelation
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasMany){

	zval *model_name, *model_relation, *initialized;
	zval *entity_name, *entity_relation, *key_relation;
	zval *has_many;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model_name, &model_relation) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_fast_strtolower(entity_name, model_name);
	
	PHALCON_INIT_VAR(entity_relation);
	phalcon_fast_strtolower(entity_relation, model_relation);
	
	/** 
	 * Relationship unique key
	 */
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, entity_name, "$", entity_relation);
	
	/** 
	 * Initialize the model first
	 */
	if (!phalcon_array_isset(initialized, entity_name)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "load", model_name);
	}
	
	PHALCON_OBS_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (phalcon_array_isset(has_many, key_relation)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Checks whether a model has a hasOne relation with another model
 *
 * @param 	string $modelName
 * @param 	string $modelRelation
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasOne){

	zval *model_name, *model_relation, *initialized;
	zval *entity_name, *entity_relation, *key_relation;
	zval *has_one;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model_name, &model_relation) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_fast_strtolower(entity_name, model_name);
	
	PHALCON_INIT_VAR(entity_relation);
	phalcon_fast_strtolower(entity_relation, model_relation);
	
	/** 
	 * Relationship unique key
	 */
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, entity_name, "$", entity_relation);
	
	/** 
	 * Initialize the model first
	 */
	if (!phalcon_array_isset(initialized, entity_name)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "load", model_name);
	}
	
	PHALCON_OBS_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if (phalcon_array_isset(has_one, key_relation)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Returns a relation by its alias
 *
 * @param string $modelName
 * @param string $alias
 * @return Phalcon\Mvc\Model\Relation
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationByAlias){

	zval *model_name, *alias, *aliases, *key_alias;
	zval *key_lower, *relation;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model_name, &alias) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(aliases);
	phalcon_read_property(&aliases, this_ptr, SL("_aliases"), PH_NOISY_CC);
	if (Z_TYPE_P(aliases) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(key_alias);
		PHALCON_CONCAT_VSV(key_alias, model_name, "$", alias);
	
		PHALCON_INIT_VAR(key_lower);
		phalcon_fast_strtolower(key_lower, key_alias);
		if (phalcon_array_isset(aliases, key_lower)) {
			PHALCON_OBS_VAR(relation);
			phalcon_array_fetch(&relation, aliases, key_lower, PH_NOISY_CC);
			RETURN_CCTOR(relation);
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Helper method to query records based on a relation definition
 *
 * @param Phalcon\Mvc\Model\Relation $relation
 * @param string $method
 * @param Phalcon\Mvc\ModelInterface $record
 * @param array $parameters
 * @return Phalcon\Mvc\Model\Resultset\Simple
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationRecords){

	zval *relation, *method, *record, *parameters = NULL, *placeholders = NULL;
	zval *pre_conditions = NULL, *conditions = NULL, *fields, *field = NULL;
	zval *value = NULL, *referenced_field = NULL, *condition = NULL, *referenced_fields;
	zval *position = NULL, *join_conditions, *has_through;
	zval *dependency_injector, *find_params, *find_arguments = NULL;
	zval *arguments, *referenced_model, *referenced_entity;
	zval *type, *retrieve_method = NULL, *call_object, *records;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &relation, &method, &record, &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	} else {
		PHALCON_SEPARATE_PARAM(parameters);
	}
	
	/** 
	 * Re-use bound parameters
	 */
	if (Z_TYPE_P(parameters) == IS_ARRAY) { 
		if (phalcon_array_isset_string(parameters, SS("bind"))) {
			PHALCON_OBS_VAR(placeholders);
			phalcon_array_fetch_string(&placeholders, parameters, SL("bind"), PH_NOISY_CC);
			PHALCON_SEPARATE_PARAM(parameters);
			phalcon_array_unset_string(parameters, SS("bind"));
		} else {
			PHALCON_INIT_NVAR(placeholders);
			array_init(placeholders);
		}
	} else {
		PHALCON_INIT_NVAR(placeholders);
		array_init(placeholders);
	}
	
	/** 
	 * Re-use conditions
	 */
	PHALCON_INIT_VAR(pre_conditions);
	if (Z_TYPE_P(parameters) == IS_ARRAY) { 
		if (phalcon_array_isset_long(parameters, 0)) {
			PHALCON_OBS_NVAR(pre_conditions);
			phalcon_array_fetch_long(&pre_conditions, parameters, 0, PH_NOISY_CC);
			PHALCON_SEPARATE_PARAM(parameters);
			phalcon_array_unset_long(parameters, 0);
		} else {
			if (phalcon_array_isset_string(parameters, SS("conditions"))) {
				PHALCON_OBS_NVAR(pre_conditions);
				phalcon_array_fetch_string(&pre_conditions, parameters, SL("conditions"), PH_NOISY_CC);
				PHALCON_SEPARATE_PARAM(parameters);
				phalcon_array_unset_string(parameters, SS("conditions"));
			}
		}
	} else {
		if (Z_TYPE_P(parameters) == IS_STRING) {
			PHALCON_CPY_WRT(pre_conditions, parameters);
		}
	}
	
	if (Z_TYPE_P(pre_conditions) != IS_NULL) {
		PHALCON_INIT_VAR(conditions);
		array_init_size(conditions, 1);
		phalcon_array_append(&conditions, pre_conditions, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(conditions);
		array_init(conditions);
	}
	
	/** 
	 * Appends conditions created from the fields defined in the relation
	 */
	PHALCON_INIT_VAR(fields);
	PHALCON_CALL_METHOD(fields, relation, "getfields");
	if (Z_TYPE_P(fields) != IS_ARRAY) { 
		PHALCON_CPY_WRT(field, fields);
	
		PHALCON_INIT_VAR(value);
		PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", field);
	
		PHALCON_INIT_VAR(referenced_field);
		PHALCON_CALL_METHOD(referenced_field, relation, "getreferencedfields");
	
		PHALCON_INIT_VAR(condition);
		PHALCON_CONCAT_VS(condition, referenced_field, " = ?0");
		phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&placeholders, value, PH_SEPARATE TSRMLS_CC);
	} else {
		/** 
		 * Compound relation
		 */
		PHALCON_INIT_VAR(referenced_fields);
		PHALCON_CALL_METHOD(referenced_fields, relation, "getreferencedfields");
	
		if (!phalcon_is_iterable(fields, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_KEY(position, ah0, hp0);
			PHALCON_GET_FOREACH_VALUE(field);
	
			PHALCON_INIT_NVAR(value);
			PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", field);
	
			PHALCON_OBS_NVAR(referenced_field);
			phalcon_array_fetch(&referenced_field, referenced_fields, position, PH_NOISY_CC);
	
			PHALCON_INIT_NVAR(condition);
			PHALCON_CONCAT_VSV(condition, referenced_field, " = ?", position);
			phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&placeholders, value, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	/** 
	 * We don't trust the user or the database so we use bound parameters
	 */
	PHALCON_INIT_VAR(join_conditions);
	phalcon_fast_join_str(join_conditions, SL(" AND "), conditions TSRMLS_CC);
	
	/** 
	 * Check if the relation is direct or through an intermediate model
	 */
	PHALCON_INIT_VAR(has_through);
	PHALCON_CALL_METHOD(has_through, relation, "hasthrough");
	if (zend_is_true(has_through)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Not implemented");
		return;
	}
	
	PHALCON_INIT_VAR(dependency_injector);
	PHALCON_CALL_METHOD(dependency_injector, record, "getdi");
	
	/** 
	 * Create a valid params array to pass to the find/findFirst method
	 */
	PHALCON_INIT_VAR(find_params);
	array_init_size(find_params, 3);
	phalcon_array_append(&find_params, join_conditions, PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&find_params, SL("bind"), &placeholders, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&find_params, SL("di"), &dependency_injector, PH_COPY | PH_SEPARATE TSRMLS_CC);
	if (Z_TYPE_P(parameters) == IS_ARRAY) { 
		PHALCON_INIT_VAR(find_arguments);
		PHALCON_CALL_FUNC_PARAMS_2(find_arguments, "array_merge", find_params, parameters);
	} else {
		PHALCON_CPY_WRT(find_arguments, find_params);
	}
	
	PHALCON_INIT_VAR(arguments);
	array_init_size(arguments, 1);
	phalcon_array_append(&arguments, find_arguments, PH_SEPARATE TSRMLS_CC);
	
	/** 
	 * Perform the query on the referenced model
	 */
	PHALCON_INIT_VAR(referenced_model);
	PHALCON_CALL_METHOD(referenced_model, relation, "getreferencedmodel");
	
	/** 
	 * Load the referenced model
	 */
	PHALCON_INIT_VAR(referenced_entity);
	PHALCON_CALL_METHOD_PARAMS_1(referenced_entity, this_ptr, "load", referenced_model);
	
	/** 
	 * Check the right method to get the data
	 */
	if (Z_TYPE_P(method) == IS_NULL) {
		PHALCON_INIT_VAR(type);
		PHALCON_CALL_METHOD(type, relation, "gettype");
	
		switch (phalcon_get_intval(type)) {
	
			case 0:
				PHALCON_INIT_VAR(retrieve_method);
				ZVAL_STRING(retrieve_method, "findFirst", 1);
				break;
	
			case 1:
				PHALCON_INIT_NVAR(retrieve_method);
				ZVAL_STRING(retrieve_method, "findFirst", 1);
				break;
	
			case 2:
				PHALCON_INIT_NVAR(retrieve_method);
				ZVAL_STRING(retrieve_method, "find", 1);
				break;
	
		}
	} else {
		PHALCON_CPY_WRT(retrieve_method, method);
	}
	
	/** 
	 * Call the function in the model
	 */
	PHALCON_INIT_VAR(call_object);
	array_init_size(call_object, 2);
	phalcon_array_append(&call_object, referenced_entity, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&call_object, retrieve_method, PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(records);
	PHALCON_CALL_USER_FUNC_ARRAY(records, call_object, arguments);
	
	RETURN_CCTOR(records);
}

/**
 * Gets belongsTo related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Mvc\Model $record
 * @param array $parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsToRecords){

	zval *method, *model_name, *model_relation, *record;
	zval *parameters = NULL, *belongs_to, *entity_name;
	zval *entity_relation, *key_relation, *relations;
	zval *relation, *records;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &method, &model_name, &model_relation, &record, &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	PHALCON_OBS_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	if (Z_TYPE_P(belongs_to) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_fast_strtolower(entity_name, model_name);
	
		PHALCON_INIT_VAR(entity_relation);
		phalcon_fast_strtolower(entity_relation, model_relation);
	
		/** 
		 * Check if there is a relation between them
		 */
		PHALCON_INIT_VAR(key_relation);
		PHALCON_CONCAT_VSV(key_relation, entity_name, "$", entity_relation);
		if (!phalcon_array_isset(belongs_to, key_relation)) {
			RETURN_MM_FALSE;
		}
	
		/** 
		 * relations is an array with all the belongsTo relationships to that model
		 */
		PHALCON_OBS_VAR(relations);
		phalcon_array_fetch(&relations, belongs_to, key_relation, PH_NOISY_CC);
	
		/** 
		 * Get the first relation
		 */
		PHALCON_OBS_VAR(relation);
		phalcon_array_fetch_long(&relation, relations, 0, PH_NOISY_CC);
	
		/** 
		 * Perform the query
		 */
		PHALCON_INIT_VAR(records);
		PHALCON_CALL_METHOD_PARAMS_4(records, this_ptr, "getrelationrecords", relation, method, record, parameters);
	
		RETURN_CCTOR(records);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Gets hasMany related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Mvc\Model $record
 * @param array $parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyRecords){

	zval *method, *model_name, *model_relation, *record;
	zval *parameters = NULL, *has_many, *entity_name, *entity_relation;
	zval *key_relation, *relations, *relation, *records;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &method, &model_name, &model_relation, &record, &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	PHALCON_OBS_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (Z_TYPE_P(has_many) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_fast_strtolower(entity_name, model_name);
	
		PHALCON_INIT_VAR(entity_relation);
		phalcon_fast_strtolower(entity_relation, model_relation);
	
		/** 
		 * Check if there is a relation between them
		 */
		PHALCON_INIT_VAR(key_relation);
		PHALCON_CONCAT_VSV(key_relation, entity_name, "$", entity_relation);
		if (!phalcon_array_isset(has_many, key_relation)) {
			RETURN_MM_FALSE;
		}
	
		/** 
		 * relations is an array with all the belongsTo relationships to that model
		 */
		PHALCON_OBS_VAR(relations);
		phalcon_array_fetch(&relations, has_many, key_relation, PH_NOISY_CC);
	
		/** 
		 * Get the first relation
		 */
		PHALCON_OBS_VAR(relation);
		phalcon_array_fetch_long(&relation, relations, 0, PH_NOISY_CC);
	
		/** 
		 * Perform the query
		 */
		PHALCON_INIT_VAR(records);
		PHALCON_CALL_METHOD_PARAMS_4(records, this_ptr, "getrelationrecords", relation, method, record, parameters);
	
		RETURN_CCTOR(records);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Gets belongsTo related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Mvc\Model $record
 * @param array $parameters
 * @return Phalcon\Mvc\Model\ResultsetInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneRecords){

	zval *method, *model_name, *model_relation, *record;
	zval *parameters = NULL, *has_one, *entity_name, *entity_relation;
	zval *key_relation, *relations, *relation, *records;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &method, &model_name, &model_relation, &record, &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_VAR(parameters);
	}
	
	PHALCON_OBS_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if (Z_TYPE_P(has_one) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_fast_strtolower(entity_name, model_name);
	
		PHALCON_INIT_VAR(entity_relation);
		phalcon_fast_strtolower(entity_relation, model_relation);
	
		/** 
		 * Check if there is a relation between them
		 */
		PHALCON_INIT_VAR(key_relation);
		PHALCON_CONCAT_VSV(key_relation, entity_name, "$", entity_relation);
		if (!phalcon_array_isset(has_one, key_relation)) {
			RETURN_MM_FALSE;
		}
	
		/** 
		 * relations is an array with all the belongsTo relationships to that model
		 */
		PHALCON_OBS_VAR(relations);
		phalcon_array_fetch(&relations, has_one, key_relation, PH_NOISY_CC);
	
		/** 
		 * Get the first relation
		 */
		PHALCON_OBS_VAR(relation);
		phalcon_array_fetch_long(&relation, relations, 0, PH_NOISY_CC);
	
		/** 
		 * Perform the query
		 */
		PHALCON_INIT_VAR(records);
		PHALCON_CALL_METHOD_PARAMS_4(records, this_ptr, "getrelationrecords", relation, method, record, parameters);
	
		RETURN_CCTOR(records);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Gets all the belongsTo relations defined in a model
 *
 *<code>
 *	$relations = $modelsManager->getBelongsTo(new Robots());
 *</code>
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return Phalcon\Mvc\Model\RelationInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsTo){

	zval *model, *belongs_to_single, *lower_name;
	zval *relations, *empty_array;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(belongs_to_single);
	phalcon_read_property(&belongs_to_single, this_ptr, SL("_belongsToSingle"), PH_NOISY_CC);
	if (Z_TYPE_P(belongs_to_single) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(lower_name);
		phalcon_get_class(lower_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(belongs_to_single, lower_name)) {
			PHALCON_OBS_VAR(relations);
			phalcon_array_fetch(&relations, belongs_to_single, lower_name, PH_NOISY_CC);
			RETURN_CCTOR(relations);
		}
	}
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	
	RETURN_CTOR(empty_array);
}

/**
 * Gets hasMany relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return Phalcon\Mvc\Model\RelationInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasMany){

	zval *model, *has_many_single, *lower_name, *relations;
	zval *empty_array;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(has_many_single);
	phalcon_read_property(&has_many_single, this_ptr, SL("_hasManySingle"), PH_NOISY_CC);
	if (Z_TYPE_P(has_many_single) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(lower_name);
		phalcon_get_class(lower_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(has_many_single, lower_name)) {
			PHALCON_OBS_VAR(relations);
			phalcon_array_fetch(&relations, has_many_single, lower_name, PH_NOISY_CC);
			RETURN_CCTOR(relations);
		}
	}
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	
	RETURN_CTOR(empty_array);
}

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOne){

	zval *model, *has_one_single, *lower_name, *relations;
	zval *empty_array;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(has_one_single);
	phalcon_read_property(&has_one_single, this_ptr, SL("_hasOneSingle"), PH_NOISY_CC);
	if (Z_TYPE_P(has_one_single) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(lower_name);
		phalcon_get_class(lower_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(has_one_single, lower_name)) {
			PHALCON_OBS_VAR(relations);
			phalcon_array_fetch(&relations, has_one_single, lower_name, PH_NOISY_CC);
			RETURN_CCTOR(relations);
		}
	}
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	
	RETURN_CTOR(empty_array);
}

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany){

	zval *model, *has_one, *has_many, *merge;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(has_one);
	PHALCON_CALL_METHOD_PARAMS_1(has_one, this_ptr, "gethasone", model);
	
	PHALCON_INIT_VAR(has_many);
	PHALCON_CALL_METHOD_PARAMS_1(has_many, this_ptr, "gethasmany", model);
	
	PHALCON_INIT_VAR(merge);
	PHALCON_CALL_FUNC_PARAMS_2(merge, "array_merge", has_one, has_many);
	RETURN_CCTOR(merge);
}

/**
 * Query all the relationships defined on a model
 *
 * @param string $modelName
 * @return Phalcon\Mvc\Model\RelationInterface[]
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelations){

	zval *model_name, *entity_name, *all_relations;
	zval *belongs_to, *relations = NULL, *relation = NULL, *has_many;
	zval *has_one;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(entity_name);
	phalcon_fast_strtolower(entity_name, model_name);
	
	PHALCON_INIT_VAR(all_relations);
	array_init(all_relations);
	
	/** 
	 * Get belongs-to relations
	 */
	PHALCON_OBS_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsToSingle"), PH_NOISY_CC);
	if (Z_TYPE_P(belongs_to) == IS_ARRAY) { 
		if (phalcon_array_isset(belongs_to, entity_name)) {
	
			PHALCON_OBS_VAR(relations);
			phalcon_array_fetch(&relations, belongs_to, entity_name, PH_NOISY_CC);
	
			if (!phalcon_is_iterable(relations, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(relation);
	
				phalcon_array_append(&all_relations, relation, PH_SEPARATE TSRMLS_CC);
	
				zend_hash_move_forward_ex(ah0, &hp0);
			}
	
		}
	}
	
	/** 
	 * Get has-many relations
	 */
	PHALCON_OBS_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasManySingle"), PH_NOISY_CC);
	if (Z_TYPE_P(has_many) == IS_ARRAY) { 
		if (phalcon_array_isset(has_many, entity_name)) {
	
			PHALCON_OBS_NVAR(relations);
			phalcon_array_fetch(&relations, has_many, entity_name, PH_NOISY_CC);
	
			if (!phalcon_is_iterable(relations, &ah1, &hp1, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(relation);
	
				phalcon_array_append(&all_relations, relation, PH_SEPARATE TSRMLS_CC);
	
				zend_hash_move_forward_ex(ah1, &hp1);
			}
	
		}
	}
	
	/** 
	 * Get has-one relations
	 */
	PHALCON_OBS_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOneSingle"), PH_NOISY_CC);
	if (Z_TYPE_P(has_one) == IS_ARRAY) { 
		if (phalcon_array_isset(has_one, entity_name)) {
	
			PHALCON_OBS_NVAR(relations);
			phalcon_array_fetch(&relations, has_one, entity_name, PH_NOISY_CC);
	
			if (!phalcon_is_iterable(relations, &ah2, &hp2, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(relation);
	
				phalcon_array_append(&all_relations, relation, PH_SEPARATE TSRMLS_CC);
	
				zend_hash_move_forward_ex(ah2, &hp2);
			}
	
		}
	}
	
	
	RETURN_CTOR(all_relations);
}

/**
 * Query the first relationship defined between two models
 *
 * @param string $first
 * @param string $second
 * @return Phalcon\Mvc\Model\RelationInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelationsBetween){

	zval *first, *second, *first_name, *second_name;
	zval *key_relation, *belongs_to, *relations = NULL;
	zval *has_many, *has_one;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &first, &second) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(first_name);
	phalcon_fast_strtolower(first_name, first);
	
	PHALCON_INIT_VAR(second_name);
	phalcon_fast_strtolower(second_name, second);
	
	PHALCON_INIT_VAR(key_relation);
	PHALCON_CONCAT_VSV(key_relation, first_name, "$", second_name);
	
	/** 
	 * Check if it's a belongs-to relationship
	 */
	PHALCON_OBS_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	if (Z_TYPE_P(belongs_to) == IS_ARRAY) { 
		if (phalcon_array_isset(belongs_to, key_relation)) {
			PHALCON_OBS_VAR(relations);
			phalcon_array_fetch(&relations, belongs_to, key_relation, PH_NOISY_CC);
			RETURN_CCTOR(relations);
		}
	}
	
	/** 
	 * Check if it's a has-many relationship
	 */
	PHALCON_OBS_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (Z_TYPE_P(has_many) == IS_ARRAY) { 
		if (phalcon_array_isset(has_many, key_relation)) {
			PHALCON_OBS_NVAR(relations);
			phalcon_array_fetch(&relations, has_many, key_relation, PH_NOISY_CC);
			RETURN_CCTOR(relations);
		}
	}
	
	/** 
	 * Check if it's a has-one relationship
	 */
	PHALCON_OBS_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if (Z_TYPE_P(has_one) == IS_ARRAY) { 
		if (phalcon_array_isset(has_one, key_relation)) {
			PHALCON_OBS_NVAR(relations);
			phalcon_array_fetch(&relations, has_one, key_relation, PH_NOISY_CC);
			RETURN_CCTOR(relations);
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Creates a Phalcon\Mvc\Model\Query without execute it
 *
 * @param string $phql
 * @return Phalcon\Mvc\Model\QueryInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, createQuery){

	zval *phql, *dependency_injector, *query;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &phql) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services");
		return;
	}
	
	/** 
	 * Create a query
	 */
	PHALCON_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "__construct", phql);
	
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "setdi", dependency_injector);
	phalcon_update_property_zval(this_ptr, SL("_lastQuery"), query TSRMLS_CC);
	
	RETURN_CTOR(query);
}

/**
 * Creates a Phalcon\Mvc\Model\Query and execute it
 *
 * @param string $phql
 * @param array $placeholders
 * @return Phalcon\Mvc\Model\QueryInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, executeQuery){

	zval *phql, *placeholders = NULL, *dependency_injector;
	zval *query, *result;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &phql, &placeholders) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!placeholders) {
		PHALCON_INIT_VAR(placeholders);
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services");
		return;
	}
	
	/** 
	 * Create a query
	 */
	PHALCON_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "__construct", phql);
	
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "setdi", dependency_injector);
	phalcon_update_property_zval(this_ptr, SL("_lastQuery"), query TSRMLS_CC);
	
	/** 
	 * Execute the query
	 */
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_METHOD_PARAMS_1(result, query, "execute", placeholders);
	
	RETURN_CCTOR(result);
}

/**
 * Creates a Phalcon\Mvc\Model\Query\Builder
 *
 * @param string $params
 * @return Phalcon\Mvc\Model\Query\BuilderInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, createBuilder){

	zval *params = NULL, *dependency_injector, *builder;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &params) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!params) {
		PHALCON_INIT_VAR(params);
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services");
		return;
	}
	
	/** 
	 * Create a query builder
	 */
	PHALCON_INIT_VAR(builder);
	object_init_ex(builder, phalcon_mvc_model_query_builder_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(builder, "__construct", params);
	
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(builder, "setdi", dependency_injector);
	
	RETURN_CTOR(builder);
}

/**
 * Returns the last query created or executed in the models manager
 *
 * @return Phalcon\Mvc\Model\QueryInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastQuery){


	RETURN_MEMBER(this_ptr, "_lastQuery");
}

