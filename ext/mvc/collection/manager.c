
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "mvc/collection/manager.h"
#include "mvc/collection/managerinterface.h"
#include "mvc/collection/exception.h"
#include "mvc/collectioninterface.h"
#include "diinterface.h"
#include "di/injectable.h"
#include "events/eventsawareinterface.h"
#include "events/managerinterface.h"

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
zend_class_entry *phalcon_mvc_collection_manager_ce;

PHP_METHOD(Phalcon_Mvc_Collection_Manager, setCustomEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getCustomEventsManager);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, initialize);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isInitialized);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getLastInitialized);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setConnectionService);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, useImplicitObjectIds);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isUsingImplicitObjectIds);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setStrictMode);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isStrictMode);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getConnection);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, notifyEvent);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setSource);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getSource);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setColumnMap);
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getColumnMap);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_setsource, 0, 0, 2)
	ZEND_ARG_INFO(0, collection)
	ZEND_ARG_INFO(0, source)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_getsource, 0, 0, 1)
	ZEND_ARG_INFO(0, collection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_setcolumnmap, 0, 0, 2)
	ZEND_ARG_INFO(0, collection)
	ZEND_ARG_INFO(0, schema)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_collection_manager_getcolumnmap, 0, 0, 1)
	ZEND_ARG_INFO(0, collection)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_collection_manager_method_entry[] = {
	PHP_ME(Phalcon_Mvc_Collection_Manager, setCustomEventsManager, arginfo_phalcon_mvc_collection_managerinterface_setcustomeventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getCustomEventsManager, arginfo_phalcon_mvc_collection_managerinterface_getcustomeventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, initialize, arginfo_phalcon_mvc_collection_managerinterface_initialize, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, isInitialized, arginfo_phalcon_mvc_collection_managerinterface_isinitialized, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getLastInitialized, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, setConnectionService, arginfo_phalcon_mvc_collection_managerinterface_setconnectionservice, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, useImplicitObjectIds, arginfo_phalcon_mvc_collection_managerinterface_useimplicitobjectids, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, isUsingImplicitObjectIds, arginfo_phalcon_mvc_collection_managerinterface_isusingimplicitobjectids, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, setStrictMode, arginfo_phalcon_mvc_collection_managerinterface_setstrictmode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, isStrictMode, arginfo_phalcon_mvc_collection_managerinterface_isstrictmode, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getConnection, arginfo_phalcon_mvc_collection_managerinterface_getconnection, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, notifyEvent, arginfo_phalcon_mvc_collection_managerinterface_notifyevent, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, setSource, arginfo_phalcon_mvc_collection_manager_setsource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getSource, arginfo_phalcon_mvc_collection_manager_getsource, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, setColumnMap, arginfo_phalcon_mvc_collection_manager_setcolumnmap, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Collection_Manager, getColumnMap, arginfo_phalcon_mvc_collection_manager_getcolumnmap, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\Collection\Manager initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_Collection_Manager){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Mvc\\Collection, Manager, mvc_collection_manager, phalcon_di_injectable_ce, phalcon_mvc_collection_manager_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_initialized"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_lastInitialized"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_customEventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_connectionServices"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_implicitObjectsIds"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_strictModes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_sources"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_columnMaps"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_collection_manager_ce TSRMLS_CC, 1, phalcon_mvc_collection_managerinterface_ce);

	return SUCCESS;
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
	PHALCON_VERIFY_INTERFACE_EX(model, phalcon_mvc_collectioninterface_ce, phalcon_mvc_collection_exception_ce, 1);
	PHALCON_VERIFY_INTERFACE_OR_NULL_EX(events_manager, phalcon_events_managerinterface_ce, phalcon_mvc_collection_exception_ce, 1);

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

	custom_events_manager = phalcon_fetch_nproperty_this(this_ptr, SL("_customEventsManager"), PH_NOISY TSRMLS_CC);
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
	phalcon_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY TSRMLS_CC);

	/** 
	 * Models are just initialized once per request
	 */
	if (!phalcon_array_isset(initialized, class_name)) {

		/** 
		 * Call the 'initialize' method if it's implemented
		 */
		if (phalcon_method_exists_ex(model, SS("initialize") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD(NULL, model, "initialize");
		}

		/** 
		 * If an EventsManager is available we pass to it every initialized model
		 */
		PHALCON_OBS_VAR(events_manager);
		phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "collectionManager:afterInitialize", 1);
			PHALCON_CALL_METHOD(NULL, events_manager, "fire", event_name, this_ptr);
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

	initialized = phalcon_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY TSRMLS_CC);

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
	phalcon_read_property_this(&implicit_objects_ids, this_ptr, SL("_implicitObjectsIds"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&implicit, implicit_objects_ids, entity_name)) {
		RETURN_CTOR(implicit);
	}

	RETURN_MM_TRUE;
}

/**
 * Sets if a model strict mode
 *
 * @param Phalcon\Mvc\CollectionInterface $collection
 * @param boolean $strictMode
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setStrictMode){

	zval *collection, *strict_mode, *entity_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &collection, &strict_mode);

	if (Z_TYPE_P(collection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "A valid collection instance is required");
		return;
	}

	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, collection, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_strictModes"), entity_name, strict_mode TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets if a model strict mode
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isStrictMode){

	zval *collection, *entity_name, *strict_modes;
	zval *strict_mode;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &collection);

	if (Z_TYPE_P(collection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "A valid collection instance is required");
		return;
	}

	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, collection, 1 TSRMLS_CC);

	/** 
	 * All collections use by default are using implicit object ids
	 */
	PHALCON_OBS_VAR(strict_modes);
	phalcon_read_property_this(&strict_modes, this_ptr, SL("_strictModes"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&strict_mode, strict_modes, entity_name)) {
		RETURN_CTOR(strict_mode);
	}

	RETURN_MM_TRUE;
}

/**
 * Returns the connection related to a model
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @return MongoDB
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getConnection){

	zval *model, *service = NULL, *connection_services;
	zval *entity_name, *dependency_injector = NULL, *has = NULL, *connection = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &model);

	if (Z_TYPE_P(model) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "A valid collection instance is required");
		return;
	}

	PHALCON_INIT_VAR(service);
	ZVAL_STRING(service, "mongo", 1);

	PHALCON_OBS_VAR(connection_services);
	phalcon_read_property_this(&connection_services, this_ptr, SL("_connectionServices"), PH_NOISY TSRMLS_CC);
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

	PHALCON_CALL_METHOD(&dependency_injector, this_ptr, "getdi");

	PHALCON_CALL_METHOD(&has, dependency_injector, "has", service);
	if (zend_is_true(has)) {
		/** 
		 * Request the connection service from the DI
		 */
		PHALCON_CALL_METHOD(&connection, dependency_injector, "getshared", service);
		if (Z_TYPE_P(connection) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid injected connection service");
			return;
		}

		/* PHALCON_VERIFY_INTERFACE(connection, phalcon_db_adapterinterface_ce); */
		RETURN_CCTOR(connection);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Invalid injected connection service");
		return;
	}
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
	phalcon_read_property_this(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {

		PHALCON_INIT_VAR(fire_event_name);
		PHALCON_CONCAT_SV(fire_event_name, "collection:", event_name);

		PHALCON_CALL_METHOD(&status, events_manager, "fire", fire_event_name, model);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_CCTOR(status);
		}
	}

	/** 
	 * A model can has a specific events manager for it
	 */
	PHALCON_OBS_VAR(custom_events_manager);
	phalcon_read_property_this(&custom_events_manager, this_ptr, SL("_customEventsManager"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(custom_events_manager) == IS_ARRAY) { 

		PHALCON_INIT_VAR(entity_name);
		phalcon_get_class(entity_name, model, 1 TSRMLS_CC);
		if (phalcon_array_isset(custom_events_manager, entity_name)) {

			PHALCON_INIT_NVAR(fire_event_name);
			PHALCON_CONCAT_SV(fire_event_name, "collection:", event_name);

			PHALCON_CALL_METHOD(&status, custom_events_manager, "fire", fire_event_name, model);
			if (PHALCON_IS_FALSE(status)) {
				RETURN_CCTOR(status);
			}
		}
	}

	RETURN_CCTOR(status);
}

/**
 * Sets the mapped source for a collection
 *
 * @param Phalcon\Mvc\Collection $collection
 * @param string $source
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setSource){

	zval *collection, *source, *entity_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &collection, &source);

	if (Z_TYPE_P(collection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Collection is not an object");
		return;
	}

	if (Z_TYPE_P(source) != IS_STRING) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Source must be a string");
		return;
	}

	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, collection, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_sources"), entity_name, source TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Returns the mapped source for a collection
 *
 * @param Phalcon\Mvc\Collection $collection
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getSource){

	zval *collection, *entity_name, *sources, *source = NULL, *class_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &collection);

	if (Z_TYPE_P(collection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Collection is not an object");
		return;
	}

	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, collection, 1 TSRMLS_CC);

	PHALCON_OBS_VAR(sources);
	phalcon_read_property_this(&sources, this_ptr, SL("_sources"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(sources) == IS_ARRAY) { 
		if (phalcon_array_isset(sources, entity_name)) {
			PHALCON_OBS_VAR(source);
			phalcon_array_fetch(&source, sources, entity_name, PH_NOISY);
			RETURN_CTOR(source);
		}
	}

	PHALCON_INIT_VAR(class_name);
	phalcon_get_class_ns(class_name, collection, 0 TSRMLS_CC);

	PHALCON_INIT_NVAR(source);
	phalcon_uncamelize(source, class_name);
	phalcon_update_property_array(this_ptr, SL("_sources"), entity_name, source TSRMLS_CC);

	RETURN_CTOR(source);
}

/**
 * Sets the column map for a collection
 *
 * @param Phalcon\Mvc\Collection $collection
 * @param array $columnMap
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setColumnMap){

	zval *collection, *column_map, *entity_name;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &collection, &column_map);

	if (Z_TYPE_P(collection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Collection is not an object");
		return;
	}

	if (Z_TYPE_P(column_map) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "ColumnMap must be an array");
		return;
	}

	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, collection, 1 TSRMLS_CC);
	phalcon_update_property_array(this_ptr, SL("_columnMaps"), entity_name, column_map TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Returns the column map for a collection
 *
 * @param Phalcon\Mvc\Collection $collection
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getColumnMap){

	zval *collection, *entity_name, *column_maps, *column_map = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &collection);

	if (Z_TYPE_P(collection) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "Collection is not an object");
		return;
	}

	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, collection, 1 TSRMLS_CC);

	PHALCON_OBS_VAR(column_maps);
	phalcon_read_property_this(&column_maps, this_ptr, SL("_columnMaps"), PH_NOISY TSRMLS_CC);
	if (Z_TYPE_P(column_maps) == IS_ARRAY) { 
		if (phalcon_array_isset(column_maps, entity_name)) {
			PHALCON_OBS_VAR(column_map);
			phalcon_array_fetch(&column_map, column_maps, entity_name, PH_NOISY);
			RETURN_CTOR(column_map);
		}
	}

	RETURN_MM_NULL();
}
