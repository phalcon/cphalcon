
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"

/**
 * Phalcon\Annotations\Collection
 *
 * Represents a collection of annotations. This class allows to traverse a group of annotations easily
 *
 *<code>
 * //Traverse annotations
 * foreach ($classAnnotations as $annotation) {
 *     echo 'Name=', $annotation->getName(), PHP_EOL;
 * }
 *
 * //Check if the annotations has an specific
 * var_dump($classAnnotations->has('Cacheable'));
 *
 * //Get an specific annotation in the collection
 * $annotation = $classAnnotations->get('Cacheable');
 *</code>
 */


/**
 * Phalcon\Annotations\Collection initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_Collection){

	PHALCON_REGISTER_CLASS(Phalcon\\Annotations, Collection, annotations_collection, phalcon_annotations_collection_method_entry, 0);

	zend_declare_property_long(phalcon_annotations_collection_ce, SL("_position"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_annotations_collection_ce, SL("_annotations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_annotations_collection_ce TSRMLS_CC, 2, zend_ce_iterator, spl_ce_Countable);

	return SUCCESS;
}

/**
 * Phalcon\Annotations\Collection constructor
 *
 * @param array $reflectionData
 */
PHP_METHOD(Phalcon_Annotations_Collection, __construct){

	zval *reflection_data = NULL, *annotations, *annotation_data = NULL;
	zval *annotation = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &reflection_data) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!reflection_data) {
		PHALCON_INIT_VAR(reflection_data);
	}
	
	if (Z_TYPE_P(reflection_data) != IS_NULL) {
		if (Z_TYPE_P(reflection_data) != IS_ARRAY) { 
			PHALCON_THROW_EXCEPTION_STR(phalcon_annotations_exception_ce, "Reflection data must be an array");
			return;
		}
	}
	if (Z_TYPE_P(reflection_data) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(annotations);
		array_init(annotations);
	
		if (!phalcon_is_iterable(reflection_data, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(annotation_data);
	
			PHALCON_INIT_NVAR(annotation);
			object_init_ex(annotation, phalcon_annotations_annotation_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(annotation, "__construct", annotation_data);
	
			phalcon_array_append(&annotations, annotation, PH_SEPARATE TSRMLS_CC);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
		phalcon_update_property_zval(this_ptr, SL("_annotations"), annotations TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the number of annotations in the collection
 *
 * @return int
 */
PHP_METHOD(Phalcon_Annotations_Collection, count){

	zval *annotations, *number;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(annotations);
	phalcon_read_property_this(&annotations, this_ptr, SL("_annotations"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(number);
	phalcon_fast_count(number, annotations TSRMLS_CC);
	RETURN_NCTOR(number);
}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Annotations_Collection, rewind){


	phalcon_update_property_long(this_ptr, SL("_position"), 0 TSRMLS_CC);
	
}

/**
 * Returns the current annotation in the iterator
 *
 * @return Phalcon\Annotations\Annotation
 */
PHP_METHOD(Phalcon_Annotations_Collection, current){

	zval *position, *annotations, *annotation;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(position);
	phalcon_read_property_this(&position, this_ptr, SL("_position"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(annotations);
	phalcon_read_property_this(&annotations, this_ptr, SL("_annotations"), PH_NOISY_CC);
	if (phalcon_array_isset(annotations, position)) {
		PHALCON_OBS_VAR(annotation);
		phalcon_array_fetch(&annotation, annotations, position, PH_NOISY_CC);
		RETURN_CCTOR(annotation);
	}
	
	RETURN_MM_NULL();
}

/**
 * Returns the current position/key in the iterator
 *
 * @return int
 */
PHP_METHOD(Phalcon_Annotations_Collection, key){


	RETURN_MEMBER(this_ptr, "_position");
}

/**
 * Moves the internal iteration pointer to the next position
 *
 */
PHP_METHOD(Phalcon_Annotations_Collection, next){


	phalcon_property_incr(this_ptr, SL("_position") TSRMLS_CC);
	
}

/**
 * Check if the current annotation in the iterator is valid
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Annotations_Collection, valid){

	zval *position, *annotations;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(position);
	phalcon_read_property_this(&position, this_ptr, SL("_position"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(annotations);
	phalcon_read_property_this(&annotations, this_ptr, SL("_annotations"), PH_NOISY_CC);
	if (phalcon_array_isset(annotations, position)) {
		RETURN_MM_TRUE;
	}
	
	RETURN_MM_FALSE;
}

/**
 * Returns the internal annotations as an array
 *
 * @return Phalcon\Annotations\Annotation[]
 */
PHP_METHOD(Phalcon_Annotations_Collection, getAnnotations){


	RETURN_MEMBER(this_ptr, "_annotations");
}

/**
 * Returns the first annotation that match a name
 *
 * @param string $name
 * @return Phalcon\Annotations\Annotation
 */
PHP_METHOD(Phalcon_Annotations_Collection, get){

	zval *name, *annotations, *annotation = NULL, *annotation_name = NULL;
	zval *exception_message;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(annotations);
	phalcon_read_property_this(&annotations, this_ptr, SL("_annotations"), PH_NOISY_CC);
	if (Z_TYPE_P(annotations) == IS_ARRAY) { 
	
		if (!phalcon_is_iterable(annotations, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(annotation);
	
			PHALCON_INIT_NVAR(annotation_name);
			PHALCON_CALL_METHOD(annotation_name, annotation, "getname");
			if (PHALCON_IS_EQUAL(name, annotation_name)) {
				RETURN_CCTOR(annotation);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_INIT_VAR(exception_message);
	PHALCON_CONCAT_SVS(exception_message, "The collection doesn't have an annotation called '", name, "'");
	PHALCON_THROW_EXCEPTION_ZVAL(phalcon_annotations_exception_ce, exception_message);
	return;
}

/**
 * Returns all the annotations that match a name
 *
 * @param string $name
 * @return Phalcon\Annotations\Annotation[]
 */
PHP_METHOD(Phalcon_Annotations_Collection, getAll){

	zval *name, *found, *annotations, *annotation = NULL, *annotation_name = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(found);
	array_init(found);
	
	PHALCON_OBS_VAR(annotations);
	phalcon_read_property_this(&annotations, this_ptr, SL("_annotations"), PH_NOISY_CC);
	if (Z_TYPE_P(annotations) == IS_ARRAY) { 
	
		if (!phalcon_is_iterable(annotations, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(annotation);
	
			PHALCON_INIT_NVAR(annotation_name);
			PHALCON_CALL_METHOD(annotation_name, annotation, "getname");
			if (PHALCON_IS_EQUAL(name, annotation_name)) {
				phalcon_array_append(&found, annotation, PH_SEPARATE TSRMLS_CC);
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	
	RETURN_CTOR(found);
}

/**
 * Check if an annotation exists in a collection
 *
 * @param string $name
 * @return boolean
 */
PHP_METHOD(Phalcon_Annotations_Collection, has){

	zval *name, *annotations, *annotation = NULL, *annotation_name = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(annotations);
	phalcon_read_property_this(&annotations, this_ptr, SL("_annotations"), PH_NOISY_CC);
	if (Z_TYPE_P(annotations) == IS_ARRAY) { 
	
		if (!phalcon_is_iterable(annotations, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(annotation);
	
			PHALCON_INIT_NVAR(annotation_name);
			PHALCON_CALL_METHOD(annotation_name, annotation, "getname");
			if (PHALCON_IS_EQUAL(name, annotation_name)) {
				RETURN_MM_TRUE;
			}
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	RETURN_MM_FALSE;
}

