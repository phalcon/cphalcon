
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
 * use Phalcon\Annotations\Reader;
 * use Phalcon\Annotations\Reflection;
 *
 * // Parse the annotations in a class
 * $reader = new Reader();
 * $parsing = reader->parse('MyComponent');
 *
 * // Create the reflection
 * $reflection = new Reflection($parsing);
 *
 * // Get the annotations in the class docblock
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

	zval *reflectionData = NULL, reflectionData_sub, __$null;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&reflectionData_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 0, 1, &reflectionData);

	if (!reflectionData) {
		reflectionData = &reflectionData_sub;
		reflectionData = &__$null;
	}


	if (Z_TYPE_P(reflectionData) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, SL("_reflectionData"), reflectionData);
	}

}

/**
 * Returns the annotations found in the class docblock
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getClassAnnotations) {

	zval __$true, __$false, annotations, reflectionClass, collection, _0$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&reflectionClass);
	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&annotations, this_ptr, SL("_classAnnotations"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&annotations) != IS_OBJECT) {
		zephir_read_property(&_0$$3, this_ptr, SL("_reflectionData"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&reflectionClass, &_0$$3, SL("class"), 1)) {
			ZEPHIR_INIT_VAR(&collection);
			object_init_ex(&collection, phalcon_annotations_collection_ce);
			ZEPHIR_CALL_METHOD(NULL, &collection, "__construct", NULL, 24, &reflectionClass);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("_classAnnotations"), &collection);
			RETURN_CCTOR(collection);
		}
		if (0) {
			zephir_update_property_zval(this_ptr, SL("_classAnnotations"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_classAnnotations"), &__$false);
		}
		RETURN_MM_BOOL(0);
	}
	RETURN_CTOR(annotations);

}

/**
 * Returns the annotations found in the methods' docblocks
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getMethodsAnnotations) {

	zend_string *_3$$5;
	zend_ulong _2$$5;
	zval __$true, __$false, annotations, reflectionMethods, collections, methodName, reflectionMethod, _0$$3, *_1$$5, _4$$6;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&reflectionMethods);
	ZVAL_UNDEF(&collections);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&reflectionMethod);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&annotations);
	zephir_read_property(&annotations, this_ptr, SL("_methodAnnotations"), PH_NOISY_CC);
	if (Z_TYPE_P(&annotations) != IS_OBJECT) {
		ZEPHIR_OBS_VAR(&reflectionMethods);
		zephir_read_property(&_0$$3, this_ptr, SL("_reflectionData"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&reflectionMethods, &_0$$3, SL("methods"), 0)) {
			if (zephir_fast_count_int(&reflectionMethods TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(&collections);
				array_init(&collections);
				zephir_is_iterable(&reflectionMethods, 0, "phalcon/annotations/reflection.zep", 104);
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&reflectionMethods), _2$$5, _3$$5, _1$$5)
				{
					ZEPHIR_INIT_NVAR(&methodName);
					if (_3$$5 != NULL) { 
						ZVAL_STR_COPY(&methodName, _3$$5);
					} else {
						ZVAL_LONG(&methodName, _2$$5);
					}
					ZEPHIR_INIT_NVAR(&reflectionMethod);
					ZVAL_COPY(&reflectionMethod, _1$$5);
					ZEPHIR_INIT_NVAR(&_4$$6);
					object_init_ex(&_4$$6, phalcon_annotations_collection_ce);
					ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", &_5, 24, &reflectionMethod);
					zephir_check_call_status();
					zephir_array_update_zval(&collections, &methodName, &_4$$6, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&reflectionMethod);
				ZEPHIR_INIT_NVAR(&methodName);
				zephir_update_property_zval(this_ptr, SL("_methodAnnotations"), &collections);
				RETURN_CCTOR(collections);
			}
		}
		if (0) {
			zephir_update_property_zval(this_ptr, SL("_methodAnnotations"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_methodAnnotations"), &__$false);
		}
		RETURN_MM_BOOL(0);
	}
	RETURN_CCTOR(annotations);

}

/**
 * Returns the annotations found in the properties' docblocks
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getPropertiesAnnotations) {

	zend_string *_3$$5;
	zend_ulong _2$$5;
	zval __$true, __$false, annotations, reflectionProperties, collections, property, reflectionProperty, _0$$3, *_1$$5, _4$$6;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&annotations);
	ZVAL_UNDEF(&reflectionProperties);
	ZVAL_UNDEF(&collections);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&reflectionProperty);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_4$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&annotations);
	zephir_read_property(&annotations, this_ptr, SL("_propertyAnnotations"), PH_NOISY_CC);
	if (Z_TYPE_P(&annotations) != IS_OBJECT) {
		ZEPHIR_OBS_VAR(&reflectionProperties);
		zephir_read_property(&_0$$3, this_ptr, SL("_reflectionData"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&reflectionProperties, &_0$$3, SL("properties"), 0)) {
			if (zephir_fast_count_int(&reflectionProperties TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(&collections);
				array_init(&collections);
				zephir_is_iterable(&reflectionProperties, 0, "phalcon/annotations/reflection.zep", 131);
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&reflectionProperties), _2$$5, _3$$5, _1$$5)
				{
					ZEPHIR_INIT_NVAR(&property);
					if (_3$$5 != NULL) { 
						ZVAL_STR_COPY(&property, _3$$5);
					} else {
						ZVAL_LONG(&property, _2$$5);
					}
					ZEPHIR_INIT_NVAR(&reflectionProperty);
					ZVAL_COPY(&reflectionProperty, _1$$5);
					ZEPHIR_INIT_NVAR(&_4$$6);
					object_init_ex(&_4$$6, phalcon_annotations_collection_ce);
					ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", &_5, 24, &reflectionProperty);
					zephir_check_call_status();
					zephir_array_update_zval(&collections, &property, &_4$$6, PH_COPY | PH_SEPARATE);
				} ZEND_HASH_FOREACH_END();
				ZEPHIR_INIT_NVAR(&reflectionProperty);
				ZEPHIR_INIT_NVAR(&property);
				zephir_update_property_zval(this_ptr, SL("_propertyAnnotations"), &collections);
				RETURN_CCTOR(collections);
			}
		}
		if (0) {
			zephir_update_property_zval(this_ptr, SL("_propertyAnnotations"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("_propertyAnnotations"), &__$false);
		}
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

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_reflectionData");

}

/**
 * Restores the state of a Phalcon\Annotations\Reflection variable export
 *
 * @return array data
 */
PHP_METHOD(Phalcon_Annotations_Reflection, __set_state) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, reflectionData;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&reflectionData);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if (Z_TYPE_P(data) == IS_ARRAY) {
		if (zephir_array_isset_string_fetch(&reflectionData, data, SL("_reflectionData"), 1)) {
			object_init_ex(return_value, phalcon_annotations_reflection_ce);
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 22, &reflectionData);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	object_init_ex(return_value, phalcon_annotations_reflection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 22);
	zephir_check_call_status();
	RETURN_MM();

}

