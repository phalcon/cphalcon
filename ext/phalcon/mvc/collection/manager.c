
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"


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
 * Phalcon\Mvc\Collection\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A CollectionManager is injected to a model via a Dependency Injector Container such as Phalcon\Di.
 *
 * <code>
 * $di = new Phalcon\Di();
 *
 * $di->set('collectionManager', function(){
 *      return new Phalcon\Mvc\Collection\Manager();
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

	zval *model, *eventsManager, *className;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &eventsManager);



	ZEPHIR_INIT_VAR(className);
	zephir_call_func_p1(className, "get_class", model);
	zephir_update_property_array(this_ptr, SL("_customEventsManager"), className, eventsManager TSRMLS_CC);
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



	customEventsManager = zephir_fetch_nproperty_this(this_ptr, SL("_customEventsManager"), PH_NOISY_CC);
	if ((Z_TYPE_P(customEventsManager) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(className);
		zephir_call_func_p1(className, "get_calls", model);
		if (zephir_array_isset(customEventsManager, className)) {
			zephir_array_fetch(&_0, customEventsManager, className, PH_NOISY | PH_READONLY TSRMLS_CC);
			RETURN_CTOR(_0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Initializes a model in the models manager
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, initialize) {

	zval *model, *className, *initialized, *eventsManager, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	ZEPHIR_INIT_VAR(className);
	zephir_call_func_p1(className, "get_class", model);
	initialized = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (!(zephir_array_isset(initialized, className))) {
		if (((zephir_method_exists_ex(model, SS("initialize") TSRMLS_CC) == SUCCESS) == true)) {
			zephir_call_method_noret(model, "initialize");
		}
		eventsManager = zephir_fetch_nproperty_this(this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		if ((Z_TYPE_P(eventsManager) == IS_OBJECT)) {
			ZEPHIR_INIT_VAR(_0);
			ZVAL_STRING(_0, "collectionManager:afterInitialize", 1);
			zephir_call_method_p1_noret(eventsManager, "fire", _0);
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

	zval *modelName, *initialized, *lowerCased;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modelName);



	initialized = zephir_fetch_nproperty_this(this_ptr, SL("_initialized"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(lowerCased);
	zephir_fast_strtolower(lowerCased, modelName);
	if (zephir_array_isset(initialized, lowerCased)) {
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
 * @param Phalcon\Mvc\CollectionInterface $model
 * @param string $connectionService
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, setConnectionService) {

	zval *model, *connectionService, *entityName;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &connectionService);



	if ((Z_TYPE_P(model) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "A valid collection instance is required");
		return;
	}
	ZEPHIR_INIT_VAR(entityName);
	zephir_call_func_p1(entityName, "get_class", model);
	zephir_update_property_array(this_ptr, SL("_connectionServices"), entityName, connectionService TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets if a model must use implicit objects ids
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @param boolean $useImplicitObjectIds
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, useImplicitObjectIds) {

	zval *model, *useImplicitObjectIds, *entityName;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &useImplicitObjectIds);



	if ((Z_TYPE_P(model) != IS_OBJECT)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_mvc_collection_exception_ce, "A valid collection instance is required");
		return;
	}
	ZEPHIR_INIT_VAR(entityName);
	zephir_call_func_p1(entityName, "get_class", model);
	zephir_update_property_array(this_ptr, SL("_implicitObjectsIds"), entityName, useImplicitObjectIds TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Checks if a model is using implicit object ids
 *
 * @param Phalcon\Mvc\CollectionInterface $model
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Collection_Manager, isUsingImplicitObjectIds) {

	zval *model;

	zephir_fetch_params(0, 1, 0, &model);




}

