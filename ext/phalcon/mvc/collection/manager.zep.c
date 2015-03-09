
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


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
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Mvc\Collection\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A CollectionManager is injected to a model via a Dependency Injector Container such as Phalcon\Di.
 *
 * <code>
 * $di = new \Phalcon\Di();
 *
 * $di->set('collectionManager', function(){
 *      return new \Phalcon\Mvc\Collection\Manager();
 * });
 *
 * $robot = new Robots($di);
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Collection_Manager) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Collection, Manager, phalcon, mvc_collection_manager, phalcon_mvc_collection_manager_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_dependencyInjector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_initialized"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_lastInitialized"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_customEventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_connectionServices"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_mvc_collection_manager_ce, SL("_implicitObjectsIds"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_collection_manager_ce TSRMLS_CC, 1, phalcon_di_injectionawareinterface_ce);
	zend_class_implements(phalcon_mvc_collection_manager_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);
	return SUCCESS;

}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DiInterface $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setDI) {

	zval *dependencyInjector;

	zephir_fetch_params(0, 1, 0, &dependencyInjector);



	if (!(zephir_instance_of_ev(dependencyInjector, phalcon_diinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'dependencyInjector' must be an instance of 'Phalcon\\DiInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);

}

/**
 * Returns the DependencyInjector container
 *
 * @return Phalcon\DiInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getDI) {


	RETURN_MEMBER(this_ptr, "_dependencyInjector");

}

/**
 * Sets the event manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setEventsManager) {

	zval *eventsManager;

	zephir_fetch_params(0, 1, 0, &eventsManager);



	if (!(zephir_instance_of_ev(eventsManager, phalcon_events_managerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'eventsManager' must be an instance of 'Phalcon\\Events\\ManagerInterface'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_eventsManager"), eventsManager TSRMLS_CC);

}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getEventsManager) {


	RETURN_MEMBER(this_ptr, "_eventsManager");

}

/**
 * Sets a custom events manager for a specific model
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setCustomEventsManager) {

	zval *model, *eventsManager, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &eventsManager);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_collectioninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\CollectionInterface'", "", 0);
		return;
	}
	if (!(zephir_instance_of_ev(eventsManager, phalcon_events_managerinterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'eventsManager' must be an instance of 'Phalcon\\Events\\ManagerInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, model, 0 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_customEventsManager"), _0, eventsManager TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns a custom events manager related to a model
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getCustomEventsManager) {

	zval *model, *customEventsManager, *className, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_collectioninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\CollectionInterface'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(customEventsManager);
	zephir_read_property_this(&customEventsManager, this_ptr, SL("_customEventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(customEventsManager) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(className);
		zephir_get_class(className, model, 1 TSRMLS_CC);
		if (zephir_array_isset(customEventsManager, className)) {
			zephir_array_fetch(&_0, customEventsManager, className, PH_NOISY | PH_READONLY, "phalcon/mvc/collection/manager.zep", 127 TSRMLS_CC);
			RETURN_CTOR(_0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Initializes a model in the models manager
 *
 * @param Phalcon\Mvc\CollectionInterface model
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, initialize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *className, *initialized, *eventsManager, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_collectioninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\CollectionInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(className);
	zephir_get_class(className, model, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(initialized);
	zephir_read_property_this(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (!(zephir_array_isset(initialized, className))) {
		if ((zephir_method_exists_ex(model, SS("initialize") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_CALL_METHOD(NULL, model, "initialize", NULL);
			zephir_check_call_status();
		}
		ZEPHIR_OBS_VAR(eventsManager);
		zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
			ZEPHIR_INIT_VAR(_0);
			ZVAL_STRING(_0, "collectionManager:afterInitialize", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(NULL, eventsManager, "fire", NULL, _0);
			zephir_check_temp_parameter(_0);
			zephir_check_call_status();
		}
		zephir_update_property_array(this_ptr, SL("_initialized"), className, model TSRMLS_CC);
		zephir_update_property_this(this_ptr, SL("_lastInitialized"), model TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether a model is already initialized
 *
 * @param string $modelName
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isInitialized) {

	zval *modelName, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_fast_strtolower(_1, modelName);
	if (zephir_array_isset(_0, _1)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * Get the latest initialized model
 *
 * @return Phalcon\Mvc\CollectionInterface
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getLastInitialized) {


	RETURN_MEMBER(this_ptr, "_lastInitialized");

}

/**
 * Sets a connection service for a specific model
 *
 * @param Phalcon\Mvc\CollectionInterface model
 * @param string connectionService
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setConnectionService) {

	zval *connectionService = NULL;
	zval *model, *connectionService_param = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService_param);

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


	if (!(zephir_instance_of_ev(model, phalcon_mvc_collectioninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\CollectionInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, model, 0 TSRMLS_CC);
	zephir_update_property_array(this_ptr, SL("_connectionServices"), _0, connectionService TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets whether a model must use implicit objects ids
 *
 * @param Phalcon\Mvc\CollectionInterface model
 * @param boolean useImplicitObjectIds
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, useImplicitObjectIds) {

	zend_bool useImplicitObjectIds;
	zval *model, *useImplicitObjectIds_param = NULL, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &useImplicitObjectIds_param);

	useImplicitObjectIds = zephir_get_boolval(useImplicitObjectIds_param);


	if (!(zephir_instance_of_ev(model, phalcon_mvc_collectioninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\CollectionInterface'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_get_class(_0, model, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, useImplicitObjectIds);
	zephir_update_property_array(this_ptr, SL("_implicitObjectsIds"), _0, _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a model is using implicit object ids
 *
 * @param Phalcon\Mvc\CollectionInterface model
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isUsingImplicitObjectIds) {

	zval *model, *implicit, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_collectioninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\CollectionInterface'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_implicitObjectsIds"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_get_class(_1, model, 0 TSRMLS_CC);
	if (zephir_array_isset_fetch(&implicit, _0, _1, 1 TSRMLS_CC)) {
		RETURN_CTOR(implicit);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Returns the connection related to a model
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @return \Mongo
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, getConnection) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *model, *service = NULL, *connectionService, *connection = NULL, *dependencyInjector, *entityName;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	if (!(zephir_instance_of_ev(model, phalcon_mvc_collectioninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\CollectionInterface'", "", 0);
		return;
	}
	if (Z_TYPE_P(model) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "A valid collection instance is required", "phalcon/mvc/collection/manager.zep", 246);
		return;
	}
	ZEPHIR_INIT_VAR(service);
	ZVAL_STRING(service, "mongo", 1);
	ZEPHIR_OBS_VAR(connectionService);
	zephir_read_property_this(&connectionService, this_ptr, SL("_connectionServices"), PH_NOISY_CC);
	if (Z_TYPE_P(connectionService) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(entityName);
		zephir_get_class(entityName, model, 0 TSRMLS_CC);
		if (zephir_array_isset(connectionService, entityName)) {
			ZEPHIR_OBS_NVAR(service);
			zephir_array_fetch(&service, connectionService, entityName, PH_NOISY, "phalcon/mvc/collection/manager.zep", 258 TSRMLS_CC);
		}
	}
	ZEPHIR_OBS_VAR(dependencyInjector);
	zephir_read_property_this(&dependencyInjector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependencyInjector) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "A dependency injector container is required to obtain the services related to the ORM", "phalcon/mvc/collection/manager.zep", 264);
		return;
	}
	ZEPHIR_CALL_METHOD(&connection, dependencyInjector, "getshared", NULL, service);
	zephir_check_call_status();
	if (Z_TYPE_P(connection) != IS_OBJECT) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_mvc_collection_exception_ce, "Invalid injected connection service", "phalcon/mvc/collection/manager.zep", 272);
		return;
	}
	RETURN_CCTOR(connection);

}

/**
 * Receives events generated in the models and dispatches them to a events-manager if available
 * Notify the behaviors that are listening in the model
 *
 * @param string eventName
 * @param Phalcon\Mvc\CollectionInterface model
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, notifyEvent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *eventName_param = NULL, *model, *eventsManager, *status = NULL, *customEventsManager, *_1;
	zval *eventName = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &eventName_param, &model);

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
	ZEPHIR_INIT_VAR(status);
	ZVAL_NULL(status);


	if (!(zephir_instance_of_ev(model, phalcon_mvc_collectioninterface_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'model' must be an instance of 'Phalcon\\Mvc\\CollectionInterface'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(eventsManager);
	zephir_read_property_this(&eventsManager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, "collection:", eventName);
		ZEPHIR_CALL_METHOD(&status, eventsManager, "fire", NULL, _0, model);
		zephir_check_call_status();
		if (!(zephir_is_true(status))) {
			RETURN_CCTOR(status);
		}
	}
	ZEPHIR_OBS_VAR(customEventsManager);
	zephir_read_property_this(&customEventsManager, this_ptr, SL("_customEventsManager"), PH_NOISY_CC);
	if (Z_TYPE_P(customEventsManager) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(_1);
		zephir_get_class(_1, model, 1 TSRMLS_CC);
		if (zephir_array_isset(customEventsManager, _1)) {
			ZEPHIR_INIT_LNVAR(_0);
			ZEPHIR_CONCAT_SV(_0, "collection:", eventName);
			ZEPHIR_CALL_METHOD(&status, customEventsManager, "fire", NULL, _0, model);
			zephir_check_call_status();
			if (!(zephir_is_true(status))) {
				RETURN_CCTOR(status);
			}
		}
	}
	RETURN_CCTOR(status);

}

