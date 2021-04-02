
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Allows to manipulate the annotations reflection in an OO manner
 *
 *```php
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
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Reflection) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Reflection, phalcon, annotations_reflection, phalcon_annotations_reflection_method_entry, 0);

	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("classAnnotations"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("methodAnnotations"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("propertyAnnotations"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("reflectionData"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Phalcon\Annotations\Reflection constructor
 */
PHP_METHOD(Phalcon_Annotations_Reflection, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *reflectionData_param = NULL;
	zval reflectionData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflectionData);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(reflectionData)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &reflectionData_param);

	if (!reflectionData_param) {
		ZEPHIR_INIT_VAR(&reflectionData);
		array_init(&reflectionData);
	} else {
		zephir_get_arrval(&reflectionData, reflectionData_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("reflectionData"), &reflectionData);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns the annotations found in the class docblock
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getClassAnnotations) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

	zephir_read_property(&_0, this_ptr, ZEND_STRL("classAnnotations"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("reflectionData"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&reflectionClass, &_1$$3, SL("class"), 1)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			object_init_ex(&_2$$4, phalcon_annotations_collection_ce);
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 48, &reflectionClass);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("classAnnotations"), &_2$$4);
		} else {
			if (0) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("classAnnotations"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("classAnnotations"), &__$false);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

	zephir_read_property(&_0, this_ptr, ZEND_STRL("methodAnnotations"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_OBS_VAR(&reflectionMethods);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("reflectionData"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&reflectionMethods, &_1$$3, SL("methods"), 0)) {
			if (zephir_fast_count_int(&reflectionMethods)) {
				ZEPHIR_INIT_VAR(&_2$$5);
				array_init(&_2$$5);
				zephir_update_property_zval(this_ptr, ZEND_STRL("methodAnnotations"), &_2$$5);
				zephir_is_iterable(&reflectionMethods, 0, "phalcon/Annotations/Reflection.zep", 88);
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
						ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", &_8, 48, &reflectionMethod);
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
							ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", &_8, 48, &reflectionMethod);
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
			zephir_update_property_zval(this_ptr, ZEND_STRL("methodAnnotations"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("methodAnnotations"), &__$false);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

	zephir_read_property(&_0, this_ptr, ZEND_STRL("propertyAnnotations"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_OBS_VAR(&reflectionProperties);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("reflectionData"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_string_fetch(&reflectionProperties, &_1$$3, SL("properties"), 0)) {
			if (zephir_fast_count_int(&reflectionProperties)) {
				ZEPHIR_INIT_VAR(&_2$$5);
				array_init(&_2$$5);
				zephir_update_property_zval(this_ptr, ZEND_STRL("propertyAnnotations"), &_2$$5);
				zephir_is_iterable(&reflectionProperties, 0, "phalcon/Annotations/Reflection.zep", 116);
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
						ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", &_8, 48, &reflectionProperty);
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
							ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", &_8, 48, &reflectionProperty);
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
			zephir_update_property_zval(this_ptr, ZEND_STRL("propertyAnnotations"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("propertyAnnotations"), &__$false);
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

