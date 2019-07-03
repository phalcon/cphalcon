
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
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
 * $parsing = $reader->parse("MyComponent");
 *
 * // Create the reflection
 * $reflection = new Reflection($parsing);
 *
 * // Get the annotations in the class docblock
 * $classAnnotations = $reflection->getClassAnnotations();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Reflection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Reflection, phalcon, annotations_reflection, phalcon_annotations_reflection_method_entry, 0);

	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("classAnnotations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("methodAnnotations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("propertyAnnotations"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("reflectionData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Annotations\Reflection constructor
 */
PHP_METHOD(Phalcon_Annotations_Reflection, __construct) {

	zval *reflectionData_param = NULL;
	zval reflectionData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflectionData);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &reflectionData_param);

	if (!reflectionData_param) {
		ZEPHIR_INIT_VAR(&reflectionData);
		array_init(&reflectionData);
	} else {
		zephir_get_arrval(&reflectionData, reflectionData_param);
	}


	zephir_update_property_zval(this_ptr, SL("reflectionData"), &reflectionData);
	ZEPHIR_MM_RESTORE();

}

/**
 * Restores the state of a Phalcon\Annotations\Reflection variable export
 */
PHP_METHOD(Phalcon_Annotations_Reflection, __set_state) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, reflectionData;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&reflectionData);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);


	if (zephir_array_isset_string_fetch(&reflectionData, &data, SL("reflectionData"), 1)) {
		object_init_ex(return_value, phalcon_annotations_reflection_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 35, &reflectionData);
		zephir_check_call_status();
		RETURN_MM();
	}
	object_init_ex(return_value, phalcon_annotations_reflection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 35);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the annotations found in the class docblock
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getClassAnnotations) {

	zval __$true, __$false, reflectionClass, _0, _1$$3, _2$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&reflectionClass);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("classAnnotations"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, SL("reflectionData"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&reflectionClass, &_1$$3, SL("class"), 1)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_annotations_collection_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 37, &reflectionClass);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("classAnnotations"), &_2$$4);
		} else {
			if (0) {
				zephir_update_property_zval(this_ptr, SL("classAnnotations"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("classAnnotations"), &__$false);
			}
		}
	}
	RETURN_MM_MEMBER(getThis(), "classAnnotations");

}

/**
 * Returns the annotations found in the methods' docblocks
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getMethodsAnnotations) {

	zend_string *_6$$5;
	zend_ulong _5$$5;
	zval __$true, __$false, reflectionMethods, methodName, reflectionMethod, _0, _1$$3, _2$$5, *_3$$5, _4$$5, _7$$6, _9$$7;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&reflectionMethods);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&reflectionMethod);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("methodAnnotations"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_OBS_VAR(&reflectionMethods);
		zephir_read_property(&_1$$3, this_ptr, SL("reflectionData"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&reflectionMethods, &_1$$3, SL("methods"), 0)) {
			if (zephir_fast_count_int(&reflectionMethods TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(&_2$$5);
				array_init(&_2$$5);
				zephir_update_property_zval(this_ptr, SL("methodAnnotations"), &_2$$5);
				zephir_is_iterable(&reflectionMethods, 0, "phalcon/Annotations/Reflection.zep", 106);
				if (Z_TYPE_P(&reflectionMethods) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&reflectionMethods), _5$$5, _6$$5, _3$$5)
					{
						ZEPHIR_INIT_NVAR(&methodName);
						if (_6$$5 != NULL) { 
							ZVAL_STR_COPY(&methodName, _6$$5);
						} else {
							ZVAL_LONG(&methodName, _5$$5);
						}
						ZEPHIR_INIT_NVAR(&reflectionMethod);
						ZVAL_COPY(&reflectionMethod, _3$$5);
						ZEPHIR_INIT_NVAR(&_7$$6);
						object_init_ex(&_7$$6, phalcon_annotations_collection_ce);
						ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", &_8, 37, &reflectionMethod);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("methodAnnotations"), &methodName, &_7$$6);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &reflectionMethods, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_4$$5, &reflectionMethods, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_4$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&methodName, &reflectionMethods, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&reflectionMethod, &reflectionMethods, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_9$$7);
							object_init_ex(&_9$$7, phalcon_annotations_collection_ce);
							ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", &_8, 37, &reflectionMethod);
							zephir_check_call_status();
							zephir_update_property_array(this_ptr, SL("methodAnnotations"), &methodName, &_9$$7);
						ZEPHIR_CALL_METHOD(NULL, &reflectionMethods, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&reflectionMethod);
				ZEPHIR_INIT_NVAR(&methodName);
				RETURN_MM_MEMBER(getThis(), "methodAnnotations");
			}
		}
		if (0) {
			zephir_update_property_zval(this_ptr, SL("methodAnnotations"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("methodAnnotations"), &__$false);
		}
	}
	RETURN_MM_MEMBER(getThis(), "methodAnnotations");

}

/**
 * Returns the annotations found in the properties' docblocks
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getPropertiesAnnotations) {

	zend_string *_6$$5;
	zend_ulong _5$$5;
	zval __$true, __$false, reflectionProperties, property, reflectionProperty, _0, _1$$3, _2$$5, *_3$$5, _4$$5, _7$$6, _9$$7;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&reflectionProperties);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&reflectionProperty);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("propertyAnnotations"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_OBS_VAR(&reflectionProperties);
		zephir_read_property(&_1$$3, this_ptr, SL("reflectionData"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&reflectionProperties, &_1$$3, SL("properties"), 0)) {
			if (zephir_fast_count_int(&reflectionProperties TSRMLS_CC)) {
				ZEPHIR_INIT_VAR(&_2$$5);
				array_init(&_2$$5);
				zephir_update_property_zval(this_ptr, SL("propertyAnnotations"), &_2$$5);
				zephir_is_iterable(&reflectionProperties, 0, "phalcon/Annotations/Reflection.zep", 134);
				if (Z_TYPE_P(&reflectionProperties) == IS_ARRAY) {
					ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&reflectionProperties), _5$$5, _6$$5, _3$$5)
					{
						ZEPHIR_INIT_NVAR(&property);
						if (_6$$5 != NULL) { 
							ZVAL_STR_COPY(&property, _6$$5);
						} else {
							ZVAL_LONG(&property, _5$$5);
						}
						ZEPHIR_INIT_NVAR(&reflectionProperty);
						ZVAL_COPY(&reflectionProperty, _3$$5);
						ZEPHIR_INIT_NVAR(&_7$$6);
						object_init_ex(&_7$$6, phalcon_annotations_collection_ce);
						ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", &_8, 37, &reflectionProperty);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("propertyAnnotations"), &property, &_7$$6);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &reflectionProperties, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_4$$5, &reflectionProperties, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_4$$5)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&property, &reflectionProperties, "key", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&reflectionProperty, &reflectionProperties, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_INIT_NVAR(&_9$$7);
							object_init_ex(&_9$$7, phalcon_annotations_collection_ce);
							ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", &_8, 37, &reflectionProperty);
							zephir_check_call_status();
							zephir_update_property_array(this_ptr, SL("propertyAnnotations"), &property, &_9$$7);
						ZEPHIR_CALL_METHOD(NULL, &reflectionProperties, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&reflectionProperty);
				ZEPHIR_INIT_NVAR(&property);
				RETURN_MM_MEMBER(getThis(), "propertyAnnotations");
			}
		}
		if (0) {
			zephir_update_property_zval(this_ptr, SL("propertyAnnotations"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("propertyAnnotations"), &__$false);
		}
	}
	RETURN_MM_MEMBER(getThis(), "propertyAnnotations");

}

/**
 * Returns the raw parsing intermediate definitions used to construct the
 * reflection
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getReflectionData) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "reflectionData");

}

