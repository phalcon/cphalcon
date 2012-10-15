
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
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"

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

PHP_METHOD(Phalcon_Mvc_Model_Manager, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_mvc_model_manager_ce, this_ptr, SL("_hasMany"), a0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	zend_update_property(phalcon_mvc_model_manager_ce, this_ptr, SL("_hasOne"), a1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a2);
	array_init(a2);
	zend_update_property(phalcon_mvc_model_manager_ce, this_ptr, SL("_belongsTo"), a2 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a3);
	array_init(a3);
	zend_update_property(phalcon_mvc_model_manager_ce, this_ptr, SL("_initialized"), a3 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Sets the DependencyInjector container
 *
 * @param Phalcon\DI $dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, setDI){

	zval *dependency_injector;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &dependency_injector) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
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
 * @return Phalcon\DI
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getDI){

	zval *dependency_injector;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	
	RETURN_CCTOR(dependency_injector);
}

/**
 * Sets the event manager
 *
 * @param Phalcon\Events\Manager $eventsManager
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
 * @return Phalcon\Events\Manager
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getEventsManager){

	zval *events_manager;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(events_manager);
	phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
	
	RETURN_CCTOR(events_manager);
}

/**
 * Initializes a model in the model manager
 *
 * @param Phalcon\Mvc\Model $model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, initialize){

	zval *model, *class_name, *initialized, *events_manager;
	zval *event_name;
	zval *t0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(class_name);
	phalcon_get_class(class_name, model TSRMLS_CC);
	
	PHALCON_INIT_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(initialized, class_name);
	if (!eval_int) {
		if (phalcon_method_exists_ex(model, SS("initialize") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_NORETURN(model, "initialize", PH_NO_CHECK);
		}
		
		PHALCON_INIT_VAR(t0);
		phalcon_read_property(&t0, this_ptr, SL("_initialized"), PH_NOISY_CC);
		phalcon_array_update_zval_bool(&t0, class_name, 1, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_initialized"), t0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_lastInitialized"), model TSRMLS_CC);
		
		PHALCON_INIT_VAR(events_manager);
		phalcon_read_property(&events_manager, this_ptr, SL("_eventsManager"), PH_NOISY_CC);
		if (Z_TYPE_P(events_manager) == IS_OBJECT) {
			PHALCON_INIT_VAR(event_name);
			ZVAL_STRING(event_name, "modelsManager:afterInitialize", 1);
			PHALCON_CALL_METHOD_PARAMS_2_NORETURN(events_manager, "fire", event_name, this_ptr, PH_NO_CHECK);
		}
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Check of a model is already initialized
 *
 * @param string $modelName
 * @return bool
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, isInitialized){

	zval *model_name, *initialized, *is_intitialized = NULL;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(initialized, model_name);
	
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	PHALCON_CPY_WRT(is_intitialized, r0);
	
	RETURN_NCTOR(is_intitialized);
}

/**
 * Get last initialized model
 *
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getLastInitialized){

	zval *initialized;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_lastInitialized"), PH_NOISY_CC);
	
	RETURN_CCTOR(initialized);
}

/**
 * Loads a model throwing an exception if it doesn't exist
 *
 * @return Phalcon\Mvc\Model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, load){

	zval *model_name, *model_exists, *model, *exception_message;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(model_exists);
	PHALCON_CALL_FUNC_PARAMS_1(model_exists, "class_exists", model_name);
	if (zend_is_true(model_exists)) {
		ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
		PHALCON_INIT_VAR(model);
		object_init_ex(model, ce0);
		PHALCON_CALL_METHOD_NORETURN(model, "__construct", PH_CHECK);
		
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
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasOne){

	zval *model, *fields, *reference_model, *referenced_fields;
	zval *options = NULL, *entity_name, *has_one, *number_fields;
	zval *number_referenced, *diferent_fields;
	zval *relation;
	zval *a0 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
		array_init(options);
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model TSRMLS_CC);
	
	PHALCON_INIT_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(has_one, entity_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_update_zval(&has_one, entity_name, &a0, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(r0);
	phalcon_array_fetch(&r0, has_one, entity_name, PH_NOISY_CC);
	eval_int = phalcon_array_isset(r0, reference_model);
	if (!eval_int) {
		if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
			PHALCON_INIT_VAR(number_fields);
			phalcon_fast_count(number_fields, fields TSRMLS_CC);
			
			PHALCON_INIT_VAR(number_referenced);
			phalcon_fast_count(number_referenced, referenced_fields TSRMLS_CC);
			
			PHALCON_INIT_VAR(diferent_fields);
			is_not_equal_function(diferent_fields, number_fields, number_referenced TSRMLS_CC);
			if (zend_is_true(diferent_fields)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
				return;
			}
		}
		
		PHALCON_INIT_VAR(relation);
		array_init(relation);
		phalcon_array_update_string(&relation, SL("fi"), &fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&relation, SL("rt"), &reference_model, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&relation, SL("rf"), &referenced_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&relation, SL("op"), &options, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_VAR(t0);
		phalcon_read_property(&t0, this_ptr, SL("_hasOne"), PH_NOISY_CC);
		phalcon_array_update_multi_2(&t0, entity_name, reference_model, &relation, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_hasOne"), t0 TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Setup a relation reverse 1-1  between two models
 *
 * @param 	Phalcon\Mvc\Model $model
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBelongsTo){

	zval *model, *fields, *reference_model, *referenced_fields;
	zval *options = NULL, *model_name, *belongs_to, *number_fields;
	zval *number_referenced, *diferent_fields;
	zval *relation;
	zval *a0 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
		array_init(options);
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, model TSRMLS_CC);
	
	PHALCON_INIT_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(belongs_to, model_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_update_zval(&belongs_to, model_name, &a0, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(r0);
	phalcon_array_fetch(&r0, belongs_to, model_name, PH_NOISY_CC);
	eval_int = phalcon_array_isset(r0, reference_model);
	if (!eval_int) {
		if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
			PHALCON_INIT_VAR(number_fields);
			phalcon_fast_count(number_fields, fields TSRMLS_CC);
			
			PHALCON_INIT_VAR(number_referenced);
			phalcon_fast_count(number_referenced, referenced_fields TSRMLS_CC);
			
			PHALCON_INIT_VAR(diferent_fields);
			is_not_equal_function(diferent_fields, number_fields, number_referenced TSRMLS_CC);
			if (zend_is_true(diferent_fields)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
				return;
			}
		}
		
		PHALCON_INIT_VAR(relation);
		array_init(relation);
		phalcon_array_update_string(&relation, SL("fi"), &fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&relation, SL("rt"), &reference_model, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&relation, SL("rf"), &referenced_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&relation, SL("op"), &options, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_VAR(t0);
		phalcon_read_property(&t0, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
		phalcon_array_update_multi_2(&t0, model_name, reference_model, &relation, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_belongsTo"), t0 TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Setup a relation 1-n between two models
 *
 * @param 	Phalcon\Mvc\Model $model
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasMany){

	zval *model, *fields, *reference_model, *referenced_fields;
	zval *options = NULL, *entity_name, *has_many, *number_fields;
	zval *number_referenced, *diferent_fields;
	zval *relation;
	zval *a0 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
		array_init(options);
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model TSRMLS_CC);
	
	PHALCON_INIT_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(has_many, entity_name);
	if (!eval_int) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		phalcon_array_update_zval(&has_many, entity_name, &a0, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(r0);
	phalcon_array_fetch(&r0, has_many, entity_name, PH_NOISY_CC);
	eval_int = phalcon_array_isset(r0, reference_model);
	if (!eval_int) {
		if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
			PHALCON_INIT_VAR(number_fields);
			phalcon_fast_count(number_fields, fields TSRMLS_CC);
			
			PHALCON_INIT_VAR(number_referenced);
			phalcon_fast_count(number_referenced, referenced_fields TSRMLS_CC);
			
			PHALCON_INIT_VAR(diferent_fields);
			is_not_equal_function(diferent_fields, number_fields, number_referenced TSRMLS_CC);
			if (zend_is_true(diferent_fields)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
				return;
			}
		}
		
		PHALCON_INIT_VAR(relation);
		array_init(relation);
		phalcon_array_update_string(&relation, SL("fi"), &fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&relation, SL("rt"), &reference_model, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&relation, SL("rf"), &referenced_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&relation, SL("op"), &options, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		PHALCON_INIT_VAR(t0);
		phalcon_read_property(&t0, this_ptr, SL("_hasMany"), PH_NOISY_CC);
		phalcon_array_update_multi_2(&t0, entity_name, reference_model, &relation, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_hasMany"), t0 TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
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
	zval *model = NULL, *belongs_to;
	zval *r0 = NULL;
	int eval_int;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model_name, &model_relation) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(initialized, model_name);
	if (!eval_int) {
		ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
		PHALCON_INIT_VAR(model);
		object_init_ex(model, ce0);
		PHALCON_CALL_METHOD_NORETURN(model, "__construct", PH_CHECK);
	}
	
	eval_int = phalcon_array_isset(initialized, model_relation);
	if (!eval_int) {
		ce1 = phalcon_fetch_class(model_relation TSRMLS_CC);
		PHALCON_INIT_NVAR(model);
		object_init_ex(model, ce1);
		PHALCON_CALL_METHOD_NORETURN(model, "__construct", PH_CHECK);
	}
	
	PHALCON_INIT_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(belongs_to, model_name);
	if (eval_int) {
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, belongs_to, model_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
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
	zval *model = NULL, *has_many;
	zval *r0 = NULL;
	int eval_int;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model_name, &model_relation) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(initialized, model_name);
	if (!eval_int) {
		ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
		PHALCON_INIT_VAR(model);
		object_init_ex(model, ce0);
		PHALCON_CALL_METHOD_NORETURN(model, "__construct", PH_CHECK);
	}
	
	eval_int = phalcon_array_isset(initialized, model_relation);
	if (!eval_int) {
		ce1 = phalcon_fetch_class(model_relation TSRMLS_CC);
		PHALCON_INIT_NVAR(model);
		object_init_ex(model, ce1);
		PHALCON_CALL_METHOD_NORETURN(model, "__construct", PH_CHECK);
	}
	
	PHALCON_INIT_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(has_many, model_name);
	if (eval_int) {
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, has_many, model_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
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
	zval *model = NULL, *has_one;
	zval *r0 = NULL;
	int eval_int;
	zend_class_entry *ce0, *ce1;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &model_name, &model_relation) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(initialized);
	phalcon_read_property(&initialized, this_ptr, SL("_initialized"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(initialized, model_name);
	if (!eval_int) {
		ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
		PHALCON_INIT_VAR(model);
		object_init_ex(model, ce0);
		PHALCON_CALL_METHOD_NORETURN(model, "__construct", PH_CHECK);
	}
	
	eval_int = phalcon_array_isset(initialized, model_relation);
	if (!eval_int) {
		ce1 = phalcon_fetch_class(model_relation TSRMLS_CC);
		PHALCON_INIT_NVAR(model);
		object_init_ex(model, ce1);
		PHALCON_CALL_METHOD_NORETURN(model, "__construct", PH_CHECK);
	}
	
	PHALCON_INIT_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(has_one, model_name);
	if (eval_int) {
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, has_one, model_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_TRUE;
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Helper method to query records based on a relation definition
 *
 * @param array $relation
 * @param string $method
 * @param Phalcon\Mvc\Model $record
 * @param array $parameters
 * @return Phalcon\Mvc\Model\Resultset\Simple
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, _getRelationRecords){

	zval *relation, *method, *record, *parameters = NULL, *placeholders = NULL;
	zval *pre_conditions = NULL, *conditions = NULL, *field = NULL, *value = NULL;
	zval *referenced_field = NULL, *condition = NULL, *i, *fields;
	zval *join_conditions, *find_params, *arguments;
	zval *reference_table, *referenced_entity;
	zval *connection_service, *call_object, *records;
	zval *r0 = NULL, *r1 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	int eval_int;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|z", &relation, &method, &record, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	if (Z_TYPE_P(parameters) == IS_ARRAY) { 
		eval_int = phalcon_array_isset_string(parameters, SS("bind"));
		if (eval_int) {
			PHALCON_INIT_VAR(placeholders);
			phalcon_array_fetch_string(&placeholders, parameters, SL("bind"), PH_NOISY_CC);
		}
	} else {
		PHALCON_INIT_NVAR(placeholders);
		array_init(placeholders);
	}
	
	PHALCON_INIT_VAR(pre_conditions);
	if (Z_TYPE_P(parameters) == IS_ARRAY) { 
		eval_int = phalcon_array_isset_long(parameters, 0);
		if (eval_int) {
			phalcon_array_fetch_long(&pre_conditions, parameters, 0, PH_NOISY_CC);
		} else {
			eval_int = phalcon_array_isset_string(parameters, SS("conditions"));
			if (eval_int) {
				PHALCON_INIT_NVAR(pre_conditions);
				phalcon_array_fetch_string(&pre_conditions, parameters, SL("conditions"), PH_NOISY_CC);
			}
		}
	} else {
		if (Z_TYPE_P(parameters) == IS_STRING) {
			PHALCON_CPY_WRT(pre_conditions, parameters);
		}
	}
	
	if (Z_TYPE_P(pre_conditions) != IS_NULL) {
		PHALCON_INIT_VAR(conditions);
		array_init(conditions);
		phalcon_array_append(&conditions, pre_conditions, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_INIT_NVAR(conditions);
		array_init(conditions);
	}
	
	PHALCON_INIT_VAR(r0);
	phalcon_array_fetch_string(&r0, relation, SL("fi"), PH_NOISY_CC);
	if (Z_TYPE_P(r0) != IS_ARRAY) { 
		PHALCON_INIT_VAR(field);
		phalcon_array_fetch_string(&field, relation, SL("fi"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(value);
		PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", field, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(referenced_field);
		phalcon_array_fetch_string(&referenced_field, relation, SL("rf"), PH_NOISY_CC);
		
		PHALCON_INIT_VAR(condition);
		PHALCON_CONCAT_VS(condition, referenced_field, " = ?0");
		phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
		phalcon_array_append(&placeholders, value, PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 0);
		
		PHALCON_INIT_VAR(fields);
		phalcon_array_fetch_string(&fields, relation, SL("fi"), PH_NOISY_CC);
		
		if (!phalcon_valid_foreach(fields TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(fields);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		
		ph_cycle_start_0:
		
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto ph_cycle_end_0;
			}
			
			PHALCON_GET_FOREACH_VALUE(field);
			
			PHALCON_INIT_NVAR(value);
			PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", field, PH_NO_CHECK);
			
			PHALCON_INIT_NVAR(r1);
			phalcon_array_fetch_string(&r1, relation, SL("rf"), PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(referenced_field);
			phalcon_array_fetch(&referenced_field, r1, i, PH_NOISY_CC);
			
			PHALCON_INIT_NVAR(condition);
			PHALCON_CONCAT_VSV(condition, referenced_field, " = ?", i);
			phalcon_array_append(&conditions, condition, PH_SEPARATE TSRMLS_CC);
			phalcon_array_append(&placeholders, value, PH_SEPARATE TSRMLS_CC);
			PHALCON_SEPARATE(i);
			increment_function(i);
			
			zend_hash_move_forward_ex(ah0, &hp0);
			goto ph_cycle_start_0;
			
		ph_cycle_end_0:
		if(0){}
		
	}
	
	PHALCON_INIT_VAR(join_conditions);
	phalcon_fast_join_str(join_conditions, SL(" AND "), conditions TSRMLS_CC);
	
	PHALCON_INIT_VAR(find_params);
	array_init(find_params);
	phalcon_array_append(&find_params, join_conditions, PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&find_params, SL("bind"), &placeholders, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(arguments);
	array_init(arguments);
	phalcon_array_append(&arguments, find_params, PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(reference_table);
	phalcon_array_fetch_string(&reference_table, relation, SL("rt"), PH_NOISY_CC);
	ce0 = phalcon_fetch_class(reference_table TSRMLS_CC);
	
	PHALCON_INIT_VAR(referenced_entity);
	object_init_ex(referenced_entity, ce0);
	PHALCON_CALL_METHOD_NORETURN(referenced_entity, "__construct", PH_CHECK);
	
	PHALCON_INIT_VAR(connection_service);
	PHALCON_CALL_METHOD(connection_service, record, "getconnectionservice", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_entity, "setconnectionservice", connection_service, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(call_object);
	array_init(call_object);
	phalcon_array_append(&call_object, referenced_entity, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&call_object, method, PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(records);
	PHALCON_CALL_FUNC_PARAMS_2(records, "call_user_func_array", call_object, arguments);
	
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
 * @return Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsToRecords){

	zval *method, *model_name, *model_relation, *record;
	zval *parameters = NULL, *belongs_to, *relation, *records;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &method, &model_name, &model_relation, &record, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	PHALCON_INIT_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(belongs_to, model_name);
	if (eval_int) {
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, belongs_to, model_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (!eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(r1);
	phalcon_array_fetch(&r1, belongs_to, model_name, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(relation);
	phalcon_array_fetch(&relation, r1, model_relation, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(records);
	PHALCON_CALL_METHOD_PARAMS_4(records, this_ptr, "_getrelationrecords", relation, method, record, parameters, PH_NO_CHECK);
	
	RETURN_CCTOR(records);
}

/**
 * Gets hasMany related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Mvc\Model $record
 * @param array $parameters
 * @return Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyRecords){

	zval *method, *model_name, *model_relation, *record;
	zval *parameters = NULL, *has_many, *relation, *records;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &method, &model_name, &model_relation, &record, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	PHALCON_INIT_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(has_many, model_name);
	if (eval_int) {
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, has_many, model_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (!eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(r1);
	phalcon_array_fetch(&r1, has_many, model_name, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(relation);
	phalcon_array_fetch(&relation, r1, model_relation, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(records);
	PHALCON_CALL_METHOD_PARAMS_4(records, this_ptr, "_getrelationrecords", relation, method, record, parameters, PH_NO_CHECK);
	
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
 * @return Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneRecords){

	zval *method, *model_name, *model_relation, *record;
	zval *parameters = NULL, *has_one, *relation, *records;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &method, &model_name, &model_relation, &record, &parameters) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!parameters) {
		PHALCON_INIT_NVAR(parameters);
	}
	
	PHALCON_INIT_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(has_one, model_name);
	if (eval_int) {
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, has_one, model_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (!eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_INIT_VAR(r1);
	phalcon_array_fetch(&r1, has_one, model_name, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(relation);
	phalcon_array_fetch(&relation, r1, model_relation, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(records);
	PHALCON_CALL_METHOD_PARAMS_4(records, this_ptr, "_getrelationrecords", relation, method, record, parameters, PH_NO_CHECK);
	
	RETURN_CCTOR(records);
}

/**
 * Gets belongsTo relations defined on a model
 *
 * @param  Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsTo){

	zval *model, *model_name, *belongs_to, *relations;
	zval *empty_array;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, model TSRMLS_CC);
	
	PHALCON_INIT_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(belongs_to, model_name);
	if (eval_int) {
		PHALCON_INIT_VAR(relations);
		phalcon_array_fetch(&relations, belongs_to, model_name, PH_NOISY_CC);
		
		RETURN_CCTOR(relations);
	}
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	
	RETURN_CTOR(empty_array);
}

/**
 * Gets hasMany relations defined on a model
 *
 * @param  Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasMany){

	zval *model, *model_name, *has_many, *relations;
	zval *empty_array;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, model TSRMLS_CC);
	
	PHALCON_INIT_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(has_many, model_name);
	if (eval_int) {
		PHALCON_INIT_VAR(relations);
		phalcon_array_fetch(&relations, has_many, model_name, PH_NOISY_CC);
		
		RETURN_CCTOR(relations);
	}
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	
	RETURN_CTOR(empty_array);
}

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOne){

	zval *model, *model_name, *has_one, *relations;
	zval *empty_array;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, model TSRMLS_CC);
	
	PHALCON_INIT_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(has_one, model_name);
	if (eval_int) {
		PHALCON_INIT_VAR(relations);
		phalcon_array_fetch(&relations, has_one, model_name, PH_NOISY_CC);
		
		RETURN_CCTOR(relations);
	}
	
	PHALCON_INIT_VAR(empty_array);
	array_init(empty_array);
	
	RETURN_CTOR(empty_array);
}

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany){

	zval *model, *has_one, *has_many, *merge;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(has_one);
	PHALCON_CALL_METHOD_PARAMS_1(has_one, this_ptr, "gethasone", model, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(has_many);
	PHALCON_CALL_METHOD_PARAMS_1(has_many, this_ptr, "gethasmany", model, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(merge);
	PHALCON_CALL_FUNC_PARAMS_2(merge, "array_merge", has_one, has_many);
	
	RETURN_CCTOR(merge);
}

/**
 * Query the relations between two models
 *
 * @param string $first
 * @param string $second
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getRelations){

	zval *first, *second, *belongs_to, *relation = NULL, *has_many;
	zval *has_one;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &first, &second) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(belongs_to, first);
	if (eval_int) {
		PHALCON_INIT_VAR(r0);
		phalcon_array_fetch(&r0, belongs_to, first, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r0, second);
		if (eval_int) {
			PHALCON_INIT_VAR(r1);
			phalcon_array_fetch(&r1, belongs_to, first, PH_NOISY_CC);
			PHALCON_INIT_VAR(relation);
			phalcon_array_fetch(&relation, r1, second, PH_NOISY_CC);
			
			RETURN_CCTOR(relation);
		}
	}
	
	PHALCON_INIT_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(has_many, first);
	if (eval_int) {
		PHALCON_INIT_VAR(r2);
		phalcon_array_fetch(&r2, has_many, first, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r2, second);
		if (eval_int) {
			PHALCON_INIT_VAR(r3);
			phalcon_array_fetch(&r3, has_many, first, PH_NOISY_CC);
			PHALCON_INIT_NVAR(relation);
			phalcon_array_fetch(&relation, r3, second, PH_NOISY_CC);
			
			RETURN_CCTOR(relation);
		}
	}
	
	PHALCON_INIT_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(has_one, first);
	if (eval_int) {
		PHALCON_INIT_VAR(r4);
		phalcon_array_fetch(&r4, has_one, first, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r4, second);
		if (eval_int) {
			PHALCON_INIT_VAR(r5);
			phalcon_array_fetch(&r5, has_one, first, PH_NOISY_CC);
			PHALCON_INIT_NVAR(relation);
			phalcon_array_fetch(&relation, r5, second, PH_NOISY_CC);
			
			RETURN_CCTOR(relation);
		}
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
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
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services");
		return;
	}
	
	PHALCON_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "__construct", phql, PH_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "setdi", dependency_injector, PH_NO_CHECK);
	
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
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!placeholders) {
		PHALCON_INIT_NVAR(placeholders);
	}
	
	PHALCON_INIT_VAR(dependency_injector);
	phalcon_read_property(&dependency_injector, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC);
	if (Z_TYPE_P(dependency_injector) != IS_OBJECT) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "A dependency injection object is required to access ORM services");
		return;
	}
	
	PHALCON_INIT_VAR(query);
	object_init_ex(query, phalcon_mvc_model_query_ce);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "__construct", phql, PH_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(query, "setdi", dependency_injector, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_METHOD_PARAMS_1(result, query, "execute", placeholders, PH_NO_CHECK);
	
	RETURN_CCTOR(result);
}

