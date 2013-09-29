
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
  |          Kenji Minamoto <kenji.minamoto@gmail.com>                     |
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
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Mvc\Collection\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A CollectionManager is injected to a model via a Dependency Injector Container such as Phalcon\DI.
 *
 * <code>
 * $di = new Phalcon\DI();
 *
 * $di->set('collectionManager', function(){
 *      return new Phalcon\Mvc\Collection\Manager();
 * });
 *
 * $robot = new Robots($di);
 * </code>
 */


/**
 * Phalcon\Mvc\Collection\Manager initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_Manager){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\Collection, Manager, mvc_collection_manager, phalcon_mvc_collection_manager_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_initialized"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_lastInitialized"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_customEventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_connectionServices"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_implicitObjectsIds"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_collection_manager_ce TSRMLS_CC, 3, phalcon_di_injectionawareinterface_ce, phalcon_events_eventsawareinterface_ce, phalcon_mvc_collection_managerinterface_ce);

	return SUCCESS;
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setDI){

	zval *dependency_injector;

	phalcon_fetch_params(0, 1, 0, &dependency_injector);
	
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_mvc_model_exception_ce, "The dependency injector is invalid");
		return;
	}
	phalcon_update_property_this(this_ptr, SL("_dependencyInjector"), dependency_injector TSRMLS_CC);
	
}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getDI){


	RETURN_MEMBER(this_ptr, "_dependencyInjector");
}

/**
 * Sets the event manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setEventsManager){

	zval *events_manager;

	phalcon_fetch_params(0, 1, 0, &events_manager);
	
	phalcon_update_property_this(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getEventsManager){


	RETURN_MEMBER(this_ptr, "_eventsManager");
}

/**
 * Sets a custom events manager for a specific model
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setCustomEventsManager){

	zval *model, *events_manager, *class_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &events_manager);
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_customEventsManager"), class_name, events_manager TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a custom events manager related to a model
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getCustomEventsManager){

	zval *model, *custom_events_manager, *class_name;
	zval *events_manager;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_OBS_VAR(custom_events_manager);
	phalcon_read_property_this(&custom_events_manager, this_ptr, SL("_customEventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(custom_events_manager) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(class_name);
		phalcon_get_class(class_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset_fetch(&events_manager, custom_events_manager, class_name)) {
			RETURN_CTOR(events_manager);
		}
	}
	
	RETURN_MM_NULL();
}

/**
 * Initializes a model in the models manager
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, initialize){

	zval *model, *class_name, *initialized, *events_manager;
	zval *event_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model, 1 TSRMLS_CC);
	
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	
	/** 
	 * Models are just initialized once per request
	 */
	if (!phalcon_array_isset(initialized, class_name)) {
	
		/** 
		 * Call the 'initialize' method if it's implemented
		 */
		if (phalcon_method_exists_ex(model, SS("initialize") TSRMLS_CC) == SUCCESS) {
			phalcon_call_method_noret(model, "initialize");
		}
	
		/** 
		 * If an EventsManager is available we pass to it every initialized model
		 */
		PHALCON_OBS_VAR(events_manager);
		phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "collectionManager:afterInitialize", 1);
			phalcon_call_method_p2_noret(events_manager, "fire", event_name, this_ptr);
		}
	
		phalcon_update_property_array(this_ptr, SL("_initialized"), class_name, model TSRMLS_CC);
		phalcon_update_property_this(this_ptr, SL("_lastInitialized"), model TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Check whether a model is already initialized
 *
 * @param string $modelName
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isInitialized){

	zval *model_name, *initialized, *lowercased;

	phalcon_fetch_params(0, 1, 0, &model_name);
	
	initialized = phalcon_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	
	ALLOC_INIT_ZVAL(lowercased);
	phalcon_fast_strtolower(lowercased, model_name);
	
	RETVAL_BOOL(phalcon_array_isset(initialized, lowercased));
	zval_ptr_dtor(&lowercased);
}

/**
 * Get the latest initialized model
 *
 * @return Phalcon\Mvc\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getLastInitialized){


	RETURN_MEMBER(this_ptr, "_lastInitialized");
}

/**
 * Sets a connection service for a specific model
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @param string $connectionService
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setConnectionService){

	zval *model, *connection_service, *entity_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &connection_service);
	
	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "A valid collection instance is required");
		return;
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_connectionServices"), entity_name, connection_service TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets if a model must use implicit objects ids
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @param boolean $useImplicitObjectIds
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, useImplicitObjectIds){

	zval *model, *use_implicit_object_ids, *entity_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &model, &use_implicit_object_ids);
	
	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "A valid collection instance is required");
		return;
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_implicitObjectsIds"), entity_name, use_implicit_object_ids TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Checks if a model is using implicit object ids
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isUsingImplicitObjectIds){

	zval *model, *entity_name, *implicit_objects_ids;
	zval *implicit;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "A valid collection instance is required");
		return;
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
	/** 
	 * All collections use by default are using implicit object ids
	 */
	PHALCON_OBS_VAR(implicit_objects_ids);
	phalcon_read_property_this(&implicit_objects_ids, this_ptr, SL("_implicitObjectsIds"), PH_NOISY_CC);
	if (phalcon_array_isset_fetch(&implicit, implicit_objects_ids, entity_name)) {
		RETURN_CTOR(implicit);
	}
	
	RETURN_MM_TRUE;
}

/**
 * Returns the connection related to a model
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @return Phalcon\Db\AdapterInterface(?) MongoDB
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getConnection){

	zval *model, *service = NULL, *connection_services;
	zval *entity_name, *dependency_injector, *connection;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);
	
	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "A valid collection instance is required");
		return;
	}
	
	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "mongo", 1);
	
	PHALCON_OBS_VAR(connection_services);
	phalcon_read_property_this(&connection_services, this_ptr, SL("_connectionServices"), PH_NOISY_CC);
	if (Z_TYPE_P(connection_services) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
	
		/** 
		 * Check if the model has a custom connection service
		 */
		if (phalcon_array_isset(connection_services, entity_name)) {
			PHALCON_OBS_NVAR(service);
			phalcon_array_fetch(&service, connection_services, entity_name, PH_NOISY);
		}
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property_this(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injector container is required to obtain the services related to the ORM");
		return;
	}
	
	/** 
	 * Request the connection service from the DI
	 */
	PHALCON_INIT_VAR(connection);
	phalcon_call_method_p1(connection, dependency_injector, "getshared", service);
	if (Z_TYPE_P(connection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Invalid injected connection service");
		return;
	}
	
	/* PHALCON_VERIFY_INTERFACE(connection, phalcon_db_adapterinterface_ce); */
	RETURN_CCTOR(connection);
}

/**
 * Receives events generated in the models and dispatches them to a events-manager if available
 * Notify the behaviors that are listening in the model
 *
 * @param string $eventName
 * @param Phalcon\Mvc\CollectionInterface $model
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, notifyEvent){

	zval *event_name, *model, *status = NULL, *events_manager;
	zval *fire_event_name = NULL, *custom_events_manager;
	zval *entity_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &event_name, &model);
	
	PHALCON_INIT_VAR(status);
	
	/** 
	 * Dispatch events to the global events manager
	 */
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
	
		PHALCON_INIT_VAR(fire_event_name);
		PHALCON_CONCAT_SV(fire_event_name, "collection:", event_name);
	
		phalcon_call_method_p2(status, events_manager, "fire", fire_event_name, model);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_CCTOR(status);
		}
	}
	
	/** 
	 * A model can has a specific events manager for it
	 */
	PHALCON_OBS_VAR(custom_events_manager);
	phalcon_read_property_this(&custom_events_manager, this_ptr, SL("_customEventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(custom_events_manager) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(custom_events_manager, entity_name)) {
	
			PHALCON_INIT_NVAR(fire_event_name);
			PHALCON_CONCAT_SV(fire_event_name, "collection:", event_name);
	
			PHALCON_INIT_NVAR(status);
			phalcon_call_method_p2(status, custom_events_manager, "fire", fire_event_name, model);
			if (PHALCON_IS_FALSE(status)) {
				RETURN_CCTOR(status);
			}
		}
	}
	
	RETURN_CCTOR(status);
}

