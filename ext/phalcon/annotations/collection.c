
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


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
 * //Check if the annotations has a specific
 * var_dump($classAnnotations->has('Cacheable'));
 *
 * //Get an specific annotation in the collection
 * $annotation = $classAnnotations->get('Cacheable');
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Collection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Collection, phalcon, annotations_collection, phalcon_annotations_collection_method_entry, 0);

	zend_declare_property_long(phalcon_annotations_collection_ce, SL("_position"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_annotations_collection_ce, SL("_annotations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_annotations_collection_ce TSRMLS_CC, 1, zend_ce_iterator);
	zend_class_implements(phalcon_annotations_collection_ce TSRMLS_CC, 1, spl_ce_Countable);

	return SUCCESS;

}

/**
 * Phalcon\Annotations\Collection constructor
 *
 * @param array reflectionData
 */
PHP_METHOD(Phalcon_Annotations_Collection, __construct) {

	zend_function *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *reflectionData = NULL, *annotations, *annotationData = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &reflectionData);

	if (!reflectionData) {
		ZEPHIR_CPY_WRT(reflectionData, ZEPHIR_GLOBAL(global_null));
	}


	if ((Z_TYPE_P(reflectionData) != IS_NULL)) {
		if ((Z_TYPE_P(reflectionData) != IS_ARRAY)) {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_annotations_exception_ce, "Reflection data must be an array");
			return;
		}
	}
	if ((Z_TYPE_P(reflectionData) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(annotations);
		array_init(annotations);
		zephir_is_iterable(reflectionData, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(annotationData, _2);
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, phalcon_annotations_annotation_ce);
			zephir_call_method_p1_cache_noret(_3, "__construct", &_4, annotationData);
			zephir_array_append(&annotations, _3, PH_SEPARATE);
		}
		zephir_update_property_this(this_ptr, SL("_annotations"), annotations TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the number of annotations in the collection
 *
 * @return int
 */
PHP_METHOD(Phalcon_Annotations_Collection, count) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_annotations"), PH_NOISY_CC);
	RETURN_LONG(zephir_fast_count_int(_0 TSRMLS_CC));

}

/**
 * Rewinds the internal iterator
 */
PHP_METHOD(Phalcon_Annotations_Collection, rewind) {

	zval *_0;


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, 0);
	zephir_update_property_this(this_ptr, SL("_position"), _0 TSRMLS_CC);

}

/**
 * Returns the current annotation in the iterator
 *
 * @return Phalcon\Annotations\Annotation
 */
PHP_METHOD(Phalcon_Annotations_Collection, current) {

	zval *annotation, *annotations, *_0;

	ZEPHIR_MM_GROW();

	annotations = zephir_fetch_nproperty_this(this_ptr, SL("_annotations"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(annotation);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_position"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&annotation, annotations, _0 TSRMLS_CC)) {
		RETURN_CCTOR(annotation);
	}
	RETURN_MM_NULL();

}

/**
 * Returns the current position/key in the iterator
 *
 * @return int
 */
PHP_METHOD(Phalcon_Annotations_Collection, key) {


	RETURN_MEMBER(this_ptr, "_position");

}

/**
 * Moves the internal iteration pointer to the next position
 *
 */
PHP_METHOD(Phalcon_Annotations_Collection, next) {



}

/**
 * Check if the current annotation in the iterator is valid
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Annotations_Collection, valid) {

	zval *annotations, *_0, *_1;

	ZEPHIR_MM_GROW();

	annotations = zephir_fetch_nproperty_this(this_ptr, SL("_annotations"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("_position"), PH_NOISY_CC);
	zephir_array_fetch(&_0, annotations, _1, PH_NOISY TSRMLS_CC);
	RETURN_CCTOR(_0);

}

/**
 * Returns the internal annotations as an array
 *
 * @return Phalcon\Annotations\Annotation[]
 */
PHP_METHOD(Phalcon_Annotations_Collection, getAnnotations) {


	RETURN_MEMBER(this_ptr, "_annotations");

}

/**
 * Returns the first annotation that match a name
 *
 * @param string name
 * @return Phalcon\Annotations\Annotation
 */
PHP_METHOD(Phalcon_Annotations_Collection, get) {

	zend_function *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *name_param = NULL, *annotation = NULL, *annotations, **_2, *_3 = NULL, *_5, *_6;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		zephir_get_strval(name, name_param);


	annotations = zephir_fetch_nproperty_this(this_ptr, SL("_annotations"), PH_NOISY_CC);
	if ((Z_TYPE_P(annotations) == IS_ARRAY)) {
		zephir_is_iterable(annotations, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(annotation, _2);
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_method_cache(_3, annotation, "getname", &_4);
			if (ZEPHIR_IS_EQUAL(name, _3)) {
				RETURN_CCTOR(annotation);
			}
		}
	}
	ZEPHIR_INIT_NVAR(_3);
	object_init_ex(_3, phalcon_annotations_exception_ce);
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_SV(_5, "The collection doesn't have an annotation called '", name);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_VS(_6, _5, "'");
	zephir_call_method_p1_noret(_3, "__construct", _6);
	zephir_throw_exception(_3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * Returns all the annotations that match a name
 *
 * @param string name
 * @return Phalcon\Annotations\Annotation[]
 */
PHP_METHOD(Phalcon_Annotations_Collection, getAll) {

	zend_function *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *name_param = NULL, *annotations, *found, *annotation = NULL, **_2, *_3 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		zephir_get_strval(name, name_param);


	ZEPHIR_INIT_VAR(found);
	array_init(found);
	annotations = zephir_fetch_nproperty_this(this_ptr, SL("_annotations"), PH_NOISY_CC);
	if ((Z_TYPE_P(annotations) == IS_ARRAY)) {
		zephir_is_iterable(annotations, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(annotation, _2);
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_method_cache(_3, annotation, "getname", &_4);
			if (ZEPHIR_IS_EQUAL(name, _3)) {
				zephir_array_append(&found, annotation, PH_SEPARATE);
			}
		}
	}
	RETURN_CCTOR(found);

}

/**
 * Check if an annotation exists in a collection
 *
 * @param string name
 * @return boolean
 */
PHP_METHOD(Phalcon_Annotations_Collection, has) {

	zend_function *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *name_param = NULL, *annotations, *annotation = NULL, **_2, *_3 = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

		zephir_get_strval(name, name_param);


	annotations = zephir_fetch_nproperty_this(this_ptr, SL("_annotations"), PH_NOISY_CC);
	if ((Z_TYPE_P(annotations) == IS_ARRAY)) {
		zephir_is_iterable(annotations, &_1, &_0, 0, 0);
		for (
			; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
			; zend_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(annotation, _2);
			ZEPHIR_INIT_NVAR(_3);
			zephir_call_method_cache(_3, annotation, "getname", &_4);
			if (ZEPHIR_IS_EQUAL(name, _3)) {
				RETURN_MM_BOOL(1);
			}
		}
	}
	RETURN_MM_BOOL(0);

}

