
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

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/file.h"

/**
 * Phalcon\Annotations\Reflection
 *
 * Allows to manipulate the annotations reflection in an OO manner
 *
 *<code>
 * //Parse the annotations in a class
 * $reader = new Phalcon\Annotations\Reader();
 * $parsing = $reader->parse('MyComponent');
 *
 * //Create the reflection
 * $reflection = new Phalcon\Annotations\Reflection($parsing);
 *
 * //Get the annotations in the class docblock
 * $classAnnotations = $reflection->getClassAnnotations();
 *</code>
 */


/**
 * Phalcon\Annotations\Reflection initializer
 */
PHALCON_INIT_CLASS(Phalcon_Annotations_Reflection){

	PHALCON_REGISTER_CLASS(Phalcon\\Annotations, Reflection, annotations_reflection, phalcon_annotations_reflection_method_entry, 0);

	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("_reflectionData"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("_classAnnotations"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("_methodAnnotations"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("_propertyAnnotations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Annotations\Reflection constructor
 *
 * @param array $reflectionData
 */
PHP_METHOD(Phalcon_Annotations_Reflection, __construct){

	zval *reflection_data;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &reflection_data) == FAILURE) {
		RETURN_NULL();
	}

	if (Z_TYPE_P(reflection_data) == IS_ARRAY) { 
		phalcon_update_property_zval(this_ptr, SL("_reflectionData"), reflection_data TSRMLS_CC);
	}
	
}

/**
 * Returns the annotations found in the class docblock
 *
 * @return Phalcon\Annotations\Collection
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getClassAnnotations){

	zval *annotations, *reflection_data, *reflection_class;
	zval *collection;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(annotations);
	phalcon_read_property(&annotations, this_ptr, SL("_classAnnotations"), PH_NOISY_CC);
	if (Z_TYPE_P(annotations) != IS_OBJECT) {
	
		PHALCON_OBS_VAR(reflection_data);
		phalcon_read_property(&reflection_data, this_ptr, SL("_reflectionData"), PH_NOISY_CC);
		if (phalcon_array_isset_string(reflection_data, SS("class"))) {
			PHALCON_OBS_VAR(reflection_class);
			phalcon_array_fetch_string(&reflection_class, reflection_data, SL("class"), PH_NOISY_CC);
	
			PHALCON_INIT_VAR(collection);
			object_init_ex(collection, phalcon_annotations_collection_ce);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(collection, "__construct", reflection_class);
	
			phalcon_update_property_zval(this_ptr, SL("_classAnnotations"), collection TSRMLS_CC);
			RETURN_CTOR(collection);
		}
	
		phalcon_update_property_bool(this_ptr, SL("_classAnnotations"), 0 TSRMLS_CC);
		RETURN_MM_FALSE;
	}
	
	
	RETURN_CCTOR(annotations);
}

/**
 * Returns the annotations found in the methods' docblocks
 *
 * @return Phalcon\Annotations\Collection[]
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getMethodsAnnotations){

	zval *annotations, *reflection_data, *reflection_methods;
	zval *collections, *reflection_method = NULL, *method_name = NULL;
	zval *collection = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(annotations);
	phalcon_read_property(&annotations, this_ptr, SL("_methodAnnotations"), PH_NOISY_CC);
	if (Z_TYPE_P(annotations) != IS_OBJECT) {
	
		PHALCON_OBS_VAR(reflection_data);
		phalcon_read_property(&reflection_data, this_ptr, SL("_reflectionData"), PH_NOISY_CC);
		if (phalcon_array_isset_string(reflection_data, SS("methods"))) {
	
			PHALCON_OBS_VAR(reflection_methods);
			phalcon_array_fetch_string(&reflection_methods, reflection_data, SL("methods"), PH_NOISY_CC);
			if (phalcon_fast_count_ev(reflection_methods TSRMLS_CC)) {
	
				PHALCON_INIT_VAR(collections);
				array_init(collections);
	
				if (!phalcon_is_iterable(reflection_methods, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
					return;
				}
	
				while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
					PHALCON_GET_FOREACH_KEY(method_name, ah0, hp0);
					PHALCON_GET_FOREACH_VALUE(reflection_method);
	
					PHALCON_INIT_NVAR(collection);
					object_init_ex(collection, phalcon_annotations_collection_ce);
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(collection, "__construct", reflection_method);
	
					phalcon_array_update_zval(&collections, method_name, &collection, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
					zend_hash_move_forward_ex(ah0, &hp0);
				}
	
				phalcon_update_property_zval(this_ptr, SL("_methodAnnotations"), collections TSRMLS_CC);
	
				RETURN_CTOR(collections);
			}
		}
	
		phalcon_update_property_bool(this_ptr, SL("_methodAnnotations"), 0 TSRMLS_CC);
		RETURN_MM_FALSE;
	}
	
	
	RETURN_CCTOR(annotations);
}

/**
 * Returns the annotations found in the properties' docblocks
 *
 * @return Phalcon\Annotations\Collection[]
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getPropertiesAnnotations){

	zval *annotations, *reflection_data, *reflection_properties;
	zval *collections, *reflection_property = NULL, *property = NULL;
	zval *collection = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(annotations);
	phalcon_read_property(&annotations, this_ptr, SL("_propertyAnnotations"), PH_NOISY_CC);
	if (Z_TYPE_P(annotations) != IS_OBJECT) {
	
		PHALCON_OBS_VAR(reflection_data);
		phalcon_read_property(&reflection_data, this_ptr, SL("_reflectionData"), PH_NOISY_CC);
		if (phalcon_array_isset_string(reflection_data, SS("properties"))) {
	
			PHALCON_OBS_VAR(reflection_properties);
			phalcon_array_fetch_string(&reflection_properties, reflection_data, SL("properties"), PH_NOISY_CC);
			if (phalcon_fast_count_ev(reflection_properties TSRMLS_CC)) {
	
				PHALCON_INIT_VAR(collections);
				array_init(collections);
	
				if (!phalcon_is_iterable(reflection_properties, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
					return;
				}
	
				while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
					PHALCON_GET_FOREACH_KEY(property, ah0, hp0);
					PHALCON_GET_FOREACH_VALUE(reflection_property);
	
					PHALCON_INIT_NVAR(collection);
					object_init_ex(collection, phalcon_annotations_collection_ce);
					PHALCON_CALL_METHOD_PARAMS_1_NORETURN(collection, "__construct", reflection_property);
	
					phalcon_array_update_zval(&collections, property, &collection, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
					zend_hash_move_forward_ex(ah0, &hp0);
				}
	
				phalcon_update_property_zval(this_ptr, SL("_propertyAnnotations"), collections TSRMLS_CC);
	
				RETURN_CTOR(collections);
			}
		}
	
		phalcon_update_property_bool(this_ptr, SL("_propertyAnnotations"), 0 TSRMLS_CC);
		RETURN_MM_FALSE;
	}
	
	
	RETURN_CCTOR(annotations);
}

/**
 * Returns the raw parsing intermediate definitions used to construct the reflection
 *
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getReflectionData){


	RETURN_MEMBER(this_ptr, "_reflectionData");
}

