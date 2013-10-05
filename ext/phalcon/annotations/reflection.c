
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"


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
 * Phalcon\Annotations\Reflection
 *
 * Allows to manipulate the annotations reflection in an OO manner
 *
 *<code>
 * //Parse the annotations in a class
 * $reader = new \Phalcon\Annotations\Reader();
 * $parsing = reader->parse('MyComponent');
 *
 * //Create the reflection
 * $reflection = new \Phalcon\Annotations\Reflection($parsing);
 *
 * //Get the annotations in the class docblock
 * $classAnnotations = reflection->getClassAnnotations();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Reflection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Reflection, phalcon, annotations_reflection, phalcon_annotations_reflection_method_entry, 0);

	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("_reflectionData"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("_classAnnotations"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("_methodAnnotations"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("_propertyAnnotations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Annotations\Reflection constructor
 *
 * @param array reflectionData
 */
PHP_METHOD(Phalcon_Annotations_Reflection, __construct) {

	zval *reflectionData = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &reflectionData);

	if (!reflectionData) {
		ZEPHIR_CPY_WRT(reflectionData, ZEPHIR_GLOBAL(global_null));
	}


	if ((Z_TYPE_P(reflectionData) == IS_ARRAY)) {
		zephir_update_property_this(this_ptr, SL("_reflectionData"), reflectionData TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the annotations found in the class docblock
 *
 * @return Phalcon\Annotations\Collection|false
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getClassAnnotations) {

	zval *annotations, *reflectionData, *reflectionClass, *collection;

	ZEPHIR_MM_GROW();

	annotations = zephir_fetch_nproperty_this(this_ptr, SL("_classAnnotations"), PH_NOISY_CC);
	if ((Z_TYPE_P(annotations) != IS_OBJECT)) {
		reflectionData = zephir_fetch_nproperty_this(this_ptr, SL("_reflectionData"), PH_NOISY_CC);
		if (zephir_array_isset_string_fetch(&reflectionClass, reflectionData, SS("class"), 1 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(collection);
			object_init_ex(collection, phalcon_annotations_collection_ce);
			zephir_call_method_p1_noret(collection, "__construct", reflectionClass);
			zephir_update_property_this(this_ptr, SL("_classAnnotations"), collection TSRMLS_CC);
			RETURN_CCTOR(collection);
		}
		zephir_update_property_this(this_ptr, SL("_classAnnotations"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	RETURN_CTOR(annotations);

}

/**
 * Returns the annotations found in the methods' docblocks
 *
 * @return Phalcon\Annotations\Collection[]
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getMethodsAnnotations) {

	zend_function *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *annotations, *reflectionData, *reflectionMethods, *collections, *methodName = NULL, *reflectionMethod = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();

	annotations = zephir_fetch_nproperty_this(this_ptr, SL("_methodAnnotations"), PH_NOISY_CC);
	if ((Z_TYPE_P(annotations) != IS_OBJECT)) {
		reflectionData = zephir_fetch_nproperty_this(this_ptr, SL("_reflectionData"), PH_NOISY_CC);
		if (zephir_array_isset_string_fetch(&reflectionMethods, reflectionData, SS("methods"), 1 TSRMLS_CC)) {
			if (zephir_fast_count_int(reflectionMethods TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(collections);
				array_init(collections);
				zephir_is_iterable(reflectionMethods, &_1, &_0, 0, 0);
				for (
					; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
					; zend_hash_move_forward_ex(_1, &_0)
				) {
					ZEPHIR_GET_HMKEY(methodName, _1, _0);
					ZEPHIR_GET_HVALUE(reflectionMethod, _2);
					ZEPHIR_INIT_NVAR(_3);
					object_init_ex(_3, phalcon_annotations_collection_ce);
					zephir_call_method_p1_cache_noret(_3, "__construct", &_4, reflectionMethod);
					zephir_array_update_zval(&collections, methodName, &_3, PH_COPY | PH_SEPARATE);
				}
				zephir_update_property_this(this_ptr, SL("_methodAnnotations"), collections TSRMLS_CC);
				RETURN_CCTOR(collections);
			}
		}
		zephir_update_property_this(this_ptr, SL("_methodAnnotations"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	RETURN_CTOR(annotations);

}

/**
 * Returns the annotations found in the properties' docblocks
 *
 * @return Phalcon\Annotations\Collection[]
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getPropertiesAnnotations) {

	zend_function *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *annotations, *reflectionData, *reflectionProperties, *collections, *property = NULL, *reflectionProperty = NULL, **_2, *_3 = NULL;

	ZEPHIR_MM_GROW();

	annotations = zephir_fetch_nproperty_this(this_ptr, SL("_propertyAnnotations"), PH_NOISY_CC);
	if ((Z_TYPE_P(annotations) != IS_OBJECT)) {
		reflectionData = zephir_fetch_nproperty_this(this_ptr, SL("_reflectionData"), PH_NOISY_CC);
		if (zephir_array_isset_string_fetch(&reflectionProperties, reflectionData, SS("properties"), 1 TSRMLS_CC)) {
			if (zephir_fast_count_int(reflectionProperties TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(collections);
				array_init(collections);
				zephir_is_iterable(reflectionProperties, &_1, &_0, 0, 0);
				for (
					; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
					; zend_hash_move_forward_ex(_1, &_0)
				) {
					ZEPHIR_GET_HMKEY(property, _1, _0);
					ZEPHIR_GET_HVALUE(reflectionProperty, _2);
					ZEPHIR_INIT_NVAR(_3);
					object_init_ex(_3, phalcon_annotations_collection_ce);
					zephir_call_method_p1_cache_noret(_3, "__construct", &_4, reflectionProperty);
					zephir_array_update_zval(&collections, property, &_3, PH_COPY | PH_SEPARATE);
				}
				zephir_update_property_this(this_ptr, SL("_propertyAnnotations"), collections TSRMLS_CC);
				RETURN_CCTOR(collections);
			}
		}
		zephir_update_property_this(this_ptr, SL("_propertyAnnotations"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	RETURN_CTOR(annotations);

}

/**
 * Returns the raw parsing intermediate definitions used to construct the reflection
 *
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getReflectionData) {


	RETURN_MEMBER(this_ptr, "_reflectionData");

}

/**
 * Restores the state of a Phalcon\Annotations\Reflection variable export
 *
 * @return array data
 */
PHP_METHOD(Phalcon_Annotations_Reflection, __set_state) {

	zval *data, *reflectionData;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if ((Z_TYPE_P(data) == IS_ARRAY)) {
		if (zephir_array_isset_string_fetch(&reflectionData, data, SS("_reflectionData"), 1 TSRMLS_CC)) {
			object_init_ex(return_value, phalcon_annotations_reflection_ce);
			zephir_call_method_p1_noret(return_value, "__construct", reflectionData);
			RETURN_MM();
		}
	}
	object_init_ex(return_value, phalcon_annotations_reflection_ce);
	zephir_call_method_noret(return_value, "__construct");
	RETURN_MM();

}

