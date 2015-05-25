
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

	zephir_fetch_params(0, 0, 1, &reflectionData);

	if (!reflectionData) {
		reflectionData = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(reflectionData) == IS_ARRAY) {
		zephir_update_property_this(this_ptr, SL("_reflectionData"), reflectionData TSRMLS_CC);
	}

}

/**
 * Returns the annotations found in the class docblock
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getClassAnnotations) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *annotations, *reflectionClass, *collection, *_0;

	ZEPHIR_MM_GROW();

	annotations = zephir_fetch_nproperty_this(this_ptr, SL("_classAnnotations"), PH_NOISY_CC);
	if (Z_TYPE_P(annotations) != IS_OBJECT) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_reflectionData"), PH_NOISY_CC);
		if (zephir_array_isset_string_fetch(&reflectionClass, _0, SS("class"), 1 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(collection);
			object_init_ex(collection, phalcon_annotations_collection_ce);
			ZEPHIR_CALL_METHOD(NULL, collection, "__construct", NULL, 6, reflectionClass);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_classAnnotations"), collection TSRMLS_CC);
			RETURN_CCTOR(collection);
		}
		zephir_update_property_this(this_ptr, SL("_classAnnotations"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
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

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *annotations, *reflectionMethods, *collections, *methodName = NULL, *reflectionMethod = NULL, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(annotations);
	zephir_read_property_this(&annotations, this_ptr, SL("_methodAnnotations"), PH_NOISY_CC);
	if (Z_TYPE_P(annotations) != IS_OBJECT) {
		ZEPHIR_OBS_VAR(reflectionMethods);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_reflectionData"), PH_NOISY_CC);
		if (zephir_array_isset_string_fetch(&reflectionMethods, _0, SS("methods"), 0 TSRMLS_CC)) {
			if (zephir_fast_count_int(reflectionMethods TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(collections);
				array_init(collections);
				zephir_is_iterable(reflectionMethods, &_2, &_1, 0, 0, "phalcon/annotations/reflection.zep", 102);
				for (
				  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
				  ; zephir_hash_move_forward_ex(_2, &_1)
				) {
					ZEPHIR_GET_HMKEY(methodName, _2, _1);
					ZEPHIR_GET_HVALUE(reflectionMethod, _3);
					ZEPHIR_INIT_NVAR(_4);
					object_init_ex(_4, phalcon_annotations_collection_ce);
					ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_5, 6, reflectionMethod);
					zephir_check_call_status();
					zephir_array_update_zval(&collections, methodName, &_4, PH_COPY | PH_SEPARATE);
				}
				zephir_update_property_this(this_ptr, SL("_methodAnnotations"), collections TSRMLS_CC);
				RETURN_CCTOR(collections);
			}
		}
		zephir_update_property_this(this_ptr, SL("_methodAnnotations"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	RETURN_CCTOR(annotations);

}

/**
 * Returns the annotations found in the properties' docblocks
 *
 * @return Phalcon\Annotations\Collection[]
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getPropertiesAnnotations) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *annotations, *reflectionProperties, *collections, *property = NULL, *reflectionProperty = NULL, *_0, **_3, *_4 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(annotations);
	zephir_read_property_this(&annotations, this_ptr, SL("_propertyAnnotations"), PH_NOISY_CC);
	if (Z_TYPE_P(annotations) != IS_OBJECT) {
		ZEPHIR_OBS_VAR(reflectionProperties);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_reflectionData"), PH_NOISY_CC);
		if (zephir_array_isset_string_fetch(&reflectionProperties, _0, SS("properties"), 0 TSRMLS_CC)) {
			if (zephir_fast_count_int(reflectionProperties TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(collections);
				array_init(collections);
				zephir_is_iterable(reflectionProperties, &_2, &_1, 0, 0, "phalcon/annotations/reflection.zep", 130);
				for (
				  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
				  ; zephir_hash_move_forward_ex(_2, &_1)
				) {
					ZEPHIR_GET_HMKEY(property, _2, _1);
					ZEPHIR_GET_HVALUE(reflectionProperty, _3);
					ZEPHIR_INIT_NVAR(_4);
					object_init_ex(_4, phalcon_annotations_collection_ce);
					ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_5, 6, reflectionProperty);
					zephir_check_call_status();
					zephir_array_update_zval(&collections, property, &_4, PH_COPY | PH_SEPARATE);
				}
				zephir_update_property_this(this_ptr, SL("_propertyAnnotations"), collections TSRMLS_CC);
				RETURN_CCTOR(collections);
			}
		}
		zephir_update_property_this(this_ptr, SL("_propertyAnnotations"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
		RETURN_MM_BOOL(0);
	}
	RETURN_CCTOR(annotations);

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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, *reflectionData;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (Z_TYPE_P(data) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&reflectionData, data, SS("_reflectionData"), 1 TSRMLS_CC)) {
			object_init_ex(return_value, phalcon_annotations_reflection_ce);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 5, reflectionData);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	object_init_ex(return_value, phalcon_annotations_reflection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 5);
	zephir_check_call_status();
	RETURN_MM();

}

