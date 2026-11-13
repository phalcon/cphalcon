
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * This is the base class for Phalcon\Annotations adapters
 *
 * @phpstan-import-type annotations_cache from AnnotationsTypes
 * @phpstan-import-type annotations_collection_map from AnnotationsTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Annotations_Adapter_AbstractAdapter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Annotations\\Adapter, AbstractAdapter, phalcon, annotations_adapter_abstractadapter, phalcon_annotations_adapter_abstractadapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 *
	 * @phpstan-var annotations_cache
	 */
	zend_declare_property_null(phalcon_annotations_adapter_abstractadapter_ce, SL("annotations"), ZEND_ACC_PROTECTED);
	/**
	 * Maximum number of class annotation entries retained in the
	 * in-memory cache. 0 (default) keeps the original unbounded
	 * behavior; a positive value clears the cache when adding a new
	 * class would exceed it.
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_annotations_adapter_abstractadapter_ce, SL("annotationsLimit"), 0, ZEND_ACC_PROTECTED);
	/**
	 * @var Reader
	 */
	zend_declare_property_null(phalcon_annotations_adapter_abstractadapter_ce, SL("reader"), ZEND_ACC_PROTECTED);
	phalcon_annotations_adapter_abstractadapter_ce->create_object = zephir_init_properties_Phalcon_Annotations_Adapter_AbstractAdapter;

	zend_class_implements(phalcon_annotations_adapter_abstractadapter_ce, 1, phalcon_annotations_adapter_adapterinterface_ce);
	return SUCCESS;
}

/**
 * Parses or retrieves all the annotations found in a class
 *
 * @phpstan-param object|string $className
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, get)
{
	zend_bool _1, _4, _6$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *className, className_sub, classAnnotations, parsedAnnotations, realClassName, reader, _0, _2$$5, _3$$5, _5$$6, _7$$6, _8$$6, _9$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_sub);
	ZVAL_UNDEF(&classAnnotations);
	ZVAL_UNDEF(&parsedAnnotations);
	ZVAL_UNDEF(&realClassName);
	ZVAL_UNDEF(&reader);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZEND_TLS zephir_method_cache _zephir_call_cache[5];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("annotations", 11, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("annotationsLimit", 16, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &className);
	if (Z_TYPE_P(className) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&realClassName);
		zephir_get_class(&realClassName, className, 0);
	} else {
		ZEPHIR_CPY_WRT(&realClassName, className);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 99, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_value(&_0, &realClassName);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		zephir_read_property_cached(&_2$$5, this_ptr, _zephir_prop_0, 99, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_memory_observe(&_3$$5);
		zephir_array_fetch(&_3$$5, &_2$$5, &realClassName, PH_NOISY, "phalcon/Annotations/Adapter/AbstractAdapter.zep", 69);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		RETURN_CCTOR(&_3$$5);
	}
	ZEPHIR_CALL_METHOD_CACHED(&classAnnotations, this_ptr, "read", &_zephir_call_cache[0], &realClassName);
	zephir_check_call_status();
	_4 = Z_TYPE_P(&classAnnotations) == IS_NULL;
	if (!(_4)) {
		_4 = ZEPHIR_IS_FALSE_IDENTICAL(&classAnnotations);
	}
	if (_4) {
		ZEPHIR_CALL_METHOD_CACHED(&reader, this_ptr, "getReader", &_zephir_call_cache[1]);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_CACHED(&parsedAnnotations, &reader, "parse", &_zephir_call_cache[2], &realClassName);
		zephir_check_call_status();
		zephir_read_property_cached(&_5$$6, this_ptr, _zephir_prop_1, 100, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_6$$6 = ZEPHIR_GT_LONG(&_5$$6, 0);
		if (_6$$6) {
			zephir_read_property_cached(&_7$$6, this_ptr, _zephir_prop_0, 99, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_property_cached(&_8$$6, this_ptr, _zephir_prop_1, 100, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_6$$6 = ZEPHIR_LE_LONG(&_8$$6, zephir_fast_count_int(&_7$$6));
		}
		if (_6$$6) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 99, &_9$$7);
		}
		ZEPHIR_INIT_NVAR(&classAnnotations);
		object_init_ex(&classAnnotations, phalcon_annotations_reflection_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &classAnnotations, "__construct", &_zephir_call_cache[3], &parsedAnnotations);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("annotations"), &realClassName, &classAnnotations);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "write", &_zephir_call_cache[4], &realClassName, &classAnnotations);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&classAnnotations);
}

/**
 * Returns the configured annotations-cache cap (0 = unlimited).
 * See setAnnotationsLimit().
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getAnnotationsLimit)
{

	RETURN_MEMBER_TYPED(getThis(), "annotationsLimit", IS_LONG);
}

/**
 * Returns the annotations found in a specific constant
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getConstant)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, constantName_zv, constants, constant;
	zend_string *className = NULL, *constantName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&constantName_zv);
	ZVAL_UNDEF(&constants);
	ZVAL_UNDEF(&constant);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(className)
		Z_PARAM_STR(constantName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_memory_observe(&constantName_zv);
	ZVAL_STR_COPY(&constantName_zv, constantName);
	ZEPHIR_CALL_METHOD_CACHED(&constants, this_ptr, "getConstants", &_zephir_call_cache[0], &className_zv);
	zephir_check_call_status();
	zephir_memory_observe(&constant);
	_0 = zephir_array_isset_fetch(&constant, &constants, &constantName_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		object_init_ex(return_value, phalcon_annotations_collection_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[1]);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&constant);
}

/**
 * Returns the annotations found in all the class' constants
 *
 * @phpstan-return annotations_collection_map
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getConstants)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, classAnnotations;
	zend_string *className = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&classAnnotations);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	ZEPHIR_CALL_METHOD_CACHED(&classAnnotations, this_ptr, "get", &_zephir_call_cache[0], &className_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&classAnnotations, "getConstantsAnnotations", &_zephir_call_cache[1]);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the annotations found in a specific property
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getProperty)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, propertyName_zv, classAnnotations, properties, property;
	zend_string *className = NULL, *propertyName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&propertyName_zv);
	ZVAL_UNDEF(&classAnnotations);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&property);
	ZEND_TLS zephir_method_cache _zephir_call_cache[3];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(className)
		Z_PARAM_STR(propertyName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_memory_observe(&propertyName_zv);
	ZVAL_STR_COPY(&propertyName_zv, propertyName);
	ZEPHIR_CALL_METHOD_CACHED(&classAnnotations, this_ptr, "get", &_zephir_call_cache[0], &className_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&properties, &classAnnotations, "getPropertiesAnnotations", &_zephir_call_cache[1]);
	zephir_check_call_status();
	zephir_memory_observe(&property);
	_0 = zephir_array_isset_fetch(&property, &properties, &propertyName_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_0)) {
		object_init_ex(return_value, phalcon_annotations_collection_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[2]);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&property);
}

/**
 * Returns the annotations found in all the class' properties
 *
 * @phpstan-return annotations_collection_map
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getProperties)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, classAnnotations;
	zend_string *className = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&classAnnotations);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	ZEPHIR_CALL_METHOD_CACHED(&classAnnotations, this_ptr, "get", &_zephir_call_cache[0], &className_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&classAnnotations, "getPropertiesAnnotations", &_zephir_call_cache[1]);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the annotations found in a specific method
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getMethod)
{
	zend_ulong _4$$3;
	zend_bool _0$$3, _9$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, methodName_zv, classAnnotations, methods, method, methodKey, *_1$$3, _2$$3, *_3$$3, _8$$3, _6$$5, _10$$7;
	zend_string *className = NULL, *methodName = NULL, *_5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&methodName_zv);
	ZVAL_UNDEF(&classAnnotations);
	ZVAL_UNDEF(&methods);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&methodKey);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_10$$7);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(className)
		Z_PARAM_STR(methodName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_memory_observe(&methodName_zv);
	ZVAL_STR_COPY(&methodName_zv, methodName);
	ZEPHIR_CALL_METHOD_CACHED(&classAnnotations, this_ptr, "get", &_zephir_call_cache[0], &className_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD_CACHED(&methods, &classAnnotations, "getMethodsAnnotations", &_zephir_call_cache[1]);
	zephir_check_call_status();
	if (Z_TYPE_P(&methods) == IS_ARRAY) {
		zephir_memory_observe(&method);
		_0$$3 = zephir_array_isset_fetch(&method, &methods, &methodName_zv, 0);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_0$$3) {
			RETURN_CCTOR(&method);
		}
		if (Z_TYPE_P(&methods) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_2$$3);
			zephir_string_to_char_array(&_2$$3, &methods);
			_1$$3 = &_2$$3;
		} else {
			_1$$3 = &methods;
		}
		zephir_is_iterable(_1$$3, 0, "phalcon/Annotations/Adapter/AbstractAdapter.zep", 206);
		if (Z_TYPE_P(_1$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_1$$3), _4$$3, _5$$3, _3$$3)
			{
				ZEPHIR_INIT_NVAR(&methodKey);
				if (_5$$3 != NULL) { 
					ZVAL_STR_COPY(&methodKey, _5$$3);
				} else {
					ZVAL_LONG(&methodKey, _4$$3);
				}
				ZEPHIR_INIT_NVAR(&method);
				ZVAL_COPY(&method, _3$$3);
				ZEPHIR_CALL_FUNCTION(&_6$$5, "strcasecmp", &_7, 35, &methodKey, &methodName_zv);
				zephir_check_call_status();
				if (!(zephir_is_true(&_6$$5))) {
					RETURN_CCTOR(&method);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD_CACHED(NULL, _1$$3, "rewind", &_zephir_call_cache[2]);
			zephir_check_call_status();
			_9$$3 = 1;
			while (1) {
				if (_9$$3) {
					_9$$3 = 0;
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _1$$3, "next", &_zephir_call_cache[3]);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD_CACHED(&_8$$3, _1$$3, "valid", &_zephir_call_cache[4]);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD_CACHED(&methodKey, _1$$3, "key", &_zephir_call_cache[5]);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&method, _1$$3, "current", &_zephir_call_cache[6]);
				zephir_check_call_status();
					ZEPHIR_CALL_FUNCTION(&_10$$7, "strcasecmp", &_7, 35, &methodKey, &methodName_zv);
					zephir_check_call_status();
					if (!(zephir_is_true(&_10$$7))) {
						RETURN_CCTOR(&method);
					}
			}
		}
		ZEPHIR_INIT_NVAR(&method);
		ZEPHIR_INIT_NVAR(&methodKey);
	}
	object_init_ex(return_value, phalcon_annotations_collection_ce);
	ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[7]);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the annotations found in all the class' methods
 *
 * @phpstan-return annotations_collection_map
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getMethods)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, classAnnotations;
	zend_string *className = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&classAnnotations);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	ZEPHIR_CALL_METHOD_CACHED(&classAnnotations, this_ptr, "get", &_zephir_call_cache[0], &className_zv);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD_CACHED(&classAnnotations, "getMethodsAnnotations", &_zephir_call_cache[1]);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the annotation reader
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, getReader)
{
	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("reader", 6, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 101, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_annotations_reader_ce);
		if (zephir_has_constructor(&_1$$3)) {
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[0]);
			zephir_check_call_status();
		}

		zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 101, &_1$$3);
	}
	RETURN_MM_MEMBER(getThis(), "reader");
}

/**
 * Caps the number of class entries retained in the annotations
 * cache. 0 disables the cap (the default; preserves the original
 * unbounded behavior). When the cap is exceeded, the cache is
 * cleared and repopulated on subsequent reads.
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, setAnnotationsLimit)
{
	zval *annotationsLimit_param = NULL, _0;
	zend_long annotationsLimit;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("annotationsLimit", 16, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(annotationsLimit)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &annotationsLimit_param);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, annotationsLimit);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 100, &_0);
}

/**
 * Sets the annotations parser
 */
PHP_METHOD(Phalcon_Annotations_Adapter_AbstractAdapter, setReader)
{
	zval *reader, reader_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&reader_sub);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("reader", 6, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(reader, phalcon_annotations_readerinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &reader);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 101, reader);
}

zend_object *zephir_init_properties_Phalcon_Annotations_Adapter_AbstractAdapter(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("annotations"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("annotations"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

