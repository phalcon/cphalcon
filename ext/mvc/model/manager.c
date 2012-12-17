
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/file.h"
#include "kernel/concat.h"

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
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_aliases"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasMany"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_hasOne"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_belongsTo"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_initialized"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_model_manager_ce, SL("_lastInitialized"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
 * Sets the event manager
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
 * Initializes a model in the model manager
 *
 * @param Phalcon\Mvc\ModelInterface $model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, initialize){

	zval *model, *class_name, *initialized, *events_manager = NULL;
	zval *lowercased, *event_name, *model_base, *connection_service;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model TSRMLS_CC);
	
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
	/** 
	 * Models are just initialized once per request
	 */
	PHALCON_INIT_VAR(lowercased);
	phalcon_fast_strtolower(lowercased, class_name);
	if (!phalcon_array_isset(initialized, lowercased)) {
	
		/** 
		 * Call the 'initialize' method if it's implemented
		 */
		if (phalcon_method_exists_ex(model, SS("initialize") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_NORETURN(model, "initialize");
		}
	
		/** 
		 * If an EventsManager is available we pass it to every model initialized
		 */
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "modelsManager:afterInitialize", 1);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr);
		}
	
		phalcon_update_property_array(this_ptr, SL("_initialized"), lowercased, model TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_lastInitialized"), model TSRMLS_CC);
	} else {
		PHALCON_OBS_VAR(t0);
		phalcon_read_property(&t0, this_ptr, SL("_initialized"), PH_NOISY_CC);
		PHALCON_OBS_VAR(model_base);
		phalcon_array_fetch(&model_base, t0, lowercased, PH_NOISY_CC);
	
		/** 
		 * Pass the connection service to each new instance
		 */
		PHALCON_INIT_VAR(connection_service);
		PHALCON_CALL_METHOD(connection_service, model_base, "getconnectionservice");
		if (!PHALCON_COMPARE_STRING(connection_service, "db")) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "setconnectionservice", connection_service);
		}
	
		/** 
		 * Pass the events manager to each new instance
		 */
		PHALCON_INIT_NVAR(events_manager);
		PHALCON_CALL_METHOD(events_manager, model_base, "geteventsmanager");
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "seteventsmanager", events_manager);
		}
	}
	
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
 * @return Phalcon\Mvc\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, load){

	zval *model_name, *dependency_injector, *model;
	zval *exception_message;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (phalcon_class_exists(model_name TSRMLS_CC)) {
		PHALCON_OBS_VAR(dependency_injector);
		phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
		ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
	
		PHALCON_INIT_VAR(model);
		object_init_ex(model, ce0);
		if (phalcon_has_constructor(model TSRMLS_CC)) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(model, "__construct", dependency_injector);
		}
		RETURN_CTOR(model);
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SVS(exception_message, "The model '", model_name, "' could not be loaded");
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_model_exception_ce, exception_message);
	return;
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
	zval *options = NULL, *model_name, *entity_name, *referenced_entity;
	zval *has_one = NULL, *number_fields, *number_referenced;
	zval *diferent_fields, *type, *relation, *alias;
	zval *lower_alias = NULL, *key_alias, *_hasOne;
	zval *a0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &referenced_model, &referenced_fields, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, model TSRMLS_CC);
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_fast_strtolower(entity_name, model_name);
	
	PHALCON_INIT_VAR(referenced_entity);
	phalcon_fast_strtolower(referenced_entity, referenced_model);
	
	PHALCON_OBS_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if (Z_TYPE_P(has_one) != IS_ARRAY) { 
		PHALCON_INIT_NVAR(has_one);
		array_init(has_one);
		phalcon_update_property_zval(this_ptr, SL("_hasOne"), has_one TSRMLS_CC);
	}
	
	if (!phalcon_array_isset(has_one, entity_name)) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_update_zval(&has_one, entity_name, &a0, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_OBS_VAR(r0);
	phalcon_array_fetch(&r0, has_one, entity_name, PH_NOISY_CC);
	if (!phalcon_array_isset(r0, referenced_entity)) {
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
	
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 1);
	
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
	
		PHALCON_INIT_VAR(key_alias);
		PHALCON_CONCAT_VSV(key_alias, entity_name, "$", lower_alias);
		phalcon_update_property_array(this_ptr, SL("_aliases"), key_alias, relation TSRMLS_CC);
	
		/** 
		 * Update the relationship
		 */
		PHALCON_OBS_VAR(_hasOne);
		phalcon_read_property(&_hasOne, this_ptr, SL("_hasOne"), PH_NOISY_CC);
		phalcon_array_update_multi_2(&_hasOne, entity_name, referenced_entity, &relation, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_hasOne"), _hasOne TSRMLS_CC);
	
		RETURN_CTOR(relation);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Setup a relation reverse 1-1  between two models
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
	zval *options = NULL, *model_name, *entity_name, *referenced_entity;
	zval *belongs_to = NULL, *number_fields, *number_referenced;
	zval *diferent_fields, *type, *relation, *alias;
	zval *lower_alias = NULL, *key_alias, *_belongsTo;
	zval *a0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &referenced_model, &referenced_fields, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, model TSRMLS_CC);
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_fast_strtolower(entity_name, model_name);
	
	PHALCON_INIT_VAR(referenced_entity);
	phalcon_fast_strtolower(referenced_entity, referenced_model);
	
	PHALCON_OBS_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	if (Z_TYPE_P(belongs_to) != IS_ARRAY) { 
		PHALCON_INIT_NVAR(belongs_to);
		array_init(belongs_to);
		phalcon_update_property_zval(this_ptr, SL("_belongsTo"), belongs_to TSRMLS_CC);
	}
	
	if (!phalcon_array_isset(belongs_to, entity_name)) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_update_zval(&belongs_to, entity_name, &a0, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_OBS_VAR(r0);
	phalcon_array_fetch(&r0, belongs_to, entity_name, PH_NOISY_CC);
	if (!phalcon_array_isset(r0, referenced_entity)) {
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
	
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 0);
	
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
	
		PHALCON_INIT_VAR(key_alias);
		PHALCON_CONCAT_VSV(key_alias, entity_name, "$", lower_alias);
		phalcon_update_property_array(this_ptr, SL("_aliases"), key_alias, relation TSRMLS_CC);
	
		/** 
		 * Update the relationship
		 */
		PHALCON_OBS_VAR(_belongsTo);
		phalcon_read_property(&_belongsTo, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
		phalcon_array_update_multi_2(&_belongsTo, entity_name, referenced_entity, &relation, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_belongsTo"), _belongsTo TSRMLS_CC);
	
		RETURN_CTOR(relation);
	}
	
	RETURN_MM_FALSE;
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
	zval *options = NULL, *model_name, *entity_name, *referenced_entity;
	zval *has_many = NULL, *number_fields, *number_referenced;
	zval *diferent_fields, *type, *relation, *alias;
	zval *lower_alias = NULL, *key_alias, *_hasMany;
	zval *a0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &referenced_model, &referenced_fields, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, model TSRMLS_CC);
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_fast_strtolower(entity_name, model_name);
	
	PHALCON_INIT_VAR(referenced_entity);
	phalcon_fast_strtolower(referenced_entity, referenced_model);
	
	PHALCON_OBS_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (Z_TYPE_P(has_many) != IS_ARRAY) { 
		PHALCON_INIT_NVAR(has_many);
		array_init(has_many);
		phalcon_update_property_zval(this_ptr, SL("_hasMany"), has_many TSRMLS_CC);
	}
	
	if (!phalcon_array_isset(has_many, entity_name)) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_update_zval(&has_many, entity_name, &a0, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_OBS_VAR(r0);
	phalcon_array_fetch(&r0, has_many, entity_name, PH_NOISY_CC);
	if (!phalcon_array_isset(r0, referenced_entity)) {
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
	
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 2);
	
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
	
		PHALCON_INIT_VAR(key_alias);
		PHALCON_CONCAT_VSV(key_alias, entity_name, "$", lower_alias);
		phalcon_update_property_array(this_ptr, SL("_aliases"), key_alias, relation TSRMLS_CC);
	
		PHALCON_OBS_VAR(_hasMany);
		phalcon_read_property(&_hasMany, this_ptr, SL("_hasMany"), PH_NOISY_CC);
		phalcon_array_update_multi_2(&_hasMany, entity_name, referenced_entity, &relation, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_hasMany"), _hasMany TSRMLS_CC);
	
		RETURN_CTOR(relation);
	}
	
	RETURN_MM_FALSE;
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
	zval *entity_name, *entity_relation, *belongs_to;
	zval *r0 = NULL;

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
	 * Initialize the model first
	 */
	if (!phalcon_array_isset(initialized, entity_name)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "load", model_name);
	}
	
	PHALCON_OBS_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	if (phalcon_array_isset(belongs_to, entity_name)) {
	
		PHALCON_OBS_VAR(r0);
		phalcon_array_fetch(&r0, belongs_to, entity_name, PH_NOISY_CC);
		if (phalcon_array_isset(r0, entity_relation)) {
			RETURN_MM_TRUE;
		}
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

	zval *model_name, *model_relation, *entity_name;
	zval *entity_relation, *initialized, *has_many;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model_name, &model_relation) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(entity_name);
	phalcon_fast_strtolower(entity_name, model_name);
	
	PHALCON_INIT_VAR(entity_relation);
	phalcon_fast_strtolower(entity_relation, model_relation);
	
	/** 
	 * Initialize the model first
	 */
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (!phalcon_array_isset(initialized, entity_name)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "load", model_name);
	}
	
	PHALCON_OBS_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (phalcon_array_isset(has_many, entity_name)) {
	
		PHALCON_OBS_VAR(r0);
		phalcon_array_fetch(&r0, has_many, entity_name, PH_NOISY_CC);
		if (phalcon_array_isset(r0, entity_relation)) {
			RETURN_MM_TRUE;
		}
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

	zval *model_name, *model_relation, *entity_name;
	zval *entity_relation, *initialized, *has_one;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model_name, &model_relation) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(entity_name);
	phalcon_fast_strtolower(entity_name, model_name);
	
	PHALCON_INIT_VAR(entity_relation);
	phalcon_fast_strtolower(entity_relation, model_relation);
	
	/** 
	 * Initialize the model first
	 */
	PHALCON_OBS_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	if (!phalcon_array_isset(initialized, entity_name)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "load", model_name);
	}
	
	PHALCON_OBS_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if (Z_TYPE_P(has_one) == IS_ARRAY) { 
		if (phalcon_array_isset(has_one, entity_name)) {
	
			PHALCON_OBS_VAR(r0);
			phalcon_array_fetch(&r0, has_one, entity_name, PH_NOISY_CC);
			if (phalcon_array_isset(r0, entity_relation)) {
				RETURN_MM_TRUE;
			}
		}
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
	zval *position = NULL, *dependency_injector, *join_conditions;
	zval *find_params, *find_arguments = NULL, *arguments;
	zval *referenced_model, *referenced_entity;
	zval *type, *retrieve_method = NULL, *call_object, *records;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &relation, &method, &record, &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
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
		 * Copound relation
		 */
		PHALCON_INIT_VAR(referenced_fields);
		PHALCON_CALL_METHOD(referenced_fields, relation, "getreferencedfields");
	
		if (!phalcon_valid_foreach(fields TSRMLS_CC)) {
			return;
		}
	
		ah0 = Z_ARRVAL_P(fields);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
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
	
	PHALCON_INIT_VAR(dependency_injector);
	PHALCON_CALL_METHOD(dependency_injector, record, "getdi");
	
	/** 
	 * We don't trust the user or the database so we use bound parameters
	 */
	PHALCON_INIT_VAR(join_conditions);
	phalcon_fast_join_str(join_conditions, SL(" AND "), conditions TSRMLS_CC);
	
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
	ce0 = phalcon_fetch_class(referenced_model TSRMLS_CC);
	
	PHALCON_INIT_VAR(referenced_entity);
	object_init_ex(referenced_entity, ce0);
	if (phalcon_has_constructor(referenced_entity TSRMLS_CC)) {
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_entity, "__construct", dependency_injector);
	}
	
	/** 
	 * Check the right method to get the data
	 */
	if (Z_TYPE_P(method) == IS_NULL) {
		PHALCON_INIT_VAR(type);
		PHALCON_CALL_METHOD(type, relation, "gettype");
	
		if (phalcon_compare_strict_long(type, 0 TSRMLS_CC)) {
			PHALCON_INIT_VAR(retrieve_method);
			ZVAL_STRING(retrieve_method, "findFirst", 1);
			goto ph_end_1;
		}
	
		if (phalcon_compare_strict_long(type, 1 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(retrieve_method);
			ZVAL_STRING(retrieve_method, "findFirst", 1);
			goto ph_end_1;
		}
	
		if (phalcon_compare_strict_long(type, 2 TSRMLS_CC)) {
			PHALCON_INIT_NVAR(retrieve_method);
			ZVAL_STRING(retrieve_method, "find", 1);
			goto ph_end_1;
		}
	
		ph_end_1:
		if(0){}
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
	zval *entity_relation, *relation, *records;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &method, &model_name, &model_relation, &record, &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	PHALCON_OBS_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	if (Z_TYPE_P(belongs_to) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_fast_strtolower(entity_name, model_name);
	
		PHALCON_INIT_VAR(entity_relation);
		phalcon_fast_strtolower(entity_relation, model_relation);
		if (phalcon_array_isset(belongs_to, entity_name)) {
	
			PHALCON_OBS_VAR(r0);
			phalcon_array_fetch(&r0, belongs_to, entity_name, PH_NOISY_CC);
			if (!phalcon_array_isset(r0, entity_relation)) {
				RETURN_MM_FALSE;
			}
		}
	
		PHALCON_OBS_VAR(r1);
		phalcon_array_fetch(&r1, belongs_to, entity_name, PH_NOISY_CC);
	
		PHALCON_OBS_VAR(relation);
		phalcon_array_fetch(&relation, r1, entity_relation, PH_NOISY_CC);
	
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
	zval *relation, *records;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &method, &model_name, &model_relation, &record, &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	PHALCON_OBS_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (Z_TYPE_P(has_many) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_fast_strtolower(entity_name, model_name);
	
		PHALCON_INIT_VAR(entity_relation);
		phalcon_fast_strtolower(entity_relation, model_relation);
		if (phalcon_array_isset(has_many, entity_name)) {
	
			PHALCON_OBS_VAR(r0);
			phalcon_array_fetch(&r0, has_many, entity_name, PH_NOISY_CC);
			if (!phalcon_array_isset(r0, entity_relation)) {
				RETURN_MM_FALSE;
			}
		}
	
		PHALCON_OBS_VAR(r1);
		phalcon_array_fetch(&r1, has_many, entity_name, PH_NOISY_CC);
	
		PHALCON_OBS_VAR(relation);
		phalcon_array_fetch(&relation, r1, entity_relation, PH_NOISY_CC);
	
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
	zval *relation, *records;
	zval *r0 = NULL, *r1 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &method, &model_name, &model_relation, &record, &parameters) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	PHALCON_OBS_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if (Z_TYPE_P(has_one) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_fast_strtolower(entity_name, model_name);
	
		PHALCON_INIT_VAR(entity_relation);
		phalcon_fast_strtolower(entity_relation, model_relation);
		if (phalcon_array_isset(has_one, entity_name)) {
	
			PHALCON_OBS_VAR(r0);
			phalcon_array_fetch(&r0, has_one, entity_name, PH_NOISY_CC);
			if (!phalcon_array_isset(r0, model_relation)) {
				RETURN_MM_FALSE;
			}
		}
	
		PHALCON_OBS_VAR(r1);
		phalcon_array_fetch(&r1, has_one, entity_name, PH_NOISY_CC);
	
		PHALCON_OBS_VAR(relation);
		phalcon_array_fetch(&relation, r1, entity_relation, PH_NOISY_CC);
	
		PHALCON_INIT_VAR(records);
		PHALCON_CALL_METHOD_PARAMS_4(records, this_ptr, "getrelationrecords", relation, method, record, parameters);
	
		RETURN_CCTOR(records);
	}
	
	RETURN_MM_FALSE;
}

/**
 * Gets belongsTo relations defined on a model
 *
 * @param  Phalcon\Mvc\ModelInterface $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsTo){

	zval *model, *belongs_to, *model_name, *entity_name;
	zval *relations, *empty_array;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	if (Z_TYPE_P(belongs_to) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(model_name);
		phalcon_get_class(model_name, model TSRMLS_CC);
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_fast_strtolower(entity_name, model_name);
		if (phalcon_array_isset(belongs_to, entity_name)) {
			PHALCON_OBS_VAR(relations);
			phalcon_array_fetch(&relations, belongs_to, entity_name, PH_NOISY_CC);
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
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasMany){

	zval *model, *has_many, *model_name, *entity_name;
	zval *relations, *empty_array;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (Z_TYPE_P(has_many) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(model_name);
		phalcon_get_class(model_name, model TSRMLS_CC);
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_fast_strtolower(entity_name, model_name);
		if (phalcon_array_isset(has_many, entity_name)) {
			PHALCON_OBS_VAR(relations);
			phalcon_array_fetch(&relations, has_many, entity_name, PH_NOISY_CC);
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

	zval *model, *has_one, *model_name, *entity_name;
	zval *relations, *empty_array;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if (Z_TYPE_P(has_one) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(model_name);
		phalcon_get_class(model_name, model TSRMLS_CC);
	
		PHALCON_INIT_VAR(entity_name);
		phalcon_fast_strtolower(entity_name, model_name);
		if (phalcon_array_isset(has_one, entity_name)) {
			PHALCON_OBS_VAR(relations);
			phalcon_array_fetch(&relations, has_one, entity_name, PH_NOISY_CC);
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
 * Query the first relationship defined between two models
 *
 * @param string $first
 * @param string $second
 * @return Phalcon\Mvc\RelationInterface
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelations){

	zval *first, *second, *first_name, *second_name;
	zval *belongs_to, *relation = NULL, *has_many, *has_one;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &first, &second) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(first_name);
	phalcon_fast_strtolower(first_name, first);
	
	PHALCON_INIT_VAR(second_name);
	phalcon_fast_strtolower(second_name, second);
	
	PHALCON_OBS_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	if (Z_TYPE_P(belongs_to) == IS_ARRAY) { 
		if (phalcon_array_isset(belongs_to, first_name)) {
	
			PHALCON_OBS_VAR(r0);
			phalcon_array_fetch(&r0, belongs_to, first_name, PH_NOISY_CC);
			if (phalcon_array_isset(r0, second_name)) {
				PHALCON_OBS_VAR(r1);
				phalcon_array_fetch(&r1, belongs_to, first_name, PH_NOISY_CC);
				PHALCON_OBS_VAR(relation);
				phalcon_array_fetch(&relation, r1, second_name, PH_NOISY_CC);
				RETURN_CCTOR(relation);
			}
		}
	}
	
	PHALCON_OBS_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	if (Z_TYPE_P(has_many) == IS_ARRAY) { 
		if (phalcon_array_isset(has_many, first_name)) {
	
			PHALCON_OBS_VAR(r2);
			phalcon_array_fetch(&r2, has_many, first_name, PH_NOISY_CC);
			if (phalcon_array_isset(r2, second_name)) {
				PHALCON_OBS_VAR(r3);
				phalcon_array_fetch(&r3, has_many, first_name, PH_NOISY_CC);
				PHALCON_OBS_NVAR(relation);
				phalcon_array_fetch(&relation, r3, second_name, PH_NOISY_CC);
				RETURN_CCTOR(relation);
			}
		}
	}
	
	PHALCON_OBS_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	if (Z_TYPE_P(has_one) == IS_ARRAY) { 
		if (phalcon_array_isset(has_one, first_name)) {
	
			PHALCON_OBS_VAR(r4);
			phalcon_array_fetch(&r4, has_one, first_name, PH_NOISY_CC);
			if (phalcon_array_isset(r4, second_name)) {
				PHALCON_OBS_VAR(r5);
				phalcon_array_fetch(&r5, has_one, first_name, PH_NOISY_CC);
				PHALCON_OBS_NVAR(relation);
				phalcon_array_fetch(&relation, r5, second_name, PH_NOISY_CC);
				RETURN_CCTOR(relation);
			}
		}
	}
	
	RETURN_MM_FALSE;
}

/**
 * Creates a Phalcon\Mvc\Model\Query without execute it
 *
 * @param string $phql
 * @return Phalcon\Mvc\Model\Query
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
	
	PHALCON_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "__construct", phql);
	
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "setdi", dependency_injector);
	
	RETURN_CTOR(query);
}

/**
 * Creates a Phalcon\Mvc\Model\Query and execute it
 *
 * @param string $phql
 * @param array $placeholders
 * @return Phalcon\Mvc\Model\Query
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, executeQuery){

	zval *phql, *placeholders = NULL, *dependency_injector;
	zval *query, *result;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &phql, &placeholders) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!placeholders) {
		PHALCON_INIT_NVAR(placeholders);
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services");
		return;
	}
	
	PHALCON_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "__construct", phql);
	
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "setdi", dependency_injector);
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_METHOD_PARAMS_1(result, query, "execute", placeholders);
	
	RETURN_CCTOR(result);
}

/**
 * Creates a Phalcon\Mvc\Model\Query\Builder
 *
 * @param string $params
 * @return Phalcon\Mvc\Model\Query\Builder
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, createBuilder){

	zval *params = NULL, *dependency_injector, *query;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &params) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!params) {
		PHALCON_INIT_NVAR(params);
	}
	
	PHALCON_OBS_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services");
		return;
	}
	
	PHALCON_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_builder_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "__construct", params);
	
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "setdi", dependency_injector);
	
	RETURN_CTOR(query);
}

