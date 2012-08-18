
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

#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\Model\Manager
 *
 * This components controls the initialization of models, keeping record of relations
 * between the different models of the application.
 *
 * A ModelsManager is injected to a model via a Dependency Injector Container such as Phalcon\DI.
 *
 * 
 */

PHP_METHOD(Phalcon_Mvc_Model_Manager, __construct){

	zval *a0 = NULL, *a1 = NULL, *a2 = NULL, *a3 = NULL;

	PHALCON_MM_GROW();

	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_mvc_model_manager_ce, this_ptr, SL("_hasMany"), a0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a1);
	array_init(a1);
	zend_update_property(phalcon_mvc_model_manager_ce, this_ptr, SL("_hasOne"), a1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a2);
	array_init(a2);
	zend_update_property(phalcon_mvc_model_manager_ce, this_ptr, SL("_belongsTo"), a2 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(a3);
	array_init(a3);
	zend_update_property(phalcon_mvc_model_manager_ce, this_ptr, SL("_initialized"), a3 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Initializes a model in the model manager
 *
 * @param Phalcon\Mvc\Model $model
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, initialize){

	zval *model = NULL, *class_name = NULL, *initialized = NULL;
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
		if (phalcon_method_exists_ex(model, SL("initialize") TSRMLS_CC) == SUCCESS) {
			PHALCON_CALL_METHOD_NORETURN(model, "initialize", PH_NO_CHECK);
		}
		
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_initialized"), PH_NOISY_CC);
		phalcon_array_update_zval_bool(&t0, class_name, 1, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_initialized"), t0 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

PHP_METHOD(Phalcon_Mvc_Model_Manager, isInitialized){

	zval *model_name = NULL, *initialized = NULL;
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
	
	RETURN_NCTOR(r0);
}

PHP_METHOD(Phalcon_Mvc_Model_Manager, load){

	zval *model_name = NULL, *model_exists = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model_name) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_CPY_WRT(model_exists, model_name);
	if (zend_is_true(model_exists)) {
		ce0 = phalcon_fetch_class(model_name TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, ce0);
		PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PH_CHECK);
		
		RETURN_CTOR(i0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, phalcon_mvc_model_exception_ce);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_SVS(r0, "The model '", model_name, "' could not be loaded");
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", r0, PH_CHECK);
	phalcon_throw_exception(i1 TSRMLS_CC);
	return;
}

/**
 * Setup a 1-1 relation between two models
 *
 * @param Phalcon\Mvc\Model $model
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasOne){

	zval *model = NULL, *fields = NULL, *reference_model = NULL, *referenced_fields = NULL;
	zval *options = NULL, *entity_name = NULL, *number_fields = NULL;
	zval *number_referenced = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
		array_init(options);
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, entity_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_hasOne"), PH_NOISY_CC);
		phalcon_array_update_zval(&t1, entity_name, &a0, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_hasOne"), t1 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch(&r0, t2, entity_name, PH_NOISY_CC);
	eval_int = phalcon_array_isset(r0, reference_model);
	if (!eval_int) {
		if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
			PHALCON_INIT_VAR(number_fields);
			phalcon_fast_count(number_fields, fields TSRMLS_CC);
			
			PHALCON_INIT_VAR(number_referenced);
			phalcon_fast_count(number_referenced, referenced_fields TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(r1);
			is_not_equal_function(r1, number_fields, number_referenced TSRMLS_CC);
			if (zend_is_true(r1)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
				return;
			}
		}
		
		PHALCON_ALLOC_ZVAL_MM(a1);
		array_init(a1);
		phalcon_array_update_string(&a1, SL("fi"), &fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a1, SL("rt"), &reference_model, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a1, SL("rf"), &referenced_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a1, SL("op"), &options, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, SL("_hasOne"), PH_NOISY_CC);
		phalcon_array_update_multi_2(&t3, entity_name, reference_model, &a1, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_hasOne"), t3 TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Setup a relation reverse 1-1  between two models
 *
 * @param Phalcon\Mvc\Model $model
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addBelongsTo){

	zval *model = NULL, *fields = NULL, *reference_model = NULL, *referenced_fields = NULL;
	zval *options = NULL, *model_name = NULL, *number_fields = NULL, *number_referenced = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
		array_init(options);
	}
	
	PHALCON_INIT_VAR(model_name);
	phalcon_get_class(model_name, model TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, model_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
		phalcon_array_update_zval(&t1, model_name, &a0, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_belongsTo"), t1 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch(&r0, t2, model_name, PH_NOISY_CC);
	eval_int = phalcon_array_isset(r0, reference_model);
	if (!eval_int) {
		if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
			PHALCON_INIT_VAR(number_fields);
			phalcon_fast_count(number_fields, fields TSRMLS_CC);
			
			PHALCON_INIT_VAR(number_referenced);
			phalcon_fast_count(number_referenced, referenced_fields TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(r1);
			is_not_equal_function(r1, number_fields, number_referenced TSRMLS_CC);
			if (zend_is_true(r1)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
				return;
			}
		}
		
		PHALCON_ALLOC_ZVAL_MM(a1);
		array_init(a1);
		phalcon_array_update_string(&a1, SL("fi"), &fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a1, SL("rt"), &reference_model, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a1, SL("rf"), &referenced_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a1, SL("op"), &options, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
		phalcon_array_update_multi_2(&t3, model_name, reference_model, &a1, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_belongsTo"), t3 TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Setup a relation 1-n between two models
 *
 * @param Phalcon\Mvc\Model $model
 * @param mixed $fields
 * @param string $referenceModel
 * @param mixed $referencedFields
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, addHasMany){

	zval *model = NULL, *fields = NULL, *reference_model = NULL, *referenced_fields = NULL;
	zval *options = NULL, *entity_name = NULL, *number_fields = NULL;
	zval *number_referenced = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz|z", &model, &fields, &reference_model, &referenced_fields, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
		array_init(options);
	}
	
	PHALCON_INIT_VAR(entity_name);
	phalcon_get_class(entity_name, model TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(t0, entity_name);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(a0);
		array_init(a0);
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, this_ptr, SL("_hasMany"), PH_NOISY_CC);
		phalcon_array_update_zval(&t1, entity_name, &a0, PH_COPY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_hasMany"), t1 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch(&r0, t2, entity_name, PH_NOISY_CC);
	eval_int = phalcon_array_isset(r0, reference_model);
	if (!eval_int) {
		if (Z_TYPE_P(referenced_fields) == IS_ARRAY) { 
			PHALCON_INIT_VAR(number_fields);
			phalcon_fast_count(number_fields, fields TSRMLS_CC);
			
			PHALCON_INIT_VAR(number_referenced);
			phalcon_fast_count(number_referenced, referenced_fields TSRMLS_CC);
			
			PHALCON_ALLOC_ZVAL_MM(r1);
			is_not_equal_function(r1, number_fields, number_referenced TSRMLS_CC);
			if (zend_is_true(r1)) {
				PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_model_exception_ce, "Number of referenced fields are not the same");
				return;
			}
		}
		
		PHALCON_ALLOC_ZVAL_MM(a1);
		array_init(a1);
		phalcon_array_update_string(&a1, SL("fi"), &fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a1, SL("rt"), &reference_model, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a1, SL("rf"), &referenced_fields, PH_COPY | PH_SEPARATE TSRMLS_CC);
		phalcon_array_update_string(&a1, SL("op"), &options, PH_COPY | PH_SEPARATE TSRMLS_CC);
		
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, SL("_hasMany"), PH_NOISY_CC);
		phalcon_array_update_multi_2(&t3, entity_name, reference_model, &a1, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_hasMany"), t3 TSRMLS_CC);
		PHALCON_MM_RESTORE();
		RETURN_TRUE;
	}
	
	PHALCON_MM_RESTORE();
	RETURN_FALSE;
}

/**
 * Checks whether a model has a belongsTo relation with another model
 *
 * @param string $modelName
 * @param string $modelRelation
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsBelongsTo){

	zval *model_name = NULL, *model_relation = NULL, *initialized = NULL;
	zval *model = NULL, *belongs_to = NULL;
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
		PHALCON_INIT_VAR(model);
		object_init_ex(model, ce1);
		PHALCON_CALL_METHOD_NORETURN(model, "__construct", PH_CHECK);
	}
	
	PHALCON_INIT_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(belongs_to, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
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
 * @param string $modelName
 * @param string $modelRelation
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasMany){

	zval *model_name = NULL, *model_relation = NULL, *initialized = NULL;
	zval *model = NULL, *has_many = NULL;
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
		PHALCON_INIT_VAR(model);
		object_init_ex(model, ce1);
		PHALCON_CALL_METHOD_NORETURN(model, "__construct", PH_CHECK);
	}
	
	PHALCON_INIT_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(has_many, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
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
 * @param string $modelName
 * @param string $modelRelation
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, existsHasOne){

	zval *model_name = NULL, *model_relation = NULL, *initialized = NULL;
	zval *model = NULL, *has_one = NULL;
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
		PHALCON_INIT_VAR(model);
		object_init_ex(model, ce1);
		PHALCON_CALL_METHOD_NORETURN(model, "__construct", PH_CHECK);
	}
	
	PHALCON_INIT_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(has_one, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
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
 * @param Phalcon\Mvc\Model\Base $record
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, _getRelationRecords){

	zval *relation = NULL, *method = NULL, *record = NULL, *conditions = NULL, *value = NULL;
	zval *i = NULL, *referenced_field = NULL, *number_args = NULL, *key = NULL;
	zval *find_params = NULL, *reference_table = NULL, *referenced_entity = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL, *r13 = NULL;
	zval *r14 = NULL, *r15 = NULL, *r16 = NULL, *r17 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *c0 = NULL;
	zval *a0 = NULL;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &relation, &method, &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(conditions);
	array_init(conditions);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, relation, SL("fi"), PH_NOISY_CC);
	if (Z_TYPE_P(r0) != IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, relation, SL("fi"), PH_NOISY_CC);
		PHALCON_INIT_VAR(value);
		PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", r1, PH_NO_CHECK);
		
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, relation, SL("rf"), PH_NOISY_CC);
		
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CONCAT_VSVS(r3, r2, " = '", value, "'");
		phalcon_array_update_long(&conditions, 0, &r3, PH_COPY | PH_SEPARATE TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(i);
		ZVAL_LONG(i, 0);
		
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, relation, SL("fi"), PH_NOISY_CC);
		if (!phalcon_valid_foreach(r4 TSRMLS_CC)) {
			return;
		}
		
		ah0 = Z_ARRVAL_P(r4);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_74b5_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_74b5_0;
			}
			
			PHALCON_INIT_VAR(referenced_field);
			ZVAL_ZVAL(referenced_field, *hd, 1, 0);
			PHALCON_INIT_VAR(r5);
			phalcon_array_fetch_string(&r5, relation, SL("fi"), PH_NOISY_CC);
			PHALCON_INIT_VAR(r6);
			phalcon_array_fetch(&r6, r5, i, PH_NOISY_CC);
			PHALCON_INIT_VAR(value);
			PHALCON_CALL_METHOD_PARAMS_1(value, record, "readattribute", r6, PH_NO_CHECK);
			
			PHALCON_INIT_VAR(r7);
			phalcon_array_fetch_string(&r7, relation, SL("rf"), PH_NOISY_CC);
			
			PHALCON_INIT_VAR(r8);
			phalcon_array_fetch(&r8, r7, i, PH_NOISY_CC);
			
			PHALCON_INIT_VAR(r9);
			PHALCON_CONCAT_VSVS(r9, r8, " = '", value, "'");
			phalcon_array_append(&conditions, r9, PH_SEPARATE TSRMLS_CC);
			PHALCON_SEPARATE(i);
			increment_function(i);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_74b5_0;
		fee_74b5_0:
		if(0){}
		
	}
	
	PHALCON_INIT_VAR(number_args);
	PHALCON_CALL_FUNC(number_args, "func_num_args");
	
	PHALCON_INIT_VAR(t0);
	ZVAL_LONG(t0, 4);
	
	PHALCON_ALLOC_ZVAL_MM(r10);
	is_smaller_function(r10, t0, number_args TSRMLS_CC);
	if (zend_is_true(r10)) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		PHALCON_CALL_FUNC(r11, "func_get_args");
		if (!phalcon_valid_foreach(r11 TSRMLS_CC)) {
			return;
		}
		
		ah1 = Z_ARRVAL_P(r11);
		zend_hash_internal_pointer_reset_ex(ah1, &hp1);
		fes_74b5_1:
			if(zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) != SUCCESS){
				goto fee_74b5_1;
			}
			
			PHALCON_INIT_VAR(key);
			PHALCON_GET_FOREACH_KEY(key, ah1, hp1);
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			PHALCON_INIT_VAR(t1);
			ZVAL_LONG(t1, 0);
			PHALCON_INIT_VAR(r12);
			is_equal_function(r12, key, t1 TSRMLS_CC);
			PHALCON_INIT_VAR(t2);
			ZVAL_STRING(t2, "conditions", 1);
			PHALCON_INIT_VAR(r13);
			is_equal_function(r13, key, t2 TSRMLS_CC);
			PHALCON_INIT_VAR(r14);
			ZVAL_BOOL(r14, zend_is_true(r12) || zend_is_true(r13));
			if (zend_is_true(r14)) {
				phalcon_array_append(&conditions, value, PH_SEPARATE TSRMLS_CC);
			}
			zend_hash_move_forward_ex(ah1, &hp1);
			goto fes_74b5_1;
		fee_74b5_1:
		if(0){}
		
	}
	
	PHALCON_INIT_VAR(find_params);
	array_init(find_params);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, " AND ", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r15);
	phalcon_fast_join(r15, c0, conditions TSRMLS_CC);
	phalcon_array_append(&find_params, r15, PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(reference_table);
	phalcon_array_fetch_string(&reference_table, relation, SL("rt"), PH_NOISY_CC);
	ce0 = phalcon_fetch_class(reference_table TSRMLS_CC);
	
	PHALCON_INIT_VAR(referenced_entity);
	object_init_ex(referenced_entity, ce0);
	PHALCON_CALL_METHOD_NORETURN(referenced_entity, "__construct", PH_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r16);
	PHALCON_CALL_METHOD(r16, record, "getconnectionservice", PH_NO_CHECK);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(referenced_entity, "setconnectionservice", r16, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	phalcon_array_append(&a0, referenced_entity, PH_SEPARATE TSRMLS_CC);
	phalcon_array_append(&a0, method, PH_SEPARATE TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r17);
	PHALCON_CALL_FUNC_PARAMS_2(r17, "call_user_func_array", a0, find_params);
	RETURN_CTOR(r17);
}

/**
 * Gets belongsTo related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Mvc\Model $record
 * @return Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsToRecords){

	zval *method = NULL, *model_name = NULL, *model_relation = NULL, *record = NULL;
	zval *belongs_to = NULL, *relation = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &method, &model_name, &model_relation, &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(belongs_to);
	phalcon_read_property(&belongs_to, this_ptr, SL("_belongsTo"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(belongs_to, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, belongs_to, model_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (!eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, belongs_to, model_name, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(relation);
	phalcon_array_fetch(&relation, r1, model_relation, PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD_PARAMS_3(r2, this_ptr, "_getrelationrecords", relation, method, record, PH_NO_CHECK);
	RETURN_CTOR(r2);
}

/**
 * Gets hasMany related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Mvc\Model $record
 * @return Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasManyRecords){

	zval *method = NULL, *model_name = NULL, *model_relation = NULL, *record = NULL;
	zval *has_many = NULL, *relation = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &method, &model_name, &model_relation, &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(has_many);
	phalcon_read_property(&has_many, this_ptr, SL("_hasMany"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(has_many, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, has_many, model_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (!eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, has_many, model_name, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(relation);
	phalcon_array_fetch(&relation, r1, model_relation, PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD_PARAMS_3(r2, this_ptr, "_getrelationrecords", relation, method, record, PH_NO_CHECK);
	RETURN_CTOR(r2);
}

/**
 * Gets belongsTo related records from a model
 *
 * @param string $method
 * @param string $modelName
 * @param string $modelRelation
 * @param Phalcon\Mvc\Model $record
 * @return Phalcon\Mvc\Model\Resultset
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneRecords){

	zval *method = NULL, *model_name = NULL, *model_relation = NULL, *record = NULL;
	zval *has_one = NULL, *relation = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzzz", &method, &model_name, &model_relation, &record) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(has_one);
	phalcon_read_property(&has_one, this_ptr, SL("_hasOne"), PH_NOISY_CC);
	eval_int = phalcon_array_isset(has_one, model_name);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, has_one, model_name, PH_NOISY_CC);
		eval_int = phalcon_array_isset(r0, model_relation);
		if (!eval_int) {
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch(&r1, has_one, model_name, PH_NOISY_CC);
	
	PHALCON_INIT_VAR(relation);
	phalcon_array_fetch(&relation, r1, model_relation, PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_CALL_METHOD_PARAMS_3(r2, this_ptr, "_getrelationrecords", relation, method, record, PH_NO_CHECK);
	RETURN_CTOR(r2);
}

/**
 * Gets belongsTo relations defined on a model
 *
 * @param  Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getBelongsTo){

	zval *model = NULL, *model_name = NULL, *belongs_to = NULL;
	zval *r0 = NULL;
	zval *a0 = NULL;
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
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, belongs_to, model_name, PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	
	RETURN_CTOR(a0);
}

/**
 * Gets hasMany relations defined on a model
 *
 * @param  Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasMany){

	zval *model = NULL, *model_name = NULL, *has_many = NULL;
	zval *r0 = NULL;
	zval *a0 = NULL;
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
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, has_many, model_name, PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	
	RETURN_CTOR(a0);
}

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOne){

	zval *model = NULL, *model_name = NULL, *has_one = NULL;
	zval *r0 = NULL;
	zval *a0 = NULL;
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
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch(&r0, has_one, model_name, PH_NOISY_CC);
		
		RETURN_CCTOR(r0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	
	RETURN_CTOR(a0);
}

/**
 * Gets hasOne relations defined on a model
 *
 * @param  Phalcon\Mvc\Model $model
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_Manager, getHasOneAndHasMany){

	zval *model = NULL, *has_one = NULL, *has_many = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &model) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(has_one);
	PHALCON_CALL_METHOD_PARAMS_1(has_one, this_ptr, "gethasone", model, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(has_many);
	PHALCON_CALL_METHOD_PARAMS_1(has_many, this_ptr, "gethasmany", model, PH_NO_CHECK);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "array_merge", has_one, has_many);
	RETURN_CTOR(r0);
}

