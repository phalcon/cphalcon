
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
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Reflection)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations, Reflection, phalcon, annotations_reflection, phalcon_annotations_reflection_method_entry, 0);

	/**
	 * @var Collection|null
	 */
	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("classAnnotations"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("constantAnnotations"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("propertyAnnotations"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("methodAnnotations"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_annotations_reflection_ce, SL("reflectionData"), ZEND_ACC_PROTECTED);
	phalcon_annotations_reflection_ce->create_object = zephir_init_properties_Phalcon_Annotations_Reflection;

	return SUCCESS;
}

PHP_METHOD(Phalcon_Annotations_Reflection, __construct)
{
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
 *
 * @return Collection|null
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getClassAnnotations)
{
	zval reflectionClass, _0, _1$$3, _2$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

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
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 34, &reflectionClass);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, ZEND_STRL("classAnnotations"), &_2$$4);
		}
	}
	RETURN_MM_MEMBER(getThis(), "classAnnotations");
}

/**
 * Returns the annotations found in the constants' docblocks
 *
 * @return Collection[]
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getConstantsAnnotations)
{
	zend_string *_5$$4;
	zend_ulong _4$$4;
	zend_bool _1$$3;
	zval reflectionConstants, constant, reflectionConstant, _0, *_2$$4, _3$$4, _6$$5, _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflectionConstants);
	ZVAL_UNDEF(&constant);
	ZVAL_UNDEF(&reflectionConstant);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&reflectionConstants);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("reflectionData"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&reflectionConstants, &_0, SL("constants"), 0)) {
		_1$$3 = Z_TYPE_P(&reflectionConstants) == IS_ARRAY;
		if (_1$$3) {
			_1$$3 = zephir_fast_count_int(&reflectionConstants) > 0;
		}
		if (_1$$3) {
			zephir_is_iterable(&reflectionConstants, 0, "phalcon/Annotations/Reflection.zep", 97);
			if (Z_TYPE_P(&reflectionConstants) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&reflectionConstants), _4$$4, _5$$4, _2$$4)
				{
					ZEPHIR_INIT_NVAR(&constant);
					if (_5$$4 != NULL) { 
						ZVAL_STR_COPY(&constant, _5$$4);
					} else {
						ZVAL_LONG(&constant, _4$$4);
					}
					ZEPHIR_INIT_NVAR(&reflectionConstant);
					ZVAL_COPY(&reflectionConstant, _2$$4);
					ZEPHIR_INIT_NVAR(&_6$$5);
					object_init_ex(&_6$$5, phalcon_annotations_collection_ce);
					ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", &_7, 34, &reflectionConstant);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("constantAnnotations"), &constant, &_6$$5);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &reflectionConstants, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_3$$4, &reflectionConstants, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_3$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&constant, &reflectionConstants, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&reflectionConstant, &reflectionConstants, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_8$$6);
						object_init_ex(&_8$$6, phalcon_annotations_collection_ce);
						ZEPHIR_CALL_METHOD(NULL, &_8$$6, "__construct", &_7, 34, &reflectionConstant);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("constantAnnotations"), &constant, &_8$$6);
					ZEPHIR_CALL_METHOD(NULL, &reflectionConstants, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&reflectionConstant);
			ZEPHIR_INIT_NVAR(&constant);
		}
	}
	RETURN_MM_MEMBER(getThis(), "constantAnnotations");
}

/**
 * Returns the annotations found in the properties' docblocks
 *
 * @return Collection[]
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getPropertiesAnnotations)
{
	zend_string *_5$$4;
	zend_ulong _4$$4;
	zend_bool _1$$3;
	zval reflectionProperties, property, reflectionProperty, _0, *_2$$4, _3$$4, _6$$5, _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflectionProperties);
	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&reflectionProperty);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&reflectionProperties);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("reflectionData"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&reflectionProperties, &_0, SL("properties"), 0)) {
		_1$$3 = Z_TYPE_P(&reflectionProperties) == IS_ARRAY;
		if (_1$$3) {
			_1$$3 = zephir_fast_count_int(&reflectionProperties) > 0;
		}
		if (_1$$3) {
			zephir_is_iterable(&reflectionProperties, 0, "phalcon/Annotations/Reflection.zep", 119);
			if (Z_TYPE_P(&reflectionProperties) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&reflectionProperties), _4$$4, _5$$4, _2$$4)
				{
					ZEPHIR_INIT_NVAR(&property);
					if (_5$$4 != NULL) { 
						ZVAL_STR_COPY(&property, _5$$4);
					} else {
						ZVAL_LONG(&property, _4$$4);
					}
					ZEPHIR_INIT_NVAR(&reflectionProperty);
					ZVAL_COPY(&reflectionProperty, _2$$4);
					ZEPHIR_INIT_NVAR(&_6$$5);
					object_init_ex(&_6$$5, phalcon_annotations_collection_ce);
					ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", &_7, 34, &reflectionProperty);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("propertyAnnotations"), &property, &_6$$5);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &reflectionProperties, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_3$$4, &reflectionProperties, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_3$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&property, &reflectionProperties, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&reflectionProperty, &reflectionProperties, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_8$$6);
						object_init_ex(&_8$$6, phalcon_annotations_collection_ce);
						ZEPHIR_CALL_METHOD(NULL, &_8$$6, "__construct", &_7, 34, &reflectionProperty);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("propertyAnnotations"), &property, &_8$$6);
					ZEPHIR_CALL_METHOD(NULL, &reflectionProperties, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&reflectionProperty);
			ZEPHIR_INIT_NVAR(&property);
		}
	}
	RETURN_MM_MEMBER(getThis(), "propertyAnnotations");
}

/**
 * Returns the annotations found in the methods' docblocks
 *
 * @return Collection[]
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getMethodsAnnotations)
{
	zend_string *_5$$4;
	zend_ulong _4$$4;
	zend_bool _1$$3;
	zval reflectionMethods, methodName, reflectionMethod, _0, *_2$$4, _3$$4, _6$$5, _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reflectionMethods);
	ZVAL_UNDEF(&methodName);
	ZVAL_UNDEF(&reflectionMethod);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&reflectionMethods);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("reflectionData"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&reflectionMethods, &_0, SL("methods"), 0)) {
		_1$$3 = Z_TYPE_P(&reflectionMethods) == IS_ARRAY;
		if (_1$$3) {
			_1$$3 = zephir_fast_count_int(&reflectionMethods) > 0;
		}
		if (_1$$3) {
			zephir_is_iterable(&reflectionMethods, 0, "phalcon/Annotations/Reflection.zep", 141);
			if (Z_TYPE_P(&reflectionMethods) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&reflectionMethods), _4$$4, _5$$4, _2$$4)
				{
					ZEPHIR_INIT_NVAR(&methodName);
					if (_5$$4 != NULL) { 
						ZVAL_STR_COPY(&methodName, _5$$4);
					} else {
						ZVAL_LONG(&methodName, _4$$4);
					}
					ZEPHIR_INIT_NVAR(&reflectionMethod);
					ZVAL_COPY(&reflectionMethod, _2$$4);
					ZEPHIR_INIT_NVAR(&_6$$5);
					object_init_ex(&_6$$5, phalcon_annotations_collection_ce);
					ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", &_7, 34, &reflectionMethod);
					zephir_check_call_status();
					zephir_update_property_array(this_ptr, SL("methodAnnotations"), &methodName, &_6$$5);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &reflectionMethods, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_3$$4, &reflectionMethods, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_3$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&methodName, &reflectionMethods, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&reflectionMethod, &reflectionMethods, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_INIT_NVAR(&_8$$6);
						object_init_ex(&_8$$6, phalcon_annotations_collection_ce);
						ZEPHIR_CALL_METHOD(NULL, &_8$$6, "__construct", &_7, 34, &reflectionMethod);
						zephir_check_call_status();
						zephir_update_property_array(this_ptr, SL("methodAnnotations"), &methodName, &_8$$6);
					ZEPHIR_CALL_METHOD(NULL, &reflectionMethods, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&reflectionMethod);
			ZEPHIR_INIT_NVAR(&methodName);
		}
	}
	RETURN_MM_MEMBER(getThis(), "methodAnnotations");
}

/**
 * Returns the raw parsing intermediate definitions used to construct the
 * reflection
 *
 * @return array
 */
PHP_METHOD(Phalcon_Annotations_Reflection, getReflectionData)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "reflectionData");
}

zend_object *zephir_init_properties_Phalcon_Annotations_Reflection(zend_class_entry *class_type)
{
		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("reflectionData"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("reflectionData"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("methodAnnotations"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("methodAnnotations"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("propertyAnnotations"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("propertyAnnotations"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("constantAnnotations"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("constantAnnotations"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

